#include "patches.h"
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
#include "vfs_rpf.h"

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
extern "C" void hk_sub_82413660(mcla::native::PPCContext &ctx, uint8_t *base);
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

  if (BisectGroupEnabled("ke")) {
    dispatcher->SetFunction(0x827BD5A4, hk_KeWaitForSingleObject);
    g_original_KeWait = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(
            reinterpret_cast<void *>(&__imp__KeWaitForSingleObject)),
        hk_KeWaitForSingleObject);
    if (!g_original_KeWait) {
      MCLA_LOG_ERROR("Failed to detour __imp__KeWaitForSingleObject");
    }
  }

  if (BisectGroupEnabled("fs")) {
    dispatcher->SetFunction(0x827BD934, hk_NtCreateFile);
    g_original_NtCreateFile = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(
            reinterpret_cast<void *>(&__imp__NtCreateFile)),
        hk_NtCreateFile);
    if (!g_original_NtCreateFile) {
      MCLA_LOG_ERROR("Failed to detour __imp__NtCreateFile");
    }

    dispatcher->SetFunction(0x827BD914, hk_NtReadFile);
    g_original_NtReadFile = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(
            reinterpret_cast<void *>(&__imp__NtReadFile)),
        hk_NtReadFile);
    if (!g_original_NtReadFile) {
      MCLA_LOG_ERROR("Failed to detour __imp__NtReadFile");
    }

    dispatcher->SetFunction(0x827BD9D4, hk_NtQueryInformationFile);
    g_original_NtQueryInformationFile = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(
            reinterpret_cast<void *>(&__imp__NtQueryInformationFile)),
        hk_NtQueryInformationFile);
    if (!g_original_NtQueryInformationFile) {
      MCLA_LOG_ERROR("Failed to detour __imp__NtQueryInformationFile");
    }

    dispatcher->SetFunction(0x827BCEB4, hk_NtClose);
    g_original_NtClose = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(reinterpret_cast<void *>(&__imp__NtClose)),
        hk_NtClose);
    if (!g_original_NtClose) {
      MCLA_LOG_ERROR("Failed to detour __imp__NtClose");
    }
  }

  if (BisectGroupEnabled("in")) {
    dispatcher->SetFunction(0x827BDC64, hk_XamInputGetState);
    g_original_XamInputGetState = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(
            reinterpret_cast<void *>(&__imp__XamInputGetState)),
        hk_XamInputGetState);
    if (!g_original_XamInputGetState) {
      MCLA_LOG_ERROR("Failed to detour __imp__XamInputGetState");
    } else {
      auto *ks = mcla::GetApp();
      if (ks) {
        g_virtual_membase = ks->GetPPCBase();
      }

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

    if (BisectGroupEnabled("gp")) {
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
    // DISABLED for bisection: mcla::native::g_renderThread.start();
    // MCLA_LOG_ERROR("mcla_ApplyPatches: Render thread started (P4.5')");

    // Device-boundary hooks for native draw path (sub_82413660, sub_82411840)
    // DISABLED for bisection:
    // if (BisectGroupEnabled("gp")) {
    //     dispatcher->SetFunction(0x82413660, hk_sub_82413660);
    //     MCLA_LOG_INFO("Device-boundary hook: sub_82413660 (draw submit)
    //     hooked"); dispatcher->SetFunction(0x82411840, hk_sub_82411840);
    //     MCLA_LOG_INFO("Device-boundary hook: sub_82411840 (draw consumer)
    //     hooked");
    // }

    if (BisectGroupEnabled("gp")) {
      dispatcher->SetFunction(0x82130690, hk_sub_82130690);
      dispatcher->SetFunction(0x82130770, hk_sub_82130770);
      dispatcher->SetFunction(0x82130850, hk_sub_82130850);
      dispatcher->SetFunction(0x82130930, hk_sub_82130930);
      dispatcher->SetFunction(0x82130A18, hk_sub_82130A18);
    }

    if (BisectGroupEnabled("ps")) {
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
    dispatcher->SetFunction(0x827BD6E4, hk_vdswap_observer);
    g_orig_VdSwap_observer = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(reinterpret_cast<void *>(&__imp__VdSwap)),
        hk_vdswap_observer);
    if (g_orig_VdSwap_observer) {
      MCLA_LOG_INFO("VdSwap observer installed (passthrough, legacy mode)");
    } else {
      MCLA_LOG_ERROR("VdSwap observer: thunk detour FAILED");
    }

    // Detour VdInitializeEngines to call the recompiled implementation
    dispatcher->SetFunction(0x827BD574, hk_VdInitializeEngines);
    g_orig_VdInitializeEngines = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t *>(
            reinterpret_cast<void *>(&__imp__VdInitializeEngines)),
        hk_VdInitializeEngines);
    if (g_orig_VdInitializeEngines) {
      MCLA_LOG_INFO(
          "VdInitializeEngines detour installed (calls recompiled impl)");
    } else {
      MCLA_LOG_ERROR("VdInitializeEngines detour: thunk detour FAILED");
    }
  }

  MCLA_LOG_INFO("MCLA patches applied (1 entry + 5 GPU hooks + 5 timer hooks + "
                "native renderer + screen hooks)");
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

  if (ctx.r3.u32 == kDisplaySyncSem) {
    if (waitCount <= 5) {
      MCLA_LOG_INFO("KeWait[{}] DISPLAY-SYNC SEM 0x{:08X} -> SKIPPED",
                    waitCount, ctx.r3.u32);
    }
    ctx.r3.u64 = 0;
    return;
  }

  if (ctx.r3.u32 != kSchedulerTick && waitCount <= 200) {
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

  if (callCount <= 10) {
    MCLA_LOG_INFO("XamInputGetState[{}]: port={} buf=0x{:08X} held={}",
                  callCount, port, buf, StartPulseActive());
  }

  if (buf >= 0x10000000) {
    if (StartPulseActive()) {
      PPC_STORE_U16(buf + 4, 0x0010);
    } else {
      PPC_STORE_U16(buf + 4, 0x0000);
    }
    if (callCount <= 5) {
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
  void *buffer = reinterpret_cast<void *>(ctx.r4.u32);
  uint32_t length = ctx.r5.u32;
  uint32_t bytes_read = 0;
  if (mcla::vfs::hooks::NtReadFileHook(file_handle, buffer, length,
                                       bytes_read)) {
    ctx.r3.u32 = 0;
    ctx.r4.u32 = bytes_read;
    return;
  }
  if (g_original_NtReadFile)
    g_original_NtReadFile(ctx, base);
}

PPC_FUNC_IMPL(hk_NtQueryInformationFile) {
  uint32_t file_handle = ctx.r3.u32;
  void *buffer = reinterpret_cast<void *>(ctx.r4.u32);
  uint32_t length = ctx.r5.u32;
  uint32_t info_class = ctx.r6.u32;
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
  if (g_orig_sub_82554E20)
    g_orig_sub_82554E20(ctx, base);
}

// SESSION 36: PPC_FUNC_IMPL(hk_sub_821C29A0) removed - dead code with a
// latent fatal-raise landmine (called sub_821BD618, the guest OOM fatal
// dispatcher, directly with (fmt, pool, size) args on its fallback path).
// The authoritative decode lives in .clinerules/memory/ and
// docs/BOOT_HANDOFF.md.

PPC_FUNC_IMPL(hk_sub_824569C8) {
  MCLA_LOG_WARN("WORKER-ENTRY sub_824569C8 called: r3={:08X} r4={:08X} "
                "r5={:08X} r13={:08X} lr={:08X}",
                ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r13.u32,
                static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  if (g_orig_sub_824569C8)
    g_orig_sub_824569C8(ctx, base);
}

PPC_FUNC_IMPL(hk_sub_82413660) {
  // Device-boundary draw submit hook - native path
  const uint32_t n = 0;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t r4 = ctx.r4.u32;
  const uint32_t r5 = ctx.r5.u32; // VB desc
  const uint32_t r6 = ctx.r6.u32; // IB desc

  // Get the captured draw data
  const mcla::gpu::CapturedDrawV2 *draw = mcla::gpu::mcla_gpu_GetLastDrawV2();
  uint32_t frameId = mcla::gpu::mcla_gpu_GetFrameCounter();

  if (draw && (draw->frameId == frameId || frameId == 0)) {
    // Native path: enqueue draw command to render thread
    MCLA_LOG_INFO("NATIVE DRAW: sub_82413660 #{} dev={:08X} r4={:08X} "
                  "r5={:08X} r6={:08X} "
                  "vb=0x{:08X}/{:08X}/{:08X} ib=0x{:08X}/{:08X}/{:08X}",
                  n, dev, r4, r5, r6, draw->vbBase, draw->vbStride,
                  draw->vbSize, draw->ibBase, draw->ibSize, draw->ibFmt);

    // Enqueue draw command to render thread
    mcla::native::RenderCommand cmd;
    cmd.type = mcla::native::RenderCommand::DRAW_CAPTURED;
    cmd.data = mcla::native::DrawCapturedCommand{
      draw->vbBase,
      draw->vbSize,
      draw->vbStride,
      draw->ibBase,
      draw->ibSize,
      draw->frameId,
      0,
    };

    mcla::native::g_commandQueue.push(cmd);
    MCLA_LOG_INFO("Enqueued DrawCaptured to command queue (queue size: {})",
                  mcla::native::g_commandQueue.size());
  }

  // Chain to original for legacy path
  __imp__sub_82413660(ctx, base);
}

PPC_FUNC_IMPL(hk_sub_82411840) {
  // Device-boundary draw consumer hook - native path
  const uint32_t n = 0;
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

// ---------------------------------------------------------------------------
// SESSION 34 (2026-08-30): OOM-frontier census - CENSUS ONLY, passthrough.
//
// Evidence base (ledger session 33): boot fatal is the guest's own RAGE OOM
// (sub_821BD618 dispatcher, fmt 0x82011F78) raised from sub_821C29A0 at guest
// lr=0x821C2A7C when its heap's free-list walk (sub_821C1BB0, 16 size-class
// buckets, NO grow path - loc_821C1D28 returns 0 outright) finds nothing.
// Heap accounting fields (validated by the sub_821C22D0 walk invariant
// [r+84]+[r+152]==[r+76]): +76=capacity, +84=free, +152=used counter.
// sub_82130B50(r3=size, r4=flags/alignment-code) is the game's physical
// memory allocation wrapper (sole caller 158.cpp:27532) - census proves
// whether the game ever attempts physical growth before the fatal.
//
// Golden rules honored: passthrough only (zero behavior change), checked
// BE reads via GuestMemoryHeap, one hook owner per address (verified: no
// prior overrides of either address in src/), no D3D12, no seeding.
// ---------------------------------------------------------------------------
#include "kernel/memory.h"
#include <atomic>

namespace {
std::atomic<uint32_t> s_oomAllocCensus{0};
std::atomic<uint32_t> s_physAllocCensus{0};
// SESSION 37: entry-time fast-path capture counters (see
// PPC_FUNC(sub_821C29A0)).
std::atomic<uint32_t> s_fastPathCensus{0};
std::atomic<uint32_t> s_zeroSizeLogged{0};

// Checked heap-field read: returns 0 when the guest address is not backed.
uint32_t OomCensusReadU32(uint32_t addr, bool *ok = nullptr) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t val = 0;
  const bool read = mem.IsValid(addr, 4) && mem.ReadU32BE(addr, &val);
  if (ok)
    *ok = read;
  return val;
}

bool RepairCorruptedTinySlabFreeList(uint32_t classHead) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t headWord = OomCensusReadU32(classHead + 4);
  const uint32_t elemsize = headWord >> 16;
  const uint32_t nodesPerSlab = headWord & 0xFFFFu;
  if (elemsize == 0 || elemsize > 64 || nodesPerSlab == 0 ||
      nodesPerSlab > 4096) {
    return false;
  }

  bool repaired = false;
  const uint32_t slabDataStart = 32u;
  const uint32_t slabDataSpan = nodesPerSlab * elemsize;
  uint32_t curSlab = OomCensusReadU32(classHead + 0);
  while (curSlab != 0) {
    const uint32_t count = OomCensusReadU32(curSlab + 8);
    const uint32_t freeHead = OomCensusReadU32(curSlab + 12);
    bool broken = (count > 0 && freeHead == 0);
    if (!broken && count > 0 && freeHead != 0) {
      const uint32_t headNext = OomCensusReadU32(freeHead + 0);
      broken = (headNext != 0 &&
                (headNext < curSlab + slabDataStart ||
                 headNext >= curSlab + slabDataStart + slabDataSpan));
    }

    if (broken) {
      uint32_t newHead = 0;
      uint32_t newCount = 0;
      bool foundAny = false;

      for (uint32_t i = 0; i < nodesPerSlab; ++i) {
        const uint32_t elemAddr = curSlab + slabDataStart + (i * elemsize);
        bool looksFree = true;
        for (uint32_t b = 4; b < elemsize; b += 4) {
          if (OomCensusReadU32(elemAddr + b) != 0xDDDDDDDDu) {
            looksFree = false;
            break;
          }
        }
        if (looksFree) {
          (void)mem.WriteU32BE(elemAddr + 0, newHead);
          newHead = elemAddr;
          ++newCount;
          foundAny = true;
        }
      }

      if (!foundAny) {
        (void)mem.WriteU32BE(curSlab + 12, 0);
        (void)mem.WriteU32BE(curSlab + 8, 0);
      } else {
        (void)mem.WriteU32BE(curSlab + 12, newHead);
        (void)mem.WriteU32BE(curSlab + 8, newCount);
      }

      MCLA_LOG_WARN("POOL-FREELIST-REPAIRED classHead={:08X} slab={:08X} "
                    "elemsize={} cap={} oldCount={} newCount={} newHead={:08X} "
                    "freeHeadWas={:08X}",
                    classHead, curSlab, elemsize, nodesPerSlab, count,
                    foundAny ? newCount : 0, foundAny ? newHead : 0, freeHead);
      repaired = true;
    }
    curSlab = OomCensusReadU32(curSlab + 4);
  }
  return repaired;
}
} // namespace

PPC_FUNC_IMPL(__imp__sub_821C29A0);
PPC_FUNC(sub_821C29A0) {
  const uint32_t n = s_oomAllocCensus.fetch_add(1) + 1;

  // SESSION 47/49: capture entry state for failure diagnosis
  const uint32_t self = ctx.r3.u32;
  const uint32_t sizeEntry = ctx.r4.u32;
  const uint32_t alignEntry = ctx.r5.u32;
  const uint32_t callerLr = static_cast<uint32_t>(ctx.lr);

  // Pre-call heap state (for comparison with post-call)
  const uint32_t preCap = OomCensusReadU32(self + 76);
  const uint32_t preCarved = OomCensusReadU32(self + 84);
  const uint32_t preFree = OomCensusReadU32(self + 152);

  // SESSION 39 FIX: handle zero-size allocations (legitimate degenerate
  // requests from the game). Standard allocator semantics: malloc(0) returns
  // a valid minimum-size allocation. Session-37 used size=4 (elemsize==4
  // class), but the game's own zero-size free path writes directly to the
  // elemsize==4 slab header — bypassing DE908 — corrupting the freelist.
  // Fix: route to the size class matching the requested alignment instead,
  // avoiding the elemsize==4 slab entirely. When align=0, fall back to 16.
  uint32_t effectiveSize = sizeEntry;
  if (effectiveSize == 0) {
    effectiveSize = (alignEntry > 0) ? alignEntry : 16;
    ctx.r4.u32 = effectiveSize; // pass corrected size to original
  }

  __imp__sub_821C29A0(ctx, base);

  // Post-call: check for failure (return value == 0)
  const uint32_t ret = ctx.r3.u32;
  if (ret == 0) {
    static std::atomic<uint32_t> s_heapOomCount{0};
    const uint32_t oomIdx = s_heapOomCount.fetch_add(1) + 1;
    const uint32_t postCap = OomCensusReadU32(self + 76);
    const uint32_t postCarved = OomCensusReadU32(self + 84);
    const uint32_t postFree = OomCensusReadU32(self + 152);
    const uint32_t flagsWord = OomCensusReadU32(self + 196);

    // Walk bucket 15 (head = heap+72): blocks >=240 bytes
    uint32_t b15Count = 0, b15Sum = 0;
    {
      uint32_t cur = OomCensusReadU32(self + 72);
      uint32_t walked = 0;
      while (cur != 0 && walked < 4096) {
        ++b15Count;
        uint32_t blkSize = OomCensusReadU32(cur + 4);
        b15Sum += blkSize;
        cur = OomCensusReadU32(cur + 20);
        ++walked;
      }
    }

    MCLA_LOG_WARN(
        "HEAP-OOM #{} heap={:08X} reqSize={:08X} align={:08X} lr={:08X} | "
        "pre: cap={:08X} carved={:08X} free={:08X} | "
        "post: cap={:08X} carved={:08X} free={:08X} | "
        "b15: count={} sum={:08X} flags={:02X}",
        oomIdx, self, sizeEntry, alignEntry, callerLr, preCap, preCarved,
        preFree, postCap, postCarved, postFree, b15Count, b15Sum,
        (flagsWord & 0xFFu));
  }

  // Periodic census (first 32 + every 2000th)
  if (n <= 32 || n % 2000 == 0) {
    const uint32_t cap = OomCensusReadU32(self + 76);
    const uint32_t freeB = OomCensusReadU32(self + 84);
    const uint32_t used = OomCensusReadU32(self + 152);
    const uint32_t flagsWord2 = OomCensusReadU32(self + 196);
    MCLA_LOG_WARN("OOM-CENSUS #{} self={:08X} req(r4)={:08X} r5={:08X} "
                  "cap={:08X} free={:08X} "
                  "used={:08X} flags199={:02X} lr={:08X} ret={:08X}",
                  n, self, sizeEntry, alignEntry, cap, freeB, used,
                  (flagsWord2 & 0xFFu), callerLr, ret);
  }
}

PPC_FUNC_IMPL(__imp__sub_82130B50);
PPC_FUNC(sub_82130B50) {
  const uint32_t n = s_physAllocCensus.fetch_add(1) + 1;
  const uint32_t sizeArg = ctx.r3.u32;
  const uint32_t flagsArg = ctx.r4.u32;
  __imp__sub_82130B50(ctx, base);
  if (n <= 32 || n % 500 == 0) {
    MCLA_LOG_WARN(
        "PHYSALLOC-CENSUS #{} size={:08X} flags={:08X} -> ret={:08X} lr={:08X}",
        n, sizeArg, flagsArg, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  }
}

// ---------------------------------------------------------------------------
// SESSION 36 (2026-08-31): refill-failure census on the arena free-list
// allocator sub_821C1BB0(heap, size, align) - CENSUS ONLY, passthrough.
//
// Evidence base (session 36 static decode + soak35 live data):
// - sub_821C29A0(heap, size, align): size<=64 && align<=16 -> tiny size-class
//   pools (heads at heap+208..240). Empty class -> sub_821DE9D8 refill:
//   sub_821C1BB0(heap, 16320, 16384) i.e. a 16 KiB-ALIGNED 16320-byte slab.
//   Refill fail -> guest OOM fatal ("Not enough memory to allocate %u bytes
//   (%u available)") prints size and heap[+152] as "available".
// - soak35 live census proves the field map: +76=capacity (0x02E7FFF0),
//   +84=carved-from-arena, +152=free/unallocated (they satisfy
//   +84 + +152 == +76 and start at 16 / cap-16 on a fresh heap). At the
//   session-35 fatal: carved ~1.87 MiB, "available" 0x02CB4F00 = 44.7 MiB
//   -> the heap was NOT exhausted; the "44.8MB request" was a misread of the
//   available field. The request was <=16 bytes.
// - sub_821C1BB0 has NO grow path (failure loc 0x821C1D28 just returns 0);
//   it serves allocations only from the 16 free-bucket chains (heads at
//   heap+12..heap+72). Bucket 15 holds every free block >=240 bytes.
// - Open question this census answers with live data: at refill failure, is
//   bucket 15 fragmented into sub-16 KiB blocks (legitimate fragmentation) or
//   is the chain empty/short while +152 still reports megabytes (accounting
//   desync)? Block layout: +0 self-magic, +4 size, +20 next-in-bucket.
// Golden rules: passthrough only (r3 flows through), checked BE reads via
// GuestMemoryHeap, one hook owner per address (no prior override of
// 0x821C1BB0 in src/), no D3D12, no seeding, no invented behavior.
// ---------------------------------------------------------------------------
namespace {
std::atomic<uint32_t> s_arenaCensus{0};
std::atomic<uint32_t> s_arenaFailures{0};
// SESSION 37: refill-depth marker so sub_821DE9D8's census can tell a
// return-0 that went through the sub_821C1BB0 refill from one that did not
// (the no-refill pop-path return-0 is the session-36 prime suspect).
thread_local uint32_t t_arenaDepth = 0;
} // namespace

PPC_FUNC_IMPL(__imp__sub_821C1BB0);
PPC_FUNC(sub_821C1BB0) {
  const uint32_t heap = ctx.r3.u32;
  const uint32_t sizeArg = ctx.r4.u32;
  const uint32_t alignArg = ctx.r5.u32;

  ++t_arenaDepth;
  __imp__sub_821C1BB0(ctx, base);
  --t_arenaDepth;

  const uint32_t n = s_arenaCensus.fetch_add(1) + 1;
  const bool failed = (ctx.r3.u32 == 0);
  uint32_t failIdx = 0;
  if (failed) {
    failIdx = s_arenaFailures.fetch_add(1) + 1;
  }

  const bool periodic = (n <= 8 || n % 65536 == 0);
  const bool logFailure = failed && (failIdx <= 200 || failIdx % 50 == 0);
  if (!periodic && !logFailure) {
    return;
  }

  // Walk bucket 15 (head = heap+72): blocks >=240 bytes live here, and the
  // 16 KiB slab refill searches exactly this chain. Cycle-capped.
  uint32_t walked = 0;
  uint32_t sum = 0;
  uint32_t head = OomCensusReadU32(heap + 72);
  uint32_t cur = head;
  uint32_t firstAddr[6] = {0, 0, 0, 0, 0, 0};
  uint32_t firstSize[6] = {0, 0, 0, 0, 0, 0};
  while (cur != 0 && walked < 4096) {
    bool okSize = false;
    bool okNext = false;
    const uint32_t blkSize = OomCensusReadU32(cur + 4, &okSize);
    const uint32_t next = OomCensusReadU32(cur + 20, &okNext);
    if (!okSize) {
      head |= 1u; // flag: unreadable chain node
      break;
    }
    if (walked < 6) {
      firstAddr[walked] = cur;
      firstSize[walked] = blkSize;
    }
    sum += blkSize;
    ++walked;
    if (!okNext) {
      head |= 2u; // flag: unreadable next link
      break;
    }
    cur = next;
  }

  MCLA_LOG_WARN(
      "ARENA-CENSUS #{} {} heap={:08X} size={:08X} align={:08X} -> ret={:08X} "
      "cap(+76)={:08X} carved(+84)={:08X} free(+152)={:08X} b15head={:08X} "
      "walked={} walkedsum={:08X} lr={:08X} blocks=[{:08X}/{:08X} "
      "{:08X}/{:08X} "
      "{:08X}/{:08X} {:08X}/{:08X} {:08X}/{:08X} {:08X}/{:08X}]",
      n, failed ? "FAIL" : "OK  ", heap, sizeArg, alignArg, ctx.r3.u32,
      OomCensusReadU32(heap + 76), OomCensusReadU32(heap + 84),
      OomCensusReadU32(heap + 152), head, walked, sum,
      static_cast<uint32_t>(ctx.lr), firstAddr[0], firstSize[0], firstAddr[1],
      firstSize[1], firstAddr[2], firstSize[2], firstAddr[3], firstSize[3],
      firstAddr[4], firstSize[4], firstAddr[5], firstSize[5]);
}

// ---------------------------------------------------------------------------
// SESSION 37 STEP 2 (2026-08-31): tiny-class slab allocator census on
// sub_821DE9D8(classHead, heap) - CENSUS ONLY, passthrough.
//
// Static decode (generated/ppc_xenon ppc_recomp.20.cpp:15810-16001):
// - slab list: head+0 = first (newest) slab; slab links: +0 = newer,
//   +4 = older (pop walk follows +4); head+4 u16 elemsize, head+6 u16
//   nodes-per-slab.
// - slab layout: +0 next-newer, +4 prev-older, +8 count (available),
//   +12 freelist head, +16 owner class head.
// - pop path (loc 0x821DEA6C): node = [slab+12]; count--; [slab+12]=[node];
//   returns node. It is entered whenever signed count([slab+8]) != 0.
//   => returns 0 WITHOUT any refill iff a slab has count != 0 but
//      freelist([slab+12]) == 0 (session-36 prime suspect).
// - refill path (loc 0x821DEA18): sub_821C1BB0(heap, 16320, 16384);
//   result==0 -> allocator returns 0 (refill failure, already censused
//   by ARENA-CENSUS and observed to never fire).
// This census flags every return-0, labels it NOREFILL vs REFILLFAIL via the
// t_arenaDepth marker set by the sub_821C1BB0 override, and dumps the class
// head + slab chain + real freelist chain length so count/freelist desync is
// visible live. Passthrough only; checked BE reads; no behavior change.
// ---------------------------------------------------------------------------
namespace {
std::atomic<uint32_t> s_poolCensus{0};
std::atomic<uint32_t> s_poolFailures{0};
std::atomic<uint32_t> s_poolPops{0};
std::atomic<uint32_t> s_allocCensus{0};

// Forward declaration — defined after the census wrappers (session 26
// write-watch)
static void Arm16BytePoolPayloadWatch(uint32_t slab, uint32_t elemsize,
                                      uint32_t nodesPerSlab);

// ---------------------------------------------------------------------------
// SESSION 55 (B3): Writer-attribution census for the 16-byte pool overflow.
// Root cause: game writes >16 bytes to 16-byte pool allocations, corrupting
// adjacent elements. Strategy:
//   1. Snapshot every allocation (element addr, first 8 bytes, caller LR)
//   2. Periodically scan all slabs to detect corruption on live elements
//   3. At free time, compare element against snapshot to detect overflow
//   4. On corruption: dump full context (element, slab, alloc history)
// ---------------------------------------------------------------------------
namespace {
constexpr uint32_t kPool16ClassHead = 0x82830DB8u;
constexpr uint32_t kPool16MaxSnapshots = 32768u;
struct Pool16Snapshot {
  uint32_t elemAddr;    // allocated element address (guest)
  uint32_t first8bytes; // snapshot of [elem+0..3] (BE) at allocation time
  uint32_t callerLR;    // return address of the allocator's caller
  uint32_t allocIdx;    // global allocation index
};
Pool16Snapshot g_pool16Snapshots[kPool16MaxSnapshots]{};
std::atomic<uint32_t> g_pool16SnapIdx{0};
std::atomic<uint32_t> g_pool16ScanCount{0};
std::atomic<uint32_t> g_pool16CorruptionCount{0};

// Dump element content as hex (16 bytes = 4 BE dwords)
void DumpPool16Element(uint32_t addr) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
  mem.ReadU32BE(addr + 0, &w0);
  mem.ReadU32BE(addr + 4, &w1);
  mem.ReadU32BE(addr + 8, &w2);
  mem.ReadU32BE(addr + 12, &w3);
  MCLA_LOG_WARN("  ELEM {:08X}: {:08X} {:08X} {:08X} {:08X}", addr, w0, w1, w2,
                w3);
}

// Scan ALL slabs for the 16-byte pool: compare each allocated element's first
// 4 bytes against its snapshot. A change in the first 4 bytes of a freed
// element (which should hold a freelist next-pointer) indicates overflow from
// the preceding element.
void ScanPool16SlabsForOverflow(uint32_t triggerAllocIdx) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t headWord = OomCensusReadU32(kPool16ClassHead + 4);
  const uint32_t es = headWord >> 16;
  const uint32_t cap = headWord & 0xFFFFu;
  if (es != 16 || cap != 1018)
    return;

  uint32_t curSlab = OomCensusReadU32(kPool16ClassHead + 0);
  uint32_t slabIdx = 0;
  while (curSlab != 0) {
    const uint32_t slabCount = OomCensusReadU32(curSlab + 8);
    const uint32_t slabFreeHead = OomCensusReadU32(curSlab + 12);

    // Build a hash set of free element addresses for this slab (fast lookup).
    // Elements on the freelist have [node+0] = next-free, which points within
    // the slab data area. Walk the chain to identify all free elements.
    // Use a small local buffer; typical slab has ~400-600 free elements.
    static thread_local uint32_t s_freeAddrs[1200];
    uint32_t freeCount = 0;
    if (slabFreeHead != 0 && slabCount > 0 && slabCount < cap) {
      uint32_t cur = slabFreeHead;
      while (cur != 0 && freeCount < 1200) {
        s_freeAddrs[freeCount++] = cur;
        cur = OomCensusReadU32(cur + 0);
        if (freeCount > cap)
          break; // safety: avoid infinite loop on corrupted chain
      }
    }

    // Scan every element in the slab
    for (uint32_t i = 0; i < cap; ++i) {
      const uint32_t elemAddr = curSlab + 32 + i * es;

      // Check if this element is on the freelist
      bool isFree = false;
      for (uint32_t f = 0; f < freeCount; ++f) {
        if (s_freeAddrs[f] == elemAddr) {
          isFree = true;
          break;
        }
      }

      if (isFree)
        continue; // free elements are expected to have freelist pointers

      // Element is allocated. Check if its first 4 bytes match the snapshot.
      const uint32_t curFirst4 = OomCensusReadU32(elemAddr + 0);

      // Search snapshot for this address
      bool found = false;
      uint32_t snapIdx = g_pool16SnapIdx.load(std::memory_order_relaxed);
      const uint32_t searchCount = std::min(snapIdx, kPool16MaxSnapshots);
      for (uint32_t s = 0; s < searchCount; ++s) {
        if (g_pool16Snapshots[s].elemAddr == elemAddr) {
          found = true;
          if (g_pool16Snapshots[s].first8bytes != curFirst4) {
            const uint32_t corruptN = g_pool16CorruptionCount.fetch_add(1) + 1;
            if (corruptN <= 32) {
              MCLA_LOG_WARN(
                  "POOL16-OVERFLOW #{} elem={:08X} slab={} elemIdx={} "
                  "snapFirst4={:08X} curFirst4={:08X} snapLR={:08X} "
                  "snapAllocIdx={} triggerAllocIdx={} slabCount={} "
                  "slabFreeHead={:08X}",
                  corruptN, elemAddr, slabIdx, i,
                  g_pool16Snapshots[s].first8bytes, curFirst4,
                  g_pool16Snapshots[s].callerLR, g_pool16Snapshots[s].allocIdx,
                  triggerAllocIdx, slabCount, slabFreeHead);

              // Dump the corrupted element and its neighbors
              if (i > 0) {
                DumpPool16Element(elemAddr - es); // preceding element
              }
              DumpPool16Element(elemAddr); // the element itself
              if (i + 1 < cap) {
                DumpPool16Element(elemAddr + es); // following element
              }

              // Dump slab header
              MCLA_LOG_WARN("  SLAB {:08X}: next={:08X} prev={:08X} count={} "
                            "freeHead={:08X} owner={:08X}",
                            curSlab, OomCensusReadU32(curSlab + 0),
                            OomCensusReadU32(curSlab + 4), slabCount,
                            slabFreeHead, OomCensusReadU32(curSlab + 16));

              spdlog::default_logger()->flush();
            }
          }
          break;
        }
      }
      // Element not in snapshot buffer (either too old or not from 16-byte
      // pool) — skip silently
    }

    curSlab = OomCensusReadU32(curSlab + 4);
    ++slabIdx;
  }
}
} // namespace

#ifdef MCLA_ALLOC_DEBUG
thread_local uint32_t t_prevPoolNode = 0; // per-thread: last returned node
thread_local uint32_t t_lastSlabHead =
    0; // head value after last pop on this thread
thread_local uint32_t t_lastSlabAddr =
    0; // slab addr of last pop on this thread
#endif
} // namespace

PPC_FUNC_IMPL(__imp__sub_821DE9D8);
PPC_FUNC(sub_821DE9D8) {
  const uint32_t classHead = ctx.r3.u32;
  const uint32_t heap = ctx.r4.u32;
  const uint32_t depthBefore = t_arenaDepth;

  // The live boot issue is a corrupted tiny-slab freelist: a count>0 slab can
  // still have a head pointer that points outside the slab body, which causes
  // an immediate return-0 even though the class still has free elements. Repair
  // the stale freelist before the original allocator sees it so boot can
  // continue.
  (void)RepairCorruptedTinySlabFreeList(classHead);

  // SESSION 47: capture slab-list head + first slab state BEFORE the allocator
  // runs.  If it differs after the allocator returns 0, another thread modified
  // the slab list during the allocator's execution.
  const uint32_t preAllocSlab = OomCensusReadU32(classHead + 0);
  uint32_t preAllocCount = 0, preAllocHead = 0;
  if (preAllocSlab != 0) {
    preAllocCount = OomCensusReadU32(preAllocSlab + 8);
    preAllocHead = OomCensusReadU32(preAllocSlab + 12);
  }

  // SESSION 47/49: walk ALL slabs for this classHead, check chain integrity.
  // Walk the chain from head and count elements. If chain length != count, the
  // chain is corrupted. Log every 8th call.
  {
    const uint32_t hw = OomCensusReadU32(classHead + 4);
    const uint32_t es = hw >> 16;
    const uint32_t cap = hw & 0xFFFFu;
    if (es > 0 && es <= 64 && cap > 0 && cap <= 4096 && preAllocSlab != 0) {
      static std::atomic<uint32_t> s_chainChecks{0};
      const uint32_t checkIdx = s_chainChecks.fetch_add(1);
      if (checkIdx % 8 == 0) {
        uint32_t curSlab = OomCensusReadU32(classHead + 0);
        while (curSlab != 0) {
          const uint32_t slabCount = OomCensusReadU32(curSlab + 8);
          const uint32_t slabHead = OomCensusReadU32(curSlab + 12);
          if (slabCount > 1 && slabHead != 0) {
            uint32_t chainLen = 0;
            uint32_t cur = slabHead;
            while (cur != 0 && chainLen <= cap * 2) {
              ++chainLen;
              cur = OomCensusReadU32(cur + 0);
            }
            if (chainLen != slabCount) {
              MCLA_LOG_WARN(
                  "POOL-CHAIN-BROKEN check={} slab={:08X} count={} chainLen={} "
                  "head={:08X} headNext={:08X} lr={:08X} tid={:08X}",
                  checkIdx, curSlab, slabCount, chainLen, slabHead,
                  OomCensusReadU32(slabHead + 0), static_cast<uint32_t>(ctx.lr),
                  static_cast<uint32_t>(GetCurrentThreadId()));
            } else {
              MCLA_LOG_WARN(
                  "CHAIN-OK check={} slab={:08X} count={} chainLen={} "
                  "head={:08X} headNext={:08X}",
                  checkIdx, curSlab, slabCount, chainLen, slabHead,
                  OomCensusReadU32(slabHead + 0));
            }
          }
          curSlab = OomCensusReadU32(curSlab + 4);
        }
      }
    }
  }

  // SESSION 49: Chain rebuild for the 16-byte pool (classHead 82830DB8).
  // Root cause: game code writes >16 bytes to 16-byte pool allocations,
  // overflowing into the adjacent element's freelist next pointer (at node+0 of
  // the next element). Since elements are packed at elemStride intervals, the
  // overflow corrupts the chain.
  //
  // Strategy: Walk ALL slabs for this classHead.  When a slab's freelist head's
  // next
  //   pointer is outside the slab data area, the chain is broken.  Attempt to
  //   scan all elements for 0xDD free pattern; if that fails (game overwrites
  //   freed memory), reset count+head to 0.  The allocator handles count=0 by
  //   creating fresh slabs. This loses ~632 free elements per corrupted slab
  //   but prevents OOM.
  {
    const uint32_t hw49 = OomCensusReadU32(classHead + 4);
    const uint32_t es49 = hw49 >> 16;
    const uint32_t cap49 = hw49 & 0xFFFFu;

    if (es49 > 0 && es49 <= 64 && cap49 > 0 && cap49 <= 4096) {
      uint32_t curSlab49 = OomCensusReadU32(classHead + 0);
      while (curSlab49 != 0) {
        const uint32_t cnt49 = OomCensusReadU32(curSlab49 + 8);
        const uint32_t hd49 = OomCensusReadU32(curSlab49 + 12);

        if (cnt49 > 0 && hd49 != 0) {
          const uint32_t hdNext49 = OomCensusReadU32(hd49 + 0);
          if (hdNext49 != 0 &&
              (hdNext49 < curSlab49 + 32 || hdNext49 >= curSlab49 + 16384)) {
            auto &mem49 = mcla::kernel::GuestMemoryHeap::Instance();
            uint32_t newHead49 = 0;
            uint32_t newCount49 = 0;

            for (uint32_t i49 = 0; i49 < cap49; i49++) {
              const uint32_t eAddr49 = curSlab49 + 32 + i49 * es49;
              bool looksFree49 = true;
              for (uint32_t b49 = 4; b49 < es49; b49 += 4) {
                if (OomCensusReadU32(eAddr49 + b49) != 0xDDDDDDDD) {
                  looksFree49 = false;
                  break;
                }
              }
              if (looksFree49) {
                (void)mem49.WriteU32BE(eAddr49 + 0, newHead49);
                newHead49 = eAddr49;
                newCount49++;
              }
            }

            (void)mem49.WriteU32BE(curSlab49 + 12, newHead49);
            (void)mem49.WriteU32BE(curSlab49 + 8, newCount49);

            MCLA_LOG_WARN("POOL-CHAIN-REBUILT slab={:08X} es={} cap={} "
                          "oldCount={} newCount={} head={:08X} lr={:08X}",
                          curSlab49, es49, cap49, cnt49, newCount49, newHead49,
                          static_cast<uint32_t>(ctx.lr));

            // Update preAlloc* if this was the first slab
            if (curSlab49 == preAllocSlab) {
              preAllocCount = newCount49;
              preAllocHead = newHead49;
            }
          }
        }

        curSlab49 = OomCensusReadU32(curSlab49 + 4);
      }
    }
  }

#ifdef MCLA_ALLOC_DEBUG
  // SESSION 39 WRITE-WATCH: capture pre-pop head state before the original
  // runs, so we can detect (a) head-reset between pops and (b) interleaved
  // writes by another thread.
  // classHead+4 layout (big-endian): halfword at +4 = elem stride, halfword at
  // +6 = capacity 32-bit read at +4: upper16 = lhz(+4) = elem stride, lower16 =
  // lhz(+6) = capacity
  const uint32_t preHeadWord = OomCensusReadU32(classHead + 4);
  const uint32_t preElemsize =
      preHeadWord >> 16; // lhz(classHead+4) = element stride
  uint32_t preSlab = 0, preHead = 0, preCount = 0;
  bool watchElemsize4 = (preElemsize == 4);
  if (watchElemsize4) {
    preSlab = OomCensusReadU32(classHead + 0);
    if (preSlab != 0) {
      preHead = OomCensusReadU32(preSlab + 12);
      preCount = OomCensusReadU32(preSlab + 8);
      if (t_lastSlabAddr == preSlab && t_lastSlabHead != 0 &&
          preHead != t_lastSlabHead && preHead != 0) {
        MCLA_LOG_WARN("WRITE-WATCH HEAD-RESET slab={:08X} lastHead={:08X} "
                      "nowHead={:08X} count={} tid={:08X}",
                      preSlab, t_lastSlabHead, preHead, preCount,
                      static_cast<uint32_t>(GetCurrentThreadId()));
      }
    }
  }
#endif

  __imp__sub_821DE9D8(ctx, base);

  if (ctx.r3.u32 != 0) {
    const uint32_t node = ctx.r3.u32;
    const uint32_t slab = node & ~0x3FFFu;
    const uint32_t headWord = OomCensusReadU32(classHead + 4);
    const uint32_t elemsize = headWord >> 16;     // lhz(+4) = elem stride
    const uint32_t capacity = headWord & 0xFFFFu; // lhz(+6) = nodes per slab

    // SESSION 52: 16-byte pool writer-attribution census.
    // Track EVERY allocation from the 16-byte pool (elemsize=16, capacity=1018)
    // with full caller context (LR, stack, TLS) to identify who later overflows
    // the 16-byte elements. The overflow root cause is a write >16 bytes into
    // these nodes - we need to know who allocates them and where from.
    if (elemsize == 16 && capacity == 1018) {
      Arm16BytePoolPayloadWatch(slab, elemsize, capacity);
      const uint32_t allocIdx = s_allocCensus.fetch_add(1) + 1;
      const uint32_t sp = ctx.r1.u32;
      const uint32_t bc = OomCensusReadU32(sp);

      // Capture caller LR and stack frame
      const uint32_t allocLr = static_cast<uint32_t>(ctx.lr);

      // Walk back chain for caller context
      uint32_t callerBC = 0, callerLR = 0, callerR28 = 0, callerR29 = 0;
      if (bc != 0) {
        callerBC = OomCensusReadU32(bc);
        callerLR = OomCensusReadU32(bc + 8);
        callerR29 = OomCensusReadU32(bc + 36); // heap
        callerR28 = OomCensusReadU32(bc + 40); // node
      }

      // Resolve TLS[28] → object → vtable → vtable[3] for type identification
      const uint32_t tlsBase = OomCensusReadU32(ctx.r13.u32);
      const uint32_t tlsObj =
          (tlsBase != 0) ? OomCensusReadU32(tlsBase + 28) : 0;
      const uint32_t vtable = (tlsObj != 0) ? OomCensusReadU32(tlsObj) : 0;
      const uint32_t vfunc3 = (vtable != 0) ? OomCensusReadU32(vtable + 12) : 0;

      // Log EVERY 16-byte pool allocation for first 2000, then every 100th
      const bool denseAllocLog = (allocIdx <= 2000u) || (allocIdx % 100u == 0u);
      if (denseAllocLog) {
        MCLA_LOG_WARN(
            "POOL16-ALLOC #{} classHead={:08X} node={:08X} slab={:08X} "
            "lr={:08X} sp={:08X} bc={:08X} callerLR={:08X} callerBC={:08X} "
            "callerR28={:08X} callerR29={:08X} tlsObj={:08X} vtable={:08X} "
            "vfunc3={:08X} "
            "r3={:08X} r4={:08X} r5={:08X} r6={:08X} r7={:08X} r8={:08X} "
            "r9={:08X} r10={:08X}",
            allocIdx, classHead, node, slab, allocLr, sp, bc, callerLR,
            callerBC, callerR28, callerR29, tlsObj, vtable, vfunc3, ctx.r3.u32,
            ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32,
            ctx.r9.u32, ctx.r10.u32);
        spdlog::default_logger()->flush();
      }

      // Also write to raw file for crash-resilient attribution
      {
        static int s_fd16 = -1;
        if (s_fd16 < 0) {
          _sopen_s(&s_fd16, "cache/pool16_writers.log",
                   _O_WRONLY | _O_CREAT | _O_APPEND, _SH_DENYNO,
                   _S_IREAD | _S_IWRITE);
        }
        if (s_fd16 >= 0) {
          char buf[384];
          const int len = snprintf(
              buf, sizeof(buf),
              "#%u classHead=%08X node=%08X slab=%08X lr=%08X sp=%08X bc=%08X "
              "callerLR=%08X callerBC=%08X callerR28=%08X callerR29=%08X "
              "tlsObj=%08X vtable=%08X vfunc3=%08X r3=%08X r4=%08X r5=%08X "
              "r6=%08X r7=%08X r8=%08X r9=%08X r10=%08X\n",
              allocIdx, classHead, node, slab, allocLr, sp, bc, callerLR,
              callerBC, callerR28, callerR29, tlsObj, vtable, vfunc3,
              ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,
              ctx.r8.u32, ctx.r9.u32, ctx.r10.u32);
          _write(s_fd16, buf, len);
          _commit(s_fd16);
        }
      }

      // SESSION 55 B3: Snapshot this allocation for writer-attribution.
      // Store the element address, first 4 bytes (snapshot), caller LR, and
      // allocation index. Used by ScanPool16SlabsForOverflow to detect when
      // an element's content changes after allocation (overflow signature).
      {
        const uint32_t snapIdx = g_pool16SnapIdx.fetch_add(1);
        const uint32_t slot = snapIdx % kPool16MaxSnapshots;
        auto &mem16 = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t first4 = 0;
        mem16.ReadU32BE(node + 0, &first4);
        g_pool16Snapshots[slot] = {node, first4, allocLr, allocIdx};
      }

      // Periodic full slab scan: every 500th 16-byte pool allocation, walk
      // ALL slabs and compare every allocated element against its snapshot.
      // This catches overflow that occurred on any element, not just at free
      // time. The scan is expensive (~200K element reads) but rare enough
      // to not impact boot time significantly.
      {
        const uint32_t scanN = g_pool16ScanCount.fetch_add(1);
        if (scanN > 0 && scanN % 500 == 0) {
          MCLA_LOG_WARN("POOL16-SCAN trigger=alloc#{} scanning all slabs...",
                        allocIdx);
          ScanPool16SlabsForOverflow(allocIdx);
          spdlog::default_logger()->flush();
        }
      }
    }

    const uint32_t a = s_allocCensus.fetch_add(1) + 1;
    if (a <= 16 || a % 4096 == 0) {
      const uint32_t sp = ctx.r1.u32;
      const uint32_t bc = OomCensusReadU32(sp);
      MCLA_LOG_WARN("POOL-ALLOC #{} classHead={:08X} node={:08X} slab={:08X} "
                    "elemsize={} capacity={} sp={:08X} bc={:08X} lr={:08X}",
                    a, classHead, node, slab, elemsize, capacity, sp, bc,
                    static_cast<uint32_t>(ctx.lr));
    }
    // SESSION 47: check for desync after EVERY successful pop.
    // The allocator just popped from a slab — verify count and freelist
    // are consistent. Log every pop for the first 512, then only desyncs.
    {
      const uint32_t node = ctx.r3.u32;
      const uint32_t slab = node & ~0x3FFFu;
      const uint32_t countAfter = OomCensusReadU32(slab + 8);
      const uint32_t headAfter = OomCensusReadU32(slab + 12);
      const uint32_t k = s_poolPops.fetch_add(1) + 1;
      const bool desync = (headAfter == 0) && (countAfter != 0);

      // SESSION 48: for the 16-byte pool, check if the new head's next
      // pointer is within the slab data area.  If not, the chain is corrupted.
      const uint32_t hw = OomCensusReadU32(classHead + 4);
      if ((hw >> 16) == 16 && (hw & 0xFFFF) == 1018 && headAfter != 0) {
        const uint32_t headNext = OomCensusReadU32(headAfter + 0);
        if (headNext != 0 &&
            (headNext < slab + 32 || headNext >= slab + 16384)) {
          MCLA_LOG_WARN("POOL-CORRUPT-NEXT #{} node={:08X} slab={:08X} "
                        "headAfter={:08X} headNext={:08X} OUT-OF-SLAB "
                        "lr={:08X} tid={:08X}",
                        k, node, slab, headAfter, headNext,
                        static_cast<uint32_t>(ctx.lr),
                        static_cast<uint32_t>(GetCurrentThreadId()));
        }
        // Also check: head valid but next==0 while count>1 means chain
        // truncated
        if (headNext == 0 && countAfter > 1) {
          MCLA_LOG_WARN("POOL-CHAIN-TRUNC #{} node={:08X} slab={:08X} "
                        "count={} headAfter={:08X} lr={:08X} tid={:08X}",
                        k, node, slab, countAfter, headAfter,
                        static_cast<uint32_t>(ctx.lr),
                        static_cast<uint32_t>(GetCurrentThreadId()));
        }
      }

      if (k <= 512 || desync) {
        MCLA_LOG_WARN(
            "POOL-POP #{} node={:08X} slab={:08X} count={} head={:08X} "
            "preSlab={:08X} preCount={} preHead={:08X} lr={:08X} "
            "tid={:08X}{}",
            k, node, slab, countAfter, headAfter, preAllocSlab, preAllocCount,
            preAllocHead, static_cast<uint32_t>(ctx.lr),
            static_cast<uint32_t>(GetCurrentThreadId()),
            desync ? " DESYNC" : "");
      }
    }
#ifdef MCLA_ALLOC_DEBUG
    const uint32_t node = ctx.r3.u32;
    const uint32_t slab = node & ~0x3FFFu;
    const uint32_t countAfter = OomCensusReadU32(slab + 8);
    const uint32_t nextAfter = OomCensusReadU32(slab + 12);
    const uint32_t k = s_poolPops.fetch_add(1) + 1;
    const bool desync = (nextAfter == 0) && (countAfter != 0);
    const bool repeat = (node == t_prevPoolNode);

    if (watchElemsize4 && preSlab != 0 && preSlab == slab) {
      const bool headDidntAdvance = (nextAfter == preHead) && (preHead != 0);
      if (headDidntAdvance) {
        MCLA_LOG_WARN("WRITE-WATCH NO-ADVANCE #{} node={:08X} slab={:08X} "
                      "preHead={:08X} postHead={:08X} count={}->{} lr={:08X} "
                      "tid={:08X}",
                      k, node, slab, preHead, nextAfter, preCount, countAfter,
                      static_cast<uint32_t>(ctx.lr),
                      static_cast<uint32_t>(GetCurrentThreadId()));
      }
      if (nextAfter != 0 &&
          (nextAfter < slab + 32 || nextAfter >= slab + 16384)) {
        MCLA_LOG_WARN("WRITE-WATCH CORRUPT-NEXT #{} node={:08X} slab={:08X} "
                      "nextAfter={:08X} OUT-OF-SLAB lr={:08X} tid={:08X}",
                      k, node, slab, nextAfter, static_cast<uint32_t>(ctx.lr),
                      static_cast<uint32_t>(GetCurrentThreadId()));
      }
      t_lastSlabHead = nextAfter;
      t_lastSlabAddr = slab;
    }

    if (k <= 512 || desync || repeat) {
      MCLA_LOG_WARN("POOL-POP #{} node={:08X} slab={:08X} countAfter={} "
                    "nextAfter={:08X} lr={:08X} r13={:08X} tid={:08X}{}{}",
                    k, node, slab, countAfter, nextAfter,
                    static_cast<uint32_t>(ctx.lr),
                    static_cast<uint32_t>(ctx.r13.u32),
                    static_cast<uint32_t>(GetCurrentThreadId()),
                    desync ? " DESYNC" : "", repeat ? " REPEAT" : "");
    }
    t_prevPoolNode = node;
#endif
    return;
  }

  const uint32_t failIdx = s_poolFailures.fetch_add(1) + 1;
  s_poolCensus.fetch_add(1);
  const bool refilled = (t_arenaDepth != depthBefore);

  // SESSION 37: log EVERY return-0 (no sampling) for slab corruption
  // root-cause. classHead+4 layout: upper16 = lhz(+4) = elem stride, lower16 =
  // lhz(+6) = capacity
  const uint32_t headWord = OomCensusReadU32(classHead + 4);
  const uint32_t elemsize = headWord >> 16;         // lhz(+4) = element stride
  const uint32_t nodesPerSlab = headWord & 0xFFFFu; // lhz(+6) = capacity
  const uint32_t headSlab = OomCensusReadU32(classHead + 0);

  // SESSION 37: walk ALL slabs and dump every one's state.
  // Slab layout: +0=next-newer, +4=prev-older, +8=count, +12=freelist,
  // +16=owner For each slab with count!=0, also walk the freelist to get chain
  // length.
  uint32_t totalSlabs = 0, totalFree = 0, slabsWithFree = 0;
  uint32_t firstNonZeroSlab = 0, firstNonZeroCount = 0,
           firstNonZeroFreelist = 0, firstNonZeroChainLen = 0;
  uint32_t curSlab = headSlab;
  while (curSlab != 0 && totalSlabs < 32) {
    const uint32_t sNext = OomCensusReadU32(curSlab + 0);
    const uint32_t sPrev = OomCensusReadU32(curSlab + 4);
    const uint32_t sCount = OomCensusReadU32(curSlab + 8);
    const uint32_t sFree = OomCensusReadU32(curSlab + 12);
    const uint32_t sOwner = OomCensusReadU32(curSlab + 16);

    uint32_t chainLen = 0;
    if (sCount != 0) {
      ++slabsWithFree;
      totalFree += sCount;
      uint32_t cur = sFree;
      while (cur != 0 && chainLen < 4096) {
        ++chainLen;
        cur = OomCensusReadU32(cur + 0);
      }
      if (firstNonZeroSlab == 0) {
        firstNonZeroSlab = curSlab;
        firstNonZeroCount = sCount;
        firstNonZeroFreelist = sFree;
        firstNonZeroChainLen = chainLen;
      }
    }

    MCLA_LOG_WARN(
        "POOL-CENSUS FAIL#{} SLAB[{}] slab={:08X} next={:08X} prev={:08X} "
        "count={} freelist={:08X} owner={:08X} chainLen={}",
        failIdx, totalSlabs, curSlab, sNext, sPrev, sCount, sFree, sOwner,
        chainLen);

    curSlab = sNext;
    ++totalSlabs;
  }

  MCLA_LOG_WARN("POOL-CENSUS FAIL#{} {} classHead={:08X} heap={:08X} "
                "elemsize={} capacity={}: "
                "headSlab={:08X} totalSlabs={} slabsWithFree={} totalFree={} "
                "preSlab={:08X} preCount={} preHead={:08X} lr={:08X}",
                failIdx, refilled ? "REFILLFAIL" : "NOREFILL", classHead, heap,
                elemsize, nodesPerSlab, headSlab, totalSlabs, slabsWithFree,
                totalFree, preAllocSlab, preAllocCount, preAllocHead,
                static_cast<uint32_t>(ctx.lr));

  // SESSION 37: diagnostic summary for first slab with count!=0
  if (firstNonZeroSlab != 0) {
    MCLA_LOG_WARN("POOL-CENSUS FAIL#{} FIRST-NONZERO slab={:08X} count={} "
                  "freelist={:08X} "
                  "chainLen={} countMatch={}",
                  failIdx, firstNonZeroSlab, firstNonZeroCount,
                  firstNonZeroFreelist, firstNonZeroChainLen,
                  firstNonZeroChainLen == firstNonZeroCount ? "YES" : "NO");
  }

  // SESSION 47: compare pre/post slab state. If the allocator saw different
  // state than what we read after, another thread modified the slab list.
  const uint32_t postAllocSlab = OomCensusReadU32(classHead + 0);
  if (preAllocSlab != postAllocSlab) {
    MCLA_LOG_WARN("POOL-CENSUS SLAB-CHANGED classHead={:08X} preSlab={:08X} "
                  "postSlab={:08X} preCount={} preHead={:08X}",
                  classHead, preAllocSlab, postAllocSlab, preAllocCount,
                  preAllocHead);
  } else if (preAllocSlab != 0 && preAllocCount == 0 && firstNonZeroCount > 0) {
    MCLA_LOG_WARN("POOL-CENSUS COUNT-JUMP classHead={:08X} slab={:08X} "
                  "preCount=0 postCount={} preHead={:08X} postHead={:08X}",
                  classHead, preAllocSlab, firstNonZeroCount, preAllocHead,
                  firstNonZeroFreelist);
  }
}

// ---------------------------------------------------------------------------
// SESSION 37 STEP 2b: push-back consistency census on sub_821DE908(slab,
// node, heap) - the pool-node free (routes from sub_821C2AB8 when the slab
// bitmap bit is set). A node outside [slab+32, slab+32 + n*elemsize) or not
// on an element boundary means a stale/foreign pointer is being pushed into
// the class freelist - the leading root-cause candidate for the count vs
// freelist desync. CENSUS ONLY, passthrough, checked BE reads.
// ---------------------------------------------------------------------------
namespace {
std::atomic<uint32_t> s_poolFreeFrees{0};
std::atomic<uint32_t> s_poolFreeAnomalies{0};
} // namespace

PPC_FUNC_IMPL(__imp__sub_821DE908);
PPC_FUNC(sub_821DE908) {
  const uint32_t slab = ctx.r3.u32;
  const uint32_t node = ctx.r4.u32;
  const uint32_t caller_lr = static_cast<uint32_t>(ctx.lr);
  const uint32_t sp = ctx.r1.u32;
  const uint32_t countBefore = OomCensusReadU32(slab + 8);
  const uint32_t freeHeadBefore = OomCensusReadU32(slab + 12);

  // sp is sub_821C2AB8's stack (after its stwu r1,-112(r1)):
  //   sp+0   = back chain (sub_821C09C8's sp after its stwu r1,-128(r1))
  //   sp+80  = lock object area
  //   sp+88  = saved r30
  //   sp+96  = saved r31
  //   sp+104 = saved LR (return to sub_821C09C8)
  const uint32_t backChain = OomCensusReadU32(sp);
  const uint32_t savedR30 = OomCensusReadU32(sp + 88);
  const uint32_t savedR31 = OomCensusReadU32(sp + 96);
  const uint32_t savedLR = OomCensusReadU32(sp + 104);
  // Walk up to sub_821C09C8's frame:
  //   backChain+0 = back chain (game caller's sp)
  //   backChain+8 = saved LR (game caller's return address, security cookie
  //   pattern) backChain+36 = r29 (heap) backChain+40 = r28 (node passed to
  //   sub_821C09C8)
  const uint32_t callerBC = OomCensusReadU32(backChain);
  const uint32_t callerLR = OomCensusReadU32(backChain + 8);
  const uint32_t callerR29 = OomCensusReadU32(backChain + 36);
  const uint32_t callerR28 = OomCensusReadU32(backChain + 40);

  // SESSION 47: log pre-free state for the failing pool (classHead 82830DB8).
  // If freelist is already 0 before the free, the slab is pre-corrupted.
  {
    const uint32_t owner = OomCensusReadU32(slab + 16);
    const uint32_t hw = OomCensusReadU32(owner + 4);
    const uint32_t es = hw >> 16;
    const uint32_t cap = hw & 0xFFFFu;
    if (es == 16 && cap == 1018 && freeHeadBefore == 0 && countBefore > 0) {
      MCLA_LOG_WARN("POOL-FREE-PRE-DESINCRONIZED slab={:08X} node={:08X} "
                    "countBefore={} freeHeadBefore={:08X} lr={:08X} tid={:08X}",
                    slab, node, countBefore, freeHeadBefore, caller_lr,
                    static_cast<uint32_t>(GetCurrentThreadId()));
    }
  }

  // SESSION 55 B3: Writer-attribution corruption check at free time.
  // Compare the element's first 4 bytes against the allocation snapshot.
  // If they differ, the element was overwritten after allocation — overflow
  // from the preceding element or a direct overwrite. Must run BEFORE the
  // original free (which overwrites [node+0] with the freelist next-pointer).
  {
    const uint32_t owner = OomCensusReadU32(slab + 16);
    const uint32_t hw = OomCensusReadU32(owner + 4);
    const uint32_t es = hw >> 16;
    const uint32_t cap = hw & 0xFFFFu;
    if (es == 16 && cap == 1018) {
      const uint32_t curFirst4 = OomCensusReadU32(node + 0);
      // Search snapshot for this element
      const uint32_t snapIdx = g_pool16SnapIdx.load(std::memory_order_relaxed);
      const uint32_t searchCount = std::min(snapIdx, kPool16MaxSnapshots);
      for (uint32_t s = 0; s < searchCount; ++s) {
        if (g_pool16Snapshots[s].elemAddr == node) {
          if (g_pool16Snapshots[s].first8bytes != curFirst4) {
            const uint32_t corruptN = g_pool16CorruptionCount.fetch_add(1) + 1;
            if (corruptN <= 64) {
              auto &memFC = mcla::kernel::GuestMemoryHeap::Instance();
              uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
              memFC.ReadU32BE(node + 0, &w0);
              memFC.ReadU32BE(node + 4, &w1);
              memFC.ReadU32BE(node + 8, &w2);
              memFC.ReadU32BE(node + 12, &w3);

              const uint32_t elemIdx = (node - (slab + 32)) / es;
              MCLA_LOG_WARN(
                  "POOL16-FREE-CORRUPT #{} node={:08X} slab={} elemIdx={} "
                  "snapFirst4={:08X} curFirst4={:08X} snapLR={:08X} "
                  "snapAllocIdx={} freeLR={:08X} freeTid={:08X} "
                  "ELEM: {:08X} {:08X} {:08X} {:08X}",
                  corruptN, node, slab, elemIdx,
                  g_pool16Snapshots[s].first8bytes, curFirst4,
                  g_pool16Snapshots[s].callerLR, g_pool16Snapshots[s].allocIdx,
                  caller_lr, static_cast<uint32_t>(GetCurrentThreadId()), w0,
                  w1, w2, w3);

              // Dump preceding and following elements for context
              if (elemIdx > 0) {
                uint32_t pw0 = 0, pw1 = 0, pw2 = 0, pw3 = 0;
                const uint32_t prevAddr = node - es;
                memFC.ReadU32BE(prevAddr + 0, &pw0);
                memFC.ReadU32BE(prevAddr + 4, &pw1);
                memFC.ReadU32BE(prevAddr + 8, &pw2);
                memFC.ReadU32BE(prevAddr + 12, &pw3);
                MCLA_LOG_WARN("  PREV  {:08X}: {:08X} {:08X} {:08X} {:08X}",
                              prevAddr, pw0, pw1, pw2, pw3);
              }
              if (elemIdx + 1 < cap) {
                uint32_t nw0 = 0, nw1 = 0, nw2 = 0, nw3 = 0;
                const uint32_t nextAddr = node + es;
                memFC.ReadU32BE(nextAddr + 0, &nw0);
                memFC.ReadU32BE(nextAddr + 4, &nw1);
                memFC.ReadU32BE(nextAddr + 8, &nw2);
                memFC.ReadU32BE(nextAddr + 12, &nw3);
                MCLA_LOG_WARN("  NEXT  {:08X}: {:08X} {:08X} {:08X} {:08X}",
                              nextAddr, nw0, nw1, nw2, nw3);
              }

              spdlog::default_logger()->flush();
            }
          }
          break;
        }
      }
    }
  }

  __imp__sub_821DE908(ctx, base);

  // classHead+4 layout: upper16 = lhz(+4) = elem stride, lower16 = lhz(+6) =
  // capacity
  const uint32_t owner = OomCensusReadU32(slab + 16);
  const uint32_t headWord = OomCensusReadU32(owner + 4);
  const uint32_t elemsize = headWord >> 16;         // lhz(+4) = element stride
  const uint32_t nodesPerSlab = headWord & 0xFFFFu; // lhz(+6) = capacity
  const uint32_t countAfter = OomCensusReadU32(slab + 8);
  const uint32_t freeHeadAfter = OomCensusReadU32(slab + 12);

  bool inside = false;
  if (elemsize != 0 && nodesPerSlab != 0) {
    const uint32_t lo = slab + 32;
    const uint32_t span = nodesPerSlab * elemsize;
    const uint32_t off = node - lo;
    inside = (node >= lo) && (off < span) && ((off % elemsize) == 0);
  }

  // SESSION 47: always log when freelist is zeroed despite count > 0 after a
  // free — this is the signature of the count-vs-freelist desync.
  if (inside && freeHeadAfter == 0 && countAfter > 0) {
    MCLA_LOG_WARN("POOL-FREE-FREELIST-ZERO slab={:08X} node={:08X} elemsize={} "
                  "countAfter={} freeHeadBefore={:08X} freeHeadAfter={:08X} "
                  "lr={:08X} tid={:08X}",
                  slab, node, elemsize, countAfter, freeHeadBefore,
                  freeHeadAfter, caller_lr,
                  static_cast<uint32_t>(GetCurrentThreadId()));
  }
  // SESSION 47: also log when freeHeadAfter != node (unexpected — the free
  // function should set freelist_head = node just freed)
  if (inside && freeHeadAfter != node && freeHeadAfter != 0) {
    MCLA_LOG_WARN("POOL-FREE-HEAD-MISMATCH slab={:08X} node={:08X} elemsize={} "
                  "countAfter={} freeHeadBefore={:08X} freeHeadAfter={:08X} "
                  "lr={:08X} tid={:08X}",
                  slab, node, elemsize, countAfter, freeHeadBefore,
                  freeHeadAfter, caller_lr,
                  static_cast<uint32_t>(GetCurrentThreadId()));
  }

  if (inside) {
    return;
  }

  const uint32_t a = s_poolFreeAnomalies.fetch_add(1) + 1;
  s_poolFreeFrees.fetch_add(1);
  if (a <= 128 || a % 256 == 0) {
    const uint32_t off = (elemsize != 0) ? (node - (slab + 32)) : 0;
    MCLA_LOG_WARN(
        "POOL-FREE-ANOMALY #{} slab={:08X} node={:08X} elemsize={} n={} "
        "countBefore={} countAfter={} off={} "
        "freeHeadBefore={:08X} freeHeadAfter={:08X} "
        "savedLR={:08X} callerLR={:08X} callerBC={:08X} "
        "callerR28={:08X} callerR29={:08X} "
        "r30={:08X} r31={:08X}",
        a, slab, node, elemsize, nodesPerSlab, countBefore, countAfter, off,
        freeHeadBefore, freeHeadAfter, savedLR, callerLR, callerBC, callerR28,
        callerR29, savedR30, savedR31);
  }
}

// SESSION 44c: census on sub_821C09C8 — the dispatch function that routes
// pool frees. Logs r3 (heap), r4 (node), and reads the caller's stack.
namespace {
std::atomic<uint32_t> s_routerCensus{0};
} // namespace

PPC_FUNC_IMPL(__imp__sub_821C09C8);
PPC_FUNC(sub_821C09C8) {
  const uint32_t heap = ctx.r3.u32;
  const uint32_t node = ctx.r4.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  const uint32_t sp = ctx.r1.u32;

  const uint32_t backChain = OomCensusReadU32(sp);

  const uint32_t n = s_routerCensus.fetch_add(1) + 1;
  if (n <= 16 || n % 2048 == 0) {
    const uint32_t c0 = OomCensusReadU32(backChain);
    const uint32_t c1 = OomCensusReadU32(backChain + 4);
    const uint32_t c2 = OomCensusReadU32(backChain + 8);
    const uint32_t c3 = OomCensusReadU32(backChain + 12);

    // Resolve TLS[28] → object → vtable → vtable[3] to find the actual caller
    const uint32_t tlsBase = OomCensusReadU32(ctx.r13.u32);
    const uint32_t tlsObj = (tlsBase != 0) ? OomCensusReadU32(tlsBase + 28) : 0;
    const uint32_t vtable = (tlsObj != 0) ? OomCensusReadU32(tlsObj) : 0;
    const uint32_t vfunc3 = (vtable != 0) ? OomCensusReadU32(vtable + 12) : 0;

    MCLA_LOG_WARN(
        "POOL-ROUTER #{} heap={:08X} node={:08X} lr={:08X} sp={:08X} "
        "bc={:08X} c0={:08X} c1={:08X} c2={:08X} c3={:08X} "
        "r5={:08X} r6={:08X} r7={:08X} r8={:08X} r9={:08X} r10={:08X} "
        "tlsObj={:08X} vtable={:08X} vfunc3={:08X}",
        n, heap, node, lr, sp, backChain, c0, c1, c2, c3,
        static_cast<uint32_t>(ctx.r5.u32), static_cast<uint32_t>(ctx.r6.u32),
        static_cast<uint32_t>(ctx.r7.u32), static_cast<uint32_t>(ctx.r8.u32),
        static_cast<uint32_t>(ctx.r9.u32), static_cast<uint32_t>(ctx.r10.u32),
        tlsObj, vtable, vfunc3);
  }

  __imp__sub_821C09C8(ctx, base);
}

// ---------------------------------------------------------------------------
// SESSION 50/51/52: Capture-only census on sub_8218CC70 — config dispatch table
// dump. The dispatch formula (from ppc_recomp.10.cpp:17326):
//   r3 = handler index
//   table_base = 0x827D6010 (lis r11,-32131 + addi r9,r11,24512)
//   offset = [table_base + r3*4]
//   if offset == -1: return (no-op)
//   base_ptr = [0x82839254] (lis r10,-32124 + lwz r3,-28076(r10))
//   struct = base_ptr + offset
//   target_fn = [struct + 64]
//   call target_fn
//
// Capture-only: reads memory, logs, calls original. No behavior change.
// Session 51: added OOB logging with full register dump.
// Session 52: DENSE census — log EVERY call for first 5000, then every 25th,
//             plus raw file entry for ALL calls with full dispatch details.
//             Goal: catch the exact crash dispatch that happens between sparse
//             logs.
// ---------------------------------------------------------------------------
namespace {
std::atomic<uint32_t> s_configDispatchCensus{0};
std::atomic<uint32_t> s_configDispatchOOB{0};

static std::unordered_set<uint32_t> g_pool16WatchSlabs;
static std::mutex g_pool16WatchMtx;

static void Arm16BytePoolPayloadWatch(uint32_t slab, uint32_t elemsize,
                                      uint32_t nodesPerSlab) {
  if (elemsize != 16 || nodesPerSlab == 0 || slab == 0) {
    return;
  }
  const uint32_t rangeStart = slab + 32u;
  const uint32_t rangeEnd = rangeStart + (nodesPerSlab * elemsize);
  std::lock_guard<std::mutex> lock(g_pool16WatchMtx);
  if (g_pool16WatchSlabs.insert(slab).second) {
    mcla::native::RegisterGuestWatchRange(rangeStart, rangeEnd);
    MCLA_LOG_WARN("POOL16-WRITEWATCH armed slab={:08X} range={:08X}-{:08X} "
                  "elemsize={} count={}",
                  slab, rangeStart, rangeEnd, elemsize, nodesPerSlab);
  }
}

static const std::unordered_map<uint32_t, PPCFunc *> g_compiledFuncs = [] {
  std::unordered_map<uint32_t, PPCFunc *> map;
  for (size_t i = 0; PPCFuncMappings[i].host != nullptr; ++i) {
    if (PPCFuncMappings[i].guest == 0) {
      continue;
    }
    map.emplace(static_cast<uint32_t>(PPCFuncMappings[i].guest),
                PPCFuncMappings[i].host);
  }
  return map;
}();

static bool IsUncompiledDispatchStubTarget(uint32_t guestAddr) {
  // The guest uses 0x827CD0xx label addresses as data-driven dispatch rails.
  // XenonRecomp never compiled these; they are not callable host symbols.
  return guestAddr >= 0x827CD000u && guestAddr < 0x827CD100u;
}

// Ring buffer to keep last N full dispatch records for post-crash analysis
struct DispatchRecord {
  uint32_t n;
  uint32_t handlerIdx;
  uint32_t callerLr;
  uint32_t slotAddr;
  uint32_t rawOffset;
  uint32_t basePtr;
  uint32_t configGlobal;
  uint32_t structAddr;
  uint32_t targetFn;
  uint8_t
      validity; // 0=N/A 1=OUT_OF_BOUNDS 2=SENTINEL 3=BASE_NULL 4=NULL
                // 5=MISALIGNED 6=VALID_CODE 7=VALID_DATA 8=SMALL_INT 9=GARBAGE
  uint32_t r3, r4, r5, r6, r7, r8, r9, r10;
};
static DispatchRecord s_dispatchRing[4096];
static std::atomic<uint32_t> s_dispatchRingHead{0};

inline void RecordDispatch(const DispatchRecord &rec) {
  uint32_t idx = s_dispatchRingHead.fetch_add(1) & 4095u;
  s_dispatchRing[idx] = rec;
}
} // namespace

// SESSION 51: Capture-only on sub_82177EB0 — log lr, r3-r10 on every entry.
// This function does NOT call sub_8218CC70 directly, but its lr value
// (0x821782AC from a memset call) propagates through tail-call chains.
PPC_FUNC_IMPL(__imp__sub_82177EB0);
PPC_FUNC(sub_82177EB0) {
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  const uint32_t r3 = ctx.r3.u32;
  const uint32_t r4 = ctx.r4.u32;
  const uint32_t r5 = ctx.r5.u32;
  const uint32_t r6 = ctx.r6.u32;
  const uint32_t r7 = ctx.r7.u32;
  const uint32_t r8 = ctx.r8.u32;
  const uint32_t r9 = ctx.r9.u32;
  const uint32_t r10 = ctx.r10.u32;

  // Log if r3 looks like a pointer (>= 0x1000 and in guest address range)
  // or if any register looks like a heap pointer in the 0xC9xxxxxx range
  const bool r3LooksLikePointer = r3 >= 0x1000u && r3 < 0xC0000000u;
  const bool anyRegInCrashRange =
      (r3 | r4 | r5 | r6 | r7 | r8 | r9 | r10) >= 0xC9000000u &&
      (r3 | r4 | r5 | r6 | r7 | r8 | r9 | r10) < 0xCA000000u;

  if (r3LooksLikePointer || anyRegInCrashRange) {
    MCLA_LOG_WARN("SUB82177EB0: lr={:08X} r3={:08X} r4={:08X} r5={:08X} "
                  "r6={:08X} r7={:08X} r8={:08X} r9={:08X} r10={:08X}",
                  lr, r3, r4, r5, r6, r7, r8, r9, r10);
  }

  __imp__sub_82177EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218CC70);
PPC_FUNC(sub_8218CC70) {
  // RAW ENTRY LOG — write directly to file, no spdlog, no formatting
  // Use _write (POSIX) which is more crash-resilient than fprintf+fflush
  {
    static int s_fd = -1;
    if (s_fd < 0) {
      _sopen_s(&s_fd, "cache/dispatch_entry.log",
               _O_WRONLY | _O_CREAT | _O_APPEND, _SH_DENYNO,
               _S_IREAD | _S_IWRITE);
    }
    if (s_fd >= 0) {
      char buf[64];
      const int len = snprintf(buf, sizeof(buf), "ENTRY r3=%08X lr=%08X\n",
                               ctx.r3.u32, (uint32_t)ctx.lr);
      _write(s_fd, buf, len);
      _commit(s_fd);
    }
  }

  const uint32_t handlerIdx = ctx.r3.u32;
  const uint32_t callerLr = static_cast<uint32_t>(ctx.lr);

  // Capture dispatch mechanics BEFORE the original runs
  // Correct addresses: lis r11,-32131 → 0x827D0000 + 24512 = 0x827D6010
  // lis r10,-32124 → 0x82840000 - 28076 = 0x82839254
  constexpr uint32_t kTableBase = 0x827D6010u;
  constexpr uint32_t kGlobalBase = 0x82839254u;
  constexpr uint32_t kConfigGlobal =
      0x82839270u; // crash-critical: ZERO at crash
  constexpr uint32_t kMaxTableIdx =
      24u; // sentinel at 23, entries 24+ are garbage
  const bool inBounds = handlerIdx < kMaxTableIdx;
  const uint32_t slotAddr = kTableBase + handlerIdx * 4;
  const uint32_t rawOffset =
      inBounds ? OomCensusReadU32(slotAddr) : 0xDEADBEEFu;
  const uint32_t basePtr = OomCensusReadU32(kGlobalBase);

  uint32_t structAddr = 0, targetFn = 0;
  const char *validity = "N/A";
  uint8_t validityCode = 0;
  if (!inBounds) {
    validity = "OUT_OF_BOUNDS";
    validityCode = 1;
  } else if (rawOffset == 0xFFFFFFFFu) {
    validity = "SENTINEL(-1)";
    validityCode = 2;
  } else if (basePtr == 0) {
    validity = "BASE_NULL";
    validityCode = 3;
  } else {
    structAddr = basePtr + rawOffset;
    targetFn = OomCensusReadU32(structAddr + 64);

    // Classify the target function pointer
    // SESSION 53: Check masked value (bit0 may be a flag, not alignment)
    const uint32_t masked = targetFn & ~3u;
    if (targetFn == 0) {
      validity = "NULL";
      validityCode = 4;
    } else if (masked >= 0x82130000u && masked < 0x83000000u) {
      // Masked target is in code range — valid after bit0 strip
      validity = ((targetFn & 3u) != 0) ? "BIT0_CODE" : "VALID_CODE";
      validityCode = ((targetFn & 3u) != 0) ? 10 : 6;
    } else if (masked >= 0x82830000u && masked < 0x83000000u) {
      validity = ((targetFn & 3u) != 0) ? "BIT0_DATA" : "VALID_DATA";
      validityCode = ((targetFn & 3u) != 0) ? 11 : 7;
    } else if (targetFn < 0x1000u) {
      validity = "SMALL_INT";
      validityCode = 8;
    } else {
      validity = ((targetFn & 3u) != 0) ? "BIT0_GARBAGE" : "GARBAGE";
      validityCode = ((targetFn & 3u) != 0) ? 12 : 9;
    }
  }

  const uint32_t n = s_configDispatchCensus.fetch_add(1) + 1;

  // On first call: dump the full table
  if (n == 1) {
    MCLA_LOG_WARN("CONFIG-DISPATCH: === TABLE DUMP (table=0x827D6010 "
                  "global=0x82839254) ===");
    for (uint32_t i = 0; i < 64; i++) {
      const uint32_t addr = kTableBase + i * 4;
      const uint32_t val = OomCensusReadU32(addr);
      if (val == 0 && i > 40)
        break;
      MCLA_LOG_WARN("CONFIG-DISPATCH: TABLE[{}] = {:08X}", i, val);
    }
    // Dump kGlobalBase range (0x82839254..927C) + the crash-critical 0x82839270
    for (uint32_t g = 0; g < 12; g++) {
      const uint32_t gaddr = kGlobalBase + g * 4;
      MCLA_LOG_WARN("CONFIG-DISPATCH: GLOBAL @ {:08X} = {:08X}{}", gaddr,
                    OomCensusReadU32(gaddr),
                    (gaddr == kConfigGlobal) ? " <== CONFIG_GLOBAL (crash-zero)"
                                             : "");
    }
  }

  // OOB: always log with full register dump — flush immediately (crash
  // imminent)
  if (!inBounds) {
    const uint32_t oobN = s_configDispatchOOB.fetch_add(1) + 1;
    if (oobN <= 32) {
      MCLA_LOG_WARN("CONFIG-DISPATCH-OOB #{} idx={:08X} lr={:08X} | "
                    "r3={:08X} r4={:08X} r5={:08X} r6={:08X} r7={:08X} "
                    "r8={:08X} r9={:08X} r10={:08X}",
                    oobN, handlerIdx, callerLr, ctx.r3.u32, ctx.r4.u32,
                    ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32, ctx.r9.u32,
                    ctx.r10.u32);
      spdlog::default_logger()->flush();
    }
  }

  // SESSION 52: DENSE census — log EVERY call for first 5000, then every 25th.
  // The crash dispatch happens between sparse logs — we must not miss it.
  // Also read the GLOBAL @82839270 (config-global that is ZERO at crash) on
  // every call.
  const uint32_t globalAtBase = OomCensusReadU32(kGlobalBase);
  const uint32_t configGlobal = OomCensusReadU32(kConfigGlobal);

  // Record to ring buffer for post-crash analysis (ALL calls)
  DispatchRecord rec{};
  rec.n = n;
  rec.handlerIdx = handlerIdx;
  rec.callerLr = callerLr;
  rec.slotAddr = slotAddr;
  rec.rawOffset = rawOffset;
  rec.basePtr = basePtr;
  rec.configGlobal = configGlobal;
  rec.structAddr = structAddr;
  rec.targetFn = targetFn;
  rec.validity = validityCode;
  rec.r3 = ctx.r3.u32;
  rec.r4 = ctx.r4.u32;
  rec.r5 = ctx.r5.u32;
  rec.r6 = ctx.r6.u32;
  rec.r7 = ctx.r7.u32;
  rec.r8 = ctx.r8.u32;
  rec.r9 = ctx.r9.u32;
  rec.r10 = ctx.r10.u32;
  RecordDispatch(rec);

  // Dense logging: EVERY call for first 5000, then every 25th
  const bool denseLog = (n <= 5000u) || (n % 25u == 0u);
  if (denseLog) {
    const char *validityStr = validity;
    if (inBounds) {
      MCLA_LOG_WARN("CONFIG-DISPATCH #{} idx={:08X} lr={:08X} | slot={:08X} "
                    "rawOff={:08X} "
                    "basePtr={:08X} global8254={:08X} global8270={:08X} "
                    "struct={:08X} targetFn={:08X} valid=[{}]",
                    n, handlerIdx, callerLr, slotAddr, rawOffset, basePtr,
                    globalAtBase, configGlobal, structAddr, targetFn,
                    validityStr);
    } else {
      MCLA_LOG_WARN("CONFIG-DISPATCH #{} idx={:08X} lr={:08X} | "
                    "global8254={:08X} global8270={:08X} valid=[{}]",
                    n, handlerIdx, callerLr, globalAtBase, configGlobal,
                    validityStr);
    }
    spdlog::default_logger()->flush();
  }

  // ALSO write full details to raw file for ALL calls (crash-resilient)
  {
    static int s_fd2 = -1;
    if (s_fd2 < 0) {
      _sopen_s(&s_fd2, "cache/dispatch_full.log",
               _O_WRONLY | _O_CREAT | _O_APPEND, _SH_DENYNO,
               _S_IREAD | _S_IWRITE);
    }
    if (s_fd2 >= 0) {
      char buf[256];
      const char *validityStr = validity;
      const int len = snprintf(
          buf, sizeof(buf),
          "#%u idx=%08X lr=%08X slot=%08X off=%08X base=%08X g8254=%08X "
          "g8270=%08X struct=%08X target=%08X valid=%s r3=%08X r4=%08X r5=%08X "
          "r6=%08X r7=%08X r8=%08X r9=%08X r10=%08X\n",
          n, handlerIdx, callerLr, slotAddr, rawOffset, basePtr, globalAtBase,
          configGlobal, structAddr, targetFn, validityStr, ctx.r3.u32,
          ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32,
          ctx.r9.u32, ctx.r10.u32);
      _write(s_fd2, buf, len);
      _commit(s_fd2);
    }
  }

  // SESSION 55: Direct dispatch only for verified compiled functions.
  // The raw PPC_LOOKUP_FUNC slots can contain non-NULL garbage for uncompiled
  // guest labels, so we validate each target against the authoritative
  // PPCFuncMappings[] table before making the indirect call. Uncompiled label
  // addresses like 0x827CD0xx are never callable host functions; they are
  // dispatch rails and must complete without invoking a host pointer.
  if (inBounds && rawOffset != 0xFFFFFFFFu && basePtr != 0) {
    const uint32_t maskedTarget = targetFn & ~3u;
    if (maskedTarget != 0 && maskedTarget >= 0x82130000u &&
        maskedTarget < 0x83000000u) {
      const auto it = g_compiledFuncs.find(maskedTarget);
      const bool hasVerifiedHost =
          it != g_compiledFuncs.end() && it->second != nullptr;
      const bool isStubTarget = IsUncompiledDispatchStubTarget(maskedTarget);

      if (hasVerifiedHost) {
        ctx.r3.u32 = basePtr;
        ctx.r8.u32 = maskedTarget;
        ctx.r9.u32 = structAddr;
        it->second(ctx, base);
        return;
      }

      if (isStubTarget) {
        static std::unordered_set<uint32_t> loggedStubs;
        if (loggedStubs.insert(maskedTarget).second) {
          MCLA_LOG_WARN(
              "CONFIG-DISPATCH: stubbed uncompiled dispatch label {:08X}",
              maskedTarget);
        }
        // Preserve the expected register state but complete the dispatch
        // without calling a garbage or non-existent host function.
        ctx.r3.u32 = basePtr;
        ctx.r8.u32 = maskedTarget;
        ctx.r9.u32 = structAddr;
        return;
      }

      // Unverified / non-compiled target: do not dispatch anywhere.
      static std::atomic<uint32_t> s_unverifiedSkip{0};
      const uint32_t skipN = s_unverifiedSkip.fetch_add(1) + 1;
      if (skipN <= 16) {
        MCLA_LOG_WARN(
            "CONFIG-DISPATCH: rejected unverified target {:08X} at base={:08X}",
            maskedTarget, basePtr);
      }
      return;
    }
  }
}
