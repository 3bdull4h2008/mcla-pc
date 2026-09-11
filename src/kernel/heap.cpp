#include <stdafx.h>
#include "heap.h"
#include "memory.h"
#include "function.h"
#include "logging.h"
#include <atomic>

constexpr size_t RESERVED_BEGIN = 0x7FEA0000;
constexpr size_t RESERVED_END = 0xA0000000;

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

void Heap::Init()
{
    heapArenaBase = (uint8_t*)mcla::kernel::g_memory.Translate(0x20000);
    heapArenaSize = RESERVED_BEGIN - 0x20000;
    heap = o1heapInit(heapArenaBase, heapArenaSize);

    physArenaBase = (uint8_t*)mcla::kernel::g_memory.Translate(RESERVED_END);
    physArenaSize = 0x100000000 - RESERVED_END;
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

void* Heap::Alloc(size_t size)
{
    std::lock_guard lock(mutex);

    if (heap == nullptr)
        return nullptr;
    if (!o1heapDoInvariantsHold(heap))
    {
        static std::atomic<uint32_t> s_badMain{0};
        const uint32_t n = s_badMain.fetch_add(1) + 1;
        if (n <= 8 || (n % 200) == 0)
            MCLA_LOG_ERROR("Alloc: o1heap invariants FAIL #{} size={:#x}", n,
                           size);
        return nullptr;
    }
    void* ptr = MCLA_O1_ALLOC(heap, std::max<size_t>(1, size));
    if (ptr == nullptr)
    {
        static std::atomic<uint32_t> s_nullMain{0};
        const uint32_t n = s_nullMain.fetch_add(1) + 1;
        if (n <= 8 || (n % 100) == 0)
            MCLA_LOG_ERROR("Alloc: o1heapAllocate returned null #{} size={:#x}",
                           n, size);
    }
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

    if (physicalHeap == nullptr)
        return nullptr;

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

    return (void*)aligned;
}

void Heap::Free(void* ptr)
{
    if (ptr == nullptr)
        return;

    if (physicalHeap != nullptr && ptr >= physicalHeap)
    {
        // Physical allocs carry custom bookkeeping just below the returned
        // pointer: *(ptr-8)=raw o1heap frag ptr, *(ptr-16)=size+32. Validate
        // the RAW pointer before touching o1heap bins.
        std::lock_guard lock(physicalMutex);
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
