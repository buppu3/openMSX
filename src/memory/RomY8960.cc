// Y8960 mapper
//
// memory mapped I/O
//    Always-valid register:
//  	RamEnable:  0x48FB, 0x49FB, 0x4AFB, 0x4BFB, 0x4CFB, 0x4DFB, 0x4EFB, 0x4FFB
//					Enable RAM write control
//
//  	OPLL0:      0x7FF4 - 0x7FF5
//					tunnel to OPLL0 I/O port
//
//  	OPLL1: 		0x7FF2 - 0x7FF3
//					tunnel to OPLL1 I/O port
//
//  	SCC:		0x9800 - 0x9FFF(bank#63)
//					SCC sound register
//
//    Registers available when RamEnable is 0:
//  	bank 1: 	0x5000 - 0x57ff
//					Bank switch for 0x4000-0x5FFF
//
//  	bank 2: 	0x7000 - 0x77ff
//					Bank switch for 0x6000-0x7FFF
//
//  	bank 3: 	0x9000 - 0x97ff
//					Bank switch for 0x8000-0x9FFF
//
//  	bank 4: 	0xB000 - 0xB7ff
//					Bank switch for 0xA000-0xBFFF
//
//    Registers available when RamEnable is 1:
//  	bank 1: 	0x48FC, 0x49FC, 0x4AFC, 0x4BFC, 0x4CFC, 0x4DFC, 0x4EFC, 0x4FFC
//					Bank switch for 0x4000-0x5FFF
//
//  	bank 2: 	0x48FD, 0x49FD, 0x4AFD, 0x4BFD, 0x4CFD, 0x4DFD, 0x4EFD, 0x4FFD
//					Bank switch for 0x6000-0x7FFF
//
//  	bank 3: 	0x48FE, 0x49FE, 0x4AFE, 0x4BFE, 0x4CFE, 0x4DFE, 0x4EFE, 0x4FFE
//					Bank switch for 0x8000-0x9FFF
//
//  	bank 4: 	0x48FF, 0x49FF, 0x4AFF, 0x4BFF, 0x4CFF, 0x4DFF, 0x4EFF, 0x4FFF
//					Bank switch for 0xA000-0xBFFF
// bank
//		 0 - 15		ROM bank
//		16 - 31		RAM bank
//		63			SCC sound register

#include "RomY8960.hh"

#include "CacheLine.hh"
#include "MSXCliComm.hh"
#include "MSXMotherBoard.hh"
#include "serialize.hh"

#include "xrange.hh"

namespace openmsx {

RomY8960::RomY8960(const DeviceConfig& config, Rom&& rom_)
	: Rom8kBBlocks(config, std::move(rom_))
	, ram(config, getName() + " ram", "ram", 8192 * RamBankCounts)
	, scc(getName(), config, getCurrentTime())
{
	// warn if a ROM is used that would not work on a real KonamiSCC mapper
	if (rom.size() > 8192 * RomBankCounts) {
		getMotherBoard().getMSXCliComm().printWarning(
			"The size of this ROM image is larger than ", 8 * RomBankCounts, "kB, "
			"which is not supported on real Konami SCC mapper "
			"chips!");
	}

	std::string_view devName1 = config.getChildData("opll0", "");
	if (devName1 == "") {
		opll_0 = nullptr;
	} else {
		opll_0 = getMotherBoard().findDevice(devName1);
	}

	if (opll_0 == nullptr) {
		getMotherBoard().getMSXCliComm().printWarning("can not found device '", devName1, "'.");
	}

	std::string_view devName2 = config.getChildData("opll1", "");
	if (devName2 == "") {
		opll_1 = nullptr;
	} else {
		opll_1 = getMotherBoard().findDevice(devName2);
	}

	if (opll_1 == nullptr) {
		getMotherBoard().getMSXCliComm().printWarning("can not found device '", devName2, "'.");
	}

	powerUp(getCurrentTime());
}

void RomY8960::powerUp(EmuTime time)
{
	scc.powerUp(time);
	reset(time);
}

void RomY8960::bankSwitch(unsigned page, unsigned block)
{
	setRom(page, block);

	// Note: the mirror behavior is different from RomKonami !
	if (page == 2 || page == 3) {
		// [0x4000-0x8000), mirrored in [0xC000-0x10000)
		setRom(page + 4, block);
	} else if (page == 4 || page == 5) {
		// [0x8000-0xC000), mirrored in [0x0000-0x4000)
		setRom(page - 4, block);
	} else {
		assert(false);
	}
}

bool RomY8960::isRamRegion(unsigned int region) const
{
	uint8_t bank = bankReg[region];
	if ((bank & 0x3F) == 0x3F) return false;	// SCC bank
	return bank >= RomBankCounts;
}

uint8_t RomY8960::getBank(unsigned int region) const
{
	return bankReg[(region - 2) & 3];
}

void RomY8960::setBank(unsigned int region, uint8_t bank)
{
	bankReg[(region - 2) & 3] = bank;
}

const unsigned int RomY8960::getRamAddress(uint16_t address) const
{
	uint8_t bank = getBank(convAddressToRegion(address)) - RomBankCounts; 
	assert(bank >= 0);
	assert(bank < RamBankCounts);
	return (bank * 0x2000) + (address & 0x1FFF);
}

unsigned int RomY8960::convAddressToRegion(uint16_t address) const
{
	return address >> 13;
}

void RomY8960::reset(EmuTime time)
{
	for (auto i : xrange(2, 6)) {
		bankSwitch(i, i - 2);
		setBank(i, i - 2);
	}

	sccEnabled = false;
	scc.reset(time);
}

byte RomY8960::peekMem(uint16_t address, EmuTime time) const
{
	if (sccEnabled && (0x9800 <= address) && (address < 0xA000)) {
		return scc.peekMem(narrow_cast<uint8_t>(address & 0xFF), time);
	} else if (isRamRegion(convAddressToRegion(address))) {
		return ram[getRamAddress(address)];
	} else {
		return Rom8kBBlocks::peekMem(address, time);
	}
}

byte RomY8960::readMem(uint16_t address, EmuTime time)
{
	if (sccEnabled && (0x9800 <= address) && (address < 0xA000)) {
		return scc.readMem(narrow_cast<uint8_t>(address & 0xFF), time);
	} else if (isRamRegion(convAddressToRegion(address))) {
		return ram[getRamAddress(address)];
	} else {
		return Rom8kBBlocks::readMem(address, time);
	}
}

const byte* RomY8960::getReadCacheLine(uint16_t address) const
{
	if (sccEnabled && (0x9800 <= address) && (address < 0xA000)) {
		// don't cache SCC
		return nullptr;
	} else if (isRamRegion(convAddressToRegion(address))) {
		// read from ram
		return &ram[getRamAddress(address)];
	} else {
		// read from rom
		return Rom8kBBlocks::getReadCacheLine(address);
	}
}

void RomY8960::writeMem(uint16_t address, byte value, EmuTime time)
{
	if ((address < 0x4800) || (address >= 0xC000)) {
		return;
	}

	// write to SCC
	if (sccEnabled && (0x9800 <= address) && (address < 0xA000)) {
		scc.writeMem(narrow_cast<uint8_t>(address & 0xFF), value, time);
		return;
	}

	// write to RAM(0x4000-0x5FFF is write-protected)
	if (ramEnabled && isRamRegion(convAddressToRegion(address)) && address >= 0x6000) {
		ram[getRamAddress(address)] = value;
	}

	// write to OPLL1
	if ((address & 0xFFFE) == 0x7FF4) {
		if(opll_0 != nullptr) opll_0->writeIO(address & 1, value, time);
	}

	// write to OPLL2
	if ((address & 0xFFFE) == 0x7FF2) {
		if(opll_1 != nullptr) opll_1->writeIO(address & 1, value, time);
	}

	// write to ramEnable register
	if ((address & 0xF8FF) == 0x48FB) {
		ramEnabled = value & 1;
	}

	// write to bank register
	unsigned int region = 0;
	bool pageSelect = false;
	if (!ramEnabled && (address & 0x1800) == 0x1000) {
		pageSelect = true;
		region = convAddressToRegion(address);
	} else if (ramEnabled && (address & 0xF8FC) == 0x48FC) {
		pageSelect = true;
		region = (address & 3) + 2;
	}
	if (pageSelect) {
		uint8_t oldBank = getBank(region);
		setBank(region, value);

		// invaildate cache
		if (value != oldBank) {
			invalidateDeviceRWCache(region << 13, 8192);
		}

		// SCC enable/disable
		bool newSccEnabled = sccEnabled;
		if (region == 4) {
			newSccEnabled = ((value & 0x3F) == 0x3F);
			if (newSccEnabled != sccEnabled) {
				sccEnabled = newSccEnabled;
			}
		}

		// switch rom bank
		bankSwitch(region, value);
	}
}

byte* RomY8960::getWriteCacheLine(uint16_t address)
{
	if ((address < 0x4800) || (address >= 0xC000)) {
		return unmappedWrite.data();
	} else if (address < 0x5000) {
		// page selection(0x4800~0x4FFF)
		return nullptr;
	} else if ((address & 0xFF00) == (0x7FF0 & CacheLine::HIGH)) {
		// write to OPLL(0x7F00~0x7FFF)
		return nullptr;
	} else if (sccEnabled && (0x9800 <= address) && (address < 0xA000)) {
		// write to SCC
		return nullptr;
	} else if ((address & 0xF800) == (0x9000 & CacheLine::HIGH)) {
		// SCC enable/disable
		return nullptr;
	} else if ((address & 0x1800) == (0x1000 & CacheLine::HIGH)) {
		// page selection
		return nullptr;
	} else if (ramEnabled && isRamRegion(convAddressToRegion(address)) && address >= 0x6000) {
		// write to RAM
		return &ram[getRamAddress(address)];
	} else {
		return unmappedWrite.data();
	}
}

template<typename Archive>
void RomY8960::serialize(Archive& ar, unsigned /*version*/)
{
	ar.template serializeBase<Rom8kBBlocks>(*this);
	ar.serialize("scc",        scc,
	             "sccEnabled", sccEnabled,
				 "bankReg",	   bankReg,
				 "ramEnabled", ramEnabled,
				 "ram",		   ram);
}
INSTANTIATE_SERIALIZE_METHODS(RomY8960);
REGISTER_MSXDEVICE(RomY8960, "RomY8960");

} // namespace openmsx
