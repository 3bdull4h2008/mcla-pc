#pragma once

#include <cstdint>

namespace rex::memory {
class Memory;
}

namespace mcla::native {

// Endian-aware, checked view over Xbox 360 guest memory address space.
//
// Validation is performed against the live ReXGlue memory heaps rather than a
// raw base pointer. Every read is range-checked against the mapped guest image
// and translated through the heap's host offset so heaps with a nonzero
// host_address_offset are handled correctly.
class GuestMemoryView {
public:
    GuestMemoryView();

    // Bind to a specific memory object. If null (or never called), the view
    // lazily resolves rex::Runtime::instance()->memory().
    void SetMemory(rex::memory::Memory* memory);
    rex::memory::Memory* GetMemory() const { return m_memory; }

    // Check if the guest address range [guestAddr, guestAddr + size) is safe
    // to read: nonzero, no 32-bit wrap, and fully inside one mapped guest heap.
    bool IsValidRange(uint32_t guestAddr, uint32_t size) const;

    // Checked pointer accessor. Returns nullptr if the range is invalid.
    const uint8_t* GetHostPtr(uint32_t guestAddr, uint32_t size) const;
    uint8_t* GetHostPtrMutable(uint32_t guestAddr, uint32_t size) const;

// Endian-safe checked reads. Return false if guestAddr range is invalid.
    bool ReadU8(uint32_t guestAddr, uint8_t* outVal) const;
    bool ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const;
    bool ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const;
    bool ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const;
    bool ReadF32BE(uint32_t guestAddr, float* outVal) const;
    bool ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const;

private:
    rex::memory::Memory* ResolveMemory() const;

    rex::memory::Memory* m_memory = nullptr;
};

// Unit self-test for the checked range logic. Safe to call before the
// memory system is fully initialized; it exercises the memory-independent
// rejection paths plus the lazy-resolution path.
bool VerifyGuestMemoryViewForTests();

} // namespace mcla::native

