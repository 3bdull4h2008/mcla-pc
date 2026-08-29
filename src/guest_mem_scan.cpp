#include <stdafx.h>
#include "logging.h"
#include "kernel/memory.h"
#include <atomic>

namespace mcla {
namespace native {
namespace kernel {

void ScanGuestMemoryForTU83SpawnPointers()
{
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    constexpr uint32_t targets[] = {
        0x8213178C,
        0x821BD8C0,
        0x824569C8,
        0x823F69C8
    };

    constexpr uint32_t scanStart = 0x82000000;
    constexpr uint32_t scanEnd   = 0x83000000;
    constexpr uint32_t step = 4;

    MCLA_LOG_INFO("=== TU83 Spawn Pointer Scan START ===");
    MCLA_LOG_INFO("Scanning guest memory 0x{:08X} - 0x{:08X} for {} target addresses",
                  scanStart, scanEnd, sizeof(targets)/sizeof(targets[0]));

    uint32_t hits = 0;
    for (uint32_t addr = scanStart; addr < scanEnd; addr += step)
    {
        uint32_t val = 0;
        if (!mem.ReadU32BE(addr, &val))
            continue;

        for (uint32_t target : targets)
        {
            if (val == target)
            {
                hits++;
                MCLA_LOG_WARN("HIT: 0x{:08X} -> 0x{:08X} (target {}.{})",
                              addr, val,
                              (&target - targets) + 1,
                              (target == 0x8213178C ? "sub_8213178C" :
                               target == 0x821BD8C0 ? "sub_821BD8C0" :
                               target == 0x824569C8 ? "sub_824569C8" : "sub_823F69C8"));

                uint32_t ctx[9] = {0};
                for (int i = -4; i <= 4; i++)
                {
                    uint32_t cval = 0;
                    if (mem.ReadU32BE(addr + i * 4, &cval))
                        ctx[i + 4] = cval;
                }
                MCLA_LOG_INFO("  Context: [{:08X}] {:08X} {:08X} {:08X} {:08X} >{:08X}< {:08X} {:08X} {:08X} {:08X}",
                              addr - 16,
                              ctx[0], ctx[1], ctx[2], ctx[3], ctx[4], ctx[5], ctx[6], ctx[7], ctx[8]);
            }
        }

        if ((addr & 0xFFFFF) == 0)
        {
            MCLA_LOG_INFO("  Progress: 0x{:08X} ({:.1f}%)", addr, 100.0 * (addr - scanStart) / (scanEnd - scanStart));
        }
    }

    MCLA_LOG_INFO("=== TU83 Spawn Pointer Scan END: {} hits ===", hits);
}

} // namespace kernel
} // namespace native
} // namespace mcla