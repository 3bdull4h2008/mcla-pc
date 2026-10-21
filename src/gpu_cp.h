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

// ---------------------------------------------------------------------------
// F-XXX: THE GUEST'S RENDER TARGET AND ITS COPY, read out of the Xenos
// register file (the SAME array the PM4/TYPE-0 path writes, g_xenosReg).
//
// WHY THIS EXISTS. The audit in build/agents/audit_gpu.md recorded that the
// guest's render-target descriptors and its copy registers are written by the
// guest and consumed by NOBODY in src/ ("NO EDRAM target and NO RB_COPY
// consumer"), and that ResolveGuestSurface (src/d3d12_backend.cpp:6295) has no
// call site at all. That is the missing half of the console's route.
//
// THE GUEST'S OWN BYTES (build/cache/mcla_pe.bin, VA = offset + 0x82000000):
//   * 0x827ED1C8  TYPE-0 header 0x000F2000 = base 0x2000, count 16
//     payload 0x827ED1CC: RB_SURFACE_INFO = 0x0A000280
//       -> surface_pitch = 0x280 = 640 px, msaa_samples = 0 (1x),
//          hiz_pitch = 640   (registers.h:670-680)
//     payload 0x827ED1D4: RB_DEPTH_INFO = 0x000000F0
//     payload 0x827ED208: PA_SC_SCREEN_SCISSOR_BR = 0x20002000 (br_x=8192,
//          br_y=8192 -- the "unbounded" sentinel, NOT a screen size)
//   * 0x827ED498  TYPE-0 header 0x00002318 -> RB_COPY_CONTROL = 0x00100000
//     0x827ED4A0  TYPE-0 header 0x00002319 -> RB_COPY_DEST_BASE = 0x1FFEF000
//     0x827ED4A8  TYPE-0 header 0x0000231A -> RB_COPY_DEST_PITCH = 0x00080020
//     0x827ED4B0  TYPE-0 header 0x0000231B -> RB_COPY_DEST_INFO = 0x01000302
//   * 0x827EDB4C  TYPE-0 header 0x00002208 -> RB_MODECONTROL = 0x00000006
//     = xenos::EdramMode::kCopy (xenos.h:886-888) -- the EDRAM-COPY MODE the
//     guest turns on for the copy draw, next to the PM4_DRAW_INDX_2 at
//     0x827ED490 and the PM4_IM_LOAD_IMMEDIATE copy shader at 0x827ED4B8.
//   * The RUNNING values were measured in build/w842.log:
//     CP-REG-HI #14 op=IB base=2000 n=16 val=14000500  -> surface_pitch 1280
//     CP-REG-HI #22 op=IB base=2318 n=4  val=00100000  -> RB_COPY_CONTROL
//     CP-REG-HI #24 op=IB base=231B n=1  val=00000000
//     CP-REG-HI #10 op=IB base=2208 n=1  val=00000004  -> EdramMode::kColorDepth
//
// REGISTER INDICES (register_table.inc:480-486, 494-495, 536-545, 595-598):
//   0x2000 RB_SURFACE_INFO   0x2001 RB_COLOR_INFO    0x2002 RB_DEPTH_INFO
//   0x200E PA_SC_SCREEN_SCISSOR_TL  0x200F PA_SC_SCREEN_SCISSOR_BR
//   0x2208 RB_MODECONTROL    0x2318 RB_COPY_CONTROL  0x2319 RB_COPY_DEST_BASE
//   0x231A RB_COPY_DEST_PITCH 0x231B RB_COPY_DEST_INFO
// ---------------------------------------------------------------------------
constexpr uint32_t kCpRegRbSurfaceInfo = 0x2000u;
constexpr uint32_t kCpRegRbColorInfo = 0x2001u;
constexpr uint32_t kCpRegPaScScreenScissorBr = 0x200Fu;
constexpr uint32_t kCpRegRbModeControl = 0x2208u;
constexpr uint32_t kCpRegRbCopyControl = 0x2318u;
constexpr uint32_t kCpRegRbCopyDestBase = 0x2319u;
constexpr uint32_t kCpRegRbCopyDestPitch = 0x231Au;
constexpr uint32_t kCpRegRbCopyDestInfo = 0x231Bu;

// The guest's render target and its copy, decoded from the register file.
// EVERY FIELD IS THE GUEST'S OWN VALUE; nothing here is a default that the
// guest did not write, and a register the guest never wrote reads back as the
// initialiser zero (see CpReadGuestRegisters' presence contract above).
struct CpGuestRenderTarget {
    // RB_SURFACE_INFO (registers.h:670-680)
    uint32_t surfacePitch = 0;   // +0  in PIXELS (14 bits)
    uint32_t msaaSamples = 0;    // +16 (2 bits)
    uint32_t hizPitch = 0;       // +18 in pixels (14 bits)
    // RB_COLOR_INFO (registers.h:736-752)
    uint32_t colorFormat = 0;    // +16 (4 bits) xenos::ColorRenderTargetFormat
    uint32_t colorBase = 0;      // +0  in EDRAM tiles (11 bits)
    // PA_SC_SCREEN_SCISSOR_BR (registers.h:598-608)
    uint32_t scissorBrX = 0;     // +0  (15 bits, signed)
    uint32_t scissorBrY = 0;     // +16 (15 bits, signed)
    // RB_MODECONTROL (registers.h:660-668)
    uint32_t edramMode = 0;      // +0  (3 bits) xenos::EdramMode
    // RB_COPY_* (registers.h:853-897)
    uint32_t copyControl = 0;    // RB_COPY_CONTROL
    uint32_t copyDestBase = 0;   // RB_COPY_DEST_BASE
    uint32_t copyDestPitch = 0;  // RB_COPY_DEST_PITCH
    uint32_t copyDestInfo = 0;   // RB_COPY_DEST_INFO
};

// READ-ONLY snapshot of the guest's render target / copy state.
// Same locking contract as CpReadGuestRegisters: no lock, per-register
// consistency, safe to call from the render thread.
CpGuestRenderTarget CpGuestRenderTargetInfo();

// ---------------------------------------------------------------------------
// F-XXX: THE CONSOLE'S SHADER-CONSTANT MODEL (the ALU constant array).
//
// THE CONSOLE'S MODEL, as guest facts:
//   * ONE array of 512 float4 lives in the Xenos REGISTER FILE at register
//     0x4000 - `XE_GPU_REGISTER(0x4000, kFloat, SHADER_CONSTANT_000_X)`
//     (register_table.inc:648; the array runs 0x4000..0x47FF = 2048 dwords).
//   * A shader's `cN` is read from THAT array, never from memory:
//     shader_interpreter.cc:260-284
//         index = N;
//         if (index > SQ_x_CONST.size)          -> zeros
//         index += SQ_x_CONST.base;
//         if (index >= 512)                     -> zeros
//         value = register_file[0x4000 + 4*index]   (4 dwords = one float4)
//   * SQ_VS_CONST (0x2307) / SQ_PS_CONST (0x2308) are (base, size) PAIRS, not
//     addresses: registers.h:256-281 - `base` is bits 0..8 and `size` is bits
//     12..20, and the size field is the VEC4 COUNT MINUS ONE. The stage picks
//     its own pair: SQ_VS_CONST for the vertex stage, SQ_PS_CONST for the pixel
//     stage (shader_interpreter.cc:270-272).
//
// THE GUEST'S OWN VALUES (build/cache/mcla_pe.bin; VA = offset + 0x82000000):
//   0x827ECD60  TYPE-0 header 0x00252300 = base 0x2300, count 38
//     payload dword 7 (VA 0x827ECD80) = 0x000FF000 -> SQ_VS_CONST
//     payload dword 8 (VA 0x827ECD84) = 0x000FF100 -> SQ_PS_CONST
//   and the RUNNING values are the same: build/w842.log CP-REGS-EXPORT #2
//   `2307=000FF000* 2308=000FF100*` (the `*` = the presence bit is set).
//   DECODED under the layout above:
//     SQ_VS_CONST = 0x000FF000 -> base = 0x000FF000 & 0x1FF = 0,
//                                size = (0x000FF000 >> 12) & 0x1FF = 255
//                                (vec4 count minus one -> 256 vec4)
//     SQ_PS_CONST = 0x000FF100 -> base = 0x100 = 256, size = 255
//   So the vertex stage owns array entries 0..255 and the pixel stage owns
//   256..511: the two windows TILE the 512-entry array exactly. These words
//   are NOT addresses, and the host must not read guest memory at them.
//
// WHAT THE HOST DID INSTEAD (the defect this replaces):
//   src/render_thread.cpp:911-1010 `FillGuestConstantBank` treats the RAW
//   value of SQ_VS_CONST as a guest VIRTUAL ADDRESS (vsVa = val[0]), reads
//   4096 bytes of GUEST MEMORY from it (:952-956) and hands that one bank to
//   the backend (:987); the pixel stage's bank is read and DISCARDED
//   (:989-991, counter `psDroppedNoSlot`). MEASURED on this boot:
//   build/w842.log CONST-BANK-PRODUCE #1 `filled=1 ... vsVa=000FF000
//   psVa=000FF100 bankBytes=4096` - the host read the page at guest VA
//   0x000FF000, which is not a constant bank at all.
//
// THE TWO BUILDERS below are the console's model, ready for a consumer:
//   CpBuildShaderConstantBank  - ONE stage's bank: out[N] = the console's
//                                 array entry (base_stage + N), zero outside
//                                 the stage's (base,size) window. This is what a
//                                 consumer binds to the stage that is drawn.
//   CpBuildShaderConstantArray - the WHOLE 512-float4 array, in the console's
//                                 own entry numbering, for a consumer that
//                                 binds one buffer and offsets per stage.
// BOTH write BIG-ENDIAN float4, which is what the host's one endian site
// (renderer::PackXenosConstantBank, pipeline_cache.cpp:1317-1351) expects and
// swaps. The register file holds the guest's words as host uint32 values
// already byte-swapped out of the guest stream, so the big-endian bytes are
// RE-ASSEMBLED here - once, at the producer, so the packer stays the single
// place the swap happens.
// ---------------------------------------------------------------------------
constexpr uint32_t kCpShaderConstantRegBase = 0x4000u;  // SHADER_CONSTANT_000_X
constexpr uint32_t kCpShaderConstantCount = 512u;       // float4 entries
constexpr uint32_t kCpShaderConstantDwords = 2048u;      // 512 * 4 dwords
constexpr uint32_t kCpShaderConstantBytes = kCpShaderConstantCount * 16u;  // 8192

// Which stage a bank is built for. The console picks the (base,size) pair by
// stage (shader_interpreter.cc:270-272).
enum class CpShaderStage : uint32_t { kVertex = 0, kPixel = 1 };

// The decoded (base,size) pairs and the state of the array itself.
struct CpShaderConstantInfo {
    bool vsRegPresent = false;   // the guest has EVER written SQ_VS_CONST
    bool psRegPresent = false;   // the guest has EVER written SQ_PS_CONST
    uint32_t vsBase = 0;         // SQ_VS_CONST base field, bits 0..8
    uint32_t vsSize = 0;         // SQ_VS_CONST size field, bits 12..20
    uint32_t psBase = 0;         // SQ_PS_CONST base field, bits 0..8
    uint32_t psSize = 0;         // SQ_PS_CONST size field, bits 12..20
    // How many of the 2048 ALU dwords the guest has EVER written. 0 means the
    // console's array is ALL ZEROS on this boot - a fact the consumer must be
    // able to read, because "the constants are zero" and "the constants were
    // never set" are different claims and only one of them is a guest fact.
    uint32_t aluDwordsPresent = 0;
    // How many float4 the last build actually filled (the rest are the
    // console's own zeros).
    uint32_t entriesFilled = 0;
};

// Builds ONE stage's constant bank. `out` receives up to outBytes/16 float4,
// BIG-ENDIAN. Returns false only when `out` is null or `outBytes` < 16.
bool CpBuildShaderConstantBank(CpShaderStage stage, uint8_t* out,
                               uint32_t outBytes, CpShaderConstantInfo* info);

// Builds the WHOLE 512-float4 array in the console's own entry numbering
// (entry i = register 0x4000 + 4*i), BIG-ENDIAN. Returns false only when
// `out` is null or `outBytes` < 16.
bool CpBuildShaderConstantArray(uint8_t* out, uint32_t outBytes,
                                CpShaderConstantInfo* info);

// Advance guest publication counter (subctx+0) for all tracked devices.
// Used to unblock guest fence waits when CP is idle but guest thinks work is pending.
void CpAdvanceGuestPublication(uint32_t windowsCompleted);

} // namespace mcla::gpu
