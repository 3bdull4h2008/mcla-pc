#include <stdafx.h>
#include "heap.h"
#include "memory.h"
#include "function.h"
#include "logging.h"
#include <boot_host.h>  // F-374: header guard arm/disarm around each operation
#include <atomic>
#include <unordered_set>
#include <windows.h>
#include <intrin.h>  // F-370: _ReturnAddress() for the heap caller census
#include <cstdio>    // F-373: snprintf for the raw header dump
#include <dbghelp.h>

// F-412: dead -- zero code references in src/; the same value lives on as kUserHeapArenaEnd
// (heap_arena.h:24). Kept only because heap_arena.h:25 still names it in prose.
constexpr size_t RESERVED_BEGIN = 0x7FEA0000;

// Session 76j: exact-allocation registry for the physical arena. The guest
// frees sub-blocks carved from ITS OWN pools via RtlFreeHeap/XFreeMem; a raw
// o1heapFree on such a pointer releases a region that still contains live
// data (observed: the device-registry holder shared bytes with a live guest
// slab element → the texture ctor scribbled FF00FF00 over it → GetDevice
// called a poisoned Device* → AV at the first uncommitted page). Only
// pointers this allocator actually returned may be freed.
static std::unordered_set<void *> &LivePhysAllocs()
{
    static std::unordered_set<void *> set;
    return set;
}

// SEH-safe o1heap allocate: must be a C-style function with no C++ objects
// that require unwinding — clang-cl crashes compiling __try in a C++ method
// that holds std::lock_guard.
#if defined(_MSC_VER)
    // Session 73: capture the faulting address so the corrupted o1heap
    // fragment can be identified. The filter runs while the exception
    // context is live; keep it C-style (no unwinding objects).
    static long SehO1Filter(EXCEPTION_POINTERS *info)
    {
        if (info && info->ExceptionRecord &&
            info->ExceptionRecord->ExceptionCode == 0xC0000005 &&
            info->ExceptionRecord->NumberParameters >= 2)
        {
            const void *faultAddr =
                (const void *)info->ExceptionRecord->ExceptionInformation[1];
            MCLA_LOG_ERROR("o1heap AV fault-addr={:p} (op={} )", faultAddr,
                           (unsigned long long)
                               info->ExceptionRecord->ExceptionInformation[0]);
            const uint8_t *gbase =
                static_cast<const uint8_t *>(
                    mcla::kernel::g_memory.Translate(0));
            const uintptr_t fault = (uintptr_t)faultAddr;
            const uintptr_t lo = (uintptr_t)gbase;
            // Unsigned offset test — `fault + 64 < lo + 4GB` wraps and passes
            // for wild pointers like 0xFFFFFFFFFFFFFFFF, and the dump below
            // then faulted *inside* this filter (2 cascading AVs per real one).
            const uintptr_t off = fault - lo;
            if (gbase != nullptr && fault >= lo && off < 0x100000000ull)
            {
                MCLA_LOG_ERROR("o1heap AV guest-addr={:08X}",
                               static_cast<uint32_t>(off));
                if (off >= 32 && off + 40 <= 0x100000000ull)
                {
                    const uint64_t *p = (const uint64_t *)(fault & ~7ull);
                    MCLA_LOG_ERROR("  [fa-32]={:016X}:{:016X} [fa-16]={:016X}:{:016X}",
                                   p[-4], p[-3], p[-2], p[-1]);
                    MCLA_LOG_ERROR("  [fa+00]={:016X} [fa+08]={:016X}", p[0], p[1]);
                    MCLA_LOG_ERROR("  [fa+16]={:016X} [fa+24]={:016X}", p[2], p[3]);
                }
            }
        }
        return EXCEPTION_EXECUTE_HANDLER;
    }

    void* SehO1Allocate(O1HeapInstance* heap, size_t amount)
    {
        void* ptr = nullptr;
        __try
        {
            ptr = o1heapAllocate(heap, amount);
        }
        __except (SehO1Filter(GetExceptionInformation()))
        {
            ptr = nullptr;
        }
        return ptr;
    }
    void SehO1Free(O1HeapInstance* heap, void* ptr)
    {
        __try
        {
            o1heapFree(heap, ptr);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            static std::atomic<uint32_t> s_freeSeh{0};
            const uint32_t n = s_freeSeh.fetch_add(1) + 1;
            if (n <= 8 || (n % 100) == 0)
                MCLA_LOG_ERROR("o1heapFree SEH catch #{} ptr={:p}", n, ptr);
        }
    }
#define MCLA_O1_ALLOC(heap, amount) SehO1Allocate((heap), (amount))
#define MCLA_O1_FREE(heap, ptr) SehO1Free((heap), (ptr))
#else
#define MCLA_O1_ALLOC(heap, amount) o1heapAllocate((heap), (amount))
#define MCLA_O1_FREE(heap, ptr) o1heapFree((heap), (ptr))
#endif

// Mirrors o1heap.c FragmentHeader layout (private there): next@0, prev@8,
// size@16, used@24. O1HEAP_ALIGNMENT=32, FRAGMENT_SIZE_MIN=64.
namespace
{
    struct FragHeaderProbe
    {
        void* next;
        void* prev;
        size_t size;
        bool used;
    };
    constexpr size_t kO1HeapAlignment = sizeof(void*) * 4; // 32
    constexpr size_t kFragmentSizeMin = kO1HeapAlignment * 2; // 64
}

// F-370: the guest user heap keeps its own o1heap header at guest VA 0x20000 (Heap::Init binds the
// arena there). In w373 and w374 those words turn to garbage between two consecutive Heap calls,
// after which Heap::Alloc refuses everything (`Alloc: o1heap invariants FAIL`), the 16th guest
// thread is never created (src/kernel/guest_thread.cpp:21 takes the null and used to AV in memset),
// and the boot worker parks forever on counting semaphore C501FC00. `capacity` is constant, so an
// O(1) compare against the value captured at Init brackets the corruption to one heap operation
// without walking the allocator's tree.
namespace
{
    size_t g_hdrGoldenCap = 0;
    uint8_t *g_hdrArena = nullptr;

    inline O1HeapDiagnostics HeapDiag(O1HeapInstance *h)
    {
        O1HeapDiagnostics d{};
        if (h != nullptr)
            d = o1heapGetDiagnostics(h);
        return d;
    }

    inline uintptr_t CallerRva(void *ra)
    {
        const uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
        return base ? reinterpret_cast<uintptr_t>(ra) - base : 0;
    }

    void CheckHeapHeader(const char *phase, size_t reqSize, O1HeapInstance *h, void *callerRa)
    {
        if (h == nullptr || g_hdrGoldenCap == 0)
            return;
        // O1HeapInstance is opaque in the public header, so the fields come through the
        // diagnostics copy - which reads the same memory the corrupter scribbled on.
        const O1HeapDiagnostics d = HeapDiag(h);
        if (d.capacity == g_hdrGoldenCap && d.allocated <= g_hdrGoldenCap &&
            d.peak_allocated <= g_hdrGoldenCap)
            return;
        static std::atomic<uint32_t> s_hdrBad{0};
        const uint32_t n = s_hdrBad.fetch_add(1) + 1;
        if (n <= 8 || (n % 500) == 0)
        {
            uint32_t glr = 0;
            if (const PPCContext *c = GetPPCContext())
                glr = static_cast<uint32_t>(c->lr);
            MCLA_LOG_ERROR("F370-HEAP-HDR #{} phase={} subj={:#x} cap={:#x} want_cap={:#x} "
                           "used={:#x} peak={:#x} oom={} hdr_off={:#x} glr={:08X} caller_rva={:#x}",
                           n, phase, reqSize, d.capacity, g_hdrGoldenCap, d.allocated,
                           d.peak_allocated, static_cast<unsigned long long>(d.oom_count),
                           g_hdrArena ? static_cast<unsigned>(reinterpret_cast<uint8_t *>(h) -
                                                                   g_hdrArena)
                                      : 0u,
                           glr, CallerRva(callerRa));
            // F-373: "the header is garbage" has two very different causes, and the fix is
            // opposite: (i) somebody wrote over guest 0x20000, or (ii) the host pointer we
            // captured at Init is stale because the mapping behind 0x20000 moved, so we are
            // reading a page that is no longer the heap. Re-Translate and read the same 40
            // bytes through the checked path: if the mapping moved, `retrans` says so directly.
            // The physical-arena compare is a free needle test -- if the two headers match, the
            // "corruption" is a copy of the other heap and the writer names itself.
            auto &gm = mcla::kernel::GuestMemoryHeap::Instance();
            void *re = gm.Translate(mcla::kernel::kUserHeapArenaVa);
            uint8_t raw[40] = {};
            const bool got = gm.ReadBytes(mcla::kernel::kUserHeapArenaVa, raw, static_cast<uint32_t>(sizeof(raw)));
            uint8_t phys[40] = {};
            const bool gotPhys =
                gm.ReadBytes(mcla::kernel::kPhysArenaBeginVa, phys, static_cast<uint32_t>(sizeof(phys)));
            char hex[sizeof(raw) * 2 + 1] = {};
            char asc[sizeof(raw) + 1] = {};
            for (size_t k = 0; k < sizeof(raw); ++k)
            {
                std::snprintf(&hex[k * 2], 3, "%02x", raw[k]);
                asc[k] = (raw[k] >= 32 && raw[k] < 127) ? static_cast<char>(raw[k]) : '.';
            }
            asc[sizeof(raw)] = 0;
            MCLA_LOG_ERROR("F373-HEAP-RAW #{} phase={} base={:p} retrans={:p} moved={} "
                           "read_ok={} phys_read_ok={} phys_same={} hex={} ascii='{}'",
                           n, phase, (void *)g_hdrArena, re, re != (void *)g_hdrArena, got,
                           gotPhys, got && gotPhys && std::memcmp(raw, phys, sizeof(raw)) == 0,
                           hex, asc);
        }
    }
} // namespace

void Heap::Init()
{
    // F-384: this line used to hardcode 0x20000 (XenonRecomp's baseline); the address is unchanged but
    // it now comes from `kUserHeapArenaVa`, and so do the four probes that watch this page. The
    // relocation to 0x20000000 was tried and measured in `w395` and REVERTED: the writer followed the
    // base (`guest=20000000 val=20000004` from the same `sub_82397060` chain), so the title is being
    // HANDED our arena base -- that hand-off is T41.67, not a relocation.
    heapArenaBase = (uint8_t*)mcla::kernel::g_memory.Translate(mcla::kernel::kUserHeapArenaVa);
    heapArenaSize = mcla::kernel::kUserHeapArenaEnd - mcla::kernel::kUserHeapArenaVa;
    heap = o1heapInit(heapArenaBase, heapArenaSize);
    g_hdrArena = heapArenaBase;
    if (heap != nullptr)
        g_hdrGoldenCap = o1heapGetDiagnostics(heap).capacity;  // F-370: constant from here on

    physArenaBase = (uint8_t*)mcla::kernel::g_memory.Translate(mcla::kernel::kPhysArenaBeginVa);
    physArenaSize = 0x100000000 - mcla::kernel::kPhysArenaBeginVa;
    physicalHeap = o1heapInit(physArenaBase, physArenaSize);
}

void Heap::AttachPhysicalArena(void* base, size_t size)
{
    physArenaBase = (uint8_t*)base;
    physArenaSize = size;
    physicalHeap = o1heapInit(base, size);
}

namespace
{
    const char* ProbeReasonName(Heap::LiveProbe::Reason reason)
    {
        switch (reason)
        {
            case Heap::LiveProbe::Reason::Ok: return "ok";
            case Heap::LiveProbe::Reason::Null: return "null";
            case Heap::LiveProbe::Reason::OutOfArena: return "out-of-arena";
            case Heap::LiveProbe::Reason::Misaligned: return "misaligned";
            case Heap::LiveProbe::Reason::BadSize: return "bad-size";
            case Heap::LiveProbe::Reason::NotUsed: return "not-used";
            case Heap::LiveProbe::Reason::BadPointers: return "bad-pointers";
        }
        return "unknown";
    }
}

bool Heap::IsLiveAllocation(uint8_t* arenaBase, size_t arenaSize, void* ptr, LiveProbe* out) const
{
    LiveProbe local;
    LiveProbe& probe = out != nullptr ? *out : local;
    probe = {};

    if (arenaBase == nullptr || ptr == nullptr)
    {
        probe.reason = LiveProbe::Reason::Null;
        return false;
    }

    const uintptr_t base = (uintptr_t)arenaBase;
    const uintptr_t p = (uintptr_t)ptr;

    // Must be inside the arena (with room for a header below it) and 32-byte
    // aligned (o1heap returns aligned ptrs).
    if (p < base + kO1HeapAlignment || p >= base + arenaSize)
    {
        probe.reason = LiveProbe::Reason::OutOfArena;
        return false;
    }
    if ((p % kO1HeapAlignment) != 0)
    {
        probe.reason = LiveProbe::Reason::Misaligned;
        return false;
    }

    // Probe the fragment header just below the user pointer.
    const FragHeaderProbe* hdr = (const FragHeaderProbe*)(p - kO1HeapAlignment);
    probe.next = hdr->next;
    probe.prev = hdr->prev;
    probe.size = hdr->size;
    probe.used = hdr->used;

    // Size must be a power-of-two multiple of FRAGMENT_SIZE_MIN within arena.
    if (probe.size < kFragmentSizeMin || (probe.size % kFragmentSizeMin) != 0 || probe.size > arenaSize)
    {
        probe.reason = LiveProbe::Reason::BadSize;
        return false;
    }

    // Live allocations have used=true; free fragments are in bins.
    if (!probe.used)
    {
        probe.reason = LiveProbe::Reason::NotUsed;
        return false;
    }

    // Header pointers must either be NULL or inside the same arena.
    const auto inArena = [base, arenaSize](void* q) {
        return (uintptr_t)q >= base && (uintptr_t)q < base + arenaSize;
    };
    if ((hdr->prev != nullptr && !inArena(hdr->prev)) || (hdr->next != nullptr && !inArena(hdr->next)))
    {
        probe.reason = LiveProbe::Reason::BadPointers;
        return false;
    }

    probe.reason = LiveProbe::Reason::Ok;
    return true;
}

namespace
{
    // F-374 / F-412: RAII window for the header guard. F-412 replaced the old bool arms with ONE
    // nesting depth over BOTH guard pages (g_hgDepth under g_hgMtx, boot_host.cpp:297-310): a
    // page goes back to NOACCESS only when the LAST open window across ALL threads closes
    // (only HeapGuardArmImpl at depth 0 re-arms; the VEH handler itself never re-arms). The
    // old rule -- "declare this immediately after the function's std::lock_guard so it
    // destructs before the mutex is released" -- was an attempt at the same guarantee:
    // Heap::Alloc follows it, Heap::Free does NOT -- it opens its window before any lock,
    // because CheckHeapHeader("pre-free") reads the guarded instance page and must run
    // disarmed. That is harmless now (depth, not ordering) and must stay so: every instance
    // read belongs in a window -- moving this below the lock trips F374-HEAPGUARD per free.
    struct HeapGuardWindow
    {
        HeapGuardWindow() { mcla::boot::HeapGuardDisarm(); }
        ~HeapGuardWindow() { mcla::boot::HeapGuardArm(); }
    };
} // namespace

void* Heap::Alloc(size_t size)
{
    std::lock_guard lock(mutex);
    HeapGuardWindow hg;

    if (heap == nullptr)
        return nullptr;

    // F-370: is the header already broken before this call? Paired with the post-alloc check
    // below, a bad "pre" with a good "post" on the previous call means the corrupter was NOT a
    // heap operation at all (an external writer into guest 0x20000..).
    CheckHeapHeader("pre-alloc", size, heap, _ReturnAddress());

    // F-370 census: who takes a >=256 KiB slice of the guest's own user heap. The host Path A
    // fill and the guest's thread contexts (0x40e90 each) share this arena.
    if (size >= 0x40000)
    {
        static std::atomic<uint32_t> s_big{0};
        const uint32_t n = s_big.fetch_add(1) + 1;
        if (n <= 40 || (n % 200) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(heap);
            MCLA_LOG_WARN("F370-HEAP-BIG #{} size={:#x} used={:#x} peak={:#x} cap={:#x} oom={} "
                          "caller_rva={:#x}",
                          n, size, d.allocated, d.peak_allocated, d.capacity,
                          static_cast<unsigned long long>(d.oom_count),
                          CallerRva(_ReturnAddress()));
            if (n == 1)
            {
                // F-100 rule: a probe that only ever fires on failure cannot tell "the header
                // broke" from "my reader is broken". Dump the same 40 bytes while the header is
                // provably healthy (this is the first of 15 successful thread-context allocs), so
                // the later F373-HEAP-RAW line has a golden reference and a working reader.
                auto &gm = mcla::kernel::GuestMemoryHeap::Instance();
                uint8_t raw[40] = {};
                const bool got =
                    gm.ReadBytes(mcla::kernel::kUserHeapArenaVa, raw, static_cast<uint32_t>(sizeof(raw)));
                char hex[sizeof(raw) * 2 + 1] = {};
                for (size_t k = 0; k < sizeof(raw); ++k)
                    std::snprintf(&hex[k * 2], 3, "%02x", raw[k]);
                MCLA_LOG_WARN("F373-HEAP-GOLDEN #{} base={:p} read_ok={} cap={:#x} hex={}", n,
                              (void *)g_hdrArena, got, d.capacity, hex);
            }
        }
    }

    if (!o1heapDoInvariantsHold(heap))
    {
        static std::atomic<uint32_t> s_badMain{0};
        const uint32_t n = s_badMain.fetch_add(1) + 1;
        if (n <= 8 || (n % 200) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(heap);
            MCLA_LOG_ERROR("Alloc: o1heap invariants FAIL #{} size={:#x} cap={:#x} used={:#x} "
                           "peak={:#x} oom={} caller_rva={:#x}",
                           n, size, d.capacity, d.allocated, d.peak_allocated,
                           static_cast<unsigned long long>(d.oom_count),
                           CallerRva(_ReturnAddress()));
        }
        return nullptr;
    }
    void* ptr = MCLA_O1_ALLOC(heap, std::max<size_t>(1, size));
    if (ptr == nullptr)
    {
        static std::atomic<uint32_t> s_nullMain{0};
        const uint32_t n = s_nullMain.fetch_add(1) + 1;
        if (n <= 8 || (n % 100) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(heap);
            MCLA_LOG_ERROR("Alloc: o1heapAllocate returned null #{} size={:#x} cap={:#x} "
                           "used={:#x} peak={:#x} oom={} caller_rva={:#x}",
                           n, size, d.capacity, d.allocated, d.peak_allocated,
                           static_cast<unsigned long long>(d.oom_count),
                           CallerRva(_ReturnAddress()));
        }
    }
    CheckHeapHeader("post-alloc", size, heap, _ReturnAddress());
    return ptr;
}

void* Heap::AllocPhysical(size_t size, size_t alignment)
{
    size = std::max<size_t>(1, size);
    alignment = alignment == 0 ? 0x1000 : std::max<size_t>(16, alignment);
    // Session 72: guest can pass non-pow2 (observed 0x404). The
    // `& ~(alignment-1)` mask is only valid for pow2 — a non-pow2 alignment
    // produced a misaligned user pointer and the bookkeeping words written
    // below it corrupted o1heap fragment headers (AV in o1heapAllocate).
    {
        size_t p2 = 16;
        while (p2 < alignment)
            p2 <<= 1;
        alignment = p2;
    }

    std::lock_guard lock(physicalMutex);
    HeapGuardWindow hg;  // F-388: both header guards off while an allocator is in flight

    if (physicalHeap == nullptr)
        return nullptr;

    // F-386 census (READ-ONLY, no behaviour change): the invariants check below PASSES in every boot
    // that still AVs inside `o1heapAllocate` -- w394/w395/w396/w397 each log exactly one
    // `code=0xC0000005 rva=0x206C_8 = o1heapAllocate+0x98`, Param[0]=1 (a WRITE) to 0xE49125FC with
    // rcx=0xE49125D4. That address is a GUEST VA in the physical band being used as a host pointer,
    // and +0x28 is the `prev_free` field of `struct Fragment` (src/kernel/o1heap.c:123-131), so the
    // walk was following a poisoned free-list link that `o1heapDoInvariantsHold` never dereferences.
    // Validate what the allocator is actually about to chase: the 64 bin heads (the first 512 bytes of
    // the instance -- `O1HeapInstance{bins[], mask, diagnostics}`, o1heap.c:133-138, F-375's
    // correction) and then the links themselves. A bad value is reported with the physical-allocation
    // registry's own answer for "is this number a buffer we handed the guest, and who asked for it".
    if (physArenaBase != nullptr)
    {
        static std::atomic<uint32_t> s_binBad{0};
        static std::atomic<uint32_t> s_physCalls{0};
        const uint32_t call = s_physCalls.fetch_add(1) + 1;
        const uintptr_t lo = (uintptr_t)physArenaBase;
        const uintptr_t hi = lo + physArenaSize;
        uint32_t bad = 0;
        int badSlot = -1;
        uintptr_t badVal = 0;
        uintptr_t bins[64] = {};
        std::memcpy(bins, (const void *)physArenaBase, sizeof(bins));
        for (int i = 0; i < 64; ++i)
        {
            const uintptr_t v = bins[i];
            if (v != 0 && (v < lo || v >= hi))
            {
                ++bad;
                if (badSlot < 0)
                {
                    badSlot = i;
                    badVal = v;
                }
            }
        }
        // The links are where the poison actually lives if the bin heads look sane: follow each
        // non-empty bin for a bounded number of hops and check every pointer.
        // F-387: the first version walked only the first 64 calls, and `w388`-style timing means the
        // AV happens ~10^4 calls later, so it was blind exactly when it mattered (F386 printed 0 rows
        // in w398 while the AV still fired). Now a round-robin SAMPLER: 8 nodes per call, advancing
        // globally, so a poison that persists in a list is found within a handful of calls while the
        // per-call cost stays negligible. The value it is looking for has an exact signature in the
        // fault dump: node = 0xE49125D4 with rdi = r8 = 0x1A0000000 (the arena's host base), i.e. a
        // host pointer to physical memory (Translate(0xE49125D4) = 0x1E49125D4) that lost its high
        // dword -- a 32-bit GUEST pointer written into a 64-bit host link field.
        int linkHop = -1;
        uintptr_t linkVal = 0;
        if (bad == 0)
        {
            static std::atomic<uint32_t> s_walkCursor{0};
            uint32_t cur = s_walkCursor.fetch_add(8) % 64;
            for (int k = 0; k < 8 && linkHop < 0; ++k)
            {
                const int b = (int)((cur + (uint32_t)k) % 64u);
                uintptr_t p = bins[b];
                for (int hop = 0; p != 0 && hop < 8; ++hop)
                {
                    if (p < lo || p >= hi)
                    {
                        linkVal = p;
                        linkHop = hop;
                        bad = 1;
                        badSlot = b;
                        break;
                    }
                    uintptr_t nxt = 0;
                    // Fragment = { header{next@0,prev@8,size@16,used@24}, next_free@32, prev_free@40 }
                    // (src/kernel/o1heap.c:115-131; O1HEAP_ALIGNMENT is 32, so the header is 32 bytes).
                    // The AV writes node+0x28 = prev_free, i.e. an unlink through a poisoned link.
                    std::memcpy(&nxt, (const void *)(p + 32), sizeof(nxt));  // Fragment::next_free
                    p = nxt;
                }
            }
        }
        if (bad != 0)
        {
            const uint32_t n = s_binBad.fetch_add(1) + 1;
            if (n <= 4)
            {
                const uintptr_t gv = bad ? (badVal ? badVal : linkVal) : 0;
                const uint32_t bogus = (uint32_t)(gv & 0xFFFFFFFFu);
                uint32_t ab = 0, asz = 0, alr = 0;
                bool exact = false;
                const bool known =
                    mcla::kernel::MclaPhysAllocInfo(bogus, &ab, &asz, &alr, &exact);
                uint32_t nb = 0, nsz = 0;
                const bool below =
                    mcla::kernel::MclaPhysNearestAllocBelow(bogus, &nb, &nsz);
                uint32_t glr = 0;
                if (const PPCContext *c = GetPPCContext())
                    glr = (uint32_t)c->lr;
                MCLA_LOG_ERROR("F386-PHYSFREE #{} call={} kind={} bin={} hop={} value={:X} "
                               "high4zero={} plusWindowInArena={} asGuestVa={:08X} allocInfo={} "
                               "base={:08X} size={:X} reqLr={:08X} exact={} nearestBelow={} "
                               "below={:08X}+{:X} guestLr={:08X} tid={}",
                               n, call, (badVal != 0) ? "binhead" : "link", badSlot, linkHop,
                               (unsigned long long)gv, gv < 0x100000000ull ? 1 : 0,
                               (gv < 0x100000000ull && (lo + 0x0000000100000000ull) >= lo &&
                                (gv + 0x0000000100000000ull) >= lo &&
                                (gv + 0x0000000100000000ull) < hi)
                                   ? 1
                                   : 0,
                               bogus,
                               known ? 1 : 0, ab, asz, alr, exact ? 1 : 0, below ? 1 : 0, nb, nsz,
                               glr, GetCurrentThreadId());
            }
        }
    }

    // Session 72: post-present AV inside o1heapAllocate walking a corrupted
    // free list (CDCDCDCD class). Refuse the alloc instead of AVing the
    // process so the guest can take its own OOM path.
    if (!o1heapDoInvariantsHold(physicalHeap))
    {
        static std::atomic<uint32_t> s_badHeap{0};
        const uint32_t n = s_badHeap.fetch_add(1) + 1;
        if (n <= 8 || (n % 200) == 0)
        {
            const auto d = o1heapGetDiagnostics(physicalHeap);
            MCLA_LOG_ERROR("AllocPhysical: o1heap invariants FAIL #{} size={:#x} "
                           "align={:#x} cap={} peak={}",
                           n, size, alignment, d.capacity, d.peak_allocated);
        }
        // First failure: dump a few fragment headers so we can see what
        // overwrote the free list (CDCDCDCD / wild next ptr).
        if (n == 1 && physArenaBase != nullptr)
        {
            const uint8_t* p = physArenaBase;
            // O1HeapInstance is at arena start; fragment headers follow.
            // Dump first 8 qwords of the instance + first fragment area.
            uint64_t words[16] = {};
            std::memcpy(words, p, sizeof(words));
            MCLA_LOG_ERROR("o1heap arena[0..127]: {:016X} {:016X} {:016X} {:016X}",
                           words[0], words[1], words[2], words[3]);
            MCLA_LOG_ERROR("o1heap arena[32..]: {:016X} {:016X} {:016X} {:016X}",
                           words[4], words[5], words[6], words[7]);
        }
        return nullptr;
    }

    // Extra head-room guarantees the aligned user pointer sits at least one
    // O1HEAP_ALIGNMENT above the raw o1heap user pointer, so the two
    // bookkeeping words written below it can never overlap the o1heap
    // fragment header (next@-32, prev@-24, size@-16, used@-8). Overlapping it
    // destroyed the pow2-size/used invariants IsLiveAllocation checks.
    //
    void* ptr = MCLA_O1_ALLOC(physicalHeap, size + alignment + O1HEAP_ALIGNMENT);
    if (ptr == nullptr)
    {
        static std::atomic<uint32_t> s_nullPtr{0};
        const uint32_t n = s_nullPtr.fetch_add(1) + 1;
        if (n <= 8 || (n % 100) == 0)
            MCLA_LOG_ERROR("AllocPhysical: o1heapAllocate returned null #{} "
                           "size={:#x} align={:#x}",
                           n, size, alignment);
        return nullptr;
    }

    uintptr_t aligned = ((uintptr_t)ptr + alignment) & ~(alignment - 1);
    if (aligned < (uintptr_t)ptr + O1HEAP_ALIGNMENT)
        aligned += alignment;

    *((void**)aligned - 1) = ptr;
    *((size_t*)aligned - 2) = size + O1HEAP_ALIGNMENT;

    LivePhysAllocs().insert((void*)aligned);

    // Session 76j: full ownership history of the overlap window (the holder
    // vs guest-slab-element collision). Log every alloc landing here.
    {
        const uintptr_t g = mcla::kernel::g_memory.MapVirtual((void*)aligned);
        if (g >= 0xA0017FE0u && g < 0xA0018060u)
        {
            static std::atomic<uint32_t> s_winAlloc{0};
            const uint32_t n = s_winAlloc.fetch_add(1) + 1;
            uint32_t lr = 0;
            if (const PPCContext *c = GetPPCContext())
                lr = static_cast<uint32_t>(c->lr);
            MCLA_LOG_WARN("WIN76-ALLOC #{} guest={:08X} size={:#x} align={:#x} "
                          "lr={:08X}",
                          n, g, size, alignment, lr);
        }
    }
    return (void*)aligned;
}

void Heap::Free(void* ptr)
{
    if (ptr == nullptr)
        return;

    HeapGuardWindow hg;  // F-374: no header guard while we are inside the allocator

    CheckHeapHeader("pre-free", 0, heap, _ReturnAddress());  // F-370

    if (physicalHeap != nullptr && ptr >= physicalHeap)
    {
        // Physical allocs carry custom bookkeeping just below the returned
        // pointer: *(ptr-8)=raw o1heap frag ptr, *(ptr-16)=size+32. Validate
        // the RAW pointer before touching o1heap bins.
        std::lock_guard lock(physicalMutex);

        // Session 76j: enforce the exact-allocation contract first. Guest
        // sub-block frees must not reach o1heap even when the bytes below
        // them happen to look like a valid fragment header.
        if (LivePhysAllocs().erase(ptr) == 0)
        {
            static std::atomic<uint32_t> s_bogusFree{0};
            const uint32_t n = s_bogusFree.fetch_add(1) + 1;
            if (n <= 16)
            {
                uint32_t guestLr = 0;
                if (const PPCContext *c = GetPPCContext())
                    guestLr = static_cast<uint32_t>(c->lr);
                MCLA_LOG_WARN("Heap::Free: rejected NON-EXACT physical free "
                              "#{} ptr={:p} lr={:08X}",
                              n, ptr, guestLr);
                if (n == 1)
                {
                    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                    static std::once_flag symOnce76j;
                    std::call_once(symOnce76j, []() {
                        SymInitialize(GetCurrentProcess(), nullptr, TRUE);
                    });
                    void *frames[16] = {};
                    const USHORT nCap =
                        CaptureStackBackTrace(0, 16, frames, nullptr);
                    for (USHORT fi = 0; fi < nCap; ++fi)
                    {
                        alignas(8) char scratch[sizeof(SYMBOL_INFO) + 160];
                        SYMBOL_INFO *si = (SYMBOL_INFO *)scratch;
                        si->SizeOfStruct = sizeof(SYMBOL_INFO);
                        si->MaxNameLen = 159;
                        DWORD64 disp = 0;
                        char nameBuf[200];
                        const char *name = "???";
                        if (SymFromAddr(GetCurrentProcess(),
                                        (DWORD64)frames[fi], &disp, si))
                        {
                            snprintf(nameBuf, sizeof(nameBuf), "%s+0x%llx",
                                     si->Name, (unsigned long long)disp);
                            name = nameBuf;
                        }
                        MCLA_LOG_WARN("BOGUSFREE frame {:02d} {} {}", fi,
                                      (void *)frames[fi], name);
                    }
                }
            }
            return;
        }

        void* rawPtr = *((void**)ptr - 1);

        LiveProbe probe;
        if (!IsLiveAllocation(physArenaBase, physArenaSize, rawPtr, &probe))
        {
            MCLA_LOG_WARN("Heap::Free: rejected non-live physical pointer {:p} "
                          "(raw={:p} reason={} hdr next={} prev={} size=0x{:X} used={} arena=[{:p},{:p}))",
                          ptr, rawPtr, ProbeReasonName(probe.reason), probe.next, probe.prev,
                          probe.size, probe.used, (void*)physArenaBase,
                          (void*)(physArenaBase + physArenaSize));
            return;
        }
        // Session 76j: log frees releasing any part of the overlap window.
        {
            const uintptr_t g = mcla::kernel::g_memory.MapVirtual(ptr);
            const uintptr_t gsz = *((size_t*)ptr - 2);
            if (g + gsz >= 0xA0017FE0u && g < 0xA0018060u)
            {
                static std::atomic<uint32_t> s_winFree{0};
                const uint32_t n = s_winFree.fetch_add(1) + 1;
                uint32_t lr = 0;
                if (const PPCContext *c = GetPPCContext())
                    lr = static_cast<uint32_t>(c->lr);
                MCLA_LOG_WARN("WIN76-FREE #{} guest={:08X} size={:#x} lr={:08X}",
                              n, g, gsz, lr);
            }
        }
        MCLA_O1_FREE(physicalHeap, rawPtr);
    }
    else
    {
        std::lock_guard lock(mutex);
        LiveProbe probe;
        if (!IsLiveAllocation(heapArenaBase, heapArenaSize, ptr, &probe))
        {
            MCLA_LOG_WARN("Heap::Free: rejected non-live pointer {:p} "
                          "(reason={} hdr next={} prev={} size=0x{:X} used={} arena=[{:p},{:p}))",
                          ptr, ProbeReasonName(probe.reason), probe.next, probe.prev,
                          probe.size, probe.used, (void*)heapArenaBase,
                          (void*)(heapArenaBase + heapArenaSize));
            return;
        }
        MCLA_O1_FREE(heap, ptr);
        // F-370: a free of a pointer that was live but whose neighbour bookkeeping was wrong
        // coalesces straight over the allocator's own header. If the header goes bad here rather
        // than at an alloc, this line names the freeing caller.
        CheckHeapHeader("post-free", reinterpret_cast<size_t>(ptr), heap, _ReturnAddress());
    }
}

size_t Heap::Size(void* ptr)
{
    if (!ptr) return 0;
    // Only read header if ptr was allocated from this heap
    LiveProbe probe;
    if (IsLiveAllocation(heapArenaBase, heapArenaSize, ptr, &probe))
        return *((size_t*)ptr - 2) - O1HEAP_ALIGNMENT;
    if (physicalHeap != nullptr && IsLiveAllocation(physArenaBase, physArenaSize, ptr, &probe))
        return *((size_t*)ptr - 2) - O1HEAP_ALIGNMENT;
    return 0;
}

uint32_t RtlAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t size)
{
    void* ptr = g_userHeap.Alloc(size);
    if (!ptr) return 0;
    if ((flags & 0x8) != 0)
        memset(ptr, 0, size);

    assert(ptr);
    return mcla::kernel::g_memory.MapVirtual(ptr);
}

uint32_t RtlReAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer, uint32_t size)
{
    void* ptr = g_userHeap.Alloc(size);
    if (!ptr) return 0;
    if ((flags & 0x8) != 0)
        memset(ptr, 0, size);

    if (memoryPointer != 0)
    {
        void* oldPtr = mcla::kernel::g_memory.Translate(memoryPointer);
        memcpy(ptr, oldPtr, std::min<size_t>(size, g_userHeap.Size(oldPtr)));
        g_userHeap.Free(oldPtr);
    }

    assert(ptr);
    return mcla::kernel::g_memory.MapVirtual(ptr);
}

uint32_t RtlFreeHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer)
{
    if (memoryPointer != NULL)
        g_userHeap.Free(mcla::kernel::g_memory.Translate(memoryPointer));

    return true;
}

uint32_t RtlSizeHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer)
{
    if (memoryPointer != NULL)
        return (uint32_t)g_userHeap.Size(mcla::kernel::g_memory.Translate(memoryPointer));

    return 0;
}

uint32_t XAllocMem(uint32_t size, uint32_t flags)
{
    // F-133 census (read-only; at most 40 lines per boot). The frontier's last
    // deterministic guest event is a physical allocation of 0xFFFFFFFF that
    // fails - once per boot, identical in w138/w140/w141 (w138:12555) - and the
    // guest then memcpy's that same length (r5=0xFFFFFFFF at the store site,
    // w142) for ~321 MB. MmAllocatePhysicalMemoryEx is ruled out as the caller
    // (its own FAILED line never prints), so name this import's caller: lr, the
    // flags bits (bit30 is the ones that would memset a null ptr below) and the
    // caller's stack words.
    if (size >= 0x04000000u)
    {
        static std::atomic<uint32_t> s_hugeAlloc{0};
        const uint32_t n = s_hugeAlloc.fetch_add(1) + 1;
        if (n <= 40)
        {
            uint32_t lr = 0, sp = 0, a3 = 0, a4 = 0, a5 = 0;
            uint32_t s[8] = {};
            if (const PPCContext *c = GetPPCContext())
            {
                lr = static_cast<uint32_t>(c->lr);
                sp = c->r1.u32;
                a3 = c->r3.u32;
                a4 = c->r4.u32;
                a5 = c->r5.u32;
                for (int k = 0; k < 8; ++k)
                    (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(
                        sp + k * 4u, &s[k]);
            }
            MCLA_LOG_WARN("XALLOC-HUGE #{} size={:#x} flags={:08X} lr={:08X} "
                          "r3={:08X} r4={:08X} r5={:08X} sp={:08X} "
                          "stk=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                          "{:08X} {:08X}]",
                          n, size, flags, lr, a3, a4, a5, sp, s[0], s[1], s[2],
                          s[3], s[4], s[5], s[6], s[7]);
        }
    }
    void* ptr = (flags & 0x80000000) != 0 ?
        g_userHeap.AllocPhysical(size, (1ull << ((flags >> 24) & 0xF))) :
        g_userHeap.Alloc(size);

    if ((flags & 0x40000000) != 0)
        memset(ptr, 0, size);

    assert(ptr);
    return mcla::kernel::g_memory.MapVirtual(ptr);
}

void XFreeMem(uint32_t baseAddress, uint32_t flags)
{
    if (baseAddress != NULL)
        g_userHeap.Free(mcla::kernel::g_memory.Translate(baseAddress));
}

GUEST_FUNCTION_STUB(sub_82BD7788); // HeapCreate
GUEST_FUNCTION_STUB(sub_82BD9250); // HeapDestroy

GUEST_FUNCTION_HOOK(sub_82BD7D30, RtlAllocateHeap);
GUEST_FUNCTION_HOOK(sub_82BD8600, RtlFreeHeap);
GUEST_FUNCTION_HOOK(sub_82BD88F0, RtlReAllocateHeap);
GUEST_FUNCTION_HOOK(sub_82BD6FD0, RtlSizeHeap);

GUEST_FUNCTION_HOOK(sub_831CC9C8, XAllocMem);
GUEST_FUNCTION_HOOK(sub_831CCA60, XFreeMem);
