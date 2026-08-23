#include "gpu_cp.h"

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "guest_memory.h"
#include "logging.h"
#include "kernel/memory.h"

#include <atomic>

namespace mcla::gpu {

namespace {

// XGPU register window (Xenia: GraphicsSystem::Initialize maps phys
// 0x7FC80000..0x7FC8FFFF, register index = offset/4).
constexpr uint32_t kMmioBase = 0x7FC80000u;
constexpr uint32_t kMmioSize = 0x00010000u;
constexpr uint32_t kMmioMask = 0xFFFF0000u;

// CP_RB_WPTR: the ring doorbell. Guest stores the new write-pointer dword
// index here (verified guest site: ppc_recomp.77.cpp store to base+1812).
constexpr uint32_t kWptrByteOffset = 0x01C5u * 4u; // 0x714

// Xenia treats this value as "no doorbell rung yet".
constexpr uint32_t kWptrSentinel = 0xBAADF00Du;

// Type-3 opcodes we give special treatment (values per xenia gpu/xenos.h).
constexpr uint32_t kPm4XeSwap = 0x64; // Xenia-invented swap packet

std::atomic<uint32_t> g_ringBase{0};        // guest phys addr of primary ring
std::atomic<uint32_t> g_ringCapDwords{0};   // ring size in dwords
std::atomic<uint32_t> g_rptrIndex{0};       // read pointer, dword index
std::atomic<uint32_t> g_writebackAddr{0};   // where rptr is published (BE)
std::atomic<uint32_t> g_driverDevCtx{0};    // GuestDevice VA (see CpAttachDriverCtx)

std::atomic<uint64_t> g_drainCount{0};
std::atomic<uint64_t> g_swapCount{0};
std::atomic<uint64_t> g_doorbellCount{0};

uint32_t ReadRingU32(uint32_t dwordIndex)
{
    const uint32_t addr = g_ringBase.load(std::memory_order_relaxed) + dwordIndex * 4u;
    uint32_t v = 0;
    (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(addr, &v);
    return v;
}

void PublishRptr()
{
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t rptr = g_rptrIndex.load(std::memory_order_relaxed);
    const uint32_t wb = g_writebackAddr.load(std::memory_order_relaxed);
    if (wb != 0)
    {
        (void)mem.WriteU32BE(wb, rptr);
    }
    // Keep the driver's local ring-context mirrors in sync: guest waiters
    // poll ctx[+0] (sub_82411E94 free-space), [+4] (barriers), and the
    // write-back word at phys(ctx[+10896]->+60) (sub_82411218). On HW the
    // write-back + interrupt handler maintain these; we own both roles.
    const uint32_t dev = g_driverDevCtx.load(std::memory_order_relaxed);
    if (dev != 0)
    {
        uint32_t subctx = 0;
        if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
        {
            (void)mem.WriteU32BE(subctx + 0, rptr);
            (void)mem.WriteU32BE(subctx + 4, rptr);
        }
    }
}

// Throttled unknown-opcode logger.
void LogUnknownOpcode(uint32_t opcode, uint32_t count)
{
    static std::atomic<uint32_t> seenMask{0};
    const uint32_t bit = opcode < 32 ? (1u << opcode) : 0;
    if (bit && (seenMask.fetch_or(bit) & bit))
    {
        return; // already reported this opcode once
    }
    MCLA_LOG_WARN("CP: skipping TYPE3 opcode=0x{:02X} count={} (unimplemented)", opcode, count);
}

// Drain packets from rptr up to wptr (both dword indices mod capacity).
// Synchronous on the guest submitter thread - no other thread touches the
// ring indices, so plain atomics are sufficient.
void DrainRing(uint32_t wptr)
{
    const uint32_t cap = g_ringCapDwords.load(std::memory_order_relaxed);
    if (cap == 0 || wptr >= cap)
    {
        static std::atomic<bool> warnedBadWptr{false};
        if (!warnedBadWptr.exchange(true))
        {
            MCLA_LOG_WARN("CP: doorbell wptr={:08X} rejected (cap={})", wptr, cap);
        }
        return;
    }

    uint32_t rptr = g_rptrIndex.load(std::memory_order_relaxed);
    uint32_t guard = cap * 2u + 16u; // hard stop against runaway streams

    while (rptr != wptr && guard--)
    {
        const uint32_t header = ReadRingU32(rptr);
        const uint32_t type = header >> 30;

        if (type == 2)
        {
            // TYPE-2 filler NOP (0x80000000).
            rptr = (rptr + 1u) % cap;
            continue;
        }

        if (type == 3)
        {
            const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
            const uint32_t opcode = (header >> 8) & 0x7Fu;

            if (opcode == kPm4XeSwap && count >= 4)
            {
                // Payload: [0]="SWAP" fourcc, [1]=frontbuffer phys,
                // [2]=width, [3]=height (xenia xboxkrnl_video.cc VdSwap).
                const uint32_t magic = ReadRingU32((rptr + 1u) % cap);
                const uint32_t fb = ReadRingU32((rptr + 2u) % cap);
                const uint32_t width = ReadRingU32((rptr + 3u) % cap);
                const uint32_t height = ReadRingU32((rptr + 4u) % cap);
                const uint64_t n = g_swapCount.fetch_add(1) + 1;
                if (n <= 10 || (n % 300) == 0)
                {
                    MCLA_LOG_INFO("CP: XE_SWAP #{} magic={:08X} fb={:08X} {}x{}", n, magic, fb, width, height);
                }
            }
            else
            {
                LogUnknownOpcode(opcode, count);
            }

            rptr = (rptr + count + 1u) % cap;
            continue;
        }

        if (type == 0)
        {
            // TYPE-0: write `count` consecutive registers from a base index.
            const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
            static std::atomic<uint32_t> type0Seen{0};
            if (type0Seen.fetch_add(1) < 8)
            {
                MCLA_LOG_INFO("CP: TYPE0 base={:03X} count={}", header & 0x3FFFu, count);
            }
            rptr = (rptr + count + 1u) % cap;
            continue;
        }

        // TYPE-1 or garbage: refusing to guess - drop to wptr so the
        // submitter unsticks, and say so loudly exactly once.
        static std::atomic<bool> warnedDesync{false};
        if (!warnedDesync.exchange(true))
        {
            MCLA_LOG_ERROR("CP: desync at rptr={} header={:08X} - dropping to wptr {:04X}",
                           rptr, header, wptr);
        }
        rptr = wptr;
        break;
    }

    g_rptrIndex.store(rptr, std::memory_order_relaxed);
    PublishRptr();
    g_drainCount.fetch_add(1);
}

} // namespace

void CpInitializeRingBuffer(uint32_t physAddr, uint32_t sizeLog2)
{
    const uint32_t sizeBytes = 1u << (sizeLog2 + 3); // log2 of quadwords
    g_ringBase.store(physAddr, std::memory_order_relaxed);
    g_ringCapDwords.store(sizeBytes >> 2, std::memory_order_relaxed);
    g_rptrIndex.store(0, std::memory_order_relaxed);
    MCLA_LOG_INFO("CP: ring base={:08X} cap={} dwords", physAddr, sizeBytes >> 2);
}

void CpEnableRPtrWriteBack(uint32_t rptrWritebackAddr, uint32_t blockSizeLog2)
{
    g_writebackAddr.store(rptrWritebackAddr, std::memory_order_relaxed);
    (void)blockSizeLog2; // update frequency - not honored yet (matches xenia TODO)
    if (rptrWritebackAddr)
    {
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(rptrWritebackAddr, 0);
    }
    MCLA_LOG_INFO("CP: rptr writeback @ {:08X}", rptrWritebackAddr);
}

void CpAttachDriverCtx(uint32_t devVA)
{
    g_driverDevCtx.store(devVA, std::memory_order_relaxed);
}

bool CpMmioWrite(uint32_t guestAddr, uint32_t value)
{
    if ((guestAddr & kMmioMask) != kMmioBase)
    {
        return false;
    }

    const uint32_t offset = guestAddr - kMmioBase;
    if (offset == kWptrByteOffset)
    {
        // Log every doorbell including the sentinel: a silent sentinel store
        // vs a missing store are different failure modes.
        const uint64_t n = g_doorbellCount.fetch_add(1) + 1;
        if (n <= 16 || (n % 500) == 0)
        {
            MCLA_LOG_INFO("CP: doorbell wptr={:08X} (rptr={})", value,
                          g_rptrIndex.load(std::memory_order_relaxed));
        }
        if (value != kWptrSentinel)
        {
            DrainRing(value);
        }
        return true;
    }

    // Other registers the driver pokes (observed in generated code:
    // reg 0x1844 kick, reg 0x0C94 = 7). Log first touches only.
    static std::atomic<uint32_t> regSeenMask{0};
    const uint32_t regIndex = offset >> 2;
    const uint32_t bit = regIndex < 32 ? (1u << regIndex) : 0;
    if (!bit || !(regSeenMask.fetch_or(bit) & bit))
    {
        MCLA_LOG_INFO("CP: MMIO write reg={:04X} offset={:04X} value={:08X}", regIndex, offset, value);
    }
    return true;
}

bool CpMmioRead(uint32_t guestAddr, uint32_t* outValue)
{
    if ((guestAddr & kMmioMask) != kMmioBase)
    {
        return false;
    }
    static std::atomic<bool> warnedRead{false};
    if (!warnedRead.exchange(true))
    {
        MCLA_LOG_WARN("CP: MMIO read @ {:08X} returning 0 (status registers unimplemented)",
                      guestAddr);
    }
    *outValue = 0;
    return true;
}

uint64_t CpSwapCount() { return g_swapCount.load(std::memory_order_relaxed); }
uint64_t CpDrainCount() { return g_drainCount.load(std::memory_order_relaxed); }

void CpInstallMmioRouting()
{
    mcla::native::SetGpuMmioHandlers(&CpMmioWrite, &CpMmioRead);
    MCLA_LOG_INFO("CP: MMIO routing installed (XGPU window 0x7FC80000)");
}

} // namespace mcla::gpu
