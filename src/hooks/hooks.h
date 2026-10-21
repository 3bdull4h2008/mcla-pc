#pragma once

// Phase 2 split of src/patches.cpp: per-family hook entry points.
// Each hooks/*.cpp TU owns its PPC_FUNC bodies; patches.cpp keeps only the
// registry (mcla_ApplyPatches) and the kernel/input/GPU-observers needed by
// it.
//
// LINKAGE (2026-10-21, fix_hooks2). THESE 13 MUST HAVE C++ LINKAGE. The guest's
// dispatch table is generated/ppc_xenon/ppc_func_mapping.cpp -- `{ 0x821C29A0,
// sub_821C29A0 }` at :4001 and the other twelve rows -- and that reference is to
// the C++-MANGLED symbol `?sub_821C29A0@@YAXAEIAUPPCContext@@PEAE@Z`. The
// generated TU exports that name as a WEAK alias of its own body
// (`__attribute__((alias("__imp__sub_821C29A0"))) PPC_WEAK_FUNC(sub_821C29A0);`,
// generated/ppc_xenon/ppc_recomp.15.cpp:10696), and the weak alias is what the
// table binds.
//
// The `extern "C" { ... }` block that used to be here made all 13 definitions
// C-LINKED, and a C-linked definition lands on a DIFFERENT symbol that nothing
// references. The /MAP of the build that produced build/w847.log proves it:
//   build/mcla.map  0001:00065d30  sub_821C29A0
//                                alloc_census.cpp.obj          <- C linkage, ORPHAN
//   build/mcla.map  0001:007b8e70  ?sub_821C29A0@@YAXAEIAUPPCContext@@PEAE@Z
//                                ppc_recomp.15.cpp.obj          <- what the table binds
// So the 13 hooks were DEAD and their 34 census printers had NEVER fired
// (0 occurrences of any of them in build/w847.log, build/w846.log,
// build/w840.log). The block was added by the 2026-09-20 module reorg
// (5eb9932), which MOVED the bodies out of src/patches.cpp; before it, the same
// `PPC_FUNC(sub_X)` bodies had no `extern "C"` declaration in scope, so they
// were C++-linked, STRONG, and won over the generated weak alias.
//
// A C++-linked definition is a strong external and overrides the generated weak
// alias, so the table (and every recompiled TU that calls `sub_X(ctx, base)`)
// binds THIS body, which chains to `__imp__sub_X` -- the generated body --
// exactly as it did before the reorg.
//
// `PPC_FUNC(x)` is the C++-mangled declaration form the generated tree uses
// (src/ppc_context.h:41); `PPC_FUNC_IMPL(x)` is `extern "C"` and is reserved
// for the `__imp__sub_X` thunks, which the generated TUs also define with C
// linkage. DO NOT put these 13 back in an `extern "C"` block.

#include "ppc_context.h"
#include "kernel/memory.h"

// hooks/alloc_census.cpp — OOM/allocation-path/pool16/slab census
PPC_FUNC(sub_821C29A0);
PPC_FUNC(sub_82130B50);
PPC_FUNC(sub_82130010);
PPC_FUNC(sub_82130048);
PPC_FUNC(sub_8218DCE8);
PPC_FUNC(sub_8218DE38);
PPC_FUNC(sub_821C22D0);
PPC_FUNC(sub_821C1BB0);
PPC_FUNC(sub_821DE9D8);
PPC_FUNC(sub_821DE908);
PPC_FUNC(sub_821C09C8);
// hooks/config_dispatch.cpp — config-dispatch census + the TEXCREATE-SC fix
PPC_FUNC(sub_82177EB0);
PPC_FUNC(sub_8218CC70);

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
