#pragma once
#include <kernel/mutex.h>
#include <kernel/heap_arena.h>  // F-384: kUserHeapArenaVa / kUserHeapArenaEnd

#include <kernel/o1heap.h>
#include <cstdint>

struct Heap
{
    Mutex mutex;
    O1HeapInstance* heap;

    Mutex physicalMutex;
    O1HeapInstance* physicalHeap;

    // Arena bounds for validate-before-free (crash fix: interior/foreign
    // pointers routed into o1heapFree corrupted bins and AV'd at 0x208).
    uint8_t* heapArenaBase = nullptr;
    size_t heapArenaSize = 0;
    uint8_t* physArenaBase = nullptr;
    size_t physArenaSize = 0;

    void Init();

    // Binds an externally-placed o1heap arena as the physical heap AND records
    // its bounds for validate-before-free. Direct field pokes leave
    // physArenaBase/Size null and make Free() reject every valid allocation.
    void AttachPhysicalArena(void* base, size_t size);

    void* Alloc(size_t size);
    void* AllocPhysical(size_t size, size_t alignment);
    void Free(void* ptr);

    // Diagnostic snapshot of a validate-before-free probe. Only filled when
    // the pointer itself was safe to read; otherwise reason says why not.
    struct LiveProbe
    {
        enum class Reason : uint8_t
        {
            Ok,
            Null,
            OutOfArena,
            Misaligned,
            BadSize,
            NotUsed,
            BadPointers,
        };
        Reason reason = Reason::Null;
        void* next = nullptr;
        void* prev = nullptr;
        size_t size = 0;
        bool used = false;
    };

    // Returns true if ptr looks like a live allocation from the given arena:
    // inside bounds, header size sane/aligned, used flag set.
    [[nodiscard]] bool IsLiveAllocation(uint8_t* arenaBase, size_t arenaSize, void* ptr,
                                        LiveProbe* out = nullptr) const;

    // True when ptr lies inside the physical (AllocPhysical) arena. Used to
    // distinguish NtCreate* identity handles (host KernelObject*) from
    // guest-owned dispatcher headers that must be lazy-wrapped.
    [[nodiscard]] bool IsPhysicalArenaPtr(void* ptr) const {
        if (!physArenaBase || !ptr) return false;
        auto *p = static_cast<uint8_t*>(ptr);
        return p >= physArenaBase && p < physArenaBase + physArenaSize;
    }

    size_t Size(void* ptr);

    template<typename T, typename... Args>
    T* Alloc(Args&&... args)
    {
        T* obj = (T*)Alloc(sizeof(T));
        // F-390b: `obj` is null on an honest OOM (F-390 made that path reachable for real: the SEH
        // around o1heap now returns null instead of the VEH parking the thread). Constructing into it
        // was a write to 0x0 -- `w394`..`w403`'s `AllocPhysical: o1heapAllocate returned null #1
        // size=0x28 align=0x10` was immediately followed by exactly that fault.
        if (obj == nullptr)
            return nullptr;
        new (obj) T(std::forward<Args>(args)...);
        return obj;
    }

    template<typename T, typename... Args>
    T* AllocPhysical(Args&&... args)
    {
        T* obj = (T*)AllocPhysical(sizeof(T), alignof(T));
        if (obj == nullptr)  // F-390b, same reason as `Alloc<T>` above
            return nullptr;
        new (obj) T(std::forward<Args>(args)...);
        return obj;
    }
};

extern Heap g_userHeap;

// F-806: the o1heap INSTANCE memory, or null when the instance is attached in-arena instead.
// F-779 moved both instances out of their arenas (`o1heapInitSeparate` over a `VirtualAlloc` block),
// which left boot_host.cpp's F-374/F-388 write-watchers pointing at the ARENA BASE. That page is no
// longer the allocator header: `o1heapInitSeparate` initialises the root Fragment AT base
// (o1heap.c:399-404), so the first 4 KB of the arena is root-fragment header followed immediately by
// payload handed to the first allocation. These accessors give the watchers the page they were
// written to watch. Non-new-symbol taint list for rule 1b: `UserHeapInstanceMem`,
// `PhysHeapInstanceMem` are the only two host symbols this change adds; they read existing statics
// and are used by src/boot_host.cpp only.
uint8_t* UserHeapInstanceMem(void);
uint8_t* PhysHeapInstanceMem(void);
