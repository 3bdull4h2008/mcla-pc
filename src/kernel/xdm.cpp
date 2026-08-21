#include <stdafx.h>
#include "xdm.h"
#include "freelist.h"

Mutex g_kernelLock;

void DestroyKernelObject(KernelObject* obj)
{
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
    DestroyKernelObject(GetKernelObject(handle));
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
