#include <stdafx.h>
#include "heap.h"
#include "memory.h"
#include "function.h"
#include "logging.h"

constexpr size_t RESERVED_BEGIN = 0x7FEA0000;
constexpr size_t RESERVED_END = 0xA0000000;

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

    return o1heapAllocate(heap, std::max<size_t>(1, size));
}

void* Heap::AllocPhysical(size_t size, size_t alignment)
{
    size = std::max<size_t>(1, size);
    alignment = alignment == 0 ? 0x1000 : std::max<size_t>(16, alignment);

    std::lock_guard lock(physicalMutex);

    // Extra head-room guarantees the aligned user pointer sits at least one
    // O1HEAP_ALIGNMENT above the raw o1heap user pointer, so the two
    // bookkeeping words written below it can never overlap the o1heap
    // fragment header (next@-32, prev@-24, size@-16, used@-8). Overlapping it
    // destroyed the pow2-size/used invariants IsLiveAllocation checks.
    void* ptr = o1heapAllocate(physicalHeap, size + alignment + O1HEAP_ALIGNMENT);
    if (ptr == nullptr)
        return nullptr;

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
        o1heapFree(physicalHeap, rawPtr);
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
        o1heapFree(heap, ptr);
    }
}

size_t Heap::Size(void* ptr)
{
    if (ptr)
        return *((size_t*)ptr - 2) - O1HEAP_ALIGNMENT; // relies on fragment header in o1heap.c

    return 0;
}

uint32_t RtlAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t size)
{
    void* ptr = g_userHeap.Alloc(size);
    if ((flags & 0x8) != 0)
        memset(ptr, 0, size);

    assert(ptr);
    return mcla::kernel::g_memory.MapVirtual(ptr);
}

uint32_t RtlReAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer, uint32_t size)
{
    void* ptr = g_userHeap.Alloc(size);
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
