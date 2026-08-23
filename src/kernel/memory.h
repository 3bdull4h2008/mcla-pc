#pragma once

#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <windows.h>
#include "xbox.h"

namespace mcla::kernel {

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
        if (offset) {
            assert(offset < size);
        }
        return base + offset;
    }

    uint32_t MapVirtual(const void* host) const noexcept {
        if (host) {
            assert(IsInMemoryRange(host));
        }
        return static_cast<uint32_t>(static_cast<const uint8_t*>(host) - base);
    }

    PPCFunc* FindFunction(uint32_t guest) const noexcept {
        return PPC_LOOKUP_FUNC(base, guest);
    }

    void InsertFunction(uint32_t guest, PPCFunc* host) {
        PPC_LOOKUP_FUNC(base, guest) = host;
    }
};

extern "C" void* MmGetHostAddress(uint32_t ptr);
extern Memory g_memory;

} // namespace mcla::kernel