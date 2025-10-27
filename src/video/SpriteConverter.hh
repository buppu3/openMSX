/*
TODO:
- Implement sprite pixels in Graphic 5.
*/

#ifndef SPRITECONVERTER_HH
#define SPRITECONVERTER_HH

#include "SpriteChecker.hh"

#include "DisplayMode.hh"

#include "narrow.hh"

#include <cstdint>
#include <ranges>
#include <span>

namespace openmsx {

/** Utility class for converting VRAM contents to host pixels.
  */
class SpriteConverter
{
public:
	using Pixel = uint32_t;

	// TODO: Move some methods to .cc?

	/** Constructor.
	  * After construction, also call the various set methods to complete
	  * initialisation.
	  * @param spriteChecker_ Delivers the sprite data to be rendered.
	  * @param pal The initial palette. Can later be changed via setPallette().
	  */
	explicit SpriteConverter(SpriteChecker& spriteChecker_,
	                         std::span<const Pixel, 256> pal)
		: spriteChecker(spriteChecker_)
		, palette(pal)
	{
	}

	/** Update the transparency setting.
	  * @param enabled The new value.
	  */
	void setTransparency(bool enabled)
	{
		transparency = enabled;
	}

	/** Notify SpriteConverter of a display mode change.
	  * @param newMode The new display mode.
	  */
	void setDisplayMode(DisplayMode newMode)
	{
		mode = newMode;
	}

	/** Set palette to use for converting sprites.
	  * This palette is stored by reference, so any modifications to it
	  * will be used while drawing.
	  * @param newPalette 16-entry array containing the sprite palette.
	  */
	void setPalette(std::span<const Pixel, 256> newPalette)
	{
		palette = newPalette;
	}

	static bool clipPattern(int& x, SpriteChecker::SpritePattern& pattern,
	                        int minX, int maxX)
	{
		if (int before = minX - x; before > 0) {
			if (before >= 32) {
				// 32 pixels before minX -> not visible
				return false;
			}
			pattern <<= before;
			x = minX;
		}
		if (int after = maxX - x; after < 32) {
			// close to maxX (or past)
			if (after <= 0) {
				// past maxX -> not visible
				return false;
			}
			auto mask = narrow_cast<int>(0x8000'0000);
			pattern &= (mask >> (after - 1));
		}
		return true; // visible
	}

	static uint8_t calc_tp(Pixel dst, Pixel src, uint8_t tp, int shift)
	{
		unsigned s = src >> (shift + 3) & 31;
		unsigned d = dst >> (shift + 3) & 31;
		switch (tp) {
		default:	// 0%
			d = s;
			break;
		case 1:		// 25%
			d = (s * 3 + d) >> 2;
			break;
		case 2:		// 50%
			d = (s + d) >> 1;
			break;
		case 3:		// 70%
			d = (d * 3 + s) >> 2;
			break;
		}
		return (d << 3) | (d >> 2);
	}

	static Pixel pixel_transparent(Pixel dst, Pixel src, uint8_t tp)
	{
		if(tp == 0) return src;
		return ((Pixel)calc_tp(dst, src, tp, 16) << 16)
				| ((Pixel)calc_tp(dst, src, tp, 8) << 8)
				| ((Pixel)calc_tp(dst, src, tp, 0) << 0);
	}

	/** Draw sprites in sprite mode 1.
	  * @param absLine Absolute line number.
	  *     Range is [0..262) for NTSC and [0..313) for PAL.
	  * @param minX Minimum X coordinate to draw (inclusive).
	  * @param maxX Maximum X coordinate to draw (exclusive).
	  * @param pixelPtr Pointer to memory to draw to.
	  */
	void drawMode1(int absLine, int minX, int maxX, std::span<Pixel> pixelPtr) const
	{
		// Determine sprites visible on this line.
		auto visibleSprites = spriteChecker.getSprites(absLine);
		// Optimisation: return at once if no sprites on this line.
		// Lines without any sprites are very common in most programs.
		if (visibleSprites.empty()) return;

		// Render using overdraw.
		for (const auto& si : std::views::reverse(visibleSprites)) {
			// Get sprite info.
			Pixel colIndex = si.colorAttrib & 0x0F;
			// Don't draw transparent sprites in sprite mode 1.
			// Verified on real V9958: TP bit also has effect in
			// sprite mode 1.
			if (colIndex == 0 && transparency) continue;
			Pixel color = palette[colIndex];
			SpriteChecker::SpritePattern pattern = si.pattern;
			int x = si.x;
			// Clip sprite pattern to render range.
			if (!clipPattern(x, pattern, minX, maxX)) continue;
			// Convert pattern to pixels.
			Pixel* p = &pixelPtr[x];
			while (pattern) {
				// Draw pixel if sprite has a dot.
				if (pattern & 0x8000'0000) {
					*p = color;
				}
				// Advancing behaviour.
				pattern <<= 1;
				p++;
			}
		}
	}

	/** Draw sprites in sprite mode 2.
	  * Make sure the pixel pointers point to a large enough memory area:
	  * 256 pixels for ZOOM_256 and ZOOM_REAL in 256-pixel wide modes;
	  * 512 pixels for ZOOM_REAL in 512-pixel wide modes.
	  * @param absLine Absolute line number.
	  *     Range is [0..262) for NTSC and [0..313) for PAL.
	  * @param minX Minimum X coordinate to draw (inclusive).
	  * @param maxX Maximum X coordinate to draw (exclusive).
	  * @param pixelPtr Pointer to memory to draw to.
	  */
	template<unsigned MODE>
	void drawMode2(int absLine, int minX, int maxX, std::span<Pixel> pixelPtr) const
	{
		// Determine sprites visible on this line.
		auto visibleSprites = spriteChecker.getSprites(absLine);
		// Optimisation: return at once if no sprites on this line.
		// Lines without any sprites are very common in most programs.
		if (visibleSprites.empty()) return;
		std::span visibleSpritesWithSentinel{visibleSprites.data(),
		                                     visibleSprites.size() +1};

		// Sprites with CC=1 are only visible if preceded by a sprite
		// with CC=0. Therefor search for first sprite with CC=0.
		int first = 0;
		do {
			if ((visibleSprites[first].colorAttrib & 0x40) == 0) [[likely]] {
				break;
			}
			++first;
		} while (first < int(visibleSprites.size()));
		for (int i = narrow<int>(visibleSprites.size() - 1); i >= first; --i) {
			const SpriteChecker::SpriteInfo& info = visibleSprites[i];
			int x = info.x;
			SpriteChecker::SpritePattern pattern = info.pattern;
			// Clip sprite pattern to render range.
			if (!clipPattern(x, pattern, minX, maxX)) continue;
			uint8_t c = info.colorAttrib & 0x0F;
			if (c == 0 && transparency) continue;
			while (pattern) {
				if (pattern & 0x8000'0000) {
					uint8_t color = c;
					// Merge in any following CC=1 sprites.
					for (int j = i + 1; /*sentinel*/; ++j) {
						const SpriteChecker::SpriteInfo& info2 =
							visibleSpritesWithSentinel[j];
						if (!(info2.colorAttrib & 0x40)) break;
						unsigned shift2 = x - info2.x;
						if ((shift2 < 32) &&
						   ((info2.pattern << shift2) & 0x8000'0000)) {
							color |= info2.colorAttrib & 0x0F;
						}
					}
					if constexpr (MODE == DisplayMode::GRAPHIC5) {
						Pixel pixL = palette[color >> 2];
						Pixel pixR = palette[color & 3];
						pixelPtr[x * 2 + 0] = pixL;
						pixelPtr[x * 2 + 1] = pixR;
					} else {
						Pixel pix = palette[color];
						if constexpr (MODE == DisplayMode::GRAPHIC6) {
							pixelPtr[x * 2 + 0] = pix;
							pixelPtr[x * 2 + 1] = pix;
						} else {
							pixelPtr[x] = pix;
						}
					}
				}
				++x;
				pattern <<= 1;
			}
		}
	}

	/** Draw sprites in sprite mode 1.
	  * @param absLine Absolute line number.
	  *     Range is [0..262) for NTSC and [0..313) for PAL.
	  * @param minX Minimum X coordinate to draw (inclusive).
	  * @param maxX Maximum X coordinate to draw (exclusive).
	  * @param pixelPtr Pointer to memory to draw to.
	  */
	void drawMode3(int absLine, int minX, int maxX, std::span<Pixel> pixelPtr) const
	{
		// Determine sprites visible on this line.
		auto visibleSprites = spriteChecker.getSprites(absLine);
		// Optimisation: return at once if no sprites on this line.
		// Lines without any sprites are very common in most programs.
		if (visibleSprites.empty()) return;

		// initialize priority buffer
		std::array<uint8_t, 512> priority;
		std::ranges::fill(priority, 0);

		// Render
		for (const auto& si : visibleSprites) {
			// check pattern
			uint64_t pattern = ((uint64_t)si.pattern << 32) | si.pattern2;
			if(pattern == 0) continue;

			// clip
			int srcX = 0;		// src X
			int dstX = si.x;	// dst X
			int nx = si.mgx;	// width
			if (dstX < minX) {
				int invalid = minX - dstX;
				dstX = minX;
				srcX = invalid;
				nx -= invalid;
				if (nx <= 0) {
					continue;
				}
			}
			if (dstX + nx > maxX) {
				nx = maxX - dstX;
				if (nx <= 0) {
					continue;
				}
			}

			// draw pattern
			uint8_t *prioPtr = &priority[dstX];
			Pixel *dstPtr = &pixelPtr[dstX];
			while (nx > 0) {
				if (*prioPtr == 0) {
					// pattern position
					int patX = 16 * srcX / si.mgx;

					// pick
					uint8_t color = (pattern >> (60 - patX * 4)) & 0x0F;

					// draw pixel
					if (color != 0) {
						*dstPtr = pixel_transparent(*dstPtr, palette[(si.paletteSet << 4) | color], si.transparent);
						*prioPtr = 1;
					}
				}
				// next position
				prioPtr++;
				dstPtr++;
				srcX++;
				nx--;
			}
		}
	}

private:
	SpriteChecker& spriteChecker;

	/** The current sprite palette.
	  */
	std::span<const Pixel, 256> palette;

	/** VDP transparency setting (R#8, bit5).
	  */
	bool transparency;

	/** The current display mode.
	  */
	DisplayMode mode;
};

} // namespace openmsx

#endif
