// Minimal RFC 1951 raw-DEFLATE inflater (no zlib in this tree; zstd's
// zlibWrapper needs zlib itself). Used by the archive serve path because the
// `preload.list` / `*.list` members of xarchive_cache.rpf are headerless,
// trailerless DEFLATE streams (F-105: verified with Python zlib wbits=-15 on
// all six members, eof=True and unused_data empty).
//
// Deliberately small: fixed + dynamic + stored blocks, canonical Huffman built
// the RFC way, no dictionaries, no Adler check (raw streams carry none).
#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

namespace mcla {

inline bool RawInflate(const uint8_t *in, size_t inLen,
                       std::vector<uint8_t> &out, size_t maxOut = 1u << 20) {
  struct Bits {
    const uint8_t *p;
    size_t left;
    uint32_t acc = 0;
    int n = 0;
    bool ok = true;
    uint32_t read(int need) {
      while (n < need) {
        if (left == 0) {
          ok = false;
          return 0;
        }
        acc |= static_cast<uint32_t>(*p++) << n;
        n += 8;
        --left;
      }
      const uint32_t v = acc & ((need == 32) ? 0xFFFFFFFFu : ((1u << need) - 1u));
      acc >>= need;
      n -= need;
      return v;
    }
    void alignByte() { acc = 0; n = 0; }
  } br{in, inLen};

  // Canonical Huffman decoder built from code lengths (RFC 1951 3.2.7).
  struct Huff {
    uint16_t counts[16] = {0};
    uint16_t symbols[288] = {0};
    int maxLen = 0;
    bool build(const uint8_t *lens, int n) {
      for (int i = 0; i < n; ++i) ++counts[lens[i]];
      if (counts[0] == n) return true;  // no codes of this kind
      uint16_t offs[16] = {0};
      for (int len = 1; len < 15; ++len) offs[len + 1] = offs[len] + counts[len];
      for (int i = 0; i < n; ++i)
        if (lens[i]) symbols[offs[lens[i]]++] = static_cast<uint16_t>(i);
      for (int len = 0; len < 16; ++len)
        if (counts[len] > 0 && len > maxLen) maxLen = len;
      return true;
    }
    int decode(Bits &b) const {
      int code = 0, first = 0, index = 0;
      for (int len = 1; len <= maxLen; ++len) {
        code |= static_cast<int>(b.read(1));
        const int count = counts[len];
        if (code - first < count) return symbols[index + (code - first)];
        index += count;
        first = (first + count) << 1;
        code <<= 1;
      }
      b.ok = false;
      return -1;
    }
  };

  static const uint16_t kLenBase[29] = {3,  4,  5,  6,  7,  8,  9,  10,  11,  13,
                                        15, 17, 19, 23, 27, 31, 35, 43,   51, 59,
                                        67, 83, 99, 115, 131, 163, 195, 227, 258};
  static const uint8_t kLenExtra[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2,
                                        2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
  static const uint16_t kDistBase[30] = {
      1,    2,    3,    4,    5,    7,     9,     13,    17,    25,
      33,   49,   65,   97,   129,  193,   257,   385,   513,   769,
      1025, 1537, 2049, 3073, 4097, 6145,  8193,  12289, 16385, 24577};
  static const uint8_t kDistExtra[30] = {0, 0, 0,  0,  1,  1,  2,  2,  3,  3,
                                        4, 4, 5,  5,  6,  6,  7,  7,  8,  8,
                                        9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

  for (;;) {
    const uint32_t last = br.read(1);
    const uint32_t type = br.read(2);
    if (!br.ok) return false;
    if (type == 0) {  // stored
      br.alignByte();
      if (br.left < 4) return false;
      const uint32_t len = static_cast<uint32_t>(br.p[0]) |
                           (static_cast<uint32_t>(br.p[1]) << 8);
      br.p += 4;
      br.left -= 4;
      if (len > br.left || out.size() + len > maxOut) return false;
      out.insert(out.end(), br.p, br.p + len);
      br.p += len;
      br.left -= len;
    } else if (type == 1 || type == 2) {
      Huff lit, dist;
      uint8_t lens[288] = {0};
      uint8_t dlens[30] = {0};
      if (type == 1) {
        for (int i = 0; i < 144; ++i) lens[i] = 8;
        for (int i = 144; i < 256; ++i) lens[i] = 9;
        for (int i = 256; i < 280; ++i) lens[i] = 7;
        for (int i = 280; i < 288; ++i) lens[i] = 8;
        for (int i = 0; i < 30; ++i) dlens[i] = 5;
      } else {
        static const uint8_t kOrder[19] = {16, 17, 18, 0, 8,  7, 9,  6, 10, 5,
                                           11, 4,  12, 3, 13, 2, 14, 1, 15};
        const int hlit = static_cast<int>(br.read(5)) + 257;
        const int hdist = static_cast<int>(br.read(5)) + 1;
        const int hclen = static_cast<int>(br.read(4)) + 4;
        if (!br.ok || hlit > 288 || hdist > 30) return false;
        uint8_t clens[19] = {0};
        for (int i = 0; i < hclen; ++i) clens[kOrder[i]] = static_cast<uint8_t>(br.read(3));
        Huff codeLen;
        if (!codeLen.build(clens, 19)) return false;
        int i = 0;
        while (i < hlit + hdist) {
          const int sym = codeLen.decode(br);
          if (sym < 0) return false;
          int value;
          if (sym < 16) {
            value = sym;
          } else if (sym == 16) {
            if (i == 0) return false;
            const int prev = (i < hlit) ? lens[i - 1] : dlens[i - hlit - 1];
            value = prev;
            int rep = 3 + static_cast<int>(br.read(2));
            while (rep-- && i < hlit + hdist) {
              if (i < hlit) lens[i] = static_cast<uint8_t>(value);
              else dlens[i - hlit] = static_cast<uint8_t>(value);
              ++i;
            }
            continue;
          } else if (sym == 17) {
            value = 0;
            int rep = 3 + static_cast<int>(br.read(3));
            while (rep-- && i < hlit + hdist) {
              if (i < hlit) lens[i] = 0;
              else dlens[i - hlit] = 0;
              ++i;
            }
            continue;
          } else {
            value = 0;
            int rep = 11 + static_cast<int>(br.read(7));
            while (rep-- && i < hlit + hdist) {
              if (i < hlit) lens[i] = 0;
              else dlens[i - hlit] = 0;
              ++i;
            }
            continue;
          }
          if (i < hlit) lens[i] = static_cast<uint8_t>(value);
          else dlens[i - hlit] = static_cast<uint8_t>(value);
          ++i;
        }
      }
      if (!lit.build(lens, 288) || !dist.build(dlens, 30)) return false;
      for (;;) {
        const int sym = lit.decode(br);
        if (sym < 0) return false;
        if (sym < 256) {
          if (out.size() >= maxOut) return false;
          out.push_back(static_cast<uint8_t>(sym));
          continue;
        }
        if (sym == 256) break;
        const int li = sym - 257;
        if (li >= 29) return false;
        const uint32_t length =
            kLenBase[li] + (kLenExtra[li] ? br.read(kLenExtra[li]) : 0u);
        const int ds = dist.decode(br);
        if (ds < 0 || ds >= 30) return false;
        const uint32_t d =
            kDistBase[ds] + (kDistExtra[ds] ? br.read(kDistExtra[ds]) : 0u);
        if (d > out.size() || out.size() + length > maxOut) return false;
        for (uint32_t k = 0; k < length; ++k)
          out.push_back(out[out.size() - d]);
      }
    } else {
      return false;  // reserved block type
    }
    if (last) break;
  }
  return br.ok;
}

}  // namespace mcla
