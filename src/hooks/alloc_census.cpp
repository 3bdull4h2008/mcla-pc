// Phase 2 split of src/patches.cpp: this TU owns the OOM/allocation-path/pool16/slab census hooks (ex-lines 1093-2647).







// Entry points used by mcla_ApplyPatches are declared in hooks/hooks.h.







// includes mirror patches.cpp so hook bodies resolve identically.







#include "patches.h"







#include "hooks/hooks.h"







#include "app.h"







#include "cpu/ppc_context.h"







#include "generated/ppc_xenon/ppc_recomp_shared.h"







#include "gpu_cp.h"







#include "gpu_device.h"







#include "gpu_mmio.h"







#include "guest_memory.h"







#include "logging.h"







#include "native_renderer.h"







#include "render_queue.h"







#include "render_thread.h"







#include "renderer_mode.h"







#include "fs/vfs_rpf.h"















#include "kernel/memory.h"







#include "kernel/xbox.h"







#include "kernel/kernel_objects.h"















#include <algorithm>







#include <atomic>







#include <cctype>







#include <chrono>







#include <cstring>







#include <filesystem>







#include <fstream>







#include <mutex>







#include <unordered_set>







#include <system_error>







#include <unordered_map>







#include <unordered_set>







#include <vector>















#include <fcntl.h>







#include <io.h>







#include <windows.h>















// Forward declarations for kernel functions via import thunks







extern "C" uint32_t KeReleaseSemaphore(void *, uint32_t, uint32_t, uint32_t);















// ---------------------------------------------------------------------------







// SESSION 34 (2026-08-30): OOM-frontier census - CENSUS ONLY, passthrough.







//







// Evidence base (ledger session 33): boot fatal is the guest's own RAGE OOM







// (sub_821BD618 dispatcher, fmt 0x82011F78) raised from sub_821C29A0 at guest







// lr=0x821C2A7C when its heap's free-list walk (sub_821C1BB0, 16 size-class







// buckets, NO grow path - loc_821C1D28 returns 0 outright) finds nothing.







// Heap accounting fields (validated by the sub_821C22D0 walk invariant







// [r+84]+[r+152]==[r+76]): +76=capacity, +84=free, +152=used counter.







// sub_82130B50(r3=size, r4=flags/alignment-code) is the game's physical







// memory allocation wrapper (sole caller 158.cpp:27532) - census proves







// whether the game ever attempts physical growth before the fatal.







//







// Golden rules honored: passthrough only (zero behavior change), checked







// BE reads via GuestMemoryHeap, one hook owner per address (verified: no







// prior overrides of either address in src/), no D3D12, no seeding.







// ---------------------------------------------------------------------------







#include "kernel/memory.h"







#include <atomic>















namespace {







std::atomic<uint32_t> s_oomAllocCensus{0};







std::atomic<uint32_t> s_physAllocCensus{0};







// SESSION 37: entry-time fast-path capture counters (see







// PPC_FUNC(sub_821C29A0)).







std::atomic<uint32_t> s_fastPathCensus{0};







std::atomic<uint32_t> s_zeroSizeLogged{0};















// Live free-path writes (lr≈0x821DEB0C) fill freed 16-byte elements with







// 0xCDCDCDCD; older census assumed 0xDDDDDDDD. Accept both.







bool LooksLikeFreeFill(uint32_t word) {







  return word == 0xCDCDCDCDu || word == 0xDDDDDDDDu;







}















bool ElementLooksFree(uint32_t elemAddr, uint32_t elemsize) {







  for (uint32_t b = 4; b < elemsize; b += 4) {







    if (!LooksLikeFreeFill(OomCensusReadU32(elemAddr + b))) {







      return false;







    }







  }







  return true;







}















bool RepairCorruptedTinySlabFreeList(uint32_t classHead) {







  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







  const uint32_t headWord = OomCensusReadU32(classHead + 4);







  const uint32_t elemsize = headWord >> 16;







  const uint32_t nodesPerSlab = headWord & 0xFFFFu;







  if (elemsize == 0 || elemsize > 64 || nodesPerSlab == 0 ||







      nodesPerSlab > 4096) {







    return false;







  }















  bool repaired = false;







  const uint32_t slabDataStart = 32u;







  const uint32_t slabDataSpan = nodesPerSlab * elemsize;







  uint32_t curSlab = OomCensusReadU32(classHead + 0);







  while (curSlab != 0) {







    const uint32_t count = OomCensusReadU32(curSlab + 8);







    const uint32_t freeHead = OomCensusReadU32(curSlab + 12);







    bool broken = (count > 0 && freeHead == 0);







    if (!broken && count > 0 && freeHead != 0) {







      const uint32_t headNext = OomCensusReadU32(freeHead + 0);







      broken = (headNext != 0 &&







                (headNext < curSlab + slabDataStart ||







                 headNext >= curSlab + slabDataStart + slabDataSpan));







    }















    if (broken) {







      uint32_t newHead = 0;







      uint32_t newCount = 0;







      bool foundAny = false;















      for (uint32_t i = 0; i < nodesPerSlab; ++i) {







        const uint32_t elemAddr = curSlab + slabDataStart + (i * elemsize);







        if (ElementLooksFree(elemAddr, elemsize)) {







          (void)mem.WriteU32BE(elemAddr + 0, newHead);







          newHead = elemAddr;







          ++newCount;







          foundAny = true;







        }







      }















      // Honest empty: zero the stale count so DE9D8 takes the refill path







      // instead of returning 0 from a phantom freeCount.







      if (!foundAny) {







        (void)mem.WriteU32BE(curSlab + 12, 0);







        (void)mem.WriteU32BE(curSlab + 8, 0);







      } else {







        (void)mem.WriteU32BE(curSlab + 12, newHead);







        (void)mem.WriteU32BE(curSlab + 8, newCount);







      }















      MCLA_LOG_WARN("POOL-FREELIST-REPAIRED classHead={:08X} slab={:08X} "







                    "elemsize={} cap={} oldCount={} newCount={} newHead={:08X} "







                    "freeHeadWas={:08X}",







                    classHead, curSlab, elemsize, nodesPerSlab, count,







                    foundAny ? newCount : 0, foundAny ? newHead : 0, freeHead);







      repaired = true;







    }







    curSlab = OomCensusReadU32(curSlab + 4);







  }







  return repaired;







}















void LogDe9D8Oom(uint32_t classHead, uint32_t heap) {







  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







  uint32_t cap = 0, carved = 0, free = 0;







  (void)mem.ReadU32BE(heap + 76, &cap);







  (void)mem.ReadU32BE(heap + 84, &carved);







  (void)mem.ReadU32BE(heap + 152, &free);







  MCLA_LOG_ERROR("DE9D8-OOM: classHead={:08X} heap={:08X} cap={} carved={} "







                 "free={}",







                 classHead, heap, cap, carved, free);







  uint32_t curSlab = OomCensusReadU32(classHead + 0);







  int idx = 0;







  while (curSlab != 0 && idx < 8) {







    const uint32_t newer = OomCensusReadU32(curSlab + 0);







    const uint32_t older = OomCensusReadU32(curSlab + 4);







    const uint32_t count = OomCensusReadU32(curSlab + 8);







    const uint32_t head = OomCensusReadU32(curSlab + 12);







    MCLA_LOG_ERROR("  slab[{}] @ {:08X}: newer={:08X} older={:08X} "







                   "freeCount={} head={:08X}",







                   idx, curSlab, newer, older, count, head);







    curSlab = older;







    ++idx;







  }







}







} // namespace















// ---------------------------------------------------------------------------







// SESSION 73: tiny-slab fill-on-alloc attribution (slim census, all classes).







//







// Static decode (ppc_recomp.20.cpp sub_821DE9D8 loc_821DEAFC): the common







// tail of this allocator runs memset(node, 0xCD, elemsize) before returning







// the element — on the freelist-pop path AND the fresh-slab refill path.







// Two more guest fills exist (startup memsets of the 1352-byte global at







// 0x8283C5E0, ppc_recomp.10.cpp sub_8218C9D4/sub_8218CCB0). Conclusion: a







// 0xCDCDCDCD field seen at a use-site is a field the element's owner never







// initialized — same fill runs on retail HW, where producers always init







// before consumers read. Our poison therefore points at a producer step the







// emulation skips, not at a hostile writer.







//







// This census records (element, caller LR, elemsize) for every allocation in







// a small ring so poison use-sites (REBASE-POISON / P10-PRE in







// task_dispatch_trace.cpp) can resolve the producer via mcla_SlimTslabFind.







// Logging is sampled: es==16 (pool16) sparsely, other classes densely for







// the first 20000 allocs (the poison window is early boot).







// ---------------------------------------------------------------------------







namespace {







std::atomic<uint32_t> s_tslabAllocs{0};







struct TslabRecord {







  std::atomic<uint32_t> elem{0};







  std::atomic<uint32_t> lr{0};







  std::atomic<uint32_t> es{0};







};







constexpr uint32_t kTslabRecords = 8192;







TslabRecord g_tslabRecords[kTslabRecords];







std::atomic<uint32_t> g_tslabRecIdx{0};















// Owner-level ring: element -> the guest code that called the RAGE heap







// small-alloc front-end (sub_821C29A0). Recorded in that wrapper; preferred







// over the allocator-level lr (which is always 0x821C2A3C for this path).







std::atomic<uint32_t> s_tslabOwners{0};







struct TslabOwnerRecord {







  std::atomic<uint32_t> elem{0};







  std::atomic<uint32_t> lr{0};







  std::atomic<uint32_t> es{0};







};







TslabOwnerRecord g_tslabOwners[kTslabRecords];







std::atomic<uint32_t> g_tslabOwnerIdx{0};







} // namespace















PPC_FUNC_IMPL(__imp__sub_821C29A0);







PPC_FUNC(sub_821C29A0) {







  // SESSION 39 FIX: handle zero-size allocations (legitimate degenerate







  // requests from the game). Standard allocator semantics: malloc(0) returns







  // a valid minimum-size allocation. Session-37 used size=4 (elemsize==4







  // class), but the game's own zero-size free path writes directly to the







  // elemsize==4 slab header — bypassing DE908 — corrupting the freelist.







  // Fix: route to the size class matching the requested alignment instead,







  // avoiding the elemsize==4 slab entirely. When align=0, fall back to 16.







  uint32_t effectiveSize = ctx.r4.u32;







  if (effectiveSize == 0) {







    effectiveSize = (ctx.r5.u32 > 0) ? ctx.r5.u32 : 16;







    ctx.r4.u32 = effectiveSize;







  }















  if constexpr (!kPool16CensusEnabled) {







    const uint32_t self = ctx.r3.u32;







    const uint32_t reqSize = ctx.r4.u32;







    const uint32_t reqAlign = ctx.r5.u32;







    const uint32_t callerLr = static_cast<uint32_t>(ctx.lr);







    __imp__sub_821C29A0(ctx, base);







    // Lightweight OOM diagnostic: only logs when allocation fails







    if (ctx.r3.u32 == 0 && self != 0) {







      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







      uint32_t cap = 0, carved = 0, free = 0, flags = 0;







      (void)mem.ReadU32BE(self + 76, &cap);







      (void)mem.ReadU32BE(self + 84, &carved);







      (void)mem.ReadU32BE(self + 152, &free);







      (void)mem.ReadU32BE(self + 196, &flags);







      MCLA_LOG_ERROR("POOL16-OOM: alloc failed size={} align={} lr={:08X} "







                     "heap={:08X} cap={} carved={} free={} flags={:08X}",







                     reqSize, reqAlign, callerLr,







                     self, cap, carved, free, flags);







    }







    // Session 73: record the owner of the returned element so poison







    // use-sites can name the guest code that received it. Verify the element







    // really came from the small-path slab (slab->owner == the size-class







    // head the front-end picks) and take the true elemsize from that head.







    if (ctx.r3.u32 != 0) {







      auto &mem73 = mcla::kernel::GuestMemoryHeap::Instance();







      const uint32_t elem = ctx.r3.u32;







      const uint32_t slotOff = (effectiveSize <= 4)   ? 208







                               : (effectiveSize <= 8) ? 216







                               : (effectiveSize <= 16)   ? 224







                               : (effectiveSize <= 32)   ? 232







                                                         : 240;







      const uint32_t slab = elem & ~0x3FFFu;







      uint32_t slabOwner = 0;







      uint16_t es16 = 0;







      (void)mem73.ReadU32BE(slab + 16, &slabOwner);







      if (slabOwner == self + slotOff)







        (void)mem73.ReadU16BE(self + slotOff + 4, &es16);







      const uint32_t orec = g_tslabOwnerIdx.fetch_add(1) % kTslabRecords;







      g_tslabOwners[orec].elem.store(elem, std::memory_order_relaxed);







      g_tslabOwners[orec].lr.store(callerLr, std::memory_order_relaxed);







      g_tslabOwners[orec].es.store(es16, std::memory_order_relaxed);







      const uint32_t oidx = s_tslabOwners.fetch_add(1) + 1;







      if (oidx <= 200u || (oidx % 64u) == 0u) {







        MCLA_LOG_WARN("TSLAB-OWNER #{:09} size={} align={} elem={:08X} "







                      "es={} lr={:08X} heap={:08X}",







                      oidx, reqSize, reqAlign, elem, es16, callerLr, self);







      }







    }







    return;







  }















  const uint32_t n = s_oomAllocCensus.fetch_add(1) + 1;







  const uint32_t self = ctx.r3.u32;







  const uint32_t sizeEntry = effectiveSize;







  const uint32_t alignEntry = ctx.r5.u32;







  const uint32_t callerLr = static_cast<uint32_t>(ctx.lr);















  const uint32_t preCap = OomCensusReadU32(self + 76);







  const uint32_t preCarved = OomCensusReadU32(self + 84);







  const uint32_t preFree = OomCensusReadU32(self + 152);















  __imp__sub_821C29A0(ctx, base);















  const uint32_t ret = ctx.r3.u32;







  if (ret == 0) {







    static std::atomic<uint32_t> s_heapOomCount{0};







    const uint32_t oomIdx = s_heapOomCount.fetch_add(1) + 1;







    const uint32_t postCap = OomCensusReadU32(self + 76);







    const uint32_t postCarved = OomCensusReadU32(self + 84);







    const uint32_t postFree = OomCensusReadU32(self + 152);







    const uint32_t flagsWord = OomCensusReadU32(self + 196);















    uint32_t b15Count = 0, b15Sum = 0;







    {







      uint32_t cur = OomCensusReadU32(self + 72);







      uint32_t walked = 0;







      while (cur != 0 && walked < 4096) {







        ++b15Count;







        uint32_t blkSize = OomCensusReadU32(cur + 4);







        b15Sum += blkSize;







        cur = OomCensusReadU32(cur + 20);







        ++walked;







      }







    }















    MCLA_LOG_WARN(







        "HEAP-OOM #{} heap={:08X} reqSize={:08X} align={:08X} lr={:08X} | "







        "pre: cap={:08X} carved={:08X} free={:08X} | "







        "post: cap={:08X} carved={:08X} free={:08X} | "







        "b15: count={} sum={:08X} flags={:02X}",







        oomIdx, self, sizeEntry, alignEntry, callerLr, preCap, preCarved,







        preFree, postCap, postCarved, postFree, b15Count, b15Sum,







        (flagsWord & 0xFFu));







  }















  if (n <= 32 || n % 2000 == 0) {







    const uint32_t cap = OomCensusReadU32(self + 76);







    const uint32_t freeB = OomCensusReadU32(self + 84);







    const uint32_t used = OomCensusReadU32(self + 152);







    const uint32_t flagsWord2 = OomCensusReadU32(self + 196);







    MCLA_LOG_WARN("OOM-CENSUS #{} self={:08X} req(r4)={:08X} r5={:08X} "







                  "cap={:08X} free={:08X} "







                  "used={:08X} flags199={:02X} lr={:08X} ret={:08X}",







                  n, self, sizeEntry, alignEntry, cap, freeB, used,







                  (flagsWord2 & 0xFFu), callerLr, ret);







  }







}















PPC_FUNC_IMPL(__imp__sub_82130B50);







PPC_FUNC(sub_82130B50) {







  if constexpr (!kPool16CensusEnabled) {







    __imp__sub_82130B50(ctx, base);







    return;







  }















  const uint32_t n = s_physAllocCensus.fetch_add(1) + 1;







  const uint32_t sizeArg = ctx.r3.u32;







  const uint32_t flagsArg = ctx.r4.u32;







  __imp__sub_82130B50(ctx, base);







  if (n <= 32 || n % 500 == 0) {







    MCLA_LOG_WARN(







        "PHYSALLOC-CENSUS #{} size={:08X} flags={:08X} -> ret={:08X} lr={:08X}",







        n, sizeArg, flagsArg, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));







  }







}















// ---------------------------------------------------------------------------







// SESSION 36 (2026-08-31): refill-failure census on the arena free-list







// allocator sub_821C1BB0(heap, size, align) - CENSUS ONLY, passthrough.







//







// Evidence base (session 36 static decode + soak35 live data):







// - sub_821C29A0(heap, size, align): size<=64 && align<=16 -> tiny size-class







//   pools (heads at heap+208..240). Empty class -> sub_821DE9D8 refill:







//   sub_821C1BB0(heap, 16320, 16384) i.e. a 16 KiB-ALIGNED 16320-byte slab.







//   Refill fail -> guest OOM fatal ("Not enough memory to allocate %u bytes







//   (%u available)") prints size and heap[+152] as "available".







// - soak35 live census proves the field map: +76=capacity (0x02E7FFF0),







//   +84=carved-from-arena, +152=free/unallocated (they satisfy







//   +84 + +152 == +76 and start at 16 / cap-16 on a fresh heap). At the







//   session-35 fatal: carved ~1.87 MiB, "available" 0x02CB4F00 = 44.7 MiB







//   -> the heap was NOT exhausted; the "44.8MB request" was a misread of the







//   available field. The request was <=16 bytes.







// - sub_821C1BB0 has NO grow path (failure loc 0x821C1D28 just returns 0);







//   it serves allocations only from the 16 free-bucket chains (heads at







//   heap+12..heap+72). Bucket 15 holds every free block >=240 bytes.







// - Open question this census answers with live data: at refill failure, is







//   bucket 15 fragmented into sub-16 KiB blocks (legitimate fragmentation) or







//   is the chain empty/short while +152 still reports megabytes (accounting







//   desync)? Block layout: +0 self-magic, +4 size, +20 next-in-bucket.







// Golden rules: passthrough only (r3 flows through), checked BE reads via







// GuestMemoryHeap, one hook owner per address (no prior override of







// 0x821C1BB0 in src/), no D3D12, no seeding, no invented behavior.







// ---------------------------------------------------------------------------







namespace {







std::atomic<uint32_t> s_arenaCensus{0};







std::atomic<uint32_t> s_arenaFailures{0};







// SESSION 37: refill-depth marker so sub_821DE9D8's census can tell a







// return-0 that went through the sub_821C1BB0 refill from one that did not







// (the no-refill pop-path return-0 is the session-36 prime suspect).







thread_local uint32_t t_arenaDepth = 0;












































} // namespace















// Session 76j: general-allocator free (sysMemSimpleAllocator::Free slow path,







// sub_821C2AB8 → sub_821C22D0(self=heap, ptr)). Log ptr + the 16-byte block







// header it trusts ([ptr-16]=self, [ptr-12]=size, [ptr-8]=phys-prev,







// [ptr-4]=flags) so a bogus/interior free that poisons the free buckets







// names itself. Volume-capped: first 40 always, size>=512, or window hits.







// Session 76j: sysMemDualBuddyAllocator Allocate/Free (the registry's default







// alloc bank: sub_821C08F8 dispatches to m_Allocators[(r6+1)*4], i.e. the







// dual buddy for r6=0). The checkerboard pixel buffer's write landed at






// payload areas when a new slab is allocated. Called from the pool allocator

// census hooks when a new 16-byte pool slab is detected.

















// A0018028 — inside the SIMPLE allocator's slab region — while buddyA's







// arena base is A4001000. Log every buddy alloc/free to catch the block that







// escaped its arena.







PPC_FUNC_IMPL(__imp__sub_82130010);







static std::atomic<uint32_t> s_buddyAlloc{0};







PPC_FUNC(sub_82130010) {







  const uint32_t n = s_buddyAlloc.fetch_add(1) + 1;







  const uint32_t size = ctx.r4.u32;







  __imp__sub_82130010(ctx, base);







  if (n <= 60 || size >= 1024) {







    MCLA_LOG_WARN("BUDDY76-ALLOC #{} dual={:08X} size={:#x} ret={:08X} lr={:08X}",







                  n, ctx.r3.u32, size, ctx.r3.u32,







                  static_cast<uint32_t>(ctx.lr));







  }







}















PPC_FUNC_IMPL(__imp__sub_82130048);







static std::atomic<uint32_t> s_buddyFree{0};







PPC_FUNC(sub_82130048) {







  const uint32_t n = s_buddyFree.fetch_add(1) + 1;







  const uint32_t ptr = ctx.r4.u32;







  __imp__sub_82130048(ctx, base);







  if (n <= 60 || (ptr >= 0xA0000000u && ptr < 0xA4000000u)) {







    MCLA_LOG_WARN("BUDDY76-FREE #{} ptr={:08X} lr={:08X}{}", n, ptr,







                  static_cast<uint32_t>(ctx.lr),







                  (ptr >= 0xA0000000u && ptr < 0xA4000000u) ? " LOWPOOL" : "");







  }







}















// Session 76j: texture-object ctor (sub_8218DE38) — dump the returned object,







// its pixel-buffer pointer (+16) and pitch (+12). The checkerboard fill wrote







// through [obj+16] at A0018028 (inside the simple allocator's 8-byte slab







// region) while every buddy allocation returns B7xxxxxx — this shows what







// [obj+16] actually held.







// Session 76j: sub_8218DCE8 = texture pitch computation. The recompiler







// failed on its jump-table switch (all cases emitted as ERROR stubs that just







// return), so [obj+12] was never written — the grcTextureXenon ctor then







// sized the pixel buffer from garbage (pitch=1 → 32-byte buffer) and the







// 32x32 checkerboard fallback fill wrote 4096 bytes over the heap, trashing







// the device-registry holder (crash: GetDevice on FF00FF00 Device*).







// Reconstructed 1:1 from the raw image: jump table @0x8218DD14, case bodies







// @0x8218DD6C-0x8218DE30 (all sth u16 at [obj+12]).







//   fmt 1,14,15,16,17,19 -> w*4     fmt 11,18,22 -> w*8







//   fmt 12,13            -> w*16    fmt 20       -> w*2







//   fmt 9,10,21          -> no store (case = plain blr)







//   fmt 2                -> 2       (addi 4 >> srawi 1, literal)







//   fmt 3..8             -> (w >= 4) ? fmt : 4







PPC_FUNC_IMPL(__imp__sub_8218DCE8);







PPC_FUNC(sub_8218DCE8) {







  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







  const uint32_t obj = ctx.r3.u32;







  uint32_t fmtWord = 0;







  if (!obj || !mem.ReadU32BE(obj + 4u, &fmtWord)) {







    __imp__sub_8218DCE8(ctx, base);







    return;







  }







  const uint32_t fmt = fmtWord & 0x7FFFFFFFu;







  const uint32_t idx = fmt - 1;







  uint16_t w = 0;







  (void)mem.ReadU16BE(obj + 0u, &w);







  uint32_t pitch = 0;







  bool store = true;







  if (idx > 21) {







    store = false; // bgtlr: pitch untouched







  } else if (fmt == 2) {







    pitch = 2;







  } else if (fmt >= 3 && fmt <= 8) {







    pitch = (w >= 4) ? fmt : 4u;







  } else if (fmt == 9 || fmt == 10 || fmt == 21) {







    store = false;







  } else if (fmt == 11 || fmt == 18 || fmt == 22) {







    pitch = static_cast<uint32_t>(w) << 3;







  } else if (fmt == 12 || fmt == 13) {







    pitch = static_cast<uint32_t>(w) << 4;







  } else if (fmt == 20) {







    pitch = static_cast<uint32_t>(w) << 1;







  } else { // 1, 14, 15, 16, 17, 19







    pitch = static_cast<uint32_t>(w) << 2;







  }







  if (store && obj) {







    (void)mem.WriteU16BE(obj + 12u, static_cast<uint16_t>(pitch));







  }







  __imp__sub_8218DCE8(ctx, base);







}















PPC_FUNC_IMPL(__imp__sub_8218DE38);







static std::atomic<uint32_t> s_texCtor{0};







PPC_FUNC(sub_8218DE38) {







  const uint32_t w = ctx.r3.u32, h = ctx.r4.u32;







  const uint32_t fmt = ctx.r6.u32;







  __imp__sub_8218DE38(ctx, base);







  const uint32_t n = s_texCtor.fetch_add(1) + 1;







  const uint32_t obj = ctx.r3.u32;







  if (obj && n <= 60) {







    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







    uint32_t pitch = 0, buf = 0;







    (void)mem.ReadU32BE(obj + 12u, &pitch);







    (void)mem.ReadU32BE(obj + 16u, &buf);







    MCLA_LOG_WARN("TEXCTOR #{} obj={:08X} w={} h={} fmt={:08X} pitch={:08X} "







                  "buf={:08X} lr={:08X}",







                  n, obj, w, h, fmt, pitch, buf,







                  static_cast<uint32_t>(ctx.lr));







  }







}















PPC_FUNC_IMPL(__imp__sub_821C22D0);







static std::atomic<uint32_t> s_genFree{0};







PPC_FUNC(sub_821C22D0) {







  const uint32_t n = s_genFree.fetch_add(1) + 1;







  const uint32_t ptr = ctx.r4.u32;







  uint32_t hdr0 = 0, hdr1 = 0, hdr2 = 0, hdr3 = 0;







  if (ptr) {







    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







    (void)mem.ReadU32BE(ptr - 16, &hdr0);







    (void)mem.ReadU32BE(ptr - 12, &hdr1);







    (void)mem.ReadU32BE(ptr - 8, &hdr2);







    (void)mem.ReadU32BE(ptr - 4, &hdr3);







  }







  const bool windowHit = ptr >= 0xA0017F00u && ptr <= 0xA0018100u;







  if (n <= 40 || hdr1 >= 512 || windowHit) {







    MCLA_LOG_WARN("GEN76-FREE #{} heap={:08X} ptr={:08X} hdr=[{:08X} {:08X} "







                  "{:08X} {:08X}] lr={:08X}{}",







                  n, ctx.r3.u32, ptr, hdr0, hdr1, hdr2, hdr3,







                  static_cast<uint32_t>(ctx.lr), windowHit ? " WINDOW" : "");







  }







  __imp__sub_821C22D0(ctx, base);







}















PPC_FUNC_IMPL(__imp__sub_821C1BB0);







PPC_FUNC(sub_821C1BB0) {







  if constexpr (!kPool16CensusEnabled) {







    const uint32_t heap = ctx.r3.u32;







    const uint32_t size = ctx.r4.u32;







    const uint32_t align = ctx.r5.u32;







    __imp__sub_821C1BB0(ctx, base);







    if (ctx.r3.u32 == 0 && heap != 0) {







      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







      uint32_t cap = 0, carved = 0, free = 0;







      (void)mem.ReadU32BE(heap + 76, &cap);







      (void)mem.ReadU32BE(heap + 84, &carved);







      (void)mem.ReadU32BE(heap + 152, &free);







      MCLA_LOG_ERROR("ARENA-OOM: sub_821C1BB0 failed size={} align={} heap={:08X} "







                     "cap={} carved={} free={}",







                     size, align, heap, cap, carved, free);







    }







    // Session 76j: the checkerboard placeholder's 4096-byte buffer (general







    // allocator) landed on the live device-holder (8B slab element). Log every







    // big allocation so the free-block history of that region is reconstructable.







    if (ctx.r3.u32 != 0 && size >= 4096) {







      static std::atomic<uint32_t> s_genBig{0};







      const uint32_t gn = s_genBig.fetch_add(1) + 1;







      if (gn <= 150) {







        MCLA_LOG_WARN("GEN76-ALLOC #{} heap={:08X} size={:#x} align={:#x} "







                      "ret={:08X} lr={:08X}",







                      gn, heap, size, align, ctx.r3.u32,







                      static_cast<uint32_t>(ctx.lr));







      }







    }







    return;







  }















  const uint32_t heap = ctx.r3.u32;







  const uint32_t sizeArg = ctx.r4.u32;







  const uint32_t alignArg = ctx.r5.u32;















  ++t_arenaDepth;







  __imp__sub_821C1BB0(ctx, base);







  --t_arenaDepth;















  const uint32_t n = s_arenaCensus.fetch_add(1) + 1;







  const bool failed = (ctx.r3.u32 == 0);







  uint32_t failIdx = 0;







  if (failed) {







    failIdx = s_arenaFailures.fetch_add(1) + 1;







  }















  const bool periodic = (n <= 8 || n % 65536 == 0);







  const bool logFailure = failed && (failIdx <= 200 || failIdx % 50 == 0);







  if (!periodic && !logFailure) {







    return;







  }















  // Walk bucket 15 (head = heap+72): blocks >=240 bytes live here, and the







  // 16 KiB slab refill searches exactly this chain. Cycle-capped.







  uint32_t walked = 0;







  uint32_t sum = 0;







  uint32_t head = OomCensusReadU32(heap + 72);







  uint32_t cur = head;







  uint32_t firstAddr[6] = {0, 0, 0, 0, 0, 0};







  uint32_t firstSize[6] = {0, 0, 0, 0, 0, 0};







  while (cur != 0 && walked < 4096) {







    bool okSize = false;







    bool okNext = false;







    const uint32_t blkSize = OomCensusReadU32(cur + 4, &okSize);







    const uint32_t next = OomCensusReadU32(cur + 20, &okNext);







    if (!okSize) {







      head |= 1u; // flag: unreadable chain node







      break;







    }







    if (walked < 6) {







      firstAddr[walked] = cur;







      firstSize[walked] = blkSize;







    }







    sum += blkSize;







    ++walked;







    if (!okNext) {







      head |= 2u; // flag: unreadable next link







      break;







    }







    cur = next;







  }















  MCLA_LOG_WARN(







      "ARENA-CENSUS #{} {} heap={:08X} size={:08X} align={:08X} -> ret={:08X} "







      "cap(+76)={:08X} carved(+84)={:08X} free(+152)={:08X} b15head={:08X} "







      "walked={} walkedsum={:08X} lr={:08X} blocks=[{:08X}/{:08X} "







      "{:08X}/{:08X} "







      "{:08X}/{:08X} {:08X}/{:08X} {:08X}/{:08X} {:08X}/{:08X}]",







      n, failed ? "FAIL" : "OK  ", heap, sizeArg, alignArg, ctx.r3.u32,







      OomCensusReadU32(heap + 76), OomCensusReadU32(heap + 84),







      OomCensusReadU32(heap + 152), head, walked, sum,







      static_cast<uint32_t>(ctx.lr), firstAddr[0], firstSize[0], firstAddr[1],







      firstSize[1], firstAddr[2], firstSize[2], firstAddr[3], firstSize[3],







      firstAddr[4], firstSize[4], firstAddr[5], firstSize[5]);







}















// ---------------------------------------------------------------------------







// SESSION 37 STEP 2 (2026-08-31): tiny-class slab allocator census on







// sub_821DE9D8(classHead, heap) - CENSUS ONLY, passthrough.







//







// Static decode (generated/ppc_xenon ppc_recomp.20.cpp:15810-16001):







// - slab list: head+0 = first (newest) slab; slab links: +0 = newer,







//   +4 = older (pop walk follows +4); head+4 u16 elemsize, head+6 u16







//   nodes-per-slab.







// - slab layout: +0 next-newer, +4 prev-older, +8 count (available),







//   +12 freelist head, +16 owner class head.







// - pop path (loc 0x821DEA6C): node = [slab+12]; count--; [slab+12]=[node];







//   returns node. It is entered whenever signed count([slab+8]) != 0.







//   => returns 0 WITHOUT any refill iff a slab has count != 0 but







//      freelist([slab+12]) == 0 (session-36 prime suspect).







// - refill path (loc 0x821DEA18): sub_821C1BB0(heap, 16320, 16384);







//   result==0 -> allocator returns 0 (refill failure, already censused







//   by ARENA-CENSUS and observed to never fire).







// This census flags every return-0, labels it NOREFILL vs REFILLFAIL via the







// t_arenaDepth marker set by the sub_821C1BB0 override, and dumps the class







// head + slab chain + real freelist chain length so count/freelist desync is







// visible live. Passthrough only; checked BE reads; no behavior change.







// ---------------------------------------------------------------------------







namespace {







std::atomic<uint32_t> s_poolCensus{0};







std::atomic<uint32_t> s_poolFailures{0};







std::atomic<uint32_t> s_poolPops{0};







std::atomic<uint32_t> s_allocCensus{0};















// Forward declaration — defined after the census wrappers (session 26







// write-watch)





























// ---------------------------------------------------------------------------







// SESSION 55 (B3): Writer-attribution census for the 16-byte pool overflow.







// Root cause: game writes >16 bytes to 16-byte pool allocations, corrupting







// adjacent elements. Strategy:







//   1. Snapshot every allocation (element addr, first 8 bytes, caller LR)







//   2. Periodically scan all slabs to detect corruption on live elements







//   3. At free time, compare element against snapshot to detect overflow







//   4. On corruption: dump full context (element, slab, alloc history)







// ---------------------------------------------------------------------------







namespace {







constexpr uint32_t kPool16ClassHead = 0x82830DB8u;







constexpr uint32_t kPool16MaxSnapshots = 32768u;







struct Pool16Snapshot {







  uint32_t elemAddr;    // allocated element address (guest)







  uint32_t first8bytes; // snapshot of [elem+0..3] (BE) at allocation time







  uint32_t callerLR;    // return address of the allocator's caller







  uint32_t allocIdx;    // global allocation index







};







Pool16Snapshot g_pool16Snapshots[kPool16MaxSnapshots]{};







std::atomic<uint32_t> g_pool16SnapIdx{0};







std::atomic<uint32_t> g_pool16ScanCount{0};







std::atomic<uint32_t> g_pool16CorruptionCount{0};















// Dump element content as hex (16 bytes = 4 BE dwords)







void DumpPool16Element(uint32_t addr) {







  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







  uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;







  mem.ReadU32BE(addr + 0, &w0);







  mem.ReadU32BE(addr + 4, &w1);







  mem.ReadU32BE(addr + 8, &w2);







  mem.ReadU32BE(addr + 12, &w3);







  MCLA_LOG_WARN("  ELEM {:08X}: {:08X} {:08X} {:08X} {:08X}", addr, w0, w1, w2,







                w3);







}















// Scan ALL slabs for the 16-byte pool: compare each allocated element's first







// 4 bytes against its snapshot. A change in the first 4 bytes of a freed







// element (which should hold a freelist next-pointer) indicates overflow from







// the preceding element.







void ScanPool16SlabsForOverflow(uint32_t triggerAllocIdx) {







  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();







  const uint32_t headWord = OomCensusReadU32(kPool16ClassHead + 4);







  const uint32_t es = headWord >> 16;







  const uint32_t cap = headWord & 0xFFFFu;







  if (es != 16 || cap != 1018)







    return;















  uint32_t curSlab = OomCensusReadU32(kPool16ClassHead + 0);







  uint32_t slabIdx = 0;







  while (curSlab != 0) {







    const uint32_t slabCount = OomCensusReadU32(curSlab + 8);







    const uint32_t slabFreeHead = OomCensusReadU32(curSlab + 12);















    // Build a hash set of free element addresses for this slab (fast lookup).







    // Elements on the freelist have [node+0] = next-free, which points within







    // the slab data area. Walk the chain to identify all free elements.







    // Use a small local buffer; typical slab has ~400-600 free elements.







    static thread_local uint32_t s_freeAddrs[1200];







    uint32_t freeCount = 0;







    if (slabFreeHead != 0 && slabCount > 0 && slabCount < cap) {







      uint32_t cur = slabFreeHead;







      while (cur != 0 && freeCount < 1200) {







        s_freeAddrs[freeCount++] = cur;







        cur = OomCensusReadU32(cur + 0);







        if (freeCount > cap)







          break; // safety: avoid infinite loop on corrupted chain







      }







    }















    // Scan every element in the slab







    for (uint32_t i = 0; i < cap; ++i) {







      const uint32_t elemAddr = curSlab + 32 + i * es;















      // Check if this element is on the freelist







      bool isFree = false;







      for (uint32_t f = 0; f < freeCount; ++f) {







        if (s_freeAddrs[f] == elemAddr) {







          isFree = true;







          break;







        }







      }















      if (isFree)







        continue; // free elements are expected to have freelist pointers















      // Element is allocated. Check if its first 4 bytes match the snapshot.







      const uint32_t curFirst4 = OomCensusReadU32(elemAddr + 0);















      // Search snapshot for this address







      bool found = false;







      uint32_t snapIdx = g_pool16SnapIdx.load(std::memory_order_relaxed);







      const uint32_t searchCount = std::min(snapIdx, kPool16MaxSnapshots);







      for (uint32_t s = 0; s < searchCount; ++s) {







        if (g_pool16Snapshots[s].elemAddr == elemAddr) {







          found = true;







          if (g_pool16Snapshots[s].first8bytes != curFirst4) {







            const uint32_t corruptN = g_pool16CorruptionCount.fetch_add(1) + 1;







            if (corruptN <= 32) {







              MCLA_LOG_WARN(







                  "POOL16-OVERFLOW #{} elem={:08X} slab={} elemIdx={} "







                  "snapFirst4={:08X} curFirst4={:08X} snapLR={:08X} "







                  "snapAllocIdx={} triggerAllocIdx={} slabCount={} "







                  "slabFreeHead={:08X}",







                  corruptN, elemAddr, slabIdx, i,







                  g_pool16Snapshots[s].first8bytes, curFirst4,







                  g_pool16Snapshots[s].callerLR, g_pool16Snapshots[s].allocIdx,







                  triggerAllocIdx, slabCount, slabFreeHead);















              // Dump the corrupted element and its neighbors







              if (i > 0) {







                DumpPool16Element(elemAddr - es); // preceding element







              }







              DumpPool16Element(elemAddr); // the element itself







              if (i + 1 < cap) {







                DumpPool16Element(elemAddr + es); // following element







              }















              // Dump slab header







              MCLA_LOG_WARN("  SLAB {:08X}: next={:08X} prev={:08X} count={} "







                            "freeHead={:08X} owner={:08X}",







                            curSlab, OomCensusReadU32(curSlab + 0),







                            OomCensusReadU32(curSlab + 4), slabCount,







                            slabFreeHead, OomCensusReadU32(curSlab + 16));















              spdlog::default_logger()->flush();







            }







          }







          break;







        }







      }







      // Element not in snapshot buffer (either too old or not from 16-byte







      // pool) — skip silently







    }















    curSlab = OomCensusReadU32(curSlab + 4);







    ++slabIdx;







  }







}







} // namespace















#ifdef MCLA_ALLOC_DEBUG







thread_local uint32_t t_prevPoolNode = 0; // per-thread: last returned node







thread_local uint32_t t_lastSlabHead =







    0; // head value after last pop on this thread







thread_local uint32_t t_lastSlabAddr =







    0; // slab addr of last pop on this thread







#endif









} // namespace















bool mcla_SlimTslabFind(uint32_t addr, uint32_t *outElem,







                        uint32_t *outCallerLr, uint32_t *outElemsize) {







  // Owner ring first: the sub_821C29A0 caller is the interesting producer.







  for (uint32_t i = 0; i < kTslabRecords; ++i) {







    const uint32_t elem =







        g_tslabOwners[i].elem.load(std::memory_order_relaxed);







    if (elem == 0 || addr < elem)







      continue;







    const uint32_t es = g_tslabOwners[i].es.load(std::memory_order_relaxed);







    if (addr < elem + es) {







      if (outElem)







        *outElem = elem;







      if (outCallerLr)







        *outCallerLr = g_tslabOwners[i].lr.load(std::memory_order_relaxed);







      if (outElemsize)







        *outElemsize = es;







      return true;







    }







  }







  for (uint32_t i = 0; i < kTslabRecords; ++i) {







    const uint32_t elem =







        g_tslabRecords[i].elem.load(std::memory_order_relaxed);







    if (elem == 0 || addr < elem)







      continue;







    const uint32_t es = g_tslabRecords[i].es.load(std::memory_order_relaxed);







    if (addr < elem + es) {







      if (outElem)







        *outElem = elem;







      if (outCallerLr)







        *outCallerLr =







            g_tslabRecords[i].lr.load(std::memory_order_relaxed);







      if (outElemsize)







        *outElemsize = es;







      return true;







    }







  }







  return false;







}















PPC_FUNC_IMPL(__imp__sub_821DE9D8);







PPC_FUNC(sub_821DE9D8) {







  if constexpr (!kPool16CensusEnabled) {







    const uint32_t classHead = ctx.r3.u32;







    const uint32_t heap = ctx.r4.u32;







    // Session 73: caller LR at entry = the guest code asking for the element.







    const uint32_t tslabLr = static_cast<uint32_t>(ctx.lr);







    // Live boot failure (2026-09-10 slab dump): freeCount=629, head=0 on







    // slab A0014000 while arena still had ~45 MiB free. Repair the phantom







    // freelist BEFORE the original allocator so it takes the refill path.







    if (classHead != 0) {







      (void)RepairCorruptedTinySlabFreeList(classHead);







    }







    __imp__sub_821DE9D8(ctx, base);







    // Safety net: if it still failed, dump state and try one more repair+retry.







    if (ctx.r3.u32 == 0 && classHead != 0) {







      LogDe9D8Oom(classHead, heap);







      if (RepairCorruptedTinySlabFreeList(classHead)) {







        ctx.r3.u32 = classHead;







        ctx.r4.u32 = heap;







        __imp__sub_821DE9D8(ctx, base);







      }







    }







    // Session 73 slim census: record who received which element.







    if (ctx.r3.u32 != 0 && classHead != 0) {







      const uint32_t node = ctx.r3.u32;







      uint16_t es16 = 0;







      mcla::kernel::GuestMemoryHeap::Instance().ReadU16BE(classHead + 4,







                                                          &es16);







      const uint32_t es = es16;







      const uint32_t idx = s_tslabAllocs.fetch_add(1) + 1;







      const uint32_t rec = g_tslabRecIdx.fetch_add(1) % kTslabRecords;







      g_tslabRecords[rec].elem.store(node, std::memory_order_relaxed);







      g_tslabRecords[rec].lr.store(tslabLr, std::memory_order_relaxed);







      g_tslabRecords[rec].es.store(es, std::memory_order_relaxed);







      const bool log = (es == 16)   ? (idx <= 100u || (idx % 4096u) == 0)







                       : (es <= 512u) ? (idx <= 20000u || (idx % 64u) == 0)







                                      : (idx <= 200u || (idx % 8u) == 0);







      if (log) {







        MCLA_LOG_WARN(







            "TSLAB-ALLOC #{:09} es={} elem={:08X} lr={:08X} ch={:08X}", idx,







            es, node, tslabLr, classHead);







      }







    }







    return;







  }















  const uint32_t classHead = ctx.r3.u32;







  const uint32_t heap = ctx.r4.u32;







  const uint32_t depthBefore = t_arenaDepth;















  // The live boot issue is a corrupted tiny-slab freelist: a count>0 slab can







  // still have a head pointer that points outside the slab body, which causes







  // an immediate return-0 even though the class still has free elements. Repair







  // the stale freelist before the original allocator sees it so boot can







  // continue.







  (void)RepairCorruptedTinySlabFreeList(classHead);















  // SESSION 47: capture slab-list head + first slab state BEFORE the allocator







  // runs.  If it differs after the allocator returns 0, another thread modified







  // the slab list during the allocator's execution.







  const uint32_t preAllocSlab = OomCensusReadU32(classHead + 0);







  uint32_t preAllocCount = 0, preAllocHead = 0;







  if (preAllocSlab != 0) {







    preAllocCount = OomCensusReadU32(preAllocSlab + 8);







    preAllocHead = OomCensusReadU32(preAllocSlab + 12);







  }















  // SESSION 47/49: walk ALL slabs for this classHead, check chain integrity.







  // Walk the chain from head and count elements. If chain length != count, the







  // chain is corrupted. Log every 8th call.







  {







    const uint32_t hw = OomCensusReadU32(classHead + 4);







    const uint32_t es = hw >> 16;







    const uint32_t cap = hw & 0xFFFFu;







    if (es > 0 && es <= 64 && cap > 0 && cap <= 4096 && preAllocSlab != 0) {







      static std::atomic<uint32_t> s_chainChecks{0};







      const uint32_t checkIdx = s_chainChecks.fetch_add(1);







      if (checkIdx % 8 == 0) {







        uint32_t curSlab = OomCensusReadU32(classHead + 0);







        while (curSlab != 0) {







          const uint32_t slabCount = OomCensusReadU32(curSlab + 8);







          const uint32_t slabHead = OomCensusReadU32(curSlab + 12);







          if (slabCount > 1 && slabHead != 0) {







            uint32_t chainLen = 0;







            uint32_t cur = slabHead;







            while (cur != 0 && chainLen <= cap * 2) {







              ++chainLen;







              cur = OomCensusReadU32(cur + 0);







            }







            if (chainLen != slabCount) {







              MCLA_LOG_WARN(







                  "POOL-CHAIN-BROKEN check={} slab={:08X} count={} chainLen={} "







                  "head={:08X} headNext={:08X} lr={:08X} tid={:08X}",







                  checkIdx, curSlab, slabCount, chainLen, slabHead,







                  OomCensusReadU32(slabHead + 0), static_cast<uint32_t>(ctx.lr),







                  static_cast<uint32_t>(GetCurrentThreadId()));







            } else {







              MCLA_LOG_WARN(







                  "CHAIN-OK check={} slab={:08X} count={} chainLen={} "







                  "head={:08X} headNext={:08X}",







                  checkIdx, curSlab, slabCount, chainLen, slabHead,







                  OomCensusReadU32(slabHead + 0));







            }







          }







          curSlab = OomCensusReadU32(curSlab + 4);







        }







      }







    }







  }















  // SESSION 49: Chain rebuild for the 16-byte pool (classHead 82830DB8).







  // Root cause: game code writes >16 bytes to 16-byte pool allocations,







  // overflowing into the adjacent element's freelist next pointer (at node+0 of







  // the next element). Since elements are packed at elemStride intervals, the







  // overflow corrupts the chain.







  //







  // Strategy: Walk ALL slabs for this classHead.  When a slab's freelist head's







  // next







  //   pointer is outside the slab data area, the chain is broken.  Attempt to







  //   scan all elements for 0xDD free pattern; if that fails (game overwrites







  //   freed memory), reset count+head to 0.  The allocator handles count=0 by







  //   creating fresh slabs. This loses ~632 free elements per corrupted slab







  //   but prevents OOM.







  {







    const uint32_t hw49 = OomCensusReadU32(classHead + 4);







    const uint32_t es49 = hw49 >> 16;







    const uint32_t cap49 = hw49 & 0xFFFFu;















    if (es49 > 0 && es49 <= 64 && cap49 > 0 && cap49 <= 4096) {







      uint32_t curSlab49 = OomCensusReadU32(classHead + 0);







      while (curSlab49 != 0) {







        const uint32_t cnt49 = OomCensusReadU32(curSlab49 + 8);







        const uint32_t hd49 = OomCensusReadU32(curSlab49 + 12);















        if (cnt49 > 0 && hd49 != 0) {







          const uint32_t hdNext49 = OomCensusReadU32(hd49 + 0);







          if (hdNext49 != 0 &&







              (hdNext49 < curSlab49 + 32 || hdNext49 >= curSlab49 + 16384)) {







            auto &mem49 = mcla::kernel::GuestMemoryHeap::Instance();







            uint32_t newHead49 = 0;







            uint32_t newCount49 = 0;















            for (uint32_t i49 = 0; i49 < cap49; i49++) {







              const uint32_t eAddr49 = curSlab49 + 32 + i49 * es49;







              if (ElementLooksFree(eAddr49, es49)) {







                (void)mem49.WriteU32BE(eAddr49 + 0, newHead49);







                newHead49 = eAddr49;







                newCount49++;







              }







            }















            (void)mem49.WriteU32BE(curSlab49 + 12, newHead49);







            (void)mem49.WriteU32BE(curSlab49 + 8, newCount49);















            MCLA_LOG_WARN("POOL-CHAIN-REBUILT slab={:08X} es={} cap={} "







                          "oldCount={} newCount={} head={:08X} lr={:08X}",







                          curSlab49, es49, cap49, cnt49, newCount49, newHead49,







                          static_cast<uint32_t>(ctx.lr));















            // Update preAlloc* if this was the first slab







            if (curSlab49 == preAllocSlab) {







              preAllocCount = newCount49;







              preAllocHead = newHead49;







            }







          }







        }















        curSlab49 = OomCensusReadU32(curSlab49 + 4);







      }







    }







  }















#ifdef MCLA_ALLOC_DEBUG







  // SESSION 39 WRITE-WATCH: capture pre-pop head state before the original







  // runs, so we can detect (a) head-reset between pops and (b) interleaved







  // writes by another thread.







  // classHead+4 layout (big-endian): halfword at +4 = elem stride, halfword at







  // +6 = capacity 32-bit read at +4: upper16 = lhz(+4) = elem stride, lower16 =







  // lhz(+6) = capacity







  const uint32_t preHeadWord = OomCensusReadU32(classHead + 4);







  const uint32_t preElemsize =







      preHeadWord >> 16; // lhz(classHead+4) = element stride







  uint32_t preSlab = 0, preHead = 0, preCount = 0;







  bool watchElemsize4 = (preElemsize == 4);







  if (watchElemsize4) {







    preSlab = OomCensusReadU32(classHead + 0);







    if (preSlab != 0) {







      preHead = OomCensusReadU32(preSlab + 12);







      preCount = OomCensusReadU32(preSlab + 8);







      if (t_lastSlabAddr == preSlab && t_lastSlabHead != 0 &&







          preHead != t_lastSlabHead && preHead != 0) {







        MCLA_LOG_WARN("WRITE-WATCH HEAD-RESET slab={:08X} lastHead={:08X} "







                      "nowHead={:08X} count={} tid={:08X}",







                      preSlab, t_lastSlabHead, preHead, preCount,







                      static_cast<uint32_t>(GetCurrentThreadId()));







      }







    }







  }







#endif















  __imp__sub_821DE9D8(ctx, base);















  if (ctx.r3.u32 != 0) {







    const uint32_t node = ctx.r3.u32;







    const uint32_t slab = node & ~0x3FFFu;







    const uint32_t headWord = OomCensusReadU32(classHead + 4);







    const uint32_t elemsize = headWord >> 16;     // lhz(+4) = elem stride







    const uint32_t capacity = headWord & 0xFFFFu; // lhz(+6) = nodes per slab















    // SESSION 52: 16-byte pool writer-attribution census.







    // Track EVERY allocation from the 16-byte pool (elemsize=16, capacity=1018)







    // with full caller context (LR, stack, TLS) to identify who later overflows







    // the 16-byte elements. The overflow root cause is a write >16 bytes into







    // these nodes - we need to know who allocates them and where from.







    const uint32_t a = s_allocCensus.fetch_add(1) + 1;







    if (elemsize == 16 && capacity == 1018) {














      const uint32_t allocIdx = a;







      const uint32_t sp = ctx.r1.u32;







      const uint32_t bc = OomCensusReadU32(sp);















      // Capture caller LR and stack frame







      const uint32_t allocLr = static_cast<uint32_t>(ctx.lr);















      // Walk back chain for caller context







      uint32_t callerBC = 0, callerLR = 0, callerR28 = 0, callerR29 = 0;







      if (bc != 0) {







        callerBC = OomCensusReadU32(bc);







        callerLR = OomCensusReadU32(bc + 8);







        callerR29 = OomCensusReadU32(bc + 36); // heap







        callerR28 = OomCensusReadU32(bc + 40); // node







      }















      // Resolve TLS[28] → object → vtable → vtable[3] for type identification







      const uint32_t tlsBase = OomCensusReadU32(ctx.r13.u32);







      const uint32_t tlsObj =







          (tlsBase != 0) ? OomCensusReadU32(tlsBase + 28) : 0;







      const uint32_t vtable = (tlsObj != 0) ? OomCensusReadU32(tlsObj) : 0;







      const uint32_t vfunc3 = (vtable != 0) ? OomCensusReadU32(vtable + 12) : 0;















      // Log EVERY 16-byte pool allocation for first 2000, then every 100th







      const bool denseAllocLog = (allocIdx <= 2000u) || (allocIdx % 100u == 0u);







      if (denseAllocLog) {







        MCLA_LOG_WARN(







            "POOL16-ALLOC #{} classHead={:08X} node={:08X} slab={:08X} "







            "lr={:08X} sp={:08X} bc={:08X} callerLR={:08X} callerBC={:08X} "







            "callerR28={:08X} callerR29={:08X} tlsObj={:08X} vtable={:08X} "







            "vfunc3={:08X} "







            "r3={:08X} r4={:08X} r5={:08X} r6={:08X} r7={:08X} r8={:08X} "







            "r9={:08X} r10={:08X}",







            allocIdx, classHead, node, slab, allocLr, sp, bc, callerLR,







            callerBC, callerR28, callerR29, tlsObj, vtable, vfunc3, ctx.r3.u32,







            ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32,







            ctx.r9.u32, ctx.r10.u32);







        spdlog::default_logger()->flush();







      }















      // Also write to raw file for crash-resilient attribution







      {







        static int s_fd16 = -1;







        if (s_fd16 < 0) {







          _sopen_s(&s_fd16, "cache/pool16_writers.log",







                   _O_WRONLY | _O_CREAT | _O_APPEND, _SH_DENYNO,







                   _S_IREAD | _S_IWRITE);







        }







        if (s_fd16 >= 0) {







          char buf[384];







          const int len = snprintf(







              buf, sizeof(buf),







              "#%u classHead=%08X node=%08X slab=%08X lr=%08X sp=%08X bc=%08X "







              "callerLR=%08X callerBC=%08X callerR28=%08X callerR29=%08X "







              "tlsObj=%08X vtable=%08X vfunc3=%08X r3=%08X r4=%08X r5=%08X "







              "r6=%08X r7=%08X r8=%08X r9=%08X r10=%08X\n",







              allocIdx, classHead, node, slab, allocLr, sp, bc, callerLR,







              callerBC, callerR28, callerR29, tlsObj, vtable, vfunc3,







              ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,







              ctx.r8.u32, ctx.r9.u32, ctx.r10.u32);







          _write(s_fd16, buf, len);







          _commit(s_fd16);







        }







      }















      // SESSION 55 B3: Snapshot this allocation for writer-attribution.







      // Store the element address, first 4 bytes (snapshot), caller LR, and







      // allocation index. Used by ScanPool16SlabsForOverflow to detect when







      // an element's content changes after allocation (overflow signature).







      {







        const uint32_t snapIdx = g_pool16SnapIdx.fetch_add(1);







        const uint32_t slot = snapIdx % kPool16MaxSnapshots;







        auto &mem16 = mcla::kernel::GuestMemoryHeap::Instance();







        uint32_t first4 = 0;







        mem16.ReadU32BE(node + 0, &first4);







        g_pool16Snapshots[slot] = {node, first4, allocLr, allocIdx};







      }















      // Periodic full slab scan: every 500th 16-byte pool allocation, walk







      // ALL slabs and compare every allocated element against its snapshot.







      // This catches overflow that occurred on any element, not just at free







      // time. The scan is expensive (~200K element reads) but rare enough







      // to not impact boot time significantly.







      {







        const uint32_t scanN = g_pool16ScanCount.fetch_add(1);







        if (scanN > 0 && scanN % 500 == 0) {







          MCLA_LOG_WARN("POOL16-SCAN trigger=alloc#{} scanning all slabs...",







                        allocIdx);







          ScanPool16SlabsForOverflow(allocIdx);







          spdlog::default_logger()->flush();







        }







      }







    }















    if (a <= 16 || a % 4096 == 0) {







      const uint32_t sp = ctx.r1.u32;







      const uint32_t bc = OomCensusReadU32(sp);







      MCLA_LOG_WARN("POOL-ALLOC #{} classHead={:08X} node={:08X} slab={:08X} "







                    "elemsize={} capacity={} sp={:08X} bc={:08X} lr={:08X}",







                    a, classHead, node, slab, elemsize, capacity, sp, bc,







                    static_cast<uint32_t>(ctx.lr));







    }







    // SESSION 47: check for desync after EVERY successful pop.







    // The allocator just popped from a slab — verify count and freelist







    // are consistent. Log every pop for the first 512, then only desyncs.







    {







      const uint32_t node = ctx.r3.u32;







      const uint32_t slab = node & ~0x3FFFu;







      const uint32_t countAfter = OomCensusReadU32(slab + 8);







      const uint32_t headAfter = OomCensusReadU32(slab + 12);







      const uint32_t k = s_poolPops.fetch_add(1) + 1;







      const bool desync = (headAfter == 0) && (countAfter != 0);















      // SESSION 48: for the 16-byte pool, check if the new head's next







      // pointer is within the slab data area.  If not, the chain is corrupted.







      const uint32_t hw = OomCensusReadU32(classHead + 4);







      if ((hw >> 16) == 16 && (hw & 0xFFFF) == 1018 && headAfter != 0) {







        const uint32_t headNext = OomCensusReadU32(headAfter + 0);







        if (headNext != 0 &&







            (headNext < slab + 32 || headNext >= slab + 16384)) {







          MCLA_LOG_WARN("POOL-CORRUPT-NEXT #{} node={:08X} slab={:08X} "







                        "headAfter={:08X} headNext={:08X} OUT-OF-SLAB "







                        "lr={:08X} tid={:08X}",







                        k, node, slab, headAfter, headNext,







                        static_cast<uint32_t>(ctx.lr),







                        static_cast<uint32_t>(GetCurrentThreadId()));







        }







        // Also check: head valid but next==0 while count>1 means chain







        // truncated







        if (headNext == 0 && countAfter > 1) {







          MCLA_LOG_WARN("POOL-CHAIN-TRUNC #{} node={:08X} slab={:08X} "







                        "count={} headAfter={:08X} lr={:08X} tid={:08X}",







                        k, node, slab, countAfter, headAfter,







                        static_cast<uint32_t>(ctx.lr),







                        static_cast<uint32_t>(GetCurrentThreadId()));







        }







      }















      if (k <= 512 || desync) {







        MCLA_LOG_WARN(







            "POOL-POP #{} node={:08X} slab={:08X} count={} head={:08X} "







            "preSlab={:08X} preCount={} preHead={:08X} lr={:08X} "







            "tid={:08X}{}",







            k, node, slab, countAfter, headAfter, preAllocSlab, preAllocCount,







            preAllocHead, static_cast<uint32_t>(ctx.lr),







            static_cast<uint32_t>(GetCurrentThreadId()),







            desync ? " DESYNC" : "");







      }







    }







#ifdef MCLA_ALLOC_DEBUG







    const uint32_t node = ctx.r3.u32;







    const uint32_t slab = node & ~0x3FFFu;







    const uint32_t countAfter = OomCensusReadU32(slab + 8);







    const uint32_t nextAfter = OomCensusReadU32(slab + 12);







    const uint32_t k = s_poolPops.fetch_add(1) + 1;







    const bool desync = (nextAfter == 0) && (countAfter != 0);







    const bool repeat = (node == t_prevPoolNode);















    if (watchElemsize4 && preSlab != 0 && preSlab == slab) {







      const bool headDidntAdvance = (nextAfter == preHead) && (preHead != 0);







      if (headDidntAdvance) {







        MCLA_LOG_WARN("WRITE-WATCH NO-ADVANCE #{} node={:08X} slab={:08X} "







                      "preHead={:08X} postHead={:08X} count={}->{} lr={:08X} "







                      "tid={:08X}",







                      k, node, slab, preHead, nextAfter, preCount, countAfter,







                      static_cast<uint32_t>(ctx.lr),







                      static_cast<uint32_t>(GetCurrentThreadId()));







      }







      if (nextAfter != 0 &&







          (nextAfter < slab + 32 || nextAfter >= slab + 16384)) {







        MCLA_LOG_WARN("WRITE-WATCH CORRUPT-NEXT #{} node={:08X} slab={:08X} "







                      "nextAfter={:08X} OUT-OF-SLAB lr={:08X} tid={:08X}",







                      k, node, slab, nextAfter, static_cast<uint32_t>(ctx.lr),







                      static_cast<uint32_t>(GetCurrentThreadId()));







      }







      t_lastSlabHead = nextAfter;







      t_lastSlabAddr = slab;







    }















    if (k <= 512 || desync || repeat) {







      MCLA_LOG_WARN("POOL-POP #{} node={:08X} slab={:08X} countAfter={} "







                    "nextAfter={:08X} lr={:08X} r13={:08X} tid={:08X}{}{}",







                    k, node, slab, countAfter, nextAfter,







                    static_cast<uint32_t>(ctx.lr),







                    static_cast<uint32_t>(ctx.r13.u32),







                    static_cast<uint32_t>(GetCurrentThreadId()),







                    desync ? " DESYNC" : "", repeat ? " REPEAT" : "");







    }







    t_prevPoolNode = node;







#endif







    return;







  }















  const uint32_t failIdx = s_poolFailures.fetch_add(1) + 1;







  s_poolCensus.fetch_add(1);







  const bool refilled = (t_arenaDepth != depthBefore);















  // SESSION 37: log EVERY return-0 (no sampling) for slab corruption







  // root-cause. classHead+4 layout: upper16 = lhz(+4) = elem stride, lower16 =







  // lhz(+6) = capacity







  const uint32_t headWord = OomCensusReadU32(classHead + 4);







  const uint32_t elemsize = headWord >> 16;         // lhz(+4) = element stride







  const uint32_t nodesPerSlab = headWord & 0xFFFFu; // lhz(+6) = capacity







  const uint32_t headSlab = OomCensusReadU32(classHead + 0);















  // SESSION 37: walk ALL slabs and dump every one's state.







  // Slab layout: +0=next-newer, +4=prev-older, +8=count, +12=freelist,







  // +16=owner For each slab with count!=0, also walk the freelist to get chain







  // length.







  uint32_t totalSlabs = 0, totalFree = 0, slabsWithFree = 0;







  uint32_t firstNonZeroSlab = 0, firstNonZeroCount = 0,







           firstNonZeroFreelist = 0, firstNonZeroChainLen = 0;







  uint32_t curSlab = headSlab;







  while (curSlab != 0 && totalSlabs < 32) {







    const uint32_t sNext = OomCensusReadU32(curSlab + 0);







    const uint32_t sPrev = OomCensusReadU32(curSlab + 4);







    const uint32_t sCount = OomCensusReadU32(curSlab + 8);







    const uint32_t sFree = OomCensusReadU32(curSlab + 12);







    const uint32_t sOwner = OomCensusReadU32(curSlab + 16);















    uint32_t chainLen = 0;







    if (sCount != 0) {







      ++slabsWithFree;







      totalFree += sCount;







      uint32_t cur = sFree;







      while (cur != 0 && chainLen < 4096) {







        ++chainLen;







        cur = OomCensusReadU32(cur + 0);







      }







      if (firstNonZeroSlab == 0) {







        firstNonZeroSlab = curSlab;







        firstNonZeroCount = sCount;







        firstNonZeroFreelist = sFree;







        firstNonZeroChainLen = chainLen;







      }







    }















    MCLA_LOG_WARN(







        "POOL-CENSUS FAIL#{} SLAB[{}] slab={:08X} next={:08X} prev={:08X} "







        "count={} freelist={:08X} owner={:08X} chainLen={}",







        failIdx, totalSlabs, curSlab, sNext, sPrev, sCount, sFree, sOwner,







        chainLen);















    curSlab = sNext;







    ++totalSlabs;







  }















  MCLA_LOG_WARN("POOL-CENSUS FAIL#{} {} classHead={:08X} heap={:08X} "







                "elemsize={} capacity={}: "







                "headSlab={:08X} totalSlabs={} slabsWithFree={} totalFree={} "







                "preSlab={:08X} preCount={} preHead={:08X} lr={:08X}",







                failIdx, refilled ? "REFILLFAIL" : "NOREFILL", classHead, heap,







                elemsize, nodesPerSlab, headSlab, totalSlabs, slabsWithFree,







                totalFree, preAllocSlab, preAllocCount, preAllocHead,







                static_cast<uint32_t>(ctx.lr));















  // SESSION 37: diagnostic summary for first slab with count!=0







  if (firstNonZeroSlab != 0) {







    MCLA_LOG_WARN("POOL-CENSUS FAIL#{} FIRST-NONZERO slab={:08X} count={} "







                  "freelist={:08X} "







                  "chainLen={} countMatch={}",







                  failIdx, firstNonZeroSlab, firstNonZeroCount,







                  firstNonZeroFreelist, firstNonZeroChainLen,







                  firstNonZeroChainLen == firstNonZeroCount ? "YES" : "NO");







  }















  // SESSION 47: compare pre/post slab state. If the allocator saw different







  // state than what we read after, another thread modified the slab list.







  const uint32_t postAllocSlab = OomCensusReadU32(classHead + 0);







  if (preAllocSlab != postAllocSlab) {







    MCLA_LOG_WARN("POOL-CENSUS SLAB-CHANGED classHead={:08X} preSlab={:08X} "







                  "postSlab={:08X} preCount={} preHead={:08X}",







                  classHead, preAllocSlab, postAllocSlab, preAllocCount,







                  preAllocHead);







  } else if (preAllocSlab != 0 && preAllocCount == 0 && firstNonZeroCount > 0) {







    MCLA_LOG_WARN("POOL-CENSUS COUNT-JUMP classHead={:08X} slab={:08X} "







                  "preCount=0 postCount={} preHead={:08X} postHead={:08X}",







                  classHead, preAllocSlab, firstNonZeroCount, preAllocHead,







                  firstNonZeroFreelist);







  }







}















// ---------------------------------------------------------------------------







// SESSION 37 STEP 2b: push-back consistency census on sub_821DE908(slab,







// node, heap) - the pool-node free (routes from sub_821C2AB8 when the slab







// bitmap bit is set). A node outside [slab+32, slab+32 + n*elemsize) or not







// on an element boundary means a stale/foreign pointer is being pushed into







// the class freelist - the leading root-cause candidate for the count vs







// freelist desync. CENSUS ONLY, passthrough, checked BE reads.







// ---------------------------------------------------------------------------







namespace {







std::atomic<uint32_t> s_poolFreeFrees{0};







std::atomic<uint32_t> s_poolFreeAnomalies{0};







} // namespace















PPC_FUNC_IMPL(__imp__sub_821DE908);







PPC_FUNC(sub_821DE908) {







  if constexpr (!kPool16CensusEnabled) {







    __imp__sub_821DE908(ctx, base);







    return;







  }















  const uint32_t slab = ctx.r3.u32;







  const uint32_t node = ctx.r4.u32;







  const uint32_t caller_lr = static_cast<uint32_t>(ctx.lr);







  const uint32_t sp = ctx.r1.u32;







  const uint32_t countBefore = OomCensusReadU32(slab + 8);







  const uint32_t freeHeadBefore = OomCensusReadU32(slab + 12);















  // sp is sub_821C2AB8's stack (after its stwu r1,-112(r1)):







  //   sp+0   = back chain (sub_821C09C8's sp after its stwu r1,-128(r1))







  //   sp+80  = lock object area







  //   sp+88  = saved r30







  //   sp+96  = saved r31







  //   sp+104 = saved LR (return to sub_821C09C8)







  const uint32_t backChain = OomCensusReadU32(sp);







  const uint32_t savedR30 = OomCensusReadU32(sp + 88);







  const uint32_t savedR31 = OomCensusReadU32(sp + 96);







  const uint32_t savedLR = OomCensusReadU32(sp + 104);







  // Walk up to sub_821C09C8's frame:







  //   backChain+0 = back chain (game caller's sp)







  //   backChain+8 = saved LR (game caller's return address, security cookie







  //   pattern) backChain+36 = r29 (heap) backChain+40 = r28 (node passed to







  //   sub_821C09C8)







  const uint32_t callerBC = OomCensusReadU32(backChain);







  const uint32_t callerLR = OomCensusReadU32(backChain + 8);







  const uint32_t callerR29 = OomCensusReadU32(backChain + 36);







  const uint32_t callerR28 = OomCensusReadU32(backChain + 40);















  // SESSION 47: log pre-free state for the failing pool (classHead 82830DB8).







  // If freelist is already 0 before the free, the slab is pre-corrupted.







  {







    const uint32_t owner = OomCensusReadU32(slab + 16);







    const uint32_t hw = OomCensusReadU32(owner + 4);







    const uint32_t es = hw >> 16;







    const uint32_t cap = hw & 0xFFFFu;







    if (es == 16 && cap == 1018 && freeHeadBefore == 0 && countBefore > 0) {







      MCLA_LOG_WARN("POOL-FREE-PRE-DESINCRONIZED slab={:08X} node={:08X} "







                    "countBefore={} freeHeadBefore={:08X} lr={:08X} tid={:08X}",







                    slab, node, countBefore, freeHeadBefore, caller_lr,







                    static_cast<uint32_t>(GetCurrentThreadId()));







    }







  }















  // SESSION 55 B3: Writer-attribution corruption check at free time.







  // Compare the element's first 4 bytes against the allocation snapshot.







  // If they differ, the element was overwritten after allocation — overflow







  // from the preceding element or a direct overwrite. Must run BEFORE the







  // original free (which overwrites [node+0] with the freelist next-pointer).







  {







    const uint32_t owner = OomCensusReadU32(slab + 16);







    const uint32_t hw = OomCensusReadU32(owner + 4);







    const uint32_t es = hw >> 16;







    const uint32_t cap = hw & 0xFFFFu;







    if (es == 16 && cap == 1018) {







      const uint32_t curFirst4 = OomCensusReadU32(node + 0);







      // Search snapshot for this element







      const uint32_t snapIdx = g_pool16SnapIdx.load(std::memory_order_relaxed);







      const uint32_t searchCount = std::min(snapIdx, kPool16MaxSnapshots);







      for (uint32_t s = 0; s < searchCount; ++s) {







        if (g_pool16Snapshots[s].elemAddr == node) {







          if (g_pool16Snapshots[s].first8bytes != curFirst4) {







            const uint32_t corruptN = g_pool16CorruptionCount.fetch_add(1) + 1;







            if (corruptN <= 64) {







              auto &memFC = mcla::kernel::GuestMemoryHeap::Instance();







              uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;







              memFC.ReadU32BE(node + 0, &w0);







              memFC.ReadU32BE(node + 4, &w1);







              memFC.ReadU32BE(node + 8, &w2);







              memFC.ReadU32BE(node + 12, &w3);















              const uint32_t elemIdx = (node - (slab + 32)) / es;







              MCLA_LOG_WARN(







                  "POOL16-FREE-CORRUPT #{} node={:08X} slab={} elemIdx={} "







                  "snapFirst4={:08X} curFirst4={:08X} snapLR={:08X} "







                  "snapAllocIdx={} freeLR={:08X} freeTid={:08X} "







                  "ELEM: {:08X} {:08X} {:08X} {:08X}",







                  corruptN, node, slab, elemIdx,







                  g_pool16Snapshots[s].first8bytes, curFirst4,







                  g_pool16Snapshots[s].callerLR, g_pool16Snapshots[s].allocIdx,







                  caller_lr, static_cast<uint32_t>(GetCurrentThreadId()), w0,







                  w1, w2, w3);















              // Dump preceding and following elements for context







              if (elemIdx > 0) {







                uint32_t pw0 = 0, pw1 = 0, pw2 = 0, pw3 = 0;







                const uint32_t prevAddr = node - es;







                memFC.ReadU32BE(prevAddr + 0, &pw0);







                memFC.ReadU32BE(prevAddr + 4, &pw1);







                memFC.ReadU32BE(prevAddr + 8, &pw2);







                memFC.ReadU32BE(prevAddr + 12, &pw3);







                MCLA_LOG_WARN("  PREV  {:08X}: {:08X} {:08X} {:08X} {:08X}",







                              prevAddr, pw0, pw1, pw2, pw3);







              }







              if (elemIdx + 1 < cap) {







                uint32_t nw0 = 0, nw1 = 0, nw2 = 0, nw3 = 0;







                const uint32_t nextAddr = node + es;







                memFC.ReadU32BE(nextAddr + 0, &nw0);







                memFC.ReadU32BE(nextAddr + 4, &nw1);







                memFC.ReadU32BE(nextAddr + 8, &nw2);







                memFC.ReadU32BE(nextAddr + 12, &nw3);







                MCLA_LOG_WARN("  NEXT  {:08X}: {:08X} {:08X} {:08X} {:08X}",







                              nextAddr, nw0, nw1, nw2, nw3);







              }















              spdlog::default_logger()->flush();







            }







          }







          break;







        }







      }







    }







  }















  __imp__sub_821DE908(ctx, base);















  // classHead+4 layout: upper16 = lhz(+4) = elem stride, lower16 = lhz(+6) =







  // capacity







  const uint32_t owner = OomCensusReadU32(slab + 16);







  const uint32_t headWord = OomCensusReadU32(owner + 4);







  const uint32_t elemsize = headWord >> 16;         // lhz(+4) = element stride







  const uint32_t nodesPerSlab = headWord & 0xFFFFu; // lhz(+6) = capacity







  const uint32_t countAfter = OomCensusReadU32(slab + 8);







  const uint32_t freeHeadAfter = OomCensusReadU32(slab + 12);















  bool inside = false;







  if (elemsize != 0 && nodesPerSlab != 0) {







    const uint32_t lo = slab + 32;







    const uint32_t span = nodesPerSlab * elemsize;







    const uint32_t off = node - lo;







    inside = (node >= lo) && (off < span) && ((off % elemsize) == 0);







  }















  // SESSION 47: always log when freelist is zeroed despite count > 0 after a







  // free — this is the signature of the count-vs-freelist desync.







  if (inside && freeHeadAfter == 0 && countAfter > 0) {







    MCLA_LOG_WARN("POOL-FREE-FREELIST-ZERO slab={:08X} node={:08X} elemsize={} "







                  "countAfter={} freeHeadBefore={:08X} freeHeadAfter={:08X} "







                  "lr={:08X} tid={:08X}",







                  slab, node, elemsize, countAfter, freeHeadBefore,







                  freeHeadAfter, caller_lr,







                  static_cast<uint32_t>(GetCurrentThreadId()));







  }







  // SESSION 47: also log when freeHeadAfter != node (unexpected — the free







  // function should set freelist_head = node just freed)







  if (inside && freeHeadAfter != node && freeHeadAfter != 0) {







    MCLA_LOG_WARN("POOL-FREE-HEAD-MISMATCH slab={:08X} node={:08X} elemsize={} "







                  "countAfter={} freeHeadBefore={:08X} freeHeadAfter={:08X} "







                  "lr={:08X} tid={:08X}",







                  slab, node, elemsize, countAfter, freeHeadBefore,







                  freeHeadAfter, caller_lr,







                  static_cast<uint32_t>(GetCurrentThreadId()));







  }















  if (inside) {







    return;







  }















  const uint32_t a = s_poolFreeAnomalies.fetch_add(1) + 1;







  s_poolFreeFrees.fetch_add(1);







  if (a <= 128 || a % 256 == 0) {







    const uint32_t off = (elemsize != 0) ? (node - (slab + 32)) : 0;







    MCLA_LOG_WARN(







        "POOL-FREE-ANOMALY #{} slab={:08X} node={:08X} elemsize={} n={} "







        "countBefore={} countAfter={} off={} "







        "freeHeadBefore={:08X} freeHeadAfter={:08X} "







        "savedLR={:08X} callerLR={:08X} callerBC={:08X} "







        "callerR28={:08X} callerR29={:08X} "







        "r30={:08X} r31={:08X}",







        a, slab, node, elemsize, nodesPerSlab, countBefore, countAfter, off,







        freeHeadBefore, freeHeadAfter, savedLR, callerLR, callerBC, callerR28,







        callerR29, savedR30, savedR31);







  }







}















// SESSION 44c: census on sub_821C09C8 — the dispatch function that routes







// pool frees. Logs r3 (heap), r4 (node), and reads the caller's stack.







namespace {







std::atomic<uint32_t> s_routerCensus{0};







} // namespace















PPC_FUNC_IMPL(__imp__sub_821C09C8);







PPC_FUNC(sub_821C09C8) {







  if constexpr (!kPool16CensusEnabled) {







    __imp__sub_821C09C8(ctx, base);







    return;







  }















  const uint32_t heap = ctx.r3.u32;







  const uint32_t node = ctx.r4.u32;







  const uint32_t lr = static_cast<uint32_t>(ctx.lr);







  const uint32_t sp = ctx.r1.u32;















  const uint32_t backChain = OomCensusReadU32(sp);















  const uint32_t n = s_routerCensus.fetch_add(1) + 1;







  if (n <= 16 || n % 2048 == 0) {







    const uint32_t c0 = OomCensusReadU32(backChain);







    const uint32_t c1 = OomCensusReadU32(backChain + 4);







    const uint32_t c2 = OomCensusReadU32(backChain + 8);







    const uint32_t c3 = OomCensusReadU32(backChain + 12);















    // Resolve TLS[28] → object → vtable → vtable[3] to find the actual caller







    const uint32_t tlsBase = OomCensusReadU32(ctx.r13.u32);







    const uint32_t tlsObj = (tlsBase != 0) ? OomCensusReadU32(tlsBase + 28) : 0;







    const uint32_t vtable = (tlsObj != 0) ? OomCensusReadU32(tlsObj) : 0;







    const uint32_t vfunc3 = (vtable != 0) ? OomCensusReadU32(vtable + 12) : 0;















    MCLA_LOG_WARN(







        "POOL-ROUTER #{} heap={:08X} node={:08X} lr={:08X} sp={:08X} "







        "bc={:08X} c0={:08X} c1={:08X} c2={:08X} c3={:08X} "







        "r5={:08X} r6={:08X} r7={:08X} r8={:08X} r9={:08X} r10={:08X} "







        "tlsObj={:08X} vtable={:08X} vfunc3={:08X}",







        n, heap, node, lr, sp, backChain, c0, c1, c2, c3,







        static_cast<uint32_t>(ctx.r5.u32), static_cast<uint32_t>(ctx.r6.u32),







        static_cast<uint32_t>(ctx.r7.u32), static_cast<uint32_t>(ctx.r8.u32),







        static_cast<uint32_t>(ctx.r9.u32), static_cast<uint32_t>(ctx.r10.u32),







        tlsObj, vtable, vfunc3);







  }















  __imp__sub_821C09C8(ctx, base);







}


























