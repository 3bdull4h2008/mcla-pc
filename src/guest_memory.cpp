#include "guest_memory.h"
#include "logging.h"
#include <cstring>

namespace mcla::native {

GuestMemoryView::GuestMemoryView() = default;

void GuestMemoryView::SetMemoryBase(uint8_t* base, uint64_t size) {
    m_base = base;
    m_size = size;
    MCLA_LOG_INFO("GuestMemoryView: memory base=0x{:p} size=0x{:X} ({} MB)",
                (void*)base, size, size / (1024 * 1024));
}

bool GuestMemoryView::IsValidRange(uint32_t guestAddr, uint32_t size) const {
    // Reject the NOACCESS guard page (first 4 KiB) so zero-base reads
    // (e.g. uninitialized r2/TOC) log as invalid instead of AV-ing.
    if (guestAddr < 0x1000 || size == 0) return false;

    const uint64_t end = static_cast<uint64_t>(guestAddr) + size;
    if (end > 0x100000000ULL) return false;

    if (!m_base) return false;
    if (guestAddr >= m_size) return false;
    if (end > m_size) return false;

    return true;
}

const uint8_t* GuestMemoryView::GetHostPtr(uint32_t guestAddr, uint32_t size) const {
    if (!IsValidRange(guestAddr, size)) return nullptr;
    return m_base + guestAddr;
}

uint8_t* GuestMemoryView::GetHostPtrMutable(uint32_t guestAddr, uint32_t size) const {
    if (!IsValidRange(guestAddr, size)) return nullptr;
    return m_base + guestAddr;
}

bool GuestMemoryView::ReadU8(uint32_t guestAddr, uint8_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint8_t));
    if (!ptr || !outVal) return false;
    *outVal = *ptr;
    return true;
}

bool GuestMemoryView::ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint16_t));
    if (!ptr || !outVal) return false;
    uint16_t val;
    std::memcpy(&val, ptr, sizeof(val));
    *outVal = Swap16(val);
    return true;
}

bool GuestMemoryView::ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint32_t));
    if (!ptr || !outVal) return false;
    uint32_t val;
    std::memcpy(&val, ptr, sizeof(val));
    *outVal = Swap32(val);
    return true;
}

bool GuestMemoryView::ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint64_t));
    if (!ptr || !outVal) return false;
    uint64_t val;
    std::memcpy(&val, ptr, sizeof(val));
    *outVal = Swap64(val);
    return true;
}

bool GuestMemoryView::ReadF32BE(uint32_t guestAddr, float* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(float));
    if (!ptr || !outVal) return false;
    uint32_t val;
    std::memcpy(&val, ptr, sizeof(val));
    uint32_t swapped = Swap32(val);
    std::memcpy(outVal, &swapped, sizeof(float));
    return true;
}

bool GuestMemoryView::ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, size);
    if (!ptr || !outBuffer) return false;
    std::memcpy(outBuffer, ptr, size);
    return true;
}

bool GuestMemoryView::WriteU8(uint32_t guestAddr, uint8_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint8_t));
    if (!ptr) return false;
    *ptr = val;
    return true;
}

bool GuestMemoryView::WriteU16BE(uint32_t guestAddr, uint16_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint16_t));
    if (!ptr) return false;
    uint16_t be = Swap16(val);
    std::memcpy(ptr, &be, sizeof(be));
    return true;
}

bool GuestMemoryView::WriteU32BE(uint32_t guestAddr, uint32_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint32_t));
    if (!ptr) return false;
    uint32_t be = Swap32(val);
    std::memcpy(ptr, &be, sizeof(be));
    return true;
}

bool GuestMemoryView::WriteU64BE(uint32_t guestAddr, uint64_t val) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, sizeof(uint64_t));
    if (!ptr) return false;
    uint64_t be = Swap64(val);
    std::memcpy(ptr, &be, sizeof(be));
    return true;
}

bool GuestMemoryView::WriteBytes(uint32_t guestAddr, const void* src, uint32_t size) const {
    uint8_t* ptr = GetHostPtrMutable(guestAddr, size);
    if (!ptr || !src) return false;
    std::memcpy(ptr, src, size);
    return true;
}

namespace {
mcla::native::GuestMemoryView* g_activeGuestMemoryView = nullptr;
}

mcla::native::GuestMemoryView& GetActiveGuestMemoryView() {
    static mcla::native::GuestMemoryView fallback;
    return g_activeGuestMemoryView ? *g_activeGuestMemoryView : fallback;
}

void SetActiveGuestMemoryView(mcla::native::GuestMemoryView* view) {
    g_activeGuestMemoryView = view;
}

bool VerifyGuestMemoryViewForTests() {
    GuestMemoryView view;

    uint8_t testMem[1024] = {0};
    view.SetMemoryBase(testMem, sizeof(testMem));

    if (view.IsValidRange(0, 1)) return false;
    if (view.IsValidRange(0x1000, 0)) return false;
    if (view.IsValidRange(0x20000000, 0xF0000000)) return false;
    if (view.GetHostPtr(0x12345678, 0)) return false;
    if (view.ReadU32BE(0, nullptr)) return false;

    uint32_t scratch = 0;
    if (view.ReadU32BE(0, &scratch)) return false;

    // Test valid reads
    testMem[0x100] = 0x12;
    testMem[0x101] = 0x34;
    testMem[0x102] = 0x56;
    testMem[0x103] = 0x78;

    uint32_t val32 = 0;
    if (!view.ReadU32BE(0x100, &val32)) return false;
    if (val32 != 0x12345678) return false;

    uint16_t val16 = 0;
    if (!view.ReadU16BE(0x100, &val16)) return false;
    if (val16 != 0x1234) return false;

    if (!view.WriteU16BE(0x200, 0xAABB)) return false;
    if (testMem[0x200] != 0xAA || testMem[0x201] != 0xBB) return false;

    return true;
}

uint64_t QueryGuestTimebase() {
    LARGE_INTEGER freq;
    LARGE_INTEGER counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    // Scale to ~800 MHz (Xenon timebase = CPU/4, 3.2 GHz / 4 = 800 MHz)
    // freq is in Hz, so multiply by 800e6 / freq.QuadPart
    return (counter.QuadPart * 800000000ULL) / freq.QuadPart;
}

} // namespace mcla::native