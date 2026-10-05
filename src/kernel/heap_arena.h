#pragma once
#include <cstdint>

// F-384: WHERE the host user-heap arena is bound in guest address space, in one place, in a header
// light enough for the checked-writer TU (`guest_memory.cpp`) to include -- `kernel/heap.h` pulls in
// `kernel/mutex.h` + `<utility>` and does not compile there. Before this, the literal 0x20000 was
// written out in five different files (arena binding, the store census, the guard page, the watch
// range, the raw re-read), which is exactly how a probe ends up watching a page the arena no longer
// occupies.
//
// WHY IT IS STILL 0x20000. The relocation was tried as a real experiment with the F-383 Path A fix in
// the tree, and the writer followed the base instead of being left behind: `w395` (arena at
// 0x20000000) prints `F374-HEAPSTORE #1 guest=20000000 val=20000004` from the *same*
// `__imp__sub_82397060+0x345` chain, with the *same* `r4=4 r5=0x10 r6=20000004`, while `sp`=8EFFF5D0
// and `r13`=8F200000 stayed put. So F-377's "the destination follows our arena base" was a real
// observation and not the census-cap artifact I suspected: **something hands the title our arena base
// and it initialises its own allocator metadata over it** -- T41.67 is the hunt for that hand-off.
// Moving the base only moves the blast radius, and a smaller arena is an unforced risk, so the
// baseline (XenonRecomp's) address stays; the constants exist so the probes can never disagree with
// the binding again.
//
// F-631 (2026-09-28) -- RELOCATION REJECTED, NOT RE-DONE. F-630 proposed moving this base so the
// instance would not sit in guest-writable range, and an adversarial review of `w654` refuted the
// mechanism before a line was written: the two arenas are disjoint (this instance at 0x20000, the
// physical one at kPhysArenaBeginVa), so zeroing this header cannot make `physicalHeap` refuse, and a
// 1-byte refusal in a 1.4949 GiB pool is o1heap's *full* path (o1heap.c:321-323), not corruption.
// `lr=821C667C` is `sub_821C6658 +0x24`, a return address inside a `memset(ptr,0,n*12)` helper, and
// with `r4=0x6F1E0` that is a ~5.2 MB memset whose only visible part was the 0x240-byte census window
// (see guest_memory.cpp:35-36) -- eight printed stores out of ~1.37 million. So this address stays,
// and the two findings that DO survive are measured elsewhere: the F-377 write over guest-owned
// allocator state is real, and the physical pool's 8,700 refusals are unexplained with ordinary
// exhaustion (512 KB per request, ~3,061 to fill 1.5 GB, zero frees) the leading hypothesis.
namespace mcla::kernel
{
    inline constexpr uint32_t kUserHeapArenaVa = 0x00020000u;
    inline constexpr uint32_t kUserHeapArenaEnd =
        0x7FEA0000u;  // == RESERVED_BEGIN, the original ~2 GiB capacity

    // F-391: the PHYSICAL arena used to start at 0xA0000000 (`RESERVED_END` in heap.cpp), and the
    // title's own XTL allocator region is guest 0xA0001000..0xA002FFC0 -- measured at the faulting
    // store, not guessed: `F389-BANK bank=82830B18 alloc=[bank+4]=82830CD8 vt=82011884
    // fn=821C29A0 head=[82011884 A0001010 A0001000 0 0 A002FFC0 0 0]` (`w403`; the chain is
    // `[[r13]+28]` -> `[obj+8]` = the dispatcher `sub_821C08F8`, which selects
    // `m_Allocators[(r6+1)*4]`). Our o1heap instance sits at the arena base and its FIRST blocks
    // therefore land at 0xA0001000+, i.e. inside the title's heap: its slab metadata overwrites our
    // fragment headers, and `o1heapAllocate` later chases a fragment pointer that is really a guest
    // address -- one `code=0xC0000005 at o1heapAllocate+0x98` per boot, `rcx=0xE49125D4`,
    // `rdi=r8=Translate(0xA0000000)`. Session 76j's `WIN76-ALLOC`/`WIN76-FREE` "overlap window"
    // census (0xA0017FE0..0xA0018060, "holder vs guest-slab-element") had already seen the overlap
    // but never named the owner of the other side. Start the host pool above the title's region
    // instead; 4 MiB of headroom so the buddy allocator can add slabs without touching us.
    // F-631: `w654` re-measures the title-side pool over THIS arena as
    // `head=[82011884 A0401010 A0401000 0 0 A042FFC0 0 0]` -- base 0xA0401000, span 0x2FFC0, i.e. the
    // same 192 KiB shape F-391 recorded, shifted by exactly the +0x4000000 this constant moved. The
    // instance here is still safe (0xA0400000 is 0x1000 below the first block o1heap returns).
    inline constexpr uint32_t kPhysArenaBeginVa = 0xA0400000u;

    // F-640: THE CONSOLE'S PHYSICAL POOL SIZE. This is the constant that replaces an invented one,
    // and it is a hardware fact, so it lives here next to the base it is measured against.
    //
    // SOURCE -- the reference emulator, .research/xenia/src/xenia/memory.cc:171-172:
    //     heaps_.physical.Initialize(this, physical_membase_, HeapType::kGuestPhysical,
    //                                0x00000000, 0x20000000, 4096);
    // 0x20000000 = 536,870,912 = 512 MiB, and the argument is positional, so it is unambiguous.
    // Corroborated three more times in the SAME file:
    //   * :132-135  reserves 0x11FFFFFFF, commented "entire 4gb space + 512mb physical";
    //   * :158      physical_membase_ = mapping_base_ + 0x100000000 -- physical memory is a SEPARATE
    //                host region ABOVE the 4 GiB guest mapping, not a slice of guest virtual space;
    //   * :271-274  maps exactly 0x100000000..0x11FFFFFFF and calls it "physical raw".
    // The three guest-visible regions that follow (:173-180, at 0xA0000000 / 0xC0000000 /
    // 0xE0000000, with 64 KiB / 16 MiB / 4 KiB page sizes) are NOT a split: each is declared with
    // the full 0x20000000 and passed `&heaps_.physical`, i.e. they are three page-size VIEWS
    // ALIASED ONTO THE SAME 512 MiB PARENT. There is no size cvar anywhere in that file -- the
    // only cvars it defines are protect_zero, scribble_heap and protect_on_release. So 512 MiB is
    // fixed, it is one pool, and this is the whole configuration surface.
    //
    // WHAT IT REPLACES, and why the old value was invented. `Heap::Init` computed the capacity as
    // `0x100000000 - kPhysArenaBeginVa` = 0x5FC00000 = 1,532.0 MiB, i.e. "everything above the
    // base, to the top of the 4 GiB window". That expression has no source: the only thing it
    // encodes is F-391's placement of kPhysArenaBeginVa, whose own comment (this file, :39-51)
    // gives the base a reason -- clear the title's XTL slab region at 0xA0001000..0xA002FFC0 -- and
    // a relocation that was tried and reverted. A reason to move the BASE is not a reason for the
    // SIZE, and none was ever offered. The ratio this constant corrects is 2.992x.
    //
    // WHAT THE GUEST IS TOLD, because that is what makes this a correction and not a policy
    // preference: the guest is told 512 MiB STRUCTURALLY, by the physical-address form this tree
    // already serves. `PhysToKernelVA` (src/gpu_cp.cpp:1752-1757) is the console's own rule --
    // "X360: kernel maps phys windows at +0xC0000000" -- and its gate is `addr < 0x20000000`; the
    // same threshold is written out independently at gpu_cp.cpp:2328, gpu_mmio.cpp:83
    // (`MmioAddrSpace`: "a < 0x20000000 -> PHYS, physForm = a | 0xC0000000"),
    // native_renderer.cpp:120/226/277/294/308, and gpu_mmio.cpp:74. Five sites, one number: this
    // tree already tells the guest that a physical address is below 0x20000000. Backing that claim
    // with 1,532 MiB is a lie with a number attached, and 1,532/512 = 2.992x is the size of it.
    // `MmAllocatePhysicalMemoryEx` (imports.cpp:4412-4466) passes the pool no size at all -- it
    // logs minAddress/maxAddress and ignores both -- so the allocation contract is NOT where the
    // guest learns this; the address form is. That is why the number has to be the real one.
    inline constexpr uint32_t kConsolePhysicalBytes = 0x20000000u;

    // F-640: the pool's upper bound in GUEST VA terms, and its CAPACITY, both DERIVED from the one
    // constant above. Nothing here is a second typed literal: the extent is
    // [kPhysArenaBeginVa, kPhysArenaBeginVa + kConsolePhysicalBytes) = 0xA0400000..0xC0400000, and
    // the capacity is that extent's length. The `min` is a saturation guard for the case where
    // the pool is ever bound low enough for the console's size to run past the top of the 4 GiB
    // window; today kPhysArenaBeginVa (0xA0400000) exceeds kConsolePhysicalBytes (0x20000000), so
    // the capacity is the console's 512 MiB in full and the guard is inert. Keeping it makes the
    // relationship a function of the BASE and the constant rather than a number that has to be
    // re-derived if the base ever moves again (F-631 moved it once already).
    // F-640: 2^32 DOES NOT FIT A uint32_t, and writing `0x100000000u` into one is a real bug that
    // this file's own static_assert caught on its first compile. On LLP64 (MSVC/clang-cl) `u` on a
    // hex literal too large for `unsigned int` promotes all the way to `unsigned long long` -- both
    // `unsigned int` and `unsigned long` are 32-bit there -- and the narrowing to uint32_t then
    // yields 0. With the ceiling reading 0, `top < ceiling` was false, the saturation guard took
    // its else arm, and the capacity came out as `0 - kPhysArenaBeginVa` = 0x5FC00000, i.e. the
    // 1,532 MiB value this change exists to delete. Every boundary here is therefore uint64_t and
    // the 32-bit values are produced only after the clamping, by an explicit cast.
    inline constexpr uint64_t kGuestWindowTopVa = 0x100000000ull;  // the 4 GiB guest window's top

    // The pool's upper bound, clamped to the guest window. 0xC0400000 today.
    constexpr uint64_t PhysArenaTopVa()
    {
        const uint64_t top = (uint64_t)kPhysArenaBeginVa + (uint64_t)kConsolePhysicalBytes;
        return (top < kGuestWindowTopVa) ? top : kGuestWindowTopVa;
    }
    // F-640: THE POOL'S UPPER BOUND, for the two call sites that still hardcode 0x100000000
    // (reported below). Named here so those two have one thing to adopt rather than a new literal.
    inline constexpr uint32_t kPhysArenaEndVa = (uint32_t)PhysArenaTopVa();

    constexpr uint32_t PhysArenaSizeBytes()
    {
        return (uint32_t)(PhysArenaTopVa() - (uint64_t)kPhysArenaBeginVa);
    }
    static_assert(PhysArenaSizeBytes() == kConsolePhysicalBytes,
                  "F-640: with the pool bound above the console's 512 MiB the capacity must BE the "
                  "console's 512 MiB. If this ever fires, kPhysArenaBeginVa moved below "
                  "0x20000000 and the extent is clamped by the 4 GiB window, not by the hardware.");
    static_assert(kPhysArenaEndVa == 0xC0400000u,
                  "F-640: the pool's guest extent must be [0xA0400000, 0xC0400000). If the base or "
                  "the constant moved, this is the number to re-derive -- not to delete.");

    // ==========================================================================================
    // F-644: THE POOL SIZE AS A DELIBERATE LEVER -- WHAT RAISING `kConsolePhysicalBytes` TOUCHES,
    // AND THE CEILING THAT WOULD BIND FIRST. The value above is NOT changed by this block and must
    // not be: 512 MiB is the console's hardware fact and honouring it is the correct default. What
    // was missing was not the ability to change it (it is one constant) but the two NUMBERS a
    // decision needs, so that the decision is one line of reading rather than an investigation. They
    // are these, and they are different numbers, which is the whole point.
    //
    //   THE CONSOLE'S FIGURE                     0x20000000   =    512.0 MiB
    //   THE CEILING AT TODAY'S BASE (below)      0x5FC00000   =  1,532.0 MiB
    //   THE CEILING AT BASE 0x80000000 (below)   0x80000000   =  2,048.0 MiB
    //
    // (1) THE GUEST WINDOW IS THE HARD CEILING, AND IT BINDS BEFORE ANY HARDWARE LIMIT.
    // This tree has ONE flat 4 GiB host window -- `GuestMemoryHeap::kSize = 0x100000000`
    // (src/kernel/memory.h:20, one VirtualAlloc at src/boot_host.cpp:677) -- and the pool is a slice
    // carved out of its top. So the pool cannot be larger than the window above its base, and the
    // moment `kConsolePhysicalBytes > kGuestWindowTopVa - kPhysArenaBeginVa` the `PhysArenaTopVa()`
    // clamp above stops being inert and `PhysArenaSizeBytes()` starts returning the window remainder
    // rather than the requested size. `static_assert(PhysArenaSizeBytes() == kConsolePhysicalBytes)`
    // above is what makes that condition a COMPILE ERROR rather than a silent capacity change, and
    // it is the one line a future editor has to read. Arithmetic at today's base:
    //     0x100000000 - 0xA0400000 = 0x5FC00000 = 1,532.0 MiB.
    // So at `kPhysArenaBeginVa` = 0xA0400000 a 2 GiB modded pool is NOT expressible, and 1,532.0 MiB
    // is the largest value that would compile. This is a different number from 512 MiB and it is
    // the number that actually limits a mod, not the console's.
    //
    // (2) TO REACH 2 GiB, MOVE THE BASE DOWN -- and here is what that costs, by file:line.
    //   * `kPhysArenaBase` itself, obviously: 0xA0400000 -> 0x80000000. `PhysArenaTopVa()` and
    //     `PhysArenaEndVa` are derived from it above and need no edit.
    //   * 0x80000000 is chosen because it is the first VA above the guest-virtual carve
    //     `GuestMemoryHeap::kGuestVirtualBase/End` = [0x40000000, 0x80000000) (src/kernel/memory.h:
    //     58-60), which `NtAllocateVirtualMemory` owns exclusively; going lower would collide with
    //     it and going higher costs ceiling. 0x80000000 + 0x80000000 = 0x100000000 exactly, i.e. a
    //     2 GiB pool at that base fills the window with ZERO headroom -- so 2 GiB is the ceiling and
    //     not a comfortable working value.
    //   * THE GPU'S PHYSICAL-ADDRESS FORM IS THE SECOND CEILING AND IT IS 512 MiB. The guest is told
    //     a physical address is below 0x20000000 by FIVE sites, all writing the literal:
    //     src/gpu_cp.cpp:1752-1757 (`PhysToKernelVA`, the console's own rule, "X360: kernel maps
    //     phys windows at +0xC0000000"), src/gpu_cp.cpp:2328, src/gpu_mmio.cpp:83
    //     (`MmioAddrSpace`: "a < 0x20000000 -> PHYS, physForm = a | 0xC0000000"), src/gpu_mmio.cpp:74,
    //     and src/native_renderer.cpp:120, :226, :277, :294, :308. A pool larger than 512 MiB hands
    //     the GPU physical addresses >= 0x20000000, and each of those sites will treat them as
    //     something they are not. This is why raising the pool is NOT a one-constant change even
    //     though the capacity IS a one-constant expression, and it is a modelling gap that is
    //     already documented at the end of this file (the console aliases 0xA0000000+pa and
    //     0xC0000000+pa onto the same bytes; this tree does not).
    //   * `Heap::Init` derives its extent from both constants (src/kernel/heap.cpp:2078,
    //     `physArenaSize = PhysArenaSizeBytes()`, then `o1heapInit` at :2079) and prints it on the
    //     `PHYS-POOL phase=init` row (heap.cpp:2094-2095), so the init row becomes the single place
    //     that confirms which of the two numbers took effect.
    //   * THE CRASH PATH ALREADY TOOK THE UPPER BOUND (so it needs no edit and is listed here only
    //     so nobody re-opens it): src/boot_host.cpp:2163-2164 `{kPhysArenaBeginVa,
    //     (uint64_t)kPhysArenaEndVa, "phys-heap"}`, :3762, :3790-3795 all adopt `kPhysArenaEndVa`.
    //     The earlier note in this file that named :1631 and :1669-1673 as still assuming
    //     0x100000000 is superseded by those edits -- measured, not assumed.
    //   * ONE RANGE IS HARDWIRED TO A POOL-LOCAL WINDOW and does not follow the size: the guest
    //     watch range src/boot_host.cpp:2786-2787 is
    //     `[kPhysArenaBeginVa, kPhysArenaBeginVa + 0x800)`, i.e. o1heap's instance header. It is
    //     size-independent by construction and correct at any pool size.
    //
    // (3) WHAT IS ASSERTED, so a future change cannot be silent. `kPhysPoolCeilingBytes` below is
    // the window remainder at the CURRENT base; the static_asserts state that the console's figure
    // is under it (true, by 3.0x) and that the pool's capacity equals the console's figure (already
    // asserted above). A future editor who raises `kConsolePhysicalBytes` past the ceiling gets a
    // compile error naming the arithmetic, which is the cheapest possible reversal cost.
    inline constexpr uint64_t kPhysPoolCeilingBytes =
        kGuestWindowTopVa - (uint64_t)kPhysArenaBeginVa;  // 0x5FC00000 = 1,532.0 MiB today
    static_assert(kConsolePhysicalBytes <= kPhysPoolCeilingBytes,
                  "F-644: the pool cannot exceed the flat 4 GiB guest window above its base "
                  "(0x100000000 - kPhysArenaBeginVa). Raise kPhysArenaBeginVa -> 0x80000000 first "
                  "(below the guest-virtual carve's top, 0x80000000) and re-derive this.");
    static_assert(PhysArenaSizeBytes() == kConsolePhysicalBytes,
                  "F-644: the capacity must still BE the requested size, not the window remainder. "
                  "This is the same invariant F-640 asserted; it is repeated here because the lever "
                  "above is where a future editor will be standing.");

    // F-645: HOW FAR ABOVE ITS OWN FRAGMENT A PHYSICAL USER POINTER MAY SIT. This is a bound, not
    // a budget: nothing here allocates, widens the pool, or raises the ceiling. It exists because
    // `Heap::AllocPhysical` does NOT return o1heap's raw pointer to the guest -- it returns
    // `aligned = round_up(raw, alignment)` with a floor of `raw + O1HEAP_ALIGNMENT`
    // (src/kernel/heap.cpp, quoted by symbol `AllocPhysical`, at the `aligned` local and the
    // `if (aligned < ptr + O1HEAP_ALIGNMENT)` guard), and stores the raw pointer in the word EIGHT
    // bytes below it. So every physical address the guest holds satisfies
    //     0 < (user - raw) <= O1HEAP_ALIGNMENT + alignment.
    // The alignment is bounded by the CALLERS, not by this file: `XAllocMem` passes
    // `1ull << ((flags >> 24) & 0xF)` (heap.cpp, `XAllocMem`), i.e. at most 1 << 15 = 32768;
    // `AllocPhysical<T>` passes `alignof(T)` (heap.h:88) and `GuestMemoryHeap::Alloc`'s own default
    // is 16 (memory.h:54); the guest's XTL alloc thunk hardcodes 16 (`82130538 li r5,16`, measured
    // off build/cache/mcla_pe.bin per F-023). So the maximum observed in-tree is 32768, and
    //     0x20 + 0x8000 = 0x8020
    // is the tightest bound that is still true for every caller in this tree. It is deliberately
    // small: it is used to REJECT a candidate user-pointer recovery, so a loose value would be a
    // wider accept than the allocator can produce.
    inline constexpr uint32_t kPhysUserPointerSlackBytes = 0x8020u;

    // F-640: TWO PLACES THAT STILL ASSUME THE OLD 0x100000000 CEILING. Both are outside this
    // stream's file ownership, so they are REPORTED here rather than edited, and a reader who
    // greps for kPhysArenaBeginVa will find the two: src/boot_host.cpp:1631 declares the guard/dump
    // range `{kPhysArenaBeginVa, 0x100000000ull, "phys-heap"}` -- which should become
    // `{kPhysArenaBeginVa, (uint64_t)kPhysArenaEndVa, "phys-heap"}` -- and
    // src/boot_host.cpp:1669-1673 treats every `r6v >= kPhysArenaBeginVa` as ours. Both now over-report by exactly the removed
    // 1,020.0 MiB (0x5FC00000 - 0x20000000): the dump scanner will walk 1.5 GiB of region that is
    // no longer ours, and the VEH attribution will name a fault at 0xC1000000+ as a physical-heap
    // hit. That is a measurement-fidelity loss in the crash path, not a corruption, and it is the
    // first thing to adopt kPhysArenaEndVa.
    //
    // AND THE STRUCTURAL DIFFERENCE, which no constant in this file can fix. The reference puts
    // physical RAM in a host region ABOVE the 4 GiB guest mapping and gives the guest three ALIASED
    // VIEWS of it (memory.cc:158, :173-180, :271-274). This tree has ONE flat 4 GiB host window
    // (src/boot_host.cpp:677, a single VirtualAlloc) and carves the pool out of its TOP, so guest
    // VA 0xC0000000 is not a view of the pool at all -- it is just more flat memory further up.
    // The console's guarantee that 0xA0000000+pa and 0xC0000000+pa are the SAME bytes is therefore
    // NOT implemented here, and the old 1.5 GiB capacity was hiding the hole: with the pool
    // reaching 0xFFFFFFFF, the GPU's own `pa | 0xC0000000` transform happened to land inside the
    // pool (though at the wrong offset, so it was never the aliasing it looked like). Capping at
    // 512 MiB puts the pool's end at 0xC0400000, so of the range 0xC0000000..0xC2000000 that
    // `PhysToKernelVA` produces for pa in 0..0x1FFFFFFF, only its first 4 MiB is inside the pool.
    // That is a real and now-VISIBLE modelling gap, it is not caused by the capacity, and it is
    // the thing to measure next -- see the F-640 note on the PHYS-POOL row in heap.cpp.
} // namespace mcla::kernel
