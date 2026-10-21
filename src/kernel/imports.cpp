#include <stdafx.h>
#include <cpu/ppc_context.h>
#include <cpu/guest_thread.h>
#include <chrono>
#include <apu/audio.h>
#include "function.h"
#include "heap.h"
#include "memory.h"
#include <memory>
#include <cstring>
#include "xam.h"
#include "xdm.h"
#include "kernel_objects.h"
// F-609 port batch, 2026-09-29 (integration stream). Both are hand-written
// headers, not generated. port_kobj.h brings the two REAL kernel objects
// (Mutant, TimerObject) and kobjport::FormatCore, the tree's SINGLE format
// engine -- DbgPrint below is wired to it rather than sitting as a stub beside
// a working engine. port_net.h brings the ONE netport last-error cell, so the
// twelve NetRefuse refusals in this file and the eighteen bodies in port_net.cpp
// share it instead of each reporting only its own half.
// INCLUDE ORDER IS LOAD-BEARING for port_kobj.h: it needs <stdafx.h> first (line
// 1 of this file) for the generated ppc_context.h, and windows.h ahead of
// <mutex>/<condition_variable>. That is the same order src/kernel/port_kobj.cpp
// uses, which is the working example.
#include "port_kobj.h"
#include "port_net.h"
// F-840 (2026-10-21): the NTSTATUS -> Win32 error table for
// RtlNtStatusToDosError. GENERATED, not hand-typed -- see
// src/kernel/ntstatus_dos_error_table.h's own header comment for the
// reference it was parsed out of and the generator that produced it.
#include "ntstatus_dos_error_table.h"
// F-841 (2026-10-21): the console's export tables for the system modules the
// guest asks about ("xam.xex", "xboxkrnl.exe") and the guest import thunks
// this title binds them to. GENERATED from the retail XEX container -- see
// src/kernel/xex_console_exports.h's own header comment.
#include "xex_console_exports.h"
#include <boot_host.h>  // F-370: counting-semaphore registry
#include "logging.h"
#include <bit>
#include <cstdlib>  // T43.28: std::getenv for the mcla_xtl_title_alloc cvar
#include <gpu_cp.h>
#include <user/config.h>
#include <os/logger.h>

// ---------------------------------------------------------------------------
// T43.28 (2026-10-21): THE CONSOLE'S OWN XTL ALLOC/FREE DISPATCHERS -- CALLED,
// NOT HOOKED.
//
// These are FORWARD DECLARATIONS. `PPC_FUNC(x);` is the "fwd" class to
// tools/addr_owners.py, and that tool's own docstring says a forward
// declaration "-- no claim" (src: "PPC_FUNC(sub_X);   fwd   forward
// declaration -- no claim"). So neither guest address gains an owner from
// this file.
//
// RULE 4 WAS RUN BEFORE THIS WAS WRITTEN (2026-10-21):
//   python tools/addr_owners.py --check 0x821C08F8
//     -> "2 site(s)  orig src/gpu_device.cpp:25829 / override src/gpu_device.cpp:25830"
//   python tools/addr_owners.py --check 0x821C09C8
//     -> "2 site(s)  orig src/hooks/alloc_census.cpp:12491 / override ...:12499"
// Both exit 0 (no conflict). The definitions live at src/gpu_device.cpp:25830
// (0x821C08F8, the F396-ALLOC-ENTER census) and src/hooks/alloc_census.cpp:
// 12499 (0x821C09C8, the pool-free dispatcher).
//
// WHY CALL THEM AT ALL: the guest's XTL heap must be served by the TITLE's own
// allocator, not by a fresh physical page per request. The measurement, the
// console's ABI, the fallback and the falsifier are all written out at the
// helper block below (search for "T43.28 -- THE XTL HEAP").
// ---------------------------------------------------------------------------
PPC_FUNC(sub_821C08F8);
PPC_FUNC(sub_821C09C8);

// Host thread id of the guest main thread (see xdm.h). Defined here; set by
// boot_host.cpp when the boot worker starts.
std::atomic<uint32_t> g_mainGuestThreadId{0};

// T43.18 (2026-10-13): latest-main-park publication, declared in xdm.h.
std::atomic<uint32_t> g_mainParkHandle{0};
std::atomic<uint32_t> g_mainParkLr{0};
std::atomic<uint64_t> g_mainParkNs{0};

// Forward declaration for VSync thread's scheduler tick signaling.
    // Signal scheduler tick semaphore (0x40004D7C) to unblock main thread wait.
    // This is the kernel-role duty that the real hardware GPU ISR/vblank path would
    // perform. The game's main thread waits on 0x40004D7C with ~30ms timeout;
    // without this signal, the main thread parks forever.
    static void SignalSchedulerTick();
    // Non-static wrapper for cross-TU calls (e.g., gpu_device.cpp boot gate).
    void SignalSchedulerTickPublic() { SignalSchedulerTick(); }

static std::atomic<uint32_t> g_keSetEventGeneration;

// Forward declarations
void MmTrackAllocationSize(uint32_t guestAddress, uint32_t size);
void StartGpuContextPoller();

// XEX loader / crypto forward declarations (must precede hook registrations)
void XexLoadImage();
void XexLoadImageHeaders();
void XexUnloadImage();
void XexCheckExecutablePages();
void XeCryptBnQwBeSigVerify();
void XeCryptSha();
void XeCryptRotSumSha();
void XeKeysGetKey();
void sub_821305B8_NoOp();

// ---------------------------------------------------------------------------
// XTL allocator - used by guest code via r13 thread block
//
// THE RETURN CONTRACT, read off the guest's own bytes, not assumed. This
// corrects an earlier brief that described the failure path of this thunk as
// "a raise" we deleted. It was never a raise, and the guest still returns
// null here. Measured three independent ways that agree:
//
// 1) `sub_82130528` (the guest thunk) loads the allocator descriptor from
//    *(r13)+28 and does `bctr` to the vfunc at vtable slot +8 with r3=descriptor,
//    r4=SIZE, r5=16. It does not test the result.
// 2) Its caller in the refusal path, `sub_821378B8`, is a strlen+1 duplicator:
//    strlen -> sub_82130528 -> sub_823DA950 (memcpy), with NO null check between
//    them. So a refusal here runs a memcpy onto 0. That is the guest's business;
//    it is safe on the console only because the console's pool never refuses.
// 3) The alleged raise, `sub_82135D38(8)`, is NOT one. It is a 4-byte
//    tail-call thunk onto a SIX-INSTRUCTION latching error store:
//
//      0x82135D38  b     0x82135D40
//      0x82135D40  lwz   r11, 0x150(r13)
//      0x82135D44  cmplwi cr6, r11, 0
//      0x82135D48  bnelr cr6                 ; latch once, then stop writing
//      0x82135D4C  lwz   r11, 0x100(r13)
//      0x82135D50  stw   r3,  0x160(r11)      ; *(*(r13+0x100) + 0x160) = code
//      0x82135D54  blr
//
//    No `twi`, no `t`, no `sc`, no `mtspr`, no stack touch, no call out: it
//    RECORDS and RETURNS NORMALLY. It unwinds nothing. Its sibling
//    `sub_82135D90` is the matching getter (same guard, `lwz r3,0x160(r11)`, and
//    `li r3,0` on the other path), and `sub_82135D58` is the same latch fed
//    through `__imp__RtlNtStatusToDosError` (0x827BD024 =
//    generated/default/mcla_init.cpp:29710) -- which is what names the family:
//    Win32 LAST-ERROR, not an exception. All 19 `bl 0x82135D38` sites in the
//    image pass 0, 3, 5, 8, 122, 996 plus 4 variable codes. It is an
//    error-code setter.
//
// So the console's contract for a refused allocation is precisely:
//     return 0, having latched the code into the thread's last-error word.
// The value the allocation wrapper passes is 8 == ERROR_NOT_ENOUGH_MEMORY
// (`addi r3,r0,8` at 0x821325DC, straight into `bl 0x82135D38`), and
// `sub_82132578` then does `mr r3,r31` at 0x821325E4 with r31 still 0 and
// epilogues -- i.e. it returns null to ITS caller too, after latching.
//
// CONSEQUENCE FOR THIS FUNCTION. Do not trap, and do not invent an exception
// the console does not raise. Return the console's 0 -- and make the refusal
// COUNTED and NAMED, because a bare 0 handed to an unchecked memcpy is exactly
// the silent failure this tree has spent a day removing. The row below also
// carries the guest's OWN last-error word, so a soak can tell "the console's
// failure path ran" (latch == 8) from "we returned null and nothing noticed".
// ---------------------------------------------------------------------------
namespace {

// What the guest itself passes as the error code on a refused allocation
// (`addi r3,r0,8` at 0x821325DC). 8 == ERROR_NOT_ENOUGH_MEMORY. The host does
// not raise it; it only compares the guest's latch against it.
constexpr uint32_t kConsoleOomLastError = 8u;

// "the guest error word could not be read" -- distinct from a guest that
// latched 0, which is a real, reportable answer.
constexpr uint32_t kXtlLastErrorUnread = 0xFFFFFFFFu;

std::atomic<uint64_t> g_xtlAllocSeen{0};
std::atomic<uint64_t> g_xtlAllocOk{0};
std::atomic<uint64_t> g_xtlAllocRefused{0};

// Read the guest's latching last-error word, *(*(r13 + 0x100) + 0x160), using
// the checked helpers only. r13 is a GUEST value (boot_host.cpp:1078 sets it to
// the ThreadBlock, 0x8F200000), so this is a census and not a contract: every
// step is range-checked, a short read is reported as unread rather than
// guessed to be 0, and nothing here can fault or assert.
uint32_t XtlGuestLastError() {
  const uint32_t r13 =
      g_ppcContext ? static_cast<uint32_t>(g_ppcContext->r13.u32) : 0u;
  if (r13 == 0u || r13 > 0xFFFFF000u)
    return kXtlLastErrorUnread;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!mem.IsValid(r13 + 0x100u, 4))
    return kXtlLastErrorUnread;
  uint32_t block = 0;
  if (!mem.ReadU32BE(r13 + 0x100u, &block))
    return kXtlLastErrorUnread;
  if (block == 0u || block > 0xFFFFF000u)
    return kXtlLastErrorUnread;
  if (!mem.IsValid(block + 0x160u, 4))
    return kXtlLastErrorUnread;
  uint32_t code = 0;
  if (!mem.ReadU32BE(block + 0x160u, &code))
    return kXtlLastErrorUnread;
  return code;
}

// ===========================================================================
// T43.28 (2026-10-21) -- THE XTL HEAP MUST COME FROM THE TITLE'S OWN
// ALLOCATOR, NOT FROM THE CONSOLE'S 512 MiB PHYSICAL POOL.
//
// THE MEASUREMENT (build/w821.log -- the run build/agents/xtlsrc.md quotes):
//   :49658  PHYS-ACCT #46000 n=46000 req=457.1MB charge=628.9MB
//           con_charge=621.9MB over_console_ppm=1011325
//           live=510.0MB cap=512.0MB free=2.0MB
//   :251    PHYS-CENSUS #1 size=0x2e80000  ( 46.5 MiB) lr=821325D4
//   :263    PHYS-CENSUS #2 size=0x800000    (  8.0 MiB) lr=821325D4
//   :271    PHYS-CENSUS #3 size=0x12b80000 (299.5 MiB) lr=821325D4
//   :1718   HEAP76 simple @82830CD8 vt=82011884 +4=A0404010 +76=02E7FFF0
//           +152=02E5FD90 +248=A0404000
//   :1643   F396-ALLOC-EXIT #1 self=82830B18 size=496 ret=A0404020
//   :49682  XTL-ALLOC-REFUSED #1 ... seen=42536
//   :50603  PHYS-STATE #6 allocated=0x20000000 capacity=0x20000000 free=0x0
//
//   42,915 XTL calls (w821.log XTL-ALLOC-REFUSED #8: seen=42915 ok=42907)
//   charged 628.9 - 354.1 (whale 299.52 + boot 46.5 + 8.0) = 274.8 MiB of the
//   512 MiB pool, for a payload whose SAMPLED MEDIAN IS 17 BYTES: the 83
//   every-512th XTL-ALLOC samples in w821.log sum 11,802 B over 42,907 calls,
//   i.e. ~6.1 MiB of payload for 274.8 MiB of pool.  And the console's own
//   page rule would want 621.9 MiB against a 512 MiB pool (pool size:
//   src/kernel/heap_arena.h:97, kConsolePhysicalBytes = 0x20000000) = 1.215x
//   the console's ENTIRE physical memory -- impossible for a game that runs on
//   that console.
//
// THE CONSOLE'S ABI, READ OFF THE GUEST'S OWN BYTES (F-023: the raw word is
// the authority. build/cache/mcla_pe.bin, offset = VA - 0x82000000,
// big-endian. Decoded with tools/ppc_disasm.py, which prints the mnemonics).
//
//   XTL ALLOC THUNK 0x82130528 (`ppc_disasm.py 0x82130528 40`):
//     82130530  mr   r4,r3        ; r4 = SIZE
//     82130534  li   r6,0         ; r6 = 0, the allocator SELECTOR
//     82130538  li   r5,16        ; r5 = ALIGN
//     8213053C  lwzx r3,r10,r11   ; r3 = *(*(r13)+28) = the DESCRIPTOR
//     82130544  lwz  r8,8(r9)     ; the method at [*descriptor + 8]
//     8213054C  bctr
//
//   XTL FREE THUNK 0x82130588 (same tool):
//     82130588  mr   r4,r3        ; r4 = THE POINTER
//     8213058C  cmpli cr6,r4,0
//     82130590  beqlr            ; NULL short-circuits IN THE GUEST
//     821305A4  lwz  r8,12(r9)    ; the method at [*descriptor + 12]
//     821305AC  bctr             ; NO SIZE IS PASSED
//
//   THE DESCRIPTOR AND ITS TWO METHODS. build/w788.log is the only run whose
//   F389 probe found the chain ALIVE:
//     F389-XTLCHAIN r13=8F200000 [r13]=8F201000 obj=[[r13]+28]=82830B18
//                  vt=[obj]=820114C4 allocFn=[vt+8]=821C08F8
//     F389-BANK     bank=82830B18 alloc=[bank+4]=82830CD8 vt=82011884
//                  fn=821C29A0 head=[82011884 A0404010 A0404000 ...]
//   and the raw vtable word at 0x820114C4+12 (build/cache/mcla_pe.bin, file
//   offset 0x114C4+12) is 0x821C09C8 -- the FREE dispatcher the guest's own
//   free thunk reads at +12.  So the console's XTL pair is ALLOC = 0x821C08F8
//   and FREE = 0x821C09C8, both entered with r3 = the descriptor 0x82830B18.
//
//   0x821C08F8's BODY (raw words 0x821C08F8..0x821C0910, and the emitted
//   body at generated/ppc_xenon/ppc_recomp.15.cpp:5463-5482):
//     39660001 addi   r11,r6,1
//     556A103A rlwinm r10,r11,2,0,29
//     7C6A182E lwzx   r3,r10,r3        ; r3 = *(self + (r6+1)*4)
//     81230000 lwz    r9,0(r3)         ; r9 = the allocator's vtable
//     81090008 lwz    r8,8(r9)         ; its ALLOC method
//     7D0903A6 mtctr  r8
//     4E800420 bctr
//   => r3 = SELF (the bank), r4 = size, r5 = align, r6 = the selector, and the
//      method is [*(self + (r6+1)*4) + 8].  r4/r5 are NOT rewritten, so they
//      reach the allocator's method AS size/align.
//
//   0x821C09C8's BODY (generated/ppc_xenon/ppc_recomp.15.cpp:5604-5716): it
//   walks the SAME array at self+4 (count at self+36), asks each allocator
//   [vtable+80] "is this pointer yours?", and on a hit calls [vtable+12].
//   => r3 = SELF, r4 = THE POINTER.  NO SIZE.
//
// WHICH ALLOCATOR THE CONSOLE'S XTL PATH REACHES: r6 = 0 -> *(self+4) ->
//   0x82830CD8, the "simple" allocator (w788.log F389-BANK).  Its pool is
//   [0xA0404020, 0xA3284000) -- the 46.5 MiB block of PHYS-CENSUS #1, ALREADY
//   charged to the 512 MiB pool -- and it is a free-list allocator over that
//   region whose small path packs elements into 16 KiB slabs
//   (src/hooks/alloc_census.cpp:2134, `slab = elem & ~0x3FFF`), which is HOW
//   the console serves 42,915 requests of a 17-byte median out of memory it
//   already owns.  Its "is this pointer mine" test -- 0x821C17A8, the
//   vtable slot +80 -- is a PURE RANGE CHECK:
//     821C17A8 lwz r11,4(r3) ; addi r10,r11,16 ; cmplw cr6,r4,r10 ;
//     821C17B8 lwz r10,76(r3) ; add r11,r10,r11 ; cmplw cr6,r4,r11
//   i.e. "mine" == first+16 <= ptr < first+cap, with first = [alloc+4] and
//   cap = [alloc+76].  THE HOST USES THAT PREDICATE VERBATIM before
//   delegating a free, so the console's dispatcher can never reach its
//   "no owner" path -- 0x821BD618, whose fallback is the `b 0x821BD640`
//   SELF-LOOP, i.e. A HANG.
//
// WHAT THIS CHANGES: the XTL class stops being 42,915 fresh 4 KiB physical
// pages (274.8 MiB of the pool) and becomes ~6.1 MiB carved out of a pool
// the title already owns.  THE POOL IS CHARGED ONCE, NOT TWICE.
//
// THE FALLBACK: until the title's allocator is initialised the physical-pool
// path is KEPT, so an early request is served rather than refused.  The
// ordering is measured, not assumed: the title's first allocation is at
// w821.log 13:42:28.677 and the first XTL allocation is at 13:42:28.640 --
// 37 ms EARLIER, i.e. the fallback is genuinely needed at boot.
//
// THE FALSIFIER -- a soak must show ALL of these:
//   1. XTL-TITLE-ALLOC rows appear at all (the delegation never happened).
//   2. Their pointers lie inside [0xA0404020, 0xA3284000).
//   3. PHYS-ACCT `charge` falls by ~275 MiB to ~354 MiB while `n` stays
//      ~46,000 (the pool would still be charged for the XTL class).
//   4. PHYS-STATE / PHYS-POOL-FULL stop appearing and `free` stays > 0.
//   5. F396-ALLOC-ENTER's count RISES (the title's allocator now serves the
//      XTL class too).  THAT IS THE CONTROL: if F396 does not change while
//      PHYS-ACCT does not change, the instrument is blind and the change is
//      unproven.
//   6. XTL-ALLOC-REFUSED > 0 (the title's 46.5 MiB pool could not take the
//      class).
//   7. POOL-ROUTER (src/patches.cpp:57) fires: that is the free side landing
//      in the EXISTING host override of 0x821C2AB8, which DROPS the free
//      (src/patches.cpp:49: "overrides it, never chains, so a firing call
//      drops the free").  The console's free would actually reclaim; the
//      host's does not.  NAMED HERE, NOT HIDDEN.
// ===========================================================================

// The console's XTL allocator object -- the "bank".  MEASURED:
//   build/w788.log F389-XTLCHAIN: obj=[[r13]+28]=82830B18
//   build/w836.log: 64/64 F396-ALLOC-ENTER rows carry self=82830B18.
constexpr uint32_t kXtlTitleBank = 0x82830B18u;

// The bank's layout, from the guest's own dispatcher bodies (see above):
//   +4  : the allocator array; the selector r indexes it as (r+1).
constexpr uint32_t kXtlBankArrayOff = 4u;
// The allocator OBJECT's layout, from its own methods:
//   +4  : the first element of the pool;  +76 : the pool's capacity.
constexpr uint32_t kXtlAllocFirstOff = 4u;
constexpr uint32_t kXtlAllocCapOff = 76u;

// THE CVar. One variable, one reversal (rule 1a). DEFAULT ON: the physical
// pool exhaustion is the wall, and the delegation is the console's own path.
// `mcla_xtl_title_alloc=0` restores the previous physical-pool behaviour
// exactly.  Same shape as `mcla_phys_subpage` (src/kernel/heap.cpp:753-760).
inline bool XtlTitleAllocEnabled() {
  static const bool kEnabled = [] {
    const char *e = std::getenv("mcla_xtl_title_alloc");
    return e == nullptr || e[0] != '0';
  }();
  return kEnabled;
}

// The delegation counters.  UNGATED, so a soak can read the take rate as one
// number instead of inferring it from sampled rows (the F-646 lesson).
std::atomic<uint64_t> g_xtlTitleAllocDelegated{0};
std::atomic<uint64_t> g_xtlTitleAllocFallback{0};
std::atomic<uint64_t> g_xtlTitleAllocDisabled{0};
std::atomic<uint64_t> g_xtlTitleFreeDelegated{0};
std::atomic<uint64_t> g_xtlTitleFreeHostPath{0};

// Re-entrancy guard.  The delegated call runs GUEST code (the console's own
// allocator) from inside a host hook; if that code ever came back through the
// XTL thunk we would recurse.  One thread-local flag breaks the cycle by
// falling back to the physical-pool path, and it is counted.
thread_local bool g_xtlTitleBusy = false;

// The title's pool, read from the guest with the checked helpers only.
struct XtlTitlePool {
  uint32_t allocObj = 0;  // the bank array entry 0 (the allocator object)
  uint32_t first = 0;     // [alloc+4]
  uint32_t cap = 0;       // [alloc+76]
  uint32_t lo = 0;        // first + 16  -- the guest's own lower bound
  uint32_t hi = 0;        // first + cap  -- the guest's own upper bound
  bool ready = false;
};

// READY MEANS: the guest has actually registered a pool with the allocator
// the console's XTL path reaches.  Every field is read with ReadU32BE, which
// is range-checked and returns false without writing on a short read, so this
// can never fault and never guesses: an uninitialised allocator reads as
// NOT ready and the physical-pool fallback runs.
XtlTitlePool ReadXtlTitlePool() {
  XtlTitlePool p;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t obj = 0;
  if (!mem.ReadU32BE(kXtlTitleBank + kXtlBankArrayOff, &obj)) return p;
  if (obj == 0u || obj == 0xCDCDCDCDu) return p;
  uint32_t vt = 0, first = 0, cap = 0;
  if (!mem.ReadU32BE(obj + 0u, &vt)) return p;
  if (vt == 0u || vt == 0xCDCDCDCDu) return p;
  if (!mem.ReadU32BE(obj + kXtlAllocFirstOff, &first)) return p;
  if (!mem.ReadU32BE(obj + kXtlAllocCapOff, &cap)) return p;
  if (first == 0u || cap == 0u) return p;
  p.allocObj = obj;
  p.first = first;
  p.cap = cap;
  p.lo = first + 16u;   // 0x821C17AC: addi r10,r11,16
  p.hi = first + cap;   // 0x821C17BC: add  r11,r10,r11
  p.ready = true;
  return p;
}

} // namespace

PPC_FUNC(__xtl_alloc) {
  uint32_t align = ctx.r5.u32;
  if (align < 16 || (align & (align - 1)) != 0)
    align = 16;
  const uint32_t size = ctx.r4.u32;
  const uint32_t glr =
      g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;

  const uint64_t seen =
      g_xtlAllocSeen.fetch_add(1, std::memory_order_relaxed) + 1;

  // -------------------------------------------------------------------------
  // T43.28: THE CONSOLE SERVES THIS REQUEST OUT OF THE TITLE'S OWN ALLOCATOR.
  //
  // OLD (the defect this replaces), src/kernel/imports.cpp:397 before this
  // edit: `ctx.r3.u32 = GuestMemoryHeap::Instance().Alloc(size, align);`
  // -> src/kernel/memory.cpp:534 -> Heap::AllocPhysical -> the 512 MiB
  // console PHYSICAL pool, ONE PAGE PER CALL.  42,915 calls, 274.8 MiB
  // charged on top of the 299.5 MiB the title already owns (the measurement
  // is in the block above).
  //
  // NEW: the console's own dispatch, with the console's own ABI, read off
  // the guest's bytes (see the block above for every citation):
  //   r3 = 0x82830B18  the descriptor the guest's TLS slot 28 holds
  //   r4 = size        r5 = align      r6 = 0  (the thunk's own selector)
  // and 0x821C08F8 forwards r4/r5 to the allocator it selects, so the
  // allocator's method sees size/align unchanged.
  //
  // THE FALLBACK: if the title's allocator has not registered a pool yet, the
  // physical-pool path is KEPT (the console's pool is not the right answer
  // for a 46.5 MiB class, but refusing an early boot request is worse).
  // That window is REAL and MEASURED: the first XTL allocation is at
  // w821.log 13:42:28.640 and the title's first allocation is at
  // 13:42:28.677 -- 37 ms later.
  //
  // A REFUSAL BY THE TITLE'S OWN ALLOCATOR IS NOT FALLEN BACK ONTO THE POOL:
  // the console would return 0 there too, and falling back would re-create
  // the very blow-up this change removes.  The refusal is counted and named.
  // -------------------------------------------------------------------------
  bool viaTitle = false;
  if (!XtlTitleAllocEnabled()) {
    g_xtlTitleAllocDisabled.fetch_add(1, std::memory_order_relaxed);
  } else {
    const XtlTitlePool pool = ReadXtlTitlePool();
    if (pool.ready && !g_xtlTitleBusy) {
      g_xtlTitleBusy = true;
      // The nested call runs GUEST code.  lr and r1 are saved and restored
      // because the PPC contract says a called function preserves both, and
      // the recompiled bodies restore lr from r12 -- but the host must not
      // DEPEND on that for the frame it is standing in.
      const uint32_t savedLr = static_cast<uint32_t>(ctx.lr);
      const uint32_t savedSp = ctx.r1.u32;
      ctx.r3.u32 = kXtlTitleBank;  // the descriptor
      ctx.r4.u32 = size;           // the size
      ctx.r5.u32 = align;          // the alignment
      ctx.r6.u32 = 0;              // the selector the XTL thunk sets
      sub_821C08F8(ctx, base);     // the console's ALLOC dispatcher
      ctx.lr = savedLr;
      ctx.r1.u32 = savedSp;
      g_xtlTitleBusy = false;
      viaTitle = true;
      g_xtlTitleAllocDelegated.fetch_add(1, std::memory_order_relaxed);
      const uint64_t dn = g_xtlTitleAllocDelegated.load(std::memory_order_relaxed);
      if (dn <= 8u || (dn % 512u) == 0u) {
        MCLA_LOG_WARN(
            "XTL-TITLE-ALLOC #{} size={} align={} -> {:08X} bank={:08X} "
            "allocObj={:08X} pool={:08X}-{:08X} glr={:08X} seen={} delegated={} "
            "fallback={}",
            dn, size, align, ctx.r3.u32, kXtlTitleBank, pool.allocObj,
            pool.lo, pool.hi, glr, seen, dn,
            g_xtlTitleAllocFallback.load(std::memory_order_relaxed));
      }
    } else {
      g_xtlTitleAllocFallback.fetch_add(1, std::memory_order_relaxed);
      const uint64_t fn = g_xtlTitleAllocFallback.load(std::memory_order_relaxed);
      if (fn <= 8u || (fn % 512u) == 0u) {
        MCLA_LOG_WARN(
            "XTL-TITLE-FALLBACK #{} size={} align={} bank={:08X} ready={} "
            "busy={} seen={} delegated={} fallback={}",
            fn, size, align, kXtlTitleBank, pool.ready ? 1 : 0,
            g_xtlTitleBusy ? 1 : 0, seen,
            g_xtlTitleAllocDelegated.load(std::memory_order_relaxed), fn);
      }
    }
  }

  if (!viaTitle) {
    // Unchanged: the same call, the same ABI, the same return-into-r3.
    ctx.r3.u32 = mcla::kernel::GuestMemoryHeap::Instance().Alloc(size, align);
  }

  if (ctx.r3.u32 == 0) {
    // The console's value for "refused" is 0 and the console does not trap
    // here (the contract note above). So r3 is left 0, deliberately, and the
    // refusal is made visible instead of silent. House cadence: first 8, then
    // every 512th -- a per-call census is what made w38e.log 66% one message
    // shape (F-054). The running served/refused totals ride along so ONE row
    // answers "are allocations still being served, and how many were refused".
    const uint64_t refused =
        g_xtlAllocRefused.fetch_add(1, std::memory_order_relaxed) + 1;
    if (refused <= 8u || (refused % 512u) == 0u) {
      const uint32_t le = XtlGuestLastError();
      MCLA_LOG_WARN(
          "XTL-ALLOC-REFUSED #{} size={} align={} -> returned 0 (console value) "
          "glr={:08X} guestLastError={:#x} consoleFailurePath={} seen={} ok={} "
          "refused={} :: caller does not test r3, sub_821378B8 memcpy follows",
          refused, size, align, glr, le,
          (le == kConsoleOomLastError)
              ? "LATCHED-by-guest"
              : (le == kXtlLastErrorUnread ? "unread" : "not-latched"),
          seen, g_xtlAllocOk.load(std::memory_order_relaxed), refused);
    }
    return;
  }

  const uint64_t n =
      g_xtlAllocOk.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8u || (n % 512u) == 0u) {
    MCLA_LOG_WARN("XTL-ALLOC #{} size={} align={} -> {:08X} glr={:08X} seen={} "
                  "refused={}",
                  n, size, align, ctx.r3.u32, glr, seen,
                  g_xtlAllocRefused.load(std::memory_order_relaxed));
  }
}

// F-633: `__xtl_free` used to be `PPC_FUNC(__xtl_free) { ctx.r3.u32 = 1; }` --
// a body that does nothing and reports success. `build/w658.log` measured what
// that costs: HEAPLEAK-SUM arena=phys reaches nalloc=79,985 against nfree=15
// (freed=16.1MB frozen for the rest of the run), o1_free 1468.0 -> 366.8 ->
// 0.07 -> 0.0005 MB, and 83 printed
// `AllocPhysical: o1heapAllocate returned null` rows against a 1.494 GiB arena.
// It is now a real free. The contract below is READ OFF THE GUEST, not assumed.
//
// ---------------------------------------------------------------------------
// THE CONTRACT, FROM THE GUEST'S OWN BYTES (raw-byte rule, F-023:
// build/cache/mcla_pe.bin, file offset = VA - 0x82000000, big-endian).
//
// The title's XTL dispatch is ONE function block with TWO slots, wired once by
// boot_host.cpp:889-890 (alloc at +8, free at +12) and reached through the r13
// chain. Both thunks run the same prologue, so they decode as a pair and each
// one confirms the other:
//
//   alloc slot  VA 0x82130528 (raw 0x130528)
//     82130530  mr   r4,r3          <- arg0 (size) moves to r4
//     82130534  li   r6,0
//     82130538  li   r5,16          <- alignment
//     8213053C  lwzx r3,r10,r11     <- r3 = *(*(r13)+28), the ALLOC DESCRIPTOR
//     82130544  lwz  r8,8(r9)       <- slot +8
//     8213054C  bctr
//   => r3 = descriptor, r4 = SIZE, r5 = ALIGN -- exactly the three registers
//      __xtl_alloc above reads. That agreement is the cross-check.
//
//   free slot  VA 0x82130588 (raw 0x130588)
//     82130588  mr   r4,r3          <- arg0 (POINTER) moves to r4
//     8213058C  cmpli cr6,r4,0
//     82130590  blr  (bo=12)        <- NULL short-circuits IN THE GUEST
//     8213059C  lwzx r3,r10,r11     <- r3 = the SAME descriptor
//     821305A4  lwz  r8,12(r9)      <- slot +12
//     821305AC  bctr
//   => r3 = descriptor, r4 = POINTER TO FREE. **NO SIZE IS PASSED.**
//
// TWO CONSEQUENCES, both load-bearing:
//
// 1) r4, NOT r3, IS THE POINTER. r3 holds our TLS descriptor (0x8F202000,
//    boot_host.cpp:869). An implementation that freed ctx.r3 would be freeing
//    the host's own descriptor table. This is the single most dangerous
//    mistake available here and the guest bytes rule it out.
//
// 2) NO SIZE IS NEEDED, SO NO HEADER HAS TO BE INVENTED. The question "where
//    does the size come from" has the answer: nowhere.
//    GuestMemoryHeap::Free(uint32_t guestAddr, size_t size)
//    (src/kernel/memory.cpp:346) NEVER READS ITS size ARGUMENT -- it translates
//    and hands the pointer to g_userHeap.Free(ptr). The footprint is recovered
//    host-side from the o1heap fragment header 32 bytes below the pointer
//    (Heap::IsLiveAllocation -> probe.size, then AcctFree(kArenaPhys,
//    physicalHeap, probe.size) at heap.cpp:1286). So the alloc and free sides
//    already subtract the SAME unit -- the fragment footprint AcctAlloc added
//    (heap.cpp:1319) -- and inventing an allocation header would only create a
//    second, disagreeing size.
//
// NO REFERENCE IMPLEMENTATION EXISTS TO COPY. A recursive search of
// .research/xenia/src/xenia/kernel/xboxkrnl/ and .../xam/ for
// xtl/_xtl/Xtl/XTL returns ZERO hits: Xenia does not implement this export at
// all, and .research/XenonRecomp/ carries neither symbol. Xenia does implement
// the neighbouring ExAllocatePool/ExFreePool pair
// (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_memory.cc:598-607), but
// that is a SYSTEM pool with a different signature (ExFreePool(base_address),
// no descriptor, no alignment) and is NOT this export. So the contract above is
// derived from the guest alone.
//
// THE COUNTERPART QUESTION -- is this the free that pairs with the 79,985? YES,
// measured, not assumed. The heap's own site ring attributes the leaking
// allocations (heap.cpp:75-87 RecordSite, printed as last_site_rva/last_site_lr
// by heap.cpp:618-644):
//   * last_site_rva=0x24282a resolves to GuestMemoryHeap::Alloc+0x1a
//     (python tools/host_rva_resolve.py build/mcla.map 0x24282a). That names the
//     HOST frame, and on its own it proves nothing about __xtl_alloc -- dozens
//     of other callers reach GuestMemoryHeap::Alloc, including this file's own
//     XamSessionCreateHandle:187 and ~50 sites in gpu_device.cpp.
//   * last_site_lr=0x82137904 is what DOES pin it. That address is the
//     instruction immediately after `bl 82130528` in sub_821378B8 (a
//     strlen+1 string duplicator), i.e. the return address INTO the guest of a
//     call that is executing the XTL alloc thunk right now.
//   * Decisively: ALL 83 printed `o1heapAllocate returned null` rows carry
//     glr=0x82137904 (67) or glr=0x821C667C (16). 0x821C667C is likewise the
//     instruction after `bl 82130528`, this time in sub_821C6658. 100% of the
//     physical refusals are the XTL allocation path, not a host bookkeeping
//     path. And the 20 `bl 82130588` call sites in the guest are the matching
//     free side of the same table.
// So the leak is the XTL pair, and the 15 frees that did land came from
// unrelated host paths (8 printed PHYS-FREE rows, glr 8244EF00/8244E8A0/
// 8244DB68 -- note PHYS-FREE #1 and #2 print the SAME ptr 0x1c64ac380, i.e. the
// second was a double free the live probe refused).
//
// WHAT IS **NOT** ESTABLISHED, stated plainly per rule 1a: that making this free
// real stops the exhaustion. This is a citation plus a self-report, not a
// single-variable revert -- no build was run (the brief forbids it) and this
// working tree already differs from the last known-good by N files. The
// measurement that would settle it is a soak whose `XTL-FREE` rows show `ok=`
// rising and whose HEAPLEAK-SUM nfree climbs off 15.
//
// NOT plumbed, and named rather than faked: the realloc thunk at 0x82130550
// (slot +8, `mr r11,r3` / `mr r4,r11`) allocates a new block and NEVER calls the
// free slot, so it leaks by construction. It is a guest-side fact, out of scope
// for this function, and it is NOT accounted for in any number here.
namespace {

// F-633: the XTL free census. Deliberately separate from the heap's own
// PHYS-FREE rows: this one is measured at the ENTRY POINT, so a soak can tell
// frees ATTEMPTED from frees HONOURED, and a refusal is named with the exact
// probe reason rather than being a silent non-event.
std::atomic<uint64_t> g_xtlFreeSeen{0};
std::atomic<uint64_t> g_xtlFreeOk{0};
std::atomic<uint64_t> g_xtlFreeRej{0};
std::atomic<uint64_t> g_xtlFreeDescMismatch{0};

// F-646: THE DENSITY DEFECT, and why every count in this block is UNGATED while
// the per-event rows are not. Measured on build/w677.log (READ ONLY, 180 s,
// 137 MB): NINE `XTL-FREE` rows in the whole file. #1..#5 and #4096 are
// `ptr=00000000` refusals; #6..#8 are `-> HONOURED`. "The frees work" therefore
// rested on THREE rows, because the house cadence (first 8, then every 4096th)
// cannot meet the free rate: #1 at 11:40:00.828 and #4096 at 11:40:13.869 is
// 4,096 attempts in 13.041 s = 299/s, i.e. ~53,900 attempts in a 180 s run, so
// a 4096th-row cadence yields 13 of them. That is the whole falsifiability
// problem, and it is a SAMPLING problem, not an allocator problem.
//
// The fix is deliberately NOT a tighter per-event gate. At 299/s even 1-in-64
// is 842 rows (~194 KB of a 137 MB log) but 1-in-1 is gigabytes, and F-054 is
// the record of what a per-event census did to a soak (w38e.log: 616,824
// laundered firings = 66% of the file). The fix is: COUNT EVERY ATTEMPT AND
// EVERY REFUSAL UNGATED, and PRINT A RUNNING SUMMARY ROW, so the honoured rate
// is one number on one line instead of a quotient a reader has to compute from
// two counts sampled 4096 apart.
constexpr uint32_t kXtlFreeSumEvery = 64u;    // XTL-FREE-SUM cadence
constexpr uint32_t kXtlFreeSumFirst = 2u;     // ...and always at least one row
constexpr uint32_t kXtlFreeDetailCap = 256u;  // HONOURED detail rows, then 1-in-512
constexpr uint32_t kXtlFreeDetailAfter = 512u;
constexpr uint32_t kXtlFreeRejEvery = 512u;   // extra refusal rows on top of first 8

// F-646: refusal buckets, one per value of Heap::LiveProbe::Reason (heap.h:38-47,
// seven values, none defaulted away) plus one for a value this switch does not
// know -- whose non-zero count is itself a finding. `ok` is kept as a bucket
// because a REFUSAL carrying reason `ok` would mean the predicate and the
// counter disagree, which is worth seeing rather than silently absorbed.
enum XtlFreeWhy : size_t {
  kXtlWhyOk = 0,
  kXtlWhyNull,
  kXtlWhyOutOfArena,
  kXtlWhyMisaligned,
  kXtlWhyBadSize,
  kXtlWhyNotUsed,
  kXtlWhyBadPointers,
  kXtlWhyUnmapped,
  kXtlWhyCount
};

// The SAME seven strings `XtlFreeProbeReason` returned before, in one table, so
// the per-event `reason=` field and the summary's `rej_why[...]=` field cannot
// drift apart in spelling.
const char *const kXtlFreeWhyName[kXtlWhyCount] = {
    "ok",          "null",     "out-of-arena", "misaligned",
    "bad-size",    "not-used", "bad-pointers", "unknown"};

std::atomic<uint64_t> g_xtlFreeRejWhy[kXtlWhyCount];
// The three refusal SITES, so a run can separate "the guest passed a null
// pointer" from "the pointer did not translate" from "the live probe said no"
// -- which is a different question from WHICH probe reason fired.
std::atomic<uint64_t> g_xtlFreeRejNullGuard{0};
std::atomic<uint64_t> g_xtlFreeRejNoTranslate{0};
std::atomic<uint64_t> g_xtlFreeRejProbe{0};
std::atomic<uint64_t> g_xtlFreeDetail{0};  // HONOURED per-event rows already printed

int XtlFreeWhyIndex(Heap::LiveProbe::Reason r) {
  switch (r) {
    case Heap::LiveProbe::Reason::Ok: return kXtlWhyOk;
    case Heap::LiveProbe::Reason::Null: return kXtlWhyNull;
    case Heap::LiveProbe::Reason::OutOfArena: return kXtlWhyOutOfArena;
    case Heap::LiveProbe::Reason::Misaligned: return kXtlWhyMisaligned;
    case Heap::LiveProbe::Reason::BadSize: return kXtlWhyBadSize;
    case Heap::LiveProbe::Reason::NotUsed: return kXtlWhyNotUsed;
    case Heap::LiveProbe::Reason::BadPointers: return kXtlWhyBadPointers;
  }
  return kXtlWhyUnmapped;  // a value this switch does not know: count it, do not fold it
}

const char *XtlFreeProbeReason(Heap::LiveProbe::Reason r) {
  return kXtlFreeWhyName[XtlFreeWhyIndex(r)];
}

// F-646: THE ONE ROW THAT DECIDES IT. `attempted` is `seen`, incremented once per
// entry before anything else, so `honoured + refused` must equal it -- and
// `unaccounted` prints that difference instead of leaving it to the reader to
// infer. A non-zero `unaccounted` would mean an exit path classified nothing,
// which is a defect in THIS census and not in the allocator.
void XtlFreeSummary(uint64_t seen, uint32_t ptr, uint32_t desc) {
  const uint64_t ok = g_xtlFreeOk.load(std::memory_order_relaxed);
  const uint64_t rej = g_xtlFreeRej.load(std::memory_order_relaxed);
  const uint64_t accounted = ok + rej;
  const uint32_t glr =
      g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
  MCLA_LOG_WARN(
      "XTL-FREE-SUM attempted={} honoured={} refused={} unaccounted={} "
      "honoured_pct={:.4f} rej[below-4KiB]={} rej[no-translate]={} "
      "rej[probe]={} rej_why[ok]={} rej_why[null]={} rej_why[out-of-arena]={} "
      "rej_why[misaligned]={} rej_why[bad-size]={} rej_why[not-used]={} "
      "rej_why[bad-pointers]={} rej_why[unknown]={} descmismatch={} "
      "detail_rows={} last_ptr={:08X} last_desc={:08X} last_glr={:08X}",
      seen, ok, rej, seen >= accounted ? seen - accounted : 0ull,
      // T43.17 (2026-10-13): pct is over ATTEMPTED (seen), not accounted.
      // The old denominator (ok+rej) excluded unaccounted, overstating pct
      // whenever an exit path lands outside the two buckets. Same flaw
      // class as PHYS-FREE-SUM before its fix.
      seen ? (static_cast<double>(ok) * 100.0 /
              static_cast<double>(seen))
           : 0.0,
      g_xtlFreeRejNullGuard.load(std::memory_order_relaxed),
      g_xtlFreeRejNoTranslate.load(std::memory_order_relaxed),
      g_xtlFreeRejProbe.load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyOk].load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyNull].load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyOutOfArena].load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyMisaligned].load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyBadSize].load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyNotUsed].load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyBadPointers].load(std::memory_order_relaxed),
      g_xtlFreeRejWhy[kXtlWhyUnmapped].load(std::memory_order_relaxed),
      g_xtlFreeDescMismatch.load(std::memory_order_relaxed),
      g_xtlFreeDetail.load(std::memory_order_relaxed), ptr, desc, glr);
}
} // namespace

PPC_FUNC(__xtl_free) {
  // r3 = the allocator descriptor the guest loaded from *(r13)+28 (0x8F202000,
  // boot_host.cpp:869). r4 = THE POINTER. See the contract note above: the
  // pointer is r4, and no size is passed.
  const uint32_t desc = ctx.r3.u32;
  const uint32_t ptr = ctx.r4.u32;

  const uint64_t seen =
      g_xtlFreeSeen.fetch_add(1, std::memory_order_relaxed) + 1;

  // F-646: every exit below goes through `done`, so the running summary is
  // emitted on ALL of them -- honoured AND refused -- exactly once per attempt.
  // Without this the summary would exist only on the paths a reader cares
  // about, which is how "no rows" stays ambiguous between "no frees" and "not
  // sampled". The r3 value is the console contract's own and is unchanged by
  // this: the summary is pure accounting.
  const auto done = [&](uint32_t r3) {
    ctx.r3.u32 = r3;
    if (seen <= kXtlFreeSumFirst || (seen % kXtlFreeSumEvery) == 0u) {
      XtlFreeSummary(seen, ptr, desc);
    }
  };

  // The descriptor is ours by construction (boot_host.cpp:889-890), so a
  // mismatch means the guest is calling a DIFFERENT export through this slot.
  // Counted, never fatal: the pointer is in r4 either way, and refusing here
  // would convert a working free back into the leak this function exists to
  // remove. If the decoding above were wrong, r4 would hold the descriptor,
  // IsLiveAllocation would reject it as out-of-arena, and the free would degrade
  // to a counted refusal rather than a corrupted heap.
  if (desc != 0x8F202000u) {
    g_xtlFreeDescMismatch.fetch_add(1, std::memory_order_relaxed);
  }

  // -------------------------------------------------------------------------
  // T43.28: A POINTER THE TITLE'S ALLOCATOR HANDED OUT MUST GO BACK TO THE
  // TITLE'S ALLOCATOR.  The console's free thunk (0x82130588) reads the
  // method at [*descriptor + 12] = 0x821C09C8 (raw vtable word at
  // 0x820114C4+12), whose body walks the SAME allocator array at self+4,
  // asks each allocator [vtable+80] "is this pointer yours?", and on a hit
  // calls that allocator's own free.  Its ABI is r3 = the descriptor, r4 =
  // THE POINTER, and NO SIZE.
  //
  // THE PREDICATE IS THE GUEST'S OWN.  0x821C17A8 (the simple allocator's
  // vtable slot +80) is a pure range check:
  //   lwz r11,4(r3) ; addi r10,r11,16 ; cmplw cr6,r4,r10 ;
  //   lwz r10,76(r3) ; add r11,r10,r11 ; cmplw cr6,r11
  // i.e. "mine" == first+16 <= ptr < first+cap.  The host applies THAT test
  // before delegating, so the console's dispatcher can never reach its
  // "no owner" path -- 0x821BD618, whose fallback is the `b 0x821BD640`
  // SELF-LOOP, i.e. A HANG.  A pointer that fails the test is NOT the
  // title's, and keeps the host path below.
  //
  // NAMED CONSEQUENCE: the free lands in the EXISTING host override of
  // 0x821C2AB8 (src/patches.cpp:53-61), which is a census that DROPS the
  // free -- its own comment says so: "overrides it, never chains, so a firing
  // call drops the free".  So the console's reclaim does not happen here;
  // the observable is the POOL-ROUTER marker (src/patches.cpp:57), which
  // fires ZERO times in build/w821.log today.  That is a divergence from the
  // console and it is named, not hidden.
  // -------------------------------------------------------------------------
  if (XtlTitleAllocEnabled() && ptr != 0u) {
    const XtlTitlePool pool = ReadXtlTitlePool();
    if (pool.ready && ptr >= pool.lo && ptr < pool.hi) {
      const uint32_t savedLr = static_cast<uint32_t>(ctx.lr);
      const uint32_t savedSp = ctx.r1.u32;
      ctx.r3.u32 = kXtlTitleBank;  // the descriptor
      ctx.r4.u32 = ptr;           // THE POINTER
      sub_821C09C8(ctx, base);     // the console's FREE dispatcher
      ctx.lr = savedLr;
      ctx.r1.u32 = savedSp;
      const uint64_t dn =
          g_xtlTitleFreeDelegated.fetch_add(1, std::memory_order_relaxed) + 1;
      const uint64_t ok =
          g_xtlFreeOk.fetch_add(1, std::memory_order_relaxed) + 1;
      if (dn <= 8u || (dn % 512u) == 0u) {
        MCLA_LOG_WARN(
            "XTL-TITLE-FREE #{} ptr={:08X} bank={:08X} allocObj={:08X} "
            "pool={:08X}-{:08X} seen={} ok={} delegated={} hostpath={}",
            dn, ptr, kXtlTitleBank, pool.allocObj, pool.lo, pool.hi, seen, ok,
            dn, g_xtlTitleFreeHostPath.load(std::memory_order_relaxed));
      }
      done(1);
      return;
    }
    g_xtlTitleFreeHostPath.fetch_add(1, std::memory_order_relaxed);
  }

  // Guard the values the guest controls, by the same rules the heap itself uses,
  // before anything is translated or probed. No assert on a guest value, ever.
  if (ptr == 0 || ptr < 4096u) {
    g_xtlFreeRej.fetch_add(1, std::memory_order_relaxed);
    g_xtlFreeRejNullGuard.fetch_add(1, std::memory_order_relaxed);
    if (seen <= 8 || (seen % 4096) == 0 ||
        (g_xtlFreeRej.load(std::memory_order_relaxed) % kXtlFreeRejEvery) == 0) {
      MCLA_LOG_WARN("XTL-FREE #{} ptr={:08X} desc={:08X} -> refused: below the "
                    "4 KiB null guard (guest=0 or the PAGE_NOACCESS window) "
                    "rej={} (running tally on XTL-FREE-SUM)",
                    seen, ptr, desc,
                    g_xtlFreeRej.load(std::memory_order_relaxed));
    }
    done(0);  // 0 = NOT honoured. Never a success we did not earn.
    return;
  }

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  void *host = mem.Translate(ptr);
  if (host == nullptr) {
    g_xtlFreeRej.fetch_add(1, std::memory_order_relaxed);
    g_xtlFreeRejNoTranslate.fetch_add(1, std::memory_order_relaxed);
    if (seen <= 8 || (seen % 4096) == 0 ||
        (g_xtlFreeRej.load(std::memory_order_relaxed) % kXtlFreeRejEvery) == 0) {
      MCLA_LOG_WARN("XTL-FREE #{} ptr={:08X} desc={:08X} -> refused: not in the "
                    "4 GiB guest window rej={} (running tally on XTL-FREE-SUM)",
                    seen, ptr, desc,
                    g_xtlFreeRej.load(std::memory_order_relaxed));
    }
    done(0);
    return;
  }

  // Pre-validate with the heap's OWN predicate, so "honoured" is counted with
  // the same rule Heap::Free will apply rather than a second, weaker copy of
  // it. XTL blocks come from GuestMemoryHeap::Alloc -> g_userHeap.AllocPhysical
  // (src/kernel/memory.cpp:339), so they live in the PHYSICAL arena; the user
  // arena is probed second only for completeness. IsLiveAllocation is
  // [[nodiscard]] and cannot fault: it range-checks, alignment-checks, and then
  // reads a 32-byte fragment header it has already proved in bounds.
  //
  // F-646: TWO PROBE OBJECTS, NOT ONE. build/w677.log's `XTL-FREE` rows all read
  // `reason=out-of-arena` for addresses that heap.cpp's own F-645 note (the
  // "XTL-FREE refused every free it saw" block, anchored on the literal
  // "MEASURED, on build/w675.log") shows are INSIDE the pool. The cause is
  // visible in the call pair below: both `IsLiveAllocation` calls were handed
  // the SAME `probe`, and `IsLiveAllocation` starts with `probe = {}` -- so the
  // user-arena call OVERWROTE the physical arena's verdict. The user arena is
  // [0x20000, 0x7FEA0000), which makes every physical pointer out-of-arena
  // there, so the row reported the second probe and the first one's reason was
  // discarded. Same number of probe calls, same order, same short-circuit; only
  // the destination objects differ, so this is an instrumentation fix and not a
  // behaviour change.
  Heap::LiveProbe physProbe{};
  Heap::LiveProbe usrProbe{};
  const bool phys = g_userHeap.IsLiveAllocation(
      g_userHeap.physArenaBase, g_userHeap.physArenaSize, host, &physProbe);
  const bool usr =
      !phys && g_userHeap.IsLiveAllocation(g_userHeap.heapArenaBase,
                                           g_userHeap.heapArenaSize, host,
                                           &usrProbe);

  if (!phys && !usr) {
    // F-646: AND THE REASON ATTRIBUTED TO THE ARENA THE POINTER IS ACTUALLY IN.
    // `IsPhysicalArenaPtr` (heap.h:63-67) is the tree's own bounds test for
    // exactly this question and costs no probe call -- and it is TRUE in the
    // F-645 case, where the pointer is a physical one that the first
    // representation missed, which is precisely the case that was being
    // mislabelled. Both probes' reasons are printed on the row regardless, so a
    // reader is never worse informed than before.
    const Heap::LiveProbe::Reason fired =
        g_userHeap.IsPhysicalArenaPtr(host) ? physProbe.reason : usrProbe.reason;
    g_xtlFreeRej.fetch_add(1, std::memory_order_relaxed);
    g_xtlFreeRejProbe.fetch_add(1, std::memory_order_relaxed);
    g_xtlFreeRejWhy[XtlFreeWhyIndex(fired)].fetch_add(1,
                                                      std::memory_order_relaxed);
    if (seen <= 8 || (seen % 4096) == 0 ||
        (g_xtlFreeRej.load(std::memory_order_relaxed) % kXtlFreeRejEvery) == 0) {
      const uint32_t glr =
          g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
      MCLA_LOG_WARN(
          "XTL-FREE #{} ptr={:08X} desc={:08X} -> REFUSED reason={} "
          "phys_why={} usr_why={} bytes kept, r3=0 (not honoured) "
          "arena=phys/{} glr={:08X} rej={}",
          seen, ptr, desc, XtlFreeProbeReason(fired),
          XtlFreeProbeReason(physProbe.reason),
          XtlFreeProbeReason(usrProbe.reason), phys ? 1 : 0, glr,
          g_xtlFreeRej.load(std::memory_order_relaxed));
    }
    done(0);
    return;
  }

  // Hand it back. GuestMemoryHeap::Free's size argument is unused
  // (src/kernel/memory.cpp:346) and is passed as 0 to say so rather than to
  // invent a size. The real accounting is the heap's own: Heap::Free re-probes
  // and, on success, AcctFree subtracts probe.size from liveBytes -- the same
  // fragment footprint AcctAlloc added (heap.cpp:1319 vs :1286), so the two
  // sides subtract one unit, not two.
  mem.Free(ptr, 0);

  const uint64_t ok = g_xtlFreeOk.fetch_add(1, std::memory_order_relaxed) + 1;
  // F-646: DENSITY, BOUNDED. The old gate was `first 8, then every 4096th`,
  // and at 299 attempts/s (XTL-FREE #1 at 11:40:00.828 -> #4096 at
  // 11:40:13.869 in build/w677.log, 4,096 in 13.041 s) that is 13 rows in a
  // 180 s run -- three of them HONOURED, which is the entire evidence base for
  // "the frees work". The new gate prints the first kXtlFreeDetailCap (256)
  // honoured frees in full and then one per kXtlFreeDetailAfter (512), so:
  //   * honoured == 3   (w677's measured value) -> 3 rows, i.e. no change: there
  //     is nothing to sample, which the summary row now STATES as honoured=3
  //     rather than leaving it inferred from an absent row.
  //   * honoured == 2,000 -> 256 + floor((2000-256)/512) = 259 rows.
  // The cap is what makes densifying safe against F-054: this branch cannot
  // exceed ~256 + honoured/512 rows no matter what the run does, so the log
  // cannot grow without bound. The exact count is reported on every
  // XTL-FREE-SUM row as `detail_rows=`, so the sample size is never a guess.
  const bool detailRow = ok <= kXtlFreeDetailCap ||
                         (ok > kXtlFreeDetailCap &&
                          (ok % kXtlFreeDetailAfter) == 0u);
  if (detailRow) {
    g_xtlFreeDetail.fetch_add(1, std::memory_order_relaxed);
    const Heap::LiveProbe& okProbe = phys ? physProbe : usrProbe;
    const uint32_t glr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    MCLA_LOG_WARN("XTL-FREE #{} ptr={:08X} desc={:08X} -> HONOURED frag={:#x} "
                  "arena={} seen={} ok={} rej={} descmismatch={} glr={:08X} "
                  "detail={}/{}",
                  seen, ptr, desc, okProbe.size, phys ? "phys" : "user", seen,
                  g_xtlFreeOk.load(std::memory_order_relaxed),
                  g_xtlFreeRej.load(std::memory_order_relaxed),
                  g_xtlFreeDescMismatch.load(std::memory_order_relaxed), glr,
                  g_xtlFreeDetail.load(std::memory_order_relaxed), ok);
  }
  done(1);
  // 1 = honoured, 0 = refused. NO measured caller reads this: all 20 guest
  // `bl 82130588` sites immediately clobber r3 (e.g. 0x82137b3c `stw r27,0(r24)`,
  // 0x82138a60 `mr r3,r26`) and none branches on it. It is reported honestly for
  // the log and the gate rather than assumed to be a success. `done(1)` is the
  // assignment -- it sets ctx.r3.u32 = 1 and then prints the summary row.
}

// ---- File metadata queries (shared impls, called from the PPC_FUNC wrappers
// below; these were silent fake-success stubs which made packfile loading fail
// with "Cannot load archive" before a single byte was ever read) ----

static uint32_t NtQueryInformationFileImpl(uint32_t handle,
                                           uint32_t ioStatusAddr,
                                           uint32_t bufferAddr, uint32_t length,
                                           uint32_t infoClass) {
  // X_FILE_STANDARD_INFORMATION (5): AllocationSize(8) EndOfFile(8)
  // NumberOfLinks(4) DeletePending(1) Directory(1)
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  KernelObject *obj = nullptr;
  if (handle != GUEST_INVALID_HANDLE_VALUE && IsKernelObject(handle)) {
    KernelObject *o = GetKernelObject(handle);
    if (o && o->IsValid())
      obj = o;
  }
  FileObject *fileObj =
      (obj && obj->IsValid()) ? dynamic_cast<FileObject *>(obj) : nullptr;

  if (infoClass == 34 && bufferAddr != 0 && length >= 52 && fileObj) {
    // X_FILE_NETWORK_OPEN_INFORMATION (NT NETWORK_OPEN_INFORMATION):
    // Creation/LastAccess/LastWrite/ChangeTime (8 each), AllocationSize(8),
    // EndOfFile(8), FileAttributes(4). The packfile loader gates on
    // EndOfFile being the REAL archive size.
    const uint64_t fileSize = fileObj->fileHandle.size;
    (void)mem.WriteU64BE(bufferAddr + 0, 0);         // CreationTime
    (void)mem.WriteU64BE(bufferAddr + 8, 0);         // LastAccessTime
    (void)mem.WriteU64BE(bufferAddr + 16, 0);        // LastWriteTime
    (void)mem.WriteU64BE(bufferAddr + 24, 0);        // ChangeTime
    (void)mem.WriteU64BE(bufferAddr + 32, fileSize); // AllocationSize
    (void)mem.WriteU64BE(bufferAddr + 40, fileSize); // EndOfFile
    (void)mem.WriteU32BE(bufferAddr + 48, 0x20);     // FILE_ATTRIBUTE_ARCHIVE
    if (ioStatusAddr) {
      (void)mem.WriteU32BE(ioStatusAddr, STATUS_SUCCESS);
      (void)mem.WriteU32BE(ioStatusAddr + 4, 52);
    }
    MCLA_LOG_INFO("NtQueryInformationFile: NETWORK_OPEN_INFO size={}",
                  fileSize);
    return STATUS_SUCCESS;
  }

  if (infoClass == 5 && bufferAddr != 0 && length >= 24 && fileObj) {
    const uint64_t fileSize = fileObj->fileHandle.size;
    (void)mem.WriteU64BE(bufferAddr + 0, fileSize);
    (void)mem.WriteU64BE(bufferAddr + 8, fileSize);
    (void)mem.WriteU32BE(bufferAddr + 16, 1);
    (void)mem.WriteU16BE(bufferAddr + 20, 0);
    if (ioStatusAddr) {
      (void)mem.WriteU32BE(ioStatusAddr, STATUS_SUCCESS);
      (void)mem.WriteU32BE(ioStatusAddr + 4, 24);
    }
    return STATUS_SUCCESS;
  }

  // Xenia semantics: never fake-success with zeros - the game branches on
  // the returned data, so unsupported classes must fail loudly.
  if (infoClass != 5 && infoClass != 34) {
    MCLA_LOG_WARN(
        "NtQueryInformationFile: class={} -> STATUS_INVALID_INFO_CLASS",
        infoClass);
    if (ioStatusAddr) {
      (void)mem.WriteU32BE(ioStatusAddr, STATUS_INVALID_INFO_CLASS);
      (void)mem.WriteU32BE(ioStatusAddr + 4, 0);
    }
    return STATUS_INVALID_INFO_CLASS;
  }

  MCLA_LOG_WARN("NtQueryInformationFile: class={} len={} handleValid={} -> "
                "INFO_LENGTH_MISMATCH",
                infoClass, length, fileObj != nullptr);
  if (ioStatusAddr) {
    (void)mem.WriteU32BE(ioStatusAddr, STATUS_INFO_LENGTH_MISMATCH);
    (void)mem.WriteU32BE(ioStatusAddr + 4, 0);
  }
  return STATUS_INFO_LENGTH_MISMATCH;
}

// NtQueryVolumeInformationFile / NtQueryDirectoryFile: typed impls live below
// (near NtReadFile) and are GUEST_FUNCTION_HOOKed at the bottom of this file.

PPC_FUNC(__imp__NtQueryInformationFile) {
  // r3=handle, r4=ioStatus, r5=buffer, r6=length, r7=infoClass
  ctx.r3.u32 = NtQueryInformationFileImpl(ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                                          ctx.r6.u32, ctx.r7.u32);
}

void VdHSIOCalibrationLock() { LOG_UTILITY("!!! STUB !!!"); }

void KeCertMonitorData() { LOG_UTILITY("!!! STUB !!!"); }

void XexExecutableModuleHandle() { LOG_UTILITY("!!! STUB !!!"); }

void ExLoadedCommandLine() { LOG_UTILITY("!!! STUB !!!"); }

void KeDebugMonitorData() { LOG_UTILITY("!!! STUB !!!"); }

void ExThreadObjectType() { LOG_UTILITY("!!! STUB !!!"); }

void KeTimeStampBundle() { LOG_UTILITY("!!! STUB !!!"); }

void XboxHardwareInfo() { LOG_UTILITY("!!! STUB !!!"); }

void XGetVideoMode() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t XGetGameRegion() {
  if (Config::Language == ELanguage::Japanese)
    return 0x0101;

  return 0x03FF;
}

// MCLA task dispatcher posts XAM msg 251 through a strict
// create-handle -> ref-by-handle -> start-IO sequence; BOTH calls must
// return 0 or the post is skipped and the main thread parks forever in
// Function_824E5350 (ppc_recomp.158.cpp:27368-27420, 159.cpp:1015+,
// soak evidence 2026-08-23: ring put cursor frozen).
uint32_t XamSessionCreateHandle(be<uint32_t> *handleOut) {
  if (!handleOut)
    return STATUS_INVALID_PARAMETER;

  // Identity-handle model: handle = guest VA of a small session object.
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t obj = mem.Alloc(16, 8);
  if (obj == 0)
    return STATUS_NO_MEMORY;

  (void)mem.WriteU32BE(obj, 0);
  (void)mem.WriteU32BE(obj + 4, 0);
  handleOut->set(obj);
  return STATUS_SUCCESS;
}

uint32_t XamSessionRefObjByHandle(uint32_t handle, be<uint32_t> *objectOut) {
  if (!objectOut)
    return STATUS_INVALID_PARAMETER;
  if (handle == 0 || handle == 0xFFFFFFFF)
    return STATUS_INVALID_HANDLE;

  // Identity handles: the referenced object IS the handle's guest VA.
  // Validate readability before handing it back as a pointer.
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t probe = 0;
  if (!mem.ReadU32BE(handle, &probe))
    return STATUS_INVALID_HANDLE;

  objectOut->set(handle);
  return STATUS_SUCCESS;
}

uint32_t XMsgStartIORequest(uint32_t App, uint32_t Message,
                            XXOVERLAPPED *lpOverlapped, void *Buffer,
                            uint32_t szBuffer) {
  // XMsgStartIORequest census probe (Lead 3)
  {
    static std::atomic<uint32_t> s_xmsgCalls{0};
    const uint32_t n = s_xmsgCalls.fetch_add(1) + 1;
    if (n <= 100) {
      MCLA_LOG_INFO(
          "XMSG-IO #{} App={:08X} Msg={:08X} ovl={:08X} buf={:08X} sz={:08X} "
          "lr={:08X}",
          n, App, Message,
          lpOverlapped
              ? static_cast<uint32_t>(reinterpret_cast<uintptr_t>(lpOverlapped))
              : 0,
          static_cast<uint32_t>(reinterpret_cast<uintptr_t>(Buffer)), szBuffer,
          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  (void)App;
  (void)Message;
  (void)Buffer;

  if (lpOverlapped) {
    // Complete synchronously and UNCONDITIONALLY: MCLA's app-task
    // dispatcher (sub_824E37E0 case 9) posts event-less overlappeds
    // (hEvent=0, pCompletionRoutine=0 - ppc_recomp.159.cpp:1100-1116)
    // then hot-polls Error for != STATUS_IO_INCOMPLETE (997). A no-op
    // here parks the main thread in Function_824E5350 forever with the
    // ring put cursor frozen (2026-08-23 soak evidence).
    lpOverlapped->Error.set(STATUS_SUCCESS);
    lpOverlapped->Length.set(szBuffer);

    // pCompletionRoutine: MCLA's known consumers poll Error instead of
    // using callbacks; guest-dispatch callback wiring deferred until a
    // consumer demands it (no invented behavior).

    if (lpOverlapped->hEvent) {
      XKEVENT *event =
          (XKEVENT *)mcla::kernel::GuestMemoryHeap::Instance().Translate(
              lpOverlapped->hEvent);
      if (event) {
        QueryKernelObject<Event>(*event)->Set();
      }
    }
  }

  return STATUS_SUCCESS;
}

// ---------------------------------------------------------------------------
// THE XAM SIGN-IN / CONTENT FAMILY -- F-609. All five of these fabricated state
// and reported success. Each is handled on its own evidence below; the shared
// fact first.
//
// THE HOST HAS NO USER PROFILE AND NO CONTENT STORE. That is not a judgement
// about the code, it is a census of this tree: no profile object, no content
// manager, nothing to read a saved game from. Xenia's versions all answer from
// `kernel_state()->user_profile()` or
// `kernel_state()->content_manager()`; there is nothing here for them to answer
// from, so every "success" below was a value invented for the guest's benefit.
//
// ERROR CONSTANTS, all from .research/xenia/src/xenia/xbox.h:
//   X_ERROR_SUCCESS               0x00000000  xbox.h:86
//   X_ERROR_FILE_NOT_FOUND        0x00000002  xbox.h:87
//   X_ERROR_PATH_NOT_FOUND        0x00000003  xbox.h:88
//   X_ERROR_ACCESS_DENIED         0x00000005  xbox.h:89
//   X_ERROR_DEVICE_NOT_CONNECTED  0x0000048F  xbox.h:100
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// ==== SYNTH-PROFILE: the one synthetic user in this host ====================
// F-609, decision (b) HONEST RETENTION. The whole family (XamUserGetSigninState,
// XamUserGetSigninInfo, XamShowSigninUI, XamUserReadProfileSettings) reads its
// answer from the single constant below, and every call that uses it emits
// `SYNTH-PROFILE fabricated`.
//
// WHY RETAINED INSTEAD OF REFUSED. Three measurements, not a preference:
//
// 1. THERE IS NO REAL PROFILE. Census of src/ for user_profile|xuid|gamertag|
//    signin_state returns exactly two hits, both in src/kernel/xbox.h:300,302 --
//    and those are the *output* struct's field declarations, not a store. There
//    is no profile, no account record, no config file read at boot. So "answer
//    from real data" is not available; the alternative is not "more honest", it
//    is just differently honest.
//
// 2. THE OLD VALUE WAS ALREADY WRONG FOR THE GUEST'S OWN CHECK. The pre-change
//    code returned `true` == 1. The guest's call site at 0x8244A6D4
//    (sub_8244A688) tests `cmpi cr6,r3,2` / `bc bo=12 -> 0x8244A6E8`
//    (ppc_disasm.py 0x8244A688). 1 != 2, so the old code ALREADY failed that
//    test and already fell into `li r3,1245; b 0x8244A74C`. There is therefore
//    no known-good "signed in" answer being disturbed here: the fabrication was
//    never being read as signed-in at the site's own gate. Dropping it to 0
//    changes nothing at 0x8244A6D4; it changes 3 of the other 4 sites (see
//    below), which is the whole risk.
//
// 3. NO BUILD WAS RUN AND NONE MAY BE. The (a) precondition -- "the title
//    depends on a signed-in answer to boot" -- cannot be established from here,
//    and this working tree differs from HEAD by 51 files (AGENTS.md rule 1a), so
//    no single-variable revert is possible either. Choosing (a) would be a blind
//    boot-risk change to a blocked build. Partial removal is the one
//    unacceptable outcome, so the family is retained *as a set* and made
//    visible, which is what the native-only charter permits for a fake that is
//    deliberately and visibly kept.
//
// THE BEHAVIOURAL DELTA IS REAL AND MEASURED (ppc_xrefs.py calls 0x827BD314 ->
// 5 sites; ppc_disasm.py at each). Returning 1 vs 0 changes the guest's road at
// 3 of them:
//   0x82457644 / 0x82457674 (sub_82457608) -- a slot-0..3 scan testing
//     `cmpi cr6,r3,1`. 1 matched slot 0 on the first iteration -> `li r3,1245`
//     + `stw 0,0(r29)`. 0 matches nothing -> 4 iterations -> `b 0x82457680`,
//     which calls a DIFFERENT import, `__imp__XamUserCheckPrivilege`.
//   0x82750BD4 (sub_82750B60) -- `mr r29,r3` then `cmpi cr6,r29,0` /
//     `bc bo=12 -> 0x82750D24`. 0 takes the 0x82750D24 state-machine arm that 1
//     skipped.
//   0x824E6CD8+0xC -- `xori r8,r3,0001` at 0x824E6CF4 inverts bit 0, so 1 gave
//     false and 0 gives true.
// Unchanged: 0x8244A6D4 (tests ==2, both fail). Unproven: 0x824E6D38 does
// `addi r11,r3,-2` (a -2 test, like 0x8244A6D4) but the following op31:26 at
// 0x824E6D40 is not decoded by our disassembler, so it is not claimed either way.
//
// *** REMOVAL TRIGGER. Delete kXamSynthProfile and make every consumer below
// *** return the truthful no-user answer (0 for GetSigninState; X_E_NO_SUCH_USER
// *** for GetSigninInfo, per xam_user.cc:93) AS ONE SINGLE COMMIT, the moment
// *** EITHER of these becomes true:
// ***   (i)  a real user profile store exists in this tree to answer from -- a
// ***        profile object, an account record, or a config file read at boot
// ***        (today's census: none), or
// ***   (ii) a soak shows the game REACHES THE MENU AND PLAYS with this block
// ***        deleted, i.e. the dependency the (a) route assumed turns out not to
// ***        exist.
// The marker `SYNTH-PROFILE fabricated` is the census handle for (ii): a soak
// with zero `SYNTH-PROFILE` lines is running in the honest-refusal world; a
// soak WITH them is running on the synthetic user. The two must never be mixed --
// that partial state is what this block exists to make impossible.
// ---------------------------------------------------------------------------
namespace {
// Deliberately constant and deliberately visible. Not synthesised per call, and
// not derived from anything: a constant string the game can print is better
// than a per-call one, because a per-call value would look like a real profile.
struct XamSyntheticProfile {
  uint64_t xuid;
  uint32_t signinState;
  const char *name;
};
constexpr XamSyntheticProfile kXamSynthProfile = {0xB13EBABEBABEBABEull, 1u,
                                                  "SWA"};

// One emitter for the whole family, so no consumer can grow its own private
// lie. `refusals` counts calls that took the truthful no-user path, separately
// from `attempts`, so a soak can watch refusals rise if this is ever made real.
struct XamSynthCounters {
  std::atomic<uint64_t> attempts{0};
  std::atomic<uint64_t> refusals{0};
};
XamSynthCounters g_xamSynthSigninState, g_xamSynthSigninInfo,
    g_xamSynthSigninUI, g_xamSynthProfileSettings;

void XamSynthEmit(const char *consumer, XamSynthCounters &c, uint64_t n,
                  const char *detail) {
  if (n <= 8 || (n % 200) == 0) {
    const uint64_t refusals =
        c.refusals.load(std::memory_order_relaxed);
    MCLA_LOG_WARN("SYNTH-PROFILE fabricated [{}] #{} attempts={} refusals={}: "
                  "xuid={:016X} signinState={} name=\"{}\" -- this host has NO "
                  "user profile (census: src/ has no profile store); {} "
                  "REMOVAL TRIGGER: delete kXamSynthProfile as ONE commit when "
                  "a real profile store exists, or when a soak reaches the menu "
                  "with this block deleted. glr={:08X}",
                  consumer, n, n, refusals, kXamSynthProfile.xuid,
                  kXamSynthProfile.signinState, kXamSynthProfile.name, detail,
                  g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
  }
}
} // namespace

// XamUserGetSigninState -- F-609, now a consumer of kXamSynthProfile.
//
// THE CONTRACT: .research/xenia/src/xenia/kernel/xam/xam_user.cc:60-71 returns
// 0 for any user_index >= 4, and for slots 1..3; only slot 0 ever reads
// kernel_state()->user_profile()->signin_state(). We have no profile object, so
// there is nothing to ask -- which is why the answer is a declared constant
// rather than a lookup, and why the `user_index < 4` bound is honoured
// explicitly (see the refusals path below) instead of being ignored.
//
// WHAT CHANGED HERE, AND IT IS A REVERT OF THE PARTIAL REMOVAL. This function
// had just been changed to `return 0` while its two siblings still fabricated,
// leaving the family inconsistent -- the exact state the task forbids. It is
// back to the synthetic signin state (1), which is also what the guest's own
// slot-scan at 0x82457648 tests for. The genuinely new part is not the value:
// it is that the value now has a name, a single source, a marker, and a written
// removal trigger, and that the attempt/refusal split is countable.
uint32_t XamUserGetSigninState(uint32_t userIndex) {
  const uint64_t n = g_xamSynthSigninState.attempts.fetch_add(
                         1, std::memory_order_relaxed) +
                     1;
  // xam_user.cc:62 notes "Yield, as some games spam this" -- this is a
  // high-frequency poll, so the census is what makes the poll affordable.
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("XAM-SIGNIN-STATE #{} userIndex={} -> {} (SYNTHETIC signed in)",
                  n, userIndex, kXamSynthProfile.signinState);
  }
  // The xam_user.cc:64 bound, made visible: slot 0 is the only slot that could
  // ever hold a profile, so every other slot is the truthful no-user answer and
  // is counted as a refusal rather than answered from the synthetic profile.
  if (userIndex != 0u) {
    const uint64_t m = g_xamSynthSigninState.refusals.fetch_add(
                           1, std::memory_order_relaxed) +
                       1;
    if (m <= 8 || (m % 200) == 0) {
      MCLA_LOG_WARN("XAM-SIGNIN-STATE #{} slot {} -> 0 (NO SUCH USER): "
                    "xam_user.cc:64-68 only ever reads a profile for slot 0, and "
                    "this host has none. refusals={}",
                    n, userIndex, m);
    }
    return 0u;
  }
  XamSynthEmit("XamUserGetSigninState", g_xamSynthSigninState, n,
               "slot 0 answered from the constant, not from a profile.");
  return kXamSynthProfile.signinState;
}

uint32_t XamGetSystemVersion() {
  // Return 2.0.17559.0 as the system version (similar to Xenia)
  return 0x00021755;
}

// XamContentDelete -- F-609, refused. Was `return 0;` (ERROR_SUCCESS) for a
// delete of nothing: the title was told a saved game had been destroyed.
//
// Xenia: .research/xenia/src/xenia/kernel/xam/xam_content.cc:393-406 returns
// `content_manager()->DeleteContent(content_data)`, and when the content is not
// present that resolves to X_ERROR_PATH_NOT_FOUND (xam_content.cc:320). We
// have no content manager, so "not present" is not a special case -- it is the
// only case, and 0x00000003 (xbox.h:88) is the correct answer for it.
//
// REACHABILITY: ABSENT from generated/ppc_xenon/ppc_func_mapping.cpp. The hook
// below is dead wiring; the marker is insurance, not measurement.
uint32_t XamContentDelete(uint32_t userIndex, void *deviceId,
                          XCONTENT_DATA *contentData,
                          XXOVERLAPPED *overlapped) {
  (void)userIndex;
  (void)deviceId;
  (void)contentData;
  // The overlapped is deliberately NOT completed. Completing it would tell the
  // guest the delete finished; it did not, and there is nothing to delete.
  (void)overlapped;
  static std::atomic<uint64_t> s_seen{0};
  const uint64_t n = s_seen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("XAM-CONTENT-DELETE #{} -> X_ERROR_PATH_NOT_FOUND "
                  "(0x00000003): no content store on this host, so nothing was "
                  "deleted and the overlapped was NOT completed (was "
                  "ERROR_SUCCESS) glr={:08X}",
                  n,
                  g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
  }
  return 0x00000003u; // X_ERROR_PATH_NOT_FOUND
}

// XamContentGetCreator -- F-609, refused with Xenia's own else branch. It wrote
// isCreator=1 and xuid=0xB13EBABEBABEBABE -- a fabricated 64-bit identity the
// title could store and later compare -- and returned 0.
//
// Xenia: .research/xenia/src/xenia/kernel/xam/xam_content.cc:294-321. The
// not-a-saved-game arm is `*is_creator_ptr = 0; *creator_xuid_ptr = 0;`
// (xam_content.cc:313-317) and the content-does-not-exist arm is
// `result = X_ERROR_PATH_NOT_FOUND` (xam_content.cc:320). We are in that arm
// unconditionally, so BOTH of Xenia's lines are reproduced rather than one of
// them faked. Writing 0/0 is not merely a refusal: it is the truthful pair of
// answers, and it is strictly better than leaving the guest's own uninitialised
// stack values in the out-parameters.
//
// REACHABILITY: ABSENT from the import table; the hook is dead wiring.
uint32_t XamContentGetCreator(uint32_t userIndex,
                              const XCONTENT_DATA *contentData,
                              be<uint32_t> *isCreator, be<uint64_t> *xuid,
                              XXOVERLAPPED *overlapped) {
  (void)userIndex;
  (void)contentData;
  (void)overlapped;
  if (isCreator)
    *isCreator = 0; // xam_content.cc:313-314
  if (xuid)
    *xuid = 0;      // xam_content.cc:315-317
  static std::atomic<uint64_t> s_seen{0};
  const uint64_t n = s_seen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("XAM-CONTENT-CREATOR #{} -> isCreator=0 xuid=0 + "
                  "X_ERROR_PATH_NOT_FOUND (0x00000003): no content store, so "
                  "nobody created anything (was isCreator=1 with a fabricated "
                  "xuid 0xB13EBABEBABEBABE) glr={:08X}",
                  n,
                  g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
  }
  return 0x00000003u; // X_ERROR_PATH_NOT_FOUND
}

// XamContentGetDeviceState -- F-609, refused, AND THE SIGNATURE WAS WRONG.
// Was `uint32_t XamContentGetDeviceState() { return 0; }`: no parameters, so
// the hook read no arguments at all, and ERROR_SUCCESS for a device query.
//
// Xenia: .research/xenia/src/xenia/kernel/xam/xam_content_device.cc:78-89
//   auto device_info = GetDummyDeviceInfo(device_id);
//   if (device_info == nullptr) { ... return X_ERROR_DEVICE_NOT_CONNECTED; }
// The "no such device" answer is X_ERROR_DEVICE_NOT_CONNECTED = 0x0000048F
// (xbox.h:100). There is no content device attached to this host, so that is
// the true answer -- and it is the one Xenia itself returns in exactly our
// situation, which is what makes it a refusal rather than an invention.
//
// The signature is now `(uint32_t deviceId, void *overlapped)` per
// xam_content_device.cc:78-79, so the guest's arguments are actually read and
// reported. The overlapping struct is NOT completed: there is no device state
// to report, and completing it would assert that there is.
//
// REACHABILITY: this one IS imported (0x827BD3C4) and ppc_xrefs.py finds 2 call
// sites, so the guest may well reach it. The refusal may therefore be
// guest-visible where the previous ERROR_SUCCESS was not.
uint32_t XamContentGetDeviceState(uint32_t deviceId, void *overlapped) {
  (void)overlapped;
  static std::atomic<uint64_t> s_seen{0};
  const uint64_t n = s_seen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("XAM-CONTENT-DEVICE #{} deviceId={:08X} -> "
                  "X_ERROR_DEVICE_NOT_CONNECTED (0x0000048F): no content device "
                  "on this host (was ERROR_SUCCESS; the hook also read no "
                  "arguments at all, the signature took none) glr={:08X}",
                  n, deviceId,
                  g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
  }
  return 0x0000048Fu; // X_ERROR_DEVICE_NOT_CONNECTED
}

// XamUserGetSigninInfo -- F-609, now a consumer of kXamSynthProfile.
//
// THE CONTRACT: .research/xenia/src/xenia/kernel/xam/xam_user.cc:85-102
//   if (!info) return X_E_INVALIDARG;                       // :87-89
//   memset(info, 0, sizeof(X_USER_SIGNIN_INFO));            // :91
//   if (user_index) return X_E_NO_SUCH_USER;                // :92-94
//   info->xuid         = user_profile->xuid();              // :97
//   info->signin_state = user_profile->signin_state();      // :98
//   copy_truncating(info->name, user_profile->name(), ...); // :99-100
//   return X_E_SUCCESS;                                     // :101
// The SHAPE here was already Xenia's and is unchanged: null-check, zero-fill,
// NO_SUCH_USER for a non-zero slot, SUCCESS for slot 0. The only thing that
// was fabricated is the *source* of the three fields on :97-100 -- Xenia reads
// them from a profile, we read them from kXamSynthProfile. That is the whole
// lie, and it is now one named constant instead of three inline literals.
//
// WHY THE SUCCESS IS THE LOAD-BEARING PART. This is the call whose return the
// guest actually gates on: at 0x8275CCA4 (sub_8275CC98) it does
// `bl 827BDC94` / `cmpi cr0,r3,0` / `bc bo=12 -> 0x8275CCB8`, and the
// success arm is where the info struct is read. Refusing here would make the
// title return 0 at 0x8275CCB0 immediately and never look at the profile. So
// if this family is ever removed, THIS function is the one that must change
// first, and it must change together with XamUserGetSigninState.
//
// THE NAME IS A CONSTANT, NOT SYNTHESISED. "SWA" is a single fixed string; it
// is not generated per call and is not derived from anything, so a soak sees
// one unchanging value. That is deliberate: a constant is visibly a constant,
// whereas a per-call synthesised gamertag would be indistinguishable from a real
// profile and would be the worse of the two. A constant string the game may
// print to the user is a known cost of this block and is called out here
// deliberately rather than hidden in a literal.
uint32_t XamUserGetSigninInfo(uint32_t userIndex, uint32_t flags,
                              XUSER_SIGNIN_INFO *info) {
  const uint64_t n = g_xamSynthSigninInfo.attempts.fetch_add(
                         1, std::memory_order_relaxed) +
                     1;
  if (!info) {
    // xam_user.cc:87-89. Counted as a refusal: nothing was fabricated.
    g_xamSynthSigninInfo.refusals.fetch_add(1, std::memory_order_relaxed);
    MCLA_LOG_WARN("XAM-SIGNIN-INFO #{} -> ERROR_INVALID_PARAMETER (null info) "
                  "glr={:08X}",
                  n, g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
    return ERROR_INVALID_PARAMETER;
  }
  // xam_user.cc:91 -- the zero-fill happens for every slot, including the ones
  // that then refuse, so a refused call still leaves a well-defined struct
  // rather than the guest's uninitialised stack.
  memset(info, 0, sizeof(*info));
  if (userIndex != 0u) {
    // xam_user.cc:92-94.
    const uint64_t m = g_xamSynthSigninInfo.refusals.fetch_add(
                           1, std::memory_order_relaxed) +
                       1;
    if (m <= 8 || (m % 200) == 0) {
      MCLA_LOG_WARN("XAM-SIGNIN-INFO #{} slot {} -> 0x00000525 "
                    "ERROR_NO_SUCH_USER (zero-filled per xam_user.cc:91) "
                    "refusals={}",
                    n, userIndex, m);
    }
    return 0x00000525; // ERROR_NO_SUCH_USER
  }
  (void)flags; // Xenia also ignores it (xam_user.cc:86).
  info->xuid = kXamSynthProfile.xuid;            // was 0xB13EBABEBABEBABE literal
  info->SigninState = kXamSynthProfile.signinState; // was 1 literal
  strncpy(info->Name, kXamSynthProfile.name, sizeof(info->Name) - 1);
  info->Name[sizeof(info->Name) - 1] = '\0'; // was strcpy, which could overrun
  XamSynthEmit("XamUserGetSigninInfo", g_xamSynthSigninInfo, n,
               "the three fields Xenia reads from user_profile() are constants.");
  return 0; // X_ERROR_SUCCESS, as xam_user.cc:101
}

// XamShowSigninUI -- F-609. THIS WAS NOT MERELY A LIE: IT WAS AN EMPTY BODY
// WHERE THE REAL API HAS SIDE EFFECTS, AND XENIA SAYS TITLES BLOCK ON THEM.
//
// THE CONTRACT: .research/xenia/src/xenia/kernel/xam/xam_user.cc:518-529
//   dword_result_t XamShowSigninUI_entry(dword_t unk, dword_t unk_mask) {
//     // To fix game modes that display a 4 profile signin UI (even if playing
//     // alone): XN_SYS_SIGNINCHANGED
//     kernel_state()->BroadcastNotification(0x0000000A, 1);
//     // Games seem to sit and loop until we trigger this notification:
//     // XN_SYS_UI (off)
//     kernel_state()->BroadcastNotification(0x00000009, 0);
//     return X_ERROR_SUCCESS;
//   }
// The old body enqueued nothing and logged "auto-bypass", so a title that
// waits on XN_SYS_SIGNINCHANGED / XN_SYS_UI waits forever. This now performs
// both of Xenia's notifications for real: XamNotifyEnqueueEvent
// (src/kernel/xam.cpp:113-122) walks the live listener list and appends to each
// subscribed listener's queue, which is a real host side effect consumed by the
// guest through XNotifyGetNext (src/kernel/xam.cpp:124). This is a real
// implementation of a real API contract, not a substitute for one -- the
// decision NOT to display UI remains synthetic and is labelled as such.
//
// RISK, STATED: this ADDS a side effect the previous body did not have. It is
// deliberately low-risk because the mechanism is already in this boot path --
// XamShowDeviceSelectorUI calls the same helper at 0x827BCDA4 with id 9
// (XamNotifyEnqueueEvent(9, true/false), imports.cpp:703-705), so id 9 has
// already been broadcast to these listeners by an existing hook. The guest's
// only call site is the tail-call thunk at 0x82131C18, reached from 0x82272D50
// (ppc_xrefs.py calls 0x82131C18 -> 1 site), which sets r3=1 and discards the
// return; no branch there depends on it.
//
// SIGNATURE: Xenia returns dword_result_t (:518). This returned void, which
// under PPC_FUNC/HostToGuestFunction (src/kernel/function.h, GUEST_FUNCTION_HOOK)
// leaves r3 holding whatever the guest last put there -- the caller at 0x82272D50
// leaves 1 in r3, so the guest has been reading a leaked 1 where Xenia returns
// X_ERROR_SUCCESS. Returning 0 explicitly is a real fix with a measured site,
// not a behaviour gamble. The two Xenia parameters (unk, unk_mask) are not
// added: ignoring extra register arguments is not a fabrication, and adding
// them would change the hook's read pattern for no measured gain.
uint32_t XamShowSigninUI() {
  const uint64_t n = g_xamSynthSigninUI.attempts.fetch_add(
                         1, std::memory_order_relaxed) +
                     1;
  if (n <= 20 || (n % 100) == 0) {
    MCLA_LOG_INFO("XAM-CENSUS[SigninUI] #{:04} lr={:08X}", n,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }
  // xam_user.cc:524 -- XN_SYS_SIGNINCHANGED, value 1.
  XamNotifyEnqueueEvent(0x0000000A, 1);
  // xam_user.cc:527 -- XN_SYS_UI off, value 0.
  XamNotifyEnqueueEvent(0x00000009, 0);
  XamSynthEmit("XamShowSigninUI", g_xamSynthSigninUI, n,
               "no UI is displayed; the two XN_SYS_* notifications Xenia sends "
               "are sent for real instead.");
  return 0; // X_ERROR_SUCCESS, xam_user.cc:528 (was: void, r3 left leaked)
}

uint32_t XamShowDeviceSelectorUI(uint32_t userIndex, uint32_t contentType,
                                 uint32_t contentFlags, uint64_t totalRequested,
                                 be<uint32_t> *deviceId,
                                 XXOVERLAPPED *overlapped) {
  XamNotifyEnqueueEvent(9, true);
  if (deviceId) *deviceId = 1;
  XamNotifyEnqueueEvent(9, false);
  return 0;
}

void XamShowDirtyDiscErrorUI() {
  // Don't show UI, just return - let boot continue
  MCLA_LOG_INFO("XamShowDirtyDiscErrorUI called (suppressed)");

  // Dump the guest call chain so we can find which media check routed us
  // here. EABI frames: back chain at [sp], saved LR at [sp+4].
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint64_t lr = g_ppcContext ? g_ppcContext->lr : 0;
  uint32_t sp = g_ppcContext ? g_ppcContext->r1.u32 : 0;
  for (int depth = 0; depth < 16; ++depth) {
    MCLA_LOG_INFO("  dirty-disc chain[{}]: lr=0x{:08X} sp=0x{:08X}", depth,
                  static_cast<uint32_t>(lr), sp);
    uint32_t nextSp = 0;
    uint32_t nextLr = 0;
    if (sp == 0 || !mem.ReadU32BE(sp, &nextSp) ||
        !mem.ReadU32BE(sp + 4, &nextLr))
      break;
    if (nextSp <= sp || (nextSp & 3) != 0)
      break;
    lr = nextLr;
    sp = nextSp;
  }
  spdlog::default_logger()->flush();
}

void XamEnableInactivityProcessing() {
  // No-op - inactivity processing not needed for headless boot
}

void XamResetInactivity() {
  // No-op
}

uint32_t XamShowMessageBoxUIEx(uint32_t userIndex, uint32_t flags, void *title,
                                void *text, uint32_t buttons,
                                uint32_t defaultButton, uint32_t *result,
                                XXOVERLAPPED *overlapped) {
  static std::atomic<uint32_t> s_census{0};
  const uint32_t n = s_census.fetch_add(1) + 1;
  if (n <= 20 || (n % 100) == 0) {
    MCLA_LOG_INFO("XAM-CENSUS[MsgBoxUIEx] #{:04} user={} flags=0x{:X} lr={:08X}", n,
                  userIndex, flags,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }
  (void)userIndex;
  (void)flags;
  (void)title;
  (void)text;
  (void)buttons;
  (void)defaultButton;
  (void)overlapped;
  if (result)
    *result = 1; // First button
  return 0;
}

void XamLoaderTerminateTitle() {
  // No-op - don't terminate
  MCLA_LOG_INFO("XamLoaderTerminateTitle called");
  spdlog::default_logger()->flush();
}

void XamGetExecutionId() {
  // No-op - execution ID not needed
}

void XamLoaderLaunchTitle() {
  // No-op - don't launch another title
}

// XamLoaderMediaGetInfo -- F-609, refused. It fabricated an XAM_MEDIA_INFO
// record -- MediaType = 0x0C (XAM_MEDIA_TYPE_GAME_DVD), everything else zero --
// told the title it was running from a game DVD, and returned ERROR_SUCCESS.
//
// TWO DEFECTS, not one. The second is the worse one and the brief did not name
// it: the function SIGNATURE takes `(uint32_t mediaId, void *infoBuffer)` and
// then IGNORES `infoBuffer` entirely, writing 16 bytes to
// `g_ppcContext->r4.u32` instead (the old line 647). So even the fabrication
// was not going where the caller asked -- it was writing to a raw register,
// and a guest that passed anything else got a 16-byte write to an address it
// never supplied. The parameter is now actually used, and the buffer is
// written with NOTHING.
//
// THE STATUS: X_ERROR_DEVICE_NOT_CONNECTED (0x0000048F, xbox.h:100), the same
// honest code XamContentGetDeviceState above uses and the one Xenia returns
// when there is no device to describe (xam_content_device.cc:80-89). There is
// no DVD, no media, and no loader media state on this host. ERROR_SUCCESS would
// assert a disc that does not exist.
//
// REACHABILITY: ABSENT from generated/ppc_xenon/ppc_func_mapping.cpp, the
// guest's static import table, so the hook below is dead wiring today. That is
// why removing the 16-byte fabrication is low risk -- but the fabrication was
// writing to a register the caller did not control, so it was a live
// wild-write hazard for any future caller too.
uint32_t XamLoaderMediaGetInfo(uint32_t mediaId, void *infoBuffer) {
  // NOTHING is written to infoBuffer. Not zeroed, not filled: the honest
  // answer carries no media record, and a zeroed record would be a record.
  (void)infoBuffer;
  static std::atomic<uint64_t> s_seen{0};
  const uint64_t n = s_seen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("XAM-MEDIA-INFO #{} mediaId={:08X} -> "
                  "X_ERROR_DEVICE_NOT_CONNECTED (0x0000048F): no media on this "
                  "host, 0 bytes written to the info buffer (was "
                  "ERROR_SUCCESS plus a fabricated XAM_MEDIA_TYPE_GAME_DVD "
                  "record written to r4 rather than to the caller's buffer) "
                  "glr={:08X}",
                  n, mediaId,
                  g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
  }
  return 0x0000048Fu; // X_ERROR_DEVICE_NOT_CONNECTED
}

uint32_t XamLoaderGetDvdTrayState() {
  // Xbox 360 DVD tray state. Must return CLOSED (0) for valid boot.
  return 0; // XAM_LOADER_DVD_TRAY_STATE_CLOSED
}

uint32_t XGetLanguage() { return (uint32_t)Config::Language; }

uint32_t XGetAVPack() {
  // Returns the A/V pack type. 3 = HDMI (widescreen/HD).
  // For 1280x720, return 3 (HDMI).
  return 3;
}

// Forward declaration so NtOpenFile can forward to it. Defined below, in this
// same file, with this exact signature.
uint32_t NtCreateFile(be<uint32_t> *FileHandle, uint32_t DesiredAccess,
                      XOBJECT_ATTRIBUTES *Attributes,
                      XIO_STATUS_BLOCK *IoStatusBlock, uint64_t *AllocationSize,
                      uint32_t FileAttributes, uint32_t ShareAccess,
                      uint32_t CreateDisposition, uint32_t CreateOptions);

// ---------------------------------------------------------------------------
// NtOpenFile -- FIXED, 2026-09-29 (integration stream). F-609 PORT BATCH.
//
// WAS: `void NtOpenFile() { LOG_UTILITY("!!! STUB !!!"); }`. That was not an
// inert stub, it was a LIVE DEFECT, and it is the reason this function is
// handled here rather than swept up with the other 63:
//
//   * GUEST_FUNCTION_STUB / a `void` hook body leaves r3 EQUAL TO THE INCOMING
//     r3 (function.h:496-499: the void arm calls the host function and returns
//     without touching the context at all).
//   * The guest therefore received its OWN FIRST ARGUMENT -- the stack address
//     of its handle out-parameter, e.g. 0x8EFFFxxx -- back in r3 where an
//     NTSTATUS belongs. That value is large and POSITIVE.
//   * All three guest call sites then test the return as an NTSTATUS and skip
//     the error branch, because `cmpwi r3,0 / blt` is false for a positive
//     value. MEASURED, one site each:
//        generated/ppc_xenon/ppc_recomp.82.cpp:10752-10755 (lr 0x8245FB74)
//        generated/ppc_xenon/ppc_recomp.82.cpp:11550-11553 (lr 0x824600E8)
//        generated/ppc_xenon/ppc_recomp.82.cpp:11753-11756 (lr 0x82460220)
//   * Each of those three proceeds to `lwz r3,<out>(r1)` -- the handle out
//     parameter, which the void body never wrote -- and feeds that
//     UNINITIALISED STACK WORD into NtDeviceIoControlFile (whose own call sites
//     are ppc_recomp.82.cpp:10786 and :10851, in the first of these three
//     functions). One stack word of garbage became a file handle.
//
// The fix is the signature, and the signature comes from the reference rather
// than from convenience. Xenia
// .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:173-182:
//
//   dword_result_t NtOpenFile_entry(
//       lpdword_t handle_out, dword_t desired_access,
//       pointer_t<X_OBJECT_ATTRIBUTES> object_attributes,
//       pointer_t<X_IO_STATUS_BLOCK> io_status_block, dword_t open_options) {
//     return NtCreateFile_entry(
//         handle_out, desired_access, object_attributes, io_status_block,
//         nullptr, 0, 0, static_cast<uint32_t>(xe::vfs::FileDisposition::kOpen),
//         open_options);
//   }
//
// So the return type is dword_result_t -- an NTSTATUS in r3 -- and the body is a
// forward to NtCreateFile with the disposition forced to kOpen
// (enum value 1, .research/xenia/src/xenia/vfs/entry.h:51). That is exactly
// what this does, against this tree's own NtCreateFile, which already returns a
// real STATUS and already writes a real kernel handle via
// `FileHandle->set(kernelHandle)`. No second open path was invented.
//
// ARITY, MEASURED, WITH THE DIVERGENCE NAMED. The guest sets SIX registers
// before the call in all three sites (e.g. ppc_recomp.82.cpp:10735-10749:
// r3=out, r4=0x1000003, r5=attrs, r6=IOSB, r7=0, r8=24). Xenia's entry takes
// FIVE and does not consume the sixth, so this host also takes five and reads
// r3..r7. Stated rather than hidden: the guest's r8 (24 at :10738, 16417 at
// :11536) is IGNORED here. That divergence is behaviourally inert in this tree
// and not only because of Xenia -- this file's own NtCreateFile already voids
// AllocationSize, FileAttributes, ShareAccess, CreateDisposition and
// CreateOptions (its `(void)` lines), so a 5-argument and a 9-argument forward
// produce identical results here. The measurable gain is the one that matters:
// a real status in r3 and a real handle in the out-parameter.
// ---------------------------------------------------------------------------
uint32_t NtOpenFile(be<uint32_t> *FileHandle, uint32_t DesiredAccess,
                    XOBJECT_ATTRIBUTES *Attributes,
                    XIO_STATUS_BLOCK *IoStatusBlock, uint32_t OpenOptions) {
  // Census, house cadence. The `disp=1` is the kOpen this function FORCES and
  // is not the guest's value; the real disposition argument is the sixth
  // register, which the reference does not pass either.
  {
    static std::atomic<uint32_t> s_census{0};
    const uint32_t n = s_census.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 20 || (n % 100) == 0) {
      MCLA_LOG_INFO("NFS-CENSUS[Open] #{:04} disp=1 opts=0x{:X} access=0x{:X} "
                    "lr={:08X}",
                    n, OpenOptions, DesiredAccess,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u));
    }
  }
  // kOpen == 1 (.research/xenia/src/xenia/vfs/entry.h:51). AllocationSize
  // nullptr, FileAttributes 0, ShareAccess 0 -- the reference's own arguments.
  return NtCreateFile(FileHandle, DesiredAccess, Attributes, IoStatusBlock,
                      /*AllocationSize=*/nullptr, /*FileAttributes=*/0,
                      /*ShareAccess=*/0, /*CreateDisposition=*/1,
                      /*CreateOptions=*/OpenOptions);
}

void RtlInitAnsiString(XANSI_STRING *destination, char *source) {
  const uint16_t length = source ? static_cast<uint16_t>(strlen(source)) : 0;

  destination->Length.set(length);
  destination->MaximumLength.set(length + 1);
  destination->Buffer = xpointer<char>(source);
}

uint32_t NtCreateFile(be<uint32_t> *FileHandle, uint32_t DesiredAccess,
                      XOBJECT_ATTRIBUTES *Attributes,
                      XIO_STATUS_BLOCK *IoStatusBlock, uint64_t *AllocationSize,
                      uint32_t FileAttributes, uint32_t ShareAccess,
                      uint32_t CreateDisposition, uint32_t CreateOptions) {
  // NtCreateFile census
  {
    static std::atomic<uint32_t> s_census{0};
    const uint32_t n = s_census.fetch_add(1) + 1;
    if (n <= 20 || (n % 100) == 0) {
      MCLA_LOG_INFO("NFS-CENSUS[Create] #{:04} disp={} opts=0x{:X} lr={:08X}", n,
                    CreateDisposition, CreateOptions,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }
  (void)DesiredAccess;
  (void)FileAttributes;
  (void)ShareAccess;
  (void)CreateDisposition;
  (void)CreateOptions;
  (void)AllocationSize;

  if (!FileHandle || !Attributes || !IoStatusBlock) {
    return 0xC000000D; // STATUS_INVALID_PARAMETER
  }

  // Get the object name from attributes
  XANSI_STRING *name = Attributes->Name.get();
  if (!name || !name->Buffer) {
    IoStatusBlock->Status.set(0xC0000034); // STATUS_OBJECT_NAME_INVALID
    return 0xC0000034;
  }

  // Read the ANSI string from guest memory
  char guestPath[260];
  uint16_t length = name->Length.get();
  if (length >= sizeof(guestPath))
    length = sizeof(guestPath) - 1;

  void *srcPtr =
      mcla::kernel::GuestMemoryHeap::Instance().Translate(name->Buffer.ptr);
  if (!srcPtr) {
    IoStatusBlock->Status.set(0xC0000005); // STATUS_ACCESS_VIOLATION
    return 0xC0000005;
  }

  memcpy(guestPath, srcPtr, length);
  guestPath[length] = '\0';

  // Open file via VFS
  std::string virtualPath = mcla::vfs::GuestPathToVirtual(guestPath);
  MCLA_LOG_INFO("NtCreateFile: '{}' -> '{}'", guestPath, virtualPath);

  // Probe for .bik movie files
  if (strstr(virtualPath.c_str(), ".bik") ||
      strstr(virtualPath.c_str(), ".BIK")) {
    MCLA_LOG_INFO("BIK MOVIE OPEN: '{}' -> '{}'", guestPath, virtualPath);
  }

  mcla::vfs::RpfVirtualFileSystem &vfs =
      mcla::vfs::RpfVirtualFileSystem::Instance();
  mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fileHandle;
  if (!vfs.OpenFile(virtualPath, fileHandle)) {
    // Raw device opens (\Device\Harddisk0\partition0 etc) have no VFS
    // backing. The boot validation loop treats a failed open as fatal, so
    // hand back an empty pseudo-file instead.
    constexpr auto startsWithDevice = [](const char *p) {
      return std::strncmp(p, "\\Device\\", 8) == 0 ||
             std::strncmp(p, "/Device/", 8) == 0;
    };
    const bool isRawDevice = startsWithDevice(guestPath);
    if (!isRawDevice) {
      MCLA_LOG_WARN("NtCreateFile: FAILED '{}' (guest '{}') -> "
                    "STATUS_OBJECT_NAME_NOT_FOUND",
                    virtualPath, guestPath);
      IoStatusBlock->Status.set(0xC0000034); // STATUS_OBJECT_NAME_NOT_FOUND
      return 0xC0000034;
    }
    MCLA_LOG_INFO("NtCreateFile: raw device '{}' -> empty pseudo-file",
                  guestPath);
    fileHandle = mcla::vfs::RpfVirtualFileSystem::OpenFileHandle{};
    fileHandle.virtual_path = virtualPath;
    fileHandle.size = 0;
    fileHandle.position = 0;
  }

  // Create kernel file object - MUST live in the guest physical heap so the
  // identity handle (its guest VA) round-trips through Translate(). Plain
  // `new` yields host pointers that MapVirtual cannot represent.
  auto *fileObj2 = CreateKernelObject<FileObject>(std::move(fileHandle));
  uint32_t kernelHandle = GetKernelHandle(fileObj2);
  // Publish the object in the identity map, the same two steps
  // CreateRegisteredKernelObject performs (xdm.h:131-135). This call site was
  // the one CreateKernelObject product that never registered, and that is what
  // left the resolver unable to tell this host object from guest memory: see
  // the long note at the signature proof in ResolveKernelObjectSafe, which is
  // why it needed a discriminator that is not a pointer comparison - for this
  // object Translate(kernelHandle) IS fileObj2, so no address test can tell
  // them apart, and an unregistered entry is by definition indistinguishable
  // from a guest page.
  //
  // The two steps are both load-bearing and are both already the shape of the
  // existing template, so no new symbol and no layout change:
  //   * `identityHdrAddr` is what DestroyKernelObject (xdm.cpp:12-13) erases on,
  //     so without it the entry would outlive the object and a recycled handle
  //     could resolve to freed memory.
  //   * the Type byte is stored verbatim as the ctor left it; nothing here
  //     rewrites header.Type, so no caller can observe a different Type than
  //     before. `GetKernelObject` is unaffected: its TryQueryKernelObject probe
  //     compares the map's Type against the byte at +0 of the object, which for
  //     a vptr-bearing host object is the low byte of the vptr, not
  //     header.Type, so that probe still misses and still returns the same
  //     pointer it returned before this entry existed.
  fileObj2->identityHdrAddr = kernelHandle;
  {
    std::lock_guard guard{g_kernelLock};
    WrapperIdentityMap()[kernelHandle] = {fileObj2, fileObj2->header.Type};
  }
  FileHandle->set(kernelHandle);
  MCLA_LOG_INFO("NtCreateFile: '{}' opened, handle={:08X}", virtualPath,
                kernelHandle);

  IoStatusBlock->Status.set(STATUS_SUCCESS);
  IoStatusBlock->Information.set(1); // FILE_OPENED

  return STATUS_SUCCESS;
}

uint32_t NtClose(uint32_t handle) {
  if (handle == GUEST_INVALID_HANDLE_VALUE)
    return 0xFFFFFFFF;

  if (IsKernelObject(handle)) {
    KernelObject *obj = GetKernelObject(handle);
    MCLA_LOG_INFO("NtClose: handle={:08X} valid={}", handle,
                  obj ? obj->IsValid() : false);
    if (obj && obj->IsValid()) {
      // Try to close VFS file if it's a FileObject
      FileObject *fileObj = dynamic_cast<FileObject *>(obj);
      if (fileObj) {
        mcla::vfs::RpfVirtualFileSystem::Instance().CloseFile(
            fileObj->fileHandle);
      }
      DestroyKernelObject(obj);
    }
    // Handles we don't recognize as host wrappers (raw guest structs the
    // game treats as handles) are simply ignored - closing them must not
    // fault or tear down guest memory.
    return 0;
  } else {
    return 0;
  }
}

// ---------------------------------------------------------------------------
// NtSetInformationFile -- F-609, REFUSED HONESTLY, per info class.
//
// Was: `uint32_t NtSetInformationFile(handle, ioStatus, buffer, length,
// infoClass) { (void)x5; if (ioStatus) ioStatus->Status.set(STATUS_SUCCESS);
// return STATUS_SUCCESS; }` -- STATUS_SUCCESS for EVERY class and EVERY handle,
// and it wrote that success into the guest's own IO_STATUS_BLOCK so the guest
// could not tell.
//
// The brief's instruction was "only claim success for the classes actually
// handled and refuse the rest". MEASURED: this function handles ZERO classes.
// The comment it used to carry -- "Common info classes: FilePositionInformation
// (14), FileEndOfFileInformation (20) For now, return success" -- named two
// classes and implemented neither; not a single byte of `buffer` was ever
// written for any class. So there is no "handled" subset to carve out and the
// refusal is total.
//
// THE STATUS: STATUS_INVALID_INFO_CLASS (0xC0000003), already defined at
// src/kernel/xbox.h:444-445. That is precisely the real kernel's answer for an
// information class the driver does not implement, so it is not an invention
// -- it is the correct code for "this class is not one I handle". It also
// carries the useful information, because the class NUMBER is in the log, so
// the next pass learns which class the title actually wanted and can implement
// exactly that one. STATUS_NOT_IMPLEMENTED would claim the request is
// malformed; STATUS_INVALID_HANDLE would claim the handle is bad, and the
// handle may well be a real VFS FileObject.
//
// `Information` is set to 0 alongside the status. Xenia's failure path
// (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:419-422) zeroes it,
// and a class we did not apply moved no bytes.
//
// NOT SIGNALLED, for the same reason as NtWriteFile: no completion event is Set
// for an information class that was not applied.
// ---------------------------------------------------------------------------
namespace {
std::atomic<uint64_t> g_nfsSetInfoSeen{0};
std::atomic<uint64_t> g_nfsSetInfoRefused{0};
// Class -> how many times the title asked for it. Bounded at 32 entries so a
// guest cannot grow this table; an unseen class is folded into "other".
constexpr uint32_t kSetInfoClassSlots = 32;
std::atomic<uint64_t> g_nfsSetInfoByClass[kSetInfoClassSlots];
} // namespace

uint32_t NtSetInformationFile(uint32_t handle, XIO_STATUS_BLOCK *ioStatus,
                              void *buffer, uint32_t length,
                              uint32_t infoClass) {
  (void)buffer;
  (void)length;

  const uint64_t seen =
      g_nfsSetInfoSeen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (infoClass < kSetInfoClassSlots) {
    g_nfsSetInfoByClass[infoClass].fetch_add(1, std::memory_order_relaxed);
  }
  g_nfsSetInfoRefused.fetch_add(1, std::memory_order_relaxed);

  if (seen <= 8 || (seen % 200) == 0) {
    const uint32_t glr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    MCLA_LOG_WARN(
        "NFS-SETINFO #{} h={:08X} class={} len={} -> REFUSED "
        "STATUS_INVALID_INFO_CLASS (0xC0000003): this function implements NO "
        "class (was STATUS_SUCCESS for every class and handle, with nothing "
        "written). Information=0, completion event NOT signalled. seen={} "
        "refused={} glr={:08X}",
        seen, handle, infoClass, length, seen,
        g_nfsSetInfoRefused.load(std::memory_order_relaxed), glr);
  }

  if (ioStatus) {
    ioStatus->Status.set(STATUS_INVALID_INFO_CLASS);
    ioStatus->Information.set(0);
  }
  return STATUS_INVALID_INFO_CLASS;
}

// FscSetCacheElementCount -- F-609, refused. Was `return 0;`, i.e.
// ERROR_SUCCESS for a call that changed nothing: the title was told its file
// system cache had been resized to a count we never applied.
//
// STATUS: ERROR_INVALID_FUNCTION (0x00000001), the Win32 code for "this
// function is not implemented by this device/driver", which is the true state
// of affairs. Xenia does not implement this export at all.
//
// REACHABILITY, so the next session does not re-derive it: ABSENT from
// generated/ppc_xenon/ppc_func_mapping.cpp, the guest's static import table.
// The GUEST_FUNCTION_HOOK below is dead wiring. Signature note preserved: this
// body declares no parameters, so the hook reads no arguments at all -- if the
// export ever becomes reachable that is the first thing to fix, and the reason
// the guest's requested count is not in the marker.
uint32_t FscSetCacheElementCount() {
  static std::atomic<uint64_t> s_seen{0};
  const uint64_t n = s_seen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("FSC-CACHECOUNT #{} -> ERROR_INVALID_FUNCTION (0x00000001): "
                  "not implemented, cache element count NOT changed (was "
                  "ERROR_SUCCESS with nothing done) glr={:08X}",
                  n,
                  g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
  }
  return 0x00000001u; // ERROR_INVALID_FUNCTION
}

// ============================================================================
// HOST IRQL MODEL + THE CONSOLE'S APC DELIVERY POINT (2026-10-21, fix_irq2)
// ============================================================================
//
// WHAT THE GUEST DOES -- the oracle is the guest's OWN bytes (build/cache/
// mcla_pe.bin, decoded with tools/ppc_disasm.py), not a doc:
//
//  * The guest's own spinlock wrappers RAISE the IRQL *before* they look at
//    the lock's recursion depth, and SAVE the value the raise RETURNED into
//    the lock struct's +12 byte:
//        0x823EAD08  bl 0x827BD514      ; __imp__KeRaiseIrqlToDpcLevel
//        0x823EAD10  mr r29,r3          ; r29 = the RETURNED (old) IRQL
//        0x823EAD9C  stb r29,12(r31)   ; lock+12 = the old IRQL
//    (the lock struct is at 0x828CD950: `lis r11,828D` + `addi r31,r11,-9904`)
//  * The release path READS IT BACK and hands it to the lowering export:
//        0x823EACE0  lbz r31,12(r3)    ; the saved old IRQL
//        0x823EACF0  bl 0x827BD544      ; __imp__KeReleaseSpinLockFromRaisedIrql
//        0x823EACF4  mr r3,r31
//        0x823EACF8  bl 0x827BD524      ; __imp__KfLowerIrql(old)
//    => the value KeRaiseIrqlToDpcLevel RETURNS is EXACTLY the value the guest
//       will later hand to KfLowerIrql.  The old host returned a constant 0
//       from the raise (imports.cpp:8993 before this change) and ignored the
//       lowering (imports.cpp:8995), so the guest's saved-IRQL byte was
//       permanently 0 and every lowering was a no-op.
//  * The same shape is in the guest's other two wrappers: 0x823EB5E0 (raise
//    0x823EB600 / save 0x823EB640 / lower 0x823EB6DC) and 0x823EE918 (raise
//    0x823EE92C / save 0x823EE968 / lower 0x823EE9F0).
//  * A RECURSIVE acquire re-raises (the raise precedes the depth check) but
//    does NOT rewrite the saved byte -- it RE-READS it (0x823EB648
//    `lbz r28,12(r31)`) -- so the OUTERMOST saved IRQL is the one restored.
//    The host's model has to agree with that or the levels drift.
//
// WHERE THE IRQL LIVES -- MEASURED, and the task's premise is REFUTED:
//  The task brief said "the guest's own IRQL byte is at [r13+?]".  It is not.
//  Scanning EVERY r13-relative load/store in build/cache/mcla_pe.bin with the
//  PROJECT's field layout (opcode = i>>26, RA = (i>>16)&31, d = s16(i&0xFFFF)
//  -- the layout tools/ppc_disasm.py uses; the usual "opcode in bits 0..5"
//  layout decodes this image into garbage) gives, inside the guest's kernel
//  (0x823E0000..0x82440000), ONLY:
//        lwz +0x100  (TEB pointer)         8 sites
//        lbz +0x10C  (CPU number byte)    11 sites
//  and nothing else.  Image-wide the surviving r13-relative BYTE accesses are
//  +0x10C (12 sites) plus one word at 0x829BD8DC which is DATA (the words
//  around it decode to NOT-DECODED).  There is NO current-IRQL byte in the
//  guest's KPCR in this image: the guest's kernel round-trips the IRQL VALUE
//  through the lock struct's +12 byte and never reads a current-IRQL slot.
//  => The host keeps the current IRQL in host per-thread state.  Because the
//  value the host RETURNS from the raise is the value the guest hands back
//  to KfLowerIrql, host and guest agree BY CONSTRUCTION.
//
// CONSOLE REFERENCE (xenia; guest FACTS only -- ordering and values):
//  * xboxkrnl_threading.cc:998-1001  KeRaiseIrqlToDpcLevel -> RaiseIrql(DPC),
//    returns the OLD value.
//  * xboxkrnl_threading.cc:1005-1010 KfLowerIrql(old) -> LowerIrql(old), THEN
//    XThread::GetCurrentThread()->CheckApcs().
//  * xboxkrnl_threading.cc:914-935  KfAcquireSpinLock -> CAS 0->1, then
//    RaiseIrql(DISPATCH=2), returns the OLD IRQL.
//  * xboxkrnl_threading.cc:940-951  KfReleaseSpinLock(lock, old) -> LowerIrql
//    FIRST, then unlock.
//  * xboxkrnl_threading.cc:956-963  KeAcquireSpinLockAtRaisedIrql -> CAS 0->1,
//    spin; NO IRQL change.
//  * xboxkrnl_threading.cc:978-982  KeReleaseSpinLockFromRaisedIrql -> unlock
//    only; NO IRQL change.
//  * cpu/processor.h:43-48           PASSIVE=0, APC=1, DISPATCH=2, DPC=3.
//
// PER-THREAD, not global: the console's IRQL is PER-PROCESSOR, and the host
// runs guest code on several host threads (the boot worker, the vblank ISR
// thread, the CP thread).  A single global IRQL would let one thread's
// lowering clobber another's level.
// ============================================================================

// Console IRQL levels (xenia cpu/processor.h:43-48).
static constexpr uint8_t kIrqlPassive = 0;
static constexpr uint8_t kIrqlApc = 1;
static constexpr uint8_t kIrqlDispatch = 2;
static constexpr uint8_t kIrqlDpc = 3;

// The current IRQL of THIS host thread.
static thread_local uint8_t t_hostIrql = kIrqlPassive;

// An APC queued for THIS host thread.  The console's APC queue lives in the
// KTHREAD (xthread.cc:587-592); the host's is per host thread.  Fixed-size
// (8) on purpose: the guest has NO APC-queueing import (see the note on
// QueueGuestApc below), so this is a mechanism, not a workload.
struct HostApc {
  uint32_t routine = 0;
  uint32_t context = 0;
  uint32_t arg1 = 0;
  uint32_t arg2 = 0;
};
static constexpr uint32_t kMaxPendingApcs = 8;
static thread_local HostApc t_pendingApcs[kMaxPendingApcs];
static thread_local uint32_t t_pendingApcCount = 0;

// Run the APCs queued for this thread.  The console runs them from
// XThread::CheckApcs() at the IRQL-lowering boundary (xboxkrnl_threading.cc:
// 1009-1010 -> xthread.cc:583).  Returns the number delivered.
static uint32_t DeliverPendingApcs() {
  uint32_t delivered = 0;
  while (t_pendingApcCount > 0) {
    const HostApc apc = t_pendingApcs[--t_pendingApcCount];
    uint8_t *base = mcla::kernel::g_memory.base;
    PPCFunc *fn = PPC_LOOKUP_FUNC(base, apc.routine);
    if (fn == nullptr) {
      static std::atomic<uint32_t> s_apcUnresolved{0};
      const uint32_t n = s_apcUnresolved.fetch_add(1) + 1;
      if (n <= 8 || (n % 500) == 0)
        MCLA_LOG_WARN("APC-UNRESOLVED #{} routine={:08X} - not a registered "
                      "guest function; the APC is DROPPED (the console would "
                      "have called it)",
                      n, apc.routine);
      continue;
    }
    PPCContext ctx{};
    ctx.r3.u32 = apc.context;
    ctx.r4.u32 = apc.arg1;
    ctx.r5.u32 = apc.arg2;
    if (g_ppcContext) {
      ctx.r13 = g_ppcContext->r13;
      ctx.r1 = g_ppcContext->r1;
      ctx.msr = g_ppcContext->msr;
    }
    PPCContext *savedCtx = GetPPCContext();
    SetPPCContext(ctx);
    fn(ctx, base);
    if (savedCtx != nullptr)
      SetPPCContext(*savedCtx);
    ++delivered;
    static std::atomic<uint32_t> s_apcDelivered{0};
    const uint32_t dn = s_apcDelivered.fetch_add(1) + 1;
    if (dn <= 40 || (dn % 500) == 0)
      MCLA_LOG_INFO("APC-DELIVER #{} routine={:08X} context={:08X}", dn,
                    apc.routine, apc.context);
  }
  return delivered;
}

// Is an APC pending for this thread?  An ALERTABLE wait is woken by one.
static inline bool HasPendingApc() { return t_pendingApcCount > 0; }

// Queue an APC for THIS host thread.  NOTHING in the guest calls this yet,
// and that is a MEASURED fact, not an omission:
//   * the guest's import table (246 __imp__ names, generated/ppc_xenon/
//     ppc_func_mapping.cpp) contains NO NtQueueApcThread, NO KeInsertQueueApc
//     and NO KeInitializeApc;
//   * the guest's own APC path is entirely GUEST-side: it builds a KAPC on
//     its stack (0x82412DA0..0x82412DD4) and hands it to its own in-guest
//     queue helper sub_824112C8 (call sites 0x82412DE4 and 0x8242F08C,
//     `py -3 tools/ppc_xrefs.py calls 0x824112C8`).
//   * `KiApcNormalRoutineNop` (0x827BD694, the one APC-ish import the guest
//     DOES call, at 0x82412DD4) is a STUB on the console too -- the
//     reference returns 0 and writes nothing (xboxkrnl_threading.cc:
//     1114-1117) -- so the host's `return 0` was already console-correct and
//     is NOT changed here.
// So the host's queue can only ever be filled by the host itself.  The
// delivery POINT is what the console's contract needs, and it is installed.
static void QueueGuestApc(uint32_t routine, uint32_t context, uint32_t arg1,
                          uint32_t arg2) {
  if (t_pendingApcCount >= kMaxPendingApcs) {
    static std::atomic<uint32_t> s_apcFull{0};
    const uint32_t n = s_apcFull.fetch_add(1) + 1;
    if (n <= 8 || (n % 500) == 0)
      MCLA_LOG_WARN("APC-QUEUE-FULL #{} (cap {}) - the APC is DROPPED", n,
                    kMaxPendingApcs);
    return;
  }
  t_pendingApcs[t_pendingApcCount++] = HostApc{routine, context, arg1, arg2};
}

// Raise: SETS the level and returns the OLD one -- exactly the console's
// atomic exchange (the reference: Processor::RaiseIrql returns
// static_cast<Irql>(xe::atomic_exchange(new_value, &irql_)), processor.cc:
// 431-435; the per-thread twin XThread::RaiseIrql, xthread.cc:577-579).  The
// reference does NOT clamp and does NOT assert, so neither does this.
static inline uint32_t HostRaiseIrql(uint8_t level) {
  const uint8_t old = t_hostIrql;
  t_hostIrql = level;
  return old;
}

// Lower: SETS the level (the reference's Processor::LowerIrql is likewise a
// plain atomic exchange, processor.cc:437-440) and then runs the pending
// APCs.
//
// The console runs the APC check on EVERY KfLowerIrql, not only below
// APC_LEVEL: xboxkrnl_threading.cc:1005-1010 is
//     kernel_state()->processor()->LowerIrql(old_value);
//     XThread::GetCurrentThread()->CheckApcs();
// unconditionally.  The level guard is therefore NOT applied here either.
//
// The ONE place the host deviates from the reference is a level outside
// 0..3: that is not an IRQL, and the host's level also decides whether the
// APC check runs, so a garbage value must not be able to wedge the level at
// "DPC forever".  Such a value is clamped to PASSIVE and logged.
static inline void HostLowerIrql(uint8_t level) {
  if (level > kIrqlDpc) {
    static std::atomic<uint32_t> s_badIrql{0};
    const uint32_t n = s_badIrql.fetch_add(1) + 1;
    if (n <= 8 || (n % 500) == 0)
      MCLA_LOG_WARN("IRQL-BAD-LEVEL #{} level={} -> PASSIVE", n,
                    static_cast<unsigned>(level));
    level = kIrqlPassive;
  }
  t_hostIrql = level;
  DeliverPendingApcs();
}

// The IRQL this host thread is running at.  Exposed so the ISR contexts can
// raise the level the way a real interrupt does (an ISR runs at DPC).
static inline uint8_t HostCurrentIrql() { return t_hostIrql; }

// ---------------------------------------------------------------------------
// F-852 (fix_sema, 2026-10-21): THE LIVE SEMAPHORE CENSUS -- SEMACNT.
//
// THE INSTRUMENT WAS BLIND, AND THAT WAS THE DEFECT (rule 19: a zero from an
// instrument that was never shown firing on a known event is not a result).
// The F-370 row (src/gpu_device.cpp:7347-7357) prints
//     "F370-SEMA #{} {} h={:08X} init={} x={:08X} tid={:08X} lr={:08X}"
// `init` is the INITIAL count, taken from boot_host.cpp's counting-semaphore
// registry (RegisterCountingSema -> g_countingSemaInit).  It is a CONSTANT for
// the life of the object, so the row is IDENTICAL whether the semaphore is
// full or starved.  The brief's premise -- "the count must have reached 0 by
// the time the boot worker waited" -- is not something that row could show,
// and it is in fact FALSE (measured below).
//
// WHAT THIS ROW PRINTS INSTEAD, on EVERY wait and EVERY release of a
// semaphore, from every path (NtWaitForSingleObjectEx, KeWaitForSingleObject,
// NtReleaseSemaphore):
//     h      the guest handle / dispatcher address
//     obj    the RESOLVED host wrapper pointer (so the wait side and the
//            release side can be compared by pointer -- a mismatch here IS
//            the wake-loss)
//     cls    sema | event | other
//     cnt    the LIVE count (the thing F-370 called `init`)
//     max    the semaphore's maximum count
//     waitrs the number of threads CURRENTLY BLOCKED on this object
//     x      timeout (wait) / release count (release)
//     lr     the guest call site
//
// THE MEASUREMENTS THAT REFUTE THE PREMISE (build/bctr_v2.log, the newest
// soak; the boot worker is tid=00005CEC -- "PARK-SAMPLE worker-tid=00005CEC",
// build/bctr_v2.log:2256):
//   1. THE LIVE COUNT WAS 15, NOT 0, AT THE BOOT WORKER'S WAIT.
//      build/bctr_v2.log:130574
//        "FI-ENQ #346 mgr=A04865D4 item=8EFFE450 triple={...} slotSem=B72C1048
//         slotCnt=15"
//      -- slotCnt is read from the LIVE host wrapper (src/gpu_device.cpp:29564
//      -> LookupIdentityKernelObject -> dynamic_cast<Semaphore*> ->
//      sem->count.load()), so this is the semaphore's count at 21:49:04.236.
//   2. THE BOOT WORKER'S WAIT ON B72C1048 RETURNED.  The main-park stamp
//      (g_mainParkNs, refreshed at the ENTRY of every wait by the main guest
//      thread -- imports.cpp:2334 and :7271) reads 21:49:04.235, i.e. the
//      boot worker entered ANOTHER wait 1 ms after the one above; a thread
//      cannot enter a second wait while still blocked in the first.
//      Derived from build/bctr_v2.log:559439
//        "HB-FLICKER #3240 ... mainwait=B72C1048 mainwaitlr=82135DF8
//         mainwait_age_ms=79314"  (21:50:23.549 - 79.314 s = 21:49:04.235).
//   3. AND IT KEPT RUNNING: build/bctr_v2.log:623017
//        "BCTR-DISP #27099136 tid=00005CEC ctr=82130000 lr=821CD378"
//      -- 27,197,440 dispatches at 21:50:35.810, the end of the log.
//
// THE POSITIVE CONTROL is the SELFTEST below, which runs ONCE per boot at the
// first semaphore use: it creates a semaphore with THREE permits and waits on
// it (the wait returns immediately, the count goes 3 -> 2), and it blocks a
// second waiter on a ZERO-count semaphore until a release wakes it.  Those
// rows prove the census prints a NON-ZERO count, a RETURNED row, and
// waiters>0 while a thread is parked -- so a later row saying cnt=0 is a
// MEASUREMENT, not a constant.
// ---------------------------------------------------------------------------
namespace {

struct SemCntSlot
{
    uint32_t handle;   // 0 = free
    uint32_t hits;     // rows printed for this handle
    bool seenZero;     // this handle was once seen with a zero count
    bool starved;      // this handle was once seen with a BLOCKED waiter
};
constexpr uint32_t kSemCntSlots = 64;
SemCntSlot g_semCntSlots[kSemCntSlots] = {};
std::atomic<uint32_t> g_semCntRows{0};
std::atomic<uint64_t> g_semCntWaits{0};
std::atomic<uint64_t> g_semCntReleases{0};
std::atomic<uint64_t> g_semCntBlocked{0};   // waits that found cnt == 0

SemCntSlot* SemCntFind(uint32_t handle)
{
    for (uint32_t i = 0; i < kSemCntSlots; ++i)
        if (g_semCntSlots[i].handle == handle)
            return &g_semCntSlots[i];
    for (uint32_t i = 0; i < kSemCntSlots; ++i)
    {
        if (g_semCntSlots[i].handle == 0)
        {
            g_semCntSlots[i].handle = handle;
            return &g_semCntSlots[i];
        }
    }
    return nullptr;
}

// The live state of whatever object a wait/release resolved to.  For a
// semaphore that is (count, max, blocked waiters); for anything else the
// count is "no count" (0xFFFFFFFF) and only the class is meaningful.
void SemCntSnapshot(KernelObject *obj, uint32_t *cnt, uint32_t *max,
                    uint32_t *waiters)
{
    *cnt = 0xFFFFFFFFu;
    *max = 0;
    *waiters = 0;
    if (obj == nullptr)
        return;
    if (auto *s = dynamic_cast<Semaphore *>(obj))
    {
        *cnt = s->LiveCount();
        *max = s->maximumCount;
        *waiters = s->BlockedWaiters();
    }
}

// The census row.  `force` prints unconditionally (the self-test, and the
// RETURNED row of a wait that actually blocked); otherwise the row is printed
// when it MATTERS -- a thread is blocked on the object, the count was zero
// for the first time on this handle, or the handle has been seen starved --
// and sampled (first 8 rows per handle, then every 500th) otherwise.  The
// "matters" cases are never sampled away, which is the whole point (rule 19:
// an instrument must be shown firing on a known event).
// Returns true when the row was printed.
bool SemCntRow(const char *op, uint32_t handle, KernelObject *obj,
               uint32_t liveCount, uint32_t maxCount, uint32_t waiters,
               uint32_t extra, uint32_t lr, bool force)
{
    const char *cls = "other";
    uint32_t shown = liveCount;
    if (obj != nullptr)
    {
        if (dynamic_cast<Semaphore *>(obj) != nullptr)
            cls = "sema";
        else if (dynamic_cast<Event *>(obj) != nullptr)
            cls = "event";
    }
    if (std::strcmp(cls, "sema") != 0)
        shown = 0xFFFFFFFFu;  // no count on a non-semaphore

    bool print = force;
    SemCntSlot *slot = SemCntFind(handle);
    if (!print)
    {
        if (waiters > 0)
            print = true;                       // somebody is parked on it
        else if (slot != nullptr)
        {
            if (liveCount == 0 && !slot->seenZero)
                print = true;                   // the FIRST zero on this handle
            else if (slot->starved)
                print = true;                   // this handle has a parked waiter
            else if (slot->hits < 8 || (slot->hits % 500) == 0)
                print = true;                   // the sample
        }
        else if (liveCount == 0)
            print = true;                       // no slot left: never hide a zero
    }
    if (slot != nullptr)
    {
        if (liveCount == 0)
            slot->seenZero = true;
        if (waiters > 0)
            slot->starved = true;
        if (print)
            slot->hits++;
    }
    if (!print)
        return false;

    const uint32_t n = g_semCntRows.fetch_add(1) + 1;
    MCLA_LOG_WARN("SEMACNT #{} {} h={:08X} obj={} cls={} cnt={} max={} "
                  "waiters={} x={:08X} tid={:08X} lr={:08X}",
                  n, op, handle, static_cast<const void *>(obj), cls, shown,
                  maxCount, waiters, extra, GetCurrentThreadId(), lr);
    return true;
}

// The POSITIVE CONTROL (see the block comment above).  Runs once per boot at
// the first semaphore use, so every log carries it.
void SemCntSelfTest()
{
    static std::atomic<bool> s_ran{false};
    bool expected = false;
    if (!s_ran.compare_exchange_strong(expected, true))
        return;

    // (a) A semaphore with THREE permits: the wait returns IMMEDIATELY and
    //     the count drops 3 -> 2.  This is the "known-good handle where the
    //     count is non-zero and the wait returns immediately" control.
    {
        Semaphore s(3u, 32767u);
        const uint32_t before = s.LiveCount();
        const uint32_t st = s.Wait(INFINITE);
        SemCntRow("SELFTEST-WAIT", 0xFFFFFFFFu, &s, before, s.maximumCount,
                  s.BlockedWaiters(), INFINITE, 0, true);
        SemCntRow("SELFTEST-RETURNED", 0xFFFFFFFFu, &s, s.LiveCount(),
                  s.maximumCount, s.BlockedWaiters(), st, 0, true);
    }

    // (b) A ZERO-count semaphore: a thread blocks on it (waiters becomes 1)
    //     and a release wakes it.  This is the "waiters blocked" control.
    {
        Semaphore s(0u, 32767u);
        std::atomic<uint32_t> got{0xFFFFFFFFu};
        std::thread waiter([&] { got.store(s.Wait(INFINITE)); });
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        SemCntRow("SELFTEST-BLOCKED", 0xFFFFFFFFu, &s, s.LiveCount(),
                  s.maximumCount, s.BlockedWaiters(), INFINITE, 0, true);
        uint32_t prev = 0xFFFFFFFFu;
        s.Release(1, &prev);
        SemCntRow("SELFTEST-RELEASE", 0xFFFFFFFFu, &s, s.LiveCount(),
                  s.maximumCount, s.BlockedWaiters(), 1, 0, true);
        waiter.join();
        SemCntRow("SELFTEST-WOKEN", 0xFFFFFFFFu, &s, s.LiveCount(),
                  s.maximumCount, s.BlockedWaiters(), got.load(), 0, true);
    }
    MCLA_LOG_WARN("SEMACNT-SELFTEST done -- the census CAN print a non-zero "
                  "count and a RETURNED row, so a later cnt=0 is a "
                  "measurement");
}

}  // namespace

uint32_t NtWaitForSingleObjectEx(uint32_t Handle, uint32_t WaitMode,
                                  uint32_t Alertable, be<int64_t> *Timeout) {
  // PARK-SAMPLE: census ALL threads at wait entry
  {
    static std::atomic<uint32_t> s_waitCensus{0};
    const uint32_t n = s_waitCensus.fetch_add(1) + 1;
    if (n <= 60 || (n % 5000) == 0) {
      const uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);
      const char* tclass = (timeout == 0) ? "poll" : (timeout == INFINITE) ? "inf" : "finite";
      MCLA_LOG_INFO("PARK-CENSUS[NTWFSO] #{:04} tid={:08X} h={:08X} class={} lr={:08X}",
                    n, GetCurrentThreadId(), Handle, tclass,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }
  // PRODUCER-DEATH CENSUS: see KeWaitForSingleObject note.
  {
    static std::atomic<uint32_t> s_wcNtw{0};
    const uint32_t n = s_wcNtw.fetch_add(1) + 1;
    const uint32_t lr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0;
    const bool hot = lr >= 0x82410000u && lr < 0x82430000u;
    if (hot || n <= 120 || (n % 300) == 0) {
      MCLA_LOG_INFO("WAIT[NTWFSO] #{:05}{} tid={:08X} handle={:08X} "
                    "alertable={} to={}ms lr={:08X}",
                    n, hot ? "!" : " ", GetCurrentThreadId(), Handle, Alertable,
                    GuestTimeoutToMilliseconds(Timeout), lr);
    }
  }
  // MAIN-THREAD PARK PROBE
  {
    static std::atomic<uint32_t> s_parkLogs2{0};
    // T43.17 (2026-10-13): passes counts EVERY pass through this probe;
    // printed rows cap at 200, so row count is a lower bound -- passes= is
    // the denominator showing cap coverage.
    static std::atomic<uint64_t> s_parkPasses2{0};
    const uint64_t t = s_parkPasses2.fetch_add(1, std::memory_order_relaxed) + 1;
    uint32_t mainId = g_mainGuestThreadId.load();
    // T43.18 (2026-10-13): publish every main-thread park uncapped for the
    // HB-FLICKER mainwait=* tail-light (see xdm.h). Relaxed store, no log.
    if (mainId != 0 && GetCurrentThreadId() == mainId) {
      g_mainParkHandle.store(Handle, std::memory_order_relaxed);
      g_mainParkLr.store(g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u,
                         std::memory_order_relaxed);
      g_mainParkNs.store(static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::steady_clock::now().time_since_epoch()).count()),
                         std::memory_order_relaxed);
    }
    if (mainId != 0 && GetCurrentThreadId() == mainId &&
        s_parkLogs2.fetch_add(1) < 200) {
      MCLA_LOG_INFO("[main-park] NtWaitForSingleObjectEx handle={:08X} "
                    "alertable={} lr={:08X} passes={}",
                    Handle, Alertable,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0), t);
    }
  }
  uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);

  // DISABLED per bisect Run A: DWELL histogram probe
  // const auto waitStart = std::chrono::steady_clock::now();
  // auto LogDwellHistogramNT = ...
  const auto waitStart = std::chrono::steady_clock::now();
  auto LogDwellHistogramNT = [&](uint32_t status) { (void)status; (void)waitStart; };

  if (IsKernelObject(Handle)) {
    // F-039: prefer the identity map so Wait hits the same object Release
    // signals (CreateRegisteredKernelObject products).
    KernelObject *obj = LookupIdentityKernelObject(Handle);
    if (!obj)
      obj = GetKernelObject(Handle);
    if (!obj) { g_ppcContext->r3.u32 = STATUS_INVALID_HANDLE; return STATUS_INVALID_HANDLE; }
    // F-589: the wait-side twin of RELSEMA-RES. handle = hostPtr - 0x100000000,
    // so this is directly comparable with the release side's `sem=` field: one
    // handle must resolve to ONE pointer on both sides, or a permit released on
    // one object is invisible to a waiter parked on the other. Bounded.
    {
      static std::atomic<uint32_t> s_waitRes{0};
      const uint32_t wn = s_waitRes.fetch_add(1) + 1;
      if (wn <= 60 || (wn % 500) == 0) {
        MCLA_LOG_WARN("WAITRES #{} handle={:08X} obj={} to={}ms tid={:08X} "
                      "lr={:08X}",
                      wn, Handle, static_cast<const void *>(obj), timeout,
                      GetCurrentThreadId(),
                      static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      }
    }
    // F-609: `obj->Wait(timeout)` drops `Alertable` entirely, because
    // KernelObject::Wait(uint32_t) (xdm.h:40-44) has no such parameter. Worse,
    // that base body is `assert(false && "Wait not implemented..."); return
    // STATUS_TIMEOUT;` - compiled out under /DNDEBUG (defined in
    // build/compile_commands.json), so an object type that never overrode Wait
    // silently answered STATUS_TIMEOUT, which is a SUCCESS status meaning
    // "waited and expired". A caller that ignores the status cannot tell a real
    // timeout from an unimplemented wait, and the title parks on INFINITE
    // timeouts, so that fake is a live hang, not a cosmetic one.
    //
    // Alertable is not plumbed, because plumbing it means changing the virtual
    // KernelObject::Wait signature (src/kernel/xdm.h, not ours) and giving every
    // override an APC-delivery path. Stated plainly instead: it is
    // UNIMPLEMENTED, and both facts are now visible to a caller and to a census
    // rather than dropped on the floor.
    if (Alertable) {
      static std::atomic<uint32_t> s_alertable{0};
      const uint32_t an = s_alertable.fetch_add(1) + 1;
      if (an <= 40 || (an % 500) == 0)
        MCLA_LOG_WARN("WAIT-ALERTABLE #{} alertable={} is honoured only when "
                      "an APC is actually PENDING (the console delivers a "
                      "pending APC and returns STATUS_USER_APC; "
                      "xobject.cc:207-215). The host's APC queue is EMPTY "
                      "today -- the guest imports no APC-queueing export "
                      "(NtQueueApcThread / KeInsertQueueApc / KeInitializeApc "
                      "are all absent from the guest's 246-entry import "
                      "table) -- so this wait parks exactly as before. "
                      "handle={:08X} tid={:08X} lr={:08X}",
                      an, Alertable, Handle, GetCurrentThreadId(),
                      static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      if (HasPendingApc()) {
        const uint32_t delivered = DeliverPendingApcs();
        MCLA_LOG_WARN("APC-WAKE #{} delivered={} handle={:08X} -> "
                      "STATUS_USER_APC",
                      static_cast<uint32_t>(GetCurrentThreadId()), delivered,
                      Handle);
        return STATUS_USER_APC;
      }
    }

    // Wait-implementing types, all `final` so typeid is an exact discriminator:
    // Event (kernel_objects.h:42), Semaphore (:129), FileObject (:216),
    // SectionObject (:233), GuestThreadHandle (guest_thread.h:48). A MISS here
    // is refused, never faked - the failure direction is a visible refusal, not
    // a silent STATUS_TIMEOUT. Extend this list when a type overrides Wait.
    //
    // F-609 PORT BATCH, 2026-09-29: Mutant (port_kobj.h:174) ADDED. This is not
    // cosmetic. NtCreateMutant in src/kernel/port_kobj.cpp:1690 is REAL and
    // returns a real object with a real guest handle, and Mutant::Wait
    // (port_kobj.cpp:222) is a real Win32-recursive-mutex state machine ported
    // from Xenia threading_win.cc:269-277 -- but without this entry a guest that
    // parked on one would have been refused with STATUS_INVALID_HANDLE and
    // would never have reached Wait, so the state machine would have been
    // unreachable code. src/kernel/port_kobj.h:37 and port_kobj.cpp:1686 both
    // name this line as a required integration edit.
    const bool waitImplemented =
        typeid(*obj) == typeid(Event) || typeid(*obj) == typeid(Semaphore) ||
        typeid(*obj) == typeid(FileObject) ||
        typeid(*obj) == typeid(SectionObject) ||
        typeid(*obj) == typeid(Mutant) ||
        typeid(*obj) == typeid(GuestThreadHandle);
    if (!waitImplemented) {
      static std::atomic<uint32_t> s_noWait{0};
      const uint32_t nn = s_noWait.fetch_add(1) + 1;
      MCLA_LOG_WARN("WAIT-UNIMPLEMENTED #{} handle={:08X} type={} does not "
                    "override KernelObject::Wait -> refused with "
                    "STATUS_INVALID_HANDLE (was a silent STATUS_TIMEOUT) "
                    "tid={:08X} lr={:08X}",
                    nn, Handle, typeid(*obj).name(), GetCurrentThreadId(),
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      return STATUS_INVALID_HANDLE;
    }

    // F-852 (fix_sema): the LIVE-count census.  This is the row that can
    // FAIL: it prints the semaphore's CURRENT count (not the initial count
    // the F-370 row printed) and the number of threads blocked on it, so a
    // starved semaphore is visible as (cnt=0, waiters>0) at the WAIT and the
    // release that should have woken it is visible as (waiters>0).
    bool semCntWaitPrinted = false;
    {
        uint32_t c = 0, mx = 0, w = 0;
        SemCntSnapshot(obj, &c, &mx, &w);
        if (c == 0)
            g_semCntBlocked.fetch_add(1, std::memory_order_relaxed);
        const uint64_t waits =
            g_semCntWaits.fetch_add(1, std::memory_order_relaxed) + 1;
        semCntWaitPrinted =
            SemCntRow("WAIT", Handle, obj, c, mx, w, timeout,
                      static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                      false);
        // F-852: the SUMMARY row, so the census can be read without counting
        // the per-event rows.  waits / releases / blocked (waits that found
        // cnt == 0) / rows.
        if ((waits % 5000) == 0) {
            MCLA_LOG_WARN("SEMACNT-SUM waits={} releases={} blocked={} rows={}",
                          waits, g_semCntReleases.load(std::memory_order_relaxed),
                          g_semCntBlocked.load(std::memory_order_relaxed),
                          g_semCntRows.load(std::memory_order_relaxed));
        }
    }

    const uint32_t st = obj->Wait(timeout);
    LogDwellHistogramNT(st);
    {
        // The RETURNED row is printed when the WAIT row was printed, and
        // ALWAYS when the wait actually BLOCKED (g_semWaitBlocked): that is
        // the row that says "this wait did not come back at once".
        uint32_t c1 = 0, mx1 = 0, w1 = 0;
        SemCntSnapshot(obj, &c1, &mx1, &w1);
        SemCntRow("RETURNED", Handle, obj, c1, mx1, w1, st,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                  semCntWaitPrinted || g_semWaitBlocked);
    }
    {
      static std::atomic<uint32_t> s_wcNtwR{0};
      const uint32_t n = s_wcNtwR.fetch_add(1) + 1;
      const uint32_t lr2 =
          g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0;
      if ((lr2 >= 0x82410000u && lr2 < 0x82430000u) || n <= 120 ||
          (n % 300) == 0)
        MCLA_LOG_INFO("WAKE[NTWFSO] #{:05} tid={:08X} status={:08X} lr={:08X}",
                      n, GetCurrentThreadId(), st, lr2);
    }
    return st;
  } else {
    // F-609: this was `assert(false && "Unrecognized handle value.");` and then
    // FELL THROUGH to `return STATUS_TIMEOUT`. /DNDEBUG is defined in
    // build/compile_commands.json, so the assert was compiled out and the
    // unrecognised-handle path silently reported STATUS_TIMEOUT - a SUCCESS
    // status meaning "waited, then expired". A guest waiting INFINITE on a
    // handle we do not own was told "timed out" instead of "invalid handle",
    // and nothing in the log said so. The assert also asserted on a
    // guest-supplied value, which is never a valid thing to do.
    //
    // Now a real refusal: STATUS_INVALID_HANDLE, with a bounded named marker so
    // a soak can count how often the title waits on a handle we do not own.
    static std::atomic<uint32_t> s_badHandle{0};
    const uint32_t bn = s_badHandle.fetch_add(1) + 1;
    if (bn <= 40 || (bn % 500) == 0)
      MCLA_LOG_WARN("WAIT-BADHANDLE #{} handle={:08X} to={}ms is not a "
                    "resolvable kernel object -> STATUS_INVALID_HANDLE (was a "
                    "silent STATUS_TIMEOUT) tid={:08X} lr={:08X}",
                    bn, Handle, timeout, GetCurrentThreadId(),
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    g_ppcContext->r3.u32 = STATUS_INVALID_HANDLE;
    LogDwellHistogramNT(STATUS_INVALID_HANDLE);
    return STATUS_INVALID_HANDLE;
  }
  // F-609: the trailing `LogDwellHistogramNT(STATUS_TIMEOUT); return
  // STATUS_TIMEOUT;` used to be the silent fall-through for an unrecognised
  // handle. Both arms now return, so it is unreachable and was deleted rather
  // than left as a second, differently-bad answer to the same question.
}

// ---------------------------------------------------------------------------
// NtWriteFile -- F-609, REFUSED HONESTLY. This was the single worst
// success-without-work in the file. It read:
//
//   auto bufferAddr = guestMem.MapVirtual(buffer);   // resolve the buffer...
//   ...
//   if (ioStatus) { ioStatus->Status.set(STATUS_SUCCESS);
//                   ioStatus->Information.set(length); }   // ...then lie
//   return STATUS_SUCCESS;
//
// The buffer was resolved and DISCARDED. It returned STATUS_SUCCESS and told
// the guest `length` bytes were written, having written NONE. A title that
// saved a file and was told it succeeded was left holding a file of exactly
// the right length full of whatever was there before -- the worst possible
// failure mode, because the caller has no way to detect it.
//
// WHY REFUSAL AND NOT IMPLEMENTATION. Xenia implements it for real
// (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:354-430), but its
// last act is `file->Write(...)` -> `XFile::Write` ->
// `file_->WriteSync(...)` (.research/xenia/src/xenia/kernel/xfile.cc:239-250).
// THIS VFS HAS NO WRITE PATH TO CALL. src/fs/vfs_rpf.h:82-89 exposes exactly:
// OpenFile, ReadFile, ReadFileAt, CloseFile, SeekFile, ListDirectory, Exists,
// GetFileSize, IsDirectory, IsVirtualPath, GuestToVirtualPath -- there is no
// WriteFile and no WriteFileAt, on the class or anywhere in the interface.
// Adding one means editing src/fs/**, which is owned by another agent right
// now, so it is out of scope here BY OWNERSHIP, not by difficulty. Writing a
// parallel write path in this file would violate the one-owner-per-address
// rule (AGENTS.md rule 4) with a second writer on the same VFS objects.
//
// THE STATUS, and why this one. STATUS_ACCESS_DENIED (0xC0000022). It is what
// real hardware returns for a title writing to the DVD/HDD, and it is the
// truthful answer here: this host does not implement guest file writes. Not
// STATUS_SUCCESS (the lie), not STATUS_NOT_IMPLEMENTED (which claims the
// REQUEST is malformed, and the request is fine), and not STATUS_INVALID_HANDLE
// (the handle may well be a real VFS handle -- NtReadFile proves we resolve
// exactly these FileObjects).
//
// `Information` IS SET TO 0, never to `length`. That is not a style choice: it
// is Xenia's own failure path, verbatim --
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:419-422
//     if (XFAILED(result) && io_status_block) {
//       io_status_block->status = result;
//       io_status_block->information = 0;
//     }
// A guest that reads Information and does not check Status would still be
// correct here, because a refused write transferred zero bytes.
//
// NOT SIGNALLED: the completion `event` is deliberately NOT Set() on the
// refusal path. Signalling an event for an I/O that did not happen is the same
// defect one layer up. The guest stays parked on its write event and says so in
// the log, which is the true state of the world.
// ---------------------------------------------------------------------------
namespace {
// Not in src/kernel/xbox.h:412-451, so declared here rather than in a header
// another agent may be reading. The value is the NTSTATUS the Xbox 360 kernel
// returns for a denied write.
constexpr uint32_t kStatusAccessDenied = 0xC0000022u;
std::atomic<uint64_t> g_nfsWriteSeen{0};
std::atomic<uint64_t> g_nfsWriteRefused{0};
std::atomic<uint64_t> g_nfsWriteEmpty{0};
} // namespace

uint32_t NtWriteFile(uint32_t handle, uint32_t event, uint32_t apcRoutine,
                     uint32_t apcContext, XIO_STATUS_BLOCK *ioStatus,
                     void *buffer, uint32_t length, be<uint64_t> *byteOffset,
                     uint32_t *key) {
  (void)apcRoutine;
  (void)apcContext;
  (void)key;
  (void)byteOffset;

  const uint64_t seen =
      g_nfsWriteSeen.fetch_add(1, std::memory_order_relaxed) + 1;

  // A ZERO-LENGTH WRITE IS REAL WORK, and zero bytes is the correct and
  // complete answer for it. Xenia's handle checks come first
  // (xboxkrnl_io.cc:363-372), so a bad handle is still a bad handle here;
  // but a 0-length write against a handle we do not own must not be reported
  // as a success either, so it is checked, not waved through.
  if (buffer == nullptr || length == 0) {
    bool resolvable = false;
    if (handle != GUEST_INVALID_HANDLE_VALUE && IsKernelObject(handle)) {
      KernelObject *o = GetKernelObject(handle);
      resolvable = (o != nullptr && o->IsValid());
    }
    if (resolvable) {
      g_nfsWriteEmpty.fetch_add(1, std::memory_order_relaxed);
      if (ioStatus) {
        ioStatus->Status.set(STATUS_SUCCESS);
        ioStatus->Information.set(0); // 0 bytes requested == 0 bytes written
      }
      return STATUS_SUCCESS;
    }
    g_nfsWriteRefused.fetch_add(1, std::memory_order_relaxed);
    if (seen <= 8 || (seen % 200) == 0) {
      MCLA_LOG_WARN("NFS-WRITE #{} h={:08X} len=0 -> STATUS_INVALID_HANDLE "
                    "(0-length write on a handle we do not own)",
                    seen, handle);
    }
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INVALID_HANDLE);
      ioStatus->Information.set(0);
    }
    return STATUS_INVALID_HANDLE;
  }

  // Resolve the buffer only to REPORT it, never to claim the write happened.
  // No bytes are copied to any VFS object and none are dropped on the floor
  // pretending otherwise.
  auto &guestMem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t bufferAddr = guestMem.MapVirtual(buffer);
  const bool bufferOk = (bufferAddr != 0) && (guestMem.Translate(bufferAddr) != nullptr);

  FileObject *fileObj = nullptr;
  if (handle != GUEST_INVALID_HANDLE_VALUE && IsKernelObject(handle)) {
    KernelObject *o = GetKernelObject(handle);
    if (o && o->IsValid())
      fileObj = dynamic_cast<FileObject *>(o);
  }

  g_nfsWriteRefused.fetch_add(1, std::memory_order_relaxed);
  if (seen <= 8 || (seen % 200) == 0) {
    const uint32_t glr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    MCLA_LOG_WARN(
        "NFS-WRITE #{} h={:08X} len={} buf={:08X} bufReadable={} "
        "vfsFile={} -> REFUSED STATUS_ACCESS_DENIED (0xC0000022), 0 bytes "
        "written, Information=0, completion event h={:08X} NOT signalled "
        "(was: STATUS_SUCCESS + Information=len with nothing written) "
        "seen={} refused={} empty={} glr={:08X}",
        seen, handle, length, bufferAddr, bufferOk ? 1 : 0, fileObj ? 1 : 0,
        event, seen, g_nfsWriteRefused.load(std::memory_order_relaxed),
        g_nfsWriteEmpty.load(std::memory_order_relaxed), glr);
  }

  if (ioStatus) {
    ioStatus->Status.set(kStatusAccessDenied);
    ioStatus->Information.set(0);
  }
  return kStatusAccessDenied;
}

void vsprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t ExGetXConfigSetting(uint16_t Category, uint16_t Setting, void *Buffer,
                             uint16_t SizeOfBuffer,
                             be<uint32_t> *RequiredSize) {
  uint32_t data[4]{};

  switch (Category) {
  // XCONFIG_SECURED_CATEGORY
  case 0x0002: {
    switch (Setting) {
    // XCONFIG_SECURED_AV_REGION
    case 0x0002:
      data[0] = ByteSwap(0x00001000); // USA/Canada
      break;

    default:
      return 1;
    }
    break;
  }

  case 0x0003: {
    switch (Setting) {
    case 0x0001: // XCONFIG_USER_TIME_ZONE_BIAS
    case 0x0002: // XCONFIG_USER_TIME_ZONE_STD_NAME
    case 0x0003: // XCONFIG_USER_TIME_ZONE_DLT_NAME
    case 0x0004: // XCONFIG_USER_TIME_ZONE_STD_DATE
    case 0x0005: // XCONFIG_USER_TIME_ZONE_DLT_DATE
    case 0x0006: // XCONFIG_USER_TIME_ZONE_STD_BIAS
    case 0x0007: // XCONFIG_USER_TIME_ZONE_DLT_BIAS
      data[0] = 0;
      break;

    // XCONFIG_USER_LANGUAGE
    case 0x0009:
      data[0] = ByteSwap((uint32_t)Config::Language);
      break;

    // XCONFIG_USER_VIDEO_FLAGS
    case 0x000A:
      data[0] = ByteSwap(0x00040000);
      break;

    // XCONFIG_USER_RETAIL_FLAGS
    case 0x000C:
      data[0] = ByteSwap(1);
      break;

    // XCONFIG_USER_COUNTRY
    case 0x000E:
      data[0] = ByteSwap(103);
      break;

    default:
      return 1;
    }
  }
  }

  *RequiredSize = 4;
  memcpy(Buffer, data, std::min((size_t)SizeOfBuffer, sizeof(data)));

  return 0;
}

namespace {
// X_MEM_* / X_PAGE_* per Xenia src/xenia/xbox.h (documented 360 values).
constexpr uint32_t kXMemCommit = 0x00001000;
constexpr uint32_t kXMemReserve = 0x00002000;
constexpr uint32_t kXMemDecommit = 0x00004000;
constexpr uint32_t kXMemRelease = 0x00008000;
constexpr uint32_t kXMemFree = 0x00010000;
constexpr uint32_t kXMemPrivate = 0x00020000;
constexpr uint32_t kXMemReset = 0x00080000;
constexpr uint32_t kXMemTopDown = 0x00100000;
constexpr uint32_t kXMemNozero = 0x00800000;
constexpr uint32_t kXMemLargePages = 0x20000000;
constexpr uint32_t kXPageNoAccess = 0x00000001;
constexpr uint32_t kXPageReadonly = 0x00000002;
constexpr uint32_t kXPageReadWrite = 0x00000004;

using VirtualRegionInfo = mcla::kernel::GuestMemoryHeap::VirtualRegionInfo;

constexpr uint32_t kVirtPageSize =
    mcla::kernel::GuestMemoryHeap::kGuestVirtualPageSize;
inline uint32_t RoundUp64K(uint32_t v) {
  return (v + kVirtPageSize - 1) & ~(kVirtPageSize - 1);
}

// Allocation census for the virtual-memory surface (P2): every call, first
// 500 then every 500th. Proves which VAs the game asks for and what we grant.
void LogVirtualAlloc(const char *api, uint32_t baseIn, uint32_t baseOut,
                     uint32_t size, uint32_t type, uint32_t status) {
  static std::atomic<uint32_t> s_allocCalls{0};
  const uint32_t n = s_allocCalls.fetch_add(1) + 1;
  if (n <= 500 || n % 500 == 0) {
    MCLA_LOG_INFO(
        "{} #{} base={:08X}->{} size={:08X} type={:08X} st={:08X} lr={:08X}",
        api, n, baseIn, baseOut, size, type, status,
        static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }
}

// Resolve a guest handle to a real kernel-object wrapper, or nullptr.
//
// F-609-BOOTCRASH (build/w657.log 19:19:22, boot worker tid 21620): this
// resolver was reached with handle = 0xFFFFFFFE and then died on the first
// guest read. 0xFFFFFFFE is CURRENT_THREAD_HANDLE (guest_thread.h:14,
// `uint32_t(-2)`) - the XOS idiom for "my own KTHREAD" - so the title asking
// for its own thread is what killed the boot, not wild memory.
//
// Measured chain, resolved against build/mcla.map from the SAME build as the
// log (rva 0x24dc00 = ResolveKernelObjectSafe, xdm.h inlined into it):
//   0x24dc0b  cmp eax,0x1001 / jb          handle < 0x1000  -> refused
//   0x24dc14  call IsKernelObject         (xdm.cpp:32)    -> TRUE
//   0x24dc27  call GuestMemoryHeap::Translate (memory.cpp:285) -> 0x1FFFFFFFE
//   0x24dc2f  je  <null>                  non-null, so NOT refused
//   0x24dc37  call TryQueryKernelObject   (xdm.h:186)     -> nullptr
//   0x24dc42  cmove rsi,rdi               rsi = the raw guest pointer
//   0x24dc49  call IsInvalidKernelObject  (xdm.cpp:46)    -> false
//   0x24dc5d  cmp dword ptr [rsi+0x10],0x584f4258        *** C0000005 ***
// w657.log's own register dump agrees: rdi=rsi=0x1fffffffe, rdx=0xffffffff.
//
// THE ARITHMETIC - this corrects the "double translation" reading of
// 0x20000000e. There is no second translation; the high '2' is a carry:
//   0xFFFFFFFE                    the handle, an ordinary guest uint32
// + 0x100000000                   kBaseAddress (memory.h:18)
// = 0x1FFFFFFFE                   Translate's result. IN bounds: the last 2
//                                 bytes of the 4 GiB window, which is why
//                                 Translate's `guestAddr >= m_size` test
//                                 (memory.cpp:287) cannot reject it
// + 0x10                          offsetof(XDISPATCHER_HEADER,
//                                 WaitListHead.Flink) - the OBJECT_SIGNATURE
//                                 compare, folded in from
//                                 KernelObject::IsValid() (xdm.h:46)
// = 0x20000000E                   14 bytes PAST the window -> AV
// No sign extension is involved: `mov esi,ecx` (0x24dc06) zero-extends, and
// r3=0xFFFFFFFE is the title's real -2, not a widened 32-bit value.
//
// ROOT CAUSE: all three guards range-check the ADDRESS, never the OBJECT.
// ResolveKernelObjectSafe and IsKernelObject both rejected only the single
// sentinel 0xFFFFFFFF BY EQUALITY, and Translate's bounds test is vacuous for a
// 4 GiB window (every uint32 is "in range"). So the top 16 bytes of the window
// - the invalid-handle class 0xFFFFFFF0..0xFFFFFFFF, which CONTAINS
// CURRENT_THREAD_HANDLE - reached a dereference.
//
// THE FIX: test the object extent, not the address. A handle may only name a
// kernel object if a whole XDISPATCHER_HEADER fits inside the window:
//     handle + sizeof(XDISPATCHER_HEADER) < kSize
// That rejects the whole 17-value invalid-handle class
// 0xFFFFFFF0..0xFFFFFFFF - which CONTAINS CURRENT_THREAD_HANDLE - in one
// deterministic place, needs no new knowledge of the title, and leaves every
// legitimate handle untouched: the highest handle in w657.log is C65C6880, three
// orders of magnitude below the class.
//
// The 4 KiB null-guard rejection is KEPT (it is the other half of the same
// window and is the protection this function exists to provide): the NOACCESS
// page memory.cpp:218 installs, which IsValid rejects at :321-322, so a handle
// in [1, 0x1000) would fault on the very first field read.
//
// The signature proof is now CHECKED and endian-explicit, not a blind host
// dereference of guest memory: GetKernelObject's raw fallback (xdm.h:72-77)
// returns `reinterpret_cast<KernelObject*>(Translate(h))`, and calling IsValid()
// on that is both a reinterpret_cast on guest data and literally the faulting
// instruction. It reads the same bytes - be<uint32_t> stores byte-swapped
// (xbox.h:64-72), so the BE read and the old host load agree on 'XBOX' - but
// cannot fault: IsValid's `end > m_size` test (memory.cpp:327-329) plus a
// __try guard (memory.cpp:81-89).
//
// The Flink ADDRESS is not the same on the two resolution paths, and assuming it
// is would be the same bug wearing a different hat: `KernelObject` is
// polymorphic (virtual dtor, xdm.h:30), so a HOST wrapper carries a vptr and its
// dispatcher header begins at +8 - `handle + 0x10` is precisely the faulting
// instruction - whereas raw guest memory has no vptr, so `XDISPATCHER_HEADER`
// begins at +0 and Flink is at +8. So each path uses the read that is correct
// for the kind of object it actually has; see (3) below.
KernelObject *ResolveKernelObjectSafe(uint32_t handle) {
  using HeapT = mcla::kernel::GuestMemoryHeap;

  // (1) 4 KiB PAGE_NOACCESS null guard: memory.cpp:218 installs it and IsValid
  //     rejects < 4096 at :321-322.
  if (handle == 0 || handle < 0x1000u)
    return nullptr;

  // (2) ROOT FIX: the object must fit, not merely the address. This is what
  //     CURRENT_THREAD_HANDLE (0xFFFFFFFE) and the invalid sentinel
  //     (0xFFFFFFFF) fail; no dereference happens for any of them. `>=` rather
  //     than `>` so the WHOLE 17-value class 0xFFFFFFF0..0xFFFFFFFF is rejected
  //     here, in one place, deterministically - and so every handle that
  //     survives has handle + 16 < kSize, which makes the read in (3) in-bounds
  //     by construction rather than by luck.
  if (static_cast<uint64_t>(handle) + sizeof(XDISPATCHER_HEADER) >=
      HeapT::kSize)
    return nullptr;

  if (!IsKernelObject(handle))
    return nullptr;
  // `raw` is what GetKernelObject starts from (xdm.h:72) and the address every
  // guest-visible read below is expressed against. It is kept as an explicit
  // precondition rather than left implicit: the handle must be translatable
  // before anything consults the identity map, so that a heap which is not
  // initialised (Translate returns nullptr, memory.cpp:478-479) cannot reach a
  // registry comparison. GetKernelObject would return nullptr for it anyway
  // (xdm.h:73), so this adds no new rejection - it only keeps the ordering
  // stated instead of assumed.
  void *raw = HeapT::Instance().Translate(handle);
  auto *o = GetKernelObject(handle);
  if (!raw || !o || IsInvalidKernelObject(o))
    return nullptr;

  // (3) OBJECT_SIGNATURE proof, replacing `!o->IsValid()`. The two kinds of
  //     object need DIFFERENT reads and conflating them is the bug being fixed:
  //
  //       * a registered HOST wrapper: `o` is a real KernelObject, so
  //         `o->IsValid()` (xdm.h:46) is a legitimate host read of
  //         `header.WaitListHead.Flink`. The vptr that `virtual
  //         ~KernelObject` (xdm.h:30) places first is already accounted for by
  //         the compiler: that read is at wrapper+0x10, which is precisely the
  //         faulting instruction (`cmp dword ptr [rsi+0x10],0x584f4258`,
  //         build/mcla.map rva 0x24dc5d).
  //       * the raw fallback (xdm.h:77): `o` is GUEST MEMORY, so no host method
  //         may be called on it - that is a reinterpret_cast on guest data, and
  //         a dereference, and it is the C0000005. Prove it with a CHECKED,
  //         endian-explicit BE read of the same field instead. Guest memory has
  //         no vptr, so XDISPATCHER_HEADER starts at +0 and Flink is at
  //         handle + offsetof(...). be<uint32_t> stores byte-swapped
  //         (xbox.h:64-72), so the BE read yields the same value the host load
  //         would have, and ReadU32BE cannot fault (memory.cpp:327-329 + __try).
  //
  // Note offsetof is deliberately NOT used on KernelObject: it is not
  // standard-layout, and clang rejects it with -Winvalid-offsetof (measured on
  // exactly that line). Reading the member instead of offsetting the handle
  // keeps the vptr arithmetic in the compiler.
  //
  // HOW THE TWO KINDS ARE TOLD APART - registry membership, not pointer equality.
  // The test that used to stand here was `o != raw`, i.e. "did GetKernelObject
  // hand back something other than the raw cast". That question cannot be
  // answered by comparing the two pointers, because for EVERY object this
  // kernel mints they are the same pointer: the handle IS MapVirtual(obj)
  // (xdm.cpp:19-23, xdm.h:130), and Translate(MapVirtual(p)) == p for any p
  // inside the window (memory.cpp:476-481 composed with :490-500). So `o != raw`
  // was FALSE for our own host wrappers, they were routed into the raw-guest
  // branch, that branch read offsetof(WaitListHead.Flink) = 8 bytes past the
  // handle - which is inside the vptr - and a good object was rejected. It was
  // equally FALSE for real guest memory, so the one test had to mean two
  // opposite things and could only ever be right about one of them.
  //
  // This is not an exotic handle. Measured on the handles the boot actually
  // passes: NtCreateFile's own "opened, handle={:08X}" rows in build/w719.log
  // and build/w720.log are B7321280 / B7322280 / B7323280 / B7328280 / B733B280,
  // and those are exactly the handles the read-path census prints - they are
  // host objects living in the physical arena, because :1539 allocates the
  // FileObject in the guest physical heap precisely so the handle round-trips
  // through Translate(). Translate(B7321280) = 0x1B7321280 = the object, so
  // `o == raw` for every one of them, and at +8 there is header.Lock, not
  // Flink: the low byte is the Type the object was created with, and read
  // big-endian it is 0x16000000, which is not OBJECT_SIGNATURE. The real 'XBOX'
  // is at +0x10, because the vptr `virtual ~KernelObject` (xdm.h:30) places
  // first pushes the header down by 8.
  //
  // WrapperIdentityMap answers the question soundly, and soundly in BOTH
  // directions: both of its insertion points (CreateRegisteredKernelObject
  // xdm.h:134, QueryKernelObject xdm.h:174) store a pointer produced by
  // CreateKernelObject, so a member is always a HOST object, and a handle that
  // is not a member is guest memory by definition. The comparison is against
  // the map's object rather than a bare membership test so that a stale or
  // replaced entry cannot promote a raw cast: the host read is only legal when
  // `o` IS the registered wrapper.
  //
  // No address-shaped test can replace this, and that is the point: for our own
  // objects guest VA H and host pointer Translate(H) name ONE object - the same
  // bytes - because the guest is handed the wrapper's own guest VA as its
  // handle. "Where did this pointer come from" is not a property of the address.
  // Conversely this WIDENS nothing: each arm still demands OBJECT_SIGNATURE at
  // its own offset, and the two arms are the same two as before, only routed by
  // a discriminator that is true. Probing both offsets and accepting either
  // would be a widening and is refused: a guest page that happens to spell 'XBOX'
  // at +0x10 would then be handed to dynamic_cast as a host object.
  const bool isHostWrapper = (LookupIdentityKernelObject(handle) == o);
  if (isHostWrapper) {
    if (!o->IsValid())
      return nullptr;
  } else {
    uint32_t sig = 0;
    if (!HeapT::Instance().ReadU32BE(
            handle + offsetof(XDISPATCHER_HEADER, WaitListHead.Flink), &sig) ||
        sig != OBJECT_SIGNATURE)
      return nullptr;
  }
  return o;
}
} // namespace

uint32_t NtQueryVirtualMemory(uint32_t baseAddress,
                              be<uint32_t> *memoryBasicInformation) {
  // Xbox 360 semantics (Xenia): (PVOID BaseAddress, PMEMORY_BASIC_INFORMATION).
  // X_MEMORY_BASIC_INFORMATION = 7 BE dwords:
  //   base_address, allocation_base, allocation_protect, region_size,
  //   state (COMMIT/RESERVE/FREE), protect, type (X_MEM_PRIVATE).
  if (!memoryBasicInformation)
    return STATUS_INVALID_PARAMETER;

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  VirtualRegionInfo info;
  if (!mem.QueryVirtualRegion(baseAddress, &info))
    return STATUS_INVALID_PARAMETER;

  const uint32_t xState =
      info.committed ? kXMemCommit : (info.reserved ? kXMemReserve : kXMemFree);
  const uint32_t xProtect =
      (baseAddress != 0 && !info.reserved) ? 0 : kXPageReadWrite;

  memoryBasicInformation[0].set(info.base);
  memoryBasicInformation[1].set(info.allocationBase);
  memoryBasicInformation[2].set(xProtect);
  memoryBasicInformation[3].set(info.size);
  memoryBasicInformation[4].set(xState);
  memoryBasicInformation[5].set(xProtect);
  memoryBasicInformation[6].set(kXMemPrivate);

  static std::atomic<uint32_t> s_queryCalls{0};
  const uint32_t n = s_queryCalls.fetch_add(1) + 1;
  if (n <= 64 || n % 500 == 0) {
    MCLA_LOG_INFO("NtQueryVM #{} base={:08X} region={:08X} size={:08X} "
                  "state={:08X} lr={:08X}",
                  n, baseAddress, info.base, info.size, xState,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }
  return STATUS_SUCCESS;
}

void MmQueryStatistics() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t NtCreateEvent(be<uint32_t> *handle, void *objAttributes,
                       uint32_t eventType, uint32_t initialState) {
  if (!handle) return STATUS_INVALID_PARAMETER;
  // Identity handle (F-039): register so Set/Wait share one Event object.
  // Event type 0 = Notification (manual reset), 1 = Synchronization.
  *handle = CreateRegisteredKernelObject<Event>(
      eventType == 0 ? uint8_t(0) : uint8_t(1), !eventType, !!initialState);

  // EVENT-CREATE CENSUS (2026-08-23 session 10): handle -> creation-LR map.
  // The TU83 driver worker waits on event [0x827D3738+52]=C9ADB800; matching
  // that handle against this census identifies the creation site statically.
  {
    static std::atomic<uint32_t> s_evtCreates{0};
    const uint32_t n = s_evtCreates.fetch_add(1) + 1;
    if (n <= 500) {
      MCLA_LOG_INFO("EVENT-CREATE #{} h={:08X} type={} init={} lr={:08X}", n,
                    static_cast<uint32_t>(*handle), eventType, initialState,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      // TARGETED CENSUS for C9ADB800 (TU83 worker wait event)
      if (static_cast<uint32_t>(*handle) == 0xC9ADB800) {
        MCLA_LOG_WARN(
            "EVENT-CREATE TARGET C9ADB800 h={:08X} type={} init={} lr={:08X}",
            static_cast<uint32_t>(*handle), eventType, initialState,
            static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      }
    }
  }

  return 0;
}

// XexCheckExecutablePrivilege -- F-609, and the verdict here is DELIBERATELY
// NOT a refusal. Reporting that, with the evidence, because the brief listed it
// under "return 1; the comment already admits it".
//
// IT IS NOT IN THE DEFECT CLASS, and the distinction is the whole answer. The
// class is "returns a SUCCESS STATUS FOR WORK NOT PERFORMED". This returns a
// POLICY ANSWER to a query, and the value 1 is a claim about the TITLE, not a
// completion receipt: nothing was supposed to be written, nothing was written,
// and the guest has no buffer to have been lied into. A refusal would be
// strictly worse here -- returning 0 tells the title it lacks a privilege it
// genuinely needs, and the honest-but-useless answer 0 buys nothing that the
// current 1 does not already cost.
//
// THE CURRENT 1 IS NONETHELESS WRONG, and the reference proves it:
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_modules.cc:22-39
//     uint32_t mask = 1 << privilege;
//     auto module = kernel_state()->GetExecutableModule();
//     if (!module) { return 0; }
//     uint32_t flags = 0;
//     module->GetOptHeader<uint32_t>(XEX_HEADER_SYSTEM_FLAGS, &flags);
//     return (flags & mask) > 0;
// It is a real READ of the XEX's XEX_HEADER_SYSTEM_FLAGS opt header
// (XEX_HEADER_SYSTEM_FLAGS = 0x00030000,
// .research/xenia/src/xenia/kernel/util/xex2_info.h:299), masked by the
// privilege BIT POSITION the caller passes. This implementation takes NO
// ARGUMENT AT ALL and returns 1 for every privilege, so it is provably wrong
// for every privilege the XEX does not set -- privilege 6
// (XEX_SYSTEM_INSECURE_SOCKETS, xboxkrnl_modules.cc:27) is the documented
// example.
//
// WHY IT IS NOT FIXED HERE: making it real needs the XEX's system-flags DWORD,
// and nothing in this tree parses it. The only XEX opt-header reader in
// .research/xenia is Xenia's own; this file has XexLoadImageHeaders but no
// opt-header walk, and src/boot_host.cpp (where the XEX is loaded) is owned by
// another agent right now. Inventing a flags value would be a NEW fabrication
// on top of the old one, which is worse than the current lie because it would
// look measured.
//
// SO: the value is unchanged, and the fiction is made VISIBLE and COUNTABLE,
// which is what the stub most lacked -- it had no log line at all, so nothing
// in any soak said the title depended on this answer.
uint32_t XexCheckExecutablePrivilege(uint32_t privilege) {
  static std::atomic<uint64_t> s_seen{0};
  const uint64_t n = s_seen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("XEX-PRIV #{} privilege={} -> 1 (UNCONDITIONAL: the XEX's "
                  "XEX_HEADER_SYSTEM_FLAGS is not parsed anywhere in this tree, "
                  "so the real answer is (flags & (1<<privilege)) != 0 per "
                  "xboxkrnl_modules.cc:22-39 -- this is 1 for every privilege, "
                  "including ones the XEX does not grant) glr={:08X}",
                  n, privilege,
                  g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u);
  }
  return 1;
}

// ---------------------------------------------------------------------------
// DbgPrint -- REAL, F-609 PORT BATCH, 2026-09-29 (integration stream).
//
// WAS: `void DbgPrint() { LOG_UTILITY("!!! STUB !!!"); }`. A `void` body means
// r3 is left equal to the incoming r3, so the guest read its own argument --
// the format-string pointer -- back as a return value, and nothing was ever
// printed or counted. Both live properties are fixed here.
//
// CONTRACT, from the reference, not from recall. Xenia
// .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_strings.cc:827-854
// (DbgPrint_entry):
//   :828-832  arg 0 is the format pointer; a null one returns
//             X_STATUS_INVALID_PARAMETER, which is 0xC000000D
//             (.research/xenia/src/xenia/xbox.h:51) -- the same value this file
//             already returns from NtCreateFile for the same condition
//             (imports.cpp NtCreateFile, STATUS_INVALID_PARAMETER).
//   :835      StackArgList(args, 1) -- firstArg 1, i.e. the first variadic
//             argument is register ordinal 1, because ordinal 0 is the format
//             string itself. port_kobj.h:127 names the same convention.
//   :836-838  StringFormatData over the format, then format_core(..., false).
//             WIDE IS FALSE here (:838). The wide=true call sites in that file
//             are :951, :1070, :1144, :1173 (the w* family), not this one.
//   :839-842  a non-positive character count returns STATUS_SUCCESS.
//   :844-849  trailing whitespace is trimmed off the end.
//   :851      the trimmed text is emitted.
//   :853      STATUS_SUCCESS.
//
// The engine is kobjport::FormatCore (port_kobj.h:156, body port_kobj.cpp:599),
// a faithful port of Xenia format_core (strings.cc:120-683). It is the tree's
// ONLY format engine and it reads the format string and the 9th-and-beyond
// arguments through checked, endian-explicit guest memory -- no
// reinterpret_cast of guest data and no assert on a guest value anywhere in it.
// The alternative was to leave a stub standing beside a working engine, which
// is how two engines drift apart, so the wiring was done here instead.
//
// SIGNATURE DISCIPLINE: `formatVa` is the RAW GUEST VA handed through r3
// untouched, not a translated host pointer. ArgTranslator's non-pointer overload
// (function.h:331) passes an integer argument through unmodified, which is the
// same discipline src/kernel/port_voice_input.cpp uses throughout, and it is
// what lets the IsValid() check below be meaningful instead of validating a
// pointer the framework had already made for us.
// ---------------------------------------------------------------------------
uint32_t DbgPrint(uint32_t formatVa) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  // Census, house cadence (first 8, then every 200th), so a soak can count
  // reachability and distinguish it from a zero.
  static std::atomic<uint64_t> s_dbgSeen{0};
  const uint64_t seen = s_dbgSeen.fetch_add(1, std::memory_order_relaxed) + 1;
  const bool census = (seen <= 8) || ((seen % 200) == 0);

  if (formatVa == 0) {
    if (census) {
      MCLA_LOG_WARN("DBGPRINT #{} format=NULL -> STATUS_INVALID_PARAMETER "
                    "(0xC000000D, xenia xbox.h:51; DbgPrint_entry :829-832) "
                    "lr={:08X}",
                    seen,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u));
    }
    return 0xC000000Du; // X_STATUS_INVALID_PARAMETER
  }

  // Checked range test on the GUEST VA before the engine is handed anything. A
  // bad VA must produce a refusal, never a fault and never a partial write.
  if (!mem.IsValid(formatVa, 1)) {
    if (census) {
      MCLA_LOG_WARN("DBGPRINT #{} format={:08X} is not a readable guest VA -> "
                    "STATUS_INVALID_PARAMETER (0xC000000D) lr={:08X}",
                    seen, formatVa,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u));
    }
    return 0xC000000Du;
  }

  kobjport::GuestFormatData data(formatVa);
  kobjport::GuestStackArgs args(1, mcla::kernel::g_memory.base);
  const int32_t count = kobjport::FormatCore(data, args, /*wide=*/false);

  if (count <= 0) {
    // The reference's own early-out (:839-842): an empty or failed format is
    // not an error, it is nothing to say.
    if (census && data.formatUnreadable()) {
      MCLA_LOG_WARN("DBGPRINT #{} count={} the format string was unreadable "
                    "(guest VA {:08X}) lr={:08X}",
                    seen, count, formatVa,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u));
    }
    return STATUS_SUCCESS;
  }

  // Trailing-whitespace trim, as Xenia :844-849.
  std::string text = data.str();
  const size_t last = text.find_last_not_of(" \t\r\n\f\v");
  if (last == std::string::npos) {
    text.clear();
  } else {
    text.erase(last + 1);
  }

  if (census) {
    MCLA_LOG_INFO("DBGPRINT #{} count={} \"{}\"", seen, count, text);
  } else if (s_dbgSeen.load(std::memory_order_relaxed) == 9) {
    // One unconditional line on the 9th call, so a reader can see the marker is
    // live even if it arrives after the first-8 window.
    MCLA_LOG_INFO("DBGPRINT reached guest DbgPrint; further lines are sampled "
                  "every 200th (marker DBGPRINT, counter in this function)");
  }
  return STATUS_SUCCESS;
}

void __C_specific_handler_x() { LOG_UTILITY("!!! STUB !!!"); }

// ===========================================================================
// F-840 (2026-10-21) -- THE VOID-IMPORT BATCH, part 1: RtlNtStatusToDosError.
//
// WAS: `void RtlNtStatusToDosError() { LOG_UTILITY("!!! STUB !!!"); }`.
//
// WHY THAT IS A LIVE DEFECT AND NOT AN INERT STUB.  A `void` hook body never
// writes r3: src/kernel/function.h:496-499 takes the `void` arm, calls the host
// function and RETURNS WITHOUT TOUCHING THE CONTEXT.  So the guest reads back
// its OWN FIRST ARGUMENT where the console's answer belongs.
//
// WHAT THE GUEST DOES WITH r3, from the guest's own bytes.  The import thunk is
// 0x827BD024 and the guest calls it from 10 distinct sites
// (tools/ppc_xrefs.py calls 0x827BD024).  The load-bearing one is the guest's
// own error-latch helper, generated/ppc_xenon/ppc_recomp.0.cpp:18617-18629:
//
//   18617  bl 0x827bd024
//   18619  __imp__RtlNtStatusToDosError(ctx, base);
//   18620  lwz r11,336(r13)          ; the thread's "already latched?" flag
//   18626  lwz r11,256(r13)          ; r11 = the thread's error block
//   18628  stw r3,352(r11)           ; <error block>->last_error = r3
//
// `stw r3,352(r11)` is the guest STORING the return value into its own Win32
// last-error word.  With the void stub the value stored was the NTSTATUS the
// guest had just passed IN (e.g. 0xC0000034), because r3 was never written.
// A Win32 last-error code is never 0xC00000xx.  Every guest error path that
// funnels through this helper therefore reported a nonsense error code.
//
// THE CONSOLE'S BEHAVIOUR.  The console returns a DOS (Win32) error code:
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_error.cc:974-1016
//     uint32_t xeRtlNtStatusToDosError(uint32_t source_status)
//     dword_result_t RtlNtStatusToDosError_entry(dword_t source_status)
// The algorithm and the value table are reproduced here verbatim.  The values
// are NOT typed by hand: build/agents/_gen_ntstatus.py parses them out of that
// reference file and writes src/kernel/ntstatus_dos_error_table.h
// (14 base codes, 888 entries, generated).
//
// FALSIFIER.  After this change the word the guest latches at
// ppc_recomp.0.cpp:18628 must be a DOS code (<= 0x7FF) and never an NTSTATUS.
// Concretely: a guest failure carrying STATUS_OBJECT_NAME_NOT_FOUND
// (0xC0000034) must latch 2 (ERROR_FILE_NOT_FOUND), NOT 0xC0000034.  If a soak
// still shows 0xC0000034 in that cell, the hook is not reaching this body.
// ===========================================================================
// The reference's own algorithm, xboxkrnl_error.cc:974-1012, in order.
static uint32_t NtStatusToDosErrorImpl(uint32_t sourceStatus) {
  uint32_t status = sourceStatus;
  if (!status || (status & 0x20000000)) {
    return status;
  }

  if ((status >> 16) == 0x8007) {
    return status & 0xFFFF;
  }

  if ((status & 0xF0000000) == 0xD0000000) {
    // High bits do not matter.
    status &= ~0x30000000;
  }

  for (const mcla::kernel::NtStatusDosErrorRow &row :
       mcla::kernel::kNtStatusDosErrorRows) {
    if (!row.base_code) {
      break;
    }
    if (status < row.base_code) {
      break;
    }
    const uint32_t index = status - row.base_code;
    if (index < row.count) {
      const uint32_t result = row.entries[index];
      if (!result) {
        break;
      }
      return result;
    }
  }

  if ((status >> 16) == 0xC001) {
    return status & 0xFFFF;
  }

  // The reference's own fallback (xboxkrnl_error.cc:1011).
  return 317; // ERROR_MR_MID_NOT_FOUND
}

uint32_t RtlNtStatusToDosError(uint32_t sourceStatus) {
  const uint32_t result = NtStatusToDosErrorImpl(sourceStatus);
  // A REAL instrument for this body: the OLD void stub printed NOTHING in a
  // release build (LOG_UTILITY expands to nothing unless _DEBUG is defined,
  // .research/UnleashedRecomp/UnleashedRecomp/os/logger.h:14-18), so the
  // "0 rows" a soak would show proved nothing.  This line prints on every
  // call the body answers, so a soak can show the NTSTATUS -> DOS mapping
  // happening (AGENTS.md rule 19).
  static std::atomic<uint32_t> s_census{0};
  const uint32_t n = s_census.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 20 || (n % 100) == 0) {
    MCLA_LOG_INFO("NT2DOS #{} lr={:08X} status=0x{:08X} -> dos=0x{:X}", n,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u),
                  sourceStatus, result);
  }
  return result;
}

// ===========================================================================
// F-840 (2026-10-21) -- THE VOID-IMPORT BATCH, part 2: XexGetProcedureAddress.
//
// WAS: `void XexGetProcedureAddress() { LOG_UTILITY("!!! STUB !!!"); }`.
//
// THE DEFECT, from the guest's own bytes.  The import thunk is 0x827BD884 and
// the guest calls it from 10 sites (tools/ppc_xrefs.py calls 0x827BD884).  The
// shape at 0x8244A2B0 (generated/ppc_xenon/ppc_recomp.80.cpp:523-544, raw
// bytes confirmed with tools/ppc_disasm.py 0x8244A290 24):
//
//   8244A2A4  addi r5,r1,80      ; r5 = the OUT slot (u32)
//   8244A2A8  lwz  r3,84(r1)     ; r3 = the module handle
//   8244A2AC  li   r4,36         ; r4 = the export ordinal
//   8244A2B0  bl   827BD884      ; XexGetProcedureAddress
//   8244A2B4  cmpi cr0,r3,0
//   8244A2B8  bge  -> 8244A2C8   ; r3 >= 0  =>  SUCCESS path
//   8244A2BC  li   r11,0
//   8244A2C0  stw  r11,80(r1)    ; r3 < 0   =>  out slot := 0
//   8244A2C8  lwz  r11,80(r1)    ; r11 = the out slot
//   8244A2CC  cmpli cr6,r11,0
//   8244A2DC  beq  -> 8244A2F4   ; out slot == 0 => do not call
//   8244A2E8  mtctr r11
//   8244A2EC  bctrl              ; CALLS the out slot AS A FUNCTION POINTER
//
// So the guest's contract is: r3 >= 0 means SUCCESS and the out slot then
// holds the resolved function address; r3 < 0 means FAILURE and the guest
// zeroes the out slot itself and skips the call.
//
// (CORRECTION to build/agents/audit_stubs.md's table row for this import, which
// reads "the guest's own test is cmpwi r3,0 / bge -> error".  It is the other
// way round: `bge` at 8244A2B8 goes to 8244A2C8, which is the path that READS
// the out slot and CALLS it.  `bge` is therefore SUCCESS.  The raw bytes are
// the tiebreaker here, not the audit's prose.)
//
// With the void stub, r3 on return was still the module handle 0x82000000 --
// POSITIVE -- so the guest took the SUCCESS branch and called the out slot,
// which the host never wrote, as a function pointer.  That is an
// UNINITIALISED STACK WORD executed as code.
//
// THE CONSOLE'S BEHAVIOUR, from the reference:
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_modules.cc:142-185
//     dword_result_t XexGetProcedureAddress_entry(lpvoid_t hmodule,
//                                                   dword_t ordinal,
//                                                   lpdword_t out_function_ptr)
//   -> X_STATUS_SUCCESS (0) and *out = the address, OR
//      X_STATUS_DRIVER_ENTRYPOINT_NOT_FOUND (0xC0000263) and *out = 0.
//   .research/xenia/src/xenia/xbox.h:77 -> X_STATUS_DRIVER_ENTRYPOINT_NOT_FOUND
//      = 0xC0000263 (negative, so it lands on the guest's failure branch).
//   The ordinal is an ordinal unless the top 16 bits are set, in which case it
//   is a pointer to the export NAME (xboxkrnl_modules.cc:147-149).
//
// THE EXPORT LOOKUP.  The console resolves the ordinal against the loaded
// module.  For the only module this host has, the game XEX, BOTH export
// sources are EMPTY, measured:
//   * the XEX2 export table: build/game_data/default.xex's Xex2SecurityInfo
//     `exportTable` field is 0 (parsed from the file: XEX2 header at 0x0,
//     security info at 0x90, exportTable at 0x90+0x130 = 0x1C0);
//   * the PE export directory: build/cache/mcla_pe.bin's PE data directory
//     [0] is {rva 0x0, size 0x0} (PE header at 0x108, optional header at
//     0x120, data directories at 0x180).
// The other module the guest asks about is "xbdm.xex"
// (generated/ppc_xenon/ppc_recomp.80.cpp:971, raw `lis r11,8207` /
// `addi r3,r11,-22644` -> 0x8206A78C = "xbdm.xex"), a development-kit module
// that is NOT present on a retail console either.
//
// So for every one of the guest's 10 call sites the console's own answer is
// "not found": a NEGATIVE status and an out slot of 0.  The lookup below is
// still implemented in full (ordinal and name forms, PE export directory read
// out of guest memory) so that the function is CORRECT rather than merely
// always-failing.
//
// FALSIFIER.  The guest must now take its FAILURE branch at every one of the
// 10 sites: r3 must be negative (0xC0000263) and the out slot must be 0, so
// the `bctrl` at 8244A2EC is NEVER reached.  If a soak shows the guest calling
// through the out slot, this body is not running.
// ===========================================================================

// ===========================================================================
// F-841 (2026-10-21) -- MODULE-AWARE XexGetModuleHandle / XexGetProcedureAddress.
//
// THE MEASUREMENT (build/game_data/default.xex + build/cache/mcla_pe.bin):
//
//  * The DECOMPRESSED PE at guest 0x82000000 has NO export directory.
//    build/cache/mcla_pe.bin: DOS header at 0x0, e_lfanew = 0x108, PE
//    signature at 0x108, COFF header at 0x10C (machine 0x1F2, 13 sections,
//    SizeOfOptionalHeader 0xE0), optional header at 0x120 (magic 0x10B,
//    ImageBase 0x82000000, AddressOfEntryPoint 0x1322B8, SizeOfImage
//    0xAD3000), data directories at 0x180, NumberOfRvaAndSizes = 16.
//    DataDirectory[0] (the export directory) = {rva 0x0, size 0x0}.
//    => there is no IMAGE_EXPORT_DIRECTORY to read, for ANY ordinal.
//  * The RETAIL XEX2 container's export table is EMPTY.  default.xex is
//    9,252,864 bytes, magic 'XEX2' at 0x00, security info at file 0x90; in the
//    xex2_security_info layout
//    (.research/xenia/src/xenia/kernel/util/xex2_info.h:570-588) the
//    export_table field is at +0x160 = file 0x1F0 and it is 0.
//    Cross-checks that this really is the security info: header_size at +0x00
//    = 0x1054 = 0x184 + 158*0x18 (the page-descriptor array for
//    page_descriptor_count = 0x9E at +0x180); image_size at +0x04 = 0x9E0000
//    = the size of build/cache/mcla_pe.bin; load_address at +0x110 = 0x82000000.
//
// => The console's answer for every ordinal of the GAME module is "not found",
//    and that is what this host already returns.  The guest is NOT asking about
//    the game module: it asks for exports of two SYSTEM modules, and the
//    console answered those from the XAM and the kernel module images, which
//    this host does not have.
//
// THE GUEST'S OWN REQUESTS (measured from the guest's bytes):
//   0x8275C7B8 (the wrapper) calls XexGetModuleHandle(name) and then
//   XexGetProcedureAddress(handle, ordinal, &out); its ten callers pass
//   ("xam.xex", 442), ("xam.xex", 520) and ("xboxkrnl.exe", 642..649).
//   Three further static sites ask ("xam.xex", 36), ("xam.xex", 80) and
//   ("xbdm.xex", 155).  The names are the guest's own strings:
//   0x8206A5F0 = "xam.xex", 0x820D432C = "xboxkrnl.exe", 0x8206A78C =
//   "xbdm.xex".
//
// WHAT THE CONSOLE WOULD HAVE ANSWERED (the console's export ordinal tables,
// .research/xenia/src/xenia/kernel/<mod>/<mod>_table.inc):
//   xam.xex      442 = XamInputGetUserVibrationLevel
//   xam.xex      520 = XamUserGetDeviceContext
//   xboxkrnl.exe 642..649 = XInputdFFGetDeviceInfo, XInputdFFSetEffect,
//       XInputdFFUpdateEffect, XInputdFFEffectOperation, XInputdFFDeviceControl,
//       XInputdFFSetDeviceGain, XInputdFFCancelIo, XInputdFFSetRumble
//   The ordinals are cross-checked against the host's own import bindings:
//   the same tables give 0x0E7 NtQueryFullAttributesFile, 0x11D
//   RtlCompareStringN, 0x12B RtlImageXexHeaderField, 0x135
//   RtlNtStatusToDosError, 0x195 XexGetModuleHandle and 0x197
//   XexGetProcedureAddress -- the ordinals the title's own XEX imports them
//   under (build/game_data/default.xex).
//
// WHAT THIS HOST CAN ANSWER, AND HOW:
//   The title's own XEX2 import-libraries block records, for every
//   (module, ordinal) the game imports, the GUEST import-thunk address the
//   console's loader binds for it.  That thunk is the address the guest calls
//   for that export, so it is exactly the right value to hand back from
//   XexGetProcedureAddress: the guest's call then reaches the host's
//   implementation of that very console export.  src/kernel/xex_console_exports.h
//   is that table, GENERATED from the retail container (see the header).
//   The guest's ten runtime requests are NOT among the title's imports (the
//   game resolves those at runtime precisely because it does not import them),
//   so they stay NOT FOUND -- honestly, with the console's export NAME in the
//   census line so the next pass sees exactly what the console had.
//
// THE HANDLE IS AN OPAQUE TOKEN.  All four guest call sites of
// XexGetModuleHandle pass the handle straight into XexGetProcedureAddress
// (0x8244A298 -> 0x8244A2B0, 0x8244A4D4 -> 0x8244A4EC, 0x824604DC ->
// 0x824604FC, 0x8275C7DC -> 0x8275C7F4); the guest never dereferences it.  So
// it may be a synthetic per-module token, and it MUST be, because one handle
// for two different modules is how a resolver answers with the WRONG module's
// function.
//
// FALSIFIER: the XEX-GPA census line must name the module and the console
// export; a lookup of a (module, ordinal) pair the title imports must answer
// FOUND with the guest thunk address; a lookup of a pair the title does not
// import must answer NOT FOUND, and the guest must skip the call -- it
// null-checks the out slot before calling it (0x8244A2CC/0x8244A2DC,
// 0x8275C870/0x8275C874, 0x8275C9AC/0x8275C9B0, 0x8275CA10/0x8275CA14).
// ===========================================================================

// The executable module's handle is the guest image base (PROGRAM_GUIDE.md:62,
// AGENTS.md rule 3 / F-023).  The SYSTEM modules get synthetic tokens above
// the guest image and above the AllocateThunk region (0x83000000, app.h:113),
// so a token can never collide with a real guest address or a host thunk.
static constexpr uint32_t kXexExecutableModuleHandle = 0x82000000u;
static constexpr uint32_t kXexSystemModuleHandleBase = 0xA1000000u;

// The console's module names are not case sensitive.
static bool XexModuleNameEquals(const char *a, const char *b) {
  if (!a || !b) {
    return false;
  }
  while (*a && *b) {
    const char ca = (*a >= 'A' && *a <= 'Z') ? static_cast<char>(*a + 32) : *a;
    const char cb = (*b >= 'A' && *b <= 'Z') ? static_cast<char>(*b + 32) : *b;
    if (ca != cb) {
      return false;
    }
    ++a;
    ++b;
  }
  return *a == *b;
}

// The system module whose name the guest passed, or nullptr.
static const mcla::kernel::XexConsoleModule *
XexFindConsoleModuleByName(const char *name) {
  for (const auto &module : mcla::kernel::kXexConsoleModules) {
    if (XexModuleNameEquals(module.name, name)) {
      return &module;
    }
  }
  return nullptr;
}

// The system module a handle stands for, or nullptr.
static const mcla::kernel::XexConsoleModule *
XexFindConsoleModuleByHandle(uint32_t handle) {
  if (handle < kXexSystemModuleHandleBase) {
    return nullptr;
  }
  const uint32_t index = handle - kXexSystemModuleHandleBase;
  const uint32_t count = sizeof(mcla::kernel::kXexConsoleModules) /
                         sizeof(mcla::kernel::kXexConsoleModules[0]);
  if (index >= count) {
    return nullptr;
  }
  return &mcla::kernel::kXexConsoleModules[index];
}

// The console export with this ordinal in this module, or nullptr.  The
// export's thunk_va is 0 when this title does not import it, i.e. when the
// host has no address to hand back.
static const mcla::kernel::XexConsoleExport *
XexFindConsoleExport(const mcla::kernel::XexConsoleModule &module,
                     uint16_t ordinal) {
  for (uint32_t i = 0; i < module.export_count; i++) {
    if (module.exports[i].ordinal == ordinal) {
      return &module.exports[i];
    }
  }
  return nullptr;
}

// The console export with this NAME in this module, or nullptr.
static const mcla::kernel::XexConsoleExport *
XexFindConsoleExportByName(const mcla::kernel::XexConsoleModule &module,
                            const char *name) {
  for (uint32_t i = 0; i < module.export_count; i++) {
    if (XexModuleNameEquals(module.exports[i].name, name)) {
      return &module.exports[i];
    }
  }
  return nullptr;
}

// The PE image inside an XEX is a LITTLE-endian PE
// (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_rtl.cc:320 -- "Little-
// endian! no swapping!"), so the PE header fields are read little-endian out
// of GUEST memory.  ReadBytes is the checked accessor (src/kernel/memory.h:
// 109); assembling the word by hand avoids adding an unchecked pointer read.
static bool GuestReadU32LE(uint32_t guestAddr, uint32_t *out) {
  if (!out) {
    return false;
  }
  uint8_t bytes[4] = {};
  if (!mcla::kernel::GuestMemoryHeap::Instance().ReadBytes(guestAddr, bytes, 4)) {
    return false;
  }
  *out = static_cast<uint32_t>(bytes[0]) |
         (static_cast<uint32_t>(bytes[1]) << 8) |
         (static_cast<uint32_t>(bytes[2]) << 16) |
         (static_cast<uint32_t>(bytes[3]) << 24);
  return true;
}

static bool GuestReadU16LE(uint32_t guestAddr, uint16_t *out) {
  if (!out) {
    return false;
  }
  uint8_t bytes[2] = {};
  if (!mcla::kernel::GuestMemoryHeap::Instance().ReadBytes(guestAddr, bytes, 2)) {
    return false;
  }
  *out = static_cast<uint16_t>(bytes[0] | (bytes[1] << 8));
  return true;
}

// Read a NUL-terminated ASCII string out of guest memory.  Bounded so a
// runaway guest string cannot walk the host's stack.
static bool GuestReadCString(uint32_t guestAddr, char *out, size_t capacity) {
  if (!out || capacity == 0) {
    return false;
  }
  for (size_t i = 0; i + 1 < capacity; i++) {
    uint8_t byte = 0;
    if (!mcla::kernel::GuestMemoryHeap::Instance().ReadU8(guestAddr + i, &byte)) {
      return false;
    }
    out[i] = static_cast<char>(byte);
    if (byte == 0) {
      return true;
    }
  }
  return false;
}

// Resolve an export inside a module that is mapped in guest memory.
//   moduleBase : the guest VA the module is mapped at
//   ordinal    : the PE export ordinal, or (top 16 bits set) the guest VA of
//                the export NAME
// Returns the guest VA of the exported function, or 0 when it does not exist.
//
// RVA -> VA uses the identity map this tree already relies on for the guest
// image (the module base IS the image base: the measured section table of
// build/cache/mcla_pe.bin puts .text at RVA 0x130000 and the guest image at
// 0x82000000, so VA = base + RVA; the same fact is recorded at
// src/kernel/imports.cpp:6550-6562).
static uint32_t ResolveGuestModuleExport(uint32_t moduleBase, uint32_t ordinal) {
  if (!moduleBase) {
    return 0;
  }

  // --- PE header -----------------------------------------------------------
  uint32_t lfanew = 0;
  if (!GuestReadU32LE(moduleBase + 0x3C, &lfanew) || lfanew > 0x10000000u) {
    return 0;
  }
  const uint32_t ntHeader = moduleBase + lfanew;
  uint32_t signature = 0;
  if (!GuestReadU32LE(ntHeader, &signature) || signature != 0x00004550u) {
    return 0; // not a PE
  }
  const uint32_t optHeader = ntHeader + 24;
  uint16_t optMagic = 0;
  if (!GuestReadU16LE(optHeader, &optMagic) ||
      (optMagic != 0x010Bu && optMagic != 0x020Bu)) {
    return 0;
  }
  uint32_t numberOfRvaAndSizes = 0;
  if (!GuestReadU32LE(optHeader + 0x5C, &numberOfRvaAndSizes) ||
      numberOfRvaAndSizes < 1) {
    return 0;
  }
  const uint32_t dataDirectories = optHeader + 0x60;
  uint32_t exportRva = 0;
  uint32_t exportSize = 0;
  if (!GuestReadU32LE(dataDirectories + 0, &exportRva) ||
      !GuestReadU32LE(dataDirectories + 4, &exportSize) || exportRva == 0) {
    return 0; // no export directory
  }

  // --- export directory ----------------------------------------------------
  const uint32_t exportDir = moduleBase + exportRva;
  uint32_t ordinalBase = 0;
  uint32_t numberOfFunctions = 0;
  uint32_t numberOfNames = 0;
  uint32_t addressOfFunctions = 0;
  uint32_t addressOfNames = 0;
  uint32_t addressOfNameOrdinals = 0;
  if (!GuestReadU32LE(exportDir + 0x10, &ordinalBase) ||
      !GuestReadU32LE(exportDir + 0x14, &numberOfFunctions) ||
      !GuestReadU32LE(exportDir + 0x18, &numberOfNames) ||
      !GuestReadU32LE(exportDir + 0x1C, &addressOfFunctions) ||
      !GuestReadU32LE(exportDir + 0x20, &addressOfNames) ||
      !GuestReadU32LE(exportDir + 0x24, &addressOfNameOrdinals)) {
    return 0;
  }

  // The function table index.  The PE spec makes the ORDINAL Base + index
  // (the reference's XEX2 path subtracts the base explicitly,
  // .research/xenia/src/xenia/cpu/xex_module.cc:129; its PE path does not,
  // :153-155, which is a divergence in the reference, not in the format).
  auto functionAt = [&](uint32_t index) -> uint32_t {
    if (index >= numberOfFunctions) {
      return 0;
    }
    uint32_t functionRva = 0;
    if (!GuestReadU32LE(moduleBase + addressOfFunctions + index * 4, &functionRva)) {
      return 0;
    }
    if (functionRva == 0) {
      return 0; // a hole in the export table
    }
    return moduleBase + functionRva;
  };

  if ((ordinal & 0xFFFF0000u) != 0) {
    // NAME form: the ordinal is a guest VA holding the export name.
    char wanted[256] = {};
    if (!GuestReadCString(ordinal, wanted, sizeof(wanted))) {
      return 0;
    }
    for (uint32_t i = 0; i < numberOfNames; i++) {
      uint32_t nameRva = 0;
      if (!GuestReadU32LE(moduleBase + addressOfNames + i * 4, &nameRva) || nameRva == 0) {
        return 0;
      }
      char name[256] = {};
      if (!GuestReadCString(moduleBase + nameRva, name, sizeof(name))) {
        return 0;
      }
      if (std::strcmp(name, wanted) != 0) {
        continue;
      }
      uint16_t index = 0;
      if (!GuestReadU16LE(moduleBase + addressOfNameOrdinals + i * 2, &index)) {
        return 0;
      }
      return functionAt(index);
    }
    return 0;
  }

  if (ordinal < ordinalBase) {
    return 0;
  }
  return functionAt(ordinal - ordinalBase);
}

uint32_t XexGetProcedureAddress(uint32_t hModule, uint32_t ordinal,
                                be<uint32_t> *outProc) {
  if (!outProc) {
    // STATUS_INVALID_PARAMETER, 0xC000000D
    // (.research/xenia/src/xenia/xbox.h:51).
    return 0xC000000D;
  }

  // The console zeroes the out slot on failure
  // (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_modules.cc:179) and
  // writes the address on success (:167).
  //
  // F-841: the lookup is MODULE-AWARE.  The handle says which module the
  // guest means, because the same ordinal means different exports in
  // different modules (xam.xex#642 is XamGetSystemVersion, xboxkrnl.exe#642
  // is XInputdFFGetDeviceInfo -- both measured in the console's export
  // tables).  Answering without knowing the module is how a resolver hands
  // back the wrong function.
  uint32_t resolved = 0;
  const char *moduleName = "<unknown>";
  const char *exportName = nullptr;
  const bool nameForm = (ordinal & 0xFFFF0000u) != 0;

  if (hModule == kXexExecutableModuleHandle) {
    // The executable module: its own PE export directory, read out of guest
    // memory.  In this title it is EMPTY (DataDirectory[0] = {0,0}), so this
    // always fails -- which is the console's answer too.
    moduleName = "<executable>";
    resolved = ResolveGuestModuleExport(hModule, ordinal);
  } else {
    const mcla::kernel::XexConsoleModule *module =
        XexFindConsoleModuleByHandle(hModule);
    if (module) {
      moduleName = module->name;
      if (nameForm) {
        // The console's name form: the ordinal is a guest VA holding the
        // export name (xboxkrnl_modules.cc:147-149).
        char wanted[128] = {};
        if (GuestReadCString(ordinal, wanted, sizeof(wanted))) {
          const mcla::kernel::XexConsoleExport *entry =
              XexFindConsoleExportByName(*module, wanted);
          if (entry) {
            exportName = entry->name;
            resolved = entry->thunk_va;
          }
        }
      } else {
        const mcla::kernel::XexConsoleExport *entry =
            XexFindConsoleExport(*module, static_cast<uint16_t>(ordinal & 0xFFFFu));
        if (entry) {
          exportName = entry->name;
          // The guest thunk the console's loader binds for this export, or 0
          // when this title does not import it (then the host has no address
          // to hand back and the console's own answer is the only honest one).
          resolved = entry->thunk_va;
        }
      }
    }
  }

  if (resolved == 0) {
    outProc->set(0);
    // House cadence: the first few, then every 100th.  The counter is a REAL
    // instrument for this body -- it prints on every call it answers, so a
    // soak can prove the import fired (AGENTS.md rule 19: a zero from an
    // instrument that never fires is not a result).
    static std::atomic<uint32_t> s_census{0};
    const uint32_t n = s_census.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 20 || (n % 100) == 0) {
      MCLA_LOG_WARN("XEX-GPA #{} lr={:08X} module={:08X} name={} ordinal={} "
                    "export={} -> NOT FOUND "
                    "(0xC0000263 X_STATUS_DRIVER_ENTRYPOINT_NOT_FOUND)",
                    n, static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u),
                    hModule, moduleName, ordinal,
                    exportName ? exportName : "?");
    }
    // X_STATUS_DRIVER_ENTRYPOINT_NOT_FOUND, 0xC0000263
    // (.research/xenia/src/xenia/xbox.h:77).  Negative, so the guest's
    // `cmpwi r3,0 / bge` takes its FAILURE branch.
    return 0xC0000263;
  }

  outProc->set(resolved);
  {
    static std::atomic<uint32_t> s_censusFound{0};
    const uint32_t n = s_censusFound.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 20 || (n % 100) == 0) {
      MCLA_LOG_WARN("XEX-GPA-FOUND #{} lr={:08X} module={:08X} name={} "
                    "ordinal={} export={} -> FOUND 0x{:08X}",
                    n, static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u),
                    hModule, moduleName, ordinal,
                    exportName ? exportName : "?", resolved);
    }
  }
  return STATUS_SUCCESS;
}

void XexGetModuleSection() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t RtlUnicodeToMultiByteN(char *MultiByteString,
                                uint32_t MaxBytesInMultiByteString,
                                be<uint32_t> *BytesInMultiByteString,
                                const be<uint16_t> *UnicodeString,
                                uint32_t BytesInUnicodeString) {
  const auto reqSize = BytesInUnicodeString / sizeof(uint16_t);

  if (BytesInMultiByteString)
    BytesInMultiByteString->set(reqSize);

  if (reqSize > MaxBytesInMultiByteString)
    return STATUS_FAIL_CHECK;

  const be<uint16_t> *src = UnicodeString;
  if (!src)
    return STATUS_FAIL_CHECK;

  for (size_t i = 0; i < reqSize; i++) {
    uint16_t c = src[i].get();

    MultiByteString[i] = c < 256 ? static_cast<char>(c) : '?';
  }

  return STATUS_SUCCESS;
}

uint32_t KeDelayExecutionThread(uint32_t WaitMode, bool Alertable,
                                be<int64_t> *Timeout) {
  // PARK-SAMPLE: census ALL threads at wait entry
  {
    static std::atomic<uint32_t> s_waitCensus{0};
    const uint32_t n = s_waitCensus.fetch_add(1) + 1;
    if (n <= 60 || (n % 5000) == 0) {
      const uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);
      const char* tclass = (timeout == 0) ? "poll" : (timeout == INFINITE) ? "inf" : "finite";
      MCLA_LOG_INFO("PARK-CENSUS[KDELAY] #{:04} tid={:08X} class={} lr={:08X}",
                    n, GetCurrentThreadId(), tclass,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }
  // We don't do async file reads.
  if (Alertable)
    return STATUS_USER_APC;

  uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);

  // PRODUCER-DEATH CENSUS: long delays from the driver range are producer
  // parks in a timing loop (classification D candidates).
  {
    static std::atomic<uint32_t> s_wcDelay{0};
    const uint32_t lr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0;
    const bool hot = lr >= 0x82410000u && lr < 0x82430000u;
    if ((hot && timeout >= 1) || ++s_wcDelay <= 60) {
      MCLA_LOG_INFO("WAIT[KDELAY] tid={:08X} to={}ms lr={:08X}{}",
                    GetCurrentThreadId(), timeout, lr, hot ? " !" : "");
    }
  }

  // MAIN-THREAD PARK PROBE: name where the guest main loop sleeps.
  {
    static std::atomic<uint32_t> s_parkLogs{0};
    uint32_t mainId = g_mainGuestThreadId.load();
    if (mainId != 0 && GetCurrentThreadId() == mainId && timeout >= 8 &&
        s_parkLogs.fetch_add(1) < 200) {
      MCLA_LOG_INFO("[main-park] KeDelayExecutionThread timeout={}ms lr={:08X}",
                    timeout,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

#ifdef _WIN32
  Sleep(timeout);
#else
  if (timeout == 0)
    std::this_thread::yield();
  else
    std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
#endif

  return STATUS_SUCCESS;
}

// ---------------------------------------------------------------------------
// ExFreePool(base_address) -- F-609, made REAL. Was `void ExFreePool() {
// LOG_UTILITY("!!! STUB !!!"); }`: no parameters (so the hook never read r3),
// no free, and a 15-frees-against-79,985-allocations shape in every soak.
//
// THE CONTRACT IS XENIA'S, cited, and it is one line:
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_memory.cc:604-607
//     void ExFreePool_entry(lpvoid_t base_address) {
//       kernel_state()->memory()->SystemHeapFree(base_address);
//     }
// i.e. a VOID function whose only argument is the base address the matching
// ExAllocatePoolTypeWithTag returned. The argument is r3: unlike the NetDll
// family (see the note above NetDll_WSAStartup) xboxkrnl exports take no
// leading selector, and the sibling allocation side in this same file
// (ExAllocatePoolTypeWithTag, below) is hooked with four typed parameters and
// works, which is the cross-check.
//
// THE COUNTERPART IS THIS FILE, not Xenia. `kernel_memory()->SystemHeapFree`
// has no analogue here, so the pool this frees from is the one
// ExAllocatePoolTypeWithTag (below) actually allocates from:
//   g_userHeap.Alloc(n)  ->  GuestMemoryHeap::MapVirtual(ptr)
// so the free is g_userHeap.Free() of the translated guest VA. Xenia's size
// question does not arise and NO size is invented, for the same reason the
// XTL free above does not invent one: Heap::Free never reads a size
// (src/kernel/memory.cpp:346) and the footprint is recovered host-side from
// the o1heap fragment header by Heap::Free itself.
//
// ORDER OF ARENAS IS THE LOAD-BEARING DETAIL and it is the OPPOSITE of the
// XTL free above. XTL blocks come from GuestMemoryHeap::Alloc ->
// g_userHeap.AllocPhysical, so __xtl_free probes phys first. THIS pool is
// g_userHeap.Alloc (the user arena), so the user arena is probed FIRST and
// phys second. Both arenas are probed, because ExAllocatePoolTypeWithTag is not
// the only producer of guest-visible pool blocks, and a wrong-arena free is a
// corruption, not a leak.
//
// SAFETY, which matters more here than in most: every guest-controlled value
// is validated by the heap's OWN predicate (Heap::IsLiveAllocation,
// src/kernel/heap.h:57) BEFORE anything is handed back. If the register decode
// were wrong, or the pointer were foreign, interior, or already freed, the
// probe refuses and this becomes a counted refusal -- it can never reach
// o1heapFree. No assert on a guest value (asserts are compiled out under
// /DNDEBUG, src/kernel/function.h:145 etc.).
// ---------------------------------------------------------------------------
namespace {
// F-609: attempts are counted separately from honoured frees and from refused
// frees, so a soak can distinguish "the title never calls ExFreePool" from
// "the title calls it and we turn it away". That distinction is the whole
// measurement, and the old stub could produce neither number.
std::atomic<uint64_t> g_xpoolFreeSeen{0};
std::atomic<uint64_t> g_xpoolFreeOk{0};
std::atomic<uint64_t> g_xpoolFreeRej{0};
} // namespace

void ExFreePool(uint32_t baseAddress) {
  const uint64_t seen =
      g_xpoolFreeSeen.fetch_add(1, std::memory_order_relaxed) + 1;

  // Below the 4 KiB null guard: guest 0, or the PAGE_NOACCESS window. Freed
  // nothing; say so rather than silently succeeding on a nonsense address.
  if (baseAddress == 0 || baseAddress < 4096u) {
    g_xpoolFreeRej.fetch_add(1, std::memory_order_relaxed);
    if (seen <= 8 || (seen % 200) == 0) {
      MCLA_LOG_WARN("XPOOL-FREE #{} base={:08X} -> refused: below the 4 KiB null "
                    "guard (guest 0 or the PAGE_NOACCESS window); no free "
                    "performed",
                    seen, baseAddress);
    }
    return;
  }

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  void *host = mem.Translate(baseAddress);
  if (host == nullptr) {
    g_xpoolFreeRej.fetch_add(1, std::memory_order_relaxed);
    if (seen <= 8 || (seen % 200) == 0) {
      MCLA_LOG_WARN(
          "XPOOL-FREE #{} base={:08X} -> refused: not inside the guest window; "
          "no free performed",
          seen, baseAddress);
    }
    return;
  }

  // Validate with the heap's own predicate so "honoured" is counted under the
  // same rule Heap::Free will apply, not a second weaker copy of it.
  // IsLiveAllocation is [[nodiscard]] and cannot fault: it range-checks,
  // alignment-checks, then reads a 32-byte header it has already proved in
  // bounds. This pool is the USER arena (see the note above), so user is first.
  Heap::LiveProbe probe{};
  const bool usr = g_userHeap.IsLiveAllocation(
      g_userHeap.heapArenaBase, g_userHeap.heapArenaSize, host, &probe);
  const bool phys =
      !usr && g_userHeap.IsLiveAllocation(g_userHeap.physArenaBase,
                                          g_userHeap.physArenaSize, host, &probe);

  if (!usr && !phys) {
    g_xpoolFreeRej.fetch_add(1, std::memory_order_relaxed);
    if (seen <= 8 || (seen % 200) == 0) {
      const uint32_t glr =
          g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
      MCLA_LOG_WARN("XPOOL-FREE #{} base={:08X} -> REFUSED reason={} bytes "
                    "kept (no free performed) seen={} ok={} rej={} glr={:08X}",
                    seen, baseAddress, XtlFreeProbeReason(probe.reason), seen,
                    g_xpoolFreeOk.load(std::memory_order_relaxed),
                    g_xpoolFreeRej.load(std::memory_order_relaxed), glr);
    }
    return;
  }

  // Hand it back. The size argument is unused (src/kernel/memory.cpp:346) and
  // is passed as 0 to say so rather than to invent a size; Heap::Free
  // re-probes and AcctFrees probe.size -- the same unit AcctAlloc added.
  mem.Free(baseAddress, 0);

  g_xpoolFreeOk.fetch_add(1, std::memory_order_relaxed);
  if (seen <= 8 || (seen % 200) == 0) {
    const uint32_t glr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    MCLA_LOG_WARN("XPOOL-FREE #{} base={:08X} -> HONOURED frag={:#x} arena={} "
                  "seen={} ok={} rej={} glr={:08X}",
                  seen, baseAddress, probe.size, usr ? "user" : "phys", seen,
                  g_xpoolFreeOk.load(std::memory_order_relaxed),
                  g_xpoolFreeRej.load(std::memory_order_relaxed), glr);
  }
  // void: there is no status to return, so there is no success claim left to
  // launder. The marker is the whole result surface.
}

// NtQueryInformationFile: real typed implementation lives above (near
// NtCreateFile) - it answers X_FILE_STANDARD_INFORMATION with true sizes.

// NOTE: no-arg stubs for these three used to sit here UNWIRED - the game's
// metadata queries fell through to generated weak defaults returning garbage,
// which is exactly why packfile loading reported "Cannot load archive" without
// a single read. All three are typed + hooked now.

// X_FILE_FS_INFORMATION_CLASS values for the 360 (Xenia
// .research/xenia/src/xenia/kernel/info/volume.h:18-23 - the same enumeration
// the reference dispatch uses):
//   1 XFileFsVolumeInformation, 3 XFileFsSizeInformation,
//   4 XFileFsDeviceInformation, 5 XFileFsAttributeInformation.
namespace {
constexpr uint32_t kXFileFsVolumeInformation = 1;
constexpr uint32_t kXFileFsSizeInformation = 3;
constexpr uint32_t kXFileFsDeviceInformation = 4;
constexpr uint32_t kXFileFsAttributeInformation = 5;

// Minimum buffer the reference requires per class
// (xboxkrnl_io_info.cc:264-278). 0 == class unknown.
constexpr uint32_t VolumeInfoMinimumLength(uint32_t infoClass) {
  switch (infoClass) {
    case kXFileFsVolumeInformation:
      return 24; // X_FILE_FS_VOLUME_INFORMATION, volume.h:28-36
    case kXFileFsSizeInformation:
      return 24; // X_FILE_FS_SIZE_INFORMATION,    volume.h:39-44
    case kXFileFsDeviceInformation:
      return 8;
    case kXFileFsAttributeInformation:
      return 16; // X_FILE_FS_ATTRIBUTE_INFORMATION, volume.h:48-55
    default:
      return 0;
  }
}
} // namespace

// NtQueryVolumeInformationFile(FileHandle, IoStatusBlock, FsInformation,
//                              FsInformationLength, FsInformationClass).
//
// F-609: this used to zero 64 bytes and return STATUS_SUCCESS for EVERY
// handle and EVERY class - the game could not tell a mounted volume from a
// disassembled one. Structure/limits now follow the reference
// (xboxkrnl_io_info.cc:280-356) exactly:
//
//   class 1 VOLUME      -> real: our single mount has no creation time, no
//                          serial number and no label, so all three are 0.
//   class 3 SIZE        -> HONEST-FAIL. RpfVirtualFileSystem keeps no
//                          allocation-unit accounting at all (vfs_rpf.h:39-101
//                          has no size/free fields, and nothing in src/ calls
//                          space()/GetDiskFreeSpace), so total/available
//                          allocation units cannot be answered. STATUS_NOT_
//                          SUPPORTED, logged, rather than a fabricated 0 that
//                          reads as "the volume is empty".
//   class 4 DEVICE      -> HONEST-FAIL STATUS_NOT_SUPPORTED (reference asserts
//                          on it too, xboxkrnl_io_info.cc:341-347).
//   class 5 ATTRIBUTE   -> real: the mount is a read-only path index with no
//                          object support, which is what attributes=0,
//                          component_name_max_length=0, name_length=0 says.
//   anything else       -> STATUS_INVALID_INFO_CLASS (reference, :284-286).
//   bad/short buffers   -> STATUS_INFO_LENGTH_MISMATCH (reference, :288-290).
//   non-file handle     -> STATUS_INVALID_HANDLE (reference, :292-295).
uint32_t NtQueryVolumeInformationFile(uint32_t handle,
                                      XIO_STATUS_BLOCK *ioStatus, void *fsInfo,
                                      uint32_t length, uint32_t infoClass) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  const uint32_t minimum = VolumeInfoMinimumLength(infoClass);
  if (minimum == 0) {
    MCLA_LOG_WARN("NtQueryVolumeInformationFile: class={} -> "
                  "STATUS_INVALID_INFO_CLASS lr={:08X}",
                  infoClass,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INVALID_INFO_CLASS);
      ioStatus->Information.set(0);
    }
    return STATUS_INVALID_INFO_CLASS;
  }

  if (length < minimum) {
    MCLA_LOG_WARN("NtQueryVolumeInformationFile: class={} len={} < {} -> "
                  "STATUS_INFO_LENGTH_MISMATCH lr={:08X}",
                  infoClass, length, minimum,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INFO_LENGTH_MISMATCH);
      ioStatus->Information.set(0);
    }
    return STATUS_INFO_LENGTH_MISMATCH;
  }

  // The handle must really be a file in the VFS before we describe its volume.
  FileObject *fileObj = dynamic_cast<FileObject *>(ResolveKernelObjectSafe(handle));
  if (!fileObj) {
    MCLA_LOG_WARN("NtQueryVolumeInformationFile: handle={:08X} is not a VFS "
                  "file -> STATUS_INVALID_HANDLE lr={:08X}",
                  handle,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INVALID_HANDLE);
      ioStatus->Information.set(0);
    }
    return STATUS_INVALID_HANDLE;
  }

  if (!fsInfo) {
    MCLA_LOG_WARN("NtQueryVolumeInformationFile: class={} with a null buffer -> "
                  "STATUS_INVALID_PARAMETER lr={:08X}",
                  infoClass,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INVALID_PARAMETER);
      ioStatus->Information.set(0);
    }
    return STATUS_INVALID_PARAMETER;
  }

  const uint32_t addr = mem.MapVirtual(fsInfo);
  if (addr == 0 || !mem.IsValid(addr, minimum)) {
    MCLA_LOG_WARN("NtQueryVolumeInformationFile: buffer outside the guest window "
                  "(class={} len={}) -> STATUS_ACCESS_VIOLATION lr={:08X}",
                  infoClass, length,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    if (ioStatus) {
      ioStatus->Status.set(0xC0000005);
      ioStatus->Information.set(0);
    }
    return 0xC0000005;
  }

  // The reference zeroes the caller's whole length up front
  // (xboxkrnl_io_info.cc:297) so the guest never sees stale bytes past
  // outLength. `length` is guest-controlled, so the zero fill is clamped twice:
  // to a bounded scratch size (the largest class here is 24 bytes) and to what
  // is actually left in the window. Without the first clamp a guest passing
  // 0xFFFFFFFF would ask the host for a 4 GiB vector.
  {
    constexpr uint32_t kMaxZeroFill = 4096;
    const uint32_t zeroable =
        std::min<uint32_t>(std::min<uint32_t>(length, kMaxZeroFill),
                           static_cast<uint32_t>(mem.Size() - addr));
    std::vector<uint8_t> zeros(zeroable, 0);
    if (zeroable)
      (void)mem.WriteBytes(addr, zeros.data(), zeroable);
  }

  uint32_t outLength = 0;
  uint32_t status = STATUS_SUCCESS;

  switch (infoClass) {
    case kXFileFsVolumeInformation: {
      // X_FILE_FS_VOLUME_INFORMATION, volume.h:28-36:
      //   creation_time(8) serial_number(4) label_length(4) supports_objects(1)
      (void)mem.WriteU64BE(addr + 0, 0);  // creation_time: none recorded
      (void)mem.WriteU32BE(addr + 8, 0);  // serial_number: none assigned
      (void)mem.WriteU32BE(addr + 12, 0); // label_length: the mount has no name
      (void)mem.WriteU8(addr + 16, 0);    // supports_objects: no named streams
      outLength = 20;                     // offsetof(label)
      break;
    }

    case kXFileFsSizeInformation: {
      // No allocation-unit accounting exists anywhere in the VFS. Saying 0
      // would tell the game the volume is full; failing is the honest answer.
      static std::atomic<uint32_t> s_sizeQ{0};
      const uint32_t n = s_sizeQ.fetch_add(1) + 1;
      MCLA_LOG_WARN("NtQueryVolumeInformationFile: FS_SIZE_INFORMATION on '{}' "
                    "-> STATUS_NOT_SUPPORTED #{} (no allocation-unit accounting "
                    "in RpfVirtualFileSystem) lr={:08X}",
                    fileObj->fileHandle.virtual_path, n,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      status = 0xC00000BB; // STATUS_NOT_SUPPORTED
      outLength = 0;
      break;
    }

    case kXFileFsDeviceInformation: {
      MCLA_LOG_WARN("NtQueryVolumeInformationFile: FS_DEVICE_INFORMATION on '{}' "
                    "-> STATUS_NOT_SUPPORTED lr={:08X}",
                    fileObj->fileHandle.virtual_path,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      status = 0xC00000BB; // STATUS_NOT_SUPPORTED
      outLength = 0;
      break;
    }

    case kXFileFsAttributeInformation: {
      // X_FILE_FS_ATTRIBUTE_INFORMATION, volume.h:48-55:
      //   attributes(4) component_name_max_length(4) name_length(4) name[]
      // The mount IS read-only (every open is GENERIC_READ, vfs_rpf.cpp:498)
      // and IS a path index with no object support, so the honest report is a
      // zeroed record - which is exactly what the reference emits for a device
      // with no name (xboxkrnl_io_info.cc:324-340).
      (void)mem.WriteU32BE(addr + 0, 0);  // attributes
      (void)mem.WriteU32BE(addr + 4, 0);  // component_name_max_length
      (void)mem.WriteU32BE(addr + 8, 0);  // name_length
      outLength = 12;                    // offsetof(name)
      break;
    }

    default:
      status = STATUS_INVALID_INFO_CLASS;
      outLength = 0;
      break;
  }

  if (ioStatus) {
    ioStatus->Status.set(status);
    ioStatus->Information.set(outLength);
  }

  static std::atomic<uint32_t> s_volQ{0};
  const uint32_t n = s_volQ.fetch_add(1) + 1;
  if (n <= 40 || (n % 500) == 0)
    MCLA_LOG_INFO("NtQueryVolumeInformationFile #{} h={:08X} path='{}' class={} "
                  "len={} -> st={:08X} out={} lr={:08X}",
                  n, handle, fileObj->fileHandle.virtual_path, infoClass,
                  length, status, outLength,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));

  return status;
}

// X_FILE_DIRECTORY_INFORMATION record, field offsets from Xenia
// .research/xenia/src/xenia/kernel/xfile.h:36-49 (NextEntryOffset 0x00,
// FileIndex 0x04, 4x LARGE_INTEGER times 0x08..0x27, EndOfFile 0x28,
// AllocationSize 0x30, FileAttributes 0x38, FileNameLength 0x3C, name 0x40).
namespace {
constexpr uint32_t kDirInfoHeaderSize = 0x40;
constexpr uint32_t kFileAttributeDirectory = 0x00000010;
constexpr uint32_t kFileAttributeNormal = 0x00000080;

// Per-handle enumeration cursor. Real NT keeps a per-file "next index"; the
// VFS index (RpfVirtualFileSystem::ListDirectory) is a plain vector, so the
// cursor has to live somewhere. Keyed by the file handle.
Mutex g_dirScanLock;
std::unordered_map<uint32_t, size_t> g_dirScanCursor;

// Case-insensitive ASCII compare, no locale, no allocation - directory names
// come from the host index and the guest pattern is ASCII.
bool DirNameEqualsNoCase(const char *a, const char *b) {
  for (;; ++a, ++b) {
    const char ca = *a, cb = *b;
    const char la = (ca >= 'A' && ca <= 'Z') ? static_cast<char>(ca + 32) : ca;
    const char lb = (cb >= 'A' && cb <= 'Z') ? static_cast<char>(cb + 32) : cb;
    if (la != lb)
      return false;
    if (la == '\0')
      return true;
  }
}
} // namespace

// NtQueryDirectoryFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock,
//                      FileInformation, Length, FileName, RestartScan).
//
// SIGNATURE NOTE (F-609): the 360 export is the 9-argument form with an
// XANSI_STRING* FileName and a RestartScan flag, per Xenia
// .research/xenia/.../xboxkrnl_io.cc:547-551. The previous declaration here
// used the Win2k 11-argument NT form, which mis-reads r8/r9 for this title.
//
// F-609: it also returned STATUS_NO_MORE_FILES unconditionally, so the game saw
// "this directory is empty" for every handle, class and buffer - including
// handles that are not directories at all. Now:
//
//   * handle is not a VFS file          -> STATUS_INVALID_HANDLE
//   * file is not a directory          -> STATUS_INVALID_PARAMETER (this is
//     what real hardware answers for NtQueryDirectoryFile on a file handle,
//     xboxkrnl_io.cc:567-576 which fails the same way for a missing object)
//   * file IS a directory in the index -> REAL enumeration out of
//     RpfVirtualFileSystem::ListDirectory, packed as
//     FILE_DIRECTORY_INFORMATION, cursor resumed between calls, exhausted ->
//     STATUS_NO_MORE_FILES (the honest "no more entries", not a default).
//
// KNOWN GAP, and it is an infrastructure gap rather than a missing index:
// RpfVirtualFileSystem::OpenFile REFUSES directories (vfs_rpf.cpp:493-496),
// and NtCreateFile only hands back an empty pseudo-file for \\Device\\ paths
// (imports.cpp NtCreateFile). So no directory handle can be produced by the
// current open path and the enumeration arm below is currently unreachable.
// It is implemented anyway, against the real index, so the day directory opens
// exist the behaviour is already correct - and the unreachable arm says so
// loudly rather than faking a populated directory.
uint32_t NtQueryDirectoryFile(uint32_t handle, uint32_t event,
                              uint32_t apcRoutine, uint32_t apcContext,
                              XIO_STATUS_BLOCK *ioStatus, void *fileInformation,
                              uint32_t length, XANSI_STRING *fileName,
                              uint32_t restartScan) {
  (void)event;
  (void)apcRoutine;
  (void)apcContext;

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t status = STATUS_SUCCESS;
  uint32_t written = 0;

  // ---- resolve the handle to a real VFS file ---------------------------------
  FileObject *fileObj =
      dynamic_cast<FileObject *>(ResolveKernelObjectSafe(handle));
  if (!fileObj) {
    status = STATUS_INVALID_HANDLE;
    MCLA_LOG_WARN("NtQueryDirectoryFile: handle={:08X} is not a VFS file -> "
                  "STATUS_INVALID_HANDLE lr={:08X}",
                  handle,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  std::vector<std::string> entries;
  bool enumerated = false;
  const std::string *path = fileObj ? &fileObj->fileHandle.virtual_path : nullptr;

  if (status == STATUS_SUCCESS) {
    if (!vfs.IsDirectory(*path)) {
      // Not a directory. Do NOT answer STATUS_NO_MORE_FILES: that reads to the
      // guest as "empty directory", which is a different and false statement.
      status = STATUS_INVALID_PARAMETER;
      MCLA_LOG_WARN("NtQueryDirectoryFile: '{}' is not a directory -> "
                    "STATUS_INVALID_PARAMETER lr={:08X} (no directory handle is "
                    "producible today: vfs_rpf.cpp:493-496 OpenFile refuses "
                    "directories)",
                    *path,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    } else if (!vfs.ListDirectory(*path, entries)) {
      // F-634: neither `ntstatus.h` nor the `NTSTATUS` typedef reaches this TU
      // (windows.h supplies the STATUS_* macros the file already used, but not
      // this one), and `status` here is a plain uint32_t like every other status
      // in this file. The WDK value is fixed: `ntstatus.h`
      // `STATUS_OBJECT_NAME_NOT_FOUND ((NTSTATUS)0xC0000034L)`.
      status = 0xC0000034u; // STATUS_OBJECT_NAME_NOT_FOUND
      MCLA_LOG_WARN("NtQueryDirectoryFile: ListDirectory('{}') failed -> "
                    "STATUS_OBJECT_NAME_NOT_FOUND lr={:08X}",
                    *path,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    } else {
      enumerated = true;
    }
  }

  // ---- optional guest-side name pattern --------------------------------------
  // Read through the checked helpers; an unreadable pattern is a real
  // STATUS_INVALID_PARAMETER, not a silent "match everything".
  std::string pattern;
  if (enumerated && fileName) {
    const uint32_t nameAddr = mem.MapVirtual(fileName);
    uint16_t nameLen = 0;
    uint32_t bufAddr = 0;
    if (nameAddr == 0 || !mem.ReadU16BE(nameAddr + 0, &nameLen) ||
        !mem.ReadU32BE(nameAddr + 4, &bufAddr)) {
      status = STATUS_INVALID_PARAMETER;
      MCLA_LOG_WARN("NtQueryDirectoryFile: unreadable FileName at {:p} -> "
                    "STATUS_INVALID_PARAMETER lr={:08X}",
                    (void *)fileName,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    } else if (nameLen != 0) {
      if (nameLen > 0x1000 || !mem.IsValid(bufAddr, nameLen)) {
        status = STATUS_INVALID_PARAMETER;
      } else {
        pattern.resize(nameLen);
        (void)mem.ReadBytes(bufAddr, pattern.data(), nameLen);
      }
    }
  }

  // ---- short buffer ------------------------------------------------------------
  // The reference refuses anything under one header up front
  // (xboxkrnl_io.cc:552-554). Same rule here.
  if (status == STATUS_SUCCESS && length < kDirInfoHeaderSize) {
    status = STATUS_INFO_LENGTH_MISMATCH;
    MCLA_LOG_WARN("NtQueryDirectoryFile: Length={} < {} -> "
                  "STATUS_INFO_LENGTH_MISMATCH lr={:08X}",
                  length, kDirInfoHeaderSize,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  uint32_t infoAddr = 0;
  if (status == STATUS_SUCCESS) {
    infoAddr = mem.MapVirtual(fileInformation);
    if (infoAddr == 0 || !mem.IsValid(infoAddr, length)) {
      status = 0xC0000005; // STATUS_ACCESS_VIOLATION
      MCLA_LOG_WARN("NtQueryDirectoryFile: FileInformation buffer outside the "
                    "guest window -> STATUS_ACCESS_VIOLATION lr={:08X}",
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  // ---- real enumeration --------------------------------------------------------
  if (status == STATUS_SUCCESS) {
    size_t start = 0;
    {
      // CTAD, not std::lock_guard<std::mutex>: Mutex derives from
      // CRITICAL_SECTION on Windows (src/kernel/mutex.h:5-25), it is not a
      // std::mutex. Same form as src/kernel/xdm.cpp:9.
      std::lock_guard cursorLock(g_dirScanLock);
      if (restartScan) {
        g_dirScanCursor[handle] = 0;
      } else if (auto it = g_dirScanCursor.find(handle);
                 it != g_dirScanCursor.end()) {
        start = it->second;
      }
    }

    // One pass: emit records until the caller's buffer is full, and remember
    // exactly where we stopped so the next call resumes there.
    uint32_t used = 0;
    size_t cursor = start;
    bool sawMatch = false;
    std::vector<uint32_t> offsets; // buffer offset of each emitted record
    offsets.reserve(16);

    for (size_t i = start; i < entries.size(); ++i) {
      const std::string &name = entries[i];
      if (!pattern.empty() && pattern != "." && pattern != "*" &&
          !DirNameEqualsNoCase(name.c_str(), pattern.c_str()))
        continue; // name did not match; the cursor still advances past it
      sawMatch = true;

      // Real per-entry facts out of the VFS index, not invented ones.
      const std::string child = *path + "/" + name;
      const bool isDir = vfs.IsDirectory(child);
      const uint64_t childSize = vfs.GetFileSize(child);
      const uint32_t nameLen = static_cast<uint32_t>(name.size());
      // xfile.h:51-72 walks next_entry_offset, so keeping records 8-aligned is
      // ours to do.
      const uint32_t padded = (kDirInfoHeaderSize + nameLen + 7) & ~7u;
      if (used + padded > length)
        break; // caller buffer is full: return what fits, keep the cursor

      const uint32_t rec = infoAddr + used;
      (void)mem.WriteU32BE(rec + 0x00, 0);  // NextEntryOffset, patched below
      (void)mem.WriteU32BE(rec + 0x04, static_cast<uint32_t>(i)); // FileIndex
      (void)mem.WriteU64BE(rec + 0x08, 0);  // CreationTime:  none recorded
      (void)mem.WriteU64BE(rec + 0x10, 0);  // LastAccessTime: none recorded
      (void)mem.WriteU64BE(rec + 0x18, 0);  // LastWriteTime:  none recorded
      (void)mem.WriteU64BE(rec + 0x20, 0);  // ChangeTime:     none recorded
      (void)mem.WriteU64BE(rec + 0x28, childSize); // EndOfFile
      (void)mem.WriteU64BE(rec + 0x30, childSize); // AllocationSize
      (void)mem.WriteU32BE(rec + 0x38, isDir ? kFileAttributeDirectory
                                             : kFileAttributeNormal);
      (void)mem.WriteU32BE(rec + 0x3C, nameLen);
      (void)mem.WriteBytes(rec + kDirInfoHeaderSize, name.data(), nameLen);

      offsets.push_back(used);
      used += padded;
      cursor = i + 1;
    }

    // Terminate the chain: every record points at the next one, the last is 0.
    for (size_t k = 0; k < offsets.size(); ++k) {
      const uint32_t next = (k + 1 < offsets.size())
                                ? offsets[k + 1] - offsets[k]
                                : 0u;
      (void)mem.WriteU32BE(infoAddr + offsets[k] + 0x00, next);
    }

    {
      std::lock_guard cursorLock(g_dirScanLock);
      g_dirScanCursor[handle] = cursor;
    }

    written = used;
    if (used == 0) {
      // Three genuinely different endings, previously all reported as
      // STATUS_NO_MORE_FILES:
      if (sawMatch) {
        // An entry exists but would not fit the caller's buffer.
        status = 0x80000005; // STATUS_BUFFER_OVERFLOW
      } else if (pattern.empty() || pattern == "." || pattern == "*") {
        // Ran off the end of a real enumeration. This is the ONLY case where
        // NO_MORE_FILES is the truth, and it is now reached only by actually
        // exhausting the index.
        status = STATUS_NO_MORE_FILES;
      } else {
        // The search pattern matched nothing in what is left.
        status = 0xC000000F; // STATUS_NO_SUCH_FILE
      }
    }
  }

  if (ioStatus) {
    ioStatus->Status.set(status);
    ioStatus->Information.set(written);
  }

  {
    static std::atomic<uint32_t> s_dirQ{0};
    const uint32_t n = s_dirQ.fetch_add(1) + 1;
    if (n <= 40 || (n % 500) == 0)
      MCLA_LOG_INFO("NtQueryDirectoryFile #{} h={:08X} path='{}' len={} "
                    "restart={} enumerated={} -> st={:08X} out={} lr={:08X}",
                    n, handle, path ? *path : "<none>", length, restartScan,
                    enumerated ? 1 : 0, status, written,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  return status;
}

uint32_t NtReadFile(uint32_t handle, uint32_t event, uint32_t apcRoutine,
                    uint32_t apcContext, XIO_STATUS_BLOCK *ioStatus,
                    void *buffer, uint32_t length, be<uint64_t> *byteOffset,
                    uint32_t *key) {
  // NtReadFile census.
  //
  // Rate limit RAISED 2026-10-05 (was `n <= 20 || (n % 100) == 0`, 22 printed
  // rows). Measured, not estimated: the highest `#NNNN` this counter printed in
  // EITHER recent soak is #0200 (build/w719.log and build/w720.log, both
  // 22 rows), and #0300 printed in neither, so the boot's true call count is
  // >= 200 and <= 299 -- rows #201-#299 happened and were invisible. Printing
  // every row through #320 therefore yields the FULL call count, not a sample,
  // and stays bounded at 320 rows + one row per further 100 calls. 320 rows is
  // 0.6% of w719.log's 50,482 lines; the counter is per-NtReadFile-call and
  // NtReadFile is not a per-byte or per-page loop.
  {
    static std::atomic<uint32_t> s_census{0};
    const uint32_t n = s_census.fetch_add(1) + 1;
    if (n <= 320 || (n % 100) == 0) {
      MCLA_LOG_INFO("NFS-CENSUS[Read] #{:04} h={:08X} len={} off={:#x} "
                    "evt={:08X} apc={:08X} lr={:08X}",
                    n, handle, length,
                    byteOffset ? byteOffset->get() : 0, event, apcRoutine,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }
  (void)event;
  (void)apcRoutine;
  (void)apcContext;
  (void)key;

  if (buffer == nullptr || length == 0) {
    if (ioStatus)
      ioStatus->Status.set(STATUS_SUCCESS);
    return STATUS_SUCCESS;
  }

  auto &guestMem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t bufferAddr = guestMem.MapVirtual(buffer);
  void *hostPtr = (bufferAddr != 0) ? guestMem.Translate(bufferAddr) : nullptr;
  if (!hostPtr) {
    if (ioStatus)
      ioStatus->Status.set(0xC0000005);
    return 0xC0000005;
  }

  // SECURITY: clamp length so the write stays inside the guest window -
  // Translate() only validates the buffer START, a huge length would
  // otherwise write out-of-bounds host memory past the window end.
  {
    auto &heapForBounds = mcla::kernel::GuestMemoryHeap::Instance();
    const uint64_t winSize = heapForBounds.Size();
    const uint64_t bufOff = bufferAddr;
    if (bufOff < winSize && length > winSize - bufOff) {
      length = static_cast<uint32_t>(winSize - bufOff);
    }
  }

  // A handle in the class that cannot name an object at all is REFUSED here, by
  // name, before either transfer arm runs.
  //
  // The class is exactly the one ResolveKernelObjectSafe rejects without ever
  // touching guest memory (imports.cpp:2177-2178 and :2187-2189):
  // `handle < 0x1000`, which lands inside the deliberate 4 KiB PAGE_NOACCESS
  // null guard (memory.cpp:409, documented at :507-513), and
  // `handle + sizeof(XDISPATCHER_HEADER) >= kSize`, which covers the whole
  // 0xFFFFFFF0..0xFFFFFFFF invalid-sentinel class.
  //
  // Why this guard exists and is not merely the resolver swap: the resolver
  // returns nullptr for both classes, and a null fileObj below lands in the
  // zero-fill arm, which memsets the caller's window and then reports
  // STATUS_SUCCESS with `length` bytes read - a full-length transfer of bytes
  // that were never read, over content the caller had already put there.
  // Measured, not assumed: the window arrives holding the caller's own
  // 0xC0+(i&0xF) pattern and every byte of it is zero on return. So the
  // one-line swap on its own would trade an access violation for a silent data
  // lie, which is worse than the bug. Refusing is the only honest arm for a
  // handle that cannot name a file.
  //
  // In-bounds handles that simply are not files - device opens - still reach the
  // zero-fill arm below, unchanged. That arm is this function's documented
  // legacy behaviour and removing it is not this fix's business; only the
  // unnameable class is taken out of it.
  //
  // Placement: AFTER the call census at the top of this function, so a refused
  // call still prints its census row, and BEFORE both arms, so a refusal can
  // never report a transfer. A refusal is not an arm, so the arm census further
  // down does not print for it.
  if (handle < 0x1000u ||
      static_cast<uint64_t>(handle) + sizeof(XDISPATCHER_HEADER) >=
          mcla::kernel::GuestMemoryHeap::kSize) {
    {
      static std::atomic<uint32_t> s_nfsBadHandle{0};
      const uint32_t bn = s_nfsBadHandle.fetch_add(1) + 1;
      if (bn <= 20 || (bn % 100) == 0)
        MCLA_LOG_WARN(
            "NFS-BADHANDLE #{} h={:08X} buf={:08X} req={} -> "
            "STATUS_INVALID_HANDLE (unnameable handle class; no bytes read, "
            "caller window untouched) lr={:08X}",
            bn, handle, bufferAddr, length,
            static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INVALID_HANDLE);
      ioStatus->Information.set(0);
    }
    return STATUS_INVALID_HANDLE;
  }

  // Resolve the kernel file object and serve real bytes from the VFS.
  //
  // `GetKernelObject` returns the raw reinterpret_cast fallback for any address
  // that is not a registered host wrapper (xdm.h:72-77), and calling
  // `IsValid()` on that is a method call through a cast of guest memory. For
  // handle 1 it reads inside the null guard and faults; ResolveKernelObjectSafe's
  // comment at :2202-2211 names that read as precisely the faulting
  // instruction. The guard above stops every handle that can reach it.
  //
  // The scatter sibling is the same shape and refuses the same way
  // (imports.cpp:3464-3476, STATUS_INVALID_HANDLE with Information=0); it has
  // no zero-fill arm, and neither does NtWriteFile's handle check
  // (imports.cpp:1946-1956). Only this function had one.
  //
  // Resolution is DELIBERATELY left as the original hand-rolled form and NOT
  // swapped for ResolveKernelObjectSafe, because the swap is NOT
  // behaviour-preserving here. Measured in the M-imports harness with a single
  // variable -- two objects differing only in this file's text, both compiled
  // at the project's real /O2 /Ob1:
  //
  //   pre-fix   ARM 1, a real FileObject handle -> 494 real bytes, byte-equal
  //             to an independent python-zlib oracle built from the raw
  //             archive bytes.
  //   resolver  ARM 1 -> all zeros, STATUS_SUCCESS, full-length "transfer".
  //
  // The cause is the resolver's `o != raw` discrimination at :2225, measured
  // gate by gate for that very handle:
  //
  //   raw = Translate(h)             = 0x1A0401280
  //   o   = GetKernelObject(h)       = 0x1A0401280   <-- EQUAL
  //   o->IsValid()                   = valid (the wrapper's own 'XBOX')
  //   ReadU32BE(h + offsetof(Flink)) = 0x16000000, != OBJECT_SIGNATURE
  //
  // Translate maps a physical-arena guest VA onto the arena's HOST address, so
  // for a registered host wrapper `raw` and `o` are the same pointer, the
  // `o != raw` test is false, and the resolver takes its raw-guest-memory
  // branch: it reads offsetof(Flink)=8 bytes past the handle and rejects a
  // perfectly good file. Routing NtReadFile through it would trade a fault for
  // silent zero-fill on every arena-range read -- strictly worse than the bug
  // being fixed. The defect belongs to the shared helper, so it is left for its
  // own change under a soak rather than smuggled in through this call site.
  //
  // The guard above is what actually removes the fault class, and it needs no
  // resolver at all. The faulting instruction is the read inside `o->IsValid()`
  // at obj+0x10, and obj is Translate(handle), so the read lands at
  // handle+0x10. That is unreadable for exactly two ranges: handle < 0x1000 (the
  // PAGE_NOACCESS null guard) and handle+0x10 >= kSize (one past the window).
  // Those are precisely the two ranges the guard refuses, so every handle that
  // could fault here is now refused by name before any dereference.
  FileObject *fileObj = nullptr;
  if (handle != GUEST_INVALID_HANDLE_VALUE && IsKernelObject(handle)) {
    KernelObject *obj = GetKernelObject(handle);
    if (obj && obj->IsValid())
      fileObj = dynamic_cast<FileObject *>(obj);
  }

  uint64_t bytesRead = 0;
  bool ok = false;
  DWORD hostErr = 0;  // T41.3r (F-105): WHY a failed read failed. The old line
                      // printed `off=0x0` for both "byteOffset == null" and a
                      // genuine position 0, and mapped every host error to
                      // C000000D, so w76/w77's 1339-retry spin was uncitable.
  uint32_t rawHandle = 0;
  uint64_t offDbg = 0;
  bool posDbg = false;
  const char *pathDbg = nullptr;
  // First four bytes already in the guest window, captured ONLY on the
  // zero-fill arm and BEFORE the fill, so a soak can say whether that arm
  // destroyed anything the caller had already written there.
  uint8_t preFill[4] = {0, 0, 0, 0};
  if (fileObj) {
    rawHandle = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
        fileObj->fileHandle.handle));
    auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
    uint64_t offset = 0;
    if (byteOffset) {
      posDbg = true;
      // Session 76d: positional read — concurrent NtReadFile callers on the
      // same handle raced the shared seek position and served wrong bytes
      // (garbage pointers downstream: 0xFF00FF00 used as an object).
      offset = byteOffset->get();
      ok = vfs.ReadFileAt(fileObj->fileHandle, offset, hostPtr, length,
                          bytesRead);
    } else {
      offset = fileObj->fileHandle.position;
      // F-628: vfs.ReadFile advances fileHandle.position ITSELF
      // (src/fs/vfs_rpf.cpp:778, and the comment there names this exact
      // duplicate). The `if (ok) fileObj->fileHandle.position += bytesRead;`
      // that used to sit here double-advanced it, so every non-positional read
      // left the stream 2x too far along - the F442-SECTION starvation class,
      // where the following read starts past the bytes it needed and returns 0.
      ok = vfs.ReadFile(fileObj->fileHandle, hostPtr, length, bytesRead);
    }
    offDbg = offset;
    pathDbg = fileObj->fileHandle.virtual_path.c_str();
    hostErr = ::GetLastError();  // captured immediately, before any other call
    MCLA_LOG_DEBUG("NtReadFile: h={:08X} off={:#x} len={} -> {} bytes", handle,
                   offset, length, bytesRead);
  } else {
    // Non-VFS handles (device opens etc): zero-fill keeps legacy behavior.
    if (length >= sizeof(preFill))
      (void)guestMem.ReadBytes(bufferAddr, preFill, sizeof(preFill));
    std::memset(hostPtr, 0, length);
    bytesRead = length;
    ok = true;
  }

  // Which arm ran, and what actually landed in the guest window. Log-only: the
  // two arms above are unchanged, and this block reads memory it has already
  // written and nothing else. `arm=READ` means a FileObject resolved and the
  // VFS served `got` bytes at `off`; `arm=ZERO` means no FileObject resolved and
  // the window was filled with `req` zero bytes while the call still reports
  // success and a full-length transfer.
  //
  // Rate: first 20 calls, every 100th after that, and EVERY zero-fill arm
  // through call #60. The zero-fill arm is the one that can silently overwrite a
  // buffer the caller had already filled, so it is the arm that must not be
  // sampled away; the per-100 rows keep the ordinary reads visible, including
  // the #201-#299 band the census limit above used to hide. Bound: <= 60 rows +
  // one row per further 100 calls.
  {
    static std::atomic<uint32_t> s_arm{0};
    const uint32_t an = s_arm.fetch_add(1) + 1;
    const bool zeroArm = (fileObj == nullptr);
    if (an <= 20 || (an % 100) == 0 || (zeroArm && an <= 60)) {
      uint8_t head8[8] = {0, 0, 0, 0, 0, 0, 0, 0};
      (void)guestMem.ReadBytes(bufferAddr, head8, sizeof(head8));
      char headHex[19] = "................";
      for (int q = 0; q < 8; ++q) {
        static const char kHex[] = "0123456789ABCDEF";
        headHex[q * 2] = kHex[(head8[q] >> 4) & 0xF];
        headHex[q * 2 + 1] = kHex[head8[q] & 0xF];
      }
      MCLA_LOG_WARN(
          "NFS-ARM #{} arm={} h={:08X} buf={:08X} req={} got={} pos={} "
          "off={:#x} raw={:08X} pre={:02X}{:02X}{:02X}{:02X} head={} "
          "path='{}' lr={:08X}",
          an, zeroArm ? "ZERO" : "READ", handle, bufferAddr, length, bytesRead,
          posDbg ? 1 : 0, offDbg, rawHandle, preFill[0], preFill[1], preFill[2],
          preFill[3], headHex, pathDbg ? pathDbg : "",
          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  if (ioStatus) {
    ioStatus->Status.set(ok ? STATUS_SUCCESS : 0xC000000D);
    ioStatus->Information.set(static_cast<uint64_t>(bytesRead));
  }
  // Session 75x: surface failed / short reads — the game now reaches its
  // disc-streaming phase and fatals with 'Fatal disc error'; find the
  // failing read.
  if (!ok || bytesRead < length) {
    static std::atomic<uint32_t> s_rdFail{0};
    const uint32_t fn = s_rdFail.fetch_add(1) + 1;
    if (fn <= 40 || (fn % 500) == 0)
      MCLA_LOG_WARN(
          "NtReadFile: {} h={:08X} off={:#x} len={} got={} status={:08X} "
          "lr={:08X} (#{}) [pos={} rawHandle={:08X} gle={} path='{}']",
          ok ? "SHORT" : "FAIL", handle, offDbg, length, bytesRead,
          ok ? 0u : 0xC000000Du,
          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0), fn,
          posDbg ? 1 : 0, rawHandle, hostErr, pathDbg ? pathDbg : "");
  }

  // Session 75p FIX: async-read completion. The streamer refill submits
  // overlapped reads with a completion event and polls it; we performed the
  // read synchronously but never signaled the event, so inLeft stayed 0
  // forever (session-73 "infinite spin", later killed by INFLATE-EMPTY,
  // which aborted the boot's second load batch). Signal the event now —
  // X360 NtReadFile signals it on IO completion.
  bool signaled = false;
  if (event != 0) {
    Event *evt = nullptr;
    if (auto *id = LookupIdentityKernelObject(event)) {
      evt = static_cast<Event *>(id);
    } else if (IsKernelObject(event)) {
      void *raw = mcla::kernel::GuestMemoryHeap::Instance().Translate(event);
      if (raw) {
        auto *hdr = reinterpret_cast<XDISPATCHER_HEADER *>(raw);
        evt = TryQueryKernelObject<Event>(*hdr);
      }
    }
    if (evt && evt->IsValid()) {
      evt->Set();
      signaled = true;
      static std::atomic<uint32_t> s_rdEvt{0};
      const uint32_t en = s_rdEvt.fetch_add(1) + 1;
      if (en <= 20 || (en % 500) == 0)
        MCLA_LOG_INFO("NtReadFile: signaled completion event h={:08X} "
                      "(async read {} bytes, #{})",
                      event, bytesRead, en);
    }
  }
  // Session 75w FIX: async-contract. The kernel read wrapper
  // (sub_8244F4C0) presets ioStatus to STATUS_PENDING (259) and branches
  // on our return: 259 → async path (page finalized via the completion
  // event), 0 → "done now" path the page-cache submitter never finalizes
  // (slots stuck state=1 → the boot's second load batch starves). With an
  // event/APC present the caller expects true async semantics: do the read
  // inline (already done above) but return STATUS_PENDING.
  if (ok && signaled && ioStatus) {
    return 259; // STATUS_PENDING
  }
  return ok ? STATUS_SUCCESS : 0xC000000D;
}

// XFILE_SCATTER_BUFFER element, 8 bytes on the 360:
//   PHYSICAL_ADDRESS Buffer (4) / ULONG Length (4)
// (Xenia .research/xenia/.../xboxkrnl_io.cc:268-271 takes the array as a bare
// guest address; the same 8-byte element is what the guest's own boot-time DMA
// paths use.)
namespace {
constexpr uint32_t kScatterElementSize = 8;
} // namespace

// NtReadFileScatter(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock,
//                   ScatterBuffer, Length, Offset, Key).
//
// F-609: this was `uint32_t NtReadFileScatter() { LOG_UTILITY(...); return
// STATUS_SUCCESS; }`. Three defects: the body was a no-op in release, it
// declared NO PARAMETERS so the hook never read r3-r10 at all (ArgTranslator
// only populates the tuple the function signature declares,
// src/kernel/function.h:273-278), and it reported success for a handle and
// buffer that were never touched. The game saw a successful read and an
// untouched destination.
//
// Real behaviour now: one logical read split across the element array, served
// through the same VFS path NtReadFile uses
// (RpfVirtualFileSystem::ReadFileAt, vfs_rpf.h:81), with the offset advancing
// across elements exactly as a single read would. The element Buffer is a
// PHYSICAL address, and this model has no paging: the physical arena is mapped
// into the flat guest window (heap.cpp:232-234), so a physical address is the
// guest VA of the same page - it is read and written through the checked
// guest helpers, never through a raw host pointer.
//
// The APC routine is deliberately not invoked: this TU has no APC delivery
// mechanism to hand the completion to, so pretending to queue one would be the
// same class of lie. Named here so the gap is a stated decision, not an
// omission.
uint32_t NtReadFileScatter(uint32_t handle, uint32_t event, uint32_t apcRoutine,
                           uint32_t apcContext, XIO_STATUS_BLOCK *ioStatus,
                           void *scatterBuffer, uint32_t length,
                           be<uint64_t> *byteOffset, uint32_t *key) {
  (void)key;

  {
    static std::atomic<uint32_t> s_census{0};
    const uint32_t n = s_census.fetch_add(1) + 1;
    if (n <= 20 || (n % 100) == 0)
      MCLA_LOG_INFO("NFS-CENSUS[ReadScatter] #{:04} h={:08X} elements={} "
                    "off={:08X} evt={:08X} apc={:08X} lr={:08X}",
                    n, handle, length,
                    byteOffset ? static_cast<uint32_t>(byteOffset->get()) : 0,
                    event, apcRoutine,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  // Resolve the handle first. Reporting success for an unknown handle is
  // exactly the bug this replaces.
  FileObject *fileObj =
      dynamic_cast<FileObject *>(ResolveKernelObjectSafe(handle));
  if (!fileObj) {
    MCLA_LOG_WARN("NtReadFileScatter: handle={:08X} is not a VFS file -> "
                  "STATUS_INVALID_HANDLE lr={:08X}",
                  handle,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INVALID_HANDLE);
      ioStatus->Information.set(0);
    }
    return STATUS_INVALID_HANDLE;
  }

  if (length == 0) {
    // Zero elements is a real, complete no-op read.
    if (ioStatus) {
      ioStatus->Status.set(STATUS_SUCCESS);
      ioStatus->Information.set(0);
    }
    return STATUS_SUCCESS;
  }

  const uint32_t arrayAddr = mem.MapVirtual(scatterBuffer);
  const uint64_t arrayBytes =
      static_cast<uint64_t>(length) * kScatterElementSize;
  if (arrayAddr == 0 || arrayBytes > 0xFFFFFFFFull ||
      !mem.IsValid(arrayAddr, static_cast<size_t>(arrayBytes))) {
    MCLA_LOG_WARN("NtReadFileScatter: element array {:p} ({} elements) is not "
                  "in the guest window -> STATUS_INVALID_PARAMETER lr={:08X}",
                  scatterBuffer, length,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    if (ioStatus) {
      ioStatus->Status.set(STATUS_INVALID_PARAMETER);
      ioStatus->Information.set(0);
    }
    return STATUS_INVALID_PARAMETER;
  }

  auto &vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
  const bool positional = byteOffset != nullptr;
  uint64_t offset = positional ? static_cast<uint64_t>(byteOffset->get())
                               : fileObj->fileHandle.position;
  uint64_t totalBytes = 0;
  uint32_t status = STATUS_SUCCESS;
  uint32_t used = 0;

  for (uint32_t i = 0; i < length; ++i) {
    const uint32_t elemAddr = arrayAddr + i * kScatterElementSize;
    uint32_t bufferAddr = 0, elemLength = 0;
    // Read the descriptor through the checked helpers: it is guest data.
    if (!mem.ReadU32BE(elemAddr, &bufferAddr) ||
        !mem.ReadU32BE(elemAddr + 4, &elemLength)) {
      status = 0xC0000005; // STATUS_ACCESS_VIOLATION
      break;
    }

    // A zero element is a legitimate hole in a scatter list; skip it without
    // consuming file bytes.
    if (elemLength == 0)
      continue;

    if (!mem.IsValid(bufferAddr, elemLength)) {
      // The element points outside the window. That is a real parameter error,
      // not something to paper over by reading into nothing.
      static std::atomic<uint32_t> s_badElem{0};
      const uint32_t n = s_badElem.fetch_add(1) + 1;
      if (n <= 20 || (n % 500) == 0)
        MCLA_LOG_WARN("NtReadFileScatter #{}: element {} buffer={:08X} "
                      "len={:X} is outside the guest window "
                      "(gap to window end={}) lr={:08X}",
                      n, i, bufferAddr, elemLength,
                      bufferAddr < mem.Size() ? mem.Size() - bufferAddr : 0u,
                      static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      status = STATUS_INVALID_PARAMETER;
      break;
    }

    void *host = mem.Translate(bufferAddr);
    if (!host) {
      status = 0xC0000005;
      break;
    }

    uint64_t got = 0;
    if (!vfs.ReadFileAt(fileObj->fileHandle, offset, host, elemLength, got)) {
      // Host read failed. Report the bytes we DID get and stop, the way a
      // short transfer does. GetLastError is captured immediately, before any
      // other call can clobber it - the T41.3r lesson from NtReadFile
      // (imports.cpp below), where an uncaptured gle made failures uncitable.
      const DWORD gle = ::GetLastError();
      static std::atomic<uint32_t> s_fail{0};
      const uint32_t n = s_fail.fetch_add(1) + 1;
      if (n <= 20 || (n % 500) == 0)
        MCLA_LOG_WARN("NtReadFileScatter #{}: element {} read FAILED "
                      "off={:#x} len={:X} got={} path='{}' gle={} lr={:08X}",
                      n, i, offset, elemLength, got,
                      fileObj->fileHandle.virtual_path, gle,
                      static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      if (got == 0)
        status = 0xC000000D; // STATUS_UNSUCCESSFUL
      break;
    }

    totalBytes += got;
    offset += got;
    used = i + 1;
    if (got < elemLength) {
      // End of file: a short read is a success with fewer bytes, not an error.
      static std::atomic<uint32_t> s_short{0};
      const uint32_t n = s_short.fetch_add(1) + 1;
      if (n <= 20 || (n % 500) == 0)
        MCLA_LOG_WARN("NtReadFileScatter: SHORT #{} at element {} off={:#x} "
                      "want={:X} got={} path='{}' lr={:08X}",
                      n, i, offset - got, elemLength, got,
                      fileObj->fileHandle.virtual_path,
                      static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      break;
    }
  }

  // A non-positional read advances the file's own position by what it served.
  if (!positional && used != 0)
    fileObj->fileHandle.position += totalBytes;

  // Signal the completion event if one was supplied - the same contract
  // NtReadFile honours. The return value stays the real NTSTATUS: there is no
  // measured PENDING contract for this entry point, so claiming STATUS_PENDING
  // here would be an invented guess.
  bool signaled = false;
  if (event != 0) {
    Event *evt = nullptr;
    if (auto *id = LookupIdentityKernelObject(event)) {
      evt = static_cast<Event *>(id);
    } else if (IsKernelObject(event)) {
      if (void *raw = mem.Translate(event))
        evt = TryQueryKernelObject<Event>(
            *reinterpret_cast<XDISPATCHER_HEADER *>(raw));
    }
    if (evt && evt->IsValid()) {
      evt->Set();
      signaled = true;
    }
  }

  if (ioStatus) {
    ioStatus->Status.set(status);
    ioStatus->Information.set(static_cast<uint32_t>(totalBytes));
  }

  // Bounded summary census: 40 then every 500th, so soak_census can count it
  // as real call evidence rather than an accidental sample.
  {
    static std::atomic<uint32_t> s_calls{0};
    const uint32_t n = s_calls.fetch_add(1) + 1;
    if (n <= 40 || (n % 500) == 0 || status != STATUS_SUCCESS)
      MCLA_LOG_INFO("NtReadFileScatter #{} h={:08X} path='{}' elements={} "
                    "used={} bytes={} off={:#x} st={:08X} evt={} "
                    "apc={:08X}/{:08X} lr={:08X}",
                    n, handle, fileObj->fileHandle.virtual_path, length, used,
                    totalBytes, offset, status, signaled ? 1 : 0, apcRoutine,
                    apcContext,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  return status;
}

void NtDuplicateObject() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t
NtAllocateVirtualMemory(be<uint32_t> *baseAddress, be<uint32_t> *regionSize,
                        uint32_t allocationType,
                        uint32_t protect /*, debugMemory r7 ignored */) {
  // Xbox 360 semantics (Xenia xboxkrnl_memory.cc
  // NtAllocateVirtualMemory_entry): _Inout_ PVOID *BaseAddress, _Inout_ PSIZE_T
  // RegionSize, _In_ ULONG AllocationType, _In_ ULONG Protect, _In_ BOOLEAN
  // DebugMemory. Explicit bases MUST land in the guest-virtual window AND must
  // actually be reservable; success merely because Translate() succeeds was a
  // bug (it ACKed reservations we never made, letting two systems share pages).
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  if (!baseAddress || !regionSize)
    return STATUS_INVALID_PARAMETER;

  const uint32_t baseIn = baseAddress->get();
  const int32_t sizeSigned = static_cast<int32_t>(regionSize->get());

  if (sizeSigned == 0)
    return STATUS_INVALID_PARAMETER;
  if (!(allocationType & (kXMemCommit | kXMemReset | kXMemReserve)))
    return STATUS_INVALID_PARAMETER;
  if ((allocationType & kXMemReset) && (allocationType & ~kXMemReset))
    return STATUS_INVALID_PARAMETER;

  // Guest-virtual window only; physical/heap ranges are not this API's space.
  if (baseIn != 0 &&
      (baseIn < mcla::kernel::GuestMemoryHeap::kGuestVirtualBase ||
       baseIn >= mcla::kernel::GuestMemoryHeap::kGuestVirtualEnd)) {
    MCLA_LOG_WARN("NtAllocVM: base {:08X} outside guest-virtual window",
                  baseIn);
    LogVirtualAlloc("NtAllocVM", baseIn, 0, static_cast<uint32_t>(sizeSigned),
                    allocationType, STATUS_INVALID_PARAMETER);
    return STATUS_INVALID_PARAMETER;
  }

  const uint32_t pageSize =
      mcla::kernel::GuestMemoryHeap::kGuestVirtualPageSize;
  const uint32_t adjustedBase = baseIn - (baseIn % pageSize);
  const uint32_t adjustedSize = RoundUp64K(
      static_cast<uint32_t>(sizeSigned < 0 ? -sizeSigned : sizeSigned));

  bool commit = (allocationType & kXMemCommit) != 0;
  const bool zeroFresh = (allocationType & kXMemNozero) == 0;

  uint32_t address = 0;
  uint32_t status = STATUS_SUCCESS;
  if (adjustedBase != 0) {
    bool wasCommitted = false;
    if (!mem.AllocVirtualFixed(adjustedBase, adjustedSize, commit, zeroFresh,
                               &wasCommitted))
      status = STATUS_NO_MEMORY;
    else
      address = adjustedBase;
  } else {
    if (!mem.AllocVirtualAny(adjustedSize, (allocationType & kXMemTopDown) != 0,
                             commit, zeroFresh, &address))
      status = STATUS_NO_MEMORY;
  }

  LogVirtualAlloc("NtAllocVM", baseIn, address, adjustedSize, allocationType,
                  status);

  if (status != STATUS_SUCCESS)
    return status;

  baseAddress->set(address);
  regionSize->set(adjustedSize);
  return STATUS_SUCCESS;
}

uint32_t NtFreeVirtualMemory(be<uint32_t> *baseAddress,
                             be<uint32_t> *regionSize, uint32_t freeType) {
  // _Inout_ PVOID *BaseAddress, _Inout_ PSIZE_T RegionSize, _In_ ULONG
  // FreeType. Only tracked guest-virtual regions may be freed. The previous
  // impl called g_userHeap.Free(Translate(base)) for ANY translated address - a
  // foreign pointer routed into o1heap (rejected by validate-before-free today,
  // heap corruption before that guard existed).
  if (!baseAddress || !regionSize)
    return STATUS_INVALID_PARAMETER;

  const uint32_t base = baseAddress->get();
  if (base == 0)
    return STATUS_MEMORY_NOT_ALLOCATED;

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t status = STATUS_UNSUCCESSFUL;
  uint32_t outSize = 0;

  if (freeType & kXMemRelease) {
    outSize = 0;
    if (mem.ReleaseVirtual(base, &outSize)) {
      regionSize->set(outSize);
      status = STATUS_SUCCESS;
    } else {
      status = STATUS_MEMORY_NOT_ALLOCATED;
    }
  } else if (freeType & kXMemDecommit) {
    outSize = 0;
    if (mem.DecommitVirtual(base, regionSize->get(), &outSize)) {
      regionSize->set(outSize);
      status = STATUS_SUCCESS;
    } else {
      status = STATUS_MEMORY_NOT_ALLOCATED;
    }
  } else {
    status = STATUS_INVALID_PARAMETER;
  }

  LogVirtualAlloc("NtFreeVM", base, 0, outSize, freeType, status);
  if (status == STATUS_SUCCESS)
    baseAddress->set(base);
  return status;
}

// ---- Ob object-reference ledger (F-609) ---------------------------------------
// KernelObject (src/kernel/xdm.h:17-47) has no reference-count field and xdm.h is
// not this agent's file, so the outstanding-reference count lives here, keyed by
// the object's guest address. ObReferenceObjectByHandle increments it and this
// function decrements it. It is a real ledger, not decoration: it is the only
// thing that makes an unbalanced guest ObReference visible in a soak instead of
// invisible. Object LIFETIME is still owned by the handle table (NtClose ->
// DestroyKernelObject), exactly as before - this does not free anything.
namespace {

Mutex g_obRefLock;
std::unordered_map<uint32_t, uint32_t> g_obRefCounts;
constexpr size_t kObRefMaxTracked = 4096;

bool BumpObRef(uint32_t object, uint32_t *outCount) {
  std::lock_guard lock(g_obRefLock);
  if (g_obRefCounts.size() >= kObRefMaxTracked &&
      g_obRefCounts.find(object) == g_obRefCounts.end()) {
    return false; // table full: do NOT grow without bound
  }
  *outCount = ++g_obRefCounts[object];
  return true;
}

bool DropObRef(uint32_t object, uint32_t *outCount) {
  std::lock_guard lock(g_obRefLock);
  auto it = g_obRefCounts.find(object);
  if (it == g_obRefCounts.end())
    return false; // never referenced through this path
  *outCount = --it->second;
  if (it->second == 0)
    g_obRefCounts.erase(it);
  return true;
}

} // namespace

void ObDereferenceObject(uint32_t object) {
  if (object == 0 || object == GUEST_INVALID_HANDLE_VALUE)
    return;

  uint32_t remaining = 0;
  if (!DropObRef(object, &remaining)) {
    // A dereference with no matching reference. Not an error the guest should
    // see (it may be balancing a reference taken before this ledger existed),
    // but it is a real imbalance and it must be visible.
    static std::atomic<uint32_t> s_unbalanced{0};
    const uint32_t n = s_unbalanced.fetch_add(1) + 1;
    if (n <= 20 || (n % 500) == 0)
      MCLA_LOG_WARN("OB-UNBALANCED-DEREF #{:04} object={:08X} lr={:08X}", n,
                    object,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return;
  }

  static std::atomic<uint32_t> s_derefs{0};
  const uint32_t n = s_derefs.fetch_add(1) + 1;
  if (n <= 20 || (n % 500) == 0)
    MCLA_LOG_INFO("OB-DEREF #{:04} object={:08X} remaining={} lr={:08X}", n,
                  object, remaining,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
}

void KeSetBasePriorityThread(GuestThreadHandle *hThread, int priority) {
#ifdef _WIN32
  if (priority == 16) {
    priority = 15;
  } else if (priority == -16) {
    priority = -15;
  }

  SetThreadPriority(hThread == GetKernelObject(CURRENT_THREAD_HANDLE)
                        ? GetCurrentThread()
                        : hThread->thread.native_handle(),
                    priority);
#endif
}

// ObReferenceObjectByHandle(Handle, ObjectType, Object) -> NTSTATUS.
//
// F-609: this used to be `*object = handle; return 0;` with `handle` and
// `objectType` never examined, so ANY 32-bit value the guest passed came back
// as a "successfully referenced object" - including 0, 0xFFFFFFFF and every
// wild pointer. Now the handle is resolved against the real kernel-object table
// and a handle that is not one fails with the real NTSTATUS.
//
// Two resolution paths, both inside ResolveKernelObjectSafe (imports.cpp above):
//  1. GetKernelObject first consults the durable host-side wrapper map
//     (TryQueryKernelObject, xdm.h:186-194) populated by
//     CreateRegisteredKernelObject. This is the authoritative path.
//  2. failing that, it wraps a guest-owned dispatcher header - accepted only if
//     the guest-visible signature Flink == 'XBOX' is still intact, and that
//     proof is now a CHECKED ReadU32BE rather than the host dereference of guest
//     memory that faulted the boot (see ResolveKernelObjectSafe above).
//
// Object lifetime is still the handle table's business; this only takes a
// reference (see the ledger above) and hands back the object address, which in
// this identity-handle model IS the handle's own guest VA.
uint32_t ObReferenceObjectByHandle(uint32_t handle, uint32_t objectType,
                                   be<uint32_t> *object) {
  if (!object)
    return STATUS_INVALID_PARAMETER;

  // F-609-BOOTCRASH: 0xFFFFFFFE is CURRENT_THREAD_HANDLE (guest_thread.h:14),
  // NOT a kernel object - it is the title asking for its own KTHREAD. Before
  // the extent check in ResolveKernelObjectSafe it was dereferenced and killed
  // the boot worker (w657.log 19:19:22, rva 0x24dc5d). There is no KTHREAD
  // object to hand back: GuestThreadHandle is not registered in
  // WrapperIdentityMap under this sentinel, and the calling thread is not
  // reachable from here BY HANDLE (only by id, via
  // GuestThread::GetCurrentThreadId). So it is refused, not faked - the old
  // `*object = handle; return 0` returned 0xFFFFFFFE as a "successfully
  // referenced object", which is exactly the invented object F-609 removed.
  // This bounded marker is how a soak shows whether the title tolerates the
  // refusal instead of faulting on it.
  if (handle == CURRENT_THREAD_HANDLE ||
      handle == GUEST_INVALID_HANDLE_VALUE) {
    static std::atomic<uint32_t> s_sentinel{0};
    const uint32_t n = s_sentinel.fetch_add(1) + 1;
    if (n <= 40 || (n % 500) == 0)
      MCLA_LOG_WARN("OB-REF-SENTINEL #{} handle={:08X} objectType={:08X} "
                    "(CURRENT_THREAD_HANDLE/invalid - no KTHREAD object) -> "
                    "STATUS_INVALID_HANDLE lr={:08X}",
                    n, handle, objectType,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return STATUS_INVALID_HANDLE;
  }

  KernelObject *obj = ResolveKernelObjectSafe(handle);
  if (!obj) {
    MCLA_LOG_WARN("OB-REF: handle={:08X} objectType={:08X} is not a resolvable "
                  "kernel object -> STATUS_INVALID_HANDLE lr={:08X}",
                  handle, objectType,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return STATUS_INVALID_HANDLE;
  }

  uint32_t refs = 0;
  if (!BumpObRef(handle, &refs)) {
    MCLA_LOG_WARN("OB-REF: ledger full ({} entries), reference to {:08X} not "
                  "recorded lr={:08X}",
                  kObRefMaxTracked, handle,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  {
    static std::atomic<uint32_t> s_refs{0};
    const uint32_t n = s_refs.fetch_add(1) + 1;
    if (n <= 40 || (n % 500) == 0)
      MCLA_LOG_INFO("OB-REF #{:04} handle={:08X} objectType={:08X} typeByte={:02X} "
                    "refs={} lr={:08X}",
                    n, handle, objectType,
                    static_cast<uint32_t>(obj->header.Type), refs,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }

  *object = handle;
  return STATUS_SUCCESS;
}

void KeQueryBasePriorityThread() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t NtSuspendThread(GuestThreadHandle *hThread, uint32_t *suspendCount) {
  // F-609: this self-check was
  //   assert(hThread != GetKernelObject(CURRENT_THREAD_HANDLE) &&
  //          hThread->GetThreadId() == GuestThread::GetCurrentThreadId());
  // with two independent defects, both silent:
  //  (a) DEAD. /DNDEBUG is defined in build/compile_commands.json, so it was
  //      compiled out and the self-suspend case was never checked at runtime.
  //  (b) INVERTED and self-contradictory. The illegal case is suspending the
  //      CALLER, i.e. hThread->GetThreadId() == GetCurrentThreadId(); as
  //      written the assert demands the LEGAL case (not-self) AND the illegal
  //      one simultaneously, so it could not have been the right predicate in
  //      either polarity. The pointer half is also dead weight: hThread is
  //      already a resolved GuestThreadHandle*, and GetKernelObject
  //      (CURRENT_THREAD_HANDLE) returns Translate(0xFFFFFFFE) = 0x1FFFFFFFE
  //      (xdm.h:72-77), which can never equal a real object pointer.
  //      (guest_thread.cpp:503-505 cites this line as evidence that the two
  //      GetThreadId implementations agree - they do, but this assert never
  //      used that agreement as a check.)
  //
  // Now a real runtime check with a named bounded marker on each refusal, so a
  // mismatch is reported instead of passing. GuestThreadHandle::GetThreadId is
  // the monotonic allocator id and GuestThread::GetCurrentThreadId() reads the
  // same space (guest_thread.cpp:332 / :509), so the comparison is like-for-like.
  if (!hThread) {
    static std::atomic<uint32_t> s_suspNull{0};
    const uint32_t n = s_suspNull.fetch_add(1) + 1;
    if (n <= 40 || (n % 500) == 0)
      MCLA_LOG_WARN("SUSP-FAIL-NULL #{} NtSuspendThread with a null thread "
                    "handle -> STATUS_INVALID_HANDLE lr={:08X}",
                    n,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return STATUS_INVALID_HANDLE;
  }
  if (hThread->GetThreadId() == GuestThread::GetCurrentThreadId()) {
    // STATUS_SUSPEND_FAILED (0xC0000041) from the XOS STATUS enumeration; the
    // local subset in xbox.h:413-451 does not name it, and xbox.h is not ours.
    static constexpr uint32_t kStatusSuspendFailed = 0xC0000041u;
    static std::atomic<uint32_t> s_suspSelf{0};
    const uint32_t n = s_suspSelf.fetch_add(1) + 1;
    if (n <= 40 || (n % 500) == 0)
      MCLA_LOG_WARN("SUSP-FAIL-SELF #{} NtSuspendThread on the CALLING thread "
                    "(tid={:08X}) refused -> STATUS_SUSPEND_FAILED (was an "
                    "inverted, NDEBUG-compiled-out assert) lr={:08X}",
                    n, hThread->GetThreadId(),
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return kStatusSuspendFailed;
  }

  // XOS writes the PREVIOUS suspend count through the out-parameter and the
  // guest reads it; it was never written at all. exchange() stores the same
  // value the old `suspended = true` did and hands back what was there.
  const bool wasSuspended = hThread->suspended.exchange(true);
  if (suspendCount)
    *suspendCount = wasSuspended ? 1u : 0u;
  hThread->suspended.wait(true);

  return S_OK;
}

uint32_t KeSetAffinityThread(uint32_t Thread, uint32_t Affinity,
                             be<uint32_t> *lpPreviousAffinity) {
  if (lpPreviousAffinity)
    *lpPreviousAffinity = 2;

  return 0;
}

void RtlLeaveCriticalSection(XRTL_CRITICAL_SECTION *cs) {
  int32_t recursionCount = cs->RecursionCount;
  if (recursionCount > 0) {
    recursionCount--;
    cs->RecursionCount = recursionCount;
  }

  if (recursionCount != 0)
    return;

  std::atomic_ref owningThread(cs->OwningThread);
  owningThread.store(0);
  owningThread.notify_one();
}

void RtlEnterCriticalSection(XRTL_CRITICAL_SECTION *cs) {
  uint32_t thisThread = g_ppcContext->r13.u32;
  assert(thisThread != NULL);

  std::atomic_ref owningThread(cs->OwningThread);

  while (true) {
    uint32_t previousOwner = 0;

    if (owningThread.compare_exchange_weak(previousOwner, thisThread) ||
        previousOwner == thisThread) {
      cs->RecursionCount++;
      return;
    }

    // F-564/F-566: log contention + timed force-acquire.
    // Guest threads can hold CS and get stuck (parked/dead), blocking the
    // boot worker forever. After 5s of contention, steal the lock.
    static std::atomic<uint32_t> s_csContention{0};
    const uint32_t cn = s_csContention.fetch_add(1) + 1;
    const uint32_t lr = static_cast<uint32_t>(g_ppcContext->lr);
    if (cn <= 32 || (cn % 500) == 0) {
      MCLA_LOG_WARN("CS-CONTEND #{} cs={:08X} owner={:08X} waiter={:08X} "
                    "lr={:08X} rec={}",
                    cn, reinterpret_cast<uintptr_t>(cs), previousOwner,
                    thisThread, lr, cs->RecursionCount);
    }

    // Try normal wait first (with timeout via spin + sleep)
    const auto start = std::chrono::steady_clock::now();
    bool acquired = false;
    while (!acquired) {
      const auto elapsed = std::chrono::steady_clock::now() - start;
      if (elapsed > std::chrono::seconds(5)) {
        // Force-acquire after 5s timeout
        MCLA_LOG_WARN("CS-TIMEOUT #{} cs={:08X} stolen_from={:08X} by={:08X} "
                      "lr={:08X} waited_ms={}",
                      cn, reinterpret_cast<uintptr_t>(cs), previousOwner,
                      thisThread, lr,
                      static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()));
        owningThread.store(thisThread);
        cs->RecursionCount = 1;
        return;
      }
      previousOwner = 0;
      if (owningThread.compare_exchange_weak(previousOwner, thisThread) ||
          previousOwner == thisThread) {
        cs->RecursionCount++;
        return;
      }
      // Brief sleep to avoid burning CPU
      Sleep(1);
    }
  }
}

// ===========================================================================
// F-840 (2026-10-21) -- RtlImageXexHeaderField: MEASUREMENT ONLY.  NOT FIXED.
//
// THIS BODY IS DELIBERATELY LEFT BEHAVIOURALLY UNCHANGED.  It is a `void`
// hook, so r3 still comes back as the guest's own first argument, exactly as
// before this batch.  Nothing here changes what the guest sees.
//
// WHY IT IS NOT FIXED YET, with the measurements:
//
// 1. THE CONSOLE RETURNS A POINTER INTO THE XEX2 HEADER, not a value.  The
//    guest's own bytes say so: at 0x821329A8
//    (generated/ppc_xenon/ppc_recomp.0.cpp:7204-7216)
//      7204  bl 0x827bcf74            ; RtlImageXexHeaderField
//      7207  cmplwi r3,0
//      7210  beq -> 821329c8          ; r3 == 0 => "field not found"
//      7211  lwz r30,0(r3)            ; <-- the guest DEREFERENCES r3
//    The reference agrees: .research/xenia/src/xenia/cpu/xex_module.cc:69-102
//    (XexModule::GetOptHeader) returns, for key&0xFF == 0x01, a POINTER to the
//    inline value, and for any other low byte, a POINTER to
//    (xex_header + opt_header.offset).  Only key&0xFF == 0x00 returns the
//    value itself.  (The reference's own RtlImageXexHeaderField_entry at
//    .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_rtl.cc:338-347 throws
//    the pointer away and returns the value -- that is a divergence between the
//    reference and the console, and the GUEST is the oracle: it dereferences.)
//
// 2. THE TWO FIELDS THE GUEST ASKS FOR, measured out of
//    build/game_data/default.xex (XEX2 header at file offset 0, security info
//    at 0x90, 15 opt headers at 0x18):
//      0x00020401 (XEX_HEADER_DEFAULT_HEAP_SIZE)  -- ABSENT from the 15
//        opt headers, so the console answers 0 here (site 0x821329A8 asks
//        for exactly this: raw `lis r4,2 / ori r4,r4,1025` = 0x20401).
//      0x00040006 (XEX_HEADER_EXECUTION_INFO)     -- PRESENT, opt-header
//        offset 0x11E4, so the console answers (xex_header + 0x11E4).
//
// 3. WHY THE HOST CANNOT PRODUCE THAT POINTER YET.  The answer must be a
//    guest-readable address INSIDE the XEX2 header, and this host does not
//    map the XEX2 header into guest memory at all: the boot host copies only
//    the DECOMPRESSED PE image (src/boot_host.cpp:924-927, InstallGuestImage)
//    and the XEX2 header is not part of it.  MEASURED: the string "XEX2"
//    occurs ZERO times in build/cache/mcla_pe.bin, i.e. no guest address
//    holds an XEX2 header.
//
// 4. WHY IT WAS NOT "JUST RETURNED 0".  At the second site the guest stores
//    the returned value and DEREFERENCES it 12 and 14 bytes further on
//    (generated/ppc_xenon/ppc_recomp.80.cpp:9433-9450 and its caller
//    :9496-9509: `lwz r11,80(r1)` then `lhz r10,12(r11)` / `lhz r11,14(r11)`).
//    Returning 0 there would flip the guest from "success" to
//    "0xC0000225 STATUS_NOT_FOUND" and change a branch at 0x8244E8CC
//    (recomp.80.cpp:11902-11911).  That is a behavioural change made on a
//    GUESS about a field the host cannot supply, and this batch does not make
//    guesses.
//
// WHAT THIS BODY DOES INSTEAD: it measures what the guest passes, so the next
// pass can finish the job without guessing.  It prints the header pointer the
// guest handed in, the 4 bytes at that pointer (the XEX2 magic would be
// 'XEX2' = 0x58455832), and the field index -- once per call site, at the
// house cadence.
//
// NEXT STEP (not done here): map the XEX2 header into guest memory, keep the
// guest's own header pointer in step with it, and return
// (header + opt_header.offset) for the keys whose low byte is neither 0x00
// nor 0x01, 0 for a key the XEX does not carry, and the inline value pointer
// for key&0xFF == 0x01.
// ===========================================================================
void RtlImageXexHeaderField() {
  if (!g_ppcContext) {
    return;
  }
  static std::atomic<uint32_t> s_census{0};
  const uint32_t n = s_census.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 20 || (n % 100) == 0) {
    const uint32_t headerPointer = g_ppcContext->r3.u32;
    const uint32_t fieldIndex = g_ppcContext->r4.u32;
    uint8_t magic[4] = {0, 0, 0, 0};
    const bool magicRead = mcla::kernel::GuestMemoryHeap::Instance().ReadBytes(
        headerPointer, magic, sizeof(magic));
    MCLA_LOG_INFO("RIXH #{} lr={:08X} header={:08X} magicRead={} magic=0x{:02X}"
                  "{:02X}{:02X}{:02X} field=0x{:08X} (BEHAVIOUR UNCHANGED: r3 "
                  "is still the guest's own argument)",
                  n, static_cast<uint32_t>(g_ppcContext->lr), headerPointer,
                  magicRead ? 1 : 0, magic[0], magic[1], magic[2], magic[3],
                  fieldIndex);
  }
}

void HalReturnToFirmware(uint32_t type) {
  // Terminates, never returns - but MCLA calls it mid-boot and continues
  // Must return (not std::exit) or process dies
  MCLA_LOG_INFO("HalReturnToFirmware: type={}", type);
  // Return to caller - game will continue
}

// RtlFillMemoryUlong(Destination, Length, Pattern) - MSDN ff552263; Xenia
// reference .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_rtl.cc:75-85.
// `Length` is in BYTES and is expected to be a multiple of 4; every ULONG
// receives the pattern in GUEST (big-endian) order.
//
// F-609: this was `LOG_UTILITY("!!! STUB !!!")`, and LOG_UTILITY expands to
// NOTHING in a release build (.research/UnleashedRecomp/UnleashedRecomp/os/
// logger.h:14-18) - so the fill silently never happened. Live call site:
// generated/ppc_xenon/ppc_recomp.78.cpp:18450-18454 fills 0x800 bytes at
// sp+0xC0 with 0x80000000, i.e. 2048 bytes of uninitialised stack were handed
// to sub_82412928 as if they had been filled.
void RtlFillMemoryUlong(void *destination, uint32_t length, uint32_t pattern) {
  if (!destination || length == 0)
    return;

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t destAddr = mem.MapVirtual(destination);
  if (destAddr == 0) {
    // Also covers destination == guest 0, which is the deliberate NOACCESS null
    // guard page (src/kernel/memory.cpp:218) - nothing to fill there, and
    // nothing to pretend about.
    MCLA_LOG_WARN("RtlFillMemoryUlong: dest outside the guest window, "
                  "len={} pattern={:08X} lr={:08X}",
                  length, pattern,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return;
  }

  // Trailing bytes under a ULONG boundary are not written: the WDK contract
  // requires Length % 4 == 0 and the reference drops the remainder
  // (xboxkrnl_rtl.cc:78, `count = length >> 2`).
  const uint32_t words = length >> 2;
  if (words == 0)
    return;

  if (!mem.IsValid(destAddr, static_cast<size_t>(words) * 4)) {
    MCLA_LOG_WARN("RtlFillMemoryUlong: range {:08X}+{:X} leaves the guest window, "
                  "lr={:08X}",
                  destAddr, words * 4,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return;
  }

  // Guest memory is only ever touched through the checked, endian-explicit
  // helpers, so the pattern is assembled here in guest byte order and handed
  // over with WriteBytes. Chunked at 16 KiB so a multi-megabyte fill does not
  // need a multi-megabyte scratch buffer.
  constexpr uint32_t kWordsPerChunk = 4096;
  const uint8_t patBytes[4] = {static_cast<uint8_t>(pattern >> 24),
                               static_cast<uint8_t>(pattern >> 16),
                               static_cast<uint8_t>(pattern >> 8),
                               static_cast<uint8_t>(pattern)};
  std::vector<uint8_t> chunk(static_cast<size_t>(kWordsPerChunk) * 4);
  for (size_t w = 0; w < kWordsPerChunk; ++w) {
    chunk[w * 4 + 0] = patBytes[0];
    chunk[w * 4 + 1] = patBytes[1];
    chunk[w * 4 + 2] = patBytes[2];
    chunk[w * 4 + 3] = patBytes[3];
  }

  for (uint32_t done = 0; done < words; done += kWordsPerChunk) {
    const uint32_t n = std::min(kWordsPerChunk, words - done);
    if (!mem.WriteBytes(destAddr + done * 4, chunk.data(), n * 4)) {
      MCLA_LOG_WARN("RtlFillMemoryUlong: write of {:X} bytes at {:08X} failed "
                    "after {} words, lr={:08X}",
                    n * 4, destAddr + done * 4, done,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      return;
    }
  }
}

void KeBugCheckEx() { __builtin_debugtrap(); }

uint32_t KeGetCurrentProcessType() { return 1; }

// RtlCompareMemoryUlong(Source, Length, Pattern) -> SIZE_T - MSDN ff552123;
// Xenia reference .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_rtl.cc:
// 54-71.
//
// NOT memcmp: the real 360 export is (Source, Length, Pattern) and returns the
// COUNT of ULONGs in Source that equal Pattern; unaligned Source or a Length
// that is not a multiple of 4 returns 0. Every one of the 8 guest call sites
// uses that shape (generated/ppc_xenon/ppc_recomp.0.cpp:8309-8316, 8406-8413,
// 8582-8589, 8697-8704, 9185-9191, 9533-9539, 16575-16580, 17531-17536 - each
// sets r3 = block+24, r4 = a byte length, r5 = the pattern).
//
// F-609: this was `void RtlCompareMemoryUlong() { LOG_UTILITY(...) }`. Two
// defects in one line: the body was a no-op in release, AND `void` meant the
// hook never assigned r3 - so all 8 call sites read the *incoming* r3, i.e. the
// Source pointer, as the match count.
uint32_t RtlCompareMemoryUlong(const void *source, uint32_t length,
                               uint32_t pattern) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t sourceAddr = source ? mem.MapVirtual(source) : 0;

  // Same refusal as the reference: nothing to count if Source or Length is not
  // ULONG-granular, or if the address is not in the guest window (guest 0 is
  // the NOACCESS guard page, memory.cpp:218).
  if (sourceAddr == 0 || (sourceAddr % 4) != 0 || (length % 4) != 0)
    return 0;

  const uint32_t words = length >> 2;
  uint32_t matches = 0;
  for (uint32_t i = 0; i < words; ++i) {
    uint32_t value = 0;
    if (!mem.ReadU32BE(sourceAddr + i * 4, &value)) {
      // Return only what was actually verified - never a count that implies
      // the whole range was scanned.
      static std::atomic<uint32_t> s_shortScans{0};
      const uint32_t n = s_shortScans.fetch_add(1) + 1;
      if (n <= 20 || (n % 500) == 0)
        MCLA_LOG_WARN("RtlCompareMemoryUlong: read failed at word {} of {} "
                      "(src={:08X} len={}) -> partial count {} #{} lr={:08X}",
                      i, words, sourceAddr, length, matches, n,
                      static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      return matches;
    }
    if (value == pattern)
      ++matches;
  }

  {
    static std::atomic<uint32_t> s_scans{0};
    const uint32_t n = s_scans.fetch_add(1) + 1;
    if (n <= 20 || (n % 500) == 0)
      MCLA_LOG_INFO("RtlCompareMemoryUlong #{} src={:08X} words={} "
                    "pattern={:08X} matches={} lr={:08X}",
                    n, sourceAddr, words, pattern, matches,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  }
  return matches;
}

uint32_t RtlInitializeCriticalSection(XRTL_CRITICAL_SECTION *cs) {
  cs->Header.Absolute = 0;
  cs->LockCount = -1;
  cs->RecursionCount = 0;
  cs->OwningThread = 0;
  // Session 76j: the guest's allocator guard (sub_821C8FE0) reads the DWORD
  // at cs+0 and SKIPS locking entirely when it is zero. On HW the kernel init
  // leaves that word nonzero (LockCount=-1 semantics) so the global allocator
  // critical section 0x82855A0C actually serializes the sysMemSimpleAllocator
  // across threads. Leaving it 0 ran the heap unlocked → freelist overlap →
  // the checkerboard placeholder fill landed on live allocations.
  cs->Header.Lock = 0xFFFFFFFFu;

  static std::atomic<uint32_t> s_csInitCount{0};
  const uint32_t n = s_csInitCount.fetch_add(1) + 1;
  if (n <= 40) {
    const uint32_t guestCs = mcla::kernel::g_memory.MapVirtual(cs);
    MCLA_LOG_INFO("RtlInitializeCriticalSection #{} cs={:p} guest={:08X}", n,
                  (void *)cs, guestCs);
  }
  return 0;
}

// ============================================================================
// (rule 1b, 2026-10-21, fix_raise) The guest's OWN `raise`.
//
// THE CONSOLE'S DELIVERY MECHANISM, READ OUT OF THE GUEST'S OWN BYTES:
//  1. The guest calls RtlRaiseException(EXCEPTION_RECORD*) -- r3 = the record.
//     The emitted call is `ctx.lr = 0x821350B8; __imp__RtlRaiseException(ctx,
//     base);` (generated/ppc_xenon/ppc_recomp.0.cpp:13700-13703; the same
//     shape at ppc_recomp.0.cpp:14875 and ppc_recomp.81.cpp:19385-19387).
//     Three guest call sites: 0x821350B4, 0x82135C58, 0x82457D7C
//     (tools/ppc_xrefs.py calls 0x827BD014).
//  2. The record is a 32-bit PPC EXCEPTION_RECORD in guest memory, big-endian:
//     +0 ExceptionCode, +4 ExceptionFlags, +8 ExceptionRecord (nested),
//     +12 ExceptionAddress, +16 NumberParameters, +24 ExceptionInformation[].
//     MEASURED at the guest's own record builders: 0x82135094-0x821350B0
//     (code 0xC0000017 = STATUS_NO_MEMORY, flags, nested, address, nparams)
//     and 0x82135C38-0x82135C54 (the same five fields), and
//     0x82457D20-0x82457D60 (code from the caller's r3, flags = r4&1,
//     nested = 0, address = 0x82457D10, nparams = min(r5,15)).
//  3. The console's normal delivery target is the GUEST's own catch: the
//     guest's .text carries 31 eight-byte descriptors
//     {0x827BCF04 = the address of `__imp____C_specific_handler`,
//      <scope-table pointer>} immediately BEFORE the entry of the function
//     that owns the handler (site = fn - 8), and the matching .pdata entry
//     (20,071 entries) has bit 31 set (0xC000....) where every other entry
//     has 0x4000.... .  The scope table is the 16-byte MSVC record in .rdata
//     {EnclosingLevel=1, FilterFunc, HandlerFunc, JumpTarget} -- measured at
//     0x82102448, 0x82102460, 0x82102478, 0x82102490, 0x82102510,
//     0x82102528.  So the 360 unwinds the guest's stack, calls the frame's
//     language handler __C_specific_handler(EXCEPTION_RECORD*,
//     EstablisherFrame, CONTEXT*, DispatcherContext*), which runs the guest's
//     Filter then Handler, and the guest resumes at the scope table's
//     JumpTarget.
//
// WHY THE HOST CANNOT REPRODUCE STEP 3 FROM THIS HOOK (measured, not
// guessed):
//  (a) The host cannot redirect the recompiled flow.  The emitted code
//      continues at `loc_821350B8:` immediately after the call
//      (generated/ppc_xenon/ppc_recomp.0.cpp:13704), so returning from this
//      hook always resumes the raise site's OWN continuation; the only way
//      out of the recompiled frames is a host unwind (a host C++ exception
//      thrown through the guest's frames), which is exactly what must NOT
//      happen.
//  (b) The guest's Filter/Handler are mid-function funclets, and the
//      recompiled function table (45,190 entries,
//      generated/ppc_xenon/ppc_func_mapping.cpp) contains 0x8213247C and
//      0x821350D4 (the JumpTargets) but NOT 0x821350BC, 0x8213246C,
//      0x821348F8, 0x821353B0 or 0x821351D8 -- so PPC_LOOKUP_FUNC cannot
//      reach a catch block.
//  (c) The guest imports NO handler-registration call: its 246-entry import
//      table has no SetUnhandledExceptionFilter and no
//      RtlAddVectoredExceptionHandler.  The only exception-related imports
//      are __C_specific_handler (0x827BCF04, 0 call sites), RtlRaiseException
//      (0x827BD014, 3 call sites) and RtlUnwind (0x827BDCA4, whose local
//      thunk sub_8274ABB0 has 0 callers).
//  => The catch block is unreachable, and the console's FALLBACK for an
//     exception nobody handles -- the process's unhandled-exception path --
//     IS reachable, and IS the guest's own registered handler: the slot the
//     guest's fatal dispatcher sub_821BD618 consults
//     (`lis r11,0x8286 / lwz r10,-352(r11)` ->
//     generated/ppc_xenon/ppc_recomp.14.cpp:22078-22084) = 0x8285FEA0.  The
//     guest installs its handler there itself
//     (`lis r10,0x8213 / lis r8,0x8286 / addi r10,r10,1656 / stw r10,-352(r8)`
//     at 0x821317AC-0x821317C8) = the guest function 0x82130678, which is in
//     the recompiled function table.  Its call chain is
//     0x82130678 -> 0x82388598 (leaf) -> 0x82131C58 ->
//     __imp__XamShowDirtyDiscErrorUI (the host SUPPRESSES it,
//     src/kernel/imports.cpp:1599-1601) and sub_821324A0 ->
//     __imp__XamLoaderLaunchTitle (a host no-op,
//     src/kernel/imports.cpp:1665-1667).  It never reaches the parking fatal
//     dispatcher sub_821BD618, so the delivery cannot hang the boot thread.
//
// WHAT THIS BODY DOES:
//  * reads the guest's EXCEPTION_RECORD and LOGS it -- the instrument this
//    defect class never had: LOG_UTILITY expands to nothing unless _DEBUG is
//    defined (.research/UnleashedRecomp/UnleashedRecomp/os/logger.h:14-18) and
//    the build is RelWithDebInfo (build/CMakeCache.txt), so the old stub was
//    invisible in every soak.
//  * delivers the exception to the GUEST's registered handler, IN GUEST CODE,
//    called exactly as the guest's own dispatcher calls it (the dispatcher
//    sets NO arguments: `mtctr r10 / bctrl`,
//    generated/ppc_xenon/ppc_recomp.14.cpp:22088-22090) and on the raising
//    frame's stack, so the handler runs on the guest's own stack.
//  * NEVER throws: the host's stack is not unwound through the recompiled
//    frames, and the guest's own RAII/destructors are not run by the host.
//  * RETURNS: the console's RtlRaiseException does not return, but (a) makes
//    that impossible here, so the guest continues at the raise site's own
//    continuation.  This is the task's sanctioned smallest safe step.
//
// FALSIFIER (the next soak must answer all three):
//  * a `RAISE-EXC` row must appear iff the guest really raises; 0 rows means
//    the guest never raises on this path and this body changed nothing
//    observable;
//  * the guest's behaviour AFTER the raise must change: the guest's
//    registered handler must now run (delivered=1) and the guest's
//    post-raise path must differ from the pre-fix path;
//  * the 540 capped VEH rows in build/w846.log CANNOT be fixed by this change
//    and are NOT the guest's raise: they are the HOST's D3D12 layer throwing
//    a C++ exception out of D3D12Backend::EnsureGuestRenderTarget ->
//    m_device->CreateCommittedResource (src/d3d12_backend.cpp:986-988),
//    which D3D12 catches internally and turns into FAILED(hr) (the host's own
//    "GUEST-RT-REFUSED ... create-failed" row, build/w846.log:9722) -- a
//    vectored handler sees every C++ throw, caught or not
//    (build/w846.log:9692-9721 is the stack).  That file belongs to another
//    agent; this change does not touch it.
// ============================================================================
void RtlRaiseException_x(PPCContext &ctx, uint8_t *base) {
  const uint32_t recVa = ctx.r3.u32;
  uint32_t code = 0, flags = 0, nest = 0, excAddr = 0, nparams = 0, info0 = 0;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const bool recOk = mem.ReadU32BE(recVa + 0, &code);
  (void)mem.ReadU32BE(recVa + 4, &flags);
  (void)mem.ReadU32BE(recVa + 8, &nest);
  (void)mem.ReadU32BE(recVa + 12, &excAddr);
  (void)mem.ReadU32BE(recVa + 16, &nparams);
  (void)mem.ReadU32BE(recVa + 24, &info0);

  // The guest's REGISTERED handler (the console's process unhandled-exception
  // filter, in the guest's own terms): the slot the guest's fatal dispatcher
  // sub_821BD618 reads -- generated/ppc_xenon/ppc_recomp.14.cpp:22078-22084.
  constexpr uint32_t kGuestHandlerSlot = 0x8285FEA0u;
  uint32_t handler = 0;
  (void)mem.ReadU32BE(kGuestHandlerSlot, &handler);

  static std::atomic<uint32_t> s_raiseCount{0};
  const uint32_t n = s_raiseCount.fetch_add(1) + 1;

  bool delivered = false;
  if (handler != 0) {
    uint8_t *gbase = mcla::kernel::g_memory.base;
    PPCFunc *fn = PPC_LOOKUP_FUNC(gbase, handler);
    if (fn != nullptr) {
      // In GUEST CODE, on the raising frame's stack, with the SAME arguments
      // the guest's own dispatcher passes (none: it does `mtctr r10; bctrl`).
      PPCContext hctx = ctx;
      hctx.r3.u32 = recVa; // the record; the handler overwrites r3 with 0
      PPCContext *cur = GetPPCContext();
      if (cur != nullptr) {
        ScopedPPCContext scope(*cur, hctx);
        fn(hctx, gbase);
      } else {
        fn(hctx, gbase);
      }
      delivered = true;
    }
  }

  MCLA_LOG_WARN(
      "RAISE-EXC #{} lr={:08X} record={:08X} recordRead={} code=0x{:08X} "
      "flags=0x{:08X} nest=0x{:08X} addr=0x{:08X} nparams={} info0=0x{:08X} "
      "handlerSlot={:08X} handler={:08X} delivered={} -- the guest's raise was "
      "delivered to the guest's own registered handler IN GUEST CODE (the "
      "guest's C++ catch block is unreachable from the host: the recompiled "
      "flow cannot be redirected and the catch blocks are not function-table "
      "entries); the host stack was NOT unwound and the guest continues at "
      "the raise site's own continuation",
      n, static_cast<uint32_t>(ctx.lr), recVa, recOk ? 1 : 0, code, flags, nest,
      excAddr, nparams, info0, kGuestHandlerSlot, handler, delivered ? 1 : 0);
  spdlog::default_logger()->flush();
}


void KfReleaseSpinLock(uint32_t *spinLock, uint32_t oldIrql) {
  // Console order (xboxkrnl_threading.cc:940-947): LOWER first, then unlock.
  // The guest passes the value KeRaiseIrqlToDpcLevel/KfAcquireSpinLock gave
  // it (0x82419738 `mr r29,r3` -> 0x82419804 `mr r4,r29` -> 0x8241980C
  // `bl __imp__KfReleaseSpinLock`), so the host and the guest agree on the
  // level they are leaving.
  HostLowerIrql(static_cast<uint8_t>(oldIrql & 0xFF));
  std::atomic_ref spinLockRef(*spinLock);
  spinLockRef = 0;
}

static constexpr uint32_t bswap32(uint32_t v) { return __builtin_bswap32(v); }

uint32_t KfAcquireSpinLock(uint32_t *spinLock) {
  // The lock word lives in GUEST memory and guest inline code reads/writes it
  // through BE accessors (PPC_LOAD_U32/PPC_STORE_U32 bswap). All values we
  // store here must therefore be byte-swapped into guest order, and the
  // unlocked sentinel (0) is endian-symmetric.
  std::atomic_ref spinLockRef(*spinLock);
  const uint32_t selfBe = bswap32(g_ppcContext->r13.u32);

  // CONTENTION PROBE (session 64): the vblank ISR stalled on 2026-09-06 and
  // the guest driver worker parked on its tick semaphore — attribute who
  // holds the lock and who spins (caller lr). Guest addr for the log:
  // ptr - g_memory.base.
  const auto start = std::chrono::steady_clock::now();
  bool recovered = false;
  uint32_t spins = 0;
  while (true) {
    uint32_t expected = 0;
    if (spinLockRef.compare_exchange_weak(expected, selfBe))
      break;

    // LOCK-RECOVERY SAFETY NET (session 64): a healthy holder keeps this
    // lock for microseconds. If we're still spinning ~5s later the holder
    // is phantom/garbage (e.g. a stale seed or a died-without-release
    // thread) and no host thread can ever release it — the ISR would wedge
    // the whole vsync path. Log once, then steal the lock. Real HW never
    // sees this because a raised-IRQL ISR preempts the holding thread; our
    // cooperative host threads cannot preempt guest code, so stealing is
    // the honest emulation point here.
    if (!recovered &&
        std::chrono::steady_clock::now() - start > std::chrono::seconds(5)) {
      recovered = true;
      MCLA_LOG_WARN("KFSPIN-RECOVERY lock@{:08X} holder_r13be={:08X} "
                    "spins={} lr={:08X} — stealing after 5s",
                    static_cast<uint32_t>(
                        reinterpret_cast<uintptr_t>(spinLock) -
                        reinterpret_cast<uintptr_t>(
                            mcla::kernel::g_memory.base)),
                    bswap32(spinLockRef.load()), spins,
                    g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr)
                                 : 0);
      spinLockRef.store(selfBe, std::memory_order_release);
      break;
    }

    const uint32_t n = ++spins;
    if (n <= 60 || (n % 5000) == 0) {
      const uint32_t holder = bswap32(spinLockRef.load());
      MCLA_LOG_INFO("KFSPIN-CONTENDED lock@{:08X} holder_r13be={:08X} "
                    "spins={} lr={:08X}",
                    static_cast<uint32_t>(
                        reinterpret_cast<uintptr_t>(spinLock) -
                        reinterpret_cast<uintptr_t>(
                            mcla::kernel::g_memory.base)),
                    holder, n,
                    g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0);
    }
    std::this_thread::yield();
  }

  // Console (xboxkrnl_threading.cc:914-935): lock, THEN raise the IRQL to
  // DISPATCH, and RETURN THE OLD IRQL.  The guest consumes r3 immediately
  // (0x82419730 `bl __imp__KfAcquireSpinLock` -> 0x82419738 `mr r29,r3` ->
  // 0x82419804 `mr r4,r29` -> 0x8241980C `bl __imp__KfReleaseSpinLock`),
  // so before this change the guest's "old IRQL" slot received the LOCK
  // POINTER (the host returned void, so r3 still held the lock pointer).
  const uint32_t oldIrql = HostRaiseIrql(kIrqlDispatch);
  {
    static std::atomic<uint32_t> s_kfAcquire{0};
    const uint32_t n = s_kfAcquire.fetch_add(1) + 1;
    if (n <= 40 || (n % 5000) == 0)
      MCLA_LOG_INFO("IRQL-KFACQUIRE #{} lock={:08X} old_irql={} new_irql={}",
                    n,
                    static_cast<uint32_t>(
                        reinterpret_cast<uintptr_t>(spinLock) -
                        reinterpret_cast<uintptr_t>(
                            mcla::kernel::g_memory.base)),
                    oldIrql, static_cast<unsigned>(kIrqlDispatch));
  }
  return oldIrql;
}

uint64_t KeQueryPerformanceFrequency() { return 49875000; }

void MmFreePhysicalMemory(uint32_t type, uint32_t guestAddress) {
  if (guestAddress != NULL)
    g_userHeap.Free(
        mcla::kernel::GuestMemoryHeap::Instance().Translate(guestAddress));
}

bool VdPersistDisplay(uint32_t a1, uint32_t *a2) {
  if (a2) *a2 = NULL;
  return false;
}

void VdSwap(uint32_t buf, uint32_t fetch, uint32_t unk2, uint32_t unk3,
            uint32_t unk4, uint32_t fbuf, uint32_t fmt, uint32_t cs, uint32_t w,
            uint32_t h) {
  MCLA_LOG_INFO(
      "VdSwap: buf=0x{:08X} fetch=0x{:08X} unk2=0x{:08X} unk3=0x{:08X} "
      "unk4=0x{:08X} fbuf=0x{:08X} fmt=0x{:08X} cs=0x{:08X} w={} h={}",
      buf, fetch, unk2, unk3, unk4, fbuf, fmt, cs, w, h);
  // Present callback - chain to native renderer hook
}

void VdGetSystemCommandBuffer(uint32_t p0, uint32_t p1) {
  // Kernel-acceptance layer (diagnostic): under
  // cp_deferred_consume_experiment=1 this export returns coherent
  // system-command-buffer state instead of BEEF markers.
  //   out1 (p0): 0x94-byte descriptor struct - contents unproven from any
  //              reference, so it stays ZEROED (xenia-parity neutral).
  //   out2 (p1): opaque identifier token; the guest stores it into
  //              subctx+8 (77.cpp decode) and passes it around opaquely.
  //              It changes only when real deferred consumption advances.
  if (mcla::gpu::CpDeferredConsumeEnabled()) {
    if (p0) {
      static const uint8_t zeroBuf[0x94] = {0};
      (void)mcla::kernel::GuestMemoryHeap::Instance().WriteBytes(p0, zeroBuf,
                                                                 0x94);
    }
    if (p1) {
      const uint32_t token = mcla::gpu::CpScbToken();
      (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(p1, token);
      static std::atomic<uint32_t> s_gscb{0};
      const uint32_t n = s_gscb.fetch_add(1) + 1;
      if (n <= 8 || (n % 500) == 0) {
        MCLA_LOG_INFO("VdGetSystemCommandBuffer[{}] token={} idAddr={:08X}", n,
                      token, mcla::gpu::CpGpuIdentifierAddress());
      }
    }
    return;
  }

  // Xenia: p0.Zero(0x94), write 0xBEEF0000@p0, 0xBEEF0001@p1
  if (p0) {
    static const uint8_t zeroBuf[0x94] = {0};
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteBytes(p0, zeroBuf,
                                                               0x94);
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(p0, 0xBEEF0000);
  }
  if (p1) {
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(p1, 0xBEEF0001);
  }
}

// Console (xboxkrnl_threading.cc:978-982): unlock only, NO IRQL change --
// the caller is "at raised IRQL" and lowers it itself.  The guest does
// exactly that: 0x823EACF0 `bl __imp__KeReleaseSpinLockFromRaisedIrql` ->
// 0x823EACF8 `bl __imp__KfLowerIrql(saved)`.
void KeReleaseSpinLockFromRaisedIrql(uint32_t *spinLock) {
  std::atomic_ref spinLockRef(*spinLock);
  spinLockRef = 0;
}

// Console (xboxkrnl_threading.cc:956-963): CAS 0->1 and SPIN -- forever.
// The host cannot afford "forever": its guest threads are COOPERATIVE (a
// host thread that spins never yields the CPU to the holder), so an
// unbounded spin here wedges that host thread outright -- the one mechanism
// in the whole import table that can kill a thread by itself.
//
// TRADE-OFF, stated: after 5 s the host LOGS the holder and STEALS the lock.
// That breaks mutual exclusion for the remainder of the lock's life (the
// console would have kept waiting, and the console's holder is preemptible
// because DISPATCH/DPC IRQL outranks the waiter).  The alternative --
// spinning forever -- trades a rare, LOGGED, time-boxed correctness loss for
// a guaranteed, SILENT death of whichever host thread lost the race.  The
// same trade was already taken for KfAcquireSpinLock (the 5 s
// KFSPIN-RECOVERY steal); this edit makes the two paths agree.
//
// FALSIFIER: a soak that shows KFSPIN-RECOVERY-ATIRQL with a holder that is
// still making progress means the 5 s window is too short (raise it) and the
// steal is unnecessary; a soak with KFSPIN-CONTENDED but NO recovery means
// the window is right.
void KeAcquireSpinLockAtRaisedIrql(uint32_t *spinLock) {
  std::atomic_ref spinLockRef(*spinLock);
  const uint32_t selfBe = bswap32(g_ppcContext->r13.u32);

  const auto start = std::chrono::steady_clock::now();
  bool recovered = false;
  uint32_t spins = 0;
  while (true) {
    uint32_t expected = 0;
    if (spinLockRef.compare_exchange_weak(expected, selfBe))
      break;

    if (!recovered &&
        std::chrono::steady_clock::now() - start > std::chrono::seconds(5)) {
      recovered = true;
      MCLA_LOG_WARN(
          "KFSPIN-RECOVERY-ATIRQL lock@{:08X} holder_r13be={:08X} spins={} "
          "lr={:08X} - stealing after 5s (the console spins forever; the "
          "host's cooperative threads cannot preempt the holder, so an "
          "unbounded spin would wedge this host thread)",
          static_cast<uint32_t>(reinterpret_cast<uintptr_t>(spinLock) -
                                reinterpret_cast<uintptr_t>(
                                    mcla::kernel::g_memory.base)),
          bswap32(spinLockRef.load()), spins,
          g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0);
      spinLockRef.store(selfBe, std::memory_order_release);
      break;
    }

    const uint32_t n = ++spins;
    if (n <= 60 || (n % 5000) == 0) {
      const uint32_t holder = bswap32(spinLockRef.load());
      MCLA_LOG_INFO("KFSPIN-CONTENDED lock@{:08X} holder_r13be={:08X} "
                    "spins={} lr={:08X}",
                    static_cast<uint32_t>(reinterpret_cast<uintptr_t>(spinLock) -
                                          reinterpret_cast<uintptr_t>(
                                              mcla::kernel::g_memory.base)),
                    holder, n,
                    g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0);
    }
    std::this_thread::yield();
  }
}

void KeInitializeSpinLock(uint32_t *spinLock) {
  // Spinlock init (guest memory) - zero the spinlock
  *spinLock = 0;
}

uint32_t KiApcNormalRoutineNop() { return 0; }

void VdEnableRingBufferRPtrWriteBack(uint32_t ringBuffer,
                                     uint32_t blockSizeLog2) {
  // Xenia: r3 IS the read-pointer writeback address (CP_RB_RPTR_ADDR),
  // not a ring base. The host CP publishes the advanced dword index there.
  MCLA_LOG_INFO(
      "VdEnableRingBufferRPtrWriteBack: writeback=0x{:08X} blockLog2={}",
      ringBuffer, blockSizeLog2);
  mcla::gpu::CpEnableRPtrWriteBack(ringBuffer, blockSizeLog2);
}

void VdInitializeRingBuffer(uint32_t physAddr, uint32_t sizeLog2) {
  // Xenia xboxkrnl_video.cc -> CommandProcessor::InitializeRingBuffer:
  // records base/size and resets the read index ONLY - no memory writes
  // to the ring body. Zeroing here would destroy unread packets when the
  // guest re-initializes a still-active ring (per-ring REINIT in gpu_cp.cpp
  // deliberately RETAINS such state).
  MCLA_LOG_INFO("VdInitializeRingBuffer: physAddr=0x{:08X} sizeLog2={}",
                physAddr, sizeLog2);
  if (physAddr) {
    mcla::gpu::CpInitializeRingBuffer(physAddr, sizeLog2);
  }
}

void VdSetSystemCommandBufferGpuIdentifierAddress(uint32_t gpuIdAddr) {
  MCLA_LOG_INFO("VdSetSystemCommandBufferGpuIdentifierAddress: 0x{:08X}",
                gpuIdAddr);
  // Record the registered identifier/writeback slot (= &subctx[8]).
  // Bookkeeping is unconditional; consumers act only under the
  // cp_deferred_consume_experiment flag.
  mcla::gpu::CpRegisterGpuIdentifierAddress(gpuIdAddr);
}

void _vsnprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

void sprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

void ExRegisterTitleTerminateNotification() { LOG_UTILITY("!!! STUB !!!"); }

void VdShutdownEngines() { LOG_UTILITY("!!! STUB !!!"); }

void VdQueryVideoMode(XVIDEO_MODE *vm) {
  memset(vm, 0, sizeof(XVIDEO_MODE));
  vm->DisplayWidth = 1280;
  vm->DisplayHeight = 720;
  vm->IsInterlaced = false;
  vm->IsWidescreen = true;
  vm->IsHighDefinition = true;
  vm->RefreshRate = 0x42700000;
  vm->VideoStandard = 1;
  vm->Unknown4A = 0x4A;
  vm->Unknown01 = 0x01;
}

void VdGetCurrentDisplayInformation() { LOG_UTILITY("!!! STUB !!!"); }

void VdSetDisplayMode() { LOG_UTILITY("!!! STUB !!!"); }

// F-818: file scope, so the CP's interrupt dispatch (VdDispatchGraphicsInterrupt, below) can
// read the LIVE registration the guest made. They were function-local inside
// VdSetGraphicsInterruptCallback, which kept them invisible to every other TU.
static std::atomic<uint32_t> s_vsyncCallback{0};
static std::atomic<uint32_t> s_vsyncUserData{0};

// ============================================================================
// GUEST DPC QUEUE (2026-10-21, fix_dpc) -- modelled from the GUEST'S OWN BYTES.
//
// MEASURED in build/cache/mcla_pe.bin (offset = VA - 0x82000000):
//   0x8242FD00 -- the guest's KeInsertQueueDpc -- does, in order:
//     lbz   r10,268(r13)        ; the KPCR CPU byte. The host emulates the
//                               ; KPCR at 0x8F200000 (see kPcrCpuByte below,
//                               ; and the same byte VdDispatchGraphicsInterrupt
//                               ; saves/restores at imports.cpp).
//     mulli r10,r10,80         ; cpu * 80
//     lwz   r11,2148(r11)       ; [0x82000864]    (image word)
//     lwz   r11,0(r11)          ; [[0x82000864]]  = the per-CPU array base
//     add   r11,r10,r11         ; base + cpu*80
//     addi  r31,r11,11324       ; ring = base + cpu*80 + 0x2C3C
//     lwz   r10,11380(r11)      ; count = ring + 0x38
//     clrlwi/addi/rlwinm       ; index = (count & 3)
//     stwx  r5,r10,r31          ; ring[0x40 + 4*index] = the DPC pointer
//     lwz/addi/stw 11380       ; count++
//     bl    0x8242EBA0 (x2)    ; push {cpu, ptr} on the lock-free stack at
//                               ; 0x828D2FC8 (payload 0x828D1F90/0x828D1F94)
//     bl    0x827BD564          ; KeSetEvent(ring + 0x20, 1, 0)
//   => the DPC list is PER CPU -- not per thread, and NOT at 0x40004D5C --
//      4 entries deep, with an event at ring+0x20 that the enqueue raises.
//
// THE DRAIN IS THE ENVIRONMENT'S JOB. In the image, the ONLY three
// references to the count field (displacement 0x2C74) are 0x8242FD38,
// 0x8242FD4C and 0x8242FD54 -- all inside the enqueue -- and the ONLY
// reference to the stack head 0x828D2FC8 is the pusher 0x8242EBA0. Nothing
// in the image reads either structure, so on the console the kernel drains
// the per-CPU DPC list when the IRQL drops below DPC_LEVEL. Here the host
// IS the kernel, so the host drains it.
//
// DISPATCH POINT: the host's vblank thread (the kernel-role duty thread in
// VdSetGraphicsInterruptCallback) is the host's IRQL-lowering point -- the
// same place the old "BOOT-GATE LEVER" comment sat.
//
// WHAT THIS REPLACES (and does not): the old comment (imports.cpp, W36d,
// 2026-09-18) claimed the boot gate "is never called because the game's
// kernel KeInsertQueueDpc (sub_8242FD00) is invoked via indirect dispatch
// from unmapped stubs that were never recompiled" and that "the DPC queue
// at 0x40004D5C stays forever empty". The bytes do not support either
// claim: the guest's 206-entry import table (0x827BD004..0x827BDCD4,
// generated/ppc_xenon/ppc_func_mapping.cpp) contains NO KeInsertQueueDpc
// import, and 0x8242FD00 has ZERO direct call sites in the image
// (tools/ppc_xrefs.py calls 0x8242FD00 -> "0 call site(s)"); it is only
// ever passed as a CALLBACK ADDRESS (0x8241C540, 0x8241CBB0, 0x82430004).
// The boot gate 0x82131008 likewise appears exactly ONCE in the whole image
// (0x821315F4, `addi r4,r11,4104` inside sub_82131508) where it is stored
// as a 5-word delegate {fn=0x82131008, mode=1} into an engine object --
// it is NOT enqueued as a DPC.
// ============================================================================

// ============================================================================
// THE ISR's THREAD BLOCK (2026-10-21, fix_irq2, item 3)
// ============================================================================
//
// MEASURED DEFECT: EVERY host ISR context was hard-aliased to the BOOT
// WORKER's thread block:
//   * the vblank ISR:      cbCtx.r13.u32 = 0x8F200000
//   * the PM4/CP interrupt: ctx.r13.u32  = 0x8F200000
//   * the DPC dispatch:    dpcCtx.r13.u32 = 0x8F200000
// and 0x8F200000 IS the boot worker's own block (src/boot_host.cpp:1093
// `constexpr uint32_t ThreadBlock = 0x8F200000u`, tagged
// "boot-worker:static-8F200000" at :1139).
//
// WHY THAT IS A CORRECTNESS BUG, in the guest's own bytes: the console's
// lock-ownership test is "owner == r13":
//   0x823EAD18  mr r30,r13            ; r30 = this thread's identity
//   0x823EAD28  lwz r10,8(r31)       ; the lock's OWNER field
//   0x823EAD2C  cmplw r10,r30        ; owner == me?
//   0x823EAD30  beq -> 823EADA0      ; SAME OWNER => recursive path: NO CAS
// With one shared r13 the vblank ISR and the boot worker were the SAME owner,
// so the guest's own recursive path SKIPPED the compare-and-swap and
// MUTUAL EXCLUSION WAS LOST SILENTLY.  (The guest also stores the owner
// itself: 0x823EAD98 `stw r30,8(r31)`.)
//
// FIX: each host thread that runs guest ISR code gets its OWN PCR block, so
// the ownership test means something.  The block is the F-609 per-thread
// block (src/boot_host.cpp:1817 AllocateGuestThreadBlock -- the same block a
// real guest thread gets), with its TLS and TEB pointers REPOINTED at the
// boot worker's, so every guest read of [r13+0] (TLS) and [r13+0x100] (TEB)
// sees exactly what it saw before.  The change is confined to the r13
// IDENTITY, which is the only thing that has to change.  (On the console an
// ISR runs on a CPU whose KPCR still points at the interrupted thread's
// TLS/TEB, so sharing them is the closer model, not a compromise.)
//
// WHAT IS DELIBERATELY NOT CHANGED: the ISR's STACK (r1 = 0x8F000000) is
// still the shared 2 MiB static stack.  The F-609 block's own stack is
// 0x40000 bytes and lives INSIDE a g_userHeap allocation, so moving the ISR
// onto it risks a guest-stack overflow into the heap -- a worse failure than
// the one being fixed, and outside this task's scope.  The shared stack is a
// SEPARATE, still-open hazard; falsifier: a soak whose VSYNC-ISR enter/exit
// rows interleave with a boot-worker stack walk that shows corruption.
// ============================================================================

// The boot worker's thread block and the two pointers inside it
// (src/boot_host.cpp:1093-1099: TableBase = ThreadBlock + 0x1000 is the TLS
// array, Teb = ThreadBlock + 0x5000).
static constexpr uint32_t kBootWorkerPcr = 0x8F200000u;
static constexpr uint32_t kBootWorkerTls = 0x8F201000u;
static constexpr uint32_t kBootWorkerTeb = 0x8F205000u;

// The r13 an ISR context on THIS host thread uses.
static uint32_t IsrThreadBlockVa() {
  static thread_local uint32_t t_blockVa = 0;
  static thread_local bool t_resolved = false;
  if (t_resolved)
    return t_blockVa;
  t_resolved = true;

  // (2026-10-21, fix_raise) `GuestThreadBlock` / `AllocateGuestThreadBlock`
  // moved into `namespace mcla::boot` in src/boot_host.h (another session's
  // edit; this is the only use of those two names outside boot_host.cpp, and
  // the compiler's own suggestion is `mcla::boot::`).  Qualified here so this
  // TU compiles; no behaviour change.
  mcla::boot::GuestThreadBlock *block = mcla::boot::AllocateGuestThreadBlock("isr", 0);
  if (block == nullptr || !block->valid()) {
    MCLA_LOG_WARN("ISR-CTX #1 no thread block available - keeping the boot "
                  "worker's r13={:08X}; the guest's owner==r13 test stays "
                  "AMBIGUOUS between the ISR and the boot worker",
                  kBootWorkerPcr);
    return kBootWorkerPcr;
  }
  t_blockVa = block->pcrVa;
  // Repoint TLS/TEB at the boot worker's so nothing that reads them changes.
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  (void)mem.WriteU32BE(t_blockVa + 0x000u, kBootWorkerTls);
  (void)mem.WriteU32BE(t_blockVa + 0x100u, kBootWorkerTeb);
  MCLA_LOG_INFO("ISR-CTX #1 block={:08X} tls={:08X} teb={:08X} (was r13={:08X})",
                t_blockVa, kBootWorkerTls, kBootWorkerTeb, kBootWorkerPcr);
  return t_blockVa;
}

// The KPCR CPU byte: the guest reads the processor index as a BYTE at
// [r13+268] (`lbz r11,268(r13)` @ 0x8242FD14, and @ 0x824114D4 for the
// graphics interrupt).  The host's KPCR block is the one THIS host thread
// uses (see IsrThreadBlockVa above), so the byte is per-host-thread now
// instead of per-process.
static uint32_t DpcPcrCpuByte() { return IsrThreadBlockVa() + 268u; }
// The image word that points at the per-CPU array: `lwz r11,2148(r11)` with
// r11 = 0x82000000 -> [0x82000864].
static constexpr uint32_t kDpcPerCpuPtrWord = 0x82000864u;
// ring = base + cpu*80 + 0x2C3C; count at ring+0x38; 4 slots at ring+0x40;
// the event the enqueue raises is at ring+0x20.
static constexpr uint32_t kDpcRingOffset = 0x2C3Cu;
static constexpr uint32_t kDpcCountOffset = 0x38u;
static constexpr uint32_t kDpcSlotsOffset = 0x40u;
static constexpr uint32_t kDpcSlots = 4u;
static constexpr uint32_t kDpcCpuStride = 80u;

// The guest's per-CPU DPC ring base, computed exactly as the guest computes
// it. 0 = unresolvable (the image word or the per-CPU array is not mapped).
static uint32_t GuestDpcRingBase(uint8_t cpu) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t pcr = 0;
  if (!mem.ReadU32BE(kDpcPerCpuPtrWord, &pcr))
    return 0;
  uint32_t base = 0;
  if (!mem.ReadU32BE(pcr, &base))
    return 0;
  return base + static_cast<uint32_t>(cpu) * kDpcCpuStride + kDpcRingOffset;
}

// Drain the guest's per-CPU DPC list and run the queued DPCs with the
// console's DPC ABI (r3 = the DPC object, r4/r5 = the system arguments).
// Returns the number of DPCs dispatched.
static uint32_t DispatchGuestDpcQueue() {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint8_t cpu = 0;
  (void)mem.ReadU8(DpcPcrCpuByte(), &cpu);

  const uint32_t ring = GuestDpcRingBase(cpu);
  if (ring == 0) {
    static std::atomic<uint32_t> s_noRing{0};
    const uint32_t n = s_noRing.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 4 || (n % 500) == 0u) {
      uint32_t pcr = 0;
      (void)mem.ReadU32BE(kDpcPerCpuPtrWord, &pcr);
      MCLA_LOG_INFO("DPC-CENSUS #{} no-ring cpu={} pcrword={:08X} "
                    "(the per-CPU array is not mapped)",
                    n, static_cast<uint32_t>(cpu), pcr);
    }
    return 0;
  }

  uint32_t count = 0;
  if (!mem.ReadU32BE(ring + kDpcCountOffset, &count))
    return 0;
  if (count == 0)
    return 0;

  // The ring is 4 deep and the guest's index is (count & 3): the NEWEST
  // entry is at (count-1)&3, so the oldest of the n entries we take sits at
  // (count-n)&3. Take them oldest-first (FIFO).
  const uint32_t n = (count > kDpcSlots) ? kDpcSlots : count;
  uint32_t entries[kDpcSlots] = {0, 0, 0, 0};
  for (uint32_t i = 0; i < n; ++i) {
    const uint32_t slot = (count - n + i) & (kDpcSlots - 1u);
    (void)mem.ReadU32BE(ring + kDpcSlotsOffset + slot * 4u, &entries[i]);
  }
  // Take them: the count is the guest's only index source, and zeroing it
  // makes the next append land in slot 0 (the guest's own (count&3) rule).
  (void)mem.WriteU32BE(ring + kDpcCountOffset, 0);

  uint8_t *base = mcla::kernel::g_memory.base;
  uint32_t dispatched = 0;
  for (uint32_t i = 0; i < n; ++i) {
    const uint32_t entry = entries[i];
    if (entry == 0)
      continue;
    // Two candidate models, both guarded by "is this a REGISTERED guest
    // function?" so the host never executes data:
    //   (a) the queued word IS the routine (the routine-pointer model);
    //   (b) the queued word is a DPC OBJECT whose first word is the routine
    //       (the console's KDPC layout: {Routine, Arg1, Arg2}).
    PPCFunc *fn = mcla::kernel::g_memory.FindFunction(entry);
    uint32_t routine = entry;
    if (!fn) {
      uint32_t w0 = 0;
      if (mem.ReadU32BE(entry, &w0)) {
        PPCFunc *f2 = mcla::kernel::g_memory.FindFunction(w0);
        if (f2) {
          fn = f2;
          routine = w0;
        }
      }
    }
    if (!fn) {
      static std::atomic<uint32_t> s_unresolved{0};
      const uint32_t u = s_unresolved.fetch_add(1, std::memory_order_relaxed) + 1;
      if (u <= 20 || (u % 100) == 0u) {
        MCLA_LOG_WARN("DPC-UNRESOLVED #{} entry={:08X} ring={:08X} cpu={} - "
                      "not a registered guest function; dropped",
                      u, entry, ring, static_cast<uint32_t>(cpu));
      }
      continue;
    }
    static std::atomic<uint32_t> s_dpcRuns{0};
    const uint32_t rn = s_dpcRuns.fetch_add(1, std::memory_order_relaxed) + 1;
    if (rn <= 40 || (rn % 500) == 0u) {
      MCLA_LOG_INFO("DPC-DISPATCH #{} entry={:08X} routine={:08X} ring={:08X} "
                    "cpu={} count={}",
                    rn, entry, routine, ring, static_cast<uint32_t>(cpu), count);
    }
    // Console DPC ABI: the routine runs at DPC_LEVEL on the interrupted
    // thread's stack, with (Dpc, SystemArgument1, SystemArgument2).
    PPCContext dpcCtx{};
    dpcCtx.r3.u32 = entry;
    dpcCtx.r4.u32 = 0;
    dpcCtx.r5.u32 = 0;
    dpcCtx.r13.u32 = IsrThreadBlockVa(); // THIS host thread's block, not the
                                         // boot worker's (see IsrThreadBlockVa)
    dpcCtx.r1.u32 = 0x8F000000u;   // stack top, as the vblank path
    dpcCtx.lr = 0x00FFFFFFu;       // dummy LR, as the vblank path
    dpcCtx.msr = 0x200A000;
    PPCContext *prev = GetPPCContext();
    SetPPCContext(dpcCtx);
    fn(dpcCtx, base);
    if (prev)
      SetPPCContext(*prev);
    ++dispatched;
  }
  return dispatched;
}

// EXPLICIT, STATED period of the host's guest-clock tick.
//
// WHY (2026-10-21, fix_typebyte).  The guest's clock handler (0x8242FB88 -
// the title's "GPU poller"; the guest's own message registry pairs it with
// message id 0x40005E03) waits on 0x40004D7C with an EXPLICIT 30 ms
// deadline: the guest builds the timeout in its own frame with
// `lis r11,FFFB / ori r11,r11,6C20 / std r11,80(r1)` = -300000 100-ns ticks
// = 30 ms (0x8242FBA8..0x8242FBBC) and branches to its own STATUS_TIMEOUT
// handler at 0x8242FC3C (`cmpli cr6,r3,0102 / beq -> 0x8242FC3C`) when the
// deadline expires.
//
// The host used to deliver that tick from the GPU-vblank thread (~16.6 ms
// MEASURED), so the signal ALWAYS beat the 30 ms deadline and the guest's
// watchdog was 100% dead: build/w842.log has 4809 WAKE[KWFSO] rows, every
// one status=00000000, and NOT ONE status=00000102.
//
// 40 ms is the smallest round period that leaves a 10 ms margin over the
// guest's 30 ms deadline (the host timer must never drift under it, and the
// guest re-arms its wait a little after each tick).  This is a STATED host
// choice, NOT a measured console fact: the console's true clock period for
// this object is not measurable from this tree (build/agents/audit_irq.md
// sec.D records exactly that gap).
//
// FALSIFIER: the guest's 30 ms waits must start returning STATUS_TIMEOUT
// (WAKE[KWFSO] status=00000102 must appear) and the guest's watchdog body at
// 0x8242FC3C must execute.  If the parent's soak shows the guest's poller
// stalling or the boot regressing, this constant is the single knob.
static constexpr uint32_t kGuestClockTickPeriodMs = 40;

// Start the dedicated guest-clock tick thread (once).
static void StartGuestClockTickThread()
{
    static std::atomic<bool> s_clockTickStarted{false};
    if (s_clockTickStarted.exchange(true))
        return;
    std::thread([]() {
        using namespace std::chrono;
        const auto period = milliseconds(kGuestClockTickPeriodMs);
        auto next = steady_clock::now() + period;
        while (true) {
            std::this_thread::sleep_until(next);
            const auto now = steady_clock::now();
            next += period;
            // Never let a late wake shorten the next period below the stated
            // one (otherwise the tick could slip under the guest's 30 ms
            // deadline and the watchdog would go silent again).
            if (next <= now)
                next = now + period;
            SignalSchedulerTick();
        }
    }).detach();
}

void VdSetGraphicsInterruptCallback(uint32_t callback, uint32_t userData) {
  MCLA_LOG_INFO(
      "VdSetGraphicsInterruptCallback: callback=0x{:08X} user=0x{:08X}",
      callback, userData);

  static std::atomic<bool> s_vsyncRunning{false};
  static uint32_t s_frameCounter = 0;

  s_vsyncCallback.store(callback);
  s_vsyncUserData.store(userData);

  if (!s_vsyncRunning.exchange(true)) {
    std::thread([=]() {
      MCLA_LOG_INFO("VSync thread started: callback=0x{:08X}", callback);
      while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60fps
        uint32_t currentCallback = s_vsyncCallback.load();
        uint32_t currentUserData = s_vsyncUserData.load();
        if (currentCallback != 0) {
          uint8_t *base = mcla::kernel::g_memory.base;
          PPCFunc *fn = PPC_LOOKUP_FUNC(base, currentCallback);
          if (fn) {
            PPCContext cbCtx{};
            // r3 = INTERRUPT TYPE, not userData (decoded from
            // generated sub_82411478). Xenia ground truth: vblank
            // delivers r3=0 (graphics/vblank branch — MarkVblank,
            // graphics_system.cc:97-118); r3=1 fires ONLY when the
            // CP drains a PM4_INTERRUPT packet
            // (command_processor.cc:900-913), which we never
            // synthesize. 2026-08-23 session-5 correction of the
            // earlier r3=1 flip: our timer is the vertical blank,
            // so deliver type 0.
            cbCtx.r3.u32 = 0;
            cbCtx.r4.u32 = currentUserData; // GPU context pointer
            cbCtx.r5.u32 = 0;               // field counter
            cbCtx.r13.u32 =
                IsrThreadBlockVa(); // THIS host thread's PCR block -- it used
                                    // to be the boot worker's 0x8F200000, which
                                    // made the guest's owner==r13 lock test
                                    // ambiguous (see IsrThreadBlockVa)
            cbCtx.r1.u32 = 0x8F000000; // stack top (from boot_host.cpp)
            cbCtx.lr = 0x00FFFFFF;     // dummy LR
            cbCtx.msr = 0x200A000;

            // Publish this thread's context so guest imports can read
            // TLS/TEB/r13
            SetPPCContext(cbCtx);

            // Per-frame ISR enter/exit probe (session 64): the vblank ISR
            // hung silently between frames 4-490 on the 2026-09-06 run (zero
            // SEMA-release probes after ~#7, zero frame%500 logs) — log
            // enter+exit with GPU-context diagnostics so the hang site is
            // attributable. spin=ctx+16712 (KfAcquireSpinLock stores the
            // holder's r13; the ISR holds it itself during the flip-done
            // bctrl, and the ISR's fake r13 is 0x8F200000), flips
            // cur/tgt = ctx+16700/16704, flip-done cb = ctx+16544.
            const uint32_t frame = s_frameCounter++;
            auto &memP = mcla::kernel::GuestMemoryHeap::Instance();
            uint32_t isrSpin = 0, flipCur = 0, flipTgt = 0, flipCb = 0;
            if (!memP.ReadU32BE(currentUserData + 16712, &isrSpin))
              isrSpin = 0xDEADBEEF;
            (void)memP.ReadU32BE(currentUserData + 16700, &flipCur);
            (void)memP.ReadU32BE(currentUserData + 16704, &flipTgt);
            (void)memP.ReadU32BE(currentUserData + 16544, &flipCb);
            if (frame < 60 || (frame % 5000) == 0) {
                MCLA_LOG_INFO("VSYNC-ISR enter f={} spin={:08X} flips={}/{} "
                              "cb={:08X}",
                              frame, isrSpin, flipCur, flipTgt, flipCb);
                fn(cbCtx, base);
                MCLA_LOG_INFO("VSYNC-ISR exit f={}", frame);
            } else {
                fn(cbCtx, base);
            }
            // Kernel-role vblank duty (2026-08-24): drain the
            // primary ring up to the driver's current wptr via
            // the existing frozen-capability DrainRing. XTEB+88
            // progress and subctx publication advance ONLY by
            // real consumed dwords (see CpVblankDrainToWptr).
            mcla::gpu::CpVblankDrainToWptr();

            // CLOCK TICK (2026-10-21, fix_typebyte): the guest's clock-tick
            // object (0x40004D7C) is NO LONGER released from this vblank
            // loop.  MEASURED: the vblank cadence is ~16.6 ms (TICK-PROBE
            // #1..#60 in build/w842.log span 12:41:45.292 -> 12:41:46.272,
            // i.e. ~60 Hz) while the guest's own wait asks for a 30 ms
            // deadline (build/w842.log "WAIT[KWFSO] ... obj@40004D7C ...
            // to=30ms"), so EVERY one of the 4809 waits was satisfied by a
            // real signal before the deadline and the guest's own
            // STATUS_TIMEOUT branch at 0x8242FC3C
            // (`cmpli cr6,r3,0102 / beq -> 0x8242FC3C`) could never run
            // (WAKE status histogram {00000000: 4809}; no 00000102 at all).
            //
            // The host has NO CPU clock (audit_irq.md C1): the vblank is a
            // graphics event, not the console's title clock.  The tick now
            // runs on its own host timer with an EXPLICIT, STATED period
            // (kGuestClockTickPeriodMs) LONGER than the guest's own 30 ms
            // deadline, so the deadline is reachable and the guest's
            // watchdog runs - the branch the console takes when its clock is
            // late.  See StartGuestClockTickThread below.
            StartGuestClockTickThread();

            // W36d BOOT-GATE LEVER (2026-09-18) -- RETIRED BY MEASUREMENT
            // (2026-10-21, fix_dpc). The old text here claimed the boot gate
            // "is never called because the game's kernel KeInsertQueueDpc
            // (sub_8242FD00) is invoked via indirect dispatch from unmapped
            // stubs that were never recompiled" and that "the DPC queue at
            // 0x40004D5C stays forever empty". The guest's bytes do not
            // support either claim:
            //   * the guest's 206-entry import table (0x827BD004..0x827BDCD4)
            //     has NO KeInsertQueueDpc import;
            //   * 0x8242FD00 has ZERO direct call sites in the image
            //     (tools/ppc_xrefs.py calls 0x8242FD00) -- it is only passed
            //     as a CALLBACK ADDRESS (0x8241C540, 0x8241CBB0, 0x82430004);
            //   * the queue is NOT at 0x40004D5C: it is the PER-CPU ring at
            //     mem[mem[0x82000864]] + cpu*80 + 0x2C3C (see the GUEST DPC
            //     QUEUE block above);
            //   * the boot gate 0x82131008 appears exactly ONCE in the image
            //     (0x821315F4) where it is stored as a 5-word delegate on an
            //     engine object -- it is NOT enqueued as a DPC.
            // The host did NOT re-add the forced boot-gate dispatch
            // (PROGRAM_GUIDE §7: kF368HostDispatchGate is RETIRED, F-609).
            //
            // What IS the kernel's job, and is now done here: drain the
            // guest's per-CPU DPC list. This thread is the host's IRQL
            // lowering point (the console dispatches DPCs when the IRQL drops
            // below DPC_LEVEL).
            DispatchGuestDpcQueue();
            // Ring-buffer submission probe: sample the head of the
            // primary ring every ~2s (120 frames) to see whether
            // the game ever writes PM4 packets for us to consume.
            if ((frame % 120) == 0) {
              auto &memProbe = mcla::kernel::GuestMemoryHeap::Instance();
              uint32_t ctxPtr = 0;
              if (memProbe.ReadU32BE(0x82839254, &ctxPtr) && ctxPtr != 0) {
                uint32_t p0 = 0, p1 = 0;
                const bool p0Ok = memProbe.ReadU32BE(ctxPtr + 0x30, &p0);
                const bool p1Ok = memProbe.ReadU32BE(ctxPtr + 0x38, &p1);
                uint8_t head[8] = {};
                bool headOk = true;
                for (int bi = 0; bi < 8; ++bi)
                  headOk &= memProbe.ReadU8(
                      0xC6224480 + static_cast<uint32_t>(bi), &head[bi]);
                // Drain-chain truth: published RPTR word (the one
                // sub_82411218 polls) + host CP drain/swap counters.
                uint32_t wbVal = 0;
                const bool wbOk = memProbe.ReadU32BE(0x072344BC, &wbVal);
                if (p0Ok && p1Ok && headOk && wbOk) {
                  MCLA_LOG_INFO(
                      "RING: ctx+30={:08X} ctx+38={:08X} "
                      "head={:02X}{:02X}{:02X}{:02X} {:02X}{:02X}{:02X}{:02X}"
                      " rptrWB={:08X} drains={} swaps={}",
                      p0, p1, head[0], head[1], head[2], head[3], head[4],
                      head[5], head[6], head[7], wbVal,
                      mcla::gpu::CpDrainCount(), mcla::gpu::CpSwapCount());
}
              }
            }
          }
        }
      }
    }).detach();
  }
}

// F-818 (FENCECLEAR): dispatch the registered graphics-interrupt callback the way the console's
// CP does when it drains a PM4_INTERRUPT packet. MEASURED in w806: the guest submits
// `C0005400 mask=00000004` (opcode 0x54, cpu_mask=4 => CPU index 2) once per beat
// (CP-INTERRUPT #1..#8), and registers `callback=0x82411478 user=0x40002080`
// (VdSetGraphicsInterruptCallback row, stored in the two file-scope atomics above). The
// consumer's r3==1 arm (raw bytes 0x82411490-0x824114FC, tools/ppc_disasm.py): loads the
// mailbox base from [ctx+0x2A94], calls the slot-4 callback at [mb+16] with [mb+20], then
// under the spinlock at ctx+0x2A98 (bl 0x827BD504 / 0x827BD544) RMWs [mb+0] clearing bit
// `1 << [r13+268]` -- and [mb+0] IS the poll address of the 10th PM4_WAIT_REG_MEM
// (pollVA=B845D040, ref=0). That clear is the fence the beat has been waiting for; without it
// the wait timed out 144 times and parked ring A (F-813).
// Xenia's reference dispatches per set bit of the packet's mask: command_processor.cc:900-913
// -> DispatchInterruptCallback(1, n) -> graphics_system.cc:241-261 with SetActiveCpu at :253,
// which is exactly the [r13+268] read. Our own vblank thread already calls this same consumer
// with r3=0 and is proven (63/63 clean VSYNC-ISR enter/exit rows); r3=1 fires ONLY from here.
// The r3==0 arm does NOT read [r13+268] (it reads MMIO 0x7FC86544 and branches -- 0x82411508-
// 0x82411528), so touching the PCR byte is invisible to the vblank path. The byte is saved
// and restored around the call so the boot worker's own PCR (tag boot-worker:static-8F200000)
// keeps its processor number.
// Rule-1b taint list: `VdDispatchGraphicsInterrupt` is the ONE new host symbol this change
// adds; it reads the two file-scope registration atomics and is called from gpu_cp.cpp only.
void VdDispatchGraphicsInterrupt(uint32_t cpuMask) {
  static std::atomic<uint32_t> s_dispatched{0};
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  for (uint32_t n = 0; n < 6u; ++n) {
    if (!(cpuMask & (1u << n)))
      continue;
    const uint32_t cb = s_vsyncCallback.load();
    const uint32_t user = s_vsyncUserData.load();
    if (cb == 0)
      continue;
    uint8_t *base = mcla::kernel::g_memory.base;
    PPCFunc *fn = PPC_LOOKUP_FUNC(base, cb);
    if (!fn)
      continue;
    // graphics_system.cc:253 SetActiveCpu -- the consumer reads the CPU index as a BYTE at
    // [r13+268] (`lbz r11,268(r13)` @0x824114D4). Save, set, call, restore.
    // The byte now lives in THIS host thread's own PCR block, so the boot
    // worker's PCR is no longer written at all (it used to be, which is why
    // the old code had to save and restore it).
    const uint32_t kPcrCpuByte = IsrThreadBlockVa() + 268u;
    uint8_t oldCpu = 0;
    (void)mem.ReadU8(kPcrCpuByte, &oldCpu);
    (void)mem.WriteU8(kPcrCpuByte, static_cast<uint8_t>(n));
    PPCContext ctx{};
    ctx.r3.u32 = 1;             // interrupt type 1 = PM4_INTERRUPT (command_processor.cc:900-913)
    ctx.r4.u32 = user;           // GPU context pointer, same as the vblank path
    ctx.r5.u32 = 0;
    ctx.r13.u32 = IsrThreadBlockVa(); // THIS host thread's block, same as the vblank path
    ctx.r1.u32 = 0x8F000000u;    // stack top, same as the vblank path
    ctx.lr = 0x00FFFFFFu;       // dummy LR, same as the vblank path
    ctx.msr = 0x200A000;
    SetPPCContext(ctx);
    const uint32_t dn = s_dispatched.fetch_add(1) + 1;
    MCLA_LOG_WARN("CP-INTERRUPT-DISPATCH #{} cpu={} cb={:08X} user={:08X} pcrOld={}",
                  dn, n, cb, user, static_cast<unsigned>(oldCpu));
    fn(ctx, base);
    (void)mem.WriteU8(kPcrCpuByte, oldCpu);
    MCLA_LOG_WARN("CP-INTERRUPT-DISPATCH-POST #{} r3={:08X}", dn, ctx.r3.u32);
  }
}

// Signal the guest's clock-tick object (0x40004D7C) so that the guest's
// clock handler (0x8242FB88 - the title's "GPU poller"; the guest's own
// message registry pairs it with message id 0x40005E03) can leave its wait.
//
// CONSOLE-CORRECT CLASS (2026-10-21, fix_typebyte).  The guest's own bytes
// say this object is an EVENT, not a semaphore:
//   * the guest-visible Type byte at 0x40004D7C is 0x00 = EventNotification
//     (manual reset): build/w842.log
//     "TYPE-CENSUS[KWFSO] #0001 objptr=40004D7C type=00 timeout_ms=30";
//   * the guest RESETS it: 0x8242FCD4 `addi r3,r26,32` (r26+32 ==
//     0x40004D7C) / 0x8242FCD8 `bl 0x827BD874` = __imp__KeResetEvent;
//   * console event classes are 0x00 (manual) / 0x01 (auto) and a semaphore
//     is 0x05 (.research/xenia/src/xenia/kernel/xevent.cc:39-58; audit C6 in
//     build/agents/audit_irq.md).
// The old code resolved the object as a SEMAPHORE, so the guest's
// KeResetEvent could not find the wrapper that had been released and minted
// a second, unregistered view instead: 29 KOBJ-CLASSFLIP rows in
// build/w842.log, and the guest's reset was LOST - the signal state was
// never cleared, so every one of the 4809 WAKE[KWFSO] rows returned
// STATUS_SUCCESS (status histogram {00000000: 4809}) and the guest's own
// STATUS_TIMEOUT branch at 0x8242FC3C could not run.
//
// FALSIFIER: KOBJ-CLASSFLIP must go 29 -> 0 in the next soak.
static void SignalSchedulerTick() {
  constexpr uint32_t kSchedulerTickSem = 0x40004D7C;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  // FAILURE-PATH PROBE (session 64): ISR ran 2261 times but the waiter woke
  // only every ~7.5s — attribute which guard bounces the tick signal.
  static std::atomic<uint32_t> s_tickProbes{0};
  const uint32_t probeN = s_tickProbes.fetch_add(1) + 1;
  auto logPath = [&](const char *path) {
    if (probeN <= 60 || (probeN % 5000) == 0)
      MCLA_LOG_INFO("TICK-PROBE #{} path={}", probeN, path);
  };

  if (!mem.IsValid(kSchedulerTickSem, 4)) {
    logPath("invalid");
    return;
  }

  auto *header = reinterpret_cast<XDISPATCHER_HEADER *>(
      static_cast<uint8_t *>(mem.Translate(kSchedulerTickSem)));
  if (!header) {
    return;
  }

  // Resolve the CANONICAL wrapper for this dispatcher address.  If there is
  // none yet, create the one the console would have: an EVENT, because the
  // object's own guest-visible Type byte says 0x00 (EventNotification).
  KernelObject *canonical = LookupKernelObjectByDispatcher(*header);
  Event *ev = canonical ? dynamic_cast<Event *>(canonical) : nullptr;
  if (!ev && !canonical) {
    ev = QueryKernelObject<Event>(*header);
  }
  if (ev) {
    logPath("set-event");
    ev->Set();
    return;
  }
  // A canonical wrapper of another class exists (the legacy semaphore model):
  // release it rather than type-confusing it.
  if (canonical) {
    if (auto *sem = dynamic_cast<Semaphore *>(canonical)) {
      logPath("release-semaphore");
      sem->Release(1, nullptr);
      return;
    }
  }
  logPath("no-object");
}

uint32_t VdInitializeEngines(uint32_t unk, uint32_t cb, uint32_t arg,
                             uint32_t pfp, uint32_t me) {
  MCLA_LOG_INFO("VdInitializeEngines: unk=0x{:08X} cb=0x{:08X} arg=0x{:08X} "
                "pfp=0x{:08X} me=0x{:08X}",
                unk, cb, arg, pfp, me);

  // Xenia: r3=0x4E810000, returns 2. Must fully init GPU context:
  // spinlocks at +0x4148, +0x4158, cmd buffer at +0x30/+0x38, present callback
  // at +0x40A0 The GPU context is allocated by the game. We initialize the
  // structure at the address the game provides (typically via a global
  // pointer).

  // The game stores the GPU context pointer at a known global address.
  // Based on Xenia and MCLA analysis, the GPU context pointer is at 0x82839254.
  constexpr uint32_t gpuCtxPtrAddr = 0x82839254;
  uint32_t gpuCtxPtr = 0;
  (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(gpuCtxPtrAddr,
                                                            &gpuCtxPtr);

  if (gpuCtxPtr != 0 && gpuCtxPtr < 0x90000000) {
    // Spinlocks at +0x4148 and +0x4158: UNLOCKED STATE IS 0, not 1.
    // (Session 64 root cause: seeding 1 planted a phantom permanent holder
    // for KfAcquireSpinLock (0=unlocked protocol) — the vblank ISR
    // (sub_82419718, lock at gpuCtx+16712=0x4148) then spun forever
    // (38M+ yields observed), wedging the vsync thread so
    // SignalSchedulerTick never fired and the driver worker parked on its
    // tick semaphore 0x40004D7C. The old "TU83 expects non-zero" heuristic
    // predated the discovery that the vblank path acquires this word.)
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(
        gpuCtxPtr + 0x4148, 0);
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(
        gpuCtxPtr + 0x4158, 0);

    // Initialize command buffer pointers at +0x30 and +0x38
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x30,
                                                               0);
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x38,
                                                               0);

    // Present callback at +0x40A0 - will be set by
    // VdSetGraphicsInterruptCallback chain The game sets this up; we don't
    // manually seed it here.
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(
        gpuCtxPtr + 0x40A0, 0);
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(
        gpuCtxPtr + 0x40A4, 0);

    // State field at +0xD0 (checked by Function_824E37E0)
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0xD0,
                                                               1);

    MCLA_LOG_INFO("VdInitializeEngines: initialized GPU context at 0x{:08X}",
                  gpuCtxPtr);
  } else {
    MCLA_LOG_WARN(
        "VdInitializeEngines: GPU context pointer not set at 0x82839254");
  }

  return 2;
}

// Manual GPU backend initialization - replicates ReinitGpuBackend logic
// Call this after boot to trigger graphics initialization
void InitGpuBackendManual(uint32_t gpuCtxPtr) {
  MCLA_LOG_INFO("InitGpuBackendManual: Starting manual GPU backend "
                "initialization for GPU context 0x{:08X}",
                gpuCtxPtr);

  // Call VdInitializeEngines with same args as ReinitGpuBackend
  // r3=0x1B530000, r4=0x82425D78, r5=0, r6=0x82066110, r7=0x82066590
  VdInitializeEngines(0x1B530000, 0x82425D78, 0, 0x82066110, 0x82066590);

  // Call VdSetGraphicsInterruptCallback with VSync callback 0x82411478 and
  // userData = GPU context
  VdSetGraphicsInterruptCallback(0x82411478, gpuCtxPtr);

  // RING INIT REMOVED (2026-08-25). This shim used to call
  // VdInitializeRingBuffer + VdEnableRingBufferRPtrWriteBack for
  // [gpuCtx+14836] and for sub_ctx+60. Log forensics (mcla.log 00:51:22-23)
  // prove the GUEST already performs the genuine pair ~670ms earlier via
  // generated ppc_recomp.77.cpp:23344-23377:
  //   init(MmGetPhysicalAddress(ring), 12); enableWB(phys(subctx+60), 6).
  // The injected calls then: (a) re-inited the LIVE ring and reset its rptr
  // mid-flight, (b) repointed the writeback INTO the ring body so
  // PublishRptr wrote into live ring memory, and (c) fabricated a phantom
  // "4MB ring" on top of the driver sub-context (zero-filling 4MB of heap
  // starting at the rptr write-back mirror subctx+60), which hijacked all
  // later doorbells and starved E98/F98. Per-ring CP state now lives in
  // gpu_cp.cpp; only genuine guest registrations create rings.
  MCLA_LOG_INFO("InitGpuBackendManual: GPU backend initialization complete");
}

// Background poller for GPU context allocation
static std::atomic<bool> s_gpuInitDone{false};
static std::atomic<bool> s_gpuPollerRunning{false};

void StartGpuContextPoller() {
  if (s_gpuPollerRunning.exchange(true))
    return;

  std::thread([]() {
    MCLA_LOG_INFO(
        "GpuContextPoller: Started polling for GPU context at 0x82839254");
    while (!s_gpuInitDone.load()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));

      constexpr uint32_t gpuCtxPtrAddr = 0x82839254;
      uint32_t gpuCtxPtr = 0;
      (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(gpuCtxPtrAddr,
                                                                &gpuCtxPtr);

      if (gpuCtxPtr != 0 && gpuCtxPtr < 0x90000000 && !s_gpuInitDone.load()) {
        MCLA_LOG_INFO("GpuContextPoller: GPU context allocated at 0x{:08X}, "
                      "initializing...",
                      gpuCtxPtr);
        if (!s_gpuInitDone.exchange(true)) {
          InitGpuBackendManual(gpuCtxPtr);
        }
        break;
      }
    }
    MCLA_LOG_INFO("GpuContextPoller: Stopped");
  }).detach();
}

void VdQueryVideoFlags(uint32_t *flags) {
  // Xenia: widescreen?1 | width>=1280?2 | width>=1920?4
  // 1280x720: widescreen=1, width>=1280=1 -> 1|2 = 3
  if (flags) {
    *flags = 3;
  }
  MCLA_LOG_INFO("VdQueryVideoFlags: returning 3 (widescreen|width>=1280)");
}

void VdCallGraphicsNotificationRoutines() { LOG_UTILITY("!!! STUB !!!"); }

void VdInitializeScalerCommandBuffer() { LOG_UTILITY("!!! STUB !!!"); }

void KeLeaveCriticalRegion() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t VdRetrainEDRAM() { return 0; }

void VdRetrainEDRAMWorker() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t VdIsHSIOTrainingSucceeded() {
  // Return 1 (succeeded) to allow boot to continue
  return 1;
}

void VdGetCurrentDisplayGamma() { LOG_UTILITY("!!! STUB !!!"); }

void KeEnterCriticalRegion() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t MmAllocatePhysicalMemoryEx(uint32_t flags, uint32_t size,
                                    uint32_t protect, uint32_t minAddress,
                                    uint32_t maxAddress, uint32_t alignment) {
  // F-810: the counter for the ungated big-request row below. Declared here, beside the only
  // function that uses it, so no new host symbol leaks into another TU (rule 1b).
  static std::atomic<uint32_t> s_mmPhysBig{0};
  LOGF_UTILITY("0x{:x}, 0x{:x}, 0x{:x}, 0x{:x}, 0x{:x}, 0x{:x}", flags, size,
               protect, minAddress, maxAddress, alignment);
  // F-810: LOGF_UTILITY above is `#if _DEBUG` -> EMPTY in a release build
  // (.research/UnleashedRecomp/UnleashedRecomp/os/logger.h:24-28, NDEBUG set by
  // CMakeLists.txt:578), so the argument tuple of the physical allocator has NEVER been logged.
  // heap.cpp:2364 cites that row as "the only place" the tuple is recorded -- that citation is
  // false. This is the real one. UNGATED (no `n % k`): a gated printer yields a cadence, not a
  // total, and this row exists to settle WHICH site asks for a 299.5 MiB block.
  // `[0x827D4304]` is dumped because it is the one runtime global any candidate site reads: its
  // single writer in the whole image is `0x82131534 stw r11,17156(r10)` with `lis r11,0040`
  // @`0x82131530` (a CONSTANT 64 MiB, gated on `[0x828309C0] != 0`), so it can only ever be
  // 0x10000 (the image word) or 0x400000. NOTE: `tools\ppc_xrefs.py xref 0x827D4304` filed that
  // stw as a READER -- ppc_xrefs models no stw/stwu displacement, which is what produced a
  // confident "no writer in the image" and sent this search after a host writer that cannot exist.
  if (size >= 0x10000000u) {
    const PPCContext* const pc = GetPPCContext();
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t w4304 = 0, w4308 = 0;
    (void)mem.ReadU32BE(0x827D4304u, &w4304);
    (void)mem.ReadU32BE(0x827D4308u, &w4308);
    MCLA_LOG_WARN(
        "MMAL-PHYS-BIG #{} size={:#x} flags={:#x} protect={:#x} min={:08X} max={:08X} "
        "align={:#x} glr={:08X} [0x827D4304]={:08X} [0x827D4308]={:08X} "
        "(glr-4 is a site id: 821BC114=A 821BC118=A2 82131CC8=B 8217B16C=C)",
        s_mmPhysBig.fetch_add(1) + 1, size, flags, protect, minAddress, maxAddress, alignment,
        pc ? static_cast<uint32_t>(pc->lr) : 0u, w4304, w4308);
  }
  void *ptr = g_userHeap.AllocPhysical(size, alignment);
  if (!ptr) {
    static std::atomic<uint32_t> s_allocFails{0};
    if (s_allocFails.fetch_add(1) < 50) {
      // Session 73: full arena diagnostics on failure — distinguishes a
      // genuine OOM (peak ~ capacity) from a leak (allocated >> freed).
      // F-806b: this is THE reader that trips F-388. `AllocPhysical` has already returned and
      // closed its own window by the time we get here (`t_hgWin == 0` on this thread), and
      // `o1heapGetDiagnostics` reads the instance -- `capacity` at instance+0x208, the field
      // boot_host.cpp:474-475 names. Since F-806 the guard watches the REAL header, so this is a
      // genuine out-of-window access. MEASURED: `F388-PHYSGUARD trip=3/5 off=0X208 want=R
      // hostRVA=0x2e4dd3` = `o1heapGetDiagnostics+0x3`, landing on the same millisecond as
      // `FAILED count=1` and `count=2` in both w801 and w802, at a 4.011 s cadence, 50 rows.
      // `HeapGuardArm`/`Disarm` are already declared at boot_host.h:101-102 and imports.cpp:27
      // already includes that header -- no new include, no new symbol.
      mcla::boot::HeapGuardDisarm();
      const auto d = o1heapGetDiagnostics(g_userHeap.physicalHeap);
      MCLA_LOG_WARN(
          "MmAllocatePhysicalMemoryEx: FAILED size={:#x} align={:#x} "
          "(count={}) cap={} allocated={} peak={} oomCount={} lr={:08X}",
          size, alignment, s_allocFails.load(), d.capacity, d.allocated,
          d.peak_allocated, d.oom_count,
          GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0);
      mcla::boot::HeapGuardArm();
    }
    return 0;
  }
  {
    // Session 73: cumulative physical usage census — find what fills the
    // 1.6GB arena during load.
    static std::atomic<uint64_t> s_totalBytes{0};
    static std::atomic<uint32_t> s_totalAllocs{0};
    const uint64_t bytes =
        s_totalBytes.fetch_add(size + 0x420, std::memory_order_relaxed) +
        size + 0x420; // + o1heap header + alignment head-room approximation
    const uint32_t allocs = s_totalAllocs.fetch_add(1) + 1;
    if (allocs <= 32 || (allocs % 2000) == 0 || bytes > (200ull << 20))
      MCLA_LOG_WARN("PHYS-CENSUS #{} size={:#x} total={:.1f}MB lr={:08X}",
                    allocs, size,
                    static_cast<double>(bytes) / (1024.0 * 1024.0),
                    GetPPCContext()
                        ? static_cast<uint32_t>(GetPPCContext()->lr)
                        : 0);
    if (bytes > (200ull << 20))
      s_totalBytes.store(0, std::memory_order_relaxed); // re-arm bucket log
  }
  uint32_t guestAddr =
      mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(ptr);
  // Session-27 window census: catch the allocation feeding the
  // deterministic unconstructed swf object at 0x88825500.
  if ((guestAddr & 0xFFFF0000u) == 0x88820000u) {
    uint32_t lr = 0;
    if (const PPCContext *c = GetPPCContext())
      lr = static_cast<uint32_t>(c->lr);
    MCLA_LOG_WARN("ALLOC-WIN MmPhys -> {:08X} size={:#x} align={:#x} "
                  "flags={:08X} lr={:08X}",
                  guestAddr, size, alignment, flags, lr);
  }
  MmTrackAllocationSize(guestAddr, size);
  return guestAddr;
}

// MmGetPhysicalAddress(BaseAddress) -> PHYSICAL_ADDRESS.
//
// WHAT "REAL" MEANS HERE. The Xbox 360 runs with TBR (translation block base)
// semantics for MmAllocatePhysicalMemory results: the kernel hands back a
// virtual address that IS the physical address, and MmGetPhysicalAddress of
// such an address is the identity. There is no page table to walk.
//
// Our model matches that for the one address class it actually hands out:
// MmAllocatePhysicalMemoryEx (imports.cpp above) allocates from the o1heap
// physical arena, which is bound into the flat guest window
// (src/kernel/heap.cpp:232-234, physArenaBase = Translate(kPhysArenaBeginVa)),
// and records every allocation in the size/LR registry via MmTrackAllocation.
// So for a REGISTERED physical allocation the correct answer is the address
// itself, and the registry is what makes that a verified fact rather than a
// guess.
//
// F-609: this used to be `return address;` for every input - the 1.6 GiB title
// heap, the 4 GiB window, 0 and 0xFFFFFFFF all "translated". An address that
// was never a physical allocation now fails the way the reference does
// (Xenia .research/xenia/.../xboxkrnl_memory.cc:554-565: no heap -> 0).
uint32_t MmGetPhysicalAddress(uint32_t address) {
  if (address == 0)
    return 0;

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!mem.Translate(address)) {
    MCLA_LOG_WARN("MmGetPhysicalAddress: {:08X} is outside the 4 GiB guest "
                  "window -> 0 lr={:08X}",
                  address,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return 0;
  }

  uint32_t allocBase = 0, allocSize = 0, allocLr = 0;
  bool exact = false;
  if (mcla::kernel::MclaPhysAllocInfo(address, &allocBase, &allocSize, &allocLr,
                                      &exact) &&
      exact) {
    return address;
  }

  // Not a physical allocation we ever handed out. We have no page table, so we
  // genuinely do not know what physical page backs it - say 0 and be loud,
  // rather than echoing an address we cannot justify.
  static std::atomic<uint32_t> s_noPa{0};
  const uint32_t n = s_noPa.fetch_add(1) + 1;
  if (n <= 20 || (n % 500) == 0) {
    uint32_t nearBase = 0, nearSize = 0;
    const bool haveNear =
        mcla::kernel::MclaPhysNearestAllocBelow(address, &nearBase, &nearSize);
    MCLA_LOG_WARN("MmGetPhysicalAddress: {:08X} is not a tracked physical "
                  "allocation -> 0 #{} [nearest below {:08X}+{:X} found={} "
                  "allocLr={:08X}] lr={:08X}",
                  address, n, nearBase, nearSize, haveNear ? 1 : 0, allocLr,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    (void)allocBase;
    (void)allocSize;
  }
  return 0;
}

void ObDeleteSymbolicLink() { LOG_UTILITY("!!! STUB !!!"); }

void ObCreateSymbolicLink() { LOG_UTILITY("!!! STUB !!!"); }

// MmQueryAddressProtect(BaseAddress) -> XDK protect flags.
//
// Xenia reference .research/xenia/.../xboxkrnl_memory.cc:413-422: look the
// address up in the heap, QueryProtect; no heap found -> 0. Our model has no
// page table, so the answer is derived from the two pieces of REAL protection
// state that do exist:
//
//   * the deliberate PAGE_NOACCESS null guard page - the first 4 KiB of the
//     guest window is VirtualProtect'ed to NOACCESS at src/kernel/memory.cpp:
//     218 (and :251 on the Adopt path), and IsValid rejects < 0x1000;
//   * the guest-virtual allocation state tracked by NtAllocateVirtualMemory /
//     NtFreeVirtualMemory (GuestMemoryHeap::QueryVirtualRegion) - a reserved
//     but uncommitted region is genuinely not accessible yet.
//
// F-609: this returned PAGE_READWRITE for every address, so a call on a
// reserved region or on the null guard page told the guest "you may write
// here" for memory it must not touch.
uint32_t MmQueryAddressProtect(uint32_t guestAddress) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  // The null guard page: real NOACCESS, not a bookkeeping state.
  if (guestAddress < 4096u) {
    return kXPageNoAccess;
  }

  if (!mem.Translate(guestAddress)) {
    static std::atomic<uint32_t> s_unmapped{0};
    const uint32_t n = s_unmapped.fetch_add(1) + 1;
    if (n <= 20 || (n % 500) == 0)
      MCLA_LOG_WARN("MmQueryAddressProtect: {:08X} is outside the guest window "
                    "-> 0 #{} lr={:08X}",
                    guestAddress, n,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    return 0; // no heap: matches the reference's "no mapping" answer
  }

  VirtualRegionInfo info;
  if (mem.QueryVirtualRegion(guestAddress, &info)) {
    if (!info.committed) {
      // Reserved or FREE in the tracked window: not backed yet. This is the
      // case the unconditional PAGE_READWRITE was actively wrong about.
      return kXPageNoAccess;
    }
    return kXPageReadWrite;
  }

  // Mapped, but outside the region tracker (title heap at 0x20000, the physical
  // arena above kPhysArenaBeginVa, the loaded XEX, the flat window generally).
  // The model really does hand these out read/write, so PAGE_READWRITE is the
  // true answer - but count them, because this is the half of the address space
  // whose protection state is asserted by the flat mapping rather than tracked.
  static std::atomic<uint32_t> s_flat{0};
  const uint32_t n = s_flat.fetch_add(1) + 1;
  if (n <= 20 || (n % 500) == 0)
    MCLA_LOG_INFO("MmQueryAddressProtect #{} {:08X} -> PAGE_READWRITE from the "
                  "flat window (untracked region) lr={:08X}",
                  n, guestAddress,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
  return kXPageReadWrite;
}

void VdEnableDisableClockGating() { LOG_UTILITY("!!! STUB !!!"); }

void KeBugCheck() { __builtin_debugtrap(); }

void KeLockL2() { LOG_UTILITY("!!! STUB !!!"); }

void KeUnlockL2() { LOG_UTILITY("!!! STUB !!!"); }

// IDENTITY-FIRST RESOLUTION (session 16 audit, systemic fix): kernel-created
// wrappers can have their guest dispatcher-header signature WIPED by the
// game's own driver (it owns these structs and re-inits them post-create),
// after which QueryKernelObject's lazy-wrap builds PHANTOM wrappers over raw
// bytes - the wake-loss bug class proven on NtReleaseSemaphore. Resolve by
// pure identity translation (same as the wait path) whenever the addressed
// memory still hosts a valid wrapper; fall back to lazy-wrap only for
// genuinely embedded/never-created objects.
template <typename T>
static T *ResolveCreatedObject(void *guestPtr, size_t guestSize) {
  const uint32_t guestAddr =
      static_cast<uint32_t>(reinterpret_cast<const uint8_t *>(guestPtr) -
                            mcla::kernel::g_memory.base);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (mem.IsValid(guestAddr, guestSize)) {
    auto *direct = reinterpret_cast<T *>(mem.Translate(guestAddr));
    if (direct->IsValid()) {
      return direct;
    }
  }
  return nullptr;
}

bool KeSetEvent(XKEVENT *pEvent, uint32_t Increment, bool Wait) {
  // SIGNAL CENSUS (2026-08-23 session 9): who signals what. Caller LR
  // attributes the producer site statically afterwards.
  {
    static std::atomic<uint32_t> s_signalLogs{0};
    const uint32_t n = s_signalLogs.fetch_add(1) + 1;
    if (n <= 40 || (n % 2000) == 0) {
      MCLA_LOG_INFO("SIGNAL KeSetEvent obj={:08X} inc={} wait={} lr={:08X}",
                    static_cast<uint32_t>(reinterpret_cast<uintptr_t>(pEvent)),
                    Increment, Wait ? 1 : 0,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  bool result = QueryKernelObject<Event>(*pEvent)->Set();

  ++g_keSetEventGeneration;
  g_keSetEventGeneration.notify_all();

  return result;
}

bool KeResetEvent(XKEVENT *pEvent) {
  return QueryKernelObject<Event>(*pEvent)->Reset();
}

uint32_t KeWaitForSingleObject(XDISPATCHER_HEADER *Object, uint32_t WaitReason,
                               uint32_t WaitMode, bool Alertable,
                               be<int64_t> *Timeout) {
  // PRODUCER-DEATH CENSUS (2026-08-25): all-thread wait/return telemetry.
  // Always logs waits whose caller sits in the GPU-driver range (the
  // producers); other callers are sampled. LOG-ONLY.
  {
    static std::atomic<uint32_t> s_wcKwfs{0};
    const uint32_t n = s_wcKwfs.fetch_add(1) + 1;
    const uint32_t lr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0;
    const bool hot = lr >= 0x82410000u && lr < 0x82430000u;
    if (hot || n <= 120 || (n % 300) == 0) {
      uint32_t r13 = g_ppcContext ? g_ppcContext->r13.u32 : 0;
      uint32_t objAddr =
          mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(Object);
      uint32_t pc = 0, pcBlk = 0, put = 0, rptrWb = 0, gpuCtx = 0;
      auto &memC = mcla::kernel::GuestMemoryHeap::Instance();
      if (r13 != 0) {
        if (memC.ReadU32BE(r13 + 256, &pcBlk) && pcBlk != 0)
          (void)memC.ReadU32BE(pcBlk + 88, &pc);
      }
      (void)memC.ReadU32BE(0x82839254u, &gpuCtx);
      if (gpuCtx != 0)
        (void)memC.ReadU32BE(gpuCtx + 10908u, &put);
      // T40.4 (F-057(1)): read the word the CP ACTUALLY publishes. The two
      // hard-coded addresses here were both wrong — 0xC71D81BC is 4 bytes left
      // of the real target and 0xC701C4BC is unrelated — so this line reported
      // "rptrWB=0000" (read as "no consumer") for many soaks while the ring
      // drained normally. CpPrimaryWritebackVA() is the CP's own publish target.
      rptrWb = 0;
      const uint32_t wbVA = mcla::gpu::CpPrimaryWritebackVA();
      if (wbVA != 0)
        (void)memC.ReadU32BE(wbVA, &rptrWb);
      // F-594: the hot `lr` 0x8242FC1C is the return of this KeWait AND the
      // branch target of the `lwarx`/`stwcx.` CAS retry loop that follows it
      // (ppc_recomp.78.cpp:27220-27238). PPCContext has NO r31 member in this
      // build (PPC_CONFIG_NON_VOLATILE_AS_LOCAL, ppc_config.h:10 — the
      // volatile regs are function-local in the generated TUs, so a hook
      // cannot read the callee's r31). Name what IS observable: the thread
      // block the reservation almost certainly lives in. r13+256 is the block
      // pointer already used for `pc` above; r13 itself is the context base.
      {
        uint32_t blk = 0, f0 = 0, f4 = 0, f8 = 0, f12 = 0, f16 = 0;
        const uint32_t c13 = g_ppcContext->r13.u32;
        (void)memC.ReadU32BE(c13 + 256u, &blk);
        (void)memC.ReadU32BE(c13 + 0u, &f0);
        (void)memC.ReadU32BE(c13 + 4u, &f4);
        (void)memC.ReadU32BE(c13 + 8u, &f8);
        (void)memC.ReadU32BE(c13 + 12u, &f12);
        (void)memC.ReadU32BE(c13 + 16u, &f16);
        MCLA_LOG_WARN("CAS-SITE #{} lr={:08X} r13={:08X} blk@+100={:08X} "
                      "f0..f3={:08X}/{:08X}/{:08X}/{:08X} tid={:08X} "
                      "obj={:08X} mode={} alertable={}",
                      n, static_cast<uint32_t>(g_ppcContext->lr), c13, blk, f0,
                      f4, f8, f12, GetCurrentThreadId(), objAddr, WaitMode,
                      Alertable ? 1 : 0);
      }
      MCLA_LOG_INFO("WAIT[KWFSO] #{:05}{} tid={:08X} obj@{:08X} reason={} "
                    "to={}ms lr={:08X} put={} rptrWB={:04X} "
                    "wb@{:08X}={:08X} pc={:08X}:{}",
                    n, hot ? "!" : " ", GetCurrentThreadId(), objAddr,
                    WaitReason, GuestTimeoutToMilliseconds(Timeout), lr, put,
                    rptrWb & 0xFFFF, wbVA, rptrWb, pcBlk, pc);
    }
  }
  // MAIN-THREAD PARK PROBE
  {
    static std::atomic<uint32_t> s_parkLogs3{0};
    // T43.17 (2026-10-13): passes counts EVERY pass through this probe
    // (any thread); printed rows cap at 200, so the row count is a lower
    // bound and passes= is the denominator showing cap coverage. A main-
    // thread park count is <= passes, never more.
    static std::atomic<uint64_t> s_parkPasses3{0};
    const uint64_t t = s_parkPasses3.fetch_add(1, std::memory_order_relaxed) + 1;
    uint32_t mainId = g_mainGuestThreadId.load();
    // T43.18 (2026-10-13): same publication as the NTW probe above. Handle
    // here is the MapVirtual'd guest VA (this path has Object*, not a
    // guest handle); 0 = unmapped at park time.
    if (mainId != 0 && GetCurrentThreadId() == mainId) {
      g_mainParkHandle.store(
          mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(Object),
          std::memory_order_relaxed);
      g_mainParkLr.store(g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u,
                         std::memory_order_relaxed);
      g_mainParkNs.store(static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::steady_clock::now().time_since_epoch()).count()),
                         std::memory_order_relaxed);
    }
    if (mainId != 0 && GetCurrentThreadId() == mainId &&
        s_parkLogs3.fetch_add(1) < 200) {
      MCLA_LOG_INFO(
          "[main-park] KeWaitForSingleObject objptr={:08X} reason={} lr={:08X} passes={}",
          static_cast<uint32_t>(reinterpret_cast<uintptr_t>(Object)),
          WaitReason,
          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0), t);
    }
  }
  const uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);

  // ALERTABLE WAIT (2026-10-21, fix_irq2, item 2).
  //
  // CONSOLE: an ALERTABLE wait is woken by a pending APC, the APC RUNS, and
  // the wait returns STATUS_USER_APC (xobject.cc:207-215: the wait result
  // kUserCallback maps to X_STATUS_USER_APC; and the APCs are delivered at
  // the IRQL-lowering boundary, xboxkrnl_threading.cc:1005-1010).
  //
  // WHERE THE GUEST'S FLAG IS -- MEASURED, and the host was reading the
  // WRONG REGISTER.  All 11 __imp__KeWaitForSingleObject call sites pass
  //   r3 = object, r4 = 3 (or 0), r5 = 1 (or 0), r6 = 0, r7 = timeout
  // (`py -3 tools/ppc_xrefs.py calls 0x827BD5A4`; the ten (3,1,0) sites are
  // 0x823EC91C, 0x823EC9DC, 0x823ECA0C, 0x8242FC18, 0x8242FCAC, 0x8244E3FC,
  // 0x8244E4FC, 0x8244E648, 0x8244EB58, 0x82459D64 and the one (0,0,0) site
  // is 0x8245AB90).  The host's signature read ALERTABLE out of r6 -- the
  // slot that is 0 at EVERY one of the 11 sites -- so the guest's alertable
  // flag was DISCARDED and every Ke-form wait was non-alertable.
  // The 10 __imp__NtWaitForSingleObjectEx sites use the SAME slot for the
  // flag (r5), which the 4-argument Nt form puts in r5 (the reference:
  // NtWaitForSingleObjectEx_entry(handle, wait_mode, alertable, timeout),
  // xboxkrnl_threading.cc:808-811), and one of them computes it
  // (0x82135DF4: `mr r5,r29` where r29 = r28 & 0xFF).  So r5 is the
  // guest's alertable slot in BOTH forms.
  //
  // The two candidate ABIs disagree about the Ke form's 5th argument (the
  // 360's layout puts a Context there, the reference's layout puts
  // "processor_mode" there and Alertable in r6), and the guest's bytes CANNOT
  // discriminate, because r6 is 0 everywhere.  So both slots are honoured.
  // That is safe under either reading because the host's APC queue is EMPTY
  // today -- the guest has no APC-queueing import (see QueueGuestApc) -- so
  // the only observable difference is this census row.
  const bool alertable = Alertable || (WaitMode != 0);
  if (alertable) {
    static std::atomic<uint32_t> s_alertableKwfso{0};
    const uint32_t an = s_alertableKwfso.fetch_add(1) + 1;
    if (an <= 40 || (an % 500) == 0)
      MCLA_LOG_INFO("WAIT-ALERTABLE-KWFSO #{} alertable=1 obj={:08X} to={}ms "
                    "lr={:08X} (r5={} r6={}; the host used to read r6 only)",
                    an, mcla::kernel::g_memory.MapVirtual(Object), timeout,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                    WaitMode, Alertable ? 1 : 0);
  }
  if (alertable && HasPendingApc()) {
    const uint32_t delivered = DeliverPendingApcs();
    MCLA_LOG_WARN("APC-WAKE #{} delivered={} obj={:08X} -> STATUS_USER_APC "
                  "(the console returns X_STATUS_USER_APC after the APC ran)",
                  static_cast<uint32_t>(GetCurrentThreadId()), delivered,
                  mcla::kernel::g_memory.MapVirtual(Object));
    return STATUS_USER_APC;
  }

  // DWELL HISTOGRAM + TYPE CENSUS: measure actual wait dwell time vs timeout class + resolution
  const auto waitStart = std::chrono::steady_clock::now();
  const char* waitResolution = "unknown";

  // DISABLED per bisect Run A: DWELL histogram probe
  // auto LogDwellHistogram = [&](uint32_t status) { ... };
  auto LogDwellHistogram = [&](uint32_t status) { (void)status; (void)waitStart; (void)waitResolution; };

  uint8_t type = Object->Type;

  // TYPE CENSUS (type only, at entry)
  {
    static std::atomic<uint32_t> s_typeLogs{0};
    const uint32_t n = s_typeLogs.fetch_add(1) + 1;
    if (n <= 60 || (n % 5000) == 0) {
      // T43.17 (2026-10-13): timeout prints DECIMAL ms, matching WAIT's
      // `to=` (both are GuestTimeoutToMilliseconds; the old {:08X} read
      // 0000001E for the same 30 WAIT prints decimal). objptr is the
      // truncated HOST pointer, NOT the guest VA -- WAIT/CAS print the
      // MapVirtual'd guest address under `obj@`; the two fields share no
      // domain despite the old shared name.
      MCLA_LOG_INFO("TYPE-CENSUS[KWFSO] #{:04} objptr={:08X} type={:02X} timeout_ms={} lr={:08X}",
                    n,
                    static_cast<uint32_t>(reinterpret_cast<uintptr_t>(Object)),
                    type, timeout,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  // Return the real wait result. Previously this hooked call returned
  // STATUS_SUCCESS unconditionally, which starved guest workers that branch
  // on STATUS_TIMEOUT (e.g. driver worker sub_8242FB88 checking r3==0x102 to
  // run its periodic GPU drain/maintenance — see session 61-62 handoff).
  uint32_t waitStatus = STATUS_TIMEOUT;

  // 2026-10-21 (fix_dpc): IDENTITY-FIRST. Resolve the CANONICAL wrapper for
  // this dispatcher address before the type switch. The guest-visible Type
  // byte must not decide WHICH object is waited on: it is guest-writable,
  // and for a host-created object the bytes at the handle are the C++ vptr,
  // so `Object->Type` reads 0x28 (the vptr's low byte) while the host wrote
  // Type=5 at obj+8 (audit C15: 61/61 host-created semaphores). The byte
  // still selects the WAIT BEHAVIOUR (auto vs manual reset) inside
  // Event/Semaphore; it no longer selects the OBJECT.
  bool resolvedByIdentity = false;
  // F-852 (fix_sema): the Ke-form wait gets the same LIVE-count census as
  // the Nt-form wait, so a wait that blocks on a semaphore is visible as
  // (cnt=0, waiters>0) and the release that should wake it is visible as
  // (waiters>0).  The handle printed here is the DISPATCHER ADDRESS, which
  // for a host-created object IS the guest handle (GetKernelHandle ->
  // MapVirtual(&obj->header)), so the two forms are comparable.
  const uint32_t keCntHandle =
      mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(Object);
  auto keCntWait = [&](KernelObject *o, const char *tag) {
    uint32_t c = 0, mx = 0, w = 0;
    SemCntSnapshot(o, &c, &mx, &w);
    if (c == 0)
      g_semCntBlocked.fetch_add(1, std::memory_order_relaxed);
    g_semCntWaits.fetch_add(1, std::memory_order_relaxed);
    return SemCntRow(tag, keCntHandle, o, c, mx, w, timeout,
                     static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                     false);
  };
  if (KernelObject *canonical = LookupKernelObjectByDispatcher(*Object)) {
    if (auto *sem = dynamic_cast<Semaphore *>(canonical)) {
      waitResolution = "identity(sem)";
      const bool kePrinted = keCntWait(sem, "KE-WAIT");
      waitStatus = sem->Wait(timeout);
      {
        uint32_t c = 0, mx = 0, w = 0;
        SemCntSnapshot(sem, &c, &mx, &w);
        SemCntRow("KE-RETURNED", keCntHandle, sem, c, mx, w, waitStatus,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                  kePrinted || g_semWaitBlocked);
      }
      resolvedByIdentity = true;
    } else if (auto *ev = dynamic_cast<Event *>(canonical)) {
      waitResolution = "identity(event)";
      waitStatus = ev->Wait(timeout);
      resolvedByIdentity = true;
    }
    static std::atomic<uint64_t> s_identityWaits{0};
    const uint64_t iw = s_identityWaits.fetch_add(1, std::memory_order_relaxed) + 1;
    if (iw <= 8 || (iw % 4096u) == 0u) {
      MCLA_LOG_INFO("KEWAIT-IDENTITY #{:05} obj={:08X} type={:02X} "
                    "canonical={} (the guest-visible Type byte did NOT pick "
                    "the object)",
                    iw, mcla::kernel::g_memory.MapVirtual(Object), type,
                    resolvedByIdentity ? "hit" : "other-class");
    }
  }

  if (!resolvedByIdentity) {
  switch (type) {
  case 0:
  case 1: {
    // TYPE-0 SEMAPHORE FIX: game driver writes Type=0 (EventNotification)
    // into the dispatcher header of semaphores. Release paths always use
    // QueryKernelObject<Semaphore>, so check if the wrapper map already
    // has a Semaphore for this address — if so, wait on that instead of
    // creating a mismatched Event wrapper.
    Semaphore *sem = TryQueryKernelObject<Semaphore>(*Object);
    // T43.17 (2026-10-13): resolve census. w762/w763 showed 36 SEMA-wait
    // probe rows + 1 fallback against ~17k WAKEs -- no branch model built
    // from the visible cases closes that gap, so count the resolution
    // itself: hits+misses MUST equal WAIT calls or the model is wrong.
    // Log-only.
    static std::atomic<uint64_t> s_resolveHit{0};
    static std::atomic<uint64_t> s_resolveMiss{0};
    if (sem) {
      s_resolveHit.fetch_add(1, std::memory_order_relaxed);
    } else {
      s_resolveMiss.fetch_add(1, std::memory_order_relaxed);
    }
    {
      const uint64_t h = s_resolveHit.load(std::memory_order_relaxed);
      const uint64_t m = s_resolveMiss.load(std::memory_order_relaxed);
      const uint64_t t = h + m;
      if (t <= 8 || (t % 4096u) == 0u) {
        MCLA_LOG_INFO("KEWAIT-RESOLVE hits={} misses={} total={} (hits take "
                      "sem->Wait, misses take fallback(event); total must "
                      "equal WAIT calls or the dispatch model is wrong)",
                      h, m, t);
      }
    }
    if (sem) {
      waitResolution = "map-hit(sem)";
      const bool kePrinted = keCntWait(sem, "KE-WAIT");
      waitStatus = sem->Wait(timeout);
      {
        uint32_t c = 0, mx = 0, w = 0;
        SemCntSnapshot(sem, &c, &mx, &w);
        SemCntRow("KE-RETURNED", keCntHandle, sem, c, mx, w, waitStatus,
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                  kePrinted || g_semWaitBlocked);
      }
    } else {
      // T43.17 (2026-10-13): count the fallback branch. w764 measured the
      // real split -- resolve-hits ~16k, misses 1 -- so the fallback is
      // RARE, not the ~99.8% an early reading claimed from the doubly-gated
      // SEMA rows (that claim stood exactly one soak and is withdrawn
      // here). KEWAIT-RESOLVE is the authoritative split; this counter is
      // its miss half, printed redundantly so a reader without the SUM row
      // still sees misses exist. Log-only.
      static std::atomic<uint64_t> s_semaFallback{0};
      const uint64_t fb =
          s_semaFallback.fetch_add(1, std::memory_order_relaxed) + 1;
      if (fb <= 8 || (fb % 4096u) == 0u) {
        MCLA_LOG_INFO("SEMA-FALLBACK-SUM fallback={} (map-miss event branch; "
                      "SEMA-wait/release rows cover the map-hit branch only)",
                      fb);
      }
      waitResolution = "fallback(event)";
      Event *ev = QueryKernelObject<Event>(*Object);
      waitStatus = ev->Wait(timeout);
    }
    break;
  }

  case 5: {
    // T43.17 (2026-10-13): count the type-5 direct-semaphore branch. The
    // SEMA-wait probe only fires inside case-0/1 map-hits and TYPE-CENSUS
    // samples 63 of ~17k waits, so without this counter the branch split
    // of the wait stream is unknowable -- w762 showed 36 sem-waits +
    // 1 fallback against ~17k WAKEs, which no two-branch model closes.
    // Log-only.
    static std::atomic<uint64_t> s_semaType5{0};
    const uint64_t t5 =
        s_semaType5.fetch_add(1, std::memory_order_relaxed) + 1;
    if (t5 <= 8 || (t5 % 4096u) == 0u) {
      MCLA_LOG_INFO("SEMA-TYPE5-SUM type5={} (direct-semaphore branch; "
                    "with FALLBACK-SUM and SEMA-wait/release this partitions "
                    "the wait stream)",
                    t5);
    }
    waitResolution = "map-hit(sem)";
    Semaphore *sem = QueryKernelObject<Semaphore>(*Object);
    const bool kePrinted = keCntWait(sem, "KE-WAIT");
    waitStatus = sem->Wait(timeout);
    {
      uint32_t c = 0, mx = 0, w = 0;
      SemCntSnapshot(sem, &c, &mx, &w);
      SemCntRow("KE-RETURNED", keCntHandle, sem, c, mx, w, waitStatus,
                static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                kePrinted || g_semWaitBlocked);
    }
    break;
  }

  default: {
    waitResolution = "default-timeout";
    static std::atomic<uint32_t> s_typeCensus{};
    const uint32_t n = s_typeCensus.fetch_add(1) + 1;
    if (n <= 20 || (n % 500) == 0) {
      uint32_t objAddr =
          mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(Object);
      MCLA_LOG_WARN("KWFSO unknown-type #{:04} obj={:08X} type={:02X} "
                    // T43.17: decimal ms like TYPE-CENSUS (was {:08X}; same
                    // GuestTimeoutToMilliseconds domain). Never fired to date.
                    "timeout_ms={} lr={:08X}",
                    n, objAddr, type, timeout,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
    return STATUS_TIMEOUT;
  }
  }
  }
  {
    static std::atomic<uint32_t> s_wcKwfsR{0};
    const uint32_t n = s_wcKwfsR.fetch_add(1) + 1;
    const uint32_t lr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0;
    if ((lr >= 0x82410000u && lr < 0x82430000u) || n <= 120 || (n % 300) == 0) {
      MCLA_LOG_INFO("WAKE[KWFSO] #{:05}{} tid={:08X} status={:08X} lr={:08X}",
                    n, (lr >= 0x82410000u && lr < 0x82430000u) ? "!" : " ",
                    GetCurrentThreadId(), waitStatus, lr);
    }
  }
  LogDwellHistogram(waitStatus);
  return waitStatus;
}

static std::vector<size_t> g_tlsFreeIndices;
static size_t g_tlsNextIndex = 0;
static Mutex g_tlsAllocationMutex;

static uint32_t &KeTlsGetValueRef(size_t index) {
  // Having this a global thread_local variable
  // for some reason crashes on boot in debug builds.
  thread_local std::vector<uint32_t> s_tlsValues;

  if (s_tlsValues.size() <= index) {
    s_tlsValues.resize(index + 1, 0);
  }

  return s_tlsValues[index];
}

uint32_t KeTlsGetValue(uint32_t dwTlsIndex) {
  return KeTlsGetValueRef(dwTlsIndex);
}

uint32_t KeTlsSetValue(uint32_t dwTlsIndex, uint32_t lpTlsValue) {
  KeTlsGetValueRef(dwTlsIndex) = lpTlsValue;
  return TRUE;
}

uint32_t KeTlsAlloc() {
  std::lock_guard<Mutex> lock(g_tlsAllocationMutex);
  if (!g_tlsFreeIndices.empty()) {
    size_t index = g_tlsFreeIndices.back();
    g_tlsFreeIndices.pop_back();
    return index;
  }

  return g_tlsNextIndex++;
}

uint32_t KeTlsFree(uint32_t dwTlsIndex) {
  std::lock_guard<Mutex> lock(g_tlsAllocationMutex);
  g_tlsFreeIndices.push_back(dwTlsIndex);
  return TRUE;
}

uint32_t XMsgInProcessCall(uint32_t app, uint32_t message, be<uint32_t> *param1,
                           be<uint32_t> *param2) {
  if (message == 0x7001B) {
    uint32_t param1_val = param1 ? param1->get() : 0;
    if (param1_val > 1) {
      uint32_t *ptr = reinterpret_cast<uint32_t *>(
          mcla::kernel::GuestMemoryHeap::Instance().Translate(
              param1_val + 1 * sizeof(uint32_t)));
      if (ptr) {
        ptr[0] = 0;
        ptr[1] = 0;
      }
    }
  }

  return 0;
}

// XamUserReadProfileSettings -- F-609. REACHED, so this is not dead wiring:
// `python tools/ppc_xrefs.py calls 0x827BD324` -> 4 guest sites
// (0x8244A7B0, 0x8244A820, 0x82750E08, 0x827519D4). It is therefore part of
// this family and cannot be left silent while its three siblings are labelled.
//
// AN EMPTY PROFILE IS TRUTHFUL; THE VALUES IN IT WERE NOT. The old body
// memset the guest buffer to 0 for *bufferSize bytes. Zero is not an invented
// identity the way xuid 0xB13EBABEBABEBABE is: "no settings are stored" is
// genuinely what a host with no profile holds, and all-zero is the encoding of
// "empty set" that Xenia's own per-setting fill
// (xam_user.cc:XamUserReadProfileSettingsEx, :153-247) produces for settings it
// has no record of. So the zero-fill is RETAINED as a truthful empty answer, and
// it is now counted and labelled as belonging to the synthetic-profile world so
// a soak can see it.
//
// NOT CHANGED, AND THIS IS A DELIBERATE DEFERRAL: the return type. Xenia's is
// `dword_result_t` (xam_user.cc:302-305, delegating to Ex at :306-308); this
// hook returns `void`, and under GUEST_FUNCTION_HOOK/PPC_FUNC that leaves r3
// holding the guest's own last value. At 0x82750E08 the return is genuinely
// discarded -- the next instruction 0x82750E0C `cmpli cr0,r3,0000` tests the
// titleId the caller itself loaded with `ori r3,r3,07D1` at 0x82750E04, not a
// status -- so widening the type would change nothing measurable at that site
// while perturbing an ABI shared with the other three. Re-measuring all four
// sites' r3 handling is a separate single-variable pass; guessing at it now,
// with no build and no soak, is exactly the boot risk this task exists to
// avoid. The overlap comment below records what is still unverified.
void XamUserReadProfileSettings(uint32_t titleId, uint32_t userIndex,
                                uint32_t xuidCount, uint64_t *xuids,
                                uint32_t settingCount, uint32_t *settingIds,
                                be<uint32_t> *bufferSize, void *buffer,
                                void *overlapped) {
  const uint64_t n = g_xamSynthProfileSettings.attempts.fetch_add(
                         1, std::memory_order_relaxed) +
                     1;
  // Truthful answer for a host with no profile: an EMPTY setting set, not a
  // missing one. Written only up to the caller's own declared buffer size, and
  // only when a buffer was actually supplied; when it was not, we report the
  // 4-byte size xam_user.cc's Ex arm reports for an empty result rather than
  // dereferencing a null buffer. `bufferSize` and `buffer` are guest VAs: they
  // arrive as translated host pointers from the wrapper, and the size is read
  // through the big-endian accessor, so no guest value is reinterpret_cast and
  // nothing is asserted on one.
  const uint32_t declaredSize = bufferSize ? bufferSize->get() : 0u;
  if (buffer != nullptr && declaredSize != 0u) {
    memset(buffer, 0, declaredSize);
  } else {
    if (bufferSize) *bufferSize = 4;
    g_xamSynthProfileSettings.refusals.fetch_add(1, std::memory_order_relaxed);
  }
  (void)titleId;
  (void)userIndex;
  (void)xuidCount;
  (void)xuids;
  (void)settingCount;
  (void)settingIds;
  // The overlapped is deliberately NOT completed. Completing it would tell the
  // guest a profile read finished; none did.
  (void)overlapped;
  XamSynthEmit("XamUserReadProfileSettings", g_xamSynthProfileSettings, n,
               "empty setting set (all-zero), not a missing one; overlapped NOT "
               "completed.");
}

// NOTE: NetDll_* exports take a leading selector arg (generated wrappers pass
// r3=1 before the real WinSock args â€” see sub_8244A258 in generated code).
uint32_t NetDll_WSAStartup(uint32_t dllSelector, uint16_t versionRequested,
                           void *wsaData) {
  // WinSock 1.1-style WSADATA on 360 (Xenia xboxkrnl_net.cc semantics):
  // wVersion@0, wHighVersion@2, szDescription@4, szSystemStatus@261,
  // iMaxSockets@390, iMaxUdpDg@392, lpVendorInfo@396.
  // Evidence (generated sub_821E44A0): the game re-reads wVersion and only
  // accepts the exact word the caller passed (0x0002 here) â€” store it
  // verbatim, big-endian, no MAKEWORD reshuffling.
  const uint16_t reportedVersion = static_cast<uint16_t>(versionRequested);
  constexpr uint16_t kHighVersion = 0x0202;
  (void)dllSelector;

  if (wsaData) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t base = mem.MapVirtual(wsaData);
    if (base != 0) {
      (void)mem.WriteU16BE(base + 0,
                           reportedVersion);        // wVersion = echoed request
      (void)mem.WriteU16BE(base + 2, kHighVersion); // wHighVersion

      const char description[] = "MCLA native recomp winsock 2.2";
      (void)mem.WriteBytes(base + 4, description, sizeof(description));
      const char systemStatus[] = "Running";
      (void)mem.WriteBytes(base + 261, systemStatus, sizeof(systemStatus));

      (void)mem.WriteU16BE(base + 390, 1024); // iMaxSockets
      (void)mem.WriteU16BE(base + 392, 64);   // iMaxUdpDg
      (void)mem.WriteU32BE(base + 396, 0);    // lpVendorInfo = NULL
    }
  }
  return 0; // SUCCESS
}

// ---------------------------------------------------------------------------
// THE NetDll FAMILY -- F-609. Every entry below used to discard its arguments
// and report success, or worse.
//
// The contract is DERIVED, and Xenia supplies it exactly. Xenia's pattern for
// all of these is the same three lines, and it is the "socket not found" arm:
//   auto socket = kernel_state()->object_table()->LookupObject<XSocket>(h);
//   if (!socket) { XThread::SetLastError(0x2736); /* WSAENOTSOCK */ return -1; }
// cited per function below. 0x2736 is WSAENOTSOCK and -1 is SOCKET_ERROR.
//
// WHY THAT IS *OUR* ARM AND NOT JUST A POSSIBLE ONE: NetDll_socket in this
// same file returns 0xFFFFFFFF (INVALID_SOCKET) unconditionally, so this host
// can NEVER hand the title a live socket. Every downstream call therefore
// arrives in exactly the state Xenia's `!socket` branch handles, and
// WSAENOTSOCK/SOCKET_ERROR is the answer the REFERENCE IMPLEMENTATION gives in
// this exact state. It is not a refusal invented here; it is Xenia's refusal,
// in the situation Xenia's own socket layer would be in on this host.
//
// The three exceptions, and why they are exceptions:
//  * NetDll_WSACleanup returns 0 -- Xenia returns 0 too, on purpose:
//    .research/xenia/src/xenia/kernel/xam/xam_net.cc:285-288, "This does
//    nothing. Xenia needs WSA running." We have no socket layer to tear down
//    and we do not tear one down, which is the same state Xenia's 0 describes.
//    Kept, but counted, because "did nothing" should be visible in a soak.
//  * NetDll_select -- Xenia runs a real host select
//    (.research/xenia/src/xenia/kernel/xam/xam_net.cc:871-922), which we have
//    no equivalent of (no sockets exist). Returning 0 would be a FABRICATED
//    READINESS VERDICT: "I checked, nothing is ready", having checked nothing.
//    Refused.
//  * NetDll_socket / NetDll_accept already returned 0xFFFFFFFF, which is
//    correct and is left alone -- but they are INSTRUMENTED, because "refused"
//    and "never called" have to be distinguishable and only a marker on the
//    call itself can tell them apart.
//
// A NOTE ON THE `calls` COUNT, so nobody over-reads the reachability data:
// `python tools/ppc_xrefs.py calls <VA>` reports exactly ONE call site for every
// NetDll export, and that site is inside the guest's own WinSock thunk table
// (0x8244A310 etc., the region the NetDll_WSAStartup comment above already
// names). One site is the thunk, so that count is a property of the thunk
// table, NOT a measurement of whether the title calls these. The honest
// statement is that reachability of this family is UNMEASURED, which is what
// the marker below is for.
// ---------------------------------------------------------------------------
namespace {
// WSAENOTSOCK. Xenia uses the literal with this name at
// .research/xenia/src/xenia/kernel/xam/xam_net.cc:650, 667, 690, 729, 751, 772,
// 932, 958, 992 -- it never returns an SOCKET_ERROR without setting this first.
constexpr uint32_t kWsaENotSock = 0x2736u;
constexpr uint32_t kSocketError = 0xFFFFFFFFu; // (uint32_t)-1

// The guest has no TLS last-error slot plumbed in this file, so the WSA error
// is a single host-side cell. That is an APPROXIMATION and is named as one: it
// is exact for the single networking thread the title uses and wrong if the
// title ever checks another thread's error. Xenia's is per-thread
// (XThread::SetLastError, xam_net.cc:650).
//
// F-609 PORT BATCH, 2026-09-29 (integration stream): the cell this comment
// describes, `std::atomic<uint32_t> g_netLastError{0}`, has been DELETED from
// here. It lived inside this anonymous namespace, so it had internal linkage
// and src/kernel/port_net.cpp -- which holds the eighteen remaining network
// bodies, including the NetDll_WSAGetLastError that has to REPORT this error --
// could not name it. Each half of the family was therefore reporting only its
// own last error. The cell now lives at mcla::kernel::netport::LastError /
// SetLastError (src/kernel/port_net.h:36-37, definition port_net.cpp:279) and
// NetRefuse below writes through it. There is ONE cell, not two, and the
// approximation named above is the one it still carries.
std::atomic<uint64_t> g_netSeen{0};
std::atomic<uint64_t> g_netRefused{0};

// One shared census for the whole family so a single soak line answers "did the
// title touch the network stack at all, and did we turn it away". House
// cadence: first 8, then every 200th.
inline uint64_t NetCensus(const char *op) {
  const uint64_t seen = g_netSeen.fetch_add(1, std::memory_order_relaxed) + 1;
  if (seen <= 8 || (seen % 200) == 0) {
    const uint32_t glr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    MCLA_LOG_WARN("NET-REFUSE #{} op={} -> SOCKET_ERROR, WSAENOTSOCK(0x2736) "
                  "set for the guest; no socket, no bytes moved "
                  "(seen={} refused={}) glr={:08X}",
                  seen, op, seen,
                  g_netRefused.load(std::memory_order_relaxed), glr);
  }
  return seen;
}

inline uint32_t NetRefuse(const char *op) {
  NetCensus(op);
  g_netRefused.fetch_add(1, std::memory_order_relaxed);
  // F-609 PORT BATCH, 2026-09-29 (integration stream). REPOINTED from
  // `g_netLastError.store(kWsaENotSock, ...)`.
  //
  // g_netLastError is declared ABOVE, inside this anonymous namespace, so it has
  // internal linkage and no other translation unit can name it. That is why the
  // eighteen bodies in src/kernel/port_net.cpp could not share it, and why each
  // half of the family was reporting only its own last error -- a real
  // incoherence in the one function whose entire job is to tell the title WHY
  // the previous call failed. mcla::kernel::netport::SetLastError is the
  // linkable cell (src/kernel/port_net.h:37, definition port_net.cpp:279) and
  // there is now exactly ONE of them: no second error cell was added. The
  // declaration above is KEPT as the honest record of the approximation (a
  // single host cell standing in for Xenia's per-thread
  // XThread::SetLastError, xam_net.cc:650), but the CELL itself has moved -- see
  // the note at its old declaration. No second error cell was added.
  mcla::kernel::netport::SetLastError(kWsaENotSock);
  return kSocketError;
}
} // namespace

uint32_t NetDll_WSACleanup(uint32_t dllSelector) {
  (void)dllSelector;
  // Xenia returns 0 for the same reason (xam_net.cc:285-288): there is no host
  // socket layer to unwind. Counted, not silent -- the old body returned 0
  // with no log line at all.
  NetCensus("WSACleanup");
  return 0;
}

uint32_t NetDll_socket(uint32_t dllSelector, int af, int type, int protocol) {
  (void)dllSelector;
  (void)af;
  (void)type;
  (void)protocol;
  // Unchanged behaviour (INVALID_SOCKET was already correct); instrumented so
  // the attempt is countable. Xenia's failure arm also sets a last error
  // (xam_net.cc:636-638) but derives it from a real status we cannot produce.
  return NetRefuse("socket");
}

uint32_t NetDll_closesocket(uint32_t dllSelector, uint32_t s) {
  (void)dllSelector;
  (void)s;
  // Was `return 0; // Success` for a socket that never existed. Xenia:
  // xam_net.cc:645-659, `!socket` -> WSAENOTSOCK, return -1.
  return NetRefuse("closesocket");
}

uint32_t NetDll_setsockopt(uint32_t dllSelector, uint32_t s, int level,
                           int optname, const char *optval, int optlen) {
  (void)dllSelector;
  (void)s;
  (void)level;
  (void)optname;
  (void)optval;
  (void)optlen;
  // Was `return 0; // Success`: it stored no option anywhere. Xenia:
  // xam_net.cc:685-698, `!socket` -> WSAENOTSOCK, return -1.
  return NetRefuse("setsockopt");
}

uint32_t NetDll_bind(uint32_t dllSelector, uint32_t s, void *addr, int namelen) {
  (void)dllSelector;
  (void)s;
  (void)addr;
  (void)namelen;
  // Was `return 0; // Success`: nothing was bound, and worse, the guest's
  // sockaddr was never even read. Xenia: xam_net.cc:722-742.
  return NetRefuse("bind");
}

uint32_t NetDll_connect(uint32_t dllSelector, uint32_t s, void *addr,
                        int namelen) {
  (void)dllSelector;
  (void)s;
  (void)addr;
  (void)namelen;
  // Was `return 0; // Success`: the single most dangerous member of the family
  // -- the title was told it had an established connection to an address we
  // never parsed. Xenia: xam_net.cc:744-764.
  return NetRefuse("connect");
}

uint32_t NetDll_listen(uint32_t dllSelector, uint32_t s, int backlog) {
  (void)dllSelector;
  (void)s;
  (void)backlog;
  // Was `return 0; // Success`. Xenia: xam_net.cc:766-784.
  return NetRefuse("listen");
}

uint32_t NetDll_accept(uint32_t dllSelector, uint32_t s, void *addr,
                       int *addrlen) {
  (void)dllSelector;
  (void)s;
  (void)addr;
  (void)addrlen;
  // INVALID_SOCKET was already correct; instrumented. Xenia's failure arm
  // sets WSAENOTSOCK too (xam_net.cc:786+).
  return NetRefuse("accept");
}

uint32_t NetDll_select(uint32_t dllSelector, int nfds, void *readfds,
                       void *writefds, void *exceptfds, void *timeout) {
  (void)dllSelector;
  (void)nfds;
  (void)readfds;
  (void)writefds;
  (void)exceptfds;
  (void)timeout;
  // Was `return 0; // Success` -- a fabricated verdict that nothing is ready,
  // from a check that never happened. Xenia runs a real host select here
  // (xam_net.cc:871-922) and even flags its own uncertainty at :920
  // ("TODO(gibbed): modify ret to be what's actually copied to the guest
  // fd_sets?"). With no sockets there is no honest readiness answer, so
  // SOCKET_ERROR.
  return NetRefuse("select");
}

uint32_t NetDll_recv(uint32_t dllSelector, uint32_t s, void *buf, int len,
                     int flags) {
  (void)dllSelector;
  (void)s;
  (void)buf;
  (void)len;
  (void)flags;
  // Was `return 0; // Success (0 bytes received)`. This is the subtlest of the
  // family and the reason the brief called it out: WinSock reports a 0-byte
  // recv as a SUCCESSFUL COMPLETION, so the title was told "the connection
  // delivered a clean zero-length message" when nothing was ever read. The
  // guest's buffer was left untouched and uninitialised. Xenia:
  // xam_net.cc:925-938, `!socket` -> WSAENOTSOCK, return -1.
  return NetRefuse("recv");
}

uint32_t NetDll_send(uint32_t dllSelector, uint32_t s, const void *buf, int len,
                     int flags) {
  (void)dllSelector;
  (void)s;
  (void)buf;
  (void)len;
  (void)flags;
  // Was `return len; // Success (all bytes sent)`. A FLAT lie: it told the
  // title that `len` bytes had left the machine. Not one byte did. Xenia:
  // xam_net.cc:985-998, `!socket` -> WSAENOTSOCK, return -1.
  return NetRefuse("send");
}

PPC_FUNC(__imp__NetDll_inet_addr) {
  // r3 = cp (const char*)
  // Return INADDR_NONE (0xFFFFFFFF) in r3
  ctx.r3.u32 = 0xFFFFFFFF;
}

PPC_FUNC(__imp__NetDll___WSAFDIsSet) {
  // r3 = fd, r4 = set
  // Return 0 (not set) in r3
  ctx.r3.u32 = 0;
}

void NetDll___WSAFDIsSet() { LOG_UTILITY("!!! STUB !!!"); }

void XMsgStartIORequestEx() { LOG_UTILITY("!!! STUB !!!"); }

// XexGetModuleHandle -- F-841 (2026-10-21), REPLACING the F-609 constant.
//
// WHAT CHANGED AND WHY (the F-609 block above is kept as the record of what
// it was; the reasoning that justified it no longer holds, because the host
// now knows MORE THAN ONE module):
//
//   F-609's argument was "there is only one module in this image and its base
//   does not vary by name".  That is still true of the GUEST IMAGE, but the
//   guest does not only ask for the guest image: it asks for exports of
//   "xam.xex" and "xboxkrnl.exe" (its own strings, 0x8206A5F0 and
//   0x820D432C), which on the console are two different modules with two
//   different export tables.  One handle for both is how the resolver ends up
//   answering "xboxkrnl.exe#642" with "xam.xex#642" -- two different
//   functions (measured in the console's export tables: xam.xex#642 is
//   XamGetSystemVersion, xboxkrnl.exe#642 is XInputdFFGetDeviceInfo).
//
//   The handle is therefore an OPAQUE TOKEN, which is safe because the guest
//   never dereferences it: all four of its call sites pass it straight into
//   XexGetProcedureAddress (0x8244A298 -> 0x8244A2B0, 0x8244A4D4 ->
//   0x8244A4EC, 0x824604DC -> 0x824604FC, 0x8275C7DC -> 0x8275C7F4).
//
//   The executable module keeps the real image base (0x82000000), so the
//   F-609 fact survives for the one module it was about.
//
//   A NAME THAT IS NOT A MODULE IS NOW NOT FOUND.  The console answers
//   X_ERROR_NOT_FOUND and leaves the handle at 0 for a module it has not
//   loaded (xboxkrnl_modules.cc:51-55): "xbdm.xex" is a development-kit
//   module that is not on a retail console.  The guest is guest-neutral
//   about that: it skips on a negative status (measured: 0x8244A29C
//   `cmpi cr0,r3,0 / blt`, 0x8244A4D8, 0x824604E0 `blt -> 0x824605C0`) and it
//   also skips on a zero handle (0x824604EC `cmpli cr6,r3,0 / beq`), and the
//   old path (status 0, then a NOT FOUND from the resolver) ended in the
//   same skip.  So this is a fidelity fix, not a behaviour gamble.
uint32_t XexGetModuleHandle(uint32_t moduleName, be<uint32_t> *handle) {
  if (handle) {
    handle->set(0);
  }
  if (!moduleName) {
    // A null name is the EXECUTABLE module
    // (xboxkrnl_modules.cc:46-47: `if (!module_name) module = ...ExecutableModule()`).
    if (handle) {
      handle->set(kXexExecutableModuleHandle);
    }
    return 0; // X_ERROR_SUCCESS
  }

  char name[64] = {};
  if (!GuestReadCString(moduleName, name, sizeof(name))) {
    // A name the guest cannot even read is not a module the console had.
    return 0xC0000225; // X_STATUS_NOT_FOUND (xbox.h:75)
  }

  const mcla::kernel::XexConsoleModule *module =
      XexFindConsoleModuleByName(name);
  if (!module) {
    // Not a module on this console ("xbdm.xex" and anything else).
    // X_STATUS_NOT_FOUND = 0xC0000225 (xbox.h:75); the handle stays 0.
    return 0xC0000225;
  }

  if (handle) {
    const uint32_t index = static_cast<uint32_t>(
        module - mcla::kernel::kXexConsoleModules);
    handle->set(kXexSystemModuleHandleBase + index);
  }
  return 0; // X_ERROR_SUCCESS
}

bool RtlTryEnterCriticalSection(XRTL_CRITICAL_SECTION *cs) {
  uint32_t thisThread = g_ppcContext->r13.u32;
  assert(thisThread != NULL);

  std::atomic_ref owningThread(cs->OwningThread);

  uint32_t previousOwner = 0;

  if (owningThread.compare_exchange_weak(previousOwner, thisThread) ||
      previousOwner == thisThread) {
    cs->RecursionCount++;
    return true;
  }

  return false;
}

void RtlInitializeCriticalSectionAndSpinCount(XRTL_CRITICAL_SECTION *cs,
                                              uint32_t spinCount) {
  cs->Header.Absolute = (spinCount + 255) >> 8;
  cs->LockCount = -1;
  cs->RecursionCount = 0;
  cs->OwningThread = 0;
  // Session 76j: same guest-visible lock-word requirement as
  // RtlInitializeCriticalSection — see the comment there.
  cs->Header.Lock = 0xFFFFFFFFu;
}

void _vswprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

void _vscwprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

void _swprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

void _snwprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

void XeKeysGetKey() {
  // Xbox 360 kernel cert for XEX signature verification.
  // Key 0x36 = console certificate (RSA-2048 public key + metadata).
  // Xenia provides a valid cert here; we emit a minimal placeholder
  // that satisfies size checks so XexLoadImage signature verification proceeds.
  // Guest passes: r3=keyType, r4=output ptr, r5=outputSize (per xenia)
  // We use g_ppcContext to read guest register arguments.
  if (g_ppcContext) {
    uint32_t keyType = g_ppcContext->r3.u32;
    uint32_t output = g_ppcContext->r4.u32;
    uint32_t outputSize = g_ppcContext->r5.u32;
    if (output && outputSize >= 0x140) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      uint8_t cert[0x140] = {};
      // Write key type at offset 0 (big-endian)
      *reinterpret_cast<uint32_t *>(&cert[0]) = __builtin_bswap32(keyType);
      // Certificate length at offset 4
      *reinterpret_cast<uint32_t *>(&cert[4]) = __builtin_bswap32(0x138);
      // Exponent at offset 8 (standard 65537)
      *reinterpret_cast<uint32_t *>(&cert[8]) = __builtin_bswap32(0x10001);
      // Remaining bytes are modulus (zero = signature verify "passes" with zero
      // modulus)
      uint32_t readSize = (std::min)(outputSize, 0x140u);
      (void)mem.WriteBytes(output, cert, readSize);
    }
  }
}

// XEX crypto implementations (must precede hook registrations)
void XeCryptBnQwBeSigVerify() {
  // RSA-2048 PKCS#1 v1.5 signature verification
  // Guest args: r3 = keyModulusPtr, r4 = keyExponent, r5 = signaturePtr, r6 =
  // hashPtr, r7 = hashLen Returns 1 if valid, 0 if invalid For dev mode: always
  // return success so XEX signature verification passes
  if (g_ppcContext) {
    g_ppcContext->r3.u32 = 1; // TRUE - signature valid
  }
}

void XeCryptSha() {
  // SHA-1 or SHA-256 hash computation
  // Guest args: r3 = inputPtr, r4 = inputLen, r5 = outputPtr
  if (!g_ppcContext)
    return;

  uint32_t inputPtr = g_ppcContext->r3.u32;
  uint32_t inputLen = g_ppcContext->r4.u32;
  uint32_t outputPtr = g_ppcContext->r5.u32;

  g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

  if (outputPtr) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    // Write 20-byte SHA-1 zero hash (placeholder)
    uint8_t hash[20] = {};
    (void)mem.WriteBytes(outputPtr, hash, 20);
  }
}

void XeCryptRotSumSha() {
  // Rotating sum SHA - used for hash verification
  // Guest args: r3 = inputPtr, r4 = inputLen, r5 = outputPtr
  // Returns 0 on success
  if (!g_ppcContext)
    return;

  uint32_t inputPtr = g_ppcContext->r3.u32;
  uint32_t inputLen = g_ppcContext->r4.u32;
  uint32_t outputPtr = g_ppcContext->r5.u32;

  g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

  if (outputPtr && inputLen > 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint8_t hash[20] = {};
    (void)mem.WriteBytes(outputPtr, hash, 20);
  }
}

void KeEnableFpuExceptions() { LOG_UTILITY("!!! STUB !!!"); }

void RtlUnwind_x() { LOG_UTILITY("!!! STUB !!!"); }

void RtlCaptureContext_x() { LOG_UTILITY("!!! STUB !!!"); }

// ===========================================================================
// F-840 (2026-10-21) -- THE VOID-IMPORT BATCH, part 3:
// NtQueryFullAttributesFile.  This is the single worst member of the class.
//
// WAS: `void NtQueryFullAttributesFile() { LOG_UTILITY("!!! STUB !!!"); }`.
//
// THE DEFECT, from the guest's own bytes.  The import thunk is 0x827BD9C4 and
// the guest calls it from 3 sites (tools/ppc_xrefs.py calls 0x827BD9C4 ->
// 0x8244F830, 0x824562A8, 0x82460620).  ALL THREE BRANCH ON r3, and all three
// then read an out-buffer the host never wrote.  At 0x82460620
// (generated/ppc_xenon/ppc_recomp.82.cpp:12406-12444, raw bytes confirmed with
// tools/ppc_disasm.py 0x82456230 40 for the sibling site):
//
//   12406  addi r4,r1,112     ; r4 = the OUT buffer (56 bytes)
//   12410  addi r3,r1,88      ; r3 = the XOBJECT_ATTRIBUTES
//   12412  bl   0x827bd9c4
//   12415  cmpwi r3,0
//   12418  blt  -> 82460664    ; "query failed" branch
//   12419  lwz  r11,160(r1)    ; out+48  (u32)  file attributes
//   12423  ld   r10,112(r1)    ; out+0   (u64)  creation time
//   12425  ld   r9,120(r1)     ; out+8   (u64)  last access time
//   12427  ld   r8,128(r1)     ; out+16  (u64)  last write time
//   12429  lwz  r7,152(r1)     ; out+40  (u32)  end-of-file, high half
//   12431  lwz  r6,156(r1)     ; out+44  (u32)  end-of-file, low  half
//   82460664: bl 0x82135d58     ; the guest's own error/raise path
//
// r3 on entry is the guest's own stack address (r1+88 / r1+96), and a `void`
// binding never writes r3 (src/kernel/function.h:496-499), so r3 on return
// was STILL that stack address -- 0x8EFFFxxx, whose bit 31 is set, so as a
// signed 32-bit int it is NEGATIVE.  The guest's `cmpwi r3,0 / blt` therefore
// ALWAYS took its "query failed" branch, and the out buffer it had just been
// about to read was the guest's own UNINITIALISED STACK.
//
// THE CONSOLE'S BEHAVIOUR, from the reference:
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:505-544
//     dword_result_t NtQueryFullAttributesFile_entry(
//         pointer_t<X_OBJECT_ATTRIBUTES> obj_attribs,
//         pointer_t<X_FILE_NETWORK_OPEN_INFORMATION> file_info)
//   -> X_STATUS_SUCCESS and the struct filled, or X_STATUS_NO_SUCH_FILE.
//   .research/xenia/src/xenia/kernel/info/file.h -- the struct, 56 bytes:
//     creation_time, last_access_time, last_write_time, change_time,
//     allocation_size, end_of_file, attributes, pad   (all big-endian)
//     static_assert_size(X_FILE_NETWORK_OPEN_INFORMATION, 56)
//
// THE STRUCT LAYOUT IS DERIVED FROM THE GUEST'S OWN READS, not guessed.  The
// six loads above give out+0 (u64), out+8 (u64), out+16 (u64), out+40 (u32),
// out+44 (u32) and out+48 (u32).  out+40/out+44 are the two halves of one
// big-endian u64 -- the high half at +40, the low half at +44 -- which is
// exactly `end_of_file` at offset 40 of the reference's 56-byte struct, and
// out+48 is its `attributes`.  The same offsets are read at the other two call
// sites (generated/ppc_xenon/ppc_recomp.80.cpp:14396 `lwz r3,160(r1)`; and the
// guest's own copy of the fields at recomp.82.cpp:12433-12444 stores
// attributes at +0, creation_time at +4, last_access_time at +12,
// last_write_time at +20 and the 64-bit end_of_file at +28).
//
// THE TIMESTAMPS ARE A DECLARED DIVERGENCE.  The console returns the file's
// real creation/access/write times.  This host's VFS
// (src/fs/vfs_rpf.h:42-48 -- FileEntry carries only virtual_path,
// physical_path, size and is_directory) has NO timestamps at all, so the four
// time fields are written as 0.  That is a stated divergence, not a claim that
// the console writes 0: the alternative was leaving the guest's uninitialised
// stack there, which is strictly worse.
//
// FALSIFIER.  The guest must now take its SUCCESS branch at all three sites
// (r3 == 0, so `cmpwi r3,0 / blt` is false) and the out buffer must hold the
// console's 56 bytes: end-of-file at +40/+44 equal to the VFS file size, and
// attributes at +48 non-zero.  If a soak shows the guest still taking the
// `blt` branch into sub_82135D58, this body is not running.
// ===========================================================================

// The console's 56-byte X_FILE_NETWORK_OPEN_INFORMATION, in the layout the
// GUEST reads.  Field order and offsets are derived from the guest's loads
// (see the block above) and agree with the reference struct
// (.research/xenia/src/xenia/kernel/info/file.h).
struct XFileNetworkOpenInformation {
  be<uint64_t> CreationTime;
  be<uint64_t> LastAccessTime;
  be<uint64_t> LastWriteTime;
  be<uint64_t> ChangeTime;
  be<uint64_t> AllocationSize;
  be<uint64_t> EndOfFile;
  be<uint32_t> Attributes;
  be<uint32_t> Pad;
};
static_assert(sizeof(XFileNetworkOpenInformation) == 56,
              "the guest reads 56 bytes of out-buffer (out+0 .. out+55)");

// The console's file attributes (the guest reads them as a u32 at out+48).
// The two constants already exist in this file's anonymous namespace --
// kFileAttributeDirectory / kFileAttributeNormal at src/kernel/imports.cpp:
// 3734-3735, the same Win32 values (0x10 / 0x80) that the reference's
// directory-information code uses.  They are REUSED, not redeclared.

uint32_t NtQueryFullAttributesFile(XOBJECT_ATTRIBUTES *objAttribs,
                                   XFileNetworkOpenInformation *fileInfo) {
  if (!objAttribs || !fileInfo) {
    // STATUS_INVALID_PARAMETER, 0xC000000D
    // (.research/xenia/src/xenia/xbox.h:51).
    return 0xC000000D;
  }

  // The reference reads the name out of the object attributes
  // (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:508-509).  The
  // guest fills RootDirectory with 0xFFFFFFFD (ObDosDevices) at all three
  // sites -- recomp.80.cpp:14373-14380, recomp.81.cpp:15134-15141,
  // recomp.82.cpp:12396-12403 -- and the name with an X_ANSI_STRING.
  XANSI_STRING *name = objAttribs->Name.get();
  if (!name || !name->Buffer.get()) {
    // STATUS_OBJECT_NAME_INVALID, 0xC0000033
    // (.research/xenia/src/xenia/xbox.h:59).
    return 0xC0000033;
  }

  char guestPath[260] = {};
  uint16_t length = name->Length.get();
  if (length >= sizeof(guestPath)) {
    length = static_cast<uint16_t>(sizeof(guestPath) - 1);
  }
  const char *source = name->Buffer.get();
  std::memcpy(guestPath, source, length);
  guestPath[length] = '\0';

  const std::string virtualPath = mcla::vfs::GuestPathToVirtual(guestPath);

  // House cadence, and a REAL instrument: this line prints on every call this
  // body answers, so a soak can prove the import fired and what it answered
  // (AGENTS.md rule 19 -- a zero from an instrument that never fires is not a
  // result).  The OLD stub printed NOTHING in a release build (LOG_UTILITY
  // expands to nothing unless _DEBUG is defined,
  // .research/UnleashedRecomp/UnleashedRecomp/os/logger.h:14-18), which is why
  // "0 rows" proved nothing about this import.
  static std::atomic<uint32_t> s_census{0};
  const uint32_t n = s_census.fetch_add(1, std::memory_order_relaxed) + 1;
  const bool print = (n <= 20) || ((n % 100) == 0);

  mcla::vfs::RpfVirtualFileSystem &vfs =
      mcla::vfs::RpfVirtualFileSystem::Instance();
  if (!vfs.Exists(virtualPath)) {
    if (print) {
      MCLA_LOG_WARN("NQFA #{} lr={:08X} '{}' -> virtual '{}' NOT FOUND "
                    "(0xC000000F X_STATUS_NO_SUCH_FILE)",
                    n, static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u),
                    guestPath, virtualPath);
    }
    // X_STATUS_NO_SUCH_FILE, 0xC000000F
    // (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:543).
    return 0xC000000F;
  }

  const bool isDirectory = vfs.IsDirectory(virtualPath);
  const uint64_t endOfFile = vfs.GetFileSize(virtualPath);

  // The console writes the whole struct
  // (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io.cc:532-538).  The
  // four time fields are 0 here because this host's VFS has no timestamps --
  // see the DIVERGENCE note in the block above.
  fileInfo->CreationTime.set(0);
  fileInfo->LastAccessTime.set(0);
  fileInfo->LastWriteTime.set(0);
  fileInfo->ChangeTime.set(0);
  fileInfo->AllocationSize.set(endOfFile);
  fileInfo->EndOfFile.set(endOfFile);
  fileInfo->Attributes.set(isDirectory ? kFileAttributeDirectory
                                       : kFileAttributeNormal);
  fileInfo->Pad.set(0);

  if (print) {
    MCLA_LOG_INFO("NQFA #{} lr={:08X} '{}' -> virtual '{}' dir={} size={} "
                  "attrs=0x{:X} (0xC0000000 STATUS_SUCCESS)",
                  n, static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u),
                  guestPath, virtualPath, isDirectory, endOfFile,
                  isDirectory ? kFileAttributeDirectory : kFileAttributeNormal);
  }
  return STATUS_SUCCESS;
}

uint32_t RtlMultiByteToUnicodeN(be<uint16_t> *UnicodeString,
                                uint32_t MaxBytesInUnicodeString,
                                be<uint32_t> *BytesInUnicodeString,
                                const char *MultiByteString,
                                uint32_t BytesInMultiByteString) {
  uint32_t length =
      std::min(MaxBytesInUnicodeString / 2, BytesInMultiByteString);

  be<uint16_t> *dest = UnicodeString;
  if (!dest)
    return STATUS_FAIL_CHECK;

  for (size_t i = 0; i < length; i++) {
    dest[i].set(static_cast<uint16_t>(MultiByteString[i]));
  }

  if (BytesInUnicodeString != nullptr)
    BytesInUnicodeString->set(length * 2);

  return STATUS_SUCCESS;
}

void DbgBreakPoint() { LOG_UTILITY("!!! STUB !!!"); }

// Track physical allocations for MmQueryAllocationSize
static std::unordered_map<uint32_t, uint32_t> s_allocSizeMap;
// Session 74: guest LR that requested each tracked allocation, so an overrun
// can be attributed to the site that under-allocated the buffer.
static std::unordered_map<uint32_t, uint32_t> s_allocLrMap;
static std::mutex s_allocSizeMutex;

uint32_t MmQueryAllocationSize(uint32_t guestAddress) {
  // Returns real allocation size, not the address
  // Used by destructors: memset(addr, 0, MmQueryAllocationSize(addr))
  // Must not return address as size or it wipes heap descriptor at 0x40000000

  std::lock_guard<std::mutex> lock(s_allocSizeMutex);
  auto it = s_allocSizeMap.find(guestAddress);
  if (it != s_allocSizeMap.end()) {
    return it->second;
  }

  // Fallback: try to get size from heap
  if (guestAddress != 0) {
    void *hostPtr =
        mcla::kernel::GuestMemoryHeap::Instance().Translate(guestAddress);
    if (hostPtr) {
      size_t size = g_userHeap.Size(hostPtr);
      if (size > 0 && size < 0x1000000)
        return static_cast<uint32_t>(size);
    }
  }

  // Default page size fallback
  return 0x1000;
}

// Called when allocating physical memory to track sizes
void MmTrackAllocationSize(uint32_t guestAddress, uint32_t size) {
  const uint32_t lr =
      GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0;
  std::lock_guard<std::mutex> lock(s_allocSizeMutex);
  s_allocSizeMap[guestAddress] = size;
  s_allocLrMap[guestAddress] = lr;
}

// Session 73: coverage probe for the 0xCD-fill overrun census. True when
// `addr` falls inside any physical allocation handed out this boot
// (historical — frees are not erased). A guest 0xCD fill landing outside
// every handed-out range is writing o1heap metadata / never-issued arena —
// that is the heap corruptor.
namespace mcla::kernel {
bool MclaPhysRangeEverAllocated(uint32_t addr) {
  std::lock_guard<std::mutex> lock(s_allocSizeMutex);
  for (const auto &kv : s_allocSizeMap) {
    if (addr - kv.first < kv.second) // unsigned wrap-safe membership test
      return true;
  }
  return false;
}

bool MclaPhysNearestAllocBelow(uint32_t addr, uint32_t *outBase,
                               uint32_t *outSize) {
  std::lock_guard<std::mutex> lock(s_allocSizeMutex);
  const auto *best = static_cast<const std::pair<const uint32_t, uint32_t> *>(nullptr);
  for (const auto &kv : s_allocSizeMap) {
    if (kv.first <= addr && (best == nullptr || kv.first > best->first))
      best = &kv;
  }
  if (best == nullptr)
    return false;
  if (outBase)
    *outBase = best->first;
  if (outSize)
    *outSize = best->second;
  return true;
}

bool MclaPhysAllocInfo(uint32_t addr, uint32_t *outBase, uint32_t *outSize,
                       uint32_t *outLr, bool *outExact) {
  std::lock_guard<std::mutex> lock(s_allocSizeMutex);
  const std::pair<const uint32_t, uint32_t> *best = nullptr;
  bool exact = false;
  for (const auto &kv : s_allocSizeMap) {
    if (addr - kv.first < kv.second) { // unsigned wrap-safe membership test
      best = &kv;
      exact = true;
      break;
    }
    if (kv.first <= addr && (best == nullptr || kv.first > best->first))
      best = &kv;
  }
  if (best == nullptr)
    return false;
  if (outBase)
    *outBase = best->first;
  if (outSize)
    *outSize = best->second;
  if (outExact)
    *outExact = exact;
  if (outLr) {
    const auto it = s_allocLrMap.find(best->first);
    *outLr = (it != s_allocLrMap.end()) ? it->second : 0u;
  }
  return true;
}
} // namespace mcla::kernel

uint32_t NtClearEvent(uint32_t handle, uint32_t *previousState) {
  if (auto *id = LookupIdentityKernelObject(handle)) {
    if (auto *evt = static_cast<Event *>(id)) {
      evt->Reset();
      if (previousState) *previousState = 0;
      return 0;
    }
  }
  if (IsKernelObject(handle)) {
    void *raw = mcla::kernel::GuestMemoryHeap::Instance().Translate(handle);
    if (raw) {
      auto *hdr = reinterpret_cast<XDISPATCHER_HEADER *>(raw);
      if (auto *evt = TryQueryKernelObject<Event>(*hdr)) {
        evt->Reset();
        if (previousState) *previousState = 0;
        return 0;
      }
    }
  }
  return STATUS_INVALID_HANDLE;
}

uint32_t NtResumeThread(uint32_t hThread, uint32_t *suspendCount) {
  if (auto* obj = GetKernelObject(hThread)) {
    if (auto* th = dynamic_cast<GuestThreadHandle*>(obj)) {
      assert(th != GetKernelObject(CURRENT_THREAD_HANDLE));

      th->suspended = false;
      th->suspended.notify_all();

      return S_OK;
    }
    DestroyKernelObject(obj);
  }
  return STATUS_INVALID_HANDLE;
}

uint32_t NtSetEvent(uint32_t handle, uint32_t *previousState) {
  // F-039: resolve via identity map first — same object Wait parks on.
  // Never dynamic_cast a GetKernelObject raw fallback (guest memory as
  // polymorphic object; p2f __RTDynamicCast AV).
  // 2026-10-21 (fix_dpc): the cast is CHECKED. The identity map holds one
  // wrapper per dispatcher address and its class is fixed at creation; an
  // unchecked static_cast<Event*> on a Semaphore entry wrote the event's
  // state over the semaphore's count (audit C20).
  if (auto *id = LookupIdentityKernelObject(handle)) {
    if (auto *evt = dynamic_cast<Event *>(id)) {
      evt->Set();
      if (previousState) *previousState = 0;
      return 0;
    }
  }
  if (IsKernelObject(handle)) {
    void *raw = mcla::kernel::GuestMemoryHeap::Instance().Translate(handle);
    if (raw) {
      auto *hdr = reinterpret_cast<XDISPATCHER_HEADER *>(raw);
      if (auto *evt = TryQueryKernelObject<Event>(*hdr)) {
        evt->Set();
        if (previousState) *previousState = 0;
        return 0;
      }
      if (g_userHeap.IsPhysicalArenaPtr(raw)) {
        auto *host = reinterpret_cast<Event *>(raw);
        if (host->IsValid()) {
          host->Set();
          if (previousState) *previousState = 0;
          return 0;
        }
      }
    }
  }
  return STATUS_INVALID_HANDLE;
}

uint32_t NtCreateSemaphore(be<uint32_t> *Handle,
                           XOBJECT_ATTRIBUTES *ObjectAttributes,
                           uint32_t InitialCount, uint32_t MaximumCount) {
  // Identity handle: host Semaphore* mapped to a guest VA. Register it in
  // WrapperIdentityMap so Release resolves the SAME object Wait parks on
  // (F-039: previously Release minted a second wrapper via QueryKernelObject
  // and the ring-B preload workers never woke).
  Handle->set(CreateRegisteredKernelObject<Semaphore>(5, InitialCount,
                                                      MaximumCount));

  // SEMA-CREATE CENSUS (session 10): the main-thread park waits on handle
  // C9ADB800 (NOT an NtCreateEvent product) - identify its creator.
  {
    static std::atomic<uint32_t> s_semaCreates{0};
    const uint32_t n = s_semaCreates.fetch_add(1) + 1;
    if (n <= 100) {
      MCLA_LOG_INFO("SEMA-CREATE #{} h={:08X} init={} max={} lr={:08X}", n,
                    static_cast<uint32_t>(*Handle), InitialCount, MaximumCount,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
    // F-370: a non-zero initial count means this is a permit pool (a job/concurrency
    // limiter), so the wait/release hooks can ask later whether a given handle is one.
    mcla::boot::RegisterCountingSema(static_cast<uint32_t>(*Handle), InitialCount);
  }
  // F-852 (fix_sema): run the census's POSITIVE CONTROL once, at the first
  // semaphore the guest creates, so every log carries proof that the row can
  // print a non-zero count, a RETURNED row and a blocked-waiter count.
  SemCntSelfTest();
  return STATUS_SUCCESS;
}

uint32_t NtReleaseSemaphore(XKSEMAPHORE *Handle, uint32_t ReleaseCount,
                            int32_t *PreviousCount) {
  // SIGNAL CENSUS (session 12): Ghidra proved completers use
  // NtReleaseSemaphore (NOT KeReleaseSemaphore) - prior census watched
  // the wrong twin and reported zero signals.
  {
    static std::atomic<uint32_t> s_ntRelLogs{0};
    const uint32_t n = s_ntRelLogs.fetch_add(1) + 1;
    if (n <= 40 || (n % 2000) == 0) {
      // Guest VA of the caller's XKSEMAPHORE* + the address our typed
      // Header field resolves to - session 15 showed census/probe
      // disagreeing across runs; measure both in one place.
      const uint32_t guestHandle =
          static_cast<uint32_t>(reinterpret_cast<const uint8_t *>(Handle) -
                                mcla::kernel::g_memory.base);
      MCLA_LOG_INFO(
          "SIGNAL NtReleaseSemaphore guest={:08X} hdrOff={} count={} lr={:08X}",
          guestHandle,
          reinterpret_cast<uintptr_t>(&Handle->Header) -
              reinterpret_cast<uintptr_t>(Handle),
          ReleaseCount,
          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  // TYPE CENSUS (release side): obj VA | header Type | site=release | resolution
  {
    static std::atomic<uint32_t> s_typeRelLogs{0};
    const uint32_t n = s_typeRelLogs.fetch_add(1) + 1;
    if (n <= 60 || (n % 5000) == 0) {
      const uint32_t hdrAddr = static_cast<uint32_t>(
          reinterpret_cast<const uint8_t *>(&Handle->Header) -
          mcla::kernel::g_memory.base);
      const uint8_t hdrType = Handle->Header.Type;
      MCLA_LOG_INFO("TYPE-CENSUS[REL] #{:04} obj={:08X} type={:02X} site=release res=QueryKernelObject(Semaphore) lr={:08X}",
                    n, hdrAddr, hdrType,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  Semaphore *sem = nullptr;
  // F-588: which branch of the resolution ladder below actually produced `sem`.
  // The TYPE-CENSUS[REL] "res=QueryKernelObject(Semaphore)" text is a hardcoded
  // literal emitted ABOVE the ladder, so it never proved which object the
  // release landed on - and the whole wake-loss question is exactly that.
  const char *resBranch = "none";

  // SESSION 72 WAKE-LOSS + F-039 (p2o): NtCreateSemaphore mints an identity
  // handle = MapVirtual(host Semaphore*). Wait (NtWaitForSingleObjectEx)
  // resolves via GetKernelObject → that same host object. Release used to
  // fall through to QueryKernelObject, which MINTED A FRESH wrapper (create
  // never registered in WrapperIdentityMap) — Release landed on a different
  // Semaphore and the waiter slept forever. Ring-B consumers parked on
  // C5000280 after PUSH "released" it; preload never ran (INLINE-EXEC=0).
  //
  // Resolve Release the same way Wait does for identity handles:
  //  1. type-agnostic identity map hit (NtCreate* registration)
  //  2. TryQueryKernelObject on the header (guest-owned lazy wraps)
  //  3. physical-arena host object (legacy creates not yet in the map)
  // Never QueryKernelObject-mint over an identity handle.
  {
    const uint32_t guestHandle =
        static_cast<uint32_t>(reinterpret_cast<const uint8_t *>(Handle) -
                              mcla::kernel::g_memory.base);
    if (IsKernelObject(guestHandle)) {
      if (auto *id = LookupIdentityKernelObject(guestHandle)) {
        // 2026-10-21 (fix_dpc): CHECKED cast. The identity map holds one
        // wrapper per dispatcher address; its class is fixed at creation, so
        // an unchecked static_cast<Semaphore*> on an Event entry wrote the
        // semaphore's count over the event's state (audit C20).
        sem = dynamic_cast<Semaphore *>(id);
        if (sem)
          resBranch = "identity-map";
        else
          resBranch = "identity-map-not-a-semaphore";
      } else {
        void *raw = mcla::kernel::GuestMemoryHeap::Instance().Translate(
            guestHandle);
        if (raw) {
          auto *hdr = reinterpret_cast<XDISPATCHER_HEADER *>(raw);
          sem = TryQueryKernelObject<Semaphore>(*hdr);
          if (sem) {
            resBranch = "try-query-header";
          } else if (g_userHeap.IsPhysicalArenaPtr(raw)) {
            // CreateKernelObject product living in the physical arena - the
            // same pointer Wait's GetKernelObject raw-fallback returns.
            //
            // CONSOLE-CORRECT HANDLE (2026-10-21, fix_typebyte): the handle
            // IS the dispatcher header (GetKernelHandle ->
            // MapVirtual(&obj->header)), so `raw` is the HEADER, not a
            // Semaphore wrapper: casting it and calling Release() on it is a
            // wild virtual call through a garbage vtable.  The KernelObject
            // wrapper sits KernelObjectHeaderOffset() BELOW the header (the
            // C++ vptr is at the wrapper's base), so recover it by
            // subtracting that offset.  MEASURED: this branch IS reached -
            // build/w842.log "RELSEMA-RES #27 guest=B98EE040
            // branch=physical-arena-reinterpret live=1".
            auto *host = reinterpret_cast<Semaphore *>(
                reinterpret_cast<uint8_t *>(raw) - KernelObjectHeaderOffset());
            if (host->IsValid()) {
              sem = host;
              resBranch = "physical-arena-reinterpret";
            } else {
              resBranch = "physical-arena-invalid";
            }
          } else {
            resBranch = "raw-unusable";
          }
        } else {
          resBranch = "translate-null";
        }
      }
    } else {
      resBranch = "not-kernel-object";
    }
  }
  // Guest-owned XKSEMAPHORE headers (KeInitializeSemaphore path). Only mint
  // a wrapper when we did NOT resolve an identity object above.
  //
  // 2026-10-21 (fix_dpc): ONE REGISTRY. The canonical wrapper for this
  // dispatcher address wins, whatever its class. If it is an EVENT (the
  // guest's own dispatcher headers are type 0/1 - see the SEMA-FALLBACK row
  // in w838.log) then the waiter is parked on THAT event, so the release is
  // delivered as a set on it: that is the only action that can wake the
  // waiter, and minting a phantom semaphore here would guarantee the loss
  // (audit C17/C19).
  if (!sem) {
    if (auto *ev = TryQueryKernelObject<Event>(Handle->Header)) {
      ev->Set();
      resBranch = "canonical-event-set";
      MCLA_LOG_WARN("RELSEMA-EVENTSET guest={:08X} rel={} lr={:08X} "
                    "(canonical wrapper is an EVENT - set, not released)",
                    static_cast<uint32_t>(reinterpret_cast<const uint8_t *>(Handle) -
                                          mcla::kernel::g_memory.base),
                    ReleaseCount,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    } else {
      sem = QueryKernelObject<Semaphore>(Handle->Header);
      resBranch = "MINT-QueryKernelObject";
    }
  }

  // F-588: report the branch that actually won, per handle, bounded. This is
  // the measurement the hardcoded res= text was pretending to be.
  // F-589: also print the RESOLVED POINTER and the CURRENT COUNT. handle =
  // hostPtr - 0x100000000, so handle 0xC5400280 must resolve to 0x1C5400280.
  // The SEMA-wait/SEMA-release probe rows at this=0x1c6420280 belong to a
  // DIFFERENT handle (0xC6420280) - one handle resolving to two pointers, or a
  // count that never leaves 0, is the wake-loss; this line shows which.
  {
    static std::atomic<uint32_t> s_resLogs{0};
    const uint32_t rn = s_resLogs.fetch_add(1) + 1;
    if (rn <= 60 || (rn % 500) == 0) {
      const uint32_t gh =
          static_cast<uint32_t>(reinterpret_cast<const uint8_t *>(Handle) -
                                mcla::kernel::g_memory.base);
      const bool live = (sem != nullptr) && sem->IsValid();
      const uint32_t sc =
          live ? sem->count.load(std::memory_order_relaxed) : 0xFFFFFFFFu;
      MCLA_LOG_WARN("RELSEMA-RES #{} guest={:08X} branch={} live={} rel={} "
                    "sem={} cnt={} lr={:08X}",
                    rn, gh, resBranch, live ? 1 : 0, ReleaseCount,
                    static_cast<const void *>(live ? sem : nullptr), sc,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  // p2f crash-2 guard: the preload completion releases C9B36F00 after the
  // worker ran its build pass; lazy-wrap can hand back a stale/destroyed
  // wrapper whose vptr is garbage (observed __RTDynamicCast AV with
  // Param[1]=-8: vtable read of a null/freed host object right after
  // NtReleaseSemaphore+0x2A9). A semaphore release that cannot resolve a
  // live object is a no-op wake — never a host crash. Log and succeed.
  if (!sem || !sem->IsValid()) {
    static std::atomic<uint32_t> s_relDead{0};
    const uint32_t dn = s_relDead.fetch_add(1) + 1;
    if (dn <= 20 || (dn % 500) == 0) {
      const uint32_t guestHandle =
          static_cast<uint32_t>(reinterpret_cast<const uint8_t *>(Handle) -
                                mcla::kernel::g_memory.base);
      MCLA_LOG_WARN("RELSEMA-DEAD #{:03} guest={:08X} count={} lr={:08X} "
                    "(no live wrapper — no-op release)",
                    dn, guestHandle, ReleaseCount,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
    if (PreviousCount != nullptr)
      *PreviousCount = 0;
    return STATUS_SUCCESS;
  }

  uint32_t previousCount;
  // F-852 (fix_sema): the LIVE-count census on the RELEASE side, so the
  // release and the wait can be compared by OBJECT POINTER and by COUNT.  A
  // release that lands on a different wrapper than the one a waiter is
  // parked on is the wake-loss, and it is invisible in every row that only
  // prints a handle (the F-370 row) or a count taken at a different moment.
  {
      const uint32_t relHandle = static_cast<uint32_t>(
          reinterpret_cast<const uint8_t *>(Handle) - mcla::kernel::g_memory.base);
      uint32_t c = 0, mx = 0, w = 0;
      SemCntSnapshot(sem, &c, &mx, &w);
      g_semCntReleases.fetch_add(1, std::memory_order_relaxed);
      SemCntRow("RELEASE-BEFORE", relHandle, sem, c, mx, w, ReleaseCount,
                static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                false);
  }
  sem->Release(ReleaseCount, &previousCount);
  {
      const uint32_t relHandle = static_cast<uint32_t>(
          reinterpret_cast<const uint8_t *>(Handle) - mcla::kernel::g_memory.base);
      uint32_t c = 0, mx = 0, w = 0;
      SemCntSnapshot(sem, &c, &mx, &w);
      SemCntRow("RELEASE-AFTER", relHandle, sem, c, mx, w, ReleaseCount,
                static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0),
                false);
  }

  if (PreviousCount != nullptr)
    *PreviousCount = previousCount;

  return STATUS_SUCCESS;
}

void NtWaitForMultipleObjectsEx() { LOG_UTILITY("!!! STUB !!!"); }

// ===========================================================================
// F-840 (2026-10-21) -- THE VOID-IMPORT BATCH, part 4: RtlCompareStringN.
//
// WAS: `void RtlCompareStringN() { LOG_UTILITY("!!! STUB !!!"); }`.
//
// THE DEFECT, from the guest's own bytes.  The import thunk is 0x827BDA34 and
// the guest calls it from 11 sites (tools/ppc_xrefs.py calls 0x827BDA34) --
// the most-called member of this defect class.  The shape at 0x82450258
// (generated/ppc_xenon/ppc_recomp.81.cpp:84-102, raw bytes confirmed with
// tools/ppc_disasm.py 0x82450250 30):
//
//   82450240  lis  r11,8207
//   82450244  lwz  r3,4(r31)    ; r3 = string 1
//   82450248  li   r7,1         ; r7 = case-insensitive
//   8245024C  addi r5,r11,-22856 ; r5 = string 2 (0x8206A6B8 = "d:")
//   82450250  li   r6,2         ; r6 = length of string 2
//   82450254  li   r4,2         ; r4 = length of string 1
//   82450258  bl   827BDA34
//   8245025C  cmpi cr0,r3,0
//   82450260  bne  -> 8245026C  ; r3 != 0 => "the strings DIFFER"
//
// So the guest's contract is: r3 == 0 means EQUAL, r3 != 0 means DIFFERENT.
// The argument order is (string1, len1, string2, len2, caseInsensitive) --
// r3, r4, r5, r6, r7 -- measured at all 11 sites.
//
// ALL 11 SITES PASS caseInsensitive == 1 (r7 == 1 at every one of them:
// recomp.81.cpp:88, :119, :159, :6540, :6608, :9230, :13256, :13356,
// :13390, :25516 and recomp.82.cpp:2596), so the compare is ALWAYS
// case-insensitive in this guest.
//
// With the void stub, r3 on return was still the string pointer (non-zero), so
// the guest ALWAYS reported "different" and NEVER reported "equal".  The
// guest's string comparison was a constant false.
//
// THE CONSOLE'S BEHAVIOUR, from the reference:
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_rtl.cc:117-137
//     dword_result_t RtlCompareStringN_entry(lpstring_t string_1,
//                                             dword_t string_1_len,
//                                             lpstring_t string_2,
//                                             dword_t string_2_len,
//                                             dword_t case_insensitive)
//   -> the ORDERING, 0 when the two are equal; case-insensitive when the flag
//      is set (the reference uses xe_strncasecmp, which is _strnicmp on
//      Windows: ASCII case folding).
// The reference treats a length of 0xFFFF as "use strlen"
// (xboxkrnl_rtl.cc:125-130); that is reproduced here.
//
// ONE DOCUMENTED DIFFERENCE FROM THE REFERENCE.  The reference computes the
// comparison length as min(string_1_len, string_2_len) from the ORIGINAL
// lengths and then calls strncasecmp, which STOPS at a NUL
// (xboxkrnl_rtl.cc:131-134).  This implementation compares exactly N bytes and
// does not stop at a NUL, which is what the console's RtlCompareStringN does.
// The two differ only when a stated length runs past the string's terminator,
// which none of the guest's 11 measured call sites does (every length there is
// an exact strlen or a stored byte count).
//
// FALSIFIER.  The guest must now be able to take its EQUAL branch: at
// recomp.81.cpp:130-133 (`beq -> 82450264`, which returns 1) and at
// recomp.81.cpp:99-102 (`bne` must NOT be taken when the strings match).  A
// concrete check: the guest's comparison of "d:" against "d:" at 0x82450258
// must return 0, so the `bne` at 82450260 is NOT taken.
// ===========================================================================
// A REAL instrument for RtlCompareStringN.  The OLD void stub printed NOTHING
// in a release build (LOG_UTILITY expands to nothing unless _DEBUG is
// defined, .research/UnleashedRecomp/UnleashedRecomp/os/logger.h:14-18), so
// "0 rows" proved nothing about this import.  This line prints on every call
// the body answers, so a soak can show an EQUAL verdict (result == 0) -- which
// is what the void stub could never produce (AGENTS.md rule 19).
static void RtlCompareStringNCensus(uint32_t length1, uint32_t length2,
                                    uint32_t caseInsensitive,
                                    uint32_t result) {
  static std::atomic<uint32_t> s_census{0};
  const uint32_t n = s_census.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 20 || (n % 1000) == 0) {
    MCLA_LOG_INFO("RTL-CMPN #{} lr={:08X} len1={} len2={} ci={} -> result=0x{:X} "
                  "({})",
                  n, static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0u),
                  length1, length2, caseInsensitive, result,
                  result == 0 ? "EQUAL" : "DIFFERENT");
  }
}

uint32_t RtlCompareStringN(char *string1, uint32_t string1Len, char *string2,
                           uint32_t string2Len, uint32_t caseInsensitive) {
  if (!string1 || !string2) {
    // A null string is not equal to anything (and must not crash the host).
    return 0xFFFFFFFFu;
  }

  // The reference's 0xFFFF sentinel means "the length is the string's own
  // length" (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_rtl.cc:125).
  // The scan is BOUNDED so a guest string without a terminator cannot walk the
  // host off the end of the guest window.
  constexpr uint32_t kMaxAutoLength = 4096;
  if (string1Len == 0xFFFFu) {
    string1Len = 0;
    while (string1Len < kMaxAutoLength && string1[string1Len] != '\0') {
      string1Len++;
    }
  }
  if (string2Len == 0xFFFFu) {
    string2Len = 0;
    while (string2Len < kMaxAutoLength && string2[string2Len] != '\0') {
      string2Len++;
    }
  }

  const uint32_t count = string1Len < string2Len ? string1Len : string2Len;

  auto fold = [caseInsensitive](uint8_t c) -> int {
    if (!caseInsensitive) {
      return static_cast<int>(c);
    }
    // ASCII case folding, which is what _strnicmp does on Windows
    // (.research/xenia/src/xenia/base/string.cc:24-30).
    if (c >= 'A' && c <= 'Z') {
      return static_cast<int>(c - 'A' + 'a');
    }
    return static_cast<int>(c);
  };

  for (uint32_t i = 0; i < count; i++) {
    const int a = fold(static_cast<uint8_t>(string1[i]));
    const int b = fold(static_cast<uint8_t>(string2[i]));
    if (a != b) {
      // The console returns the difference of the first differing characters.
      const uint32_t difference =
          static_cast<uint32_t>(static_cast<int32_t>(a - b));
      RtlCompareStringNCensus(string1Len, string2Len, caseInsensitive,
                              difference);
      return difference;
    }
  }

  // Equal over the compared prefix.
  RtlCompareStringNCensus(string1Len, string2Len, caseInsensitive, 0);
  return 0;
}

void _snprintf_x() { LOG_UTILITY("!!! STUB !!!"); }

void StfsControlDevice() {
  // STFS control device - return success
  if (!g_ppcContext)
    return;
  g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
}

void StfsCreateDevice() {
  if (!g_ppcContext)
    return;
  g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
}

// Fatal error dispatcher override: the generated weak function has an infinite
// loop. We provide a strong definition that terminates the game instead of
// infinite-looping.
void sub_821BD618(PPCContext &ctx, uint8_t *base) {
  (void)base;
  // Original dispatcher: reads handler from slot 0x8285FEA0, calls it if
  // non-zero, then infinite loops. The callers expect this to NEVER return. We
  // dump state first so we know who routed us here, then terminate.
  MCLA_LOG_ERROR("Fatal error dispatcher invoked - terminating game");
  MCLA_LOG_ERROR("  fatal-dispatch regs: lr=0x{:08X} r1=0x{:08X} r3=0x{:08X} "
                 "r4=0x{:08X} r5=0x{:08X} r6=0x{:08X}",
                 static_cast<uint32_t>(ctx.lr), ctx.r1.u32, ctx.r3.u32,
                 ctx.r4.u32, ctx.r5.u32, ctx.r6.u32);

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t slotValue = 0;
  if (mem.ReadU32BE(0x8285FEA0, &slotValue))
    MCLA_LOG_ERROR("  slot 0x8285FEA0 = 0x{:08X}", slotValue);

  // r3 usually points at the fatal message string - read it straight out
  if (ctx.r3.u32 >= 0x82000000u && ctx.r3.u32 < 0x83000000u) {
    if (const void *p = mem.Translate(ctx.r3.u32))
      MCLA_LOG_ERROR("  fatal message: '{}'", static_cast<const char *>(p));
    if (ctx.r4.u32 >= 0x82000000u && ctx.r4.u32 < 0x83000000u) {
      if (const void *p4 = mem.Translate(ctx.r4.u32))
        MCLA_LOG_ERROR("  fatal aux r4: '{}'", static_cast<const char *>(p4));
    } else if (ctx.r4.u32 >= 0x8E000000u && ctx.r4.u32 < 0x90000000u) {
      // varargs: %s value passed directly - r4 IS the char* (stack copy)
      if (const void *ps = mem.Translate(ctx.r4.u32))
        MCLA_LOG_ERROR("  fatal %%s arg: '{}'", static_cast<const char *>(ps));
      uint32_t strPtr = 0;
      if (mem.ReadU32BE(ctx.r4.u32, &strPtr) && strPtr >= 0x82000000u &&
          strPtr < 0x83000000u) {
        if (const void *ps2 = mem.Translate(strPtr))
          MCLA_LOG_ERROR("  fatal %s indirection -> '{}'",
                         static_cast<const char *>(ps2));
      }
    }
  }

  // EABI frames: back chain at [sp], saved LR at [sp+4].
  uint64_t lr = ctx.lr;
  uint32_t sp = ctx.r1.u32;
  for (int depth = 0; depth < 16; ++depth) {
    MCLA_LOG_ERROR("  fatal chain[{}]: lr=0x{:08X} sp=0x{:08X}", depth,
                   static_cast<uint32_t>(lr), sp);
    uint32_t nextSp = 0;
    uint32_t nextLr = 0;
    if (sp == 0 || !mem.ReadU32BE(sp, &nextSp) ||
        !mem.ReadU32BE(sp + 4, &nextLr))
      break;
    if (nextSp <= sp || (nextSp & 3) != 0)
      break;
    lr = nextLr;
    sp = nextSp;
  }
  spdlog::default_logger()->flush();

  // W0: NEVER ExitProcess from the guest fatal dispatcher. The host window
  // + render thread must outlive any guest pause. Log and park this thread.
  {
    char msgBuf[192] = {0};
    if (ctx.r3.u32 >= 0x82000000u && ctx.r3.u32 < 0x83000000u) {
      if (const void *p = mem.Translate(ctx.r3.u32))
        std::snprintf(msgBuf, sizeof(msgBuf), "%s",
                      static_cast<const char *>(p));
    }
    MCLA_LOG_WARN("FATAL-SOFT: '{}' lr={:08X} — guest paused, host window stays",
                  msgBuf, static_cast<uint32_t>(ctx.lr));
    // w24: Resource fatal from the place-pass walk (lr=8260A8B0 A830→D2378,
    // lr=82184514 84458→D2378) must soft-park and RETURN so the guest can
    // retry — the A830/84458 tails already take delta-0 after D2378 returns.
    // Also soft-park swfOBJECT::Fixup unknown-type (lr=825EF1FC after FDA90)
    // so EF100 can finish the entry loop and write the real swfC vtable.
    // Other fatals keep the permanent park (never ExitProcess).
    const uint32_t lr32 = static_cast<uint32_t>(ctx.lr);
    const bool resourceFatal =
        lr32 == 0x8260A8B0u || lr32 == 0x82184514u ||
        lr32 == 0x821D2378u ||
        std::strstr(msgBuf, "Resource") != nullptr ||
        std::strstr(msgBuf, "unknown type") != nullptr ||
        std::strstr(msgBuf, "Fixup") != nullptr ||
        lr32 == 0x825EF1FCu || lr32 == 0x825EF1A4u || lr32 == 0x825EF1DCu;
    spdlog::default_logger()->flush();
    if (resourceFatal) {
      static std::atomic<uint32_t> s_resPark{0};
      const uint32_t pn = s_resPark.fetch_add(1) + 1;
      MCLA_LOG_WARN("FATAL-SOFT-RESOURCE-PARK #{} lr={:08X} r3={:08X} "
                    "r5={:08X} — soft-park return (guest retry)",
                    pn, lr32, ctx.r3.u32, ctx.r5.u32);
      spdlog::default_logger()->flush();
      return;
    }
    while (true) {
      Sleep(1000);
    }
  }
}

// CRT init function that unconditionally calls fatal dispatcher - make it a
// no-op
void sub_821305B8_NoOp() {
  // This CRT init function unconditionally calls the fatal error dispatcher.
  // We NOP it to allow boot to proceed past early CRT init.
}

void NtFlushBuffersFile() { LOG_UTILITY("!!! STUB !!!"); }

void KeQuerySystemTime(be<uint64_t> *time) {
  constexpr int64_t FILETIME_EPOCH_DIFFERENCE = 116444736000000000LL;

  auto now = std::chrono::system_clock::now();
  auto timeSinceEpoch = now.time_since_epoch();

  int64_t currentTime100ns =
      std::chrono::duration_cast<
          std::chrono::duration<int64_t, std::ratio<1, 10000000>>>(
          timeSinceEpoch)
          .count();
  currentTime100ns += FILETIME_EPOCH_DIFFERENCE;

  *time = currentTime100ns;
}

void RtlTimeToTimeFields() { LOG_UTILITY("!!! STUB !!!"); }

// ---------------------------------------------------------------------------
// RtlFreeAnsiString -- F-609, partially real, partially a counted refusal. The
// brief listed it beside ExFreePool as "the same shape"; verified, it is NOT
// the same shape, and the difference matters.
//
// WHAT XENIA DOES, cited: .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_rtl.cc:155-163
//   void RtlFreeAnsiString_entry(pointer_t<X_ANSI_STRING> string) {
//     if (string->pointer) { kernel_memory()->SystemHeapFree(string->pointer); }
//     string->reset();
//   }
// Two actions: free the buffer, then reset the struct. So yes, it must really
// release -- the reference implementation does.
//
// WHY ONLY THE SECOND HALF IS SAFE HERE, and this is the load-bearing finding.
// The ONLY producer of an XANSI_STRING reachable in this tree is
// RtlInitAnsiString in this same file, and it BORROWS -- it stores the
// caller's own pointer without copying anything:
//   src/kernel/imports.cpp:667-673
//     destination->Buffer = xpointer<char>(source);
// There is no RtlAllocateAnsiString in this file and none in the guest's
// import table, so no XANSI_STRING buffer here is ever heap-owned. Calling
// g_userHeap.Free on a borrowed pointer would be a use-after-free of a
// CALLER's buffer -- converting a leak into heap corruption, which is strictly
// worse than the stub and is precisely the "never stack a mitigation" rule.
//
// So: the free is attempted only when the buffer is provably one of OURS, and
// when it is not, the refusal is NAMED and counted rather than silent. The
// struct reset is done unconditionally, because that much is real work we
// genuinely perform and it is the guest-visible effect of "this string is
// dead" (Xenia's `string->reset()`, xboxkrnl_rtl.cc:161).
//
// REACHABILITY, so the next session does not spend time here:
// `RtlFreeAnsiString` is ABSENT from generated/ppc_xenon/ppc_func_mapping.cpp,
// which is the guest's static import table. Combined with XexGetProcedureAddress
// being an unwired stub in this file, there is no path by which default.xex can
// reach this export. The GUEST_FUNCTION_HOOK below is dead wiring.
// ---------------------------------------------------------------------------
namespace {
std::atomic<uint64_t> g_ansiFreeSeen{0};
std::atomic<uint64_t> g_ansiFreeFreed{0};
std::atomic<uint64_t> g_ansiFreeBorrowed{0};
} // namespace

void RtlFreeAnsiString(XANSI_STRING *string) {
  const uint64_t seen =
      g_ansiFreeSeen.fetch_add(1, std::memory_order_relaxed) + 1;

  if (string == nullptr) {
    return;
  }

  // `Buffer.ptr` is a be<uint32_t> holding the GUEST virtual address, and
  // be<T>::value is the RAW big-endian word (src/kernel/xbox.h:28-70) -- on an
  // x86 host that is the byte-reversed form, NOT the address. `get()` is the
  // one that gives back the guest VA; the same is true of the implicit
  // conversion, which is what NtCreateFile at :715 uses.
  const uint32_t buf = static_cast<uint32_t>(string->Buffer.ptr.get());
  if (buf == 0) {
    // Nothing to release. Xenia's `if (string->pointer)` guard, verbatim.
    string->Length.set(0);
    string->MaximumLength.set(0);
    string->Buffer = xpointer<char>(nullptr);
    return;
  }

  // Is this buffer one of ours? The same IsLiveAllocation predicate
  // ExFreePool above uses: if it is a live fragment of a heap arena, the
  // allocation is ours and releasing it is correct. If it is not, it is a
  // caller's buffer that RtlInitAnsiString borrowed, and freeing it would be a
  // use-after-free -- so we refuse, by name, and say so.
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  void *host = mem.Translate(buf);
  Heap::LiveProbe probe{};
  bool ours = false;
  if (host != nullptr) {
    ours = g_userHeap.IsLiveAllocation(g_userHeap.heapArenaBase,
                                       g_userHeap.heapArenaSize, host, &probe) ||
           g_userHeap.IsLiveAllocation(g_userHeap.physArenaBase,
                                       g_userHeap.physArenaSize, host, &probe);
  }

  if (ours) {
    mem.Free(buf, 0);
    g_ansiFreeFreed.fetch_add(1, std::memory_order_relaxed);
  } else {
    g_ansiFreeBorrowed.fetch_add(1, std::memory_order_relaxed);
    if (seen <= 8 || (seen % 200) == 0) {
      const uint32_t glr =
          g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
      MCLA_LOG_WARN("ANSI-FREE #{} buf={:08X} -> REFUSED the free: not a live "
                    "fragment of any heap arena, so RtlInitAnsiString borrowed "
                    "it (src/kernel/imports.cpp:667-673) and it is the caller's "
                    "buffer; struct reset only, bytes kept. seen={} freed={} "
                    "borrowed={} glr={:08X}",
                    seen, buf, seen,
                    g_ansiFreeFreed.load(std::memory_order_relaxed),
                    g_ansiFreeBorrowed.load(std::memory_order_relaxed), glr);
    }
  }

  // The reset is real work in both arms -- Xenia's `string->reset()`,
  // xboxkrnl_rtl.cc:161. void, so there is no status to launder here; that is
  // why this entry is only half the defect the brief described.
  string->Length.set(0);
  string->MaximumLength.set(0);
  string->Buffer = xpointer<char>(nullptr);
}

void RtlUnicodeStringToAnsiString() { LOG_UTILITY("!!! STUB !!!"); }

void RtlInitUnicodeString() { LOG_UTILITY("!!! STUB !!!"); }

// ExTerminateThread (2026-10-21, fix_irq2, item 5): NOW REAL.
//
// CONSOLE BEHAVIOUR, and it is NOT "terminate some other thread":
//   .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_threading.cc:155-159
//       dword_result_t ExTerminateThread_entry(dword_t exit_code) {
//         XThread* thread = XThread::GetCurrentThread();
//         // NOTE: this kills us right now. We won't return from it.
//         return thread->Exit(exit_code);
//       }
//   The single argument is the EXIT CODE, and the thread that dies is the
//   CALLING thread.
//
// THE GUEST'S OWN BYTES agree, and there is exactly one call site
// (`py -3 tools/ppc_xrefs.py calls 0x827BD864`):
//   0x8242F834  li r3,0              ; exit code 0
//   0x8242F838  bl 827BD864          ; __imp__ExTerminateThread(0)
//   0x8242F83C  sync
//   i.e. the thread tears ITSELF down, inside sub_8242F748.
//
// The old body was a refusal (`LOG_UTILITY("!!! STUB !!!")` + a census),
// justified by three obstacles.  Two of them are gone, one is not:
//
//  1. AN UNWIND TARGET -- STILL A REAL CONSTRAINT, but it no longer blocks
//     this.  The recompiler emits setjmp/longjmp only for the two reserved
//     import addresses (.research/XenonRecomp/XenonRecomp/recompiler.cpp:
//     523-535 gates longjmp on config.longJmpAddress and setjmp on
//     config.setJmpAddress, and config/mcla_xenonrecomp.toml sets NEITHER),
//     so the guest cannot be unwound with longjmp and a C++ exception would
//     unwind through frames with no landing pads.  The console's mechanism
//     ("we won't return from it") does NOT need an unwind: it simply does not
//     come back.  The host's equivalent is TerminateThread on the CURRENT
//     host thread, which stops the thread at the call without unwinding
//     anything.  Per rule 2 mcla_xenonrecomp.toml is not ours to edit, and
//     the setjmp/longjmp route stays blocked; this edit does not need it.
//  2. A THREAD REGISTRY -- NOT NEEDED for the console's semantics.  The
//     console kills the CALLING thread, so there is no other thread to find,
//     no handle to resolve and no waiter to release.  (The old note assumed
//     the export took a thread HANDLE; the guest's bytes and the reference
//     both say it takes an EXIT CODE.)
//  3. A PC-side entry for the teardown -- not needed either, for the same
//     reason.
//
// TRADE-OFF, stated: TerminateThread abandons the thread's C++ frames, so
// the guest thread's GuestThreadContext destructor (which frees the guest
// thread's PCR/TLS/TEB/stack block, guest_thread.cpp:183-186) does not run
// and that block leaks, and any host lock the thread happened to hold stays
// held.  The console's thread->Exit() has the same shape: it tears the
// thread down without running the thread's cleanup.  The alternative --
// refusing and letting the guest continue -- is NOT the console's behaviour
// and leaves every waiter on that thread blocked forever.
//
// FALSIFIER: a soak in which the guest reaches 0x8242F838 must show an
// EX-TERMINATE row and the thread's own subsequent activity must STOP
// (no further rows with that tid).  A soak with EX-TERMINATE rows and the
// thread still running means TerminateThread failed and the fallback path
// ran.
uint32_t ExTerminateThread(uint32_t exitCode) {
  static std::atomic<uint32_t> s_exTerm{0};
  const uint32_t n = s_exTerm.fetch_add(1) + 1;
  if (n <= 40 || (n % 500) == 0)
    MCLA_LOG_WARN("EX-TERMINATE #{} exit_code={} tid={:08X} lr={:08X} - "
                  "terminating THIS host thread now (console: xenia "
                  "xboxkrnl_threading.cc:155-159, 'this kills us right now')",
                  n, exitCode, GetCurrentThreadId(),
                  static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));

#if defined(_WIN32)
  // TerminateThread on the CURRENT thread: the thread stops at this call and
  // never returns, exactly like the console's thread->Exit().  The exit code
  // is the guest's r3.
  if (TerminateThread(GetCurrentThread(), static_cast<UINT>(exitCode)) != 0) {
    // Unreachable in practice: TerminateThread on the calling thread does
    // not return.  If it ever did, say so rather than falling through.
    MCLA_LOG_ERROR("EX-TERMINATE #{} TerminateThread returned - the thread "
                   "was NOT killed",
                   n);
    return 0;
  }
#endif
  // TerminateThread failed (or is unavailable): refuse loudly, the way the
  // old body did, and let the guest continue.
  LOG_UTILITY("!!! STUB !!!");
  MCLA_LOG_ERROR("EX-TERMINATE #{} could not terminate the thread - REFUSING "
                 "and returning; the guest continues on this thread",
                 n);
  return 0;
}

uint32_t ExCreateThread(be<uint32_t> *handle, uint32_t stackSize,
                        be<uint32_t> *threadId, uint32_t xApiThreadStartup,
                        uint32_t startAddress, uint32_t startContext,
                        uint32_t creationFlags) {
  // THREAD-CREATE CENSUS (session 10): completer threads must be visible.
  // The async-op drainer Function_823EC990 family never ran - verify
  // whether its spawn ever happens (LOGF_UTILITY is compiled out).
  {
    static std::atomic<uint32_t> s_threadCreates{0};
    const uint32_t n = s_threadCreates.fetch_add(1) + 1;
    if (n <= 60) {
      MCLA_LOG_INFO(
          "THREAD-CREATE #{} start={:08X} ctx={:08X} flags={:08X} lr={:08X}", n,
          startAddress, startContext, creationFlags,
          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      // Trampoline 0x821C91C8 copies {proc,arg} (44 bytes) from the ctx
      // node onto its stack then bctrls - dump the node so the REAL
      // thread procedures become visible.
      if (startAddress == 0x821C91C8u && startContext != 0) {
        auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
        std::string words;
        for (uint32_t off = 0; off < 48; off += 4) {
          uint32_t w = 0;
          (void)mem.ReadU32BE(startContext + off, &w);
          words += fmt::format(" {:08X}", w);
        }
        MCLA_LOG_INFO("THREAD-NODE #{} @ {:08X}:{}", n, startContext, words);
      }
      // TU83 worker thread census (Lead 1/3)
      if (startAddress == 0x824569C8u || startAddress == 0x823F69C8u) {
        MCLA_LOG_WARN(
            "THREAD-CREATE TU83 WORKER #{} start={:08X} ctx={:08X} "
            "flags={:08X} lr={:08X}",
            n, startAddress, startContext, creationFlags,
            static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
      }
    }
  }

  LOGF_UTILITY("0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}",
               handle ? handle->get() : 0, stackSize,
               threadId ? threadId->get() : 0, xApiThreadStartup, startAddress,
               startContext, creationFlags);

  uint32_t hostThreadId;

  GuestThreadHandle *hThread = GuestThread::Start(
      {startAddress, startContext, creationFlags}, &hostThreadId);
  // F-799 (2026-10-17, w791): register the thread object in the identity
  // map -- the same two steps NtCreateFile already performs for file
  // objects (imports.cpp, the "Publish the object in the identity map"
  // block). Without this EVERY thread handle is unresolvable:
  // TryQueryKernelObject misses (the entry never existed), and the raw
  // fallback in ResolveKernelObjectSafe reads handle+8 -- which for a
  // host-allocated object is the upper half of the 8-byte vptr, NOT
  // Flink -- so the OBJECT_SIGNATURE proof fails and
  // ObReferenceObjectByHandle returns STATUS_INVALID_HANDLE for the
  // title's own thread handles. Measured in w791: the streaming worker
  // (THREAD-CREATE #17, start=821C91C8) references its own thread object
  // BE108C40 three times at startup (lr=82131D64/82131DE4/82131E78), all
  // three fail, and the main thread then parks on SEMA #39 (BE108BC0)
  // forever because the worker never reaches the code that releases it.
  // identityHdrAddr is what DestroyKernelObject (xdm.cpp:12-13) erases
  // on, so a closed thread's entry cannot outlive it.
  hThread->identityHdrAddr = GetKernelHandle(hThread);
  {
    std::lock_guard guard{g_kernelLock};
    WrapperIdentityMap()[hThread->identityHdrAddr] = {hThread,
                                                     hThread->header.Type};
  }
  uint32_t kernelHandle = hThread->identityHdrAddr;
  if (handle)
    handle->set(kernelHandle);

  if (threadId)
    threadId->set(hostThreadId);

  return 0;
}

void IoInvalidDeviceRequest() { LOG_UTILITY("!!! STUB !!!"); }

void ObReferenceObject() { LOG_UTILITY("!!! STUB !!!"); }

void IoCreateDevice() { LOG_UTILITY("!!! STUB !!!"); }

void IoDeleteDevice() { LOG_UTILITY("!!! STUB !!!"); }

uint32_t ExAllocatePoolTypeWithTag(uint32_t poolType, uint32_t numberOfBytes,
                                   uint32_t tag, uint32_t lookasideListEx) {
  LOGF_UTILITY("poolType=0x{:X} size=0x{:X} tag=0x{:X} lookaside=0x{:X}",
               poolType, numberOfBytes, tag, lookasideListEx);
  void *ptr = g_userHeap.Alloc(numberOfBytes);
  if (!ptr)
    return 0;
  uint32_t guestAddr =
      mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(ptr);
  // Session-27 window census (deterministic swf object 0x88825500).
  if ((guestAddr & 0xFFFF0000u) == 0x88820000u) {
    uint32_t lr = 0;
    if (const PPCContext *c = GetPPCContext())
      lr = static_cast<uint32_t>(c->lr);
    MCLA_LOG_WARN("ALLOC-WIN Pool -> {:08X} size={:#x} tag={:08X} lr={:08X}",
                  guestAddr, numberOfBytes, tag, lr);
  }
  MmTrackAllocationSize(guestAddr, numberOfBytes);
  return guestAddr;
}

void RtlTimeFieldsToTime() { LOG_UTILITY("!!! STUB !!!"); }

void IoCompleteRequest() { LOG_UTILITY("!!! STUB !!!"); }

void RtlUpcaseUnicodeChar() { LOG_UTILITY("!!! STUB !!!"); }

void ObIsTitleObject() { LOG_UTILITY("!!! STUB !!!"); }

void IoCheckShareAccess() { LOG_UTILITY("!!! STUB !!!"); }

void IoSetShareAccess() { LOG_UTILITY("!!! STUB !!!"); }

void IoRemoveShareAccess() { LOG_UTILITY("!!! STUB !!!"); }

// ===========================================================================
// SYNTH-XNET -- A FABRICATION. This block, and only this block, is synthetic.
// Read this before "fixing" it, and do not widen it to the socket family.
//
// ---------------------------------------------------------------------------
// WHAT THE TITLE ACTUALLY DOES WITH THE XNetStartup RESULT (measured)
// ---------------------------------------------------------------------------
// There is exactly ONE call of the XNetStartup thunk in the image:
//   `python tools/ppc_xrefs.py calls 0x8244A548` -> 1 site, 0x821E44F0, inside
//   sub_821E44A0. `calls 0x821E44A0` -> 2 sites, 0x821D5F68 (a bare
//   tail-branch thunk) and 0x82500F70. Neither caller inspects anything;
//   sub_821E44A0 owns the only check on the result, and it is:
//     0x821E44F0  bl   8244A548
//     0x821E44F4  cmpi cr6,r3,0
//     0x821E44F8  bc    (branch IF EQUAL -- verified against w659.log below)
//     0x821E44FC  lis r11,8201 / addi r3,r11,32300 / bl 821BD618
//   with 0x82017E2C == "XNetStartup failed" (raw bytes, mcla_pe.bin +
//   0x17E2C, F-023). So: tested against zero exactly once, and a non-zero
//   answer is FATAL. There is no tolerance, no retry, no offline branch. The
//   branch polarity is not guessed: w659.log:305-316 shows the fatal printing
//   for a return of 0x32, i.e. the `bc` is "branch if equal". (`tools/
//   ppc_disasm.py` prints a raw BO/BI whose BI field it decodes wrong -- every
//   `cmpi cr6` / `bc ... bi=26` pair in this image is bo=12 => branch-if-equal,
//   bo=4 => branch-if-not-equal. The log is the arbiter.)
//
// This wrapper is the boot worker's step 2. sub_821BD7C0 stores two words,
// calls 821BD648, then 0x821BD7F8 -> 821D5F68 (this), then goes on to
// 821C06F0 / 82130000 / 821C45D8. w659.log:321 mirror stack
// f0=821E44F4 f1=821BD7FC f2=82132454: the refusal killed the whole boot, one
// second in, at "Fatal error dispatcher invoked" 0 -> 1.
//
// The same wrapper then does WinSock: `bl 8244A300` (0x827BD0F4 is
// __imp__NetDll_WSAStartup, generated/ppc_xenon/ppc_func_mapping.cpp:44815),
// fatal on non-zero with "InitWinSock - Couldn't find a usable WinSock DLL"
// (0x82017DF8), then requires WSADATA.wVersion == 0x0002 or fatals again
// (0x82017DB8). NetDll_WSAStartup above already returns 0 and already stores
// the echoed version word, so that half of the wrapper is already satisfied and
// nothing in this block is needed for it.
//
// The decisive question -- can the title proceed with startup succeeding and
// no server? YES, and statically so. XNetGetTitleXnAddr is a DIFFERENT export
// with 7 call sites (`calls 0x8244A670` -> 0x824E6148 x2, 0x824E61F0 x2,
// 0x825019B0, 0x82501A28, 0x82501AC0), every one of them inside the RakNet /
// "is there a network" helpers, and NONE of them on the boot path. It is also
// not a pointer return, so there is no NULL to dereference: the guest passes
// its own XNADDR buffer and tests the status word (sub_824E6148: r3 == 0 is
// the success branch at 0x824E6190-0x824E61B0) plus the abEnet bytes the
// guest itself copies out of that buffer at XNADDR+0x10. So the title reaches
// its menu with no server; it fails later, where the server is actually
// needed, and it fails there for an honest reason.
//
// ---------------------------------------------------------------------------
// IS A REAL IMPLEMENTATION POSSIBLE HERE? No, and the reason is structural.
// ---------------------------------------------------------------------------
// XNet is Xbox Live's session/broker layer, not a socket. There is no Live
// service to join and no peer to broker to; and the only networking primitive
// the guest has is NetDll_socket, which returns INVALID_SOCKET
// unconditionally (measured, and correct), so even a real XNet would have
// nothing to ride on. The reference implementation agrees and does not try:
//   .research/xenia/src/xenia/kernel/xam/xam_net.cc:172-191
//     NetDll_XNetStartup_entry -- copies the params, has the XNet construction
//     COMMENTED OUT at :181-188, and `return 0;` at :190.
// "XNet started, nothing behind it" is Xenia's own state. It is still a
// fabrication, and it is labelled as one here, with a trigger below.
//
// ---------------------------------------------------------------------------
// WHAT IS REAL IN THIS BLOCK
// ---------------------------------------------------------------------------
//  1. The 13 XNetStartupParams bytes are really read out of guest memory
//     through the checked helper with explicit byte reads, and really stored
//     host-side. Xenia asserts the same 13 bytes (xam_net.cc:154-168 and the
//     assert_true at :175) and stores the same struct (xam_net.cc:170, :176),
//     so state a guest could later read back through NetDll_XNetGetOpt
//     (xam_net.cc:206-222) genuinely exists here.
//  2. XNetGetTitleXnAddr really zeroes the caller's XNADDR, because the guest
//     does NOT initialise it before the call (0x824E6188 and 0x82501AE4 pass
//     an uninitialised stack buffer), so "do nothing" would hand the title
//     uninitialised guest stack. 36 bytes is the size the guest itself memsets
//     (`li r5,36` at 0x825019D0 and 0x82501AD0), not an assumed one.
//
// WHAT IS NOT REAL: the `return 0` in both functions. Nothing was started and
// no address exists. "XNetStartup succeeded" is a claim about a subsystem that
// does not exist, and the title believes it. Nothing here invents a server,
// an IP or a MAC.
//
// NOT DONE, DELIBERATELY: Xenia also plants a loopback ina and a 0xCC-filled
// 6-byte abEnet (xam_net.cc:455, :470) and says in the comment there that "a
// zero value will cause RakPeer::Startup to fail". That is deferred, because
// it is a SECOND fabrication for a code path the boot does not reach, and
// because reaching it honestly (as "we are not online") is the better failure.
// If the boot ever reaches RakPeer, that is the moment to reconsider it -- and
// the reconsideration is recorded at those two sites, not here.
//
// REMOVAL TRIGGER -- delete this whole block and restore the refusal
// (NetRefuse("XNetStartup") + return 0x32) exactly when ANY of these holds:
//   (a) a second native peer exists that can answer XNet session requests, so
//       a real XNet can be built and its real status returned;
//   (b) the title is run against a real Xbox Live service or a LAN bridge to
//       one (no such thing exists in this tree -- grep for it before assuming);
//   (c) the boot reaches code that needs a live session and fails there, in
//       which case the answer is (a), not a longer life for this stub.
// Until one of those holds, THE BOOT DEPENDS ON THE `return 0` BELOW.
//
// SIGNATURE (F-609 Task 3): both entries gained the leading `dllSelector`, and
// the old one-argument form was binding the WRONG REGISTER. The thunk at
// 0x8244A548 is `mr r4,r3 ; li r3,1 ; b 8244A490` -- the guest calls
// (1, params) -- so the old `NetDll_XNetStartup(void *xnaddr)` was reading the
// selector 1 as `xnaddr` and never saw the params at all. Same at 0x8244A670
// for XNetGetTitleXnAddr. That is the off-by-one the socket family's fix
// already removed everywhere else; these two were missed.
// ===========================================================================
namespace {
// SYNTH-XNET census. Attempts and outcomes are counted separately, by house
// rule. `attempts` is every entry into this block; `outcomes` is every entry
// that went on to return the fabricated success. They are equal by
// construction today; the moment they differ, a refusal path has been added
// and this comment is stale.
std::atomic<uint64_t> g_synthXnetAttempts{0};
std::atomic<uint64_t> g_synthXnetOutcomes{0};
std::atomic<uint64_t> g_synthXnetParamsCaptured{0};
std::atomic<uint32_t> g_synthXnetSizeOfStruct{0};
std::atomic<uint32_t> g_synthXnetFlags{0};

// 13 bytes. Xenia's XNetStartupParams is thirteen uint8_t
// (xam_net.cc:154-168) and the guest agrees: sub_821E44A0 builds it with
// `stb r9,80(r1)` where r9 = 13 (0x821E44CC/0x821E44E8), then `stb r8,81(r1)`
// where r8 = 1 (0x821E44D0/0x821E44EC).
constexpr uint32_t kXnetStartupParamsBytes = 13u;
// The XNADDR extent the guest zeroes itself with `li r5,36`
// (0x825019D0, 0x82501AD0, 0x82501A7C).
constexpr uint32_t kXnetXnAddrBytes = 36u;
const uint8_t kXnetZeroes[kXnetXnAddrBytes] = {};
} // namespace

uint32_t NetDll_XNetStartup(uint32_t dllSelector, const void *xnaddr) {
  const uint64_t attempt =
      g_synthXnetAttempts.fetch_add(1, std::memory_order_relaxed) + 1;

  // REAL: read the params the title actually filled in. Checked helper,
  // explicit byte granularity, no reinterpret_cast on guest data, no assert.
  bool paramsRead = false;
  if (xnaddr != nullptr) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t guestAddr = mem.MapVirtual(xnaddr);
    uint8_t params[kXnetStartupParamsBytes] = {};
    if (guestAddr != 0 && mem.ReadBytes(guestAddr, params, sizeof(params))) {
      paramsRead = true;
      g_synthXnetSizeOfStruct.store(params[0], std::memory_order_relaxed);
      g_synthXnetFlags.store(params[1], std::memory_order_relaxed);
      g_synthXnetParamsCaptured.fetch_add(1, std::memory_order_relaxed);
    }
  }

  // The marker. SYNTH-XNET advances on EVERY call; the line prints on the
  // house cadence (first 8, then every 200th) so a soak can attribute the
  // whole running title to this block.
  if (attempt <= 8 || (attempt % 200) == 0) {
    const uint32_t glr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    MCLA_LOG_WARN(
        "SYNTH-XNET #{} op=XNetStartup attempts={} outcomes={} "
        "params_captured={} sizeOfStruct={} flags={} selector={:08X} "
        "paramsRead={} -> returning 0 (SUCCESS) with NOTHING started behind it "
        "glr={:08X}",
        attempt, attempt,
        g_synthXnetOutcomes.load(std::memory_order_relaxed),
        g_synthXnetParamsCaptured.load(std::memory_order_relaxed),
        g_synthXnetSizeOfStruct.load(std::memory_order_relaxed),
        g_synthXnetFlags.load(std::memory_order_relaxed), dllSelector,
        paramsRead ? 1 : 0, glr);
  }
  g_synthXnetOutcomes.fetch_add(1, std::memory_order_relaxed);
  return 0; // <-- THE FABRICATION. Nothing was started. See the trigger above.
}

// F-609 Task 3: this does NOT return a pointer, and 0 is not NULL. It returns
// an XnAddrStatus word and fills the caller's XNADDR.
//
// F-845: THE PREVIOUS COMMENT HERE WAS INVERTED, AND THE INVERSION WAS THE
// BOOT'S OUTERMOST WALL.  It claimed "sub_824E6148 (0x824E6188-0x824E61B0) and
// sub_82501AC0 (0x82501AE4) both take the r3 == 0 branch as SUCCESS".
// **THE GUEST'S OWN BYTES SAY THE OPPOSITE.**  The emitted body of
// sub_824E6148 (generated/ppc_xenon/ppc_recomp.97.cpp:23046-23067) is:
//
//   23046: bl 0x8244a670        <- the XNet call
//   23049: cmplwi cr6,r3,0
//   23051: bne cr6,0x824e61b0  <- r3 != 0  => LEAVE THE LOOP (done)
//   23053: loc_824E6198:
//   23054: li r3,1
//   23056: bl 0x8244fec0       <- the 1 ms KeDelayExecutionThread sleep
//   23061: bl 0x8244a670        <- call again
//   23064: cmplwi cr6,r3,0
//   23066: beq cr6,0x824e6198  <- r3 == 0  => SLEEP AND RETRY
//
// So **r3 == 0 means PENDING-and-RETRY**, and only a NON-ZERO value lets the
// boot worker leave the loop.  The host returned 0 on every one of its
// 139,800 calls (build/w848.log SYNTH-XNET), so the boot worker spun in that
// 1 ms loop for the whole run and NEVER reached the boot-gate registration at
// guest 0x821315F4 -- which is why W35-BOOT-GATE and W35-UILOAD were 0 and
// F438-GFXCTOR was 0 in EVERY soak.  The boot worker's own published frame
// chain names the loop: guest sub_824E6148 (w848.log:88042, chain
// f1=824E61A0) and PARK-SAMPLE worker-tid.
//
// THE VALUE: Xenia returns XNET_GET_XNADDR_STATIC = 4 for a local title
// (xam_net.cc:474); 0 is Xenia's XNET_GET_XNADDR_PENDING (:431) and 1 is its
// NONE (:433).  The guest's OWN encoding is what the loop above decides, and
// it needs NON-ZERO -- 4 is the console's value, so 4 it is.
//
// NO CONFLICT WITH THE OTHER CALLER: sub_82501AC0 calls the same thunk at
// 0x82501AE8 and then OVERWRITES r3 with 1 immediately (recomp.101.cpp:7651-7655),
// so it never inspects the return value.  The earlier comment's claim that
// it "takes the r3 == 0 branch as SUCCESS" is refuted by the emitted body.
//
// FALSIFIER: SYNTH-XNET stops repeating, PARK-CENSUS[KDELAY] for the boot
// worker stops, and the F362 probes G,H,I,J,K,L -- the calls on the
// straight-line tail after `bl sub_822C2EA8` at guest 0x82131550 -- FIRE.
// **DO NOT use the F363-C2EA8 RETURN row as the test: it can never print.**
// sub_822C2EA8 ends in a TAIL JUMP (recomp.43.cpp:24200-24222: `addi r1,r1,240;
// lfd f29/f30/f31; b 0x823D9240`), so the hook's post-call code is abandoned
// and the RETURN row is structurally impossible, not a measurement of anything.
uint32_t NetDll_XNetGetTitleXnAddr(uint32_t dllSelector, void *xnaddr) {
  const uint64_t attempt =
      g_synthXnetAttempts.fetch_add(1, std::memory_order_relaxed) + 1;

  bool zeroed = false;
  if (xnaddr != nullptr) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t guestAddr = mem.MapVirtual(xnaddr);
    if (guestAddr != 0) {
      zeroed = mem.WriteBytes(guestAddr, kXnetZeroes, kXnetXnAddrBytes);
    }
  }

  if (attempt <= 8 || (attempt % 200) == 0) {
    const uint32_t glr =
        g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    MCLA_LOG_WARN(
        "SYNTH-XNET #{} op=XNetGetTitleXnAddr attempts={} outcomes={} "
        "selector={:08X} xnaddr_zeroed={} -> returning 4 (XNET_GET_XNADDR_STATIC; no address, no "
        "server, no MAC) glr={:08X}",
        attempt, attempt,
        g_synthXnetOutcomes.load(std::memory_order_relaxed), dllSelector,
        zeroed ? 1 : 0, glr);
  }
  g_synthXnetOutcomes.fetch_add(1, std::memory_order_relaxed);
  // F-845: return the console's XNET_GET_XNADDR_STATIC (4), NOT 0.  The guest's
  // loop in sub_824E6148 (recomp.97.cpp:23049-23067) treats r3 == 0 as
  // PENDING-and-RETRY (beq -> sleep 1 ms -> call again) and only a NON-ZERO
  // value lets it leave (bne -> 0x824e61b0).  Returning 0 kept the boot
  // worker in that 1 ms loop for the whole run, which is why the boot gate was
  // never registered.  The XNADDR buffer is already zeroed above, and the
  // guest copies 6 bytes out of XNADDR+0x10 after it leaves the loop.
  return 4; // XNET_GET_XNADDR_STATIC (Xenia xam_net.cc:474)
}

uint32_t KeWaitForMultipleObjects(uint32_t Count,
                                  xpointer<XDISPATCHER_HEADER> *Objects,
                                  uint32_t WaitType, uint32_t WaitReason,
                                  uint32_t WaitMode, uint32_t Alertable,
                                  be<int64_t> *Timeout) {
  // PARK-SAMPLE: census ALL threads at wait entry
  {
    static std::atomic<uint32_t> s_waitCensus{0};
    const uint32_t n = s_waitCensus.fetch_add(1) + 1;
    if (n <= 60 || (n % 5000) == 0) {
      const uint64_t timeout = GuestTimeoutToMilliseconds(Timeout);
      const char* tclass = (timeout == 0) ? "poll" : (timeout == INFINITE) ? "inf" : "finite";
      uint32_t obj0 = Objects ? static_cast<uint32_t>(
                                  reinterpret_cast<uintptr_t>(Objects[0].get()))
                            : 0;
      MCLA_LOG_INFO("PARK-CENSUS[KWFMULTI] #{:04} tid={:08X} cnt={} obj0={:08X} class={} lr={:08X}",
                    n, GetCurrentThreadId(), Count, obj0, tclass,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }
  const uint64_t timeout = GuestTimeoutToMilliseconds(Timeout);
  assert(timeout == INFINITE || timeout == 0);

  // MAIN-THREAD PARK PROBE
  {
    static std::atomic<uint32_t> s_parkLogs4{0};
    uint32_t mainId = g_mainGuestThreadId.load();
    if (mainId != 0 && GetCurrentThreadId() == mainId &&
        s_parkLogs4.fetch_add(1) < 200) {
      MCLA_LOG_INFO("[main-park] KeWaitForMultipleObjects count={} waitType={} "
                    "obj0={:08X} lr={:08X}",
                    Count, WaitType,
                    Objects ? static_cast<uint32_t>(
                                  reinterpret_cast<uintptr_t>(Objects[0].get()))
                            : 0,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  if (WaitType == 0) // Wait all
  {
    for (size_t i = 0; i < Count; i++) {
      xpointer<XDISPATCHER_HEADER> obj = Objects[i];
      if (!obj)
        continue;
      uint8_t type = obj->Type;
      switch (type) {
      case 0:
      case 1:
        QueryKernelObject<Event>(*obj)->Wait(static_cast<uint32_t>(timeout));
        break;
      case 5:
        QueryKernelObject<Semaphore>(*obj)->Wait(
            static_cast<uint32_t>(timeout));
        break;
      default:
        assert(false && "Unrecognized kernel object type in WaitAll");
        return STATUS_TIMEOUT;
      }
    }
    return STATUS_WAIT_0;
  } else // Wait any
  {
    thread_local std::vector<KernelObject *> s_objects;
    s_objects.resize(Count);

    for (size_t i = 0; i < Count; i++) {
      xpointer<XDISPATCHER_HEADER> obj = Objects[i];
      if (!obj) {
        s_objects[i] = nullptr;
        continue;
      }
      uint8_t type = obj->Type;
      switch (type) {
      case 0:
      case 1:
        s_objects[i] = QueryKernelObject<Event>(*obj);
        break;
      case 5:
        s_objects[i] = QueryKernelObject<Semaphore>(*obj);
        break;
      default:
        assert(false && "Unrecognized kernel object type in WaitAny");
        return STATUS_TIMEOUT;
      }
    }

    while (true) {
      uint32_t generation = g_keSetEventGeneration.load();

      for (size_t i = 0; i < Count; i++) {
        if (s_objects[i] && s_objects[i]->Wait(0) == STATUS_SUCCESS) {
          return STATUS_WAIT_0 + static_cast<uint32_t>(i);
        }
      }

      if (timeout == 0)
        return STATUS_TIMEOUT;

      g_keSetEventGeneration.wait(generation);
    }
  }
}

// Console (xboxkrnl_threading.cc:998-1001): raise to DPC and RETURN THE OLD
// IRQL.  The old body returned a constant 0, which is only right for the
// OUTERMOST acquire on a thread that starts at PASSIVE; for a NESTED acquire
// it handed the guest a wrong "old level", and because the guest stores that
// value in its lock struct's +12 byte and hands it back to KfLowerIrql
// (0x823EAD9C / 0x823EACF8), every lowering was a no-op.
uint32_t KeRaiseIrqlToDpcLevel() {
  const uint32_t oldIrql = HostRaiseIrql(kIrqlDpc);
  {
    static std::atomic<uint32_t> s_raise{0};
    const uint32_t n = s_raise.fetch_add(1) + 1;
    if (n <= 40 || (n % 5000) == 0)
      MCLA_LOG_INFO("IRQL-RAISE #{} old_irql={} new_irql={} lr={:08X}", n,
                    oldIrql, static_cast<unsigned>(kIrqlDpc),
                    g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0);
  }
  return oldIrql;
}

// Console (xboxkrnl_threading.cc:1005-1010): restore the level, THEN run the
// pending APCs (CheckApcs).  The old body was `{}`: it ignored its argument
// entirely, so the host had NO IRQL and NO APC delivery point at all.
//
// The argument arrives in r3: the guest does `mr r3,r31` (the saved old
// IRQL) immediately before the call (0x823EACF4 -> 0x823EACF8, and the same
// at 0x823EAD48 -> 0x823EAD4C, 0x823EB6D8 -> 0x823EB6DC, 0x823EE9EC ->
// 0x823EE9F0).
void KfLowerIrql(uint32_t oldIrql) {
  HostLowerIrql(static_cast<uint8_t>(oldIrql & 0xFF));
  {
    static std::atomic<uint32_t> s_lower{0};
    const uint32_t n = s_lower.fetch_add(1) + 1;
    if (n <= 40 || (n % 5000) == 0)
      MCLA_LOG_INFO("IRQL-LOWER #{} old_irql={} now={} lr={:08X}", n, oldIrql,
                    static_cast<unsigned>(HostCurrentIrql()),
                    g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0);
  }
}

extern "C" uint32_t KeReleaseSemaphore(XKSEMAPHORE *semaphore, uint32_t increment,
                            uint32_t adjustment, uint32_t wait) {
  // SIGNAL CENSUS (2026-08-23 session 9): same attribution as KeSetEvent.
  {
    static std::atomic<uint32_t> s_signalLogs2{0};
    const uint32_t n = s_signalLogs2.fetch_add(1) + 1;
    if (n <= 40 || (n % 2000) == 0) {
      MCLA_LOG_INFO(
          "SIGNAL KeReleaseSemaphore obj={:08X} inc={} adj={} lr={:08X}",
          static_cast<uint32_t>(reinterpret_cast<uintptr_t>(semaphore)),
          increment, adjustment,
          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  // TYPE CENSUS (release side): obj VA | header Type | site=release | resolution
  {
    static std::atomic<uint32_t> s_typeRelLogs2{0};
    const uint32_t n = s_typeRelLogs2.fetch_add(1) + 1;
    if (n <= 60 || (n % 5000) == 0) {
      const uint32_t hdrAddr = static_cast<uint32_t>(
          reinterpret_cast<const uint8_t *>(&semaphore->Header) -
          mcla::kernel::g_memory.base);
      const uint8_t hdrType = semaphore->Header.Type;
      MCLA_LOG_INFO("TYPE-CENSUS[REL] #{:04} obj={:08X} type={:02X} site=release res=QueryKernelObject(Semaphore) lr={:08X}",
                    n, hdrAddr, hdrType,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
  }

  Semaphore *sem = QueryKernelObject<Semaphore>(semaphore->Header);
  sem->Release(adjustment, nullptr);

  ++g_keSetEventGeneration;
  g_keSetEventGeneration.notify_all();

  return STATUS_SUCCESS;
}

uint32_t XAudioGetVoiceCategoryVolume(uint32_t Driver, be<uint32_t> *Volume) {
  // Honest per-port: no per-category volume table exists in this host, so
  // report the default (0 dB = 0x3F800000 in Xbox convention? — we report
  // 0 = unity, matching the guest's "no attenuation" expectation). The
  // previous void stub left r3 garbage and never wrote the guest buffer
  // (F-799 class); the guest reads *Volume on return.
  (void)Driver;
  if (Volume) *Volume = 0;
  return 0;  // STATUS_SUCCESS
}

uint32_t XAudioGetVoiceCategoryVolumeChangeMask(uint32_t Driver,
                                                be<uint32_t> *Mask) {
  *Mask = 0;
  return 0;
}

uint32_t KeResumeThread(GuestThreadHandle *object) {
  assert(object != GetKernelObject(CURRENT_THREAD_HANDLE));

  object->suspended = false;
  object->suspended.notify_all();
  return 0;
}

void KeInitializeSemaphore(XKSEMAPHORE *semaphore, uint32_t count,
                           uint32_t limit) {
  semaphore->Header.Type = 5; // Semaphore object type
  semaphore->Header.SignalState.set(count);
  semaphore->Limit.set(limit);

  auto *object = QueryKernelObject<Semaphore>(semaphore->Header);
}

void XMAReleaseContext(uint32_t contextPtr) {
  apu::XmaReleaseContext(contextPtr);
}

uint32_t XMACreateContext(be<uint32_t> *outContext) {
  uint32_t ptr = 0;
  if (!apu::XmaCreateContext(&ptr)) {
    if (outContext) *outContext = 0;
    return 0;
  }
  if (outContext) *outContext = ptr;
  return ptr;
}

// XAudio render-driver hooks (M5). Xenia/UnleashedRecomp ABI:
//   callback_ptr[0] = guest fn, callback_ptr[1] = userdata
//   samples = be<float> [6 ch * 256], channel-major.
uint32_t XAudioRegisterRenderDriverClient(be<uint32_t> *callback,
                                          be<uint32_t> *driver) {
  if (driver) {
    if (callback) {
      *driver = apu::RegisterClient(callback[0], callback[1]);
    } else {
      *driver = apu::RegisterClient(0, 0);
    }
  }
  return 0;
}

uint32_t XAudioUnregisterRenderDriverClient(uint32_t driver) {
  (void)driver;
  apu::UnregisterClient();
  return 0;
}

uint32_t XAudioSubmitRenderDriverFrame(uint32_t driver, void *samples) {
  (void)driver;
  apu::SubmitFrames(samples);
  return 0;
}

uint32_t XAudioGetSpeakerConfig(be<uint32_t> *config) {
  if (config) {
    *config = 0x00010001;
  }
  return 0;
}

GUEST_FUNCTION_HOOK(__imp__XGetVideoMode, VdQueryVideoMode); // XGetVideoMode
GUEST_FUNCTION_HOOK(__imp__XNotifyGetNext, XNotifyGetNext);
GUEST_FUNCTION_HOOK(__imp__XGetGameRegion, XGetGameRegion);
GUEST_FUNCTION_HOOK(__imp__XMsgStartIORequest, XMsgStartIORequest);
GUEST_FUNCTION_HOOK(__imp__XamUserGetSigninState, XamUserGetSigninState);
GUEST_FUNCTION_HOOK(__imp__XamGetSystemVersion, XamGetSystemVersion);
GUEST_FUNCTION_HOOK(__imp__XamContentCreateEx, XamContentCreateEx);
GUEST_FUNCTION_HOOK(__imp__XamContentDelete, XamContentDelete);
GUEST_FUNCTION_HOOK(__imp__XamContentClose, XamContentClose);
GUEST_FUNCTION_HOOK(__imp__XamContentGetCreator, XamContentGetCreator);
GUEST_FUNCTION_HOOK(__imp__XamContentCreateEnumerator,
                    XamContentCreateEnumerator);
GUEST_FUNCTION_HOOK(__imp__XamContentGetDeviceState, XamContentGetDeviceState);
GUEST_FUNCTION_HOOK(__imp__XamContentGetDeviceData, XamContentGetDeviceData);
GUEST_FUNCTION_HOOK(__imp__XamEnumerate, XamEnumerate);
GUEST_FUNCTION_HOOK(__imp__XamNotifyCreateListener, XamNotifyCreateListener);
GUEST_FUNCTION_HOOK(__imp__XamUserGetSigninInfo, XamUserGetSigninInfo);
GUEST_FUNCTION_HOOK(__imp__XamShowSigninUI, XamShowSigninUI);
GUEST_FUNCTION_HOOK(__imp__XamShowDeviceSelectorUI, XamShowDeviceSelectorUI);
GUEST_FUNCTION_HOOK(__imp__XamShowMessageBoxUI, XamShowMessageBoxUI);
GUEST_FUNCTION_HOOK(__imp__XamShowDirtyDiscErrorUI, XamShowDirtyDiscErrorUI);
GUEST_FUNCTION_HOOK(__imp__XamEnableInactivityProcessing,
                    XamEnableInactivityProcessing);
GUEST_FUNCTION_HOOK(__imp__XamResetInactivity, XamResetInactivity);
GUEST_FUNCTION_HOOK(__imp__XamShowMessageBoxUIEx, XamShowMessageBoxUIEx);
GUEST_FUNCTION_HOOK(__imp__XGetLanguage, XGetLanguage);
GUEST_FUNCTION_HOOK(__imp__XGetAVPack, XGetAVPack);
GUEST_FUNCTION_HOOK(__imp__XamLoaderTerminateTitle, XamLoaderTerminateTitle);
// ExitProcess hook removed - conflicts with Windows API
GUEST_FUNCTION_HOOK(__imp__XamGetExecutionId, XamGetExecutionId);
GUEST_FUNCTION_HOOK(__imp__XamLoaderLaunchTitle, XamLoaderLaunchTitle);
GUEST_FUNCTION_HOOK(__imp__XamLoaderMediaGetInfo, XamLoaderMediaGetInfo);
GUEST_FUNCTION_HOOK(__imp__XamLoaderGetDvdTrayState, XamLoaderGetDvdTrayState);
GUEST_FUNCTION_HOOK(__imp__NtOpenFile, NtOpenFile);
GUEST_FUNCTION_HOOK(__imp__RtlInitAnsiString, RtlInitAnsiString);
GUEST_FUNCTION_HOOK(__imp__NtCreateFile, NtCreateFile);
GUEST_FUNCTION_HOOK(__imp__NtClose, NtClose);
GUEST_FUNCTION_HOOK(__imp__NtSetInformationFile, NtSetInformationFile);
GUEST_FUNCTION_HOOK(__imp__FscSetCacheElementCount, FscSetCacheElementCount);
GUEST_FUNCTION_HOOK(__imp__NtWaitForSingleObjectEx, NtWaitForSingleObjectEx);
GUEST_FUNCTION_HOOK(__imp__NtWriteFile, NtWriteFile);
GUEST_FUNCTION_HOOK(__imp__ExGetXConfigSetting, ExGetXConfigSetting);
GUEST_FUNCTION_HOOK(__imp__NtQueryVirtualMemory, NtQueryVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__MmQueryStatistics, MmQueryStatistics);
GUEST_FUNCTION_HOOK(__imp__NtCreateEvent, NtCreateEvent);
GUEST_FUNCTION_HOOK(__imp__XexCheckExecutablePrivilege,
                    XexCheckExecutablePrivilege);
GUEST_FUNCTION_HOOK(__imp__DbgPrint, DbgPrint);
GUEST_FUNCTION_HOOK(__imp____C_specific_handler, __C_specific_handler_x);
GUEST_FUNCTION_HOOK(__imp__RtlNtStatusToDosError, RtlNtStatusToDosError);
GUEST_FUNCTION_HOOK(__imp__XexGetProcedureAddress, XexGetProcedureAddress);
GUEST_FUNCTION_HOOK(__imp__XexGetModuleSection, XexGetModuleSection);
GUEST_FUNCTION_HOOK(__imp__RtlUnicodeToMultiByteN, RtlUnicodeToMultiByteN);
GUEST_FUNCTION_HOOK(__imp__KeDelayExecutionThread, KeDelayExecutionThread);
GUEST_FUNCTION_HOOK(__imp__ExFreePool, ExFreePool);
// NtQueryInformationFile stays on its PPC_FUNC wrapper (no typed impl yet);
// Volume/Directory queries use the typed impls above.
GUEST_FUNCTION_HOOK(__imp__NtQueryVolumeInformationFile,
                    NtQueryVolumeInformationFile);
GUEST_FUNCTION_HOOK(__imp__NtQueryDirectoryFile, NtQueryDirectoryFile);
GUEST_FUNCTION_HOOK(__imp__NtReadFileScatter, NtReadFileScatter);
GUEST_FUNCTION_HOOK(__imp__NtReadFile, NtReadFile);
GUEST_FUNCTION_HOOK(__imp__NtDuplicateObject, NtDuplicateObject);
GUEST_FUNCTION_HOOK(__imp__NtAllocateVirtualMemory, NtAllocateVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__NtFreeVirtualMemory, NtFreeVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__ObDereferenceObject, ObDereferenceObject);
GUEST_FUNCTION_HOOK(__imp__KeSetBasePriorityThread, KeSetBasePriorityThread);
GUEST_FUNCTION_HOOK(__imp__ObReferenceObjectByHandle,
                    ObReferenceObjectByHandle);
GUEST_FUNCTION_HOOK(__imp__KeQueryBasePriorityThread,
                    KeQueryBasePriorityThread);
GUEST_FUNCTION_HOOK(__imp__NtSuspendThread, NtSuspendThread);
GUEST_FUNCTION_HOOK(__imp__KeSetAffinityThread, KeSetAffinityThread);
GUEST_FUNCTION_HOOK(__imp__RtlLeaveCriticalSection, RtlLeaveCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlEnterCriticalSection, RtlEnterCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlImageXexHeaderField, RtlImageXexHeaderField);
GUEST_FUNCTION_HOOK(__imp__HalReturnToFirmware, HalReturnToFirmware);
GUEST_FUNCTION_HOOK(__imp__RtlFillMemoryUlong, RtlFillMemoryUlong);
GUEST_FUNCTION_HOOK(__imp__KeBugCheckEx, KeBugCheckEx);
GUEST_FUNCTION_HOOK(__imp__KeGetCurrentProcessType, KeGetCurrentProcessType);
GUEST_FUNCTION_HOOK(__imp__RtlCompareMemoryUlong, RtlCompareMemoryUlong);
GUEST_FUNCTION_HOOK(__imp__RtlInitializeCriticalSection,
                    RtlInitializeCriticalSection);
// (rule 1b, 2026-10-21, fix_raise) NOT a GUEST_FUNCTION_HOOK: the hook needs
// the LIVE guest context (the guest's raise registers, the raising frame's
// stack and the return address), and the GUEST_FUNCTION_HOOK machinery can
// only hand a hook the guest's ARGUMENT REGISTERS -- a PPCContext& parameter
// would be gathered as an integer argument
// (src/kernel/function.h:330-341, ArgTranslator::GetValue), and the
// thread-local g_ppcContext is STALE here because the recompiled code never
// calls SetPPCContext (0 hits in generated/ppc_xenon/ppc_recomp.0.cpp), so it
// still holds the boot root's registers.  A direct PPC_FUNC body gets the
// live `ctx` and `base`; the same shape is used for
// __imp__NtQueryInformationFile at src/kernel/imports.cpp:1058.
PPC_FUNC(__imp__RtlRaiseException) { RtlRaiseException_x(ctx, base); }
GUEST_FUNCTION_HOOK(__imp__KfReleaseSpinLock, KfReleaseSpinLock);
GUEST_FUNCTION_HOOK(__imp__KfAcquireSpinLock, KfAcquireSpinLock);
GUEST_FUNCTION_HOOK(__imp__KeQueryPerformanceFrequency,
                    KeQueryPerformanceFrequency);
GUEST_FUNCTION_HOOK(__imp__MmFreePhysicalMemory, MmFreePhysicalMemory);
GUEST_FUNCTION_HOOK(__imp__VdPersistDisplay, VdPersistDisplay);
// VdSwap: replaced GUEST_FUNCTION_HOOK with direct forwarding to native renderer.
// The original GUEST_FUNCTION_HOOK intercepted the import thunk and called a no-op,
// preventing Hooked_VdSwap at 0x827BD6E4 from ever executing.
// Forward to the native renderer's Hooked_VdSwap which handles PRESENT + frame advance.
extern "C" void Hooked_VdSwap(PPCContext &ctx, unsigned char *base);
PPC_FUNC(__imp__VdSwap) { Hooked_VdSwap(ctx, base); }
GUEST_FUNCTION_HOOK(__imp__VdGetSystemCommandBuffer, VdGetSystemCommandBuffer);
GUEST_FUNCTION_HOOK(__imp__KeReleaseSpinLockFromRaisedIrql,
                    KeReleaseSpinLockFromRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__KeAcquireSpinLockAtRaisedIrql,
                    KeAcquireSpinLockAtRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__KiApcNormalRoutineNop, KiApcNormalRoutineNop);
GUEST_FUNCTION_HOOK(__imp__VdEnableRingBufferRPtrWriteBack,
                    VdEnableRingBufferRPtrWriteBack);
GUEST_FUNCTION_HOOK(__imp__VdInitializeRingBuffer, VdInitializeRingBuffer);
GUEST_FUNCTION_HOOK(__imp__MmGetPhysicalAddress, MmGetPhysicalAddress);
GUEST_FUNCTION_HOOK(__imp__VdSetSystemCommandBufferGpuIdentifierAddress,
                    VdSetSystemCommandBufferGpuIdentifierAddress);
GUEST_FUNCTION_HOOK(__imp__ExRegisterTitleTerminateNotification,
                    ExRegisterTitleTerminateNotification);
GUEST_FUNCTION_HOOK(__imp__VdShutdownEngines, VdShutdownEngines);
GUEST_FUNCTION_HOOK(__imp__VdQueryVideoMode, VdQueryVideoMode);
GUEST_FUNCTION_HOOK(__imp__VdGetCurrentDisplayInformation,
                    VdGetCurrentDisplayInformation);
GUEST_FUNCTION_HOOK(__imp__VdSetDisplayMode, VdSetDisplayMode);
GUEST_FUNCTION_HOOK(__imp__VdSetGraphicsInterruptCallback,
                    VdSetGraphicsInterruptCallback);
GUEST_FUNCTION_HOOK(__imp__VdInitializeEngines, VdInitializeEngines);
GUEST_FUNCTION_HOOK(__imp__VdIsHSIOTrainingSucceeded,
                    VdIsHSIOTrainingSucceeded);
GUEST_FUNCTION_HOOK(__imp__VdGetCurrentDisplayGamma, VdGetCurrentDisplayGamma);
GUEST_FUNCTION_HOOK(__imp__VdQueryVideoFlags, VdQueryVideoFlags);
GUEST_FUNCTION_HOOK(__imp__VdCallGraphicsNotificationRoutines,
                    VdCallGraphicsNotificationRoutines);
GUEST_FUNCTION_HOOK(__imp__VdInitializeScalerCommandBuffer,
                    VdInitializeScalerCommandBuffer);
GUEST_FUNCTION_HOOK(__imp__KeLeaveCriticalRegion, KeLeaveCriticalRegion);
GUEST_FUNCTION_HOOK(__imp__VdRetrainEDRAM, VdRetrainEDRAM);
GUEST_FUNCTION_HOOK(__imp__VdRetrainEDRAMWorker, VdRetrainEDRAMWorker);
GUEST_FUNCTION_HOOK(__imp__KeEnterCriticalRegion, KeEnterCriticalRegion);
GUEST_FUNCTION_HOOK(__imp__ObDeleteSymbolicLink, ObDeleteSymbolicLink);
GUEST_FUNCTION_HOOK(__imp__ObCreateSymbolicLink, ObCreateSymbolicLink);
GUEST_FUNCTION_HOOK(__imp__MmQueryAddressProtect, MmQueryAddressProtect);
GUEST_FUNCTION_HOOK(__imp__VdEnableDisableClockGating,
                    VdEnableDisableClockGating);
GUEST_FUNCTION_HOOK(__imp__KeBugCheck, KeBugCheck);
GUEST_FUNCTION_HOOK(__imp__KeLockL2, KeLockL2);
GUEST_FUNCTION_HOOK(__imp__KeUnlockL2, KeUnlockL2);
GUEST_FUNCTION_HOOK(__imp__KeSetEvent, KeSetEvent);
GUEST_FUNCTION_HOOK(__imp__KeResetEvent, KeResetEvent);
GUEST_FUNCTION_HOOK(__imp__KeWaitForSingleObject, KeWaitForSingleObject);
GUEST_FUNCTION_HOOK(__imp__KeTlsGetValue, KeTlsGetValue);
GUEST_FUNCTION_HOOK(__imp__KeTlsSetValue, KeTlsSetValue);
GUEST_FUNCTION_HOOK(__imp__KeTlsAlloc, KeTlsAlloc);
GUEST_FUNCTION_HOOK(__imp__KeTlsFree, KeTlsFree);
GUEST_FUNCTION_HOOK(__imp__XMsgInProcessCall, XMsgInProcessCall);
GUEST_FUNCTION_HOOK(__imp__XamUserReadProfileSettings,
                    XamUserReadProfileSettings);
GUEST_FUNCTION_HOOK(__imp__NetDll_WSAStartup, NetDll_WSAStartup);
GUEST_FUNCTION_HOOK(__imp__NetDll_WSACleanup, NetDll_WSACleanup);
GUEST_FUNCTION_HOOK(__imp__NetDll_socket, NetDll_socket);
GUEST_FUNCTION_HOOK(__imp__NetDll_closesocket, NetDll_closesocket);
GUEST_FUNCTION_HOOK(__imp__NetDll_setsockopt, NetDll_setsockopt);
GUEST_FUNCTION_HOOK(__imp__NetDll_bind, NetDll_bind);
GUEST_FUNCTION_HOOK(__imp__NetDll_connect, NetDll_connect);
GUEST_FUNCTION_HOOK(__imp__NetDll_listen, NetDll_listen);
GUEST_FUNCTION_HOOK(__imp__NetDll_accept, NetDll_accept);
GUEST_FUNCTION_HOOK(__imp__NetDll_select, NetDll_select);
GUEST_FUNCTION_HOOK(__imp__NetDll_recv, NetDll_recv);
GUEST_FUNCTION_HOOK(__imp__NetDll_send, NetDll_send);
// NetDll_inet_addr, NetDll___WSAFDIsSet - implemented as PPC_FUNC
GUEST_FUNCTION_HOOK(__imp__XMsgStartIORequestEx, XMsgStartIORequestEx);
GUEST_FUNCTION_HOOK(__imp__XamInputGetCapabilities, XamInputGetCapabilities);
GUEST_FUNCTION_HOOK(__imp__XamInputGetState, XamInputGetState);
GUEST_FUNCTION_HOOK(__imp__XamInputSetState, XamInputSetState);
GUEST_FUNCTION_HOOK(__imp__XexGetModuleHandle, XexGetModuleHandle);
GUEST_FUNCTION_HOOK(__imp__XexLoadImage, XexLoadImage);
GUEST_FUNCTION_HOOK(__imp__XexLoadImageHeaders, XexLoadImageHeaders);
GUEST_FUNCTION_HOOK(__imp__XexUnloadImage, XexUnloadImage);
GUEST_FUNCTION_HOOK(__imp__XexCheckExecutablePages, XexCheckExecutablePages);
GUEST_FUNCTION_HOOK(__imp__RtlTryEnterCriticalSection,
                    RtlTryEnterCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlInitializeCriticalSectionAndSpinCount,
                    RtlInitializeCriticalSectionAndSpinCount);
GUEST_FUNCTION_HOOK(__imp__XeCryptBnQwBeSigVerify, XeCryptBnQwBeSigVerify);
GUEST_FUNCTION_HOOK(__imp__XeKeysGetKey, XeKeysGetKey);
GUEST_FUNCTION_HOOK(__imp__XeCryptRotSumSha, XeCryptRotSumSha);
GUEST_FUNCTION_HOOK(__imp__XeCryptSha, XeCryptSha);
GUEST_FUNCTION_HOOK(__imp__KeEnableFpuExceptions, KeEnableFpuExceptions);
GUEST_FUNCTION_HOOK(__imp__RtlUnwind, RtlUnwind_x);
GUEST_FUNCTION_HOOK(__imp__RtlCaptureContext, RtlCaptureContext_x);
GUEST_FUNCTION_HOOK(__imp__NtQueryFullAttributesFile,
                    NtQueryFullAttributesFile);
GUEST_FUNCTION_HOOK(__imp__RtlMultiByteToUnicodeN, RtlMultiByteToUnicodeN);
GUEST_FUNCTION_HOOK(__imp__DbgBreakPoint, DbgBreakPoint);
GUEST_FUNCTION_HOOK(__imp__MmQueryAllocationSize, MmQueryAllocationSize);
GUEST_FUNCTION_HOOK(__imp__NtClearEvent, NtClearEvent);
GUEST_FUNCTION_HOOK(__imp__NtResumeThread, NtResumeThread);
GUEST_FUNCTION_HOOK(__imp__NtSetEvent, NtSetEvent);
GUEST_FUNCTION_HOOK(__imp__NtCreateSemaphore, NtCreateSemaphore);
GUEST_FUNCTION_HOOK(__imp__NtReleaseSemaphore, NtReleaseSemaphore);
GUEST_FUNCTION_HOOK(__imp__NtWaitForMultipleObjectsEx,
                    NtWaitForMultipleObjectsEx);
GUEST_FUNCTION_HOOK(__imp__RtlCompareStringN, RtlCompareStringN);
GUEST_FUNCTION_HOOK(__imp__NtFlushBuffersFile, NtFlushBuffersFile);
GUEST_FUNCTION_HOOK(__imp__KeQuerySystemTime, KeQuerySystemTime);
GUEST_FUNCTION_HOOK(__imp__RtlTimeToTimeFields, RtlTimeToTimeFields);
GUEST_FUNCTION_HOOK(__imp__RtlFreeAnsiString, RtlFreeAnsiString);
GUEST_FUNCTION_HOOK(__imp__RtlUnicodeStringToAnsiString,
                    RtlUnicodeStringToAnsiString);
GUEST_FUNCTION_HOOK(__imp__RtlInitUnicodeString, RtlInitUnicodeString);
GUEST_FUNCTION_HOOK(__imp__ExTerminateThread, ExTerminateThread);
GUEST_FUNCTION_HOOK(__imp__ExCreateThread, ExCreateThread);
GUEST_FUNCTION_HOOK(__imp__IoInvalidDeviceRequest, IoInvalidDeviceRequest);
GUEST_FUNCTION_HOOK(__imp__ObReferenceObject, ObReferenceObject);
GUEST_FUNCTION_HOOK(__imp__IoCreateDevice, IoCreateDevice);
GUEST_FUNCTION_HOOK(__imp__IoDeleteDevice, IoDeleteDevice);
GUEST_FUNCTION_HOOK(__imp__ExAllocatePoolTypeWithTag,
                    ExAllocatePoolTypeWithTag);
GUEST_FUNCTION_HOOK(__imp__RtlTimeFieldsToTime, RtlTimeFieldsToTime);
GUEST_FUNCTION_HOOK(__imp__IoCompleteRequest, IoCompleteRequest);
GUEST_FUNCTION_HOOK(__imp__RtlUpcaseUnicodeChar, RtlUpcaseUnicodeChar);
GUEST_FUNCTION_HOOK(__imp__ObIsTitleObject, ObIsTitleObject);
GUEST_FUNCTION_HOOK(__imp__IoCheckShareAccess, IoCheckShareAccess);
GUEST_FUNCTION_HOOK(__imp__IoSetShareAccess, IoSetShareAccess);
GUEST_FUNCTION_HOOK(__imp__IoRemoveShareAccess, IoRemoveShareAccess);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetStartup, NetDll_XNetStartup);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetGetTitleXnAddr,
                    NetDll_XNetGetTitleXnAddr);
GUEST_FUNCTION_HOOK(__imp__KeWaitForMultipleObjects, KeWaitForMultipleObjects);
GUEST_FUNCTION_HOOK(__imp__KeRaiseIrqlToDpcLevel, KeRaiseIrqlToDpcLevel);
GUEST_FUNCTION_HOOK(__imp__StfsControlDevice, StfsControlDevice);
GUEST_FUNCTION_HOOK(__imp__StfsCreateDevice, StfsCreateDevice);
GUEST_FUNCTION_HOOK(__imp__KfLowerIrql, KfLowerIrql);
GUEST_FUNCTION_HOOK(__imp__KeReleaseSemaphore, KeReleaseSemaphore);
GUEST_FUNCTION_HOOK(__imp__XAudioGetVoiceCategoryVolume,
                    XAudioGetVoiceCategoryVolume);
GUEST_FUNCTION_HOOK(__imp__XAudioGetVoiceCategoryVolumeChangeMask,
                    XAudioGetVoiceCategoryVolumeChangeMask);
GUEST_FUNCTION_HOOK(__imp__KeResumeThread, KeResumeThread);
GUEST_FUNCTION_HOOK(__imp__KeInitializeSemaphore, KeInitializeSemaphore);
GUEST_FUNCTION_HOOK(__imp__XMAReleaseContext, XMAReleaseContext);
GUEST_FUNCTION_HOOK(__imp__XMACreateContext, XMACreateContext);
GUEST_FUNCTION_HOOK(sub_821305B8, sub_821305B8_NoOp);

// Missing Xam/NetDll imports referenced by generated code
//
// F-609 PORT BATCH, 2026-09-29 (integration stream). The dead host definitions
// that used to sit under that heading are GONE, and this heading is kept
// verbatim on instruction. It is now only half true, so the correction is
// recorded here rather than left to the next reader to discover:
//
//   * "Missing" is no longer accurate for the 63 exports this batch ported.
//     19 now have real bodies and 44 have honest, counted refusals, in
//     src/kernel/port_net.cpp, src/kernel/port_xam_user.cpp,
//     src/kernel/port_kobj.cpp and src/kernel/port_voice_input.cpp. Each of
//     those files registers its own GUEST_FUNCTION_HOOK, so there is exactly
//     one owner of each guest address (AGENTS.md rule 4) and the empty
//     GUEST_FUNCTION_STUB bodies are gone rather than merely unreachable.
//   * "Missing ... referenced by generated code" IS still true of the wider
//     tree, and this heading is therefore still a real statement, just a
//     smaller one.
//   * What the deletion also removed, and why it mattered: two of the deleted
//     bodies were LIVE FABRICATIONS. `NetDll_XNetGetConnectStatus` returned
//     1 (commented "Connected") and `NetDll_XNetGetEthernetLinkStatus`
//     returned 1 (commented "Link up"). Both told the title it had a network
//     this host does not have. port_net.cpp refuses both instead.
//   * Also deleted: `int NetDll_WSAGetLastError()`, which was DEAD code (its
//     GUEST_FUNCTION_STUB body was empty, so the guest read its own r3 back as
//     its error code). port_net.cpp:297 is the live one. See the F-609 note
//     that used to precede it, kept below.
//   * NOT deleted, and deliberately so: `void _snprintf()` and
//     `void _vsnprintf()` further down this file. They are SINGLE-underscore
//     symbols. The stubs this batch removed are `__imp___snprintf` /
//     `__imp___vsnprintf` (double underscore after the prefix), which had
//     empty bodies and therefore never called `_snprintf`/`_vsnprintf` at all.
//     Those two are pre-existing orphans for a different (also empty) import
//     pair; they are out of scope here and are named rather than swept up.


// F-609, beyond the brief's list. Was `int NetDll_WSAGetLastError() { return 0; }`
// -- "no error", unconditionally, forever. That is the load-bearing partner of
// the whole NetDll family: it is the function the title calls to find out WHY a
// socket call failed, and with every failure above reporting SOCKET_ERROR, a
// hardcoded 0 would tell it there was no reason. So this now reports the
// WSAENOTSOCK that the refusals above set.
//
// TASK 3 CORRECTION (measured, this pass): the body below was correct and was
// NOT REACHABLE. `GUEST_FUNCTION_STUB(__imp__NetDll_WSAGetLastError)` expands
// to `PPC_FUNC(name) { }` (src/kernel/function.h:640-641) -- an empty body that
// leaves r3 holding whatever the caller passed, so the title was reading its
// own argument back as its error code and the host definition was dead code.
// It is a real HOOK now, at the single site that import already had
// (`addr_owners.py --check 0x827BD204` -> one map row, one binding, no
// duplicate).
//
// ARITY, verified not assumed: the guest thunk is `sub_8244A480`, a bare
// `b 827BD204` with no register setup at all (0x8244A478 and 0x8244A484 are
// the only instructions either side of it). So this entry takes NO leading
// selector, unlike the rest of the family, and the zero-argument signature is
// correct as written.
//
// Xenia: NetDll_WSAGetLastError_entry (xam_net.cc:291-294) returns
// XThread::GetLastError() -- a per-thread cell. This is a single host cell
// (g_netLastError, declared with the family), which is exact for the one
// networking thread this title uses and would be wrong if a second thread ever
// asked. That approximation is named rather than hidden.
//
// F-609 PORT BATCH, 2026-09-29 (integration stream) -- SUPERSEDING. Two changes
// to the paragraph above, both measured, neither erasing the F-609 finding:
//
//   1. THE DEFINITION IS GONE from this file. `int NetDll_WSAGetLastError()`
//      was DEAD CODE, exactly as the TASK 3 CORRECTION note says: the
//      GUEST_FUNCTION_STUB body was empty, so the host definition was never
//      called and the title was reading its own r3 back as its error code. The
//      live one is src/kernel/port_net.cpp:297. Leaving the definition here
//      would have been a LNK2005 duplicate external symbol, since both are at
//      global scope with external linkage and the same signature.
//   2. THE BINDING MOVED. The note above says the hook lives "at the single
//      site that import already had". That is no longer true: the single site is
//      now src/kernel/port_net.cpp:694, and the
//      GUEST_FUNCTION_HOOK(__imp__NetDll_WSAGetLastError, ...) that used to sit
//      further down this file has been DELETED from it. That deletion is the
//      point, not an accident: keeping both would be two owners of one guest
//      function (AGENTS.md rule 4) and a second duplicate symbol. One owner
//      remains, and it is the one that has a body.
//   3. The g_netLastError cell named above still exists, but it is no longer
//      the whole story. It is file-static inside an anonymous namespace, so
//      port_net.cpp could not name it. There is now ONE cell, reachable as
//      mcla::kernel::netport::SetLastError / LastError (src/kernel/port_net.h:
//      36-37), and NetRefuse below writes through it -- so the twelve refusals
//      in this file and the eighteen in port_net.cpp finally share one
//      last-error, which is the whole point of the function.

void XexLoadImage() {
  // XexLoadImage: loads an XEX module from a file handle.
  // Guest args: r3 = FileHandle, r4 = ModuleTypeFlags, r5 = Version, r6 =
  // ModuleHandleOut Returns 0 on success, writes module handle to output.
  if (!g_ppcContext)
    return;

  uint32_t fileHandle = g_ppcContext->r3.u32;
  uint32_t moduleTypeFlags = g_ppcContext->r4.u32;
  uint32_t version = g_ppcContext->r5.u32;
  uint32_t moduleHandleOut = g_ppcContext->r6.u32;

  // For now, return success for any load attempt (dev mode).
  // Real implementation would parse XEX headers, verify signature via
  // XeKeys/XeCrypt, map sections, and register module in kernel loader table.
  g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

  if (moduleHandleOut) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t handle = 0x82000000; // Dummy handle
    (void)mem.WriteU32BE(moduleHandleOut, handle);
  }
}

void XexLoadImageHeaders() {
  // XexLoadImageHeaders: reads XEX header from file into buffer without loading
  // executable sections. Guest args: r3 = FileHandle, r4 = BufferOut, r5 =
  // BufferSize
  if (!g_ppcContext)
    return;

  uint32_t fileHandle = g_ppcContext->r3.u32;
  uint32_t bufferOut = g_ppcContext->r4.u32;
  uint32_t bufferSize = g_ppcContext->r5.u32;

  g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

  if (bufferOut && bufferSize >= 0x1000) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    // Minimal XEX2 header
    uint8_t header[0x1000] = {};
    *reinterpret_cast<uint32_t *>(&header[0]) =
        __builtin_bswap32(0x58455832); // 'XEX2' magic
    *reinterpret_cast<uint32_t *>(&header[4]) =
        __builtin_bswap32(0x0); // ModuleFlags
    *reinterpret_cast<uint32_t *>(&header[8]) =
        __builtin_bswap32(0x1000); // HeaderSize
    (void)mem.WriteBytes(bufferOut, header, bufferSize);
  }
}
void XexUnloadImage() {
  // XexUnloadImage: unloads a previously loaded module
  // Guest args: r3 = ModuleHandle
  g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
}

void XexCheckExecutablePages() {
  // XexCheckExecutablePages: verifies executable pages integrity
  // Guest args: r3 = ModuleHandle, r4 = Flags
  // Returns 0 on success
  if (g_ppcContext) {
    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
  }
}

void _snprintf() { LOG_UTILITY("!!! STUB !!!"); }
void _vsnprintf() { LOG_UTILITY("!!! STUB !!!"); }

// F-609 PORT BATCH, 2026-09-29 (integration stream). `void sprintf()` used to
// sit here too and is GONE: the guest import `sprintf` was registered as
// GUEST_FUNCTION_STUB(__imp__sprintf), an empty body, so this definition was
// never called. src/kernel/port_kobj.cpp:2349 now registers
// GUEST_FUNCTION_HOOK(__imp__sprintf, ::kobjport::XkSprintf), a real engine
// (Xenia strings.cc:897-925). The two single-underscore bodies above are KEPT:
// they are a different import pair, pre-existing orphans, and out of scope here
// (see the F-609 note under the "Missing Xam/NetDll imports" heading above).

// ---- F-609 PORT BATCH, 2026-09-29: GUEST_FUNCTION_STUB bodies removed. -------
// Every line of this run expanded to `PPC_FUNC(name) { }` -- an EMPTY body that
// leaves r3 equal to the incoming r3, so each caller read a POINTER back where
// an NTSTATUS, a count or a handle belonged. Each is now registered by the port
// file named beside it, which is the single owner of that guest address.
//   XamShowFriendsUI / XamShowGamerCardUIForXUID / XamShowAchievementsUI /
//   XamShowPlayerReviewUI / XamShowMarketplaceUI / XamLoaderSetLaunchData /
//   XamLoaderGetLaunchData / XamLoaderGetLaunchDataSize /
//   XamCreateEnumeratorHandle / XamGetPrivateEnumStructureFromHandle /
//   KeSetDisableBoostThread ................ src/kernel/port_xam_user.cpp,
//                                               src/kernel/port_kobj.cpp
//   NetDll_ioctlsocket / getsockname / recvfrom / sendto / XNetCleanup
//   NetDll_XNetRegisterKey / XNetUnregisterKey / XNetXnAddrToInAddr /
//   XNetServerToInAddr / XNetUnregisterInAddr / XNetConnect /
//   XNetGetConnectStatus / XNetQosListen / XNetQosLookup / XNetQosRelease /
//   XNetGetEthernetLinkStatus / XNetLogonGetTitleID ... src/kernel/port_net.cpp
//   NetDll_WSAGetLastError ......... KEPT AS A HOOK HERE UNTIL 2026-09-29; the
//   single live registration has MOVED to src/kernel/port_net.cpp:694, so the
//   line is deleted below. It was the one member of this family that was
//   already a live registration rather than a stub, and keeping it here while
//   port_net.cpp registered it too would have been two owners of one guest
//   function (AGENTS.md rule 4) and a duplicate external symbol.
// ---------------------------------------------------------------------------

GUEST_FUNCTION_HOOK(__imp__MmAllocatePhysicalMemoryEx,
                    MmAllocatePhysicalMemoryEx);
// F-609, 2026-09-29 (integration stream): the F-609 TASK 3 CORRECTION block
// that used to stand here is preserved in full further up this file, at the
// "Missing Xam/NetDll imports" heading, together with the superseding note that
// the binding has MOVED to src/kernel/port_net.cpp:694 and the definition is
// src/kernel/port_net.cpp:297. Nothing is lost by deleting it here: the arity
// proof it carried (NetDll_WSAGetLastError is the one NetDll thunk with no
// leading selector, so it takes zero arguments) is restated independently at
// src/kernel/port_net.cpp:92-100, against a separate measurement
// (ppc_recomp.82.cpp:6464-6468).
//
// Also removed here, all eighteen network family members, each of which was
// GUEST_FUNCTION_STUB(__imp__X) == `PPC_FUNC(name) { }`:
//
//   NetDll_getsockname, NetDll_ioctlsocket, NetDll_recvfrom, NetDll_sendto,
//   NetDll_XNetCleanup, NetDll_XNetConnect, NetDll_XNetGetConnectStatus,
//   NetDll_XNetGetEthernetLinkStatus, NetDll_XNetQosListen,
//   NetDll_XNetQosLookup, NetDll_XNetQosRelease, NetDll_XNetRegisterKey,
//   NetDll_XNetServerToInAddr, NetDll_XNetUnregisterInAddr,
//   NetDll_XNetUnregisterKey, NetDll_XNetXnAddrToInAddr, XNetLogonGetTitleID
//       -> registered at src/kernel/port_net.cpp:695-711 (17 of the 18; the
//          eighteenth, WSAGetLastError, is :694).
//
// The arity bug the port file documents (F-609's "missing leading
// caller/selector") is the reason these were invisible: the empty body meant
// the guest's own r3 came back, so a wrong-arity body could not be observed
// here either. Seventeen of the eighteen thunks do `li r3,1` and an N-deep `mr`
// shift, so seventeen take a leading selector; XNetLogonGetTitleID takes none
// because the guest `bl 0x827bd304` directly with the user index in r3.
// ---------------------------------------------------------------------------

// F-609 PORT BATCH, 2026-09-29. Removed: XamUserGetXUID, XamUserGetName,
// XamFree, XamAlloc, XamTaskShouldExit, XamTaskCloseHandle, XamTaskSchedule
//     -> src/kernel/port_xam_user.cpp:1128-1145 (registering hooks).
//   IoDismountVolume, IoDismountVolumeByFileHandle, KeSetDisableBoostThread,
//   KeTryToAcquireSpinLockAtRaisedIrql, NtCancelTimer, NtCreateMutant,
//   NtCreateTimer, NtDeviceIoControlFile, NtReleaseMutant, NtSetTimerEx,
//   XMsgCancelIORequest ... src/kernel/port_kobj.cpp:2334-2346.
//     XMsgCancelIORequest and KeSetDisableBoostThread had `void` bodies here
//     that returned the incoming r3 (a pointer) where a status belonged; the
//     port versions return the reference's status (Xenia xam_msg.cc:89-102 and
//     threading.cc:286-295). KeTryToAcquireSpinLockAtRaisedIrql is a genuine
//     behavioural fix in the same family: the old `void` body could not report
//     either outcome of the one CAS it stands for, so a waiter could not be told
//     it failed to acquire.
//   XamInputGetKeystrokeEx, XamParseGamerTileKey, XamReadTileToTexture,
//   XamWriteGamerTile, XamUserAreUsersFriends, XamUserCheckPrivilege,
//   XamUserCreateAchievementEnumerator, XamUserCreateStatsEnumerator,
//   XamVoiceClose, XamVoiceCreate, XamVoiceHeadsetPresent,
//   XamVoiceSubmitPacket ... src/kernel/port_xam_user.cpp:1146-1155 for the
//     Xam ones, src/kernel/port_voice_input.cpp:568-575 for the four voices.
//   XeKeysConsolePrivateKeySign, XeKeysConsoleSignatureVerification
//     ... src/kernel/port_voice_input.cpp:576-578. Both refuse. A
//     "verification" that always answers "verified" is a security-relevant lie
//     and is not acceptable in this tree at any point; there is no console
//     private key to verify against and no remote party to fool.
//   __snprintf, __vsnprintf, sprintf
//     ... src/kernel/port_kobj.cpp:2347-2349, backed by
//     kobjport::FormatCore, the tree's single format engine
//     (Xenia xboxkrnl_strings.cc format_core :120-683). __snprintf is a live,
//     heavily used path: all 7 guest call sites go through three wrappers
//     (sub_8244DC68, sub_8244E178, sub_8244E1F8).
// ---------------------------------------------------------------------------

GUEST_FUNCTION_HOOK(__imp__XAudioGetSpeakerConfig, XAudioGetSpeakerConfig);
// Not part of the F-609 port batch and NOT removed -- XamSessionCreateHandle and
// XamSessionRefObjByHandle are already-ported live hooks that live here, and
// they are preserved verbatim through the 2026-09-29 edit above.
GUEST_FUNCTION_HOOK(__imp__XamSessionCreateHandle, XamSessionCreateHandle);
GUEST_FUNCTION_HOOK(__imp__XamSessionRefObjByHandle, XamSessionRefObjByHandle);
GUEST_FUNCTION_HOOK(__imp__XAudioRegisterRenderDriverClient,
                    XAudioRegisterRenderDriverClient);
GUEST_FUNCTION_HOOK(__imp__XAudioUnregisterRenderDriverClient,
                    XAudioUnregisterRenderDriverClient);
GUEST_FUNCTION_HOOK(__imp__XAudioSubmitRenderDriverFrame,
                    XAudioSubmitRenderDriverFrame);
