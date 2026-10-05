// ===========================================================================
// port_kobj.cpp -- see port_kobj.h for what this file is, what it is not, and
// the removal condition attached to every refusal.
//
// Template followed throughout: the already-ported RtlCompareMemoryUlong
// (src/kernel/imports.cpp:3564-3620) -- a real body, a Xenia file:line, the
// guest's own call sites as corroboration, and a count that keeps working when
// the body returns early.
//
// HOUSE RULES HONOURED HERE
//   * guest access is always a 32-bit VA through GuestMemoryHeap's checked,
//     endian-explicit helpers. No reinterpret_cast of guest data, anywhere.
//   * no assert on a guest value: the build is /DNDEBUG
//     (build/compile_commands.json), so an assert here would be a comment.
//   * variadic arguments come off the guest stack through ArgTranslator
//     (src/kernel/function.h:169-203), the checked reader that owns the
//     F611-STACKARG-READ marker. A pointer built from the guest's r1 is never
//     cast.
//   * refusals are countable: KOBJPORT-REFUSE #N, with the attempt and the
//     outcome on separate counters.
// ===========================================================================

// stdafx.h FIRST, and this is load-bearing rather than stylistic: stdafx.h:34
// includes the GENERATED ppc_context.h, which is where PPCFunc, PPC_FUNC and
// PPC_LOOKUP_FUNC come from -- and src/kernel/memory.h:170-175, which xdm.h
// pulls in, uses all three. src/kernel/function.h includes <cpu/ppc_context.h>,
// which is a different and much smaller header that does NOT define them, so
// the order here is the same one imports.cpp:1-6 relies on.
#include <stdafx.h>

#include "port_kobj.h"

#include <cpu/ppc_context.h>

#include "function.h"
#include "heap.h"
#include "kernel_objects.h"
#include "logging.h"
#include "memory.h"
#include "xdm.h"

#include <cstdio>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include <vector>

// ---------------------------------------------------------------------------
// Counters and the two log shapes. One tally per exported function so a census
// can be read per function; the `fn=` field is what a grep matches.
// ---------------------------------------------------------------------------
namespace {

struct RefusalTally
{
    std::atomic<uint64_t> attempt{0};
    std::atomic<uint64_t> outcome{0};
};

RefusalTally g_refIoControl{};
RefusalTally g_refSetTimerEx{};
RefusalTally g_refDismount{};
RefusalTally g_refDismountByHandle{};
RefusalTally g_refSpinTry{};
RefusalTally g_refCancelIo{};
RefusalTally g_refMutant{};
RefusalTally g_refMutantRelease{};
RefusalTally g_refTimer{};
RefusalTally g_refCancelTimer{};
RefusalTally g_refFormat{};
// Per-control-code refusals, so a census can read the three codes the guest
// actually passes separately from each other (do-not #9: a refusal that cannot
// be attributed to a cause is not countable).
RefusalTally g_refIoctlPartition{};
RefusalTally g_refIoctlScsiPassThrough{};
RefusalTally g_refIoctlUnknown{};

struct Census
{
    std::atomic<uint64_t> calls{0};
    std::atomic<uint64_t> ok{0};
};

Census g_censusMutant{};
Census g_censusMutantRelease{};
Census g_censusTimer{};
Census g_censusCancelTimer{};
Census g_censusCancelIo{};
Census g_censusSpinTry{};
Census g_censusBoost{};
Census g_censusFormat{};

uint32_t GuestLr()
{
    return g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
}

uint32_t GuestPcr()
{
    return g_ppcContext ? static_cast<uint32_t>(g_ppcContext->r13.u32) : 0u;
}

std::string Hex(uint32_t v)
{
    char buf[16];
    std::snprintf(buf, sizeof(buf), "0x%08X", v);
    return buf;
}

std::string Dec(uint32_t v)
{
    char buf[16];
    std::snprintf(buf, sizeof(buf), "%u", v);
    return buf;
}

// The one refusal shape. Counts the attempt and the outcome separately, logs on
// the house schedule (n <= 20 || (n % 200) == 0), and hands back the status the
// caller's comment justifies.
uint32_t Refuse(RefusalTally& tally, const char* fn, uint32_t status,
                const std::string& why)
{
    tally.attempt.fetch_add(1, std::memory_order_relaxed);
    const uint64_t o = tally.outcome.fetch_add(1, std::memory_order_relaxed) + 1;
    if (o <= 20 || (o % 200) == 0)
    {
        MCLA_LOG_WARN("KOBJPORT-REFUSE #{} fn={} status={} why=\"{}\" lr={}",
                      o, fn, Hex(status), why, Hex(GuestLr()));
    }
    return status;
}

// Counted, and logged, without the Refuse shape -- for an observation that is
// reported but is not the refusal being returned.
void Note(RefusalTally& tally, const char* fn, uint32_t status,
          const std::string& why)
{
    tally.attempt.fetch_add(1, std::memory_order_relaxed);
    const uint64_t o = tally.outcome.fetch_add(1, std::memory_order_relaxed) + 1;
    if (o <= 20 || (o % 200) == 0)
    {
        MCLA_LOG_WARN("KOBJPORT-REFUSE #{} fn={} status={} why=\"{}\" lr={}", o, fn,
                      Hex(status), why, Hex(GuestLr()));
    }
}

// Format-engine refusals return the CRT's own error value, -1. `fn` is the
// export the caller is, not always the engine itself, so a census can be read
// per function instead of lumping all three string exports into one row.
int32_t RefuseFormatAs(const char* fn, const char* why)
{
    return static_cast<int32_t>(Refuse(g_refFormat, fn, 0xFFFFFFFFu, why));
}

int32_t RefuseFormat(const char* why)
{
    return RefuseFormatAs("FormatCore", why);
}

void CountCall(Census& c)
{
    c.calls.fetch_add(1, std::memory_order_relaxed);
}

void CountOk(Census& c, const char* fn, const std::string& detail)
{
    const uint64_t n = c.ok.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 20 || (n % 200) == 0)
    {
        MCLA_LOG_INFO("KOBJPORT-OK #{} fn={} {}", n, fn, detail);
    }
}

// ---------------------------------------------------------------------------
// The IOCTL census. Attempts and answers are SEPARATE counters, and that
// separation is the gate: the reason this file answers the geometry code is
// that the title's 158 retries in 180 s (build/w661.log) must stop, so a soak
// has to be able to read "asked N times" against "answered N times" without
// inferring one from the other.
// `sinceAnswer` is how far past the LAST answer the code is being asked again.
// ---------------------------------------------------------------------------
struct IoctlTally
{
    std::atomic<uint64_t> attempt{0};
    std::atomic<uint64_t> answer{0};
    std::atomic<uint64_t> sinceAnswer{0};
};

IoctlTally g_ioctlGeometry{};
IoctlTally g_ioctlPartition{};
IoctlTally g_ioctlScsiPassThrough{};

// One row per arrival at a known control code. If the code has already been
// answered, this is also the IOCTL-RETRY-AFTER-OK measurement: a second ask
// after a good answer means the title did not accept the answer, and a
// `gap=` that keeps climbing is the shape of the 158-retry loop.
void EnterIoctl(IoctlTally& tally, uint32_t code)
{
    const uint64_t attempt = tally.attempt.fetch_add(1, std::memory_order_relaxed) + 1;
    const uint64_t answered = tally.answer.load(std::memory_order_acquire);
    if (answered == 0)
    {
        return;
    }
    const uint64_t gap = tally.sinceAnswer.fetch_add(1, std::memory_order_relaxed) + 1;
    if (gap <= 20 || (gap % 200) == 0)
    {
        MCLA_LOG_WARN(
            "IOCTL-RETRY-AFTER-OK code={} attempts={} answers={} gap={} lr={}",
            Hex(code), attempt, answered, gap, Hex(GuestLr()));
    }
}

// KOBJPORT-IOCTL-OK -- a control code that was ANSWERED, with the values that
// went into the guest's reply buffer. Same house schedule as every other marker
// in this file (n <= 20 || n % 200 == 0), so a 158-retry loop cannot flood the
// log and a passing boot still shows the values.
void ReportIoctlOk(IoctlTally& tally, uint32_t code, const std::string& detail)
{
    const uint64_t n = tally.answer.fetch_add(1, std::memory_order_relaxed) + 1;
    tally.sinceAnswer.store(0, std::memory_order_relaxed);
    if (n <= 20 || (n % 200) == 0)
    {
        MCLA_LOG_INFO("KOBJPORT-IOCTL-OK #{} code={} {}", n, Hex(code), detail);
    }
}

// The io status block, NT shape: Status at +0, Information at +4, both
// big-endian through the checked writer (memory.h:103-105). Returns false when
// the block is outside the guest window -- the REPORT is lost, never the
// decision: r3 is already fixed by then, and turning a lost duplicate report
// into a different failure would be a lie about work that did happen.
bool WriteIoStatus(uint32_t ioStatusBlock, uint32_t status, uint32_t information)
{
    if (ioStatusBlock == 0)
    {
        return true;
    }
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    return mem.WriteU32BE(ioStatusBlock, status) &&
           mem.WriteU32BE(ioStatusBlock + 4, information);
}

// A control code nothing implements is its OWN refusal: its own counters, its
// own marker, its own status, and never a fallthrough into one of the three
// codes above. The status is the reference's own for an unhandled IOCTL --
// X_STATUS_INVALID_PARAMETER (xboxkrnl_io.cc:703-708), which is
// 0xC000000D (xenia/xbox.h:51 and the identical src/kernel/xbox.h:427-428).
uint32_t RefuseUnknownIoctl(uint32_t ioControlCode, uint32_t ioStatusBlock)
{
    g_refIoctlUnknown.attempt.fetch_add(1, std::memory_order_relaxed);
    const uint64_t o = g_refIoctlUnknown.outcome.fetch_add(1, std::memory_order_relaxed) + 1;
    if (o <= 20 || (o % 200) == 0)
    {
        MCLA_LOG_WARN(
            "KOBJPORT-IOCTL-UNKNOWN #{} code={} status={} why=\"no such control "
            "code in the reference dispatch (xboxkrnl_io.cc:686-687) and none "
            "invented here\" lr={}",
            o, Hex(ioControlCode), Hex(STATUS_INVALID_PARAMETER), Hex(GuestLr()));
    }
    if (!WriteIoStatus(ioStatusBlock, STATUS_INVALID_PARAMETER, 0))
    {
        Note(g_refIoControl, "NtDeviceIoControlFile", STATUS_INVALID_PARAMETER,
             ("io status block at " + Hex(ioStatusBlock) +
              " is outside the guest window; the REFUSAL still stands, only its "
              "duplicate report was lost"));
    }
    return STATUS_INVALID_PARAMETER;
}

constexpr uint32_t Bswap32(uint32_t v)
{
    return ((v & 0xFFu) << 24) | ((v & 0xFF00u) << 8) | ((v >> 8) & 0xFF00u) |
           ((v >> 24) & 0xFFu);
}

}  // namespace

// ===========================================================================
// Mutant and TimerObject -- REAL host objects.
//
// Both are at global scope (port_kobj.h) because they are KernelObject
// subclasses that the project's own machinery names by type: the wait
// allow-list in imports.cpp:1384-1388 compares typeid(*obj) against a list of
// types, so they must be findable there, not hidden in a namespace.
// ===========================================================================

// ---------------------------------------------------------------------------
// Mutant. Xenia's mutant is a Win32 RECURSIVE MUTEX
// (.research/xenia/src/xenia/base/threading_win.cc:269-277 CreateMutex with
// initial_owner; :266 `Release() { return ReleaseMutex(handle_); }`, which fails
// when the calling thread does not own it). That is the state machine here:
// owner + recursion count, Wait acquires (recursively for the owner), Release
// gives one count back and reports failure otherwise. Xenia's
// XMutant::ReleaseMutant (kernel/xmutant.cc:41-55) clears owning_thread_ when the
// caller owns it and then defers to exactly that Release().
//
// The Type byte (2 OneShotMutant / 3 RegularMutant) follows the 360
// X_DISPATCH_TYPE series that this project already matches -- its
// NtCreateSemaphore uses 5, which is XDispatchSemaphore in that series
// (imports.cpp:5358). STATED AS UNMEASURED: the object is allocated from the
// PHYSICAL arena at guest VA 0xA0400000 (src/kernel/heap_arena.h:56), so the
// guest can in principle address the header, and whether it reads that byte is
// not established. It is logged on every create so a soak can settle it.
// ---------------------------------------------------------------------------
Mutant::Mutant(bool initialOwner)
{
    header.Type = initialOwner ? 3 /* RegularMutant */ : 2 /* OneShotMutant */;
    if (initialOwner)
    {
        owner_ = CurrentThreadToken();
        recursion_ = 1;
    }
}

uint32_t Mutant::CurrentThreadToken()
{
    // The guest's thread identity is r13, the PCR/TEB base: the same identity
    // KfAcquireSpinLock already stores as a spinlock owner (imports.cpp:3660).
    // Host order, and never written to guest memory.
    return GuestPcr();
}

uint32_t Mutant::Wait(uint32_t timeout)
{
    // Only reachable once the wait allow-list in imports.cpp:1384-1388 admits
    // typeid(Mutant); until that one-line integration edit lands the project's
    // NtWaitForSingleObjectEx refuses this object with STATUS_INVALID_HANDLE
    // BEFORE calling here and logs WAIT-UNIMPLEMENTED. Recorded in port_kobj.h.
    std::unique_lock<std::mutex> lock(m_);
    const uint32_t me = CurrentThreadToken();
    const auto deadline =
        std::chrono::steady_clock::now() +
        std::chrono::milliseconds(timeout == INFINITE ? 0 : timeout);

    while (true)
    {
        if (owner_ == 0 && recursion_ > 0)
        {
            owner_ = me;
            return STATUS_SUCCESS;  // acquired
        }
        if (owner_ == me)
        {
            ++recursion_;  // recursive acquire, as a Win32 mutex
            return STATUS_SUCCESS;
        }
        if (timeout == 0)
        {
            return STATUS_TIMEOUT;
        }
        if (timeout != INFINITE && std::chrono::steady_clock::now() >= deadline)
        {
            return STATUS_TIMEOUT;
        }
        if (timeout == INFINITE)
        {
            cv_.wait(lock);
        }
        else
        {
            cv_.wait_until(lock, deadline);
        }
    }
}

bool Mutant::Release(uint32_t ownerThread)
{
    std::lock_guard<std::mutex> lock(m_);
    if (owner_ == 0 || owner_ != ownerThread || recursion_ == 0)
    {
        return false;  // Xenia: X_STATUS_MUTANT_NOT_OWNED
    }
    --recursion_;
    if (recursion_ == 0)
    {
        owner_ = 0;
        cv_.notify_all();  // a waiter may now take it
    }
    return true;
}

// ---------------------------------------------------------------------------
// TimerObject. Xenia's XTimer is a manual-reset timer for type 0
// (NotificationTimer) and a synchronization timer for type 1
// (.research/xenia/src/xenia/kernel/xtimer.cc:25-39). The object, its type and
// its state word are real; ARMING is refused by NtSetTimerEx because expiry
// delivery needs an APC queue this host does not have, so `armed_` only ever
// reads false and Wait says so rather than blocking to a deadline it can never
// reach.
// ---------------------------------------------------------------------------
TimerObject::TimerObject(uint32_t timerType)
{
    header.Type = timerType == 0 ? 6 /* XDispatchTimer */ : 9 /* XDispatchTimerSync */;
    timerType_ = timerType;
    signalled_.store(false, std::memory_order_release);
}

uint32_t TimerObject::Wait(uint32_t timeout)
{
    std::unique_lock<std::mutex> lock(m_);
    const auto deadline =
        std::chrono::steady_clock::now() +
        std::chrono::milliseconds(timeout == INFINITE ? 0 : timeout);
    while (!signalled_.load(std::memory_order_acquire))
    {
        if (!armed_.load(std::memory_order_acquire) || timeout == 0)
        {
            // Never armed, therefore never able to signal. STATUS_TIMEOUT is a
            // SUCCESS-shaped status, so the reason is stated here rather than
            // being allowed to look like a wait that expired on a real deadline.
            return STATUS_TIMEOUT;
        }
        if (timeout != INFINITE && std::chrono::steady_clock::now() >= deadline)
        {
            return STATUS_TIMEOUT;
        }
        if (timeout == INFINITE)
        {
            cv_.wait(lock);
        }
        else
        {
            cv_.wait_until(lock, deadline);
        }
    }
    if (timerType_ == 1)
    {
        // Synchronization timers auto-reset for the next waiter; notification
        // timers stay signalled (xtimer.cc:27-37).
        signalled_.store(false, std::memory_order_release);
    }
    return STATUS_SUCCESS;
}

bool TimerObject::Cancel()
{
    // Xenia: `return timer_->Cancel() ? X_STATUS_SUCCESS : X_STATUS_UNSUCCESSFUL`
    // (xtimer.cc:95-97). Here nothing was ever armed, so "cancelled" is the
    // TRUE state and the state word is 0 -- which is also what the caller
    // reports, so the two agree by measurement rather than by convention.
    armed_.store(false, std::memory_order_release);
    signalled_.store(false, std::memory_order_release);
    {
        std::lock_guard<std::mutex> lock(m_);
        cv_.notify_all();
    }
    return true;
}

// ===========================================================================
// Format engine -- the project's ONE engine.
//
// Transcribed from .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_strings.cc
// with the structure preserved, because in format_core the fall-throughs ARE
// the format grammar:  FormatState :30-41, FormatFlags :43-57,
// format_core :120-683, format_double :87-118, StackArgList :685-701,
// ArrayArgList :703-720, StringFormatData :722-757.
//
// THREE DELIBERATE DIVERGENCES from the reference, each counted when it fires:
//  (1) Xenia walks raw host pointers into guest memory. Here every byte comes
//      from GuestMemoryHeap::ReadU8/ReadU16BE/WriteU16BE/WriteU32BE, so an
//      out-of-window format string, %s target or %n destination is a refusal
//      rather than a fault inside the emulator's own address space.
//  (2) Xenia's StackArgList::get64 (:692-696) consumes ONE slot per 64-bit
//      value. The PowerPC EABI puts a 64-bit integer argument in an
//      EVEN-ALIGNED PAIR of slots, low word in the even one, consuming two.
//      Reading one slot returns the low half and then re-reads the high half as
//      the next argument, so the real rule is implemented here.
//  (3) Xenia's %s scan is bounded only by the NUL. The guest window is 4 GiB,
//      so an unbounded scan is a hang; there is a cap, and hitting it counts.
// ===========================================================================
namespace kobjport {
namespace {

enum FormatState
{
    FS_Invalid = 0,
    FS_Unknown,
    FS_Start,
    FS_Flags,
    FS_Width,
    FS_PrecisionStart,
    FS_Precision,
    FS_Size,
    FS_Type,
    FS_End,
};

enum FormatFlags
{
    FF_LeftJustify = 1 << 0,
    FF_AddLeadingZeros = 1 << 1,
    FF_AddPositive = 1 << 2,
    FF_AddPositiveAsSpace = 1 << 3,
    FF_AddNegative = 1 << 4,
    FF_AddPrefix = 1 << 5,
    FF_IsShort = 1 << 6,
    FF_IsLong = 1 << 7,
    FF_IsLongLong = 1 << 8,
    FF_IsWide = 1 << 9,
    FF_IsSigned = 1 << 10,
    FF_ForceLeadingZero = 1 << 11,
    FF_InvertWide = 1 << 12,
};

// Longest %s / %S scanned out of guest memory (divergence 3 above).
constexpr int32_t kMaxStringScan = 0x10000;
constexpr int32_t kWork8Size = 512;

}  // namespace

// --- GuestFormatData : Xenia StringFormatData (strings.cc:722-757) ----------
// `const uint8_t* input_` becomes a guest VA. get() advances only past non-NUL
// bytes, exactly as the reference does (:726-732), so peek(0) after a get() that
// returned the NUL still sees the NUL.
uint16_t GuestFormatData::get()
{
    if (unreadable_)
    {
        return 0;
    }
    uint8_t byte = 0;
    if (!mcla::kernel::GuestMemoryHeap::Instance().ReadU8(formatVa_ + cursor_,
                                                          &byte))
    {
        // Running off the window is not an empty format string. Flagged so the
        // caller returns -1 instead of a plausible-looking count of zero.
        unreadable_ = true;
        return 0;
    }
    if (byte == 0)
    {
        return 0;
    }
    ++cursor_;
    return byte;
}

uint16_t GuestFormatData::peek(int32_t offset)
{
    if (unreadable_ || offset < 0)
    {
        return 0;
    }
    uint8_t byte = 0;
    if (!mcla::kernel::GuestMemoryHeap::Instance().ReadU8(
            formatVa_ + cursor_ + static_cast<uint32_t>(offset), &byte))
    {
        return 0;
    }
    return byte;
}

void GuestFormatData::skip(int32_t count)
{
    while (count-- > 0)
    {
        if (!get())
        {
            break;
        }
    }
}

bool GuestFormatData::put(uint16_t c)
{
    if (c >= 0x100)
    {
        return false;
    }
    output_.push_back(static_cast<char>(c));
    return true;
}

// --- GuestStackArgs : Xenia StackArgList (strings.cc:685-701) ---------------
uint64_t GuestStackArgs::get64()
{
    const PPCContext* ctx = g_ppcContext;
    if (ctx == nullptr)
    {
        // A host-initiated entry with no guest frame. There is no argument to
        // read, so this is counted rather than guessed at.
        g_refFormat.attempt.fetch_add(1, std::memory_order_relaxed);
        const uint64_t n =
            g_refFormat.outcome.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 20 || (n % 200) == 0)
        {
            MCLA_LOG_WARN("KOBJPORT-REFUSE #{} fn=FormatCore status=0xFFFFFFFF "
                          "why=\"no live PPCContext for a stack vararg - argument "
                          "taken as 0\" lr={}",
                          n, Hex(GuestLr()));
        }
        return 0;
    }

    // EABI even-aligned pair (divergence 2). Low word in the even slot.
    uint32_t index = static_cast<uint32_t>(index_);
    if ((index & 1u) != 0)
    {
        ++index;
    }

    const uint64_t low = ArgTranslator::GetIntegerArgumentValue(*ctx, base_, index);
    const uint32_t hiVa = ArgTranslator::StackArgVa(*ctx, index + 1);
    uint32_t high = 0;
    if (hiVa == 0 ||
        !mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(hiVa, &high))
    {
        // The F611 marker already fired inside GetIntegerArgumentValue if the
        // LOW slot was the unreadable one; this covers the odd slot, which has
        // no reader of its own.
        g_refFormat.attempt.fetch_add(1, std::memory_order_relaxed);
        const uint64_t n =
            g_refFormat.outcome.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 20 || (n % 200) == 0)
        {
            MCLA_LOG_WARN("KOBJPORT-REFUSE #{} fn=FormatCore status=0xFFFFFFFF "
                          "why=\"64-bit vararg high word (slot {}) at {} unreadable "
                          "- the whole argument was taken as its low word\" lr={}",
                          n, index + 1, Hex(hiVa), Hex(GuestLr()));
        }
        index_ = static_cast<int32_t>(index) + 2;
        return low;
    }

    index_ = static_cast<int32_t>(index) + 2;
    return (static_cast<uint64_t>(high) << 32) | low;
}

// --- GuestArrayArgs : Xenia ArrayArgList (strings.cc:703-720) ---------------
uint64_t GuestArrayArgs::get64()
{
    uint64_t value = 0;
    const uint32_t va = argListVa_ + index_ * 8u;
    if (!mcla::kernel::GuestMemoryHeap::Instance().ReadU64BE(va, &value))
    {
        g_refFormat.attempt.fetch_add(1, std::memory_order_relaxed);
        const uint64_t n =
            g_refFormat.outcome.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 20 || (n % 200) == 0)
        {
            MCLA_LOG_WARN("KOBJPORT-REFUSE #{} fn=FormatCore status=0xFFFFFFFF "
                          "why=\"va_list slot {} at {} unreadable - argument taken "
                          "as 0\" lr={}",
                          n, index_, Hex(va), Hex(GuestLr()));
        }
    }
    ++index_;
    return value;
}

// --- format_double : verbatim from strings.cc:87-118 -----------------------
std::string FormatDouble(double value, int32_t precision, uint16_t c,
                         uint32_t flags)
{
    if (precision < 0)
    {
        precision = 6;
    }
    else if (precision == 0 && c == 'g')
    {
        precision = 1;
    }

    std::ostringstream temp;
    temp << std::setprecision(precision);

    if (c == 'f')
    {
        temp << std::fixed;
    }
    else if (c == 'e' || c == 'E')
    {
        temp << std::scientific;
    }
    else if (c == 'a' || c == 'A')
    {
        temp << std::hexfloat;
    }
    else if (c == 'g' || c == 'G')
    {
        temp << std::defaultfloat;
    }

    if (c == 'E' || c == 'G' || c == 'A')
    {
        temp << std::uppercase;
    }

    if (flags & FF_AddPrefix)
    {
        temp << std::showpoint;
    }

    temp << value;
    return temp.str();
}

// --- format_core : transcribed from strings.cc:120-683 ---------------------
int32_t FormatCore(GuestFormatData& data, ArgList& args, bool wide)
{
    int32_t count = 0;

    char work8[kWork8Size];
    char16_t work16[4];

    // Backing stores so `text.buffer` never points at guest memory: the
    // divergence-1 reads copy out first, and the emit loop then walks host
    // memory known to be valid for exactly text.length units.
    std::string text8;
    std::vector<char16_t> text16;

    struct
    {
        const void* buffer;
        int32_t length;
        bool is_wide;
        bool swap_wide;
    } text;
    text.buffer = nullptr;
    text.is_wide = false;
    text.swap_wide = true;
    text.length = 0;

    struct
    {
        char buffer[2];
        int32_t length;
    } prefix;
    prefix.buffer[0] = '\0';
    prefix.length = 0;

    auto state = FS_Unknown;
    uint32_t flags = 0;
    int32_t width = 0;
    int32_t precision = -1;
    int32_t radix = 0;
    const char* digits = nullptr;
    // Xenia keeps an ArgumentSize (`size`, strings.cc:59-64) and never assigns
    // it -- FS_Size sets only flags. Not carried; the flags are the whole of it.

    for (uint16_t c = data.get();; c = data.get())
    {
        // Xenia reaches its `output:` label by goto from two places: once for an
        // ordinary literal character and once for a doubled '%%'. A flag carries
        // the same control flow without a backward goto into a sibling block.
        bool emitLiteral = false;

        if (state == FS_Unknown)
        {
            if (!c)
            {
                // Divergence 1 made the format string unreadable: -1, not 0.
                return data.formatUnreadable() ? -1 : count;
            }
            else if (c != '%')
            {
                emitLiteral = true;
            }
            else
            {
                state = FS_Start;
                c = data.get();
            }
        }

        if (emitLiteral)
        {
            if (!data.put(c))
            {
                return -1;
            }
            ++count;
            continue;
        }

        // in any state, if c is \0, it's bad
        if (!c)
        {
            return -1;
        }

    restart:
        switch (state)
        {
            case FS_Invalid:
            case FS_Unknown:
            case FS_End:
            default:
                // Xenia: assert_always() (strings.cc:182-184), then falls into
                // FS_Type with whatever `text` the previous conversion left.
                // Guest-driven undefined behaviour is not reproduced; it is
                // refused and counted, so a soak can show whether the title ever
                // prints a conversion this engine does not know.
                return RefuseFormat("format state machine reached an invalid state");

            case FS_Start:
            {
                if (c == '%')
                {
                    // Xenia: `goto output` (strings.cc:187-190). The literal
                    // emission happens before the emit tail, so %% never runs
                    // through the padding path.
                    state = FS_Unknown;
                    emitLiteral = true;
                    break;
                }

                state = FS_Flags;

                // reset to defaults
                flags = 0;
                width = 0;
                precision = -1;
                radix = 0;
                digits = nullptr;

                text.buffer = nullptr;
                text.is_wide = false;
                text.swap_wide = true;
                text.length = 0;
                prefix.buffer[0] = '\0';
                prefix.length = 0;

                // fall through, don't need to goto restart
            }

            case FS_Flags:
            {
                if (c == '-')
                {
                    flags |= FF_LeftJustify;
                    continue;
                }
                else if (c == '+')
                {
                    flags |= FF_AddPositive;
                    continue;
                }
                else if (c == '0')
                {
                    flags |= FF_AddLeadingZeros;
                    continue;
                }
                else if (c == ' ')
                {
                    flags |= FF_AddPositiveAsSpace;
                    continue;
                }
                else if (c == '#')
                {
                    flags |= FF_AddPrefix;
                    continue;
                }
                state = FS_Width;
                // fall through
            }

            case FS_Width:
            {
                if (c == '*')
                {
                    width = static_cast<int32_t>(args.get32());
                    if (width < 0)
                    {
                        flags |= FF_LeftJustify;
                        width = -width;
                    }
                    state = FS_PrecisionStart;
                    continue;
                }
                else if (c >= '0' && c <= '9')
                {
                    width *= 10;
                    width += c - '0';
                    continue;
                }
                state = FS_PrecisionStart;
                // fall through
            }

            case FS_PrecisionStart:
            {
                if (c == '.')
                {
                    state = FS_Precision;
                    precision = 0;
                    continue;
                }
                state = FS_Size;
                goto restart;
            }

            case FS_Precision:
            {
                if (c == '*')
                {
                    precision = static_cast<int32_t>(args.get32());
                    if (precision < 0)
                    {
                        precision = -1;
                    }
                    state = FS_Size;
                    continue;
                }
                else if (c >= '0' && c <= '9')
                {
                    precision *= 10;
                    precision += c - '0';
                    continue;
                }
                state = FS_Size;
                // fall through
            }

            case FS_Size:
            {
                if (c == 'l')
                {
                    if (data.peek(0) == 'l')
                    {
                        data.skip(1);
                        flags |= FF_IsLongLong;
                    }
                    else
                    {
                        flags |= FF_IsLong;
                    }
                    state = FS_Type;
                    continue;
                }
                else if (c == 'L')
                {
                    // 58410826 uses 'L' where it means 'l'; Xenia treats it as a
                    // no-op with a TODO (strings.cc:293-299). Kept as a no-op.
                    state = FS_Type;
                    continue;
                }
                else if (c == 'h')
                {
                    flags |= FF_IsShort;
                    state = FS_Type;
                    continue;
                }
                else if (c == 'w')
                {
                    flags |= FF_IsWide;
                    state = FS_Type;
                    continue;
                }
                else if (c == 'I')
                {
                    if (data.peek(0) == '6' && data.peek(1) == '4')
                    {
                        data.skip(2);
                        flags |= FF_IsLongLong;
                        state = FS_Type;
                        continue;
                    }
                    else if (data.peek(0) == '3' && data.peek(1) == '2')
                    {
                        data.skip(2);
                        state = FS_Type;
                        continue;
                    }
                    else
                    {
                        state = FS_Type;
                        continue;
                    }
                }
                // fall through
            }

            case FS_Type:
            {
                switch (c)
                {
                    case 'C':
                    {
                        flags |= FF_InvertWide;
                        // fall through
                    }

                    case 'c':
                    {
                        bool is_wide;
                        if (flags & (FF_IsLong | FF_IsWide))
                        {
                            is_wide = true;
                        }
                        else if (flags & FF_IsShort)
                        {
                            is_wide = false;
                        }
                        else
                        {
                            is_wide = ((flags & FF_InvertWide) != 0) != wide;
                        }

                        const auto value = args.get32();

                        if (!is_wide)
                        {
                            work8[0] = static_cast<char>(value);
                            text.buffer = &work8[0];
                            text.length = 1;
                            text.is_wide = false;
                        }
                        else
                        {
                            work16[0] = static_cast<char16_t>(value);
                            text.buffer = &work16[0];
                            text.length = 1;
                            text.is_wide = true;
                            // Host-order char16_t we just built: do NOT swap on
                            // emit, exactly as the reference (strings.cc:362).
                            text.swap_wide = false;
                        }
                        break;
                    }

                    case 'd':
                    case 'i':
                    {
                        flags |= FF_IsSigned;
                        digits = "0123456789";
                        radix = 10;
                        goto integer;
                    }

                    case 'o':
                    {
                        digits = "01234567";
                        radix = 8;
                        if (flags & FF_AddPrefix)
                        {
                            flags |= FF_ForceLeadingZero;
                        }
                        goto integer;
                    }

                    case 'u':
                    {
                        digits = "0123456789";
                        radix = 10;
                        goto integer;
                    }

                    case 'x':
                    case 'X':
                    {
                        digits = (c == 'x') ? "0123456789abcdef"
                                            : "0123456789ABCDEF";
                        radix = 16;
                        if (flags & FF_AddPrefix)
                        {
                            prefix.buffer[0] = '0';
                            prefix.buffer[1] = (c == 'x') ? 'x' : 'X';
                            prefix.length = 2;
                        }
                        goto integer;
                    }

                    case 'e':
                    case 'E':
                    {
                        // fall through
                    }

                    case 'f':
                    {
                    floatingpoint:
                        flags |= FF_IsSigned;

                        const uint64_t bits = args.get64();
                        double value = 0.0;
                        std::memcpy(&value, &bits, sizeof(value));

                        if (value < 0)
                        {
                            value = -value;
                            flags |= FF_AddNegative;
                        }

                        const std::string s =
                            FormatDouble(value, precision, c, flags);
                        const int32_t length = static_cast<int32_t>(s.size());
                        if (length >= kWork8Size)
                        {
                            // Xenia asserts (strings.cc:485). Refused rather than
                            // truncated: a silently cut float is a wrong number
                            // in the guest's buffer.
                            return RefuseFormat(
                                "double expansion longer than the work buffer");
                        }
                        std::memcpy(&work8[0], s.c_str(),
                                    static_cast<size_t>(length));
                        work8[length] = '\0';
                        text.buffer = &work8[0];
                        text.length = length;
                        text.is_wide = false;
                        break;
                    }

                    case 'g':
                    case 'G':
                    {
                        goto floatingpoint;
                    }

                    case 'a':
                    case 'A':
                    {
                        goto floatingpoint;
                    }

                    case 'n':
                    {
                        // Xenia SHIM_SET_MEM_16/32 to a guest pointer
                        // (strings.cc:512-520). Divergence 1: checked, and
                        // REFUSED -- not skipped -- when the destination is not
                        // in the window, because skipping %n would leave the
                        // guest's counter uninitialised and its own output
                        // self-inconsistent.
                        const auto pointer = static_cast<uint32_t>(args.get32());
                        if (flags & FF_IsShort)
                        {
                            if (!mcla::kernel::GuestMemoryHeap::Instance()
                                     .WriteU16BE(pointer,
                                                 static_cast<uint16_t>(count)))
                            {
                                return RefuseFormat(
                                    "%n destination outside the guest window");
                            }
                        }
                        else
                        {
                            if (!mcla::kernel::GuestMemoryHeap::Instance()
                                     .WriteU32BE(pointer,
                                                 static_cast<uint32_t>(count)))
                            {
                                return RefuseFormat(
                                    "%n destination outside the guest window");
                            }
                        }
                        continue;
                    }

                    case 'p':
                    {
                        digits = "0123456789ABCDEF";
                        radix = 16;
                        precision = 8;
                        flags &= ~(FF_IsLongLong | FF_IsShort);
                        flags |= FF_IsLong;
                        goto integer;
                    }

                    case 'S':
                    {
                        flags |= FF_InvertWide;
                        // fall through
                    }

                    case 's':
                    {
                        const auto pointer = static_cast<uint32_t>(args.get32());
                        const int32_t cap =
                            precision < 0 ? kMaxStringScan : precision;

                        if (pointer == 0)
                        {
                            static const char kNullString[] = "(null)";
                            text.buffer = kNullString;
                            text.length = std::min<int32_t>(6, cap);
                            text.is_wide = false;
                            text.swap_wide = false;
                            break;
                        }

                        bool is_wide;
                        if (flags & (FF_IsLong | FF_IsWide))
                        {
                            is_wide = true;
                        }
                        else if (flags & FF_IsShort)
                        {
                            is_wide = false;
                        }
                        else
                        {
                            is_wide = ((flags & FF_InvertWide) != 0) != wide;
                        }

                        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
                        int32_t length = 0;
                        bool outOfWindow = false;
                        text16.clear();
                        text8.clear();
                        if (!is_wide)
                        {
                            for (int32_t i = 0; i < cap; ++i)
                            {
                                uint8_t b = 0;
                                if (!mem.ReadU8(pointer + static_cast<uint32_t>(i), &b))
                                {
                                    outOfWindow = true;
                                    break;
                                }
                                if (b == 0)
                                {
                                    break;
                                }
                                text8.push_back(static_cast<char>(b));
                                ++length;
                            }
                        }
                        else
                        {
                            for (int32_t i = 0; i < cap; ++i)
                            {
                                uint16_t b = 0;
                                if (!mem.ReadU16BE(
                                        pointer + static_cast<uint32_t>(i) * 2u, &b))
                                {
                                    outOfWindow = true;
                                    break;
                                }
                                if (b == 0)
                                {
                                    break;
                                }
                                text16.push_back(static_cast<char16_t>(b));
                                ++length;
                            }
                        }

                        if (outOfWindow)
                        {
                            return RefuseFormat(
                                "%s target outside the guest window before its NUL");
                        }

                        if (!is_wide)
                        {
                            text.buffer = text8.c_str();
                            text.is_wide = false;
                            // Host bytes, one per char: no swap on emit.
                            text.swap_wide = false;
                        }
                        else
                        {
                            text.buffer = text16.data();
                            text.is_wide = true;
                            // ReadU16BE already produced host order, so the
                            // reference's byte_swap on emit (strings.cc:655) must
                            // NOT be applied. The twin of divergence 1.
                            text.swap_wide = false;
                        }
                        text.length = length;

                        if (length == cap && cap == kMaxStringScan)
                        {
                            // The scan cap was reached with no NUL. Counted, and
                            // said out loud; never silently applied.
                            Note(g_refFormat, "FormatCore", 0xFFFFFFFFu,
                                 "%s reached the 0x10000-byte scan cap with no NUL "
                                 "- output truncated");
                        }
                        break;
                    }

                    case 'Z':
                    {
                        // Xenia asserts (strings.cc:584-587). Refused: this engine
                        // renders into a std::string, and guessing an
                        // ANSI_STRING's layout would be fabrication.
                        return RefuseFormat("%Z (ANSI_STRING) is not implemented");
                    }

                    default:
                    {
                        return RefuseFormat("unknown conversion character");
                    }
                }

                break;
            }

        // ---- the `integer:` target, transcribed from strings.cc:375-429 ----
        // In the reference this label sits inside FS_Type, so the emit tail that
        // follows the switch runs for it exactly as it does for every other
        // conversion.
        integer:
            if (digits == nullptr || radix <= 0)
            {
                return RefuseFormat("integer conversion reached with no radix");
            }

            {
                int64_t value;
                if (flags & FF_IsLongLong)
                {
                    value = static_cast<int64_t>(args.get64());
                }
                else if (flags & FF_IsLong)
                {
                    value = static_cast<int32_t>(args.get32());
                }
                else if (flags & FF_IsShort)
                {
                    value = static_cast<int16_t>(args.get32());
                }
                else
                {
                    value = static_cast<int32_t>(args.get32());
                }

                if (precision >= 0)
                {
                    precision = std::min(precision, kWork8Size);
                }
                else
                {
                    precision = 1;
                }

                if ((flags & FF_IsSigned) && value < 0)
                {
                    value = -value;
                    flags |= FF_AddNegative;
                }

                if (!(flags & FF_IsLongLong))
                {
                    value &= 0xFFFFFFFF;
                }

                if (value == 0)
                {
                    prefix.length = 0;
                }

                char* end = &work8[kWork8Size - 1];
                char* start = end;
                start[0] = '\0';

                while (precision-- > 0 || value != 0)
                {
                    if (start <= &work8[0])
                    {
                        return RefuseFormat("integer wider than the work buffer");
                    }
                    const auto digit = static_cast<int32_t>(value % radix);
                    value /= radix;
                    if (digit < 0 || digit >= 16 || digits[digit] == '\0')
                    {
                        return RefuseFormat("digit out of range for the radix");
                    }
                    *--start = digits[digit];
                }

                if ((flags & FF_ForceLeadingZero) && (start == end || *start != '0'))
                {
                    if (start <= &work8[0])
                    {
                        return RefuseFormat("no room for the forced leading zero");
                    }
                    *--start = '0';
                }

                text.buffer = start;
                text.length = static_cast<int32_t>(end - start);
                text.is_wide = false;
            }
            break;
        }

        // ---- the shared emit tail, transcribed from strings.cc:596-679 -----
        if (emitLiteral)
        {
            if (!data.put(c))
            {
                return -1;
            }
            ++count;
            continue;
        }

        if (flags & FF_IsSigned)
        {
            if (flags & FF_AddNegative)
            {
                prefix.buffer[0] = '-';
                prefix.length = 1;
            }
            else if (flags & FF_AddPositive)
            {
                prefix.buffer[0] = '+';
                prefix.length = 1;
            }
            else if (flags & FF_AddPositiveAsSpace)
            {
                prefix.buffer[0] = ' ';
                prefix.length = 1;
            }
        }

        int32_t padding = width - text.length - prefix.length;

        if (!(flags & (FF_LeftJustify | FF_AddLeadingZeros)) && padding > 0)
        {
            count += padding;
            while (padding-- > 0)
            {
                if (!data.put(' '))
                {
                    return -1;
                }
            }
        }

        if (prefix.length > 0)
        {
            count += prefix.length;
            for (int32_t i = 0; i < prefix.length; ++i)
            {
                if (!data.put(static_cast<uint16_t>(prefix.buffer[i])))
                {
                    return -1;
                }
            }
        }

        if ((flags & FF_AddLeadingZeros) && !(flags & FF_LeftJustify) && padding > 0)
        {
            count += padding;
            while (padding-- > 0)
            {
                if (!data.put('0'))
                {
                    return -1;
                }
            }
        }

        {
            if (text.buffer == nullptr)
            {
                return RefuseFormat("conversion produced no text");
            }
            int32_t remaining = text.length;
            if (!text.is_wide)
            {
                const auto* b = static_cast<const uint8_t*>(text.buffer);
                for (int32_t i = 0; i < remaining; ++i)
                {
                    if (!data.put(b[i]))
                    {
                        return -1;
                    }
                }
            }
            else if (text.swap_wide)
            {
                // Guest-order UTF-16 read straight out of the window: swap on
                // emit, as the reference does (strings.cc:653-656). Unreachable
                // from this file's own %s/%c paths, which both set swap_wide
                // false, and kept so a future guest-order producer is correct.
                const auto* b = static_cast<const uint8_t*>(text.buffer);
                for (int32_t i = 0; i < remaining; ++i)
                {
                    const uint16_t unit =
                        static_cast<uint16_t>((static_cast<uint16_t>(b[i * 2]) << 8) |
                                              b[i * 2 + 1]);
                    if (!data.put(unit))
                    {
                        return -1;
                    }
                }
            }
            else
            {
                const auto* b = static_cast<const uint16_t*>(text.buffer);
                for (int32_t i = 0; i < remaining; ++i)
                {
                    if (!data.put(b[i]))
                    {
                        return -1;
                    }
                }
            }
            count += text.length;
        }

        if ((flags & FF_LeftJustify) && padding > 0)
        {
            count += padding;
            while (padding-- > 0)
            {
                if (!data.put(' '))
                {
                    return -1;
                }
            }
        }

        state = FS_Unknown;
    }
}

// ===========================================================================
// Helpers shared by the object bodies.
// ===========================================================================
namespace {

// CreateKernelObject (xdm.h:49-54) can return nullptr on an honest OOM --
// Heap::AllocPhysical does exactly that (heap.h:86-93). CreateRegisteredKernel-
// Object (xdm.h:124-137) does NOT check and would dereference the null. So the
// registration is done here, in the same four steps, with the check the
// reference helper lacks.
template <typename T, typename... Args>
bool CreateRegisteredChecked(uint32_t* outHandle, Args&&... args)
{
    T* obj = CreateKernelObject<T>(std::forward<Args>(args)...);
    if (obj == nullptr)
    {
        *outHandle = 0;
        return false;
    }
    const uint8_t type = obj->header.Type;
    const uint32_t handle = GetKernelHandle(obj);
    obj->identityHdrAddr = handle;
    {
        std::lock_guard guard{g_kernelLock};
        WrapperIdentityMap()[handle] = { obj, type };
    }
    *outHandle = handle;
    return true;
}

// Resolve a guest handle to a host object of exactly T, or nullptr. NEVER falls
// back to the raw guest-memory cast GetKernelObject does (xdm.h:72-77) -- that
// path hands a reinterpret_cast<KernelObject*> over raw guest memory to
// dynamic_cast, which is the UB xdm.h:69-71 warns about.
template <typename T>
T* ResolveTyped(uint32_t handle)
{
    if (handle == 0 || handle == GUEST_INVALID_HANDLE_VALUE)
    {
        return nullptr;
    }
    KernelObject* obj = LookupIdentityKernelObject(handle);
    if (obj == nullptr)
    {
        return nullptr;
    }
    if (typeid(*obj) != typeid(T))
    {
        return nullptr;
    }
    return static_cast<T*>(obj);
}

// Both reference tails agree on this and differ only in what they RETURN on
// overflow:
//   _snprintf  (strings.cc:880-892): copy buffer_count bytes, return -1.
//   _vsnprintf (strings.cc:1025-1039): copy buffer_count bytes, return the count
//                                     that WOULD have been written.
// So the copy is shared and each caller applies its own return rule.
int32_t TailBuffer(uint32_t bufferVa, int32_t bufferCount, const std::string& text)
{
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const int32_t count = static_cast<int32_t>(text.size());

    if (count <= bufferCount)
    {
        if (count > 0 && !mem.WriteBytes(bufferVa, text.c_str(),
                                         static_cast<uint32_t>(count)))
        {
            return RefuseFormat("destination write failed");
        }
        if (count < bufferCount)
        {
            // The terminator is not optional: the reference writes it in the
            // same breath as the text (:887-888). A failure here leaves the
            // guest reading past the text it was just handed, so it is refused
            // rather than dropped.
            if (!mem.WriteU8(bufferVa + static_cast<uint32_t>(count), 0))
            {
                return RefuseFormat("terminator write failed");
            }
        }
        return count;
    }

    // Overflowed: copy what fits, without a terminator, as both bodies do.
    if (bufferCount > 0 &&
        !mem.WriteBytes(bufferVa, text.c_str(), static_cast<uint32_t>(bufferCount)))
    {
        return RefuseFormat("destination write failed");
    }
    return count;
}

}  // namespace

// ---------------------------------------------------------------------------
// XMsgCancelIORequest -- REAL
// Xenia .research/xenia/src/xenia/kernel/xam/xam_msg.cc:89-102.
//
// SIGNATURE CORRECTION, and that is the substantive part of this port. The stub
// in this tree was
//     uint32_t XMsgCancelIORequest(uint32_t App, XXOVERLAPPED *lpOverlapped)
//     { return STATUS_SUCCESS; }                                (imports.cpp:6748)
// -- the wrong argument list. The real export takes (overlapped, wait). The
// guest passes r3 = the overlapped and r4 = 1
// (generated/ppc_xenon/ppc_recomp.157.cpp:10488-10492), so the old body read a
// handle out of the WAIT FLAG and did nothing whatsoever. Xenia reads the event
// handle from the overlapped at +0xC (xenia/xbox.h:176-184 and :210-213) and,
// when `wait` is set, polls that event with a zero timeout (xam_msg.cc:91-98:
// `ev->Wait(0, 0, true, nullptr)`).
//
// WHAT IT STILL DOES NOT DO, not hidden: it cancels nothing. Xenia does not
// cancel anything either -- there is no queue to remove the request from, and
// XIOCompletion (kernel/xiocompletion.cc:15-45, the host-pointer ring plus
// semaphore) is a DIFFERENT subsystem that this export never touches. The
// honest description is "the event poll Xenia performs, performed", and the
// poll's result goes in the census so a reader can see whether anything was
// ever in flight.
// ---------------------------------------------------------------------------
uint32_t XMsgCancelIORequest(void* overlapped, uint32_t wait)
{
    CountCall(g_censusCancelIo);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t overlappedVa = overlapped ? mem.MapVirtual(overlapped) : 0;

    if (overlappedVa == 0)
    {
        return Refuse(g_refCancelIo, "XMsgCancelIORequest", STATUS_INVALID_PARAMETER,
                      "overlapped pointer is null or outside the guest window");
    }

    uint32_t eventHandle = 0;
    if (!mem.ReadU32BE(overlappedVa + 0xC, &eventHandle))
    {
        return Refuse(g_refCancelIo, "XMsgCancelIORequest", STATUS_INVALID_PARAMETER,
                      "overlapped+0xC unreadable");
    }

    if (eventHandle == 0 || !wait)
    {
        // Xenia's own short-circuit (xam_msg.cc:92).
        CountOk(g_censusCancelIo, "XMsgCancelIORequest",
                "event=0 wait=" + Dec(wait) + " -> nothing to poll");
        return 0;
    }

    Event* ev = ResolveTyped<Event>(eventHandle);
    if (ev == nullptr)
    {
        // Not a host Event we own. Xenia simply would not find it and falls
        // through to `return 0`; the same here, but counted, because a handle
        // that resolves to nothing is a fact worth seeing.
        CountOk(g_censusCancelIo, "XMsgCancelIORequest",
                "event=" + Hex(eventHandle) +
                    " is not a host Event -> poll skipped, nothing cancelled");
        return 0;
    }

    // Zero-timeout poll, as the reference. This consumes the signal on a
    // synchronization (auto-reset) event, which is what Wait(0) means.
    const uint32_t st = ev->Wait(0);
    CountOk(g_censusCancelIo, "XMsgCancelIORequest",
            "event=" + Hex(eventHandle) + " poll=" + Hex(st) +
                " (no request was removed from any queue: none exists on this "
                "host, same as the reference)");
    return 0;
}

// ---------------------------------------------------------------------------
// KeTryToAcquireSpinLockAtRaisedIrql -- REAL
// Xenia .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_threading.cc:967-974:
//     if (!xe::atomic_cas(0, 1, lock)) { return 0; }  return 1;
// One CAS: 1 on success, 0 on failure. The reference marks the export kSketchy
// (:975-976), which is a comment about the ABI, not about the CAS.
//
// WHY THIS IS NEITHER A DEADLOCK NOR A LIVELOCK, which the two wrong answers
// would each be. The blocking side of this protocol is already real and
// complete in this tree: KfAcquireSpinLock (imports.cpp:3654-3712) and
// KeAcquireSpinLockAtRaisedIrql (:3782-3792) both spin on a CAS from 0 to
// bswap32(r13) -- the OWNER's thread id -- and KeReleaseSpinLockFromRaisedIrql
// (:3777-3780) stores 0. MEASURED: all three are in the guest's import table
// (generated/ppc_xenon/ppc_func_mapping.cpp:44880, :44884) and all three are
// hooked (:6458-6461). So a lock taken here is released by a path that already
// exists, and the 0 sentinel CASed from here is the same 0 those two store.
//
// The value stored is bswap32(r13) rather than Xenia's constant 1: the lock
// word is guest memory that guest inline code reads through BE accessors, and
// the owner id is what imports.cpp:3660 and :3700 already log. Storing 1 would
// be a different encoding from the pair that owns the lock.
//
// A null spinLock (the guest VA fell outside the window, so function.h:363-369
// passed nullptr and logged F611-ARGPTR) returns 0 == NOT ACQUIRED, the safe
// direction: no lock is taken, so nothing can be left held.
// ---------------------------------------------------------------------------
uint32_t KeTryToAcquireSpinLockAtRaisedIrql(uint32_t* spinLock)
{
    CountCall(g_censusSpinTry);
    if (spinLock == nullptr)
    {
        return Refuse(g_refSpinTry, "KeTryToAcquireSpinLockAtRaisedIrql", 0,
                      "lock pointer is null or outside the guest window - "
                      "reporting NOT acquired (no lock taken, so none can be "
                      "left held)");
    }

    std::atomic_ref<uint32_t> lockRef(*spinLock);
    const uint32_t selfBe = Bswap32(GuestPcr());
    uint32_t expected = 0;
    if (lockRef.compare_exchange_strong(expected, selfBe, std::memory_order_acquire,
                                        std::memory_order_relaxed))
    {
        CountOk(g_censusSpinTry, "KeTryToAcquireSpinLockAtRaisedIrql",
                "ACQUIRED owner_r13be=" + Hex(selfBe));
        return 1;
    }

    // Contended. Counted, not silent: a title that spins here forever is a bug
    // this marker will localise, and the reported answer is still the truthful
    // one -- a try that did not take the lock.
    Note(g_refSpinTry, "KeTryToAcquireSpinLockAtRaisedIrql", 0,
         "CAS 0->owner failed, holder r13be=" +
             Hex(Bswap32(lockRef.load(std::memory_order_relaxed))) +
             " - reporting NOT acquired (correct try-lock semantics, not a "
             "livelock: the holder is a real thread)");
    return 0;
}

// ---------------------------------------------------------------------------
// KeSetDisableBoostThread -- REAL, and the `void` was the whole bug.
// Xenia xboxkrnl_threading.cc:286-295:
//     auto thread = XObject::GetNativeObject<XThread>(kernel_state, thread_ptr);
//     if (thread) { // Uhm? }
//     return 0;
// The reference resolves the thread and deliberately does NOTHING with it, then
// returns 0 -- the previous boost value, i.e. "boost was in effect, now
// disabled". That is a POLICY ANSWER about a thread, not a completion receipt
// for work: the same distinction this project drew for KeQueryPrivilege
// (imports.cpp:1901-1909).
//
// The stub was `void KeSetDisableBoostThread() {}` (imports.cpp:6602), hooked
// with GUEST_FUNCTION_STUB (imports.cpp:6841), so r3 was never assigned and the
// call site read its own r3 -- the THREAD POINTER -- back as the previous
// priority. The single caller is sub_82131DC0+0x3c (measured:
// `ppc_xrefs.py calls 0x827BCE94`), in the boot worker's own address range.
// ---------------------------------------------------------------------------
uint32_t KeSetDisableBoostThread(uint32_t thread, uint32_t disabled)
{
    CountCall(g_censusBoost);
    CountOk(g_censusBoost, "KeSetDisableBoostThread",
            "thread=" + Hex(thread) + " disabled=" + Dec(disabled) +
                " -> 0 (previous boost state; the reference resolves the thread "
                "and deliberately does nothing with it)");
    return 0;
}

// ---------------------------------------------------------------------------
// NtCreateMutant -- REAL
// Xenia xboxkrnl_threading.cc:638-670: named-object collision check, then
// `new XMutant` + `Initialize(initial_owner)` + `*handle_out = handle()`. The
// guest's wrapper sub_8244FD90 passes a zeroed XOBJECT_ATTRIBUTES when the
// caller's name pointer is null and a filled one otherwise
// (generated/ppc_xenon/ppc_recomp.80.cpp:15288-15315).
//
// DIVERGENCE, stated rather than hidden: Xenia returns
// X_STATUS_OBJECT_NAME_EXISTS (0x40000000) when a same-named object exists.
// This host has NO named-object table, so a named create is served as a fresh
// private object -- which is what NtCreateEvent (imports.cpp:1870-1876) and
// NtCreateSemaphore (:5351-5359) already do with the same argument, both of
// which drop ObjectAttributes entirely. A private object is a WEAKER guarantee,
// not a stronger claim: no name is invented and no existing object is aliased.
// Named creates are counted so a soak can size the exposure.
//
// PREREQUISITE for the integration stream: the wait allow-list at
// imports.cpp:1384-1388 must gain `typeid(Mutant)`, or a guest that waits on
// this handle is refused with STATUS_INVALID_HANDLE by the project's own
// NtWaitForSingleObjectEx even though the object implements Wait.
// ---------------------------------------------------------------------------
uint32_t NtCreateMutant(uint32_t handleOut, uint32_t objectAttributes,
                        uint32_t initialOwner)
{
    CountCall(g_censusMutant);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    if (handleOut == 0)
    {
        return Refuse(g_refMutant, "NtCreateMutant", STATUS_INVALID_PARAMETER,
                      "null handle-out pointer");
    }

    // XOBJECT_ATTRIBUTES.Name is at +4 (src/kernel/xbox.h:216-221). Read as a
    // guest VA through the checked BE reader; no cast.
    uint32_t nameVa = 0;
    if (objectAttributes != 0 && !mem.ReadU32BE(objectAttributes + 4, &nameVa))
    {
        return Refuse(g_refMutant, "NtCreateMutant", STATUS_INVALID_PARAMETER,
                      "object attributes unreadable at the supplied VA");
    }
    if (nameVa != 0)
    {
        Note(g_refMutant, "NtCreateMutant", kStatusObjectNameExists,
             ("named create (Name=" + Hex(nameVa) +
              ") served as a PRIVATE object: this host has no named-object "
              "table, so Xenia's X_STATUS_OBJECT_NAME_EXISTS collision cannot "
              "be detected")
             );
    }

    uint32_t handle = 0;
    if (!CreateRegisteredChecked<Mutant>(&handle, initialOwner != 0))
    {
        return Refuse(g_refMutant, "NtCreateMutant", STATUS_NO_MEMORY,
                      "Mutant allocation returned null (honest OOM); NO handle "
                      "was written");
    }

    if (!mem.WriteU32BE(handleOut, handle))
    {
        // The object exists but the guest cannot be told its handle. Report it
        // rather than leave a live object the guest will never close.
        DestroyKernelObject(handle);
        return Refuse(g_refMutant, "NtCreateMutant", STATUS_INVALID_PARAMETER,
                      "handle-out slot outside the guest window; object destroyed");
    }

    CountOk(g_censusMutant, "NtCreateMutant",
            "handle=" + Hex(handle) + " initialOwner=" + Dec(initialOwner) +
                " dispatcherType=" + Dec(initialOwner ? 3u : 2u));
    return STATUS_SUCCESS;
}

// ---------------------------------------------------------------------------
// NtReleaseMutant -- REAL
// Xenia xboxkrnl_threading.cc:672-696. The second argument is read and discarded
// exactly as the reference discards it: Xenia asserts it is zero (:679) and then
// hardcodes priority_increment=0, abandon=false, wait=false, because every game
// sets it to 0. The guest does pass 0 -- measured at
// generated/ppc_xenon/ppc_recomp.80.cpp:15378-15379 (`li r4,0` immediately before
// the call).
//
// The guest's wrapper treats ANY negative status as a hard error
// (ppc_recomp.80.cpp:15383-15394: `blt` -> sub_82135D58, its assert/fatal path),
// so STATUS_MUTANT_NOT_OWNED is returned ONLY when the release genuinely failed
// to give a count back. That is the reference's own answer (xmutant.cc:52-54)
// and the truthful one: reporting SUCCESS for a release that released nothing
// is the fabrication this file exists to avoid. If a soak shows this counter
// non-zero on the title's job path, the OWNERSHIP MODEL is what is wrong --
// not the status.
// ---------------------------------------------------------------------------
uint32_t NtReleaseMutant(uint32_t mutantHandle, uint32_t unknown)
{
    CountCall(g_censusMutantRelease);
    (void)unknown;  // read and ignored, as Xenia does (threading.cc:675-682)

    Mutant* m = ResolveTyped<Mutant>(mutantHandle);
    if (m == nullptr)
    {
        return Refuse(g_refMutantRelease, "NtReleaseMutant", STATUS_INVALID_HANDLE,
                      "handle is not a live Mutant in the identity map");
    }
    if (!m->IsValid())
    {
        return Refuse(g_refMutantRelease, "NtReleaseMutant", STATUS_INVALID_HANDLE,
                      "object header is invalidated (already destroyed)");
    }

    if (!m->Release(Mutant::CurrentThreadToken()))
    {
        return Refuse(g_refMutantRelease, "NtReleaseMutant", kStatusMutantNotOwned,
                      "the calling thread owns no count on this mutant - the "
                      "reference's X_STATUS_MUTANT_NOT_OWNED; the guest's wrapper "
                      "treats a negative status as fatal");
    }

    CountOk(g_censusMutantRelease, "NtReleaseMutant",
            "handle=" + Hex(mutantHandle) + " released one count");
    return STATUS_SUCCESS;
}

// ---------------------------------------------------------------------------
// NtCreateTimer -- REAL
// Xenia xboxkrnl_threading.cc:698-732: collision check, `new XTimer`,
// `Initialize(timer_type)`, `*handle_ptr = timer->handle()`.
//
// DIVERGENCE: Xenia's `default:` arm for an out-of-range timer_type
// (xtimer.cc:34-37) asserts and leaves the internal timer null, after which its
// own SetAttributes would fault. Here an unknown type is refused with
// STATUS_INVALID_PARAMETER and nothing is created -- the same information without
// the crash.
// ---------------------------------------------------------------------------
uint32_t NtCreateTimer(uint32_t handleOut, uint32_t objectAttributes,
                       uint32_t timerType)
{
    CountCall(g_censusTimer);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    if (handleOut == 0)
    {
        return Refuse(g_refTimer, "NtCreateTimer", STATUS_INVALID_PARAMETER,
                      "null handle-out pointer");
    }
    if (timerType > 1)
    {
        return Refuse(g_refTimer, "NtCreateTimer", STATUS_INVALID_PARAMETER,
                      "timer_type must be 0 (Notification) or 1 (Synchronization)");
    }

    uint32_t nameVa = 0;
    if (objectAttributes != 0 && !mem.ReadU32BE(objectAttributes + 4, &nameVa))
    {
        return Refuse(g_refTimer, "NtCreateTimer", STATUS_INVALID_PARAMETER,
                      "object attributes unreadable at the supplied VA");
    }
    if (nameVa != 0)
    {
        Note(g_refTimer, "NtCreateTimer", kStatusObjectNameExists,
             ("named create (Name=" + Hex(nameVa) +
              ") served as a PRIVATE object: no named-object table on this host")
             );
    }

    uint32_t handle = 0;
    if (!CreateRegisteredChecked<TimerObject>(&handle, timerType))
    {
        return Refuse(g_refTimer, "NtCreateTimer", STATUS_NO_MEMORY,
                      "TimerObject allocation returned null; NO handle written");
    }
    if (!mem.WriteU32BE(handleOut, handle))
    {
        DestroyKernelObject(handle);
        return Refuse(g_refTimer, "NtCreateTimer", STATUS_INVALID_PARAMETER,
                      "handle-out slot outside the guest window; object destroyed");
    }

    CountOk(g_censusTimer, "NtCreateTimer",
            "handle=" + Hex(handle) + " type=" + Dec(timerType) +
                " (armable only once NtSetTimerEx stops refusing)");
    return STATUS_SUCCESS;
}

// ---------------------------------------------------------------------------
// NtSetTimerEx -- REFUSE, and the reason is structural rather than cautious.
//
// Xenia xboxkrnl_threading.cc:734-758 -> XTimer::SetTimer
// (.research/xenia/src/xenia/kernel/xtimer.cc:41-93). The timer is armed for
// real, and on expiry the routine is delivered as an APC to the thread that
// armed it:
//     callback_thread_->EnqueueApc(callback_routine_, callback_routine_arg_,
//                                  time_low, time_high);            (xtimer.cc:79-81)
// MEASURED: this host has no APC queue. EnqueueApc / QueueApc /
// NtQueueApcThread appear nowhere in src/ outside comments, and the project's
// own NtWaitForSingleObjectEx says so in as many words (imports.cpp:1352-1377:
// "plumbing it means changing the virtual KernelObject::Wait signature and
// giving every override an APC-delivery path").
//
// So all three available answers are forbidden: arming without a delivery path
// is "a timer that never fires silently"; firing and dropping the routine is
// "silently discarding work it was asked to do"; returning success is a
// fabricated completion. STATUS_NOT_IMPLEMENTED (0xC0000002, measured at
// xenia/xbox.h:46) says exactly one true thing -- this host does not implement
// the operation -- and it is negative, so the guest's own caller takes its
// failure branch instead of continuing on a timer state that does not exist (the
// guest stores the status and hands it back: ppc_recomp.156.cpp:2080-2101).
//
// The due time and period are still read and logged, so a soak can show whether
// the title ever arms one and how long it wanted it to run. The unk_one /
// unk_zero shape Xenia asserts (threading.cc:739-740) is CHECKED, not asserted,
// because /DNDEBUG compiles an assert out.
// ---------------------------------------------------------------------------
uint32_t NtSetTimerEx(uint32_t timerHandle, uint32_t dueTimePtr, uint32_t routine,
                      uint32_t unkOne, uint32_t routineArg, uint32_t resume,
                      uint32_t periodMs, uint32_t unkZero)
{
    CountCall(g_censusTimer);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    uint64_t dueTime = 0;
    if (dueTimePtr == 0 || !mem.ReadU64BE(dueTimePtr, &dueTime))
    {
        return Refuse(g_refSetTimerEx, "NtSetTimerEx", kStatusNotImplemented,
                      "due-time pointer unreadable; nothing armed, and the refusal "
                      "is the same one the missing APC path forces");
    }

    if (unkOne != 1 || unkZero != 0)
    {
        Note(g_refSetTimerEx, "NtSetTimerEx", kStatusNotImplemented,
             ("unk_one=" + Dec(unkOne) + " (Xenia asserts 1) unk_zero=" +
              Dec(unkZero) + " (Xenia asserts 0) - the shape differs from the "
              "reference")
             );
    }

    // The handle is resolved even though the call is refused, so the marker can
    // separate "refused because of the APC gap" from "refused because the handle
    // was never a Timer".
    TimerObject* t = ResolveTyped<TimerObject>(timerHandle);

    g_refSetTimerEx.attempt.fetch_add(1, std::memory_order_relaxed);
    const uint64_t o = g_refSetTimerEx.outcome.fetch_add(1, std::memory_order_relaxed) + 1;
    if (o <= 20 || (o % 200) == 0)
    {
        MCLA_LOG_WARN(
            "KOBJPORT-REFUSE #{} fn=NtSetTimerEx status={} "
            "why=\"expiry delivery needs XThread::EnqueueApc (xtimer.cc:79-81) and "
            "this host has NO APC queue (measured: zero hits in src/), so arming "
            "would be a timer that never fires; NOTHING WAS ARMED and the timer is "
            "still in state 0\" handle={} liveTimer={} dueTime={} periodMs={} "
            "routine={} routineArg={} resume={} lr={}",
            o, Hex(kStatusNotImplemented), Hex(timerHandle), t != nullptr,
            static_cast<uint64_t>(dueTime), periodMs, Hex(routine),
            Hex(routineArg), Dec(resume), Hex(GuestLr()));
    }
    return kStatusNotImplemented;
}

// ---------------------------------------------------------------------------
// NtCancelTimer -- REAL
// Xenia xboxkrnl_threading.cc:760-776. The structure is preserved exactly,
// including the detail that the current-state word is written even on the
// invalid-handle path:
//     if (current_state_ptr) { *current_state_ptr = 0; }
// and that the word is 0 rather than "whatever the timer was doing". Here that
// is not a courtesy: NtSetTimerEx refuses to arm anything, so "not armed" is the
// TRUE state and the 0 is a measurement, not a stub value.
// ---------------------------------------------------------------------------
uint32_t NtCancelTimer(uint32_t timerHandle, uint32_t currentStateOut)
{
    CountCall(g_censusCancelTimer);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    uint32_t result = STATUS_SUCCESS;
    TimerObject* t = ResolveTyped<TimerObject>(timerHandle);
    if (t != nullptr && t->IsValid())
    {
        result = t->Cancel() ? STATUS_SUCCESS : STATUS_UNSUCCESSFUL;
        CountOk(g_censusCancelTimer, "NtCancelTimer",
                "handle=" + Hex(timerHandle) +
                    " cancelled (it was not armed: NtSetTimerEx refuses to arm)");
    }
    else
    {
        result = Refuse(g_refCancelTimer, "NtCancelTimer", STATUS_INVALID_HANDLE,
                        "handle is not a live Timer in the identity map");
    }

    // Xenia writes this unconditionally when the pointer is non-null
    // (threading.cc:771-773).
    if (currentStateOut != 0 && !mem.WriteU32BE(currentStateOut, 0))
    {
        // The cancel itself happened; only the report failed. Say so, and do not
        // turn a real cancel into a failure status.
        Note(g_refCancelTimer, "NtCancelTimer", result,
             ("current-state slot " + Hex(currentStateOut) +
              " is outside the guest window; the CANCEL DID HAPPEN, only the "
              "report was lost")
             );
    }

    return result;
}

// ---------------------------------------------------------------------------
// NtDeviceIoControlFile -- REFUSE. Highest reachability of the fourteen, and the
// only one where a SUCCESS return would be a lie with a body attached.
//
// REACHABILITY, measured three ways:
//   * the import is in the guest's static import table:
//     generated/ppc_xenon/ppc_func_mapping.cpp:44964 --
//     { 0x827BDA44, __imp__NtDeviceIoControlFile }.
//   * THREE call sites. `python tools/ppc_xrefs.py calls 0x827BDA44` ->
//     0x82451764 (sub_82451668+0xfc), 0x8245FBAC and 0x8245FC20
//     (sub_8245FB30+0x7c and +0xf0).
//   * the IOCTL codes are LITERALS in that recompiled code, not inferred:
//     0x70000 and 0x74004 (ppc_recomp.82.cpp:10770-10771, and :10824-10825 with
//     :10834-10835) and 0x24400 (ppc_recomp.81.cpp:3470-3471 with :3484-3485).
//     Xenia names the first two X_IOCTL_DISK_GET_DRIVE_GEOMETRY and
//     X_IOCTL_DISK_GET_PARTITION_INFO and hardcodes a 0xFF000-byte "cache_size"
//     for them (xboxkrnl_io.cc:684-702); it marks the whole export kStub (:712).
//   * the 0x24400 site is ASYNC: it tests the result against 259
//     (STATUS_PENDING -- ppc_recomp.81.cpp:3497-3498, and 259 is decimal in the
//     disassembly) and on PENDING waits on an event and re-reads the io status
//     block (:3501-3513). No synchronous implementation of that site exists, and
//     inventing one is exactly the fabricated I/O completion the charter forbids.
//
// WHAT CHANGED AND WHY, 2026-09-30. This body used to refuse all three codes
// with STATUS_NO_SUCH_DEVICE, and the refusal was right about the FIELDS it
// could not fill: build/w661.log, a 180 s soak, held 158
// KOBJPORT-REFUSE rows for fn=NtDeviceIoControlFile, all of them code
// 0x70000, one every ~1.1 s. A 158-attempt retry loop is the title waiting for
// an answer, and refusing forever is its own defect. The two replies are NOT
// symmetric, and separating them is the whole fix:
//
//   * BYTES PER SECTOR is a constant of the console's block device. It is
//     established, it is published below, and the answer costs nothing to
//     invent. A host with no DVD drive can still say what the console's drive
//     reports, exactly as a console with one fitted does.
//   * A VOLUME CAPACITY (the partition LENGTH, and the geometry reply's total
//     sector count) is a property of one particular volume. Nothing in
//     .research/** establishes the console's utility/cache capacity, so those
//     stay refused. The reference's 0xFF000 is NOT carried forward: it is a
//     hardcoded size for a disk that does not exist
//     (xboxkrnl_io.cc:684, :694, :702), and that fabrication is the only
//     reason the port refused in the first place.
//
// The title's own use of the answer is what makes answering safe. After
// 0x70000 succeeds it reads ONLY the bytes-per-sector dword and uses it as a
// power of two to convert a byte count into a sector count
// (ppc_recomp.82.cpp:10801-10813, then :11166-11167 `srw r11,r24,r22` feeding
// `stw r11,8(r31)`), and it then page-aligns it for its own I/O chunk
// (:10882-10887, `(bps+4095) & ~0xFFF` = 4096 for every bps <= 4096). A
// fabricated total-sector count would have been read as a disc size and used to
// shape that I/O; zero cannot be, because nothing reads it.
//
// WHAT THE OLD REFUSAL ALSO BOUGHT, and this is why the body was the highest
// priority of the fourteen: the project's NtOpenFile is a `void` stub
// (imports.cpp:1042), so r3 is never assigned and the guest's `cmpwi r3,0; blt`
// (ppc_recomp.82.cpp:10752-10755) sees a POSITIVE pointer and walks INTO this
// call with a handle that was never a handle. With the refusal the stub
// returned that handle pointer, `bge` was taken anyway, and the title read
// UNINITIALISED STACK at [r1+124] for its cache size (:10801-10806). This body
// therefore does not trust ANY of its arguments, least of all the handle: it
// dispatches on the control code alone and never dereferences the handle.
//
// DIVERGENCE FROM THE REFERENCE, deliberate and unchanged in spirit: Xenia
// never touches its io_status_block argument at all (xboxkrnl_io.cc:676-711).
// The NT contract reports completion there -- for a refusal AND for the answer
// this file now gives -- and this project already follows it elsewhere
// (imports.cpp:1481-1489, quoting xboxkrnl_io.cc:419-422). Information is the
// number of bytes handed back: 0 on a refusal because nothing was written, 8
// on the geometry answer because 8 were. The event is NOT signalled on any
// path: signalling an event for I/O this host did not perform is the same
// fabricated-completion defect one layer up (imports.cpp:1491-1494), and the
// async code below is answered with a negative status precisely so the title
// never parks on an event that will not be signalled.
// ---------------------------------------------------------------------------

// The three control codes, as LITERALS in the recompiled guest, plus the one
// that is not. Nothing here is a guess at an enumeration: each is a value read
// out of the recompiled call site, and each site's full argument list was read
// rather than inferred.
//   0x70000  ppc_recomp.82.cpp:10770-10771  (r8 = 0x70000; output buffer
//            r1+120 = arg 9 at :10762-10763, length 8 at :10760/:10768-10769)
//   0x74004  ppc_recomp.82.cpp:10824-10835  (r8 = 0x70000|0x4004; output buffer
//            r1+160 at :10822/:10828-10829, length 16 at :10818/:10826-10827)
//   0x24400  ppc_recomp.81.cpp:3470-3485    (r8 = 0x20000|0x4400; output buffer
//            r1+104 at :3466/:3476-3477, length 4 at :3474/:3482-3483)
constexpr uint32_t kIoctlDiskGetDriveGeometry = 0x00070000u;
constexpr uint32_t kIoctlDiskGetPartitionInfo = 0x00074004u;
constexpr uint32_t kIoctlScsiPassThrough = 0x00024400u;

// The GET_DRIVE_GEOMETRY reply is 8 bytes: the reference requires exactly that
// much of the caller's buffer (xboxkrnl_io.cc:690-693) and writes exactly that
// much (xboxkrnl_io.cc:694-695).
constexpr uint32_t kGeometryReplyBytes = 8;

// THE GEOMETRY VALUE THAT IS ESTABLISHED, with the derivation, because the
// difference between 512 and 2048 IS the answer:
//   * 512 (0x200) is the sector size the console's own block layer reports to
//     userland, and Xenia ASSERTS it rather than assuming it:
//     `assert_true(info->bytes_per_sector == 0x200)` in the
//     XFileFsSizeInformation case at
//     .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_io_info.cc:320, under
//     the comment at :319 "sanity check, XCTD userland code seems to require
//     this". That is a property of the CONSOLE.
//   * it is the same value the reference writes into the geometry reply
//     (xboxkrnl_io.cc:695), and it is the value the title's only reader of
//     this field needs: the reply dword is used as a power of two
//     (ppc_recomp.82.cpp:10807-10811, `cntlzw` then `31-clz`) and as the shift
//     that turns a byte count into a sector count (:11166-11167,
//     `srw r11,r24,r22`), then page-aligned for its I/O chunk (:10882-10887).
// NOT 2048. 2048 is the sector of the DVD FILE SYSTEM layer, which is a
// different layer: .research/360tools/tools/extract_iso.py:22
// `SECTOR_SIZE = 2048` and
// .research/UnleashedRecomp/UnleashedRecomp/install/iso_file_system.cpp:29
// `XeSectorSize = 2048` both address XDVDFS sectors inside a disc image. A
// disc's own sector size is not the block device's sector size, and the block
// device is what an IOCTL_DISK_* code answers about.
// NOT the host's value either: nothing in this file or in src/** reads a host
// drive's geometry, and the host is not the console.
constexpr uint32_t kConsoleBytesPerSector = 512u;

// The OTHER half of the reply, and this is the field the reference fabricated.
// Reply dword +0 is the volume's total sector count; the reference derives it
// from its hardcoded 0xFF000-byte "cache_size" (xboxkrnl_io.cc:684 and :694),
// a capacity belonging to a disk that does not exist. No source in
// .research/** establishes the console's utility/cache volume capacity, so this
// field is published as ZERO -- the absence of a capacity, not a guess at one
// -- and that is safe because reply dword +0 is read by NOBODY in the guest
// image: the single load of the geometry reply buffer in the only function
// that calls this code is `lwz r11,124(r1)`, i.e. reply+4, at
// ppc_recomp.82.cpp:10801-10802. A fabricated 2040 would be read as "this
// disc holds 2040 sectors" and used to shape the title's I/O; zero cannot be
// mistaken for a disc, which is the truth about a host with none.
constexpr uint32_t kConsoleVolumeSectors = 0u;

uint32_t NtDeviceIoControlFile(uint32_t handle, uint32_t event, uint32_t apcRoutine,
                               uint32_t apcContext, uint32_t ioStatusBlock,
                               uint32_t ioControlCode, uint32_t inputBuffer,
                               uint32_t inputBufferLength, uint32_t outputBuffer,
                               uint32_t outputBufferLength)
{
    (void)apcRoutine;
    (void)apcContext;
    (void)inputBuffer;
    (void)inputBufferLength;
    (void)handle;
    (void)event;
    // `event` is deliberately never signalled on any path below; see the
    // DIVERGENCE paragraph above. At the answered code the guest passes 0
    // anyway (ppc_recomp.82.cpp:10776-10777, `li r4,0`).

    // ---- 0x70000 IOCTL_DISK_GET_DRIVE_GEOMETRY -- ANSWERED ---------------
    // CTL_CODE(FILE_DEVICE_DISK=7, function 0, METHOD_BUFFERED,
    // FILE_ANY_ACCESS) is the standard value of this code, and the reference
    // names it X_IOCTL_DISK_GET_DRIVE_GEOMETRY (xboxkrnl_io.cc:686).
    if (ioControlCode == kIoctlDiskGetDriveGeometry)
    {
        EnterIoctl(g_ioctlGeometry, ioControlCode);

        // The one ESTABLISHED refusal on this code, and its status is the
        // reference's own: the reply is 8 bytes and the reference requires
        // exactly that much (xboxkrnl_io.cc:690-693). The null check is OURS and
        // stricter than the reference, which would have written through a null
        // output pointer: on this guest VA 0 is mapped low memory, so an
        // unanswered write there would corrupt the guest instead of the log.
        if (outputBuffer == 0 || outputBufferLength < kGeometryReplyBytes)
        {
            const uint32_t tooSmall = Refuse(
                g_refIoControl, "NtDeviceIoControlFile", kStatusBufferTooSmall,
                "IOCTL 0x00070000 GET_DRIVE_GEOMETRY needs a non-NULL 8-byte reply "
                "buffer (xboxkrnl_io.cc:690-693); the caller offered out=" +
                    Hex(outputBuffer) + " out_len=" + Dec(outputBufferLength));
            WriteIoStatus(ioStatusBlock, tooSmall, 0);
            return tooSmall;
        }

        // THE REPLY, field for field, in the guest's byte order. The
        // reference's `xe::store_and_swap<uint32_t>` is a big-endian store on a
        // little-endian host -- `*reinterpret_cast<uint32_t*>(mem) =
        // byte_swap(value)`, .research/xenia/src/xenia/base/memory.h:431-433 --
        // so WriteU32BE is the matching checked writer (memory.h:103-104) and no
        // reinterpret_cast of guest data appears anywhere in this body.
        //
        // Reply shape, from the reference (xboxkrnl_io.cc:694-695):
        //     +0  uint32  total sector count of the volume
        //     +4  uint32  bytes per sector
        // Measured NOT to be the 24-byte Windows DISK_GEOMETRY: the reference
        // demands 8 bytes and writes 8 (xboxkrnl_io.cc:690-695), and the title's
        // only read of the reply is +4, used as a power of two and as a shift
        // (ppc_recomp.82.cpp:10801-10813, :11166-11167). In a Windows
        // DISK_GEOMETRY, +4 is the low half of Cylinders and +0x14 is
        // BytesPerSector, so the 360's reply is its own, smaller structure.
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        const bool wrote = mem.WriteU32BE(outputBuffer, kConsoleVolumeSectors) &&
                           mem.WriteU32BE(outputBuffer + 4, kConsoleBytesPerSector);
        if (!wrote)
        {
            // The answer could not be delivered, so it did not happen. Same
            // status as before, different and named cause -- and it stays a
            // refusal, so a soak can still see that nothing was answered.
            const uint32_t undeliverable = Refuse(
                g_refIoControl, "NtDeviceIoControlFile", kStatusNoSuchDevice,
                "IOCTL 0x00070000 GET_DRIVE_GEOMETRY ANSWERED, but the caller's "
                "reply buffer at " +
                    Hex(outputBuffer) +
                    " is outside the guest window; NOTHING WAS WRITTEN");
            WriteIoStatus(ioStatusBlock, undeliverable, 0);
            return undeliverable;
        }

        // SUCCESS. Information is the count of reply bytes handed back -- the
        // NT meaning of that field -- which is 8 here, not 0.
        WriteIoStatus(ioStatusBlock, 0, kGeometryReplyBytes);

        ReportIoctlOk(g_ioctlGeometry, ioControlCode,
                      "GET_DRIVE_GEOMETRY total_sectors=0(CAPACITY-UNVERIFIED,"
                      "read-by-nobody) bytes_per_sector=512 reply_bytes=8 "
                      "out=" + Hex(outputBuffer) + " out_len=" +
                          Dec(outputBufferLength));
        return 0;
    }

    // ---- 0x74004 IOCTL_DISK_GET_PARTITION_INFO -- REFUSED, and why -------
    // CTL_CODE(FILE_DEVICE_DISK=7, function 1, METHOD_BUFFERED, FILE_READ_DATA),
    // named at xboxkrnl_io.cc:687. The title reads the partition LENGTH out of
    // this reply -- `ld r10,168(r1)` = reply+8, ppc_recomp.82.cpp:10853-10854 --
    // and rejects the volume with 0xC000007F unless the length exceeds one 4 KiB
    // chunk (:10906-10916, the constant built at :10911-10914). A length is a
    // property of ONE particular volume, not a console constant, and no source
    // in .research/** establishes it. The reference's 0xFF000 (xboxkrnl_io.cc:702)
    // is not carried forward.
    if (ioControlCode == kIoctlDiskGetPartitionInfo)
    {
        EnterIoctl(g_ioctlPartition, ioControlCode);
        const uint32_t status = Refuse(
            g_refIoctlPartition, "NtDeviceIoControlFile", kStatusNoSuchDevice,
            "IOCTL 0x00074004 GET_PARTITION_INFO: the title reads the partition "
            "LENGTH (reply+8, ppc_recomp.82.cpp:10853-10854) and rejects a volume "
            "shorter than one 4 KiB chunk with 0xC000007F (:10906-10916). A "
            "partition LENGTH is a property of ONE volume; no source in "
            ".research/** establishes the console's utility/cache capacity, and "
            "Xenia's hardcoded 0xFF000 (xboxkrnl_io.cc:702) is a size for a disk "
            "that does not exist. NOT FABRICATED, NOT ANSWERED");
        WriteIoStatus(ioStatusBlock, status, 0);
        return status;
    }

    // ---- 0x24400 IOCTL_SCSI_PASS_THROUGH -- REFUSED, and why -------------
    // Decoded from the value rather than recalled, because the reference has no
    // name for it: device = 0x24400>>16 = 2 = FILE_DEVICE_CD_ROM, access =
    // (0x24400>>14)&3 = 1 = FILE_READ_DATA, function = (0x24400>>2)&0xFFF = 0x100,
    // method = 0x24400&3 = 0 = METHOD_BUFFERED -- which is exactly the
    // documented definition of IOCTL_SCSI_PASS_THROUGH, a SCSI command
    // descriptor block handed to a physical optical drive. This host has no
    // drive, and the title's own reader of the 4-byte reply only tests bit 28 of
    // it for a "this is a real disc" decision (ppc_recomp.81.cpp:3529-3536), so
    // any value we invented would be read as a disc capacity.
    // It is also the ASYNC site: the title tests STATUS_PENDING == 259
    // (ppc_recomp.81.cpp:3497-3498) and then parks in NtWaitForSingleObjectEx on
    // the event (:3501-3511), re-reading the io status block afterwards
    // (:3512-3513). So it is answered with a NEGATIVE status the caller takes
    // on its error branch (:3525-3528) and NEVER with STATUS_PENDING: an armed
    // completion that is never delivered is a hang, and there is no APC or event
    // delivery machinery in src/ to deliver one.
    if (ioControlCode == kIoctlScsiPassThrough)
    {
        EnterIoctl(g_ioctlScsiPassThrough, ioControlCode);
        const uint32_t status = Refuse(
            g_refIoctlScsiPassThrough, "NtDeviceIoControlFile", kStatusNotSupported,
            "IOCTL 0x00024400 IOCTL_SCSI_PASS_THROUGH (device 2 = CD_ROM, "
            "function 0x100, METHOD_BUFFERED, FILE_READ_DATA): a SCSI CDB for a "
            "physical optical drive, and this host has no drive to pass it to; the "
            "title's only read of the 4-byte reply tests bit 28 of it as a "
            "real-disc decision (ppc_recomp.81.cpp:3529-3536). ASYNC at its only "
            "call site (STATUS_PENDING test :3497-3498, then a park on the event "
            ":3501-3511), so it is refused NOT_SUPPORTED and never PENDING");
        WriteIoStatus(ioStatusBlock, status, 0);
        return status;
    }

    // ---- anything else -- its own refusal, never a fallthrough -----------
    return RefuseUnknownIoctl(ioControlCode, ioStatusBlock);
}

// ---------------------------------------------------------------------------
// IoDismountVolume -- REFUSE
//
// THERE IS NO REFERENCE. Measured: "IoDismountVolume" appears ZERO times in the
// entire Xenia kernel tree -- a recursive content search over
// .research/xenia/src/xenia/kernel/**/*.{cc,h}. The brief pointed at
// xboxkrnl_io.cc; it is not there, and it is not in xiocompletion.cc either.
//
// IT IS DESTRUCTIVE, and the guest calls it on a LIVE volume: sub_8244E538+0x19c
// and +0x1d4 (ppc_recomp.80.cpp:11597-11601 and :11629-11633), the cache-volume
// teardown loop, each immediately followed by ObDereferenceObject on the same
// handle (:11602-11606, :11634-11636) -- the guest believes the volume went away
// and drops its reference. STATUS_SUCCESS here would leave the title believing a
// volume it still holds was torn down, which is the "appears torn down when it
// was not" case exactly.
//
// WHY A REFUSAL IS SAFE HERE, measured rather than assumed: the guest DISCARDS
// the return value. ppc_recomp.80.cpp:11599-11606 runs straight from
// `bl 0x827bd964` to `ObDereferenceObject` with no test of r3, and the second
// site (:11629-11636) does the same. So no status can trip a fatal on this path,
// and the only dangerous answer -- success -- is the one being withheld.
//
// STATUS_NOT_IMPLEMENTED (0xC0000002, xenia/xbox.h:46): "this host does not
// perform this operation". Not STATUS_SUCCESS, and not an access-denied, which
// would blame a permission the title never lacked.
// ---------------------------------------------------------------------------
uint32_t IoDismountVolume(uint32_t unknown0, uint32_t unknown1)
{
    (void)unknown0;
    (void)unknown1;
    return Refuse(g_refDismount, "IoDismountVolume", kStatusNotImplemented,
                  "NO REFERENCE EXISTS (0 hits for IoDismountVolume in the whole "
                  "Xenia kernel tree) and the call is DESTRUCTIVE: the guest "
                  "discards r3 and immediately ObDereferenceObject's the same "
                  "handle (ppc_recomp.80.cpp:11599-11606), so a success would claim "
                  "a live volume was torn down. NOTHING WAS UNMOUNTED");
}

// ---------------------------------------------------------------------------
// IoDismountVolumeByFileHandle -- REFUSE, same reason, one call site:
// sub_8245FB30+0x3c8, the tail of the same cache-mount routine. The project's
// VFS has no unmount entry point at all -- src/fs/vfs_rpf.h exposes Open, Read,
// Seek, Close, List, Exists, GetFileSize and IsDirectory (that list measured at
// imports.cpp:1464-1467) -- so there is nothing to call even if the semantics
// were known.
// ---------------------------------------------------------------------------
uint32_t IoDismountVolumeByFileHandle(uint32_t fileHandle, uint32_t unknown1)
{
    (void)fileHandle;
    (void)unknown1;
    return Refuse(g_refDismountByHandle, "IoDismountVolumeByFileHandle",
                  kStatusNotImplemented,
                  "same as IoDismountVolume: no reference anywhere in Xenia, and "
                  "src/fs/vfs_rpf.h exposes no unmount entry point to call. "
                  "NOTHING WAS UNMOUNTED");
}

// ---------------------------------------------------------------------------
// The three string exports. The engine is the one above; these three bodies are
// the reference's own tails, transcribed.
//
// The guest's use, measured: __snprintf has 7 call sites, sprintf 7,
// __vsnprintf 2 (`ppc_xrefs.py calls 0x827BD944 / 0x827BD704 / 0x827BD724`).
// All 7 __snprintf sites go through three wrappers (sub_8244DC68, sub_8244E178,
// sub_8244E1F8), so this is a live, heavily used path -- which is why it is REAL
// and why the engine is worth getting right rather than stubbing.
// ---------------------------------------------------------------------------

// _snprintf -- REAL. strings.cc:857-894. The early-out is the reference's: a
// null buffer, a non-positive count or a null format returns -1 (:868-871).
int32_t XkSnprintf(void* buffer, int32_t bufferCount, const void* format)
{
    CountCall(g_censusFormat);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t bufferVa = buffer ? mem.MapVirtual(buffer) : 0;
    const uint32_t formatVa = format ? mem.MapVirtual(format) : 0;

    if (bufferVa == 0 || bufferCount <= 0 || formatVa == 0)
    {
        return RefuseFormatAs("__snprintf",
                              "null buffer, non-positive count, or null format "
                              "(the reference returns -1 here too)");
    }

    GuestFormatData data(formatVa);
    // First variadic argument is ordinal 3. Ordinals 8 and beyond come off the
    // guest stack through ArgTranslator (function.h:162-203), the reader that
    // owns the F611-STACKARG-READ marker.
    GuestStackArgs args(3, mcla::kernel::g_memory.base);
    const int32_t produced = FormatCore(data, args, false);

    int32_t result;
    if (produced < 0)
    {
        // Xenia: "write a null, just to be safe" (strings.cc:881-883). The
        // buffer VA was range-checked above, so a failure here means a racing
        // teardown; still not dropped silently.
        if (!mem.WriteU8(bufferVa, 0))
        {
            return RefuseFormatAs("__snprintf",
                                  "could not write the safety terminator after a "
                                  "format error");
        }
        result = produced;
    }
    else
    {
        result = TailBuffer(bufferVa, bufferCount, data.str());
        if (result > bufferCount)
        {
            result = -1;  // strings.cc:891-892
        }
    }

    CountOk(g_censusFormat, "__snprintf",
            "produced=" + std::to_string(produced) +
                " returned=" + std::to_string(result) +
                " bufferCount=" + std::to_string(bufferCount));
    return result;
}

// _vsnprintf -- REAL. strings.cc:1001-1041. The va_list is read as 8-byte slots
// out of guest memory (Xenia's ArrayArgList, :703-720).
int32_t XkVsnprintf(void* buffer, int32_t bufferCount, const void* format,
                    uint32_t argList)
{
    CountCall(g_censusFormat);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t bufferVa = buffer ? mem.MapVirtual(buffer) : 0;
    const uint32_t formatVa = format ? mem.MapVirtual(format) : 0;

    if (bufferVa == 0 || bufferCount <= 0 || formatVa == 0)
    {
        return RefuseFormatAs("__vsnprintf",
                              "null buffer, non-positive count, or null format "
                              "(the reference returns -1 here too)");
    }

    GuestFormatData data(formatVa);
    GuestArrayArgs args(argList);
    const int32_t produced = FormatCore(data, args, false);

    int32_t result;
    if (produced < 0)
    {
        if (!mem.WriteU8(bufferVa, 0))
        {
            return RefuseFormatAs("__vsnprintf",
                                  "could not write the safety terminator after a "
                                  "format error");
        }
        result = produced;
    }
    else
    {
        // The reference does NOT apply the _snprintf -1 on overflow here; it
        // returns the count it would have written (strings.cc:1037-1038). Kept.
        result = TailBuffer(bufferVa, bufferCount, data.str());
    }

    CountOk(g_censusFormat, "__vsnprintf",
            "produced=" + std::to_string(produced) +
                " returned=" + std::to_string(result) + " vaList=" + Hex(argList));
    return result;
}

// sprintf -- REAL. strings.cc:897-925. Unbounded destination, so the full length
// is written and the terminator always follows. The early-out is the
// reference's: -1 for a null buffer or format (:906-909). Note the reference
// returns `count` -- not 0 -- when the result is empty (:918-920), and that is
// preserved.
int32_t XkSprintf(void* buffer, const void* format)
{
    CountCall(g_censusFormat);
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t bufferVa = buffer ? mem.MapVirtual(buffer) : 0;
    const uint32_t formatVa = format ? mem.MapVirtual(format) : 0;

    if (bufferVa == 0 || formatVa == 0)
    {
        return RefuseFormatAs("sprintf",
                              "null buffer or null format (the reference returns "
                              "-1 here too)");
    }

    GuestFormatData data(formatVa);
    // First variadic argument is ordinal 2.
    GuestStackArgs args(2, mcla::kernel::g_memory.base);
    const int32_t produced = FormatCore(data, args, false);

    int32_t result;
    if (produced <= 0)
    {
        if (!mem.WriteU8(bufferVa, 0))
        {
            return RefuseFormatAs("sprintf", "could not write the empty-result terminator");
        }
        result = produced;
    }
    else
    {
        const std::string& text = data.str();
        if (!mem.WriteBytes(bufferVa, text.c_str(), static_cast<uint32_t>(produced)))
        {
            result = RefuseFormat("destination write failed");
        }
        else if (!mem.WriteU8(bufferVa + static_cast<uint32_t>(produced), 0))
        {
            result = RefuseFormat("terminator write failed");
        }
        else
        {
            result = produced;
        }
    }

    CountOk(g_censusFormat, "sprintf",
            "produced=" + std::to_string(produced) +
                " returned=" + std::to_string(result));
    return result;
}

}  // namespace kobjport

// ===========================================================================
// Registration. The form used by every already-ported function in imports.cpp
// (e.g. :6441 GUEST_FUNCTION_HOOK(__imp__RtlCompareMemoryUlong,
// RtlCompareMemoryUlong)); the integration stream deletes the 14 matching
// GUEST_FUNCTION_STUB lines from imports.cpp so exactly one definition of each
// __imp__ thunk exists.
//
// The bodies are namespaced so this file's `sprintf` cannot collide with the
// CRT's extern "C" sprintf. That is not a theoretical worry: the old
// `void sprintf() { ... }` at imports.cpp:6834 sat in the GLOBAL namespace, so
// leaving it in place next to a namespaced port of the same export would be both
// a duplicate and a trap for the next reader.
// ===========================================================================
GUEST_FUNCTION_HOOK(__imp__XMsgCancelIORequest, ::kobjport::XMsgCancelIORequest);
GUEST_FUNCTION_HOOK(__imp__KeTryToAcquireSpinLockAtRaisedIrql,
                    ::kobjport::KeTryToAcquireSpinLockAtRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__KeSetDisableBoostThread, ::kobjport::KeSetDisableBoostThread);
GUEST_FUNCTION_HOOK(__imp__NtCreateMutant, ::kobjport::NtCreateMutant);
GUEST_FUNCTION_HOOK(__imp__NtReleaseMutant, ::kobjport::NtReleaseMutant);
GUEST_FUNCTION_HOOK(__imp__NtCreateTimer, ::kobjport::NtCreateTimer);
GUEST_FUNCTION_HOOK(__imp__NtSetTimerEx, ::kobjport::NtSetTimerEx);
GUEST_FUNCTION_HOOK(__imp__NtCancelTimer, ::kobjport::NtCancelTimer);
GUEST_FUNCTION_HOOK(__imp__NtDeviceIoControlFile, ::kobjport::NtDeviceIoControlFile);
GUEST_FUNCTION_HOOK(__imp__IoDismountVolume, ::kobjport::IoDismountVolume);
GUEST_FUNCTION_HOOK(__imp__IoDismountVolumeByFileHandle,
                    ::kobjport::IoDismountVolumeByFileHandle);
GUEST_FUNCTION_HOOK(__imp___snprintf, ::kobjport::XkSnprintf);
GUEST_FUNCTION_HOOK(__imp___vsnprintf, ::kobjport::XkVsnprintf);
GUEST_FUNCTION_HOOK(__imp__sprintf, ::kobjport::XkSprintf);
