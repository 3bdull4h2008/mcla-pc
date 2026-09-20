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

// Forward declarations for kernel functions via import thunks
extern "C" uint32_t KeReleaseSemaphore(void *, uint32_t, uint32_t, uint32_t);

static mcla::App::FunctionDispatcher *g_dispatcher = nullptr;
static uint8_t *g_virtual_membase = nullptr;

static uint8_t g_original_native_bytes[12];
static uint8_t g_native_detour_code[12];

// Internal helpers only - no external linkage needed
namespace {
constexpr std::chrono::milliseconds kStartHoldMs(1000);
constexpr std::chrono::milliseconds kStartReleaseMs(1000);

bool StartPulseActive() {
  static bool held = false;
  static auto phase_end = std::chrono::steady_clock::now() + kStartHoldMs;
  const auto now = std::chrono::steady_clock::now();
  if (now >= phase_end) {
    held = !held;
    phase_end = now + (held ? kStartHoldMs : kStartReleaseMs);
  }
  return held;
}

// SESSION 44b: minimal census on sub_821C2AB8 to verify call path
namespace {
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

// SESSION 44c: census on sub_821C09C8 — the dispatch function that routes
// pool frees. Logs r3 (heap), r4 (node), ctx.lr (stale but diagnostic),
// and reads the caller's stack to find the real return address.

static void *g_native_XamInputGetState_func = nullptr;

static bool InstallNativeDetour(void *target, void *hook, uint8_t *save_buf,
                                size_t size) {
  if (!target || size < 12)
    return false;
  DWORD old;
  if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old))
    return false;
  memcpy(save_buf, target, 12);
  uint8_t *p = (uint8_t *)target;
  p[0] = 0x48;
  p[1] = 0xB8;
  memcpy(p + 2, &hook, sizeof(void *));
  p[10] = 0xFF;
  p[11] = 0xE0;
  FlushInstructionCache(GetCurrentProcess(), target, size);
  DWORD dummy;
  VirtualProtect(target, size, PAGE_EXECUTE_READ, &dummy);
  return true;
}

static void RemoveNativeDetour(void *target, const uint8_t *save_buf,
                               size_t size) {
  DWORD old;
  VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old);
  memcpy(target, save_buf, size < 12 ? size : 12);
  FlushInstructionCache(GetCurrentProcess(), target, size);
  DWORD dummy;
  VirtualProtect(target, size, PAGE_EXECUTE_READ, &dummy);
}

extern "C" DWORD __fastcall hk_native_XamInputGetState(DWORD port,
                                                       void *state) {
  static int callCount = 0;
  callCount++;

  if (callCount <= 10) {
    MCLA_LOG_INFO("hk_native_XamInputGetState[{}]: port={} state=0x{:p}",
                  callCount, port, state);
  }

  if (state) {
    uint16_t *buttons = (uint16_t *)((uint8_t *)state + 4);
    uint16_t old = *buttons;
    if (StartPulseActive()) {
      *buttons |= 0x0010;
    } else {
      *buttons &= static_cast<uint16_t>(~0x0010u);
    }
    if (callCount <= 5) {
      MCLA_LOG_INFO("hk_native_XamInputGetState[{}]: Start held={} "
                    "(old=0x{:04X} new=0x{:04X})",
                    callCount, StartPulseActive(), old, *buttons);
    }
  }
  return 0;
}

extern "C" DWORD __fastcall CallOriginalNativeXamInputGetState(DWORD port,
                                                               void *state) {
  void *target = g_native_XamInputGetState_func;
  if (!target)
    return 0;

  RemoveNativeDetour(target, g_original_native_bytes, 12);
  DWORD ret = ((DWORD(__fastcall *)(DWORD, void *))target)(port, state);
  InstallNativeDetour(target, (void *)hk_native_XamInputGetState,
                      g_original_native_bytes, 12);
  return ret;
}

static PPCFunc *g_original_KeWait = nullptr;
static PPCFunc *g_original_XamInputGetState = nullptr;
static PPCFunc *g_original_NtCreateFile = nullptr;
static PPCFunc *g_original_NtReadFile = nullptr;
static PPCFunc *g_original_NtQueryInformationFile = nullptr;
static PPCFunc *g_original_NtClose = nullptr;
static PPCFunc *g_original_GpuKick = nullptr;

static constexpr uint32_t kDummyLocHandle = 0x7FFF0001;
static thread_local uint32_t t_pendingLocHandleOut = 0;
static thread_local uint32_t t_lastLocStatus = 0;
static std::unordered_set<uint32_t> s_realLocHandles;
static std::mutex s_realLocHandlesMtx;

PPCFunc *mcla_DetourImportThunk(uint8_t *thunk, PPCFunc *hook) {
  if (!thunk)
    return nullptr;
  if (thunk[0] != 0xFF || thunk[1] != 0x25) {
    MCLA_LOG_ERROR("DetourImportThunk: unexpected thunk bytes at %p: %02X %02X",
                   (void *)thunk, thunk[0], thunk[1]);
    return nullptr;
  }
  int32_t disp = *reinterpret_cast<int32_t *>(thunk + 2);
  void **iat_entry = reinterpret_cast<void **>(thunk + 6 + disp);
  void *original_func = *iat_entry;
  if (!original_func)
    return nullptr;

  DWORD old;
  VirtualProtect(thunk, 12, PAGE_EXECUTE_READWRITE, &old);
  thunk[0] = 0x48;
  thunk[1] = 0xB8;
  memcpy(thunk + 2, &hook, sizeof(void *));
  thunk[10] = 0xFF;
  thunk[11] = 0xE0;
  FlushInstructionCache(GetCurrentProcess(), thunk, 12);
  VirtualProtect(thunk, 12, PAGE_EXECUTE_READ, &old);

  MCLA_LOG_INFO(
      "DetourImportThunk: 0x{:p} -> 0x{:p} (original DLL func = 0x{:p})",
      (void *)thunk, (void *)hook, original_func);
  return reinterpret_cast<PPCFunc *>(original_func);
}

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

static bool g_press_start_bypassed;

static void TimerHookDispatch(mcla::native::PPCContext &ctx, uint8_t *base,
                              uint32_t nameStr, bool returnOne) {
  uint32_t timerObj = PPC_LOAD_U32(TIMER_OBJ_PTR);
  uint64_t deltaBits = GetWallClockDeltaBits();

  PPC_STORE_U64(TIMEBASE_STORE, PPC_QUERY_TIMEBASE());

  static int timerCount = 0;
  timerCount++;

  // CP progress nudge: advance guest publication periodically to unblock
  // fence waits when the CP is idle (guest thinks work is done but CP
  // never processed it). The guest's put/pub counters can get ahead of
  // actual ring consumption.
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

extern "C" void hk_KeWaitForSingleObject(mcla::native::PPCContext &ctx,
                                         uint8_t *base);
extern "C" void hk_XamInputGetState(mcla::native::PPCContext &ctx,
                                    uint8_t *base);
extern "C" void hk_NtCreateFile(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_NtReadFile(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_NtQueryInformationFile(mcla::native::PPCContext &ctx,
                                          uint8_t *base);
extern "C" void hk_NtClose(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130690(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130770(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130850(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130930(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82130A18(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_822A3998(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_82554E20(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_VdInitializeEngines(mcla::native::PPCContext &ctx,
                                       uint8_t *base);
extern "C" void hk_sub_82554590(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_GpuKick(mcla::native::PPCContext &ctx, uint8_t *base);
extern "C" void hk_sub_824569C8(mcla::native::PPCContext &ctx, uint8_t *base);
// hk_sub_82413660 (dead dispatcher duplicate) removed in P5'/B8 — the live
// owner of guest 0x82413660 is the global-scope PPC_FUNC override in
// src/gpu_device.cpp; native geometry submission is owned by sub_82420BA8.
extern "C" void hk_sub_82411840(mcla::native::PPCContext &ctx, uint8_t *base);

PPC_FUNC_IMPL(__imp__sub_82413660);
PPC_FUNC_IMPL(__imp__sub_82411840);

static PPCFunc *g_orig_sub_82554E20 = nullptr;
// SESSION 36: g_orig_sub_821C29A0 / g_orig_sub_82130B50 / g_fast_pool_alloc /
// g_debug_alloc_caller and the hk_sub_821C29A0 hook were removed. The hook was
// registered only via FunctionDispatcher::SetFunction, which fills the
// m_functions map - generated direct calls bind to the weak alias and
// ppc_func_mapping-table indirect calls resolve through that table, so the map
// is never consulted for guest calls (proof: soak35.log has ZERO "ALLOC["
// lines). Its fallback path additionally called the fatal raiser
// sub_821BD618 directly with wrong args. The real allocation-path census now
// lives in the PPC_FUNC(sub_821C29A0) weak-alias override below (OOM-CENSUS)
// and in PPC_FUNC(sub_821C1BB0) (ARENA-CENSUS).
static PPCFunc *g_orig_sub_824569C8 = nullptr;
static PPCFunc *g_orig_VdSwap_observer = nullptr;
PPCFunc *g_orig_VdInitializeEngines = nullptr;

PPC_FUNC_IMPL(hk_vdswap_observer) {
  static std::atomic<uint64_t> s_vdswap_count{0};
  uint64_t c = s_vdswap_count.fetch_add(1) + 1;
  if (c <= 5 || c % 300 == 0) {
    MCLA_LOG_INFO("VdSwapObserver[{}] obj=0x{:08X} swap_info=0x{:08X}", c,
                  ctx.r3.u32, ctx.r4.u32);
  }
  if (g_orig_VdSwap_observer) {
    g_orig_VdSwap_observer(ctx, base);
  }
}

PPC_FUNC_IMPL(hk_VdInitializeEngines) {
  static std::atomic<uint64_t> s_init_count{0};
  uint64_t c = s_init_count.fetch_add(1) + 1;
  MCLA_LOG_INFO("VdInitializeEngines[{}] ctx=0x{:08X}", c, ctx.r3.u32);
  if (g_orig_VdInitializeEngines) {
    g_orig_VdInitializeEngines(ctx, base);
  }
}

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
  MCLA_LOG_ERROR("BisectGroupEnabled('ke') = {}", BisectGroupEnabled("ke") ? "true" : "false");
  g_dispatcher = dispatcher;

  dispatcher->SetFunction(0x82554080, sub_82554080_stub);

  // Register recompiled allocation functions so they can be hooked
  dispatcher->SetFunction(0x821C29A0, sub_821C29A0);
  dispatcher->SetFunction(0x821DE9D8, sub_821DE9D8);
  dispatcher->SetFunction(0x821BD618, sub_821BD618);
  dispatcher->SetFunction(0x821C1BB0, sub_821C1BB0);

  // SESSION 50/51: Capture-only config dispatch census + caller trace
  dispatcher->SetFunction(0x8218CC70, sub_8218CC70);
  dispatcher->SetFunction(0x82177EB0, sub_82177EB0);

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

  if (!BisectGroupEnabled("guest") && !BisectGroupEnabled("ke") &&
      !BisectGroupEnabled("fs") && !BisectGroupEnabled("in") &&
      !BisectGroupEnabled("gp") && !BisectGroupEnabled("ps")) {
    MCLA_LOG_WARN("mcla_patch_groups: no guest sub-group enabled - all guest "
                  "hooks (KeWait/FS/input/GPU-kick/DPC/PressStart) skipped");
    MCLA_LOG_INFO("MCLA patches applied (stub only)");
    return;
  }

  if (true) { // BisectGroupEnabled("ke") - FORCE ENABLED
    MCLA_LOG_WARN("Installing KeWaitForSingleObject hook at 0x827BD5A4 (FORCE ENABLED)");
    g_original_KeWait = dispatcher->GetFunction(0x827BD5A4);
    dispatcher->SetFunction(0x827BD5A4, hk_KeWaitForSingleObject);
    if (!g_original_KeWait) {
      MCLA_LOG_ERROR("KeWaitForSingleObject original not found in dispatch table");
    }
  }

  if (BisectGroupEnabled("fs")) {
    g_original_NtCreateFile = dispatcher->GetFunction(0x827BD934);
    dispatcher->SetFunction(0x827BD934, hk_NtCreateFile);
    if (!g_original_NtCreateFile) {
      MCLA_LOG_ERROR("NtCreateFile original not found in dispatch table");
    }

    g_original_NtReadFile = dispatcher->GetFunction(0x827BD914);
    dispatcher->SetFunction(0x827BD914, hk_NtReadFile);
    if (!g_original_NtReadFile) {
      MCLA_LOG_ERROR("NtReadFile original not found in dispatch table");
    }

    g_original_NtQueryInformationFile = dispatcher->GetFunction(0x827BD9D4);
    dispatcher->SetFunction(0x827BD9D4, hk_NtQueryInformationFile);
    if (!g_original_NtQueryInformationFile) {
      MCLA_LOG_ERROR("NtQueryInformationFile original not found in dispatch table");
    }

    g_original_NtClose = dispatcher->GetFunction(0x827BCEB4);
    dispatcher->SetFunction(0x827BCEB4, hk_NtClose);
    if (!g_original_NtClose) {
      MCLA_LOG_ERROR("NtClose original not found in dispatch table");
    }
  }

  if (BisectGroupEnabled("in")) {
    dispatcher->SetFunction(0x827BDC64, hk_XamInputGetState);

    auto *ks = mcla::GetApp();
    if (ks) {
      g_virtual_membase = ks->GetPPCBase();
    }

    // DetourImportThunk for hotpatch thunk analysis (x86 pointer, not PPC)
    g_original_XamInputGetState = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(
            reinterpret_cast<void *>(&__imp__XamInputGetState)),
        hk_XamInputGetState);
    if (!g_original_XamInputGetState) {
      MCLA_LOG_WARN("XamInputGetState thunk detour failed (hotpatch analysis skipped, hook still active)");
    } else {
      uint8_t *hotpatch_thunk = (uint8_t *)g_original_XamInputGetState;
      if (hotpatch_thunk[0] == 0xE9) {
        int32_t rel = *reinterpret_cast<int32_t *>(hotpatch_thunk + 1);
        g_native_XamInputGetState_func = (void *)(hotpatch_thunk + 5 + rel);
        MCLA_LOG_INFO("XamInputGetState hotpatch thunk at 0x{:p} -> actual "
                      "func at 0x{:p}",
                      (void *)hotpatch_thunk, g_native_XamInputGetState_func);

        uint8_t *af = (uint8_t *)g_native_XamInputGetState_func;
        MCLA_LOG_INFO(
            "Actual func first 128 bytes: "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
            "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X}",
            af[0], af[1], af[2], af[3], af[4], af[5], af[6], af[7], af[8],
            af[9], af[10], af[11], af[12], af[13], af[14], af[15], af[16],
            af[17], af[18], af[19], af[20], af[21], af[22], af[23], af[24],
            af[25], af[26], af[27], af[28], af[29], af[30], af[31], af[32],
            af[33], af[34], af[35], af[36], af[37], af[38], af[39], af[40],
            af[41], af[42], af[43], af[44], af[45], af[46], af[47], af[48],
            af[49], af[50], af[51], af[52], af[53], af[54], af[55], af[56],
            af[57], af[58], af[59], af[60], af[61], af[62], af[63], af[64],
            af[65], af[66], af[67], af[68], af[69], af[70], af[71], af[72],
            af[73], af[74], af[75], af[76], af[77], af[78], af[79], af[80],
            af[81], af[82], af[83], af[84], af[85], af[86], af[87], af[88],
            af[89], af[90], af[91], af[92], af[93], af[94], af[95], af[96],
            af[97], af[98], af[99], af[100], af[101], af[102], af[103], af[104],
            af[105], af[106], af[107], af[108], af[109], af[110], af[111],
            af[112], af[113], af[114], af[115], af[116], af[117], af[118],
            af[119], af[120], af[121], af[122], af[123], af[124], af[125],
            af[126], af[127]);

        if (g_native_XamInputGetState_func) {
          uint8_t *wrap = (uint8_t *)g_native_XamInputGetState_func;
          int32_t rel = *reinterpret_cast<int32_t *>(wrap + 70);
          void *real_func = wrap + 74 + rel;
          MCLA_LOG_INFO(
              "Translation wrapper calls real XamInputGetState at 0x{:p}",
              real_func);

          uint8_t *rf = (uint8_t *)real_func;
          MCLA_LOG_INFO(
              "Real XamInputGetState func first 16 bytes: "
              "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
              "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X}",
              rf[0], rf[1], rf[2], rf[3], rf[4], rf[5], rf[6], rf[7], rf[8],
              rf[9], rf[10], rf[11], rf[12], rf[13], rf[14], rf[15]);

          MCLA_LOG_INFO("Installing native XamInputGetState detour on REAL "
                        "func at 0x{:p} ...",
                        real_func);
          if (InstallNativeDetour(real_func, (void *)hk_native_XamInputGetState,
                                  g_original_native_bytes, 12)) {
            MCLA_LOG_INFO("Native XamInputGetState (real func) detour "
                          "installed successfully");
          } else {
            MCLA_LOG_ERROR("Failed to install native XamInputGetState detour "
                           "on real func");
          }
        } else {
          MCLA_LOG_WARN("XamInputGetState target does NOT start with E9 (jmp). "
                        "Using thunk address directly.");
          g_native_XamInputGetState_func = (void *)hotpatch_thunk;
        }
      }
    }

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

    // Device-boundary draw capture (sub_82413660) is owned by the
    // global-scope PPC_FUNC override in src/gpu_device.cpp (P5'/B8) — the
    // dispatcher map is not consulted for guest calls, so registering here
    // would be dead code.

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
    // block (dead: dispatcher-map SetFunction is never consulted for guest
    // calls) and the g_fast_pool_alloc / g_debug_alloc_caller resolution that
    // only served it. See the note near the removed statics above.

    g_orig_sub_82554E20 = dispatcher->GetFunction(0x82554E20);
    if (g_orig_sub_82554E20) {
      dispatcher->SetFunction(0x82554E20, hk_sub_82554E20);
      MCLA_LOG_INFO("Screen manager (sub_82554E20) hooked");
    } else {
      MCLA_LOG_ERROR("sub_82554E20 not found in dispatcher");
    }

    // Worker entry census (sub_824569C8) — TU83 driver worker
    dispatcher->SetFunction(0x824569C8, sub_824569C8); // ensure registered
    g_orig_sub_824569C8 = dispatcher->GetFunction(0x824569C8);
    if (g_orig_sub_824569C8) {
      dispatcher->SetFunction(0x824569C8, hk_sub_824569C8);
      MCLA_LOG_INFO("Worker entry sub_824569C8 hooked for census");
    } else {
      MCLA_LOG_ERROR("sub_824569C8 not found in dispatcher");
    }

    if (g_virtual_membase) {
      uint32_t cb2 = *(uint32_t *)(g_virtual_membase + 0x828DA3C4);
      MCLA_LOG_INFO("sub_82554590 callback at 0x828DA3C4 = 0x{:08X}", cb2);
    }

  } // end BisectGroupEnabled("gp")

  if (mode != "compat" && !BisectGroupEnabled("native")) {
    g_orig_VdSwap_observer = dispatcher->GetFunction(0x827BD6E4);
    dispatcher->SetFunction(0x827BD6E4, hk_vdswap_observer);
    if (g_orig_VdSwap_observer) {
      MCLA_LOG_INFO("VdSwap observer installed (passthrough, legacy mode)");
    } else {
      MCLA_LOG_ERROR("VdSwap observer: original not found in dispatch table");
    }

    // Detour VdInitializeEngines to call the recompiled implementation
    g_orig_VdInitializeEngines = dispatcher->GetFunction(0x827BD574);
    dispatcher->SetFunction(0x827BD574, hk_VdInitializeEngines);
    if (g_orig_VdInitializeEngines) {
      MCLA_LOG_INFO(
          "VdInitializeEngines detour installed (calls recompiled impl)");
    } else {
      MCLA_LOG_ERROR("VdInitializeEngines original not found in dispatch table");
    }
  }

  MCLA_LOG_INFO("MCLA patches applied (1 entry + 5 GPU hooks + 5 timer hooks + "
                "native renderer + screen hooks)");

  // Signal the GPU init semaphore (0x40004D7C) after 3 seconds to unblock loading screen
  std::thread([ ] {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    void *sem_host = mem.Translate(0x40004D7C);
    if (sem_host) {
      KeReleaseSemaphore(sem_host, 1, 1, 0);
      MCLA_LOG_WARN("Signaled GPU init semaphore 0x40004D7C via KeReleaseSemaphore");
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

PPC_FUNC_IMPL(hk_KeWaitForSingleObject) {
  static bool firstCall = true;
  if (firstCall) {
    firstCall = false;
    MCLA_LOG_WARN("KeWait FIRST CALL: obj=0x{:08X} (tid={})", ctx.r3.u32,
                  GetCurrentThreadId());
  }

  static constexpr uint32_t kDisplaySyncSem = 0x828CD9AC;
  static constexpr uint32_t kSchedulerTick = 0x40004D7C;

  static int waitCount = 0;
  waitCount++;

  if (ctx.r3.u32 == kDisplaySyncSem || ctx.r3.u32 == kSchedulerTick) {
    if (waitCount <= 5) {
      MCLA_LOG_WARN("KeWait[{}] SEM 0x{:08X} -> SKIPPED (return 0)",
                    waitCount, ctx.r3.u32);
    }
    ctx.r3.u64 = 0;
    return;
  }

  if (waitCount <= 200) {
    MCLA_LOG_INFO("KeWait[{}] obj=0x{:08X} -> chaining to original", waitCount,
                  ctx.r3.u32);
  }

  if (g_original_KeWait) {
    g_original_KeWait(ctx, base);
  }
}

PPC_FUNC_IMPL(hk_XamInputGetState) {
  static int callCount = 0;
  callCount++;

  uint32_t port = ctx.r3.u32;
  uint32_t buf = ctx.r5.u32;

  if (callCount <= 100 || (callCount % 1000) == 0) {
    MCLA_LOG_INFO("XamInputGetState[{}]: port={} buf=0x{:08X} held={} lr={:08X}",
                  callCount, port, buf, StartPulseActive(),
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  if (buf >= 0x10000000) {
    if (StartPulseActive()) {
      PPC_STORE_U16(buf + 4, 0x0010);
    } else {
      PPC_STORE_U16(buf + 4, 0x0000);
    }
    if (callCount <= 50 || (callCount % 1000) == 0) {
      MCLA_LOG_INFO("XamInputGetState[{}]: Start held={} buf=0x{:08X}",
                    callCount, StartPulseActive(), buf);
    }
  }

  ctx.r3.u64 = 0;
}

PPC_FUNC_IMPL(hk_NtCreateFile) {
  uint32_t oa = ctx.r3.u32;
  mcla::native::GuestMemoryView view;
  uint32_t status = 0;
  if (mcla::vfs::hooks::NtCreateFileHook(oa, view, status)) {
    ctx.r3.u32 = status;
    return;
  }
  if (g_original_NtCreateFile)
    g_original_NtCreateFile(ctx, base);
}

PPC_FUNC_IMPL(hk_NtReadFile) {
  uint32_t file_handle = ctx.r3.u32;
  uint32_t io_status = ctx.r7.u32;
  uint32_t buffer = ctx.r8.u32;
  uint32_t length = ctx.r9.u32;
  uint32_t bytes_read = 0;
  if (mcla::vfs::hooks::NtReadFileHook(file_handle, buffer, length,
                                       bytes_read)) {
    ctx.r3.u32 = 0;
    if (io_status)
      mcla::native::WriteGuestU32(io_status, bytes_read);
    return;
  }
  if (g_original_NtReadFile)
    g_original_NtReadFile(ctx, base);
}

PPC_FUNC_IMPL(hk_NtQueryInformationFile) {
  uint32_t file_handle = ctx.r3.u32;
  uint32_t io_status = ctx.r4.u32;
  uint32_t buffer = ctx.r5.u32;
  uint32_t length = ctx.r6.u32;
  uint32_t info_class = ctx.r7.u32;
  if (mcla::vfs::hooks::NtQueryInformationFileHook(file_handle, buffer, length,
                                                   info_class)) {
    ctx.r3.u32 = 0;
    return;
  }
  if (g_original_NtQueryInformationFile)
    g_original_NtQueryInformationFile(ctx, base);
}

PPC_FUNC_IMPL(hk_NtClose) {
  uint32_t file_handle = ctx.r3.u32;
  if (mcla::vfs::hooks::NtCloseHook(file_handle)) {
    ctx.r3.u32 = 0;
    return;
  }
  if (g_original_NtClose)
    g_original_NtClose(ctx, base);
}

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
// The authoritative decode lives in .clinerules/memory/ and
// docs/BOOT_HANDOFF.md.

// MASTER SWITCH: disable all census overhead (slab walks, file I/O,
// snapshot scans, per-alloc logging).  All corruption detections were false
// positives (Session 56).  Set to true to re-enable diagnostics.

PPC_FUNC_IMPL(hk_sub_824569C8) {
  if constexpr (!kPool16CensusEnabled) {
    if (g_orig_sub_824569C8)
      g_orig_sub_824569C8(ctx, base);
    return;
  }
  MCLA_LOG_WARN("WORKER-ENTRY sub_824569C8 called: r3={:08X} r4={:08X} "
                "r5={:08X} r13={:08X} lr={:08X}",
                ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r13.u32,
                static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  if (g_orig_sub_824569C8)
    g_orig_sub_824569C8(ctx, base);
}

// hk_sub_82413660 removed (P5'/B8): never registered (dispatcher map is not
// consulted for guest calls), and duplicated the live global-scope override
// PPC_FUNC(sub_82413660) in src/gpu_device.cpp, which remains diagnostic-only;
// native geometry submission is owned by sub_82420BA8.

PPC_FUNC_IMPL(hk_sub_82411840) {
  // Device-boundary draw consumer hook - native path
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
// handler-dispatch case (opcode 0x2D at 0x82555C24) in place of the
// original XAM handler. The screen object is read from the guest global
// that sub_82554E20 persists (0x828DA3BC, Ghidra-validated); the
// completion reason is the interpreter's own value 0x828110D4
// (0x82017D0C is absent from the binary). r31 is a generated-function
// local under this ABI, so it must not be read here.
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

PPC_FUNC_IMPL(sub_82554080_stub) {
  static int count = 0;
  count++;
  g_press_start_bypassed = true;

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

