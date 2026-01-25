#include "Y8960Mixer.hh"

#include "MSXMotherBoard.hh"
#include "MSXMixer.hh"
#include "serialize.hh"

//#include "StringOp.hh"
//#include "checked_cast.hh"
//#include "stl.hh"

namespace openmsx {

Y8960Mixer::Y8960Mixer(const DeviceConfig& config)
	: MSXDevice(config)
{
	for (auto e : config.getXML()->getChildren("channel")) {
		std::string_view idRef = e->getAttributeValue("idref", "");
		if (idRef == "") continue;

		int num = e->getAttributeValueAsInt("num", 0);
		if (num < 0 || num >= ChannelCount) {
			throw MSXException("Invalid channel number(", num, ") device '", idRef, "'");
		}

		channelDevices[num].push_back(idRef);
	}
	reset(getCurrentTime());
}

Y8960Mixer::~Y8960Mixer()
{
	getMotherBoard().getMSXMixer().selectExternal(false);
	for(int i = 0; i < ChannelCount; i++) channelDevices[i].clear();
}

void Y8960Mixer::reset(EmuTime time)
{
	getMotherBoard().getMSXMixer().selectExternal(true);
	registerLatch = 0;
	for(int i = 0; i < ChannelCount; i++) {
		regs[i] = 0;
	}
	for(int i = 0; i < ChannelCount; i++) {
		for (std::string_view device : channelDevices[i]) {
			getMotherBoard().getMSXMixer().setExternal(device, true);
		}
		updateBalance(i);
	}
}

byte Y8960Mixer::readIO(uint16_t port, EmuTime time)
{
	switch (port & 0x01) {
	case 0:
		return registerLatch;
	case 1:
		return registerLatch < ChannelCount ? regs[registerLatch] : 0;
	default:
		return 0xFF;
	}
}

byte Y8960Mixer::peekIO(uint16_t /*port*/, EmuTime time) const
{
	return registerLatch < ChannelCount ? regs[registerLatch] : 0;
}

void Y8960Mixer::writeIO(uint16_t port, byte value, EmuTime time)
{
	switch (port & 0x01) {
	case 0:
		registerLatch = value & 0x01;
		break;
	case 1:
		if (registerLatch < ChannelCount) {
			regs[registerLatch] = value;
			updateBalance(registerLatch);
		}
		break;
	}
}

void Y8960Mixer::updateBalance(int ch)
{
	int balance = (regs[ch] & 0x02) ? ((regs[ch] & 0x01) ? 100 : -100) : 0;
	for (std::string_view device : channelDevices[ch]) {
		getMotherBoard().getMSXMixer().setBalance(device, balance);
	}
}

template<typename Archive>
void Y8960Mixer::serialize(Archive& ar, unsigned version)
{
	ar.template serializeBase<MSXDevice>(*this);
	ar.serialize("registerLatch", registerLatch);
	for (int i = 0; i < ChannelCount; i++) {
		ar.serialize("ch" + i, regs[i]);
	}
	if constexpr (Archive::IS_LOADER) {
		for(int i = 0; i < ChannelCount; i++) {
			updateBalance(i);
		}
	}
	// selectedPort is derived from portB
}
INSTANTIATE_SERIALIZE_METHODS(Y8960Mixer);
REGISTER_MSXDEVICE(Y8960Mixer, "Y8960MIXER");

} // namespace openmsx
