#pragma once

#include <cstdint>

namespace apu {

uint32_t RegisterClient(uint32_t callback, uint32_t userData);
void SubmitFrames(void* samples);
void Init();
void Shutdown();

} // namespace apu