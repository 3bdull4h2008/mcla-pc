// tools/validators/texture_import_stubs.cpp
//
// Link seams for building src/guest_memory.cpp into an offline validator.
// guest_memory.cpp calls these from its PAGE-WATCH hooks; gpu_cp.cpp owns the real
// implementations and drags in the whole PPC ABI header chain, which the validator
// does not need. The texture import path never touches a watched page, so these are
// inert by construction.
#include <cstdint>

namespace mcla::gpu {
void PageWatchOnWrite(uint32_t guestAddr, uint32_t value) {
    (void)guestAddr;
    (void)value;
}
void PageWatchOnRead(uint32_t guestAddr, uint32_t value) {
    (void)guestAddr;
    (void)value;
}
}  // namespace mcla::gpu
