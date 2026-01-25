#include "Y8960OPLL.hh"

#include "CacheLine.hh"
#include "serialize.hh"

namespace openmsx {

Y8960OPLL::Y8960OPLL(DeviceConfig& config)
	: MSXDevice(config)
	, ym2413(getName(), config)
{
	reset(getCurrentTime());
}

void Y8960OPLL::reset(EmuTime time)
{
	ym2413.reset(time);
}

void Y8960OPLL::writeIO(uint16_t port, byte value, EmuTime time)
{
	writePort(port & 1, value, time);
}

void Y8960OPLL::writePort(bool port, byte value, EmuTime time)
{
	ym2413.writePort(port, value, time);
}

template<typename Archive>
void Y8960OPLL::serialize(Archive& ar, unsigned version)
{
	ar.template serializeBase<MSXDevice>(*this);
	ar.serialize("ym2413", ym2413);
}
INSTANTIATE_SERIALIZE_METHODS(Y8960OPLL);
REGISTER_MSXDEVICE(Y8960OPLL, "Y8960-OPLL");

} // namespace openmsx
