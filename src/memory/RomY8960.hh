#ifndef ROMY8960_HH
#define ROMY8960_HH

#include "RomBlocks.hh"
#include "SCC.hh"
#include "Y8960OPLL.hh"

namespace openmsx {

class RomY8960 final : public Rom8kBBlocks
{
public:
	RomY8960(const DeviceConfig& config, Rom&& rom);

	void powerUp(EmuTime time) override;
	void reset(EmuTime time) override;
	[[nodiscard]] byte peekMem(uint16_t address, EmuTime time) const override;
	[[nodiscard]] byte readMem(uint16_t address, EmuTime time) override;
	[[nodiscard]] const byte* getReadCacheLine(uint16_t address) const override;
	void writeMem(uint16_t address, byte value, EmuTime time) override;
	[[nodiscard]] byte* getWriteCacheLine(uint16_t address) override;

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

private:
	void bankSwitch(unsigned page, unsigned block);

private:
	Y8960OPLL *opll_1;
	Y8960OPLL *opll_2;
	SCC scc;
	bool sccEnabled;
};

} // namespace openmsx

#endif
