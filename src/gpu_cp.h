#pragma once

#include <cstdint>

namespace mcla::gpu {

// Xenia-model Xenos primary-ring command processor (Phase 4).
//
// The game's kernel-mode driver writes PM4 packets into the primary ring
// (registered via VdInitializeRingBuffer) and rings the doorbell by storing
// the new write-pointer dword index into XGPU register CP_RB_WPTR
// (register index 0x01C5 -> physical 0x7FC80714). We intercept those stores
// in the checked guest-accessor path, drain the ring from the current read
// index up to the rung write index (wrap-aware, big-endian dwords), and
// write the advanced read index back as a BE dword to the address registered
// via VdEnableRingBufferRPtrWriteBack - which is what an idle submitter
// polls before refilling the ring.

void CpInitializeRingBuffer(uint32_t physAddr, uint32_t sizeLog2);
void CpEnableRPtrWriteBack(uint32_t rptrWritebackAddr, uint32_t blockSizeLog2);

// Returns true when guestAddr lies inside the XGPU MMIO window and was
// consumed (never written through to RAM).
bool CpMmioWrite(uint32_t guestAddr, uint32_t value);
bool CpMmioRead(uint32_t guestAddr, uint32_t* outValue);

// Installs the MMIO interceptors into mcla::native's guest accessors.
void CpInstallMmioRouting();

// Diagnostics.
uint64_t CpSwapCount();
uint64_t CpDrainCount();

} // namespace mcla::gpu
