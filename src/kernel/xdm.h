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

// T43.18 (2026-10-13): the main thread's LATEST wait, published uncapped by
// the main-park probes (imports.cpp) for the render-thread heartbeat
// (HB-FLICKER mainwait=* in render_thread.cpp). Handle/lr stampit: the
// probe's 200-row cap blinds the TAIL of a soak, while the heartbeat prints
// ~every 4 s all run, so the tail always shows the latest main park.
// mainwait_age_ms on the HB row (now minus ns) says how stale the stamp
// is; 0 handle = no main park yet observed.
extern std::atomic<uint32_t> g_mainParkHandle;
extern std::atomic<uint32_t> g_mainParkLr;
extern std::atomic<uint64_t> g_mainParkNs;

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

// (rule 1b, 2026-10-21 fix_typebyte) The offset of the embedded dispatcher
// header inside a KernelObject wrapper.  The handle the guest holds IS that
// header (GetKernelHandle -> MapVirtual(&obj->header)), so the wrapper is
// recovered from a guest-visible header address by subtracting this offset.
// It is MEASURED at creation time (CreateKernelObject) because KernelObject
// is polymorphic: the position of the C++ vptr relative to the first data
// member is ABI-defined, not standard, so it is not assumed.
inline uint32_t& KernelObjectHeaderOffset()
{
    static uint32_t s_offset = sizeof(void *);
    return s_offset;
}

template<typename T, typename... Args>
inline T* CreateKernelObject(Args&&... args)
{
    static_assert(std::is_base_of_v<KernelObject, T>);
    T* obj = g_userHeap.AllocPhysical<T>(std::forward<Args>(args)...);
    // Measure the real header offset (see KernelObjectHeaderOffset).
    KernelObjectHeaderOffset() = static_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(&obj->header) -
        reinterpret_cast<uintptr_t>(obj));
    return obj;
}

// Forward declaration of the type-agnostic dispatcher-address lookup defined
// further down (one registry, one wrapper per dispatcher address). Declared
// here because GetKernelObject (below) needs it to tell "this address is
// known but the class differs" from "this address is unknown".
inline KernelObject* LookupKernelObjectByDispatcher(XDISPATCHER_HEADER& header);

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
    // p2f NOTE: the raw fallback feeds guest memory to dynamic_cast as a
    // polymorphic object — UB. Callers that dynamic_cast the result must
    // null/vptr-check first (see NtReleaseSemaphore p2f guard).
    //
    // CONSOLE-CORRECT HANDLE (2026-10-21, fix_typebyte): the handle IS the
    // dispatcher header (GetKernelHandle -> MapVirtual(&obj->header), see the
    // note in xdm.cpp), so `raw` below is the HEADER, not a KernelObject.
    // Casting it to T* and calling a virtual on it is a wild vtable call, so
    // the fallbacks are rewritten:
    //  * address known, class differs -> nullptr (refuse, never type-confuse);
    //  * address unknown, physical-arena object -> the wrapper sits
    //    KernelObjectHeaderOffset() BELOW the header (the C++ vptr is at
    //    the wrapper's base), so recover it by subtracting that offset;
    //  * otherwise the address is a guest-owned header: the old raw fallback
    //    was already UB there and stays last-resort only.
    void* raw = mcla::kernel::GuestMemoryHeap::Instance().Translate(handle);
    if (!raw) return nullptr;
    auto* hdr = reinterpret_cast<XDISPATCHER_HEADER*>(raw);
    auto* wrapper = TryQueryKernelObject<T>(*hdr);
    if (wrapper) return wrapper;
    if (LookupKernelObjectByDispatcher(*hdr)) return nullptr;
    if (g_userHeap.IsPhysicalArenaPtr(raw))
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(raw) -
                                   KernelObjectHeaderOffset());
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
//
// ONE REGISTRY, ONE WRAPPER PER DISPATCHER ADDRESS (2026-10-21, fix_dpc).
// MEASURED, and it CORRECTS build/agents/audit_threads.md C14/C15:
//   * CreateRegisteredKernelObject registers under MapVirtual(obj) — the
//     guest-visible handle (xdm.h below).
//   * QueryKernelObject/TryQueryKernelObject looked up under
//     MapVirtual(&header) AND COMPARED the guest-visible Type byte.
//   * BOTH ladders are called with the GUEST pointer (the handle), so the
//     KEYS already coincide — the two ladders did NOT address different
//     objects. What did NOT coincide was the Type byte: for a host-created
//     object the guest-visible bytes at the handle are the C++ vptr, so
//     `header.Type` reads 0x28 (the vptr's low byte) while the host wrote
//     Type=5 at obj+8 (audit C15, 61/61 semaphores). The comparison then
//     failed and QueryKernelObject MINTED A SECOND WRAPPER AND REPLACED the
//     map entry (xdm.h:185 before this change) — orphaning the wrapper a
//     waiter was parked on. That orphaning, not a key mismatch, is the
//     wake-loss mechanism.
//
// CORRECTION (2026-10-21, fix_typebyte).  The "KEYS already coincide" claim
// above is TRUE only for GUEST-owned headers.  For a HOST-created object the
// create key was MapVirtual(obj) = the object BASE while the query key is
// MapVirtual(&header) = base + 8 (the C++ vptr sits at the base), so the
// two ladders really were 8 bytes apart.  With the console-correct handle
// (GetKernelHandle -> MapVirtual(&obj->header), xdm.cpp) the handle IS the
// dispatcher header, so EVERY object — host-created or guest-owned — is
// keyed by its dispatcher address and the registry is literally ONE
// registry.  The guest-visible Type byte is now the class id the host
// published (handle+0), not a vptr byte.
// THEREFORE: one registry, resolved by OBJECT IDENTITY (dynamic_cast), and
//   * the guest-visible Type byte NEVER selects the object (it is
//     guest-writable, and for host-created objects it is a vptr byte);
//   * an existing entry is NEVER replaced — a class mismatch mints an
//     UNREGISTERED view (identityHdrAddr = 0) so the canonical wrapper
//     survives, and the mismatch is logged (KOBJ-CLASSFLIP).
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

// Register a CreateKernelObject product in WrapperIdentityMap keyed by the
// guest identity handle (MapVirtual of the host object). NtWaitForSingleObject
// resolves identity handles via GetKernelObject → Translate → raw host pointer.
// NtReleaseSemaphore previously fell through to QueryKernelObject, which minted
// a SECOND host wrapper over the same guest VA — Release landed on the new
// wrapper while Wait slept on the original (ring-B preload never woke; F-039).
// Key is the handle itself (object start); Type is stored for guest-header
// Query paths but identity lookups are type-agnostic.
//
// ONE REGISTRY (2026-10-21): the handle IS the dispatcher header the guest
// holds (the console's handle points at the dispatcher header, see
// GetKernelHandle in xdm.cpp), so this key and QueryKernelObject's
// MapVirtual(&header) key are the SAME address for EVERY object - host-
// created or guest-owned. Before 2026-10-21 (fix_typebyte) the handle was
// MapVirtual(obj) = the object BASE, so for a host-created object the two
// keys differed by the 8 bytes of the C++ vptr and the registry was really
// two registries. The recorded Type is the host's own class id and is NOT
// compared against the guest-visible byte any more - see the ONE REGISTRY
// note above.
template<typename T, typename... Args>
inline uint32_t CreateRegisteredKernelObject(uint8_t type, Args&&... args)
{
    static_assert(std::is_base_of_v<KernelObject, T>);
    T* obj = CreateKernelObject<T>(std::forward<Args>(args)...);
    // F-856 (2026-10-22): AN HONEST OOM MUST NOT BE A HOST AV.
    //
    // CreateKernelObject returns nullptr when Heap::AllocPhysical cannot
    // satisfy the request (heap.h:85-93 -- the F-390b note says exactly
    // that).  The line below then wrote `type` through a null `obj`, and
    // because KernelObject is polymorphic (xdm.h:41) the C++ vptr sits at
    // offset 0 and `header` at offset 8, so the write landed on host
    // address 0x8 and killed the whole thread.
    //
    // MEASURED (build/w871.log:336554-336583, the boot-root thread):
    //   Vectored exception: code=0xC0000005 ... Param[1]=0x0x8
    //   [ 4] CreateRegisteredKernelObject<Semaphore,unsigned int &,unsigned int &> +0x89
    //   [ 5] NtCreateSemaphore +0x3C
    //   [ 7] __imp__sub_8244EC78 +0xDF
    //   VEH-NEUTRAL guest AV: lr=8244ECC8 write to host addr 0x8
    // with the pool already exhausted 556 ms earlier:
    //   PHYS-STATE #2000 ... free=0x0 verdict=exhausted why=no_free_fragment
    //   oom=2000 tid=956
    //
    // So an OOM -- which the guest CAN handle -- was turned into a
    // process-fatal null dereference, and that is why the boot-root thread
    // died instead of degrading (the boot gate never ran).
    //
    // The fix returns the INVALID HANDLE instead of inventing one.  It does
    // NOT skip the registration for a live object: when the allocation
    // succeeds every step below is byte-for-byte the old one.  The CALLER
    // must still turn the invalid handle into an NTSTATUS (do-not #1/#9:
    // no fake handle, no fake success) -- NtCreateSemaphore and
    // NtCreateEvent now do exactly that.
    if (obj == nullptr)
    {
        return GUEST_INVALID_HANDLE_VALUE;
    }
    obj->header.Type = type;
    // The class id is published in the object's OWN guest-visible bytes:
    // header.Type is at the dispatcher header, and the handle IS that
    // header, so the guest reads the class id at handle+0 (console layout).
    const uint32_t handle = GetKernelHandle(obj); // MapVirtual(&obj->header)
    obj->identityHdrAddr = handle;
    {
        std::lock_guard guard{ g_kernelLock };
        WrapperIdentityMap()[handle] = { obj, type };
    }
    return handle;
}

// Type-agnostic identity lookup (NtCreate* products). Returns nullptr when
// this handle was never registered as an identity object.
inline KernelObject* LookupIdentityKernelObject(uint32_t handle)
{
    std::lock_guard guard{ g_kernelLock };
    auto it = WrapperIdentityMap().find(handle);
    if (it == WrapperIdentityMap().end())
        return nullptr;
    return it->second.obj;
}

// Type-agnostic lookup by DISPATCHER ADDRESS: the canonical wrapper that owns
// the XDISPATCHER_HEADER the caller holds, whatever its class. This is the
// "one registry" entry point the wait/release/set paths use so that the
// guest-visible Type byte can never choose a DIFFERENT object for the same
// address (see the ONE REGISTRY note above). nullptr = no wrapper yet.
inline KernelObject* LookupKernelObjectByDispatcher(XDISPATCHER_HEADER& header)
{
    std::lock_guard guard{ g_kernelLock };
    const uint32_t hdrAddr = mcla::kernel::g_memory.MapVirtual(&header);
    auto it = WrapperIdentityMap().find(hdrAddr);
    if (it == WrapperIdentityMap().end())
        return nullptr;
    return it->second.obj;
}

// Resolve the canonical wrapper for a dispatcher address AS a given class.
// Identity (dynamic_cast), never the guest-visible Type byte.
template<typename T = KernelObject>
inline T* TryQueryKernelObject(XDISPATCHER_HEADER& header)
{
    std::lock_guard guard{ g_kernelLock };
    const uint32_t hdrAddr = mcla::kernel::g_memory.MapVirtual(&header);
    auto it = WrapperIdentityMap().find(hdrAddr);
    if (it == WrapperIdentityMap().end())
        return nullptr;
    // dynamic_cast, NOT static_cast: the stored wrapper's class is decided
    // once, at creation, and must never be type-confused by a caller that
    // asks for a different class (audit C20: the release path cast an Event
    // to Semaphore* and wrote a semaphore count over the event's state).
    return dynamic_cast<T*>(it->second.obj);
}

template<typename T = KernelObject>
inline T* QueryKernelObject(XDISPATCHER_HEADER& header)
{
    std::lock_guard guard{ g_kernelLock };
    const uint32_t hdrAddr = mcla::kernel::g_memory.MapVirtual(&header);

    auto it = WrapperIdentityMap().find(hdrAddr);
    if (it != WrapperIdentityMap().end())
    {
        // The canonical wrapper for this dispatcher address. Resolve by
        // IDENTITY: the guest-visible Type byte cannot choose the object.
        if (auto* typed = dynamic_cast<T*>(it->second.obj))
            return typed;

        // CLASS MISMATCH: this address already owns a wrapper of a different
        // class. NEVER replace it (that replacement is what orphaned the
        // parked waiters) and never type-confuse it. Mint an UNREGISTERED
        // view for this caller only; identityHdrAddr stays 0 so destroying
        // the view cannot erase the canonical entry.
        static std::atomic<uint32_t> s_classFlips{0};
        const uint32_t n = s_classFlips.fetch_add(1) + 1;
        if (n <= 20 || (n % 500) == 0)
            spdlog::warn("KOBJ-CLASSFLIP #{0} hdr={1:08X} want={2} have={3} - "
                         "unregistered view minted; the canonical wrapper is kept",
                         n, hdrAddr, sizeof(T), it->second.type);

        auto* obj = CreateKernelObject<T>(reinterpret_cast<typename T::guest_type*>(&header));
        obj->identityHdrAddr = 0;
        header.WaitListHead.Flink = OBJECT_SIGNATURE;
        header.WaitListHead.Blink = mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(obj);
        return obj;
    }

    auto* obj = CreateKernelObject<T>(reinterpret_cast<typename T::guest_type*>(&header));
    obj->identityHdrAddr = hdrAddr;
    WrapperIdentityMap()[hdrAddr] = {obj, header.Type};

    // Keep the legacy guest-visible markers in sync for code paths (guest-side
    // thunks validate Flink == 'XBOX' before touching the object).
    header.WaitListHead.Flink = OBJECT_SIGNATURE;
    header.WaitListHead.Blink = mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(obj);

    return obj;
}

// TLS functions
uint32_t KeTlsAlloc();
uint32_t KeTlsFree(uint32_t dwTlsIndex);
uint32_t KeTlsGetValue(uint32_t dwTlsIndex);
uint32_t KeTlsSetValue(uint32_t dwTlsIndex, uint32_t lpTlsValue);