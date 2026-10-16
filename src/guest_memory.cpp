#include "guest_memory.h"
#include "kernel/heap_arena.h"  // F-384: kUserHeapArenaVa, so the census follows the arena
#include "logging.h"
#include <atomic>
#include <intrin.h>   // F-374b: _ReturnAddress() for the heap-instance store report
#include <windows.h>   // F-374b: GetModuleHandleA() to turn the caller into an RVA
#include <algorithm>   // F-635: std::sort for the capped exact-set dumps
#include <cstring>
#include <mutex>
#include <string>
#include <unordered_set>
#include <vector>

// PAGE-WATCH hooks (session 24): defined in gpu_cp.cpp which owns the full
// PPCContext includes - keeps this hot-path TU free of ABI header chains.
namespace mcla::gpu {
void PageWatchOnWrite(uint32_t guestAddr, uint32_t value);
void PageWatchOnRead(uint32_t guestAddr, uint32_t value);
// F-375: gpu_cp.cpp owns the PPCContext includes, so the guest-side argument dump for a store
// that reached the host heap instance lives there (see ReportHeapInstanceStore below).
void HeapInstanceStoreReport(uint32_t guestAddr, uint32_t value);
// F-784: the T44 wipe watch (defined next to PageWatchOnWrite in gpu_cp.cpp, same linkage
// reasoning as above). `T44WipeOverlaps` is the cheap address test against the two armed
// pages; `T44WipeSpan` additionally returns the overlapping sub-range so a bulk copy can
// snapshot the exact bytes it is about to overwrite; `T44WipeNote` prints the row. Callers
// must test first -- these are report paths, not filters, and every one of them is called
// on the hot write path.
bool T44WipeOverlaps(uint32_t guestAddr, uint32_t len);
bool T44WipeSpan(uint32_t guestAddr, uint32_t len, uint32_t* outStart, uint32_t* outLen);
void T44WipeNote(const char* op, uint32_t guestAddr, uint32_t len, uint64_t val,
                 uint64_t pre, uint32_t preN, const void* hostPc);
} // namespace mcla::gpu

static constexpr uint32_t kWatchPage = 0x50000000u;

// F-374b/F-631: the guest user heap's o1heap INSTANCE occupies guest 0x20000..0x20240
// (src/kernel/o1heap.c:133-138 -- 64 free-bin pointers, a bin mask, then the diagnostics block;
// `capacity` is the constant at +0x208). Only o1heap writes there, and it does so through raw host
// pointers. A store that reaches that window through the GUEST-facing checked writers is a wild
// destination by definition.
//
// F-631 -- THIS WINDOW IS 0x240 BYTES AND THAT IS THE WHOLE PROBLEM WITH IT. F-630 read `w654`'s
// eight `F375-HEAPSTORE` rows as "the guest zeroed the allocator header", i.e. as the COMPLETE event.
// It is a 0.240 KB sample of a much larger write. `python tools/ppc_xrefs.py fn 0x821C667C` resolves
// the `lr` on all eight rows to `sub_821C6658 +0x24` -- a return address INSIDE the guest's own
// `memset(ptr,0,n*12)` wrapper, not a function entry -- and the same rows carry `r4=0x6F1E0`, so the
// store loop was walking ~0x6F1E0 elements of 12 bytes: roughly 5.2 MB starting at 0x20004, of which
// the window could show 8 stores. Every count, byte range and "extent" claim derived from this probe
// is therefore a lower bound, and the two instruments below exist so no future reader has to know
// that to be told the truth:
//
//   * `F631-HEAPEXT` -- one row per BULK copy that overlaps the window, carrying the copy's real
//     destination and length. A 5.2 MB memset is ONE row with `len=0x5081A0`, not eight dword rows,
//     and it is emitted from `WriteBytes` where the length is still known. This is the primary
//     instrument: `WriteBytes` is the only entry point that knows the extent of a write, and it
//     previously reported nothing at all for the heap window.
//   * `F631-HEAPWIN` -- a bounded rollup of the per-dword path: cumulative store count, the lowest
//     and highest address the window has seen, and `saturated=` saying whether the observed range
//     reached the window's own end (which is what "truncated" looks like from inside the probe).
//
// Both are capped on the house cadence, because the log-quality rule (F-054) is the difference
// between a soak that can be read and a soak that cannot. The old `F374-HEAPSTORE` rows are left
// exactly as they are: they are the only per-store attribution in the tree (caller_rva + tid) and
// they resolve with `tools/host_rva_resolve.py`, so they stay and gain an explicit `sample_of` note
// rather than being replaced.
namespace {
// F-384: these follow the arena; they are NOT hardcoded addresses. Watching a stale range after a
// relocated arena would read as "the corruption stopped" when it only moved out of sight -- the
// values come from the single definition in `src/kernel/heap.h`.
constexpr uint32_t kHeapInstanceLo = mcla::kernel::kUserHeapArenaVa;
constexpr uint32_t kHeapInstanceHi = mcla::kernel::kUserHeapArenaVa + 0x240u;

// F-777: the PHYSICAL instance was missing from this family entirely. BOTH o1heap instances are
// destroyed in every soak (`o1heap invariants FAIL` x4, `XTL-ALLOC-REFUSED` x4, `F370-HEAP-HDR`
// reading `cap=0x0` against `want_cap=0x7fe7fdc0`), yet the extent instrument -- the only one in
// the tree that reports a real `dst`, a real `len` and a `caller_rva` that
// `tools/host_rva_resolve.py` can name -- was pointed at kUserHeapArenaVa alone. The physical
// instance at kPhysArenaBeginVa was covered only by the 2 KB armed watch range, whose attribution
// is a guest `lr` read through GetPPCContext() and is therefore STICKY (do-not #14): 512 rows of
// `lr=821BE3BC` were read as an attribution when the same lr also sits on 1115 unrelated rows and
// on 40 genuine 2-byte memcpys 0x3C000 higher. These three functions are called from
// WriteU32BE/WriteU64BE/WriteBytes, the chokepoint every guest store must cross, so neither a
// direct `stw` loop nor a bulk copy can bypass them -- which is more than a PPC_FUNC hook can
// claim: `F382-MEMCPY` has fired 0 times in every log ever written (w725..w739), so its zero is
// blindness, not absence (LT rule 19).
struct HeapInstanceWindow { uint32_t lo; uint32_t hi; const char *tag; };
constexpr uint32_t kPhysInstanceLo = mcla::kernel::kPhysArenaBeginVa;
constexpr uint32_t kPhysInstanceHi = mcla::kernel::kPhysArenaBeginVa + 0x240u;
constexpr HeapInstanceWindow kHeapWindows[] = {
    {kHeapInstanceLo, kHeapInstanceHi, "user"},
    {kPhysInstanceLo, kPhysInstanceHi, "phys"},
};
constexpr size_t kNumHeapWindows = sizeof(kHeapWindows) / sizeof(kHeapWindows[0]);

// Returns the matching window index, or -1. Deliberately NOT a bool: -1 is truthy, so every call
// site must compare `>= 0` rather than test the result.
inline int HeapInstanceStoreHit(uint32_t guestAddr) {
    for (size_t i = 0; i < kNumHeapWindows; ++i)
        if (guestAddr >= kHeapWindows[i].lo && guestAddr < kHeapWindows[i].hi) return (int)i;
    return -1;
}

// F-631: SPAN overlap, not point containment. The write that matters starts at 0x20004 and runs for
// megabytes; a test on the start address alone sees it, a test on the window alone does not. Mirrors
// the range logic `RangeOverlapsWatch` already uses for the dynamic ranges (guest_memory.cpp:183).
inline int HeapWindowOverlaps(uint32_t guestAddr, uint32_t size) {
    if (size == 0) return -1;
    const uint64_t end = static_cast<uint64_t>(guestAddr) + size;
    for (size_t i = 0; i < kNumHeapWindows; ++i)
        if (guestAddr < kHeapWindows[i].hi && kHeapWindows[i].lo < end) return (int)i;
    return -1;
}

// Cumulative extent of the per-dword path, per window. Monotonic and never reset: this measures the
// whole boot's writing into the window, which is the quantity F-630 got wrong by treating 8 as the
// total. Widened with a CAS-free exchange-max: a lost race can only under-report the low bound by
// one address, and the rollup is a census, not a lock.
std::atomic<uint64_t> g_winStores[kNumHeapWindows]{};
std::atomic<uint32_t> g_winLo[kNumHeapWindows] = {0xFFFFFFFFu, 0xFFFFFFFFu};
std::atomic<uint32_t> g_winHi[kNumHeapWindows]{};

void CountWindowStore(size_t wi, uint32_t guestAddr) {
    g_winStores[wi].fetch_add(1, std::memory_order_relaxed);
    uint32_t cur = g_winLo[wi].load(std::memory_order_relaxed);
    while (guestAddr < cur && !g_winLo[wi].compare_exchange_weak(cur, guestAddr, std::memory_order_relaxed)) {}
    cur = g_winHi[wi].load(std::memory_order_relaxed);
    while (guestAddr > cur && !g_winHi[wi].compare_exchange_weak(cur, guestAddr, std::memory_order_relaxed)) {}
}

void ReportHeapInstanceStore(const char *op, uint32_t guestAddr, uint64_t val, void *ra, size_t wi) {
    static std::atomic<uint32_t> s_storeN[kNumHeapWindows]{};
    const HeapInstanceWindow &w = kHeapWindows[wi];
    const uint32_t n = s_storeN[wi].fetch_add(1) + 1;
    // F-379: the old hard cap (`n > 16`) made the burst length unmeasurable -- w387 and w388 both
    // printed exactly 16 rows regardless of how long the copy actually was, so "16 dwords" was the
    // cap, not a measurement. First 16 plus every 4096th row keeps a short burst complete (cap-shape
    // rule) while making a long one visible. tid separates bursts from different threads.
    // F-631: `sample_of` and `win_stores` are what stop the next reader making F-630's mistake again.
    // `win_stores` is the number of stores the window has actually seen; a burst far larger than the
    // 16 rows below it is a sample of something bigger, and the row now says so in the same line.
    // F-777: the counter is now PER WINDOW, so the two instances cannot spend each other's budget --
    // a shared counter would let a chatty user heap starve the physical one to zero rows and read as
    // "the physical instance was never written".
    if (n <= 16 || (n % 4096) == 0) {
        const uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
        const uintptr_t abs = reinterpret_cast<uintptr_t>(ra);
        const uint64_t total = g_winStores[wi].load(std::memory_order_relaxed);
        MCLA_LOG_ERROR("F374-HEAPSTORE #{} inst={} op={} guest={:08X} inst_off={:#x} val={:#x} "
                       "caller_rva={:#x} tid={} sample_of={} (window is 0x240 bytes: these rows are "
                       "a SAMPLE, the whole event is F631-HEAPEXT or F631-HEAPWIN)",
                       n, w.tag, op, guestAddr, guestAddr - w.lo, val, base ? abs - base : abs,
                       GetCurrentThreadId(), (unsigned long long)total);
        mcla::gpu::HeapInstanceStoreReport(guestAddr, static_cast<uint32_t>(val));
        // F-631: the rollup, on the same cadence as the rows it qualifies. `saturated` is the whole
        // point -- it is true once the window has seen its own last byte, which means the observed
        // range is bounded by the window and NOT by the writer.
        const uint32_t lo = g_winLo[wi].load(std::memory_order_relaxed);
        const uint32_t hi = g_winHi[wi].load(std::memory_order_relaxed);
        MCLA_LOG_ERROR("F631-HEAPWIN #{} inst={} op={} win_stores={} lo={:08X} hi={:08X} "
                       "saturated={} window=[{:08X},{:08X}) window_bytes=0x{:X} tid={}",
                       n, w.tag, op, (unsigned long long)total, lo, hi,
                       (hi >= w.hi - 4u) ? 1 : 0, w.lo, w.hi,
                       (unsigned)(w.hi - w.lo), GetCurrentThreadId());
    }
    CountWindowStore(wi, guestAddr);
}

// F-631: the primary extent instrument. A bulk copy that overlaps the instance window is ONE event
// with a real destination and a real length, which is the thing F-630 needed and the dword window
// could not provide. `len` is the whole copy, not the part that landed in the window, and the row
// says how much of it did -- so a 5.2 MB memset reads as a 5.2 MB memset.
void ReportHeapWindowExtent(const char *op, uint32_t guestAddr, uint32_t size, void *ra, size_t wi) {
    static std::atomic<uint64_t> s_extN[kNumHeapWindows]{};
    const HeapInstanceWindow &w = kHeapWindows[wi];
    const uint64_t n = s_extN[wi].fetch_add(1, std::memory_order_relaxed) + 1;
    // Cadence: the first 4, then every 64th. A guest that memsets its own allocator state once per
    // frame is not interesting; one that does it in a loop is, and 64 keeps a loop visible without
    // letting it become the log. F-777: per window, for the same reason as s_storeN above.
    if (n > 4 && (n % 64) != 0) return;
    const uint32_t hi = guestAddr + size;  // size is bounded by IsValidRange (<= 4 GiB window)
    const uint32_t ovLo = guestAddr > w.lo ? guestAddr : w.lo;
    const uint32_t ovHi = hi < w.hi ? hi : w.hi;
    const uintptr_t mbase = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
    const uintptr_t abs = reinterpret_cast<uintptr_t>(ra);
    MCLA_LOG_ERROR("F631-HEAPEXT #{} inst={} op={} dst={:08X} len={:#x} window_overlap=[{:08X},{:08X}) "
                   "overlap_bytes={:#x} covers_window={} caller_rva={:#x} tid={}",
                   (unsigned long long)n, w.tag, op, guestAddr, size, ovLo, ovHi,
                   (unsigned)(ovHi > ovLo ? ovHi - ovLo : 0u),
                   (guestAddr <= w.lo && hi >= w.hi) ? 1 : 0,
                   mbase ? abs - mbase : abs, GetCurrentThreadId());
}
}  // namespace

// Dynamic watch ranges (session 26): armed by censuses when they observe a
// suspicious structure (e.g. empty dispatch method-object). Guest stores into
// these ranges are reported by PageWatchOnWrite with caller LR.
constexpr uint32_t kMaxWatchRanges = 64;
struct WatchRange
{
    std::atomic<uint32_t> start{0};
    std::atomic<uint32_t> end{0};
};
WatchRange g_watchRanges[kMaxWatchRanges];
std::atomic<uint32_t> g_watchRangeCount{0};

static std::mutex s_watchMtx;

void mcla::native::RegisterGuestWatchRange(uint32_t start, uint32_t end)
{
    std::lock_guard lock(s_watchMtx);
    const uint32_t n = g_watchRangeCount.load(std::memory_order_relaxed);
    for (uint32_t i = 0; i < n; ++i)
    {
        if (g_watchRanges[i].start.load(std::memory_order_relaxed) == start)
        {
            return; // already armed
        }
    }
    if (n >= kMaxWatchRanges)
    {
        // F-412: silent drop -> one-time warning. w430 armed only 30/64, so this is NOT exhausted
        // today; the cap is named here for consistency with RegisterGuestWatchValue below so a
        // future exhaustion is visible instead of a silent blind spot. ONE row ever (F-054: a
        // per-drop log poisons the soak).
        static bool s_warnedRange = false;  // guarded by s_watchMtx
        if (!s_warnedRange)
        {
            s_warnedRange = true;
            MCLA_LOG_WARN("WATCH: range cap kMaxWatchRanges={} hit -- dropping [{:08X},{:08X})",
                          kMaxWatchRanges, start, end);
        }
        return;
    }
    g_watchRanges[n].start.store(start, std::memory_order_relaxed);
    g_watchRanges[n].end.store(end, std::memory_order_relaxed);
    g_watchRangeCount.store(n + 1, std::memory_order_release);
    MCLA_LOG_WARN("WATCH: range armed [{:08X},{:08X})", start, end);
}

// Value watch (session 27): log every store whose VALUE equals a registered
// constant - catches pointer registration sites (e.g. who links object
// 0x88825500 into the swf display-list chain).
// F-412: was 4, which w430 proved exhausted -- 4 armed (CDCDCDCD, 80010000, 00020037, 88825500)
// while src/task_dispatch_trace.cpp:84-92 registers 8 more that were dropped silently at the cap
// below, a blind spot hiding evidence for many sessions. 16 = power of two, still a cheap scan in
// WatchValueHit.
constexpr uint32_t kMaxWatchValues = 16;
std::atomic<uint32_t> g_watchValues[kMaxWatchValues];
std::atomic<uint32_t> g_watchValueCount{0};

void mcla::native::RegisterGuestWatchValue(uint32_t value)
{
    std::lock_guard lock(s_watchMtx);
    const uint32_t n = g_watchValueCount.load(std::memory_order_relaxed);
    for (uint32_t i = 0; i < n; ++i)
    {
        if (g_watchValues[i].load(std::memory_order_relaxed) == value)
        {
            return;
        }
    }
    if (n >= kMaxWatchValues)
    {
        // F-412: was a bare `return` -- w430 silently lost the 8 value watches from
        // task_dispatch_trace.cpp at this exact site. Warn ONCE naming the cap and the dropped
        // value so the next exhaustion is a log line, not a hole in the evidence. Never per-drop:
        // repeated mitigation lines poison the soak (F-054).
        static bool s_warnedValue = false;  // guarded by s_watchMtx
        if (!s_warnedValue)
        {
            s_warnedValue = true;
            MCLA_LOG_WARN("WATCH: value cap kMaxWatchValues={} hit -- dropping value {:08X}",
                          kMaxWatchValues, value);
        }
        return;
    }
    g_watchValues[n].store(value, std::memory_order_relaxed);
    g_watchValueCount.store(n + 1, std::memory_order_release);
    MCLA_LOG_WARN("WATCH: value armed {:08X}", value);
}

inline bool WatchValueHit(uint32_t value)
{
    const uint32_t n = g_watchValueCount.load(std::memory_order_acquire);
    for (uint32_t i = 0; i < n; ++i)
    {
        if (g_watchValues[i].load(std::memory_order_relaxed) == value)
        {
            return true;
        }
    }
    return false;
}

inline bool PageWatchHit(uint32_t guestAddr)
{
    if ((guestAddr & 0xFFFFF000u) == kWatchPage)
    {
        return true;
    }
    const uint32_t n = g_watchRangeCount.load(std::memory_order_acquire);
    for (uint32_t i = 0; i < n; ++i)
    {
        const uint32_t s = g_watchRanges[i].start.load(std::memory_order_relaxed);
        const uint32_t e = g_watchRanges[i].end.load(std::memory_order_relaxed);
        if (guestAddr >= s && guestAddr < e)
        {
            return true;
        }
    }
    return false;
}

// Session 73: bulk copies must be checked by RANGE overlap, not endpoints —
// a memset/memcpy spanning a watched region (start before it, end after)
// previously slipped through with only the first/last dword probes.
inline bool RangeOverlapsWatch(uint32_t guestAddr, uint32_t size)
{
    const uint32_t e = guestAddr + size;
    if (size != 0 &&
        (guestAddr & 0xFFFFF000u) == kWatchPage)
    {
        return true;
    }
    const uint32_t n = g_watchRangeCount.load(std::memory_order_acquire);
    for (uint32_t i = 0; i < n; ++i)
    {
        const uint32_t s = g_watchRanges[i].start.load(std::memory_order_relaxed);
        const uint32_t r = g_watchRanges[i].end.load(std::memory_order_relaxed);
        if (guestAddr < r && s < e)
        {
            return true;
        }
    }
    return false;
}

// F-633 -- READ-REFUSAL CENSUS FOR GuestMemoryView::ReadU32BE (the class this file owns).
//
// WHY THIS EXISTS. `mcla::native::ReadGuestU32` (src/guest_memory.h:82-86) pre-zeroes `val` and
// DISCARDS ReadU32BE's bool:
//     uint32_t val = 0; GetActiveGuestMemoryView().ReadU32BE(guestAddr, &val); return val;
// so a refusal is a SILENT 0 handed back to the recompiler as if it were memory. Measured
// consequence, w682.log (the boot's only guest access violation):
//     Param[0]=0 (READ) Param[1]=0x7E780000 r8=0xFFFFFFFF7E780000 rdx=0x100000000
//     rip owner=guest 0x825FB348 -> generated/ppc_xenon/ppc_recomp.121.cpp:25113
//     = PPC_CALL_INDIRECT_FUNC(ctr.u32), i.e.
//         lwz r3,4(r30) ; lwz r11,0(r3) ; lwz r10,12(r11) ; mtctr r10 ; bctrl
//     (ppc_recomp.121.cpp:25102/25106/25108/25110/25113) where each lwz is PPC_LOAD_U32 ->
//     ReadGuestU32 -> ReadU32BE (ppc_context.h:57, guest_memory.h:82).
// 0xFFFFFFFF7E780000 is the compiler's fold of `base + PPC_IMAGE_BASE + PPC_IMAGE_SIZE -
// 2*PPC_CODE_BASE` from PPC_LOOKUP_FUNC (src/ppc_context.h:124), and with base = 0x100000000
// the log's Param[1] implies ctr == 0 -- the host dereferenced 0x81880000 bytes below its own
// allocation. THREE causes produce that identical machine state and the log separates none of
// them:
//   (1) the guest's vtable slot really holds 0 (unconstructed object) -- a guest bug;
//   (2) r3 == 0 -> ReadU32BE(0) refuses -> fabricates 0 -> r11 = 0 -> ReadU32BE(12) refuses ->
//       fabricates 0 -> ctr = 0                      -- a HOST bug, cascading, silent;
//   (3) r3 in range but unreadable -> same cascade     -- a HOST bug, cascading, silent.
// The register dump cannot break the tie (the crash row says `ppc ctx=nil` and F-046 says any
// GPR read from that dump is another frame's), so the discriminator has to be the refusal itself.
// `LogGuestLoadRefused` (src/kernel/memory.cpp:74) instruments the OTHER class
// (GuestMemoryHeap) and therefore cannot see this path at all -- which is why that census
// returned rows that said nothing about this crash. THIS file is the only place that can.
//
// WHAT IS REPORTED. One row per refusal, on the house cadence, carrying the guest VA, the size,
// which check refused, the thread, and the cumulative totals; plus one SUMMARY on the same
// cadence so a zero is distinguishable from a dropped sample. Because ReadU32BE is a hot path
// the rows are sampled: first 16, then every 4096th (kGvPrintFirst/kGvPrintEvery). A hard cap
// is NOT used: an earlier burst was capped at 16 rows, both soaks printed exactly 16, and the
// "16" was then read as a measurement (F-379, guest_memory.cpp:91-94) -- the burst length became
// unmeasurable. Sampling keeps a short burst complete while making a long one visible, and the
// `total=`/`rows=`/`dropped=` fields in the same line say which is which.
//
// FABRICATED ZEROS (the decisive number). A refusal with va < 0x1000 -- below the NOACCESS guard
// page that IsValidRange rejects (guest_memory.cpp:307) -- cannot come from any legitimate
// recompiled `lwz`: the guest image is mapped at 0x82000000 and no Xenon guest address lives in
// the first page. So each one is a zero this host invented and handed to the recompiler as
// memory. `GUESTVIEW-U32-FABZERO` counts those on its own cadence, independent of the row
// sampling, so it is conclusive on its own.
//     fab_zero > 0 on tid 16332 within ms of the crash  => cause (2) or (3): the host
//                                                          fabricates the 0 and the crash is a
//                                                          CASCADE, not the root cause.
//     total == 0 across a full soak that still crashes => cause (1): the guest really stored 0
//                                                          into a vtable slot, and the host's only
//                                                          defect is the missing range check on the
//                                                          dispatch index.
// FALSIFIER for the instrument itself: rows from another thread but nothing on 16332 -- the
// marker demonstrably works, and the crash is cause (1).
//
// TWO THINGS THAT PRODUCE ROWS THAT ARE NOT THE CRASH -- read before interpreting a FABZERO:
//   * `VerifyGuestMemoryViewForTests` (this file, ~line 750) deliberately calls ReadU32BE(0,
//     nullptr), ReadU32BE(0,&v) and ReadU32BE(0x100,&v) to prove the guard page refuses, and
//     `InstallNativeRenderer` (src/native_renderer.cpp:502) runs it at boot. That is exactly 3
//     refusals, va=00000000 x2 and va=00000100, on the renderer-install thread. They are
//     separable from the crash without guessing: the self-test runs on a LOCAL `GuestMemoryView`
//     whose base is a 0x3000-byte stack array, so those three rows carry a `view_base` that is a
//     stack address, while the recompiler's view is the real allocation (0x100000000 in w682.log,
//     `rdx=0x100000000`). `caller_rva` + `tools/host_rva_resolve.py` names the caller as well.
//   * Host-side census/probe callers of ReadU32BE (src/boot_host.cpp, src/gpu_cp.cpp,
//     src/capture_hooks.cpp) also drop the bool, so a probe of an absent guest address lands here
//     too. They are NOT reccompiled `lwz`s and must not be read as guest evidence. Same key:
//     `caller_rva` (a recompiled load resolves to `ReadGuestU32` in ppc_recomp.*.cpp; a host probe
//     resolves to the probing function) and `view_base`.
//
// BEHAVIOUR: none changed. Same `false` returns, same untouched *outVal, same MMIO routing, same
// PageWatchOnRead. The one shape change is that the `__except` handler now only sets a flag and
// the log call happens after the SEH scope: formatting inside a handler that is running off an
// access violation can fault again, which is the same reason src/kernel/memory.cpp:53-57
// captures the exception in a filter and formats outside. The bool that ReadGuestU32 drops is
// NOT fixed here -- that is src/guest_memory.h, a different file, a separate task.
namespace {
enum GvU32Why { kGvRange = 0, kGvNullOut, kGvAv, kGvWhyCount };
const char* const kGvU32WhyName[kGvWhyCount] = {"range", "nullout", "av"};

// kGvGuardPage duplicates the `guestAddr < 0x1000` floor in IsValidRange on purpose: this
// counter is the *interpretation* of that constant, and it must keep working even if someone
// later tunes IsValidRange. Verified equal by reading guest_memory.cpp:307.
constexpr uint32_t kGvGuardPage = 0x1000u;
constexpr uint64_t kGvPrintFirst = 16;
constexpr uint64_t kGvPrintEvery = 4096;

std::atomic<uint64_t> g_gvTotal{0};                        // every refusal, printed or not
std::atomic<uint64_t> g_gvRows{0};                         // rows actually printed
std::atomic<uint64_t> g_gvByWhy[kGvWhyCount]{};           // range / nullout / av
std::atomic<uint64_t> g_gvFabZero{0};                     // refusals with va < 0x1000
std::atomic<uint64_t> g_gvFabRows{0};                     // FABZERO rows printed
std::atomic<uint32_t> g_gvLo{0xFFFFFFFFu};
std::atomic<uint32_t> g_gvHi{0};

// Exception facts, captured in the filter and formatted outside it (see above).
struct GvU32Fault {
    unsigned long code = 0;
    unsigned long long addr = 0;
};

// A filter expression must be a constant expression, hence a named function. Returning
// EXCEPTION_EXECUTE_HANDLER keeps the original control flow exactly.
int GvU32AvFilter(EXCEPTION_POINTERS* ep, void* ctx) {
    auto* f = static_cast<GvU32Fault*>(ctx);
    if (ep && ep->ExceptionRecord) {
        f->code = ep->ExceptionRecord->ExceptionCode;
        // Information[1] is the faulting DATA address, [0] the access type.
        if (ep->ExceptionRecord->NumberParameters >= 2)
            f->addr = ep->ExceptionRecord->ExceptionInformation[1];
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

void ReportGuestViewU32Refused(uint32_t guestAddr, int why, unsigned long avCode,
                               unsigned long long avAddr, const void* ra,
                               const void* viewBase, uint64_t viewSize) {
    const uint64_t n = g_gvTotal.fetch_add(1, std::memory_order_relaxed) + 1;
    if (why >= 0 && why < kGvWhyCount)
        g_gvByWhy[why].fetch_add(1, std::memory_order_relaxed);
    uint32_t cur = g_gvLo.load(std::memory_order_relaxed);
    while (guestAddr < cur && !g_gvLo.compare_exchange_weak(cur, guestAddr, std::memory_order_relaxed)) {}
    cur = g_gvHi.load(std::memory_order_relaxed);
    while (guestAddr > cur && !g_gvHi.compare_exchange_weak(cur, guestAddr, std::memory_order_relaxed)) {}
    const uintptr_t mbase = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
    const uintptr_t cabs = reinterpret_cast<uintptr_t>(ra);
    const uint64_t caller_rva = (mbase && cabs > mbase) ? (cabs - mbase) : cabs;

    // Fabricated zero, on its OWN counter and its own cadence: if the main rows are all sampled
    // out, this one still reports, and a non-zero value cannot be argued down to a sampling
    // artefact because the cadence is printed in the row with its own total.
    if (guestAddr < kGvGuardPage) {
        const uint64_t f = g_gvFabZero.fetch_add(1, std::memory_order_relaxed) + 1;
        if (f <= kGvPrintFirst || (f % kGvPrintEvery) == 0) {
            const uint64_t frows = g_gvFabRows.fetch_add(1, std::memory_order_relaxed) + 1;
            MCLA_LOG_ERROR(
                "GUESTVIEW-U32-FABZERO #{} va={:08X} size=4 why={} fab_total={} fab_rows={} "
                "refusals_total={} caller_rva={:#x} tid={} - va is BELOW the 0x1000 guard-page floor: "
                "IsValidRange refused it, *outVal was NOT written, and ReadGuestU32 "
                "(src/guest_memory.h:82) drops the bool, so the RECOMPILER SAW THIS 0 AS MEMORY. "
                "No legitimate guest `lwz` can land here.",
                (unsigned long long)f, guestAddr, kGvU32WhyName[why], (unsigned long long)f,
                (unsigned long long)frows, (unsigned long long)n, caller_rva,
                GetCurrentThreadId());
        }
    }

    if (n > kGvPrintFirst && (n % kGvPrintEvery) != 0) return;  // sampled out; SUMMARY carries total

    const uint64_t rows = g_gvRows.fetch_add(1, std::memory_order_relaxed) + 1;
    const uint64_t total = g_gvTotal.load(std::memory_order_relaxed);
    const uint32_t lo = g_gvLo.load(std::memory_order_relaxed);
    const uint32_t hi = g_gvHi.load(std::memory_order_relaxed);
    const uint64_t fab = g_gvFabZero.load(std::memory_order_relaxed);
    MCLA_LOG_ERROR(
        "GUESTVIEW-U32-REFUSED #{} va={:08X} size=4 why={} av_code=0x{:X} av_addr=0x{:X} "
        "n={} rows={} dropped={} lo_va={:08X} hi_va={:08X} "
        "by_why=[range={} nullout={} av={}] fab_zero={} view_base=0x{:X} view_size=0x{:X} "
        "caller_rva={:#x} tid={} - ReadU32BE REFUSED, *outVal NOT written; ReadGuestU32 drops the "
        "bool, so this is a SILENT 0 to the recompiler (cadence: first {} then every {}th)",
        (unsigned long long)n, guestAddr, kGvU32WhyName[why], avCode, avAddr, (unsigned long long)n,
        (unsigned long long)rows, (unsigned long long)(total - rows),
        lo, hi, (unsigned long long)g_gvByWhy[kGvRange].load(std::memory_order_relaxed),
        (unsigned long long)g_gvByWhy[kGvNullOut].load(std::memory_order_relaxed),
        (unsigned long long)g_gvByWhy[kGvAv].load(std::memory_order_relaxed),
        (unsigned long long)fab, reinterpret_cast<uintptr_t>(viewBase), viewSize, caller_rva,
        GetCurrentThreadId(), (unsigned long long)kGvPrintFirst, (unsigned long long)kGvPrintEvery);

    // The SUMMARY is what makes "zero" and "sampled out" different readings of the same log:
    // no rows + no summary means total==0 for the whole run, which is the cause-(1) signature.
    if ((n % kGvPrintEvery) == 0) {
        MCLA_LOG_ERROR(
            "GUESTVIEW-U32-SUMMARY total={} rows={} dropped={} fab_zero={} fab_rows={} "
            "by_why=[range={} nullout={} av={}] lo_va={:08X} hi_va={:08X} view_base=0x{:X} "
            "view_size=0x{:X} tid={}",
            (unsigned long long)total, (unsigned long long)rows, (unsigned long long)(total - rows),
            (unsigned long long)fab, (unsigned long long)g_gvFabRows.load(std::memory_order_relaxed),
            (unsigned long long)g_gvByWhy[kGvRange].load(std::memory_order_relaxed),
            (unsigned long long)g_gvByWhy[kGvNullOut].load(std::memory_order_relaxed),
            (unsigned long long)g_gvByWhy[kGvAv].load(std::memory_order_relaxed),
            lo, hi, reinterpret_cast<uintptr_t>(viewBase), viewSize, GetCurrentThreadId());
    }
}
}  // namespace

// ===========================================================================
// F-635 (2026-10-01) -- IMPLEMENTATION OF THE `ctr` OUT-OF-RANGE CENSUS. The
// design, the range derivation and the guard-asymmetry note are all in
// src/guest_memory.h next to the macro; this is the counter.
// ===========================================================================
//
// REPEATED HERE BECAUSE IT IS THE PART THAT GETS COPIED: this counts and
// prints. It does not refuse. Control returns to the stock expansion
// immediately, the load executes, and the access violation still happens at the
// same address with the same registers. Rule 1 (census before fix) is why the
// refusal is somebody else's task.
//
// CADENCE. The XSF-LASTSERVE-MISMATCH marker shipped unconditional and wrote
// 8,649,924 rows = 96.91% of w687.log (F-634). Same failure class as F-054. So
// this one is bounded by construction:
//   rows 1..32          verbatim, unfiltered -- the first out-of-range `ctr` of a
//                       boot is the diagnostic one and a sparse sample would
//                       hide it (src/gpu_device.cpp:1709-1714)
//   then every 4096th   floor(N/4096) rows
//   powers of two       the SUMMARY, so a TRUNCATED soak still bounds the truth:
//                       the last SUMMARY's total=N is a power of two, so the true
//                       total is in [N, 2N) -- the property F-634 argued for and
//                       the reason there is no atexit (spdlog's sinks are gone by
//                       then: src/app.cpp:30-33, :173).
// ESTIMATED ROWS PER SOAK: w688.log contains ONE real C0000005 (rva 0x28EC537,
// thread 20864; the other row is the benign 0x406D1388 thread-exit pseudo-
// exception on thread 25980) and the thread is then parked, so the expected
// total is 1 and the expected output is 1 row + 1 SUMMARY = 2 rows. To exceed
// the ~200-row target, N would have to exceed ~668,000 out-of-range indirect
// calls in one soak; that number is the falsifier for the cadence, and a total
// of 0 is the falsifier for the RANGE (it would mean the predicate is wrong,
// not that the fault is gone).
//
// THE SETS ARE EXACT, NOT SAMPLED (F-634 JOB 2). `ctr` and `lr` cardinalities
// are exact and never capped, so "how many distinct bad `ctr` values" -- the
// question the rows cannot answer -- is answered by a number. The value LISTS
// are capped at kF635SetCap and always print `*_shown=` beside the exact count,
// so a capped list can never be read as the whole set.
// ===========================================================================
namespace mcla::native {
namespace census {
namespace {

constexpr uint64_t kF635Head = 32;      // first N out-of-range events, verbatim
constexpr uint64_t kF635Stride = 4096;  // then every Mth
constexpr size_t kF635SetCap = 64;      // value-list cap; COUNTS are uncapped

// One struct, one mutex: the counter and both sets must be snapshotted
// together or `total=` and `n_ctr=` are two different runs of the world. Same
// shape and same reason as MclaLastServeTally (src/gpu_device.cpp:1786-1791).
struct F635Tally {
    std::mutex mtx;
    uint64_t total = 0;  // EXACT out-of-range count, never sampled, never capped
    uint64_t rows = 0;   // EXACT count of F635-CTR-OOR rows actually printed
    std::unordered_set<uint32_t> ctrs;
    std::unordered_set<uint32_t> lrs;
};

F635Tally g_f635;

// Sorted so two soaks diff; capped so a pathological population cannot re-
// poison the log this marker exists to keep readable. The caller prints the
// exact size; this only bounds the text.
std::string JoinCapped(const std::unordered_set<uint32_t>& s, size_t* shown) {
    std::vector<uint32_t> v(s.begin(), s.end());
    std::sort(v.begin(), v.end());
    if (v.size() > kF635SetCap)
        v.resize(kF635SetCap);
    std::string out;
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            out += ',';
        char buf[16];
        std::snprintf(buf, sizeof(buf), "%08X", v[i]);
        out += buf;
    }
    *shown = v.size();
    return out;
}

}  // namespace

void ReportCtrOutOfRange(uint32_t ctr, uintptr_t base, uint32_t lr) {
    // Recompute the address from the SAME expression the macro loads through, so
    // `load_addr=` is the number the CPU used and not a re-derivation. Verified
    // against w688.log: base=0x100000000, ctr=0 -> 0x7E780000 = logged Param[1].
    const uint64_t slotOff = (static_cast<uint64_t>(ctr) - kPpcCodeBase) * 2u;
    const uint64_t slotVa = static_cast<uint64_t>(kFuncTableGuestVa) + slotOff;
    const uint64_t loadAddr = static_cast<uint64_t>(base) + slotVa;
    const uint64_t ctrSpanHi = static_cast<uint64_t>(kCtrLo) + kCtrSpan;

    // Host site, so a row names the call even where `lr` does not (below).
    const uintptr_t mbase = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
    const uintptr_t cabs = reinterpret_cast<uintptr_t>(_ReturnAddress());
    const uint64_t callerRva = (mbase && cabs > mbase) ? (cabs - mbase) : cabs;

    uint64_t n = 0;
    bool printRow = false;
    bool printSummary = false;
    uint64_t total = 0;
    uint64_t rows = 0;
    size_t nCtr = 0;
    size_t nLr = 0;
    size_t shownCtr = 0;
    size_t shownLr = 0;
    std::string sCtr;
    std::string sLr;
    {
        std::lock_guard<std::mutex> lk(g_f635.mtx);
        n = ++g_f635.total;
        g_f635.ctrs.insert(ctr);
        g_f635.lrs.insert(lr);
        // `n` is the EXACT ordinal, so the printed `#` is the true event index,
        // never a row counter (F-634's point about XSF-LASTSERVE-MISMATCH).
        printRow = (n <= kF635Head) || ((n % kF635Stride) == 0);
        if (printRow)
            ++g_f635.rows;
        // Powers of two: guarantees a SUMMARY after a single event (1 is 2^0)
        // and bounds a truncated soak's true total to [N, 2N).
        printSummary = ((n & (n - 1)) == 0);
        if (printRow || printSummary) {
            total = g_f635.total;
            rows = g_f635.rows;
            nCtr = g_f635.ctrs.size();
            nLr = g_f635.lrs.size();
            sCtr = JoinCapped(g_f635.ctrs, &shownCtr);
            sLr = JoinCapped(g_f635.lrs, &shownLr);
        }
    }  // snapshot under the lock, emit outside it

    if (printRow) {
        // `lr` is ctx.lr, i.e. the guest return address the recompiler wrote on
        // the line above the macro (14,304 of 14,832 sites -- measured). The
        // other 528 sites emit no `ctx.lr = ` at all, so there `lr` is INHERITED
        // from the guest and is not this call's site; `caller_rva` is the
        // disambiguator for those (resolve it with tools/host_rva_resolve.py
        // against the same build's build/mcla.map). It is not printed as 0 when
        // unavailable, because a fabricated 0 reads as a measurement.
        MCLA_LOG_ERROR(
            "F635-CTR-OOR #{} ctr={:08X} slot_off=0x{:X} slot_guest_va=0x{:X} load_addr=0x{:X} "
            "base=0x{:X} lr={:08X} caller_rva={:#x} tid={} n={} total={} rows={} dropped={} "
            "n_ctr={} ctr_set_shown={} n_lr={} lr_set_shown={} ctr_set=[{}] lr_set=[{}] "
            "in_range=[{:08X},{:08X}] - CENSUS, NOT A FIX, NO REFUSAL: this `ctr` is outside "
            "the span every function-table registration in this tree has ever used, so "
            "PPC_LOOKUP_FUNC indexed the guest image at ctr_set address ABOVE; the stock "
            "load then ran unchanged and faulted as it always does. Resolve caller_rva with "
            "tools/host_rva_resolve.py. CADENCE: first {} verbatim then every {}th; the "
            "-SUMMARY carries the EXACT total and EXACT distinct counts.",
            (unsigned long long)n, ctr, (unsigned long long)slotOff,
            (unsigned long long)slotVa, (unsigned long long)loadAddr, (unsigned long long)base, lr,
            (unsigned long long)callerRva, GetCurrentThreadId(), (unsigned long long)n,
            (unsigned long long)total, (unsigned long long)rows, (unsigned long long)(total - rows),
            (unsigned long long)nCtr, (unsigned long long)shownCtr, (unsigned long long)nLr,
            (unsigned long long)shownLr, sCtr, sLr, kCtrLo, ctrSpanHi,
            (unsigned long long)kF635Head, (unsigned long long)kF635Stride);
    }
    if (printSummary) {
        MCLA_LOG_ERROR(
            "F635-CTR-OOR-SUMMARY total={} rows={} dropped={} n_ctr={} ctr_set_shown={} "
            "n_lr={} lr_set_shown={} ctr_set=[{}] lr_set=[{}] in_range=[{:08X},{:08X}] "
            "tid={} - EXACT totals: `total` is every out-of-range `ctr`, `rows` is how many "
            "F635-CTR-OOR rows were printed, so total-rows=dropped by sampling and NOT by "
            "discard. total==0 across a full soak that still faults means the RANGE is wrong.",
            (unsigned long long)total, (unsigned long long)rows,
            (unsigned long long)(total - rows), (unsigned long long)nCtr,
            (unsigned long long)shownCtr, (unsigned long long)nLr, (unsigned long long)shownLr,
            sCtr, sLr, kCtrLo, ctrSpanHi, GetCurrentThreadId());
    }
}

}  // namespace census
}  // namespace mcla::native

namespace mcla::native {

GuestMemoryView::GuestMemoryView() = default;

void GuestMemoryView::SetMemoryBase(uint8_t* base, uint64_t size) {
    m_base = base;
    m_size = size;
    MCLA_LOG_INFO("GuestMemoryView: memory base=0x{:p} size=0x{:X} ({} MB)",
                (void*)base, size, size / (1024 * 1024));
}

bool GuestMemoryView::IsValidRange(uint32_t guestAddr, uint32_t size) const {
    // Reject the NOACCESS guard page (first 4 KiB) so zero-base reads
    // (e.g. uninitialized r2/TOC) log as invalid instead of AV-ing.
    if (guestAddr < 0x1000 || size == 0) return false;

    const uint64_t end = static_cast<uint64_t>(guestAddr) + size;
    if (end > 0x100000000ULL) return false;

    if (!m_base) return false;
    if (guestAddr >= m_size) return false;
    if (end > m_size) return false;

    return true;
}

const uint8_t* GuestMemoryView::GetHostPtr(uint32_t guestAddr, uint32_t size) const {
    if (!IsValidRange(guestAddr, size)) return nullptr;
    return m_base + guestAddr;
}

uint8_t* GuestMemoryView::GetHostPtrMutable(uint32_t guestAddr, uint32_t size) const {
    if (!IsValidRange(guestAddr, size)) return nullptr;
    return m_base + guestAddr;
}

bool GuestMemoryView::ReadU8(uint32_t guestAddr, uint8_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint8_t));
    if (!ptr || !outVal) return false;
    *outVal = *ptr;
    return true;
}

bool GuestMemoryView::ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint16_t));
    if (!ptr || !outVal) return false;
    uint16_t val;
    std::memcpy(&val, ptr, sizeof(val));
    *outVal = Swap16(val);
    return true;
}

bool GuestMemoryView::ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const {
    if ((guestAddr & 0xFFFF0000u) == 0x7FC80000u) {
        GpuMmioReadFn handler = GetGpuMmioReadHandler();
        if (handler && outVal && handler(guestAddr, outVal)) return true;
    }
    // F-633: the two refusal sites below are instrumented; nothing else about this function
    // changes. `!ptr` and `!outVal` used to share one guard and so could not be told apart in the
    // log -- they are different bugs (an out-of-range VA vs a caller passing no destination), so
    // they are now split. Same two `return false`, same untouched *outVal.
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint32_t));
    if (!ptr) {
        ReportGuestViewU32Refused(guestAddr, kGvRange, 0, 0, _ReturnAddress(), m_base, m_size);
        return false;
    }
    if (!outVal) {
        ReportGuestViewU32Refused(guestAddr, kGvNullOut, 0, 0, _ReturnAddress(), m_base, m_size);
        return false;
    }
    // F-633: capture the AV, then log OUTSIDE the SEH scope -- formatting while an access
    // violation is being handled can itself fault (same reasoning as src/kernel/memory.cpp:53-57).
    GvU32Fault fault;
    bool av = false;
    __try
    {
        uint32_t val;
        std::memcpy(&val, ptr, sizeof(val));
        *outVal = Swap32(val);
    }
    __except (GvU32AvFilter(GetExceptionInformation(), &fault)) { av = true; }
    if (av) {
        ReportGuestViewU32Refused(guestAddr, kGvAv, fault.code, fault.addr, _ReturnAddress(),
                                  m_base, m_size);
        return false;
    }
    if (PageWatchHit(guestAddr))
        mcla::gpu::PageWatchOnRead(guestAddr, *outVal);
    return true;
}

bool GuestMemoryView::ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint64_t));
    if (!ptr || !outVal) return false;
    __try
    {
        uint64_t val;
        std::memcpy(&val, ptr, sizeof(val));
        *outVal = Swap64(val);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    return true;
}

bool GuestMemoryView::ReadF32BE(uint32_t guestAddr, float* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(float));
    if (!ptr || !outVal) return false;
    __try
    {
        uint32_t val;
        std::memcpy(&val, ptr, sizeof(val));
        uint32_t swapped = Swap32(val);
        std::memcpy(outVal, &swapped, sizeof(float));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    return true;
}

bool GuestMemoryView::ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, size);
    if (!ptr || !outBuffer) return false;
    __try
    {
        std::memcpy(outBuffer, ptr, size);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    return true;
}

bool GuestMemoryView::WriteU8(uint32_t guestAddr, uint8_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint8_t));
    if (!ptr) return false;
    // F-784: T44 wipe watch. A byte store never reaches the value watch below
    // (Session 73's own note), so the address test has to be explicit here.
    // `pre` is captured inside the __try so it is only ever a value this
    // function actually read.
    const bool t44 = mcla::gpu::T44WipeOverlaps(guestAddr, sizeof(uint8_t));
    uint32_t t44Pre = 0;
    __try {
        if (t44) {
            uint8_t raw = 0;
            std::memcpy(&raw, ptr, sizeof(raw));
            t44Pre = raw;
        }
        *ptr = val;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    if (t44)
        mcla::gpu::T44WipeNote("U8", guestAddr, 1, val, t44Pre, 1, _ReturnAddress());
    // Session 73: byte-wide 0xCD fills bypassed the value watch entirely.
    // Route them into the watch (synthetic word value) so registered ranges
    // get LR attribution for byte fill loops (memset alignment head etc.).
    if (val == 0xCDu && PageWatchHit(guestAddr))
        mcla::gpu::PageWatchOnWrite(guestAddr, 0xCDCDCDCDu);
    return true;
}

bool GuestMemoryView::WriteU16BE(uint32_t guestAddr, uint16_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint16_t));
    if (!ptr) return false;
    // F-784: T44 wipe watch, same shape as WriteU8 above.
    const bool t44 = mcla::gpu::T44WipeOverlaps(guestAddr, sizeof(uint16_t));
    uint32_t t44Pre = 0;
    __try
    {
        if (t44) {
            uint16_t raw = 0;
            std::memcpy(&raw, ptr, sizeof(raw));
            t44Pre = Swap16(raw);
        }
        uint16_t be = Swap16(val);
        std::memcpy(ptr, &be, sizeof(be));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    if (t44)
        mcla::gpu::T44WipeNote("U16", guestAddr, 2, val, t44Pre, 2, _ReturnAddress());
    // Session 73: same as WriteU8 — halfword 0xCDCD stores were unwatched.
    if (val == 0xCDCDu && PageWatchHit(guestAddr))
        mcla::gpu::PageWatchOnWrite(guestAddr, 0xCDCDCDCDu);
    return true;
}

bool GuestMemoryView::WriteU32BE(uint32_t guestAddr, uint32_t val) const {
    if ((guestAddr & 0xFFFF0000u) == 0x7FC80000u) {
        GpuMmioWriteFn handler = GetGpuMmioWriteHandler();
        if (handler && handler(guestAddr, val)) return true;
    }
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint32_t));
    if (!ptr) return false;
    if (const int wi = HeapInstanceStoreHit(guestAddr); wi >= 0)
        ReportHeapInstanceStore("U32", guestAddr, val, _ReturnAddress(), (size_t)wi);
    // F-784: T44 wipe watch -- address test + pre-copy snapshot of the dword
    // this store is about to replace, so the row can show header-was-live.
    const bool t44 = mcla::gpu::T44WipeOverlaps(guestAddr, sizeof(uint32_t));
    uint32_t t44Pre = 0;
    __try
    {
        if (t44) {
            uint32_t raw = 0;
            std::memcpy(&raw, ptr, sizeof(raw));
            t44Pre = Swap32(raw);
        }
        uint32_t be = Swap32(val);
        std::memcpy(ptr, &be, sizeof(be));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    if (t44)
        mcla::gpu::T44WipeNote("U32", guestAddr, 4, val, t44Pre, 4, _ReturnAddress());
    if (PageWatchHit(guestAddr))
        mcla::gpu::PageWatchOnWrite(guestAddr, val);
    else if (WatchValueHit(val))
        mcla::gpu::PageWatchOnWrite(guestAddr, val);
    return true;
}

bool GuestMemoryView::WriteU64BE(uint32_t guestAddr, uint64_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint64_t));
    if (!ptr) return false;
    if (const int wi = HeapInstanceStoreHit(guestAddr); wi >= 0)
        ReportHeapInstanceStore("U64", guestAddr, val, _ReturnAddress(), (size_t)wi);
    // F-784: T44 wipe watch -- the 8 bytes this store replaces.
    const bool t44 = mcla::gpu::T44WipeOverlaps(guestAddr, sizeof(uint64_t));
    uint64_t t44Pre = 0;
    __try
    {
        if (t44) {
            uint64_t raw = 0;
            std::memcpy(&raw, ptr, sizeof(raw));
            t44Pre = Swap64(raw);
        }
        uint64_t be = Swap64(val);
        std::memcpy(ptr, &be, sizeof(be));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    if (t44)
        mcla::gpu::T44WipeNote("U64", guestAddr, 8, val, t44Pre, 8, _ReturnAddress());
    if (PageWatchHit(guestAddr) || PageWatchHit(guestAddr + 4))
    {
        mcla::gpu::PageWatchOnWrite(guestAddr, static_cast<uint32_t>(val >> 32));
        mcla::gpu::PageWatchOnWrite(guestAddr + 4, static_cast<uint32_t>(val));
    }
    else if (WatchValueHit(static_cast<uint32_t>(val >> 32)) ||
             WatchValueHit(static_cast<uint32_t>(val)))
    {
        mcla::gpu::PageWatchOnWrite(guestAddr, static_cast<uint32_t>(val >> 32));
        mcla::gpu::PageWatchOnWrite(guestAddr + 4, static_cast<uint32_t>(val));
    }
    return true;
}

bool GuestMemoryView::WriteBytes(uint32_t guestAddr, const void* src, uint32_t size) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, size);
    if (!ptr || !src) return false;
    // F-784: T44 wipe watch. The span test runs BEFORE the copy so `pre` is the
    // true prior content of the first overlapped bytes, and this is the only
    // entry point that knows how many bytes the copy actually moved -- the
    // per-dword arms can report a sweep only store by store (F-631's lesson,
    // guest_memory.cpp:40-50). `pre`/`post` hold up to 8 memory-order bytes,
    // zero-padded on the right when the overlap is shorter; `pre_n` says how
    // many of them were really read.
    uint32_t t44Va = 0, t44Len = 0, t44Off = 0, t44Cap = 0;
    uint64_t t44Pre = 0;
    const bool t44 = mcla::gpu::T44WipeSpan(guestAddr, size, &t44Va, &t44Len);
    if (t44) {
        t44Off = t44Va - guestAddr;
        const uint32_t rem = size - t44Off;
        t44Cap = rem < 8u ? rem : 8u;
    }
    __try
    {
        if (t44) {
            uint64_t raw = 0;
            std::memcpy(&raw, ptr + t44Off, t44Cap);
            t44Pre = _byteswap_uint64(raw);
        }
        std::memcpy(ptr, src, size);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    if (t44) {
        uint64_t t44Post = 0;
        __try
        {
            uint64_t raw = 0;
            std::memcpy(&raw, ptr + t44Off, t44Cap);
            t44Post = _byteswap_uint64(raw);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) { t44Post = 0; }
        mcla::gpu::T44WipeNote("BULK", t44Va, t44Len, t44Post, t44Pre, t44Cap,
                               _ReturnAddress());
    }
    // F-631: the heap-window EXTENT census, and the only place in this file that knows how many
    // bytes a bulk copy actually moved. `WriteBytes` had no heap-window arm at all, so a guest
    // `memset` of megabytes across 0x20000 was visible only as the handful of dword stores that
    // happened to land inside the 0x240-byte census window (guest_memory.cpp:55-56) -- which is how
    // eight rows came to be read as a complete event in F-630. One row here says the whole thing:
    // destination, length, and how much of the length overlapped the window. Placed after the
    // `__except` so it reports only copies that actually landed, and before the `size >= 4` block
    // so it does not depend on the copy being long enough to have endpoints.
    if (const int wi = HeapWindowOverlaps(guestAddr, size); wi >= 0)
        ReportHeapWindowExtent("bulk", guestAddr, size, _ReturnAddress(), (size_t)wi);
    if (size >= 4)
    {
        // Watch coverage for bulk copies of ANY size: check first + last
        // dword against range and value watches, AND overlap of the whole
        // span against watched ranges (session 73 — a copy spanning a
        // watched region previously evaded both endpoint probes).
        uint32_t vFirst = 0, vLast = 0;
        std::memcpy(&vFirst, ptr, sizeof(vFirst));
        std::memcpy(&vLast, ptr + size - sizeof(uint32_t), sizeof(vLast));
        vFirst = Swap32(vFirst);
        vLast = Swap32(vLast);
        const bool rangeHit = PageWatchHit(guestAddr) ||
                              PageWatchHit(guestAddr + size - 4) ||
                              RangeOverlapsWatch(guestAddr, size);
        const bool valueHit =
            WatchValueHit(vFirst) || WatchValueHit(vLast);
        if (rangeHit || valueHit)
        {
            mcla::gpu::PageWatchOnWrite(guestAddr, vFirst);
            if (size > 4)
            {
                mcla::gpu::PageWatchOnWrite(guestAddr + size - 4, vLast);
            }
        }
    }
    return true;
}

namespace {
mcla::native::GuestMemoryView* g_activeGuestMemoryView = nullptr;
}

mcla::native::GuestMemoryView& GetActiveGuestMemoryView() {
    static mcla::native::GuestMemoryView fallback;
    return g_activeGuestMemoryView ? *g_activeGuestMemoryView : fallback;
}

void SetActiveGuestMemoryView(mcla::native::GuestMemoryView* view) {
    g_activeGuestMemoryView = view;
}

namespace {
GpuMmioWriteFn g_gpuMmioWriteHandler = nullptr;
GpuMmioReadFn g_gpuMmioReadHandler = nullptr;
} // namespace

void SetGpuMmioHandlers(GpuMmioWriteFn writeFn, GpuMmioReadFn readFn) {
    g_gpuMmioWriteHandler = writeFn;
    g_gpuMmioReadHandler = readFn;
}

GpuMmioWriteFn GetGpuMmioWriteHandler() { return g_gpuMmioWriteHandler; }
GpuMmioReadFn GetGpuMmioReadHandler() { return g_gpuMmioReadHandler; }

bool VerifyGuestMemoryViewForTests() {
    GuestMemoryView view;

    // Guest addr 0 is a NOACCESS guard page (IsValidRange rejects < 0x1000).
    // Use a buffer large enough that guest addrs 0x1000/0x1004/0x2000 land
    // inside it — the old test used 0x100/0x200 and always failed after the
    // guard-page rejection landed (session 73).
    constexpr uint32_t kBase = 0x1000;
    uint8_t testMem[0x3000] = {0};
    view.SetMemoryBase(testMem, sizeof(testMem));

    if (view.IsValidRange(0, 1)) return false;
    if (view.IsValidRange(0x1000, 0)) return false;
    if (view.IsValidRange(0x20000000, 0xF0000000)) return false;
    if (view.GetHostPtr(0x12345678, 0)) return false;
    if (view.ReadU32BE(0, nullptr)) return false;

    uint32_t scratch = 0;
    if (view.ReadU32BE(0, &scratch)) return false;
    if (view.ReadU32BE(0x100, &scratch)) return false; // below guard page

    // Test valid reads (host offsets = guestAddr, identity map)
    testMem[kBase + 0] = 0x12;
    testMem[kBase + 1] = 0x34;
    testMem[kBase + 2] = 0x56;
    testMem[kBase + 3] = 0x78;

    uint32_t val32 = 0;
    if (!view.ReadU32BE(kBase, &val32)) return false;
    if (val32 != 0x12345678) return false;

    uint16_t val16 = 0;
    if (!view.ReadU16BE(kBase, &val16)) return false;
    if (val16 != 0x1234) return false;

    if (!view.WriteU16BE(0x2000, 0xAABB)) return false;
    if (testMem[0x2000] != 0xAA || testMem[0x2001] != 0xBB) return false;

    return true;
}

uint64_t QueryGuestTimebase() {
    LARGE_INTEGER freq;
    LARGE_INTEGER counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    // Scale to ~800 MHz (Xenon timebase = CPU/4, 3.2 GHz / 4 = 800 MHz)
    // freq is in Hz, so multiply by 800e6 / freq.QuadPart
    const uint64_t now =
        (static_cast<uint64_t>(counter.QuadPart) * 800000000ULL) /
        static_cast<uint64_t>(freq.QuadPart > 0 ? freq.QuadPart : 1);
    // T43.18 (2026-10-13, taken from LARecomp's clock lesson): monotonic
    // max-latch. QPC is monotonic on healthy HALs, but a backward step on
    // VMs/buggy firmware would rewind guest time and spiral timer-driven
    // guest code the way their vblank catch-up did. The latch is identity
    // on a healthy clock; a clamp prints (throttled) so a silent rewind
    // can never hide here. Log-only; no guest behavior changes while the
    // clock behaves.
    static std::atomic<uint64_t> s_maxTick{0};
    static std::atomic<uint64_t> s_clamps{0};
    uint64_t prev = s_maxTick.load(std::memory_order_relaxed);
    while (prev < now &&
           !s_maxTick.compare_exchange_weak(prev, now, std::memory_order_relaxed)) {
    }
    if (now < prev) {
        const uint64_t n = s_clamps.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 4 || (n % 1000u) == 0u) {
            MCLA_LOG_WARN("TIMEBASE-CLAMP #{} now={} held={} (host clock "
                          "stepped backward; holding last tick)",
                          n, now, prev);
        }
        return prev;
    }
    return now;
}

} // namespace mcla::native