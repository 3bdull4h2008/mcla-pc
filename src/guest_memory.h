#pragma once

#include <cstdint>
#include <cstddef>

namespace mcla::native {

class GuestMemoryView {
public:
    GuestMemoryView();

    void SetMemoryBase(uint8_t* base, uint32_t size);

    uint8_t* GetMemoryBase() const { return m_base; }
    uint32_t GetMemorySize() const { return m_size; }

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
    bool WriteU32BE(uint32_t guestAddr, uint32_t val) const;
    bool WriteU64BE(uint32_t guestAddr, uint64_t val) const;
    bool WriteBytes(uint32_t guestAddr, const void* src, uint32_t size) const;

private:
    uint8_t* m_base = nullptr;
    uint32_t m_size = 0;

    uint16_t Swap16(uint16_t val) const { return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF); }
    uint32_t Swap32(uint32_t val) const { return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF); }
    uint64_t Swap64(uint64_t val) const {
        return ((val & 0xFFULL) << 56) | ((val & 0xFF00ULL) << 40) | ((val & 0xFF0000ULL) << 24) | ((val & 0xFF000000ULL) << 8) |
               ((val >> 8) & 0xFF000000ULL) | ((val >> 24) & 0xFF0000ULL) | ((val >> 40) & 0xFF00ULL) | ((val >> 56) & 0xFFULL);
    }
};

bool VerifyGuestMemoryViewForTests();

} // namespace mcla::native