#pragma once

// ===========================================================================
// port_kobj.h -- console kernel-object and string functions, ported from
// Xenia into this recompiler. F-609 (native-only charter), F-611 (call ABI).
//
// WHAT THIS FILE IS. Fourteen console exports whose bodies in
// src/kernel/imports.cpp were `GUEST_FUNCTION_STUB(__imp__X)` -- an empty body
// that left r3 equal to the incoming r3, so every caller read a POINTER back
// where an NTSTATUS or a count belonged. Each body here is either REAL (built
// on state this host genuinely has, cited to a Xenia file:line), PARTIAL (one
// control code of several answered from a console constant, the rest refused --
// counted under BOTH KOBJPORT-IOCTL-OK and KOBJPORT-REFUSE), or REFUSE (returns
// the reference's own failure status, counted under KOBJPORT-REFUSE).
//
// WHAT THIS FILE IS NOT. It is not an emulator, it is not a stub layer, and it
// does not contain a second printf engine -- kobjport::FormatCore below is the
// project's single engine, and src/kernel/imports.cpp:1957 `void DbgPrint()` is
// STILL a stub, so there was no existing engine to reuse (that was the point to
// check). DbgPrint should adopt this one rather than grow a second; that edit
// belongs to whoever owns imports.cpp.
//
// REMOVAL CONDITION for anything refused here. A refusal is not a placeholder
// and must not outlive its cause. Each refused body below names the ONE
// measurable thing that would let it become real; until that measurement is
// true, the refusal is the correct answer and the count must be visible in a
// soak. Concretely:
//   NtDeviceIoControlFile   - PARTIAL, one code of three. 0x70000
//                             GET_DRIVE_GEOMETRY is ANSWERED (bytes per
//                             sector is a console constant, established at
//                             xboxkrnl_io_info.cc:320 and written at
//                             xboxkrnl_io.cc:695); 0x74004
//                             GET_PARTITION_INFO and 0x24400
//                             IOCTL_SCSI_PASS_THROUGH are named refusals,
//                             and each becomes real when (a) a real backing
//                             store exists at guest device 0x100000 (the XAM
//                             cache/utility volume the title opens), which
//                             settles the partition CAPACITY that is still
//                             UNVERIFIED, and (b) an optical-drive pass-through
//                             with a real completion path exists for the async
//                             code. The volume capacity is deliberately NOT
//                             taken from the reference's hardcoded 0xFF000.
//   NtSetTimerEx            - an APC delivery path (Xenia delivers the expiry
//                             routine with XThread::EnqueueApc,
//                             xtimer.cc:69-82). No such queue exists in src/.
//   IoDismountVolume[By..]  - not even in the reference (0 hits in the whole
//                             Xenia kernel tree), and it is destructive.
// The Mutant and Timer classes below are real host objects and stay; the wait
// allow-list in imports.cpp:1384-1388 must gain `typeid(Mutant)` before a
// guest can park on one (see port_kobj.cpp, NtCreateMutant).
// ===========================================================================

#include <stdint.h>

// INCLUDE ORDER IS LOAD-BEARING. Whoever includes this header must have included
// <stdafx.h> first: stdafx.h:34 pulls in the GENERATED ppc_context.h, which is
// where PPCFunc / PPC_FUNC / PPC_LOOKUP_FUNC live, and xdm.h -> memory.h:170-175
// uses all three. <cpu/ppc_context.h> is a different, small header that does NOT
// define them. src/kernel/mutex.h:5 derives Mutex from CRITICAL_SECTION, so
// windows.h has to arrive before the standard <mutex> / <condition_variable> too
// (kernel_objects.h:12-14 records the same constraint for logging.h).
#include "kernel/xdm.h"  // KernelObject, CreateKernelObject, identity map
#include "kernel/xbox.h" // XDISPATCHER_HEADER, be<>, STATUS_*, XOBJECT_ATTRIBUTES

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <string>

// ---------------------------------------------------------------------------
// Statuses this file returns that src/kernel/xbox.h:412-454 does not define.
// Values measured in .research/xenia/src/xenia/xbox.h, not recalled:
//   :57  X_STATUS_BUFFER_TOO_SMALL      0xC0000023
//   :46  X_STATUS_NOT_IMPLEMENTED       0xC0000002
//   :63  X_STATUS_MUTANT_NOT_OWNED      0xC0000046
//   :41  X_STATUS_OBJECT_NAME_EXISTS    0x40000000
//   :68  X_STATUS_NOT_SUPPORTED         0xC00000BB
// `STATUS_NO_SUCH_DEVICE` is not an Xenia constant; it is the NTSTATUS that
// means "this device is not on this machine", which is the true state of the
// utility-cache device 0x100000 the title opens.
// `STATUS_INVALID_PARAMETER` (0xC000000D) is NOT re-declared here: src/kernel/
// xbox.h:427-428 already defines that macro with the same value
// (.research/xenia/src/xenia/xbox.h:51), so it is named, not re-typed.
// ---------------------------------------------------------------------------
namespace kobjport {
constexpr uint32_t kStatusBufferTooSmall = 0xC0000023u;
constexpr uint32_t kStatusNotImplemented = 0xC0000002u;
constexpr uint32_t kStatusMutantNotOwned = 0xC0000046u;
constexpr uint32_t kStatusObjectNameExists = 0x40000000u;
constexpr uint32_t kStatusNoSuchDevice = 0xC000000Eu;
constexpr uint32_t kStatusNotSupported = 0xC00000BBu;
}  // namespace kobjport

// ===========================================================================
// The one format engine (see the header paragraph). Faithful port of
// .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_strings.cc:
//   format_core          :120-683   (states, flags, conversions, padding)
//   format_double        :87-118
//   StackArgList         :685-701   -> GuestStackArgs
//   ArrayArgList         :703-720   -> GuestArrayArgs
//   StringFormatData     :722-757   -> GuestFormatData
// Both argument readers go through checked, endian-explicit guest memory and
// ArgTranslator::GetIntegerArgumentValue (function.h:169-203), the reader that
// owns the F611-STACKARG-READ marker. No reinterpret_cast of guest data, and
// no assert on a guest value anywhere in this engine.
// ===========================================================================
namespace kobjport {

// Abstract sink + cursor over a guest format string. Mirrors Xenia's
// FormatData (:66-72) / StringFormatData (:722-757) with the raw pointer
// replaced by a checked guest VA.
class GuestFormatData
{
 public:
    explicit GuestFormatData(uint32_t formatVa) : formatVa_(formatVa) {}

    // Xenia StringFormatData::get() (:726-732): stops at NUL without consuming.
    uint16_t get();
    uint16_t peek(int32_t offset);
    void skip(int32_t count);
    bool put(uint16_t c);

    const std::string& str() const { return output_; }
    bool formatUnreadable() const { return unreadable_; }

 private:
    uint32_t formatVa_;
    uint32_t cursor_ = 0;
    std::string output_;
    bool unreadable_ = false;
};

// Xenia ArgList (:74-78).
class ArgList
{
 public:
    virtual ~ArgList() = default;
    virtual uint32_t get32() = 0;
    virtual uint64_t get64() = 0;
};

// Xenia StackArgList (:685-701). `firstArg` is the 0-based ordinal of the first
// variadic argument in the PPC register/stack sequence: 3 for _snprintf and
// sprintf, 1 for DbgPrint. The 9th and beyond come off the guest stack through
// ArgTranslator (function.h:162-203).
class GuestStackArgs final : public ArgList
{
 public:
    GuestStackArgs(int32_t firstArg, uint8_t* base) : index_(firstArg), base_(base) {}
    uint32_t get32() override { return static_cast<uint32_t>(get64()); }
    uint64_t get64() override;

 private:
    int32_t index_;
    uint8_t* base_;
};

// Xenia ArrayArgList (:703-720) -- the `va_list` of _vsnprintf: 8-byte slots
// read from a guest array, again via the checked BE reader.
class GuestArrayArgs final : public ArgList
{
 public:
    explicit GuestArrayArgs(uint32_t argListVa) : argListVa_(argListVa) {}
    uint32_t get32() override { return static_cast<uint32_t>(get64()); }
    uint64_t get64() override;

 private:
    uint32_t argListVa_;
    uint32_t index_ = 0;
};

std::string FormatDouble(double value, int32_t precision, uint16_t c, uint32_t flags);
int32_t FormatCore(GuestFormatData& data, ArgList& args, bool wide);

}  // namespace kobjport

// ===========================================================================
// REAL kernel objects. Both derive from KernelObject (src/kernel/xdm.h:17-47),
// are allocated from the same physical heap as every other NtCreate* product
// (CreateKernelObject, xdm.h:49-54), and carry a real guest handle registered
// in WrapperIdentityMap (xdm.h:110-137) so a waiter and a signaller resolve the
// SAME object -- the F-039 lesson. Neither is a counter.
// ===========================================================================

// Mutant -- Xenia's mutant is a Win32 recursive mutex
// (.research/xenia/src/xenia/base/threading_win.cc:269-277 CreateMutex, and
// :266 Release() == ReleaseMutex, which fails when the caller does not own it).
// That is the state machine ported here: recursion count + owner, Wait
// acquires (recursively for the owner), Release gives one count back and
// reports STATUS_MUTANT_NOT_OWNED when the caller owns nothing.
struct Mutant final : KernelObject
{
    explicit Mutant(bool initialOwner);

    uint32_t Wait(uint32_t timeout) override;
    bool Release(uint32_t ownerThread);  // Xenia XMutant::ReleaseMutant

    // Guest thread identity (r13, the PCR/TEB base) of the current caller, or
    // 0 when there is no live context. Host-side and host-order on purpose:
    // it never touches guest memory.
    static uint32_t CurrentThreadToken();

 private:
    std::mutex m_;
    std::condition_variable cv_;
    uint32_t owner_ = 0;      // guest r13, 0 == unowned
    uint32_t recursion_ = 0;  // Win32 recursion count
};

// Timer -- Xenia's XTimer is a manual-reset (NotificationTimer, type 0) or
// synchronization (type 1) timer (.research/xenia/src/xenia/kernel/xtimer.cc:
// 25-39). The object and its type are real here; the ARMING is refused by
// NtSetTimerEx because expiry delivery needs an APC queue this host does not
// have. `armed` therefore only ever reads false, and every read of it says so.
struct TimerObject final : KernelObject
{
    explicit TimerObject(uint32_t timerType);

    uint32_t Wait(uint32_t timeout) override;
    bool Cancel();  // Xenia XTimer::Cancel (xtimer.cc:95-97)

    uint32_t timerType() const { return timerType_; }
    bool armed() const { return armed_.load(std::memory_order_acquire); }

 private:
    std::mutex m_;
    std::condition_variable cv_;
    uint32_t timerType_;               // 0 Notification, 1 Synchronization
    std::atomic<bool> armed_{false};   // never set true: NtSetTimerEx refuses
    std::atomic<bool> signalled_{false};
};

// ===========================================================================
// The fourteen bodies. Every one is registered by port_kobj.cpp with
// GUEST_FUNCTION_HOOK, matching the form used by the already-ported
// RtlCompareMemoryUlong (imports.cpp:6441).
// ===========================================================================
namespace kobjport {

// REAL  -- Xenia xam_msg.cc:89-102 (+ xbox.h:210-213 for the +0xC event slot).
uint32_t XMsgCancelIORequest(void* overlapped, uint32_t wait);

// REAL  -- threading.cc:967-974. One CAS, 1 on success / 0 on failure; the
// project's own KeAcquireSpinLockAtRaisedIrql (imports.cpp:3782-3792) and
// KeReleaseSpinLockFromRaisedIrql (:3777-3780) use the same 0->owner word.
uint32_t KeTryToAcquireSpinLockAtRaisedIrql(uint32_t* spinLock);

// REAL  -- threading.cc:286-295: looks the thread up, does nothing, returns 0.
// The old `void` body returned the incoming r3 (the thread pointer) in r3.
uint32_t KeSetDisableBoostThread(uint32_t thread, uint32_t disabled);

// REAL  -- threading.cc:638-670. Real object, real handle. Divergence, stated
// in the body: the project has no named-object table, so a named create does
// not collide (Xenia returns STATUS_OBJECT_NAME_EXISTS).
// `objectAttributes` is the raw guest VA of the XOBJECT_ATTRIBUTES, NOT a host
// pointer: the Name field is read out of it with the checked BE reader. Passing
// it as void* would make the framework translate it and then force this file to
// un-translate it, and a name that is a bad VA would never be reportable.
uint32_t NtCreateMutant(uint32_t handleOut, uint32_t objectAttributes,
                        uint32_t initialOwner);

// REAL  -- threading.cc:672-696 + xmutant.cc:41-55. `unknown` is read and
// ignored exactly as Xenia ignores it (it asserts it is zero; the guest does
// pass 0 -- measured at ppc_recomp.80.cpp:15378-15379).
uint32_t NtReleaseMutant(uint32_t mutantHandle, uint32_t unknown);

// REAL  -- threading.cc:698-732. A real timer object with a real handle.
// `objectAttributes` is a raw guest VA, as for NtCreateMutant.
uint32_t NtCreateTimer(uint32_t handleOut, uint32_t objectAttributes,
                       uint32_t timerType);

// REFUSE -- xtimer.cc:41-93 delivers expiry through XThread::EnqueueApc
// (:79-82). No such APC queue exists in src/ (measured: zero hits for EnqueueApc
// / QueueApc outside comments). Returns X_STATUS_NOT_IMPLEMENTED.
// `dueTime` is the raw guest VA of the 64-bit due time, which the reference
// dereferences (threading.cc:742) and which is read here with ReadU64BE.
uint32_t NtSetTimerEx(uint32_t timerHandle, uint32_t dueTime, uint32_t routine,
                      uint32_t unkOne, uint32_t routineArg, uint32_t resume,
                      uint32_t periodMs, uint32_t unkZero);

// REAL  -- threading.cc:760-776. Cancels, and reports "not armed", which is
// TRUE here precisely because NtSetTimerEx refuses to arm.
uint32_t NtCancelTimer(uint32_t timerHandle, uint32_t currentStateOut);

// MIXED, one answer and two refusals -- 2026-09-30, this was a blanket REFUSE
// and the blanket was measured to cost 158 attempts in 180 s (build/w661.log,
// 158 KOBJPORT-REFUSE rows for fn=NtDeviceIoControlFile, every one of them
// code 0x70000). It is dispatched on the control code explicitly, and the three
// codes the recompiled guest passes are identified, not guessed:
//
//   0x70000  IOCTL_DISK_GET_DRIVE_GEOMETRY (xboxkrnl_io.cc:686).
//            ANSWERED. Reply is 8 bytes, big-endian, two uint32:
//              +0  total sector count  -> 0, the ABSENCE of a capacity
//              +4  bytes per sector    -> 512
//            512 is established, not chosen: the console's block layer reports
//            it to userland and Xenia asserts it
//            (xboxkrnl_io_info.cc:319-320), and it is what the reference writes
//            (xboxkrnl_io.cc:695). 2048 is the DVD FILE SYSTEM sector
//            (extract_iso.py:22), a different layer, and is NOT used. The +0
//            capacity is left at zero rather than fabricated: no source
//            establishes the console's cache volume size, the reference's
//            0xFF000 is not carried forward, and reply+0 is read by nobody in
//            the image (the one load is reply+4, ppc_recomp.82.cpp:10801-10802).
//            Refuses only a short buffer, with the reference's own
//            X_STATUS_BUFFER_TOO_SMALL (xboxkrnl_io.cc:690-693).
//   0x74004  IOCTL_DISK_GET_PARTITION_INFO (xboxkrnl_io.cc:687). REFUSED
//            STATUS_NO_SUCH_DEVICE: the only field the title reads is a
//            per-volume CAPACITY, and that is not establishable here.
//   0x24400  IOCTL_SCSI_PASS_THROUGH (decoded from the value: device 2 =
//            FILE_DEVICE_CD_ROM, function 0x100, METHOD_BUFFERED,
//            FILE_READ_DATA). REFUSED STATUS_NOT_SUPPORTED: it needs a physical
//            optical drive, it is the async site, and an armed-but-undelivered
//            completion would park the title on an event forever.
//   other    REFUSED STATUS_INVALID_PARAMETER -- its own counters and its own
//            KOBJPORT-IOCTL-UNKNOWN marker, the reference's own status for an
//            unhandled IOCTL (xboxkrnl_io.cc:703-708). Never a fallthrough.
//
// Every pointer here is a RAW GUEST VA. That is deliberate and it is what makes
// the 10th and 11th arguments work at all: the framework reads ordinals 8 and 9
// off the guest stack through ArgTranslator::StackArgVa (function.h:162-167),
// which is the same r1+0x54 base the guest stored its two stack arguments at
// (ppc_recomp.82.cpp:10762-10769). The `handle` argument is never
// dereferenced: the project's NtOpenFile is a `void` stub (imports.cpp:1042) so
// the title arrives here holding a stack address, not a handle.
uint32_t NtDeviceIoControlFile(uint32_t handle, uint32_t event,
                               uint32_t apcRoutine, uint32_t apcContext,
                               uint32_t ioStatusBlock, uint32_t ioControlCode,
                               uint32_t inputBuffer, uint32_t inputBufferLength,
                               uint32_t outputBuffer, uint32_t outputBufferLength);

// REFUSE -- 0 hits for IoDismountVolume in the entire Xenia kernel tree, and
// the guest calls it from the cache-volume teardown loop
// (ppc_recomp.80.cpp, sub_8244E538 +0x19c/+0x1d4) with a live volume.
uint32_t IoDismountVolume(uint32_t unknown0, uint32_t unknown1);

// REFUSE -- same, +0x3c8 of the same function, by file handle.
uint32_t IoDismountVolumeByFileHandle(uint32_t fileHandle, uint32_t unknown1);

// REAL  -- strings.cc:857-894 (_snprintf). Returns the C99/CRT count exactly
// as the reference does, including the -1 on overflow.
int32_t XkSnprintf(void* buffer, int32_t bufferCount, const void* format);

// REAL  -- strings.cc:1001-1041 (_vsnprintf). Note this variant returns the
// count it WOULD have written on overflow, without the -1 that _snprintf
// applies -- that asymmetry is the reference's, not a slip.
int32_t XkVsnprintf(void* buffer, int32_t bufferCount, const void* format,
                    uint32_t argList);

// REAL  -- strings.cc:897-925 (sprintf). Unbounded destination, still returns
// -1 for a null buffer or format, as the reference does.
int32_t XkSprintf(void* buffer, const void* format);

}  // namespace kobjport
