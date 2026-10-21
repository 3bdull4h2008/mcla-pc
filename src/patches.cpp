#include "patches.h"
#include "hooks/hooks.h"
#include "app.h"
#include "cpu/ppc_context.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "gpu_cp.h"
#include "gpu_device.h"
#include "gpu_mmio.h"
#include "guest_memory.h"
#include "logging.h"
#include "native_renderer.h"
#include "render_queue.h"
#include "render_thread.h"
#include "renderer_mode.h"
#include "fs/vfs_rpf.h"

#include "kernel/memory.h"
#include "kernel/xbox.h"
#include "kernel/kernel_objects.h"

// (rule 1b, 2026-10-21 fix_typebyte) Cross-TU entry point of the host's
// guest-clock tick (src/kernel/imports.cpp: SignalSchedulerTick).  It sets
// the guest's clock-tick EVENT 0x40004D7C, which is the console-correct
// class for that object.
void SignalSchedulerTickPublic();

#include <algorithm>
#include <atomic>
#include <cctype>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <system_error>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <fcntl.h>
#include <io.h>
#include <windows.h>

// extern "C" host kernel impls (src/kernel/imports.cpp) - direct host calls, not guest thunks
extern "C" uint32_t KeReleaseSemaphore(void *, uint32_t, uint32_t, uint32_t);

static mcla::App::FunctionDispatcher *g_dispatcher = nullptr;
static uint8_t *g_virtual_membase = nullptr;

// Internal helpers only - no external linkage needed. This namespace spans
// from here to the `} // namespace` after GetWallClockDeltaBits() (the
// closing brace survived the F-609 deletions below; the opening one did not,
// so it is restored here rather than left dangling).
namespace {
namespace {
// SESSION 44b: census on sub_821C2AB8 (guest allocator free) - overrides it, never chains, so a firing call drops the free.
std::atomic<uint32_t> s_routerCalls{0};
} // namespace

PPC_FUNC_IMPL(__imp__sub_821C2AB8);
PPC_FUNC(sub_821C2AB8) {
  const uint32_t lr_val = static_cast<uint32_t>(ctx.lr);
  const uint32_t n = s_routerCalls.fetch_add(1) + 1;
  if (n <= 16 || n % 1024 == 0) {
    MCLA_LOG_WARN("POOL-ROUTER #{} r3={:08X} r4={:08X} lr={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, lr_val);
  }
}

// SESSION 44c: the census on sub_821C09C8 (pool-free dispatcher: r3 heap, r4
// node, ctx.lr, caller's stack for the real return address) is NOT in this file
// any more - it lives in src/hooks/alloc_census.cpp:12443, gated by hooks.h:34.

// DELETED 2026-09-28 (F-609 sweep): the native-detour input path —
// g_native_XamInputGetState_func, InstallNativeDetour, RemoveNativeDetour,
// hk_native_XamInputGetState, CallOriginalNativeXamInputGetState,
// g_original_native_bytes and g_native_detour_code. Reachability proof:
// `g_native_XamInputGetState_func` (was :81) was initialised to nullptr and
// assigned in exactly zero places, so CallOriginalNativeXamInputGetState's
// `if (!target) return 0;` made it a constant zero — and its only two
// callers were InstallNativeDetour/RemoveNativeDetour inside itself, so that
// closure had no entry point either. `rg hk_native_XamInputGetState src/`
// after this deletion: 0 hits (the only prior references were this block plus
// docs/ROOT_CAUSE_VALIDATION.md:4142-4143, historical). The synthetic Start
// pulse (StartPulseActive, was :51) went with them: it had no host input
// behind it, so it fabricated the Start button out of a wall clock, and its
// only two consumers were the two dead input functions. F-048's note that
// both are "left in tree unreferenced so the pulse can be reinstated
// deliberately" is superseded — the charter is no-emulation, so the corpse
// is gone rather than parked as a re-instatement stash.

// 2026-09-28 RULE-4: the four g_original_Nt* slots and their hk_Nt* wrappers
// were deleted. Each pair was a *layer*, not a hook: build/mcla.map:3961/:4005
// /:3661/:3963 show the ONLY body for ?__imp__NtCreateFile/NtReadFile/
// NtQueryInformationFile/NtClose@@YAXAEIAUPPCContext@@PEAE@Z is
// `imports.cpp.obj` -- the GUEST_FUNCTION_HOOK/PPC_FUNC owner in
// src/kernel/imports.cpp -- while the generated rows
// (ppc_func_mapping.cpp:44917 NtClose, :44936 NtQueryInformationFile, and the
// NtCreateFile/NtReadFile rows) are the dispatcher's DEFAULT binding
// (src/hooks/config_dispatch.cpp:66-76). The hk_Nt* wrappers' only added
// behaviour was `if (mcla::vfs::hooks::NtXxxHook(...))` and all four of those
// are `(void)`-bodied stubs that `return false` unconditionally
// (src/fs/vfs_rpf.cpp:1328-1362), so each wrapper was provably
// `g_original_NtXxx(ctx, base)` -- a second binding mechanism in front of the
// only implementation, exactly the F-092 shape already removed from the "in"
// group below. Get+Set on 0x827BCEB4/0x827BD914/0x827BD934/0x827BD9D4 gone;
// imports.cpp:4891/:4892/:4917/:145 keeps sole ownership of all four.
static PPCFunc *g_original_GpuKick = nullptr;

static constexpr uint32_t kDummyLocHandle = 0x7FFF0001;
static thread_local uint32_t t_pendingLocHandleOut = 0;
static thread_local uint32_t t_lastLocStatus = 0;
static std::unordered_set<uint32_t> s_realLocHandles;
static std::mutex s_realLocHandlesMtx;

static const std::chrono::steady_clock::time_point g_wallClockStart =
    std::chrono::steady_clock::now();

static uint64_t GetWallClockDeltaBits() {
  auto now = std::chrono::steady_clock::now();
  double elapsed =
      std::chrono::duration<double>(now - g_wallClockStart).count();
  float elapsedF = static_cast<float>(elapsed);
  double result = static_cast<double>(elapsedF);
  uint64_t bits;
  std::memcpy(&bits, &result, sizeof(bits));
  return bits;
}
} // namespace

static constexpr uint32_t TIMER_STR_30690 = 0x822A0E28;
static constexpr uint32_t TIMER_STR_30770 = 0x822A0E3C;
static constexpr uint32_t TIMER_STR_30850 = 0x822A0E50;
static constexpr uint32_t TIMER_STR_30930 = 0x822A0E64;
static constexpr uint32_t TIMER_STR_30A18 = 0x822A0E78;

static constexpr uint32_t TIMER_OBJ_PTR = 0x82C30990;
static constexpr uint32_t TIMEBASE_STORE = 0x82C30AB0;

// DELETED 2026-09-28 (F-609 sweep): `static bool g_press_start_bypassed` (was
// :190) and its single store inside sub_82554080_stub. It was a write-only
// latch — `rg g_press_start_bypassed src/` gave 3 hits, all of them the
// declaration and the two-word store — so the "already bypassed" flag gated
// nothing and told a reader the bypass was live when its only writer has
// 0 firings in w654.log ("sub_82554080 stub" = 0).

static void TimerHookDispatch(mcla::native::PPCContext &ctx, uint8_t *base,
                              uint32_t nameStr, bool returnOne) {
  uint32_t timerObj = PPC_LOAD_U32(TIMER_OBJ_PTR);
  uint64_t deltaBits = GetWallClockDeltaBits();

  PPC_STORE_U64(TIMEBASE_STORE, PPC_QUERY_TIMEBASE());

  static int timerCount = 0;
  timerCount++;

  // CP progress nudge (host mitigation): credit one push-buffer window per timer
  // hook so a waiting guest fence can clear. CpAdvanceGuestPublication
  // (src/gpu_cp.cpp:992) writes subctx+0 clamped to put (dev+10908) because
  // sub_82411E98 waits on *(subctx+0) >= needed: pub LAGS put, it never leads it.
  mcla::gpu::CpAdvanceGuestPublication(1);

  if (timerObj) {
    if (timerCount <= 10) {
      MCLA_LOG_INFO(
          "Timer ARMED: obj=0x{:08X} name=0x{:08X} deltaBits=0x{:016X}",
          timerObj, nameStr, deltaBits);
    }
    ctx.r3.u64 = timerObj;
    ctx.r4.u64 = nameStr;
    ctx.r5.u64 = deltaBits;
    sub_821BE860(ctx, base);
    if (returnOne)
      ctx.r3.u64 = 1;
  } else {
    if (timerCount <= 10) {
      MCLA_LOG_INFO(
          "Timer UNARMED: name=0x{:08X} deltaBits=0x{:016X} origR3=0x{:08X}",
          nameStr, deltaBits, ctx.r3.u32);
    }
    uint32_t origR3 = ctx.r3.u32;
    ctx.r3.u64 = nameStr;
    ctx.r4.u64 = deltaBits;
    ctx.r5.u64 = origR3;
    sub_823D9750(ctx, base);
  }
}

// DELETED 2026-09-28 (F-609 sweep): the extern "C" declaration and the
// PPC_FUNC_IMPL body of hk_KeWaitForSingleObject, plus its g_original_KeWait
// and its SetFunction registration — the hook force-returned STATUS_SUCCESS
// for any guest wait on 0x828CD9AC / 0x40004D7C, a short-circuit stacked on
// the real HLE wait (imports.cpp:2156) and the vsync-driven tick semaphore
// (imports.cpp:1836 SignalSchedulerTick, called at :1784). Full reachability
// proof at the former registration site below; the same hook was never
// entered even once. Its two object constants went with it.
extern "C" void hk_sub_82130690(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130770(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130850(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130930(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130A18(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_822A3998(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82554E20(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82554590(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_GpuKick(mcla::native::PPCContext &ctx, uint8_t *base);
// hk_sub_824569C8 removed 2026-09-28 (F-609 one-owner sweep): its only
// registration bound guest 0x824569C8, a function a compile-time PPC_FUNC body
// already owned (src/gpu_device.cpp:14944), and it chained back into that very
// body. See the deletion note where the registration block used to be.
// hk_sub_82413660 (dead dispatcher duplicate) removed in P5'/B8 — the live
// owner of guest 0x82413660 is the global-scope PPC_FUNC override in
// src/gpu_device.cpp; native geometry submission is owned by sub_82420BA8.
extern "C" void hk_sub_82411840(mcla::native::PPCContext &ctx, uint8_t *base);

PPC_FUNC_IMPL(__imp__sub_82413660);
PPC_FUNC_IMPL(__imp__sub_82411840);

static PPCFunc *g_orig_sub_82554E20 = nullptr;
// SESSION 36: g_orig_sub_821C29A0 / g_orig_sub_82130B50 / g_fast_pool_alloc /
// g_debug_alloc_caller and the hk_sub_821C29A0 hook were removed. That hook was
// registered only via SetFunction, which in SESSION 36 filled only m_functions,
// and generated direct calls bind to the weak alias, so the map was not
// consulted for guest calls (proof: soak35.log, ZERO "ALLOC[" lines).
// SUPERSEDED today: SetFunction also writes the real dispatch table
// (src/app.cpp:337-343, note :315-322; F-092 item 2 relies on it). The removed
// hook's fallback also called the fatal raiser sub_821BD618 with wrong args.
// Live allocation-path census is NOT in this file: src/hooks/alloc_census.cpp
// sub_821C29A0 :1774 (OOM-CENSUS :2703) / sub_821C1BB0 :4356 (ARENA-CENSUS).
// g_orig_sub_824569C8 removed 2026-09-28 with the hk_sub_824569C8 registration:
// the "original" it saved was the compile-time override at
// src/gpu_device.cpp:14944, so the wrapper looped back into the body that was
// already installed and the saved pointer was the only thing it ever used.
// 2026-09-28 RULE-4 (0x827BD6E4): hk_vdswap_observer (body was :228), its
// g_orig_VdSwap_observer global and its Get+Set registration are DELETED.
// Three sites claimed this address; the one that ran is not this one.
// build/w658.log:5727 prints
//   VdSwap[1] obj=0xC65D931C swap_info=0x004E0D30 kva=0xC04E0D30 (INERT -
//   present owned by PresentKick 0x824294E0; presents=1 vdswap=1 ratio=1:1)
// which is src/native_renderer.cpp Hooked_VdSwap's own format string, and
// w658.log:133 shows its installer ("Native renderer: VdSwap registered INERT").
// This file's observer never installed and never ran: 0 "VdSwap observer
// installed", 0 "VdSwapObserver[" in w658.log (and 0 "VdSwap observer
// installed" in w653.log). The third claimant, src/kernel/imports.cpp's
// `PPC_FUNC(__imp__VdSwap) { Hooked_VdSwap(ctx, base); }`, already forwards to
// the same function, so this observer was a third name for one passthrough.
// Left in place it also made the slot's owner depend on install order between
// two files, which is what F-612 reported.

// hk_VdInitializeEngines and its g_orig_VdInitializeEngines global were
// deleted 2026-09-28 (RULE-4 at 0x827BD574). The wrapper's only content was a
// census line plus a call straight back into g_orig_VdInitializeEngines --
// i.e. a second binding in front of the single real body -- and the name was
// never right: 0x827BD574 is __imp__KeReleaseSemaphore
// (generated/ppc_xenon/ppc_func_mapping.cpp:44887), NOT __imp__VdInitializeEngines
// (:44920, which is 0x827BD784). The census it could have produced was never
// produced in any soak: 0 "VdInitializeEngines[" and 0 "VdInitializeEngines
// detour installed" in build/w658.log and build/w653.log.

PPC_FUNC_IMPL(hk_sub_82130690) {
  TimerHookDispatch(ctx, base, TIMER_STR_30690, false);
}

PPC_FUNC_IMPL(hk_sub_82130770) {
  TimerHookDispatch(ctx, base, TIMER_STR_30770, false);
}

PPC_FUNC_IMPL(hk_sub_82130850) {
  TimerHookDispatch(ctx, base, TIMER_STR_30850, false);
}

PPC_FUNC_IMPL(hk_sub_82130930) {
  TimerHookDispatch(ctx, base, TIMER_STR_30930, true);
}

PPC_FUNC_IMPL(hk_sub_82130A18) {
  TimerHookDispatch(ctx, base, TIMER_STR_30A18, false);
}

static uint32_t g_press_start_shim_thunk = 0;

namespace {
constexpr uint32_t kEpt3SigRva = 0x1C25A;
constexpr uint32_t kEpt3PatchRva = 0x1C262;
constexpr uint32_t kEpt3EpilogueRva = 0x1CAA8;
constexpr uint8_t kEpt3Signature[] = {0x39, 0xCA, 0x0F, 0x86, 0xC6,
                                      0x00, 0x00, 0x00, 0x8B, 0x05};
constexpr size_t kEpt3SignatureLen = sizeof(kEpt3Signature);
} // namespace

static void MclaPatchSdkExecutePacketType3Overflow() {
  HMODULE mod = GetModuleHandleW(L"rexgpu-xenos.dll");
  if (!mod) {
    MCLA_LOG_ERROR("SDK overflow patch: rexgpu-xenos.dll not loaded");
    return;
  }
  uint8_t *base = reinterpret_cast<uint8_t *>(mod);
  uint8_t *sig = base + kEpt3SigRva;
  if (memcmp(sig, kEpt3Signature, kEpt3SignatureLen) != 0) {
    MCLA_LOG_ERROR("SDK overflow patch: signature mismatch at 0x1C25A; "
                   "DLL build differs from expected - not patching");
    return;
  }
  uint8_t *target = base + kEpt3PatchRva;
  uint8_t patch[18];
  patch[0] = 0x8B;
  patch[1] = 0x43;
  patch[2] = 0x10;
  patch[3] = 0x89;
  patch[4] = 0x43;
  patch[5] = 0x0C;
  patch[6] = 0x41;
  patch[7] = 0xC7;
  patch[8] = 0xC6;
  patch[9] = 0x01;
  patch[10] = 0x00;
  patch[11] = 0x00;
  patch[12] = 0x00;
  patch[13] = 0xE9;
  int64_t rel = (base + kEpt3EpilogueRva) - (target + 18);
  memcpy(patch + 14, &rel, 4);
  DWORD old;
  if (!VirtualProtect(target, sizeof(patch), PAGE_EXECUTE_READWRITE, &old)) {
    MCLA_LOG_ERROR("SDK overflow patch: VirtualProtect failed ({})",
                   GetLastError());
    return;
  }
  memcpy(target, patch, sizeof(patch));
  FlushInstructionCache(GetCurrentProcess(), target, sizeof(patch));
  DWORD dummy;
  VirtualProtect(target, sizeof(patch), old, &dummy);
  MCLA_LOG_WARN("SDK overflow patch applied at 0x1C262: ExecutePacketType3 "
                "overflow now drains ring + returns true (non-fatal)");
}

MCLA_CVAR_STRING(mcla_patch_groups, "all", "MCLA Renderer",
                 "Which hook groups to install: all|none|sdk,guest,native");
MCLA_CVAR_BOOL(tu83_manual_spawn, false, "MCLA Kernel",
               "Enable manual TU83 worker spawn (EXPERIMENTAL - workaround for "
               "missing async trigger, defaults OFF)");
bool BisectGroupEnabled(std::string_view group) {
  const std::string_view groups = MCLA_CVAR_GET_STRING(mcla_patch_groups);
  if (groups == "all")
    return true;
  if (groups == "none")
    return false;
  size_t pos = 0;
  while (pos <= groups.size()) {
    size_t end = groups.find(',', pos);
    std::string_view item = groups.substr(pos, end == std::string_view::npos
                                                   ? std::string_view::npos
                                                   : end - pos);
    while (!item.empty() && (item.front() == ' ' || item.front() == '\t'))
      item.remove_prefix(1);
    while (!item.empty() && (item.back() == ' ' || item.back() == '\t'))
      item.remove_suffix(1);
    if (item == group)
      return true;
    if (end == std::string_view::npos)
      break;
    pos = end + 1;
  }
  return false;
}

void mcla_ApplyPatches(mcla::App::FunctionDispatcher *dispatcher) {
  MCLA_LOG_ERROR("=== mcla_ApplyPatches ENTERED ===");
  const std::string_view groups = MCLA_CVAR_GET_STRING(mcla_patch_groups);
  MCLA_LOG_ERROR("mcla_patch_groups = '{}'", groups);
  MCLA_LOG_ERROR("BisectGroupEnabled('ke') = {} (dead group name: the KeWait hook it gated is deleted below)", BisectGroupEnabled("ke") ? "true" : "false");
  g_dispatcher = dispatcher;

  dispatcher->SetFunction(0x82554080, sub_82554080_stub);

  // DELETED 2026-09-28 (F-609 one-owner sweep): five SetFunction registrations
  // that re-registered an address onto the host symbol of the SAME address --
  // 0x821C29A0, 0x821DE9D8, 0x821C1BB0, 0x8218CC70, 0x82177EB0. Each was a
  // bit-identical no-op, and each was a second binding mechanism on a guest
  // function a compile-time PPC_FUNC body already owned, so which one won
  // depended on the call site (direct bl -> the body; table-indirect -> the
  // SetFunction). No-op proof, three independent legs:
  //  (1) The generated table already binds the address. ppc_func_mapping.cpp
  //      rows :4001 (821C29A0), :4991 (821DE9D8), :3993 (821C1BB0), :2559
  //      (8218CC70), :1955 (82177EB0) are `{ addr, sub_<addr> }`, and
  //      boot_host.cpp:609 InstallFunctionTable copies every row into the real
  //      table via InsertFunction (app.cpp:375). It runs at boot_host.cpp:2247
  //      inside LoadAndPrepare, which app.cpp:82 calls BEFORE mcla_ApplyPatches
  //      at app.cpp:94 -- so the mapping install strictly precedes these calls.
  //  (2) `sub_<addr>` is the OVERRIDE, not the generated body, in this link.
  //      Both patches.cpp:5 and ppc_func_mapping.cpp include the same
  //      generated/ppc_xenon/ppc_recomp_shared.h, so both name one symbol; the
  //      /MAP from the link that produced build/w654.log resolves it to the
  //      override TU and to nothing else:
  //        build/mcla.map:1483  sub_821C29A0  alloc_census.cpp.obj
  //        build/mcla.map:1511  sub_82177EB0  config_dispatch.cpp.obj
  //        (+ :1483/:1660-class rows for 821DE9D8, 821C1BB0, 8218CC70)
  //      The generated bodies are the separate `__imp__sub_<addr>` symbols
  //      (:13246, :9208). So SetFunction(addr, sub_addr) stored the value the
  //      mapping row had already stored, into the same slot.
  //  (3) The SetFunction mechanism cannot reach these call sites anyway.
  //      ppc_xrefs.py calls reports direct bl/b edges only (5 for 0x82177EB0,
  //      6 for 0x8218CC70, 2 for 0x821C1BB0, 1 for 0x821DE9D8, 0 for
  //      0x821C29A0); each recompiles to `sub_<addr>(ctx, base);` at link time
  //      (e.g. ppc_recomp.9.cpp:11598-11600). `rg PPC_CALL_INDIRECT_FUNC\(0x
  //      82177EB0\|0x8218CC70\|0x821C1BB0\|0x821C29A0\|0x821DE9D8\)` in
  //      generated/ = 0 hits out of 14,832 indirect sites, and ppc_xrefs.py
  //      xref finds no site materialising any of the five as a pointer value.
  //      The only raw BE occurrence of each in build/cache/mcla_pe.bin is the
  //      module's sorted function-boundary table (off 0x106140/0x106170/
  //      106FD0/0x1042B8: VA + a flags word), which is an enclosing-function
  //      lookup, not a call target -- and 0x8218CC70 is absent from it entirely.
  // Live owners, unchanged: alloc_census.cpp:1774 (0x821C29A0, the unconditional
  // SESSION-39 zero-size fix), :4356 (0x821C1BB0), :6908 (0x821DE9D8),
  // config_dispatch.cpp:113 (0x82177EB0, the TEXCREATE-SC r3<0 -> 0 fix) and
  // :157 (0x8218CC70).
  //
  // 0x821BD618 stays: it is the same redundant no-op, but it is the ONLY claim
  // on that address (the owner is the PPC_FUNC_IMPL body in
  // src/kernel/imports.cpp, which addr_owners.py indexes as `body:`, not as a
  // claim), so no rule-4 conflict exists to resolve. Named here for the next
  // sweep rather than deleted under a rule that was not triggered.
  dispatcher->SetFunction(0x821BD618, sub_821BD618);

  // SESSION 50/51: Capture-only config dispatch census + caller trace now lives
  // only in the config_dispatch.cpp:113 / :157 bodies (see the deletion note
  // above); nothing is registered for 0x8218CC70 or 0x82177EB0 at runtime.

  // Watch the specific config-dispatch global region to catch who writes
  // 0x82839254..0x8283927C.
  mcla::native::RegisterGuestWatchRange(0x82839254u, 0x82839280u);

  const std::string_view mode = MCLA_CVAR_GET_STRING(renderer_mode);
  if (mode == "compat") {
    MCLA_LOG_WARN(
        "mcla_ApplyPatches: COMPAT mode - only 0x82554080 stub "
        "installed (backup 2026-07-16 parity); all guest patches skipped");
    return;
  }

  if (BisectGroupEnabled("sdk")) {
    MclaPatchSdkExecutePacketType3Overflow();
  }

  // "ke" is now an EMPTY group name: it was the KeWait bisect axis and the
  // hook it gated is gone (below). Left in the OR-list so an existing
  // mcla_patch_groups=ke command line keeps parsing and still falls through
  // to the other groups instead of short-circuiting to "stub only".
  if (!BisectGroupEnabled("guest") && !BisectGroupEnabled("ke") &&
      !BisectGroupEnabled("fs") && !BisectGroupEnabled("in") &&
      !BisectGroupEnabled("gp") && !BisectGroupEnabled("ps")) {
    MCLA_LOG_WARN("mcla_patch_groups: no guest sub-group enabled - all guest "
                  "hooks (FS/input/GPU-kick/DPC/PressStart) skipped");
    MCLA_LOG_INFO("MCLA patches applied (stub only)");
    return;
  }

  // DELETED 2026-09-28 (F-609 sweep): the hk_KeWaitForSingleObject registration
  // at 0x827BD5A4, which force-returned STATUS_SUCCESS for waits on
  // 0x828CD9AC ("kDisplaySyncSem") and 0x40004D7C ("kSchedulerTick") instead
  // of calling the real wait. Both objects now have real producers/consumers
  // — imports.cpp:1836 SignalSchedulerTick (kSchedulerTickSem = 0x40004D7C,
  // called from the vblank thread at :1784) and the real wait at
  // imports.cpp:2156 — so the hook was a short-circuit stacked on working
  // code (do-not #9). REACHABILITY PROOF, three independent legs:
  //  (1) Link-time binding. All 22 `bl 0x827bd5a4` sites in generated/
  //      recompile to a DIRECT C++ call, e.g. ppc_xenon/ppc_recomp.78.cpp:
  //      27217-27218 `ctx.lr = 0x8242FC1C; __imp__KeWaitForSingleObject(ctx,
  //      base);`; the rest are ppc_xenon/ppc_recomp.{72,80,81,82,83,84}.cpp and
  //      ppc/ppc_recomp.{74,80,82,83,84}.cpp. `__imp__KeWaitForSingleObject`
  //      is a plain `GUEST_FUNCTION_HOOK` body (imports.cpp:3653), fixed at
  //      link time.
  //  (2) SetFunction cannot intercept a direct call. It writes m_functions
  //      (app.cpp:337) and calls InsertFunction (app.cpp:342); that runtime
  //      table is read only by PPC_LOOKUP_FUNC / PPC_CALL_INDIRECT_FUNC
  //      (ppc_context.h:124-127). `rg 827BD5A4 generated/` finds no
  //      PPC_CALL_INDIRECT_FUNC(0x827BD5A4) — only the mapping-table rows.
  //  (3) Measured, w654.log (newest soak, 21.5 MB): the real wait logs
  //      WAIT[KWFSO] 6515 / WAKE[KWFSO] 6513, of which 6514 name
  //      obj@40004D7C — i.e. 0x40004D7C is STILL waited on by reachable guest
  //      code (the boot-worker poll at lr=0x8242FC1C) and the HLE wait is the
  //      thing that serves it. This hook's own unconditional first-fire marker
  //      "KeWait FIRST CALL" = 0, "KEWAIT-CENSUS" = 0, "-> SKIPPED" = 0,
  //      "chaining to original" = 0 — against "Installing KeWaitForSingleObject
  //      hook at 0x827BD5A4 (FORCE ENABLED)" = 1. Not a near-miss: never
  //      entered, for either object.
  //  PER-OBJECT: 0x40004D7C = REACHABLE, and served correctly by the real
  //  path (above) — keeping the hook would only have been harmful.
  //  0x828CD9AC = no reachability evidence at all: `rg 828CD9AC .` gives 1
  //  hit, this file's own constant; the raw image has 0 occurrences of the
  //  BE word (build/cache/mcla_pe.bin) and its one 0x828C word at 0x827ebec6
  //  is data (op=0, zero-padded neighbours), not a `lis`; and 0 of the last 6
  //  soaks (w649-w654) mention it. But per F-088 §5 "0 times in the image" is
  //  a category error for a runtime object address, so this is recorded as
  //  UNPROVEN-DEAD rather than asserted — moot, because the hook was dead for
  //  BOTH addresses and the object is now served by imports.cpp:2156.

  // 2026-09-28 RULE-4 (0x827BCEB4 NtClose / 0x827BD914 NtReadFile /
  // 0x827BD934 NtCreateFile / 0x827BD9D4 NtQueryInformationFile): the four
  // Get+Set pairs here and their hk_Nt* wrappers (the g_original_Nt* globals at
  // the top of this file) are DELETED, not re-gated. Owner is and always was
  // src/kernel/imports.cpp -- build/mcla.map:3961 / :4005 / :3661 / :3963 name
  // `imports.cpp.obj` as the sole definer of all four
  // ?__imp__NtCreateFile/NtReadFile/NtQueryInformationFile/NtClose@@YAXAEIAU
  // PPCContext@@PEAE@Z symbols, and the generated table rows are the
  // dispatcher's default binding (config_dispatch.cpp:66-76). The wrappers
  // added nothing: each is `if (mcla::vfs::hooks::NtXxxHook(...)) {...}` over a
  // stub that `(void)`-casts all four args and `return false`
  // (src/fs/vfs_rpf.cpp:1328-1362), so the body was provably
  // `g_original_NtXxx(ctx, base)`. Measured: the real file path is served by
  // the imports.cpp body -- build/w658.log carries 694 "GETDEV" and 256
  // "NT-CREATE" lines with 0 "VFS-NTCREATE"/"OPENFILE" from the hook side.
  // "fs" is kept in the bisect-group name list at the gate above so an
  // existing mcla_patch_groups=fs still parses.
  if (BisectGroupEnabled("fs")) {
    MCLA_LOG_INFO(
        "mcla_patch_groups: fs group is a no-op -- the Nt* import thunks are "
        "owned by src/kernel/imports.cpp (RULE-4, 2026-09-28)");
  }

  if (BisectGroupEnabled("in")) {
    // Removed 2026-09-23 (F-092): this shadowed the REAL input path. The
    // generated table owns the slot -- ppc_func_mapping.cpp:44998 maps
    // 0x827BDC64 to __imp__XamInputGetState, which via GUEST_FUNCTION_HOOK
    // (kernel/function.h:351) reaches kernel::XamInputGetState
    // (kernel/xam.cpp:261), an SDL keyboard-to-pad mapping. SetFunction
    // overwrites m_functions[addr] (app.cpp:339) AND calls InsertFunction
    // (app.cpp:342; body app.cpp:337-343), and mcla_ApplyPatches runs after
    // InstallFunctionTable (boot_host.cpp:1972, reached from app.cpp:72) -- so
    // this later registration always won, leaving the guest reading a pad that
    // reports no buttons unless the synthetic StartPulseActive() timer
    // (was patches.cpp:51, no host input behind it) happened to be high.
    // Two owners of one guest address is also what rule 4 forbids.
    // SUPERSEDED 2026-09-28 (F-609 sweep): the last sentence above no longer
    // holds. hk_XamInputGetState, StartPulseActive, hk_native_XamInputGetState
    // and CallOriginalNativeXamInputGetState are DELETED, not parked -- they
    // were a fabricator (a Start press synthesised from a wall clock, with no
    // host input behind it) with no reachable entry point, and the no-emulation
    // charter says a corpse is worse than an absence. Guest input now has
    // exactly one owner, kernel::XamInputGetState (kernel/xam.cpp:261).

    auto *ks = mcla::GetApp();
    if (ks) {
      g_virtual_membase = ks->GetPPCBase();
    }

    // Removed 2026-09-23 (F-092): mcla_DetourImportThunk(&__imp__XamInputGetState)
    // could never succeed, and success would have been worse than the error it
    // logged. __imp__XamInputGetState is NOT a Windows import thunk --
    // GUEST_FUNCTION_HOOK (src/kernel/function.h:351) expands it to a host
    // PPC_FUNC at src/kernel/imports.cpp:3596, so its first bytes are our own
    // compiled prologue, never the `FF 25` (jmp [rip+disp32]) the test demanded.
    // Had it passed, VirtualProtect + the 12-byte write would have replaced the
    // head of that live host function with `movabs rax,hook; jmp rax`. Everything
    // downstream (E9/hotpatch analysis, the 128-byte dumps, the
    // InstallNativeDetour rewrite of the "real" func) sat unreachable behind
    // that impossible condition, and its
    // only consumer was more logging. Intercepting a guest import here takes
    // dispatcher->SetFunction (writes the real table, app.cpp:342) - none now.
    if (true) { // BisectGroupEnabled("gp") - FORCE ENABLED
      mcla::gpu::CpInstallMmioRouting();
      mcla::gpu::InstallGpuHooks(dispatcher, mcla::gpu::GpuHooks{});

      g_original_GpuKick = dispatcher->GetFunction(0x82412710);
      if (g_original_GpuKick) {
        dispatcher->SetFunction(0x82412710, hk_GpuKick);
        MCLA_LOG_INFO("GPU Kick (sub_82412710) hooked for PM4 sanitization");
      } else {
        MCLA_LOG_WARN("GPU Kick (sub_82412710) not found in dispatcher");
      }
    }

    // Start render thread for P4.5' - owns all D3D12 calls
    mcla::native::g_renderThread.start();
    MCLA_LOG_ERROR("mcla_ApplyPatches: Render thread started (P4.5')");

    // Device-boundary draw capture (sub_82413660) stays owned by the
    // global-scope PPC_FUNC override in src/gpu_device.cpp:4572 (P5'/B8) - rule
    // 4, one owner per guest address. Registering it here is pointless, not
    // "dead code": SetFunction now writes the real table (app.cpp:342).

    if (true) { // BisectGroupEnabled("gp") - FORCE ENABLED
      dispatcher->SetFunction(0x82130690, hk_sub_82130690);
      dispatcher->SetFunction(0x82130770, hk_sub_82130770);
      dispatcher->SetFunction(0x82130850, hk_sub_82130850);
      dispatcher->SetFunction(0x82130930, hk_sub_82130930);
      dispatcher->SetFunction(0x82130A18, hk_sub_82130A18);
    }

    if (true) { // BisectGroupEnabled("ps") - FORCE ENABLED
      g_press_start_shim_thunk =
          dispatcher->AllocateThunk(hk_press_start_shim, 0x82554080);
      dispatcher->SetFunction(g_press_start_shim_thunk, hk_press_start_shim);
      MCLA_LOG_INFO("Press Start shim thunk allocated+registered at 0x{:08X}",
                    g_press_start_shim_thunk);
    }

    // SESSION 36: removed the hk_sub_821C29A0 / hk_sub_82130B50 registration
    // block and the g_fast_pool_alloc / g_debug_alloc_caller resolution that
    // served it (dead *then*: SetFunction touched only m_functions; it now also
    // writes the real table, app.cpp:342). See the note near the statics above.

    g_orig_sub_82554E20 = dispatcher->GetFunction(0x82554E20);
    if (g_orig_sub_82554E20) {
      dispatcher->SetFunction(0x82554E20, hk_sub_82554E20);
      MCLA_LOG_INFO("Screen manager (sub_82554E20) hooked");
    } else {
      MCLA_LOG_ERROR("sub_82554E20 not found in dispatcher");
    }

    // DELETED 2026-09-28 (F-609 one-owner sweep): the save-original-then-hook
    // on 0x824569C8. It looked like the sanctioned idiom -- GetFunction sits
    // between the two SetFunction calls, single file -- but the "original" it
    // saved was NOT the generated body: `sub_824569C8` resolves to the
    // compile-time PPC_FUNC override at src/gpu_device.cpp:14944 (build/mcla.map
    // :1822 `?sub_824569C8@@YAXAEIAUPPCContext@@PEAE@Z gpu_device.cpp.obj`;
    // the generated body is the separate `__imp__sub_824569C8`, :46817). So the
    // block put a `set` claim on an address a `PPC_FUNC` body already owned, and
    // the wrapper it installed chains straight back into that same body -- a
    // binding cycle, not a hook.
    //
    // The two mechanisms diverged per call site, which is the hazard:
    //  * direct bl/b -- ppc_xrefs.py calls 0x824569C8 = 0 sites, and
    //    `rg "sub_824569C8\(ctx" generated/` = 0, so this arm is unmeasured-dead;
    //  * table-indirect -- src/kernel/guest_thread.cpp:177 resolves a guest
    //    thread entry with FindFunction and calls it at :179, so an
    //    ExCreateThread(0x824569C8) would reach hk_sub_824569C8, while a direct
    //    edge would reach the gpu_device body and skip it.
    // Measured: build/w654.log + w653.log hold 0 "WORKER-ENTRY sub_824569C8"
    // (the wrapper's own marker) AND 0 "WORKER sub_824569C8" (the override's
    // marker) -- the guest never creates that thread: 17 "THREAD-CREATE #"
    // lines, 0 of them the "THREAD-CREATE TU83 WORKER" census at
    // src/kernel/imports.cpp:4247, which fires only for 0x824569C8/0x823F69C8.
    //
    // Deleting the wrapper loses nothing and unifies the owner: the override
    // logs 9 wake-relevant fields of 0x827D3738 + caller LR + callback target
    // UNCONDITIONALLY, against the wrapper's 5 registers behind a
    // kPool16CensusEnabled gate that is false (src/hooks/hooks.h:34), so the
    // override is both the richer and the unconditionally-reachable census.
    // Keep the census; keep one owner. src/gpu_device.cpp:14944 needs no edit.

    if (g_virtual_membase) {
      uint32_t cb2 = *(uint32_t *)(g_virtual_membase + 0x828DA3C4);
      MCLA_LOG_INFO("sub_82554590 callback at 0x828DA3C4 = 0x{:08X}", cb2);
    }

  } // end BisectGroupEnabled("gp")

  // 2026-09-28 RULE-4 (0x827BD6E4): the VdSwap observer Get+Set pair (was
  // :638-645) is DELETED -- see the hk_vdswap_observer note above. 0x827BD6E4 is
  // bound by src/native_renderer.cpp Hooked_VdSwap (SetFunction, w658.log:133
  // and its own census at w658.log:5727) and, for the direct-import arm, by
  // src/kernel/imports.cpp's `PPC_FUNC(__imp__VdSwap)` body. Nothing is left to
  // install here in legacy mode, so `mode`/`native` no longer gate anything at
  // this point in the function.
  // 2026-09-28 RULE-4 (0x827BD574): the Get+Set pair that put
  // hk_VdInitializeEngines on 0x827BD574 and its two log lines are DELETED.
  // 0x827BD574 is __imp__KeReleaseSemaphore
  // (generated/ppc_xenon/ppc_func_mapping.cpp:44887); VdInitializeEngines is
  // 0x827BD784 (:44920) -- the old comment on the removed line said so and the
  // code contradicted it anyway. The one real body is
  // src/kernel/imports.cpp:5080 GUEST_FUNCTION_HOOK(__imp__KeReleaseSemaphore,
  // KeReleaseSemaphore), proven by build/mcla.map:4271
  // (`?__imp__KeReleaseSemaphore@@YAXAEIAUPPCContext@@PEAE@Z ... imports.cpp.obj`,
  // the only definition in the image); ppc_func_mapping.cpp:44887 is a table
  // row, not a body, and it is the default binding config_dispatch.cpp:66-76
  // loads. hk_VdInitializeEngines was a passthrough into that same body
  // (g_orig_VdInitializeEngines(ctx, base) and nothing else), so the Set
  // replaced the only KeReleaseSemaphore with a wrapper that calls it -- a
  // chain, not a hook. Which mechanism would have won is not worth recording
  // as unknown: this build never ran it. The gate above needs BOTH mode !=
  // "compat" and !BisectGroupEnabled("native"), and build/w658.log:131 says
  // "mode=native" -- so the block was skipped, and neither
  // "VdInitializeEngines detour installed" nor "VdInitializeEngines[" nor
  // "VdInitializeEngines original not found" occurs in w658.log or w653.log.
  // It was a latent hijack, never a live loss.

  MCLA_LOG_INFO("MCLA patches applied (1 entry + 5 GPU hooks + 5 timer hooks + "
                "native renderer + screen hooks)");

  // One-shot host signal into the guest's 30 ms scheduler-tick object, 3 s in.
  // F-316 names 0x40004D7C the boot-worker tick (the guest computes it as
  // r26+32 off its own DPC context 0x40004D5C), NOT a "GPU init semaphore" as
  // the log line below still says. LABELLED, NOT REMOVED: it is still
  // reached (w654.log:747, the single occurrence of the string in that soak),
  // and rule 1 forbids deleting a live short-circuit whose root cause is
  // unknown. Its measured worth is zero -- F-316 counted this release as
  // satisfying 0 of 6,626 polls on the object, and w654 still ends in the
  // WAIT[KWFSO] obj@40004D7C to=30ms poll (6,515 lines). GATE FOR REMOVAL:
  // a soak in which `WAKE[KWFSO] ... obj@40004D7C status=00000000` rows are
  // attributable to this thread rather than to SignalSchedulerTick
  // (imports.cpp:1836, fired from the vblank thread at :1784). Until then it
  // is an unverifiable producer racing the real one; it is NOT a wait
  // short-circuit and must not be conflated with the deleted KeWait hook.
  std::thread([ ] {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    void *sem_host = mem.Translate(0x40004D7C);
    if (sem_host) {
      // CONSOLE-CORRECT CLASS (2026-10-21, fix_typebyte): the guest's
      // clock-tick object 0x40004D7C is an EVENT - the guest-visible Type
      // byte at that address is 0x00 (EventNotification, build/w842.log
      // "TYPE-CENSUS[KWFSO] objptr=40004D7C type=00") and the guest RESETS
      // it (0x8242FCD4 addi r3,r26,32 / 0x8242FCD8 bl 0x827BD874 =
      // __imp__KeResetEvent).  The old KeReleaseSemaphore call resolved it
      // as a Semaphore, which is the cross-type confusion that produced the
      // KOBJ-CLASSFLIP rows (29 in build/w842.log) and LOST the guest's
      // reset.  SignalSchedulerTickPublic() is the same path the recurring
      // clock tick uses (it SETs the event).
      SignalSchedulerTickPublic();
      MCLA_LOG_WARN("HOST-ONE-SHOT set scheduler-tick 0x40004D7C "
                    "(lr=0, host-origin, not a guest producer; F-316: 0 of "
                    "the polls satisfied)");
    } else {
      MCLA_LOG_ERROR("Failed to translate semaphore 0x40004D7C");
    }
  }).detach();
}

static constexpr uint32_t kMaxPm4Count = 0x800;
static constexpr uint32_t kPm4Type3Mask = 0xC0000000;
static constexpr uint32_t kPm4Type3Value = 0xC0000000;
static constexpr uint32_t kPm4OpcodeMask = 0x00007F00;
static constexpr uint32_t kPm4CountMask = 0x3FFF0000;
static constexpr uint32_t kPm4IndirectBufOpcode = 0x3F;

static void SanitizePm4Buffer(mcla::native::GuestMemoryView &view,
                              uint32_t base, uint32_t limit) {
  if (!base || base >= limit)
    return;
  uint32_t offset = 0;
  while (base + offset + 4 <= limit) {
    uint32_t header = 0;
    if (!view.ReadU32BE(base + offset, &header))
      break;
    if ((header & kPm4Type3Mask) != kPm4Type3Value) {
      offset += 4;
      continue;
    }
    uint32_t count = (header & kPm4CountMask) >> 16;
    uint32_t opcode = (header & kPm4OpcodeMask) >> 8;
    uint32_t packet_dwords = 1 + count;

    if (count > kMaxPm4Count) {
      uint32_t new_header = (header & ~kPm4CountMask) | (kMaxPm4Count << 16);
      view.WriteU32BE(base + offset, new_header);
      count = kMaxPm4Count;
      packet_dwords = 1 + count;
    }

    if (opcode == kPm4IndirectBufOpcode && count == 2) {
      uint32_t ib_base = 0, ib_dwords = 0;
      if (view.ReadU32BE(base + offset + 4, &ib_base) &&
          view.ReadU32BE(base + offset + 8, &ib_dwords)) {
        if (ib_dwords > kMaxPm4Count) {
          ib_dwords = kMaxPm4Count;
          view.WriteU32BE(base + offset + 8, ib_dwords);
        }
        if (ib_base && ib_dwords > 0) {
          SanitizePm4Buffer(view, ib_base, ib_base + ib_dwords * 4);
        }
      }
    }

    offset += packet_dwords * 4;
    if (offset > (limit - base))
      break;
  }
}

PPC_FUNC_IMPL(hk_GpuKick) {
  uint32_t mgr = ctx.r3.u32;
  if (mgr) {
    mcla::native::GuestMemoryView view;
    uint32_t write_ptr = 0, limit = 0, base = 0;
    static bool s_kick_diag_done = false;
    if (!s_kick_diag_done) {
      s_kick_diag_done = true;
      uint32_t d48 = 0, d52 = 0, d56 = 0;
      view.ReadU32BE(mgr + 48, &d48);
      view.ReadU32BE(mgr + 52, &d52);
      view.ReadU32BE(mgr + 56, &d56);
      MCLA_LOG_WARN("GpuKick diag: mgr=0x{:08X} +48(write)=0x{:08X} "
                    "+52(limit)=0x{:08X} +56={:08X}",
                    mgr, d48, d52, d56);
    }
    if (view.ReadU32BE(mgr + 48, &write_ptr) &&
        view.ReadU32BE(mgr + 52, &limit)) {
      if (!view.ReadU32BE(mgr + 56, &base) || !base) {
        base = limit - 0x10000;
      }
      if (base && write_ptr && write_ptr >= base && write_ptr <= limit) {
        SanitizePm4Buffer(view, base, write_ptr);
      }
    }
  }
  if (g_original_GpuKick)
    g_original_GpuKick(ctx, base);
}

// DELETED 2026-09-28 (F-609 sweep), bodies of hk_KeWaitForSingleObject
// (was :703-780) and hk_XamInputGetState (was :782-808), together with
// their object constants kDisplaySyncSem = 0x828CD9AC (:711) and
// kSchedulerTick = 0x40004D7C (:712). Reachability proofs:
//  * hk_KeWaitForSingleObject - never entered. See the three-leg proof at
//    the deleted SetFunction(0x827BD5A4) registration: 22 direct __imp__
//    binds, no PPC_CALL_INDIRECT_FUNC(0x827BD5A4) in generated/, and
//    w654.log measuring 6515 real WAIT[KWFSO] rows against 0 rows from
//    this hook. The F-578 KEWAIT-CENSUS it carried also died with it
//    (0 rows in w649-w654), so nothing observational is lost:
//    imports.cpp:2214 prints the same obj+lr per wait and is the row count
//    that actually moved.
//  * hk_XamInputGetState - no entry point at all. Its only registration,
//    SetFunction(0x827BDC64, ...) (was :516), was removed on 2026-09-23
//    (F-092) precisely because it shadowed the real path; after that edit
//    the only references left in the whole tree were its own extern "C"
//    declaration (was :236) and this definition, so `rg
//    hk_XamInputGetState src/ generated/` returned 2 self-references. It
//    also fabricated the Start button out of StartPulseActive, a
//    wall-clock toggler with no host input behind it, and returned a
//    hardcoded r3=0 instead of the real pad state.
// 2026-09-28 RULE-4: hk_NtCreateFile / hk_NtReadFile /
// hk_NtQueryInformationFile / hk_NtClose (bodies were :803/:815/:832/:847) and
// their registrations at 0x827BD934 / 0x827BD914 / 0x827BD9D4 / 0x827BCEB4 are
// DELETED. Each was `if (mcla::vfs::hooks::NtXxxHook(...)) { ...; return; }` +
// `g_original_NtXxx(ctx, base)`, and all four hooks are `(void)`-cast stubs
// that `return false` unconditionally (src/fs/vfs_rpf.cpp:1328-1362) -- so each
// body provably reduced to the passthrough call and the guest-visible
// behaviour with or without the wrapper is identical. The `get` half is what
// made it a second binding at all: it resolved to the same body
// (build/mcla.map:3961/:4005/:3661/:3963 all name `imports.cpp.obj`).
// The four log markers they could have printed ("Nt*Hook" census, the
// "Nt*File original not found" errors) are all at 0 in build/w658.log.
// src/kernel/imports.cpp:4891/:4892/:4917/:145 is the sole owner. Restore the
// VFS interposition there, not here, if it is ever wanted.

PPC_FUNC_IMPL(hk_sub_82554E20) {
  static int callCount = 0;
  callCount++;
  if (callCount <= 50 || (callCount % 1000) == 0) {
    MCLA_LOG_INFO("hk_sub_82554E20[{}]: lr={:08X}", callCount,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }
  if (g_orig_sub_82554E20)
    g_orig_sub_82554E20(ctx, base);
}

// SESSION 36: PPC_FUNC_IMPL(hk_sub_821C29A0) removed - dead code with a
// latent fatal-raise landmine (called sub_821BD618, the guest OOM fatal
// dispatcher, directly with (fmt, pool, size) args on its fallback path).
// The authoritative decode is now src/hooks/alloc_census.cpp:1774+ - the
// .clinerules/memory/ (c83ec91) + docs/BOOT_HANDOFF.md (5fbc08e) paths are gone.

// MASTER SWITCH kPool16CensusEnabled (src/hooks/hooks.h:34; hooks.h:35 also
// wants MCLA_ALLOC_DEBUG) is false, so no census overhead (slab walks, file I/O,
// snapshot scans, per-alloc logging) runs. Session 56: every detection was false.

// PPC_FUNC_IMPL(hk_sub_824569C8) removed 2026-09-28 (F-609 one-owner sweep).
// It was the census half of the save-original-then-hook that has been deleted
// above, and it was strictly weaker than the owner it wrapped: the whole body
// sat behind `if constexpr (!kPool16CensusEnabled) { chain; return; }`
// (src/hooks/hooks.h:34 -> false), so the log line below could never print, and
// the one it replaced -- src/gpu_device.cpp:14944, "WORKER sub_824569C8" --
// logs 9 wake-relevant fields of 0x827D3738 plus the caller LR and the
// 0x82945A80 callback target, unconditionally. Both were 0 in build/w654.log and
// w653.log, so this is a fork with no measured traffic either way, resolved in
// favour of the unconditionally-reachable owner.

// hk_sub_82413660 removed (P5'/B8): it was never registered and it duplicated
// the live global-scope override PPC_FUNC(sub_82413660) in
// src/gpu_device.cpp:4572, which stays diagnostic-only (chains to __imp__ at
// :4590); native geometry submission is owned by sub_82420BA8 (:3163).

PPC_FUNC_IMPL(hk_sub_82411840) {
  // DEAD: registered nowhere; the live census of 0x82411840 is src/gpu_device.cpp:4595.
  static std::atomic<uint32_t> s_hookCount{0};
  const uint32_t n = s_hookCount.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t cls = ctx.r4.u32;
  const uint32_t arg = ctx.r5.u32;

  MCLA_LOG_INFO(
      "NATIVE DRAW CONSUMER: sub_82411840 #{} dev={:08X} class={} arg={:08X}",
      n, dev, cls, arg);

  // Enqueue state change command if needed
  // For now just log and chain to original
  // TODO: Enqueue state change commands

  // Chain to original for legacy path
  __imp__sub_82411840(ctx, base);
}

PPC_FUNC_IMPL(hk_sub_822A3998) {
  // Placeholder for other hooks
  MCLA_LOG_INFO("hk_sub_822A3998 called");
}

PPC_FUNC_IMPL(hk_sub_82554590) {
  // Placeholder
  MCLA_LOG_INFO("hk_sub_82554590 called");
}

// Press Start handler shim, dispatched by the bytecode interpreter's
// handler-dispatch case (opcode 0x2D = case 44 of its switch on opcode-1,
// 0x82555C24) instead of the handler the operand bytes name. Screen object:
// guest global 0x828DA3BC, stored/cleared by sub_82554800 (recomp.109:1194) -
// sub_82554E20 never touches it. Reason = the interpreter's own 0x828110D4
// (recomp.109:4496); 0x82017D0C occurs 0 times in mcla_pe.bin. r31 is a local
// register in generated code under this ABI, so it must not be read here.
PPC_FUNC_IMPL(hk_press_start_shim) {
  static int count = 0;
  count++;

  uint32_t screenObj = PPC_LOAD_U32(0x828DA3BC);
  uint32_t old = PPC_LOAD_U32(screenObj + 12);

  // Call sub_82554590 - signals screen completion (writes flag=2).
  {
    uint32_t saved_r3 = ctx.r3.u32;
    uint32_t saved_r4 = ctx.r4.u32;
    ctx.r3.u64 = screenObj;
    ctx.r4.u64 = 0x828110D4;
    sub_82554590(ctx, base);
    ctx.r3.u64 = saved_r3;
    ctx.r4.u64 = saved_r4;
  }

  // Ensure flag=2.
  PPC_STORE_U32(screenObj + 12, 2);

  if (count <= 3) {
    uint32_t cb = PPC_LOAD_U32(0x828DA3C4);
    MCLA_LOG_WARN("hk_press_start_shim[{}]: screenObj=0x{:08X} old=0x{:08X} "
                  "cb=0x{:08X} -> flag=2",
                  count, screenObj, old, cb);
  }
}

// Deliberate (kept, NOT deleted) -- it hands back the shim thunk instead of
// the original XAM handler at 0x812A1100, covering the jump-table lookup
// path. MEASURED, w654.log: "sub_82554080 stub" = 0 and "hk_press_start_shim"
// = 0, i.e. this stub has never been entered and therefore neither has the
// shim, whose ONLY route in is the thunk it returns (g_press_start_shim_thunk,
// consumed at :881 and nowhere else). So the whole press-start chain is
// registered-but-unentered today; it is kept because it is a deliberate
// design, not a fake, and its root cause for not firing (the guest never
// calls 0x82554080) is not established. The write-only latch
// `g_press_start_bypassed = true` that used to sit here was deleted with the
// statics at the top of this file -- it gated nothing.
PPC_FUNC_IMPL(sub_82554080_stub) {
  static int count = 0;
  count++;

  // Return the shim thunk address so the screen manager calls our
  // handler (hk_press_start_shim) instead of the original XAM handler
  // at 0x812A1100. Covers the jump-table lookup path.
  ctx.r3.u64 = g_press_start_shim_thunk;
  if (count <= 3) {
    MCLA_LOG_WARN("sub_82554080 stub[{}]: returning thunk 0x{:08X}", count,
                  ctx.r3.u32);
  }
}

static void ReinitGpuBackend(mcla::native::PPCContext &ctx, uint8_t *base) {
  uint32_t gfx_ctx_guest = PPC_LOAD_U32(0x82839254);
  if (!gfx_ctx_guest || gfx_ctx_guest >= 0x90000000) {
    MCLA_LOG_ERROR("Invalid GPU context ptr 0x{:08X} from [0x82839254]",
                   gfx_ctx_guest);
    return;
  }

  MCLA_LOG_WARN("Calling VdInitializeEngines (ctx=0x{:08X})", gfx_ctx_guest);
  {
    auto saved_lr = ctx.lr;
    ctx.r3.u64 = 0x1B530000;
    ctx.r4.u64 = 0x82425D78;
    ctx.r5.u64 = 0;
    ctx.r6.u64 = 0x82066110;
    ctx.r7.u64 = 0x82066590;
    PPC_CALL_INDIRECT_FUNC(0x827BD784);
    ctx.lr = saved_lr;
  }

  MCLA_LOG_WARN("Calling VdSetGraphicsInterruptCallback");
  {
    auto saved_lr = ctx.lr;
    ctx.r3.u64 = 0x82411478;
    ctx.r4.u64 = gfx_ctx_guest;
    PPC_CALL_INDIRECT_FUNC(0x827BD774);
    ctx.lr = saved_lr;
  }

  uint32_t ring_buf = PPC_LOAD_U32(gfx_ctx_guest + 14836);
  if (ring_buf) {
    MCLA_LOG_WARN("Calling VdInitializeRingBuffer (ring=0x{:08X})", ring_buf);
    auto saved_lr = ctx.lr;
    ctx.r3.u64 = ring_buf;
    PPC_CALL_INDIRECT_FUNC(0x827BD5F4);
    ctx.r4.u64 = 12;
    PPC_CALL_INDIRECT_FUNC(0x827BD6B4);
    ctx.lr = saved_lr;
  }

  uint32_t sub_ctx = PPC_LOAD_U32(gfx_ctx_guest + 10896);
  if (sub_ctx) {
    auto saved_lr = ctx.lr;
    ctx.r3.u64 = sub_ctx + 60;
    PPC_CALL_INDIRECT_FUNC(0x827BD5F4);
    ctx.r4.u64 = 19;
    PPC_CALL_INDIRECT_FUNC(0x827BD6A4);
    ctx.lr = saved_lr;
  }

  {
    MclaGpuContext *gpuCtx =
        reinterpret_cast<MclaGpuContext *>(base + gfx_ctx_guest);
    mcla::native::WriteGpuContextToRegisterFile(gpuCtx);
    MCLA_LOG_WARN("Register file seeded from saved context (rbSurf0=0x{:08X})",
                  gpuCtx->rbSurfaceInfoP0);
  }

  uint32_t ctrl_struct = PPC_LOAD_U32(gfx_ctx_guest + 10900);
  if (ctrl_struct) {
    uint32_t callback = PPC_LOAD_U32(ctrl_struct + 16);
    if (callback == 0x0BADF00D) {
      MCLA_LOG_WARN("Clearing 0x0BADF00D from ctrl_struct+16 (ctrl=0x{:08X})",
                    ctrl_struct);
      PPC_STORE_U32(ctrl_struct + 16, 0);
    }
  }
}

