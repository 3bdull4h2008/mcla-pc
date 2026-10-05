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
// The CP's own publish target (kernel-VA form), or 0 when no write-back is
// enabled. A census that wants the ring's read pointer must read this word,
// never a hard-coded address four bytes away from it (F-057(1)).
uint32_t CpPrimaryWritebackVA();

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
// produced (via PrimaryRing lastDoorbellWptr), advancing XTEB+0x58 by
// exactly those dwords.
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

// F-647: READ-ONLY export of the Xenos register file (F-646's missing link).
//
// Reads up to `count` register values by Xenos register INDEX (not by dword
// offset) and, for each, whether the guest has EVER WRITTEN that index.
// `present[i]` non-zero == `values[i]` is the guest's value. `present[i] == 0`
// == `values[i]` is the initialiser zero and MUST NOT be decoded: "never
// written" and "written as 0" are different facts, and conflating them is how a
// legal-but-wrong default (e.g. PA_SU_SC_MODE_CNTL=0 -> solid triangles, both
// faces, CCW) gets built into a rasteriser. Either out-param may be null.
//
// `values`/`present` must each have room for `count` entries. Returns false if
// any index was out of file range (counted as `oob`, not asserted); `indices`
// are compile-time constants at every call site, so oob is a programming error,
// never a guest value.
//
// THREAD SAFETY / LOCK ORDERING: no lock is taken. The register file and the
// per-register presence bitmap are atomics, so this is safe to call from the
// render thread while the command-processor thread pokes. Consistency is PER
// REGISTER, not across registers -- there is no seqlock. This function takes no
// other lock, so it is safe to call while holding the microcode window's mutex.
// Full rationale and the rule for adding a seqlock later: the CpReadGuest-
// Registers definition comment in src/gpu_cp.cpp.
bool CpReadGuestRegisters(const uint32_t* indices, uint32_t count,
                          uint32_t* values, uint32_t* present);

// F-647: the three registers the renderer needs for raster/clip/viewport state
// (F-646). Named HERE, at the producer, from the same table the consumer cites
// (.research/xenia/src/xenia/gpu/register_table.inc:540-542,
// XE_GPU_REGISTER(0x2204, kDword, PA_CL_CLIP_CNTL) / 0x2205 PA_SU_SC_MODE_CNTL
// / 0x2206 PA_CL_VTE_CNTL), so the producer and
// renderer::kXenosRegPa{ClipCntl,SuScModeCntl,ClVteCntl}
// (src/renderer/pipeline_cache.h:101-103) cannot drift apart. These are
// XENOS REGISTER INDICES.
constexpr uint32_t kCpRegPaClipCntl = 0x2204u;
constexpr uint32_t kCpRegPaSuScModeCntl = 0x2205u;
constexpr uint32_t kCpRegPaClVteCntl = 0x2206u;
// F-647: SQ_VS_CONST / SQ_PS_CONST, the guest VAs of the vertex and pixel
// constant banks (register_table.inc:578-579). Read by index, exactly like the
// three above; the VALUES are 32-bit guest VAs and must be read out of guest
// memory through the checked, endian-explicit helpers -- never
// reinterpret_cast, never asserted.
constexpr uint32_t kCpRegSqVsConst = 0x2307u;
constexpr uint32_t kCpRegSqPsConst = 0x2308u;

// Advance guest publication counter (subctx+0) for all tracked devices.
// Used to unblock guest fence waits when CP is idle but guest thinks work is pending.
void CpAdvanceGuestPublication(uint32_t windowsCompleted);

} // namespace mcla::gpu
