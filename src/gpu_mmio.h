#pragma once

#include <cstdint>
#include "app.h"

namespace mcla::gpu {

// ---------------------------------------------------------------------------
// REGISTER CENSUS, measured 2026-10-05. ALL 14 PAIRS BELOW DISAGREE WITH THE
// XENOS ABI. ZERO AGREE. READ THIS BEFORE USING ANY OF THEM.
//
// Oracle: .research/xenia/src/xenia/gpu/register_table.inc -- 2670
// XE_GPU_REGISTER entries spanning 0x0048..0x8D07. Cross-checked against the
// live command processor, which is RIGHT everywhere this enum is wrong, all four
// agreeing with the oracle:
//   gpu_cp.cpp:2807  kRegVgtEventInitiator = 0x21F9  == table:530 VGT_EVENT_INITIATOR
//   gpu_cp.cpp:5387  CpRegPoke(0x21FAu, dmaBase)    == table:531 VGT_DMA_BASE
//   gpu_cp.cpp:5388  CpRegPoke(0x21FBu, dmaSize)    == table:532 VGT_DMA_SIZE
//   gpu_cp.cpp:5389  CpRegPoke(0x21FCu, di)         == table:533 VGT_DRAW_INITIATOR
//
// 13 OF THE 14 NAMES DO NOT EXIST IN THE XENOS ABI AT ANY OFFSET -- the table has
// zero CB_* entries, and no VGT_PRIMITIVE_TYPE and no VGT_NUM_INDICES. The 14th,
// VGT_DRAW_INITIATOR, is real and lives at 0x21FC, which this enum hands to
// VGT_NUM_INDICES while giving VGT_DRAW_INITIATOR 0x21F0.
//
// THE 5 THAT ARE OCCUPIED BY A DIFFERENT, REAL, WRITTEN REGISTER -- the dangerous
// ones, because each is written for real, so wiring one of these constants to
// hardware would talk to the wrong register while printing a confident label:
//   0x2000 CB_COLOR0_BASE      -> RB_SURFACE_INFO    (table:480)
//   0x2002 CB_DEPTH_BASE       -> RB_DEPTH_INFO      (table:482)
//   0x21FC VGT_NUM_INDICES     -> VGT_DRAW_INITIATOR (table:533)  CP WRITES THIS
//   0x2300 SQ_PGM_RESOURCES_VS -> PA_SC_LINE_CNTL    (table:571)
//   0x2301 SQ_PGM_RESOURCES_PS -> PA_SC_AA_CONFIG    (table:572)  GUEST WRITES THIS
// The other 9 (0x01C0, 0x01C4, 0x01C8, 0x01CC, 0x21F0, 0x21F4, 0x21F6, 0x21F8,
// 0x2440) name no table entry at all.
//
// SQ_PROGRAM_CNTL IS NOT HERE AND MUST NOT BE ADDED. It is register 0x2180
// (table:523), and it is REGISTER STATE, never a program pointer:
// .research/xenia/src/xenia/gpu/registers.h:127-150 decodes it as vs_num_reg and
// ps_num_reg (GPR counts stored minus 1), vs_export_mode, ps_export_mode,
// vs_export_count, param_gen, gen_index_pix and gen_index_vtx. It says HOW MANY
// registers a program uses, never WHICH program. src/render_thread.cpp:862-868
// already records that this file's 0x2301 is not it.
//
// WHY NOT ONE VALUE IS CORRECTED BELOW. Measured blast radius: `XenosRegister`
// has exactly one reader in the tree -- the label `switch` in gpu_mmio.cpp's
// LogMmioWrite, which maps an offset to a `const char*` and does nothing else. It
// reads no memory, writes no memory, and has ZERO callers: the only occurrences of
// the name in src/ are gpu_mmio.cpp:20 (a comment), :43 (the definition) and
// gpu_mmio.h:31 (the declaration). So a wrong offset here cannot change behaviour;
// it can only pick a wrong log LABEL in a function nobody calls. Exactly ONE of
// the 14 is establishable (VGT_DRAW_INITIATOR -> 0x21FC, three agreeing sources);
// the other 13 names are not Xenos names at any offset, so their true offsets are
// NOT ESTABLISHABLE from any authority in this tree and writing new numbers would
// be fabrication rather than a fix. And correcting that one would collide with
// VGT_NUM_INDICES = 0x21FC and turn the switch into a duplicate-case compile
// error. So: census recorded, values left untouched.
//
// MEASURED, what the guest really writes (build/w720.log, byte-identical in
// build/w704.log): 0x2180 <- 0x1000000E over 26 writes; 0x2301 <- 0x0000C003, one
// write. Across 2116 captured register-write rows spanning 30 distinct offsets
// there are ZERO at 0x2000, 0x2002, 0x2300, 0x2440, 0x21F0, 0x21F4, 0x21F6, 0x21F8
// or 0x01C0..0x01CC -- so those 12 are not merely misnamed, on this boot path the
// title does not write them at all.
// ---------------------------------------------------------------------------
enum XenosRegister : uint32_t {
    CP_RB_WPTR            = 0x01C4,
    CP_RB_RPTR            = 0x01C8,
    CP_RB_BASE            = 0x01C0,
    CP_RB_CNTL            = 0x01CC,
    VGT_PRIMITIVE_TYPE    = 0x21F8,
    VGT_NUM_INDICES       = 0x21FC,
    VGT_DRAW_INITIATOR    = 0x21F0,
    SQ_ALU_CONST_CACHE    = 0x2440,
    CB_COLOR0_BASE        = 0x2000,
    CB_DEPTH_BASE         = 0x2002,
    SQ_PGM_START_VS       = 0x21F4,
    SQ_PGM_START_PS       = 0x21F6,
    SQ_PGM_RESOURCES_VS   = 0x2300,
    SQ_PGM_RESOURCES_PS   = 0x2301,
};

struct GpuHooks {
    void (*onGpuKick)(mcla::native::PPCContext&) = nullptr;
    void (*onDrawCall)(mcla::native::PPCContext&) = nullptr;
    void (*onSetupVertexFetch)(mcla::native::PPCContext&) = nullptr;
};

void LogMmioWrite(uint32_t offset, uint32_t value);

void NotifyGpuSubmit(mcla::native::PPCContext& ctx, uint8_t* base);

void DefaultGpuKickHook(mcla::native::PPCContext& ctx);
void DefaultSetupVertexFetchHook(mcla::native::PPCContext& ctx);
void DefaultDrawCallHook(mcla::native::PPCContext& ctx);

void InstallGpuHooks(mcla::App::FunctionDispatcher* dispatcher, const GpuHooks& hooks);

} // namespace mcla::gpu