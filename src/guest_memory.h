#pragma once

#include <cstdint>
#include <cstddef>

namespace mcla::native {

class GuestMemoryView {
public:
    GuestMemoryView();

    void SetMemoryBase(uint8_t* base, uint64_t size);

    uint8_t* GetMemoryBase() const { return m_base; }
    uint64_t GetMemorySize() const { return m_size; }

    bool IsValidRange(uint32_t guestAddr, uint32_t size) const;

    const uint8_t* GetHostPtr(uint32_t guestAddr, uint32_t size) const;
    uint8_t* GetHostPtrMutable(uint32_t guestAddr, uint32_t size) const;

    bool ReadU8(uint32_t guestAddr, uint8_t* outVal) const;
    bool ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const;
    bool ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const;
    bool ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const;
    bool ReadF32BE(uint32_t guestAddr, float* outVal) const;
    bool ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const;

    bool WriteU8(uint32_t guestAddr, uint8_t val) const;
    bool WriteU16BE(uint32_t guestAddr, uint16_t val) const;
    bool WriteU32BE(uint32_t guestAddr, uint32_t val) const;
    bool WriteU64BE(uint32_t guestAddr, uint64_t val) const;
    bool WriteBytes(uint32_t guestAddr, const void* src, uint32_t size) const;

private:
    uint8_t* m_base = nullptr;
    uint64_t m_size = 0;

    // Xenos VA segments 0x8 (cached), 0xA (uncached), 0xC (extended) all
    // alias the same physical RAM (phys = va & 0x1FFFFFFF, xenia memory.cc).
    // The guest heap lives at identity host offsets in the 0x8 segment, so
    // A/C accesses converge onto their 0x8-segment slot to keep every alias
    // viewing the same bytes. 0x8 and low addresses stay identity-mapped
    // (existing heap placement / boot seeds rely on it). Segments 0xE/0xF
    // stay identity too: 0xE hosts the physical arena (kernel heap.cpp), so
    // its raw-offset VAs round-trip; bounds are enforced by u64 end>m_size.
    static uint64_t TranslateHostOffset(uint32_t guestAddr) {
        const uint32_t seg = guestAddr >> 29;
        if (seg == 4 || seg == 5 || seg == 6)
            return 0x80000000ull | (guestAddr & 0x1FFFFFFFull);
        return guestAddr;
    }

    uint16_t Swap16(uint16_t val) const { return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF); }
    uint32_t Swap32(uint32_t val) const { return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF); }
    uint64_t Swap64(uint64_t val) const {
        return ((val & 0xFFULL) << 56) | ((val & 0xFF00ULL) << 40) | ((val & 0xFF0000ULL) << 24) | ((val & 0xFF000000ULL) << 8) |
               ((val >> 8) & 0xFF000000ULL) | ((val >> 24) & 0xFF0000ULL) | ((val >> 40) & 0xFF00ULL) | ((val >> 56) & 0xFFULL);
    }
};

bool VerifyGuestMemoryViewForTests();

// Active memory view used by the PPC ABI load/store macros. The recompiled
// guest TUs are compiled against a copy of ppc_context.h that cannot see the
// App instance, so the macros route through this process-global accessor.
GuestMemoryView& GetActiveGuestMemoryView();
void SetActiveGuestMemoryView(GuestMemoryView* view);

// GPU MMIO interception: guest stores/loads landing inside the XGPU register
// window are routed to these handlers instead of RAM. Installed once during
// boot patching by mcla::gpu::CpInstallMmioRouting.
using GpuMmioWriteFn = bool (*)(uint32_t guestAddr, uint32_t value);
using GpuMmioReadFn = bool (*)(uint32_t guestAddr, uint32_t* outValue);
void SetGpuMmioHandlers(GpuMmioWriteFn writeFn, GpuMmioReadFn readFn);
GpuMmioWriteFn GetGpuMmioWriteHandler();
GpuMmioReadFn GetGpuMmioReadHandler();

// Routed, checked, endian-explicit accessors for the PPC ABI macros.
inline uint8_t ReadGuestU8(uint32_t guestAddr) {
    uint8_t val = 0;
    GetActiveGuestMemoryView().ReadU8(guestAddr, &val);
    return val;
}
inline uint16_t ReadGuestU16(uint32_t guestAddr) {
    uint16_t val = 0;
    GetActiveGuestMemoryView().ReadU16BE(guestAddr, &val);
    return val;
}
inline uint32_t ReadGuestU32(uint32_t guestAddr) {
    uint32_t val = 0;
    GetActiveGuestMemoryView().ReadU32BE(guestAddr, &val);
    return val;
}
inline uint64_t ReadGuestU64(uint32_t guestAddr) {
    uint64_t val = 0;
    GetActiveGuestMemoryView().ReadU64BE(guestAddr, &val);
    return val;
}
inline void WriteGuestU8(uint32_t guestAddr, uint8_t val) {
    GetActiveGuestMemoryView().WriteU8(guestAddr, val);
}
inline void WriteGuestU16(uint32_t guestAddr, uint16_t val) {
    GetActiveGuestMemoryView().WriteU16BE(guestAddr, val);
}
inline void WriteGuestU32(uint32_t guestAddr, uint32_t val) {
    GetActiveGuestMemoryView().WriteU32BE(guestAddr, val);
}
inline void WriteGuestU64(uint32_t guestAddr, uint64_t val) {
    GetActiveGuestMemoryView().WriteU64BE(guestAddr, val);
}

// Query the guest timebase (replaces the legacy timebase hook)
// Returns a 64-bit tick count suitable for the Xbox 360 timebase register.
// Uses high-resolution performance counter scaled to ~800 MHz (Xenon timebase frequency).
uint64_t QueryGuestTimebase();

} // namespace mcla::native