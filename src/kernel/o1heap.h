// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions
// of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// Copyright (c) 2020 Pavel Kirienko
// Authors: Pavel Kirienko <pavel.kirienko@zubax.com>
//
// READ THE DOCUMENTATION IN README.md.

#ifndef O1HEAP_H_INCLUDED
#define O1HEAP_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    /// The semantic version number of this distribution.
#define O1HEAP_VERSION_MAJOR 2

/// The guaranteed alignment depends on the platform pointer width.
#define O1HEAP_ALIGNMENT (sizeof(void*) * 4U)

/// The definition is private, so the user code can only operate on pointers. This is done to enforce encapsulation.
    typedef struct O1HeapInstance O1HeapInstance;

    /// Runtime diagnostic information. This information can be used to facilitate runtime self-testing,
    /// as required by certain safety-critical development guidelines.
    /// If assertion checks are not disabled, the library will perform automatic runtime self-diagnostics that trigger
    /// an assertion failure if a heap corruption is detected.
    /// Health checks and validation can be done with o1heapDoInvariantsHold().
    typedef struct
    {
        /// The total amount of memory available for serving allocation requests (heap size).
        /// The maximum allocation size is (capacity - O1HEAP_ALIGNMENT).
        /// This parameter does not include the overhead used up by O1HeapInstance and arena alignment.
        /// This parameter is constant.
        size_t capacity;

        /// The amount of memory that is currently allocated, including the per-fragment overhead and size alignment.
        /// For example, if the application requested a fragment of size 1 byte, the value reported here may be 32 bytes.
        size_t allocated;

        /// The maximum value of 'allocated' seen since initialization. This parameter is never decreased.
        size_t peak_allocated;

        /// The largest amount of memory that the allocator has attempted to allocate (perhaps unsuccessfully)
        /// since initialization (not including the rounding and the allocator's own per-fragment overhead,
        /// so the total is larger). This parameter is never decreased. The initial value is zero.
        size_t peak_request_size;

        /// The number of times an allocation request could not be completed due to the lack of memory or
        /// excessive fragmentation. OOM stands for "out of memory". This parameter is never decreased.
        uint64_t oom_count;

        /// 2026-09-30, ADDED (see o1heapAllocateGranular): the number of times the fixed-granularity
        /// search gave up because it walked O1HEAP_GRANULAR_MAX_HOPS links without finding a run.
        /// A well-formed heap never reaches the cap, so a non-zero value here is a CORRUPTION SIGNAL
        /// (a cyclic or self-referencing free list), not an out-of-memory signal. It exists because
        /// O1HEAP_ASSERT is compiled out under -DNDEBUG on every build of this file, so a property
        /// that must be observed at run time has to be observable through the diagnostics copy.
        /// Appended LAST on purpose: the fields above keep their offsets, which the host reads by
        /// hardcoded instance offsets (mask at instance+0x200, capacity at instance+0x208).
        uint64_t granular_walk_capped;
    } O1HeapDiagnostics;

    /// The arena base pointer shall be aligned at O1HEAP_ALIGNMENT, otherwise NULL is returned.
    ///
    /// The total heap capacity cannot exceed approx. (SIZE_MAX/2). If the arena size allows for a larger heap,
    /// the excess will be silently truncated away (no error). This is not a realistic use case because a typical
    /// application is unlikely to be able to dedicate that much of the address space for the heap.
    ///
    /// The function initializes a new heap instance allocated in the provided arena, taking some of its space for its
    /// own needs (normally about 40..600 bytes depending on the architecture, but this parameter is not characterized).
    /// A pointer to the newly initialized instance is returned.
    ///
    /// If the provided space is insufficient, NULL is returned.
    ///
    /// An initialized instance does not hold any resources. Therefore, if the instance is no longer needed,
    /// it can be discarded without any de-initialization procedures.
    ///
    /// The heap is not thread-safe; external synchronization may be required.
    O1HeapInstance* o1heapInit(void* const base, const size_t size);

    /// The footprint an instance needs, in bytes, i.e. INSTANCE_SIZE_PADDED. Exposed so a caller can
    /// size a buffer for o1heapInitSeparate without O1HeapInstance being a complete type here.
    size_t o1heapInstanceSize(void);

    /// Like o1heapInit, except the instance is placed in caller-supplied memory OUTSIDE the arena
    /// instead of in its first INSTANCE_SIZE_PADDED bytes.
    ///
    /// Why this exists: o1heapInit puts host control blocks at `base`, and when `base` is a
    /// guest-addressable physical-arena address the guest can be handed that address by a different
    /// allocator and write through it -- which destroys every bin head and makes o1heapAllocate
    /// return NULL for all sizes while o1heapDoInvariantsHold still reports the pool healthy. With the
    /// instance detached, the arena's first byte is an ordinary allocatable fragment and no guest
    /// write to a guest address can reach the control block.
    ///
    /// `instanceMem` must be aligned at O1HEAP_ALIGNMENT and hold at least o1heapInstanceSize() bytes;
    /// it is never returned by o1heapAllocate and must outlive the instance. `base` must be aligned at
    /// O1HEAP_ALIGNMENT and `size` must be at least FRAGMENT_SIZE_MIN. capacity is `size` (not
    /// `size - INSTANCE_SIZE_PADDED`), clamped and aligned exactly as o1heapInit does.
    ///
    /// Returns NULL if either pointer is NULL, either is misaligned, or `size` is too small.
    ///
    /// NOTE: o1heapFree's two debug bounds checks derive the arena from the handle address and are
    /// therefore meaningless for a detached instance. They are O1HEAP_ASSERT, compiled out under
    /// -DNDEBUG, and this project builds RelWithDebInfo with /DNDEBUG (CMakeLists.txt:569, :578), so
    /// they do not fire. A Debug build of a detached instance would assert on the first free.
    O1HeapInstance* o1heapInitSeparate(void* const instanceMem, void* const base, const size_t size);

    /// The semantics follows malloc() with additional guarantees the full list of which is provided below.
    ///
    /// If the allocation request is served successfully, a pointer to the newly allocated memory fragment is returned.
    /// The returned pointer is guaranteed to be aligned at O1HEAP_ALIGNMENT.
    ///
    /// If the allocation request cannot be served due to the lack of memory or its excessive fragmentation,
    /// a NULL pointer is returned.
    ///
    /// The function is executed in constant time.
    /// The allocated memory is NOT zero-filled (because zero-filling is a variable-complexity operation).
    void* o1heapAllocate(O1HeapInstance* const handle, const size_t amount);

    /// 2026-09-30, ADDED. Same semantics as o1heapAllocate() -- the returned pointer is aligned at
    /// O1HEAP_ALIGNMENT, the 32 bytes below it are the fragment header, and the block is released by
    /// passing the SAME pointer to o1heapFree() -- but the block is sized by rounding the request up to
    /// `granularity` instead of up to a power of two. Everything else about the block, its neighbours,
    /// its header and the diagnostics, is identical, so the two allocators are interchangeable.
    ///
    /// It exists because o1heap's sizing rule cannot express some requests at all. The power-of-two
    /// charge is `roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT)`, and a fragment that is the size of
    /// the WHOLE arena can only be held by the arena itself: a request whose class exceeds the
    /// capacity is unservable at every occupancy, so a pool can hold nearly all of its bytes free and
    /// still be unable to answer. Use this for a physical/page-backed pool; leave o1heapAllocate()
    /// alone for a heap whose size classes are part of the contract.
    ///
    /// `granularity` must be a power of two that is a multiple of FRAGMENT_SIZE_MIN; anything else is
    /// REFUSED (NULL) rather than rounded, because the arena is a grid of FRAGMENT_SIZE_MIN cells.
    ///
    /// 2026-09-30 (F-642), SCOPE WIDENED, and the note above is what made that necessary. This header
    /// previously said to call it "only for requests o1heapAllocate() has already proved it cannot
    /// serve, so the scan is paid on a refusal path and never on the hot path". That was the F-641
    /// threshold, and it was too narrow: being SERVABLE does not mean being served CHEAPLY. The
    /// power-of-two rule wastes up to half the arena on every request, and on a 512 MiB console pool
    /// that is the difference between a game that runs and one that exhausts its RAM (measured
    /// 1.5130x charged bytes over the same requests; see the F-642 block beside kO1PageGranule in
    /// src/kernel/heap.cpp). The reference allocator this sizing imitates has no size class at all --
    /// BaseHeap::AllocRange reduces the request to a PAGE COUNT and scans a per-page table
    /// (.research/xenia/src/xenia/memory.cc:924, :934, :949-988) -- so the page rule, not the
    /// power-of-two rule, is the faithful one for that pool, and it is now used for the whole pool.
    ///
    /// THE COST OF THE SCAN, MEASURED, so the widening is not taken on trust. Unlike every other
    /// entry point in this library, o1heapAllocateGranular() WALKS a free list rather than taking a
    /// bin head, so it is not constant time and that is a real difference. On this machine, replaying
    /// the request sequence measured in build/w672.log against a 512 MiB arena, it cost +24.9 ns per
    /// allocation (+2.77%) alloc-only and +4.2 ns (+25.3%) with a free every third request, i.e.
    /// 15-167 us across the whole 180-second run's 6,691 allocations. An instrumented COPY of
    /// o1heap.c (the library file itself unmodified) counted the links the scan skips: ZERO, on all
    /// 13,386 calls. The reason is structural rather than lucky: the scan starts at the charge's own
    /// bin and walks up, every split leftover is binned strictly BELOW the class that produced it, and
    /// o1heapFree() coalesces adjacent free runs, so free space migrates out of the bins the scan
    /// would have to search. O1HEAP_GRANULAR_MAX_HOPS still bounds the pathological case and
    /// `diagnostics.granular_walk_capped` still counts it, because O1HEAP_ASSERT is compiled out under
    /// -DNDEBUG and a property that must be observed at run time has to be observable in the
    /// diagnostics copy.
    void* o1heapAllocateGranular(O1HeapInstance* const handle, const size_t amount, const size_t granularity);

    /// The semantics follows free() with additional guarantees the full list of which is provided below.
    ///
    /// If the pointer does not point to a previously allocated block and is not NULL, the behavior is undefined.
    /// Builds where assertion checks are enabled may trigger an assertion failure for some invalid inputs.
    ///
    /// The function is executed in constant time.
    void o1heapFree(O1HeapInstance* const handle, void* const pointer);

    /// Performs a basic sanity check on the heap.
    /// This function can be used as a weak but fast method of heap corruption detection.
    /// If the handle pointer is NULL, the behavior is undefined.
    /// The time complexity is constant.
    /// The return value is truth if the heap looks valid, falsity otherwise.
    bool o1heapDoInvariantsHold(const O1HeapInstance* const handle);

    /// Samples and returns a copy of the diagnostic information, see O1HeapDiagnostics.
    /// This function merely copies the structure from an internal storage, so it is fast to return.
    /// If the handle pointer is NULL, the behavior is undefined.
    O1HeapDiagnostics o1heapGetDiagnostics(const O1HeapInstance* const handle);

    /// 2026-10-07, ADDED (T43.2). READ-ONLY replay of o1heapAllocateGranular()'s search.
    ///
    /// WHY THE DIAGNOSTICS COPY CANNOT ANSWER THIS. build/w743.log:30954 refuses a 413-byte guest
    /// request with `free=0x22f8000` (34.97 MiB), `bin_mask=0x801c0` and `capped_walks=0`, and
    /// `o1heapDoInvariantsHold` had just passed on the same instance. Those four readings are
    /// mutually fatal: the charge is 0x5000 so the search starts at bin 8; bit 19 is set; the
    /// invariant check this library provides tests exactly `(mask bit i set) == (bins[i] != NULL)`
    /// for all 64 bins, so `bins[19]` was non-NULL; and a fragment binned at 19 is at least
    /// 2^19 * FRAGMENT_SIZE_MIN = 32 MiB, which satisfies a 20 KiB charge. The search therefore
    /// had to succeed, and it returned NULL. Every word of that argument is either read out of this
    /// file or printed by the host -- EXCEPT one: the search decides on `fragment->header.size`,
    /// and no diagnostic in this library reports a fragment's size. `diagnostics.allocated` is a
    /// sum, `nonempty_bin_mask` is a presence bitmap, and `o1heapDoInvariantsHold` never
    /// dereferences a fragment at all. So the one quantity the decision turns on is the one
    /// quantity that is unobservable, and this function exists to observe it.
    ///
    /// WHAT IT REPORTS, and the three outcomes that matter. `found_bin >= 0` means the replay WOULD
    /// have served the request from the state as it now stands, so the allocator's NULL is not
    /// reproducible from that state and the state moved between the call and the reading.
    /// `found_bin < 0` with some `bins[i].head_null == 1` means the mask promises a bin that the
    /// bin array does not hold, i.e. the invariant check did not actually run on this instance.
    /// `found_bin < 0` with every listed bin's `max_size < charge` means a fragment is sitting in a
    /// bin its own size does not belong to -- which is a fragment header that no longer matches the
    /// bin it is linked from, and is the one shape neither the mask nor the invariants can see.
    /// `probe_av` is set by the caller's exception net, not here: walking `next_free` is exactly the
    /// dereference that a corrupt list makes unsafe, so a probe that faults is itself a result.
    ///
    /// This function allocates nothing, writes nothing and changes no diagnostic. It is bounded by
    /// O1HEAP_GRANULAR_MAX_HOPS on the replay and O1HEAP_PROBE_MAX_LINKS per census bin, so a cyclic
    /// list costs a bounded walk and reports `truncated` rather than hanging.
#define O1HEAP_PROBE_MAX_BINS 4
#define O1HEAP_PROBE_MAX_LINKS 4096U

    /// One bin the search would have visited, censused read-only.
    typedef struct
    {
        uint32_t bin;           ///< Bin index.
        uint32_t head_null;     ///< 1 = the mask bit is set but bins[bin] is NULL.
        uint32_t head_used;     ///< bins[bin]->header.used. MUST be 0 in a free list; 1 is corruption.
        uint32_t list_len;      ///< Fragments walked, capped at O1HEAP_PROBE_MAX_LINKS.
        uint32_t truncated;     ///< 1 = the walk stopped on the cap, so list_len is a floor.
        uint32_t n_ge_charge;   ///< Fragments whose size satisfies the charge. 0 here IS the refusal.
        size_t   head_size;     ///< bins[bin]->header.size, the word the search compares against.
        size_t   min_size;      ///< Smallest header.size seen in this bin.
        size_t   max_size;      ///< Largest header.size seen in this bin.
        /// w744 measured `head_size == 0` in BOTH set bins at the refusal, which is structurally
        /// impossible for a binned fragment (FRAGMENT_SIZE_MIN is 64, and `rebin` bins by
        /// log2Floor(size/64)), i.e. the header was overwritten after binning. A size alone cannot
        /// say WHERE, so the whole header is reported: the fragment's own address, which the caller
        /// turns into a guest VA by offset from the arena base, plus `prev`/`next` because a zeroed
        /// `next_free` is what makes `list_len` read 1 no matter how long the list really is.
        size_t   head_addr;     ///< bins[bin] itself, as an integer.
        size_t   head_prev;     ///< bins[bin]->header.prev.
        size_t   head_next;     ///< bins[bin]->next_free, the link the census walk follows.
    } O1HeapProbeBin;

    typedef struct
    {
        size_t   charge;                 ///< The charge the search would use, computed identically.
        uint32_t valid;                  ///< 1 = the probe ran at all; 0 = NULL handle or amount.
        uint32_t granularity_ok;         ///< The shape guards o1heapAllocateGranular applies.
        uint32_t charge_ok;              ///< The capacity/grid guards it applies.
        uint32_t start_bin;              ///< log2Floor(charge / FRAGMENT_SIZE_MIN).
        uint32_t bits_at_or_above_start; ///< Set mask bits the search would consider.
        uint32_t hops;                   ///< Links the replay walked.
        uint32_t cap_would_fire;         ///< 1 = hops reached O1HEAP_GRANULAR_MAX_HOPS.
        int32_t  found_bin;              ///< Bin the replay would serve from; -1 = none.
        size_t   found_size;             ///< That fragment's header.size.
        uint32_t probe_av;               ///< Set by the caller's SEH net: the walk itself faulted.
        uint32_t n_bins;                 ///< Entries in bins[], at most O1HEAP_PROBE_MAX_BINS.
        O1HeapProbeBin bins[O1HEAP_PROBE_MAX_BINS];
    } O1HeapProbeResult;

    void o1heapProbeGranular(const O1HeapInstance* const handle, const size_t amount,
                             const size_t granularity, O1HeapProbeResult* const out);

#ifdef __cplusplus
}
#endif
#endif  // O1HEAP_H_INCLUDED
