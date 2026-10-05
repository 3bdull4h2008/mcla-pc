#include <stdafx.h>
#include "memory.h"
#include "heap.h"
#include <atomic>
#include "logging.h"

// --- GUEST-LOAD-REFUSED / GUEST-REFUSED-SUM ----------------------------------
// INSTRUMENT ONLY. It records refusals; it never writes *outVal, never changes a
// return value, and never touches a caller.
//
// WHY. Every GuestMemoryHeap::Read* below refuses by `return false` WITHOUT
// writing *outVal, and callers that drop the bool turn that into a silent 0
// (src/gpu_cp.cpp:2096 and :2816 are `(void)...ReadU32BE(...)`). A refused read
// is then indistinguishable from a guest word that really is 0. This is the
// discriminator for the two competing causes of the current boot's only
// C0000005 (guest 0x825FB348; host generated/ppc_xenon/ppc_recomp.121.cpp:25113
// PPC_CALL_INDIRECT_FUNC(ctr.u32) reached with ctr==0):
//   #1 the guest's *(obj+12) really is 0  -> GUEST-REFUSED-SUM total=0
//   #2 the host fabricated that 0         -> GUEST-REFUSED-SUM total>0
//
// FLOOD CONTROL. These reads sit in the host hot path (gpu_cp.cpp:4078 and :2821
// call ReadU32BE per loop element), so one persistently out-of-range pointer can
// refuse thousands of times per frame. F-054: a marker that fires 2,000,000
// times poisons the log. So the first 16 refusals print, then every 4096th, and
// GUEST-REFUSED-SUM prints on that SAME cadence carrying the true `total` and the
// number of rows deliberately dropped (`dropped`). That is the F-379/F-631
// cap-shape rule: a short burst stays complete, a long one stays visible, and
// total/dropped stop a reader mistaking the sample for the whole (F-630).
// lo_va/hi_va bound the refused addresses, so "is the va inside the crashing
// object's vtable chain" is answerable from the log without a re-run.
// Because both markers are emission-only, ABSENCE of both across a full soak is
// itself the measurement: total == 0.
//
// `why` is the check that refused: range = !IsValid(), av = the __try guard
// caught an access violation, nullout = null out-pointer.

namespace {

enum RefusedSite {
    kRefU8 = 0, kRefU16, kRefU32, kRefU64, kRefF32, kRefBytes, kRefSiteCount
};

constexpr uint64_t kRefPrintFirst = 16;
constexpr uint64_t kRefPrintEvery = 4096;

std::atomic<uint64_t> g_refusedTotal{0};  // every refusal, printed or not
std::atomic<uint64_t> g_refusedRows{0};   // rows actually printed
std::atomic<uint64_t> g_refusedBySite[kRefSiteCount]{};
std::atomic<uint32_t> g_refusedLo{0};
std::atomic<uint32_t> g_refusedHi{0};
std::atomic<bool> g_refusedAny{false};

// Captured inside the SEH filter, formatted OUTSIDE the handler: allocating for
// fmt/spdlog while an access violation is being handled can itself fault.
// A filter expression must be a constant expression, so this is a named
// function (it cannot be written as an inline-parameter call) and is invoked as
// __except (GuestLoadAvFilter(GetExceptionInformation(), &fault), EXCEPTION_EXECUTE_HANDLER).
struct GuestLoadFault {
    unsigned long code = 0;
    unsigned long long addr = 0;
};

int GuestLoadAvFilter(EXCEPTION_POINTERS* ep, void* ctx) {
    auto* f = static_cast<GuestLoadFault*>(ctx);
    if (ep && ep->ExceptionRecord) {
        f->code = ep->ExceptionRecord->ExceptionCode;
        // Information[1] is the faulting DATA address; [0] is the access type.
        if (ep->ExceptionRecord->NumberParameters >= 2)
            f->addr = ep->ExceptionRecord->ExceptionInformation[1];
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

void LogGuestLoadRefused(const char* fn, uint32_t va, size_t size, const char* why, int site,
                         unsigned long av_code, unsigned long long av_addr) {
    uint32_t cur = g_refusedLo.load(std::memory_order_relaxed);
    while (va < cur && !g_refusedLo.compare_exchange_weak(cur, va, std::memory_order_relaxed)) {}
    cur = g_refusedHi.load(std::memory_order_relaxed);
    while (va > cur && !g_refusedHi.compare_exchange_weak(cur, va, std::memory_order_relaxed)) {}
    g_refusedAny.store(true, std::memory_order_relaxed);

    const uint64_t n = g_refusedTotal.fetch_add(1, std::memory_order_relaxed) + 1;
    g_refusedBySite[site].fetch_add(1, std::memory_order_relaxed);
    if (n > kRefPrintFirst && (n % kRefPrintEvery) != 0)
        return;  // sampled out; the sum line below carries the true total

    const uint64_t rows = g_refusedRows.fetch_add(1, std::memory_order_relaxed) + 1;
    const uint64_t total = g_refusedTotal.load(std::memory_order_relaxed);
    const uint32_t lo = g_refusedAny.load(std::memory_order_relaxed)
                            ? g_refusedLo.load(std::memory_order_relaxed) : 0;
    const uint32_t hi = g_refusedHi.load(std::memory_order_relaxed);
    MCLA_LOG_ERROR(
        "GUEST-LOAD-REFUSED va={:08X} size={} why={} fn={} n={} av_code=0x{:X} av_addr=0x{:X} - "
        "checked read REFUSED, *outVal NOT written: a caller that drops the bool sees a SILENT 0",
        va, size, why, fn, n, av_code, av_addr);
    MCLA_LOG_ERROR(
        "GUEST-REFUSED-SUM total={} rows={} dropped={} fn={} why={} va={:08X} lo_va={:08X} "
        "hi_va={:08X} by_site=[u8={} u16={} u32={} u64={} f32={} bytes={}]",
        (unsigned long long)total, (unsigned long long)rows,
        (unsigned long long)(total - rows), fn, why, va, lo, hi,
        (unsigned long long)g_refusedBySite[kRefU8].load(std::memory_order_relaxed),
        (unsigned long long)g_refusedBySite[kRefU16].load(std::memory_order_relaxed),
        (unsigned long long)g_refusedBySite[kRefU32].load(std::memory_order_relaxed),
        (unsigned long long)g_refusedBySite[kRefU64].load(std::memory_order_relaxed),
        (unsigned long long)g_refusedBySite[kRefF32].load(std::memory_order_relaxed),
        (unsigned long long)g_refusedBySite[kRefBytes].load(std::memory_order_relaxed));
}

}  // namespace

mcla::kernel::Memory::Memory()
{
#ifdef _WIN32
    // First check if memory is already reserved or committed at the target address
    MEMORY_BASIC_INFORMATION mbi;
    if (VirtualQuery((void*)0x100000000ull, &mbi, sizeof(mbi)) == sizeof(mbi) && 
        (mbi.State == MEM_RESERVE || mbi.State == MEM_COMMIT))
    {
        base = (uint8_t*)0x100000000ull;
    }
    else
    {
        base = (uint8_t*)VirtualAlloc((void*)0x100000000ull, PPC_MEMORY_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        if (base == nullptr)
            base = (uint8_t*)VirtualAlloc(nullptr, PPC_MEMORY_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    }

    if (base == nullptr)
        return;

    DWORD oldProtect;
    VirtualProtect(base, 4096, PAGE_NOACCESS, &oldProtect);
#else
    // MAP_FIXED_NOREPLACE below *is* the "already mapped there?" check: no
    // /proc/self/maps parse needed. The two fallbacks omit it and may relocate.
    base = (uint8_t*)mmap((void*)0x100000000ull, PPC_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE | MAP_FIXED_NOREPLACE, -1, 0);

    if (base == (uint8_t*)MAP_FAILED)
        base = (uint8_t*)mmap((void*)0x100000000ull, PPC_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (base == (uint8_t*)MAP_FAILED)
        base = (uint8_t*)mmap(NULL, PPC_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (base == nullptr)
        return;

    mprotect(base, 4096, PROT_NONE);
#endif

    // Record the window size: IsInMemoryRange and boot_host's full-4GiB reuse
    // test (boot_host.cpp:560) read it. Memory::Translate only asserts on it.
    size = PPC_MEMORY_SIZE;

    for (size_t i = 0; PPCFuncMappings[i].guest != 0; i++)
    {
        if (PPCFuncMappings[i].host != nullptr)
            InsertFunction(PPCFuncMappings[i].guest, PPCFuncMappings[i].host);
    }
}

void* MmGetHostAddress(uint32_t ptr)
{
    return mcla::kernel::g_memory.Translate(ptr);
}

// Checked, endian-explicit read/write helpers for GuestMemoryHeap
bool mcla::kernel::GuestMemoryHeap::ReadU8(uint32_t guestAddr, uint8_t* outVal) const
{
    // No __try here (and none in ReadU16BE): a bad pointer AVs instead of
    // refusing, so `why=av` can never originate from these two -- a silent zero
    // is impossible from ReadU8/ReadU16BE.
    if (!IsValid(guestAddr, sizeof(uint8_t)))
    {
        LogGuestLoadRefused("ReadU8", guestAddr, sizeof(uint8_t), "range", kRefU8, 0, 0);
        return false;
    }
    if (!outVal)
    {
        LogGuestLoadRefused("ReadU8", guestAddr, sizeof(uint8_t), "nullout", kRefU8, 0, 0);
        return false;
    }
    *outVal = *reinterpret_cast<const uint8_t*>(Translate(guestAddr));
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const
{
    if (!IsValid(guestAddr, sizeof(uint16_t)))
    {
        LogGuestLoadRefused("ReadU16BE", guestAddr, sizeof(uint16_t), "range", kRefU16, 0, 0);
        return false;
    }
    if (!outVal)
    {
        LogGuestLoadRefused("ReadU16BE", guestAddr, sizeof(uint16_t), "nullout", kRefU16, 0, 0);
        return false;
    }
    const uint16_t beVal = *reinterpret_cast<const uint16_t*>(Translate(guestAddr));
    *outVal = Swap16(beVal);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const
{
    if (!IsValid(guestAddr, sizeof(uint32_t)))
    {
        LogGuestLoadRefused("ReadU32BE", guestAddr, sizeof(uint32_t), "range", kRefU32, 0, 0);
        return false;
    }
    if (!outVal)
    {
        LogGuestLoadRefused("ReadU32BE", guestAddr, sizeof(uint32_t), "nullout", kRefU32, 0, 0);
        return false;
    }
    const uint8_t* ptr = static_cast<const uint8_t*>(Translate(guestAddr));
    bool ok = false;
    GuestLoadFault fault;  // filled by the filter, formatted outside the handler
    __try
    {
        const uint32_t beVal = *reinterpret_cast<const uint32_t*>(ptr);
        *outVal = Swap32(beVal);
        ok = true;
    }
    __except (GuestLoadAvFilter(GetExceptionInformation(), &fault), EXCEPTION_EXECUTE_HANDLER)
    {
        // The filter already recorded the code and the faulting address; nothing
        // is formatted while the exception is being handled.
    }
    if (!ok)
    {
        LogGuestLoadRefused("ReadU32BE", guestAddr, sizeof(uint32_t), "av", kRefU32,
                            fault.code, fault.addr);
    }
    return ok;
}

bool mcla::kernel::GuestMemoryHeap::ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const
{
    if (!IsValid(guestAddr, sizeof(uint64_t)))
    {
        LogGuestLoadRefused("ReadU64BE", guestAddr, sizeof(uint64_t), "range", kRefU64, 0, 0);
        return false;
    }
    if (!outVal)
    {
        LogGuestLoadRefused("ReadU64BE", guestAddr, sizeof(uint64_t), "nullout", kRefU64, 0, 0);
        return false;
    }
    const uint8_t* ptr = static_cast<const uint8_t*>(Translate(guestAddr));
    bool ok = false;
    GuestLoadFault fault;
    __try
    {
        const uint64_t beVal = *reinterpret_cast<const uint64_t*>(ptr);
        *outVal = Swap64(beVal);
        ok = true;
    }
    __except (GuestLoadAvFilter(GetExceptionInformation(), &fault), EXCEPTION_EXECUTE_HANDLER)
    {
    }
    if (!ok)
    {
        LogGuestLoadRefused("ReadU64BE", guestAddr, sizeof(uint64_t), "av", kRefU64,
                            fault.code, fault.addr);
    }
    return ok;
}

bool mcla::kernel::GuestMemoryHeap::ReadF32BE(uint32_t guestAddr, float* outVal) const
{
    // Instrumented too: if this guard refuses, the inner ReadU32BE is never
    // reached, so without its own line the event would be invisible. The two
    // paths are mutually exclusive, so `total` still counts each refused load
    // exactly once.
    if (!IsValid(guestAddr, sizeof(float)))
    {
        LogGuestLoadRefused("ReadF32BE", guestAddr, sizeof(float), "range", kRefF32, 0, 0);
        return false;
    }
    if (!outVal)
    {
        LogGuestLoadRefused("ReadF32BE", guestAddr, sizeof(float), "nullout", kRefF32, 0, 0);
        return false;
    }
    uint32_t beVal;
    if (!ReadU32BE(guestAddr, &beVal))
        return false;  // already reported by ReadU32BE with why=av
    *outVal = *reinterpret_cast<const float*>(&beVal);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const
{
    if (!IsValid(guestAddr, size))
    {
        LogGuestLoadRefused("ReadBytes", guestAddr, size, "range", kRefBytes, 0, 0);
        return false;
    }
    if (!outBuffer)
    {
        LogGuestLoadRefused("ReadBytes", guestAddr, size, "nullout", kRefBytes, 0, 0);
        return false;
    }
    const uint8_t* src = static_cast<const uint8_t*>(Translate(guestAddr));
    bool ok = false;
    GuestLoadFault fault;
    __try
    {
        memcpy(outBuffer, src, size);
        ok = true;
    }
    __except (GuestLoadAvFilter(GetExceptionInformation(), &fault), EXCEPTION_EXECUTE_HANDLER)
    {
    }
    if (!ok)
    {
        LogGuestLoadRefused("ReadBytes", guestAddr, size, "av", kRefBytes,
                            fault.code, fault.addr);
    }
    return ok;
}

bool mcla::kernel::GuestMemoryHeap::WriteU8(uint32_t guestAddr, uint8_t val)
{
    if (!IsValid(guestAddr, sizeof(uint8_t))) return false;
    __try
    {
        *reinterpret_cast<uint8_t*>(Translate(guestAddr)) = val;
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

bool mcla::kernel::GuestMemoryHeap::WriteU16BE(uint32_t guestAddr, uint16_t val)
{
    if (!IsValid(guestAddr, sizeof(uint16_t))) return false;
    __try
    {
        *reinterpret_cast<uint16_t*>(Translate(guestAddr)) = Swap16(val);
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

bool mcla::kernel::GuestMemoryHeap::WriteU32BE(uint32_t guestAddr, uint32_t val)
{
    if (!IsValid(guestAddr, sizeof(uint32_t))) return false;
    __try
    {
        *reinterpret_cast<uint32_t*>(Translate(guestAddr)) = Swap32(val);
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

bool mcla::kernel::GuestMemoryHeap::WriteU64BE(uint32_t guestAddr, uint64_t val)
{
    if (!IsValid(guestAddr, sizeof(uint64_t))) return false;
    __try
    {
        *reinterpret_cast<uint64_t*>(Translate(guestAddr)) = Swap64(val);
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

bool mcla::kernel::GuestMemoryHeap::WriteBytes(uint32_t guestAddr, const void* src, uint32_t size)
{
    if (!IsValid(guestAddr, size) || !src) return false;
    __try
    {
        memcpy(Translate(guestAddr), src, size);
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

mcla::kernel::GuestMemoryHeap::~GuestMemoryHeap()
{
    Shutdown();
}

bool mcla::kernel::GuestMemoryHeap::Initialize()
{
    if (m_initialized)
        return true;

#ifdef _WIN32
    // First check if memory is already reserved/committed at the target address
    MEMORY_BASIC_INFORMATION mbi;
    if (VirtualQuery((void*)kBaseAddress, &mbi, sizeof(mbi)) == sizeof(mbi) && 
        (mbi.State == MEM_RESERVE || mbi.State == MEM_COMMIT))
    {
        m_base = (uint8_t*)kBaseAddress;
    }
    else
    {
        m_base = (uint8_t*)VirtualAlloc((void*)kBaseAddress, kSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        if (m_base == nullptr)
            m_base = (uint8_t*)VirtualAlloc(nullptr, kSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    }

    if (m_base == nullptr)
        return false;

    DWORD oldProtect;
    VirtualProtect(m_base, 4096, PAGE_NOACCESS, &oldProtect);
#else
    // On Linux, check if memory is already mapped at the target address
    m_base = (uint8_t*)mmap((void*)kBaseAddress, kSize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE | MAP_FIXED_NOREPLACE, -1, 0);

    if (m_base == (uint8_t*)MAP_FAILED)
        m_base = (uint8_t*)mmap((void*)kBaseAddress, kSize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (m_base == (uint8_t*)MAP_FAILED)
        m_base = (uint8_t*)mmap(NULL, kSize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (m_base == nullptr)
        return false;

    mprotect(m_base, 4096, PROT_NONE);
#endif

    m_size = kSize;
    m_initialized = true;
    m_owned = true;
    return true;
}

bool mcla::kernel::GuestMemoryHeap::Adopt(uint8_t* base, uint64_t size)
{
    if (m_initialized)
        return true;

    if (!base || size < 4096)
        return false;

#ifdef _WIN32
    DWORD oldProtect;
    if (!VirtualProtect(base, 4096, PAGE_NOACCESS, &oldProtect))
        return false;
#else
    if (mprotect(base, 4096, PROT_NONE) != 0)
        return false;
#endif

    m_base = base;
    m_size = size;
    m_initialized = true;
    m_owned = false;
    return true;
}

void mcla::kernel::GuestMemoryHeap::Shutdown()
{
    if (!m_initialized)
        return;

    if (m_owned && m_base)
    {
#ifdef _WIN32
        VirtualFree(m_base, 0, MEM_RELEASE);
#else
        munmap(m_base, m_size);
#endif
    }

    m_base = nullptr;
    m_size = 0;
    m_initialized = false;
    m_owned = false;
}

void* mcla::kernel::GuestMemoryHeap::Translate(uint32_t guestAddr)
{
    if (!m_initialized || guestAddr >= m_size)
        return nullptr;
    return m_base + guestAddr;
}

const void* mcla::kernel::GuestMemoryHeap::Translate(uint32_t guestAddr) const
{
    if (!m_initialized || guestAddr >= m_size)
        return nullptr;
    return m_base + guestAddr;
}

uint32_t mcla::kernel::GuestMemoryHeap::MapVirtual(const void* hostPtr) const
{
    if (!m_initialized || !hostPtr)
        return 0;

    const uint8_t* base = static_cast<const uint8_t*>(hostPtr);
    if (base < m_base || base >= m_base + m_size)
        return 0;

    return static_cast<uint32_t>(base - m_base);
}

bool mcla::kernel::GuestMemoryHeap::IsValid(uint32_t guestAddr, size_t size) const
{
    if (!m_initialized || guestAddr == 0 || size == 0)
        return false;

    // The first 4 KB of the heap is a deliberate PAGE_NOACCESS null guard (set at
    // :218/:251), and the rest of the 4 GB is committed read/write. Without this
    // clause a "checked" helper passes IsValid for a near-null guest pointer and
    // then faults inside memcpy - which is what F-122 measured: 50 AVs in
    // MemoryStreamServeRead's ReadBytes at wrapped src 0x00000C61 (#6: 0x0).
    if (guestAddr < 4096u)
        return false;

    if (guestAddr >= m_size)
        return false;

    uint64_t end = static_cast<uint64_t>(guestAddr) + size;
    if (end > m_size)
        return false;

    return true;
}

uint32_t mcla::kernel::GuestMemoryHeap::Alloc(size_t size, size_t alignment)
{
    if (!m_initialized)
        return 0;

    void* ptr = g_userHeap.AllocPhysical(size, alignment);
    if (!ptr)
        return 0;

    return MapVirtual(ptr);
}

void mcla::kernel::GuestMemoryHeap::Free(uint32_t guestAddr, size_t size)
{
    if (!m_initialized || guestAddr == 0)
        return;

    void* ptr = Translate(guestAddr);
    if (!ptr)
        return;

    g_userHeap.Free(ptr);
}

mcla::kernel::GuestMemoryHeap& mcla::kernel::GuestMemoryHeap::Instance()
{
    static GuestMemoryHeap instance;
    return instance;
}

// --- Guest-virtual region tracking -------------------------------------------
// Coarse, allocation-granular bookkeeping (not page-granular): enough to make
// NtAllocateVirtualMemory/NtFreeVirtualMemory/NtQueryVirtualMemory honest
// without inventing a second allocator model. The flat window remains
// identity-mapped; only STATE is tracked.

namespace {
constexpr uint32_t kVirtPage = mcla::kernel::GuestMemoryHeap::kGuestVirtualPageSize;

uint32_t RoundUpPage(uint32_t v) { return (v + kVirtPage - 1) & ~(kVirtPage - 1); }
} // namespace

bool mcla::kernel::GuestMemoryHeap::QueryVirtualRegion(uint32_t addr, VirtualRegionInfo* out) const
{
    if (!out)
        return false;
    std::lock_guard<std::mutex> lock(m_virtualMutex);
    for (const auto& r : m_virtualRegions)
    {
        if (addr >= r.base && addr < r.base + r.size)
        {
            out->base = r.base;
            out->allocationBase = r.base;
            out->size = r.size;
            out->committed = r.committed;
            out->reserved = true;
            return true;
        }
    }
    // Untracked: report FREE within the window (page-granular slice).
    if (addr < kGuestVirtualBase || addr >= kGuestVirtualEnd)
        return false;
    uint32_t nextBound = kGuestVirtualEnd;
    for (const auto& r : m_virtualRegions)
    {
        if (r.base > addr)
        {
            nextBound = r.base;
            break;
        }
    }
    out->base = addr & ~(kVirtPage - 1);
    out->allocationBase = 0;
    out->size = RoundUpPage(nextBound - out->base);
    out->committed = false;
    out->reserved = false;
    return true;
}

bool mcla::kernel::GuestMemoryHeap::AllocVirtualFixed(uint32_t base, uint32_t size, bool commit, bool zeroFresh, bool* outWasCommitted)
{
    *outWasCommitted = false;
    if (!m_initialized || size == 0)
        return false;
    if (base < kGuestVirtualBase || size > kGuestVirtualEnd - base)
        return false;

    std::lock_guard<std::mutex> lock(m_virtualMutex);
    const uint32_t end = base + size;

    // 1) Exact-match re-commit / upgrade / reserve-no-op.
    for (auto& r : m_virtualRegions)
    {
        if (r.base == base && r.size == size)
        {
            if (commit && !r.committed)
            {
                r.committed = true;
                if (zeroFresh)
                    memset(Base() + base, 0, size);
            }
            else if (commit && r.committed)
            {
                *outWasCommitted = true;
            }
            return true;
        }
    }

    // 2) Contained within ONE existing region: legal reserve->commit /
    //    sub-commit (Xenia allows page-granular commit inside reservations;
    //    our bookkeeping is region-granular, so we upgrade the whole region
    //    but zero only the freshly-committed sub-range).
    const VirtualRegion* containing = nullptr;
    for (const auto& r : m_virtualRegions)
    {
        if (base >= r.base && end <= r.base + r.size)
        {
            containing = &r;
            break;
        }
    }
    if (containing)
    {
        // Re-scan for the same element to get a non-const ref (search used const&).
        for (auto& r : m_virtualRegions)
        {
            if (&r == containing)
            {
                if (commit && !r.committed)
                {
                    r.committed = true;
                    if (zeroFresh)
                        memset(Base() + base, 0, size);
                }
                else if (commit && r.committed)
                {
                    *outWasCommitted = true;
                }
                return true;
            }
        }
    }

    // 3) Otherwise the whole range must be free of any region.
    for (const auto& r : m_virtualRegions)
    {
        if (r.base < end && base < r.base + r.size)
            return false; // partial overlap = real conflict
    }

    if (commit && zeroFresh)
        memset(Base() + base, 0, size);
    m_virtualRegions.insert(
        std::lower_bound(m_virtualRegions.begin(), m_virtualRegions.end(), base,
                         [](const VirtualRegion& r, uint32_t b) { return r.base < b; }),
        VirtualRegion{base, size, commit});
    return true;
}

bool mcla::kernel::GuestMemoryHeap::AllocVirtualAny(uint32_t size, bool topDown, bool commit, bool zeroFresh, uint32_t* outBase)
{
    if (!m_initialized || size == 0 || size > kGuestVirtualEnd - kGuestVirtualBase)
        return false;

    std::lock_guard<std::mutex> lock(m_virtualMutex);

    auto gapFits = [size](uint32_t lo, uint32_t hi) { return hi >= lo && hi - lo >= size; };

    if (!topDown)
    {
        // Walk regions in order; first gap before/between/after them wins.
        uint32_t cursor = kGuestVirtualBase;
        for (const auto& r : m_virtualRegions)
        {
            if (gapFits(cursor, r.base))
            {
                if (commit && zeroFresh)
                    memset(Base() + cursor, 0, size);
                m_virtualRegions.insert(
                    std::lower_bound(m_virtualRegions.begin(), m_virtualRegions.end(), cursor,
                                     [](const VirtualRegion& rr, uint32_t b) { return rr.base < b; }),
                    VirtualRegion{cursor, size, commit});
                *outBase = cursor;
                return true;
            }
            cursor = std::max(cursor, r.base + r.size);
        }
        if (gapFits(cursor, kGuestVirtualEnd))
        {
            if (commit && zeroFresh)
                memset(Base() + cursor, 0, size);
            m_virtualRegions.emplace_back(VirtualRegion{cursor, size, commit}); // append at end
            *outBase = cursor;
            return true;
        }
        return false;
    }

    // Top-down: last gap near the window end.
    uint32_t hi = kGuestVirtualEnd;
    for (auto it = m_virtualRegions.rbegin(); it != m_virtualRegions.rend(); ++it)
    {
        if (gapFits(it->base + it->size, hi))
        {
            uint32_t base = hi - size;
            if (commit && zeroFresh)
                memset(Base() + base, 0, size);
            m_virtualRegions.insert(
                std::lower_bound(m_virtualRegions.begin(), m_virtualRegions.end(), base,
                                 [](const VirtualRegion& r, uint32_t b) { return r.base < b; }),
                VirtualRegion{base, size, commit});
            *outBase = base;
            return true;
        }
        hi = std::min(hi, it->base);
    }
    if (gapFits(kGuestVirtualBase, hi))
    {
        uint32_t base = hi - size;
        if (commit && zeroFresh)
            memset(Base() + base, 0, size);
        m_virtualRegions.insert(m_virtualRegions.begin(), VirtualRegion{base, size, commit});
        *outBase = base;
        return true;
    }
    return false;
}

bool mcla::kernel::GuestMemoryHeap::DecommitVirtual(uint32_t base, uint32_t size, uint32_t* outSize)
{
    std::lock_guard<std::mutex> lock(m_virtualMutex);
    for (auto& r : m_virtualRegions)
    {
        if (base >= r.base && base < r.base + r.size)
        {
            r.committed = false;
            *outSize = r.size;
            return true;
        }
    }
    return false;
}

bool mcla::kernel::GuestMemoryHeap::ReleaseVirtual(uint32_t base, uint32_t* outSize)
{
    std::lock_guard<std::mutex> lock(m_virtualMutex);
    for (auto it = m_virtualRegions.begin(); it != m_virtualRegions.end(); ++it)
    {
        if (it->base == base)
        {
            *outSize = it->size;
            m_virtualRegions.erase(it);
            return true;
        }
    }
    return false;
}

mcla::kernel::Memory mcla::kernel::g_memory;
Heap g_userHeap;
