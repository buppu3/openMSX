#ifndef Y8960OPLL_HH
#define Y8960OPLL_HH

#include "MSXMusic.hh"

#include "RomBlockDebuggable.hh"
#include "SRAM.hh"
#include "serialize_meta.hh"

namespace openmsx {

class Y8960OPLL final : public MSXMusicY8960
{
public:
	explicit Y8960OPLL(DeviceConfig& config);

	void reset(EmuTime time) override;
	void writeIO(uint16_t port, byte value, EmuTime time) override;
	[[nodiscard]] byte readMem(uint16_t address, EmuTime time) override;
	void writeMem(uint16_t address, byte value, EmuTime time) override;
	[[nodiscard]] const byte* getReadCacheLine(uint16_t address) const override;
	[[nodiscard]] byte* getWriteCacheLine(uint16_t address) override;

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

private:
	RomBlockDebuggable romBlockDebug;
	//byte enable;
	byte bank;
};
SERIALIZE_CLASS_VERSION(Y8960OPLL, 3); // must be in-sync with MSXMusicBase

} // namespace openmsx

#endif
