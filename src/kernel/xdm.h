#pragma once

#include <atomic>
#include "heap.h"
#include "memory.h"
#include "xbox.h"

// Host thread id of the boot worker (the guest's main thread). Set by
// boot_host once the worker starts; imports use it to attribute waits.
extern std::atomic<uint32_t> g_mainGuestThreadId;

#define OBJECT_SIGNATURE           (uint32_t)'XBOX'
#define GUEST_INVALID_HANDLE_VALUE 0xFFFFFFFF

struct KernelObject
{
    // Guest-visible dispatcher header, MUST be first: handles are guest VAs,
    // and guest-side thunks validate them by checking
    // WaitListHead.Flink == 'XBOX' before touching the object.
    XDISPATCHER_HEADER header{};

    KernelObject()
    {
        header.WaitListHead.Flink = OBJECT_SIGNATURE;
        header.WaitListHead.Blink = 0;
    }

    virtual ~KernelObject()
    {
        header.WaitListHead.Flink = 0; // invalidate on destruction
    }

    virtual uint32_t Wait(uint32_t timeout)
    {
        assert(false && "Wait not implemented for this kernel object.");
        return STATUS_TIMEOUT;
    }

    bool IsValid() const { return header.WaitListHead.Flink == OBJECT_SIGNATURE; }
};

template<typename T, typename... Args>
inline T* CreateKernelObject(Args&&... args)
{
    static_assert(std::is_base_of_v<KernelObject, T>);
    return g_userHeap.AllocPhysical<T>(std::forward<Args>(args)...);
}

template<typename T = KernelObject>
inline T* GetKernelObject(uint32_t handle)
{
    assert(handle != GUEST_INVALID_HANDLE_VALUE);
    return reinterpret_cast<T*>(mcla::kernel::GuestMemoryHeap::Instance().Translate(handle));
}

uint32_t GetKernelHandle(KernelObject* obj);

void DestroyKernelObject(KernelObject* obj);
void DestroyKernelObject(uint32_t handle);

bool IsKernelObject(uint32_t handle);
bool IsKernelObject(void* obj);

bool IsInvalidKernelObject(void* obj);

template<typename T = void>
inline T* GetInvalidKernelObject()
{
    return reinterpret_cast<T*>(mcla::kernel::GuestMemoryHeap::Instance().Translate(GUEST_INVALID_HANDLE_VALUE));
}

extern Mutex g_kernelLock;

template<typename T>
inline T* QueryKernelObject(XDISPATCHER_HEADER& header)
{
    std::lock_guard guard{ g_kernelLock };
    if (header.WaitListHead.Flink != OBJECT_SIGNATURE)
    {
        header.WaitListHead.Flink = OBJECT_SIGNATURE;
        auto* obj = CreateKernelObject<T>(reinterpret_cast<typename T::guest_type*>(&header));
        header.WaitListHead.Blink = mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(obj);

        return obj;
    }

    return static_cast<T*>(mcla::kernel::GuestMemoryHeap::Instance().Translate(header.WaitListHead.Blink));
}

// Get object without initialisation
template<typename T>
inline T* TryQueryKernelObject(XDISPATCHER_HEADER& header)
{
    if (header.WaitListHead.Flink != OBJECT_SIGNATURE)
        return nullptr;

    return static_cast<T*>(mcla::kernel::GuestMemoryHeap::Instance().Translate(header.WaitListHead.Blink));
}

// TLS functions
uint32_t KeTlsAlloc();
uint32_t KeTlsFree(uint32_t dwTlsIndex);
uint32_t KeTlsGetValue(uint32_t dwTlsIndex);
uint32_t KeTlsSetValue(uint32_t dwTlsIndex, uint32_t lpTlsValue);