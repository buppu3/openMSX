#ifndef Y8960MIXER_HH
#define Y8960MIXER_HH

#include "MSXDevice.hh"
#include "serialize_meta.hh"
#include "XMLElement.hh"
#include "BooleanSetting.hh"

#include <array>
#include <vector>

namespace openmsx {

class Y8960Mixer final : public MSXDevice, private Observer<Setting>
{
public:
	static constexpr int ChannelCount = 10;
	static constexpr int RegCount = ChannelCount * 2;

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
	int convRegToChNum(uint8_t num);
	float convRegToGain(uint8_t val);
    void updateBalance(int ch);
	void updateSelector();

	void update(const Setting& setting) noexcept override;

private:
    std::array<std::vector<std::string_view>, ChannelCount> channelDevices;
    std::array<byte, RegCount> regs;
    byte registerLatch;
	std::unique_ptr<BooleanSetting> cmdExternalSoundSetting;
};
SERIALIZE_CLASS_VERSION(Y8960Mixer, 1);

} // namespace openmsx

#endif
