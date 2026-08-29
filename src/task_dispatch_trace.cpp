// Task-runner dispatch forensics (P1 + P4) - 2026-08-24 session.
//
// P1: log-only census on sub_825FDB30 (task-runner dispatch). For every
// invocation record caller LR, container, task, entry, head, node, obj, fn,
// obj+8, obj+12 - ALL via checked guest reads BEFORE passthrough. Goal:
// discriminate (A) registrar ran but this container instance has an
// uninitialized handler vs (B) the registrar/initialization path never ran.
// NO state is mutated.
//
// P4: one-shot scan of the decompressed XEX image for big-endian dwords equal
// to the family entry points (0x825FDB30 et al.) to locate the vtable/data
// table that reaches this dispatcher. Reference-only evidence; no inference.

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include <cpu/ppc_context.h>
#include "logging.h"
#include "guest_memory.h"
#include "kernel/memory.h"

#include <atomic>
#include <vector>

namespace mcla::trace {

void ScanForDispatchVtableWords(uint32_t imageBase, uint32_t imageSize)
{
    static std::atomic<bool> ran{false};
    MCLA_LOG_INFO("P4-VTSCAN begin base={:08X} size={:08X}", imageBase, imageSize);
    if (ran.exchange(true))
        return;

    // PHASE A (session 27): the crashing swf object address is deterministic
    // across runs (0x88825500). Pre-arm destination + value watches from boot
    // start so we capture allocator/constructor/registration sites, not just
    // post-dispatch state. LOG-ONLY.
    mcla::native::RegisterGuestWatchRange(0x888254F0u, 0x88825520u);
    mcla::native::RegisterGuestWatchValue(0x88825500u);
    mcla::native::RegisterGuestWatchValue(0x88825504u);
    mcla::native::RegisterGuestWatchValue(0xB7996E50u);
    mcla::native::RegisterGuestWatchValue(0x500705E0u); // session-28 miss ptr
    // Session-28: third dispatch table (sub_821DEE40 worker router).
    mcla::native::RegisterGuestWatchRange(0x821DEFD4u, 0x821DF014u);
    // FDA90 dispatch table @0x825FDAC0 reads as CODE bytes in the flat
    // image yet the dispatcher loads targets from it - watch who populates
    // it (loader relocation vs guest init).
    mcla::native::RegisterGuestWatchRange(0x825FDAC0u, 0x825FDBC4u);

    struct Target {
        uint32_t word;
        const char* name;
    };
    constexpr Target kTargets[] = {
        {0x825FDB30u, "sub_825FDB30"},
        {0x825FC5E0u, "sub_825FC5E0"},
        {0x825FA2E8u, "sub_825FA2E8"},
        {0x8260A710u, "sub_8260A710"},
        {0x8260A770u, "sub_8260A770"},
        {0x8260A7D0u, "sub_8260A7D0"},
    };

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    std::vector<uint8_t> image(imageSize);
    if (!mem.ReadBytes(imageBase, image.data(), imageSize))
    {
        MCLA_LOG_WARN("P4-VTSCAN: failed to read image {:08X}+{:08X}", imageBase, imageSize);
        return;
    }

    constexpr uint32_t kCodeBase = 0x82130000u;
    uint32_t totalHits = 0;
    for (const auto& t : kTargets)
    {
        uint32_t hits = 0;
        for (uint32_t off = 0; off + 4 <= imageSize; off += 4)
        {
            const uint32_t w =
                (uint32_t(image[off]) << 24) | (uint32_t(image[off + 1]) << 16) |
                (uint32_t(image[off + 2]) << 8) | uint32_t(image[off + 3]);
            if (w != t.word)
                continue;
            ++hits;
            ++totalHits;
            const uint32_t site = imageBase + off;
            if (hits <= 16)
            {
                // Context: the two dwords before and after the reference.
                auto rd = [&](uint32_t o) -> uint32_t {
                    if (o + 4 > imageSize)
                        return 0;
                    return (uint32_t(image[o]) << 24) | (uint32_t(image[o + 1]) << 16) |
                           (uint32_t(image[o + 2]) << 8) | uint32_t(image[o + 3]);
                };
                const bool inData = site < kCodeBase;
                MCLA_LOG_INFO(
                    "P4-VTSCAN {} ref @{:08X} [{}] ctx= {:08X} {:08X} | {:08X} | {:08X} {:08X}",
                    t.name, site, inData ? "data/vtable" : "code/literal", rd(off - 8),
                    rd(off - 4), rd(off), rd(off + 4), rd(off + 8));
            }
        }
        MCLA_LOG_INFO("P4-VTSCAN {}: {} reference(s)", t.name, hits);
    }
    MCLA_LOG_INFO("P4-VTSCAN done: {} total reference(s) over {:08X}+{:08X}", totalHits,
                  imageBase, imageSize);
}

} // namespace mcla::trace

// ---------------------------------------------------------------------------
// P1: sub_825FDB30 dispatch census (log-only).
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_825FDB30);

static std::atomic<uint32_t> s_fdb30Calls{0};

PPC_FUNC(sub_825FDB30)
{
    const uint32_t n = s_fdb30Calls.fetch_add(1) + 1;
    if (n <= 64 || n % 500 == 0)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

        const uint32_t container = ctx.r3.u32;
        const uint32_t task = ctx.r4.u32;

        uint32_t entryTable = 0;
        uint16_t idx = 0;
        uint8_t verbose = 0;
        uint32_t entry = 0, head = 0, obj = 0, fn = 0, fn8 = 0, fn12 = 0;

        (void)mem.ReadU32BE(container + 12, &entryTable);
        (void)mem.ReadU16BE(task + 164, &idx);
        (void)mem.ReadU8(task + 172, &verbose);
        entry = entryTable + (uint32_t(idx) << 3);
        (void)mem.ReadU32BE(entry + 4, &head);
        if (head != 0)
        {
            (void)mem.ReadU32BE(head, &obj);
            if (obj != 0)
            {
                (void)mem.ReadU32BE(obj + 4, &fn);
                (void)mem.ReadU32BE(obj + 8, &fn8);
                (void)mem.ReadU32BE(obj + 12, &fn12);
            }
        }

        uint32_t entryVal = 0, objVtbl = 0, nodeNext = 0, taskVtbl = 0;
        (void)mem.ReadU32BE(entry, &entryVal);
        (void)mem.ReadU32BE(task, &taskVtbl);
        if (head != 0)
        {
            (void)mem.ReadU32BE(head + 12, &nodeNext);
            (void)mem.ReadU32BE(head, &obj);
            if (obj != 0)
            {
                (void)mem.ReadU32BE(obj + 0, &objVtbl);
                (void)mem.ReadU32BE(obj + 4, &fn);
                (void)mem.ReadU32BE(obj + 8, &fn8);
                (void)mem.ReadU32BE(obj + 12, &fn12);
            }
        }

        MCLA_LOG_INFO("P1-FDB30 #{:05d} lr={:08X} cont={:08X} task={:08X} tbl={:08X} "
                      "idx={} v={} entry={:08X}/{:08X} head={:08X} next={:08X} "
                      "obj={:08X} vtbl={:08X} fn={:08X} "
                      "obj+8={:08X} obj+C={:08X}",
                      n, static_cast<uint32_t>(ctx.lr), container, task, entryTable, idx,
                      verbose, entry, entryVal, head, nodeNext, obj, objVtbl, fn,
                      fn8, fn12);

        // Arm a write-watch on empty method blocks: every guest store into
        // [obj, obj+16) is logged with value + caller LR. Deterministic site
        // (obj=88825500 across runs) => catches the missing initializer live.
        if (obj != 0 && fn == 0 && fn8 == 0 && fn12 == 0)
        {
            static std::atomic<uint32_t> s_armed{0};
            const uint32_t armed = s_armed.fetch_add(1) + 1;
            if (armed <= 4)
            {
                mcla::native::RegisterGuestWatchRange(obj, obj + 16);
                MCLA_LOG_WARN("P1-WATCH-ARMED #{} obj={:08X}", armed, obj);
            }
            // Neighborhood dump: is this a skipped construction inside a pool
            // of otherwise-valid swf objects, or raw untyped memory?
            auto rd = [&](uint32_t a) {
                uint32_t v = 0;
                (void)mem.ReadU32BE(a, &v);
                return v;
            };
            uint8_t typeByte = 0;
            (void)mem.ReadU8(head + 4, &typeByte);
            MCLA_LOG_WARN(
                "P1-OBJWIN head={:08X} type={:02X} | obj-16:{:08X} {:08X} "
                "| obj:{:08X} {:08X} {:08X} {:08X} | obj+16:{:08X} {:08X} "
                "{:08X} {:08X} | +32:{:08X} {:08X} +48:{:08X}",
                head, typeByte, rd(obj - 16), rd(obj - 12), rd(obj), rd(obj + 4),
                rd(obj + 8), rd(obj + 12), rd(obj + 16), rd(obj + 20),
                rd(obj + 24), rd(obj + 28), rd(obj + 32), rd(obj + 36),
                rd(obj + 44), rd(obj + 48));
        }
    }

    __imp__sub_825FDB30(ctx, base);
}

// ---------------------------------------------------------------------------
// P8: FDA90 tag-dispatcher census. r3=object, tag=u8[obj+8], case=tag-1,
// target loaded from table @0x825FDAC0+case*4. Logs the raw table dword so
// we can see whether targets are valid code pointers at runtime.
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// FIX (session 27): XenonRecomp failed to recover the relocation-populated
// jump tables for these two dispatchers - emitted switch bodies contain ONLY
// "// ERROR: <target>" + return (124.cpp:10971-11001, 125.cpp:10204-10222;
// 1571 such sites image-wide). Every indirect dispatch through them was a
// silent no-op: swf display-list nodes never received their class vtbls ->
// ctr=0 bctrl crash in sub_825FDB30.
//
// Repair = exact HW semantics: ctr = table[type]; bctr, with register state
// at branch = (r3=node, r4=type-byte, r11=group). This build compiles with
// PPC_CONFIG_NON_ARGUMENT_AS_LOCAL so r11 does not exist in PPCContext; the
// handlers are therefore invoked at their TAIL targets with (r3=node,
// r4=group) - bit-faithful for every worker (verified: workers read only
// r3/r4 + stack; thunks' `mr r4,r11` is the compile artifact being repaired).
// Targets come from the runtime-relocated tables - nothing invented.
// Error tags on HW enter sub_821BD618's deliberate `b .` loop (fnptr slot
// 0x8285FEA0 is zero in this title); the regenerated dispatchers no longer
// need any of that - see Session-28 FINAL notes at each hook.
// ---------------------------------------------------------------------------

// sub_825FDA90(group=r3, object=r4): tag=u8[object+8]; table @0x825FDAC0.
PPC_FUNC_IMPL(__imp__sub_825FDA90);
static std::atomic<uint32_t> s_hFDA90{0};
PPC_FUNC(sub_825FDA90)
{
    const uint32_t n = s_hFDA90.fetch_add(1) + 1;
    const uint32_t group = ctx.r3.u32; (void)group;
    const uint32_t node = ctx.r4.u32;

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint8_t tag = 0;
    (void)mem.ReadU8(node + 8, &tag);

    // First dispatch => relocations applied; snapshot all three tables.
    if (n == 1)
    {
        auto dumpTable = [&](const char* name, uint32_t base, uint32_t count) {
            for (uint32_t i = 0; i < count; ++i)
            {
                uint32_t w = 0;
                (void)mem.ReadU32BE(base + i * 4, &w);
                MCLA_LOG_INFO("TBL {} [{:02}] @{:08X} = {:08X}", name, i,
                              base + i * 4, w);
            }
        };
        dumpTable("FDA90", 0x825FDAC0u, 9);
        dumpTable("B588", 0x8260B5B4u, 5);
        dumpTable("DEE40", 0x821DEFD4u, 16);
    }

    if (n <= 48 || (n % 1000) == 0)
    {
        MCLA_LOG_INFO("P8-FDA90 #{:05} obj={:08X} tag={:02X} lr={:08X}", n, node,
                      tag, static_cast<uint32_t>(ctx.lr));
    }

    // Session-28 FINAL: dispatch override removed - the regenerated
    // __imp__ body performs the real in-function goto switch.
    __imp__sub_825FDA90(ctx, base);
}

// sub_8260B588(group=r3, node=r4): type=u8[node+4]; table @0x8260B5B4.
PPC_FUNC_IMPL(__imp__sub_8260B588);
static std::atomic<uint32_t> s_hB588{0};
PPC_FUNC(sub_8260B588)
{
    const uint32_t n = s_hB588.fetch_add(1) + 1;
    const uint32_t group = ctx.r3.u32; (void)group;
    const uint32_t node = ctx.r4.u32;

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint8_t type = 0;
    (void)mem.ReadU8(node + 4, &type);

    uint32_t v0 = 0;
    (void)mem.ReadU32BE(node, &v0);
    const bool watch = node >= 0xB7996E40u && node <= 0xB7996E60u;
    if (n <= 64 || (n % 2000) == 0 || watch)
    {
        MCLA_LOG_INFO("P9-B588 #{:05} node={:08X} type={:02X} [0]={:08X}{}", n,
                      node, type, v0, watch ? "  <<< CRASH-NODE" : "");
    }

    // Session-28 FINAL: dispatch override removed - regenerated body
    // performs the real in-function goto switch.
    __imp__sub_8260B588(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8260B510);
static std::atomic<uint32_t> s_hB510{0};
PPC_FUNC(sub_8260B510)
{
    const uint32_t n = s_hB510.fetch_add(1) + 1;
    const uint32_t node = ctx.r3.u32;
    const bool watch = node >= 0xB7996E40u && node <= 0xB7996E60u;
    if (n <= 64 || (n % 2000) == 0 || watch)
    {
        MCLA_LOG_INFO("P9-B510 #{:05} node={:08X}{}", n, node,
                      watch ? "  <<< CRASH-NODE" : "");
    }
    __imp__sub_8260B510(ctx, base);
    if (watch)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t v0a = 0;
        (void)mem.ReadU32BE(node, &v0a);
        MCLA_LOG_WARN("P9-B510-POST node={:08X} [0]={:08X}  <<< CRASH-NODE", node,
                      v0a);
    }
}

// ---------------------------------------------------------------------------
// P5: relocation-resolver census. The container build pass
// (FDBF8 -> A830) rebases node pointers via primary lookup sub_8217D828;
// misses fall back to named resolver sub_821D2378. Runtime fact: one node's
// [node+0] was rewritten to heap-zeroed 88825500 where an .rdata vtable
// belongs -> dispatch crash. These censuses catch the exact miss/rewrite.
// LOG-ONLY.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_8217D828);
static std::atomic<uint32_t> s_h17D828{0};
PPC_FUNC(sub_8217D828)
{
    const uint32_t n = s_h17D828.fetch_add(1) + 1;
    const uint32_t a3 = ctx.r3.u32;
    const uint32_t a4 = ctx.r4.u32;
    const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);
    __imp__sub_8217D828(ctx, base);
    if (n <= 16 || (n % 20000) == 0)
    {
        MCLA_LOG_INFO("P5-LOOKUP #{:06} r3={:08X} r4={:08X} -> {:08X} lr={:08X}",
                      n, a3, a4, ctx.r3.u32, lrIn);
    }
}

PPC_FUNC_IMPL(__imp__sub_821D2378);
static std::atomic<uint32_t> s_h1D2378{0};
PPC_FUNC(sub_821D2378)
{
    const uint32_t n = s_h1D2378.fetch_add(1) + 1;
    const uint32_t desc = ctx.r3.u32;
    const uint32_t a4 = ctx.r4.u32;
    const uint32_t a5 = ctx.r5.u32;
    const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);
    // LOG FIRST: the fallback body dereferences [desc+8] unchecked-style and
    // has already AV'd on garbage descriptors - post-call logging never ran.
    MCLA_LOG_WARN("P5-MISSFIX #{:05} desc={:08X} a4={:08X} old={:08X} lr={:08X} "
                  "r13={:08X}",
                  n, desc, a4, a5, lrIn, ctx.r13.u32);
    __imp__sub_821D2378(ctx, base);
}

// ---------------------------------------------------------------------------
// P10 (session 28): delta-provider census with FULL region-table dump on
// any membership miss. sub_8217D890(heapGroup=r3, oldAddr=r4) -> delta or
// -1 (then falls back to 821D2378). Entry layout (TU-verified): stride 12,
// {dupBase@+0, oldBase@+4, newBase@+8}; membership base..base+[ent+8];
// delta = newBase-oldBase. Goal: prove WHY 0x500705E0 misses its region.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_8217D890);
static std::atomic<uint32_t> s_h17D890{0};
PPC_FUNC(sub_8217D890)
{
    const uint32_t n = s_h17D890.fetch_add(1) + 1;
    const uint32_t group = ctx.r3.u32;
    const uint32_t oldAddr = ctx.r4.u32;

    __imp__sub_8217D890(ctx, base);

    const int32_t res = static_cast<int32_t>(ctx.r3.u32);
    const bool watched =
        (oldAddr & 0xFFFF0000u) == 0x50070000u || oldAddr == 0x50035E50u;
    if (res != -1 && !watched)
    {
        return; // healthy rebase - silent
    }

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t regions = 0;
    (void)mem.ReadU32BE(group, &regions);
    uint16_t cntA = 0, cntB = 0;
    (void)mem.ReadU16BE(regions + 0, &cntA);
    (void)mem.ReadU16BE(regions + 2, &cntB);
    MCLA_LOG_WARN("P10-D890 #{:06} {} group={:08X} regions={:08X} counts={}/{} "
                  "old={:08X} -> {:08X} lr={:08X}",
                  n, res == -1 ? "MISS" : "WATCH", group, regions, cntA, cntB,
                  oldAddr, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
    if (regions != 0)
    {
        constexpr uint32_t kMaxDump = 24;
        for (uint32_t i = 0; i < kMaxDump; ++i)
        {
            uint32_t dupBase = 0, oldBase = 0, newBase = 0;
            (void)mem.ReadU32BE(regions + i * 12, &dupBase);
            (void)mem.ReadU32BE(regions + i * 12 + 4, &oldBase);
            (void)mem.ReadU32BE(regions + i * 12 + 8, &newBase);
            if (dupBase == 0 && oldBase == 0 && newBase == 0)
            {
                break;
            }
            MCLA_LOG_WARN("P10-REGION [{:02}] dup={:08X} old={:08X} new={:08X} "
                          "span-end={:08X} delta={:08X}",
                          i, dupBase, oldBase, newBase, dupBase + newBase,
                          newBase - oldBase);
        }
    }
}

// ---------------------------------------------------------------------------
// Session-28: sub_821DEE40 worker-router census. Its jump table
// @0x821DEFD4 is relocation/runtime-populated; first call dumps entries so
// regen-grade labels can be captured. Also exposes kind arg + result.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_821DEE40);
static std::atomic<uint32_t> s_hDEE40{0};
PPC_FUNC(sub_821DEE40)
{
    const uint32_t n = s_hDEE40.fetch_add(1) + 1;
    if (n == 1)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        for (uint32_t i = 0; i < 32; ++i)
        {
            uint32_t w = 0;
            (void)mem.ReadU32BE(0x821DEFD4u + i * 4u, &w);
            MCLA_LOG_INFO("TBL DEE40 [{:02}] @{:08X} = {:08X}", i,
                          0x821DEFD4u + i * 4u, w);
        }
    }
    if (n <= 24 || (n % 2000) == 0)
    {
        MCLA_LOG_INFO("P11-DEE40 #{:05} r3={:08X} kind={} lr={:08X}", n,
                      ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
    }
    __imp__sub_821DEE40(ctx, base);
}



// ---------------------------------------------------------------------------
// P6 (session 26): container-build fixup walker census + node-slot watches.
// rebases each node's [node+0] (an .rdata vtable pointer) by the region
// delta. Runtime fact: one rewritten node[0]=88825500 lands in zeroed heap
// -> dispatch crash. Arming a write-watch on every walked node slot catches
// the rewriting instruction with caller LR, plus dumps the chain shape.
// LOG-ONLY.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_8260A830);
static std::atomic<uint32_t> s_hA830{0};
PPC_FUNC(sub_8260A830)
{
    const uint32_t n = s_hA830.fetch_add(1) + 1;
    const uint32_t bucket = ctx.r3.u32;
    const uint32_t buildCtx = ctx.r4.u32;
    if (n <= 48)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t head = 0;
        uint32_t e0 = 0;
        (void)mem.ReadU32BE(bucket, &e0);
        (void)mem.ReadU32BE(bucket + 4, &head);
        MCLA_LOG_INFO("P6-FIXWALK #{:03} bucket={:08X} [0]={:08X} head={:08X}", n,
                      bucket, e0, head);
        uint32_t node = head;
        for (int i = 0; i < 4 && node != 0; ++i)
        {
            uint32_t v0 = 0;
            (void)mem.ReadU32BE(node, &v0);
            MCLA_LOG_INFO("P6-FIXWALK   node={:08X} [0]={:08X}", node, v0);
            mcla::native::RegisterGuestWatchRange(node, node + 4);
            uint32_t next = 0;
            (void)mem.ReadU32BE(node + 12, &next);
            node = next;
        }
    }
    __imp__sub_8260A830(ctx, base);
}

