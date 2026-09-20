#pragma once

// Phase 2 split of src/patches.cpp: per-family hook entry points.
// Each hooks/*.cpp TU owns its PPC_FUNC bodies; patches.cpp keeps only the
// registry (mcla_ApplyPatches) and the kernel/input/GPU-observers needed by
// it. ABI note: PPC_FUNC_IMPL expands to extern "C", so these use C linkage.

#include "ppc_context.h"
#include "kernel/memory.h"

extern "C" {
// hooks/alloc_census.cpp — OOM/allocation-path/pool16/slab census
void sub_821C29A0(PPCContext& ctx, uint8_t* base);
void sub_82130B50(PPCContext& ctx, uint8_t* base);
void sub_82130010(PPCContext& ctx, uint8_t* base);
void sub_82130048(PPCContext& ctx, uint8_t* base);
void sub_8218DCE8(PPCContext& ctx, uint8_t* base);
void sub_8218DE38(PPCContext& ctx, uint8_t* base);
void sub_821C22D0(PPCContext& ctx, uint8_t* base);
void sub_821C1BB0(PPCContext& ctx, uint8_t* base);
void sub_821DE9D8(PPCContext& ctx, uint8_t* base);
void sub_821DE908(PPCContext& ctx, uint8_t* base);
void sub_821C09C8(PPCContext& ctx, uint8_t* base);
void sub_82177EB0(PPCContext& ctx, uint8_t* base);
void sub_8218CC70(PPCContext& ctx, uint8_t* base);
}

// Session 73: tiny-slab fill-on-alloc census (implemented in
// hooks/alloc_census.cpp, declared in patches.h historically; keep the
// declaration there — this header only carries the hook entry points).

// Census gate: keep false for ship; true enables dense logging inside
// alloc_census.cpp hooks. If true, also needs MCLA_ALLOC_DEBUG defined.
static constexpr bool kPool16CensusEnabled = false;

// Checked heap-field read: returns 0 when the guest address is not backed.
// Shared by alloc_census.cpp and config_dispatch.cpp.
inline uint32_t OomCensusReadU32(uint32_t addr, bool *ok = nullptr) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t val = 0;
  const bool read = mem.IsValid(addr, 4) && mem.ReadU32BE(addr, &val);
  if (ok)
    *ok = read;
  return val;
}

// CP progress helper: advance guest publication counter for all tracked devices.
// Used to unblock guest fence waits when CP is stalled.
// Declared in gpu_cp.h as mcla::gpu::CpAdvanceGuestPublication.
