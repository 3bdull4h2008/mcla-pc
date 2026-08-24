#include "gpu_device.h"
#include "gpu_cp.h"

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include <cpu/ppc_context.h>
#include "logging.h"
#include "kernel/memory.h"

#include <atomic>
#include <iterator>

static std::atomic<uint32_t> s_rsRealThunkHits{0};
static std::atomic<uint32_t> s_rsLogOnlyThunkHits{0};
void HostRsRealPassthrough(PPCContext& __restrict ctx, uint8_t* base);
void HostRsRealPassthroughLogOnly(PPCContext& __restrict ctx, uint8_t* base);


namespace mcla::gpu {

namespace {

std::atomic<uint32_t> g_deviceAddr{0};
std::atomic<bool> g_layoutDumped{false};

// Canonical publish slot the rest of the driver reads the device from:
// device = **(uint32_t**)0x82000864 (reverser-verified, 23 consumers).
constexpr uint32_t kDevicePublishSlot = 0x82000864;

constexpr uint32_t kDumpBytes = 0x400; // FP tables + sampler region + constants head

void DumpDeviceLayout(uint32_t dev)
{
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    for (uint32_t off = 0; off < kDumpBytes; off += 16)
    {
        uint32_t w[4] = {};
        bool ok = true;
        for (int i = 0; i < 4; ++i)
        {
            ok &= mem.ReadU32BE(dev + off + 4u * static_cast<uint32_t>(i), &w[i]);
        }
        if (!ok)
        {
            MCLA_LOG_WARN("DEVICE: read failed at +{:04X}", off);
            return;
        }
        // SWA GuestDevice reference layout for comparison: dirtyFlags[8]
        // @+0x00, setRenderStateFunctions[0x65] @+0x40,
        // setSamplerStateFunctions[0x14] @+0x1D4. Pointer-like words show up
        // as 82xxxxxx guest code addresses.
        MCLA_LOG_INFO("DEVICE +{:04X}: {:08X} {:08X} {:08X} {:08X}",
                      off, w[0], w[1], w[2], w[3]);
    }
}

void OnDeviceCreated(uint32_t dev)
{
    g_deviceAddr.store(dev, std::memory_order_relaxed);

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t slotPtr = 0;
    uint32_t published = 0;
    if (mem.ReadU32BE(kDevicePublishSlot, &slotPtr) && slotPtr != 0 &&
        mem.ReadU32BE(slotPtr, &published))
    {
        MCLA_LOG_INFO("DEVICE: created @ {:08X} (publish slot {:08X} -> {:08X}, {})",
                      dev, slotPtr, published,
                      published == dev ? "match" : "MISMATCH");
    }
    else
    {
        MCLA_LOG_INFO("DEVICE: created @ {:08X} (publish slot unreadable)", dev);
    }

    if (!g_layoutDumped.exchange(true))
    {
        DumpDeviceLayout(dev);
    }
}

} // namespace

uint32_t DeviceGuestAddr() { return g_deviceAddr.load(std::memory_order_relaxed); }

} // namespace mcla::gpu

// ---------------------------------------------------------------------------
// Render-state table redirection (UnleashedRecomp video.cpp CreateDevice).
// Slots left at the driver's own default stub (= PPC_CODE_BASE) are pointed
// at a host passthrough thunk registered past the guest code range. Real
// handlers stay untouched - this proves the FP-table seam end-to-end without
// changing behavior.
// ---------------------------------------------------------------------------

static std::atomic<uint32_t> s_rsThunkHits{0};

static void HostRsUnimplementedPassthrough(PPCContext& __restrict ctx, uint8_t* base)
{
    // First touches get logged; behavior passes through to the driver's own
    // default handler unchanged.
    const uint32_t hits = s_rsThunkHits.fetch_add(1) + 1;
    if (hits <= 12 || (hits % 500) == 0)
    {
        MCLA_LOG_INFO("DEVICE: RS-default-thunk hit #{} r3={:08X} r4={:08X}", hits,
                      ctx.r3.u32, ctx.r4.u32);
    }
    if (PPCFunc* orig = mcla::kernel::g_memory.FindFunction(static_cast<uint32_t>(PPC_CODE_BASE)))
    {
        orig(ctx, base);
    }
}

namespace mcla::gpu {
namespace {

void RedirectDefaultRenderStateSlots(uint32_t dev)
{
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    const auto fnOffset = static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE);
    mcla::kernel::g_memory.InsertFunction(fnOffset, &HostRsUnimplementedPassthrough);

    uint32_t redirected = 0;
    constexpr uint32_t kSlots = 0x65; // setRenderStateFunctions count
    for (uint32_t slot = 0; slot < kSlots; ++slot)
    {
        const uint32_t addr = dev + 0x40u + slot * 4u;
        uint32_t cur = 0;
        if (!mem.ReadU32BE(addr, &cur))
        {
            return;
        }
        if (cur == static_cast<uint32_t>(PPC_CODE_BASE))
        {
            (void)mem.WriteU32BE(addr, fnOffset);
            ++redirected;
        }
    }

    // Rung-2 self-test: table round-trip + thunk resolution.
    uint32_t readBack = 0;
    const bool tableOk = mem.ReadU32BE(dev + 0x40u, &readBack);
    PPCFunc* resolved = mcla::kernel::g_memory.FindFunction(fnOffset);
    MCLA_LOG_INFO("DEVICE: redirected {}/{} default RS slots -> {:08X} | readback={} "
                  "(slot0={:08X}) | thunkResolved={}",
                  redirected, kSlots, fnOffset,
                  tableOk ? "ok" : "FAIL", readBack, resolved != nullptr);
}

// P4' step 2: passthrough-thunk ONE real handler slot so a runtime call proves
// dispatch through our synthetic VA end-to-end. Slot +0x68 (table index 10)
// held 0x82414078 in both dumped devices. The original stays reachable via its
// own guest address (FindFunction), so redirection loses nothing.
constexpr uint32_t kRealSlotOffset = 0x68;
constexpr uint32_t kRealSlotOriginal = 0x82414078;

void RedirectFirstRealRenderStateSlot(uint32_t dev)
{
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    const uint32_t slotAddr = dev + kRealSlotOffset;
    uint32_t cur = 0;
    if (!mem.ReadU32BE(slotAddr, &cur))
    {
        MCLA_LOG_WARN("DEVICE: real-slot redirect read failed @ {:08X}", slotAddr);
        return;
    }
    if (cur != kRealSlotOriginal)
    {
        MCLA_LOG_WARN("DEVICE: real-slot @ {:08X} holds {:08X} (expected {:08X}) - skipping",
                      slotAddr, cur, kRealSlotOriginal);
        return;
    }

    // Synthetic VA right after the default-slots thunk.
    const auto fnOffset = static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE) + 4u;
    mcla::kernel::g_memory.InsertFunction(fnOffset, &HostRsRealPassthrough);
    (void)mem.WriteU32BE(slotAddr, fnOffset);

    uint32_t readBack = 0;
    const bool ok = mem.ReadU32BE(slotAddr, &readBack) && readBack == fnOffset &&
                    mcla::kernel::g_memory.FindFunction(fnOffset) != nullptr;
    MCLA_LOG_INFO("DEVICE: real RS slot +{:X} -> {:08X} | selftest={}",
                  kRealSlotOffset, fnOffset, ok ? "ok" : "FAIL");

    // Probe widening: EVERY other real slot gets a log-only thunk (no
    // passthrough - originals stay reachable by address if needed later).
    // Purpose: discover which states are actually hot during boot/menu.
    constexpr uint32_t kSlots = 0x65;
    uint32_t probed = 0;
    auto nextFn = fnOffset;
    for (uint32_t slot = 0; slot < kSlots; ++slot)
    {
        const uint32_t sAddr = dev + 0x40u + slot * 4u;
        uint32_t v = 0;
        if (!mem.ReadU32BE(sAddr, &v)) break;
        if (v == static_cast<uint32_t>(PPC_CODE_BASE)) continue;   // default stub
        if (sAddr == slotAddr) continue;                           // faithful one above
        if (v < static_cast<uint32_t>(PPC_CODE_BASE) ||
            v >= static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE)) continue; // not guest code
        ++nextFn;
        mcla::kernel::g_memory.InsertFunction(nextFn, &HostRsRealPassthroughLogOnly);
        (void)mem.WriteU32BE(sAddr, nextFn);
        ++probed;
    }
    MCLA_LOG_INFO("DEVICE: probe widened - {} additional real slots log-only", probed);
}

} // namespace
} // namespace mcla::gpu

// ---------------------------------------------------------------------------
// Guest-function override. MUST live at GLOBAL scope: the generated TUs bind
// calls to the global weak symbol sub_82413588; a namespaced definition would
// be a different symbol entirely and silently never run.
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_82413588);

PPC_FUNC(sub_82413588)
{
    // r8 is caller-volatile under the recomp ABI - the callee clobbers ctx.r8
    // immediately after saving it to a callee-saved register. Capture the
    // out-pointer BEFORE transferring control.
    const uint32_t outPtr = ctx.r8.u32;

    static std::atomic<bool> entryLogged{false};
    if (!entryLogged.exchange(true))
    {
        MCLA_LOG_INFO("DEVICE: create entry hit (out={:08X})", outPtr);
    }

    __imp__sub_82413588(ctx, base);

    if (outPtr != 0)
    {
        uint32_t dev = 0;
        if (mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(outPtr, &dev) && dev != 0)
        {
            mcla::gpu::OnDeviceCreated(dev);
            mcla::gpu::RedirectDefaultRenderStateSlots(dev);
            mcla::gpu::RedirectFirstRealRenderStateSlot(dev);
        }
        else
        {
            static std::atomic<bool> warned{false};
            if (!warned.exchange(true))
            {
                MCLA_LOG_WARN("DEVICE: create produced no device (out={:08X})", outPtr);
            }
        }
    }
}




// P4' step 2 runtime thunk: proves guest -> synthetic VA -> host dispatch.
void HostRsRealPassthrough(PPCContext& __restrict ctx, uint8_t* base)
{
    const uint32_t n = s_rsRealThunkHits.fetch_add(1) + 1;
    if (n <= 12 || (n % 500) == 0)
        MCLA_LOG_INFO("DEVICE: RS-real-thunk hit #{} r3={:08X} r4={:08X}", n, ctx.r3.u32, ctx.r4.u32);
    if (PPCFunc* orig = mcla::kernel::g_memory.FindFunction(mcla::gpu::kRealSlotOriginal))
        orig(ctx, base);
}


// Log-only probe thunk: records the hit, does NOT call the original - used to
// discover hot render-state slots; originals remain at their guest addresses.
void HostRsRealPassthroughLogOnly(PPCContext& __restrict ctx, uint8_t* base)
{
    const uint32_t n = s_rsLogOnlyThunkHits.fetch_add(1) + 1;
    if (n <= 20 || (n % 1000) == 0)
        MCLA_LOG_INFO("DEVICE: RS-logonly-thunk hit #{} r3={:08X} r4={:08X}", n, ctx.r3.u32, ctx.r4.u32);
}


// ---------------------------------------------------------------------------
// P4' PIVOT: MCLA never dispatches via device FP tables (see PIVOT FINDING).
// State/draw intent flows DIRECTLY through these helpers. Global-scope strong
// overrides intercept every caller; passthrough preserves behavior.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411180);
static std::atomic<uint32_t> s_h11180{0};
static std::atomic<uint32_t> s_h11180done{0};
PPC_FUNC(sub_82411180)
{
    const uint32_t n = s_h11180.fetch_add(1) + 1;
    const uint32_t dev = ctx.r3.u32;
    uint32_t mask = 0, subctx = 0, published4 = 0;
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(dev + 14900, &mask);
        if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
            (void)mem.ReadU32BE(subctx + 4, &published4);
    }
    if (n <= 16 || (n % 2000) == 0)
        MCLA_LOG_INFO("HELPER-thunk sub_82411180 hit #{} r3={:08X} r4={:08X} r5={:08X} msk={:X} sc={:X} wb4={:X}",
                      n, dev, ctx.r4.u32, ctx.r5.u32, mask, subctx, published4);
    __imp__sub_82411180(ctx, base);
    const uint32_t d = s_h11180done.fetch_add(1) + 1;
    if (n <= 16 || (n % 2000) == 0)
        MCLA_LOG_INFO("HELPER-thunk sub_82411180 RETURNED #{} (r3={:08X})", d, ctx.r3.u32);
}

PPC_FUNC_IMPL(__imp__sub_82411618);
static std::atomic<uint32_t> s_h11618{0};
PPC_FUNC(sub_82411618)
{
    const uint32_t n = s_h11618.fetch_add(1) + 1;
    if (n <= 12 || (n % 2000) == 0)
        MCLA_LOG_INFO("HELPER-thunk sub_82411618 hit #{} r3={:08X}", n, ctx.r3.u32);
    __imp__sub_82411618(ctx, base);
}

// PRIMARY CHOKE POINT (reverser-pinned 2026-08-23): sub_82411640 is a
// push-buffer SPACE RESERVER, not a packet writer:
//   sub_82411640(dev /*r3*/, flags /*r4*/, sizeSlot /*r5*/, alignBytes /*r6*/)
// r5 points to ONE u32 {requested bytes}; only desc[0] is read by the guest.
// Return r3 = reserved ring-window VA; desc[0] written back = consumed bytes.
// => the reserved window holds FULLY-FORMED driver output for every
//    submission class; capture it AFTER passthrough.
// Submission classes (ppc_recomp.77.cpp evidence):
//   (flags=1, align=32) -> sub_82411B10 descriptor batches
//   (flags=1, align=4)  -> sub_82412710 indirect-dispatch packet
//   (flags=2, align=32) -> sub_82412318 raw packet envelopes
// PM4 classification ground truth: .research/xenia/src/xenia/gpu/xenos.h:1572-1664.
// Capture-only: bounds-checked BE reads, no D3D12, no invented fields.
namespace {

constexpr uint32_t kPktCapMaxDwords = 256; // defensive cap per window read
constexpr uint32_t kPktCapFullDumps = 16;  // full hex dumps before stats-only
constexpr uint32_t kPktCapPendingMax = 64; // deferred-window ring capacity

// Reserved windows are EMPTY at sub_82411640 return - builders (sub_82411B10 /
// sub_82411DC0) fill them afterwards. Capture is therefore DEFERRED: entries
// are queued here and scanned on the NEXT reservation, when their bytes are
// actually present in the ring.
struct PendingWindow
{
    uint32_t addr;
    uint32_t dwords;
    uint32_t flags;
    uint32_t alignBytes;
};
PendingWindow g_pending[kPktCapPendingMax] = {};
uint32_t g_pendingCount = 0;

struct PktCapStats
{
    std::atomic<uint32_t> descriptors{0};
    std::atomic<uint32_t> dwords{0};
    std::atomic<uint32_t> clsDescBatch{0};   // flags=1 align>=32
    std::atomic<uint32_t> clsIndirect{0};    // flags=1 align<32
    std::atomic<uint32_t> clsRawEnvelope{0}; // flags!=1 align>=32
    std::atomic<uint32_t> type0{0};
    std::atomic<uint32_t> type1{0};
    std::atomic<uint32_t> type2Nop{0};
    std::atomic<uint32_t> t3Nop{0};          // 0x10
    std::atomic<uint32_t> t3DrawIndx{0};     // 0x22
    std::atomic<uint32_t> t3DrawIndx2{0};    // 0x36
    std::atomic<uint32_t> t3ImLoad{0};       // 0x27 / 0x2b
    std::atomic<uint32_t> t3SetConstant{0};  // 0x2d
    std::atomic<uint32_t> t3LoadAluConst{0}; // 0x2f
    std::atomic<uint32_t> t3MemWrite{0};     // 0x3d
    std::atomic<uint32_t> t3EventWrite{0};   // 0x46, 0x58-0x5b
    std::atomic<uint32_t> t3Other{0};
    std::atomic<uint32_t> clampedWindow{0}; // read clamp / VA-space overrun
    std::atomic<uint32_t> midPacket{0};     // scan ended inside a packet
    std::atomic<uint32_t> oddBytes{0};      // consumed not dword-aligned
};

PktCapStats g_pktCap;

bool IsEventOpcode(uint32_t op)
{
    return op == 0x46 || (op >= 0x58 && op <= 0x5b);
}

void ClassifyT3(uint32_t op)
{
    switch (op)
    {
    case 0x10: ++g_pktCap.t3Nop; break;
    case 0x22: ++g_pktCap.t3DrawIndx; break;
    case 0x36: ++g_pktCap.t3DrawIndx2; break;
    case 0x27:
    case 0x2b: ++g_pktCap.t3ImLoad; break;
    case 0x2d: ++g_pktCap.t3SetConstant; break;
    case 0x2f: ++g_pktCap.t3LoadAluConst; break;
    case 0x3d: ++g_pktCap.t3MemWrite; break;
    default:
        if (IsEventOpcode(op))
            ++g_pktCap.t3EventWrite;
        else
            ++g_pktCap.t3Other;
        break;
    }
}

void ScanPackets(const uint32_t* w, uint32_t n)
{
    // Packet sizes per .research/xenia/src/xenia/gpu/command_processor.cc:
    // type-0 = header + (((p>>16)&0x3FFF)+1) dwords (:641),
    // type-1 = header + TWO payload dwords (:666-670), type-2 = 1 dword,
    // type-3 = header + (((p>>16)&0x3FFF)+1) payload dwords.
    uint32_t i = 0;
    while (i < n)
    {
        const uint32_t hdr = w[i];
        uint32_t next = i + 1;
        switch (hdr >> 30)
        {
        case 0:
            ++g_pktCap.type0;
            next = i + ((hdr >> 16) & 0x3FFFu) + 2;
            break;
        case 1:
            ++g_pktCap.type1;
            next = i + 3;
            break;
        case 2:
            ++g_pktCap.type2Nop;
            next = i + 1;
            break;
        default:
            ClassifyT3((hdr >> 8) & 0xFFu);
            next = i + ((hdr >> 16) & 0x3FFFu) + 2;
            break;
        }
        if (next > n)
        {
            ++g_pktCap.midPacket; // window ends inside a packet; stop cleanly
            return;
        }
        i = next;
    }
}

} // namespace

PPC_FUNC_IMPL(__imp__sub_82411640);
static std::atomic<uint32_t> s_h11640{0};

namespace {

// Read+classify one (previously reserved) ring window. Called from the 640
// override AFTER the window has had time to be filled by its builder.
void CaptureWindow(uint32_t n, uint32_t dev, const PendingWindow& pw)
{
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    if ((pw.dwords * 4u) % 4u != 0)
        ++g_pktCap.oddBytes;

    // Clamp to capture buffer AND to guest VA space (u64 math: no wrap near
    // 0xFFFFFFFF into low RAM).
    uint64_t availDwords = pw.dwords;
    if (availDwords > kPktCapMaxDwords)
        availDwords = kPktCapMaxDwords;
    if (pw.addr == 0)
        return;
    const uint64_t vaRoomDwords = (uint64_t(0x100000000ull) - pw.addr) / 4u;
    if (vaRoomDwords < availDwords)
        availDwords = vaRoomDwords;

    const uint32_t wordCount = uint32_t(availDwords);
    if (wordCount < pw.dwords)
        ++g_pktCap.clampedWindow;

    uint32_t words[kPktCapMaxDwords] = {};
    bool readOk = wordCount > 0;
    for (uint32_t i = 0; i < wordCount; ++i)
        readOk &= mem.ReadU32BE(pw.addr + i * 4u, &words[i]);

    if (!readOk)
    {
        static std::atomic<bool> readWarned{false};
        if (!readWarned.exchange(true))
            MCLA_LOG_WARN("PKT-CAP: window read failed dev={:08X} @ {:08X}", dev, pw.addr);
        return;
    }

    ++g_pktCap.descriptors;
    g_pktCap.dwords.fetch_add(wordCount, std::memory_order_relaxed);

    // Consumption accounting: these bytes are resident ⇒ kernel CP may fetch
    // through them. Advances the ctx[+0]/[+4] watermark + progress counter
    // by the FULL reserved size (not the clamped read).
    mcla::gpu::CpConsumePushWindow(pw.addr + pw.dwords * 4u, pw.dwords);

    if ((pw.flags & 1u) != 0)
    {
        if (pw.alignBytes >= 32)
            ++g_pktCap.clsDescBatch;
        else
            ++g_pktCap.clsIndirect;
    }
    else if (pw.alignBytes >= 32)
    {
        ++g_pktCap.clsRawEnvelope;
    }
    ScanPackets(words, wordCount);

    if (n <= kPktCapFullDumps)
    {
        std::string hex;
        hex.reserve(wordCount * 9);
        for (uint32_t i = 0; i < wordCount; ++i)
            fmt::format_to(std::back_inserter(hex), "{:08X} ", words[i]);
        MCLA_LOG_INFO("PKT-CAP #{:04X}: dev={:08X} f={} a={} win={:08X} n={} | {}",
                      n, dev, pw.flags, pw.alignBytes, pw.addr, pw.dwords, hex);
    }
}

void LogSummary(uint32_t n)
{
    MCLA_LOG_INFO(
        "PKT-CAP summary: desc={} dw={} descBatch={} indirect={} rawEnv={} "
        "t0={} t1={} t2nop={} t3nop={} draw_indx={} draw_indx2={} "
        "im_load={} set_const={} load_alu={} mem_write={} event_write={} "
        "other_t3={} clamped={} midpkt={} oddbytes={}",
        g_pktCap.descriptors.load(), g_pktCap.dwords.load(),
        g_pktCap.clsDescBatch.load(), g_pktCap.clsIndirect.load(),
        g_pktCap.clsRawEnvelope.load(), g_pktCap.type0.load(),
        g_pktCap.type1.load(), g_pktCap.type2Nop.load(), g_pktCap.t3Nop.load(),
        g_pktCap.t3DrawIndx.load(), g_pktCap.t3DrawIndx2.load(),
        g_pktCap.t3ImLoad.load(), g_pktCap.t3SetConstant.load(),
        g_pktCap.t3LoadAluConst.load(), g_pktCap.t3MemWrite.load(),
        g_pktCap.t3EventWrite.load(), g_pktCap.t3Other.load(),
        g_pktCap.clampedWindow.load(), g_pktCap.midPacket.load(),
        g_pktCap.oddBytes.load());
}

} // namespace

PPC_FUNC(sub_82411640)
{
    const uint32_t n = s_h11640.fetch_add(1) + 1;
    const uint32_t dev = ctx.r3.u32;
    const uint32_t flags = ctx.r4.u32;
    const uint32_t slotAddr = ctx.r5.u32;
    const uint32_t alignBytes = ctx.r6.u32; // volatile reg: snapshot pre-call

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t requested = 0;
    const bool haveReq = mem.ReadU32BE(slotAddr, &requested);
    if (!haveReq)
    {
        static std::atomic<bool> slotWarned{false};
        if (!slotWarned.exchange(true))
            MCLA_LOG_WARN("PKT-CAP: size-slot read failed dev={:08X} @ {:08X}", dev, slotAddr);
        __imp__sub_82411640(ctx, base);
        return;
    }

    __imp__sub_82411640(ctx, base);

    // Post-passthrough: consumed bytes in slot[0], reserved window in r3.
    uint32_t consumed = 0;
    if (!mem.ReadU32BE(slotAddr, &consumed))
        return;

    const uint32_t window = ctx.r3.u32;

    // Drain previously reserved windows first - their builders have filled
    // them by now. THEN queue the freshly reserved (still empty) window.
    for (uint32_t i = 0; i < g_pendingCount; ++i)
        CaptureWindow(n, dev, g_pending[i]);
    g_pendingCount = 0;

    if (window != 0 && consumed != 0 && g_pendingCount < kPktCapPendingMax)
    {
        g_pending[g_pendingCount].addr = window;
        g_pending[g_pendingCount].dwords = consumed / 4u;
        g_pending[g_pendingCount].flags = flags;
        g_pending[g_pendingCount].alignBytes = alignBytes;
        ++g_pendingCount;
    }

    if (n <= 16 || (n % 5000) == 0)
        MCLA_LOG_INFO("HELPER-thunk sub_82411640 hit #{} dev={:08X} f={} req={}",
                      n, dev, flags, requested);

    // 640 fires ~handful of times per boot (init/state batches), so summarize
    // every hit during the early run + on a LOW cadence afterwards - this
    // guarantees per-run gate metrics regardless of submission volume.
    if (n <= 32 || (n % 100) == 0)
    {
        for (uint32_t i = 0; i < g_pendingCount; ++i)
            CaptureWindow(n, dev, g_pending[i]);
        g_pendingCount = 0;
        LogSummary(n);
    }
}

// ---------------------------------------------------------------------------
// P4' submit-family census (reverser-ranked per-frame seam candidates).
// Log-only passthrough overrides; each size-class helper embeds its OWN
// reserver clone (dev+14908/14916 accessed directly in 11840 at
// ppc_recomp.77.cpp:20129), which is why 640 stays cold while frames flow.
// Ranked targets: sub_82420BA8 (per-batch draw submit), sub_82413660 (draw-
// packet builder), sub_8241BD08 (flush/kick), sub_82429570/sub_824294E0
// (present kickers, DEBCBEEF marker).
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82420BA8);
static std::atomic<uint32_t> s_h20BA8{0};
PPC_FUNC(sub_82420BA8)
{
    const uint32_t n = s_h20BA8.fetch_add(1) + 1;
    if (n <= 12 || (n % 1000) == 0)
        MCLA_LOG_INFO("SUBMIT-census sub_82420BA8 #{} dev={:08X} flags={:X} blk={:08X} desc={:08X}/{:08X} r10={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r10.u32);
    __imp__sub_82420BA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413660);
static std::atomic<uint32_t> s_h13660{0};
PPC_FUNC(sub_82413660)
{
    const uint32_t n = s_h13660.fetch_add(1) + 1;
    if (n <= 12 || (n % 5000) == 0)
        MCLA_LOG_INFO("SUBMIT-census sub_82413660 #{} r3={:08X} r4={:08X} r5={:08X} r6={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32);
    __imp__sub_82413660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82411840);
static std::atomic<uint32_t> s_h11840{0};
PPC_FUNC(sub_82411840)
{
    const uint32_t n = s_h11840.fetch_add(1) + 1;
    if (n <= 12 || (n % 5000) == 0)
        MCLA_LOG_INFO("SUBMIT-census sub_82411840 #{} dev={:08X} cls={} a={}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
    __imp__sub_82411840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241BD08);
static std::atomic<uint32_t> s_h1BD08{0};
PPC_FUNC(sub_8241BD08)
{
    const uint32_t n = s_h1BD08.fetch_add(1) + 1;
    if (n <= 12 || (n % 1000) == 0)
        MCLA_LOG_INFO("SUBMIT-census sub_8241BD08(flush) #{} dev={:08X} r4={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32);
    __imp__sub_8241BD08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82429570);
static std::atomic<uint32_t> s_h29570{0};
PPC_FUNC(sub_82429570)
{
    const uint32_t n = s_h29570.fetch_add(1) + 1;
    if (n <= 12 || (n % 1000) == 0)
        MCLA_LOG_INFO("SUBMIT-census sub_82429570(present) #{} r3={:08X} r4={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32);
    __imp__sub_82429570(ctx, base);
}

// ---------------------------------------------------------------------------
// RING-WAIT census (2026-08-23): sub_82411928 is the SOLE doorbell-ringer
// module-wide (PPC_MM_STORE_U32(0x7FC80000+1812), 77.cpp:20398). Earlier run:
// 5 reserve passes then silence — thread parked between 11218-return and the
// doorbell store. Log predicate inputs + whether the tail is ever reached.
// Units: dword indices, mask=dev[+14900]; published rptr = subctx[+60].
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411218);
static std::atomic<uint32_t> s_h11218{0};
PPC_FUNC(sub_82411218)
{
    const uint32_t n = s_h11218.fetch_add(1) + 1;
    const uint32_t dev = ctx.r3.u32;
    const uint32_t target = ctx.r4.u32;
    const uint32_t bytes = ctx.r5.u32;
    if (dev != 0)
    {
        mcla::gpu::CpAttachDriverCtx(dev);
    }
    uint32_t mask = 0, subctx = 0, published = 0;
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(dev + 14900, &mask);
        if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
            (void)mem.ReadU32BE(subctx + 60, &published);
    }
    // Progress-counter visibility: *(r13+256)+88 of THIS thread (sub_82412F98
    // exits when it advances >=5000 past snapshot). Pump preconditions per
    // gate-cracker E3: dev[+13432]!=0 && blocker [0x827CDA3C]==0.
    uint32_t pcBlk = 0, pcVal = 0, pumpObj = 0, blocker = 0;
    if (PPCContext* pctx = GetPPCContext())
    {
        const uint32_t tls = pctx->r13.u32;
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        if (tls != 0 && mem.ReadU32BE(tls + 256, &pcBlk) && pcBlk != 0)
            (void)mem.ReadU32BE(pcBlk + 88, &pcVal);
        (void)mem.ReadU32BE(dev + 13432, &pumpObj);
        (void)mem.ReadU32BE(0x827CDA3C, &blocker);
    }
    const bool wraps = ((target + bytes) & ~mask) != (target & ~mask);
    if (n <= 16 || (n % 2000) == 0)
        MCLA_LOG_INFO("RW #{:04X} tgt={:05X} b={:X} msk={:X} sc={:X} wb={:X} pc={}:{} pump={:08X} blk={:08X} wrap={}",
                      n, target, bytes, mask, subctx, published, pcBlk, pcVal, pumpObj, blocker, wraps ? 1 : 0);
    __imp__sub_82411218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82411928);
static std::atomic<uint32_t> s_h11928{0};
static std::atomic<uint32_t> s_h11928done{0};
PPC_FUNC(sub_82411928)
{
    const uint32_t n = s_h11928.fetch_add(1) + 1;
    if (n <= 12 || (n % 2000) == 0)
        MCLA_LOG_INFO("DOORBELL sub_82411928 #{} r3={:08X} r4={:08X} r5={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
    __imp__sub_82411928(ctx, base);
    const uint32_t d = s_h11928done.fetch_add(1) + 1;
    if (d <= 12 || (d % 2000) == 0)
        MCLA_LOG_INFO("DOORBELL sub_82411928 RETURNED #{}", d);
}

// ---------------------------------------------------------------------------
// E98 census (2026-08-23 session 9): sub_82411E94 is an EMPTY padding stub;
// the real wait body is sibling sub_82411E98 (77.cpp:21047-21170), decoded:
//   r4=needed, dev=r3; put=dev[+10908]; pub=*(*(dev+10896)+0)
//   early-exit r4==0 | free>=used | special (r7&0xFF)==0 && needed==put &&
//   dev[+13232]==0 -> sub_82412710; else wait loop: init ctx via
//   sub_82412EA0, poll sub_82412F98 (busy r3=1 keeps looping), recheck
//   needed > pub, destroy ctx via sub_82412ED0.
// Persistent stall shape: needed > published at every recheck. Census pins
// WHICH device spins, the exact predicate words, and THIS thread's progress
// counter (F98's gate input) - discriminates wrong-device mirrors vs frozen
// per-thread progress. Also registers every waiting device so mirror
// maintenance covers it.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411E98);
static std::atomic<uint32_t> s_h11E98{0};
static std::atomic<uint32_t> s_h11E98done{0};
PPC_FUNC(sub_82411E98)
{
    const uint32_t n = s_h11E98.fetch_add(1) + 1;
    const uint32_t dev = ctx.r3.u32;
    const uint32_t needed = ctx.r4.u32;
    const uint32_t arg5 = ctx.r5.u32;
    const uint32_t flags = ctx.r7.u32 & 0xFF;
    if (dev != 0)
    {
        mcla::gpu::CpAttachDriverCtx(dev);
    }
    uint32_t put = 0, subctx = 0, pub0 = 0, flag13232 = 0, pcBlk = 0, pcVal = 0;
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(dev + 10908, &put);
        if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
        {
            (void)mem.ReadU32BE(subctx + 0, &pub0);
        }
        (void)mem.ReadU32BE(dev + 13232, &flag13232);
        if (PPCContext* pctx = GetPPCContext())
        {
            const uint32_t tls = pctx->r13.u32;
            if (tls != 0 && mem.ReadU32BE(tls + 256, &pcBlk) && pcBlk != 0)
            {
                (void)mem.ReadU32BE(pcBlk + 88, &pcVal);
            }
        }
    }
    // Same expression as the generated compare (u32 wraparound semantics).
    const bool waitsAtEntry = needed != 0 &&
                              ((put - needed) < (put - pub0));
    if (n <= 16 || (n % 500) == 0)
    {
        MCLA_LOG_INFO("E98 #{:04X} dev={:08X} need={:08X} put={:08X} pub={:08X} "
                      "f13232={} flg={} wait={} a5={:08X} pc={}:{}",
                      n, dev, needed, put, pub0, flag13232 != 0, flags,
                      waitsAtEntry ? 1 : 0, arg5, pcBlk, pcVal);
    }
    __imp__sub_82411E98(ctx, base);
    const uint32_t d = s_h11E98done.fetch_add(1) + 1;
    if (d <= 16 || (d % 500) == 0)
        MCLA_LOG_INFO("E98 RETURNED #{}", d);
}

// ---------------------------------------------------------------------------
// FLIP-PROCESSOR census: sub_82419718 runs from the vsync ISR type-0 branch
// once gate [0x7FC86544]&1 is set (77.cpp:19534-19547). Per session-5 RE:
// drains flip-request entries at dev[+16572+i*8], MMIO store 0x7FCE6110 per
// entry, callback dev[+16544]. Census proves the gate path executes and dumps
// queue head + present-callback slot.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82419718);
static std::atomic<uint32_t> s_h19718{0};
PPC_FUNC(sub_82419718)
{
    const uint32_t n = s_h19718.fetch_add(1) + 1;
    const uint32_t dev = ctx.r3.u32;
    uint32_t cb = 0, q0 = 0, q1 = 0, q2 = 0;
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(dev + 16544, &cb);
        (void)mem.ReadU32BE(dev + 16572, &q0);
        (void)mem.ReadU32BE(dev + 16580, &q1);
        (void)mem.ReadU32BE(dev + 16588, &q2);
    }
    if (n <= 12 || (n % 2000) == 0)
        MCLA_LOG_INFO("FLIP sub_82419718 #{} dev={:08X} cb={:08X} q[0..2]={:08X}/{:08X}/{:08X}",
                      n, dev, cb, q0, q1, q2);
    __imp__sub_82419718(ctx, base);
}

// ---------------------------------------------------------------------------
// WAIT-HELPER census: sub_82135DC0(handle=r3, timeoutMs=r4, alertable=r5)
// wraps NtWaitForSingleObjectEx in a retry-on-timeout loop
// (ppc_recomp.0.cpp:18590-18654). PARK-SAMPLE caught the main thread parked
// inside it on handle C9ADB800 with ~unit timeout - this pins handle,
// timeout, alertability, and result distribution (257=STATUS_TIMEOUT spin).
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82135DC0);
static std::atomic<uint32_t> s_h135DC0{0};
static std::atomic<uint32_t> s_h135DC0done{0};
PPC_FUNC(sub_82135DC0)
{
    const uint32_t n = s_h135DC0.fetch_add(1) + 1;
    const uint32_t handle = ctx.r3.u32;
    const uint32_t timeoutArg = ctx.r4.u32;
    const uint32_t alertable = ctx.r5.u32 & 0xFF;
    // Finite timeouts are the poll patterns (frame pacing etc.) - always
    // surface those up to a cap; infinite worker parks stay throttled.
    const bool finite = timeoutArg != 0xFFFFFFFFu;
    if ((finite && n <= 400) || n <= 12 || (n % 1000) == 0)
        MCLA_LOG_INFO("WAITHELP sub_82135DC0 #{} h={:08X} t={} al={} lr={:08X}",
                      n, handle, timeoutArg, alertable, ctx.lr);
    __imp__sub_82135DC0(ctx, base);
    const uint32_t d = s_h135DC0done.fetch_add(1) + 1;
    if (d <= 12 || (d % 1000) == 0)
        MCLA_LOG_INFO("WAITHELP RETURNED #{} r3={:08X} (257=timeout)", d, ctx.r3.u32);
}

// Non-alertable wrapper (li r5,0 -> DC0, TU0:18580-18587): the MAIN thread's
// park goes through here (PARK-SAMPLE lr=82135DF8 is inside DC0's own
// NtWaitForSingleObjectEx call). Census names each caller site + handle.
PPC_FUNC_IMPL(__imp__sub_82135DB8);
static std::atomic<uint32_t> s_h135DB8{0};
PPC_FUNC(sub_82135DB8)
{
    const uint32_t n = s_h135DB8.fetch_add(1) + 1;
    if (n <= 24 || (n % 1000) == 0)
        MCLA_LOG_INFO("WAITB8 sub_82135DB8 #{} h={:08X} t={} lr={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.lr);
    __imp__sub_82135DB8(ctx, base);
}

// Sync-wait utility (TU17:10837): wait INFINITE non-alertable on r3, return
// r3==0. The main thread's park handle C9ADB800 arrives HERE - capture the
// caller one level up to name the waiting subsystem.
PPC_FUNC_IMPL(__imp__sub_821C90C0);
static std::atomic<uint32_t> s_h90C0{0};
PPC_FUNC(sub_821C90C0)
{
    const uint32_t n = s_h90C0.fetch_add(1) + 1;
    const uint32_t handle = ctx.r3.u32;
    const uint32_t caller = ctx.lr;
    if (n <= 24 || (n % 1000) == 0)
        MCLA_LOG_INFO("WAITSYNC sub_821C90C0 #{} h={:08X} caller={:08X}",
                      n, handle, caller);
    __imp__sub_821C90C0(ctx, base);
}

// FENCE-WAIT (TU21:4085): sub_821E5640(obj=r3, blocking=r4, release=r5)
// waits INFINITE on the embedded completion event [obj+8]. Dump the object
// tag/state so the pending async-job TYPE becomes visible; caller LR names
// the submitter (async wrapper sub_821E5FD0 family).
PPC_FUNC_IMPL(__imp__sub_821E5640);
static std::atomic<uint32_t> s_h5640{0};
PPC_FUNC(sub_821E5640)
{
    const uint32_t n = s_h5640.fetch_add(1) + 1;
    const uint32_t obj = ctx.r3.u32;
    const uint32_t blocking = ctx.r4.u32 & 0xFF;
    uint32_t tag = 0, state = 0, evt = 0;
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(obj + 0, &tag);
        (void)mem.ReadU32BE(obj + 4, &state);
        (void)mem.ReadU32BE(obj + 8, &evt);
    }
    if (n <= 24 || (n % 500) == 0)
        MCLA_LOG_INFO("FENCE sub_821E5640 #{} obj={:08X} tag={:08X} st={} ev={:08X} blk={} lr={:08X}",
                      n, obj, tag, state, evt, blocking, ctx.lr);
    __imp__sub_821E5640(ctx, base);
}

// TASK-COMPLETE census: sub_8244EE00 runs after every pool-worker task
// execution (TU16:15473, sysTaskExecutor pool proc 821C4528). If tasks ever
// execute, this fires - and its release chain should wake the parked fence.
PPC_FUNC_IMPL(__imp__sub_8244EE00);
static std::atomic<uint32_t> s_h4EE00{0};
PPC_FUNC(sub_8244EE00)
{
    const uint32_t n = s_h4EE00.fetch_add(1) + 1;
    if (n <= 24 || (n % 2000) == 0)
        MCLA_LOG_INFO("TASK-DONE sub_8244EE00 #{} arg={:08X}", n, ctx.r3.u32);
    __imp__sub_8244EE00(ctx, base);
}

// ENQUEUE-CHOOSER census: Function_821BCB10 decides inline-execute vs
// ring-A vs ring-B push vs reject (Ghidra: [obj+4]!=0 -> inline ret -1;
// ring full -> ret 0 = silent dead-end; else slot id). MINIMAL form:
// registers only - a prior version that read guest memory here crashed the
// first invocation (fault sub_821BCB10+0x7B, the vtable-dispatch region).
PPC_FUNC_IMPL(__imp__sub_821BCB10);
static std::atomic<uint32_t> s_hBCB10{0};
PPC_FUNC(sub_821BCB10)
{
    const uint32_t n = s_hBCB10.fetch_add(1) + 1;
    const uint32_t a0 = ctx.r3.u32;
    const uint32_t a6 = ctx.r7.u32;
    __imp__sub_821BCB10(ctx, base);
    if (n <= 16 || (n % 500) == 0)
        MCLA_LOG_INFO("ENQ sub_821BCB10 #{} a0={:08X} cb={:08X} -> r3={:08X}",
                      n, a0, a6, ctx.r3.u32);
}

// INLINE-TASK-EXEC census: 0x821bc140 executes a task descriptor directly
// (the [obj+4]!=0 path). If this fires for op tag=4, the task ran inline and
// its own completion step is what silently failed.
PPC_FUNC_IMPL(__imp__sub_821BC140);
static std::atomic<uint32_t> s_hBC140{0};
PPC_FUNC(sub_821BC140)
{
    const uint32_t n = s_hBC140.fetch_add(1) + 1;
    if (n <= 16 || (n % 2000) == 0)
        MCLA_LOG_INFO("INLINE-EXEC sub_821BC140 #{} a0={:08X} a1={:08X} lr={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.lr);
    // NODE-CHAIN DUMP (session 19): the dispatched fnptr was ZERO. Walk the
    // list head a0 -> [a0+4]=node {node[0] ?, node[4]=fnptr, node[12]=next}
    // up to 3 nodes with checked reads (body starts with plain guest loads,
    // no early vtable dispatch - safe to pre-read).
    if (n <= 8)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t node = 0;
        if (mem.ReadU32BE(ctx.r3.u32 + 4, &node))
        {
            for (int i = 0; i < 3 && node != 0; ++i)
            {
                uint32_t w0 = 0, fn = 0, nx = 0;
                const bool ok0 = mem.ReadU32BE(node + 0, &w0);
                const bool okf = mem.ReadU32BE(node + 4, &fn);
                const bool okn = mem.ReadU32BE(node + 12, &nx);
                MCLA_LOG_INFO("NODE[{}] @ {:08X} w0={:08X}{} fn={:08X}{} next={:08X}{}",
                              i, node, w0, ok0 ? "" : "?", fn, okf ? "" : "?",
                              nx, okn ? "" : "?");
                node = nx;
            }
        }
    }
    __imp__sub_821BC140(ctx, base);
}

// RING-B CONSUMER census: threads #14/#15 run Function_821BC910(arg=0/1).
// Entry = thread start; RETURN = one full wait->pop->maybe-execute cycle
// completed. If returns happen but INLINE-EXEC stays 0, the consumer woke,
// popped, and SKIPPED (slot[0x60C]==0 or empty slot). If no return after the
// wake release, our host semaphore wake is broken for this handle.
PPC_FUNC_IMPL(__imp__sub_821BC910);
static std::atomic<uint32_t> s_hBC910in{0};
static std::atomic<uint32_t> s_hBC910out{0};
PPC_FUNC(sub_821BC910)
{
    const uint32_t n = s_hBC910in.fetch_add(1) + 1;
    if (n <= 8)
        MCLA_LOG_INFO("RINGB-CONSUMER sub_821BC910 ENTER #{} arg={:08X}", n, ctx.r3.u32);
    __imp__sub_821BC910(ctx, base);
    const uint32_t d = s_hBC910out.fetch_add(1) + 1;
    // Counters for BOTH consumer queues (arg 0 -> base+0, arg 1 -> +0x6174).
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t w0 = 0, p0 = 0, c0 = 0, w1 = 0, p1 = 0, c1 = 0;
        (void)mem.ReadU32BE(0x82849518u + 0x6160, &w0);
        (void)mem.ReadU32BE(0x82849518u + 0x6164, &p0);
        (void)mem.ReadU32BE(0x82849518u + 0x6168, &c0);
        (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6160, &w1);
        (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6164, &p1);
        (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6168, &c1);
        MCLA_LOG_INFO("RINGB-CONSUMER CYCLE #{} r3={:08X} q0 w/p/c={}/{}/{} q1 w/p/c={}/{}/{}",
                      d, ctx.r3.u32, w0, p0, c0, w1, p1, c1);
    }
}

// PRODUCER-PUSH census (session 16): Function_821BC868 pushes a task slot
// and releases [q+0x616C]. Queue base family = 0x82849518 + idx*0x6174 (ring
// B) / 0x8283D218 family (ring A) - both sides agree statically, so log the
// ACTUAL q pointer to see which index/instance the parked submit used.
// Register-only entry logging (crash lesson from BCB10+0x7B).
PPC_FUNC_IMPL(__imp__sub_821BC868);
static std::atomic<uint32_t> s_hBC868{0};
PPC_FUNC(sub_821BC868)
{
    const uint32_t n = s_hBC868.fetch_add(1) + 1;
    const uint32_t q = ctx.r3.u32;
    __imp__sub_821BC868(ctx, base);
    // Queue-counter dump (session 20): write idx [+0x6160], pop idx
    // [+0x6164], count [+0x6168]. Prove/disprove stale-pop: if pop idx or
    // count was non-zero BEFORE our first real push, the consumer woke on a
    // leaked increment and executed a stale zeroed slot.
    if (n <= 16 || (n % 2000) == 0)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t wIdx = 0, pIdx = 0, cnt = 0;
        const bool okW = mem.ReadU32BE(q + 0x6160, &wIdx);
        const bool okP = mem.ReadU32BE(q + 0x6164, &pIdx);
        const bool okC = mem.ReadU32BE(q + 0x6168, &cnt);
        MCLA_LOG_INFO("PUSH sub_821BC868 #{} q={:08X} wIdx={}{} pIdx={}{} cnt={}{} lr={:08X}",
                      n, q, wIdx, okW ? "" : "?", pIdx, okP ? "" : "?",
                      cnt, okC ? "" : "?", ctx.lr);
    }
}

// ---------------------------------------------------------------------------
// TU83 DRIVER-WORKER census: sub_824569C8 is the worker loop the main guest
// thread parks inside (sibling 824569C4 = empty padding stub). Its global
// block 0x827D3738: event-handle@+52 (PARK-SAMPLE saw C9ADB800),
// deadline@+128/+132, lazy-init@+184, wake flags@+188/+196/+200/+208/+212.
// Census dumps all wake-relevant fields + caller LR at entry so we can pin
// which field transition must lift the park. No direct callers exist
// module-wide => invoked as a thread entry / function pointer.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_824569C8);
static std::atomic<uint32_t> s_h569C8{0};
PPC_FUNC(sub_824569C8)
{
    const uint32_t n = s_h569C8.fetch_add(1) + 1;
    constexpr uint32_t kBlk = 0x827D3738u;
    const uint32_t lr = ctx.lr;
    uint32_t ev52 = 0, dl128 = 0, dl132 = 0, f184 = 0, f188 = 0, f196 = 0;
    uint32_t f200 = 0, f208 = 0, f212 = 0, cbTarget = 0;
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(kBlk + 52, &ev52);
        (void)mem.ReadU32BE(kBlk + 128, &dl128);
        (void)mem.ReadU32BE(kBlk + 132, &dl132);
        (void)mem.ReadU32BE(kBlk + 184, &f184);
        (void)mem.ReadU32BE(kBlk + 188, &f188);
        (void)mem.ReadU32BE(kBlk + 196, &f196);
        (void)mem.ReadU32BE(kBlk + 200, &f200);
        (void)mem.ReadU32BE(kBlk + 208, &f208);
        (void)mem.ReadU32BE(kBlk + 212, &f212);
        uint32_t cbStruct = 0;
        if (mem.ReadU32BE(0x82945A80u + 16, &cbStruct) && cbStruct != 0)
        {
            // r26 = 0x82945A80; head bctrl target lives at [r26+16] with arg [+20]
            (void)mem.ReadU32BE(cbStruct, &cbTarget);
        }
    }
    if (n <= 12 || (n % 1000) == 0)
        MCLA_LOG_INFO("WORKER sub_824569C8 #{} lr={:08X} ev={:08X} dl={:08X}/{:08X} "
                      "f184={} f188={:08X} f196={:08X} f200={:08X} f208={:08X} f212={:08X} cbt={:08X}",
                      n, lr, ev52, dl128, dl132, f184 != 0, f188, f196, f200, f208, f212, cbTarget);
    __imp__sub_824569C8(ctx, base);
}
