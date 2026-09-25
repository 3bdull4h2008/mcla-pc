// Host-side Xbox-360 XMem / raw-MS-LZX decoder for the RSC5 UI .xsf containers.
//
// Faithful C++ port of .research/360tools/tools/lzx_decompress.py, validated
// byte-exact offline against build/xmem_golden/{raceeditor,garage,policecam,
// credits}.bin via tools/xmem_decode.py. This is Path A (host decode); it does
// NOT touch guest decoder state, so it is free of the guest-inflate context
// conflict that closed Path B full-apply (F-288/F-290/F-293).
//
// Format (see docs/ROOT_CAUSE_VALIDATION.md F-295):
//   RSC5: +0 0x05435352, +12 0x0FF512EF (XComp), +16 uncLen (BE). window_bits=17.
//   "single": raw LZX at pkg+0x16 as one continuous stream (raceeditor/policecam/credits).
//   "walk"  : per-frame u16-BE length headers from pkg+0x14, shared decoder state (garage).
//
// Header-only by design so the standalone offline test and gpu_device.cpp can
// both include it with no build-system churn.
#ifndef MCLA_XMEM_LZX_H_
#define MCLA_XMEM_LZX_H_

#include <cstdint>
#include <cstring>
#include <vector>

namespace mcla_lzx {

constexpr int kNumChars = 256;
constexpr int kMinMatch = 2;
constexpr int kNumPrimaryLengths = 7;
constexpr int kSecondaryNumElements = 249;

constexpr int kPretreeNum = 20;
constexpr int kPretreeTableBits = 6;
constexpr int kPretreeMaxSymbols = 20;
constexpr int kPretreeMaxCodeword = 16;

constexpr int kMaintreeTableBits = 11;
constexpr int kMaintreeMaxSymbols = kNumChars + (51 << 3);
constexpr int kMaintreeMaxCodeword = 16;

constexpr int kLentreeTableBits = 10;
constexpr int kLentreeMaxSymbols = kSecondaryNumElements;
constexpr int kLentreeMaxCodeword = 16;

constexpr int kAligntreeTableBits = 7;
constexpr int kAligntreeMaxSymbols = 8;
constexpr int kAligntreeMaxCodeword = 8;

constexpr int kLenTableSafety = 64;

constexpr int kBlocktypeVerbatim = 1;
constexpr int kBlocktypeAligned = 2;
constexpr int kBlocktypeUncompressed = 3;

constexpr uint32_t kRsc5Magic = 0x05435352u;
constexpr uint32_t kXCompMagic = 0x0FF512EFu;

inline int num_position_slots(int window_bits) {
  switch (window_bits) {
    case 15: return 30;
    case 16: return 32;
    case 17: return 34;
    case 18: return 36;
    case 19: return 38;
    case 20: return 42;
    case 21: return 50;
    default: return -1;
  }
}

constexpr int kPositionBase[52] = {
    0,     1,     2,     3,     4,     6,     8,     12,    16,    24,
    32,    48,    64,    96,    128,   192,   256,   384,   512,   768,
    1024,  1536,  2048,  3072,  4096,  6144,  8192,  12288, 16384, 24576,
    32768, 49152, 65536, 98304, 131072, 196608, 262144, 393216, 524288, 655360,
    786432, 917504, 1048576, 1179648, 1310720, 1441792, 1572864, 1703936,
    1835008, 1966080, 2097152};

constexpr int kExtraBits[52] = {
    0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
    7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14,
    15, 15, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17};

// --- Bit reader: 16-bit little-endian words consumed MSB-first. -------------
// Mirrors _BitBuffer. bits_left always tracks the number of valid low bits held
// in `buf` (buf never exceeds ~33 bits, so a plain uint64 is safe).
struct BitBuf {
  const uint8_t* data = nullptr;
  size_t len = 0;
  size_t pos = 0;
  uint64_t buf = 0;
  int bits_left = 0;

  void set(const uint8_t* d, size_t n) {
    data = d;
    len = n;
    pos = 0;
  }
  void reset() {
    buf = 0;
    bits_left = 0;
  }
  void ensure_bits(int n) {
    while (bits_left < n) {
      uint32_t word = 0;
      if (pos + 1 < len) {
        uint32_t lo = data[pos], hi = data[pos + 1];
        word = (hi << 8) | lo;
        pos += 2;
      } else if (pos < len) {
        word = data[pos];
        pos += 1;
      }
      buf = (buf << 16) | word;
      bits_left += 16;
    }
  }
  uint32_t peek_bits(int n) {
    return (uint32_t)((buf >> (bits_left - n)) & ((((uint64_t)1) << n) - 1));
  }
  void remove_bits(int n) {
    bits_left -= n;
    if (bits_left <= 0) {
      bits_left = 0;
      buf = 0;
    } else {
      buf &= ((((uint64_t)1) << bits_left) - 1);
    }
  }
  uint32_t read_bits(int n) {
    if (n == 0) return 0;
    ensure_bits(n);
    uint32_t v = peek_bits(n);
    remove_bits(n);
    return v;
  }
};

// --- Huffman decode table builder (mirrors _make_decode_table). -------------
inline bool make_decode_table(int nsyms, int nbits, const int* length,
                              int* table) {
  int pos = 0;
  int table_mask = 1 << nbits;
  int bit_mask = table_mask >> 1;
  int next_symbol = bit_mask;

  for (int bit_num = 1; bit_num <= nbits; bit_num++) {
    for (int sym = 0; sym < nsyms; sym++) {
      if (length[sym] == bit_num) {
        int leaf = pos;
        pos += bit_mask;
        if (pos > table_mask) return false;
        for (int k = 0; k < bit_mask; k++) table[leaf + k] = sym;
      }
    }
    bit_mask >>= 1;
  }
  if (pos == table_mask) return true;

  for (int i = pos; i < table_mask; i++) table[i] = 0;

  pos <<= 16;
  table_mask <<= 16;
  bit_mask = 1 << 15;

  for (int bit_num = nbits + 1; bit_num <= 17; bit_num++) {
    for (int sym = 0; sym < nsyms; sym++) {
      if (length[sym] == bit_num) {
        int leaf = pos >> 16;
        for (int j = 0; j < bit_num - nbits; j++) {
          if (table[leaf] == 0) {
            table[next_symbol << 1] = 0;
            table[(next_symbol << 1) + 1] = 0;
            table[leaf] = next_symbol;
            next_symbol++;
          }
          leaf = table[leaf] << 1;
          if (((pos >> (15 - j)) & 1) == 1) leaf++;
        }
        table[leaf] = sym;
        pos += bit_mask;
        if (pos > table_mask) return false;
      }
    }
    bit_mask >>= 1;
  }
  if (pos == table_mask) return true;

  for (int sym = 0; sym < nsyms; sym++)
    if (length[sym] != 0) return false;
  return true;
}

inline int read_huff_sym(const int* table, const int* lengths, int nsyms,
                         int nbits, BitBuf& bb, int max_codeword) {
  bb.ensure_bits(max_codeword);
  int i = table[bb.peek_bits(nbits)];
  if (i >= nsyms) {
    int bit_pos = bb.bits_left - nbits - 1;
    for (;;) {
      i <<= 1;
      if (bit_pos < 0) return 0;
      if ((bb.buf >> bit_pos) & 1) i |= 1;
      bit_pos--;
      i = table[i];
      if (i < nsyms) break;
    }
  }
  bb.remove_bits(lengths[i]);
  return i;
}

// --- Decoder (mirrors LZXDecoder; persistent state across decompress() calls
//     gives the shared-window "walk" semantics; fresh instance = "single"). ---
class Decoder {
 public:
  explicit Decoder(int window_bits)
      : window_bits_(window_bits),
        window_size_(1 << window_bits),
        num_pos_slots_(num_position_slots(window_bits)),
        main_elements_(kNumChars + (num_pos_slots_ << 3)) {
    window_.assign(window_size_, 0xDC);
    pretree_table_.assign((1 << kPretreeTableBits) + (kPretreeMaxSymbols << 1), 0);
    maintree_table_.assign((1 << kMaintreeTableBits) + (kMaintreeMaxSymbols << 1), 0);
    lentree_table_.assign((1 << kLentreeTableBits) + (kLentreeMaxSymbols << 1), 0);
    aligntree_table_.assign((1 << kAligntreeTableBits) + (kAligntreeMaxSymbols << 1), 0);
    pretree_len_.assign(kPretreeMaxSymbols + kLenTableSafety, 0);
    maintree_len_.assign(kMaintreeMaxSymbols + kLenTableSafety, 0);
    lentree_len_.assign(kLentreeMaxSymbols + kLenTableSafety, 0);
    aligntree_len_.assign(kAligntreeMaxSymbols + kLenTableSafety, 0);
  }

  // Decode one call from `src` (a raw LZX bitstream or one frame payload),
  // producing exactly `output_size` bytes appended into `out`. Shared state on
  // window_/R0-2/block_remaining_/header_read_ persists across calls.
  bool decompress(const uint8_t* src, size_t src_len, uint32_t output_size,
                  std::vector<uint8_t>& out) {
    BitBuf bb;
    bb.set(src, src_len);
    size_t out_pos = out.size();
    out.resize(out_pos + output_size);
    uint8_t* output = out.data() + out_pos;

    int frame_size = window_size_;
    int window_mask = window_size_ - 1;
    int window_posn = window_pos_;
    int frame_posn = 0;

    if (!header_read_) {
      uint32_t intel_e8 = bb.read_bits(1);
      if (intel_e8) {
        uint32_t hi16 = bb.read_bits(16);
        uint32_t lo16 = bb.read_bits(16);
        intel_filesize_ = (hi16 << 16) | lo16;
      }
      intel_started_ = false;
      header_read_ = true;
    }

    int written = 0;
    while (written < (int)output_size) {
      int cur_frame_size = frame_size;
      if (cur_frame_size > (int)output_size - written)
        cur_frame_size = (int)output_size - written;

      int bytes_todo = frame_posn + cur_frame_size - window_posn;
      if (bytes_todo < 0) bytes_todo = 0;

      while (bytes_todo > 0) {
        if (block_remaining_ == 0) {
          if (!read_block_header(bb)) return false;
        }
        int this_run = block_remaining_;
        if (this_run > bytes_todo) this_run = bytes_todo;
        bytes_todo -= this_run;
        block_remaining_ -= this_run;
        if (this_run <= 0) continue;

        if (block_type_ == kBlocktypeUncompressed) {
          for (int i = 0; i < this_run; i++) {
            uint8_t b = bb.pos < bb.len ? bb.data[bb.pos] : 0;
            bb.pos += 1;
            window_[window_posn & window_mask] = b;
            window_posn += 1;
          }
        } else {
          while (this_run > 0) {
            int main_element = read_huff_sym(maintree_table_.data(),
                                             maintree_len_.data(),
                                             kMaintreeMaxSymbols,
                                             kMaintreeTableBits, bb,
                                             kMaintreeMaxCodeword);
            if (main_element < kNumChars) {
              window_[window_posn & window_mask] = (uint8_t)main_element;
              window_posn += 1;
              this_run -= 1;
              continue;
            }
            main_element -= kNumChars;
            int match_length = main_element & kNumPrimaryLengths;
            if (match_length == kNumPrimaryLengths) {
              int lf = read_huff_sym(lentree_table_.data(), lentree_len_.data(),
                                     kLentreeMaxSymbols, kLentreeTableBits, bb,
                                     kLentreeMaxCodeword);
              match_length += lf;
            }
            match_length += kMinMatch;
            int match_offset = main_element >> 3;
            if (match_offset > 2) {
              int extra = kExtraBits[match_offset];
              int verbatim_bits, aligned_bits;
              if (block_type_ == kBlocktypeAligned && extra >= 3) {
                verbatim_bits = (int)bb.read_bits(extra - 3);
                verbatim_bits <<= 3;
                aligned_bits = read_huff_sym(aligntree_table_.data(),
                                             aligntree_len_.data(),
                                             kAligntreeMaxSymbols,
                                             kAligntreeTableBits, bb,
                                             kAligntreeMaxCodeword);
              } else {
                verbatim_bits = (int)bb.read_bits(extra);
                aligned_bits = 0;
              }
              match_offset = kPositionBase[match_offset] + verbatim_bits +
                             aligned_bits - 2;
              R2_ = R1_;
              R1_ = R0_;
              R0_ = match_offset;
            } else if (match_offset == 0) {
              match_offset = R0_;
            } else if (match_offset == 1) {
              match_offset = R1_;
              R1_ = R0_;
              R0_ = match_offset;
            } else {
              match_offset = R2_;
              R2_ = R0_;
              R0_ = match_offset;
            }
            this_run -= match_length;
            int runsrc = (window_posn - match_offset) & window_mask;
            for (int k = 0; k < match_length; k++) {
              window_[window_posn & window_mask] = window_[runsrc];
              window_posn += 1;
              runsrc = (runsrc + 1) & window_mask;
            }
          }
          if (this_run < 0) block_remaining_ -= -this_run;
        }
      }

      // Re-align bit buffer to the next 16-bit word at the frame boundary.
      if (bb.bits_left > 0) bb.ensure_bits(16);
      if (bb.bits_left & 15) bb.remove_bits(bb.bits_left & 15);

      int wp = frame_posn & window_mask;
      for (int k = 0; k < cur_frame_size; k++) {
        output[written++] = window_[wp];
        wp = (wp + 1) & window_mask;
      }
      frame_posn += cur_frame_size;
    }

    window_pos_ = window_posn & window_mask;

    if (intel_started_ && output_size > 10) {
      e8_decode(output, output_size);
    }
    intel_curpos_ += output_size;
    return true;
  }

 private:
  void read_lengths(int* lens, int first, int last, BitBuf& bb) {
    for (int i = 0; i < kPretreeNum; i++)
      pretree_len_[i] = (int)bb.read_bits(4);
    make_decode_table(kPretreeMaxSymbols, kPretreeTableBits,
                      pretree_len_.data(), pretree_table_.data());
    int x = first;
    while (x < last) {
      int z = read_huff_sym(pretree_table_.data(), pretree_len_.data(),
                            kPretreeMaxSymbols, kPretreeTableBits, bb,
                            kPretreeMaxCodeword);
      if (z == 17) {
        int y = (int)bb.read_bits(4) + 4;
        for (int k = 0; k < y; k++) lens[x++] = 0;
      } else if (z == 18) {
        int y = (int)bb.read_bits(5) + 20;
        for (int k = 0; k < y; k++) lens[x++] = 0;
      } else if (z == 19) {
        int y = (int)bb.read_bits(1) + 4;
        z = read_huff_sym(pretree_table_.data(), pretree_len_.data(),
                          kPretreeMaxSymbols, kPretreeTableBits, bb,
                          kPretreeMaxCodeword);
        z = (lens[x] + 17 - z) % 17;
        for (int k = 0; k < y; k++) lens[x++] = z;
      } else {
        z = (lens[x] + 17 - z) % 17;
        lens[x++] = z;
      }
    }
  }

  bool read_block_header(BitBuf& bb) {
    if (block_type_ == kBlocktypeUncompressed) {
      if ((block_length_ & 1) == 1) bb.pos += 1;
      bb.reset();
    }
    block_type_ = (int)bb.read_bits(3);
    block_length_ = (int)bb.read_bits(24);
    block_remaining_ = block_length_;

    if (block_type_ == kBlocktypeAligned) {
      for (int i = 0; i < 8; i++) aligntree_len_[i] = (int)bb.read_bits(3);
      make_decode_table(kAligntreeMaxSymbols, kAligntreeTableBits,
                        aligntree_len_.data(), aligntree_table_.data());
    }
    if (block_type_ == kBlocktypeVerbatim || block_type_ == kBlocktypeAligned) {
      read_lengths(maintree_len_.data(), 0, kNumChars, bb);
      read_lengths(maintree_len_.data(), kNumChars, main_elements_, bb);
      make_decode_table(kMaintreeMaxSymbols, kMaintreeTableBits,
                        maintree_len_.data(), maintree_table_.data());
      if (maintree_len_[0xE8] != 0) intel_started_ = true;
      read_lengths(lentree_len_.data(), 0, kSecondaryNumElements, bb);
      make_decode_table(kLentreeMaxSymbols, kLentreeTableBits,
                        lentree_len_.data(), lentree_table_.data());
    } else if (block_type_ == kBlocktypeUncompressed) {
      intel_started_ = true;
      bb.ensure_bits(16);
      if (bb.bits_left > 16) bb.pos -= 2;
      bb.reset();
      if (bb.pos + 12 <= bb.len) {
        auto rd32 = [&](size_t p) -> uint32_t {
          return (uint32_t)bb.data[p] | ((uint32_t)bb.data[p + 1] << 8) |
                 ((uint32_t)bb.data[p + 2] << 16) | ((uint32_t)bb.data[p + 3] << 24);
        };
        R0_ = (int)rd32(bb.pos);
        bb.pos += 4;
        R1_ = (int)rd32(bb.pos);
        bb.pos += 4;
        R2_ = (int)rd32(bb.pos);
        bb.pos += 4;
      }
    } else {
      return false;  // invalid block type
    }
    return true;
  }

  void e8_decode(uint8_t* data, uint32_t size) {
    if (intel_curpos_ >= 0x40000000) return;
    uint32_t i = 0;
    while (i + 10 < size) {
      if (data[i] != 0xE8) {
        i += 1;
        continue;
      }
      uint32_t curpos = intel_curpos_ + i;
      int64_t abs_off = (int64_t)(data[i + 1] | (data[i + 2] << 8) |
                                  (data[i + 3] << 16) |
                                  ((uint32_t)data[i + 4] << 24));
      if (abs_off & 0x80000000LL) abs_off -= 0x100000000LL;
      if (abs_off >= -(int64_t)curpos && abs_off < (int64_t)intel_filesize_) {
        uint32_t rel_off;
        if (abs_off >= 0)
          rel_off = (uint32_t)(abs_off - (int64_t)curpos);
        else
          rel_off = (uint32_t)(abs_off + (int64_t)intel_filesize_);
        data[i + 1] = rel_off & 0xFF;
        data[i + 2] = (rel_off >> 8) & 0xFF;
        data[i + 3] = (rel_off >> 16) & 0xFF;
        data[i + 4] = (rel_off >> 24) & 0xFF;
      }
      i += 5;
    }
  }

  int window_bits_;
  int window_size_;
  int num_pos_slots_;
  int main_elements_;
  std::vector<uint8_t> window_;
  int window_pos_ = 0;
  int R0_ = 1, R1_ = 1, R2_ = 1;

  std::vector<int> pretree_table_, maintree_table_, lentree_table_,
      aligntree_table_;
  std::vector<int> pretree_len_, maintree_len_, lentree_len_, aligntree_len_;

  int block_remaining_ = 0;
  int block_length_ = 0;
  int block_type_ = 0;

  bool header_read_ = false;
  uint32_t intel_filesize_ = 0;
  uint32_t intel_curpos_ = 0;
  bool intel_started_ = false;
};

// --- Two-path UI .xsf driver. On success `out` holds exactly uncLen bytes with
//     head "DIU\0" and returns the path used ("single"/"walk") in path_out. ---
inline int host_decode_ui_xsf(const uint8_t* pkg, size_t pkg_len,
                              std::vector<uint8_t>& out, int window_bits = 17) {
  if (pkg_len < 24) return 0;
  auto be32 = [&](size_t i) -> uint32_t {
    return ((uint32_t)pkg[i] << 24) | ((uint32_t)pkg[i + 1] << 16) |
           ((uint32_t)pkg[i + 2] << 8) | (uint32_t)pkg[i + 3];
  };
  if (be32(0) != kRsc5Magic || be32(12) != kXCompMagic) return 0;
  uint32_t unc = be32(16);
  if (unc == 0) return 0;

  auto is_diu = [&](const std::vector<uint8_t>& v) {
    return v.size() == unc && v[0] == 0x44 && v[1] == 0x49 && v[2] == 0x55 &&
           v[3] == 0x00;
  };

  // Path "single": one continuous stream at pkg+0x16.
  {
    Decoder d(window_bits);
    std::vector<uint8_t> o;
    if (pkg_len > 0x16 &&
        d.decompress(pkg + 0x16, pkg_len - 0x16, unc, o) && is_diu(o)) {
      out.swap(o);
      return 1;  // single
    }
  }
  // Path "walk": per-frame shared state from pkg+0x14.
  {
    Decoder d(window_bits);
    std::vector<uint8_t> o;
    size_t src = 20;
    uint32_t acc = 0;
    while (src + 2 <= pkg_len && acc < unc) {
      uint8_t b0 = pkg[src];
      int hdr, uncomp, pay;
      if (b0 == 0xFF) {
        if (src + 5 > pkg_len) break;
        hdr = 5;
        uncomp = (pkg[src + 1] << 8) | pkg[src + 2];
        pay = (pkg[src + 3] << 8) | pkg[src + 4];
      } else {
        hdr = 2;
        uncomp = 0x8000;
        pay = (b0 << 8) | pkg[src + 1];
      }
      if (pay == 0 || src + hdr + (size_t)pay > pkg_len) break;
      int want = uncomp < (int)(unc - acc) ? uncomp : (int)(unc - acc);
      if (!d.decompress(pkg + src + hdr, (size_t)pay, (uint32_t)want, o)) break;
      acc += (uint32_t)want;
      src += hdr + (size_t)pay;
      if (acc >= unc) break;
    }
    if (is_diu(o)) {
      out.swap(o);
      return 2;  // walk
    }
  }
  return 0;
}

}  // namespace mcla_lzx

#endif  // MCLA_XMEM_LZX_H_
