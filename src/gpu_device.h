#pragma once

#include <cstdint>

namespace mcla::gpu {

// UnleashedRecomp-style device boundary for MCLA.
//
// The game's embedded XGPU/D3D runtime creates its device object inside
// sub_82413588 (0x5E00-byte allocation, out-pointer in r8 - verified against
// generated ppc_recomp.77.cpp). We intercept+passthrough so the real driver
// keeps running, capture the live device guest VA, and dump its layout once
// to ground-truth field offsets before redirecting anything.

constexpr uint32_t kMclaDeviceCreateAddr = 0x82413588;

// Live device guest VA once creation succeeded; 0 before that.
uint32_t DeviceGuestAddr();

// Captured draw data for native renderer (V2 - safe VB/IB capture)
struct CapturedDrawV2
{
    uint32_t seq = 0;
    uint32_t dev = 0;
    uint32_t primTypeFlags = 0;
    uint32_t vbBase = 0, vbStride = 0, vbSize = 0;
    uint32_t ibBase = 0, ibSize = 0, ibFmt = 0;
    uint32_t frameId = 0;
    // Shader programs for PSO lookup
    uint32_t vsProgram = 0;
    uint32_t psProgram = 0;
    // grcFvf vertex declaration
    uint32_t fvfMask = 0;
    uint8_t  fvfSize = 0;
    uint8_t  fvfFlags = 0;
    uint8_t  fvfDynamicOrder = 0;
    uint8_t  fvfChannelCount = 0;
    uint64_t fvfTypes = 0;
    uint8_t  hasGrcFvf = 0;
};

// Access captured draw data for native renderer
const CapturedDrawV2* mcla_gpu_GetLastDrawV2();
uint32_t mcla_gpu_GetFrameCounter();

} // namespace mcla::gpu
