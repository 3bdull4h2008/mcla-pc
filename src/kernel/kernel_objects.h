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

struct Semaphore final : KernelObject, HostObject<XKSEMAPHORE>
{
    std::atomic<uint32_t> count;
    uint32_t maximumCount;

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
                    count.wait(0);
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