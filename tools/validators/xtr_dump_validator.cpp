// Standalone Xenia .xtr frame-trace dumper / validator.
//
// The built-in host frame trace (written by the GPU plugin's TraceWriter on
// the command-processor thread) produces a .xtr file with the header layout
// in the trace protocol.  This tool parses that stream directly
// (no runtime dependency) and reports:
//
//   1. Header integrity (format version, title_id).
//   2. Per-command counts (packet start/end, memory reads/writes, registers,
//      events/swaps, EDRAM snapshots, primary/indirect buffer spans).
//   3. Decoded register writes (so we can see SQ_VS/SQ_PS program + VB/IB
//      base/stride registers that prove real guest geometry state).
//   4. Decoded memory-read ranges (the vertex/index/constant data the GPU
//      actually fetched), with snappy payloads expanded.
//
// This is the offline evidence gate for Phase 3: proving the host path emits
// real draws + geometry, distinct from the dead guest PPC hooks.
//
// Usage:
//   xtr_dump_validator.exe <trace.xtr> [--hex] [--verbose]
//   xtr_dump_validator.exe                   (built-in self-test)
//
// Exit code 0 = clean, 1 = errors found.

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <map>    
#include <set>    
#include <string> 
#include <vector>

namespace proto {
// Mirrors the trace protocol (kept local so this tool has no SDK
// dependency).  This is the Xenia .xtr on-disk format, version 1.
static const uint32_t kTraceFormatVersion = 1;

struct TraceHeader {
  uint32_t version;
  char build_commit_sha[40];
  uint32_t title_id;
};

enum class TC : uint32_t {
  kPrimaryBufferStart,
  kPrimaryBufferEnd,
  kIndirectBufferStart,
  kIndirectBufferEnd,
  kPacketStart,
  kPacketEnd,
  kMemoryRead,
  kMemoryWrite,
  kEdramSnapshot,
  kEvent,
  kRegisters,
  kGammaRamp,
};

enum class MEnc : uint32_t { kNone = 0, kSnappy = 1 };
}  // namespace proto

// Minimal raw snappy decompressor (standard snappy stream, which is what
// Xenia/TraceWriter writes for compressed memory payloads).  *out receives the
// decoded bytes.  Returns false on unsupported/truncated input.
//
// Tag format (matches snappy's DecompressAllTags; verified byte-for-byte
// against an independent reference decoder):
//   tag&3 == 0 : literal, length = (tag>>2)+1
//                (if >=61, length-1 is stored in (tag>>2)-60 extra LE bytes)
//   tag&3 == 3 : copy with 4-byte offset; length = (tag>>2)+1
//   tag&3 == 1 : copy with 1-byte offset; length = ((tag>>2)&7)+4;
//                offset = trailer(1) - entry + length, where
//                entry = ((tag>>2)&7)+4 - ((tag>>5)<<8)
//   tag&3 == 2 : copy with 2-byte offset; length = (tag>>2)+1;
//                offset = trailer(2) (16-bit LE trailer is the raw offset)
static bool SnappyUncompress(const uint8_t* src, size_t srcLen, std::vector<uint8_t>& out) {
  size_t p = 0;
  out.clear();

  // Varint uncompressed length.
  uint64_t ulen = 0;
  for (int i = 0; i < 10; ++i) {
    if (p >= srcLen) return false;
    uint8_t b = src[p++];
    ulen |= static_cast<uint64_t>(b & 0x7F) << (7u * i);
    if (!(b & 0x80)) break;
  }
  if (ulen > 512u * 1024u * 1024u) return false;
  out.reserve(static_cast<size_t>(ulen));

  size_t outPos = 0;
  auto load_le = [&](size_t off, size_t n) -> uint64_t {
    uint64_t v = 0;
    for (size_t i = 0; i < n && off + i < srcLen; ++i) v |= uint64_t(src[off + i]) << (8u * i);
    return v;
  };
  auto grow = [&](size_t need) {
    if (out.size() < need) out.resize(need);
  };
  auto copy_self = [&](size_t offset, size_t length) -> bool {
    if (offset == 0 || offset > outPos) return false;
    grow(outPos + length);
    if (outPos + length > out.size()) return false;
    for (size_t i = 0; i < length; ++i) out[outPos + i] = out[outPos + i - offset];
    outPos += length;
    return true;
  };

  while (p < srcLen) {
    uint32_t tag = src[p++];
    uint32_t tagType = tag & 3u;

    if (tagType == 0) {  // literal
      uint32_t len = (tag >> 2) + 1;
      if (len >= 61) {  // long literal: (tag>>2)-60 extra LE bytes hold len-1
        uint32_t nb = (tag >> 2) - 60;
        if (nb < 1 || nb > 4 || p + nb > srcLen) return false;
        len = 0;
        for (uint32_t i = 0; i < nb; ++i) len |= uint32_t(src[p++]) << (8u * i);
        len += 1;
      }
      if (p + len > srcLen) return false;
      grow(outPos + len);
      std::memcpy(out.data() + outPos, src + p, len);
      p += len;
      outPos += len;
      continue;
    }

    if (tagType == 3) {  // copy with 4-byte offset
      if (p + 4 > srcLen) return false;
      uint32_t offset = (uint32_t)load_le(p, 4);
      p += 4;
      uint32_t length = (tag >> 2) + 1;
      if (!copy_self(offset, length)) return false;
      continue;
    }

    // tagType == 1 or 2 (copy with 1- or 2-byte offset)
    uint32_t d = tag >> 2;
    // int16 entry per LengthMinusOffset[tag].
    int32_t raw = (tagType == 2) ? (int32_t)(d + 1)
                                 : (int32_t)(((d & 7) + 4) - ((d >> 3) << 8));
    int16_t entry = (int16_t)raw;
    uint32_t ntr = (tagType == 1) ? 1 : 2;
    if (p + ntr > srcLen) return false;
    uint32_t trailer = (uint32_t)load_le(p, ntr);
    uint32_t length = (uint32_t)(entry & 0xFF);
    uint32_t copy_offset = (uint32_t)((int64_t)trailer - entry + (int64_t)length);
    p += ntr;
    if (!copy_self(copy_offset, length)) return false;
  }

  return outPos == ulen;
}

static const char* MemEncName(uint32_t e) {
  switch (static_cast<proto::MEnc>(e)) {
    case proto::MEnc::kNone: return "none";
    case proto::MEnc::kSnappy: return "snappy";
  }
  return "?";
}
static const char* RegName(uint32_t reg) {
  switch (reg) {
    case 0x01C5: return "CP_RB_WPTR";
    case 0x0A2F: return "COHER_SIZE_HOST";
    case 0x0A30: return "COHER_BASE_HOST";
    case 0x1844: return "D1GRPH_PRIMARY_SURFACE_ADDRESS";
    case 0x2000: return "RB_SURFACE_INFO";
    case 0x2001: return "RB_COLOR_INFO";
    case 0x2002: return "RB_DEPTH_INFO";
    case 0x2082: return "PA_SC_WINDOW_SCISSOR_BR";
    case 0x2102: return "VGT_INDX_OFFSET";
    case 0x21F9: return "VGT_EVENT_INITIATOR";
    case 0x21FC: return "VGT_DRAW_INITIATOR";
    case 0x2319: return "RB_COPY_DEST_BASE";
    case 0x231A: return "RB_COPY_DEST_PITCH";
  }
  return nullptr;
}
static const char* TcName(proto::TC t) {
  switch (t) {
    case proto::TC::kPrimaryBufferStart: return "PrimaryBufferStart";
    case proto::TC::kPrimaryBufferEnd: return "PrimaryBufferEnd";
    case proto::TC::kIndirectBufferStart: return "IndirectBufferStart";
    case proto::TC::kIndirectBufferEnd: return "IndirectBufferEnd";
    case proto::TC::kPacketStart: return "PacketStart";
    case proto::TC::kPacketEnd: return "PacketEnd";
    case proto::TC::kMemoryRead: return "MemoryRead";
    case proto::TC::kMemoryWrite: return "MemoryWrite";
    case proto::TC::kEdramSnapshot: return "EdramSnapshot";
    case proto::TC::kEvent: return "Event";
    case proto::TC::kRegisters: return "Registers";
    case proto::TC::kGammaRamp: return "GammaRamp";
  }
  return "?";
}

static int g_errors = 0;
static int g_verbose = 0;
static int g_hex = 0;
static int g_dump_mem = 0;

static void Diag(bool ok, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::printf(ok ? "  [OK] " : "  [!!] ");
  std::vprintf(fmt, args);
  std::printf("\n");
  va_end(args);
  if (!ok) g_errors++;
}

struct Counts {
  uint64_t primaryStart = 0, primaryEnd = 0;
  uint64_t indirectStart = 0, indirectEnd = 0;
  uint64_t packetStart = 0, packetEnd = 0;
  uint64_t memRead = 0, memWrite = 0;
  uint64_t edram = 0, event = 0, registers = 0, gamma = 0;
  uint64_t totalBytes = 0;
  uint64_t memReadBytes = 0;
  uint64_t memWriteBytes = 0;
  uint64_t primaryDwords = 0;
  uint64_t packetDwords = 0;
  std::map<uint32_t, uint64_t> regWrites;  // register index -> write count
  std::map<uint32_t, uint32_t> regValues;  // first register set snapshot (live value)
  struct MemOp {
    uint32_t base;
    uint32_t enc, encLen, decLen;
    bool isWrite;
    const uint8_t* payloadPtr;  // into the original file buffer
  };
  std::vector<MemOp> memOps;
};

// Parse one command starting at d.  Advances `consumed` by the number of
// bytes consumed.  Returns an error string, or nullptr on success.  The
// command's mnemonic is copied into mnem[64].
static const char* ParseCommand(const uint8_t* d, const uint8_t* end, uint64_t& consumed,
                                Counts& c, std::vector<uint8_t>& scratch, char* mnemonic) {
  if (end - d < 4) return "truncated command tag";
  const uint8_t* body = d + 4;
  proto::TC type = static_cast<proto::TC>(*(const uint32_t*)d);
  const uint8_t* p = body;
  std::snprintf(mnemonic, 64, "%s", TcName(type));

#define NEED(n)                                        \
  do {                                                 \
    if (p + (n) > end) return "truncated command body"; \
  } while (0)
#define ADV (p += 4)
#define SKIP(nee) (p += (nee))

  switch (type) {
    case proto::TC::kPrimaryBufferStart: {
      // PrimaryBufferStartCommand: type(4) + base_ptr + count(4), then count
      // dwords of inline command body follow (12 + count*4 total).
      NEED(8);
      uint32_t base = *(const uint32_t*)(p + 0);
      uint32_t cnt = *(const uint32_t*)(p + 4);
      SKIP(8);
      if (p + (size_t)cnt * 4 > end) return "truncated primary body";
      if (g_verbose) std::printf("      primary buf start base=0x%08X count=%u\n", base, cnt);
      c.primaryStart++;
      c.primaryDwords += cnt;
      SKIP(cnt * 4u);
      break;
    }
    case proto::TC::kPrimaryBufferEnd:
      c.primaryEnd++;
      break;
    case proto::TC::kIndirectBufferStart: {
      // IndirectBufferStartCommand: type + base_ptr + count, then count dwords
      // of inline command body (12 + count*4 total).
      NEED(8);
      uint32_t base = *(const uint32_t*)(p + 0);
      uint32_t cnt = *(const uint32_t*)(p + 4);
      SKIP(8);
      if (p + (size_t)cnt * 4 > end) return "truncated indirect body";
      if (g_verbose) std::printf("      indirect buf start base=0x%08X count=%u\n", base, cnt);
      c.indirectStart++;
      SKIP(cnt * 4u);
      break;
    }
    case proto::TC::kIndirectBufferEnd:
      c.indirectEnd++;
      break;
    case proto::TC::kPacketStart: {
      // PacketStartCommand: type + base_ptr + count, then count dwords of
      // inline command body (12 + count*4 total).
      NEED(8);
      uint32_t base = *(const uint32_t*)(p + 0);
      uint32_t cnt = *(const uint32_t*)(p + 4);
      SKIP(8);
      if (p + (size_t)cnt * 4 > end) return "truncated packet body";
      if (g_verbose) std::printf("      <packet begin> base=0x%08X count=%u\n", base, cnt);
      c.packetStart++;
      c.packetDwords += cnt;
      SKIP(cnt * 4u);
      break;
    }
    case proto::TC::kPacketEnd:
      c.packetEnd++;
      break;
    case proto::TC::kMemoryRead: {
      // MemoryCommand: type + base + enc + encLen + decLen (20 total).
      NEED(16);
      uint32_t base = *(const uint32_t*)(p + 0);
      uint32_t enc = *(const uint32_t*)(p + 4);
      uint32_t encLen = *(const uint32_t*)(p + 8);
      uint32_t decLen = *(const uint32_t*)(p + 12);
      SKIP(16);
      if (p + encLen > end) return "truncated memread payload";
      if (g_verbose)
        std::printf("      memRead base=0x%08X enc=%s len=%u/%u\n", base,
                    MemEncName(enc), encLen, decLen);
      c.memRead++;
      c.memReadBytes += decLen;
      c.memOps.push_back({base, enc, encLen, decLen, false, p});
      SKIP(encLen);
      break;
    }
    case proto::TC::kMemoryWrite: {
      // MemoryCommand: type + base + enc + encoded_length + decoded_length (20).
      NEED(16);
      uint32_t base = *(const uint32_t*)(p + 0);
      uint32_t enc = *(const uint32_t*)(p + 4);
      uint32_t encLen = *(const uint32_t*)(p + 8);
      uint32_t decLen = *(const uint32_t*)(p + 12);
      SKIP(16);
      if (p + encLen > end) return "truncated memwrite payload";
      if (g_verbose)
        std::printf("      memWrite base=0x%08X enc=%s len=%u/%u\n", base,
                    MemEncName(enc), encLen, decLen);
      c.memWrite++;
      c.memWriteBytes += decLen;
      c.memOps.push_back({base, enc, encLen, decLen, true, p});
      SKIP(encLen);
      break;
    }
    case proto::TC::kEdramSnapshot: {
      // EdramSnapshotCommand: type + encoding_format + encoded_length (12).
      NEED(8);
      uint32_t enc = *(const uint32_t*)(p + 0);
      uint32_t encLen = *(const uint32_t*)(p + 4);
      SKIP(8);
      if (p + encLen > end) return "truncated edram payload";
      if (g_verbose) std::printf("      edram enc=%s len=%u\n", MemEncName(enc), encLen);
      c.edram++;
      SKIP(encLen);
      break;
    }
    case proto::TC::kEvent: {
      // EventCommand: type + event_type(4) (8 total).
      NEED(4);
      uint32_t ev = *(const uint32_t*)(p + 0);
      SKIP(4);
      if (g_verbose) std::printf("      event type=%u\n", ev);
      c.event++;
      break;
    }
    case proto::TC::kRegisters: {
      // RegistersCommand: type + first + count + execute_callbacks(bool+pad) +
      // encoding_format + encoded_length (24 total).
      NEED(20);
      uint32_t first = *(const uint32_t*)(p + 0);
      uint32_t count = *(const uint32_t*)(p + 4);
      uint32_t enc = *(const uint32_t*)(p + 12);
      uint32_t encLen = *(const uint32_t*)(p + 16);
      SKIP(20);
      if (p + encLen > end) return "truncated registers payload";
      c.registers++;
      const uint8_t* payload = p;
      scratch.clear();
      const uint32_t* vals = nullptr;
      uint32_t nvals = 0;
      if (static_cast<proto::MEnc>(enc) == proto::MEnc::kNone) {
        vals = reinterpret_cast<const uint32_t*>(payload);
        nvals = count;
      } else {
        if (!SnappyUncompress(payload, encLen, scratch)) {
          if (g_verbose) std::printf("      reg decode failed\n");
        } else {
          vals = reinterpret_cast<const uint32_t*>(scratch.data());
          nvals = static_cast<uint32_t>(scratch.size() / 4);
        }
      }
      for (uint32_t i = 0; i < nvals; ++i) {
        uint32_t reg = first + i;
        c.regWrites[reg]++;
        if (vals) c.regValues[reg] = vals[i];
        if (g_verbose) std::printf("      reg[0x%04X] = 0x%08X\n", reg, vals[i]);
      }
      SKIP(encLen);
      break;
    }
    case proto::TC::kGammaRamp: {
      // GammaRampCommand: type + rw_component(1+pad3) + encoding_format +
      // encoded_length (16 total).
      NEED(12);
      uint32_t enc = *(const uint32_t*)(p + 4);
      uint32_t encLen = *(const uint32_t*)(p + 8);
      SKIP(12);
      if (p + encLen > end) return "truncated gamma payload";
      if (g_verbose) std::printf("      gamma enc=%s len=%u\n", MemEncName(enc), encLen);
      c.gamma++;
      SKIP(encLen);
      break;
    }
  }
  consumed = static_cast<uint64_t>(p - d);
#undef NEED_T
#undef ADV
#undef SKIP
  return nullptr;
}

static int AnalyzeFile(const char* path) {
  std::printf("== Trace: %s\n", path);
  FILE* f = std::fopen(path, "rb");
  if (!f) {
    Diag(false, "cannot open %s", path);
    return 1;
  }
  std::fseek(f, 0, SEEK_END);
  long sz = std::ftell(f);
  std::fseek(f, 0, SEEK_SET);
  std::vector<uint8_t> data(sz);
  if (fread(data.data(), 1, sz, f) != static_cast<size_t>(sz)) {
    std::fclose(f);
    Diag(false, "read error");
    return 1;
  }
  std::fclose(f);

  if (data.size() < sizeof(proto::TraceHeader)) {
    Diag(false, "file too small for header");
    return 1;
  }
  proto::TraceHeader h;
  std::memcpy(&h, data.data(), sizeof(h));
  Diag(h.title_id != 0, "title_id = 0x%08X", h.title_id);
  Diag(h.version == proto::kTraceFormatVersion, "format version %u (expected %u)",
       h.version, proto::kTraceFormatVersion);
  std::printf("      build commit: %.40s\n", h.build_commit_sha);

  Counts c;
  const uint8_t* begin = data.data() + sizeof(h);
  const uint8_t* end = data.data() + data.size();
  const uint8_t* p = begin;
  std::vector<uint8_t> scratch;

  while (p < end) {
    if (end - p < 4) {
      Diag(false, "%zu trailing bytes after last command", size_t(end - p));
      break;
    }
    uint64_t consumed = 0;
    char mnemonic[64] = {0};
    const char* err = ParseCommand(p, end, consumed, c, scratch, mnemonic);
    if (err) {
      Diag(false, "parse error at offset 0x%zX: %s", size_t(p - data.data()), err);
      break;
    }
    if (consumed == 0) {
      Diag(false, "consumed 0 bytes at offset 0x%zX", size_t(p - data.data()));
      break;
    }
    (void)mnemonic;
    p += consumed;
    c.totalBytes += consumed;
  }

  std::printf("\n== Command counts\n");
  std::printf("  primary buffer start/end : %llu / %llu\n",
              (unsigned long long)c.primaryStart, (unsigned long long)c.primaryEnd);
  std::printf("  indirect buffer start/end: %llu / %llu\n",
              (unsigned long long)c.indirectStart, (unsigned long long)c.indirectEnd);
  std::printf("  packets start/end        : %llu / %llu (%llu dwords body)\n",
              (unsigned long long)c.packetStart, (unsigned long long)c.packetEnd,
              (unsigned long long)c.packetDwords);
  std::printf("  primary body dwords      : %llu\n", (unsigned long long)c.primaryDwords);
  std::printf("  memory reads/writes      : %llu / %llu (reads decode %llu bytes)\n",
              (unsigned long long)c.memRead, (unsigned long long)c.memWrite,
              (unsigned long long)c.memReadBytes);
  std::printf("  register groups          : %llu\n", (unsigned long long)c.registers);
  std::printf("  edram snapshots          : %llu\n", (unsigned long long)c.edram);
  std::printf("  events                   : %llu\n", (unsigned long long)c.event);
  std::printf("  gamma ramps              : %llu\n", (unsigned long long)c.gamma);
  std::printf("  total parsed bytes       : %llu\n", (unsigned long long)c.totalBytes);

  if (g_dump_mem) {
    std::printf("\n== Memory read/write commands\n");
    std::map<uint32_t, int> sizeHist;
    for (auto& m : c.memOps) sizeHist[m.decLen]++;
    for (auto& [sz, n] : sizeHist)
      std::printf("  decLen %8u x%-6d\n", sz, n);
    std::printf("  -- unique bases: ");
    std::set<uint32_t> bases;
    for (auto& m : c.memOps) bases.insert(m.base);
    int n = 0;
    for (auto b : bases) {
      if (n && n % 6 == 0) std::printf("\n                      ");
      std::printf("0x%08X ", b);
      n++;
    }
    std::printf("\n");

    // Decode and hex-show the small reads (not the framebuffer/page blobs).
    int shown = 0;
    for (auto& m : c.memOps) {
      if (m.isWrite || m.decLen >= 4096) continue;
      if (shown >= 8) break;
      std::vector<uint8_t> dec;
      bool ok = false;
      if (static_cast<proto::MEnc>(m.enc) == proto::MEnc::kNone) {
        dec.assign(m.payloadPtr, m.payloadPtr + m.encLen);
        ok = true;
      } else {
        ok = SnappyUncompress(m.payloadPtr, m.encLen, dec);
      }
      std::printf("  read base=0x%08X enc=%s decLen=%u%s\n", m.base,
                  MemEncName(m.enc), m.decLen, ok ? "" : " [decode failed]");
      if (ok) {
        uint32_t lim = dec.size() < 32 ? (uint32_t)dec.size() : 32;
        std::printf("    ");
        for (uint32_t i = 0; i < lim; ++i) std::printf("%02X ", dec[i]);
        std::printf("\n");
      }
      shown++;
    }
  }

  std::printf("\n== Register writes observed\n");
  if (c.regWrites.empty()) {
    std::printf("  (none)\n");
  } else {
    int shown = 0;
    for (auto& [reg, n] : c.regWrites) {
      // Only print registers that hold live (nonzero) values or carry a name;
      // sparse zeros add no evidence.
      auto it = c.regValues.find(reg);
      uint32_t v = (it != c.regValues.end()) ? it->second : 0;
      if (v == 0 && !RegName(reg)) continue;
      const char* rn = RegName(reg);
      std::printf("  0x%04X  %-28s = 0x%08X  (%llu write)\n", reg,
                  rn ? rn : "", v, (unsigned long long)n);
      if (++shown >= 60) break;
    }
    if (shown == 0) std::printf("  (only zeroed registers captured)\n");
  }

  bool clean = (g_errors == 0);
  std::printf("\nRESULT: %s\n", clean ? "CLEAN — parsed full stream" : "errors present");
  return clean ? 0 : 1;
}

// Self-test: synthesize a small .xtr with header + a few known commands and
// ensure the parser reads them back.
static int RunSelfTest() {
  std::printf("== Self-test: synthetic .xtr\n");
  std::vector<uint8_t> buf;
  proto::TraceHeader h{};
  h.version = proto::kTraceFormatVersion;
  std::memcpy(h.build_commit_sha, "0123456789abcdef0123456789abcdef01234567", 40);
  h.title_id = 0x4D5309AA;
  buf.insert(buf.end(), (uint8_t*)&h, (uint8_t*)&h + sizeof(h));

  auto pushu32 = [&](uint32_t v) {
    const uint8_t* q = (const uint8_t*)&v;
    buf.insert(buf.end(), q, q + 4);
  };
  // primary buffer start with count=5: header(12) + 5 inline body dwords,
  // then the matching end. The parser validates the inline body length against
  // count, so the fixture must actually carry the 5 dwords it advertises.
  pushu32((uint32_t)proto::TC::kPrimaryBufferStart); pushu32(0x1000); pushu32(5);
  pushu32(0x00000001); pushu32(0x00000002); pushu32(0x00000003);
  pushu32(0x00000004); pushu32(0x00000005);
  pushu32((uint32_t)proto::TC::kPrimaryBufferEnd);
  // registers: first=0x21FC, count=2, enc none, 2 regs
  pushu32((uint32_t)proto::TC::kRegisters);
  pushu32(0x21FC); pushu32(2); pushu32(0); pushu32((uint32_t)proto::MEnc::kNone); pushu32(8);
  pushu32(0x0000000A); pushu32(0x00FF0000);
  // memory read of 4 bytes, uncompressed
  pushu32((uint32_t)proto::TC::kMemoryRead);
  pushu32(0x80001000); pushu32((uint32_t)proto::MEnc::kNone); pushu32(4); pushu32(4);
  pushu32(0x89ABCDEF);
  pushu32((uint32_t)proto::TC::kEvent); pushu32(1);

  // Write temp file and analyze.
  const char* tmp = "xtr_selftest.tmp";
  FILE* f = std::fopen(tmp, "wb");
  if (!f) return 1;
  fwrite(buf.data(), 1, buf.size(), f);
  fclose(f);
  int rc = AnalyzeFile(tmp);
  std::remove(tmp);
  std::printf("  self-test %s\n", rc == 0 ? "PASSED" : "FAILED");
  return rc;
}

int main(int argc, char** argv) {
  std::printf("MCLA Xenia .xtr dump validator\n");
  if (argc < 2) return RunSelfTest();

  std::vector<std::string> args;
  for (int i = 1; i < argc; ++i) args.push_back(argv[i]);
  std::string path;
  for (auto& a : args) {
    if (a == "--verbose") g_verbose = 1;
    else if (a == "--hex") g_hex = 1;
    else if (a == "--dump-mem") g_dump_mem = 1;
    else path = a;
  }
  if (path.empty()) return RunSelfTest();
  return AnalyzeFile(path.c_str());
}