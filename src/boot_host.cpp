// Guest boot host: allocates the 4 GiB guest window, loads default.xex, installs the 45k-function
// lookup table (45,190 PPCFuncMappings entries), seeds the pre-boot slots and runs the guest entry
// under a process-wide VEH + SetUnhandledExceptionFilter -- no __try around the entry call. Ported
// from tools/xenon_smoke @8fc8842 (removed by 72cda76) with MCLA logging and the App's active
// GuestMemoryView / PPC base wiring. Phase 5 of BOOT_REBUILD_PLAN.md (doc no longer in the tree).

#include "ppc_config.h"
#include "ppc_context.h"
#include <cpu/ppc_context.h>
#include "ppc_recomp_shared.h"

#include "app.h"
#include "guest_memory.h"
#include "logging.h"
#include "boot_host.h"
#include "kernel/heap.h"
#include "kernel/heap_arena.h"  // F-412: kPhysArenaBeginVa used directly (guard, watch ranges, dump scan)
#include "kernel/memory.h"
#include <image.h>

// P4 vtable-word scan (defined in task_dispatch_trace.cpp)
namespace mcla::trace {
void ScanForDispatchVtableWords(uint32_t imageBase, uint32_t imageSize);
}

// Forward declare Xex2LoadImage from XenonRecomp (Image is defined in image.h)
Image Xex2LoadImage(const uint8_t* data, size_t dataSize);

#include <windows.h>
#include <dbghelp.h>
// F-616: _ReturnAddress() so PARK-SAMPLE can print the SAMPLER's own pc next to the
// worker's. The two are both routinely inside GuestMemoryView::ReadU32BE/WriteU32BE,
// which is how the worker's rawrip came to be read as a sampler address.
#include <intrin.h>
#include <unordered_map>

// s_skipSub822FA958 (generated/ppc_xenon/ppc_recomp.49.cpp:18142) has had no writer in src/ since T38.3.

// UILOAD thread tracking
std::atomic<DWORD> s_uiLoadThreadId{0};
std::atomic<bool> s_inUILoad{false};

#pragma comment(lib, "dbghelp.lib")

// Guest main-thread id (defined in kernel imports.cpp, declared in xdm.h).
extern std::atomic<uint32_t> g_mainGuestThreadId;

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

// Global-scope redeclarations of the kernel-stub XTL alloc/free (defined at
// global scope in src/kernel/imports.cpp:53/:61; C++ linkage). Referenced via
// the r13 thread-block function block so indirect calls resolve in the guest table.
PPC_EXTERN_FUNC(__xtl_alloc);
PPC_EXTERN_FUNC(__xtl_free);

// F-784: the T44 wipe-watch positive control (LT rule 19), defined at the foot
// of the T44 block in gpu_cp.cpp. Declared at GLOBAL scope, before namespace
// mcla::boot opens -- a declaration written inside that namespace would name a
// different function with different linkage, the F-637 trap F-640's own
// declaration above had to be written around.
namespace mcla::gpu { void T44WipeSelfTest(); }

namespace mcla::boot {

// F-640: the physical-view alias probe + the init row. Defined at the foot of this TU with
// the other F-640 entry points, and declared HERE, in mcla::boot scope, BEFORE the anonymous
// namespace opens -- a declaration inside that namespace would be a different function with
// internal linkage, which is the exact trap F-637 had to be documented around.
void F640PhysAliasInit();

namespace
{
    uint8_t* g_base = nullptr;

    constexpr size_t GuestMemorySize = 0x100000000ull; // 4 GiB, matches PPC_MEMORY_SIZE
    constexpr uintptr_t GuestMemoryBase = 0x100000000ull;

    // ==========================================================================
    // F-640: THE CONSOLE'S THREE PHYSICAL VIEWS, AND WHAT THIS TREE DOES ABOUT THEM
    // ==========================================================================
    // WHAT THE HARDWARE PROMISES. The reference emulator declares physical memory
    // ONCE (`.research/xenia/src/xenia/memory.cc:171-172`:
    // `heaps_.physical.Initialize(this, physical_membase_, kGuestPhysical, 0x00000000,
    // 0x20000000, 4096)`) and then hands that same parent heap to THREE guest-visible
    // regions, each declared with the FULL 0x20000000, differing only in page size
    // (memory.cc:173-180): 0xA0000000 / 64 KiB, 0xC0000000 / 16 MiB, 0xE0000000 / 4 KiB.
    // So `0xA0000000 + pa` and `0xC0000000 + pa` are THE SAME BYTES. That is a hardware
    // aliasing guarantee, and it is what `PhysToKernelVA` (src/gpu_cp.cpp:1755-1756,
    // `addr < 0x20000000u ? (addr | 0xC0000000u) : addr`, commented "X360: kernel maps phys
    // windows at +0xC0000000") converts a physical address into. The same 0x20000000
    // threshold is written out at gpu_cp.cpp:2328, gpu_mmio.cpp:83 and :74, and
    // native_renderer.cpp:120/226/277/294/308 -- five sites, one number.
    //
    // WHAT THIS TREE HAS. One flat 4 GiB host window from a single VirtualAlloc
    // (`AllocateGuestMemory`, :677, or the reservation `Memory::Initialize` made and this
    // function adopts), and `GuestMemoryHeap::Translate` is PURE ARITHMETIC --
    // `return m_base + guestAddr;` (src/kernel/memory.cpp:285-297), with `MapVirtual` the
    // exact inverse (`:299-309`). The virtual-region table next to it is bookkeeping only
    // and says so: "The flat window remains identity-mapped; only STATE is tracked"
    // (memory.cpp:366-368); `DecommitVirtual` flips a bool and calls no OS API
    // (memory.cpp:563-576). Therefore one guest VA is one host page, forever.
    //
    // WHY (a) MAPPING-THE-VIEWS IS NOT FEASIBLE HERE, and it is not a matter of effort:
    //  1. TWO VIEWS OF ONE HOST RANGE REQUIRE A SECTION. Windows shares pages between two
    //     guest-visible VAs only if both are views of one section object. The pool's bytes
    //     are a sub-range of one private VirtualAlloc (:677), and a private allocation
    //     cannot be retroactively turned into a second view of itself. Making the pool a
    //     section (as Xenia does, `physical_membase_ = mapping_base_ + 0x100000000`,
    //     memory.cc:158) would move the pool's HOST address, and then
    //     `Translate(0xA0400000)` (src/kernel/heap.cpp:1561, the pool binding) and every
    //     other `Translate` caller in the tree would read the wrong bytes. That is a
    //     mapping layer in `Translate`/`MapVirtual` -- src/kernel/memory.cpp, owned by
    //     another stream, and a rewrite of the one primitive this whole tree assumes.
    //  2. THE TARGET ADDRESSES ARE ALREADY COMMITTED. All three views live INSIDE the flat
    //     4 GiB window, which is `MEM_COMMIT|MEM_RESERVE` as a single reservation. A view
    //     cannot be mapped over committed pages, and a private reservation cannot be
    //     released in the middle (`MEM_RELEASE` is whole-region). So the window itself would
    //     have to be torn into reserve-only islands with three holes -- i.e. exactly the
    //     restructure (1) forbids.
    //  3. THE 16 MiB VIEW'S ALIGNMENT IS NOT MET BY THE POOL'S BASE. The C view is the
    //     16 MiB-page GPU write-back window, so its backing must be 16 MiB-aligned;
    //     `kPhysArenaBeginVa & 0xFFFFFF` = 0x400000, not 0 (measured from the constant, not
    //     typed here). The pool base is 4 MiB into the A view precisely because F-391 moved
    //     it off the title's XTL slab region at 0xA0001000..0xA002FFC0, and that relocation
    //     is NOT to be redone (F-631, and the instruction for this change).
    //  4. THE THREE VIEWS TILE [0xA0000000, 0x100000000) EXACTLY -- 3 x 0x20000000 -- so
    //     they can only be line up with the pool by binding the pool at 0xA0000000, which
    //     is (3) inverted and forbidden.
    // CONCLUSION: (a) is out. (b) -- translate the accesses -- is the only honest mechanism,
    // and the primitives for it are below. The call sites that must adopt them are named in
    // `F640-PHYSALIAS phase=init`'s `adopt=` field; the two that matter most are the CP rptr
    // write-back (src/gpu_cp.cpp:3673, `PhysToKernelVA(rptrWritebackAddr)` ->
    // `memP.WriteU32BE(vaForm, publish)`) and the present-surface resolve
    // (src/native_renderer.cpp:294, `mcla_gpu_AddSurfaceCandidate(swap_info | 0xC0000000u, ...)`).
    //
    // MEASURED CONSEQUENCE, and the arithmetic is worth stating exactly because it is NOT
    // uniform across the three views. `poolVa(pa) = kPhysArenaBeginVa + (pa - 0x400000)`
    // collapses, because F-391 moved the base by exactly 0x400000, to `0xA0000000 + pa` --
    // which IS the A view's address for pa. So THE A VIEW IS THE POOL, already, for every pa
    // in [0x400000, 0x20400000): `A(pa) == poolVa(pa)` is an identity here, not an
    // approximation, and the A view needs no work at all. The C and E views are each exactly
    // 0x20000000 ABOVE that, for every pa (measured, not typed: `C(pa) - poolVa(pa)` is
    // 0x20000000 at pa = 0, at pa = 0x4E0D30 and at pa = 0x10400000 alike).
    //
    // F-640/B2 (2026-10-21): THE IDENTITY NOW HOLDS FOR EVERY pa IN THE CONSOLE'S WINDOW,
    // not only for pa >= 0x400000. The reason it did not is exactly the LOW REGION: the
    // formula `0xA0000000 + pa` names a byte BELOW the allocator's pool for pa < 0x400000,
    // and there was nothing there. There is now: the 4 MiB [0xA0000000, 0xA0400000) is the
    // console's physical [0, 0x400000). So the rule is the console's own (memory.cc:173-175:
    // the A view's base IS the physical heap's base) and it is uniform over the whole
    // 512 MiB window -- `poolVa(pa) == A(pa) == 0xA0000000 + pa` for every pa below
    // 0x20000000 -- and the only view that is NOT the pool is the C and E views, each
    // exactly 0x20000000 / 0x40000000 above it.
    //
    // SO THE HOLE IS PRECISE AND IT IS EXACTLY ONE CONSTANT: every `pa | 0xC0000000` in this
    // tree -- `PhysToKernelVA` (gpu_cp.cpp:1755-1756), `MmioAddrSpace` (gpu_mmio.cpp:83), the
    // five native_renderer.cpp sites -- produces an address 0x20000000 above the pool byte the
    // console means, and the access therefore lands in flat memory. F-612's own present
    // surface is the worked example: pa = 0x004E0D30, the console's byte is at 0xA04E0D30, the
    // tree computes 0xC04E0D30, and 0xC04E0D30 is NOT inside the pool at all (pool ends at
    // 0xC0400000) -- so the present resolve reads flat memory that nothing wrote.
    //
    // AND ONE OVERLAP IS NOT MERELY INEFFECTIVE, IT IS CORRUPTING. `F640ViewOverlapBytes`
    // computes how much of each view lands inside the pool: the A view by 508 MiB (all of it
    // correct, it is the pool) and the C view by 4 MiB -- and that 4 MiB is the pool's TAIL,
    // bytes for physical 0x20400000..0x207FFFFF, which the console does not have. So a C-view
    // access for pa in [0, 0x3FFFFF) does not vanish: it LANDS INSIDE OUR POOL, in live
    // pool-managed memory, at the wrong offset. A silent pool write is the one failure mode
    // in this project that produces a black screen with no error anywhere.
    //
    // F-640/B2 (2026-10-21): THE SKEW IS GONE. The text below used to say that the
    // pool does not hold physical [0, 0x400000) at all and that every access to the
    // console's low 4 MiB therefore had no pool byte here. That was MEASURED and it
    // was TRUE of the tree as it stood, and it was WRONG about the console.
    //
    // THE CONSOLE HAS NO SUCH HOLE. `.research/xenia/src/xenia/memory.cc:171-172`
    // declares ONE physical heap of 0x20000000 bytes at physical 0, and memory.cc:
    // 173-180 hands that SAME parent heap to the three guest-visible views:
    //   0xA0000000 / 64 KiB pages, 0xC0000000 / 16 MiB pages, 0xE0000000 / 4 KiB pages.
    // So the A view's base IS the physical heap's base: `0xA0000000 + pa` is the
    // console's byte for physical `pa`, for EVERY pa in [0, 0x20000000). Physical 0 is
    // a real, writable byte and the console's first `MmAllocatePhysicalMemoryEx` lands
    // there.
    //
    // WHY THE TREE HAD A HOLE: F-391 moved the pool from 0xA0000000 to
    // kPhysArenaBeginVa = 0xA0400000 so the title's XTL slab region would not be inside
    // it, and that move is exactly +0x400000. The consequence was that the pool's first
    // byte presented as physical 0x00400000 and the pool's last 4 MiB presented as
    // physical 0x20400000..0x207FFFFF, which the console does not have. Both halves
    // are now gone: the 4 MiB BELOW the pool is the LOW REGION (boot_host.h,
    // kPhysLowRegionVa) and carries console physical [0, 0x400000), and the translation
    // rule is the console's own identity for the whole window.
    //
    // WHAT IT COST, MEASURED (build/w852.log): the only accesses that ever hit the hole
    // were the guest's VERTEX FETCH CONSTANT bases -- `CP: POOL-XLATE-REFUSED` printed
    // 2503 rows and EVERY ONE of them says `site=FETCHVB-CONSTANTS`, with pa=001FE0FC
    // (1250 rows), pa=00000000 (1249 rows) and pa=0003E01C (4 rows). The guest's own
    // fetch constants name physical 0 (528 bytes) and physical 0x1FE0FC (11,013,392
    // bytes) -- see `CP-FETCHVB-DECODE #249200 ... slot=1 physBase=001FE0FC
    // sizeWords=2753348` and `slot=2 physBase=00000000 sizeWords=132`. In this tree
    // those bytes had nowhere to live, so 499,342 reads were dropped
    // (`CP: POOL-XLATE-REFUSED #499342 ... refused=499342`, the log's last row).
    //
    // LABELLED INFERENCE, NOT A MEASUREMENT: that the guest's fetch-constant buffers are
    // among the FIRST pages the console's physical heap handed out. It is not measured
    // from the guest's bytes here. What IS measured is that the guest names physical 0
    // and physical 0x1FE0FC, and that the console's physical heap covers physical
    // [0, 0x20000000) with its base at physical 0 (memory.cc:171-172) -- so those bytes
    // exist on the console and did not exist here. Falsifier: if the guest's low-physical
    // buffers turn out to be console-allocated by something OTHER than the CPU's
    // physical allocator (an EDRAM aperture, a fixed platform region), then the low
    // region's CONTENT is still wrong even though its EXISTENCE is right; the
    // `F640-LOWREGION-PROBE` row's `orig=` bytes are where that would show up.
    //
    // AND WHAT THE SKEW DID NOT TOUCH: the guest's PRESENT. Every VdSwap physical
    // address in w852 is 0x004E0AF0 (8 rows, one distinct value), which is ABOVE the
    // old 4 MiB floor, so `F640-CVIEW-REFUSED` was 0 in w852 -- the present path was
    // never inside the hole. The hole was in the VERTEX FETCH path, and it is the one
    // the guest's own geometry needs.
    //
    // AND WHAT THIS CHANGE DID NOT CHANGE: the C view's 4 MiB overlap with the pool is
    // still the pool's TAIL (the paragraph above). The fix gives the TRANSLATED path a
    // real byte for physical [0, 0x400000); it does NOT make 0xC0000000 + pa alias the
    // low region, because in this flat window 0xC0000000 is the pool's own address. Any
    // site that uses the UNTRANSLATED C-view address still reads the wrong bytes, which
    // is why the rule is "translate, never fall back" and why the fall-back arm stays
    // refused.
    enum class F640View : uint8_t { kNone = 0, kA64K = 1, kC16M = 2, kE4K = 3 };
    enum class F640Map : uint8_t { kNotAView = 0, kMapped = 1, kNoPoolByte = 2 };

    struct F640ViewDesc
    {
        uint32_t base;
        uint32_t size;      // kConsolePhysicalBytes, NOT a literal (see above)
        uint32_t pageShift; // log2 of the view's page size: 16 / 24 / 12
        const char* name;
    };
    constexpr F640ViewDesc kF640Views[] = {
        {0xA0000000u, mcla::kernel::kConsolePhysicalBytes, 16u, "A64K"},
        {0xC0000000u, mcla::kernel::kConsolePhysicalBytes, 24u, "C16M"},
        {0xE0000000u, mcla::kernel::kConsolePhysicalBytes, 12u, "E4K"},
    };
    static_assert(kF640Views[1].pageShift == 24,
                  "F-640: the C view is the 16 MiB-page GPU write-back window (memory.cc:173-180). "
                  "If this fires, the view table is not the reference's.");

    // F-640: THE POOL'S OWN PHYSICAL WINDOW, DERIVED. F-391 moved the pool to
    // kPhysArenaBeginVa so the title's XTL slab region would not be inside it, and that move
    // is +0x400000 relative to the A view's base. So our pool's FIRST byte presents as
    // physical 0x00400000, not physical 0 -- that single skew is the whole reason no view
    // aliases the pool here, and it is derived from the two constants rather than restated.
    //
    // F-640/B2: THIS IS NOW THE ALLOCATOR'S WINDOW ONLY. The console's window is wider, at
    // the bottom, because the LOW REGION (boot_host.h, kPhysLowRegionVa) carries console
    // physical [0, 0x400000). The two are kept apart on purpose: the allocator's window is
    // what o1heap owns, and the console's window is what the guest may address.
    constexpr uint64_t F640PoolPhysBase()
    {
        return (uint64_t)(mcla::kernel::kPhysArenaBeginVa - kF640Views[0].base);
    }
    constexpr uint64_t F640PoolPhysTop()
    {
        return F640PoolPhysBase() + (uint64_t)mcla::kernel::PhysArenaSizeBytes();
    }

    // F-640/B2: THE CONSOLE'S PHYSICAL WINDOW -- [0, 0x20000000), physical 0 INCLUDED.
    // The reference declares the physical heap at physical 0 with the console's own size
    // (memory.cc:171-172) and aliases it into the three views (memory.cc:173-180), so a
    // physical address is in-window exactly when it is below 0x20000000 -- which is also
    // the threshold the tree already tells the guest (gpu_cp.cpp:1756 `addr <
    // 0x20000000u`, gpu_mmio.cpp:83/:74). Derived from kConsolePhysicalBytes, not typed.
    constexpr uint64_t F640ConsolePhysBase() { return 0ull; }
    constexpr uint64_t F640ConsolePhysTop()
    {
        return (uint64_t)mcla::kernel::kConsolePhysicalBytes;
    }

    F640View F640ClassifyView(uint32_t guestVa)
    {
        for (uint32_t i = 0; i < (uint32_t)(sizeof(kF640Views) / sizeof(kF640Views[0])); ++i)
        {
            const F640ViewDesc& v = kF640Views[i];
            if (guestVa >= v.base &&
                (uint64_t)guestVa < (uint64_t)v.base + (uint64_t)v.size)
                return static_cast<F640View>(i + 1);
        }
        return F640View::kNone;
    }

    // The translation. Pure, no memory touched, no guest value asserted on: a physical
    // address outside the console's window is a MISS, not a fault and not a clamped value.
    //
    // F-640/B2: THE RULE IS NOW THE CONSOLE'S OWN IDENTITY, `poolVa = 0xA0000000 + pa`,
    // for EVERY pa in the console's window -- the same formula the tree already used for
    // pa >= 0x400000, extended DOWN over the LOW REGION so that console physical 0 has a
    // byte at 0xA0000000. The A view's base IS the physical heap's base on the console
    // (memory.cc:173-175), so this is the hardware's mapping, not a host invention. The
    // belt below is the allocator's upper bound, which is exactly
    // kPhysLowRegionVa + kConsolePhysicalBytes (0xA0000000 + 0x20000000 = 0xC0400000), so
    // the window the guest may address and the extent the host has bytes for are the same
    // number by construction.
    F640Map F640MapViewToPool(uint32_t viewVa, uint32_t* outPoolVa)
    {
        const F640View view = F640ClassifyView(viewVa);
        if (view == F640View::kNone)
            return F640Map::kNotAView;
        const uint64_t pa = (uint64_t)viewVa - (uint64_t)kF640Views[(uint32_t)view - 1].base;
        if (pa < F640ConsolePhysBase() || pa >= F640ConsolePhysTop())
            return F640Map::kNoPoolByte;  // past the console's 512 MiB physical window
        const uint64_t poolVa = (uint64_t)mcla::boot::kPhysLowRegionVa + pa;
        // belt: the byte must be inside the extent the host actually has.
        if (poolVa < (uint64_t)mcla::boot::kPhysLowRegionVa ||
            poolVa >= (uint64_t)mcla::kernel::kPhysArenaEndVa)
            return F640Map::kNoPoolByte;
        if (outPoolVa != nullptr)
            *outPoolVa = (uint32_t)poolVa;
        return F640Map::kMapped;
    }

    // How much of a view lands INSIDE the pool. For the A view this is 508 MiB and every byte
    // of it is CORRECT (the A view is the pool). For the C view it is 4 MiB and every byte of
    // it is WRONG -- it is the pool's tail. Read with the block comment above, not alone.
    uint64_t F640ViewOverlapBytes(F640View view)
    {
        if (view == F640View::kNone)
            return 0;
        const F640ViewDesc& v = kF640Views[(uint32_t)view - 1];
        const uint64_t vLo = v.base, vHi = (uint64_t)v.base + (uint64_t)v.size;
        const uint64_t pLo = mcla::kernel::kPhysArenaBeginVa;
        const uint64_t pHi = (uint64_t)mcla::kernel::kPhysArenaEndVa;
        const uint64_t lo = vLo > pLo ? vLo : pLo;
        const uint64_t hi = vHi < pHi ? vHi : pHi;
        return hi > lo ? (hi - lo) : 0;
    }

    // ---- F-640 counters. Attempts and outcomes are counted SEPARATELY and the two sets are
    // published with a row that makes them add up, so a zero can never be read as "nothing
    // happened" when in fact nothing called (F-057(6): a tracked marker whose producer is dead
    // reports zero and means nothing). `adopted` is the number of call sites that adopted the
    // translation; while it is 0, `dropped == 0` is NOT a measurement.
    struct F640Counters
    {
        std::atomic<uint64_t> calls{0};        // every F640TranslateViewToPoolVa call
        std::atomic<uint64_t> notAView{0};     // outcome: the address is not a view address
        std::atomic<uint64_t> translated{0};   // outcome: mapped onto a pool byte
        std::atomic<uint64_t> dropped{0};      // outcome: in a view, no pool byte -> THE number
        std::atomic<uint64_t> dropSeq{0};      // monotonic, for the bounded print of the drop row
        std::atomic<uint32_t> adopted{0};      // distinct call sites that registered themselves
        // F-640/B2: how many TRANSLATED accesses landed in the console's LOW physical
        // region (console physical [0, 4 MiB) -> guest VA [0xA0000000, 0xA0400000)).
        // This is the census that says the guest really does address the console's low
        // memory; before the low region existed the same accesses were DROPPED, so this
        // counter and `dropped` together are the before/after pair.
        std::atomic<uint64_t> lowRegion{0};
    };
    F640Counters g_f640;

    constexpr uint64_t kF640PrintHead = 32;  // K in `n <= K || (n % 200) == 0`
    constexpr uint64_t kF640PrintMod = 200;
    bool F640Allow(uint64_t n) { return n <= kF640PrintHead || (n % kF640PrintMod) == 0; }

    // A call site that adopts the translation registers itself here, so the row can say how
    // many there are. Until one does, `zero_is_measured=0` and the zero means nothing.
    std::mutex g_reportMutex;
    BootReport g_report;
    std::atomic<bool> g_bootDone{false};
    // Per-thread, because the VEH handler runs on the faulting thread: a process-wide
    // pointer here printed the BOOT THREAD'S context for a fault on any other thread
    // (F-046). The tag names which context so a dump can never be mistaken again.
    thread_local const PPCContext* g_faultCtx = nullptr;
    thread_local const char* g_faultCtxTag = "none";
    // T41.5b: g_faultCtx is thread_local ON PURPOSE (F-046), which means every
    // cross-thread reader of it -- the PARK-SAMPLE heartbeat, and
    // GetBootWorkerReg() called from another thread -- has been silently reading
    // its own null copy. That is why all the guest fields in those lines printed
    // 0 in w108/w109; it was never evidence about the boot thread's state.
    // This is a deliberate process-wide mirror of just the boot worker's context.
    std::atomic<const PPCContext*> g_bootWorkerCtx{nullptr};
    uintptr_t g_moduleBase = 0;
    static DWORD s_bootWorkerThreadId = 0;
    // F-412: the PARK-SAMPLE sampler thread (set by the lambda in Start()). It is the one thread
    // the VEH must never park: it owns the worker's suspend count (boot_host.cpp SuspendThread /
    // ResumeThread), so a park there strands the worker suspended forever -- and if the worker was
    // suspended inside HeapGuardHandle/Arm holding g_hgMtx, every later guard trip deadlocks too.
    std::atomic<DWORD> s_parkSamplerTid{0};

    // B1 discriminator (F-094 open bit): hardware watchpoints on the two
    // globaltex.list member-page heads (stable VAs across w47-w50). A hit whose
    // host RIP is NOT our NtReadFile fill path means a real consumer touched the
    // member bytes; hits only from the fill path = the prototype tolerates the
    // raw opaque window as-is. Log-only, budgeted, self-disarming.
    constexpr uint32_t kB1WatchVas[2] = {0xC6157B80u, 0xC6167C00u};
    std::atomic<uint32_t> g_b1Hit[2]{};
    std::atomic<uint32_t> g_b1Logged{0};

    bool B1HandleSingleStep(PEXCEPTION_POINTERS ei) {
        CONTEXT* c = ei->ContextRecord;
        if (c == nullptr) return false;
        int slot = -1;
        if (c->Dr6 & 1ULL) slot = 0;
        else if (c->Dr6 & 2ULL) slot = 1;
        if (slot < 0) return false;  // not ours: let the rest of the VEH see it
        const uint32_t n = g_b1Hit[slot].fetch_add(1) + 1;
        const uint32_t ln = g_b1Logged.fetch_add(1) + 1;
        uint32_t glr = 0;
        if (const PPCContext* pc = GetPPCContext()) glr = (uint32_t)pc->lr;
        const uintptr_t rip = (uintptr_t)c->Rip;
        const uintptr_t rv = (g_moduleBase != 0 && rip >= g_moduleBase) ? rip - g_moduleBase : rip;
        if (ln <= 48) {
            MCLA_LOG_WARN("B1-WATCH slot={} va={:08X} hits={} tid={} hostRIP=0x{:X} guestLR={:08X}",
                          slot, kB1WatchVas[slot], n, GetCurrentThreadId(), rv, glr);
        } else {
            c->Dr7 &= ~(1ULL << 0 | 1ULL << 2);  // budget spent: disarm
        }
        c->Dr6 = 0;
        return true;  // ours: continue execution, no park/crash-dump
    }

    void B1ArmCurrentThreadImpl() {
        if (g_base == nullptr) {
            MCLA_LOG_WARN("B1-ARM tid={} SKIP base=null", GetCurrentThreadId());
            return;
        }
        CONTEXT ctx{};
        ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
        HANDLE self = GetCurrentThread();
        if (!GetThreadContext(self, &ctx)) {
            MCLA_LOG_WARN("B1-ARM tid={} FAIL getcontext err={}", GetCurrentThreadId(), GetLastError());
            return;
        }
        ctx.Dr0 = (DWORD64)(uintptr_t)(g_base + kB1WatchVas[0]);
        ctx.Dr1 = (DWORD64)(uintptr_t)(g_base + kB1WatchVas[1]);
        ctx.Dr6 = 0;
        ctx.Dr7 = (1ULL << 0) | (2ULL << 16) | (3ULL << 18)   // L0 RW len8
                | (1ULL << 2) | (2ULL << 20) | (3ULL << 22);  // L1 RW len8
        const bool ok = SetThreadContext(self, &ctx) != 0;
        MCLA_LOG_WARN("B1-ARM tid={} ok={} dr0={:X} dr1={:X}", GetCurrentThreadId(), ok,
                      (uintptr_t)ctx.Dr0, (uintptr_t)ctx.Dr1);
    }

    // B1 redo (rule 19 / F-100). Debug registers cannot be programmed from a
    // running thread, so the page-cache windows are watched with a guard page
    // instead: thread-agnostic, and its EFFECT is provable, because every arm is
    // followed by a deliberate one-byte read that must fault and log tag=SELFTEST
    // before the watch is left live. One trip per arm; the handler restores
    // PAGE_READWRITE and lets the accessor re-execute untouched, so the guest
    // sees no behavioural change beyond the log line.
    namespace {
        uintptr_t g_b1gHost = 0;
        SIZE_T g_b1gLen = 0;
        std::atomic<bool> g_b1gArmed{false};
        std::atomic<bool> g_b1gSelfTest{false};
        std::atomic<uint32_t> g_b1gTrips{0};
        std::atomic<uint32_t> g_b1gSelfTests{0};
        std::atomic<uint32_t> g_b1gLogged{0};
        // Every page this instrument has ever made inaccessible. A fault on any
        // of them is ours no matter what the protection looks like at handler
        // time: w62/w63 showed that claiming only the first trip let a second
        // thread's in-window fault reach the park machinery and parked a live
        // guest thread, which moved the frontier (GETDEV 168->116, fatal lost).
        constexpr int kB1gPages = 32;
        std::atomic<uintptr_t> g_b1gPages[kB1gPages];
        std::atomic<int> g_b1gPageN{0};

        bool B1GuardOwns(uintptr_t page) {
            const int n = g_b1gPageN.load(std::memory_order_acquire);
            for (int i = 0; i < n; ++i) {
                if (g_b1gPages[i].load(std::memory_order_relaxed) == page) return true;
            }
            return false;
        }

        void B1GuardClaim(uintptr_t page) {
            const int n = g_b1gPageN.load(std::memory_order_relaxed);
            if (n >= kB1gPages) return;
            g_b1gPages[n].store(page, std::memory_order_relaxed);
            g_b1gPageN.store(n + 1, std::memory_order_release);
        }
    }  // namespace

    bool B1GuardHandle(PEXCEPTION_POINTERS ei) {
        const EXCEPTION_RECORD* rec = ei->ExceptionRecord;
        if (rec == nullptr || rec->ExceptionCode != 0xC0000005L ||
            rec->NumberParameters < 2) {
            return false;
        }
        const uintptr_t fa = (uintptr_t)rec->ExceptionInformation[1];
        constexpr uintptr_t kPage = 0xFFFull;
        if (!B1GuardOwns(fa & ~kPage)) return false;
        const uint32_t n = g_b1gTrips.fetch_add(1) + 1;
        const bool wantWrite = (rec->ExceptionInformation[0] == 1);
        const bool wasWatched = g_b1gArmed.load(std::memory_order_acquire);
        DWORD old = 0;
        const uintptr_t page = fa & ~kPage;
        VirtualProtect((void*)page, 4096, PAGE_READWRITE, &old);
        g_b1gArmed.store(false, std::memory_order_release);  // one watch per arm
        if (g_b1gSelfTest.load()) {
            g_b1gSelfTests.fetch_add(1);
            MCLA_LOG_WARN("B1-GUARD tag=SELFTEST trip={} addr={:X} want={} tid={}", n, fa,
                          wantWrite ? "W" : "R", GetCurrentThreadId());
            return true;  // the read instruction re-executes on restored RW
        }
        if (g_b1gLogged.fetch_add(1) < 48) {
            const uintptr_t rip = (uintptr_t)ei->ContextRecord->Rip;
            const uintptr_t rv =
                (g_moduleBase != 0 && rip >= g_moduleBase) ? rip - g_moduleBase : rip;
            uint32_t glr = 0;
            if (const PPCContext* pc = GetPPCContext()) glr = (uint32_t)pc->lr;
            MCLA_LOG_WARN("B1-GUARD tag={} trip={} addr={:X} want={} hostRIP=0x{:X} "
                          "guestLR={:08X} tid={}",
                          wasWatched ? "ACCESS" : "LATE", n, fa, wantWrite ? "W" : "R",
                          rv, glr, GetCurrentThreadId());
        }
        return true;
    }

    void B1GuardArmImpl(uint32_t guestVa) {
        if (g_base == nullptr || guestVa == 0) return;
        constexpr SIZE_T kLen = 4096;
        const uintptr_t host = (uintptr_t)(g_base + guestVa) & ~(uintptr_t)0xFFF;
        DWORD old = 0;
        g_b1gHost = host;
        g_b1gLen = kLen;
        if (!VirtualProtect((void*)host, kLen, PAGE_NOACCESS, &old)) {
            MCLA_LOG_WARN("B1-GUARD arm-FAIL va={:08X} host={:X} err={}", guestVa, host,
                          GetLastError());
            return;
        }
        B1GuardClaim(host);
        g_b1gArmed.store(true, std::memory_order_release);
        g_b1gSelfTest.store(true, std::memory_order_release);
        volatile uint32_t sink = 0;
        sink = *reinterpret_cast<volatile uint32_t*>(host);  // must trip: proves the watch lives
        (void)sink;
        g_b1gSelfTest.store(false, std::memory_order_release);
        const bool rearmed =
            VirtualProtect((void*)host, kLen, PAGE_NOACCESS, &old) != 0;
        if (rearmed) g_b1gArmed.store(true, std::memory_order_release);
        MCLA_LOG_WARN("B1-GUARD armed va={:08X} host={:X} live={} selftests={} trips={}",
                      guestVa, host, rearmed ? 1 : 0, g_b1gSelfTests.load(),
                      g_b1gTrips.load());
    }

    // F-374: user-heap header watch, to name the writer that trashes the o1heap instance at
    // guest 0x20000 (F-370). Two facts make this the only instrument that can see it.
    // CORRECTED (F-412 review): the original first premise -- "PPC_STORE_U32 = `base[va]`, which
    // never touches the checked accessors where RegisterGuestWatchRange lives" -- is WRONG. The
    // verified chain is PPC_STORE_U32 (src/ppc_context.h:93) -> mcla::native::WriteGuestU32
    // (src/guest_memory.h:98) -> GuestMemoryView::WriteU32BE (src/guest_memory.cpp:354) ->
    // PageWatchHit/PageWatchOnWrite (src/guest_memory.cpp:369-372): a registered watch range DOES
    // see every guest dword store. What no watch range can see is the allocator itself, which
    // operates on the arena through a raw HOST pointer obtained from Translate (F-373: a checked
    // read of 0x20000 returns zeros while the allocator's own pointer sees cap=0x7FE7FDC0), and
    // SetThreadContext (CONTEXT_DEBUG_REGISTERS) on a running, un-debugged thread silently does
    // nothing (F-100), so the DR route is dead. Guard page it is, with the same
    // self-test-before-believing rule.
    // Page granularity is 4 KB and a trip is classified by offset into the instance -- but the
    // buckets still assume the pre-F-370 model that the first 40 bytes were the header. Per
    // o1heap.c:133-139 (and `instance+0x208` below) bins[64] run +0x00..+0x200, so off<8 counts
    // writes to bins[0..1] (routine alloc/free), not `capacity` (+0x208); fragments start +0x240.
    //
    // First attempt (build 17:23, w380) SEGFAULTED the host 34 ms in: the handler re-armed the
    // page before the faulting instruction re-executed, so every allocator write into that page
    // faulted again -> storm. The page is therefore only guarded while NO heap operation is in
    // flight: Heap::Alloc/Free disarm it under the heap mutex on entry and re-arm on exit (see
    // HeapGuardDisarm/HeapGuardArm), and the handler never re-arms.
    // F-637: forward decls, in mcla::boot (NOT in the anonymous namespace below, which would declare
    // different functions). The F388 cross-thread repair self-test runs inside PhysGuardArmImpl, which
    // is inside that namespace, and has to drive a window open and closed to reach the repair branch.
    void HeapGuardDisarmImpl();
    void HeapGuardArmImpl();
    namespace {
        constexpr uint32_t kHeapHdrVa = mcla::kernel::kUserHeapArenaVa;  // F-384: follows the arena
        constexpr uintptr_t kHdrCapEnd = 8;   // 'cap' bucket: bins[0..1] (capacity is +0x208)
        constexpr uintptr_t kHdrEnd = 0x28;   // 'hdr' bucket end (instance is 0x230 bytes)
        uintptr_t g_hgPage = 0;               // page-aligned host address of the header
        std::atomic<bool> g_hgLive{false};
        std::atomic<bool> g_hgSelfTest{false};
        std::atomic<uint32_t> g_hgSelfTests{0};
        std::atomic<uint32_t> g_hgArms{0};
        std::atomic<uint32_t> g_hgTrips{0};
        std::atomic<uint32_t> g_hgCapTrips{0};
        std::atomic<uint32_t> g_hgHdrTrips{0};
        std::atomic<uint32_t> g_hgFragTrips{0};
        std::atomic<uint32_t> g_hgLogged{0};

        // F-388: a second guard, over the PHYSICAL heap's instance page (guest
        // kPhysArenaBeginVa = 0xA0400000 since F-391 (old `RESERVED_END`, heap.cpp:250); it was
        // 0xA0000000, which is inside the title's own XTL heap). Why this page and not the other
        // one: `w394`..`w399` each AV once inside `o1heapAllocate+0x98`, a WRITE to 0xE49125FC
        // with rcx=0xE49125D4 and
        // rdi=r8=0x1A0000000 = the host address of THIS arena -- i.e. the allocator followed a link
        // whose value is a pointer that lost its high dword (Translate(0xE49125D4) = 0x1E49125D4).
        // Both pre-checks we have are clean at that moment: `o1heapDoInvariantsHold` passes (the
        // invariants FAIL line count is 0) and F-386's bin/link validator prints nothing, so the poison
        // is created between the check and the dereference. Only a write watch names the writer, and
        // unlike the user-heap guard this one prints the HOST BACKTRACE of the trip, because the fault
        // thread publishes no PPCContext (`ppc ctx=nil tag=none`) so guest lr would be another frame's.
        // Same two rules as F-374: prove the watch with a SELFTEST read before believing a silent one,
        // and never re-arm inside the handler (that storm segfaulted the host in w380).
        constexpr uint32_t kPhysHdrVa = mcla::kernel::kPhysArenaBeginVa;  // F-391: follows the pool
        uintptr_t g_pgPage = 0;
        std::atomic<bool> g_pgLive{false};
        std::atomic<bool> g_pgSelfTest{false};
        std::atomic<uint32_t> g_pgSelfTests{0};
        std::atomic<uint32_t> g_pgTrips{0};
        std::atomic<uint32_t> g_pgLogged{0};
        // F-637: the trip generation -- the repair obligation, made decidable from ANY thread.
        // The armed state of both guard pages used to be a pure function of g_hgDepth: open while
        // depth > 0, NOACCESS at depth 0. A trip BREAKS that function. PhysGuardHandle/HeapGuardHandle
        // must force the page open (w380 forbids re-arming inside the handler), so the page is now open
        // with g_pgLive=false at a depth of ZERO, and the only code in the tree that can put it back is
        // HeapGuardArmImpl, which returns early while any other thread's window is still open. So one
        // trip plus one stranded window leaves both pages PAGE_READWRITE for the rest of the run and
        // logs NOTHING: a guard that can strand silently is worse than no guard (F-637). Bumped by both
        // handlers on every forced open; compared by HeapGuardArmImpl, which then re-arms and says so
        // once. Cheap, and it makes "the window is disarmed after a trip" a property rather than a hope.
        std::atomic<uint32_t> g_hgTripGen{0};
        // g_hgMtx-guarded: the g_hgTripGen that the last successful arm accounted for. Only consulted
        // when g_hgDepth != 0; the normal depth-0 path arms unconditionally.
        uint32_t g_hgArmedTripGen = 0;
        // F-637: one-shot. A repair is expected exactly once per stranded window; a flood is the
        // F-054 log-poisoning class, and the depth it reports is already the loud part.
        std::atomic<uint32_t> g_hgRepairLog{0};

        // F-386 / F-412: ONE nesting depth covering BOTH guards, serialised by ONE mutex.
        // Before this the two arms were plain bools toggled from two different heap locks --
        // `mutex` inside Heap::Alloc/Free, `physicalMutex` inside AllocPhysical -- so thread A's
        // exit could re-arm the page while thread B was still inside o1heapAllocate, and that
        // false trip was charged to us (F-386: "the second guard page caught our own allocator").
        // A depth makes the page return to NOACCESS only when the LAST open window closes, which
        // makes arm/disarm safe regardless of where HeapGuardWindow sits relative to its
        // std::lock_guard -- the ordering rule heap.cpp:351 was itself an attempt at this, and
        // Heap::Free did not follow it (it opens its window before any lock, because
        // CheckHeapHeader reads the guarded page and must run disarmed).
        // recursive_mutex, not mutex: the deliberate self-test read below faults on THIS thread
        // and the VEH handler takes this same mutex to record the trip.
        std::recursive_mutex g_hgMtx;
        int32_t g_hgDepth = 0;  // guarded by g_hgMtx: open-window count, both guards together
        // F-412: the same open-window count kept PER THREAD. g_hgDepth cannot self-heal: the VEH
        // parks with `for(;;) Sleep(1000)` inside the handler, so ~HeapGuardWindow (heap.cpp:360)
        // never runs on that thread and a thread that is neither the boot worker nor UILOAD would
        // strand g_hgDepth > 0 forever -- both guard pages left PAGE_READWRITE for the rest of the
        // run plus the parked thread's heap mutex (heap.cpp:366/752) held with it. The park branch
        // drains t_hgWin (calls HeapGuardArmImpl while > 0) before it parks.
        thread_local int t_hgWin = 0;

        // -- locked cores. The caller holds g_hgMtx. --------------------------------------
        void PhysGuardDisarmImpl() {
            if (g_pgPage == 0 || !g_pgLive.load(std::memory_order_relaxed)) return;
            g_pgLive.store(false, std::memory_order_relaxed);
            DWORD old = 0;
            VirtualProtect((void *)g_pgPage, 4096, PAGE_READWRITE, &old);
        }

        // F-637: the cross-thread half of the guard self-test, and the only part that reaches the
        // repair path. PhysGuardHandle force-opens the page and may never re-arm it (w380), so a trip on
        // a thread that no other code path can reach leaves the page PAGE_READWRITE for the rest of the
        // run -- under the old `depth != 0 -> return` arm, silently. This reproduces exactly that state
        // change from a SECOND OS thread -- no fault, no VEH re-entry, no guest involvement -- touching
        // only the three words PhysGuardHandle touches, and returns only once the writes are visible, so
        // the caller's discharge is genuinely cross-thread rather than a same-thread accident.
        void PhysGuardForeignTripForTest() {
            std::thread t([] {
                g_pgLive.store(false, std::memory_order_relaxed);
                DWORD old = 0;
                VirtualProtect((void*)g_pgPage, 4096, PAGE_READWRITE, &old);
                g_hgTripGen.fetch_add(1, std::memory_order_relaxed);
            });
            t.join();
        }

        void PhysGuardArmImpl() {
            // ~(uintptr_t)0 is the "this guard is broken" marker, so an arm-FAIL does not turn into a
            // VirtualProtect attempt on every heap call.
            if (g_base == nullptr || g_pgPage == ~(uintptr_t)0) return;
            if (g_pgPage == 0) {
                // F-806: the watched page is the allocator's own header, and since F-779 it is NOT
                // at the arena base -- `o1heapInitSeparate` puts the instance in its own VirtualAlloc
                // block (heap.cpp:2717-2721) and initialises the root Fragment AT base
                // (o1heap.c:399-404), so `kPhysHdrVa` is now root-fragment header plus the payload of
                // the first allocation. MEASURED: w798 trips here at off=0x0 want=R with a guest
                // backtrace (`__imp__sub_825FA460+0x2a7` <- `__imp__sub_825EDC08+0x45d` <- ...), i.e.
                // a guest reading its own first physical block. The arena-base page is still the
                // fallback, because it is the only correct target if the instance is ever attached.
                uint8_t* const inst = PhysHeapInstanceMem();
                g_pgPage = (inst != nullptr) ? ((uintptr_t)inst & ~(uintptr_t)0xFFF)
                                            : (((uintptr_t)(g_base + kPhysHdrVa)) & ~(uintptr_t)0xFFF);
                MCLA_LOG_WARN("F388-PHYSGUARD target={} page={:X} inst={:p} arena_base_guest={:08X}",
                              inst != nullptr ? "detached-instance" : "arena-base(attached)",
                              g_pgPage, (void*)inst, kPhysHdrVa);
                DWORD old = 0;
                if (!VirtualProtect((void *)g_pgPage, 4096, PAGE_NOACCESS, &old)) {
                    MCLA_LOG_WARN("F388-PHYSGUARD arm-FAIL page={:X} err={}", g_pgPage,
                                  GetLastError());
                    g_pgPage = ~(uintptr_t)0;
                    return;
                }
                g_pgLive.store(true);
                g_pgSelfTest.store(true);
                volatile uint32_t sink = 0;
                sink = *reinterpret_cast<volatile uint32_t *>(g_pgPage);
                (void)sink;
                g_pgSelfTest.store(false);
                // F-412: the SELFTEST trip set g_pgLive=false and reopened the page
                // (PhysGuardHandle never re-arms -- w380), so without this the first real
                // physical-heap window ran unguarded. Same re-close as the user-heap side.
                if (VirtualProtect((void *)g_pgPage, 4096, PAGE_NOACCESS, &old))
                    g_pgLive.store(true, std::memory_order_relaxed);
                // F-637: the CROSS-THREAD repair proof, and the reason `xthread` appears on the SELFTEST
                // done line below. Steps, on this thread except (a):
                //   (a) a foreign thread force-opens the page exactly as PhysGuardHandle does: page
                //       PAGE_READWRITE, g_pgLive=false, g_hgTripGen bumped -- with no window open,
                //       which is what a trip always looks like from the guard's side;
                //   (b) two windows are opened, so the next arm still finds depth>0 AFTER its decrement.
                //       Depth is the only thing the old early-return consulted, so this is the one shape
                //       that reaches the repair branch at all;
                //   (c) the first arm closes: stranded=true AND a trip is unaccounted for, so it re-arms
                //       OVER the still-open window and logs F637-GUARDREPAIR;
                //   (d) the second arm returns depth to 0;
                //   (e) a deliberate read must FAULT -- and that read is the entire oracle. Were the page
                //       left writable, the read would succeed, PhysGuardHandle would never run, and
                //       g_pgSelfTests would not advance. A rising selftests count is therefore proof the
                //       page is NOACCESS, NOT proof that a log line printed. The single-arm selftest
                //       above cannot distinguish this: it runs at depth 0, where old and new agree.
                const uint32_t stBefore = g_pgSelfTests.load();
                uint32_t xthread = 0;
                try {
                    PhysGuardForeignTripForTest();
                    HeapGuardDisarmImpl();  // depth 2
                    HeapGuardDisarmImpl();
                    HeapGuardArmImpl();     // depth 1 -- stranded, repays the foreign trip
                    HeapGuardArmImpl();     // depth 0
                    g_pgSelfTest.store(true);
                    volatile uint32_t sink2 = 0;
                    sink2 = *reinterpret_cast<volatile uint32_t *>(g_pgPage);
                    (void)sink2;
                    g_pgSelfTest.store(false);
                    xthread = g_pgSelfTests.load() - stBefore;
                } catch (...) {
                    // A thread that could not be created proves nothing; say 0 rather than guess, so a
                    // soak can tell "the repair is broken" from "the test could not run".
                    xthread = 0;
                }
                // The (e) trip force-opened the page again, so pay the same debt the first selftest does.
                if (VirtualProtect((void *)g_pgPage, 4096, PAGE_NOACCESS, &old))
                    g_pgLive.store(true, std::memory_order_relaxed);
                MCLA_LOG_WARN("F388-PHYSGUARD SELFTEST done page={:X} selftests={} xthread={} "
                              "(selftests MUST be 1 and xthread MUST be 1, else this probe is blind)",
                              g_pgPage, g_pgSelfTests.load(), xthread);
                return;
            }
            if (g_pgLive.load(std::memory_order_relaxed)) return;
            DWORD old = 0;
            if (VirtualProtect((void *)g_pgPage, 4096, PAGE_NOACCESS, &old))
                g_pgLive.store(true, std::memory_order_relaxed);
        }

        bool PhysGuardHandle(PEXCEPTION_POINTERS ei) {
            if (g_pgPage == 0) return false;
            const EXCEPTION_RECORD *rec = ei->ExceptionRecord;
            if (rec == nullptr || rec->ExceptionCode != 0xC0000005L || rec->NumberParameters < 2)
                return false;
            const uintptr_t fa = (uintptr_t)rec->ExceptionInformation[1];
            if ((fa & ~0xFFFull) != g_pgPage) return false;
            std::lock_guard<std::recursive_mutex> lk(g_hgMtx);  // F-412: same reason as HeapGuardHandle
            const bool wasLive = g_pgLive.exchange(false);  // no re-arm here: see w380
            DWORD old = 0;
            VirtualProtect((void *)g_pgPage, 4096, PAGE_READWRITE, &old);
            // F-637: this force-open is a repair obligation no depth-0 path will ever discharge, because
            // the only re-arm (HeapGuardArmImpl) skips while another thread's window is open. Record it.
            g_hgTripGen.fetch_add(1, std::memory_order_relaxed);
            const uint32_t n = g_pgTrips.fetch_add(1) + 1;
            const uintptr_t rip = (uintptr_t)ei->ContextRecord->Rip;
            const uintptr_t mb = g_moduleBase ? g_moduleBase : 1;
            if (g_pgSelfTest.load()) {
                g_pgSelfTests.fetch_add(1);
                MCLA_LOG_WARN("F388-PHYSGUARD SELFTEST trip={} page={:X}", n, g_pgPage);
                return true;
            }
            if (g_pgLogged.fetch_add(1) < 3) {
                MCLA_LOG_ERROR("F388-PHYSGUARD trip={} off={:#X} want={} live={} hostRVA={:#x} "
                               "tid={} backtrace:",
                               n, fa - g_pgPage, rec->ExceptionInformation[0] == 1 ? "W" : "R",
                               wasLive, (uintptr_t)(mb ? rip - mb : rip), GetCurrentThreadId());
                void *frames[16] = {};
                const WORD nf = RtlCaptureStackBackTrace(0, 16, frames, nullptr);
                for (WORD i = 0; i < nf; ++i) {
                    const uintptr_t f = (uintptr_t)frames[i];
                    const bool inMod = mb && f >= mb && f < mb + 0x08000000u;
                    MCLA_LOG_ERROR("F388-PHYSGUARD-BT frame={}/{} rva={:x} inmod={}",
                                   static_cast<int>(i), static_cast<int>(nf),
                                   static_cast<unsigned long long>(inMod ? f - mb : f),
                                   inMod ? 1 : 0);
                }
            }
            spdlog::default_logger()->flush();
            return true;
        }
    }  // namespace

    bool HeapGuardHandle(PEXCEPTION_POINTERS ei) {
        if (g_hgPage == 0) return false;
        const EXCEPTION_RECORD* rec = ei->ExceptionRecord;
        if (rec == nullptr || rec->ExceptionCode != 0xC0000005L || rec->NumberParameters < 2)
            return false;
        const uintptr_t fa = (uintptr_t)rec->ExceptionInformation[1];
        if ((fa & ~0xFFFull) != g_hgPage) return false;  // not our page
        // F-412: serialise with arm/disarm, so the trip's "open the page" step cannot interleave
        // with a transition on another thread. recursive: the self-test read faults on this very
        // thread while it already holds g_hgMtx.
        std::lock_guard<std::recursive_mutex> lk(g_hgMtx);
        const bool wasLive = g_hgLive.exchange(false);   // no re-arm here: see the storm above
        const uintptr_t off = fa - g_hgPage;
        const bool wantWrite = (rec->ExceptionInformation[0] == 1);
        const uint32_t n = g_hgTrips.fetch_add(1) + 1;
        (void)off;
        if (off < kHdrCapEnd)
            g_hgCapTrips.fetch_add(1);
        else if (off < kHdrEnd)
            g_hgHdrTrips.fetch_add(1);
        else
            g_hgFragTrips.fetch_add(1);
        DWORD old = 0;
        VirtualProtect((void*)g_hgPage, 4096, PAGE_READWRITE, &old);
        // F-637: same obligation as PhysGuardHandle, same reason -- the handler cannot re-arm (w380), so
        // the page is left open and only a later HeapGuardArmImpl on ANY thread can close it again.
        g_hgTripGen.fetch_add(1, std::memory_order_relaxed);
        const uintptr_t rip = (uintptr_t)ei->ContextRecord->Rip;
        const uintptr_t rv =
            (g_moduleBase != 0 && rip >= g_moduleBase) ? rip - g_moduleBase : rip;
        uint32_t glr = 0;
        if (const PPCContext* pc = GetPPCContext()) glr = (uint32_t)pc->lr;
        const bool interesting = off < kHdrEnd || g_hgSelfTest.load();
        if (interesting && g_hgLogged.fetch_add(1) < 48)
            MCLA_LOG_ERROR("F374-HEAPGUARD trip={} off={:#X} want={} live={} selftest={} "
                           "hostRIP=0x{:X} rva={:#X} guestLR={:08X} tid={} "
                           "(cap={},hdr={},frag={})",
                           n, off, wantWrite ? "W" : "R", wasLive, g_hgSelfTest.load(), rip, rv,
                           glr, GetCurrentThreadId(), g_hgCapTrips.load(), g_hgHdrTrips.load(),
                           g_hgFragTrips.load());
        if (g_hgSelfTest.load())
            g_hgSelfTests.fetch_add(1);
        spdlog::default_logger()->flush();
        return true;
    }

    // Called by HeapGuardWindow on entry and exit. F-412: the two arms now go through
    // g_hgDepth + g_hgMtx, so the pages come back NOACCESS only when the last window closes and
    // neither Heap::Alloc nor Heap::Free can re-arm under the other's in-flight run.
    void HeapGuardDisarmImpl() {
        std::lock_guard<std::recursive_mutex> lk(g_hgMtx);
        ++g_hgDepth;
        ++t_hgWin;  // F-412: paired per-thread count, drained if this thread ever parks
        PhysGuardDisarmImpl();  // F-388: both guards, same window
        if (g_hgPage == 0 || !g_hgLive.load(std::memory_order_relaxed)) return;
        g_hgLive.store(false, std::memory_order_relaxed);
        DWORD old = 0;
        VirtualProtect((void*)g_hgPage, 4096, PAGE_READWRITE, &old);
    }

    void HeapGuardArmImpl() {
        std::lock_guard<std::recursive_mutex> lk(g_hgMtx);
        if (g_hgDepth > 0) --g_hgDepth;
        if (t_hgWin > 0) --t_hgWin;  // F-412: paired with the ++ in HeapGuardDisarmImpl
        // F-637: an arm is owed whenever a trip has force-opened a page that no arm has accounted for
        // yet -- and that obligation survives depth > 0, which is the entire point. A trip happens
        // OUTSIDE every window by construction: if the faulting thread held one, the page would have
        // been readable and there would be nothing to catch. So "another window is still open" is not
        // a reason to leave a page open as well, and the old bare `depth != 0 -> return` is exactly
        // what let one trip plus one stranded window silently disable both guards for the rest of the
        // run. F-412 fixed the parked-thread strand at two call sites (the VEH park branch and
        // UnhandledExceptionFilter); it did not fix a strand from any OTHER source, and a guard that
        // can strand silently is worse than no guard, so the obligation is discharged here instead.
        const bool stranded = (g_hgDepth != 0);
        if (stranded && g_hgArmedTripGen == g_hgTripGen.load(std::memory_order_relaxed)) {
            return;  // another window is open AND no trip is outstanding: leave both pages writable
        }
        PhysGuardArmImpl();  // F-388: the physical-heap guard shares this window
        g_hgArmedTripGen = g_hgTripGen.load(std::memory_order_relaxed);
        if (stranded && g_hgRepairLog.fetch_add(1) == 0) {
            // BootReportError, NOT MCLA_LOG_*: this TU holds __try and clang 19.1.7 ICEs instantiating
            // spdlog/fmt here (boot_host.h:161). `depth` is the reason the arm could not happen the old
            // way; a depth that never returns to 0 is a stuck thread and names itself in this one line.
            char lbuf[224];
            std::snprintf(lbuf, sizeof(lbuf),
                          "F637-GUARDREPAIR depth=%d tripGen=%u armedGen=%u - page(s) re-armed "
                          "OVER a still-open window; a thread has stranded g_hgDepth",
                          (int)g_hgDepth, g_hgArmedTripGen, (unsigned)g_hgTripGen.load());
            BootReportError(lbuf);
        }
        // F-412: ~(uintptr_t)0 is PhysGuardArmImpl's "this guard is broken" marker. It sits AFTER
        // the two decrements, not at the very top: a top-of-function return would skip them and
        // the park-branch drain (while t_hgWin > 0) would spin forever. With the marker the arm
        // attempt -- and the unbounded F374-HEAPGUARD arm-FAIL WARN per heap call that would
        // otherwise repeat (the F-054 log-poisoning class) -- is skipped entirely.
        if (g_hgPage == ~(uintptr_t)0) return;
        if (g_hgPage == 0) {
            if (g_base == nullptr) return;
            // F-806: same stale premise as the F-388 page above, and the false positive is measured.
            // `w798.log` trips at off=0x20 want=W, hostRIP inside vcruntime's memset, on the thread
            // immediately after `HEAPLEAK-SUM arena=user #1 nalloc=1 ... last_site_sz=0x40e90` --
            // i.e. the zero-fill of the FIRST user-arena block, which now lives at guest 0x20020
            // because F-779 moved the instance out and the root fragment starts at the arena base
            // (o1heap.c:399-404 + o1heap.c:517's `frag + O1HEAP_ALIGNMENT`). Guest 0x20000 is
            // ordinary block payload, not a header. The fallback is kept for the attached layout.
            uint8_t* const inst = UserHeapInstanceMem();
            g_hgPage = (inst != nullptr) ? ((uintptr_t)inst & ~(uintptr_t)0xFFF)
                                        : (((uintptr_t)(g_base + kHeapHdrVa)) & ~(uintptr_t)0xFFF);
            // Prove the watch is live before believing a silent one (F-100): one deliberate read
            // must trip and log tag=SELFTEST with selftest=true.
            DWORD old = 0;
            if (!VirtualProtect((void*)g_hgPage, 4096, PAGE_NOACCESS, &old)) {
                MCLA_LOG_WARN("F374-HEAPGUARD arm-FAIL page={:X} err={}", g_hgPage, GetLastError());
                g_hgPage = ~(uintptr_t)0;  // F-412: broken marker, as in PhysGuardArmImpl
                return;
            }
            g_hgLive.store(true);
            g_hgSelfTest.store(true);
            volatile uint32_t sink = 0;
            sink = *reinterpret_cast<volatile uint32_t*>(g_hgPage);
            (void)sink;
            g_hgSelfTest.store(false);
            // F-412: the SELFTEST trip set g_hgLive=false and reopened the page (HeapGuardHandle
            // must never re-arm inside the handler -- w380), and this first-arm path used to
            // return right here, so the whole NEXT heap window ran unguarded. Re-close it before
            // believing the probe: the read already completed, so this is not the w380 storm.
            if (VirtualProtect((void*)g_hgPage, 4096, PAGE_NOACCESS, &old))
                g_hgLive.store(true, std::memory_order_relaxed);
            MCLA_LOG_WARN("F374-HEAPGUARD SELFTEST done page={:X} trips={} selftests={} "
                          "(selftests MUST be 1, else this probe is blind)",
                          g_hgPage, g_hgTrips.load(), g_hgSelfTests.load());
            return;
        }
        if (g_hgLive.load(std::memory_order_relaxed)) return;
        DWORD old = 0;
        if (VirtualProtect((void*)g_hgPage, 4096, PAGE_NOACCESS, &old))
            g_hgLive.store(true, std::memory_order_relaxed);
    }

    // Reverse map: host function entry -> guest address, for fault triage.
    std::unordered_map<uintptr_t, uint32_t> g_hostToGuest;
    void InsertFunction(uint32_t guest, PPCFunc* host)
    {
        PPC_LOOKUP_FUNC(g_base, guest) = host;
    }

    // Re-write one function-table slot from the canonical mapping. Used when
    // guest allocs (the CDCD-FILL band) zero entries inside the table region,
    // which PPC_LOOKUP_FUNC puts at PPC_IMAGE_BASE + PPC_IMAGE_SIZE = 0x829E0000+.
    void RemapFunctionSlot(uint32_t guest)
    {
        if (g_base == nullptr)
            return;
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if ((uint32_t)PPCFuncMappings[i].guest == guest)
            {
                InsertFunction(guest, PPCFuncMappings[i].host);
                return;
            }
        }
    }

    static uint32_t ReadU32BE(uint8_t* base, uint32_t guestAddr)
    {
        return __builtin_bswap32(*(volatile uint32_t*)(base + guestAddr));
    }

    static void WriteU32BE(uint8_t* base, uint32_t guestAddr, uint32_t value)
    {
        *(volatile uint32_t*)(base + guestAddr) = __builtin_bswap32(value);
    }

    bool AllocateGuestMemory()
    {
        // Share the window Memory::Memory() reserved at static-init so every
        // translation frontend (g_memory, GuestMemoryHeap, GuestMemoryView)
        // sees identical host addresses for a given guest address. Skipping
        // this forked the address space: g_memory stayed on its own window
        // while the boot host allocated a second one at a random base.
        if (mcla::kernel::g_memory.base != nullptr && mcla::kernel::g_memory.size >= GuestMemorySize)
        {
            g_base = mcla::kernel::g_memory.base;
            return true;
        }

        g_base = (uint8_t*)VirtualAlloc((void*)GuestMemoryBase, GuestMemorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (g_base == nullptr)
        {
            // Fallback: any 32-byte-aligned region works (recomp code requires base % 0x20 == 0).
            g_base = (uint8_t*)VirtualAlloc(nullptr, GuestMemorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        }
        if (g_base == nullptr)
        {
            return false;
        }

        // Keep g_memory in sync with whichever window we actually got.
        mcla::kernel::g_memory.base = g_base;
        mcla::kernel::g_memory.size = GuestMemorySize;

        // First-page NOACCESS guard (UnleashedRecomp canonical): trap null derefs
        DWORD oldProtect;
        VirtualProtect(g_base, 4096, PAGE_NOACCESS, &oldProtect);
        return true;
    }

    void InstallGuestImage(const Image& image)
    {
        std::memcpy(g_base + image.base, image.data.get(), image.size);
    }

    __attribute__((noinline)) void DumpImageRegion(uint32_t guestAddr, uint32_t words)
    {
        char lbuf[512];
        size_t o = 0;
        o += std::snprintf(lbuf + o, sizeof(lbuf) - o, "[boot] region-dump 0x%08X:", guestAddr);
        for (uint32_t i = 0; i < words; i++)
        {
            uint32_t v = ReadU32BE(g_base, guestAddr + i * 4);
            o += std::snprintf(lbuf + o, sizeof(lbuf) - o, " %08X", v);
        }
        BootReportInfo(lbuf);
    }

    size_t InstallFunctionTable()
    {
        size_t inserted = 0;
        g_hostToGuest.clear();
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            const uint32_t guest = (uint32_t)PPCFuncMappings[i].guest;
            PPCFunc* host = PPCFuncMappings[i].host;
            InsertFunction(guest, host);
            g_hostToGuest.emplace((uintptr_t)host, guest);
            inserted++;
        }
        // Runtime holes: 8C760 bctrls to vtable+88 = 0x821A5CC0 and AVs
        // when the table slot is null. Force-map the no-op stub.
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if ((uint32_t)PPCFuncMappings[i].guest == 0x821A5CC0u)
            {
                InsertFunction(0x821A5CC0u, PPCFuncMappings[i].host);
                char lbuf[128];
                std::snprintf(lbuf, sizeof(lbuf),
                              "[boot] force-map 821A5CC0 -> %p",
                              (void*)PPCFuncMappings[i].host);
                BootReportInfo(lbuf);
                break;
            }
        }
        return inserted;
    }

    // Nearest guest function whose start address is <= `guest` (a return address).
    const char* GuestFunctionName(uint32_t guest)
    {
        static thread_local char buf[128];
        uint32_t best = 0;
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if (PPCFuncMappings[i].guest <= guest && PPCFuncMappings[i].guest > best)
                best = (uint32_t)PPCFuncMappings[i].guest;
        }
        if (best != 0)
        {
            std::snprintf(buf, sizeof(buf), "0x%08x", best);
            return buf;
        }
        std::snprintf(buf, sizeof(buf), "0x%08x (unmapped)", guest);
        return buf;
    }

    // F-609: block geometry. Copied from kernel/guest_thread.cpp:11-17, NOT
    // re-derived -- GuestThreadContext's TOTAL is 0x40E90 and a second,
    // slightly different block layout is the same class of bug as the alias
    // itself. TEB_OFFSET there is PCR+TLS (0xBB0), which is where the +0x150 /
    // +0x160 "want errors" / last-error fields the boot block documents
    // (boot_host.cpp:731-733) are NOT: in a real block +0x150 is inside the
    // TEB. Recorded here so the next reader does not reconcile the two
    // comments and "fix" the offset.
    //
    // Declared ABOVE SetupInitialContext, which registers the static block and
    // self-tests AllocateGuestThreadBlock. Line numbers quoted in the
    // F-609 comments below are PRE-EDIT values; re-measure with grep (rule 13)
    // before repeating them in a doc. Post-edit anchors: SetupInitialContext is
    // called from BootWorker at :1353, after LoadAndPrepare's g_userHeap.Init()
    // at :2078, so the heap is live when the self-test runs.
    namespace {
        constexpr size_t F609PcrSize = 0xAB0;
        constexpr size_t F609TlsSize = 0x100;
        constexpr size_t F609TebSize = 0x2E0;
        constexpr size_t F609StackSize = 0x40000;
        constexpr size_t F609TotalSize = F609PcrSize + F609TlsSize + F609TebSize + F609StackSize;  // 0x40E90
        constexpr size_t F609TebOffset = F609PcrSize + F609TlsSize;                                // 0xBB0

        // pcr VA -> owning host thread's tag. Attribution only: nothing the
        // guest executes reads it, so a miss or a stale entry cannot change
        // behaviour. Guest-visible PCR bytes are the o1heap payload, NOT here.
        std::mutex g_f609TagMutex;
        std::unordered_map<uint32_t, const char*> g_f609Tags;

        void RegisterBlockTag(uint32_t pcrVa, const char* tag)
        {
            if (pcrVa == 0 || tag == nullptr)
                return;
            std::lock_guard lock(g_f609TagMutex);
            g_f609Tags[pcrVa] = tag;
        }
    } // namespace

// F-635: __except filter for the F-609 block self-test. MSVC restricts
// GetExceptionInformation() to the filter expression, so the address and the
// exception information have to be copied out here, through pointers to locals
// declared in the enclosing function. Returns EXCEPTION_EXECUTE_HANDLER, so the
// handler body runs and the boot continues instead of dying.
static int F635CaptureFilter(EXCEPTION_POINTERS* ep, uintptr_t* outAddr,
                             int* outInfoN, uint32_t* outInfo) {
    if (ep == nullptr || ep->ExceptionRecord == nullptr) {
        *outAddr = 0;
        *outInfoN = 0;
        return EXCEPTION_EXECUTE_HANDLER;
    }
    *outAddr = reinterpret_cast<uintptr_t>(ep->ExceptionRecord->ExceptionAddress);
    const ULONG n = ep->ExceptionRecord->NumberParameters;
    *outInfoN = static_cast<int>(n);
    for (ULONG i = 0; i < n && i < 4; ++i)
        outInfo[i] = static_cast<uint32_t>(ep->ExceptionRecord->ExceptionInformation[i]);
    return EXCEPTION_EXECUTE_HANDLER;
}


    void SetupInitialContext(PPCContext& ctx)
    {
        std::memset(&ctx, 0, sizeof(ctx));

        // Seed the FPSCR cache from the real host MXCSR. The recompiled code
        // only toggles rounding + flush bits via ctx.fpscr; if the cache starts
        // at zero, the first enableFlushMode() writes MXCSR = 0x8040, clearing
        // the exception-mask bits (0x1F80) and unmasking host FPU exceptions
        // (STATUS_FLOAT_MULTIPLE_FAULTS = 0xC00002B4; 0xC000008F is INEXACT_RESULT) in guest FP.
        // The mask bits are ORed in defensively (guest FP never faults on 360).
        ctx.fpscr.csr = ctx.fpscr.getcsr() | 0x1F80;

        // 2 MiB guest stack, clear of the image (image ends around 0x829E0000).
        constexpr uint32_t StackTop = 0x8F000000u;
        constexpr uint32_t StackSize = 0x200000u;
        std::memset(g_base + StackTop - StackSize, 0, StackSize);

        ctx.r1.u32 = StackTop; // r1 = stack pointer (grows down)
        ctx.msr = 0x200A000;   // FP/VMX bits, matches PPCContext default

        // Xbox 360 entry point (_xstart) expects:
        // r3 = module handle (image base)
        // r4 = reason (DLL_PROCESS_ATTACH = 1)
        // r5 = reserved (0)
        ctx.r3.u32 = 0x82000000; // image base
        ctx.r4.u32 = 1;          // DLL_PROCESS_ATTACH
        ctx.r5.u32 = 0;

        // Guest r13 thread block + XTL import dispatch chain.
        //
        // The generated thunks sub_82130528/550/588 (XTL allocation import)
        // resolve through r13:
        //   r11 = *(r13); r3 = *(r11 + 28); r9 = *r3; fn = *(r9 + 8|12); call fn
        // so slot 7 (offset 28) of the table at *(r13) must point at a
        // descriptor whose first word points at a function block holding the
        // alloc/free guest addresses at +8/+12. The resolved address is looked
        // up in the function table (PPC_CALL_INDIRECT_FUNC), so those guest
        // addresses must be registered via InsertFunction.
        //
        // The same block also serves the other r13 consumers found in the game:
        //   r13+0x100 (256): TEB pointer (last error stored at TEB+0x160)
        //   r13+0x10C (268): cpu number (byte)
        //   r13+0x150 (336): "program doesn't want errors" flag
        constexpr uint32_t ThreadBlock = 0x8F200000u; // clear of stack (0x8F000000) and image
        constexpr uint32_t TableBase = ThreadBlock + 0x1000;
        constexpr uint32_t Descriptor = ThreadBlock + 0x2000;
        constexpr uint32_t FuncBlock = ThreadBlock + 0x3000;
        constexpr uint32_t AllocFnGuest = ThreadBlock + 0x4000;
        constexpr uint32_t FreeFnGuest = ThreadBlock + 0x4010;
        constexpr uint32_t Teb = ThreadBlock + 0x5000;

        const auto storeU32 = [](uint32_t guestAddr, uint32_t value) {
            *(volatile uint32_t*)(g_base + guestAddr) = __builtin_bswap32(value);
        };

        std::memset(g_base + ThreadBlock, 0, 0x10000);

        ctx.r13.u32 = ThreadBlock;
        storeU32(ThreadBlock + 0x000, TableBase);
        storeU32(ThreadBlock + 0x100, Teb);
        *(volatile uint8_t*)(g_base + ThreadBlock + 0x10C) = 0; // cpu number
        storeU32(ThreadBlock + 0x150, 0);                       // "want errors" flag

        storeU32(TableBase + 28, Descriptor);
        storeU32(Descriptor + 0, FuncBlock);
        storeU32(FuncBlock + 8, AllocFnGuest);
        storeU32(FuncBlock + 12, FreeFnGuest);

        InsertFunction(AllocFnGuest, &__xtl_alloc);
        InsertFunction(FreeFnGuest, &__xtl_free);

        // F-609: the static block above STAYS at 0x8F200000. Two measured
        // dependents make moving it unsafe in this pass, and both are in files
        // this agent does not own:
        //   gpu_device.cpp:20489-20496 -- sub_8242FB88 writes the TLS chain
        //     into a HARD-CODED kBootWorkerTlsTable = 0x8F201000 (= this
        //     block + 0x1000 = TableBase) and its own comment admits "the boot
        //     worker may start with a temporary r13; we hardcode the known TLS
        //     table". Move r13 and that write lands on a dead table.
        //   gpu_device.cpp:20385, 20500, 20536 -- the three chain-heal guards
        //     are s_tlsChainInitDone / s_bootWorkerTlsInit /
        //     s_bootWorkerTlsInit2, each `fetch_add(1) == 0`, i.e. once per
        //     PROCESS. gpu_device.cpp:20382-20383 justifies that with "all
        //     threads share r13=0x8F200000 and tlsTable=0x8F201000, so one-time
        //     init suffices" -- which is FALSE the moment blocks are per-thread.
        //     Those three must become per-VA before any r13 moves.
        // So: register the alias by NAME (pure attribution, no register change)
        // and self-test the new allocator, leaving the guest-visible registers
        // exactly where they are.
        RegisterBlockTag(ThreadBlock, "boot-worker:static-8F200000");

        // F-636 (w656): the F-609 self-test is REMOVED from the boot path, not
        // repaired in place. Measured sequence:
        //   w655 - the call faulted (0xC0000005, no VEH row) and killed the
        //           process 160 lines in.
        //   w656 - wrapped in __except it reported
        //           `THREW addr=0x0 nParams=2 p0=0x00000000 p1=0xA0400000`,
        //           i.e. a NULL host pointer dereferenced with a length of
        //           exactly kPhysArenaBeginVa. The fault is therefore INSIDE
        //           the allocator, not in the block bookkeeping around it --
        //           and an exception unwinding out of g_userHeap.Alloc leaves
        //           the o1heap instance half-updated.
        //   The consequence is visible and is the reason for removal: w656
        //   produced 1,154 log lines against w654's 166,256, with no
        //   BOOTPATH, no DISCCHK, no F556-C54D8 and no CP-DRAW at all. The
        //   guest never left the installer. A probe that damages the thing it
        //   is probing is worse than no probe: it costs a boot AND produces a
        //   fault that the universal gate counts against the change.
        //
        //   AllocateGuestThreadBlock / ReleaseGuestThreadBlock / LookupGuestThreadBlockTag stay in the
        //   tree, UNUSED AND UNPROVED. Nothing may call the first two until a soak can show one
        //   allocation and one release with PHYS-VERDICT-CHANGE staying `healthy`. The wake-up
        //   condition is explicit, not a date.
        //
        //   F-637 CORRECTION: the "all three unused" claim above was FALSE and was falsified by
        //   measurement, not by inspection. LookupGuestThreadBlockTag has a live caller at :2677 (the
        //   park-sampler mirror row) and has had one since it was introduced. It is a pure
        //   std::unordered_map lookup under g_f609TagMutex (:1202) and reads NO guest memory, so it
        //   needs no allocation to be reachable -- which is exactly why "unused" was the wrong
        //   inference to draw from "no F609-BLOCK line in any soak": a map miss is silent, and a
        //   hit is silent. w657.log:811 prints `tag=boot-worker:static-8F200000` from that call
        //   19 s into the run. The first two remain genuinely uncalled; that half of the claim stands.
        (void)0;
    }

    // T4-final: faithful replay of the dead memory-device ctor / Mount("memory:")
    // special path. GETDEV("memory:"/"embedded:/") returns the static Device*
    // 0x827D838C (sub_821CB488: lis r11,-32130; addi r3,r11,-31860). The CRT
    // initializer sub_827B8B38 only installs the BASE vtable 0x8201206C whose
    // +16 slot is the no-op stub 0x82762480, so EMB76 (open = 0x821CB070 on
    // vtable 0x82012918+16) never fires. Replay the stores the dead chain
    // should have produced, before CRT overwrites and before shader preload.
    //
    // Field cites (guest store instructions, identity map VA-0x82000000):
    //   [0x827D838C] = 0x82012918   // vtable: CRT sub_827B8B38 stw r11,-31860(r10)
    //                                 //   but r11 must be the MEMORY table
    //                                 //   (scan of .rdata: 82012918 holds
    //                                 //    AE50/AFB8/CB070/CB400), not base
    //                                 //   0x8201206C (addi r11,r11,8300).
    //   [0x827D8380] = 0x827D838C   // fallback Device*: Mount sub_821CB9D8
    //                                 //   stw r26,-31872(r11) for path=="memory:"
    //   name "memory:" @ image       // Mount/GETDEV prefix, string 0x820127D8
    //   276-byte handler link        // Mount general path: sub_821CB760 inits
    //                                 //   entry+268/272/274; name at +0, flag
    //                                 //   +262, nameLen +264. GETDEV prefix
    //                                 //   path does not scan this table, so
    //                                 //   the link is installed for the
    //                                 //   fallback/no-prefix path only.
    // ======================================================================
    // F-640: THE .CRT$XCU STATIC-INITIALISER WALK — LAYOUT, CONVENTION, AND
    // WHY THE 15-ENTRY SUBSTITUTE BELOW IS NOT A SUBSTITUTE ANY MORE
    // ======================================================================
    // The comment this block replaces is kept here, quoted, because it is the
    // record of a real past decision and the next reader needs to know it was
    // WRONG rather than silently rewritten:
    //
    //   WAS: "Seed the embedded:/ name list with static .data blobs that the
    //   CRT .CRT$XCU inits would have registered via sub_821D22E8. Our boot
    //   host jumps at the game entry and those inits never run — AFB76
    //   therefore sees an empty list." + a 15-row hand-typed table.
    //
    // BOTH HALVES OF THAT ARE FALSE, and the second one is false in a way that
    // cost a boot. Re-measured 2026-09-30; nothing below is inherited.
    //
    // (1) THE INITIALISERS DO RUN. The entry point this host jumps at IS the
    //     guest's own C-runtime start. Image entry RVA 0x1322B8 -> VA
    //     0x821322B8 (`[boot] image base ... entry 0x821322B8`, w666.log:53).
    //     Its unconditional prefix contains `bl sub_82132820` at 0x82132310
    //     and `bl sub_82132740` at 0x82132318; the only branch in that
    //     stretch (0x82132300) skips 0x82132304 alone. sub_82132740 IS the
    //     XCU walker: `addi r10,r10,16` / `addi r30,r11,5104` at
    //     0x82132778/0x8213277C over a `mtctr; bctrl` loop. `tools/
    //     addr_owners.py --check 0x82132740` reports one owner and it is the
    //     plain recompiled mapping (generated/ppc_xenon/ppc_func_mapping.cpp
    //     :112) — no host override, no stub. The console's stage and this
    //     host's stage are the same code, so there is nothing to skip and
    //     nothing to substitute. Adding a second host-side run here would
    //     DOUBLE-INITIALISE 1267 constructors: fabrication, and a divergence
    //     from the hardware in the one place the hardware is the reference.
    //
    // (2) THE SEED COULD NOT WIN EVEN IF IT RAN FIRST, and it does: it runs
    //     here, in LoadAndPrepare, and the initialisers run later, from the
    //     entry point. The seed's 15 `node` addresses ARE the 15 static nodes
    //     the initialisers write, so every word is overwritten. The row that
    //     settles it is w666.log:16255 —
    //       AFB76-HIT #4 path='embedded:/fxl_final/rage_postfx.fxc'
    //                  buf=8281BB00 size=38024
    //     38024 is the literal sub_827B4E80 passes (`lis r6,0` at 0x827B4E8C,
    //     `ori r6,r6,0x9488` at 0x827B4E9C). The hand-typed table said 48 for
    //     that same field. All five rage_* hits in w666 carry ctor sizes.
    //
    // (3) A 4-BYTE HEAD DEFECT, present in BOTH this file and the reader in
    //     src/gpu_device.cpp. The guest links the list through `lis r10,8286`
    //     + 2804 = 0x82860AF4 (`lwz r11,2804(r10)` at 0x821D22F8, `stw r3,
    //     2804(r10)` at 0x821D2300, sub_821D22E8). This seed writes
    //     0x82860AF8; gpu_device.cpp's `kEmbeddedNameListHead` is 0x82860AF8
    //     with the trailing comment `// lis -32122 + 2804`, whose own
    //     arithmetic gives 0xAF4. So the seed has only ever worked as a
    //     BRIDGE: its head word is the entry point, its first `next` is
    //     clobbered by the guest, and the walk continues into the guest's own
    //     chain at 0x82860AF4 — which is why w666 shows 15 nodes and correct
    //     sizes from a table that is 14/15 stale. EXACT CHANGE NEEDED in
    //     src/gpu_device.cpp (NOT this file's, and not edited here):
    //     `kEmbeddedNameListHead = 0x82860AF8` -> `0x82860AF4`. When that
    //     lands, SeedEmbeddedNameList() goes with it and nothing else changes.
    //
    // (4) STILL NOT THE FIX FOR `Shadows`, and it must not be read as one.
    //     `Shadows` is registered by NONE of the 15 and cannot be: the call
    //     sites name exactly these fifteen (`fxl_final/rage_im.fxc` ..
    //     `fxl_final/rage_postfx.fxc`), see the F640-XCU-REG rows this boot
    //     prints. The fatal is a SERVE gap. The census prints
    //     `hostSlotCollisions=0` precisely so nobody re-derives "the ctors
    //     were skipped" from it a third time.
    //
    // WHAT IS HERE NOW: the 15 registrations are DECODED FROM THE INSTALLED
    // IMAGE at run time, out of the same `bl sub_821D22E8` sites the hardware's
    // linker emitted, instead of being typed in by hand. For 14 of 15 the
    // words written are byte-identical to the old table, so the boot is
    // unchanged; the 15th gets 38024 instead of 48, which is the correction.
    // Nothing here can drift from the guest again, and no guest value is ever
    // asserted on: every decoded field is shape-checked and refused by name.

    // The table the walker loops over, from the walker's own two `addi`s. NOT
    // from the section table: the PE header in build/cache/mcla_pe.bin has 13
    // sections and no `.CRT` among them, and its raw offsets disagree with its
    // virtual addresses (.text rawoff 0x12C800 vs vaddr 0x130000; .data
    // 0x7C9A00 vs 0x7D0000), so the table is found in the bytes and then
    // verified at run time (the word AT `end` is the zero sentinel) before a
    // single byte is written. All 1267 entries are present in
    // generated/ppc_xenon/ppc_func_mapping.cpp, and 1265 of 1266 adjacent
    // pairs are non-decreasing — the address order a linker emits.
    //
    // THE TWO CITATIONS BELOW WERE WRONG UNTIL 2026-09-30; THE VALUES NEVER
    // WERE. The old comment named sub_82132778 / sub_8213277C, whose raw words
    // are `394A13E4` (addi r10,r10,5092) and `3BCB13F0` (addi r30,r11,5104):
    // over the `lis r10,0x827D` / `lis r11,0x827D` pair at 0x82132770/74 those
    // materialise 0x827D13E4 and 0x827D13F0 -- the bounds of the OTHER loop in
    // the same function, 0x50 bytes along. The XCU bounds come from the pair
    // BELOW them: sub_821327C8 `394A0010` (addi r10,r10,16) -> 0x827D0010 and
    // sub_821327CC `3BCB13E0` (addi r30,r11,5088) -> 0x827D13E0. So the two
    // constants were right and only the instructions named to justify them
    // were not, and they named the adjacent array.
    //
    // The mis-citation was not cosmetic, because the two loops differ in KIND.
    // Loop A (0x82132770..0x821327BC) tests `cmpi cr6,r3,0` at 0x82132790 and
    // bails out of the entire walk on a non-zero constructor return. Loop B
    // (0x821327C0..0x82132800) -- the one that walks THIS array -- has no such
    // test; it falls through to `li r3,0` at 0x82132804. And loop B null-skips
    // 0 (`cmpli cr6,r11,0`, 0x821327E0) and 0xFFFFFFFF (`cmpi cr6,r11,-1`,
    // 0x821327E8) without leaving. The array whose first word is a NULL prefix
    // is therefore exactly the array that does not bail on it.
    //
    // The .CRT layout, read from build/cache/mcla_pe.bin (offset = VA -
    // 0x82000000, words big-endian). THREE arrays, and every one of them is
    // NULL-prefixed and NUL-terminated one word past its last slot:
    //   0x827D0000 .. 0x827D000C   0, 823D9930, 823E3CB8   end 0 at 0x827D000C
    //   0x827D0010 .. 0x827D13E0   0, then 1267 .text pointers   <-- THIS ONE
    //   0x827D13E4 .. 0x827D13F0   0, 823E1170, 823E6590   end 0 at 0x827D13F0
    // 0x13D0 / 4 = 1268 words, so kCrtXcuMaxSlots = 8192 is a backstop this
    // table can never reach: of the 1268, one is 0, 1267 are non-null, none is
    // 0xFFFFFFFF, and all 1267 fall inside [kTextLo,kTextHi]. 1267 of the
    // 45,190 guest addresses in generated/ppc_xenon/ppc_func_mapping.cpp, 0
    // missing, 1267 distinct. 1265 of the 1266 adjacent entry pairs are
    // non-decreasing; the one exception is entry 19, 827A9458 -> 827A78F0.
    static constexpr uint32_t kCrtXcuBegin = 0x827D0010u; // sub_821327C8: addi r10,r10,16   (loop B)
    static constexpr uint32_t kCrtXcuEnd   = 0x827D13E0u; // sub_821327CC: addi r30,r11,5088 (loop B)
    static constexpr uint32_t kCrtWalker   = 0x82132740u; // the function that walks it
    static constexpr uint32_t kCrtWalkCall = 0x82132318u; // `bl sub_82132740` inside _xstart
    static constexpr uint32_t kCrtXcuMaxSlots = 8192u;    // 0x13D0 bytes = 1268 slots, measured
    // kTextHi is INCLUSIVE -- it is the last .text byte, not one past it -- so
    // the containment test below is `v >= kTextLo && v <= kTextHi`, and the
    // marker prints the pair as textRange= so "in text" is checkable from the
    // log instead of taken on trust. Unchanged: making the bound half-open
    // would move the meaning of the existing nonNull/truncated fields.
    static constexpr uint32_t kTextLo = 0x82130000u, kTextHi = 0x827BDCE4u;
    static constexpr uint32_t kRdataLo = 0x82000600u, kRdataHi = 0x82102824u;
    static constexpr uint32_t kDataLo = 0x827D0000u, kDataHi = 0x8294A72Cu;

    // Words the HOST substitutes in this same function family, i.e. the only
    // addresses a static initialiser could collide with. The memory-device
    // vtable slot and its fallback pointer (ReplayDeadMemoryDeviceCtor, below),
    // the scratch table pointer (SeedPreBootSlots, below), and both candidate
    // list heads. The census checks all 15 registrations against all of them.
    static constexpr uint32_t kHostSubstSlots[] = {
        0x827D8380u, 0x827D838Cu, 0x8288E5ACu, 0x82860AF4u, 0x82860AF8u};

    // The 15 `bl sub_821D22E8` call sites: `tools/ppc_xrefs.py calls
    // 0x821D22E8` -> 15 sites, every one inside 0x827A..0x827B. A measured
    // search result, not a discovery, and each one is re-decoded at run time
    // rather than trusted.
    static constexpr uint32_t kD22E8Sites[] = {
        0x827A7FCCu, 0x827A821Cu, 0x827AD164u, 0x827AFC74u, 0x827B0534u,
        0x827B0554u, 0x827B0574u, 0x827B0594u, 0x827B1044u, 0x827B1064u,
        0x827B10C4u, 0x827B4B54u, 0x827B4B74u, 0x827B4B94u, 0x827B4EA0u};

    struct CrtReg {
        uint32_t site, node, name, buf, size;
    };

    // Decode r3/r4/r5/r6 at one call site by scanning the constructor block that
    // ENDS at the `bl`. FORWARD, not backward: a constructor materialises its
    // argument addresses in address order — `lis r11` / `lis r10` / `lis r9` first
    // (sub_827A7FB0: 0x827A7FB0/B4/B8), then the `addi`s that fold the low halves
    // (0x827A7FBC/C0/C4), then the size (0x827A7FC8) — so a backward pass meets the
    // `addi`s before their bases exist. Only `lis`(15) / `addi`(14) / `ori`(24) are
    // understood; ANY other opcode (the previous constructor's tail `b`, or its
    // 0x00000000 padding) resets the register state, which is what keeps one
    // constructor's bases out of the next one's arguments. A register only counts
    // if it was written AFTER the last reset. The window is 0x30 bytes, the widest
    // measured block is 0x24 (sub_827B4E80, the one that needs the two-word
    // `lis r6,0` + `ori r6,r6,imm` size form; the other fourteen use
    // `addi r6,0,imm`).
    //
    // CALLING CONVENTION, verified from those bodies rather than assumed: the
    // entry is `void(void)`. Each is a leaf with no `mflr`, no `stwu` and no
    // stack traffic — sub_827A7FB0 is nine instructions ending in a tail `b` — it
    // clobbers only r9/r10/r11, and the walker itself sets up NO arguments
    // (`mtctr r11; bctrl` with r3 already 0 from `li r3,0` at 0x82132784). It
    // also aborts the remaining entries if a constructor returns non-zero in r3
    // (the `cmpi cr6,r3,0` at 0x82132790), which is the console's behaviour and is
    // therefore reproduced by NOT running the walk at all.
    //
    // `why` names the refusal; nothing here asserts on a guest value.
    static bool DecodeCrtRegistration(uint32_t site, CrtReg& out, const char** why)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        static constexpr uint32_t kUnset = 0xDEADBEEFu; // a `lis` result has low 16 bits zero
        static constexpr int kNoPos = -1;
        uint32_t hi[32];
        uint32_t reg[32] = {};
        int pos[4];
        int lastReset = kNoPos;
        for (uint32_t i = 0; i < 32; ++i)
            hi[i] = kUnset;
        hi[0] = 0; // r0 reads as zero, so `addi rT,0,imm` materialises
        for (uint32_t i = 0; i < 4; ++i)
            pos[i] = kNoPos;
        int p = 0;
        for (uint32_t back = 0x30u; back >= 4; back -= 4, ++p)
        {
            uint32_t w = 0;
            if (!mem.ReadU32BE(site - back, &w)) { *why = "UNREADABLE-TEXT"; return false; }
            const uint32_t op = w >> 26, T = (w >> 21) & 0x1Fu, A = (w >> 16) & 0x1Fu;
            const uint32_t uimm = w & 0xFFFFu;
            const uint32_t simm = static_cast<uint32_t>(
                static_cast<int32_t>(static_cast<int16_t>(static_cast<uint16_t>(uimm))));
            if (op == 15 && A == 0) { // lis
                hi[T] = simm << 16; continue;
            }
            if ((op == 14 || op == 24) && hi[A] != kUnset) { // addi / ori
                reg[T] = (op == 14) ? (hi[A] + simm) : (hi[A] | uimm);
                if (T >= 3 && T <= 6) pos[T - 3] = p;
                continue;
            }
            // Anything else -- a branch, padding, an `addis` with a live base, an
            // unresolvable addi -- ends the current block.
            for (uint32_t i = 0; i < 32; ++i)
                hi[i] = kUnset;
            hi[0] = 0;
            for (uint32_t i = 0; i < 4; ++i)
                pos[i] = kNoPos;
            for (uint32_t i = 0; i < 32; ++i)
                reg[i] = 0;
            lastReset = p;
        }
        for (uint32_t i = 0; i < 4; ++i)
            if (pos[i] <= lastReset) { *why = "ARG-NOT-AFTER-RESET"; return false; }
        out.site = site; out.node = reg[3]; out.name = reg[4];
        out.buf = reg[5]; out.size = reg[6];
        if (out.node == 0 || out.name == 0 || out.buf == 0) { *why = "NULL-ARG"; return false; }
        if (out.size == 0 || out.size > (64u << 20)) { *why = "SIZE-SHAPE"; return false; }
        if (out.node < kDataLo || out.node + 16u > kDataHi) { *why = "NODE-NOT-STATIC-DATA"; return false; }
        if (out.name < kRdataLo || out.name >= kRdataHi) { *why = "NAME-NOT-RDATA"; return false; }
        if (out.buf < kDataLo || out.buf >= kDataHi) { *why = "BUF-NOT-STATIC-DATA"; return false; }
        *why = "OK";
        return true;
    }

    // Log-only. Prints the measured table, one row per decoded registration with
    // the collision answer, and a summary naming both halves of the shader
    // question. It writes no guest memory and calls no guest code, so it cannot
    // be the thing that breaks a boot (F-636's lesson).
    static void CensusCrtXcu()
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        // 768, not 384: the marker gained a block of APPENDED fields and
        // std::snprintf truncates SILENTLY, so an undersized buffer would have
        // dropped the new evidence and left no sign that it was dropped -- the
        // first 384 bytes would still have looked like a well-formed row. The
        // numbers, measured by rendering both format strings with the values
        // read out of build/cache/mcla_pe.bin: the unchanged `begin=`..
        // `verify=` prefix 162 bytes, the 16 appended fields 253, the row 416
        // + NUL. The ABSOLUTE worst case -- every %u/%d at 10 digits, every
        // %08X at 8, %s at its longest verdict REFUSED-END-UNREADABLE -- is 571
        // + NUL, so 384 would have truncated on the day the table went wrong
        // and 768 has 197 bytes of headroom. The same buffer serves the
        // F640-XCU-REG rows and the F640-XCU-SUMMARY row, both far shorter.
        char lbuf[768];

        // (a) the table itself, verified before it is believed.
        //
        // THE GATE IS THE END SENTINEL AND NOTHING ELSE. It used to be
        // `firstOk && endOk`, and `firstOk` additionally demanded that the word
        // AT `begin` be a .text pointer. That word measures 0x00000000 in the
        // image -- the NULL prefix that all three .CRT arrays here carry -- so
        // the gate could never pass, and the marker has printed
        // `slots=0 nonNull=0 first=00000000 ... verify=REFUSED-FIRST-NOT-TEXT`
        // in every soak since w444 while the region held 1268 slots, 1 null and
        // 1267 non-null .text pointers, all 1267 mappable. A refusal that is on
        // by construction is not a measurement; it is the same defect as a
        // tracked marker whose literal cannot be printed, F-057(6). The zeros it
        // produced were the gate talking, not the table.
        //
        // THE TWO READS ARE NOW RECORDED SEPARATELY, because the old `firstOk`
        // folded "the read failed" into "the value is not text" and one field
        // cannot say which of the two happened. `beginReadOk` / `endReadOk` are
        // the read-success flags; `beginWord` / `endWord` are the values. A
        // failed read leaves its word at 0, so the FLAGS are what make a failed
        // read distinguishable from a successful read of zero -- the difference
        // the retired gate erased.
        //
        // EVERY PRE-EXISTING FIELD KEEPS ITS MEANING, ITS ORDER, ITS SPELLING
        // AND ITS POSITION. `slots` is still the number of words walked;
        // `nonNull` is still the number of walked words that were non-null AND
        // in [kTextLo,kTextHi] (the out-of-text test still breaks BEFORE the
        // increment, exactly as before); `first`/`last` are still the
        // lowest/highest such word; `truncated` is still 0/1/2 for ok / read
        // failed / non-text value. New fields are APPENDED, after `verify=`, so
        // the whole `begin=` .. `verify=` prefix is byte-identical to every log
        // written before this change.
        //
        // tools/soak_census.py is unaffected, and not only by luck: its
        // count_markers() counts MATCHING LINES (`grep -ic` compatible) and
        // never splits a line into fields, so field count was never a
        // dependency; and F640-XCU-TABLE is not one of the 204 markers
        // markers_from_guide() parses out of PROGRAM_GUIDE sec 9, so it has no
        // tracked row whose meaning could shift. The one string that stops
        // being printed is `REFUSED-FIRST-NOT-TEXT`, and it stops because the
        // test it named is gone -- the first word is still measured, as
        // `beginWord` and `beginInText`.
        uint32_t firstWord = 0, endWord = 0;
        const bool beginReadOk = mem.ReadU32BE(kCrtXcuBegin, &firstWord);
        const bool endReadOk = mem.ReadU32BE(kCrtXcuEnd, &endWord);
        const bool endSentinelOk = endReadOk && endWord == 0;
        uint32_t slots = 0, nonNull = 0, lo = 0, last = 0, unmapped = 0, truncated = 0;
        // New, appended-only. `entries` counts the words the WALKER would enter
        // -- non-zero and not 0xFFFFFFFF, the two tests at 0x821327E0 and
        // 0x821327E8 -- which is NOT what `nonNull` counts, so the two are
        // reported side by side instead of one being taken on trust for the
        // other. `regionReadFail` marks a second pass that stopped early, so a
        // partial count is never read as a whole one.
        uint32_t entries = 0, entriesInText = 0, ffffffff = 0, outOfText = 0;
        uint32_t firstEntry = 0, orderBreaks = 0, adjacentPairs = 0;
        uint32_t regionWords = 0, regionReadFail = 0, prevEntry = 0;
        if (endSentinelOk)
        {
            // Pass 1 is the original loop, body unchanged, so the six original
            // counters keep their exact previous definitions.
            for (uint32_t va = kCrtXcuBegin; va < kCrtXcuEnd && slots < kCrtXcuMaxSlots; va += 4)
            {
                uint32_t v = 0;
                if (!mem.ReadU32BE(va, &v)) { truncated = 1; break; }
                ++slots;
                if (v == 0)
                    continue;
                if (v < kTextLo || v > kTextHi) { truncated = 2; break; }
                ++nonNull;
                // PRE-FLIGHT, and the only containment that costs nothing: PPC_LOOKUP_FUNC is
                // an array index, so naming the entries the host could not enter BEFORE
                // the entry point runs is free and turns a would-be boot-killing jump
                // through a null slot into a counted row. (A mapped-but-faulting ctor is
                // NOT containable from here: the walk lives in the guest's entry and this
                // TU keeps its "no __try around the entry call" contract. Owning
                // sub_82132740 is the named next step; its gate is `unmapped=0` in
                // F640-XCU-TABLE plus C0000005 0.)
                if (g_base != nullptr && PPC_LOOKUP_FUNC(g_base, v) == nullptr)
                    ++unmapped;
                if (lo == 0) lo = v;
                last = v;
            }
            // Pass 2 is new and deliberately does NOT break on an out-of-text
            // word, so `outOfText` and `entries` are totals for the WHOLE region
            // and not "up to whatever truncated pass 1 hit". It is a second read
            // of the same 1268 words through the same accessor: 2536 reads once,
            // no writes, no guest code, nothing a boot can trip over.
            for (uint32_t va = kCrtXcuBegin; va < kCrtXcuEnd && regionWords < kCrtXcuMaxSlots; va += 4)
            {
                uint32_t v = 0;
                if (!mem.ReadU32BE(va, &v)) { regionReadFail = 1; break; }
                ++regionWords;
                if (v == 0xFFFFFFFFu) { ++ffffffff; continue; }
                if (v == 0) continue;
                if (firstEntry == 0) firstEntry = regionWords; // 1-based, so a NULL prefix is visible as a number
                if (prevEntry != 0)
                {
                    ++adjacentPairs;
                    if (v < prevEntry) ++orderBreaks;
                }
                prevEntry = v;
                ++entries;
                if (v >= kTextLo && v <= kTextHi) ++entriesInText; else ++outOfText;
            }
        }
        std::snprintf(lbuf, sizeof(lbuf),
                      "F640-XCU-TABLE begin=%08X end=%08X slots=%u nonNull=%u first=%08X "
                      "last=%08X unmapped=%u truncated=%u walker=%08X callSite=%08X "
                      "verify=%s",
                      kCrtXcuBegin, kCrtXcuEnd, slots, nonNull, lo, last, unmapped,
                      truncated, kCrtWalker, kCrtWalkCall,
                      endSentinelOk
                          ? "OK"
                          : (endReadOk ? "REFUSED-END-NOT-ZERO" : "REFUSED-END-UNREADABLE"));
        // APPENDED FIELDS. All sixteen are new, and none of the ELEVEN above
        // (begin, end, slots, nonNull, first, last, unmapped, truncated, walker,
        // callSite, verify) changes name, order, spelling or meaning.
        //   beginReadOk   read at kCrtXcuBegin succeeded (1/0) -- the fact the
        //                  old `firstOk` swallowed.
        //   endReadOk     read at kCrtXcuEnd succeeded (1/0).
        //   beginWord     the raw word at kCrtXcuBegin. 00000000 here: the NULL
        //                  prefix, normal for all three arrays.
        //   endWord       the raw word at kCrtXcuEnd, i.e. the sentinel.
        //   beginInText   is beginWord inside [textRange]? The RETIRED gate's
        //                  own boolean, reported rather than enforced (0 here).
        //   endSentinel   the LIVE gate's own boolean, endReadOk && endWord==0.
        //   regionWords   words walked by pass 2; equals `slots` when
        //                  truncated==0, and is a total (pass 2 never breaks on
        //                  an out-of-text value).
        //   entries       non-zero and not 0xFFFFFFFF == what loop B enters.
        //   entriesInText of those, inside [textRange] == `nonNull` when
        //                  truncated==0.
        //   ffffffff      the other skip class; 0 measured.
        //   outOfText     entered but outside [textRange] -- a slot the guest
        //                  would bctrl into. A total, not "up to truncated".
        //   firstEntry    1-based slot index of the first entered word (2
        //                  measured: the NULL prefix is exactly ONE slot, so
        //                  0x827D0010 is skipped and 0x827D0014 is entry one).
        //   adjacentPairs non-decreasing pairs checkable among `entries`.
        //   orderBreaks   of those, how many decrease -- re-measures the linker
        //                  address-order claim at run time (1 measured).
        //   regionReadFail pass 2 stopped on an unreadable word, so every
        //                  pass-2 count above is partial and must not be read
        //                  as a whole.
        //   textRange     kTextLo..kTextHi, INCLUSIVE, so "in text" is
        //                  checkable from the log rather than trusted.
        std::snprintf(lbuf + std::strlen(lbuf), sizeof(lbuf) - std::strlen(lbuf),
                      " beginReadOk=%d endReadOk=%d beginWord=%08X endWord=%08X "
                      "beginInText=%d endSentinel=%d regionWords=%u entries=%u "
                      "entriesInText=%u ffffffff=%u outOfText=%u firstEntry=%u "
                      "adjacentPairs=%u orderBreaks=%u regionReadFail=%d "
                      "textRange=%08X-%08X",
                      beginReadOk ? 1 : 0, endReadOk ? 1 : 0, firstWord, endWord,
                      (firstWord >= kTextLo && firstWord <= kTextHi) ? 1 : 0,
                      endSentinelOk ? 1 : 0, regionWords, entries, entriesInText,
                      ffffffff, outOfText, firstEntry, adjacentPairs, orderBreaks,
                      regionReadFail ? 1 : 0, kTextLo, kTextHi);
        BootReportInfo(lbuf);

        // Two region dumps, both through the UNCHECKED accessor at
        // boot_host.cpp:851 (`*(volatile uint32_t*)(base + guestAddr)`) rather
        // than through `mem`, so the same bytes are read by two independent
        // paths: this one off the installed window, the census above off the
        // guest heap. If the two disagree, the marker above is describing an
        // image that is not the one running. TOTALLY LOG-ONLY and two lines per
        // boot, so it is not gated -- a dump that only prints when the census is
        // already happy is a dump that cannot catch the case it exists for.
        // 8 words at the head covers the NULL prefix and 7 entries; 4 at
        // 0x827D13D0 covers the last slot, the end sentinel the gate reads, and
        // the next array's prefix, which is where an off-by-one in the bounds
        // would show. A whole-table dump would be 1268 words = 33 lines per boot
        // (DumpImageRegion's 512-byte buffer holds ~53 words), so it is one
        // argument away if a soak ever needs it.
        DumpImageRegion(kCrtXcuBegin, 8);
        DumpImageRegion(kCrtXcuEnd - 16, 4);

        // (b) the 15 embedded-file registrations, and whether any of them lands on
        //     a word the host has already substituted.
        uint32_t decoded = 0, refused = 0, collide = 0;
        for (const uint32_t site : kD22E8Sites)
        {
            CrtReg r{};
            const char* why = "?";
            if (!DecodeCrtRegistration(site, r, &why))
            {
                ++refused;
                std::snprintf(lbuf, sizeof(lbuf),
                              "F640-XCU-REG-REFUSE site=%08X reason=%s (nothing written)",
                              site, why);
                BootReportInfo(lbuf);
                continue;
            }
            ++decoded;
            bool hostSlot = false;
            for (const uint32_t s : kHostSubstSlots)
                for (uint32_t d = 0; d < 16u; d += 4)
                    if (r.node + d == s) hostSlot = true;
            if (hostSlot) ++collide;
            char name[48] = {0};
            (void)mem.ReadBytes(r.name, name, sizeof(name) - 1);
            std::snprintf(lbuf, sizeof(lbuf),
                          "F640-XCU-REG #%u site=%08X node=%08X name='%s' buf=%08X size=%u "
                          "nodeInStaticData=%d landsOnHostSubstitutedWord=%d",
                          decoded, r.site, r.node, name, r.buf, r.size,
                          (r.node >= kDataLo && r.node < kDataHi) ? 1 : 0, hostSlot ? 1 : 0);
            BootReportInfo(lbuf);
        }

        // (c) the summary, stating the two halves separately so a soak cannot
        //     read one as the other.
        std::snprintf(lbuf, sizeof(lbuf),
                      "F640-XCU-SUMMARY tableSlots=%u nonNull=%u unmapped=%u truncated=%u "
                      "regSites=%u decoded=%u refused=%u hostSubstitutedCollisions=%u "
                      "walkerRunsThem=1 hostAddsSecondRun=0 ShadowsRegisteredByCtor=0 "
                      "-> the 'preload' half is closed; Shadows is a SERVE gap "
                      "(gpu_device.cpp AFB76-REFUSE), not a missing ctor",
                      slots, nonNull, unmapped, truncated,
                      static_cast<uint32_t>(sizeof(kD22E8Sites) / sizeof(kD22E8Sites[0])),
                      decoded, refused, collide);
        BootReportInfo(lbuf);
    }

    // Seed the embedded:/ name list with the static .data blobs the guest's own
    // C runtime registers via sub_821D22E8. The 15 registrations are read out of
    // the image at the measured call sites (see the F-640 block above), not typed
    // in: 14 of the 15 quadruples are byte-identical to the retired hand-typed
    // table, and the 15th (rage_postfx) now carries the ctor's own 38024 instead of
    // the table's stale 48 — the value w666.log:16255 shows reaching the log.
    // Nodes live in image .data (no heap Alloc). Format matches D22E8:
    // {name*, buf, size, next}, head at 0x82860AF8 — four bytes above the guest's
    // real 0x82860AF4, which is the open defect in item (3) above.
    static void SeedEmbeddedNameList()
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        constexpr uint32_t kListHead = 0x82860AF8;

        uint32_t head = 0;
        mem.ReadU32BE(kListHead, &head);
        int n = 0;
        int refused = 0;
        for (const uint32_t site : kD22E8Sites)
        {
            CrtReg r{};
            const char* why = "?";
            if (!DecodeCrtRegistration(site, r, &why)) { ++refused; continue; }
            mem.WriteU32BE(r.node + 0, r.name);
            mem.WriteU32BE(r.node + 4, r.buf);
            mem.WriteU32BE(r.node + 8, r.size);
            mem.WriteU32BE(r.node + 12, head);
            head = r.node;
            ++n;
        }
        // Refuse rather than write a half-list: with nothing decoded there is no
        // bridge into the guest's chain, and a silent zero here would read as
        // "the preload half is broken" rather than "the image did not decode".
        if (n > 0)
            mem.WriteU32BE(kListHead, head);
        char lbuf[160];
        std::snprintf(lbuf, sizeof(lbuf),
                      "[boot] embed-seed %d CRT triples, listHead=%08X", n,
                      n > 0 ? head : 0u);
        BootReportInfo(lbuf);
        if (refused != 0)
        {
            std::snprintf(lbuf, sizeof(lbuf),
                          "[boot] embed-seed %d sites refused (decoded from image, not "
                          "written; the guest's own initialisers still run)",
                          refused);
            BootReportInfo(lbuf);
        }
    }

    static void ReplayDeadMemoryDeviceCtor()
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        constexpr uint32_t kMemDeviceObj = 0x827D838C; // GETDEV prefix return
        constexpr uint32_t kFallbackPtr = 0x827D8380;  // Mount("memory:") slot
        constexpr uint32_t kMemVtable = 0x82012918;    // AE50/AFB8/B070/B400

        // Only image .data stores. Do NOT write guest heap scratch (0xA00xxxxx)
        // here — that landed in o1heap fragments and produced
        // sysMemMultiAllocator::Free "Not owned by any known heap".
        // [0x827D838C+0] = memory vtable (override CRT's 0x8201206C).
        mem.WriteU32BE(kMemDeviceObj + 0, kMemVtable);
        // [0x827D8380] = Device* fallback = the static object itself.
        mem.WriteU32BE(kFallbackPtr, kMemDeviceObj);

        SeedEmbeddedNameList();

        uint32_t vt = 0, fb = 0, head = 0;
        mem.ReadU32BE(kMemDeviceObj, &vt);
        mem.ReadU32BE(kFallbackPtr, &fb);
        mem.ReadU32BE(0x82860AF8u, &head);
        char lbuf[192];
        std::snprintf(lbuf, sizeof(lbuf),
                      "[boot] dead-ctor replay: vt@%08X=%08X fallback@%08X=%08X "
                      "listHead=%08X",
                      kMemDeviceObj, vt, kFallbackPtr, fb, head);
        BootReportInfo(lbuf);
    }

    void SeedPreBootSlots()
    {
        // F-640: measure and publish the .CRT$XCU layout BEFORE anything writes, so
        // a soak has the table's real bounds, the 15 decoded registrations and the
        // collision answer in the log next to whatever the entry point then does
        // with them. Log-only, no guest writes, no guest calls.
        CensusCrtXcu();

        ReplayDeadMemoryDeviceCtor();

        // The fatal-error dispatcher (Function_821BD618) reads slot 0x8285FEA0
        // and calls it when non-zero. Leave it ZERO -- what runs is the host override
        // sub_821BD618 (kernel/imports.cpp:2982, registered patches.cpp:417), which only
        // logs the slot and terminates; the guest body would call a handler, then loop (b .).
        constexpr uint32_t SlotAddr = 0x8285FEA0;
        uint32_t slotValue = 0;
        std::memcpy(&slotValue, g_base + SlotAddr, sizeof(slotValue));
        const uint32_t slotBE = __builtin_bswap32(slotValue);
        if (slotBE != 0)
        {
            char lbuf[192];
            std::snprintf(lbuf, sizeof(lbuf), "[boot] pre-boot init: slot @0x%08X already 0x%08X; leaving as-is",
                          SlotAddr, slotBE);
            BootReportInfo(lbuf);
        }
        else
        {
            BootReportInfo("[boot] pre-boot init: slot @0x8285FEA0 left zero (dispatcher will loop)");
        }

        // Global table pointer at 0x8288E5AC read by sub_82388598. Point it at
        // a valid guest scratch table region so the load succeeds.
        constexpr uint32_t TablePtrAddr = 0x8288E5AC;
        constexpr uint32_t ScratchTable = 0x8F207000;
        uint32_t tablePtrVal = 0;
        std::memcpy(&tablePtrVal, g_base + TablePtrAddr, sizeof(tablePtrVal));
        if (__builtin_bswap32(tablePtrVal) == 0)
        {
            const uint32_t scratchBE = __builtin_bswap32(ScratchTable);
            std::memcpy(g_base + TablePtrAddr, &scratchBE, sizeof(scratchBE));
            char lbuf[192];
            std::snprintf(lbuf, sizeof(lbuf), "[boot] pre-boot init: table ptr @0x%08X populated with scratch table 0x%08X",
                          TablePtrAddr, ScratchTable);
            BootReportInfo(lbuf);
        }
    }

} // namespace boot internals (keep NearestFunctionName below in same ns)

// F-609: hand out one real, per-host-thread guest identity block.
//
// The five stores below are GuestThreadContext's, one for one
// (kernel/guest_thread.cpp:40-45), because the point of this function is that a
// synthetic host thread becomes indistinguishable from an ExCreateThread one to
// every guest reader of r13+off. Big-endian via __builtin_bswap32 rather than
// the ByteSwap() helper guest_thread.cpp uses: that symbol lives in
// kernel/xbox.h, which boot_host.cpp does not include, and SetupInitialContext
// already spells the same conversion at :740. guest_thread.cpp:44 stores
// 0xFFFFFFFF UNSWAPPED; it is a palindrome, so the swap is a no-op either way.
//
// Note for the consumer: block r1 is the top of the block's own 0x40000 stack
// (== pcrVa + 0x40E90, guest_thread.cpp:47), NOT the 2 MiB static stack at
// 0x8F000000 that the boot worker and the vsync ISR use. A guest stack living
// inside the user arena is a new exposure: heap_arena.h records the open
// F-377 question that "something hands the title our arena base and it
// initialises its own allocator metadata over it". Whoever moves a context onto
// a heap block must confirm the title's XTL metadata never lands on a live
// stack, and stack depth must fit 0x40000 (real guest threads get the same).
GuestThreadBlock* AllocateGuestThreadBlock(const char* tag, uint32_t cpuNumber)
{
    // Descriptor and payload are separate allocations: the payload has to be a
    // contiguous PCR..stack window the guest can address, and the descriptor is
    // host-side bookkeeping that must stay OUTSIDE the guest window (a guest
    // pointer to it would be a wild write waiting to happen). Descriptor uses
    // ordinary new/delete rather than g_userHeap.Alloc<T>: that template was
    // never instantiated anywhere before this, so its placement-new path is
    // unproven in this build, and the payload path below is the one
    // guest_thread.cpp:23 already runs for every real guest thread. Freed
    // together by ReleaseGuestThreadBlock, so the pairing cannot leak.
    GuestThreadBlock* block = new GuestThreadBlock();
    if (block == nullptr)  // not reachable without -fno-exceptions; checked anyway
        return nullptr;

    block->pcr = static_cast<uint8_t*>(g_userHeap.Alloc(F609TotalSize));
    if (block->pcr == nullptr)
    {
        // F-370 in the F-609 shape. guest_thread.cpp:26-37 logs before it
        // returns so "the guest wanted N blocks and got M<N" is answerable
        // from the log; the unnamed version of this path is what used to
        // memset(nullptr, 0x40E90) and kill a thread silently (w373). Log
        // through BootReportInfo, NOT MCLA_LOG_*: this TU holds __try and
        // clang 19.1.7 ICEs instantiating spdlog/fmt here (boot_host.h:161).
        static std::atomic<uint32_t> s_f609Oom{0};
        const uint32_t n = s_f609Oom.fetch_add(1) + 1;
        if (n <= 16 || (n % 100) == 0)
        {
            char lbuf[192];
            std::snprintf(lbuf, sizeof(lbuf),
                          "F609-BLOCK-NULL #%u size=0x%zX cpu=%u tag=%s - block NOT published",
                          n, F609TotalSize, cpuNumber, tag ? tag : "?");
            BootReportInfo(lbuf);
        }
        delete block;
        return nullptr;
    }

    std::memset(block->pcr, 0, F609TotalSize);
    block->tag = tag;
    block->cpuNumber = cpuNumber;

    const uint32_t pcrVa = mcla::kernel::g_memory.MapVirtual(block->pcr);
    const uint32_t tlsVa = mcla::kernel::g_memory.MapVirtual(block->pcr + F609PcrSize);
    const uint32_t tebVa = mcla::kernel::g_memory.MapVirtual(block->pcr + F609TebOffset);
    const uint32_t topVa = mcla::kernel::g_memory.MapVirtual(block->pcr + F609TotalSize);

    const auto storeU32 = [pcr = block->pcr](size_t off, uint32_t value) {
        *reinterpret_cast<uint32_t*>(pcr + off) = __builtin_bswap32(value);
    };
    storeU32(0x000, tlsVa);                        // *(r13+0x000) = TLS array
    storeU32(0x100, tebVa);                        // *(r13+0x100) = TEB
    block->pcr[0x10C] = static_cast<uint8_t>(cpuNumber);
    storeU32(F609PcrSize + 0x10, 0xFFFFFFFF);     // the one quirky TLS entry
    storeU32(F609TebOffset + 0x14C, GetCurrentThreadId());  // TEB thread id

    block->pcrVa = pcrVa;
    block->tlsVa = tlsVa;
    block->tebVa = tebVa;
    block->stackTopVa = topVa;

    RegisterBlockTag(pcrVa, tag);

    char lbuf[224];
    std::snprintf(lbuf, sizeof(lbuf),
                  "F609-BLOCK tag=%s pcr=%08X tls=%08X teb=%08X r1=%08X cpu=%u host=%p",
                  tag ? tag : "?", pcrVa, tlsVa, tebVa, topVa, cpuNumber,
                  static_cast<void*>(block->pcr));
    BootReportInfo(lbuf);
    return block;
}

void ReleaseGuestThreadBlock(GuestThreadBlock* block)
{
    if (block == nullptr)
        return;

    {
        std::lock_guard lock(g_f609TagMutex);
        g_f609Tags.erase(block->pcrVa);
    }
    g_userHeap.Free(block->pcr);  // PCR..stack window, one allocation
    delete block;                 // descriptor, ordinary new in AllocateGuestThreadBlock
}

const char* LookupGuestThreadBlockTag(uint32_t pcrVa)
{
    std::lock_guard lock(g_f609TagMutex);
    const auto it = g_f609Tags.find(pcrVa);
    return it == g_f609Tags.end() ? nullptr : it->second;
}

// CRT .CRT$XCU initializer that would install the BASE vtable 0x8201206C into
// the static memory-device object at 0x827D838C. Override so the object keeps
// the real memory-family vtable 0x82012918 (EMB76 / open = sub_821CB070).
// Guest stores, cited:
//   stw r11,-31860(r10)  @0x827B8B38+0x0C  -> [0x827D838C] = vtable
//   (r11 was addi r11,r11,8300 = 0x8201206C; we write 0x82012918)
PPC_FUNC_IMPL(__imp__sub_827B8B38);
PPC_FUNC(sub_827B8B38) {
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    constexpr uint32_t kMemDeviceObj = 0x827D838C;
    constexpr uint32_t kMemVtable = 0x82012918;
    mem.WriteU32BE(kMemDeviceObj + 0, kMemVtable);
    // Mount("memory:") special path: stw r26,-31872(r11) -> [0x827D8380]=dev*
    mem.WriteU32BE(0x827D8380, kMemDeviceObj);
}

// Sibling CRT init writes the same base vtable into 0x827D8388. Keep it in
// sync so neighboring statics stay consistent if anything aliases them.
PPC_FUNC_IMPL(__imp__sub_827B8B20);
PPC_FUNC(sub_827B8B20) {
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    mem.WriteU32BE(0x827D8388, 0x82012918);
}

namespace { // resume file-local helpers

    const char* NearestFunctionName(uint64_t hostAddr)
    {
        static thread_local char buf[160];
        const uintptr_t pc = (uintptr_t)hostAddr;

        // Walk unwind metadata to get the real containing host function start.
        DWORD64 imageBase = 0;
        const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, &imageBase, nullptr);
        if (fn != nullptr)
        {
            const uintptr_t start = imageBase + fn->BeginAddress;
            auto it = g_hostToGuest.find(start);
            if (it != g_hostToGuest.end())
            {
                std::snprintf(buf, sizeof(buf), "0x%08x", it->second);
                return buf;
            }
        }

        // Host-only code (kernel imports, our C++): ask the PDB via dbghelp.
        {
            static std::once_flag symOnce;
            std::call_once(symOnce, []() {
                SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                SymInitialize(GetCurrentProcess(), nullptr, TRUE);
            });
            SYMBOL_INFO* si = (SYMBOL_INFO*)buf;
            // Use a scratch buffer: SYMBOL_INFO must precede the name.
            alignas(8) char scratch[sizeof(SYMBOL_INFO) + 96];
            si = (SYMBOL_INFO*)scratch;
            si->SizeOfStruct = sizeof(SYMBOL_INFO);
            si->MaxNameLen = 95;
            DWORD64 disp = 0;
            if (SymFromAddr(GetCurrentProcess(), pc, &disp, si))
            {
                std::snprintf(buf, sizeof(buf), "%s+0x%llx", si->Name,
                              (unsigned long long)disp);
                return buf;
            }
        }

        // Fallback: the PC may sit in a merged/leaf-thunk region with no unwind
        // entry of its own (identical-code folding splits chunks). Scan the full
        // mapping table for the function whose host start is the closest one <= PC.
        PPCFunc* closest = nullptr;
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            PPCFunc* h = PPCFuncMappings[i].host;
            if ((uintptr_t)h <= pc && (closest == nullptr || (uintptr_t)h > (uintptr_t)closest))
                closest = h;
        }
        if (closest != nullptr)
        {
            const uintptr_t start = (uintptr_t)closest;
            std::snprintf(buf, sizeof(buf), "0x%08x (+0x%llx)", g_hostToGuest[start],
                          (unsigned long long)(pc - start));
            return buf;
        }

        std::snprintf(buf, sizeof(buf), "host 0x%llx", (unsigned long long)hostAddr);
        return buf;
    }

    // T38.2b (F-046): "which translated guest function contains the faulting host RIP"
    // is answerable WITHOUT the context registers, so it survives the wrong-frame problem.
    // Allocation- and lock-free on purpose (unwind metadata + the static mapping table):
    // this runs inside the VEH handler, where NearestFunctionName's dbghelp path does not.
    const char* GuestFnAtHostAddr(uint64_t hostAddr)
    {
        static thread_local char buf[80];
        DWORD64 imageBase = 0;
        const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry((DWORD64)hostAddr, &imageBase, nullptr);
        if (fn == nullptr)
        {
            std::snprintf(buf, sizeof(buf), "no unwind entry");
            return buf;
        }
        const uintptr_t start = (uintptr_t)(imageBase + fn->BeginAddress);
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if ((uintptr_t)PPCFuncMappings[i].host == start)
            {
                // The offset is HOST code bytes from the translated function's entry, not a guest PC
                // displacement — 0x82304348 + 0x144 decoded as guest is a block that never ran (F-050).
                std::snprintf(buf, sizeof(buf), "guest 0x%08zX (host+0x%llX)", PPCFuncMappings[i].guest,
                              (unsigned long long)(hostAddr - start));
                return buf;
            }
        }
        std::snprintf(buf, sizeof(buf), "host 0x%llx, not a mapped guest fn",
                      (unsigned long long)start);
        return buf;
    }

    static void CaptureFaultInfo(EXCEPTION_POINTERS* info, BootReport& report, bool captureStack)
    {
        const uintptr_t pc = (uintptr_t)info->ContextRecord->Rip;

        if (captureStack)
        {
            void* frames[24] = {};
            const WORD n = RtlCaptureStackBackTrace(0, 24, frames, nullptr);
            report.faultStack.clear();
            for (WORD i = 0; i < n; i++)
            {
                const uintptr_t fa = (uintptr_t)frames[i];
                char buf[128];
                std::snprintf(buf, sizeof(buf), "0x%016zx %s", (size_t)fa, NearestFunctionName(fa));
                report.faultStack.emplace_back(buf);
            }
        }

        DWORD64 imageBase = 0;
        const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, &imageBase, nullptr);
        if (fn != nullptr)
        {
            report.faultOwnerStart = imageBase + fn->BeginAddress;
            report.faultOwnerOffset = pc - report.faultOwnerStart;
        }
        report.faultInfo = NearestFunctionName(pc);
        report.faultHost = pc;
        report.faultRva = pc - g_moduleBase;
        report.faultCode = info->ExceptionRecord->ExceptionCode;
        report.faultAddr = (uintptr_t)info->ExceptionRecord->ExceptionInformation[1];
        report.readFault = info->ExceptionRecord->ExceptionInformation[0] == 0;

        report.faultRax = info->ContextRecord->Rax;
        report.faultRbx = info->ContextRecord->Rbx;
        report.faultRcx = info->ContextRecord->Rcx;
        report.faultRdx = info->ContextRecord->Rdx;
        report.faultRsi = info->ContextRecord->Rsi;
        report.faultRdi = info->ContextRecord->Rdi;
        report.faultR1 = g_faultCtx ? g_faultCtx->r1.u32 : 0;
        report.faultR3 = g_faultCtx ? g_faultCtx->r3.u32 : 0;
        report.faultR13 = g_faultCtx ? g_faultCtx->r13.u32 : 0;
        report.faultLR = g_faultCtx ? (uint32_t)g_faultCtx->lr : 0;
        if (g_faultCtx != nullptr)
        {
            std::memset(report.faultGpr, 0, sizeof(report.faultGpr));
            report.faultGpr[1] = g_faultCtx->r1.u32;
            report.faultGpr[3] = g_faultCtx->r3.u32;
            report.faultGpr[4] = g_faultCtx->r4.u32;
            report.faultGpr[5] = g_faultCtx->r5.u32;
            report.faultGpr[6] = g_faultCtx->r6.u32;
            report.faultGpr[7] = g_faultCtx->r7.u32;
            report.faultGpr[8] = g_faultCtx->r8.u32;
            report.faultGpr[9] = g_faultCtx->r9.u32;
            report.faultGpr[10] = g_faultCtx->r10.u32;
            report.faultGpr[13] = g_faultCtx->r13.u32;
        }

        std::memset(report.faultBytes, 0, sizeof(report.faultBytes));
        if (pc >= g_moduleBase)
            std::memcpy(report.faultBytes, (const void*)pc, sizeof(report.faultBytes));

        if (g_base != nullptr)
        {
            for (int i = 0; i < 16; i++)
                report.faultTable[i] = ReadU32BE(g_base, 0x827EB900u + (uint32_t)i * 4);
        }

        if (report.faultR1 != 0 && g_base != nullptr)
        {
            uint32_t callerLR = 0;
            std::memcpy(&callerLR, g_base + report.faultR1 + 88, sizeof(callerLR));
            report.faultCallerLR = callerLR;
        }
    }

    int FilterCapture(EXCEPTION_POINTERS* info)
    {
        CaptureFaultInfo(info, g_report, true);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    void LogReport()
    {
        std::scoped_lock lock(g_reportMutex);
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] entry=0x%08X returned=%d",
                      g_report.entryGuest, g_report.returned ? 1 : 0);
        BootReportInfo(lbuf);
        if (g_report.returned)
            return;
        std::snprintf(lbuf, sizeof(lbuf), "[boot] fault: code=0x%08X read=%d addr=0x%016zX host=0x%016zX rva=0x%zX in %s",
                      g_report.faultCode, g_report.readFault ? 1 : 0, (size_t)g_report.faultAddr,
                      (size_t)g_report.faultHost, (size_t)g_report.faultRva, g_report.faultInfo.c_str());
        BootReportError(lbuf);
        if (g_report.faultOwnerStart != 0)
        {
            std::snprintf(lbuf, sizeof(lbuf), "[boot] fault owner host=0x%016zX +0x%zX",
                          (size_t)g_report.faultOwnerStart, (size_t)g_report.faultOwnerOffset);
            BootReportError(lbuf);
        }
        std::snprintf(lbuf, sizeof(lbuf), "[boot] r1=0x%08X r3=0x%08X r13=0x%08X lr=0x%08X callerLR=0x%08X",
                      g_report.faultR1, g_report.faultR3, g_report.faultR13,
                      g_report.faultLR, g_report.faultCallerLR);
        BootReportError(lbuf);
        {
            char tbuf[256];
            int o = std::snprintf(tbuf, sizeof(tbuf), "[boot] fault-table 0x827EB900:");
            for (int i = 0; i < 16; i++)
                o += std::snprintf(tbuf + o, sizeof(tbuf) - (size_t)o, " %08X", g_report.faultTable[i]);
            BootReportInfo(tbuf);
        }
        // Reverse-lookup the fault owner host address to a guest address
        if (g_report.faultOwnerStart != 0)
        {
            auto it = g_hostToGuest.find(g_report.faultOwnerStart);
            if (it != g_hostToGuest.end())
            {
                std::snprintf(lbuf, sizeof(lbuf), "[boot] fault guest=0x%08X (+0x%zX)",
                              it->second, (size_t)g_report.faultOwnerOffset);
                BootReportError(lbuf);
            }
        }
        for (const auto& line : g_report.faultStack)
        {
            std::snprintf(lbuf, sizeof(lbuf), "[boot]   stack %s", line.c_str());
            BootReportInfo(lbuf);
        }
    }

    // Use SetUnhandledExceptionFilter instead of VEH+SEH for fault handling
// This avoids SEH which causes clang-cl ICE and CRT linkage issues with MSVC

static LONG WINAPI UnhandledExceptionFilter(PEXCEPTION_POINTERS info)
{
    if (g_faultCtx == nullptr)
        return EXCEPTION_CONTINUE_SEARCH;

    CaptureFaultInfo(info, g_report, false);
    // W0: do not let the process die. Park this thread so the window survives.
    while (t_hgWin > 0)  // F-412: same drain as the VEH park branch -- this park never returns
        HeapGuardArmImpl();
    spdlog::default_logger()->flush();
    for (;;)
        Sleep(1000);
    return EXCEPTION_EXECUTE_HANDLER; // unreachable
}

// SEH-safe stack-slot read: C-style free function with no C++ objects that
// require unwinding. clang-cl ICEs compiling __try inside the VEH lambda
// below (same ICE class as the note at heap.cpp:31-33, and the one above
// Start()'s CreateThread: SEH + unwinding objects in one function). No caller in this TU today.
#if defined(_MSC_VER)
static uint64_t SehReadStackSlot(const uint64_t *p)
{
    uint64_t v = 0;
    __try { v = *p; } __except (EXCEPTION_EXECUTE_HANDLER) { v = 0; }
    return v;
}
#endif

void BootWorker(uint32_t entryGuest)
{
    // Publish this host thread as the guest "main thread" for park probes.
    g_mainGuestThreadId.store(GetCurrentThreadId());

    PPCFunc* entryFunc = PPC_LOOKUP_FUNC(g_base, entryGuest);
    if (entryFunc == nullptr)
    {
        std::scoped_lock lock(g_reportMutex);
        g_report.faultInfo = "entry point not present in function table";
        g_bootDone.store(true);
        return;
    }

    PPCContext ctx;
    SetupInitialContext(ctx);
    ctx.lr = 0x00FFFFFF;

    // Publish this thread's context: hand-written kernel imports read
    // registers via the thread-local g_ppcContext (generated code gets ctx as
    // a parameter). Without this the first such import AV'd reading
    // g_ppcContext->r13 at offsetof 0x48 on a null pointer.
    SetPPCContext(ctx);

    g_faultCtx = &ctx;
    g_faultCtxTag = "boot-root";
    // T41.5b: the mirror another thread may read (see g_bootWorkerCtx above).
    g_bootWorkerCtx.store(&ctx, std::memory_order_relaxed);

// Install vectored exception handler for early crash detection
    PVOID vehHandle = AddVectoredExceptionHandler(1, [](PEXCEPTION_POINTERS ExceptionInfo) -> LONG {
        DWORD code = ExceptionInfo->ExceptionRecord->ExceptionCode;
        PVOID addr = ExceptionInfo->ExceptionRecord->ExceptionAddress;
        DWORD flags = ExceptionInfo->ExceptionRecord->ExceptionFlags;
        ULONG_PTR* info = ExceptionInfo->ExceptionRecord->ExceptionInformation;
        DWORD nInfo = ExceptionInfo->ExceptionRecord->NumberParameters;
        const uintptr_t pc = (uintptr_t)addr;
        const uintptr_t rva = (g_moduleBase != 0 && pc >= g_moduleBase) ? pc - g_moduleBase : pc;

        // B1: DR watchpoint single-steps are ours — log and continue BEFORE any
        // of the census/park machinery below sees them (they would eat the
        // fullDump budget and could park a healthy consumer thread).
        if (code == 0x80000004L && B1HandleSingleStep(ExceptionInfo)) {
            return EXCEPTION_CONTINUE_EXECUTION;
        }

        // B1 guard-page watchpoint (F-100 rule 19): same reason — must be
        // resolved before the census/park machinery, which would otherwise spend
        // the fullDump budget and park a thread that is merely the consumer.
        if (code == 0xC0000005L && B1GuardHandle(ExceptionInfo)) {
            return EXCEPTION_CONTINUE_EXECUTION;
        }

        // F-374: user-heap header guard. Same placement rule as B1GuardHandle above — it must
        // settle before the census/park machinery, or a trip on the first page of the guest heap
        // would be charged to whatever thread happened to fault there.
        if (code == 0xC0000005L && (HeapGuardHandle(ExceptionInfo) ||
                                    PhysGuardHandle(ExceptionInfo))) {
            return EXCEPTION_CONTINUE_EXECUTION;
        }

        // W0 flood cap: full dump only for the first few exceptions. Later
        // faults on other threads get a one-liner and still get parked.
        static std::atomic<uint32_t> s_vehCount{0};
        const uint32_t vehN = s_vehCount.fetch_add(1, std::memory_order_relaxed);
        const bool fullDump = (vehN < 3);

        // Write crash dump to file immediately (in case log doesn't flush)
        if (fullDump) {
        FILE* crashFile = nullptr;
        fopen_s(&crashFile, "crash_dump.txt", "w");
        if (crashFile) {
            fprintf(crashFile, "Exception: code=0x%08X addr=0x%p rva=0x%X flags=0x%X nParams=%u thread=%lu\n",
                    code, addr, rva, flags, nInfo, GetCurrentThreadId());
            for (DWORD i = 0; i < nInfo; ++i) {
                fprintf(crashFile, "  Param[%u]=0x%p\n", i, (PVOID)info[i]);
            }
            
            // Register-independent attribution (survives a stale/wrong-context dump).
            fprintf(crashFile, "  rip owner=%s\n", GuestFnAtHostAddr(pc));

            // PPC context
            // F692-FIX-1 (2026-10-01): THE GATE IS SPLIT BY WHAT IT ACTUALLY OWNS.
            // One `if (g_faultCtx)` used to cover three groups that do not have
            // the same dependency. Measured, not assumed: g_faultCtx is
            // thread_local and is assigned in exactly two places -- the boot
            // root at :2184 and FaultContextScope's ctor at :2902 -- and
            // w685.log:376 prints `ppc ctx=nil tag=none tid=9068`, i.e. the
            // faulting thread was neither, so the whole block was skipped. The
            // group below is the one that would have named the bad call target.
            //   * DEPENDS on g_faultCtx, and correctly so: `ppc ctx=` and the
            //     `ppc r1..r13` GPR row. They ARE the context. With no context
            //     there is nothing to print, and substituting another frame's
            //     registers is exactly F-046/F-692.
            //   * DEPENDS on nothing g_faultCtx owns: `g_base=`, the `y = 0`
            //     member of `probe y=`, and the CTRFROMFAULTADDR row added
            //     below. These read only the process-wide g_base and Param[1].
            const PPCContext* fc = g_faultCtx;
            if (fc != nullptr) {
                fprintf(crashFile, "  ppc ctx=%p tag=%s tid=%lu (registers below belong to THIS context)\n",
                        (const void*)fc, g_faultCtxTag, GetCurrentThreadId());
                fprintf(crashFile, "  ppc r1=%08X lr=%08X r3=%08X r4=%08X r5=%08X r6=%08X r7=%08X r8=%08X r9=%08X r10=%08X r13=%08X\n",
                        fc->r1.u32, (uint32_t)fc->lr, fc->r3.u32, fc->r4.u32, fc->r5.u32,
                        fc->r6.u32, fc->r7.u32, fc->r8.u32, fc->r9.u32, fc->r10.u32, fc->r13.u32);
            } else {
                fprintf(crashFile, "  ppc ctx=nil tag=%s tid=%lu — nothing published on the faulting thread;"
                                   " any GPR read from this dump would be another frame's (F-046)\n",
                        g_faultCtxTag, GetCurrentThreadId());
                // The gate is now NAMED rather than silent. A missing row and a
                // row that is absent because nothing produced it are different
                // facts, and only one of them is diagnosable.
                fprintf(crashFile,
                        "  FAULTCTX-GATE gate=thread_local g_faultCtx value=nullptr "
                        "tag=%s tid=%lu "
                        "suppressed=[ppc r1..r13, probe y in {r8,r9,r3,lr}] "
                        "why=no-FaultContextScope-on-this-thread "
                        "(ctor is at :2902, the boot root assignment at :2184; "
                        "measured nil at w685.log:376) "
                        "recovered=[CTRFROMFAULTADDR, below] "
                        "not-recoverable=[live guest ctr/xer/r11/r30 -- host locals "
                        "per ppc_config.h, not PPCContext members]\n",
                        g_faultCtxTag, GetCurrentThreadId());
            }

            // ---- F692-FIX-1: everything below is UNCONDITIONAL. It sat inside
            // the `if (g_faultCtx)` above and therefore printed only when a
            // context existed -- i.e. never on the faults that needed it. Each
            // row is hoisted verbatim (same format string, same values) and the
            // ORDER relative to the rows it used to follow is unchanged, so a run
            // that DOES have a context emits byte-identical rows in byte-identical
            // order. Nothing here dereferences `fc` without checking it first.
            {
                const uint64_t b = (uint64_t)(uintptr_t)g_base;
                fprintf(crashFile, "  g_base=0x%llX table=0x%llX\n",
                        (unsigned long long)b,
                        (unsigned long long)(b + PPC_IMAGE_BASE + PPC_IMAGE_SIZE));

                // T38.2 (revised at build time): PPCContext has NO ctr/xer/r11/r30
                // members — ppc_config.h makes them host locals
                // (PPC_CONFIG_CTR_AS_LOCAL / _NON_ARGUMENT_AS_LOCAL / _NON_VOLATILE_AS_LOCAL),
                // so they can never be dumped. What CAN settle the 0x7E780000 family is
                // identity-testing the fault address against the function-table probe
                // PPC_LOOKUP_FUNC(base,y) for the candidate targets, because the generated
                // code does `ctr.u64 = ctx.rN.u64` straight before the call.
                // The candidate set is split the same way the gate is: `y = 0` needs
                // no register at all and the other four read registers, so with no
                // context the printed set is exactly {0}. No register is ever
                // synthesised to pad the list (charter F-609).
                uint32_t probeCands[5];
                int nProbeCands = 0;
                probeCands[nProbeCands++] = (uint32_t)0u;
                if (fc != nullptr) {
                    probeCands[nProbeCands++] = fc->r8.u32;
                    probeCands[nProbeCands++] = fc->r9.u32;
                    probeCands[nProbeCands++] = fc->r3.u32;
                    probeCands[nProbeCands++] = (uint32_t)fc->lr;
                }
                for (int probeI = 0; probeI < nProbeCands; ++probeI) {
                    const uint32_t cand = probeCands[probeI];
                    const uint64_t s64 = (uint64_t)PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
                                         (uint64_t(uint32_t(cand) - PPC_CODE_BASE) * 2);
                    const bool hit = code == 0xC0000005 && nInfo >= 2 &&
                            (uint32_t)(uintptr_t)info[1] == (uint32_t)s64;
                    fprintf(crashFile, "  probe y=%08X -> off32=0x%08X%s\n", cand,
                            (uint32_t)s64, hit ? " == Param[1] (base contributed 0)" : "");
                }

                // ---- CTRFROMFAULTADDR: the value `ctr` would have had, RECOVERED
                // FROM Param[1]. This is the row the old layout structurally could
                // not print, and it is what makes the next 0x7E780000-family AV one
                // line instead of a disassembly hunt.
                //
                // WHY IT IS A MEASUREMENT AND NOT A FABRICATION (charter F-609).
                // Both inputs were produced by something other than this code:
                // Param[1] is the address the CPU faulted on, g_base is the window
                // the guest ran in. The middle step is the macro's own expression,
                // quoted rather than recalled -- src/ppc_context.h:124:
                //   x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE
                //       + (uint64_t(uint32_t(y) - PPC_CODE_BASE) * 2)
                // No PPCContext is touched, so this row cannot inherit another
                // frame's registers (the F-046 failure), and it does not claim to
                // BE a register value: it names the unique 32-bit `y` that makes
                // the load address equal Param[1], and refuses when there is none.
                //
                // TWO ARITHMETIC TRAPS, both found by evaluating the expression and
                // round-tripping it over 69,632 values of y -- not by reasoning:
                //   (1) `uint32_t(y) - PPC_CODE_BASE` is a 64-BIT subtraction.
                //       PPC_CODE_BASE is `0x82130000ull` and unsigned long long
                //       represents every uint32_t, so `y` is promoted and the
                //       subtraction does NOT wrap at 32 bits. For y = 0 the term is
                //       0xFFFFFFFF7ED00000, *2 wraps, and the resulting address
                //       0x7E780000 lands BELOW base = 0x100000000 (measured,
                //       w688.log). An inversion that rejected `p1 < base` would
                //       refuse exactly the case that matters, and one done on the
                //       low 32 bits cannot recover it at all -- the high bits it
                //       needs are the ones that truncation drops.
                //   (2) halving the wrapped product is ambiguous by 2^63, because
                //       the true term has its top bit set for every y below
                //       PPC_CODE_BASE. Resolved without guessing: y is 32-bit, so
                //       the term must lie in [-0x82130000, 0x7ED00000); the two
                //       candidates are 2^63 apart, so at most one is in range, and
                //       when NEITHER is the row REFUSES instead of rounding.
                if (g_base != nullptr && nInfo >= 2) {
                    const uint64_t p1 = (uint64_t)(uintptr_t)info[1];
                    const uint64_t t2 = (p1 - b - PPC_IMAGE_BASE - PPC_IMAGE_SIZE);
                    uint64_t ctrInv = 0;
                    bool solved = false;
                    bool termWrapped = false;
                    if ((t2 & 1u) == 0) {
                        // A plain array, not a braced-init-list range: the list
                        // form needs <initializer_list>, which this TU only has
                        // transitively, and a standalone compile of this block
                        // proved it is not guaranteed.
                        const uint64_t ctrCands[2] = { t2 >> 1, (t2 >> 1) + (1ull << 63) };
                        for (const uint64_t cand : ctrCands) {
                            const int64_t sv = (int64_t)cand;
                            if (sv >= -(int64_t)PPC_CODE_BASE &&
                                sv <= (int64_t)(0xFFFFFFFFull - PPC_CODE_BASE)) {
                                ctrInv = (uint32_t)(cand + PPC_CODE_BASE);
                                solved = true;
                                termWrapped = (sv < 0);
                                break;
                            }
                        }
                    }
                    if (solved) {
                        fprintf(crashFile,
                                "  CTRFROMFAULTADDR code=%08X param1=0x%llX base=0x%llX "
                                "invert=OK ctr=0x%08X term=%s "
                                "note=\"unique 32-bit y with PPC_LOOKUP_FUNC(base,y)"
                                "==Param[1]; NOT a register read\"\n",
                                (unsigned)code, (unsigned long long)p1,
                                (unsigned long long)b, (unsigned)ctrInv,
                                termWrapped ? "wrapped_neg" : "plain");
                    } else {
                        fprintf(crashFile,
                                "  CTRFROMFAULTADDR code=%08X param1=0x%llX base=0x%llX "
                                "invert=%s "
                                "note=\"Param[1] is NOT base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE"
                                "+2*(uint32 y - PPC_CODE_BASE) for any 32-bit y; this "
                                "fault address is not a function-table load\"\n",
                                (unsigned)code, (unsigned long long)p1,
                                (unsigned long long)b,
                                (t2 & 1u) ? "ODD_DELTA" : "NO_32BIT_CTR");
                    }
                }
            }
            
            // Host registers
            if (code == 0xC0000005 && ExceptionInfo->ContextRecord) {
                const CONTEXT* c = ExceptionInfo->ContextRecord;
                fprintf(crashFile, "  host regs rip=%p rax=%p rbx=%p rcx=%p rdx=%p rsi=%p rdi=%p r8=%p r9=%p r10=%p r11=%p rsp=%p\n",
                        (PVOID)c->Rip, (PVOID)c->Rax, (PVOID)c->Rbx, (PVOID)c->Rcx, (PVOID)c->Rdx,
                        (PVOID)c->Rsi, (PVOID)c->Rdi, (PVOID)c->R8, (PVOID)c->R9,
                        (PVOID)c->R10, (PVOID)c->R11, (PVOID)c->Rsp);
            }

            // F-640: A FAULT INSIDE A PHYSICAL VIEW IS NAMED AS ONE. The three views
            // (0xA0000000/64K, 0xC0000000/16M, 0xE0000000/4K, memory.cc:173-180) are flat
            // memory in this tree, so a fault there is not "some flat address" -- it is a
            // physical access that never reached the pool, and the crash file is the only
            // place that can say so while the row is still cheap. Prints the view, the
            // physical address it carries, the pool address that address SHOULD have used,
            // and the fact that no alias exists here. Read-only: it classifies, it does not
            // touch the window, and it cannot change guest behaviour.
            if (code == 0xC0000005 && addr != nullptr && g_base != nullptr)
            {
                const uintptr_t ab = (uintptr_t)g_base;
                const uintptr_t a = (uintptr_t)addr;
                if (a >= ab && (uint64_t)(a - ab) < GuestMemorySize)
                {
                    const uint32_t gva = (uint32_t)(a - ab);
                    if (F640ClassifyView(gva) != F640View::kNone)
                    {
                        uint32_t poolVa = 0;
                        const F640Map map = F640MapViewToPool(gva, &poolVa);
                        char poolStr[16] = "NONE";
                        if (map == F640Map::kMapped)
                            std::snprintf(poolStr, sizeof(poolStr), "%08X", poolVa);
                        fprintf(crashFile,
                                "  F640-CVIEW-FAULT guest=%08X view=%s pa=%08X pool_va=%s "
                                "verdict=%s\n",
                                gva, PhysViewName(gva),
                                gva - kF640Views[(uint32_t)F640ClassifyView(gva) - 1u].base,
                                poolStr,
                                (map == F640Map::kMapped
                                     ? "ALIAS_ABSENT: reached flat memory, not the pool"
                                     : "NO_POOL_BYTE: this physical address has no pool byte "
                                       "in this tree (F-640)"));
                    }
                }
            }

            // Session 76b: locate the faulting value in guest memory —
            // find which structure carries the garbage pointer.
            if (code == 0xC0000005 && nInfo >= 2) {
                const uint32_t needle = (uint32_t)(uintptr_t)info[1];
                if (needle != 0) {
                    uint8_t pat[4] = {(uint8_t)(needle >> 24),
                                      (uint8_t)(needle >> 16),
                                      (uint8_t)(needle >> 8),
                                      (uint8_t)needle};
                    // F-412: `hi` is 64-bit so the phys band can name its real upper bound
                    // (0x100000000 does not fit in uint32_t).
                    struct Range { uint32_t lo; uint64_t hi; const char* name; };
                    const Range ranges[] = {
                        {0x00600000, 0x00800000, "stacks"},
                        {0x50000000, 0x60000000, "inflate-out"},
                        // F-412: the pool follows F-391 to kPhysArenaBeginVa (0xA0400000). F-640:
                        // its upper bound is the ALLOCATOR's extent, kPhysArenaEndVa, which is
                        // kPhysArenaBeginVa + kConsolePhysicalBytes = 0xC0400000. This row used
                        // the 4 GiB window top (`0x100000000`), which after the 512 MiB cap
                        // over-reports by exactly 0x100000000 - 0xC0400000 = 0x3FC00000 =
                        // 1,022.0 MiB of memory that is no longer ours -- a 1.5 GiB byte-by-byte
                        // scan in a crash handler, and (worse for triage) a scan that could spend
                        // its `hits < 8` budget on flat memory above the pool and suppress a real
                        // in-pool hit. The 4 MiB of C-view addresses that used to sit inside this
                        // band are now correctly EXCLUDED: on the console 0xC0000000+pa is pool
                        // offset pa, which is not what those bytes are here (see F-640's block
                        // comment at the top of this file).
                        {mcla::kernel::kPhysArenaBeginVa,
                         (uint64_t)mcla::kernel::kPhysArenaEndVa, "phys-heap"},
                        {0x82000000, 0x82AD3000, "image+bss"},
                    };
                    uint8_t* guestBase = (uint8_t*)mcla::kernel::g_memory.base;
                    int hits = 0;
                    for (const auto& r : ranges) {
                        uint8_t* p = guestBase + r.lo;
                        const size_t len = r.hi - r.lo;
                        for (size_t i = 0; i + 4 <= len && hits < 8; ++i) {
                            if (p[i] == pat[0] && p[i+1] == pat[1] &&
                                p[i+2] == pat[2] && p[i+3] == pat[3]) {
                                const uint32_t va = r.lo + (uint32_t)i;
                                fprintf(crashFile,
                                        "  needle %08X @ guest %08X (%s): ",
                                        needle, va, r.name);
                                for (int k = -16; k < 16; k += 4) {
                                    if ((int)i + k >= 0) {
                                        uint32_t w;
                                        memcpy(&w, p + i + k, 4);
                                        fprintf(crashFile, "%08X ", w);
                                    }
                                }
                                fprintf(crashFile, "\n");
                                ++hits;
                                i += 4;
                            }
                        }
                        if (hits >= 8) break;
                    }
                    if (hits == 0)
                        fprintf(crashFile, "  needle %08X: no occurrences in scanned regions\n", needle);
                }
            }

            // Session 76g: dump the device-list neighborhood around the
            // faulting ppc r6 (the device object whose name ptr = garbage).
            if (code == 0xC0000005 && g_faultCtx) {
                const uint32_t r6v = g_faultCtx->r6.u32;
                // F-412: F-391 moved the pool to kPhysArenaBeginVa (0xA0400000); the old
                // 0xA0000000..0xB0000000 band cut the pool in half at a stale address. F-640:
                // the upper bound is the allocator's extent, kPhysArenaEndVa, NOT the end of the
                // 4 GiB window. This predicate is what this dump is gated on, so the old `>=`
                // alone admitted r6 anywhere in the top 1.5 GiB and printed a "device dump
                // around r6" for a pointer that is not a pool address at all -- after the
                // 512 MiB cap that is 1,020.0 MiB of guest VA that no longer belongs to the
                // pool (0xC0400000..0xFFFFFFFF). A guest VA is never asserted on: the test is
                // two unsigned comparisons and the dump is skipped, not sanitised.
                if (r6v >= mcla::kernel::kPhysArenaBeginVa &&
                    r6v < mcla::kernel::kPhysArenaEndVa) {
                    uint8_t* guestBase = (uint8_t*)mcla::kernel::g_memory.base;
                    uint8_t* p = guestBase + (r6v & ~0xFu) - 0x40;
                    fprintf(crashFile, "  device dump around r6=%08X:\n", r6v);
                    for (int row = 0; row < 12; ++row) {
                        fprintf(crashFile, "   %08X:", (r6v & ~0xFu) - 0x40 + row*16);
                        for (int w = 0; w < 4; ++w) {
                            uint32_t v;
                            memcpy(&v, p + row*16 + w*4, 4);
                            fprintf(crashFile, " %08X", v);
                        }
                        fprintf(crashFile, "\n");
                    }
                }
            }
            
            // Stack trace
            if (code == 0xC0000005 || code == 0x80000003 || code == 0xE06D7363) {
                static std::once_flag symOnce;
                std::call_once(symOnce, [] {
                    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                    SymInitialize(GetCurrentProcess(), nullptr, TRUE);
                });
                void* frames[32] = {};
                const USHORT nFrames = CaptureStackBackTrace(0, 32, frames, nullptr);
                fprintf(crashFile, "Stack trace (%hu frames):\n", nFrames);
                char symBuf[sizeof(SYMBOL_INFO) + 160] = {};
                auto* sym = reinterpret_cast<SYMBOL_INFO*>(symBuf);
                sym->SizeOfStruct = sizeof(SYMBOL_INFO);
                sym->MaxNameLen = 159;
                SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                SymInitialize(GetCurrentProcess(), nullptr, TRUE);
                for (USHORT i = 0; i < 32 && i < (USHORT)nFrames; ++i) {
                    DWORD64 disp = 0;
                    char symBuf2[sizeof(SYMBOL_INFO) + 160] = {};
                    auto* sym = reinterpret_cast<SYMBOL_INFO*>(symBuf2);
                    sym->SizeOfStruct = sizeof(SYMBOL_INFO);
                    sym->MaxNameLen = 159;
                    if (SymFromAddr(GetCurrentProcess(), reinterpret_cast<DWORD64>(frames[i]), nullptr, sym)) {
                        fprintf(crashFile, "  [%02u] %s\n", i, sym->Name);
                    } else {
                        fprintf(crashFile, "  [%02u] ??? 0x%p\n", i, frames[i]);
                    }
                }
            }
            fflush(crashFile);
            fclose(crashFile);
        }
        } // fullDump

        if (!fullDump) {
            MCLA_LOG_ERROR("VEH[{}] (capped) code=0x{:08X} addr=0x{:p} nParams={} thread={}",
                           vehN, code, addr, nInfo, GetCurrentThreadId());
        } else {
        MCLA_LOG_ERROR("Vectored exception: code=0x{:08X} addr=0x{:p} rva=0x{:X} flags=0x{:X} nParams={} thread={}",
                       code, addr, rva, flags, nInfo, GetCurrentThreadId());
        for (DWORD i = 0; i < nInfo; ++i) {
            MCLA_LOG_ERROR("  Param[{}]=0x{:p}", i, (PVOID)info[i]);
        }
        // Register-independent attribution: the translated guest function that
        // contains the faulting host instruction.
        MCLA_LOG_ERROR("  rip owner={}", GuestFnAtHostAddr(pc));
        // F692-FIX-1 (2026-10-01): the gate is split by what it owns. See the
        // long form of this comment in the crash_dump.txt block above, which is
        // the same VEH lambda. Measured: g_faultCtx is thread_local, assigned
        // only at :2184 (boot root) and at :2902 (FaultContextScope ctor), and
        // w685.log:376 prints `ppc ctx=nil tag=none` -- so this whole block used
        // to be skipped on the faults that needed it.
        //   DEPENDS on g_faultCtx: `ppc ctx=` and `ppc r1..r13` (they ARE the
        //     context; substituting another frame's is F-046/F-692).
        //   DEPENDS on nothing it owns: `g_base=`, the `y = 0` member of
        //     `probe y=`, and CTRFROMFAULTADDR (Param[1] + g_base only).
        const PPCContext* fc = g_faultCtx;
        if (fc != nullptr)
        {
            MCLA_LOG_ERROR("  ppc ctx={:p} tag={} tid={} (registers below belong to THIS context)",
                           (const void*)fc, g_faultCtxTag, GetCurrentThreadId());
            MCLA_LOG_ERROR("  ppc r1={:08X} lr={:08X} r3={:08X} r4={:08X} r5={:08X} r6={:08X} "
                           "r7={:08X} r8={:08X} r9={:08X} r10={:08X} r13={:08X}",
                           fc->r1.u32, (uint32_t)fc->lr, fc->r3.u32, fc->r4.u32, fc->r5.u32,
                           fc->r6.u32, fc->r7.u32, fc->r8.u32, fc->r9.u32, fc->r10.u32, fc->r13.u32);
        }
        else
        {
            MCLA_LOG_ERROR("  ppc ctx=nil tag={} tid={} — nothing published on the faulting thread;"
                           " any GPR read from this dump would be another frame's (F-046)",
                           g_faultCtxTag, GetCurrentThreadId());
            // Name the gate rather than leave the omission silent.
            MCLA_LOG_ERROR("  FAULTCTX-GATE gate=thread_local g_faultCtx value=nullptr tag={} tid={} "
                           "suppressed=[ppc r1..r13, probe y in {{r8,r9,r3,lr}}] "
                           "why=no-FaultContextScope-on-this-thread "
                           "(ctor is at :2902, the boot root assignment at :2184; "
                           "measured nil at w685.log:376) "
                           "recovered=[CTRFROMFAULTADDR, below] "
                           "not-recoverable=[live guest ctr/xer/r11/r30 -- host locals "
                           "per ppc_config.h, not PPCContext members]",
                           g_faultCtxTag, GetCurrentThreadId());
        }

        // ---- F692-FIX-1: UNCONDITIONAL. Hoisted verbatim from inside the
        // `if (fc)` above (same format strings, same values, same order relative
        // to the rows they used to follow), so a run WITH a context emits
        // byte-identical rows in byte-identical order. Nothing dereferences `fc`
        // without checking it first.
        {
            const uint64_t b = (uint64_t)(uintptr_t)g_base;
            MCLA_LOG_ERROR("  g_base=0x{:X} table=0x{:X}", b,
                           b + PPC_IMAGE_BASE + PPC_IMAGE_SIZE);

            // T38.2 (revised at build time): ctr/xer/r11/r30 are NOT PPCContext members
            // (ppc_config.h PPC_CONFIG_CTR_AS_LOCAL / _NON_ARGUMENT_AS_LOCAL /
            // _NON_VOLATILE_AS_LOCAL make them host locals), so the dump can never carry
            // them. Identity-test the fault address against the function-table probe
            // instead — the generated code copies a ctx register into ctr immediately
            // before PPC_CALL_INDIRECT_FUNC, so one of these candidates must match.
            // Split the same way the gate is: `y = 0` reads no register, the other
            // four do, so with no context the printed set is exactly {0}. No
            // register is ever synthesised to pad the list (charter F-609).
            uint32_t probeCands[5];
            int nProbeCands = 0;
            probeCands[nProbeCands++] = (uint32_t)0u;
            if (fc != nullptr) {
                probeCands[nProbeCands++] = fc->r8.u32;
                probeCands[nProbeCands++] = fc->r9.u32;
                probeCands[nProbeCands++] = fc->r3.u32;
                probeCands[nProbeCands++] = (uint32_t)fc->lr;
            }
            for (int probeI = 0; probeI < nProbeCands; ++probeI) {
                const uint32_t cand = probeCands[probeI];
                const uint64_t s64 = (uint64_t)PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
                                     (uint64_t(uint32_t(cand) - PPC_CODE_BASE) * 2);
                MCLA_LOG_ERROR("  probe y={:08X} -> off32=0x{:08X}{}", cand, (uint32_t)s64,
                               code == 0xC0000005 && nInfo >= 2 &&
                                       (uint32_t)(uintptr_t)info[1] == (uint32_t)s64
                                   ? " == Param[1] (base contributed 0)"
                                   : "");
            }

            // CTRFROMFAULTADDR: `ctr` recovered from Param[1] alone. A measurement
            // (charter F-609), not a register read: Param[1] is what the CPU faulted
            // on, g_base is the window the guest ran in, and the middle step is
            // src/ppc_context.h:124 quoted verbatim:
            //   x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE
            //       + (uint64_t(uint32_t(y) - PPC_CODE_BASE) * 2)
            // Two arithmetic traps, both found by round-tripping 69,632 values of y
            // rather than by reasoning (see the crash_dump.txt block for the full
            // derivation): `uint32_t(y) - PPC_CODE_BASE` is a 64-bit subtraction, so
            // for y=0 the resulting address 0x7E780000 lands BELOW base=0x100000000
            // (a `p1 < base` guard would refuse the case that matters); and halving
            // the wrapped product is ambiguous by 2^63, resolved without guessing
            // because y is 32-bit and the two candidates are 2^63 apart -- when
            // NEITHER is in range the row refuses instead of rounding.
            if (g_base != nullptr && nInfo >= 2) {
                const uint64_t p1 = (uint64_t)(uintptr_t)info[1];
                const uint64_t t2 = (p1 - b - PPC_IMAGE_BASE - PPC_IMAGE_SIZE);
                uint64_t ctrInv = 0;
                bool solved = false;
                bool termWrapped = false;
                if ((t2 & 1u) == 0) {
                    // A plain array, not a braced-init-list range: the list form
                    // needs <initializer_list>, which this TU only has
                    // transitively, and a standalone compile of this block proved
                    // it is not guaranteed.
                    const uint64_t ctrCands[2] = { t2 >> 1, (t2 >> 1) + (1ull << 63) };
                    for (const uint64_t cand : ctrCands) {
                        const int64_t sv = (int64_t)cand;
                        if (sv >= -(int64_t)PPC_CODE_BASE &&
                            sv <= (int64_t)(0xFFFFFFFFull - PPC_CODE_BASE)) {
                            ctrInv = (uint32_t)(cand + PPC_CODE_BASE);
                            solved = true;
                            termWrapped = (sv < 0);
                            break;
                        }
                    }
                }
                if (solved) {
                    MCLA_LOG_ERROR("  CTRFROMFAULTADDR code={:08X} param1=0x{:X} base=0x{:X} "
                                   "invert=OK ctr=0x{:08X} term={} "
                                   "note=\"unique 32-bit y with PPC_LOOKUP_FUNC(base,y)"
                                   "==Param[1]; NOT a register read\"",
                                   (unsigned)code, p1, b, (unsigned)ctrInv,
                                   termWrapped ? "wrapped_neg" : "plain");
                } else {
                    MCLA_LOG_ERROR("  CTRFROMFAULTADDR code={:08X} param1=0x{:X} base=0x{:X} "
                                   "invert={} "
                                   "note=\"Param[1] is NOT base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE"
                                   "+2*(uint32 y - PPC_CODE_BASE) for any 32-bit y; this "
                                   "fault address is not a function-table load\"",
                                   (unsigned)code, p1, b,
                                   (t2 & 1u) ? "ODD_DELTA" : "NO_32BIT_CTR");
                }
            }
        }

        // Host GP registers - session 17: pin which pointer is the bad raw
        // host address (e.g. 0x7E780000) at indirect-dispatch fault sites.
        if (code == 0xC0000005 && ExceptionInfo->ContextRecord)
        {
            const CONTEXT* c = ExceptionInfo->ContextRecord;
            MCLA_LOG_ERROR("  host regs rip={:p} rax={:p} rbx={:p} rcx={:p} rdx={:p} rsi={:p} rdi={:p} "
                           "r8={:p} r9={:p} r10={:p} r11={:p} rsp={:p}",
                           (PVOID)c->Rip, (PVOID)c->Rax, (PVOID)c->Rbx, (PVOID)c->Rcx, (PVOID)c->Rdx,
                           (PVOID)c->Rsi, (PVOID)c->Rdi, (PVOID)c->R8, (PVOID)c->R9,
                           (PVOID)c->R10, (PVOID)c->R11, (PVOID)c->Rsp);
        }

        // resolve host symbols from the PDB so crashes name themselves
        if (code == 0xC0000005 || code == 0x80000003 || code == 0xE06D7363)
        {
            static std::once_flag symOnce;
            std::call_once(symOnce, [] {
                SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                SymInitialize(GetCurrentProcess(), nullptr, TRUE);
            });
            void* frames[24] = {};
            const USHORT nFrames = CaptureStackBackTrace(0, 24, frames, nullptr);
            char symBuf[sizeof(SYMBOL_INFO) + 160] = {};
            auto* sym = reinterpret_cast<SYMBOL_INFO*>(symBuf);
            sym->SizeOfStruct = sizeof(SYMBOL_INFO);
            sym->MaxNameLen = 159;
            MCLA_LOG_ERROR("  host stack (deepest first):");
            for (USHORT i = 0; i < nFrames && i < 14; ++i) {
                DWORD64 disp = 0;
                if (SymFromAddr(GetCurrentProcess(), reinterpret_cast<DWORD64>(frames[i]), &disp, sym)) {
                    MCLA_LOG_ERROR("   [{:2}] {} +0x{:X}", i, sym->Name, disp);
                } else {
                    MCLA_LOG_ERROR("   [{:2}] ??? 0x{:p}", i, frames[i]);
                }
            }
        }
        } // fullDump log
        spdlog::default_logger()->flush();

        // W0: park guest (and any recoverable) AVs instead of letting Windows
        // kill the thread/process via EXCEPTION_CONTINUE_SEARCH.
        // 0x7E78xxxx = PPC_LOOKUP_FUNC(guest 0) wild-pointer family.
        // Guest lr set while g_faultCtx is live = fault inside recompiled code.
        bool wildParam = false;
        if (code == 0xC0000005 && nInfo >= 2) {
            const uint32_t p1 = (uint32_t)(uintptr_t)info[1];
            if (p1 >= 0x7E000000u && p1 < 0x7F000000u)
                wildParam = true;
        }
        const uint32_t glr = g_faultCtx ? (uint32_t)g_faultCtx->lr : 0u;
        const bool guestLrSet = (g_faultCtx != nullptr) && glr != 0u && glr != 0x00FFFFFFu;
        const bool guestAv = wildParam || guestLrSet || (g_faultCtx != nullptr && code == 0xC0000005);
        const bool isBootWorker = (GetCurrentThreadId() == s_bootWorkerThreadId);
        const bool isUILoadThread = (GetCurrentThreadId() == s_uiLoadThreadId.load()) || s_inUILoad.load();

        // W36f: boot worker / UILOAD thread special handling.
        //
        // T38.3 (2026-09-20): the three recovery paths that used to live inside this block are
        // DELETED, not tuned. They were (a) float-div-0 → clear MXCSR + zero XMM0 + re-execute,
        // plus a 0xC3 (RET) code patch over sub_823D91F8's host entry and an infinite park at
        // lr=0x82133440; (b) illegal-instruction → Rip += 256MB; (c) the "known crash site"
        // lr=0x822F44E0/0x82133440 branch → set s_skipSub822FA958, patch sub_822FA958's host
        // entry with 0xC3 and Rip += 256MB. F-051 measured 0 firings across two honest soaks and
        // called them dead; build/w38e.log disproved that the moment the gate driver reached
        // UILOAD — (c) fired 616,824 times, each 256MB advance re-faulting 0x10000000 higher,
        // turning ONE guest write to 0xE0 into a 1.86M-line log. All three fabricated execution
        // (PLAN_VMX128 risk R5) and hid the real fault. A guest AV now takes the VEH-NEUTRAL
        // decline below, and then the generic park at the end of the handler.
        if (isBootWorker || isUILoadThread) {
            if (code == 0xC0000005) { // STATUS_ACCESS_VIOLATION
                if (ExceptionInfo->ContextRecord) {
                    // EXPERIMENT (session 79, user-approved): the recovery removed here
                    // advanced the host RIP by 16/64/4096 bytes and fabricated returns
                    // with RAX=0, so the guest executed control flow the PPC binary does
                    // not describe -- exactly what PLAN_VMX128 risk R5 forbids. It fired
                    // 703 times at one lr in build/smoke_long2.log. Report the real fault
                    // and decline instead, so the first divergence is observable.
                    const ULONG_PTR accessType =
                        ExceptionInfo->ExceptionRecord->ExceptionInformation[0];
                    const void* faultAddr = reinterpret_cast<const void*>(
                        ExceptionInfo->ExceptionRecord->ExceptionInformation[1]);
                    MCLA_LOG_WARN(
                        "VEH-NEUTRAL guest AV: lr={:08X} {} host addr {:p} (hostRip={:p}) "
                        "-- recovery disabled, declining",
                        glr,
                        accessType == 0 ? "read of"
                                        : (accessType == 1 ? "write to" : "exec of"),
                        faultAddr, (void*)ExceptionInfo->ContextRecord->Rip);
                    return EXCEPTION_CONTINUE_SEARCH;
                }
            }
        }

        // Park this thread forever for AV / illegal insn / fp-div0 / 0xC000012A. Never
        // return to the faulting code. Other threads (window, render,
        // workers) keep running so the process and HWND stay alive.
        // F-390: EXCEPT for a fault inside the allocator family, which the structured handler
        // already knows how to survive. VEH handlers run BEFORE `__except`, so the park below has
        // been swallowing exactly what `SehO1Allocate`/`SehO1Free` (`src/kernel/heap.cpp:74-102`)
        // exist to catch: `w394`..`w403` each log one `code=0xC0000005` at `o1heapAllocate+0x98`
        // and then park the thread, and F-387's `PARK-STACK` shows that thread is the boot worker
        // inside the UILOAD chain (`sub_82131508 -> sub_822C2EA8 -> ... -> sub_823973AC`, the
        // title's XTL allocator). Continuing the search makes the wrapper return null, so
        // `Heap::Alloc`/`AllocPhysical` emit their own OOM line and the guest keeps its error path
        // instead of losing a thread.
        if (code == 0xC0000005 && ExceptionInfo->ContextRecord)
        {
            const uintptr_t rip = (uintptr_t)ExceptionInfo->ContextRecord->Rip;
            bool inHeap = false;
            DWORD64 ib = 0;
            if (const PRUNTIME_FUNCTION rf = RtlLookupFunctionEntry((DWORD64)rip, &ib, nullptr))
            {
                const uintptr_t begin = (uintptr_t)(ib + rf->BeginAddress);
                const uintptr_t end = (uintptr_t)(ib + rf->EndAddress);
                for (const void *e : {static_cast<const void *>(&o1heapAllocate),
                                      static_cast<const void *>(&o1heapFree)})
                    if ((uintptr_t)e >= begin && (uintptr_t)e < end)
                        inHeap = true;
            }
            if (inHeap)
            {
                MCLA_LOG_WARN("F390-SEHPASS rip={} tid={} inside o1heap entry -- continuing the "
                              "search so SehO1* handles it",
                              g_moduleBase ? (unsigned long long)(rip - g_moduleBase)
                                           : (unsigned long long)rip,
                              GetCurrentThreadId());
                spdlog::default_logger()->flush();
                return EXCEPTION_CONTINUE_SEARCH;
            }
        }
        // W36: also park 0xC000008E (STATUS_FLOAT_DIVIDE_BY_ZERO) which
        // the atArray allocator chain triggers when the TLS chain is broken.
        if (code == 0xC0000005 || code == 0xC000001D || code == 0xC000012A ||
            code == 0xC000008E) {
            // F-412: never park the PARK-SAMPLE sampler. It is registered as a process-wide VEH
            // (AddVectoredExceptionHandler at BootWorker), so an AV on ANY thread reaches this
            // branch before any __try/__except can run -- ParkUnwindCapture's EXCEPTION_EXECUTE_HANDLER
            // never fires, ResumeThread (the sampler's worker-resume) is skipped, and the worker
            // stays suspended forever. Declining here hands the exception to that __except, so the
            // unwind returns normally and the resume runs on the way out.
            if (GetCurrentThreadId() == s_parkSamplerTid) {
                MCLA_LOG_ERROR("VEH W0: sampler thread {} code=0x{:08X} guest={} -- declining to "
                               "park (it owns the worker's suspend count); continuing the search",
                               GetCurrentThreadId(), code, guestAv ? 1 : 0);
                spdlog::default_logger()->flush();
                return EXCEPTION_CONTINUE_SEARCH;
            }
            MCLA_LOG_ERROR("VEH W0: parking thread {} code=0x{:08X} guest={} wild={} lr={:08X} "
                           "— process stays alive",
                           GetCurrentThreadId(), code, guestAv ? 1 : 0, wildParam ? 1 : 0, glr);
            // F-412: drain THIS thread's heap-guard windows before parking. The park never returns,
            // so ~HeapGuardWindow (heap.cpp:360) never runs and g_hgDepth would stay > 0 for the
            // rest of the run: both guard pages left PAGE_READWRITE, plus whatever heap mutex this
            // thread holds (heap.cpp:366/752) held forever, which would then deadlock every later
            // guard trip. Each HeapGuardArmImpl() drops one of our windows (t_hgWin and g_hgDepth
            // move together), and g_hgMtx is a recursive_mutex so re-entering it on this thread
            // while we already hold it (fault inside the drain's self-test read) cannot
            // self-deadlock; that self-test trip is claimed by HeapGuardHandle and
            // CONTINUE_EXECUTIONs, so it never re-enters this park branch.
            while (t_hgWin > 0)
                HeapGuardArmImpl();
            spdlog::default_logger()->flush();
            for (;;)
                Sleep(1000);
        }
        return EXCEPTION_CONTINUE_SEARCH;
    });

    // Install unhandled exception filter
    LPTOP_LEVEL_EXCEPTION_FILTER prevFilter = SetUnhandledExceptionFilter(UnhandledExceptionFilter);

    bool returned = false;
    MCLA_LOG_INFO("BootWorker: calling entry point 0x{:08X}", entryGuest);
    s_bootWorkerThreadId = GetCurrentThreadId();
    spdlog::default_logger()->flush();
    entryFunc(ctx, g_base);
    returned = true;
    MCLA_LOG_INFO("BootWorker: entry point returned! r3=0x{:08X} lr=0x{:08X} r1=0x{:08X} r13=0x{:08X}",
                  ctx.r3.u32, (uint32_t)ctx.lr, ctx.r1.u32, ctx.r13.u32);
    spdlog::default_logger()->flush();

    SetUnhandledExceptionFilter(prevFilter);

    {
        std::scoped_lock lock(g_reportMutex);
        g_report.returned = returned;
    }
    g_faultCtx = nullptr;
    g_bootWorkerCtx.store(nullptr, std::memory_order_relaxed);
    g_bootDone.store(true);
}

// T41.71 / F-393: name WHO CALLS the guest-memory accessors the boot worker parks in.
// PARK-SAMPLE's NearestFunctionName() is a nearest-preceding lookup, and its
// `nf=0x82131508 (+0x17171)` rows sit ~94 KB past the function they name; the raw RVAs
// resolve (tools/host_rva_resolve.py, bases printed by `PARK-SAMPLE base=` in w406 and
// w408) to GuestMemoryView::ReadU32BE/WriteU32BE/IsValidRange. So that thread is
// EXECUTING, not waiting, and the caller chain is the unknown. RtlCaptureStackBackTrace
// cannot walk another thread, and the [Rsp+8k] words the sampler prints are stack data,
// not return addresses -- so walk the exception table instead, while the thread is
// suspended, and report module RVAs for offline resolution (no PDB in this build, F-118).
// File scope, not a lambda: a function containing __try may not be defined at block
// scope, and SEH in this TU is what the clang-ICE note by BootThreadProc is about.
static void ParkUnwindCapture(const CONTEXT& tc, uint64_t* outRva, uint32_t* outN,
                              uint64_t* outOwnerRva, uint64_t* outOwnerOff)
{
    *outN = 0;
    __try
    {
        DWORD64 imgBase = 0;
        PRUNTIME_FUNCTION pf = RtlLookupFunctionEntry(tc.Rip, &imgBase, nullptr);
        if (pf == nullptr)
            return;
        *outOwnerRva = (uint64_t)pf->BeginAddress;
        *outOwnerOff = tc.Rip - (imgBase + (uint64_t)pf->BeginAddress);
        // F-412: RtlVirtualUnwind returns a PEXCEPTION_ROUTINE, NOT the caller's
        // PRUNTIME_FUNCTION (MSDN nf-winnt-rtlvirtualunwind; ReactOS unwind.c returns NULL
        // unless the frame carries a language handler). Treating it as the next table entry --
        // which is what the previous version did -- made `pf` NULL after the first step, so the
        // walk emitted exactly two rows and stopped: 51/51 samples in w418/w419/w420 printed
        // frames=0 or frames=2 and never 3. The next RUNTIME_FUNCTION has to be looked up again
        // from the advanced RIP, with its OWN image base (a frame may belong to another module).
        // The return value is discarded on purpose; that also sidesteps the 10.0.26100
        // signature mismatch that cost F-394 one build. The last parameter is
        // PKNONVOLATILE_CONTEXT_POINTERS on that SDK, hence nullptr rather than a history table.
        CONTEXT c = tc;
        DWORD64 imgBaseCur = imgBase;
        ULONG64 est = 0;
        for (uint32_t fr = 0; fr < 8; ++fr)
        {
            if (*outN < 8)
                outRva[(*outN)++] = c.Rip - imgBaseCur;
            PVOID hd = nullptr;
            CONTEXT next = c;
            RtlVirtualUnwind(0, imgBaseCur, c.Rip, pf, &next, &hd, &est, nullptr);
            // A non-advancing context ends the walk: prologue/epilogue ("null frame region")
            // or a leaf frame the table cannot describe.
            if (next.Rip == 0 || next.Rip == c.Rip)
                break;
            c = next;
            DWORD64 nb = 0;
            PRUNTIME_FUNCTION npf = RtlLookupFunctionEntry(c.Rip, &nb, nullptr);
            if (npf == nullptr)
            {
                // No table entry for the caller, but `c.Rip` is a real return address: record
                // it once here (the loop head would have duplicated it on a continuation).
                if (*outN < 8)
                    outRva[(*outN)++] = c.Rip - (nb != 0 ? nb : imgBaseCur);
                break;
            }
            imgBaseCur = nb;
            pf = npf;
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        // A failed unwind is a result, not a crash: keep whatever was captured.
    }
}

// F-412: the __finally the sampler's suspend window did not have. ResumeThread used to be a
// single statement between SuspendThread and the end of the iteration, so ANY path that left that
// window early (an exception thrown while the worker is suspended, or the VEH parking this thread
// before the F-412 decline was added) stranded the worker suspended -- and with it, if it was
// suspended holding g_hgMtx, every later heap-guard trip on every thread. Release() is the normal
// exit; the destructor covers everything else.
struct WorkerResumeGuard
{
    HANDLE h;
    bool live;
    explicit WorkerResumeGuard(HANDLE t) : h(t), live(true) {}
    void Release()
    {
        if (live)
        {
            live = false;
            ResumeThread(h);
        }
    }
    ~WorkerResumeGuard() { Release(); }
};

// F-616: the PARK sampler's proof that it can SEE. The false "65% of samples at guest
// lr=821C6DC8" was not a misread of a live field -- it was a sampler with NO WAY TO TELL
// "the worker did not move" from "I am blind", so a field that had been frozen for 97 s
// (last real F598-C6658 call 18:13:19.977, first PARK row claiming it 18:13:20.351, last
// 18:14:57.694) was believed for eight rounds. Same discipline as F388-PHYSGUARD SELFTEST
// and F374-HEAPGUARD SELFTEST: prove the probe fires on a change you made, or the probe
// is blind and its zeros/constancy mean nothing. s_parkBlind rides on every PARK-* line.
//
// Sink for the probe thread so its varying frame is addressable and cannot be elided.
    volatile uint8_t g_parkProbeSink = 0;
    std::atomic<uint32_t> s_parkBlind{1};  // 1 until ParkSamplerSelfTest says otherwise

// A probe thread that varies its OWN frame depth, so the one register the sampler claims
// to read from a suspended thread (Rsp) takes three distinct values. Deliberately NOT a
// write to a global: a global write proves the WRITE path, not the suspend/GetThreadContext
// path this probe exists to test. 3 x 1024 B of stack => 3 distinct Rsp by construction.
// Each depth is held for ~100 ms (100 x Sleep(1)) and the sequence runs 4 times, so the
// self-test gets ~1.2 s of wall time to observe all three -- bounding the self-test by
// COUNT instead (the first version) let the probe finish before the reads spread out,
// which would have reported blind=1 on a sampler that is fine.
    DWORD WINAPI ParkProbeThread(LPVOID)
{
    uint8_t depth[3][1024];
    std::memset(depth, 0, sizeof(depth));
    for (int round = 0; round < 4; ++round)
    {
        for (int d = 0; d < 3; ++d)
        {
            depth[d][0] = (uint8_t)(d + 1);
            for (int k = 0; k < 100; ++k)
            {
                g_parkProbeSink = depth[d][0];
                Sleep(1);
            }
        }
    }
    return 0;
}

// Returns 1 = the sampler is trustworthy, 0 = BLIND (every PARK-* row then carries blind=1
// and no conclusion may be drawn from it). Asserts, in order:
//   1. SuspendThread on a thread this process created does not fail,
//   2. GetThreadContext fills Rsp/Rip at all (an all-zero context is a fake read),
//   3. RtlLookupFunctionEntry describes that Rip, so PARK-UNWIND is armed (F-412 saw
//      frames=0/frames=2 come out of a build where the walk could not step),
//   4. THE ONE THAT MATTERS: reads taken 3 distinct Rsp values from a probe the sampler
//      did not have to cooperate with -- "I can see a change", not "I read a value".
// Criterion is distinct>=2, not 3: two values are the minimum that falsifies "constant".
    uint32_t ParkSamplerSelfTest(uintptr_t modBase, uint32_t* sawRva, uint32_t* sawFrames,
                                 uint32_t* sawDistinct)
    {
    *sawRva = 0;
    *sawFrames = 0;
    *sawDistinct = 0;
        HANDLE probe = CreateThread(nullptr, 0, ParkProbeThread, nullptr, 0, nullptr);
    if (probe == nullptr)
        return 0;
    uint64_t seen[3] = {0, 0, 0};
    uint32_t distinct = 0, reads = 0;
    // F-616: bounded by DEADLINE, not by spin count -- see ParkProbeThread's comment. The
    // deadline is 1.5 s, the probe lives ~1.2 s, so the reads are guaranteed to span all
    // three of its frames without this costing the boot anything measurable (once).
    const uint64_t deadline = GetTickCount64() + 1500;
    while (distinct < 3 && GetTickCount64() < deadline)
    {
        CONTEXT tc;
        std::memset(&tc, 0, sizeof(tc));
        tc.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
        if (SuspendThread(probe) == (DWORD)-1)
            break;
        const bool got = GetThreadContext(probe, &tc) != 0;
        if (got)
        {
            ++reads;
            bool dup = false;
            for (uint32_t k = 0; k < distinct; ++k)
                dup = dup || (seen[k] == tc.Rsp);
            if (!dup && distinct < 3)
                seen[distinct++] = tc.Rsp;
            if (*sawFrames == 0)
            {
                *sawRva = (modBase != 0 && tc.Rip >= modBase)
                              ? (uint32_t)(tc.Rip - modBase)
                              : 0;
                uint64_t u[8] = {0}, ownerRva = 0, ownerOff = 0;
                uint32_t n = 0;
                ParkUnwindCapture(tc, u, &n, &ownerRva, &ownerOff);
                *sawFrames = n;
            }
        }
        ResumeThread(probe);  // never leave the probe suspended: it must reach its 2nd frame
        // Yield often enough that the probe advances frames between our reads, but not so
        // often that the suspend/read/resume path stops being the thing under test.
        if ((reads % 16) == 0)
            Sleep(0);
    }
    WaitForSingleObject(probe, 3000);
    CloseHandle(probe);
    *sawDistinct = distinct;
    return (reads > 0 && distinct >= 2 && *sawFrames > 0) ? 1u : 0u;
}

    DWORD WINAPI BootThreadProc(LPVOID param)
    {
        const uint32_t entryGuest = (uint32_t)(uintptr_t)param;
        B1ArmCurrentThreadImpl();
        BootWorker(entryGuest);
        return 0;
    }
} // namespace

    // B1 cross-TU arming entry: guest_thread.cpp calls this at every guest
    // thread's start so the watchpoints follow the workers, not just the root.
    void B1ArmGuestThread() { B1ArmCurrentThreadImpl(); }

    void B1GuardArm(uint32_t guestVa) { B1GuardArmImpl(guestVa); }

    // F-374: public entry points for the user-heap header guard. The implementations live in this
    // file's anonymous namespace (opened at line 63), where they have internal linkage and
    // heap.cpp cannot link against them -- the first build of this instrument failed that way.
    // Same shape as the two wrappers above.
    void HeapGuardArm() { HeapGuardArmImpl(); }
    void HeapGuardDisarm() { HeapGuardDisarmImpl(); }

    // Publishes the context the current thread is running guest code ON, so a VEH dump
    // taken inside the scope names the faulting frame instead of the boot thread's root
    // context (F-046). Restores the previous pairing on scope exit.
    FaultContextScope::FaultContextScope(const PPCContext* ctx, const char* tag)
        : prevCtx_(g_faultCtx), prevTag_(g_faultCtxTag)
    {
        g_faultCtx = ctx;
        g_faultCtxTag = tag;
    }

    FaultContextScope::~FaultContextScope()
    {
        g_faultCtx = prevCtx_;
        g_faultCtxTag = prevTag_;
    }

bool LoadAndPrepare(const std::string& xexPath, uint32_t& entryGuest)
{
    g_moduleBase = (uintptr_t)GetModuleHandle(nullptr);
    if (!AllocateGuestMemory())
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] failed to allocate %llu GiB guest window",
                      (unsigned long long)(GuestMemorySize >> 30));
        BootReportError(lbuf);
        return false;
    }

    mcla::App* app = mcla::GetApp();
    if (app == nullptr)
    {
        BootReportError("[boot] no App instance; cannot wire guest memory");
        return false;
    }
    app->GetGuestMemoryView().SetMemoryBase(g_base, GuestMemorySize);
    app->SetPPCBase(g_base);
    mcla::kernel::GuestMemoryHeap::Instance().Adopt(g_base, GuestMemorySize);
    // Function table lives at guest VA 0x829E0000 = PPC_IMAGE_BASE + PPC_IMAGE_SIZE
    // (src/ppc_context.h:124). Guest o1heap/XTL allocs were landing in that band and
    // zeroing table slots (A5CC0 → null bctrl AV). Reserve that range.
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        constexpr uint32_t kFTableGuest = 0x829E0000u;
        constexpr uint32_t kFTableSize = 0x800000u; // 8 MiB covers ~45k slots
        bool wasCommitted = false;
        if (!mem.AllocVirtualFixed(kFTableGuest, kFTableSize, true, false,
                                   &wasCommitted))
        {
            char lbuf[160];
            std::snprintf(lbuf, sizeof(lbuf),
                          "[boot] WARN: could not reserve func-table "
                          "0x%08X+0x%X (wasCommitted=%d)",
                          kFTableGuest, kFTableSize, (int)wasCommitted);
            BootReportInfo(lbuf);
        }
        else
        {
            // F692-FIX-2 (2026-10-01): THIS LITERAL WAS WRONG -- it read
            // 0x8B9E0000, while the constant this branch reserved one line up is
            // kFTableGuest = 0x829E0000u. Only the message was wrong; the
            // reservation itself went to the right address all along (the WARN
            // arm above prints kFTableGuest and never had the bug). Reported, not
            // silently patched, by src/guest_memory.h:194-197, which measured the
            // row in w688.log and cited the same two lines. Fixed by editing the
            // digits; the format string is otherwise byte-identical.
            BootReportInfo("[boot] reserved func-table guest 0x829E0000 +8MB");
        }
    }

    // TU83 spawn pointer scanner (Lead 1) — runs once after guest memory is adopted
    mcla::native::kernel::ScanGuestMemoryForTU83SpawnPointers();

    // Session 72/73: physical o1heap lives at guest kPhysArenaBeginVa = 0xA0400000 (F-391; it
    // was 0xA0000000 when this comment was written). The instance is 0x230 bytes
    // (64 bins x8 + mask + diagnostics, o1heap.c:133-139) padded to 0x240, then fragments follow.
    // Guest stores here are the heap-corruption vector — the session-72
    // 0x200 window saw nothing, but that run never reached the load stage
    // where the corruption fires. Watch the instance + first fragments.
    mcla::native::RegisterGuestWatchRange(mcla::kernel::kPhysArenaBeginVa,
                                          mcla::kernel::kPhysArenaBeginVa + 0x800u);

    // F-370: the USER heap's o1heap instance lives at guest 0x20000 (Heap::Init binds the arena
    // there), and in w373/w374 its header words become garbage between two consecutive
    // Heap::Alloc calls -- after which every allocation refuses and the 16th guest thread never
    // starts, which is what parks the boot worker on the counting semaphore C501FC00. Session 72
    // watched a 0x200-byte window here and saw nothing, but that run never reached the stage where
    // this fires; re-armed because the frontier now does.
    mcla::native::RegisterGuestWatchRange(mcla::kernel::kUserHeapArenaVa,
                                          mcla::kernel::kUserHeapArenaVa + 0x100u);

    // Session 73: attribute every 0xCDCDCDCD store. Static decode: the guest
    // fills tiny-slab elements with 0xCD on alloc (sub_821DE9D8 tail) — the
    // watch confirms the fill source and catches any OTHER fill site live.
    mcla::native::RegisterGuestWatchValue(0xCDCDCDCDu);

    // F-141: name the producer of the two values that the renderer treats as
    // resource pointers at the current frontier - 0x80010000 (the AUTO draw's
    // CP register 0x81 value, and the object `sub_82184458`'s fixup runs on)
    // and 0x00020037 (`r01DC`, which `sub_82185190` dereferences as a
    // descriptor at the PlaceTexture fatal). Both are 0x80010000-style
    // non-addresses, so the question is who stored them; the store-level report
    // is in gpu_cp.cpp PageWatchOnWrite (RSC-REF-STORE).
    mcla::native::RegisterGuestWatchValue(0x80010000u);
    mcla::native::RegisterGuestWatchValue(0x00020037u);

    // Session 73 probe: poison-param regions (see gpu_cp.cpp PARAM-STORE).
    mcla::native::RegisterGuestWatchRange(0xA0106000u, 0xA0107000u);
    mcla::native::RegisterGuestWatchRange(0xA0197E00u, 0xA0197F00u);

    // F-440 (T41.92): watch the {handler, msgid} registry so PageWatchOnRead can answer whether any
    // guest code ever reads it -- the question F-313 could only answer statically ("no walker
    // materialises the base", which does not exclude a computed one). Read-side probe lives in
    // gpu_cp.cpp as F440-REGREAD.
    // F-872 (2026-10-22): the watch bounds were STALE -- they covered only 0x82102AA0..0x82118000,
    // missing BOTH the first 20 slots (the measured table START is 0x82102A00, first entry
    // {0x82130048, 0x40005703}) and the upper ~40% of the table (measured END 0x82129D38, last
    // entry {0x827CCBC0, 0x40012503}; 20,071 stride-8 slots, 139 of which carry the value
    // 0x40001905). The wall's "the guest never reads the table" was therefore only ever measured
    // on ~78% of the table. This extends the watch to the measured bounds; a F440-REGREAD row
    // inside 0x82118000..0x82129D38 falsifies the static-only reading.
    mcla::native::RegisterGuestWatchRange(0x82102A00u, 0x82129D38u);

    // F-441 (T41.93): the title's boot-worker queue object (words seen at 0x40004B40 qBase and
    // 0x40004D5C = the worker's a1). Store-side probe F441-QUEUE-STORE lives in gpu_cp.cpp.
    mcla::native::RegisterGuestWatchRange(0x40004B40u, 0x40004DC0u);

    // Session 76f: watch the "ui" preload-list global (0x827D7770, 32 bytes)
    // — the boot init reads it before anything fills it (BOOTPATH crash).
    mcla::native::RegisterGuestWatchRange(0x827D7770u, 0x827D7790u);

    // F-397 (T41.74, closes the T41.65/T41.67 question the right way): F-396 showed nothing in
    // src/ hands guest VA 0x20000 to the title, yet `sub_82397060` -- the routine that enters once
    // and never exits (F-395) -- builds a `[p]=p+4` list there (F374-HEAPSTORE, caller
    // `__imp__sub_82397060+0x345`). So the value must arrive through the container it is given:
    // w414's enter record is `obj=828CD064`, whose +8 is the block pointer this routine frees and
    // republishes (ppc_recomp.61.cpp:17759-17774, 17824). Watch those 16 bytes: the store that
    // names itself here IS the hand-off, and its `caller_rva` resolves with
    // tools/host_rva_resolve.py exactly like F-383's did.
    // F-397/F-398: the count that kills the boot worker is `lhz r4,4(r28)` at
    // ppc_recomp.61.cpp:18242, with `r28 = lis(-32115) - 12120` (`:18143-18147`) = **0x828CD0A8** (F-432 §1),
    // so the halfword is **0x828CD0AC**; F-398 printed 0CC/0C8. The container 0x828CD064 the callee
    // receives is the measured `F395-GROW-ENTER obj=`, not F-398's `lis(-32115) - 12188` (= 0x828CD084).
    // Both sit in zero-initialised image data (raw `mcla_pe.bin` at 0x828CD064 is 24 bytes of 0x00), so
    // the count must be written at runtime: watch the pair, a `PAGEWATCH W @ 828CD0AC` row names the
    // producer that should have run; its absence is the answer, and it is clause (b)'s real
    // upstream -- F-397 showed `sub_82397060(0x828CD064, count=0)` cannot terminate (the link loop
    // at loc_82397184 guards only `count-1 == 0`, so r11 starts at 0xFFFFFFFF).
    mcla::native::RegisterGuestWatchRange(0x828CD064u, 0x828CD0D8u);

    // Session 76i: watch the device-registry header (0x82860844: array ptr
    // + count) — catch WHO registers devices and when.
    mcla::native::RegisterGuestWatchRange(0x82860844u, 0x82860850u);

    // Session 76j: entry0's device-vector fields (arr+268..276: holder ptr,
    // device count/cap) and the holder array contents themselves. The crash
    // reads holder[i] = FF00FF00 at the match call; catch the writer live.
    // F-412: 0xA008261C stays where it is ON PURPOSE -- after F-391 it sits in the unowned gap
    // 0xA0030000..0xA0400000 (0 rows in build/w430.log), there is no new address for it, and an
    // armed-but-inert window is not a false hit.
    mcla::native::RegisterGuestWatchRange(0xA008261Cu, 0xA0082624u);
    // F-412: the holder followed the title's XTL heap when F-391 moved the physical pool to
    // kPhysArenaBeginVa: w430 `F389-BANK head=[... A0401010 A0401000 ... A042FFC0]` vs w403
    // `A0001010/A0001000`, i.e. +0x400000. The old 0xA0018028 armed nothing (0 rows in w430).
    mcla::native::RegisterGuestWatchRange(0xA0418028u, 0xA0418030u);

    // F-875 (2026-10-23): the GFx gate chain, measured from raw words.
    //   sub_822C0980 (:0x822C09C0) reads r3 = mem[0x8288B9AC] and requires
    //   mem[r3+72] > 0 SIGNED; the per-frame caller sub_82131008 (:0x82131020)
    //   runs the countdown tick sub_823043F8(obj) ONLY while mem[0x8288E6F0]==0
    //   (:0x82131028 bne over both 0x823043F8 and 0x82304348), and the tick body
    //   (:0x823043F8-0x82304424) is `if((int)obj+68>0){obj+72=obj+68;obj+68=0;}
    //   if((int)obj+72>0)obj+72-=1;` -- so +68 is the REQUEST and +72 the FRAME
    //   COUNTDOWN the gate tests.  w888: all 8 gate rows had +72=0 with no
    //   request posted (F-873). These two watches are static and arm from boot,
    //   so they name (a) whoever installs the gate object into 0x8288B9AC and
    //   (b) whoever flips the tick-inhibit switch 0x8288E6F0 -- the two
    //   producers upstream of the wall. Log-only census, no guest write.
    mcla::native::RegisterGuestWatchRange(0x8288B9ACu, 0x8288B9B0u);
    mcla::native::RegisterGuestWatchRange(0x8288E6F0u, 0x8288E6F4u);

    // F-877 (2026-10-23): the three +68 poster sites in sub_8263EFC0/FA10/C8B0
    // require these conditions:
    //   0x82905384 == 0  (checked at 0x8263F06C/0x8263FD20)
    //   owner+493: bits 0-24=0, bit 25=1  (checked at 0x8263F08C/0x8263FD34)
    //   where owner = mem[0x8288B9AC]+4 (set by sub_82304708 to r31)
    // Static watches on the two global flags:
    mcla::native::RegisterGuestWatchRange(0x82905384u, 0x82905388u);
    mcla::native::RegisterGuestWatchRange(0x8290622Cu, 0x82906230u);

    // F-877: watch the gate object's +4 (owner pointer) and the owner's +493 byte.
    // Gate object at A0487720 (consistent across runs), +4 at A0487724 holds owner.
    // GFx-GATE shows mgr=A050A320, so owner+493 = A050A320 + 0x1ED = A050A50D.
    mcla::native::RegisterGuestWatchRange(0xA0487724u, 0xA0487728u);
    mcla::native::RegisterGuestWatchRange(0xA050A50Du, 0xA050A511u);

    // F-878 (2026-10-24): the UILOAD queue descriptor wall, measured in w898:
    //   F360-REGCB #1 obj=[0x8288B9E8]=A04876A0 [obj+4]=00000100 [obj+88/92]=0
    //   F365-COPIER #1 (20:38:41.004) landed obj+92=821FC008 obj+104=1, obj+88 stayed 0.
    // The copier's skip predicate reads a BYTE at obj+4 (0x00 here), so the copy
    // ran -- but [obj+88] stayed 0 and the pump (sub_821FC008 -> sub_82305870)
    // is UNMEASURED. Watch obj+4 (0x8288B9EC) and obj+88 (0x8288BA40) to name
    // who writes the 0x100 gate and whether obj+88 ever becomes non-zero.
    mcla::native::RegisterGuestWatchRange(0x8288B9ECu, 0x8288B9F0u);
    mcla::native::RegisterGuestWatchRange(0x8288BA40u, 0x8288BA48u);

    // F-880 CORRECTED (2026-10-25): the FlashSema frame counter is 0x8288BBE8
    // (0x82890000 - 17432 borrows into page 0x8288 -- the earlier 0x8289BBE8
    // was an address-arithmetic error; its "FFFF0000" was an unrelated static).
    // sub_82306CB8+0x6b8 INCREMENTS it (lwz/addi 1/stw); the gate-FAIL zeroing
    // (sub_82306A20 epilogue) RESETS it to 0 every failed tick.
    mcla::native::RegisterGuestWatchRange(0x8288BBE8u, 0x8288BBECu);

    // Kernel heaps must exist before any guest import allocates. Skipping this
    // left heap==physicalHeap==nullptr and the first allocation crashed inside
    // o1heapAllocate reading handle->diagnostics.capacity at instance+0x208.
    g_userHeap.Init();

    // F-640: the physical-view alias probe + the model row. After g_userHeap.Init(), so the
    // pool exists and the probe's save/restore lands in real (untouched) pool space; before
    // the XEX is installed and before any guest thread exists, so nothing else can be inside
    // the byte it borrows. It publishes which alias mechanism is in force -- read off the
    // probe, not asserted in source -- and the extents the two reporting sites below now use.
    F640PhysAliasInit();

    // F-784: prove the T44 wipe-watch chain fires on THIS build before any
    // silence in T44-WIPE-STORE can be read as a result (LT rule 19). It writes
    // byte-identical values back through the checked accessors, so the arena's
    // contents are unchanged; its own row says read=N/2 and rows=N (expect 6).
    // After F640 so the physical pool exists; before the XEX is installed, so
    // nothing else is writing while the control runs.
    ::mcla::gpu::T44WipeSelfTest();

    {
        const auto mainDiag = o1heapGetDiagnostics(g_userHeap.heap);
        const auto physDiag = o1heapGetDiagnostics(g_userHeap.physicalHeap);
        MCLA_LOG_INFO("[boot] kernel heaps: main capacity={} physical capacity={}",
                      mainDiag.capacity, physDiag.capacity);
    }

    std::vector<uint8_t> bytes;
    FILE* f = nullptr;
    if (fopen_s(&f, xexPath.c_str(), "rb") != 0 || f == nullptr)
    {
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] cannot open XEX: %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    fseek(f, 0, SEEK_END);
    const long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (len <= 0)
    {
        fclose(f);
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] empty XEX: %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    bytes.resize((size_t)len);
    if (fread(bytes.data(), 1, (size_t)len, f) != (size_t)len)
    {
        fclose(f);
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] short read from %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    fclose(f);

    Image image = Xex2LoadImage(bytes.data(), bytes.size());
    if (image.data == nullptr || image.size == 0)
    {
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] Xex2LoadImage failed for %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] image base 0x%08X size 0x%X entry 0x%08X",
                      (uint32_t)image.base, image.size, (uint32_t)image.entry_point);
        BootReportInfo(lbuf);
    }

    InstallGuestImage(image);
    // One-time cache dump of the decompressed linear image (identity map:
    // file offset = VA - 0x82000000) so IDA/Ghidra raw-byte lookups work
    // without a live boot. Skip when already present.
    {
        std::error_code ec;
        const std::filesystem::path pe = "build/cache/mcla_pe.bin";
        if (!std::filesystem::exists(pe, ec) && image.data != nullptr)
        {
            std::FILE* f = std::fopen(pe.string().c_str(), "wb");
            if (f)
            {
                const size_t n = std::fwrite(image.data.get(), 1, image.size, f);
                std::fclose(f);
                char lbuf[192];
                std::snprintf(lbuf, sizeof(lbuf),
                              "[boot] dumped %zu bytes to build/cache/mcla_pe.bin", n);
                BootReportInfo(lbuf);
            }
        }
    }
    DumpImageRegion(0x827EB900u, 32);
    mcla::trace::ScanForDispatchVtableWords((uint32_t)image.base, image.size);
    const size_t mapped = InstallFunctionTable();
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] installed %zu function-table entries", mapped);
        BootReportInfo(lbuf);
    }

    SeedPreBootSlots();

    // NOTE: the old self-patching blocks here (jmp->ret on the fatal dispatcher
    // and NOP'ing a "bl" in sub_821305B8) scanned HOST x86 code as if it were
    // PPC and wrote into .text. After any relayout they false-positive and
    // corrupt live functions - the kernel-side override of sub_821BD618 in
    // imports.cpp handles the dispatcher correctly now. Do not reintroduce.

    entryGuest = (uint32_t)image.entry_point;
    return true;
}

void Start(uint32_t entryGuest)
{
    {
        std::scoped_lock lock(g_reportMutex);
        g_report = BootReport{};
        g_report.entryGuest = entryGuest;
    }
    g_bootDone.store(false);

    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] starting guest worker thread, entry @0x%08X", entryGuest);
        BootReportInfo(lbuf);
    }

    // Plain CreateThread proc (no std::thread/std::invoke wrapper): clang
    // 19.1.7 ICEs in the X86 assembler for the std::invoke lambda wrapper of a
    // function that contains __try/__except under /EHa. spdlog/fmt calls also
    // must not be made inside a function that holds __try (same ICE) — those paths log
    // through BootReportInfo/BootReportError in boot_log.cpp (note in boot_host.h).
    // Increase worker thread stack size to 8MB to accommodate recompiled PPC functions
    constexpr size_t WorkerStackSize = 8 * 1024 * 1024; // 8MB
    const HANDLE workerHandle = CreateThread(nullptr, WorkerStackSize, BootThreadProc, (LPVOID)(uintptr_t)entryGuest, 0, nullptr);

    // T41.71 / F-393: the sampler below needs a caller-chain walk; it lives at file scope
    // (ParkUnwindCapture) because a function containing __try cannot be defined at block
    // scope and must not be a lambda in this TU (clang ICE, see BootThreadProc's comment).
    // Park sampler (diagnostic): periodically suspend the guest worker, log
    // its host RIP + top stack return addresses resolved to guest VAs.
    // Evidence for boot-progression blockers (ring put frozen post-init,
    // 2026-08-23). Capture-only; runs 600 x 500 ms = 5 min or until boot completes.
    if (workerHandle != nullptr)
    {
        std::thread([workerHandle]() {
            s_parkSamplerTid = GetCurrentThreadId();  // F-412: named so the VEH never parks us
            // F-616: the base is printed here ONCE and every host address the sampler
            // emits is ALSO printed as an RVA against it, because F-616 was eight rounds
            // lost to a reader having to go hunting for `base=` before host_rva_resolve.py
            // would name a rawrip. `wrva` = the suspended WORKER's pc, `srva` = the
            // SAMPLER's own pc (which is inside ReadU32BE/WriteU32BE just as often,
            // which is exactly how rawrip got mistaken for a sampler address).
            const uintptr_t modBase = (uintptr_t)GetModuleHandle(nullptr);
            {
                char lbuf[256];
                std::snprintf(lbuf, sizeof(lbuf),
                              "PARK-SAMPLE base=%llx -- host pcs are RVAs against this; "
                              "resolve with: python tools/host_rva_resolve.py build/mcla.map "
                              "--base %llx <rva>  (map from the SAME build as this log)",
                              (unsigned long long)modBase, (unsigned long long)modBase);
                BootReportInfo(lbuf);
            }
            // F-616: the field dictionary, printed once so no reader has to infer what a
            // token means. This is the guard against the exact failure that cost a day --
            // a field with no name-to-source binding was read as the worker's location.
            {
                char lbuf[1024];
                std::snprintf(lbuf, sizeof(lbuf),
                              "PARK-KEY wrva/srva=host module RVA of the SUSPENDED WORKER pc / "
                              "of the SAMPLER's own pc | live:* = read from the suspended thread's "
                              "real CONTEXT (trustworthy for where the worker is NOW) | "
                              "mirror:* = read from g_bootWorkerCtx, the LAST guest frame that "
                              "published a context (STALE by construction once the guest stops "
                              "calling; NEVER a location, NEVER a dwell %%) | sw*=raw top-of-stack "
                              "words of the worker, which are DATA not return addresses "
                              "(boot_host.cpp:1819-1822) | dev/cur/vbl/flg/ud*=guest MEMORY read BY "
                              "THE SAMPLER at print time, not worker registers (cur = ring write "
                              "pointer, the second liveness witness) | polls=all samples, rows=only "
                              "printed ones, rows-moved/-frozen = did ANY live field change between "
                              "consecutive rows (a spin loop repeats its rip legitimately) | "
                              "blind=0 means ParkSamplerSelfTest saw a change it made; blind=1 "
                              "means every PARK-* row below is a lie");
                BootReportInfo(lbuf);
            }
            // F-616: selftest BEFORE the first sample, so `blind=` on row #1 is already
            // meaningful. Rule: selftests MUST be 1, else this probe is blind (F388/F374).
            uint32_t probeRva = 0, probeFrames = 0, probeDistinct = 0;
            const uint32_t selftest =
                ParkSamplerSelfTest(modBase, &probeRva, &probeFrames, &probeDistinct);
            s_parkBlind.store(selftest == 0 ? 1u : 0u, std::memory_order_relaxed);
            {
                char lbuf[256];
                std::snprintf(lbuf, sizeof(lbuf),
                              "PARK-SELFTEST ok=%u (MUST be 1) distinct-rsp-seen=%u/3"
                              " change-visible-to-suspend=%s probe-rva=%x probe-unwind-frames=%u",
                              selftest, probeDistinct, selftest ? "yes" : "NO-BLIND", probeRva,
                              probeFrames);
                BootReportInfo(lbuf);
            }
            // F-601: name the sampled worker thread once, so per-thread
            // censuses (XTLIMPORT tid=, WAIT tid=) can be joined to these
            // parks: same tid = the parked boot worker is the churner.
            {
                char lbuf[128];
                std::snprintf(lbuf, sizeof(lbuf), "PARK-SAMPLE worker-tid=%08X",
                              (uint32_t)GetThreadId(workerHandle));
                BootReportInfo(lbuf);
            }
            uint64_t lastRip = 0;
            // F-616: per-PC sample COUNTS over 0x10-byte host-RVA buckets, from the
            // LIVE worker rip only. Deliberately counts and NEVER a percentage: this
            // loop polls every 500 ms, so a count is a count of POLLS, not of wall time.
            // "X% of wall time at address Y" is not a quantity this sampler can measure
            // even when every field it reads is live -- and the one time such a number
            // was published (F-616) every field behind it was stale. So the percentage
            // is gone from the tool, not just relabelled.
            std::unordered_map<uint32_t, uint32_t> hist;
            uint32_t samples = 0;
            // F-616: the sound replacement for the dwell percentage -- did the worker's
            // LIVE state move between consecutive samples? `frozen` counts samples where
            // NONE of rip/rsp/rp-write-pointer changed, which is a fact about the worker
            // rather than about a field that stopped being written. A spin loop repeats
            // its rip legitimately (w654: 40/203 rows share rawrip ...0ad), so rip alone
            // would read as "frozen" while the guest is demonstrably progressing.
            uint32_t frozen = 0, movedRows = 0, printed = 0;
            // prevRip is separate from lastRip on purpose: lastRip drives the print gate
            // and is set to tc.Rip before the comparison below, so reusing it would make
            // "rip changed" permanently false. prevRip is the liveness witness only.
            uint64_t prevRip = 0, lastRsp = 0, lastCur = 0;
            // F-616: mirror freshness. g_bootWorkerCtx is published by whichever guest
            // function last stored its frame (boot_host.cpp:1367) and NEVER cleared on
            // return, so it is a LAST-REGISTERED value: printing it without a freshness
            // stamp is what let a frozen lr be reported for 97 s as a live location.
            // age_ms is measured with GetTickCount64 -- no allocation, 15 ms resolution,
            // and the threshold (1 s) is two orders of magnitude above that.
            uint64_t mirrorChangeTick = GetTickCount64();
            uint64_t lastMirrorTup = 0;
            constexpr uint64_t kMirrorStaleMs = 1000;
            // T41.5a: the old bound was 120 x 500ms = 60s, and a line printed
            // ONLY when the host RIP changed -- so a thread parked in one place
            // for the rest of the boot produced total silence that read like
            // "not stalled" (rule 19). Run for the whole soak and heartbeat
            // every 4th sample (2s) even when the RIP is unchanged.
            for (int i = 0; i < 600 && !g_bootDone.load(); ++i)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                CONTEXT tc;
                std::memset(&tc, 0, sizeof(tc));
                tc.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
                if (SuspendThread(workerHandle) == (DWORD)-1)
                    break;
                // F-412: from here to Release() the worker is suspended on THIS thread's count;
                // the guard resumes it on every path out (the __finally that ParkUnwindCapture's
                // early `return`s and any escaping exception did not have).
                WorkerResumeGuard resumeGuard(workerHandle);
                const bool ok = GetThreadContext(workerHandle, &tc) != 0;
                uint64_t rets[3] = {0, 0, 0};
                if (ok)
                {
                    for (size_t k = 0; k < 3; ++k)
                    {
                        const void* sp = (const void*)(tc.Rsp + 8 * (k + 1));
                        if (!IsBadReadPtr(sp, sizeof(uint64_t)))
                            rets[k] = *(const uint64_t*)sp;
                    }
                    ++samples;
                    if (g_moduleBase != 0 && tc.Rip >= g_moduleBase)
                        ++hist[uint32_t((tc.Rip - g_moduleBase) >> 4)];
                }
                // T41.71: walk the caller chain WHILE SUSPENDED (the unwind reads this
                // thread's stack); printing happens after ResumeThread.
                uint64_t urva[8] = {0, 0, 0, 0, 0, 0, 0, 0};
                uint64_t ownerRva = 0, ownerOff = 0;
                uint32_t nU = 0;
                if (ok)
                    ParkUnwindCapture(tc, urva, &nU, &ownerRva, &ownerOff);
                resumeGuard.Release();  // F-412: was a bare ResumeThread; dtor covers the rest
                // T41.5a: print when the host RIP moves AND as a 2 s heartbeat,
                // so "the boot worker has not moved for 60 s" becomes a visible
                // repeated line instead of silence. Repeated identical rawrip
                // values are the signal, not noise.
                const bool ripChanged = ok && tc.Rip != lastRip;
                if (!ripChanged && !(ok && i % 4 == 3))
                    continue;
                if (ripChanged)
                    lastRip = tc.Rip;
                // Guest driver state via the pinned device chain
                // **(u32**)0x82000864 (gpu_device.cpp overrides use it), plus
                // VdSetGraphicsInterruptCallback userData object. The old
                // pollerCtx/D0 probe (0x82839254) read a DIFFERENT object —
                // retired per session-5.
                uint32_t dev = 0, slot = 0, cursor = 0, vbl = 0, flg = 0, ud = 0, ud1 = 0, ud8 = 0;
                {
                    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
                    if (mem.ReadU32BE(0x82000864, &slot) && slot != 0)
                        (void)mem.ReadU32BE(slot, &dev);
                    if (dev != 0)
                    {
                        (void)mem.ReadU32BE(dev + 0x30, &cursor);
                        (void)mem.ReadU32BE(dev + 21648, &vbl);
                        (void)mem.ReadU32BE(dev + 10942, &flg);
                    }
                    // VdSetGraphicsInterruptCallback userData: probe BOTH the
                    // uncached alias (guest-chosen 0xA0003080) and its
                    // would-be cached slot (0x80003080). System-wide A/C
                    // convergence was reverted (e9c9445: title needs >512 MB
                    // physical; identity-safe capacity insufficient), so
                    // alias resolution stays per-probe until evidence
                    // justifies more.
                    (void)mem.ReadU32BE(0xA0003080, &ud);
                    if (ud != 0)
                        (void)mem.ReadU32BE(ud, &ud1);
                    (void)mem.ReadU32BE(0x80003080, &ud8);
                }
                // F-616: the mirror, and the ONLY thing the pre-F-616 line called "the
                // live guest state of the parked boot worker". It is not live. T41.5b
                // already moved it off thread_local g_faultCtx (which was always null on
                // the sampler thread, so every field printed 0); that fixed the WRONG-TLS
                // bug and left a new one, because g_bootWorkerCtx is a plain pointer store
                // at boot_host.cpp:1367 and is never cleared on guest return. What it
                // holds is the frame of whichever guest function last wrote a context --
                // a LAST-REGISTERED value, and after that function stops being called it
                // is frozen forever. Measured on w654: F598-C6658 (the sub_821C6658
                // realloc, whose call site 0x821C6DC4 makes lr=821C6DC8 a live value)
                // fired 16 times, last at 18:13:19.977; the sampler then reported
                // lr=821C6DC8 on 132/203 rows through 18:14:57.694, i.e. for 97.3 s after
                // the call it names had stopped happening, and r3=r4=00000000 on 78 of
                // them. Every field derived from bwctx is therefore printed under
                // `mirror:` and carries a freshness verdict computed below.
                const PPCContext* bwctx =
                    g_bootWorkerCtx.load(std::memory_order_relaxed);
                uint32_t gr3 = 0, gr4 = 0, gr13 = 0, glr = 0;
                uint32_t swM8 = 0, swM16 = 0, swM24 = 0, tls0 = 0;
                uint32_t msp = 0;
                const char* r13tag = nullptr;
                if (bwctx != nullptr)
                {
                    gr3 = bwctx->r3.u32;
                    gr4 = bwctx->r4.u32;
                    gr13 = bwctx->r13.u32; // TLS/PCR base
                    glr = (uint32_t)bwctx->lr;
                    msp = bwctx->r1.u32;
                    // F-616 / F-609: name WHICH host thread the alias r13 belongs to.
                    // Every non-ExCreateThread host context hard-aliases r13=0x8F200000
                    // (boot_host.h:111-124), so a bare 0x8F200000 cannot distinguish the
                    // boot worker from the ~20 synthesized contexts in gpu_device.cpp --
                    // which is the same class of unattributable number that cost F-616 a
                    // day. Read-only; a miss prints "-" and changes nothing.
                    // F-637: MEASURED, this call CANNOT be the F388-PHYSGUARD tripper. It was
                    // nominated as one (a sampler that reads a guarded page is the classic way to
                    // trip a page you are only printing), and it is innocent: LookupGuestThreadBlockTag
                    // is `lock_guard + unordered_map::find` over g_f609Tags (:1202) and dereferences no
                    // guest VA at all, so it cannot reach kPhysHdrVa. The trip is attributed by
                    // w657.log:980-995, whose backtrace is self-referential -- frames 0/1/5 are
                    // PhysGuardHandle+0x2b6 and BootWorker::<lambda_3>+0x395/+0x770, i.e. the VEH
                    // itself, and frame 9 is rva=0x24DC5D = ResolveKernelObjectSafe+0x5d, the SAME rva
                    // as the C0000005 616 ms later. The read of phys+0 came from that resolver. The
                    // invariant the sampler does owe, and now does not have to, is that an
                    // instrumentation thread must not be able to change guest-visible page
                    // permissions as a side effect of printing a field; with F637-GUARDREPAIR a trip
                    // from ANY thread is now discharged by the next arm instead of stranding the guard.
                    r13tag = LookupGuestThreadBlockTag(gr13);
                    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
                    if (gr13 != 0)
                        (void)mem.ReadU32BE(gr13 + 0x0, &tls0);
                    const uint32_t sp = msp;
                    if (sp != 0)
                    {
                        (void)mem.ReadU32BE(sp - 8, &swM8);   // saved lr slot
                        (void)mem.ReadU32BE(sp - 16, &swM16); // saved r31 slot
                        (void)mem.ReadU32BE(sp - 24, &swM24); // saved r30 slot
                    }
                }
                // F-616: freshness verdict for the mirror, from a cheap monotonic stamp.
                // Any change to the published tuple (lr/r3/r4/r13/sp) restarts the clock;
                // if none has happened for kMirrorStaleMs the mirror is provably not
                // tracking a running thread, and the line says so in its first tokens.
                const uint64_t nowTick = GetTickCount64();
                const uint64_t mirrorTup = ((uint64_t)glr << 32) ^ ((uint64_t)gr3 << 8) ^
                                           ((uint64_t)gr4 << 20) ^ ((uint64_t)gr13 << 4) ^ msp;
                if (mirrorTup != lastMirrorTup)
                {
                    lastMirrorTup = mirrorTup;
                    mirrorChangeTick = nowTick;
                }
                const uint64_t mirrorAgeMs = nowTick - mirrorChangeTick;
                const bool mirrorStale = (bwctx == nullptr) || (mirrorAgeMs > kMirrorStaleMs);
                // F-616: did the WORKER move, from live fields only. rip repeats
                // legitimately in a spin loop, so the ring write pointer (cursor, the same
                // device+0x30 the guest bumps) is the second, independent witness: w654 had
                // 40 rows sharing one rawrip while cur changed on every one of them.
                uint32_t moved = 0;
                if (printed > 0)
                {
                    if (tc.Rip != prevRip) ++moved;
                    if (tc.Rsp != lastRsp) ++moved;
                    if (cursor != lastCur) ++moved;
                    if (moved == 0) ++frozen; else ++movedRows;
                }
                ++printed;
                prevRip = tc.Rip;
                lastRsp = tc.Rsp;
                lastCur = cursor;
                {
                    // F-616: the WORKER's own pc and the SAMPLER's own pc, both as module
                    // RVAs so host_rva_resolve.py names them without a `base=` hunt. The
                    // audit that produced the false 65% resolved `rawrip`, got
                    // ReadU32BE/WriteU32BE, and concluded it was reading the sampler's own
                    // code -- because the sampler DOES call those (the dev/cur probe below
                    // and the mirror reads). It is not: PARK-UNWIND #1 in w654 walks
                    // 63e80d -> 63eb46 -> __xstart+0x55e -> BootWorker+0x1d9 ->
                    // BootThreadProc+0x14, which only the suspended worker can unwind to.
                    // Printing both on one line makes that argument checkable in place.
                    const uintptr_t sRip = (uintptr_t)_ReturnAddress();
                    const unsigned long long wrva =
                        (modBase != 0 && tc.Rip >= modBase)
                            ? (unsigned long long)(tc.Rip - modBase)
                            : (unsigned long long)tc.Rip;
                    const unsigned long long srva =
                        (modBase != 0 && sRip >= modBase)
                            ? (unsigned long long)(sRip - modBase)
                            : (unsigned long long)sRip;
                    char lbuf[1536];
                    std::snprintf(
                        lbuf, sizeof(lbuf),
                        "PARK-SAMPLE mirror=%s(age_ms=%llu) blind=%u polls=%u rows=%u rows-moved=%u"
                        " | live:{rsp=%llx rip-host=%llx wrva=%llx srva=%llx(sampler) moved=%u}"
                        " live:sw0=%llx sw1=%llx sw2=%llx(stack-top-words,NOT-ret-addr)"
                        " | dev=%08X cur=%08X vbl=%u flg=%u ud=%08X ud1=%08X ud8=%08X"
                        " | mirror:STALE/LAST-REGISTERED lr=%08X r3=%08X r4=%08X"
                        " r13=%08X tag=%s tls0=%08X sp=%08X [r1-8]=%08X [r1-16]=%08X [r1-24]=%08X",
                        mirrorStale ? "STALE" : "fresh", (unsigned long long)mirrorAgeMs,
                        s_parkBlind.load(std::memory_order_relaxed), samples, printed, movedRows,
                        (unsigned long long)tc.Rsp, (unsigned long long)tc.Rip, wrva, srva, moved,
                        (unsigned long long)rets[0], (unsigned long long)rets[1],
                        (unsigned long long)rets[2], dev, cursor, vbl, flg, ud, ud1, ud8,
                        glr, gr3, gr4, gr13, r13tag ? r13tag : "-", tls0, msp, swM8, swM16, swM24);
                    BootReportInfo(lbuf);
                }
                // T41.71 / F-616: the caller chain behind the WORKER's pc. This one IS
                // live -- it walks the suspended thread's stack, and the w654 frame lists
                // terminate in BootWorker/BootThreadProc, so it can be trusted for "where
                // is the worker". RVAs, not names -- this build has no PDB and
                // NearestFunctionName is what produced the 94 KB-off `nf` artifact (which
                // is why `nf=` is no longer printed on PARK-SAMPLE at all: a name that is
                // wrong by 94 KB is worse than an RVA the reader can resolve).
                // Resolve offline: python tools/host_rva_resolve.py build/mcla.map --base
                // <base from PARK-SAMPLE base=> <owner> <frame0> <frame1> ...  A frame whose
                // symbol is __imp__sub_82XXXXXX / sub_82XXXXXX names the GUEST function.
                {
                    static uint32_t s_pu = 0;
                    const uint32_t pu = ++s_pu;
                    // Printed for EVERY sample that got here, including nU=0/1: `frames=1`
                    // means the lookup found the function but the first unwind failed, and
                    // `frames=0` means no table entry for the RIP at all. Both are results
                    // (F-089 s6: a capped or conditional printer turns a null into silence).
                    if (pu <= 12 || (pu % 40) == 0)
                    {
                        char ubuf[320];
                        size_t uoff = (size_t)std::snprintf(
                            ubuf, sizeof(ubuf),
                            "PARK-UNWIND #%u blind=%u source=live-suspended-worker frames=%u owner=%llx+%llx rip=[",
                            pu, s_parkBlind.load(std::memory_order_relaxed), nU,
                            (unsigned long long)ownerRva, (unsigned long long)ownerOff);
                        for (uint32_t f = 0; f < nU && uoff + 24 < sizeof(ubuf); ++f)
                            uoff += (size_t)std::snprintf(
                                ubuf + uoff, sizeof(ubuf) - uoff, "%s%llx", f ? "," : "",
                                (unsigned long long)urva[f]);
                        std::snprintf(ubuf + uoff, sizeof(ubuf) - uoff, "]");
                        BootReportInfo(ubuf);
                    }
                }
                // T41.5b / F-616: the guest frame chain. Renamed PARK-MIRROR-STACK because
                // every word of it is read through bwctx->r1, i.e. out of the FROZEN mirror
                // frame -- it describes a stack the guest has since left, not the worker's.
                // The generated prologues keep the back-chain at [r1] and the caller's
                // return address at [r1-8] (stw lr,-8(r1)); the stack grows down, so each
                // caller frame sits at a HIGHER address. Each fNN= is resolved offline
                // against generated/ppc_xenon/ppc_func_mapping.cpp. It is still worth
                // printing -- it names the guest call chain as of the last context publish
                // -- and the mirror verdict rides along so it cannot be read as current.
                if (bwctx != nullptr)
                {
                    auto& mem2 = mcla::kernel::GuestMemoryHeap::Instance();
                    char sbuf[512];
                    size_t so = (size_t)std::snprintf(
                        sbuf, sizeof(sbuf),
                        "PARK-MIRROR-STACK mirror=%s(age_ms=%llu) blind=%u sp=%08X lr=%08X:",
                        mirrorStale ? "STALE" : "fresh",
                        (unsigned long long)mirrorAgeMs,
                        s_parkBlind.load(std::memory_order_relaxed), msp, glr);
                    uint32_t sp = msp;
                    for (int fr = 0; fr < 8 && sp >= 0x80000000u &&
                                    sp < 0x90000000u;
                         ++fr)
                    {
                        uint32_t back = 0, ret = 0;
                        if (!mem2.ReadU32BE(sp, &back) ||
                            !mem2.ReadU32BE(sp - 8, &ret))
                            break;
                        const int w = std::snprintf(sbuf + so, sizeof(sbuf) - so,
                                                    " f%d=%08X", fr, ret);
                        if (w < 0)
                            break;
                        so += (size_t)w;
                        if (back <= sp || back >= 0x90000000u ||
                            back < 0x80000000u)
                            break;
                        sp = back;
                    }
                    BootReportInfo(sbuf);
                }
            }
            {
                // F-616: COUNTS, never percentages, and never a number derived from the
                // mirror. Two reasons, both measured:
                //   (a) provenance -- the histogram is built from tc.Rip, the LIVE worker
                //       pc, so it is sound; but the buckets sit 0x10 apart and 40 of
                //       w654's 203 rows share one rip, which reads like a dwell fact and is
                //       not one.
                //   (b) units -- this loop POLLS every 500 ms. A count is a count of
                //       polls, not of wall time. "65% of wall time at X" is not a
                //       quantity this instrument can produce, and the one time it was
                //       published (F-616) every field behind it had been frozen for 97 s.
                // The sound worker-state statistic is `frozen`/`moved` above: did any LIVE
                // field (rip, rsp, ring write pointer) change between consecutive samples.
                char lbuf[2048];
                size_t off = (size_t)std::snprintf(
                    lbuf, sizeof(lbuf),
                    "PARK-HIST source=live-worker-rip counts-not-pct blind=%u polls=%u rows=%u"
                    " rows-moved=%u rows-frozen=%u buckets=%zu top:",
                    s_parkBlind.load(std::memory_order_relaxed), samples, printed, movedRows,
                    frozen, hist.size());
                std::vector<std::pair<uint32_t, uint32_t>> top(hist.begin(), hist.end());
                std::sort(top.begin(), top.end(), [](auto& a, auto& b) { return a.second > b.second; });
                for (size_t k = 0; k < top.size() && k < 16 && off < sizeof(lbuf); ++k)
                {
                    const int w = std::snprintf(lbuf + off, sizeof(lbuf) - off, " %06x=%u",
                                                (unsigned)(top[k].first * 16), top[k].second);
                    if (w < 0)
                        break;
                    off += (size_t)w;
                }
                BootReportInfo(lbuf);
            }
        }).detach();
    }

    constexpr int WatchdogMs = 300000; // 5 minutes
    for (int i = 0; i < WatchdogMs && !g_bootDone.load(); i += 100)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!g_bootDone.load())
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] watchdog fired after %d ms; boot still running (parked in main loop is expected)",
                      WatchdogMs);
        BootReportInfo(lbuf);
        CONTEXT tc;
        std::memset(&tc, 0, sizeof(tc));
        tc.ContextFlags = CONTEXT_CONTROL;
        if (workerHandle != nullptr && SuspendThread(workerHandle) != (DWORD)-1)
        {
            if (GetThreadContext(workerHandle, &tc))
            {
                const uintptr_t rip = (uintptr_t)tc.Rip;
                std::snprintf(lbuf, sizeof(lbuf), "[boot] worker suspended; RIP=0x%llX in %s",
                              (unsigned long long)rip, NearestFunctionName(rip));
                BootReportInfo(lbuf);
            }
            // Try to seed GPU context state field (ctx+0xd0 = 1) so Function_824E37E0 proceeds.
            const uint32_t gpuCtxPtrAddr = 0x82839254;
            const uint32_t gpuCtxPtr = ReadU32BE(g_base, gpuCtxPtrAddr);
            if (gpuCtxPtr != 0 && gpuCtxPtr < 0x90000000)
            {
                const uint32_t stateAddr = gpuCtxPtr + 0xD0;
                WriteU32BE(g_base, stateAddr, 1);
                std::snprintf(lbuf, sizeof(lbuf), "[boot] seeded GPU context state @0x%08X+0xD0 = 1", gpuCtxPtr);
                BootReportInfo(lbuf);
            }
            ResumeThread(workerHandle);
        }
    }
    else if (workerHandle != nullptr)
    {
        WaitForSingleObject(workerHandle, INFINITE);
        CloseHandle(workerHandle);
        LogReport();
    }
    else
    {
        LogReport();
    }
}

const BootReport& GetReport()
{
    return g_report;
}

uint32_t GetBootWorkerReg(unsigned regIndex)
{
    if (!g_faultCtx) return 0;
    // Only registers guaranteed to exist in PPCContext are returned
    // directly. Non-volatile registers (r14-r31) may be compiled out
    // when PPC_CONFIG_NON_VOLATILE_AS_LOCAL is set.
    switch (regIndex) {
    case 1:  return g_faultCtx->r1.u32;
    case 3:  return g_faultCtx->r3.u32;
    case 4:  return g_faultCtx->r4.u32;
    case 5:  return g_faultCtx->r5.u32;
    case 6:  return g_faultCtx->r6.u32;
    case 7:  return g_faultCtx->r7.u32;
    case 8:  return g_faultCtx->r8.u32;
    case 9:  return g_faultCtx->r9.u32;
    case 10: return g_faultCtx->r10.u32;
    case 13: return g_faultCtx->r13.u32;
    default: return 0;
    }
}

// F-370: counting-semaphore registry (see the declaration in boot_host.h). Deliberately
// lock-free and fixed-size: fmt must not be built inside a function holding __try (the clang ICE note in
// boot_host.h), and a boot creates far fewer than the cap. Creation already logs in
// imports.cpp (SEMA-CREATE), so this only has to remember which handles had permits.
namespace {
constexpr uint32_t kCountingSemaCap = 64;
uint32_t g_countingSema[kCountingSemaCap] = {};
uint32_t g_countingSemaInit[kCountingSemaCap] = {};
// F-412: atomic -- `++g_countingSemaHits[i]` from two concurrent NtCreateSemaphore hooks was a
// lost update (read-modify-write on a plain uint32_t).
std::atomic<uint32_t> g_countingSemaHits[kCountingSemaCap] = {};
std::atomic<uint32_t> g_countingSemaN{0};
} // namespace

void RegisterCountingSema(uint32_t handle, uint32_t initCount)
{
    if (handle == 0 || initCount == 0)
        return;
    // F-412: the slot is RESERVED with a CAS, not read-then-store. The old
    // `i = load(N); ...; store(N, i+1)` let two concurrent NtCreateSemaphore hooks read the same
    // i, overwrite each other's slot and drop a handle. A reader may now see index i for the few
    // instructions before the slot store lands, but a zero slot can never equal a handle (0 is
    // rejected above), so that window only delays recognition.
    uint32_t i = g_countingSemaN.load(std::memory_order_relaxed);
    for (;;)
    {
        if (i >= kCountingSemaCap)
            return;
        if (g_countingSemaN.compare_exchange_strong(i, i + 1, std::memory_order_acq_rel,
                                                    std::memory_order_relaxed))
            break;
        // CAS failed: i now holds the current count -- retry with it.
    }
    g_countingSema[i] = handle;
    g_countingSemaInit[i] = initCount;
}

bool IsCountingSema(uint32_t handle, uint32_t *initOut)
{
    const uint32_t n = g_countingSemaN.load(std::memory_order_acquire);
    for (uint32_t i = 0; i < n; ++i)
    {
        if (g_countingSema[i] == handle)
        {
            if (initOut != nullptr)
                *initOut = g_countingSemaInit[i];
            return true;
        }
    }
    return false;
}

bool CountingSemaAllow(uint32_t handle)
{
    const uint32_t n = g_countingSemaN.load(std::memory_order_acquire);
    for (uint32_t i = 0; i < n; ++i)
    {
        if (g_countingSema[i] == handle)
        {
            // F-412: atomic fetch_add -- two hooks could increment the same slot concurrently,
            // which the old plain `++` lost.
            const uint32_t k =
                g_countingSemaHits[i].fetch_add(1, std::memory_order_relaxed) + 1;
            return k <= 24 || (k % 200) == 0;
        }
    }
    return false;
}

// ============================================================================
// F-640: the physical-view translation, published so the sites that need it can
// adopt it in one line. The map itself lives in the F-640 block at the top of this
// TU; these are the entry points, the counters, and the rows.
// ============================================================================

namespace {
// F-640: which call sites have adopted the translation. Bounded, and published in
// the init row, because `dropped == 0` only means "no write was lost" once at least
// one writer is actually routing through here.
constexpr size_t kF640WriterCap = 8;
const char* g_f640Writers[kF640WriterCap] = {};
std::mutex g_f640WriterMtx;
} // namespace

void F640RegisterWriterImpl(const char* site)
{
    if (site == nullptr)
        return;
    std::lock_guard<std::mutex> lock(g_f640WriterMtx);
    for (size_t i = 0; i < kF640WriterCap; ++i)
    {
        if (g_f640Writers[i] == nullptr)
        {
            g_f640Writers[i] = site;
            g_f640.adopted.fetch_add(1, std::memory_order_relaxed);
            return;
        }
        if (std::strcmp(g_f640Writers[i], site) == 0)
            return; // already registered; a per-boot re-registration is not a new site
    }
    // Full: count it anyway so the row can never under-report the number of adopters.
    g_f640.adopted.fetch_add(1, std::memory_order_relaxed);
}

void RegisterPhysAliasWriter(const char* site)
{
    F640RegisterWriterImpl(site);
}

const char* PhysViewName(uint32_t viewVa)
{
    switch (F640ClassifyView(viewVa))
    {
    case F640View::kA64K:  return "A64K";
    case F640View::kC16M:  return "C16M";
    case F640View::kE4K:   return "E4K";
    case F640View::kNone:  break;
    }
    return "-";
}

void LogPhysAliasRow(const char* reason)
{
    const uint64_t calls = g_f640.calls.load(std::memory_order_relaxed);
    const uint64_t notA = g_f640.notAView.load(std::memory_order_relaxed);
    const uint64_t tr = g_f640.translated.load(std::memory_order_relaxed);
    const uint64_t dr = g_f640.dropped.load(std::memory_order_relaxed);
    const uint64_t lr = g_f640.lowRegion.load(std::memory_order_relaxed);
    const uint64_t ad = (uint64_t)g_f640.adopted.load(std::memory_order_relaxed);
    MCLA_LOG_WARN("F640-PHYSALIAS-SUM reason={} calls={} not_a_view={} translated={} dropped={} "
                  "low_region={} adopted_sites={} zero_is_measured={} sum_ok={}",
                  (reason != nullptr ? reason : "-"), calls, notA, tr, dr, lr, ad,
                  (ad > 0 ? 1 : 0),
                  ((notA + tr + dr == calls) ? 1 : 0));
}

void F640CountAndLog(uint32_t viewVa, F640Map map, uint32_t poolVa)
{
    const uint64_t call = g_f640.calls.fetch_add(1, std::memory_order_relaxed) + 1;
    switch (map)
    {
    case F640Map::kMapped:
    {
        const uint64_t n = g_f640.translated.fetch_add(1, std::memory_order_relaxed) + 1;
        // F-640/B2: the low-region census. The LOW REGION is console physical
        // [0, 4 MiB); an access that lands there is the guest addressing the console's
        // page 0, which before this change had no byte at all.
        if ((uint64_t)poolVa < (uint64_t)mcla::boot::kPhysLowRegionEndVa)
            g_f640.lowRegion.fetch_add(1, std::memory_order_relaxed);
        if (F640Allow(n))
            MCLA_LOG_WARN("F640-CVIEW-TRANSLATE #{} view={} view_va={:08X} pool_va={:08X} "
                          "pa={:08X} translated_total={}",
                          n, PhysViewName(viewVa), viewVa, poolVa,
                          (uint32_t)((uint64_t)viewVa -
                                     (uint64_t)kF640Views[(uint32_t)F640ClassifyView(viewVa) - 1].base),
                          n);
        return;
    }
    case F640Map::kNoPoolByte:
    {
        // F-640: THE ROW THAT MUST READ ZERO. Its own line, its own budget, and it prints
        // the attempt number it belongs to -- a `dropped=0` with no attempt index beside it
        // is indistinguishable from "nothing was ever routed here" (F-057(6)).
        const uint64_t n = g_f640.dropped.fetch_add(1, std::memory_order_relaxed) + 1;
        const uint64_t seq = g_f640.dropSeq.fetch_add(1, std::memory_order_relaxed) + 1;
        if (F640Allow(n))
            MCLA_LOG_ERROR("F640-CVIEW-DROPPED #{} attempt={} view={} view_va={:08X} "
                           "pa={:08X} pool_va=NONE reason=NO_POOL_BYTE adopted_sites={} "
                           "NOTE=this_access_is_NOT_reaching_the_pool",
                           n, call, PhysViewName(viewVa), viewVa,
                           (uint32_t)((uint64_t)viewVa -
                                      (uint64_t)kF640Views[(uint32_t)F640ClassifyView(viewVa) - 1].base),
                           (uint64_t)g_f640.adopted.load(std::memory_order_relaxed));
        (void)seq;
        return;
    }
    case F640Map::kNotAView:
        g_f640.notAView.fetch_add(1, std::memory_order_relaxed);
        return;
    }
}

PhysViewResult TranslatePhysViewToPoolVa(uint32_t viewVa, uint32_t* outPoolVa)
{
    uint32_t poolVa = 0;
    const F640Map map = F640MapViewToPool(viewVa, &poolVa);
    F640CountAndLog(viewVa, map, poolVa);
    switch (map)
    {
    case F640Map::kMapped:
        if (outPoolVa != nullptr)
            *outPoolVa = poolVa;
        return PhysViewResult::kMapped;
    case F640Map::kNoPoolByte:
        if (outPoolVa != nullptr)
            *outPoolVa = 0;  // never leave a stale value beside a refusal
        return PhysViewResult::kNoPoolByte;
    case F640Map::kNotAView:
        break;
    }
    if (outPoolVa != nullptr)
        *outPoolVa = 0;
    return PhysViewResult::kNotAView;
}

// F-640: THE ALIAS PROBE. One byte, written into the pool, read back through all three
// views, then restored and re-read. It is the only test that can decide the question,
// because `Translate` is arithmetic (memory.cpp:285-297): comparing host pointers would only
// re-derive `base + va` and would "prove" aliasing that is not there.
//
// The byte is the pool byte for a physical address in the MIDDLE of the console's window,
// not the pool's last byte: the pool's last byte presents as physical 0x203FFFFF, which is
// ABOVE the console's 0x20000000 limit, and `0xE0000000 + 0x203FFFFF` is 0x1003FFFFF -- past
// the end of the 4 GiB window, so the E-view read would have wrapped. That is why the probe
// address is derived from the console's size, not from the pool's end.
//
// It is free space and stays that way: o1heap grows from the arena base, this runs after
// g_userHeap.Init() but before the XEX is installed and before any guest thread exists, and
// the original value is restored and re-read either way -- reported as `canary_restored=`, so
// a soak can confirm the probe left no mark.
void F640PhysAliasInit()
{
    const uint64_t pa = F640PoolPhysBase() +
                        ((uint64_t)mcla::kernel::PhysArenaSizeBytes() / 2u);
    const uint8_t kCanary = 0xA5u;

    uint32_t poolVa = 0;
    const F640Map self = F640MapViewToPool(kF640Views[0].base + (uint32_t)pa, &poolVa);
    uint8_t before = 0, after = 0, seen[3] = {0, 0, 0};
    // The CHECKED accessors, and the same instance heap.cpp:974-980 uses for its own needle
    // reads: GuestMemoryHeap::ReadBytes/WriteBytes are IsValid-checked and __try-guarded.
    // `g_memory` is the flat base holder and has no such members.
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const bool gotBefore = (self == F640Map::kMapped) && mem.ReadBytes(poolVa, &before, 1);
    const bool wrote = (self == F640Map::kMapped) && mem.WriteBytes(poolVa, &kCanary, 1);
    if (wrote)
    {
        for (uint32_t i = 0; i < 3; ++i)
            (void)mem.ReadBytes(kF640Views[i].base + (uint32_t)pa, &seen[i], 1);
    }
    if (self == F640Map::kMapped)
        (void)mem.WriteBytes(poolVa, &before, 1);
    const bool gotAfter = (self == F640Map::kMapped) && mem.ReadBytes(poolVa, &after, 1);

    uint32_t shared = 0;
    for (uint32_t i = 0; i < 3; ++i)
        if (seen[i] == kCanary)
            ++shared;
    // The mechanism in force is READ OFF the probe, not asserted in source: 3 shared views
    // would mean the window really is three views of one pool; 0 means the flat window, and
    // the only mechanism left is per-access translation. A PARTIAL result would mean the
    // window is something this file's model does not describe, and is reported as such
    // instead of being rounded to one of the two expected answers.
    const char* mech = (shared == 3)  ? "view-alias(MAPPED)"
                        : (shared == 0) ? "flat-window(TRANSLATE-BY-CALLER)"
                                        : "PARTIAL(alias-broken)";

    // The second probe needs no canary: physical 0 is the address `PhysToKernelVA(0)`
    // produces. F-640/B2: it must now MAP in all three views -- console physical 0 is a
    // real byte and the LOW REGION holds it -- so the expected count is 3, and a count
    // below 3 is a real defect, not a style. (Before the low region existed this probe
    // read 0/3, and the tree called that correct.)
    //
    // THE OUT-PARAMETER IS A SEPARATE VARIABLE, and that is a FIX, not a style choice: the
    // original code passed the COUNTER itself as the out-parameter, which was harmless
    // only because the mapping always refused and the out-param was therefore written
    // with 0. Now that physical 0 maps, the same call would overwrite the counter with
    // the pool VA (0xA0000000) and the row would print `zero_pa_mapped_views=2684354561/3`
    // -- a number that is neither the count nor the address. It printed that in the first
    // run of this change (build/agents/fix_fb_boot.log:52) and was fixed.
    uint32_t mappedAtZero = 0;
    uint32_t zeroPoolVa = 0;
    for (uint32_t i = 0; i < 3; ++i)
        if (F640MapViewToPool(kF640Views[i].base, &zeroPoolVa) == F640Map::kMapped)
            ++mappedAtZero;  // 3 is the answer; a lower count is a real defect, not a style

    // F-640/B2: THE LOW-REGION ROUND TRIP. The claim this fix makes is not "the hole is
    // smaller"; it is "console physical [0, 4 MiB) now has REAL, MAPPED, WRITABLE bytes
    // that a guest write reaches and a host read sees". A counter cannot show that, so
    // this probe SHOWS it, with byte values:
    //   (1) the translation maps console physical 0 and 0x1FE0FC -- the two the guest
    //       actually asked for in w852 (`CP: POOL-XLATE-REFUSED site=FETCHVB-CONSTANTS
    //       pa=00000000` and `pa=001FE0FC`) -- to real addresses inside the low region;
    //   (2) a WRITE through the translated address is read back through it AND through
    //       the console's own A-view form (0xA0000000 + pa), byte for byte;
    //   (3) the original bytes are restored and re-read, so the probe leaves no mark.
    // The C-VIEW form (0xC0000000 + pa) is printed too and is EXPECTED to differ: in
    // this flat window that address is the allocator pool's tail, not the low region.
    // That is not a bug in the probe; it is the whole reason the translation exists -- a
    // reader who believes the C view aliases the pool is the reader this row is for.
    {
        struct LowProbe
        {
            uint32_t pa;
            const char* what;
        };
        const LowProbe kProbes[] = {
            {0x00000000u, "guest-fetchvb-slot2-base"},
            {0x001FE0FCu, "guest-fetchvb-slot1-base"},
        };
        const uint8_t kPat[4] = {0xA5u, 0x5Au, 0x3Cu, 0xC3u};
        for (uint32_t i = 0; i < (uint32_t)(sizeof(kProbes) / sizeof(kProbes[0])); ++i)
        {
            const uint32_t lpa = kProbes[i].pa;
            uint32_t lpool = 0;
            const F640Map lm =
                F640MapViewToPool(kF640Views[0].base + lpa, &lpool);
            uint8_t orig[4] = {0, 0, 0, 0};
            uint8_t back[4] = {0, 0, 0, 0};
            uint8_t aView[4] = {0, 0, 0, 0};
            uint8_t cView[4] = {0, 0, 0, 0};
            uint8_t after[4] = {0, 0, 0, 0};
            const bool gotOrig =
                (lm == F640Map::kMapped) && mem.ReadBytes(lpool, orig, sizeof(orig));
            const bool lwrite =
                (lm == F640Map::kMapped) && mem.WriteBytes(lpool, kPat, sizeof(kPat));
            const bool gotBack =
                (lm == F640Map::kMapped) && mem.ReadBytes(lpool, back, sizeof(back));
            (void)mem.ReadBytes(kF640Views[0].base + lpa, aView, sizeof(aView));
            (void)mem.ReadBytes(kF640Views[1].base + lpa, cView, sizeof(cView));
            bool restored = false;
            if (lm == F640Map::kMapped && gotOrig)
            {
                (void)mem.WriteBytes(lpool, orig, sizeof(orig));
                restored = mem.ReadBytes(lpool, after, sizeof(after)) &&
                           std::memcmp(after, orig, sizeof(orig)) == 0;
            }
            const bool roundTrip = lwrite && gotBack &&
                                   std::memcmp(back, kPat, sizeof(kPat)) == 0;
            const bool aViewOk = std::memcmp(aView, kPat, sizeof(kPat)) == 0;
            const bool cViewDiffers = std::memcmp(cView, kPat, sizeof(kPat)) != 0;
            MCLA_LOG_WARN(
                "F640-LOWREGION-PROBE #{} what={} pa={:08X} map={} pool_va={:08X} "
                "in_low_region={} orig={:02X}{:02X}{:02X}{:02X} wrote={} "
                "readback={:02X}{:02X}{:02X}{:02X} roundtrip_ok={} "
                "aView={:02X}{:02X}{:02X}{:02X} aView_ok={} "
                "cView={:02X}{:02X}{:02X}{:02X} cView_differs={} restored={} "
                "NOTE=the_A_view_form_is_the_console's_own_alias; the_C_view_form_is_NOT",
                i + 1, kProbes[i].what, lpa,
                (lm == F640Map::kMapped) ? "MAPPED" : "NO_POOL_BYTE", lpool,
                ((uint64_t)lpool < (uint64_t)mcla::boot::kPhysLowRegionEndVa) ? 1 : 0,
                orig[0], orig[1], orig[2], orig[3], (lwrite ? 1 : 0),
                back[0], back[1], back[2], back[3], (roundTrip ? 1 : 0),
                aView[0], aView[1], aView[2], aView[3], (aViewOk ? 1 : 0),
                cView[0], cView[1], cView[2], cView[3], (cViewDiffers ? 1 : 0),
                (restored ? 1 : 0));
        }
    }

    // Why (a) is closed, measured on THIS process's window rather than argued: one
    // reservation, committed, private (Type == MEM_PRIVATE), covering the whole 4 GiB.
    MEMORY_BASIC_INFORMATION mbi{};
    const bool haveMbi = (g_base != nullptr) && (VirtualQuery(g_base, &mbi, sizeof(mbi)) != 0);
    const bool oneRegion = haveMbi && (mbi.RegionSize >= GuestMemorySize);

    MCLA_LOG_WARN(
        "F640-PHYSALIAS phase=init mech={} canary_shared_views={}/3 probe_pa={:08X} "
        "probe_pool_va={:08X} canary_written={} canary_restored={} zero_pa_mapped_views={}/3 "
        "zero_pa_pool_va={:08X} | "
        "pool=[{:08X}..{:08X}) cap={:#x} cap_mb={:.1f} pool_phys=[{:08X}..{:08X}) "
        "low_region=[{:08X}..{:08X}) low_bytes={:#x} console_phys_window=[{:08X}..{:08X}) "
        "phys_below_allocator={}MiB(covered_by_low_region={}) pool_tail_above_console={}MiB | "
        "views=A:{:08X}/{}KiB C:{:08X}/{}MiB E:{:08X}/{}KiB (size_each={:#x} from "
        "kConsolePhysicalBytes) | A_view_is_pool={} C_minus_pool={:#x} E_minus_pool={:#x} "
        "overlap_in_pool: A={}MiB C={}MiB E={}MiB | window=one_allocation:{} committed:{} "
        "private:{} region_mb={:.1f} | calls={} translated={} dropped={} adopted_sites={} "
        "zero_is_measured={} | adopt=gpu_cp.cpp:3673(rptr-writeback) "
        "native_renderer.cpp:294(present) gpu_mmio.cpp:83(MMIO-physForm)",
        mech, shared, (uint32_t)pa, poolVa, (wrote ? 1 : 0),
        ((gotBefore && gotAfter && before == after) ? 1 : 0), mappedAtZero, zeroPoolVa,
        mcla::kernel::kPhysArenaBeginVa, mcla::kernel::kPhysArenaEndVa,
        (uint64_t)mcla::kernel::PhysArenaSizeBytes(),
        (double)mcla::kernel::PhysArenaSizeBytes() / (1024.0 * 1024.0),
        (uint32_t)F640PoolPhysBase(), (uint32_t)F640PoolPhysTop(),
        mcla::boot::kPhysLowRegionVa, mcla::boot::kPhysLowRegionEndVa,
        (uint64_t)mcla::boot::kPhysLowRegionBytes,
        (uint32_t)F640ConsolePhysBase(), (uint32_t)F640ConsolePhysTop(),
        (double)F640PoolPhysBase() / (1024.0 * 1024.0),
        ((uint64_t)mcla::boot::kPhysLowRegionBytes == F640PoolPhysBase()) ? 1 : 0,
        (double)(F640PoolPhysTop() - (uint64_t)mcla::kernel::kConsolePhysicalBytes) /
            (1024.0 * 1024.0),
        kF640Views[0].base, 1u << (kF640Views[0].pageShift - 10),
        kF640Views[1].base, 1u << (kF640Views[1].pageShift - 20),
        kF640Views[2].base, 1u << (kF640Views[2].pageShift - 10),
        (uint64_t)mcla::kernel::kConsolePhysicalBytes,
        (poolVa == kF640Views[0].base + (uint32_t)pa ? 1 : 0),
        (uint64_t)(kF640Views[1].base - kF640Views[0].base),
        (uint64_t)(kF640Views[2].base - kF640Views[0].base),
        (double)F640ViewOverlapBytes(F640View::kA64K) / (1024.0 * 1024.0),
        (double)F640ViewOverlapBytes(F640View::kC16M) / (1024.0 * 1024.0),
        (double)F640ViewOverlapBytes(F640View::kE4K) / (1024.0 * 1024.0),
        (oneRegion ? 1 : 0), (haveMbi && mbi.State == MEM_COMMIT ? 1 : 0),
        (haveMbi && mbi.Type == MEM_PRIVATE ? 1 : 0),
        (haveMbi ? (double)mbi.RegionSize / (1024.0 * 1024.0) : 0.0),
        g_f640.calls.load(std::memory_order_relaxed),
        g_f640.translated.load(std::memory_order_relaxed),
        g_f640.dropped.load(std::memory_order_relaxed),
        (uint64_t)g_f640.adopted.load(std::memory_order_relaxed),
        ((uint64_t)g_f640.adopted.load(std::memory_order_relaxed) > 0 ? 1 : 0));

    // F-640: the two reporting sites this file corrected, published at INIT so a soak can
    // see the corrected extent without waiting for a crash to produce the crash file.
    MCLA_LOG_WARN("F640-POOLSCAN phase=init needle_scan_range=[{:08X}..{:08X}) label=phys-heap "
                  "bytes={} r6_device_dump_predicate=in[{:08X}..{:08X}) outside_pool_no_dump=1 "
                  "replaced_ceiling=0x100000000 over_report_bytes={} over_report_mib={:.1f}",
                  mcla::kernel::kPhysArenaBeginVa, mcla::kernel::kPhysArenaEndVa,
                  (uint64_t)mcla::kernel::PhysArenaSizeBytes(),
                  mcla::kernel::kPhysArenaBeginVa, mcla::kernel::kPhysArenaEndVa,
                  (uint64_t)0x100000000ull - (uint64_t)mcla::kernel::kPhysArenaEndVa,
                  (double)((uint64_t)0x100000000ull - (uint64_t)mcla::kernel::kPhysArenaEndVa) /
                      (1024.0 * 1024.0));
}

} // namespace mcla::boot