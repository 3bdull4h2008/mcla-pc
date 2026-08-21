#pragma once

#include "mutex.h"
#include <o1heap.h>
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

    size_t Size(void* ptr);

    template<typename T, typename... Args>
    T* Alloc(Args&&... args)
    {
        T* obj = (T*)Alloc(sizeof(T));
        new (obj) T(std::forward<Args>(args)...);
        return obj;
    }

    template<typename T, typename... Args>
    T* AllocPhysical(Args&&... args)
    {
        T* obj = (T*)AllocPhysical(sizeof(T), alignof(T));
        new (obj) T(std::forward<Args>(args)...);
        return obj;
    }
};

extern Heap g_userHeap;
