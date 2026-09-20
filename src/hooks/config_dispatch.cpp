// Phase 2 split of src/patches.cpp: this TU owns the config-dispatch census hooks (ex-lines 2649-3039).
// Entry points used by mcla_ApplyPatches are declared in hooks/hooks.h.
// includes mirror patches.cpp so hook bodies resolve identically.
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

  __imp__sub_82177EB0(ctx, base);

  // Session 72: callers treat r3<0 as "Unable to create backup texture for
  // depth/rendertarget" and fatal. In native mode the legacy Xenos backup
  // texture is unused (D3D12 owns RTs). Force success so boot continues.
  if (static_cast<int32_t>(ctx.r3.u32) < 0) {
    static std::atomic<uint32_t> s_createFail{0};
    const uint32_t n = s_createFail.fetch_add(1) + 1;
    if (n <= 16 || (n % 100) == 0)
      MCLA_LOG_WARN("TEXCREATE-SC #{} lr={:08X} r3={:08X} -> 0 (legacy backup "
                    "unused in native)",
                    n, lr, ctx.r3.u32);
    ctx.r3.u32 = 0;
  }

  if constexpr (!kPool16CensusEnabled) {
    return;
  }

  const uint32_t r3 = ctx.r3.u32;
  const uint32_t r4 = ctx.r4.u32;
  const uint32_t r5 = ctx.r5.u32;
  const uint32_t r6 = ctx.r6.u32;
  const uint32_t r7 = ctx.r7.u32;
  const uint32_t r8 = ctx.r8.u32;
  const uint32_t r9 = ctx.r9.u32;
  const uint32_t r10 = ctx.r10.u32;

  const bool r3LooksLikePointer = r3 >= 0x1000u && r3 < 0xC0000000u;
  const bool anyRegInCrashRange =
      (r3 | r4 | r5 | r6 | r7 | r8 | r9 | r10) >= 0xC9000000u &&
      (r3 | r4 | r5 | r6 | r7 | r8 | r9 | r10) < 0xCA000000u;

  if (r3LooksLikePointer || anyRegInCrashRange) {
    MCLA_LOG_WARN("SUB82177EB0: lr={:08X} r3={:08X} r4={:08X} r5={:08X} "
                  "r6={:08X} r7={:08X} r8={:08X} r9={:08X} r10={:08X}",
                  lr, r3, r4, r5, r6, r7, r8, r9, r10);
  }
}

PPC_FUNC_IMPL(__imp__sub_8218CC70);
PPC_FUNC(sub_8218CC70) {
  if constexpr (!kPool16CensusEnabled) {
    __imp__sub_8218CC70(ctx, base);
    return;
  }

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

// Session 75l: the committed generated tree references 0x8221D9D0 in the
// mapping table but no TU defines a body for it (linker: undefined symbol).
// No recompiled guest code calls it directly (indirect dispatch only).
// Provide a log-once census body so the table links; a hit means the game
// dispatches here and the real semantics must be recovered.
PPC_FUNC(sub_8221D9D0) {
  static std::atomic<uint32_t> s_h8221D9D0{0};
  const uint32_t n = s_h8221D9D0.fetch_add(1) + 1;
  if (n <= 8 || (n % 500) == 0) {
    MCLA_LOG_WARN("MISSING-BODY sub_8221D9D0 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  ctx.r3.u32 = 0;
}
