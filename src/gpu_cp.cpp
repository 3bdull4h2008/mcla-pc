#include "gpu_cp.h"

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "guest_memory.h"
#include "logging.h"
#include "kernel/memory.h"
#include <cpu/ppc_context.h>

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

// Register-file shadow over the 64 KB MMIO window (xenia persists writes and
// serves unhandled reads from it, graphics_system.cc:207-223).
constexpr size_t kMmioRegCount = kMmioSize / 4u;
std::atomic<uint32_t> g_regShadow[kMmioRegCount]{};

// Type-3 opcodes we give special treatment (values per xenia gpu/xenos.h).
constexpr uint32_t kPm4XeSwap = 0x64; // Xenia-invented swap packet

std::atomic<uint32_t> g_ringBase{0};        // guest phys addr of primary ring
std::atomic<uint32_t> g_ringCapDwords{0};   // ring size in dwords
std::atomic<uint32_t> g_rptrIndex{0};       // read pointer, dword index
std::atomic<uint32_t> g_writebackAddr{0};   // where rptr is published (BE)
std::atomic<uint32_t> g_pushWatermark{0};   // consumed-through VA (driver space)
std::atomic<uint32_t> g_progressBlk{0};     // submitting thread's *(r13+256) block

// All GuestDevices seen driving the ring (create hook + reserver/waiter
// censuses attach). MCLA binds a SECOND GuestDevice (A0009100) of the same
// class at create (sub_82413588); waiters poll THEIR OWN dev[+10896] ctx, so
// mirror maintenance must cover every device, not just the last attacher.
constexpr size_t kMaxDevices = 4;
std::atomic<uint32_t> g_devices[kMaxDevices]{};
static std::atomic<uint32_t> s_attachedCount{0};

template <typename Fn>
void ForEachDevice(Fn&& fn)
{
    for (auto& slot : g_devices)
    {
        if (const uint32_t dev = slot.load(std::memory_order_relaxed); dev != 0)
        {
            fn(dev);
        }
    }
}

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
    // Keep every known driver's local ring-context mirrors in sync. The
    // ctx[+0]/[+4] mirrors live in the DRIVER push-buffer address space
    // (guest waiters sub_82411E98/barriers compare them against
    // dev[+10908]-derived put cursors), so they track our consumption
    // watermark — not the kernel-ring dword index (that is the phys
    // write-back word above, sub_82411218's view). On HW the write-back +
    // interrupt handler maintain all of these.
    const uint32_t mark = g_pushWatermark.load(std::memory_order_relaxed);
    if (mark != 0)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        ForEachDevice([&mem, mark](uint32_t dev) {
            uint32_t subctx = 0;
            if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
            {
                (void)mem.WriteU32BE(subctx + 0, mark);
                (void)mem.WriteU32BE(subctx + 4, mark);
            }
        });
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
    const uint32_t startRptr = rptr;
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

    // Kernel-side role: the real kernel CP consumer bumps the submitting
    // thread's GPU progress counter (*(r13+256)+88) as ring data is consumed;
    // sub_82412F98 busy-returns until it advanced >=5000 past the snapshot
    // (77.cpp:23832-23953). We run synchronously ON the submitter thread
    // (doorbell store), so its own PPC context is live here. Increment is
    // exactly the dwords consumed this drain - derived, not invented.
    if (const uint32_t advanced = (rptr - startRptr + cap) % cap; advanced != 0)
    {
        if (PPCContext* ctx = GetPPCContext())
        {
            auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
            const uint32_t tls = ctx->r13.u32;
            uint32_t blk = 0;
            if (tls != 0 && mem.ReadU32BE(tls + 256, &blk) && blk != 0)
            {
                g_progressBlk.store(blk, std::memory_order_relaxed);
                uint32_t cur = 0;
                if (mem.ReadU32BE(blk + 88, &cur))
                {
                    (void)mem.WriteU32BE(blk + 88, cur + advanced);
                }
            }
        }
    }
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
    if (devVA == 0)
    {
        return;
    }
    for (auto& slot : g_devices)
    {
        if (slot.load(std::memory_order_relaxed) == devVA)
        {
            return; // already registered
        }
    }
    for (auto& slot : g_devices)
    {
        uint32_t expected = 0;
        if (slot.compare_exchange_strong(expected, devVA, std::memory_order_relaxed))
        {
            const uint32_t n = s_attachedCount.fetch_add(1) + 1;
            MCLA_LOG_INFO("CP: attached GuestDevice {:08X} ({}/{})", devVA, n, kMaxDevices);
            if (n == kMaxDevices)
            {
                MCLA_LOG_WARN("CP: device registry full - further devices untracked");
            }
            return;
        }
    }
}

void CpConsumePushWindow(uint32_t endVA, uint32_t dwords)
{
    // Monotonic: windows may be captured slightly out of order.
    uint32_t prev = g_pushWatermark.load(std::memory_order_relaxed);
    while (endVA > prev && !g_pushWatermark.compare_exchange_weak(prev, endVA, std::memory_order_relaxed))
    {
    }

    if (dwords == 0)
        return;
    if (PPCContext* ctx = GetPPCContext())
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        const uint32_t tls = ctx->r13.u32;
        uint32_t blk = 0;
        if (tls != 0 && mem.ReadU32BE(tls + 256, &blk) && blk != 0)
        {
            uint32_t cur = 0;
            if (mem.ReadU32BE(blk + 88, &cur))
            {
                (void)mem.WriteU32BE(blk + 88, cur + dwords);
            }
        }
    }
}

void CpVblankBump(uint32_t amount)
{
    const uint32_t blk = g_progressBlk.load(std::memory_order_relaxed);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    // Mirror maintenance: on HW the CP fetches everything the driver writes
    // almost immediately, so the consumer cursor chases the producer cursor.
    // Guest waiters (sub_82411E98 etc.) compare ctx[+0]/[+4] against
    // dev[+10908]-derived put values; feeding them our stale capture
    // watermark deadlocks once writes bypass the reserver seam. Maintain
    // EVERY attached device - each waiter polls its own dev[+10896] ctx.
    ForEachDevice([&mem](uint32_t dev) {
        uint32_t subctx = 0;
        uint32_t put = 0;
        if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0 &&
            mem.ReadU32BE(dev + 10908, &put) && put != 0)
        {
            (void)mem.WriteU32BE(subctx + 0, put);
            (void)mem.WriteU32BE(subctx + 4, put);
        }
    });

    if (blk == 0 || amount == 0)
        return;
    uint32_t cur = 0;
    if (mem.ReadU32BE(blk + 88, &cur))
    {
        (void)mem.WriteU32BE(blk + 88, cur + amount);
    }
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

    // Xenia persists every register write in its register file and serves
    // later reads from it (GraphicsSystem::WriteRegister,
    // graphics_system.cc:207-223). Mirroring that: store into the shadow so
    // guest read-back sees what it wrote (interrupt-enable bits included).
    const uint32_t regIndex = offset >> 2;
    if (regIndex < kMmioRegCount)
    {
        g_regShadow[regIndex].store(value, std::memory_order_relaxed);
    }

    // First-touch-per-register logging (low regs tracked by bitmask; high
    // regs are rare enough to log every store, matching prior behavior).
    static std::atomic<uint32_t> regSeenMask{0};
    const uint32_t bit = regIndex < 32 ? (1u << regIndex) : 0;
    if (!bit || !(regSeenMask.fetch_or(bit) & bit))
    {
        static std::atomic<uint32_t> highRegLogCount{0};
        if (bit || (highRegLogCount.fetch_add(1) % 200) == 0)
        {
            MCLA_LOG_INFO("CP: MMIO write reg={:04X} offset={:04X} value={:08X}", regIndex, offset, value);
        }
    }
    return true;
}

bool CpMmioRead(uint32_t guestAddr, uint32_t* outValue)
{
    if ((guestAddr & kMmioMask) != kMmioBase)
    {
        return false;
    }

    const uint32_t offset = guestAddr - kMmioBase;
    const uint32_t regIndex = offset >> 2;

    // Per-register first-read logging for EVERY read (hardcoded + shadow):
    // the old warn-once-global flag hid all poll addresses after the first.
    {
        static std::atomic<uint32_t> slotReg[16]{};
        static std::atomic<uint32_t> slotBusy[16]{};
        const uint32_t slot = regIndex % 16;
        uint32_t expected = 0;
        bool wasEmpty = slotBusy[slot].load(std::memory_order_relaxed) == 0;
        if (wasEmpty &&
            slotBusy[slot].compare_exchange_strong(expected, 1u, std::memory_order_relaxed))
        {
            slotReg[slot].store(regIndex, std::memory_order_relaxed);
            MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} (first touch)", regIndex, offset);
        }
        else if (!wasEmpty && slotReg[slot].load(std::memory_order_relaxed) != regIndex)
        {
            // Slot occupied by another reg: rotate once per 500 distinct-ish
            // events so rare regs still surface without spamming hot polls.
            static std::atomic<uint32_t> rotateCounter{0};
            if ((rotateCounter.fetch_add(1, std::memory_order_relaxed) % 500) == 0)
            {
                slotReg[slot].store(regIndex, std::memory_order_relaxed);
                MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} (rotate)", regIndex, offset);
            }
        }
    }

    // Hardcoded status reads, mirroring xenia GraphicsSystem::ReadRegister
    // (graphics_system.cc:184-201). Reg 0x1951 bit0 = vblank pending - the
    // game's own vsync ISR gates its flip-request processor on exactly this
    // word ([0x7FC80000+0x6544]&1, ppc_recomp.77.cpp:19534-19542); answering
    // 0 starves the present path.
    switch (regIndex)
    {
    case 0x0F00: // RB_EDRAM_TIMING
        *outValue = 0x08100748u;
        return true;
    case 0x0F01: // RB_BC_CONTROL
        *outValue = 0x0000200Eu;
        return true;
    case 0x194C: // R500_D1MODE_V_COUNTER (720 visible lines)
        *outValue = 0x000002D0u;
        return true;
    case 0x1951: // interrupt status: vblank pending
        *outValue = 1u;
        return true;
    case 0x1961: // AVIVO_D1MODE_VIEWPORT_SIZE 1280x720
        *outValue = 0x050002D0u;
        return true;
    default:
        break;
    }

    // Everything else: last written value (xenia register-file fallback),
    // 0 when never written. Per-register first-read logging replaces the
    // old warn-once-global flag (which hid every subsequent poll address).
    if (regIndex < kMmioRegCount)
    {
        *outValue = g_regShadow[regIndex].load(std::memory_order_relaxed);
    }
    else
    {
        *outValue = 0;
    }
    {
        static std::atomic<uint32_t> seenRegs{0};
        uint32_t slot = regIndex % 16;
        uint32_t maskBit = 1u << slot;
        // Same reg logged once; distinct regs evict via round-robin slot.
        static std::atomic<uint32_t> slotReg[16]{};
        uint32_t expected = slotReg[slot].load(std::memory_order_relaxed);
        if (expected != regIndex &&
            slotReg[slot].compare_exchange_strong(expected, regIndex, std::memory_order_relaxed))
        {
            MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} -> {:08X} (shadow/hardcoded)",
                          regIndex, offset, *outValue);
            seenRegs.fetch_add(1, std::memory_order_relaxed);
        }
        else if (expected != regIndex && (seenRegs.load(std::memory_order_relaxed) % 500) == 0)
        {
            slotReg[slot].store(regIndex, std::memory_order_relaxed);
            MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} -> {:08X} (shadow/hardcoded)",
                          regIndex, offset, *outValue);
        }
    }
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
