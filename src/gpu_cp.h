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

// Capture the guest driver-extension object (GuestDevice VA whose [+10896]
// holds the ring context). Its ctx[+0]/[+4]/[+60] are three views of the
// ring read pointer polled by different guest waiters (sub_82411218 polls
// +60, sub_82411E94 polls +0, sub_82411180-style barriers poll +4); the
// kernel CP on HW keeps them in sync via the write-back + interrupt handler.
void CpAttachDriverCtx(uint32_t devVA);

// Account a driver push-buffer window whose bytes are now resident (capture
// v2 deferred-drain). Advances the consumption watermark that feeds the
// ctx[+0]/[+4] mirrors (guest free-space/progress predicates operate in
// this VA space) and bumps the submitting thread's progress counter by
// dwords. Call from the thread running guest code (counter chain uses its
// live PPC context).
void CpConsumePushWindow(uint32_t endVA, uint32_t dwords);

// EXPERIMENT (2026-08-23, falsifiable): xenia never maintains KTHREAD+0x58
// (MCLA freezes there too), yet sub_82412F98 requires delta>=5000. We bump
// the submitting thread's progress block by `amount` per vblank tick from
// the vsync pump - mirroring MarkVblink placement. Revert if disproven.
void CpVblankBump(uint32_t amount);

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
