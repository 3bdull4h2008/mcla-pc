#include "guest_memory.h"

#include <cstring>
#include <rex/logging.h>
#include <rex/memory/utils.h>
#include <rex/runtime.h>
#include <rex/system/xmemory.h>
#include <rex/types.h>

namespace mcla::native {

GuestMemoryView::GuestMemoryView() = default;

void GuestMemoryView::SetMemory(rex::memory::Memory* memory) {
    m_memory = memory;
}

rex::memory::Memory* GuestMemoryView::ResolveMemory() const {
    if (m_memory) return m_memory;
    auto* runtime = rex::Runtime::instance();
    if (!runtime) return nullptr;
    const_cast<GuestMemoryView*>(this)->m_memory = runtime->memory();
    return m_memory;
}

bool GuestMemoryView::IsValidRange(uint32_t guestAddr, uint32_t size) const {
    if (guestAddr == 0 || size == 0) return false;

    // Reject 32-bit wrap-around / out-of-32-bit-space ranges.
    const uint64_t end = static_cast<uint64_t>(guestAddr) + size;
    if (end > 0x100000000ULL) return false;

    rex::memory::Memory* memory = ResolveMemory();
    if (!memory) return false;

    // The whole range must live inside a single mapped guest heap.
    rex::memory::BaseHeap* heap = memory->LookupHeap(guestAddr);
    if (!heap) return false;

    const uint32_t heapBase = heap->heap_base();
    const uint32_t heapSize = heap->heap_size();
    if (guestAddr < heapBase) return false;
    if (end - heapBase > heapSize) return false;

    // Require the full range to be readable (reserved/committed with read).
    const auto access = heap->QueryRangeAccess(guestAddr, static_cast<uint32_t>(end) - 1);
    constexpr uint32_t kRead = static_cast<uint32_t>(rex::memory::PageAccess::kReadOnly);
    if ((static_cast<uint32_t>(access) & kRead) == 0) return false;

    return true;
}

const uint8_t* GuestMemoryView::GetHostPtr(uint32_t guestAddr, uint32_t size) const {
    if (!IsValidRange(guestAddr, size)) return nullptr;

    rex::memory::Memory* memory = ResolveMemory();
    rex::memory::BaseHeap* heap = memory->LookupHeap(guestAddr);
    return heap->TranslateRelative<uint8_t*>(guestAddr - heap->heap_base());
}

uint8_t* GuestMemoryView::GetHostPtrMutable(uint32_t guestAddr, uint32_t size) const {
    if (!IsValidRange(guestAddr, size)) return nullptr;

    rex::memory::Memory* memory = ResolveMemory();
    rex::memory::BaseHeap* heap = memory->LookupHeap(guestAddr);
    return heap->TranslateRelative<uint8_t*>(guestAddr - heap->heap_base());
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
    *outVal = rex::byte_swap(val);
    return true;
}

bool GuestMemoryView::ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint32_t));
    if (!ptr || !outVal) return false;
    uint32_t val;
    std::memcpy(&val, ptr, sizeof(val));
    *outVal = rex::byte_swap(val);
    return true;
}

bool GuestMemoryView::ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(uint64_t));
    if (!ptr || !outVal) return false;
    uint64_t val;
    std::memcpy(&val, ptr, sizeof(val));
    *outVal = rex::byte_swap(val);
    return true;
}

bool GuestMemoryView::ReadF32BE(uint32_t guestAddr, float* outVal) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, sizeof(float));
    if (!ptr || !outVal) return false;
    uint32_t val;
    std::memcpy(&val, ptr, sizeof(val));
    uint32_t swapped = rex::byte_swap(val);
    std::memcpy(outVal, &swapped, sizeof(float));
    return true;
}

bool GuestMemoryView::ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const {
    const uint8_t* ptr = GetHostPtr(guestAddr, size);
    if (!ptr || !outBuffer) return false;
    std::memcpy(outBuffer, ptr, size);
    return true;
}



bool VerifyGuestMemoryViewForTests() {
    GuestMemoryView view;

    // Memory-independent rejections must always hold, regardless of whether a
    // live memory system is available at test time.
    if (view.IsValidRange(0, 1)) { return false; }               // zero address
    if (view.IsValidRange(0x1000, 0)) { return false; }          // zero size
    if (view.IsValidRange(0x20000000, 0xF0000000)) { return false; }  // wraps 32-bit
    if (view.GetHostPtr(0x12345678, 0)) { return false; }        // zero size -> null
    if (view.ReadU32BE(0, nullptr)) { return false; }            // null out param

    // Every checked read against a rejected range must fail cleanly.
    uint32_t scratch = 0;
    if (view.ReadU32BE(0, &scratch)) { return false; }

    return true;
}

} // namespace mcla::native
