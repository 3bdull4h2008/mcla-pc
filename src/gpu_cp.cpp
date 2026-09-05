#include "gpu_cp.h"

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "guest_memory.h"
#include "kernel/memory.h"
#include "logging.h"
#include <cpu/ppc_context.h>


#include <atomic>
#include <cstdlib>
#include <mutex>
#include <thread>
#include <vector>

namespace mcla::gpu {

namespace {

// XGPU register window (Xenia: GraphicsSystem::Initialize maps phys
// 0x7FC80000..0x7FC8FFFF, register index = offset/4).
constexpr uint32_t kMmioBase = 0x7FC80000u;
constexpr uint32_t kMmioSize = 0x00010000u;
constexpr uint32_t kMmioMask = 0xFFFF0000u;

// CP_RB_WPTR: the ring doorbell. Guest stores the new write-pointer dword
// index here (verified guest site: ppc_recomp.77.cpp store to base+1812).
constexpr uint32_t kWptrByteOffset = 0x01C5u * 4u; // 0x714

// Xenia treats this value as "no doorbell rung yet".
constexpr uint32_t kWptrSentinel = 0xBAADF00Du;

// Register-file shadow over the 64 KB MMIO window (xenia persists writes and
// serves unhandled reads from it, graphics_system.cc:207-223).
constexpr size_t kMmioRegCount = kMmioSize / 4u;
std::atomic<uint32_t> g_regShadow[kMmioRegCount]{};

// Type-3 opcodes we give special treatment (values per xenia gpu/xenos.h).
constexpr uint32_t kPm4XeSwap = 0x64; // Xenia-invented swap packet

// ---------------------------------------------------------------------------
// Per-ring state (2026-08-25). Replaces the former singleton descriptor
// {g_ringBase, g_ringCapDwords, g_rptrIndex, g_writebackAddr}.
//
// Guest ring identity = EXACT (baseGuestVA, capacityDwords) pair as passed to
// VdInitializeRingBuffer. Never keyed by writeback address or capacity alone.
//
// Runtime evidence (build/cache/mcla.log 00:51:22.789 + generated
// ppc_recomp.77.cpp:23344-23377): the guest's only genuine registration is
// sub_82412198: init(MmGetPhysicalAddress(ring), log2) followed by
// enableWB(phys(dev[+10896]ctx + 60), blockLog2). The write-back address is a
// PHYSICAL address (< 0x20001000); guest waiters poll the same word through
// its kernel-VA alias PA | 0xC0000000 (= C701C4BC for PA 0701C4BC). We store
// both forms and publish to the VA form - that is where guest memory lives.
struct RingState {
  // Identity (immutable after creation).
  uint32_t baseGuestVA = 0;
  uint32_t capDwords = 0;

  // Stable diagnostic name ("A", "B", ... assigned at creation).
  char id = '?';

  std::atomic<uint32_t> rptrIndex{0}; // read pointer, dword index
  std::atomic<uint32_t> lastDoorbellWptr{0xFFFFFFFFu}; // newest accepted wptr
  std::atomic<uint32_t> writebackVA{0};  // publish target (guest-VA form)
  std::atomic<uint32_t> writebackRaw{0}; // exactly what the caller passed
  std::atomic<bool> initialized{false};
  std::atomic<bool> writebackEnabled{false};
  std::atomic<bool> draining{false}; // single-drain guard per ring

  uint64_t EndByte() const { return baseGuestVA + uint64_t(capDwords) * 4u; }
};

constexpr size_t kMaxRings = 4;
constexpr uint32_t kInvalidSlot = 0xFFFFFFFFu;
RingState g_rings[kMaxRings];
std::mutex g_ringMutex; // guards registry structure (create/bind)
std::atomic<uint32_t> g_primarySlot{
    kInvalidSlot};                     // doorbell target (most recent init/WB)
std::atomic<uint32_t> g_nextRingId{0}; // 'A', 'B', ...

std::atomic<uint32_t> g_pushWatermark{0}; // consumed-through VA (driver space)
std::atomic<uint32_t> g_progressBlk{0}; // submitting thread's *(r13+256) block

// ---------------------------------------------------------------------------
// DIAGNOSTIC deferred-consumption experiment (2026-08-25).
// Default OFF: cp_deferred_consume_experiment=1 enables. When OFF, every
// path below is byte-for-byte the pre-experiment behavior.
//
// Problem being tested (mcla_perring.log 08:01 run): CaptureWindow credited
// window consumption at RESERVE time (KICK #2 pc 40 -> 131133 in one call),
// so by fence-creation time zero backlog remained and F98's delta stayed 0
// forever. On HW the kernel CP drains submitted work ASYNCHRONOUSLY after
// the kick; F98's delta>=5000 measures exactly that outstanding drain.
//
// Cursors kept strictly separate:
//   producedEnd  - driver-space endVA through which the guest has SUBMITTED
//                  (fed by reservations; cross-checked vs GPU_ctx+0x30)
//   consumedEnd  - driver-space endVA the host consumer has accounted
//   g_pushWatermark - guest-visible consumed watermark (pub mirrors)
//   XTEB+0x58    - per-thread progress, advanced ONLY by real consumption
// ---------------------------------------------------------------------------
struct PendingConsume {
  uint32_t startVA;
  uint32_t endVA;
  uint32_t dwords;
};
std::mutex g_pendingMutex;
std::vector<PendingConsume> g_pendingWindows;
std::atomic<uint32_t> g_producedEnd{0};
std::atomic<uint32_t> g_consumedEnd{0};

// Batched progress publication (deferred experiment): real consumption
// credits accumulate here and are flushed to the guest-visible XTEB+0x58
// ONCE per vblank, mirroring the kernel's batched ISR publication cadence.
// This makes fences observe consumption as a post-fence batch regardless of
// when within the frame the CP actually fetched the data.
std::atomic<uint32_t> g_progressPending{0};
void AccumProgress(uint32_t dwords) {
  if (dwords != 0) {
    g_progressPending.fetch_add(dwords, std::memory_order_relaxed);
  }
}
uint32_t FlushProgressAtVblank() {
  const uint32_t add = g_progressPending.exchange(0, std::memory_order_acq_rel);
  if (add == 0) {
    return 0;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t blk = 0;
  if (const PPCContext *c = GetPPCContext()) {
    const uint32_t tls = c->r13.u32;
    uint32_t b = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &b)) {
      blk = b;
    }
  }
  if (blk == 0) {
    blk = g_progressBlk.load(std::memory_order_relaxed);
  }
  if (blk == 0) {
    static std::atomic<uint32_t> s_flushNoBlk{0};
    const uint32_t nb = s_flushNoBlk.fetch_add(1) + 1;
    if (nb <= 8 || (nb % 500) == 0) {
      MCLA_LOG_WARN("CP: PROGRESS-FLUSH #{} blk=0 (no TLS page and no "
                    "cached submitter block) - retrying later",
                    nb);
    }
    g_progressPending.fetch_add(add, std::memory_order_relaxed); // retry later
    return 0;
  }
  uint32_t cur = 0;
  if (mem.ReadU32BE(blk + 88, &cur)) {
    (void)mem.WriteU32BE(blk + 88, cur + add);
  }
  static std::atomic<uint32_t> s_flush{0};
  const uint32_t n = s_flush.fetch_add(1) + 1;
  if (n <= 12 || (n % 200) == 0) {
    MCLA_LOG_INFO("CP: PROGRESS-FLUSH #{} +{} -> {}", n, add, cur + add);
  }
  return add;
}

std::atomic<int> g_deferredMode{0}; // 0=unresolved, 1=off, 2=on
std::atomic<uint32_t> g_pendingRingWptr{
    0xFFFFFFFFu}; // doorbell deferred to vblank

// System-command-buffer state (kernel-acceptance boundary, 2026-08-25).
// g_gpuIdAddr = address the guest registered via
// VdSetSystemCommandBufferGpuIdentifierAddress (= &subctx[8]).
// g_scbToken  = opaque identifier handed out by VdGetSystemCommandBuffer;
// advances ONLY when real deferred consumption is credited, so repeated
// calls are stable while nothing is consumed (guest treats it opaquely).
std::atomic<uint32_t> g_gpuIdAddr{0};
std::atomic<uint32_t> g_scbToken{1};

void ScbNoteConsumption() {
  g_scbToken.fetch_add(1, std::memory_order_relaxed);
}

bool DeferredConsumeEnabled() {
  int mode = g_deferredMode.load(std::memory_order_acquire);
  if (mode != 0) {
    return mode == 2;
  }
  const char *e = std::getenv("cp_deferred_consume_experiment");
  const bool on = e != nullptr && e[0] == '1';
  if (g_deferredMode.compare_exchange_strong(mode, on ? 2 : 1)) {
    MCLA_LOG_WARN("CP: deferred-consumption experiment {} (diagnostic only)",
                  on ? "ENABLED" : "disabled");
  }
  return on;
}

// Physical -> kernel-virtual alias (X360: kernel maps phys windows at
// +0xC0000000; generated EA->PA transform is the inverse). Values at or
// above the kernel window are returned unchanged.
inline uint32_t PhysToKernelVA(uint32_t addr) {
  return addr < 0x20000000u ? (addr | 0xC0000000u) : addr;
}

int FindRingSlotLocked(uint32_t base, uint32_t capDwords) {
  for (size_t i = 0; i < kMaxRings; ++i) {
    const RingState &r = g_rings[i];
    if (r.initialized.load(std::memory_order_acquire) &&
        r.baseGuestVA == base && r.capDwords == capDwords) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

// Ring whose window [base, base+cap*4) contains byte address va, else nullptr.
RingState *RingContainingVA(uint32_t va) {
  for (auto &r : g_rings) {
    if (!r.initialized.load(std::memory_order_acquire))
      continue;
    if (va >= r.baseGuestVA && va < r.EndByte())
      return &r;
  }
  return nullptr;
}

// REJECTED HYPOTHESIS (2026-08-25, kept as evidence): GPU_ctx+0x30 was
// guessed to be a wrap-aliased ring cursor ("~65KB past ring base, wraps",
// BOOT_HANDOFF). Measured twice across boots the cursor sits at
// base + 2*ringSpan + ~0x13C/0x23C (mcla.log 07:06 C601C5BC, 00:51-era
// C62346BC vs C6224480) - i.e. just past TWO ring spans. That is a different
// driver arena's cursor, NOT ring-owned under any wrap rule. Strict window
// containment stays; consuming those cursors would be fabrication.
RingState *RingOwningCursorVA(uint32_t va) { return RingContainingVA(va); }

// Primary ring = the one the guest most recently initialized (and, if a WB
// was enabled afterwards, that one). The Xenos hardware CP has exactly ONE
// primary ring doorbell (CP_RB_WPTR); repeated VdInitializeRingBuffer calls
// reprogram it. This mirrors that without inventing multi-ring ownership.
RingState *PrimaryRing() {
  const uint32_t slot = g_primarySlot.load(std::memory_order_acquire);
  if (slot >= kMaxRings)
    return nullptr;
  RingState &r = g_rings[slot];
  return r.initialized.load(std::memory_order_acquire) ? &r : nullptr;
}

// All GuestDevices seen driving the ring (create hook + reserver/waiter
// censuses attach). MCLA binds a SECOND GuestDevice (A0009100) of the same
// class at create (sub_82413588); waiters poll THEIR OWN dev[+10896] ctx, so
// mirror maintenance must cover every device, not just the last attacher.
constexpr size_t kMaxDevices = 4;
std::atomic<uint32_t> g_devices[kMaxDevices]{};
static std::atomic<uint32_t> s_attachedCount{0};

template <typename Fn> void ForEachDevice(Fn &&fn) {
  for (auto &slot : g_devices) {
    if (const uint32_t dev = slot.load(std::memory_order_relaxed); dev != 0) {
      fn(dev);
    }
  }
}

std::atomic<uint64_t> g_drainCount{0};
std::atomic<uint64_t> g_swapCount{0};
std::atomic<uint64_t> g_doorbellCount{0};

uint32_t ReadRingU32(const RingState &ring, uint32_t dwordIndex) {
  const uint32_t addr = ring.baseGuestVA + dwordIndex * 4u;
  uint32_t v = 0;
  (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(addr, &v);
  return v;
}

// Phase-6 diagnostic: writeback target unexpectedly overlapping a ring body
// is logged loudly but NOT rejected (HW programs CP_RB_RPTR_ADDR as given;
// fabricating an error would be worse than surfacing the fact).
void WarnWritebackOverlap(RingState &ring) {
  const uint32_t wb = ring.writebackVA.load(std::memory_order_relaxed);
  if (wb == 0)
    return;
  for (auto &other : g_rings) {
    if (!other.initialized.load(std::memory_order_acquire))
      continue;
    if (wb >= other.baseGuestVA && wb < other.EndByte()) {
      static std::atomic<bool> warned{false};
      if (!warned.exchange(true)) {
        MCLA_LOG_WARN("CP: RING {} writeback {:08X} lies inside RING {} "
                      "body [{:08X},{:08X}) - rptr publishes will land "
                      "in ring memory",
                      ring.id, wb, other.id, other.baseGuestVA,
                      other.EndByte());
      }
      return;
    }
  }
}

void SyncConsumptionMirrors(uint32_t mark);

// ---------------------------------------------------------------------------
// Guest publication contract (IDA-proven 2026-08-26,
// .research/mcla_rex_contract):
//   dev[10908] "put"    - window counter, init 3, guest sub_82415500 advances
//                         +2 per reserved window (only guest writer).
//   *(dev[10896]) "pub" - consumed-window counter, init 1 (sub_824162D8 GPU-ctx
//                         init). On HW the kernel/GPU side publishes completion
//                         here; the only in-image writers are abort paths
//                         (sub_82415500 killbit branch, C18 recovery = put-2).
//   sub_82411E98(dev,N) blocks until pub >= N; healthy fences exit via this
//   check. F98's delta>=5000 -> C18 path is stall recovery only and TRAPS
//   (twi 31) when dev[13432]==0, so it must stay dormant.
// Therefore we publish COUNTS (prev+2 per completed window, clamped to live
// put), never VAs. Writing the consumed-through VA (old behavior) made
// (put-needed) < (put-pub) permanently true under u32 wraparound -> E98
// spins forever with pub=0xC60xxxxx against put=7..9.
// ---------------------------------------------------------------------------
namespace {
struct GuestPub {
  uint32_t dev;
  uint32_t count;
};
std::mutex g_pubMutex;
std::vector<GuestPub> g_pubStates;
} // namespace

void CpAdvanceGuestPublication(uint32_t windowsCompleted) {
  if (windowsCompleted == 0) {
    return;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  std::lock_guard<std::mutex> lock(g_pubMutex);
  ForEachDevice([&](uint32_t dev) {
    uint32_t subctx = 0;
    if (!mem.ReadU32BE(dev + 10896, &subctx) || subctx == 0) {
      return;
    }
    uint32_t put = 0;
    (void)mem.ReadU32BE(dev + 10908, &put);
    GuestPub *st = nullptr;
    for (auto &s : g_pubStates) {
      if (s.dev == dev) {
        st = &s;
        break;
      }
    }
    if (st == nullptr) {
      uint32_t seed = 0;
      (void)mem.ReadU32BE(subctx, &seed);
      g_pubStates.push_back({dev, seed});
      st = &g_pubStates.back();
    }
    uint32_t next = st->count + 2u * windowsCompleted;
    if (next > put) {
      next = put; // never publish beyond the guest's own production cursor
    }
    if (next != st->count) {
      const uint32_t prev = st->count;
      st->count = next;
      (void)mem.WriteU32BE(subctx + 0, next);
      static std::atomic<uint32_t> s_pubLog{0};
      const uint32_t n = s_pubLog.fetch_add(1) + 1;
      if (n <= 24 || (n % 500) == 0) {
        MCLA_LOG_INFO("CP: GUEST-PUB #{} dev={:08X} pub {}->{} put={}", n, dev,
                      prev, next, put);
      }
    }
  });
}

void PublishRptr(RingState &ring) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t rptr = ring.rptrIndex.load(std::memory_order_relaxed);
  const uint32_t wb = ring.writebackVA.load(std::memory_order_relaxed);
  if (ring.writebackEnabled.load(std::memory_order_acquire) && wb != 0) {
    (void)mem.WriteU32BE(wb, rptr);
  }
}

// Throttled unknown-opcode logger.
void LogUnknownOpcode(uint32_t opcode, uint32_t count) {
  static std::atomic<uint32_t> seenMask{0};
  static std::atomic<bool> highReported{false};
  if (opcode < 32) {
    const uint32_t bit = 1u << opcode;
    if (seenMask.fetch_or(bit) & bit)
      return; // already reported this opcode once
  } else {
    if (highReported.exchange(true))
      return; // one report covers all >=32 opcodes
  }
  MCLA_LOG_WARN("CP: skipping TYPE3 opcode=0x{:02X} count={} (unimplemented)",
                opcode, count);
}

// PM4 TYPE3 opcode values (xenia gpu/xenos.h PM4 enum).
constexpr uint32_t kPm4MeInit = 0x48;         // initialize CP micro-engine
constexpr uint32_t kPm4IndirectBuffer = 0x3F; // indirect buffer dispatch
constexpr uint32_t kPm4MemWrite = 0x3D;       // write N dwords to memory

// GpuSwap mirror (xenia command_processor.cc:1038-1064): endianness encoded
// in the low bits of PM4 memory addresses.
inline uint32_t GpuSwap32(uint32_t value, uint32_t endianBits) {
  switch (endianBits & 0x3) {
  case 1: // k8in16: swap bytes in half words
    return ((value << 8) & 0xFF00FF00u) | ((value >> 8) & 0x00FF00FFu);
  case 2: // k8in32: swap all bytes
    return ((value >> 24) & 0xFFu) | ((value >> 8) & 0xFF00u) |
           ((value << 8) & 0xFF0000u) | ((value << 24) & 0xFF000000u);
  default: // kNone / unhandled: no swap
    return value;
  }
}

// Honest MEM_WRITE (xenia :1092-1108): [addr, data*(count-1)]; sequential
// BE dwords, per-word endianness from addr low bits, addr advances by 4
// including its flag bits each iteration.
void ExecuteMemWrite(uint32_t wordAddr, uint32_t count) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t addr = wordAddr;
  for (uint32_t i = 1; i < count; ++i) {
    uint32_t data = 0;
    if (!mem.ReadU32BE(addr, &data)) {
      break;
    }
    const uint32_t swapped = GpuSwap32(data, addr & 0x3);
    (void)mem.WriteU32BE(addr & ~0x3u, swapped);
    addr += 4;
  }
}

// Linear indirect-buffer executor (xenia ExecuteIndirectBuffer :575-593):
// contiguous guest memory holding the same packet encoding as the primary
// ring. Depth-guarded against runaway nesting.
void DrainIndirectBuffer(uint32_t byteAddr, uint32_t dwordCount, int depth);

// PHASE-4 DIAGNOSTIC (cp_ib_trace=1): classify every packet inside an
// indirect-buffer walk so we know what the CP actually executes there.
bool IbTraceEnabled() {
  static const bool on = [] {
    const char *e = std::getenv("cp_ib_trace");
    return e != nullptr && e[0] == '1';
  }();
  return on;
}

bool DrainPacketAt(uint32_t byteAddr, int depth, uint32_t &outAdvanceDwords) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t header = 0;
  if (!mem.ReadU32BE(byteAddr, &header)) {
    return false;
  }

  const uint32_t type = header >> 30;
  if (type == 2) {
    outAdvanceDwords = 1; // TYPE-2 filler NOP
    return true;
  }

  if (type == 0) {
    const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
    static std::atomic<uint32_t> ibType0Seen{0};
    if (ibType0Seen.fetch_add(1) < 8) {
      MCLA_LOG_INFO("CP[IB]: TYPE0 base={:03X} count={}", header & 0x3FFFu,
                    count);
    }
    outAdvanceDwords = count + 1u;
    return true;
  }

  if (type != 3) {
    MCLA_LOG_WARN("CP[IB]: unsupported packet type={} at {:08X}", type,
                  byteAddr);
    return false;
  }

  const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
  const uint32_t opcode = (header >> 8) & 0x7Fu;

  switch (opcode) {
  case kPm4IndirectBuffer: {
    if (depth >= 4) {
      MCLA_LOG_WARN("CP[IB]: nested INDIRECT_BUFFER beyond depth limit");
      return false;
    }
    uint32_t listPtr = 0, listLen = 0;
    if (!mem.ReadU32BE(byteAddr + 4, &listPtr) ||
        !mem.ReadU32BE(byteAddr + 8, &listLen)) {
      return false;
    }
    DrainIndirectBuffer(listPtr & ~0x3u, listLen & 0xFFFFFu, depth + 1);
    outAdvanceDwords = count + 1u;
    return true;
  }
  case kPm4MeInit: {
    static std::atomic<uint32_t> meInitSeen{0};
    if (meInitSeen.fetch_add(1) < 4) {
      MCLA_LOG_INFO("CP[IB]: ME_INIT count={}", count);
    }
    outAdvanceDwords = count + 1u;
    return true;
  }
  case kPm4MemWrite: {
    uint32_t wordAddr = 0;
    if (!mem.ReadU32BE(byteAddr + 4, &wordAddr)) {
      return false;
    }
    // Payload dwords live contiguously after the addr word.
    ExecuteMemWrite(wordAddr, count);
    outAdvanceDwords = count + 1u;
    return true;
  }
  default:
    LogUnknownOpcode(opcode, count);
    outAdvanceDwords = count + 1u;
    return true;
  }
}

// Credit pending windows whose bytes an executed INDIRECT_BUFFER range
// actually covered. Called from DrainIndirectBuffer - i.e. consumption is
// credited when the content REALLY executes, never at reservation time.
// credited when the content REALLY executes, never at reservation time.
void CreditDeferredRange(uint32_t startVA, uint32_t endVA) {
  std::vector<PendingConsume> done;
  {
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    for (size_t i = g_pendingWindows.size(); i-- > 0;) {
      const auto &w = g_pendingWindows[i];
      if (w.startVA >= startVA && w.endVA <= endVA) {
        done.push_back(w);
        g_pendingWindows.erase(g_pendingWindows.begin() + static_cast<long>(i));
      }
    }
  }
  if (done.empty()) {
    return;
  }

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t credited = 0;
  uint32_t blk = 0;
  if (const PPCContext *c = GetPPCContext()) {
    const uint32_t tls = c->r13.u32;
    uint32_t b = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &b)) {
      blk = b;
    }
  }
  if (blk == 0) {
    blk = g_progressBlk.load(std::memory_order_relaxed);
  }
  uint32_t pcBefore = 0;
  if (blk != 0) {
    uint32_t cur = 0;
    if (mem.ReadU32BE(blk + 88, &cur)) {
      pcBefore = cur;
    }
  }
  for (const auto &w : done) {
    credited += w.dwords;
  }
  if (credited != 0) {
    ScbNoteConsumption();
  }
  // Real consumption covered these windows - publish their completion
  // counts to the guest (E98 wait contract).
  CpAdvanceGuestPublication(static_cast<uint32_t>(done.size()));
  if (blk != 0 && credited != 0) {
    AccumProgress(credited);
  }

  static std::atomic<uint32_t> s_creditCount{0};
  const uint32_t n = s_creditCount.fetch_add(1) + 1;
  if (n <= 16 || (n % 500) == 0) {
    MCLA_LOG_INFO("CP: DEFER-CREDIT #{:04} range [{:08X},{:08X}) windows={} "
                  "credited={} pc {}->{}",
                  n, startVA, endVA, done.size(), credited, pcBefore,
                  pcBefore + credited);
  }
}
void DrainIndirectBuffer(uint32_t byteAddr, uint32_t dwordCount, int depth) {
  constexpr uint32_t kMaxDwords = 0x100000u; // hard stop vs runaway streams
  const uint32_t limited = dwordCount > kMaxDwords ? kMaxDwords : dwordCount;

  static std::atomic<uint32_t> ibEnterSeen{0};
  if (ibEnterSeen.fetch_add(1) < 12) {
    MCLA_LOG_INFO("CP: INDIRECT_BUFFER @ {:08X} dwords={} depth={}", byteAddr,
                  limited, depth);
  }

  uint32_t p = 0;
  const bool trace = IbTraceEnabled() && depth == 0;
  uint32_t tCounts[4] = {0, 0, 0, 0};
  uint32_t opCount[128] = {};
  uint32_t nonzeroType3 = 0, firstT3Off = 0, firstT3Hdr = 0;
  while (p < limited) {
    if (trace) {
      uint32_t hdrProbe = 0;
      if (mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(byteAddr + p * 4u,
                                                              &hdrProbe)) {
        const uint32_t ty = hdrProbe >> 30;
        tCounts[ty < 4 ? ty : 3]++;
        if (ty == 3) {
          const uint32_t op = (hdrProbe >> 8) & 0x7Fu;
          if (op < 128)
            opCount[op]++;
          if (op != 0) {
            if (nonzeroType3 == 0) {
              firstT3Off = p;
              firstT3Hdr = hdrProbe;
            }
            nonzeroType3++;
          }
        }
      }
    }
    uint32_t advance = 0;
    if (!DrainPacketAt(byteAddr + p * 4, depth, advance)) {
      MCLA_LOG_WARN("CP[IB]: desync at dword {} - aborting buffer", p);
      break;
    }
    p += advance;
  }

  // Deferred experiment: this range's content has now actually executed.
  // Credit any pending reservation windows fully contained in it.
  if (DeferredConsumeEnabled()) {
    CreditDeferredRange(byteAddr, byteAddr + limited * 4u);
  }

  // EXPERIMENT A (cp_deferred_consume_experiment=1): XTEB+0x58 counts
  // dwords FETCHED BY THE CP - ring and indirect content alike. Evidence
  // (mcla_ibtrace.log 14:08): the driver enqueues a 1,019,567-dword
  // zero-padded INDIRECT_BUFFER immediately before parking on the 5000
  // threshold - a unit that only makes sense as fetched-dword accounting.
  // Credit the walked span at depth 0 only (nested content is part of the
  // parent span; double-fetch not modeled). Real consumption only.
  if (DeferredConsumeEnabled() && p != 0) {
    AccumProgress(p);
    static std::atomic<uint32_t> s_ibCredit{0};
    const uint32_t nIb = s_ibCredit.fetch_add(1) + 1;
    if (nIb <= 12 || (nIb % 200) == 0) {
      MCLA_LOG_INFO("CP: IB-CREDIT #{} base={:08X} credited={} dwords", nIb,
                    byteAddr, p);
    }
  }
}

// Drain packets from rptr up to wptr (both dword indices mod cap) for THE
// ring identified by the doorbell/wptr source. Synchronous on the calling
// thread; per-ring draining guard keeps a concurrent vblank drain out.
void DrainRing(RingState &ring, uint32_t wptr, const char *source) {
  const uint32_t cap = ring.capDwords;
  if (cap == 0 || wptr >= cap) {
    // Phase-6: wptr outside owning ring window.
    static std::atomic<bool> warnedBadWptr{false};
    if (!warnedBadWptr.exchange(true)) {
      MCLA_LOG_WARN("CP: RING {} doorbell wptr={:08X} rejected (cap={})",
                    ring.id, wptr, cap);
    }
    return;
  }

  uint32_t rptr = ring.rptrIndex.load(std::memory_order_relaxed);
  const uint32_t startRptr = rptr;
  uint32_t guard = cap * 2u + 16u; // hard stop against runaway streams

  while (rptr != wptr && guard--) {
    const uint32_t header = ReadRingU32(ring, rptr);
    const uint32_t type = header >> 30;

    if (type == 2) {
      // TYPE-2 filler NOP (0x80000000).
      rptr = (rptr + 1u) % cap;
      continue;
    }

    if (type == 3) {
      const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
      const uint32_t opcode = (header >> 8) & 0x7Fu;

      if (opcode == kPm4XeSwap && count >= 4) {
        // Payload: [0]="SWAP fourcc, [1]=frontbuffer phys,
        // [2]=width, [3]=height (xenia xboxkrnl_video.cc VdSwap).
        const uint32_t magic = ReadRingU32(ring, (rptr + 1u) % cap);
        const uint32_t fb = ReadRingU32(ring, (rptr + 2u) % cap);
        const uint32_t width = ReadRingU32(ring, (rptr + 3u) % cap);
        const uint32_t height = ReadRingU32(ring, (rptr + 4u) % cap);
        const uint64_t n = g_swapCount.fetch_add(1) + 1;
        if (n <= 10 || (n % 300) == 0) {
          MCLA_LOG_INFO("CP: XE_SWAP #{} magic={:08X} fb={:08X} {}x{}", n,
                        magic, fb, width, height);
        }
      } else if (opcode == kPm4IndirectBuffer && count >= 2) {
        // PM4_INDIRECT_BUFFER (xenia :943-953): [list_ptr, list_len]
        // - execute the referenced buffer's packets now.
        uint32_t listPtr = ReadRingU32(ring, (rptr + 1u) % cap);
        uint32_t listLen = ReadRingU32(ring, (rptr + 2u) % cap);
        DrainIndirectBuffer(listPtr & ~0x3u, listLen & 0xFFFFFu, 0);
      } else if (opcode == kPm4MeInit) {
        // PM4_ME_INIT (xenia :880-890): CP micro-engine init -
        // consumes count dwords of ME binary; no memory side effects.
        static std::atomic<uint32_t> meInitSeen{0};
        if (meInitSeen.fetch_add(1) < 4) {
          MCLA_LOG_INFO("CP: ME_INIT count={}", count);
        }
      } else if (opcode == kPm4MemWrite && count >= 2) {
        // PM4_MEM_WRITE (xenia :1092-1108): honest memory writes.
        const uint32_t wordAddr = ReadRingU32(ring, (rptr + 1u) % cap);
        ExecuteMemWrite(wordAddr, count);
      } else {
        LogUnknownOpcode(opcode, count);
      }

      rptr = (rptr + count + 1u) % cap;
      continue;
    }

    if (type == 0) {
      // TYPE-0: write `count` consecutive registers from a base index.
      const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
      static std::atomic<uint32_t> type0Seen{0};
      if (type0Seen.fetch_add(1) < 8) {
        MCLA_LOG_INFO("CP: TYPE0 base={:03X} count={}", header & 0x3FFFu,
                      count);
      }
      rptr = (rptr + count + 1u) % cap;
      continue;
    }

    // TYPE-1 or garbage: refusing to guess - drop to wptr so the
    // submitter unsticks, and say so loudly exactly once.
    static std::atomic<bool> warnedDesync{false};
    if (!warnedDesync.exchange(true)) {
      MCLA_LOG_ERROR("CP: RING {} desync at rptr={} header={:08X} - dropping "
                     "to wptr {:04X}",
                     ring.id, rptr, header, wptr);
    }
    rptr = wptr;
    break;
  }

  ring.rptrIndex.store(rptr, std::memory_order_relaxed);
  ring.lastDoorbellWptr.store(wptr, std::memory_order_relaxed);
  PublishRptr(ring);
  g_drainCount.fetch_add(1);

  // Kernel-side role: the real kernel CP consumer bumps the submitting
  // thread's GPU progress counter (*(r13+256)+88) as ring data is consumed;
  // sub_82412F98 busy-returns until it advanced >=5000 past the snapshot
  // (77.cpp:23832-23953). We run synchronously ON the submitter thread
  // (doorbell store), so its own PPC context is live here. Increment is
  // exactly the dwords consumed this drain - derived, not invented.
  if (const uint32_t advanced = (rptr - startRptr + cap) % cap; advanced != 0) {
    if (DeferredConsumeEnabled()) {
      // Batched publication: flushed once per vblank.
      AccumProgress(advanced);
      if (PPCContext *ctx0 = GetPPCContext()) {
        const uint32_t tls0 = ctx0->r13.u32;
        uint32_t blk0 = 0;
        auto &mem0 = mcla::kernel::GuestMemoryHeap::Instance();
        if (tls0 != 0 && mem0.ReadU32BE(tls0 + 256, &blk0) && blk0 != 0) {
          g_progressBlk.store(blk0, std::memory_order_relaxed);
        }
      }
    } else if (PPCContext *ctx = GetPPCContext()) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      const uint32_t tls = ctx->r13.u32;
      uint32_t blk = 0;
      if (tls != 0 && mem.ReadU32BE(tls + 256, &blk) && blk != 0) {
        g_progressBlk.store(blk, std::memory_order_relaxed);
        uint32_t cur = 0;
        if (mem.ReadU32BE(blk + 88, &cur)) {
          (void)mem.WriteU32BE(blk + 88, cur + advanced);
        }
      }
    }
  }
}

} // namespace

bool CpDeferredConsumeEnabled() { return DeferredConsumeEnabled(); }

void CpDeferredSnapshot(uint32_t *producedEnd, uint32_t *consumedEnd,
                        uint32_t *outstandingDwords, uint32_t *pendingWindows) {
  uint32_t outstanding = 0;
  {
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    for (const auto &w : g_pendingWindows) {
      outstanding += w.dwords;
    }
    if (pendingWindows) {
      *pendingWindows = static_cast<uint32_t>(g_pendingWindows.size());
    }
  }
  if (producedEnd)
    *producedEnd = g_producedEnd.load(std::memory_order_relaxed);
  if (consumedEnd)
    *consumedEnd = g_consumedEnd.load(std::memory_order_relaxed);
  if (outstandingDwords)
    *outstandingDwords = outstanding;
}

uint32_t CpScbToken() { return g_scbToken.load(std::memory_order_relaxed); }

uint32_t CpGpuIdentifierAddress() {
  return g_gpuIdAddr.load(std::memory_order_relaxed);
}

void CpRegisterGpuIdentifierAddress(uint32_t addr) {
  g_gpuIdAddr.store(addr, std::memory_order_relaxed);
}

void CpInitializeRingBuffer(uint32_t physAddr, uint32_t sizeLog2) {
  // Phase-6 diagnostic: ring capacity derives from 1u<<(sizeLog2+3) bytes;
  // log2 values >= 29 would overflow the dword math. Observed guests pass
  // 12..19. Diagnose and refuse - never guess a capacity.
  if (sizeLog2 > 28) {
    MCLA_LOG_ERROR("CP: VdInitializeRingBuffer base={:08X} sizeLog2={} "
                   "out of range (>28) - REJECTED",
                   physAddr, sizeLog2);
    return;
  }

  const uint32_t sizeBytes = 1u << (sizeLog2 + 3); // log2 of quadwords
  const uint32_t capDwords = sizeBytes >> 2;

  std::lock_guard<std::mutex> lock(g_ringMutex);

  RingState *ring = nullptr;
  int slot = FindRingSlotLocked(physAddr, capDwords);
  if (slot < 0) {
    // NEW RING: claim a free slot.
    for (size_t i = 0; i < kMaxRings; ++i) {
      if (!g_rings[i].initialized.load(std::memory_order_acquire)) {
        slot = static_cast<int>(i);
        break;
      }
    }
    if (slot < 0) {
      MCLA_LOG_ERROR("CP: ring registry full - VdInitializeRingBuffer "
                     "base={:08X} cap={} REJECTED",
                     physAddr, capDwords);
      return;
    }
    ring = &g_rings[slot];
    ring->baseGuestVA = physAddr;
    ring->capDwords = capDwords;
    ring->id = static_cast<char>('A' + g_nextRingId.fetch_add(1) % 26);
    ring->rptrIndex.store(0, std::memory_order_relaxed);
    ring->lastDoorbellWptr.store(0xFFFFFFFFu, std::memory_order_relaxed);
    ring->writebackVA.store(0, std::memory_order_relaxed);
    ring->writebackRaw.store(0, std::memory_order_relaxed);
    ring->writebackEnabled.store(false, std::memory_order_relaxed);
    ring->initialized.store(true, std::memory_order_release);

    // Phase-6: overlapping ring identities (same body, different key).
    for (auto &other : g_rings) {
      if (&other == ring || !other.initialized.load(std::memory_order_acquire))
        continue;
      const bool overlap =
          physAddr < other.EndByte() && other.baseGuestVA < ring->EndByte();
      if (overlap) {
        MCLA_LOG_WARN("CP: RING {} [{:08X},{:08X}) overlaps RING {} "
                      "[{:08X},{:08X}) - guest re-used ring memory with "
                      "a different identity",
                      ring->id, ring->baseGuestVA, ring->EndByte(), other.id,
                      other.baseGuestVA, other.EndByte());
      }
    }

    // New registration becomes the doorbell target (HW: one primary ring,
    // reprogramming it switches the CP over).
    g_primarySlot.store(static_cast<uint32_t>(slot), std::memory_order_release);
    MCLA_LOG_INFO("CP: RING {} NEW base={:08X} cap={} dwords", ring->id,
                  physAddr, capDwords);
  } else {
    // REINITIALIZATION OF AN EXISTING RING. Do not blindly reset an
    // active ring: preserve rptr when work is pending (doorbell wptr not
    // fully consumed); reset only when the ring is quiescent.
    ring = &g_rings[slot];
    const uint32_t rptr = ring->rptrIndex.load(std::memory_order_acquire);
    const uint32_t lastWptr =
        ring->lastDoorbellWptr.load(std::memory_order_acquire);
    const bool quiescent = lastWptr == 0xFFFFFFFFu || rptr == lastWptr;
    g_primarySlot.store(static_cast<uint32_t>(slot), std::memory_order_release);
    if (quiescent) {
      ring->rptrIndex.store(0, std::memory_order_relaxed);
      ring->lastDoorbellWptr.store(0xFFFFFFFFu, std::memory_order_relaxed);
      MCLA_LOG_INFO("CP: RING {} REINIT (idle) base={:08X} cap={} - rptr reset",
                    ring->id, physAddr, capDwords);
    } else {
      // Phase-5/6: re-init of an ACTIVE ring - retain its state.
      MCLA_LOG_WARN("CP: RING {} REINIT while ACTIVE base={:08X} cap={} "
                    "rptr={} pendingWptr={} - state RETAINED",
                    ring->id, physAddr, capDwords, rptr, lastWptr);
    }
  }
}

void CpEnableRPtrWriteBack(uint32_t rptrWritebackAddr, uint32_t blockSizeLog2) {
  (void)
      blockSizeLog2; // update frequency - not honored yet (matches xenia TODO)

  std::lock_guard<std::mutex> lock(g_ringMutex);
  RingState *ring = PrimaryRing();
  if (!ring) {
    // Phase-6: WB referencing a ring without RingState.
    MCLA_LOG_WARN("CP: rptr writeback {:08X} arrived before any ring init",
                  rptrWritebackAddr);
    return;
  }

  // The genuine guest call site passes PHYS(subctx+60) (< 0x20001000).
  // Guest waiters poll the same word through its kernel-VA alias, which is
  // where our flat guest-memory view lives - publish to the VA form and
  // keep the raw value for diagnostics.
  const uint32_t vaForm = PhysToKernelVA(rptrWritebackAddr);
  ring->writebackRaw.store(rptrWritebackAddr, std::memory_order_relaxed);
  ring->writebackVA.store(vaForm, std::memory_order_relaxed);
  ring->writebackEnabled.store(true, std::memory_order_release);
  g_primarySlot.store(FindRingSlotLocked(ring->baseGuestVA, ring->capDwords),
                      std::memory_order_release);

  WarnWritebackOverlap(*ring);

  if (vaForm != 0) {
    (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(vaForm, 0);
  }
  if (vaForm != rptrWritebackAddr) {
    MCLA_LOG_INFO("CP: RING {} rptr writeback raw={:08X} (phys) -> publish @ "
                  "{:08X} (kernel VA)",
                  ring->id, rptrWritebackAddr, vaForm);
  } else {
    MCLA_LOG_INFO("CP: RING {} rptr writeback @ {:08X}", ring->id, vaForm);
  }
}

void CpAttachDriverCtx(uint32_t devVA) {
  if (devVA == 0) {
    return;
  }
  for (auto &slot : g_devices) {
    if (slot.load(std::memory_order_relaxed) == devVA) {
      return; // already registered
    }
  }
  for (auto &slot : g_devices) {
    uint32_t expected = 0;
    if (slot.compare_exchange_strong(expected, devVA,
                                     std::memory_order_relaxed)) {
      const uint32_t n = s_attachedCount.fetch_add(1) + 1;
      MCLA_LOG_INFO("CP: attached GuestDevice {:08X} ({}/{})", devVA, n,
                    kMaxDevices);
      if (n == kMaxDevices) {
        MCLA_LOG_WARN("CP: device registry full - further devices untracked");
      }
      return;
    }
  }
}

void CpConsumePushWindow(uint32_t endVA, uint32_t dwords) {
  if (DeferredConsumeEnabled()) {
    // Experiment: record the submitted range; do NOT credit consumption.
    // The vblank-paced consumer credits it once the driver's production
    // cursor (GPU_ctx+0x30) actually covers the range.
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    const uint32_t prevEnd = g_producedEnd.load(std::memory_order_relaxed);
    if (endVA > prevEnd) {
      g_pendingWindows.push_back({prevEnd, endVA, dwords});
      g_producedEnd.store(endVA, std::memory_order_relaxed);
      // Bound sanity: production between vblanks is frame-sized; a
      // pathological pile-up means the consumer is not running.
      if (g_pendingWindows.size() > 4096) {
        static std::atomic<bool> warned{false};
        if (!warned.exchange(true)) {
          MCLA_LOG_WARN("CP: DEFER pending windows > 4096 - consumer "
                        "not draining?");
        }
      }
    }
    return;
  }

  // Monotonic: windows may be captured slightly out of order.
  uint32_t prev = g_pushWatermark.load(std::memory_order_relaxed);
  while (endVA > prev && !g_pushWatermark.compare_exchange_weak(
                             prev, endVA, std::memory_order_relaxed)) {
  }

  if (dwords == 0)
    return;
  // One captured window = one completed push-buffer window for the guest
  // publication contract (eager mode credits at capture).
  CpAdvanceGuestPublication(1);
  if (PPCContext *ctx = GetPPCContext()) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t tls = ctx->r13.u32;
    uint32_t blk = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &blk) && blk != 0) {
      uint32_t cur = 0;
      if (mem.ReadU32BE(blk + 88, &cur)) {
        (void)mem.WriteU32BE(blk + 88, cur + dwords);
      }
    }
  }
}

// VBLANK-PACED CONSUMER (deferred-consumption experiment). Credits only
// ranges the driver has actually produced (GPU_ctx+0x30 covers them), then
// publishes the consumed watermark and advances progress by EXACTLY those
// dwords - never a forced amount. Runs once per vblank from
// CpVblankDrainToWptr; no-op unless the experiment flag is on.
void ConsumePendingAtVblank() {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  uint32_t gpuCtxPtr = 0, producedVA = 0;
  if (!mem.ReadU32BE(0x82839254u, &gpuCtxPtr) || gpuCtxPtr == 0) {
    return;
  }
  if (!mem.ReadU32BE(gpuCtxPtr + 0x30u, &producedVA)) {
    return;
  }

  std::vector<PendingConsume> ready;
  {
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    while (!g_pendingWindows.empty() &&
           g_pendingWindows.front().endVA <= producedVA) {
      ready.push_back(g_pendingWindows.front());
      g_pendingWindows.erase(g_pendingWindows.begin());
    }
  }
  if (ready.empty()) {
    return;
  }

  uint32_t credited = 0, lastEnd = 0;
  for (const auto &w : ready) {
    credited += w.dwords;
    lastEnd = w.endVA;
  }

  // Guest-visible consumed watermark (monotonic advance only).
  uint32_t prevMark = g_pushWatermark.load(std::memory_order_relaxed);
  while (lastEnd > prevMark &&
         !g_pushWatermark.compare_exchange_weak(prevMark, lastEnd,
                                                std::memory_order_relaxed)) {
  }
  g_consumedEnd.store(lastEnd, std::memory_order_relaxed);
  ScbNoteConsumption();
  CpAdvanceGuestPublication(static_cast<uint32_t>(ready.size()));

  // Progress attribution: same block the eager path credited. All
  // synthesized threads share the boot-host r13 page, so the live vsync
  // context and the cached submitter block resolve to the same field.
  uint32_t blk = 0;
  if (const PPCContext *c = GetPPCContext()) {
    const uint32_t tls = c->r13.u32;
    uint32_t b = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &b)) {
      blk = b;
    }
  }
  if (blk == 0) {
    blk = g_progressBlk.load(std::memory_order_relaxed);
  }
  uint32_t pcBefore = 0;
  if (blk != 0) {
    uint32_t cur = 0;
    if (mem.ReadU32BE(blk + 88, &cur)) {
      pcBefore = cur;
      AccumProgress(credited);
    }
  }

  static std::atomic<uint32_t> s_deferCount{0};
  const uint32_t n = s_deferCount.fetch_add(1) + 1;
  uint32_t outstandingNow = 0, pendN = 0;
  CpDeferredSnapshot(nullptr, nullptr, &outstandingNow, &pendN);
  if (n <= 24 || (n % 500) == 0) {
    MCLA_LOG_INFO("CP: DEFER-CONSUME #{} produced={:08X} consumed->{:08X} "
                  "windows={} credited={} outstanding={} pendN={} "
                  "pc {}->{}",
                  n, producedVA, lastEnd, ready.size(), credited,
                  outstandingNow, pendN, pcBefore, pcBefore + credited);
  }
}

// Credit pending windows whose bytes an executed INDIRECT_BUFFER range
// actually covered. Called from DrainIndirectBuffer - i.e. consumption is

// VDRAIN CENSUS (2026-08-31 session 35): the hot WAIT census shows pc=0
// forever while this function produces no VDRAIN lines at all - meaning it
// exits early on some branch, but every early-exit here is silent. Count each
// reason and surface the ring registry state; log-only, no behavior change.
static std::atomic<uint32_t> s_vdInvocations{0};
static std::atomic<uint32_t> s_vdNoCtx{0};
static std::atomic<uint32_t> s_vdNoCtx30{0};
static std::atomic<uint32_t> s_vdNoRing{0};
static std::atomic<uint32_t> s_vdSameWptr{0};
static std::atomic<uint32_t> s_vdBusy{0};
static std::atomic<uint32_t> s_vdRejected{0};

void CpVblankDrainToWptr() {
  const uint32_t vdN = s_vdInvocations.fetch_add(1) + 1;
  if (vdN <= 16 || (vdN % 500) == 0) {
    auto &memC = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t gpuCtxC = 0, wptrVAC = 0;
    (void)memC.ReadU32BE(0x82839254u, &gpuCtxC);
    if (gpuCtxC != 0) {
      (void)memC.ReadU32BE(gpuCtxC + 0x30u, &wptrVAC);
    }
    std::string ringDump;
    {
      std::lock_guard<std::mutex> dumpLock(g_ringMutex);
      for (size_t i = 0; i < kMaxRings; ++i) {
        const RingState &r = g_rings[i];
        if (!r.initialized.load(std::memory_order_acquire))
          continue;
        ringDump += fmt::format(
            " {}[base={:08X} cap={} rptr={:04X} db={:08X} wb={:08X}]", r.id,
            r.baseGuestVA, r.capDwords,
            r.rptrIndex.load(std::memory_order_relaxed),
            r.lastDoorbellWptr.load(std::memory_order_relaxed),
            r.writebackVA.load(std::memory_order_relaxed));
      }
    }
    MCLA_LOG_INFO("CP: VDRAIN-CENSUS #{} def={} gpuCtx={:08X} ctx+30={:08X} "
                  "doorbells={} drains={} swaps={} exits[noCtx={} noCtx30={} "
                  "noRing={} sameWptr={} busy={} rejected={}]{}",
                  vdN, DeferredConsumeEnabled() ? 1 : 0, gpuCtxC, wptrVAC,
                  g_doorbellCount.load(std::memory_order_relaxed),
                  g_drainCount.load(std::memory_order_relaxed),
                  g_swapCount.load(std::memory_order_relaxed),
                  s_vdNoCtx.load(std::memory_order_relaxed),
                  s_vdNoCtx30.load(std::memory_order_relaxed),
                  s_vdNoRing.load(std::memory_order_relaxed),
                  s_vdSameWptr.load(std::memory_order_relaxed),
                  s_vdBusy.load(std::memory_order_relaxed),
                  s_vdRejected.load(std::memory_order_relaxed), ringDump);
  }
  // Deferred-consumption experiment: credit submitted-but-unconsumed
  // driver windows here, paced by vblank, before the ring-drain duty.
  if (DeferredConsumeEnabled()) {
    ConsumePendingAtVblank();

    // Drain the doorbell ring deferred from MMIO stores this frame.
    const uint32_t pendingW =
        g_pendingRingWptr.exchange(0xFFFFFFFFu, std::memory_order_acq_rel);
    if (pendingW != 0xFFFFFFFFu) {
      if (RingState *pring = PrimaryRing()) {
        if (!pring->draining.exchange(true)) {
          const uint32_t startR =
              pring->rptrIndex.load(std::memory_order_relaxed);
          DrainRing(*pring, pendingW, "vblank-deferred");
          const uint32_t endR =
              pring->rptrIndex.load(std::memory_order_relaxed);
          MCLA_LOG_INFO("CP: RING {} VDRAIN-DEFERRED rptr {:04X}->{:04X} "
                        "wptr={:04X} consumed={}",
                        pring->id, startR, endR, pendingW,
                        (endR - startR + pring->capDwords) % pring->capDwords);
          pring->draining.store(false, std::memory_order_release);
        }
      }
    }

    // Single batched publication point per vblank.
    FlushProgressAtVblank();
  }
  // Kernel-role vblank duty (2026-08-24). REPLACES both the retired fake
  // pub=put mirror (it force-refreshed F98 snapshots every tick, pinning
  // delta==0 forever - see sub_82412F98 decode) and the retired rate-based
  // +64 experiment. On HW the kernel CP fetches the ring continuously; the
  // closest honest emulation point we own is: at vblank, consume whatever
  // the driver has ACTUALLY produced (rptr -> GPU_ctx+0x30 wptr) through
  // the existing frozen-capability DrainRing. Progress/publication are
  // then consequences of real consumption only:
  //  - PublishRptr (inside DrainRing) publishes the consumed watermark.
  //  - DrainRing's consumed-dword accounting advances XTEB+88 progress.
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  uint32_t ctxPtr = 0;
  if (!mem.ReadU32BE(0x82839254u, &ctxPtr) || ctxPtr == 0) {
    s_vdNoCtx.fetch_add(1, std::memory_order_relaxed);
    return; // GPU context not published yet
  }

  // GPU_ctx+0x30 holds a driver-space BYTE VA (BOOT_HANDOFF: 0xC62346BC),
  // not a dword index. Route by EXACT ownership: the ring whose registered
  // window contains that byte VA is the one the driver produced into.
  uint32_t wptrVA = 0;
  if (!mem.ReadU32BE(ctxPtr + 0x30u, &wptrVA)) {
    s_vdNoCtx30.fetch_add(1, std::memory_order_relaxed);
    return;
  }

  RingState *ring = RingOwningCursorVA(wptrVA);
  if (!ring) {
    s_vdNoRing.fetch_add(1, std::memory_order_relaxed);
    static std::atomic<bool> warnedNoOwner{false};
    if (!warnedNoOwner.exchange(true)) {
      MCLA_LOG_WARN("CP: VDRAIN wptrVA={:08X} matches no registered ring "
                    "window - not consuming (would be fabrication)",
                    wptrVA);
    }
    return;
  }

  const uint32_t cap = ring->capDwords;
  const uint32_t oldRptr = ring->rptrIndex.load(std::memory_order_relaxed);

  // Byte-cursor -> dword index mod cap. Handles both in-body cursors and
  // wrap-aliased cursors past the physical end (see RingOwningCursorVA).
  const uint32_t wptr = static_cast<uint32_t>(
      ((uint64_t(wptrVA) - ring->baseGuestVA) >> 2) % cap);
  if (wptr == oldRptr) {
    s_vdSameWptr.fetch_add(1, std::memory_order_relaxed);
    return; // nothing produced: zero consumption, zero publication
  }

  // Single-drain guard per ring: DrainRing was designed for the synchronous
  // submitter thread; a concurrent doorbell drain must not interleave.
  if (ring->draining.exchange(true)) {
    s_vdBusy.fetch_add(1, std::memory_order_relaxed);
    return;
  }

  uint32_t probeDev = 0, pubBefore = 0;
  ForEachDevice([&](uint32_t dev) {
    if (probeDev != 0)
      return;
    uint32_t subctx = 0;
    probeDev = dev;
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
      (void)mem.ReadU32BE(subctx, &pubBefore);
  });

  const uint64_t drainsBefore = g_drainCount.load(std::memory_order_relaxed);
  DrainRing(*ring, wptr, "vblank");
  const bool ran = g_drainCount.load(std::memory_order_relaxed) != drainsBefore;
  if (!ran) {
    s_vdRejected.fetch_add(1, std::memory_order_relaxed);
    ring->draining.store(false, std::memory_order_release);
    return; // rejected/desync: nothing consumed, nothing published
  }

  const uint32_t newRptr = ring->rptrIndex.load(std::memory_order_relaxed);
  const uint32_t consumed = (newRptr - oldRptr + cap) % cap;

  uint32_t pubAfter = 0;
  {
    uint32_t subctx = 0;
    if (probeDev != 0 && mem.ReadU32BE(probeDev + 10896, &subctx) &&
        subctx != 0)
      (void)mem.ReadU32BE(subctx, &pubAfter);
  }

  static std::atomic<uint32_t> s_vdrain{0};
  const uint32_t n = s_vdrain.fetch_add(1) + 1;
  if (n <= 24 || (n % 500) == 0) {
    MCLA_LOG_INFO("CP: VDRAIN #{} RING {} base={:08X} cap={} dev={:08X} "
                  "wptrVA={:08X}->wptr={:04X} rptr {:04X}->{:04X} consumed={} "
                  "wb={:08X} pub {:X}->{}",
                  n, ring->id, ring->baseGuestVA, cap, probeDev, wptrVA, wptr,
                  oldRptr, newRptr, consumed,
                  ring->writebackVA.load(std::memory_order_relaxed), pubBefore,
                  pubAfter);
  }
  ring->draining.store(false, std::memory_order_release);
}

bool CpMmioWrite(uint32_t guestAddr, uint32_t value) {
  if ((guestAddr & kMmioMask) != kMmioBase) {
    return false;
  }

  const uint32_t offset = guestAddr - kMmioBase;
  if (offset == kWptrByteOffset) {
    // Log every doorbell including the sentinel: a silent sentinel store
    // vs a missing store are different failure modes.
    const uint64_t n = g_doorbellCount.fetch_add(1) + 1;

    // Phase-4 routing: the doorbell register carries only the wptr index
    // (HW has ONE primary ring). Drain THAT ring's state; never another
    // ring's base/cap/rptr/writeback.
    RingState *ring = PrimaryRing();
    const uint32_t rptrBefore =
        ring ? ring->rptrIndex.load(std::memory_order_relaxed) : 0;
    if (n <= 16 || (n % 500) == 0) {
      if (ring) {
        MCLA_LOG_INFO(
            "CP: doorbell RING {} base={:08X} cap={} wptr={:08X} (rptr={})",
            ring->id, ring->baseGuestVA, ring->capDwords, value, rptrBefore);
      } else {
        MCLA_LOG_WARN("CP: doorbell wptr={:08X} with NO registered ring",
                      value);
      }
    }
    if (value != kWptrSentinel) {
      // Deferred experiment: the doorbell only MARKS production on HW;
      // the CP fetches asynchronously. Record the target and let the
      // vblank consumer perform the actual drain + accounting.
      if (DeferredConsumeEnabled()) {
        uint32_t prevW = g_pendingRingWptr.load(std::memory_order_relaxed);
        while (prevW == 0xFFFFFFFFu || value > prevW) {
          if (g_pendingRingWptr.compare_exchange_weak(
                  prevW, value, std::memory_order_relaxed)) {
            break;
          }
        }
        const uint64_t n2 = g_doorbellCount.load(std::memory_order_relaxed);
        if (n2 <= 16) {
          MCLA_LOG_INFO("CP: DOORBELL-DEFER RING {} wptr={:04X} "
                        "(drain deferred to vblank)",
                        ring ? ring->id : '?', value);
        }
        return true;
      }
      // Bounded wait on the per-ring drain guard: losing this wptr
      // would stall the submitter until its NEXT doorbell.
      bool acquired = false;
      if (ring) {
        for (int spin = 0; spin < 64; ++spin) {
          if (!ring->draining.exchange(true)) {
            acquired = true;
            break;
          }
          std::this_thread::yield();
        }
        if (!acquired) {
          static std::atomic<bool> warnedBusy{false};
          if (!warnedBusy.exchange(true)) {
            MCLA_LOG_WARN("CP: RING {} drain guard held - doorbell "
                          "wptr={:08X} deferred to next submission",
                          ring->id, value);
          }
        }
      }
      if (ring && acquired) {
        const uint32_t startRptr =
            ring->rptrIndex.load(std::memory_order_relaxed);
        uint32_t callerLr = 0;
        if (const PPCContext *c = GetPPCContext())
          callerLr = static_cast<uint32_t>(c->lr);
        DrainRing(*ring, value, "doorbell");
        const uint32_t endRptr =
            ring->rptrIndex.load(std::memory_order_relaxed);
        const uint32_t consumed =
            (endRptr - startRptr + ring->capDwords) % ring->capDwords;
        // Phase-4 trace: full per-ring drain record.
        if (n <= 16 || (n % 500) == 0) {
          MCLA_LOG_INFO("CP: RING {} DRAIN src=doorbell base={:08X} cap={} "
                        "rptr {:04X}->{:04X} wptr={:04X} consumed={} wb={:08X} "
                        "published={} lr={:08X}",
                        ring->id, ring->baseGuestVA, ring->capDwords, startRptr,
                        endRptr, value, consumed,
                        ring->writebackVA.load(std::memory_order_relaxed),
                        consumed != 0, callerLr);
        }
        ring->draining.store(false, std::memory_order_release);
      } else if (!ring) {
        static std::atomic<bool> warnedNoRing{false};
        if (!warnedNoRing.exchange(true)) {
          MCLA_LOG_WARN("CP: doorbell dropped - no RingState yet "
                        "(wptr={:08X})",
                        value);
        }
      }
    }
    return true;
  }

  // Xenia persists every register write in its register file and serves
  // later reads from it (GraphicsSystem::WriteRegister,
  // graphics_system.cc:207-223). Mirroring that: store into the shadow so
  // guest read-back sees what it wrote (interrupt-enable bits included).
  const uint32_t regIndex = offset >> 2;
  if (regIndex < kMmioRegCount) {
    g_regShadow[regIndex].store(value, std::memory_order_relaxed);
  }

  // First-touch-per-register logging (low regs tracked by bitmask; high
  // regs are rare enough to log every store, matching prior behavior).
  static std::atomic<uint32_t> regSeenMask{0};
  const uint32_t bit = regIndex < 32 ? (1u << regIndex) : 0;
  if (!bit || !(regSeenMask.fetch_or(bit) & bit)) {
    static std::atomic<uint32_t> highRegLogCount{0};
    if (bit || (highRegLogCount.fetch_add(1) % 200) == 0) {
      MCLA_LOG_INFO("CP: MMIO write reg={:04X} offset={:04X} value={:08X}",
                    regIndex, offset, value);
    }
  }
  return true;
}

bool CpMmioRead(uint32_t guestAddr, uint32_t *outValue) {
  if ((guestAddr & kMmioMask) != kMmioBase) {
    return false;
  }

  const uint32_t offset = guestAddr - kMmioBase;
  const uint32_t regIndex = offset >> 2;

  // Per-register first-read logging for EVERY read (hardcoded + shadow):
  // the old warn-once-global flag hid all poll addresses after the first.
  {
    static std::atomic<uint32_t> slotReg[16]{};
    static std::atomic<uint32_t> slotBusy[16]{};
    const uint32_t slot = regIndex % 16;
    uint32_t expected = 0;
    bool wasEmpty = slotBusy[slot].load(std::memory_order_relaxed) == 0;
    if (wasEmpty && slotBusy[slot].compare_exchange_strong(
                        expected, 1u, std::memory_order_relaxed)) {
      slotReg[slot].store(regIndex, std::memory_order_relaxed);
      MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} (first touch)",
                    regIndex, offset);
    } else if (!wasEmpty &&
               slotReg[slot].load(std::memory_order_relaxed) != regIndex) {
      // Slot occupied by another reg: rotate once per 500 distinct-ish
      // events so rare regs still surface without spamming hot polls.
      static std::atomic<uint32_t> rotateCounter{0};
      if ((rotateCounter.fetch_add(1, std::memory_order_relaxed) % 500) == 0) {
        slotReg[slot].store(regIndex, std::memory_order_relaxed);
        MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} (rotate)",
                      regIndex, offset);
      }
    }
  }

  // Hardcoded status reads, mirroring xenia GraphicsSystem::ReadRegister
  // (graphics_system.cc:184-201) - values verbatim from that switch.
  // Reg 0x1951 bit0 = vblank pending - the game's own vsync ISR gates its
  // flip-request processor on exactly this word
  // ([0x7FC80000+0x6544]&1, ppc_recomp.77.cpp:19534-19542); answering 0
  // starves the present path.
  switch (regIndex) {
  case 0x0F00: // RB_EDRAM_TIMING (graphics_system.cc:186)
    *outValue = 0x08100748u;
    return true;
  case 0x0F01: // RB_BC_CONTROL (graphics_system.cc:188)
    *outValue = 0x0000200Eu;
    return true;
  case 0x194C: // R500_D1MODE_V_COUNTER (graphics_system.cc:189-190)
    *outValue = 0x000002D0u;
    return true;
  case 0x1951: // interrupt status: vblank pending (graphics_system.cc:191-192)
    *outValue = 1u;
    return true;
  case 0x1961: // AVIVO_D1MODE_VIEWPORT_SIZE 1280x720
               // (graphics_system.cc:193-196)
    *outValue = 0x050002D0u;
    return true;
  default:
    break;
  }

  // Everything else: last written value (xenia register-file fallback,
  // graphics_system.cc:204 register_file_.values[r] return), 0 when never
  // written.
  if (regIndex < kMmioRegCount) {
    *outValue = g_regShadow[regIndex].load(std::memory_order_relaxed);
  } else {
    *outValue = 0;
  }
  return true;
}

uint64_t CpSwapCount() { return g_swapCount.load(std::memory_order_relaxed); }
uint64_t CpDrainCount() { return g_drainCount.load(std::memory_order_relaxed); }

// PAGE-WATCH (session 24): attribution probes for the async-task work buffer
// at guest 0x50000000 - called from GuestMemoryView checked accessors.
void PageWatchOnWrite(uint32_t guestAddr, uint32_t value) {
  static std::atomic<uint32_t> s_watchWrites{0};
  const uint32_t n = s_watchWrites.fetch_add(1) + 1;
  if (guestAddr >= 0xA0000000u && guestAddr < 0xA1000000u) {
    uint32_t lr = 0;
    uint32_t sp = 0;
    uint32_t r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0;
    uint32_t r8 = 0, r9 = 0, r10 = 0;
    if (const PPCContext *c = GetPPCContext()) {
      lr = static_cast<uint32_t>(c->lr);
      sp = c->r1.u32;
      r3 = c->r3.u32;
      r4 = c->r4.u32;
      r5 = c->r5.u32;
      r6 = c->r6.u32;
      r7 = c->r7.u32;
      r8 = c->r8.u32;
      r9 = c->r9.u32;
      r10 = c->r10.u32;
    }
    MCLA_LOG_WARN(
      "POOL16-WRITE #{} @ {:08X} = {:08X} lr={:08X} sp={:08X} "
        "r3={:08X} r4={:08X} r5={:08X} r6={:08X} r7={:08X} r8={:08X} "
        "r9={:08X} r10={:08X}",
        n, guestAddr, value, lr, sp, r3, r4, r5, r6, r7, r8, r9, r10);
    spdlog::default_logger()->flush();
  }
  if (guestAddr >= 0x82839254u && guestAddr < 0x82839280u) {
    uint32_t lr = 0;
    if (const PPCContext *c = GetPPCContext())
      lr = static_cast<uint32_t>(c->lr);
    MCLA_LOG_WARN("CONFIG-WRITE WATCH @ {:08X} = {:08X} lr={:08X}", guestAddr,
                  value, lr);
  }
  if (n <= 16) {
    uint32_t lr = 0;
    if (const PPCContext *c = GetPPCContext())
      lr = static_cast<uint32_t>(c->lr);
    MCLA_LOG_WARN("PAGEWATCH W #{:02} @ {:08X} = {:08X} lr={:08X}", n,
                  guestAddr, value, lr);
  }
}

void PageWatchOnRead(uint32_t guestAddr, uint32_t value) {
  static std::atomic<uint32_t> s_watchReads{0};
  const uint32_t n = s_watchReads.fetch_add(1) + 1;
  if (n <= 8) {
    uint32_t lr = 0;
    if (const PPCContext *c = GetPPCContext())
      lr = static_cast<uint32_t>(c->lr);
    MCLA_LOG_WARN("PAGEWATCH R #{:02} @ {:08X} -> {:08X} lr={:08X}", n,
                  guestAddr, value, lr);
  }
}

void CpInstallMmioRouting() {
  mcla::native::SetGpuMmioHandlers(&CpMmioWrite, &CpMmioRead);
  MCLA_LOG_INFO("CP: MMIO routing installed (XGPU window 0x7FC80000)");
}

} // namespace mcla::gpu
