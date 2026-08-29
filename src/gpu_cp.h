#pragma once

#include <cstdint>

namespace mcla::gpu {

// Xenia-model Xenos command processor with PER-RING state (Phase 4).
//
// Ring identity is the exact (baseGuestVA, capacityDwords) pair passed to
// VdInitializeRingBuffer; each registered ring owns its rptr and its own
// write-back address (VdEnableRingBufferRPtrWriteBack binds to the most
// recently initialized ring - the Xenos CP has exactly one primary ring
// doorbell). The game's kernel-mode driver writes PM4 packets into a ring
// and rings the doorbell by storing the new write-pointer dword index into
// XGPU register CP_RB_WPTR (register index 0x01C5 -> physical 0x7FC80714).
// We intercept those stores in the checked guest-accessor path, drain THE
// owning ring from its read index up to the rung write index (wrap-aware,
// big-endian dwords), and write that ring's advanced read index back as a BE
// dword to ITS registered write-back address - which is what an idle
// submitter polls before refilling the ring.
//
// Write-back addresses arriving below 0x20000000 are PHYSICAL forms (the
// genuine guest call site passes phys(subctx+60)); they are published through
// their kernel-VA alias PA|0xC0000000 where guest waiters poll them.

void CpInitializeRingBuffer(uint32_t physAddr, uint32_t sizeLog2);
void CpEnableRPtrWriteBack(uint32_t rptrWritebackAddr, uint32_t blockSizeLog2);

// Register a guest driver-extension object (GuestDevice VA whose [+10896]
// holds the 96-byte ring-context object). Idempotent; keeps a small registry -
// MCLA binds a SECOND GuestDevice (A0009100) of the same class at create.
// IDA-proven field semantics (2026-08-26): *(ctx+0) = consumed-window COUNT
// (init 1), dev[+10908] = production window COUNT (init 3, +2/reserve);
// sub_82411E98 waits until count >= needed. Not ring pointers.
void CpAttachDriverCtx(uint32_t devVA);

// Account a driver push-buffer window whose bytes are now resident (capture
// v2 deferred-drain). Advances the consumption watermark that feeds the
// ctx[+0]/[+4] mirrors (guest free-space/progress predicates operate in
// this VA space) and bumps the submitting thread's progress counter by
// dwords. Call from the thread running guest code (counter chain uses its
// live PPC context).
void CpConsumePushWindow(uint32_t endVA, uint32_t dwords);

// --- DIAGNOSTIC deferred-consumption experiment (cp_deferred_consume_
//     experiment=1; default OFF) ------------------------------------------------
// When enabled, CpConsumePushWindow records submitted windows WITHOUT
// crediting consumption; a vblank-paced consumer (inside
// CpVblankDrainToWptr) later consumes only ranges the driver has actually
// produced (GPU_ctx+0x30), advancing XTEB+0x58 by exactly those dwords.
// Diagnostic timing experiment ONLY - not final HW semantics.
bool CpDeferredConsumeEnabled();
void CpDeferredSnapshot(uint32_t* producedEnd, uint32_t* consumedEnd,
                        uint32_t* outstandingDwords, uint32_t* pendingWindows);

// System-command-buffer boundary (kernel-acceptance layer, diagnostic).
// Token changes only when real deferred consumption is credited.
void CpRegisterGpuIdentifierAddress(uint32_t addr);
uint32_t CpGpuIdentifierAddress();
uint32_t CpScbToken();

// EXPERIMENT (2026-08-23, falsifiable): xenia never maintains KTHREAD+0x58
// (MCLA freezes there too), yet sub_82412F98 requires delta>=5000. We bump
// the submitting thread's progress block by `amount` per vblank tick from
// the vsync pump - mirroring MarkVblink placement. Revert if disproven.
void CpVblankDrainToWptr();

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
