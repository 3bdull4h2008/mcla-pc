#include "gpu_device.h"
#include "gpu_cp.h"
#include "render_queue.h"
#include "renderer_mode.h"
#include "renderer_hook_dispatch.h"
#include "capture_hooks.h"
#include "native_renderer.h"

#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "kernel/memory.h"
#include "logging.h"
#include <cpu/ppc_context.h>

#include <atomic>
#include <iterator>

extern std::atomic<uint32_t> g_mainGuestThreadId;

static std::atomic<uint32_t> s_rsRealThunkHits{0};
static std::atomic<uint32_t> s_rsLogOnlyThunkHits{0};
void HostRsRealPassthrough(PPCContext &__restrict ctx, uint8_t *base);
void HostRsRealPassthroughLogOnly(PPCContext &__restrict ctx, uint8_t *base);

// Mutex for protecting g_lastDraw and g_drawMutex access across namespace blocks
static std::mutex g_drawMutex;

namespace mcla::gpu {

namespace {

std::atomic<uint32_t> g_deviceAddr{0};
std::atomic<bool> g_layoutDumped{false};

// Canonical publish slot the rest of the driver reads the device from:
// device = **(uint32_t**)0x82000864 (reverser-verified, 23 consumers).
constexpr uint32_t kDevicePublishSlot = 0x82000864;

constexpr uint32_t kDumpBytes =
    0x400; // FP tables + sampler region + constants head

void DumpDeviceLayout(uint32_t dev) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  for (uint32_t off = 0; off < kDumpBytes; off += 16) {
    uint32_t w[4] = {};
    bool ok = true;
    for (int i = 0; i < 4; ++i) {
      ok &= mem.ReadU32BE(dev + off + 4u * static_cast<uint32_t>(i), &w[i]);
    }
    if (!ok) {
      MCLA_LOG_WARN("DEVICE: read failed at +{:04X}", off);
      return;
    }
    // SWA GuestDevice reference layout for comparison: dirtyFlags[8]
    // @+0x00, setRenderStateFunctions[0x65] @+0x40,
    // setSamplerStateFunctions[0x14] @+0x1D4. Pointer-like words show up
    // as 82xxxxxx guest code addresses.
    MCLA_LOG_INFO("DEVICE +{:04X}: {:08X} {:08X} {:08X} {:08X}", off, w[0],
                  w[1], w[2], w[3]);
  }
}

void OnDeviceCreated(uint32_t dev) {
  g_deviceAddr.store(dev, std::memory_order_relaxed);

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t slotPtr = 0;
  uint32_t published = 0;
  if (mem.ReadU32BE(kDevicePublishSlot, &slotPtr) && slotPtr != 0 &&
      mem.ReadU32BE(slotPtr, &published)) {
    MCLA_LOG_INFO(
        "DEVICE: created @ {:08X} (publish slot {:08X} -> {:08X}, {})", dev,
        slotPtr, published, published == dev ? "match" : "MISMATCH");
  } else {
    MCLA_LOG_INFO("DEVICE: created @ {:08X} (publish slot unreadable)", dev);
  }

  if (!g_layoutDumped.exchange(true)) {
    DumpDeviceLayout(dev);
  }
}

} // namespace

uint32_t DeviceGuestAddr() {
  return g_deviceAddr.load(std::memory_order_relaxed);
}

} // namespace mcla::gpu

// ---------------------------------------------------------------------------
// Render-state table redirection (UnleashedRecomp video.cpp CreateDevice).
// Slots left at the driver's own default stub (= PPC_CODE_BASE) are pointed
// at a host passthrough thunk registered past the guest code range. Real
// handlers stay untouched - this proves the FP-table seam end-to-end without
// changing behavior.
// ---------------------------------------------------------------------------

static std::atomic<uint32_t> s_rsThunkHits{0};

static void HostRsUnimplementedPassthrough(PPCContext &__restrict ctx,
                                           uint8_t *base) {
  // First touches get logged; behavior passes through to the driver's own
  // default handler unchanged.
  const uint32_t hits = s_rsThunkHits.fetch_add(1) + 1;
  if (hits <= 12 || (hits % 500) == 0) {
    MCLA_LOG_INFO("DEVICE: RS-default-thunk hit #{} r3={:08X} r4={:08X}", hits,
                  ctx.r3.u32, ctx.r4.u32);
  }
  if (PPCFunc *orig = mcla::kernel::g_memory.FindFunction(
          static_cast<uint32_t>(PPC_CODE_BASE))) {
    orig(ctx, base);
  }
}

namespace mcla::gpu {
namespace {

void RedirectDefaultRenderStateSlots(uint32_t dev) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  const auto fnOffset = static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE);
  mcla::kernel::g_memory.InsertFunction(fnOffset,
                                        &HostRsUnimplementedPassthrough);

  uint32_t redirected = 0;
  constexpr uint32_t kSlots = 0x65; // setRenderStateFunctions count
  for (uint32_t slot = 0; slot < kSlots; ++slot) {
    const uint32_t addr = dev + 0x40u + slot * 4u;
    uint32_t cur = 0;
    if (!mem.ReadU32BE(addr, &cur)) {
      return;
    }
    if (cur == static_cast<uint32_t>(PPC_CODE_BASE)) {
      (void)mem.WriteU32BE(addr, fnOffset);
      ++redirected;
    }
  }

  // Rung-2 self-test: table round-trip + thunk resolution.
  uint32_t readBack = 0;
  const bool tableOk = mem.ReadU32BE(dev + 0x40u, &readBack);
  PPCFunc *resolved = mcla::kernel::g_memory.FindFunction(fnOffset);
  MCLA_LOG_INFO(
      "DEVICE: redirected {}/{} default RS slots -> {:08X} | readback={} "
      "(slot0={:08X}) | thunkResolved={}",
      redirected, kSlots, fnOffset, tableOk ? "ok" : "FAIL", readBack,
      resolved != nullptr);
}

// P4' step 2: passthrough-thunk ONE real handler slot so a runtime call proves
// dispatch through our synthetic VA end-to-end. Slot +0x68 (table index 10)
// held 0x82414078 in both dumped devices. The original stays reachable via its
// own guest address (FindFunction), so redirection loses nothing.
constexpr uint32_t kRealSlotOffset = 0x68;
constexpr uint32_t kRealSlotOriginal = 0x82414078;

void RedirectFirstRealRenderStateSlot(uint32_t dev) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  const uint32_t slotAddr = dev + kRealSlotOffset;
  uint32_t cur = 0;
  if (!mem.ReadU32BE(slotAddr, &cur)) {
    MCLA_LOG_WARN("DEVICE: real-slot redirect read failed @ {:08X}", slotAddr);
    return;
  }
  if (cur != kRealSlotOriginal) {
    MCLA_LOG_WARN(
        "DEVICE: real-slot @ {:08X} holds {:08X} (expected {:08X}) - skipping",
        slotAddr, cur, kRealSlotOriginal);
    return;
  }

  // Synthetic VA right after the default-slots thunk.
  const auto fnOffset =
      static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE) + 4u;
  mcla::kernel::g_memory.InsertFunction(fnOffset, &HostRsRealPassthrough);
  (void)mem.WriteU32BE(slotAddr, fnOffset);

  uint32_t readBack = 0;
  const bool ok = mem.ReadU32BE(slotAddr, &readBack) && readBack == fnOffset &&
                  mcla::kernel::g_memory.FindFunction(fnOffset) != nullptr;
  MCLA_LOG_INFO("DEVICE: real RS slot +{:X} -> {:08X} | selftest={}",
                kRealSlotOffset, fnOffset, ok ? "ok" : "FAIL");

  // Probe widening: EVERY other real slot gets a log-only thunk (no
  // passthrough - originals stay reachable by address if needed later).
  // Purpose: discover which states are actually hot during boot/menu.
  constexpr uint32_t kSlots = 0x65;
  uint32_t probed = 0;
  auto nextFn = fnOffset;
  for (uint32_t slot = 0; slot < kSlots; ++slot) {
    const uint32_t sAddr = dev + 0x40u + slot * 4u;
    uint32_t v = 0;
    if (!mem.ReadU32BE(sAddr, &v))
      break;
    if (v == static_cast<uint32_t>(PPC_CODE_BASE))
      continue; // default stub
    if (sAddr == slotAddr)
      continue; // faithful one above
    if (v < static_cast<uint32_t>(PPC_CODE_BASE) ||
        v >= static_cast<uint32_t>(PPC_CODE_BASE + PPC_CODE_SIZE))
      continue; // not guest code
    ++nextFn;
    mcla::kernel::g_memory.InsertFunction(nextFn,
                                          &HostRsRealPassthroughLogOnly);
    (void)mem.WriteU32BE(sAddr, nextFn);
    ++probed;
  }
  MCLA_LOG_INFO("DEVICE: probe widened - {} additional real slots log-only",
                probed);
}

} // namespace
} // namespace mcla::gpu

// ---------------------------------------------------------------------------
// Guest-function override. MUST live at GLOBAL scope: the generated TUs bind
// calls to the global weak symbol sub_82413588; a namespaced definition would
// be a different symbol entirely and silently never run.
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_82413588);

PPC_FUNC(sub_82413588) {
  // r8 is caller-volatile under the recomp ABI - the callee clobbers ctx.r8
  // immediately after saving it to a callee-saved register. Capture the
  // out-pointer BEFORE transferring control.
  const uint32_t outPtr = ctx.r8.u32;

  static std::atomic<bool> entryLogged{false};
  if (!entryLogged.exchange(true)) {
    MCLA_LOG_INFO("DEVICE: create entry hit (out={:08X})", outPtr);
  }

  __imp__sub_82413588(ctx, base);

  if (outPtr != 0) {
    uint32_t dev = 0;
    if (mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(outPtr, &dev) &&
        dev != 0) {
      mcla::gpu::OnDeviceCreated(dev);
      mcla::gpu::RedirectDefaultRenderStateSlots(dev);
      mcla::gpu::RedirectFirstRealRenderStateSlot(dev);
    } else {
      static std::atomic<bool> warned{false};
      if (!warned.exchange(true)) {
        MCLA_LOG_WARN("DEVICE: create produced no device (out={:08X})", outPtr);
      }
    }
  }
}

// P4' step 2 runtime thunk: proves guest -> synthetic VA -> host dispatch.
void HostRsRealPassthrough(PPCContext &__restrict ctx, uint8_t *base) {
  const uint32_t n = s_rsRealThunkHits.fetch_add(1) + 1;
  if (n <= 12 || (n % 500) == 0)
    MCLA_LOG_INFO("DEVICE: RS-real-thunk hit #{} r3={:08X} r4={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32);
  if (PPCFunc *orig =
          mcla::kernel::g_memory.FindFunction(mcla::gpu::kRealSlotOriginal))
    orig(ctx, base);
}

// Log-only probe thunk: records the hit, does NOT call the original - used to
// discover hot render-state slots; originals remain at their guest addresses.
void HostRsRealPassthroughLogOnly(PPCContext &__restrict ctx, uint8_t *base) {
  const uint32_t n = s_rsLogOnlyThunkHits.fetch_add(1) + 1;
  if (n <= 20 || (n % 1000) == 0)
    MCLA_LOG_INFO("DEVICE: RS-logonly-thunk hit #{} r3={:08X} r4={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32);
}

// ---------------------------------------------------------------------------
// P4' PIVOT: MCLA never dispatches via device FP tables (see PIVOT FINDING).
// State/draw intent flows DIRECTLY through these helpers. Global-scope strong
// overrides intercept every caller; passthrough preserves behavior.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411180);
static std::atomic<uint32_t> s_h11180{0};
static std::atomic<uint32_t> s_h11180done{0};
PPC_FUNC(sub_82411180) {
  const uint32_t n = s_h11180.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  uint32_t mask = 0, subctx = 0, published4 = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 14900, &mask);
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
      (void)mem.ReadU32BE(subctx + 4, &published4);
  }
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411180 hit #{} r3={:08X} r4={:08X} "
                  "r5={:08X} msk={:X} sc={:X} wb4={:X}",
                  n, dev, ctx.r4.u32, ctx.r5.u32, mask, subctx, published4);
  __imp__sub_82411180(ctx, base);
  const uint32_t d = s_h11180done.fetch_add(1) + 1;
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411180 RETURNED #{} (r3={:08X})", d,
                  ctx.r3.u32);
}

PPC_FUNC_IMPL(__imp__sub_82411618);
static std::atomic<uint32_t> s_h11618{0};
PPC_FUNC(sub_82411618) {
  const uint32_t n = s_h11618.fetch_add(1) + 1;
  if (n <= 12 || (n % 2000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411618 hit #{} r3={:08X}", n, ctx.r3.u32);
  __imp__sub_82411618(ctx, base);
}

// PRIMARY CHOKE POINT (reverser-pinned 2026-08-23): sub_82411640 is a
// push-buffer SPACE RESERVER, not a packet writer:
//   sub_82411640(dev /*r3*/, flags /*r4*/, sizeSlot /*r5*/, alignBytes /*r6*/)
// r5 points to ONE u32 {requested bytes}; only desc[0] is read by the guest.
// Return r3 = reserved ring-window VA; desc[0] written back = consumed bytes.
// => the reserved window holds FULLY-FORMED driver output for every
//    submission class; capture it AFTER passthrough.
// Submission classes (ppc_recomp.77.cpp evidence):
//   (flags=1, align=32) -> sub_82411B10 descriptor batches
//   (flags=1, align=4)  -> sub_82412710 indirect-dispatch packet
//   (flags=2, align=32) -> sub_82412318 raw packet envelopes
// PM4 classification ground truth:
// .research/xenia/src/xenia/gpu/xenos.h:1572-1664. Capture-only: bounds-checked
// BE reads, no D3D12, no invented fields.
namespace {

constexpr uint32_t kPktCapMaxDwords = 256; // defensive cap per window read
constexpr uint32_t kPktCapFullDumps = 16;  // full hex dumps before stats-only
constexpr uint32_t kPktCapPendingMax = 64; // deferred-window ring capacity

// Reserved windows are EMPTY at sub_82411640 return - builders (sub_82411B10 /
// sub_82411DC0) fill them afterwards. Capture is therefore DEFERRED: entries
// are queued here and scanned on the NEXT reservation, when their bytes are
// actually present in the ring.
struct PendingWindow {
  uint32_t addr;
  uint32_t dwords;
  uint32_t flags;
  uint32_t alignBytes;
};
static std::mutex s_pendingMtx;
PendingWindow g_pending[kPktCapPendingMax] = {};
uint32_t g_pendingCount = 0;

struct PktCapStats {
  std::atomic<uint32_t> descriptors{0};
  std::atomic<uint32_t> dwords{0};
  std::atomic<uint32_t> clsDescBatch{0};   // flags=1 align>=32
  std::atomic<uint32_t> clsIndirect{0};    // flags=1 align<32
  std::atomic<uint32_t> clsRawEnvelope{0}; // flags!=1 align>=32
  std::atomic<uint32_t> type0{0};
  std::atomic<uint32_t> type1{0};
  std::atomic<uint32_t> type2Nop{0};
  std::atomic<uint32_t> t3Nop{0};          // 0x10
  std::atomic<uint32_t> t3DrawIndx{0};     // 0x22
  std::atomic<uint32_t> t3DrawIndx2{0};    // 0x36
  std::atomic<uint32_t> t3ImLoad{0};       // 0x27 / 0x2b
  std::atomic<uint32_t> t3SetConstant{0};  // 0x2d
  std::atomic<uint32_t> t3LoadAluConst{0}; // 0x2f
  std::atomic<uint32_t> t3MemWrite{0};     // 0x3d
  std::atomic<uint32_t> t3EventWrite{0};   // 0x46, 0x58-0x5b
  std::atomic<uint32_t> t3Other{0};
  std::atomic<uint32_t> clampedWindow{0}; // read clamp / VA-space overrun
  std::atomic<uint32_t> midPacket{0};     // scan ended inside a packet
  std::atomic<uint32_t> oddBytes{0};      // consumed not dword-aligned
};

PktCapStats g_pktCap;

bool IsEventOpcode(uint32_t op) {
  return op == 0x46 || (op >= 0x58 && op <= 0x5b);
}

void ClassifyT3(uint32_t op) {
  switch (op) {
  case 0x10:
    ++g_pktCap.t3Nop;
    break;
  case 0x22:
    ++g_pktCap.t3DrawIndx;
    break;
  case 0x36:
    ++g_pktCap.t3DrawIndx2;
    break;
  case 0x27:
  case 0x2b:
    ++g_pktCap.t3ImLoad;
    break;
  case 0x2d:
    ++g_pktCap.t3SetConstant;
    break;
  case 0x2f:
    ++g_pktCap.t3LoadAluConst;
    break;
  case 0x3d:
    ++g_pktCap.t3MemWrite;
    break;
  default:
    if (IsEventOpcode(op))
      ++g_pktCap.t3EventWrite;
    else
      ++g_pktCap.t3Other;
    break;
  }
}

void ScanPackets(const uint32_t *w, uint32_t n) {
  // Packet sizes per .research/xenia/src/xenia/gpu/command_processor.cc:
  // type-0 = header + (((p>>16)&0x3FFF)+1) dwords (:641),
  // type-1 = header + TWO payload dwords (:666-670), type-2 = 1 dword,
  // type-3 = header + (((p>>16)&0x3FFF)+1) payload dwords.
  uint32_t i = 0;
  while (i < n) {
    const uint32_t hdr = w[i];
    uint32_t next = i + 1;
    switch (hdr >> 30) {
    case 0:
      ++g_pktCap.type0;
      next = i + ((hdr >> 16) & 0x3FFFu) + 2;
      break;
    case 1:
      ++g_pktCap.type1;
      next = i + 3;
      break;
    case 2:
      ++g_pktCap.type2Nop;
      next = i + 1;
      break;
    default:
      ClassifyT3((hdr >> 8) & 0xFFu);
      next = i + ((hdr >> 16) & 0x3FFFu) + 2;
      break;
    }
    if (next > n) {
      ++g_pktCap.midPacket; // window ends inside a packet; stop cleanly
      return;
    }
    i = next;
  }
}

} // namespace

PPC_FUNC_IMPL(__imp__sub_82411640);
static std::atomic<uint32_t> s_h11640{0};

namespace {

// Read+classify one (previously reserved) ring window. Called from the 640
// override AFTER the window has had time to be filled by its builder.
void CaptureWindow(uint32_t n, uint32_t dev, const PendingWindow &pw) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  if (pw.dwords == 0)
    ++g_pktCap.oddBytes;

  // Clamp to capture buffer AND to guest VA space (u64 math: no wrap near
  // 0xFFFFFFFF into low RAM).
  uint64_t availDwords = pw.dwords;
  if (availDwords > kPktCapMaxDwords)
    availDwords = kPktCapMaxDwords;
  if (pw.addr == 0)
    return;
  const uint64_t vaRoomDwords = (uint64_t(0x100000000ull) - pw.addr) / 4u;
  if (vaRoomDwords < availDwords)
    availDwords = vaRoomDwords;

  const uint32_t wordCount = uint32_t(availDwords);
  if (wordCount < pw.dwords)
    ++g_pktCap.clampedWindow;

  uint32_t words[kPktCapMaxDwords] = {};
  bool readOk = wordCount > 0;
  for (uint32_t i = 0; i < wordCount; ++i)
    readOk &= mem.ReadU32BE(pw.addr + i * 4u, &words[i]);

  if (!readOk) {
    static std::atomic<bool> readWarned{false};
    if (!readWarned.exchange(true))
      MCLA_LOG_WARN("PKT-CAP: window read failed dev={:08X} @ {:08X}", dev,
                    pw.addr);
    return;
  }

  ++g_pktCap.descriptors;
  g_pktCap.dwords.fetch_add(wordCount, std::memory_order_relaxed);

  // Consumption accounting: these bytes are resident ? kernel CP may fetch
  // through them. Advances the ctx[+0]/[+4] watermark + progress counter
  // by the FULL reserved size (not the clamped read).
  mcla::gpu::CpConsumePushWindow(pw.addr + pw.dwords * 4u, pw.dwords);

  if ((pw.flags & 1u) != 0) {
    if (pw.alignBytes >= 32)
      ++g_pktCap.clsDescBatch;
    else
      ++g_pktCap.clsIndirect;
  } else if (pw.alignBytes >= 32) {
    ++g_pktCap.clsRawEnvelope;
  }
  ScanPackets(words, wordCount);

  if (n <= kPktCapFullDumps) {
    std::string hex;
    hex.reserve(wordCount * 9);
    for (uint32_t i = 0; i < wordCount; ++i)
      fmt::format_to(std::back_inserter(hex), "{:08X} ", words[i]);
    MCLA_LOG_INFO("PKT-CAP #{:04X}: dev={:08X} f={} a={} win={:08X} n={} | {}",
                  n, dev, pw.flags, pw.alignBytes, pw.addr, pw.dwords, hex);
  }
}

void LogSummary(uint32_t n) {
  MCLA_LOG_INFO(
      "PKT-CAP summary: desc={} dw={} descBatch={} indirect={} rawEnv={} "
      "t0={} t1={} t2nop={} t3nop={} draw_indx={} draw_indx2={} "
      "im_load={} set_const={} load_alu={} mem_write={} event_write={} "
      "other_t3={} clamped={} midpkt={} oddbytes={}",
      g_pktCap.descriptors.load(), g_pktCap.dwords.load(),
      g_pktCap.clsDescBatch.load(), g_pktCap.clsIndirect.load(),
      g_pktCap.clsRawEnvelope.load(), g_pktCap.type0.load(),
      g_pktCap.type1.load(), g_pktCap.type2Nop.load(), g_pktCap.t3Nop.load(),
      g_pktCap.t3DrawIndx.load(), g_pktCap.t3DrawIndx2.load(),
      g_pktCap.t3ImLoad.load(), g_pktCap.t3SetConstant.load(),
      g_pktCap.t3LoadAluConst.load(), g_pktCap.t3MemWrite.load(),
      g_pktCap.t3EventWrite.load(), g_pktCap.t3Other.load(),
      g_pktCap.clampedWindow.load(), g_pktCap.midPacket.load(),
      g_pktCap.oddBytes.load());
}

} // namespace

PPC_FUNC(sub_82411640) {
  const uint32_t n = s_h11640.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t flags = ctx.r4.u32;
  const uint32_t slotAddr = ctx.r5.u32;
  const uint32_t alignBytes = ctx.r6.u32; // volatile reg: snapshot pre-call

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t requested = 0;
  const bool haveReq = mem.ReadU32BE(slotAddr, &requested);
  if (!haveReq) {
    static std::atomic<bool> slotWarned{false};
    if (!slotWarned.exchange(true))
      MCLA_LOG_WARN("PKT-CAP: size-slot read failed dev={:08X} @ {:08X}", dev,
                    slotAddr);
    __imp__sub_82411640(ctx, base);
    return;
  }

  __imp__sub_82411640(ctx, base);

  // Post-passthrough: consumed bytes in slot[0], reserved window in r3.
  uint32_t consumed = 0;
  if (!mem.ReadU32BE(slotAddr, &consumed))
    return;

  const uint32_t window = ctx.r3.u32;

  // Drain previously reserved windows first - their builders have filled
  // them by now. THEN queue the freshly reserved (still empty) window.
  {
    std::lock_guard<std::mutex> lock(s_pendingMtx);
    for (uint32_t i = 0; i < g_pendingCount; ++i)
      CaptureWindow(n, dev, g_pending[i]);
    g_pendingCount = 0;

    if (window != 0 && consumed != 0 && g_pendingCount < kPktCapPendingMax) {
      g_pending[g_pendingCount].addr = window;
      g_pending[g_pendingCount].dwords = consumed / 4u;
      g_pending[g_pendingCount].flags = flags;
      g_pending[g_pendingCount].alignBytes = alignBytes;
      ++g_pendingCount;
    }
  }

  if (n <= 16 || (n % 5000) == 0)
    MCLA_LOG_INFO("HELPER-thunk sub_82411640 hit #{} dev={:08X} f={} req={}", n,
                  dev, flags, requested);

  // 640 fires ~handful of times per boot (init/state batches), so summarize
  // every hit during the early run + on a LOW cadence afterwards - this
  // guarantees per-run gate metrics regardless of submission volume.
  if (n <= 32 || (n % 100) == 0) {
    {
      std::lock_guard<std::mutex> lock(s_pendingMtx);
      for (uint32_t i = 0; i < g_pendingCount; ++i)
        CaptureWindow(n, dev, g_pending[i]);
      g_pendingCount = 0;
    }
    LogSummary(n);
  }
}

// ---------------------------------------------------------------------------
// P4' submit-family census (reverser-ranked per-frame seam candidates).
// Log-only passthrough overrides; each size-class helper embeds its OWN
// reserver clone (dev+14908/14916 accessed directly in 11840 at
// ppc_recomp.77.cpp:20129), which is why 640 stays cold while frames flow.
// Ranked targets: sub_82420BA8 (per-batch draw submit), sub_82413660 (draw-
// packet builder), sub_8241BD08 (flush/kick), sub_82429570/sub_824294E0
// (present kickers, DEBCBEEF marker).
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// P4' CAPTURE (session 24): SubmitBatch = per-batch geometry submit
// (DrawIndexedPrimitive-equivalent, Ghidra-verified). Capture geometry args
// + device state snapshot BEFORE passthrough; legacy rendering unchanged.
// State lives in device shadow blocks - no per-RS-handler overrides needed.
// ---------------------------------------------------------------------------
struct CapturedDrawV1 {
  uint32_t primTypeFlags;
  uint32_t vbDesc[2][4];   // r5/r7 raw {base,stride,size,size}
  uint32_t ibDesc[4];      // r6 raw
  uint32_t ibBase;         // [+0x20] page-aligned | fmt bits0-5
  uint32_t ibCounts;       // [+0x24] 11/13-bit halves split by tiling
  uint32_t indexWidthBits; // [+0x28] bits31-30
  uint32_t dirtyMask[6];   // dev+0x10/+0x18/+0x20 (3x u64)
  static constexpr uint32_t kShadowDwords = 437; // 0x28CC..0x2FA0
  uint32_t shadow[kShadowDwords];
  uint32_t seq;
};

static CapturedDrawV1 g_lastDraw{};
static std::atomic<uint32_t> g_capturedDrawCount{0};

static uint32_t DecodeIndexedCount(uint32_t packedCounts,
                                   uint32_t indexWidthBits,
                                   uint32_t tilingFlags) {
  const uint32_t widthAdjust = ((indexWidthBits >> 31) & 0x1u) * 2u + 1u;
  if ((tilingFlags & 0x600u) == 0x400u)
    return (packedCounts & 0x7FFu) + widthAdjust;
  return (packedCounts & 0x1FFFu) + widthAdjust;
}

const CapturedDrawV1 *mcla_gpu_GetLastCapturedDraw(uint32_t *outTotal);

const CapturedDrawV1 *mcla_gpu_GetLastCapturedDraw(uint32_t *outTotal) {
  if (outTotal) {
    *outTotal = g_capturedDrawCount.load(std::memory_order_relaxed);
  }
  return &g_lastDraw;
}

PPC_FUNC_IMPL(__imp__sub_82420BA8);
static std::atomic<uint32_t> s_h20BA8{0};
PPC_FUNC(sub_82420BA8) {
  // Single owner of the draw-builder seam (S1–S3 consolidation). The removed
  // native_renderer dual-owner hook folded its duties in here.
  mcla::renderer::RecordDrawBuild();
  const uint32_t n = s_h20BA8.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const bool devOk = dev != 0 && mem.IsValid(dev + 0x2FA0, 4);
  if (devOk) {
    const uint32_t r5 = ctx.r5.u32, r6 = ctx.r6.u32, r7 = ctx.r7.u32;
    const bool vb0Ok = mem.IsValid(r5, 16);
    const bool vb1Ok = mem.IsValid(r7, 16);
    const bool ibOk = mem.IsValid(r6, 0x2C);
    CapturedDrawV1 cap{};
    cap.primTypeFlags = ctx.r4.u32;
    if (vb0Ok && vb1Ok && ibOk) {
      for (uint32_t i = 0; i < 4; ++i) {
        (void)mem.ReadU32BE(r5 + i * 4, &cap.vbDesc[0][i]);
        (void)mem.ReadU32BE(r7 + i * 4, &cap.vbDesc[1][i]);
        (void)mem.ReadU32BE(r6 + i * 4, &cap.ibDesc[i]);
      }
      (void)mem.ReadU32BE(r6 + 0x20, &cap.ibBase);
      (void)mem.ReadU32BE(r6 + 0x24, &cap.ibCounts);
      (void)mem.ReadU32BE(r6 + 0x28, &cap.indexWidthBits);
    }
    for (uint32_t w = 0; w < 6; ++w) {
      (void)mem.ReadU32BE(dev + 0x10 + w * 4, &cap.dirtyMask[w]);
    }
    for (uint32_t d = 0; d < CapturedDrawV1::kShadowDwords; ++d) {
      (void)mem.ReadU32BE(dev + 0x28CC + d * 4, &cap.shadow[d]);
    }
    cap.seq = n;

    {
      std::lock_guard<std::mutex> lock(g_drawMutex);
      g_lastDraw = cap;
    }
    const uint32_t total = g_capturedDrawCount.fetch_add(1) + 1;
    if (total == 1 || (total % 500) == 0) {
      MCLA_LOG_INFO(
          "P4'-CAPTURE draw #{} prim={:08X} ibBase={:08X} ibCnt={:08X} "
          "dirty={:08X}{:08X}",
          total, cap.primTypeFlags, cap.ibBase, cap.ibCounts, cap.dirtyMask[1],
          cap.dirtyMask[0]);
    }
  }
  if (n <= 12 || (n % 1000) == 0) {
    uint32_t r5w0 = 0, r5w1 = 0, r5w2 = 0, r5w3 = 0;
    uint32_t r6w0 = 0, r6w1 = 0, r6w2 = 0, r6w3 = 0;
    if (ctx.r5.u32 != 0 && mem.IsValid(ctx.r5.u32, 16)) {
      (void)mem.ReadU32BE(ctx.r5.u32 + 0, &r5w0);
      (void)mem.ReadU32BE(ctx.r5.u32 + 4, &r5w1);
      (void)mem.ReadU32BE(ctx.r5.u32 + 8, &r5w2);
      (void)mem.ReadU32BE(ctx.r5.u32 + 12, &r5w3);
    }
    if (ctx.r6.u32 != 0 && mem.IsValid(ctx.r6.u32, 16)) {
      (void)mem.ReadU32BE(ctx.r6.u32 + 0, &r6w0);
      (void)mem.ReadU32BE(ctx.r6.u32 + 4, &r6w1);
      (void)mem.ReadU32BE(ctx.r6.u32 + 8, &r6w2);
      (void)mem.ReadU32BE(ctx.r6.u32 + 12, &r6w3);
    }
    MCLA_LOG_INFO("SUBMIT-census sub_82420BA8 #{} dev={:08X} flags={:X} "
                  "r5={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "r6={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "r7={:08X} r8={:08X} r9={:08X} r10={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, r5w0, r5w1, r5w2, r5w3,
                  ctx.r6.u32, r6w0, r6w1, r6w2, r6w3, ctx.r7.u32, ctx.r8.u32,
                  ctx.r9.u32, ctx.r10.u32);
  }

  {
    mcla::native::DrawIndexedCommand dic{};
    dic.primitiveTopology = ctx.r4.u32 & 7u;
    if (ctx.r5.u32 != 0 && mem.IsValid(ctx.r5.u32, 16)) {
      (void)mem.ReadU32BE(ctx.r5.u32 + 0, &dic.vbAddr);
      (void)mem.ReadU32BE(ctx.r5.u32 + 4, &dic.vbStride);
      (void)mem.ReadU32BE(ctx.r5.u32 + 8, &dic.vbSize);
    }
    if (ctx.r6.u32 != 0 && mem.IsValid(ctx.r6.u32, 0x34)) {
      (void)mem.ReadU32BE(ctx.r6.u32 + 0, &dic.ibAddr);
      (void)mem.ReadU32BE(ctx.r6.u32 + 4, &dic.ibSize);
      (void)mem.ReadU32BE(ctx.r6.u32 + 8, &dic.ibFormat);
    }
    if (ctx.r6.u32 != 0 && mem.IsValid(ctx.r6.u32 + 0x24, 4)) {
      uint32_t ibCntRaw = 0;
      uint32_t ibWidthRaw = 0;
      uint32_t ibTilingRaw = 0;
      (void)mem.ReadU32BE(ctx.r6.u32 + 0x24, &ibCntRaw);
      (void)mem.ReadU32BE(ctx.r6.u32 + 0x28, &ibWidthRaw);
      (void)mem.ReadU32BE(ctx.r6.u32 + 0x30, &ibTilingRaw);
      dic.indexCount = DecodeIndexedCount(ibCntRaw, ibWidthRaw, ibTilingRaw);
      dic.startIndexLocation = 0;
      dic.baseVertexLocation = 0;
    }

    // Read shader program addresses from MclaGpuContext
    // Device struct layout: sqVsProgram @ +0x3184, sqPsProgram @ +0x3188
    if (dev != 0 && mem.IsValid(dev + 0x3188, 4)) {
      (void)mem.ReadU32BE(dev + 0x3184, &dic.vsProgram);
      (void)mem.ReadU32BE(dev + 0x3188, &dic.psProgram);
    }

    // P5' (B8): only enqueue draws with plausible geometry. The guest
    // calls this builder with null/dummy descriptors during init and
    // menu-state polling; forwarding those just burns queue slots and
    // gets discarded by the render thread's own validation anyway.
    const bool plausible = dic.vbAddr >= 0x10000u && dic.vbSize != 0 &&
                           dic.vbStride != 0 && dic.ibAddr >= 0x10000u &&
                           dic.ibSize != 0 && dic.indexCount != 0;
    if (plausible) {
      mcla::native::g_commandQueue.push(mcla::native::RenderCommand{
          mcla::native::RenderCommand::DRAW_INDEXED, dic});
    }
  }

  // Trace feed (folded from the removed native_renderer dual-owner hook).
  // The accumulator no-ops unless capture mode enabled it via
  // SetCaptureEnabled; the MclaGpuContext overlay is the pre-existing
  // capture-path pattern (S4 inventory — refactor with checked reads when
  // capture_hooks grows a checked-read API).
  if (dev != 0) {
    mcla::native::GetDrawAccumulator()->OnDrawBuild(
        reinterpret_cast<::MclaGpuContext*>(base + dev), ctx);
  }

  __imp__sub_82420BA8(ctx, base);
}

// ---------------------------------------------------------------------------
// P4' CAPTURE: PresentKick frame boundary. sub_824294E0 = raw kick
// (r3=dev, r4=fbAddr); sub_82429570 = vsync-aware flip picker (backbuffer
// idx dev[+0x5498], count [+0x5494], base [+0x548c]). Both emit PM4 flip +
// 0xDEADBEEF fence consumed by ISR 0x82411478.
//
// R1 (2026-09-10): THIS is the native present owner. Guest frame-end
// (sub_82419E90 -> sub_82419E98) calls PresentKick and VdSwap from the same
// path (ppc_recomp.79.cpp:12387/12532). Native mode presents here; VdSwap
// is inert (see native_renderer.cpp Hooked_VdSwap).
// ---------------------------------------------------------------------------
static std::atomic<uint32_t> s_presentKickCount{0};
static std::atomic<uint32_t> s_lastFbAddr{0};

namespace mcla::gpu {
// Global frame counter for draw-flip correlation. Defined early so the
// present-kick hook (sub_824294E0, below) can advance it; the draw hook
// (sub_82413660) and mcla_gpu_GetFrameCounter() read it.
static std::atomic<uint32_t> g_frameCounter{0};
} // namespace mcla::gpu

PPC_FUNC_IMPL(__imp__sub_824294E0);
PPC_FUNC(sub_824294E0) {
  const uint32_t n = s_presentKickCount.fetch_add(1) + 1;
  s_lastFbAddr.store(ctx.r4.u32, std::memory_order_relaxed);
  // P5' (B8) / R1: present kick = frame boundary. Advance frame counter and
  // enqueue host present in native mode (single owner — not VdSwap).
  const uint32_t frame =
      mcla::gpu::g_frameCounter.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 500) == 0)
    MCLA_LOG_INFO("P4'-PRESENT kick #{} dev={:08X} fb={:08X}", n, ctx.r3.u32,
                  ctx.r4.u32);

  mcla::native::GetDrawAccumulator()->OnFrameEnd();
  mcla::native::EnqueueNativePresent(frame, ctx.r3.u32, ctx.r4.u32);
  mcla::renderer::RecordFramePresented();

  __imp__sub_824294E0(ctx, base);
}

// R1 census: high-level frame-end entry. sub_82419E90(r3=dev) forwards to
// sub_824199B0 which runs the flip picker + PresentKick + VdSwap sequence.
// Fires only when the guest actually presents — first hit is the present
// milestone (currently absent through pool-OOM-era boots).
PPC_FUNC_IMPL(__imp__sub_82419E90);
static std::atomic<uint32_t> s_h19E90{0};
PPC_FUNC(sub_82419E90) {
  const uint32_t n = s_h19E90.fetch_add(1) + 1;
  if (n <= 8 || (n % 200) == 0)
    MCLA_LOG_INFO("FRAME-END sub_82419E90 #{} dev={:08X} lr={:08X}", n,
                  ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82419E90(ctx, base);
}

namespace mcla::gpu {

// Captured draw data for native renderer (V2 - safe VB/IB capture)
static CapturedDrawV2 g_lastDrawV2{};

uint32_t mcla_gpu_GetFrameCounter() {
  return g_frameCounter.load(std::memory_order_relaxed);
}

const CapturedDrawV2 *mcla_gpu_GetLastDrawV2() {
  std::lock_guard<std::mutex> lock(g_drawMutex);
  return &g_lastDrawV2;
}

std::mutex &mcla_gpu_GetDrawMutex() { return g_drawMutex; }

} // namespace mcla::gpu

PPC_FUNC_IMPL(__imp__sub_82413660);
static std::atomic<uint32_t> s_h13660{0};
PPC_FUNC(sub_82413660) {
  const uint32_t n = s_h13660.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t r4 = ctx.r4.u32;
  const uint32_t r5 = ctx.r5.u32; // VB desc pointer
  const uint32_t r6 = ctx.r6.u32; // IB desc pointer

  // P4' Step 3: Capture draw submit details
  if (n <= 10 || (n % 1000) == 0) {
    MCLA_LOG_INFO(
        "DRAW-SEAM sub_82413660 #{} dev={:08X} r4={:08X} r5={:08X} "
        "r6={:08X} r7={:08X} r8={:08X} r9={:08X} r10={:08X} lr={:08X}",
        n, dev, r4, r5, r6, ctx.r7.u32, ctx.r8.u32, ctx.r9.u32, ctx.r10.u32,
        ctx.lr);
  }

  // Keep this helper as a diagnostic/state capture seam. Geometry ownership
  // belongs to sub_82420BA8, which has the packed index count and draw flags.
  __imp__sub_82413660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82411840);
static std::atomic<uint32_t> s_h11840{0};
PPC_FUNC(sub_82411840) {
  const uint32_t n = s_h11840.fetch_add(1) + 1;
  if (n <= 12 || (n % 5000) == 0)
    MCLA_LOG_INFO("SUBMIT-census sub_82411840 #{} dev={:08X} cls={} a={}", n,
                  ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
  __imp__sub_82411840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241BD08);
static std::atomic<uint32_t> s_h1BD08{0};
PPC_FUNC(sub_8241BD08) {
  const uint32_t n = s_h1BD08.fetch_add(1) + 1;
  // Single owner of the submit seam (S1–S3 consolidation): frame counters +
  // submit observers folded in from the removed native_renderer hook.
  mcla::renderer::RecordSubmit();
  mcla::renderer::hooks::DispatchBeforeSubmit(ctx, base);
  const uint32_t dev1BD08 = ctx.r3.u32;
  if (dev1BD08 != 0 && dev1BD08 >= 0x1000u) {
    mcla::native::GetDrawAccumulator()->OnSubmit(
        reinterpret_cast<::MclaGpuContext*>(base + dev1BD08), ctx.r4.u32);
  }
  if (n <= 12 || (n % 1000) == 0)
    MCLA_LOG_INFO("SUBMIT-census sub_8241BD08(flush) #{} dev={:08X} r4={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32);
  __imp__sub_8241BD08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82429570);
static std::atomic<uint32_t> s_h29570{0};
PPC_FUNC(sub_82429570) {
  const uint32_t n = s_h29570.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (dev != 0 && mem.IsValid(dev + 0x5498, 4)) {
    uint32_t bbIdx = 0, bbCount = 0, bbBase = 0;
    (void)mem.ReadU32BE(dev + 0x5498, &bbIdx);
    (void)mem.ReadU32BE(dev + 0x5494, &bbCount);
    (void)mem.ReadU32BE(dev + 0x548c, &bbBase);
    if (n <= 12 || (n % 1000) == 0)
      MCLA_LOG_INFO(
          "P4'-PRESENT picker #{} dev={:08X} bb idx={} count={} base={:08X}", n,
          dev, bbIdx, bbCount, bbBase);
  }

  // LOADING-PROGRESS GATE CENSUS (session 65+): after present kick, dump the
  // subctx publication state and fence status to decode what the guest waits
  // on during loading screens (VdSwap ~1/15s, no DRAW_INDEXED).
  if (dev != 0) {
    uint32_t subctx = 0, pub4 = 0, pub8 = 0, pub12 = 0;
    uint32_t put = 0, mask = 0, rptr = 0;
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0) {
      (void)mem.ReadU32BE(subctx + 0, &pub4);   // published rptr
      (void)mem.ReadU32BE(subctx + 4, &pub8);   // kick completion token
      (void)mem.ReadU32BE(subctx + 8, &pub12);  // subctx publication
    }
    (void)mem.ReadU32BE(dev + 10908, &put);
    (void)mem.ReadU32BE(dev + 14900, &mask);
    (void)mem.ReadU32BE(dev + 10912, &rptr);  // CP read pointer
    if (n <= 20 || (n % 500) == 0)
      MCLA_LOG_INFO("LOADING-GATE post-kick #{} dev={:08X} subctx={:08X} "
                    "pub[0..2]={:08X}/{:08X}/{:08X} put={:08X} rptr={:08X} "
                    "mask={:08X} diff={:08X}",
                    n, dev, subctx, pub4, pub8, pub12, put, rptr, mask,
                    (put > pub4) ? (put - pub4) : 0);
  }

  s_presentKickCount.fetch_add(1, std::memory_order_relaxed);
  __imp__sub_82429570(ctx, base);
}

// ---------------------------------------------------------------------------
// RING-WAIT census (2026-08-23): sub_82411928 is the SOLE doorbell-ringer
// module-wide (PPC_MM_STORE_U32(0x7FC80000+1812), 77.cpp:20398). Earlier run:
// 5 reserve passes then silence � thread parked between 11218-return and the
// doorbell store. Log predicate inputs + whether the tail is ever reached.
// Units: dword indices, mask=dev[+14900]; published rptr = subctx[+60].
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411218);
static std::atomic<uint32_t> s_h11218{0};
PPC_FUNC(sub_82411218) {
  const uint32_t n = s_h11218.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t target = ctx.r4.u32;
  const uint32_t bytes = ctx.r5.u32;
  if (dev != 0) {
    mcla::gpu::CpAttachDriverCtx(dev);
  }
  uint32_t mask = 0, subctx = 0, published = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 14900, &mask);
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
      (void)mem.ReadU32BE(subctx + 60, &published);
  }
  // Progress-counter visibility: *(r13+256)+88 of THIS thread (sub_82412F98
  // exits when it advances >=5000 past snapshot). Pump preconditions per
  // gate-cracker E3: dev[+13432]!=0 && blocker [0x827CDA3C]==0.
  uint32_t pcBlk = 0, pcVal = 0, pumpObj = 0, blocker = 0;
  if (PPCContext *pctx = GetPPCContext()) {
    const uint32_t tls = pctx->r13.u32;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    if (tls != 0 && mem.ReadU32BE(tls + 256, &pcBlk) && pcBlk != 0)
      (void)mem.ReadU32BE(pcBlk + 88, &pcVal);
    (void)mem.ReadU32BE(dev + 13432, &pumpObj);
    (void)mem.ReadU32BE(0x827CDA3C, &blocker);
  }
  const bool wraps = ((target + bytes) & ~mask) != (target & ~mask);
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("RW #{:04X} tgt={:05X} b={:X} msk={:X} sc={:X} wb={:X} "
                  "pc={}:{} pump={:08X} blk={:08X} wrap={}",
                  n, target, bytes, mask, subctx, published, pcBlk, pcVal,
                  pumpObj, blocker, wraps ? 1 : 0);
  __imp__sub_82411218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82411928);
static std::atomic<uint32_t> s_h11928{0};
static std::atomic<uint32_t> s_h11928done{0};
PPC_FUNC(sub_82411928) {
  const uint32_t n = s_h11928.fetch_add(1) + 1;
  if (n <= 12 || (n % 2000) == 0)
    MCLA_LOG_INFO("DOORBELL sub_82411928 #{} r3={:08X} r4={:08X} r5={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
  __imp__sub_82411928(ctx, base);
  const uint32_t d = s_h11928done.fetch_add(1) + 1;
  if (d <= 12 || (d % 2000) == 0)
    MCLA_LOG_INFO("DOORBELL sub_82411928 RETURNED #{}", d);
}

// ---------------------------------------------------------------------------
// E98 census (2026-08-23 session 9): sub_82411E94 is an EMPTY padding stub;
// the real wait body is sibling sub_82411E98 (77.cpp:21047-21170), decoded:
//   r4=needed, dev=r3; put=dev[+10908]; pub=*(*(dev+10896)+0)
//   early-exit r4==0 | free>=used | special (r7&0xFF)==0 && needed==put &&
//   dev[+13232]==0 -> sub_82412710; else wait loop: init ctx via
//   sub_82412EA0, poll sub_82412F98 (busy r3=1 keeps looping), recheck
//   needed > pub, destroy ctx via sub_82412ED0.
// Persistent stall shape: needed > published at every recheck. Census pins
// WHICH device spins, the exact predicate words, and THIS thread's progress
// counter (F98's gate input) - discriminates wrong-device mirrors vs frozen
// per-thread progress. Also registers every waiting device so mirror
// maintenance covers it.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82411E98);
static std::atomic<uint32_t> s_h11E98{0};
static std::atomic<uint32_t> s_h11E98done{0};
PPC_FUNC(sub_82411E98) {
  const uint32_t n = s_h11E98.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  const uint32_t needed = ctx.r4.u32;
  const uint32_t arg5 = ctx.r5.u32;
  const uint32_t flags = ctx.r7.u32 & 0xFF;
  if (dev != 0) {
    mcla::gpu::CpAttachDriverCtx(dev);
  }
  uint32_t put = 0, subctx = 0, pub0 = 0, flag13232 = 0, pcBlk = 0, pcVal = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 10908, &put);
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0) {
      (void)mem.ReadU32BE(subctx + 0, &pub0);
    }
    (void)mem.ReadU32BE(dev + 13232, &flag13232);
    if (PPCContext *pctx = GetPPCContext()) {
      const uint32_t tls = pctx->r13.u32;
      if (tls != 0 && mem.ReadU32BE(tls + 256, &pcBlk) && pcBlk != 0) {
        (void)mem.ReadU32BE(pcBlk + 88, &pcVal);
      }
    }
  }
  // Same expression as the generated compare (u32 wraparound semantics).
  const bool waitsAtEntry = needed != 0 && ((put - needed) < (put - pub0));
  if (n <= 16 || (n % 500) == 0) {
    MCLA_LOG_INFO("E98 #{:04X} dev={:08X} need={:08X} put={:08X} pub={:08X} "
                  "f13232={} flg={} wait={} a5={:08X} pc={}:{}",
                  n, dev, needed, put, pub0, flag13232 != 0, flags,
                  waitsAtEntry ? 1 : 0, arg5, pcBlk, pcVal);
  }

  // KDELAY-SC (session 70c): Short-circuit the GPU progress polling loop on the
  // main thread.  When the CP is frozen the consumed-count (pub0 at subctx+0)
  // can never advance to match `needed`, so the generated wait-loop in this
  // function spins forever (polling KeDelayExecutionThread(10ms) which
  // returns STATUS_USER_APC immediately, creating a tight CPU-burning loop).
  //
  // The GPU work was already processed synchronously by the CP doorbell handler
  // before the fence was created (proven in session 69).  pub0 is a formality
  // the frozen CP cannot satisfy.  Forcing it is the honest short-circuit:
  // the work IS done, the counter just can't reflect it.
  //
  // Scoped to main thread only (g_mainGuestThreadId) to prevent side effects
  // on worker threads.  The write uses checked guest memory access and will be
  // harmless once the CP is deleted at P6'.
  if (waitsAtEntry && subctx != 0) {
    const uint32_t mainId = g_mainGuestThreadId.load();
    if (mainId != 0 && GetCurrentThreadId() == mainId) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      MCLA_LOG_INFO("KDELAY-SC #{} E98 stall: tid={:08X} need={:08X} pub={:08X} "
                    "put={:08X} -> forcing pub0={:08X}",
                    n, mainId, needed, pub0, put, needed);
      (void)mem.WriteU32BE(subctx + 0, needed);
      // Also advance the per-thread progress counter (pcBlk+88) so that
      // sub_82412F98's >=5000 delta check is satisfied.
      if (pcBlk != 0) {
        (void)mem.WriteU32BE(pcBlk + 88, pcVal + 6000);
      }
      ctx.r3.u32 = 0;  // STATUS_SUCCESS — wait completed
      return;
    }
  }

  __imp__sub_82411E98(ctx, base);
  const uint32_t d = s_h11E98done.fetch_add(1) + 1;
  if (d <= 16 || (d % 500) == 0)
    MCLA_LOG_INFO("E98 RETURNED #{}", d);
}

// ---------------------------------------------------------------------------
// FLIP-PROCESSOR census: sub_82419718 runs from the vsync ISR type-0 branch
// once gate [0x7FC86544]&1 is set (77.cpp:19534-19547). Per session-5 RE:
// drains flip-request entries at dev[+16572+i*8], MMIO store 0x7FCE6110 per
// entry, callback dev[+16544]. Census proves the gate path executes and dumps
// queue head + present-callback slot.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82419718);
static std::atomic<uint32_t> s_h19718{0};
PPC_FUNC(sub_82419718) {
  const uint32_t n = s_h19718.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  uint32_t cb = 0, q0 = 0, q1 = 0, q2 = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev + 16544, &cb);
    (void)mem.ReadU32BE(dev + 16572, &q0);
    (void)mem.ReadU32BE(dev + 16580, &q1);
    (void)mem.ReadU32BE(dev + 16588, &q2);
  }
  if (n <= 12 || (n % 2000) == 0)
    MCLA_LOG_INFO("FLIP sub_82419718 #{} dev={:08X} cb={:08X} "
                  "q[0..2]={:08X}/{:08X}/{:08X}",
                  n, dev, cb, q0, q1, q2);
  // NOTE: Frame counter is NOT incremented here; it is only advanced in
  // sub_824294E0 (the PresentKick) to avoid double-counting.
  __imp__sub_82419718(ctx, base);
}

// ---------------------------------------------------------------------------
// SLEEP-HELPER census (2026-09-10 KDELAY stall): sub_82460270(ms=r3,
// alertable=r4) is the ONLY body that contains the lr=0x824602C4 site.
// sub_8244FEC0(ms) is a tail-call with r4=0 (single Sleep). Main thread
// parks forever at 10ms — outer poll loop re-enters this helper. Log
// (ms, alertable, caller LR) so the outer loop is named.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82460270);
static std::atomic<uint32_t> s_h60270{0};
PPC_FUNC(sub_82460270) {
  const uint32_t n = s_h60270.fetch_add(1) + 1;
  const uint32_t ms = ctx.r3.u32;
  const uint32_t alertable = ctx.r4.u32 & 0xFF;
  const uint32_t callerLr = static_cast<uint32_t>(ctx.lr);
  if (n <= 40 || (n % 200) == 0)
    MCLA_LOG_INFO("SLEEP60270 #{} ms={} al={} callerLR={:08X}", n, ms,
                  alertable, callerLr);
  __imp__sub_82460270(ctx, base);
}

// ---------------------------------------------------------------------------
// WAIT-HELPER census: sub_82135DC0(handle=r3, timeoutMs=r4, alertable=r5)
// wraps NtWaitForSingleObjectEx in a retry-on-timeout loop
// (ppc_recomp.0.cpp:18590-18654). PARK-SAMPLE caught the main thread parked
// inside it on handle C9ADB800 with ~unit timeout - this pins handle,
// timeout, alertability, and result distribution (257=STATUS_TIMEOUT spin).
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82135DC0);
static std::atomic<uint32_t> s_h135DC0{0};
static std::atomic<uint32_t> s_h135DC0done{0};
PPC_FUNC(sub_82135DC0) {
  const uint32_t n = s_h135DC0.fetch_add(1) + 1;
  const uint32_t handle = ctx.r3.u32;
  const uint32_t timeoutArg = ctx.r4.u32;
  const uint32_t alertable = ctx.r5.u32 & 0xFF;
  // Finite timeouts are the poll patterns (frame pacing etc.) - always
  // surface those up to a cap; infinite worker parks stay throttled.
  const bool finite = timeoutArg != 0xFFFFFFFFu;
  if ((finite && n <= 400) || n <= 12 || (n % 1000) == 0)
    MCLA_LOG_INFO("WAITHELP sub_82135DC0 #{} h={:08X} t={} al={} lr={:08X}", n,
                  handle, timeoutArg, alertable, ctx.lr);
  __imp__sub_82135DC0(ctx, base);
  const uint32_t d = s_h135DC0done.fetch_add(1) + 1;
  if (d <= 12 || (d % 1000) == 0)
    MCLA_LOG_INFO("WAITHELP RETURNED #{} r3={:08X} (257=timeout)", d,
                  ctx.r3.u32);
}

// Non-alertable wrapper (li r5,0 -> DC0, TU0:18580-18587): the MAIN thread's
// park goes through here (PARK-SAMPLE lr=82135DF8 is inside DC0's own
// NtWaitForSingleObjectEx call). Census names each caller site + handle.
PPC_FUNC_IMPL(__imp__sub_82135DB8);
static std::atomic<uint32_t> s_h135DB8{0};
PPC_FUNC(sub_82135DB8) {
  const uint32_t n = s_h135DB8.fetch_add(1) + 1;
  if (n <= 24 || (n % 1000) == 0)
    MCLA_LOG_INFO("WAITB8 sub_82135DB8 #{} h={:08X} t={} lr={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, ctx.lr);
  __imp__sub_82135DB8(ctx, base);
}

// Sync-wait utility (TU17:10837): wait INFINITE non-alertable on r3, return
// r3==0. The main thread's park handle C9ADB800 arrives HERE - capture the
// caller one level up to name the waiting subsystem.
PPC_FUNC_IMPL(__imp__sub_821C90C0);
static std::atomic<uint32_t> s_h90C0{0};
PPC_FUNC(sub_821C90C0) {
  const uint32_t n = s_h90C0.fetch_add(1) + 1;
  const uint32_t handle = ctx.r3.u32;
  const uint32_t caller = ctx.lr;
  if (n <= 24 || (n % 1000) == 0)
    MCLA_LOG_INFO("WAITSYNC sub_821C90C0 #{} h={:08X} caller={:08X}", n, handle,
                  caller);
  __imp__sub_821C90C0(ctx, base);
}

// Task-join table (generated ppc_recomp.15.cpp sub_821BD220):
//   r30 = 0x8283D1AC  (lis -32124 → 0x82840000, addi -11860)
//   count   = *(u32*)(r30-4)  = 0x8283D1A8   // slot count; mask = count-1
//   entries = *(u32*)(r30+24) = 0x8283D1C4
//   idx     = (count-1) & tag
//   entry   = entries + idx * 28
//   entry+0 = key, entry+12 = in-progress flag (join wait word)
constexpr uint32_t kTaskJoinCountAddr = 0x8283D1A8u;
constexpr uint32_t kTaskJoinEntriesAddr = 0x8283D1C4u;
constexpr uint32_t kTaskJoinStride = 28u;

// Clear task_entry+12 for `tag` if the slot is live and still marked busy.
// Used by FENCE-SC: GPU work is already done synchronously, but the join
// in sub_821BD220 would spin forever on a flag the frozen CP never clears.
static bool ClearTaskJoinBusy(uint32_t tag) {
  if (tag == 0xFFFFFFFFu)
    return false;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t count = 0, entries = 0;
  if (!mem.ReadU32BE(kTaskJoinCountAddr, &count) ||
      !mem.ReadU32BE(kTaskJoinEntriesAddr, &entries) || entries == 0)
    return false;
  const uint32_t mask = (count == 0) ? 0u : (count - 1u);
  const uint32_t idx = tag & mask;
  const uint32_t entry = entries + idx * kTaskJoinStride;
  uint32_t key = 0, busy = 0;
  if (!mem.ReadU32BE(entry + 0, &key) || !mem.ReadU32BE(entry + 12, &busy))
    return false;
  if (key != tag)
    return false;
  if (busy == 0)
    return true;
  (void)mem.WriteU32BE(entry + 12, 0);
  MCLA_LOG_INFO("TASKJOIN-SC tag={:08X} idx={} entry={:08X} busy {:08X}->0", tag,
                idx, entry, busy);
  return true;
}

// FENCE-WAIT (TU21:4085): sub_821E5640(obj=r3, blocking=r4, release=r5)
// waits INFINITE on the embedded completion event [obj+8]. Dump the object
// tag/state so the pending async-job TYPE becomes visible; caller LR names
// the submitter (async wrapper sub_821E5FD0 family).
//
// KERNEL SHORT-CIRCUIT (session 69): When blocking=1, pre-release the
// semaphore before calling the original. The GPU work is already done
// (processed synchronously in the CP doorbell handler), so the fence is
// effectively complete. The worker thread that would normally release it
// is parked on its own semaphore and never runs. Pre-releasing lets the
// original WaitForObject return immediately; the original cleanup
// (close handle, zero fields, optional release-flag work) runs normally.
PPC_FUNC_IMPL(__imp__sub_821E5640);
PPC_FUNC_IMPL(__imp__sub_8244ED10);
static std::atomic<uint32_t> s_h5640{0};
PPC_FUNC(sub_821E5640) {
  const uint32_t n = s_h5640.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  const uint32_t blocking = ctx.r4.u32 & 0xFF;
  const uint32_t releaseFlag = ctx.r5.u32 & 0xFF;
  uint32_t tag = 0, state = 0, evt = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(obj + 0, &tag);
    (void)mem.ReadU32BE(obj + 4, &state);
    (void)mem.ReadU32BE(obj + 8, &evt);
  }

  // KERNEL SHORT-CIRCUIT (session 69/70c): When blocking=1, pre-release the
  // semaphore before calling the original. The GPU work is already done
  // (processed synchronously in the CP doorbell handler), so the fence is
  // effectively complete. The worker thread that would normally release it
  // is parked on its own semaphore and never runs. Pre-releasing lets the
  // original WaitForObject return immediately; the original cleanup
  // (close handle, zero fields, optional release-flag work) runs normally.
  //
  // v1 failed because GetKernelObject(handle) returned raw guest memory
  // instead of the canonical WrapperIdentityMap wrapper — Wait() saw count=0
  // on the wrong object.  With GetKernelObject fixed (session 70c) to route
  // through QueryKernelObject, both Release and Wait now operate on the same
  // host wrapper.
  //
  // TASKJOIN-SC (session 72): after the semaphore pre-release, also clear
  // task_entry+12 for this tag. Probe soak proved main then entered
  // sub_821BD220's 10ms join on a busy flag the reinitialized CP never
  // publishes. Same "work IS done" honesty as E98/KDELAY-SC.
  if (blocking == 1 && evt != 0) {
    MCLA_LOG_INFO("FENCE-SC #{} obj={:08X} tag={:08X} ev={:08X} rel={} lr={:08X}",
                  n, obj, tag, evt, releaseFlag, ctx.lr);
    const uint32_t sr3 = ctx.r3.u32, sr4 = ctx.r4.u32, sr5 = ctx.r5.u32;
    ctx.r3.u32 = evt;
    ctx.r4.u32 = 1;
    ctx.r5.u32 = 0;
    __imp__sub_8244ED10(ctx, base);
    ctx.r3.u32 = sr3;
    ctx.r4.u32 = sr4;
    ctx.r5.u32 = sr5;
    if (releaseFlag != 0)
      (void)ClearTaskJoinBusy(tag);
  }

  if (n <= 24 || (n % 500) == 0)
    MCLA_LOG_INFO("FENCE sub_821E5640 #{} obj={:08X} tag={:08X} st={} "
                  "ev={:08X} blk={} lr={:08X}",
                  n, obj, tag, state, evt, blocking, ctx.lr);
  __imp__sub_821E5640(ctx, base);
}

// TASK-JOIN census + short-circuit (session 72): sub_821BD220(tag) joins a
// 28-byte task-table slot, spinning Sleep(10) while entry+12 != 0. Probe
// pinned callerLR=0x821BD334 on the main-thread KDELAY flood. When the slot
// is already known-done (FENCE-SC / TASKJOIN-SC), force busy=0 so the join
// exits. Scoped to main thread to avoid side effects on real worker joins.
PPC_FUNC_IMPL(__imp__sub_821BD220);
static std::atomic<uint32_t> s_hBD220{0};
PPC_FUNC(sub_821BD220) {
  const uint32_t n = s_hBD220.fetch_add(1) + 1;
  const uint32_t tag = ctx.r3.u32;
  uint32_t count = 0, entries = 0, entry = 0, key = 0, busy = 0, idx = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(kTaskJoinCountAddr, &count);
    (void)mem.ReadU32BE(kTaskJoinEntriesAddr, &entries);
    if (entries != 0 && count != 0) {
      idx = tag & (count - 1u);
      entry = entries + idx * kTaskJoinStride;
      (void)mem.ReadU32BE(entry + 0, &key);
      (void)mem.ReadU32BE(entry + 12, &busy);
    }
  }
  if (n <= 32 || (n % 200) == 0)
    MCLA_LOG_INFO("TASKJOIN sub_821BD220 #{} tag={:08X} count={} idx={} "
                  "entry={:08X} key={:08X} busy={:08X} lr={:08X}",
                  n, tag, count, idx, entry, key, busy, ctx.lr);

  // Honest short-circuit: if this is the main-thread join on a slot that is
  // still marked busy, force busy=0 so the 10ms spin can exit. GPU work for
  // FENCE-SC tags is already done synchronously.
  if (busy != 0 && key == tag) {
    const uint32_t mainId = g_mainGuestThreadId.load();
    if (mainId != 0 && GetCurrentThreadId() == mainId) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      MCLA_LOG_INFO("TASKJOIN-SC #{} tag={:08X} entry={:08X} busy {:08X}->0 "
                    "(main)",
                    n, tag, entry, busy);
      (void)mem.WriteU32BE(entry + 12, 0);
    }
  }
  __imp__sub_821BD220(ctx, base);
}

// INFLATE-BEGIN pass-through (session 72): zlibInflater::InflateBegin
// (sub_821D5E10) fatals unless the stream starts with XCompress magic
// 0x0FF512EF. Our VFS serves already-extracted raw files (vfs_rpf.h),
// so the magic check fires on every named resource (meshtextures, …).
// Honest short-circuit: if the stream does not carry the magic, copy the
// remaining input to the output as uncompressed and advance the state —
// same shape as the post-decompress pointer update in generated.
//
// state (r4) layout from ppc_recomp.19.cpp sub_821D5E10:
//   +0  remaining input bytes
//   +4  input pointer
//   +8  bytes consumed/produced so far (0 at stream start)
//   +12 expected total output (from XCompress header+4)
//   +16 remaining output space
//   +20 output pointer
//   +24 total produced
constexpr uint32_t kXCompressMagic = 0x0FF512EFu;
PPC_FUNC_IMPL(__imp__sub_821D5E10);
static std::atomic<uint32_t> s_h5E10{0};
static std::atomic<uint32_t> s_h5E10pt{0};
PPC_FUNC(sub_821D5E10) {
  const uint32_t n = s_h5E10.fetch_add(1) + 1;
  const uint32_t st = ctx.r4.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t inLeft = 0, inPtr = 0, consumed = 0, expected = 0;
  uint32_t outLeft = 0, outPtr = 0, produced = 0;
  (void)mem.ReadU32BE(st + 0, &inLeft);
  (void)mem.ReadU32BE(st + 4, &inPtr);
  (void)mem.ReadU32BE(st + 8, &consumed);
  (void)mem.ReadU32BE(st + 12, &expected);
  (void)mem.ReadU32BE(st + 16, &outLeft);
  (void)mem.ReadU32BE(st + 20, &outPtr);
  (void)mem.ReadU32BE(st + 24, &produced);

  uint32_t magic = 0;
  if (consumed == 0 && inLeft >= 4 && inPtr != 0)
    (void)mem.ReadU32BE(inPtr, &magic);

  // Session 72: empty input — nothing to inflate. The guest re-enters with
  // in=0 consumed=0xFFFFFFF4 forever (INFLATE #286600+). Mark the stream
  // fully consumed so the caller's progress check exits; do not call the
  // original (it would spin or AV on a corrupt state).
  if (inLeft == 0) {
    static std::atomic<uint32_t> s_h5E10empty{0};
    const uint32_t e = s_h5E10empty.fetch_add(1) + 1;
    if (e <= 8 || (e % 1000) == 0)
      MCLA_LOG_WARN("INFLATE-EMPTY #{} st={:08X} consumed={} (bail)", e, st,
                    consumed);
    // Normalize state: no input left, consumed covers all, expected=0.
    (void)mem.WriteU32BE(st + 0, 0);
    (void)mem.WriteU32BE(st + 8, 0);
    (void)mem.WriteU32BE(st + 12, 0);
    return;
  }

  if (n <= 16 || (n % 200) == 0)
    MCLA_LOG_INFO("INFLATE #{} st={:08X} in={} out={} consumed={} magic={:08X} "
                  "lr={:08X}",
                  n, st, inLeft, outLeft, consumed, magic, ctx.lr);

  if (consumed == 0 && inLeft >= 4 && magic != kXCompressMagic &&
      inPtr != 0 && outPtr != 0) {
    // Session 72: do NOT copy unknown-magic bytes into the output. A
    // 525DE064 stream was pass-through'd raw and the guest parser produced
    // wild pointer 0x7E780000 → AV in sub_821DEE40. Skip the XCompress
    // fatal, consume the stream, emit nothing. Guest sees empty output.
    (void)mem.WriteU32BE(st + 0, 0);       // inLeft = 0
    (void)mem.WriteU32BE(st + 8, inLeft);  // consumed = all input
    (void)mem.WriteU32BE(st + 12, 0);      // expected = 0
    const uint32_t pt = s_h5E10pt.fetch_add(1) + 1;
    if (pt <= 16 || (pt % 50) == 0)
      MCLA_LOG_WARN("INFLATE-SKIP #{} magic={:08X} in={} out={} (no XCompress "
                    "header — skip fatal, emit 0)",
                    pt, magic, inLeft, outLeft);
    return;
  }
  __imp__sub_821D5E10(ctx, base);
}

// TASK-COMPLETE census: sub_8244EE00 runs after every pool-worker task
// execution (TU16:15473, sysTaskExecutor pool proc 821C4528). If tasks ever
// execute, this fires - and its release chain should wake the parked fence.
PPC_FUNC_IMPL(__imp__sub_8244EE00);
static std::atomic<uint32_t> s_h4EE00{0};
PPC_FUNC(sub_8244EE00) {
  const uint32_t n = s_h4EE00.fetch_add(1) + 1;
  if (n <= 24 || (n % 2000) == 0)
    MCLA_LOG_INFO("TASK-DONE sub_8244EE00 #{} arg={:08X}", n, ctx.r3.u32);
  __imp__sub_8244EE00(ctx, base);
}

// ENQUEUE-CHOOSER census: Function_821BCB10 decides inline-execute vs
// ring-A vs ring-B push vs reject (Ghidra: [obj+4]!=0 -> inline ret -1;
// ring full -> ret 0 = silent dead-end; else slot id). MINIMAL form:
// registers only - a prior version that read guest memory here crashed the
// first invocation (fault sub_821BCB10+0x7B, the vtable-dispatch region).
PPC_FUNC_IMPL(__imp__sub_821BCB10);
static std::atomic<uint32_t> s_hBCB10{0};
PPC_FUNC(sub_821BCB10) {
  const uint32_t n = s_hBCB10.fetch_add(1) + 1;
  const uint32_t a0 = ctx.r3.u32;
  const uint32_t a6 = ctx.r7.u32;
  __imp__sub_821BCB10(ctx, base);
  if (n <= 16 || (n % 500) == 0)
    MCLA_LOG_INFO("ENQ sub_821BCB10 #{} a0={:08X} cb={:08X} -> r3={:08X}", n,
                  a0, a6, ctx.r3.u32);
}

// INLINE-TASK-EXEC census: 0x821bc140 executes a task descriptor directly
// (the [obj+4]!=0 path). If this fires for op tag=4, the task ran inline and
// its own completion step is what silently failed.
PPC_FUNC_IMPL(__imp__sub_821BC140);
static std::atomic<uint32_t> s_hBC140{0};
PPC_FUNC(sub_821BC140) {
  const uint32_t n = s_hBC140.fetch_add(1) + 1;
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("INLINE-EXEC sub_821BC140 #{} a0={:08X} a1={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.lr);
  // NODE-CHAIN DUMP (session 19): the dispatched fnptr was ZERO. Walk the
  // list head a0 -> [a0+4]=node {node[0] ?, node[4]=fnptr, node[12]=next}
  // up to 3 nodes with checked reads (body starts with plain guest loads,
  // no early vtable dispatch - safe to pre-read).
  if (n <= 8) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t node = 0;
    if (mem.ReadU32BE(ctx.r3.u32 + 4, &node)) {
      for (int i = 0; i < 3 && node != 0; ++i) {
        uint32_t w0 = 0, fn = 0, nx = 0;
        const bool ok0 = mem.ReadU32BE(node + 0, &w0);
        const bool okf = mem.ReadU32BE(node + 4, &fn);
        const bool okn = mem.ReadU32BE(node + 12, &nx);
        MCLA_LOG_INFO("NODE[{}] @ {:08X} w0={:08X}{} fn={:08X}{} next={:08X}{}",
                      i, node, w0, ok0 ? "" : "?", fn, okf ? "" : "?", nx,
                      okn ? "" : "?");
        node = nx;
      }
    }
  }
  __imp__sub_821BC140(ctx, base);
}

// RING-B CONSUMER census: threads #14/#15 run Function_821BC910(arg=0/1).
// Entry = thread start; RETURN = one full wait->pop->maybe-execute cycle
// completed. If returns happen but INLINE-EXEC stays 0, the consumer woke,
// popped, and SKIPPED (slot[0x60C]==0 or empty slot). If no return after the
// wake release, our host semaphore wake is broken for this handle.
PPC_FUNC_IMPL(__imp__sub_821BC910);
static std::atomic<uint32_t> s_hBC910in{0};
static std::atomic<uint32_t> s_hBC910out{0};
PPC_FUNC(sub_821BC910) {
  const uint32_t n = s_hBC910in.fetch_add(1) + 1;
  if (n <= 8)
    MCLA_LOG_INFO("RINGB-CONSUMER sub_821BC910 ENTER #{} arg={:08X}", n,
                  ctx.r3.u32);
  __imp__sub_821BC910(ctx, base);
  const uint32_t d = s_hBC910out.fetch_add(1) + 1;
  // Counters for BOTH consumer queues (arg 0 -> base+0, arg 1 -> +0x6174).
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t w0 = 0, p0 = 0, c0 = 0, w1 = 0, p1 = 0, c1 = 0;
    (void)mem.ReadU32BE(0x82849518u + 0x6160, &w0);
    (void)mem.ReadU32BE(0x82849518u + 0x6164, &p0);
    (void)mem.ReadU32BE(0x82849518u + 0x6168, &c0);
    (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6160, &w1);
    (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6164, &p1);
    (void)mem.ReadU32BE(0x82849518u + 0x6174 + 0x6168, &c1);
    MCLA_LOG_INFO("RINGB-CONSUMER CYCLE #{} r3={:08X} q0 w/p/c={}/{}/{} q1 "
                  "w/p/c={}/{}/{}",
                  d, ctx.r3.u32, w0, p0, c0, w1, p1, c1);
  }
}

// PRODUCER-PUSH census (session 16): Function_821BC868 pushes a task slot
// and releases [q+0x616C]. Queue base family = 0x82849518 + idx*0x6174 (ring
// B) / 0x8283D218 family (ring A) - both sides agree statically, so log the
// ACTUAL q pointer to see which index/instance the parked submit used.
// Register-only entry logging (crash lesson from BCB10+0x7B).
PPC_FUNC_IMPL(__imp__sub_821BC868);
static std::atomic<uint32_t> s_hBC868{0};
PPC_FUNC(sub_821BC868) {
  const uint32_t n = s_hBC868.fetch_add(1) + 1;
  const uint32_t q = ctx.r3.u32;
  __imp__sub_821BC868(ctx, base);
  // Queue-counter dump (session 20): write idx [+0x6160], pop idx
  // [+0x6164], count [+0x6168]. Prove/disprove stale-pop: if pop idx or
  // count was non-zero BEFORE our first real push, the consumer woke on a
  // leaked increment and executed a stale zeroed slot.
  if (n <= 16 || (n % 2000) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t wIdx = 0, pIdx = 0, cnt = 0, relH = 0;
    const bool okW = mem.ReadU32BE(q + 0x6160, &wIdx);
    const bool okP = mem.ReadU32BE(q + 0x6164, &pIdx);
    const bool okC = mem.ReadU32BE(q + 0x6168, &cnt);
    const bool okR = mem.ReadU32BE(q + 0x616C, &relH);
    MCLA_LOG_INFO(
        "PUSH sub_821BC868 #{} q={:08X} wIdx={}{} pIdx={}{} cnt={}{} "
        "relH={:08X}{} lr={:08X}",
        n, q, wIdx, okW ? "" : "?", pIdx, okP ? "" : "?", cnt, okC ? "" : "?",
        relH, okR ? "" : "?", ctx.lr);
  }
}

// RELEASE-HANDLE census (session 72): sub_821C9108(h) → sub_8244ED10(h,1,0).
// Ring-B PUSH should release queue+0x616C to wake the consumer parked on
// C5000300. That SIGNAL never appeared. Dump every release handle.
PPC_FUNC_IMPL(__imp__sub_821C9108);
static std::atomic<uint32_t> s_hC9108{0};
PPC_FUNC(sub_821C9108) {
  const uint32_t n = s_hC9108.fetch_add(1) + 1;
  const uint32_t h = ctx.r3.u32;
  if (n <= 40 || (n % 500) == 0)
    MCLA_LOG_INFO("RELSEMA sub_821C9108 #{} h={:08X} lr={:08X}", n, h,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821C9108(ctx, base);
}

// ---------------------------------------------------------------------------
// TU83 DRIVER-WORKER census: sub_824569C8 is the worker loop the main guest
// thread parks inside (sibling 824569C4 = empty padding stub). Its global
// block 0x827D3738: event-handle@+52 (PARK-SAMPLE saw C9ADB800),
// deadline@+128/+132, lazy-init@+184, wake flags@+188/+196/+200/+208/+212.
// Census dumps all wake-relevant fields + caller LR at entry so we can pin
// which field transition must lift the park. No direct callers exist
// module-wide => invoked as a thread entry / function pointer.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_824569C8);
static std::atomic<uint32_t> s_h569C8{0};
PPC_FUNC(sub_824569C8) {
  const uint32_t n = s_h569C8.fetch_add(1) + 1;
  constexpr uint32_t kBlk = 0x827D3738u;
  const uint32_t lr = ctx.lr;
  uint32_t ev52 = 0, dl128 = 0, dl132 = 0, f184 = 0, f188 = 0, f196 = 0;
  uint32_t f200 = 0, f208 = 0, f212 = 0, cbTarget = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(kBlk + 52, &ev52);
    (void)mem.ReadU32BE(kBlk + 128, &dl128);
    (void)mem.ReadU32BE(kBlk + 132, &dl132);
    (void)mem.ReadU32BE(kBlk + 184, &f184);
    (void)mem.ReadU32BE(kBlk + 188, &f188);
    (void)mem.ReadU32BE(kBlk + 196, &f196);
    (void)mem.ReadU32BE(kBlk + 200, &f200);
    (void)mem.ReadU32BE(kBlk + 208, &f208);
    (void)mem.ReadU32BE(kBlk + 212, &f212);
    uint32_t cbStruct = 0;
    if (mem.ReadU32BE(0x82945A80u + 16, &cbStruct) && cbStruct != 0) {
      (void)mem.ReadU32BE(cbStruct, &cbTarget);
    }
  }
  MCLA_LOG_WARN("WORKER sub_824569C8 #{} lr={:08X} ev={:08X} dl={:08X}/{:08X} "
         "f184={} f188={:08X} f196={:08X} f200={:08X} f208={:08X} f212={:08X} "
         "cbt={:08X}",
         n, lr, ev52, dl128, dl132, f184 != 0, f188, f196, f200, f208, f212,
         cbTarget);
  __imp__sub_824569C8(ctx, base);
}

// ---------------------------------------------------------------------------
// GPU fence wait short-circuit: sub_82412F98 busy-loops reading
// *(TLS_block+332) but the CP drain only writes to *(TLS_block+88).
// The fence never signals, parking the main thread forever in boot.
// Override returns r3=0 (success) to unblock boot → start menu.
// Reference: PARK-SAMPLE shows thread stuck at lr=82412FA0 (mid-function
// label inside sub_82412F98), polling dev+10896 sub-context via TLS.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82412F98);
static std::atomic<uint32_t> s_h12F98{0};
PPC_FUNC(sub_82412F98) {
  const uint32_t n = s_h12F98.fetch_add(1) + 1;
  // r3 = frame pointer, *(r3+0) = device context
  const uint32_t dev = ctx.r3.u32;
  uint32_t actualDev = 0;
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadU32BE(dev, &actualDev);
  }
  MCLA_LOG_WARN("F98-SKIP #{} frame={:08X} dev={:08X} lr={:08X}", n, dev, actualDev, ctx.lr);
  
  // Also log the TLS block fence addresses being polled
  if (n <= 10) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t tlsBlock = dev + 0x14C; // TLS block offset from device
    uint32_t tlsFence = 0, tlsCp = 0;
    mem.ReadU32BE(tlsBlock + 88, &tlsCp); // CP write pointer
    mem.ReadU32BE(tlsBlock + 332, &tlsFence); // Fence being polled
    MCLA_LOG_WARN("F98-TLS dev={:08X} tlsBlock={:08X} cpPtr={:08X} fencePoll={:08X}", 
        dev, tlsBlock, tlsCp, tlsFence);
  }
  ctx.r3.u64 = 0; // return 0 = "fence satisfied, proceed"
}
