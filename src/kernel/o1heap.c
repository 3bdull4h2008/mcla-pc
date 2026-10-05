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

#include "o1heap.h"
#include <assert.h>
#include <limits.h>

// ---------------------------------------- BUILD CONFIGURATION OPTIONS ----------------------------------------

/// Define this macro to include build configuration header. This is an alternative to the -D compiler flag.
/// Usage example with CMake: "-DO1HEAP_CONFIG_HEADER=\"${CMAKE_CURRENT_SOURCE_DIR}/my_o1heap_config.h\""
#ifdef O1HEAP_CONFIG_HEADER
#    include O1HEAP_CONFIG_HEADER
#endif

/// The assertion macro defaults to the standard assert().
/// It can be overridden to manually suppress assertion checks or use a different error handling policy.
#ifndef O1HEAP_ASSERT
// Intentional violation of MISRA: the assertion check macro cannot be replaced with a function definition.
#    define O1HEAP_ASSERT(x) assert(x)  // NOSONAR
#endif

/// Allow usage of compiler intrinsics for branch annotation and CLZ.
#ifndef O1HEAP_USE_INTRINSICS
#    define O1HEAP_USE_INTRINSICS 1
#endif

/// Branch probability annotations are used to improve the worst case execution time (WCET). They are entirely optional.
#if O1HEAP_USE_INTRINSICS && !defined(O1HEAP_LIKELY)
#    if defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM)
// Intentional violation of MISRA: branch hinting macro cannot be replaced with a function definition.
#        define O1HEAP_LIKELY(x) __builtin_expect((x), 1)  // NOSONAR
#    endif
#endif
#ifndef O1HEAP_LIKELY
#    define O1HEAP_LIKELY(x) x
#endif

/// 2026-09-30, ADDED for o1heapAllocateGranular: the mirror of O1HEAP_LIKELY, for the one branch in
/// that function that reports corruption rather than normal flow. It has no configuration block of
/// its own; when the compiler offers no branch hint, both hints degrade to the identity, which is
/// exactly the behaviour of O1HEAP_LIKELY without intrinsics.
#ifndef O1HEAP_UNLIKELY
#    if defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM)
// Intentional violation of MISRA: branch hinting macro cannot be replaced with a function definition.
#        define O1HEAP_UNLIKELY(x) __builtin_expect((x), 0)  // NOSONAR
#    else
#        define O1HEAP_UNLIKELY(x) x
#    endif
#endif

/// This option is used for testing only. Do not use in production.
#ifndef O1HEAP_PRIVATE
#    define O1HEAP_PRIVATE static inline
#endif

/// Count leading zeros (CLZ) is used for fast computation of binary logarithm (which needs to be done very often).
/// Most of the modern processors (including the embedded ones) implement dedicated hardware support for fast CLZ
/// computation, which is available via compiler intrinsics. The default implementation will automatically use
/// the intrinsics for some of the compilers; for others it will default to the slow software emulation,
/// which can be overridden by the user via O1HEAP_CONFIG_HEADER. The library guarantees that the argument is positive.
#if O1HEAP_USE_INTRINSICS && !defined(O1HEAP_CLZ)
#    if defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM)
#        if SIZE_MAX == 0xFFFFFFFFFFFFFFFF
#            define O1HEAP_CLZ __builtin_clzll
#        else
#            define O1HEAP_CLZ __builtin_clzl
#        endif
#    endif
#endif
#ifndef O1HEAP_CLZ
O1HEAP_PRIVATE uint_fast8_t O1HEAP_CLZ(const size_t x)
{
    O1HEAP_ASSERT(x > 0);
    size_t       t = ((size_t)1U) << ((sizeof(size_t) * CHAR_BIT) - 1U);
    uint_fast8_t r = 0;
    while ((x & t) == 0)
    {
        t >>= 1U;
        r++;
    }
    return r;
}
#endif

// ---------------------------------------- INTERNAL DEFINITIONS ----------------------------------------

#if __STDC_VERSION__ < 201112L
// Intentional violation of MISRA: static assertion macro cannot be replaced with a function definition.
#    define static_assert(x, ...) typedef char _static_assert_gl(_static_assertion_, __LINE__)[(x) ? 1 : -1]  // NOSONAR
#    define _static_assert_gl(a, b) _static_assert_gl_impl(a, b)                                              // NOSONAR
// Intentional violation of MISRA: the paste operator ## cannot be avoided in this context.
#    define _static_assert_gl_impl(a, b) a##b  // NOSONAR
#endif

/// The overhead is at most O1HEAP_ALIGNMENT bytes large,
/// then follows the user data which shall keep the next fragment aligned.
#define FRAGMENT_SIZE_MIN (O1HEAP_ALIGNMENT * 2U)

/// This is risky, handle with care: if the allocation amount plus per-fragment overhead exceeds 2**(b-1),
/// where b is the pointer bit width, then ceil(log2(amount)) yields b; then 2**b causes an integer overflow.
/// To avoid this, we put a hard limit on fragment size (which is amount + per-fragment overhead): 2**(b-1)
#define FRAGMENT_SIZE_MAX ((SIZE_MAX >> 1U) + 1U)

/// Normally we should subtract log2(FRAGMENT_SIZE_MIN) but log2 is bulky to compute using the preprocessor only.
/// We will certainly end up with unused bins this way, but it is cheap to ignore.
#define NUM_BINS_MAX (sizeof(size_t) * CHAR_BIT)

/// 2026-09-30, ADDED for o1heapAllocateGranular: the hard bound on how many free-list links the
/// fixed-granularity search will follow before it gives up and reports failure. The search is the only
/// place in this file that walks a list instead of taking a bin head, so it is the only place a
/// cyclic list could spin forever; the bound turns that into a refusal, which is the same failure the
/// caller already handles, and bumps diagnostics.granular_walk_capped so the anomaly is countable.
/// 4096 free fragments of at least FRAGMENT_SIZE_MIN (64) bytes each is 256 KiB; a real arena holds
/// far more than that, but it holds them in FEWER classes than this, and the search starts at the
/// class it needs rather than at the smallest.
#define O1HEAP_GRANULAR_MAX_HOPS (4096U)

static_assert((O1HEAP_ALIGNMENT& (O1HEAP_ALIGNMENT - 1U)) == 0U, "Not a power of 2");
static_assert((FRAGMENT_SIZE_MIN& (FRAGMENT_SIZE_MIN - 1U)) == 0U, "Not a power of 2");
static_assert((FRAGMENT_SIZE_MAX& (FRAGMENT_SIZE_MAX - 1U)) == 0U, "Not a power of 2");

typedef struct Fragment Fragment;

typedef struct FragmentHeader
{
    Fragment* next;
    Fragment* prev;
    size_t    size;
    bool      used;
} FragmentHeader;
static_assert(sizeof(FragmentHeader) <= O1HEAP_ALIGNMENT, "Memory layout error");

struct Fragment
{
    FragmentHeader header;
    // Everything past the header may spill over into the allocatable space. The header survives across alloc/free.
    Fragment* next_free;  // Next free fragment in the bin; NULL in the last one.
    Fragment* prev_free;  // Same but points back; NULL in the first one.
};
static_assert(sizeof(Fragment) <= FRAGMENT_SIZE_MIN, "Memory layout error");

struct O1HeapInstance
{
    Fragment* bins[NUM_BINS_MAX];  ///< Smallest fragments are in the bin at index 0.
    size_t    nonempty_bin_mask;   ///< Bit 1 represents a non-empty bin; bin at index 0 is for the smallest fragments.

    O1HeapDiagnostics diagnostics;
};

/// The amount of space allocated for the heap instance.
/// Its size is padded up to O1HEAP_ALIGNMENT to ensure correct alignment of the allocation arena that follows.
#define INSTANCE_SIZE_PADDED ((sizeof(O1HeapInstance) + O1HEAP_ALIGNMENT - 1U) & ~(O1HEAP_ALIGNMENT - 1U))

static_assert(INSTANCE_SIZE_PADDED >= sizeof(O1HeapInstance), "Invalid instance footprint computation");
static_assert((INSTANCE_SIZE_PADDED% O1HEAP_ALIGNMENT) == 0U, "Invalid instance footprint computation");

/// 2026-09-30, ADDED. A COMPILE-TIME guard for a layout other translation units read by hand.
/// `granular_walk_capped` was appended to O1HeapDiagnostics (o1heap.h), which takes the instance from
/// 0x230 to 0x238 bytes -- and 0x238 still PADS to 0x240, so INSTANCE_SIZE_PADDED, and therefore the
/// arena layout, is unchanged. That is a coincidence of the 32-byte alignment, not a property, and it
/// is load-bearing: the host reads `nonempty_bin_mask` at instance+0x200 and `diagnostics.capacity` at
/// instance+0x208 by hardcoded offset (src/kernel/heap.cpp, `kO1BinMaskOffset` and CheckHeapHeader),
/// and the boot host's own note records the instance as "0x230 bytes padded to 0x240". A future field
/// that crossed 0x240 would move BOTH offsets by 32 bytes with no runtime symptom this file could
/// see, so the value is pinned here where the padding is computed. O1HEAP_ASSERT is unusable for this:
/// -DNDEBUG removes it, and this is a build-time property of the type layout anyway.
static_assert(INSTANCE_SIZE_PADDED == 0x240U,
              "The host reads this instance at hardcoded offsets (mask +0x200, capacity +0x208). "
              "Changing the instance size past 0x240 moves them; update the host offsets too.");

/// Undefined for zero argument.
O1HEAP_PRIVATE uint_fast8_t log2Floor(const size_t x)
{
    O1HEAP_ASSERT(x > 0);
    // NOLINTNEXTLINE redundant cast to the same type.
    return (uint_fast8_t)(((sizeof(x) * CHAR_BIT) - 1U) - ((uint_fast8_t)O1HEAP_CLZ(x)));
}

/// Special case: if the argument is zero, returns zero.
O1HEAP_PRIVATE uint_fast8_t log2Ceil(const size_t x)
{
    // NOLINTNEXTLINE redundant cast to the same type.
    return (x <= 1U) ? 0U : (uint_fast8_t)((sizeof(x) * CHAR_BIT) - ((uint_fast8_t)O1HEAP_CLZ(x - 1U)));
}

/// Raise 2 into the specified power.
/// You might be tempted to do something like (1U << power). WRONG! We humans are prone to forgetting things.
/// If you forget to cast your 1U to size_t or ULL, you may end up with undefined behavior.
O1HEAP_PRIVATE size_t pow2(const uint_fast8_t power)
{
    return ((size_t)1U) << power;
}

/// This is equivalent to pow2(log2Ceil(x)). Undefined for x<2.
O1HEAP_PRIVATE size_t roundUpToPowerOf2(const size_t x)
{
    O1HEAP_ASSERT(x >= 2U);
    // NOLINTNEXTLINE redundant cast to the same type.
    return ((size_t)1U) << ((sizeof(x) * CHAR_BIT) - ((uint_fast8_t)O1HEAP_CLZ(x - 1U)));
}

/// Links two fragments so that their next/prev pointers point to each other; left goes before right.
O1HEAP_PRIVATE void interlink(Fragment* const left, Fragment* const right)
{
    if (O1HEAP_LIKELY(left != NULL))
    {
        left->header.next = right;
    }
    if (O1HEAP_LIKELY(right != NULL))
    {
        right->header.prev = left;
    }
}

/// Adds a new fragment into the appropriate bin and updates the lookup mask.
O1HEAP_PRIVATE void rebin(O1HeapInstance* const handle, Fragment* const fragment)
{
    O1HEAP_ASSERT(handle != NULL);
    O1HEAP_ASSERT(fragment != NULL);
    O1HEAP_ASSERT(fragment->header.size >= FRAGMENT_SIZE_MIN);
    O1HEAP_ASSERT((fragment->header.size % FRAGMENT_SIZE_MIN) == 0U);
    const uint_fast8_t idx = log2Floor(fragment->header.size / FRAGMENT_SIZE_MIN);  // Round DOWN when inserting.
    O1HEAP_ASSERT(idx < NUM_BINS_MAX);
    // Add the new fragment to the beginning of the bin list.
    // I.e., each allocation will be returning the most-recently-used fragment -- good for caching.
    fragment->next_free = handle->bins[idx];
    fragment->prev_free = NULL;
    if (O1HEAP_LIKELY(handle->bins[idx] != NULL))
    {
        handle->bins[idx]->prev_free = fragment;
    }
    handle->bins[idx] = fragment;
    handle->nonempty_bin_mask |= pow2(idx);
}

/// Removes the specified fragment from its bin.
O1HEAP_PRIVATE void unbin(O1HeapInstance* const handle, const Fragment* const fragment)
{
    O1HEAP_ASSERT(handle != NULL);
    O1HEAP_ASSERT(fragment != NULL);
    O1HEAP_ASSERT(fragment->header.size >= FRAGMENT_SIZE_MIN);
    O1HEAP_ASSERT((fragment->header.size % FRAGMENT_SIZE_MIN) == 0U);
    const uint_fast8_t idx = log2Floor(fragment->header.size / FRAGMENT_SIZE_MIN);  // Round DOWN when removing.
    O1HEAP_ASSERT(idx < NUM_BINS_MAX);
    // Remove the bin from the free fragment list.
    if (O1HEAP_LIKELY(fragment->next_free != NULL))
    {
        fragment->next_free->prev_free = fragment->prev_free;
    }
    if (O1HEAP_LIKELY(fragment->prev_free != NULL))
    {
        fragment->prev_free->next_free = fragment->next_free;
    }
    // Update the bin header.
    if (O1HEAP_LIKELY(handle->bins[idx] == fragment))
    {
        O1HEAP_ASSERT(fragment->prev_free == NULL);
        handle->bins[idx] = fragment->next_free;
        if (O1HEAP_LIKELY(handle->bins[idx] == NULL))
        {
            handle->nonempty_bin_mask &= ~pow2(idx);
        }
    }
}

// ---------------------------------------- PUBLIC API IMPLEMENTATION ----------------------------------------

O1HeapInstance* o1heapInit(void* const base, const size_t size)
{
    O1HeapInstance* out = NULL;
    if ((base != NULL) && ((((size_t)base) % O1HEAP_ALIGNMENT) == 0U) &&
        (size >= (INSTANCE_SIZE_PADDED + FRAGMENT_SIZE_MIN)))
    {
        // Allocate the core heap metadata structure in the beginning of the arena.
        O1HEAP_ASSERT(((size_t)base) % sizeof(O1HeapInstance*) == 0U);
        out = (O1HeapInstance*)base;
        out->nonempty_bin_mask = 0U;
        for (size_t i = 0; i < NUM_BINS_MAX; i++)
        {
            out->bins[i] = NULL;
        }

        // Limit and align the capacity.
        size_t capacity = size - INSTANCE_SIZE_PADDED;
        if (capacity > FRAGMENT_SIZE_MAX)
        {
            capacity = FRAGMENT_SIZE_MAX;
        }
        while ((capacity % FRAGMENT_SIZE_MIN) != 0)
        {
            O1HEAP_ASSERT(capacity > 0U);
            capacity--;
        }
        O1HEAP_ASSERT((capacity % FRAGMENT_SIZE_MIN) == 0);
        O1HEAP_ASSERT((capacity >= FRAGMENT_SIZE_MIN) && (capacity <= FRAGMENT_SIZE_MAX));

        // Initialize the root fragment.
        Fragment* const frag = (Fragment*)(void*)(((char*)base) + INSTANCE_SIZE_PADDED);
        O1HEAP_ASSERT((((size_t)frag) % O1HEAP_ALIGNMENT) == 0U);
        frag->header.next = NULL;
        frag->header.prev = NULL;
        frag->header.size = capacity;
        frag->header.used = false;
        frag->next_free = NULL;
        frag->prev_free = NULL;
        rebin(out, frag);
        O1HEAP_ASSERT(out->nonempty_bin_mask != 0U);

        // Initialize the diagnostics.
        out->diagnostics.capacity = capacity;
        out->diagnostics.allocated = 0U;
        out->diagnostics.peak_allocated = 0U;
        out->diagnostics.peak_request_size = 0U;
        out->diagnostics.oom_count = 0U;
        out->diagnostics.granular_walk_capped = 0U;   // 2026-09-30: see O1HeapDiagnostics in o1heap.h.
    }
    return out;
}

void* o1heapAllocate(O1HeapInstance* const handle, const size_t amount)
{
    O1HEAP_ASSERT(handle != NULL);
    O1HEAP_ASSERT(handle->diagnostics.capacity <= FRAGMENT_SIZE_MAX);
    void* out = NULL;

    // If the amount approaches approx. SIZE_MAX/2, an undetected integer overflow may occur.
    // To avoid that, we do not attempt allocation if the amount exceeds the hard limit.
    // We perform multiple redundant checks to account for a possible unaccounted overflow.
    if (O1HEAP_LIKELY((amount > 0U) && (amount <= (handle->diagnostics.capacity - O1HEAP_ALIGNMENT))))
    {
        // Add the header size and align the allocation size to the power of 2.
        // See "Timing-Predictable Memory Allocation In Hard Real-Time Systems", Herter, page 27.
        //
        // 2026-09-30 (measurement note, NO behaviour change). This is the only place in the library
        // where a byte can be multiplied: `amount` already carries the caller's own header, so the
        // per-fragment overhead IS folded into the rounded quantity, and a request that sits within
        // 32 B below a power of two pays a whole extra factor of two. It was measured against
        // build/w661.log and the term turned out to be worth nothing on this workload, so the
        // rounding stays. The arithmetic, so that the next reader does not re-derive it:
        //   * charged = roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT) = roundUpToPowerOf2(2^k) for
        //     amount in (2^(k-1) - 32, 2^(k-1)], hence the overhead is amplified by up to 2x;
        //   * decomposition, charged = P + R with P = roundUpToPowerOf2(amount) and
        //     R = charged - P, which is non-zero ONLY when a power of two lies in (amount, amount+32];
        //   * over the 181 physical-arena rows of w661.log that carry a class (`PHYS-STATE o1_frag`
        //     and the refusal rows, both reproduced exactly by this expression, 0 mismatches), R is
        //     non-zero on 145 rows and every one of them is amount == 0x31 (a 1-byte caller request,
        //     charged 0x80). That 0x80 is NOT recoverable: the caller pointer is frag+32, so
        //     amount + 32 = 81 forces 128 on a 64-byte grid whatever the rounding does. On all 36
        //     rows above the 1-byte class R is exactly 0.
        //   * so the whole of the run's 405.9 MB of footprint over request (1169.1 / 763.2 = 1.53x)
        //     is the power-of-two rounding of the PAYLOAD, which is irreducible without giving up
        //     the constant-time bin lookup; the recoverable share of the folded overhead is bounded
        //     by 32 B * nalloc = 2.4 MB (0.6 % of 405.9 MB) and measured 0 on every large class.
        // If a future log ever shows a dominant R, the fix is to round `amount` and add the
        // overhead afterwards; that keeps every other invariant in this file (FRAGMENT_SIZE_MIN
        // multiples, log2Ceil/log2Floor bin indices, the leftover split) intact, because both
        // operands stay multiples of 64.
        const size_t fragment_size = roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT);
        O1HEAP_ASSERT(fragment_size <= FRAGMENT_SIZE_MAX);
        O1HEAP_ASSERT(fragment_size >= FRAGMENT_SIZE_MIN);
        O1HEAP_ASSERT(fragment_size >= amount + O1HEAP_ALIGNMENT);
        O1HEAP_ASSERT((fragment_size & (fragment_size - 1U)) == 0U);  // Is power of 2.

        const uint_fast8_t optimal_bin_index = log2Ceil(fragment_size / FRAGMENT_SIZE_MIN);  // Use CEIL when fetching.
        O1HEAP_ASSERT(optimal_bin_index < NUM_BINS_MAX);
        const size_t candidate_bin_mask = ~(pow2(optimal_bin_index) - 1U);

        // Find the smallest non-empty bin we can use.
        const size_t suitable_bins = handle->nonempty_bin_mask & candidate_bin_mask;
        const size_t smallest_bin_mask = suitable_bins & ~(suitable_bins - 1U);  // Clear all bits but the lowest.
        if (O1HEAP_LIKELY(smallest_bin_mask != 0))
        {
            O1HEAP_ASSERT((smallest_bin_mask & (smallest_bin_mask - 1U)) == 0U);  // Is power of 2.
            const uint_fast8_t bin_index = log2Floor(smallest_bin_mask);
            O1HEAP_ASSERT(bin_index >= optimal_bin_index);
            O1HEAP_ASSERT(bin_index < NUM_BINS_MAX);

            // The bin we found shall not be empty, otherwise it's a state divergence (memory corruption?).
            Fragment* const frag = handle->bins[bin_index];
            O1HEAP_ASSERT(frag != NULL);
            O1HEAP_ASSERT(frag->header.size >= fragment_size);
            O1HEAP_ASSERT((frag->header.size % FRAGMENT_SIZE_MIN) == 0U);
            O1HEAP_ASSERT(!frag->header.used);
            unbin(handle, frag);

            // Split the fragment if it is too large.
            const size_t leftover = frag->header.size - fragment_size;
            frag->header.size = fragment_size;
            O1HEAP_ASSERT(leftover < handle->diagnostics.capacity);  // Overflow check.
            O1HEAP_ASSERT(leftover % FRAGMENT_SIZE_MIN == 0U);       // Alignment check.
            if (O1HEAP_LIKELY(leftover >= FRAGMENT_SIZE_MIN))
            {
                Fragment* const new_frag = (Fragment*)(void*)(((char*)frag) + fragment_size);
                O1HEAP_ASSERT(((size_t)new_frag) % O1HEAP_ALIGNMENT == 0U);
                new_frag->header.size = leftover;
                new_frag->header.used = false;
                interlink(new_frag, frag->header.next);
                interlink(frag, new_frag);
                rebin(handle, new_frag);
            }

            // Update the diagnostics.
            O1HEAP_ASSERT((handle->diagnostics.allocated % FRAGMENT_SIZE_MIN) == 0U);
            handle->diagnostics.allocated += fragment_size;
            O1HEAP_ASSERT(handle->diagnostics.allocated <= handle->diagnostics.capacity);
            if (O1HEAP_LIKELY(handle->diagnostics.peak_allocated < handle->diagnostics.allocated))
            {
                handle->diagnostics.peak_allocated = handle->diagnostics.allocated;
            }

            // Finalize the fragment we just allocated.
            O1HEAP_ASSERT(frag->header.size >= amount + O1HEAP_ALIGNMENT);
            frag->header.used = true;

            out = ((char*)frag) + O1HEAP_ALIGNMENT;
        }
    }

    // Update the diagnostics.
    if (O1HEAP_LIKELY(handle->diagnostics.peak_request_size < amount))
    {
        handle->diagnostics.peak_request_size = amount;
    }
    if (O1HEAP_LIKELY((out == NULL) && (amount > 0U)))
    {
        handle->diagnostics.oom_count++;
    }

    return out;
}

// 2026-09-30 (F-641, ADDITIVE: no existing function in this file is modified). THE DEFECT THIS EXISTS
// TO FIX, measured in build/w665.log and not inferred: with a 512 MiB physical pool (o1heap capacity
// 0x1FFFFDC0 = 512 MiB - 0x240 of instance padding), a request of 0x12B80030 -- 299.5 MiB, legal, and
// SMALLER than the 431.9 MiB that were free -- was REFUSED. The charge was
// `roundUpToPowerOf2(0x12B80030 + 32) = 0x20000000` = 512.0 MiB, i.e. 576 bytes MORE than the entire
// arena, so no free run could ever satisfy it: `o1_frag=0x20000000 class_ok=0 suitable=0x0
// bin_mask=0x400000 free=0x1afffdc0`. One free run of 0x1AFFFDC0 was present and the allocator could
// not address it. `over_cap=1` on the PHYS-POOL-FULL row, then
// `'ExternalAllocator - Out of virtual memory'` and the fatal dispatcher.
//
// WHY THE POWER-OF-TWO CLASS IS NOT FAITHFUL FOR THE CONSOLE'S PHYSICAL POOL. The console's kernel
// does not bin; it rounds the region to the PAGE size and then scans a per-page table.
//   * MmAllocatePhysicalMemoryEx_entry picks page_size = 4 KiB by default (64 KiB for
//     X_MEM_LARGE_PAGES, 16 MiB for X_MEM_16MB_PAGES) and rounds the region and the alignment to it:
//     `adjusted_size = xe::round_up(region_size, page_size)`
//     (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_memory.cc:364) and
//     `adjusted_alignment = xe::round_up(alignment, page_size)` (same file:365), then calls
//     `PhysicalHeap::AllocRange` (same file:383).
//   * PhysicalHeap::AllocRange re-rounds to its own page size and delegates
//     (.research/xenia/src/xenia/memory.cc:1466, size rounded at :1473, delegation at :1484).
//   * BaseHeap::AllocRange converts the size to a PAGE COUNT (`get_page_count(size, page_size_)`,
//     memory.cc:924) and the only size precondition anywhere in the chain is
//     `page_count > (high_page_number - low_page_number)` (memory.cc:934); the search is a linear
//     top-down scan of `page_table_` for that many consecutive free pages (memory.cc:949-988).
//     `page_table_` is a `std::vector<PageEntry>`, one entry per page (memory.h:210).
// So the console charges `round_up(region_size, 4096)` and knows no size CLASS. For the 0x12B80000
// region it charges 0x12B80000 = 299.5 MiB against a servable pool of 0x1FFF0000 = 511.9 MiB
// (0x20000000, memory.cc:171-172, less the 0x10000 reserved at the top, memory.cc:188-189), needing
// 76416 of the 131072 pages. o1heap charged 0x20000000. The gap is 222,806,192 bytes of padding the
// console never asks for.
//
// WHAT THIS FUNCTION IS, PRECISELY: the reference's sizing rule (round to the granularity) expressed
// over THIS file's fragment structures, so that a large block is indistinguishable to every existing
// consumer -- a 32-byte-aligned user pointer, a header at -32, a size that is a multiple of
// FRAGMENT_SIZE_MIN, address-list links maintained by interlink(), and a release through the
// unmodified o1heapFree(). Nothing else changes: o1heapAllocate(), o1heapFree(), o1heapInit() and
// o1heapDoInvariantsHold() are untouched, so the USER arena -- the title's own o1dev heap, whose
// power-of-two classes are the contract -- keeps exactly the behaviour three streams built on today.
// 2026-09-30 (F-642, ADDITIVE: no statement in this file is modified). THE THRESHOLD THAT GOVERNS
// WHICH CALLER REACHES o1heapAllocateGranular IS GONE, and that changes how this file's one
// non-constant-time function is to be read, so the note belongs here and not only in the header.
//
// WHAT WAS TRUE BEFORE. The caller routed only the requests o1heap could not serve -- "unservable at
// every occupancy" -- which is a statement about the power-of-two class exceeding the whole arena. It
// is true, and it is narrower than the defect. A request can be perfectly servable and still charge
// twice what it needs, and on a pool that backs guest page mappings those charges add up: the console's
// 512 MiB pool reached 536,545,408 of its 536,870,336 bytes (99.94%) across 6,691 requests and then
// refused a 256 KiB request whose power-of-two class was 512 KiB while 324,928 bytes were already
// free. Rounding the same request to a page charges 270,336 B, which fitted. The rounding, not the
// guest, spent the pool.
//
// WHAT IS TRUE NOW, AND WHY IT IS A PROPERTY OF THE ALLOCATOR RATHER THAN A NUMBER. This file has
// exactly two sizing rules and no third: a fragment is either `roundUpToPowerOf2(amount +
// O1HEAP_ALIGNMENT)` bytes or a whole number of `granularity` bytes. There is no request for which a
// size class could pick the cheaper of the two in a way the page rule does not already take, because
// the two rules never tie on a request whose charge is a whole number of pages: the page rule is then
// never worse by more than granule-1 and is usually strictly better, which measured 1.5130x fewer
// charged bytes over the request sizes recorded in build/w672.log. So there is nothing for a threshold
// to select between, and the physical pool now uses the page rule throughout.
//
// THE PRICE, MEASURED RATHER THAN ASSUMED, because this is the only function in the file that WALKS a
// free list instead of taking a bin head and the distinction is the whole reason it existed. Against
// a 512 MiB arena, replaying w672's own request sequence: +24.9 ns per allocation (+2.77%) alloc-only,
// +4.2 ns (+25.3%) with a free every third request -- 15 to 167 microseconds across the entire run.
// An instrumented COPY of this file, made in a temp directory with the repository file untouched,
// counted the links the scan skips and found ZERO on all 13,386 calls, with `granular_walk_capped`
// at 0 throughout. That is not luck: the scan starts at the charge's own bin and walks up, `rebin`
// bins every split leftover by its OWN size and a leftover is always strictly smaller than the class
// that produced it, and o1heapFree coalesces every run it touches. Free space migrates DOWN the
// ladder and out of the bins the scan would have to search.
//
// NOTHING ELSE HERE CHANGES. o1heapAllocate, o1heapFree, o1heapInit, o1heapDoInvariantsHold,
// O1HEAP_GRANULAR_MAX_HOPS and the diagnostics layout are all untouched, and the instance size is
// still pinned by the static_assert on INSTANCE_SIZE_PADDED above. The user's heap -- the title's own
// arena, whose power-of-two classes are a contract three streams measured 181 rows against -- is not
// routed here at all and never was; only the page-backed physical pool is.
void* o1heapAllocateGranular(O1HeapInstance* const handle, const size_t amount, const size_t granularity)
{
    O1HEAP_ASSERT(handle != NULL);
    O1HEAP_ASSERT(handle->diagnostics.capacity <= FRAGMENT_SIZE_MAX);
    O1HEAP_ASSERT(granularity >= FRAGMENT_SIZE_MIN);
    O1HEAP_ASSERT(granularity <= (SIZE_MAX / 2U));
    void* out = NULL;

    // REJECTED SHAPES ARE REFUSED, NOT ASSERTED. This file is compiled with -DNDEBUG on the mcla
    // target, so every O1HEAP_ASSERT above is compiled out and a bad shape would otherwise be
    // rounded into a charge that no other operation in the file can describe. The granularity must
    // therefore be checked BY VALUE: a power of two (so the charge is a whole number of cells) and a
    // multiple of FRAGMENT_SIZE_MIN (so the arena grid is preserved). The overflow bound on the
    // addition is checked here for the same reason, and is the reason `granularity` is capped at
    // SIZE_MAX/2 above: `amount + O1HEAP_ALIGNMENT + granularity - 1` is computed below and must
    // not wrap.
    const bool granularity_ok = (granularity >= FRAGMENT_SIZE_MIN) && (granularity <= (SIZE_MAX / 2U)) &&
        ((granularity & (granularity - 1U)) == 0U) && ((granularity % FRAGMENT_SIZE_MIN) == 0U);
    const bool amount_ok = (amount > 0U) && (amount <= (SIZE_MAX - O1HEAP_ALIGNMENT));
    if (O1HEAP_LIKELY(granularity_ok && amount_ok))
    {
        // The charge is the request plus the per-fragment header, rounded to the granularity. This
        // mirrors o1heapAllocate()'s `amount + O1HEAP_ALIGNMENT` term for term and replaces ONLY
        // the rounding function, so the request/charge pair a census reports is the same pair the
        // power-of-two path reports and the two subtract cleanly against each other.
        const size_t charge = (((amount + O1HEAP_ALIGNMENT) + granularity - 1U) / granularity) * granularity;

        // The charge is refused unless it is on the arena grid and the whole arena can hold it.
        // `charge > capacity` is the case o1heap could not express at all, and it is also the only
        // case in which this function must not touch a fragment.
        if (O1HEAP_LIKELY((charge <= handle->diagnostics.capacity) && (charge >= FRAGMENT_SIZE_MIN) &&
                          ((charge % FRAGMENT_SIZE_MIN) == 0U)))
        {
            // FIND A RUN. The bin index alone is not sufficient and using it as if it were is the
            // classic way to hand out a fragment smaller than the request: `rebin` rounds DOWN, so
            // the lowest bin that could hold the charge also holds fragments BELOW it. So the
            // candidate is the first node whose own `size` is at least the charge, scanning bins
            // from the charge's own class upwards. Lowest-class-first is the same anti-fragmentation
            // choice o1heapAllocate() makes when it clears all but the lowest set bit of
            // `suitable_bins`, and it is why a large leftover is not consumed by small work later.
            Fragment* frag = NULL;
            uint32_t   hops = 0U;
            for (uint_fast8_t idx = log2Floor(charge / FRAGMENT_SIZE_MIN);
                 (idx < NUM_BINS_MAX) && (frag == NULL); idx++)
            {
                if ((handle->nonempty_bin_mask & pow2(idx)) == 0U)
                {
                    continue;
                }
                Fragment* f = handle->bins[idx];
                while ((f != NULL) && (f->header.size < charge) && (hops < O1HEAP_GRANULAR_MAX_HOPS))
                {
                    f = f->next_free;
                    hops++;
                }
                if (O1HEAP_LIKELY(f != NULL) && (f->header.size >= charge))
                {
                    frag = f;
                }
            }
            if (O1HEAP_UNLIKELY(hops >= O1HEAP_GRANULAR_MAX_HOPS))
            {
                // A free list that cannot be walked to its end is corrupt. Refuse rather than spin,
                // and make the refusal distinguishable from an ordinary out-of-memory one: the caller
                // reads granular_walk_capped out of the diagnostics copy and counts it.
                handle->diagnostics.granular_walk_capped++;
                frag = NULL;
            }

            if (O1HEAP_LIKELY(frag != NULL))
            {
                unbin(handle, frag);

                // Split. The leftover is binned by its OWN size like any other free fragment, so its
                // class may be ABOVE the charge's class -- a shape the power-of-two path cannot
                // produce, and a legal one: re-bin only requires the size to be a multiple of
                // FRAGMENT_SIZE_MIN, which `charge` is and therefore `leftover` is too. When there is
                // no room for a leftover (`leftover < FRAGMENT_SIZE_MIN`) no fragment is created and
                // `frag->header.next` is left pointing at the old neighbour, which is correct: that
                // link is the ADDRESS list, maintained by interlink() across used and free fragments
                // alike, and o1heapFree() relies on it. Nothing is stolen either way.
                const size_t leftover = frag->header.size - charge;
                frag->header.size = charge;
                if (O1HEAP_LIKELY(leftover >= FRAGMENT_SIZE_MIN))
                {
                    Fragment* const new_frag = (Fragment*)(void*)(((char*)frag) + charge);
                    new_frag->header.size = leftover;
                    new_frag->header.used = false;
                    interlink(new_frag, frag->header.next);
                    interlink(frag, new_frag);
                    rebin(handle, new_frag);
                }

                // Diagnostics, in the same order and with the same terms as o1heapAllocate() so that
                // `allocated`, `peak_allocated` and the fragmentation readings in the host's census
                // mean the same thing whichever path served the request. Both are multiples of
                // FRAGMENT_SIZE_MIN by construction, which is what
                // `(allocated % FRAGMENT_SIZE_MIN) == 0U` in o1heapDoInvariantsHold() requires.
                handle->diagnostics.allocated += charge;
                if (O1HEAP_LIKELY(handle->diagnostics.peak_allocated < handle->diagnostics.allocated))
                {
                    handle->diagnostics.peak_allocated = handle->diagnostics.allocated;
                }

                // Finalize the fragment we just allocated. The header survives across alloc/free, so
                // this is the only state o1heapFree() reads to decide that the block is live.
                frag->header.used = true;

                out = ((char*)frag) + O1HEAP_ALIGNMENT;
            }
        }
    }

    // Diagnostics on the way out, identical to o1heapAllocate()'s, including `peak_request_size`
    // and `oom_count`. A refusal through this path is therefore counted as a refusal by every
    // existing census and cannot be mistaken for a served request.
    if (O1HEAP_LIKELY(handle->diagnostics.peak_request_size < amount))
    {
        handle->diagnostics.peak_request_size = amount;
    }
    if (O1HEAP_LIKELY((out == NULL) && (amount > 0U)))
    {
        handle->diagnostics.oom_count++;
    }

    return out;
}

void o1heapFree(O1HeapInstance* const handle, void* const pointer)
{
    O1HEAP_ASSERT(handle != NULL);
    O1HEAP_ASSERT(handle->diagnostics.capacity <= FRAGMENT_SIZE_MAX);
    if (O1HEAP_LIKELY(pointer != NULL))  // NULL pointer is a no-op.
    {
        Fragment* const frag = (Fragment*)(void*)(((char*)pointer) - O1HEAP_ALIGNMENT);

        // Check for heap corruption in debug builds.
        O1HEAP_ASSERT(((size_t)frag) % sizeof(Fragment*) == 0U);
        O1HEAP_ASSERT(((size_t)frag) >= (((size_t)handle) + INSTANCE_SIZE_PADDED));
        O1HEAP_ASSERT(((size_t)frag) <=
            (((size_t)handle) + INSTANCE_SIZE_PADDED + handle->diagnostics.capacity - FRAGMENT_SIZE_MIN));
        O1HEAP_ASSERT(frag->header.used);  // Catch double-free
        O1HEAP_ASSERT(((size_t)frag->header.next) % sizeof(Fragment*) == 0U);
        O1HEAP_ASSERT(((size_t)frag->header.prev) % sizeof(Fragment*) == 0U);
        O1HEAP_ASSERT(frag->header.size >= FRAGMENT_SIZE_MIN);
        O1HEAP_ASSERT(frag->header.size <= handle->diagnostics.capacity);
        O1HEAP_ASSERT((frag->header.size % FRAGMENT_SIZE_MIN) == 0U);

        // Even if we're going to drop the fragment later, mark it free anyway to prevent double-free.
        frag->header.used = false;

        // Update the diagnostics. It must be done before merging because it invalidates the fragment size information.
        O1HEAP_ASSERT(handle->diagnostics.allocated >= frag->header.size);  // Heap corruption check.
        handle->diagnostics.allocated -= frag->header.size;

        // Merge with siblings and insert the returned fragment into the appropriate bin and update metadata.
        Fragment* const prev = frag->header.prev;
        Fragment* const next = frag->header.next;
        const bool      join_left = (prev != NULL) && (!prev->header.used);
        const bool      join_right = (next != NULL) && (!next->header.used);
        if (join_left && join_right)  // [ prev ][ this ][ next ] => [ ------- prev ------- ]
        {
            unbin(handle, prev);
            unbin(handle, next);
            prev->header.size += frag->header.size + next->header.size;
            frag->header.size = 0;  // Invalidate the dropped fragment headers to prevent double-free.
            next->header.size = 0;
            O1HEAP_ASSERT((prev->header.size % FRAGMENT_SIZE_MIN) == 0U);
            interlink(prev, next->header.next);
            rebin(handle, prev);
        }
        else if (join_left)  // [ prev ][ this ][ next ] => [ --- prev --- ][ next ]
        {
            unbin(handle, prev);
            prev->header.size += frag->header.size;
            frag->header.size = 0;
            O1HEAP_ASSERT((prev->header.size % FRAGMENT_SIZE_MIN) == 0U);
            interlink(prev, next);
            rebin(handle, prev);
        }
        else if (join_right)  // [ prev ][ this ][ next ] => [ prev ][ --- this --- ]
        {
            unbin(handle, next);
            frag->header.size += next->header.size;
            next->header.size = 0;
            O1HEAP_ASSERT((frag->header.size % FRAGMENT_SIZE_MIN) == 0U);
            interlink(frag, next->header.next);
            rebin(handle, frag);
        }
        else
        {
            rebin(handle, frag);
        }
    }
}

bool o1heapDoInvariantsHold(const O1HeapInstance* const handle)
{
    O1HEAP_ASSERT(handle != NULL);
    bool valid = true;

    // Check the bin mask consistency.
    for (size_t i = 0; i < NUM_BINS_MAX; i++)  // Dear compiler, feel free to unroll this loop.
    {
        const bool mask_bit_set = (handle->nonempty_bin_mask & pow2((uint_fast8_t)i)) != 0U;
        const bool bin_nonempty = handle->bins[i] != NULL;
        valid = valid && (mask_bit_set == bin_nonempty);
    }

    // Create a local copy of the diagnostics struct.
    const O1HeapDiagnostics diag = handle->diagnostics;

    // Capacity check.
    valid = valid && (diag.capacity <= FRAGMENT_SIZE_MAX) && (diag.capacity >= FRAGMENT_SIZE_MIN) &&
        ((diag.capacity % FRAGMENT_SIZE_MIN) == 0U);

    // Allocation info check.
    valid = valid && (diag.allocated <= diag.capacity) && ((diag.allocated % FRAGMENT_SIZE_MIN) == 0U) &&
        (diag.peak_allocated <= diag.capacity) && (diag.peak_allocated >= diag.allocated) &&
        ((diag.peak_allocated % FRAGMENT_SIZE_MIN) == 0U);

    // Peak request check
    valid = valid && ((diag.peak_request_size < diag.capacity) || (diag.oom_count > 0U));
    if (diag.peak_request_size == 0U)
    {
        valid = valid && (diag.peak_allocated == 0U) && (diag.allocated == 0U) && (diag.oom_count == 0U);
    }
    else
    {
        valid = valid &&  // Overflow on summation is possible but safe to ignore.
            (((diag.peak_request_size + O1HEAP_ALIGNMENT) <= diag.peak_allocated) || (diag.oom_count > 0U));
    }

    return valid;
}

O1HeapDiagnostics o1heapGetDiagnostics(const O1HeapInstance* const handle)
{
    O1HEAP_ASSERT(handle != NULL);
    const O1HeapDiagnostics out = handle->diagnostics;
    return out;
}
