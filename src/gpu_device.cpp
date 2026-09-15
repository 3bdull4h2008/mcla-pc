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
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <mutex>
#include <dbghelp.h>
#include <unordered_map>
#include <iterator>
#include <string>

extern std::atomic<uint32_t> g_mainGuestThreadId;

// Defined later near the embedded-list helpers; used by GETDEV so the
// 0x827D838C device has a live vtable when callers dispatch +88.
static void EnsureMemoryDeviceVtable();
static constexpr uint32_t kMemDeviceObj = 0x827D838Cu;

// Used by several later censuses (CBSETUP/GETDEV/MOUNT/TOC76); defined here
// so it is visible at every use site.
static void MclaSanitizePath(char *buf, size_t cap) {
  buf[cap - 1] = 0;
  for (size_t i = 0; i + 1 < cap; ++i) {
    unsigned char c = static_cast<unsigned char>(buf[i]);
    if (c == 0) break;
    if (c < 0x20 || c > 0x7E) {
      buf[i] = 0;
      break;
    }
  }
}

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
  // Single owner of the draw-builder seam (S1â€“S3 consolidation). The removed
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
    uint32_t streamCount = 0, vb0base = 0, vb0stride = 0, vb0size = 0;
    if (dev != 0 && mem.IsValid(dev + 12748, 16)) {
      (void)mem.ReadU32BE(dev + 12748, &streamCount);
      (void)mem.ReadU32BE(dev + 12756, &vb0base);
      (void)mem.ReadU32BE(dev + 12760, &vb0stride);
      (void)mem.ReadU32BE(dev + 12764, &vb0size);
    }
    MCLA_LOG_INFO("SUBMIT-census sub_82420BA8 #{} dev={:08X} flags={:X} lr={:08X} "
                  "streams={} vb0=[{:08X},{:08X},{:08X}] "
                  "r5={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "r6={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "r7={:08X} r8={:08X} r9={:08X} r10={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr),
                  streamCount, vb0base, vb0stride, vb0size,
                  ctx.r5.u32, r5w0, r5w1, r5w2, r5w3,
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
  // capture-path pattern (S4 inventory â€” refactor with checked reads when
  // capture_hooks grows a checked-read API).
  if (dev != 0) {
    mcla::native::GetDrawAccumulator()->OnDrawBuild(
        reinterpret_cast<::MclaGpuContext*>(base + dev), ctx);
  }

  __imp__sub_82420BA8(ctx, base);
}

// ---------------------------------------------------------------------------
// Session 75b census (log-only, no behavior change): who binds streams and
// who enters the real draw wrapper. DRAW_INDEXED stays 0 because the
// 20BA8 hook only sees dummy li-r5=0 submits. Real chain (TU-mapped):
//   sub_8217A470 -> sub_8241BE78 (SetStreams, writes dev+12748 count +
//   VB descs at dev+12756) -> sub_8241C308 (r6 must be IB) -> sub_82420BA8
// ---------------------------------------------------------------------------

PPC_FUNC_IMPL(__imp__sub_8241BE78);
static std::atomic<uint32_t> s_h41BE78{0};
PPC_FUNC(sub_8241BE78) {
  const uint32_t n = s_h41BE78.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("SETSTREAMS-census sub_8241BE78 #{} dev={:08X} count={:08X} "
                  "vbArray={:08X} extra={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8241BE78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241C308);
static std::atomic<uint32_t> s_h41C308{0};
PPC_FUNC(sub_8241C308) {
  const uint32_t n = s_h41C308.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("DRAWWRAP-census sub_8241C308 #{} dev={:08X} flags={:08X} "
                  "r5={:08X} r6={:08X} r7={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  ctx.r7.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8241C308(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8217A470);
static std::atomic<uint32_t> s_h17A470{0};
PPC_FUNC(sub_8217A470) {
  const uint32_t n = s_h17A470.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("SETSTREAMS-CALLER sub_8217A470 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} r6={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8217A470(ctx, base);
}

// Session 75c: real-draw dispatcher gate. sub_82227428 only reaches
// sub_8217A470 (SetStreams) when its dispatch dword == 0x20000000
// (explore mapping of the three bl sites). Loading-screen HUD uses the
// dummy path instead. Census r4 so we can see what type values actually
// arrive.
PPC_FUNC_IMPL(__imp__sub_82227428);
static std::atomic<uint32_t> s_h227428{0};
PPC_FUNC(sub_82227428) {
  const uint32_t n = s_h227428.fetch_add(1) + 1;
  if (n <= 32 || (n % 200) == 0) {
    MCLA_LOG_INFO("DRAWDISP-census sub_82227428 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} r6={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_82227428(ctx, base);
}

// Session 75c: first gate inside the SetStreams caller path.
PPC_FUNC_IMPL(__imp__sub_82178F38);
static std::atomic<uint32_t> s_h178F38{0};
PPC_FUNC(sub_82178F38) {
  __imp__sub_82178F38(ctx, base);
  const uint32_t n = s_h178F38.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    MCLA_LOG_INFO("LOADGATE-census sub_82178F38 #{} ret={} lr={:08X}",
                  n, ctx.r3.s32, static_cast<uint32_t>(ctx.lr));
  }
}

// Session 75d (Ghidra): texture-registry special-name init.
// FUN_82180A30 creates the "none" / "nonresident" fallback objects that
// FUN_821811C0 special-cases by string compare. Called only from 82177248.
PPC_FUNC_IMPL(__imp__sub_82180A30);
static std::atomic<uint32_t> s_h180A30{0};
// Session 75k BOOT LIFE-SUPPORT (not a short-circuit of a guest gate):
// After TEXINIT creates the real "none" object at 0x82839CF0, insert
// names from globaltex.list into the named registry via the guest's own
// insert linker (821854C8). Lookups then HIT the none fallback instead of
// missing and minting CDCDCDCD 64-byte objects. Removes names once a real
// loader fills them (replace on re-insert).
PPC_FUNC_IMPL(__imp__sub_821854C8);
static void MclaBootstrapGlobaltexNames(uint8_t *base) {
  static std::atomic<bool> s_done{false};
  if (s_done.exchange(true))
    return;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t noneObj = 0;
  (void)mem.ReadU32BE(0x82839CF0, &noneObj);
  if (noneObj == 0) {
    MCLA_LOG_WARN("GLOBTEX-BOOT skipped: none object not ready");
    return;
  }
  const char *paths[] = {
      "build/game_data/xarchive_cache/textures/global/cars/globaltex.list",
      "build/game_data/xarchive_cache/textures/global/city/globaltex.list",
  };
  int inserted = 0;
  for (const char *path : paths) {
    std::ifstream in(path);
    if (!in)
      continue;
    std::string line;
    while (std::getline(in, line)) {
      // format: "<name> <file>" â€” first token is the registry name
      const auto sp = line.find_first_of(" \t\r");
      std::string name = (sp == std::string::npos) ? line : line.substr(0, sp);
      while (!name.empty() && (name.back() == '\r' || name.back() == '\n'))
        name.pop_back();
      if (name.empty() || name[0] == '#')
        continue;
      const uint32_t nameAddr =
          mem.Alloc(static_cast<size_t>(name.size()) + 1, 16);
      if (nameAddr == 0)
        continue;
      (void)mem.WriteBytes(nameAddr, name.c_str(),
                           static_cast<uint32_t>(name.size()) + 1);
      PPCContext tmp{};
      tmp.r3.u32 = noneObj;
      tmp.r4.u32 = nameAddr;
      __imp__sub_821854C8(tmp, base);
      ++inserted;
    }
  }
  MCLA_LOG_INFO("GLOBTEX-BOOT inserted={} noneObj={:08X}", inserted, noneObj);
}

PPC_FUNC(sub_82180A30) {
  const uint32_t n = s_h180A30.fetch_add(1) + 1;
  MCLA_LOG_INFO("TEXINIT-census sub_82180A30 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82180A30(ctx, base);
  if (n == 1)
    MclaBootstrapGlobaltexNames(base);
}

PPC_FUNC_IMPL(__imp__sub_82177248);
static std::atomic<uint32_t> s_h177248{0};
PPC_FUNC(sub_82177248) {
  const uint32_t n = s_h177248.fetch_add(1) + 1;
  MCLA_LOG_INFO("TEXINIT-CALLER sub_82177248 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82177248(ctx, base);
}

// Graphics/resource init bundle that calls 82177248 (none/nonresident tex init).
PPC_FUNC_IMPL(__imp__sub_82177948);
static std::atomic<uint32_t> s_h177948{0};
PPC_FUNC(sub_82177948) {
  const uint32_t n = s_h177948.fetch_add(1) + 1;
  MCLA_LOG_INFO("GFXINIT-census sub_82177948 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82177948(ctx, base);
}

// ===========================================================================
// Stage C: Shader dictionary hash-table hydration
//
// ROOT CAUSE (refined): Factory sub_8218BF20 runs 10x creating entries that
// are linked into the active list at 0x82839ED0. The hash table at 0x82839F70
// (256 slots x 4 bytes) is NEVER populated. When sub_82189438 calls
// sub_82189138 (lookup-or-insert), it scans the empty hash table, tries to
// INSERT via sub_82188E50, which calls sub_8218C760 -> sub_821BDF20 to
// resolve the name as a file resource. sub_821BDF20 calls sub_821CB488
// (resource handler lookup) which returns NULL, causing the INSERT to fail.
//
// FIX: After factory completes (10 TEXDICT-CALLER hits), populate the hash
// table with pointers to the factory-created entries. This way sub_82189138
// finds the entries during its linear scan without needing the INSERT path.
// ===========================================================================

// Hash table hydration: populate 0x82839F70 from factory-created entries.
static uint32_t s_factoryEntryPtrs[256] = {};
static std::atomic<uint32_t> s_factoryEntryCount{0};

static void HydrateShaderHashTable() {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  constexpr uint32_t TABLE = 0x82839F70;
  constexpr uint32_t SLOT_COUNT = 256;

  uint32_t count = s_factoryEntryCount.load();
  uint32_t inserted = 0;

  for (uint32_t i = 0; i < count && inserted < SLOT_COUNT; ++i) {
    uint32_t entry = s_factoryEntryPtrs[i];
    if (entry == 0 || !mem.IsValid(entry, 112))
      continue;

    uint32_t slot = 0;
    for (; slot < SLOT_COUNT; ++slot) {
      uint32_t val = 0;
      mem.ReadU32BE(TABLE + slot * 4, &val);
      if (val == 0)
        break;
    }
    if (slot >= SLOT_COUNT)
      break;

    mem.WriteU32BE(TABLE + slot * 4, entry);
    ++inserted;

    uint32_t w[4] = {};
    for (int j = 0; j < 4; ++j)
      (void)mem.ReadU32BE(entry + j * 4, &w[j]);
    MCLA_LOG_INFO("DICT-HYDRATE slot={} entry={:08X} [{:08X} {:08X} {:08X} "
                  "{:08X}]",
                  slot, entry, w[0], w[1], w[2], w[3]);
  }

  MCLA_LOG_INFO("DICT-HYDRATE done: {}/{} entries -> hash table @0x{:08X}",
                inserted, count, TABLE);
}

// Census on sub_82189138 (hash-table lookup-or-insert).
// Scans 256 slots at 0x82839F70 comparing entry+4 hash with target.
// On miss: tries sub_82188E50 (INSERT) twice, then falls to fatal path.
PPC_FUNC_IMPL(__imp__sub_82189138);
static std::atomic<uint32_t> s_h189138{0};
PPC_FUNC(sub_82189138) {
  const uint32_t n = s_h189138.fetch_add(1) + 1;
  const uint32_t name = ctx.r3.u32;

  char nameStr[80] = {0};
  if (name != 0 && name >= 0x82000000 && name < 0x82AD3000) {
    const char *p =
        static_cast<const char *>(mcla::kernel::MmGetHostAddress(name));
    if (p) {
      for (int i = 0; i < 79 && p[i]; ++i)
        nameStr[i] = (p[i] >= 32 && p[i] < 127) ? p[i] : '.';
    }
  }

  const uint32_t lr = static_cast<uint32_t>(ctx.lr);

  __imp__sub_82189138(ctx, base);

  const int32_t result = static_cast<int32_t>(ctx.r3.s32);

  if (result == -1) {
    MCLA_LOG_WARN("DICTLOOKUP-MISS #{} name='{}' ({:08X}) lr={:08X}",
                  n, nameStr, name, lr);
  } else if (n <= 32 || (n % 50) == 0) {
    MCLA_LOG_INFO("DICTLOOKUP-OK #{} name='{}' ({:08X}) slot={} lr={:08X}",
                  n, nameStr, name, result, lr);
  }
}

// Session 75e (IDA): pgDictionary load/register caller.
// sub_82197598 links the dict into active list 0x82839ED0 (not a
// recompiled entry â€” no __imp__). Census its mapped caller instead.
// Stage C: collect entry pointers for hash table hydration.
PPC_FUNC_IMPL(__imp__sub_8218B000);
static std::atomic<uint32_t> s_h18B000{0};
PPC_FUNC(sub_8218B000) {
  const uint32_t n = s_h18B000.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;

  // Collect entry pointer for hash table hydration (Stage C)
  if (obj != 0 && s_factoryEntryCount.load() < 256) {
    s_factoryEntryPtrs[s_factoryEntryCount.fetch_add(1)] = obj;
  }

  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("TEXDICT-CALLER sub_8218B000 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, obj, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8218B000(ctx, base);
  if (n <= 12) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t w[8] = {};
    if (obj != 0 && mem.IsValid(obj, 32)) {
      for (int i = 0; i < 8; ++i)
        (void)mem.ReadU32BE(obj + i * 4, &w[i]);
    }
    MCLA_LOG_INFO("TEXDICT-OBJ #{} @{:08X} [{:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X}]",
                  n, obj, w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7]);
  }

  // Stage C: after factory completes all 10 entries, hydrate the hash table
  if (n == 10) {
    MCLA_LOG_INFO("TEXDICT-CALLER #10 reached â€” triggering hash table hydration");
    HydrateShaderHashTable();
  }
}

// Session 75f (IDA): named-registry INSERT callers.
// sub_82185468 is the hash-table insert into 0x82839E2C. Mapped caller.
PPC_FUNC_IMPL(__imp__sub_821FB1C8);
static std::atomic<uint32_t> s_h1FB1C8{0};
PPC_FUNC(sub_821FB1C8) {
  const uint32_t n = s_h1FB1C8.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("TEXINSERT-CALLER sub_821FB1C8 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821FB1C8(ctx, base);
}

// Session 75g: parent of the globaltex.list preload (82185A40 is a label
// inside this large function). If this never runs, named textures never
// get INSERTED into 0x82839E2C.
PPC_FUNC_IMPL(__imp__sub_82185648);
static std::atomic<uint32_t> s_h185648{0};
PPC_FUNC(sub_82185648) {
  const uint32_t n = s_h185648.fetch_add(1) + 1;
  if (n <= 8) {
    MCLA_LOG_INFO("TEXLOAD-census sub_82185648 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_82185648(ctx, base);
}

// Session 75h: XMemDecompress (RPF3 LZX) â€” the real unsquish for archive
// entries. Doc: docs/MCLA_RPF3_Technical_Reference.txt Â§8.
// 8244FF20 = XMemDecompress dispatcher (codec must be 1/LZX).
// 82460420 = maps inner result to HRESULT.
PPC_FUNC_IMPL(__imp__sub_8244FF20);
static std::atomic<uint32_t> s_h44FF20{0};
PPC_FUNC(sub_8244FF20) {
  const uint32_t n = s_h44FF20.fetch_add(1) + 1;
  const uint32_t ctxp = ctx.r3.u32;
  const uint32_t dest = ctx.r4.u32;
  const uint32_t destSz = ctx.r5.u32;
  const uint32_t src = ctx.r6.u32;
  const uint32_t srcSz = ctx.r7.u32;
  __imp__sub_8244FF20(ctx, base);
  const uint32_t ret = ctx.r3.u32;
  if (n <= 16 || (n % 100) == 0) {
    MCLA_LOG_INFO("XMEM #{} ctx={:08X} dest={:08X} destSz={} src={:08X} "
                  "srcSz={} ret={:08X} lr={:08X}",
                  n, ctxp, dest, destSz, src, srcSz, ret,
                  static_cast<uint32_t>(ctx.lr));
  }
  if (n <= 6 && ret == 0 && dest != 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t head = 0;
    if (mem.IsValid(dest, 4))
      (void)mem.ReadU32BE(dest, &head);
    MCLA_LOG_INFO("XMEM-OUT #{} dest={:08X} head={:08X}", n, dest, head);
  }
}

// Session 75l: streamables loader itself (now a recompiled entry after
// TOML explicit function 0x82216B98 size 0x2B4).
PPC_FUNC_IMPL(__imp__sub_82216B98);
static std::atomic<uint32_t> s_h216B98{0};
PPC_FUNC(sub_82216B98) {
  const uint32_t n = s_h216B98.fetch_add(1) + 1;
  MCLA_LOG_INFO("STREAMTEX-LOADER sub_82216B98 #{} lr={:08X}",
                n, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82216B98(ctx, base);
}

// Session 75i: UI streamables / blank-texture loader caller.
// 82216B98 refs "$/resources/ui/textures/streamables" and "$/textures/blank".
// Not in func map; mapped callers: 821FD6B0, 821FD640, 822012E8.
PPC_FUNC_IMPL(__imp__sub_821FD6B0);
static std::atomic<uint32_t> s_h1FD6B0{0};
PPC_FUNC(sub_821FD6B0) {
  const uint32_t n = s_h1FD6B0.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("STREAMTEX-census sub_821FD6B0 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821FD6B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821FD640);
static std::atomic<uint32_t> s_h1FD640{0};
PPC_FUNC(sub_821FD640) {
  const uint32_t n = s_h1FD640.fetch_add(1) + 1;
  if (n <= 8) {
    MCLA_LOG_INFO("STREAMTEX-PARENT sub_821FD640 #{} lr={:08X}",
                  n, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821FD640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822012E8);
static std::atomic<uint32_t> s_h2012E8{0};
PPC_FUNC(sub_822012E8) {
  const uint32_t n = s_h2012E8.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("UILOAD-census sub_822012E8 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_822012E8(ctx, base);
}

// Session 75j: the empty-dict factory itself (mapped). Requesters 8218D120/
// 8218CB10 never run â€” this is reached via indirect/vtable from unmapped code.
PPC_FUNC_IMPL(__imp__sub_8218BF20);
static std::atomic<uint32_t> s_h18BF20{0};
PPC_FUNC(sub_8218BF20) {
  const uint32_t n = s_h18BF20.fetch_add(1) + 1;
  if (n <= 48 || (n % 100) == 0) {
    // r4 is the deserialization stream the dict is built from:
    // +8 buffer ptr, +24 read cursor, +28 end. Entry format proven in 75l:
    // u8 nameLen + name + u32 hash. Dump the pending name at the cursor.
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t buf = 0, pos = 0, end = 0;
    mem.ReadU32BE(ctx.r4.u32 + 8, &buf);
    mem.ReadU32BE(ctx.r4.u32 + 24, &pos);
    mem.ReadU32BE(ctx.r4.u32 + 28, &end);
    char name[80] = {0};
    uint8_t len = 0;
    if (end > pos && buf != 0) {
      const uint8_t *p =
          static_cast<const uint8_t *>(mcla::kernel::MmGetHostAddress(buf + pos));
      if (p) {
        len = p[0];
        if (len > 0 && len < 70) {
          for (uint32_t i = 0; i < len; ++i)
            name[i] = (p[1 + i] >= 32 && p[1 + i] < 127) ? static_cast<char>(p[1 + i]) : '.';
        }
      }
    }
    MCLA_LOG_INFO("DICTFACT-census sub_8218BF20 #{} r3={:08X} r4={:08X} "
                  "r5={:08X} lr={:08X} stream buf={:08X} pos={:08X} end={:08X} "
                  "left={} name[{}]='{}'",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr), buf, pos, end,
                  end > pos ? end - pos : 0, len, name);
  }
  __imp__sub_8218BF20(ctx, base);
}

// Session 75l: stream slot allocator (fixed 40-byte slot array @0x82860C18,
// per-slot 4KB buffers @0x82860DF8+i*0x1000). Args r4/r5 identify the data
// source feeding the dict deserialization streams.
PPC_FUNC_IMPL(__imp__sub_821BDDE8);
static std::atomic<uint32_t> s_h1BDDE8{0};
PPC_FUNC(sub_821BDDE8) {
  const uint32_t n = s_h1BDDE8.fetch_add(1) + 1;
  if (n <= 32 || (n % 100) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    char a[48] = {0}, b[48] = {0};
    auto dumpstr = [&](uint32_t addr, char *out, size_t cap) {
      if (addr < 0x82000000 || addr > 0x82AD3000) {
        snprintf(out, cap, "%08X", addr);
        return;
      }
      const char *p =
          static_cast<const char *>(mcla::kernel::MmGetHostAddress(addr));
      if (!p) {
        snprintf(out, cap, "%08X?", addr);
        return;
      }
      size_t i = 0;
      for (; i < 40 && p[i]; ++i)
        out[i] = (static_cast<unsigned char>(p[i]) >= 32 &&
                  static_cast<unsigned char>(p[i]) < 127)
                     ? p[i]
                     : '.';
      out[i] = 0;
    };
    dumpstr(ctx.r4.u32, a, sizeof(a));
    dumpstr(ctx.r5.u32, b, sizeof(b));
    MCLA_LOG_INFO("DICTSLOT-ALLOC sub_821BDDE8 #{} r4='{}' r5='{}' lr={:08X}",
                  n, a, b, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821BDDE8(ctx, base);
}

// Session 75j: insert linker called from texture ctor 82185648.
PPC_FUNC_IMPL(__imp__sub_821854C8);
static std::atomic<uint32_t> s_h1854C8{0};
PPC_FUNC(sub_821854C8) {
  const uint32_t n = s_h1854C8.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("TEXINSERT2-census sub_821854C8 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821854C8(ctx, base);
}

// Session 75j: requesters into the empty-dict factory (8218BEB0â†’8218BF20).
PPC_FUNC_IMPL(__imp__sub_8218D120);
static std::atomic<uint32_t> s_h18D120{0};
PPC_FUNC(sub_8218D120) {
  const uint32_t n = s_h18D120.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("DICTREQ-census sub_8218D120 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8218D120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218CB10);
static std::atomic<uint32_t> s_h18CB10{0};
PPC_FUNC(sub_8218CB10) {
  const uint32_t n = s_h18CB10.fetch_add(1) + 1;
  if (n <= 16 || (n % 50) == 0) {
    MCLA_LOG_INFO("DICTREQ2-census sub_8218CB10 #{} r3={:08X} r4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_8218CB10(ctx, base);
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
  const uint32_t dev = ctx.r3.u32; // clobbered by the guest body â€” capture now
  s_lastFbAddr.store(ctx.r4.u32, std::memory_order_relaxed);
  // P5' (B8) / R1: present kick = frame boundary. Advance frame counter and
  // enqueue host present in native mode (single owner â€” not VdSwap).
  const uint32_t frame =
      mcla::gpu::g_frameCounter.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 500) == 0)
    MCLA_LOG_INFO("P4'-PRESENT kick #{} dev={:08X} fb={:08X}", n, ctx.r3.u32,
                  ctx.r4.u32);

  __imp__sub_824294E0(ctx, base);

  // SESSION 73: HW side of the swap-table handshake. The guest reserves two
  // slots per kick by writing ZERO into dev[10896] table at ((queued&7)+16)
  // and ((queued+1&7)+16) (ppc_recomp.79.cpp: r24=0 before both stwx). On HW
  // the display engine later fills the slots with flip timestamps; the
  // completion processor (sub_824286A0) advances dev[+21624] only when the
  // slot at (completed+1&7)+16 is non-zero (lwbrx = little-endian). Without
  // those writes the queue drains never and the >=6 gate at loc_82419FD8
  // stops all kicks after 6 presents. Write a monotonic 64-bit timebase
  // value into both reserved slots, little-endian, like HW.
  {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t tableBase = 0, queued = 0;
    if (dev != 0 && mem.ReadU32BE(dev + 10896, &tableBase) &&
        tableBase != 0 && mem.ReadU32BE(dev + 21628, &queued)) {
      const uint32_t ts = static_cast<uint32_t>(
          mcla::native::QueryGuestTimebase() & 0xFFFFFFFFu) | 1u;
      // The table is 4-BYTE slots (idx 16..23). Write exactly one slot per
      // entry â€” an 8-byte write here spilled into subctx+96 whenever
      // (queued&7)+16 == 23. lwbrx interprets the bytes little-endian.
      for (uint32_t k = 0; k < 2; ++k) {
        const uint32_t off = (((queued + k) & 7u) + 16u) * 4u;
        (void)mem.WriteU32BE(tableBase + off, __builtin_bswap32(ts));
      }
      if (n <= 8 || (n % 500) == 0)
        MCLA_LOG_WARN("SWAP-FILL #{} table={:08X} queued={} ts={:08X}", n,
                      tableBase, queued, ts);
    }
  }

  mcla::native::GetDrawAccumulator()->OnFrameEnd();
  mcla::native::EnqueueNativePresent(frame, ctx.r3.u32, ctx.r4.u32);
  mcla::renderer::RecordFramePresented();
}

// R1 census: high-level frame-end entry. sub_82419E90(r3=dev) forwards to
// sub_824199B0 which runs the flip picker + PresentKick + VdSwap sequence.
// Fires only when the guest actually presents â€” first hit is the present
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

// ---------------------------------------------------------------------------
// SESSION 74 census: tiled 2D surface blit (d3d9-style copy-rect, generated
// impl ppc_recomp.80.cpp:37005). PROVEN corruptor path â€” its two memcpy call
// sites (guest lr 0x82431C5C / 0x82431D18) write 0xCDCDCDCD into the physical
// arena at the allocation frontier (PHYS-OVERRUN @ CAEC5004..CAF04004), which
// clobbers o1heap free-fragment headers: header.size / next_free read back as
// 0xCDCDCDCDCDCDCDCD, unbin() dereferences it, SehO1Allocate swallows the AV
// and returns null -> E_OUTOFMEMORY -> TEXCREATE-SC fakes success -> guest
// null-deref fatal. Capture the inputs to find which one is garbage.
// r3=dst base  r4=width  r5=height  r6=src origin{x,y} (0 => {0,0})
// r7=src base  r8=src pitch  r9=dst rect{x0,y0,x1,y1} (0 => {0,0,r4,r5})
// r10=format/tiling descriptor (bpp + log2 tile shifts)
// Census only: no behaviour change, no D3D12 calls.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82431A40);
static std::atomic<uint32_t> s_h31A40{0};
PPC_FUNC(sub_82431A40) {
  const uint32_t n = s_h31A40.fetch_add(1) + 1;
  const uint32_t dst = ctx.r3.u32;
  const uint32_t w = ctx.r4.u32;
  const uint32_t h = ctx.r5.u32;
  const uint32_t srcOrigin = ctx.r6.u32;
  const uint32_t src = ctx.r7.u32;
  const uint32_t pitch = ctx.r8.u32;
  const uint32_t rectPtr = ctx.r9.u32;
  const uint32_t fmt = ctx.r10.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  const bool log = (n <= 1024) || (n % 256) == 0;

  uint32_t x0 = 0, y0 = 0, x1 = w, y1 = h;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (rectPtr != 0) {
    (void)mem.ReadU32BE(rectPtr + 0, &x0);
    (void)mem.ReadU32BE(rectPtr + 4, &y0);
    (void)mem.ReadU32BE(rectPtr + 8, &x1);
    (void)mem.ReadU32BE(rectPtr + 12, &y1);
  }

  // Source descriptor: good mip-chain blits carry a real one; a garbage or
  // uninitialized descriptor is the other candidate root cause.
  uint32_t sd[8] = {};
  if (log && src != 0) {
    for (uint32_t i = 0; i < 8; ++i)
      (void)mem.ReadU32BE(src + i * 4, &sd[i]);
  }

  const bool dstPhys = (dst >= 0xA0000000u);
  uint32_t aBase = 0, aSize = 0, aLr = 0;
  bool exact = false;
  const bool haveAlloc =
      dstPhys &&
      mcla::kernel::MclaPhysAllocInfo(dst, &aBase, &aSize, &aLr, &exact);
  // The copy extent is RECT-driven: rows = y1-y0, per-row = x1-x0, so the
  // blit writes w*h BYTES. The format/bpp (r10) only sizes an internal
  // staging alloc and is never multiplied into the copy size.
  const uint32_t rectW = (x1 > x0) ? (x1 - x0) : 0u;
  const uint32_t rectH = (y1 > y0) ? (y1 - y0) : 0u;
  const uint64_t need = static_cast<uint64_t>(rectW) * rectH;
  const bool overrun = haveAlloc && exact && need > aSize;

  if (log)
    MCLA_LOG_WARN("BLIT-CAP #{} dst={:08X} src={:08X} pitch={:#x} fmt={:08X} "
                  "rect=[{},{},{},{}] wh={}x{} srcOrigin={:08X} lr={:08X} "
                  "alloc={} size={:#x} allocLr={:08X} exact={} need={:#x} "
                  "overrunBy={:#x}",
                  n, dst, src, pitch, fmt, x0, y0, x1, y1, w, h, srcOrigin, lr,
                  haveAlloc ? aBase : 0u, haveAlloc ? aSize : 0u,
                  haveAlloc ? aLr : 0u, exact, need,
                  overrun ? static_cast<uint32_t>(need - aSize) : 0u);
  if (log)
    MCLA_LOG_WARN("BLIT-SRC #{} src={:08X} [{:08X} {:08X} {:08X} {:08X}] "
                  "[{:08X} {:08X} {:08X} {:08X}]",
                  n, src, sd[0], sd[1], sd[2], sd[3], sd[4], sd[5], sd[6], sd[7]);

  // SESSION 74 GUARD: refuse a provably out-of-bounds blit. Blit #8 is handed
  // a 512x640 RECT against a 0xA000 destination and writes 0x46000 bytes of
  // copied 0xCD straight over o1heap free-fragment headers at the arena
  // frontier â€” that is the AV storm, the E_OUTOFMEMORY cascade and the fatal
  // null-deref. On hardware the surface dims and the buffer always agree; here
  // the source descriptor is uninitialized (fmtEnum=0, flag=1 direct-copy
  // path), so the two disagree. Skipping only when the allocation match is
  // exact leaves every legitimate blit (all #1-#7 fit) untouched. r3 keeps the
  // dst pointer, matching the flag=1 path which applies no dst-base adjust.
  if (overrun) {
    static std::atomic<uint32_t> s_blitGuards{0};
    const uint32_t g = s_blitGuards.fetch_add(1) + 1;
    if (g <= 64 || (g % 500) == 0)
      MCLA_LOG_ERROR("BLIT-OOB-GUARD #{} SKIPPED dst={:08X} size={:#x} "
                     "need={:#x} overrunBy={:#x} rect=[{},{},{},{}] fmt={:08X} "
                     "src={:08X} lr={:08X} allocLr={:08X}",
                     g, dst, aSize, need, static_cast<uint32_t>(need - aSize),
                     x0, y0, x1, y1, fmt, src, lr, aLr);
    return;
  }

  __imp__sub_82431A40(ctx, base);
}

// ---------------------------------------------------------------------------
// SESSION 74 census: sub_824321E0 â€” the copy-rect wrapper, sole caller of the
// blit sub_82431A40 (call site guest 0x82432428). Capturing ITS parameters is
// what separates "destination under-allocated" from "RECT is garbage":
//   r3=dstW r4=dstH (the true surface dims) r5=log2 tile shift
//   r6=src D3DFORMAT enum (0 = invalid/uninitialized; falls through the
//      decoder sub_8240F2A8 to the 1x1-block default)
//   r7=flag bit (0 => tile-adjust path via sub_82432D30, fills a real origin;
//      1 => direct-copy path, leaves origin = caller r9 = 0)
//   r8=dst base/pitch  r9=origin ptr  r10=src base
// Its only caller is sub_82182FA0 (surface copy/update), which also appears in
// the fatal crash stack under the texture placeholder factory sub_82184F58.
// Census only: no behaviour change.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_824321E0);
static std::atomic<uint32_t> s_h321E0{0};
PPC_FUNC(sub_824321E0) {
  const uint32_t n = s_h321E0.fetch_add(1) + 1;
  const uint32_t dstW = ctx.r3.u32;
  const uint32_t dstH = ctx.r4.u32;
  const uint32_t tileShift = ctx.r5.u32;
  const uint32_t fmtEnum = ctx.r6.u32;
  const uint32_t flag = ctx.r7.u32;
  const uint32_t dstBase = ctx.r8.u32;
  const uint32_t origin = ctx.r9.u32;
  const uint32_t src = ctx.r10.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);

  if (n <= 1024 || (n % 256) == 0) {
    uint32_t aBase = 0, aSize = 0, aLr = 0;
    bool exact = false;
    const bool haveAlloc =
        (dstBase >= 0xA0000000u) &&
        mcla::kernel::MclaPhysAllocInfo(dstBase, &aBase, &aSize, &aLr, &exact);
    // What the surface dims imply vs what was actually allocated.
    const uint64_t need =
        static_cast<uint64_t>(dstW) * static_cast<uint64_t>(dstH);
    MCLA_LOG_WARN("BLITWRAP #{} dstW={} dstH={} tileShift={} fmtEnum={:#x} "
                  "flag={} dstBase={:08X} origin={:08X} src={:08X} lr={:08X} "
                  "alloc={} size={:#x} exact={} need={:#x} overrunBy={:#x}",
                  n, dstW, dstH, tileShift, fmtEnum, flag, dstBase, origin, src,
                  lr, haveAlloc ? aBase : 0u, haveAlloc ? aSize : 0u, exact,
                  need,
                  (haveAlloc && exact && need > aSize)
                      ? static_cast<uint32_t>(need - aSize)
                      : 0u);
  }

  __imp__sub_824321E0(ctx, base);
}

// ---------------------------------------------------------------------------
// SESSION 73 census: swap-completion processor. Advances dev[+21624] when
// the swap table (dev[10896]) holds non-zero entries at the completed index.
// Reads are lwbrx (little-endian) â€” the entries are HW-side bytes. Dump the
// table window around the completed index to see why the advance stalls.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_824286A0);
static std::atomic<uint32_t> s_h86A0{0};
PPC_FUNC(sub_824286A0) {
  const uint32_t n = s_h86A0.fetch_add(1) + 1;
  const uint32_t dev = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t completed = 0, queued = 0, tableBase = 0;
  if (dev != 0) {
    (void)mem.ReadU32BE(dev + 21624, &completed);
    (void)mem.ReadU32BE(dev + 21628, &queued);
    (void)mem.ReadU32BE(dev + 10896, &tableBase);
  }
  __imp__sub_824286A0(ctx, base);
  if (n <= 24 || (n % 500) == 0) {
    uint32_t after = 0;
    (void)mem.ReadU32BE(dev + 21624, &after);
    MCLA_LOG_WARN(
        "SWAP-COMP #{} dev={:08X} completed={}->{} queued={} table={:08X}",
        n, dev, completed, after, queued, tableBase);
    if (tableBase != 0) {
      // dump the 8 entry slots (idx 16..23 of the table, 4B each)
      for (uint32_t i = 0; i < 8; ++i) {
        uint32_t v = 0;
        (void)mem.ReadU32BE(tableBase + (16 + i) * 4, &v);
        MCLA_LOG_WARN("  SWAP-COMP slot[{}] = {:08X}", i, v);
      }
    }
  }
}

// ---------------------------------------------------------------------------
// SESSION 73: swap-completion status. The guest stops kicking presents once
// dev[+21628] (queued) - dev[+21624] (completed) >= 6 (gate decoded at
// ppc_recomp.79.cpp loc_82419FD8). Completions advance only when the
// per-frame check sub_82428FD8 sees bit26 of sub_82458030() set â€” that fn
// reads [0x820007E8]=0x10059 then *(u32*)0x10059, a low-memory block the
// 360 kernel populates and our emu never writes (always 0 -> return 0 ->
// completions never advance -> presents stop after 6 kicks).
//
// Single caller (sub_82428FD8), no other hook owner. Additive emulation
// point: pass the original through when it yields a status; otherwise
// report bit26 from the device's real queue state so the completion
// processor drains the swap table exactly like HW.
// ---------------------------------------------------------------------------
PPC_FUNC_IMPL(__imp__sub_82458030);
static std::atomic<uint32_t> s_h58030{0};
PPC_FUNC(sub_82458030) {
  const uint32_t n = s_h58030.fetch_add(1) + 1;
  __imp__sub_82458030(ctx, base);
  if (ctx.r3.u32 != 0)
    return; // guest resolved its own status object â€” trust it

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0;
  (void)mem.ReadU32BE(0x82839254, &dev);
  if (dev == 0)
    return;
  uint32_t queued = 0, completed = 0;
  (void)mem.ReadU32BE(dev + 21628, &queued);
  (void)mem.ReadU32BE(dev + 21624, &completed);
  const uint32_t gap = queued - completed;
  if (gap != 0) {
    // rlwinm r11,r3,0,26,26 == r3 & 0x20: PPC bit 26 is value bit 5.
    ctx.r3.u32 = 0x20u; // swap pending â€” run the completion processor
    if (n <= 16 || (n % 1000) == 0)
      MCLA_LOG_WARN("SWAP-STATUS #{} dev={:08X} queued={} completed={} gap={} "
                    "-> bit26 (emu status; guest chain [0x820007E8]->0x10059 "
                    "reads 0)",
                    n, dev, queued, completed, gap);
  }
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
  // Single owner of the submit seam (S1â€“S3 consolidation): frame counters +
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
// 5 reserve passes then silence ï¿½ thread parked between 11218-return and the
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
      ctx.r3.u32 = 0;  // STATUS_SUCCESS â€” wait completed
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
// parks forever at 10ms â€” outer poll loop re-enters this helper. Log
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
//   r30 = 0x8283D1AC  (lis -32124 â†’ 0x82840000, addi -11860)
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
  // instead of the canonical WrapperIdentityMap wrapper â€” Wait() saw count=0
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
// so the magic check fires on every named resource (meshtextures, â€¦).
// Honest short-circuit: if the stream does not carry the magic, copy the
// remaining input to the output as uncompressed and advance the state â€”
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
static std::atomic<uint32_t> s_maxInflateOut{0};
PPC_FUNC_IMPL(__imp__sub_821D5E10);
static std::atomic<uint32_t> s_h5E10{0};
static std::atomic<uint32_t> s_h5E10pt{0};
static std::atomic<uint32_t> s_h5E10empty{0};
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

  // Session 72: empty input â€” nothing to inflate. The guest re-enters with
  // in=0 consumed=0xFFFFFFF4 forever (INFLATE #286600+). Mark the stream
  // fully consumed so the caller's progress check exits; do not call the
  // original (it would spin or AV on a corrupt state).
  //
  // Session 73 decode of the caller loop (ppc_recomp.15.cpp, LR 0x821BC380):
  //   loc_821BC2D4: if (state.inLeft != 0) goto InflateStep;
  //                 ... async input refill (Sleep(100)-paced) ...
  //   loc_821BC374: InflateStep(state);
  //                 if (state.outLeft /*[r1+112]=state+16*/ != 0) goto 2D4;
  //               exit per stream when outLeft == 0
  // The caller refills input BEFORE re-entering InflateStep, so InflateStep
  // never sees inLeft==0 on a live stream â€” reaching here means the stream
  // is dead/empty. Zeroing outLeft is the caller's own "stream complete"
  // key (same path a descriptor with expected==0 takes); without it the
  // guest spins on the loop forever (INFLATE-EMPTY x1663).
  if (inLeft == 0) {
    // Session 73: empty input â€” original code spun forever (INFLATE
    // x286600+) on a stream whose refill never delivered, so we bailed by
    // zeroing outLeft (the caller loop's exit key).
    //
    // Session 75p CORRECTION: the boot init enqueues batches of streams and
    // calls InflateStep BEFORE the async input refill delivers. Killing
    // those (produced=0, sequential outPtrs, all in one burst) aborted the
    // boot's next load batch â€” the emu has been stalling itself. Distinguish:
    //  - fresh/pending stream (no real progress yet): return WITHOUT touching
    //    state; the caller's own refill pacing re-polls until data arrives.
    //  - genuinely dead (no input after ~20s of paced retries, or the -12
    //    EOF artifact after partial consumption): bail as before.
    static std::mutex s_emptyMtx;
    static std::unordered_map<uint32_t, uint32_t> s_emptyRetries;
    const bool fresh = (consumed == 0 || consumed == 0xFFFFFFF4u) &&
                       produced == 0;
    uint32_t &retries = [&]() -> uint32_t & {
      std::lock_guard<std::mutex> lk(s_emptyMtx);
      return s_emptyRetries[st];
    }();
    if (inPtr != 0 && outPtr != 0 && outLeft != 0 &&
        retries < 200 /* ~20s at 100ms pacing */) {
      retries++;
      if (retries == 1) {
        uint32_t credits = 0;
        (void)mem.ReadU32BE(0x827D74E0u, &credits);
        // Session 75s: capture the HOST callstack to name the caller that
        // drives these calls with a garbage context (lr=1, r1=code).
        static std::atomic<uint32_t> s_btCount{0};
        if (s_btCount.fetch_add(1) < 2) {
          SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
          static std::once_flag symOnce;
          std::call_once(symOnce, []() {
            SymInitialize(GetCurrentProcess(), nullptr, TRUE);
          });
          void *frames[14] = {};
          const USHORT nCap = CaptureStackBackTrace(0, 14, frames, nullptr);
          for (USHORT fi2 = 0; fi2 < nCap; ++fi2) {
            alignas(8) char scratch[sizeof(SYMBOL_INFO) + 128];
            SYMBOL_INFO *si = (SYMBOL_INFO *)scratch;
            si->SizeOfStruct = sizeof(SYMBOL_INFO);
            si->MaxNameLen = 127;
            DWORD64 disp = 0;
            char nameBuf[160];
            const char *name = "???";
            if (SymFromAddr(GetCurrentProcess(), (DWORD64)frames[fi2], &disp,
                            si)) {
              snprintf(nameBuf, sizeof(nameBuf), "%s+0x%llx", si->Name,
                       (unsigned long long)disp);
              name = nameBuf;
            }
            MCLA_LOG_WARN("BT[{}] frame {:02d} {} {}", n, fi2,
                          (void *)frames[fi2], name);
          }
        }
        // lr=1 is bogus â€” walk the stack instead (recompiler frames:
        // [sp]=back, [back-8]=saved lr).
        uint32_t inPtr = 0;
        mem.ReadU32BE(st + 4, &inPtr);
        char chain[120] = {0};
        size_t off = 0;
        uint32_t sp = ctx.r1.u32;
        for (int f = 0; f < 4 && sp != 0 && off + 12 < sizeof(chain); ++f) {
          uint32_t back = 0, lr2 = 0;
          if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
          mem.ReadU32BE(back - 8, &lr2);
          off += static_cast<size_t>(snprintf(chain + off, sizeof(chain) - off,
                                              " f%d=%08X", f, lr2));
          sp = back;
        }
        MCLA_LOG_WARN(
            "INFLATE-PENDING #{} | st={:08X} inPtr={:08X} produced={} "
            "outPtr={:08X} outLeft={} credits={:08X} | lr={:08X} r1={:08X} "
            "hostTid={:08X} | chain='{}'",
            n, st, inPtr, produced, outPtr, outLeft, credits,
            static_cast<uint32_t>(ctx.lr), ctx.r1.u32, GetCurrentThreadId(),
            chain);
        // Session 75v: dump the inner stream's 3 page-cache slots
        // (inner+296/336/356) â€” the fill reads land in page buffers but the
        // buffered reader never matches, so watch the slot state.
        {
          uint32_t inner = 0;
          // 75v fix: the inner object lives at wrapper+32; the wrapper is
          // join_entry+8 (A007D810 in every soak). Do not deref the object
          // to get its vtable â€” we want the OBJECT itself.
          uint32_t wrapper = 0;
          mem.ReadU32BE(0xA0121560u + 8, &wrapper);
          if (wrapper != 0 && wrapper != 0xCDCDCDCDu)
            mem.ReadU32BE(wrapper + 32, &inner);
          if (inner == 0) inner = 0xA0083660u;
          if (inner >= 0xA0000000u && inner != 0xCDCDCDCDu) {
            for (int slot = 0; slot < 3; ++slot) {
              uint32_t sBase = inner + 296u + slot * 40u;
              uint32_t w[9] = {0};
              for (int wi = 0; wi < 9; ++wi)
                mem.ReadU32BE(sBase + wi * 4u, &w[wi]);
              MCLA_LOG_WARN("PAGESLOT[{}] @ {:08X} = [{:08X} {:08X} {:08X} "
                            "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                            slot, sBase, w[0], w[1], w[2], w[3], w[4], w[5],
                            w[6], w[7], w[8]);
            }
            uint32_t i48 = 0, i296 = 0;
            mem.ReadU32BE(inner + 48, &i48);
            mem.ReadU32BE(inner + 296, &i296);
            MCLA_LOG_WARN("INNER {:08X}: [48]={:08X} [296]={:08X}", inner,
                          i48, i296);
          }
        }
        // Session 75q: dump the join table â€” entry+8 = the source stream
        // object whose vtable+28 read returns 0 for this batch.
        uint32_t jcount = 0, jentries = 0;
        mem.ReadU32BE(0x8283D1A8u, &jcount);
        mem.ReadU32BE(0x8283D1C4u, &jentries);
        if (jentries != 0 && jcount != 0) {
          for (uint32_t ji = 0; ji < 8 && ji < jcount; ++ji) {
            uint32_t eBase = jentries + ji * 28u;
            uint32_t key = 0, obj = 0, busy = 0, vt = 0, rd = 0;
            mem.ReadU32BE(eBase + 0, &key);
            mem.ReadU32BE(eBase + 8, &obj);
            mem.ReadU32BE(eBase + 12, &busy);
            if (obj != 0 && obj != 0xCDCDCDCDu) {
              mem.ReadU32BE(obj, &vt);
              if (vt != 0) mem.ReadU32BE(vt + 28, &rd);
              // 75r: wrapper fields +0..+44 (incl. +36 lookup base) and the
              // join entry's own +16/+20/+24 (the request params).
              uint32_t f[12] = {0}, jf[3] = {0};
              for (int fi = 0; fi < 12; ++fi)
                mem.ReadU32BE(obj + 4u * fi, &f[fi]);
              mem.ReadU32BE(eBase + 16, &jf[0]);
              mem.ReadU32BE(eBase + 20, &jf[1]);
              mem.ReadU32BE(eBase + 24, &jf[2]);
              MCLA_LOG_WARN("JOIN[{}] key={:08X} obj={:08X} vt={:08X} "
                            "rd={:08X} objf=[{:08X} {:08X} {:08X} {:08X} "
                            "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                            "{:08X} {:08X}] joinf=[{:08X} {:08X} {:08X}]",
                            ji, key, obj, vt, rd, f[0], f[1], f[2], f[3],
                            f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11],
                            jf[0], jf[1], jf[2]);
              continue;
            }
            MCLA_LOG_WARN("JOIN[{}] @ {:08X} key={:08X} obj={:08X} "
                          "busy={:08X} vt={:08X} readFn={:08X}",
                          ji, eBase, key, obj, busy, vt, rd);
          }
        }
      }
      return;
    }
    retries = 0;
    const uint32_t e = s_h5E10empty.fetch_add(1) + 1;
    if (e <= 16) {
      uint32_t outPtr2 = 0, produced2 = 0, h0 = 0, h1 = 0, h2 = 0, h3 = 0;
      (void)mem.ReadU32BE(st + 20, &outPtr2);
      (void)mem.ReadU32BE(st + 24, &produced2);
      if (outPtr2 != 0) {
        (void)mem.ReadU32BE(outPtr2 + 0, &h0);
        (void)mem.ReadU32BE(outPtr2 + 4, &h1);
        (void)mem.ReadU32BE(outPtr2 + 8, &h2);
        (void)mem.ReadU32BE(outPtr2 + 12, &h3);
      }
      MCLA_LOG_WARN("INFLATE-EMPTY #{} st={:08X} consumed={} produced={} "
                    "outPtr={:08X} head=[{:08X} {:08X} {:08X} {:08X}] "
                    "(bail, clear outLeft â€” caller loop key)",
                    e, st, consumed, produced2, outPtr2, h0, h1, h2, h3);
    } else if ((e % 1000) == 0) {
      MCLA_LOG_WARN("INFLATE-EMPTY #{} st={:08X} consumed={} (bail)", e, st,
                    consumed);
    }
    // Normalize state: no input left, consumed covers all, expected=0,
    // outLeft=0 (caller loop exit key).
    (void)mem.WriteU32BE(st + 0, 0);
    (void)mem.WriteU32BE(st + 8, 0);
    (void)mem.WriteU32BE(st + 12, 0);
    (void)mem.WriteU32BE(st + 16, 0);
    return;
  }

  if (n <= 16 || (n % 200) == 0) {
    // Session 75n: guest stack walk. Recompiler frame convention:
    // mflr r12; stw r12,-8(r1); stwu r1,-X(r1)  â‡’  saved LR of the function
    // owning this frame sits at [back_chain - 8]. Walk back chains upward.
    char chain[160] = {0};
    size_t off = 0;
    uint32_t sp = ctx.r1.u32;
    for (int f = 0; f < 6 && sp != 0 && off + 12 < sizeof(chain); ++f) {
      uint32_t back = 0, lr = 0;
      if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
      if (!mem.ReadU32BE(back - 8, &lr)) break;
      off += static_cast<size_t>(
          snprintf(chain + off, sizeof(chain) - off, " f%d=%08X", f, lr));
      sp = back;
    }
    MCLA_LOG_INFO("INFLATE #{} st={:08X} in={} out={} consumed={} magic={:08X} "
                  "lr={:08X} r1={:08X} tid={:08X} chain[{}]",
                  n, st, inLeft, outLeft, consumed, magic,
                  static_cast<uint32_t>(ctx.lr), ctx.r1.u32,
                  GetCurrentThreadId(), chain);
  }
  // Track the largest inflate-output capacity we have seen for this process.
  // PRELOAD-CTX inflSize is a 12-byte sentinel; the real package size is the
  // out buffer size from the stream (up to 512 KiB in boot soaks).
  if (outLeft > 16 && outLeft < (1u << 20)) {
    uint32_t prev = s_maxInflateOut.load();
    while (outLeft > prev && !s_maxInflateOut.compare_exchange_weak(prev, outLeft))
      {}
  }

  // p2q (IDA): 821D5E10 = zlibInflater::InflateBegin ("not in XCompress
  // format"). Job #2 enters with inLeft=0xFFFFFFD4 (-44) and inPtr on the
  // guest stack — the pgStreamer Read never filled the buffer. Unsigned
  // `inLeft >= 4` then treats stack residue (e.g. 525DE064) as a magic.
  // Corrupt sizes are NOT a format; complete the stream empty so we do
  // not AV on the original magic-check / decode.
  if (inLeft >= 0x10000000u) {
    static std::atomic<uint32_t> s_inCorrupt{0};
    const uint32_t cn = s_inCorrupt.fetch_add(1) + 1;
    if (cn <= 32 || (cn % 200) == 0)
      MCLA_LOG_WARN("INFLATE-CORRUPT #{} in={:#x} (signed {}) inPtr={:08X} "
                    "out={} outPtr={:08X} consumed={} lr={:08X}",
                    cn, inLeft, static_cast<int32_t>(inLeft), inPtr, outLeft,
                    outPtr, consumed,
                    static_cast<uint32_t>(ctx.lr));
    (void)mem.WriteU32BE(st + 0, 0);
    (void)mem.WriteU32BE(st + 8, inLeft);
    (void)mem.WriteU32BE(st + 12, 0);
    if (outLeft)
      (void)mem.WriteU32BE(st + 16, 0);
    return;
  }

  if (consumed == 0 && inLeft >= 4 && magic != kXCompressMagic &&
      inPtr != 0 && outPtr != 0) {
    // Session 72: do NOT copy unknown-magic bytes into the output. A
    // 525DE064 stream was pass-through'd raw and the guest parser produced
    // wild pointer 0x7E780000 â†’ AV in sub_821DEE40. Skip the XCompress
    // fatal, consume the stream, emit nothing. Guest sees empty output.
    uint32_t b0 = 0, b1 = 0, b2 = 0, b3 = 0;
    (void)mem.ReadU32BE(inPtr + 0, &b0);
    if (inLeft >= 16) {
      (void)mem.ReadU32BE(inPtr + 4, &b1);
      (void)mem.ReadU32BE(inPtr + 8, &b2);
      (void)mem.ReadU32BE(inPtr + 12, &b3);
    }
    (void)mem.WriteU32BE(st + 0, 0);       // inLeft = 0
    (void)mem.WriteU32BE(st + 8, inLeft);  // consumed = all input
    (void)mem.WriteU32BE(st + 12, 0);      // expected = 0
    const uint32_t pt = s_h5E10pt.fetch_add(1) + 1;
    if (pt <= 16 || (pt % 50) == 0)
      MCLA_LOG_WARN("INFLATE-SKIP #{} magic={:08X} in={} out={} inPtr={:08X} "
                    "head=[{:08X} {:08X} {:08X} {:08X}] (no XCompress "
                    "header â€” skip fatal, emit 0)",
                    pt, magic, inLeft, outLeft, inPtr, b0, b1, b2, b3);
    return;
  }
  __imp__sub_821D5E10(ctx, base);
}

// POST-INFLATE CACHE FLUSH census: sub_821D5510 (dcbf/dcbst loop).
// Called after each inflate step completes. Logs r3 (base addr), r4 (size),
// r5 (flags), lr.
PPC_FUNC_IMPL(__imp__sub_821D5510);
static std::atomic<uint32_t> s_h5510{0};
PPC_FUNC(sub_821D5510) {
  const uint32_t n = s_h5510.fetch_add(1) + 1;
  if (n <= 64 || (n % 200) == 0) {
    MCLA_LOG_INFO("FLUSH sub_821D5510 #{} r3={:08X} r4={:08X} r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821D5510(ctx, base);
}

// POST-INFLATE CLEANUP census: sub_821CE100 (atomic decrement).
// Called twice at loc_821BC4CC for cleanup. Logs r3 (object), lr.
PPC_FUNC_IMPL(__imp__sub_821CE100);
static std::atomic<uint32_t> s_hCE100{0};
PPC_FUNC(sub_821CE100) {
  const uint32_t n = s_hCE100.fetch_add(1) + 1;
  if (n <= 64 || (n % 200) == 0) {
    MCLA_LOG_INFO("CLEANUP sub_821CE100 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821CE100(ctx, base);
}

// CALLBACK SETUP census: sub_8268B960 (find-or-create by name).
// Returns the callback pointer stored at [ctx+1548] and the archive device
// stored at [ctx+1552]. Logs which string lookup produced which function.
PPC_FUNC_IMPL(__imp__sub_8268B960);
static std::atomic<uint32_t> s_h68B960{0};
PPC_FUNC(sub_8268B960) {
  const uint32_t n = s_h68B960.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    char name[68] = {0};
    mem.ReadBytes(ctx.r5.u32, name, 64);
    MclaSanitizePath(name, sizeof(name));
    uint32_t ret = 0;
    __imp__sub_8268B960(ctx, base);
    ret = ctx.r3.u32;
    MCLA_LOG_WARN("CBSETUP sub_8268B960 #{} pool={:08X} idx={:08X} name='{}' "
                  "flags={:08X} -> ret={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, name, ctx.r6.u32, ret,
                  static_cast<uint32_t>(ctx.lr));
  } else {
    __imp__sub_8268B960(ctx, base);
  }
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
// Forward declaration for fiDevice::Mount (sub_821CB9D8) used in post-inflate mount fix.
extern "C" void __imp__sub_821CB9D8(PPCContext &ctx, uint8_t *base);
// Defined at EOF: push {name,buf,size} onto the embedded:/ D22E8 list.
static bool EmbeddedListInsert(const char *name, uint32_t buf, uint32_t size);

PPC_FUNC(sub_821BC140) {
  const uint32_t n = s_hBC140.fetch_add(1) + 1;
  if (n <= 16 || (n % 2000) == 0)
    MCLA_LOG_INFO("INLINE-EXEC sub_821BC140 #{} a0={:08X} a1={:08X} "
                  "lr={:08X} r1={:08X} tid={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32,
                  static_cast<uint32_t>(ctx.lr), ctx.r1.u32,
                  GetCurrentThreadId());
  // NODE-CHAIN DUMP (session 19): the dispatched fnptr was ZERO. Walk the
  // list head a0 -> [a0+4]=node {node[0] ?, node[4]=fnptr, node[12]=next}
  // up to 3 nodes with checked reads (body starts with plain guest loads,
  // no early vtable dispatch - safe to pre-read).
  if (n <= 8) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    // Session 75n: these descriptors are the streamer request slots (queue
    // + 0x614 per slot). Dump the header dwords + attempt an ASCII name so
    // we know WHAT the 3 boot requests load and which callback they carry.
    uint32_t d[16] = {0};
    for (int i = 0; i < 16; ++i)
      (void)mem.ReadU32BE(ctx.r3.u32 + static_cast<uint32_t>(i * 4), &d[i]);
    char name[48] = {0};
    for (int nofs = 8; nofs <= 64 && name[0] == 0; nofs += 4) {
      const char *p = static_cast<const char *>(
          mcla::kernel::MmGetHostAddress(ctx.r3.u32 + static_cast<uint32_t>(nofs)));
      if (!p) break;
      size_t j = 0;
      for (; j < 40; ++j) {
        const unsigned char c = static_cast<unsigned char>(p[j]);
        if (c == 0) break;
        name[j] = (c >= 32 && c < 127) ? static_cast<char>(c) : '?';
      }
      name[j] = 0;
      if (j < 4) name[0] = 0; // too short to be a path â€” keep scanning
    }
    MCLA_LOG_INFO("REQDUMP #{} a0={:08X} name='{}' d=[{:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                  "{:08X} {:08X} {:08X} {:08X} {:08X}]",
                  n, ctx.r3.u32, name, d[0], d[1], d[2], d[3], d[4], d[5],
                  d[6], d[7], d[8], d[9], d[10], d[11], d[12], d[13], d[14],
                  d[15]);
  }
  // POST-INFLATE CALLBACK TRACE: read context fields before execution.
  // r26 (ctx.r3) is the preload context. Key offsets:
  // +1540: stream count
  // +1544: inflated size
  // +1548: callback function pointer
  // +1552: archive device
  // +8: buffer/data pointer
  if (n <= 16 || (n % 500) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t ctxBase = ctx.r3.u32;
    uint32_t cbPtr = 0, arcDev = 0, bufPtr = 0, streamCnt = 0, inflSize = 0;
    mem.ReadU32BE(ctxBase + 1540, &streamCnt);
    mem.ReadU32BE(ctxBase + 1544, &inflSize);
    mem.ReadU32BE(ctxBase + 1548, &cbPtr);
    mem.ReadU32BE(ctxBase + 1552, &arcDev);
    mem.ReadU32BE(ctxBase + 8, &bufPtr);
    MCLA_LOG_WARN("PRELOAD-CTX #{} base={:08X} streamCnt={} inflSize={} "
                  "cbPtr={:08X} arcDev={:08X} bufPtr={:08X}",
                  n, ctxBase, streamCnt, inflSize, cbPtr, arcDev, bufPtr);
    // p2q: dump stream descriptors (12-byte stride at ctx+12). Job #2
    // (tag 0x8004, streamCnt=17) left inflate with inLeft=-44 reading a
    // stack buffer — identify which streams have no device/handle yet.
    if (streamCnt > 0 && streamCnt <= 64) {
      for (uint32_t si = 0; si < streamCnt && si < 24; ++si) {
        const uint32_t sAddr = ctxBase + 12 + si * 12;
        uint32_t w0 = 0, w1 = 0, w2 = 0;
        (void)mem.ReadU32BE(sAddr + 0, &w0);
        (void)mem.ReadU32BE(sAddr + 4, &w1);
        (void)mem.ReadU32BE(sAddr + 8, &w2);
        uint32_t vt = 0, h = 0, sz = 0, pos = 0;
        // w0/w1 may be {stream*, size} or {handle, size}; probe both.
        if (w0 && w0 != 0xCDCDCDCDu) {
          (void)mem.ReadU32BE(w0 + 0, &vt);
          (void)mem.ReadU32BE(w0 + 4, &h);
          (void)mem.ReadU32BE(w0 + 28, &sz);
          (void)mem.ReadU32BE(w0 + 24, &pos);
        }
        MCLA_LOG_WARN("PSTREAM #{} s[{}] @{:08X} w0={:08X} w1={:08X} "
                      "w2={:08X} vt={:08X} h={:08X} sz={} pos={}",
                      n, si, sAddr, w0, w1, w2, vt, h, sz, pos);
      }
    }
  }
  __imp__sub_821BC140(ctx, base);
  // POST-EXEC: mount the inflated buffer as a memory: device so shader
  // lookups (star_glow etc.) can find it. The callback at [ctx+1548] is
  // 0x821BC548 (semaphore release) â€” wrong function. We do the mount here.
  MCLA_LOG_WARN("POST-EXEC-START #{} reached", n);
  if (n <= 16 || (n % 500) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t ctxBase = ctx.r3.u32;
    uint32_t streamCnt = 0, inflSize = 0, bufPtr = 0, arcDev = 0;
    mem.ReadU32BE(ctxBase + 1540, &streamCnt);
    mem.ReadU32BE(ctxBase + 1544, &inflSize);
    mem.ReadU32BE(ctxBase + 8, &bufPtr);
    mem.ReadU32BE(ctxBase + 1552, &arcDev);
    if (streamCnt > 0 && bufPtr != 0 && arcDev != 0) {
      // Register the inflated buffer under embedded:/ relative names.
      // inflSize in the preload ctx is a 12-byte sentinel; use the largest
      // INFLATE out capacity seen this process as the package size.
      // NOTE: do NOT Mount a fake device at 0xA001xxxx â€” that is o1heap and
      // previously caused sysMemMultiAllocator::Free ownership fatals.
      uint32_t regSize = inflSize;
      if (regSize < 16)
        regSize = s_maxInflateOut.load();
      if (regSize >= 16) {
        static const char *kNames[] = {
            "fxl_final/rage_im.fxc",
            "fxl_final/star_glow.fxc",
            "dcl/star_glow.dcl",
            "star_glow.dcl",
            "shaders/star_glow.fxc",
            "fxl_final/star_glow",
        };
        for (const char *nm : kNames)
          (void)EmbeddedListInsert(nm, bufPtr, regSize);
        MCLA_LOG_WARN("D2308-INS-DONE #{} buf={:08X} size={} (infl={} maxOut={})",
                      n, bufPtr, regSize, inflSize, s_maxInflateOut.load());
      } else {
        MCLA_LOG_WARN("D2308-INS-SKIP #{} buf={:08X} inflSize={} maxOut={}",
                      n, bufPtr, inflSize, s_maxInflateOut.load());
      }
    } else {
      MCLA_LOG_WARN("POST-EXEC-SKIP #{} streamCnt={} buf={:08X} arc={:08X} infl={}",
                    n, streamCnt, bufPtr, arcDev, inflSize);
    }
  }
  // POST-EXEC: re-read to see if callback fired (state changes)
  if (n <= 16 || (n % 500) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t ctxBase = ctx.r3.u32;
    uint32_t streamCnt2 = 0;
    mem.ReadU32BE(ctxBase + 1540, &streamCnt2);
    MCLA_LOG_INFO("POST-EXEC sub_821BC140 #{} streamCnt={}", n, streamCnt2);
  }
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
    MCLA_LOG_INFO("RINGB-CONSUMER sub_821BC910 ENTER #{} arg={:08X} "
                  "r1={:08X} tid={:08X}",
                  n, ctx.r3.u32, ctx.r1.u32, GetCurrentThreadId());
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
    // Session 75o: walk the guest stack to name the boot requester above
    // the push wrapper. Recompiler convention saves LR at [back-8]; plain
    // ABI frames save it at [back+4] â€” try both, log both.
    char chain[160] = {0};
    size_t off = 0;
    uint32_t sp = ctx.r1.u32;
    for (int f = 0; f < 5 && sp != 0 && off + 16 < sizeof(chain); ++f) {
      uint32_t back = 0, lrA = 0, lrB = 0;
      if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
      (void)mem.ReadU32BE(back - 8, &lrA);
      (void)mem.ReadU32BE(back + 4, &lrB);
      off += static_cast<size_t>(snprintf(chain + off, sizeof(chain) - off,
                                          " f%d=%08X/%08X", f, lrA, lrB));
      sp = back;
    }
    MCLA_LOG_INFO(
        "PUSH sub_821BC868 #{} q={:08X} wIdx={}{} pIdx={}{} cnt={}{} "
        "relH={:08X}{} lr={:08X} chain[{}]",
        n, q, wIdx, okW ? "" : "?", pIdx, okP ? "" : "?", cnt, okC ? "" : "?",
        relH, okR ? "" : "?", ctx.lr, chain);
  }
}

// Session 75o: completion dispatcher census. The transfer executor
// (sub_821BC140) tail calls sub_821C31B8(slot+1544, slot+8, slot+1552,
// slot+1548) when slot+1540 != 0 â€” the per-transfer completion, which then
// issues a virtual call (vtable+88). If this never runs after the 3 boot
// transfers, the init sequence never advances.
PPC_FUNC_IMPL(__imp__sub_821C31B8);
static std::atomic<uint32_t> s_hC31B8{0};
PPC_FUNC(sub_821C31B8) {
  const uint32_t n = s_hC31B8.fetch_add(1) + 1;
  if (n <= 16 || (n % 500) == 0)
    MCLA_LOG_INFO("COMPLETE sub_821C31B8 #{} a0={:08X} a1={:08X} a2={:08X} "
                  "a3={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821C31B8(ctx, base);
}

// RELEASE-HANDLE census (session 72): sub_821C9108(h) â†’ sub_8244ED10(h,1,0).
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
// Override returns r3=0 (success) to unblock boot â†’ start menu.
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

// Session 75o: THE request entry census. sub_821E5F48 is called by 31
// subsystems (incl. streamables loader 82216B98, UI-adjacent 82201B30) to
// push a load request + create a task join. Log every request with its
// caller so a soak shows who requested the boot batch and whether anyone
// ever requests again.
PPC_FUNC_IMPL(__imp__sub_821E5F48);
static std::atomic<uint32_t> s_h5F48{0};
PPC_FUNC(sub_821E5F48) {
  const uint32_t n = s_h5F48.fetch_add(1) + 1;
  if (n <= 48 || (n % 200) == 0)
    MCLA_LOG_INFO("REQ sub_821E5F48 #{} a0={:08X} a1={:08X} a2={:08X} "
                  "a3={:08X} a4={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  ctx.r7.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_821E5F48(ctx, base);
}

// Session 75o: async-request wrapper census + dispatcher hunt. Boot loads
// arrive here via message 0x40003803 (table entry 0x821071B0). Walk the
// stack (both LR-slot conventions) to identify the message dispatcher.
PPC_FUNC_IMPL(__imp__sub_821E5FD0);
static std::atomic<uint32_t> s_h5FD0{0};
PPC_FUNC(sub_821E5FD0) {
  const uint32_t n = s_h5FD0.fetch_add(1) + 1;
  if (n <= 12 || (n % 200) == 0) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    char chain[160] = {0};
    size_t off = 0;
    uint32_t sp = ctx.r1.u32;
    for (int f = 0; f < 6 && sp != 0 && off + 16 < sizeof(chain); ++f) {
      uint32_t back = 0, lrA = 0, lrB = 0;
      if (!mem.ReadU32BE(sp, &back) || back == 0 || back <= sp) break;
      (void)mem.ReadU32BE(back - 8, &lrA);
      (void)mem.ReadU32BE(back + 4, &lrB);
      off += static_cast<size_t>(snprintf(chain + off, sizeof(chain) - off,
                                          " f%d=%08X/%08X", f, lrA, lrB));
      sp = back;
    }
    MCLA_LOG_INFO("ASYNC-REQ sub_821E5FD0 #{} a0={:08X} a1={:08X} "
                  "a2={:08X} a3={:08X} lr={:08X} chain[{}]",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr), chain);
  }
  __imp__sub_821E5FD0(ctx, base);
}

// Session 75p: IO-credit census. The streamer refill waits while
// [0x82757500] <= 0 (Sleep 100ms) before issuing its virtual read â€” an
// async-IO credit/deepth limit. These two TU45 functions are the credit
// consumers/producers; log them to see whether credits ever flow.
PPC_FUNC_IMPL(__imp__sub_822CBE30);
static std::atomic<uint32_t> s_hCBE30{0};
PPC_FUNC(sub_822CBE30) {
  const uint32_t n = s_hCBE30.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0)
    MCLA_LOG_INFO("IOCRED-A sub_822CBE30 #{} a0={:08X} a1={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822CBE30(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822CC5E0);
static std::atomic<uint32_t> s_hCC5E0{0};
PPC_FUNC(sub_822CC5E0) {
  const uint32_t n = s_hCC5E0.fetch_add(1) + 1;
  if (n <= 16 || (n % 200) == 0)
    MCLA_LOG_INFO("IOCRED-B sub_822CC5E0 #{} a0={:08X} a1={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822CC5E0(ctx, base);
}

// Session 75r: page/descriptor lookup census. The executor calls
// vtable+8 = sub_821CC570(obj, join+24, &out) per request; returns -1 when
// the vtable+144 find fails (suspected batch-2 stall point).
PPC_FUNC_IMPL(__imp__sub_821CC570);
static std::atomic<uint32_t> s_hCC570{0};
PPC_FUNC(sub_821CC570) {
  const uint32_t n = s_hCC570.fetch_add(1) + 1;
  __imp__sub_821CC570(ctx, base);
  if (n <= 32 || (n % 200) == 0)
    MCLA_LOG_WARN("PGLOOKUP sub_821CC570 #{} obj={:08X} key={:08X} "
                  "out={:08X} -> ret={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r3.u32,
                  static_cast<uint32_t>(ctx.lr));
}

// Session 75t: read-wrapper census. The executor's refill loop calls
// vtable+28 = sub_821CC6F0 per refill; if the page-cache copy smashes the
// executor stack, r1 flips bad across this call.
PPC_FUNC_IMPL(__imp__sub_821CC6F0);
static std::atomic<uint32_t> s_hCC6F0{0};
PPC_FUNC(sub_821CC6F0) {
  const uint32_t n = s_hCC6F0.fetch_add(1) + 1;
  const uint32_t r1in = ctx.r1.u32;
  __imp__sub_821CC6F0(ctx, base);
  const bool saneIn = r1in < 0x82130000u;
  const bool saneOut = ctx.r1.u32 < 0x82130000u;
  if ((!saneIn || !saneOut) || n <= 8 || (n % 500) == 0)
    MCLA_LOG_WARN("READWRAP sub_821CC6F0 #{} r1in={:08X}{} r1out={:08X}{} "
                  "lr={:08X} tid={:08X}",
                  n, r1in, saneIn ? "" : "!", ctx.r1.u32,
                  saneOut ? "" : "!", static_cast<uint32_t>(ctx.lr),
                  GetCurrentThreadId());
}

// Session 75v: kernel read-submit census. sub_8244F4C0 is the kernel-layer
// read that produced the batch-1 NFS reads. If batch-2 never hits it, the
// fetch is never even attempted upstream.
PPC_FUNC_IMPL(__imp__sub_8244F4C0);
static std::atomic<uint32_t> s_hF4C0{0};
// Session 76a: completed-read tracking. Our NtReadFile finishes reads
// synchronously; record the destination buffers so SLOT-READY only marks
// slots whose buffer really received a completed read (a flip without a
// read serves garbage â€” the 0x7E780000 guest AV).
constexpr size_t kDoneBufCap = 64;
static std::atomic<uint32_t> g_doneBufs[kDoneBufCap];
static std::atomic<uint32_t> g_doneBufIdx{0};
static bool BufferReadDone(uint32_t buf) {
  for (size_t i = 0; i < kDoneBufCap; ++i)
    if (g_doneBufs[i].load(std::memory_order_acquire) == buf) return true;
  return false;
}
PPC_FUNC(sub_8244F4C0) {
  const uint32_t n = s_hF4C0.fetch_add(1) + 1;
  if (n <= 24 || (n % 200) == 0)
    MCLA_LOG_INFO("RD-SUBMIT sub_8244F4C0 #{} a0={:08X} a1={:08X} "
                  "a2={:08X} a3={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_8244F4C0(ctx, base);
  if (ctx.r4.u32 != 0 && ctx.r4.u32 != 0xCDCDCDCDu) {
    const uint32_t idx = g_doneBufIdx.fetch_add(1) % kDoneBufCap;
    g_doneBufs[idx].store(ctx.r4.u32, std::memory_order_release);
  }
}

// Session 75w: slot-ready fix. sub_821CBE18(slot) waits on the slot's
// event while [slot+12]==1 (read in flight). Our NtReadFile completes all
// reads synchronously with no event signal, so pending slots would block
// forever on data that is already in their buffers. Flip state 1â†’2 before
// the wait: the IO has in fact completed.
PPC_FUNC_IMPL(__imp__sub_821CBE18);
static std::atomic<uint32_t> s_hCBE18{0};
PPC_FUNC(sub_821CBE18) {
  const uint32_t n = s_hCBE18.fetch_add(1) + 1;
  const uint32_t slot = ctx.r3.u32;
  uint32_t state = 0;
  auto &memS = mcla::kernel::GuestMemoryHeap::Instance();
  if (slot != 0 && slot != 0xCDCDCDCDu) {
    (void)memS.ReadU32BE(slot + 12, &state);
    uint32_t buf = 0;
    memS.ReadU32BE(slot + 8, &buf);
    if (state == 1 && BufferReadDone(buf)) {
      (void)memS.WriteU32BE(slot + 12, 2);
      if (n <= 32 || (n % 500) == 0)
        MCLA_LOG_INFO("SLOT-READY sub_821CBE18 #{} slot={:08X} buf={:08X} "
                      "state 1->2 (read completed synchronously)",
                      n, slot, buf);
    }
  }
  __imp__sub_821CBE18(ctx, base);
}

// Session 75x: disc-error check census. sub_821CC1E0 fatals with
// 'Fatal disc error' when [dev+12] bit30/31 (error/media flags) are set.
// Log the device object and flag word to find who sets them.
PPC_FUNC_IMPL(__imp__sub_821CC1E0);
static std::atomic<uint32_t> s_hCC1E0{0};
PPC_FUNC(sub_821CC1E0) {
  const uint32_t n = s_hCC1E0.fetch_add(1) + 1;
  const uint32_t strm = ctx.r4.u32;
  // Session 75z: ack BEFORE the original â€” the fatal fires inside it.
  // The check passes only when bit30 (error flag) is clear OR bit31
  // (handled) is set; our emu misses the step that sets bit31.
  {
    auto &memD = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t dev = 0, flags = 0;
    memD.ReadU32BE(strm + 0, &dev);
    if (dev != 0 && dev != 0xCDCDCDCDu) {
      memD.ReadU32BE(dev + 12, &flags);
      if ((flags & 0x40000000u) != 0 && (flags & 0x80000000u) == 0) {
        (void)memD.WriteU32BE(dev + 12, flags | 0x80000000u);
        if (n <= 16 || (n % 200) == 0)
          MCLA_LOG_WARN("DISCCHK #{} dev={:08X} flags {:08X} -> ack (bit31 "
                        "set before check)",
                        n, dev, flags);
      }
    }
  }
  __imp__sub_821CC1E0(ctx, base);
}

// Session 76e: boot-init path census. sub_82187820(descriptor) runs in the
// boot task and reaches fiDevice::GetDevice(path) â€” the crash showed the
// path pointer itself = garbage (0xFF00FF00). Log the descriptor + the
// path string at entry to find which field is unwritten.
PPC_FUNC_IMPL(__imp__sub_82187820);
static std::atomic<uint32_t> s_h87820{0};
PPC_FUNC(sub_82187820) {
  const uint32_t n = s_h87820.fetch_add(1) + 1;
  if (n <= 8 || (n % 100) == 0) {
    auto &memP = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t f[6] = {0};
    for (int i = 0; i < 6; ++i)
      memP.ReadU32BE(ctx.r4.u32 + i * 4u, &f[i]);
    char path[48] = {0};
    for (int cand = 0; cand < 24 && path[0] == 0; ++cand) {
      const uint32_t addr = f[cand % 6] + (cand / 6) * 4u;
      // Session 76x: descriptor fields can be NULL/garbage â€” read through the
      // checked accessor only (a raw MmGetHostAddress + deref AV'd at guest 0).
      if (addr < 0x1000)
        continue;
      unsigned char raw[41] = {0};
      if (!memP.ReadBytes(addr, raw, 40))
        continue;
      size_t j = 0;
      for (; j < 40; ++j) {
        if (raw[j] == 0) break;
        path[j] = (raw[j] >= 32 && raw[j] < 127) ? (char)raw[j] : '?';
      }
      path[j] = 0;
      if (j < 3) path[0] = 0;
    }
    MCLA_LOG_WARN("BOOTPATH sub_82187820 #{} r3={:08X} r4={:08X} "
                  "desc=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X}] path='{}'",
                  n, ctx.r3.u32, ctx.r4.u32, f[0], f[1], f[2], f[3], f[4],
                  f[5], path);
  }
  __imp__sub_82187820(ctx, base);
}

// Session 76g: census of the 13 preload-list global users â€” which runs?
// (the global 0x827D7770 is never populated before the boot init reads it)
PPC_FUNC_IMPL(__imp__sub_8268A828);
static std::atomic<uint32_t> s_h8268A828{0};
PPC_FUNC(sub_8268A828) {
  const uint32_t n = s_h8268A828.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_8268A828 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_8268A828(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_826DB370);
static std::atomic<uint32_t> s_h826DB370{0};
PPC_FUNC(sub_826DB370) {
  const uint32_t n = s_h826DB370.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_826DB370 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_826DB370(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_8226D638);
static std::atomic<uint32_t> s_h8226D638{0};
PPC_FUNC(sub_8226D638) {
  const uint32_t n = s_h8226D638.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_8226D638 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_8226D638(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822C79A0);
static std::atomic<uint32_t> s_h822C79A0{0};
PPC_FUNC(sub_822C79A0) {
  const uint32_t n = s_h822C79A0.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822C79A0 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822C79A0(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822DA210);
static std::atomic<uint32_t> s_h822DA210{0};
PPC_FUNC(sub_822DA210) {
  const uint32_t n = s_h822DA210.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822DA210 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822DA210(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822DC388);
static std::atomic<uint32_t> s_h822DC388{0};
PPC_FUNC(sub_822DC388) {
  const uint32_t n = s_h822DC388.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822DC388 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822DC388(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822E9398);
static std::atomic<uint32_t> s_h822E9398{0};
PPC_FUNC(sub_822E9398) {
  const uint32_t n = s_h822E9398.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822E9398 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822E9398(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822ED628);
static std::atomic<uint32_t> s_h822ED628{0};
PPC_FUNC(sub_822ED628) {
  const uint32_t n = s_h822ED628.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822ED628 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822ED628(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822F8718);
static std::atomic<uint32_t> s_h822F8718{0};
PPC_FUNC(sub_822F8718) {
  const uint32_t n = s_h822F8718.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822F8718 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822F8718(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_822F9268);
static std::atomic<uint32_t> s_h822F9268{0};
PPC_FUNC(sub_822F9268) {
  const uint32_t n = s_h822F9268.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_822F9268 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_822F9268(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_82300928);
static std::atomic<uint32_t> s_h82300928{0};
PPC_FUNC(sub_82300928) {
  const uint32_t n = s_h82300928.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_82300928 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82300928(ctx, base);
}
PPC_FUNC_IMPL(__imp__sub_82363990);
static std::atomic<uint32_t> s_h82363990{0};
PPC_FUNC(sub_82363990) {
  const uint32_t n = s_h82363990.fetch_add(1) + 1;
  if (n <= 2)
    MCLA_LOG_INFO("PLUSER sub_82363990 #{} r3={:08X} lr={:08X}",
                  n, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_82363990(ctx, base);
}

// Session 76j: registry-state census at fiDevice::GetDevice entry.
// Registry header 0x82860844: {Device** array@+0, u16 count@+4, u16 capacity@+6}.
// Entry (276 bytes): name[262], flag@262, nameLen@264,
//   device vector {Device** arr@268, u16 cnt@272, u16 cap@274}.
PPC_FUNC_IMPL(__imp__sub_821CB488);
static std::atomic<uint32_t> s_hCB488{0};
PPC_FUNC(sub_821CB488) {
  const uint32_t n = s_hCB488.fetch_add(1) + 1;
  // Null/empty path (8C760 loads [obj+72] which can be 0 after stream
  // teardown). Returning 0 makes 8C760 do lwz from address 0. Return the
  // memory device so the vtable+88 no-op can run.
  if (ctx.r3.u32 == 0 || ctx.r3.u32 == 0xCDCDCDCDu) {
    if (n <= 40 || (n % 200) == 0)
      MCLA_LOG_WARN("GETDEV-NULL #{} lr={:08X} -> memory-dev", n,
                    static_cast<uint32_t>(ctx.lr));
    EnsureMemoryDeviceVtable();
    ctx.r3.u32 = kMemDeviceObj;
    return;
  }
  if (n <= 200 || (n % 100) == 0) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char path[68] = {0};
    memR.ReadBytes(ctx.r3.u32, path, 64);
    MclaSanitizePath(path, sizeof(path));
    if (path[0] == 0) {
      MCLA_LOG_WARN("GETDEV-EMPTY #{} lr={:08X}", n,
                    static_cast<uint32_t>(ctx.lr));
      ctx.r3.u32 = 0;
      return;
    }
    uint32_t arr = 0;
    uint16_t cnt = 0, cap = 0;
    memR.ReadU32BE(0x82860844u, &arr);
    memR.ReadU16BE(0x82860848u, &cnt);
    memR.ReadU16BE(0x8286084Au, &cap);
    uint32_t lockFlag = 0;
    (void)memR.ReadU32BE(0x82855A0Cu, &lockFlag);
    MCLA_LOG_WARN("GETDEV #{} path='{}' arr={:08X} cnt={} cap={} lockFlag={:08X}",
                  n, path, arr, cnt, cap, lockFlag);
    if (n <= 3) {
      // Session 76j: heap-arena layout dump. Default allocs route to
      // m_Allocators[1] = sysMemDualBuddyAllocator (sub_821C08F8 uses
      // [reg+(r6+1)*4]); if a buddy arena intersects the simple allocator's
      // registered pool range, the two allocators hand out the same bytes.
      auto dumpHeap = [&](const char *tag, uint32_t base) {
        uint32_t f0 = 0, f4 = 0, c76 = 0, f152 = 0, f248 = 0;
        (void)memR.ReadU32BE(base + 0u, &f0);
        (void)memR.ReadU32BE(base + 4u, &f4);
        (void)memR.ReadU32BE(base + 76u, &c76);
        (void)memR.ReadU32BE(base + 152u, &f152);
        (void)memR.ReadU32BE(base + 248u, &f248);
        MCLA_LOG_WARN("HEAP76 {} @{:08X} vt={:08X} +4={:08X} +76={:08X} "
                      "+152={:08X} +248={:08X}",
                      tag, base, f0, f4, c76, f152, f248);
      };
      dumpHeap("simple", 0x82830CD8u);
      dumpHeap("buddyA", 0x82830C10u);
      dumpHeap("buddyB", 0x82830B50u);
      dumpHeap("dual  ", 0x82830B40u);
    }
    for (uint32_t e = 0; arr != 0 && e < 2 && e <= cnt; ++e) {
      const uint32_t eb = arr + e * 276u;
      uint16_t flag = 0, len = 0, dcnt = 0, dcap = 0;
      uint32_t hold = 0, d0 = 0, d1 = 0, vt0 = 0, vt1 = 0;
      char name[17] = {0};
      memR.ReadBytes(eb, name, 16);
      MclaSanitizePath(name, sizeof(name));
      memR.ReadU16BE(eb + 262u, &flag);
      memR.ReadU16BE(eb + 264u, &len);
      memR.ReadU32BE(eb + 268u, &hold);
      memR.ReadU16BE(eb + 272u, &dcnt);
      memR.ReadU16BE(eb + 274u, &dcap);
      if (hold) {
        memR.ReadU32BE(hold, &d0);
        memR.ReadU32BE(hold + 4u, &d1);
        memR.ReadU32BE(d0, &vt0);
        memR.ReadU32BE(d1, &vt1);
      }
      uint32_t d0pfx = 0, d1pfx = 0;
      if (d0) (void)memR.ReadU32BE(d0 + 36u, &d0pfx);
      if (d1) (void)memR.ReadU32BE(d1 + 36u, &d1pfx);
      MCLA_LOG_WARN(
          "GETDEV-E{} [name='{}' flag={:x} len={} hold={:08X} dcnt={:04X} "
          "dcap={:04X} d0={:08X} vt0={:08X} pfx0={:08X} d1={:08X} vt1={:08X} "
          "pfx1={:08X}]",
          e, name, flag, len, hold, dcnt, dcap, d0, vt0, d0pfx, d1, vt1, d1pfx);
    }
  }
  const uint32_t pathG = ctx.r3.u32; // path arg, clobbered by the call
    EnsureMemoryDeviceVtable();
  __imp__sub_821CB488(ctx, base);
  if (n <= 80 || (n % 200) == 0) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char path[68] = {0};
    if (n <= 80 && pathG != 0 && pathG != 0xCDCDCDCDu) {
      (void)memR.ReadBytes(pathG, path, 64);
      MclaSanitizePath(path, sizeof(path));
    }
    const uint32_t ret = ctx.r3.u32;
    uint32_t vt = 0;
    if (ret != 0 && ret != 0xFFFFFFFFu)
      (void)memR.ReadU32BE(ret, &vt);
    MCLA_LOG_WARN("GETDEV-RET #{} path='{}' ret={:08X} vt={:08X}", n, path,
                  ret, vt);
  }
}

// Session 76j: fiDevice::Mount census â€” every device registration with its
// device pointer and vtable sanity (crash = garbage Device* in the holder).
PPC_FUNC_IMPL(__imp__sub_821CB9D8);
static std::atomic<uint32_t> s_hMnt{0};
PPC_FUNC(sub_821CB9D8) {
  const uint32_t n = s_hMnt.fetch_add(1) + 1;
  if (n <= 40) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char path[68] = {0};
    memR.ReadBytes(ctx.r3.u32, path, 64);
    MclaSanitizePath(path, sizeof(path));
    const uint32_t dev = ctx.r4.u32;
    uint32_t vt = 0;
    memR.ReadU32BE(dev, &vt);
    MCLA_LOG_WARN("MOUNT76 #{} path='{}' dev={:08X} vt={:08X} flag={:x} lr={:08X}",
                  n, path, dev, vt, ctx.r5.u32 & 0xFFu,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821CB9D8(ctx, base);
}

// Session 76j: the "embedded:" device method (sub_821CB070) â€” crash RIP was
// inside its inlined strrchr/strlen (AV at first uncommitted page below the
// scan). Log its args to separate garbage-device vs non-terminated string.
PPC_FUNC_IMPL(__imp__sub_821CB070);
static std::atomic<uint32_t> s_hCB070{0};
PPC_FUNC(sub_821CB070) {
  const uint32_t n = s_hCB070.fetch_add(1) + 1;
  if (n <= 12) {
    auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
    char p3[40] = {0}, p4[40] = {0};
    memR.ReadBytes(ctx.r3.u32, p3, 32);
    MclaSanitizePath(p3, sizeof(p3));
    memR.ReadBytes(ctx.r4.u32, p4, 32);
    MclaSanitizePath(p4, sizeof(p4));
    uint32_t vt = 0;
    (void)memR.ReadU32BE(ctx.r3.u32, &vt);
    MCLA_LOG_WARN("EMB76 #{} r3={:08X} [vt={:08X} s3='{}'] r4={:08X} s4='{}' lr={:08X}",
                  n, ctx.r3.u32, vt, p3, ctx.r4.u32, p4,
                  static_cast<uint32_t>(ctx.lr));
  }
  __imp__sub_821CB070(ctx, base);
}

// Session 76j: packfile TOC lookup (vtable+144, sub_821CBFC0). Returns 0
// immediately when [obj+8]==0 â€” a phantom not-found here sends GetDevice to
// the NEXT device in the holder (the audlo packfile) whose state may be
// uninitialized â†’ the 0x7E780000 AV.
// PHASE1 T3: hang census. p0d1 ends with TOC76 #22 (lr=821CC44C) entered and
// no RET â€” dump TOC bounds + elapsed so a spin/corrupt-search is visible.
PPC_FUNC_IMPL(__imp__sub_821CBFC0);
static std::atomic<uint32_t> s_hTOC{0};
PPC_FUNC(sub_821CBFC0) {
  const uint32_t n = s_hTOC.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  const uint32_t pathPtr = ctx.r4.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
  char path[68] = {0};
  memR.ReadBytes(pathPtr, path, 64);
  MclaSanitizePath(path, sizeof(path));
  const bool hot =
      (n <= 80) || (path[0] && std::strstr(path, "policecam") != nullptr);
  uint32_t inner = 0, tStart = 0, tCount = 0, e0 = 0, e4 = 0, e8 = 0, e12 = 0;
  if (hot) {
    (void)memR.ReadU32BE(obj + 8u, &inner);
    if (inner) {
      (void)memR.ReadU32BE(inner + 8u, &tStart);
      (void)memR.ReadU32BE(inner + 12u, &tCount);
      (void)memR.ReadU32BE(inner + 0u, &e0);
      (void)memR.ReadU32BE(inner + 4u, &e4);
      (void)memR.ReadU32BE(inner + 16u, &e8);
      (void)memR.ReadU32BE(inner + 20u, &e12);
    }
    MCLA_LOG_WARN(
        "TOC76 #{} obj={:08X} inner={:08X} start={:08X} cnt={:08X} "
        "e0={:08X} e4={:08X} e8={:08X} e12={:08X} path='{}' lr={:08X}",
        n, obj, inner, tStart, tCount, e0, e4, e8, e12, path, lr);
  }
  const auto t0 = std::chrono::steady_clock::now();
  __imp__sub_821CBFC0(ctx, base);
  if (hot) {
    const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::steady_clock::now() - t0)
                        .count();
    MCLA_LOG_WARN("TOC76-RET #{} ret={:08X} dt={}ms lr={:08X}", n, ctx.r3.u32,
                  ms, lr);
  }
}

// ===========================================================================
// PHASE1 T4a: Mount-gate census
//
// Non-archive Mount call chain (never observed firing):
//   caller@82144C88 (gated by [r30+4]==0)
//     â†’ sub_82135E48(r31+6468, [r31+1312], [r31+1316])
//       â†’ sub_8213AB78(...)  // must return true
//       â†’ sub_82139BE0(...)  // builds path, bl Mount
//         â†’ sub_821CB9D8 (fiDevice::Mount)
//
// Prove which fork holds: host-missing gate vs device-must-exist vs
// dead code / constructor-based registration.
// ===========================================================================

PPC_FUNC_IMPL(__imp__sub_8213AB78);
static std::atomic<uint32_t> s_hAB78{0};
PPC_FUNC(sub_8213AB78) {
  const uint32_t n = s_hAB78.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (n <= 40 || (n % 200) == 0) {
    MCLA_LOG_WARN("MNTGATE-AB78 #{} r3={:08X} r4={:08X} r5={:08X} "
                  "lr={:08X} tid={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr,
                  GetCurrentThreadId());
  }
  __imp__sub_8213AB78(ctx, base);
  if (n <= 40 || (n % 200) == 0)
    MCLA_LOG_WARN("MNTGATE-AB78-RET #{} ret={:08X} lr={:08X}", n,
                  ctx.r3.u32, lr);
}

PPC_FUNC_IMPL(__imp__sub_82135E48);
static std::atomic<uint32_t> s_h5E48{0};
PPC_FUNC(sub_82135E48) {
  const uint32_t n = s_h5E48.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  char name[80] = {0};
  // r3 is often a path/buffer on the caller's stack (r31+6468).
  if (ctx.r3.u32 != 0 && ctx.r3.u32 != 0xCDCDCDCDu)
    mem.ReadBytes(ctx.r3.u32, name, 64);
  MclaSanitizePath(name, sizeof(name));
  if (n <= 40 || (n % 200) == 0) {
    MCLA_LOG_WARN("MNTGATE-5E48 #{} r3={:08X} [{}] r4={:08X} r5={:08X} "
                  "lr={:08X} tid={:08X}",
                  n, ctx.r3.u32, name, ctx.r4.u32, ctx.r5.u32, lr,
                  GetCurrentThreadId());
  }
  __imp__sub_82135E48(ctx, base);
  if (n <= 40 || (n % 200) == 0)
    MCLA_LOG_WARN("MNTGATE-5E48-RET #{} ret={:08X} lr={:08X}", n,
                  ctx.r3.u32, lr);
}

PPC_FUNC_IMPL(__imp__sub_82139BE0);
static std::atomic<uint32_t> s_h9BE0{0};
PPC_FUNC(sub_82139BE0) {
  const uint32_t n = s_h9BE0.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  MCLA_LOG_WARN("MNTGATE-9BE0 #{} r3={:08X} r4={:08X} r5={:08X} "
                "r6={:08X} lr={:08X}",
                n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, lr);
  __imp__sub_82139BE0(ctx, base);
  MCLA_LOG_WARN("MNTGATE-9BE0-RET #{} ret={:08X} lr={:08X}", n, ctx.r3.u32,
                lr);
}

// The site that decides whether to enter 5E48 at all:
//   lwz r11,4(r30); cmplwi r11,0; bne skip;  else bl 5E48
// Log every hit of the caller-side gate check via a thin wrapper on 5E48's
// peer sub_82144F28 (loop entry of the outer init fn) is not enough â€”
// census 5E48 is the proof. Also census 82144C88 via lrs already covered.
//
// Extra: dump [r30+4] from the outer frame is host-only; we log r30 contents
// when 5E48 is entered (caller passed r3=r31+6468). If 5E48 never logs,
// the gate above it bounced.
PPC_FUNC_IMPL(__imp__sub_82144F28);
static std::atomic<uint32_t> s_h44F28{0};
PPC_FUNC(sub_82144F28) {
  const uint32_t n = s_h44F28.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  // Only census when called from the Mount-gate caller range.
  if (n <= 24 || (n % 200) == 0)
    MCLA_LOG_INFO("MNTGATE-44F28 #{} r3={:08X} lr={:08X}", n, ctx.r3.u32, lr);
  __imp__sub_82144F28(ctx, base);
}

// Outer init fn that owns the Mount-gate block (contains 82144C88).
PPC_FUNC_IMPL(__imp__sub_82144B90);
static std::atomic<uint32_t> s_h44B90{0};
PPC_FUNC(sub_82144B90) {
  const uint32_t n = s_h44B90.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // r30 is set inside to a global block; dump [r3+772] and a few flags.
  uint32_t f772 = 0, f1312 = 0, f1316 = 0;
  if (ctx.r3.u32 != 0 && ctx.r3.u32 != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(ctx.r3.u32 + 772u, &f772);
    (void)mem.ReadU32BE(ctx.r3.u32 + 1312u, &f1312);
    (void)mem.ReadU32BE(ctx.r3.u32 + 1316u, &f1316);
  }
  MCLA_LOG_WARN(
      "MNTGATE-44B90 #{} r3={:08X} +772={:08X} +1312={:08X} +1316={:08X} "
      "lr={:08X} tid={:08X}",
      n, ctx.r3.u32, f772, f1312, f1316, lr, GetCurrentThreadId());
  __imp__sub_82144B90(ctx, base);
  MCLA_LOG_WARN("MNTGATE-44B90-RET #{} ret={:08X} lr={:08X}", n,
                ctx.r3.u32, lr);
}

// Caller of 44B90 (init teardown/finish).
PPC_FUNC_IMPL(__imp__sub_82144D30);
static std::atomic<uint32_t> s_h44D30{0};
PPC_FUNC(sub_82144D30) {
  const uint32_t n = s_h44D30.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  MCLA_LOG_WARN("MNTGATE-44D30 #{} r3={:08X} r4={:08X} r5={:08X} "
                "lr={:08X} tid={:08X}",
                n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr,
                GetCurrentThreadId());
  __imp__sub_82144D30(ctx, base);
  MCLA_LOG_WARN("MNTGATE-44D30-RET #{} ret={:08X} lr={:08X}", n,
                ctx.r3.u32, lr);
}

// Wrapper that calls 44D30 with a global block (r11=-32125+19856).
PPC_FUNC_IMPL(__imp__sub_82144EB0);
static std::atomic<uint32_t> s_h44EB0{0};
PPC_FUNC(sub_82144EB0) {
  const uint32_t n = s_h44EB0.fetch_add(1) + 1;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  MCLA_LOG_WARN("MNTGATE-44EB0 #{} r3={:08X} r4={:08X} r5={:08X} "
                "lr={:08X} tid={:08X}",
                n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, lr,
                GetCurrentThreadId());
  __imp__sub_82144EB0(ctx, base);
  MCLA_LOG_WARN("MNTGATE-44EB0-RET #{} ret={:08X} lr={:08X}", n,
                ctx.r3.u32, lr);
}

// ===========================================================================
// PHASE1 T4a2: sub_821CB740 (sprintf memory:$%p,%d,%d:%s) owners + handler
// entry ctor sub_821CB760 (call site lr=821CBAA4). Case A = any owner fires
// during preload. Case C = none fire + memory: only in prefix parsers.
// ===========================================================================

#define MCLA_T4A2_CENSUS(sym, tag)                                             \
  PPC_FUNC_IMPL(__imp__##sym);                                                 \
  static std::atomic<uint32_t> s_##tag{0};                                     \
  PPC_FUNC(sym) {                                                              \
    const uint32_t n = s_##tag.fetch_add(1) + 1;                               \
    if (n <= 24 || (n % 500) == 0)                                             \
      MCLA_LOG_WARN("MEMFMT-{} #{} r3={:08X} r4={:08X} r5={:08X} lr={:08X}",   \
                    #sym, n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,               \
                    static_cast<uint32_t>(ctx.lr));                            \
    __imp__##sym(ctx, base);                                                   \
    if (n <= 24 || (n % 500) == 0)                                             \
      MCLA_LOG_WARN("MEMFMT-{}-RET #{} ret={:08X}", #sym, n, ctx.r3.u32);      \
  }

MCLA_T4A2_CENSUS(sub_821CB740, fmt740)
MCLA_T4A2_CENSUS(sub_821CB760, ctor760)

// 13 unique owners of blâ†’sub_821CB740 (raw scan of mcla_pe.bin)
MCLA_T4A2_CENSUS(sub_8215B1D8, own5B1D8)
// sub_821BE8D8 is handled below with a richer census (obj/dev/handle).
MCLA_T4A2_CENSUS(sub_822C3A58, own2C3A58)
MCLA_T4A2_CENSUS(sub_822C4BD8, own2C4BD8)
MCLA_T4A2_CENSUS(sub_82390E08, own390E08)
MCLA_T4A2_CENSUS(sub_82390EB0, own390EB0)
MCLA_T4A2_CENSUS(sub_824A2B28, own4A2B28)
MCLA_T4A2_CENSUS(sub_826058B0, own6058B0)
MCLA_T4A2_CENSUS(sub_8263C728, own63C728)
MCLA_T4A2_CENSUS(sub_8263C8B0, own63C8B0)
MCLA_T4A2_CENSUS(sub_8263C9C8, own63C9C8)
MCLA_T4A2_CENSUS(sub_8263DCF8, own63DCF8)
MCLA_T4A2_CENSUS(sub_8263E1E8, own63E1E8)

#undef MCLA_T4A2_CENSUS

// Plain "memory:" @0x820127D8 owners â€” all fiDevice prefix parsers
// (hash/EMB/GETDEV), NOT a constructor. Census to confirm they are the
// only scanners and whether any produces a device object.
PPC_FUNC_IMPL(__imp__sub_821C9AB0);
static std::atomic<uint32_t> s_memC9AB0{0};
PPC_FUNC(sub_821C9AB0) {
  const uint32_t n = s_memC9AB0.fetch_add(1) + 1;
  if (n <= 16 || (n % 400) == 0)
    MCLA_LOG_INFO("MEMPARSE-C9AB0 #{} r3={:08X} r4={:08X} lr={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_821C9AB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821CAE50);
static std::atomic<uint32_t> s_memAE50{0};
PPC_FUNC(sub_821CAE50) {
  const uint32_t n = s_memAE50.fetch_add(1) + 1;
  if (n <= 16 || (n % 400) == 0)
    MCLA_LOG_INFO("MEMPARSE-AE50 #{} r3={:08X} r4={:08X} r5={:08X} lr={:08X}",
                  n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32,
                  static_cast<uint32_t>(ctx.lr));
  __imp__sub_821CAE50(ctx, base);
}

// ===========================================================================
// T5-next: embedded:/ content via the D22E8/D2308 name list.
//
// INSERT file-resolve sub_821BDF20 does:
//   dev = GETDEV(path)                 // embedded: â†’ 0x827D838C
//   handle = dev->vtable[+4](path, x)  // AFB8 â€” only understands "memory:"
// AFB8 returns -1 for embedded:/, so INSERT fails even with a live device.
// Fix: host-hook AFB8 so embedded:/ walks the same list D2308 uses
// (head 0x82860AF8, node {+0 name*, +4 buf, +8 size, +12 next}) and returns
// the buffer pointer as the open handle (r3 != -1).
// ===========================================================================

constexpr uint32_t kEmbeddedNameListHead = 0x82860AF8; // lis -32122 + 2804
constexpr uint32_t kEmbeddedPfxLen = 10;               // "embedded:/"
constexpr uint32_t kMemVtable = 0x82012918;            // AE50/AFB8/...
// kMemDeviceObj is at file scope near the top.

// Something zeros [0x827D838C] and even .rdata vtable slot +4 at runtime
// (T9c/T10c: BE0C8 saw vt=0 then vt+4=0). Re-arm device ptr and the two
// load-bearing vtable slots before any virtual call.
static void EnsureMemoryDeviceVtable() {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t vt = 0;
  (void)mem.ReadU32BE(kMemDeviceObj, &vt);
  if (vt != kMemVtable)
    mem.WriteU32BE(kMemDeviceObj, kMemVtable);
  // Full known slots from mcla_pe.bin @0x82012918 â€” runtime wipes .rdata.
  static const uint32_t kSlots[] = {
      0x821CAE50u, // +0
      0x821CAFB8u, // +4
      0x8249B538u, // +8
      0x82762480u, // +12
      0x821CB070u, // +16
      0x821CB158u, // +20
      0x821CB030u, // +24
      0x82762480u, // +28
      0x821CB1F8u, // +32
      0x821CB330u, // +36
      0x821CB3C8u, // +40
      0x821CB2A0u, // +44
      0x821A5CC0u, // +48
      0x821CAB38u, // +52
      0x821CABB8u, // +56
      0x821A5CC0u, // +60
      0x821A5CC0u, // +64
      0x821A5CC0u, // +68
      0x821A5CC0u, // +72
      0x821A5CC0u, // +76
      0x821CB400u, // +80
      0x821A5CC0u, // +84
      0x821A5CC0u, // +88
  };
  for (size_t i = 0; i < sizeof(kSlots) / sizeof(kSlots[0]); ++i) {
    uint32_t cur = 0;
    (void)mem.ReadU32BE(kMemVtable + static_cast<uint32_t>(i * 4), &cur);
    if (cur != kSlots[i])
      mem.WriteU32BE(kMemVtable + static_cast<uint32_t>(i * 4), kSlots[i]);
  }
  // Guest allocs zero function-table slots at guest VA 0x829E0000+
  // (IMAGE_BASE+IMAGE_SIZE). Re-install the no-op stub A5CC0 (vtable+88).
  {
    uint8_t *gbase = mem.Base();
    // PPC_LOOKUP_FUNC: base + 0x82000000 + 0x9E0000 + (guest-0x82130000)*2
    constexpr uint32_t kA5CC0 = 0x821A5CC0u;
    void **slot = reinterpret_cast<void **>(
        gbase + 0x829E0000ull + (uint64_t(kA5CC0 - 0x82130000u) * 2));
    extern void sub_821A5CC0(PPCContext &, uint8_t *);
    void *want = reinterpret_cast<void *>(&sub_821A5CC0);
    if (*slot != want) {
      *slot = want;
      MCLA_LOG_WARN("FUNC-TAB remap 821A5CC0 -> {:p}", want);
    }
  }
}

// Host-side D2308: strcmp-walk the list; on hit fill buf/size and return true.
static bool EmbeddedListLookup(const char *relName, uint32_t *outBuf,
                               uint32_t *outSize) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t node = 0;
  if (!mem.ReadU32BE(kEmbeddedNameListHead, &node) || node == 0)
    return false;
  for (int guard = 0; node != 0 && guard < 256; ++guard) {
    uint32_t namePtr = 0, buf = 0, size = 0, next = 0;
    if (!mem.ReadU32BE(node + 0, &namePtr) ||
        !mem.ReadU32BE(node + 4, &buf) || !mem.ReadU32BE(node + 8, &size) ||
        !mem.ReadU32BE(node + 12, &next))
      return false;
    char name[128] = {0};
    if (namePtr != 0)
      (void)mem.ReadBytes(namePtr, name, sizeof(name) - 1);
    if (name[0] && std::strcmp(name, relName) == 0) {
      if (outBuf) *outBuf = buf;
      if (outSize) *outSize = size;
      return true;
    }
    node = next;
  }
  return false;
}

// Host-side D22E8: push {name, buf, size} onto the list head.
// Guest memory comes from GuestMemoryHeap::Alloc â€” never a hardcoded
// 0xA00xxxxx scratch (that hits o1heap and Free-ownership fatals).
static bool EmbeddedListInsert(const char *name, uint32_t buf, uint32_t size) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (!name || !name[0] || buf == 0 || size == 0)
    return false;
  // Reject duplicate relative name.
  uint32_t dummyB = 0, dummyS = 0;
  if (EmbeddedListLookup(name, &dummyB, &dummyS))
    return false;

  const size_t nlen = std::strlen(name) + 1;
  const uint32_t nameG = mem.Alloc(nlen, 1);
  const uint32_t node = mem.Alloc(16, 4);
  if (nameG == 0 || node == 0) {
    MCLA_LOG_WARN("D2308-INS-FAIL name='{}' nameG={:08X} node={:08X}", name,
                  nameG, node);
    return false;
  }
  mem.WriteBytes(nameG, name, static_cast<uint32_t>(nlen));
  uint32_t head = 0;
  (void)mem.ReadU32BE(kEmbeddedNameListHead, &head);
  mem.WriteU32BE(node + 0, nameG);
  mem.WriteU32BE(node + 4, buf);
  mem.WriteU32BE(node + 8, size);
  mem.WriteU32BE(node + 12, head);
  mem.WriteU32BE(kEmbeddedNameListHead, node);
  MCLA_LOG_WARN("D2308-INS name='{}' buf={:08X} size={} node={:08X}",
                name, buf, size, node);
  return true;
}

// Last MakeMemoryStream â€” used by BE710-SKIP to serve magic bytes.
static uint32_t s_lastMemStream = 0;

// Stable .data slot (next to CRT nodes ~0x829054C0). Heap Alloc at
// C8024B00 got zeroed by a later arena wipe.
static constexpr uint32_t kMemStreamSlot = 0x82905500u;

// Phase 2 T3: the guest device API (sub_821CAE50 open family, CB158 read,
// CB2A0 close/getbuf, BE8D8's vt+56 size fetch) treats an open HANDLE as an
// index into a 16-entry slot table at 0x82860740 (stride 16: +0 buf, +4
// size, +8 pos, +12 flag). Returning a raw pointer as the handle made
// CB2A0's `if (h < 0 || h >= 16) return -1` poison BE8D8's alloc size into
// 0xffffffff -> the CDCD fill marathon. Register {buf,size} in the REAL
// guest slot table and return the slot index, matching sub_821CAE50's
// loc_821CAF50 open path exactly.
static constexpr uint32_t kGuestSlotTable = 0x82860740u;
static constexpr uint32_t kGuestSlotCount = 16;
static std::atomic<uint32_t> s_slotTableFull{0};

static int GuestSlotTableInsert(uint32_t buf, uint32_t size) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Slot 0 is reserved: the guest uses `r3 != 0` as the open-success check
  // (8218C804 after BE8D8), so index 0 is indistinguishable from NULL.
  for (uint32_t i = 1; i < kGuestSlotCount; ++i) {
    const uint32_t slot = kGuestSlotTable + i * 16;
    uint32_t cur = 0;
    if (!mem.ReadU32BE(slot + 0, &cur))
      return -1;
    if (cur == 0) {
      mem.WriteU32BE(slot + 0, buf);
      mem.WriteU32BE(slot + 4, size);
      mem.WriteU32BE(slot + 8, 0);
      mem.WriteU32BE(slot + 12, 0);
      return static_cast<int>(i);
    }
  }
  const uint32_t n = s_slotTableFull.fetch_add(1) + 1;
  if (n <= 8)
    MCLA_LOG_WARN("SLOT-TABLE-FULL #{} (16/16 in use) — cannot host-register "
                  "buf={:08X} size={}",
                  n, buf, size);
  return -1;
}

static uint32_t MakeMemoryStream(uint32_t device, uint32_t handle,
                                  uint32_t size) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // Host-side shadow wrapper (BE250 Read() fields: +0 dev, +4 handle,
  // +8 buf, +16 counter, +24 readPos, +28 end, +32 cap). Kept so
  // MemoryStreamServeRead and the s_lastMemStream consumers still work.
  const uint32_t s = kMemStreamSlot;
  mem.WriteU32BE(s + 0, device);
  mem.WriteU32BE(s + 4, handle);
  mem.WriteU32BE(s + 8, size);
  mem.WriteU32BE(s + 12, 0);
  mem.WriteU32BE(s + 16, 0);
  mem.WriteU32BE(s + 20, 0);
  mem.WriteU32BE(s + 24, 0); // readPos  (BE250 field)
  mem.WriteU32BE(s + 28, 0); // writePos (BE250 field)
  s_lastMemStream = s;
  // Phase 2 T3 fix: the guest treats an open handle as a slot index. Insert
  // {handle=buf, size} into the real 16-entry slot table and return the
  // INDEX — the exact contract of sub_821CAE50's open path. The BE8D8
  // vt+56 size fetch then returns the real buffer, alloc(size) succeeds,
  // and Read() gets sane counts instead of 0xffffffff.
  const int slotIdx = GuestSlotTableInsert(handle, size);
  if (slotIdx >= 0) {
    static std::atomic<uint32_t> s_slotReg{0};
    const uint32_t n = s_slotReg.fetch_add(1) + 1;
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("SLOT-REG #{} idx={} buf={:08X} size={} (guest slot table "
                    "@82860740)",
                    n, slotIdx, handle, size);
    return static_cast<uint32_t>(slotIdx);
  }
  // Table full: legacy behavior (pointer handle) — logged above.
  return s;
}

// Host-side read for a dead/legacy wrapper: obj+4=buf, obj+8=size, cursor at
// obj+24 (mirrors sub_821BE250's buffer shape). Serves min(count, size-cursor)
// bytes and advances the cursor. Returns bytes served, or -1 when obj is not
// a wrapper we recognize.
static int64_t MemoryStreamServeRead(uint32_t obj, uint32_t dst, uint32_t count) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t buf = 0, size = 0, pos = 0;
  if (obj == 0 || obj == 0xCDCDCDCDu)
    return -1;
  // Wrapper form: [+4]=buf [+8]=size [+24]=cursor. The CRT seed slot is the
  // canonical wrapper (MakeMemoryStream layout).
  if (!mem.ReadU32BE(obj + 4, &buf) || !mem.ReadU32BE(obj + 8, &size))
    return -1;
  if (buf == 0 || buf == 0xCDCDCDCDu || size == 0 || size == 0xCDCDCDCDu)
    return -1;
  (void)mem.ReadU32BE(obj + 24, &pos);
  if (pos > size)
    pos = size;
  const uint32_t avail = size - pos;
  const uint32_t n = (count < avail) ? count : avail;
  if (n != 0 && dst != 0 && dst != 0xCDCDCDCDu) {
    uint8_t tmp[512];
    uint32_t done = 0;
    while (done < n) {
      const uint32_t chunk = (n - done > sizeof(tmp)) ? sizeof(tmp) : n - done;
      if (!mem.ReadBytes(buf + pos + done, tmp, chunk))
        return -1;
      if (!mem.WriteBytes(dst + done, tmp, chunk))
        return -1;
      done += chunk;
    }
  }
  if (n != 0)
    (void)mem.WriteU32BE(obj + 24, pos + n);
  return n;
}

// p2d rgxa fix: serve a read directly from a guest slot-table entry
// ({buf,size,pos,flag} @0x82860740 + h*16 — the exact contract of the
// original vt+20 slot read 821CB158). The original BE250 machinery can't
// serve these: BDF20's guest wrapper keeps +8/+24/+28/+32 buffered fields
// uninitialized for our slot handles, so its refill path yields garbage.
// wordSwap mirrors the original sub_821BE710 tail loop (821BE73C-768):
// it byteswaps each full 4-byte word of the destination after the raw
// copy (the .fxc format is little-endian on disk, PPC host is BE).
// Returns bytes served (advancing slot pos), or -1 when h is not a live
// slot or dst is poisoned (pos NOT advanced on failure).
static int64_t SlotTableServeRead(uint32_t h, uint32_t dst, uint32_t count,
                                   bool wordSwap = false) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (h == 0 || h >= kGuestSlotCount)
    return -1;
  const uint32_t slot = kGuestSlotTable + h * 16;
  uint32_t sbuf = 0, ssize = 0, spos = 0;
  if (!mem.ReadU32BE(slot + 0, &sbuf) || !mem.ReadU32BE(slot + 4, &ssize) ||
      !mem.ReadU32BE(slot + 8, &spos))
    return -1;
  if (sbuf == 0 || sbuf == 0xCDCDCDCDu || ssize == 0 || ssize == 0xCDCDCDCDu)
    return -1;
  if (spos > ssize)
    spos = ssize;
  const uint32_t avail = ssize - spos;
  const uint32_t nb = (count < avail) ? count : avail;
  if (nb != 0) {
    if (dst == 0 || dst == 0xCDCDCDCDu)
      return -1;
    uint8_t tmp[512];
    uint32_t done = 0;
    while (done < nb) {
      const uint32_t chunk = (nb - done > sizeof(tmp)) ? sizeof(tmp) : nb - done;
      if (!mem.ReadBytes(sbuf + spos + done, tmp, chunk))
        return -1;
      if (wordSwap) {
        for (uint32_t o = 0; o + 4 <= chunk; o += 4)
          std::swap(tmp[o], tmp[o + 3]), std::swap(tmp[o + 1], tmp[o + 2]);
      }
      if (!mem.WriteBytes(dst + done, tmp, chunk))
        return -1;
      done += chunk;
    }
    (void)mem.WriteU32BE(slot + 8, spos + nb);
  }
  return nb;
}

// AFB8 = INSERT's vtable+4 open. Path is r4.
// Host-handle BOTH embedded:/ and memory:$ so we never re-enter original
// AFB8/CAD80 (BE0C8 re-open AVed at 0x7e780000 there). Return value matches
// original semantics: the buffer pointer, or -1 on miss.
// memory:$ format from sub_821CB740: "memory:$%p,%d,%d:%s"
PPC_FUNC_IMPL(__imp__sub_821CAFB8);
static std::atomic<uint32_t> s_hAFB8{0};
static bool ParseMemoryDollar(const char *path, uint32_t *outBuf,
                              uint32_t *outSize) {
  // path like memory:$827D2DD0,5258,0:name
  if (!path || std::strncmp(path, "memory:$", 8) != 0)
    return false;
  const char *p = path + 8;
  char *end = nullptr;
  const unsigned long buf = std::strtoul(p, &end, 16);
  if (end == p || *end != ',')
    return false;
  p = end + 1;
  const unsigned long sz = std::strtoul(p, &end, 10);
  if (end == p)
    return false;
  if (outBuf) *outBuf = static_cast<uint32_t>(buf);
  if (outSize) *outSize = static_cast<uint32_t>(sz);
  return true;
}

PPC_FUNC(sub_821CAFB8) {
  const uint32_t n = s_hAFB8.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  char path[192] = {0};
  if (ctx.r4.u32 != 0 && ctx.r4.u32 != 0xCDCDCDCDu)
    (void)mem.ReadBytes(ctx.r4.u32, path, sizeof(path) - 1);
  MclaSanitizePath(path, sizeof(path));
  if (n <= 8 || path[0] == 'm' || path[0] == 'e')
    MCLA_LOG_WARN("AFB8-IN #{} r3={:08X} r4={:08X} path='{}' lr={:08X}", n,
                  ctx.r3.u32, ctx.r4.u32, path,
                  static_cast<uint32_t>(ctx.lr));
  EnsureMemoryDeviceVtable();
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  uint32_t buf = 0, size = 0;

  if (std::strncmp(path, "embedded:/", 10) == 0 && path[10]) {
    const bool hit = EmbeddedListLookup(path + 10, &buf, &size);
    if (hit) {
      const uint32_t st = MakeMemoryStream(kMemDeviceObj, buf, size);
      MCLA_LOG_WARN("AFB76-HIT #{} path='{}' buf={:08X} size={} stream={:08X} "
                    "lr={:08X}",
                    n, path, buf, size, st, lr);
      ctx.r3.u32 = st;
      return;
    }
    if (n <= 40 || (n % 200) == 0)
      MCLA_LOG_WARN("AFB76-MISS #{} path='{}' lr={:08X}", n, path, lr);
    ctx.r3.u32 = 0xFFFFFFFFu;
    return;
  }

  if (ParseMemoryDollar(path, &buf, &size) && buf != 0) {
    const uint32_t st = MakeMemoryStream(kMemDeviceObj, buf, size);
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("AFB76-MEM$ #{} path='{}' buf={:08X} size={} stream={:08X} "
                    "lr={:08X}",
                    n, path, buf, size, st, lr);
    ctx.r3.u32 = st;
    return;
  }

  __imp__sub_821CAFB8(ctx, base);
}

// INSERT file-resolve sub_821BDF20: GETDEV â†’ vtable+4 (AFB8) â†’ handle.
// Census so we see whether AFB76-HIT actually feeds a successful INSERT.
PPC_FUNC_IMPL(__imp__sub_821BDF20);
static std::atomic<uint32_t> s_hBDF20{0};
PPC_FUNC(sub_821BDF20) {
  const uint32_t n = s_hBDF20.fetch_add(1) + 1;
  const uint32_t pathG = ctx.r3.u32;
  const uint32_t flags = ctx.r4.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  char path[96] = {0};
  if (pathG != 0 && pathG != 0xCDCDCDCDu) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    (void)mem.ReadBytes(pathG, path, sizeof(path) - 1);
    MclaSanitizePath(path, sizeof(path));
  }
  __imp__sub_821BDF20(ctx, base);
  const int32_t ret = static_cast<int32_t>(ctx.r3.s32);
  if (n <= 40 || (n % 200) == 0 || std::strstr(path, "star_glow") ||
      std::strstr(path, "embedded:"))
    MCLA_LOG_WARN("BDF20 #{} path='{}' flags={:x} ret={:d} lr={:08X}", n,
                  path, flags, ret, lr);
}

// Richer BE8D8 census (replaces MCLA_T4A2_CENSUS): [obj+0]=device* [obj+4]=handle.
//
// Phase 2 T3 root-cause fix: sub_821BE8D8 = "load whole embedded file":
//   size = dev->vt[+56](dev, handle); alloc(size); Read(this, dst, size);
//   format "memory:$..." (CB740); GetSize (BE610); re-open (BE0C8).
// On the REAL device this runs against (archive vt=82012BDC), vt+56 =
// sub_821CD3C8: indexes dev+h*68 entry table, returns [file+4] = size.
// Our memory-device vt+56 (CABB8 -> 3x vt+44 close) returns -1 by
// construction -> alloc(0xffffffff) NULL -> Read(NULL, -1) -> the CDCD
// fill marathon (135M+ stores, PHYS-OVERRUN storm, t24c/p2b).
// Host-complete the whole flow when the wrapper's handle is one of ours:
// real size, guest-visible alloc, serve bytes, return a memory:$ stream
// (the exact contract of the tail's BE0C8-RET path).
PPC_FUNC_IMPL(__imp__sub_821BE8D8);
static std::atomic<uint32_t> s_hBE8D8{0};
PPC_FUNC(sub_821BE8D8) {
  const uint32_t n = s_hBE8D8.fetch_add(1) + 1;
  EnsureMemoryDeviceVtable();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0, h = 0, vt = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
    if (dev != 0 && dev != 0xCDCDCDCDu)
      (void)mem.ReadU32BE(dev, &vt);
  }
  if (n <= 24 || (n % 200) == 0 || dev == 0x7E780000u || h == 0x7E780000u ||
      obj == 0x7E780000u)
    MCLA_LOG_WARN("BE8D8 #{} obj={:08X} dev={:08X} vt={:08X} h={:08X} lr={:08X}",
                  n, obj, dev, vt, h, lr);
  // Host-complete for memory-device wrappers whose handle is a slot index
  // (0..15) registered by MakeMemoryStream (SLOT-REG). The guest slot table
  // at 0x82860740 holds {buf, size, pos, flag}.
  if (dev == kMemDeviceObj && h < kGuestSlotCount) {
    const uint32_t slot = kGuestSlotTable + h * 16;
    uint32_t sbuf = 0, ssize = 0;
    bool have = mem.ReadU32BE(slot + 0, &sbuf) && mem.ReadU32BE(slot + 4, &ssize);
    if (have && sbuf != 0 && ssize != 0 && ssize != 0xCDCDCDCDu) {
      // BE8D8 semantics, faithfully: alloc(size) then Read all `ssize` bytes
      // into it. The tail (memory:$ format + BE610 + BE0C8) exists to re-open
      // the loaded buffer as a stream; return that stream directly, exactly
      // like the BE0C8-RET host path does.
      const uint32_t dst = mem.Alloc(ssize, 16);
      if (dst != 0) {
        uint8_t tmp[512];
        uint32_t done = 0;
        bool ok = true;
        while (done < ssize) {
          const uint32_t chunk =
              (ssize - done > sizeof(tmp)) ? sizeof(tmp) : ssize - done;
          if (!mem.ReadBytes(sbuf + done, tmp, chunk) ||
              !mem.WriteBytes(dst + done, tmp, chunk)) {
            ok = false;
            break;
          }
          done += chunk;
        }
        if (ok) {
          // Slot consumed (guest close semantics: CB2A0 clears the slot).
          mem.WriteU32BE(slot + 0, 0);
          const uint32_t st = MakeMemoryStream(kMemDeviceObj, dst, ssize);
          MCLA_LOG_WARN("BE8D8-HOST #{} obj={:08X} h={} buf={:08X} size={} "
                        "dst={:08X} stream={:08X}",
                        n, obj, h, sbuf, ssize, dst, st);
          ctx.r3.u32 = st;
          return;
        }
        MCLA_LOG_WARN("BE8D8-HOST #{} copy FAILED buf={:08X} size={}", n, sbuf,
                      ssize);
      } else {
        MCLA_LOG_WARN("BE8D8-HOST #{} alloc FAILED size={} (guest heap)",
                      n, ssize);
      }
    }
  }
  __imp__sub_821BE8D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821BE610);
static std::atomic<uint32_t> s_hBE610{0};
PPC_FUNC(sub_821BE610) {
  const uint32_t n = s_hBE610.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0, h = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  // T7b/T8a: after BE8D8 formats memory:$ the stream object's device/handle
  // are already 0; BE610 still does vtable+48 on null â†’ AV 0x7e780000.
  if (dev == 0) {
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BE610-SKIP #{} obj={:08X} (null device)", n, obj);
    ctx.r3.u32 = 0;
    return;
  }
  if (n <= 24 || (n % 200) == 0 || h == 0x7E780000u)
    MCLA_LOG_WARN("BE610 #{} obj={:08X} dev={:08X} h={:08X}", n, obj, dev, h);
  __imp__sub_821BE610(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821BDD28);
static std::atomic<uint32_t> s_hBDD28{0};
PPC_FUNC(sub_821BDD28) {
  const uint32_t n = s_hBDD28.fetch_add(1) + 1;
  const uint32_t obj = ctx.r3.u32;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t dev = 0, h = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  if (dev == 0) {
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BDD28-SKIP #{} obj={:08X} (null device)", n, obj);
    return;
  }
  if (n <= 24 || (n % 200) == 0 || h == 0x7E780000u)
    MCLA_LOG_WARN("BDD28 #{} obj={:08X} dev={:08X} h={:08X}", n, obj, dev, h);
  __imp__sub_821BDD28(ctx, base);
}

// BE0C8: r4 is the vtable object; r3 is the path (or vice versa after prologue).
// Crash T8b/T9a: stack path ends up in the vtable slot.
PPC_FUNC_IMPL(__imp__sub_821BE0C8);
static std::atomic<uint32_t> s_hBE0C8{0};
PPC_FUNC(sub_821BE0C8) {
  const uint32_t n = s_hBE0C8.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  EnsureMemoryDeviceVtable();
  uint32_t r3 = ctx.r3.u32, r4 = ctx.r4.u32, r5 = ctx.r5.u32;
  uint32_t w3 = 0, w4 = 0, slot4 = 0;
  if (r3) (void)mem.ReadU32BE(r3, &w3);
  if (r4) (void)mem.ReadU32BE(r4, &w4);
  if (w4 == kMemVtable)
    (void)mem.ReadU32BE(w4 + 4, &slot4);
  char pth[96] = {0};
  // Path is whichever pointer is NOT the device object.
  const uint32_t pathG = (r4 == kMemDeviceObj) ? r3 : r4;
  if (pathG != 0 && pathG != 0xCDCDCDCDu)
    (void)mem.ReadBytes(pathG, pth, sizeof(pth) - 1);
  MclaSanitizePath(pth, sizeof(pth));
  // Empty path â†’ GetSize/CB740 never produced "memory:$â€¦". Invent the
  // re-open string from the known CRT blob so BE0C8 can call AFB8 cleanly.
  // Stack is ~0x8E...... (ABOVE image 0x82......) â€” don't gate on <0x82000000.
  if (pth[0] == 0 && pathG != 0 && pathG != 0xFFFFFFFFu) {
    uint32_t buf = 0, size = 0;
    if (!EmbeddedListLookup("fxl_final/rage_im.fxc", &buf, &size)) {
      buf = 0x827D2DD0u;
      size = 5258u;
    }
    char fix[128] = {0};
    std::snprintf(fix, sizeof(fix), "memory:$%08X,%u,0:fxl_final/rage_im.fxc",
                  buf, size);
    mem.WriteBytes(pathG, fix, static_cast<uint32_t>(std::strlen(fix) + 1));
    MCLA_LOG_WARN("BE0C8-FIX #{} wrote '{}' @{:08X}", n, fix, pathG);
    std::strncpy(pth, fix, sizeof(pth) - 1);
  }
  if (pth[0] == 0) {
    MCLA_LOG_WARN("BE0C8-SKIP #{} r3={:08X} r4={:08X} empty path lr={:08X}",
                  n, r3, r4, static_cast<uint32_t>(ctx.lr));
    ctx.r3.u32 = 0;
    return;
  }
  MCLA_LOG_WARN("BE0C8 #{} r3={:08X}[{:08X}] r4={:08X}[{:08X}] vt+4={:08X} "
                "pth='{}' r5={} lr={:08X}",
                n, r3, w3, r4, w4, slot4, pth, r5,
                static_cast<uint32_t>(ctx.lr));
  // Host-complete the re-open: guest bctrlâ†’AFB8 with this stack path AVed
  // (function-table lookup null / 0x0). Return the buffer handle ourselves.
  uint32_t mb = 0, ms = 0;
  if (ParseMemoryDollar(pth, &mb, &ms) && mb != 0) {
    const uint32_t st = MakeMemoryStream(kMemDeviceObj, mb, ms);
    MCLA_LOG_WARN("BE0C8-RET stream={:08X} buf={:08X} size={}", st, mb, ms);
    ctx.r3.u32 = st;
    return;
  }
    __imp__sub_821BE0C8(ctx, base);
}

// Shared no-op vtable stub (li r3,0; blr). 8C760 calls device+88 after
// GETDEV; if the function-table slot is null we AV at 0x0. Strong override.
PPC_FUNC_IMPL(__imp__sub_821A5CC0);
PPC_FUNC(sub_821A5CC0) {
  ctx.r3.u32 = 0;
}

// After 8C760 accepts the rgxa magic, D3070(bufobj, size) runs with r3=0.
// Guard the null object.
PPC_FUNC_IMPL(__imp__sub_821D3070);
static std::atomic<uint32_t> s_hD3070{0};
PPC_FUNC(sub_821D3070) {
  const uint32_t n = s_hD3070.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  uint32_t field8 = 0;
  if (obj != 0 && obj != 0xCDCDCDCDu)
    (void)mem.ReadU32BE(obj + 8, &field8);
  // 8C760 magic-accept path does ori r4,r4,0x8000 then D3070 â€” original
  // pulls r3 from TLS[+28] and AVs when that is null (0x7e780000).
  const bool fromMagic = (ctx.r4.u32 & 0x8000u) != 0 &&
                         (ctx.lr == 0x8218C89Cu ||
                          static_cast<uint32_t>(ctx.lr) == 0x8218C89Cu);
  if (obj == 0 || obj == 0xCDCDCDCDu || field8 == 0 || field8 == 0xCDCDCDCDu ||
      (ctx.r4.u32 & 0x8000u) != 0) {
    if (n <= 16 || (ctx.r4.u32 & 0x8000u) != 0)
      MCLA_LOG_WARN("D3070-SKIP #{} obj={:08X} +8={:08X} r4={:08X} lr={:08X}",
                    n, obj, field8, ctx.r4.u32,
                    static_cast<uint32_t>(ctx.lr));
    ctx.r3.u32 = 0;
    return;
  }
  __imp__sub_821D3070(ctx, base);
}

// Stream read: [obj+0] must be a live device. Dead wrapper â†’ serve bytes from
// the wrapper fields ourselves (MakeMemoryStream layout) so factory reads get
// real data instead of -1 (which cascaded into AF68's cap=-1 AV).
PPC_FUNC_IMPL(__imp__sub_821BE250);
static std::atomic<uint32_t> s_hBE250{0};
PPC_FUNC(sub_821BE250) {
  const uint32_t n = s_hBE250.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t dst = ctx.r4.u32;
  const uint32_t count = ctx.r5.u32;
  uint32_t dev = 0, h = 0;
  if (obj && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  // p2d rgxa fix: live memory-device wrapper whose handle is one of our
  // slot indices — serve from the slot table directly (821CB158 contract).
  // The original body's buffered-refill path reads uninitialized wrapper
  // fields (+8/+24/+28/+32) and serves wrong bytes ("Old version" fatal).
  if (dev == kMemDeviceObj && h != 0 && h < kGuestSlotCount) {
    const int64_t served = SlotTableServeRead(h, dst, count);
    if (served >= 0) {
      if (n <= 24 || (n % 200) == 0)
        MCLA_LOG_WARN("BE250-SLOT #{} obj={:08X} h={} served={} count={}",
                      n, obj, h, served, count);
      ctx.r3.u32 = static_cast<uint32_t>(served);
      return;
    }
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BE250-SLOT-MISS #{} obj={:08X} h={} count={}", n, obj, h,
                    count);
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  if (dev == 0 || dev == 0xCDCDCDCDu) {
    const int64_t served = MemoryStreamServeRead(obj, dst, count);
    if (served >= 0) {
      if (n <= 24 || (n % 200) == 0)
        MCLA_LOG_WARN("BE250-MEM #{} obj={:08X} served={} count={} posfield=+24",
                      n, obj, served, count);
      ctx.r3.u32 = static_cast<uint32_t>(served);
      return;
    }
    if (n <= 24 || (n % 200) == 0)
      MCLA_LOG_WARN("BE250-SKIP #{} obj={:08X} dev={:08X}", n, obj, dev);
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  __imp__sub_821BE250(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821BE710);
static std::atomic<uint32_t> s_hBE710{0};
PPC_FUNC(sub_821BE710) {
  const uint32_t n = s_hBE710.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  uint32_t dev = 0, h = 0;
  if (obj && obj != 0xCDCDCDCDu) {
    (void)mem.ReadU32BE(obj + 0, &dev);
    (void)mem.ReadU32BE(obj + 4, &h);
  }
  // p2d rgxa fix: live memory-device wrapper with a slot-table handle.
  // Original BE710 shifts r5 by 2 (word count) then tails into BE250's
  // buffered machinery, which needs initialized wrapper fields we never
  // set for slot handles — serve from the slot table instead (exact
  // 821CB158 semantics: copy min(count, size-pos), advance slot pos).
  if (dev == kMemDeviceObj && h != 0 && h < kGuestSlotCount) {
    const uint32_t bytes = ctx.r5.u32 * 4u;
    const int64_t served = SlotTableServeRead(h, ctx.r4.u32, bytes, true);
    if (served >= 0) {
      MCLA_LOG_WARN("BE710-SLOT #{} obj={:08X} h={} words={} served={}", n,
                    obj, h, ctx.r5.u32, served);
      ctx.r3.u32 = static_cast<uint32_t>(served) / 4u;
      return;
    }
    MCLA_LOG_WARN("BE710-SLOT-MISS #{} obj={:08X} h={} words={}", n, obj, h,
                  ctx.r5.u32);
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  if (dev == 0 || dev == 0xCDCDCDCDu) {
    auto &mem2 = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t sbuf = 0, ssize = 0;
    if (s_lastMemStream != 0) {
      (void)mem2.ReadU32BE(s_lastMemStream + 4, &sbuf);
      (void)mem2.ReadU32BE(s_lastMemStream + 8, &ssize);
    }
    MCLA_LOG_WARN("BE710-DEAD #{} obj={:08X} lastStream={:08X} sbuf={:08X} "
                  "ssize={} r4={:08X}",
                  n, obj, s_lastMemStream, sbuf, ssize, ctx.r4.u32);
    if (sbuf != 0 && ssize >= 4 && ctx.r4.u32 != 0) {
      mem2.WriteU32BE(ctx.r4.u32, 0x61786772u);
      MCLA_LOG_WARN("BE710-MAGIC #{} wrote 61786772", n);
      ctx.r3.u32 = 1;
      return;
    }
    ctx.r3.u32 = static_cast<uint32_t>(-1);
    return;
  }
  if (n <= 16 || (n % 200) == 0)
    MCLA_LOG_WARN("BE710 #{} obj={:08X} dev={:08X} h={:08X} r5={}", n, obj, dev,
                  h, ctx.r5.u32);
  __imp__sub_821BE710(ctx, base);
}

// ===========================================================================
// T5-next (t23a frontier): atArray ctor guards - sub_8218AF68 (16-byte
// stride) and sub_82189F00 (32-byte stride).
//
// Shared ABI (ppc_recomp.9.cpp:14521 / :11806): r3=obj, r4=count, r5=cap.
//   sth count -> obj+4 ; sth cap -> obj+6
//   r10 = *(r13)                       <- TLS table (WIPED at runtime:
//                                         park sample tls0=00000000)
//   r3  = *(r10+12)                    <- slot +12 allocator descriptor
//   r11 = *(r3) ; ctr = *(r11+8) ; bctrl   <- alloc(cap*stride, align 16)
//   *(obj+0) = alloc result; then count entries field-zeroed (16B: [+8]=0;
//   32B: +4/+8/+20/+24=0, +28/+30=0xFFFF).
//
// Faults observed (boot_stdout_t22a.log, t23a.log):
//   1. bctrl through ctr=0 (TLS wiped) -> PPC_LOOKUP_FUNC(0) -> host AV
//      0x7E780000 (that "wild pointer" is literally lookup-of-guest-0).
//   2. Caller 8C1C0 passes count/cap = -1 (0xFFFFFFF0) because the upstream
//      ReadByte chain got -1 from the dead stream -> count/cap poison.
//
// Guard: null obj -> return; insane count/cap (>0x8000, covers -1) -> empty
// array; TLS wiped -> host-complete the ctor faithfully.
// ===========================================================================
PPC_FUNC_IMPL(__imp__sub_8218AF68);
static std::atomic<uint32_t> s_hAF68{0};

// Shared guard body. entryBytes = 16 or 32. Returns true when handled.
static bool AtArrayCtorGuard(PPCContext &__restrict ctx, uint32_t n,
                             uint32_t entryBytes) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);

  if (obj == 0 || obj == 0xCDCDCDCDu) {
    MCLA_LOG_WARN("ATARRAY-SKIP #{} null obj lr={:08X}", n, lr);
    return true;
  }

  // Count/cap live in the low 16 bits of r4/r5 (sth stores). -1 -> 0xFFFF.
  const uint32_t countRaw = ctx.r4.u32 & 0xFFFFu;
  const uint32_t capRaw = ctx.r5.u32 & 0xFFFFu;

  // Poisoned args (from BE250 -1 upstream): empty array.
  if (countRaw > 0x8000u || capRaw > 0x8000u) {
    MCLA_LOG_WARN("ATARRAY-CLAMP #{} obj={:08X} count={:04X} cap={:04X} "
                  "stride={} lr={:08X} (poisoned args, empty array)",
                  n, obj, countRaw, capRaw, entryBytes, lr);
    (void)mem.WriteU16BE(obj + 4, 0);
    (void)mem.WriteU16BE(obj + 6, 0);
    (void)mem.WriteU32BE(obj + 0, 0);
    return true;
  }

  // TLS table alive? Fast path: original body handles everything.
  uint32_t tlsTable = 0;
  if (ctx.r13.u32 != 0 && mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
      tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
    return false;
  }

  // TLS wiped: host-complete the ctor faithfully.
  MCLA_LOG_WARN("ATARRAY-TLSDEAD #{} obj={:08X} count={} cap={} stride={} "
                "lr={:08X}",
                n, obj, countRaw, capRaw, entryBytes, lr);
  (void)mem.WriteU16BE(obj + 4, static_cast<uint16_t>(countRaw));
  (void)mem.WriteU16BE(obj + 6, static_cast<uint16_t>(capRaw));
  uint32_t arrPtr = 0;
  if (capRaw != 0) {
    arrPtr = mem.Alloc(capRaw * entryBytes, 16);
    if (arrPtr == 0) {
      MCLA_LOG_WARN("ATARRAY-ALLOCFAIL #{} cap={} stride={}", n, capRaw,
                    entryBytes);
      (void)mem.WriteU16BE(obj + 4, 0);
      (void)mem.WriteU16BE(obj + 6, 0);
      (void)mem.WriteU32BE(obj + 0, 0);
      return true;
    }
  }
  (void)mem.WriteU32BE(obj + 0, arrPtr);
  if (arrPtr != 0 && countRaw != 0) {
    // 16B entries (AF68): [+8]=0. 16B entries (BFF0): +0/+4/+8=0, +12/+14=0.
    // 32B entries (8F00): +4/+8/+20/+24=0, +28/+30=0xFFFF. The zero-init
    // differences don't matter for a zeroed array — all-zero entries match
    // every variant except 8F00's 0xFFFF tails, kept exact above.
    if (entryBytes == 16) {
      uint8_t zero[16] = {0};
      for (uint32_t i = 0; i < countRaw; ++i)
        (void)mem.WriteBytes(arrPtr + i * 16u, zero, sizeof(zero));
    } else {
      uint8_t zero[32] = {0};
      zero[28] = 0xFF;
      zero[29] = 0xFF;
      zero[30] = 0xFF;
      zero[31] = 0xFF;
      for (uint32_t i = 0; i < countRaw; ++i)
        (void)mem.WriteBytes(arrPtr + i * 32u, zero, sizeof(zero));
    }
  }
  return true;
}

PPC_FUNC(sub_8218AF68) {
  const uint32_t n = s_hAF68.fetch_add(1) + 1;
  if (AtArrayCtorGuard(ctx, n, 16))
    return;
  __imp__sub_8218AF68(ctx, base);
}

// 32-byte-stride sibling (t23a AV at +0x50, lr=82189F50, same TLS+12 chain).
PPC_FUNC_IMPL(__imp__sub_82189F00);
static std::atomic<uint32_t> s_h89F00{0};
PPC_FUNC(sub_82189F00) {
  const uint32_t n = s_h89F00.fetch_add(1) + 1;
  if (AtArrayCtorGuard(ctx, n, 32))
    return;
  __imp__sub_82189F00(ctx, base);
}

// 16-byte-stride sibling #2 (t23b AV at +0x50, lr=8218C040, from 8C1C0+0x1101).
// Entry zero-init: +0/+4/+8 (u32) +12/+14 (u16) — all-zero entries cover it.
PPC_FUNC_IMPL(__imp__sub_8218BFF0);
static std::atomic<uint32_t> s_hBFF0{0};
PPC_FUNC(sub_8218BFF0) {
  const uint32_t n = s_hBFF0.fetch_add(1) + 1;
  if (AtArrayCtorGuard(ctx, n, 16))
    return;
  __imp__sub_8218BFF0(ctx, base);
}

// ===========================================================================
// T5 systemic fix (t23c frontier): the XTL allocation import thunks
// (sub_82130528/550/588) resolve the host allocator through the guest TLS
// table: *( *(r13) + 28 ) -> FuncBlock -> +8 alloc / +12 free. The TLS block
// at 0x8F200000 gets WIPED at runtime (park sample tls0=00000000), so every
// late-boot alloc/free through these thunks AVs at 0x7E780000 (= lookup of
// guest-0). These are strong overrides: same result contract as __xtl_alloc /
// __xtl_free (kernel/imports.cpp), TLS-independent.
//   sub_82130528(r3=size)        -> alloc(size, align 16)
//   sub_82130550(r3=a, r4=b)     -> alloc(max(a,b), align 16)
//   sub_82130588(r3=ptr)         -> free(ptr) — returns success (r3=1)
// ===========================================================================
PPC_EXTERN_FUNC(__xtl_alloc);
PPC_EXTERN_FUNC(__xtl_free);
static std::atomic<uint32_t> s_hXtlImport{0};
static void XtlImportCensus(const char *which, uint32_t n, uint32_t a,
                            uint32_t b) {
  if (n <= 8 || (n % 500) == 0)
    MCLA_LOG_WARN("XTLIMPORT #{} {} a={:08X} b={:08X}", n, which, a, b);
}

PPC_FUNC_IMPL(__imp__sub_82130528);
PPC_FUNC(sub_82130528) {
  const uint32_t n = s_hXtlImport.fetch_add(1) + 1;
  XtlImportCensus("alloc", n, ctx.r3.u32, 0);
  // Original thunk: mr r4,r3; li r5,16; li r6,0 then TLS-slot-28 call.
  // __xtl_alloc reads r4 (size) and r5 (align) — restore the full ABI.
  ctx.r4.u32 = ctx.r3.u32;
  ctx.r5.u32 = 16;
  ctx.r6.u32 = 0;
  __xtl_alloc(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82130550);
PPC_FUNC(sub_82130550) {
  const uint32_t n = s_hXtlImport.fetch_add(1) + 1;
  // Original: r11 = max(r3, r4); then mr r4,r11; li r5,16; li r6,0.
  const uint32_t sz = (ctx.r3.u32 > ctx.r4.u32) ? ctx.r3.u32 : ctx.r4.u32;
  XtlImportCensus("alloc-max", n, ctx.r3.u32, ctx.r4.u32);
  ctx.r4.u32 = sz;
  ctx.r5.u32 = 16;
  ctx.r6.u32 = 0;
  __xtl_alloc(ctx, base);
  if (ctx.r3.u32 == 0 && sz != 0)
    MCLA_LOG_WARN("XTLIMPORT alloc-max #{} FAILED size={}", n, sz);
}

// ===========================================================================
// T5 (t24b frontier): sub_821D30E8 buffer-Grow via dead TLS FuncBlock+16.
//
// ABI (ppc_recomp.18.cpp:3185): r3 = bufobj {+8 blk {ptr@0,size@4}, +4 size,
// +12 next-cap}. Rounds size up to 16, reallocs via *(TLS slot 28 fn)+16
// (Realloc slot), stores blk->ptr, mirrors obj+4 -> blk+4, parks obj+12 in
// TLS[+12], clears obj+12. Crash: lr=821D3134, r3=0 (caller 8C760+0x3FB
// passed the stream wrapper whose +8 block was wiped).
// Host-complete: grow via GuestMemoryHeap::Alloc, copy, faithful stores.
// ===========================================================================
PPC_FUNC_IMPL(__imp__sub_821D30E8);
static std::atomic<uint32_t> s_hD30E8{0};
PPC_FUNC(sub_821D30E8) {
  const uint32_t n = s_hD30E8.fetch_add(1) + 1;
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t obj = ctx.r3.u32;
  const uint32_t lr = static_cast<uint32_t>(ctx.lr);
  if (obj == 0 || obj == 0xCDCDCDCDu) {
    MCLA_LOG_WARN("D30E8-SKIP #{} null obj lr={:08X}", n, lr);
    return;
  }
  uint32_t blk = 0, size = 0, oldPtr = 0;
  (void)mem.ReadU32BE(obj + 8, &blk);
  (void)mem.ReadU32BE(obj + 4, &size);
  if (blk != 0 && blk != 0xCDCDCDCDu)
    (void)mem.ReadU32BE(blk + 0, &oldPtr);
  // Original rounds the requested size up to 16 (addi 15; rlwinm ... 27).
  const uint32_t rounded = (size + 15u) & ~15u;
  (void)mem.WriteU32BE(obj + 4, rounded);
  // TLS-table alive? Let the original body run (its bctrl uses TLS FuncBlock
  // +16 Realloc which the boot chain arms).
  uint32_t tlsTable = 0;
  if (ctx.r13.u32 != 0 && mem.ReadU32BE(ctx.r13.u32, &tlsTable) &&
      tlsTable != 0 && tlsTable != 0xCDCDCDCDu) {
    __imp__sub_821D30E8(ctx, base);
    return;
  }
  // TLS dead: host-complete the grow.
  MCLA_LOG_WARN("D30E8-TLSDEAD #{} obj={:08X} blk={:08X} size={} old={:08X}",
                n, obj, blk, rounded, oldPtr);
  if (blk == 0 || blk == 0xCDCDCDCDu) {
    // Nothing to grow — mirror the skip path (caller treats size as-is).
    return;
  }
  const uint32_t newPtr = mem.Alloc(rounded ? rounded : 16u, 16);
  if (newPtr == 0) {
    MCLA_LOG_WARN("D30E8-ALLOCFAIL #{} size={}", n, rounded);
    return;
  }
  if (oldPtr != 0) {
    // Preserve prior contents (realloc semantics).
    uint8_t tmp[512];
    uint32_t copied = 0;
    uint32_t oldSize = 0;
    (void)mem.ReadU32BE(blk + 4, &oldSize);
    const uint32_t lim = (oldSize < rounded) ? oldSize : rounded;
    while (copied < lim) {
      const uint32_t chunk = (lim - copied > sizeof(tmp)) ? sizeof(tmp) : lim - copied;
      if (!mem.ReadBytes(oldPtr + copied, tmp, chunk) ||
          !mem.WriteBytes(newPtr + copied, tmp, chunk))
        break;
      copied += chunk;
    }
  }
  (void)mem.WriteU32BE(blk + 0, newPtr);
  (void)mem.WriteU32BE(blk + 4, rounded);
  // Original: TLS[+12] = obj+12 then obj+12 = 0 — the TLS write is part of
  // the real contract; keep it best-effort (r13 block is dead anyway).
  (void)mem.WriteU32BE(obj + 12, 0);
}

PPC_FUNC_IMPL(__imp__sub_82130588);
PPC_FUNC(sub_82130588) {
  const uint32_t n = s_hXtlImport.fetch_add(1) + 1;
  XtlImportCensus("free", n, ctx.r3.u32, 0);
  // Original thunk: r4=r3 then TLS-slot-28 call with FuncBlock+12 (free).
  ctx.r4.u32 = ctx.r3.u32;
  __xtl_free(ctx, base);
}
