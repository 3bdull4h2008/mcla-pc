#include <stdafx.h>
#include "guest_thread.h"
#include <kernel/memory.h>
#include <kernel/heap.h>
#include <kernel/function.h>
#include "ppc_context.h"
#include <boot_host.h>  // B1ArmGuestThread (F-094 discriminator)
#include "logging.h"    // F-370: failed thread-context allocation must be named, not AV'd
#include <atomic>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include <unordered_map>

constexpr size_t PCR_SIZE = 0xAB0;
constexpr size_t TLS_SIZE = 0x100;
constexpr size_t TEB_SIZE = 0x2E0;
constexpr size_t STACK_SIZE = 0x40000;
constexpr size_t TOTAL_SIZE = PCR_SIZE + TLS_SIZE + TEB_SIZE + STACK_SIZE;

constexpr size_t TEB_OFFSET = PCR_SIZE + TLS_SIZE;

// ---------------------------------------------------------------------------
// F-612 guest thread identity. GetThreadId used to hash std::thread::id (or
// pthread_t) with XXH32 (guest_thread.cpp:132-148 before this change) and hand
// that 32-bit hash to the guest as the KTHREAD ThreadId - both through
// ExCreateThread's out-parameter (imports.cpp:4264-4270) and into the TEB at
// +0x14C (:45). A hash of a host handle is not a Xenon TID: it is not monotonic,
// it collides, and it has no relation to the handle the guest was handed.
//
// Xenia draws ids from ONE plain monotonic counter:
//   xthread.cc:47   uint32_t next_xthread_id_ = 0;
//   xthread.cc:57   thread_id_(++next_xthread_id_)
//   xthread.cc:218  xe::store_and_swap<uint32_t>(p + 0x14C, thread_id_);
//   xthread.cc:127  GetCurrentThreadId() -> the KTHREAD's thread_id
// i.e. a single global sequence starting at 1 - NOT a per-CPU counter - and the
// SAME id is both the out-parameter value and the TEB+0x14C value. That is what
// is reproduced here. 0 stays reserved: to the guest it means "no thread".
// ---------------------------------------------------------------------------
static std::atomic<uint32_t> g_nextGuestThreadId{1};

static uint32_t AllocGuestThreadId() noexcept
{
    uint32_t id = g_nextGuestThreadId.fetch_add(1, std::memory_order_relaxed);
    if (id == 0)
    {
        // Wrapped past 2^32; step over the reserved 0.
        id = g_nextGuestThreadId.fetch_add(1, std::memory_order_relaxed);
    }
    return id;
}

// Guest TID of the host thread running guest code right now. Seeded by
// GuestThreadFunc from the owning handle's id, so a thread's own id and its
// handle's id are ONE number (xthread.cc:218); lazily allocated for a host
// thread that runs guest code without a handle (boot worker, audio worker).
static thread_local uint32_t t_currentGuestThreadId = 0;

static void SetCurrentGuestThreadId(uint32_t id) noexcept
{
    t_currentGuestThreadId = id;
}

// Per-handle state. GuestThreadHandle's layout is fixed by guest_thread.h (not
// this change), so the id assigned at creation and the exit facts live here,
// keyed by the handle. Registered in the ctor BEFORE the host thread exists and
// erased in the dtor AFTER the join, so a running body can never see a record
// destroyed underneath it, and Wait() can see a thread that has finished.
struct GuestThreadRecord
{
    uint32_t threadId = 0;
    uint32_t exitStatus = 0;                // guest r3 when the body returned
    std::atomic<bool> finished{false};
};

static std::mutex& ThreadTableMutex()
{
    static std::mutex s_mutex;
    return s_mutex;
}

static std::unordered_map<const GuestThreadHandle*, std::shared_ptr<GuestThreadRecord>>& ThreadTable()
{
    static std::unordered_map<const GuestThreadHandle*, std::shared_ptr<GuestThreadRecord>> s_table;
    return s_table;
}

static std::shared_ptr<GuestThreadRecord> FindThreadRecord(const GuestThreadHandle* handle)
{
    std::lock_guard<std::mutex> lock{ ThreadTableMutex() };
    const auto it = ThreadTable().find(handle);
    return it != ThreadTable().end() ? it->second : nullptr;
}

// The thread block (PCR/TLS/TEB/stack) IS guest memory, so these fields go
// through the checked, big-endian helpers. The old form stored them with
// `*(uint32_t*)thread = ByteSwap(...)` on a host pointer, which is
// endian-correct only on a little-endian host and range-checks nothing.
static bool WriteThreadBlockU32(uint8_t* block, size_t offset, uint32_t value)
{
    return mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(
        mcla::kernel::g_memory.MapVirtual(block + offset), value);
}

static bool WriteThreadBlockU8(uint8_t* block, size_t offset, uint8_t value)
{
    return mcla::kernel::GuestMemoryHeap::Instance().WriteU8(
        mcla::kernel::g_memory.MapVirtual(block + offset), value);
}

GuestThreadContext::GuestThreadContext(uint32_t cpuNumber)
{
    assert(thread == nullptr);

    thread = (uint8_t*)g_userHeap.Alloc(TOTAL_SIZE);
    if (thread == nullptr)
    {
        // F-370: this used to fall straight into `memset(nullptr, 0, 0x40E90)`, which is the
        // 2026-09-26 w373 host C0000005 (write to 0x20 inside memset, called from
        // GuestThread::Start -> this ctor) and it killed the new thread silently. Logging the
        // failure makes "the guest asked for N threads and got M<N" answerable from the log;
        // GuestThread::Start below refuses to run the entry point when the context has no stack.
        static std::atomic<uint32_t> s_ctxNull{0};
        const uint32_t n = s_ctxNull.fetch_add(1) + 1;
        if (n <= 16 || (n % 100) == 0)
            MCLA_LOG_ERROR("F370-THREAD-CTX-NULL #{} size=0x{:X} cpu={} - thread NOT started", n,
                           static_cast<unsigned>(TOTAL_SIZE), cpuNumber);
        return;
    }
    memset(thread, 0, TOTAL_SIZE);

    // TLS / TEB / cpu number / thread id are all big-endian GUEST memory: they
    // go through WriteThreadBlock* so a failed MapVirtual or an out-of-window
    // address is named instead of storing into whatever the host pointer
    // arithmetic produced. The values written are unchanged.
    const uint32_t tlsVa = mcla::kernel::g_memory.MapVirtual(thread + PCR_SIZE);
    const uint32_t tebVa = mcla::kernel::g_memory.MapVirtual(thread + PCR_SIZE + TLS_SIZE);
    const uint32_t blockVa = mcla::kernel::g_memory.MapVirtual(thread);
    if (tlsVa == 0 || tebVa == 0 || blockVa == 0)
    {
        static std::atomic<uint32_t> s_badBlockVa{0};
        const uint32_t n = s_badBlockVa.fetch_add(1) + 1;
        if (n <= 8 || (n % 100) == 0)
            MCLA_LOG_ERROR("F612-THREAD-BLOCK-VA #{} block={} tls={:08X} teb={:08X} "
                           "- TLS/TEB links NOT written; the guest faults on its "
                           "first TLS access",
                           n, static_cast<const void*>(thread), tlsVa, tebVa);
    }
    else
    {
        (void)WriteThreadBlockU32(thread, 0x000, tlsVa);  // tls pointer
        (void)WriteThreadBlockU32(thread, 0x100, tebVa);  // teb pointer
        (void)WriteThreadBlockU8(thread, 0x10C, cpuNumber);
        // TEB + 0x14C is the KTHREAD ThreadId and must be the same number
        // ExCreateThread handed the guest in its out-parameter
        // (imports.cpp:4264-4270); xthread.cc:218 stores thread_id_ there.
        (void)WriteThreadBlockU32(thread, TEB_OFFSET + 0x14C,
                                  GuestThread::GetCurrentThreadId());
    }

    (void)WriteThreadBlockU32(thread, PCR_SIZE + 0x10, 0xFFFFFFFF); // that one TLS entry that felt quirky

    ppcContext.r1.u64 = mcla::kernel::g_memory.MapVirtual(thread + PCR_SIZE + TLS_SIZE + TEB_SIZE + STACK_SIZE); // stack pointer
    ppcContext.r13.u64 = mcla::kernel::g_memory.MapVirtual(thread);
    ppcContext.fpscr.loadFromHost();
    // F-611 carriage: `ppcContext` is value-initialised (guest_thread.h:18
    // `PPCContext ppcContext{}`), so every context member the *_as_local
    // recompiler config leaves behind - lr, r4..r10, f1..f13, v0..v13 - is a
    // deterministic 0 instead of this frame's stack garbage, and msr takes the
    // PPCContext default 0x200A000 (FP+VMX on), the same value boot_host.cpp:710
    // sets for the boot thread. lr stays 0 deliberately: a thread start address
    // is entered like a function CALL, and the XEX entry stubs save LR before
    // touching it (`savegprlr 14`, toml:6-7), so a non-zero lr here would only
    // put a bogus return address on the guest stack. ctr/xer/cr0-7/reserved and
    // r14-r31 are function-locals in the callee and are not ours to set - see
    // the call-ABI contract at the top of kernel/function.h.

    assert(GetPPCContext() == nullptr);
    SetPPCContext(ppcContext);
}

GuestThreadContext::~GuestThreadContext()
{
    g_userHeap.Free(thread);
}

#ifdef USE_PTHREAD
static size_t GetStackSize()
{
    // Cache as this should not change.
    static size_t stackSize = 0;
    if (stackSize == 0)
    {
        // 8 MiB is a typical default.
        constexpr auto defaultSize = 8 * 1024 * 1024;
        struct rlimit lim;
        const auto ret = getrlimit(RLIMIT_STACK, &lim);
        if (ret == 0 && lim.rlim_cur < defaultSize)
        {
            // Use what the system allows.
            stackSize = lim.rlim_cur;
        }
        else
        {
            stackSize = defaultSize;
        }
    }
    return stackSize;
}

static void* GuestThreadFunc(void* arg)
{
    GuestThreadHandle* hThread = (GuestThreadHandle*)arg;
#else
static void GuestThreadFunc(GuestThreadHandle* hThread)
{
#endif
    mcla::boot::B1ArmGuestThread();  // B1 discriminator (F-094), log-only

    // Adopt the handle's guest TID as this host thread's own BEFORE any guest
    // code runs, so GetCurrentThreadId() answers from the same space as
    // GetThreadId() and GuestThreadContext's TEB+0x14C write lands the same
    // number ExCreateThread returned to the guest (xthread.cc:218).
    auto record = FindThreadRecord(hThread);
    SetCurrentGuestThreadId(record ? record->threadId : AllocGuestThreadId());

    hThread->suspended.wait(true);

    // The guest's r3 at thread exit. The old body threw this away
    // (`GuestThread::Start(hThread->params);` with the result unused), so a
    // thread that returned a status the guest cared about was indistinguishable
    // from one that never ran.
    const uint32_t status = GuestThread::Start(hThread->params);

    if (record)
    {
        record->exitStatus = status;
        record->finished.store(true, std::memory_order_release);
        MCLA_LOG_INFO("THREAD-EXIT id={} fn={:08X} r3={:08X} cpu-flag={:08X}",
                      record->threadId, hThread->params.function, status,
                      hThread->params.flags);
    }
    else
    {
        static std::atomic<uint32_t> s_noRecord{0};
        const uint32_t n = s_noRecord.fetch_add(1) + 1;
        if (n <= 8 || (n % 100) == 0)
            MCLA_LOG_WARN("F612-THREAD-NO-RECORD #{} fn={:08X} r3={:08X} - "
                          "exited with no registered record (Wait cannot time "
                          "out on it)",
                          n, hThread->params.function, status);
    }
#ifdef USE_PTHREAD
    return nullptr;
#endif
}

GuestThreadHandle::GuestThreadHandle(const GuestThreadParams& params)
    : params(params), suspended((params.flags & 0x1) != 0)
#ifdef USE_PTHREAD
    , threadCreated(false)
#endif
{
    // The record is registered HERE, in the body, and the host thread is started
    // after it. It used to be started from the mem-initializer list
    // (`thread(GuestThreadFunc, this)`), which means the guest body could run
    // while the constructor was still executing and read a not-yet-constructed
    // object - and there was no point at which an id could be assigned before
    // the thread that must use it started.
    auto record = std::make_shared<GuestThreadRecord>();
    record->threadId = AllocGuestThreadId();
    {
        std::lock_guard<std::mutex> lock{ ThreadTableMutex() };
        ThreadTable()[this] = record;
    }

#ifdef USE_PTHREAD
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, GetStackSize());
    const auto ret = pthread_create(&thread, &attr, GuestThreadFunc, this);
    pthread_attr_destroy(&attr);
    if (ret != 0) {
        fprintf(stderr, "pthread_create failed with error code 0x%X.\n", ret);
        record->finished.store(true, std::memory_order_release);
        return;
    }
    threadCreated = true;
#else
    thread = std::thread(GuestThreadFunc, this);
#endif
}

GuestThreadHandle::~GuestThreadHandle()
{
    // A real ExTerminateThread has to make this join return. There is nothing
    // today that can: ExTerminateThread is a log-only stub (imports.cpp:4216,
    // hooked at 4739), the guest body is an ordinary C++ frame with no cancel
    // point, and config/mcla_xenonrecomp.toml sets neither setJmpAddress nor
    // longJmpAddress, so recompiler.cpp:525-534 emits no setjmp/longjmp frames
    // for a kernel thread to unwind to. Until one of those exists, destroying
    // or waiting on a thread whose guest body never returns blocks here
    // forever. What a real terminate needs, in order of cost:
    //   1. a cancel flag on the record above, polled by the wait path the guest
    //      blocks in (its unsignalled infinite wait is the project's park class,
    //      F-412), so at least a *cooperative* terminate can complete; or
    //   2. setJmpAddress/longJmpAddress in the recompiler config, giving each
    //      guest thread a jmp_buf to longjmp back to - the only way to preempt
    //      a guest frame that is not at a poll point.
    // Either way the record must be erased only AFTER the join below, so a body
    // that is still running can never write into freed state.
#ifdef USE_PTHREAD
    if (threadCreated)
        pthread_join(thread, nullptr);
#else
    if (thread.joinable())
        thread.join();
#endif
    {
        std::lock_guard<std::mutex> lock{ ThreadTableMutex() };
        ThreadTable().erase(this);
    }
}

// F-612: the guest-visible KTHREAD ThreadId, from the monotonic allocator
// described at the top of this file. It is a property of the HANDLE, allocated
// once at construction, so it is stable for the guest's whole lifetime and is
// the same number ExCreateThread returns in its out-parameter and the same one
// in TEB+0x14C. The XXH32-of-std::thread::id it replaces could differ between
// two calls, collide between two live threads, and had no relation to the handle.
uint32_t GuestThreadHandle::GetThreadId() const
{
    auto record = FindThreadRecord(this);
    if (!record)
    {
        // Unreachable for a constructed handle; the lazy allocation keeps the
        // contract (never 0, always monotonic) even if the record was lost.
        record = std::make_shared<GuestThreadRecord>();
        record->threadId = AllocGuestThreadId();
        std::lock_guard<std::mutex> lock{ ThreadTableMutex() };
        ThreadTable()[this] = record;
        MCLA_LOG_WARN("F612-THREAD-ID-REALLOC {} - record missing, id={}",
                      static_cast<const void*>(this), record->threadId);
    }

    return record->threadId;
}

uint32_t GuestThreadHandle::Wait(uint32_t timeout)
{
    // F-612. `timeout` is milliseconds (imports.cpp:630 converts the guest's
    // Timeout argument with GuestTimeoutToMilliseconds) or INFINITE, and BOTH
    // are legal guest input, so neither may be asserted on:
    //   INFINITE -> the thread has finished; join it, report STATUS_WAIT_0
    //   0        -> poll: join if already finished, else STATUS_TIMEOUT
    //   finite   -> wait up to that long, then STATUS_TIMEOUT WITHOUT joining
    // The old body was `assert(timeout == INFINITE); join(); return WAIT_0;`.
    // Under the build's /DNDEBUG (compile_commands.json) the assert vanished and
    // a FINITE timeout still ran join(), i.e. a timed/alertable wait blocked
    // forever on a guest thread parked in an unsignalled infinite wait - the
    // project's observed park class.
    auto record = FindThreadRecord(this);

    if (timeout != INFINITE)
    {
        if (!record)
        {
            // Nothing registered to wait on. Report the timeout instead of
            // blocking, and say so once.
            static std::atomic<uint32_t> s_noRecWait{0};
            const uint32_t n = s_noRecWait.fetch_add(1, std::memory_order_relaxed) + 1;
            if (n <= 8 || (n % 100) == 0)
                MCLA_LOG_WARN("F612-WAIT-NO-RECORD #{} to={}ms - STATUS_TIMEOUT "
                              "without waiting",
                              n, timeout);
            return STATUS_TIMEOUT;
        }

        bool done;
#ifdef _WIN32
        // A Win32 thread handle takes a real timeout and stays joinable
        // afterwards (std::thread owns the handle; we do not close it).
        const auto hThread = thread.native_handle();
        if (hThread != nullptr)
        {
            const DWORD r = WaitForSingleObject(hThread, timeout);
            if (r == WAIT_TIMEOUT)
            {
                done = false;
            }
            else if (r == WAIT_OBJECT_0)
            {
                done = true;
            }
            else
            {
                MCLA_LOG_WARN("F612-WAIT-FAILED tid={} to={}ms err={} - "
                              "STATUS_UNSUCCESSFUL",
                              record->threadId, timeout, GetLastError());
                return STATUS_UNSUCCESSFUL;
            }
        }
        else
        {
            done = record->finished.load(std::memory_order_acquire);
        }
#else
        // The pthread ABI has no timed join, so poll the record's finished flag
        // at 1 ms. A condition_variable would need the guest body - which we do
        // not control - to be the notifier.
        const auto deadline = std::chrono::steady_clock::now() +
                              std::chrono::milliseconds(timeout);
        for (;;)
        {
            done = record->finished.load(std::memory_order_acquire);
            if (done || std::chrono::steady_clock::now() >= deadline)
                break;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
#endif

        if (!done)
        {
            static std::atomic<uint32_t> s_timeouts{0};
            const uint32_t n = s_timeouts.fetch_add(1, std::memory_order_relaxed) + 1;
            if (n <= 16 || (n % 500) == 0)
                MCLA_LOG_WARN("WAIT-TIMEOUT[TID] #{} tid={} to={}ms -> "
                              "STATUS_TIMEOUT (still running; NOT joined)",
                              n, record->threadId, timeout);
            return STATUS_TIMEOUT;
        }
    }

#ifdef USE_PTHREAD
    if (threadCreated)
        pthread_join(thread, nullptr);
#else
    if (thread.joinable())
        thread.join();
#endif

    if (record)
    {
        static std::atomic<uint32_t> s_waits{0};
        const uint32_t n = s_waits.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 16 || (n % 500) == 0)
            MCLA_LOG_INFO("WAIT-OK[TID] #{} tid={} r3={:08X}", n, record->threadId,
                          record->exitStatus);
    }

    return STATUS_WAIT_0;
}

uint32_t GuestThread::Start(const GuestThreadParams& params)
{
    const auto procMask = (uint8_t)(params.flags >> 24);
    const auto cpuNumber = procMask == 0 ? 0 : 7 - std::countl_zero(procMask);

    GuestThreadContext ctx(cpuNumber);
    ctx.ppcContext.r3.u64 = params.value;

    if (ctx.thread == nullptr)
        return 0;  // F-370: no stack window was allocated, so the entry point would fault on its
                   // very first store; the ctor already logged F370-THREAD-CTX-NULL.

    auto func = mcla::kernel::g_memory.FindFunction(params.function);
    if (!func)
    {
        // Named, not silent: the entry address is simply not in the recompiled
        // function table, and the guest thread has done nothing at all.
        static std::atomic<uint32_t> s_noEntry{0};
        const uint32_t n = s_noEntry.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 100) == 0)
            MCLA_LOG_WARN("F612-THREAD-NOFUNC #{} entry={:08X} ctx={:08X} - thread "
                          "did not run",
                          n, params.function, params.value);
        return 0;
    }
    func(ctx.ppcContext, mcla::kernel::g_memory.base);

    // The guest's exit status. GuestThreadFunc stores this on the handle's
    // record so a wait/join can report it; it used to be returned into the void
    // and dropped.
    return ctx.ppcContext.r3.u32;
}

GuestThreadHandle* GuestThread::Start(const GuestThreadParams& params, uint32_t* threadId)
{
    auto hThread = CreateKernelObject<GuestThreadHandle>(params);

    if (threadId != nullptr)
    {
        // The same number the thread writes into its own TEB+0x14C, from the one
        // monotonic allocator (xthread.cc:57/:218).
        *threadId = hThread->GetThreadId();
    }

    return hThread;
}

// F-612: the guest TID of the host thread running guest code, from the same
// monotonic allocator as GuestThreadHandle::GetThreadId() - so the self-check
// at imports.cpp:2141-2142 (`hThread->GetThreadId() ==
// GuestThread::GetCurrentThreadId()`) compares like with like. GuestThreadFunc
// seeds it with the handle's id; a host thread that runs guest code without a
// handle (boot worker, audio worker) gets one lazily on first use. Never 0,
// which the guest reads as "no thread".
uint32_t GuestThread::GetCurrentThreadId()
{
    if (t_currentGuestThreadId == 0)
    {
        t_currentGuestThreadId = AllocGuestThreadId();
    }

    return t_currentGuestThreadId;
}

void GuestThread::SetLastError(uint32_t error)
{
    // TEB-relative fields in GUEST memory: r13 is guest-supplied, so both the
    // read of the opt-out flag at +0x150 and the write of Win32LastError at
    // TEB+0x160 go through the checked, big-endian helpers. The old body did
    // `(char*)g_memory.Translate(r13)` (the unchecked `base + offset`,
    // memory.h:157-161) and then read/wrote it through `*(uint32_t*)` casts, so
    // a garbage r13 was a wild access in both directions.
    auto* ctx = GetPPCContext();
    if (ctx == nullptr)
        return;

    auto& heap = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t teb = ctx->r13.u32 + TEB_OFFSET;
    if (teb < ctx->r13.u32) // 32-bit wrap: the addition left the window
        return;

    uint32_t optedOut = 0;
    if (!heap.ReadU32BE(teb - (TEB_OFFSET - 0x150), &optedOut))
        return;
    if (optedOut)
    {
        // Program doesn't want errors
        return;
    }

    // TEB + 0x160 : Win32LastError
    (void)heap.WriteU32BE(teb + 0x160, error);
}

#ifdef _WIN32
void GuestThread::SetThreadName(uint32_t threadId, const char* name)
{
#pragma pack(push,8)
    const DWORD MS_VC_EXCEPTION = 0x406D1388;

    typedef struct tagTHREADNAME_INFO
    {
        DWORD dwType; // Must be 0x1000.
        LPCSTR szName; // Pointer to name (in user addr space).
        DWORD dwThreadID; // Thread ID (-1=caller thread).
        DWORD dwFlags; // Reserved for future use, must be zero.
    } THREADNAME_INFO;
#pragma pack(pop)

    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = name;
    info.dwThreadID = threadId;
    info.dwFlags = 0;

    __try
    {
        RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
    }
}
#endif

void SetThreadNameImpl(uint32_t a1, uint32_t threadId, uint32_t* name)
{
#ifdef _WIN32
    GuestThread::SetThreadName(threadId, (const char*)mcla::kernel::g_memory.Translate(ByteSwap(*name)));
#endif
}

int GetThreadPriorityImpl(GuestThreadHandle* hThread)
{
#ifdef _WIN32
    return GetThreadPriority(hThread == GetKernelObject(CURRENT_THREAD_HANDLE) ? GetCurrentThread() : hThread->thread.native_handle());
#else 
    return 0;
#endif
}

uint32_t SetThreadIdealProcessorImpl(GuestThreadHandle* hThread, uint32_t dwIdealProcessor)
{
    return 0;
}

GUEST_FUNCTION_HOOK(sub_82DFA2E8, SetThreadNameImpl);
GUEST_FUNCTION_HOOK(sub_82BD57A8, GetThreadPriorityImpl);
GUEST_FUNCTION_HOOK(sub_82BD5910, SetThreadIdealProcessorImpl);

GUEST_FUNCTION_STUB(sub_82BD58F8); // Some function that updates the TEB, don't really care since the field is not set
