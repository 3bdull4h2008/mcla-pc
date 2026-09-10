#pragma once

#include <atomic>
#include <spdlog/spdlog.h>
#include <unordered_map>
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

    // Host-only: guest address of the embedded dispatcher header this wrapper
    // was lazy-wrapped over (0 = kernel-created object). Used by
    // QueryKernelObject's durable identity map and erased on destroy.
    uint32_t identityHdrAddr = 0;

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
    // SESSION 70c: The old path did Translate(handle) → raw guest memory →
    // reinterpret_cast<KernelObject*>.  This bypassed WrapperIdentityMap and
    // returned a pointer to the raw guest dispatcher struct whose vtable and
    // atomic fields are garbage — Wait() on it was undefined behavior.
    // Look up the canonical host wrapper first.  If a prior QueryKernelObject
    // call (e.g. from NtCreateSemaphore/NtReleaseSemaphore) already minted a
    // wrapper for this header address, return it so Wait/Release share state.
    // Fall back to the raw cast when no wrapper exists yet (handles for
    // non-dispatcher objects, or pre-init callers).
    void* raw = mcla::kernel::GuestMemoryHeap::Instance().Translate(handle);
    if (!raw) return nullptr;
    auto* hdr = reinterpret_cast<XDISPATCHER_HEADER*>(raw);
    auto* wrapper = TryQueryKernelObject<T>(*hdr);
    if (wrapper) return wrapper;
    return reinterpret_cast<T*>(raw);
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

// DURABLE WRAPPER IDENTITY (session 64): the guest driver owns its dispatcher
// headers and rewrites WaitListHead.Flink/Blink at will, so OBJECT_SIGNATURE
// in guest memory is NOT a durable marker — lazy-wraps kept building phantom
// wrappers and signals were lost between the wait and release paths (the
// 0x40004D7C tick-semaphore wake-loss: releases landed on wrapper A, the
// waiter blocked on wrapper B). Wrapper identity is now kept host-side,
// keyed by the header's guest address + the header's Type byte.
struct WrapperRecord
{
    KernelObject* obj;
    uint8_t type;
};
inline std::unordered_map<uint32_t, WrapperRecord>& WrapperIdentityMap()
{
    static std::unordered_map<uint32_t, WrapperRecord> s_map;
    return s_map;
}

template<typename T = KernelObject>
inline T* QueryKernelObject(XDISPATCHER_HEADER& header)
{
    std::lock_guard guard{ g_kernelLock };
    const uint32_t hdrAddr = mcla::kernel::g_memory.MapVirtual(&header);
    const uint8_t wantType = header.Type;

    auto it = WrapperIdentityMap().find(hdrAddr);
    if (it != WrapperIdentityMap().end() && it->second.type == wantType)
        return static_cast<T*>(it->second.obj);

    // TYPE-FLIP PROBE (session 64): a rewrite of the guest Type byte would
    // mint a fresh wrapper per call and orphan the one the waiter sleeps on.
    if (it != WrapperIdentityMap().end())
    {
        static std::atomic<uint32_t> s_typeFlips{0};
        const uint32_t n = s_typeFlips.fetch_add(1) + 1;
        if (n <= 20 || (n % 500) == 0)
            spdlog::warn("KOBJ-TYPEFLIP #{0} hdr={1:08X} old={2:02X} new={3:02X}",
                         n, hdrAddr, it->second.type, wantType);
    }

    auto* obj = CreateKernelObject<T>(reinterpret_cast<typename T::guest_type*>(&header));
    obj->identityHdrAddr = hdrAddr;
    WrapperIdentityMap()[hdrAddr] = {obj, wantType};

    // Keep the legacy guest-visible markers in sync for code paths (guest-side
    // thunks validate Flink == 'XBOX' before touching the object).
    header.WaitListHead.Flink = OBJECT_SIGNATURE;
    header.WaitListHead.Blink = mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(obj);

    return obj;
}

// Get object without initialisation
template<typename T = void>
inline T* TryQueryKernelObject(XDISPATCHER_HEADER& header)
{
    std::lock_guard guard{ g_kernelLock };
    const uint32_t hdrAddr = mcla::kernel::g_memory.MapVirtual(&header);
    auto it = WrapperIdentityMap().find(hdrAddr);
    if (it != WrapperIdentityMap().end() && it->second.type == header.Type)
        return static_cast<T*>(it->second.obj);
    return nullptr;
}

// TLS functions
uint32_t KeTlsAlloc();
uint32_t KeTlsFree(uint32_t dwTlsIndex);
uint32_t KeTlsGetValue(uint32_t dwTlsIndex);
uint32_t KeTlsSetValue(uint32_t dwTlsIndex, uint32_t lpTlsValue);