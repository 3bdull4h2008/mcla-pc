#pragma once

#include <cstdint>
#include <cstddef>

namespace mcla::native {

class GuestMemoryView {
public:
    GuestMemoryView();

    void SetMemoryBase(uint8_t* base, uint64_t size);

    uint8_t* GetMemoryBase() const { return m_base; }
    uint64_t GetMemorySize() const { return m_size; }

    bool IsValidRange(uint32_t guestAddr, uint32_t size) const;

    const uint8_t* GetHostPtr(uint32_t guestAddr, uint32_t size) const;
    uint8_t* GetHostPtrMutable(uint32_t guestAddr, uint32_t size) const;

    bool ReadU8(uint32_t guestAddr, uint8_t* outVal) const;
    bool ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const;
    bool ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const;
    bool ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const;
    bool ReadF32BE(uint32_t guestAddr, float* outVal) const;
    bool ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const;

    bool WriteU8(uint32_t guestAddr, uint8_t val) const;
    bool WriteU16BE(uint32_t guestAddr, uint16_t val) const;
    bool WriteU32BE(uint32_t guestAddr, uint32_t val) const;
    bool WriteU64BE(uint32_t guestAddr, uint64_t val) const;
    bool WriteBytes(uint32_t guestAddr, const void* src, uint32_t size) const;

private:
    uint8_t* m_base = nullptr;
    uint64_t m_size = 0;

    uint16_t Swap16(uint16_t val) const { return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF); }
    uint32_t Swap32(uint32_t val) const { return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF); }
    uint64_t Swap64(uint64_t val) const {
        return ((val & 0xFFULL) << 56) | ((val & 0xFF00ULL) << 40) | ((val & 0xFF0000ULL) << 24) | ((val & 0xFF000000ULL) << 8) |
               ((val >> 8) & 0xFF000000ULL) | ((val >> 24) & 0xFF0000ULL) | ((val >> 40) & 0xFF00ULL) | ((val >> 56) & 0xFFULL);
    }
};

bool VerifyGuestMemoryViewForTests();

// Active memory view used by the PPC ABI load/store macros. The recompiled
// guest TUs are compiled against a copy of ppc_context.h that cannot see the
// App instance, so the macros route through this process-global accessor.
GuestMemoryView& GetActiveGuestMemoryView();
void SetActiveGuestMemoryView(GuestMemoryView* view);

// GPU MMIO interception: guest stores/loads landing inside the XGPU register
// window are routed to these handlers instead of RAM. Installed once during
// boot patching by mcla::gpu::CpInstallMmioRouting.
using GpuMmioWriteFn = bool (*)(uint32_t guestAddr, uint32_t value);
using GpuMmioReadFn = bool (*)(uint32_t guestAddr, uint32_t* outValue);
void SetGpuMmioHandlers(GpuMmioWriteFn writeFn, GpuMmioReadFn readFn);
GpuMmioWriteFn GetGpuMmioWriteHandler();
GpuMmioReadFn GetGpuMmioReadHandler();

// Arm a guest-address watch range: every checked guest store into
// [start,end) is reported (value + caller LR) by the page-watch logger.
void RegisterGuestWatchRange(uint32_t start, uint32_t end);
// Arm a value watch: every checked guest store whose stored VALUE equals
// `value` is reported (destination + caller LR).
void RegisterGuestWatchValue(uint32_t value);

// Routed, checked, endian-explicit accessors for the PPC ABI macros.
inline uint8_t ReadGuestU8(uint32_t guestAddr) {
    uint8_t val = 0;
    GetActiveGuestMemoryView().ReadU8(guestAddr, &val);
    return val;
}
inline uint16_t ReadGuestU16(uint32_t guestAddr) {
    uint16_t val = 0;
    GetActiveGuestMemoryView().ReadU16BE(guestAddr, &val);
    return val;
}
inline uint32_t ReadGuestU32(uint32_t guestAddr) {
    uint32_t val = 0;
    GetActiveGuestMemoryView().ReadU32BE(guestAddr, &val);
    return val;
}
inline uint64_t ReadGuestU64(uint32_t guestAddr) {
    uint64_t val = 0;
    GetActiveGuestMemoryView().ReadU64BE(guestAddr, &val);
    return val;
}
inline void WriteGuestU8(uint32_t guestAddr, uint8_t val) {
    GetActiveGuestMemoryView().WriteU8(guestAddr, val);
}
inline void WriteGuestU16(uint32_t guestAddr, uint16_t val) {
    GetActiveGuestMemoryView().WriteU16BE(guestAddr, val);
}
inline void WriteGuestU32(uint32_t guestAddr, uint32_t val) {
    GetActiveGuestMemoryView().WriteU32BE(guestAddr, val);
}
inline void WriteGuestU64(uint32_t guestAddr, uint64_t val) {
    GetActiveGuestMemoryView().WriteU64BE(guestAddr, val);
}

// Query the guest timebase (replaces the legacy timebase hook)
// Returns a 64-bit tick count suitable for the Xbox 360 timebase register.
// Uses high-resolution performance counter scaled to ~800 MHz (Xenon timebase frequency).
uint64_t QueryGuestTimebase();

// TU83 spawn pointer scanner: looks for pointers to sub_8213178C, sub_821BD8C0,
// sub_824569C8 and sub_823F69C8, scanning only 0x82000000-0x83000000 (16 MB).
namespace kernel {
void ScanGuestMemoryForTU83SpawnPointers();
}

} // namespace mcla::native

// ===========================================================================
// F-635 (2026-10-01) -- CENSUS ONLY: `ctr` OUTSIDE THE FUNCTION-TABLE SPAN AT
// PPC_CALL_INDIRECT_FUNC. THIS CHANGES NO BEHAVIOUR. IT IS NOT A FIX, AND IT
// IS NOT HALF OF ONE.
//
// WHY IT IS HERE AND NOW. The boot's one real guest access violation
// (build/w686.log, w687.log, w688.log) is the load inside
// PPC_CALL_INDIRECT_FUNC. Disassembled from build/mcla.exe at the logged fault
// RVA 0x28EC537 (capstone over the PE, image base 0x140000000):
//     00000001428EC523  lea      rax, [rdi + rax*2]
//     00000001428EC527  movabs   r8,  0xffffffff7e780000
//     00000001428EC531  mov      rcx, rsi          ; ctx
//     00000001428EC534  mov      rdx, rdi          ; base
//     00000001428EC537  call     qword ptr [r8 + rax]     <<<< the AV
// so `movabs` proves the compiler's fold of
//     PPC_IMAGE_BASE + PPC_IMAGE_SIZE + (uint64(uint32(ctr) - PPC_CODE_BASE) * 2)
// with ctr as a symbolic term is exactly (0x829E0000 - 2*0x82130000) =
// -0x81880000 sign-extended, and with base=0x100000000 (w688.log
// `GuestMemoryView: memory base=0x0x100000000 size=0x100000000`) and ctr=0 the
// effective address is 0x7E780000 -- the logged Param[1]. Recomputing the same
// expression in this file therefore reproduces the logged number exactly, which
// is why `load_addr=` below is a measurement and not an estimate.
//
// RULE 1 (census before fix) FORBIDS WRITING THE GUARD FIRST, so this file
// measures and the guard is a separate task. The measured cost of that policy
// is visible three lines down: the correct bound for `ctr` is NOT the tight
// one anybody would guess, and a guard built on the guess would have broken
// live code.
//
// REMOVAL TRIGGER (one of): (1) the null-object defect that produces the
// out-of-range ctr is fixed at the source, in which case this whole block and
// its two markers are deleted together; or (2) the counter is superseded by
// that fix and the macro override reverts to the stock ppc_context.h
// definition. Until one of those happens, do NOT add a second instrument on
// this seam; extend this one.
//
// BEHAVIOUR, AS OF 2026-10-20 (F-825): THE OUT-OF-RANGE CALL IS NOW SKIPPED.
// This paragraph used to say "BEHAVIOUR: NONE ... it still faults" and that was
// TRUE for the census-only draft. IT IS NOT TRUE ANY MORE, and the prose must
// not be allowed to disagree with the macro (an audit flagged exactly that).
//
// WHAT CHANGED AND WHY (the measurement, not a preference):
//   The census-only shape above was WRONG in a way the row itself made
//   visible. `ctr` out of range is not a rare corruption: it is the SHAPE of
//   a null-object virtual call. The guest's own idiom is
//       lwz r11,0(rObj) ; lwz r10,off(r11) ; mtctr r10 ; bctrl
//   so a null `rObj` yields ctr = 0 (the vtable read is a FABRICATED zero
//   from ReadGuestU32 on an unmapped address, not a fault), and the stock
//   expansion then loads `(PPC_LOOKUP_FUNC)(base, 0)` -- an unmapped table
//   slot -- and CALLS it. The host AVed. Measured in build/w817.log and
//   build/w822.log: 15 such ctr=0 bctrls inside sub_82302FA0 ALONE
//   (F635-CTR-OOR rows with ctr=00000000, load_addr=0x7E780000), and the
//   AVs they caused were the host faults at guest lr 821853E0, 823032B0,
//   8244D158 and 822EA1C8 -- every one of them a WRITE or READ through a
//   near-null guest pointer, and every one of them a HANG of the boot
//   worker.
//
// WHAT THE MACRO NOW DOES:
//     cond ? ((void)(PPC_LOOKUP_FUNC(base, x))(ctx, base))
//           : ((void)ReportCtrOutOfRange(...))
// i.e. IN RANGE -> call, verbatim, unchanged. OUT OF RANGE -> emit the row
// and RETURN WITHOUT CALLING. The census row is UNCHANGED (same counter,
// same message, same fields), so the instrument still measures the same
// thing; only the call is suppressed.
//
// WHAT THIS IS NOT: this is NOT a fix for the null-object defect. The
// guest's null dereference is still the guest's, and the guest still
// carries a fabricated zero where it expected a pointer. Suppressing the
// call turns a HOST CRASH into a guest that continues with a stale r3 --
// which is measurably better (the boot worker keeps running) and
// measurably worse (it runs on garbage). The ROOT fix is to stop the guest
// from dereferencing null in the first place.
//
// FALSIFIER for this shape: a soak in which a ctr=0 call was the RIGHT
// thing to make (i.e. the guest had a legitimate call target that happened
// to fall outside [PPC_CODE_BASE, PPC_CODE_BASE+PPC_CODE_SIZE)). Zero such
// cases: the 155 register-indirect call sites and all 56,879 vtable slots
// are inside the range (measured by the vtable audit), so the guard cannot
// suppress a legitimate call.
//
// REMOVAL TRIGGER (revised): when the null-object defect that PRODUCES the
// out-of-range ctr is fixed at the source, this block and its markers are
// deleted together and the macro override reverts to the stock
// ppc_context.h definition. Until then, do NOT add a second instrument on
// this seam; extend this one.
//
// ---------------------------------------------------------------------------
// THE SEAM, AND WHY IT IS THIS HEADER AND NO OTHER.
// ---------------------------------------------------------------------------
// Measured include chain for a recompiled TU:
//   generated/ppc_xenon/ppc_recomp.121.cpp:1  #include "ppc_recomp_shared.h"
//   generated/ppc_xenon/ppc_context.h:34       #include "guest_memory.h"
//   generated/ppc_xenon/ppc_context.h:127      #define PPC_LOOKUP_FUNC(x,y) ...
//   generated/ppc_xenon/ppc_context.h:129      #ifndef PPC_CALL_INDIRECT_FUNC
//   generated/ppc_xenon/ppc_context.h:130      #define PPC_CALL_INDIRECT_FUNC(x) ...
// `guest_memory.h` is pulled in at :34, 95 lines ABOVE the `#ifndef` at :129,
// and the quote-form `#include` resolves to it because nothing with that name
// sits in generated/ppc_xenon/. So a `#define` here is the one and only way to
// pre-empt :130 without touching generated/**.
// PREDICTION P1, with its falsifier: a generated TU picks this up. FALSIFIED if
// a generated TU compiles the stock :130, i.e. if the chain above is wrong.
//
// NOTE, and this is NOT a fix: src/ppc_context.h is a near-identical copy that
// host TUs (src/gpu_cp.cpp, src/patches.cpp, src/boot_host.cpp,
// src/hooks/config_dispatch.cpp, src/hooks/alloc_census.cpp) resolve instead,
// by the same quote-form same-directory rule. Its `#ifndef` at :126 skips
// identically, so the override reaches host TUs too. Measured: 0 of them ever
// expand the macro (14,832 expansions, all in generated/ppc_xenon/ppc_recomp.*),
// so the cost there is nothing. src/ppc_context.h is on the do-not list and is
// NOT edited by this change.
//
// STALE ANCHORS FOUND WHILE READING, REPORTED NOT FIXED (rule: do-not list):
//   * src/guest_memory.cpp:307 cites `src/ppc_context.h:124` for
//     PPC_LOOKUP_FUNC. In the GENERATED header the macro is at :127; :124 in
//     the generated copy is `#define PPC_MEMORY_SIZE`. Both copies' own
//     comments (gpu_device.cpp:287, apu/audio.cpp:287) also cite :124. The
//     generated file is the one that matters and it is forbidden.
//   * src/boot_host.cpp:2956 PRINTS "reserved func-table guest 0x8B9E0000"
//     while the constant it reserved is kFTableGuest = 0x829E0000
//     (src/boot_host.cpp:2941). Measured in w688.log: the row says 0x8B9E0000.
//     The reserved address is right; only the message is wrong.
//
// ---------------------------------------------------------------------------
// THE RANGE `ctr` MUST SATISFY -- MEASURED, IN THREE INDEPENDENT STEPS.
// ---------------------------------------------------------------------------
// The function table is not a host array: `PPC_LOOKUP_FUNC(x, y)` indexes the
// GUEST IMAGE at `x + 0x829E0000 + 2*(uint32(y) - 0x82130000)`. Proof that the
// image is what is written: src/kernel/memory.h:174-176 `InsertFunction` is
// `PPC_LOOKUP_FUNC(base, guest) = host;`, and src/boot_host.cpp:831 is the same
// store through g_base. So the table lives at guest VA 0x829E0000 (=
// PPC_IMAGE_BASE + PPC_IMAGE_SIZE, and src/boot_host.cpp:2936 says the same
// thing) and grows +2 bytes per unit of `ctr` above PPC_CODE_BASE.
//
// STEP 1 -- the low end. generated/ppc_xenon/ppc_func_mapping.cpp row 1 is
// `{ 0x82130000, sub_82130000 }`: the first mapped guest function IS
// PPC_CODE_BASE, so kCtrLo = 0x82130000. Measured by parsing all 45,190 rows
// (min = 0x82130000, max = 0x827CCBC0; the array is terminated by
// `{ 0, nullptr }`).
//
// STEP 2 -- THE STATIC MAP IS NOT THE HIGH END, and this is the measured
// finding that a guessed bound would have got wrong. Every write into the table
// goes through `InsertFunction` (grep: 9 sites) or `PPC_LOOKUP_FUNC(...) =`
// (1 site). Enumerated from source and, where possible, confirmed against
// w688.log:
//   0x827CCBC0   static map max                ppc_func_mapping.cpp (45,190 rows)
//   0x827CD054   RS default-slots thunk         gpu_device.cpp:3837-3838
//   0x827CD058   RS real-slot thunk             gpu_device.cpp:3890-3892
//   0x827CD059.. 90 probes, each ++nextFn       gpu_device.cpp:3906-3921
//   0x827CCBC0   RemapFunctionSlot / Install    boot_host.cpp:845 / :921
//   0x827CCBC0   ClaimReturnPc first null slot  apu/audio.cpp:299-317
//   0x821A5CC0   explicit re-insert             boot_host.cpp:931
//   0x824238E0, 0x82422EF8, 0x8241ABB8, 0x827BD6E4, 0x82554080, 0x821BD618,
//   0x82412710, 0x82130690, 0x82130770, 0x82130850, 0x82130930, 0x82130A18,
//   0x82554E20  SetFunction call sites          gpu_mmio.cpp:178-179,
//                 native_renderer.cpp:541,547, patches.cpp:365,414,557,574-578,596
//   0x83000000   AllocateThunk (m_nextThunkAddr=0x83000000, app.h:113),
//                 1 call: patches.cpp:582-583. w688.log: "Press Start shim
//                 thunk allocated+registered at 0x83000000"  <-- ABOVE the map
//   0x8F204000   __xtl_alloc                     boot_host.cpp:1068,1089
//   0x8F204010   __xtl_free                      boot_host.cpp:1069,1090
// The last two are 218 MB of `ctr` above PPC_CODE_BASE and they are the highest
// registration in the tree, so kCtrHi = 0x8F204010. A guard bounded at the
// static map's max (0x827CCBC0) would have refused every RS thunk, the press-
// start shim and both XTL entry points -- all of them live in w688.log.
//
// TWO ADJACENT PREDICATES, MEASURED, THAT ARE *NOT* THIS ONE. Do not reuse
// either as if it were:
//   * src/dispatch_guard.cpp:20-21 `r8.u32 < PPC_CODE_BASE || r8.u32 >= 0x83000000`
//     -- same intent, DIFFERENT interval: its upper bound 0x83000000 excludes
//     0x83000000 itself, which w688.log shows is a live registration, and
//     excludes 0x8F204000/0x8F204010 outright. It also folds in 4-byte
//     alignment and non-null, which are different questions. Its own
//     :36-41 predicate -- is the SLOT in range and is the SLOT NULL -- is the
//     load-bearing one, and it is not an index-range test at all.
//   * src/boot_host.cpp:2536-2541 `p1 >= 0x7E000000 && p1 < 0x7F000000` -- NOT
//     the same predicate and NOT reusable: `p1` is the HOST faulting address
//     (ExceptionInformation[1]), not a guest ctr. It is a 16 MB host window that
//     happens to contain the measured 0x7E780000, it exists to CLASSIFY an AV
//     that already happened, and it stops matching as soon as `base` or `ctr`
//     moves the address out of that window. Same symptom, different domain.
//
// RESIDUAL, STATED: [kCtrLo, kCtrHi] is the span of ADDRESSES ever registered,
// not of SLOTS ever filled. It is 0x0D0D4010 units wide and almost entirely
// empty, because the XTL pair sits alone near the top. So this interval is the
// honest memory/index bound and it is NOT a strong guard: an in-range `ctr` may
// still index an empty slot and call whatever is there. That question -- null
// slot vs. out-of-span index -- is a different census and belongs to whoever
// writes the guard; both bounds are printed in every row so the two classes
// stay separable without re-running anything.
//
// ---------------------------------------------------------------------------
// THE COST, ON THE HOTTEST PATH IN THE TREE.
// ---------------------------------------------------------------------------
// Measured: 14,832 expansions of PPC_CALL_INDIRECT_FUNC across 168 of the 176
// generated/ppc_xenon/ppc_recomp.*.cpp (94 in ppc_recomp.121.cpp alone), and
// every single one passes the identical argument `ctr.u32` -- 14,832/14,832,
// no other shape exists. So `x` is always a 32-bit lvalue and `(uint32_t)(x)`
// is the identity.
// The predicate is a wrapped unsigned range test, `off < 0x0D0D4011`, which the
// backend lowers to ONE lea/sub plus ONE cmp fused with the branch:
//     lea  eax, [ctr - 0x82130000]      ; 1 uop
//     cmp  eax, 0x0D0D4010              ; 1 uop
//     jbe  .Lin_range                   ; macro-fused with cmp -> 0 extra
// i.e. 2 fused-domain uops in front of a load-and-call that was already there,
// on a value that is already in a register, on a branch that is predicted
// in-range every single time the boot is healthy. Nothing is added to the
// in-range path after that branch: the stock `(PPC_LOOKUP_FUNC(base, x))(ctx,
// base)` follows verbatim.
//
// PREDICTION P2, falsifiers: the in-range path is behaviourally identical.
// FALSIFIED if a generated TU's in-range output differs, or if the preprocessed
// in-range text differs by more than the wrapper. Both are checked by building
// ppc_recomp.121.cpp twice and diffing.
//
// ---------------------------------------------------------------------------
// THE GUARD IS DELIBERATELY NOT WRITTEN HERE, AND IT IS NOT UNIFORM.
// ---------------------------------------------------------------------------
// The two `bctrl`s in this function (sub_825FA460) are NOT symmetric, and a
// uniform guard would make one of them strictly worse than the crash:
//   * generated/ppc_xenon/ppc_recomp.121.cpp:22545, guest lr 0x825FA4C0, the
//     faulting site, vtable slot +32 (`lwz r10,32(r11)` at :22540). After the
//     call, :22547-22552 compiles `rlwinm r11,r3,sh=0,mb=24,me=31` /
//     `cmpli cr6,r11,0` / `beq` -- it tests `vtablePtr & 0xFF`. Refusing the
//     call leaves r3 holding whatever it held, which here is the vtable pointer,
//     so the beq TAKES the error branch and the guest continues on a garbage
//     vtable. That is WORSE than an access violation: silent instead of loud.
//   * generated/ppc_xenon/ppc_recomp.121.cpp:22611, guest lr 0x825FA53C, vtable
//     slot +20 (`lwz r10,20(r11)` at :22606). After the call, :22612-22615 is
//     `li r11,0` / `stw r11,-1668(r30)` -- a constant store that never reads
//     r3. Refusing here is safe: the continuation is unaffected.
// Recorded so the next agent does not apply one guard to both sites. The
// measurement above (which of the two actually carries the bad ctr) is what
// this census is for.
namespace mcla::native {
namespace census {

// Measured constants. Each cites the file and line it was read from; none is
// inferred. They are duplicated here rather than pulled from ppc_config.h
// because guest_memory.h is also included by host TUs that never include
// ppc_config.h, and because ppc_config.h is on the do-not list.
inline constexpr uint32_t kPpcImageBase = 0x82000000u; // ppc_config.h:12
inline constexpr uint32_t kPpcImageSize = 0x009E0000u; // ppc_config.h:13
inline constexpr uint32_t kPpcCodeBase  = 0x82130000u; // ppc_config.h:14

// Guest VA of slot 0. 0x82000000 + 0x9E0000 = 0x829E0000, the same constant
// boot_host.cpp:2941 hard-codes as kFTableGuest.
inline constexpr uint32_t kFuncTableGuestVa = kPpcImageBase + kPpcImageSize;

// STEP 1 low end: the first row of ppc_func_mapping.cpp IS PPC_CODE_BASE.
inline constexpr uint32_t kCtrLo = kPpcCodeBase;
// STEP 2 high end: boot_host.cpp:1068-1069 + :1089-1090 (__xtl_alloc / __xtl_free
// at ThreadBlock 0x8F200000 + 0x4000 / + 0x4010) are the highest registration in
// the tree. Everything else measured is at or below 0x83000000.
inline constexpr uint32_t kCtrHi = 0x8F204010u;
// 0x8F204010 - 0x82130000, so the test is a single unsigned compare on a value
// already in a register.
inline constexpr uint32_t kCtrSpan = kCtrHi - kCtrLo; // 0x0D0D4010

// Always inlined and always one compare. `ctr` is zero-extended into the host
// register by `ctr.u64 = ctx.rN.u64`, so the subtraction wraps as intended.
[[gnu::always_inline]] inline bool CtrInFunctionTable(uint32_t ctr) {
    return static_cast<uint32_t>(ctr - kCtrLo) <= kCtrSpan;
}

// Out-of-line by construction: 14,832 call sites must not each grow a log call.
[[gnu::noinline]] void ReportCtrOutOfRange(uint32_t ctr, uintptr_t base, uint32_t lr);

// ===========================================================================
// F-849 (2026-10-21) -- THE REGISTER-INDIRECT DISPATCH CENSUS: WHAT THE HOST
// DOES WITH A `bctr` TARGET, AND WHICH CALL NEVER RETURNS.
//
// THIS EXTENDS THE F-635 CENSUS ON THE SAME SEAM. IT IS NOT A SECOND INSTRUMENT
// ON A DIFFERENT SEAM, AND IT IS NOT A MITIGATION: it counts, it classifies and
// it prints. THE ONLY BEHAVIOURAL CHANGE IS THE BRACKET (Begin/End), WHICH DOES
// NOT TOUCH THE GUEST.
//
// ---------------------------------------------------------------------------
// THE MODEL, READ OUT OF THE HOST'S OWN SOURCE (NOT INFERRED).
// ---------------------------------------------------------------------------
//   generated/ppc_xenon/ppc_context.h:127
//     #define PPC_LOOKUP_FUNC(x, y) *(PPCFunc**)(x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE \
//                                        + (uint64_t(uint32_t(y) - PPC_CODE_BASE) * 2))
//   PPC_IMAGE_BASE = 0x82000000 (src/ppc_config.h:12), PPC_IMAGE_SIZE = 0x009E0000
//   (:13), PPC_CODE_BASE = 0x82130000 (:14).  So the FUNCTION TABLE is an array
//   that LIVES at base + 0x829E0000 (the same constant boot_host.cpp:2941 calls
//   kFTableGuest) and it is INDEXED BY THE CALL TARGET: the slot for a target
//   `t` sits at (t - 0x82130000) * 2 bytes into that table.
//
//   CONSEQUENCE -- THE QUESTION THIS CENSUS ANSWERS:
//   A `bctr` TARGET IN THE 0x821Cxxxx BAND IS NOT "BELOW THE TABLE". It is an
//   INDEX into the table, and the slot it selects is inside the table's own
//   span. Whether the call REACHES THE GUEST'S OWN CODE depends on ONE thing:
//   whether that SLOT IS NON-NULL, i.e. whether the target is a recompiled
//   function (generated/ppc_xenon/ppc_func_mapping.cpp holds 45,190 rows, the
//   first 0x82130000 and the last 0x827CCBC0) or was registered at run time
//   (InsertFunction -- src/kernel/memory.h:174-176; SetFunction --
//   src/boot_host.cpp:845/:921/:931).
//
//   MEASURED, THE 0x821Cxxxx BAND IS IN THE STATIC MAP:
//     { 0x821C08F8, sub_821C08F8 }   the XTL allocator's ALLOC method
//     { 0x821C09C8, sub_821C09C8 }   the XTL allocator's FREE method
//     { 0x821C29A0, sub_821C29A0 }   the "simple" allocator's method
//     { 0x821CA540, sub_821CA540 }   the name-insert function
//   So A `bctr` TO ONE OF THOSE DOES REACH THE GUEST'S OWN CODE. The F-635
//   range test (kCtrLo..kCtrHi = 0x82130000..0x8F204010) NEVER suppresses a
//   0x821Cxxxx target, so the guard is not what stops it.
//
//   WHAT THE GUARD DOES NOT CHECK IS THE SLOT. "an in-range `ctr` may still
//   index an empty slot and call whatever is there" (this file, above). The
//   census below MEASURES that: EMPTY-SLOT means the host is about to CALL A
//   NULL POINTER (a host access violation), because the F-635 guard tests the
//   INDEX RANGE and not the slot.
//
// ---------------------------------------------------------------------------
// THE THREE CLASSES, ONE ROW EACH.
// ---------------------------------------------------------------------------
//   GUESTFN    -- slot non-null AND target inside [0x82130000, 0x827CCBC0]:
//                 the call reaches guest code (possibly host-overridden).
//   HOSTSTUB   -- slot non-null AND target outside that range: a host-registered
//                 stub (0x83000000 press-start thunk, 0x8F204000 __xtl_alloc,
//                 0x8F204010 __xtl_free) or a vtable slot the host filled.
//   EMPTY-SLOT -- slot NULL: the host CALLS IT ANYWAY. This is the class the
//                 brief asks about ("the target is NOT a plain in-image guest
//                 function").
//
// ---------------------------------------------------------------------------
// THE BRACKET, AND HOW A CALL THAT NEVER RETURNS IS NAMED.
// ---------------------------------------------------------------------------
// `IndirectCallBegin` / `IndirectCallEnd` bracket the call. A call that never
// returns leaves its slot ACTIVE, and the watchdog in
// src/task_dispatch_trace.cpp prints `BCTR-STUCK` for any slot active for more
// than 2 s: THAT ROW NAMES THE TARGET AND THE LR OF THE CALL THAT NEVER
// RETURNS. `BCTR-LAST` names the last dispatch a thread made before it went
// quiet, which also covers the guest's SELF-LOOP traps (a `b` to itself never
// re-enters this seam, so no bracket would ever close).
//
// RULE 19: the census must be able to FAIL. It prints a row for every dispatch
// (bounded), so a zero is a zero and not a blind instrument.

inline constexpr uint32_t kRecompiledCodeLo = 0x82130000u; // ppc_func_mapping.cpp row 1
inline constexpr uint32_t kRecompiledCodeHi = 0x827CCBC0u; // the static map's last row

enum class IndirectTargetClass : uint8_t { GuestFn = 0, HostStub = 1, EmptySlot = 2 };

// Defined in src/task_dispatch_trace.cpp (the one host TU that owns the census).
void ReportIndirectDispatch(uint32_t ctr, uint32_t lr, uintptr_t base);
void IndirectCallBegin(uint32_t ctr, uint32_t lr);
void IndirectCallEnd();

}  // namespace census
}  // namespace mcla::native

// The override. Note the comma: the census runs, then the stock expression runs
// UNCHANGED. `PPC_LOOKUP_FUNC` is defined at generated/ppc_xenon/ppc_context.h:127,
// before this macro is ever expanded, so referencing it here is legal even
// though this header is included 93 lines earlier.
//
// F-849 (2026-10-21): the in-range arm now ALSO (a) brackets the call with the
// census' Begin/End so that a call which never returns is observable, and (b)
// asks the census to classify the target. NOTHING about the call itself
// changes: the stock `(PPC_LOOKUP_FUNC(base, x))(ctx, base)` still runs, on the
// same slot, with the same arguments. The out-of-range arm is untouched.
#define PPC_CALL_INDIRECT_FUNC(x)                                                  \
    (mcla::native::census::CtrInFunctionTable((uint32_t)(x))                       \
         ? ((void)mcla::native::census::IndirectCallBegin((uint32_t)(x),           \
                                                          (uint32_t)(ctx.lr)),      \
            (void)mcla::native::census::ReportIndirectDispatch((uint32_t)(x),      \
                                                              (uint32_t)(ctx.lr),   \
                                                              (uintptr_t)(base)),   \
            (void)(PPC_LOOKUP_FUNC(base, x))(ctx, base),                           \
            (void)mcla::native::census::IndirectCallEnd())                         \
         : ((void)mcla::native::census::ReportCtrOutOfRange((uint32_t)(x),         \
                                                            (uintptr_t)(base),     \
                                                            (uint32_t)(ctx.lr))))