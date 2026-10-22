#pragma once

#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <mutex>
#include <vector>
#include <windows.h>
#include "xbox.h"

namespace mcla::kernel {

// F-782: the first `kNullGuardBytes` of the guest window are deliberately inaccessible, so a guest
// null dereference faults instead of silently reading real memory. This was a bare `4096` literal
// in eight places across four sites in memory.cpp, so nothing in the tree could be grepped for
// "who must respect the guard" -- and a raw `base + pos` sweep in heap.cpp did not respect it,
// which cost one access violation per boot and left `PHYS-LIVE` at 0 rows in all 313 logs on disk.
// Any code that reads the window by pointer arithmetic rather than through `Translate`/`IsValid`
// must start at this offset.
constexpr uint64_t kNullGuardBytes = 4096u;

// Guest memory heap: 4 GB VirtualAlloc at fixed base 0x100000000
// Provides MapVirtual/Translate for guest↔host pointer translation

class GuestMemoryHeap {
public:
    static constexpr uint64_t kBaseAddress = 0x100000000ULL;
    static constexpr uint64_t kSize = 0x100000000ULL; // 4 GB

    GuestMemoryHeap() = default;
    ~GuestMemoryHeap();

    // Non-copyable, non-movable
    GuestMemoryHeap(const GuestMemoryHeap&) = delete;
    GuestMemoryHeap& operator=(const GuestMemoryHeap&) = delete;

    // Initialize with fresh VirtualAlloc
    bool Initialize();

    // Adopt an externally-allocated guest window (the boot host's 4 GiB
    // VirtualAlloc) instead of allocating a second one. Ownership stays with
    // the caller; Shutdown() will not release adopted memory.
    bool Adopt(uint8_t* base, uint64_t size);

    void Shutdown();

    // Guest address -> host pointer (checked, bounds-checked)
    void* Translate(uint32_t guestAddr);
    const void* Translate(uint32_t guestAddr) const;

    // Host pointer -> guest address (for return values)
    uint32_t MapVirtual(const void* hostPtr) const;

    // Check if guest address is valid
    bool IsValid(uint32_t guestAddr, size_t size = 1) const;

    // Direct base access
    uint8_t* Base() { return m_base; }
    const uint8_t* Base() const { return m_base; }
    uint64_t Size() const { return m_size; }

    // Allocate/free within guest heap (for kernel objects, etc.)
    uint32_t Alloc(size_t size, size_t alignment = 16);
    void Free(uint32_t guestAddr, size_t size);

    // --- Guest-virtual region tracking (NtAllocateVirtualMemory honesty) ---
    // Xbox 360 semantics (Xenia reference): the guest-virtual window
    // [0x40000000, 0x80000000) uses 64 KB pages and is carved exclusively by
    // NtAllocateVirtualMemory/NtFreeVirtualMemory. The flat guest window maps
    // it identity-style; this tracker only records allocation STATE so that
    // explicit-base requests fail loudly instead of being rubber-stamped.
    static constexpr uint32_t kGuestVirtualBase = 0x40000000;
    static constexpr uint32_t kGuestVirtualEnd = 0x80000000;     // exclusive
    static constexpr uint32_t kGuestVirtualPageSize = 0x10000;   // 64 KB

    struct VirtualRegionInfo {
        uint32_t base = 0;
        uint32_t allocationBase = 0;
        uint32_t size = 0;
        bool committed = false;
        bool reserved = false; // false => FREE
    };

    // Region containing addr (FREE info if untracked but inside window).
    [[nodiscard]] bool QueryVirtualRegion(uint32_t addr, VirtualRegionInfo* out) const;

    // Fixed-base reservation. Fails if [base, base+size) overlaps a DIFFERENT
    // region or exits the window. commit over an existing reservation upgrades
    // it (whole-region granularity, matching our coarse bookkeeping).
    // *outWasCommitted = true when the range was already committed.
    [[nodiscard]] bool AllocVirtualFixed(uint32_t base, uint32_t size, bool commit, bool zeroFresh, bool* outWasCommitted);

    // Bottom-up (or top-down) search for a free gap of `size`; inserts region.
    [[nodiscard]] bool AllocVirtualAny(uint32_t size, bool topDown, bool commit, bool zeroFresh, uint32_t* outBase);

    // Mark the region containing [base, base+size) uncommitted. Returns the
    // containing region's full size via *outSize. False if no such region.
    [[nodiscard]] bool DecommitVirtual(uint32_t base, uint32_t size, uint32_t* outSize);

    // Remove the region whose ALLOCATION BASE == base. *outSize = its size.
    [[nodiscard]] bool ReleaseVirtual(uint32_t base, uint32_t* outSize);

    // Checked, endian-explicit read/write helpers
    [[nodiscard]] bool ReadU8(uint32_t guestAddr, uint8_t* outVal) const;
    [[nodiscard]] bool ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const;
    [[nodiscard]] bool ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const;
    [[nodiscard]] bool ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const;
    [[nodiscard]] bool ReadF32BE(uint32_t guestAddr, float* outVal) const;
    [[nodiscard]] bool ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const;

    [[nodiscard]] bool WriteU8(uint32_t guestAddr, uint8_t val);
    [[nodiscard]] bool WriteU16BE(uint32_t guestAddr, uint16_t val);
    [[nodiscard]] bool WriteU32BE(uint32_t guestAddr, uint32_t val);
    [[nodiscard]] bool WriteU64BE(uint32_t guestAddr, uint64_t val);
    [[nodiscard]] bool WriteBytes(uint32_t guestAddr, const void* src, uint32_t size);

    // Singleton access
    static GuestMemoryHeap& Instance();

private:
    uint8_t* m_base = nullptr;
    uint64_t m_size = 0;
    bool m_initialized = false;
    bool m_owned = false;

    struct VirtualRegion {
        uint32_t base;
        uint32_t size;
        bool committed;
    };
    mutable std::mutex m_virtualMutex;
    std::vector<VirtualRegion> m_virtualRegions; // sorted by base, disjoint

    static uint16_t Swap16(uint16_t val) { return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF); }
    static uint32_t Swap32(uint32_t val) { return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF); }
    static uint64_t Swap64(uint64_t val) {
        return ((val & 0xFFULL) << 56) | ((val & 0xFF00ULL) << 40) | ((val & 0xFF0000ULL) << 24) | ((val & 0xFF000000ULL) << 8) |
               ((val >> 8) & 0xFF000000ULL) | ((val >> 24) & 0xFF0000ULL) | ((val >> 40) & 0xFF00ULL) | ((val >> 56) & 0xFFULL);
    }
};

// Convenience inline functions for PPC ABI macros
inline void* TranslateGuest(uint32_t guestAddr) {
    return GuestMemoryHeap::Instance().Translate(guestAddr);
}

inline const void* TranslateGuestConst(uint32_t guestAddr) {
    return GuestMemoryHeap::Instance().Translate(guestAddr);
}

inline uint32_t MapVirtual(const void* hostPtr) {
    return GuestMemoryHeap::Instance().MapVirtual(hostPtr);
}

// Memory class for PPC_LOOKUP_FUNC
struct Memory {
    uint8_t* base = nullptr;
    uint64_t size = 0;

    Memory();

    bool IsInMemoryRange(const void* host) const noexcept {
        return host >= base && host < (base + size);
    }

    void* Translate(size_t offset) const noexcept {
        if (!base) return nullptr;
        if (offset) { assert(offset < size); }
        return base + offset;
    }

    uint32_t MapVirtual(const void* host) const noexcept {
        if (host) {
            assert(IsInMemoryRange(host));
        }
        return static_cast<uint32_t>(static_cast<const uint8_t*>(host) - base);
    }

    PPCFunc* FindFunction(uint32_t guest) const noexcept {
        // F-859 (2026-10-22): THE FUNCTION TABLE HAS AN INDEX RANGE, AND
        // LOOKING UP A GUEST ADDRESS OUTSIDE IT COMPUTES A HOST ADDRESS 2 GiB
        // BELOW THE GUEST WINDOW AND THEN DEREFERENCES IT.
        //
        // MEASURED (build/w873.log:2156038, the vblank/DPC thread):
        //   Vectored exception: code=0xC0000005 addr=0x0x7ff6e465181a
        //     rva=0x35181A ... thread=21712
        //   Param[1]=0x0x7e780000
        //   rip owner=host ..., not a mapped guest fn
        // and the host stack names `DispatchGuestDpcQueue+0x36A` ->
        // src/kernel/imports.cpp:6632 `FindFunction(w0)`, where `w0` is the
        // FIRST WORD of the guest's queued DPC object -- and it was 0.
        //
        // The arithmetic, from the macro itself (src/ppc_context.h:124):
        //   slot = base + PPC_IMAGE_BASE + PPC_IMAGE_SIZE
        //                + (uint64_t(uint32_t(guest) - PPC_CODE_BASE) * 2)
        // For guest == 0 the index underflows and the slot lands at
        //   base + 0x829E0000 - 0x104260000 = base - 0x7E780000
        // which with base = 0x100000000 is 0x7E780000 -- 2 GiB BELOW the
        // guest window, unmapped.  The tree already names this address: the
        // VEH classifies it as `wild=1` (src/boot_host.cpp:2891-2894) and
        // F-782 records the same 0x7E780000 "function-table index 0" family
        // from the GUEST side.
        //
        // THE BOUND is the recompiled code's own extent: the table is indexed
        // by guest VA from PPC_CODE_BASE, and every mapped row lies inside
        // [PPC_CODE_BASE, PPC_CODE_BASE + PPC_CODE_SIZE) (src/ppc_config.h:14-15;
        // the measured maximum mapped row is 0x827CCBC0 < 0x827CD054).  A
        // guest VA outside that range has NO table slot, so the answer is
        // null -- which is what the CALLER already handles:
        // src/kernel/imports.cpp:6639-6646 logs `DPC-UNRESOLVED` and drops
        // the entry, which is that code's own stated intent.
        //
        // WHAT THIS DOES NOT CHANGE (do-not #1/#9): no guest state is
        // written, no handle is fabricated, no dispatch is skipped, and the
        // guest's own ring-count write (src/kernel/imports.cpp:6614) still
        // happens.  It only stops the host from DERIVING an address outside
        // its own mapping.  It is placed HERE rather than at the one call
        // site because the same hazard exists at src/kernel/imports.cpp:6627
        // and at the other FindFunction callers, and `src/ppc_context.h` is
        // forbidden (rule 2) so the macro itself cannot be guarded.
        if (guest < PPC_CODE_BASE || guest >= PPC_CODE_BASE + PPC_CODE_SIZE) {
            return nullptr;
        }
        return PPC_LOOKUP_FUNC(base, guest);
    }

    void InsertFunction(uint32_t guest, PPCFunc* host) {
        PPC_LOOKUP_FUNC(base, guest) = host;
    }
};

extern "C" void* MmGetHostAddress(uint32_t ptr);
extern Memory g_memory;

// Session 73: true when `addr` falls inside any physical allocation handed
// out this boot (historical registry — frees are not erased). Used by the
// 0xCD-fill overrun census to flag writes into o1heap metadata space.
bool MclaPhysRangeEverAllocated(uint32_t addr);

// Highest tracked physical allocation base at or below `addr`. Lets the
// overrun census name the buffer a wild write ran past, and the gap to it.
bool MclaPhysNearestAllocBelow(uint32_t addr, uint32_t *outBase,
                               uint32_t *outSize);

// Resolve `addr` to its owning physical allocation (exact membership first,
// nearest-below fallback). Reports base, size, the guest LR that requested it,
// and whether the match was exact. Used by the blit-overrun census to name the
// site that under-allocated a destination buffer.
bool MclaPhysAllocInfo(uint32_t addr, uint32_t *outBase, uint32_t *outSize,
                       uint32_t *outLr, bool *outExact);

} // namespace mcla::kernel