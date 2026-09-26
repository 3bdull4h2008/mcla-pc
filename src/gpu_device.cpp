#include "gpu_device.h"
#include "raw_inflate.h"  // F-130: expand a member the page-window hook can't
#include "xmem_lzx.h"     // F-295: Path A host XMem/raw-LZX decoder (offline-proven)
#include "gpu_cp.h"
#include "render_queue.h"
#include "renderer_mode.h"
#include "renderer_hook_dispatch.h"
#include "capture_hooks.h"
#include "native_renderer.h"
#include "boot_host.h"

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "generated/ppc_xenon/ppc_context.h"
#include "kernel/memory.h"
#include "kernel/heap.h"
#include "logging.h"
#include <cpu/ppc_context.h>
#include "fs/vfs_rpf.h"

// F-188: host-side LZX via libmspack (already compiled, CMakeLists.txt:354).
#include <lzx.h>
#include <mspack.h>

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <mutex>
#include <dbghelp.h>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <string>
#include <thread>
#include <vector>

extern std::atomic<uint32_t> g_mainGuestThreadId;
// Forward declaration for kernel tick pump (global namespace, defined in imports.cpp)
void SignalSchedulerTickPublic();
extern std::atomic<bool> s_inUILoad;

// Defined later near the embedded-list helpers; used by GETDEV so the
// 0x827D838C device has a live vtable when callers dispatch +88.
static void EnsureMemoryDeviceVtable();
static constexpr uint32_t kMemDeviceObj = 0x827D838Cu;

// Used by several later censuses (CBSETUP/GETDEV/MOUNT/TOC76); defined here
// so it is visible at every use site.
static void MclaSanitizePath(char *buf, size_t cap) {
  buf[cap - 1] = 0;
  for (size_t i = 0; i + 1 < cap; ++i) {
    unsigned char c = static_cast<unsigned char>(buf[i]);
    if (c == 0) break;
    if (c < 0x20 || c > 0x7E) {
      buf[i] = 0;
      break;
    }
  }
}

// ---------------------------------------------------------------------------
// w13: UI .xsf census. TOC76 finds the files (encrypted RPF TOC, no plaintext
// names on disk) but bodies never parse. Cache the decrypted TOC entry words
// so Open/Read/AFB8 can host-serve from xarchive_cache.rpf at the real offset.
// ---------------------------------------------------------------------------
struct XsfTocInfo {
  uint32_t entry = 0;
  uint32_t w[4] = {0, 0, 0, 0};
  int32_t openRet = -999;
  uint32_t bodyHits = 0;
};
static std::mutex g_xsfMtx;
static std::unordered_map<std::string, XsfTocInfo> g_xsfToc;
// F-247: defined early (before IsJob2UiDest) so the job2 pstream-allowlist
// expansion below can be gated on it — flag OFF keeps the EXACT baseline.
// Full F-192→F-247 rationale sits at its original declaration site (~:404).
// F-247: ON (with PATHB-PKGFIX + dynamic IsJob2UiDest) eliminated the produced=0
// livelock (w245 12106 -> w247 2), collapsed REBASE-POISON 3.36M -> 409, and made
// job2 dests decode real RSC5 — but the executor then soft-loops because the SHARED
// g_job2SharedWalk is reset to 0 by JOB2-PKG-RESET on every non-RSC5 continuation
// (w247 ×14). That is the F-195/196 J2-DIST-replay <-> inflate-re-point collision, a
// whole-package source (F-249 premise refuted by F-250: 0xA0000 is a MULTI-.xsf
// container). F-251: new ordering fix — publish the UI container's real pkg via
// s_pendingUiPkg BEFORE the FDD50 call that inflates it (post-call PATHB-PKGFIX
// was 7 ms too late). ON to test whether raceeditor/others now decompress. OFF == exact baseline.
static constexpr bool kPathBEnqueueUI = true;
// F-247 dynamic serve-framing predicate: defined after g_mclaRebaseMap (~:3945).
static bool MclaIsCurrentJob2Pbase(uint32_t outPtr);
// w18: job #2 dests are the UI/swfC set only. Shared by package assigner
// (file-scope) and the inflate host-serve paths.
static bool IsJob2UiDest(uint32_t outPtr) {
  // F-247 serve-framing (route 1, gated by kPathBEnqueueUI so OFF == exact
  // baseline). Root cause PROVEN across w245/w246: the hardcoded allowlist below
  // is a snapshot that OMITS most job2 PSTREAM children. Every omitted pbase dest
  // falls to the non-job2 ForceServe → AssignPackageForDest "first unclaimed
  // rscTab entry" guess → wrong package + the stale 7 MB (destSz=7179940) inflate
  // state via the stack-keyed LastServe re-point → produced=0 livelock. w245 proved
  // it on B7881000 (×9554); hardcoding B7881000 into the list (fix#2) fixed THAT
  // one but merely moved the spin to the next omitted child B7121000 (w246) —
  // textbook whack-a-mole. FIX: derive membership dynamically from the live job2
  // rebase map so ALL current pbase dests are served. Excludes the standalone
  // .xsf containers (raceeditor B7B01000 / garage B7AC1000) that PATHB-PKGFIX
  // serves from their own archive package instead.
  if (kPathBEnqueueUI &&
      outPtr != 0xB7B01000u && outPtr != 0xB7AC1000u &&
      MclaIsCurrentJob2Pbase(outPtr))
    return true;
  switch (outPtr) {
  case 0xB7B41000u: // swfC container
  case 0xB7981000u:
  case 0xB79A1000u:
  case 0xB79B1000u:
  case 0xB7B61000u: // arr payload
  case 0xB7B71000u:
  case 0xB79C1000u:
  case 0xB7B69000u:
  case 0xB79C7000u:
  // w23: remaining job #2 PSTREAM pbase dests (REQDUMP #2 tag 0x8004
  // streamCnt=17). B7021000 spun on EA77D236 outside the old list.
  case 0xB79E1000u:
  case 0xB7001000u:
  case 0xB700F000u:
  case 0xB7021000u:
  case 0xB7041000u:
  case 0xB7061000u:
  case 0xB7081000u:
  case 0xB70A1000u:
  case 0xB70C1000u:
  case 0xB70E1000u:
  case 0xB7101000u:
    return true;
  default:
    return false;
  }
}

// w18: archive-content paths (not just UI .xsf). TOC76 finds preload.list /
// globaltex.list / .xtd the same way; their bodies never land because the
// cache/serve path excluded them.
static bool PathLooksLikeArchiveContent(const char *path) {
  if (!path || !path[0])
    return false;
  return std::strstr(path, ".xsf") != nullptr ||
         std::strstr(path, ".xtd") != nullptr ||
         std::strstr(path, ".list") != nullptr ||
         std::strstr(path, "globaltex") != nullptr ||
         std::strstr(path, "preload") != nullptr ||
         std::strstr(path, "shaders/") != nullptr ||
         std::strstr(path, "textures/") != nullptr ||
         std::strstr(path, "resources/") != nullptr;
}

static bool PathLooksLikeUiBody(const char *path) {
  return PathLooksLikeArchiveContent(path);
}

static void XsfTocCache(const char *path, uint32_t entry,
                        const uint32_t w[4]) {
  if (!PathLooksLikeUiBody(path))
    return;
  std::lock_guard<std::mutex> lk(g_xsfMtx);
  auto &e = g_xsfToc[path];
  e.entry = entry;
  for (int i = 0; i < 4; ++i)
    e.w[i] = w[i];
}

// w18: RSC5/XCompress package heads in the REAL xarchive_cache.rpf.
// Retail TOC is AES-encrypted on disk; guest TOC76 decrypts in memory but
// body Read still fails. Host-serve must use REAL package offsets, not a
// shared sequential walk that lands on junk after the first 32KB window.
struct MclaRscPkg {
  uint32_t off;
  uint32_t size; // bytes until next RSC5 (or scan cap)
};
static std::mutex g_rscTabMtx;
static std::vector<MclaRscPkg> g_rscTab;
static std::atomic<bool> g_rscTabBuilt{false};

static void BuildRscPackageTable() {
  if (g_rscTabBuilt.load(std::memory_order_acquire))
    return;
  std::lock_guard<std::mutex> lk(g_rscTabMtx);
  if (g_rscTabBuilt.load(std::memory_order_relaxed))
    return;
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  if (!vfs.OpenFile("xarchive_cache.rpf", fh)) {
    MCLA_LOG_WARN("RSC-TAB: open xarchive_cache.rpf failed");
    g_rscTabBuilt.store(true, std::memory_order_release);
    return;
  }
  constexpr uint32_t kScan = 0x2000000u; // first 32MB covers boot packages
  constexpr uint32_t kWin = 0x80000u;
  std::vector<uint8_t> buf(kWin);
  std::vector<uint32_t> offs;
  for (uint32_t base = 0; base < kScan; base += kWin) {
    uint64_t got = 0;
    if (!vfs.ReadFileAt(fh, base, buf.data(), kWin, got) || got < 16)
      break;
    for (uint32_t i = 0; i + 16 <= got; ++i) {
      if (buf[i] == 0x05 && buf[i + 1] == 'C' && buf[i + 2] == 'S' &&
          buf[i + 3] == 'R') {
        const uint32_t xc = (uint32_t(buf[i + 12]) << 24) |
                            (uint32_t(buf[i + 13]) << 16) |
                            (uint32_t(buf[i + 14]) << 8) | buf[i + 15];
        if (xc == 0x0FF512EFu)
          offs.push_back(base + i);
      }
    }
  }
  vfs.CloseFile(fh);
  for (size_t i = 0; i < offs.size(); ++i) {
    MclaRscPkg p{};
    p.off = offs[i];
    p.size = (i + 1 < offs.size()) ? (offs[i + 1] - offs[i]) : 0x40000u;
    if (p.size < 0x800)
      p.size = 0x800;
    g_rscTab.push_back(p);
  }
  MCLA_LOG_WARN("RSC-TAB: {} RSC5 packages in first {}MB; head offs "
                "{:08X} {:08X} {:08X}",
                g_rscTab.size(), kScan >> 20,
                g_rscTab.size() > 0 ? g_rscTab[0].off : 0u,
                g_rscTab.size() > 1 ? g_rscTab[1].off : 0u,
                g_rscTab.size() > 2 ? g_rscTab[2].off : 0u);
  g_rscTabBuilt.store(true, std::memory_order_release);
}

// Per-dest package cursor. Job2 UI dests stay on package @0xA0000. Other
// inflate dests each get their own unused RSC5 package — walking one shared
// cursor past the first package head was INFLATE-HOSTSERVE-STOP 6655A8B1.
static std::mutex g_destPkgMtx;
static std::unordered_map<uint32_t, uint32_t> g_destPkgOff; // dest -> file off
static std::unordered_map<uint32_t, uint32_t> g_destPkgWalk; // dest -> bytes served
static std::unordered_map<uint32_t, uint32_t> g_pkgUsed;     // off -> dest
// F-251: the UI container's real archive offset, published by the Path B hook
// JUST BEFORE it calls the guest's own sub_821FDD50. FDD50 synchronously runs
// E5C78 (record build) + the streamer inflate, so AssignPackageForDest is hit
// DURING that call — before the post-FDD50 PATHB-PKGFIX can register the dest.
// (w249 proof: raceeditor B7B01000 served 8× from the WRONG guessed 0x60000,
// PATHB-PKGFIX overwrite landed 7 ms later, then the executor starved on the
// job2 B7841000 whole-package loop and never re-served raceeditor.) The serve
// consumes+clears this for the first unclaimed 0xB7-band dest so the container
// inflates its own RSC5/XMem bytes. Gated by the caller (kPathBEnqueueUI).
static std::atomic<uint32_t> s_pendingUiPkg{0};

static uint32_t AssignPackageForDest(uint32_t outPtr) {
  BuildRscPackageTable();
  std::lock_guard<std::mutex> lk(g_destPkgMtx);
  auto it = g_destPkgOff.find(outPtr);
  if (it != g_destPkgOff.end())
    return it->second;
  // F-251: consume a Path B-published UI container package BEFORE the guess,
  // so the inflate that runs INSIDE sub_821FDD50 gets the container's real
  // archive offset instead of the "first unclaimed rscTab" meshtexture guess.
  {
    const uint32_t pend = s_pendingUiPkg.load();
    if (pend != 0 && outPtr >= 0xB0000000u && outPtr < 0xC0000000u &&
        !IsJob2UiDest(outPtr)) {
      g_destPkgOff[outPtr] = pend;
      g_destPkgWalk[outPtr] = 0;
      g_pkgUsed[pend] = outPtr;
      s_pendingUiPkg.store(0);  // one container per publish
      MCLA_LOG_WARN("DEST-PKG outPtr={:08X} -> off={:08X} (PATHB-PENDING real pkg)",
                    outPtr, pend);
      return pend;
    }
  }
  uint32_t chosen = 0;
  if (IsJob2UiDest(outPtr)) {
    chosen = 0xA0000u;
  } else {
    // Prefer an unclaimed table entry; fall back to 0x60000.
    for (const auto &p : g_rscTab) {
      if (g_pkgUsed.find(p.off) == g_pkgUsed.end()) {
        chosen = p.off;
        break;
      }
    }
    if (chosen == 0 && !g_rscTab.empty())
      chosen = g_rscTab[0].off;
    if (chosen == 0)
      chosen = 0x60000u;
  }
  g_destPkgOff[outPtr] = chosen;
  g_destPkgWalk[outPtr] = 0;
  g_pkgUsed[chosen] = outPtr;
  MCLA_LOG_WARN("DEST-PKG outPtr={:08X} -> off={:08X} ({})", outPtr, chosen,
                IsJob2UiDest(outPtr) ? "job2" : "job1/other");
  return chosen;
}

static uint32_t PackageSizeAt(uint32_t off) {
  BuildRscPackageTable();
  std::lock_guard<std::mutex> lk(g_rscTabMtx);
  for (const auto &p : g_rscTab) {
    if (p.off == off)
      return p.size;
  }
  return 0x40000u;
}

// F-297: the 4 UI .xsf archive package offsets (raceeditor / garage / policecam /
// credits). The offsets are stable; the DEST each one lands on is not, so every
// Path A host-decode site keys off the dynamically resolved package offset and
// never off a literal dest address. These offsets only ever appear as a dest
// mapping under Path B (s_pendingUiPkg / PATHB-PKGFIX), so a flag-OFF boot never
// routes through the host decoder at all.
static bool IsUiXsfPkg(uint32_t off) {
  return off == 0x64CB0000u || off == 0x64980000u || off == 0x64CA3000u ||
         off == 0x6496F000u;
}

// Read-only view of the dest -> package map AssignPackageForDest maintains.
// Deliberately does NOT call it: that would consume s_pendingUiPkg and emit
// DEST-PKG out of order, changing which dest a pending UI package lands on.
// Caller must not hold g_destPkgMtx.
static uint32_t PeekPackageForDest(uint32_t outPtr) {
  std::lock_guard<std::mutex> lk(g_destPkgMtx);
  const auto it = g_destPkgOff.find(outPtr);
  return it == g_destPkgOff.end() ? 0u : it->second;
}

// F-297: Path A bookkeeping shared by both host-decode sites. A dest is recorded
// complete only for the package it was completed with, so a later re-assignment
// (PATHB-PKGFIX overwriting a PATHB-PENDING guess) decodes again instead of
// draining outLeft over stale bytes.
static std::mutex g_uiDecMtx;
static std::unordered_map<uint32_t, uint32_t> g_uiDecDone; // dest -> pkg written
static std::unordered_set<uint64_t> g_uiDecSkip;   // (dest,pkg) -> leave to guest
static inline uint64_t UiDecKey(uint32_t dest, uint32_t pkg) {
  return (static_cast<uint64_t>(dest) << 32) | pkg;
}
enum UiDecAct { kUiDecTry, kUiDecComplete, kUiDecSkipGuest };
static UiDecAct UiDecClassify(uint32_t dest, uint32_t pkg) {
  std::lock_guard<std::mutex> lk(g_uiDecMtx);
  if (g_uiDecSkip.count(UiDecKey(dest, pkg)))
    return kUiDecSkipGuest;
  const auto it = g_uiDecDone.find(dest);
  if (it != g_uiDecDone.end() && it->second == pkg)
    return kUiDecComplete;
  return kUiDecTry;
}

// F-298: BUF-HEAD only proves the first 16 bytes of a host-decoded container
// survived in guest memory. This records a digest of the whole body at write
// time so a later one-shot readback can prove residency of all of it.
static inline uint64_t UiFnv1a(const uint8_t *p, size_t n) {
  uint64_t h = 1469598103934665603ull;
  for (size_t i = 0; i < n; ++i) {
    h ^= static_cast<uint64_t>(p[i]);
    h *= 1099511628211ull;
  }
  return h;
}
struct UiDecExpect {
  uint32_t pkg = 0;
  uint32_t unc = 0;
  uint64_t hash = 0;
  bool verified = false;
};
static std::unordered_map<uint32_t, UiDecExpect> g_uiDecExpect; // dest -> digest
static void UiDecRecordExpect(uint32_t dest, uint32_t pkg, const uint8_t *data,
                              size_t len) {
  UiDecExpect ex;
  ex.pkg = pkg;
  ex.unc = static_cast<uint32_t>(len);
  ex.hash = UiFnv1a(data, len);
  std::lock_guard<std::mutex> lk(g_uiDecMtx);
  g_uiDecExpect[dest] = ex;
}

// ---------------------------------------------------------------------------
// w20: plaintext RSC5 package preference + post-serve inflate re-force.
// Retail TOC bodies for .xtd/.xsf are AES — inflate sees zeros/stack junk.
// Prefer the known plaintext package heads in xarchive_cache.rpf.
// ---------------------------------------------------------------------------
static uint32_t MclaBE(const uint8_t *p) {
  return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) |
         (uint32_t(p[2]) << 8) | uint32_t(p[3]);
}

static bool MclaHeadLooksParseable(const uint8_t *p, uint32_t n) {
  if (!p || n < 4)
    return false;
  const uint32_t be = MclaBE(p);
  if (be == 0x05435352u || be == 0x0FF512EFu)
    return true; // RSC5 / XCompress
  if (be == 0xCDCDCDCDu || be == 0u || be == 0xFFFFFFFFu)
    return false;
  // Named list bodies start with printable tokens.
  if (p[0] >= 32 && p[0] < 127 && (n < 2 || p[1] == 0 || p[1] >= 32))
    return true;
  return false; // high-entropy AES / junk
}

static bool MclaHeadIsRscOrXc(const uint8_t *p, uint32_t n) {
  if (!p || n < 4)
    return false;
  const uint32_t be = MclaBE(p);
  return be == 0x05435352u || be == 0x0FF512EFu;
}

// TOC w2 encodes the plaintext package offset in bits [31:12] and the RSC5 header
// length in bits [11:0] (0x000A001B -> package 0xA0000, header 27 bytes;
// 0x6496F01B -> package 0x6496F000). F-171 corrected the earlier "bits [23:12]"
// reading, which could not express any package above 16 MB.
static uint32_t MclaPkgOffFromTocW2(uint32_t w2) {
  // F-171: a UI record's word[2] is (packageOffset & 0xFFFFF000) | headerLength -
  // credits.xsf's 0x6496F01B is package 0x6496F000 with a 27-byte header, and
  // the archive confirms an RSC5 header there whose ID word at +0x08 equals the
  // record's word[3] (verified for all four .xsf once the truncated local copy
  // was replaced, F-170). Two earlier limits hid this: the mask was 0x00FFF000,
  // which truncated any package above 16 MB, and table membership was required,
  // which could never hold because BuildRscPackageTable scans only kScan =
  // 0x2000000. The caller now validates the candidate (RSC5 magic AND
  // [pkg+8] == word[3]), so a wrong guess cannot be served.
  return w2 & 0xFFFFF000u;
}

static uint32_t MclaPreferredPkgOffForPath(const char *path) {
  if (!path)
    return 0;
  // Lists keep their own plaintext name bodies — never substitute a package.
  if (std::strstr(path, ".list") || std::strstr(path, "globaltex") ||
      std::strstr(path, "preload"))
    return 0;
  if (std::strstr(path, "meshtextures"))
    return 0x60000u;
  if (std::strstr(path, ".xsf") || std::strstr(path, ".xtd") ||
      std::strstr(path, "resources/ui"))
    return 0xA0000u;
  return 0;
}

// F-169: the window cap here was 0x8000, and PackageSizeAt() returns a table size
// that is also <= 0x8000 for the UI packages, so every RSC5 body was served 32 KB
// regardless of what its own header declares (F-168). Bound it by the largest
// package we actually have to carry instead.
constexpr uint32_t kPkgWindowMax = 0x400000u;  // 4 MB

// F-346: each UI .xsf container has TWO copies in this boot — the bytes we read
// out of `xarchive_cache.rpf` at a package offset, and the whole body
// `HostServeUiBody` already placed in guest memory when the file was opened.
// Nothing has ever compared them, so "the guest's decoder rejects the bytes we
// serve" and "we are reading the wrong region" have been indistinguishable for
// the whole life of Path B. w334 makes the question sharp: the same inflate
// state decoded 327,680 bytes successfully from a guest-heap source (calls
// #1..#4) and then produced 0 from 32,768 bytes of ours (call #5 onward), and
// both sources were 32,748-byte windows beginning with RSC5.
// Log-only comparator. `kUiXsfCompareGuestCopy=false` == byte-identical
// baseline behaviour.
static constexpr bool kUiXsfCompareGuestCopy = true;

// F-347: present the stream where the guest's own preamble check looks, i.e.
// serve a UI .xsf stream's first window from its XCompress sub-header
// (pkg+0x0C) instead of the container head (pkg+0), and reset the shared
// record's `consumed` so that check actually runs.
// MEASURED (w336): the mechanism is real — `XMEM-SRCHEAD #5` shows the guest
// taking its own 8-byte preamble skip on our buffer for the first time in the
// project (`src CAF28300 -> CAF28308`, `srcSz 32768 -> 32760`) — but on its own
// it moved nothing (`still_present=63072`, `first_bad=00008000`, every marker
// +0), because recognition is not what the ten-frame ceiling turns on.
// RE-ENABLED briefly by F-349 as the precondition of the whole-stream window,
// which is itself refuted (see below), so this is OFF again: it is a measured
// null on its own and the tree ships the F-346 framing. The pair
// kUiXsfStreamHeadServe + kUiXsfFrameServe is still predicted-worse
// (F-333/F-343 measured it twice) and is not being re-run.
// `false` == the F-346 serve framing byte-for-byte.
static constexpr bool kUiXsfStreamHeadServe = false;

// F-349: hand the first inflate call the WHOLE stream instead of one 32 KiB
// window. w338 seemed to pin why ten frames is the ceiling: at frame 10 — the
// first failure — `srcEnd - srcp == 4`, and `sub_82461530` computes
// `srcEnd = src + available + 4`
// (`generated/ppc_xenon/ppc_recomp.82.cpp:14906`, `:14918-14920`), so
// `available == 0`: the frame driver was handed an EMPTY source.
// TESTED (w339) AND REFUTED BY ITS OWN SUCCESS. The whole container was
// presented — `INFLATE-HOSTSERVE-PEND #32 got=1098825 headBE=0FF512EF …
// whole=1` — and frame 10 died exactly as before: same `frameoff=5698`, same
// cursor `4003C4D5` inside the context's own staging, same `srcEnd=4003C4EF`
// (available 0), same frozen `cumprod=327680`, still 10 successes in the whole
// boot. So the empty source is a SYMPTOM: by frame 10 the driver has already
// abandoned the caller's buffer and is walking from `savedcur=4003AEA9`
// (= `stagbase+0x8000`), which no amount of available input can influence.
// Worse, presenting 1 MB made the caller re-enter forever: `INFLATE-ENTER`
// 106,697 vs 4,901 and the garage's late reverify never ran at all — the
// progress-starvation shape of F-315/F-325/F-344, not a crash (every tracked
// marker +0, `C0000005` 0). `false` == the `w338` behaviour.
static constexpr bool kUiXsfWholeStreamWindow = false;
static constexpr uint32_t kUiXsfWholeCap = 0x200000u;  // 2 MB guest window

// F-350: place the host-decoded container through the guest's OWN destination
// chain instead of requiring it to fit one dest. This is the only gate that has
// ever kept the garage out of deliverable (a): `PATHB-HOSTDECODE-TOP-SKIP …
// unc=1066057 room=131072 → guest`, and the guest then decodes 5.9 % of it
// (F-326). The guest never asks for the whole container in one buffer — w338's
// healthy stream fills four dests in sequence, each exactly
// (65536, 16384, 131072, 114688 = 327,680). Distinct from F-324's list-order
// slot fill, which guessed the slot sequence from the readlist and had to skip
// any slot the guest had already touched: every write here lands on a dest the
// guest requested at this very entry, and the claim is verified by reading
// guest memory back, not by echoing the write.
static constexpr bool kUiXsfChunkedHostFill = true;

// F-356: advance the inflate record the way the guest's own post-call code does
// instead of declaring the destination finished. See the use site for the
// instruction-by-instruction basis (`ppc_recomp.18.cpp:10960-10995`) and for the
// revert condition; F-354 measured the two-destination ceiling this was aimed at.
// TESTED (w350) AND REVERTED — it does not add a destination. The chain census still
// printed exactly two (`n=1 B7A41000`, `n=2 B7AC1000`), while inflate effort tripled:
// `INFLATE 41,246 vs 17,784`, `READWRAP 27,340 vs 12,020`, `INFLATE-ENTER 13,653 vs
// 6,016`, `INFLATE-SKIP 283 vs 127` (F-344's rule: read a quality gain beside
// throughput — the durability did improve, `still_present 458,752 pct=100` vs
// 440,720/96, but for 47,388 more log lines and a 2.3x inflate rate that is the
// same shape F-349 showed becoming a livelock). Verdict that matters for task #15:
// **how we mark the record is not what bounds the chain** — the destination list is
// fixed upstream by the load request, so record-marking variants should not be
// explored further.
static constexpr bool kUiXsfChunkFaithfulAdvance = false;

// F-357: can the hook layer make the guest supply MORE than two inflate destinations for
// one UI container? Enqueue the same resource once per ~256 KiB of its decompressed length
// (bounded at 6 passes) so the loader's own descriptor builder would allocate a fresh
// destination chain per request and F-350's chunked fill would have somewhere to put the
// rest of the body. Motivated by F-354 (exactly two destinations per UI container,
// unchanged at 300 s) and F-356 (record marking is not the limiter).
// ANSWER: NO, measured twice. `sub_821FDD50` returns 0 for a repeat request and creates no
// record and no destination (`PATHB-ENQ-EXTRA #2 pass=1..4 pkg=64980000 unc=1066057
// prim=B7AC1000 ret=00000000 out=[00000000 00000000]`, w354) — and the attempt is
// otherwise COMPLETELY inert: w354 vs w351 reproduces `recs=5 recs_whole=4`, both chunk rows
// (#33 131,072/claims=1 and #64 393,216 of 1,066,057/claims=2), `claimed=458752
// still_present=440720 pct=96 first_bad=00020005`, 18 XMEM rows, `GFx` 13, W34-GFX-CENSUS 6,
// INFLATE 17,784, LISTLINE 171, Fatal 1, C0000005 0 — all +0.
// w352 (the first attempt, before the slot fix) is VOID as evidence about the loader: its
// loop shared the primary call's out slot, and FDD50 WRITES THE DESTINATION THERE (w351 and
// w354 `PATHB2 #2 path='garage/garage' … out=[B7AC1000 00000000]`), so the repeats erased
// the handle — minting the project's first `PATHB-PKGFIX-SKIP … dest=00000000`, dropping a
// record (recs 5->4), costing a chunk (393,216 -> 131,072) and turning the boot into a
// 238,679-row re-drive of destination B7841000 (18 rows in w351) that never reached the
// GFX-CENSUS rows. F-308's class; the rule it teaches is F-357b at the call site: never
// reuse a guest call's out param.
// Consequence for the objective: the ceiling is not request-side, so deliverable (a)'s only
// remaining path is the consumer that would ask again — `nGfx`=0.
static constexpr bool kUiXsfMultiEnqueue = false;

// Path -> package name-match, factored out of the PATHB-PKGPEND site so the
// comparator and the serve can never disagree. Package offsets are RPF content
// facts (verified stable in w231/w245/w249); user directive #5's ban on
// hardcoding applies to guest addresses, which stay dynamically keyed.
static uint32_t MclaUiXsfPkgForPath(const char *path) {
  if (!path)
    return 0u;
  if (std::strstr(path, "raceeditor"))
    return 0x64CB0000u;
  if (std::strstr(path, "garage"))
    return 0x64980000u;
  if (std::strstr(path, "policecam"))
    return 0x64CA3000u;
  if (std::strstr(path, "credits"))
    return 0x6496F000u;
  return 0u;
}

struct MclaUiXsfGuestCopy {
  uint32_t buf = 0u;
  uint32_t size = 0u;
};
static std::mutex g_uiXsfCopyMtx;
static std::unordered_map<uint32_t, MclaUiXsfGuestCopy> g_uiXsfGuestCopy;

static void MclaUiXsfRecordGuestCopy(const char *path, uint32_t buf,
                                     uint32_t size) {
  const uint32_t pkg = MclaUiXsfPkgForPath(path);
  if (pkg == 0u || buf == 0u || size == 0u)
    return;
  {
    std::lock_guard<std::mutex> lk(g_uiXsfCopyMtx);
    g_uiXsfGuestCopy[pkg] = MclaUiXsfGuestCopy{buf, size};
  }
  MCLA_LOG_WARN("UIXSF-GUESTCOPY-REG pkg={:08X} buf={:08X} size={} path='{}'",
                pkg, buf, size, path);
}

// Compare the window just read from the archive against the guest's own copy at
// the same package offset. Bounded to 6 lines per package so it cannot repeat
// the w298 flood; a recycled guest buffer stays interpretable because the
// guest's head word is printed alongside.
static void MclaUiXsfCompareGuestCopy(uint32_t n, uint32_t pkg, uint32_t walk,
                                      const uint8_t *ours, uint32_t len) {
  if (!kUiXsfCompareGuestCopy || pkg == 0u || len < 16u)
    return;
  uint32_t buf = 0u, size = 0u;
  {
    std::lock_guard<std::mutex> lk(g_uiXsfCopyMtx);
    const auto it = g_uiXsfGuestCopy.find(pkg);
    if (it == g_uiXsfGuestCopy.end())
      return;
    buf = it->second.buf;
    size = it->second.size;
  }
  static std::mutex s_cntMtx;
  static std::unordered_map<uint32_t, uint32_t> s_cnt;
  uint32_t seen = 0u;
  {
    std::lock_guard<std::mutex> ck(s_cntMtx);
    seen = ++s_cnt[pkg];
  }
  if (seen > 6u)
    return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (buf == 0u || walk >= size || !mem.IsValid(buf + walk, 4))
    return;
  uint32_t cmp = size - walk;
  if (cmp > len)
    cmp = len;
  std::vector<uint8_t> theirs(cmp, 0u);
  if (!mem.ReadBytes(buf + walk, theirs.data(), cmp))
    return;
  uint32_t diff = 0u, first = cmp;
  for (uint32_t i = 0u; i < cmp; ++i) {
    if (theirs[i] != ours[i]) {
      ++diff;
      if (i < first)
        first = i;
    }
  }
  uint32_t oh1 = 0u, gh1 = 0u;
  if (first + 4u <= cmp) {
    oh1 = static_cast<uint32_t>((ours[first] << 24) | (ours[first + 1] << 16) |
                                (ours[first + 2] << 8) | ours[first + 3]);
    gh1 = static_cast<uint32_t>(
        (theirs[first] << 24) | (theirs[first + 1] << 16) |
        (theirs[first + 2] << 8) | theirs[first + 3]);
  }
  MCLA_LOG_WARN("UIXSF-GUESTCOPY #{} pkg={:08X} walk={:08X} cmp={} diff={} "
                "firstdiff={} match={} ours_at_first={:08X} "
                "guest_at_first={:08X} guest_head={:08X} guest_buf={:08X} "
                "guest_size={}",
                n, pkg, walk, cmp, diff, first, diff == 0u ? 1 : 0, oh1, gh1,
                MclaBE(theirs.data()), buf, size);
}

// F-183: serve an RSC5 member from its XCompress sub-header (RSC5+0x0C)
// instead of the container head, so the guest's own magic check sees the
// stream it documents. Flip to false to restore the container-head framing.
static constexpr bool kServeFromXCompressHead = false;

// F-188: host-side LZX decode via libmspack instead of guest 0x82461530.
// Eliminates guest-state dependency for UI container decompression.
// F-190 control (w204, kHostLzxDecode=false) also hit RD-SUBMIT=4 — TOC stall
// is environmental (F-123), not this switch.
// F-191 DISABLED: an offline harness (tools/lzx_raceeditor_proof.c) proved libmspack's
// CAB-LZX decodes raceeditor.xsf only to 131072 B (4×32KiB) then rc=11 under EVERY
// strategy/window — XMem LZX != CAB LZX. w207 (fresh build) confirms XSF-LZX ok=0,
// XSF-LZX-FAIL=23. Path A is inert; turned off so it cannot stack with Path B (do-not #9).
static constexpr bool kHostLzxDecode = false;
// XCompress codec=1 window size in bits (17 = 128KB, standard for Xbox 360).
static constexpr int kXcWindowBits = 17;

// F-295: Path A host XMem/raw-LZX decoder (src/xmem_lzx.h), proven byte-exact
// offline against build/xmem_golden/*.bin for all 4 UI .xsf (no guest VM
// re-entry, so free of the F-288/290 corrupt-serve context conflict). ON by
// default (user decision 09-25): at the corrupt-serve UI block and the unified
// four-dest hook, decode the loaded package host-side and write the FULL
// container into the guest dest, then drain outLeft so the guest's partial
// inflate is bypassed. Set false to restore exact baseline.
static constexpr bool kPathBHostFullDecode = true;

// T41.9 / F-191 Path B: after sub_821E2940 opens a UI .xsf container, re-issue the
// async ENQUEUE the way sub_821E5F48 does. E2940 already runs E5C78(record builder)+
// BCE68(pgStreamer::Open)+BC7A0(metadata) (ppc_recomp.20.cpp:25180/25194/25218) but
// never calls E5E58 (enqueue) — the sole missing step (F-186). We rebuild the record
// via E5C78 (same args) and call E5E58 so the GUEST's own XMemDecompress inflates it.
// F-192 OFF: enqueue SUCCEEDS (E5E58 returns a slot; INFLATE 45->47210, the pipeline
// wakes) but E5C78's record is NOT the correct E5E58 `D` layout descriptor — the
// executor livelocks producing=0 (magic=8BE44DA1) and boot never reaches W34. The
// true `D` must be captured from a working meshtexture request (see F-192 next step).
// F-192 v2: switched to calling the guest's own sub_821FDD50 async helper with the
// container's E2940 args so the GUEST builds I/D/ctx. v2 CONFIRMS the enqueue gap is
// closed (FDD50 returns real handles, streamer slots advance 0->0x8001..3, C0000005=0),
// but the guest inflate then livelocks (INFLATE 45->44870, produced=0, magic bad) ->
// boot never reaches W34. So the blocker MOVED from "enqueue" to "UI serve data is
// undecodable" (F-181/182/183 data-serve). OFF to avoid the livelock regression (F-193).
// F-194: with kInflateIntervene=false the loop vanished (re-point was the loop cause,
// not the enqueue) but the guest's OWN inflate rejected the UI bytes ('not in XCompress
// format') and meshtextures collapsed too — the remaining blocker is SERVE FRAMING,
// fixable only in the dense re-point stack (peer-owned). Kept OFF (safe baseline) until
// serve framing is fixed with the re-point still ON for meshtextures.
// F-195 test: ON with kUiServeAdvance so the re-point stream advances and terminates.
// F-195 RESULT: the j2BadMag pos-advance did NOT break the w214 loop — the runaway
// inflate carries j2=0 (NOT IsJob2UiDest) + the hard-coded destSz=7179940/srcSz=7179936
// of the peer's OWN McLaJob2/J2-DIST XMem replay (F-172 "our own replay, not guest").
// So the loop is in the J2-DIST replay machinery, a different host-side stack than the
// j2BadMag re-point. Reverted to OFF (safe baseline). Path B enqueue itself is proven
// good (F-193); the residual is the peer's J2-DIST replay not terminating.
// T41.9b test: ON with kJ2DistReplay=false — Path B enqueue + no J2-DIST collision.
// F-196 RESULT: disabling J2-DIST did NOT break the loop (w220 INFLATE still 44802,
// src=CAB28300/destSz=7179940) — that replay comes via the kInflateIntervene re-point
// (INFLATE lr=821BC380), not J2-DIST. No toggle combo works → the enqueued UI record
// does not self-advance in the guest streaming executor (F-181). Reverted to OFF.
// F-198 diagnostic ON to dump the enqueued record[+4].
// F-199: single-open ALSO gives +4=0 → the 0-length is intrinsic to FDD50/E5DC8's
// BCE68 open (r4=0, different E5C78 record). F-200 FIX: pass the STATIC resource-id
// arg0 (captured from E2940's internal E5C78) to FDD50, not the heap pathPtr.
// F-200b (w226) NEGATIVE: capture misfired (arg0used=CDCDCDCD→fell back to pathPtr);
// AND legals (works) uses resource-id "legals" (arg0=0x8EFFF1C0) not the heap path,
// plus double-open re-creates a 0-length record anyway (F-198). Reconstructing the
// exact async request (resource-id string + no double-open) is a multi-layer F-187
// descriptor problem in the peer's active streaming code → REVERTED to OFF.
// F-201: single-open + copied path string STILL gives +4=0 (w229) → these 4 are NOT
// async-loadable resources; the async builder resolves their length to 0 regardless
// of string form. Path B via FDD50/async is fundamentally blocked for them (F-187).
// F-204 (2026-09-25, w231): tested exactly this. Enabling the post-open double-open
// FDD50 path produced CORRECTLY-SIZED enqueued records (raceeditor +4=0x22EDD=143069,
// garage 0x104449, policecam 0x4B89, credits 0x73D7, all with valid pkgoff 64CB0000/…)
// — refuting F-186/198/201's "the blocker is the zero-length record" premise. Yet the
// soak REGRESSED: INFLATE 361→47,182 (the XMEM `src=CAB28300` semaphore-handle livelock
// = F-195/197 signature), GFx census 5→1, W34-GFX-CENSUS/W34-NOGFX 2→0, FATAL-SOFT 0→1.
// So the correctly-sized record is NOT sufficient: the guest streaming executor livelocks
// on the peer's `kInflateIntervene` re-point (F-194/196/201), which is load-bearing and
// peer-owned. Path B via FDD50 double-open is CONFIRMED DEAD. (arg0used=CDCDCDCD → the
// static-arg0 capture never fires through __imp__ E2940, so the "correct static arg0"
// single-request variant remains untested; it is a separate hook fix and, per the above,
// not expected to change the livelock outcome.) Reverted to OFF.
// F-204b (2026-09-25 01:40): re-tested OFF after the un-confounded single-request
// (w232) + record[+4]-seed (w233) experiments. Both livelocked identically to the
// double-open (w231): INFLATE ~48K on `XMEM src=CAB28300`, GFx 5→1, W34→0, FATAL-SOFT+1.
// w232 proved the async FDD50 open CANNOT size record[+4] even with the EXACT static
// arg0 (+24 pkgoff resolves, +4 stays 0). w233's seed never fired because the executor
// is stuck on the CAB28300 re-point UPSTREAM of the UI record → +4 is not the blocker.
// Path B host-hook enqueue is CONFIRMED DEAD; the residual is the peer's kInflateIntervene
// re-point (load-bearing, do-not #9). Stays OFF.
// F-247 (authorized route 1): root cause found — AssignPackageForDest serves the 4 UI
// containers the WRONG package (w231 DEST-PKG B7B01000 -> off=00060000=meshtextures,
// not their real record +24 pkgoff), so the guest inflate reads non-XCompress bytes and
// the re-point re-serves the CAB28300 bounce forever. The Path B hook now registers each
// dest's TRUE archive offset (PATHB-PKGFIX) to pre-empt the guess. ON to test the fix.
// (Definition hoisted to :77 so IsJob2UiDest can gate the job2 pstream-allowlist fix.)

// F-200 v4 uses the E2940 open (runs first, captures arg0) THEN FDD50 with the
// captured static arg0 — so single-open stays OFF (we need E2940 to run to capture).
// F-201: single-open WITH copied path string (no capture-timing bug). Reverted OFF.
// F-204b: re-tested via hardcoded static arg0 (w232) — +4 STILL 0. Stays OFF.
static constexpr bool kPathBSingleOpen = false;

// F-195: advance the j2BadMag LastServe pos by the guest's previous consumed amount so
// enqueued UI inflate streams forward instead of re-serving sbuf+0 (the w214 INFLATE
// #2.2M loop). Scoped to IsJob2UiDest serves. Revert with Path B if it regresses.
// F-195: ineffective — the loop is the J2-DIST replay (j2=0), not the j2BadMag path.
// F-315: that "ineffective" verdict was measured on the ls0/j2BadMag leg only. The
// MclaFindLastServe leg (:8065) had the same never-written-back defect and is the one
// every INFLATE-REFORCE pos=00000000 line comes from, so it is being tried there.
// F-315 RESULT: tried ON in w275 and it LIVELCKED — 657,657 lines vs w274's 57,886.
// REVERTED to false; the advance code stays, gated off.
// F-318 SUPERSEDES the F-315 diagnosis of WHY (both halves of it were wrong):
//  (1) The w275 loop was NOT the garage and NOT "the same 512 bytes": its dominant
//      shape was 119,403x "INFLATE #n st=006D8F20 in=15 out=65536 consumed=196553
//      magic=03EE0509" on pkg 0xA0000 (meshtextures) — and the printer's own counter
//      reached #10,956,600, so ~11 MILLION guest inflate calls happened and only the
//      first 40 + every 200th got printed.
//  (2) st+8 "consumed" is CUMULATIVE for the stream, not per-call: w276 garage shows
//      32748 -> 65516 (exactly two 32 KiB chunks) and w275 shows +20 per call. So
//      "ls.pos += consumed" double-counts and runs the cursor away.
//  (3) Worse, the advance was never NEEDED. MclaForceServePkgForDest registers
//      ls.pos=0, ls.size=n (:7740-7741) for ONE window, so "srcOff >= srcSize" is
//      already the correct "this chunk is exhausted, give me the next one" signal,
//      and the absolute position is carried by g_destPkgWalk, not ls.pos. Leaving
//      ls.pos pinned at 0 is what makes ls.pos+consumed an absolute offset.
// The advance was never the gap; see F-318 and kUiXsfChunkFeed below.
static constexpr bool kUiServeAdvance = false;

// F-318: garage's UI .xsf is aborted by our OWN empty-stream bail, not by serve
// framing. w276/w277 evidence, dest B7A41000 -> pkg 64980000 (unc 1066057):
//   INFLATE-ENTER #32  in=0 consumed=32748 outPtr=B7A41000
//   INFLATE-HOSTSERVE-PEND #32 got=32768 walk=00000000 pkgSz=00040000 serve=1
//   XMEM-SZPTR #5      *destSz 131072->0  *srcSz 32768->32768  ret=0
//   INFLATE-ENTER #34..#42 in=0 consumed=65516 outPtr=B7A41000   (nothing served)
//   INFLATE-J2-DRAIN-B7 #12 "... — zero outLeft (backup)" -> FLUSH sub_821D5510
// The refill at :8760ff already walks g_destPkgWalk one 32 KiB window per call and
// has its own CAP/DONE bounds, but hsThisRetry fires ONLY on retries==3 (once per
// st) and maxEmptyRetries is 24 when produced>0 — and produced is a LEFTOVER of a
// previous dest in this shared stack state (the w10 comment says so for the
// hardcoded needArrData trio). So a UI .xsf dest can never get window #2 and is
// then killed as "dead". ON = treat a dynamically-keyed UI .xsf dest as a live
// mid-stream: refill every empty retry while walk < PackageSizeAt, and give it the
// 400-retry budget. OFF == exact baseline. Census marker: INFLATE-HOSTSERVE-PEND
// serve=N per dest (no new literal).
// F-341 tested OFF and it is back to ON: with the refill disabled the garage is still
// 63,072 (w326_1/_2, LOCATE 0 / PEND 2 confirming the mode) and raceeditor stays
// 143,069/143,069, so the interference lead is refuted and there is no POSITIVE reason
// to move a shipped default on two 120 s soaks -- what the experiment established is
// that this serve is inert with respect to the deliverable, which is itself the result.
static constexpr bool kUiXsfChunkFeed = true;

// F-329: also construct the descriptor field the guest actually clamps on.
// `sub_821D5E10` (generated/ppc_xenon/ppc_recomp.18.cpp:10832+) limits every
// XMemDecompress call's input to ([st+12] - [st+8]) — `expected` minus
// `consumed`. w302 shows why that matters: on the garage stream `exp` is
// 0x0002FFC9 = 196,553 and CONSTANT across five successive entries while
// `consumed` runs 32,748 -> 163,820, i.e. the field is a STALE leftover of the
// shared stack state 006D8F20 (whose previous owner was the pkg 0xA0000 walk,
// which stalled at exactly that value in w277), and neither ForceServe nor the
// refill ever writes st+12. The container declares its real total at pkg+0x10
// (0x00104449 = 1,066,057 for garage, read from the RPF in w297's header dump),
// so the honest descriptor value is available. ON = publish it when serving a UI
// .xsf stream. OFF == the exact w302 behaviour.
static constexpr bool kUiXsfSetExpected = true;

// F-319: the tail top-up that goes with kUiXsfChunkFeed. OFF — it addressed the
// wrong resource. See the block at the `inLeft > 0 && inLeft < 256` UNSTUCK site
// for the full diagnosis: the leftover there means the dest window is OUTPUT-full,
// so more input only spins (w280: 704,373 lines vs w279's 57,892).
static constexpr bool kUiXsfTailTopup = false;

// F-333: the frame driver resumes a PARTLY-CONSUMED frame from its OWN state,
// not from the src we hand it. sub_82461010 takes `cursor = src` only while
// [S+12280] == 0 (generated/ppc_xenon/ppc_recomp.82.cpp:14181-14184 jumps to
// loc_8246117C at :14286-14288), and [S+12280] is a byte offset inside the
// current frame — the code computes a frame's total length as
// `headerLength + payload` and stores it there (:14248-14277, :14409-14410).
// A stale non-zero value from whatever stream last used this shared ctx sends
// the walk to the saved cursor [S+12276] in a DIFFERENT buffer, and the call
// then consumes 0 input, writes 0 output and returns S_OK: build/w306.log
// XMEM-SZPTR #5..#12, eight identical `srcSz(in)=32768 srcSz(out)=32768
// destSz(out)=0 ret=0` lines for the garage. Our own W27 driver has always
// soft-reset this exact range before driving the same function
// (src/gpu_device.cpp:5045-5049); the guest-driven path never got that
// treatment. ON = clear the resume latch when we install a frame-aligned
// window for a UI .xsf stream.
// F-333 MEASURED: ON with kUiXsfFrameServe ON = w307, garage coverage
// 63,072 → 43,732 and ~89,000 failing frame decodes. The latch is real, but
// clearing it is the wrong use of that knowledge: the decoder is one CONTINUOUS
// bit stream, so the correct move is to leave `src` where the guest put it and
// extend the buffer in place. Keep OFF until that is what is being tested.
static constexpr bool kUiXsfClearResume = false;

// F-334 (MEASUREMENT ONLY, writes nothing): where in the package IS the guest's
// buffer? F-333 closed "move src and reset the driver's position" by showing the
// LZX decode is one continuous bit stream, so the surviving Path B design is to
// extend the buffer the guest already points at — and that is only possible if
// the guest-address ↔ package-offset mapping is *known*. Every serve so far has
// ASSUMED it from our own walkPos. This reads 48 bytes at the stream's current
// `inPtr`, finds that byte string inside the package image, and prints how far
// our bookkeeping is from it. One number decides whether the data is missing or
// our position model is wrong.
static constexpr bool kUiXsfLocate = true;

// F-335: give each UI .xsf stream ONE append-only input window sized for its whole
// container, and after installing it move only `st+0` — never `st+4` again (plan
// §5 step 1b). The serve otherwise rewrites the same host buffer from offset 0
// while walkPos advances, which is exactly what F-333 showed breaks the frame
// driver's absolute-position bookkeeping. If the window cannot be built or the
// cursor leaves it, this returns false and the legacy path runs unchanged.
// F-335 MEASURED = false: the window opens (cap 1,098,825 at CAF28300) and appends
// cleanly, but on the NEXT call the guest's `st+4` is back to `st + 0x20` (its own
// stack scratch, exactly what F-334 found), so `inside` is false and the code
// re-points anyway — continuity across calls is not available to any buffer
// design. w311: 682,178 log lines vs 58,217, INFLATE-ENTER 109,072 vs 4,901,
// cumprod still frozen at 327,680, and `UIXSF-GOLDEN-REVERIFY pkg=64980000`
// printed ZERO times (10 reverify lines total vs w310's 12, none for the garage,
// i.e. the boot stopped sampling the container it was supposed to measure).
// Reverted; the surviving candidate is a per-stream re-init of the codec ctx
// (sub_82460F88 / sub_82461840), not another window shape.
static constexpr bool kUiXsfAppendWindow = false;

// F-337: open a PRIVATE codec context per UI .xsf stream (plan step 1c). F-336
// measured the whole cause: two Open calls in an entire boot (r5 = 4000FD80 and
// 400446C0, ~215 KB apart) against 4,901 inflate entries, so every container
// decodes into a context whose walk state and history belong to whatever ran
// before it. That is why six serve designs moved `consumed` and none moved
// correct output. The replay below is the exact observed call:
//   sub_82461378(r3 = 0x8EFFF990 owner, r4 = 1 flags, r5 = block, r6 = 0x3492E)
// and r7 is live at the call but never read by the wrapper
// (generated/ppc_xenon/ppc_recomp.82.cpp:14611-14650). obj+0 is republished on
// every refill because F-335 §2 showed the caller re-arms the record between
// calls. Known hazard, named rather than hidden: this calls guest code from
// inside a guest hook, which is the re-entrancy that collapsed boot depth ~3x
// once before (F-285/286) -- here it is at most four calls per boot.
// F-337 MEASURED = false: the republish works (obj=0x8283D1B0 held *obj =
// 0x4000FD80 and took the private ctx), and the boot then DIED 6 ms later --
// 27,760 log lines vs 58,119 and INFLATE-ENTER 32 vs 4,901, with no fault line
// and no garage reverify sample at all. The prime suspect is named rather than
// guessed around: mem.Alloc(0x35000) returned 0xCAF28300, which is the SAME
// address the XSF serve window uses in w310/w315, so the frame driver was
// writing its input over its own context (or vice versa). Before this is
// retried, the private ctx must be allocated in a block that cannot alias the
// serve buffer and the aliasing checked, not assumed away.
// F-338 MEASURED = false, and it corrects F-337 §4: the collapse was NOT the
// allocation aliasing. With the context placed in the second half of a doubled
// allocation (raw=CAF28300..CAF92300, ctx=CAF5D300) the serve windows were at
// C8A0xxxx -- provably disjoint -- and the boot still stopped progressing 6 ms
// after the republish (w318: 27,810 lines vs w317's 58,764, INFLATE-ENTER 32 vs
// 4,901, one reverify line, no fault line). The reason is in the slot itself:
// obj = 0x8283D1B0 is a per-JOB record (F-323 showed vbase is per-job), so
// republishing its +0 hijacks every stream in that job, including the ones that
// were decoding fine. A per-stream context therefore needs its own object, i.e.
// the enqueue side (task #15), not a serve-side rewrite of a shared slot.
// F-339 MEASURED = false, and it closes this avenue rather than the hypothesis:
// there is no per-stream handle to key a publish/restore on. st (006D8F20, F-329/F-334)
// AND obj (0x8283D1B0, F-338) are BOTH per-JOB records, and the four UI containers are
// multiplexed through that one record by the guest job loop (sub_821BC140 walks
// 28-byte descriptors inside the job). w320 proves it directly: publish fired 0 times
// and restore fired 0 times, because every entry that reached this code found priv != 0
// for its own st -- the garage's private context had become the whole job's context.
// A private context per stream therefore needs a per-stream RECORD, i.e. re-plumbing
// the streamer's job loop (task #15), not another hook intervention.
static constexpr bool kUiXsfPrivateCtx = false;

// F-340: SERIALISE the shared codec context instead of trying to own a private one.
// The reason this is now possible: the "obj" the inflate hook receives as r3 is
// 0x8283D1B0, and the streamer job loop computes it as `lis r10,-32124; addi
// r19,r10,-11888` -> 0x8283D190, i.e. obj is **one global field at +0x20 of the
// streamer object**, not a per-record allocation (ppc_recomp.14.cpp:18844-18874,
// where the same r19 also holds the descriptor count at +24 and the 28-byte
// descriptor array base at +52). So there is exactly ONE codec context for the whole
// streamer, which matches F-336 (two opens per boot) and explains F-339 (per-job
// records): the guest serialises streams through one context by construction, and we
// interleave them because our serve makes every stream ready at once.
//
// The intervention therefore is not a new context; it is letting ONE container finish
// before another touches the shared one. Ownership is keyed on the container's package
// offset (per-container, dynamic-dest-safe per user directive #5), and a non-owner is
// refused a refill for a bounded number of entries -- it has no input, so its frames
// cannot advance the shared context's walk state. The cap exists so this can never
// become the F-315/w275 kind of unbounded livelock: after kUiXsfCtxStallCap stalls for
// a given package, ownership is released and the legacy path resumes.
// F-340 MEASURED = false. w323 (this binary, block active: 7 UIXSF-CTX-OWNER lines)
// left every frontier number at baseline -- garage still_present 63,072, cumprod 917,504,
// failtotal 5,279 -- so deferring non-owner containers does not un-corrupt the shared
// context. It also exposed something bigger than the fix: the SAME binary produced
// still_present=121,946 in w322, i.e. this metric has a cross-boot spread that F-326's
// five within-boot samples never measured. Any coverage claim now needs a same-binary
// repeat soak beside it (see F-340 §3), which retroactively qualifies F-333's 43,732 as
// possibly-noisy (its failtotal=89,483 vs ~5,280 is the part that was never noise).
static constexpr bool kUiXsfSerializeCtx = false;
static constexpr uint32_t kUiXsfCtxStallCap = 40u;
static std::mutex g_uiXsfOwnerMtx;
static uint32_t g_uiXsfCtxOwner = 0;  // pkg offset holding the context
static std::unordered_map<uint32_t, uint32_t> g_uiXsfStalls;  // pkg -> stalls

// F-342: a context per PACKAGE, published per entry from the entry's own destination.
// F-339 failed because it keyed the publish on `st`, and `st` is the job's record, so
// every stream of the job got the one private context and the healthy ones died. The
// destination is per slot and the package binding of a destination is per container, so
// keying on the package gives the isolation F-339 was reaching for without starving or
// hijacking anything: each entry publishes its own container's context, and any entry
// that is not a UI .xsf container gets the guest's original shared context back.
// Contexts are created by the guest's own Open replay (F-337 §2: r7 unread, r6 = the
// size) and capped so this cannot exhaust the guest heap; the shared value is captured
// before the first swap and is the only thing ever restored.
// F-342 MEASURED = false, and it is the strongest of the three negatives: publishing
// the slot per entry, keyed on that entry's own package binding (not on the per-job st
// that defeated F-339), opens one private context for the garage and swaps it in -- and
// the UI decode then stops entirely: 27,467 lines vs 57,685, INFLATE-ENTER 32 vs 4,901,
// and LZX-FRAME failtotal 0, i.e. not one frame decoded after the swap, rather than
// frames failing. The slot at 0x8283D190+0x20 is therefore the streamer object's own
// current-context field, read by the job loop outside the inflate call as well; anything
// that writes it corrupts the streamer, not just the decode. Task #15 has to construct
// the (record, context) pair at the source instead of redirecting this global.
static constexpr bool kUiXsfPerPkgCtx = false;
static std::mutex g_uiXsfPkgMtx;
static std::unordered_map<uint32_t, uint32_t> g_uiXsfPkgCtx;  // pkg -> private ctx
static std::atomic<uint32_t> g_uiXsfOrigCtx{0};

// F-344: hold the shared codec context by not letting another container's INFLATE CALL
// run, instead of withholding its bytes. F-340 deferred non-owner refills and F-341 then
// showed the refill is inert for the outcome -- so F-340's null never tested the idea.
// What actually mutates the context's walk state is the call into sub_8244FF20, so this
// skips the guest call itself for entries whose destination binds to a UI .xsf package
// other than the current owner, and returns the benign "consumed nothing" (r3 = 0, no
// state touched). Ownership rotates after kUiXsfHoldOwnerEntries of the owner's entries
// so a blocked container is guaranteed to be served eventually -- this cannot livelock.
// F-344 MEASURED = false, and it catches a trap worth recording: the first run looked
// like the session best result (failtotal 6 against a ~5,280 baseline) but that was only
// because the livelocked boot completed 40 inflate entries in 120 s -- fewer frames, not
// better ones, and cumprod had not passed the baseline either. With the bounded handover
// the mechanism engages 5 times, hands over 0 times, and every frontier number is exactly
// baseline (garage 63,072, raceeditor 100 %, cumprod 884,736, failtotal 5,280). So
// container contention on the shared context is NOT what costs the garage its frames --
// which removes the last hook-layer mechanism on the list.
static constexpr bool kUiXsfHoldCtx = false;
static constexpr uint32_t kUiXsfHoldOwnerEntries = 400u;
static std::atomic<uint32_t> g_uiXsfHoldOwner{0};
static std::atomic<uint32_t> g_uiXsfHoldCount{0};
static std::atomic<uint32_t> g_uiXsfHoldBlocked{0};
// F-344b: w332 blocked 1,161,883 times in 120 s -- a livelock of exactly the F-315/w275
// shape, because the cap was only on the OWNER's entries and a blocked container's job
// loop re-calls inflate immediately. Ownership now also rotates on a run of consecutive
// blocks against the same package, so no container can be starved for more than
// kUiXsfHoldMaxRun calls.
static std::atomic<uint32_t> g_uiXsfHoldLast{0};
static std::atomic<uint32_t> g_uiXsfHoldRun{0};
static constexpr uint32_t kUiXsfHoldMaxRun = 24u;

// F-343: the one combination F-333 never ran. F-333 cleared the frame driver's resume
// pair once, at refill time, and coverage moved the wrong way -- but F-335 then
// established that the caller RE-ARMS the inflate record on every call, so a clear that
// happens once is stale by the second window. This clears the driver's walk state
// (saved cursor S+12276, byte-offset-into-frame S+12280, and the undrained-staging count
// S+12272) on EVERY entry whose destination binds to a UI .xsf package, which is what
// "start this call's window as a fresh frame walk" has to mean given the re-arming.
// Paired with kUiXsfFrameServe (windows that begin on real frame headers), that is the
// full contract: src at a frame boundary + the driver told to believe it.
// Unlike F-337/338/342 this writes no context pointer, only the walk fields the driver
// itself re-initialises, so it cannot halt the streamer.
// F-343 MEASURED = false, and it reinstates F-333's conclusion on better evidence. The
// per-entry clear does exactly what F-333's install-time clear could not (by entry #3 the
// driver's frame offset is already 0 and stays clean), and the outcome is the same as
// w307's to the byte: garage coverage 43,732, cumprod DOWN to 196,608 from 917,504,
// failtotal 70,483 vs ~5,280, INFLATE-ENTER 14,293 vs 4,901. Two independent
// configurations 17 soaks apart both landing on 43,732 -- with co-signals far outside the
// F-341 noise band -- means F-333's revert was right after all, and the reason is now
// clear: [S+12280]/[S+12276] are the continuous bit stream's real position, so erasing
// them makes the driver re-walk frames it has already consumed and lose sync. The walk
// state must be RESPECTED, not cleared -- which, with F-342 (it cannot be isolated),
// leaves only task #15.
static constexpr bool kUiXsfClearResumeEvery = false;
static std::mutex g_uiXsfPrivMtx;
static std::unordered_map<uint32_t, uint32_t> g_uiXsfPrivCtx;  // st -> private ctx
// F-339: the publish/restore pair. g_uiXsfSharedCtx is the value the slot held
// before we ever touched it (0x4000FD80 in every soak), and g_uiXsfPrivSet is the
// set of contexts WE created -- a restore is only allowed onto one of ours, so a
// record that legitimately holds the guest's other real context (0x400446C0) is
// never overwritten.
static std::atomic<uint32_t> g_uiXsfSharedCtx{0};
static std::unordered_set<uint32_t> g_uiXsfPrivSet;

// T41.9b / F-195: the legacy host-side J2-DIST XMem replay of pkg 0xA0000. Path B
// (correct guest enqueue) replaces its purpose; with Path B ON this replay only
// collides (the INFLATE #2.2M loop carries its 7179940 constants). Disabled by
// default while testing Path B; restore to true if meshtextures depend on it.
// F-196: J2-DIST-off did NOT break the loop (it's via the re-point, not J2-DIST).
// Kept true = the function's original always-on behavior (gate preserved, inert).
static constexpr bool kJ2DistReplay = true;

// F-168: an RSC5 package states its own UNCOMPRESSED length. Layout, verified
// against xarchive_cache.rpf on three packages (legals.xsf @0xA0000 hdrLen 27 ->
// 196,553; meshtextures.xtd @0x60000 hdrLen 9 -> 240,531; trash.xrn @0x35A000
// hdrLen 66 -> 10,799):
//   +00 0x05435352 "RSC5" | +04 header length | +08 package ID (== the TOC
//   record's word[3]) | +0C 0x0FF512EF (Xcompress) | +10 uncompressed length
// Returns 0 when the buffer is not a header we can trust, so callers keep the
// size they already had.
static uint32_t MclaRsc5DeclaredSize(const uint8_t *p, uint32_t n) {
  if (!p || n < 20)
    return 0;
  if (MclaBE(p) != 0x05435352u || MclaBE(p + 12) != 0x0FF512EFu)
    return 0;
  const uint32_t sz = MclaBE(p + 16);
  return (sz >= 0x20u && sz <= kPkgWindowMax) ? sz : 0;
}

static bool MclaLoadPkgWindow(uint32_t fileOff, uint32_t walk, uint32_t want,
                              std::vector<uint8_t> &out) {
  BuildRscPackageTable();
  const uint32_t pkgSz = PackageSizeAt(fileOff);
  if (walk >= pkgSz + kPkgWindowMax)
    return false;
  uint32_t n = want ? want : 0x8000u;
  if (n > kPkgWindowMax)
    n = kPkgWindowMax;
  if (walk + n > pkgSz + kPkgWindowMax)
    n = (pkgSz + kPkgWindowMax > walk) ? (pkgSz + kPkgWindowMax - walk) : 0;
  if (n < 16)
    return false;
  out.resize(n);
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  if (!vfs.OpenFile("xarchive_cache.rpf", fh))
    return false;
  uint64_t got = 0;
  const bool ok = vfs.ReadFileAt(fh, fileOff + walk, out.data(), n, got) &&
                  got >= 16;
  vfs.CloseFile(fh);
  if (!ok)
    return false;
  out.resize(static_cast<size_t>(got));
  const uint32_t be = MclaBE(out.data());
  if (walk == 0 && be != 0x05435352u && be != 0x0FF512EFu)
    return false;
  return true;
}

// Last successful CC6F0 serve, keyed by inflate-state address and dest so the
// inflate hook can re-point st+0/st+4 after the guest clobbers them to stack.
struct MclaLastServe {
  uint32_t sbuf = 0;
  uint32_t pos = 0;
  uint32_t size = 0;
  uint32_t stCand = 0;
  uint32_t dest = 0;
  uint32_t want = 0;
  uint32_t head = 0;
  uint32_t srcPkg = 0; // nonzero when bytes came from plaintext RSC5 table
  std::string path;
};
static std::mutex g_lastServeMtx;
static std::unordered_map<uint32_t, MclaLastServe> g_lastServeBySt;
static std::unordered_map<uint32_t, MclaLastServe> g_lastServeByDest;

static void MclaRecordLastServe(const MclaLastServe &ls) {
  if (!ls.sbuf || !ls.size)
    return;
  std::lock_guard<std::mutex> lk(g_lastServeMtx);
  if (ls.stCand)
    g_lastServeBySt[ls.stCand] = ls;
  if (ls.dest)
    g_lastServeByDest[ls.dest] = ls;
}

static bool MclaFindLastServe(uint32_t st, uint32_t dest,
                              MclaLastServe *out) {
  if (!out)
    return false;
  std::lock_guard<std::mutex> lk(g_lastServeMtx);
  if (st) {
    auto it = g_lastServeBySt.find(st);
    if (it != g_lastServeBySt.end() && it->second.sbuf) {
      *out = it->second;
      return true;
    }
  }
  if (dest) {
    auto it = g_lastServeByDest.find(dest);
    if (it != g_lastServeByDest.end() && it->second.sbuf) {
      *out = it->second;
      return true;
    }
  }
  return false;
}

// Stamp the inner page-cache slots (inner+296 + slot*40) so the guest's own
// buffered reader sees the host-served window instead of an empty miss.
// w20 soak: WRITE disabled — slot+4 looked like capacity (0x8000) not
// valid-bytes; overwriting it may prevent the inflate caller from running.
// Census only; dest copy + LastServe re-force carry the delivery.
static void MclaStampPageCache(uint32_t inner, uint32_t filePos, uint32_t want,
                               uint32_t bodyBuf, uint32_t pathHash) {
  if (inner < 0xA0000000u || inner == 0xCDCDCDCDu || !bodyBuf || !want)
    return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  for (int slot = 0; slot < 3; ++slot) {
    const uint32_t sBase = inner + 296u + static_cast<uint32_t>(slot) * 40u;
    uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
    (void)mem.ReadU32BE(sBase + 0, &w0);
    (void)mem.ReadU32BE(sBase + 4, &w1);
    (void)mem.ReadU32BE(sBase + 8, &w2);
    (void)mem.ReadU32BE(sBase + 12, &w3);
    MCLA_LOG_WARN(
        "PAGESLOT-CENSUS inner={:08X} slot={} @={:08X} "
        "[{:08X} {:08X} {:08X} {:08X}] filePos={:08X} want={} body={:08X}",
        inner, slot, sBase, w0, w1, w2, w3, filePos, want, bodyBuf);
  }
  (void)pathHash;
}

// Candidate file offsets from a decrypted TOC entry. w18: guest TOC words are
// NOT always {off,size,uncomp}. Raceeditor/garage entries have a plausible
// w1 size/hash and a huge w2 (flag bits). Treat w1 as size-or-offset when
// in-range; also accept low-24-bit packed sizes. Never walk RPF junk —
// only serve a window whose head is non-poison.
static int XsfOffsetCandidates(uint32_t w0, uint32_t w1, uint32_t w2,
                               uint32_t w3, uint32_t *offs, uint32_t *szs,
                               int maxOut) {
  int n = 0;
  (void)w0;
  (void)w3;
  const uint32_t sizeA = w2 & 0x7FFFFFFFu;
  const uint32_t sizeLow = w2 & 0x00FFFFFFu;
  const uint32_t sizeB = w3 & 0x7FFFFFFFu;
  const uint32_t w1m = w1 & 0x0FFFFFFFu; // strip flag bits
  // Primary: w1 as data_offset when it looks like an RPF data cursor.
  if (w1m > 0x1000u && w1m < 0x0F000000u) {
    uint32_t sz = sizeLow;
    if (sz < 0x40u || sz > 0x400000u)
      sz = (w1 > 0x40u && w1 < 0x400000u) ? w1 : 0x8000u;
    offs[n] = w1m;
    szs[n] = sz;
    ++n;
  }
  // w18 list-form: w1 is SIZE (small), w2/w3 carry flag|offset. Use
  // low-24 of w2/w3 as file offset when it is a plausible RPF cursor.
  if (n < maxOut && w1 > 0x20u && w1 < 0x100000u) {
    const uint32_t off2 = sizeLow; // w2 & 0xFFFFFF
    if (off2 > 0x1000u && off2 < 0x0F000000u) {
      offs[n] = off2;
      szs[n] = w1;
      ++n;
    }
    if (n < maxOut) {
      const uint32_t off3 = w3 & 0x0FFFFFFFu;
      if (off3 > 0x1000u && off3 < 0x0F000000u && off3 != off2) {
        offs[n] = off3;
        szs[n] = w1;
        ++n;
      }
    }
  }
  // Secondary: classic {offset=w1, size=w2} when both plausible.
  if (n < maxOut && w1 > 0x1000u && w1 < 0x80000000u && sizeA > 0x40u &&
      sizeA < 0x4000000u && w1 != w1m) {
    offs[n] = w1;
    szs[n] = sizeA;
    ++n;
  }
  if (n < maxOut && w2 > 0x800u && w2 < 0x80000000u && sizeB > 0x40u &&
      sizeB < 0x4000000u) {
    offs[n] = w2;
    szs[n] = sizeB;
    ++n;
  }
  if (n < maxOut && sizeA > 0x800u && sizeA < 0x2000000u) {
    const uint32_t packed = ((w2 & 0x7FFFFF00u) >> 11) & 0x1FFFFFu;
    if (packed > 0x10u) {
      offs[n] = packed << 11;
      szs[n] = sizeB ? sizeB : sizeA;
      ++n;
    }
  }
  return n;
}

// Host-serve a UI body from xarchive_cache.rpf using cached TOC words.
// Same pattern as job2: OpenFile + ReadFileAt, refuse junk windows.
//
// T41.3p (F-105): the six *.list name-list members are headerless raw-DEFLATE
// streams in xarchive_cache.rpf. All six expand to CRLF shader/texture NAME
// LISTS (measured with Python zlib wbits=-15 and independently by
// src/raw_inflate.h: ui 260, city 1246, cars 1108, globaltex 575, characters
// 496, effects 368 — in == out for every one, so the packer padded the stream
// to the TOC's stored length). The image carries its own zlib 1.2.3 (" inflate
// 1.2.3 Copyright 1995-2005 Mark Adler " at VA 0x82017F00 with length_base /
// dist_base at 0x82017F30 / 0x82017FB0) but never calls it for these members
// (all 149 decompressor entries in w74 are the RSC5 package path), so the
// expansion is applied where the archive bytes enter guest memory —
// RpfVirtualFileSystem::ReadFileAt. Without it the loader's line reader
// (sub_82188E50) is handed binary and yields no name (F-104).
static bool MclaListMemberPath(const char *path) {
  if (path == nullptr)
    return false;
  const size_t n = std::strlen(path);
  return n >= 5 && std::strcmp(path + n - 5, ".list") == 0;
}

// T41.3v (F-110 fix attempt): F-110 showed the lazy registration at the first
// TOC *query* is too late — a member page pumped before that keeps its DEFLATE
// bytes in the guest's page cache, which is why only `city` (whose page happened
// to be read after its mark) ever produced preload lines. The archive reads
// start ~59 s before the first list query (`w95`: first pump read 03:53:54.409,
// first mark 03:54:53.082), so the spans must be known at the first I/O submit.
//
// These twelve numbers are not host guesses: each is a `[entry+4]/[entry+8]`
// pair the guest published from its OWN decrypted TOC (`w74`/`w95`
// TOC76-XSF/LAYOUT lines: e.g. `[0DB1C876 00000104 001DD11C 4000007E]`), and
// every one was re-derived independently by the raw-DEFLATE decode of F-105
// (all six expand to name lists of exactly this length). The general key is the
// leaf hash — all five `preload.list` records share `0DB1C876`, and
// `globaltex.list` is `3D9B8154` — so a TOC scan could replace this table once
// the decrypted table is reachable before the first read.
struct MclaListMemberSpan {
  const char *path;
  uint32_t off;
  uint32_t size;
};
constexpr MclaListMemberSpan kListMemberSpans[] = {
    {"shaders/ui/preload.list", 0x001DD11Cu, 260u},
    {"shaders/city/preload.list", 0x001F41FBu, 1246u},
    {"shaders/cars/preload.list", 0x0027F1AFu, 1108u},
    {"shaders/characters/preload.list", 0x002DB9A1u, 496u},
    {"shaders/effects/preload.list", 0x00304E12u, 368u},
    {"textures/global/cars/globaltex.list", 0x000D0000u, 575u},
};

// ON IS THE COMMITTED DEFAULT since F-111: it is what clears B2's gate
// ('wasn't preloaded properly' 2 -> 0; star_glow's .dcl opens ret=1) and it costs
// the C0000005 0 invariant — 50 AVs at the wrapper site (F-108/F-111), which are
// logged, not masked. Set false to return to the w96/w81/w72 frontier exactly
// (censuses then print nothing on this path).
// F-121/T41.5d measured with this OFF (w112): the 50 `NULL+0xC61` reads at
// lr=821BE508 vanish (VEH-NEUTRAL 0, was 50) -- so the seam is what exposes
// them, not what causes them -- but the boot loses the lists (LISTLINE 167 -> 2)
// and regains a fatal. So ON stays the committed frontier and the null pointer
// is the thing to fix.
constexpr bool kExpandListInArchive = true;

// F-149 (T41.11): the `entity.type` members are the same headerless raw-DEFLATE
// family, and they are the blocker itself - `a:/archive/vehicle/shared_utility/
// sst_trail/entity.type` is what sub_826113A8 must parse before it publishes the
// shader group whose absent 'skinningData' variable is the frontier fatal
// (F-143…F-148). Measured offline against the guest's own decrypted TOC dump
// (`tools/rpf_offline.py find entity.type build/toc_parsed.bin` - control passes
// there: the same command resolves `trash.xrn`, whose archive offset the log
// prints in `TOC76-XSF #1365`), and against the archive bytes: member 0x35CA43
// stores 255 deflate bytes and inflates to exactly the 0x1E0 the TOC declares,
// beginning "Version: 103\r\nshadinggroup {". `Version:` is the token
// sub_82611018 tests first and 103 is the constant it compares, so the format is
// settled, not guessed. Unlike the .list spans (in == out, F-105) the stored and
// logical lengths differ here, which is why the span is registered with the TOC
// size - the length ApplyExpandedSpans must produce - exactly as the lazy TOC76
// site already does. Excluded: the two records whose offset word carries bit31
// (0x7F000EBA, 0x7EA85817); at offset & 0x3FFFFFFF they do not inflate, so their
// offset encoding is still unknown.
constexpr bool kExpandTypeMembersInArchive = true;
struct MclaTypeMemberSpan {
  uint32_t off;
  uint32_t logical;
};
constexpr MclaTypeMemberSpan kTypeMemberSpans[] = {
    {0x0032C000u, 0x1E5u}, {0x0032C729u, 0x1E2u}, {0x0032E767u, 0x1E1u},
    {0x0035CA43u, 0x1E0u}, {0x0127E226u, 0x1E9u}, {0x0127EBB1u, 0x1ECu},
    {0x0127FCB8u, 0x288u}, {0x03F0C65Au, 0x22Bu}, {0x055233B5u, 0x21Eu},
    {0x055301D0u, 0x225u},
};

void MclaMarkKnownListMembers() {
  if (!kExpandListInArchive)
    return;
  for (const auto &m : kListMemberSpans) {
    mcla::vfs::MarkMemberExpanded(m.off, m.size);
    MCLA_LOG_WARN("MEMBER-EXPAND-MARK-EARLY path='{}' off={:08X} stored={}",
                  m.path, m.off, m.size);
  }
  if (kExpandTypeMembersInArchive) {
    for (const auto &m : kTypeMemberSpans) {
      mcla::vfs::MarkMemberExpanded(m.off, m.logical);
      MCLA_LOG_WARN("MEMBER-EXPAND-MARK-TYPE off={:08X} logical={}", m.off,
                    m.logical);
    }
  }
}

static uint32_t HostServeUiBody(const char *path, uint32_t &outSize);

// F-188 Path A: host-buffer XC decode (defined after MclaHostLzxDecode).
static uint32_t MclaHostXcDecodePackage(const uint8_t *pkg, uint32_t pkgSz,
                                        std::vector<uint8_t> &out);

static uint32_t HostServeUiBody(const char *path, uint32_t &outSize) {
  outSize = 0;
  // T41.3g (F-077) refusal RETIRED by T41.3p/F-105: list paths were blocked
  // from host-serve so the guest's own open/read could be observed. F-103 showed
  // the guest's own path never reaches the loader (BE8D8-PACK-MISS: no body),
  // and F-105 identifies the transform, so list bodies are served expanded.
  uint32_t w[4] = {0, 0, 0, 0};
  std::string pathKey = path ? path : "";
  {
    std::lock_guard<std::mutex> lk(g_xsfMtx);
    auto it = g_xsfToc.find(pathKey);
    if (it == g_xsfToc.end() || it->second.entry == 0) {
      // Guest may open "a:/archive/..." while TOC cached the relative form.
      if (pathKey.size() > 11 &&
          _strnicmp(pathKey.c_str(), "a:/archive/", 11) == 0) {
        pathKey = pathKey.substr(11);
        it = g_xsfToc.find(pathKey);
      }
    }
    if (it == g_xsfToc.end() || it->second.entry == 0)
      return 0;
    for (int i = 0; i < 4; ++i)
      w[i] = it->second.w[i];
  }
  uint32_t offs[4] = {0}, szs[4] = {0};
  const int ncand =
      XsfOffsetCandidates(w[0], w[1], w[2], w[3], offs, szs, 4);
  if (ncand == 0)
    return 0;
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  if (!vfs.OpenFile("xarchive_cache.rpf", fh))
    return 0;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dst = 0;
  // F-129/T41.11: pass 0 accepts ONLY a candidate whose first word is a real
  // container magic; pass 1 repeats with today's "first non-sentinel" rule so a
  // plaintext .list body still lands (it has no magic). Measured why this is
  // needed: the member at the TOC's own offset/size inflates to
  // 'rgxa\1\377\1\22VS_UnlitTransform' - the head the guest's rage-effect gate
  // compares (0x61786772 LE) - while the masked candidates (MEMBER-EXPAND
  // off=001DD11C stored=260, i.e. w2 with its low bits cleared) yield another
  // member's name-list text, which is what w132's BE710-BODY #68 showed.
  constexpr uint32_t kHeadRgxa = 0x72677861u;  // 'rgxa' as BE of bytes r,g,x,a
  constexpr uint32_t kHeadRsc5 = 0x05435352u;  // 'RSC5'
  constexpr uint32_t kHeadXcmp = 0x0FF512EFu;  // XCompress
  for (int pass = 0; pass < 2 && dst == 0; ++pass) {
  for (int c = 0; c < ncand && dst == 0; ++c) {
    if (offs[c] == 0 || szs[c] < 0x40 || szs[c] > 0x400000)
      continue;
    std::vector<uint8_t> tmp(szs[c]);
    uint64_t got = 0;
    if (!vfs.ReadFileAt(fh, offs[c], tmp.data(), szs[c], got) || got < 0x40)
      continue;
    uint32_t be = (uint32_t(tmp[0]) << 24) | (uint32_t(tmp[1]) << 16) |
                  (uint32_t(tmp[2]) << 8) | uint32_t(tmp[3]);
    // Refuse poison / zeros. Accept RSC5/XC package heads — archive .list
    // and dict bodies ARE those families; the old reject starved preload.
    if (be == 0xCDCDCDCDu || be == 0 || be == 0xFFFFFFFFu)
      continue;
    // F-130: the span hook in vfs_rpf.cpp only expands a member that fits
    // WHOLE inside one read window, so a member straddling a page boundary -
    // exactly the TOC's own 0x1DD1E8 + 3170 for AlphaModulate.fxc - reaches us
    // still DEFLATE-compressed (that is why only 6 spans ever printed
    // MEMBER-EXPAND and why no candidate carried a magic in w134). Inflate the
    // candidate here, with the same helper.
    if (be != kHeadRgxa && be != kHeadRsc5 && be != kHeadXcmp) {
      std::vector<uint8_t> inf;
      if (mcla::RawInflate(tmp.data(), tmp.size(), inf) && inf.size() >= 0x40) {
        const uint32_t ibe = (uint32_t(inf[0]) << 24) |
                             (uint32_t(inf[1]) << 16) |
                             (uint32_t(inf[2]) << 8) | uint32_t(inf[3]);
        if (ibe == kHeadRgxa || ibe == kHeadRsc5 || ibe == kHeadXcmp) {
          MCLA_LOG_WARN("XSF-INFLATE path='{}' off={:08X} stored={} "
                        "expanded={} head={:08X}->{:08X}",
                        path, offs[c], szs[c], inf.size(), be, ibe);
          tmp.swap(inf);
          be = ibe;
        }
      }
    }
    if (pass == 0 && be != kHeadRgxa && be != kHeadRsc5 && be != kHeadXcmp)
      continue;

    // w20: TOC-derived bodies for .xtd/.xsf are often AES ciphertext.
    // Prefer the plaintext RSC5+XCompress package from the host table
    // (0x60000 meshtextures, 0xA0000 UI) when the candidate head is not
    // parseable. Lists keep their own plaintext name bodies.
    uint32_t serveOff = offs[c];
    std::vector<uint8_t> serveBytes = tmp;
    uint32_t pkgSubst = 0;
    {
      const uint32_t pathPkg = MclaPreferredPkgOffForPath(path);
      const uint32_t tocPkg = MclaPkgOffFromTocW2(w[2]);
      const bool wantsPkg =
          (pathPkg != 0 || tocPkg != 0) &&
          !MclaHeadIsRscOrXc(tmp.data(), static_cast<uint32_t>(got));
      // Lists never take a package substitute (their name bodies work).
      const bool isList =
          std::strstr(path, ".list") != nullptr ||
          std::strstr(path, "globaltex") != nullptr ||
          std::strstr(path, "preload") != nullptr;
      if (wantsPkg && !isList) {
        // F-171: use the package the guest's OWN record names, but only when it
        // verifies - a TOC record is {leafHash, SIZE, packageOffset|headerLength,
        // packageID} and the package header repeats that ID at +0x08, so
        // [pkg+8] == w[3] is a per-file check, not a guess. Verified on all
        // seven UI members once the archive was complete (F-170): credits
        // 0x6496F000 declares 29,655 bytes, garage 0x64980000 -> 1,066,057,
        // policecam 0x64CA3000 -> 19,337, raceeditor 0x64CB0000 -> 143,069, each
        // with RSC5 magic and a matching ID. The substring placeholder below is
        // therefore kept only as a fallback, because it serves legals.xsf's
        // package (196,553 bytes) to every .xsf.
        uint32_t pkgOff = 0;
        {
          std::vector<uint8_t> probe;
          if (tocPkg != 0 && MclaLoadPkgWindow(tocPkg, 0, 64, probe) &&
              probe.size() >= 12 && MclaBE(probe.data()) == 0x05435352u &&
              MclaBE(probe.data() + 8) == w[3])
            pkgOff = tocPkg;
          else if (pathPkg != 0)
            pkgOff = pathPkg;  // MITIGATION fallback (pre-F-171 substring map)
        }
        if (pkgOff != 0) {
        // F-169: ask the package how big it is before deciding the window. The
        // table-derived size below was floored at 32 KB and capped at 256 KB, and
        // MclaLoadPkgWindow clamped every read to 32 KB as well, so a 196 KB UI
        // package was served as 32 KB (F-165 measured six paths all binding at
        // exactly 32768; F-168 read the declared lengths out of the archive).
        uint32_t pkgSz = PackageSizeAt(pkgOff);
        if (pkgSz < 0x8000u)
          pkgSz = 0x8000u;
        if (pkgSz > kPkgWindowMax)
          pkgSz = kPkgWindowMax;
        {
          std::vector<uint8_t> head;
          if (MclaLoadPkgWindow(pkgOff, 0, 64, head)) {
            const uint32_t declared = MclaRsc5DeclaredSize(
                head.data(), static_cast<uint32_t>(head.size()));
            // Replace, do not raise: w174 took max(table, declared) and the table
            // sizes run to 2.8-4 MB, so the guest was handed neighbouring archive
            // data after the package and Fatal error went 1->4 with [error]
            // 28->52. The header's own number is the body's length.
            if (declared != 0)
              pkgSz = declared;
          }
        }
        std::vector<uint8_t> pkg;
        if (MclaLoadPkgWindow(pkgOff, 0, pkgSz, pkg) && pkg.size() >= 16) {
          const uint32_t pbe = MclaBE(pkg.data());
          if (pbe == 0x05435352u || pbe == 0x0FF512EFu) {
            // F-183: zlibInflater::InflateBegin compares the FIRST WORD of the
            // stream with 0x0FF512EF and consumes 8 bytes from there (magic +
            // block size) before handing the rest to XMemDecompress. That header
            // is not at the container head - it is at RSC5+0x0C, the guest's own
            // pgStreamer::Open reading RSC5+0x04 as its parameter proves the
            // preamble is real. F-182 measured the guest reaching the check for
            // the first time and printing its own 'not in XCompress format', so
            // hand it a stream that starts where its check looks.
            uint32_t useOff = pkgOff;
            if (kServeFromXCompressHead && pbe == 0x05435352u &&
                pkg.size() > 16u) {
              pkg.erase(pkg.begin(), pkg.begin() + 12);
              useOff = pkgOff + 12u;
            }
            serveOff = useOff;
            serveBytes.swap(pkg);
            pkgSubst = useOff;
            MCLA_LOG_WARN("PKG-SUBST path='{}' tocOff={:08X} tocHead={:08X} "
                          "-> pkg={:08X} head={:08X} n={}",
                          path, offs[c], be, pkgOff, pbe, serveBytes.size());
            // F-188 Path A: UI .xsf never reach guest inflate (F-186 enqueue
            // gap). Decode the RSC5+XCompress LZX payload here so the guest
            // gets real resource bytes. Lists keep DEFLATE/`RawInflate` above.
            if constexpr (kHostLzxDecode) {
              std::vector<uint8_t> decoded;
              if (MclaHostXcDecodePackage(serveBytes.data(),
                                          static_cast<uint32_t>(serveBytes.size()),
                                          decoded) > 0) {
                serveBytes.swap(decoded);
              }
            }
          }
        }
        }
      }
    }

    // T41.3p (F-105): the expansion of raw-DEFLATE list members happens once,
    // in RpfVirtualFileSystem::ReadFileAt (registered from the guest's own TOC
    // words at the TOC76-XSF census), so the guest's page-cache copy and this
    // host-served body see the same expanded archive image.

    dst = mem.Alloc(static_cast<uint32_t>(serveBytes.size()), 16);
    if (!dst)
      continue;
    if (!mem.WriteBytes(dst, serveBytes.data(),
                        static_cast<uint32_t>(serveBytes.size()))) {
      dst = 0;
      continue;
    }
    outSize = static_cast<uint32_t>(serveBytes.size());
    MCLA_LOG_WARN("XSF-HOSTSERVE path='{}' off={:08X} size={} buf={:08X} "
                  "head={:08X} pkgSubst={:08X} pass={} toc=[{:08X} {:08X} "
                  "{:08X} {:08X}]",
                  path, serveOff, outSize, dst, MclaBE(serveBytes.data()),
                  pkgSubst, pass, w[0], w[1], w[2], w[3]);
  }
  }
  vfs.CloseFile(fh);
  return dst;
}

// ---------------------------------------------------------------------------
// w19: POSTOPEN-SERVE → packfile size/Read wire.
//
// CDE/Open (CCEA0) contract (ppc_recomp.17.cpp):
//   tocEntry = dev->vt[+144](dev, path);
//   handle   = first free slot in {dev+40+i*68, i<16} with [slot+0]==0;
//   [slot+0] = tocEntry; [slot+4] = 0; return handle.
// GetSize (CD3C8): return [ [dev+40+h*68] + 4 ] == [tocEntry+4] == TOC w1.
// Read wrapper (CC6F0): inner=[obj+32]; inner->vt[28](inner, r4, [obj+24]+r5,
//   dest, count). JOIN dump: r5 matches TOC w2 with low byte cleared
//   (40060000 vs meshtextures w2=40060009) — use that to pick the body.
//
// Host keeps a served-body table keyed by path / tocEntry / w3 / (dev,handle)
// so subsequent size+Read return the bytes we already landed.
// ---------------------------------------------------------------------------
struct MclaServedBody {
  uint32_t buf = 0;
  uint32_t size = 0;
  uint32_t pos = 0;
  uint32_t dev = 0;
  uint32_t handle = 0xFFFFFFFFu;
  uint32_t tocEntry = 0;
  uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
  std::string path;
};
static std::mutex g_servedMtx;
static std::unordered_map<std::string, MclaServedBody> g_servedByPath;
static std::unordered_map<uint32_t, MclaServedBody> g_servedByEntry;
static std::unordered_map<uint32_t, MclaServedBody> g_servedByDevH;
static std::unordered_set<std::string> g_globtexNames;
static std::atomic<uint32_t> g_globtexServedInserted{0};

static std::string MclaNormalizeArchivePath(const char *path) {
  std::string p = path ? path : "";
  static const char kPfx[] = "a:/archive/";
  if (p.size() >= 11 && _strnicmp(p.c_str(), kPfx, 11) == 0)
    p = p.substr(11);
  return p;
}

static uint32_t MclaDevHandleKey(uint32_t dev, uint32_t h) {
  return (dev & 0x0FFFFFFFu) ^ (h * 0x9E3779B9u);
}

static void MclaRegisterServedBody(const char *path, uint32_t buf,
                                   uint32_t size, uint32_t dev,
                                   uint32_t handle, uint32_t tocEntry,
                                   const uint32_t w[4]) {
  if (!buf || !size)
    return;
  MclaServedBody b;
  b.buf = buf;
  b.size = size;
  b.pos = 0;
  b.dev = dev;
  b.handle = handle;
  b.tocEntry = tocEntry;
  b.w0 = w[0];
  b.w1 = w[1];
  b.w2 = w[2];
  b.w3 = w[3];
  b.path = MclaNormalizeArchivePath(path);
  std::lock_guard<std::mutex> lk(g_servedMtx);
  g_servedByPath[b.path] = b;
  if (tocEntry)
    g_servedByEntry[tocEntry] = b;
  // F-126: w[3] is the TOC record's FLAGS dword, not a file identity. Measured
  // in w115: 40000061 is shared by 52 distinct records, 40000057 by 26,
  // 4000004E by 22 - so a body indexed by it cross-serves another file as soon
  // as many records are registered. Same class as the (dev,handle) demotion of
  // F-091; this index no longer exists.
  if (dev && handle != 0xFFFFFFFFu)
    g_servedByDevH[MclaDevHandleKey(dev, handle)] = b;
}

static bool MclaFindServedBody(uint32_t dev, uint32_t handle, uint32_t flagWord,
                               uint32_t tocEntry, uint32_t w3,
                               MclaServedBody *out) {
  if (!out)
    return false;
  std::lock_guard<std::mutex> lk(g_servedMtx);
  if (tocEntry) {
    auto it = g_servedByEntry.find(tocEntry);
    if (it != g_servedByEntry.end()) {
      *out = it->second;
      return true;
    }
  }
  // F-126: no w3 (TOC flags dword) lookup - the key is not an identity.
  // T41.3o (F-091): (dev,handle) is a per-device SLOT key, not a file
  // identity — it served legals.xsf as the body of all five
  // shaders/*/preload.list reads. Log-only; only tocEntry is exact (F-126).
  if (dev && handle != 0xFFFFFFFFu) {
    auto it = g_servedByDevH.find(MclaDevHandleKey(dev, handle));
    if (it != g_servedByDevH.end()) {
      static std::atomic<uint32_t> s_dhSkip{0};
      const uint32_t k = s_dhSkip.fetch_add(1) + 1;
      if (k <= 24)
        MCLA_LOG_WARN("T413O-SKIP #{} key=devh dev={:08X} h={} would-serve "
                      "path='{}' size={}", k, dev, handle, it->second.path,
                      it->second.size);
    }
  }
  // CC6F0 r5 ≈ TOC w2 with low byte cleared (gate/size family).
  // T41.3o (F-091): this family match ignores the low byte, so a .list read
  // borrows whatever shader body shares its w2 family. Log-only; the exact
  // w3 re-check below still stands.
  if (flagWord) {
    for (const auto &kv : g_servedByPath) {
      const uint32_t w2 = kv.second.w2;
      if (w2 == 0)
        continue;
      if ((w2 & 0xFFFFFF00u) == (flagWord & 0xFFFFFF00u)) {
        static std::atomic<uint32_t> s_fwSkip{0};
        const uint32_t k = s_fwSkip.fetch_add(1) + 1;
        if (k <= 24)
          MCLA_LOG_WARN("T413O-SKIP #{} key=flagWord {:08X} would-serve "
                        "path='{}' size={}", k, flagWord, kv.second.path,
                        kv.second.size);
        break;
      }
    }
    // F-126: flagWord may carry TOC w3; that index is retired, so nothing is
    // served here and the family match above stays log-only.
  }
  // T41.3o (F-091): the bare-dev "last body on this device" fallback is the
  // loosest of the three — it would re-introduce exactly the legals.xsf-as-
  // .list-body contamination the task is removing, so it is now log-only too.
  if (dev) {
    const MclaServedBody *best = nullptr;
    for (const auto &kv : g_servedByPath) {
      if (kv.second.dev == dev && kv.second.buf)
        best = &kv.second;
    }
    if (best) {
      static std::atomic<uint32_t> s_devSkip{0};
      const uint32_t k = s_devSkip.fetch_add(1) + 1;
      if (k <= 24)
        MCLA_LOG_WARN("T413O-SKIP #{} key=dev dev={:08X} would-serve "
                      "path='{}' size={}", k, dev, best->path, best->size);
    }
  }
  return false;
}

// Guest insert linker (definition hooked later at TEXINIT). Declared here so
// the w19 served-list bootstrap can call it before that hook appears.
PPC_FUNC_IMPL(__imp__sub_821854C8);

// Parse first tokens (and embedded printable runs) from a served body and
// INSERT each name via the guest's own 821854C8(noneObj, name).
static int MclaInsertNamesFromBytes(uint8_t *base, uint32_t noneObj,
                                    const uint8_t *data, uint32_t len,
                                    const char *tag) {
  if (!base || !data || len == 0 || noneObj == 0)
    return 0;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Hex+ASCII head so the soak can show what the list body actually is.
  {
    char ascii[48] = {0};
    const uint32_t n = len < 32 ? len : 32u;
    for (uint32_t i = 0; i < n; ++i) {
      const uint8_t c = data[i];
      ascii[i] = (c >= 32 && c < 127) ? static_cast<char>(c) : '.';
    }
    uint32_t w0 = 0, w1 = 0;
    if (len >= 4)
      w0 = (uint32_t(data[0]) << 24) | (uint32_t(data[1]) << 16) |
           (uint32_t(data[2]) << 8) | data[3];
    if (len >= 8)
      w1 = (uint32_t(data[4]) << 24) | (uint32_t(data[5]) << 16) |
           (uint32_t(data[6]) << 8) | data[7];
    MCLA_LOG_WARN("GLOBTEX-BODY {} len={} head={:08X} {:08X} ascii='{}'", tag,
                  len, w0, w1, ascii);
  }
  int inserted = 0;
  std::string cur;
  bool skipLineRest = false;
  auto flushTok = [&]() {
    if (cur.size() >= 2 && cur[0] != '#') {
      std::lock_guard<std::mutex> lk(g_servedMtx);
      if (g_globtexNames.find(cur) != g_globtexNames.end()) {
        cur.clear();
        return;
      }
      g_globtexNames.insert(cur);
      const uint32_t nameAddr =
          mem.Alloc(static_cast<size_t>(cur.size()) + 1, 16);
      if (nameAddr != 0) {
        (void)mem.WriteBytes(nameAddr, cur.c_str(),
                             static_cast<uint32_t>(cur.size()) + 1);
        PPCContext tmp{};
        tmp.r3.u32 = noneObj;
        tmp.r4.u32 = nameAddr;
        __imp__sub_821854C8(tmp, base);
        ++inserted;
      }
    }
    cur.clear();
  };
  for (uint32_t i = 0; i < len; ++i) {
    const char c = static_cast<char>(data[i]);
    if (c == '\n' || c == '\r' || c == 0) {
      flushTok();
      skipLineRest = false;
      continue;
    }
    if (c == ' ' || c == '\t' || c == ',' || c == ';') {
      if (!cur.empty()) {
        flushTok();
        skipLineRest = true; // first token only ("name file" rows)
      }
      continue;
    }
    if (c < 32 || c >= 127) {
      // Binary break — flush any run (embedded C-strings in RSC lists).
      flushTok();
      skipLineRest = false;
      continue;
    }
    if (skipLineRest)
      continue;
    if (cur.size() < 96)
      cur.push_back(c);
  }
  flushTok();
  g_globtexServedInserted.fetch_add(static_cast<uint32_t>(inserted));
  MCLA_LOG_WARN("GLOBTEX-SERVE inserted={} tag='{}' total={}", inserted, tag,
                g_globtexServedInserted.load());
  return inserted;
}

// T41.3q (F-105): both GLOBTEX bootstraps below are HOST stand-ins — they write
// shader/texture names into the guest's non-resident-texture registry by hand
// (and one of them reads the extracted tree off the host disk). Switching them
// off was tested in w77 alongside the archive-level expansion: the page-retry
// spin was unchanged, so the double-registration hypothesis is refuted and the
// stand-ins stay on until the guest's own loader demonstrably replaces them.
constexpr bool kHostGlobaltexNameInjection = true;

static void MclaBootstrapGlobaltexFromServed(uint8_t *base) {
  if (!kHostGlobaltexNameInjection)
    return;
  uint32_t noneObj = 0;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  (void)mem.ReadU32BE(0x82839CF0, &noneObj);
  if (noneObj == 0) {
    MCLA_LOG_WARN("GLOBTEX-SERVE skipped: none object not ready");
    return;
  }
  std::vector<MclaServedBody> lists;
  {
    std::lock_guard<std::mutex> lk(g_servedMtx);
    for (const auto &kv : g_servedByPath) {
      if (kv.first.find("globaltex") != std::string::npos &&
          kv.first.find(".list") != std::string::npos && kv.second.buf &&
          kv.second.size)
        lists.push_back(kv.second);
      // Also feed preload lists — same first-token format.
      if (kv.first.find("preload.list") != std::string::npos &&
          kv.second.buf && kv.second.size)
        lists.push_back(kv.second);
    }
  }
  int total = 0;
  for (const auto &b : lists) {
    std::vector<uint8_t> tmp(b.size);
    if (!mem.ReadBytes(b.buf, tmp.data(), b.size))
      continue;
    total += MclaInsertNamesFromBytes(base, noneObj, tmp.data(), b.size,
                                      b.path.c_str());
  }
  MCLA_LOG_WARN("GLOBTEX-SERVE-DONE lists={} inserted={} noneObj={:08X}",
                lists.size(), total, noneObj);
}

static std::atomic<uint32_t> s_rsRealThunkHits{0};
static std::atomic<uint32_t> s_rsLogOnlyThunkHits{0};
void HostRsRealPassthrough(PPCContext &__restrict ctx, uint8_t *base);
void HostRsRealPassthroughLogOnly(PPCContext &__restrict ctx, uint8_t *base);

// Mutex for protecting g_lastDraw and g_drawMutex access across namespace blocks
static std::mutex g_drawMutex;

namespace mcla::gpu {

namespace {

std::atomic<uint32_t> g_deviceAddr{0};
std::atomic<bool> g_layoutDumped{false};

// Canonical publish slot the rest of the driver reads the device from:
// device = **(uint32_t**)0x82000864 (reverser-verified, 23 consumers).
constexpr uint32_t kDevicePublishSlot = 0x82000864;

constexpr uint32_t kDumpBytes =
    0x400; // FP tables + sampler region + constants head

void DumpDeviceLayout(uint32_t dev) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  for (uint32_t off = 0; off < kDumpBytes; off += 16) {
    uint32_t w[4] = {};
    bool ok = true;
    for (int i = 0; i < 4; ++i) {
      ok &= mem.ReadU32BE(dev + off + 4u * static_cast<uint32_t>(i), &w[i]);
    }
    if (!ok) {
      MCLA_LOG_WARN("DEVICE: read failed at +{:04X}", off);
      return;
    }
    // SWA GuestDevice reference layout for comparison: dirtyFlags[8]
    // @+0x00, setRenderStateFunctions[0x65] @+0x40,
    // setSamplerStateFunctions[0x14] @+0x1D4. Pointer-like words show up
    // as 82xxxxxx guest code addresses.
    MCLA_LOG_INFO("DEVICE +{:04X}: {:08X} {:08X} {:08X} {:08X}", off, w[0],
                  w[1], w[2], w[3]);
  }
}

void OnDeviceCreated(uint32_t dev) {
  g_deviceAddr.store(dev, std::memory_order_relaxed);

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t slotPtr = 0;
  uint32_t published = 0;
  if (mem.ReadU32BE(kDevicePublishSlot, &slotPtr) && slotPtr != 0 &&
      mem.ReadU32BE(slotPtr, &published)) {
    MCLA_LOG_INFO(
        "DEVICE: created @ {:08X} (publish slot {:08X} -> {:08X}, {})", dev,
        slotPtr, published, published == dev ? "match" : "MISMATCH");
  } else {
    MCLA_LOG_INFO("DEVICE: created @ {:08X} (publish slot unreadable)", dev);
  }

  if (!g_layoutDumped.exchange(true)) {
    DumpDeviceLayout(dev);
  }
}

} // namespace

uint32_t DeviceGuestAddr() {
  return g_deviceAddr.load(std::memory_order_relaxed);
}

} // namespace mcla::gpu

// ---------------------------------------------------------------------------
// Render-state table redirection (UnleashedRecomp video.cpp CreateDevice).
// Slots left at the driver's own default stub (= PPC_CODE_BASE) are pointed
// at a host passthrough thunk registered past the guest code range. Real
// handlers stay untouched - this proves the FP-table seam end-to-end without
// changing behavior.
// ---------------------------------------------------------------------------

static std::atomic<uint32_t> s_rsThunkHits{0};

static void HostRsUnimplementedPassthrough(PPCContext &__restrict ctx,
                                           uint8_t *base) {
  // First touches get logged; behavior passes through to the driver's own
  // default handler unchanged.
  const uint32_t hits = s_rsThunkHits.fetch_add(1) + 1;
  if (hits <= 12 || (hits % 500) == 0) {
    MCLA_LOG_INFO("DEVICE: RS-default-thunk hit #{} r3={:08X} r4={:08X}", hits,
                  ctx.r3.u32, ctx.r4.u32);
  }
  if (PPCFunc *orig = mcla::kernel::g_memory.FindFunction(
          static_cast<uint32_t>(PPC_CODE_BASE))) {
    orig(ctx, base);
  }
}

namespace mcla::gpu {
namespace {

void RedirectDefaultRenderStateSlots(uint32_t dev) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  const auto fnOffset = static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE);
  mcla::kernel::g_memory.InsertFunction(fnOffset,
                                        &HostRsUnimplementedPassthrough);

  uint32_t redirected = 0;
  constexpr uint32_t kSlots = 0x65; // setRenderStateFunctions count
  for (uint32_t slot = 0; slot < kSlots; ++slot) {
    const uint32_t addr = dev + 0x40u + slot * 4u;
    uint32_t cur = 0;
    if (!mem.ReadU32BE(addr, &cur)) {
      return;
    }
    if (cur == static_cast<uint32_t>(PPC_CODE_BASE)) {
      (void)mem.WriteU32BE(addr, fnOffset);
      ++redirected;
    }
  }

  // Rung-2 self-test: table round-trip + thunk resolution.
  uint32_t readBack = 0;
  const bool tableOk = mem.ReadU32BE(dev + 0x40u, &readBack);
  PPCFunc *resolved = mcla::kernel::g_memory.FindFunction(fnOffset);
  MCLA_LOG_INFO(
      "DEVICE: redirected {}/{} default RS slots -> {:08X} | readback={} "
      "(slot0={:08X}) | thunkResolved={}",
      redirected, kSlots, fnOffset, tableOk ? "ok" : "FAIL", readBack,
      resolved != nullptr);
}

// P4' step 2: passthrough-thunk ONE real handler slot so a runtime call proves
// dispatch through our synthetic VA end-to-end. Slot +0x68 (table index 10)
// held 0x82414078 in both dumped devices. The original stays reachable via its
// own guest address (FindFunction), so redirection loses nothing.
constexpr uint32_t kRealSlotOffset = 0x68;
constexpr uint32_t kRealSlotOriginal = 0x82414078;

void RedirectFirstRealRenderStateSlot(uint32_t dev) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  const uint32_t slotAddr = dev + kRealSlotOffset;
  uint32_t cur = 0;
  if (!mem.ReadU32BE(slotAddr, &cur)) {
    MCLA_LOG_WARN("DEVICE: real-slot redirect read failed @ {:08X}", slotAddr);
    return;
  }
  if (cur != kRealSlotOriginal) {
    MCLA_LOG_WARN(
        "DEVICE: real-slot @ {:08X} holds {:08X} (expected {:08X}) - skipping",
        slotAddr, cur, kRealSlotOriginal);
    return;
  }

  // Synthetic VA right after the default-slots thunk.
  const auto fnOffset =
      static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE) + 4u;
  mcla::kernel::g_memory.InsertFunction(fnOffset, &HostRsRealPassthrough);
  (void)mem.WriteU32BE(slotAddr, fnOffset);

  uint32_t readBack = 0;
  const bool ok = mem.ReadU32BE(slotAddr, &readBack) && readBack == fnOffset &&
                  mcla::kernel::g_memory.FindFunction(fnOffset) != nullptr;
  MCLA_LOG_INFO("DEVICE: real RS slot +{:X} -> {:08X} | selftest={}",
                kRealSlotOffset, fnOffset, ok ? "ok" : "FAIL");

  // Probe widening: EVERY other real slot gets a log-only thunk (no
  // passthrough - originals stay reachable by address if needed later).
  // Purpose: discover which states are actually hot during boot/menu.
  constexpr uint32_t kSlots = 0x65;
  uint32_t probed = 0;
  auto nextFn = fnOffset;
  for (uint32_t slot = 0; slot < kSlots; ++slot) {
    const uint32_t sAddr = dev + 0x40u + slot * 4u;
    uint32_t v = 0;
    if (!mem.ReadU32BE(sAddr, &v))
      break;
    if (v == static_cast<uint32_t>(PPC_CODE_BASE))
      continue; // default stub
    if (sAddr == slotAddr)
      continue; // faithful one above
    if (v < static_cast<uint32_t>(PPC_CODE_BASE) ||
        v >= static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE))
      continue; // not guest code
    ++nextFn;
    mcla::kernel::g_memory.InsertFunction(nextFn,
                                          &HostRsRealPassthroughLogOnly);
    (void)mem.WriteU32BE(sAddr, nextFn);
    ++probed;
  }
  MCLA_LOG_INFO("DEVICE: probe widened - {} additional real slots log-only",
                probed);
}

} // namespace
} // namespace mcla::gpu

// ---------------------------------------------------------------------------
// Guest-function override. MUST live at GLOBAL scope: the generated TUs bind
// calls to the global weak symbol sub_82413588; a namespaced definition would
// be a different symbol entirely and silently never run.
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_82413588);

// FIX: sub_821873E8 (p2t). RAW image (F-023), NOT the IDA decompile:
//   mflr/stwu; r11=[r13]; r3=[r11+12]; r9=[r3]; r8=[r9+8]; mtctr; bctrl
//   (alloc 72, align 16); cmpli r3,0; beq return0; bl 82188CF8; return r3.
// Crash: TLS slot +12 is never-armed (0) on this worker -> lwz r9,0(0) AV,
// Param[1]=0x7E780000 = PPC_LOOKUP_FUNC(guest 0). Same disease as the
// atArray ctor family (slot 12 = 16B allocator). Host-complete the alloc
// when the slot is dead; call original when it is live.
PPC_FUNC_IMPL(__imp__sub_821873E8);
static void LogFabricatedShader(const char *tag, uint32_t obj);  // defined at the MSGCHAIN block
static std::atomic<uint32_t> s_821873E8_hits{0};
static std::atomic<uint32_t> s_821873E8_live{0};  // F-358 alive-path census
PPC_FUNC(sub_821873E8) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t n = s_821873E8_hits.fetch_add(1) + 1;

  uint32_t tlsTable = 0;
  uint32_t slot12 = 0;
  const bool tlsOk =
      ctx.r13.u32 != 0 && mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
      tlsTable != 0 && tlsTable != 0xCDCDCDCDu;
  if (tlsOk)
    (void)mem.ReadU32BE(tlsTable + 12, &slot12);

  const bool slotLive = slot12 != 0 && slot12 != 0xCDCDCDCDu;
  if (tlsOk && slotLive) {
    // F-358: the ONLY other exit in this hook is the TLSDEAD branch below, whose
    // printers (`FIX-821873E8`, cap `n<=4 || n%200`) are 0 in w351/w354/w355/w356 --
    // so either this hook never fires or it always returns here, and that difference
    // decides whether the boot-gate dispatch at :2100 is dormant or unreachable.
    // Uncapped-first-8: a count <=8 is complete.
    const uint32_t nl = s_821873E8_live.fetch_add(1) + 1;
    if (nl <= 8 || (nl % 500) == 0)
      MCLA_LOG_WARN("F358-821873E8-ALIVE #{} of {} hits r13={:08X} tlsTable={:08X} "
                    "slot12={:08X} lr={:08X}",
                    nl, n, ctx.r13.u32, tlsTable, slot12,
                    static_cast<uint32_t>(ctx.lr));
    __imp__sub_821873E8(ctx, base);
    return;
  }

  if (n <= 4 || (n % 200) == 0)
    MCLA_LOG_WARN("FIX-821873E8 #{} TLSDEAD r13={:08X} tlsTable={:08X} "
                  "slot12={:08X} lr={:08X} - host-complete alloc72 + chain init",
                  n, ctx.r13.u32, tlsTable, slot12,
                  static_cast<uint32_t>(ctx.lr));

// Per-TLS-table chain init (global-once starved thread 2+; heal each dead table).
  if (tlsOk && (slot12 == 0 || slot12 == 0xCDCDCDCDu)) {
    static std::mutex s_tlsChainMtx;
    static std::unordered_set<uint32_t> s_tlsChainDone;
    std::lock_guard<std::mutex> lk(s_tlsChainMtx);
    uint32_t cur = 0;
    (void)mem.ReadU32BE(tlsTable + 12, &cur);
    if ((cur == 0 || cur == 0xCDCDCDCDu) && s_tlsChainDone.find(tlsTable) == s_tlsChainDone.end()) {
      MCLA_LOG_WARN("FIX-821873E8 initializing TLS chain for tlsTable={:08X}", tlsTable);
      uint32_t allocatorObj = mem.Alloc(16, 16);
      uint32_t vtable = mem.Alloc(16, 16);
      if (allocatorObj != 0 && vtable != 0) {
        for (uint32_t o = 0; o < 16; o += 4) {
          (void)mem.WriteU32BE(vtable + o, 0);
          (void)mem.WriteU32BE(allocatorObj + o, 0);
        }
        (void)mem.WriteU32BE(vtable + 8, 0x82130528); // __xtl_alloc
        (void)mem.WriteU32BE(allocatorObj + 0, vtable);
        (void)mem.WriteU32BE(tlsTable + 12, allocatorObj);
      }
      s_tlsChainDone.insert(tlsTable);
    }
  }

  // After chain init, dispatch the REAL boot-gate (sub_82131008) on this thread.
  // It performs init + event-gate checks and calls UILOAD itself at guest
  // 0x821310B0 with the correct r3=[0x82830998]. Calling UILOAD directly
  // (prior rev) bypassed the gates. Per W36 note, preset [0x8212E6F0]=1 to
  // skip the 823043F8/4348 crash path.
  static std::atomic<uint32_t> s_uiLoadCalled{0};
  if (s_uiLoadCalled.fetch_add(1) == 0) {
    // T41.3 / w38o: this stand-in used to run INLINE, i.e. the host forced
    // sub_82131008 re-entrantly from inside the guest's own allocator hook, on the
    // thread that was mid-way through sub_823047D8 (w38o.log:3866 -> :3868 -> :3869
    // -> :4088 in w38n). The AV the gate provoked therefore killed that caller too,
    // and the tail of sub_823047D8 never ran — including 0x82304910, whose callee
    // sub_822F38C0 is the ONLY writer of the [0x8287E26C] singleton that the gate
    // then faulted on (F-060). Same stand-in, off the caller's stack, and given the
    // guest a window to publish that singleton itself first. Nothing is fabricated:
    // if [0x8287E26C] never appears, GATE-WAIT says so and the gate runs anyway.
    MCLA_LOG_WARN("FIX-821873E8 dispatching BOOT-GATE (sub_82131008) on its own thread");
    std::thread([caller = ctx]() mutable {
      PPCContext &ctx = caller;
      SetPPCContext(ctx);  // a fresh host thread has no TLS context (guest_thread.cpp:34)
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      // This thread now runs concurrently with the guest thread the hook was called
      // from, so the gate cannot share that thread's stack: everything below r1 is
      // exactly where a live thread pushes its next frames. Give it its own — from
      // the HOST user heap, the same source GuestThreadContext uses for real guest
      // thread stacks (src/kernel/guest_thread.cpp:20). Taking it from
      // GuestMemoryHeap::Alloc (the guest PHYSICAL o1heap) is wrong: w38p.log:3890
      // allocated r1=CA75D740 there and 1 ms later three
      // `AllocPhysical: o1heapAllocate returned null size=0xca71d400` appeared that
      // are absent from the baseline w38m.log.
      void *stackHost = g_userHeap.Alloc(0x40000);
      const uint32_t callerR1 = ctx.r1.u32;
      if (stackHost != nullptr) {
        ctx.r1.u64 = mcla::kernel::MapVirtual(
                         static_cast<uint8_t *>(stackHost) + 0x40000u - 64u) &
                     ~15u;
        MCLA_LOG_WARN("GATE-STACK own guest stack r1={:08X} (caller's was {:08X})",
                      ctx.r1.u32, callerR1);
      } else {
        MCLA_LOG_WARN("GATE-STACK 256K userHeap alloc FAILED, gate reuses caller r1={:08X}",
                      ctx.r1.u32);
      }
      uint32_t sing = 0;
      int waits = 0;
      for (; waits < 50; ++waits) {
        sing = 0;
        (void)mem.ReadU32BE(0x8287E26Cu, &sing);
        if (sing != 0 && sing != 0xCDCDCDCDu) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
      }
      MCLA_LOG_WARN("GATE-WAIT [8287E26C]={:08X} after {} ms", sing, waits * 10);
      auto &mem2 = mcla::kernel::GuestMemoryHeap::Instance();
    // T38.3f (2026-09-20): the four seed writes that used to be here are DELETED. The driver
    // used to publish [0x8288E6F0]=1, [0x82830ACC]=0, [0x82830AB8]=0 and [0x82830B14]=0 and then
    // call, by hand, exactly the functions those flags tell the gate to skip (raw decode:
    // 0x82131020 `lwz r11,4(r29)` / 0x82131028 `bc -> 0x8213103C` skips 0x82131030/1038). Now
    // the flags are only READ, so the log shows what the guest really has and the guest's own
    // branches decide what runs. (F-055: the stage deletions got UILOAD to fire; this removes
    // the last of the fabricated state that made that entry meaningless.)
    for (const uint32_t flag : {0x8288E6F0u, 0x82830ACCu, 0x82830AB8u, 0x82830B14u, 0x8288B9ACu,
                                0x82830998u}) {
      uint32_t v = 0;
      (void)mem2.ReadU32BE(flag, &v);
      MCLA_LOG_WARN("GATE-FLAG-READ [{:08X}] = {:08X} (read-only, T38.3f)", flag, v);
    }

    // ponytail: pump scheduler tick semaphore (0x40004D7C) now so UILOAD's KeWait
    // doesn't park forever on an unsignaled semaphore.
    ::SignalSchedulerTickPublic();

    constexpr uint32_t kBootGateAddr = 0x82131008;
    if (auto *gateFn = mcla::kernel::g_memory.FindFunction(kBootGateAddr)) {
      // T38.3f: this is now the ONE guest entry the host forces here — sub_82131008 itself,
      // with no seeded flags and no hand-staged callees (see the block below).
      // ponytail: fresh ctx per house style (W32/W34 levers); gate takes no args, propagate stack only
      PPCContext g{};
      g.r1.u64 = ctx.r1.u64;
      g.r13.u64 = ctx.r13.u64;
      g.fpscr = ctx.fpscr;
      g.fpscr.disableFlushModeUnconditional();

      // Every guest call below runs on `g`, not on the caller's ctx: publish it so a
      // fault inside the gate reports THIS frame (F-046 — the old dumps printed the
      // boot thread's root context and every session read them as the faulting one).
      mcla::boot::FaultContextScope gateCtx(&g, "forced-boot-gate");

      // ponytail: create GFx loader object BEFORE gate stages so it exists even if gate hangs
      // The ctor 824C6F08 writes vtable 0x820736DC at offset 0 and 0x820736B0 at offset 672.
      MCLA_LOG_ERROR("GFX-BLOCK: entered pre-gate");
      // 1024B: ctor 824C6F08 writes obj+740+68/+72 (=+808/+812) and 6F70 reads
      // [obj+816]; Alloc(800) truncated both and corrupted the heap.
      uint32_t gfxLoader = mem.Alloc(1024, 16);
      MCLA_LOG_ERROR("GFX-ALLOC loader={:08X} null={}", gfxLoader, gfxLoader == 0);
      if (gfxLoader) {
        for (uint32_t off = 0; off < 1024; off += 4)
          (void)mem.WriteU32BE(gfxLoader + off, 0);
        if (auto *ctorFn = mcla::kernel::g_memory.FindFunction(0x824C6F08u)) {
          MCLA_LOG_ERROR("GFX-CTOR-FN found at 824C6F08");
          PPCContext gfxP{};
          gfxP.r1.u64 = ctx.r1.u64;
          gfxP.r13.u64 = ctx.r13.u64;
          gfxP.fpscr = ctx.fpscr;
          gfxP.r3.u64 = gfxLoader; // ctor expects object pointer in r3
          mcla::boot::FaultContextScope gfxCtx(&gfxP, "gfx-loader-ctor");
          MCLA_LOG_ERROR("GFX-CTOR entering loader={:08X}", gfxLoader);
          ctorFn(gfxP, mcla::kernel::g_memory.base);
          uint32_t vt = 0, vt2 = 0;
          (void)mem.ReadU32BE(gfxLoader, &vt);
          (void)mem.ReadU32BE(gfxLoader + 672, &vt2);
          MCLA_LOG_ERROR("GFX-CTOR done loader={:08X} vt0={:08X} vt672={:08X}", gfxLoader, vt, vt2);
          // Faithful: ctor 824C6F08 writes vt0=0x820736DC, vt672=0x820736B0
          // (generated ppc_recomp.94.cpp:3559-3587, single-arg r3 only).
          // Prior D8/B8 overwrite was off-by-4 (off_820736DC confusion) — verify only.
          if (vt != 0x820736DCu || vt2 != 0x820736B0u) {
            MCLA_LOG_ERROR("GFX-CTOR-VT-MISMATCH loader={:08X} got {:08X}/{:08X} want 820736DC/820736B0",
                           gfxLoader, vt, vt2);
          }
        } else {
          MCLA_LOG_ERROR("GFX-CTOR-FN NOT FOUND at 824C6F08");
        }
      } else {
        MCLA_LOG_ERROR("GFX-ALLOC FAILED");
      }

      MCLA_LOG_WARN("BOOT-GATE started on boot worker thread");
      s_inUILoad.store(true);
      struct UiLoadGuard {
        ~UiLoadGuard() { s_inUILoad.store(false); }
      } uiGuard;

      // Reserve 4 KB guest stack window for the gate and everything it calls; never
      // reuse the caller's live frame (prior r1+80/84 overwrote the LR-save area).
      // T38.3f: 256 B was enough for the hand-staged leaf calls, but the gate now runs
      // its own tree (0x82131010 `stwu r1,-128(r1)` plus nested frames), so the reserve
      // has to cover nested guest frames instead of one leaf.
      uint32_t stageStack = 0;
      {
        auto &mm = mcla::kernel::GuestMemoryHeap::Instance();
        const uint32_t rs = (g.r1.u32 - 4096u) & ~15u;
        uint32_t probe = 0;
        uint32_t probeLo = 0;
        if (rs && mm.ReadU32BE(rs, &probe) && mm.ReadU32BE(rs + 4080u, &probeLo)) {
          stageStack = rs;
          g.r1.u32 = rs;
        } else {
          MCLA_LOG_WARN("GATE-STAGE no 4K stack reserve, keeping r1={:08X}", g.r1.u32);
        }
      }
      // T38.3f (2026-09-20): the hand-staged calls (sub_821C0750 x2 + UILOAD sub_822C0980)
      // are DELETED. They existed only to isolate a hang point after the gate's own
      // prologue crashed, and they contradicted the flag seeds that are now gone: the guest
      // reaches them itself at 0x82131054 / 0x821310B0 with r1-relative out-params and
      // r3=[0x82830998], and it compares their results against [0x827D7500+44] before
      // deciding (raw decode of 0x82131008-0x821310D0). Running the real function is the
      // only measurement that says whether the boot path can advance without a host
      // stand-in (F-055 named the last fabrication; this deletes it).
      // lr is the caller's own return address, so `mflr r12` at 0x82131008 sees a frame
      // this host actually called from.
      g.lr = ctx.lr;
      MCLA_LOG_WARN("BOOT-GATE-ENTER 82131008 r1={:08X} r13={:08X} lr={:08X} reserve={:08X} (no seeds, T38.3f)",
                    g.r1.u32, g.r13.u32, (uint32_t)g.lr, stageStack);
      gateFn(g, mcla::kernel::g_memory.base);
      MCLA_LOG_WARN("BOOT-GATE-RETURN 82131008 r3={:08X} r1={:08X}", g.r3.u32, g.r1.u32);
      MCLA_LOG_WARN("BOOT-GATE stages done on boot worker thread r1={:08X}", g.r1.u32);

      // Factory 82488C98 DISABLED: generated ppc_recomp.88.cpp:14741 shows
      // (parent:r3 needs >=11576B for +11572 store, r4 index/flags, r5 ignored,
      // r6 required config deref [r6+20]/[r6+24] via 82257678; zero calls to
      // 824C6F08; movie lands at [parent+11572], never dest+4). Calling with
      // r4=r5=r6=0 + Alloc(800) guarantees early-out/AV + heap overflow, and
      // reading dest+4 always yields 0. Next: trace a real r6 config from a
      // 82257678 caller, alloc >=11576, or drive 824C6F70(obj) lifecycle
      // (824880F8 creates [obj+4] movie) then reuse W34-LOOKUP/PARSE-FLAG.
      MCLA_LOG_ERROR("GFX-FACTORY-SKIP 82488C98 needs real r6 config + 11576B parent (see ppc_recomp.88)");
      (void)mem;
    }
    }).detach();
  }

  uint32_t obj = mem.Alloc(72, 16);
  if (obj == 0) {
    ctx.r3.u64 = 0;
    return;
  }
  for (uint32_t off = 0; off < 72; off += 4)
    (void)mem.WriteU32BE(obj + off, 0);
  if (auto *initFn = mcla::kernel::g_memory.FindFunction(0x82188CF8u)) {
    PPCContext newCtx;
    newCtx.r1 = ctx.r1;
    newCtx.r13 = ctx.r13;
    newCtx.fpscr = ctx.fpscr;
    newCtx.r3.u64 = obj;
    mcla::boot::FaultContextScope initCtx(&newCtx, "tls-alloc72-init");
    initFn(newCtx, mcla::kernel::g_memory.base);
  }
  ctx.r3.u64 = obj;
  LogFabricatedShader("FIX-821873E8 HANDOFF", obj);
}

PPC_FUNC(sub_82413588) {
  // r8 is caller-volatile under the recomp ABI - the callee clobbers ctx.r8
  // immediately after saving it to a callee-saved register. Capture the
  // out-pointer BEFORE transferring control.
  const uint32_t outPtr = ctx.r8.u32;

  static std::atomic<bool> entryLogged{false};
  if (!entryLogged.exchange(true)) {
    MCLA_LOG_INFO("DEVICE: create entry hit (out={:08X})", outPtr);
  }

  __imp__sub_82413588(ctx, base);

  if (outPtr != 0) {
    uint32_t dev = 0;
    if (mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(outPtr, &dev) &&
        dev != 0) {
      mcla::gpu::OnDeviceCreated(dev);
      mcla::gpu::RedirectDefaultRenderStateSlots(dev);
      mcla::gpu::RedirectFirstRealRenderStateSlot(dev);
    } else {
      static std::atomic<bool> warned{false};
      if (!warned.exchange(true)) {
        MCLA_LOG_WARN("DEVICE: create produced no device (out={:08X})", outPtr);
      }
    }
  }
}

// P4' step 2 runtime thunk: proves guest -> synthetic VA -> host dispatch.
void HostRsRealPassthrough(PPCContext &__restrict ctx, uint8_t *base) {
  const uint32_t n = s_rsRealThunkHits.fetch_add(1) + 1;
  if (n <= 12 || (n % 500) == 0)
    MCLA_LOG_INFO("DEVICE: RS-real-thunk hit #{} r3={:08X} r4={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32);
  if (PPCFunc *orig =
          mcla::kernel::g_memory.FindFunction(mcla::gpu::kRealSlotOriginal))
    orig(ctx, base);
}

// Log-only probe thunk: records the hit, does NOT call the original - used to
// discover hot render-state slots; originals remain at their guest addresses.
void HostRsRealPassthroughLogOnly(PPCContext &__restrict ctx, uint8_t *base) {
  const uint32_t n = s_rsLogOnlyThunkHits.fetch_add(1) + 1;
  if (n <= 20 || (n % 1000) == 0)
    MCLA_LOG_INFO("DEVICE: RS-logonly-thunk hit #{} r3={:08X} r4={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32);
}

// ---------------------------------------------------------------------------
// P4' PIVOT: MCLA never dispatches via device FP tables (see PIVOT FINDING).
// State/draw intent flows DIRECTLY through these helpers. Global-scope strong
// overrides intercept every caller; passthrough preserves behavior.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411180);
static std::atomic<uint32_t> s_h11180{0};
static std::atomic<uint32_t> s_h11180done{0};
PPC_FUNC(sub_82411180) {
  const uint32_t n = s_h11180.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  uint32_t mask = 0, subctx = 0, published4 = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 14900, &mask);
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
      (void)mem.ReadU32BE(subctx + 4, &published4);
  }
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411180 hit #{} r3={:08X} r4={:08X} "
                  "r5={:08X} msk={:X} sc={:X} wb4={:X}",
                  n, dev, ctx.r4.u32, ctx.r5.u32, mask, subctx, published4);
  __imp__sub_82411180(ctx, base);
  const uint32_t d = s_h11180done.fetch_add(1) + 1;
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411180 RETURNED #{} (r3={:08X})", d,
                  ctx.r3.u32);
}

PPC_FUNC_IMPL(__imp__sub_82411618);
static std::atomic<uint32_t> s_h11618{0};
PPC_FUNC(sub_82411618) {
  const uint32_t n = s_h11618.fetch_add(1) + 1;
  if (n <= 12 || (n % 2000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411618 hit #{} r3={:08X}", n, ctx.r3.u32);
  __imp__sub_82411618(ctx, base);
}

// PRIMARY CHOKE POINT (reverser-pinned 2026-08-23): sub_82411640 is a
// push-buffer SPACE RESERVER, not a packet writer:
//   sub_82411640(dev /*r3*/, flags /*r4*/, sizeSlot /*r5*/, alignBytes /*r6*/)
// r5 points to ONE u32 {requested bytes}; only desc[0] is read by the guest.
// Return r3 = reserved ring-window VA; desc[0] written back = consumed bytes.
// => the reserved window holds FULLY-FORMED driver output for every
//    submission class; capture it AFTER passthrough.
// Submission classes (ppc_recomp.77.cpp evidence):
//   (flags=1, align=32) -> sub_82411B10 descriptor batches
//   (flags=1, align=4)  -> sub_82412710 indirect-dispatch packet
//   (flags=2, align=32) -> sub_82412318 raw packet envelopes
// PM4 classification ground truth:
// .research/xenia/src/xenia/gpu/xenos.h:1572-1664. Capture-only: bounds-checked
// BE reads, no D3D12, no invented fields.
namespace {

constexpr uint32_t kPktCapMaxDwords = 256; // defensive cap per window read
constexpr uint32_t kPktCapFullDumps = 16;  // full hex dumps before stats-only
constexpr uint32_t kPktCapPendingMax = 64; // deferred-window ring capacity

// Reserved windows are EMPTY at sub_82411640 return - builders (sub_82411B10 /
// sub_82411DC0) fill them afterwards. Capture is therefore DEFERRED: entries
// are queued here and scanned on the NEXT reservation, when their bytes are
// actually present in the ring.
struct PendingWindow {
  uint32_t addr;
  uint32_t dwords;
  uint32_t flags;
  uint32_t alignBytes;
};
static std::mutex s_pendingMtx;
PendingWindow g_pending[kPktCapPendingMax] = {};
uint32_t g_pendingCount = 0;

struct PktCapStats {
  std::atomic<uint32_t> descriptors{0};
  std::atomic<uint32_t> dwords{0};
  std::atomic<uint32_t> clsDescBatch{0};   // flags=1 align>=32
  std::atomic<uint32_t> clsIndirect{0};    // flags=1 align<32
  std::atomic<uint32_t> clsRawEnvelope{0}; // flags!=1 align>=32
  std::atomic<uint32_t> type0{0};
  std::atomic<uint32_t> type1{0};
  std::atomic<uint32_t> type2Nop{0};
  std::atomic<uint32_t> t3Nop{0};          // 0x10
  std::atomic<uint32_t> t3DrawIndx{0};     // 0x22
  std::atomic<uint32_t> t3DrawIndx2{0};    // 0x36
  std::atomic<uint32_t> t3ImLoad{0};       // 0x27 / 0x2b
  std::atomic<uint32_t> t3SetConstant{0};  // 0x2d
  std::atomic<uint32_t> t3LoadAluConst{0}; // 0x2f
  std::atomic<uint32_t> t3MemWrite{0};     // 0x3d
  std::atomic<uint32_t> t3EventWrite{0};   // 0x46, 0x58-0x5b
  std::atomic<uint32_t> t3Other{0};
  std::atomic<uint32_t> clampedWindow{0}; // read clamp / VA-space overrun
  std::atomic<uint32_t> midPacket{0};     // scan ended inside a packet
  std::atomic<uint32_t> oddBytes{0};      // consumed not dword-aligned
};

PktCapStats g_pktCap;

// Session: distinguish dummy (null-desc) vs plausible geometry at 20BA8.
// Explains DRAW_INDEXED=0 without re-reading the full SUBMIT-census dump.
std::atomic<uint32_t> g_submitDummy{0};
std::atomic<uint32_t> g_submitPlausible{0};

bool IsEventOpcode(uint32_t op) {
  return op == 0x46 || (op >= 0x58 && op <= 0x5b);
}

void ClassifyT3(uint32_t op) {
  switch (op) {
  case 0x10:
    ++g_pktCap.t3Nop;
    break;
  case 0x22:
    ++g_pktCap.t3DrawIndx;
    break;
  case 0x36:
    ++g_pktCap.t3DrawIndx2;
    break;
  case 0x27:
  case 0x2b:
    ++g_pktCap.t3ImLoad;
    break;
  case 0x2d:
    ++g_pktCap.t3SetConstant;
    break;
  case 0x2f:
    ++g_pktCap.t3LoadAluConst;
    break;
  case 0x3d:
    ++g_pktCap.t3MemWrite;
    break;
  default:
    if (IsEventOpcode(op))
      ++g_pktCap.t3EventWrite;
    else
      ++g_pktCap.t3Other;
    break;
  }
}

void ScanPackets(const uint32_t *w, uint32_t n) {
  // Packet sizes per .research/xenia/src/xenia/gpu/command_processor.cc:
  // type-0 = header + (((p>>16)&0x3FFF)+1) dwords (:641),
  // type-1 = header + TWO payload dwords (:666-670), type-2 = 1 dword,
  // type-3 = header + (((p>>16)&0x3FFF)+1) payload dwords.
  uint32_t i = 0;
  while (i < n) {
    const uint32_t hdr = w[i];
    uint32_t next = i + 1;
    switch (hdr >> 30) {
    case 0:
      ++g_pktCap.type0;
      next = i + ((hdr >> 16) & 0x3FFFu) + 2;
      break;
    case 1:
      ++g_pktCap.type1;
      next = i + 3;
      break;
    case 2:
      ++g_pktCap.type2Nop;
      next = i + 1;
      break;
    default:
      ClassifyT3((hdr >> 8) & 0xFFu);
      next = i + ((hdr >> 16) & 0x3FFFu) + 2;
      break;
    }
    if (next > n) {
      ++g_pktCap.midPacket; // window ends inside a packet; stop cleanly
      return;
    }
    i = next;
  }
}

} // namespace

PPC_FUNC_IMPL(__imp__sub_82411640);
static std::atomic<uint32_t> s_h11640{0};

namespace {

// Read+classify one (previously reserved) ring window. Called from the 640
// override AFTER the window has had time to be filled by its builder.
void CaptureWindow(uint32_t n, uint32_t dev, const PendingWindow &pw) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  if (pw.dwords == 0)
    ++g_pktCap.oddBytes;

  // Clamp to capture buffer AND to guest VA space (u64 math: no wrap near
  // 0xFFFFFFFF into low RAM).
  uint64_t availDwords = pw.dwords;
  if (availDwords > kPktCapMaxDwords)
    availDwords = kPktCapMaxDwords;
  if (pw.addr == 0)
    return;
  const uint64_t vaRoomDwords = (uint64_t(0x100000000ull) - pw.addr) / 4u;
  if (vaRoomDwords < availDwords)
    availDwords = vaRoomDwords;

  const uint32_t wordCount = uint32_t(availDwords);
  if (wordCount < pw.dwords)
    ++g_pktCap.clampedWindow;

  uint32_t words[kPktCapMaxDwords] = {};
  bool readOk = wordCount > 0;
  for (uint32_t i = 0; i < wordCount; ++i)
    readOk &= mem.ReadU32BE(pw.addr + i * 4u, &words[i]);

  if (!readOk) {
    static std::atomic<bool> readWarned{false};
    if (!readWarned.exchange(true))
      MCLA_LOG_WARN("PKT-CAP: window read failed dev={:08X} @ {:08X}", dev,
                    pw.addr);
    return;
  }

  ++g_pktCap.descriptors;
  g_pktCap.dwords.fetch_add(wordCount, std::memory_order_relaxed);

  // Consumption accounting: these bytes are resident ? kernel CP may fetch
  // through them. Advances the ctx[+0]/[+4] watermark + progress counter
  // by the FULL reserved size (not the clamped read).
  mcla::gpu::CpConsumePushWindow(pw.addr + pw.dwords * 4u, pw.dwords);

  if ((pw.flags & 1u) != 0) {
    if (pw.alignBytes >= 32)
      ++g_pktCap.clsDescBatch;
    else
      ++g_pktCap.clsIndirect;
  } else if (pw.alignBytes >= 32) {
    ++g_pktCap.clsRawEnvelope;
  }
  ScanPackets(words, wordCount);

  if (n <= kPktCapFullDumps) {
    std::string hex;
    hex.reserve(wordCount * 9);
    for (uint32_t i = 0; i < wordCount; ++i)
      fmt::format_to(std::back_inserter(hex), "{:08X} ", words[i]);
    MCLA_LOG_INFO("PKT-CAP #{:04X}: dev={:08X} f={} a={} win={:08X} n={} | {}",
                  n, dev, pw.flags, pw.alignBytes, pw.addr, pw.dwords, hex);
  }
}

void LogSummary(uint32_t n) {
  MCLA_LOG_INFO(
      "PKT-CAP summary: desc={} dw={} descBatch={} indirect={} rawEnv={} "
      "t0={} t1={} t2nop={} t3nop={} draw_indx={} draw_indx2={} "
      "im_load={} set_const={} load_alu={} mem_write={} event_write={} "
      "other_t3={} clamped={} midpkt={} oddbytes={} "
      "submitPlausible={} submitDummy={}",
      g_pktCap.descriptors.load(), g_pktCap.dwords.load(),
      g_pktCap.clsDescBatch.load(), g_pktCap.clsIndirect.load(),
      g_pktCap.clsRawEnvelope.load(), g_pktCap.type0.load(),
      g_pktCap.type1.load(), g_pktCap.type2Nop.load(), g_pktCap.t3Nop.load(),
      g_pktCap.t3DrawIndx.load(), g_pktCap.t3DrawIndx2.load(),
      g_pktCap.t3ImLoad.load(), g_pktCap.t3SetConstant.load(),
      g_pktCap.t3LoadAluConst.load(), g_pktCap.t3MemWrite.load(),
      g_pktCap.t3EventWrite.load(), g_pktCap.t3Other.load(),
      g_pktCap.clampedWindow.load(), g_pktCap.midPacket.load(),
      g_pktCap.oddBytes.load(), g_submitPlausible.load(),
      g_submitDummy.load());
}

} // namespace

PPC_FUNC(sub_82411640) {
  const uint32_t n = s_h11640.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t flags = ctx.r4.u32;
  const uint32_t slotAddr = ctx.r5.u32;
  const uint32_t alignBytes = ctx.r6.u32; // volatile reg: snapshot pre-call

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t requested = 0;
  const bool haveReq = mem.ReadU32BE(slotAddr, &requested);
  if (!haveReq) {
    static std::atomic<bool> slotWarned{false};
    if (!slotWarned.exchange(true))
      MCLA_LOG_WARN("PKT-CAP: size-slot read failed dev={:08X} @ {:08X}", dev,
                    slotAddr);
    __imp__sub_82411640(ctx, base);
    return;
  }

  __imp__sub_82411640(ctx, base);

  // Post-passthrough: consumed bytes in slot[0], reserved window in r3.
  uint32_t consumed = 0;
  if (!mem.ReadU32BE(slotAddr, &consumed))
    return;

  const uint32_t window = ctx.r3.u32;

  // Drain previously reserved windows first - their builders have filled
  // them by now. THEN queue the freshly reserved (still empty) window.
  {
    std::lock_guard<std::mutex> lock(s_pendingMtx);
    for (uint32_t i = 0; i < g_pendingCount; ++i)
      CaptureWindow(n, dev, g_pending[i]);
    g_pendingCount = 0;

    if (window != 0 && consumed != 0 && g_pendingCount < kPktCapPendingMax) {
      g_pending[g_pendingCount].addr = window;
      g_pending[g_pendingCount].dwords = consumed / 4u;
      g_pending[g_pendingCount].flags = flags;
      g_pending[g_pendingCount].alignBytes = alignBytes;
      ++g_pendingCount;
    }
  }

  if (n <= 16 || (n % 5000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411640 hit #{} dev={:08X} f={} req={}", n,
                  dev, flags, requested);

  // 640 fires ~handful of times per boot (init/state batches), so summarize
  // every hit during the early run + on a LOW cadence afterwards - this
  // guarantees per-run gate metrics regardless of submission volume.
  if (n <= 32 || (n % 100) == 0) {
    {
      std::lock_guard<std::mutex> lock(s_pendingMtx);
      for (uint32_t i = 0; i < g_pendingCount; ++i)
        CaptureWindow(n, dev, g_pending[i]);
      g_pendingCount = 0;
    }
    LogSummary(n);
  }
}

// ---------------------------------------------------------------------------
// P4' submit-family census (reverser-ranked per-frame seam candidates).
// Log-only passthrough overrides; each size-class helper embeds its OWN
// reserver clone (dev+14908/14916 accessed directly in 11840 at
// ppc_recomp.77.cpp:20129), which is why 640 stays cold while frames flow.
// Ranked targets: sub_82420BA8 (per-batch draw submit), sub_82413660 (draw-
// packet builder), sub_8241BD08 (flush/kick), sub_82429570/sub_824294E0
// (present kickers, DEBCBEEF marker).
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// P4' CAPTURE (session 24): SubmitBatch = per-batch geometry submit
// (DrawIndexedPrimitive-equivalent, Ghidra-verified). Capture geometry args
// + device state snapshot BEFORE passthrough; legacy rendering unchanged.
// State lives in device shadow blocks - no per-RS-handler overrides needed.
// ---------------------------------------------------------------------------
struct CapturedDrawV1 {
  uint32_t primTypeFlags;
  uint32_t vbDesc[2][4];   // r5/r7 raw {base,stride,size,size}
  uint32_t ibDesc[4];      // r6 raw
  uint32_t ibBase;         // [+0x20] page-aligned | fmt bits0-5
  uint32_t ibCounts;       // [+0x24] 11/13-bit halves split by tiling
  uint32_t indexWidthBits; // [+0x28] bits31-30
  uint32_t dirtyMask[6];   // dev+0x10/+0x18/+0x20 (3x u64)
  static constexpr uint32_t kShadowDwords = 437; // 0x28CC..0x2FA0
  uint32_t shadow[kShadowDwords];
  uint32_t seq;
};

static CapturedDrawV1 g_lastDraw{};
static std::atomic<uint32_t> g_capturedDrawCount{0};

static uint32_t DecodeIndexedCount(uint32_t packedCounts,
                                   uint32_t indexWidthBits,
                                   uint32_t tilingFlags) {
  const uint32_t widthAdjust = ((indexWidthBits >> 31) & 0x1u) * 2u + 1u;
  if ((tilingFlags & 0x600u) == 0x400u)
    return (packedCounts & 0x7FFu) + widthAdjust;
  return (packedCounts & 0x1FFFu) + widthAdjust;
}

const CapturedDrawV1 *mcla_gpu_GetLastCapturedDraw(uint32_t *outTotal);

const CapturedDrawV1 *mcla_gpu_GetLastCapturedDraw(uint32_t *outTotal) {
  if (outTotal) {
    *outTotal = g_capturedDrawCount.load(std::memory_order_relaxed);
  }
  return &g_lastDraw;
}

PPC_FUNC_IMPL(__imp__sub_82420BA8);
static std::atomic<uint32_t> s_h20BA8{0};
PPC_FUNC(sub_82420BA8) {
  // Single owner of the draw-builder seam (S1â€“S3 consolidation). The removed
  // native_renderer dual-owner hook folded its duties in here.
  mcla::renderer::RecordDrawBuild();
  const uint32_t n = s_h20BA8.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const bool devOk = dev != 0 && mem.IsValid(dev + 0x2FA0, 4);
  if (devOk) {
    const uint32_t r5 = ctx.r5.u32, r6 = ctx.r6.u32, r7 = ctx.r7.u32;
    const bool vb0Ok = mem.IsValid(r5, 16);
    const bool vb1Ok = mem.IsValid(r7, 16);
    const bool ibOk = mem.IsValid(r6, 0x2C);
    CapturedDrawV1 cap{};
    cap.primTypeFlags = ctx.r4.u32;
    if (vb0Ok && vb1Ok && ibOk) {
      for (uint32_t i = 0; i < 4; ++i) {
        (void)mem.ReadU32BE(r5 + i * 4, &cap.vbDesc[0][i]);
        (void)mem.ReadU32BE(r7 + i * 4, &cap.vbDesc[1][i]);
        (void)mem.ReadU32BE(r6 + i * 4, &cap.ibDesc[i]);
      }
      (void)mem.ReadU32BE(r6 + 0x20, &cap.ibBase);
      (void)mem.ReadU32BE(r6 + 0x24, &cap.ibCounts);
      (void)mem.ReadU32BE(r6 + 0x28, &cap.indexWidthBits);
    }
    for (uint32_t w = 0; w < 6; ++w) {
      (void)mem.ReadU32BE(dev + 0x10 + w * 4, &cap.dirtyMask[w]);
    }
    for (uint32_t d = 0; d < CapturedDrawV1::kShadowDwords; ++d) {
      (void)mem.ReadU32BE(dev + 0x28CC + d * 4, &cap.shadow[d]);
    }
    cap.seq = n;

    {
      std::lock_guard<std::mutex> lock(g_drawMutex);
      g_lastDraw = cap;
    }
    const uint32_t total = g_capturedDrawCount.fetch_add(1) + 1;
    if (total == 1 || (total % 500) == 0) {
      MCLA_LOG_INFO(
          "P4'-CAPTURE draw #{} prim={:08X} ibBase={:08X} ibCnt={:08X} "
          "dirty={:08X}{:08X}",
          total, cap.primTypeFlags, cap.ibBase, cap.ibCounts, cap.dirtyMask[1],
          cap.dirtyMask[0]);
    }
  }
  if (n <= 12 || (n % 1000) == 0) {
    uint32_t r5w0 = 0, r5w1 = 0, r5w2 = 0, r5w3 = 0;
    uint32_t r6w0 = 0, r6w1 = 0, r6w2 = 0, r6w3 = 0;
    if (ctx.r5.u32 != 0 && mem.IsValid(ctx.r5.u32, 16)) {
      (void)mem.ReadU32BE(ctx.r5.u32 + 0, &r5w0);
      (void)mem.ReadU32BE(ctx.r5.u32 + 4, &r5w1);
      (void)mem.ReadU32BE(ctx.r5.u32 + 8, &r5w2);
      (void)mem.ReadU32BE(ctx.r5.u32 + 12, &r5w3);
    }
    if (ctx.r6.u32 != 0 && mem.IsValid(ctx.r6.u32, 16)) {
      (void)mem.ReadU32BE(ctx.r6.u32 + 0, &r6w0);
      (void)mem.ReadU32BE(ctx.r6.u32 + 4, &r6w1);
      (void)mem.ReadU32BE(ctx.r6.u32 + 8, &r6w2);
      (void)mem.ReadU32BE(ctx.r6.u32 + 12, &r6w3);
    }
    uint32_t streamCount = 0, vb0base = 0, vb0stride = 0, vb0size = 0;
    if (dev != 0 && mem.IsValid(dev + 12748, 16)) {
      (void)mem.ReadU32BE(dev + 12748, &streamCount);
      (void)mem.ReadU32BE(dev + 12756, &vb0base);
      (void)mem.ReadU32BE(dev + 12760, &vb0stride);
      (void)mem.ReadU32BE(dev + 12764, &vb0size);
    }
    MCLA_LOG_INFO("SUBMIT-census sub_82420BA8 #{} dev={:08X} flags={:X} lr={:08X} "
                  "streams={} vb0=[{:08X},{:08X},{:08X}] "
                  "r5={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "r6={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "r7={:08X} r8={:08X} r9={:08X} r10={:08X} "
                  "plausible={} dummy={}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr),
                  streamCount, vb0base, vb0stride, vb0size,
                  ctx.r5.u32, r5w0, r5w1, r5w2, r5w3,
                  ctx.r6.u32, r6w0, r6w1, r6w2, r6w3, ctx.r7.u32, ctx.r8.u32,
                  ctx.r9.u32, ctx.r10.u32,
                  g_submitPlausible.load(), g_submitDummy.load());
  }

  {
    mcla::native::DrawIndexedCommand dic{};
    dic.primitiveTopology = ctx.r4.u32 & 7u;
    if (ctx.r5.u32 != 0 && mem.IsValid(ctx.r5.u32, 16)) {
      (void)mem.ReadU32BE(ctx.r5.u32 + 0, &dic.vbAddr);
      (void)mem.ReadU32BE(ctx.r5.u32 + 4, &dic.vbStride);
      (void)mem.ReadU32BE(ctx.r5.u32 + 8, &dic.vbSize);
    }
    if (ctx.r6.u32 != 0 && mem.IsValid(ctx.r6.u32, 0x34)) {
      (void)mem.ReadU32BE(ctx.r6.u32 + 0, &dic.ibAddr);
      (void)mem.ReadU32BE(ctx.r6.u32 + 4, &dic.ibSize);
      (void)mem.ReadU32BE(ctx.r6.u32 + 8, &dic.ibFormat);
    }
    if (ctx.r6.u32 != 0 && mem.IsValid(ctx.r6.u32 + 0x24, 4)) {
      uint32_t ibCntRaw = 0;
      uint32_t ibWidthRaw = 0;
      uint32_t ibTilingRaw = 0;
      (void)mem.ReadU32BE(ctx.r6.u32 + 0x24, &ibCntRaw);
      (void)mem.ReadU32BE(ctx.r6.u32 + 0x28, &ibWidthRaw);
      (void)mem.ReadU32BE(ctx.r6.u32 + 0x30, &ibTilingRaw);
      dic.indexCount = DecodeIndexedCount(ibCntRaw, ibWidthRaw, ibTilingRaw);
      dic.startIndexLocation = 0;
      dic.baseVertexLocation = 0;
    }

    // Read shader program addresses from MclaGpuContext
    // Device struct layout: sqVsProgram @ +0x3184, sqPsProgram @ +0x3188
    if (dev != 0 && mem.IsValid(dev + 0x3188, 4)) {
      (void)mem.ReadU32BE(dev + 0x3184, &dic.vsProgram);
      (void)mem.ReadU32BE(dev + 0x3188, &dic.psProgram);
    }

    // P5' (B8): only enqueue draws with plausible geometry. The guest
    // calls this builder with null/dummy descriptors during init and
    // menu-state polling; forwarding those just burns queue slots and
    // gets discarded by the render thread's own validation anyway.
    const bool plausible = dic.vbAddr >= 0x10000u && dic.vbSize != 0 &&
                           dic.vbStride != 0 && dic.ibAddr >= 0x10000u &&
                           dic.ibSize != 0 && dic.indexCount != 0;
    if (plausible) {
      const uint32_t pl = g_submitPlausible.fetch_add(1) + 1;
      if (pl <= 8 || (pl % 200) == 0)
        MCLA_LOG_INFO("DRAW-GATE plausible #{} vb={:08X} ib={:08X} cnt={}", pl,
                      dic.vbAddr, dic.ibAddr, dic.indexCount);
      mcla::native::g_commandQueue.push(mcla::native::RenderCommand{
          mcla::native::RenderCommand::DRAW_INDEXED, dic});
    } else {
      const uint32_t du = g_submitDummy.fetch_add(1) + 1;
      if (du <= 8 || (du % 500) == 0)
        MCLA_LOG_INFO("DRAW-GATE dummy #{} vb={:08X}/{:X} ib={:08X}/{:X} "
                      "stride={} cnt={}",
                      du, dic.vbAddr, dic.vbSize, dic.ibAddr, dic.ibSize,
                      dic.vbStride, dic.indexCount);
    }
  }

  // Trace feed (folded from the removed native_renderer dual-owner hook).
  // The accumulator no-ops unless capture mode enabled it via
  // SetCaptureEnabled; the MclaGpuContext overlay is the pre-existing
  // capture-path pattern (S4 inventory â€” refactor with checked reads when
  // capture_hooks grows a checked-read API).
  if (dev != 0) {
    mcla::native::GetDrawAccumulator()->OnDrawBuild(
        reinterpret_cast<::MclaGpuContext*>(base + dev), ctx);
  }

  __imp__sub_82420BA8(ctx, base);
}

// ---------------------------------------------------------------------------
// Session 75b census (log-only, no behavior change): who binds streams and
// who enters the real draw wrapper. DRAW_INDEXED stays 0 because the
// 20BA8 hook only sees dummy li-r5=0 submits. Real chain (TU-mapped):
//   sub_8217A470 -> sub_8241BE78 (SetStreams, writes dev+12748 count +
//   VB descs at dev+12756) -> sub_8241C308 (r6 must be IB) -> sub_82420BA8
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_8241BE78);
static std::atomic<uint32_t> s_h41BE78{0};
PPC_FUNC(sub_8241BE78) {
  const uint32_t n = s_h41BE78.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("SETSTREAMS-census sub_8241BE78 #{} dev={:08X} count={:08X} "
                  "vbArray={:08X} extra={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8241BE78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241C308);
static std::atomic<uint32_t> s_h41C308{0};
PPC_FUNC(sub_8241C308) {
  const uint32_t n = s_h41C308.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("DRAWWRAP-census sub_8241C308 #{} dev={:08X} flags={:08X} "
                  "r5={:08X} r6={:08X} r7={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  ctx.r7.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8241C308(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8217A470);
static std::atomic<uint32_t> s_h17A470{0};
PPC_FUNC(sub_8217A470) {
  const uint32_t n = s_h17A470.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("SETSTREAMS-CALLER sub_8217A470 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} r6={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8217A470(ctx, base);
}

// Session 75c: real-draw dispatcher gate. sub_82227428 only reaches
// sub_8217A470 (SetStreams) when its dispatch dword == 0x20000000
// (explore mapping of the three bl sites). Loading-screen HUD uses the
// dummy path instead. Census r4 so we can see what type values actually
// arrive.
PPC_FUNC_IMPL(__imp__sub_82227428);
static std::atomic<uint32_t> s_h227428{0};
PPC_FUNC(sub_82227428) {
  const uint32_t n = s_h227428.fetch_add(1) + 1;
  if (n <= 32 || (n % 200) == 0) {
    MCLA_LOG_INFO("DRAWDISP-census sub_82227428 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} r6={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_82227428(ctx, base);
}

// Session 75c: first gate inside the SetStreams caller path.
PPC_FUNC_IMPL(__imp__sub_82178F38);
static std::atomic<uint32_t> s_h178F38{0};
PPC_FUNC(sub_82178F38) {
  __imp__sub_82178F38(ctx, base);
  const uint32_t n = s_h178F38.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("LOADGATE-census sub_82178F38 #{} ret={} lr={:08X}",
                  n, ctx.r3.s32, static_cast<uint32_t>(ctx.lr));
  }
}

// Session 75d (Ghidra): texture-registry special-name init.
// FUN_82180A30 creates the "none" / "nonresident" fallback objects that
// FUN_821811C0 special-cases by string compare. Called only from 82177248.
PPC_FUNC_IMPL(__imp__sub_82180A30);
static std::atomic<uint32_t> s_h180A30{0};
// Session 75k BOOT LIFE-SUPPORT (not a short-circuit of a guest gate):
// After TEXINIT creates the real "none" object at 0x82839CF0, insert
// names from globaltex.list into the named registry via the guest's own
// insert linker (821854C8). Lookups then HIT the none fallback instead of
// missing and minting CDCDCDCD 64-byte objects. Removes names once a real
// loader fills them (replace on re-insert).
PPC_FUNC_IMPL(__imp__sub_821854C8);
static void MclaBootstrapGlobaltexNames(uint8_t *base) {
  if (!kHostGlobaltexNameInjection)
    return;
  static std::atomic<bool> s_done{false};
  if (s_done.exchange(true))
    return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t noneObj = 0;
  (void)mem.ReadU32BE(0x82839CF0, &noneObj);
  if (noneObj == 0) {
    MCLA_LOG_WARN("GLOBTEX-BOOT skipped: none object not ready");
    return;
  }
  const char *paths[] = {
      "build/game_data/xarchive_cache/textures/global/cars/globaltex.list",
      "build/game_data/xarchive_cache/textures/global/city/globaltex.list",
  };
  int inserted = 0;
  for (const char *path : paths) {
    std::ifstream in(path);
    if (!in)
      continue;
    std::string line;
    while (std::getline(in, line)) {
      // format: "<name> <file>" â€” first token is the registry name
      const auto sp = line.find_first_of(" \t\r");
      std::string name = (sp == std::string::npos) ? line : line.substr(0, sp);
      while (!name.empty() && (name.back() == '\r' || name.back() == '\n'))
        name.pop_back();
      if (name.empty() || name[0] == '#')
        continue;
      const uint32_t nameAddr =
          mem.Alloc(static_cast<size_t>(name.size()) + 1, 16);
      if (nameAddr == 0)
        continue;
      (void)mem.WriteBytes(nameAddr, name.c_str(),
                           static_cast<uint32_t>(name.size()) + 1);
      PPCContext tmp{};
      tmp.r3.u32 = noneObj;
      tmp.r4.u32 = nameAddr;
      __imp__sub_821854C8(tmp, base);
      ++inserted;
    }
  }
  MCLA_LOG_INFO("GLOBTEX-BOOT inserted={} noneObj={:08X} (file-cache; served "
                "bodies follow via GLOBTEX-SERVE)",
                inserted, noneObj);
  // w19: if any POSTOPEN-SERVE list bodies already landed, feed them too.
  MclaBootstrapGlobaltexFromServed(base);
}

PPC_FUNC(sub_82180A30) {
  const uint32_t n = s_h180A30.fetch_add(1) + 1;
  MCLA_LOG_INFO("TEXINIT-census sub_82180A30 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82180A30(ctx, base);
  if (n == 1)
    MclaBootstrapGlobaltexNames(base);
}

PPC_FUNC_IMPL(__imp__sub_82177248);
static std::atomic<uint32_t> s_h177248{0};
PPC_FUNC(sub_82177248) {
  const uint32_t n = s_h177248.fetch_add(1) + 1;
  MCLA_LOG_INFO("TEXINIT-CALLER sub_82177248 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82177248(ctx, base);
}

// Graphics/resource init bundle that calls 82177248 (none/nonresident tex init).
PPC_FUNC_IMPL(__imp__sub_82177948);
static std::atomic<uint32_t> s_h177948{0};
PPC_FUNC(sub_82177948) {
  const uint32_t n = s_h177948.fetch_add(1) + 1;
  MCLA_LOG_INFO("GFXINIT-census sub_82177948 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82177948(ctx, base);
}

// ===========================================================================
// Stage C: Shader dictionary hash-table hydration
//
// MEASURED (F-085/F-086, 2026-09-21). The table address 0x82839F70 is
// raw-verified: sub_82188E50 holds `lis r11,0x8284` at 0x82188E5C and
// `addi r28,r11,-0x6090` at 0x82188E60. The old account here ("empty table ->
// sub_82189138 returns -1 -> star_glow fatal") is REFUTED: w38s.log:3975 shows
// DICTLOOKUP-OK slot=10 followed by a different fatal, and w41i.log calls
// sub_82189138 zero times while the same fatal occurs, so the lookup is not on
// the fatal path. sub_821CB488 is a 7-byte "memory:" comparator, not a resource
// handler lookup. The ten entries written below all carry a zero word at +4 and
// an empty name, so a match by name hash is not possible.
// Kept in tree pending a measured behaviour-neutral removal (soak x2).
// ===========================================================================

// Hash table hydration: populate 0x82839F70 from factory-created entries.
static uint32_t s_factoryEntryPtrs[256] = {};
static std::atomic<uint32_t> s_factoryEntryCount{0};

static void HydrateShaderHashTable() {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  constexpr uint32_t TABLE = 0x82839F70;
  constexpr uint32_t SLOT_COUNT = 256;

  uint32_t count = s_factoryEntryCount.load();
  uint32_t inserted = 0;

  for (uint32_t i = 0; i < count && inserted < SLOT_COUNT; ++i) {
    uint32_t entry = s_factoryEntryPtrs[i];
    if (entry == 0 || !mem.IsValid(entry, 112))
      continue;

    uint32_t slot = 0;
    for (; slot < SLOT_COUNT; ++slot) {
      uint32_t val = 0;
      mem.ReadU32BE(TABLE + slot * 4, &val);
      if (val == 0)
        break;
    }
    if (slot >= SLOT_COUNT)
      break;

    mem.WriteU32BE(TABLE + slot * 4, entry);
    ++inserted;

    uint32_t w[4] = {};
    for (int j = 0; j < 4; ++j)
      (void)mem.ReadU32BE(entry + j * 4, &w[j]);
    MCLA_LOG_INFO("DICT-HYDRATE slot={} entry={:08X} [{:08X} {:08X} {:08X} "
                  "{:08X}]",
                  slot, entry, w[0], w[1], w[2], w[3]);
  }

  MCLA_LOG_INFO("DICT-HYDRATE done: {}/{} entries -> hash table @0x{:08X}",
                inserted, count, TABLE);
}

// Census on sub_82189138 (lookup-or-insert).
// ASSUMED, not verified (F-085/F-086): "scans 256 slots at 0x82839F70 comparing
// entry+4 hash with target". Measured instead: sub_82189138 builds an
// "embedded:/" path at +0xA8 (0x821891E0, literal 0x8200B39C, len 11), and it
// was called 0 times in w41i while the star_glow fatal still occurred.
PPC_FUNC_IMPL(__imp__sub_82189138);
static std::atomic<uint32_t> s_h189138{0};
PPC_FUNC(sub_82189138) {
  const uint32_t n = s_h189138.fetch_add(1) + 1;
  const uint32_t name = ctx.r3.u32;

  char nameStr[80] = {0};
  if (name != 0 && name >= 0x82000000 && name < 0x82AD3000) {
    const char *p =
        static_cast<const char *>(mcla::kernel::MmGetHostAddress(name));
    if (p) {
      for (int i = 0; i < 79 && p[i]; ++i)
        nameStr[i] = (p[i] >= 32 && p[i] < 127) ? p[i] : '.';
    }
  }

  const uint32_t lr = static_cast<uint32_t>(ctx.lr);

  __imp__sub_82189138(ctx, base);

  const int32_t result = static_cast<int32_t>(ctx.r3.s32);

  if (result == -1) {
    MCLA_LOG_WARN("DICTLOOKUP-MISS #{} name='{}' ({:08X}) lr={:08X}",
                  n, nameStr, name, lr);
  } else if (n <= 32 || (n % 50) == 0) {
    MCLA_LOG_INFO("DICTLOOKUP-OK #{} name='{}' ({:08X}) slot={} lr={:08X}",
                  n, nameStr, name, result, lr);
  }
}

// Session 75e (IDA): pgDictionary load/register caller.
// sub_82197598 links the dict into active list 0x82839ED0 (not a
// recompiled entry â€” no __imp__). Census its mapped caller instead.
// Stage C: collect entry pointers for hash table hydration.
PPC_FUNC_IMPL(__imp__sub_8218B000);
static std::atomic<uint32_t> s_h18B000{0};
PPC_FUNC(sub_8218B000) {
  const uint32_t n = s_h18B000.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;

  // Collect entry pointer for hash table hydration (Stage C)
  if (obj != 0 && s_factoryEntryCount.load() < 256) {
    s_factoryEntryPtrs[s_factoryEntryCount.fetch_add(1)] = obj;
  }

  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("TEXDICT-CALLER sub_8218B000 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, obj, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8218B000(ctx, base);
  if (n <= 12) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t w[8] = {};
    if (obj != 0 && mem.IsValid(obj, 32)) {
      for (int i = 0; i < 8; ++i)
        (void)mem.ReadU32BE(obj + i * 4, &w[i]);
    }
    MCLA_LOG_INFO("TEXDICT-OBJ #{} @{:08X} [{:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X}]",
                  n, obj, w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7]);
  }

  // Stage C: after factory completes all 10 entries, hydrate the hash table
  if (n == 10) {
    MCLA_LOG_INFO("TEXDICT-CALLER #10 reached â€” triggering hash table hydration");
    HydrateShaderHashTable();
  }
}

// Session 75f (IDA): named-registry INSERT callers.
// sub_82185468 is the hash-table insert into 0x82839E2C. Mapped caller.
PPC_FUNC_IMPL(__imp__sub_821FB1C8);
static std::atomic<uint32_t> s_h1FB1C8{0};
PPC_FUNC(sub_821FB1C8) {
  const uint32_t n = s_h1FB1C8.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("TEXINSERT-CALLER sub_821FB1C8 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821FB1C8(ctx, base);
}

// Session 75g: parent of the globaltex.list preload (82185A40 is a label
// inside this large function). If this never runs, named textures never
// get INSERTED into 0x82839E2C.
PPC_FUNC_IMPL(__imp__sub_82185648);
static std::atomic<uint32_t> s_h185648{0};
PPC_FUNC(sub_82185648) {
  const uint32_t n = s_h185648.fetch_add(1) + 1;
  if (n <= 8) {
    MCLA_LOG_INFO("TEXLOAD-census sub_82185648 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_82185648(ctx, base);
}

// Session 75h: XMemDecompress (RPF3 LZX) â€” the real unsquish for archive
// entries. Doc: docs/MCLA_RPF3_Technical_Reference.txt Â§8.
// 8244FF20 = XMemDecompress dispatcher (codec must be 1/LZX).
// 82460420 = maps inner result to HRESULT.
PPC_FUNC_IMPL(__imp__sub_8244FF20);
static std::atomic<uint32_t> s_h44FF20{0};
PPC_FUNC(sub_8244FF20) {
  const uint32_t n = s_h44FF20.fetch_add(1) + 1;
  const uint32_t ctxp = ctx.r3.u32;
  const uint32_t dest = ctx.r4.u32;
  const uint32_t destSz = ctx.r5.u32;
  const uint32_t src = ctx.r6.u32;
  const uint32_t srcSz = ctx.r7.u32;
  // T41.3n2 S2: lr must be captured BEFORE the call (F-091 trap #1 — the
  // old XMEM line read ctx.lr after return, so its lr= was callee residue),
  // and every call must reach the log: the old n<=16|n%100 cap meant calls
  // 17..99 were invisible, which is how "all XMEM are the 7 MB job" was
  // partly an instrument artifact. Dedup by (src>>16, srcSz), max 64 keys.
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  // F-253 INSTRUMENT FIX: XMemDecompress takes size POINTERS (uint32* destSize,
  // uint32* srcSize), so ctx.r5/ctx.r7 hold ADDRESSES (e.g. stack 0x6D9004), NOT
  // the sizes. The old "destSz=7179940" was printing a pointer value and led the
  // whole 7-MB-contamination theory astray (F-091/F-231 field trap). Read the
  // pointed-to values so the real in/out sizes are visible.
  auto &xmemMem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t realDestSz = 0, realSrcSz = 0;
  if (destSz)
    (void)xmemMem.ReadU32BE(destSz, &realDestSz);
  if (srcSz)
    (void)xmemMem.ReadU32BE(srcSz, &realSrcSz);
  // F-346: the bytes at the source. w334 calls #1..#4 read from a guest-heap
  // buffer and produced 327,680 bytes; call #5 onward read from our bounce
  // buffer and produced 0. Both windows are 32,748/32,768 bytes long, so size
  // alone cannot tell them apart — only the head words can. Log-only, 12 lines.
  if (n <= 12 && src != 0u && realSrcSz >= 16u && xmemMem.IsValid(src, 16u)) {
    uint32_t sh[4] = {0};
    for (int i = 0; i < 4; ++i)
      (void)xmemMem.ReadU32BE(src + i * 4u, &sh[i]);
    MCLA_LOG_WARN("XMEM-SRCHEAD #{} src={:08X} srcSz={} head=[{:08X} {:08X} "
                  "{:08X} {:08X}]",
                  n, src, realSrcSz, sh[0], sh[1], sh[2], sh[3]);
  }
  // F-331 CENSUS (log-only, zero behaviour change): the frame driver's OWN
  // context, which no instrument of ours has ever read. The chain is
  // sub_821BC140 -> sub_821D5E10 (ppc_recomp.18.cpp:10832) -> sub_8244FF20
  // (:10933, with r3 = *obj, i.e. THIS ctxp) -> sub_82460420 -> sub_82461010
  // (ppc_recomp.82.cpp:14065), and sub_82461010 keeps its walk state at
  // ctx+20, so its r31+N fields are ctxp+(20+N): staging base +12284, staging
  // read position +12288, UNDRAINED staging bytes +12292, frame cursor +12296,
  // frame-header bytes consumed +12300, src-size latch byte +12304.
  // sub_82461530 (:14885) writes the last frame's src +11032, src end +11036,
  // decode dest +11040, cumulative produced +11044 and its own frame counter
  // at +11992. Pre/post because the counters are per-ctx, not per-call.
  auto peekW = [&xmemMem](uint32_t a) {
    uint32_t v = 0;
    if (a != 0u && xmemMem.IsValid(a, 4))
      (void)xmemMem.ReadU32BE(a, &v);
    return v;
  };
  struct CtxSnap {
    uint32_t codec, frames, produced, leftover, cursor, hdrpos, latch, stagbase,
        stagpos, lastsrc, lastdst;
  };
  auto snapCtx = [&peekW, ctxp]() {
    return CtxSnap{peekW(ctxp + 4u),      peekW(ctxp + 11992u),
                   peekW(ctxp + 11044u),  peekW(ctxp + 12292u),
                   peekW(ctxp + 12296u),  peekW(ctxp + 12300u),
                   peekW(ctxp + 12304u),  peekW(ctxp + 12284u),
                   peekW(ctxp + 12288u),  peekW(ctxp + 11032u),
                   peekW(ctxp + 11040u)};
  };
  const CtxSnap pre = snapCtx();
  __imp__sub_8244FF20(ctx, base);
  const uint32_t ret = ctx.r3.u32;
  uint32_t outDestSz = 0, outSrcSz = 0;
  if (destSz)
    (void)xmemMem.ReadU32BE(destSz, &outDestSz);
  if (srcSz)
    (void)xmemMem.ReadU32BE(srcSz, &outSrcSz);
  // F-253: always log the UI container dests. F-321 INSTRUMENT FIX: this used a
  // four-address snapshot (`B7B01000/B7AC1000/B7441000/B74E1000`) taken from some
  // earlier boot, so it printed for stale dests and stayed SILENT for the live
  // ones — which is how F-320 could not say whether the garage's successor slots
  // hold real container bytes. Keyed on the dynamic dest->package map instead
  // (directive #5); log-only, no behaviour change.
  const uint32_t destPkg = PeekPackageForDest(dest);
  const bool uiDest = IsUiXsfPkg(destPkg) || dest == 0xB7B01000u ||
                      dest == 0xB7AC1000u || dest == 0xB7441000u ||
                      dest == 0xB74E1000u;
  // F-327 INSTRUMENT BUG I introduced in F-321: making `uiDest` dynamic was
  // right (the hardcoded four-address snapshot was blind to live dests), but
  // this hook fires ~200 times per inflate entry, so "print for every UI dest"
  // turned w298 into 5,531,016 XMEM-SZPTR lines out of 5.7 M total and the boot
  // never reached the measurement I built it for. Bound it per dest instead of
  // per call: the census wants a sample per dest, not every step.
  static std::mutex s_uiCntMtx;
  static std::unordered_map<uint32_t, uint32_t> s_uiCnt;
  bool uiLogged = false;
  {
    std::lock_guard<std::mutex> clk(s_uiCntMtx);
    uiLogged = uiDest && s_uiCnt[dest]++ < 8u;
  }
  if (n <= 24 || uiLogged)
    MCLA_LOG_WARN("XMEM-SZPTR #{} dest={:08X} *destSz(in)={} *srcSz(in)={} "
                  "src={:08X} *destSz(out)={} *srcSz(out)={} ret={:08X} "
                  "lr={:08X}",
                  n, dest, realDestSz, realSrcSz, src, outDestSz, outSrcSz, ret,
                  lr);
  // F-331: same gate as the line above (per-dest bound, so this cannot repeat
  // w298's 5.5 M-line flooding), one line per call pair showing the frame
  // driver's own progress. `frames`/`ctxprod` are cumulative over the ctx's
  // life, so a call that decoded nothing leaves them flat; `leftover>0` marks
  // the staging-deferral path (ppc_recomp.82.cpp:14436-14444).
  if (n <= 24 || uiLogged) {
    const CtxSnap post = snapCtx();
    // F-331 §9: ctx+12296 and ctx+12300 do NOT behave as the disasm implies
    // (the first is constant, the second exceeds the 0..5 bound the only two
    // writers allow), so they are printed as raw words, not as cursor/hdr.
    MCLA_LOG_WARN(
        "XMEM-CTX #{} ctx={:08X} codec={} dest={:08X} pkg={:08X} "
        "frames {}->{} ctxprod {}->{} leftover {}->{} w12296={:08X} "
        "w12300 {}->{} latch {}->{} stagbase={:08X} stagpos={}->{} "
        "lastsrc={:08X} lastdst={:08X}",
        n, ctxp, post.codec, dest, destPkg, pre.frames, post.frames,
        pre.produced, post.produced, pre.leftover, post.leftover, post.cursor,
        pre.hdrpos, post.hdrpos, pre.latch, post.latch, post.stagbase,
        pre.stagpos, post.stagpos, post.lastsrc, post.lastdst);
  }
  // F-256: dump the decompressed UI-container head once to verify a REAL .xsf
  // (vs capacity-truncated / garbage). A valid Rage/GFx container head tells us
  // whether sub-goal A (decompression) is actually complete, not just flowing.
  if (uiDest && ret == 0) {
    static std::unordered_set<uint32_t> s_dumpedUi;
    if (s_dumpedUi.size() < 8 && s_dumpedUi.insert(dest).second) {
      uint32_t w[8] = {0};
      for (int i = 0; i < 8; ++i)
        if (xmemMem.IsValid(dest + i * 4, 4))
          (void)xmemMem.ReadU32BE(dest + i * 4, &w[i]);
      // F-266: measure how much real (non-poison) data the decompress wrote by
      // scanning for the first 0xCDCDCDCD run — settles whether the UI .xsf fully
      // decompressed vs the ambiguous destSz(out)==capacity reading.
      // F-321: `valid` alone is a trap of the F-302/F-308 kind — a container head
      // is legitimately followed by zero words (w277: XMEM-UIHEAD validbytes=20 on
      // a dest whose stream demonstrably advanced), so a small `valid` is NOT
      // evidence of an empty slot. Report coverage over the first 4 KiB too:
      // `nzwords` counts every word that is neither poison nor zero, `runs` the
      // number of separate non-poison regions. nzwords≈1024 ⇒ full; nzwords≈0 ⇒
      // untouched; a real decompressed body sits in between.
      uint32_t valid = 0;
      for (uint32_t off = 0; off + 4 <= 0x200000u; off += 4) {
        uint32_t word = 0;
        if (!xmemMem.IsValid(dest + off, 4) ||
            !xmemMem.ReadU32BE(dest + off, &word))
          break;
        if (word == 0xCDCDCDCDu || word == 0u)
          break;
        valid = off + 4;
      }
      uint32_t nzwords = 0, runs = 0;
      bool inRun = false;
      for (uint32_t off = 0; off + 4 <= 0x1000u; off += 4) {
        uint32_t word = 0;
        if (!xmemMem.IsValid(dest + off, 4) ||
            !xmemMem.ReadU32BE(dest + off, &word))
          break;
        const bool nz = word != 0xCDCDCDCDu && word != 0u;
        if (nz) {
          ++nzwords;
          if (!inRun) {
            ++runs;
            inRun = true;
          }
        } else {
          inRun = false;
        }
      }
      MCLA_LOG_WARN("XMEM-UIHEAD #{} dest={:08X} pkg={:08X} validbytes={} "
                    "nzwords={} runs={} words=[{:08X} "
                    "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                    n, dest, destPkg, valid, nzwords, runs, w[0], w[1], w[2],
                    w[3], w[4], w[5], w[6],
                    w[7]);
    }
  }
  {
    static std::mutex s_t413n2Mtx;
    static std::unordered_set<uint64_t> s_seen;
    const uint64_t key =
        (static_cast<uint64_t>(src >> 16) << 32) | srcSz;
    std::lock_guard<std::mutex> lk(s_t413n2Mtx);
    if (s_seen.size() < 64 && s_seen.insert(key).second)
      MCLA_LOG_WARN("T413N2-XMEM #{} src={:08X} srcSz={} dest={:08X} "
                    "destSz={} ret={:08X} lr={:08X}",
                    n, src, srcSz, dest, destSz, ret, lr);
  }
  if (n <= 16 || (n % 100) == 0) {
    MCLA_LOG_INFO("XMEM #{} ctx={:08X} dest={:08X} destSz={} src={:08X} "
                  "srcSz={} ret={:08X} lr={:08X}",
                  n, ctxp, dest, destSz, src, srcSz, ret,
                  static_cast<uint32_t>(ctx.lr));
  }
  if (n <= 6 && ret == 0 && dest != 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t head = 0;
    if (mem.IsValid(dest, 4))
      (void)mem.ReadU32BE(dest, &head);
    MCLA_LOG_INFO("XMEM-OUT #{} dest={:08X} head={:08X}", n, dest, head);
  }
}

// Session 75l: streamables loader itself (now a recompiled entry after
// TOML explicit function 0x82216B98 size 0x2B4).
PPC_FUNC_IMPL(__imp__sub_82216B98);
static std::atomic<uint32_t> s_h216B98{0};
PPC_FUNC(sub_82216B98) {
  const uint32_t n = s_h216B98.fetch_add(1) + 1;
  MCLA_LOG_INFO("STREAMTEX-LOADER sub_82216B98 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82216B98(ctx, base);
}

// Session 75i: UI streamables / blank-texture loader caller.
// 82216B98 refs "$/resources/ui/textures/streamables" and "$/textures/blank".
// Not in func map; mapped callers: 821FD6B0, 821FD640, 822012E8.
PPC_FUNC_IMPL(__imp__sub_821FD6B0);
static std::atomic<uint32_t> s_h1FD6B0{0};
PPC_FUNC(sub_821FD6B0) {
  const uint32_t n = s_h1FD6B0.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("STREAMTEX-census sub_821FD6B0 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821FD6B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821FD640);
static std::atomic<uint32_t> s_h1FD640{0};
PPC_FUNC(sub_821FD640) {
  const uint32_t n = s_h1FD640.fetch_add(1) + 1;
  if (n <= 8) {
    MCLA_LOG_INFO("STREAMTEX-PARENT sub_821FD640 #{} lr={:08X}",
                  n, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821FD640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822012E8);
static std::atomic<uint32_t> s_h2012E8{0};
PPC_FUNC(sub_822012E8) {
  const uint32_t n = s_h2012E8.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("UILOAD-census sub_822012E8 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_822012E8(ctx, base);
}

// Session 75j: the empty-dict factory itself (mapped). Requesters 8218D120/
// 8218CB10 never run â€” this is reached via indirect/vtable from unmapped code.
PPC_FUNC_IMPL(__imp__sub_8218BF20);
static std::atomic<uint32_t> s_h18BF20{0};
PPC_FUNC(sub_8218BF20) {
  const uint32_t n = s_h18BF20.fetch_add(1) + 1;
  if (n <= 48 || (n % 100) == 0) {
    // r4 is the deserialization stream the dict is built from:
    // +8 buffer ptr, +24 read cursor, +28 end. Entry format proven in 75l:
    // u8 nameLen + name + u32 hash. Dump the pending name at the cursor.
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t buf = 0, pos = 0, end = 0;
    mem.ReadU32BE(ctx.r4.u32 + 8, &buf);
    mem.ReadU32BE(ctx.r4.u32 + 24, &pos);
    mem.ReadU32BE(ctx.r4.u32 + 28, &end);
    char name[80] = {0};
    uint8_t len = 0;
    if (end > pos && buf != 0) {
      const uint8_t *p =
          static_cast<const uint8_t *>(mcla::kernel::MmGetHostAddress(buf + pos));
      if (p) {
        len = p[0];
        if (len > 0 && len < 70) {
          for (uint32_t i = 0; i < len; ++i)
            name[i] = (p[1 + i] >= 32 && p[1 + i] < 127) ? static_cast<char>(p[1 + i]) : '.';
        }
      }
    }
    MCLA_LOG_INFO("DICTFACT-census sub_8218BF20 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X} stream buf={:08X} pos={:08X} end={:08X} "
                  "left={} name[{}]='{}'",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr), buf, pos, end,
                  end > pos ? end - pos : 0, len, name);
  }
  __imp__sub_8218BF20(ctx, base);
}

// Session 75l: stream slot allocator (fixed 40-byte slot array @0x82860C18,
// per-slot 4KB buffers @0x82860DF8+i*0x1000). Args r4/r5 identify the data
// source feeding the dict deserialization streams.
PPC_FUNC_IMPL(__imp__sub_821BDDE8);
static std::atomic<uint32_t> s_h1BDDE8{0};
PPC_FUNC(sub_821BDDE8) {
  const uint32_t n = s_h1BDDE8.fetch_add(1) + 1;
  if (n <= 32 || (n % 100) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    char a[48] = {0}, b[48] = {0};
    auto dumpstr = [&](uint32_t addr, char *out, size_t cap) {
      if (addr < 0x82000000 || addr > 0x82AD3000) {
        snprintf(out, cap, "%08X", addr);
        return;
      }
      const char *p =
          static_cast<const char *>(mcla::kernel::MmGetHostAddress(addr));
      if (!p) {
        snprintf(out, cap, "%08X?", addr);
        return;
      }
      size_t i = 0;
      for (; i < 40 && p[i]; ++i)
        out[i] = (static_cast<unsigned char>(p[i]) >= 32 &&
                  static_cast<unsigned char>(p[i]) < 127)
                     ? p[i]
                     : '.';
      out[i] = 0;
    };
    dumpstr(ctx.r4.u32, a, sizeof(a));
    dumpstr(ctx.r5.u32, b, sizeof(b));
    MCLA_LOG_INFO("DICTSLOT-ALLOC sub_821BDDE8 #{} r4='{}' r5='{}' lr={:08X}",
                  n, a, b, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821BDDE8(ctx, base);
}

// Session 75j: insert linker called from texture ctor 82185648.
PPC_FUNC_IMPL(__imp__sub_821854C8);
static std::atomic<uint32_t> s_h1854C8{0};
PPC_FUNC(sub_821854C8) {
  const uint32_t n = s_h1854C8.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("TEXINSERT2-census sub_821854C8 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821854C8(ctx, base);
}

// Session 75j: requesters into the empty-dict factory (8218BEB0â†’8218BF20).
PPC_FUNC_IMPL(__imp__sub_8218D120);
static std::atomic<uint32_t> s_h18D120{0};
PPC_FUNC(sub_8218D120) {
  const uint32_t n = s_h18D120.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("DICTREQ-census sub_8218D120 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8218D120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218CB10);
static std::atomic<uint32_t> s_h18CB10{0};
PPC_FUNC(sub_8218CB10) {
  const uint32_t n = s_h18CB10.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("DICTREQ2-census sub_8218CB10 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8218CB10(ctx, base);
}

// ---------------------------------------------------------------------------
// P4' CAPTURE: PresentKick frame boundary. sub_824294E0 = raw kick
// (r3=dev, r4=fbAddr); sub_82429570 = vsync-aware flip picker (backbuffer
// idx dev[+0x5498], count [+0x5494], base [+0x548c]). Both emit PM4 flip +
// 0xDEADBEEF fence consumed by ISR 0x82411478.
//
// R1 (2026-09-10): THIS is the native present owner. Guest frame-end
// (sub_82419E90 -> sub_82419E98) calls PresentKick and VdSwap from the same
// path (ppc_recomp.79.cpp:12387/12532). Native mode presents here; VdSwap
// is inert (see native_renderer.cpp Hooked_VdSwap).
// ---------------------------------------------------------------------------
static std::atomic<uint32_t> s_presentKickCount{0};
static std::atomic<uint32_t> s_lastFbAddr{0};

namespace mcla::gpu {
// Global frame counter for draw-flip correlation. Defined early so the
// present-kick hook (sub_824294E0, below) can advance it; the draw hook
// (sub_82413660) and mcla_gpu_GetFrameCounter() read it.
static std::atomic<uint32_t> g_frameCounter{0};
} // namespace mcla::gpu

// ---------------------------------------------------------------------------
// W7 SURFACE RESOLVER
//
// PresentKick r4 is the swap-table SLOT address (C71D81xx family), not pixels.
// The flip picker fields (dev+0x548c/0x5494/0x5498) are zero in this boot, so
// the picker never computes a surface VA. We track multiple candidates and
// score them by sampling pixel variety, then expose the best via
// ResolvedPresentSurfaceVA() for the render_thread PRESENT path.
//
// Candidate sources (in priority order when scoring ties):
//   1. Flip picker: bbBase + slot*4 (when count/base non-zero)
//   2. VdSwap swap_info (physical-ish, seen as 0x004E0D30)
//   3. Last BLIT-CAP dst that is large enough to be a framebuffer
//   4. Device backbuffer pointer scan (dev+offsets around the picker fields)
// ---------------------------------------------------------------------------
namespace {
struct SurfaceCandidate {
  uint32_t va = 0;
  uint32_t score = 0;   // pixel-variety score (higher = more varied)
  const char* src = "";
  uint32_t w = 0, h = 0;
};
constexpr size_t kMaxCandidates = 8;
SurfaceCandidate g_candidates[kMaxCandidates];
std::mutex g_candMutex;
std::atomic<uint32_t> g_resolvedSurfaceVA{0};

// Sample a guest VA as linear 32bpp and score pixel variety.
// Returns 0 if unreadable or all-zero; higher scores mean more color variety.
uint32_t ScoreSurfacePixels(uint32_t va, uint32_t w, uint32_t h) {
  if (va == 0 || w == 0 || h == 0) return 0;
  auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Sample a 16x16 grid of pixels (stride through the buffer).
  uint32_t distinct = 0;
  uint32_t nonzero = 0;
  uint32_t lastRGB = 0xFFFFFFFF;
  constexpr uint32_t kGrid = 16;
  uint8_t pix[4];
  for (uint32_t gy = 0; gy < kGrid; ++gy) {
    for (uint32_t gx = 0; gx < kGrid; ++gx) {
      const uint32_t sx = (gx * w) / kGrid;
      const uint32_t sy = (gy * h) / kGrid;
      const uint32_t off = (sy * w + sx) * 4;
      if (!mem.ReadBytes(va + off, pix, 4)) return 0;
      const uint32_t rgb = (uint32_t(pix[0]) << 16) | (uint32_t(pix[1]) << 8) | pix[2];
      if (rgb != 0) ++nonzero;
      if (rgb != lastRGB) { ++distinct; lastRGB = rgb; }
    }
  }
  if (nonzero == 0) return 0;
  // Score = distinct colors * nonzero fraction, clamped to 1..1000.
  uint32_t score = distinct * nonzero / (kGrid * kGrid);
  if (score == 0) score = 1;
  if (score > 1000) score = 1000;
  return score;
}

void AddSurfaceCandidate(uint32_t va, uint32_t w, uint32_t h, const char* src) {
  if (va == 0) return;
  std::lock_guard<std::mutex> lock(g_candMutex);
  // Update existing entry for this VA.
  for (auto& c : g_candidates) {
    if (c.va == va) {
      c.score = ScoreSurfacePixels(va, w, h);
      c.w = w; c.h = h; c.src = src;
      return;
    }
  }
  // Find empty slot or replace lowest score.
  SurfaceCandidate* slot = &g_candidates[0];
  for (auto& c : g_candidates) {
    if (c.va == 0) { slot = &c; break; }
    if (c.score < slot->score) slot = &c;
  }
  slot->va = va;
  slot->w = w; slot->h = h; slot->src = src;
  slot->score = ScoreSurfacePixels(va, w, h);
}

// Re-score all candidates and publish the best.
void RefreshResolvedSurface() {
  std::lock_guard<std::mutex> lock(g_candMutex);
  uint32_t bestVA = 0, bestScore = 0;
  for (auto& c : g_candidates) {
    if (c.va == 0) continue;
    c.score = ScoreSurfacePixels(c.va, c.w ? c.w : 1280, c.h ? c.h : 720);
    if (c.score > bestScore) { bestScore = c.score; bestVA = c.va; }
  }
  if (bestVA != 0 && bestVA != g_resolvedSurfaceVA.load()) {
    g_resolvedSurfaceVA.store(bestVA);
    MCLA_LOG_WARN("PRESENT-SURF resolved va={:08X} score={} (was {})",
                  bestVA, bestScore, g_resolvedSurfaceVA.load());
  }
}
} // anonymous namespace

uint32_t mcla::gpu::ResolvedPresentSurfaceVA() {
  return g_resolvedSurfaceVA.load(std::memory_order_relaxed);
}

// C-linkage wrapper so native_renderer.cpp can add VdSwap candidates
// without including the anonymous-namespace helpers directly.
extern "C" void mcla_gpu_AddSurfaceCandidate(uint32_t va, uint32_t w,
                                              uint32_t h, const char* src) {
  AddSurfaceCandidate(va, w, h, src);
  RefreshResolvedSurface();
}

PPC_FUNC_IMPL(__imp__sub_824294E0);
PPC_FUNC(sub_824294E0) {
  const uint32_t n = s_presentKickCount.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t fbAddr = ctx.r4.u32;
  s_lastFbAddr.store(fbAddr, std::memory_order_relaxed);
  const uint32_t frame =
      mcla::gpu::g_frameCounter.fetch_add(1, std::memory_order_relaxed) + 1;

  // W7: dump device backbuffer fields + resolve surface VA.
  uint32_t bbBase = 0, bbCount = 0, bbIdx = 0;
  uint32_t resolvedSurf = 0;
  {
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    if (dev != 0 && mem.IsValid(dev + 0x5498, 4)) {
      (void)mem.ReadU32BE(dev + 0x548c, &bbBase);
      (void)mem.ReadU32BE(dev + 0x5494, &bbCount);
      (void)mem.ReadU32BE(dev + 0x5498, &bbIdx);
    }
    uint32_t f5480 = 0, f5484 = 0, f5488 = 0, f5490 = 0, f549c = 0, f54a0 = 0;
    if (dev != 0) {
      (void)mem.ReadU32BE(dev + 0x5480, &f5480);
      (void)mem.ReadU32BE(dev + 0x5484, &f5484);
      (void)mem.ReadU32BE(dev + 0x5488, &f5488);
      (void)mem.ReadU32BE(dev + 0x5490, &f5490);
      (void)mem.ReadU32BE(dev + 0x549c, &f549c);
      (void)mem.ReadU32BE(dev + 0x54a0, &f54a0);
    }
    if (bbBase != 0 && bbCount != 0) {
      const uint32_t pickIdx = (bbIdx >= 3) ? 0 : (bbIdx + 1);
      if (pickIdx < bbCount) {
        resolvedSurf = bbBase + pickIdx * 2 * 4;
        AddSurfaceCandidate(resolvedSurf, 1280, 720, "picker");
      }
    }
    const uint32_t scanFields[] = {f5480, f5484, f5488, f5490, f549c, f54a0};
    for (uint32_t fv : scanFields) {
      if (fv >= 0xC0000000u && fv < 0xF0000000u) {
        AddSurfaceCandidate(fv, 1280, 720, "devfield");
      }
    }
    if (n <= 16 || (n % 500) == 0) {
      MCLA_LOG_WARN("PRESENT-KICK-CENSUS #{} dev={:08X} fb={:08X} "
                    "bbBase={:08X} bbCount={} bbIdx={} "
                    "dev+5480={:08X}/5484={:08X}/5488={:08X}/5490={:08X}"
                    "/549c={:08X}/54a0={:08X} resolvedSurf={:08X}",
                    n, dev, fbAddr, bbBase, bbCount, bbIdx,
                    f5480, f5484, f5488, f5490, f549c, f54a0, resolvedSurf);
    }
  }
  RefreshResolvedSurface();

  if (n <= 8 || (n % 500) == 0)
    MCLA_LOG_INFO("P4'-PRESENT kick #{} dev={:08X} fb={:08X} surf={:08X}",
                  n, dev, fbAddr, mcla::gpu::ResolvedPresentSurfaceVA());

  __imp__sub_824294E0(ctx, base);

  // SESSION 73: HW side of the swap-table handshake. The guest reserves two
  // slots per kick by writing ZERO into dev[10896] table at ((queued&7)+16)
  // and ((queued+1&7)+16) (ppc_recomp.79.cpp: r24=0 before both stwx). On HW
  // the display engine later fills the slots with flip timestamps; the
  // completion processor (sub_824286A0) advances dev[+21624] only when the
  // slot at (completed+1&7)+16 is non-zero (lwbrx = little-endian). Without
  // those writes the queue drains never and the >=6 gate at loc_82419FD8
  // stops all kicks after 6 presents. Write a monotonic 64-bit timebase
  // value into both reserved slots, little-endian, like HW.
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t tableBase = 0, queued = 0;
    if (dev != 0 && mem.ReadU32BE(dev + 10896, &tableBase) &&
        tableBase != 0 && mem.ReadU32BE(dev + 21628, &queued)) {
      const uint32_t ts = static_cast<uint32_t>(
          mcla::native::QueryGuestTimebase() & 0xFFFFFFFFu) | 1u;
      // The table is 4-BYTE slots (idx 16..23). Write exactly one slot per
      // entry â€” an 8-byte write here spilled into subctx+96 whenever
      // (queued&7)+16 == 23. lwbrx interprets the bytes little-endian.
      for (uint32_t k = 0; k < 2; ++k) {
        const uint32_t off = (((queued + k) & 7u) + 16u) * 4u;
        (void)mem.WriteU32BE(tableBase + off, __builtin_bswap32(ts));
      }
      if (n <= 8 || (n % 500) == 0)
        MCLA_LOG_WARN("SWAP-FILL #{} table={:08X} queued={} ts={:08X}", n,
                      tableBase, queued, ts);
    }
  }

  mcla::native::GetDrawAccumulator()->OnFrameEnd();
  mcla::native::EnqueueNativePresent(frame, dev, fbAddr);
  mcla::renderer::RecordFramePresented();
}

// R1 census: high-level frame-end entry. sub_82419E90(r3=dev) forwards to
// sub_824199B0 which runs the flip picker + PresentKick + VdSwap sequence.
// Fires only when the guest actually presents â€” first hit is the present
// milestone (currently absent through pool-OOM-era boots).
PPC_FUNC_IMPL(__imp__sub_82419E90);
static std::atomic<uint32_t> s_h19E90{0};
PPC_FUNC(sub_82419E90) {
  const uint32_t n = s_h19E90.fetch_add(1) + 1;
  if (n <= 8 || (n % 200) == 0)
    MCLA_LOG_INFO("FRAME-END sub_82419E90 #{} dev={:08X} lr={:08X}", n,
                  ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82419E90(ctx, base);
}

// ---------------------------------------------------------------------------
// SESSION 74 census: tiled 2D surface blit (d3d9-style copy-rect, generated
// impl ppc_recomp.80.cpp:37005). PROVEN corruptor path â€” its two memcpy call
// sites (guest lr 0x82431C5C / 0x82431D18) write 0xCDCDCDCD into the physical
// arena at the allocation frontier (PHYS-OVERRUN @ CAEC5004..CAF04004), which
// clobbers o1heap free-fragment headers: header.size / next_free read back as
// 0xCDCDCDCDCDCDCDCD, unbin() dereferences it, SehO1Allocate swallows the AV
// and returns null -> E_OUTOFMEMORY -> TEXCREATE-SC fakes success -> guest
// null-deref fatal. Capture the inputs to find which one is garbage.
// r3=dst base  r4=width  r5=height  r6=src origin{x,y} (0 => {0,0})
// r7=src base  r8=src pitch  r9=dst rect{x0,y0,x1,y1} (0 => {0,0,r4,r5})
// r10=format/tiling descriptor (bpp + log2 tile shifts)
// Census only: no behaviour change, no D3D12 calls.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82431A40);
static std::atomic<uint32_t> s_h31A40{0};
PPC_FUNC(sub_82431A40) {
  const uint32_t n = s_h31A40.fetch_add(1) + 1;
  const uint32_t dst = ctx.r3.u32;
  const uint32_t w = ctx.r4.u32;
  const uint32_t h = ctx.r5.u32;
  const uint32_t srcOrigin = ctx.r6.u32;
  const uint32_t src = ctx.r7.u32;
  const uint32_t pitch = ctx.r8.u32;
  const uint32_t rectPtr = ctx.r9.u32;
  const uint32_t fmt = ctx.r10.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  const bool log = (n <= 1024) || (n % 256) == 0;

  uint32_t x0 = 0, y0 = 0, x1 = w, y1 = h;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (rectPtr != 0) {
    (void)mem.ReadU32BE(rectPtr + 0, &x0);
    (void)mem.ReadU32BE(rectPtr + 4, &y0);
    (void)mem.ReadU32BE(rectPtr + 8, &x1);
    (void)mem.ReadU32BE(rectPtr + 12, &y1);
  }

  // Source descriptor: good mip-chain blits carry a real one; a garbage or
  // uninitialized descriptor is the other candidate root cause.
  uint32_t sd[8] = {};
  if (log && src != 0) {
    for (uint32_t i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(src + i * 4, &sd[i]);
  }

  const bool dstPhys = (dst >= 0xA0000000u);
  uint32_t aBase = 0, aSize = 0, aLr = 0;
  bool exact = false;
  const bool haveAlloc =
      dstPhys &&
      mcla::kernel::MclaPhysAllocInfo(dst, &aBase, &aSize, &aLr, &exact);
  // The copy extent is RECT-driven: rows = y1-y0, per-row = x1-x0, so the
  // blit writes w*h BYTES. The format/bpp (r10) only sizes an internal
  // staging alloc and is never multiplied into the copy size.
  const uint32_t rectW = (x1 > x0) ? (x1 - x0) : 0u;
  const uint32_t rectH = (y1 > y0) ? (y1 - y0) : 0u;
  const uint64_t need = static_cast<uint64_t>(rectW) * rectH;
  const bool overrun = haveAlloc && exact && need > aSize;

  if (log)
    MCLA_LOG_WARN("BLIT-CAP #{} dst={:08X} src={:08X} pitch={:#x} fmt={:08X} "
                  "rect=[{},{},{},{}] wh={}x{} srcOrigin={:08X} lr={:08X} "
                  "alloc={} size={:#x} allocLr={:08X} exact={} need={:#x} "
                  "overrunBy={:#x}",
                  n, dst, src, pitch, fmt, x0, y0, x1, y1, w, h, srcOrigin, lr,
                  haveAlloc ? aBase : 0u, haveAlloc ? aSize : 0u,
                  haveAlloc ? aLr : 0u, exact, need,
                  overrun ? static_cast<uint32_t>(need - aSize) : 0u);
  if (log)
    MCLA_LOG_WARN("BLIT-SRC #{} src={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "[{:08X} {:08X} {:08X} {:08X}]",
                  n, src, sd[0], sd[1], sd[2], sd[3], sd[4], sd[5], sd[6], sd[7]);

  // W7: track large blit destinations as surface candidates.
  // A framebuffer-sized blit (>= 320x240) is a plausible color buffer.
  if (!overrun && dst != 0 && rectW >= 320 && rectH >= 240) {
    AddSurfaceCandidate(dst, rectW, rectH, "blit");
  }

  // SESSION 74 GUARD: refuse a provably out-of-bounds blit. Blit #8 is handed
  // a 512x640 RECT against a 0xA000 destination and writes 0x46000 bytes of
  // copied 0xCD straight over o1heap free-fragment headers at the arena
  // frontier â€” that is the AV storm, the E_OUTOFMEMORY cascade and the fatal
  // null-deref. On hardware the surface dims and the buffer always agree; here
  // the source descriptor is uninitialized (fmtEnum=0, flag=1 direct-copy
  // path), so the two disagree. Skipping only when the allocation match is
  // exact leaves every legitimate blit (all #1-#7 fit) untouched. r3 keeps the
  // dst pointer, matching the flag=1 path which applies no dst-base adjust.
  if (overrun) {
    static std::atomic<uint32_t> s_blitGuards{0};
    const uint32_t g = s_blitGuards.fetch_add(1) + 1;
    if (g <= 64 || (g % 500) == 0)
      MCLA_LOG_ERROR("BLIT-OOB-GUARD #{} SKIPPED dst={:08X} size={:#x} "
                     "need={:#x} overrunBy={:#x} rect=[{},{},{},{}] fmt={:08X} "
                     "src={:08X} lr={:08X} allocLr={:08X}",
                     g, dst, aSize, need, static_cast<uint32_t>(need - aSize),
                     x0, y0, x1, y1, fmt, src, lr, aLr);
    return;
  }

  __imp__sub_82431A40(ctx, base);
}

// ---------------------------------------------------------------------------
// SESSION 74 census: sub_824321E0 â€” the copy-rect wrapper, sole caller of the
// blit sub_82431A40 (call site guest 0x82432428). Capturing ITS parameters is
// what separates "destination under-allocated" from "RECT is garbage":
//   r3=dstW r4=dstH (the true surface dims) r5=log2 tile shift
//   r6=src D3DFORMAT enum (0 = invalid/uninitialized; falls through the
//      decoder sub_8240F2A8 to the 1x1-block default)
//   r7=flag bit (0 => tile-adjust path via sub_82432D30, fills a real origin;
//      1 => direct-copy path, leaves origin = caller r9 = 0)
//   r8=dst base/pitch  r9=origin ptr  r10=src base
// Its only caller is sub_82182FA0 (surface copy/update), which also appears in
// the fatal crash stack under the texture placeholder factory sub_82184F58.
// Census only: no behaviour change.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_824321E0);
static std::atomic<uint32_t> s_h321E0{0};
PPC_FUNC(sub_824321E0) {
  const uint32_t n = s_h321E0.fetch_add(1) + 1;
  const uint32_t dstW = ctx.r3.u32;
  const uint32_t dstH = ctx.r4.u32;
  const uint32_t tileShift = ctx.r5.u32;
  const uint32_t fmtEnum = ctx.r6.u32;
  const uint32_t flag = ctx.r7.u32;
  const uint32_t dstBase = ctx.r8.u32;
  const uint32_t origin = ctx.r9.u32;
  const uint32_t src = ctx.r10.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);

  if (n <= 1024 || (n % 256) == 0) {
    uint32_t aBase = 0, aSize = 0, aLr = 0;
    bool exact = false;
    const bool haveAlloc =
        (dstBase >= 0xA0000000u) &&
        mcla::kernel::MclaPhysAllocInfo(dstBase, &aBase, &aSize, &aLr, &exact);
    // What the surface dims imply vs what was actually allocated.
    const uint64_t need =
        static_cast<uint64_t>(dstW) * static_cast<uint64_t>(dstH);
    MCLA_LOG_WARN("BLITWRAP #{} dstW={} dstH={} tileShift={} fmtEnum={:#x} "
                  "flag={} dstBase={:08X} origin={:08X} src={:08X} lr={:08X} "
                  "alloc={} size={:#x} exact={} need={:#x} overrunBy={:#x}",
                  n, dstW, dstH, tileShift, fmtEnum, flag, dstBase, origin, src,
                  lr, haveAlloc ? aBase : 0u, haveAlloc ? aSize : 0u, exact,
                  need,
                  (haveAlloc && exact && need > aSize)
                      ? static_cast<uint32_t>(need - aSize)
                      : 0u);
  }

  __imp__sub_824321E0(ctx, base);
}

// ---------------------------------------------------------------------------
// SESSION 73 census: swap-completion processor. Advances dev[+21624] when
// the swap table (dev[10896]) holds non-zero entries at the completed index.
// Reads are lwbrx (little-endian) â€” the entries are HW-side bytes. Dump the
// table window around the completed index to see why the advance stalls.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_824286A0);
static std::atomic<uint32_t> s_h86A0{0};
PPC_FUNC(sub_824286A0) {
  const uint32_t n = s_h86A0.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t completed = 0, queued = 0, tableBase = 0;
  if (dev != 0) {
    (void)mem.ReadU32BE(dev + 21624, &completed);
    (void)mem.ReadU32BE(dev + 21628, &queued);
    (void)mem.ReadU32BE(dev + 10896, &tableBase);
  }
  __imp__sub_824286A0(ctx, base);
  if (n <= 24 || (n % 500) == 0) {
    uint32_t after = 0;
    (void)mem.ReadU32BE(dev + 21624, &after);
    MCLA_LOG_WARN(
        "SWAP-COMP #{} dev={:08X} completed={}->{} queued={} table={:08X}",
        n, dev, completed, after, queued, tableBase);
    if (tableBase != 0) {
      // dump the 8 entry slots (idx 16..23 of the table, 4B each)
      for (uint32_t i = 0; i < 8; ++i) {
        uint32_t v = 0;
        (void)mem.ReadU32BE(tableBase + (16 + i) * 4, &v);
        MCLA_LOG_WARN("  SWAP-COMP slot[{}] = {:08X}", i, v);
      }
    }
  }
}

// ---------------------------------------------------------------------------
// SESSION 73: swap-completion status. The guest stops kicking presents once
// dev[+21628] (queued) - dev[+21624] (completed) >= 6 (gate decoded at
// ppc_recomp.79.cpp loc_82419FD8). Completions advance only when the
// per-frame check sub_82428FD8 sees bit26 of sub_82458030() set â€” that fn
// reads [0x820007E8]=0x10059 then *(u32*)0x10059, a low-memory block the
// 360 kernel populates and our emu never writes (always 0 -> return 0 ->
// completions never advance -> presents stop after 6 kicks).
//
// Single caller (sub_82428FD8), no other hook owner. Additive emulation
// point: pass the original through when it yields a status; otherwise
// report bit26 from the device's real queue state so the completion
// processor drains the swap table exactly like HW.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82458030);
static std::atomic<uint32_t> s_h58030{0};
PPC_FUNC(sub_82458030) {
  const uint32_t n = s_h58030.fetch_add(1) + 1;
  __imp__sub_82458030(ctx, base);
  if (ctx.r3.u32 != 0)
    return; // guest resolved its own status object â€” trust it

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0;
  (void)mem.ReadU32BE(0x82839254, &dev);
  if (dev == 0)
    return;
  uint32_t queued = 0, completed = 0;
  (void)mem.ReadU32BE(dev + 21628, &queued);
  (void)mem.ReadU32BE(dev + 21624, &completed);
  const uint32_t gap = queued - completed;
  if (gap != 0) {
    // rlwinm r11,r3,0,26,26 == r3 & 0x20: PPC bit 26 is value bit 5.
    ctx.r3.u32 = 0x20u; // swap pending â€” run the completion processor
    if (n <= 16 || (n % 1000) == 0)
      MCLA_LOG_WARN("SWAP-STATUS #{} dev={:08X} queued={} completed={} gap={} "
                    "-> bit26 (emu status; guest chain [0x820007E8]->0x10059 "
                    "reads 0)",
                    n, dev, queued, completed, gap);
  }
}

namespace mcla::gpu {

// Captured draw data for native renderer (V2 - safe VB/IB capture)
static CapturedDrawV2 g_lastDrawV2{};

uint32_t mcla_gpu_GetFrameCounter() {
  return g_frameCounter.load(std::memory_order_relaxed);
}

const CapturedDrawV2 *mcla_gpu_GetLastDrawV2() {
  std::lock_guard<std::mutex> lock(g_drawMutex);
  return &g_lastDrawV2;
}

std::mutex &mcla_gpu_GetDrawMutex() { return g_drawMutex; }

} // namespace mcla::gpu

PPC_FUNC_IMPL(__imp__sub_82413660);
static std::atomic<uint32_t> s_h13660{0};
PPC_FUNC(sub_82413660) {
  const uint32_t n = s_h13660.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t r4 = ctx.r4.u32;
  const uint32_t r5 = ctx.r5.u32; // VB desc pointer
  const uint32_t r6 = ctx.r6.u32; // IB desc pointer

  // P4' Step 3: Capture draw submit details
  if (n <= 10 || (n % 1000) == 0) {
    MCLA_LOG_INFO(
        "DRAW-SEAM sub_82413660 #{} dev={:08X} r4={:08X} r5={:08X} "
        "r6={:08X} r7={:08X} r8={:08X} r9={:08X} r10={:08X} lr={:08X}",
        n, dev, r4, r5, r6, ctx.r7.u32, ctx.r8.u32, ctx.r9.u32, ctx.r10.u32,
        ctx.lr);
  }

  // Keep this helper as a diagnostic/state capture seam. Geometry ownership
  // belongs to sub_82420BA8, which has the packed index count and draw flags.
  __imp__sub_82413660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82411840);
static std::atomic<uint32_t> s_h11840{0};
PPC_FUNC(sub_82411840) {
  const uint32_t n = s_h11840.fetch_add(1) + 1;
  if (n <= 12 || (n % 5000) == 0)
    MCLA_LOG_INFO("SUBMIT-census sub_82411840 #{} dev={:08X} cls={} a={}", n,
                  ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
  __imp__sub_82411840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241BD08);
static std::atomic<uint32_t> s_h1BD08{0};
PPC_FUNC(sub_8241BD08) {
  const uint32_t n = s_h1BD08.fetch_add(1) + 1;
  // Single owner of the submit seam (S1â€“S3 consolidation): frame counters +
  // submit observers folded in from the removed native_renderer hook.
  mcla::renderer::RecordSubmit();
  mcla::renderer::hooks::DispatchBeforeSubmit(ctx, base);
  const uint32_t dev1BD08 = ctx.r3.u32;
  if (dev1BD08 != 0 && dev1BD08 >= 0x1000u) {
    mcla::native::GetDrawAccumulator()->OnSubmit(
        reinterpret_cast<::MclaGpuContext*>(base + dev1BD08), ctx.r4.u32);
  }
  if (n <= 12 || (n % 1000) == 0)
    MCLA_LOG_INFO("SUBMIT-census sub_8241BD08(flush) #{} dev={:08X} r4={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32);
  __imp__sub_8241BD08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82429570);
static std::atomic<uint32_t> s_h29570{0};
PPC_FUNC(sub_82429570) {
  const uint32_t n = s_h29570.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (dev != 0 && mem.IsValid(dev + 0x5498, 4)) {
    uint32_t bbIdx = 0, bbCount = 0, bbBase = 0;
    (void)mem.ReadU32BE(dev + 0x5498, &bbIdx);
    (void)mem.ReadU32BE(dev + 0x5494, &bbCount);
    (void)mem.ReadU32BE(dev + 0x548c, &bbBase);
    // W7: compute surface VA from picker fields and add as candidate.
    if (bbBase != 0 && bbCount != 0) {
      const uint32_t pickIdx = (bbIdx >= 3) ? 0 : (bbIdx + 1);
      if (pickIdx < bbCount) {
        const uint32_t surfVA = bbBase + pickIdx * 2 * 4;
        AddSurfaceCandidate(surfVA, 1280, 720, "picker");
        if (n <= 12 || (n % 1000) == 0)
          MCLA_LOG_WARN("PRESENT-SURF picker #{} va={:08X} bbBase={:08X} "
                        "idx={} count={}",
                        n, surfVA, bbBase, pickIdx, bbCount);
      }
    }
    if (n <= 12 || (n % 1000) == 0)
      MCLA_LOG_INFO(
          "P4'-PRESENT picker #{} dev={:08X} bb idx={} count={} base={:08X}", n,
          dev, bbIdx, bbCount, bbBase);
  }

  // LOADING-PROGRESS GATE CENSUS (session 65+): after present kick, dump the
  // subctx publication state and fence status to decode what the guest waits
  // on during loading screens (VdSwap ~1/15s, no DRAW_INDEXED).
  if (dev != 0) {
    uint32_t subctx = 0, pub4 = 0, pub8 = 0, pub12 = 0;
    uint32_t put = 0, mask = 0, rptr = 0;
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0) {
      (void)mem.ReadU32BE(subctx + 0, &pub4);   // published rptr
      (void)mem.ReadU32BE(subctx + 4, &pub8);   // kick completion token
      (void)mem.ReadU32BE(subctx + 8, &pub12);  // subctx publication
    }
    (void)mem.ReadU32BE(dev + 10908, &put);
    (void)mem.ReadU32BE(dev + 14900, &mask);
    (void)mem.ReadU32BE(dev + 10912, &rptr);  // CP read pointer
    if (n <= 20 || (n % 500) == 0)
      MCLA_LOG_INFO("LOADING-GATE post-kick #{} dev={:08X} subctx={:08X} "
                    "pub[0..2]={:08X}/{:08X}/{:08X} put={:08X} rptr={:08X} "
                    "mask={:08X} diff={:08X}",
                    n, dev, subctx, pub4, pub8, pub12, put, rptr, mask,
                    (put > pub4) ? (put - pub4) : 0);
  }

  s_presentKickCount.fetch_add(1, std::memory_order_relaxed);
  __imp__sub_82429570(ctx, base);
}

// ---------------------------------------------------------------------------
// RING-WAIT census (2026-08-23): sub_82411928 is the SOLE doorbell-ringer
// module-wide (PPC_MM_STORE_U32(0x7FC80000+1812), 77.cpp:20398). Earlier run:
// 5 reserve passes then silence ï¿½ thread parked between 11218-return and the
// doorbell store. Log predicate inputs + whether the tail is ever reached.
// Units: dword indices, mask=dev[+14900]; published rptr = subctx[+60].
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411218);
static std::atomic<uint32_t> s_h11218{0};
PPC_FUNC(sub_82411218) {
  const uint32_t n = s_h11218.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t target = ctx.r4.u32;
  const uint32_t bytes = ctx.r5.u32;
  if (dev != 0) {
    mcla::gpu::CpAttachDriverCtx(dev);
  }
  uint32_t mask = 0, subctx = 0, published = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 14900, &mask);
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
      (void)mem.ReadU32BE(subctx + 60, &published);
  }
  // Progress-counter visibility: *(r13+256)+88 of THIS thread (sub_82412F98
  // exits when it advances >=5000 past snapshot). Pump preconditions per
  // gate-cracker E3: dev[+13432]!=0 && blocker [0x827CDA3C]==0.
  uint32_t pcBlk = 0, pcVal = 0, pumpObj = 0, blocker = 0;
  if (PPCContext *pctx = GetPPCContext()) {
    const uint32_t tls = pctx->r13.u32;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    if (tls != 0 && mem.ReadU32BE(tls + 256, &pcBlk) && pcBlk != 0)
      (void)mem.ReadU32BE(pcBlk + 88, &pcVal);
    (void)mem.ReadU32BE(dev + 13432, &pumpObj);
    (void)mem.ReadU32BE(0x827CDA3C, &blocker);
  }
  const bool wraps = ((target + bytes) & ~mask) != (target & ~mask);
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("RW #{:04X} tgt={:05X} b={:X} msk={:X} sc={:X} wb={:X} "
                  "pc={}:{} pump={:08X} blk={:08X} wrap={}",
                  n, target, bytes, mask, subctx, published, pcBlk, pcVal,
                  pumpObj, blocker, wraps ? 1 : 0);
  __imp__sub_82411218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82411928);
static std::atomic<uint32_t> s_h11928{0};
static std::atomic<uint32_t> s_h11928done{0};
PPC_FUNC(sub_82411928) {
  const uint32_t n = s_h11928.fetch_add(1) + 1;
  if (n <= 12 || (n % 2000) == 0)
    MCLA_LOG_INFO("DOORBELL sub_82411928 #{} r3={:08X} r4={:08X} r5={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
  __imp__sub_82411928(ctx, base);
  const uint32_t d = s_h11928done.fetch_add(1) + 1;
  if (d <= 12 || (d % 2000) == 0)
    MCLA_LOG_INFO("DOORBELL sub_82411928 RETURNED #{}", d);
}

// ---------------------------------------------------------------------------
// E98 census (2026-08-23 session 9): sub_82411E94 is an EMPTY padding stub;
// the real wait body is sibling sub_82411E98 (77.cpp:21047-21170), decoded:
//   r4=needed, dev=r3; put=dev[+10908]; pub=*(*(dev+10896)+0)
//   early-exit r4==0 | free>=used | special (r7&0xFF)==0 && needed==put &&
//   dev[+13232]==0 -> sub_82412710; else wait loop: init ctx via
//   sub_82412EA0, poll sub_82412F98 (busy r3=1 keeps looping), recheck
//   needed > pub, destroy ctx via sub_82412ED0.
// Persistent stall shape: needed > published at every recheck. Census pins
// WHICH device spins, the exact predicate words, and THIS thread's progress
// counter (F98's gate input) - discriminates wrong-device mirrors vs frozen
// per-thread progress. Also registers every waiting device so mirror
// maintenance covers it.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411E98);
static std::atomic<uint32_t> s_h11E98{0};
static std::atomic<uint32_t> s_h11E98done{0};
PPC_FUNC(sub_82411E98) {
  const uint32_t n = s_h11E98.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t needed = ctx.r4.u32;
  const uint32_t arg5 = ctx.r5.u32;
  const uint32_t flags = ctx.r7.u32 & 0xFF;
  if (dev != 0) {
    mcla::gpu::CpAttachDriverCtx(dev);
  }
  uint32_t put = 0, subctx = 0, pub0 = 0, flag13232 = 0, pcBlk = 0, pcVal = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 10908, &put);
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0) {
      (void)mem.ReadU32BE(subctx + 0, &pub0);
    }
    (void)mem.ReadU32BE(dev + 13232, &flag13232);
    if (PPCContext *pctx = GetPPCContext()) {
      const uint32_t tls = pctx->r13.u32;
      if (tls != 0 && mem.ReadU32BE(tls + 256, &pcBlk) && pcBlk != 0) {
        (void)mem.ReadU32BE(pcBlk + 88, &pcVal);
      }
    }
  }
  // Same expression as the generated compare (u32 wraparound semantics).
  const bool waitsAtEntry = needed != 0 && ((put - needed) < (put - pub0));
  if (n <= 16 || (n % 500) == 0) {
    MCLA_LOG_INFO("E98 #{:04X} dev={:08X} need={:08X} put={:08X} pub={:08X} "
                  "f13232={} flg={} wait={} a5={:08X} pc={}:{}",
                  n, dev, needed, put, pub0, flag13232 != 0, flags,
                  waitsAtEntry ? 1 : 0, arg5, pcBlk, pcVal);
  }

  // KDELAY-SC (session 70c): Short-circuit the GPU progress polling loop on the
  // main thread.  When the CP is frozen the consumed-count (pub0 at subctx+0)
  // can never advance to match `needed`, so the generated wait-loop in this
  // function spins forever (polling KeDelayExecutionThread(10ms) which
  // returns STATUS_USER_APC immediately, creating a tight CPU-burning loop).
  //
  // The GPU work was already processed synchronously by the CP doorbell handler
  // before the fence was created (proven in session 69).  pub0 is a formality
  // the frozen CP cannot satisfy.  Forcing it is the honest short-circuit:
  // the work IS done, the counter just can't reflect it.
  //
  // Scoped to main thread only (g_mainGuestThreadId) to prevent side effects
  // on worker threads.  The write uses checked guest memory access and will be
  // harmless once the CP is deleted at P6'.
  if (waitsAtEntry && subctx != 0) {
    const uint32_t mainId = g_mainGuestThreadId.load();
    if (mainId != 0 && GetCurrentThreadId() == mainId) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      MCLA_LOG_INFO("KDELAY-SC #{} E98 stall: tid={:08X} need={:08X} pub={:08X} "
                    "put={:08X} -> forcing pub0={:08X}",
                    n, mainId, needed, pub0, put, needed);
      (void)mem.WriteU32BE(subctx + 0, needed);
      // Also advance the per-thread progress counter (pcBlk+88) so that
      // sub_82412F98's >=5000 delta check is satisfied.
      if (pcBlk != 0) {
        (void)mem.WriteU32BE(pcBlk + 88, pcVal + 6000);
      }
      ctx.r3.u32 = 0;  // STATUS_SUCCESS â€” wait completed
      return;
    }
  }

  __imp__sub_82411E98(ctx, base);
  const uint32_t d = s_h11E98done.fetch_add(1) + 1;
  if (d <= 16 || (d % 500) == 0)
    MCLA_LOG_INFO("E98 RETURNED #{}", d);
}

// ---------------------------------------------------------------------------
// FLIP-PROCESSOR census: sub_82419718 runs from the vsync ISR type-0 branch
// once gate [0x7FC86544]&1 is set (77.cpp:19534-19547). Per session-5 RE:
// drains flip-request entries at dev[+16572+i*8], MMIO store 0x7FCE6110 per
// entry, callback dev[+16544]. Census proves the gate path executes and dumps
// queue head + present-callback slot.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82419718);
static std::atomic<uint32_t> s_h19718{0};
PPC_FUNC(sub_82419718) {
  const uint32_t n = s_h19718.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  uint32_t cb = 0, q0 = 0, q1 = 0, q2 = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 16544, &cb);
    (void)mem.ReadU32BE(dev + 16572, &q0);
    (void)mem.ReadU32BE(dev + 16580, &q1);
    (void)mem.ReadU32BE(dev + 16588, &q2);
  }
  if (n <= 12 || (n % 2000) == 0)
    MCLA_LOG_INFO("FLIP sub_82419718 #{} dev={:08X} cb={:08X} "
                  "q[0..2]={:08X}/{:08X}/{:08X}",
                  n, dev, cb, q0, q1, q2);
  // NOTE: Frame counter is NOT incremented here; it is only advanced in
  // sub_824294E0 (the PresentKick) to avoid double-counting.
  __imp__sub_82419718(ctx, base);
}

// ---------------------------------------------------------------------------
// SLEEP-HELPER census (2026-09-10 KDELAY stall): sub_82460270(ms=r3,
// alertable=r4) is the ONLY body that contains the lr=0x824602C4 site.
// sub_8244FEC0(ms) is a tail-call with r4=0 (single Sleep). Main thread
// parks forever at 10ms â€” outer poll loop re-enters this helper. Log
// (ms, alertable, caller LR) so the outer loop is named.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82460270);
static std::atomic<uint32_t> s_h60270{0};
PPC_FUNC(sub_82460270) {
  const uint32_t n = s_h60270.fetch_add(1) + 1;
  const uint32_t ms = ctx.r3.u32;
  const uint32_t alertable = ctx.r4.u32 & 0xFF;
  const uint32_t callerLr = static_cast<uint32_t>(ctx.lr);
  if (n <= 40 || (n % 200) == 0)
    MCLA_LOG_INFO("SLEEP60270 #{} ms={} al={} callerLR={:08X}", n, ms,
                  alertable, callerLr);
  __imp__sub_82460270(ctx, base);
}

// ---------------------------------------------------------------------------
// WAIT-HELPER census: sub_82135DC0(handle=r3, timeoutMs=r4, alertable=r5)
// wraps NtWaitForSingleObjectEx in a retry-on-timeout loop
// (ppc_recomp.0.cpp:18590-18654). PARK-SAMPLE caught the main thread parked
// inside it on handle C9ADB800 with ~unit timeout - this pins handle,
// timeout, alertability, and result distribution (257=STATUS_TIMEOUT spin).
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82135DC0);
static std::atomic<uint32_t> s_h135DC0{0};
static std::atomic<uint32_t> s_h135DC0done{0};
PPC_FUNC(sub_82135DC0) {
  const uint32_t n = s_h135DC0.fetch_add(1) + 1;
  const uint32_t handle = ctx.r3.u32;
  const uint32_t timeoutArg = ctx.r4.u32;
  const uint32_t alertable = ctx.r5.u32 & 0xFF;
  // Finite timeouts are the poll patterns (frame pacing etc.) - always
  // surface those up to a cap; infinite worker parks stay throttled.
  const bool finite = timeoutArg != 0xFFFFFFFFu;
  if ((finite && n <= 400) || n <= 12 || (n % 1000) == 0)
    MCLA_LOG_INFO("WAITHELP sub_82135DC0 #{} h={:08X} t={} al={} lr={:08X}", n,
                  handle, timeoutArg, alertable, ctx.lr);
  __imp__sub_82135DC0(ctx, base);
  const uint32_t d = s_h135DC0done.fetch_add(1) + 1;
  if (d <= 12 || (d % 1000) == 0)
    MCLA_LOG_INFO("WAITHELP RETURNED #{} r3={:08X} (257=timeout)", d,
                  ctx.r3.u32);
}

// Non-alertable wrapper (li r5,0 -> DC0, TU0:18580-18587): the MAIN thread's
// park goes through here (PARK-SAMPLE lr=82135DF8 is inside DC0's own
// NtWaitForSingleObjectEx call). Census names each caller site + handle.
PPC_FUNC_IMPL(__imp__sub_82135DB8);
static std::atomic<uint32_t> s_h135DB8{0};
PPC_FUNC(sub_82135DB8) {
  const uint32_t n = s_h135DB8.fetch_add(1) + 1;
  if (n <= 24 || (n % 1000) == 0)
    MCLA_LOG_INFO("WAITB8 sub_82135DB8 #{} h={:08X} t={} lr={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, ctx.lr);
  __imp__sub_82135DB8(ctx, base);
}

// Sync-wait utility (TU17:10837): wait INFINITE non-alertable on r3, return
// r3==0. The main thread's park handle C9ADB800 arrives HERE - capture the
// caller one level up to name the waiting subsystem.
PPC_FUNC_IMPL(__imp__sub_821C90C0);
static std::atomic<uint32_t> s_h90C0{0};
PPC_FUNC(sub_821C90C0) {
  const uint32_t n = s_h90C0.fetch_add(1) + 1;
  const uint32_t handle = ctx.r3.u32;
  const uint32_t caller = ctx.lr;
  if (n <= 24 || (n % 1000) == 0)
    MCLA_LOG_INFO("WAITSYNC sub_821C90C0 #{} h={:08X} caller={:08X}", n, handle,
                  caller);
  __imp__sub_821C90C0(ctx, base);
}

// Task-join table (generated ppc_recomp.15.cpp sub_821BD220):
//   r30 = 0x8283D1AC  (lis -32124 â†’ 0x82840000, addi -11860)
//   count   = *(u32*)(r30-4)  = 0x8283D1A8   // slot count; mask = count-1
//   entries = *(u32*)(r30+24) = 0x8283D1C4
//   idx     = (count-1) & tag
//   entry   = entries + idx * 28
//   entry+0 = key, entry+12 = in-progress flag (join wait word)
constexpr uint32_t kTaskJoinCountAddr = 0x8283D1A8u;
constexpr uint32_t kTaskJoinEntriesAddr = 0x8283D1C4u;
constexpr uint32_t kTaskJoinStride = 28u;

// Clear task_entry+12 for `tag` if the slot is live and still marked busy.
// Used by FENCE-SC: GPU work is already done synchronously, but the join
// in sub_821BD220 would spin forever on a flag the frozen CP never clears.
static bool ClearTaskJoinBusy(uint32_t tag) {
  if (tag == 0xFFFFFFFFu)
    return false;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t count = 0, entries = 0;
  if (!mem.ReadU32BE(kTaskJoinCountAddr, &count) ||
      !mem.ReadU32BE(kTaskJoinEntriesAddr, &entries) || entries == 0)
    return false;
  const uint32_t mask = (count == 0) ? 0u : (count - 1u);
  const uint32_t idx = tag & mask;
  const uint32_t entry = entries + idx * kTaskJoinStride;
  uint32_t key = 0, busy = 0;
  if (!mem.ReadU32BE(entry + 0, &key) || !mem.ReadU32BE(entry + 12, &busy))
    return false;
  if (key != tag)
    return false;
  if (busy == 0)
    return true;
  (void)mem.WriteU32BE(entry + 12, 0);
  MCLA_LOG_INFO("TASKJOIN-SC tag={:08X} idx={} entry={:08X} busy {:08X}->0", tag,
                idx, entry, busy);
  return true;
}

// FENCE-WAIT (TU21:4085): sub_821E5640(obj=r3, blocking=r4, release=r5)
// waits INFINITE on the embedded completion event [obj+8]. Dump the object
// tag/state so the pending async-job TYPE becomes visible; caller LR names
// the submitter (async wrapper sub_821E5FD0 family).
//
// KERNEL SHORT-CIRCUIT (session 69): When blocking=1, pre-release the
// semaphore before calling the original. The GPU work is already done
// (processed synchronously in the CP doorbell handler), so the fence is
// effectively complete. The worker thread that would normally release it
// is parked on its own semaphore and never runs. Pre-releasing lets the
// original WaitForObject return immediately; the original cleanup
// (close handle, zero fields, optional release-flag work) runs normally.
PPC_FUNC_IMPL(__imp__sub_821E5640);
PPC_FUNC_IMPL(__imp__sub_8244ED10);
static std::atomic<uint32_t> s_h5640{0};
PPC_FUNC(sub_821E5640) {
  const uint32_t n = s_h5640.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  const uint32_t blocking = ctx.r4.u32 & 0xFF;
  const uint32_t releaseFlag = ctx.r5.u32 & 0xFF;
  uint32_t tag = 0, state = 0, evt = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(obj + 0, &tag);
    (void)mem.ReadU32BE(obj + 4, &state);
    (void)mem.ReadU32BE(obj + 8, &evt);
  }

  // KERNEL SHORT-CIRCUIT (session 69/70c): When blocking=1, pre-release the
  // semaphore before calling the original. The GPU work is already done
  // (processed synchronously in the CP doorbell handler), so the fence is
  // effectively complete. The worker thread that would normally release it
  // is parked on its own semaphore and never runs. Pre-releasing lets the
  // original WaitForObject return immediately; the original cleanup
  // (close handle, zero fields, optional release-flag work) runs normally.
  //
  // v1 failed because GetKernelObject(handle) returned raw guest memory
  // instead of the canonical WrapperIdentityMap wrapper â€” Wait() saw count=0
  // on the wrong object.  With GetKernelObject fixed (session 70c) to route
  // through QueryKernelObject, both Release and Wait now operate on the same
  // host wrapper.
  //
  // TASKJOIN-SC (session 72): after the semaphore pre-release, also clear
  // task_entry+12 for this tag. Probe soak proved main then entered
  // sub_821BD220's 10ms join on a busy flag the reinitialized CP never
  // publishes. Same "work IS done" honesty as E98/KDELAY-SC.
  if (blocking == 1 && evt != 0) {
    MCLA_LOG_INFO("FENCE-SC #{} obj={:08X} tag={:08X} ev={:08X} rel={} lr={:08X}",
                  n, obj, tag, evt, releaseFlag, ctx.lr);
    const uint32_t sr3 = ctx.r3.u32, sr4 = ctx.r4.u32, sr5 = ctx.r5.u32;
    ctx.r3.u32 = evt;
    ctx.r4.u32 = 1;
    ctx.r5.u32 = 0;
    __imp__sub_8244ED10(ctx, base);
    ctx.r3.u32 = sr3;
    ctx.r4.u32 = sr4;
    ctx.r5.u32 = sr5;
    if (releaseFlag != 0)
      (void)ClearTaskJoinBusy(tag);
  }

  if (n <= 24 || (n % 500) == 0)
    MCLA_LOG_INFO("FENCE sub_821E5640 #{} obj={:08X} tag={:08X} st={} "
                  "ev={:08X} blk={} lr={:08X}",
                  n, obj, tag, state, evt, blocking, ctx.lr);
  __imp__sub_821E5640(ctx, base);
}

// TASK-JOIN census + short-circuit (session 72): sub_821BD220(tag) joins a
// 28-byte task-table slot, spinning Sleep(10) while entry+12 != 0. Probe
// pinned callerLR=0x821BD334 on the main-thread KDELAY flood. When the slot
// is already known-done (FENCE-SC / TASKJOIN-SC), force busy=0 so the join
// exits. Scoped to main thread to avoid side effects on real worker joins.
PPC_FUNC_IMPL(__imp__sub_821BD220);
static std::atomic<uint32_t> s_hBD220{0};
PPC_FUNC(sub_821BD220) {
  const uint32_t n = s_hBD220.fetch_add(1) + 1;
  const uint32_t tag = ctx.r3.u32;
  uint32_t count = 0, entries = 0, entry = 0, key = 0, busy = 0, idx = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(kTaskJoinCountAddr, &count);
    (void)mem.ReadU32BE(kTaskJoinEntriesAddr, &entries);
    if (entries != 0 && count != 0) {
      idx = tag & (count - 1u);
      entry = entries + idx * kTaskJoinStride;
      (void)mem.ReadU32BE(entry + 0, &key);
      (void)mem.ReadU32BE(entry + 12, &busy);
    }
  }
  if (n <= 32 || (n % 200) == 0)
    MCLA_LOG_INFO("TASKJOIN sub_821BD220 #{} tag={:08X} count={} idx={} "
                  "entry={:08X} key={:08X} busy={:08X} lr={:08X}",
                  n, tag, count, idx, entry, key, busy, ctx.lr);

  // Honest short-circuit: if this is the main-thread join on a slot that is
  // still marked busy, force busy=0 so the 10ms spin can exit. GPU work for
  // FENCE-SC tags is already done synchronously.
  if (busy != 0 && key == tag) {
    const uint32_t mainId = g_mainGuestThreadId.load();
    if (mainId != 0 && GetCurrentThreadId() == mainId) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      MCLA_LOG_INFO("TASKJOIN-SC #{} tag={:08X} entry={:08X} busy {:08X}->0 "
                    "(main)",
                    n, tag, entry, busy);
      (void)mem.WriteU32BE(entry + 12, 0);
    }
  }
  __imp__sub_821BD220(ctx, base);
}

// INFLATE-BEGIN pass-through (session 72): zlibInflater::InflateBegin
// (sub_821D5E10) fatals unless the stream starts with XCompress magic
// 0x0FF512EF. Our VFS serves already-extracted raw files (vfs_rpf.h),
// so the magic check fires on every named resource (meshtextures, â€¦).
// Honest short-circuit: if the stream does not carry the magic, copy the
// remaining input to the output as uncompressed and advance the state â€”
// same shape as the post-decompress pointer update in generated.
//
// state (r4) layout from ppc_recomp.19.cpp sub_821D5E10:
//   +0  remaining input bytes
//   +4  input pointer
//   +8  bytes consumed/produced so far (0 at stream start)
//   +12 expected total output (from XCompress header+4)
//   +16 remaining output space
//   +20 output pointer
//   +24 total produced
constexpr uint32_t kXCompressMagic = 0x0FF512EFu;
// Effect loader 8218C844: lis r9,24952 / ori r8,r9,26482 / cmpw r7,r8
// → expected first dword of a rage effect blob is 0x61786772 ('axgr' BE).
// w9: STAR-GLOW-SEED / D2308-INS were registering the inflated PRELOAD PACK
// (A47FD000) as star_glow. That pack is a multi-chunk resource, NOT a single
// effect file, so BE710's first-word compare fails → FATAL-SOFT "Old version
// of rage effect" at lr=8218C864. Gate every effect-name insert on this
// magic; keep the AFB76-FALLBACK (serves the known-good rage_im blob at
// 827D2DD0) so the guest's own compare passes on real content.
constexpr uint32_t kRgxaMagic = 0x61786772u;
static bool BufLooksLikeRgxa(uint32_t buf) {
  if (buf == 0 || buf == 0xCDCDCDCDu || buf == 0xFFFFFFFFu)
    return false;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t w = 0;
  return mem.ReadU32BE(buf, &w) && w == kRgxaMagic;
}
static void DumpBufHead(const char *tag, uint32_t buf) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t w[4] = {0};
  for (int i = 0; i < 4; ++i)
    (void)mem.ReadU32BE(buf + static_cast<uint32_t>(i * 4), &w[i]);
  MCLA_LOG_WARN("BUF-HEAD {} @{:08X} {:08X} {:08X} {:08X} {:08X} rgxa={}", tag,
                buf, w[0], w[1], w[2], w[3],
                (w[0] == kRgxaMagic) ? "yes" : "no");
}
// F-298: one-shot per dest, log-only. Re-reads the whole host-decoded body from
// guest memory and compares it against the digest taken at write time, so
// "3/4 UI .xsf decompressed into guest memory" rests on the full buffer and not
// on BUF-HEAD's 16 bytes. Marked verified even on a failed read so a bad dest
// cannot turn this into a per-call cost.
static void UiDecVerifyReadback(uint32_t dest) {
  UiDecExpect ex;
  {
    std::lock_guard<std::mutex> lk(g_uiDecMtx);
    const auto it = g_uiDecExpect.find(dest);
    if (it == g_uiDecExpect.end() || it->second.verified)
      return;
    it->second.verified = true;
    ex = it->second;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  std::vector<uint8_t> body(ex.unc);
  if (ex.unc == 0 || !mem.ReadBytes(dest, body.data(), ex.unc)) {
    MCLA_LOG_WARN("PATHB-HOSTVERIFY dest={:08X} pkg={:08X} unc={} read=FAIL",
                  dest, ex.pkg, ex.unc);
    return;
  }
  const uint64_t got = UiFnv1a(body.data(), body.size());
  MCLA_LOG_WARN("PATHB-HOSTVERIFY dest={:08X} pkg={:08X} unc={} want={:016X} "
                "got={:016X} match={}",
                dest, ex.pkg, ex.unc, ex.hash, got,
                (got == ex.hash) ? "true" : "false");
}
// w9: PSTREAM virtual→physical map captured at RSC-HEAD parse time. Used by
// sub_8217D890 (task_dispatch_trace.cpp) to resolve leftover 0x50xxxxxx
// virtual pointers the nested walk did not rewrite (e.g. 5002DB70) so the
// place-pass gets a real delta instead of the "Resource" fatal.
struct MclaRebaseRegion {
  uint32_t vbase, pbase, size;
};
constexpr int kMclaRebaseMax = 24;
MclaRebaseRegion g_mclaRebaseMap[kMclaRebaseMax] = {};
int g_mclaRebaseCount = 0;
// w15: nested 5500-family place candidates recorded by FDBF8-build
// (task_dispatch_trace.cpp). Consumed after root ARR-RERUN.
extern uint32_t g_mclaNestedPlaceObj[];
extern int g_mclaNestedPlaceN;
// w11: guest region table for D828/D890. Layout (BE):
//   +0 u16 countA (=N), +2 u16 countB (=0)
//   +4+i*12 {vbase, pbase, size}
// 82184458 / D890 consumer math uses [table+i*12+8]-[table+i*12+4] which
// equals pbase-vbase with this layout. D828 membership is
// vbase <= addr < vbase+size walking from table+4.
static uint32_t s_gRebaseTable = 0;
static std::atomic<uint32_t> s_maxInflateOut{0};

// w11: materialize g_mclaRebaseMap as the guest region table that
// sub_8217D828 walks and that sub_82184458/D890 index for delta. Without
// this the place-pass group (C9D96280) has [0]=0 → D828 miss → fatal
// "Resource '%s': Invalid fixup... (ptr=600E0000)".
static void MclaPublishGuestRebaseTable()
{
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const int nmap = g_mclaRebaseCount;
  if (nmap <= 0 || nmap > kMclaRebaseMax)
    return;
  if (s_gRebaseTable == 0)
  {
    s_gRebaseTable = mem.Alloc(static_cast<size_t>(kMclaRebaseMax) * 12u + 16u,
                               16);
  }
  if (s_gRebaseTable == 0)
    return;
  // countA=N, countB=0 — D828 uses the sum.
  (void)mem.WriteU32BE(s_gRebaseTable + 0,
                       static_cast<uint32_t>(nmap) << 16);
  for (int i = 0; i < nmap; ++i)
  {
    const uint32_t e =
        s_gRebaseTable + 4u + static_cast<uint32_t>(i) * 12u;
    (void)mem.WriteU32BE(e + 0, g_mclaRebaseMap[i].vbase);
    (void)mem.WriteU32BE(e + 4, g_mclaRebaseMap[i].pbase);
    (void)mem.WriteU32BE(e + 8, g_mclaRebaseMap[i].size);
  }
  MCLA_LOG_WARN("REBASE-TABLE @{:08X} n={} (D828-form vbase/pbase/size)",
                s_gRebaseTable, nmap);
}

// Zero a place-pass rebase group, then point [group+0] at the PSTREAM
// region table so D828 can resolve 0x50/0x60 virtuals instead of fataling.
static void MclaArmRebaseCtx(uint32_t rebaseCtx)
{
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  for (uint32_t off = 0; off < 64; off += 4)
    (void)mem.WriteU32BE(rebaseCtx + off, 0);
  if (s_gRebaseTable != 0)
    (void)mem.WriteU32BE(rebaseCtx + 0, s_gRebaseTable);
}

// Shared PSTREAM virtual-band check: nested-resource 0x50xxxxxx AND
// stream/page 0x60xxxxxx (job #1/#2 dest tags; w11 place-pass blocker).
static bool MclaIsPstreamVirtual(uint32_t p)
{
  return p >= 0x50000000u && p < 0x70000000u;
}

// w24: pointer-family gates for the place-pass Resource fatal.
// Proven w23 miss: D828 r4=41C4FF12 / [arr]=533D00CB — neither is in the
// 0x50/0x60 PSTREAM virtual map nor the 0x80-B phys map. Gate via the
// existing rebase map / delta-0 family; never invent a vtable.
bool MclaPtrInRebaseMap(uint32_t p)
{
  for (int i = 0; i < g_mclaRebaseCount && i < kMclaRebaseMax; ++i)
  {
    const uint32_t vb = g_mclaRebaseMap[i].vbase;
    const uint32_t pb = g_mclaRebaseMap[i].pbase;
    const uint32_t sz = g_mclaRebaseMap[i].size;
    if (sz == 0)
      continue;
    if (p >= vb && p < vb + sz)
      return true;
    if (p >= pb && p < pb + sz)
      return true;
  }
  return false;
}

// F-247 (route 1): dynamic job2-dest membership. True if outPtr is the exact
// physical pbase (the 0xB0-0xC inflate dest) of a region in the CURRENT job2
// rebase map, populated from the live PSTREAM/REQDUMP (0x8004) at :9107. Replaces
// the incomplete hardcoded IsJob2UiDest allowlist for Path B — reads the same map
// MclaPtrInRebaseMap does (unguarded by existing precedent; a job's pbase set is
// stable across that job's inflates).
// F-252: the live map is RESET per Job2 (g_mclaRebaseCount=0), so a job2 pbase
// dest whose inflate runs AFTER a later REQDUMP is missed by the current-map scan
// → falls to the guessing non-job2 path → wrong package → the whole-7MB XMem
// livelock that starves the shared BC140 ring before the UI containers finish
// (w250 B7121000 11456 produced=0 spins). Accumulate every job2 pbase ever seen
// into a persistent set so membership is stable across the whole boot.
static std::mutex g_job2PbaseSeenMtx;
static std::unordered_set<uint32_t> g_job2PbaseSeen;
static void MclaNoteJob2Pbase(uint32_t pbase) {
  if (pbase >= 0xB0000000u && pbase < 0xC0000000u) {
    std::lock_guard<std::mutex> lk(g_job2PbaseSeenMtx);
    g_job2PbaseSeen.insert(pbase);
  }
}
static bool MclaIsCurrentJob2Pbase(uint32_t outPtr)
{
  if (outPtr < 0xB0000000u || outPtr >= 0xC0000000u)
    return false;
  for (int i = 0; i < g_mclaRebaseCount && i < kMclaRebaseMax; ++i)
    if (g_mclaRebaseMap[i].pbase == outPtr && g_mclaRebaseMap[i].size != 0)
      return true;
  {
    std::lock_guard<std::mutex> lk(g_job2PbaseSeenMtx);
    if (g_job2PbaseSeen.count(outPtr))
      return true;
  }
  return false;
}

bool MclaPtrIsKnownPhys(uint32_t p)
{
  // 0x80+ high half = image + host guest-heap + B7 dests + CA/C2 scratch.
  // Delta-0: already at a final address the place-pass can keep.
  return p >= 0x80000000u;
}

bool MclaPtrIsPstreamVirt(uint32_t p) { return MclaIsPstreamVirtual(p); }

bool MclaPtrIsGateBad(uint32_t p)
{
  if (p == 0 || p == 0xFFFFFFFFu)
    return false;
  if (p == 0xCDCDCDCDu || (p & 0xFFFFFF00u) == 0xCDCD0000u)
    return false; // poison family — existing paths handle
  if (MclaIsPstreamVirtual(p))
    return !MclaPtrInRebaseMap(p); // unmapped virtual → already delta-0
  if (MclaPtrIsKnownPhys(p))
    return false;
  if (MclaPtrInRebaseMap(p))
    return false;
  return true; // e.g. 41C4FF12 / 533D00CB
}

// w25: dest-cap helper usable before MclaDestCapFromPstream is defined.
static uint32_t MclaJob2DestCap(uint32_t dest) {
  switch (dest) {
  case 0xB7B41000u:
  case 0xB7981000u:
  case 0xB79A1000u:
  case 0xB79B1000u:
  case 0xB79C1000u:
  case 0xB79E1000u:
  case 0xB7001000u:
  case 0xB7021000u:
  case 0xB7041000u:
  case 0xB7061000u:
  case 0xB7081000u:
  case 0xB70A1000u:
  case 0xB70C1000u:
  case 0xB70E1000u:
  case 0xB7101000u:
    return 0x20000u;
  case 0xB7B61000u:
  case 0xB79C7000u:
  case 0xB7B69000u:
    return 0x10000u;
  case 0xB7B71000u:
    return 0x8000u;
  default:
    return 0x20000u;
  }
}

// w25: deep census — scan job2 dests + known child candidate bands for real
// 8208xxxx swfC objects. Returns count; fills outPtrs/outVts (max 16).
// Does not invent vtables — only reports objects already in guest memory.
static int MclaCensusSwfcChildren(auto &mem, uint32_t *outPtrs, uint32_t *outVts,
                                   int maxOut) {
  static const uint32_t kScan[] = {
      0xB7B41000u, 0xB7981000u, 0xB79A1000u, 0xB79B1000u, 0xB7B61000u,
      0xB7B69000u, 0xB7B71000u, 0xB79C1000u, 0xB79C7000u, 0xB79E1000u,
      0xB7001000u, 0xB7021000u, 0xB7041000u, 0xB7061000u, 0xB7081000u,
      0xB70A1000u, 0xB70C1000u, 0xB70E1000u, 0xB7101000u,
      0xB7996E00u, 0xB7996E40u, // w24 watch / session-28 miss family
      0xB7B6D9B0u, 0xB7B6D9B4u, // arr itself
      0xB79B0C20u,              // w26: +24 list lead (dest-range ptrs)
  };
  int n = 0;
  uint32_t seen[16] = {0};
  // Always dump the arr neighborhood first (w25 census requirement).
  {
    uint32_t aw[16] = {0};
    for (int i = 0; i < 16; ++i)
      (void)mem.ReadU32BE(0xB7B6D9B4u + static_cast<uint32_t>(i * 4), &aw[i]);
    MCLA_LOG_WARN("W25-ARR-DUMP B7B6D9B4 "
                  "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}",
                  aw[0], aw[1], aw[2], aw[3], aw[4], aw[5], aw[6], aw[7],
                  aw[8], aw[9], aw[10], aw[11], aw[12], aw[13], aw[14],
                  aw[15]);
  }
  // w26: also census swfC +24 list (lead B79B0C20 dest-range ptrs).
  // Full helper MclaCensusPlus24List is defined with J2-DIST below; here we
  // only dump the +24 head + known list base so place/bind has evidence.
  {
    uint32_t p24 = 0, lw[8] = {0};
    (void)mem.ReadU32BE(0xB7B41000u + 24u, &p24);
    for (int i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(0xB79B0C20u + static_cast<uint32_t>(i * 4), &lw[i]);
    MCLA_LOG_WARN("W26-PLUS24-HEAD obj+24={:08X} B79B0C20="
                  "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                  p24, lw[0], lw[1], lw[2], lw[3], lw[4], lw[5], lw[6], lw[7]);
  }
  for (uint32_t base : kScan) {
    // Scan a wider window so mid-object children are visible.
    const uint32_t span =
        (base == 0xB7B6D9B0u || base == 0xB7B6D9B4u) ? 0x80u
        : (base == 0xB7996E00u || base == 0xB7996E40u) ? 0x80u
                                                        : 0x800u;
    for (uint32_t off = 0; off + 4 <= span && n < maxOut; off += 4) {
      uint32_t a = 0, vt = 0;
      if (!mem.ReadU32BE(base + off, &a))
        break;
      // A child slot holds a pointer to an object whose [0] is 8208xxxx,
      // OR the dest itself starts with 8208xxxx (object resident in place).
      uint32_t obj = 0;
      if ((a & 0xFFFF0000u) == 0x82080000u) {
        obj = base + off; // vtable word sits here (object head)
        vt = a;
      } else if (a >= 0x80000000u && a < 0xC0000000u && a != 0xCDCDCDCDu &&
                 a != 0xFFFFFFFFu && mem.ReadU32BE(a, &vt) &&
                 (vt & 0xFFFF0000u) == 0x82080000u) {
        obj = a;
      } else {
        continue;
      }
      bool dup = false;
      for (int i = 0; i < n; ++i)
        if (seen[i] == obj)
          dup = true;
      if (dup)
        continue;
      seen[n] = obj;
      if (outPtrs)
        outPtrs[n] = obj;
      if (outVts)
        outVts[n] = vt;
      uint32_t w[6] = {0};
      for (int k = 0; k < 6; ++k)
        (void)mem.ReadU32BE(obj + static_cast<uint32_t>(k * 4), &w[k]);
      MCLA_LOG_WARN("W25-CHILD-CENSUS #{} obj={:08X} vt={:08X} "
                    "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}] "
                    "scanBase={:08X}+{:02X}",
                    n, obj, vt, w[0], w[1], w[2], w[3], w[4], w[5], base,
                    off);
      ++n;
    }
  }
  return n;
}

// w26: guest inflater r3 captured at InflateBegin entry (executor r24 =
// joinTable+32+(idx*4)). XMem ctx is *(inflater+0) — the real 8244FF20
// dispatcher argument. Never call InflateBegin with r3=0 (w25 fatal
// 80004005). Never invent a vtable.
extern "C" void __imp__sub_821D5E10(PPCContext &ctx, uint8_t *base);
extern "C" void __imp__sub_8244FF20(PPCContext &ctx, uint8_t *base);
extern "C" void __imp__sub_82461530(PPCContext &ctx, uint8_t *base);
extern "C" void __imp__sub_824619C0(PPCContext &ctx, uint8_t *base);
extern "C" void __imp__sub_82461E68(PPCContext &ctx, uint8_t *base);
extern "C" void __imp__sub_82461B98(PPCContext &ctx, uint8_t *base);
static std::atomic<uint32_t> s_guestInflaterR3{0};
static std::atomic<uint32_t> s_xmemCtx{0};
static std::atomic<uint32_t> s_joinSlotAddr{0};

// w27: host XCompress (0x0FF512EF) decode. Guest __imp__sub_8244FF20 /
// 82461010 / 82461530 implement the real codec but share a dirty xmemCtx
// (job1 leaves pending-window state). Reset a FRESH decoder ctx, parse XC
// frames at package+20, and call guest 82461530 per frame. Never InflateBegin
// r3=0; never plant compressed bytes; never invent vtables.
void MclaCompleteRscRebaseBeforePlace(uint32_t obj);
// w32: open FDA90 walk bound when +24 holds dest-range/SWF-tag candidates.
bool MclaW32OpenConstructWalk(uint32_t obj, uint32_t stack, bool redispatch);
static void MclaXcCallGuest(auto &mem, uint32_t fnAddr, uint32_t r3,
                            uint32_t r4, uint32_t stack) {
  auto *fn = mcla::kernel::g_memory.FindFunction(fnAddr);
  if (!fn)
    return;
  PPCContext p{};
  p.r1.u64 = stack ? stack : 0x006D8EC0u;
  p.r13.u64 = 0x8F200000u;
  p.r3.u64 = r3;
  p.r4.u64 = r4;
  p.lr = 0x821BC380u;
  fn(p, mcla::kernel::g_memory.base);
}

// Zero XMem decoder state at ctx+20 (covers 82461010/82461530 fields through
// ~+12304) and force codec gate ctx+4==1. Then re-init Huffman tables via
// guest 824619C0 / 82461E68 on state=ctx+20.
static uint32_t MclaXcFreshCtx(auto &mem, uint32_t stack) {
  static std::mutex s_xcMtx;
  static uint32_t s_xcCtx = 0;
  std::lock_guard<std::mutex> lk(s_xcMtx);
  if (s_xcCtx == 0)
    s_xcCtx = mem.Alloc(0x4000u, 16);
  if (!s_xcCtx)
    return 0;
  // Zero whole codec object + decoder state.
  {
    std::vector<uint8_t> z(0x4000, 0);
    (void)mem.WriteBytes(s_xcCtx, z.data(), 0x4000);
  }
  (void)mem.WriteU32BE(s_xcCtx + 4, 1); // codec gate
  // Guest reset/init on decoder state (ctx+20).
  MclaXcCallGuest(mem, 0x824619C0u, s_xcCtx + 20u, 0, stack);
  MclaXcCallGuest(mem, 0x82461E68u, s_xcCtx + 20u, 0, stack);
  // Re-assert codec after guest init (824619C0 writes state+12.. not +4).
  (void)mem.WriteU32BE(s_xcCtx + 4, 1);
  return s_xcCtx;
}

// F-188: in-memory mspack_system adapter for libmspack LZX decompression.
// Pattern from Xenia lzx.cc / XenonRecomp xex_patcher.cpp.
namespace {
struct MspackMemFile {
  uint8_t *buf;
  off_t size;
  off_t pos;
};

static int MspackMemRead(mspack_file *f, void *buf, int n) {
  auto *mf = reinterpret_cast<MspackMemFile *>(f);
  const off_t rem = mf->size - mf->pos;
  const int got = (n < rem) ? n : static_cast<int>(rem);
  if (got > 0) std::memcpy(buf, mf->buf + mf->pos, got);
  mf->pos += got;
  return got;
}
static int MspackMemWrite(mspack_file *f, void *buf, int n) {
  auto *mf = reinterpret_cast<MspackMemFile *>(f);
  const off_t rem = mf->size - mf->pos;
  const int put = (n < rem) ? n : static_cast<int>(rem);
  if (put > 0) std::memcpy(mf->buf + mf->pos, buf, put);
  mf->pos += put;
  return put;
}
static void *MspackMemAlloc(mspack_system *, size_t n) { return std::malloc(n); }
static void MspackMemFree(void *p) { std::free(p); }
static void MspackMemCopy(void *s, void *d, size_t n) { std::memcpy(d, s, n); }

static mspack_system g_mspackSys = {
    nullptr,          // open
    nullptr,          // close
    MspackMemRead,    // read
    MspackMemWrite,   // write
    nullptr,          // seek
    nullptr,          // tell
    nullptr,          // message
    MspackMemAlloc,   // alloc
    MspackMemFree,    // free
    MspackMemCopy,    // copy
    nullptr           // null_ptr
};
} // namespace

// F-188: decompress a single LZX stream (one XC frame payload or full stream)
// using host libmspack. Returns bytes produced into dst; 0 = fail.
static uint32_t MclaHostLzxDecode(const uint8_t *src, uint32_t srcLen,
                                  uint8_t *dst, uint32_t dstCap,
                                  uint32_t wantOut) {
  if (!src || srcLen < 2 || !dst || dstCap < 16)
    return 0;
  const uint32_t outSz = (wantOut > 0 && wantOut <= dstCap) ? wantOut : dstCap;
  MspackMemFile inFile{const_cast<uint8_t *>(src),
                       static_cast<off_t>(srcLen), 0};
  MspackMemFile outFile{dst, static_cast<off_t>(outSz), 0};
  // reset_interval=0: one continuous LZX bitstream. Guest 82461010 keeps the
  // same decoder object across XC frames (r31=r3+20, no 824614E8 reset).
  auto *lzx = lzxd_init(&g_mspackSys,
                         reinterpret_cast<mspack_file *>(&inFile),
                         reinterpret_cast<mspack_file *>(&outFile),
                         kXcWindowBits, 0, 0x8000,
                         static_cast<off_t>(outSz), 0);
  if (!lzx) {
    MCLA_LOG_WARN("XC-HOST-LZX lzxd_init FAILED srcLen={} outSz={} windowBits={}",
                  srcLen, outSz, kXcWindowBits);
    return 0;
  }
  const int rc = lzxd_decompress(lzx, static_cast<off_t>(outSz));
  const uint32_t produced = static_cast<uint32_t>(outFile.pos);
  if (rc != MSPACK_ERR_OK && produced == 0) {
    MCLA_LOG_WARN("XC-HOST-LZX decompress FAILED rc={} srcLen={} outSz={} inFilePos={}/{} outFilePos={}",
                  rc, srcLen, outSz, inFile.pos, inFile.size, outFile.pos);
  }
  lzxd_free(lzx);
  return (rc == MSPACK_ERR_OK || produced > 0) ? produced : 0;
}

// F-188 Path A: host-buffer XC frame walk (UI serve path). Same frame format as
// MclaXcDecodeGuestFrames. XCompress frames are one LZX bitstream split into
// 32 KiB chunks (guest keeps ctx+20 across frames), so payload bytes are
// concatenated and decoded in one lzxd call. Returns decompressed bytes; 0 =
// fail. Partial output is a fail — never serve a truncated resource.
static uint32_t MclaHostXcDecodePackage(const uint8_t *pkg, uint32_t pkgSz,
                                        std::vector<uint8_t> &out) {
  out.clear();
  if (!pkg || pkgSz < 24)
    return 0;
  const uint32_t ph0 = MclaBE(pkg);
  uint32_t payloadOff = 0;
  uint32_t wantOut = 0;
  if (ph0 == 0x05435352u) { // RSC5
    if (pkgSz < 20)
      return 0;
    const uint32_t xc = MclaBE(pkg + 12);
    if (xc != kXCompressMagic)
      return 0;
    payloadOff = 20; // RSC5(12)+XC(4)+size(4)
    wantOut = MclaBE(pkg + 16);
    if (wantOut < 16u || wantOut > 0x400000u)
      wantOut = 0;
  } else if (ph0 == kXCompressMagic) {
    payloadOff = 8;
    wantOut = MclaBE(pkg + 4);
    if (wantOut < 16u || wantOut > 0x400000u)
      wantOut = 0;
  } else {
    return 0;
  }
  if (payloadOff >= pkgSz)
    return 0;
  if (wantOut == 0)
    wantOut = 0x100000; // 1 MB safety cap

  // Walk frames and concatenate compressed payloads (headers stripped).
  // Keep per-frame uncompressed sizes / payload lengths for the SS fallback.
  std::vector<uint8_t> payload;
  std::vector<uint32_t> frameUncomp;
  std::vector<uint32_t> framePayLen;
  payload.reserve(pkgSz - payloadOff);
  frameUncomp.reserve(64);
  framePayLen.reserve(64);
  uint32_t src = payloadOff;
  int frameN = 0;
  while (src + 2 <= pkgSz && frameN < 512) {
    const uint8_t *hb = pkg + src;
    uint32_t hdrSz = 0, uncomp = 0, payLen = 0;
    if (hb[0] == 0xFF) {
      if (src + 5 > pkgSz)
        break;
      hdrSz = 5;
      uncomp = (uint32_t(hb[1]) << 8) | uint32_t(hb[2]);
      payLen = (uint32_t(hb[3]) << 8) | uint32_t(hb[4]);
    } else {
      hdrSz = 2;
      uncomp = 0x8000u;
      payLen = (uint32_t(hb[0]) << 8) | uint32_t(hb[1]);
    }
    if (payLen == 0 || src + hdrSz + payLen > pkgSz)
      break;
    payload.insert(payload.end(), pkg + src + hdrSz, pkg + src + hdrSz + payLen);
    frameUncomp.push_back(uncomp);
    framePayLen.push_back(payLen);
    src += hdrSz + payLen;
    ++frameN;
  }
  if (payload.empty() || frameN == 0) {
    MCLA_LOG_WARN("XSF-LZX-FAIL pkgSz={} wantOut={} frames=0 (no XC frames)",
                  pkgSz, wantOut);
    return 0;
  }

  out.resize(wantOut);
  // One LZX stream over all frame payloads. reset_interval = 0x8000 matches
  // the 32 KiB XCompress block size (per-frame lzxd_init reset_interval=0
  // decoded frame 0 only and then returned rc=11 on frame 1).
  const uint32_t produced =
      MclaHostLzxDecode(payload.data(), static_cast<uint32_t>(payload.size()),
                        out.data(), wantOut, wantOut);
  // Require a complete resource: never swap a truncated body into the serve
  // (w199: produced=32768 of 143069 corrupted LISTLINE/TYPINIT consumers).
  if (produced > 0 && produced + 64u >= wantOut) {
    out.resize(produced);
    MCLA_LOG_WARN("XSF-LZX pkgSz={} wantOut={} produced={} frames={} payLen={}",
                  pkgSz, wantOut, produced, frameN,
                  static_cast<uint32_t>(payload.size()));
    return produced;
  }

  // Fallback: shared-state incremental LZX (guest 82461010 keeps one decoder
  // across XC frames, r31=r3+20, no 824614E8 reset). Init one lzxd_stream once
  // (window 17, reset_interval=0, output_length=wantOut), walk XC frames
  // appending payload and calling lzxd_decompress(lzx, frameUncomp) each time.
  {
    out.assign(wantOut, 0);
    // Input size starts at 0 and grows per frame = "append payload".
    MspackMemFile inFile{payload.data(), 0, 0};
    MspackMemFile outFile{out.data(), static_cast<off_t>(wantOut), 0};
    auto *lzx = lzxd_init(&g_mspackSys,
                          reinterpret_cast<mspack_file *>(&inFile),
                          reinterpret_cast<mspack_file *>(&outFile),
                          kXcWindowBits, 0, 0x8000,
                          static_cast<off_t>(wantOut), 0);
    if (!lzx) {
      MCLA_LOG_WARN("XSF-LZX-SS-FAIL pkgSz={} wantOut={} concatProd={} "
                    "frames={} (lzxd_init)",
                    pkgSz, wantOut, produced, frameN);
      MCLA_LOG_WARN("XSF-LZX-FAIL pkgSz={} wantOut={} produced={} frames={} "
                    "payLen={} (partial or zero)",
                    pkgSz, wantOut, produced, frameN,
                    static_cast<uint32_t>(payload.size()));
      out.clear();
      return 0;
    }
    int ssRc = MSPACK_ERR_OK;
    off_t ssPayOff = 0;
    for (int i = 0; i < frameN; ++i) {
      ssPayOff += static_cast<off_t>(framePayLen[static_cast<size_t>(i)]);
      inFile.size = ssPayOff; // append this frame's compressed payload
      off_t nOut =
          static_cast<off_t>(frameUncomp[static_cast<size_t>(i)]
                                 ? frameUncomp[static_cast<size_t>(i)]
                                 : 0x8000u);
      const off_t remain = static_cast<off_t>(wantOut) - outFile.pos;
      if (remain <= 0)
        break;
      if (nOut > remain)
        nOut = remain;
      ssRc = lzxd_decompress(lzx, nOut);
      if (ssRc != MSPACK_ERR_OK)
        break;
    }
    const uint32_t ssProduced = static_cast<uint32_t>(outFile.pos);
    lzxd_free(lzx);
    if (ssProduced > 0 && ssProduced + 64u >= wantOut) {
      out.resize(ssProduced);
      MCLA_LOG_WARN("XSF-LZX-SS pkgSz={} wantOut={} produced={} frames={} "
                    "payLen={} concatProd={}",
                    pkgSz, wantOut, ssProduced, frameN,
                    static_cast<uint32_t>(payload.size()), produced);
      return ssProduced;
    }
    MCLA_LOG_WARN("XSF-LZX-SS-FAIL pkgSz={} wantOut={} produced={} frames={} "
                  "payLen={} concatProd={} rc={} inPos={}/{} (partial or zero)",
                  pkgSz, wantOut, ssProduced, frameN,
                  static_cast<uint32_t>(payload.size()), produced, ssRc,
                  inFile.pos, inFile.size);
    MCLA_LOG_WARN("XSF-LZX-FAIL pkgSz={} wantOut={} produced={} frames={} "
                  "payLen={} (partial or zero)",
                  pkgSz, wantOut, produced, frameN,
                  static_cast<uint32_t>(payload.size()));
    out.clear();
    return 0;
  }
}

// Parse XC frames after RSC5+XC header (payload at package+20) and call
// guest 82461530 per frame into dest. Returns produced bytes; 0 = fail.
// Frame format (from 82461010):
//   byte0==0xFF: uncomp=BE16[1..2], payloadLen=BE16[3..4], hdr=5
//   else:        uncomp=0x8000,      payloadLen=BE16[0..1], hdr=2
static uint32_t MclaXcDecodeGuestFrames(auto &mem, uint32_t pkgBounce,
                                        uint32_t pkgSz, uint32_t dest,
                                        uint32_t destCap, uint32_t stack) {
  if (!pkgBounce || !dest || destCap < 16)
    return 0;
  uint32_t ph[6] = {0};
  for (int i = 0; i < 6; ++i)
    (void)mem.ReadU32BE(pkgBounce + static_cast<uint32_t>(i * 4), &ph[i]);
  uint32_t payloadOff = 0;
  uint32_t wantOut = destCap;
  if (ph[0] == 0x05435352u && ph[3] == kXCompressMagic) {
    payloadOff = 20u; // RSC5(12) + XC magic(4) + size(4)
    if (ph[4] > 16u && ph[4] < 0x400000u)
      wantOut = ph[4];
  } else if (ph[0] == kXCompressMagic) {
    payloadOff = 8u;
    if (ph[1] > 16u && ph[1] < 0x400000u)
      wantOut = ph[1];
  } else {
    return 0;
  }
  if (wantOut > destCap)
    wantOut = destCap;

  uint32_t src = pkgBounce + payloadOff;
  uint32_t srcLeft = (pkgSz > payloadOff) ? (pkgSz - payloadOff) : 0;
  if (srcLeft < 4)
    return 0;

  // Census first 8 frame headers.
  {
    uint8_t peek[32] = {0};
    (void)mem.ReadBytes(src, peek, 32);
    uint32_t be[8] = {0};
    for (int i = 0; i < 8; ++i)
      be[i] = MclaBE(peek + i * 4);
    MCLA_LOG_WARN("W27-XC-FRAMES src={:08X} left={} wantOut={} "
                  "head=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X}]",
                  src, srcLeft, wantOut, be[0], be[1], be[2], be[3], be[4],
                  be[5], be[6], be[7]);
  }

  static std::mutex s_xcDecMtx;
  std::lock_guard<std::mutex> dlock(s_xcDecMtx);
  static uint32_t s_xcSt = 0;  // size pointers
  static uint32_t s_xcProd = 0; // produced out
  if (s_xcSt == 0)
    s_xcSt = mem.Alloc(32, 16);
  if (s_xcProd == 0)
    s_xcProd = mem.Alloc(32, 16);
  if (!s_xcSt || !s_xcProd)
    return 0;

  uint32_t produced = 0;
  int frameN = 0;
  int failN = 0;
  while (srcLeft >= 2 && produced < wantOut && frameN < 256) {
    uint8_t hb[8] = {0};
    if (!mem.ReadBytes(src, hb, 8))
      break;
    uint32_t hdr = 0;
    uint32_t uncomp = 0;
    uint32_t payLen = 0;
    uint32_t hdrSz = 0;
    if (hb[0] == 0xFF) {
      if (srcLeft < 5)
        break;
      hdrSz = 5;
      uncomp = (uint32_t(hb[1]) << 8) | uint32_t(hb[2]);
      payLen = (uint32_t(hb[3]) << 8) | uint32_t(hb[4]);
    } else {
      hdrSz = 2;
      uncomp = 0x8000u;
      payLen = (uint32_t(hb[0]) << 8) | uint32_t(hb[1]);
    }
    hdr = MclaBE(hb);
    const uint32_t frameTotal = payLen + hdrSz;
    if (payLen == 0 || frameTotal > srcLeft + 16u) {
      MCLA_LOG_WARN("W27-XC-FRAME-BAD #{} src={:08X} hdr={:08X} payLen={} "
                    "srcLeft={} hdrSz={}",
                    frameN, src, hdr, payLen, srcLeft, hdrSz);
      break;
    }
    const uint32_t outRoom = wantOut - produced;
    const uint32_t tryOut = (uncomp > 0 && uncomp < outRoom) ? uncomp : outRoom;
    if (tryOut < 16)
      break;

    uint32_t frameOut = 0;
    uint32_t ret = 0;
    if constexpr (kHostLzxDecode) {
      // F-188: host-side LZX via libmspack per XC frame.
      std::vector<uint8_t> compBuf(payLen);
      if (!mem.ReadBytes(src + hdrSz, compBuf.data(), payLen))
        break;
      std::vector<uint8_t> outBuf(tryOut);
      frameOut = MclaHostLzxDecode(compBuf.data(), payLen,
                                   outBuf.data(), tryOut,
                                   uncomp ? uncomp : tryOut);
      if (frameOut > 0)
        (void)mem.WriteBytes(dest + produced, outBuf.data(), frameOut);
      ret = (frameOut > 0) ? 0 : 1;
      if (frameN < 12 || (frameN % 32) == 0) {
        uint32_t cb = 0;
        if (payLen >= 4)
          cb = (uint32_t(compBuf[0]) << 24) | (uint32_t(compBuf[1]) << 16) |
               (uint32_t(compBuf[2]) << 8) | uint32_t(compBuf[3]);
        MCLA_LOG_WARN("W27-XC-HOST-FRAME #{} payLen={} uncomp={} "
                      "frameOut={} ret={} head={:08X}",
                      frameN, payLen, uncomp, frameOut, ret, cb);
      }
    } else {
    // Fresh ctx per frame so Huffman tables match this frame.
    const uint32_t ctx = MclaXcFreshCtx(mem, stack);
    if (!ctx)
      break;
    (void)mem.WriteU32BE(s_xcProd + 0, 0);
    (void)mem.WriteU32BE(s_xcSt + 0, tryOut);
    (void)mem.WriteU32BE(s_xcSt + 4, payLen);

    // 82461530 ABI:
    //   r3=state(ctx+20) r4=uncomp r5=srcPayload r6=srcLen
    //   r7=dest r8=destCap r9=&produced
    auto *fn = mcla::kernel::g_memory.FindFunction(0x82461530u);
    if (!fn) {
      MCLA_LOG_WARN("W27-XC-NOFN 82461530 missing");
      return 0;
    }
    PPCContext p{};
    p.r1.u64 = stack ? stack : 0x006D8EC0u;
    p.r13.u64 = 0x8F200000u;
    p.r3.u64 = ctx + 20u;
    p.r4.u64 = uncomp ? uncomp : tryOut;
    p.r5.u64 = src + hdrSz;
    p.r6.u64 = payLen;
    p.r7.u64 = dest + produced;
    p.r8.u64 = tryOut;
    p.r9.u64 = s_xcProd;
    p.lr = 0x821BC380u;
    fn(p, mcla::kernel::g_memory.base);
    ret = p.r3.u32;
    (void)mem.ReadU32BE(s_xcProd + 0, &frameOut);
    } // end guest path
    if (frameN < 12 || (frameN % 32) == 0) {
      uint32_t dh[4] = {0};
      for (int k = 0; k < 4; ++k)
        (void)mem.ReadU32BE(dest + produced + static_cast<uint32_t>(k * 4),
                            &dh[k]);
      MCLA_LOG_WARN("W27-XC-FRAME #{} src={:08X} hdr={:08X} hdrSz={} "
                    "payLen={} uncomp={} ret={:08X} frameOut={} "
                    "dest+prod={:08X} head=[{:08X} {:08X} {:08X} {:08X}]",
                    frameN, src, hdr, hdrSz, payLen, uncomp, ret, frameOut,
                    dest + produced, dh[0], dh[1], dh[2], dh[3]);
    }
    if (ret != 0 || frameOut == 0) {
      ++failN;
      // Advance anyway so we can walk the stream; do not plant the frame.
      src += frameTotal;
      srcLeft -= frameTotal;
      ++frameN;
      if (failN >= 8 && produced == 0)
        break;
      continue;
    }
    produced += frameOut;
    src += frameTotal;
    srcLeft -= (frameTotal <= srcLeft) ? frameTotal : srcLeft;
    ++frameN;
  }

  // Census scratch after frames.
  uint32_t dh[8] = {0};
  for (int k = 0; k < 8; ++k)
    (void)mem.ReadU32BE(dest + static_cast<uint32_t>(k * 4), &dh[k]);
  uint32_t mid = 0;
  if (produced > 64)
    (void)mem.ReadU32BE(dest + 32, &mid);
  MCLA_LOG_WARN("W27-XC-FRAMES-DONE frames={} failN={} produced={} "
                "wantOut={} dest={:08X} head=[{:08X} {:08X} {:08X} {:08X} "
                "{:08X} {:08X} {:08X} {:08X}] mid32={:08X}",
                frameN, failN, produced, wantOut, dest, dh[0], dh[1], dh[2],
                dh[3], dh[4], dh[5], dh[6], dh[7], mid);
  return produced;
}

// Full-stream XMem via a FRESH ctx (package payload at +20).
static uint32_t MclaXcDecodeFullStream(auto &mem, uint32_t pkgBounce,
                                       uint32_t pkgSz, uint32_t dest,
                                       uint32_t destCap, uint32_t stack,
                                       bool forceFresh = false) {
  if (!pkgBounce || !dest || destCap < 16)
    return 0;
  uint32_t ph[6] = {0};
  for (int i = 0; i < 6; ++i)
    (void)mem.ReadU32BE(pkgBounce + static_cast<uint32_t>(i * 4), &ph[i]);
  uint32_t payloadOff = 20u;
  uint32_t tryOut = destCap;
  uint32_t hint = 0;
  if (ph[0] == 0x05435352u && ph[3] == kXCompressMagic) {
    payloadOff = 20u;
    if (ph[4] > 16u && ph[4] < 0x400000u)
      hint = ph[4];
  } else if (ph[0] == kXCompressMagic) {
    payloadOff = 8u;
    if (ph[1] > 16u && ph[1] < 0x400000u)
      hint = ph[1];
  } else {
    return 0;
  }
  // w27: +16 hint is often only the FIRST resource (0x2FFC9). Place/arr
  // live deeper in the PSTREAM image — target destCap when it is larger.
  if (destCap > hint)
    tryOut = destCap;
  else if (hint > 16u)
    tryOut = hint;
  if (tryOut > destCap)
    tryOut = destCap;
  const uint32_t srcN =
      (pkgSz > payloadOff + 8u) ? (pkgSz - payloadOff) : 0u;
  if (srcN < 8)
    return 0;

  // F-188: try host-side LZX on the full payload before guest path.
  if constexpr (kHostLzxDecode) {
    std::vector<uint8_t> compBuf(srcN);
    if (mem.ReadBytes(pkgBounce + payloadOff, compBuf.data(), srcN)) {
      std::vector<uint8_t> outBuf(tryOut);
      const uint32_t produced = MclaHostLzxDecode(
          compBuf.data(), srcN, outBuf.data(), tryOut, tryOut);
      if (produced > 0) {
        (void)mem.WriteBytes(dest, outBuf.data(), produced);
        MCLA_LOG_WARN("W27-XC-HOST-FULL srcN={} tryOut={} produced={}",
                      srcN, tryOut, produced);
        return produced;
      }
      MCLA_LOG_WARN("W27-XC-HOST-FULL-FAIL srcN={} tryOut={}, falling to guest",
                    srcN, tryOut);
    }
  }

  static std::mutex s_xcFullMtx;
  std::lock_guard<std::mutex> lk(s_xcFullMtx);
  static uint32_t s_sz = 0;
  if (s_sz == 0)
    s_sz = mem.Alloc(32, 16);
  if (!s_sz)
    return 0;

  // w27: prefer the WARM shared xmemCtx that job1 XMem just used
  // successfully (head=44365500 / 00019249). Note: live xmemCtx is
  // 4000FD80 — NOT in the 0x80xxxxxx phys band. Accept any non-poison
  // guest pointer. Fresh allocs lack the decoder window/tables the guest
  // built at boot. Soft-reset only the pending-stream fields at
  // state+12264..12304; keep Huffman tables.
  uint32_t ctx = forceFresh ? 0u : s_xmemCtx.load();
  if (!forceFresh &&
      (ctx == 0 || ctx == 0xCDCDCDCDu || ctx == 0xFFFFFFFFu)) {
    const uint32_t inf = s_guestInflaterR3.load();
    if (inf && inf != 0xCDCDCDCDu) {
      uint32_t w0 = 0;
      if (mem.ReadU32BE(inf, &w0) && w0 && w0 != 0xCDCDCDCDu)
        ctx = w0;
    }
  }
  const bool warm = (ctx != 0 && ctx != 0xCDCDCDCDu &&
                     ctx != 0xFFFFFFFFu);
  if (warm) {
    // Soft-reset pending stream fields (r31=ctx+20 → offsets 12264+).
    for (uint32_t off = 12264u; off <= 12304u; off += 4)
      (void)mem.WriteU32BE(ctx + 20u + off, 0);
    (void)mem.WriteU32BE(ctx + 4u, 1);
    // Keep inflater-linked window if present at inflater+4.
    const uint32_t inf = s_guestInflaterR3.load();
    if (inf && inf != 0xCDCDCDCDu) {
      uint32_t win = 0, wsz = 0;
      (void)mem.ReadU32BE(inf + 4, &win);
      (void)mem.ReadU32BE(inf + 8, &wsz);
      if (win && win != 0xCDCDCDCDu) {
        (void)mem.WriteU32BE(ctx + 8u, wsz ? wsz : 0x80000u);
      }
    }
  } else {
    ctx = MclaXcFreshCtx(mem, stack);
  }
  if (!ctx)
    return 0;
  // w27: XMem produces one window (~32KB) per call and reports consumed
  // in *srcSz. Loop: advance src by consumed, dest by produced, until
  // no progress or destCap filled.
  uint32_t producedTotal = 0;
  uint32_t srcAdv = 0;
  const uint32_t srcBase = pkgBounce + payloadOff;
  for (int call = 0; call < 64 && producedTotal + 16 < tryOut; ++call) {
    const uint32_t srcLeft = (srcN > srcAdv) ? (srcN - srcAdv) : 0;
    if (srcLeft < 4)
      break;
    const uint32_t destRoom = tryOut - producedTotal;
    (void)mem.WriteU32BE(s_sz + 0, destRoom);
    (void)mem.WriteU32BE(s_sz + 4, srcLeft);
    if (call == 0) {
      std::vector<uint8_t> z(64, 0);
      (void)mem.WriteBytes(dest, z.data(), 64);
    }
    PPCContext p{};
    p.r1.u64 = stack ? stack : 0x006D8EC0u;
    p.r13.u64 = 0x8F200000u;
    p.r3.u64 = ctx;
    p.r4.u64 = dest + producedTotal;
    p.r5.u64 = s_sz + 0;
    p.r6.u64 = srcBase + srcAdv;
    p.r7.u64 = s_sz + 4;
    p.lr = 0x821D5EBCu;
    __imp__sub_8244FF20(p, mcla::kernel::g_memory.base);
    const uint32_t ret = p.r3.u32;
    uint32_t dSz = 0, sSz = 0;
    (void)mem.ReadU32BE(s_sz + 0, &dSz);
    (void)mem.ReadU32BE(s_sz + 4, &sSz);
    uint32_t dh[4] = {0};
    for (int k = 0; k < 4; ++k)
      (void)mem.ReadU32BE(dest + producedTotal + static_cast<uint32_t>(k * 4),
                          &dh[k]);
    // Interpret sSz as consumed this call (82461010 writes r24).
    uint32_t consumed = sSz;
    if (consumed == 0 || consumed > srcLeft) {
      // Some builds leave *srcSz as remaining; try the complement.
      const uint32_t alt = srcLeft - sSz;
      if (alt > 0 && alt <= srcLeft)
        consumed = alt;
    }
    if (call < 8 || (call % 8) == 0) {
      MCLA_LOG_WARN("W27-XC-FULL#{} ctx={:08X} warm={} dest+={} "
                    "src+={:08X} destRoom={} ret={:08X} dSz={} sSz={} "
                    "consumed={} head=[{:08X} {:08X} {:08X} {:08X}]",
                    call, ctx, warm ? 1 : 0, producedTotal,
                    srcBase + srcAdv, destRoom, ret, dSz, sSz, consumed,
                    dh[0], dh[1], dh[2], dh[3]);
    }
    if (dSz > 0 && dSz <= destRoom) {
      producedTotal += dSz;
    } else if (dSz > destRoom) {
      producedTotal = tryOut;
    }
    if (consumed == 0 && dSz == 0)
      break;
    srcAdv += consumed ? consumed : (dSz ? 4u : 0u);
    if (srcAdv >= srcN)
      break;
    // Soft-reset pending stream between windows so the next call starts
    // a fresh block boundary rather than a dirty continuation.
    if (warm) {
      for (uint32_t off = 12264u; off <= 12304u; off += 4)
        (void)mem.WriteU32BE(ctx + 20u + off, 0);
      (void)mem.WriteU32BE(ctx + 4u, 1);
    }
  }
  uint32_t dh[8] = {0};
  for (int k = 0; k < 8; ++k)
    (void)mem.ReadU32BE(dest + static_cast<uint32_t>(k * 4), &dh[k]);
  MCLA_LOG_WARN("W27-XC-FULL-DONE ctx={:08X} warm={} dest={:08X} "
                "producedTotal={} tryOut={} srcAdv={} "
                "head=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                "{:08X}]",
                ctx, warm ? 1 : 0, dest, producedTotal, tryOut, srcAdv,
                dh[0], dh[1], dh[2], dh[3], dh[4], dh[5], dh[6], dh[7]);
  // w28: multi-call soft-reset walk produced high-entropy heads (B6E3AE7F)
  // vs job1's single-call convention (destSz=7179940 srcSz=7179936
  // src=pkg+0x14 → head=44365500). Retry once with job1's exact sizes and
  // NO mid-stream ctx soft-reset when heads look like entropy.
  const bool entropyHead =
      dh[0] != 0 && dh[0] != 0xCDCDCDCDu &&
      (dh[0] & 0xFFFFFF00u) != 0x44365500u &&
      (dh[0] & 0xFFFFFF00u) != 0x44495500u && (dh[0] & 0xFFFFu) != 0x5500u &&
      dh[0] != 0x00019249u && dh[0] != 0x05435352u && dh[0] != 0x0FF512EFu;
  if (entropyHead && warm && ctx && srcN > 32) {
    const uint32_t j1DestSz = 7179940u; // w24 job1 XMem destSz
    const uint32_t j1SrcSz = 7179936u;  // w24 job1 XMem srcSz
    static uint32_t s_j1sz = 0;
    if (s_j1sz == 0)
      s_j1sz = mem.Alloc(32, 16);
    if (s_j1sz) {
      std::vector<uint8_t> z(64, 0);
      (void)mem.WriteBytes(dest, z.data(), 64);
      (void)mem.WriteU32BE(s_j1sz + 0, j1DestSz);
      (void)mem.WriteU32BE(s_j1sz + 4, j1SrcSz);
      (void)mem.WriteU32BE(ctx + 4u, 1);
      PPCContext p{};
      p.r1.u64 = stack ? stack : 0x006D8EC0u;
      p.r13.u64 = 0x8F200000u;
      p.r3.u64 = ctx;
      p.r4.u64 = dest;
      p.r5.u64 = s_j1sz + 0;
      p.r6.u64 = srcBase; // pkgBounce+payloadOff, w24 used +0x14
      p.r7.u64 = s_j1sz + 4;
      p.lr = 0x821D5EBCu;
      __imp__sub_8244FF20(p, mcla::kernel::g_memory.base);
      uint32_t jdSz = 0, jsSz = 0, jh[4] = {0};
      (void)mem.ReadU32BE(s_j1sz + 0, &jdSz);
      (void)mem.ReadU32BE(s_j1sz + 4, &jsSz);
      for (int k = 0; k < 4; ++k)
        (void)mem.ReadU32BE(dest + static_cast<uint32_t>(k * 4), &jh[k]);
      const bool j1live =
          (jh[0] & 0xFFFFFF00u) == 0x44365500u ||
          (jh[0] & 0xFFFFFF00u) == 0x44495500u ||
          (jh[0] & 0xFFFFu) == 0x5500u || jh[0] == 0x00019249u;
      MCLA_LOG_WARN(
          "W28-XC-J1CONV ctx={:08X} dest={:08X} ret dSz={} sSz={} "
          "head=[{:08X} {:08X} {:08X} {:08X}] live={}",
          ctx, dest, jdSz, jsSz, jh[0], jh[1], jh[2], jh[3],
          j1live ? 1 : 0);
      if (j1live) {
        // Count non-zero produced window up to min(jdSz, destCap).
        uint32_t lim = jdSz;
        if (lim > destCap)
          lim = destCap;
        if (lim < 64)
          lim = 64;
        return lim;
      }
    }
  }
  const bool live = (dh[0] != 0 && dh[0] != 0xCDCDCDCDu &&
                     dh[0] != 0xFFFFFFFFu) ||
                    (dh[0] == 0 && dh[1] != 0 && dh[1] != 0xCDCDCDCDu) ||
                    (producedTotal > 64 && dh[0] != 0xCDCDCDCDu);
  return live ? producedTotal : 0;
}

// w27 Path D: guest InflateBegin with captured inflater r3 (never 0).
// Job1 XMem via this path produces real heads when ctx is warm.
static uint32_t MclaXcDecodeGuestInflate(auto &mem, uint32_t pkgBounce,
                                         uint32_t pkgSz, uint32_t dest,
                                         uint32_t destCap, uint32_t stack) {
  const uint32_t inflater = s_guestInflaterR3.load();
  if (!inflater || inflater < 0x80000000u || inflater == 0xCDCDCDCDu)
    return 0;
  if (!pkgBounce || !dest || destCap < 16)
    return 0;
  static std::mutex s_giMtx;
  std::lock_guard<std::mutex> lk(s_giMtx);
  static uint32_t s_giSt = 0;
  if (s_giSt == 0)
    s_giSt = mem.Alloc(64, 16);
  if (!s_giSt)
    return 0;
  const uint32_t srcOff = 12u; // XC magic; InflateBegin strips +8 more
  const uint32_t srcN =
      (pkgSz > srcOff + 16u) ? (pkgSz - srcOff) : 0x8000u;
  (void)mem.WriteU32BE(s_giSt + 0, srcN);
  (void)mem.WriteU32BE(s_giSt + 4, pkgBounce + srcOff);
  (void)mem.WriteU32BE(s_giSt + 8, 0);
  (void)mem.WriteU32BE(s_giSt + 12, destCap);
  (void)mem.WriteU32BE(s_giSt + 16, destCap);
  (void)mem.WriteU32BE(s_giSt + 20, dest);
  (void)mem.WriteU32BE(s_giSt + 24, 0);
  {
    std::vector<uint8_t> z(64, 0);
    (void)mem.WriteBytes(dest, z.data(), 64);
  }
  PPCContext p{};
  p.r1.u64 = stack ? stack : 0x006D8EC0u;
  p.r13.u64 = 0x8F200000u;
  p.r3.u64 = inflater;
  p.r4.u64 = s_giSt;
  p.lr = 0x821BC380u;
  __imp__sub_821D5E10(p, mcla::kernel::g_memory.base);
  uint32_t produced = 0, dh[8] = {0};
  (void)mem.ReadU32BE(s_giSt + 24, &produced);
  for (int k = 0; k < 8; ++k)
    (void)mem.ReadU32BE(dest + static_cast<uint32_t>(k * 4), &dh[k]);
  MCLA_LOG_WARN("W27-XC-INF r3={:08X} dest={:08X} destCap={} produced={} "
                "head=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                "{:08X}]",
                inflater, dest, destCap, produced, dh[0], dh[1], dh[2], dh[3],
                dh[4], dh[5], dh[6], dh[7]);
  const bool live = (dh[0] != 0 && dh[0] != 0xCDCDCDCDu &&
                     dh[0] != 0xFFFFFFFFu) ||
                    (dh[0] == 0 && dh[1] != 0 && dh[1] != 0xCDCDCDCDu);
  return live ? produced : 0;
}

// Census joinTable+32+(a1*4) family + inflater object words.
static void MclaCensusInflaterFamily(auto &mem, uint32_t infR3) {
  uint32_t iw[8] = {0};
  if (infR3 && infR3 >= 0x80000000u && infR3 != 0xCDCDCDCDu) {
    for (int i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(infR3 + static_cast<uint32_t>(i * 4), &iw[i]);
    uint32_t xctx = iw[0];
    if (xctx != 0 && xctx != 0xCDCDCDCDu)
      s_xmemCtx.store(xctx);
  }
  // joinTable family: load-queue / task-join / preload-ctx slots.
  // Executor (ppc_recomp.14 loc_821BC22C): r24 = r19+32+(r31*4) where r31
  // is the stream index. Probe join entries + preload slot +32+idx*4.
  uint32_t jcount = 0, jentries = 0;
  (void)mem.ReadU32BE(0x8283D1A8u, &jcount);
  (void)mem.ReadU32BE(0x8283D1C4u, &jentries);
  uint32_t slotCand = s_joinSlotAddr.load();
  uint32_t slotWords[4] = {0};
  if (jentries && jcount) {
    for (uint32_t ji = 0; ji < 4 && ji < jcount; ++ji) {
      const uint32_t e = jentries + ji * 28u;
      uint32_t key = 0, obj = 0;
      (void)mem.ReadU32BE(e + 0, &key);
      (void)mem.ReadU32BE(e + 8, &obj);
      // Preload ctx often sits in the join slot family; +32+(idx*4) holds
      // the inflater pointer the executor loads into r24.
      if (obj && obj >= 0x80000000u && obj != 0xCDCDCDCDu) {
        for (uint32_t idx = 0; idx < 4; ++idx) {
          const uint32_t slot = obj + 32u + idx * 4u;
          uint32_t p = 0;
          if (mem.ReadU32BE(slot, &p) && p >= 0x80000000u &&
              p != 0xCDCDCDCDu && p < 0xC0000000u) {
            uint32_t p0 = 0;
            if (mem.ReadU32BE(p, &p0) && p0 != 0 && p0 != 0xCDCDCDCDu) {
              if (slotCand == 0) {
                slotCand = slot;
                s_joinSlotAddr.store(slot);
                if (s_guestInflaterR3.load() == 0)
                  s_guestInflaterR3.store(p);
                if (s_xmemCtx.load() == 0 && p0 != 0)
                  s_xmemCtx.store(p0);
              }
              slotWords[0] = slot;
              slotWords[1] = p;
              slotWords[2] = p0;
            }
          }
        }
      }
    }
  }
  MCLA_LOG_WARN("INFLATE-R3-CENSUS infR3={:08X} words=[{:08X} {:08X} "
                "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}] "
                "xmemCtx={:08X} joinSlot={:08X} slot=[{:08X} {:08X} {:08X}] "
                "jentries={:08X}",
                infR3, iw[0], iw[1], iw[2], iw[3], iw[4], iw[5], iw[6],
                iw[7], s_xmemCtx.load(), slotCand, slotWords[0], slotWords[1],
                slotWords[2], jentries);
}

// w26: census swfC +24 list nodes for real 8208xxxx pointers. Lead:
// B79B0C20 list holds dest-range ptrs (B79BE0F0 B7B6CC00 ...). Bind only
// pointers that already carry a real swfC vtable — never invent one.
static int MclaCensusPlus24List(auto &mem, uint32_t obj,
                                uint32_t *outPtrs, uint32_t *outVts,
                                int maxOut) {
  uint32_t bases[4] = {0, 0xB79B0C20u, 0, 0};
  if (obj && obj != 0xCDCDCDCDu)
    (void)mem.ReadU32BE(obj + 24, &bases[0]);
  int n = 0;
  uint32_t seen[16] = {0};
  for (int bi = 0; bi < 4; ++bi) {
    const uint32_t base = bases[bi];
    if (!base || base < 0x80000000u || base >= 0xC0000000u ||
        base == 0xCDCDCDCDu)
      continue;
    uint32_t w[16] = {0};
    for (int i = 0; i < 16; ++i)
      (void)mem.ReadU32BE(base + static_cast<uint32_t>(i * 4), &w[i]);
    MCLA_LOG_WARN("W26-PLUS24 base={:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}",
                  base, w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8],
                  w[9], w[10], w[11], w[12], w[13], w[14], w[15]);
    for (int i = 0; i < 16 && n < maxOut; ++i) {
      const uint32_t a = w[i];
      uint32_t objC = 0, vt = 0;
      if ((a & 0xFFFF0000u) == 0x82080000u) {
        objC = base + static_cast<uint32_t>(i * 4);
        vt = a;
      } else if (a >= 0x80000000u && a < 0xC0000000u && a != 0xCDCDCDCDu &&
                 a != 0xFFFFFFFFu && mem.ReadU32BE(a, &vt) &&
                 (vt & 0xFFFF0000u) == 0x82080000u) {
        objC = a;
      } else {
        // Classify dest-range ptrs (lead: B79BE0F0 / B7B6CC00).
        const bool destRange =
            a >= 0xB7000000u && a < 0xB8000000u && a != 0xCDCDCDCDu;
        if (destRange && (i < 8)) {
          uint32_t dw[4] = {0};
          for (int k = 0; k < 4; ++k)
            (void)mem.ReadU32BE(a + static_cast<uint32_t>(k * 4), &dw[k]);
          MCLA_LOG_WARN("W26-PLUS24-DEST base={:08X}[{}]={:08X} "
                        "[{:08X} {:08X} {:08X} {:08X}]",
                        base, i, a, dw[0], dw[1], dw[2], dw[3]);
        }
        continue;
      }
      bool dup = false;
      for (int j = 0; j < n; ++j)
        if (seen[j] == objC)
          dup = true;
      if (dup)
        continue;
      seen[n] = objC;
      if (outPtrs)
        outPtrs[n] = objC;
      if (outVts)
        outVts[n] = vt;
      MCLA_LOG_WARN("W26-PLUS24-SWFC #{} obj={:08X} vt={:08X} base={:08X}+{}",
                    n, objC, vt, base, i);
      ++n;
    }
  }
  return n;
}

// w29: file-scope resource-image head check (also used by spin-census).
static bool MclaHeadIsResourceImage(uint32_t h) {
  return (h & 0xFFFFFF00u) == 0x44365500u ||
         (h & 0xFFFFFF00u) == 0x44495500u || (h & 0xFFFFu) == 0x5500u ||
         h == 0x00019249u;
}

// w30 ONE LEVER: never host FEX / J2-DIST over a dest the guest already owns.
// Guest-owned = place-pass wrote a real swfC vtable (8208xxxx) OR guest inflate
// left a resource-image head (44495500 / 5500 / 44365500 / 00019249).
static bool MclaHeadIsPlaceVt(uint32_t h) {
  return (h & 0xFFFF0000u) == 0x82080000u; // 8208521C / 82085364 family
}
static bool MclaDestGuestOwned(auto &mem, uint32_t dest) {
  if (!dest || dest == 0xCDCDCDCDu || dest == 0xFFFFFFFFu)
    return false;
  uint32_t h = 0;
  if (!mem.ReadU32BE(dest, &h))
    return false;
  return MclaHeadIsPlaceVt(h) || MclaHeadIsResourceImage(h);
}

// w30: after guest fill+place, bind ONLY already-written real 8208xxxx
// children from rebased PSTREAM / known leads into the place object's arr.
// Never invent a vtable. Never plant tags (00B60006) as pointers.
// Call only when dest[0] is place vt 8208xxxx.
static int MclaW30BindPstreamChildren(auto &mem, uint32_t obj,
                                      uint32_t stack) {
  if (!obj || obj == 0xCDCDCDCDu)
    return 0;
  uint32_t vt = 0, arr = 0;
  uint16_t cnt = 0;
  (void)mem.ReadU32BE(obj + 0, &vt);
  (void)mem.ReadU32BE(obj + 12, &arr);
  (void)mem.ReadU16BE(obj + 16, &cnt);
  const bool placeVt = MclaHeadIsPlaceVt(vt);
  const bool rscHead = MclaHeadIsResourceImage(vt);

  // Dest-head census (report required by w30 goal).
  constexpr uint32_t kHeads[] = {
      0xB7B41000u, 0xB7981000u, 0xB79A1000u, 0xB7B61000u,
      0xB7B71000u, 0xB79C1000u, 0xB79E1000u,
  };
  for (uint32_t d : kHeads) {
    uint32_t h[4] = {0};
    for (int k = 0; k < 4; ++k)
      (void)mem.ReadU32BE(d + static_cast<uint32_t>(k * 4), &h[k]);
    MCLA_LOG_WARN("W30-DESTHEAD @{:08X} [{:08X} {:08X} {:08X} {:08X}]", d,
                  h[0], h[1], h[2], h[3]);
  }

  uint32_t kids[16] = {0}, kvts[16] = {0};
  int n = 0;
  uint32_t seen[16] = {0};
  auto consider = [&](uint32_t ptr) {
    if (n >= 16)
      return;
    if (ptr < 0x80000000u || ptr >= 0xC0000000u || ptr == 0xCDCDCDCDu ||
        ptr == 0xFFFFFFFFu)
      return;
    uint32_t cvt = 0;
    if (!mem.ReadU32BE(ptr, &cvt))
      return;
    if (!MclaHeadIsPlaceVt(cvt))
      return;
    for (int i = 0; i < n; ++i)
      if (seen[i] == ptr)
        return;
    seen[n] = ptr;
    kids[n] = ptr;
    kvts[n] = cvt;
    ++n;
  };

  // Known leads + PSTREAM job2 dests + w29 kid candidates (B7984DE0 / B79B0C20).
  static const uint32_t kLead[] = {
      0xB7984DE0u, 0xB79B0C20u, 0xB79BE0F0u, 0xB7B6CC00u,
      0xB7988D10u, 0xB7B6BF60u, 0xB7B6C6E0u, 0xB7B67C60u, 0xB7B6C8C0u,
      0xB7981000u, 0xB79A1000u, 0xB79B1000u, 0xB7B61000u,
      0xB7B71000u, 0xB79C1000u, 0xB79E1000u, 0xB7B6D9B4u,
  };
  for (uint32_t base : kLead) {
    if (n >= 16)
      break;
    const uint32_t page = base & 0xFFFFF000u;
    const uint32_t span =
        (page >= 0xB7000000u && page < 0xB8000000u && (base & 0xFFFu) == 0)
            ? 0x800u
            : 0x100u;
    for (uint32_t off = 0; off + 4 <= span && n < 16; off += 4) {
      uint32_t a = 0;
      if (!mem.ReadU32BE(base + off, &a))
        break;
      if (MclaHeadIsPlaceVt(a))
        consider(base + off); // object head resident here
      else
        consider(a); // pointer to already-written object
    }
  }
  // PSTREAM rebased pbases: dest-resident 8208xxxx heads after guest place.
  for (int i = 0; i < g_mclaRebaseCount && i < kMclaRebaseMax && n < 16; ++i) {
    const uint32_t pb = g_mclaRebaseMap[i].pbase;
    const uint32_t sz = g_mclaRebaseMap[i].size;
    if (pb < 0xB7000000u || pb >= 0xB8000000u || sz < 4)
      continue;
    const uint32_t span = sz < 0x800u ? sz : 0x800u;
    for (uint32_t off = 0; off + 4 <= span && n < 16; off += 4) {
      uint32_t a = 0;
      if (!mem.ReadU32BE(pb + off, &a))
        break;
      if (MclaHeadIsPlaceVt(a))
        consider(pb + off);
    }
  }

  uint32_t a0 = 0, a0vt = 0;
  if (arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
    (void)mem.ReadU32BE(arr, &a0);
  if (a0 >= 0x80000000u && a0 < 0xC0000000u && a0 != 0xCDCDCDCDu &&
      a0 != 0xFFFFFFFFu)
    (void)mem.ReadU32BE(a0, &a0vt);
  const bool a0IsChild = MclaHeadIsPlaceVt(a0vt);
  // w29 proven: arr tag 00B60006 is NOT a pointer.
  const bool a0IsTag = (a0 != 0 && a0 < 0x10000u);

  MCLA_LOG_WARN("W30-ARR obj={:08X} vt={:08X} arr={:08X} [arr]={:08X} "
                "a0vt={:08X} cnt={} nReal={} a0IsChild={} a0IsTag={} "
                "placeVt={} rscHead={}",
                obj, vt, arr, a0, a0vt, cnt, n, a0IsChild ? 1 : 0,
                a0IsTag ? 1 : 0, placeVt ? 1 : 0, rscHead ? 1 : 0);

  if (!placeVt) {
    MCLA_LOG_WARN("W30-ARR-SKIP obj={:08X} vt={:08X} — not place 8208xxxx; "
                  "no ARR-FIX (guest place must run first)",
                  obj, vt);
    return 0;
  }
  if (n == 0) {
    MCLA_LOG_WARN("W30-ARR-NOKIDS obj={:08X} — no already-written 8208xxxx "
                  "children in PSTREAM/leads; leave arr untouched",
                  obj);
    return 0;
  }

  uint32_t arrSlot = arr;
  if (arrSlot == 0 || arrSlot == 0xCDCDCDCDu || arrSlot == 0xFFFFFFFFu ||
      a0IsTag) {
    // Known physical arr from w9 RSC-REBASE: 5006C9B4 → B7B6D9B4.
    arrSlot = 0xB7B6D9B4u;
  }
  if (arrSlot < 0x80000000u || arrSlot >= 0xC0000000u) {
    MCLA_LOG_WARN("W30-ARR-SKIP arrSlot={:08X} not guest phys", arrSlot);
    return 0;
  }

  bool need = !a0IsChild || a0IsTag || arr != arrSlot ||
              cnt != static_cast<uint16_t>(n);
  if (a0IsChild) {
    bool has = false;
    for (int i = 0; i < n; ++i)
      if (kids[i] == a0)
        has = true;
    if (!has)
      need = true;
  }
  if (!need) {
    MCLA_LOG_WARN("W30-ARR-OK obj={:08X} arr={:08X} n={} — already bound",
                  obj, arr, n);
    return n;
  }

  const int nb = n > 8 ? 8 : n;
  for (int i = 0; i < nb; ++i)
    (void)mem.WriteU32BE(arrSlot + static_cast<uint32_t>(i * 4), kids[i]);
  if (arr != arrSlot)
    (void)mem.WriteU32BE(obj + 12, arrSlot);
  (void)mem.WriteU16BE(obj + 16, static_cast<uint16_t>(nb));
  MCLA_LOG_WARN("W30-ARR-FIX obj={:08X} arr={:08X}->{:08X} n={} cnt {}->{} "
                "arr[0]={:08X} vt0={:08X} (already-written PSTREAM kids only)",
                obj, arr, arrSlot, nb, cnt, nb, kids[0], kvts[0]);

  if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
    static uint32_t s_w30Ctx = 0;
    if (s_w30Ctx == 0)
      s_w30Ctx = mem.Alloc(64, 16);
    if (s_w30Ctx) {
      MclaCompleteRscRebaseBeforePlace(obj);
      MclaArmRebaseCtx(s_w30Ctx);
      PPCContext p{};
      p.r1.u64 = stack ? stack : 0x006D8EC0u;
      p.r13.u64 = 0x8F200000u;
      p.r3.u64 = obj;
      p.r4.u64 = s_w30Ctx;
      // F-117: this call is host-fabricated execution. It builds a synthetic
      // PPCContext (r1 = 0x006D8EC0 from a 15-day-old run, r13 = 0x8F200000) and
      // drives the guest's own place/fixup walker over obj+12 -- a field the
      // block above just wrote. w103 line-for-line: ARR-FIX(6204) -> PLACE(6328)
      // -> walker on our synthetic r13 (P5-MISSFIX/P9-B588) -> the boot's only
      // remaining fatal, 'swfCMD::Fixup - unknown type %d' (14613), on
      // node=B7B6D9B4 type=B7 with r13=8F200000 -- our own value, and
      // type == the top byte of the B7 pointer WE stored at arrSlot+4. The
      // guest never sees obj+12 != 0 without the write above, so this fatal is
      // an artifact of the re-dispatch, not of the boot (rule 1 / the same
      // reason the VEH RIP-advance recovery was removed). ARR-FIX's writes stay
      // so the memory hypothesis remains testable without this execution.
      constexpr bool kW30SyntheticPlaceRedispatch = false;
      MCLA_LOG_WARN(
          "W30-PLACE obj={:08X} arr={:08X} n={} — re-dispatch 825EF100 after "
          "ARR-FIX {}",
          obj, arrSlot, nb,
          kW30SyntheticPlaceRedispatch ? "RUN" : "SKIPPED");
      if (kW30SyntheticPlaceRedispatch) {
        place(p, mcla::kernel::g_memory.base);
        uint32_t vt2 = 0, arr2 = 0, a2 = 0;
        uint16_t cnt2 = 0;
        (void)mem.ReadU32BE(obj + 0, &vt2);
        (void)mem.ReadU32BE(obj + 12, &arr2);
        (void)mem.ReadU16BE(obj + 16, &cnt2);
        if (arr2 && arr2 != 0xCDCDCDCDu && arr2 != 0xFFFFFFFFu)
          (void)mem.ReadU32BE(arr2, &a2);
        MCLA_LOG_WARN("W30-PLACE-DONE vt={:08X} arr={:08X} [arr]={:08X} cnt={}",
                      vt2, arr2, a2, cnt2);
      }
    }
  }
  return nb;
}

// w31: deep child census. Scan job2 dest pages + rebased pbases + known
// leads with a wide span for any already-written 8208xxxx swfC heads.
// Never invent a vtable — only report objects already in guest memory.
// Also dumps B7984DE0 / B79B0C20 list nodes / B79E1000 for the w31 report.
static int MclaW31DeepChildCensus(auto &mem, uint32_t *outPtrs,
                                   uint32_t *outVts, int maxOut) {
  static const uint32_t kDest[] = {
      0xB7B41000u, 0xB7981000u, 0xB79A1000u, 0xB79B1000u, 0xB7B61000u,
      0xB7B69000u, 0xB7B71000u, 0xB79C1000u, 0xB79C7000u, 0xB79E1000u,
      0xB7001000u, 0xB7021000u, 0xB7041000u, 0xB7061000u, 0xB7081000u,
      0xB70A1000u, 0xB70C1000u, 0xB70E1000u, 0xB7101000u,
  };
  static const uint32_t kLead[] = {
      0xB7984DE0u, 0xB79B0C20u, 0xB79BE0F0u, 0xB7B6CC00u,
      0xB7988D10u, 0xB7B6BF60u, 0xB7B6C6E0u, 0xB7B67C60u, 0xB7B6C8C0u,
      0xB798EB70u, 0xB7B6D9B4u,
  };
  int n = 0;
  uint32_t seen[16] = {0};
  auto consider = [&](uint32_t addr, uint32_t vt, const char *src) {
    if (n >= maxOut)
      return;
    if ((vt & 0xFFFF0000u) != 0x82080000u)
      return;
    for (int i = 0; i < n; ++i)
      if (seen[i] == addr)
        return;
    seen[n] = addr;
    if (outPtrs)
      outPtrs[n] = addr;
    if (outVts)
      outVts[n] = vt;
    uint32_t w[6] = {0};
    for (int k = 0; k < 6; ++k)
      (void)mem.ReadU32BE(addr + static_cast<uint32_t>(k * 4), &w[k]);
    MCLA_LOG_WARN("W31-CHILD-VT #{} obj={:08X} vt={:08X} src={} "
                  "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                  n, addr, vt, src, w[0], w[1], w[2], w[3], w[4], w[5]);
    ++n;
  };
  // Wide scan of dest pages (0x2000 covers mid-page children).
  for (uint32_t base : kDest) {
    if (n >= maxOut)
      break;
    const uint32_t span = 0x2000u;
    for (uint32_t off = 0; off + 4 <= span && n < maxOut; off += 4) {
      uint32_t a = 0;
      if (!mem.ReadU32BE(base + off, &a))
        break;
      if ((a & 0xFFFF0000u) == 0x82080000u)
        consider(base + off, a, "dest-head");
      else if (a >= 0x80000000u && a < 0xC0000000u && a != 0xCDCDCDCDu &&
               a != 0xFFFFFFFFu) {
        uint32_t cvt = 0;
        if (mem.ReadU32BE(a, &cvt) && (cvt & 0xFFFF0000u) == 0x82080000u)
          consider(a, cvt, "dest-ptr");
      }
    }
  }
  // Leads + list nodes.
  for (uint32_t base : kLead) {
    if (n >= maxOut)
      break;
    const uint32_t span = 0x200u;
    for (uint32_t off = 0; off + 4 <= span && n < maxOut; off += 4) {
      uint32_t a = 0;
      if (!mem.ReadU32BE(base + off, &a))
        break;
      if ((a & 0xFFFF0000u) == 0x82080000u)
        consider(base + off, a, "lead-head");
      else if (a >= 0x80000000u && a < 0xC0000000u && a != 0xCDCDCDCDu &&
               a != 0xFFFFFFFFu) {
        uint32_t cvt = 0;
        if (mem.ReadU32BE(a, &cvt) && (cvt & 0xFFFF0000u) == 0x82080000u)
          consider(a, cvt, "lead-ptr");
      }
    }
  }
  // Rebases pbases (PSTREAM physical dests).
  for (int i = 0; i < g_mclaRebaseCount && i < kMclaRebaseMax && n < maxOut;
       ++i) {
    const uint32_t pb = g_mclaRebaseMap[i].pbase;
    const uint32_t sz = g_mclaRebaseMap[i].size;
    if (pb < 0xB7000000u || pb >= 0xB8000000u || sz < 4)
      continue;
    const uint32_t span = sz < 0x2000u ? sz : 0x2000u;
    for (uint32_t off = 0; off + 4 <= span && n < maxOut; off += 4) {
      uint32_t a = 0;
      if (!mem.ReadU32BE(pb + off, &a))
        break;
      if ((a & 0xFFFF0000u) == 0x82080000u)
        consider(pb + off, a, "rebase-pbase");
    }
  }
  // Structured dumps (always — required by w31 report).
  {
    uint32_t w[16] = {0};
    for (int i = 0; i < 16; ++i)
      (void)mem.ReadU32BE(0xB7984DE0u + static_cast<uint32_t>(i * 4), &w[i]);
    MCLA_LOG_WARN("W31-DUMP B7984DE0 {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X}",
                  w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8], w[9],
                  w[10], w[11], w[12], w[13], w[14], w[15]);
  }
  {
    uint32_t lw[8] = {0};
    for (int i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(0xB79B0C20u + static_cast<uint32_t>(i * 4), &lw[i]);
    MCLA_LOG_WARN("W31-DUMP B79B0C20 {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X}",
                  lw[0], lw[1], lw[2], lw[3], lw[4], lw[5], lw[6], lw[7]);
    for (int i = 0; i < 8; ++i) {
      const uint32_t p = lw[i];
      if (p < 0x80000000u || p >= 0xC0000000u || p == 0xCDCDCDCDu)
        continue;
      uint32_t nw[6] = {0};
      for (int k = 0; k < 6; ++k)
        (void)mem.ReadU32BE(p + static_cast<uint32_t>(k * 4), &nw[k]);
      const bool isSwf = (nw[0] & 0xFFFF0000u) == 0x82080000u;
      MCLA_LOG_WARN("W31-DUMP B79B0C20[{}]={:08X} [{:08X} {:08X} {:08X} "
                    "{:08X} {:08X} {:08X}] swfc={}",
                    i, p, nw[0], nw[1], nw[2], nw[3], nw[4], nw[5],
                    isSwf ? 1 : 0);
      if (isSwf)
        consider(p, nw[0], "p24-node");
    }
  }
  {
    uint32_t ew[8] = {0};
    for (int i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(0xB79E1000u + static_cast<uint32_t>(i * 4), &ew[i]);
    MCLA_LOG_WARN("W31-DUMP B79E1000 {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X}",
                  ew[0], ew[1], ew[2], ew[3], ew[4], ew[5], ew[6], ew[7]);
  }
  {
    uint32_t vt = 0, arr = 0, a0 = 0, p24 = 0;
    uint16_t cnt = 0;
    (void)mem.ReadU32BE(0xB7B41000u + 0, &vt);
    (void)mem.ReadU32BE(0xB7B41000u + 12, &arr);
    (void)mem.ReadU32BE(0xB7B41000u + 24, &p24);
    (void)mem.ReadU16BE(0xB7B41000u + 16, &cnt);
    if (arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
      (void)mem.ReadU32BE(arr, &a0);
    MCLA_LOG_WARN("W31-ROOT vt={:08X} +4= arr={:08X} [arr]={:08X} cnt={} "
                  "+24={:08X} nDeep={}",
                  vt, arr, a0, cnt, p24, n);
  }
  return n;
}

// w31: census + bind already-written 8208xxxx children + re-dispatch place.
// Never invent vtables. Never host FEX. Bind only what guest already wrote.
void MclaW31CensusBindPlace(auto &mem, uint32_t stack) {
  uint32_t kids[16] = {0}, kvts[16] = {0};
  const int nDeep = MclaW31DeepChildCensus(mem, kids, kvts, 16);
  uint32_t vt = 0, arr = 0, a0 = 0;
  uint16_t cnt = 0;
  (void)mem.ReadU32BE(0xB7B41000u + 0, &vt);
  (void)mem.ReadU32BE(0xB7B41000u + 12, &arr);
  (void)mem.ReadU16BE(0xB7B41000u + 16, &cnt);
  if (arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
    (void)mem.ReadU32BE(arr, &a0);
  const bool placeVt = MclaHeadIsPlaceVt(vt);
  // Real children = deep hits that are NOT the root itself.
  int nRealChild = 0;
  uint32_t bindPtrs[8] = {0}, bindVts[8] = {0};
  for (int i = 0; i < nDeep && nRealChild < 8; ++i) {
    if (kids[i] == 0xB7B41000u)
      continue;
    bindPtrs[nRealChild] = kids[i];
    bindVts[nRealChild] = kvts[i];
    ++nRealChild;
  }
  MCLA_LOG_WARN("W31-BIND-CHECK nDeep={} nRealChild={} vt={:08X} "
                "arr={:08X} [arr]={:08X} cnt={} placeVt={}",
                nDeep, nRealChild, vt, arr, a0, cnt, placeVt ? 1 : 0);
  if (!placeVt) {
    MCLA_LOG_WARN("W31-SKIP vt={:08X} — not place 8208xxxx; no ARR-FIX",
                  vt);
    return;
  }
  if (nRealChild == 0) {
    MCLA_LOG_WARN("W31-NOKIDS — no already-written 8208xxxx children in "
                  "dest-range/leads; leave arr untouched");
    // w32: children missing because FDA90 never ran — +24 list may still be
    // live with SWF-tag payload nodes. Open the walk bound + re-dispatch guest
    // construct. Never invent vtables. Never host FEX.
    if (placeVt)
      (void)MclaW32OpenConstructWalk(0xB7B41000u, stack, /*redispatch=*/true);
    return;
  }
  // Check whether real children are already bound in arr.
  bool already = (cnt == static_cast<uint16_t>(nRealChild + 1));
  if (already && arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu) {
    uint32_t aw = 0;
    (void)mem.ReadU32BE(arr + 4, &aw); // arr[1] should be first real child
    if (aw != bindPtrs[0])
      already = false;
  }
  if (already) {
    MCLA_LOG_WARN("W31-ARR-OK arr={:08X} nRealChild={} — already bound", arr,
                  nRealChild);
    return;
  }
  uint32_t arrSlot = arr;
  if (arrSlot == 0 || arrSlot == 0xCDCDCDCDu || arrSlot == 0xFFFFFFFFu ||
      arrSlot < 0x80000000u || arrSlot >= 0xC0000000u)
    arrSlot = 0xB7B6D9B4u;
  int nb = 0;
  // Keep root at [0] (walker expects the place object).
  (void)mem.WriteU32BE(arrSlot + 0, 0xB7B41000u);
  ++nb;
  for (int i = 0; i < nRealChild && nb < 8; ++i) {
    (void)mem.WriteU32BE(arrSlot + static_cast<uint32_t>(nb * 4), bindPtrs[i]);
    ++nb;
  }
  if (arr != arrSlot)
    (void)mem.WriteU32BE(0xB7B41000u + 12, arrSlot);
  (void)mem.WriteU16BE(0xB7B41000u + 16, static_cast<uint16_t>(nb));
  MCLA_LOG_WARN("W31-ARR-FIX arr={:08X}->{:08X} n={} cnt {}->{} "
                "arr[0]=B7B41000 firstChild={:08X} vt={:08X} "
                "(already-written dest-range kids only)",
                arr, arrSlot, nb, cnt, nb, bindPtrs[0], bindVts[0]);
  if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
    static uint32_t s_w31Ctx = 0;
    if (s_w31Ctx == 0)
      s_w31Ctx = mem.Alloc(64, 16);
    if (s_w31Ctx) {
      MclaCompleteRscRebaseBeforePlace(0xB7B41000u);
      MclaArmRebaseCtx(s_w31Ctx);
      PPCContext p{};
      p.r1.u64 = stack ? stack : 0x006D8EC0u;
      p.r13.u64 = 0x8F200000u;
      p.r3.u64 = 0xB7B41000u;
      p.r4.u64 = s_w31Ctx;
      MCLA_LOG_WARN("W31-PLACE re-dispatch 825EF100 n={}", nb);
      place(p, mcla::kernel::g_memory.base);
      uint32_t vt2 = 0, arr2 = 0, a2 = 0;
      uint16_t cnt2 = 0;
      (void)mem.ReadU32BE(0xB7B41000u + 0, &vt2);
      (void)mem.ReadU32BE(0xB7B41000u + 12, &arr2);
      (void)mem.ReadU16BE(0xB7B41000u + 16, &cnt2);
      if (arr2 && arr2 != 0xCDCDCDCDu && arr2 != 0xFFFFFFFFu)
        (void)mem.ReadU32BE(arr2, &a2);
      MCLA_LOG_WARN("W31-PLACE-DONE vt={:08X} arr={:08X} [arr]={:08X} cnt={}",
                    vt2, arr2, a2, cnt2);
      uint32_t kids2[16] = {0}, kvts2[16] = {0};
      const int n2 = MclaW31DeepChildCensus(mem, kids2, kvts2, 16);
      MCLA_LOG_WARN("W31-POSTPLACE nDeep={}", n2);
    }
  }
}

// w31: periodic census hook (called from NATIVE-PRESENT).
void MclaW31OnPresent() {
  static std::atomic<uint32_t> s_n{0};
  const uint32_t n = s_n.fetch_add(1) + 1;
  if (n > 6 && (n % 30) != 0)
    return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  MCLA_LOG_WARN("W31-PRESENT-CENSUS #{}", n);
  MclaW31CensusBindPlace(mem, 0);
  // w32: after fill the +24 construct list can be live while +50 stays gated.
  (void)MclaW32OpenConstructWalk(0xB7B41000u, 0, /*redispatch=*/true);
}

// ---------------------------------------------------------------------------
// w32: census-proven construct gate.
// Guest place-pass 825EF100 (ppc_recomp.120.cpp) does:
//   FDBF8 build; write vt 82085364; rebase [obj+24];
//   lhz r11,[obj+50]; if (r11 <= 1) skip walk;
//   else for (i=1; i<+50; ++i) rebase +24[i]; FDA90(group, +24[i]).
// Host CNT-GATE (w24) forced +50=1 whenever [+24][0] looked junk — that
// starved FDA90 even after job2 fill wrote real dest-range pointers at
// +24[1..] (B79B0C20 → B79BE0F0/B7B6BF60/B7B6C8C0 …) with SWF-tag-like
// words (00C10037/00CB0037). FDA90 count stayed 0; only root vt written.
// Lever: open +50 to the real pointer count ONLY when the +24 list holds
// construct candidates. Never invent tags/vtables. Never host FEX on dests.
// ---------------------------------------------------------------------------
bool MclaW32OpenConstructWalk(uint32_t obj, uint32_t stack, bool redispatch) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!obj || obj == 0xCDCDCDCDu)
    return false;
  uint32_t vt = 0, p24 = 0, arr = 0;
  uint16_t cnt50 = 0;
  (void)mem.ReadU32BE(obj + 0, &vt);
  (void)mem.ReadU32BE(obj + 24, &p24);
  (void)mem.ReadU32BE(obj + 12, &arr);
  (void)mem.ReadU16BE(obj + 50, &cnt50);

  auto isGuestPtr = [](uint32_t p) -> bool {
    if (p == 0 || p == 0xCDCDCDCDu || p == 0xFFFFFFFFu)
      return false;
    return p >= 0x80000000u && p < 0xC0000000u && (p & 0xFFFF0000u) != 0xCDCD0000u;
  };
  auto isDestRange = [](uint32_t p) -> bool {
    return p >= 0xB7000000u && p < 0xB8000000u;
  };

  uint32_t ptrs[16] = {0};
  uint8_t tags[16] = {0};
  uint32_t w0s[16] = {0};
  int nPtr = 0, nValidTag = 0, nSwfLike = 0, nDest = 0;

  if (p24 && isGuestPtr(p24)) {
    for (int i = 0; i < 16; ++i) {
      uint32_t p = 0;
      if (!mem.ReadU32BE(p24 + static_cast<uint32_t>(i * 4), &p))
        break;
      if (!isGuestPtr(p))
        continue;
      uint32_t w0 = 0, w1 = 0, w2 = 0;
      uint8_t tag = 0;
      if (!mem.ReadU32BE(p, &w0))
        continue;
      (void)mem.ReadU32BE(p + 4, &w1);
      (void)mem.ReadU32BE(p + 8, &w2);
      (void)mem.ReadU8(p + 8, &tag);
      const bool dest = isDestRange(p);
      // SWF-tag-like: 00xx00yy packed halfwords (w31 observed 00C10037).
      const bool swfLike =
          (w0 & 0xFF000000u) == 0 && (w1 & 0xFF000000u) == 0 && (w0 != 0 || w1 != 0);
      const bool validTag = (tag >= 1u && tag <= 9u);
      if (!dest && !validTag && !swfLike)
        continue;
      if (nPtr < 16) {
        ptrs[nPtr] = p;
        tags[nPtr] = tag;
        w0s[nPtr] = w0;
      }
      if (validTag)
        ++nValidTag;
      if (swfLike)
        ++nSwfLike;
      if (dest)
        ++nDest;
      ++nPtr;
    }
  }

  static std::atomic<uint32_t> s_n{0};
  const uint32_t n = s_n.fetch_add(1) + 1;
  if (n <= 32 || (n % 20) == 0) {
    MCLA_LOG_WARN("W32-CONSTRUCT-CENSUS #{} obj={:08X} vt={:08X} +24={:08X} "
                  "+50={} arr={:08X} nPtr={} nValidTag={} nSwfLike={} nDest={} "
                  "p1={:08X}/t{:02X} p2={:08X}/t{:02X} p3={:08X}/t{:02X} "
                  "p4={:08X}/t{:02X}",
                  n, obj, vt, p24, cnt50, arr, nPtr, nValidTag, nSwfLike, nDest,
                  ptrs[1], tags[1], ptrs[2], tags[2], ptrs[3], tags[3], ptrs[4],
                  tags[4]);
  }

  const bool walkStarved = (cnt50 <= 1);
  const bool junkBound = (cnt50 > 32);
  if (nPtr >= 1 && (walkStarved || junkBound) && isGuestPtr(p24)) {
    // Guest walk: r25 starts 1, r29 starts +4 → skips +24[0], walks [1..+50).
    int nFrom1 = 0;
    for (int i = 1; i < 16; ++i) {
      uint32_t p = 0;
      if (!mem.ReadU32BE(p24 + static_cast<uint32_t>(i * 4), &p))
        break;
      if (!isGuestPtr(p))
        continue;
      uint32_t w0 = 0, w1 = 0;
      uint8_t tag = 0;
      (void)mem.ReadU32BE(p, &w0);
      (void)mem.ReadU32BE(p + 4, &w1);
      (void)mem.ReadU8(p + 8, &tag);
      const bool dest = isDestRange(p);
      const bool swfLike =
          (w0 & 0xFF000000u) == 0 && (w1 & 0xFF000000u) == 0 && (w0 != 0 || w1 != 0);
      const bool validTag = (tag >= 1u && tag <= 9u);
      if (!dest && !validTag && !swfLike)
        continue;
      ++nFrom1;
    }
    uint16_t open = static_cast<uint16_t>(nFrom1 + 1);
    if (open < 2 && nPtr >= 1)
      open = static_cast<uint16_t>((nPtr > 8 ? 8 : nPtr) + 1);
    if (open > 9)
      open = 9; // FDA90 tags 1..9; keep walk tight
    if (open > cnt50) {
      (void)mem.WriteU16BE(obj + 50, open);
      MCLA_LOG_WARN("W32-OPEN-CONSTRUCT #{} obj={:08X} +24={:08X} +50 {} -> {} "
                    "nPtr={} nFrom1={} nValidTag={} nSwfLike={} nDest={} "
                    "(FDA90 walk bound; no tag/vtable invent)",
                    n, obj, p24, cnt50, open, nPtr, nFrom1, nValidTag, nSwfLike,
                    nDest);
    }
  }

  if (redispatch && nPtr >= 1) {
    if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
      static uint32_t s_ctx = 0;
      if (s_ctx == 0)
        s_ctx = mem.Alloc(64, 16);
      if (s_ctx) {
        MclaCompleteRscRebaseBeforePlace(obj);
        MclaArmRebaseCtx(s_ctx);
        PPCContext p{};
        p.r1.u64 = stack ? stack : 0x006D8EC0u;
        p.r13.u64 = 0x8F200000u;
        p.r3.u64 = obj;
        p.r4.u64 = s_ctx;
        uint16_t cnt50b = 0;
        (void)mem.ReadU16BE(obj + 50, &cnt50b);
        MCLA_LOG_WARN("W32-PLACE-REDISPATCH obj={:08X} +24={:08X} +50={} nPtr={}",
                      obj, p24, cnt50b, nPtr);
        place(p, mcla::kernel::g_memory.base);
        uint32_t vt2 = 0, arr2 = 0, a2 = 0, p24b = 0;
        uint16_t cnt2 = 0;
        (void)mem.ReadU32BE(obj + 0, &vt2);
        (void)mem.ReadU32BE(obj + 12, &arr2);
        (void)mem.ReadU16BE(obj + 16, &cnt2);
        (void)mem.ReadU32BE(obj + 24, &p24b);
        if (arr2 && isGuestPtr(arr2))
          (void)mem.ReadU32BE(arr2, &a2);
        uint16_t cnt50c = 0;
        (void)mem.ReadU16BE(obj + 50, &cnt50c);
        // Post-construct: any NEW 8208xxxx children at +24[i]?
        int nChildVt = 0;
        if (p24b && isGuestPtr(p24b)) {
          for (int i = 1; i < 9; ++i) {
            uint32_t pn = 0, cvt = 0;
            if (!mem.ReadU32BE(p24b + static_cast<uint32_t>(i * 4), &pn))
              break;
            if (!isGuestPtr(pn) || pn == obj)
              continue;
            if (mem.ReadU32BE(pn, &cvt) && (cvt & 0xFFFF0000u) == 0x82080000u)
              ++nChildVt;
          }
        }
        MCLA_LOG_WARN("W32-PLACE-DONE obj={:08X} vt={:08X} arr={:08X} "
                      "[arr]={:08X} cnt={} +24={:08X} +50={} nChildVt={}",
                      obj, vt2, arr2, a2, cnt2, p24b, cnt50c, nChildVt);
      }
    }
  }
  return nPtr >= 1;
}

// ---------------------------------------------------------------------------
// w33: dest tag-table census + one faithful guest construct attempt.
// Census (IDA/raw): factories 82275D88/82275DA8/82299C20 write node+8 tags
// (stride 12). Construct walker 825EF248 bl 8260B740 per live +8. Neither is
// on the EF100 place path (FDA90 sole bl=825EF1F8). Place walks +24 dest
// pointers that still hold raw SWF/poison — nValidTag=0, FDA90 UNKNOWN-TYPE.
// Host-missing gate: guest construct opcode never dispatched after inflate.
// Fix: scan job2 dests for a guest-built stride-12 tag table (+8 in 1..9).
// If found, bind +24 to those records and re-dispatch EF100 (guest place
// writes 8208xxxx via FDA90 type handlers). Never invent tags/vtables.
// Never host FEX over dests. If no tag table → W33-PARSE-MISSING.
// ---------------------------------------------------------------------------
bool MclaW33ScanTagTableAndConstruct(uint32_t obj, uint32_t stack) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!obj || obj == 0xCDCDCDCDu)
    return false;
  static std::atomic<uint32_t> s_n{0};
  const uint32_t n = s_n.fetch_add(1) + 1;
  if (n > 12)
    return false;

  auto isGuestPtr = [](uint32_t p) -> bool {
    return p >= 0x80000000u && p < 0xC0000000u && p != 0xCDCDCDCDu &&
           (p & 0xFFFF0000u) != 0xCDCD0000u;
  };

  uint32_t p24 = 0;
  (void)mem.ReadU32BE(obj + 24, &p24);

  // Census current +24 walk list.
  uint32_t ptrs[16] = {0};
  uint8_t tags[16] = {0};
  int nPtr = 0, nValidTag = 0, nSwf = 0;
  if (p24 && isGuestPtr(p24)) {
    for (int i = 0; i < 16; ++i) {
      uint32_t p = 0;
      if (!mem.ReadU32BE(p24 + static_cast<uint32_t>(i * 4), &p))
        break;
      if (!isGuestPtr(p))
        continue;
      uint32_t w0 = 0;
      uint8_t tag = 0;
      if (!mem.ReadU32BE(p, &w0))
        continue;
      (void)mem.ReadU8(p + 8, &tag);
      if (nPtr < 16) {
        ptrs[nPtr] = p;
        tags[nPtr] = tag;
      }
      if (tag >= 1u && tag <= 9u)
        ++nValidTag;
      if ((w0 & 0xFF000000u) == 0 && w0 != 0)
        ++nSwf;
      ++nPtr;
    }
  }

  // Scan job2 dest-range for a dense stride-12 tag table (guest-built).
  struct Hit {
    uint32_t base;
    int nValid;
    uint8_t t0, t1, t2, t3;
  };
  Hit hits[8];
  int nHit = 0;
  static const uint32_t kDests[] = {
      0xB7B41000u, 0xB7981000u, 0xB79A1000u, 0xB7B61000u,
      0xB7B71000u, 0xB79C1000u, 0xB79E1000u, 0xB7B01000u,
      0xB7901000u, 0xB7801000u,
  };
  for (uint32_t d : kDests) {
    // Probe several alignments inside the dest (tag table may sit at +0 or
    // deeper in an RSC body). Stride 12, look for >=2 consecutive valid tags.
    for (uint32_t off = 0; off < 0x200u; off += 4) {
      const uint32_t b = d + off;
      uint8_t t[8] = {0};
      int nv = 0;
      bool ok = true;
      for (int i = 0; i < 8; ++i) {
        if (!mem.ReadU8(b + static_cast<uint32_t>(i * 12) + 8, &t[i])) {
          ok = false;
          break;
        }
        if (t[i] >= 1u && t[i] <= 9u)
          ++nv;
      }
      if (!ok)
        continue;
      // Dense valid tags in 1..9 across the window.
      if (nv >= 2) {
        if (nHit < 8)
          hits[nHit++] = {b, nv, t[0], t[1], t[2], t[3]};
        break; // one hit per dest
      }
    }
  }

  MCLA_LOG_WARN("W33-TAGCENSUS #{} obj={:08X} +24={:08X} nPtr={} nValidTag={} "
                "nSwfLike={} nTagTables={} "
                "p1={:08X}/t{:02X} p2={:08X}/t{:02X} p3={:08X}/t{:02X} "
                "p4={:08X}/t{:02X}",
                n, obj, p24, nPtr, nValidTag, nSwf, nHit,
                ptrs[1], tags[1], ptrs[2], tags[2], ptrs[3], tags[3], ptrs[4],
                tags[4]);
  for (int i = 0; i < nHit; ++i)
    MCLA_LOG_WARN("W33-TAGTABLE #{} base={:08X} nValid={} t=[{:02X} {:02X} "
                  "{:02X} {:02X}]",
                  n, hits[i].base, hits[i].nValid, hits[i].t0, hits[i].t1,
                  hits[i].t2, hits[i].t3);

  if (nValidTag > 0) {
    MCLA_LOG_WARN("W33-TAGS-LIVE #{} nValidTag={} — place/FDA90 can construct "
                  "without host bind",
                  n, nValidTag);
    return true;
  }

  if (nHit == 0) {
    MCLA_LOG_WARN("W33-PARSE-MISSING #{} obj={:08X} nPtr={} nSwfLike={} — "
                  "factories 82275D88/82275DA8/82299C20 never wrote node+8; "
                  "construct opcode 825EF248 not on place path. "
                  "No tag invent. Re-dispatch EF100 for place-vt census only.",
                  n, obj, nPtr, nSwf);
    // Keep place alive for vtable/census; FDA90 will gate unknown types.
    if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
      static uint32_t s_ctx = 0;
      if (s_ctx == 0)
        s_ctx = mem.Alloc(64, 16);
      if (s_ctx) {
        MclaCompleteRscRebaseBeforePlace(obj);
        // Open +50 (keep w32 lever) so FDA90 still walks for census.
        (void)MclaW32OpenConstructWalk(obj, 0, /*redispatch=*/false);
        static uint32_t s_arm = 0;
        if (auto *arm = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
          (void)arm;
        }
        // Arm rebase ctx the same way W32 does.
        {
          uint32_t dummy = 0;
          (void)dummy;
        }
        // Reuse W32 open + place via the existing redispatch path.
        (void)MclaW32OpenConstructWalk(obj, stack, /*redispatch=*/true);
        (void)s_ctx;
      }
    }
    return false;
  }

  // Faithful bind: point +24[1..] at guest-built tag-table records (stride 12),
  // open +50, re-dispatch guest place. Records already carry node+8 tags from
  // the guest image — we do not write tags or vtables.
  if (!p24 || !isGuestPtr(p24))
    return false;
  const uint32_t tb = hits[0].base;
  int bound = 0;
  for (int i = 1; i < 9; ++i) {
    const uint32_t slot = tb + static_cast<uint32_t>((i - 1) * 12);
    uint8_t t = 0;
    if (!mem.ReadU8(slot + 8, &t))
      break;
    if (t < 1u || t > 9u)
      continue;
    (void)mem.WriteU32BE(p24 + static_cast<uint32_t>(i * 4), slot);
    ++bound;
  }
  if (bound == 0)
    return false;
  (void)mem.WriteU16BE(obj + 50, static_cast<uint16_t>(bound + 1));
  MCLA_LOG_WARN("W33-BIND-TAGTABLE #{} obj={:08X} table={:08X} bound={} "
                "+50->{} (guest tags already present; re-dispatch EF100)",
                n, obj, tb, bound, bound + 1);

  if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
    static uint32_t s_pctx = 0;
    if (s_pctx == 0)
      s_pctx = mem.Alloc(64, 16);
    if (s_pctx) {
      MclaCompleteRscRebaseBeforePlace(obj);
      // Arm via existing W32 machinery then place.
      (void)MclaW32OpenConstructWalk(obj, stack, /*redispatch=*/false);
      PPCContext p{};
      p.r1.u64 = stack ? stack : 0x006D8EC0u;
      p.r13.u64 = 0x8F200000u;
      p.r3.u64 = obj;
      p.r4.u64 = s_pctx;
      MCLA_LOG_WARN("W33-PLACE obj={:08X} table={:08X} bound={}", obj, tb,
                    bound);
      place(p, mcla::kernel::g_memory.base);
      uint32_t vt2 = 0, arr2 = 0, p24b = 0;
      uint16_t cnt50 = 0;
      (void)mem.ReadU32BE(obj + 0, &vt2);
      (void)mem.ReadU32BE(obj + 12, &arr2);
      (void)mem.ReadU32BE(obj + 24, &p24b);
      (void)mem.ReadU16BE(obj + 50, &cnt50);
      int nChildVt = 0, nValidAfter = 0;
      if (p24b && isGuestPtr(p24b)) {
        for (int i = 1; i < 9; ++i) {
          uint32_t pn = 0, cvt = 0;
          uint8_t tg = 0;
          if (!mem.ReadU32BE(p24b + static_cast<uint32_t>(i * 4), &pn))
            break;
          if (!isGuestPtr(pn) || pn == obj)
            continue;
          (void)mem.ReadU8(pn + 8, &tg);
          if (tg >= 1u && tg <= 9u)
            ++nValidAfter;
          if (mem.ReadU32BE(pn, &cvt) && (cvt & 0xFFFF0000u) == 0x82080000u)
            ++nChildVt;
        }
      }
      MCLA_LOG_WARN("W33-PLACE-DONE obj={:08X} vt={:08X} arr={:08X} "
                    "+24={:08X} +50={} nValidAfter={} nChildVt={}",
                    obj, vt2, arr2, p24b, cnt50, nValidAfter, nChildVt);
    }
  }
  return true;
}

// ---------------------------------------------------------------------------
// w34: one host lever after job2 POST-EXEC when W33-PARSE-MISSING proves the
// guest GFx parse gate. Gate evidence (w33 + PE):
//   - UILOAD 822012E8 / EF220 / 824876E0 / factories FAC4/5 = 0 hits
//   - POST-EXEC #2 streamCnt=17, place writes vt 82085364, nChildVt=0
//   - +24=5004FC20 virtual at POST-EXEC; rebased B79B0C20; FDA90 garbage tags
//   - 824876E0 skips GFx LoadBytes when stream+0 is signed-negative (CDCD/-1)
//   - 824EAFA0 needs a 16-bit data id present in the GFx movie hash table
// Lever (faithful, no invent): census GFx movies + FP table + deep dest tags;
// if a GFx loader/movie exists and stream+0 is poison while inflated dest
// data is live, probe guest 824EAFA0 with package-visible 16-bit ids; only
// if lookup returns a real entry, set stream+0 to that id and re-dispatch
// guest 824876E0. Never host FEX over dests. Never invent tags/vtables.
// ---------------------------------------------------------------------------
static uint32_t MclaW34DeepTagScan(auto &mem, uint32_t dest, uint32_t *outBase)
{
  // Deeper than W33 (0x200): scan 0x2000 of dest for stride-12 tags 1..9.
  for (uint32_t off = 0; off < 0x2000u; off += 4) {
    const uint32_t b = dest + off;
    uint8_t t[8] = {0};
    int nv = 0;
    bool ok = true;
    for (int i = 0; i < 8; ++i) {
      if (!mem.ReadU8(b + static_cast<uint32_t>(i * 12) + 8, &t[i])) {
        ok = false;
        break;
      }
      if (t[i] >= 1u && t[i] <= 9u)
        ++nv;
    }
    if (ok && nv >= 2) {
      if (outBase)
        *outBase = b;
      return static_cast<uint32_t>(nv);
    }
  }
  return 0;
}

bool MclaW34GfxParseLever(uint32_t obj, uint32_t slotAddr)
{
  static std::atomic<uint32_t> s_n{0};
  const uint32_t n = s_n.fetch_add(1) + 1;
  if (n > 8)
    return false;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!obj || obj == 0xCDCDCDCDu)
    return false;

  uint32_t vt = 0, p24 = 0;
  uint16_t cnt50 = 0;
  (void)mem.ReadU32BE(obj + 0, &vt);
  (void)mem.ReadU32BE(obj + 24, &p24);
  (void)mem.ReadU16BE(obj + 50, &cnt50);

  // FP factory table census (rdata).
  uint32_t fp4 = 0, fp5 = 0;
  (void)mem.ReadU32BE(0x8202FE20u, &fp4);
  (void)mem.ReadU32BE(0x8202FE24u, &fp5);

  // Deep dest tag scan (job2 PSTREAM pbases).
  static const uint32_t kDests[] = {
      0xB7B41000u, 0xB7981000u, 0xB79A1000u, 0xB7B61000u,
      0xB7B71000u, 0xB79C1000u, 0xB79E1000u, 0xB7B01000u,
      0xB7901000u, 0xB7801000u,
  };
  uint32_t tagBase = 0, tagNv = 0, tagDest = 0;
  uint32_t destHeads[10] = {0};
  int nLive = 0;
  for (int i = 0; i < 10; ++i) {
    uint32_t h = 0;
    (void)mem.ReadU32BE(kDests[i], &h);
    destHeads[i] = h;
    if (h != 0 && h != 0xCDCDCDCDu && h != 0xFFFFFFFFu)
      ++nLive;
  }
  for (uint32_t d : kDests) {
    uint32_t b = 0;
    const uint32_t nv = MclaW34DeepTagScan(mem, d, &b);
    if (nv > tagNv) {
      tagNv = nv;
      tagBase = b;
      tagDest = d;
    }
  }

  // Scan guest heap bands for GFx loader objects (vt 0x82073xxx from
  // 824C6F08 ctor writing 0x820736DC / 0x820736B0). Bounded sample.
  struct GfxHit {
    uint32_t obj;
    uint32_t vt;
    uint32_t movie;
  };
  GfxHit gfx[6];
  int nGfx = 0;
  static const uint32_t kScanLo[] = {0xA0000000u, 0xC5000000u, 0xC7000000u, 0xCA000000u};
  static const uint32_t kScanHi[] = {0xA0800000u, 0xC6000000u, 0xC8000000u, 0xCB000000u};
  for (int band = 0; band < 4 && nGfx < 6; ++band) {
    for (uint32_t a = kScanLo[band]; a < kScanHi[band] && nGfx < 6; a += 0x40) {
      uint32_t w0 = 0;
      if (!mem.ReadU32BE(a, &w0))
        continue;
      if ((w0 & 0xFFFFFF00u) != 0x82073600u && (w0 & 0xFFFF0000u) != 0x82070000u)
        continue;
      // Tighten: accept 0x82073xxx vtables only.
      if ((w0 & 0xFFFFF000u) != 0x82073000u)
        continue;
      uint32_t movie = 0;
      (void)mem.ReadU32BE(a + 4, &movie);
      gfx[nGfx++] = {a, w0, movie};
    }
  }

  // Movie hash-table census for hits.
  uint32_t movTsize[6] = {0}, movBuck[6] = {0};
  for (int i = 0; i < nGfx; ++i) {
    uint32_t m = gfx[i].movie;
    if (m && m != 0xCDCDCDCDu) {
      (void)mem.ReadU32BE(m + 92, &movTsize[i]);
      (void)mem.ReadU32BE(m + 88, &movBuck[i]);
    }
  }

  MCLA_LOG_WARN("W34-GFX-CENSUS #{} obj={:08X} vt={:08X} +24={:08X} +50={} "
                "fpFE20={:08X} fpFE24={:08X} nLiveDest={} "
                "d0={:08X} d2={:08X} tagDest={:08X} tagBase={:08X} tagNv={} "
                "nGfx={}",
                n, obj, vt, p24, cnt50, fp4, fp5, nLive, destHeads[0],
                destHeads[2], tagDest, tagBase, tagNv, nGfx);
  for (int i = 0; i < nGfx; ++i)
    MCLA_LOG_WARN("W34-GFX-MOVIE #{} obj={:08X} vt={:08X} movie={:08X} "
                  "tsize={} buckets={:08X}",
                  n, gfx[i].obj, gfx[i].vt, gfx[i].movie, movTsize[i],
                  movBuck[i]);
  if (fp4 != 0x82275D88u || fp5 != 0x82275DA8u)
    MCLA_LOG_WARN("W34-FP-MISMATCH #{} FE20={:08X} FE24={:08X} want 82275D88/82275DA8",
                  n, fp4, fp5);

  // Lifecycle drive: ctor leaves [obj+12]=0, [obj+28]=0. 824C6F70 cold path
  // needs [obj+12]=live device to reach 824880F8 and set [obj+28]=1.
  // Arm dev from OnDeviceCreated, then dispatch guest 824C6F70 once per lever
  // hit (lever capped at 8). Never invent device internals.
  {
    const uint32_t liveDev = mcla::gpu::DeviceGuestAddr();
    auto *lifeFn = mcla::kernel::g_memory.FindFunction(0x824C6F70u);
    for (int gi = 0; gi < nGfx; ++gi) {
      uint32_t st28 = 0, dev12 = 0, fl664 = 0, w816 = 0;
      (void)mem.ReadU32BE(gfx[gi].obj + 28, &st28);
      (void)mem.ReadU32BE(gfx[gi].obj + 12, &dev12);
      (void)mem.ReadU32BE(gfx[gi].obj + 664, &fl664);
      (void)mem.ReadU32BE(gfx[gi].obj + 816, &w816);
      if (st28 != 0 || fl664 == 1 || !lifeFn)
        continue;
      if (dev12 == 0 && liveDev != 0) {
        (void)mem.WriteU32BE(gfx[gi].obj + 12, liveDev);
        (void)mem.ReadU32BE(gfx[gi].obj + 12, &dev12);
      }
      if (dev12 == 0 || dev12 == 0xCDCDCDCDu) {
        MCLA_LOG_WARN("W34-LIFE-SKIP #{} obj={:08X} no live dev (lever dev={:08X})",
                      n, gfx[gi].obj, liveDev);
        continue;
      }
      PPCContext lc{};
      lc.r1.u64 = 0x006D8EC0u;
      lc.r13.u64 = 0x8F200000u;
      lc.fpscr.disableFlushModeUnconditional();
      lc.r3.u64 = gfx[gi].obj;
      MCLA_LOG_WARN("W34-LIFE #{} obj={:08X} st28={} dev={:08X} fl664={:08X} w816={:08X} — dispatch 824C6F70",
                    n, gfx[gi].obj, st28, dev12, fl664, w816);
      lifeFn(lc, mcla::kernel::g_memory.base);
      uint32_t st28b = 0, movieB = 0, tsizeB = 0, buckB = 0;
      (void)mem.ReadU32BE(gfx[gi].obj + 28, &st28b);
      (void)mem.ReadU32BE(gfx[gi].obj + 4, &movieB);
      if (movieB && movieB != 0xCDCDCDCDu) {
        (void)mem.ReadU32BE(movieB + 92, &tsizeB);
        (void)mem.ReadU32BE(movieB + 88, &buckB);
      }
      MCLA_LOG_WARN("W34-LIFE-POST #{} obj={:08X} st28 {}->{} movie {:08X}->{:08X} tsize={} buckets={:08X}",
                    n, gfx[gi].obj, st28, st28b, gfx[gi].movie, movieB, tsizeB, buckB);
      gfx[gi].movie = movieB;
      if (gi < 6) {
        movTsize[gi] = tsizeB;
        movBuck[gi] = buckB;
      }
    }
  }

  // If deep scan found a guest-built tag table that W33 missed, bind +24
  // records the same faithful way (guest tags already present) + EF100.
  // Guarded: p24/obj must be writable guest memory, bound clamped to 8.
  if (tagNv >= 2 && tagBase != 0 && p24 >= 0x80000000u &&
      p24 != 0xCDCDCDCDu) {
    uint32_t p24probe = 0, objProbe = 0;
    const bool p24ok = mem.ReadU32BE(p24 + 4, &p24probe);
    const bool objok = mem.ReadU32BE(obj + 0, &objProbe);
    if (!p24ok || !objok) {
      MCLA_LOG_WARN("W34-BIND-SKIP #{} p24/obj unreadable p24={:08X} obj={:08X}",
                    n, p24, obj);
    } else {
    int bound = 0;
    for (int i = 1; i < 9; ++i) {
      const uint32_t slot = tagBase + static_cast<uint32_t>((i - 1) * 12);
      uint8_t t = 0;
      if (!mem.ReadU8(slot + 8, &t))
        break;
      if (t < 1u || t > 9u)
        continue;
      const bool wok = mem.WriteU32BE(p24 + static_cast<uint32_t>(i * 4), slot);
      if (!wok)
        break;
      ++bound;
    }
    if (bound > 0) {
      (void)mem.WriteU16BE(obj + 50, static_cast<uint16_t>(bound + 1));
      MCLA_LOG_WARN("W34-BIND-DEEP #{} dest={:08X} table={:08X} nv={} "
                    "bound={} +50->{} (guest tags; EF100)",
                    n, tagDest, tagBase, tagNv, bound, bound + 1);
      if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
        static uint32_t s_pctx = 0;
        if (s_pctx == 0)
          s_pctx = mem.Alloc(64, 16);
        if (s_pctx) {
          MclaCompleteRscRebaseBeforePlace(obj);
          (void)MclaW32OpenConstructWalk(obj, 0, /*redispatch=*/false);
          PPCContext pctx{};
          pctx.r1.u64 = 0x006D8EC0u;
          pctx.r13.u64 = 0x8F200000u;
          pctx.r3.u64 = obj;
          pctx.r4.u64 = s_pctx;
          MCLA_LOG_WARN("W34-PLACE obj={:08X} table={:08X}", obj, tagBase);
          place(pctx, mcla::kernel::g_memory.base);
        }
      }
    }
    } // else p24/obj readable
  }

  // Parse-flag lever: if a GFx loader object exists, probe guest 824EAFA0
  // with package-visible 16-bit ids. Only on a non-zero guest lookup result
  // set stream+0 and re-dispatch guest 824876E0. Ids from w28 package/TOC
  // (pkg+16=0x0002FFC9 -> 0xFFC9; READWRAP key=0x00008004; pkg+4=0x1B) —
  // never invent; lookup must return a real entry.
  if (nGfx > 0) {
    // Only FFC9 grounded (low16 of pkg+16 0x2FFC9); 8004 is a PSTREAM tag not a
    // GFx id, 1B/09/04 ungrounded — lookup must still return a real entry.
    static const uint32_t kCandIds[] = {0x0000FFC9u, 0x00008004u,
                                        0x0000001Bu, 0x00000009u,
                                        0x00000004u};
    int nMoviesLive = 0;
    for (int gi = 0; gi < nGfx; ++gi)
      if (gfx[gi].movie && gfx[gi].movie != 0xCDCDCDCDu &&
          gfx[gi].movie >= 0x80000000u && gfx[gi].movie < 0xC0000000u)
        ++nMoviesLive;
    auto *afa0 = mcla::kernel::g_memory.FindFunction(0x824EAFA0u);
    auto *ld = mcla::kernel::g_memory.FindFunction(0x824876E0u);
    for (int gi = 0; gi < nGfx && gi < 3; ++gi) {
      const uint32_t movie = gfx[gi].movie;
      if (!movie || movie == 0xCDCDCDCDu)
        continue;
      if (movie < 0x80000000u || movie >= 0xC0000000u)
        continue;
      if (!afa0)
        break;
      // tryId uses the guest itself as oracle (824EAFA0 hash walk:
      // id16<tize else null; buckets+88/shift+104/mask+108, stride 148).
      // Returns entry, or 0 when miss. Logs only hits (sweep would flood).
      auto tryId = [&](uint32_t cid, bool verbose, uint32_t *outEntry) -> uint32_t {
        PPCContext p{};
        p.r1.u64 = 0x006D8EC0u;
        p.r13.u64 = 0x8F200000u;
        p.r3.u64 = movie;
        p.r4.u64 = cid;
        afa0(p, mcla::kernel::g_memory.base);
        const uint32_t entry = p.r3.u32;
        if (outEntry)
          *outEntry = entry;
        const bool hit = (entry != 0 && entry != 0xCDCDCDCDu &&
                          entry >= 0x80000000u && entry < 0xC0000000u);
        if (verbose || hit)
          MCLA_LOG_WARN("W34-LOOKUP #{} movie={:08X} id={:04X} entry={:08X} "
                        "tsize={}",
                        n, movie, cid & 0xFFFFu, entry, movTsize[gi]);
        return hit ? entry : 0;
      };
      // Phase 1: dynamic sweep 0..cap-1 via guest oracle. tsize bounds id16
      // (guest returns null when id16>=tsize), so every hit is a real entry.
      {
        const uint32_t tsize = movTsize[gi];
        const uint32_t buck = movBuck[gi];
        uint32_t cap = (tsize > 128u) ? 128u : tsize;
        if (tsize == 0 || tsize > 0x10000u || buck == 0 || buck == 0xCDCDCDCDu)
          cap = 0;
        uint32_t hits = 0, firstId = 0, firstEntry = 0;
        for (uint32_t cid = 0; cid < cap; ++cid) {
          uint32_t e = 0;
          if (tryId(cid, false, &e) && ld) {
            ++hits;
            if (firstEntry == 0) {
              firstId = cid;
              firstEntry = e;
            }
          }
        }
        if (hits)
          MCLA_LOG_WARN("W34-SWEEP #{} movie={:08X} tsize={} cap={} hits={} first id={:04X} entry={:08X}",
                        n, movie, tsize, cap, hits, firstId, firstEntry);
        else if (cap)
          MCLA_LOG_WARN("W34-SWEEP #{} movie={:08X} tsize={} cap={} hits=0", n, movie, tsize, cap);
        if (firstEntry && ld) {
          const uint32_t cid = firstId;
          const uint32_t entry = firstEntry;
          (void)entry;
          (void)cid;
          // Faithful parse-flag: write the proven id into the loader stream
          // slot and re-dispatch guest 824876E0(loader, stream).
          // Use a host-allocated stream descriptor (64B) — loader reads
          // [stream+0] as dataId. Do not touch live dests.
          static uint32_t s_stream = 0;
          if (s_stream == 0)
            s_stream = mem.Alloc(64, 16);
          if (!s_stream)
            break;
          {
            uint8_t z[64] = {0};
            (void)mem.WriteBytes(s_stream, z, sizeof(z));
          }
          (void)mem.WriteU32BE(s_stream + 0, cid);
          PPCContext lc{};
          lc.r1.u64 = 0x006D8EC0u;
          lc.r13.u64 = 0x8F200000u;
          lc.r3.u64 = gfx[gi].obj; // loader object
          lc.r4.u64 = s_stream;
          MCLA_LOG_WARN("W34-PARSE-FLAG #{} loader={:08X} stream={:08X} "
                        "dataId={:04X} movie={:08X} entry={:08X} — "
                        "dispatch guest 824876E0",
                        n, gfx[gi].obj, s_stream, cid & 0xFFFFu, movie,
                        entry);
          ld(lc, mcla::kernel::g_memory.base);
          // Post census.
          uint32_t vt2 = 0, p24b = 0;
          (void)mem.ReadU32BE(obj + 0, &vt2);
          (void)mem.ReadU32BE(obj + 24, &p24b);
          MCLA_LOG_WARN("W34-POST #{} vt={:08X} +24={:08X} +50={} tagNv={}",
                        n, vt2, p24b, cnt50, tagNv);
          return true;
        }
      }
      // Phase 2: static fallback candidates (mostly ungrounded; guest oracle
      // still gates — dispatch only on real entry).
      for (uint32_t cid : kCandIds) {
        uint32_t e = 0;
        if (tryId(cid, true, &e) && ld) {
          const uint32_t entry = e;
          static uint32_t s_stream2 = 0;
          if (s_stream2 == 0)
            s_stream2 = mem.Alloc(64, 16);
          if (!s_stream2)
            break;
          {
            uint8_t z[64] = {0};
            (void)mem.WriteBytes(s_stream2, z, sizeof(z));
          }
          (void)mem.WriteU32BE(s_stream2 + 0, cid);
          PPCContext lc{};
          lc.r1.u64 = 0x006D8EC0u;
          lc.r13.u64 = 0x8F200000u;
          lc.r3.u64 = gfx[gi].obj;
          lc.r4.u64 = s_stream2;
          MCLA_LOG_WARN("W34-PARSE-FLAG-FB #{} loader={:08X} stream={:08X} "
                        "dataId={:04X} movie={:08X} entry={:08X} — "
                        "dispatch guest 824876E0",
                        n, gfx[gi].obj, s_stream2, cid & 0xFFFFu, movie,
                        entry);
          ld(lc, mcla::kernel::g_memory.base);
          uint32_t vt2 = 0, p24b = 0;
          (void)mem.ReadU32BE(obj + 0, &vt2);
          (void)mem.ReadU32BE(obj + 24, &p24b);
          MCLA_LOG_WARN("W34-POST #{} vt={:08X} +24={:08X} +50={} tagNv={}",
                        n, vt2, p24b, cnt50, tagNv);
          return true;
        }
      }
    }
    if (nMoviesLive == 0)
      MCLA_LOG_WARN("W34-NOMOVIE #{} nGfx={} — loaders present but movie==0/poison; "
                    "factory/lifecycle has not armed [loader+4] (do not invent)",
                    n, nGfx);
    else
      MCLA_LOG_WARN("W34-NOLOOKUP #{} nGfx={} nMoviesLive={} — no GFx hash entry for package "
                    "ids; parse still gated (do not invent)",
                    n, nGfx, nMoviesLive);
  } else {
    MCLA_LOG_WARN("W34-NOGFX #{} — no GFx loader objects (vt 0x82073xxx) in "
                  "scan bands; UILOAD/EF220 never armed after inflate",
                  n);
  }
  (void)slotAddr;
  return false;
}

// w29: dump UI .xsf TOC census (path, toc words, pkg) once per boot.
static void MclaLogXsfTocCensus(const char *tag) {
  std::lock_guard<std::mutex> lk(g_xsfMtx);
  int n = 0;
  for (const auto &kv : g_xsfToc) {
    const auto &e = kv.second;
    if (kv.first.find(".xsf") == std::string::npos &&
        kv.first.find("resources/ui") == std::string::npos)
      continue;
    uint32_t pkg = 0;
    const uint32_t c2 = e.w[2] & 0x00FFF000u;
    const uint32_t c3 = e.w[3] & 0x00FFF000u;
    if (c2 == 0x60000u || c2 == 0xA0000u || c2 == 0x35A000u)
      pkg = c2;
    else if (c3 == 0x60000u || c3 == 0xA0000u || c3 == 0x35A000u)
      pkg = c3;
    else if (kv.first.find(".xsf") != std::string::npos)
      pkg = 0xA0000u;
    else if (kv.first.find("meshtextures") != std::string::npos)
      pkg = 0x60000u;
    MCLA_LOG_WARN("W29-TOC {} path='{}' entry={:08X} "
                  "toc=[{:08X} {:08X} {:08X} {:08X}] "
                  "tocOff={:08X} pkgFromToc={:08X} bodyHits={}",
                  tag, kv.first, e.entry, e.w[0], e.w[1], e.w[2], e.w[3],
                  e.w[1], pkg, e.bodyHits);
    ++n;
  }
  MCLA_LOG_WARN("W29-TOC-DONE {} n={} cached={}", tag, n, g_xsfToc.size());
}

// w29: per-dest XC-frame extract from multi-.xsf package 0xA0000.
// Package +16 unc hint 196553 << pstreamSum 1867776 — multi-resource
// container, NOT a linear image. Linear host XC distribute (w27/w28)
// plants entropy. Walk XC frames at pkg+20; fill each job2 PSTREAM dest
// in vbase order via guest 82461530 + fresh ctx. Keep dest only when the
// head is a real resource image (44495500/5500/00019249). Never plant
// entropy/zero. Never invent vtables. Never r3=0.
static int MclaJ2FrameExtract(auto &mem, uint32_t pkgBounce, uint32_t pkgSz,
                              uint32_t stack) {
  auto HeadIsRes = [](uint32_t h) -> bool {
    return (h & 0xFFFFFF00u) == 0x44365500u ||
           (h & 0xFFFFFF00u) == 0x44495500u || (h & 0xFFFFu) == 0x5500u ||
           h == 0x00019249u;
  };
  auto HeadLooksStructured = [](const uint8_t *p, uint32_t n) -> bool {
    if (!p || n < 8)
      return false;
    const uint32_t h = MclaBE(p);
    if ((h & 0xFFFFFF00u) == 0x44365500u ||
        (h & 0xFFFFFF00u) == 0x44495500u || (h & 0xFFFFu) == 0x5500u ||
        h == 0x00019249u)
      return true;
    int live = 0, zeros = 0;
    const uint32_t lim = n < 64u ? n : 64u;
    for (uint32_t bi = 0; bi + 4 <= lim; bi += 4) {
      const uint32_t w = MclaBE(p + bi);
      if (w == 0)
        ++zeros;
      else if (w != 0xCDCDCDCDu && w != 0xFFFFFFFFu)
        ++live;
    }
    if (live == 0)
      return false;
    if (live >= 12 && zeros <= 2)
      return false;
    return (zeros >= 1 && live <= 10);
  };
  if (!pkgBounce || pkgSz < 32)
    return 0;
  uint32_t ph[6] = {0};
  for (int i = 0; i < 6; ++i)
    (void)mem.ReadU32BE(pkgBounce + static_cast<uint32_t>(i * 4), &ph[i]);
  if (ph[0] != 0x05435352u || ph[3] != 0x0FF512EFu) {
    MCLA_LOG_WARN("W29-FEX-SKIP bounce={:08X} head=[{:08X} {:08X} {:08X} "
                  "{:08X}] (want RSC5+XC)",
                  pkgBounce, ph[0], ph[1], ph[2], ph[3]);
    return 0;
  }
  // Job2 PSTREAM dests in vbase order (IsJob2UiDest only).
  struct Sl {
    uint32_t vbase, pbase, size;
  };
  Sl sl[kMclaRebaseMax];
  int nsl = 0;
  for (int i = 0; i < g_mclaRebaseCount && i < kMclaRebaseMax; ++i) {
    const auto &r = g_mclaRebaseMap[i];
    if (r.pbase == 0 || r.size == 0)
      continue;
    if (r.pbase >= 0xB7000000u && r.pbase < 0xB8000000u &&
        IsJob2UiDest(r.pbase))
      sl[nsl++] = {r.vbase, r.pbase, r.size};
  }
  for (int i = 0; i < nsl; ++i)
    for (int j = i + 1; j < nsl; ++j)
      if (sl[j].vbase < sl[i].vbase) {
        const Sl t = sl[i];
        sl[i] = sl[j];
        sl[j] = t;
      }
  if (nsl == 0) {
    MCLA_LOG_WARN("W29-FEX-SKIP nsl=0 nmap={}", g_mclaRebaseCount);
    return 0;
  }
  auto *fn82461530 = mcla::kernel::g_memory.FindFunction(0x82461530u);
  if (!fn82461530) {
    MCLA_LOG_WARN("W29-FEX-SKIP 82461530 missing");
    return 0;
  }
  static std::mutex s_fexMtx;
  std::lock_guard<std::mutex> dlock(s_fexMtx);
  static std::atomic<uint32_t> s_fexRun{0};
  const uint32_t runN = s_fexRun.fetch_add(1) + 1;
  if (runN > 8)
    return 0;
  static uint32_t s_prod = 0;
  static uint32_t s_sz = 0;
  if (s_prod == 0)
    s_prod = mem.Alloc(32, 16);
  if (s_sz == 0)
    s_sz = mem.Alloc(32, 16);
  if (!s_prod || !s_sz)
    return 0;

  uint32_t src = pkgBounce + 20u;
  uint32_t srcLeft = (pkgSz > 20u) ? (pkgSz - 20u) : 0u;
  int frameN = 0;
  int destOk = 0;
  int destFail = 0;
  MCLA_LOG_WARN("W29-FEX #{} bounce={:08X} pkgSz={:08X} nsl={} "
                "+4={} +16={} (unc hint) pstream framedecode",
                runN, pkgBounce, pkgSz, nsl, ph[1], ph[4]);
  for (int si = 0; si < nsl; ++si) {
    const uint32_t dest = sl[si].pbase;
    const uint32_t destSz = sl[si].size;
    uint32_t filled = 0;
    int framesThis = 0;
    // Snapshot dest head before fill (w28 left place-vt 82085364 on B7B41000).
    uint32_t pre[4] = {0};
    for (int k = 0; k < 4; ++k)
      (void)mem.ReadU32BE(dest + static_cast<uint32_t>(k * 4), &pre[k]);
    // w30 ONE LEVER: NEVER host FEX over a guest-owned dest (place vt
    // 8208xxxx or rscHead 44495500/5500). w29 FEX ZEROED B7B41000 after
    // place wrote 82085364 — that image is guest-owned, leave it alone.
    if (MclaHeadIsPlaceVt(pre[0]) || MclaHeadIsResourceImage(pre[0])) {
      MCLA_LOG_WARN("W30-GATE-FEX #{} dest={:08X} pre={:08X} — guest-owned "
                    "(place vt / rscHead); NEVER host FEX over dest",
                    si, dest, pre[0]);
      ++destOk; // treat as preserved, not a host fill
      continue;
    }
    while (filled + 16 < destSz && srcLeft >= 2 && frameN < 256) {
      uint8_t hb[8] = {0};
      if (!mem.ReadBytes(src, hb, 8))
        break;
      uint32_t hdrSz = 0, uncomp = 0, payLen = 0;
      if (hb[0] == 0xFF) {
        if (srcLeft < 5)
          break;
        hdrSz = 5;
        uncomp = (uint32_t(hb[1]) << 8) | uint32_t(hb[2]);
        payLen = (uint32_t(hb[3]) << 8) | uint32_t(hb[4]);
      } else {
        hdrSz = 2;
        uncomp = 0x8000u;
        payLen = (uint32_t(hb[0]) << 8) | uint32_t(hb[1]);
      }
      if (payLen == 0 || hdrSz + payLen > srcLeft + 16u)
        break;
      const uint32_t room = destSz - filled;
      uint32_t tryOut = (uncomp > 16 && uncomp < room) ? uncomp : room;
      if (tryOut > room)
        tryOut = room;
      if (tryOut < 16)
        break;
      const uint32_t ctx = MclaXcFreshCtx(mem, stack);
      if (!ctx)
        break;
      (void)mem.WriteU32BE(s_prod + 0, 0);
      (void)mem.WriteU32BE(s_sz + 0, tryOut);
      (void)mem.WriteU32BE(s_sz + 4, payLen);
      // Do NOT zero dest body — place may already own a vt there; we
      // overwrite only when the frame produces a structured head at +0.
      PPCContext p{};
      p.r1.u64 = stack ? stack : 0x006D8EC0u;
      p.r13.u64 = 0x8F200000u;
      p.r3.u64 = ctx + 20u;
      p.r4.u64 = uncomp ? uncomp : tryOut;
      p.r5.u64 = src + hdrSz;
      p.r6.u64 = payLen;
      p.r7.u64 = dest + filled;
      p.r8.u64 = tryOut;
      p.r9.u64 = s_prod;
      p.lr = 0x821BC380u;
      fn82461530(p, mcla::kernel::g_memory.base);
      const uint32_t ret = p.r3.u32;
      uint32_t frameOut = 0;
      (void)mem.ReadU32BE(s_prod + 0, &frameOut);
      const uint32_t fheadAddr = dest + filled;
      uint32_t fh[4] = {0};
      for (int k = 0; k < 4; ++k)
        (void)mem.ReadU32BE(fheadAddr + static_cast<uint32_t>(k * 4), &fh[k]);
      if (framesThis < 4 || (framesThis % 16) == 0)
        MCLA_LOG_WARN("W29-FEX-FRAME #{} dest={:08X}+{:05X} "
                      "src={:08X} payLen={} uncomp={} ret={:08X} "
                      "frameOut={} head=[{:08X} {:08X} {:08X} {:08X}]",
                      frameN, dest, filled, src, payLen, uncomp, ret, frameOut,
                      fh[0], fh[1], fh[2], fh[3]);
      if (ret != 0 || frameOut == 0 ||
          !HeadLooksStructured(reinterpret_cast<uint8_t *>(&fh[0]), 16)) {
        // Decode failed or produced entropy — do not keep this frame in
        // the dest. Advance source; leave dest bytes as-is for this slice.
        // If this is the FIRST frame of the dest and head is entropy,
        // restore pre-image so place never walks XC residue.
        if (filled == 0 && fh[0] != 0 && fh[0] != 0xCDCDCDCDu &&
            !HeadIsRes(fh[0])) {
          for (int k = 0; k < 4; ++k)
            (void)mem.WriteU32BE(dest + static_cast<uint32_t>(k * 4), pre[k]);
        }
        src += hdrSz + payLen;
        srcLeft = (srcLeft > hdrSz + payLen) ? (srcLeft - hdrSz - payLen) : 0;
        ++frameN;
        ++framesThis;
        continue;
      }
      filled += frameOut;
      src += hdrSz + payLen;
      srcLeft = (srcLeft > hdrSz + payLen) ? (srcLeft - hdrSz - payLen) : 0;
      ++frameN;
      ++framesThis;
    }
    uint32_t dh[4] = {0};
    for (int k = 0; k < 4; ++k)
      (void)mem.ReadU32BE(dest + static_cast<uint32_t>(k * 4), &dh[k]);
    const bool ok = HeadIsRes(dh[0]) ||
                    (dh[0] != 0 && dh[0] != 0xCDCDCDCDu &&
                     dh[0] != 0xFFFFFFFFu && filled >= 64 &&
                     HeadLooksStructured(reinterpret_cast<uint8_t *>(&dh[0]),
                                         16));
    if (ok)
      ++destOk;
    else
      ++destFail;
    MCLA_LOG_WARN("W29-FEX-DEST #{} dest={:08X} vbase={:08X} sz={:08X} "
                  "filled={} frames={} pre=[{:08X} {:08X}] "
                  "head=[{:08X} {:08X} {:08X} {:08X}] ok={}",
                  si, dest, sl[si].vbase, destSz, filled, framesThis, pre[0],
                  pre[1], dh[0], dh[1], dh[2], dh[3], ok ? 1 : 0);
  }
  MCLA_LOG_WARN("W29-FEX-DONE #{} frames={} destOk={} destFail={} "
                "srcLeft={}",
                runN, frameN, destOk, destFail, srcLeft);
  return destOk;
}

// w26: host-decompress package 0xA0000 (RSC5+XC, +16 size hint, next RSC5
// @0x35A000) into a scratch image, then copy decompressed slices across
// job2 PSTREAM physical dests in vbase order. Uses captured guest inflater
// r3 / XMem ctx — NEVER r3=0. Writes ONLY decompressed resource image
// (never compressed plant, never invented vtables). Guest place still runs
// on the decompressed image afterwards.
static int MclaJob2DecompressAndDistribute(PPCContext &ctx) {
  // F-195/T41.9b: this is the legacy host-side J2-DIST XMem replay of pkg 0xA0000
  // (UI). It collides with Path B's correct guest enqueue (F-193) — the runaway
  // INFLATE loop carries j2=0 + our 7179940 replay constants. When Path B is on,
  // disable this replay so the guest's own streaming owns UI inflate.
  if (!kJ2DistReplay)
    return 0;
  static std::mutex s_j2distMtx;
  std::lock_guard<std::mutex> dlock(s_j2distMtx);
  static std::atomic<uint32_t> s_j2distRun{0};
  const uint32_t runN = s_j2distRun.fetch_add(1) + 1;
  if (runN > 24)
    return 0;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  constexpr uint32_t kPkg = 0xA0000u;
  const uint32_t pkgSz = PackageSizeAt(kPkg);

  // F-293: the safe-site guest-decoder avenue is now FULLY CLOSED. At this
  // boot-safe J2-DIST context, both warm-ctx (F-290: garbage head=0) and
  // forceFresh (this run: produced=0 for the 2 big containers) fail — the
  // engine needs the live corrupt-serve inflate tables, which only exist where
  // it collapses boot (F-288). No guest-decoder site yields both correct output
  // and safe boot. Full decompress therefore requires the funded host XMemEx/
  // LZX decoder (task #17); deflate ruled out (F-292), single-stream LZX ruled
  // out (F-291). Block removed to keep the dests at the valid first-window
  // baseline (writing garbage head=0 is a net regression).

  // Capture inflater family (may already be live from job1 InflateBegin).
  const uint32_t inflater = s_guestInflaterR3.load();
  uint32_t xmemCtx = s_xmemCtx.load();
  if (inflater && xmemCtx == 0) {
    uint32_t w0 = 0;
    if (mem.ReadU32BE(inflater, &w0) && w0 != 0 && w0 != 0xCDCDCDCDu)
      xmemCtx = w0;
    if (xmemCtx)
      s_xmemCtx.store(xmemCtx);
  }
  if (inflater == 0 && xmemCtx == 0) {
    // Try join-table family even before first guest InflateBegin.
    uint32_t dummy[4] = {0};
    MclaCensusInflaterFamily(mem, 0);
    (void)dummy;
  }

  // Uncompressed target from RSC5 +16 / +28 low-20.
  uint32_t wantOut = 0x80000u;
  uint32_t h16 = 0;
  {
    std::vector<uint8_t> hdr(32);
    if (MclaLoadPkgWindow(kPkg, 0, 32, hdr) && hdr.size() >= 32) {
      h16 = MclaBE(hdr.data() + 16);
      const uint32_t h28 = MclaBE(hdr.data() + 28);
      if (h16 > 16 && h16 < 0x200000u)
        wantOut = h16;
      if ((h28 & 0x000FFFFFu) > wantOut && (h28 & 0x000FFFFFu) < 0x200000u)
        wantOut = h28 & 0x000FFFFFu;
      if (wantOut < 0x80000u)
        wantOut = 0x80000u;
    }
  }
  uint32_t pstreamSum = 0;
  struct DistSlice {
    uint32_t vbase, pbase, size;
  };
  DistSlice slices[kMclaRebaseMax] = {};
  int nSlice = 0;
  for (int i = 0; i < g_mclaRebaseCount && i < kMclaRebaseMax; ++i) {
    const auto &r = g_mclaRebaseMap[i];
    if (r.pbase == 0 || r.size == 0)
      continue;
    if (r.pbase >= 0xB7000000u && r.pbase < 0xB8000000u &&
        IsJob2UiDest(r.pbase)) {
      pstreamSum += r.size;
      slices[nSlice++] = {r.vbase, r.pbase, r.size};
    }
  }
  // Sort slices by vbase so linear image maps onto physical dests.
  for (int i = 0; i < nSlice; ++i)
    for (int j = i + 1; j < nSlice; ++j)
      if (slices[j].vbase < slices[i].vbase) {
        const DistSlice t = slices[i];
        slices[i] = slices[j];
        slices[j] = t;
      }
  if (pstreamSum > wantOut && pstreamSum < 0x200000u)
    wantOut = pstreamSum;
  if (wantOut > 0x200000u)
    wantOut = 0x200000u;

  static uint32_t s_outBuf = 0;
  static uint32_t s_pkgFull = 0;
  static uint32_t s_st = 0;
  static uint32_t s_stack = 0;
  static uint32_t s_sizePtrs = 0;
  if (s_outBuf == 0)
    s_outBuf = mem.Alloc(0x200000u, 16);
  if (s_pkgFull == 0)
    s_pkgFull = mem.Alloc(pkgSz + 32u, 16);
  if (s_st == 0)
    s_st = mem.Alloc(64, 16);
  if (s_sizePtrs == 0)
    s_sizePtrs = mem.Alloc(32, 16);
  if (s_stack == 0) {
    const uint32_t raw = mem.Alloc(0x800, 16);
    s_stack = raw ? (raw + 0x700u) : 0u;
  }
  if (!s_outBuf || !s_pkgFull || !s_st || !s_sizePtrs)
    return 0;

  MCLA_LOG_WARN("J2-DIST #{} pkg={:08X} pkgSz={:08X} wantOut={} h16={:08X} "
                "nmap={} nSlice={} inflater={:08X} xmemCtx={:08X} pstreamSum={}",
                runN, kPkg, pkgSz, wantOut, h16, g_mclaRebaseCount, nSlice,
                inflater, xmemCtx, pstreamSum);

  // Load FULL package into guest bounce (32KB windows; walk=0 must be RSC5).
  {
    uint32_t loaded = 0;
    for (uint32_t off = 0; off < pkgSz; off += 0x8000u) {
      std::vector<uint8_t> win;
      const uint32_t want =
          (pkgSz - off > 0x8000u) ? 0x8000u : (pkgSz - off);
      if (!MclaLoadPkgWindow(kPkg, off, want, win) || win.size() < 4)
        break;
      if (!mem.WriteBytes(s_pkgFull + off, win.data(),
                          static_cast<uint32_t>(win.size())))
        break;
      loaded += static_cast<uint32_t>(win.size());
      if (win.size() < want)
        break;
    }
    uint32_t ph[6] = {0};
    for (int i = 0; i < 6; ++i)
      (void)mem.ReadU32BE(s_pkgFull + static_cast<uint32_t>(i * 4), &ph[i]);
    MCLA_LOG_WARN("J2-DIST-PKG bounce={:08X} loaded={} head="
                  "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                  s_pkgFull, loaded, ph[0], ph[1], ph[2], ph[3], ph[4], ph[5]);
    if (loaded < 32 || ph[0] != 0x05435352u) {
      MCLA_LOG_WARN("J2-DIST-PKG-FAIL loaded={} head={:08X} (want RSC5)",
                    loaded, ph[0]);
      return 0;
    }
  }

  // w29: TOC census + per-dest XC-frame extract. Package 0xA0000 is a
  // multi-.xsf container (unc hint 196553 << pstreamSum 1867776); linear
  // host XC distribute plants entropy. Prefer frame decode into each
  // PSTREAM pbase; only structured heads stay. Skip linear slice write
  // when FEX already filled dests (do not clobber structured heads).
  MclaLogXsfTocCensus("J2-DIST");
  int fexOk = 0;
  {
    fexOk = MclaJ2FrameExtract(mem, s_pkgFull, pkgSz, s_stack ? s_stack : 0);
    MCLA_LOG_WARN("W29-FEX-RESULT ok={}/{} (structured dests)", fexOk, nSlice);
  }
  const bool skipLinearDist = (fexOk > 0);

  // Clear scratch so we can see what decompress actually wrote.
  {
    std::vector<uint8_t> z(256, 0);
    (void)mem.WriteBytes(s_outBuf, z.data(), 256);
  }

  bool inflated = false;
  uint32_t produced = 0;

  // w27 PATH A: host XCompress via FRESH decoder ctx + guest 8244FF20
  // (full stream). Never reuse dirty shared xmemCtx; never InflateBegin r3=0.
  {
    const uint32_t outCap =
        (wantOut > 0x200000u) ? 0x200000u : wantOut;
    produced = MclaXcDecodeFullStream(mem, s_pkgFull, pkgSz, s_outBuf,
                                      outCap, s_stack);
    // F-188: partial output (< wantOut) means the full-stream path could not
    // decompress the entire payload (multi-frame XC with independent Huffman
    // tables). Fall through to per-frame decode which handles each frame
    // independently via host libmspack.
    inflated = produced >= wantOut;
    if (!inflated && produced > 0) {
      MCLA_LOG_WARN("J2-DIST-PARTIAL produced={} wantOut={}, trying per-frame",
                    produced, wantOut);
      produced = 0;
    }
    if (!inflated) {
      // w27 PATH B: per-frame host LZX (kHostLzxDecode) or guest 82461530.
      produced = MclaXcDecodeGuestFrames(mem, s_pkgFull, pkgSz, s_outBuf,
                                         outCap, s_stack);
      inflated = produced > 0;
    }
    if (!inflated) {
      // w27 PATH D: guest InflateBegin with captured inflater r3 (never 0)
      // on the warm ctx job1 just used successfully.
      produced = MclaXcDecodeGuestInflate(mem, s_pkgFull, pkgSz, s_outBuf,
                                          outCap, s_stack);
      inflated = produced > 0;
    }
    if (!inflated) {
      // w27 PATH C: re-run full-stream but target pstreamSum / wantOut
      // when +16 hint is a single-resource size smaller than the PSTREAM
      // image the place-pass needs.
      uint32_t big = wantOut;
      if (big < pstreamSum)
        big = pstreamSum;
      if (big < 0x80000u)
        big = 0x80000u;
      if (big > 0x200000u)
        big = 0x200000u;
      if (big != outCap) {
        produced = MclaXcDecodeFullStream(mem, s_pkgFull, pkgSz, s_outBuf,
                                          big, s_stack);
        inflated = produced > 0;
        if (!inflated)
          produced = MclaXcDecodeGuestInflate(mem, s_pkgFull, pkgSz, s_outBuf,
                                              big, s_stack);
        inflated = produced > 0;
        if (!inflated)
          produced = MclaXcDecodeGuestFrames(mem, s_pkgFull, pkgSz, s_outBuf,
                                             big, s_stack);
        inflated = produced > 0;
      }
    }
  }

  // Always census inflater context + scratch, even if inflate looks empty.
  {
    uint32_t ctx4 = 0, ctx0 = 0, sc[8] = {0};
    if (xmemCtx && xmemCtx != 0xCDCDCDCDu) {
      (void)mem.ReadU32BE(xmemCtx + 0, &ctx0);
      (void)mem.ReadU32BE(xmemCtx + 4, &ctx4);
    }
    for (int i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(s_outBuf + static_cast<uint32_t>(i * 64), &sc[i]);
    uint32_t infW[4] = {0};
    if (inflater && inflater >= 0x80000000u)
      for (int i = 0; i < 4; ++i)
        (void)mem.ReadU32BE(inflater + static_cast<uint32_t>(i * 4), &infW[i]);
    MCLA_LOG_WARN("J2-DIST-CENSUS inflater={:08X} infW=[{:08X} {:08X} "
                  "{:08X} {:08X}] xmemCtx={:08X} ctx0={:08X} ctx+4={:08X} "
                  "(XMem requires ctx+4==1) scratch@[0,64,128,192,256,320,"
                  "384,448]=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X}] produced={}",
                  inflater, infW[0], infW[1], infW[2], infW[3], xmemCtx, ctx0,
                  ctx4, sc[0], sc[1], sc[2], sc[3], sc[4], sc[5], sc[6],
                  sc[7], produced);
  }

  // w26: +24 list census ALWAYS — even when host XC wrote zeros. Guest
  // inflate/place may still have constructed children; bind only real
  // 8208xxxx pointers (never invent a vtable).
  int nPlus24 = 0;
  uint32_t plus24p[16] = {0}, plus24v[16] = {0};
  {
    nPlus24 = MclaCensusPlus24List(mem, 0xB7B41000u, plus24p, plus24v, 16);
    // Also census dest-range nodes from the +24 list lead.
    static const uint32_t kLead[] = {
        0xB79BE0F0u, 0xB7B6CC00u, 0xB7988D10u, 0xB7B6BF60u,
        0xB7B6C6E0u, 0xB7B67C60u, 0xB7B6C8C0u,
    };
    for (uint32_t p : kLead) {
      uint32_t w[6] = {0};
      for (int k = 0; k < 6; ++k)
        (void)mem.ReadU32BE(p + static_cast<uint32_t>(k * 4), &w[k]);
      const bool swfc = (w[0] & 0xFFFF0000u) == 0x82080000u;
      MCLA_LOG_WARN("W26-PLUS24-NODE @{:08X} [{:08X} {:08X} {:08X} {:08X} "
                    "{:08X} {:08X}] swfc={}",
                    p, w[0], w[1], w[2], w[3], w[4], w[5],
                    swfc ? 1 : 0);
      if (swfc && nPlus24 < 16) {
        bool dup = false;
        for (int j = 0; j < nPlus24; ++j)
          if (plus24p[j] == p)
            dup = true;
        if (!dup) {
          plus24p[nPlus24] = p;
          plus24v[nPlus24] = w[0];
          MCLA_LOG_WARN("W26-PLUS24-SWFC #{} obj={:08X} vt={:08X} (lead)",
                        nPlus24, p, w[0]);
          ++nPlus24;
        }
      }
    }
    // Bind real 8208xxxx from +24 into arr (only those pointers).
    if (nPlus24 > 0) {
      uint32_t arr = 0;
      uint16_t cnt = 0;
      (void)mem.ReadU32BE(0xB7B41000u + 12, &arr);
      (void)mem.ReadU16BE(0xB7B41000u + 16, &cnt);
      uint32_t a0 = 0;
      if (arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
        (void)mem.ReadU32BE(arr, &a0);
      bool has = false;
      for (int i = 0; i < nPlus24; ++i)
        if (a0 == plus24p[i])
          has = true;
      if (!has && arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu) {
        const int nb = nPlus24 > 8 ? 8 : nPlus24;
        for (int i = 0; i < nb; ++i)
          (void)mem.WriteU32BE(arr + static_cast<uint32_t>(i * 4), plus24p[i]);
        (void)mem.WriteU16BE(0xB7B41000u + 16,
                             static_cast<uint16_t>(nb));
        MCLA_LOG_WARN("W26-ARR-BIND-PLUS24 arr={:08X} n={} arr0={:08X}"
                      "->{:08X} vt0={:08X}",
                      arr, nb, a0, plus24p[0], plus24v[0]);
        // Re-dispatch guest place on the bound arr (never invent vt).
        if (auto *placeB =
                mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
          static uint32_t s_bindCtx = 0;
          if (s_bindCtx == 0)
            s_bindCtx = mem.Alloc(64, 16);
          if (s_bindCtx) {
            MclaArmRebaseCtx(s_bindCtx);
            PPCContext pB;
            pB.r1.u64 = s_stack ? s_stack : 0x006D8EC0u;
            pB.r13.u64 = 0x8F200000u;
            pB.r3.u64 = 0xB7B41000u;
            pB.r4.u64 = s_bindCtx;
            MCLA_LOG_WARN("W26-PLUS24-PLACE arr={:08X} n={} — re-dispatch "
                          "825EF100 after +24 bind",
                          arr, nb);
            placeB(pB, mcla::kernel::g_memory.base);
            uint32_t vt6 = 0, arr6 = 0, a6 = 0;
            uint16_t cnt6 = 0;
            (void)mem.ReadU32BE(0xB7B41000u, &vt6);
            (void)mem.ReadU32BE(0xB7B41000u + 12, &arr6);
            (void)mem.ReadU16BE(0xB7B41000u + 16, &cnt6);
            if (arr6 && arr6 != 0xCDCDCDCDu && arr6 != 0xFFFFFFFFu)
              (void)mem.ReadU32BE(arr6, &a6);
            MCLA_LOG_WARN("W26-PLUS24-PLACE-DONE vt={:08X} arr={:08X} "
                          "[arr]={:08X} cnt={}",
                          vt6, arr6, a6, cnt6);
          }
        }
      }
    }
    MCLA_LOG_WARN("J2-DIST-PLUS24 n={} (produced={} inflater={:08X})",
                  nPlus24, produced, inflater);
  }

  // Dest-head census after decompress / guest inflate.
  constexpr uint32_t kHeads[] = {
      0xB7B41000u, 0xB7981000u, 0xB79A1000u, 0xB7B61000u,
      0xB7B71000u, 0xB79C1000u, 0xB79E1000u,
  };
  for (uint32_t d : kHeads) {
    uint32_t h[4] = {0};
    for (int k = 0; k < 4; ++k)
      (void)mem.ReadU32BE(d + static_cast<uint32_t>(k * 4), &h[k]);
    MCLA_LOG_WARN("J2-DIST-DESTHEAD @{:08X} [{:08X} {:08X} {:08X} {:08X}]",
                  d, h[0], h[1], h[2], h[3]);
  }
  {
    uint32_t aw[8] = {0};
    for (int i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(0xB7B6D9B4u + static_cast<uint32_t>(i * 4), &aw[i]);
    MCLA_LOG_WARN("J2-DIST-ARR B7B6D9B4 "
                  "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                  aw[0], aw[1], aw[2], aw[3], aw[4], aw[5], aw[6], aw[7]);
  }

  if (!inflated) {
    // Census/bind already ran. Refuse r3=0. Guest inflate may still feed
    // dests; place re-dispatch happens at the call site when wrote==0 but
    // nPlus24>0 (bind path above).
    MCLA_LOG_WARN("J2-DIST-NOINFLATE inflater={:08X} xmemCtx={:08X} "
                  "nPlus24={} produced={} — host XC produced no live image; "
                  "census/bind only (refuse InflateBegin r3=0)",
                  inflater, xmemCtx, nPlus24, produced);
    (void)ctx;
    return 0;
  }

  // w28: gate host-distribute on STRUCTURED image heads. w27 planted
  // high-entropy XC residue (B6E3AE7F…) into PSTREAM dests; place then
  // walked garbage and arr children stayed poison. Only copy a slice when
  // the image head looks like a real resource / RSC family. Never plant
  // entropy, never invent vtables.
  auto HeadLooksStructured = [](const uint8_t *p, uint32_t n) -> bool {
    if (!p || n < 8)
      return false;
    const uint32_t h = MclaBE(p);
    if ((h & 0xFFFFFF00u) == 0x44365500u ||
        (h & 0xFFFFFF00u) == 0x44495500u || (h & 0xFFFFu) == 0x5500u)
      return true; // RSC resource image family
    if (h == 0x00019249u || h == 0x05435352u || h == 0x0FF512EFu)
      return true;
    // w29: all-zero is NOT a resource image (w28 planted zeros as
    // "structured" because zeros>=2). High-entropy (almost every word
    // live) is XC residue — refuse. Accept only sparse structured heads.
    int live = 0, zeros = 0;
    const uint32_t lim = n < 64u ? n : 64u;
    for (uint32_t bi = 0; bi + 4 <= lim; bi += 4) {
      const uint32_t w = MclaBE(p + bi);
      if (w == 0)
        ++zeros;
      else if (w != 0xCDCDCDCDu && w != 0xFFFFFFFFu)
        ++live;
    }
    if (live == 0)
      return false; // empty / all-zero / poison-only
    if (live >= 12 && zeros <= 2)
      return false; // high-entropy XC residue
    return (zeros >= 1 && live <= 10);
  };
  auto HeadIsResourceImage = [](uint32_t h) -> bool {
    return (h & 0xFFFFFF00u) == 0x44365500u ||
           (h & 0xFFFFFF00u) == 0x44495500u || (h & 0xFFFFu) == 0x5500u ||
           h == 0x00019249u || h == 0x05435352u || h == 0x0FF512EFu;
  };
  (void)HeadIsResourceImage;
  const uint32_t imgLimit =
      (produced > 0 && produced < wantOut) ? produced : wantOut;
  int wrote = 0;
  uint32_t imgOff = 0;
  // w29: FEX already filled structured dests — do not clobber with linear
  // XC slices (w28 entropy path).
  if (skipLinearDist) {
    MCLA_LOG_WARN("W29-DIST-SKIP-LINEAR fexOk={} — keep frame-extract dests",
                  fexOk);
  }
  for (int i = 0; i < nSlice && !skipLinearDist; ++i) {
    const auto &s = slices[i];
    if (imgOff >= imgLimit)
      break;
    // w30 ONE LEVER: NEVER host J2-DIST linear slice over guest-owned dest.
    {
      uint32_t ph0 = 0;
      (void)mem.ReadU32BE(s.pbase, &ph0);
      if (MclaHeadIsPlaceVt(ph0) || MclaHeadIsResourceImage(ph0)) {
        MCLA_LOG_WARN("W30-GATE-DIST dest={:08X} head={:08X} — guest-owned; "
                      "skip host J2-DIST slice",
                      s.pbase, ph0);
        imgOff += s.size;
        continue;
      }
    }
    uint32_t n = s.size;
    if (imgOff + n > imgLimit)
      n = imgLimit - imgOff;
    if (n == 0)
      continue;
    std::vector<uint8_t> chunk(n);
    if (!mem.ReadBytes(s_outBuf + imgOff, chunk.data(), n))
      break;
    // Do not write all-zero / poison / entropy slices as place image.
    {
      bool anyLive = false;
      for (uint32_t bi = 0; bi < n && bi < 256u; bi += 4) {
        const uint32_t w = MclaBE(chunk.data() + bi);
        if (w != 0 && w != 0xCDCDCDCDu && w != 0xFFFFFFFFu) {
          anyLive = true;
          break;
        }
      }
      if (anyLive && !HeadLooksStructured(chunk.data(), n)) {
        MCLA_LOG_WARN(
            "W28-DIST-ENTROPY dest={:08X} n={} imgOff={:08X} "
            "head={:08X} — skip entropy plant",
            s.pbase, n, imgOff, MclaBE(chunk.data()));
        imgOff += n;
        continue;
      }
      if (!anyLive && n >= 16) {
        MCLA_LOG_WARN("J2-DIST-SLICE-ZERO dest={:08X} n={} imgOff={:08X} "
                      "— skip empty slice",
                      s.pbase, n, imgOff);
        imgOff += n;
        continue;
      }
    }
    if (!mem.WriteBytes(s.pbase, chunk.data(), n)) {
      MCLA_LOG_WARN("J2-DIST-SLICE-FAIL dest={:08X} n={} imgOff={}",
                    s.pbase, n, imgOff);
      imgOff += n;
      continue;
    }
    uint32_t dh[4] = {0};
    for (int k = 0; k < 4; ++k)
      (void)mem.ReadU32BE(s.pbase + static_cast<uint32_t>(k * 4), &dh[k]);
    MCLA_LOG_WARN("J2-DIST-SLICE #{} dest={:08X} vbase={:08X} n={} "
                  "imgOff={:08X} destHead=[{:08X} {:08X} {:08X} {:08X}]",
                  i, s.pbase, s.vbase, n, imgOff, dh[0], dh[1], dh[2], dh[3]);
    imgOff += n;
    ++wrote;
  }

  // Re-dispatch guest place on the freshly fed dests (never invent vtable).
  {
    static uint32_t s_w27PlaceCtx = 0;
    if (s_w27PlaceCtx == 0)
      s_w27PlaceCtx = mem.Alloc(64, 16);
    if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
      if (s_w27PlaceCtx) {
        MclaCompleteRscRebaseBeforePlace(0xB7B41000u);
        MclaArmRebaseCtx(s_w27PlaceCtx);
        uint32_t vt0 = 0, arr0 = 0;
        (void)mem.ReadU32BE(0xB7B41000u, &vt0);
        (void)mem.ReadU32BE(0xB7B41000u + 12, &arr0);
        PPCContext pB{};
        pB.r1.u64 = s_stack ? s_stack : 0x006D8EC0u;
        pB.r13.u64 = 0x8F200000u;
        pB.r3.u64 = 0xB7B41000u;
        pB.r4.u64 = s_w27PlaceCtx;
        MCLA_LOG_WARN("W27-PLACE-AFTER-XC wrote={} produced={} "
                      "vtBefore={:08X} arrBefore={:08X}",
                      wrote, produced, vt0, arr0);
        place(pB, mcla::kernel::g_memory.base);
        uint32_t vt = 0, arr = 0, a0 = 0;
        uint16_t cnt = 0;
        (void)mem.ReadU32BE(0xB7B41000u, &vt);
        (void)mem.ReadU32BE(0xB7B41000u + 12, &arr);
        (void)mem.ReadU16BE(0xB7B41000u + 16, &cnt);
        if (arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
          (void)mem.ReadU32BE(arr, &a0);
        int nChild = 0;
        uint32_t kids[8] = {0}, kvts[8] = {0};
        nChild = MclaCensusSwfcChildren(mem, kids, kvts, 8);
        uint32_t aw[8] = {0};
        for (int i = 0; i < 8; ++i)
          (void)mem.ReadU32BE(0xB7B6D9B4u + static_cast<uint32_t>(i * 4),
                              &aw[i]);
        constexpr uint32_t kHeads2[] = {
            0xB7B41000u, 0xB7981000u, 0xB79A1000u, 0xB7B61000u,
            0xB7B71000u, 0xB79C1000u, 0xB79E1000u,
        };
        for (uint32_t d : kHeads2) {
          uint32_t h[4] = {0};
          for (int k = 0; k < 4; ++k)
            (void)mem.ReadU32BE(d + static_cast<uint32_t>(k * 4), &h[k]);
          MCLA_LOG_WARN("W27-DESTHEAD @{:08X} [{:08X} {:08X} {:08X} {:08X}]",
                        d, h[0], h[1], h[2], h[3]);
        }
        MCLA_LOG_WARN("W27-PLACE-AFTER-XC-DONE vt={:08X} arr={:08X} "
                      "[arr]={:08X} cnt={} nChild={} arrWords="
                      "[{:08X} {:08X} {:08X} {:08X}]",
                      vt, arr, a0, cnt, nChild, aw[0], aw[1], aw[2], aw[3]);
        // w30: after guest place, bind already-written PSTREAM 8208xxxx kids.
        if (MclaHeadIsPlaceVt(vt))
          (void)MclaW30BindPstreamChildren(mem, 0xB7B41000u,
                                           s_stack ? s_stack : 0);
      }
    }
  }
  (void)ctx;
  return wrote;
}

// w24: complete 0x50/0x60 rebase + RSC-head census BEFORE 825EF100.
// Idempotent on words nest already rewrote; adds child-head dumps and
// gate-bad census so place-pass can survive the resource walk.
void MclaCompleteRscRebaseBeforePlace(uint32_t obj)
{
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (obj == 0 || obj == 0xCDCDCDCDu)
    return;

  // Always re-publish the guest region table D828/D890 walk.
  MclaPublishGuestRebaseTable();

  auto rebasePtr = [&](uint32_t p) -> uint32_t {
    if (!MclaIsPstreamVirtual(p))
      return p;
    for (int i = 0; i < g_mclaRebaseCount; ++i)
    {
      const uint32_t vb = g_mclaRebaseMap[i].vbase;
      const uint32_t pb = g_mclaRebaseMap[i].pbase;
      const uint32_t sz = g_mclaRebaseMap[i].size;
      if (sz != 0 && p >= vb && p < vb + sz)
        return pb + (p - vb);
    }
    return p;
  };

  uint32_t rh[16] = {0};
  for (int i = 0; i < 16; ++i)
    (void)mem.ReadU32BE(obj + static_cast<uint32_t>(i * 4), &rh[i]);
  const uint32_t vt = rh[0];
  const bool rscHead =
      (vt & 0xFFFFFF00u) == 0x44495500u ||
      (vt & 0xFFFFFF00u) == 0x44365500u || (vt & 0xFFFFu) == 0x5500u;
  MCLA_LOG_WARN("RSC-CENSUS-44495500 obj={:08X} vt={:08X} "
                "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}] "
                "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}] "
                "nmap={}",
                obj, vt, rh[0], rh[1], rh[2], rh[3], rh[4], rh[5], rh[6],
                rh[7], rh[8], rh[9], rh[10], rh[11], rh[12], rh[13], rh[14],
                rh[15], g_mclaRebaseCount);

  // Complete 0x50/0x60 rebase on the head itself (idempotent).
  uint32_t headRewritten = 0;
  for (int i = 0; i < 16; ++i)
  {
    if (!MclaIsPstreamVirtual(rh[i]))
      continue;
    const uint32_t np = rebasePtr(rh[i]);
    if (np != rh[i])
    {
      (void)mem.WriteU32BE(obj + static_cast<uint32_t>(i * 4), np);
      MCLA_LOG_WARN("RSC-REBASE-PREPLACE [{}] {:08X} -> {:08X}",
                    obj + static_cast<uint32_t>(i * 4), rh[i], np);
      rh[i] = np;
      ++headRewritten;
    }
  }

  // Follow already-physical pointer fields: dump + rebase child heads.
  uint32_t childGate = 0, childRebased = 0;
  static const char *kGateCls[] = {"ok", "gate-bad", "poison", "zero"};
  for (int i = 1; i < 16; ++i)
  {
    const uint32_t w = rh[i];
    if (!MclaPtrIsKnownPhys(w) && !MclaPtrInRebaseMap(w))
      continue;
    if (w < 0x80000000u)
      continue;
    uint32_t cw[8] = {0};
    for (int k = 0; k < 8; ++k)
      (void)mem.ReadU32BE(w + static_cast<uint32_t>(k * 4), &cw[k]);
    // Rebase 0x50/0x60 in the first 0x40 of each child head.
    for (int k = 0; k < 8; ++k)
    {
      if (!MclaIsPstreamVirtual(cw[k]))
        continue;
      const uint32_t np = rebasePtr(cw[k]);
      if (np != cw[k])
      {
        (void)mem.WriteU32BE(w + static_cast<uint32_t>(k * 4), np);
        MCLA_LOG_WARN("RSC-CHILD-REBASE [{:08X}] {:08X} -> {:08X}",
                      w + static_cast<uint32_t>(k * 4), cw[k], np);
        cw[k] = np;
        ++childRebased;
      }
    }
    MCLA_LOG_WARN("RSC-CHILD-DUMP obj={:08X}[{}] -> {:08X} "
                  "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                  obj, i, w, cw[0], cw[1], cw[2], cw[3], cw[4], cw[5], cw[6],
                  cw[7]);
    for (int k = 0; k < 8; ++k)
    {
      const uint32_t v = cw[k];
      const char *cls = kGateCls[0];
      if (v == 0)
        cls = kGateCls[3];
      else if (v == 0xCDCDCDCDu || (v & 0xFFFFFF00u) == 0xCDCD0000u)
        cls = kGateCls[2];
      else if (MclaPtrIsGateBad(v))
      {
        cls = kGateCls[1];
        ++childGate;
      }
      if (cls != kGateCls[0])
        MCLA_LOG_WARN("RSC-CHILD-WORD {:08X}[{}] = {:08X} {}", w, k, v, cls);
    }
  }

  // Arr-slot census (w23 stuck: arr=B7B6D9B4 [arr]=533D00CB).
  const uint32_t arr = rh[3];
  uint32_t arr0 = 0;
  if (arr != 0 && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
    (void)mem.ReadU32BE(arr, &arr0);
  const char *arrCls = "ok";
  if (arr0 == 0)
    arrCls = "zero";
  else if (arr0 == 0xCDCDCDCDu || (arr0 & 0xFFFFFF00u) == 0xCDCD0000u)
    arrCls = "poison";
  else if (MclaPtrIsGateBad(arr0))
    arrCls = "gate-bad";
  MCLA_LOG_WARN("RSC-ARR-CENSUS obj={:08X} arr={:08X} [arr]={:08X} cls={} "
                "rscHead={} headRewritten={} childRebased={} childGate={}",
                obj, arr, arr0, arrCls, rscHead ? 1 : 0, headRewritten,
                childRebased, childGate);

  // Full nest re-scan: force a few times per boot (early EF100 / deferred
  // place) then skip — w23 already proved nest runs in POST-EXEC.
  static std::atomic<uint32_t> s_preplaceNest{0};
  const uint32_t nestN = s_preplaceNest.fetch_add(1) + 1;
  if (nestN <= 4 && g_mclaRebaseCount > 0)
  {
    uint32_t scanned = 0, nested = 0;
    for (int i = 0; i < g_mclaRebaseCount; ++i)
    {
      const uint32_t pbase = g_mclaRebaseMap[i].pbase;
      const uint32_t size = g_mclaRebaseMap[i].size;
      if (pbase == 0 || size < 4 || size > 0x400000u)
        continue;
      for (uint32_t off = 0; off + 4 <= size; off += 4)
      {
        uint32_t v = 0;
        if (!mem.ReadU32BE(pbase + off, &v))
          break;
        ++scanned;
        if (!MclaIsPstreamVirtual(v))
          continue;
        const uint32_t np = rebasePtr(v);
        if (np != v)
        {
          (void)mem.WriteU32BE(pbase + off, np);
          ++nested;
        }
      }
    }
    MCLA_LOG_WARN("RSC-NEST-PREPLACE #{} obj={:08X} scanned={} nested={}",
                  nestN, obj, scanned, nested);
  }
  MCLA_LOG_WARN("RSC-REBASE-PREPLACE-DONE obj={:08X} nmap={} "
                "headRewritten={} childRebased={} childGate={} nestPass={}",
                obj, g_mclaRebaseCount, headRewritten, childRebased, childGate,
                nestN);
}
// w10: shared job #2 package cursor (file offset into xarchive_cache.rpf).
// Both the CORRUPT-path (s_seqOff) and EMPTY-path host-serve must walk the
// SAME continuation; restarting at 0xA0000 re-fed the RSC5 head mid-stream
// and starved B79B1000/B7B61000/B7B71000 (arr stayed CDCD → RSC-PLACE-SKIP).
static std::mutex g_job2WalkMtx;
static uint32_t g_job2Walk = 0;      // bytes past package base 0xA0000
static uint32_t g_job2WalkBase = 0;  // package base (0xA0000 for job #2)
// w10: deferred place-pass. Job #2 POST-EXEC often runs before B7B61000
// inflates; RSC-PLACE-SKIP then leaves swfC unconstructed. When a later
// inflate sighting shows the need-data dest live, re-run 825EF100.
static std::atomic<uint32_t> g_placeDeferred{0};
static uint32_t g_placeObj = 0xB7B41000u;

// w21: shared package walk for job #2 UI dests. REQDUMP #2 is one UI package
// streamed into sequential physical dests (vbase 0x50000000 → B7B41000,
// 0x50020000 → B7981000, …). Per-dest walk starting every dest at package+0
// fed identical heads; this cursor walks 0xA0000 in PSTREAM order.
static std::mutex g_job2SharedMtx;
static uint32_t g_job2SharedWalk = 0;
static std::mutex g_j2ServedMtx;
static std::unordered_map<uint32_t, uint32_t> g_j2ServedCnt;

// w21: pin a dest to its per-dest RSC5 package (job #2 UI → 0xA0000 via the
// existing PKG-SUBST / AssignPackageForDest table), load a plaintext window,
// prime inflate st+0/st+4 at the guest-heap bounce, record LastServe, and
// optionally host-inflate into the dest so B7B41000 family gets real payload.
// Does not write page-cache slot+4. Does not invent vtables.
static uint32_t MclaDestCapFromPstream(uint32_t dest) {
  // Known job #2 UI dest sizes from w20 REQDUMP #2 / BUDDY76-ALLOC.
  switch (dest) {
  case 0xB7B41000u:
  case 0xB7981000u:
  case 0xB79A1000u:
    return 0x20000u;
  case 0xB7B61000u:
  case 0xB79C1000u:
    return 0x10000u;
  case 0xB7B71000u:
    return 0x8000u;
  default:
    return 0x20000u;
  }
}

static bool MclaHostInflateToDest(uint32_t dest, uint32_t bounce, uint32_t n,
                                  uint32_t destCap) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // w30: NEVER host-inflate over guest-owned place/rsc dest.
  if (MclaDestGuestOwned(mem, dest)) {
    uint32_t h0 = 0;
    (void)mem.ReadU32BE(dest, &h0);
    MCLA_LOG_WARN("W30-GATE-HOSTINF dest={:08X} head={:08X} — guest-owned",
                  dest, h0);
    return false;
  }
  auto *fn = mcla::kernel::g_memory.FindFunction(0x821D5E10u);
  if (!fn || !bounce || !dest || !n || dest == 0xCDCDCDCDu)
    return false;
  static std::mutex s_stMtx;
  static uint32_t s_st = 0;
  static uint32_t s_infStack = 0;
  std::lock_guard<std::mutex> lk(s_stMtx);
  if (s_st == 0)
    s_st = mem.Alloc(64, 16);
  if (s_infStack == 0) {
    const uint32_t raw = mem.Alloc(0x400, 16);
    s_infStack = raw ? (raw + 0x300u) : 0u;
  }
  if (!s_st)
    return false;
  uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
  (void)mem.ReadU32BE(bounce + 0, &w0);
  (void)mem.ReadU32BE(bounce + 4, &w1);
  (void)mem.ReadU32BE(bounce + 12, &w2);
  (void)mem.ReadU32BE(bounce + 16, &w3);
  uint32_t expected = destCap ? destCap : 0x20000u;
  uint32_t inPtr0 = bounce;
  uint32_t inN = n;
  if (w0 == 0x05435352u && w2 == 0x0FF512EFu) {
    inPtr0 = bounce + 12;
    inN = (n > 12u) ? (n - 12u) : n;
    if (w3 > 16u && w3 < 0x400000u)
      expected = w3;
  } else if (w0 == 0x0FF512EFu) {
    if (w1 > 16u && w1 < 0x400000u)
      expected = w1;
  }
  if (expected > 0x80000u)
    expected = 0x80000u;
  if (destCap && expected > destCap)
    expected = destCap;
  (void)mem.WriteU32BE(s_st + 0, inN);
  (void)mem.WriteU32BE(s_st + 4, inPtr0);
  (void)mem.WriteU32BE(s_st + 8, 0);
  (void)mem.WriteU32BE(s_st + 12, expected);
  (void)mem.WriteU32BE(s_st + 16, destCap ? destCap : expected);
  (void)mem.WriteU32BE(s_st + 20, dest);
  (void)mem.WriteU32BE(s_st + 24, 0);
  PPCContext pctx{};
  pctx.r1.u64 = s_infStack ? s_infStack : 0x006D8EC0u;
  pctx.r13.u64 = 0x8F200000u;
  pctx.r4.u64 = s_st;
  pctx.r3.u64 = 0;
  pctx.lr = 0x821BC380u;
  MCLA_LOG_WARN("HOST-INFLATE dest={:08X} st={:08X} bounce={:08X} n={} "
                "inPtr={:08X} inN={} expected={} destCap={}",
                dest, s_st, bounce, n, inPtr0, inN, expected, destCap);
  fn(pctx, mcla::kernel::g_memory.base);
  uint32_t dh[4] = {0, 0, 0, 0};
  uint32_t produced = 0, outLeft = 0;
  (void)mem.ReadU32BE(dest + 0, &dh[0]);
  (void)mem.ReadU32BE(dest + 4, &dh[1]);
  (void)mem.ReadU32BE(dest + 8, &dh[2]);
  (void)mem.ReadU32BE(dest + 12, &dh[3]);
  (void)mem.ReadU32BE(s_st + 24, &produced);
  (void)mem.ReadU32BE(s_st + 16, &outLeft);
  MCLA_LOG_WARN("HOST-INFLATE-DONE dest={:08X} head=[{:08X} {:08X} {:08X} "
                "{:08X}] produced={} outLeft={}",
                dest, dh[0], dh[1], dh[2], dh[3], produced, outLeft);
  return dh[0] != 0xCDCDCDCDu && dh[0] != 0 && dh[0] != 0xFFFFFFFFu;
}

static bool MclaForceServePkgForDest(uint32_t outPtr, uint32_t st,
                                     bool hostInflate) {
  if (outPtr == 0 || outPtr == 0xCDCDCDCDu)
    return false;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t baseOff = AssignPackageForDest(outPtr);
  const bool job2 = IsJob2UiDest(outPtr);
  uint32_t walkPos = 0;
  if (job2) {
    std::lock_guard<std::mutex> wl(g_job2SharedMtx);
    walkPos = g_job2SharedWalk;
  } else {
    std::lock_guard<std::mutex> wl(g_destPkgMtx);
    walkPos = g_destPkgWalk[outPtr];
  }
  std::vector<uint8_t> pkgWin;
  if (!MclaLoadPkgWindow(baseOff, walkPos, 0x8000u, pkgWin) ||
      pkgWin.size() < 16) {
    // Retry from package head if the shared walk ran past the table size.
    if (walkPos != 0) {
      pkgWin.clear();
      if (!MclaLoadPkgWindow(baseOff, 0, 0x8000u, pkgWin) ||
          pkgWin.size() < 16)
        return false;
      walkPos = 0;
      if (job2) {
        std::lock_guard<std::mutex> wl(g_job2SharedMtx);
        g_job2SharedWalk = 0;
      }
    } else {
      return false;
    }
  }
  // w25: continuation window whose head is not RSC5/XC cannot be inflated
  // independently — reset job2 shared walk to the package head so guest
  // InflateStep sees a decodable stream (w24 proven path).
  // F-248 probe (gated by kPathBEnqueueUI): this reset is what thrashes the
  // SHARED g_job2SharedWalk back to 0 on every legitimate LZX continuation frame
  // (compressed bytes, no RSC5 head by design), so each job2 dest re-serves the
  // package head forever (w247 B7841000 produced=16384 loop, JOB2-PKG-RESET ×14).
  // A mid-stream continuation does NOT need an RSC5 head, so SKIP the reset when the
  // serve-framing stack is on and let the walk advance. Flag OFF == exact baseline.
  if (!kPathBEnqueueUI && job2 && walkPos > 0 && pkgWin.size() >= 4) {
    const uint32_t wh = MclaBE(pkgWin.data());
    if (wh != 0x05435352u && wh != 0x0FF512EFu) {
      pkgWin.clear();
      if (!MclaLoadPkgWindow(baseOff, 0, 0x8000u, pkgWin) ||
          pkgWin.size() < 16)
        return false;
      walkPos = 0;
      {
        std::lock_guard<std::mutex> wl(g_job2SharedMtx);
        g_job2SharedWalk = 0;
      }
      MCLA_LOG_WARN("JOB2-PKG-RESET dest={:08X} — continuation head not "
                    "RSC5/XC, re-serve package head",
                    outPtr);
    }
  }
  static std::mutex s_bounceMtx;
  static std::unordered_map<uint32_t, uint32_t> s_destBounce;
  uint32_t bounce = 0;
  {
    std::lock_guard<std::mutex> bl(s_bounceMtx);
    bounce = s_destBounce[outPtr];
    if (bounce == 0) {
      bounce = mem.Alloc(0x8000, 16);
      s_destBounce[outPtr] = bounce;
    }
  }
  if (!bounce)
    return false;
  const uint32_t n = static_cast<uint32_t>(pkgWin.size());
  if (!mem.WriteBytes(bounce, pkgWin.data(), n))
    return false;
  const uint32_t head = MclaBE(pkgWin.data());
  const uint32_t destCap = MclaDestCapFromPstream(outPtr);

  // Prime inflate state at the guest-heap package walk (never stack).
  // Fresh package window → consumed=0 so the decoder sees the head.
  if (st && st != 0xCDCDCDCDu) {
    (void)mem.WriteU32BE(st + 0, n);
    (void)mem.WriteU32BE(st + 4, bounce);
    (void)mem.WriteU32BE(st + 8, 0);
    if (job2 && destCap) {
      uint32_t stOut = 0;
      (void)mem.ReadU32BE(st + 20, &stOut);
      if (stOut == 0 || stOut == 0xCDCDCDCDu || stOut == outPtr)
        (void)mem.WriteU32BE(st + 20, outPtr);
      uint32_t stOl = 0;
      (void)mem.ReadU32BE(st + 16, &stOl);
      if (stOl == 0 || stOl == 0xCDCDCDCDu || stOut == outPtr)
        (void)mem.WriteU32BE(st + 16, destCap);
    }
  }

  // Stack dest → head only (w20: 32KB write smashes the guest frame).
  // Heap dest → do NOT plant package bytes into the dest body. w21 soak:
  // planting continuation windows made place-pass walk 16E3C617 as a
  // resource pointer → FATAL-SOFT Resource at 8260A8B0. Delivery is
  // LastServe + st re-point + guest inflater; dest body stays guest-owned.
  if (outPtr < 0xA0000000u) {
    const uint32_t plant = (n > 256u) ? 256u : n;
    (void)mem.WriteBytes(outPtr, pkgWin.data(), plant);
  }

  if (job2) {
    std::lock_guard<std::mutex> wl(g_job2SharedMtx);
    g_job2SharedWalk = walkPos + n;
    std::lock_guard<std::mutex> dl(g_destPkgMtx);
    g_destPkgWalk[outPtr] = walkPos + n;
    g_destPkgOff[outPtr] = baseOff;
  } else {
    std::lock_guard<std::mutex> wl(g_destPkgMtx);
    g_destPkgWalk[outPtr] = walkPos + n;
  }

  MclaLastServe ls;
  ls.sbuf = bounce;
  ls.pos = 0;
  ls.size = n;
  ls.stCand = st;
  ls.dest = outPtr;
  ls.want = n;
  ls.srcPkg = baseOff;
  ls.path = job2 ? "job2-ui-pkg" : "dest-pkg";
  ls.head = head;
  MclaRecordLastServe(ls);

  bool inflated = false;
  // w21: host-inflate via FindFunction(821D5E10/InflateBegin) fatals
  // 0x80004005 even with XC magic (needs a real inflater object in r3).
  // Disabled — package plant + LastServe + REFORCE carry delivery.
  (void)hostInflate;
  inflated = false;

  uint32_t dh[4] = {0, 0, 0, 0};
  (void)mem.ReadU32BE(outPtr + 0, &dh[0]);
  (void)mem.ReadU32BE(outPtr + 4, &dh[1]);
  (void)mem.ReadU32BE(outPtr + 8, &dh[2]);
  (void)mem.ReadU32BE(outPtr + 12, &dh[3]);
  uint32_t servedN = 0;
  {
    std::lock_guard<std::mutex> jl(g_j2ServedMtx);
    servedN = ++g_j2ServedCnt[outPtr];
  }
  MCLA_LOG_WARN("JOB2-PKG-SERVE #{} dest={:08X} st={:08X} pkg={:08X} "
                "walk={:08X} bounce={:08X} n={} head={:08X} destCap={} "
                "hostInflate={} inflated={} destHead=[{:08X} {:08X} {:08X} "
                "{:08X}]",
                servedN, outPtr, st, baseOff, walkPos, bounce, n, head,
                destCap, hostInflate ? 1 : 0, inflated ? 1 : 0, dh[0], dh[1],
                dh[2], dh[3]);
  return true;
}

// F-320: a UI .xsf inflate STREAM is not one dest. w281 shows the guest walking
// its own readlist slot by slot — `PSTREAM #1` is a contiguous virtual range
// (s[3..9]: vbase 60000000/60020000/60040000/60060000/60080000/600A0000/600C0000
// with size 20000,20000,20000,20000,20000,20000,10000, and vbase(k+1) ==
// vbase(k)+size(k) exactly) over physical slots B7B41000, B7A01000, B7A21000,
// B7A41000, B7A61000, B7A81000, B7AA1000 — and `INFLATE-ENTER` follows it:
// #32..#40 on B7A41000 (consumed 32,748→163,820), then **#58 onward on B7A61000
// carrying consumed=196,553 forward**, then B7A81000, then B7AA1000. Only the
// FIRST slot ever gets a `DEST-PKG` mapping, so a dest-keyed cursor stops dead
// at the slot boundary — that, not output capacity, is what ended F-318's run.
// The cursor therefore has to live on the inflate state `st` (which IS the
// stream), with the dest mapping consulted when it exists.
static std::mutex g_uiXsfStreamMtx;
static std::unordered_map<uint32_t, uint32_t> g_uiXsfStreamPkg;   // st -> pkg
static std::unordered_map<uint32_t, uint32_t> g_uiXsfStreamWalk;  // st -> bytes delivered
// F-327: package offset of the NEXT frame header for this inflate state. 0 means
// "not started" -> the container header occupies pkg+0..19, so the first frame
// begins at 20 (the guest is served from pkg+0 and skips the header itself).
static std::unordered_map<uint32_t, uint32_t> g_uiXsfStreamFrame;

// Which UI .xsf package (0 = none) is this inflate state streaming? A dest that
// IS mapped settles it authoritatively — including NEGATIVELY: a dest mapped to
// a non-UI package proves this `st` has moved on to another family, so the
// binding is dropped rather than trusted. Only an UNMAPPED dest (a successor
// slot, which never gets a mapping) consults the stream binding.
static uint32_t MclaUiXsfStreamPkg(uint32_t st, uint32_t outPtr) {
  const uint32_t pkg = PeekPackageForDest(outPtr);
  std::lock_guard<std::mutex> lk(g_uiXsfStreamMtx);
  if (pkg != 0) {
    if (IsUiXsfPkg(pkg)) {
      g_uiXsfStreamPkg[st] = pkg;
      return pkg;
    }
    g_uiXsfStreamPkg.erase(st);
    g_uiXsfStreamWalk.erase(st);
    return 0u;
  }
  const auto it = g_uiXsfStreamPkg.find(st);
  return it == g_uiXsfStreamPkg.end() ? 0u : it->second;
}

// F-321: PackageSizeAt() answers the fabricated **0x40000 fallback** for any
// package absent from g_rscTab, and garage (unc 1,066,057) is absent — which is
// exactly where F-320's stream stopped (294,912 − 32,748 = 262,164 ≈ 0x40000)
// with three readlist slots still unfilled. The container's own header is the
// honest source: RSC5 `+0x10` is the uncompressed length, and an LZX stream is
// never longer than what it expands to, so `unc` is a safe ceiling for the input
// walk. OFF == the old fabricated bound byte-for-byte.
static constexpr bool kUiXsfBoundUnc = true;

// The container's own declared uncompressed length (RSC5 header +0x10, BE),
// cached per package. 0 when the header is missing or implausible.
static uint32_t MclaUiXsfUnc(uint32_t pkg) {
  static std::mutex s_uncMtx;
  static std::unordered_map<uint32_t, uint32_t> s_unc;
  std::lock_guard<std::mutex> lk(s_uncMtx);
  const auto it = s_unc.find(pkg);
  if (it != s_unc.end())
    return it->second;
  uint32_t unc = 0;
  uint8_t hdr[20] = {0};
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  uint64_t got = 0;
  if (vfs.OpenFile("xarchive_cache.rpf", fh)) {
    const bool ok = vfs.ReadFileAt(fh, pkg, hdr, 20, got) && got >= 20;
    vfs.CloseFile(fh);
    const uint32_t magic = MclaBE(hdr);
    const uint32_t v = MclaBE(hdr + 0x10);
    if (ok && (magic == 0x05435352u || magic == 0x0FF512EFu) && v >= 0x100u &&
        v <= 0x800000u)
      unc = v;
  }
  return s_unc.emplace(pkg, unc).first->second;
}

static uint32_t MclaUiXsfWalkCeil(uint32_t pkg) {
  const uint32_t pkgSz = PackageSizeAt(pkg);
  if (!kUiXsfBoundUnc)
    return pkgSz;
  static std::mutex s_ceilMtx;
  static std::unordered_map<uint32_t, uint32_t> s_ceil;
  std::lock_guard<std::mutex> lk(s_ceilMtx);
  const auto it = s_ceil.find(pkg);
  if (it != s_ceil.end())
    return it->second;
  uint32_t ceil = pkgSz;
  uint8_t hdr[24] = {0};
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  uint64_t got = 0;
  if (vfs.OpenFile("xarchive_cache.rpf", fh)) {
    const bool ok = vfs.ReadFileAt(fh, pkg, hdr, 24, got) && got >= 24;
    vfs.CloseFile(fh);
    const uint32_t magic = MclaBE(hdr);
    const uint32_t unc = MclaBE(hdr + 0x10);
    if (ok && (magic == 0x05435352u || magic == 0x0FF512EFu) && unc >= 0x100u &&
        unc <= 0x800000u) {
      ceil = unc + 0x8000u;
      if (ceil < pkgSz)
        ceil = pkgSz;
    }
  }
  s_ceil[pkg] = ceil;
  return ceil;
}

// F-321: how full is a UI .xsf slot when the stream retires it?
// XMEM-UIHEAD dumps on the FIRST call for a dest, so it reads a window that is
// about to be filled — that is why w283 shows B7A41000 as all-poison and says
// nothing about its end state. This measures coverage at the retirement sites
// instead: non-poison, non-zero words over the first 4 KiB (max 1024). Log-only.
static uint32_t MclaUiXsfSlotCov(uint32_t dest) {
  if (dest == 0 || dest == 0xCDCDCDCDu || !IsUiXsfPkg(PeekPackageForDest(dest)))
    return 0xFFFFFFFFu;  // not a UI .xsf dest: caller must not print
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t nz = 0;
  for (uint32_t off = 0; off + 4 <= 0x1000u; off += 4) {
    uint32_t word = 0;
    if (!mem.IsValid(dest + off, 4) || !mem.ReadU32BE(dest + off, &word))
      break;
    if (word != 0xCDCDCDCDu && word != 0u)
      ++nz;
  }
  return nz;
}

// F-327: parse one entry of a UI .xsf container's own frame table. The layout is
// copied from the validated offline decoder (`src/xmem_lzx.h:531-552`): frames
// start at pkg+0x14, each with a 2-byte header {uncomp fixed at 0x8000, pay as
// be16} or the escape 0xFF followed by {uncomp be16, pay be16} for five bytes.
// Returns false if the header cannot be read or the payload size is not
// plausible, in which case the caller must fall back to the legacy stride.
static bool MclaUiXsfFrameAt(uint32_t pkg, uint32_t pos, uint32_t &hdrLen,
                             uint32_t &payLen, uint32_t &uncLen) {
  hdrLen = payLen = uncLen = 0;
  if (pos >= 0x4000000u)
    return false;
  uint8_t h[5] = {0};
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  uint64_t got = 0;
  bool ok = false;
  if (vfs.OpenFile("xarchive_cache.rpf", fh)) {
    ok = vfs.ReadFileAt(fh, pkg + pos, h, 5, got) && got >= 5;
    vfs.CloseFile(fh);
  }
  if (!ok)
    return false;
  if (h[0] == 0xFF) {
    hdrLen = 5;
    uncLen = (static_cast<uint32_t>(h[1]) << 8) | h[2];
    payLen = (static_cast<uint32_t>(h[3]) << 8) | h[4];
  } else {
    hdrLen = 2;
    uncLen = 0x8000u;
    payLen = (static_cast<uint32_t>(h[0]) << 8) | h[1];
  }
  return payLen > 0u && payLen <= 0x8000u && uncLen > 0u && uncLen <= 0x8000u;
}

// F-334: locate the stream's current guest buffer inside its own package image.
// Log-only; see the kUiXsfLocate comment for what question this answers. The
// needle is 16 bytes (a whole 48-byte run can legitimately diverge if the guest
// re-used part of the buffer), and the scan is a byte prefilter over 64 KiB
// chunks, so a miss costs microseconds rather than a stalled boot.
static void MclaUiXsfLocateStream(uint32_t st, uint32_t pkg, uint32_t inPtr,
                                  uint32_t inLeft, uint32_t walkPos) {
  static std::mutex s_locMtx;
  static std::unordered_map<uint32_t, uint32_t> s_locSeen;
  uint32_t nth = 0;
  {
    std::lock_guard<std::mutex> lk(s_locMtx);
    nth = ++s_locSeen[st];
  }
  if (nth > 6u || pkg == 0u)
    return;
  // The interesting moment is inLeft == 0 — that is when the serve fires — and
  // then there is nothing left IN the buffer to search. So take the needle from
  // the last 16 bytes the guest actually consumed (the 16 ending at inPtr) and
  // carry the offset forward to inPtr+inLeft. w309 proved this the hard way:
  // the first version required inLeft >= 16 and therefore printed nothing at
  // all, which is the same zero-with-no-printer error F-057(6) warns about.
  const uint32_t nbase = inLeft >= 16u ? inPtr : (inPtr - 16u);
  if (inPtr < 0x1000u) {
    MCLA_LOG_WARN("UIXSF-LOCATE #{} st={:08X} pkg={:08X} inPtr={:08X} "
                  "inLeft={} — NOT SEARCHABLE",
                  nth, st, pkg, inPtr, inLeft);
    return;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  std::vector<uint8_t> head(16, 0);
  if (!mem.IsValid(nbase, 16) || !mem.ReadBytes(nbase, head.data(), 16)) {
    MCLA_LOG_WARN("UIXSF-LOCATE #{} st={:08X} pkg={:08X} nbase={:08X} "
                  "NEEDLE UNREADABLE walk={:08X}",
                  nth, st, pkg, nbase, walkPos);
    return;
  }
  bool dead = true;
  for (uint8_t b : head)
    if (b != 0x00u && b != 0xCDu)
      dead = false;
  if (dead) {
    MCLA_LOG_WARN("UIXSF-LOCATE #{} st={:08X} pkg={:08X} nbase={:08X} "
                  "NEEDLE DEAD (zero/poison) walk={:08X}",
                  nth, st, pkg, nbase, walkPos);
    return;
  }
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  if (!vfs.OpenFile("xarchive_cache.rpf", fh)) {
    MCLA_LOG_WARN("UIXSF-LOCATE #{} st={:08X} RPF NOT OPENABLE", nth, st);
    return;
  }
  const uint32_t chunk = 0x10000u;
  std::vector<uint8_t> win(chunk + 16);
  uint32_t found = 0xFFFFFFFFu;
  for (uint32_t off = 0; off < 0x400000u && found == 0xFFFFFFFFu; off += chunk) {
    uint64_t got = 0;
    if (!vfs.ReadFileAt(fh, pkg + off, win.data(), win.size(), got) ||
        got < head.size())
      break;
    for (uint64_t i = 0; i + head.size() <= got; ++i) {
      if (win[i] == head[0] &&
          std::memcmp(win.data() + i, head.data(), head.size()) == 0) {
        found = off + static_cast<uint32_t>(i);
        break;
      }
    }
  }
  vfs.CloseFile(fh);
  if (found == 0xFFFFFFFFu) {
    MCLA_LOG_WARN("UIXSF-LOCATE #{} st={:08X} pkg={:08X} inPtr={:08X} "
                  "inLeft={} walk={:08X} → NOT IN PACKAGE (scanned 4 MB)",
                  nth, st, pkg, inPtr, inLeft, walkPos);
    return;
  }
  // If our bookkeeping agrees with the guest's buffer, then the byte at
  // inPtr+inLeft is the byte at pkg+want, which is exactly what walkPos should
  // be right now. The needle started at nbase, so carry it forward to the end
  // of the guest's valid data.
  const uint32_t want = found + (inPtr + inLeft - nbase);
  MCLA_LOG_WARN("UIXSF-LOCATE #{} st={:08X} pkg={:08X} inPtr={:08X} inLeft={} "
                "nbase={:08X} found_at={:08X} want_walk={:08X} walk={:08X} "
                "AGREE={} delta={}",
                nth, st, pkg, inPtr, inLeft, nbase, found, want, walkPos,
                want == walkPos ? 1 : 0,
                static_cast<int64_t>(walkPos) - static_cast<int64_t>(want));
}

// F-335 (plan §5 step 1b): ONE append-only window per UI .xsf stream.
// F-332/F-333 together say the frame driver keeps absolute positions
// (`[S+12276]` saved cursor and `[S+12280]` byte offset into the current frame)
// and that they are the stream position, not stale junk — but the serve has
// always written each window over the SAME host buffer from offset 0 while
// `walkPos` advanced, so every absolute position the driver kept silently
// changed meaning between calls. This gives a stream one window sized for its
// whole container, fills it forward from the package and never rewrites a byte
// the driver has already seen; after the first install, only `st+0` (input
// remaining) moves. Returns true = handled, caller must not run the legacy path.
struct MclaUiXsfWin {
  uint32_t buf = 0, cap = 0, base = 0, fill = 0;
};
static std::mutex g_uiXsfWinMtx;
static std::unordered_map<uint32_t, MclaUiXsfWin> g_uiXsfWin;

static bool MclaUiXsfAppendServe(uint32_t n, uint32_t st, uint32_t pkg,
                                uint32_t walkPos, uint32_t inPtr,
                                uint32_t inLeft) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  std::lock_guard<std::mutex> lk(g_uiXsfWinMtx);
  MclaUiXsfWin &w = g_uiXsfWin[st];
  if (w.buf == 0u) {
    uint32_t c = MclaUiXsfWalkCeil(pkg);
    if (c < 0x10000u)
      c = 0x10000u;
    if (c > 0x400000u)
      c = 0x400000u;
    w.buf = mem.Alloc(c, 16);
    if (w.buf == 0u) {
      MCLA_LOG_WARN("UIXSF-APPEND #{} st={:08X} ALLOC FAILED cap={}", n, st, c);
      w.buf = 0;
      return false;
    }
    w.cap = c;
    w.base = walkPos;
    w.fill = 0;
    MCLA_LOG_WARN("UIXSF-APPEND #{} st={:08X} pkg={:08X} OPENED buf={:08X} "
                  "cap={} base={:08X}",
                  n, st, pkg, w.buf, w.cap, w.base);
  }
  if (walkPos < w.base || walkPos > w.base + w.cap) {
    MCLA_LOG_WARN("UIXSF-APPEND #{} st={:08X} walk={:08X} OUTSIDE window "
                  "base={:08X} cap={} — legacy path",
                  n, st, walkPos, w.base, w.cap);
    return false;
  }
  const uint32_t have = walkPos - w.base;  // bytes of the window already consumed
  if (have > w.fill) {
    MCLA_LOG_WARN("UIXSF-APPEND #{} st={:08X} GAP have={} filled={} — legacy",
                  n, st, have, w.fill);
    return false;
  }
  uint32_t got = 0;
  if (w.fill < w.cap) {
    auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
    mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
    const uint32_t want =
        w.cap - w.fill < 0x10000u ? w.cap - w.fill : 0x10000u;
    std::vector<uint8_t> tmp(want);
    uint64_t g64 = 0;
    if (vfs.OpenFile("xarchive_cache.rpf", fh)) {
      const bool okf =
          vfs.ReadFileAt(fh, pkg + w.base + w.fill, tmp.data(), want, g64);
      vfs.CloseFile(fh);
      if (okf && g64 > 0 &&
          mem.WriteBytes(w.buf + w.fill, tmp.data(),
                         static_cast<uint32_t>(g64)))
        got = static_cast<uint32_t>(g64);
    }
    w.fill += got;
  }
  // Where is the guest inside the window? First install sets st+4 once; after
  // that the pointer is the guest's own and must not be touched again.
  const bool inside = inPtr >= w.buf && (inPtr - w.buf) < w.cap && inLeft <= w.cap;
  const uint32_t pos = inside ? (inPtr - w.buf) : have;
  const uint32_t room = w.fill > pos ? w.fill - pos : 0u;
  if (!inside)
    (void)mem.WriteU32BE(st + 4, w.buf + have);
  (void)mem.WriteU32BE(st + 0, room);
  MCLA_LOG_WARN("UIXSF-APPEND #{} st={:08X} pkg={:08X} walk={:08X} pos={} "
                "appended={} filled={} inLeft={} st0={} re-pointed={}",
                n, st, pkg, walkPos, pos, got, w.fill, inLeft, room,
                inside ? 0 : 1);
  return true;
}

// Is this UI .xsf stream still short of its package end? Keys on the stream
// cursor (max of the dest's own walk and the stream's), bounded by
// MclaUiXsfWalkCeil, so it cannot spin past the package: MclaLoadPkgWindow only
// fails at walk >= pkgSz + 4 MB, which for a default-sized (0x40000) package
// would mean ~130 re-serves of past-the-end bytes before it stopped on its own.
static bool MclaUiXsfChunkOpen(uint32_t st, uint32_t outPtr) {
  const uint32_t pkg = MclaUiXsfStreamPkg(st, outPtr);
  if (pkg == 0)
    return false;
  uint32_t walk = 0;
  {
    std::lock_guard<std::mutex> wl(g_destPkgMtx);
    const auto it = g_destPkgWalk.find(outPtr);
    if (it != g_destPkgWalk.end())
      walk = it->second;
  }
  {
    std::lock_guard<std::mutex> lk(g_uiXsfStreamMtx);
    const auto it = g_uiXsfStreamWalk.find(st);
    if (it != g_uiXsfStreamWalk.end() && it->second > walk)
      walk = it->second;
  }
  return walk < MclaUiXsfWalkCeil(pkg);
}

// F-321: coverage says a slot is *occupied*; this says whether it holds the RIGHT
// bytes. The Path A decoder is byte-exact offline and in-boot for these packages
// (F-299 proved full-buffer equality for 3 of 4), so its output for a package IS a
// golden image of the container. Re-derive it once per package, locate the slot's
// first 64 bytes inside it, then compare forward — which answers the objective's
// actual question ("is the .xsf decompressed in guest memory") for dests the GUEST
// filled, not just the ones the host wrote. Log-only: no guest state is touched.
static constexpr bool kUiXsfVerify = true;

// Golden bytes for a UI .xsf package, decoded once and cached. Empty means the
// decode failed and no verdict from this package is admissible.
static const std::vector<uint8_t> &MclaUiXsfGolden(uint32_t pkg) {
  static std::mutex s_gMtx;
  static std::unordered_map<uint32_t, std::vector<uint8_t>> s_golden;
  std::lock_guard<std::mutex> glk(s_gMtx);
  const auto it = s_golden.find(pkg);
  if (it != s_golden.end())
    return it->second;
  std::vector<uint8_t> dec;
  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
  std::vector<uint8_t> raw(0x400000);
  uint64_t got = 0;
  int hp = 0;
  if (vfs.OpenFile("xarchive_cache.rpf", fh)) {
    const bool rd =
        vfs.ReadFileAt(fh, pkg, raw.data(), 0x400000, got) && got >= 24;
    vfs.CloseFile(fh);
    if (rd)
      hp = mcla_lzx::host_decode_ui_xsf(raw.data(), static_cast<size_t>(got),
                                        dec, kXcWindowBits);
  }
  if (!hp)
    dec.clear();
  return s_golden.emplace(pkg, std::move(dec)).first->second;
}

// F-322: WHERE did the guest put the container bytes past the one window F-321
// verified? w285 measured pkg 64980000 consuming 294,912 input bytes while only
// container offset 0..0x8000 matched anywhere the FLUSH census named. Rather
// than guess more dests, search the golden for the physical slots the host
// rebase map currently holds and report which container offset each one holds,
// with a forward byte-compare. One-shot verdict per slot; the hunt runs at
// several shots per package because the map is reset per job2 (F-252) and grows
// as jobs are enqueued.
static constexpr bool kUiXsfHunt = true;

// Slot inventory for the hunt, filled from the SAME guest structure the PSTREAM
// census reads: the {vbase,pbase,size} triplet array at ctxBase+4+si*12. The
// first version iterated `g_mclaRebaseMap` instead and w287 printed
// `nmap=0 anchor_in_map=0` for every package — including raceeditor, whose dest
// the same boot had just proved byte-exact. A zero that contradicts a known-true
// fact is an instrument failure, and the anchor field is what caught it.
// Accumulated across jobs (deduped, capped) because F-322 asks "in ANY slot",
// not "in this job's slots".
struct MclaUiXsfSlot {
  uint32_t job;   // which readlist announced it (PSTREAM #n)
  uint32_t seq;   // its index inside that readlist
  uint32_t vbase;
  uint32_t pbase;
  uint32_t size;
};
static std::mutex g_uiXsfSlotsMtx;
static std::vector<MclaUiXsfSlot> g_uiXsfSlots;

// F-324: what the fill CLAIMED, in (dest, golden-range) terms, so a later pass
// can prove the bytes are STILL there instead of trusting the write call's
// return. `gold_span` only ever reported what we asked to be written; the guest
// inflates into the same slots, so presence has to be re-read.
struct MclaUiXsfFillRec {
  uint32_t pkg, pbase, off, len;
};
static std::mutex g_uiXsfFillLogMtx;
static std::vector<MclaUiXsfFillRec> g_uiXsfFillLog;

static void MclaUiXsfNoteSlot(uint32_t job, uint32_t seq, uint32_t vbase,
                              uint32_t pbase, uint32_t size) {
  if (pbase < 0xB0000000u || pbase >= 0xC0000000u || size < 64)
    return;
  std::lock_guard<std::mutex> lk(g_uiXsfSlotsMtx);
  if (g_uiXsfSlots.size() >= 128)
    return;
  for (const auto &e : g_uiXsfSlots)
    if (e.pbase == pbase)
      return;
  g_uiXsfSlots.push_back({job, seq, vbase, pbase, size});
}

// `anchor` is the dest the caller just got a byte-exact (or at least named)
// verdict for. Reporting whether that dest is even IN the map is the hunt's own
// control: w286's first version printed slots_matched=0 for all four packages,
// including raceeditor whose dest UIXSF-SLOT-VERIFY had just proved byte-exact —
// a zero that contradicts a known-true fact is an instrument failure, not a
// finding, and this field is what tells the two apart.
// Defined below; called at the end of every hunt so the NEXT hunt reports
// whether the fill worked — that is the whole verification loop.
static void MclaUiXsfGoldenFill(uint32_t pkg, const std::vector<uint8_t> &gold,
                                const std::vector<MclaUiXsfSlot> &slots,
                                uint32_t shot);
static void MclaUiXsfLayoutAudit(uint32_t pkg, const std::vector<uint8_t> &gold,
                                 const std::vector<MclaUiXsfSlot> &slots,
                                 uint32_t anchorPbase);
static void MclaUiXsfReverify(uint32_t pkg, const std::vector<uint8_t> &gold,
                              uint32_t shot);

static void MclaUiXsfGoldenHunt(uint32_t pkg, uint32_t shot, uint32_t anchor) {
  const std::vector<uint8_t> &gold = MclaUiXsfGolden(pkg);
  if (gold.size() < 64)
    return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  static std::mutex s_huntMtx;
  static std::unordered_set<uint32_t> s_hunted;  // pkg*8 + shot
  {
    std::lock_guard<std::mutex> hlk(s_huntMtx);
    const uint32_t key = pkg * 8u + shot;
    if (s_hunted.count(key) || s_hunted.size() >= 64)
      return;
    s_hunted.insert(key);
  }
  // Snapshot the inventory so the scan never runs under its lock.
  std::vector<MclaUiXsfSlot> slots;
  {
    std::lock_guard<std::mutex> slk(g_uiXsfSlotsMtx);
    slots = g_uiXsfSlots;
  }
  // Fill BEFORE scanning, so this same hunt's slots_matched /
  // bytes_exactly_covered report the fill's effect instead of its preconditions
  // (w290 filled 819,200 bytes and still printed 0, because the scan had already
  // run). Each package is filled at most once per shot, so this cannot loop.
  MclaUiXsfGoldenFill(pkg, gold, slots, shot);
  MclaUiXsfLayoutAudit(pkg, gold, slots, anchor);
  MclaUiXsfReverify(pkg, gold, shot);
  uint32_t hits = 0, scanned = 0, skip_range = 0, skip_poison = 0,
           skip_read = 0;
  std::vector<std::pair<uint32_t, uint32_t>> runs;
  bool anchor_found = false;
  const int nmap = static_cast<int>(slots.size());
  for (int i = 0; i < nmap; ++i) {
    const uint32_t pb = slots[i].pbase;
    const uint32_t sz = slots[i].size;
    if (pb == anchor)
      anchor_found = true;  // the hunt's own control, checked before any skip
    if (pb < 0xB0000000u || pb >= 0xC0000000u || sz < 64) {
      ++skip_range;
      continue;
    }
    ++scanned;
    // F-323: the needle has to be 64 bytes, not 16. w291 printed goldoff=0 for
    // all four filled slots because this container's 0x40000 blocks share a
    // 16-byte head (`head=44495500` on every one), so a short needle resolves to
    // the FIRST such block and the reported offset was meaningless even though
    // the byte-compare beneath it was real.
    uint8_t head[64] = {0};
    if (!mem.ReadBytes(pb, head, 64)) {
      ++skip_read;
      continue;
    }
    const uint32_t h0 = MclaBE(head);
    if (h0 == 0xCDCDCDCDu || h0 == 0u || h0 == 0xFFFFFFFFu) {
      ++skip_poison;  // untouched slot
      continue;
    }
    uint32_t off = 0;
    bool found = false;
    while (off + 64 <= gold.size()) {
      if (gold[off] == head[0] &&
          std::memcmp(gold.data() + off, head, 64) == 0) {
        found = true;
        break;
      }
      ++off;
    }
    if (!found)
      continue;
    uint32_t cmp = sz;
    if (cmp > gold.size() - off)
      cmp = static_cast<uint32_t>(gold.size() - off);
    if (cmp > 0x80000u)
      cmp = 0x80000u;
    uint32_t mismatch = 0;
    std::vector<uint8_t> buf(0x4000);
    for (uint32_t done = 0; done < cmp; done += buf.size()) {
      const uint32_t want =
          cmp - done < buf.size() ? cmp - done
                                  : static_cast<uint32_t>(buf.size());
      if (!mem.ReadBytes(pb + done, buf.data(), want)) {
        mismatch = cmp - done;
        break;
      }
      for (uint32_t j = 0; j < want; ++j)
        if (buf[j] != gold[off + done + j])
          ++mismatch;
    }
    ++hits;
    if (mismatch == 0) {
      // Union, not sum: w292 printed bytes_exactly_covered=819200 as 4 slots
      // x their lengths, but the 64-byte needle resolved every one of them to
      // goldoff=0 because garage.xsf's decoded blocks repeat (all four heads are
      // 44495500), so summing double-counted the same golden range. Accumulating
      // [off, off+cmp) intervals and merging them makes this field report
      // DISTINCT container bytes present, which is the question.
      runs.push_back({off, off + cmp});
    }
    MCLA_LOG_WARN("UIXSF-GOLDEN-HUNT shot={} pkg={:08X} slot[{}]={:08X} "
                  "slotsize={} goldoff={:08X} compared={} mismatch={} "
                  "head={:08X}",
                  shot, pkg, i, pb, sz, off, cmp, mismatch, h0);
  }
  std::sort(runs.begin(), runs.end());
  uint32_t covered = 0;
  for (size_t r = 0; r < runs.size();) {
    const uint32_t lo = runs[r].first;
    uint32_t hi = runs[r].second;
    ++r;
    while (r < runs.size() && runs[r].first <= hi) {
      if (runs[r].second > hi)
        hi = runs[r].second;
      ++r;
    }
    covered += hi - lo;
  }
  MCLA_LOG_WARN("UIXSF-GOLDEN-HUNT-SUMMARY shot={} pkg={:08X} goldsize={} "
                "nmap={} scanned={} skip_range={} skip_poison={} skip_read={} "
                "slots_matched={} bytes_exactly_covered={} anchor={:08X} "
                "anchor_in_map={}",
                shot, pkg, static_cast<uint32_t>(gold.size()), nmap, scanned,
                skip_range, skip_poison, skip_read, hits, covered, anchor,
                anchor_found ? 1 : 0);
}

// F-323: NAMED MITIGATION, not a fix — the same mechanism class as the shipped
// `kPathBHostFullDecode` dest-write, extended from one dest to a slot run. The
// measurement that justifies it is F-322: the host has all 1,066,057 garage
// bytes byte-exact (`MclaUiXsfGolden`), the guest produced correct output for
// 32,768 of them and nothing anywhere else holds any other part, so the deficit
// is PLACEMENT in a container that spans several readlist slots. F-320
// established `vbase(k+1) == vbase(k)+size(k)`, i.e. a job's slots tile one
// contiguous virtual range, so the container's own virtual span is
// [anchorVbase, anchorVbase + goldenSize) and slot S holds
// golden[S.vbase - anchorVbase ..]. That mapping is the hypothesis under test —
// `UIXSF-GOLDEN-HUNT-SUMMARY bytes_exactly_covered` climbs toward goldsize or
// it does not, so this cannot quietly "look successful".
//
// Protections, in order of importance:
//  - only slots whose CURRENT content is entirely poison/zero are written, plus
//    the anchor itself (measured wrong past 0x8000), so the three containers
//    already at 100% cannot be touched;
//  - a slot must be mapped to THIS package or sit inside this package's virtual
//    span with a plausible vbase, and the anchor must be mapped to this package;
//  - bounded to one fill pass per package per shot index, and the whole thing is
//    one flag flip.
static constexpr bool kUiXsfGoldenFill = true;

static bool MclaSlotUntouched(uint32_t pbase, uint32_t size) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t span = size < 0x40u ? 0x40u : size;
  uint32_t seen = 0;
  for (uint32_t off = 0; off + 4 <= span && seen < 64u; off += (span / 64u + 4u)) {
    uint32_t w = 0;
    if (!mem.IsValid(pbase + off, 4) || !mem.ReadU32BE(pbase + off, &w))
      return false;
    ++seen;
    if (w != 0xCDCDCDCDu && w != 0u && w != 0xFFFFFFFFu)
      return false;  // has real content — never overwrite it
  }
  return seen > 0;
}

// F-324: list-order placement (see the comment at the plan builder). OFF == the
// F-323 span behaviour byte-for-byte.
static constexpr bool kUiXsfFillListOrder = true;

// F-327: serve the UI .xsf streams FRAME-ALIGNED instead of in fixed 0x8000
// slices. The container is a sequence of self-delimiting frames starting at
// pkg+0x14 (2-byte header {uncomp=0x8000, pay_be16}, or 0xFF + {uncomp,pay} for
// five bytes), each decoded by one shared decoder with 16-bit re-alignment --
// that is the recipe `src/xmem_lzx.h:527-552` validates byte-exact offline. The
// refill ignored it: it advanced by exactly 0x8000, so window 1 (pkg+0, 32,768
// B) carried the 20-byte container header + 2-byte frame header + 32,726 B of
// frame 0, which the guest consumed to `consumed=32,748` and turned into exactly
// one correct 32,768-byte output window (F-321 `firstbad=00008000`, F-326
// `first_bad=00008000`), and window 2 then started 20 bytes INSIDE frame 1. From
// there the guest reads a frame header that is payload, decodes nothing, and
// keeps eating input -- which is the whole 63,072-of-1,066,057 plateau.
//
// So the cursor is the FRAME TABLE, not a fixed stride: per inflate state,
// remember the package offset of the next frame header, serve exactly
// hdr+pay bytes, and stop at the end of the declared uncompressed length.
// F-327 RESULT: tried ON in w298/w299 and REVERTED. It does walk the frame
// table correctly (32 frame-sized serves, `off` advancing 64980000 -> 649A6F7A
// with per-frame sizes 9572/5206/3344/... instead of a fixed 0x8000), and the
// stream got further into the package than the fixed stride ever had — but the
// guest then STALLS on a partial frame with `inLeft` NONZERO
// (w299: `INFLATE-ENTER #20,364,800 st=006D8F20 in=2051 consumed=196553
// outPtr=B7A41000` at 20 MILLION inflate entries, 659,319 log lines vs w297's
// 57,866) and never reaches retirement, so the garage produced no verdict at all
// in the soak. Because inLeft != 0, the refill cannot even help: its trigger is
// an empty buffer. So the container's byte offsets were never the obstacle —
// the guest's per-call frame/outLeft accounting is, which is Path B's
// descriptor-construction side (task #15), not serve framing. Keep the parser
// and the cursor: they are what makes that side measurable.
// F-333 SUPERSEDES the paragraph above, and it is the latch that paragraph
// could not see: `inLeft` stayed 2,051 because the frame driver never touched
// our window at all — it resumed a stale mid-frame offset from the saved
// cursor (see kUiXsfClearResume), so it consumed nothing and our refill
// trigger (an EMPTY buffer) could not fire. Framing and the latch are one
// mechanism and must be tested as a pair.
// TESTED AS THAT PAIR IN w307 AND REVERTED: the latch really does clear (four
// UIXSF-RESUME-CLEAR lines walked the garage's own frame table at offsets 0,
// 0x2564, 0x39BA, 0x46CA with frames of 9,572/5,206/3,344/4,072 bytes), and the
// result was WORSE — garage coverage 63,072 → 43,732, INFLATE-ENTER 4,890 →
// 17,703, and ~89,000 failing frame decodes on the shared ctx. Reading that
// back: the decoder is a CONTINUOUS bit stream, so a window that starts on a
// container frame boundary is only correct if the driver's own resume offset
// and saved cursor agree with it. Moving `src` under it is wrong in both
// directions. The next step is therefore to stop moving `src` at all — see
// kUiXsfServeInPlace.
static constexpr bool kUiXsfFrameServe = false;  // F-343: re-reverted; F-333+F-343 twice now show frame-aligned serving with a cleared walk state loses sync

// F-326: DRY RUN builds the same plan and records the same claims but writes
// NOTHING, so `UIXSF-GOLDEN-REVERIFY` then reports how much of the container the
// GUEST put there by itself. That is the only admissible baseline for Path B:
// with the fill on, `still_present` conflates host placement and guest output,
// and F-325's 64.9 % is a mixture of the two.
// F-350: the conflation was the point while Path B was being measured, and Path B
// is now settled (F-346/F-347/F-348/F-349 excluded content, recognition and
// supply; the guest decodes exactly ten frames and no more). Deliverable (a) is
// "the container decompressed in guest memory", which for the other three
// containers is satisfied BY Path A writing the bytes itself
// (`PATHB-HOSTDECODE … wrote=143069 ok` + `PATHB-HOSTVERIFY … match=true`). The
// garage is the one oversized container that cannot use that single-shot path, so
// it is placed through the guest's requested dests (F-350 chunked fill) and the
// remainder through its own slot chain here. w341 measured why both are needed:
// the chunked fill placed 393,216 bytes and verified them present at write time,
// then the shared inflate record `st=006D8F20` was taken by another container
// (`exp=000073D7` = credits' 29,655 in entry #67) and the chain stopped at two
// dests, leaving 132,578 surviving of what was placed.
static constexpr bool kUiXsfFillDryRun = false;

// F-350: allow the plan to overwrite a slot that belongs to THIS container's own
// chain. `MclaSlotUntouched` was written to stop the host from clobbering another
// stream's live data, and it does that job — but applied to the container's own
// slots it protects the guest's failed partial decode instead, which is why the
// claim stopped at 458,752/1,066,057 (`w342` three FILL-SKIP lines at golden
// offsets 0x20000/0x40000/0x60000, with `first_bad=00020005` inside the same
// region). Guarded three ways in the use site: same job and sequence range (list
// order), not claimed as another package's completed dest, and not already equal
// to the golden bytes. `false` == w342 behaviour.
static constexpr bool kUiXsfFillOwnSlots = true;

// F-352: every coverage number this project has printed for the garage rests on
// an UNTESTED assumption: that the container's bytes continue into the next
// readlist slot (F-327 chose "list order" because vbase arithmetic dead-ended at
// 0xC8000). The alternative is that a slot's position in the container is its
// VBASE DELTA from the chain's first slot. The two models agree while slots are
// contiguous and equal-sized, and diverge exactly where they are not — job #1
// s[2] is 0x4000 among 0x10000/0x20000 neighbours and the table jumps from the
// 0x50000000 block to 0x60000000 at s[3], so this is measurable, not
// philosophical. Log-only; run it with `kUiXsfFillDryRun=true` so the bytes
// being compared are the GUEST's own output and not something we wrote (F-308:
// a marker that echoes our own mitigation is not a measurement).
static constexpr bool kUiXsfLayoutAudit = true;

static void MclaUiXsfLayoutAudit(uint32_t pkg, const std::vector<uint8_t> &gold,
                                 const std::vector<MclaUiXsfSlot> &slots,
                                 uint32_t anchorPbase) {
  if (!kUiXsfLayoutAudit || gold.size() < 0x10000u)
    return;
  static std::mutex s_auditMtx;
  static std::unordered_set<uint32_t> s_audited;
  {
    std::lock_guard<std::mutex> elk(s_auditMtx);
    if (!s_audited.insert(pkg).second)
      return;  // once per package per boot
  }
  int ai = -1;
  for (int i = 0; i < static_cast<int>(slots.size()); ++i)
    if (slots[i].pbase == anchorPbase) {
      ai = i;
      break;
    }
  if (ai < 0) {
    MCLA_LOG_WARN("UIXSF-LAYOUT-AUDIT pkg={:08X} anchor={:08X} NOT IN INVENTORY",
                  pkg, anchorPbase);
    return;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t job = slots[ai].job, vAnchor = slots[ai].vbase;
  std::vector<uint8_t> rb(0x1000u);
  uint32_t totA = 0, cmpA = 0, totB = 0, cmpB = 0, seq = 0, considered = 0;
  for (size_t i = static_cast<size_t>(ai); i < slots.size(); ++i) {
    if (slots[i].job != job)
      continue;  // the chain under test is one readlist
    if (considered >= 12u || seq >= gold.size())
      break;
    ++considered;
    const uint32_t sz = slots[i].size;
    const uint32_t offB = slots[i].vbase >= vAnchor ? slots[i].vbase - vAnchor
                                                   : 0xFFFFFFFFu;
    // Model A: sequential — this slot holds gold[seq .. seq+sz).
    // Model B: vbase delta — this slot holds gold[offB .. offB+sz).
    uint32_t sameA = 0, sameB = 0;
    for (int m = 0; m < 2; ++m) {
      const uint32_t off = m == 0 ? seq : offB;
      if (off >= gold.size())
        continue;
      const uint32_t len =
          (gold.size() - off) < sz ? static_cast<uint32_t>(gold.size() - off)
                                   : sz;
      uint32_t same = 0, seen = 0;
      for (uint32_t done = 0; done < len; done += rb.size()) {
        const uint32_t want =
            (len - done) < rb.size() ? (len - done) : static_cast<uint32_t>(
                                                         rb.size());
        if (!mem.IsValid(slots[i].pbase + done, want) ||
            !mem.ReadBytes(slots[i].pbase + done, rb.data(), want))
          break;
        if (std::memcmp(rb.data(), gold.data() + off + done, want) == 0)
          same += want;
        seen += want;
      }
      if (m == 0) {
        totA += same;
        cmpA += seen;
        sameA = same;
      } else {
        totB += same;
        cmpB += seen;
        sameB = same;
      }
    }
    MCLA_LOG_WARN("UIXSF-LAYOUT-AUDIT pkg={:08X} slot[{}]={:08X} vbase={:08X} "
                  "size={} modelA_off={:08X} matchA={} modelB_off={:08X} "
                  "matchB={}",
                  pkg, i, slots[i].pbase, slots[i].vbase, sz, seq, sameA, offB,
                  sameB);
    seq += sz;
  }
  MCLA_LOG_WARN("UIXSF-LAYOUT-AUDIT pkg={:08X} anchor={:08X} slots={} "
                "modelA {}/{} bytes match  modelB {}/{} bytes match  winner={}",
                pkg, anchorPbase, considered, totA, cmpA, totB, cmpB,
                totA == totB ? "TIE" : (totA > totB ? "SEQUENTIAL" : "VBASE"));
}

static void MclaUiXsfGoldenFill(uint32_t pkg, const std::vector<uint8_t> &gold,
                                const std::vector<MclaUiXsfSlot> &slots,
                                uint32_t shot) {
  if (!kUiXsfGoldenFill || gold.size() < 0x10000u)
    return;  // only the oversized (garage) case needs placement help
  static std::mutex s_fillMtx;
  static std::unordered_set<uint32_t> s_filled;
  {
    std::lock_guard<std::mutex> flk(s_fillMtx);
    const uint32_t key = pkg * 8u + shot;
    if (s_filled.count(key) != 0u || s_filled.size() >= 32u)
      return;
    s_filled.insert(key);
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Anchor = the slot mapped to this package whose head is golden offset 0.
  int ai = -1;
  uint8_t ah[16] = {0};
  for (size_t i = 0; i < slots.size(); ++i) {
    if (PeekPackageForDest(slots[i].pbase) != pkg)
      continue;
    if (!mem.ReadBytes(slots[i].pbase, ah, 16))
      continue;
    if (gold.size() >= 16 && std::memcmp(gold.data(), ah, 16) == 0) {
      ai = static_cast<int>(i);
      break;
    }
    std::memset(ah, 0, sizeof(ah));
  }
  if (ai < 0) {
    MCLA_LOG_WARN("UIXSF-GOLDEN-FILL pkg={:08X} shot={} → NO ANCHOR SLOT", pkg,
                  shot);
    return;
  }
  const uint32_t v0 = slots[ai].vbase;
  if (v0 < 0x40000000u || v0 >= 0x80000000u) {
    MCLA_LOG_WARN("UIXSF-GOLDEN-FILL pkg={:08X} shot={} → BAD ANCHOR VBASE "
                  "{:08X}",
                  pkg, shot, v0);
    return;
  }
  // Two placement hypotheses. `span` (F-323, shipped) maps a slot by its
  // distance from the anchor's vbase — which dead-ended the garage at golden
  // offset 0xC8000 in w293/w294, because a job's virtual ranges are
  // DISCONTINUOUS (readlist #2: vbase 50000000..500C8000 then 60000000.., so the
  // span test excludes the second block). `list` treats the readlist as what it
  // is for a stream bigger than one slot: an ORDERED list of destinations, so
  // container bytes continue into the next `seq` regardless of vbase. Both agree
  // on the first four slots; they differ exactly in the region that is missing.
  const bool listOrder = kUiXsfFillListOrder;
  std::vector<std::pair<size_t, uint32_t>> plan;  // (slot index, golden offset)
  if (listOrder) {
    // F-352 WALKS ONLY WITHIN THE ANCHOR'S OWN READLIST. F-351 crossed into later
    // tables because the guest's own inflate requests did (it asked for B7A41000,
    // then B7AC1000, which is `PSTREAM #2 s[0]`), and that raised the claim from
    // 458,752 to 934,985. It also put garage bytes into slots belonging to a
    // DIFFERENT load — `UIXSF-SLOT-VERIFY dest=B7801000 pkg=6496F000 mismatch=0`
    // says that slot is credits' — and the new layout audit cannot adjudicate it:
    // within one readlist the slots tile contiguously (`vbase(k+1)==vbase(k)+
    // size(k)`, F-320), so the sequential and vbase-delta models are the same
    // function there and the audit reports `winner=TIE` (w345, 458,752/458,752
    // under both). Across tables vbase restarts at 0x50000000, so continuing the
    // sequential run is a guess about a mapping nothing observes — the guest never
    // reads these slots, because `nGfx` is still 0. Placing a container into
    // another container's verified memory to raise a percentage is the F-308
    // failure mode, so it is out; the spill stays in only where the guest asked
    // for the dest itself, which is the F-350 chunked path.
    std::vector<size_t> ord;
    for (size_t i = 0; i < slots.size(); ++i)
      if (slots[i].job == slots[ai].job && slots[i].seq >= slots[ai].seq)
        ord.push_back(i);
    std::sort(ord.begin(), ord.end(), [&](size_t a2, size_t b2) {
      return slots[a2].seq < slots[b2].seq;
    });
    uint32_t run = 0;
    for (size_t idx : ord) {
      if (run >= gold.size())
        break;
      {
        std::lock_guard<std::mutex> elk(g_uiDecMtx);
        const auto it = g_uiDecExpect.find(slots[idx].pbase);
        if (it != g_uiDecExpect.end() && it->second.pkg != pkg &&
            IsUiXsfPkg(it->second.pkg))
          continue;  // another container owns this slot — do not spill into it
      }
      plan.push_back({idx, run});
      uint32_t take = slots[idx].size;
      if (take > gold.size() - run)
        take = static_cast<uint32_t>(gold.size() - run);
      run += take;
    }
  } else {
    for (size_t i = 0; i < slots.size(); ++i) {
      const MclaUiXsfSlot &S = slots[i];
      if (S.vbase < v0 || S.vbase >= v0 + static_cast<uint32_t>(gold.size()))
        continue;
      const uint32_t off = S.vbase - v0;
      if (off >= gold.size())
        continue;
      plan.push_back({i, off});
    }
  }
  uint32_t slotsWritten = 0, bytesWritten = 0, skipped = 0;
  uint32_t covLo = 0xFFFFFFFFu, covHi = 0;
  for (const auto &pr : plan) {
    const size_t i = pr.first;
    const MclaUiXsfSlot &S = slots[i];
    const bool isAnchor = (static_cast<int>(i) == ai);
    const uint32_t off = pr.second;
    if (!isAnchor && !MclaSlotUntouched(S.pbase, S.size)) {
      // The protection that keeps the three verified containers untouched, made
      // visible: w290 placed 819,200 of 1,066,057 bytes and the remaining
      // 246,857 are unexplained unless this line exists.
      // F-350: `MclaSlotUntouched` refuses ANY non-fill content, but for this
      // container's own chain slots that content is the guest's own failed decode
      // of the very bytes we hold — w342 proves the cost of the blanket refusal:
      // three slots (B7A61000/B7A81000/B7AA1000 at golden offsets 0x20000,
      // 0x40000, 0x60000) were skipped, capping the claim at 458,752 of 1,066,057
      // and the garage at 41.3 %. Overwrite here is allowed only when all three
      // hold: the slot is in THIS container's own list-order plan (same job and a
      // sequence at or after the anchor's — true by how `ord` was built), the slot
      // is not claimed as some other package's completed dest, and what is there
      // now is not already the golden bytes (so a correct slot is never touched).
      bool own = false;
      if (kUiXsfFillOwnSlots && listOrder) {
        bool claimedByOtherPkg = false;
        {
          std::lock_guard<std::mutex> elk(g_uiDecMtx);
          const auto it = g_uiDecExpect.find(S.pbase);
          claimedByOtherPkg = it != g_uiDecExpect.end() && it->second.pkg != pkg;
        }
        if (!claimedByOtherPkg) {
          auto &mem2 = mcla::kernel::GuestMemoryHeap::Instance();
          const uint32_t span = S.size < 16u ? 16u
                                             : (S.size > gold.size() - off
                                                ? static_cast<uint32_t>(
                                                      gold.size() - off)
                                                : S.size);
          bool alreadyGolden = span > 0u;
          for (uint32_t o = 0u; o + 4u <= span; o += 4u) {
            uint32_t w = 0;
            if (!mem2.IsValid(S.pbase + o, 4) ||
                !mem2.ReadU32BE(S.pbase + o, &w)) {
              alreadyGolden = false;  // unreadable: do not presume
              break;
            }
            if (w != MclaBE(gold.data() + off + o)) {
              alreadyGolden = false;
              break;
            }
          }
          own = !alreadyGolden;
        }
        if (!own && (skipped <= 4u))
          MCLA_LOG_WARN("UIXSF-GOLDEN-FILL-SKIP pkg={:08X} slot[{}]={:08X} "
                        "goldoff={:08X} reason=PROTECTED(claimed_or_golden)",
                        pkg, i, S.pbase, off);
      }
      if (!own) {
        ++skipped;
        MCLA_LOG_WARN("UIXSF-GOLDEN-FILL-SKIP pkg={:08X} slot[{}]={:08X} "
                      "vbase={:08X} goldoff={:08X} size={} reason=NOT_UNTOUCHED",
                      pkg, i, S.pbase, S.vbase, off, S.size);
        continue;
      }
      MCLA_LOG_WARN("UIXSF-GOLDEN-FILL-OVERWRITE pkg={:08X} slot[{}]={:08X} "
                    "vbase={:08X} goldoff={:08X} size={} — own chain, content "
                    "is the guest's failed decode",
                    pkg, i, S.pbase, S.vbase, off, S.size);
    }
    uint32_t cmp = S.size;
    if (cmp > gold.size() - off)
      cmp = static_cast<uint32_t>(gold.size() - off);
    std::vector<uint8_t> buf(0x4000);
    uint32_t wrote = 0;
    for (uint32_t done = 0; done < cmp; done += buf.size()) {
      const uint32_t want = cmp - done < buf.size() ? cmp - done
                                                   : static_cast<uint32_t>(
                                                         buf.size());
      if (kUiXsfFillDryRun) {
        // Claim the range without touching memory: the reverify that reads it
        // back then measures the guest's own bytes against the golden layout.
        wrote += want;
        bytesWritten += want;
        continue;
      }
      std::memcpy(buf.data(), gold.data() + off + done, want);
      if (!mem.WriteBytes(S.pbase + done, buf.data(), want))
        break;
      wrote += want;
      bytesWritten += want;
    }
    if (wrote) {
      std::lock_guard<std::mutex> llk(g_uiXsfFillLogMtx);
      g_uiXsfFillLog.push_back({pkg, S.pbase, off, wrote});
    }
    if (off < covLo)
      covLo = off;
    if (off + cmp > covHi)
      covHi = off + cmp;
    ++slotsWritten;
    MCLA_LOG_WARN("UIXSF-GOLDEN-FILL pkg={:08X} slot[{}]={:08X} vbase={:08X} "
                  "goldoff={:08X} wrote={} anchor={}",
                  pkg, i, S.pbase, S.vbase, off, cmp, isAnchor ? 1 : 0);
  }
  MCLA_LOG_WARN("UIXSF-GOLDEN-FILL-SUMMARY pkg={:08X} shot={} goldsize={} "
                "anchor={:08X} slots_written={} bytes_written={} skipped={} "
                "dryrun={} gold_span=[{:08X},{:08X})",
                pkg, shot, static_cast<uint32_t>(gold.size()),
                slots[ai].pbase, slotsWritten, bytesWritten, skipped,
                kUiXsfFillDryRun ? 1u : 0u,
                covLo == 0xFFFFFFFFu ? 0u : covLo, covHi);
}

// F-324: how many claimed container bytes are STILL in guest memory right now.
// The fill's `bytes_written`/`gold_span` only report what we asked to be stored;
// the guest inflates into the same slots afterwards, so "decompressed in guest
// memory" has to be answered by reading the slots back. Per claim we mark the
// golden range it covers, then count bytes that actually match — so overlapping
// claims cannot inflate the number, and a later guest write that disagrees shows
// up as a drop on the next shot.
static constexpr bool kUiXsfReverify = true;

static void MclaUiXsfReverify(uint32_t pkg, const std::vector<uint8_t> &gold,
                              uint32_t shot) {
  if (!kUiXsfReverify || gold.size() < 0x10000u)
    return;
  std::vector<MclaUiXsfFillRec> recs;
  {
    std::lock_guard<std::mutex> llk(g_uiXsfFillLogMtx);
    for (const auto &r : g_uiXsfFillLog)
      if (r.pkg == pkg && r.off < gold.size() &&
          r.len <= gold.size() - r.off)
        recs.push_back(r);
  }
  if (recs.empty())
    return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  std::vector<uint8_t> claimed(static_cast<size_t>(gold.size()), 0);
  std::vector<uint8_t> present(static_cast<size_t>(gold.size()), 0);
  std::vector<uint8_t> buf(0x4000);
  uint32_t recsOk = 0, firstBadOff = 0xFFFFFFFFu;
  uint32_t fbPbase = 0, fbLocal = 0, fbLen = 0;  // F-330: the first mismatch
  for (const auto &r : recs) {
    uint32_t good = 0;
    for (uint32_t done = 0; done < r.len; done += buf.size()) {
      const uint32_t want =
          r.len - done < buf.size() ? r.len - done
                                    : static_cast<uint32_t>(buf.size());
      if (!mem.ReadBytes(r.pbase + done, buf.data(), want))
        break;
      for (uint32_t i = 0; i < want; ++i) {
        claimed[r.off + done + i] = 1;
        if (buf[i] == gold[r.off + done + i]) {
          present[r.off + done + i] = 1;
          ++good;
        } else if (firstBadOff == 0xFFFFFFFFu) {
          firstBadOff = r.off + done + i;
          fbPbase = r.pbase;
          fbLocal = done + i;
          fbLen = r.len;
        }
      }
    }
    if (good == r.len)
      ++recsOk;
  }
  uint32_t nClaimed = 0, nPresent = 0;
  for (size_t i = 0; i < gold.size(); ++i) {
    if (claimed[i]) {
      ++nClaimed;
      if (present[i])
        ++nPresent;
    }
  }
  MCLA_LOG_WARN("UIXSF-GOLDEN-REVERIFY pkg={:08X} shot={} recs={} recs_whole={}"
                " goldsize={} claimed={} still_present={} pct={} "
                "first_bad={:08X}",
                pkg, shot, static_cast<uint32_t>(recs.size()), recsOk,
                static_cast<uint32_t>(gold.size()), nClaimed, nPresent,
                nClaimed ? (nPresent * 100u) / nClaimed : 0u, firstBadOff);

  // F-330: classify the divergence instead of hypothesising about it. Everything
  // so far (F-326/327/329) left two candidate causes for the garage stopping at
  // container offset 0x8000 -- a BYTE-SHIFT (our framing/alignment: the guest is
  // reading the right LZX data from the wrong offset, which a shift exposes) or
  // UNRELATED bytes (decoder state, e.g. the lazily-initialised singleton at
  // 0x828D38D8 that `sub_82460420` guards, whose mis-sync no amount of re-slicing
  // fixes). They need opposite fixes, and only the bytes at the divergence can
  // tell them apart. So: take 32 bytes of what the guest put there and search the
  // golden for them within +/-4 KiB; a hit is a shift, a miss is state.
  if (firstBadOff != 0xFFFFFFFFu && fbPbase != 0 && fbLocal + 32 <= fbLen) {
    uint8_t gb[32] = {0};
    if (firstBadOff + 32 <= gold.size() &&
        mem.ReadBytes(fbPbase + fbLocal, gb, 32)) {
      int shift = 0;
      bool shifted = false;
      const int lo = firstBadOff > 4096 ? -4096 : -(int)firstBadOff;
      for (int k = lo; k <= 4096 && !shifted; ++k) {
        if (k == 0)
          continue;
        const int pos = (int)firstBadOff + k;
        if (pos < 0 || pos + 32 > (int)gold.size())
          continue;
        if (std::memcmp(gold.data() + pos, gb, 32) == 0) {
          shift = k;
          shifted = true;
        }
      }
      MCLA_LOG_WARN("UIXSF-DIVERGE pkg={:08X} at={:08X} slot={:08X}+{:08X} "
                    "guest=[{:08X} {:08X} {:08X} {:08X}] "
                    "golden=[{:08X} {:08X} {:08X} {:08X}] {}",
                    pkg, firstBadOff, fbPbase, fbLocal, MclaBE(gb),
                    MclaBE(gb + 4), MclaBE(gb + 8), MclaBE(gb + 12),
                    MclaBE(gold.data() + firstBadOff),
                    MclaBE(gold.data() + firstBadOff + 4),
                    MclaBE(gold.data() + firstBadOff + 8),
                    MclaBE(gold.data() + firstBadOff + 12),
                    shifted ? "IS A SHIFT" : "NOT-IN-GOLDEN-NEIGHBOURHOOD");
      if (shifted)
        MCLA_LOG_WARN("UIXSF-DIVERGE-SHIFT pkg={:08X} shift={}", pkg, shift);
    }
  }
}

static void MclaUiXsfVerifySlot(uint32_t dest, uint32_t slotsize) {
  if (!kUiXsfVerify)
    return;
  const uint32_t pkg = PeekPackageForDest(dest);
  if (!IsUiXsfPkg(pkg) || dest == 0 || dest == 0xCDCDCDCDu)
    return;
  // Bookkeeping under its own lock, released before any helper is called so the
  // lock order stays one-way (verify -> hunt -> golden; never the reverse).
  static std::mutex s_vMtx;
  static std::unordered_set<uint32_t> s_verdict;
  static std::unordered_map<uint32_t, uint32_t> s_vfyN;  // pkg -> verifies seen
  uint32_t vfn = 0;
  {
    std::lock_guard<std::mutex> vlk(s_vMtx);
    if (s_verdict.count(dest) != 0u || s_verdict.size() >= 24u)
      return;  // one verdict per dest
    s_verdict.insert(dest);
    vfn = ++s_vfyN[pkg];
  }
  // Hunt early and late: g_mclaRebaseMap grows as jobs are enqueued, so a single
  // pass would miss slots allocated afterwards.
  // One hunt per verify (bounded) rather than per package: w288 proved the
  // garage's hunt fired while its byte-exact dest was not yet in the inventory
  // (nmap=9, skip_poison=5, slots_matched=0), so an early single shot cannot
  // answer "where did the bytes go" for a container that fills later.
  if (kUiXsfHunt && vfn <= 6u)
    MclaUiXsfGoldenHunt(pkg, vfn, dest);
  const std::vector<uint8_t> &gold = MclaUiXsfGolden(pkg);
  if (gold.size() < 64 || slotsize < 64) {
    MCLA_LOG_WARN("UIXSF-SLOT-VERIFY dest={:08X} pkg={:08X} goldsize={} "
                  "slotsize={} → NO GOLDEN",
                  dest, pkg, static_cast<uint32_t>(gold.size()), slotsize);
    return;
  }
  uint8_t head[64] = {0};
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!mem.ReadBytes(dest, head, 64))
    return;
  uint32_t off = 0;
  bool found = false;
  // Single-byte prefilter first: ~1 M byte compares is microseconds, whereas a
  // 64-byte memcmp at every offset would cost seconds per dest and perturb a
  // timing-sensitive boot.
  while (off + 64 <= gold.size()) {
    if (gold[off] == head[0] &&
        std::memcmp(gold.data() + off, head, 64) == 0) {
      found = true;
      break;
    }
    ++off;
  }
  if (!found) {
    MCLA_LOG_WARN("UIXSF-SLOT-VERIFY dest={:08X} pkg={:08X} goldsize={} "
                  "→ HEAD NOT IN GOLDEN head={:08X} {:08X}",
                  dest, pkg, static_cast<uint32_t>(gold.size()),
                  MclaBE(head), MclaBE(head + 4));
    return;
  }
  uint32_t cmp = slotsize;
  if (cmp > gold.size() - off)
    cmp = static_cast<uint32_t>(gold.size() - off);
  if (cmp > 0x200000u)
    cmp = 0x200000u;
  uint32_t mismatch = 0, firstbad = 0;
  std::vector<uint8_t> buf(cmp > 0x4000u ? 0x4000u : cmp);
  for (uint32_t done = 0; done < cmp; done += buf.size()) {
    const uint32_t want = cmp - done < buf.size() ? cmp - done
                                                  : static_cast<uint32_t>(buf.size());
    if (!mem.ReadBytes(dest + done, buf.data(), want)) {
      mismatch = cmp - done;  // unreadable tail counts as unverifiable
      firstbad = done;
      break;
    }
    for (uint32_t i = 0; i < want; ++i)
      if (buf[i] != gold[off + done + i] && mismatch++ == 0)
        firstbad = done + i;
  }
  MCLA_LOG_WARN("UIXSF-SLOT-VERIFY dest={:08X} pkg={:08X} goldoff={:08X} "
                "goldsize={} compared={} mismatch={} firstbad={:08X}",
                dest, pkg, off, static_cast<uint32_t>(gold.size()), cmp,
                mismatch, firstbad);
}

// w10 FIX: job #2 dests are the UI/swfC set only. The whole B7* range also
// contains job #1 preload dests (B7A01000, B7801000, …) that must keep
// using package base 0x60000 — routing them to the job #2 walk at 0xA0000
// starved job #1 and never delivered the job #2 package head.
// (IsJob2UiDest now lives at file scope near the XSF helpers — w18.)
// F-332: per-frame LZX decoder census. sub_82461B98
// (generated/ppc_xenon/ppc_recomp.82.cpp:15846) is the frame decode called
// once per frame by sub_82461530 (:14943). Its -1 return is what makes
// sub_82461530 produce 0 bytes while its frame counter still advances, and
// sub_82461010 discards that return (F-331 §6) — so until now every failure
// this decoder ever raised was invisible. r3 = the decoder state base S, i.e.
// ctx+20 of the codec ctx, so S+N is what XMEM-CTX prints as ctxp+N+20.
// Log-only: no register and no guest byte is touched.
// F-336: is the codec ctx ever OPENED, or only ever driven? Step 1c of the plan
// needs the guest's own reset (`sub_82460F88` / `sub_82461840`), and both are
// reached only from the Open wrapper `sub_82461378` (generated/ppc_xenon/
// ppc_recomp.82.cpp:14590), which has exactly ONE call site in the whole image
// (`0x8246039c` inside `sub_82460370`, per tools/ppc_xrefs.py) and 0 sites
// materialising its address. So this measures three things in one build: the
// wrapper, its only caller, and `sub_82460420` as the CONTROL — the control is
// known-live because every container call goes through it, which is what makes
// a zero from the other two a measurement rather than an absence (F-309's
// discipline; a bare zero from a brand-new hook is uninterpretable).
extern "C" void __imp__sub_82461378(PPCContext &ctx, uint8_t *base);
extern "C" void __imp__sub_82460370(PPCContext &ctx, uint8_t *base);
extern "C" void __imp__sub_82460420(PPCContext &ctx, uint8_t *base);
static std::atomic<uint32_t> s_openWrap{0}, s_openCaller{0}, s_openCtrl{0};
static void MclaOpenCensus(const char *site, uint32_t n, uint32_t r3,
                           uint32_t r4, uint32_t r5, uint32_t r6, uint32_t r7,
                           uint32_t ctrlNow,
                           uint32_t wrapNow, uint32_t callerNow) {
  if (n <= 4u || (n % 2000u) == 0u)
    MCLA_LOG_WARN("XMEM-OPEN-CENSUS site={} #{} r3={:08X} r4={:08X} r5={:08X} r6={:08X} r7={:08X} "
                  "[wrapper={} caller={} control={}]",
                  site, n, r3, r4, r5, r6, r7, wrapNow, callerNow, ctrlNow);
}
PPC_FUNC(sub_82461378) {
  const uint32_t n = s_openWrap.fetch_add(1) + 1;
  MclaOpenCensus("wrapper", n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,
                 s_openCtrl.load(), n, s_openCaller.load());
  __imp__sub_82461378(ctx, base);
}
PPC_FUNC(sub_82460370) {
  const uint32_t n = s_openCaller.fetch_add(1) + 1;
  MclaOpenCensus("caller", n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,
                 s_openCtrl.load(), s_openWrap.load(), n);
  __imp__sub_82460370(ctx, base);
}
PPC_FUNC(sub_82460420) {
  const uint32_t n = s_openCtrl.fetch_add(1) + 1;
  MclaOpenCensus("control", n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, n,
                 s_openWrap.load(), s_openCaller.load());
  __imp__sub_82460420(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82461B98);
static std::atomic<uint32_t> s_h461B98{0};
static std::atomic<uint32_t> s_h461B98fail{0};
PPC_FUNC(sub_82461B98) {
  const uint32_t n = s_h461B98.fetch_add(1) + 1;
  const uint32_t S = ctx.r3.u32;
  const uint32_t want = ctx.r4.u32;
  auto &bmem = mcla::kernel::GuestMemoryHeap::Instance();
  auto peekS = [&bmem, S](uint32_t off) {
    uint32_t v = 0;
    if (S != 0u && bmem.IsValid(S + off, 4))
      (void)bmem.ReadU32BE(S + off, &v);
    return v;
  };
  const uint32_t frameIdxPre = peekS(11972u);
  __imp__sub_82461B98(ctx, base);
  const int32_t ret = static_cast<int32_t>(ctx.r3.u32);
  bool tally = false;
  if (ret < 0)
    tally = (s_h461B98fail.fetch_add(1) + 1) <= 24u;
  // Caps: the first 16 frames of any kind, the first 24 FAILURES (the signal
  // this was built for), a tally line every 500 frames. What the caps hide:
  // failure 25+ and every successful frame past n=16 — their totals are on the
  // tally line, so a missing per-frame line never means a zero count
  // (F-089 §6 / F-321 the same trap twice).
  if (n <= 16 || tally || (n % 500u) == 0u) {
    // F-348: the staging block, read after the frame so it describes what the
    // NEXT frame resumes from. `w334 XMEM-CTX #4` showed the last successful
    // call draining `leftover` 16384->0 while `stagpos` filled 16384->32768, and
    // the very next frame's cursor (`4003C4CB`) sits past the staging window
    // (`stagbase=40032EA9`, `w12296=4003AEA9` = base+0x8000). If that pairing
    // holds on every boot, the failure is source AVAILABILITY at the moment the
    // decoder's 32 KiB staging drains — not content (F-346) and not
    // recognition (F-347) — and the fix has a name: keep enough contiguous
    // payload in front of the driver that staging never has to read past it.
    const uint32_t stagBase = peekS(12264u), stagPosW = peekS(12268u);
    const uint32_t stagLeft = peekS(12272u), savedCur = peekS(12276u);
    const uint32_t frameOff = peekS(12280u), srcEnd = peekS(11016u);
    const uint32_t srcp = peekS(11012u);
    const bool inStaging = stagBase != 0u && srcp >= stagBase &&
                           srcp < stagBase + 0x8000u;
    MCLA_LOG_WARN("LZX-FRAME #{} S={:08X} frameIdx={} want={} type={} "
                  "fsize={} state={} ret={} srcp={:08X} bitbuf={:08X} "
                  "cumprod={} failtotal={} stag=[{:08X} pos={} left={}] "
                  "savedcur={:08X} frameoff={} srcEnd={:08X} inStag={} "
                  "pastEnd={}",
                  n, S, frameIdxPre, want, peekS(11984u), peekS(11980u),
                  peekS(11988u), ret, srcp, peekS(11952u), peekS(11024u),
                  s_h461B98fail.load(), stagBase, stagPosW, stagLeft, savedCur,
                  frameOff, srcEnd, inStaging ? 1 : 0,
                  srcEnd != 0u && srcp > srcEnd ? 1 : 0);
  }
}

PPC_FUNC_IMPL(__imp__sub_821D5E10);
// F-182: the single switch for every state rewrite this hook performs. Set to
// false to let the guest's own zlibInflater::InflateBegin run untouched.
// T41.9 experiment (F-194, w216): with Path B enqueue ON + this OFF, the
// `INFLATE #2.2M` loop DISAPPEARED (6 inflates, not 11264) — proving the loop was
// the re-point machinery, NOT the enqueue. BUT the guest's own InflateBegin then
// printed its OWN `not in XCompress format` assert (×2) and INFLATE collapsed 361→6
// + boot stalled at 19,964 lines: the re-point is LOAD-BEARING for meshtextures too
// (F-182), so this combo is confounded, not viable. Restored to true. The residual
// blocker is SERVE FRAMING (the bytes at the inflate head aren't 0x0FF512EF), which
// must be fixed WITH the re-point kept on for meshtextures (F-169/183 line).
static constexpr bool kInflateIntervene = true;
static std::atomic<uint32_t> s_h5E10{0};
static std::atomic<uint32_t> s_h5E10pt{0};
static std::atomic<uint32_t> s_h5E10empty{0};

// F-325: does the placement SURVIVE, or did F-324 only prove it landed? The
// reverify fired once, immediately after the fill, so it could not see a later
// guest write over any of these slots. The inflate hook is the natural sampler:
// it runs ~4,900 times spread across the whole boot, so every 1,000th entry
// re-reads the recorded claims and reports how much of each container is still
// byte-exact in guest memory at that moment. Read-only; bounded by the counter.
static void MclaUiXsfLateReverify(uint32_t n) {
  // Bounded: w299 hit 20 MILLION inflate entries while the guest spun, and
  // "every 1,000th" printed 20,365 reverify lines. Eight samples per package is
  // plenty to answer "did it survive".
  if (!kUiXsfReverify || n < 1000u || (n % 1000u) != 0u || n > 9000u)
    return;
  static constexpr uint32_t kPkgs[4] = {0x64CB0000u, 0x64980000u, 0x64CA3000u,
                                        0x6496F000u};
  const uint32_t sample = n / 1000u;
  for (const uint32_t p : kPkgs)
    MclaUiXsfReverify(p, MclaUiXsfGolden(p), 99u + sample);
}

PPC_FUNC(sub_821D5E10) {
  // F-337: the caller passes the codec *object* in r3 and the inflate reads
  // *obj as the context; r3 is the return value by the time the refill runs, so
  // capture it here.
  const uint32_t objAtEntry = ctx.r3.u32;
  // F-344: one container at a time inside the shared context, by skipping the CALL.
  if (kUiXsfHoldCtx) {
    auto &hm = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t hst = ctx.r4.u32;
    uint32_t hdest = 0;
    (void)hm.ReadU32BE(hst + 20u, &hdest);
    const uint32_t hpkg = hdest != 0u ? PeekPackageForDest(hdest) : 0u;
    if (hpkg != 0u && IsUiXsfPkg(hpkg)) {
      uint32_t owner = g_uiXsfHoldOwner.load();
      if (owner == 0u) {
        g_uiXsfHoldOwner.store(hpkg);
        g_uiXsfHoldCount.store(1);
        MCLA_LOG_WARN("UIXSF-HOLD-CTX pkg={:08X} takes the context", hpkg);
      } else if (owner == hpkg) {
        if (g_uiXsfHoldCount.fetch_add(1) + 1 >= kUiXsfHoldOwnerEntries) {
          g_uiXsfHoldOwner.store(0);
          g_uiXsfHoldCount.store(0);
          MCLA_LOG_WARN("UIXSF-HOLD-CTX pkg={:08X} releases after {} entries",
                        hpkg, kUiXsfHoldOwnerEntries);
        }
      } else {
        const uint32_t run =
            g_uiXsfHoldLast.load() == hpkg ? g_uiXsfHoldRun.fetch_add(1) + 1 : 1u;
        g_uiXsfHoldLast.store(hpkg);
        g_uiXsfHoldRun.store(run);
        const uint32_t blocked = g_uiXsfHoldBlocked.fetch_add(1) + 1;
        if (run >= kUiXsfHoldMaxRun) {
          g_uiXsfHoldOwner.store(hpkg);
          g_uiXsfHoldCount.store(1);
          g_uiXsfHoldRun.store(0);
          if (blocked <= 8u || (blocked % 2000u) == 0u)
            MCLA_LOG_WARN("UIXSF-HOLD-CTX hand over {:08X} -> {:08X} (blocked={})",
                          owner, hpkg, blocked);
        } else {
          if (blocked <= 4u || (blocked % 2000u) == 0u)
            MCLA_LOG_WARN("UIXSF-HOLD-CTX pkg={:08X} blocked by owner {:08X} "
                          "run={} (blocked={})", hpkg, owner, run, blocked);
          ctx.r3.u32 = 0u;  // the caller reads r3 as the status; 0 == S_OK, no bytes
          return;
        }
      }
    }
  }

  // F-343: clear the frame driver's walk state on every UI-container entry.
  if (kUiXsfClearResumeEvery) {
    auto &wm = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t wst = ctx.r4.u32;
    uint32_t wdest = 0;
    (void)wm.ReadU32BE(wst + 20u, &wdest);
    const uint32_t wpkg = wdest != 0u ? PeekPackageForDest(wdest) : 0u;
    if (wpkg != 0u && IsUiXsfPkg(wpkg)) {
      uint32_t wctx = s_xmemCtx.load();
      if (wctx == 0u) {
        const uint32_t inf = s_guestInflaterR3.load();
        if (inf != 0u)
          (void)wm.ReadU32BE(inf, &wctx);
      }
      uint32_t wcodec = 0;
      if (wctx != 0u && wm.ReadU32BE(wctx + 4u, &wcodec) && wcodec == 1u) {
        uint32_t pre_off = 0, pre_cur = 0, pre_left = 0;
        (void)wm.ReadU32BE(wctx + 20u + 12280u, &pre_off);
        (void)wm.ReadU32BE(wctx + 20u + 12276u, &pre_cur);
        (void)wm.ReadU32BE(wctx + 20u + 12272u, &pre_left);
        (void)wm.WriteU32BE(wctx + 20u + 12280u, 0);
        (void)wm.WriteU32BE(wctx + 20u + 12276u, 0);
        (void)wm.WriteU32BE(wctx + 20u + 12272u, 0);
        static uint32_t s_clog = 0;
        if (s_clog < 10u) {
          ++s_clog;
          MCLA_LOG_WARN("UIXSF-RESUME-EVERY #{} pkg={:08X} ctx={:08X} cleared "
                        "off={} cur={:08X} leftover={}",
                        s_clog, wpkg, wctx, pre_off, pre_cur, pre_left);
        }
      }
    }
  }

  // F-342: publish the container's own codec context for the duration of this entry.
  if (kUiXsfPerPkgCtx) {
    auto &cmem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t pst = ctx.r4.u32;
    uint32_t pdest = 0;
    (void)cmem.ReadU32BE(pst + 20u, &pdest);
    const uint32_t ppkg = pdest != 0u ? PeekPackageForDest(pdest) : 0u;
    const bool ui = ppkg != 0u && IsUiXsfPkg(ppkg);
    const bool slotOK = objAtEntry >= 0x40000000u && objAtEntry < 0xF0000000u &&
                        cmem.IsValid(objAtEntry, 4u);
    if (slotOK) {
      uint32_t want = 0, cur = 0;
      {
        std::lock_guard<std::mutex> plk(g_uiXsfPkgMtx);
        if (ui) {
          const auto it = g_uiXsfPkgCtx.find(ppkg);
          want = it != g_uiXsfPkgCtx.end() ? it->second : 1u;  // 1 = need one
        } else {
          want = g_uiXsfOrigCtx.load();
        }
      }
      (void)cmem.ReadU32BE(objAtEntry, &cur);
      if (want == 1u && g_uiXsfPkgCtx.size() < 8u) {
        const uint32_t raw = cmem.Alloc(0x6A000u, 16);
        const uint32_t blk = raw != 0u ? raw + 0x35000u : 0u;
        if (blk != 0u) {
          if (g_uiXsfOrigCtx.load() == 0u && cur != 0u && cur != 0xCDCDCDCDu)
            g_uiXsfOrigCtx.store(cur);
          PPCContext q{};
          q.r1.u64 = ctx.r1.u32 - 0x400u;
          q.r13.u64 = 0x8F200000u;
          q.r3.u64 = 0x8EFFF990u;
          q.r4.u64 = 1u;
          q.r5.u64 = blk;
          q.r6.u64 = 0x3492Eu;
          q.lr = 0x824613D4u;
          __imp__sub_82461378(q, base);
          std::lock_guard<std::mutex> plk(g_uiXsfPkgMtx);
          g_uiXsfPkgCtx[ppkg] = blk;
          want = blk;
          MCLA_LOG_WARN("UIXSF-PKGCTX pkg={:08X} opened ctx={:08X} (shared "
                        "{:08X})", ppkg, blk, g_uiXsfOrigCtx.load());
        }
      }
      if (want != 0u && want != cur) {
        (void)cmem.WriteU32BE(objAtEntry, want);
        static uint32_t s_plog = 0;
        if (s_plog < 12u) {
          ++s_plog;
          MCLA_LOG_WARN("UIXSF-PKGCTX obj={:08X} pkg={:08X} ctx {:08X} -> "
                        "{:08X}", objAtEntry, ppkg, cur, want);
        }
      }
    }
  }
  // F-339: F-338 showed that writing a private context into the shared per-job
  // slot takes down the job's OTHER streams too, because they read the same word.
  // So the publish has to be paired: hold the private ctx only while this entry
  // belongs to the stream it was opened for, and put the shared ctx back for
  // every other entry. Keyed on the inflate record (`st`), never on an address.
  if (kUiXsfPrivateCtx) {
    auto &pmem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t stx = ctx.r4.u32;
    uint32_t priv = 0;
    {
      std::lock_guard<std::mutex> pl(g_uiXsfPrivMtx);
      const auto it = g_uiXsfPrivCtx.find(stx);
      if (it != g_uiXsfPrivCtx.end())
        priv = it->second;
    }
    if (objAtEntry >= 0x40000000u && objAtEntry < 0xF0000000u &&
        pmem.IsValid(objAtEntry, 4u)) {
      uint32_t cur = 0;
      if (pmem.ReadU32BE(objAtEntry, &cur)) {
        if (priv != 0u && cur != priv) {
          (void)pmem.WriteU32BE(objAtEntry, priv);
          static uint32_t s_pubLog = 0;
          if (s_pubLog < 6u) {
            ++s_pubLog;
            MCLA_LOG_WARN("UIXSF-PRIVCTX publish obj={:08X} {} -> {} (st={:08X})",
                          objAtEntry, cur, priv, stx);
          }
        } else if (priv == 0u && cur != 0u) {
          bool mine = false;
          {
            std::lock_guard<std::mutex> pl(g_uiXsfPrivMtx);
            mine = g_uiXsfPrivSet.count(cur) != 0u;
          }
          const uint32_t shared = g_uiXsfSharedCtx.load();
          if (mine && shared != 0u && shared != cur) {
            (void)pmem.WriteU32BE(objAtEntry, shared);
            static uint32_t s_resLog = 0;
            if (s_resLog < 6u) {
              ++s_resLog;
              MCLA_LOG_WARN("UIXSF-PRIVCTX restore obj={:08X} {} -> {} "
                            "(st={:08X})", objAtEntry, cur, shared, stx);
            }
          }
        }
      }
    }
  }
  const uint32_t n = s_h5E10.fetch_add(1) + 1;
  const uint32_t st = ctx.r4.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // w26: capture guest inflater r3 (executor r24 = joinTable+32+(idx*4)).
  // Host decompress of package 0xA0000 needs this object — never r3=0.
  const uint32_t infR3 = ctx.r3.u32;
  if (infR3 >= 0x80000000u && infR3 != 0xCDCDCDCDu && infR3 < 0xC0000000u) {
    if (s_guestInflaterR3.load() != infR3)
      s_guestInflaterR3.store(infR3);
    uint32_t x0 = 0;
    if (mem.ReadU32BE(infR3, &x0) && x0 != 0 && x0 != 0xCDCDCDCDu &&
        s_xmemCtx.load() != x0)
      s_xmemCtx.store(x0);
  }
  if (n <= 4 || (n % 200) == 1)
    MclaCensusInflaterFamily(mem, infR3);
  uint32_t inLeft = 0, inPtr = 0, consumed = 0, expected = 0;
  uint32_t outLeft = 0, outPtr = 0, produced = 0;
  (void)mem.ReadU32BE(st + 0, &inLeft);
  (void)mem.ReadU32BE(st + 4, &inPtr);
  (void)mem.ReadU32BE(st + 8, &consumed);
  (void)mem.ReadU32BE(st + 12, &expected);
  (void)mem.ReadU32BE(st + 16, &outLeft);
  (void)mem.ReadU32BE(st + 20, &outPtr);
  (void)mem.ReadU32BE(st + 24, &produced);
  // w20/w21 census so INFLATE entry is never silent on job #2 / stack walks.
  {
    const bool j2Ent = IsJob2UiDest(outPtr);
    const bool stackCont =
        (inPtr != 0 && inPtr < 0xA0000000u && consumed > 0);
    // F-328: `exp` (st+12) and the 8 bytes at inPtr are the guest's OWN block
    // header parse. Read from generated/ppc_xenon/ppc_recomp.18.cpp:10832+
    // (`sub_821D5E10`): when [st+8]==0 it compares [inPtr+0] against 0x0FF512E0,
    // copies [inPtr+4] into st+12, then advances inPtr+=8 / inLeft-=8, and clamps
    // every XMemDecompress call's input to ([st+12] - [st+8]). So `exp` alone
    // decides how much buffered input the guest will accept, and a wrong `exp`
    // gives exactly F-327's symptom (a non-zero inLeft the guest refuses to
    // consume). Folded into this line rather than adding one (F-133).
    uint8_t ih[8] = {0};
    if (inPtr)
      (void)mem.ReadBytes(inPtr, ih, 8);
    if (n <= 16 || (n % 200) == 0 || j2Ent || stackCont)
      MCLA_LOG_WARN("INFLATE-ENTER #{} st={:08X} in={} inPtr={:08X} "
                    "consumed={} exp={:08X} ihdr=[{:08X} {:08X}] "
                    "outPtr={:08X} lr={:08X} j2={}",
                    n, st, inLeft, inPtr, consumed, expected, MclaBE(ih),
                    MclaBE(ih + 4), outPtr, static_cast<uint32_t>(ctx.lr),
                    j2Ent ? 1 : 0);
  }

  MclaUiXsfLateReverify(n);  // F-325 persistence sampler (read-only)
  uint32_t magic = 0;
  // F-295 Path A (unified): host XMem/raw-LZX decode of the UI .xsf dests,
  // fired once per dest at the very top of the inflate handler so it covers
  // BOTH the corrupt-serve leg (raceeditor, inLeft<0) and the normal
  // INFLATE-RSC5 leg (garage/policecam/credits, valid in=32768). Pure host
  // computation — no guest VM re-entry, so free of the F-288/290/293 corrupt-
  // serve context conflict. On success the FULL byte-exact container is in the
  // dest and outLeft is drained (caller-loop complete key). Gated OFF == baseline.
  if (kPathBHostFullDecode && outPtr != 0 && outLeft != 0) {
    // F-297: resolve the dest through the same dynamic mapping the serve path
    // uses (AssignPackageForDest -> g_destPkgOff, populated by the PATHB-PENDING
    // publish and the PATHB-PKGFIX registration) and allowlist on the stable
    // package-offset side. An UNMAPPED dest is not a failure and is not cached
    // as one: the corrupt-serve leg below calls AssignPackageForDest, which
    // registers the mapping mid-entry, so a later entry for the same dest hits
    // this hook (w270: DEST-PKG B7B01000 -> 64CB0000 lands between inflate
    // entries #1 and #2).
    const uint32_t uiPkg = PeekPackageForDest(outPtr);
    if (uiPkg != 0 && IsUiXsfPkg(uiPkg)) {
      const UiDecAct act = UiDecClassify(outPtr, uiPkg);
      // F-354: print the DESTINATION CHAIN the guest actually requests for each UI
      // container, because that — not any host choice — is what bounds Path A
      // placement: F-350 reached 458,752 of 1,066,057 bytes and the ceiling is
      // exactly the destinations offered (`B7A41000` room 131,072 then
      // `B7AC1000` room 262,144, `w341`), after which the shared record
      // `st=0x6D8F20` is taken by another container. Is the chain 2 long, does it
      // resume later in the boot (a multi-pass load would let F-350 place the rest
      // with no new mechanism), or does `outPtr` repeat (a ring, which would mean
      // placement must round-robin)? Nothing printed that before. Log-only, and it
      // prints the whole chain each time it grows so one line answers the question
      // regardless of order.
      {
        static std::mutex s_chainMtx;
        static std::unordered_map<uint32_t, std::vector<uint32_t>> s_chain;
        std::lock_guard<std::mutex> clk(s_chainMtx);
        std::vector<uint32_t> &ch = s_chain[uiPkg];
        bool fresh = true;
        for (uint32_t d : ch)
          if (d == outPtr) {
            fresh = false;
            break;
          }
        if (fresh && ch.size() < 24u) {
          ch.push_back(outPtr);
          std::string listing;
          for (uint32_t d : ch) {
            char hex[9];
            for (int b = 0; b < 4; ++b) {
              const unsigned v = (d >> (24 - 8 * b)) & 0xFFu;
              const char dig[] = "0123456789ABCDEF";
              hex[2 * b] = dig[v >> 4];
              hex[2 * b + 1] = dig[v & 0xF];
            }
            hex[8] = 0;
            listing += hex;
            listing += ' ';
          }
          uint32_t r0 = 0, r4 = 0, r8 = 0, r12 = 0, r16 = 0, r24 = 0;
          (void)mem.ReadU32BE(st + 0, &r0);
          (void)mem.ReadU32BE(st + 4, &r4);
          (void)mem.ReadU32BE(st + 8, &r8);
          (void)mem.ReadU32BE(st + 12, &r12);
          (void)mem.ReadU32BE(st + 16, &r16);
          (void)mem.ReadU32BE(st + 24, &r24);
          MCLA_LOG_WARN("PATHB-HOSTDECODE-CHAIN pkg={:08X} n={} this={:08X} "
                        "act={} room={} rec=[inLeft={} inPtr={:08X} consumed={} "
                        "exp={} outLeft={} produced={}] chain={} ",
                        uiPkg, static_cast<uint32_t>(ch.size()), outPtr,
                        static_cast<int>(act), outLeft, r0, r4, r8, r12, r16,
                        r24, listing);
        }
      }
      if (act == kUiDecComplete) {
        // already fully decoded into this dest — keep it complete, skip re-inflate.
        (void)mem.WriteU32BE(st + 0, 0);
        (void)mem.WriteU32BE(st + 16, 0);
        return;
      }
      if (act == kUiDecTry) {
        const uint32_t cpsz = PackageSizeAt(uiPkg);
        uint32_t want = cpsz ? cpsz : 0x200000u;
        if (want > 0x200000u) want = 0x200000u;
        auto &vfsH = mcla::vfs::RpfVirtualFileSystem::Instance();
        mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fhH;
        std::vector<uint8_t> bigH(want);
        uint64_t gotH = 0;
        bool srvH = false;
        if (vfsH.OpenFile("xarchive_cache.rpf", fhH)) {
          srvH = vfsH.ReadFileAt(fhH, uiPkg, bigH.data(), want, gotH) &&
                 gotH >= 24;
          vfsH.CloseFile(fhH);
        }
        int hp = 0;
        std::vector<uint8_t> decH;
        if (srvH)
          hp = mcla_lzx::host_decode_ui_xsf(bigH.data(),
                                            static_cast<size_t>(gotH), decH,
                                            kXcWindowBits);
        // Write+complete ONLY when the WHOLE decoded container fits the dest's
        // current room. Garage (uncLen 1066057) exceeds a 256 KiB window; a
        // truncated prefix marked complete would corrupt the tail, so oversized
        // containers fall through to the guest's own progressive inflate.
        bool fits = hp && !decH.empty() && decH.size() <= outLeft;
        // F-350: the oversized case is not "leave it to the guest" — the guest
        // manages 5.9 % (F-326). Keep the decoded body, place the next `room`
        // bytes at the dest the guest is asking for, and mark THIS record
        // complete so its caller advances to the next slot in the chain.
        static std::unordered_map<uint32_t, std::vector<uint8_t>> s_body;
        static std::unordered_map<uint32_t, uint32_t> s_bodyOff;
        struct UiChunkClaim {
          uint32_t dest;
          uint32_t off;
          uint32_t len;
        };
        static std::unordered_map<uint32_t, std::vector<UiChunkClaim>>
            s_bodyClaims;
        static std::unordered_map<uint32_t, uint32_t> s_bodyChunks;
        if (!fits && kUiXsfChunkedHostFill && hp && !decH.empty() && outLeft) {
          std::vector<uint8_t> &body = s_body[uiPkg];
          if (body.empty())
            body = decH;  // the chain spans several entries; keep the decode
          uint32_t &off = s_bodyOff[uiPkg];
          uint32_t &chunks = s_bodyChunks[uiPkg];
          if (off >= body.size()) {
            // Whole container already placed on this boot. Keep the record
            // complete rather than placing a second copy: an unbounded restart
            // is how F-349 turned a null into 106,697 inflate entries.
            if (chunks <= 4u || (chunks % 200u) == 0u)
              MCLA_LOG_WARN("PATHB-HOSTDECODE-CHUNK-DONE #{} dest={:08X} "
                            "pkg={:08X} placed={}/{} chunks={} claims={}",
                            n, outPtr, uiPkg, off,
                            static_cast<uint32_t>(body.size()), chunks,
                            static_cast<uint32_t>(s_bodyClaims[uiPkg].size()));
            ++chunks;
            (void)mem.WriteU32BE(st + 0, 0);
            (void)mem.WriteU32BE(st + 16, 0);
            return;
          }
          const uint32_t took =
              (body.size() - off) < outLeft ? (body.size() - off) : outLeft;
          if (chunks >= 64u) {
            // 64 dests is more room than any UI container needs; hitting the cap
            // means the chain is not advancing, so stop writing and let the
            // guest have this one.
            MCLA_LOG_WARN("PATHB-HOSTDECODE-CHUNK-CAP #{} dest={:08X} "
                          "pkg={:08X} placed={}/{} chunks={}",
                          n, outPtr, uiPkg, off,
                          static_cast<uint32_t>(body.size()), chunks);
          } else if (mem.WriteBytes(outPtr, body.data() + off, took)) {
            ++chunks;
            s_bodyClaims[uiPkg].push_back({outPtr, off, took});
            off += took;
            {
              std::lock_guard<std::mutex> lk(g_uiDecMtx);
              g_uiDecDone[outPtr] = uiPkg;
            }
            // Verify by reading guest memory back — the write is not evidence.
            uint32_t exact = 0u;
            std::vector<uint8_t> rb(0x4000u);
            for (const UiChunkClaim &c : s_bodyClaims[uiPkg])
              for (uint32_t done = 0u; done < c.len; done += rb.size()) {
                const uint32_t want =
                    (c.len - done) < rb.size() ? (c.len - done)
                                               : static_cast<uint32_t>(
                                                     rb.size());
                if (!mem.IsValid(c.dest + done, want) ||
                    !mem.ReadBytes(c.dest + done, rb.data(), want))
                  break;
                if (std::memcmp(rb.data(), body.data() + c.off + done, want) ==
                    0)
                  exact += want;
              }
            MCLA_LOG_WARN("PATHB-HOSTDECODE-CHUNK #{} dest={:08X} "
                          "pkg={:08X} wrote={} placed={}/{} room={} "
                          "claims={} present={} final={}",
                          n, outPtr, uiPkg, took, off,
                          static_cast<uint32_t>(body.size()), outLeft,
                          static_cast<uint32_t>(s_bodyClaims[uiPkg].size()),
                          exact, off >= body.size() ? 1 : 0);
            // F-356: `sub_821D5E10` advances the record itself after every call
            // (`generated/ppc_xenon/ppc_recomp.18.cpp:10960-10995`):
            // `st+20 outPtr += written`, `st+16 outLeft -= written`,
            // `st+24 produced += written`, `st+0 inLeft -= consumed`,
            // `st+4 inPtr += consumed`. F-350 instead wrote `outLeft = 0`, which is
            // the guest's own signal that the destination is FINISHED — so the
            // caller stops asking and the chain dies at two requests (F-354). Mimic
            // the real advance so the record stays self-consistent and the caller
            // keeps going. If the neighbouring slot belongs to another container the
            // `match=true` checks on raceeditor/policecam/credits will show it, and
            // this reverts. `false` == F-350's completion marking exactly.
            if (kUiXsfChunkFaithfulAdvance) {
              uint32_t oLeft = 0, oPtr = 0, prod = 0;
              (void)mem.ReadU32BE(st + 16, &oLeft);
              (void)mem.ReadU32BE(st + 20, &oPtr);
              (void)mem.ReadU32BE(st + 24, &prod);
              (void)mem.WriteU32BE(st + 16, oLeft > took ? oLeft - took : 0u);
              (void)mem.WriteU32BE(st + 20, oPtr + took);
              (void)mem.WriteU32BE(st + 24, prod + took);
              (void)mem.WriteU32BE(st + 0, 0);  // input consumed: caller refills
            } else {
              (void)mem.WriteU32BE(st + 0, 0);
              (void)mem.WriteU32BE(st + 16, 0);  // this dest is full: advance
            }
            return;
          }
        }
        if (fits && mem.WriteBytes(outPtr, decH.data(),
                                   static_cast<uint32_t>(decH.size()))) {
          {
            std::lock_guard<std::mutex> lk(g_uiDecMtx);
            g_uiDecDone[outPtr] = uiPkg;
          }
          UiDecRecordExpect(outPtr, uiPkg, decH.data(), decH.size());
          MCLA_LOG_WARN("PATHB-HOSTDECODE-TOP #{} dest={:08X} pkg={:08X} "
                        "path={} unc={} wrote={} room={} ok",
                        n, outPtr, uiPkg, hp,
                        static_cast<uint32_t>(decH.size()),
                        static_cast<uint32_t>(decH.size()), outLeft);
          (void)mem.WriteU32BE(st + 0, 0);
          (void)mem.WriteU32BE(st + 8, static_cast<uint32_t>(gotH));
          (void)mem.WriteU32BE(st + 16, 0);  // outLeft -> complete
          {
            std::lock_guard<std::mutex> wl(g_destPkgMtx);
            g_destPkgWalk[outPtr] = static_cast<uint32_t>(gotH);
          }
          return;
        }
        {
          std::lock_guard<std::mutex> lk(g_uiDecMtx);
          g_uiDecSkip.insert(UiDecKey(outPtr, uiPkg));
        }
        MCLA_LOG_WARN("PATHB-HOSTDECODE-TOP-SKIP #{} dest={:08X} pkg={:08X} "
                      "srv={} gotH={} path={} unc={} room={} → guest",
                      n, outPtr, uiPkg, srvH, static_cast<uint32_t>(gotH), hp,
                      decH.empty() ? 0u : static_cast<uint32_t>(decH.size()),
                      outLeft);
      }
      // kUiDecSkipGuest (and kUiDecTry-after-SKIP) fall through to the guest
      // inflate path below, exactly as a non-UI dest does.
    }
  }

  // w21: read magic even when consumed>0 — continuation entries walk stack
  // zeros after the first XCompress window and magic must be visible then.
  if (inLeft >= 4 && inPtr != 0)
    (void)mem.ReadU32BE(inPtr, &magic);

  // F-182 EXPERIMENT, revert first if the frontier moves. Everything below this
  // line rewrites the guest's inflater state (re-point st+0/st+4 at a host
  // bounce, force-serve windows, INFLATE-UNSTUCK zeroing outLeft). F-172 proved
  // those paths are what the 34 XMem calls belong to (our j1SrcSz constants, a
  // semaphore handle as `src`, ret=0 every time), and F-181 proved the guest
  // needs nothing from us: pgStreamer::Open seeds every container's real
  // length and we serve whole bodies since F-169/F-171. So: pass the call to the
  // guest's own InflateBegin/XMemDecompress untouched and see what it does with
  // the bytes - either it decodes, or it prints 'not in XCompress format'
  // through its own path. Both are answers; neither has ever been tried.
  if (!kInflateIntervene) {
    __imp__sub_821D5E10(ctx, base);
    return;
  }

  // w20/w21: guest re-points inPtr at stack (006D8F4C / 006D9840) after
  // CC6F0 primes st. REFORCE when magic is bad OR when consumed>0 walking
  // stack — do NOT require consumed==0. Re-point st+0/st+4 at remaining
  // guest-heap package bytes; job #2 UI dests pin to package 0xA0000.
  if (st != 0 && st != 0xCDCDCDCDu) {
    const bool badMagic =
        (magic == 0u) || (magic == 0xCDCDCDCDu) ||
        (magic != kXCompressMagic && magic != 0x05435352u &&
         inPtr != 0 && inPtr < 0xA0000000u);
    const bool stackWalk =
        (consumed > 0 && inPtr != 0 && inPtr < 0xA0000000u &&
         (magic == 0u || magic == 0xCDCDCDCDu ||
          (magic != kXCompressMagic && magic != 0x05435352u)));
    // w22: also enter re-point when job2 dest has non-XC magic even if
    // inPtr looks like heap and inLeft!=0 (spin at #9+ magic=9960BB82).
    // Only while produced==0 — once __imp__ lands XC output, job1-style
    // mid-stream continuations (produced>0) must pass through unchanged.
    const bool j2NeedRepoint =
        IsJob2UiDest(outPtr) && produced == 0 &&
        (magic != kXCompressMagic && magic != 0x05435352u);
    // w28: stack-hosted RSC5/XC head is a PLANTED HEAD (READWRAP-SERVE
    // copies ≤256B to stack dest), NOT the full compressed body. w27
    // regression: valid XC magic on stack skipped re-point → XMem ran on
    // src=006D8F54 (stack+0x14) → zeros; w24 CORRUPT path host-served
    // package to heap C9C36F00 and XMem produced 44365500. Always
    // re-point at the guest-heap package bounce when the inflate source
    // is a stack head with package magic.
    const bool stackPkgHead =
        (inPtr != 0 && inPtr < 0xA0000000u && consumed < 16u &&
         (magic == kXCompressMagic || magic == 0x05435352u));
    if (badMagic || inLeft == 0 || stackWalk || j2NeedRepoint ||
        stackPkgHead) {
      bool served = false;
      // w22: job #2 InflateStep entries must re-point at the LastServe bounce
      // (RSC5 head @ walk=0 for that dest). ForceServe uses g_job2SharedWalk
      // which PSTREAM dump already advanced — continuation bytes have no
      // RSC5/XC head and starve the decoder. Prefer LastServe first.
      // Also re-point when magic is non-XC even if inPtr looks like heap
      // (w22 #9: consumed=1 magic=9960BB82 on C9CF3E00 fell through to
      // __imp__ and FATAL-SOFT "not in XCompress format").
      const bool j2BadMag =
          IsJob2UiDest(outPtr) && produced == 0 &&
          (badMagic || stackWalk || stackPkgHead || inLeft == 0 ||
           magic == 0u ||
           (magic != kXCompressMagic && magic != 0x05435352u &&
            magic != 0xCDCDCDCDu) ||
           consumed > 0x7F000000u);
      if (j2BadMag) {
        MclaLastServe ls0;
        // Dest-keyed LastServe first (JOB2-PKG-SERVE bounce @ walk=0 RSC5
        // head). St-keyed may still point at a shared READWRAP body.
        bool haveLs = MclaFindLastServe(0, outPtr, &ls0) && ls0.sbuf &&
                      ls0.size > ls0.pos;
        if (!haveLs)
          haveLs = MclaFindLastServe(st, outPtr, &ls0) && ls0.sbuf &&
                   ls0.size > ls0.pos;
        // w25: LastServe head must be RSC5/XC. A junk continuation bounce
        // (913F58A1 family) re-served forever starved Job2 (never POST-EXEC).
        uint32_t lsHead = 0;
        if (haveLs)
          (void)mem.ReadU32BE(ls0.sbuf + ls0.pos, &lsHead);
        const bool lsDecodable =
            (lsHead == 0x05435352u || lsHead == 0x0FF512EFu);
        if (haveLs && !lsDecodable) {
          static std::atomic<uint32_t> s_j2lsJunk{0};
          const uint32_t jn = s_j2lsJunk.fetch_add(1) + 1;
          MCLA_LOG_WARN(
              "INFLATE-J2-LAST-JUNK #{} dest={:08X} head={:08X} "
              "— skip LastServe, fall through",
              jn, outPtr, lsHead);
          haveLs = false;
        }
        if (haveLs) {
          // F-195: the j2BadMag path re-served sbuf+ls0.pos with ls0.pos pinned at
          // its registration value (0), and set served=true, so the continuation
          // branch (:7623, which advances by `consumed`) was NEVER reached → w214
          // `INFLATE #2.2M` loop (produced>0 each call, but pos/outPtr never moved).
          // Advance the stored pos by the amount the guest consumed on the previous
          // InflateBegin (local `consumed` = st+8 set by __imp__ last time) so the
          // stream walks forward and eventually exhausts (give0==0 → fall through).
          // F-252: also fire under kPathBEnqueueUI (route-1) — now that job2 pbase
          // dests resolve to real 0xA0000 (persistent membership), the walk must
          // advance past each consumed window or the whole-package inflate re-serves
          // the head (w247 loop). flag-OFF => kUiServeAdvance=false && flag=false =>
          // no change to baseline.
          if ((kUiServeAdvance || kPathBEnqueueUI) && consumed > 0 &&
              consumed < 0x80000000u &&
              ls0.pos + consumed <= ls0.size) {
            ls0.pos += consumed;
            MclaRecordLastServe(ls0);
          }
          const uint32_t rem0 =
              (ls0.size > ls0.pos) ? (ls0.size - ls0.pos) : 0u;
          const uint32_t give0 = (rem0 > 0x8000u) ? 0x8000u : rem0;
          (void)mem.WriteU32BE(st + 0, give0);
          (void)mem.WriteU32BE(st + 4, ls0.sbuf + ls0.pos);
          (void)mem.WriteU32BE(st + 8, 0);
          uint32_t stOut0 = 0, stOl0 = 0;
          (void)mem.ReadU32BE(st + 20, &stOut0);
          (void)mem.ReadU32BE(st + 16, &stOl0);
          const uint32_t destCap0 = MclaDestCapFromPstream(outPtr);
          if (stOut0 == 0 || stOut0 == 0xCDCDCDCDu || stOut0 == outPtr)
            (void)mem.WriteU32BE(st + 20, outPtr);
          if (stOl0 == 0 || stOl0 == 0xCDCDCDCDu || stOut0 == outPtr)
            (void)mem.WriteU32BE(st + 16, destCap0);
          // Locals must track the guest state or RSC5-strip is skipped
          // (w22 fatal: consumed stayed 32768 → __imp__ saw RSC5, not XC).
          inLeft = give0;
          inPtr = ls0.sbuf + ls0.pos;
          consumed = 0;
          uint32_t m0 = 0;
          (void)mem.ReadU32BE(inPtr, &m0);
          if (m0 == 0x05435352u || m0 == 0x0FF512EFu)
            magic = m0;
          static std::atomic<uint32_t> s_j2ls{0};
          const uint32_t jn = s_j2ls.fetch_add(1) + 1;
          if (jn <= 32 || (jn % 50) == 0)
            MCLA_LOG_WARN(
                "INFLATE-J2-LAST #{} dest={:08X} st={:08X} sbuf={:08X} "
                "pos={:08X} give={} head={:08X} inPtr={:08X} magic={:08X} "
                "outPtr={:08X} consumed=0",
                jn, ls0.dest, st, ls0.sbuf, ls0.pos, give0, ls0.head, inPtr,
                magic, outPtr);
          served = true;
        } else {
          served = MclaForceServePkgForDest(outPtr, st, /*hostInflate=*/false);
          if (served) {
            // ForceServe primed st; reload locals so strip/__imp__ see it.
            (void)mem.ReadU32BE(st + 0, &inLeft);
            (void)mem.ReadU32BE(st + 4, &inPtr);
            (void)mem.ReadU32BE(st + 8, &consumed);
            if (inLeft >= 4 && inPtr)
              (void)mem.ReadU32BE(inPtr, &magic);
          }
        }
      }
      if (!served) {
        MclaLastServe ls;
        if (MclaFindLastServe(st, outPtr, &ls) && ls.sbuf && ls.size > ls.pos) {
          uint32_t srcBuf = ls.sbuf;
          uint32_t srcOff = ls.pos;
          const uint32_t srcSize = ls.size;
          // w21 continuation: guest consumed from stack staging only — the
          // remaining package bytes stay on the guest-heap body at pos+consumed.
          //
          // F-315: this leg had the SAME defect F-195 fixed on the sibling leg at
          // :8015-8020 — `ls` is a local copy from MclaFindLastServe and nothing
          // here ever wrote ls.pos back, so it stayed pinned at its registration
          // value 0 forever. Every INFLATE-REFORCE line therefore shows
          // pos=00000000, and the only reach was ls.pos+consumed (< srcSize), so
          // once the guest consumed a whole entry both branches failed and
          // srcOff fell back to 0 — re-serving the same head indefinitely (the
          // garage frame-0 stall, F-303 §2). Mirror the sibling: advance the
          // stored cursor by what the guest consumed and persist it, which lets
          // the `srcOff >= srcSize` escape below pull the next package chunk.
          // Gated by kUiServeAdvance, which is otherwise redundant here because
          // kPathBEnqueueUI already satisfies the sibling's condition — so
          // flipping it changes THIS leg and nothing else.
          if (kUiServeAdvance && consumed > 0 && consumed < 0x80000000u &&
              ls.pos + consumed <= ls.size) {
            ls.pos += consumed;
            MclaRecordLastServe(ls);
            srcOff = ls.pos;
          } else if (consumed > 0 && inPtr != 0 && inPtr < 0xA0000000u) {
            const uint32_t afterPos = ls.pos + consumed;
            if (afterPos < srcSize)
              srcOff = afterPos;
            else if (consumed < srcSize)
              srcOff = consumed; // body cursor still at start of this serve
          }
          if (srcOff >= srcSize && IsJob2UiDest(outPtr)) {
            served = MclaForceServePkgForDest(outPtr, st, false);
          } else if (srcOff < srcSize) {
            uint8_t h16[16] = {0};
            (void)mem.ReadBytes(srcBuf + srcOff, h16, 16);
            const uint32_t shead = MclaBE(h16);
            const bool goodHead =
                (shead == 0x05435352u || shead == 0x0FF512EFu ||
                 (h16[0] >= 32 && h16[0] < 127) ||
                 // w21: continuation payload has no RSC/XC head — accept
                 // non-poison remainder when consumed>0.
                 (consumed > 0 && shead != 0xCDCDCDCDu && shead != 0u &&
                  shead != 0xFFFFFFFFu));
            uint32_t remain = srcSize - srcOff;
            if (goodHead && remain >= 16) {
              const uint32_t wasMagic = magic;
              const uint32_t wasInPtr = inPtr;
              const uint32_t wasIn = inLeft;
              const uint32_t wasConsumed = consumed;
              uint32_t give = remain;
              if (give > 0x8000u)
                give = 0x8000u;
              // Re-point inflate state at remaining guest-heap package bytes.
              (void)mem.WriteU32BE(st + 0, give);
              (void)mem.WriteU32BE(st + 4, srcBuf + srcOff);
              inLeft = give;
              inPtr = srcBuf + srcOff;
              if (shead == 0x05435352u || shead == 0x0FF512EFu) {
                magic = shead;
                // Fresh package head — reset consumed so RSC5-strip runs.
                consumed = 0;
                (void)mem.WriteU32BE(st + 8, 0);
              }
              // Plant head into stack staging; heap dests keep inflate output.
              if (ls.dest && ls.dest != 0xCDCDCDCDu &&
                  ls.dest < 0xA0000000u) {
                uint8_t tmp[256];
                uint32_t done = 0;
                const uint32_t plant = (give > 256u) ? 256u : give;
                while (done < plant) {
                  uint32_t chunk = plant - done;
                  if (chunk > sizeof(tmp))
                    chunk = static_cast<uint32_t>(sizeof(tmp));
                  if (!mem.ReadBytes(srcBuf + srcOff + done, tmp, chunk) ||
                      !mem.WriteBytes(ls.dest + done, tmp, chunk))
                    break;
                  done += chunk;
                }
              }
              static std::atomic<uint32_t> s_reforce{0};
              const uint32_t rn = s_reforce.fetch_add(1) + 1;
              if (rn <= 32 || (rn % 50) == 0)
                MCLA_LOG_WARN(
                    "INFLATE-REFORCE #{} st={:08X} path='{}' sbuf={:08X} "
                    "pos={:08X} off={:08X} give={} head={:08X} dest={:08X} "
                    "pkg={:08X} outPtr={:08X} wasMagic={:08X} "
                    "wasInPtr={:08X} wasIn={} wasConsumed={}",
                    rn, st, ls.path, ls.sbuf, ls.pos, srcOff, give, shead,
                    ls.dest, ls.srcPkg, outPtr, wasMagic, wasInPtr, wasIn,
                    wasConsumed);
              served = true;
            }
          }
        }
      }
      // Job #2 dest still unserved on a bad-magic / empty entry — pin now.
      if (!served && IsJob2UiDest(outPtr) &&
          (badMagic || inLeft == 0 || magic == 0u))
        (void)MclaForceServePkgForDest(outPtr, st, /*hostInflate=*/false);
      // w28: job1-style stack-head without a usable LastServe — host-serve
      // the assigned package (A47FD000 → 0x60000 meshtextures) to heap so
      // XMem reads real compressed bytes, not stack residue.
      if (!served && stackPkgHead && outPtr != 0 && outPtr != 0xCDCDCDCDu &&
          !IsJob2UiDest(outPtr)) {
        served = MclaForceServePkgForDest(outPtr, st, /*hostInflate=*/false);
        if (served) {
          (void)mem.ReadU32BE(st + 0, &inLeft);
          (void)mem.ReadU32BE(st + 4, &inPtr);
          (void)mem.ReadU32BE(st + 8, &consumed);
          if (inLeft >= 4 && inPtr)
            (void)mem.ReadU32BE(inPtr, &magic);
          MCLA_LOG_WARN("W28-STACKHEAD-SERVE dest={:08X} st={:08X} "
                        "inPtr={:08X} inLeft={} magic={:08X}",
                        outPtr, st, inPtr, inLeft, magic);
        }
      }
    }
  }

  // w8 CENSUS: dump every inflate outPtr that lands in job #2's dest range
  // so we can see the full fill sequence (B7B41000 → … → B7B61000/B7B71000).
  if (outPtr >= 0xB7000000u && outPtr < 0xB8000000u) {
    static std::atomic<uint32_t> s_outPtrCensus{0};
    const uint32_t oc = s_outPtrCensus.fetch_add(1) + 1;
    if (oc <= 64 || (oc % 200) == 0)
      MCLA_LOG_WARN("INFLATE-OUTPTR #{} outPtr={:08X} outLeft={} produced={} "
                    "inLeft={} consumed={} magic={:08X}",
                    oc, outPtr, outLeft, produced, inLeft, consumed, magic);
    // w30: after guest inflate lands a resource image on the UI container,
    // re-dispatch place then ARR-FIX already-written PSTREAM kids. Host FEX
    // must not touch this dest (guest-owned once rscHead/place vt is live).
    if (outPtr == 0xB7B41000u) {
      uint32_t h = 0;
      (void)mem.ReadU32BE(outPtr, &h);
      static std::atomic<uint32_t> s_w30PostFill{0};
      if (MclaHeadIsResourceImage(h) || MclaHeadIsPlaceVt(h)) {
        const uint32_t pn = s_w30PostFill.fetch_add(1) + 1;
        if (pn <= 6) {
          MCLA_LOG_WARN("W30-POSTFILL #{} dest={:08X} head={:08X} — guest "
                        "fill/place live; host must not FEX/J2-DIST",
                        pn, outPtr, h);
          if (MclaHeadIsResourceImage(h)) {
            if (auto *placeF =
                    mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
              static uint32_t s_w30FillCtx = 0;
              if (s_w30FillCtx == 0)
                s_w30FillCtx = mem.Alloc(64, 16);
              if (s_w30FillCtx) {
                MclaCompleteRscRebaseBeforePlace(outPtr);
                MclaArmRebaseCtx(s_w30FillCtx);
                PPCContext pF{};
                pF.r1 = ctx.r1;
                pF.r13 = ctx.r13;
                pF.r3.u64 = outPtr;
                pF.r4.u64 = s_w30FillCtx;
                MCLA_LOG_WARN("W30-POSTFILL-PLACE #{} obj={:08X} head={:08X}",
                              pn, outPtr, h);
                placeF(pF, mcla::kernel::g_memory.base);
              }
            }
          }
          uint32_t vtF = 0;
          (void)mem.ReadU32BE(outPtr, &vtF);
          if (MclaHeadIsPlaceVt(vtF))
            (void)MclaW30BindPstreamChildren(mem, outPtr, 0);
          // w31: deep dest-range census after guest fill/place.
          if (pn <= 6)
            MclaW31CensusBindPlace(mem, 0);
        }
      }
    }
    // w10: deferred place-pass. If a need-data dest just became live after
    // a prior RSC-PLACE-SKIP, re-run 825EF100 so swfC is constructed from
    // the real rebased RSC data (never a made-up vtable).
    if (outPtr == 0xB7B61000u || outPtr == 0xB7B71000u ||
        outPtr == 0xB79B1000u) {
      uint32_t h = 0;
      (void)mem.ReadU32BE(outPtr, &h);
      const bool live =
          h != 0xCDCDCDCDu && h != 0 && h != 0xFFFFFFFFu;
      if (live && g_mclaRebaseCount > 0 &&
          g_placeDeferred.load() < 4) {
        uint32_t vt = 0, arr = 0, arr0 = 0;
        uint16_t cnt = 0;
        (void)mem.ReadU32BE(g_placeObj + 0, &vt);
        (void)mem.ReadU32BE(g_placeObj + 12, &arr);
        (void)mem.ReadU16BE(g_placeObj + 16, &cnt);
        if (arr && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
          (void)mem.ReadU32BE(arr, &arr0);
        const bool arrLive =
            arr0 != 0xCDCDCDCDu && arr0 != 0 && arr0 != 0xFFFFFFFFu;
        MCLA_LOG_WARN("PLACE-DEFERRED-CHECK #{} outPtr={:08X} head={:08X} "
                      "objVt={:08X} arr={:08X} [arr]={:08X} cnt={} "
                      "arrLive={} nmap={}",
                      oc, outPtr, h, vt, arr, arr0, cnt, arrLive ? 1 : 0,
                      g_mclaRebaseCount);
        if (arrLive) {
          auto *place =
              mcla::kernel::g_memory.FindFunction(0x825EF100u);
          if (place) {
            static uint32_t s_dRebaseCtx = 0;
            if (s_dRebaseCtx == 0)
              s_dRebaseCtx = mem.Alloc(64, 16);
            if (s_dRebaseCtx) {
              // w24: complete 0x50/0x60 rebase + census before guest place.
              MclaCompleteRscRebaseBeforePlace(g_placeObj);
              // w11: arm [group+0] with the PSTREAM region table (do not
              // leave it zero — D828 miss → Resource fatal on 60xxxxxx).
              MclaArmRebaseCtx(s_dRebaseCtx);
              PPCContext pctx;
              pctx.r1 = ctx.r1;
              pctx.r13 = ctx.r13;
              pctx.fpscr = ctx.fpscr;
              pctx.r3.u64 = g_placeObj;
              pctx.r4.u64 = s_dRebaseCtx;
              const uint32_t attempt =
                  g_placeDeferred.fetch_add(1) + 1;
              MCLA_LOG_WARN("RSC-PLACE-DEFERRED #{} obj={:08X} "
                            "rebaseCtx={:08X} hdr={:08X} arr={:08X}",
                            attempt, g_placeObj, s_dRebaseCtx, vt, arr);
              place(pctx, mcla::kernel::g_memory.base);
              uint32_t vt2 = 0, arr2 = 0;
              uint16_t cnt2 = 0;
              (void)mem.ReadU32BE(g_placeObj + 0, &vt2);
              (void)mem.ReadU32BE(g_placeObj + 12, &arr2);
              (void)mem.ReadU16BE(g_placeObj + 16, &cnt2);
              MCLA_LOG_WARN("RSC-PLACE-DEFERRED-DONE #{} vt={:08X} arr={:08X} "
                            "cnt={} (want 8208xxxx)",
                            attempt, vt2, arr2, cnt2);
              if ((vt2 & 0xFFFF0000u) == 0x82080000u) {
                g_placeDeferred.store(100); // success — stop retrying
                // w30: bind already-written PSTREAM kids after deferred place.
                (void)MclaW30BindPstreamChildren(mem, g_placeObj, 0);
              }
            }
          }
        }
      }
    }
    // F-319 (REVERTED OFF — keep for the diagnosis, do not re-try in this form):
    // a UI .xsf stream with a tiny leftover is NOT complete — it has filled its
    // current dest window and the refill at the `inLeft == 0` block can only
    // trigger on exactly zero. w279 measured the collision: garage dest
    // B7A41000 consumed five consecutive windows (32,748 → 196,588 = 32,748 +
    // 5×32,768, 20 XMem calls vs one in w274), filled its whole 131,072-byte
    // PSTREAM window (XMEM-SZPTR `*destSz 131072->0`), then sat at inLeft=35
    // until UNSTUCK zeroed outLeft.
    // Tried: re-read the package at walkPos-inLeft and re-prime st+0/st+4 — the
    // offset arithmetic was RIGHT (w280: `readAt=649A7FDD` = 0x64980000+0x2FFDD,
    // exactly walkPos-35, `got=32768`) and it fired once, but the boot then
    // spun to **704,373 lines vs w279's 57,892**, of which **451,084 name this
    // dest** and 112,786 are INFLATE-ENTER at `consumed=196553` FROZEN.
    // **Why it fails, and this is the useful part: the wall there is OUTPUT
    // capacity, not input starvation.** The dest window is full, so every
    // InflateStep writes 0 bytes, outLeft never reaches its caller-loop exit key
    // on its own, and removing UNSTUCK's exit leaves the guest's own loop
    // spinning. So the garage needs the consumer to drain the window and hand the
    // stream a NEW dest — which is exactly T41.11's multi-window fill (closed
    // not-viable in F-303 on frame-0 cursor reset + slot clobber), reachable only
    // from the place-pass/consumer side, NOT from the serve side. UNSTUCK's
    // zero-outLeft is crude but it is what lets the rest of the boot proceed.
    if (kUiXsfTailTopup && inLeft > 0 && inLeft < 256 && outLeft > 0 &&
        MclaUiXsfChunkOpen(st, outPtr)) {
      static std::mutex s_tailMtx;
      static uint32_t s_tailBuf = 0;
      std::lock_guard<std::mutex> tlk(s_tailMtx);
      uint32_t pkgOff = 0, walkPos = 0;
      {
        std::lock_guard<std::mutex> wl(g_destPkgMtx);
        pkgOff = g_destPkgOff[outPtr];
        walkPos = g_destPkgWalk[outPtr];
      }
      if (walkPos >= inLeft) {
        if (s_tailBuf == 0)
          s_tailBuf = mem.Alloc(0x8000, 16);
        std::vector<uint8_t> tmp(0x8000);
        auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
        mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
        uint64_t got = 0;
        bool ok = vfs.OpenFile("xarchive_cache.rpf", fh);
        if (ok) {
          ok = vfs.ReadFileAt(fh, pkgOff + walkPos - inLeft, tmp.data(),
                              0x8000, got) && got >= 0x8000;
          vfs.CloseFile(fh);
        }
        if (ok && s_tailBuf &&
            mem.WriteBytes(s_tailBuf, tmp.data(), static_cast<uint32_t>(got))) {
          const uint32_t newWalk = walkPos - inLeft + static_cast<uint32_t>(got);
          {
            std::lock_guard<std::mutex> wl(g_destPkgMtx);
            g_destPkgWalk[outPtr] = newWalk;
          }
          (void)mem.WriteU32BE(st + 0, static_cast<uint32_t>(got));
          (void)mem.WriteU32BE(st + 4, s_tailBuf);
          static std::atomic<uint32_t> s_tailN{0};
          const uint32_t tn = s_tailN.fetch_add(1) + 1;
          MCLA_LOG_WARN("UIXSF-TAIL-TOPUP #{} dest={:08X} pkg={:08X} "
                        "wasInLeft={} readAt={:08X} got={} → in={} walk={:08X} "
                        "consumed={}",
                        tn, outPtr, pkgOff, inLeft, pkgOff + walkPos - inLeft,
                        got, got, newWalk, consumed);
          return;  // don't run InflateStep on a 35-byte unusable buffer
        }
      }
    }
    // w8 UNSTUCK: stream has a tiny unusable leftover (all real input
    // consumed) but outLeft>0 so the caller never advances to the next
    // dest. After a few sightings, zero outLeft — the caller loop's
    // "stream complete" key — so B7B61000/B7B71000 get their turn.
    if (inLeft > 0 && inLeft < 256 && outLeft > 0 && produced > 0) {
      static std::mutex s_unstuckMtx;
      static std::unordered_map<uint32_t, uint32_t> s_unstuck;
      uint32_t &uc = [&]() -> uint32_t & {
        std::lock_guard<std::mutex> lk(s_unstuckMtx);
        return s_unstuck[st];
      }();
      uc++;
      if (uc >= 16) {
        MCLA_LOG_WARN("INFLATE-UNSTUCK #{} outPtr={:08X} inLeft={} "
                      "produced={} consumed={} outLeft={} slotcov={} — zero "
                      "outLeft",
                      uc, outPtr, inLeft, produced, consumed, outLeft,
                      MclaUiXsfSlotCov(outPtr));
        (void)mem.WriteU32BE(st + 0, 0);  // inLeft = 0
        (void)mem.WriteU32BE(st + 16, 0); // outLeft = 0
        uc = 0;
        return;
      }
    }
  }

  // w23 lever (INFLATE-J2-CONT): job2 dest spinning on non-XC continuation
  // with produced>0 (shared-state leftover or junk walk head — w22
  // B7B71000 magic=EA77D236; w23 B7021000 same after list miss).
  // UNSTUCK only catches inLeft<256; this catches the large-inLeft spin.
  // Progress (produced↑ or outLeft↓) resets the spin so legitimate
  // mid-stream XCompress block headers (058E0402/07B00083/…) still reach
  // __imp__. No-progress: poison dest gets an RSC5 LastServe window so
  // guest inflate can finish; cap retries then drain outLeft — the
  // caller-loop stream-complete key — so job2 streams advance to
  // POST-EXEC #2 / place-pass. Never plant compressed bytes into dests.
  {
    static std::mutex s_j2cMtx;
    static std::unordered_map<uint32_t, uint32_t> s_j2cSpin;
    static std::unordered_map<uint32_t, uint32_t> s_j2cProd;
    static std::unordered_map<uint32_t, uint32_t> s_j2cOl;
    const bool j2cDest = IsJob2UiDest(outPtr);
    const bool j2cAnyB7 =
        outPtr >= 0xB7000000u && outPtr < 0xB8000000u && outLeft > 0 &&
        produced > 0 && magic != kXCompressMagic && magic != 0x05435352u;
    if (j2cDest && j2cAnyB7) {
      uint32_t &j2spin = [&]() -> uint32_t & {
        std::lock_guard<std::mutex> lk(s_j2cMtx);
        return s_j2cSpin[outPtr];
      }();
      uint32_t &j2prod = [&]() -> uint32_t & {
        std::lock_guard<std::mutex> lk(s_j2cMtx);
        return s_j2cProd[outPtr];
      }();
      uint32_t &j2ol = [&]() -> uint32_t & {
        std::lock_guard<std::mutex> lk(s_j2cMtx);
        return s_j2cOl[outPtr];
      }();
      const bool progressed =
          (produced > j2prod) || (outLeft < j2ol && j2ol != 0);
      if (progressed) {
        j2spin = 0;
        j2prod = produced;
        j2ol = outLeft;
      } else {
        j2spin++;
        j2prod = produced;
        j2ol = outLeft;
      }
      uint32_t j2h0 = 0;
      (void)mem.ReadU32BE(outPtr, &j2h0);
      const bool j2poison =
          (j2h0 == 0xCDCDCDCDu || j2h0 == 0 || j2h0 == 0xFFFFFFFFu);
      if (j2spin >= 4 || (j2spin == 0 && j2poison))
        MCLA_LOG_WARN(
            "INFLATE-J2-CONT #{} dest={:08X} magic={:08X} produced={} "
            "outLeft={} inLeft={} consumed={} head={:08X} poison={} prog={}",
            j2spin, outPtr, magic, produced, outLeft, inLeft, consumed, j2h0,
            j2poison ? 1 : 0, progressed ? 1 : 0);

      // No-progress + poison dest — re-point at a real RSC5/XC window and
      // reset per-dest produced/outLeft/consumed so guest inflate finishes.
      // w25 FIX: once g_job2SharedWalk > 0 the package stream has already
      // progressed — re-serving the package HEAD into a continuation dest
      // fills it with the START of the decompressed image (same bytes as
      // B7B41000) instead of the virtual slice that becomes child objects.
      // Prefer: (a) dest-keyed LastServe if it is NOT the package head,
      // (b) next shared-walk window, (c) host decompress+distribute.
      if (!progressed && j2poison && j2spin <= 4 &&
          magic != 0x0FF512EFu) {
        uint32_t sharedWalk = 0;
        {
          std::lock_guard<std::mutex> wl(g_job2SharedMtx);
          sharedWalk = g_job2SharedWalk;
        }
        MclaLastServe ls0;
        if (MclaFindLastServe(0, outPtr, &ls0) && ls0.sbuf &&
            ls0.size > ls0.pos) {
          uint32_t mh = 0;
          (void)mem.ReadU32BE(ls0.sbuf + ls0.pos, &mh);
          const bool isPkgHead =
              (mh == 0x05435352u || mh == 0x0FF512EFu);
          // w25: skip package-head LastServe when the shared walk already
          // advanced — that window is the wrong virtual slice.
          if (isPkgHead && sharedWalk > 0x8000u) {
            MCLA_LOG_WARN(
                "INFLATE-J2-WIN-SKIPHEAD #{} dest={:08X} head={:08X} "
                "sharedWalk={:08X} (continuation dest — no pkg-head re-serve)",
                j2spin, outPtr, mh, sharedWalk);
          } else if (isPkgHead || mh != 0) {
            const uint32_t give0 = (ls0.size - ls0.pos > 0x8000u)
                                       ? 0x8000u
                                       : (ls0.size - ls0.pos);
            (void)mem.WriteU32BE(st + 0, give0);
            (void)mem.WriteU32BE(st + 4, ls0.sbuf + ls0.pos);
            (void)mem.WriteU32BE(st + 8, isPkgHead ? 0u : 1u);
            (void)mem.WriteU32BE(st + 20, outPtr);
            (void)mem.WriteU32BE(st + 16, MclaDestCapFromPstream(outPtr));
            (void)mem.WriteU32BE(st + 24, 0);
            j2spin = 0;
            MCLA_LOG_WARN(
                "INFLATE-J2-WIN #{} dest={:08X} sbuf={:08X} give={} "
                "head={:08X} (dest-keyed LastServe RSC5/XC)",
                j2spin, outPtr, ls0.sbuf + ls0.pos, give0, mh);
            return;
          }
        }
        // w25: shared walk already started — serve the NEXT compressed
        // window ONLY if it still carries RSC5/XC head. Mid-stream XC
        // continuation bytes are NOT independently inflatable; serving them
        // as LastServe made J2-LAST re-feed junk (913F58A1) forever and
        // Job2 never reached POST-EXEC. Fall through to package-head RSC5
        // (w24 proven) when the continuation head is not decodable.
        if (sharedWalk > 0) {
          const uint32_t baseOff = AssignPackageForDest(outPtr);
          std::vector<uint8_t> pkgWin;
          if (MclaLoadPkgWindow(baseOff, sharedWalk, 0x8000u, pkgWin) &&
              pkgWin.size() >= 16) {
            const uint32_t chead = MclaBE(pkgWin.data());
            const bool contDecodable =
                (chead == 0x05435352u || chead == 0x0FF512EFu);
            if (contDecodable) {
              static std::mutex s_j2bMtx;
              static std::unordered_map<uint32_t, uint32_t> s_j2cBounce;
              uint32_t bounce = 0;
              {
                std::lock_guard<std::mutex> bl(s_j2bMtx);
                bounce = s_j2cBounce[outPtr];
                if (bounce == 0) {
                  bounce = mem.Alloc(0x8000, 16);
                  s_j2cBounce[outPtr] = bounce;
                }
              }
              if (bounce &&
                  mem.WriteBytes(bounce, pkgWin.data(),
                                 static_cast<uint32_t>(pkgWin.size()))) {
                const uint32_t give0 = static_cast<uint32_t>(pkgWin.size());
                const uint32_t destCap = MclaDestCapFromPstream(outPtr);
                (void)mem.WriteU32BE(st + 0, give0);
                (void)mem.WriteU32BE(st + 4, bounce);
                (void)mem.WriteU32BE(st + 8, 0);
                (void)mem.WriteU32BE(st + 20, outPtr);
                (void)mem.WriteU32BE(st + 16, destCap);
                (void)mem.WriteU32BE(st + 24, 0);
                MclaLastServe ls;
                ls.sbuf = bounce;
                ls.pos = 0;
                ls.size = give0;
                ls.stCand = st;
                ls.dest = outPtr;
                ls.want = give0;
                ls.srcPkg = baseOff;
                ls.path = "j2-win-cont";
                ls.head = chead;
                MclaRecordLastServe(ls);
                {
                  std::lock_guard<std::mutex> wl2(g_job2SharedMtx);
                  g_job2SharedWalk = sharedWalk + give0;
                }
                j2spin = 0;
                MCLA_LOG_WARN(
                    "INFLATE-J2-WIN-CONT #{} dest={:08X} bounce={:08X} "
                    "walk={:08X} head={:08X} give={} destCap={}",
                    j2spin, outPtr, bounce, sharedWalk, chead, give0,
                    destCap);
                return;
              }
            } else {
              MCLA_LOG_WARN("INFLATE-J2-WIN-CONT-SKIP #{} dest={:08X} "
                            "walk={:08X} head={:08X} (not RSC5/XC — "
                            "fall back to pkg-head / drain)",
                            j2spin, outPtr, sharedWalk, chead);
            }
          }
        }
        // LastServe window was junk AND walk==0 — package-head RSC5 OK only
        // for the first dest of the package.
        const uint32_t baseOff = AssignPackageForDest(outPtr);
        std::vector<uint8_t> pkgWin;
        if (MclaLoadPkgWindow(baseOff, 0, 0x8000u, pkgWin) &&
            pkgWin.size() >= 16) {
          const uint32_t head = MclaBE(pkgWin.data());
          if (head == 0x05435352u || head == 0x0FF512EFu) {
            static std::mutex s_j2bMtx;
            static std::unordered_map<uint32_t, uint32_t> s_j2cBounce;
            uint32_t bounce = 0;
            {
              std::lock_guard<std::mutex> bl(s_j2bMtx);
              bounce = s_j2cBounce[outPtr];
              if (bounce == 0) {
                bounce = mem.Alloc(0x8000, 16);
                s_j2cBounce[outPtr] = bounce;
              }
            }
            if (bounce &&
                mem.WriteBytes(bounce, pkgWin.data(),
                               static_cast<uint32_t>(pkgWin.size()))) {
              const uint32_t give0 = static_cast<uint32_t>(pkgWin.size());
              const uint32_t destCap = MclaDestCapFromPstream(outPtr);
              (void)mem.WriteU32BE(st + 0, give0);
              (void)mem.WriteU32BE(st + 4, bounce);
              (void)mem.WriteU32BE(st + 8, 0);
              (void)mem.WriteU32BE(st + 20, outPtr);
              (void)mem.WriteU32BE(st + 16, destCap);
              (void)mem.WriteU32BE(st + 24, 0);
              MclaLastServe ls;
              ls.sbuf = bounce;
              ls.pos = 0;
              ls.size = give0;
              ls.stCand = st;
              ls.dest = outPtr;
              ls.want = give0;
              ls.srcPkg = baseOff;
              ls.path = "j2-win-rsc5";
              ls.head = head;
              MclaRecordLastServe(ls);
              j2spin = 0;
              MCLA_LOG_WARN(
                  "INFLATE-J2-WIN #{} dest={:08X} bounce={:08X} "
                  "pkg={:08X} head={:08X} give={} destCap={} "
                  "(RSC5 package-head window for poison dest)",
                  j2spin, outPtr, bounce, baseOff, head, give0, destCap);
              return;
            }
          }
        }
      }

      // Cap: no-progress drain outLeft so the caller loop advances.
      constexpr uint32_t kJ2ContDrainCap = 8u;
      if (!progressed && j2spin >= kJ2ContDrainCap) {
        MCLA_LOG_WARN(
            "INFLATE-J2-DRAIN #{} dest={:08X} magic={:08X} produced={} "
            "outLeft={} inLeft={} consumed={} head={:08X} — zero outLeft "
            "(caller loop key)",
            j2spin, outPtr, magic, produced, outLeft, inLeft, consumed, j2h0);
        (void)mem.WriteU32BE(st + 0, 0);  // inLeft = 0
        (void)mem.WriteU32BE(st + 16, 0); // outLeft = 0
        j2spin = 0;
        return;
      }

      // No-progress mid-cap junk: skip __imp__ (guest decoder would spin).
      // Progressed mid-stream XC falls through to __imp__.
      if (!progressed && j2spin > 0)
        return;
    }
    // Backup drain: any B7* dest with no-progress junk continuation
    // (covers job2 PSTREAM pbase not yet listed). Same cap, same key.
    //
    // F-318: EXEMPT a UI .xsf dest that still has package windows to serve. This
    // branch is why two earlier attempts at the refill site did nothing at all:
    // its `return` at the b7spin>0 line below runs BEFORE the inLeft==0 refill
    // block, so a garage dest that is merely waiting for window #2 is counted as
    // "no-progress junk", spun 12 times, and then killed by the zero-outLeft bail
    // — w277: INFLATE-J2-DRAIN-B7 #12 dest=B7A41000 magic=00000000 produced=327680
    // outLeft=131072 consumed=65516 with 65,516 of 1,066,057 bytes delivered.
    // Skipping it here lets control fall through to the refill, which is bounded
    // twice over (retries < 400, and MclaUiXsfChunkOpen goes false at
    // walk >= PackageSizeAt → the drain resumes).
    else if (j2cAnyB7 && outPtr >= 0xB7000000u &&
             !(kUiXsfChunkFeed && MclaUiXsfChunkOpen(st, outPtr))) {
      static std::mutex s_b7cMtx;
      static std::unordered_map<uint32_t, uint32_t> s_b7cSpin;
      static std::unordered_map<uint32_t, uint32_t> s_b7cProd;
      static std::unordered_map<uint32_t, uint32_t> s_b7cOl;
      uint32_t &b7spin = [&]() -> uint32_t & {
        std::lock_guard<std::mutex> lk(s_b7cMtx);
        return s_b7cSpin[outPtr];
      }();
      uint32_t &b7prod = [&]() -> uint32_t & {
        std::lock_guard<std::mutex> lk(s_b7cMtx);
        return s_b7cProd[outPtr];
      }();
      uint32_t &b7ol = [&]() -> uint32_t & {
        std::lock_guard<std::mutex> lk(s_b7cMtx);
        return s_b7cOl[outPtr];
      }();
      const bool progressed =
          (produced > b7prod) || (outLeft < b7ol && b7ol != 0);
      if (progressed) {
        b7spin = 0;
        b7prod = produced;
        b7ol = outLeft;
      } else {
        b7spin++;
        b7prod = produced;
        b7ol = outLeft;
      }
      if (!progressed && b7spin >= 12) {
        MCLA_LOG_WARN(
            "INFLATE-J2-DRAIN-B7 #{} dest={:08X} magic={:08X} produced={} "
            "outLeft={} consumed={} slotcov={} — zero outLeft (backup)",
            b7spin, outPtr, magic, produced, outLeft, consumed,
            MclaUiXsfSlotCov(outPtr));
        (void)mem.WriteU32BE(st + 0, 0);
        (void)mem.WriteU32BE(st + 16, 0);
        b7spin = 0;
        return;
      }
      if (!progressed && b7spin > 0)
        return;
    }
  }

  // Session 72: empty input â€” nothing to inflate. The guest re-enters with
  // in=0 consumed=0xFFFFFFF4 forever (INFLATE #286600+). Mark the stream
  // fully consumed so the caller's progress check exits; do not call the
  // original (it would spin or AV on a corrupt state).
  //
  // Session 73 decode of the caller loop (ppc_recomp.15.cpp, LR 0x821BC380):
  //   loc_821BC2D4: if (state.inLeft != 0) goto InflateStep;
  //                 ... async input refill (Sleep(100)-paced) ...
  //   loc_821BC374: InflateStep(state);
  //                 if (state.outLeft /*[r1+112]=state+16*/ != 0) goto 2D4;
  //               exit per stream when outLeft == 0
  // The caller refills input BEFORE re-entering InflateStep, so InflateStep
  // never sees inLeft==0 on a live stream â€” reaching here means the stream
  // is dead/empty. Zeroing outLeft is the caller's own "stream complete"
  // key (same path a descriptor with expected==0 takes); without it the
  // guest spins on the loop forever (INFLATE-EMPTY x1663).
  if (inLeft == 0) {
    // Session 73: empty input â€” original code spun forever (INFLATE
    // x286600+) on a stream whose refill never delivered, so we bailed by
    // zeroing outLeft (the caller loop's exit key).
    //
    // Session 75p CORRECTION: the boot init enqueues batches of streams and
    // calls InflateStep BEFORE the async input refill delivers. Killing
    // those (produced=0, sequential outPtrs, all in one burst) aborted the
    // boot's next load batch â€” the emu has been stalling itself. Distinguish:
    //  - fresh/pending stream (no real progress yet): return WITHOUT touching
    //    state; the caller's own refill pacing re-polls until data arrives.
    //  - genuinely dead (no input after ~20s of paced retries, or the -12
    //    EOF artifact after partial consumption): bail as before.
    static std::mutex s_emptyMtx;
    static std::unordered_map<uint32_t, uint32_t> s_emptyRetries;
    const bool fresh = (consumed == 0 || consumed == 0xFFFFFFF4u) &&
                       produced == 0;
    uint32_t &retries = [&]() -> uint32_t & {
      std::lock_guard<std::mutex> lk(s_emptyMtx);
      return s_emptyRetries[st];
    }();
    // w9: dests that already produced output are mid-stream dead leftovers
    // (tiny unusable tail after the package ended). Waiting the full 20s
    // each stalls the soak. Bail those after ~2.4s; keep 20s for fresh
    // dests still waiting on the async refill.
    //
    // w10: need-data dests (B79B1000 / B7B61000 / B7B71000) are job #2's
    // remaining inflate sinks for the swfC arr. produced>0 on those is a
    // LEFTOVER from the prior dest in the shared inflater state — trimming
    // them at 24 retries starved the dest (RSC-PLACE-SKIP). Exempt them.
    const bool needArrData =
        (outPtr == 0xB7B61000u || outPtr == 0xB7B71000u ||
         outPtr == 0xB79B1000u);
    // F-318: a standalone UI .xsf stream is mid-stream, not dead. w276/w277 show
    // garage dest B7A41000 reaching inLeft=0 with consumed=65516 (one 32 KiB
    // window already served), spinning ~9 times and then being killed by the
    // backup drain (INFLATE-J2-DRAIN-B7 "zero outLeft") + FLUSH — i.e. the
    // emulator aborts its own load, exactly the Session 75p mistake, for the one
    // container whose decoded size (1066057) exceeds the host-decode fit test at
    // :7884. The per-dest refill below ALREADY walks g_destPkgWalk a window at a
    // time with its own CAP/DONE bounds, but it only fires on `retries == 3`
    // (once) and the budget for produced>0 is 24, so it can never deliver more
    // than one window. Both are keyed on the dynamic dest->pkg map, not an
    // address, per directive #5; MclaUiXsfChunkOpen returns false once the walk
    // passes PackageSizeAt, so this cannot spin past the package.
    const bool uiXsfStream = kUiXsfChunkFeed && MclaUiXsfChunkOpen(st, outPtr);
    const uint32_t maxEmptyRetries =
        (needArrData || uiXsfStream)
            ? 400u
            : ((produced > 0) ? 24u : 200u);
    if (inPtr != 0 && outPtr != 0 && outLeft != 0 &&
        retries < maxEmptyRetries) {
      retries++;
      // p2z: after a few empty retries, host-serve 32KB of RSC5+XCompress
      // from the cache RPF so inflate can proceed (guest Read returns 0).
      //
      // w10: need-data dests re-serve on a cadence (not only retries==3)
      // because a single 32KB window is not enough to materialize arr.
      const bool hsThisRetry =
          needArrData ? (retries == 3 || (retries > 3 && (retries % 8) == 0))
                      : (retries == 3 || uiXsfStream);
      if (hsThisRetry) {
        static std::mutex s_hsMtx;
        static uint32_t s_hsBuf = 0;
        // F-349: a separate buffer for the whole-stream window, so a failed or
        // disabled whole-stream serve cannot shrink what the legacy 0x8400 path
        // hands to non-UI dests.
        static uint32_t s_wsBuf = 0;
        std::lock_guard<std::mutex> hlk(s_hsMtx);
        // w18: per-dest package cursor. Job2 UI dests stay on 0xA0000; other
        // B7* dests each get an unused RSC5 package from the host table.
        // Shared sequential walks after the first package head were the
        // INFLATE-HOSTSERVE-STOP 6655A8B1 family.
        uint32_t baseOff = AssignPackageForDest(outPtr);
        uint32_t walkPos = 0;
        uint32_t readOff = baseOff;
        {
          std::lock_guard<std::mutex> wl(g_destPkgMtx);
          walkPos = g_destPkgWalk[outPtr];
          readOff = baseOff + walkPos;
        }
        // F-320: for a UI .xsf stream, the STREAM owns the package and the
        // cursor. A successor PSTREAM slot has no g_destPkgOff entry, so
        // AssignPackageForDest would guess (the F-247 wrong-package hazard that
        // produced the produced=0 livelocks), and its g_destPkgWalk starts at 0
        // and would re-serve bytes the guest already consumed — the w275
        // re-serve failure in a new place. Take the stream's package and advance
        // past everything already delivered on this inflate state.
        uint32_t frLen = 0;  // F-327: frame-aligned window size, 0 = legacy
        bool headServe = false;  // F-347: this window is the stream's preamble
        const uint32_t sPkg =
            kUiXsfChunkFeed ? MclaUiXsfStreamPkg(st, outPtr) : 0u;
        if (sPkg != 0) {
          uint32_t sWalk = 0;
          {
            std::lock_guard<std::mutex> lk(g_uiXsfStreamMtx);
            sWalk = g_uiXsfStreamWalk[st];
          }
          baseOff = sPkg;
          if (sWalk > walkPos)
            walkPos = sWalk;
          readOff = baseOff + walkPos;
          // F-347: present the stream where the guest's own preamble check
          // looks. `sub_821D5E10` (generated/ppc_xenon/ppc_recomp.18.cpp:10832,
          // the algorithm read in F-328) tests [inPtr+0] against the XCompress
          // magic, takes the stream total from [inPtr+4], and skips 8 bytes —
          // and w335 `XMEM-SRCHEAD #5` shows both facts of that layout in this
          // container: 0x0FF512EF at pkg+0x0C and the declared total 1,066,057
          // at pkg+0x10, so the check fires at +0x0C and the skip lands the
          // walk on pkg+0x14, which is exactly where the byte-exact offline
          // decoder (`src/xmem_lzx.h:531-552`) starts. Serving pkg+0 instead —
          // what every Path B refill has done since F-251 — hands the frame
          // driver the 20-byte RSC5 container header as if it were a frame
          // header, and w334 shows the result: `w12300` (header position)
          // 5650→23001→55769→24659→1680, i.e. nonsense, and every frame from
          // the first returning −1 while the container call still says S_OK.
          // The window advance below already computes `readOff - baseOff + got`,
          // so continuation windows line up with the 8 bytes the guest skips.
          // MEASURED w336: the skip does happen (src +8, srcSz -8) and coverage
          // is unmoved — the flag's comment carries the whole result.
          if (kUiXsfStreamHeadServe && sWalk == 0u) {
            headServe = true;
            walkPos = 12u;
            readOff = baseOff + walkPos;
          }
          // F-327: replace the fixed stride with THIS frame's byte count. The
          // first window keeps the 20-byte container header in front of frame 0
          // because that is what the guest successfully consumed in w277/w297
          // (`consumed=32748` = 20 + 2 + 32,726); every later window starts
          // exactly on a frame header.
          if (kUiXsfFrameServe) {
            uint32_t fpos = 0;
            {
              std::lock_guard<std::mutex> lk(g_uiXsfStreamMtx);
              fpos = g_uiXsfStreamFrame[st];
            }
            const bool first = (fpos == 0u);
            uint32_t hl = 0, pay = 0, uf = 0;
            if (MclaUiXsfFrameAt(baseOff, first ? 20u : fpos, hl, pay, uf)) {
              const uint32_t len = (first ? 20u : 0u) + hl + pay;
              if (len <= 0x8400u) {
                walkPos = first ? 0u : fpos;
                readOff = baseOff + walkPos;
                frLen = len;
              }
            }
          }
          // Publish the mapping for this slot too, so the top-of-hook Path A
          // decoder and the drain exemption see it from the next entry on.
          std::lock_guard<std::mutex> wl(g_destPkgMtx);
          g_destPkgOff[outPtr] = baseOff;
        }
        if (kUiXsfPrivateCtx && sPkg != 0u && mem.IsValid(objAtEntry, 4u)) {
          uint32_t priv = 0;
          {
            std::lock_guard<std::mutex> pl(g_uiXsfPrivMtx);
            const auto it = g_uiXsfPrivCtx.find(st);
            if (it != g_uiXsfPrivCtx.end())
              priv = it->second;
          }
          if (priv == 0u) {
            // F-338: w316 died because that allocation returned 0xCAF28300 -- the
            // garage's LIVE serve window -- so each private context aliased its own
            // input. Ask for twice what is needed and use the SECOND half: the block
            // the allocator hands out first is the one the legacy serve keeps using,
            // so the two ranges cannot overlap. Both are printed to make the claim
            // checkable in the log rather than asserted in a comment.
            const uint32_t raw = mem.Alloc(0x6A000u, 16);
            const uint32_t blk = raw != 0u ? raw + 0x35000u : 0u;
            if (raw != 0u)
              MCLA_LOG_WARN("UIXSF-PRIVCTX #{} alloc raw={:08X}..{:08X} ctx={:08X}",
                            n, raw, raw + 0x6A000u, blk);
            if (blk != 0u) {
              PPCContext q{};
              q.r1.u64 = ctx.r1.u32 - 0x400u;
              q.r13.u64 = 0x8F200000u;
              q.r3.u64 = 0x8EFFF990u;
              q.r4.u64 = 1u;
              q.r5.u64 = blk;
              q.r6.u64 = 0x3492Eu;
              q.lr = 0x824613D4u;
              __imp__sub_82461378(q, mcla::kernel::g_memory.base);
              priv = blk;
              std::lock_guard<std::mutex> pl(g_uiXsfPrivMtx);
              g_uiXsfPrivCtx[st] = priv;
              g_uiXsfPrivSet.insert(priv);
              if (g_uiXsfSharedCtx.load() == 0u) {
                uint32_t cur0 = 0;
                if (mem.ReadU32BE(objAtEntry, &cur0) && cur0 != 0u &&
                    cur0 != 0xCDCDCDCDu)
                  g_uiXsfSharedCtx.store(cur0);
              }
              MCLA_LOG_WARN("UIXSF-PRIVCTX #{} st={:08X} pkg={:08X} opened "
                            "private ctx={:08X} (shared is 4000FD80)",
                            n, st, sPkg, priv);
            } else {
              MCLA_LOG_WARN("UIXSF-PRIVCTX #{} st={:08X} ALLOC FAILED", n, st);
            }
          }
          static uint32_t s_privSeen = 0;
          if (s_privSeen < 4u) {
            ++s_privSeen;
            uint32_t c0 = 0;
            (void)mem.ReadU32BE(objAtEntry, &c0);
            MCLA_LOG_WARN("UIXSF-PRIVCTX #{} st={:08X} pkg={:08X} obj={:08X} "
                          "*obj={:08X} priv={:08X}",
                          n, st, sPkg, objAtEntry, c0, priv);
          }
          if (priv != 0u) {
            uint32_t cur = 0;
            if (mem.ReadU32BE(objAtEntry, &cur) && cur != priv && cur != 0u &&
                cur != 0xCDCDCDCDu) {
              (void)mem.WriteU32BE(objAtEntry, priv);
              static uint32_t s_swLog = 0;
              if (s_swLog < 8u) {
                ++s_swLog;
                MCLA_LOG_WARN("UIXSF-PRIVCTX #{} obj={:08X} ctx {:08X} -> "
                              "{:08X}", n, objAtEntry, cur, priv);
              }
            }
          }
        }
        // F-340: keep the shared codec context with one container at a time.
        if (kUiXsfSerializeCtx && sPkg != 0u) {
          bool defer = false;
          uint32_t owner = 0, seen = 0;
          {
            std::lock_guard<std::mutex> olk(g_uiXsfOwnerMtx);
            owner = g_uiXsfCtxOwner;
            if (owner == 0u) {
              g_uiXsfCtxOwner = sPkg;
              owner = sPkg;
            }
            if (owner != sPkg) {
              seen = ++g_uiXsfStalls[sPkg];
              if (seen <= kUiXsfCtxStallCap)
                defer = true;
              else {
                g_uiXsfCtxOwner = sPkg;  // hand the context over, stop deferring
                owner = sPkg;
              }
            }
          }
          if (defer) {
            if (seen <= 3u || (seen % 20u) == 0u)
              MCLA_LOG_WARN("UIXSF-CTX-OWNER #{} pkg={:08X} held by pkg={:08X} "
                            "-> defer this stream (stall {}/{})",
                            n, sPkg, owner, seen, kUiXsfCtxStallCap);
            return;
          }
          static uint32_t s_ownLog = 0;
          if (s_ownLog < 6u) {
            ++s_ownLog;
            MCLA_LOG_WARN("UIXSF-CTX-OWNER #{} pkg={:08X} HOLDS the shared ctx "
                          "(st={:08X})", n, sPkg, st);
          }
        }
        // F-334: ask the guest's own buffer where it is, before deciding what to
        // write. Log-only, ≤6 lines per inflate state. This is the reachability
        // fix after w309 showed the first version's guard (inLeft >= 16) made it
        // print nothing at the one moment that matters.
        if (kUiXsfLocate && sPkg != 0u) {
          uint32_t lwalk = 0;
          {
            std::lock_guard<std::mutex> lk(g_uiXsfStreamMtx);
            lwalk = g_uiXsfStreamWalk[st];
          }
          MclaUiXsfLocateStream(st, sPkg, inPtr, inLeft, lwalk);
        }
        // F-335: the append-only window takes this stream over entirely; the
        // legacy re-point below keeps serving everything else.
        if (kUiXsfAppendWindow && sPkg != 0u &&
            MclaUiXsfAppendServe(n, st, sPkg, walkPos, inPtr, inLeft))
          return;
        // F-349: the whole-stream window, used only when this is a UI .xsf
        // stream's first presentation. `s_wsBuf` is separate from `s_hsBuf` so a
        // failed 2 MB allocation leaves the legacy 0x8400 path exactly as it was.
        if (kUiXsfWholeStreamWindow && headServe && s_wsBuf == 0)
          s_wsBuf = mem.Alloc(kUiXsfWholeCap, 16);
        if (s_hsBuf == 0)
          // F-327: 0x8400 so a full frame plus its header always fits.
          s_hsBuf = mem.Alloc(0x8400, 16);
        const bool wholeWin =
            kUiXsfWholeStreamWindow && headServe && s_wsBuf != 0u;
        const uint32_t hsBuf = wholeWin ? s_wsBuf : s_hsBuf;
        if (hsBuf) {
          auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
          mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
          uint32_t winLen = frLen ? frLen : 0x8000u;
          if (wholeWin) {
            // The container's own declared length plus one window, bounded by the
            // allocation actually made. Reading past the member end returns a short
            // `got`, which the existing advance (`readOff - baseOff + got`) handles.
            const uint32_t need = MclaUiXsfWalkCeil(baseOff);
            winLen = need < kUiXsfWholeCap ? need : kUiXsfWholeCap;
          }
          std::vector<uint8_t> tmp(winLen);
          uint64_t got = 0;
          bool ok = vfs.OpenFile("xarchive_cache.rpf", fh);
          if (ok) {
            ok = vfs.ReadFileAt(fh, readOff, tmp.data(), winLen, got);
            vfs.CloseFile(fh);
          }
          if (ok && got > 16) {
            const uint32_t be =
                (uint32_t(tmp[0]) << 24) | (uint32_t(tmp[1]) << 16) |
                (uint32_t(tmp[2]) << 8) | uint32_t(tmp[3]);
            constexpr uint32_t kRsc5 = 0x05435352u;
            constexpr uint32_t kXCompress = 0x0FF512EFu;
            const bool isPkgHead = (be == kRsc5 || be == kXCompress);
            // F-346: bytes-vs-state decider, log-only. If this prints
            // `match=1` the archive region we serve IS the container the guest
            // already holds, so the produced=0 failure cannot be a content
            // problem; if it prints a small `firstdiff`, the package offset in
            // the path table is wrong and that is the whole bug.
            MclaUiXsfCompareGuestCopy(n, baseOff, walkPos, tmp.data(),
                                      static_cast<uint32_t>(got));
            const uint32_t pkgSz = sPkg ? MclaUiXsfWalkCeil(baseOff)
                                        : PackageSizeAt(baseOff);
            // w18: first window of a package MUST be RSC5/XC. Continuation
            // windows are raw XCompress payload — allow them while walk is
            // still inside the package size (do not walk past into junk).
            if (!isPkgHead && walkPos == 0) {
              MCLA_LOG_WARN("INFLATE-HOSTSERVE-PEND-STOP #{} off={:08X} "
                            "headBE={:08X} outPtr={:08X} (pkg head not RSC5/XC)",
                            n, readOff, be, outPtr);
              return;
            }
            if (walkPos + 0x8000 > pkgSz + 0x8000u) {
              MCLA_LOG_WARN("INFLATE-HOSTSERVE-PEND-CAP #{} off={:08X} "
                            "walk={:08X} pkgSz={:08X} outPtr={:08X}",
                            n, readOff, walkPos, pkgSz, outPtr);
              return;
            }
            static std::mutex s_contMtx;
            static std::unordered_map<uint32_t, uint32_t> s_contPerDest;
            uint32_t serves = 0;
            {
              std::lock_guard<std::mutex> clk(s_contMtx);
              serves = s_contPerDest[outPtr];
              const uint32_t contCap =
                  (pkgSz + 0x7FFFu) / 0x8000u; // windows in this package
              if (walkPos > 0 && serves >= contCap) {
                MCLA_LOG_WARN("INFLATE-HOSTSERVE-PEND-DONE #{} outPtr="
                              "{:08X} (served {} windows, pkgCap={})",
                              n, outPtr, serves, contCap);
                return;
              }
              s_contPerDest[outPtr] = serves + 1;
            }
            MCLA_LOG_WARN("INFLATE-HOSTSERVE-PEND #{} off={:08X} got={} "
                          "headBE={:08X} buf={:08X} outPtr={:08X} outLeft={} "
                          "(pkg={:08X} walk={:08X} pkgSz={:08X} serve={} "
                          "frame={} whole={})",
                          n, readOff, got, be, hsBuf, outPtr, outLeft,
                          baseOff, walkPos, pkgSz, serves + 1,
                          frLen != 0u ? 1 : 0, wholeWin ? 1 : 0);
            (void)mem.WriteBytes(hsBuf, tmp.data(),
                                 static_cast<uint32_t>(got));
            (void)mem.WriteU32BE(st + 0, static_cast<uint32_t>(got));
            (void)mem.WriteU32BE(st + 4, hsBuf);
            // F-347: the preamble check only runs when this record reports a
            // fresh stream. `st` is the shared stack record 0x6D8F20, so it
            // arrives here carrying the PREVIOUS container's `consumed`
            // (w334: `consumed=32748` straight into the garage's first window),
            // which makes the guest treat the head as mid-stream payload.
            if (headServe)
              (void)mem.WriteU32BE(st + 8, 0u);
            if (kUiXsfSetExpected && sPkg != 0u) {
              // F-329: publish the block's declared total into the field the
              // guest clamps against, so a stale value inherited on the shared
              // stack state cannot truncate the stream at 196,553 bytes.
              const uint32_t unc = MclaUiXsfUnc(sPkg);
              if (unc)
                (void)mem.WriteU32BE(st + 12, unc);
            }
            if (kUiXsfClearResume && sPkg != 0u && frLen != 0u) {
              // F-333: this window starts exactly on a frame header, so "resume
              // byte N of the previous frame" is now WRONG information, and
              // while that field is non-zero the frame driver ignores this src
              // entirely and walks from its saved cursor — which belongs to
              // whichever stream last used the shared ctx (see the flag's
              // comment for the branch and the w306 signature). Clear it on the
              // ctx the guest is about to use, and only if the word really is a
              // codec ctx (its +4 must read 1, the same value the guest's own
              // gate at sub_8244FF20 tests).
              uint32_t xctx = s_xmemCtx.load();
              if (xctx == 0u) {
                const uint32_t inf = s_guestInflaterR3.load();
                if (inf != 0u)
                  (void)mem.ReadU32BE(inf, &xctx);
              }
              uint32_t codec = 0;
              const bool sane =
                  xctx != 0u && mem.ReadU32BE(xctx + 4u, &codec) && codec == 1u;
              static std::atomic<uint32_t> s_resumeClears{0};
              static std::atomic<uint32_t> s_resumeSkips{0};
              if (sane) {
                (void)mem.WriteU32BE(xctx + 20u + 12280u, 0);
                (void)mem.WriteU32BE(xctx + 20u + 12276u, 0);
                const uint32_t c = s_resumeClears.fetch_add(1) + 1;
                if (c <= 4u || (c % 200u) == 0u)
                  MCLA_LOG_WARN("UIXSF-RESUME-CLEAR #{} ctx={:08X} pkg={:08X} "
                                "frameoff={:08X} frlen={}",
                                c, xctx, baseOff, walkPos, frLen);
              } else if (s_resumeSkips.fetch_add(1) < 2u) {
                MCLA_LOG_WARN("UIXSF-RESUME-CLEAR-SKIP xctx={:08X} codec={:08X} "
                              "s_xmemCtx={:08X} — latch left set",
                              xctx, codec, s_xmemCtx.load());
              }
            }
            if (!isPkgHead) {
              uint32_t consumedNow = 0;
              (void)mem.ReadU32BE(st + 8, &consumedNow);
              if (consumedNow == 0)
                (void)mem.WriteU32BE(st + 8, 1);
            }
            {
              std::lock_guard<std::mutex> wl(g_destPkgMtx);
              // Exact advance for a UI .xsf stream; the legacy fixed-window
              // advance is left byte-for-byte alone for every other dest, so
              // this change cannot perturb the shared job2 walk.
              g_destPkgWalk[outPtr] =
                  sPkg ? (readOff - baseOff + got) : (walkPos + 0x8000);
            }
            if (sPkg != 0) {
              std::lock_guard<std::mutex> lk(g_uiXsfStreamMtx);
              const uint32_t nw = readOff - baseOff + got;
              if (nw > g_uiXsfStreamWalk[st])
                g_uiXsfStreamWalk[st] = nw;
            }
            if (frLen != 0u) {
              // F-327: the frame cursor advances by the WHOLE frame just
              // served, so the next refill lands on the next frame header.
              std::lock_guard<std::mutex> lk(g_uiXsfStreamMtx);
              g_uiXsfStreamFrame[st] = readOff - baseOff + frLen;
            }
            retries = 0;
            return;
          }
          MCLA_LOG_WARN("INFLATE-HOSTSERVE-PEND-FAIL #{} ok={} got={}", n,
                        ok, got);
        }
      }
      if (retries == 1) {
        uint32_t credits = 0;
        (void)mem.ReadU32BE(0x827D74E0u, &credits);
        // Session 75s: capture the HOST callstack to name the caller that
        // drives these calls with a garbage context (lr=1, r1=code).
        static std::atomic<uint32_t> s_btCount{0};
        if (s_btCount.fetch_add(1) < 2) {
          SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
          static std::once_flag symOnce;
          std::call_once(symOnce, []() {
            SymInitialize(GetCurrentProcess(), nullptr, TRUE);
          });
          void *frames[14] = {};
          const USHORT nCap = CaptureStackBackTrace(0, 14, frames, nullptr);
          for (USHORT fi2 = 0; fi2 < nCap; ++fi2) {
            alignas(8) char scratch[sizeof(SYMBOL_INFO) + 128];
            SYMBOL_INFO *si = (SYMBOL_INFO *)scratch;
            si->SizeOfStruct = sizeof(SYMBOL_INFO);
            si->MaxNameLen = 127;
            DWORD64 disp = 0;
            char nameBuf[160];
            const char *name = "???";
            if (SymFromAddr(GetCurrentProcess(), (DWORD64)frames[fi2], &disp,
                            si)) {
              snprintf(nameBuf, sizeof(nameBuf), "%s+0x%llx", si->Name,
                       (unsigned long long)disp);
              name = nameBuf;
            }
            MCLA_LOG_WARN("BT[{}] frame {:02d} {} {}", n, fi2,
                          (void *)frames[fi2], name);
          }
        }
        // lr=1 is bogus â€” walk the stack instead (recompiler frames:
        // [sp]=back, [back-8]=saved lr).
        uint32_t inPtr = 0;
        mem.ReadU32BE(st + 4, &inPtr);
        char chain[120] = {0};
        size_t off = 0;
        uint32_t sp = ctx.r1.u32;
        for (int f = 0; f < 4 && sp != 0 && off + 12 < sizeof(chain); ++f) {
          uint32_t back = 0, lr2 = 0;
          if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
          mem.ReadU32BE(back - 8, &lr2);
          off += static_cast<size_t>(snprintf(chain + off, sizeof(chain) - off,
                                              " f%d=%08X", f, lr2));
          sp = back;
        }
        MCLA_LOG_WARN(
            "INFLATE-PENDING #{} | st={:08X} inPtr={:08X} produced={} "
            "outPtr={:08X} outLeft={} credits={:08X} | lr={:08X} r1={:08X} "
            "hostTid={:08X} | chain='{}'",
            n, st, inPtr, produced, outPtr, outLeft, credits,
            static_cast<uint32_t>(ctx.lr), ctx.r1.u32, GetCurrentThreadId(),
            chain);
        // Session 75v: dump the inner stream's 3 page-cache slots
        // (inner+296/336/356) â€” the fill reads land in page buffers but the
        // buffered reader never matches, so watch the slot state.
        {
          uint32_t inner = 0;
          // 75v fix: the inner object lives at wrapper+32; the wrapper is
          // join_entry+8 (A007D810 in every soak). Do not deref the object
          // to get its vtable â€” we want the OBJECT itself.
          uint32_t wrapper = 0;
          mem.ReadU32BE(0xA0121560u + 8, &wrapper);
          if (wrapper != 0 && wrapper != 0xCDCDCDCDu)
            mem.ReadU32BE(wrapper + 32, &inner);
          if (inner == 0) inner = 0xA0083660u;
          if (inner >= 0xA0000000u && inner != 0xCDCDCDCDu) {
            for (int slot = 0; slot < 3; ++slot) {
              uint32_t sBase = inner + 296u + slot * 40u;
              uint32_t w[9] = {0};
              for (int wi = 0; wi < 9; ++wi)
                mem.ReadU32BE(sBase + wi * 4u, &w[wi]);
              MCLA_LOG_WARN("PAGESLOT[{}] @ {:08X} = [{:08X} {:08X} {:08X} "
                            "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                            slot, sBase, w[0], w[1], w[2], w[3], w[4], w[5],
                            w[6], w[7], w[8]);
            }
            uint32_t i48 = 0, i296 = 0;
            mem.ReadU32BE(inner + 48, &i48);
            mem.ReadU32BE(inner + 296, &i296);
            MCLA_LOG_WARN("INNER {:08X}: [48]={:08X} [296]={:08X}", inner,
                          i48, i296);
          }
        }
        // Session 75q: dump the join table â€” entry+8 = the source stream
        // object whose vtable+28 read returns 0 for this batch.
        uint32_t jcount = 0, jentries = 0;
        mem.ReadU32BE(0x8283D1A8u, &jcount);
        mem.ReadU32BE(0x8283D1C4u, &jentries);
        if (jentries != 0 && jcount != 0) {
          for (uint32_t ji = 0; ji < 8 && ji < jcount; ++ji) {
            uint32_t eBase = jentries + ji * 28u;
            uint32_t key = 0, obj = 0, busy = 0, vt = 0, rd = 0;
            mem.ReadU32BE(eBase + 0, &key);
            mem.ReadU32BE(eBase + 8, &obj);
            mem.ReadU32BE(eBase + 12, &busy);
            if (obj != 0 && obj != 0xCDCDCDCDu) {
              mem.ReadU32BE(obj, &vt);
              if (vt != 0) mem.ReadU32BE(vt + 28, &rd);
              // 75r: wrapper fields +0..+44 (incl. +36 lookup base) and the
              // join entry's own +16/+20/+24 (the request params).
              uint32_t f[12] = {0}, jf[3] = {0};
              for (int fi = 0; fi < 12; ++fi)
                mem.ReadU32BE(obj + 4u * fi, &f[fi]);
              mem.ReadU32BE(eBase + 16, &jf[0]);
              mem.ReadU32BE(eBase + 20, &jf[1]);
              mem.ReadU32BE(eBase + 24, &jf[2]);
              MCLA_LOG_WARN("JOIN[{}] key={:08X} obj={:08X} vt={:08X} "
                            "rd={:08X} objf=[{:08X} {:08X} {:08X} {:08X} "
                            "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                            "{:08X} {:08X}] joinf=[{:08X} {:08X} {:08X}]",
                            ji, key, obj, vt, rd, f[0], f[1], f[2], f[3],
                            f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11],
                            jf[0], jf[1], jf[2]);
              continue;
            }
            MCLA_LOG_WARN("JOIN[{}] @ {:08X} key={:08X} obj={:08X} "
                          "busy={:08X} vt={:08X} readFn={:08X}",
                          ji, eBase, key, obj, busy, vt, rd);
          }
        }
      }
      return;
    }
    retries = 0;
    // w10: need-data dests that still have outLeft>0 must NOT be marked
    // stream-complete — zeroing outLeft is the caller-loop exit key and
    // permanently abandons the dest (RSC-PLACE-SKIP residual). Keep the
    // stream alive so the next empty-retry can host-serve more payload.
    // Hard-capped so a truly undecodable dest cannot spin the boot forever.
    {
      uint32_t outPtrChk = 0, h0 = 0;
      (void)mem.ReadU32BE(st + 20, &outPtrChk);
      if (outPtrChk)
        (void)mem.ReadU32BE(outPtrChk, &h0);
      const bool needAlive =
          (outPtrChk == 0xB7B61000u || outPtrChk == 0xB7B71000u ||
           outPtrChk == 0xB79B1000u) &&
          outLeft != 0 && h0 == 0xCDCDCDCDu;
      if (needAlive) {
        static std::mutex s_kaMtx;
        static std::unordered_map<uint32_t, uint32_t> s_keepAlive;
        uint32_t &ka = [&]() -> uint32_t & {
          std::lock_guard<std::mutex> lk(s_kaMtx);
          return s_keepAlive[outPtrChk];
        }();
        ka++;
        if (ka <= 80) {
          MCLA_LOG_WARN("INFLATE-EMPTY-KEEP #{} st={:08X} outPtr={:08X} "
                        "outLeft={} produced={} head={:08X} (need-data dest "
                        "still poison — not marking stream complete)",
                        ka, st, outPtrChk, outLeft, produced, h0);
          return;
        }
        MCLA_LOG_WARN("INFLATE-EMPTY-KEEP-GIVEUP #{} outPtr={:08X} "
                      "(hard cap — falling through to bail)",
                      ka, outPtrChk);
      }
    }
    const uint32_t e = s_h5E10empty.fetch_add(1) + 1;
    if (e <= 16) {
      uint32_t outPtr2 = 0, produced2 = 0, h0 = 0, h1 = 0, h2 = 0, h3 = 0;
      (void)mem.ReadU32BE(st + 20, &outPtr2);
      (void)mem.ReadU32BE(st + 24, &produced2);
      if (outPtr2 != 0) {
        (void)mem.ReadU32BE(outPtr2 + 0, &h0);
        (void)mem.ReadU32BE(outPtr2 + 4, &h1);
        (void)mem.ReadU32BE(outPtr2 + 8, &h2);
        (void)mem.ReadU32BE(outPtr2 + 12, &h3);
      }
      MCLA_LOG_WARN("INFLATE-EMPTY #{} st={:08X} consumed={} produced={} "
                    "outPtr={:08X} head=[{:08X} {:08X} {:08X} {:08X}] "
                    "(bail, clear outLeft â€” caller loop key)",
                    e, st, consumed, produced2, outPtr2, h0, h1, h2, h3);
    } else if ((e % 1000) == 0) {
      MCLA_LOG_WARN("INFLATE-EMPTY #{} st={:08X} consumed={} (bail)", e, st,
                    consumed);
    }
    // Normalize state: no input left, consumed covers all, expected=0,
    // outLeft=0 (caller loop exit key).
    (void)mem.WriteU32BE(st + 0, 0);
    (void)mem.WriteU32BE(st + 8, 0);
    (void)mem.WriteU32BE(st + 12, 0);
    (void)mem.WriteU32BE(st + 16, 0);
    return;
  }

  if (n <= 16 || (n % 200) == 0) {
    // Session 75n: guest stack walk. Recompiler frame convention:
    // mflr r12; stw r12,-8(r1); stwu r1,-X(r1)  â‡’  saved LR of the function
    // owning this frame sits at [back_chain - 8]. Walk back chains upward.
    char chain[160] = {0};
    size_t off = 0;
    uint32_t sp = ctx.r1.u32;
    for (int f = 0; f < 6 && sp != 0 && off + 12 < sizeof(chain); ++f) {
      uint32_t back = 0, lr = 0;
      if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
      if (!mem.ReadU32BE(back - 8, &lr)) break;
      off += static_cast<size_t>(
          snprintf(chain + off, sizeof(chain) - off, " f%d=%08X", f, lr));
      sp = back;
    }
    MCLA_LOG_INFO("INFLATE #{} st={:08X} in={} out={} consumed={} magic={:08X} "
                  "lr={:08X} r1={:08X} tid={:08X} chain[{}]",
                  n, st, inLeft, outLeft, consumed, magic,
                  static_cast<uint32_t>(ctx.lr), ctx.r1.u32,
                  GetCurrentThreadId(), chain);
  }
  // Track the largest inflate-output capacity we have seen for this process.
  // PRELOAD-CTX inflSize is a 12-byte sentinel; the real package size is the
  // out buffer size from the stream (up to 512 KiB in boot soaks).
  if (outLeft > 16 && outLeft < (1u << 20)) {
    uint32_t prev = s_maxInflateOut.load();
    while (outLeft > prev && !s_maxInflateOut.compare_exchange_weak(prev, outLeft))
      {}
  }

  // p2q (IDA): 821D5E10 = zlibInflater::InflateBegin ("not in XCompress
  // format"). Job #2 enters with inLeft=0xFFFFFFD4 (-44) and inPtr on the
  // guest stack — the pgStreamer Read never filled the buffer. Unsigned
  // `inLeft >= 4` then treats stack residue (e.g. 525DE064) as a magic.
  //
  // p2t fix: do NOT complete the stream empty. The caller loop only refills
  // when inLeft==0; a completed-empty stream starves the whole preload.
  // Zero inLeft and leave outLeft intact so the next iteration takes the
  // refill path (same shape as the inLeft==0 pending branch above).
  if (inLeft >= 0x10000000u) {
    static std::atomic<uint32_t> s_inCorrupt{0};
    static uint32_t s_hostInBuf = 0;
    static std::mutex s_hostInMtx;
    const uint32_t cn = s_inCorrupt.fetch_add(1) + 1;
    if (cn <= 32 || (cn % 200) == 0)
      MCLA_LOG_WARN("INFLATE-CORRUPT #{} in={:#x} (signed {}) inPtr={:08X} "
                    "out={} outPtr={:08X} consumed={} lr={:08X}",
                    cn, inLeft, static_cast<int32_t>(inLeft), inPtr, outLeft,
                    outPtr, consumed,
                    static_cast<uint32_t>(ctx.lr));

    // w18: per-dest package cursor (shared with the EMPTY/PEND path).
    // STRENT +24 carries flag bits (0x40060000 = package @0x60000) — mask
    // before using as a file offset. Prefer the RSC5 table assigner so each
    // inflate dest gets a real package head instead of a shared walk.
    std::lock_guard<std::mutex> lk(s_hostInMtx);
    if (s_hostInBuf == 0)
      s_hostInBuf = mem.Alloc(0x8000, 16);
    uint32_t fileOff = AssignPackageForDest(outPtr);
    uint32_t walkPos = 0;
    {
      std::lock_guard<std::mutex> wl(g_destPkgMtx);
      walkPos = g_destPkgWalk[outPtr];
    }
    const uint32_t readOff = fileOff + walkPos;

    if (s_hostInBuf != 0 && outPtr != 0 && outLeft != 0) {
      // F-258 (gated to the 4 Path-B UI container pkgs): a Rage .xsf is ONE
      // whole-buffer XMemDecompress stream; the 0x8000-window corrupt-serve fed
      // only ~64 KB of raceeditor's 143 KB and the executor never re-entered, so
      // each UI .xsf decompressed PARTIALLY (F-257). Serve the ENTIRE compressed
      // package (PackageSizeAt) into a 2 MB bounce so the guest's single
      // decompress yields the full container. These 4 offsets only ever appear as
      // dest mappings under Path B (s_pendingUiPkg/PATHB-PKGFIX), so baseline is
      // untouched; flag-OFF never routes here anyway.
      if (IsUiXsfPkg(fileOff)) {
        static uint32_t s_uiBig = 0;
        if (s_uiBig == 0)
          s_uiBig = mem.Alloc(0x200000, 16);
        const uint32_t cpsz = PackageSizeAt(fileOff);
        uint32_t want = cpsz ? cpsz : 0x8000u;
        if (want > 0x1FF000u)
          want = 0x1FF000u;
        auto &vfsu = mcla::vfs::RpfVirtualFileSystem::Instance();
        mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fhu;
        const bool uOpen = vfsu.OpenFile("xarchive_cache.rpf", fhu);
        uint64_t gotu = 0;
        std::vector<uint8_t> big(want);
        bool uServed = false;
        if (uOpen && s_uiBig)
          uServed = vfsu.ReadFileAt(fhu, fileOff, big.data(), want, gotu) &&
                    gotu >= 16 &&
                    mem.WriteBytes(s_uiBig, big.data(),
                                   static_cast<uint32_t>(gotu));
        if (uOpen)
          vfsu.CloseFile(fhu);
        if (uServed) {
          // F-295: Path A host decode. big.data()[0..gotu) is the compressed
          // RSC5 container. xmem_lzx decodes it byte-exact offline (all 4 UI
          // .xsf) WITHOUT re-entering the guest VM — so it dodges the F-288
          // corrupt-serve context coupling that killed the guest-decoder path.
          // On success write the FULL container into the dest and drain outLeft
          // (caller-loop complete key) so the guest's partial inflate is
          // bypassed. F-297: keyed off the dynamically resolved fileOff (never a
          // literal dest), shares the top-of-handler bookkeeping, and refuses to
          // complete a container that does not FIT the dest room — a truncated
          // prefix marked complete is worse than leaving it to the guest.
          if (kPathBHostFullDecode && outPtr != 0 &&
              UiDecClassify(outPtr, fileOff) == kUiDecTry) {
            std::vector<uint8_t> dec;
            const int hpath = mcla_lzx::host_decode_ui_xsf(
                big.data(), static_cast<size_t>(gotu), dec, kXcWindowBits);
            const bool fits = hpath && !dec.empty() && dec.size() <= outLeft;
            if (fits) {
              const uint32_t wr = static_cast<uint32_t>(dec.size());
              const bool wrote = mem.WriteBytes(outPtr, dec.data(), wr);
              MCLA_LOG_WARN(
                  "PATHB-HOSTDECODE #{} off={:08X} path={} decoded={} "
                  "wrote={} dest={:08X} outLeft={} ok={}",
                  cn, fileOff, hpath, wr, wr, outPtr, outLeft, wrote);
              if (wrote) {
                {
                  std::lock_guard<std::mutex> lk(g_uiDecMtx);
                  g_uiDecDone[outPtr] = fileOff;
                }
                UiDecRecordExpect(outPtr, fileOff, dec.data(), dec.size());
                (void)mem.WriteU32BE(st + 0, 0);       // inLeft
                (void)mem.WriteU32BE(st + 8, static_cast<uint32_t>(gotu));
                (void)mem.WriteU32BE(st + 16, 0);      // outLeft -> complete
                {
                  std::lock_guard<std::mutex> wl(g_destPkgMtx);
                  g_destPkgWalk[outPtr] = static_cast<uint32_t>(gotu);
                }
                return;
              }
            } else {
              MCLA_LOG_WARN("PATHB-HOSTDECODE-FAIL #{} off={:08X} path={} "
                            "gotu={} decoded={} dest={:08X} room={} → guest",
                            cn, fileOff, hpath, static_cast<uint32_t>(gotu),
                            dec.empty() ? 0u : static_cast<uint32_t>(dec.size()),
                            outPtr, outLeft);
              std::lock_guard<std::mutex> lk(g_uiDecMtx);
              g_uiDecSkip.insert(UiDecKey(outPtr, fileOff));
            }
            // fall through to the guest whole-package serve on any failure
          }
          // F-288 REVERT. Tested the isolated-stack hypothesis (F-287 said the
          // synchronous decode destabilizes boot). w264 ran MclaXcDecodeFullStream
          // on a DEDICATED stack (stk=CA128980, not the guest r1) yet STILL
          // regressed policecam/credits to 0 and boot depth to 24,429 lines (vs
          // w257 88,884), exactly like the guest-stack w262 and the scratch-only
          // w258. => The regression is NOT stack corruption; it is RE-ENTERING
          // the guest VM (<=64 sub_8244FF20 calls) from inside the corrupt-serve
          // handler coupling the shared VM/thread state. Infeasible to apply the
          // full-decompress from this hook regardless of stack/ctx isolation.
          // Engine still proven offline (produced=143069). Raw serve restored.
          (void)mem.WriteU32BE(st + 0, static_cast<uint32_t>(gotu)); // inLeft
          (void)mem.WriteU32BE(st + 4, s_uiBig);                      // inPtr
          (void)mem.WriteU32BE(st + 8, 0);                            // consumed
          {
            std::lock_guard<std::mutex> wl(g_destPkgMtx);
            g_destPkgWalk[outPtr] = static_cast<uint32_t>(gotu);
          }
          MCLA_LOG_WARN("PATHB-UIFULL #{} off={:08X} pkgSz={:08X} served={} "
                        "dest={:08X} outLeft={}",
                        cn, fileOff, cpsz, static_cast<uint32_t>(gotu), outPtr,
                        outLeft);
          return;
        }
        // fall through to the windowed path if the full load failed
      }
      auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
      mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fh;
      bool ok = vfs.OpenFile("xarchive_cache.rpf", fh);
      uint64_t got = 0;
      std::vector<uint8_t> tmp(0x8000);
      if (ok) {
        ok = vfs.ReadFileAt(fh, readOff, tmp.data(), 0x8000, got);
        vfs.CloseFile(fh);
      }
      if (ok && got >= 16) {
        const uint32_t be = (uint32_t(tmp[0]) << 24) | (uint32_t(tmp[1]) << 16) |
                            (uint32_t(tmp[2]) << 8) | uint32_t(tmp[3]);
        constexpr uint32_t kRsc5Head = 0x05435352u;
        constexpr uint32_t kXcHead = 0x0FF512EFu;
        const bool isPkgHead = (be == kRsc5Head || be == kXcHead);
        const uint32_t pkgSz = PackageSizeAt(fileOff);
        if (!isPkgHead && walkPos == 0) {
          if (cn <= 16 || (cn % 50) == 0)
            MCLA_LOG_WARN("INFLATE-HOSTSERVE-STOP #{} off={:08X} "
                          "headBE={:08X} outPtr={:08X} (pkg head not RSC5/XC)",
                          cn, readOff, be, outPtr);
          (void)mem.WriteU32BE(st + 0, 0);
          return;
        }
        if (walkPos + 0x8000 > pkgSz + 0x8000u) {
          if (cn <= 16 || (cn % 50) == 0)
            MCLA_LOG_WARN("INFLATE-HOSTSERVE-CAP #{} off={:08X} "
                          "walk={:08X} pkgSz={:08X} outPtr={:08X}",
                          cn, readOff, walkPos, pkgSz, outPtr);
          (void)mem.WriteU32BE(st + 0, 0);
          return;
        }
        if (cn <= 8 || (cn % 50) == 0)
          MCLA_LOG_WARN("INFLATE-HOSTSERVE #{} off={:08X} got={} "
                        "headBE={:08X} buf={:08X} outPtr={:08X} outLeft={} "
                        "pkg={:08X} walk={:08X}",
                        cn, readOff, got, be, s_hostInBuf, outPtr, outLeft,
                        fileOff, walkPos);
        (void)mem.WriteBytes(s_hostInBuf, tmp.data(),
                             static_cast<uint32_t>(got));
        (void)mem.WriteU32BE(st + 0, static_cast<uint32_t>(got)); // inLeft
        (void)mem.WriteU32BE(st + 4, s_hostInBuf);                // inPtr
        if (!isPkgHead) {
          uint32_t consumedNow = 0;
          (void)mem.ReadU32BE(st + 8, &consumedNow);
          if (consumedNow == 0)
            (void)mem.WriteU32BE(st + 8, 1);
        }
        {
          std::lock_guard<std::mutex> wl3(g_destPkgMtx);
          g_destPkgWalk[outPtr] = walkPos + 0x8000;
        }
        return;
      }
      if (cn <= 8)
        MCLA_LOG_WARN("INFLATE-HOSTSERVE-FAIL #{} ok={} got={} off={:08X}",
                      cn, ok, got, readOff);
    }
    (void)mem.WriteU32BE(st + 0, 0); // inLeft = 0 → caller refills
    return;
  }

  // RSC5 resource header: magic 05 'CSR' at +0, XCompress payload at +0xC.
  // The inflate caller is supposed to do inLeft = bytesRead - 12. Our
  // host-serve feeds the raw file, so strip the header here and fall
  // through to XCompress with the payload.
  constexpr uint32_t kRsc5Magic = 0x05435352u; // 05 'C' 'S' 'R'
  if (consumed == 0 && magic == kRsc5Magic && inLeft > 12 && inPtr != 0) {
    uint32_t xc = 0;
    (void)mem.ReadU32BE(inPtr + 12, &xc);
    // w29: cap job2 / B7001000 RSC5 spin. Same dest+inPtr re-fed without
    // produced progress → drain outLeft (caller-loop complete key) after
    // 6 hits so later streams advance. Never plant entropy; never r3=0.
    if (IsJob2UiDest(outPtr) || outPtr == 0xB7001000u) {
      static std::mutex s_rsc5SpinMtx;
      static std::unordered_map<uint32_t, std::pair<uint32_t, uint32_t>>
          s_rsc5Spin; // dest -> {count, inPtr}
      static std::unordered_map<uint32_t, uint32_t> s_rsc5Prod;
      uint32_t cnt = 0;
      {
        std::lock_guard<std::mutex> lk(s_rsc5SpinMtx);
        auto &slot = s_rsc5Spin[outPtr];
        if (slot.second == inPtr)
          slot.first++;
        else {
          slot.first = 1;
          slot.second = inPtr;
        }
        cnt = slot.first;
        uint32_t &lastProd = s_rsc5Prod[outPtr];
        const bool prog = produced > lastProd && lastProd != 0;
        if (prog)
          slot.first = 1;
        lastProd = produced;
      }
      if (cnt >= 6) {
        MCLA_LOG_WARN("W29-SPIN-CAP #{} dest={:08X} inPtr={:08X} "
                      "produced={} outLeft={} inLeft={} — drain "
                      "(never re-plant RSC5 on same window)",
                      cnt, outPtr, inPtr, produced, outLeft, inLeft);
        (void)mem.WriteU32BE(st + 0, 0);  // inLeft = 0
        (void)mem.WriteU32BE(st + 16, 0); // outLeft = 0
        {
          std::lock_guard<std::mutex> lk(s_rsc5SpinMtx);
          s_rsc5Spin[outPtr].first = 0;
        }
        return;
      }
      if (cnt <= 3 || (cnt % 3) == 0)
        MCLA_LOG_WARN("W29-RSC5-SPIN dest={:08X} inPtr={:08X} cnt={} "
                      "produced={} outLeft={}",
                      outPtr, inPtr, cnt, produced, outLeft);
    }
    MCLA_LOG_WARN("INFLATE-RSC5 #{} in={} xc@+12={:08X} inPtr={:08X} "
                  "out={} outPtr={:08X} — skip 12B header",
                  n, inLeft, xc, inPtr, outLeft, outPtr);
    (void)mem.WriteU32BE(st + 0, inLeft - 12); // inLeft
    (void)mem.WriteU32BE(st + 4, inPtr + 12);  // inPtr
    magic = xc;
    inLeft = inLeft - 12;
    inPtr = inPtr + 12;
  }

  if (consumed == 0 && inLeft >= 4 && magic != kXCompressMagic &&
      inPtr != 0 && outPtr != 0) {
    // Session 72: do NOT copy unknown-magic bytes into the output. A
    // 525DE064 stream was pass-through'd raw and the guest parser produced
    // wild pointer 0x7E780000 â†’ AV in sub_821DEE40. Skip the XCompress
    // fatal, consume the stream, emit nothing. Guest sees empty output.
    uint32_t b0 = 0, b1 = 0, b2 = 0, b3 = 0;
    (void)mem.ReadU32BE(inPtr + 0, &b0);
    if (inLeft >= 16) {
      (void)mem.ReadU32BE(inPtr + 4, &b1);
      (void)mem.ReadU32BE(inPtr + 8, &b2);
      (void)mem.ReadU32BE(inPtr + 12, &b3);
    }
    (void)mem.WriteU32BE(st + 0, 0);       // inLeft = 0
    (void)mem.WriteU32BE(st + 8, inLeft);  // consumed = all input
    (void)mem.WriteU32BE(st + 12, 0);      // expected = 0
    const uint32_t pt = s_h5E10pt.fetch_add(1) + 1;
    if (pt <= 16 || (pt % 50) == 0)
      MCLA_LOG_WARN("INFLATE-SKIP #{} magic={:08X} in={} out={} inPtr={:08X} "
                    "head=[{:08X} {:08X} {:08X} {:08X}] (no XCompress "
                    "header â€” skip fatal, emit 0)",
                    pt, magic, inLeft, outLeft, inPtr, b0, b1, b2, b3);
    return;
  }

  // w22 guard: never hand __imp__ a non-XC stream that has not produced
  // output yet (job #2 fresh dest). w22 soak FATAL-SOFT at 821D5E5C
  // "not in XCompress format" when J2-LAST left magic=RSC5 and local
  // consumed prevented the strip. Mid-stream job1 continuations
  // (produced>0) still pass through — proven path.
  if (magic != kXCompressMagic && produced == 0 && IsJob2UiDest(outPtr)) {
    static std::atomic<uint32_t> s_j2guard{0};
    const uint32_t gn = s_j2guard.fetch_add(1) + 1;
    if (gn <= 16 || (gn % 50) == 0)
      MCLA_LOG_WARN("INFLATE-J2-GUARD #{} dest={:08X} magic={:08X} in={} "
                    "consumed={} inPtr={:08X} (skip __imp__ — no XC yet)",
                    gn, outPtr, magic, inLeft, consumed, inPtr);
    return;
  }
  __imp__sub_821D5E10(ctx, base);
}

// POST-INFLATE CACHE FLUSH census: sub_821D5510 (dcbf/dcbst loop).
// Called after each inflate step completes. Logs r3 (base addr), r4 (size),
// r5 (flags), lr.
PPC_FUNC_IMPL(__imp__sub_821D5510);
static std::atomic<uint32_t> s_h5510{0};
PPC_FUNC(sub_821D5510) {
  const uint32_t n = s_h5510.fetch_add(1) + 1;
  // F-321: the golden-byte verify runs on EVERY flush, not just the printed ones —
  // a dest that retires late would otherwise never get a verdict. It is a map
  // lookup plus a one-shot-per-dest guard for non-UI dests, so the cost off the
  // print path is bounded. SlotCov stays INSIDE the cap: 1,024 guest reads per
  // call is far too much to add to a hot hook.
  MclaUiXsfVerifySlot(ctx.r3.u32, ctx.r4.u32);
  if (n <= 64 || (n % 200) == 0) {
    // slotcov is the coverage of a UI .xsf dest at its NATURAL retirement (the
    // guest flushes after the inflate step completes) — 1024 = the whole first
    // 4 KiB is real data, 0xFFFFFFFF = not a UI .xsf dest. XMEM-UIHEAD dumps on
    // the FIRST call and so cannot answer "how full did it get".
    MCLA_LOG_INFO("FLUSH sub_821D5510 #{} r3={:08X} r4={:08X} r5={:08X} "
                  "slotcov={} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  MclaUiXsfSlotCov(ctx.r3.u32),
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821D5510(ctx, base);
}

// POST-INFLATE CLEANUP census: sub_821CE100 (atomic decrement).
// Called twice at loc_821BC4CC for cleanup. Logs r3 (object), lr.
PPC_FUNC_IMPL(__imp__sub_821CE100);
static std::atomic<uint32_t> s_hCE100{0};
PPC_FUNC(sub_821CE100) {
  const uint32_t n = s_hCE100.fetch_add(1) + 1;
  if (n <= 64 || (n % 200) == 0) {
    MCLA_LOG_INFO("CLEANUP sub_821CE100 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821CE100(ctx, base);
}

// CALLBACK SETUP census: sub_8268B960 (find-or-create by name).
// Returns the callback pointer stored at [ctx+1548] and the archive device
// stored at [ctx+1552]. Logs which string lookup produced which function.
PPC_FUNC_IMPL(__imp__sub_8268B960);
static std::atomic<uint32_t> s_h68B960{0};
PPC_FUNC(sub_8268B960) {
  const uint32_t n = s_h68B960.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    char name[68] = {0};
    mem.ReadBytes(ctx.r5.u32, name, 64);
    MclaSanitizePath(name, sizeof(name));
    uint32_t ret = 0;
    __imp__sub_8268B960(ctx, base);
    ret = ctx.r3.u32;
    MCLA_LOG_WARN("CBSETUP sub_8268B960 #{} pool={:08X} idx={:08X} name='{}' "
                  "flags={:08X} -> ret={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, name, ctx.r6.u32, ret,
                  static_cast<uint32_t>(ctx.lr));
  } else {
    __imp__sub_8268B960(ctx, base);
  }
}

// TASK-COMPLETE census: sub_8244EE00 runs after every pool-worker task
// execution (TU16:15473, sysTaskExecutor pool proc 821C4528). If tasks ever
// execute, this fires - and its release chain should wake the parked fence.
PPC_FUNC_IMPL(__imp__sub_8244EE00);
static std::atomic<uint32_t> s_h4EE00{0};
PPC_FUNC(sub_8244EE00) {
  const uint32_t n = s_h4EE00.fetch_add(1) + 1;
  if (n <= 24 || (n % 2000) == 0)
    MCLA_LOG_INFO("TASK-DONE sub_8244EE00 #{} arg={:08X}", n, ctx.r3.u32);
  __imp__sub_8244EE00(ctx, base);
}

// ENQUEUE-CHOOSER census: Function_821BCB10 decides inline-execute vs
// ring-A vs ring-B push vs reject (Ghidra: [obj+4]!=0 -> inline ret -1;
// ring full -> ret 0 = silent dead-end; else slot id). MINIMAL form:
// registers only - a prior version that read guest memory here crashed the
// first invocation (fault sub_821BCB10+0x7B, the vtable-dispatch region).
PPC_FUNC_IMPL(__imp__sub_821BCB10);
static std::atomic<uint32_t> s_hBCB10{0};
PPC_FUNC(sub_821BCB10) {
  const uint32_t n = s_hBCB10.fetch_add(1) + 1;
  const uint32_t a0 = ctx.r3.u32;
  const uint32_t a6 = ctx.r7.u32;
  __imp__sub_821BCB10(ctx, base);
  if (n <= 16 || (n % 500) == 0)
    MCLA_LOG_INFO("ENQ sub_821BCB10 #{} a0={:08X} cb={:08X} -> r3={:08X}", n,
                  a0, a6, ctx.r3.u32);
}

// F-173/F-174: sub_821867A0 builds 28-byte streamer request records - but into
// the array its CALLER hands it (`sub_82187150+0x1A8` passes r1+224 + idx*28,
// and every store base inside is r22 = r3 or idx*28 + r22), NOT into the pool
// sub_821BC140 reads (`r28 = [0x8283D190+52] + [task+0]*28`). F-174 withdrew
// the earlier claim that this is the writer of the slot whose [+4] the inflate
// loop takes as its length; read this census as a bound on a request BUILDER.
// What it does establish: 2 firings per boot, returns ids 3 and 4, exactly one
// caller, and its only non-pointer argument is 0 both times.
// MINIMAL FORM - REGISTERS ONLY, no guest reads: an adjacent census in this
// subsystem crashed its consumer by reading memory (the ENQ note at
// sub_821BCB10), and the F-125/F-133 footprint rule applies anyway.
PPC_FUNC_IMPL(__imp__sub_821867A0);
static std::atomic<uint32_t> s_h867A0{0};
PPC_FUNC(sub_821867A0) {
  const uint32_t n = s_h867A0.fetch_add(1) + 1;
  const uint32_t r3 = ctx.r3.u32, r4 = ctx.r4.u32, r5 = ctx.r5.u32;
  const uint32_t r6 = ctx.r6.u32, r7 = ctx.r7.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  __imp__sub_821867A0(ctx, base);
  if (n <= 24 || (n % 2000) == 0)
    MCLA_LOG_INFO("REQFILL sub_821867A0 #{} r3={:08X} r4={:08X} r5={:08X} "
                  "r6={:08X} r7={:08X} -> r3={:08X} lr={:08X}",
                  n, r3, r4, r5, r6, r7, ctx.r3.u32, lr);
}

// F-177: sub_821BCE68 is pgStreamer::Open (its own assert strings are at
// 0x82010FF0 'pgStreamer::Open - out of handles' and 0x82011014 'You forgot to
// call pgStreamer::InitClass.'). F-176's trace of its body found the store that
// sets the field the inflate loop reads as its transfer length:
//
//   lwz  r10,-11824(r11)  -> [0x8283D1F0] a factory fnptr; blr-call it
//   bl 0x821cb488 (r4=1)  -> r31 = the stream object
//   stw  r31,8(r29)       -> record+8 = object
//   lwz  r11,0(r31); lwz r10,84(r11); mtctr r10; bctrl   -> obj->vt[+84]()
//   stw  r3,4(r29)        -> record+4  =  that call's return
//
// so F-172's zero length is vt+84 returning 0 (or Open never running, which is
// what the 'calls' count here settles - the records are 28 bytes and
// sub_821BCB10 only SEARCHES them by record[0]). Registers-only: see the ENQ
// note above for the guest-memory-read AV this subsystem has already produced.
PPC_FUNC_IMPL(__imp__sub_821BCE68);
static std::atomic<uint32_t> s_hBCE68{0};
PPC_FUNC(sub_821BCE68) {
  const uint32_t n = s_hBCE68.fetch_add(1) + 1;
  const uint32_t r3 = ctx.r3.u32, r4 = ctx.r4.u32, r5 = ctx.r5.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  __imp__sub_821BCE68(ctx, base);
  // F-181: which Open leaves its record's byte count at 0 (F-180 measured the
  // legals generation at +4 = 0 with +12 = 4, while meshtextures and trash got
  // their true sizes)? Read the record this return id selects, right here, so
  // "Open never wrote a length" separates from "a later phase zeroed it".
  uint32_t rbase = 0, rlen = 0, rflag = 0, rid = 0, rpkg = 0, rdev = 0, rent = 0;
  (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(0x8283D1C4u,
                                                            &rbase);
  rid = ctx.r3.u32;
  if (rbase != 0 && rbase != 0xCDCDCDCDu && rid != 0xFFFFFFFFu) {
    auto &m = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t rec = rbase + (rid & 0x7FFFu) * 28u;
    (void)m.ReadU32BE(rec + 4u, &rlen);
    (void)m.ReadU32BE(rec + 8u, &rdev);   // F-205: stream/device object (BC140
                                          // derefs record+8 -> vt[124]; if this
                                          // is a semaphore/0 the record cannot
                                          // execute, independent of +4)
    (void)m.ReadU32BE(rec + 12u, &rflag);
    (void)m.ReadU32BE(rec + 16u, &rpkg);
    (void)m.ReadU32BE(rec + 20u, &rent);
  }
  if (n <= 24 || (n % 500) == 0)
    MCLA_LOG_INFO("STREAM-OPEN sub_821BCE68 #{} r3={:08X} r4={:08X} r5={:08X} "
                  "-> r3={:08X} rec[+4]={} [+8dev]={:08X} [+12]={} [+16]={:08X} "
                  "[+20]={:08X} lr={:08X}",
                  n, r3, r4, r5, ctx.r3.u32, rlen, rdev, rflag, rpkg, rent, lr);
}

// INLINE-TASK-EXEC census: 0x821bc140 executes a task descriptor directly
// (the [obj+4]!=0 path). If this fires for op tag=4, the task ran inline and
// its own completion step is what silently failed.
PPC_FUNC_IMPL(__imp__sub_821BC140);
static std::atomic<uint32_t> s_hBC140{0};
// Forward declaration for fiDevice::Mount (sub_821CB9D8) used in post-inflate mount fix.
extern "C" void __imp__sub_821CB9D8(PPCContext &ctx, uint8_t *base);
// Defined at EOF: push {name,buf,size} onto the embedded:/ D22E8 list.
static bool EmbeddedListInsert(const char *name, uint32_t buf, uint32_t size);

PPC_FUNC(sub_821BC140) {
  const uint32_t n = s_hBC140.fetch_add(1) + 1;
  // SAVE the slot descriptor before __imp__: the guest body clobbers r3
  // (return value = completion status). Every post-exec census must use
  // this snapshot — reading ctx.r3 after the call AV'd the consumer
  // (w1: thread 0xC5C parked in VEH, job #2 never INLINE-EXEC'd).
  const uint32_t slotAddr = ctx.r3.u32;
  const uint32_t queueArg = ctx.r4.u32;
  // F-179a: F-172 says the length BC140 uses is `[[0x8283D190+52] +
  // [slot+0]*28] + 4` and that it is 0; F-179 showed pgStreamer::Open resolving
  // all seven containers through vtable+84 -> +144 with non-null entry pointers
  // (w186 lr=821CC4BC). Both cannot be about the same record. Measure the
  // record this function actually indexes, before the body runs. Bounded by
  // construction: INLINE-EXEC fires 3x per boot, and every read is checked.
  // F-213 A/B instrument: widen to 60 executions and add the ring task's
  // READ-LIST COUNT (task+1540) + the slot's record +12 state / +4 len, to
  // decide whether BC140 skips a UI slot because it has ZERO read entries
  // (H1 read-list/staging gap) vs meshtextures' cnt>0. w230 showed BC140 JOINs
  // UI slots 0-3 but issues NO CC6F0 read for them (only 0x60000/0xA0000, all
  // ret=0). This is the single decisive measurement for that asymmetry.
  if (n <= 60) {
    auto &smem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t cls = 0, cap = 0, base = 0, ident = 0, rlc = 0, rl0 = 0, rl1 = 0;
    uint32_t rec[7] = {0};
    (void)smem.ReadU32BE(0x8283D190u, &cls);
    (void)smem.ReadU32BE(0x8283D190u + 24u, &cap);
    (void)smem.ReadU32BE(0x8283D190u + 52u, &base);
    (void)smem.ReadU32BE(slotAddr, &ident);
    (void)smem.ReadU32BE(slotAddr + 1540u, &rlc);   // read-list entry count
    (void)smem.ReadU32BE(slotAddr + 8u, &rl0);      // first entry [+0] (dest/off)
    (void)smem.ReadU32BE(slotAddr + 12u, &rl1);     // first entry [+4] (size)
    // BC140 masks [slot+0] with (cap-1) in place unless it is -1, then indexes
    // by *28 - mirror that exactly rather than assuming cap is already a mask.
    const uint32_t mask = cap - 1u;
    const uint32_t recAddr = base + (ident & mask) * 28u;
    for (uint32_t i = 0; i < 7u; ++i)
      (void)smem.ReadU32BE(recAddr + i * 4u, &rec[i]);
    MCLA_LOG_WARN("BC140-REC #{} slot={:08X} q={} id={:08X} mask={:08X} "
                  "base={:08X} rec={:08X} [{:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X}] cls={:08X} RLC={} e0={:08X}/{:08X} +24={:08X}",
                  n, slotAddr, queueArg, ident, mask, base, recAddr, rec[0],
                  rec[1], rec[2], rec[3], rec[4], rec[5], rec[6], cls, rlc, rl0,
                  rl1, rec[6]);
  }
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("INLINE-EXEC sub_821BC140 #{} a0={:08X} a1={:08X} "
                  "lr={:08X} r1={:08X} tid={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32,
                  static_cast<uint32_t>(ctx.lr), ctx.r1.u32,
                  GetCurrentThreadId());
  // NODE-CHAIN DUMP (session 19): the dispatched fnptr was ZERO. Walk the
  // list head a0 -> [a0+4]=node {node[0] ?, node[4]=fnptr, node[12]=next}
  // up to 3 nodes with checked reads (body starts with plain guest loads,
  // no early vtable dispatch - safe to pre-read).
  if (n <= 8) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    // Session 75n: these descriptors are the streamer request slots (queue
    // + 0x614 per slot). Dump the header dwords + attempt an ASCII name so
    // we know WHAT the 3 boot requests load and which callback they carry.
    uint32_t d[16] = {0};
    for (int i = 0; i < 16; ++i)
      (void)mem.ReadU32BE(ctx.r3.u32 + static_cast<uint32_t>(i * 4), &d[i]);
    char name[48] = {0};
    for (int nofs = 8; nofs <= 64 && name[0] == 0; nofs += 4) {
      const char *p = static_cast<const char *>(
          mcla::kernel::MmGetHostAddress(ctx.r3.u32 + static_cast<uint32_t>(nofs)));
      if (!p) break;
      size_t j = 0;
      for (; j < 40; ++j) {
        const unsigned char c = static_cast<unsigned char>(p[j]);
        if (c == 0) break;
        name[j] = (c >= 32 && c < 127) ? static_cast<char>(c) : '?';
      }
      name[j] = 0;
      if (j < 4) name[0] = 0; // too short to be a path â€” keep scanning
    }
    MCLA_LOG_INFO("REQDUMP #{} a0={:08X} name='{}' d=[{:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X}]",
                  n, ctx.r3.u32, name, d[0], d[1], d[2], d[3], d[4], d[5],
                  d[6], d[7], d[8], d[9], d[10], d[11], d[12], d[13], d[14],
                  d[15]);
    // F-205: the working meshtexture's READ-LIST so option (b) can replicate it.
    // BC140 iterates r25=task+8 (stride 8) reading {+0 off, +4 size} and stops
    // on size==0; entry count at task+1540 (ppc_recomp.14.cpp:19007/19030-19041).
    {
      uint32_t rlcnt = 0, e0o = 0, e0s = 0, e1o = 0, e1s = 0, rlid = 0;
      (void)mem.ReadU32BE(ctx.r3.u32 + 1540u, &rlcnt);
      (void)mem.ReadU32BE(ctx.r3.u32 + 8u, &e0o);
      (void)mem.ReadU32BE(ctx.r3.u32 + 12u, &e0s);
      (void)mem.ReadU32BE(ctx.r3.u32 + 16u, &e1o);
      (void)mem.ReadU32BE(ctx.r3.u32 + 20u, &e1s);
      (void)mem.ReadU32BE(ctx.r3.u32 + 0u, &rlid);
      MCLA_LOG_INFO("TASK-READLIST #{} task={:08X} id+0={:08X} cnt+1540={} "
                    "e0={:08X}/{:08X} e1={:08X}/{:08X}",
                    n, ctx.r3.u32, rlid, rlcnt, e0o, e0s, e1o, e1s);
    }
    // w25: Job2 REQDUMP (tag 0x8004) — seed PSTREAM map from the slot and
    // host-decompress package 0xA0000 into dest slices so place-pass has
    // real child object payload (not RSC residue at arr).
    if ((d[0] & 0xFFFFu) == 0x8004u) {
      uint32_t sc = 0;
      (void)mem.ReadU32BE(ctx.r3.u32 + 1540, &sc);
      if (sc > 24)
        sc = 24;
      g_mclaRebaseCount = 0;
      for (uint32_t si = 0; si < sc && g_mclaRebaseCount < kMclaRebaseMax;
           ++si) {
        const uint32_t sAddr = ctx.r3.u32 + 4 + si * 12;
        uint32_t vbase = 0, pbase = 0, size = 0;
        (void)mem.ReadU32BE(sAddr + 0, &vbase);
        (void)mem.ReadU32BE(sAddr + 4, &pbase);
        (void)mem.ReadU32BE(sAddr + 8, &size);
        if (MclaIsPstreamVirtual(vbase) && pbase != 0 && size != 0 &&
            size < 0x1000000u) {
          g_mclaRebaseMap[g_mclaRebaseCount].vbase = vbase;
          g_mclaRebaseMap[g_mclaRebaseCount].pbase = pbase;
          g_mclaRebaseMap[g_mclaRebaseCount].size = size;
          MclaNoteJob2Pbase(pbase);  // F-252: persist membership across the boot
          ++g_mclaRebaseCount;
        }
      }
      MclaPublishGuestRebaseTable();
      MCLA_LOG_WARN("W25-J2-EARLY-DIST reqdump#{} nmap={}", n,
                    g_mclaRebaseCount);
      const int wrote = MclaJob2DecompressAndDistribute(ctx);
      MCLA_LOG_WARN("W25-J2-EARLY-DIST-DONE reqdump#{} wrote={}", n, wrote);
    }
  }
  // POST-INFLATE CALLBACK TRACE: read context fields before execution.
  // r26 (ctx.r3) is the preload context. Key offsets:
  // +1540: stream count
  // +1544: inflated size
  // +1548: callback function pointer
  // +1552: archive device
  // +8: buffer/data pointer
  if (n <= 16 || (n % 500) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t ctxBase = ctx.r3.u32;
    uint32_t cbPtr = 0, arcDev = 0, bufPtr = 0, streamCnt = 0, inflSize = 0;
    mem.ReadU32BE(ctxBase + 1540, &streamCnt);
    mem.ReadU32BE(ctxBase + 1544, &inflSize);
    mem.ReadU32BE(ctxBase + 1548, &cbPtr);
    mem.ReadU32BE(ctxBase + 1552, &arcDev);
    mem.ReadU32BE(ctxBase + 8, &bufPtr);
    MCLA_LOG_WARN("PRELOAD-CTX #{} base={:08X} streamCnt={} inflSize={} "
                  "cbPtr={:08X} arcDev={:08X} bufPtr={:08X}",
                  n, ctxBase, streamCnt, inflSize, cbPtr, arcDev, bufPtr);
    // p2x: dump the 28-byte task/stream-table entry the refill uses for r30.
    // r28 = [0x8283D1C4] + tag*28; [r28+4] is the refill size (r30).
    {
      uint32_t tag = 0, entriesBase = 0, joinCount = 0;
      (void)mem.ReadU32BE(ctxBase + 0, &tag);
      (void)mem.ReadU32BE(0x8283D1C4u, &entriesBase);
      (void)mem.ReadU32BE(0x8283D1A8u, &joinCount);
      MCLA_LOG_WARN("STRTAB #{} tag={:08X} entries={:08X} joinCnt={}", n,
                    tag, entriesBase, joinCount);
      if (entriesBase && entriesBase != 0xCDCDCDCDu) {
        const uint32_t idx = tag & 0xFF; // table is small; clamp
        const uint32_t e = entriesBase + idx * 28u;
        uint32_t f[7] = {0};
        for (int i = 0; i < 7; ++i)
          (void)mem.ReadU32BE(e + static_cast<uint32_t>(i * 4), &f[i]);
        MCLA_LOG_WARN("STRENT #{} idx={} @{:08X} "
                      "+0={:08X} +4={:08X} +8={:08X} +12={:08X} "
                      "+16={:08X} +20={:08X} +24={:08X}",
                      n, idx, e, f[0], f[1], f[2], f[3], f[4], f[5], f[6]);
      }
    }
    // p2q: dump stream descriptors (12-byte stride at ctx+12). Job #2
    // (tag 0x8004, streamCnt=17) left inflate with inLeft=-44 reading a
    // stack buffer — identify which streams have no device/handle yet.
    if (streamCnt > 0 && streamCnt <= 64) {
      for (uint32_t si = 0; si < streamCnt && si < 24; ++si) {
        // w11: correct triplet layout {vbase, pbase, size} at ctx+4+si*12.
        // (Old census at ctx+12 read {size_i, vbase_{i+1}, pbase_{i+1}}.)
        const uint32_t sAddr = ctxBase + 4 + si * 12;
        uint32_t vbase = 0, pbase = 0, size = 0;
        (void)mem.ReadU32BE(sAddr + 0, &vbase);
        (void)mem.ReadU32BE(sAddr + 4, &pbase);
        (void)mem.ReadU32BE(sAddr + 8, &size);
        MclaUiXsfNoteSlot(n, si, vbase, pbase,
                          size);  // F-322 inventory for the hunt
        MCLA_LOG_WARN("PSTREAM #{} s[{}] @{:08X} vbase={:08X} pbase={:08X} "
                      "size={:08X}",
                      n, si, sAddr, vbase, pbase, size);
        // w21: job #2 UI dests announced here still CDCD in w20 (inflate
        // never re-entered). Pin them to package 0xA0000 and host-inflate
        // so B7B41000/B7B61000 get real payload before place-pass.
        if (IsJob2UiDest(pbase)) {
          uint32_t h0 = 0;
          (void)mem.ReadU32BE(pbase, &h0);
          const bool poison =
              h0 == 0xCDCDCDCDu || h0 == 0 || h0 == 0xFFFFFFFFu;
          uint32_t servedN = 0;
          {
            std::lock_guard<std::mutex> jl(g_j2ServedMtx);
            servedN = g_j2ServedCnt[pbase];
          }
          if (poison || servedN == 0) {
            static uint32_t s_pstreamSt = 0;
            if (s_pstreamSt == 0)
              s_pstreamSt = mem.Alloc(64, 16);
            (void)MclaForceServePkgForDest(pbase, s_pstreamSt,
                                           /*hostInflate=*/true);
          }
        }
      }
    }
  }
  __imp__sub_821BC140(ctx, base);
  // POST-EXEC: mount the inflated buffer as a memory: device so shader
  // lookups (star_glow etc.) can find it. The callback at [ctx+1548] is
  // 0x821BC548 (semaphore release) â€” wrong function. We do the mount here.
  // NOTE: use slotAddr (saved pre-call), never ctx.r3 — r3 is clobbered.
  MCLA_LOG_WARN("POST-EXEC-START #{} slot={:08X} qarg={:08X} r3after={:08X} "
                "tid={:08X}",
                n, slotAddr, queueArg, ctx.r3.u32, GetCurrentThreadId());
  if (n <= 16 || (n % 500) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t ctxBase = slotAddr;
    uint32_t streamCnt = 0, inflSize = 0, bufPtr = 0, arcDev = 0;
    mem.ReadU32BE(ctxBase + 1540, &streamCnt);
    mem.ReadU32BE(ctxBase + 1544, &inflSize);
    mem.ReadU32BE(ctxBase + 8, &bufPtr);
    mem.ReadU32BE(ctxBase + 1552, &arcDev);
    if (streamCnt > 0 && bufPtr != 0 && arcDev != 0) {
      // Register the inflated buffer under embedded:/ relative names.
      // inflSize in the preload ctx is a 12-byte sentinel; use the largest
      // INFLATE out capacity seen this process as the package size.
      // NOTE: do NOT Mount a fake device at 0xA001xxxx â€” that is o1heap and
      // previously caused sysMemMultiAllocator::Free ownership fatals.
      uint32_t regSize = inflSize;
      if (regSize < 16)
        regSize = s_maxInflateOut.load();
      if (regSize >= 16) {
        // w9 CENSUS: dump the inflated buffer head so we can see why any
        // effect-name insert would fail the rgxa compare.
        DumpBufHead("D2308-buf", bufPtr);
        UiDecVerifyReadback(bufPtr);
        // w9 FIX: only register names whose buffer actually starts with the
        // rgxa effect magic. The preload pack at A47FD000 is a multi-chunk
        // resource (first dword is NOT 0x61786772); registering star_glow /
        // rage_im against it made AFB76-HIT serve garbage into 8218C760 and
        // fatal "Old version of rage effect". rage_im is already CRT-seeded
        // from the static .data blob — do not overwrite with the pack.
        if (BufLooksLikeRgxa(bufPtr)) {
          static const char *kNames[] = {
              "fxl_final/star_glow.fxc",
              "dcl/star_glow.dcl",
              "star_glow.dcl",
              "shaders/star_glow.fxc",
              "fxl_final/star_glow",
          };
          for (const char *nm : kNames)
            (void)EmbeddedListInsert(nm, bufPtr, regSize);
          MCLA_LOG_WARN("D2308-INS-DONE #{} buf={:08X} size={} (infl={} maxOut={})",
                        n, bufPtr, regSize, inflSize, s_maxInflateOut.load());
        } else {
          MCLA_LOG_WARN("D2308-INS-SKIP #{} buf={:08X} size={} — not rgxa "
                        "(preload pack); AFB76-FALLBACK will serve rage_im",
                        n, bufPtr, regSize);
        }
      } else {
        MCLA_LOG_WARN("D2308-INS-SKIP #{} buf={:08X} inflSize={} maxOut={}",
                      n, bufPtr, inflSize, s_maxInflateOut.load());
      }
    } else {
      MCLA_LOG_WARN("POST-EXEC-SKIP #{} streamCnt={} buf={:08X} arc={:08X} infl={}",
                    n, streamCnt, bufPtr, arcDev, inflSize);
    }
  }
  // p3c: place-pass (FDBF8) often runs BEFORE job #2 fills B7B41000.
  // After a job whose dest is that container, re-run the build pass if the
  // object now looks live (vtable not CDCD).
  if (n >= 2) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t vt = 0, arr = 0;
    uint16_t cnt = 0;
    constexpr uint32_t kUiCont = 0xB7B41000u;
    (void)mem.ReadU32BE(kUiCont + 0, &vt);
    (void)mem.ReadU32BE(kUiCont + 12, &arr);
    (void)mem.ReadU16BE(kUiCont + 16, &cnt);
    // w33: after job2 POST-EXEC, census dest tag tables and attempt a
    // faithful guest construct bind (tags already in image) + EF100.
    (void)MclaW33ScanTagTableAndConstruct(kUiCont, ctx.r1.u32);
    // w34: one host lever — GFx parse-path census + parse-flag dispatch
    // when W33-PARSE-MISSING proves factories/EF220 never ran after inflate.
    (void)MclaW34GfxParseLever(kUiCont, slotAddr);
    // w35: faithful boot-gate lever — sub_82131008 is the guest callback that
    // gates the entire UI load path (UILOAD 822012E8). It checks two events
    // via 821C0750, then calls 822C0980 → 821FD640 → UILOAD. When UILOAD=0
    // and EF220=0 after POST-EXEC, dispatch the boot gate once to unblock
    // the movie/loader initialization chain. Never invent vtables or FEX
    // over live dests.
    //
    // W36: set the init-done flag at [0x8212E6F0]=1 before calling so
    // sub_82131008 skips the init step (sub_823043F8/82304348) that crashes
    // through the broken atArray allocator chain. The function unconditionally
    // calls sub_822C0980 at the end regardless of gate check results.
    //
    // W36b: boot gate dispatch from the GPU handler crashes in the TLS
    // allocator chain (wrong thread, broken per-thread allocator state).
    // Instead, read the boot worker's r26 (message queue context) from
    // g_faultCtx, log the queue state, and attempt to post a wake-up
    // message to the boot worker's ring buffer so IT calls the gate
    // callback on its own thread with proper TLS.
    {
      static std::atomic<uint32_t> s_w35Gate{0};
      const uint32_t gateN = s_w35Gate.fetch_add(1) + 1;
      if (gateN <= 5) {
        // Derive r26 (message queue context) from the known boot worker
        // event address. The WAIT log shows the boot worker waits on
        // event at guest address 0x40004D7C = r26+32, so r26=0x40004D5C.
        const uint32_t bwR26 = 0x40004D5Cu;
        const uint32_t bwR1  = mcla::boot::GetBootWorkerReg(1);
        MCLA_LOG_WARN("W36b-QUEUE #{} gate#{} bwR26={:08X} bwR1={:08X}",
                      n, gateN, bwR26, bwR1);
        auto &heap = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t qBase = 0, qWrite = 0, qRead = 0;
        (void)heap.ReadU32BE(bwR26 + 0, &qBase);   // [r26+0] = queue state ptr
        (void)heap.ReadU32BE(bwR26 + 56, &qWrite);  // [r26+56] = write cursor
        (void)heap.ReadU32BE(bwR26 + 60, &qRead);   // [r26+60] = read cursor
        MCLA_LOG_WARN("W36b-QUEUE #{} qBase={:08X} qWrite={} qRead={} delta={}",
                      n, qBase, qWrite, qRead,
                      static_cast<int32_t>(qWrite - qRead));
        if (qBase != 0) {
          uint32_t qThreshold = 0, qReadCursor = 0;
          (void)heap.ReadU32BE(qBase + 376, &qThreshold);
          (void)heap.ReadU32BE(bwR26 + 4, &qReadCursor);
          MCLA_LOG_WARN("W36b-QUEUE #{} qThreshold={} [r26+4]={}",
                        n, qThreshold, qReadCursor);
        }
      }
    }
    // Only rebuild on a REAL swfC vtable — 44495500 is inflate payload, not
    // an object (p3h Resource fatal from walking garbage).
    const bool realVt =
        (vt & 0xFFFF0000u) == 0x82080000u; // 8208521C / 82085364 family
    // w7: RSC resource head after XCompress (44495500 / 44365500 family).
    // The place-pass (825EF100) ran BEFORE job #2 inflated into this buffer,
    // so the C++ object it built was overwritten by raw RSC bytes. Parse the
    // RSC header and re-run the guest place-pass so the swfC object is
    // constructed from the real payload.
    const bool isRscHead =
        (vt & 0xFFFFFF00u) == 0x44495500u ||
        (vt & 0xFFFFFF00u) == 0x44365500u;
    if (realVt) {
      // w10: place-pass can write vt 8208521C/82085364 while arr/cnt are
      // still empty (early FDBF8 POISON-SKIP zeroed them, or job #2 had not
      // inflated yet). Restore arr from the rebased RSC map / dest payload
      // so the build pass has a real entry array — never invent a vtable.
      if ((arr == 0 || arr == 0xCDCDCDCDu || arr == 0xFFFFFFFFu) ||
          (cnt == 0 || cnt == 0xCDCDu)) {
        // Known physical arr from w9 RSC-REBASE: 5006C9B4 → B7B6D9B4.
        constexpr uint32_t kArrCand[] = {
            0xB7B6D9B4u, 0xB7B61000u, 0xB7B71000u, 0xB79C1000u,
            0xB79A1000u, 0xB7981000u,
        };
        for (uint32_t cand : kArrCand) {
          uint32_t c0 = 0, c1 = 0;
          (void)mem.ReadU32BE(cand, &c0);
          (void)mem.ReadU32BE(cand + 4, &c1);
          const bool live =
              c0 != 0xCDCDCDCDu && c0 != 0 && c0 != 0xFFFFFFFFu;
          if (!live)
            continue;
          // Prefer a candidate whose first word looks like a guest pointer
          // or a small tag — not raw inflate residue (0xFF.. / 0x0A0A..).
          const bool looksPtr = (c0 >= 0x80000000u && c0 < 0xA0000000u) ||
                                (c0 >= 0xB0000000u && c0 < 0xC0000000u);
          const bool looksTag = (c0 < 0x10000u);
          if (!looksPtr && !looksTag && cand != 0xB7B6D9B4u)
            continue;
          if (arr == 0 || arr == 0xCDCDCDCDu || arr == 0xFFFFFFFFu)
            arr = cand;
          if (cnt == 0 || cnt == 0xCDCDu) {
            // w9 RSC header +16 was 0001CDCD — low half often holds cnt=1
            // when the container has a single clip entry.
            uint16_t cntProbe = 0;
            (void)mem.ReadU16BE(kUiCont + 16, &cntProbe);
            if (cntProbe == 0 || cntProbe == 0xCDCDu)
              cntProbe = 1;
            cnt = cntProbe;
            (void)mem.WriteU32BE(kUiCont + 12, arr);
            (void)mem.WriteU16BE(kUiCont + 16, cnt);
          }
          MCLA_LOG_WARN("FDBF8-ARR-RESTORE #{} obj=B7B41000 vt={:08X} "
                        "arr={:08X} [arr]={:08X}/{:08X} cnt={} "
                        "(from dest cand {:08X})",
                        n, vt, arr, c0, c1, cnt, cand);
          break;
        }
      }
      // Re-run place-pass (not just FDBF8) so 825EF100 can walk entries
      // with the restored arr. 825EF100 calls FDBF8 internally.
      if (auto *place = mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
        static uint32_t s_rbCtx = 0;
        if (s_rbCtx == 0)
          s_rbCtx = mem.Alloc(64, 16);
        if (s_rbCtx) {
          // w11: arm guest rebase group with the PSTREAM region table.
          MclaArmRebaseCtx(s_rbCtx);
          PPCContext pctx;
          pctx.r1 = ctx.r1;
          pctx.r13 = ctx.r13;
          pctx.fpscr = ctx.fpscr;
          pctx.r3.u64 = kUiCont;
          pctx.r4.u64 = s_rbCtx;
          MCLA_LOG_WARN("FDBF8-REBUILD #{} obj=B7B41000 vt={:08X} arr={:08X} "
                        "cnt={} (via place-pass 825EF100)",
                        n, vt, arr, cnt);
          place(pctx, mcla::kernel::g_memory.base);
        }
      } else if (auto *fn = mcla::kernel::g_memory.FindFunction(0x825FDBF8u)) {
        PPCContext nctx;
        nctx.r1 = ctx.r1;
        nctx.r13 = ctx.r13;
        nctx.fpscr = ctx.fpscr;
        nctx.r3.u64 = kUiCont;
        MCLA_LOG_WARN("FDBF8-REBUILD #{} obj=B7B41000 vt={:08X} arr={:08X} "
                      "cnt={}",
                      n, vt, arr, cnt);
        fn(nctx, mcla::kernel::g_memory.base);
      }
    } else if (isRscHead) {
      // Census the RSC resource header so we can decode the format.
      uint32_t rh[8] = {0};
      for (int i = 0; i < 8; ++i)
        (void)mem.ReadU32BE(kUiCont + static_cast<uint32_t>(i * 4), &rh[i]);
      MCLA_LOG_WARN("RSC-HEAD #{} @{:08X} [{:08X} {:08X} {:08X} {:08X} "
                    "{:08X} {:08X} {:08X} {:08X}]",
                    n, kUiCont, rh[0], rh[1], rh[2], rh[3], rh[4], rh[5],
                    rh[6], rh[7]);
      // RSC5 resource layout (post-XCompress): pointers are in the 0x50xxxxxx
      // virtual range. The job stream descriptors give the virtual→physical
      // map. w11 REQDUMP decode: triplets {vbase, pbase, size} start at
      // ctx+4 (tag at ctx+0), stride 12. The old PSTREAM census read
      // ctx+12 as {w0,w1,w2}={size_i, vbase_{i+1}, pbase_{i+1}} — off by
      // one field, which DROPPED stream0 (job #2: 50000000→B7B41000) and
      // attached the previous stream's size to the next vbase. 5001CE90
      // lives in that dropped head region (→ B7B5DE90) and was the w11
      // Resource-fatal address.
      {
        // Build the rebase map from the job stream descriptors.
        // w11: accept BOTH package virtual bands — 0x50 nested-resource
        // pointers AND 0x60 stream/page dest tags (job #2 s[12]
        // 600E0000→B70A1000 is a place-pass Resource-fatal address).
        struct Reb { uint32_t vbase, pbase, size; };
        Reb map[24] = {};
        int nmap = 0;
        uint32_t sc = 0;
        (void)mem.ReadU32BE(slotAddr + 1540, &sc);
        if (sc > 24) sc = 24;
        for (uint32_t si = 0; si < sc; ++si) {
          // Correct layout: {vbase, pbase, size} at ctx+4+si*12.
          const uint32_t sAddr = slotAddr + 4 + si * 12;
          uint32_t vbase = 0, pbase = 0, size = 0;
          (void)mem.ReadU32BE(sAddr + 0, &vbase);
          (void)mem.ReadU32BE(sAddr + 4, &pbase);
          (void)mem.ReadU32BE(sAddr + 8, &size);
          if (MclaIsPstreamVirtual(vbase) && pbase != 0 &&
              size != 0 && size < 0x1000000u) {
            map[nmap++] = {vbase, pbase, size};
            if (nmap <= 20)
              MCLA_LOG_WARN("PSTREAM-MAP #{} s[{}] @{:08X} "
                            "v={:08X} p={:08X} sz={:08X}",
                            n, si, sAddr, vbase, pbase, size);
          }
        }
        // Publish for sub_8217D890 / sub_82184458 (see g_mclaRebaseMap).
        g_mclaRebaseCount = nmap;
        for (int i = 0; i < nmap && i < kMclaRebaseMax; ++i) {
          g_mclaRebaseMap[i].vbase = map[i].vbase;
          g_mclaRebaseMap[i].pbase = map[i].pbase;
          g_mclaRebaseMap[i].size = map[i].size;
          MclaNoteJob2Pbase(map[i].pbase);  // F-252: persist membership
        }
        // w11: materialize the guest region table D828 walks.
        MclaPublishGuestRebaseTable();
        auto rebasePtr = [&](uint32_t p) -> uint32_t {
          if (!MclaIsPstreamVirtual(p)) return p;
          for (int i = 0; i < nmap; ++i) {
            if (p >= map[i].vbase && p < map[i].vbase + map[i].size)
              return map[i].pbase + (p - map[i].vbase);
          }
          return p;
        };
        // Rebase the 8 header dwords in place.
        uint32_t rewritten = 0;
        for (int i = 1; i < 8; ++i) {
          if (MclaIsPstreamVirtual(rh[i])) {
            const uint32_t np = rebasePtr(rh[i]);
            if (np != rh[i]) {
              (void)mem.WriteU32BE(kUiCont + static_cast<uint32_t>(i * 4), np);
              MCLA_LOG_WARN("RSC-REBASE #{} [{:08X}] {:08X} -> {:08X}", n,
                            kUiCont + static_cast<uint32_t>(i * 4), rh[i], np);
              rh[i] = np;
              ++rewritten;
            }
          }
        }
        MCLA_LOG_WARN("RSC-REBASE-DONE #{} nmap={} rewritten={}", n, nmap,
                      rewritten);
        // w9/w11: walk each mapped physical region once and rebase nested
        // 0x50xxxxxx AND 0x60xxxxxx pointers via the same PSTREAM map.
        // Without this the place-pass / guest walks deref virtual group
        // addresses that have no backing (600E0000 Resource fatal).
        {
          uint32_t nested = 0, scanned = 0;
          for (int i = 0; i < nmap; ++i) {
            const uint32_t pbase = map[i].pbase;
            const uint32_t size = map[i].size;
            if (pbase == 0 || size < 4 || size > 0x400000u)
              continue;
            for (uint32_t off = 0; off + 4 <= size; off += 4) {
              uint32_t v = 0;
              if (!mem.ReadU32BE(pbase + off, &v))
                break;
              ++scanned;
              if (!MclaIsPstreamVirtual(v))
                continue;
              const uint32_t np = rebasePtr(v);
              if (np != v) {
                (void)mem.WriteU32BE(pbase + off, np);
                if (nested < 16)
                  MCLA_LOG_WARN("RSC-NEST #{} [{:08X}] {:08X} -> {:08X}", n,
                                pbase + off, v, np);
                ++nested;
              }
            }
          }
          MCLA_LOG_WARN("RSC-NEST-DONE #{} scanned={} nested={}", n, scanned,
                        nested);
        }
      }
      // w8: dump dests BEFORE place-pass so the census still prints if
      // place fatals (w8 soak hit "Old version of rage effect" inside
      // 8260A8B0 after a successful fill of B7B61000/B7B71000).
      {
        constexpr uint32_t kPreDests[] = {
            0xB7B41000u, 0xB7981000u, 0xB79A1000u,
            0xB7B61000u, 0xB7B71000u, 0xB79C1000u,
        };
        for (uint32_t d : kPreDests) {
          uint32_t w[8] = {0};
          for (int i = 0; i < 8; ++i)
            (void)mem.ReadU32BE(d + static_cast<uint32_t>(i * 4), &w[i]);
          const char *cls = "?";
          if (w[0] == 0xCDCDCDCDu)
            cls = "POISON";
          else if ((w[0] & 0xFFFF0000u) == 0x82080000u)
            cls = "swfC-obj";
          else if ((w[0] & 0xFFFFFF00u) == 0x44495500u ||
                   (w[0] & 0xFFFFFF00u) == 0x44365500u)
            cls = "RSC-res";
          else if (w[0] == 0)
            cls = "zero";
          MCLA_LOG_WARN("DEST-DUMP #{} @{:08X} [{}] "
                        "{:08X} {:08X} {:08X} {:08X} "
                        "{:08X} {:08X} {:08X} {:08X}",
                        n, d, cls, w[0], w[1], w[2], w[3], w[4], w[5], w[6],
                        w[7]);
          // w21: poison job #2 UI dests → package 0xA0000 host-inflate so
          // place-pass has real payload (w20: B798/79A/7B6/7B7 stayed CDCD).
          if (IsJob2UiDest(d) && (w[0] == 0xCDCDCDCDu || w[0] == 0)) {
            static uint32_t s_dumpSt = 0;
            if (s_dumpSt == 0)
              s_dumpSt = mem.Alloc(64, 16);
            (void)MclaForceServePkgForDest(d, s_dumpSt, /*hostInflate=*/true);
          }
        }
      }
      // Now re-run the guest place-pass 825EF100(r3=obj, r4=rebase-ctx) —
      // but ONLY if the rebased arr pointer lands on real (non-poison)
      // data. B7B61000 was never inflated by job #2, so arr=B7B6D9B4 is
      // still CDCD. Calling place-pass on that fatals in 8217D890.
      uint32_t arrNow = 0, arrC0 = 0;
      (void)mem.ReadU32BE(kUiCont + 12, &arrNow);
      if (arrNow != 0 && arrNow != 0xFFFFFFFFu && arrNow != 0xCDCDCDCDu)
        (void)mem.ReadU32BE(arrNow, &arrC0);
      if (arrC0 == 0xCDCDCDCDu || arrNow == 0 || arrNow == 0xCDCDCDCDu) {
        MCLA_LOG_WARN("RSC-PLACE-SKIP #{} arr={:08X} [arr]={:08X} "
                      "(dest never inflated — need B7B61000/B7B71000 "
                      "chunks)",
                      n, arrNow, arrC0);
        // w25: poison arr — feed package windows then re-place.
        {
          static uint32_t s_skipCtx = 0;
          if (s_skipCtx == 0)
            s_skipCtx = mem.Alloc(64, 16);
          const int wrote = MclaJob2DecompressAndDistribute(ctx);
          MCLA_LOG_WARN("W25-SKIP-DIST #{} wrote={} arr={:08X}", n, wrote,
                        arrNow);
          if (wrote > 0 && s_skipCtx != 0) {
            MclaCompleteRscRebaseBeforePlace(kUiCont);
            if (auto *placeS =
                    mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
              MclaArmRebaseCtx(s_skipCtx);
              PPCContext pS;
              pS.r1 = ctx.r1;
              pS.r13 = ctx.r13;
              pS.fpscr = ctx.fpscr;
              pS.r3.u64 = kUiCont;
              pS.r4.u64 = s_skipCtx;
              placeS(pS, mcla::kernel::g_memory.base);
              uint32_t vtS = 0, arrS = 0, aS = 0;
              uint16_t cntS = 0;
              (void)mem.ReadU32BE(kUiCont + 0, &vtS);
              (void)mem.ReadU32BE(kUiCont + 12, &arrS);
              (void)mem.ReadU16BE(kUiCont + 16, &cntS);
              if (arrS && arrS != 0xCDCDCDCDu && arrS != 0xFFFFFFFFu)
                (void)mem.ReadU32BE(arrS, &aS);
              MCLA_LOG_WARN("W25-SKIP-PLACE-DONE #{} vt={:08X} arr={:08X} "
                            "[arr]={:08X} cnt={}",
                            n, vtS, arrS, aS, cntS);
            }
          }
        }
      } else if (auto *place =
                     mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
        static uint32_t s_rebaseCtx = 0;
        if (s_rebaseCtx == 0)
          s_rebaseCtx = mem.Alloc(64, 16);
        if (s_rebaseCtx != 0) {
          // w24: complete 0x50/0x60 rebase + census on the 44495500 head
          // BEFORE 825EF100. Gate-bad [arr] (533D00CB / walk 41C4FF12) is
          // handled by D2378/D890/A830 delta-0 + Resource soft-park.
          MclaCompleteRscRebaseBeforePlace(kUiCont);
          if (MclaPtrIsGateBad(arrC0))
            MCLA_LOG_WARN("RSC-PLACE-ARR-GATE #{} arr={:08X} [arr]={:08X} "
                          "— not in 0x50/0x60/0x80-B map; place will "
                          "delta-0 the walk",
                          n, arrNow, arrC0);
          // w24: EF100 reads u16[obj+50] as the entry-walk bound AFTER
          // FDBF8. On an RSC-res head whose arr[0] is gate-bad that bound
          // is residue (0x00A4) — cap it so construct returns. Not a
          // vtable invent; guest still writes the real 8208xxxx vt.
          // w32: do NOT cap when +24[1..] already holds dest-range /
          // SWF-tag construct candidates — that was the FDA90 starvation gate.
          {
            uint16_t cnt50 = 0;
            (void)mem.ReadU16BE(kUiCont + 50, &cnt50);
            const bool p24Live =
                MclaW32OpenConstructWalk(kUiCont, 0, /*redispatch=*/false);
            if (cnt50 > 1 && !p24Live && (MclaPtrIsGateBad(arrC0) ||
                                          arrC0 == 0xCDCDCDCDu || arrC0 == 0))
            {
              (void)mem.WriteU16BE(kUiCont + 50, 1);
              MCLA_LOG_WARN("RSC-PLACE-CNT-GATE #{} obj=B7B41000 +50 {} -> 1",
                            n, cnt50);
            }
            else if (p24Live)
            {
              MCLA_LOG_WARN("RSC-PLACE-CNT-HOLD #{} obj=B7B41000 +50={} "
                            "p24Live=1 — keep guest construct walk",
                            n, cnt50);
            }
          }
          // w11: arm [group+0] = PSTREAM region table so D828 can resolve
          // 0x50/0x60 virtuals (w10 fatal: old=600E0000 lr=82184514).
          MclaArmRebaseCtx(s_rebaseCtx);
          PPCContext pctx;
          pctx.r1 = ctx.r1;
          pctx.r13 = ctx.r13;
          pctx.fpscr = ctx.fpscr;
          pctx.r3.u64 = kUiCont;
          pctx.r4.u64 = s_rebaseCtx;
          MCLA_LOG_WARN("RSC-PLACE #{} obj=B7B41000 rebaseCtx={:08X} "
                        "hdr={:08X}",
                        n, s_rebaseCtx, vt);
          place(pctx, mcla::kernel::g_memory.base);
          // Post-place census: did we get a real swfC vtable?
          uint32_t vt2 = 0, arr2 = 0;
          uint16_t cnt2 = 0;
          (void)mem.ReadU32BE(kUiCont + 0, &vt2);
          (void)mem.ReadU32BE(kUiCont + 12, &arr2);
          (void)mem.ReadU16BE(kUiCont + 16, &cnt2);
          MCLA_LOG_WARN("RSC-PLACE-DONE #{} vt={:08X} arr={:08X} cnt={} "
                        "(want 8208xxxx)",
                        n, vt2, arr2, cnt2);
          // w30: bind already-written PSTREAM 8208xxxx kids after place.
          if (MclaHeadIsPlaceVt(vt2))
            (void)MclaW30BindPstreamChildren(mem, kUiCont, 0);
          // w31: deep dest-range census + bind already-written children.
          if (MclaHeadIsPlaceVt(vt2))
            MclaW31CensusBindPlace(mem, 0);
          // w25: deep child census. If arr is still gate-bad / no real
          // swfC children, feed guest inflate/place the package windows
          // (host decompress package 0xA0000 → PSTREAM dest slices), then
          // re-dispatch place. Never invent a vtable.
          {
            uint32_t kids[16] = {0}, kvts[16] = {0};
            const int nKids = MclaCensusSwfcChildren(mem, kids, kvts, 16);
            uint32_t arr0w = 0;
            if (arr2 && arr2 != 0xCDCDCDCDu && arr2 != 0xFFFFFFFFu)
              (void)mem.ReadU32BE(arr2, &arr0w);
            const bool arrGateBad =
                arr2 == 0 || arr2 == 0xCDCDCDCDu || arr2 == 0xFFFFFFFFu ||
                MclaPtrIsGateBad(arr0w) || arr0w == 0xCDCDCDCDu || arr0w == 0;
            const bool wantFeed = arrGateBad || nKids == 0;
            MCLA_LOG_WARN("W25-POSTPLACE-CENSUS #{} vt={:08X} arr={:08X} "
                          "[arr]={:08X} cnt={} nKids={} arrGateBad={} "
                          "wantFeed={}",
                          n, vt2, arr2, arr0w, cnt2, nKids,
                          arrGateBad ? 1 : 0, wantFeed ? 1 : 0);
            if (wantFeed) {
              const int wrote = MclaJob2DecompressAndDistribute(ctx);
              MCLA_LOG_WARN("W25-J2-DIST #{} wrote={}", n, wrote);
              if (wrote > 0) {
                // Rebase + place again on the newly fed resource image.
                MclaCompleteRscRebaseBeforePlace(kUiCont);
                uint32_t hdr0 = 0;
                (void)mem.ReadU32BE(kUiCont, &hdr0);
                if (auto *place2 =
                        mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
                  if (s_rebaseCtx != 0) {
                    MclaArmRebaseCtx(s_rebaseCtx);
                    PPCContext p2;
                    p2.r1 = ctx.r1;
                    p2.r13 = ctx.r13;
                    p2.fpscr = ctx.fpscr;
                    p2.r3.u64 = kUiCont;
                    p2.r4.u64 = s_rebaseCtx;
                    MCLA_LOG_WARN("W25-PLACE-AFTER-DIST #{} hdr={:08X} "
                                  "rebaseCtx={:08X}",
                                  n, hdr0, s_rebaseCtx);
                    place2(p2, mcla::kernel::g_memory.base);
                    uint32_t vt4 = 0, arr4 = 0, a0 = 0;
                    uint16_t cnt4 = 0;
                    (void)mem.ReadU32BE(kUiCont + 0, &vt4);
                    (void)mem.ReadU32BE(kUiCont + 12, &arr4);
                    (void)mem.ReadU16BE(kUiCont + 16, &cnt4);
                    if (arr4 && arr4 != 0xCDCDCDCDu &&
                        arr4 != 0xFFFFFFFFu)
                      (void)mem.ReadU32BE(arr4, &a0);
                    MCLA_LOG_WARN("W25-PLACE-AFTER-DIST-DONE #{} vt={:08X} "
                                  "arr={:08X} [arr]={:08X} cnt={}",
                                  n, vt4, arr4, a0, cnt4);
                    // Census again after place on fed image.
                    uint32_t kids2[16] = {0}, kvts2[16] = {0};
                    const int nk2 =
                        MclaCensusSwfcChildren(mem, kids2, kvts2, 16);
                    MCLA_LOG_WARN("W25-POSTDIST-CHILDREN #{} n={} ", n, nk2);
                    // Bind: if real 8208xxxx children exist but arr[0] is
                    // still not one of them, compact the real pointers that
                    // are already live in guest memory (place-built objects
                    // or dest-resident object heads) into arr and re-place.
                    if (nk2 > 0 && arr4 != 0 && arr4 != 0xCDCDCDCDu &&
                        arr4 != 0xFFFFFFFFu) {
                      uint32_t a0b = 0;
                      (void)mem.ReadU32BE(arr4, &a0b);
                      bool arrHasReal = false;
                      for (int ki = 0; ki < nk2; ++ki)
                        if (a0b == kids2[ki])
                          arrHasReal = true;
                      if (!arrHasReal) {
                        for (int ki = 0; ki < nk2 && ki < 8; ++ki)
                          (void)mem.WriteU32BE(
                              arr4 + static_cast<uint32_t>(ki * 4),
                              kids2[ki]);
                        (void)mem.WriteU16BE(
                            kUiCont + 16,
                            static_cast<uint16_t>(nk2 > 8 ? 8 : nk2));
                        MCLA_LOG_WARN("W25-ARR-BIND #{} arr={:08X} n={} "
                                      "arr0={:08X}->{:08X} vt0={:08X}",
                                      n, arr4, nk2, a0b, kids2[0], kvts2[0]);
                        if (auto *place3 = mcla::kernel::g_memory.FindFunction(
                                0x825EF100u)) {
                          if (s_rebaseCtx != 0) {
                            MclaArmRebaseCtx(s_rebaseCtx);
                            PPCContext p3;
                            p3.r1 = ctx.r1;
                            p3.r13 = ctx.r13;
                            p3.fpscr = ctx.fpscr;
                            p3.r3.u64 = kUiCont;
                            p3.r4.u64 = s_rebaseCtx;
                            place3(p3, mcla::kernel::g_memory.base);
                          }
                        }
                        uint32_t vt5 = 0, arr5 = 0, a0c = 0;
                        uint16_t cnt5 = 0;
                        (void)mem.ReadU32BE(kUiCont + 0, &vt5);
                        (void)mem.ReadU32BE(kUiCont + 12, &arr5);
                        (void)mem.ReadU16BE(kUiCont + 16, &cnt5);
                        if (arr5 && arr5 != 0xCDCDCDCDu &&
                            arr5 != 0xFFFFFFFFu)
                          (void)mem.ReadU32BE(arr5, &a0c);
                        MCLA_LOG_WARN("W25-ARR-BIND-DONE #{} vt={:08X} "
                                      "arr={:08X} [arr]={:08X} cnt={}",
                                      n, vt5, arr5, a0c, cnt5);
                      }
                    }
                  }
                }
              }
            } else if (nKids > 0 && arrGateBad == false) {
              // Children exist and arr looks live — still bind if arr[0]
              // is not a real child (compact place-written pointers).
              uint32_t a0b = 0;
              (void)mem.ReadU32BE(arr2, &a0b);
              bool arrHasReal = false;
              for (int ki = 0; ki < nKids; ++ki)
                if (a0b == kids[ki])
                  arrHasReal = true;
              if (!arrHasReal) {
                for (int ki = 0; ki < nKids && ki < 8; ++ki)
                  (void)mem.WriteU32BE(
                      arr2 + static_cast<uint32_t>(ki * 4), kids[ki]);
                (void)mem.WriteU16BE(
                    kUiCont + 16,
                    static_cast<uint16_t>(nKids > 8 ? 8 : nKids));
                MCLA_LOG_WARN("W25-ARR-BIND-EARLY #{} arr={:08X} n={} "
                              "arr0={:08X}->{:08X}",
                              n, arr2, nKids, a0b, kids[0]);
              }
            }
          }
          // w13: dump arr children so we can see stub vs real 8208xxxx.
          if (arr2 != 0 && arr2 != 0xCDCDCDCDu && arr2 != 0xFFFFFFFFu) {
            static const char *kCls[] = {"zero", "poison", "swfC", "rsc",
                                         "ptr", "other"};
            uint32_t realKids[8] = {0};
            uint32_t realVts[8] = {0};
            int nReal = 0;
            for (int ci = 0; ci < 8; ++ci) {
              uint32_t child = 0, cvt = 0;
              (void)mem.ReadU32BE(arr2 + static_cast<uint32_t>(ci * 4),
                                  &child);
              // Only deref pointers that look like guest heap/code — junk
              // words (0x41, EE4EF8F7, …) host-AV inside ReadU32BE.
              const bool childPtr =
                  child >= 0x80000000u && child < 0xC0000000u &&
                  child != 0xCDCDCDCDu && child != 0xFFFFFFFFu;
              if (childPtr)
                (void)mem.ReadU32BE(child, &cvt);
              const char *cls = "zero";
              if (child == 0)
                cls = kCls[0];
              else if (child == 0xCDCDCDCDu || child == 0xFFFFFFFFu)
                cls = kCls[1];
              else if (childPtr && (cvt & 0xFFFF0000u) == 0x82080000u)
                cls = kCls[2];
              else if (childPtr && ((cvt & 0xFFFFFF00u) == 0x44495500u ||
                                    (cvt & 0xFFFFFF00u) == 0x44365500u))
                cls = kCls[3];
              else if (child >= 0x80000000u)
                cls = kCls[4];
              else
                cls = kCls[5];
              MCLA_LOG_WARN("PLACE-CHILD #{} arr={:08X}[{}]={:08X} "
                            "vt={:08X} cls={}",
                            n, arr2, ci, child, cvt, cls);
              if (childPtr && (cvt & 0xFFFF0000u) == 0x82080000u &&
                  nReal < 8) {
                realKids[nReal] = child;
                realVts[nReal] = cvt;
                ++nReal;
                uint32_t cw[6] = {0};
                for (int k = 0; k < 6; ++k)
                  (void)mem.ReadU32BE(
                      child + static_cast<uint32_t>(k * 4), &cw[k]);
                MCLA_LOG_WARN("PLACE-REALCHILD #{} ptr={:08X} vt={:08X} "
                              "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                              n, child, cvt, cw[0], cw[1], cw[2], cw[3],
                              cw[4], cw[5]);
              }
            }
            // Compact real 8208xxxx children to arr[0..] and set cnt so the
            // UI walker sees them (never invent a vtable — only rearrange
            // pointers the place-pass already wrote). Avoid deref of arr[0]
            // when it is junk (FF000000) — that read can host-AV.
            bool arrFixed = false;
            if (nReal > 0) {
              uint32_t a0 = 0;
              (void)mem.ReadU32BE(arr2, &a0);
              const bool arr0LooksReal = (a0 >= 0x80000000u &&
                                          a0 < 0xC0000000u &&
                                          a0 != 0xCDCDCDCDu &&
                                          a0 != 0xFFFFFFFFu &&
                                          a0 == realKids[0]);
              const bool needFix =
                  !arr0LooksReal || cnt2 != static_cast<uint16_t>(nReal);
              MCLA_LOG_WARN("PLACE-ARR-PRE #{} arr={:08X} nReal={} cnt={} "
                            "arr0={:08X} needFix={}",
                            n, arr2, nReal, cnt2, a0, needFix ? 1 : 0);
              if (needFix) {
                for (int ci = 0; ci < nReal; ++ci)
                  (void)mem.WriteU32BE(
                      arr2 + static_cast<uint32_t>(ci * 4), realKids[ci]);
                (void)mem.WriteU16BE(kUiCont + 16,
                                     static_cast<uint16_t>(nReal));
                arrFixed = true;
                MCLA_LOG_WARN("PLACE-ARR-FIX #{} arr={:08X} nReal={} "
                              "cnt {} -> {} (compact real 8208xxxx to front; "
                              "arr[0]={:08X} vt={:08X})",
                              n, arr2, nReal, cnt2, nReal, realKids[0],
                              realVts[0]);
              }
            }
            const bool anyReal = nReal > 0;
            uint32_t xsfHits = 0;
            {
              std::lock_guard<std::mutex> lk(g_xsfMtx);
              for (const auto &kv : g_xsfToc)
                xsfHits += kv.second.bodyHits;
            }
            // w14: guest place() runs BEFORE ARR-FIX and walks junk arr[0]
            // (head at arr[1] via FIXWALK). After compact the root is never
            // re-read — UI walker starves. One host fix: re-dispatch place
            // (825EF100 → FDBF8) so the guest consumes arr[0]=real child.
            // Never invent a vtable — only re-run the existing guest pass.
            if (arrFixed) {
              static std::atomic<uint32_t> s_arrFixRerun{0};
              const uint32_t rn = s_arrFixRerun.fetch_add(1) + 1;
              if (rn <= 3) {
                MCLA_LOG_WARN("PLACE-ARR-RERUN #{} arr={:08X} xsfHits={} — "
                              "re-dispatch 825EF100 after ARR-FIX compact",
                              rn, arr2, xsfHits);
                if (auto *place2 =
                        mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
                  if (s_rebaseCtx != 0) {
                    MclaArmRebaseCtx(s_rebaseCtx);
                    PPCContext p2;
                    p2.r1 = ctx.r1;
                    p2.r13 = ctx.r13;
                    p2.fpscr = ctx.fpscr;
                    p2.r3.u64 = kUiCont;
                    p2.r4.u64 = s_rebaseCtx;
                    place2(p2, mcla::kernel::g_memory.base);
                    uint32_t vt3 = 0, arr3 = 0, a0 = 0, a1 = 0;
                    uint16_t cnt3 = 0;
                    (void)mem.ReadU32BE(kUiCont + 0, &vt3);
                    (void)mem.ReadU32BE(kUiCont + 12, &arr3);
                    (void)mem.ReadU16BE(kUiCont + 16, &cnt3);
                    if (arr3 != 0 && arr3 != 0xCDCDCDCDu &&
                        arr3 != 0xFFFFFFFFu) {
                      (void)mem.ReadU32BE(arr3 + 0, &a0);
                      (void)mem.ReadU32BE(arr3 + 4, &a1);
                    }
                    MCLA_LOG_WARN("PLACE-ARR-RERUN-DONE #{} vt={:08X} "
                                  "arr={:08X} cnt={} arr[0]={:08X} "
                                  "arr[1]={:08X}",
                                  rn, vt3, arr3, cnt3, a0, a1);
                  }
                }
              }
            }
            // w15 nested place: FDBF8-build saw children still on the 5500
            // resource-head family (C4445500/D0815500). Guest place-pass
            // converts those to 8208xxxx when run as ROOT (proven on
            // B7B41000 44495500→82085364 and B7B61000 D0815500→82088784)
            // but children only received FDBF8-build. Re-dispatch the same
            // guest pass 825EF100 on those objects — never invent a vtable.
            if (s_rebaseCtx != 0 && g_mclaNestedPlaceN > 0) {
              if (auto *placeN =
                      mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
                static std::atomic<uint32_t> s_nestedPlaceRun{0};
                const int nCand = g_mclaNestedPlaceN;
                int dispatched = 0, converted = 0, skipped = 0;
                int alreadySwfC = 0, notFamily = 0, isRoot = 0;
                std::string census;
                for (int i = 0; i < nCand && dispatched < 12; ++i) {
                  const uint32_t nobj = g_mclaNestedPlaceObj[i];
                  if (nobj == 0)
                    continue;
                  uint32_t nvt = 0, nf4 = 0, narr = 0;
                  uint16_t ncnt = 0;
                  (void)mem.ReadU32BE(nobj + 0, &nvt);
                  (void)mem.ReadU32BE(nobj + 4, &nf4);
                  (void)mem.ReadU32BE(nobj + 12, &narr);
                  (void)mem.ReadU16BE(nobj + 16, &ncnt);
                  if (census.size() < 240)
                    census += fmt::format(" {:08X}:{:08X}", nobj, nvt);
                  // Root already handled by RSC-PLACE / ARR-RERUN.
                  if (nobj == kUiCont) {
                    ++skipped;
                    ++isRoot;
                    continue;
                  }
                  const bool already =
                      (nvt & 0xFFF00000u) == 0x82000000u;
                  const bool family =
                      (nvt & 0xFFFFu) == 0x5500u ||
                      (nvt & 0xFFFFFF00u) == 0xC4445500u ||
                      (nvt & 0xFFFFFF00u) == 0xD0815500u ||
                      (nvt & 0xFFFFFF00u) == 0x44495500u ||
                      (nvt & 0xFFFFFF00u) == 0x44365500u;
                  if (already) {
                    ++skipped;
                    ++alreadySwfC;
                    continue;
                  }
                  if (!family) {
                    ++skipped;
                    ++notFamily;
                    continue;
                  }
                  MclaArmRebaseCtx(s_rebaseCtx);
                  PPCContext p3;
                  p3.r1 = ctx.r1;
                  p3.r13 = ctx.r13;
                  p3.fpscr = ctx.fpscr;
                  p3.r3.u64 = nobj;
                  p3.r4.u64 = s_rebaseCtx;
                  MCLA_LOG_WARN("NESTED-PLACE-RERUN #{} obj={:08X} "
                                "vt={:08X} +4={:08X} arr={:08X} cnt={} "
                                "— re-dispatch 825EF100 as place-root",
                                dispatched + 1, nobj, nvt, nf4, narr, ncnt);
                  placeN(p3, mcla::kernel::g_memory.base);
                  uint32_t nvt2 = 0, narr2 = 0;
                  uint16_t ncnt2 = 0;
                  (void)mem.ReadU32BE(nobj + 0, &nvt2);
                  (void)mem.ReadU32BE(nobj + 12, &narr2);
                  (void)mem.ReadU16BE(nobj + 16, &ncnt2);
                  const bool nowSwfC =
                      (nvt2 & 0xFFFF0000u) == 0x82080000u;
                  if (nowSwfC)
                    ++converted;
                  MCLA_LOG_WARN("NESTED-PLACE-RERUN-DONE #{} obj={:08X} "
                                "vt={:08X}->{:08X} arr={:08X} cnt={} "
                                "converted={}",
                                dispatched + 1, nobj, nvt, nvt2, narr2,
                                ncnt2, nowSwfC ? 1 : 0);
                  ++dispatched;
                }
                const uint32_t np =
                    s_nestedPlaceRun.fetch_add(1) + 1;
                if (np <= 3)
                  MCLA_LOG_WARN("NESTED-PLACE-SUMMARY #{} cands={} "
                                "dispatched={} converted={} skipped={} "
                                "(alreadySwfC={} notFamily={} isRoot={}) "
                                "vtCensus:{}",
                                np, nCand, dispatched, converted, skipped,
                                alreadySwfC, notFamily, isRoot, census);
              }
            }
            if (!anyReal && cnt2 <= 1) {
              static std::atomic<uint32_t> s_placeRerun{0};
              const uint32_t rn = s_placeRerun.fetch_add(1) + 1;
              if (rn <= 3) {
                MCLA_LOG_WARN("PLACE-RERUN #{} cnt={} xsfHits={} — re-dispatch "
                              "825EF100 (children still stub)",
                              rn, cnt2, xsfHits);
                if (auto *place2 =
                        mcla::kernel::g_memory.FindFunction(0x825EF100u)) {
                  if (s_rebaseCtx != 0) {
                    MclaArmRebaseCtx(s_rebaseCtx);
                    PPCContext p2;
                    p2.r1 = ctx.r1;
                    p2.r13 = ctx.r13;
                    p2.fpscr = ctx.fpscr;
                    p2.r3.u64 = kUiCont;
                    p2.r4.u64 = s_rebaseCtx;
                    place2(p2, mcla::kernel::g_memory.base);
                    uint32_t vt3 = 0, arr3 = 0;
                    uint16_t cnt3 = 0;
                    (void)mem.ReadU32BE(kUiCont + 0, &vt3);
                    (void)mem.ReadU32BE(kUiCont + 12, &arr3);
                    (void)mem.ReadU16BE(kUiCont + 16, &cnt3);
                    MCLA_LOG_WARN("PLACE-RERUN-DONE #{} vt={:08X} arr={:08X} "
                                  "cnt={}",
                                  rn, vt3, arr3, cnt3);
                  }
                }
              }
            }
          }
        }
      }
    } else if (n <= 8) {
      MCLA_LOG_WARN("FDBF8-REBUILD-SKIP #{} vt={:08X} (still poison)", n, vt);
    }
    // w1a census: dump job #2 dest buffers AFTER COMPLETE so we know what
    // the inflate actually produced (file payload vs object vs poison).
    if (n == 2) {
      constexpr uint32_t kDests[] = {
          0xB7B41000u, 0xB7981000u, 0xB79A1000u,
          0xB7B61000u, 0xB7B71000u, 0xB79C1000u,
      };
      for (uint32_t d : kDests) {
        uint32_t w[8] = {0};
        for (int i = 0; i < 8; ++i)
          (void)mem.ReadU32BE(d + static_cast<uint32_t>(i * 4), &w[i]);
        // Classify: 8208xxxx = swfC vtable, 4449xxxx/4436xxxx = RSC resource
        // head after XCompress, CDCDCDCD = never written.
        const char *cls = "?";
        if (w[0] == 0xCDCDCDCDu)
          cls = "POISON";
        else if ((w[0] & 0xFFFF0000u) == 0x82080000u)
          cls = "swfC-obj";
        else if ((w[0] & 0xFFFFFF00u) == 0x44495500u ||
                 (w[0] & 0xFFFFFF00u) == 0x44365500u)
          cls = "RSC-res";
        else if (w[0] == 0)
          cls = "zero";
        MCLA_LOG_WARN("DEST-DUMP #{} @{:08X} [{}] "
                      "{:08X} {:08X} {:08X} {:08X} "
                      "{:08X} {:08X} {:08X} {:08X}",
                      n, d, cls, w[0], w[1], w[2], w[3], w[4], w[5], w[6],
                      w[7]);
      }
    }
  }
  // p3g: after job #1 (shader preload COMPLETE), seed star_glow names into
  // the embedded list from the inflate dest so lookup does not fatal.
  // w9 FIX: same rgxa gate as D2308-INS — the inflate dest is the preload
  // PACK, not a single effect. Registering it as star_glow made the effect
  // loader's 8218C844 magic compare fail ("Old version of rage effect").
  // Leave the list clean so AFB76-MISS → AFB76-FALLBACK serves rage_im.
  if (n == 1) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t bufPtr = 0;
    (void)mem.ReadU32BE(slotAddr + 8, &bufPtr);
    uint32_t sz = s_maxInflateOut.load();
    if (bufPtr == 0 || bufPtr == 0xCDCDCDCDu)
      bufPtr = 0xA47FD000u;
    if (sz < 16)
      sz = 0x20000;
    DumpBufHead("STAR-GLOW-SEED", bufPtr);
    if (!BufLooksLikeRgxa(bufPtr)) {
      MCLA_LOG_WARN("STAR-GLOW-SEED #{} buf={:08X} size={} — not rgxa, "
                    "skip insert (fallback serves rage_im)",
                    n, bufPtr, sz);
    } else {
      static const char *kShaderNames[] = {
          "fxl_final/star_glow.fxc",
          "dcl/star_glow.dcl",
          "star_glow.dcl",
          "shaders/star_glow.fxc",
          "fxl_final/star_glow",
          "star_glow",
      };
      int ins = 0;
      for (const char *nm : kShaderNames)
        if (EmbeddedListInsert(nm, bufPtr, sz))
          ++ins;
      MCLA_LOG_WARN("STAR-GLOW-SEED #{} buf={:08X} size={} inserted={}", n,
                    bufPtr, sz, ins);
    }
  }
  // POST-EXEC: re-read to see if callback fired (state changes)
  if (n <= 16 || (n % 500) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t ctxBase = slotAddr;
    uint32_t streamCnt2 = 0;
    mem.ReadU32BE(ctxBase + 1540, &streamCnt2);
    MCLA_LOG_INFO("POST-EXEC sub_821BC140 #{} slot={:08X} streamCnt={}",
                  n, ctxBase, streamCnt2);
  }
}

// RING-B CONSUMER census: threads #14/#15 run Function_821BC910(arg=0/1).
// Entry = thread start; RETURN = one full wait->pop->maybe-execute cycle
// completed. If returns happen but INLINE-EXEC stays 0, the consumer woke,
// popped, and SKIPPED (slot[0x60C]==0 or empty slot). If no return after the
// wake release, our host semaphore wake is broken for this handle.
PPC_FUNC_IMPL(__imp__sub_821BC910);
static std::atomic<uint32_t> s_hBC910in{0};
static std::atomic<uint32_t> s_hBC910out{0};
PPC_FUNC(sub_821BC910) {
  const uint32_t n = s_hBC910in.fetch_add(1) + 1;
  const uint32_t arg = ctx.r3.u32;
  const uint32_t qBase = 0x82849518u + arg * 24948u;
  if (n <= 8)
    MCLA_LOG_INFO("RINGB-CONSUMER sub_821BC910 ENTER #{} arg={:08X} "
                  "q={:08X} waitH@+6154 r1={:08X} tid={:08X}",
                  n, arg, qBase, ctx.r1.u32, GetCurrentThreadId());
  // Pre-wait snapshot: popIdx @+0x6164, count @+0x6168, wait @+0x616C.
  // (24932=0x6164, 24936=0x6168, 24940=0x616C — decimal disasm offsets.)
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t popIdx = 0, cnt = 0, waitH = 0;
    (void)mem.ReadU32BE(qBase + 0x6164, &popIdx);
    (void)mem.ReadU32BE(qBase + 0x6168, &cnt);
    (void)mem.ReadU32BE(qBase + 0x616C, &waitH);
    MCLA_LOG_INFO("RINGB-CONSUMER PRE #{} q={:08X} popIdx={} cnt={} "
                  "waitH={:08X} tid={:08X}",
                  n, qBase, popIdx, cnt, waitH, GetCurrentThreadId());
  }
  __imp__sub_821BC910(ctx, base);
  const uint32_t d = s_hBC910out.fetch_add(1) + 1;
  // Counters for BOTH consumer queues using REAL offsets
  // (write +0x6160, pop +0x6164, count +0x6168, wait +0x616C).
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t w0 = 0, p0 = 0, c0 = 0, h0 = 0, w1 = 0, p1 = 0, c1 = 0, h1 = 0;
    (void)mem.ReadU32BE(0x82849518u + 0x6160, &w0);
    (void)mem.ReadU32BE(0x82849518u + 0x6164, &p0);
    (void)mem.ReadU32BE(0x82849518u + 0x6168, &c0);
    (void)mem.ReadU32BE(0x82849518u + 0x616C, &h0);
    (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6160, &w1);
    (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6164, &p1);
    (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6168, &c1);
    (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x616C, &h1);
    MCLA_LOG_INFO("RINGB-CONSUMER CYCLE #{} r3={:08X} q0 w/p/c/h={}/{}/{}/{:08X} "
                  "q1 w/p/c/h={}/{}/{}/{:08X} tid={:08X} (empty-pop/exit)",
                  d, ctx.r3.u32, w0, p0, c0, h0, w1, p1, c1, h1,
                  GetCurrentThreadId());
  }
}

// PRODUCER-PUSH census (session 16): Function_821BC868 pushes a task slot
// and releases [q+0x616C]. Queue base family = 0x82849518 + idx*0x6174 (ring
// B) / 0x8283D218 family (ring A) - both sides agree statically, so log the
// ACTUAL q pointer to see which index/instance the parked submit used.
// Register-only entry logging (crash lesson from BCB10+0x7B).
PPC_FUNC_IMPL(__imp__sub_821BC868);
static std::atomic<uint32_t> s_hBC868{0};
PPC_FUNC(sub_821BC868) {
  const uint32_t n = s_hBC868.fetch_add(1) + 1;
  const uint32_t q = ctx.r3.u32;
  __imp__sub_821BC868(ctx, base);
  // Queue-counter dump: REAL offsets from sub_821BC868 (decimal disasm):
  //   write 24928=+0x6160, pop 24932=+0x6164, count 24936=+0x6168,
  //   wait 24940=+0x616C. slot = q + wIdx*1556; cb @ slot+0x60C.
  if (n <= 16 || (n % 2000) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t wIdx = 0, pIdx = 0, cnt = 0, relH = 0;
    const bool okW = mem.ReadU32BE(q + 0x6160, &wIdx);
    const bool okP = mem.ReadU32BE(q + 0x6164, &pIdx);
    const bool okC = mem.ReadU32BE(q + 0x6168, &cnt);
    const bool okR = mem.ReadU32BE(q + 0x616C, &relH);
    uint32_t slotCb = 0, slotTag = 0;
    const uint32_t slot = q + wIdx * 1556u;
    (void)mem.ReadU32BE(slot + 0x60C, &slotCb);
    (void)mem.ReadU32BE(slot + 0, &slotTag);
    // Session 75o: walk the guest stack to name the boot requester above
    // the push wrapper. Recompiler convention saves LR at [back-8]; plain
    // ABI frames save it at [back+4] â€” try both, log both.
    char chain[160] = {0};
    size_t off = 0;
    uint32_t sp = ctx.r1.u32;
    for (int f = 0; f < 5 && sp != 0 && off + 16 < sizeof(chain); ++f) {
      uint32_t back = 0, lrA = 0, lrB = 0;
      if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
      (void)mem.ReadU32BE(back - 8, &lrA);
      (void)mem.ReadU32BE(back + 4, &lrB);
      off += static_cast<size_t>(snprintf(chain + off, sizeof(chain) - off,
                                          " f%d=%08X/%08X", f, lrA, lrB));
      sp = back;
    }
    MCLA_LOG_INFO(
        "PUSH sub_821BC868 #{} q={:08X} wIdx={}{} pIdx={}{} cnt={}{} "
        "relH={:08X}{} slot={:08X} tag={:08X} cb={:08X}{} "
        "lr={:08X} tid={:08X} chain[{}]",
        n, q, wIdx, okW ? "" : "?", pIdx, okP ? "" : "?", cnt, okC ? "" : "?",
        relH, okR ? "" : "?", slot, slotTag, slotCb, slotCb ? "" : "(EMPTY)",
        ctx.lr, GetCurrentThreadId(), chain);
  }
}

// Session 75o: completion dispatcher census. The transfer executor
// (sub_821BC140) tail calls sub_821C31B8(slot+1544, slot+8, slot+1552,
// slot+1548) when slot+1540 != 0 â€” the per-transfer completion, which then
// issues a virtual call (vtable+88). If this never runs after the 3 boot
// transfers, the init sequence never advances.
PPC_FUNC_IMPL(__imp__sub_821C31B8);
static std::atomic<uint32_t> s_hC31B8{0};
PPC_FUNC(sub_821C31B8) {
  const uint32_t n = s_hC31B8.fetch_add(1) + 1;
  if (n <= 16 || (n % 500) == 0)
    MCLA_LOG_INFO("COMPLETE sub_821C31B8 #{} a0={:08X} a1={:08X} a2={:08X} "
                  "a3={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821C31B8(ctx, base);
}

// RELEASE-HANDLE census (session 72): sub_821C9108(h) â†’ sub_8244ED10(h,1,0).
// Ring-B PUSH should release queue+0x616C to wake the consumer parked on
// C5000300. That SIGNAL never appeared. Dump every release handle.
PPC_FUNC_IMPL(__imp__sub_821C9108);
static std::atomic<uint32_t> s_hC9108{0};
PPC_FUNC(sub_821C9108) {
  const uint32_t n = s_hC9108.fetch_add(1) + 1;
  const uint32_t h = ctx.r3.u32;
  if (n <= 40 || (n % 500) == 0)
    MCLA_LOG_INFO("RELSEMA sub_821C9108 #{} h={:08X} lr={:08X}", n, h,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821C9108(ctx, base);
}

// ---------------------------------------------------------------------------
// TU83 DRIVER-WORKER census: sub_824569C8 is the worker loop the main guest
// thread parks inside (sibling 824569C4 = empty padding stub). Its global
// block 0x827D3738: event-handle@+52 (PARK-SAMPLE saw C9ADB800),
// deadline@+128/+132, lazy-init@+184, wake flags@+188/+196/+200/+208/+212.
// Census dumps all wake-relevant fields + caller LR at entry so we can pin
// which field transition must lift the park. No direct callers exist
// module-wide => invoked as a thread entry / function pointer.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_824569C8);
static std::atomic<uint32_t> s_h569C8{0};
PPC_FUNC(sub_824569C8) {
  const uint32_t n = s_h569C8.fetch_add(1) + 1;
  constexpr uint32_t kBlk = 0x827D3738u;
  const uint32_t lr = ctx.lr;
  uint32_t ev52 = 0, dl128 = 0, dl132 = 0, f184 = 0, f188 = 0, f196 = 0;
  uint32_t f200 = 0, f208 = 0, f212 = 0, cbTarget = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(kBlk + 52, &ev52);
    (void)mem.ReadU32BE(kBlk + 128, &dl128);
    (void)mem.ReadU32BE(kBlk + 132, &dl132);
    (void)mem.ReadU32BE(kBlk + 184, &f184);
    (void)mem.ReadU32BE(kBlk + 188, &f188);
    (void)mem.ReadU32BE(kBlk + 196, &f196);
    (void)mem.ReadU32BE(kBlk + 200, &f200);
    (void)mem.ReadU32BE(kBlk + 208, &f208);
    (void)mem.ReadU32BE(kBlk + 212, &f212);
    uint32_t cbStruct = 0;
    if (mem.ReadU32BE(0x82945A80u + 16, &cbStruct) && cbStruct != 0) {
      (void)mem.ReadU32BE(cbStruct, &cbTarget);
    }
  }
  MCLA_LOG_WARN("WORKER sub_824569C8 #{} lr={:08X} ev={:08X} dl={:08X}/{:08X} "
         "f184={} f188={:08X} f196={:08X} f200={:08X} f208={:08X} f212={:08X} "
         "cbt={:08X}",
         n, lr, ev52, dl128, dl132, f184 != 0, f188, f196, f200, f208, f212,
         cbTarget);
  __imp__sub_824569C8(ctx, base);
}

// ---------------------------------------------------------------------------
// GPU fence wait short-circuit: sub_82412F98 busy-loops reading
// *(TLS_block+332) but the CP drain only writes to *(TLS_block+88).
// The fence never signals, parking the main thread forever in boot.
// Override returns r3=0 (success) to unblock boot â†’ start menu.
// Reference: PARK-SAMPLE shows thread stuck at lr=82412FA0 (mid-function
// label inside sub_82412F98), polling dev+10896 sub-context via TLS.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82412F98);
static std::atomic<uint32_t> s_h12F98{0};
PPC_FUNC(sub_82412F98) {
  const uint32_t n = s_h12F98.fetch_add(1) + 1;
  // r3 = frame pointer, *(r3+0) = device context
  const uint32_t dev = ctx.r3.u32;
  uint32_t actualDev = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev, &actualDev);
  }
  MCLA_LOG_WARN("F98-SKIP #{} frame={:08X} dev={:08X} lr={:08X}", n, dev, actualDev, ctx.lr);
  
  // Also log the TLS block fence addresses being polled
  if (n <= 10) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t tlsBlock = dev + 0x14C; // TLS block offset from device
    uint32_t tlsFence = 0, tlsCp = 0;
    mem.ReadU32BE(tlsBlock + 88, &tlsCp); // CP write pointer
    mem.ReadU32BE(tlsBlock + 332, &tlsFence); // Fence being polled
    MCLA_LOG_WARN("F98-TLS dev={:08X} tlsBlock={:08X} cpPtr={:08X} fencePoll={:08X}", 
        dev, tlsBlock, tlsCp, tlsFence);
  }
  ctx.r3.u64 = 0; // return 0 = "fence satisfied, proceed"
}

// Session 75o: THE request entry census. sub_821E5F48 is called by 31
// subsystems (incl. streamables loader 82216B98, UI-adjacent 82201B30) to
// push a load request + create a task join. Log every request with its
// caller so a soak shows who requested the boot batch and whether anyone
// ever requests again.
PPC_FUNC_IMPL(__imp__sub_821E5F48);
static std::atomic<uint32_t> s_h5F48{0};
PPC_FUNC(sub_821E5F48) {
  const uint32_t n = s_h5F48.fetch_add(1) + 1;
  if (n <= 48 || (n % 200) == 0)
    MCLA_LOG_INFO("REQ sub_821E5F48 #{} a0={:08X} a1={:08X} a2={:08X} "
                  "a3={:08X} a4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  ctx.r7.u32, static_cast<uint32_t>(ctx.lr));
  // F-192: capture the REAL meshtexture enqueue descriptors so Path B can copy
  // their exact layout. Per ppc_recomp.21.cpp:5585-5589, E5F48 forwards
  //   r6 -> E5E58 r3 = I (inflate desc; filled by E5DC8 open, so near-empty here)
  //   r7 -> E5E58 r4 = D (data/layout desc; caller-supplied, THIS is what we need)
  // D+0/+2 = u16 counts (countA,countB), D+4 = 12-byte entry array.
  {
    const uint32_t dPtr = ctx.r7.u32, iPtr = ctx.r6.u32;
    if (dPtr >= 0x80000000u && dPtr < 0xE0000000u &&
        dPtr != 0xCDCDCDCDu && iPtr >= 0x80000000u && iPtr < 0xE0000000u) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      uint32_t dw[6] = {0}, iw[4] = {0};
      for (int i = 0; i < 6; ++i)
        (void)mem.ReadU32BE(dPtr + i * 4, &dw[i]);
      for (int i = 0; i < 4; ++i)
        (void)mem.ReadU32BE(iPtr + i * 4, &iw[i]);
      MCLA_LOG_WARN("REQ-DESC #{} D={:08X}[{:08X} {:08X} {:08X} {:08X} {:08X} "
                    "{:08X}] I={:08X}[{:08X} {:08X} {:08X} {:08X}] lr={:08X}",
                    n, dPtr, dw[0], dw[1], dw[2], dw[3], dw[4], dw[5],
                    iPtr, iw[0], iw[1], iw[2], iw[3],
                    static_cast<uint32_t>(ctx.lr));
    }
  }
  __imp__sub_821E5F48(ctx, base);
}

// F-200 census: E5C78 builds a load-request record from (r3=recBuf, r4=256,
// r5=arg0, r6=arg1, r7=count, r8=0). Captured at ENTRY for BOTH the working
// meshtexture requests (lr~0x821E5E00, via E5DC8) and the UI opens (lr~0x821E29AC,
// via E2940) to see whether arg0 is a path string or a static template pointer,
// and what `count` a working request uses — the datum needed to feed FDD50/E5F48
// correctly (my Path B used E2940's pathPtr + count=27 and got record[+4]=0).
static std::atomic<uint32_t> s_h5C78{0};
PPC_FUNC_IMPL(__imp__sub_821E5C78);
// F-200: stash the STATIC resource-id arg0/arg1 that E2940's internal E5C78 uses
// (lr=0x821E29AC), so the Path B FDD50 call can pass the same static string instead
// of E2940's heap pathPtr (the +4=0 root cause). Reset per E2940 via the flag below.
static std::atomic<uint32_t> s_pbE2940Arg0{0};
static std::atomic<uint32_t> s_pbE2940Arg1{0};
PPC_FUNC(sub_821E5C78) {
  const uint32_t n = s_h5C78.fetch_add(1) + 1;
  const uint32_t a0 = ctx.r5.u32, a1 = ctx.r6.u32, cnt = ctx.r7.u32;
  const uint32_t lrc = static_cast<uint32_t>(ctx.lr);
  if (lrc == 0x821E29ACu) {  // E2940's own E5C78 → capture its static args
    s_pbE2940Arg0.store(a0);
    s_pbE2940Arg1.store(a1);
  }
  if (n <= 24 || (n % 200) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t a0w = 0, a1w = 0;
    if (a0 >= 0x80000000u && a0 < 0xE0000000u) (void)mem.ReadU32BE(a0, &a0w);
    if (a1 >= 0x80000000u && a1 < 0xE0000000u) (void)mem.ReadU32BE(a1, &a1w);
    // F-201: dump the arg0/arg1 STRING bytes — the exact resource-id/path format a
    // working request uses (legals) vs the UI path-open, to construct a correct
    // single async request for the 4 broken containers.
    char s0[40] = {0}, s1[40] = {0};
    if (a0 >= 0x80000000u && a0 < 0xE0000000u)
      for (int i = 0; i < 32; ++i) {
        uint8_t c = 0;
        if (!mem.ReadBytes(a0 + i, &c, 1) || c == 0 || c > 0x7E) break;
        s0[i] = static_cast<char>(c);
      }
    if (a1 >= 0x80000000u && a1 < 0xE0000000u)
      for (int i = 0; i < 24; ++i) {
        uint8_t c = 0;
        if (!mem.ReadBytes(a1 + i, &c, 1) || c == 0 || c > 0x7E) break;
        s1[i] = static_cast<char>(c);
      }
    MCLA_LOG_WARN("E5C78-C #{} arg0={:08X}[\"{}\"] arg1={:08X}[\"{}\"] "
                  "count={} lr={:08X}",
                  n, a0, s0, a1, s1, cnt, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821E5C78(ctx, base);
}

// F-192 census: dump the FULLY-POPULATED enqueue descriptors at sub_821E5E58
// ENTRY for the WORKING (meshtexture) requests, which E5F48 fills during its
// E5DC8 open BEFORE calling E5E58 (ppc_recomp.21.cpp:5565 then :5589). Path B's
// E2940 hook calls __imp__sub_821E5E58 directly, so this weak-dispatch hook sees
// only guest-internal (meshtexture) calls — the golden reference for I/D layout.
static std::atomic<uint32_t> s_h5E58{0};
PPC_FUNC_IMPL(__imp__sub_821E5E58);
PPC_FUNC(sub_821E5E58) {
  const uint32_t n = s_h5E58.fetch_add(1) + 1;
  const uint32_t iPtr = ctx.r3.u32, dPtr = ctx.r4.u32;
  if (iPtr >= 0x80000000u && iPtr < 0xE0000000u &&
      dPtr >= 0x80000000u && dPtr < 0xE0000000u &&
      (n <= 16 || (n % 50) == 0)) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t iw[4] = {0}, dw[8] = {0};
    for (int i = 0; i < 4; ++i) (void)mem.ReadU32BE(iPtr + i * 4, &iw[i]);
    for (int i = 0; i < 8; ++i) (void)mem.ReadU32BE(dPtr + i * 4, &dw[i]);
    MCLA_LOG_WARN("ENQ-D #{} I={:08X}[{:08X} {:08X} {:08X} {:08X}] "
                  "D={:08X}[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X}] r5={:08X} r6={:08X} lr={:08X}",
                  n, iPtr, iw[0], iw[1], iw[2], iw[3], dPtr, dw[0], dw[1],
                  dw[2], dw[3], dw[4], dw[5], dw[6], dw[7], ctx.r5.u32,
                  ctx.r6.u32, static_cast<uint32_t>(ctx.lr));
  }
  // F-204b MITIGATION (labelled per do-not #9; gated by kPathBEnqueueUI): the
  // un-confounded w232 test PROVED the async FDD50/E5DC8 open cannot size
  // record[+4] for the 4 UI containers even with the EXACT static arg0/tag/count
  // (+24=pkgoff resolves, +4 stays 0). record[+4] is the container's UNCOMPRESSED
  // length (F-180; = RSC5+0x10, real data we already read at serve time), and it
  // is the ONE field E2940's sync open fills but the async open leaves 0. This
  // decisive test seeds that known length into the enqueued record right before
  // BCB10 puts it on the ring, isolating whether +4 is the executor's blocker or
  // merely necessary. Self-identifying: only fires when the slot's record has
  // +4==0 AND +24 matches a known UI pkgoff (meshtextures/legals have +4!=0 and
  // are untouched). pkgoff→uncompLen from F-198/E5C78-C (stable across boots).
  if (kPathBEnqueueUI && iPtr >= 0x80000000u && iPtr < 0xE0000000u) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t slotWord = 0;
    (void)mem.ReadU32BE(iPtr + 0, &slotWord);
    const uint32_t slot = slotWord & 0x7FFFu;
    uint32_t recBase = 0;
    if (mem.ReadU32BE(0x8283D190u + 52u, &recBase) && recBase >= 0x80000000u &&
        recBase < 0xE0000000u) {
      const uint32_t rec = recBase + slot * 28u;
      uint32_t r4 = 0, r24 = 0;
      (void)mem.ReadU32BE(rec + 4, &r4);
      (void)mem.ReadU32BE(rec + 24, &r24);
      uint32_t seedLen = 0;
      switch (r24) {
        case 0x64CB0000u: seedLen = 0x00022EDDu; break;  // raceeditor 143069
        case 0x64980000u: seedLen = 0x00104449u; break;  // garage     1065545
        case 0x64CA3000u: seedLen = 0x00004B89u; break;  // policecam    19337
        case 0x6496F000u: seedLen = 0x000073D7u; break;  // credits      29655
        default: break;
      }
      if (r4 == 0 && seedLen != 0) {
        (void)mem.WriteU32BE(rec + 4, seedLen);
        MCLA_LOG_WARN("PATHB-SEED #{} slot={} rec={:08X} +24={:08X} +4:0→{:08X}",
                      n, slot, rec, r24, seedLen);
      }
    }
  }
  __imp__sub_821E5E58(ctx, base);
}

// F-187: sub_821E2940 opens .xsf UI containers through pgStreamer::Open +
// sub_821BC7A0, but never enqueues them for async inflate. The non-UI path
// (sub_821E5DC8 -> sub_821E5F48 -> sub_821E5E58) does enqueue. Direct
// enqueue from inside this hook corrupts guest state (3/4 opens fail with
// handle=FFFFFFFF). Need to find a safe injection point — likely at the
// caller level (sub_821FDED8) after all four opens complete.
// T41.9 Path B: forward-declare the enqueue primitives we call from the hook
// below (defined in generated/ppc_xenon; same pattern as __imp__sub_821E2940).
PPC_FUNC_IMPL(__imp__sub_821E5C78);
PPC_FUNC_IMPL(__imp__sub_821BC7A0);
PPC_FUNC_IMPL(__imp__sub_821E5E58);
PPC_FUNC_IMPL(__imp__sub_821FDD50);
PPC_FUNC_IMPL(__imp__sub_821E2940);
static std::atomic<uint32_t> s_hE2940{0};
PPC_FUNC(sub_821E2940) {
  const uint32_t n = s_hE2940.fetch_add(1) + 1;
  const uint32_t structPtr = ctx.r3.u32;
  const uint32_t pathPtr = ctx.r4.u32;
  const uint32_t paramR5 = ctx.r5.u32;
  const uint32_t countR6 = ctx.r6.u32;  // = 27 for the UI containers (E5C78 count arg)
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  char pathName[68] = {0};
  if (pathPtr != 0 && pathPtr != 0xCDCDCDCDu) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    mem.ReadBytes(pathPtr, pathName, 64);
    MclaSanitizePath(pathName, sizeof(pathName));
  }
  // F-198/F-199 single-open path: skip the real E2940 open for UI containers so
  // FDD50's open is the FIRST (correct-length) one; then enqueue happens in FDD50.
  const bool isUiContainer =
      lr >= 0x821FE520u && lr <= 0x821FE5D4u && countR6 == 27 &&
      pathPtr != 0 && pathPtr != 0xCDCDCDCDu;
  if (kPathBEnqueueUI && kPathBSingleOpen && isUiContainer) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    static uint32_t s_soStack = 0;
    if (s_soStack == 0) {
      const uint32_t raw = mem.Alloc(0x800, 16);
      s_soStack = raw ? (raw + 0x700u) : 0u;
    }
    const uint32_t outSlot = mem.Alloc(8, 16);
    if (s_soStack && outSlot) {
      (void)mem.WriteU32BE(outSlot, 0);
      (void)mem.WriteU32BE(outSlot + 4, 0);
      PPCContext f{};
      f.r1.u64 = s_soStack;
      f.r13.u64 = 0x8F200000u;
      f.r3.u64 = outSlot;
      // F-204 clean test: F-192..F-201 all silently fell back to `pathPtr` because
      // the E5C78 static-arg0 capture never fires through __imp__sub_821E2940. But
      // E5FD0 passes FDD50's r4/r5/r6 STRAIGHT to E5C78 as (arg0, arg1, count) — no
      // snprintf (ppc_recomp.20.cpp:1689-1703) — so feeding the EXACT static resource-id
      // pointer E2940's own E5C78 used must reproduce record[+4]=143069. Those pointers
      // are stable guest .data (E5C78-C, w228/w230): raceeditor=0x8201BAAC,
      // garage=0x8201BA9C, policecam=0x8201BA88, credits=0x8201BA78, arg1=0x8201BB28
      // "#sf", count=27. This is the first UN-confounded single-request test of the +4
      // lever: correct static arg0 AND no E2940 double-open. If PATHB-REC now shows the
      // enqueued record +4!=0 and the executor inflates → Path B unlocks; if +4!=0 and it
      // STILL livelocks → F-203 refuted, residual is serve framing (F-194); if +4==0 even
      // with the exact static arg0 → async builder cannot size these, F-201's real claim.
      uint32_t staticArg0 = 0;
      if (std::strcmp(pathName, "raceeditor/raceeditor") == 0)
        staticArg0 = 0x8201BAACu;
      else if (std::strcmp(pathName, "garage/garage") == 0)
        staticArg0 = 0x8201BA9Cu;
      else if (std::strcmp(pathName, "policecam/policecam") == 0)
        staticArg0 = 0x8201BA88u;
      else if (std::strcmp(pathName, "credits/credits") == 0)
        staticArg0 = 0x8201BA78u;
      f.r4.u64 = staticArg0 ? staticArg0 : pathPtr;
      f.r5.u64 = 0x8201BB28u;  // the "#sf" tag E2940's E5C78 passed as arg1
      f.r6.u64 = countR6;       // count = 27
      f.r7.u64 = 0;
      f.lr = 0x821FE6ECu;
      __imp__sub_821FDD50(f, base);   // sole open + enqueue with the exact static arg0
      uint32_t fhandle = 0;
      (void)mem.ReadU32BE(outSlot, &fhandle);
      // Give the caller a coherent struct: +0=0, +4=handle/dest, +8=0.
      (void)mem.WriteU32BE(structPtr + 0, 0);
      (void)mem.WriteU32BE(structPtr + 4, fhandle);
      (void)mem.WriteU32BE(structPtr + 8, 0);
      ctx.r3.u64 = 1;  // E2940 returns ret=1 on success
      MCLA_LOG_WARN("PATHB-SO #{} path='{}' FDD50 ret={:08X} out0={:08X} -> "
                    "struct+4={:08X}",
                    n, pathName, f.r3.u32, fhandle, fhandle);
      // Diagnostic: dump the record for this path's pkg offset (find +4!=0).
      uint32_t recBase = 0;
      if (mem.ReadU32BE(0x8283D190u + 52u, &recBase) &&
          recBase >= 0x80000000u && recBase < 0xE0000000u) {
        for (uint32_t h = 0; h < 12u; ++h) {
          const uint32_t rec = recBase + h * 28u;
          uint32_t w4 = 0, w24 = 0;
          (void)mem.ReadU32BE(rec + 4, &w4);
          (void)mem.ReadU32BE(rec + 24, &w24);
          if (w4 != 0 || w24 != 0)
            MCLA_LOG_WARN("PATHB-SOREC #{} id={} +4={:08X} +24={:08X}", n, h,
                          w4, w24);
        }
      }
    }
    return;
  }
  __imp__sub_821E2940(ctx, base);
  uint32_t handle = 0xFFFFFFFFu;
  if (structPtr != 0 && structPtr != 0xCDCDCDCDu) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(structPtr + 4, &handle);
  }
  if (n <= 8 || (n % 100) == 0) {
    MCLA_LOG_WARN("UI-OPEN sub_821E2940 #{} struct={:08X} path='{}' "
                  "r5={:08X} -> handle={:08X} ret={:08X} lr={:08X}",
                  n, structPtr, pathName, paramR5,
                  handle, ctx.r3.u32, lr);
  }

  // T41.9 / F-192 Path B v2 — re-issue the enqueue E2940 omits by calling the
  // GUEST's own async helper sub_821FDD50 with the SAME args E2940 received, so
  // the guest builds the inflate/data descriptors (I+0 ctx + D table) correctly.
  // v1 hand-built them and got I+0 wrong (F-192). FDD50(r3=outSlot, r4=path,
  // r5=tag, r6=count, r7=0) is what meshtextures call at ppc_recomp.22.cpp:15168
  // (count=9); UI containers reach it with count=27 and their own path/tag.
  // Gate: the 4 UI opens (lr in sub_821FDED8's E2940 sites) with count==27.
  const bool fromUiOpenLoop = lr >= 0x821FE520u && lr <= 0x821FE5D4u;
  if (kPathBEnqueueUI && fromUiOpenLoop && countR6 == 27 &&
      handle != 0xFFFFFFFFu && handle != 0xCDCDCDCDu &&
      pathPtr != 0 && pathPtr != 0xCDCDCDCDu) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    static uint32_t s_pb2Stack = 0;
    if (s_pb2Stack == 0) {
      const uint32_t raw = mem.Alloc(0x800, 16);
      s_pb2Stack = raw ? (raw + 0x700u) : 0u;
    }
    const uint32_t outSlot = mem.Alloc(8, 16);  // FDD50 writes the load handle
    if (s_pb2Stack && outSlot) {
      (void)mem.WriteU32BE(outSlot, 0);
      (void)mem.WriteU32BE(outSlot + 4, 0);
      PPCContext f{};
      f.r1.u64 = s_pb2Stack;
      f.r13.u64 = 0x8F200000u;
      f.r3.u64 = outSlot;   // out param (FDD50 :14800 stores handle here)
      // F-200: use the STATIC resource-id string E2940's internal E5C78 used
      // (captured during __imp__sub_821E2940 above), NOT the heap pathPtr — the
      // pathPtr caused E5C78 to build a garbage record → record[+4]=0 (F-200).
      const uint32_t sArg0 = s_pbE2940Arg0.load();
      const uint32_t sArg1 = s_pbE2940Arg1.load();
      f.r4.u64 = (sArg0 != 0 && sArg0 != 0xCDCDCDCDu) ? sArg0 : pathPtr;
      f.r5.u64 = (sArg1 != 0 && sArg1 != 0xCDCDCDCDu) ? sArg1 : paramR5;
      f.r6.u64 = countR6;   // count = 27
      f.r7.u64 = 0;
      // F-251: publish this container's REAL archive package offset BEFORE the
      // FDD50 call, because FDD50 synchronously runs the record build + the
      // streamer inflate (AssignPackageForDest is hit mid-call). The post-call
      // PATHB-PKGFIX is 7 ms too late (w249: raceeditor served 8× from the wrong
      // guessed 0x60000). Offsets verified stable in w231/w245/w249 (record +24)
      // and match the offline RSC5 read at xarchive_cache.rpf+off. Unmapped path
      // leaves s_pendingUiPkg=0 → AssignPackageForDest falls to prior behavior.
      {
        const uint32_t pk = MclaUiXsfPkgForPath(pathName);
        s_pendingUiPkg.store(pk);  // 0 = none (safe)
        MCLA_LOG_WARN("PATHB-PKGPEND #{} path='{}' pending_pkg={:08X}", n,
                      pathName, pk);
      }
      f.lr = 0x821FE6ECu;   // a real FDD50 caller's return address
      __imp__sub_821FDD50(f, base);
      // F-357: enqueue the SAME container more than once when it is bigger than one
      // destination chain. `w351`'s PATHB-REC dump shows why this is the right knob:
      // each container gets a data record carrying its FULL length
      // (`+4=00104449` = 1,066,057 for the garage, `+24=64980000`) plus a consumer
      // record at `+4=0`, so the streamer knows the size and allocates destination
      // lazily per request -- and F-354 measured that it stops after two requests
      // (262,144-393,216 B) because the consumer that would ask for more (GFx) never
      // runs. F-356 proved the record-marking is not the limiter. One enqueue call
      // per pass is the guest's OWN descriptor construction (`sub_821FDD50` also runs
      // the record build + inflate synchronously, F-251), so the hope was that each
      // pass yields a fresh record, a fresh destination chain, and a fresh `kUiDecTry`
      // for the F-350 chunked fill to place the NEXT chunk of the body into.
      {
        const uint32_t pkEnq = MclaUiXsfPkgForPath(pathName);
        const uint32_t uncEnq = pkEnq != 0u ? MclaUiXsfUnc(pkEnq) : 0u;
        uint32_t passes = 1u;
        if (kUiXsfMultiEnqueue && uncEnq > 0x40000u) {
          passes = (uncEnq + 0x3FFFFu) / 0x40000u;  // ~256 KiB of dest per pass
          if (passes > 6u)
            passes = 6u;
        }
        // F-357b: the PRIMARY call stores its destination in `outSlot` (w351 garage
        // `PATHB2 #2 … out=[B7AC1000 00000000]`), so a repeat must never share it. w352
        // zeroed it once per pass and left it 0, which is what made
        // `PATHB-PKGFIX-SKIP … dest=00000000` appear for the first time in the project and
        // let the streamer re-drive one destination 238,672 times (11 in w351). Read the
        // primary handle for the record, then give every repeat its own slot.
        uint32_t primH = 0;
        (void)mem.ReadU32BE(outSlot, &primH);
        for (uint32_t p = 1u; p < passes; ++p) {
          const uint32_t slotX = mem.Alloc(8, 16);
          if (!slotX)
            break;
          (void)mem.WriteU32BE(slotX, 0);
          (void)mem.WriteU32BE(slotX + 4, 0);
          s_pendingUiPkg.store(pkEnq);
          PPCContext g = f;  // same args, same calling convention, new request
          g.r3.u64 = slotX;
          __imp__sub_821FDD50(g, base);
          s_pendingUiPkg.store(0);
          uint32_t h0 = 0, h1 = 0;
          (void)mem.ReadU32BE(slotX, &h0);
          (void)mem.ReadU32BE(slotX + 4, &h1);
          MCLA_LOG_WARN("PATHB-ENQ-EXTRA #{} pass={} pkg={:08X} unc={} "
                        "prim={:08X} ret={:08X} out=[{:08X} {:08X}]",
                        n, p, pkEnq, uncEnq, primH, g.r3.u32, h0, h1);
        }
      }
      // F-251: if FDD50's internal inflate didn't consume the pending pkg
      // (dest already mapped, etc.), drop it so it can't leak to a later dest.
      s_pendingUiPkg.store(0);
      uint32_t o0 = 0, o1 = 0;
      (void)mem.ReadU32BE(outSlot, &o0);
      (void)mem.ReadU32BE(outSlot + 4, &o1);
      MCLA_LOG_WARN("PATHB2 #{} path='{}' handle={:08X} -> FDD50 ret={:08X} "
                    "out=[{:08X} {:08X}] arg0used={:08X}",
                    n, pathName, handle, f.r3.u32, o0, o1, (uint32_t)f.r4.u32);
      // F-361: separate "the UI-load callback was never registered" from "registered and
      // never dispatched". F-360 traced the registration: sub_82131508+0xec builds
      // {0, fn, ?, 0, 1} via sub_821C2FD8 and sub_82305690 copies those 5 dwords into
      // [0x8288B9E8]+88, so the callback pointer must sit at obj+92. This site runs after
      // boot init, so a read here is a late, independent check. Reads only.
      {
        uint32_t bootObj = 0;
        if (mem.ReadU32BE(0x8288B9E8u, &bootObj) && bootObj >= 0x80000000u &&
            bootObj < 0xE0000000u) {
          uint32_t d[5] = {0, 0, 0, 0, 0};
          for (int k = 0; k < 5; ++k)
            (void)mem.ReadU32BE(bootObj + 88u + 4u * static_cast<uint32_t>(k), &d[k]);
          static std::atomic<uint32_t> s_f361{0};
          const uint32_t f1 = s_f361.fetch_add(1) + 1;
          if (f1 <= 4)  // prints the FIRST 4, so any count <=4 is complete (F-317)
            MCLA_LOG_WARN("F361-BOOTOBJ #{} obj={:08X} desc[+88..+104]={:08X} {:08X} "
                          "{:08X} {:08X} {:08X} want+92=82131008 got+92={:08X}",
                          f1, bootObj, d[0], d[1], d[2], d[3], d[4], d[1]);
        } else {
          static std::atomic<uint32_t> s_f361bad{0};
          if (s_f361bad.fetch_add(1) + 1 <= 4)
            MCLA_LOG_WARN("F361-BOOTOBJ [0x8288B9E8]={:08X} not a guest pointer", bootObj);
        }
      }
      // F-198 read-only diagnostic: dump the streamer RECORD for the enqueued
      // handle to see if record[+4] (remaining length) is 0 AT enqueue (=> Path B
      // built a bad/zero-length record) or non-zero (=> zeroed later by the
      // executor/re-point = F-181). Record array base = [[0x8283D190+52]];
      // 28-byte record at base + (id&0x7FFF)*28; layout {+0 id|gen, +4 remain,
      // +8 dev, +12 state, +16 pkgid, +20 entryoff, +24 pkgoff} (F-180).
      uint32_t recBase = 0;
      uint32_t pbPkgOff = 0;  // F-247: this container's real archive offset (record +24)
      if (mem.ReadU32BE(0x8283D190u + 52u, &recBase) &&
          recBase >= 0x80000000u && recBase < 0xE0000000u) {
        for (uint32_t h = 0; h < 12u; ++h) {
          const uint32_t rec = recBase + (h & 0x7FFFu) * 28u;
          uint32_t w0 = 0, w4 = 0, w8 = 0, w12 = 0, w16 = 0, w20 = 0, w24 = 0;
          (void)mem.ReadU32BE(rec + 0, &w0);
          (void)mem.ReadU32BE(rec + 4, &w4);
          (void)mem.ReadU32BE(rec + 8, &w8);
          (void)mem.ReadU32BE(rec + 12, &w12);
          (void)mem.ReadU32BE(rec + 16, &w16);
          (void)mem.ReadU32BE(rec + 20, &w20);
          (void)mem.ReadU32BE(rec + 24, &w24);
          if (h == (handle & 0x7FFFu))
            pbPkgOff = w24;
          if (w4 != 0 || w8 != 0 || w24 != 0)
            MCLA_LOG_WARN("PATHB-REC #{} id={} rec={:08X} w0={:08X} +4={:08X} "
                          "+8={:08X} +12={:08X} +16={:08X} +20={:08X} "
                          "+24={:08X}{}",
                          n, h, rec, w0, w4, w8, w12, w16, w20, w24,
                          (h == (handle & 0x7FFFu)) ? " <==ENQ" : "");
        }
      }
      // F-247 SERVE-FRAMING FIX (authorized route 1; gated by kPathBEnqueueUI so
      // flag-OFF == the exact baseline, no meshtexture regression). Root cause:
      // AssignPackageForDest has no dest→pkgoff knowledge for the 4 UI containers
      // (they are NOT in the IsJob2UiDest list) so it falls to a "first unclaimed
      // g_rscTab entry" guess — w231 proved it serves the WRONG package (DEST-PKG
      // outPtr=B7B01000 -> off=00060000 = meshtextures, not raceeditor's real
      // 0x64CB0000). The guest inflate then reads non-XCompress bytes and the
      // LastServe re-point re-serves the meshtexture bounce (CAB28300) forever
      // (the F-244 livelock). Pre-empt the guess by registering this container's
      // TRUE archive offset (its streamer record +24) keyed to the FDD50 dest base
      // (o0), so AssignPackageForDest returns it and MclaForceServePkgForDest reads
      // the real RSC5/XCompress head (verified offline at that file offset).
      {
        const uint32_t uiDest = o0;  // FDD50 wrote the load-buffer base = inflate outPtr
        if (uiDest >= 0xB0000000u && uiDest < 0xC0000000u &&
            pbPkgOff >= 0x1000u && pbPkgOff < 0x80000000u) {
          std::lock_guard<std::mutex> lk(g_destPkgMtx);
          g_destPkgOff[uiDest] = pbPkgOff;
          g_destPkgWalk[uiDest] = 0;
          g_pkgUsed[pbPkgOff] = uiDest;
          MCLA_LOG_WARN("PATHB-PKGFIX #{} path='{}' dest={:08X} -> off={:08X} "
                        "(pre-empted AssignPackageForDest guess)",
                        n, pathName, uiDest, pbPkgOff);
        } else {
          MCLA_LOG_WARN("PATHB-PKGFIX-SKIP #{} path='{}' dest={:08X} off={:08X} "
                        "(implausible)",
                        n, pathName, uiDest, pbPkgOff);
        }
      }
    } else {
      MCLA_LOG_WARN("PATHB2-SKIP #{} alloc failed stack={:08X} out={:08X}", n,
                    s_pb2Stack, outSlot);
    }
  }
}

// F-218 read-only census: sub_821EBCF0 is the function that reads/writes the GFx
// {handler,kernelHandle} dispatch table at 0x82117828 (ctor sub_824C6F08 -> handle
// 0x40001905, movie sub_824C6F70 -> 0x40003D03). F-217 showed the whole GFx data
// path (LoadBytes/construct/loaders) is 0 in baseline, so the loader object is
// never constructed. This census decides whether the table DISPATCHER sub_821EBCF0
// ever RUNS — if 0 (with this hook as the positive control), the GFx handler
// dispatch never executes → the terminal gate for nGfx. Log-only, no state write.
PPC_FUNC_IMPL(__imp__sub_821EBCF0);
static std::atomic<uint32_t> s_hEBCF0{0};
PPC_FUNC(sub_821EBCF0) {
  const uint32_t n = s_hEBCF0.fetch_add(1) + 1;
  if (n <= 8 || (n % 500) == 0)
    MCLA_LOG_WARN("GFX-TABLE-DISP sub_821EBCF0 #{} r3={:08X} r4={:08X} "
                  "r10={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r10.u32,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821EBCF0(ctx, base);
}

// F-219 read-only census: the 4 direct callers of sub_821EBCF0 (per
// ppc_xrefs calls). If sub_821EBCF0 fired 0x (F-218) because NONE of these
// ever runs, the GFx-table dispatch is cold from its entry set and the trace
// escalates to the producer (needs IDA). If any DOES run, we found the live
// GFx-init entry. Log-only, positive control = these are distinct hooks that
// will fire if their function is entered.
static std::atomic<uint32_t> s_hE7420{0}, s_hF5AA0{0}, s_h69F8C0{0}, s_h69FCC8{0};
PPC_FUNC_IMPL(__imp__sub_821E7420);
PPC_FUNC(sub_821E7420) {
  const uint32_t n = s_hE7420.fetch_add(1) + 1;
  if (n <= 6) MCLA_LOG_WARN("GFXDISP-CALLER 821E7420 #{} r3={:08X} lr={:08X}",
                             n, ctx.r3.u32, (uint32_t)ctx.lr);
  __imp__sub_821E7420(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_821F5AA0);
PPC_FUNC(sub_821F5AA0) {
  const uint32_t n = s_hF5AA0.fetch_add(1) + 1;
  if (n <= 6) MCLA_LOG_WARN("GFXDISP-CALLER 821F5AA0 #{} r3={:08X} lr={:08X}",
                            n, ctx.r3.u32, (uint32_t)ctx.lr);
  __imp__sub_821F5AA0(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_8269F8C0);
PPC_FUNC(sub_8269F8C0) {
  const uint32_t n = s_h69F8C0.fetch_add(1) + 1;
  if (n <= 6) MCLA_LOG_WARN("GFXDISP-CALLER 8269F8C0 #{} r3={:08X} lr={:08X}",
                            n, ctx.r3.u32, (uint32_t)ctx.lr);
  __imp__sub_8269F8C0(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_8269FCC8);
PPC_FUNC(sub_8269FCC8) {
  const uint32_t n = s_h69FCC8.fetch_add(1) + 1;
  if (n <= 6) MCLA_LOG_WARN("GFXDISP-CALLER 8269FCC8 #{} r3={:08X} lr={:08X}",
                            n, ctx.r3.u32, (uint32_t)ctx.lr);
  __imp__sub_8269FCC8(ctx, base);
}

// Session 75o: async-request wrapper census + dispatcher hunt. Boot loads
// arrive here via message 0x40003803 (table entry 0x821071B0). Walk the
// stack (both LR-slot conventions) to identify the message dispatcher.
PPC_FUNC_IMPL(__imp__sub_821E5FD0);
static std::atomic<uint32_t> s_h5FD0{0};
PPC_FUNC(sub_821E5FD0) {
  const uint32_t n = s_h5FD0.fetch_add(1) + 1;
  if (n <= 12 || (n % 200) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    char chain[160] = {0};
    size_t off = 0;
    uint32_t sp = ctx.r1.u32;
    for (int f = 0; f < 6 && sp != 0 && off + 16 < sizeof(chain); ++f) {
      uint32_t back = 0, lrA = 0, lrB = 0;
      if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
      (void)mem.ReadU32BE(back - 8, &lrA);
      (void)mem.ReadU32BE(back + 4, &lrB);
      off += static_cast<size_t>(snprintf(chain + off, sizeof(chain) - off,
                                          " f%d=%08X/%08X", f, lrA, lrB));
      sp = back;
    }
    MCLA_LOG_INFO("ASYNC-REQ sub_821E5FD0 #{} a0={:08X} a1={:08X} "
                  "a2={:08X} a3={:08X} lr={:08X} chain[{}]",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr), chain);
  }
  __imp__sub_821E5FD0(ctx, base);
}

// ===========================================================================
// T41.3 census (2026-09-20): the last surviving C0000005 is a null
// SINGLETON, not a null gate argument.
//   sub_823045E0 (msg-handler table entry 0x8210DED8, msg 0x40000B03) does
//     lis r11,-32120; lwz r3,-7572(r11); bl 0x822f3bd8
//   so `this` for sub_822F3BD8 is guest [0x8287E26C] (ppc_recomp.50.cpp:6059-6063).
//   The ONLY writer of that word in the whole image is sub_822F38C0
//   (ppc_recomp.48.cpp:27313 stw r3,-7572(r11)), which is itself a table entry
//   (0x8210DA98, msg 0x40001503) and allocates 14720 B via sub_82130528.
// Log-only, every hook chains to __imp__: which of the chain runs, and from
// whom. Nothing here changes behaviour (rule 1, do-not #9).
// ===========================================================================
static void LogMsgChain(const char *tag, uint32_t n, uint32_t a0,
                        const PPCContext &c) {
  if (n > 16 && (n % 200) != 0) return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  char chain[128] = {0};
  size_t off = 0;
  uint32_t sp = c.r1.u32;
  for (int f = 0; f < 5 && sp != 0 && off + 16 < sizeof(chain); ++f) {
    uint32_t back = 0, lrA = 0, lrB = 0;
    if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
    (void)mem.ReadU32BE(back - 8, &lrA);
    (void)mem.ReadU32BE(back + 4, &lrB);
    off += static_cast<size_t>(snprintf(chain + off, sizeof(chain) - off,
                                        " f%d=%08X/%08X", f, lrA, lrB));
    sp = back;
  }
  uint32_t sing = 0;
  (void)mem.ReadU32BE(0x8287E26Cu, &sing);
  MCLA_LOG_WARN("MSGCHAIN {} #{} a0={:08X} [8287E26C]={:08X} lr={:08X} chain[{}]",
                tag, n, a0, sing, static_cast<uint32_t>(c.lr), chain);
}

PPC_FUNC_IMPL(__imp__sub_822F38C0);
static std::atomic<uint32_t> s_hF38C0{0};
PPC_FUNC(sub_822F38C0) {
  const uint32_t n = s_hF38C0.fetch_add(1) + 1;
  LogMsgChain("creator-822F38C0", n, ctx.r3.u32, ctx);
  __imp__sub_822F38C0(ctx, base);
  uint32_t pub = 0;
  (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(0x8287E26Cu, &pub);
  MCLA_LOG_WARN("MSGCHAIN creator-822F38C0 #{} RET [8287E26C]={:08X}", n, pub);
}

PPC_FUNC_IMPL(__imp__sub_823045E0);
static std::atomic<uint32_t> s_h045E0{0};
PPC_FUNC(sub_823045E0) {
  LogMsgChain("consumer-823045E0", s_h045E0.fetch_add(1) + 1, ctx.r3.u32, ctx);
  __imp__sub_823045E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822F3BD8);
static std::atomic<uint32_t> s_hF3BD8{0};
PPC_FUNC(sub_822F3BD8) {
  // The faulting frame: r3 on entry is the `this` F-056's store dereferences.
  LogMsgChain("faulting-822F3BD8", s_hF3BD8.fetch_add(1) + 1, ctx.r3.u32, ctx);
  __imp__sub_822F3BD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823047D8);
static std::atomic<uint32_t> s_h047D8{0};
PPC_FUNC(sub_823047D8) {
  LogMsgChain("init-823047D8", s_h047D8.fetch_add(1) + 1, ctx.r3.u32, ctx);
  __imp__sub_823047D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822C2EA8);
static std::atomic<uint32_t> s_hC2EA8{0};
PPC_FUNC(sub_822C2EA8) {
  LogMsgChain("parent-822C2EA8", s_hC2EA8.fetch_add(1) + 1, ctx.r3.u32, ctx);
  __imp__sub_822C2EA8(ctx, base);
}

// T41.3 step 2 (w38n): sub_823047D8 is ENTERED (w38n.log:2650) but the factory
// census above never fires, and IDA shows the call at 0x8230490c is
// unconditional — so the bail is inside the first 30 instructions of that
// function (IDA lines 29-58). Hook every step in that window to bisect it.
// Log-only; each hook chains to __imp__ (rule 1, do-not #9). All seven were
// verified unowned by tools/addr_owners.py --check first (rule 4).
static void LogBisect(const char *tag, uint32_t n, const PPCContext &c) {
  if (n > 8) return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t mgr = 0, res = 0, sing = 0;
  (void)mem.ReadU32BE(0x82839F68u, &mgr);
  (void)mem.ReadU32BE(0x8287E064u, &res);
  (void)mem.ReadU32BE(0x8287E26Cu, &sing);
  MCLA_LOG_WARN(
      "MSGBISECT {} #{} r3={:08X} r4={:08X} [82839F68]={:08X} "
      "[8287E064]={:08X} [8287E26C]={:08X} lr={:08X}",
      tag, n, c.r3.u32, c.r4.u32, mgr, res, sing, static_cast<uint32_t>(c.lr));
}

#define MCLA_BISECT_HOOK(guest_fn, tag)                                     \
  PPC_FUNC_IMPL(__imp__##guest_fn);                                         \
  static std::atomic<uint32_t> s_h_##guest_fn{0};                           \
  PPC_FUNC(guest_fn) {                                                      \
    LogBisect(tag, s_h_##guest_fn.fetch_add(1) + 1, ctx);                    \
    __imp__##guest_fn(ctx, base);                                           \
  }

MCLA_BISECT_HOOK(sub_82182240, "1-82182240 register-cars")
MCLA_BISECT_HOOK(sub_8218A9E0, "2-8218A9E0 shader-dir")
MCLA_BISECT_HOOK(sub_821CA540, "3-821CA540 name-insert")
MCLA_BISECT_HOOK(sub_821C9A90, "4-821C9A90 lookup-or-create")
MCLA_BISECT_HOOK(sub_823074B0, "6-823074B0 a1p2-ctor")
MCLA_BISECT_HOOK(sub_822F96E0, "7-822F96E0 a1-before-factory")

// w38p: sub_823047D8 enters sub_822FBAF8 (the star_glow effect init, IDA
// 0x822fbb04..0x822fbd90: alloc 104 -> [0x8287E334], 3x sub_821B4838 render
// targets, then vtable+4 on [0x82839F68] with "star_glow") and none of the
// hooks after it ever fire — with the gate dispatch moved off this thread the
// factory at 0x82304910 is STILL unreached (w38p.log:6564
// GATE-WAIT [8287E26C]=00000000 after 5000 ms). So the question is now only
// whether FBAF8 returns. Log its exit.
PPC_FUNC_IMPL(__imp__sub_822FBAF8);
static std::atomic<uint32_t> s_hFBAF8{0};
PPC_FUNC(sub_822FBAF8) {
  const uint32_t n = s_hFBAF8.fetch_add(1) + 1;
  LogBisect("5-822FBAF8 star_glow-init", n, ctx);
  __imp__sub_822FBAF8(ctx, base);
  uint32_t glowObj = 0, glowRdr = 0, sing = 0;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  (void)mem.ReadU32BE(0x8287E318u, &glowObj);
  (void)mem.ReadU32BE(0x8287E334u, &glowRdr);
  (void)mem.ReadU32BE(0x8287E26Cu, &sing);
  MCLA_LOG_WARN("MSGBISECT 5-822FBAF8 RETURN #{} [8287E318]={:08X} "
                "[8287E334]={:08X} [8287E26C]={:08X}",
                n, glowObj, glowRdr, sing);
}

MCLA_BISECT_HOOK(sub_822F9FA8, "8-822F9FA8 e334-producer")
MCLA_BISECT_HOOK(sub_8218FE20, "9-8218FE20 fba-fmtor")
MCLA_BISECT_HOOK(sub_82187150, "10-82187150 e330-create")
MCLA_BISECT_HOOK(sub_821B4838, "11-821B4838 render-target")
MCLA_BISECT_HOOK(sub_82188CF8, "12-82188CF8 shader-obj-ctor")
MCLA_BISECT_HOOK(sub_8218A568, "13-8218A568 param-lookup")
MCLA_BISECT_HOOK(sub_8218B688, "14-8218B688 technique-lookup")
#undef MCLA_BISECT_HOOK

// w38q: sub_822FBAF8 enters, our FIX-821873E8 substitution answers its
// 0x822FBC24 call (lr=822FBC28), and the function never returns (F-061). The
// next step it takes is through the vtable of the object THIS hook hands back,
// so print what that object actually looks like on the way out.
static void LogFabricatedShader(const char *tag, uint32_t obj) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t vt = 0, s4 = 0, s8 = 0, s12 = 0;
  if (obj) {
    (void)mem.ReadU32BE(obj + 0, &vt);
    if (vt) {
      (void)mem.ReadU32BE(vt + 4, &s4);
      (void)mem.ReadU32BE(vt + 8, &s8);
      (void)mem.ReadU32BE(vt + 12, &s12);
    }
  }
  MCLA_LOG_WARN("{} obj={:08X} vt={:08X} vt+4={:08X} vt+8={:08X} vt+12={:08X}",
                tag, obj, vt, s4, s8, s12);
}

// Session 75p: IO-credit census. The streamer refill waits while
// [0x82757500] <= 0 (Sleep 100ms) before issuing its virtual read â€” an
// async-IO credit/deepth limit. These two TU45 functions are the credit
// consumers/producers; log them to see whether credits ever flow.
PPC_FUNC_IMPL(__imp__sub_822CBE30);
static std::atomic<uint32_t> s_hCBE30{0};
PPC_FUNC(sub_822CBE30) {
  const uint32_t n = s_hCBE30.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0)
    MCLA_LOG_INFO("IOCRED-A sub_822CBE30 #{} a0={:08X} a1={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822CBE30(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822CC5E0);
static std::atomic<uint32_t> s_hCC5E0{0};
PPC_FUNC(sub_822CC5E0) {
  const uint32_t n = s_hCC5E0.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0)
    MCLA_LOG_INFO("IOCRED-B sub_822CC5E0 #{} a0={:08X} a1={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822CC5E0(ctx, base);
}

// Session 75r: page/descriptor lookup census. The executor calls
// vtable+8 = sub_821CC570(obj, join+24, &out) per request; returns -1 when
// the vtable+144 find fails (suspected batch-2 stall point).
PPC_FUNC_IMPL(__imp__sub_821CC570);
static std::atomic<uint32_t> s_hCC570{0};
PPC_FUNC(sub_821CC570) {
  const uint32_t n = s_hCC570.fetch_add(1) + 1;
  __imp__sub_821CC570(ctx, base);
  if (n <= 32 || (n % 200) == 0)
    MCLA_LOG_WARN("PGLOOKUP sub_821CC570 #{} obj={:08X} key={:08X} "
                  "out={:08X} -> ret={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r3.u32,
                  static_cast<uint32_t>(ctx.lr));
}

// Session 75t / w19: packfile read-wrapper. vt+28 = sub_821CC6F0.
// Contract: inner=[obj+32]; inner->vt[28](inner, r4, [obj+24]+r5, dest, count).
// JOIN census: r5 matches TOC w2 with low byte cleared. When POSTOPEN-SERVE
// has a body for that TOC family, host-complete the read from the served
// guest-mem buffer so loaders/inflate consume real bytes (ret was always 0
// because count/page-cache miss — guest never saw the host-served body).
PPC_FUNC_IMPL(__imp__sub_821CC6F0);
static std::atomic<uint32_t> s_hCC6F0{0};
PPC_FUNC(sub_821CC6F0) {
  const uint32_t n = s_hCC6F0.fetch_add(1) + 1;
  const uint32_t r1in = ctx.r1.u32;
  const uint32_t r3 = ctx.r3.u32;
  const uint32_t r4 = ctx.r4.u32;
  const uint32_t r5 = ctx.r5.u32;
  const uint32_t r6 = ctx.r6.u32;
  const uint32_t r7 = ctx.r7.u32;
  const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  // F-186: sample streamer record[+4] (remaining bytes) on EVERY call, before
  // any conditional branch. Log only on change; cap 24 entries. The lr here
  // names whoever triggered the read that observed the new value.
  {
    static uint32_t s_lastRec4 = 0xFFFFFFFFu;
    static uint32_t s_rec4Logs = 0;
    uint32_t rbase = 0, rv4 = 0, rv12 = 0;
    if (mem.ReadU32BE(0x8283D1C4u, &rbase) && rbase >= 0x80000000u &&
        rbase != 0xCDCDCDCDu && rbase != 0xFFFFFFFFu) {
      const uint32_t rec = rbase + 4u * 28u;
      if (mem.ReadU32BE(rec + 4u, &rv4) && rv4 != s_lastRec4) {
        if (s_rec4Logs < 24) {
          s_rec4Logs++;
          (void)mem.ReadU32BE(rec + 12u, &rv12);
          MCLA_LOG_WARN("REC4-CHANGE #{} {} -> {} [+12]={:08X} lr={:08X}",
                        s_rec4Logs, s_lastRec4, rv4, rv12, lrIn);
        }
        s_lastRec4 = rv4;
      }
    }
  }

  uint32_t inner = 0, obj24 = 0, vt = 0, tocEntry = 0;
  if (r3 && r3 != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(r3, &vt);
    (void)mem.ReadU32BE(r3 + 24, &obj24);
    (void)mem.ReadU32BE(r3 + 32, &inner);
  }
  uint32_t r4w[4] = {0, 0, 0, 0};
  if (r4 && r4 != 0xCDCDCDCDu)
    for (int i = 0; i < 4; ++i)
      (void)mem.ReadU32BE(r4 + static_cast<uint32_t>(i * 4), &r4w[i]);
  uint32_t slots[4] = {0, 0, 0, 0};
  if (r3 && vt == 0x82012BDCu) {
    for (int s = 0; s < 4; ++s)
      (void)mem.ReadU32BE(r3 + 40u + static_cast<uint32_t>(s) * 68u,
                          &slots[s]);
  }

  MclaServedBody body{};
  const bool have =
      MclaFindServedBody(r3, 0xFFFFFFFFu, r5, 0, r5, &body) && body.buf &&
      body.size;
  if (have) {
    uint32_t want = r7;
    if (want == 0 || want > 0x40000u)
      want = (body.size < 0x8000u) ? body.size : 0x8000u;
    uint32_t pos = body.pos;
    if (pos > body.size)
      pos = 0;

    // w20: if the registered body head is zeros/AES, substitute a plaintext
    // RSC5+XCompress window from the host package table (0x60000 meshtextures
    // / 0xA0000 UI) so inflate/guest parse see real package bytes.
    uint32_t sbuf = body.buf;
    uint32_t ssize = body.size;
    uint32_t srcPkg = 0;
    std::vector<uint8_t> pkgWin;
    {
      uint32_t head = 0;
      (void)mem.ReadU32BE(body.buf + pos, &head);
      uint8_t hbuf[16] = {0};
      (void)mem.ReadBytes(body.buf + pos, hbuf, 16);
      const bool rscHead = MclaHeadIsRscOrXc(hbuf, 16);
      uint32_t pkgOff = MclaPreferredPkgOffForPath(body.path.c_str());
      if (pkgOff == 0)
        pkgOff = MclaPkgOffFromTocW2(body.w2);
      const bool isList =
          body.path.find(".list") != std::string::npos ||
          body.path.find("globaltex") != std::string::npos ||
          body.path.find("preload") != std::string::npos;
      if (!rscHead && pkgOff != 0 && !isList) {
        // Continuation walk for this path/dest, shared with inflate host-serve.
        uint32_t walk = 0;
        {
          std::lock_guard<std::mutex> wl(g_destPkgMtx);
          const uint32_t key = pkgOff ^ (r3 * 0x9E3779B9u);
          walk = g_destPkgWalk[key];
        }
        if (MclaLoadPkgWindow(pkgOff, walk, want ? want : 0x8000u, pkgWin) &&
            pkgWin.size() >= 16) {
          srcPkg = pkgOff;
          // Serve directly from the host vector via a guest-heap bounce buf.
          static std::mutex s_bounceMtx;
          static std::unordered_map<uint32_t, uint32_t> s_bounce; // pkg→buf
          uint32_t bounce = 0;
          {
            std::lock_guard<std::mutex> bl(s_bounceMtx);
            bounce = s_bounce[pkgOff];
            if (bounce == 0) {
              bounce = mem.Alloc(0x8000, 16);
              s_bounce[pkgOff] = bounce;
            }
          }
          if (bounce) {
            (void)mem.WriteBytes(bounce, pkgWin.data(),
                                 static_cast<uint32_t>(pkgWin.size()));
            sbuf = bounce;
            ssize = static_cast<uint32_t>(pkgWin.size());
            pos = 0;
            {
              std::lock_guard<std::mutex> wl(g_destPkgMtx);
              const uint32_t key = pkgOff ^ (r3 * 0x9E3779B9u);
              g_destPkgWalk[key] = walk + static_cast<uint32_t>(pkgWin.size());
            }
            MCLA_LOG_WARN("CC6F0-PKGSUBST #{} path='{}' bodyHead={:08X} "
                          "pkg={:08X} bounce={:08X} n={} walk={:08X}",
                          n, body.path, head, pkgOff, bounce,
                          pkgWin.size(), walk);
          }
        }
      } else if ((pos >= body.size || body.size - pos < 16) && pkgOff != 0 &&
                 !isList) {
        // Registered package body exhausted — pull the next plaintext window.
        uint32_t walk = 0;
        {
          std::lock_guard<std::mutex> wl(g_destPkgMtx);
          const uint32_t key = pkgOff ^ (r3 * 0x9E3779B9u);
          walk = g_destPkgWalk[key];
        }
        if (MclaLoadPkgWindow(pkgOff, walk, want ? want : 0x8000u, pkgWin) &&
            pkgWin.size() >= 16) {
          srcPkg = pkgOff;
          static std::mutex s_bounceMtx;
          static std::unordered_map<uint32_t, uint32_t> s_bounce;
          uint32_t bounce = 0;
          {
            std::lock_guard<std::mutex> bl(s_bounceMtx);
            bounce = s_bounce[pkgOff];
            if (bounce == 0) {
              bounce = mem.Alloc(0x8000, 16);
              s_bounce[pkgOff] = bounce;
            }
          }
          if (bounce) {
            (void)mem.WriteBytes(bounce, pkgWin.data(),
                                 static_cast<uint32_t>(pkgWin.size()));
            sbuf = bounce;
            ssize = static_cast<uint32_t>(pkgWin.size());
            pos = 0;
            {
              std::lock_guard<std::mutex> wl(g_destPkgMtx);
              const uint32_t key = pkgOff ^ (r3 * 0x9E3779B9u);
              g_destPkgWalk[key] = walk + static_cast<uint32_t>(pkgWin.size());
            }
            MCLA_LOG_WARN("CC6F0-PKGCONT #{} path='{}' pkg={:08X} n={} "
                          "walk={:08X}",
                          n, body.path, pkgOff, pkgWin.size(), walk);
          }
        }
      }
    }

    uint32_t avail = (pos < ssize) ? (ssize - pos) : 0;
    if (want > avail)
      want = avail;

    // Inflate stream state was observed at dest-0x20 (st=006D8F20, r6=...F40).
    const uint32_t stCand = (r6 > 0x20u) ? (r6 - 0x20u) : 0u;
    uint32_t st0 = 0, st4 = 0, st12 = 0, st16 = 0, st20 = 0;
    if (stCand && stCand != 0xCDCDCDCDu) {
      (void)mem.ReadU32BE(stCand + 0, &st0);
      (void)mem.ReadU32BE(stCand + 4, &st4);
      (void)mem.ReadU32BE(stCand + 12, &st12);
      (void)mem.ReadU32BE(stCand + 16, &st16);
      (void)mem.ReadU32BE(stCand + 20, &st20);
    }
    const bool stLooks =
        stCand && st16 != 0 && st16 != 0xCDCDCDCDu && st16 < 0x200000u;

    // Prime inflate-visible input fields to the served guest-heap body.
    if (stLooks && want != 0) {
      (void)mem.WriteU32BE(stCand + 0, want);
      (void)mem.WriteU32BE(stCand + 4, sbuf + pos);
      if (st12 == 0 || st12 == 0xCDCDCDCDu)
        (void)mem.WriteU32BE(stCand + 12, want);
    }

    // w20: copy served bytes into dest. Heap dest → full window.
    // Stack dest (006D8F40 family) → HEAD ONLY (256B). A 32KB write from
    // dest smashes the guest frame (r1≈006D8EC0, dest=r1+0x80) and the
    // inflate caller at 821BC380 never runs (w20 soak: INFLATE=0).
    // Inflate input is carried by st+0/st+4 → guest-heap sbuf, not dest.
    if (want != 0 && r6 != 0 && r6 != 0xCDCDCDCDu) {
      const bool heapDest = r6 >= 0xA0000000u;
      const uint32_t cap = heapDest ? want : ((want > 256u) ? 256u : want);
      uint8_t tmp[256];
      uint32_t done = 0;
      while (done < cap) {
        uint32_t chunk = cap - done;
        if (chunk > sizeof(tmp))
          chunk = static_cast<uint32_t>(sizeof(tmp));
        if (!mem.ReadBytes(sbuf + pos + done, tmp, chunk) ||
            !mem.WriteBytes(r6 + done, tmp, chunk))
          break;
        done += chunk;
      }
    }

    // w20: stamp the inner page-cache slots so the guest buffered reader
    // can also hit the served body (inner+296/336/356 family).
    uint32_t innerForPages = inner;
    if (innerForPages == 0 || innerForPages < 0xA0000000u)
      innerForPages = 0xA0083660u; // JOIN-census fallback
    MclaStampPageCache(innerForPages, pos, want, sbuf + pos, r3);

    // Record for inflate re-force after guest clobbers st to stack.
    {
      MclaLastServe ls;
      ls.sbuf = sbuf;
      ls.pos = pos;
      ls.size = ssize;
      ls.stCand = stLooks ? stCand : 0u;
      ls.dest = r6;
      ls.want = want;
      ls.srcPkg = srcPkg;
      ls.path = body.path;
      uint8_t h16[16] = {0};
      (void)mem.ReadBytes(sbuf + pos, h16, 16);
      ls.head = MclaBE(h16);
      MclaRecordLastServe(ls);
    }

    // Advance the shared served-body cursor only when we served the
    // registered body (not a package bounce).
    if (srcPkg == 0) {
      std::lock_guard<std::mutex> lk(g_servedMtx);
      for (auto &kv : g_servedByPath) {
        if (kv.second.buf == sbuf)
          kv.second.pos = pos + want;
      }
    }

    uint32_t destHead[2] = {0, 0};
    if (r6 && r6 != 0xCDCDCDCDu) {
      (void)mem.ReadU32BE(r6 + 0, &destHead[0]);
      (void)mem.ReadU32BE(r6 + 12, &destHead[1]); // guest inPtr = dest+12
    }
    uint32_t serveHead[2] = {0, 0};
    (void)mem.ReadU32BE(sbuf + pos, &serveHead[0]);
    if (ssize - pos >= 16)
      (void)mem.ReadU32BE(sbuf + pos + 12, &serveHead[1]);

    // w22 lever: guest inflate caller (loc_821BC2D4/374, lr=821BC334) does
    //   r31=min(32768,r30); Read(..., r7=r31); if (r3!=r31) short-read EXIT;
    //   else inLeft=r3-12, inPtr=stack+12, InflateStep(r24, state).
    // w21: r7=0 (r30 appeared 0) but we returned want=32768 → r3!=r31 →
    // short-read exit, guest NEVER called InflateStep for job2 B7* dests.
    // Return exactly r7. When r7==0 the guest takes the full-read path
    // (r3==r31==0) and enters InflateStep with inLeft=-12; our hook then
    // re-points st at LastServe bounce (RSC5/XC) and guest InflateStep runs.
    // Do NOT plant package bytes into B7* place dests (Resource fatal).
    const bool inflateRefill =
        (lrIn == 0x821BC334u || lrIn == 0x821BC484u);
    if (r7 == 0 && inflateRefill) {
      uint32_t credits = 0, abortFlag = 0;
      uint32_t jcount = 0, jentries = 0, jkey = 0, jsz = 0, jsrc = 0,
               jtagw = 0;
      (void)mem.ReadU32BE(0x827D74E0u, &credits);
      (void)mem.ReadU32BE(0x8286073Cu, &abortFlag);
      (void)mem.ReadU32BE(0x8283D1A8u, &jcount);
      (void)mem.ReadU32BE(0x8283D1C4u, &jentries);
      if (jentries && jcount) {
        const uint32_t mask = (jcount == 0) ? 0u : (jcount - 1u);
        // job2 tag 0x8004 & mask → idx; also dump idx=4 (both jobs collide)
        const uint32_t idx = 0x00008004u & mask;
        const uint32_t e = jentries + idx * 28u;
        (void)mem.ReadU32BE(e + 0, &jkey);
        (void)mem.ReadU32BE(e + 4, &jsz);
        (void)mem.ReadU32BE(e + 8, &jsrc);
        (void)mem.ReadU32BE(e + 16, &jtagw);
      }
      static std::atomic<uint32_t> s_r7z{0};
      const uint32_t zn = s_r7z.fetch_add(1) + 1;
      MCLA_LOG_WARN(
          "READWRAP-R7Z #{} path='{}' dest={:08X} st={:08X} r7={} lr={:08X} "
          "credits={:08X} abort={:08X} joinCnt={} idx4 key={:08X} "
          "jsz={:08X} jsrc={:08X} j16={:08X} (ret 0 → InflateStep)",
          zn, body.path, r6, stLooks ? stCand : 0u, r7, lrIn, credits,
          abortFlag, jcount, jkey, jsz, jsrc, jtagw);
      // Abort flag at 0x8286073C (lbz r9,1852(r27) in the inflate caller)
      // sends the post-Read path to loc_821BC3C0 BEFORE the r3==r31 check.
      // Clear it so the guest can reach InflateStep.
      if (abortFlag != 0)
        (void)mem.WriteU32BE(0x8286073Cu, 0);
      // Ensure IO credits stay positive (refill Sleep(100) gate).
      if (credits == 0)
        (void)mem.WriteU32BE(0x827D74E0u, 1);
      ctx.r3.u32 = 0;
      return;
    }
    MCLA_LOG_WARN("READWRAP-SERVE #{} path='{}' r3={:08X} r4={:08X} r5={:08X} "
                  "dest={:08X} r7={} want={} pos={}->{} sbuf={:08X} ssz={} "
                  "st={:08X} st16={:08X} pkg={:08X} "
                  "serveHead=[{:08X} {:08X}] destHead=[{:08X} {:08X}] "
                  "lr={:08X}",
                  n, body.path, r3, r4, r5, r6, r7, want, pos, pos + want,
                  sbuf, ssize, stLooks ? stCand : 0u, st16, srcPkg,
                  serveHead[0], serveHead[1], destHead[0], destHead[1], lrIn);
    // Return the guest's want (r7) so r3==r31 on the inflate refill path.
    ctx.r3.u32 = r7 ? r7 : want;
    return;
  }

  if (n <= 32 || (n % 200) == 0 || r7 == 0) {
    MCLA_LOG_WARN(
        "READWRAP sub_821CC6F0 #{} r3={:08X} vt={:08X} r4={:08X}[{:08X} "
        "{:08X} {:08X} {:08X}] r5={:08X} r6={:08X} r7={} inner={:08X} "
        "+24={:08X} slots=[{:08X} {:08X} {:08X} {:08X}] lr={:08X}",
        n, r3, vt, r4, r4w[0], r4w[1], r4w[2], r4w[3], r5, r6, r7, inner,
        obj24, slots[0], slots[1], slots[2], slots[3], lrIn);
  }
  __imp__sub_821CC6F0(ctx, base);
  const uint32_t ret = ctx.r3.u32;
  const bool saneIn = r1in < 0x82130000u;
  const bool saneOut = ctx.r1.u32 < 0x82130000u;
  if ((!saneIn || !saneOut) || n <= 8 || (n % 500) == 0 || ret == 0)
    MCLA_LOG_WARN("READWRAP sub_821CC6F0 #{} r3={:08X} r4={:08X} r5={:08X} "
                  "r6={:08X} r7={:08X} ret={:08X} r1in={:08X}{} "
                  "r1out={:08X}{} lr={:08X} tid={:08X}",
                  n, r3, r4, r5, r6, r7, ret, r1in, saneIn ? "" : "!",
                  ctx.r1.u32, saneOut ? "" : "!",
                  static_cast<uint32_t>(ctx.lr), GetCurrentThreadId());
}

// w19: packfile GetSize (vtable size-fetch family / BE8D8 vt+56 on the
// archive device). CD3C8: [dev+40+h*68]=tocEntry, return [tocEntry+4].
// When POSTOPEN-SERVE published the body, return that size even if the TOC
// word still holds the encrypted/packed length.
PPC_FUNC_IMPL(__imp__sub_821CD3C8);
static std::atomic<uint32_t> s_hCD3C8{0};
PPC_FUNC(sub_821CD3C8) {
  const uint32_t n = s_hCD3C8.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t h = ctx.r4.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t tocEntry = 0;
  if (dev && dev != 0xCDCDCDCDu && h < 16u)
    (void)mem.ReadU32BE(dev + 40u + h * 68u, &tocEntry);
  MclaServedBody body{};
  if (MclaFindServedBody(dev, h, 0, tocEntry, 0, &body) && body.size) {
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("CD3C8-SERVE #{} dev={:08X} h={} tocEntry={:08X} "
                    "path='{}' size={} lr={:08X}",
                    n, dev, h, tocEntry, body.path, body.size, lr);
    ctx.r3.u32 = body.size;
    return;
  }
  __imp__sub_821CD3C8(ctx, base);
  if (n <= 24 || (n % 200) == 0 || static_cast<int32_t>(ctx.r3.s32) < 0)
    MCLA_LOG_WARN("CD3C8 #{} dev={:08X} h={} tocEntry={:08X} ret={} lr={:08X}",
                  n, dev, h, tocEntry, ctx.r3.s32, lr);
}

// Session 75v: kernel read-submit census. sub_8244F4C0 is the kernel-layer
// read that produced the batch-1 NFS reads. If batch-2 never hits it, the
// fetch is never even attempted upstream.
PPC_FUNC_IMPL(__imp__sub_8244F4C0);
static std::atomic<uint32_t> s_hF4C0{0};
// Session 76a: completed-read tracking. Our NtReadFile finishes reads
// synchronously; record the destination buffers so SLOT-READY only marks
// slots whose buffer really received a completed read (a flip without a
// read serves garbage â€” the 0x7E780000 guest AV).
constexpr size_t kDoneBufCap = 64;
static std::atomic<uint32_t> g_doneBufs[kDoneBufCap];
static std::atomic<uint32_t> g_doneBufIdx{0};
static bool BufferReadDone(uint32_t buf) {
  for (size_t i = 0; i < kDoneBufCap; ++i)
    if (g_doneBufs[i].load(std::memory_order_acquire) == buf) return true;
  return false;
}
PPC_FUNC(sub_8244F4C0) {
  const uint32_t n = s_hF4C0.fetch_add(1) + 1;
  if (n <= 24 || (n % 200) == 0)
    MCLA_LOG_INFO("RD-SUBMIT sub_8244F4C0 #{} a0={:08X} a1={:08X} "
                  "a2={:08X} a3={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  // Capture BEFORE the call: sub_8244F4C0 moves r4/r5 into its own registers,
  // so post-call ctx.r4/r5 are clobbered (the project's own sticky-register
  // caveat, PROGRAM_GUIDE s8 -- a census that reads them after prints nothing).
  const uint32_t bufG = ctx.r4.u32, cntG = ctx.r5.u32, r6G = ctx.r6.u32,
                 r7G = ctx.r7.u32;
  // T41.3v (F-110): this is the first archive I/O the guest issues, so the list
  // spans must be known here — registering them later leaves already-pumped
  // pages holding DEFLATE bytes (see the table above).
  if (n == 1)
    MclaMarkKnownListMembers();
  __imp__sub_8244F4C0(ctx, base);
  if (ctx.r4.u32 != 0 && ctx.r4.u32 != 0xCDCDCDCDu) {
    const uint32_t idx = g_doneBufIdx.fetch_add(1) % kDoneBufCap;
    g_doneBufs[idx].store(ctx.r4.u32, std::memory_order_release);
  }
  // T41.3n (F-091), UNCAPPED read-only: the discriminator F-077's experiment
  // was missing. r4 = destination buffer, r5 = byte count, and NtReadFile
  // completes synchronously, so the bytes the guest now holds are the answer to
  // "did a *.list body decode to ASCII names, or is the payload opaque?".
  // Nothing in this project has ever printed a read buffer's CONTENT.
  {
    const uint32_t buf = bufG;
    const uint32_t cnt = cntG;
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    // No IsValid() gate: it validates the virtual heap only, and these buffers
    // live in the physical arena (0xC6...), so it returned false and the census
    // printed nothing -- the same blind-printer trap as F-089 s6. ReadBytes
    // itself reports whether the read worked, and the line prints either way.
    if (buf != 0 && buf != 0xCDCDCDCDu && cnt >= 0x10u) {
      char raw[17] = {0};
      const bool got = memR.ReadBytes(buf, raw, 16);
      uint32_t pr = 0, nz = 0;
      char vis[17] = {0};
      for (int k = 0; k < 16; ++k) {
        const unsigned char c = static_cast<unsigned char>(raw[k]);
        if (c) ++nz;
        if (c >= 0x20u && c < 0x7Fu) {
          ++pr;
          vis[k] = static_cast<char>(c);
        } else {
          vis[k] = '.';
        }
      }
      uint32_t pos = 0, posHi = 0, out = 0;
      (void)memR.ReadU32BE(r7G + 24u, &pos);
      (void)memR.ReadU32BE(r7G + 28u, &posHi);
      (void)memR.ReadU32BE(r6G, &out);
      MCLA_LOG_WARN("RD-BUF #{} h={:08X} buf={:08X} cnt={} read={} ascii={}/16 "
                    "nz={}/16 head=[{}] reqPos={:08X}_{:08X} out={:08X}",
                    n, ctx.r3.u32, buf, cnt, got ? 1 : 0, pr, nz, vis, posHi,
                    pos, out);
      // B2a (F-095 follow-on): one-shot dump of the guest's DECRYPTED archive
      // views so member names are enumerated from the guest's own answer, not
      // our on-disk parsing (F-090: src has no RPF TOC parser and must not
      // gain one for a verdict; disk names proven absent-encrypted 09-23).
      {
        static bool s_tocDumped = false;
        static bool s_earlyDumped = false;
        auto dumpOnce = [&](uint32_t wantBuf, uint32_t wantCnt, bool& flag,
                            const char* path) {
          if (flag || buf != wantBuf || cnt < wantCnt) return;
          flag = true;
          std::vector<uint8_t> tmp(wantCnt);
          bool okAll = true;
          for (uint32_t o = 0; o < wantCnt; o += 4096u) {
            const uint32_t piece = (wantCnt - o < 4096u) ? (wantCnt - o) : 4096u;
            if (!memR.ReadBytes(buf + o, reinterpret_cast<char*>(&tmp[o]), piece)) {
              okAll = false;
              MCLA_LOG_WARN("TOC-DUMP {} failed at +{} buf={:08X}", path, o, buf);
              break;
            }
          }
          if (!okAll) return;
          FILE* fp = nullptr;
          if (fopen_s(&fp, path, "wb") == 0 && fp != nullptr) {
            fwrite(tmp.data(), 1, wantCnt, fp);
            fclose(fp);
            MCLA_LOG_WARN("TOC-DUMP wrote {} bytes={} buf={:08X}", path, wantCnt, buf);
          } else {
            MCLA_LOG_WARN("TOC-DUMP {} open failed", path);
          }
        };
        dumpOnce(0xC60B7780u, 382976u, s_tocDumped, "toc_decrypted.bin");
        dumpOnce(0xC60ACE00u, 18432u, s_earlyDumped, "early_decrypted.bin");
      }
      // F-100 / rule 19: our own census reads are done, so arm the guard page on
      // the window just filled and let the NEXT accessor name itself. Physical
      // arena 0xC6xxxxxx holds the four archive page-cache buffers.
      //
      // ARMING RETIRED (F-106): B1's verdict was earned in F-101, and the witness
      // is now actively breaking I/O — PAGE_NOACCESS on a buffer that a host-side
      // ::ReadFile targets makes ReadFile FAIL with ERROR_NOACCESS (gle 998)
      // instead of raising the exception we handle, so any page the guest re-reads
      // fails forever (w76/w77/w79: 1339 retries at off=0x158000, ~800k log lines).
      // The instrument survives in src/boot_host.cpp for a future one-shot window;
      // it just no longer claims pages in the archive read path.
      constexpr bool kB1GuardArmFromReads = false;
      if (kB1GuardArmFromReads && got && cnt >= 0x100u &&
          (buf & 0xFF000000u) == 0xC6000000u) {
        mcla::boot::B1GuardArm(buf);
      }
    }
  }
}

// T41.3n2 S4b: pump attribution. Raw-byte decode recovered the two read-pump
// prologues (0x821C4F98, 0x821C5038) — they own every RD-SUBMIT lr seen for
// the *.list page reads; their own caller is the consumer that should branch
// to XMemDecompress. Log-only entry census with honest (pre-call) lr.
PPC_FUNC_IMPL(__imp__sub_821C4F98);
PPC_FUNC(sub_821C4F98) {
  static std::atomic<uint32_t> s_pump1{0};
  const uint32_t n = s_pump1.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (n <= 24)
    MCLA_LOG_WARN("T413N2-PUMP1 #{} r3={:08X} r4={:08X} r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr);
  __imp__sub_821C4F98(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_821C5038);
PPC_FUNC(sub_821C5038) {
  static std::atomic<uint32_t> s_pump2{0};
  const uint32_t n = s_pump2.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (n <= 24)
    MCLA_LOG_WARN("T413N2-PUMP2 #{} r3={:08X} r4={:08X} r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr);
  __imp__sub_821C5038(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821CC970);
PPC_FUNC(sub_821CC970) {
  // T41.3n2 S4b hop 3: the XDK window pager (page-loop, [TLS+52]-gated).
  // Its entry lr names the RAGE consumer that should branch to inflate.
  static std::atomic<uint32_t> s_pager{0};
  const uint32_t n = s_pager.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  uint32_t tls52 = 0;
  {
    auto &memP = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t tls = ctx.r13.u32;
    if (tls) (void)memP.ReadU32BE(tls + 52u, &tls52);
  }
  if (n <= 24)
    MCLA_LOG_WARN("T413N2-PAGER #{} r3={:08X} r4={:08X} r5={:08X} "
                  "[TLS+52]={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, tls52, lr);
  __imp__sub_821CC970(ctx, base);
}

// B2b (F-096 follow-on): device-claim census. sub_821CB650-0x821CB68C is the
// mount device loop: it asks each device's vtable[+4] (sub_821CDB88) about the
// path and STOPS at the first device whose answer leaves r4 != -1. Both
// a:/archive/ devices share the 11-char prefix, so a non -1 answer from the
// 2-entry d0 shadow hides the full-table d1 forever. Log dev+path at entry
// (pre-call, trap #1 honest) and the r3/r4 the loop actually branches on.
PPC_FUNC_IMPL(__imp__sub_821CDB88);
static std::atomic<uint32_t> s_hCDB88{0};
PPC_FUNC(sub_821CDB88) {
  const uint32_t n = s_hCDB88.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t pathPtr = ctx.r4.u32;
  char pbuf[96] = {0};
  if (pathPtr) {
    auto &memD = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t got = 0;
    for (uint32_t i = 0; i + 4 <= 96; i += 4) {
      uint32_t w = 0;
      if (!memD.ReadU32BE(pathPtr + i, &w)) break;
      const char* b = reinterpret_cast<const char*>(&w);
      for (int k = 3; k >= 0; --k) {
        if (!b[k]) { pbuf[got] = 0; got = 99; break; }
        pbuf[got++] = b[k];
      }
      if (got == 99) break;
    }
    if (got < 96) pbuf[95] = 0;
  }
  __imp__sub_821CDB88(ctx, base);
  // F-148: census-only predicate extension (this hook is a peer's; behaviour is
  // untouched). w158's DEVCLAIM stops at #96 / 12:25:15.136, 1.8 s before the
  // entity.type opens, so the one answer F-147 needs - whether the composed
  // a:/archive/vehicle/.../entity.type name ever reached a device's claim call -
  // is off-screen. Print those paths at any count.
  if (n <= 96 || std::strstr(pbuf, "entity") || std::strstr(pbuf, ".type"))
    MCLA_LOG_WARN("DEVCLAIM #{} dev={:08X} path='{}' -> r3={:08X} r4={:08X} lr={:08X}",
                  n, dev, pbuf, ctx.r3.u32, ctx.r4.u32,
                  static_cast<uint32_t>(ctx.lr));
}

// Session 75w: slot-ready fix. sub_821CBE18(slot) waits on the slot's
// event while [slot+12]==1 (read in flight). Our NtReadFile completes all
// reads synchronously with no event signal, so pending slots would block
// forever on data that is already in their buffers. Flip state 1â†’2 before
// the wait: the IO has in fact completed.
PPC_FUNC_IMPL(__imp__sub_821CBE18);
static std::atomic<uint32_t> s_hCBE18{0};
PPC_FUNC(sub_821CBE18) {
  const uint32_t n = s_hCBE18.fetch_add(1) + 1;
  const uint32_t slot = ctx.r3.u32;
  uint32_t state = 0;
  auto &memS = mcla::kernel::GuestMemoryHeap::Instance();
  if (slot != 0 && slot != 0xCDCDCDCDu) {
    (void)memS.ReadU32BE(slot + 12, &state);
    uint32_t buf = 0;
    memS.ReadU32BE(slot + 8, &buf);
    if (state == 1 && BufferReadDone(buf)) {
      (void)memS.WriteU32BE(slot + 12, 2);
      if (n <= 32 || (n % 500) == 0)
        MCLA_LOG_INFO("SLOT-READY sub_821CBE18 #{} slot={:08X} buf={:08X} "
                      "state 1->2 (read completed synchronously)",
                      n, slot, buf);
    }
  }
  __imp__sub_821CBE18(ctx, base);
}

// T41.3w (B3): the "[dev+12] error/media flags" word is the RPF3 TOC record's
// 4th dword, copied verbatim (w99/w100: dev=C60F7A40 flags=400000EC == the
// globaltex.list record [3D9B8154 0000023F 000D0000 400000EC]; 2dnoise3.dds
// C60F7AA0 == ...4001258B). Every record in the cache packfile has bit30 set,
// so bit30 cannot mean "this file errored". What the guest does with it (read
// the executed translation, NOT tools/ppc_disasm.py -- its mr/RA-RT order is
// inverted, see F-112): generated/ppc_xenon/ppc_recomp.17.cpp:3114 ff --
//   r31 = r4 (the read-request object), r30 = r3, r27 = r6 (length)
//   r11 = [r31+0] = the TOC record;  r10 = [r11+12]
//   if (r10 & 0x40000000) { if (!(r10 & 0x80000000)) -> 0x821CC234 block }
//   else -> 0x821CC224 with r10 = r25 = 0 -> normal
// so the block at 0x821CC234 runs iff bit30 set AND bit31 clear, and inside it
// the guest submits the real read through the device vtable (bctrl at
// 0x821CC2B8), waits on the IO block (bl 0x821DEE40 at 0x821CC2EC), and fatals
// with 'Fatal disc error' when THAT returns 1 (r29 = r3, cmpi r29,1 at
// 0x821CC2F8). i.e. bit30 = "bytes not resident yet, do a disc read",
// bit31 = "read completed". The missing step is the completion, not an ack.
// MITIGATION (labelled, NOT the mechanism): forcing bit31 claims the data is
// already resident and skips the guest's own read submission. Without it the
// boot dies 13k lines earlier (w100 vs w99: TOC76 232 vs 2079, GETDEV 100 vs
// 694), so the forced bit is load-bearing while the completion path is unfixed.
// The honest measurement of the missing step is DISCCHK2-RES below.
PPC_FUNC_IMPL(__imp__sub_821CC1E0);
static std::atomic<uint32_t> s_hCC1E0{0};
PPC_FUNC(sub_821CC1E0) {
  const uint32_t n = s_hCC1E0.fetch_add(1) + 1;
  const uint32_t strm = ctx.r4.u32;  // == the guest's r31 (generated mr r31,r4)
  {
    auto &memD = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t rec = 0, flags = 0, size = 0, offs = 0;
    memD.ReadU32BE(strm + 0, &rec);
    if (rec != 0 && rec != 0xCDCDCDCDu) {
      memD.ReadU32BE(rec + 12, &flags);
      if (n <= 40 || (n % 200) == 0) {
        (void)memD.ReadU32BE(rec + 4, &size);
        (void)memD.ReadU32BE(rec + 8, &offs);
        MCLA_LOG_WARN(
            "DISCCHK2 #{} strm={:08X} fobj={:08X} len={:X} rec={:08X} "
            "size={:X} offs={:X} flags={:08X} route={}",
            n, strm, ctx.r3.u32, ctx.r6.u32, rec, size, offs, flags,
            ((flags & 0x40000000u) && !(flags & 0x80000000u))
                ? "guest-disc-read"
                : "already-resident");
      }
      if ((flags & 0x40000000u) != 0 && (flags & 0x80000000u) == 0) {
        // MITIGATION, load-bearing: w101 (false) dies at 4,528 lines with
        // 'Fatal disc error' because the guest's own completion returns -3
        // (DISCCHK2-RES), and r3<0 is exactly its fatal condition; w99 (true)
        // reaches 17,868 lines. Cost: forcing bit31 tells the guest the bytes
        // are already resident, so its read submission (the bctrl at
        // 0x821CC2B8) never runs for ANY record -- every cache-packfile record
        // has bit30. Retiring this means making that path deliver.
        constexpr bool kDiscChkForcedAck = true;
        if (kDiscChkForcedAck)
          (void)memD.WriteU32BE(rec + 12, flags | 0x80000000u);
      }
    }
  }
  __imp__sub_821CC1E0(ctx, base);
}

// Session 76e: boot-init path census. sub_82187820(descriptor) runs in the
// boot task and reaches fiDevice::GetDevice(path) â€” the crash showed the
// path pointer itself = garbage (0xFF00FF00). Log the descriptor + the
// path string at entry to find which field is unwritten.
PPC_FUNC_IMPL(__imp__sub_82187820);
static std::atomic<uint32_t> s_h87820{0};
PPC_FUNC(sub_82187820) {
  const uint32_t n = s_h87820.fetch_add(1) + 1;
  if (n <= 8 || (n % 100) == 0) {
    auto &memP = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t f[6] = {0};
    for (int i = 0; i < 6; ++i)
      memP.ReadU32BE(ctx.r4.u32 + i * 4u, &f[i]);
    // F-102: r4 is NOT an array of pointers (w58 proved it: r4=82041D80 holds the
    // bytes "cars\0\0\0\0$/shaders" inline), so render the record as text instead
    // of dereferencing each word, and capture the call's outcome afterwards.
    char head[25] = {0};
    {
      unsigned char raw[24] = {0};
      if (ctx.r4.u32 >= 0x1000u && memP.ReadBytes(ctx.r4.u32, raw, 24)) {
        for (int i = 0; i < 24; ++i)
          head[i] = (raw[i] >= 32 && raw[i] < 127) ? (char)raw[i] : '.';
      }
    }
    MCLA_LOG_WARN("BOOTPATH sub_82187820 #{} r3={:08X} r4={:08X} "
                  "desc=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}] head='{}'",
                  n, ctx.r3.u32, ctx.r4.u32, f[0], f[1], f[2], f[3], f[4],
                  f[5], head);
  }
  const uint32_t preLr = static_cast<uint32_t>(ctx.lr);
  __imp__sub_82187820(ctx, base);
  // Post-call registers are the callee's (the sticky-register trap), but r3 is
  // exactly what the caller branches on: this is the per-group pass/fail bit.
  if (n <= 8)
    MCLA_LOG_WARN("BOOTPATH-RET #{} r3={:08X} r4={:08X} lr={:08X}", n, ctx.r3.u32,
                  ctx.r4.u32, preLr);
}

// F-104: `sub_82187820` (the per-group preload-list loader) is a LINE READER, not
// a binary parser — `bl 821CFAA8(r3=chunk src, r4=line buf, r5=128)` in a loop,
// three `bl 823DB730` token walks, `stb r24,0(r31)` NUL terminators, and
// `bl 82188E50(r3=r1+80)` handing over one line. So the retail `preload.list`
// bodies are TEXT, and this is the only way to see what the loader is handed:
// the first per-line text print in the project (T41.3n's unfinished question).
// In `w69`/`w70`/`w71` it fires exactly TWICE, both from the FATAL function
// (lr=82189234/82189248 inside sub_82189138) with 'embedded:/star_glow' and the
// bare name at 0x82040F0C — never from the loader, because its line loop is
// never entered (see F-104 for the stream-binding reason).
// CORRECTED by F-107/F-109: with the archive-level expansion in place the loader
// DOES enter its line loop and this prints 77 real names from
// shaders/city/preload.list. F-104's stream-binding reason is superseded (F-105).
PPC_FUNC_IMPL(__imp__sub_823DB730);
// T41.3u (F-109 follow-on) census, log-only. sub_823DB730 is a case-folding
// backward string scan (`addi -1`, `lbzu`, `ori 0x20` on A-Z, `subf` result) —
// i.e. the loader's per-line token/extension test, called twice at the loop head
// 0x82187928/0x8218793C where r3==0 selects whether 0x82187948..0x82187954 (NUL
// terminator + the line hand-over) run at all. Four of the five lists never
// reach the read, so print the operands and the result — filtered to calls from
// inside the loader, or this would swamp the log.
PPC_FUNC(sub_823DB730) {
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (lr < 0x82187820u || lr >= 0x82187A00u) {
    __imp__sub_823DB730(ctx, base);
    return;
  }
  static std::atomic<uint32_t> s_sc{0};
  const uint32_t n = s_sc.fetch_add(1) + 1;
  const uint32_t a3 = ctx.r3.u32, a4 = ctx.r4.u32;
  auto &memS = mcla::kernel::GuestMemoryHeap::Instance();
  auto peek = [&memS](uint32_t a, int back) {
    std::string s;
    if (a < 0x1000u || a == 0xCDCDCDCDu)
      return std::string("<bad>");
    const uint32_t at = a - static_cast<uint32_t>(back);
    unsigned char raw[32] = {0};
    if (!memS.ReadBytes(at, raw, 32))
      return std::string("<unread>");
    for (unsigned char c : raw)
      s += (c >= 32u && c < 127u) ? static_cast<char>(c) : (c ? '?' : '.');
    return s;
  };
  __imp__sub_823DB730(ctx, base);
  if (n <= 120)
    MCLA_LOG_WARN("DB730-LOADER #{} r3={:08X}['{}'] r4={:08X}['{}'@-24] "
                  "ret={:08X} lr={:08X}",
                  n, a3, peek(a3, 0), a4, peek(a4, 24), ctx.r3.u32, lr);
}

// T41.3u3 (F-109 follow-on), log-only: the loader's setup ends with
// `bl 821CA490` at 0x8218789C and takes `mr r31,r4` at 0x821878A8 — and r31 is
// what the line loop tests at 0x82187900 (`cmpli r31,0` → skip the NUL-terminate
// + hand-over at 0x82187948..0x82187954 for every chunk). In w90/w91 the ui/cars/
// effects groups read chunks yet never hand one over and never even reach the
// token compare, which says their r31 was 0. Print this call's argument and both
// returns, filtered to the loader's site.
PPC_FUNC_IMPL(__imp__sub_821CA490);
PPC_FUNC(sub_821CA490) {
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (lr != 0x821878A0u) {
    __imp__sub_821CA490(ctx, base);
    return;
  }
  static std::atomic<uint32_t> s_gs{0};
  const uint32_t n = s_gs.fetch_add(1) + 1;
  const uint32_t a3 = ctx.r3.u32;
  __imp__sub_821CA490(ctx, base);
  if (n <= 40)
    MCLA_LOG_WARN("A490-LOADER #{} self={:08X} -> r3={:08X} r4={:08X} r5={:08X} "
                  "(r4 is the loop gate)",
                  n, a3, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
}

// T41.3u2 (F-109 follow-on) census, log-only: the loader's per-line read is
// `bl 821CFAA8(r3 = stream obj at r1+208, r4 = line buf, r5 = 128)` at
// 0x82187964, and r3==0 exits the loop at 0x821878F0. Four of the five lists
// deliver plaintext bodies yet never produce a line, so dump the stream object
// and the return for reads issued from inside the loader.
PPC_FUNC_IMPL(__imp__sub_821CFAA8);
PPC_FUNC(sub_821CFAA8) {
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (lr < 0x82187820u || lr >= 0x82187A00u) {
    __imp__sub_821CFAA8(ctx, base);
    return;
  }
  static std::atomic<uint32_t> s_rd{0};
  const uint32_t n = s_rd.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32, dst = ctx.r4.u32, cnt = ctx.r5.u32;
  auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t f[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  for (int k = 0; k < 8; ++k)
    (void)memR.ReadU32BE(obj + k * 4u, &f[k]);
  // F-110 candidate test: word[3] is the stream wrapper (0x82860C40 family) and
  // word[5] looks like the memory-stream slot our MakeMemoryStream returned.
  // Dump that slot's {buf,size,pos,flag} (guest slot table @0x82860740, 16 B per
  // slot — kGuestSlotTable) so "the slot was consumed by the first of the two
  // opens" is answered by the soak instead of by argument.
  uint32_t s[4] = {0, 0, 0, 0};
  const uint32_t slotBase = 0x82860740u + (f[5] < 16u ? f[5] * 16u : 0u);
  for (int k = 0; k < 4; ++k)
    (void)memR.ReadU32BE(slotBase + k * 4u, &s[k]);
  uint32_t wdev = 0, whandle = 0;
  (void)memR.ReadU32BE(f[3], &wdev);
  (void)memR.ReadU32BE(f[3] + 4u, &whandle);
  // F-110: sub_821CFAA8 turns out NOT to be a stream reader — its own body
  // compares a char against 32/9/10/13/0, i.e. it splits the NEXT TOKEN out of
  // the caller's buffer (r1+80) and returns its length. So the dead groups'
  // question is simply what that buffer held; print it at entry.
  char bufvis[65] = {0};
  {
    unsigned char braw[64] = {0};
    if (dst && memR.ReadBytes(dst, braw, 64)) {
      for (int k = 0; k < 64; ++k) {
        const unsigned char c = braw[k];
        if (c == 0)
          break;
        bufvis[k] = (c >= 32u && c < 127u) ? static_cast<char>(c) : '?';
      }
    }
  }
  __imp__sub_821CFAA8(ctx, base);
  if (n <= 60 || (n % 100) == 0)
    MCLA_LOG_WARN("CFAA8-LOADER #{} obj={:08X} words=[{:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X}] dst={:08X} cnt={} "
                  "ret={:08X} lr={:08X} | wrap@{:08X}=[{:08X},{:08X}] "
                  "slot[{}]=[{:08X} {:08X} {:08X} {:08X}] buf='{}'",
                  n, obj, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], dst,
                  cnt, ctx.r3.u32, lr, f[3], wdev, whandle, f[5], s[0], s[1],
                  s[2], s[3], bufvis);
}

PPC_FUNC_IMPL(__imp__sub_82188E50);
PPC_FUNC(sub_82188E50) {
  static std::atomic<uint32_t> s_lineN{0};
  const uint32_t n = s_lineN.fetch_add(1) + 1;
  // F-107: the old `n <= 40` cap hid the real line count exactly when the
  // loader started reading names, so a 40-line print could not be told apart
  // from a 400-line one. Wide cap + a periodic marker to expose the total.
  if (n <= 600 || (n % 500) == 0) {
    auto &memL = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t buf = ctx.r3.u32;
    char text[129] = {0};
    bool got = false;
    if (buf >= 0x1000u && buf != 0xCDCDCDCDu) {
      unsigned char raw[128] = {0};
      got = memL.ReadBytes(buf, raw, 128);
      for (int i = 0; i < 128; ++i) {
        const unsigned char c = raw[i];
        if (c == 0) break;
        text[i] = (c >= 32 && c < 127) ? static_cast<char>(c) : '.';
      }
    }
    MCLA_LOG_WARN("LISTLINE sub_82188E50 #{} r3={:08X} r4={:08X} lr={:08X} "
                  "read={} text='{}'",
                  n, buf, ctx.r4.u32, static_cast<uint32_t>(ctx.lr), got ? 1 : 0,
                  text);
  }
  __imp__sub_82188E50(ctx, base);
}

// Session 76g: census of the 13 preload-list global users â€” which runs?
// (the global 0x827D7770 is never populated before the boot init reads it)
PPC_FUNC_IMPL(__imp__sub_8268A828);
static std::atomic<uint32_t> s_h8268A828{0};
PPC_FUNC(sub_8268A828) {
  const uint32_t n = s_h8268A828.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_8268A828 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_8268A828(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_826DB370);
static std::atomic<uint32_t> s_h826DB370{0};
PPC_FUNC(sub_826DB370) {
  const uint32_t n = s_h826DB370.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_826DB370 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_826DB370(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_8226D638);
static std::atomic<uint32_t> s_h8226D638{0};
PPC_FUNC(sub_8226D638) {
  const uint32_t n = s_h8226D638.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_8226D638 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_8226D638(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822C79A0);
static std::atomic<uint32_t> s_h822C79A0{0};
PPC_FUNC(sub_822C79A0) {
  const uint32_t n = s_h822C79A0.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822C79A0 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822C79A0(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822DA210);
static std::atomic<uint32_t> s_h822DA210{0};
PPC_FUNC(sub_822DA210) {
  const uint32_t n = s_h822DA210.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822DA210 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822DA210(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822DC388);
static std::atomic<uint32_t> s_h822DC388{0};
PPC_FUNC(sub_822DC388) {
  const uint32_t n = s_h822DC388.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822DC388 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822DC388(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822E9398);
static std::atomic<uint32_t> s_h822E9398{0};
PPC_FUNC(sub_822E9398) {
  const uint32_t n = s_h822E9398.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822E9398 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822E9398(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822ED628);
static std::atomic<uint32_t> s_h822ED628{0};
PPC_FUNC(sub_822ED628) {
  const uint32_t n = s_h822ED628.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822ED628 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822ED628(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822F8718);
static std::atomic<uint32_t> s_h822F8718{0};
PPC_FUNC(sub_822F8718) {
  const uint32_t n = s_h822F8718.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822F8718 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822F8718(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822F9268);
static std::atomic<uint32_t> s_h822F9268{0};
PPC_FUNC(sub_822F9268) {
  const uint32_t n = s_h822F9268.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822F9268 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822F9268(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_82300928);
static std::atomic<uint32_t> s_h82300928{0};
PPC_FUNC(sub_82300928) {
  const uint32_t n = s_h82300928.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_82300928 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82300928(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_82363990);
static std::atomic<uint32_t> s_h82363990{0};
PPC_FUNC(sub_82363990) {
  const uint32_t n = s_h82363990.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_82363990 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82363990(ctx, base);
}

// Session 76j: registry-state census at fiDevice::GetDevice entry.
// Registry header 0x82860844: {Device** array@+0, u16 count@+4, u16 capacity@+6}.
// Entry (276 bytes): name[262], flag@262, nameLen@264,
//   device vector {Device** arr@268, u16 cnt@272, u16 cap@274}.
PPC_FUNC_IMPL(__imp__sub_821CB488);
static std::atomic<uint32_t> s_hCB488{0};
PPC_FUNC(sub_821CB488) {
  const uint32_t n = s_hCB488.fetch_add(1) + 1;
  // Null/empty path (8C760 loads [obj+72] which can be 0 after stream
  // teardown). Returning 0 makes 8C760 do lwz from address 0. Return the
  // memory device so the vtable+88 no-op can run.
  if (ctx.r3.u32 == 0 || ctx.r3.u32 == 0xCDCDCDCDu) {
    if (n <= 40 || (n % 200) == 0)
      MCLA_LOG_WARN("GETDEV-NULL #{} lr={:08X} -> memory-dev", n,
                    static_cast<uint32_t>(ctx.lr));
    EnsureMemoryDeviceVtable();
    ctx.r3.u32 = kMemDeviceObj;
    return;
  }
  if (n <= 200 || (n % 100) == 0) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char path[68] = {0};
    memR.ReadBytes(ctx.r3.u32, path, 64);
    MclaSanitizePath(path, sizeof(path));
    if (path[0] == 0) {
      MCLA_LOG_WARN("GETDEV-EMPTY #{} lr={:08X}", n,
                    static_cast<uint32_t>(ctx.lr));
      ctx.r3.u32 = 0;
      return;
    }
    uint32_t arr = 0;
    uint16_t cnt = 0, cap = 0;
    memR.ReadU32BE(0x82860844u, &arr);
    memR.ReadU16BE(0x82860848u, &cnt);
    memR.ReadU16BE(0x8286084Au, &cap);
    uint32_t lockFlag = 0;
    (void)memR.ReadU32BE(0x82855A0Cu, &lockFlag);
    MCLA_LOG_WARN("GETDEV #{} path='{}' arr={:08X} cnt={} cap={} lockFlag={:08X}",
                  n, path, arr, cnt, cap, lockFlag);
    if (n <= 3) {
      // Session 76j: heap-arena layout dump. Default allocs route to
      // m_Allocators[1] = sysMemDualBuddyAllocator (sub_821C08F8 uses
      // [reg+(r6+1)*4]); if a buddy arena intersects the simple allocator's
      // registered pool range, the two allocators hand out the same bytes.
      auto dumpHeap = [&](const char *tag, uint32_t base) {
        uint32_t f0 = 0, f4 = 0, c76 = 0, f152 = 0, f248 = 0;
        (void)memR.ReadU32BE(base + 0u, &f0);
        (void)memR.ReadU32BE(base + 4u, &f4);
        (void)memR.ReadU32BE(base + 76u, &c76);
        (void)memR.ReadU32BE(base + 152u, &f152);
        (void)memR.ReadU32BE(base + 248u, &f248);
        MCLA_LOG_WARN("HEAP76 {} @{:08X} vt={:08X} +4={:08X} +76={:08X} "
                      "+152={:08X} +248={:08X}",
                      tag, base, f0, f4, c76, f152, f248);
      };
      dumpHeap("simple", 0x82830CD8u);
      dumpHeap("buddyA", 0x82830C10u);
      dumpHeap("buddyB", 0x82830B50u);
      dumpHeap("dual  ", 0x82830B40u);
    }
    for (uint32_t e = 0; arr != 0 && e < 2 && e <= cnt; ++e) {
      const uint32_t eb = arr + e * 276u;
      uint16_t flag = 0, len = 0, dcnt = 0, dcap = 0;
      uint32_t hold = 0, d0 = 0, d1 = 0, vt0 = 0, vt1 = 0;
      char name[17] = {0};
      memR.ReadBytes(eb, name, 16);
      MclaSanitizePath(name, sizeof(name));
      memR.ReadU16BE(eb + 262u, &flag);
      memR.ReadU16BE(eb + 264u, &len);
      memR.ReadU32BE(eb + 268u, &hold);
      memR.ReadU16BE(eb + 272u, &dcnt);
      memR.ReadU16BE(eb + 274u, &dcap);
      if (hold) {
        memR.ReadU32BE(hold, &d0);
        memR.ReadU32BE(hold + 4u, &d1);
        memR.ReadU32BE(d0, &vt0);
        memR.ReadU32BE(d1, &vt1);
      }
      uint32_t d0pfx = 0, d1pfx = 0;
      if (d0) (void)memR.ReadU32BE(d0 + 36u, &d0pfx);
      if (d1) (void)memR.ReadU32BE(d1 + 36u, &d1pfx);
      MCLA_LOG_WARN(
          "GETDEV-E{} [name='{}' flag={:x} len={} hold={:08X} dcnt={:04X} "
          "dcap={:04X} d0={:08X} vt0={:08X} pfx0={:08X} d1={:08X} vt1={:08X} "
          "pfx1={:08X}]",
          e, name, flag, len, hold, dcnt, dcap, d0, vt0, d0pfx, d1, vt1, d1pfx);
    }
  }
  const uint32_t pathG = ctx.r3.u32; // path arg, clobbered by the call
    EnsureMemoryDeviceVtable();
  __imp__sub_821CB488(ctx, base);
  if (n <= 80 || (n % 200) == 0) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char path[68] = {0};
    if (n <= 80 && pathG != 0 && pathG != 0xCDCDCDCDu) {
      (void)memR.ReadBytes(pathG, path, 64);
      MclaSanitizePath(path, sizeof(path));
    }
    const uint32_t ret = ctx.r3.u32;
    uint32_t vt = 0;
    if (ret != 0 && ret != 0xFFFFFFFFu)
      (void)memR.ReadU32BE(ret, &vt);
    MCLA_LOG_WARN("GETDEV-RET #{} path='{}' ret={:08X} vt={:08X}", n, path,
                  ret, vt);
  }
}

// Session 76j: fiDevice::Mount census â€” every device registration with its
// device pointer and vtable sanity (crash = garbage Device* in the holder).
PPC_FUNC_IMPL(__imp__sub_821CB9D8);
static std::atomic<uint32_t> s_hMnt{0};
PPC_FUNC(sub_821CB9D8) {
  const uint32_t n = s_hMnt.fetch_add(1) + 1;
  if (n <= 40) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char path[68] = {0};
    memR.ReadBytes(ctx.r3.u32, path, 64);
    MclaSanitizePath(path, sizeof(path));
    const uint32_t dev = ctx.r4.u32;
    uint32_t vt = 0;
    memR.ReadU32BE(dev, &vt);
    MCLA_LOG_WARN("MOUNT76 #{} path='{}' dev={:08X} vt={:08X} flag={:x} lr={:08X}",
                  n, path, dev, vt, ctx.r5.u32 & 0xFFu,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821CB9D8(ctx, base);
}

// Session 76j: the "embedded:" device method (sub_821CB070) â€” crash RIP was
// inside its inlined strrchr/strlen (AV at first uncommitted page below the
// scan). Log its args to separate garbage-device vs non-terminated string.
PPC_FUNC_IMPL(__imp__sub_821CB070);
static std::atomic<uint32_t> s_hCB070{0};
PPC_FUNC(sub_821CB070) {
  const uint32_t n = s_hCB070.fetch_add(1) + 1;
  if (n <= 12) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char p3[40] = {0}, p4[40] = {0};
    memR.ReadBytes(ctx.r3.u32, p3, 32);
    MclaSanitizePath(p3, sizeof(p3));
    memR.ReadBytes(ctx.r4.u32, p4, 32);
    MclaSanitizePath(p4, sizeof(p4));
    uint32_t vt = 0;
    (void)memR.ReadU32BE(ctx.r3.u32, &vt);
    MCLA_LOG_WARN("EMB76 #{} r3={:08X} [vt={:08X} s3='{}'] r4={:08X} s4='{}' lr={:08X}",
                  n, ctx.r3.u32, vt, p3, ctx.r4.u32, p4,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821CB070(ctx, base);
}

// Session 76j: packfile TOC lookup (vtable+144, sub_821CBFC0). Returns 0
// immediately when [obj+8]==0 â€” a phantom not-found here sends GetDevice to
// the NEXT device in the holder (the audlo packfile) whose state may be
// uninitialized â†’ the 0x7E780000 AV.
// PHASE1 T3: hang census. p0d1 ends with TOC76 #22 (lr=821CC44C) entered and
// no RET â€” dump TOC bounds + elapsed so a spin/corrupt-search is visible.
PPC_FUNC_IMPL(__imp__sub_821CBFC0);
static std::atomic<uint32_t> s_hTOC{0};
PPC_FUNC(sub_821CBFC0) {
  const uint32_t n = s_hTOC.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  const uint32_t pathPtr = ctx.r4.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
  char path[68] = {0};
  memR.ReadBytes(pathPtr, path, 64);
  MclaSanitizePath(path, sizeof(path));
  // T41.3m (F-089): the n<=80 window closed 1 ms before the star_glow lookups,
  // so the guest's own TOC answer for them was never printed. GetDevice
  // (sub_821CB488) reaches this function through the mount-prefix-stripping
  // thunk sub_821CDB88 (vtable 0x82012BDC slot+4), so the paths arriving here
  // are relative ("fxl_final/star_glow.fxc"). Log-only.
  const bool hot =
      (n <= 80) || (path[0] && (std::strstr(path, "policecam") != nullptr ||
                                std::strstr(path, "star_glow") != nullptr));
  uint32_t inner = 0, tStart = 0, tCount = 0, e0 = 0, e4 = 0, e8 = 0, e12 = 0;
  if (hot) {
    (void)memR.ReadU32BE(obj + 8u, &inner);
    if (inner) {
      (void)memR.ReadU32BE(inner + 8u, &tStart);
      (void)memR.ReadU32BE(inner + 12u, &tCount);
      (void)memR.ReadU32BE(inner + 0u, &e0);
      (void)memR.ReadU32BE(inner + 4u, &e4);
      (void)memR.ReadU32BE(inner + 16u, &e8);
      (void)memR.ReadU32BE(inner + 20u, &e12);
    }
    MCLA_LOG_WARN(
        "TOC76 #{} obj={:08X} inner={:08X} start={:08X} cnt={:08X} "
        "e0={:08X} e4={:08X} e8={:08X} e12={:08X} path='{}' lr={:08X}",
        n, obj, inner, tStart, tCount, e0, e4, e8, e12, path, lr);
    // B2c: d0's PARSED inner at query time (the fill-time copy is pre-parse).
    if (obj == 0xC60ABD08u && inner != 0 && path[0] &&
        std::strstr(path, "star_glow") != nullptr) {
      static bool s_d0Dumped = false;
      if (!s_d0Dumped) {
        s_d0Dumped = true;
        const uint32_t len = 18432u;
        std::vector<uint8_t> tmp(len);
        bool okAll = true;
        for (uint32_t o = 0; o < len; o += 4096u) {
          const uint32_t piece = (len - o < 4096u) ? (len - o) : 4096u;
          if (!memR.ReadBytes(inner + o, reinterpret_cast<char*>(&tmp[o]), piece)) {
            okAll = false;
            break;
          }
        }
        bool wrote = false;
        if (okAll) {
          FILE* fp = nullptr;
          if (fopen_s(&fp, "d0_parsed.bin", "wb") == 0 && fp != nullptr) {
            fwrite(tmp.data(), 1, len, fp);
            fclose(fp);
            wrote = true;
          }
        }
        MCLA_LOG_WARN("TOC-DUMP3 d0 wrote={} okread={} inner={:08X} path='{}'",
                      wrote ? 1 : 0, okAll ? 1 : 0, inner, path);
      }
    }
  }
  const auto t0 = std::chrono::steady_clock::now();
  __imp__sub_821CBFC0(ctx, base);
  if (hot) {
    const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::steady_clock::now() - t0)
                        .count();
    MCLA_LOG_WARN("TOC76-RET #{} ret={:08X} dt={}ms lr={:08X}", n, ctx.r3.u32,
                  ms, lr);
  }
  // w18: dump the decrypted TOC entry for ALL archive-content paths
  // (preload.list / globaltex.list included). This is the only place the
  // guest reveals data-offset/size (RPF TOC is AES-encrypted on disk).
  if (PathLooksLikeArchiveContent(path) && ctx.r3.u32 != 0 &&
      ctx.r3.u32 != 0xFFFFFFFFu && ctx.r3.u32 != 0xCDCDCDCDu) {
    uint32_t w[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; ++i)
      (void)memR.ReadU32BE(ctx.r3.u32 + static_cast<uint32_t>(i * 4), &w[i]);
    XsfTocCache(path, ctx.r3.u32, w);
    // T41.3p (F-105): tell the archive layer this member's span is one the
    // guest must see DEFLATE-expanded, using the size/offset the guest itself
    // published (w[1]=size, w[2]=offset; bit30 of the offset is our own
    // open-gate flag, so mask it off).
    //
    // kExpandListInArchive: OFF by default. With it ON (w76/w77) the guest
    // parses the expanded globaltex.list itself and opens all eight named
    // textures (2dnoise3/4, anisodir, billettanmap, cf_bump2, dmg_scrape,
    // no_damage, powerup_beam — each with its own TOC record), which proves the
    // transform and where it belongs; it then wedges in a page-retry loop on the
    // archive handle (NtReadFile off=0 repeated, ~263k submits) and never
    // reaches the star_glow fatal, so the soak is poisoned. The follow-on paging
    // is the open question, not the transform. See F-105.
    if (kExpandListInArchive && MclaListMemberPath(path) && w[1] >= 16u &&
        w[1] <= 0x100000u && (w[2] & 0x3FFFFFFFu) != 0) {
      mcla::vfs::MarkMemberExpanded(w[2] & 0x3FFFFFFFu, w[1]);
      MCLA_LOG_WARN("MEMBER-EXPAND-MARK path='{}' off={:08X} stored={}", path,
                    w[2] & 0x3FFFFFFFu, w[1]);
    }
    // Open gate (CCEA0): proceeds when bit 30 of [entry+8] is SET.
    const bool openGate = (w[2] & 0x40000000u) != 0;
    const bool allZero = (w[0] | w[1] | w[2] | w[3]) == 0;
    MCLA_LOG_WARN("TOC76-XSF #{} ret={:08X} path='{}' "
                  "[{:08X} {:08X} {:08X} {:08X}] openGateBit30={} zeros={} "
                  "lr={:08X}",
                  n, ctx.r3.u32, path, w[0], w[1], w[2], w[3],
                  openGate ? 1 : 0, allZero ? 1 : 0, lr);
    // B2a rev2 (F-095 lesson): the fill-time dump caught the table PRE-parse;
    // the live hashed entries exist only from query time on. One-shot dump of
    // the parsed region anchored on the entry array base the census itself
    // names (inner=C60B7780, TOC76 lines), triggered on the first real entry.
    {
      static bool s_parsedDumped = false;
      if (!s_parsedDumped && w[0] != 0) {
        s_parsedDumped = true;
        const uint32_t region = 0xC60B7780u, len = 382976u;
        std::vector<uint8_t> tmp(len);
        bool okAll = true;
        for (uint32_t o = 0; o < len; o += 4096u) {
          const uint32_t piece = (len - o < 4096u) ? (len - o) : 4096u;
          if (!memR.ReadBytes(region + o, reinterpret_cast<char*>(&tmp[o]), piece)) {
            okAll = false;
            break;
          }
        }
        bool wrote = false;
        if (okAll) {
          FILE* fp = nullptr;
          if (fopen_s(&fp, "toc_parsed.bin", "wb") == 0 && fp != nullptr) {
            fwrite(tmp.data(), 1, len, fp);
            fclose(fp);
            wrote = true;
          }
        }
        MCLA_LOG_WARN("TOC-DUMP2 parsed wrote={} okread={} entry={:08X} at query #{}",
                      wrote ? 1 : 0, okAll ? 1 : 0, ctx.r3.u32, n);
      }
    }
    // T41.3h (F-078) read-only: the host currently consumes entry+8 as BOTH
    // the Open gate flags (XSF-OPEN-GATE ORs bit30 there) and the member
    // offset, which cannot both hold. Dump the neighbouring 8 words so the
    // real layout is read from guest bytes instead of guessed. A 16-byte
    // stride that repeats the shape means the entry is 16B and +10 is sibling.
    uint32_t L[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 8; ++i)
      (void)memR.ReadU32BE(ctx.r3.u32 + 4u + static_cast<uint32_t>(i * 4),
                           &L[i]);
    MCLA_LOG_WARN(
        "TOC76-LAYOUT #{} path='{}' entry={:08X} +4=[{:08X} {:08X} {:08X} "
        "{:08X}] +14=[{:08X} {:08X} {:08X} {:08X}] xsf={} list={}",
        n, path, ctx.r3.u32, L[0], L[1], L[2], L[3], L[4], L[5], L[6], L[7],
        std::strstr(path, ".xsf") != nullptr ? 1 : 0,
        std::strstr(path, ".list") != nullptr ? 1 : 0);
  }
  // T41.3m (F-089) read-only, UNCAPPED: PathLooksLikeArchiveContent matches
  // .xsf/.xtd/.list/… but can never match "fxl_final/star_glow.fxc", so the
  // guest's TOC answer for the exact file the boot fatals on has never been
  // printable. Deliberately NOT routed through XsfTocCache or the Open-gate
  // pre-scan — a census, not a serve. If this line is absent for a path the
  // GETDEV census shows being asked for, the lookup was never attempted.
  if (path[0] && std::strstr(path, "star_glow") != nullptr) {
    const uint32_t ret = ctx.r3.u32;
    uint32_t w[4] = {0, 0, 0, 0};
    if (ret != 0 && ret != 0xFFFFFFFFu && ret != 0xCDCDCDCDu) {
      for (int i = 0; i < 4; ++i)
        (void)memR.ReadU32BE(ret + static_cast<uint32_t>(i * 4), &w[i]);
    }
    MCLA_LOG_WARN("TOC76-SG #{} path='{}' ret={:08X} [{:08X} {:08X} {:08X} "
                  "{:08X}] lr={:08X}",
                  n, path, ret, w[0], w[1], w[2], w[3], lr);
  }
}

// ---------------------------------------------------------------------------
// w13: fiPackfile Open (vtable+4 → CDB88 tails into CCEA0). TOC lookup can
// succeed while Open returns -1 because [entry+8] bit30 is clear — that is
// why .xsf stay TOC-only. Census return + entry; if the gate bit is clear on
// a live entry, set it (guest-memory flag fix — never an invented vtable).
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_821CCEA0);
static std::atomic<uint32_t> s_hCCEA0{0};
PPC_FUNC(sub_821CCEA0) {
  const uint32_t n = s_hCCEA0.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t pathPtr = ctx.r4.u32;
  const uint32_t flags = ctx.r5.u32;
  auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
  char path[96] = {0};
  if (pathPtr && pathPtr != 0xCDCDCDCDu)
    (void)memR.ReadBytes(pathPtr, path, sizeof(path) - 1);
  MclaSanitizePath(path, sizeof(path));
  const bool ui = PathLooksLikeUiBody(path);
  // Pre-scan: if this is a UI body and the cached TOC entry is missing the
  // Open-gate bit, set it so the body can land (same contract as a decrypted
  // retail entry).
  if (ui) {
    std::lock_guard<std::mutex> lk(g_xsfMtx);
    auto it = g_xsfToc.find(path);
    if (it != g_xsfToc.end() && it->second.entry != 0) {
      uint32_t e8 = 0;
      if (memR.ReadU32BE(it->second.entry + 8, &e8) &&
          (e8 & 0x40000000u) == 0) {
  // T41.3h (F-079): (void)memR.WriteU32BE(it->second.entry + 8, e8 | 0x40000000u);
        it->second.w[2] = e8 | 0x40000000u;
        // T41.3w: the guest-visible write above was removed by T41.3h (F-079),
        // so say what actually happens — only the host-side cached TOC copy
        // gets bit30, which is what the host serve path reads.
        MCLA_LOG_WARN("XSF-OPEN-GATE-SKIPPED path='{}' entry={:08X} +8 {:08X} -> "
                      "host cache only {:08X} (guest memory untouched)",
                      path, it->second.entry, e8, e8 | 0x40000000u);
      }
    }
  }
  __imp__sub_821CCEA0(ctx, base);
  const int32_t ret = static_cast<int32_t>(ctx.r3.s32);
  if (ui || n <= 24 || (n % 200) == 0) {
    uint32_t e0 = 0, e4 = 0, e8 = 0, e12 = 0;
    {
      std::lock_guard<std::mutex> lk(g_xsfMtx);
      auto it = g_xsfToc.find(path);
      if (it != g_xsfToc.end()) {
        e0 = it->second.w[0];
        e4 = it->second.w[1];
        e8 = it->second.w[2];
        e12 = it->second.w[3];
        it->second.openRet = ret;
      }
    }
    MCLA_LOG_WARN("XSF-OPEN #{} dev={:08X} flags={:x} path='{}' ret={} "
                  "toc=[{:08X} {:08X} {:08X} {:08X}] lr={:08X}",
                  n, dev, flags, path, ret, e0, e4, e8, e12,
                  static_cast<uint32_t>(ctx.lr));
  }
  // w18/w19: after a successful Open of an archive-content path, host-serv
  // the body from the cache RPF using TOC words, then BIND that buffer into
  // the packfile size/Read path (slot table + global BDF20 wrapper + served
  // registry). Guest Open returns 0; subsequent CC6F0/CD3C8/BE8D8 must see
  // these bytes, not empty/encrypted RPF payload.
  // F-131 CLOSED this route with offline evidence, so archive .fxc bodies must
  // NOT be served: the prototype XEX carries `rgxa 03 ff 03 10` at
  // 0x827D2DD0 (13 such containers in the image) while the retail archive's
  // compiled effects are `rgxa 01 ff 01 12` (AlphaModulate.fxc inflated at
  // 0x1DD1E8), and the guest's gate reads that difference as
  // 'Old version of rage effect found. You need to recompile your shaders!'.
  // Serving the pending (ret==1) opens therefore cannot reach a draw - w117/
  // w124/w125/w134/w136 all die at that fatal with LISTLINE 167 -> 1.
  // ret==-1/1 are not served; only the resident opens (ret==0) are.
  if (ret == 0 && PathLooksLikeArchiveContent(path)) {
    uint32_t tw[4] = {0, 0, 0, 0};
    uint32_t tocEntry = 0;
    {
      std::lock_guard<std::mutex> lk(g_xsfMtx);
      auto it = g_xsfToc.find(path);
      if (it == g_xsfToc.end() && std::strncmp(path, "a:/archive/", 11) == 0)
        it = g_xsfToc.find(path + 11);
      if (it != g_xsfToc.end()) {
        tocEntry = it->second.entry;
        for (int i = 0; i < 4; ++i)
          tw[i] = it->second.w[i];
      }
    }
    uint32_t xsz = 0;
    const uint32_t xbuf = HostServeUiBody(path, xsz);
    MCLA_LOG_WARN("XSF-POSTOPEN-SERVE path='{}' buf={:08X} size={} "
                  "dev={:08X} handle={} tocEntry={:08X} "
                  "toc=[{:08X} {:08X} {:08X} {:08X}]",
                  path, xbuf, xsz, dev, ret, tocEntry, tw[0], tw[1], tw[2],
                  tw[3]);
    if (xbuf && xsz > 0) {
      {
        std::lock_guard<std::mutex> lk(g_xsfMtx);
        auto it = g_xsfToc.find(path);
        if (it == g_xsfToc.end() && std::strncmp(path, "a:/archive/", 11) == 0)
          it = g_xsfToc.find(path + 11);
        if (it != g_xsfToc.end())
          it->second.bodyHits++;
      }
      auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
      MclaRegisterServedBody(path, xbuf, xsz, dev,
                             static_cast<uint32_t>(ret), tocEntry, tw);
      // F-346: remember the guest's own copy of a UI container so the Path B
      // serve can byte-compare its archive read against it (log-only).
      MclaUiXsfRecordGuestCopy(path, xbuf, xsz);
      // CD3C8 GetSize returns [tocEntry+4]. Publish the served size so
      // alloc+Read consumers get the body we actually hold.
      if (tocEntry && tocEntry != 0xCDCDCDCDu)
        (void)memR.WriteU32BE(tocEntry + 4, xsz);
      // Bind the global BDF20 stream wrapper {dev, handle} so later
      // BE8D8/BE610/BE250 on 0x82860C18 address this open file.
      constexpr uint32_t kBdf20Wrap = 0x82860C18u;
      (void)memR.WriteU32BE(kBdf20Wrap + 0, dev);
      (void)memR.WriteU32BE(kBdf20Wrap + 4, static_cast<uint32_t>(ret));
      // Packfile slot: Open already wrote tocEntry at dev+40+h*68.
      // Confirm + publish size on the TOC entry only (never invent a vtable).
      if (n <= 16 || (n % 8) == 0)
        MCLA_LOG_WARN("XSF-BIND path='{}' dev={:08X} h={} wrap={:08X} "
                      "tocEntry={:08X} size={} buf={:08X}",
                      path, dev, ret, kBdf20Wrap, tocEntry, xsz, xbuf);
      // Late GLOBTEX-BOOT from the served list body.
      const std::string np = MclaNormalizeArchivePath(path);
      if (np.find("globaltex") != std::string::npos ||
          np.find("preload.list") != std::string::npos)
        MclaBootstrapGlobaltexFromServed(base);
    }
  }
}

// ===========================================================================
// PHASE1 T4a: Mount-gate census
//
// Non-archive Mount call chain (never observed firing):
//   caller@82144C88 (gated by [r30+4]==0)
//     â†’ sub_82135E48(r31+6468, [r31+1312], [r31+1316])
//       â†’ sub_8213AB78(...)  // must return true
//       â†’ sub_82139BE0(...)  // builds path, bl Mount
//         â†’ sub_821CB9D8 (fiDevice::Mount)
//
// Prove which fork holds: host-missing gate vs device-must-exist vs
// dead code / constructor-based registration.
// ===========================================================================

PPC_FUNC_IMPL(__imp__sub_8213AB78);
static std::atomic<uint32_t> s_hAB78{0};
PPC_FUNC(sub_8213AB78) {
  const uint32_t n = s_hAB78.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (n <= 40 || (n % 200) == 0) {
    MCLA_LOG_WARN("MNTGATE-AB78 #{} r3={:08X} r4={:08X} r5={:08X} "
                  "lr={:08X} tid={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr,
                  GetCurrentThreadId());
  }
  __imp__sub_8213AB78(ctx, base);
  if (n <= 40 || (n % 200) == 0)
    MCLA_LOG_WARN("MNTGATE-AB78-RET #{} ret={:08X} lr={:08X}", n,
                  ctx.r3.u32, lr);
}

PPC_FUNC_IMPL(__imp__sub_82135E48);
static std::atomic<uint32_t> s_h5E48{0};
PPC_FUNC(sub_82135E48) {
  const uint32_t n = s_h5E48.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  char name[80] = {0};
  // r3 is often a path/buffer on the caller's stack (r31+6468).
  if (ctx.r3.u32 != 0 && ctx.r3.u32 != 0xCDCDCDCDu)
    mem.ReadBytes(ctx.r3.u32, name, 64);
  MclaSanitizePath(name, sizeof(name));
  if (n <= 40 || (n % 200) == 0) {
    MCLA_LOG_WARN("MNTGATE-5E48 #{} r3={:08X} [{}] r4={:08X} r5={:08X} "
                  "lr={:08X} tid={:08X}",
                  n, ctx.r3.u32, name, ctx.r4.u32, ctx.r5.u32, lr,
                  GetCurrentThreadId());
  }
  __imp__sub_82135E48(ctx, base);
  if (n <= 40 || (n % 200) == 0)
    MCLA_LOG_WARN("MNTGATE-5E48-RET #{} ret={:08X} lr={:08X}", n,
                  ctx.r3.u32, lr);
}

PPC_FUNC_IMPL(__imp__sub_82139BE0);
static std::atomic<uint32_t> s_h9BE0{0};
PPC_FUNC(sub_82139BE0) {
  const uint32_t n = s_h9BE0.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  MCLA_LOG_WARN("MNTGATE-9BE0 #{} r3={:08X} r4={:08X} r5={:08X} "
                "r6={:08X} lr={:08X}",
                n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, lr);
  __imp__sub_82139BE0(ctx, base);
  MCLA_LOG_WARN("MNTGATE-9BE0-RET #{} ret={:08X} lr={:08X}", n, ctx.r3.u32,
                lr);
}

// The site that decides whether to enter 5E48 at all:
//   lwz r11,4(r30); cmplwi r11,0; bne skip;  else bl 5E48
// Log every hit of the caller-side gate check via a thin wrapper on 5E48's
// peer sub_82144F28 (loop entry of the outer init fn) is not enough â€”
// census 5E48 is the proof. Also census 82144C88 via lrs already covered.
//
// Extra: dump [r30+4] from the outer frame is host-only; we log r30 contents
// when 5E48 is entered (caller passed r3=r31+6468). If 5E48 never logs,
// the gate above it bounced.
PPC_FUNC_IMPL(__imp__sub_82144F28);
static std::atomic<uint32_t> s_h44F28{0};
PPC_FUNC(sub_82144F28) {
  const uint32_t n = s_h44F28.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  // Only census when called from the Mount-gate caller range.
  if (n <= 24 || (n % 200) == 0)
    MCLA_LOG_INFO("MNTGATE-44F28 #{} r3={:08X} lr={:08X}", n, ctx.r3.u32, lr);
  __imp__sub_82144F28(ctx, base);
}

// Outer init fn that owns the Mount-gate block (contains 82144C88).
PPC_FUNC_IMPL(__imp__sub_82144B90);
static std::atomic<uint32_t> s_h44B90{0};
PPC_FUNC(sub_82144B90) {
  const uint32_t n = s_h44B90.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // r30 is set inside to a global block; dump [r3+772] and a few flags.
  uint32_t f772 = 0, f1312 = 0, f1316 = 0;
  if (ctx.r3.u32 != 0 && ctx.r3.u32 != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(ctx.r3.u32 + 772u, &f772);
    (void)mem.ReadU32BE(ctx.r3.u32 + 1312u, &f1312);
    (void)mem.ReadU32BE(ctx.r3.u32 + 1316u, &f1316);
  }
  MCLA_LOG_WARN(
      "MNTGATE-44B90 #{} r3={:08X} +772={:08X} +1312={:08X} +1316={:08X} "
      "lr={:08X} tid={:08X}",
      n, ctx.r3.u32, f772, f1312, f1316, lr, GetCurrentThreadId());
  __imp__sub_82144B90(ctx, base);
  MCLA_LOG_WARN("MNTGATE-44B90-RET #{} ret={:08X} lr={:08X}", n,
                ctx.r3.u32, lr);
}

// Caller of 44B90 (init teardown/finish).
PPC_FUNC_IMPL(__imp__sub_82144D30);
static std::atomic<uint32_t> s_h44D30{0};
PPC_FUNC(sub_82144D30) {
  const uint32_t n = s_h44D30.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  MCLA_LOG_WARN("MNTGATE-44D30 #{} r3={:08X} r4={:08X} r5={:08X} "
                "lr={:08X} tid={:08X}",
                n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr,
                GetCurrentThreadId());
  __imp__sub_82144D30(ctx, base);
  MCLA_LOG_WARN("MNTGATE-44D30-RET #{} ret={:08X} lr={:08X}", n,
                ctx.r3.u32, lr);
}

// Wrapper that calls 44D30 with a global block (r11=-32125+19856).
PPC_FUNC_IMPL(__imp__sub_82144EB0);
static std::atomic<uint32_t> s_h44EB0{0};
PPC_FUNC(sub_82144EB0) {
  const uint32_t n = s_h44EB0.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  MCLA_LOG_WARN("MNTGATE-44EB0 #{} r3={:08X} r4={:08X} r5={:08X} "
                "lr={:08X} tid={:08X}",
                n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr,
                GetCurrentThreadId());
  __imp__sub_82144EB0(ctx, base);
  MCLA_LOG_WARN("MNTGATE-44EB0-RET #{} ret={:08X} lr={:08X}", n,
                ctx.r3.u32, lr);
}

// ===========================================================================
// PHASE1 T4a2: sub_821CB740 (sprintf memory:$%p,%d,%d:%s) owners + handler
// entry ctor sub_821CB760 (call site lr=821CBAA4). Case A = any owner fires
// during preload. Case C = none fire + memory: only in prefix parsers.
// ===========================================================================

#define MCLA_T4A2_CENSUS(sym, tag)                                             \
  PPC_FUNC_IMPL(__imp__##sym);                                                 \
  static std::atomic<uint32_t> s_##tag{0};                                     \
  PPC_FUNC(sym) {                                                              \
    const uint32_t n = s_##tag.fetch_add(1) + 1;                               \
    if (n <= 24 || (n % 500) == 0)                                             \
      MCLA_LOG_WARN("MEMFMT-{} #{} r3={:08X} r4={:08X} r5={:08X} lr={:08X}",   \
                    #sym, n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,               \
                    static_cast<uint32_t>(ctx.lr));                            \
    __imp__##sym(ctx, base);                                                   \
    if (n <= 24 || (n % 500) == 0)                                             \
      MCLA_LOG_WARN("MEMFMT-{}-RET #{} ret={:08X}", #sym, n, ctx.r3.u32);      \
  }

MCLA_T4A2_CENSUS(sub_821CB740, fmt740)
MCLA_T4A2_CENSUS(sub_821CB760, ctor760)

// 13 unique owners of blâ†’sub_821CB740 (raw scan of mcla_pe.bin)
MCLA_T4A2_CENSUS(sub_8215B1D8, own5B1D8)
// sub_821BE8D8 is handled below with a richer census (obj/dev/handle).
MCLA_T4A2_CENSUS(sub_822C3A58, own2C3A58)
MCLA_T4A2_CENSUS(sub_822C4BD8, own2C4BD8)
MCLA_T4A2_CENSUS(sub_82390E08, own390E08)
MCLA_T4A2_CENSUS(sub_82390EB0, own390EB0)
MCLA_T4A2_CENSUS(sub_824A2B28, own4A2B28)
MCLA_T4A2_CENSUS(sub_826058B0, own6058B0)
MCLA_T4A2_CENSUS(sub_8263C728, own63C728)
MCLA_T4A2_CENSUS(sub_8263C8B0, own63C8B0)
MCLA_T4A2_CENSUS(sub_8263C9C8, own63C9C8)
MCLA_T4A2_CENSUS(sub_8263DCF8, own63DCF8)
MCLA_T4A2_CENSUS(sub_8263E1E8, own63E1E8)

#undef MCLA_T4A2_CENSUS

// Plain "memory:" @0x820127D8 owners â€” all fiDevice prefix parsers
// (hash/EMB/GETDEV), NOT a constructor. Census to confirm they are the
// only scanners and whether any produces a device object.
PPC_FUNC_IMPL(__imp__sub_821C9AB0);
static std::atomic<uint32_t> s_memC9AB0{0};
PPC_FUNC(sub_821C9AB0) {
  const uint32_t n = s_memC9AB0.fetch_add(1) + 1;
  if (n <= 16 || (n % 400) == 0)
    MCLA_LOG_INFO("MEMPARSE-C9AB0 #{} r3={:08X} r4={:08X} lr={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_821C9AB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821CAE50);
static std::atomic<uint32_t> s_memAE50{0};
PPC_FUNC(sub_821CAE50) {
  const uint32_t n = s_memAE50.fetch_add(1) + 1;
  if (n <= 16 || (n % 400) == 0)
    MCLA_LOG_INFO("MEMPARSE-AE50 #{} r3={:08X} r4={:08X} r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821CAE50(ctx, base);
}

// ===========================================================================
// T5-next: embedded:/ content via the D22E8/D2308 name list.
//
// INSERT file-resolve sub_821BDF20 does:
//   dev = GETDEV(path)                 // embedded: â†’ 0x827D838C
//   handle = dev->vtable[+4](path, x)  // AFB8 â€” only understands "memory:"
// AFB8 returns -1 for embedded:/, so INSERT fails even with a live device.
// Fix: host-hook AFB8 so embedded:/ walks the same list D2308 uses
// (head 0x82860AF8, node {+0 name*, +4 buf, +8 size, +12 next}) and returns
// the buffer pointer as the open handle (r3 != -1).
// ===========================================================================

constexpr uint32_t kEmbeddedNameListHead = 0x82860AF8; // lis -32122 + 2804
constexpr uint32_t kEmbeddedPfxLen = 10;               // "embedded:/"
constexpr uint32_t kMemVtable = 0x82012918;            // AE50/AFB8/...
// kMemDeviceObj is at file scope near the top.

// Something zeros [0x827D838C] and even .rdata vtable slot +4 at runtime
// (T9c/T10c: BE0C8 saw vt=0 then vt+4=0). Re-arm device ptr and the two
// load-bearing vtable slots before any virtual call.
static void EnsureMemoryDeviceVtable() {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t vt = 0;
  (void)mem.ReadU32BE(kMemDeviceObj, &vt);
  if (vt != kMemVtable)
    mem.WriteU32BE(kMemDeviceObj, kMemVtable);
  // Full known slots from mcla_pe.bin @0x82012918 â€” runtime wipes .rdata.
  static const uint32_t kSlots[] = {
      0x821CAE50u, // +0
      0x821CAFB8u, // +4
      0x8249B538u, // +8
      0x82762480u, // +12
      0x821CB070u, // +16
      0x821CB158u, // +20
      0x821CB030u, // +24
      0x82762480u, // +28
      0x821CB1F8u, // +32
      0x821CB330u, // +36
      0x821CB3C8u, // +40
      0x821CB2A0u, // +44
      0x821A5CC0u, // +48
      0x821CAB38u, // +52
      0x821CABB8u, // +56
      0x821A5CC0u, // +60
      0x821A5CC0u, // +64
      0x821A5CC0u, // +68
      0x821A5CC0u, // +72
      0x821A5CC0u, // +76
      0x821CB400u, // +80
      0x821A5CC0u, // +84
      0x821A5CC0u, // +88
  };
  for (size_t i = 0; i < sizeof(kSlots) / sizeof(kSlots[0]); ++i) {
    uint32_t cur = 0;
    (void)mem.ReadU32BE(kMemVtable + static_cast<uint32_t>(i * 4), &cur);
    if (cur != kSlots[i])
      mem.WriteU32BE(kMemVtable + static_cast<uint32_t>(i * 4), kSlots[i]);
  }
  // Guest allocs zero function-table slots at guest VA 0x829E0000+
  // (IMAGE_BASE+IMAGE_SIZE). Re-install the no-op stub A5CC0 (vtable+88).
  {
    uint8_t *gbase = mem.Base();
    // PPC_LOOKUP_FUNC: base + 0x82000000 + 0x9E0000 + (guest-0x82130000)*2
    constexpr uint32_t kA5CC0 = 0x821A5CC0u;
    void **slot = reinterpret_cast<void **>(
        gbase + 0x829E0000ull + (uint64_t(kA5CC0 - 0x82130000u) * 2));
    extern void sub_821A5CC0(PPCContext &, uint8_t *);
    void *want = reinterpret_cast<void *>(&sub_821A5CC0);
    if (*slot != want) {
      *slot = want;
      MCLA_LOG_WARN("FUNC-TAB remap 821A5CC0 -> {:p}", want);
    }
  }
}

// Host-side D2308: strcmp-walk the list; on hit fill buf/size and return true.
static bool EmbeddedListLookup(const char *relName, uint32_t *outBuf,
                               uint32_t *outSize) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t node = 0;
  if (!mem.ReadU32BE(kEmbeddedNameListHead, &node) || node == 0)
    return false;
  for (int guard = 0; node != 0 && guard < 256; ++guard) {
    uint32_t namePtr = 0, buf = 0, size = 0, next = 0;
    if (!mem.ReadU32BE(node + 0, &namePtr) ||
        !mem.ReadU32BE(node + 4, &buf) || !mem.ReadU32BE(node + 8, &size) ||
        !mem.ReadU32BE(node + 12, &next))
      return false;
    char name[128] = {0};
    if (namePtr != 0)
      (void)mem.ReadBytes(namePtr, name, sizeof(name) - 1);
    if (name[0] && std::strcmp(name, relName) == 0) {
      if (outBuf) *outBuf = buf;
      if (outSize) *outSize = size;
      return true;
    }
    node = next;
  }
  return false;
}

// Host-side D22E8: push {name, buf, size} onto the list head.
// Guest memory comes from GuestMemoryHeap::Alloc â€” never a hardcoded
// 0xA00xxxxx scratch (that hits o1heap and Free-ownership fatals).
static bool EmbeddedListInsert(const char *name, uint32_t buf, uint32_t size) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!name || !name[0] || buf == 0 || size == 0)
    return false;
  // Reject duplicate relative name.
  uint32_t dummyB = 0, dummyS = 0;
  if (EmbeddedListLookup(name, &dummyB, &dummyS))
    return false;

  const size_t nlen = std::strlen(name) + 1;
  const uint32_t nameG = mem.Alloc(nlen, 1);
  const uint32_t node = mem.Alloc(16, 4);
  if (nameG == 0 || node == 0) {
    MCLA_LOG_WARN("D2308-INS-FAIL name='{}' nameG={:08X} node={:08X}", name,
                  nameG, node);
    return false;
  }
  mem.WriteBytes(nameG, name, static_cast<uint32_t>(nlen));
  uint32_t head = 0;
  (void)mem.ReadU32BE(kEmbeddedNameListHead, &head);
  mem.WriteU32BE(node + 0, nameG);
  mem.WriteU32BE(node + 4, buf);
  mem.WriteU32BE(node + 8, size);
  mem.WriteU32BE(node + 12, head);
  mem.WriteU32BE(kEmbeddedNameListHead, node);
  MCLA_LOG_WARN("D2308-INS name='{}' buf={:08X} size={} node={:08X}",
                name, buf, size, node);
  return true;
}

// Last MakeMemoryStream â€” used by BE710-SKIP to serve magic bytes.
static uint32_t s_lastMemStream = 0;

// Stable .data slot (next to CRT nodes ~0x829054C0). Heap Alloc at
// C8024B00 got zeroed by a later arena wipe.
static constexpr uint32_t kMemStreamSlot = 0x82905500u;

// Phase 2 T3: the guest device API (sub_821CAE50 open family, CB158 read,
// CB2A0 close/getbuf, BE8D8's vt+56 size fetch) treats an open HANDLE as an
// index into a 16-entry slot table at 0x82860740 (stride 16: +0 buf, +4
// size, +8 pos, +12 flag). Returning a raw pointer as the handle made
// CB2A0's `if (h < 0 || h >= 16) return -1` poison BE8D8's alloc size into
// 0xffffffff -> the CDCD fill marathon. Register {buf,size} in the REAL
// guest slot table and return the slot index, matching sub_821CAE50's
// loc_821CAF50 open path exactly.
static constexpr uint32_t kGuestSlotTable = 0x82860740u;
static constexpr uint32_t kGuestSlotCount = 16;
static std::atomic<uint32_t> s_slotTableFull{0};

static int GuestSlotTableInsert(uint32_t buf, uint32_t size) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // The index this path handed out most recently. Only MakeMemoryStream calls
  // us, and every one of its streams is described by the single shared static
  // object kMemStreamSlot - so an older handle from this path already aliases
  // the newer body whether or not the slot table does.
  static std::atomic<uint32_t> s_lastIdx{0};
  // Slot 0 is reserved: the guest uses `r3 != 0` as the open-success check
  // (8218C804 after BE8D8), so index 0 is indistinguishable from NULL.
  for (uint32_t i = 1; i < kGuestSlotCount; ++i) {
    const uint32_t slot = kGuestSlotTable + i * 16;
    uint32_t cur = 0;
    if (!mem.ReadU32BE(slot + 0, &cur))
      return -1;
    if (cur == 0) {
      mem.WriteU32BE(slot + 0, buf);
      mem.WriteU32BE(slot + 4, size);
      mem.WriteU32BE(slot + 8, 0);
      mem.WriteU32BE(slot + 12, 0);
      s_lastIdx.store(i, std::memory_order_relaxed);
      return static_cast<int>(i);
    }
  }
  // F-135: the table is bounded (15 usable) and nothing ever released an
  // entry, so from the 16th served body on this returned -1 and
  // MakeMemoryStream fell back to handing the guest a raw pointer as its
  // handle. The guest's own device Seek (sub_821CB2A0, installed at vtable+44
  // for 0x827D838C) rejects h >= 16 with -1, and that -1 is exactly the size
  // the frontier's stream slurp allocates and reads: w145 SLOT-REG #1..#16
  // fill idx=1..15, SLOT-TABLE-FULL #1 starts 0.7 s later, and the single
  // doomed BE8D8 (w145, n=173, obj=82860C40 = the wrapper BDF20 #532 returned
  // for embedded:/fxl_final/rage_postfx.fxc) follows. Recycle a slot the guest
  // has already read to its last byte (pos >= size, the only state in which no
  // later Read of that body can still want it) before giving up.
  for (uint32_t i = 1; i < kGuestSlotCount; ++i) {
    const uint32_t slot = kGuestSlotTable + i * 16;
    uint32_t osize = 0, opos = 0;
    if (!mem.ReadU32BE(slot + 4, &osize) || !mem.ReadU32BE(slot + 8, &opos))
      continue;
    if (osize == 0 || osize == 0xCDCDCDCDu || opos < osize)
      continue;
    mem.WriteU32BE(slot + 0, buf);
    mem.WriteU32BE(slot + 4, size);
    mem.WriteU32BE(slot + 8, 0);
    mem.WriteU32BE(slot + 12, 0);
    static std::atomic<uint32_t> s_reused{0};
    const uint32_t r = s_reused.fetch_add(1) + 1;
    if (r <= 24 || (r % 200) == 0)
      MCLA_LOG_WARN("SLOT-RECYCLE #{} idx={} took buf={:08X} size={} from "
                    "exhausted slot (pos>=size)",
                    r, i, buf, size);
    s_lastIdx.store(i, std::memory_order_relaxed);
    return static_cast<int>(i);
  }
  // F-135b MITIGATION (labelled, cited; do-not #9): last resort before the
  // pointer fallback that F-134 proves costs the boot. w146 measured that the
  // pos>=size test above recycles only 1 of 15 slots (SLOT-RECYCLE #1 then
  // SLOT-TABLE-FULL #1..#8) because the guest consumes these bodies through
  // the served-registry path, never advancing slot pos - so the table stays
  // full and the frontier's embedded:/fxl_final/rage_postfx.fxc stream still
  // gets a pointer handle (w146:12649 doomed=1, w146:12650 the 0xffffffff
  // alloc). Overwrite the index this same host path used last: any older
  // handle already aliases the newer body anyway, because MakeMemoryStream
  // describes every stream with the one shared static kMemStreamSlot.
  {
    const uint32_t prev = s_lastIdx.load(std::memory_order_relaxed);
    if (prev >= 1 && prev < kGuestSlotCount) {
      const uint32_t slot = kGuestSlotTable + prev * 16;
      mem.WriteU32BE(slot + 0, buf);
      mem.WriteU32BE(slot + 4, size);
      mem.WriteU32BE(slot + 8, 0);
      mem.WriteU32BE(slot + 12, 0);
      static std::atomic<uint32_t> s_shared{0};
      const uint32_t q = s_shared.fetch_add(1) + 1;
      if (q <= 24 || (q % 200) == 0)
        MCLA_LOG_WARN("SLOT-RECYCLE-SHARED #{} idx={} reused the index this "
                      "host path last handed out (shared static stream) for "
                      "buf={:08X} size={}",
                      q, prev, buf, size);
      return static_cast<int>(prev);
    }
  }
  const uint32_t n = s_slotTableFull.fetch_add(1) + 1;
  if (n <= 8)
    MCLA_LOG_WARN("SLOT-TABLE-FULL #{} (16/16 in use) — cannot host-register "
                  "buf={:08X} size={}",
                  n, buf, size);
  return -1;
}
static uint32_t MakeMemoryStream(uint32_t device, uint32_t handle,
                                  uint32_t size) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Host-side shadow wrapper (BE250 Read() fields: +0 dev, +4 handle,
  // +8 buf, +16 counter, +24 readPos, +28 end, +32 cap). Kept so
  // MemoryStreamServeRead and the s_lastMemStream consumers still work.
  const uint32_t s = kMemStreamSlot;
  mem.WriteU32BE(s + 0, device);
  mem.WriteU32BE(s + 4, handle);
  mem.WriteU32BE(s + 8, size);
  mem.WriteU32BE(s + 12, 0);
  mem.WriteU32BE(s + 16, 0);
  mem.WriteU32BE(s + 20, 0);
  mem.WriteU32BE(s + 24, 0); // readPos  (BE250 field)
  mem.WriteU32BE(s + 28, 0); // writePos (BE250 field)
  s_lastMemStream = s;
  // Phase 2 T3 fix: the guest treats an open handle as a slot index. Insert
  // {handle=buf, size} into the real 16-entry slot table and return the
  // INDEX — the exact contract of sub_821CAE50's open path. The BE8D8
  // vt+56 size fetch then returns the real buffer, alloc(size) succeeds,
  // and Read() gets sane counts instead of 0xffffffff.
  const int slotIdx = GuestSlotTableInsert(handle, size);
  if (slotIdx >= 0) {
    static std::atomic<uint32_t> s_slotReg{0};
    const uint32_t n = s_slotReg.fetch_add(1) + 1;
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("SLOT-REG #{} idx={} buf={:08X} size={} (guest slot table "
                    "@82860740)",
                    n, slotIdx, handle, size);
    return static_cast<uint32_t>(slotIdx);
  }
  // Table full: legacy behavior (pointer handle) — logged above.
  return s;
}

// Host-side read for a dead/legacy wrapper: obj+4=buf, obj+8=size, cursor at
// obj+24 (mirrors sub_821BE250's buffer shape). Serves min(count, size-cursor)
// bytes and advances the cursor. Returns bytes served, or -1 when obj is not
// a wrapper we recognize.
static int64_t MemoryStreamServeRead(uint32_t obj, uint32_t dst, uint32_t count,
                                     uint32_t callerLr = 0) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t buf = 0, size = 0, pos = 0;
  if (obj == 0 || obj == 0xCDCDCDCDu)
    return -1;
  // Wrapper form: [+4]=buf [+8]=size [+24]=cursor. The CRT seed slot is the
  // canonical wrapper (MakeMemoryStream layout).
  if (!mem.ReadU32BE(obj + 4, &buf) || !mem.ReadU32BE(obj + 8, &size))
    return -1;
  if (buf == 0 || buf == 0xCDCDCDCDu || size == 0 || size == 0xCDCDCDCDu)
    return -1;
  (void)mem.ReadU32BE(obj + 24, &pos);
  if (pos > size)
    pos = size;
  const uint32_t avail = size - pos;
  const uint32_t n = (count < avail) ? count : avail;
  // F-122 census: this MakeMemoryStream-layout interpretation is only correct
  // for OUR wrappers. On a guest-native buffered stream [+4] is a handle and
  // [+8] is the buffer, so `buf + pos` lands in the null guard page — that is
  // the read that faulted 50 times per soak. Refuse it and name the object, so
  // the soak says which wrapper was misread instead of the VEH saying only that
  // a copy faulted.
  const uint32_t src = buf + pos;
  if (src < 4096u) {
    static std::atomic<uint32_t> s_badPtr{0};
    const uint32_t nb = s_badPtr.fetch_add(1) + 1;
    if (nb <= 52 || (nb % 200) == 0)
      MCLA_LOG_WARN("BE250-MEM-BADPTR #{} obj={:08X} +4={:08X} +8={:08X} "
                    "+24={:08X} src={:08X} dst={:08X} count={} lr={:08X} — "
                    "not a MakeMemoryStream wrapper, refused (r3=-1)",
                    nb, obj, buf, size, pos, src, dst, count, callerLr);
    return -1;
  }
  if (n != 0 && dst != 0 && dst != 0xCDCDCDCDu) {
    uint8_t tmp[512];
    uint32_t done = 0;
    while (done < n) {
      const uint32_t chunk = (n - done > sizeof(tmp)) ? sizeof(tmp) : n - done;
      if (!mem.ReadBytes(buf + pos + done, tmp, chunk))
        return -1;
      if (!mem.WriteBytes(dst + done, tmp, chunk))
        return -1;
      done += chunk;
    }
  }
  if (n != 0)
    (void)mem.WriteU32BE(obj + 24, pos + n);
  return n;
}

// p2d rgxa fix: serve a read directly from a guest slot-table entry
// ({buf,size,pos,flag} @0x82860740 + h*16 — the exact contract of the
// original vt+20 slot read 821CB158). The original BE250 machinery can't
// serve these: BDF20's guest wrapper keeps +8/+24/+28/+32 buffered fields
// uninitialized for our slot handles, so its refill path yields garbage.
// wordSwap mirrors the original sub_821BE710 tail loop (821BE73C-768):
// it byteswaps each full 4-byte word of the destination after the raw
// copy (the .fxc format is little-endian on disk, PPC host is BE).
// Returns bytes served (advancing slot pos), or -1 when h is not a live
// slot or dst is poisoned (pos NOT advanced on failure).
static int64_t SlotTableServeRead(uint32_t h, uint32_t dst, uint32_t count,
                                   bool wordSwap = false) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (h == 0 || h >= kGuestSlotCount)
    return -1;
  const uint32_t slot = kGuestSlotTable + h * 16;
  uint32_t sbuf = 0, ssize = 0, spos = 0;
  if (!mem.ReadU32BE(slot + 0, &sbuf) || !mem.ReadU32BE(slot + 4, &ssize) ||
      !mem.ReadU32BE(slot + 8, &spos))
    return -1;
  if (sbuf == 0 || sbuf == 0xCDCDCDCDu || ssize == 0 || ssize == 0xCDCDCDCDu)
    return -1;
  if (spos > ssize)
    spos = ssize;
  const uint32_t avail = ssize - spos;
  const uint32_t nb = (count < avail) ? count : avail;
  if (nb != 0) {
    if (dst == 0 || dst == 0xCDCDCDCDu)
      return -1;
    uint8_t tmp[512];
    uint32_t done = 0;
    while (done < nb) {
      const uint32_t chunk = (nb - done > sizeof(tmp)) ? sizeof(tmp) : nb - done;
      if (!mem.ReadBytes(sbuf + spos + done, tmp, chunk))
        return -1;
      if (wordSwap) {
        for (uint32_t o = 0; o + 4 <= chunk; o += 4)
          std::swap(tmp[o], tmp[o + 3]), std::swap(tmp[o + 1], tmp[o + 2]);
      }
      if (!mem.WriteBytes(dst + done, tmp, chunk))
        return -1;
      done += chunk;
    }
    (void)mem.WriteU32BE(slot + 8, spos + nb);
  }
  return nb;
}

// AFB8 = INSERT's vtable+4 open. Path is r4.
// Host-handle BOTH embedded:/ and memory:$ so we never re-enter original
// AFB8/CAD80 (BE0C8 re-open AVed at 0x7e780000 there). Return value matches
// original semantics: the buffer pointer, or -1 on miss.
// memory:$ format from sub_821CB740: "memory:$%p,%d,%d:%s"
PPC_FUNC_IMPL(__imp__sub_821CAFB8);
static std::atomic<uint32_t> s_hAFB8{0};
static bool ParseMemoryDollar(const char *path, uint32_t *outBuf,
                              uint32_t *outSize) {
  // path like memory:$827D2DD0,5258,0:name
  if (!path || std::strncmp(path, "memory:$", 8) != 0)
    return false;
  const char *p = path + 8;
  char *end = nullptr;
  const unsigned long buf = std::strtoul(p, &end, 16);
  if (end == p || *end != ',')
    return false;
  p = end + 1;
  const unsigned long sz = std::strtoul(p, &end, 10);
  if (end == p)
    return false;
  if (outBuf) *outBuf = static_cast<uint32_t>(buf);
  if (outSize) *outSize = static_cast<uint32_t>(sz);
  return true;
}

PPC_FUNC(sub_821CAFB8) {
  const uint32_t n = s_hAFB8.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  char path[192] = {0};
  if (ctx.r4.u32 != 0 && ctx.r4.u32 != 0xCDCDCDCDu)
    (void)mem.ReadBytes(ctx.r4.u32, path, sizeof(path) - 1);
  MclaSanitizePath(path, sizeof(path));
  const bool uiBody = PathLooksLikeUiBody(path);
  if (n <= 8 || path[0] == 'm' || path[0] == 'e' || uiBody)
    MCLA_LOG_WARN("AFB8-IN #{} r3={:08X} r4={:08X} path='{}' lr={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, path,
                  static_cast<uint32_t>(ctx.lr));
  EnsureMemoryDeviceVtable();
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  uint32_t buf = 0, size = 0;

  if (std::strncmp(path, "embedded:/", 10) == 0 && path[10]) {
    const bool hit = EmbeddedListLookup(path + 10, &buf, &size);
    if (hit) {
      const uint32_t st = MakeMemoryStream(kMemDeviceObj, buf, size);
      MCLA_LOG_WARN("AFB76-HIT #{} path='{}' buf={:08X} size={} stream={:08X} "
                    "lr={:08X}",
                    n, path, buf, size, st, lr);
      ctx.r3.u32 = st;
      return;
    }
    if (n <= 40 || (n % 200) == 0)
      MCLA_LOG_WARN("AFB76-MISS #{} path='{}' lr={:08X}", n, path, lr);
    // T41.3d (F-066/F-067): this substitution could never work. star_glow.fxc is
    // absent from all 15 embedded fxl_final/* bodies and none carries a star_glow
    // key name, while rage_im's body necessarily contains the obsolete drawblit
    // technique at buf+0x1365 - so serving it guaranteed the guest's
    // 'drawblit technique is old and busted' fatal. Measured on the pre-fault
    // tree: C0000005 2 -> 0 (first zero-AV soak), parked thread 1 -> 0.
    if (std::strstr(path, "star_glow") != nullptr)
      MCLA_LOG_WARN("AFB76-MISS-HONEST #{} path='{}' lr={:08X} (T41.3d/F-066)",
                    n, path, lr);
    ctx.r3.u32 = 0xFFFFFFFFu;
    return;
  }

  if (ParseMemoryDollar(path, &buf, &size) && buf != 0) {
    const uint32_t st = MakeMemoryStream(kMemDeviceObj, buf, size);
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("AFB76-MEM$ #{} path='{}' buf={:08X} size={} stream={:08X} "
                    "lr={:08X}",
                    n, path, buf, size, st, lr);
    // F-152: an object-shaped return for the sub_821BE0C8 re-open was tried here
    // and MEASURED INERT (w162: AFB76-MEM$-OBJ 0 lines, SEEK-DEAD unchanged) -
    // this hook never sees the memory:$ path at all, so the index that faults is
    // the guest's own sub_821BE0C8 return. Reverted; see F-152.
    ctx.r3.u32 = st;
    return;
  }

  // w13: UI .xsf body host-serve. Guest TOC lookup finds the file but the
  // body Read never lands (encrypted RPF + Open gate). Serve from cache RPF
  // at the TOC-derived offset when we have one — same pattern as job2.
  // T41.3f was VOID as a no-op (F-077): this branch never served the list
  // paths. The gate now lives in HostServeUiBody (T41.3g).
  if (uiBody) {
    uint32_t xsz = 0;
    const uint32_t xbuf = HostServeUiBody(path, xsz);
    if (xbuf && xsz > 0) {
      const uint32_t st = MakeMemoryStream(kMemDeviceObj, xbuf, xsz);
      {
        std::lock_guard<std::mutex> lk(g_xsfMtx);
        auto it = g_xsfToc.find(path);
        if (it != g_xsfToc.end())
          it->second.bodyHits++;
      }
      MCLA_LOG_WARN("AFB76-XSF-HIT #{} path='{}' buf={:08X} size={} "
                    "stream={:08X} lr={:08X}",
                    n, path, xbuf, xsz, st, lr);
      // w19: also register so packfile CC6F0/BE8D8 can find this body.
      uint32_t tw[4] = {0, 0, 0, 0};
      uint32_t tocEntry = 0;
      {
        std::lock_guard<std::mutex> lk(g_xsfMtx);
        auto it = g_xsfToc.find(path);
        if (it == g_xsfToc.end() &&
            std::strncmp(path, "a:/archive/", 11) == 0)
          it = g_xsfToc.find(path + 11);
        if (it != g_xsfToc.end()) {
          tocEntry = it->second.entry;
          for (int i = 0; i < 4; ++i)
            tw[i] = it->second.w[i];
        }
      }
      MclaRegisterServedBody(path, xbuf, xsz, kMemDeviceObj,
                             static_cast<uint32_t>(st), tocEntry, tw);
      ctx.r3.u32 = st;
      return;
    }
    if (n <= 40 || (n % 50) == 0)
      MCLA_LOG_WARN("AFB76-XSF-MISS #{} path='{}' lr={:08X} (no TOC offset "
                    "or body refused)",
                    n, path, lr);
  }

  __imp__sub_821CAFB8(ctx, base);
}

// INSERT file-resolve sub_821BDF20: GETDEV â†’ vtable+4 (AFB8) â†’ handle.
// Census so we see whether AFB76-HIT actually feeds a successful INSERT.
PPC_FUNC_IMPL(__imp__sub_821BDF20);
static std::atomic<uint32_t> s_hBDF20{0};
PPC_FUNC(sub_821BDF20) {
  const uint32_t n = s_hBDF20.fetch_add(1) + 1;
  const uint32_t pathG = ctx.r3.u32;
  const uint32_t flags = ctx.r4.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  char path[96] = {0};
  if (pathG != 0 && pathG != 0xCDCDCDCDu) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadBytes(pathG, path, sizeof(path) - 1);
    MclaSanitizePath(path, sizeof(path));
  }
  __imp__sub_821BDF20(ctx, base);
  const int32_t ret = static_cast<int32_t>(ctx.r3.s32);
  // F-144: 0x827D7770 is not a type registry, it is the resource *path* manager
  // (w152's MSGBISECT "3-821CA540 name-insert" shows it being fed
  // '$/resources/ui', '$/resources/ui/', '$/textures/global/cars', 'globaltex',
  // '$/tune/shaders/lib', 'ui'), and sub_821CA6A8(mgr, name, typeName, 0,
  // required) opens one composed candidate path per mount from its scan loop -
  // a `bl` whose return address is 0x821CA708 (ppc_recomp.16.cpp:14210-ff:
  // sub_821CA2F8 composes into sp+80, then sub_821BDF20). w152's TYPINIT showed
  // 'entity' (x3) and 'entity.type' all failing with that loop's bound
  // [0x827D7770+3076] == 1, and none of those opens passed this census's
  // filter, so print them on their own marker: the composed path plus the
  // guest's own open result is what says whether this is a missing mount, a
  // missing archive member, or a path that is composed wrong.
  static std::atomic<uint32_t> s_hPathMgrOpen{0};
  if (lr == 0x821CA708u) {
    const uint32_t m = s_hPathMgrOpen.fetch_add(1) + 1;
    // w153: the first 60 candidates are globaltex/.list, 19 .dds and the ui
    // shader dcls - the cap expired ~16 s before the entity.type lookup, so
    // print any candidate that could BE the failing one regardless of count.
    if (m <= 60 || std::strstr(path, "entity") || std::strstr(path, ".type"))
      MCLA_LOG_WARN("PATHMGR-OPEN #{} path='{}' flags={:x} ret={:d} lr={:08X}",
                    m, path, flags, ret, lr);
  }
  if (n <= 40 || (n % 200) == 0 || std::strstr(path, "star_glow") ||
      std::strstr(path, "embedded:") || PathLooksLikeUiBody(path))
    MCLA_LOG_WARN("BDF20 #{} path='{}' flags={:x} ret={:d} lr={:08X}", n,
                  path, flags, ret, lr);
}

// F-233 targeted read-only census: name the container the UI-bootstrap byte-reader
// (sub_821CFAA8) blocks refilling. Per generated ppc_recomp.17.cpp:12420-12424, when
// the reader's byte buffer is exhausted it calls sub_821BE4F0 (return 0x821CFB40) to
// pull the next "kind" byte from the stream; the bootstrap parks deeper (sub_82249750)
// when that refill never delivers. RESULT (w242, now reverted): the reader is refilling
// SHADER/EFFECT files (AlphaModulate.fx / WheelRubber.fx / Character.fx / entity.type
// "Version: 103" shadinggroups), NOT the UI .xsf — the bootstrap blocks in the
// shader/effects preload, upstream of UI load. Kept as a named symbol only; the noisy
// 2432-line dump was removed after measurement.
// Richer BE8D8 census (replaces MCLA_T4A2_CENSUS): [obj+0]=device* [obj+4]=handle.
//
// Phase 2 T3 root-cause fix: sub_821BE8D8 = "load whole embedded file":
//   size = dev->vt[+56](dev, handle); alloc(size); Read(this, dst, size);
//   format "memory:$..." (CB740); GetSize (BE610); re-open (BE0C8).
// On the REAL device this runs against (archive vt=82012BDC), vt+56 =
// sub_821CD3C8: indexes dev+h*68 entry table, returns [file+4] = size.
// Our memory-device vt+56 (CABB8 -> 3x vt+44 close) returns -1 by
// construction -> alloc(0xffffffff) NULL -> Read(NULL, -1) -> the CDCD
// fill marathon (135M+ stores, PHYS-OVERRUN storm, t24c/p2b).
// Host-complete the whole flow when the wrapper's handle is one of ours:
// real size, guest-visible alloc, serve bytes, return a memory:$ stream
// (the exact contract of the tail's BE0C8-RET path).
PPC_FUNC_IMPL(__imp__sub_821BE8D8);
static std::atomic<uint32_t> s_hBE8D8{0};
// F-162: latched around the single sub_821BE8D8 call whose caller dereferences
// the return value. sub_82191040 does `mr r31,r3` after this call
// (generated/ppc_xenon/ppc_recomp.10.cpp:10912-10993) and then passes r31 to
// sub_821BE4F0 / sub_821CF7B8 / sub_821BE610 / sub_821BE568 as a stream OBJECT,
// while every other caller stores the value as a slot handle - which is precisely
// why F-153/F-155/F-156's blanket object return at sub_821BE0C8 lost ground (it
// re-shaped all 179 re-opens). w170's caller tally shows this caller runs exactly
// once per boot: BE8D8-CALLER #4 lr=82191070 first at n=190.
static bool s_reopenWantsObject = false;
PPC_FUNC(sub_821BE8D8) {
  const uint32_t n = s_hBE8D8.fetch_add(1) + 1;
  EnsureMemoryDeviceVtable();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0, h = 0, vt = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
    if (dev != 0 && dev != 0xCDCDCDCDu)
      (void)mem.ReadU32BE(dev, &vt);
  }
  if (n <= 24 || (n % 200) == 0 || dev == 0x7E780000u || h == 0x7E780000u ||
      obj == 0x7E780000u)
    MCLA_LOG_WARN("BE8D8 #{} obj={:08X} dev={:08X} vt={:08X} h={:08X} lr={:08X}",
                  n, obj, dev, vt, h, lr);
  // F-162 census: WHICH callers reach this function. The predicate above only
  // ever showed lr=8218C804, and sub_82191040 - the caller whose `mr r31,r3`
  // makes this return value a stream object at four later sites (F-157) - lands
  // outside that window, so its attribution could be neither confirmed nor
  // refuted from the log. Tally by caller, print each caller once when it first
  // appears, and print the whole tally every 200 calls. Log-only.
  {
    struct Caller {
      uint32_t lr;
      std::atomic<uint32_t> n;
    };
    static Caller s_tally[12] = {};
    int found = -1, freeSlot = -1;
    for (int k = 0; k < 12; ++k) {
      if (s_tally[k].lr == 0) {
        if (freeSlot < 0)
          freeSlot = k;
        continue;
      }
      if (s_tally[k].lr == lr) {
        found = k;
        break;
      }
    }
    if (found < 0 && freeSlot >= 0) {
      s_tally[freeSlot].lr = lr;
      s_tally[freeSlot].n.store(1, std::memory_order_relaxed);
      MCLA_LOG_WARN("BE8D8-CALLER #{} lr={:08X} first at n={} obj={:08X} "
                    "dev={:08X} h={:08X}",
                    freeSlot, lr, n, obj, dev, h);
    } else if (found >= 0) {
      s_tally[found].n.fetch_add(1, std::memory_order_relaxed);
    }
    if ((n % 200) == 0) {
      char acc[256] = {0};
      int o = 0;
      for (int k = 0; k < 12 && o < 200; ++k)
        if (s_tally[k].lr != 0)
          o += std::snprintf(acc + o, sizeof(acc) - o, " %08X:%u",
                             s_tally[k].lr,
                             s_tally[k].n.load(std::memory_order_relaxed));
      MCLA_LOG_WARN("BE8D8-CALLERS at n={} lr:count[{}]", n, acc);
    }
  }
  // Host-complete for memory-device wrappers whose handle is a slot index
  // (0..15) registered by MakeMemoryStream (SLOT-REG). The guest slot table
  // at 0x82860740 holds {buf, size, pos, flag}.
  if (dev == kMemDeviceObj && h < kGuestSlotCount) {
    const uint32_t slot = kGuestSlotTable + h * 16;
    uint32_t sbuf = 0, ssize = 0;
    bool have = mem.ReadU32BE(slot + 0, &sbuf) && mem.ReadU32BE(slot + 4, &ssize);
    if (have && sbuf != 0 && ssize != 0 && ssize != 0xCDCDCDCDu) {
      // BE8D8 semantics, faithfully: alloc(size) then Read all `ssize` bytes
      // into it. The tail (memory:$ format + BE610 + BE0C8) exists to re-open
      // the loaded buffer as a stream; return that stream directly, exactly
      // like the BE0C8-RET host path does.
      const uint32_t dst = mem.Alloc(ssize, 16);
      if (dst != 0) {
        uint8_t tmp[512];
        uint32_t done = 0;
        bool ok = true;
        while (done < ssize) {
          const uint32_t chunk =
              (ssize - done > sizeof(tmp)) ? sizeof(tmp) : ssize - done;
          if (!mem.ReadBytes(sbuf + done, tmp, chunk) ||
              !mem.WriteBytes(dst + done, tmp, chunk)) {
            ok = false;
            break;
          }
          done += chunk;
        }
        if (ok) {
          // F-160: release the consumed slot by calling the guest's OWN close
          // routine (sub_821CB2A0, the entry we install at memory-device
          // vtable+44) instead of writing 0 to [entry+0] by hand. Decoded from
          // build/cache/mcla_pe.bin, that routine's `stw r11,0(r31)` is the only
          // thing in the image that frees a table entry, and w167 measured
          // SLOT-CLOSE firing 0 times - nothing calls it, which is why the
          // guest's 16-entry table leaks and why F-135's SLOT-RECYCLE tiers were
          // ever needed. We borrow the caller's frame, so r1 is moved to a
          // scratch window first (the routine saves LR at -8(r1) and r31 at
          // -96(r1) BEFORE its own stwu) and restored after. The flag byte stays
          // 0, so the routine's free path (taken only when [entry+12] != 0) is
          // not entered and our buffer survives.
          // F-161 MEASURED: this is the only safe release point. Adding the same
          // release at the READ sites (sub_821BE250 / sub_821BE710 once slot pos
          // reached size, i.e. F-135 tier-1's own condition) was built and soaked
          // as w169 and is catastrophic - Fatal error 0->2, FATAL-SOFT 0->3,
          // fatal-shaped lines 37->5,946, INFLATE 358->168, [error] 42->61 -
          // because while GuestSlotTableInsert's SLOT-RECYCLE-SHARED tier hands
          // the same index to consecutive bodies, a "consumed" slot IS the one
          // other live handles still alias. Here the body has already been
          // duplicated into dst, so the source slot is genuinely dead. Do not
          // re-try the read-site release without first giving each body its own
          // slot; that is what would retire F-135/F-135b.
          const uint32_t r1In = ctx.r1.u32;
          const uint32_t r4In = ctx.r4.u32;
          ctx.r1.u32 = r1In - 256u;
          ctx.r4.u32 = h;
          sub_821CB2A0(ctx, base);
          ctx.r1.u32 = r1In;
          ctx.r4.u32 = r4In;
          uint32_t entry0 = 0xFFFFFFFFu;
          (void)mem.ReadU32BE(slot + 0, &entry0);
          if (n <= 24 || (n % 200) == 0)
            MCLA_LOG_WARN("BE8D8-CLOSE #{} h={} slot={:08X} entry0_after={:08X}",
                          n, h, slot, entry0);
          const uint32_t st = MakeMemoryStream(kMemDeviceObj, dst, ssize);
          MCLA_LOG_WARN("BE8D8-HOST #{} obj={:08X} h={} buf={:08X} size={} "
                        "dst={:08X} stream={:08X}",
                        n, obj, h, sbuf, ssize, dst, st);
          ctx.r3.u32 = st;
          return;
        }
        MCLA_LOG_WARN("BE8D8-HOST #{} copy FAILED buf={:08X} size={}", n, sbuf,
                      ssize);
      } else {
        MCLA_LOG_WARN("BE8D8-HOST #{} alloc FAILED size={} (guest heap)",
                      n, ssize);
      }
    }
  }
  // w19: packfile-device wrapper {dev=packfile, handle=slot}. Open stored
  // tocEntry at dev+40+h*68; POSTOPEN-SERVE registered the body. Host-complete
  // size+Read from that buffer (same BE8D8 semantics as the memory-device path).
  if (dev != 0 && dev != 0xCDCDCDCDu && dev != kMemDeviceObj &&
      dev != 0x7E780000u && h < 16u) {
    uint32_t tocEntry = 0;
    (void)mem.ReadU32BE(dev + 40u + h * 68u, &tocEntry);
    MclaServedBody body{};
    if (MclaFindServedBody(dev, h, 0, tocEntry, 0, &body) && body.buf &&
        body.size) {
      const uint32_t ssize = body.size;
      const uint32_t dst = mem.Alloc(ssize, 16);
      if (dst != 0) {
        uint8_t tmp[512];
        uint32_t done = 0;
        bool ok = true;
        while (done < ssize) {
          const uint32_t chunk =
              (ssize - done > sizeof(tmp)) ? sizeof(tmp) : ssize - done;
          if (!mem.ReadBytes(body.buf + done, tmp, chunk) ||
              !mem.WriteBytes(dst + done, tmp, chunk)) {
            ok = false;
            break;
          }
          done += chunk;
        }
        if (ok) {
          const uint32_t st = MakeMemoryStream(kMemDeviceObj, dst, ssize);
          // T41.3t (F-107 follow-on): five of five list bodies are delivered but
          // only two groups yield lines, so print what the loader was actually
          // handed — text or stored bytes — next to the path.
          char vis[33] = {0};
          unsigned char raw[32] = {0};
          (void)mem.ReadBytes(dst, raw, ssize < 32u ? ssize : 32u);
          for (int k = 0; k < 32; ++k)
            vis[k] = (raw[k] >= 32u && raw[k] < 127u) ? (char)raw[k] : '.';
          MCLA_LOG_WARN("BE8D8-PACK #{} obj={:08X} dev={:08X} vt={:08X} h={} "
                        "tocEntry={:08X} path='{}' sbuf={:08X} size={} "
                        "dst={:08X} stream={:08X} head=[{:08X}] ascii='{}'",
                        n, obj, dev, vt, h, tocEntry, body.path, body.buf,
                        ssize, dst, st, MclaBE(raw), vis);
          ctx.r3.u32 = st;
          return;
        }
        MCLA_LOG_WARN("BE8D8-PACK #{} copy FAILED path='{}' buf={:08X} size={}",
                      n, body.path, body.buf, ssize);
      } else {
        MCLA_LOG_WARN("BE8D8-PACK #{} alloc FAILED size={} path='{}'", n,
                      ssize, body.path);
      }
    } else if (tocEntry != 0 && tocEntry != 0xCDCDCDCDu && n <= 24) {
      uint32_t tsz = 0;
      (void)mem.ReadU32BE(tocEntry + 4, &tsz);
      MCLA_LOG_WARN("BE8D8-PACK-MISS #{} dev={:08X} h={} tocEntry={:08X} "
                    "toc+4={:08X} (no served body)",
                    n, dev, h, tocEntry, tsz);
    }
  }
  // T41.13 CENSUS ONLY (read-only). The frontier's one 0xFFFFFFFF per boot is
  // the size this call site's *own* device GetSize returns: the rage-effect
  // loader's slurp is `bl 0x821be8d8` with ctx.lr = 0x8218C804
  // (ppc_recomp.9.cpp:18394-18396), and the body computes
  //   size = [[dev]+56](dev, handle)          (ppc_recomp.15.cpp:200-212)
  //   buf  = XTL alloc(size)                  (thunk sub_82130528: mr r4,r3;
  //                                            li r5,16 -> __xtl_alloc, which
  //                                            is the caller of the failed
  //                                            AllocPhysical(0xffffffff) -
  //                                            XAllocMem printed 0x in w143)
  //   then Read(buf, size)                    -> the 321 MB poison memcpy
  // GetSize is 0x821CD3C8 (raw word at vtable 0x82012BDC+56 in mcla_pe.bin):
  //   cmpi r4,0 / cmpi r4,16 -> li r3,-1 ; toc=[dev+40+h*68] ; if(!toc) li r3,-1
  //   else return [toc+4]
  // so -1 is an ERROR return, not a size read from data, and the body allocates
  // whatever it returns without checking (ppc_recomp.15.cpp:213-222). Print only
  // the calls where the guest's own GetSize will answer -1, plus every wrapper
  // that is not the 0x82860C68 one the archive path reuses.
  if (lr == 0x8218C804u) {
    static std::atomic<uint32_t> s_rageSz{0};
    uint32_t sz56 = 0, toc = 0, toc4 = 0, f8 = 0, f24 = 0, f28 = 0, f32 = 0;
    if (vt)
      (void)mem.ReadU32BE(vt + 56, &sz56);
    if (dev && h < 64u) {
      (void)mem.ReadU32BE(dev + 40u + h * 68u, &toc);
      if (toc && toc != 0xCDCDCDCDu)
        (void)mem.ReadU32BE(toc + 4, &toc4);
    }
    const bool doomed = (h == 0u) || (h >= 16u) || (toc == 0u) ||
                        (toc == 0xCDCDCDCDu) || (toc4 == 0xFFFFFFFFu);
    if (doomed || obj != 0x82860C68u) {
      const uint32_t k = s_rageSz.fetch_add(1) + 1;
      if (k <= 40) {
        (void)mem.ReadU32BE(obj + 8, &f8);
        (void)mem.ReadU32BE(obj + 24, &f24);
        (void)mem.ReadU32BE(obj + 28, &f28);
        (void)mem.ReadU32BE(obj + 32, &f32);
        MCLA_LOG_WARN("BE8D8-RAGESZ #{} n={} obj={:08X} dev={:08X} vt={:08X} "
                      "h={} getSz={:08X} slot={:08X} toc={:08X} toc+4={:08X} "
                      "obj+8={:08X} +24={} +28={} +32={} doomed={}",
                      k, n, obj, dev, vt, h, sz56, dev + 40u + h * 68u, toc,
                      toc4, f8, f24, f28, f32, doomed ? 1 : 0);
      }
    }
  }
  // F-162: the ONE call whose caller dereferences the result - let the guest's
  // own tail run (it reaches sub_821BE0C8 from inside, w170: BE0C8 #179 with
  // lr=821BE988 right after this site) but ask that re-open for an object.
  if (lr == 0x82191070u) {
    s_reopenWantsObject = true;
    __imp__sub_821BE8D8(ctx, base);
    s_reopenWantsObject = false;
    return;
  }
  __imp__sub_821BE8D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821BE610);
static std::atomic<uint32_t> s_hBE610{0};
PPC_FUNC(sub_821BE610) {
  const uint32_t n = s_hBE610.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0, h = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  // T7b/T8a: after BE8D8 formats memory:$ the stream object's device/handle
  // are already 0; BE610 still does vtable+48 on null â†’ AV 0x7e780000.
  if (dev == 0) {
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BE610-SKIP #{} obj={:08X} (null device)", n, obj);
    ctx.r3.u32 = 0;
    return;
  }
  if (n <= 24 || (n % 200) == 0 || h == 0x7E780000u)
    MCLA_LOG_WARN("BE610 #{} obj={:08X} dev={:08X} h={:08X}", n, obj, dev, h);
  __imp__sub_821BE610(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821BDD28);
static std::atomic<uint32_t> s_hBDD28{0};
PPC_FUNC(sub_821BDD28) {
  const uint32_t n = s_hBDD28.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0, h = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  if (dev == 0) {
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BDD28-SKIP #{} obj={:08X} (null device)", n, obj);
    return;
  }
  if (n <= 24 || (n % 200) == 0 || h == 0x7E780000u)
    MCLA_LOG_WARN("BDD28 #{} obj={:08X} dev={:08X} h={:08X}", n, obj, dev, h);
  __imp__sub_821BDD28(ctx, base);
}

// BE0C8: r4 is the vtable object; r3 is the path (or vice versa after prologue).
// Crash T8b/T9a: stack path ends up in the vtable slot.
PPC_FUNC_IMPL(__imp__sub_821BE0C8);
static std::atomic<uint32_t> s_hBE0C8{0};
PPC_FUNC(sub_821BE0C8) {
  const uint32_t n = s_hBE0C8.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  EnsureMemoryDeviceVtable();
  uint32_t r3 = ctx.r3.u32, r4 = ctx.r4.u32, r5 = ctx.r5.u32;
  uint32_t w3 = 0, w4 = 0, slot4 = 0;
  if (r3) (void)mem.ReadU32BE(r3, &w3);
  if (r4) (void)mem.ReadU32BE(r4, &w4);
  if (w4 == kMemVtable)
    (void)mem.ReadU32BE(w4 + 4, &slot4);
  char pth[96] = {0};
  // Path is whichever pointer is NOT the device object.
  const uint32_t pathG = (r4 == kMemDeviceObj) ? r3 : r4;
  if (pathG != 0 && pathG != 0xCDCDCDCDu)
    (void)mem.ReadBytes(pathG, pth, sizeof(pth) - 1);
  MclaSanitizePath(pth, sizeof(pth));
  // Empty path â†’ GetSize/CB740 never produced "memory:$â€¦". Invent the
  // re-open string from the known CRT blob so BE0C8 can call AFB8 cleanly.
  // Stack is ~0x8E...... (ABOVE image 0x82......) â€” don't gate on <0x82000000.
  if (pth[0] == 0 && pathG != 0 && pathG != 0xFFFFFFFFu) {
    uint32_t buf = 0, size = 0;
    if (!EmbeddedListLookup("fxl_final/rage_im.fxc", &buf, &size)) {
      buf = 0x827D2DD0u;
      size = 5258u;
    }
    char fix[128] = {0};
    std::snprintf(fix, sizeof(fix), "memory:$%08X,%u,0:fxl_final/rage_im.fxc",
                  buf, size);
    mem.WriteBytes(pathG, fix, static_cast<uint32_t>(std::strlen(fix) + 1));
    MCLA_LOG_WARN("BE0C8-FIX #{} wrote '{}' @{:08X}", n, fix, pathG);
    std::strncpy(pth, fix, sizeof(pth) - 1);
  }
  if (pth[0] == 0) {
    MCLA_LOG_WARN("BE0C8-SKIP #{} r3={:08X} r4={:08X} empty path lr={:08X}",
                  n, r3, r4, static_cast<uint32_t>(ctx.lr));
    ctx.r3.u32 = 0;
    return;
  }
  MCLA_LOG_WARN("BE0C8 #{} r3={:08X}[{:08X}] r4={:08X}[{:08X}] vt+4={:08X} "
                "pth='{}' r5={} lr={:08X}",
                n, r3, w3, r4, w4, slot4, pth, r5,
                static_cast<uint32_t>(ctx.lr));
  // Host-complete the re-open: guest bctrlâ†’AFB8 with this stack path AVed
  // (function-table lookup null / 0x0). Return the buffer handle ourselves.
  uint32_t mb = 0, ms = 0;
  if (ParseMemoryDollar(pth, &mb, &ms) && mb != 0) {
    const uint32_t st = MakeMemoryStream(kMemDeviceObj, mb, ms);
    MCLA_LOG_WARN("BE0C8-RET stream={:08X} buf={:08X} size={}", st, mb, ms);
    // F-155 MEASURED AND REJECTED: returning a guest-native stream OBJECT here
    // (dev=kMemDeviceObj 0x827D838C, +4=slot index, +8=buf, +28/+32=size) does
    // remove the fault the way F-150/F-151 predicted - C0000005 1->0, SEEK-DEAD
    // 1->0, Fatal/FATAL-SOFT still 0 - and it also loses ground, identically in
    // three independent builds: LISTLINE 171->167 (the four embedded:/rage_* and
    // rmptfx_collision entries F-135 recovers are the last four and stop
    // appearing), TYPINIT 1->0, FACTORY 1->0, DICTLOOKUP 14->2, PATHMGR-OPEN
    // 61->60. w164 = object + writes at 0x82861740 on F-154's "second handle
    // table" theory; F-155 then measured that theory FALSE (no instruction pair
    // in mcla_pe.bin forms 0x82861740 at all - the only handle-table base in the
    // image is 0x82860740, addis at 0x821CAF50), so w165 re-ran the object with
    // those writes gone and w166 with the guest-heap footprint cut from 167
    // allocations to one pooled block. All three score the same loss, so neither
    // the writes nor the heap churn was the confound: the INDEX is what this
    // branch's consumers need, and the object shape is not the fix.
    // F-155 also corrects F-150/F-151's account of the fault. ppc_recomp.10.cpp
    // :10912-10993 shows sub_82191040 doing `mr r31,r3` after the
    // sub_821BE8D8 call - NOT after the open - and then using r31 as a stream
    // object at four sites (sub_821BE4F0 kind byte, sub_821CF7B8 reader-ctor arg
    // r5, sub_821BE610, sub_821BE568 Seek). So the object that is missing is
    // sub_821BE8D8's return value (w161 BE8D8-HOST prints it as stream=00000001,
    // alongside a dst=CBE40280 buffer it filled), not this function's.
    // F-162 narrows that: the object IS wanted, but only by the one caller that
    // dereferences it (sub_82191040, latched by the sub_821BE8D8 hook above).
    // Building it here serves that caller's contract while leaving the other 178
    // re-opens on the index shape they store as a handle.
    if (s_reopenWantsObject && st >= 1u && st < kGuestSlotCount) {
      s_reopenWantsObject = false;  // exactly the latched call
      static uint32_t s_objPool = 0;
      if (s_objPool == 0)
        s_objPool = mem.Alloc(kGuestSlotCount * 64, 16);  // one touch, ever
      const uint32_t o = s_objPool != 0 ? s_objPool + st * 64u : 0;
      if (o != 0) {
        for (uint32_t q = 0; q < 64; q += 4)
          (void)mem.WriteU32BE(o + q, 0);
        (void)mem.WriteU32BE(o + 0, kMemDeviceObj);  // +0  device
        (void)mem.WriteU32BE(o + 4, st);             // +4  handle = slot index
        (void)mem.WriteU32BE(o + 8, mb);             // +8  buffer
        (void)mem.WriteU32BE(o + 28, ms);            // +28 end
        (void)mem.WriteU32BE(o + 32, ms);            // +32 cap
        MCLA_LOG_WARN("BE0C8-OBJ #{} obj={:08X} dev={:08X} h={} buf={:08X} "
                      "size={} lr={:08X}",
                      n, o, kMemDeviceObj, st, mb, ms,
                      static_cast<uint32_t>(ctx.lr));
        ctx.r3.u32 = o;
        return;
      }
      MCLA_LOG_WARN("BE0C8-OBJ-FAIL #{} pool=0, returning index {}", n, st);
    }
    ctx.r3.u32 = st;
    return;
  }
    __imp__sub_821BE0C8(ctx, base);
}

// Shared no-op vtable stub (li r3,0; blr). 8C760 calls device+88 after
// GETDEV; if the function-table slot is null we AV at 0x0. Strong override.
PPC_FUNC_IMPL(__imp__sub_821A5CC0);
// F-178: F-177 inferred that pgStreamer::Open's size query (vtable slot +84 on
// the `memory:` device) lands here and is answered 0 because of this override.
// That inference is only citable once measured, and the address cannot
// distinguish the thirteen slots that share it - so tally by `lr`, which does.
// Bounded by construction: one line per newly-seen `lr` (max 16) and the first
// 12 calls, so a hot stub cannot flood the log (F-057(6)/F-125).
PPC_FUNC(sub_821A5CC0) {
  static std::mutex s_stubMtx;
  static uint32_t s_stubSeen = 0;
  static uint32_t s_stubLrs = 0;
  static uint32_t s_stubLr[16] = {0};
  static uint32_t s_stubCount[16] = {0};
  static std::atomic<uint32_t> s_stubCalls{0};
  const uint32_t n = s_stubCalls.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  const uint32_t r3 = ctx.r3.u32, r4 = ctx.r4.u32, r5 = ctx.r5.u32;
  bool fresh = false;
  int slot = -1;
  {
    std::lock_guard<std::mutex> g(s_stubMtx);
    s_stubSeen = n;
    for (uint32_t i = 0; i < s_stubLrs; ++i)
      if (s_stubLr[i] == lr) {
        slot = static_cast<int>(i);
        break;
      }
    if (slot < 0 && s_stubLrs < 16) {
      slot = static_cast<int>(s_stubLrs++);
      s_stubLr[slot] = lr;
      fresh = true;
    }
    if (slot >= 0)
      ++s_stubCount[slot];
  }
  if (fresh)
    MCLA_LOG_WARN("STUB-SLOT #{} lr={:08X} r3={:08X} r4={:08X} r5={:08X} "
                  "(new caller; the slot this call came through is not knowable "
                  "from this address)",
                  n, lr, r3, r4, r5);
  else if (n <= 12)
    MCLA_LOG_INFO("STUB-SLOT call #{} lr={:08X} r3={:08X}", n, lr, r3);
  if (slot >= 0 && (n % 4096u) == 0u) {
    std::string tail;
    {
      std::lock_guard<std::mutex> g(s_stubMtx);
      for (uint32_t i = 0; i < s_stubLrs; ++i)
        tail += fmt::format("{}{:08X}:{}", (i ? " " : ""), s_stubLr[i],
                            s_stubCount[i]);
    }
    MCLA_LOG_WARN("STUB-SLOT-TALLY #{} lr_capped_at_16 [{}]", n, tail);
  }
  ctx.r3.u32 = 0;
}

// After 8C760 accepts the rgxa magic, D3070(bufobj, size) runs with r3=0.
// Guard the null object.
PPC_FUNC_IMPL(__imp__sub_821D3070);
static std::atomic<uint32_t> s_hD3070{0};
PPC_FUNC(sub_821D3070) {
  const uint32_t n = s_hD3070.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  uint32_t field8 = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu)
    (void)mem.ReadU32BE(obj + 8, &field8);
  // 8C760 magic-accept path does ori r4,r4,0x8000 then D3070 — original
  // pulls r3 from TLS[+28] and AVs when that is null (0x7e780000).
  // F-062: the r4 test must NOT be part of the skip condition. The star_glow
  // shader buffer call arrives as obj=8EFFEE20 +8=CA71D5A8 r4=00008000
  // lr=8218C89C (w38r.log:3937) — a VALID object and a valid block pointer —
  // and skipping it left the shader with no buffer, so sub_822FBAF8 never
  // returned and the [0x8287E26C] singleton was never created (F-061). The
  // guard exists only for the unusable-object case; keep it to that.
  const bool fromMagic = (ctx.r4.u32 & 0x8000u) != 0 &&
                         (ctx.lr == 0x8218C89Cu ||
                          static_cast<uint32_t>(ctx.lr) == 0x8218C89Cu);
  // F-063 re-applied (it was lost with E:'s working tree on 2026-09-21 00:54;
  // see C:\mcla-pc\docs\HANDOFF_NEXT_AGENT.md): bit 15 of r4 is a FLAG the
  // 8C760 magic-accept path ORs in, not a size, so skipping on it starved the
  // shader's own 32 KB buffer. The other clauses (null obj / null +8) stay.
  if (obj == 0 || obj == 0xCDCDCDCDu || field8 == 0 || field8 == 0xCDCDCDCDu) {
    if (n <= 16 || fromMagic)
      MCLA_LOG_WARN("D3070-SKIP #{} obj={:08X} +8={:08X} r4={:08X} lr={:08X}",
                    n, obj, field8, ctx.r4.u32,
                    static_cast<uint32_t>(ctx.lr));
    ctx.r3.u32 = 0;
    return;
  }
  if (fromMagic && n <= 16)
    MCLA_LOG_WARN("D3070-RUN #{} obj={:08X} +8={:08X} r4={:08X} lr={:08X}",
                  n, obj, field8, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_821D3070(ctx, base);
}

// ---------------------------------------------------------------------------
// F-142 CENSUS ONLY (read-only; rule 4 checked first: addr_owners --check
// 0x82193AF8 reported only ppc_func_mapping.cpp:2764, no owner).
// sub_82193AF8(group=r3, name=r4, required=r5) is the guest's shader-group
// variable binding (F-136): it walks lhz [group+12] entries of the array at
// [group+8], resolving each entry's +20 word against `name`, and raises
// "Required grmShaderGroupVar '%s' not found." when the flag is set and nothing
// matched. That leaves two very different worlds and the plan branches on them:
// the group HAS variables but none named skinningData (content, F-136's raw
// measurement) versus the group has NO variables (our serve/parse). Print the
// count and the names the guest actually sees.
PPC_FUNC_IMPL(__imp__sub_82193AF8);
static std::atomic<uint32_t> s_h93AF8{0};
PPC_FUNC(sub_82193AF8) {
  const uint32_t n = s_h93AF8.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t group = ctx.r3.u32;
  const uint32_t nameA = ctx.r4.u32;
  const uint32_t req = ctx.r5.u32 & 0xFFu;
  const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);
  // w150 printed ZERO of these while the fatal *inside* this function printed
  // twice, and the only filter was `group != 0` - so a null/poison group is
  // itself the leading candidate. Log unconditionally, including r3 == 0.
  if (n <= 80) {
    uint32_t vt = 0, arr = 0, cntW = 0;
    (void)mem.ReadU32BE(group + 0, &vt);
    (void)mem.ReadU32BE(group + 8, &arr);
    (void)mem.ReadU32BE(group + 12, &cntW);  // +12 halfword, +14 next field
    const uint32_t nvars = cntW & 0xFFFFu;
    char want[33] = {0};
    {
      unsigned char raw[32] = {0};
      (void)mem.ReadBytes(nameA, raw, 32u);
      int j = 0;
      for (; j < 32 && raw[j]; ++j)
        want[j] = (raw[j] >= 32u && raw[j] < 127u) ? (char)raw[j] : '?';
      want[j] = 0;
    }
    char first[33] = {0}, second[33] = {0};
    uint32_t e0 = 0, e1 = 0, n0 = 0, n1 = 0;
    if (arr && nvars > 0) {
      (void)mem.ReadU32BE(arr + 0, &e0);
      if (e0 && e0 != 0xCDCDCDCDu) {
        (void)mem.ReadU32BE(e0 + 20, &n0);
        if (n0 && n0 != 0xCDCDCDCDu) {
          unsigned char raw[32] = {0};
          (void)mem.ReadBytes(n0, raw, 32u);
          int j = 0;
          for (; j < 32 && raw[j]; ++j)
            first[j] = (raw[j] >= 32u && raw[j] < 127u) ? (char)raw[j] : '?';
          first[j] = 0;
        }
      }
      if (nvars > 1) {
        (void)mem.ReadU32BE(arr + 4, &e1);
        if (e1 && e1 != 0xCDCDCDCDu) {
          (void)mem.ReadU32BE(e1 + 20, &n1);
          if (n1 && n1 != 0xCDCDCDCDu) {
            unsigned char raw[32] = {0};
            (void)mem.ReadBytes(n1, raw, 32u);
            int j = 0;
            for (; j < 32 && raw[j]; ++j)
              second[j] = (raw[j] >= 32u && raw[j] < 127u) ? (char)raw[j] : '?';
            second[j] = 0;
          }
        }
      }
    }
    MCLA_LOG_WARN("SHGRP-VARS #{} group={:08X} vt={:08X} arr={:08X} nvars={} "
                  "req={} want='{}' e0={:08X}/'{}' e1={:08X}/'{}' lr={:08X}",
                  n, group, vt, arr, nvars, req, want, e0, first, e1, second,
                  lrIn);
  }
  __imp__sub_82193AF8(ctx, base);
}

// ---------------------------------------------------------------------------
// F-143 CENSUS ONLY (read-only; rule 4 checked first: addr_owners --check
// 0x826113A8 → only ppc_func_mapping.cpp:31569, no owner).
// The group that w151's SHGRP-VARS saw as 0 is NOT the object
// sub_82379C68 allocates — it is `[allocatedObject+8]` (ppc_recomp.58.cpp:3997
// `lwz r3,8(r11)` with r11 = [0x8288E054]). The ctor sub_82611298 stores 0
// there by construction (ppc_recomp.123.cpp:14366 `stw r11,8(r31)`, r11 = 0),
// so the only thing that can fill it is the virtual at vtable 0x82089568,
// i.e. sub_826113A8 — which is also the function sub_82379C68 calls at
// 0x82379CC4 and whose return value it then *discards*. Inside it,
// sub_821CA6A8(0x827D7770, "entity.type", "type", 0, 1) is the parent-type
// lookup, and if that returns 0 the function takes `li r3,0; return` at
// loc_8261143C without ever reaching the vtable+16 realize. That fork —
// parent lookup failed vs realize ran but did not publish +8 — is what this
// prints. Name the three vtables holding this slot: 0x82054928, 0x82089568,
// 0x8211e778 (raw scan of build/cache/mcla_pe.bin for the word 0x826113A8).
PPC_FUNC_IMPL(__imp__sub_826113A8);
static std::atomic<uint32_t> s_h6113A8{0};
PPC_FUNC(sub_826113A8) {
  const uint32_t n = s_h6113A8.fetch_add(1) + 1;
  const bool show = n <= 24;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t self = ctx.r3.u32;
  const uint32_t nm = ctx.r4.u32;
  const uint32_t a5 = ctx.r5.u32, a6 = ctx.r6.u32;
  const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);
  uint32_t vt = 0, f8 = 0, f12 = 0, mgrCnt = 0, mgrBase = 0, obj = 0;
  char name[49] = {0};
  if (show) {
    (void)mem.ReadU32BE(self + 0, &vt);
    (void)mem.ReadU32BE(self + 8, &f8);
    (void)mem.ReadU32BE(self + 12, &f12);
    (void)mem.ReadU32BE(0x827D7770u + 3072, &mgrBase);
    (void)mem.ReadU32BE(0x827D7770u + 3076, &mgrCnt);
    (void)mem.ReadU32BE(0x8288E054u, &obj);
    unsigned char raw[48] = {0};
    (void)mem.ReadBytes(nm, raw, 48u);
    int j = 0;
    for (; j < 48 && raw[j]; ++j)
      name[j] = (raw[j] >= 32u && raw[j] < 127u) ? (char)raw[j] : '?';
    name[j] = 0;
    MCLA_LOG_WARN("TYPINIT #{} self={:08X} vt={:08X} +8={:08X} +12={:08X} "
                  "name='{}' r5={:08X} r6={:08X} mgr=[{:08X}] cnt={} "
                  "obj@[8288E054]={:08X} lr={:08X}",
                  n, self, vt, f8, f12, name, a5, a6, mgrBase, mgrCnt, obj,
                  lrIn);
  }
  __imp__sub_826113A8(ctx, base);
  if (show) {
    uint32_t post8 = 0;
    (void)mem.ReadU32BE(self + 8, &post8);
    MCLA_LOG_WARN("TYPINIT-RET #{} self={:08X} -> r3={:08X} +8={:08X}", n,
                  self, ctx.r3.u32, post8);
  }
}

// ---------------------------------------------------------------------------
// F-145 CENSUS ONLY (read-only; rule 4 checked first: addr_owners --check
// 0x821CFE80 → only ppc_func_mapping.cpp:4506, no owner).
// w154 showed the entity.type file OPENING (PATHMGR-OPEN #406
// a:/archive/vehicle/shared_utility/sst_trail/entity.type → the same static
// stream object the loading .list files return), so sub_821CA6A8 succeeded,
// sub_826113A8 did not take its early exit, and the r3 = 0 that leaves
// [object+8] at the ctor's zero came out of the realize sub_82611018. Its first
// gate is `sub_821CFE80(r3 = &temp, r4 = 0x82089564, r5 = 0)` with
// `(r3 & 0xFF) == 0` jumping straight to `return 0` - and it is the only one of
// that function's checks that can fail without any I/O, which is what w154's
// open→return adjacency looks like. Gating on lr == 0x82611048 (the `bl` inside
// sub_82611018, ppc_recomp.123.cpp:13929) keeps a generic helper quiet; r3 is
// the &temp the caller built, so its vtable and +4 are readable directly.
PPC_FUNC_IMPL(__imp__sub_821CFE80);
static std::atomic<uint32_t> s_hRealizeCast{0};
PPC_FUNC(sub_821CFE80) {
  const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);
  const bool show = lrIn == 0x82611048u && s_hRealizeCast.fetch_add(1) < 24;
  const uint32_t obj = ctx.r3.u32, ti = ctx.r4.u32, flag = ctx.r5.u32;
  uint32_t vt = 0, w4 = 0;
  if (show) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(obj + 0, &vt);
    (void)mem.ReadU32BE(obj + 4, &w4);
  }
  const uint32_t r1In = ctx.r1.u32;
  __imp__sub_821CFE80(ctx, base);
  if (show) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    // Reader layout is settled by its constructor sub_821CF7B8
    // (ppc_recomp.17.cpp:11858): +4 = name, +12 = the stream the lookup handed
    // back, +16 = current char (initialised to 32), +24 = buffer count (0),
    // +20 = 2, +8 = 1, +28 = 0, +540 = 0. sub_821CFAA8 (the [vt+8] tokeniser)
    // indexes reader+count for the buffered bytes, so the reader's own payload
    // starts at reader+32 - which is what the guest actually saw of
    // entity.type. Printing it separates "we served ciphertext" (F-129 defect 2:
    // MarkMemberExpanded covers the three .list spans and nothing else) from
    // "we served text whose first keyword is not Version:".
    uint32_t strm = 0, b8 = 0, c16 = 0, n24 = 0, mode20 = 0;
    (void)mem.ReadU32BE(obj + 8, &b8);
    (void)mem.ReadU32BE(obj + 12, &strm);
    (void)mem.ReadU32BE(obj + 16, &c16);
    (void)mem.ReadU32BE(obj + 20, &mode20);
    (void)mem.ReadU32BE(obj + 24, &n24);
    uint8_t raw[32] = {0};
    (void)mem.ReadBytes(obj + 32, raw, 32u);
    char asc[33] = {0};
    for (int j = 0; j < 32; ++j)
      asc[j] = (raw[j] >= 32u && raw[j] < 127u) ? (char)raw[j] : '.';
    uint8_t tok[16] = {0};
    (void)mem.ReadBytes(r1In - 560u, tok, 16u);
    char tokAsc[17] = {0};
    for (int j = 0; j < 16 && tok[j]; ++j)
      tokAsc[j] = (tok[j] >= 32u && tok[j] < 127u) ? (char)tok[j] : '.';
    MCLA_LOG_WARN("REALIZE-CAST obj={:08X} vt={:08X} name={:08X} stream={:08X} "
                  "+8={} +20={} cur={:02X} cnt={} key={:08X} flag={} -> r3={:08X} "
                  "(byte={}) buf='{}' hex={:02X} {:02X} {:02X} {:02X} {:02X} "
                  "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} | tok='{}'",
                  obj, vt, w4, strm, b8, mode20, c16 & 0xFFu, n24, ti, flag,
                  ctx.r3.u32, ctx.r3.u32 & 0xFFu, asc, raw[0], raw[1], raw[2],
                  raw[3], raw[4], raw[5], raw[6], raw[7], raw[8], raw[9],
                  raw[10], raw[11], tokAsc);
    // F-148: F-147 left one thing unresolved - whether the wrapper this reader
    // was given was actually loaded with entity.type bytes. 0x82860C40 is a
    // *static* image-.data object from F-122's trio and is reused (BE710-SLOT
    // has 978 firings on it), so apply F-122's own dead-wrapper test to it
    // here: guest-native buffered shape is +0 device, +4 handle, +8 buf, +24
    // cur, +28 end, +32 cap. Live device + end>cur means a real read happened
    // and the problem is the body's content; a dead +0 means the guest
    // tokenised leftovers, which is the F-127/F-128 bind-and-serve defect on a
    // new path.
    if (strm && strm != 0xCDCDCDCDu) {
      uint32_t d0 = 0, h4 = 0, bf8 = 0, c24 = 0, e28 = 0, k32 = 0;
      (void)mem.ReadU32BE(strm + 0, &d0);
      (void)mem.ReadU32BE(strm + 4, &h4);
      (void)mem.ReadU32BE(strm + 8, &bf8);
      (void)mem.ReadU32BE(strm + 24, &c24);
      (void)mem.ReadU32BE(strm + 28, &e28);
      (void)mem.ReadU32BE(strm + 32, &k32);
      MCLA_LOG_WARN("REALIZE-WRAP reader={:08X} wrap={:08X} dev={:08X} h={:08X} "
                    "buf={:08X} cur={:08X} end={:08X} cap={:08X} avail={}",
                    obj, strm, d0, h4, bf8, c24, e28, k32,
                    (int32_t)(e28 - c24));
    }
  }
}

// ---------------------------------------------------------------------------
// F-150 CENSUS ONLY (read-only; rule 4 checked first: addr_owners --check
// 0x821BE568 → only ppc_func_mapping.cpp:3836, no owner).
// w160's single C0000005 (which F-149's entity.type expansion exposed) is
// sub_821BE568 - a buffered-stream Seek - executing loc_821BE5D0:
//   lwz r3,0(r31) ; lwz r4,4(r31) ; lwz r11,0(r3) ; lwz r10,44(r11) ; bctrl
// i.e. it loads the DEVICE out of [stream+0], the HANDLE out of [stream+4], and
// dereferences the device's vtable. The fault context matches that instruction
// exactly (r3=0 from [stream+0], r4=0 from [stream+4], lr=0x821BE5F4 = the bctrl
// site, faulting guest address 0). So the stream object is live but unbound -
// the same dead-wrapper shape F-122 fixed for the READ path (sub_821BE250),
// which this Seek path has no equivalent for. r14-r31 are host locals
// (F-113), so the VEH dump cannot name r31; print it here, with the object's own
// buffered fields, but only for objects that are actually unbound so the marker
// stays rare enough to read.
PPC_FUNC_IMPL(__imp__sub_821BE568);
static std::atomic<uint32_t> s_hSeekDead{0};
PPC_FUNC(sub_821BE568) {
  const uint32_t obj = ctx.r3.u32;
  const uint32_t pos = ctx.r4.u32;
  const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);
  bool dead = false;
  uint32_t dev = 0, h = 0, cur = 0, en = 0, cap = 0;
  // Seek is a hot path, and F-125 says a census that perturbs timing is not
  // citable: pay exactly one checked read per call, and only resolve the rest of
  // the object for the rare unbound case.
  if (obj && obj != 0xCDCDCDCDu) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(obj + 0, &dev);
    dead = (dev == 0u || dev == 0xCDCDCDCDu || dev == 0xFFFFFFFFu);
    if (dead) {
      (void)mem.ReadU32BE(obj + 4, &h);
      (void)mem.ReadU32BE(obj + 24, &cur);
      (void)mem.ReadU32BE(obj + 28, &en);
      (void)mem.ReadU32BE(obj + 32, &cap);
    }
  } else {
    dead = true;
  }
  if (dead && s_hSeekDead.fetch_add(1) < 24) {
    MCLA_LOG_WARN("SEEK-DEAD obj={:08X} dev={:08X} h={:08X} cur={} end={:08X} "
                  "cap={:08X} seekto={:08X} lr={:08X}",
                  obj, dev, h, cur, en, cap, pos, lrIn);
  }
  __imp__sub_821BE568(ctx, base);
}

// F-160 census: the guest's OWN handle-release routine. Decoded from
// build/cache/mcla_pe.bin at 0x821CB2A0: reject h < 0 or h >= 16
// (cmpi 0 / cmpi 16 at 821CB2B0-821CB2BC - so the 16-entry bound is the guest's,
// not our constant), index 0x82860740 + h*16 (rlwinm sh=4 then
// `lis 8286 / addi 1856` at 821CB2C0-821CB2C8), reject when [entry+0] == 0, and
// when the BYTE at [entry+12] is non-zero call 821BBEA8/82130588/821BBF00 on
// [entry+0] (a free), then unconditionally `stw r11,0(r31)` with r11=0 and
// return 0. That last store is the only thing in the image that releases a
// slot. So if this never fires for a host-served handle, the leak that F-135's
// SLOT-RECYCLE tiers paper over is entirely ours.
// Read-only census (rule 1): prints state, calls the original through.
PPC_FUNC_IMPL(__imp__sub_821CB2A0);
static std::atomic<uint32_t> s_hCB2A0{0};
PPC_FUNC(sub_821CB2A0) {
  const uint32_t n = s_hCB2A0.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t h = ctx.r4.u32;
  uint32_t buf = 0, size = 0, pos = 0, flag = 0;
  if (h < kGuestSlotCount) {
    const uint32_t slot = kGuestSlotTable + h * 16;
    (void)mem.ReadU32BE(slot + 0, &buf);
    (void)mem.ReadU32BE(slot + 4, &size);
    (void)mem.ReadU32BE(slot + 8, &pos);
    (void)mem.ReadU32BE(slot + 12, &flag);
  }
  if (n <= 40 || (n % 500) == 0)
    MCLA_LOG_WARN("SLOT-CLOSE #{} r3={:08X} h={} slot=[buf={:08X},size={},"
                  "pos={},flag={:02X}] lr={:08X}",
                  n, ctx.r3.u32, h, buf, size, pos, flag & 0xFFu,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821CB2A0(ctx, base);
}

// Stream read: [obj+0] must be a live device. Dead wrapper â†’ serve bytes from
// the wrapper fields ourselves (MakeMemoryStream layout) so factory reads get
// real data instead of -1 (which cascaded into AF68's cap=-1 AV).
PPC_FUNC_IMPL(__imp__sub_821BE250);
static std::atomic<uint32_t> s_hBE250{0};
PPC_FUNC(sub_821BE250) {
  const uint32_t n = s_hBE250.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t dst = ctx.r4.u32;
  const uint32_t count = ctx.r5.u32;
  uint32_t dev = 0, h = 0;
  if (obj && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  // p2d rgxa fix: live memory-device wrapper whose handle is one of our
  // slot indices — serve from the slot table directly (821CB158 contract).
  // The original body's buffered-refill path reads uninitialized wrapper
  // fields (+8/+24/+28/+32) and serves wrong bytes ("Old version" fatal).
  if (dev == kMemDeviceObj && h != 0 && h < kGuestSlotCount) {
    const int64_t served = SlotTableServeRead(h, dst, count);
    if (served >= 0) {
      if (n <= 24 || (n % 200) == 0)
        MCLA_LOG_WARN("BE250-SLOT #{} obj={:08X} h={} served={} count={}",
                      n, obj, h, served, count);
      ctx.r3.u32 = static_cast<uint32_t>(served);
      return;
    }
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BE250-SLOT-MISS #{} obj={:08X} h={} count={}", n, obj, h,
                    count);
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  if (dev == 0 || dev == 0xCDCDCDCDu) {
    const int64_t served =
        MemoryStreamServeRead(obj, dst, count, static_cast<uint32_t>(ctx.lr));
    if (served >= 0) {
      if (n <= 24 || (n % 200) == 0)
        MCLA_LOG_WARN("BE250-MEM #{} obj={:08X} served={} count={} posfield=+24",
                      n, obj, served, count);
      ctx.r3.u32 = static_cast<uint32_t>(served);
      return;
    }
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BE250-SKIP #{} obj={:08X} dev={:08X}", n, obj, dev);
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  // T41.3s (F-106 follow-on) census, log-only: the fall-through hands control to
  // the guest's real Read(), whose buffered-refill path dereferences wrapper
  // +8/+24/+28/+32. With the archive expansion on (w80) that path faulted on a
  // host AV reading guest 0xE17 (obj=82860C68, a sibling of the 82860C18 wrapper
  // our post-open serve binds). Print the fields so the bad slot is named by the
  // soak instead of by an exception.
  if (n <= 40 || (n % 200) == 0) {
    uint32_t f8 = 0, f16 = 0, f24 = 0, f28 = 0, f32 = 0;
    (void)mem.ReadU32BE(obj + 8, &f8);
    (void)mem.ReadU32BE(obj + 16, &f16);
    (void)mem.ReadU32BE(obj + 24, &f24);
    (void)mem.ReadU32BE(obj + 28, &f28);
    (void)mem.ReadU32BE(obj + 32, &f32);
    MCLA_LOG_WARN("BE250-GUEST #{} obj={:08X} dev={:08X} h={} dst={:08X} "
                  "count={} +8={:08X} +16={:08X} +24={:08X} +28={:08X} "
                  "+32={:08X} lr={:08X}",
                  n, obj, dev, h, dst, count, f8, f16, f24, f28, f32,
                  static_cast<uint32_t>(ctx.lr));
    // T41.3s2 census: w80's AV read guest 0x00000E17, and F-107 left the question
    // "which field holds it". Dump the whole object (and the healthy wrapper the
    // post-open serve does bind) so the offset comes from the soak.
    {
      constexpr uint32_t kBoundWrapper = 0x82860C18u;  // XSF-POSTOPEN-SERVE's obj
      std::string w, ref;
      for (int k = 0; k < 24; ++k) {
        uint32_t v = 0;
        (void)mem.ReadU32BE(obj + k * 4u, &v);
        w += fmt::format("{:08X} ", v);
      }
      for (int k = 0; k < 24; ++k) {
        uint32_t v = 0;
        (void)mem.ReadU32BE(kBoundWrapper + k * 4u, &v);
        ref += fmt::format("{:08X} ", v);
      }
      MCLA_LOG_WARN("BE250-OBJ #{} obj={:08X} words=[{}] boundWrapper={:08X} "
                    "words=[{}]",
                    n, obj, w, kBoundWrapper, ref);
    }
  }
  __imp__sub_821BE250(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821BE710);
static std::atomic<uint32_t> s_hBE710{0};
PPC_FUNC(sub_821BE710) {
  const uint32_t n = s_hBE710.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  uint32_t dev = 0, h = 0;
  if (obj && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  // p2d rgxa fix: live memory-device wrapper with a slot-table handle.
  // Original BE710 shifts r5 by 2 (word count) then tails into BE250's
  // buffered machinery, which needs initialized wrapper fields we never
  // set for slot handles — serve from the slot table instead (exact
  // 821CB158 semantics: copy min(count, size-pos), advance slot pos).
  if (dev == kMemDeviceObj && h != 0 && h < kGuestSlotCount) {
    const uint32_t bytes = ctx.r5.u32 * 4u;
    const int64_t served = SlotTableServeRead(h, ctx.r4.u32, bytes, true);
    if (served >= 0) {
      MCLA_LOG_WARN("BE710-SLOT #{} obj={:08X} h={} words={} served={}", n,
                    obj, h, ctx.r5.u32, served);
      ctx.r3.u32 = static_cast<uint32_t>(served) / 4u;
      return;
    }
    MCLA_LOG_WARN("BE710-SLOT-MISS #{} obj={:08X} h={} words={}", n, obj, h,
                  ctx.r5.u32);
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  if (dev == 0 || dev == 0xCDCDCDCDu) {
    auto &mem2 = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t sbuf = 0, ssize = 0;
    if (s_lastMemStream != 0) {
      (void)mem2.ReadU32BE(s_lastMemStream + 4, &sbuf);
      (void)mem2.ReadU32BE(s_lastMemStream + 8, &ssize);
    }
    MCLA_LOG_WARN("BE710-DEAD #{} obj={:08X} lastStream={:08X} sbuf={:08X} "
                  "ssize={} r4={:08X}",
                  n, obj, s_lastMemStream, sbuf, ssize, ctx.r4.u32);
    if (sbuf != 0 && ssize >= 4 && ctx.r4.u32 != 0) {
      // T41.9 census (read-only, F-127 §5): the gate in sub_8218C760 compares the
      // ONE word this call returns against 0x61786772 ('axgr' = rgxa LE). Print
      // what the stream actually holds - at its head and at the cursor - so the
      // question "does the real rage_im body carry the magic, and is our read
      // position wrong?" is answered by the soak instead of by argument.
      {
        uint32_t pos = 0, head = 0, atPos = 0, dstNow = 0;
        (void)mem2.ReadU32BE(s_lastMemStream + 24, &pos);
        (void)mem2.ReadU32BE(sbuf, &head);
        (void)mem2.ReadU32BE(sbuf + (pos < ssize ? pos : 0u), &atPos);
        (void)mem2.ReadU32BE(ctx.r4.u32, &dstNow);
        MCLA_LOG_WARN("BE710-MAGIC-CENSUS #{} obj={:08X} stream={:08X} "
                      "sbuf={:08X} ssize={} pos={} head={:08X} [sbuf+pos]={:08X} "
                      "dst={:08X} dstWordNow={:08X} magic={:08X} r5words={}",
                      n, obj, s_lastMemStream, sbuf, ssize, pos, head, atPos,
                      ctx.r4.u32, dstNow, 0x61786772u, ctx.r5.u32);
        // T41.10 (read-only): is the served body raw DEFLATE, ciphertext, or a
        // container this guest simply never validated? The head word says little
        // without the surrounding bytes, so print 32 of each the way
        // BE8D8-PACK does for list bodies.
        static std::atomic<uint32_t> s_bodyDumped{0};
        if (s_bodyDumped.fetch_add(1) < 6u) {
          uint8_t raw[32] = {0};
          char vis[33] = {0};
          if (mem2.ReadBytes(sbuf, raw, sizeof(raw))) {
            for (int k = 0; k < 32; ++k)
              vis[k] = (raw[k] >= 32u && raw[k] < 127u) ? (char)raw[k] : '.';
          }
          std::string hexb;
          for (int k = 0; k < 32; ++k)
            hexb += fmt::format("{:02X}{}", raw[k], (k % 4 == 3) ? " " : "");
          MCLA_LOG_WARN("BE710-BODY #{} sbuf={:08X} size={} bytes=[{}] "
                        "ascii='{}'",
                        n, sbuf, ssize, hexb, vis);
        }
      }
      // MITIGATION, load-bearing (F-127): the guest's rage-effect gate at
      // sub_8218C760 reads ONE word through sub_821BE710 and requires it to be
      // 0x61786772 ('axgr' = the rgxa magic, LE) before loc_8218C878; anything
      // else is the fatal 'Old version of rage effect found. You need to
      // recompile your shaders!' (lr=8218C864, reached for the first time in
      // w117/w124/w125 once real archive .fxc bodies were served). This write
      // is what lets the current frontier past that gate. Conversion target:
      // make the rage_im stream itself deliver the magic at the read position.
      // T41.9b: set false (one soak) to prove the prop is load-bearing.
      constexpr bool kBe710MagicWrite = true;   // false = w130 (T41.9b control)
      if (kBe710MagicWrite) {
        mem2.WriteU32BE(ctx.r4.u32, 0x61786772u);
        MCLA_LOG_WARN("BE710-MAGIC #{} wrote 61786772", n);
      } else {
        MCLA_LOG_WARN("BE710-MAGIC-OFF #{} obj={:08X} dst={:08X} — withheld "
                      "(diagnostic, guest gets the stream's own bytes)",
                      n, obj, ctx.r4.u32);
      }
      ctx.r3.u32 = 1;
      return;
    }
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  if (n <= 16 || (n % 200) == 0)
    MCLA_LOG_WARN("BE710 #{} obj={:08X} dev={:08X} h={:08X} r5={}", n, obj, dev,
                  h, ctx.r5.u32);
  __imp__sub_821BE710(ctx, base);
}

// ===========================================================================
// T5-next (t23a frontier): atArray ctor guards - sub_8218AF68 (16-byte
// stride) and sub_82189F00 (32-byte stride).
//
// Shared ABI (ppc_recomp.9.cpp:14521 / :11806): r3=obj, r4=count, r5=cap.
//   sth count -> obj+4 ; sth cap -> obj+6
//   r10 = *(r13)                       <- TLS table (WIPED at runtime:
//                                         park sample tls0=00000000)
//   r3  = *(r10+12)                    <- slot +12 allocator descriptor
//   r11 = *(r3) ; ctr = *(r11+8) ; bctrl   <- alloc(cap*stride, align 16)
//   *(obj+0) = alloc result; then count entries field-zeroed (16B: [+8]=0;
//   32B: +4/+8/+20/+24=0, +28/+30=0xFFFF).
//
// Faults observed (boot_stdout_t22a.log, t23a.log):
//   1. bctrl through ctr=0 (TLS wiped) -> PPC_LOOKUP_FUNC(0) -> host AV
//      0x7E780000 (that "wild pointer" is literally lookup-of-guest-0).
//   2. Caller 8C1C0 passes count/cap = -1 (0xFFFFFFF0) because the upstream
//      ReadByte chain got -1 from the dead stream -> count/cap poison.
//
// Guard: null obj -> return; insane count/cap (>0x8000, covers -1) -> empty
// array; TLS wiped -> host-complete the ctor faithfully.
// ===========================================================================
PPC_FUNC_IMPL(__imp__sub_8218AF68);
static std::atomic<uint32_t> s_hAF68{0};

// Shared guard body. entryBytes = 16 or 32. Returns true when handled.
static bool AtArrayCtorGuard(PPCContext &__restrict ctx, uint32_t n,
                             uint32_t entryBytes) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);

  if (obj == 0 || obj == 0xCDCDCDCDu) {
    MCLA_LOG_WARN("ATARRAY-SKIP #{} null obj lr={:08X}", n, lr);
    return true;
  }

  // Count/cap live in the low 16 bits of r4/r5 (sth stores). -1 -> 0xFFFF.
  const uint32_t countRaw = ctx.r4.u32 & 0xFFFFu;
  const uint32_t capRaw = ctx.r5.u32 & 0xFFFFu;

  // Poisoned args (from BE250 -1 upstream): empty array. Also require
  // count<=cap; count>cap with cap-sized alloc is a heap overflow.
  if (countRaw > 0x8000u || capRaw > 0x8000u || countRaw > capRaw) {
    MCLA_LOG_WARN("ATARRAY-CLAMP #{} obj={:08X} count={:04X} cap={:04X} "
                  "stride={} lr={:08X} (poisoned args, empty array)",
                  n, obj, countRaw, capRaw, entryBytes, lr);
    (void)mem.WriteU16BE(obj + 4, 0);
    (void)mem.WriteU16BE(obj + 6, 0);
    (void)mem.WriteU32BE(obj + 0, 0);
    return true;
  }

  // TLS table alive? Fast path: original body handles everything.
  // W36: also validate the allocator chain through TLS slot 12 so we don't
  // fall through to the original body when the chain is broken (causes
  // float-div/0 or null-ptr inside the allocator callback).
  uint32_t tlsTable = 0;
  if (ctx.r13.u32 != 0 && mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
      tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
    uint32_t allocator = 0;
    if (mem.ReadU32BE(tlsTable + 12, &allocator) &&
        allocator != 0 && allocator != 0xCDCDCDCDu) {
      uint32_t vtable = 0;
      if (mem.ReadU32BE(allocator, &vtable) &&
          vtable != 0 && vtable != 0xCDCDCDCDu) {
        uint32_t funcPtr = 0;
        if (mem.ReadU32BE(vtable + 8, &funcPtr) &&
            funcPtr != 0 && funcPtr != 0xCDCDCDCDu) {
          return false; // full chain alive — let original body run
        }
      }
    }
    // Chain broken somewhere — fall through to host-complete path
  }

  // TLS wiped: host-complete the ctor faithfully.
  MCLA_LOG_WARN("ATARRAY-TLSDEAD #{} obj={:08X} count={} cap={} stride={} "
                "lr={:08X}",
                n, obj, countRaw, capRaw, entryBytes, lr);
  (void)mem.WriteU16BE(obj + 4, static_cast<uint16_t>(countRaw));
  (void)mem.WriteU16BE(obj + 6, static_cast<uint16_t>(capRaw));
  uint32_t arrPtr = 0;
  if (capRaw != 0) {
    arrPtr = mem.Alloc(capRaw * entryBytes, 16);
    if (arrPtr == 0) {
      MCLA_LOG_WARN("ATARRAY-ALLOCFAIL #{} cap={} stride={}", n, capRaw,
                    entryBytes);
      (void)mem.WriteU16BE(obj + 4, 0);
      (void)mem.WriteU16BE(obj + 6, 0);
      (void)mem.WriteU32BE(obj + 0, 0);
      return true;
    }
  }
  (void)mem.WriteU32BE(obj + 0, arrPtr);
  if (arrPtr != 0 && countRaw != 0) {
    // 16B entries (AF68): [+8]=0. 16B entries (BFF0): +0/+4/+8=0, +12/+14=0.
    // 32B entries (8F00): +4/+8/+20/+24=0, +28/+30=0xFFFF. The zero-init
    // differences don't matter for a zeroed array — all-zero entries match
    // every variant except 8F00's 0xFFFF tails, kept exact above.
    if (entryBytes == 16) {
      uint8_t zero[16] = {0};
      for (uint32_t i = 0; i < countRaw; ++i)
        (void)mem.WriteBytes(arrPtr + i * 16u, zero, sizeof(zero));
    } else {
      uint8_t zero[32] = {0};
      zero[28] = 0xFF;
      zero[29] = 0xFF;
      zero[30] = 0xFF;
      zero[31] = 0xFF;
      for (uint32_t i = 0; i < countRaw; ++i)
        (void)mem.WriteBytes(arrPtr + i * 32u, zero, sizeof(zero));
    }
  }
  return true;
}

PPC_FUNC(sub_8218AF68) {
  const uint32_t n = s_hAF68.fetch_add(1) + 1;
  if (AtArrayCtorGuard(ctx, n, 16))
    return;
  __imp__sub_8218AF68(ctx, base);
}

// 32-byte-stride sibling (t23a AV at +0x50, lr=82189F50, same TLS+12 chain).
PPC_FUNC_IMPL(__imp__sub_82189F00);
static std::atomic<uint32_t> s_h89F00{0};
PPC_FUNC(sub_82189F00) {
  const uint32_t n = s_h89F00.fetch_add(1) + 1;
  if (AtArrayCtorGuard(ctx, n, 32))
    return;
  __imp__sub_82189F00(ctx, base);
}

// 16-byte-stride sibling #2 (t23b AV at +0x50, lr=8218C040, from 8C1C0+0x1101).
// Entry zero-init: +0/+4/+8 (u32) +12/+14 (u16) — all-zero entries cover it.
PPC_FUNC_IMPL(__imp__sub_8218BFF0);
static std::atomic<uint32_t> s_hBFF0{0};
PPC_FUNC(sub_8218BFF0) {
  const uint32_t n = s_hBFF0.fetch_add(1) + 1;
  if (AtArrayCtorGuard(ctx, n, 16))
    return;
  __imp__sub_8218BFF0(ctx, base);
}

// ===========================================================================
// W36c: sub_8218A008 census — CDCD fill-marathon worker that allocates via
// TLS slot-12 chain (lr=8218A0E8 crash site). When the TLS allocator chain
// is broken, the worker thread gets parked by VEH, which prevents GPU
// completions from being processed, which means the boot worker queue
// never receives messages and the game stalls.
//
// Fix: check the TLS chain at entry. If broken, zero the output struct
// (count=0, buf=0) and return without calling the original. The caller
// handles count==0 gracefully.
// ===========================================================================
PPC_FUNC_IMPL(__imp__sub_8218A008);
static std::atomic<uint32_t> s_h8A008{0};
PPC_FUNC(sub_8218A008) {
  const uint32_t n = s_h8A008.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // r3 = output struct [+0]=count [+4]=buf, r4 = stream context
  const uint32_t outStruct = ctx.r3.u32;
  // Check TLS chain: r13 -> [r13+0] -> [tlsTable+12] -> [alloc+0] -> [vtable+8]
  bool chainAlive = false;
  if (ctx.r13.u32 != 0) {
    uint32_t tlsTable = 0;
    if (mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
        tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
      uint32_t allocator = 0;
      if (mem.ReadU32BE(tlsTable + 12, &allocator) &&
          allocator != 0 && allocator != 0xCDCDCDCDu) {
        uint32_t vtable = 0;
        if (mem.ReadU32BE(allocator, &vtable) &&
            vtable != 0 && vtable != 0xCDCDCDCDu) {
          uint32_t funcPtr = 0;
          if (mem.ReadU32BE(vtable + 8, &funcPtr) &&
              funcPtr != 0 && funcPtr != 0xCDCDCDCDu) {
            chainAlive = true;
          }
        }
      }
    }
  }
  if (!chainAlive) {
    if (n <= 5 || (n % 200) == 0)
      MCLA_LOG_WARN("TLS-8A008 #{} chain broken, zeroing out={:08X}", n, outStruct);
    // Zero the output struct: count=0, buf=0
    (void)mem.WriteU32BE(outStruct + 0, 0u);
    (void)mem.WriteU32BE(outStruct + 4, 0u);
    return;
  }
  if (n <= 5 || (n % 200) == 0)
    MCLA_LOG_WARN("TLS-8A008 #{} chain alive, calling original", n);
  __imp__sub_8218A008(ctx, base);
}

// ===========================================================================
// W36e TLS CHAIN INIT (2026-09-18): The TLS allocator chain at
// tlsTable+12 (r13 -> [r13+0] -> [+12]) is initialized by the boot
// worker thread, but worker threads (sub_821C91C8) start BEFORE the
// boot worker and find the chain dead (slot12=0). Fix: initialize the
// chain on first thread entry. All threads share r13=0x8F200000 and
// tlsTable=0x8F201000, so one-time init suffices.
PPC_FUNC_IMPL(__imp__sub_821C91C8);
static std::atomic<uint32_t> s_tlsChainInitDone{0};
PPC_FUNC(sub_821C91C8) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Check if chain is already alive.
  bool chainAlive = false;
  if (ctx.r13.u32 != 0) {
    uint32_t tlsTable = 0;
    if (mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
        tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
      uint32_t allocator = 0;
      if (mem.ReadU32BE(tlsTable + 12, &allocator) &&
          allocator != 0 && allocator != 0xCDCDCDCDu) {
        uint32_t vtable = 0;
        if (mem.ReadU32BE(allocator, &vtable) &&
            vtable != 0 && vtable != 0xCDCDCDCDu) {
          uint32_t funcPtr = 0;
          if (mem.ReadU32BE(vtable + 8, &funcPtr) &&
              funcPtr != 0 && funcPtr != 0xCDCDCDCDu) {
            chainAlive = true;
          }
        }
      }
    }
  }
  if (!chainAlive) {
    // Initialize the chain once.
    if (s_tlsChainInitDone.fetch_add(1) == 0) {
      MCLA_LOG_WARN("W36e-TLS-INIT first init, r13={:08X}", ctx.r13.u32);
      // Build allocator object in guest memory: vtable at allocator+0,
      // alloc func at vtable+8. Use global __xtl_alloc (GuestMemoryHeap).
      uint32_t allocatorObj = mem.Alloc(16, 16); // allocator object
      uint32_t vtable = mem.Alloc(16, 16);       // vtable
      if (allocatorObj != 0 && vtable != 0) {
        // vtable[0] = vtable self (or 0), vtable[2] = alloc func
        // The chain check reads: allocator -> vtable -> vtable+8
        (void)mem.WriteU32BE(vtable + 8, 0x82130528); // __xtl_alloc address
        (void)mem.WriteU32BE(allocatorObj + 0, vtable);
        // tlsTable = [r13+0]
        uint32_t tlsTable = 0;
        if (mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
            tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
          (void)mem.WriteU32BE(tlsTable + 12, allocatorObj);
        }
      }
    }
  }
  __imp__sub_821C91C8(ctx, base);
}

// ===========================================================================
// F-309 DPC-PRODUCER CENSUS. sub_8242FD00 is the KeInsertQueueDpc-shaped ring
// append (body: per-CPU object via [0x82000864] + ([r13+268]&0xFF)*80, slot at
// obj+0x2C3C indexed by obj+0x2C74 counter, store r5 then counter++), and it is
// reached from the {handler,msgid} registry at 0x82113A90..0x82113ADC -- NOT via
// a bl, which is why "0 static callers" (F-269/F-270/F-301) proves nothing: the
// demonstrably-running place-pass sub_825EF100 has exactly one. No census has
// ever been hooked here, so "the producer never runs" has never been MEASURED.
// sub_8242F870 is the adjacent registry entry at 0x82113AB0 and DOES have a bl
// caller, so it is the within-build control: if the mechanism works at all, one
// of the two should print.
// LOG-ONLY: no guest write, no behaviour change, no RegisterFile dependency.
PPC_FUNC_IMPL(__imp__sub_8242FD00);
PPC_FUNC(sub_8242FD00) {
  static std::atomic<uint32_t> s_dpcIns{0};
  const uint32_t n = s_dpcIns.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t cpuArr = 0, tlsWord = 0, gbase = 0, cnt = 0, ring = 0;
  (void)mem.ReadU32BE(0x82000864u, &cpuArr);
  (void)mem.ReadU32BE(ctx.r13.u32 + 268u, &tlsWord);
  // lbz loads the byte at that address = the MSB of the BE dword there.
  const uint32_t idx = (tlsWord >> 24) & 0xFFu;
  if (cpuArr != 0) {
    (void)mem.ReadU32BE(cpuArr, &gbase);
    const uint32_t obj = gbase + idx * 80u;
    (void)mem.ReadU32BE(obj + 0x2C74u, &cnt);
    (void)mem.ReadU32BE(obj + 0x2C3Cu, &ring);
    MCLA_LOG_WARN("DPC-INS-CENSUS #{} r3={:08X} r4={:08X} r5={:08X} r13={:08X} "
                  "cpuArr={:08X} idx={} obj={:08X} cnt={} slot0={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r13.u32, cpuArr, idx,
                  obj, cnt, ring, static_cast<uint32_t>(ctx.lr));
  } else {
    MCLA_LOG_WARN("DPC-INS-CENSUS #{} r3={:08X} r4={:08X} r5={:08X} r13={:08X} "
                  "cpuArr=0 (table ptr null) lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r13.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8242FD00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8242F870);
PPC_FUNC(sub_8242F870) {
  static std::atomic<uint32_t> s_dpcSib{0};
  const uint32_t n = s_dpcSib.fetch_add(1) + 1;
  if (n <= 12) {
    MCLA_LOG_WARN("DPC-SIBLING-CENSUS #{} sub_8242F870 r3={:08X} r4={:08X} "
                  "r5={:08X} r13={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r13.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8242F870(ctx, base);
}

// ===========================================================================
// W36e TLS CHAIN INIT for boot worker (sub_8242FB88): The boot worker
// thread uses a different entry function and its TLS table (r13=8F200000
// -> tlsTable=8F201000) also needs the chain initialized. The boot worker
// may start with a temporary r13; we hardcode the known TLS table.
PPC_FUNC_IMPL(__imp__sub_8242FB88);
PPC_FUNC(sub_8242FB88) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Always ensure the known boot worker TLS table (8F201000) has a chain.
  const uint32_t kBootWorkerTlsTable = 0x8F201000;
  uint32_t slot12 = 0;
  if (mem.ReadU32BE(kBootWorkerTlsTable + 12, &slot12)) {
    if (slot12 == 0 || slot12 == 0xCDCDCDCDu) {
      static std::atomic<uint32_t> s_bootWorkerTlsInit{0};
      if (s_bootWorkerTlsInit.fetch_add(1) == 0) {
        MCLA_LOG_WARN("W36e-BOOT-WORKER-TLS-INIT fixing 8F201000 slot12={:08X}", slot12);
        uint32_t allocatorObj = mem.Alloc(16, 16);
        uint32_t vtable = mem.Alloc(16, 16);
        if (allocatorObj != 0 && vtable != 0) {
          (void)mem.WriteU32BE(vtable + 8, 0x82130528); // __xtl_alloc
          (void)mem.WriteU32BE(allocatorObj + 0, vtable);
          (void)mem.WriteU32BE(kBootWorkerTlsTable + 12, allocatorObj);
        }
      }
    }
  }
  // Also check current thread's chain.
  auto &mem2 = mcla::kernel::GuestMemoryHeap::Instance();
  bool chainAlive = false;
  if (ctx.r13.u32 != 0) {
    uint32_t tlsTable = 0;
    if (mem2.ReadU32BE(ctx.r13.u32, &tlsTable) &&
        tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
      uint32_t allocator = 0;
      if (mem2.ReadU32BE(tlsTable + 12, &allocator) &&
          allocator != 0 && allocator != 0xCDCDCDCDu) {
        uint32_t vtable = 0;
        if (mem2.ReadU32BE(allocator, &vtable) &&
            vtable != 0 && vtable != 0xCDCDCDCDu) {
          uint32_t funcPtr = 0;
          if (mem2.ReadU32BE(vtable + 8, &funcPtr) &&
              funcPtr != 0 && funcPtr != 0xCDCDCDCDu) {
            chainAlive = true;
          }
        }
      }
    }
  }
  if (!chainAlive) {
    static std::atomic<uint32_t> s_bootWorkerTlsInit2{0};
    if (s_bootWorkerTlsInit2.fetch_add(1) == 0) {
      MCLA_LOG_WARN("W36e-BOOT-WORKER-TLS-INIT current r13={:08X}", ctx.r13.u32);
      uint32_t allocatorObj = mem2.Alloc(16, 16);
      uint32_t vtable = mem2.Alloc(16, 16);
      if (allocatorObj != 0 && vtable != 0) {
        (void)mem2.WriteU32BE(vtable + 8, 0x82130528);
        (void)mem2.WriteU32BE(allocatorObj + 0, vtable);
        uint32_t tlsTable = 0;
        if (mem2.ReadU32BE(ctx.r13.u32, &tlsTable) &&
            tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
          (void)mem2.WriteU32BE(tlsTable + 12, allocatorObj);
        }
      }
    }
  }
  __imp__sub_8242FB88(ctx, base);
}

// ===========================================================================
// T5 systemic fix (t23c frontier): the XTL allocation import thunks
// (sub_82130528/550/588) resolve the host allocator through the guest TLS
// table: *( *(r13) + 28 ) -> FuncBlock -> +8 alloc / +12 free. The TLS block
// at 0x8F200000 gets WIPED at runtime (park sample tls0=00000000), so every
// late-boot alloc/free through these thunks AVs at 0x7E780000 (= lookup of
// guest-0). These are strong overrides: same result contract as __xtl_alloc /
// __xtl_free (kernel/imports.cpp), TLS-independent.
//   sub_82130528(r3=size)        -> alloc(size, align 16)
//   sub_82130550(r3=a, r4=b)     -> alloc(max(a,b), align 16)
//   sub_82130588(r3=ptr)         -> free(ptr) — returns success (r3=1)
// ===========================================================================
PPC_EXTERN_FUNC(__xtl_alloc);
PPC_EXTERN_FUNC(__xtl_free);
static std::atomic<uint32_t> s_hXtlImport{0};
static void XtlImportCensus(const char *which, uint32_t n, uint32_t a,
                            uint32_t b) {
  if (n <= 8 || (n % 500) == 0)
    MCLA_LOG_WARN("XTLIMPORT #{} {} a={:08X} b={:08X}", n, which, a, b);
}

PPC_FUNC_IMPL(__imp__sub_82130528);
PPC_FUNC(sub_82130528) {
  const uint32_t n = s_hXtlImport.fetch_add(1) + 1;
  XtlImportCensus("alloc", n, ctx.r3.u32, 0);
  // Original thunk: mr r4,r3; li r5,16; li r6,0 then TLS-slot-28 call.
  // __xtl_alloc reads r4 (size) and r5 (align) — restore the full ABI.
  ctx.r4.u32 = ctx.r3.u32;
  ctx.r5.u32 = 16;
  ctx.r6.u32 = 0;
  __xtl_alloc(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82130550);
PPC_FUNC(sub_82130550) {
  const uint32_t n = s_hXtlImport.fetch_add(1) + 1;
  // Original: r11 = max(r3, r4); then mr r4,r11; li r5,16; li r6,0.
  const uint32_t sz = (ctx.r3.u32 > ctx.r4.u32) ? ctx.r3.u32 : ctx.r4.u32;
  XtlImportCensus("alloc-max", n, ctx.r3.u32, ctx.r4.u32);
  ctx.r4.u32 = sz;
  ctx.r5.u32 = 16;
  ctx.r6.u32 = 0;
  __xtl_alloc(ctx, base);
  if (ctx.r3.u32 == 0 && sz != 0)
    MCLA_LOG_WARN("XTLIMPORT alloc-max #{} FAILED size={}", n, sz);
}

// ===========================================================================
// T5 (t24b frontier): sub_821D30E8 buffer-Grow via dead TLS FuncBlock+16.
//
// ABI (ppc_recomp.18.cpp:3185): r3 = bufobj {+8 blk {ptr@0,size@4}, +4 size,
// +12 next-cap}. Rounds size up to 16, reallocs via *(TLS slot 28 fn)+16
// (Realloc slot), stores blk->ptr, mirrors obj+4 -> blk+4, parks obj+12 in
// TLS[+12], clears obj+12. Crash: lr=821D3134, r3=0 (caller 8C760+0x3FB
// passed the stream wrapper whose +8 block was wiped).
// Host-complete: grow via GuestMemoryHeap::Alloc, copy, faithful stores.
// ===========================================================================
PPC_FUNC_IMPL(__imp__sub_821D30E8);
static std::atomic<uint32_t> s_hD30E8{0};
PPC_FUNC(sub_821D30E8) {
  const uint32_t n = s_hD30E8.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (obj == 0 || obj == 0xCDCDCDCDu) {
    MCLA_LOG_WARN("D30E8-SKIP #{} null obj lr={:08X}", n, lr);
    return;
  }
  uint32_t blk = 0, size = 0, oldPtr = 0;
  (void)mem.ReadU32BE(obj + 8, &blk);
  (void)mem.ReadU32BE(obj + 4, &size);
  if (blk != 0 && blk != 0xCDCDCDCDu)
    (void)mem.ReadU32BE(blk + 0, &oldPtr);
  // Original rounds the requested size up to 16 (addi 15; rlwinm ... 27).
  const uint32_t rounded = (size + 15u) & ~15u;
  (void)mem.WriteU32BE(obj + 4, rounded);
  // TLS-table alive? Let the original body run (its bctrl uses TLS FuncBlock
  // +16 Realloc which the boot chain arms).
  uint32_t tlsTable = 0;
  if (ctx.r13.u32 != 0 && mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
      tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
    __imp__sub_821D30E8(ctx, base);
    return;
  }
  // TLS dead: host-complete the grow.
  MCLA_LOG_WARN("D30E8-TLSDEAD #{} obj={:08X} blk={:08X} size={} old={:08X}",
                n, obj, blk, rounded, oldPtr);
  if (blk == 0 || blk == 0xCDCDCDCDu) {
    // Nothing to grow — mirror the skip path (caller treats size as-is).
    return;
  }
  const uint32_t newPtr = mem.Alloc(rounded ? rounded : 16u, 16);
  if (newPtr == 0) {
    MCLA_LOG_WARN("D30E8-ALLOCFAIL #{} size={}", n, rounded);
    return;
  }
  if (oldPtr != 0) {
    // Preserve prior contents (realloc semantics).
    uint8_t tmp[512];
    uint32_t copied = 0;
    uint32_t oldSize = 0;
    (void)mem.ReadU32BE(blk + 4, &oldSize);
    const uint32_t lim = (oldSize < rounded) ? oldSize : rounded;
    while (copied < lim) {
      const uint32_t chunk = (lim - copied > sizeof(tmp)) ? sizeof(tmp) : lim - copied;
      if (!mem.ReadBytes(oldPtr + copied, tmp, chunk) ||
          !mem.WriteBytes(newPtr + copied, tmp, chunk))
        break;
      copied += chunk;
    }
  }
  (void)mem.WriteU32BE(blk + 0, newPtr);
  (void)mem.WriteU32BE(blk + 4, rounded);
  // Original: TLS[+12] = obj+12 then obj+12 = 0 — the TLS write is part of
  // the real contract; keep it best-effort (r13 block is dead anyway).
  (void)mem.WriteU32BE(obj + 12, 0);
}

PPC_FUNC_IMPL(__imp__sub_82130588);
PPC_FUNC(sub_82130588) {
  const uint32_t n = s_hXtlImport.fetch_add(1) + 1;
  XtlImportCensus("free", n, ctx.r3.u32, 0);
  // Original thunk: r4=r3 then TLS-slot-28 call with FuncBlock+12 (free).
  ctx.r4.u32 = ctx.r3.u32;
  __xtl_free(ctx, base);
}
