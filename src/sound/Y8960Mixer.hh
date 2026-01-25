#ifndef Y8960MIXER_HH
#define Y8960MIXER_HH

#include "MSXDevice.hh"
#include "serialize_meta.hh"
#include "XMLElement.hh"

#include <array>
#include <vector>

namespace openmsx {

class Y8960Mixer final : public MSXDevice
{
public:
	static constexpr  int ChannelCount = 8;

    explicit Y8960Mixer(const DeviceConfig& config);
	~Y8960Mixer() override;

    void reset(EmuTime time) override;
	//void powerDown(EmuTime time) override;
	[[nodiscard]] byte readIO(uint16_t port, EmuTime time) override;
	[[nodiscard]] byte peekIO(uint16_t port, EmuTime time) const override;
	void writeIO(uint16_t port, byte value, EmuTime time) override;

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

private:
    void updateBalance(int ch);

private:
    std::array<std::vector<std::string_view>, ChannelCount> channelDevices;
    std::array<byte, ChannelCount> regs;
    byte registerLatch;
};
SERIALIZE_CLASS_VERSION(Y8960Mixer, 1);

} // namespace openmsx

#endif
