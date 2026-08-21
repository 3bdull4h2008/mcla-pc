#include "audio.h"
#include "logging.h"

namespace apu {

uint32_t RegisterClient(uint32_t callback, uint32_t userData) {
    MCLA_LOG_INFO("apu::RegisterClient: callback=0x{:x}, userData=0x{:x}", callback, userData);
    return 1; // Dummy driver ID
}

void SubmitFrames(void* samples) {
    (void)samples;
}

void Init() {
    MCLA_LOG_INFO("apu::Init");
}

void Shutdown() {
    MCLA_LOG_INFO("apu::Shutdown");
}

} // namespace apu