#pragma once

#include "xdm.h"
#include "xbox.h"
#include "fs/vfs_rpf.h"
#include <spdlog/spdlog.h>
#include <atomic>
#include <cassert>
#include <chrono>
#include <thread>

// WAKE-LOSS PROBE (session 14): wrapper identity between semaphore wait and
// release paths. Inline + spdlog direct - including logging.h here breaks
// mutex.h's windows.h include-order assumption.
inline void SemaphoreProbeLog(const void* self, const char* site, uint32_t count)
{
    static std::atomic<uint32_t> s_semaProbeLogs{0};
    const uint32_t n = s_semaProbeLogs.fetch_add(1) + 1;
    if (n <= 60 || (n % 2000) == 0)
        spdlog::info("SEMA-{} this={} count={}", site, self, count);
}

struct Event final : KernelObject, HostObject<XKEVENT>
{
    bool manualReset;
    std::atomic<bool> signaled;

    Event(xpointer<XKEVENT> header)
    {
        uint8_t type = header->Type;
        manualReset = (type == 0);
        
        uint32_t signalState = header->SignalState.get();
        signaled = !!signalState;
    }

    Event(bool manualReset, bool initialState)
        : manualReset(manualReset), signaled(initialState)
    {
    }

    uint32_t Wait(uint32_t timeout) override
    {
        if (timeout == 0)
        {
            if (manualReset)
            {
                if (!signaled)
                    return STATUS_TIMEOUT;
            }
            else
            {
                bool expected = true;
                if (!signaled.compare_exchange_strong(expected, false))
                    return STATUS_TIMEOUT;
            }
        }
        else if (timeout == INFINITE)
        {
            if (manualReset)
            {
                signaled.wait(false);
            }
            else
            {
                while (true)
                {
                    bool expected = true;
                    if (signaled.compare_exchange_weak(expected, false))
                        break;

                    signaled.wait(expected);
                }
            }
        }
        else
        {
            // Finite timeout: bounded poll. std::atomic::wait has NO timed
            // form - blocking on it here skipped the deadline check whenever
            // no thread signaled inside the window (infinite park). Polling
            // honors the deadline; 1ms quantum is well under one frame.
            //
            // T43.24 (2026-10-16, audit finding #4): CONSUME the auto-reset
            // signal on the success exit. The finite arm previously returned
            // STATUS_SUCCESS without clearing `signaled`, so an auto-reset
            // event stayed signaled after a finite wait — the NEXT waiter
            // consumed the stale permit (spurious wake, doubled dispatch).
            // The CAS below matches what the Wait(0) and Wait(INFINITE) arms
            // already do for auto-reset events; manual-reset is a no-op.
            const auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(timeout);
            while (!signaled.load(std::memory_order_acquire))
            {
                if (std::chrono::steady_clock::now() >= deadline)
                    return STATUS_TIMEOUT;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            // Auto-reset: consume the signal (same CAS as the other arms).
            if (manualReset == false)
            {
                bool expected = true;
                signaled.compare_exchange_strong(expected, false,
                                                  std::memory_order_acq_rel,
                                                  std::memory_order_acquire);
            }
        }

        return STATUS_SUCCESS;
    }

    bool Set()
    {
        signaled = true;

        if (manualReset)
            signaled.notify_all();
        else
            signaled.notify_one();

        return TRUE;
    }

    bool Reset()
    {
        signaled = false;
        return TRUE;
    }
};

// F-852 (fix_sema, 2026-10-21): TRUE when the CALLING THREAD's last
// Semaphore::Wait actually BLOCKED -- i.e. it found no permit and had to wait
// for one -- as opposed to taking a permit and returning at once.  The
// semaphore's Wait() signature cannot carry it out (the base class's virtual
// is fixed and other overrides live in port_kobj.cpp, which is not ours to
// edit), so the flag is published here, per thread, and read by the SEMACNT
// census.  It is what lets the census print a RETURNED row for a wait that
// was DELAYED, which is the difference between "the wait returned at once"
// and "the wait came back only when somebody released".
inline thread_local bool g_semWaitBlocked = false;

struct Semaphore final : KernelObject, HostObject<XKSEMAPHORE>
{
    std::atomic<uint32_t> count;
    uint32_t maximumCount;

    // F-852 (fix_sema, 2026-10-21): the number of threads CURRENTLY BLOCKED
    // inside Semaphore::Wait on this object.
    //
    // WHY IT EXISTS.  The F-370 census row (src/gpu_device.cpp:7347-7357)
    // prints `init=` -- the INITIAL count, a CONSTANT for the life of the
    // object -- so it can never distinguish "this semaphore was starved" from
    // "this semaphore always had 15 permits".  MEASURED on the newest soak
    // (build/bctr_v2.log):
    //   :130574  "FI-ENQ #346 ... slotSem=B72C1048 slotCnt=15"
    //            -- the LIVE count of the very semaphore the boot worker parks
    //               on was 15 at 21:49:04.236, ONE MILLISECOND after the boot
    //               worker's wait entry at 21:49:04.235 (derived from
    //               :559439 "HB-FLICKER ... mainwait=B72C1048
    //               mainwait_age_ms=79314").  The F-370 row would have
    //               printed "init=15" for the whole story and looked identical.
    //   :623017  "BCTR-DISP #27099136 tid=00005CEC ctr=82130000 ..."
    //            -- the boot worker was STILL dispatching at 21:50:35, so that
    //               wait RETURNED.  The semaphore is not what stops it.
    // This counter is what makes a starved semaphore visible: (cnt=0,
    // waiters>0) at the WAIT, and waiters>0 at the RELEASE that should have
    // woken it.
    std::atomic<uint32_t> blockedWaiters{0};

    // Live snapshot of the semaphore's state, for the SEMACNT census row.
    uint32_t LiveCount() const { return count.load(std::memory_order_relaxed); }
    uint32_t BlockedWaiters() const
    {
        return blockedWaiters.load(std::memory_order_relaxed);
    }

    Semaphore(xpointer<XKSEMAPHORE> semaphore)
    {
        count = semaphore->Header.SignalState.get();
        maximumCount = semaphore->Limit.get();
    }

    Semaphore(uint32_t count, uint32_t maximumCount)
        : count(count), maximumCount(maximumCount)
    {
    }

    uint32_t Wait(uint32_t timeout) override
    {
        // WAKE-LOSS PROBE (session 14): consumers park on C5218280 but never
        // cycle despite NtReleaseSemaphore firing on it. Compare wrapper
        // identity between wait and release paths.
        //
        // T43.17 (2026-10-13): NO per-site gate here -- every call reaches
        // SemaphoreProbeLog, whose single shared gate (first 60 + every
        // 2000th across wait AND release) does the sampling. The old shape
        // had a second gate here (first 60 + every 2000th of waits alone),
        // so SEMA-wait rows were a doubly-censored sample: w764 showed 36
        // wait rows against 16,384 resolve-hits, which read as "36 waits"
        // when the truth was ~17k. One gate, stated here, no other.
        SemaphoreProbeLog(this, "wait", count.load());
        // F-852 (fix_sema): clear the "this wait blocked" flag; it is set only
        // by the arm that actually parks.
        g_semWaitBlocked = false;
        if (timeout == 0)
        {
            uint32_t currentCount = count.load();
            if (currentCount != 0)
            {
                if (count.compare_exchange_weak(currentCount, currentCount - 1))
                    return STATUS_SUCCESS;
            }

            return STATUS_TIMEOUT;
        }
        else if (timeout == INFINITE)
        {
            uint32_t currentCount;
            while (true)
            {
                currentCount = count.load();
                if (currentCount != 0)
                {
                    if (count.compare_exchange_weak(currentCount, currentCount - 1))
                        return STATUS_SUCCESS;
                }
                else
                {
                    // F-852 (fix_sema): we are ABOUT TO BLOCK.  Publish that
                    // fact so the SEMACNT census can print waiters>0 while this
                    // thread is parked, which is the difference between "the
                    // permit pool was empty" and "the wait never came back".
                    // The counter is decremented on EVERY path out of the
                    // blocking call, including a spurious wake-up.
                    blockedWaiters.fetch_add(1, std::memory_order_acq_rel);
                    g_semWaitBlocked = true;
                    count.wait(0);
                    blockedWaiters.fetch_sub(1, std::memory_order_acq_rel);
                }
            }

            return STATUS_SUCCESS;
        }
        else
        {
            // Finite timeout: bounded poll (see Event::Wait note - atomic::wait
            // is untimed and skipped the deadline when nobody signaled).
            const auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(timeout);
            while (true)
            {
                uint32_t currentCount = count.load();
                if (currentCount != 0)
                {
                    if (count.compare_exchange_weak(currentCount, currentCount - 1))
                        return STATUS_SUCCESS;
                }
                else
                {
                    if (std::chrono::steady_clock::now() >= deadline)
                        return STATUS_TIMEOUT;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }
            }
        }
    }

    void Release(uint32_t releaseCount, uint32_t* previousCount)
    {
        SemaphoreProbeLog(this, "release", count.load());

        if (previousCount != nullptr)
            *previousCount = count;

        assert(count + releaseCount <= maximumCount);

        count += releaseCount;
        count.notify_all();
    }
};

struct FileObject final : KernelObject
{
    mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fileHandle;

    FileObject(mcla::vfs::RpfVirtualFileSystem::OpenFileHandle&& handle)
        : fileHandle(std::move(handle))
    {
    }

    uint32_t Wait(uint32_t timeout) override
    {
        (void)timeout;
        return STATUS_SUCCESS; // Files don't really wait
    }
};

struct SectionObject final : KernelObject
{
    uint32_t fileHandle;   // guest kernel handle to the backing FileObject
    uint64_t maximumSize;  // maximum section size in bytes

    SectionObject(uint32_t fh, uint64_t maxSize)
        : fileHandle(fh), maximumSize(maxSize)
    {
    }

    uint32_t Wait(uint32_t timeout) override
    {
        (void)timeout;
        return STATUS_SUCCESS;
    }
};

inline void CloseKernelObject(XDISPATCHER_HEADER& header)
{
    if (header.WaitListHead.Flink != OBJECT_SIGNATURE)
    {
        return;
    }

    // CONSOLE-CORRECT HANDLE (2026-10-21, fix_typebyte): the wrapper is
    // found by the DISPATCHER ADDRESS (the handle the guest holds), not by
    // the Blink word: Blink carries the wrapper's BASE address (the C++
    // vptr is there), and the base is NOT a handle any more - feeding it to
    // DestroyKernelObject(uint32_t) would resolve the wrong object.
    DestroyKernelObject(mcla::kernel::g_memory.MapVirtual(&header));
}

inline uint32_t GuestTimeoutToMilliseconds(be<int64_t>* timeout)
{
    return timeout ? (*timeout * -1) / 10000 : INFINITE;
}