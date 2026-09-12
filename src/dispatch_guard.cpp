// midasm hook for the game's dispatcher trampoline sub_8218CC70
// (lis r11 / lwzx handle / cmpwi -1 / beqlr / lwz base / add / lwz fn / mtctr / bctr).
//
// The recompiled bctr resolves through the function-pointer table that follows
// the guest image (PPC_LOOKUP_FUNC in ppc_context.h): an entry that is NULL or
// a garbage pointer is a direct call through a bad function pointer. A previous
// session guarded this by hand-editing generated/ppc_xenon/ppc_recomp.9.cpp,
// which every recompiler run silently dropped — this hook is the same checks,
// expressed so regens keep them.

#include "ppc_config.h"
#include "ppc_context.h"

#include "kernel/memory.h"

// Runs after `lwz r8,64(r9)` at 0x8218CC94. Returning true makes the generated
// code return from the guest function instead of reaching the bctr.
bool mcla_DispatchGuard_8218CC94(PPCRegister& r3, PPCRegister& r8) {
    // Target must be aligned, non-NULL and inside the recompiled code range.
    if ((r8.u32 & 3u) != 0 || r8.u32 == 0 ||
        r8.u32 < PPC_CODE_BASE || r8.u32 >= 0x83000000u) {
        return true;
    }
    // Base pointer must be heap or image data — reject GPU memory, NULL and
    // the dead patterns seen in crashes here (0xCABA..., 0xDEAD...).
    if (r3.u32 == 0 ||
        (r3.u32 >= 0x40000000u && r3.u32 < 0x50000000u) ||
        (r3.u32 & 0xFFF00000u) == 0xCAB00000u ||
        (r3.u32 & 0xFFF00000u) == 0xDEAD0000u) {
        return true;
    }
    // Mirror PPC_LOOKUP_FUNC: slot = image end + (target - code base) * 2.
    // If the slot holds no recompiled function pointer, the bctr would call
    // NULL.
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t slot =
        uint32_t(PPC_IMAGE_BASE + PPC_IMAGE_SIZE) + (r8.u32 - PPC_CODE_BASE) * 2u;
    if (!mem.IsValid(slot, sizeof(void*))) {
        return true;
    }
    return *reinterpret_cast<void* const*>(mem.Translate(slot)) == nullptr;
}
