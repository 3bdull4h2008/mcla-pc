#include <stdafx.h>
#include "xdm.h"
#include "freelist.h"

Mutex g_kernelLock;

void DestroyKernelObject(KernelObject* obj)
{
    if (!obj) return;
    std::lock_guard lock(g_kernelLock);
    // DURABLE WRAPPER IDENTITY (session 64): drop the side-map entry so a
    // recycled guest header cannot resolve to a destroyed wrapper.
    if (obj->identityHdrAddr != 0)
        WrapperIdentityMap().erase(obj->identityHdrAddr);

    obj->~KernelObject();
    g_userHeap.Free(obj);
}

uint32_t GetKernelHandle(KernelObject* obj)
{
    assert(obj != GetInvalidKernelObject());
    return mcla::kernel::g_memory.MapVirtual(obj);
}

void DestroyKernelObject(uint32_t handle)
{
    auto* obj = GetKernelObject(handle);
    if (!obj) return;
    DestroyKernelObject(obj);
}

bool IsKernelObject(uint32_t handle)
{
    if (handle == GUEST_INVALID_HANDLE_VALUE)
        return false;

    void* translated = mcla::kernel::GuestMemoryHeap::Instance().Translate(handle);
    return translated != nullptr;
}

bool IsKernelObject(void* obj)
{
    return IsKernelObject(mcla::kernel::g_memory.MapVirtual(obj));
}

bool IsInvalidKernelObject(void* obj)
{
    return obj == GetInvalidKernelObject();
}
