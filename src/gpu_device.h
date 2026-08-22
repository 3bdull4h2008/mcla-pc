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

} // namespace mcla::gpu
