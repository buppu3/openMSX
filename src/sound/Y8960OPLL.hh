#ifndef Y8960OPLL_HH
#define Y8960OPLL_HH

#include "MSXDevice.hh"
#include "YM2413.hh"
#include "serialize_meta.hh"

namespace openmsx {

class Y8960OPLL final : public MSXDevice
{
public:
	explicit Y8960OPLL(DeviceConfig& config);

	void reset(EmuTime time) override;
	void writeIO(uint16_t port, byte value, EmuTime time) override;
	void writePort(bool port, byte value, EmuTime time);

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);
protected:
	YM2413 ym2413;
};
SERIALIZE_CLASS_VERSION(Y8960OPLL, 3); // must be in-sync with MSXMusicBase

} // namespace openmsx

#endif
