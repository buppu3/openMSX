#ifndef ROMY8960_HH
#define ROMY8960_HH

#include "RomBlocks.hh"
#include "Ram.hh"
#include "SCC.hh"
#include "Y8960OPLL.hh"

namespace openmsx {

class RomY8960 final : public Rom8kBBlocks
{
public:
	static constexpr int RomBankCounts = 16;
	static constexpr int RamBankCounts = 16;

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
	bool isRamRegion(unsigned int region) const;
	uint8_t getBank(unsigned int region) const;
	void setBank(unsigned int region, uint8_t bank);
	const unsigned int getRamAddress(uint16_t address) const;
	unsigned int convAddressToRegion(uint16_t address) const;

private:
	MSXDevice *opll_0;
	MSXDevice *opll_1;
	SCC scc;
	Ram ram;
	bool sccEnabled;
	bool ramEnabled;
	std::array<uint8_t, 4> bankReg;
};

} // namespace openmsx

#endif
