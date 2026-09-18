#pragma once

#include <cstdint>

namespace apu {

// Stores the guest XAudio render-driver callback and starts the host
// worker thread that periodically invokes it (UnleashedRecomp pattern).
uint32_t RegisterClient(uint32_t callback, uint32_t userData);
void UnregisterClient();
void SubmitFrames(void* samples);
void Init();
void Shutdown();

} // namespace apu
