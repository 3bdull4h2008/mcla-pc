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
#include "patches.h"

#include <atomic>
#include <vector>

// w9: PSTREAM virtual→physical map published by gpu_device.cpp at RSC-HEAD
// parse. sub_8217D890 uses it to resolve leftover 0x50xxxxxx virtuals.
struct MclaRebaseRegion {
    uint32_t vbase, pbase, size;
};
extern MclaRebaseRegion g_mclaRebaseMap[];
extern int g_mclaRebaseCount;

// w24: place-pass Resource-fatal gates (defined in gpu_device.cpp).
extern bool MclaPtrIsGateBad(uint32_t p);
extern bool MclaPtrInRebaseMap(uint32_t p);
extern void MclaCompleteRscRebaseBeforePlace(uint32_t obj);
// w32: open FDA90 walk bound when +24 holds dest-range/SWF-tag candidates.
extern bool MclaW32OpenConstructWalk(uint32_t obj, uint32_t stack,
                                     bool redispatch);

// w15: nested 5500-family resource heads observed by FDBF8-build as CHILDREN
// (lr=825EF1FC). Guest place-pass 825EF100 converts these to 8208xxxx when
// run as ROOT (proven: 44495500→82085364 on B7B41000, D0815500→82088784 on
// B7B61000) but children only get FDBF8-build, so vt stays C4445500/D0815500.
// Record objects here; gpu_device.cpp re-dispatches the guest place-pass on
// them after the root ARR-RERUN. Never invent a vtable.
constexpr int kMclaNestedPlaceMax = 24;
uint32_t g_mclaNestedPlaceObj[kMclaNestedPlaceMax] = {};
int g_mclaNestedPlaceN = 0;

static void MclaNoteNestedPlaceCand(uint32_t obj, uint32_t vt)
{
    if (obj == 0 || obj == 0xCDCDCDCDu)
        return;
    // Family marker: low 16 bits 0x5500 (RSC/resource head), not already
    // an image/swfC vtable.
    if ((vt & 0xFFFFu) != 0x5500u)
        return;
    if ((vt & 0xFFF00000u) == 0x82000000u)
        return;
    for (int i = 0; i < g_mclaNestedPlaceN; ++i)
        if (g_mclaNestedPlaceObj[i] == obj)
            return;
    if (g_mclaNestedPlaceN >= kMclaNestedPlaceMax)
        return;
    g_mclaNestedPlaceObj[g_mclaNestedPlaceN++] = obj;
}

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
    // w25: PAGEWATCH family for swfC / display-list place-write census.
    mcla::native::RegisterGuestWatchValue(0x8208883Cu);
    mcla::native::RegisterGuestWatchValue(0x8208521Cu);
    mcla::native::RegisterGuestWatchValue(0x82085364u);
    mcla::native::RegisterGuestWatchValue(0x82085784u);
    mcla::native::RegisterGuestWatchValue(0x82088784u); // w31: B7B61000 family
    mcla::native::RegisterGuestWatchRange(0x82088800u, 0x82088900u);
    mcla::native::RegisterGuestWatchRange(0x82085200u, 0x82085400u);
    mcla::native::RegisterGuestWatchRange(0xB7B6D9B0u, 0xB7B6DA00u);
    mcla::native::RegisterGuestWatchRange(0xB7B41000u, 0xB7B41040u);
    // w31: dest-range leads — catch guest child-vt writes into rebased
    // PSTREAM nodes (B7984DE0 / B79B0C20 family) after fill+place.
    mcla::native::RegisterGuestWatchRange(0xB7984DE0u, 0xB7984E20u);
    mcla::native::RegisterGuestWatchRange(0xB79B0C20u, 0xB79B0C60u);
    mcla::native::RegisterGuestWatchRange(0xB79BE0F0u, 0xB79BE130u);
    mcla::native::RegisterGuestWatchRange(0xB7B6CC00u, 0xB7B6CC40u);
    mcla::native::RegisterGuestWatchRange(0xB7988D10u, 0xB7988D50u);
    mcla::native::RegisterGuestWatchRange(0xB7B6BF60u, 0xB7B6BFA0u);
    mcla::native::RegisterGuestWatchRange(0xB7B6C6E0u, 0xB7B6C720u);
    mcla::native::RegisterGuestWatchRange(0xB7B67C60u, 0xB7B67CA0u);
    mcla::native::RegisterGuestWatchRange(0xB7B6C8C0u, 0xB7B6C900u);
    mcla::native::RegisterGuestWatchRange(0xB79E1000u, 0xB79E1040u);
    mcla::native::RegisterGuestWatchRange(0xB7981000u, 0xB7981040u);
    mcla::native::RegisterGuestWatchRange(0xB79A1000u, 0xB79A1040u);
    mcla::native::RegisterGuestWatchRange(0xB7B61000u, 0xB7B61040u);
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
    const uint32_t container = ctx.r3.u32;
    const uint32_t task = ctx.r4.u32;
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    // p2f: poison containers (the never-filled preload buffers, e.g.
    // B7B41000 with vt/arr=CDCDCDCD) made the unchecked pointer math in
    // both the census below AND the original body read unmapped guest
    // addresses (entryTable=CDCD + idx<<3) — the vectored-handler AV
    // storm at 2+ minutes (crash rva=0x121BF5, caught but noisy).
    // Empty dispatch for poison containers.
    {
        uint32_t arr = 0;
        const bool dead =
            container == 0 || container == 0xCDCDCDCDu || task == 0 ||
            task == 0xCDCDCDCDu ||
            (!mem.ReadU32BE(container + 12, &arr) ||
             (arr & 0xFFFF0000u) == 0xCDCD0000u);
        if (dead)
        {
            static std::atomic<uint32_t> s_fdb30Dead{0};
            const uint32_t dn = s_fdb30Dead.fetch_add(1) + 1;
            if (dn <= 16 || (dn % 500) == 0)
                MCLA_LOG_WARN("FDB30-DEAD #{:03} cont={:08X} task={:08X} "
                              "lr={:08X} (poison container — empty dispatch)",
                              dn, container, task,
                              static_cast<uint32_t>(ctx.lr));
            return;
        }
    }

    if (n <= 64 || n % 500 == 0)
    {
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
// w31: FDA90 type-write census — who constructs child swfC?
static std::atomic<uint32_t> s_fda90TagHist[16] = {};
static std::atomic<uint32_t> s_fda90WroteVt{0};
static std::atomic<uint32_t> s_fda90Gated{0};
static std::atomic<uint32_t> s_fda90Passed{0};
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

    uint32_t v0 = 0;
    (void)mem.ReadU32BE(node, &v0);
    const bool gateBad = node != 0 && MclaPtrIsGateBad(node);
    // Guest body: type=u8[node+8]; case=type-1; case>8 → fatal unknown type.
    // Valid types are 1..9. Gate garbage from the 44495500 place walk so
    // EF100 can finish and write the real swfC vtable (never invent one).
    const bool unknownType = (tag < 1u || tag > 9u);
    const bool unreadable = node == 0 || node == 0xCDCDCDCDu;
    if (n <= 48 || (n % 1000) == 0 || gateBad || unknownType)
    {
        MCLA_LOG_INFO("P8-FDA90 #{:05} obj={:08X} tag={:02X} [0]={:08X} "
                      "lr={:08X}{}{}{}",
                      n, node, tag, v0, static_cast<uint32_t>(ctx.lr),
                      gateBad ? " GATE-BAD" : "",
                      unknownType ? " UNKNOWN-TYPE" : "",
                      unreadable ? " UNREADABLE" : "");
    }
    if (unreadable || gateBad || unknownType)
    {
        s_fda90Gated.fetch_add(1);
        MCLA_LOG_WARN("FDA90-GATE #{:05} node={:08X} tag={:02X} [0]={:08X} "
                      "lr={:08X} — skip fixup dispatch (place-walk garbage)",
                      n, node, tag, v0, static_cast<uint32_t>(ctx.lr));
        return;
    }

    // w31: valid type 1..9 — census what the guest body writes.
    s_fda90Passed.fetch_add(1);
    if (tag < 16u)
        s_fda90TagHist[tag].fetch_add(1);
    const uint32_t v0Before = v0;

    // Session-28 FINAL: dispatch override removed - the regenerated
    // __imp__ body performs the real in-function goto switch.
    __imp__sub_825FDA90(ctx, base);

    // w31: post-dispatch census — did the type handler write a real swfC
    // vtable onto the node? Never invent one; only report what guest wrote.
    {
        uint32_t v0After = 0;
        (void)mem.ReadU32BE(node, &v0After);
        const bool wroteVt = (v0After & 0xFFFF0000u) == 0x82080000u;
        const bool changed = v0After != v0Before;
        if (wroteVt)
            s_fda90WroteVt.fetch_add(1);
        if (wroteVt || changed || n <= 32)
        {
            uint32_t nw[6] = {0};
            for (int k = 0; k < 6; ++k)
                (void)mem.ReadU32BE(node + static_cast<uint32_t>(k * 4),
                                    &nw[k]);
            MCLA_LOG_WARN("W31-FDA90 #{:05} node={:08X} tag={:02X} "
                          "[0] {:08X}->{:08X} wroteVt={} "
                          "[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}] "
                          "lr={:08X}",
                          n, node, tag, v0Before, v0After, wroteVt ? 1 : 0,
                          nw[0], nw[1], nw[2], nw[3], nw[4], nw[5],
                          static_cast<uint32_t>(ctx.lr));
        }
    }
    if ((n % 200) == 0)
    {
        MCLA_LOG_WARN("W31-FDA90-SUM n={} passed={} gated={} wroteVt={} "
                      "t1={} t2={} t3={} t4={} t5={} t6={} t7={} t8={} t9={}",
                      n, s_fda90Passed.load(), s_fda90Gated.load(),
                      s_fda90WroteVt.load(),
                      s_fda90TagHist[1].load(), s_fda90TagHist[2].load(),
                      s_fda90TagHist[3].load(), s_fda90TagHist[4].load(),
                      s_fda90TagHist[5].load(), s_fda90TagHist[6].load(),
                      s_fda90TagHist[7].load(), s_fda90TagHist[8].load(),
                      s_fda90TagHist[9].load());
    }
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
    // w24: never dispatch the type-table body on an unmapped gate-bad node
    // (41C4FF12 / 533D00CB from the 44495500 place walk).
    const bool gate = node != 0 && MclaPtrIsGateBad(node);
    if (n <= 64 || (n % 2000) == 0 || watch || gate)
    {
        MCLA_LOG_INFO("P9-B588 #{:05} node={:08X} type={:02X} [0]={:08X}{}{}",
                      n, node, type, v0, watch ? "  <<< CRASH-NODE" : "",
                      gate ? " GATE-SKIP" : "");
    }
    if (gate)
        return;

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
// Session 72: pointer-rebase via sub_821B5A60(&addr) → sub_8217D890(group,*addr).
// Probe: id=0xCDCDCDCD (uninitialized object field) → lookup miss → fatal
// "Resource 'meshtextures'". Caller lr=0x821B5AB4. Honest short-circuit:
// poison is not a valid guest pointer — take the same *param=0 path the
// function already uses on membership miss. Do NOT invent a resource size.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_821B5A60);
static std::atomic<uint32_t> s_hB5A60{0};
static std::atomic<uint32_t> s_hB5A60poison{0};
PPC_FUNC(sub_821B5A60)
{
    const uint32_t n = s_hB5A60.fetch_add(1) + 1;
    const uint32_t param = ctx.r3.u32;
    uint32_t val = 0;
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(param, &val);
    }
    if ((val & 0xFFu) == 0xCDu)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        const uint32_t p = s_hB5A60poison.fetch_add(1) + 1;
        // Session 73: name the producer. The element was 0xCD-filled on
        // alloc; the ring census knows who received it.
        uint32_t elem = 0, prodLr = 0, esz = 0;
        const bool known = mcla_SlimTslabFind(param, &elem, &prodLr, &esz);
        MCLA_LOG_WARN("REBASE-POISON #{:05} n={} param={:08X} val={:08X} -> 0 "
                      "lr={:08X} (skip D890 fatal) prod={} elem={:08X} es={} "
                      "prodLr={:08X}",
                      p, n, param, val, static_cast<uint32_t>(ctx.lr),
                      known ? "Y" : "N", elem, esz, prodLr);
        // Session 73: dump the surrounding record so the poison scope is
        // visible (one 0x70-stride field vs a fully uninit element).
        if (p <= 3)
        {
            const uint32_t base = param & ~0xFu;
            for (uint32_t row = 0; row < 8; ++row)
            {
                uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
                (void)mem.ReadU32BE(base + row * 16 + 0, &w0);
                (void)mem.ReadU32BE(base + row * 16 + 4, &w1);
                (void)mem.ReadU32BE(base + row * 16 + 8, &w2);
                (void)mem.ReadU32BE(base + row * 16 + 12, &w3);
                MCLA_LOG_WARN("  POISON-DUMP {:08X}: {:08X} {:08X} {:08X} {:08X}",
                              base + row * 16, w0, w1, w2, w3);
            }
        }
        (void)mem.WriteU32BE(param, 0);
        return;
    }
    __imp__sub_821B5A60(ctx, base);
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
    const bool poison = (a4 & 0xFFu) == 0xCDu;
    // w24 census on the 44495500 place-pass path (A830 / 84458 callers).
    const bool placePath =
        lrIn == 0x8260A878u || lrIn == 0x821844D8u || lrIn == 0x8260A830u;
    const bool gate = MclaPtrIsGateBad(a4);
    if (n <= 16 || (n % 20000) == 0 || poison || gate || placePath)
    {
        MCLA_LOG_INFO("P5-LOOKUP #{:06} r3={:08X} r4={:08X} -> {:08X} lr={:08X}"
                      "{}{}{}",
                      n, a3, a4, ctx.r3.u32, lrIn, poison ? " POISON" : "",
                      gate ? " GATE-BAD" : "",
                      placePath ? " PLACE-44495500" : "");
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
    // w13: throttle — unthrottled flood made place take 41s (same as P10-PHYS).
    if (n <= 32 || (n % 500) == 0)
        MCLA_LOG_WARN("P5-MISSFIX #{:05} desc={:08X} a4={:08X} old={:08X} lr={:08X} "
                      "r13={:08X}",
                      n, desc, a4, a5, lrIn, ctx.r13.u32);
    // w9: this is the "resource group miss → fatal" tail (b 821BD618). After
    // our RSC-NEST walk rewrote 0x50xxxxxx virtual ptrs to physical dests
    // (e.g. 50035E50 → B7996E50), the place-pass still asks the guest rebase
    // table about the ALREADY-PHYSICAL address, misses, and fatals. The
    // caller 8260A830 (loc_8260A8A0) expects either a fatal OR a return that
    // falls into `li r11,0` / loc_8260A8B4 — delta 0, pointer already final.
    // Return without invoking the fatal for those.
    const bool alreadyPhys =
        (a5 >= 0xB7000000u && a5 < 0xB8000000u) ||
        (a5 >= 0xA47F0000u && a5 < 0xA4800000u) ||
        (a5 >= 0x80000000u); // w24: image + all high phys → delta-0
    if (alreadyPhys)
    {
        if (n <= 32 || (n % 500) == 0)
            MCLA_LOG_WARN("P5-PHYS #{:05} old={:08X} lr={:08X} — already "
                          "physical, skip fatal (caller takes delta-0 path)",
                          n, a5, lrIn);
        ctx.r3.u32 = 0;
        return;
    }
    // w11: unmapped PSTREAM-family virtual (e.g. 5001CE90 in the package
    // head before the corrected {vbase,pbase,size} parse). Returning 0
    // takes the same delta-0 path alreadyPhys uses so place-pass can
    // finish; nest walk + P10-MAP rewrite the ones we can resolve.
    if (a5 >= 0x50000000u && a5 < 0x70000000u)
    {
        bool mapped = false;
        for (int i = 0; i < g_mclaRebaseCount; ++i)
        {
            const uint32_t vb = g_mclaRebaseMap[i].vbase;
            const uint32_t sz = g_mclaRebaseMap[i].size;
            if (sz != 0 && a5 >= vb && a5 < vb + sz)
            {
                mapped = true;
                break;
            }
        }
        if (n <= 32 || (n % 500) == 0)
            MCLA_LOG_WARN("P5-VIRT #{:05} old={:08X} lr={:08X} mapped={} — "
                          "skip fatal, delta-0",
                          n, a5, lrIn, mapped ? 1 : 0);
        ctx.r3.u32 = 0;
        return;
    }
    // w24: gate bad ptrs not in 0x50/0x60/0x80-B phys map (w23: 41C4FF12 /
    // 533D00CB from the 44495500 place walk). Delta-0 family — A830/84458
    // already do `li r11,0` after D2378 returns, so place continues.
    if (MclaPtrIsGateBad(a5))
    {
        MCLA_LOG_WARN("P5-GATE #{:05} old={:08X} lr={:08X} — not in "
                      "0x50/0x60/0x80-B map, delta-0 (no Resource fatal)",
                      n, a5, lrIn);
        ctx.r3.u32 = 0;
        return;
    }
    __imp__sub_821D2378(ctx, base);
}

// ---------------------------------------------------------------------------
// w11: sub_82184458 place-pass resource walker. It D890-rebases [this+24] /
// [this+28], then D828-looks-up the page at [resource+32] against the guest
// region table. Job #2 left 600E0000 (PSTREAM s[12] → B70A1000) there; the
// empty group table misses and D2378 fatals "Resource '%s': %s (ptr=%p)".
// Pre-rebase +32 through g_mclaRebaseMap so the miss path sees physical
// (alreadyPhys / delta-0) and the walker keeps the final pointer.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82184458);
static std::atomic<uint32_t> s_h84458{0};
PPC_FUNC(sub_82184458)
{
    const uint32_t n = s_h84458.fetch_add(1) + 1;
    const uint32_t thisObj = ctx.r3.u32;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t res = 0;
    uint32_t f0 = 0, f24 = 0, f28 = 0;
    if (thisObj != 0 && thisObj != 0xCDCDCDCDu)
    {
        (void)mem.ReadU32BE(thisObj + 0, &f0);
        (void)mem.ReadU32BE(thisObj + 24, &f24);
        (void)mem.ReadU32BE(thisObj + 28, &f28);
    }
    // w24: complete +24/+28/+32 rebase through g_mclaRebaseMap BEFORE the
    // guest body D890/D828-walks them (44495500 RSC-head path).
    const auto isPstreamVirt = [](uint32_t p) -> bool {
        return p >= 0x50000000u && p < 0x70000000u;
    };
    auto rebaseField = [&](uint32_t addr, uint32_t val, const char *tag) {
        if (val == 0 || !isPstreamVirt(val))
            return val;
        for (int i = 0; i < g_mclaRebaseCount; ++i)
        {
            const uint32_t vbase = g_mclaRebaseMap[i].vbase;
            const uint32_t size = g_mclaRebaseMap[i].size;
            if (size == 0)
                continue;
            if (val >= vbase && val < vbase + size)
            {
                const uint32_t np =
                    g_mclaRebaseMap[i].pbase + (val - vbase);
                (void)mem.WriteU32BE(addr, np);
                MCLA_LOG_WARN(
                    "P5-84458-REBASE #{} obj={:08X} {} @{:08X} "
                    "{:08X} -> {:08X} vbase={:08X} lr={:08X}",
                    n, thisObj, tag, addr, val, np, vbase,
                    static_cast<uint32_t>(ctx.lr));
                return np;
            }
        }
        return val;
    };
    if (thisObj != 0 && thisObj != 0xCDCDCDCDu && g_mclaRebaseCount > 0)
    {
        f24 = rebaseField(thisObj + 24, f24, "+24");
        f28 = rebaseField(thisObj + 28, f28, "+28");
        if (f28 != 0 && f28 != 0xCDCDCDCDu)
        {
            (void)mem.ReadU32BE(thisObj + 28, &res);
            uint32_t page = 0;
            if (mem.ReadU32BE(res + 32, &page))
            {
                const uint32_t np2 = rebaseField(res + 32, page, "+32");
                (void)np2;
            }
        }
    }
    // Census when the walker is on a 44495500-family head.
    const bool rsc =
        (f0 & 0xFFFFFF00u) == 0x44495500u ||
        (f0 & 0xFFFFFF00u) == 0x44365500u || (f0 & 0xFFFFu) == 0x5500u;
    if (n <= 16 || rsc || (n % 200) == 0)
    {
        uint32_t page = 0, arr = 0, arr0 = 0;
        if (f28 != 0 && f28 != 0xCDCDCDCDu)
        {
            (void)mem.ReadU32BE(f28 + 32, &page);
            (void)mem.ReadU32BE(f28 + 12, &arr);
            if (arr != 0 && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
                (void)mem.ReadU32BE(arr, &arr0);
        }
        MCLA_LOG_WARN("P5-84458-CENSUS #{:05} obj={:08X} vt={:08X} "
                      "+24={:08X} +28={:08X} res+32={:08X} arr={:08X} "
                      "[arr]={:08X} rsc={} lr={:08X}{}",
                      n, thisObj, f0, f24, f28, page, arr, arr0,
                      rsc ? 1 : 0, static_cast<uint32_t>(ctx.lr),
                      MclaPtrIsGateBad(page) || MclaPtrIsGateBad(arr0)
                          ? " GATE-BAD"
                          : "");
    }
    if (thisObj != 0 && g_mclaRebaseCount > 0 &&
        mem.ReadU32BE(thisObj + 28, &res) && res != 0 &&
        res != 0xCDCDCDCDu && res != 0xFFFFFFFFu)
    {
        uint32_t page = 0;
        if (mem.ReadU32BE(res + 32, &page) && page >= 0x50000000u &&
            page < 0x70000000u)
        {
            for (int i = 0; i < g_mclaRebaseCount; ++i)
            {
                const uint32_t vbase = g_mclaRebaseMap[i].vbase;
                const uint32_t size = g_mclaRebaseMap[i].size;
                if (size == 0)
                    continue;
                if (page >= vbase && page < vbase + size)
                {
                    const uint32_t np =
                        g_mclaRebaseMap[i].pbase + (page - vbase);
                    (void)mem.WriteU32BE(res + 32, np);
                    MCLA_LOG_WARN(
                        "P5-84458-REBASE #{} obj={:08X} res={:08X} "
                        "+32 {:08X} -> {:08X} vbase={:08X} lr={:08X}",
                        n, thisObj, res, page, np, vbase,
                        static_cast<uint32_t>(ctx.lr));
                    break;
                }
            }
        }
    }
    __imp__sub_82184458(ctx, base);
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
    const uint32_t lrIn = static_cast<uint32_t>(ctx.lr);

    // Session 72: log BEFORE passthrough. On id=0xCDCDCDCD the original
    // body calls sub_821D2378 which fatals and never returns — post-call
    // census stays silent. Pre-call log names the caller.
    if ((oldAddr & 0xFFu) == 0xCDu || oldAddr == 0xFFFFFFFFu)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t tablePtr = 0;
        (void)mem.ReadU32BE(group, &tablePtr);
        MCLA_LOG_WARN("P10-PRE #{:06} id={:08X} group={:08X} table={:08X} "
                      "lr={:08X}",
                      n, oldAddr, group, tablePtr, lrIn);
        // Skip the original body: it fatals on this id. Return 0 (same as
        // the miss path after fatal) without invoking the fatal dispatcher.
        ctx.r3.u32 = 0;
        return;
    }

    // w7: pointers already in the B7 physical heap (post-RSC-REBASE) have
    // no entry in the rebase group — the original body fatals via
    // 821D2378 "Resource '%s'". Return delta 0: the pointer is already at
    // its final physical address. w9: also accept the A47F9xxx dest that
    // job #2 PSTREAM s[4] maps (physical page in the A47F scratch range).
    // w24: any 0x80+ high address (image, host guest-heap, B7, CA) is
    // already final — D890 miss must not Resource-fatal the place-pass.
    if ((oldAddr >= 0xB7000000u && oldAddr < 0xB8000000u) ||
        (oldAddr >= 0xA47F0000u && oldAddr < 0xA4800000u) ||
        (oldAddr >= 0x80000000u))
    {
        if (n <= 32 || (n % 500) == 0)
            MCLA_LOG_WARN("P10-PHYS #{:06} id={:08X} group={:08X} lr={:08X} "
                          "-> delta 0 (already physical)",
                          n, oldAddr, group, lrIn);
        ctx.r3.u32 = 0;
        return;
    }

    // w9/w11: leftover PSTREAM virtuals (0x50 nested-resource family AND
    // 0x60 stream/page family — job #2 s[12] 600E0000→B70A1000) still hit
    // the guest's empty rebase table and fatal. Resolve via the PSTREAM map
    // published at RSC-HEAD parse and return the same delta the guest table
    // would have produced (newBase-oldBase). Membership is the map itself —
    // do not hard-gate on a single virtual band.
    if (g_mclaRebaseCount > 0)
    {
        for (int i = 0; i < g_mclaRebaseCount; ++i)
        {
            const uint32_t vbase = g_mclaRebaseMap[i].vbase;
            const uint32_t size = g_mclaRebaseMap[i].size;
            if (size == 0)
                continue;
            if (oldAddr >= vbase && oldAddr < vbase + size)
            {
                const uint32_t delta = g_mclaRebaseMap[i].pbase - vbase;
                if (n <= 64 || (n % 200) == 0)
                    MCLA_LOG_WARN("P10-MAP #{:06} id={:08X} vbase={:08X} "
                                  "pbase={:08X} size={:08X} -> delta={:08X}",
                                  n, oldAddr, vbase, g_mclaRebaseMap[i].pbase,
                                  size, delta);
                ctx.r3.u32 = delta;
                return;
            }
        }
    }

    // w24: unmapped bad ptr (41C4FF12 family) — delta-0, no fatal.
    if (MclaPtrIsGateBad(oldAddr))
    {
        MCLA_LOG_WARN("P10-GATE #{:06} id={:08X} group={:08X} lr={:08X} "
                      "-> delta 0 (not in rebase map / phys)",
                      n, oldAddr, group, lrIn);
        ctx.r3.u32 = 0;
        return;
    }

    __imp__sub_8217D890(ctx, base);

    const int32_t res = static_cast<int32_t>(ctx.r3.u32);
    const bool watched =
        (oldAddr & 0xFFFF0000u) == 0x50070000u || oldAddr == 0x50035E50u;
    // Session 72: resource-miss path returns 0 (after fatal) with id=0xCDCDCDCD.
    // Dump those plus the historic -1/watch cases.
    const bool poisonId = (oldAddr & 0xFFu) == 0xCDu;
    if (res != -1 && res != 0 && !watched && !poisonId)
    {
        return; // healthy rebase - silent
    }

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t tablePtr = 0, g0 = 0, g4 = 0, g8 = 0;
    (void)mem.ReadU32BE(group, &tablePtr);
    (void)mem.ReadU32BE(group + 0, &g0);
    (void)mem.ReadU32BE(group + 4, &g4);
    (void)mem.ReadU32BE(group + 8, &g8);
    uint32_t regions = tablePtr;
    uint16_t cntA = 0, cntB = 0;
    if (regions != 0)
    {
        (void)mem.ReadU16BE(regions + 0, &cntA);
        (void)mem.ReadU16BE(regions + 2, &cntB);
    }
    MCLA_LOG_WARN("P10-D890 #{:06} {} group={:08X} table={:08X} counts={}/{} "
                  "id={:08X} -> {:08X} lr={:08X} g+4={:08X} g+8={:08X}",
                  n, res == -1 ? "MISS" : (res == 0 && poisonId ? "POISON" : "WATCH"),
                  group, regions, cntA, cntB, oldAddr, ctx.r3.u32, lrIn, g4, g8);
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
    // T41.3w (B3): the call at guest 0x821CC2EC (return 0x821CC2F0) is the
    // wait inside sub_821CC1E0's disc-read block, and its RESULT is what the
    // guest compares against 1 before raising 'Fatal disc error' (generated/
    // ppc_xenon/ppc_recomp.17.cpp: r29.u64 = ctx.r3.u64 after this call, then
    // cmpi r29,1 at 0x821CC2F8). r3 = the guest IO block (r1+80 of the caller).
    // Logging status/information before + after is the direct measurement of
    // the completion step the forced-bit31 mitigation skips.
    const bool discWait =
        static_cast<uint32_t>(ctx.lr) == 0x821CC2F0u && ctx.r4.u32 == 2;
    uint32_t iob0 = 0, iob4 = 0, iob8 = 0;
    if (discWait)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        (void)mem.ReadU32BE(ctx.r3.u32 + 0, &iob0);
        (void)mem.ReadU32BE(ctx.r3.u32 + 4, &iob4);
        (void)mem.ReadU32BE(ctx.r3.u32 + 8, &iob8);
        MCLA_LOG_WARN("DISCCHK2-WAIT iob={:08X} [+0]={:08X} [+4]={:08X} "
                      "[+8]={:08X}",
                      ctx.r3.u32, iob0, iob4, iob8);
    }
    // Session 72 AV: dump the worker-router object so we can see which
    // field becomes 0x7E780000 (unmapped guest VA).
    if (n <= 8)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t w[16] = {};
        for (int i = 0; i < 16; ++i)
            (void)mem.ReadU32BE(ctx.r3.u32 + i * 4, &w[i]);
        MCLA_LOG_INFO("DEE40-OBJ #{:05} r3={:08X} +0..+60 = {:08X} {:08X} "
                      "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                      "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}",
                      n, ctx.r3.u32, w[0], w[1], w[2], w[3], w[4], w[5], w[6],
                      w[7], w[8], w[9], w[10], w[11], w[12], w[13], w[14],
                      w[15]);
    }
    __imp__sub_821DEE40(ctx, base);
    if (discWait)
        MCLA_LOG_WARN("DISCCHK2-RES wait returned r3={} (guest fatals on ==1)",
                      ctx.r3.u32);
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
    // p2f: the 825FDBF8 build pass walked 27 CDCD buckets then AV'd inside
    // this body (lr=825FDC64, r3=CDCDCEA5). An unmapped/poison bucket base
    // can never be fixed up — the container's [+12] array was never filled
    // by the preload task. Skip the original on poison, log as FIXWALK-SKIP.
    // w7: also skip when the bucket ADDRESS is valid but its CONTENTS are
    // poison (RSC-REBASE rewrote a 0x50xxxxxx pointer to a B7 dest that was
    // never inflated — B7B61000 stays CDCD).
    {
        auto& memC = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t b0 = 0;
        if (bucket != 0 && bucket != 0xFFFFFFFFu)
            (void)memC.ReadU32BE(bucket, &b0);
        uint32_t node = 0;
        if (bucket != 0 && bucket != 0xFFFFFFFFu)
            (void)memC.ReadU32BE(bucket + 4, &node);
        const bool bucketGate = MclaPtrIsGateBad(bucket);
        const bool nodeGate = node != 0 && MclaPtrIsGateBad(node);
        if ((bucket & 0xFFFF0000u) == 0xCDCD0000u || bucket == 0 ||
            bucket == 0xFFFFFFFFu || b0 == 0xCDCDCDCDu)
        {
            MCLA_LOG_WARN("FIXWALK-SKIP #{:03} bucket={:08X} [0]={:08X} "
                          "buildCtx={:08X} lr={:08X} (poison bucket contents "
                          "- dest never inflated)",
                          n, bucket, b0, buildCtx,
                          static_cast<uint32_t>(ctx.lr));
            ctx.r3.u32 = 0;
            return;
        }
        // w24: gate bad ptrs the walk would D828/D2378 (41C4FF12 / 533D00CB).
        // Skip the original body so B588 is not invoked on an unmapped node.
        if (bucketGate || nodeGate)
        {
            MCLA_LOG_WARN("FIXWALK-GATE #{:03} bucket={:08X} [0]={:08X} "
                          "node={:08X} buildCtx={:08X} lr={:08X} "
                          "bucketGate={} nodeGate={} — delta-0 skip",
                          n, bucket, b0, node, buildCtx,
                          static_cast<uint32_t>(ctx.lr),
                          bucketGate ? 1 : 0, nodeGate ? 1 : 0);
            ctx.r3.u32 = 0;
            return;
        }
        if (n <= 48)
        {
            uint32_t table = 0;
            (void)memC.ReadU32BE(buildCtx, &table);
            MCLA_LOG_WARN("P6-FIXWALK-CENSUS #{:03} bucket={:08X} node={:08X} "
                          "table={:08X} buildCtx={:08X} lr={:08X}",
                          n, bucket, node, table, buildCtx,
                          static_cast<uint32_t>(ctx.lr));
        }
    }
    __imp__sub_8260A830(ctx, base);
}

// ---------------------------------------------------------------------------
// p2f: sub_825FDBF8 = swf-container build pass (vt 0x8208521C family, the
// container whose [+12] entry array stays CDCD when the preload task never
// fills it). Census + poison guard: when the container's own vtable or
// [+12] array is CDCD poison, the whole build pass is garbage-in — its
// entry walk would iterate cnt(=0xCDCD)*8 bytes of unmapped memory no
// matter what 8260A830 does per entry. Skip the original body in that
// case (census first logged the state as FDBF8-BUILD).
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_825FDBF8);
static std::atomic<uint32_t> s_hFDBF8{0};
PPC_FUNC(sub_825FDBF8)
{
    const uint32_t n = s_hFDBF8.fetch_add(1) + 1;
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t obj = ctx.r3.u32;
    uint32_t vt = 0, f4 = 0, f8 = 0, arr = 0;
    uint16_t cnt = 0;
    bool readable = obj != 0 && obj != 0xCDCDCDCDu;
    if (readable)
    {
        (void)mem.ReadU32BE(obj + 0, &vt);
        (void)mem.ReadU32BE(obj + 4, &f4);
        (void)mem.ReadU32BE(obj + 8, &f8);
        (void)mem.ReadU32BE(obj + 12, &arr);
        (void)mem.ReadU16BE(obj + 16, &cnt);
    }
    const bool poison =
        !readable || vt == 0xCDCDCDCDu || arr == 0xCDCDCDCDu || cnt == 0xCDCDu;
    // w7: arr can be a valid B7 address whose CONTENTS are still poison
    // (RSC-REBASE rewrote a 0x50xxxxxx pointer to a dest that was never
    // inflated). Check [arr] too — walking it would fatal in 8260A830.
    uint32_t arr0 = 0;
    if (!poison && arr != 0 && arr != 0xFFFFFFFFu)
        (void)mem.ReadU32BE(arr, &arr0);
    const bool arrPoison = (arr0 == 0xCDCDCDCDu);
    const bool arrGate = !poison && !arrPoison && MclaPtrIsGateBad(arr0);
    if (n <= 16 || (n % 200) == 0 || poison || arrPoison || arrGate)
        MCLA_LOG_WARN("FDBF8-BUILD #{:03} obj={:08X} vt={:08X} +4={:08X} "
                      "+8={:08X} arr={:08X} [arr]={:08X} cnt={} lr={:08X}{}{}",
                      n, obj, vt, f4, f8, arr, arr0, cnt,
                      static_cast<uint32_t>(ctx.lr),
                      (poison || arrPoison) ? " POISON-SKIP" : "",
                      arrGate ? " ARR-GATE" : "");
    // w15: record nested 5500-family heads for post-place re-dispatch.
    MclaNoteNestedPlaceCand(obj, vt);
    if (poison || arrPoison)
    {
        // Garbage container: neutralize the walk fields the original body
        // would consume ([obj+12] array=NULL, [obj+16] count=0) so both the
        // rebase leg (8217D890) and the entry loop see an empty container.
        //
        // w10 FIX: if the vtable is already a real swfC family pointer
        // (place-pass wrote it) do NOT zero arr/cnt — that permanently
        // starved the container (FDBF8-REBUILD then saw arr=0/cnt=0).
        // Only neutralize when the vtable itself is poison/garbage.
        const bool realSwfCVt = (vt & 0xFFFF0000u) == 0x82080000u;
        if (readable && !realSwfCVt)
        {
            (void)mem.WriteU32BE(obj + 12, 0);
            (void)mem.WriteU16BE(obj + 16, 0);
        }
        return; // skip original build pass entirely
    }
    __imp__sub_825FDBF8(ctx, base);
}

// ---------------------------------------------------------------------------
// p2f: sub_825FB0D8 = the swf-container family destructor. Its virtual
// dispatches ([child]=this -> vtable +68/+16/+20) AV'd when the child is
// the never-filled preload container (vt=CDCDCDCD, crash r3=B7B41000,
// lr=825FB14C). Guard: dispatch only when the child's vtable pointer is a
// plausible guest image address (< image top, non-poison); otherwise skip
// — same semantics as the function's own [+216]==0 null path.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_825FB0D8);
static std::atomic<uint32_t> s_hFB0D8{0};
PPC_FUNC(sub_825FB0D8)
{
    const uint32_t n = s_hFB0D8.fetch_add(1) + 1;
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t obj = ctx.r3.u32;
    uint32_t child = 0, childVt = 0, childP4 = 0, childP12 = 0;
    bool readable = obj != 0 && obj != 0xCDCDCDCDu;
    if (readable)
    {
        (void)mem.ReadU32BE(obj + 4, &child);
        if (child != 0 && child != 0xCDCDCDCDu)
        {
            (void)mem.ReadU32BE(child, &childVt);
            (void)mem.ReadU32BE(child + 4, &childP4);
            (void)mem.ReadU32BE(child + 12, &childP12);
        }
    }
    // w1a: a place-pass can write vt=82085364 onto an otherwise-CDCD
    // buffer. Dispatching the dtor through that vtable AVs at 825FB14C
    // because the body fields are still poison. Require the body to look
    // initialized too (at least one of +4/+12 non-CDCD and non-zero).
    const bool bodyPoison =
        childP4 == 0xCDCDCDCDu || childP12 == 0xCDCDCDCDu ||
        (childP4 == 0 && childP12 == 0 && childVt != 0);
    const bool poisonVt =
        !readable || childVt == 0 || childVt == 0xCDCDCDCDu ||
        (childVt & 0xFFF00000u) != 0x82000000u || bodyPoison;
    if (n <= 12 || poisonVt)
        MCLA_LOG_WARN("FB0D8-DTOR #{:03} obj={:08X} child={:08X} childVt={:08X} "
                      "+4={:08X} +12={:08X} lr={:08X}{}",
                      n, obj, child, childVt, childP4, childP12,
                      static_cast<uint32_t>(ctx.lr),
                      poisonVt ? " POISON-SKIP" : "");
    if (poisonVt)
    {
        // Child is the unfilled container (CDCD body): any virtual dtor
        // dispatch would AV (crash-2, lr=825FB14C). Skip the original body
        // — the object is host-side neutralized already (FDBF8 POISON-SKIP
        // nulled its walk fields), so the dtor has nothing real to free.
        return;
    }
    __imp__sub_825FB0D8(ctx, base);
}

// ---------------------------------------------------------------------------
// w1a: sub_825EF100 = PLACE pass. Calls FDBF8 (build), sets vt 0x82085364,
// rebases [obj+24], walks entries via 825FDA90. Runs BEFORE job #2 fills
// B7B41000 (still CDCD). w1a tried deferring the whole call — that broke
// the boot because the vtable write is load-bearing for FB0D8-DTOR and the
// job #2 enqueue path. Census-only hook: log entry, pass through.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_825EF100);
static std::atomic<uint32_t> s_hEF100{0};

PPC_FUNC(sub_825EF100)
{
    const uint32_t n = s_hEF100.fetch_add(1) + 1;
    const uint32_t obj = ctx.r3.u32;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t vt = 0, arr = 0, arr0 = 0;
    uint16_t cnt = 0;
    if (obj && obj != 0xCDCDCDCDu)
    {
        (void)mem.ReadU32BE(obj, &vt);
        (void)mem.ReadU32BE(obj + 12, &arr);
        (void)mem.ReadU16BE(obj + 16, &cnt);
        if (arr != 0 && arr != 0xCDCDCDCDu && arr != 0xFFFFFFFFu)
            (void)mem.ReadU32BE(arr, &arr0);
    }
    const bool rsc =
        (vt & 0xFFFFFF00u) == 0x44495500u ||
        (vt & 0xFFFFFF00u) == 0x44365500u || (vt & 0xFFFFu) == 0x5500u;
    // w24: complete 0x50/0x60 rebase + census on RSC heads BEFORE the guest
    // place body walks them (early EF100, deferred place, nested re-dispatch).
    if (rsc || (g_mclaRebaseCount > 0 && n <= 8))
        MclaCompleteRscRebaseBeforePlace(obj);
    // Gate the guest entry-walk bound when it is RSC residue (w23/w24:
    // +50 read as 0x00A4 → 164 junk iterations; [arr]=533D00CB gate-bad).
    // Cap to 1 so 825EF100 still runs FDBF8 + writes the real swfC vtable
    // then returns — never invent a vtable.
    if (rsc && obj && obj != 0xCDCDCDCDu)
    {
        uint16_t cnt50 = 0;
        uint32_t arr50 = 0, arr50c = 0;
        (void)mem.ReadU16BE(obj + 50, &cnt50);
        (void)mem.ReadU32BE(obj + 24, &arr50);
        if (arr50 != 0 && arr50 != 0xCDCDCDCDu && arr50 != 0xFFFFFFFFu)
            (void)mem.ReadU32BE(arr50, &arr50c);
        const bool gateWalk =
            cnt50 > 1 && (MclaPtrIsGateBad(arr0) || MclaPtrIsGateBad(arr) ||
                          MclaPtrIsGateBad(arr50c) || arr0 == 0xCDCDCDCDu);
        MCLA_LOG_WARN("EF100-WALK #{:03} obj={:08X} +24={:08X} +50={} "
                      "arr={:08X} [arr]={:08X} [+24]={:08X} gateWalk={}",
                      n, obj, arr50, cnt50, arr, arr0, arr50c,
                      gateWalk ? 1 : 0);
        if (gateWalk)
        {
            (void)mem.WriteU16BE(obj + 50, 1);
            MCLA_LOG_WARN("EF100-CNT-GATE #{:03} obj={:08X} +50 {} -> 1 "
                          "(RSC-residue walk bound; place still constructs)",
                          n, obj, cnt50);
        }
    }
    if (n <= 16 || rsc || (n % 200) == 0) {
        MCLA_LOG_WARN("EF100 #{:03} obj={:08X} r4={:08X} vt={:08X} "
                      "arr={:08X} [arr]={:08X} cnt={} lr={:08X}{}{}",
                      n, obj, ctx.r4.u32, vt, arr, arr0, cnt,
                      static_cast<uint32_t>(ctx.lr),
                      rsc ? " RSC-44495500" : "",
                      MclaPtrIsGateBad(arr0) ? " ARR-GATE" : "");
    }
    // w32: census-proven gate — guest walk is `if (u16[obj+50] <= 1) skip`.
    // After fill, +24 holds dest-range/SWF-tag candidates while +50 stays 1
    // (host CNT-GATE looked only at [+24][0]). Open the bound in-place so
    // THIS EF100 call runs FDA90 on +24[1..]. Never invent tags/vtables.
    if (obj && obj != 0xCDCDCDCDu)
        (void)MclaW32OpenConstructWalk(obj, 0, /*redispatch=*/false);
    __imp__sub_825EF100(ctx, base);
}

// ---------------------------------------------------------------------------
// w33: Scaleform/GFx tag-factory + construct-walker census.
// Raw PE + generated C (IDA offline):
//   82275D88 tag=4: r3+r4*12, stb 4,+8          (leaf; 0 bl callers)
//   82275DA8 tag=5: r3+r4*12, stb 5,+8; stw -1,+4
//   82299C20 tag=6: mid-fn 82299AA0, base+idx*12, stb 6,+8 then bl 824EF220
//   FP table 0x8202FE20/FE24 holds 82275D88/82275DA8 (rdata; no bl sites).
//   825EF248 = construct walker: stride-12 table, bl 8260B740 per live +8.
//   Sole bl of FDA90 = 825EF1F8 (place). Construct opcode EF248 is NOT on
//   the place path — host only re-dispatches EF100 on dest-range pointers.
// Census-only: log every guest hit; never invent tags/vtables.
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_82275D88);
static std::atomic<uint32_t> s_hFac4{0};
PPC_FUNC(sub_82275D88)
{
    const uint32_t n = s_hFac4.fetch_add(1) + 1;
    const uint32_t basep = ctx.r3.u32;
    const uint32_t idx = ctx.r4.u32;
    const uint32_t slot = basep + idx * 12u;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t w0 = 0;
    (void)mem.ReadU32BE(slot, &w0);
    if (n <= 32 || (n % 200) == 0)
        MCLA_LOG_WARN("W33-FAC4 #{:05} base={:08X} idx={} slot={:08X} "
                      "pre[0]={:08X} lr={:08X}",
                      n, basep, idx, slot, w0, static_cast<uint32_t>(ctx.lr));
    __imp__sub_82275D88(ctx, base);
    uint8_t tag = 0;
    (void)mem.ReadU8(slot + 8, &tag);
    if (n <= 32)
        MCLA_LOG_WARN("W33-FAC4-DONE #{:05} slot={:08X} tag={:02X}", n, slot,
                      tag);
}

PPC_FUNC_IMPL(__imp__sub_82275DA8);
static std::atomic<uint32_t> s_hFac5{0};
PPC_FUNC(sub_82275DA8)
{
    const uint32_t n = s_hFac5.fetch_add(1) + 1;
    const uint32_t basep = ctx.r3.u32;
    const uint32_t idx = ctx.r4.u32;
    const uint32_t slot = basep + idx * 12u;
    if (n <= 32 || (n % 200) == 0)
        MCLA_LOG_WARN("W33-FAC5 #{:05} base={:08X} idx={} slot={:08X} "
                      "lr={:08X}",
                      n, basep, idx, slot, static_cast<uint32_t>(ctx.lr));
    __imp__sub_82275DA8(ctx, base);
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint8_t tag = 0;
    uint32_t p4 = 0;
    (void)mem.ReadU8(slot + 8, &tag);
    (void)mem.ReadU32BE(slot + 4, &p4);
    if (n <= 32)
        MCLA_LOG_WARN("W33-FAC5-DONE #{:05} slot={:08X} tag={:02X} [+4]={:08X}",
                      n, slot, tag, p4);
}

// Construct walker 825EF248: r3/r4/r28/r29/r30 = task args; walks stride-12
// table via r30-family and bl 8260B740 per live slot. Census the table.
PPC_FUNC_IMPL(__imp__sub_825EF248);
static std::atomic<uint32_t> s_hEF248{0};
PPC_FUNC(sub_825EF248)
{
    const uint32_t n = s_hEF248.fetch_add(1) + 1;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    // Dump plausible table bases from arg regs (non-volatiles are locals
    // under PPC_CONFIG_NON_ARGUMENT_AS_LOCAL — do not read r28/r29/r30).
    const uint32_t cands[4] = {
        ctx.r3.u32,
        ctx.r4.u32,
        ctx.r5.u32,
        ctx.r6.u32,
    };
    if (n <= 16 || (n % 50) == 0) {
        MCLA_LOG_WARN("W33-EF248 #{:05} r3={:08X} r4={:08X} r5={:08X} "
                      "r6={:08X} r7={:08X} lr={:08X}",
                      n, cands[0], cands[1], cands[2], cands[3],
                      ctx.r7.u32, static_cast<uint32_t>(ctx.lr));
        for (int ci = 0; ci < 4; ++ci) {
            const uint32_t b = cands[ci];
            if (b < 0x80000000u || b >= 0xC0000000u)
                continue;
            uint8_t t8[8] = {0};
            uint32_t w0[4] = {0};
            int nValid = 0, nSent = 0;
            for (int i = 0; i < 8; ++i) {
                uint32_t slot = b + static_cast<uint32_t>(i * 12);
                uint32_t w = 0;
                uint8_t t = 0;
                if (!mem.ReadU32BE(slot, &w))
                    break;
                (void)mem.ReadU8(slot + 8, &t);
                if (i < 4)
                    w0[i] = w;
                t8[i] = t;
                if (t >= 1u && t <= 9u)
                    ++nValid;
                if (t == 0xFFu)
                    ++nSent;
            }
            if (nValid || nSent || (w0[0] & 0xFF000000u) == 0)
                MCLA_LOG_WARN("W33-EF248-TBL #{:05} base={:08X} nValid={} "
                              "nSent={} t8=[{:02X} {:02X} {:02X} {:02X} "
                              "{:02X} {:02X} {:02X} {:02X}] "
                              "w0=[{:08X} {:08X} {:08X} {:08X}]",
                              n, b, nValid, nSent, t8[0], t8[1], t8[2], t8[3],
                              t8[4], t8[5], t8[6], t8[7], w0[0], w0[1], w0[2],
                              w0[3]);
        }
    }
    __imp__sub_825EF248(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8260B740);
static std::atomic<uint32_t> s_hB740{0};
PPC_FUNC(sub_8260B740)
{
    const uint32_t n = s_hB740.fetch_add(1) + 1;
    if (n <= 32 || (n % 200) == 0)
        MCLA_LOG_WARN("W33-B740 #{:05} r3={:08X} r4={:08X} r5={:08X} "
                      "r6={:08X} r7={:08X} lr={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                      ctx.r7.u32, static_cast<uint32_t>(ctx.lr));
    __imp__sub_8260B740(ctx, base);
}

// ---------------------------------------------------------------------------
// w34: guest GFx/SWF parse-path census after archive inflate.
// PE/generated (mcla_pe.bin + ppc_recomp.*):
//   824EF220 = GFx LoadBytes: lock movie+1292; 824EAFA0(movie, dataId);
//              824EEC28(movie, entry, flags) constructs nodes.
//   824876E0 = loader: r4=stream, r3=loader; dataId=[stream+0];
//              if (int32)dataId < 0 -> skip EF220 (PARSE FLAG GATE).
//   824C6E88 = second loader, same skip on [obj+0x90]/nested+4.
//   824EAFA0 = resource lookup: dataId & 0xFFFF indexed in movie hash
//              table (+88 buckets, +92 size, +104 shift, +108 mask,
//              entry stride 148). No table -> return 0 -> no parse.
//   824EEC28 = GFx construct on entry; entry+144 bit7 = already-parsed.
//   FP 0x8202FE20/FE24 = {82275D88,82275DA8} tag factories (rdata; 0 bl).
//   bl 824EF220 sites: 822999C4/A80/C44, 82487708/B00/81A8, 824C6ED0,
//   824CAA8C. bl FDA90 still sole=825EF1F8. Opcode/reg table 0x8211E000
//   is {func,flags} resource-class registry (825FB0D8 swfC dtor appears).
// Census-only: log every guest hit. Never invent tags/vtables.
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_824EF220);
static std::atomic<uint32_t> s_hEF220{0};
PPC_FUNC(sub_824EF220)
{
    const uint32_t n = s_hEF220.fetch_add(1) + 1;
    if (n <= 32 || (n % 50) == 0)
        MCLA_LOG_WARN("W34-EF220 #{:05} r3(movie)={:08X} r4(dataId)={:08X} "
                      "r5(flags)={:08X} lr={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                      static_cast<uint32_t>(ctx.lr));
    __imp__sub_824EF220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824876E0);
static std::atomic<uint32_t> s_h876E0{0};
PPC_FUNC(sub_824876E0)
{
    const uint32_t n = s_h876E0.fetch_add(1) + 1;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t d0 = 0, movie = 0;
    const uint32_t loader = ctx.r3.u32, stream = ctx.r4.u32;
    if (stream && stream != 0xCDCDCDCDu)
        (void)mem.ReadU32BE(stream + 0, &d0);
    if (loader && loader != 0xCDCDCDCDu)
        (void)mem.ReadU32BE(loader + 4, &movie);
    const bool skip = static_cast<int32_t>(d0) < 0;
    if (n <= 32 || (n % 20) == 0)
        MCLA_LOG_WARN("W34-876E0 #{:05} r3(loader)={:08X} r4(stream)={:08X} "
                      "stream+0={:08X} movie={:08X} skip={} lr={:08X}",
                      n, loader, stream, d0, movie, skip ? 1 : 0,
                      static_cast<uint32_t>(ctx.lr));
    __imp__sub_824876E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824C6E88);
static std::atomic<uint32_t> s_h6E88{0};
PPC_FUNC(sub_824C6E88)
{
    const uint32_t n = s_h6E88.fetch_add(1) + 1;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t d90 = 0, nested = 0, movie = 0;
    const uint32_t obj = ctx.r3.u32;
    if (obj && obj != 0xCDCDCDCDu) {
        (void)mem.ReadU32BE(obj + 0x90, &d90);
        (void)mem.ReadU32BE(obj + 0x0C, &nested);
        if (nested && nested != 0xCDCDCDCDu)
            (void)mem.ReadU32BE(nested + 4, &movie);
    }
    const bool skip = d90 == 0;
    if (n <= 32 || (n % 20) == 0)
        MCLA_LOG_WARN("W34-6E88 #{:05} r3(obj)={:08X} +90(dataId)={:08X} "
                      "+0C(nested)={:08X} movie={:08X} skip={} lr={:08X}",
                      n, obj, d90, nested, movie, skip ? 1 : 0,
                      static_cast<uint32_t>(ctx.lr));
    __imp__sub_824C6E88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824EAFA0);
static std::atomic<uint32_t> s_hAFA0{0};
PPC_FUNC(sub_824EAFA0)
{
    const uint32_t n = s_hAFA0.fetch_add(1) + 1;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t tsize = 0, tbuck = 0;
    const uint32_t movie = ctx.r3.u32, dataId = ctx.r4.u32;
    if (movie && movie != 0xCDCDCDCDu) {
        (void)mem.ReadU32BE(movie + 92, &tsize);
        (void)mem.ReadU32BE(movie + 88, &tbuck);
    }
    __imp__sub_824EAFA0(ctx, base);
    if (n <= 32 || (n % 50) == 0)
        MCLA_LOG_WARN("W34-AFA0 #{:05} r3(movie)={:08X} r4(id)={:08X} "
                      "id16={:04X} tsize={} buckets={:08X} ret={:08X} "
                      "lr={:08X}",
                      n, movie, dataId, dataId & 0xFFFFu, tsize, tbuck,
                      ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
}

PPC_FUNC_IMPL(__imp__sub_824EEC28);
static std::atomic<uint32_t> s_hEEC28{0};
PPC_FUNC(sub_824EEC28)
{
    const uint32_t n = s_hEEC28.fetch_add(1) + 1;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint8_t fl = 0;
    uint32_t eid = 0;
    if (ctx.r4.u32 && ctx.r4.u32 != 0xCDCDCDCDu) {
        (void)mem.ReadU8(ctx.r4.u32 + 144, &fl);
        (void)mem.ReadU32BE(ctx.r4.u32 + 0, &eid);
    }
    if (n <= 32 || (n % 20) == 0)
        MCLA_LOG_WARN("W34-EEC28 #{:05} r3(movie)={:08X} r4(entry)={:08X} "
                      "r5(flags)={:08X} entry+144={:02X} entry[0]={:08X} "
                      "lr={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, fl, eid,
                      static_cast<uint32_t>(ctx.lr));
    __imp__sub_824EEC28(ctx, base);
}

// ---------------------------------------------------------------------------
// w35: census the GFx movie ctor wrapper + lifecycle + boot gate to identify
// why UILOAD 822012E8 never fires after POST-EXEC.
//   sub_82482F78: movie ctor wrapper — calls 824C6F08 (writes vt 0x820736DC),
//     optionally frees. Called via vtable dispatch from unmapped Scaleform code.
//   sub_824C6F70: movie lifecycle step — state machine at +28 (0=unconstructed,
//     1=constructed). Calls 824880F8 to init movie when +28==0.
//   sub_82131008: boot gate callback — checks two events via 821C0750, then
//     calls 822C0980 → 821FD640 → 822012E8 (UILOAD).
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_82482F78);
static std::atomic<uint32_t> s_hMovieCtor{0};
PPC_FUNC(sub_82482F78) {
    const uint32_t n = s_hMovieCtor.fetch_add(1) + 1;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t obj = ctx.r3.u32;
    uint32_t flags = ctx.r4.u32;
    uint32_t vt = 0;
    if (obj && obj != 0xCDCDCDCDu)
        (void)mem.ReadU32BE(obj + 0, &vt);
    if (n <= 32 || (n % 50) == 0)
        MCLA_LOG_WARN("W35-MOVIE-CTOR #{:05} r3(obj)={:08X} r4(flags)={:08X} "
                      "vt={:08X} lr={:08X}",
                      n, obj, flags, vt,
                      static_cast<uint32_t>(ctx.lr));
    __imp__sub_82482F78(ctx, base);
    if (n <= 8) {
        uint32_t vt2 = 0;
        if (obj && obj != 0xCDCDCDCDu)
            (void)mem.ReadU32BE(obj + 0, &vt2);
        MCLA_LOG_WARN("W35-MOVIE-POST #{:05} obj={:08X} vt→{:08X} "
                      "vt+672={:08X}",
                      n, obj, vt2, 0u);
        if (obj && obj != 0xCDCDCDCDu)
            (void)mem.ReadU32BE(obj + 672, &vt2);
        MCLA_LOG_WARN("W35-MOVIE-POST #{:05} obj+672 vt→{:08X}", n, vt2);
    }
}

PPC_FUNC_IMPL(__imp__sub_824C6F70);
static std::atomic<uint32_t> s_hMovieLife{0};
PPC_FUNC(sub_824C6F70) {
    const uint32_t n = s_hMovieLife.fetch_add(1) + 1;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t obj = ctx.r3.u32;
    uint32_t state = 0, dev = 0, fl664 = 0, p672 = 0, p740 = 0;
    if (obj && obj != 0xCDCDCDCDu) {
        (void)mem.ReadU32BE(obj + 28, &state);
        (void)mem.ReadU32BE(obj + 12, &dev);
        (void)mem.ReadU32BE(obj + 664, &fl664);
        (void)mem.ReadU32BE(obj + 672, &p672);
        (void)mem.ReadU32BE(obj + 740, &p740);
    }
    if (n <= 32 || (n % 20) == 0)
        MCLA_LOG_WARN("W35-MOVIE-LIFE #{:05} obj={:08X} state={} dev={:08X} "
                      "fl664={:08X} p672={:08X} p740={:08X} lr={:08X}",
                      n, obj, state, dev, fl664, p672, p740,
                      static_cast<uint32_t>(ctx.lr));
    __imp__sub_824C6F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82131008);
static std::atomic<uint32_t> s_hBootGate{0};
PPC_FUNC(sub_82131008) {
    const uint32_t n = s_hBootGate.fetch_add(1) + 1;
    if (n <= 32 || (n % 100) == 0)
        MCLA_LOG_WARN("W35-BOOT-GATE #{:05} r3={:08X} r4={:08X} r5={:08X} "
                      "lr={:08X}",
                      n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                      static_cast<uint32_t>(ctx.lr));
    __imp__sub_82131008(ctx, base);
    if (n <= 8 || (n % 100) == 0) {
        MCLA_LOG_WARN("W35-BOOT-GATE-POST #{:05} ret r3={:08X}",
                      n, ctx.r3.u32);
    }
}

