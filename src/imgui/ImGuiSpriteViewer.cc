#include "ImGuiSpriteViewer.hh"

#include "ImGuiCpp.hh"
#include "ImGuiManager.hh"
#include "ImGuiPalette.hh"
#include "ImGuiUtils.hh"

#include "MSXMotherBoard.hh"
#include "SpriteChecker.hh"
#include "SpriteConverter.hh"
#include "VDP.hh"
#include "VDPVRAM.hh"

#include "xrange.hh"

#include <imgui.h>

#include <cassert>
#include <cstdint>
#include <ranges>
#include <span>

namespace openmsx {

using namespace std::literals;

ImGuiSpriteViewer::ImGuiSpriteViewer(ImGuiManager& manager_, size_t index)
	: ImGuiPart(manager_)
	, title("Sprite viewer")
{
	if (index) {
		strAppend(title, " (", index + 1, ')');
	}
}

void ImGuiSpriteViewer::save(ImGuiTextBuffer& buf)
{
	savePersistent(buf, *this, persistentElements);
}

void ImGuiSpriteViewer::loadLine(std::string_view name, zstring_view value)
{
	loadOnePersistent(name, value, *this, persistentElements);
}

static void draw8(uint8_t pattern, uint32_t fgCol, uint32_t bgCol, std::span<uint32_t, 8> out)
{
	out[0] = (pattern & 0x80) ? fgCol : bgCol;
	out[1] = (pattern & 0x40) ? fgCol : bgCol;
	out[2] = (pattern & 0x20) ? fgCol : bgCol;
	out[3] = (pattern & 0x10) ? fgCol : bgCol;
	out[4] = (pattern & 0x08) ? fgCol : bgCol;
	out[5] = (pattern & 0x04) ? fgCol : bgCol;
	out[6] = (pattern & 0x02) ? fgCol : bgCol;
	out[7] = (pattern & 0x01) ? fgCol : bgCol;
}

static void renderPatterns8(const VramTable& pat, std::span<uint32_t> output)
{
	auto zero = getColor(imColor::TRANSPARENT);
	auto one  = getColor(imColor::TEXT);
	for (auto row : xrange(8)) {
		for (auto column : xrange(32)) {
			auto patNum = 32 * row + column;
			auto offset = 8 * patNum;
			for (auto y : xrange(8)) {
				auto pattern = pat[offset + y];
				auto out = subspan<8>(output, (8 * row + y) * 256 + 8 * column);
				draw8(pattern, one, zero, out);
			}
		}
	}
}

static void renderPatterns16(const VramTable& pat, std::span<uint32_t> output)
{
	auto zero = getColor(imColor::TRANSPARENT);
	auto one  = getColor(imColor::TEXT);
	for (auto row : xrange(4)) {
		for (auto column : xrange(16)) {
			auto patNum = 4 * (16 * row + column);
			auto offset = 8 * patNum;
			for (auto y : xrange(16)) {
				auto patternA = pat[offset + y +  0];
				auto patternB = pat[offset + y + 16];
				auto outA = subspan<8>(output, (16 * row + y) * 256 + 16 * column +  0);
				auto outB = subspan<8>(output, (16 * row + y) * 256 + 16 * column +  8);
				draw8(patternA, one, zero, outA);
				draw8(patternB, one, zero, outB);
			}
		}
	}
}

static void renderPatternsMode3(const VramTable& att, const VramTable& pat, unsigned baseAddress, std::span<uint32_t, 4 * 256> palette, std::span<uint32_t> output)
{
	for (auto num : xrange(64)) {
		int row = num / 16;
		int col = num % 16;

		int addr = num * 8;
		int sz = (att[addr + 1] >> 6) & 0x03;
		int ps = att[addr + 3] & 0x0F;
		int pts = (att[addr + 5] >> 4) & 0x07;
		int tp = (att[addr + 3] >> 6) & 0x03;
		bool rvx = (att[addr + 3] & 0x10) != 0;
		bool rvy = (att[addr + 3] & 0x20) != 0;
		int px = att[addr + 7] & 0x0F;
		int py = (att[addr + 7] >> 4) & 0x0F;

		unsigned pat_offset = baseAddress + ((pts << 15) | (py << 11) | (px << 3));
		unsigned color_base = ((int)tp << 8) | ((int)ps << 4);
		for (auto y : xrange(16)) {
			int sy = rvy ? ((16 << sz) - y - 1) : y;
			unsigned ptr = pat_offset + (sy << 7);
			uint64_t p;
			if (rvx) {
				p = ((uint64_t)pat[ptr + 0] << 56) |
					((uint64_t)pat[ptr + 1] << 48) |
					((uint64_t)pat[ptr + 2] << 40) |
					((uint64_t)pat[ptr + 3] << 32) |
					((uint64_t)pat[ptr + 4] << 24) |
					((uint64_t)pat[ptr + 5] << 16) |
					((uint64_t)pat[ptr + 6] <<  8) |
					((uint64_t)pat[ptr + 7] <<  0);
			} else {
				p = ((uint64_t)SpriteChecker::swapNibble(pat[ptr + 7]) << 56) |
					((uint64_t)SpriteChecker::swapNibble(pat[ptr + 6]) << 48) |
					((uint64_t)SpriteChecker::swapNibble(pat[ptr + 5]) << 40) |
					((uint64_t)SpriteChecker::swapNibble(pat[ptr + 4]) << 32) |
					((uint64_t)SpriteChecker::swapNibble(pat[ptr + 3]) << 24) |
					((uint64_t)SpriteChecker::swapNibble(pat[ptr + 2]) << 16) |
					((uint64_t)SpriteChecker::swapNibble(pat[ptr + 1]) <<  8) |
					((uint64_t)SpriteChecker::swapNibble(pat[ptr + 0]) <<  0);
			}

			auto out = subspan<16>(output, (16 * row + y) * 256 + 16 * col +  0);
			for (auto x : xrange(16)) {
				uint8_t c = p & 0x0F;
				out[x] = (c == 0) ? 0 : palette[color_base | c];
				p >>= 4;
			}
		}
	}
}

[[nodiscard]] static int getSpriteAttrAddr(int sprite, int mode)
{
	if (mode == 3) return sprite * 8;
	return (mode == 2 ? 512 : 0) + 4 * sprite;
}
[[nodiscard]] static int getSpriteColorAddr(int sprite, int mode)
{
	assert(mode == 2); (void)mode;
	return 16 * sprite;
}

static void renderMode3Pattern(int sprite, float zoom, ImTextureID patternTex)
{
	int cc = sprite % 16;
	int rr = sprite / 16;
	float u1 = float(cc + 0) / 16.0f;
	float u2 = float(cc + 1) / 16.0f;
	float v1 = float(16 * rr) * (1.0f / 64.0f);
	float v2 = float(16 * (rr + 1)) * (1.0f / 64.0f);
	ImGui::Image(patternTex, zoom * gl::vec2{16.0f}, {u1,v1}, {u2,v2});
}

static void renderSpriteAttrib(const VramTable& att, int sprite, int mode, int size, int transparent,
                               float zoom, std::span<uint32_t, 4 * 256> palette, ImTextureID patternTex)
{
	int addr = getSpriteAttrAddr(sprite, mode);
	int pattern = att[addr + 2];
	if (size == 16) pattern /= 4;

	int patternsPerRow = 256 / size;
	int cc = pattern % patternsPerRow;
	int rr = pattern / patternsPerRow;
	float u1 = float(cc + 0) / float(patternsPerRow);
	float u2 = float(cc + 1) / float(patternsPerRow);
	float v1 = float(size * rr) * (1.0f / 64.0f);

	auto getColor = [&](int color) -> gl::vec4 {
		if (color == 0 && transparent) return {};
		return ImGui::ColorConvertU32ToFloat4(palette[color]);
	};

	if (mode == 1) {
		auto attrib = att[addr + 3];
		auto color = attrib & 0x0f;
		float v2 = float(size * (rr + 1)) * (1.0f / 64.0f);
		ImGui::ImageWithBg(patternTex, zoom * gl::vec2{float(size)}, {u1, v1}, {u2, v2},
		                   {}, getColor(color));
	} else {
		int colorBase = getSpriteColorAddr(sprite, mode);
		gl::vec2 pos = ImGui::GetCursorPos();
		for (auto y : xrange(size)) {
			auto attrib = att[colorBase + y];
			auto color = attrib & 0x0f;
			ImGui::SetCursorPos({pos.x, pos.y + zoom * float(y)});
			float v2 = v1 + (1.0f / 64.0f);
			ImGui::ImageWithBg(patternTex, zoom * gl::vec2{float(size), 1.0f}, {u1, v1}, {u2, v2},
			                   {}, getColor(color));
			v1 = v2;
		}
	}
}

void ImGuiSpriteViewer::paint(MSXMotherBoard* motherBoard)
{
	if (!show || !motherBoard) return;

	ImGui::SetNextWindowSize({748, 1010}, ImGuiCond_FirstUseEver);
	im::Window(title.c_str(), &show, [&]{
		auto* vdp = dynamic_cast<VDP*>(motherBoard->findDevice("VDP")); // TODO name based OK?
		if (!vdp) return;
		const auto& vram = vdp->getVRAM().getData();

		auto modeToStr = [](int mode) {
			if (mode == 0) return "no sprites";
			if (mode == 1) return "1";
			if (mode == 2) return "2";
			if (mode == 3) return "3";
			assert(false); return "ERROR";
		};
		auto sizeToStr = [](int size) {
			if (size ==  8) return "8 x 8";
			if (size == 16) return "16 x 16";
			assert(false); return "ERROR";
		};
		auto yesNo = [](int x) {
			if (x == 0) return "no";
			if (x == 1) return "yes";
			assert(false); return "ERROR";
		};
		auto attMult = [](int mode) { return 1 << ((mode == 2) ? 10 : 7); };

		bool isMSX1 = vdp->isMSX1VDP();
		auto displayMode = vdp->getDisplayMode();
		bool planar = displayMode.isPlanar();
		int vdpMode = displayMode.getSpriteMode(isMSX1, vdp->isSP3());
		int vdpVerticalScroll = vdp->getVerticalScroll();
		int vdpLines = vdp->getNumberOfLines();
		bool isSPS = vdp->isSPS();

		int vdpSize = (vdpMode == 3) ? 16 : vdp->getSpriteSize();
		int vdpMag = (vdpMode == 3) ? 0 : vdp->isSpriteMag();
		int vdpTransparent = (vdpMode == 3) ? true : vdp->getTransparency();

		int vdpPatBase = vdp->getSpritePatternTableBase();
		int vdpAttBase = vdp->getSpriteAttributeTableBase() & ~(attMult(vdpMode) - 1);

		auto vramSize = std::min(vdp->getVRAM().getSize(), 0x20000u); // max 128kB

		auto palette = manager.palette->getPaletteWithTP(vdp);
		// TODO? if (color0 < 16) palette[0] = palette[color0];

		bool manMode   = overrideAll || overrideMode;
		bool manSize   = overrideAll || overrideSize;
		bool manMag    = overrideAll || overrideMag;
		bool manTrans  = overrideAll || overrideTrans;
		bool manPat    = overrideAll || overridePat;
		bool manAtt    = overrideAll || overrideAtt;
		bool manScroll = overrideAll || overrideScroll;
		bool manLines  = overrideAll || overrideLines;

		im::TreeNode("Settings", ImGuiTreeNodeFlags_DefaultOpen, [&]{
			im::Group([&]{
				ImGui::TextUnformatted("VDP settings");
				im::Disabled(manMode, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Sprite mode: ", modeToStr(vdpMode));
				});
				im::Disabled(manSize, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Sprite size: ", sizeToStr(vdpSize));
				});
				im::Disabled(manMag, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Sprites magnified: ", yesNo(vdpMag));
				});
				im::Disabled(manTrans, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Color 0 transparent: ", yesNo(vdpTransparent));
				});
				im::Disabled(manPat, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Pattern table: 0x", hex_string<5>(vdpPatBase));
				});
				im::Disabled(manAtt, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Attribute table: 0x", hex_string<5>(vdpAttBase | (vdpMode == 2 ? 512 : 0)));
				});
				im::Disabled(manScroll, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Vertical scroll: ", vdpVerticalScroll);
				});
				im::Disabled(manLines, [&]{
					ImGui::AlignTextToFramePadding();
					ImGui::StrCat("Visible lines: ", (vdpLines == 192) ? "192"sv : "212"sv);
				});
			});
			ImGui::SameLine();
			im::Group([&]{
				ImGui::Checkbox("Manual override", &overrideAll);
				im::Group([&]{
					im::Disabled(overrideAll, [&]{
						ImGui::Checkbox("##o-mode",   overrideAll ? &overrideAll : &overrideMode);
						ImGui::Checkbox("##o-size",   overrideAll ? &overrideAll : &overrideSize);
						ImGui::Checkbox("##o-mag",    overrideAll ? &overrideAll : &overrideMag);
						ImGui::Checkbox("##o-trans",  overrideAll ? &overrideAll : &overrideTrans);
						ImGui::Checkbox("##o-pat",    overrideAll ? &overrideAll : &overridePat);
						ImGui::Checkbox("##o-att",    overrideAll ? &overrideAll : &overrideAtt);
						ImGui::Checkbox("##o-scroll", overrideAll ? &overrideAll : &overrideScroll);
						ImGui::Checkbox("##o-lines",  overrideAll ? &overrideAll : &overrideLines);
					});
				});
				ImGui::SameLine();
				im::Group([&]{
					im::ItemWidth(ImGui::GetFontSize() * 9.0f, [&]{
						im::Disabled(!manMode, [&]{
							if (manMode && isMSX1) manualMode = 1;
							im::Combo("##mode", modeToStr(manualMode), [&]{
								if (ImGui::Selectable("1")) manualMode = 1;
								if (!isMSX1 && ImGui::Selectable("2")) manualMode = 2;
							});
						});
						im::Disabled(!manSize, [&]{
							im::Combo("##size", sizeToStr(manualSize), [&]{
								if (ImGui::Selectable(" 8 x  8")) manualSize =  8;
								if (ImGui::Selectable("16 x 16")) manualSize = 16;
							});
						});
						im::Disabled(!manMag, [&]{
							im::Combo("##mag", yesNo(manualMag), [&]{
								if (ImGui::Selectable("no"))  manualMag = 0;
								if (ImGui::Selectable("yes")) manualMag = 1;
							});
						});
						im::Disabled(!manTrans, [&]{
							im::Combo("##trans", yesNo(manualTransparent), [&]{
								if (ImGui::Selectable("no"))  manualTransparent = 0;
								if (ImGui::Selectable("yes")) manualTransparent = 1;
							});
						});
						im::Disabled(!manPat, [&]{
							comboHexSequence<5>("##pat", &manualPatBase, 8 * 256, vramSize, 0);
						});
						im::Disabled(!manAtt, [&]{
							comboHexSequence<5>("##att", &manualAttBase, attMult(manualMode), vramSize, manualMode == 2 ? 512 : 0);
						});
						im::Disabled(!manScroll, [&]{
							ImGui::InputInt("##verticalScroll", &manualVerticalScroll);
							manualVerticalScroll &= 0xff;
						});
						im::Disabled(!manLines, [&]{
							ImGui::Combo("##lines", &manualLines, "192\000212\000256\000");
						});
					});
				});
			});
			ImGui::SameLine();
			ImGui::Dummy(ImVec2(25, 1));
			ImGui::SameLine();
			im::Group([&]{
				ImGui::SetNextItemWidth(ImGui::GetFontSize() * 10.0f);
				ImGui::Combo("Palette", &manager.palette->whichPalette, "VDP\000Custom\000Fixed\000");
				if (ImGui::Button("Open palette editor")) {
					manager.palette->window.raise();
				}
				ImGui::Separator();
				ImGui::SetNextItemWidth(ImGui::GetFontSize() * 3.0f);
				ImGui::Combo("Zoom", &zoom, "1x\0002x\0003x\0004x\0005x\0006x\0007x\0008x\000");
				ImGui::Checkbox("grid", &grid);
				ImGui::SameLine();
				im::Disabled(!grid, [&]{
					ImGui::ColorEdit4("Grid color", gridColor.data(),
						ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar);
				});

				ImGui::TextUnformatted("Checkerboard:"sv);
				simpleToolTip("Used as background in 'Sprite attribute' and 'Rendered sprites' view");
				ImGui::SameLine();
				auto checkerBoardColorFlags = ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha;
				ImGui::ColorEdit4("checkerboard color1", checkerBoardColor1.data(), checkerBoardColorFlags);
				ImGui::SameLine();
				ImGui::ColorEdit4("checkerboard color2", checkerBoardColor2.data(), checkerBoardColorFlags);
				im::Indent([&]{
					ImGui::SetNextItemWidth(ImGui::GetFontSize() * 6.0f);
					ImGui::InputInt("size", &checkerBoardSize);
				});
			});
		});
		ImGui::Separator();

		auto copySpriteDataPopup = [&](zstring_view text, function_ref<std::string()> supplier) {
			return im::PopupContextWindow("CopySpriteDataPopup", [&]{
				if (ImGui::MenuItem(text.c_str())) {
					ImGui::SetClipboardText(supplier().c_str());
				}
			});
		};
		auto formatClipboardData = [&](unsigned address, unsigned size) {
			return formatToString([&](unsigned addr) { return vram[addr]; }, address, address + size - 1, {}, 1, {}, "%02X", manager.getInterpreter());
		};

		int mode = manMode ? manualMode : vdpMode;
		int size = manSize ? manualSize : vdpSize;
		int mag  = manMag ? manualMag  : vdpMag;
		int verticalScroll = manScroll ? manualVerticalScroll : vdpVerticalScroll;
		int lines = manLines ? (manualLines == 0 ? 192 :
		                        manualLines == 1 ? 212 :
		                                           256)
		                     : vdpLines;
		int transparent  = manTrans ? manualTransparent  : vdpTransparent;

		VramTable patTable(vram, vdp->hasEVR(), planar);
		if (mode == 3) {
			patTable.setRegister(0x3FFFF, 0);
			//patTable.setIndexSize(18);
		} else {
			unsigned patReg = (manPat ? (manualPatBase | ((8 * 256) - 1)) : vdp->getSpritePatternTableBase()) >> 11;
			patTable.setRegister(patReg, 11);
			patTable.setIndexSize(11);
		}

		VramTable attTable(vram, vdp->hasEVR(), planar);
		if (mode == 3) {
			unsigned attReg = (manAtt ? (manualAttBase | (attMult(manualMode) - 1)) : vdp->getSpriteAttributeTableBase()) >> 9;
			attTable.setRegister(attReg, 9);
			attTable.setIndexSize(9);
		} else {
			unsigned attReg = (manAtt ? (manualAttBase | (attMult(manualMode) - 1)) : vdp->getSpriteAttributeTableBase()) >> 7;
			attTable.setRegister(attReg, 7);
			attTable.setIndexSize((mode == 2) ? 10 : 7);
		}

		// create pattern texture
		if (!patternTex.get()) {
			patternTex = gl::Texture(false, false); // no interpolation, no wrapping
		}
		patternTex.bind();
		std::array<uint32_t, 256 * 64> pixels;
		if (mode == 1 || mode == 2) {
			if (size == 8) {
				renderPatterns8 (patTable, pixels);
			} else {
				renderPatterns16(patTable, pixels);
			}
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 64, 0,
			             GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
		} else if (mode == 3) {
			renderPatternsMode3(attTable, patTable, vdp->getSpritePatternTableBase(), palette, pixels);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 64, 0,
			             GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
		} else {
			pixels[0] = getColor(imColor::GRAY);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0,
			             GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
		}

		// create grid texture
		int zm = 2 * (1 + zoom);
		auto gColor = ImGui::ColorConvertFloat4ToU32(gridColor);
		if (grid) {
			size_t gridSize = size * zm;
			for (auto y : xrange(gridSize)) {
				auto* line = &pixels[y * gridSize];
				for (auto x : xrange(gridSize)) {
					line[x] = (x == 0 || y == 0) ? gColor : 0;
				}
			}
			if (!gridTex.get()) {
				gridTex = gl::Texture(false, true); // no interpolation, with wrapping
			}
			gridTex.bind();
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
			             narrow<int>(gridSize), narrow<int>(gridSize),
			             0, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
		}

		// create checker board texture
		if (checkerBoardSize) {
			pixels[0] = pixels[3] = ImGui::ColorConvertFloat4ToU32(checkerBoardColor1);
			pixels[1] = pixels[2] = ImGui::ColorConvertFloat4ToU32(checkerBoardColor2);
			if (!checkerTex.get()) {
				checkerTex = gl::Texture(false, true); // no interpolation, with wrapping
			}
			checkerTex.bind();
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0,
			             GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
		}
		im::TreeNode("Sprite patterns", ImGuiTreeNodeFlags_DefaultOpen, [&]{
			auto fullSize = gl::vec2(256, 64) * float(zm);
			im::Child("##pattern", {0, fullSize.y}, 0, ImGuiWindowFlags_HorizontalScrollbar, [&]{
				if (mode == 3) {
					ImGui::TextUnformatted("Sptterns cannot be displayed in this mode"sv);
				} else {
					auto pos1 = ImGui::GetCursorPos();
					gl::vec2 scrnPos = ImGui::GetCursorScreenPos();
					ImGui::Image(patternTex.getImGui(), fullSize);
					gl::vec2 zoomPatSize{float(size * zm)};
					bool hovered = ImGui::IsItemHovered() && (mode != 0);
					if (hovered) {
						gridPosition = trunc((gl::vec2(ImGui::GetIO().MousePos) - scrnPos) / zoomPatSize);
					}
					ImGui::SameLine();
					im::Group([&]{
						auto pattern = (size == 16) ? ((16 * gridPosition.y) + gridPosition.x) * 4
													: ((32 * gridPosition.y) + gridPosition.x) * 1;
						bool popup = copySpriteDataPopup("Copy pattern data to clipboard", [&] {
							return formatClipboardData(patTable.getAddress(8 * pattern), size == 16 ? 32 : 8);
						});
						if (hovered || popup) {
							ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 1); // HACK !!
							ImGui::StrCat("pattern: ", pattern);
							ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 1); // HACK !!
							ImGui::StrCat("address: 0x", hex_string<5>(patTable.getAddress(8 * pattern)));
							ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 1); // HACK !!
							auto recipPatTex = recip((size == 16) ? gl::vec2{16, 4} : gl::vec2{32, 8});
							auto uv1 = gl::vec2(gridPosition) * recipPatTex;
							auto uv2 = uv1 + recipPatTex;
							auto pos2 = ImGui::GetCursorPos();
							int z = (size == 16) ? 3 : 6;
							ImGui::Image(patternTex.getImGui(), float(z) * zoomPatSize, uv1, uv2);
							if (grid) {
								if (!zoomGridTex.get()) {
									zoomGridTex = gl::Texture(false, true); // no interpolation, with wrapping
								}
								int s = z * zm;
								for (auto y : xrange(s)) {
									auto* line = &pixels[y * s];
									for (auto x : xrange(s)) {
										line[x] = (x == 0 || y == 0) ? gColor : 0;
									}
								}
								zoomGridTex.bind();
								glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, s, s, 0,
									GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
								ImGui::SetCursorPos(pos2);
								ImGui::Image(zoomGridTex.getImGui(),
								             float(z) * zoomPatSize, {}, gl::vec2{float(size)});
							}
						} else {
							ImGui::Dummy(zoomPatSize);
						}
					});
					if (grid) {
						ImGui::SetCursorPos(pos1);
						ImGui::Image(gridTex.getImGui(), fullSize,
							{}, (size == 8) ? gl::vec2{32.0f, 8.0f} : gl::vec2{16.0f, 4.0f});
					}
				}
			});
		});
		ImGui::Separator();

		im::TreeNode("Sprite attributes", ImGuiTreeNodeFlags_DefaultOpen, [&]{
			auto colCount = (mode == 3) ? 16 : 8;
			auto rowCount = (mode == 3) ? 4 : 4;
			auto zoomSize = float(zm * size);
			auto fullSize = zoomSize * gl::vec2(colCount, rowCount);
			im::Child("##attrib", {0, fullSize.y}, 0, ImGuiWindowFlags_HorizontalScrollbar, [&]{
				if (mode == 0) {
					ImGui::TextUnformatted("No sprites in this screen mode"sv);
				} else {
					gl::vec2 topLeft = ImGui::GetCursorPos();
					gl::vec2 scrnPos = ImGui::GetCursorScreenPos();
					if (checkerBoardSize) {
						ImGui::SetCursorPos(topLeft);
						ImGui::Image(checkerTex.getImGui(), fullSize,
							{}, fullSize / (4.0f * float(checkerBoardSize)));
					}
					if (mode == 3) {
						for (auto row : xrange(rowCount)) {
							for (auto column : xrange(colCount)) {
								int sprite = colCount * row + column;
								ImGui::SetCursorPos(topLeft + zoomSize * gl::vec2(float(column), float(row)));
								renderMode3Pattern(sprite, float(zm), patternTex.getImGui());
							}
						}
					} else {
						for (auto row : xrange(rowCount)) {
							for (auto column : xrange(colCount)) {
								int sprite = colCount * row + column;
								ImGui::SetCursorPos(topLeft + zoomSize * gl::vec2(float(column), float(row)));
								renderSpriteAttrib(attTable, sprite, mode, size, transparent,
								                   float(zm), palette, patternTex.getImGui());
							}
						}
					}
					ImGui::SetCursorPos(topLeft);
					if (grid) {
						ImGui::Image(gridTex.getImGui(), fullSize,
							{}, gl::vec2{float(colCount), float(rowCount)});
					} else {
						ImGui::Dummy(fullSize);
					}
					gl::vec2 zoomPatSize{float(size * zm)};
					bool hovered = ImGui::IsItemHovered();
					if (hovered) {
						gridPosition = trunc((gl::vec2(ImGui::GetIO().MousePos) - scrnPos) / zoomPatSize);
					}
					auto sprite = colCount * gridPosition.y + gridPosition.x;
					auto addr = getSpriteAttrAddr(sprite, mode);
					bool popup = (mode == 2) && copySpriteDataPopup("Copy color data to clipboard", [&]{
						return formatClipboardData(attTable.getAddress(getSpriteColorAddr(sprite, mode)), size);
					});
					if (hovered || popup) {
						ImGui::SameLine();
						im::Group([&]{
							ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 1); // HACK !!
							ImGui::StrCat("sprite: ", sprite);
							ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 1); // HACK !!
							ImGui::StrCat("address: 0x", hex_string<5>(attTable.getAddress(addr)));
							ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 1); // HACK !!
							auto pos = ImGui::GetCursorPos();
							if (checkerBoardSize) {
								ImGui::Image(checkerTex.getImGui(), 3.0f * zoomPatSize,
									{}, zoomPatSize / (4.0f * float(checkerBoardSize)));
							}
							if (mode == 3) {
								ImGui::SetCursorPos(pos);
								renderMode3Pattern(sprite, float(3 * zm), patternTex.getImGui());
							} else {
								ImGui::SetCursorPos(pos);
								renderSpriteAttrib(attTable, sprite, mode, size, transparent,
								                   float(3 * zm), palette, patternTex.getImGui());
							}
						});
						ImGui::SameLine();
						im::Group([&]{
							if (mode == 3) {
								ImGui::StrCat("X: ", attTable[addr + 4],
								              "  Y: ", attTable[addr + 0] | ((attTable[addr + 1] & 0x03) << 8));
								ImGui::StrCat("PX: ", attTable[addr + 7] & 15,
								              "  PY: ", (attTable[addr + 7] >> 4) & 15, " PTS:", (attTable[addr + 5] >> 4) & 7);
								ImGui::StrCat("SZ: ", 16 << ((attTable[addr + 1] >> 6) & 3));
								ImGui::StrCat("MGX: ", (attTable[addr + 6] == 0) ? 256 : attTable[addr + 6], " MGY: ", (attTable[addr + 2] == 0) ? 256 : attTable[addr + 2]);
								ImGui::StrCat("RVX: ", (attTable[addr + 3] & 0x10) != 0 ? "rev" : "nor", " RVY: ", (attTable[addr + 3] & 0x20) != 0 ? "rev" : "nor");
								ImGui::StrCat("PS: ", attTable[addr + 3] & 0x15, " TP: ", 25 * ((attTable[addr + 3] >> 6) & 3), "%");
							} else {
								ImGui::StrCat("x: ", attTable[addr + 1],
								              "  y: ", attTable[addr + 0]);
								ImGui::StrCat("pattern: ", attTable[addr + 2]);
								if (mode == 1) {
									auto c = attTable[addr + 3];
									ImGui::StrCat("color: ", c & 15, (c & 80 ? " (EC)"sv : ""sv));
								} else if (mode == 2) {
									int colorBase = getSpriteColorAddr(sprite, mode);
									im::StyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1), [&]{ // Tighten spacing
										ImGui::TextUnformatted("Colors per line (hex):"sv);
										for (auto y : xrange(4)) {
											for (auto x : xrange(4)) {
												auto line = 4 * y + x;
												auto a = attTable[colorBase + line];
												ImGui::StrCat(hex_string<1>(line), ": ",
												              hex_string<1>(a & 15),
												              (a & 0xe0 ? '*' : ' '),
												              ' ');
												if (x != 3) ImGui::SameLine();
											}
										}
										ImGui::StrCat("address: 0x", hex_string<5>(attTable.getAddress(colorBase)));
									});
								}
							}
						});
					}
				}
			});
		});
		ImGui::Separator();

		im::TreeNode("Rendered sprites", ImGuiTreeNodeFlags_DefaultOpen, [&]{
			struct SpriteBox {
				int x, y, w, h; // box
				uint8_t sprite;
				uint16_t vramX, vramY;	//uint8_t vramX, vramY;
				uint32_t pattern;		//uint8_t pattern;
			};

			std::array<uint8_t, 256> spriteCount = {}; // zero initialize
			std::array<std::array<SpriteChecker::SpriteInfo, 64 + 1>, 256> spriteBuffer; // uninitialized
			std::array<SpriteBox, 64> spriteBoxes; // uninitialized
			uint8_t spriteCnt = 0;
			uint8_t spriteLimit;
			uint8_t stopY;

			if (mode == 3) {
				spriteLimit = 16;
				stopY = 216;
				uint8_t spriteNum = isSPS ? (vdp->getSpsTopPlane() & 63) : 0;
				for (int i = 0; i < 64; i++, spriteNum = isSPS ? ((spriteNum + SpriteChecker::SPS_NEXT_PLANE) & 63) : (spriteNum + 1)) {
					int addr = getSpriteAttrAddr(spriteNum, 3);
					int originalY = (int)attTable[addr + 0] | ((int)attTable[addr + 1] & 0x03) << 8;
					if (originalY & 0x200) originalY |= ~0x1FF;
					int x = (int)attTable[addr + 4] | ((int)attTable[addr + 5] & 0x03) << 8;
					if (x & 0x200) x |= ~0x1FF;
					if (enableStopY && (originalY == stopY && !isSPS)) break;
					int initialY = originalY;
					int mgx = attTable[addr + 6] == 0 ? 256 : attTable[addr + 6];
					int mgy = attTable[addr + 2] == 0 ? 256 : attTable[addr + 2];
					int sz = (attTable[addr + 1] >> 6) & 0x03;
					int ps = attTable[addr + 3] & 0x0F;
					int pts = (attTable[addr + 5] >> 4) & 0x07;
					int tp = (attTable[addr + 3] >> 6) & 0x03;
					bool rvx = (attTable[addr + 3] & 0x10) != 0;
					bool rvy = (attTable[addr + 3] & 0x20) != 0;
					int px = attTable[addr + 7] & 0x0F;
					int py = (attTable[addr + 7] >> 4) & 0x0F;
					unsigned pat = (pts << 15) | (py << 11) | (px << 3);
					int y = originalY;
					for (int spriteY = 0; spriteY < mgy; spriteY++, y++) { // each line in the sprite
						if (y >= 0 && y <= 255) {
							auto count = spriteCount[y];
							if (!enableLimitPerLine || (count < spriteLimit)) {
								auto& spr = spriteBuffer[y][count];
								int y2 = rvy ? (mgy - spriteY) - 1 : spriteY;
								unsigned srcY = (16 << sz) * y2 / mgy;
								unsigned offset = (vdp->getSpritePatternTableBase() + pat + (srcY << 7)) & 0x3FFFF;
								if (rvx) {
									spr.pattern = (SpriteChecker::swapNibble(patTable[offset + 7]) << 24)
												| (SpriteChecker::swapNibble(patTable[offset + 6]) << 16)
												| (SpriteChecker::swapNibble(patTable[offset + 5]) <<  8)
												| (SpriteChecker::swapNibble(patTable[offset + 4]) <<  0);
									spr.pattern2 = (SpriteChecker::swapNibble(patTable[offset + 3]) << 24)
												| (SpriteChecker::swapNibble(patTable[offset + 2]) << 16)
												| (SpriteChecker::swapNibble(patTable[offset + 1]) <<  8)
												| (SpriteChecker::swapNibble(patTable[offset + 0]) <<  0);
								} else {
									spr.pattern = (patTable[offset + 0] << 24)
												| (patTable[offset + 1] << 16)
												| (patTable[offset + 2] <<  8)
												| (patTable[offset + 3] <<  0);
									spr.pattern2 = (patTable[offset + 4] << 24)
												| (patTable[offset + 5] << 16)
												| (patTable[offset + 6] <<  8)
												| (patTable[offset + 7] <<  0);
								}
								spr.x = x;
								spr.mgx = mgx;
								spr.paletteSet = ps;
								spr.transparent = tp;
								spriteCount[y]++;
							}
						}
					}

					spriteBoxes[spriteCnt++] = SpriteBox{
						.x = x,
						.y = initialY,
						.w = mgx,
						.h = mgy,
						.sprite = spriteNum,
						.vramX = static_cast<uint16_t>(x & 0xFFFF),
						.vramY = static_cast<uint16_t>(y & 0xFFFF),
						.pattern = pat};
				}
			} else {
				spriteLimit = (mode == 1) ? 4 : 8;
				stopY = (mode == 1) ? 208 : 216;
				uint8_t patMask = (size == 8) ? 0xff : 0xfc;
				int magFactor = mag ? 2 : 1;
				auto magSize = magFactor * size;

				uint8_t spriteNum = isSPS ? (vdp->getSpsTopPlane() & 31) : 0;
				for (/**/; spriteCnt < 32; ++spriteCnt) {
					int addr = getSpriteAttrAddr(spriteNum, mode);
					uint8_t originalY = attTable[addr + 0];
					if (enableStopY && (originalY == stopY && !isSPS)) break;
					auto y = uint8_t(originalY + 1 - verticalScroll);
					int initialY = y;

					uint8_t x    = attTable[addr + 1];
					uint8_t pat  = attTable[addr + 2] & patMask;
					uint8_t att1 = attTable[addr + 3]; // only mode 1

					bool anyEC = false;
					bool anyNonEC = false;
					for (int spriteY : xrange(size)) { // each line in the sprite
						auto attr = [&]{
							if (mode != 2) return att1;
							int colorBase = getSpriteColorAddr(spriteCnt, mode);
							return attTable[colorBase + spriteY];
						}();

						bool EC = attr & 0x80;
						(EC ? anyEC : anyNonEC) = true;
						int xx = EC ? x - 32 : x;

						auto pattern = [&]{
							uint8_t p0 = patTable[8 * pat + spriteY +  0];
							SpriteChecker::SpritePattern result = p0 << 24;
							if (size == 8) return result;
							uint8_t p1 = patTable[8 * pat + spriteY + 16];
							return result | (p1 << 16);
						}();
						if (mag) pattern = SpriteChecker::doublePattern(pattern);

						for ([[maybe_unused]] int mm : xrange(magFactor)) {
							auto count = spriteCount[y];
							if (!enableLimitPerLine || (count < spriteLimit)) {
								auto& spr = spriteBuffer[y][count];
								spr.pattern = pattern;
								spr.x = narrow<int16_t>(xx);
								spr.colorAttrib = attr;

								spriteCount[y] = count + 1;
								spriteBuffer[y][count + 1].colorAttrib = 0; // sentinel (mode 2)
							}
							++y; // wraps 256->0
						}
					}
					assert(anyEC || anyNonEC);
					spriteBoxes[spriteCnt] = SpriteBox{
						.x = anyEC ? x - 32 : x,
						.y = initialY,
						.w = magSize + (anyEC && anyNonEC ? 32 : 0),
						.h = magSize,
						.sprite = spriteNum,
						.vramX = x,
						.vramY = originalY,
						.pattern = pat};

					spriteNum = isSPS ? ((spriteNum + SpriteChecker::SPS_NEXT_PLANE) & 31) : (spriteNum + 1);
				}
			}

			std::array<uint32_t, 256 * 256> screen; // TODO screen6 striped colors
			memset(screen.data(), 0, sizeof(uint32_t) * 256 * lines); // transparent
			for (auto line : xrange(lines)) {
				auto count = spriteCount[line];
				if (count == 0) continue;
				auto lineBuf = subspan<256>(screen, 256 * line);

				if (mode == 1) {
					auto visibleSprites = subspan(spriteBuffer[line], 0, count);
					for (const auto& spr : std::views::reverse(visibleSprites)) {
						uint8_t colIdx = spr.colorAttrib & 0x0f;
						if (colIdx == 0 && transparent) continue;
						auto color = palette[colIdx];

						auto pattern = spr.pattern;
						int x = spr.x;
						if (!SpriteConverter::clipPattern(x, pattern, 0, 256)) continue;

						while (pattern) {
							if (pattern & 0x8000'0000) {
								lineBuf[x] = color;
							}
							pattern <<= 1;
							++x;
						}
					}
				} else if (mode == 2) {
					auto visibleSprites = subspan(spriteBuffer[line], 0, count + 1); // +1 for sentinel

					// see SpriteConverter
					int first = 0;
					while (true /*sentinel*/) {
						if ((visibleSprites[first].colorAttrib & 0x40) == 0) [[likely]] {
							break;
						}
						++first;
					}
					for (int i = narrow<int>(count - 1); i >= first; --i) {
						const auto& spr = visibleSprites[i];
						uint8_t c = spr.colorAttrib & 0x0F;
						if (c == 0 && transparent) continue;

						auto pattern = spr.pattern;
						int x = spr.x;
						if (!SpriteConverter::clipPattern(x, pattern, 0, 256)) continue;

						while (pattern) {
							if (pattern & 0x8000'0000) {
								uint8_t color = c;
								// Merge in any following CC=1 sprites.
								for (int j = i + 1; /*sentinel*/; ++j) {
									const auto& info2 = visibleSprites[j];
									if (!(info2.colorAttrib & 0x40)) break;
									unsigned shift2 = x - info2.x;
									if ((shift2 < 32) &&
									((info2.pattern << shift2) & 0x8000'0000)) {
										color |= info2.colorAttrib & 0x0F;
									}
								}
								// TODO screen 6
								//	auto pixL = palette[color >> 2];
								//	auto pixR = palette[color & 3];
								//	lineBuf[x * 2 + 0] = pixL;
								//	lineBuf[x * 2 + 1] = pixR;
								lineBuf[x] = palette[color];
							}
							++x;
							pattern <<= 1;
						}
					}
				} else if (mode == 3) {
					auto visibleSprites = subspan(spriteBuffer[line], 0, count);
					for (const auto& spr : std::views::reverse(visibleSprites)) {
						uint64_t pattern = ((uint64_t)spr.pattern << 32) | (uint64_t)spr.pattern2;
						int color_base = (spr.paletteSet << 4) | (spr.transparent << 8);
						for (int i = 0; i < spr.mgx; i++) {
							int x = spr.x + i;
							if (x >= 0 && x <= 255) {
								int patX = 16 * i / spr.mgx;
								uint8_t color = (pattern >> (60 - patX * 4)) & 0x0F;
								if (color != 0 && lineBuf[x] == 0) {
									lineBuf[x] = palette[color_base | color];
								}
							}
						}
					}
				}
			}
			if (!renderTex.get()) {
				renderTex = gl::Texture(false, true); // no interpolation, with wrapping
			}
			renderTex.bind();
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, lines, 0,
			             GL_RGBA, GL_UNSIGNED_BYTE, screen.data());

			std::array<SpriteBox, 2 * 32> clippedBoxes;
			int nrClippedBoxes = 0;
			auto addClippedBox = [&](SpriteBox b) {
				assert(nrClippedBoxes < 64);
				clippedBoxes[nrClippedBoxes] = b;
				++nrClippedBoxes;
			};
			for (int sprite : xrange(spriteCnt)) {
				const auto& b = spriteBoxes[sprite];
				int x = b.x;
				int y = b.y;
				int w = b.w;
				int h = b.h;
				if (x < 0) {
					w += x;
					if (w <= 0) continue;
					x = 0;
				} else if (x + w > 256) {
					w = 256 - x;
				}

				int yEnd = y + h;
				if (yEnd < 256) {
					addClippedBox(SpriteBox{x, y, w, h, b.sprite, b.vramX, b.vramY, b.pattern});
				} else {
					addClippedBox(SpriteBox{x, y, w, 256 - y, b.sprite, b.vramX, b.vramY, b.pattern});
					addClippedBox(SpriteBox{x, 0, w, yEnd - 256, b.sprite, b.vramX, b.vramY, b.pattern});
				}
			}

			auto fullSize = float(zm) * gl::vec2(256, float(lines));
			im::Child("##screen", {0.0f, fullSize.y}, 0, ImGuiWindowFlags_HorizontalScrollbar, [&]{
				auto* drawList = ImGui::GetWindowDrawList();
				gl::vec2 scrnPos = ImGui::GetCursorScreenPos();
				auto boxColor = ImGui::ColorConvertFloat4ToU32(boundingBoxColor);
				auto drawBox = [&](int x, int y, int w, int h) {
					gl::vec2 tl = scrnPos + gl::vec2{float(x), float(y)} * float(zm);
					gl::vec2 br = tl + gl::vec2{float(w), float(h)} * float(zm);
					drawList->AddRect(tl, br, boxColor);
				};

				gl::vec2 topLeft = ImGui::GetCursorPos();
				if (checkerBoardSize) {
					ImGui::Image(checkerTex.getImGui(), fullSize,
						{}, fullSize / (4.0f * float(checkerBoardSize)));
				}
				ImGui::SetCursorPos(topLeft);
				ImGui::Image(renderTex.getImGui(), fullSize);
				bool hovered = ImGui::IsItemHovered();
				auto hoverPos = trunc((gl::vec2(ImGui::GetIO().MousePos) - scrnPos) / gl::vec2(float(zm)));
				ImGui::SameLine();

				im::Group([&]{
					ImGui::Checkbox("Bounding box", &drawBoundingBox);
					im::Indent([&]{
						im::Disabled(!drawBoundingBox, [&]{
							ImGui::ColorEdit4("color", boundingBoxColor.data(),
								ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
							ImGui::RadioButton("On hovered sprites", &boundingBoxOnAll, 0);
							ImGui::RadioButton("On all sprites", &boundingBoxOnAll, 1);

						});
					});
					{
						auto maxStr = tmpStrCat("Max ", spriteLimit, " sprites per line");
						ImGui::Checkbox(maxStr.c_str(), &enableLimitPerLine);
					}
					{
						auto stopStr = tmpStrCat("Stop at y=", stopY);
						ImGui::Checkbox(stopStr.c_str(), &enableStopY);
					}

					if (hovered) {
						ImGui::Separator();
						auto [hx, hy] = hoverPos;
						ImGui::Text("x=%d y=%d", hx, hy);
						ImGui::Spacing();

						for (int i : xrange(nrClippedBoxes)) {
							const auto& b = clippedBoxes[i];
							if ((b.x <= hx) && (hx < (b.x + b.w)) &&
							    (b.y <= hy) && (hy < (b.y + b.h))) {
								if (drawBoundingBox && (boundingBoxOnAll == 0)) {
									drawBox(b.x, b.y, b.w, b.h);
								}
								ImGui::Text("sprite=%d x=%d y=%d pat=%d", b.sprite, b.vramX, b.vramY, b.pattern);
							}
						}
					}
				});

				if (drawBoundingBox && (boundingBoxOnAll == 1)) {
					for (int i : xrange(nrClippedBoxes)) {
						const auto& b = clippedBoxes[i];
						drawBox(b.x, b.y, b.w, b.h);
					}
				}
			});
		});

	});
}

} // namespace openmsx
