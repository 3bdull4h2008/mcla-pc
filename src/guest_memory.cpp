#include "guest_memory.h"
#include "kernel/heap_arena.h"  // F-384: kUserHeapArenaVa, so the census follows the arena
#include "logging.h"
#include <atomic>
#include <intrin.h>   // F-374b: _ReturnAddress() for the heap-instance store report
#include <windows.h>   // F-374b: GetModuleHandleA() to turn the caller into an RVA
#include <cstring>
#include <mutex>

// PAGE-WATCH hooks (session 24): defined in gpu_cp.cpp which owns the full
// PPCContext includes - keeps this hot-path TU free of ABI header chains.
namespace mcla::gpu {
void PageWatchOnWrite(uint32_t guestAddr, uint32_t value);
void PageWatchOnRead(uint32_t guestAddr, uint32_t value);
// F-375: gpu_cp.cpp owns the PPCContext includes, so the guest-side argument dump for a store
// that reached the host heap instance lives there (see ReportHeapInstanceStore below).
void HeapInstanceStoreReport(uint32_t guestAddr, uint32_t value);
} // namespace mcla::gpu

static constexpr uint32_t kWatchPage = 0x50000000u;

// F-374b: the guest user heap's o1heap INSTANCE occupies guest 0x20000..0x20240 (src/kernel/
// o1heap.c:133-138 -- 64 free-bin pointers, a bin mask, then the diagnostics block; `capacity` is
// the constant at +0x208). Only o1heap writes there, and it does so through raw host pointers. A
// store that reaches that window through the GUEST-facing checked writers is a wild destination by
// definition: the F-374 guard page caught exactly one such store live in w382.log (17:30:56.311,
// hostRIP = GuestMemoryView::WriteU32BE+0x7d, guest lr 821BC998), and 155 ms later Heap::Alloc
// began refusing every request -- F-370's dead header and uncreated thread #16. This names the
// CALLER of the store, which is the line to fix:
//     python tools/host_rva_resolve.py build/mcla.map <caller_rva>
namespace {
// F-384: these two follow the arena; they are NOT a hardcoded address any more. Watching a stale
// range after a relocated arena would read as "the corruption stopped" when it only moved out of
// sight -- the values now come from the single definition in `src/kernel/heap.h`.
constexpr uint32_t kHeapInstanceLo = mcla::kernel::kUserHeapArenaVa;
constexpr uint32_t kHeapInstanceHi = mcla::kernel::kUserHeapArenaVa + 0x240u;

inline bool HeapInstanceStoreHit(uint32_t guestAddr) {
    return guestAddr >= kHeapInstanceLo && guestAddr < kHeapInstanceHi;
}

void ReportHeapInstanceStore(const char *op, uint32_t guestAddr, uint64_t val, void *ra) {
    static std::atomic<uint32_t> s_storeN{0};
    const uint32_t n = s_storeN.fetch_add(1) + 1;
    // F-379: the old hard cap (`n > 16`) made the burst length unmeasurable -- w387 and w388 both
    // printed exactly 16 rows regardless of how long the copy actually was, so "16 dwords" was the
    // cap, not a measurement. First 16 plus every 4096th row keeps a short burst complete (cap-shape
    // rule) while making a long one visible. tid separates bursts from different threads.
    if (n > 16 && (n % 4096) != 0) return;
    const uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
    const uintptr_t abs = reinterpret_cast<uintptr_t>(ra);
    MCLA_LOG_ERROR("F374-HEAPSTORE #{} op={} guest={:08X} inst_off={:#x} val={:#x} "
                   "caller_rva={:#x} tid={}",
                   n, op, guestAddr, guestAddr - kHeapInstanceLo, val, base ? abs - base : abs,
                   GetCurrentThreadId());
    mcla::gpu::HeapInstanceStoreReport(guestAddr, static_cast<uint32_t>(val));
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
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint32_t));
    if (!ptr || !outVal) return false;
    __try
    {
        uint32_t val;
        std::memcpy(&val, ptr, sizeof(val));
        *outVal = Swap32(val);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
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
    __try { *ptr = val; }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
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
    __try
    {
        uint16_t be = Swap16(val);
        std::memcpy(ptr, &be, sizeof(be));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
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
    if (HeapInstanceStoreHit(guestAddr))
        ReportHeapInstanceStore("U32", guestAddr, val, _ReturnAddress());
    __try
    {
        uint32_t be = Swap32(val);
        std::memcpy(ptr, &be, sizeof(be));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
    if (PageWatchHit(guestAddr))
        mcla::gpu::PageWatchOnWrite(guestAddr, val);
    else if (WatchValueHit(val))
        mcla::gpu::PageWatchOnWrite(guestAddr, val);
    return true;
}

bool GuestMemoryView::WriteU64BE(uint32_t guestAddr, uint64_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint64_t));
    if (!ptr) return false;
    if (HeapInstanceStoreHit(guestAddr))
        ReportHeapInstanceStore("U64", guestAddr, val, _ReturnAddress());
    __try
    {
        uint64_t be = Swap64(val);
        std::memcpy(ptr, &be, sizeof(be));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
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
    __try
    {
        std::memcpy(ptr, src, size);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
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
    return (counter.QuadPart * 800000000ULL) / freq.QuadPart;
}

} // namespace mcla::native