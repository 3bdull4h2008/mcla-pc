#include <stdafx.h>
#include "xdm.h"

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

// CONSOLE-CORRECT GUEST-VISIBLE DISPATCHER HEADER (2026-10-21, fix_typebyte).
//
// MEASURED (the guest's own bytes are the oracle):
//  * The console's kernel-object layout that the GUEST ITSELF writes is a
//    16-byte dispatcher header whose CLASS/TYPE byte is at offset +0, the
//    signal state at +4 and the wait list at +8/+12:
//      - the guest's own header initialiser (generated/ppc_xenon/
//        ppc_recomp.72.cpp:19342-19384) stores the Type byte at +0, a word at
//        +4, and SELF-LINKS the wait list (Flink = Blink = &header+8) at
//        +8/+12, then calls __imp__KeInitializeSemaphore on that header;
//      - the guest waits on / sets / resets such a header RAW: 0x8242FCD4
//        `addi r3,r26,32` (r26+32 == 0x40004D7C) / 0x8242FCD8
//        `bl 0x827BD874` = __imp__KeResetEvent, and 0x8242FC18
//        `bl 0x827BD5A4` = __imp__KeWaitForSingleObject on the same +32.
//    => The HANDLE a title holds for a kernel object IS the dispatcher
//       header; there is no separate OBJECT_HEADER in front of it.
//  * The host's own XDISPATCHER_HEADER has exactly that shape
//    (src/kernel/xbox.h:168-199: Type at +0, SignalState at +4, WaitListHead
//    at +8); Xenia's X_DISPATCH_HEADER is 0x10 bytes with `type` at +0
//    (.research/xenia/src/xenia/kernel/xobject.h:38-63).
//
// BEFORE this change the handle was MapVirtual(obj) = the OBJECT BASE, and
// KernelObject is POLYMORPHIC (virtual dtor xdm.h:41, virtual Wait xdm.h:51),
// so the C++ vptr sat at +0 and the embedded header at +8. The guest
// therefore read the VPTR's low byte as the class id: 0x28, measured 61/61
// host-created semaphores in build/w838.log
// ("TYPE-CENSUS[REL] obj=B660F040 type=28") while the host wrote Type=5 at
// obj+8.
//
// NOW the handle IS the dispatcher header, so the guest-visible bytes at the
// handle are the console's 16-byte header and handle+0 IS the class id.
//
// FALSIFIER: the guest-visible Type byte at a host-created handle must read
// the class id (5 for a semaphore), never 0x28.
uint32_t GetKernelHandle(KernelObject* obj)
{
    assert(obj != GetInvalidKernelObject());
    return mcla::kernel::g_memory.MapVirtual(&obj->header);
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
