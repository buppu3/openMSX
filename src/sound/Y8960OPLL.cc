#include "Y8960OPLL.hh"

#include "CacheLine.hh"
#include "serialize.hh"

namespace openmsx {

Y8960OPLL::Y8960OPLL(DeviceConfig& config)
	: MSXMusicY8960(config)
	, romBlockDebug(*this, std::span{&bank, 1}, 0x4000, 0x4000, 14)
{
	reset(getCurrentTime());
}

void Y8960OPLL::reset(EmuTime time)
{
	MSXMusicY8960::reset(time);
	//enable = 0;
	bank = 0;
}

void Y8960OPLL::writeIO(uint16_t port, byte value, EmuTime time)
{
	MSXMusicY8960::writeIO(port & 3, value, time);
}

byte Y8960OPLL::readMem(uint16_t address, EmuTime /*time*/)
{
	address &= 0x3FFF;
	switch (address) {
	//case 0x3FF6:
	//	return enable;
	case 0x3FF7:
		return bank;
	default:
		return rom[bank * 0x4000 + address];
	}
}

const byte* Y8960OPLL::getReadCacheLine(uint16_t address) const
{
	address &= 0x3FFF;
	if (address == (0x3FF6 & CacheLine::HIGH)) {
		return nullptr;
	}
	return &rom[bank * 0x4000 + address];
}

void Y8960OPLL::writeMem(uint16_t address, byte value, EmuTime time)
{
	// 'enable' has no effect for memory mapped access
	//   (thanks to BiFiMSX for investigating this)
	address &= 0x3FFF;
	switch (address) {
	case 0x3FF2: // address
	case 0x3FF3: // data
	case 0x3FF4: // address
	case 0x3FF5: // data
		writePort((address & 2) != 0, address & 1, value, time);
		break;
	//case 0x3FF6:
	//	enable = value & 0x11;
	//	break;
	case 0x3FF7: {
		if (byte newBank = value & 0x03; bank != newBank) {
			bank = newBank;
			invalidateDeviceRCache();
		}
		break;
	}
	}
}

byte* Y8960OPLL::getWriteCacheLine(uint16_t address)
{
	address &= 0x3FFF;
	if (address == (0x3FF4 & CacheLine::HIGH)) {
		return nullptr;
	}
	return unmappedWrite.data();
}

template<typename Archive>
void Y8960OPLL::serialize(Archive& ar, unsigned version)
{
	ar.template serializeInlinedBase<MSXMusicY8960>(*this, version);
	ar.serialize(//"enable", enable,
	             "bank",   bank);
}
INSTANTIATE_SERIALIZE_METHODS(Y8960OPLL);
REGISTER_MSXDEVICE(Y8960OPLL, "Y8960-OPLL");

} // namespace openmsx
