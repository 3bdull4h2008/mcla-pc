#include "gpu_device.h"

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "logging.h"
#include "kernel/memory.h"

#include <atomic>

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
