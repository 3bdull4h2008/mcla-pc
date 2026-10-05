// Host implementations for missing VMX128 vpkd3d128 / vupkd3d128 modes
// (plan: docs/PLAN_VMX128.md).
// XenonRecomp midasm hooks call these by C++ reference, then jump over the
// __builtin_debugtrap() the recompiler would have emitted. The hook emission
// shape a regen produces (measured, generated/ppc_xenon/ppc_recomp.13.cpp:23363-23368):
//
//     // vpkd3d128 v63,v0,2,1,0
//     mcla_Vpkd3d128_type2(v63, ctx.v0);
//     goto loc_821B3818;
//     __builtin_debugtrap();
//  loc_821B3818:
//
// so a hook is nothing but an externally-linked free function with that exact
// signature plus the regen emitting the call. The debugtrap that survives the
// goto is dead code -- the unconditional `goto` skips it.
//
// VUPKD3D128 MODE NUMBERING (imm >> 2 == Xenia PackType index).
//   .research/XenonRecomp/XenonRecomp/recompiler.cpp:2341 `switch (insn.operands[2] >> 2)`
//   implements only case 0 (D3D color) and case 1 (2 shorts); the `default:` at
//   :2368 is the __builtin_debugtrap() we are replacing. Xenia's PackType enum
//   (.research/xenia/src/xenia/cpu/hir/opcodes.h) is indexed by that same
//   nibble: 0 D3DCOLOR, 1 FLOAT16_2, 2 SHORT_4, 3 FLOAT16_4, 4 SHORT_2,
//   5 UINT_2101010, 6 ULONG_4202020, 7 8_IN_16.
//   => imm 20 == type 5 == UINT_2101010 (NOT a 64-bit/doubleword unpack; that
//      description is wrong for Xenon -- the destination is a single 128-bit VR,
//      see the UNPACK signature at x64_seq_vector.cc:2483,
//      `Sequence<UNPACK, I<OPCODE_UNPACK, V128Op, V128Op>>`, two operands).
//   => imm  8 == type 2 == SHORT_4.
//   => imm  4 == type 1 == SHORT_2 (443 live sites, see mcla_Vupkd3d128_type1).
//
// HOST LANE ORDER. `PPCVRegister.u32[0]` is VR word 0 and `u32[3]` is VR word 3;
// Xenia's x64 backend uses the same order, which is why this file and Xenia agree
// lane-for-lane. The ordering is pinned by Xenia's own *architectural* test
// corpus (.research/xenia/src/xenia/cpu/ppc/testing/instr_vupkd3d128.s), whose
// `REGISTER_IN/OUT` lists are plain `[u32[0], u32[1], u32[2], u32[3]]` -- Xenia
// loads them that way, `string_util::from_string<vec128_t>` filling
// `v.u32[i]` in list order (.research/xenia/src/xenia/base/string_util.h:308-352,
// called from .research/xenia/src/xenia/cpu/ppc/ppc_context.cc:130-137) and prints
// them back in the same order (string_util.h:136-139, ppc_context.cc:177-179).
// CAUTION for anyone re-deriving this: tools/difftest/** loads the very same
// corpus lists MIRRORED (list[i] -> u32[3-i]), copied from XenonRecomp's
// test_recompiler.cpp:165-168 rather than from Xenia. That mirror cancels
// XenonRecomp's own lane reversal, so it reports a masked subject as correct;
// see the report for the four cases it hides. Do not "fix" a lane order here to
// agree with that harness. Check against instr_vupkd3d128.s and
// x64_seq_vector.cc, which agree with each other on all four unpack modes:
//   host u32[0] = bits  0- 9   host u32[2] = bits 20-29
//   host u32[1] = bits 10-19   host u32[3] = bits 30-31 (2-bit W/alpha)

#include "ppc_config.h"
// Angle include: self-dir src/cpu/ppc_context.h is the TLS holder, not the
// ABI header (moved to src/cpu/, quote include would shadow src/ppc_context.h).
#include <ppc_context.h>

#include "logging.h"

#include <atomic>
#include <cstdint>
#include <cstring>

namespace {

// Xenia XMMPackUINT_2101010_* (x64_emitter.cc:710-718) and XMM3331/XMM3333
// (x64_emitter.cc:670-671). Type-2 pack does NOT take raw [-1,1] floats --
// it clamps IEEE bits near 3.0 and ANDs the mantissa.
// XYZ: signed 10-bit in the low 10 bits of the float encoding of 3.0 + k*2^-22,
//      k in [-511, 511].
// W:   unsigned 2-bit in the float encoding of 1.0 + n*2^-23, n in [0, 3]
//      (x64_emitter.cc:670 `XMM3331 = vec128f(3.0f, 3.0f, 3.0f, 1.0f)`).
constexpr uint32_t kXyzMinBits = 0x403FFE01u;
constexpr uint32_t kXyzMaxBits = 0x404001FFu;
constexpr uint32_t kWMinBits   = 0x3F800000u;
constexpr uint32_t kWMaxBits   = 0x3F800003u;
// bits of 3.0f; XYZ lanes on both the pack and the unpack side.
constexpr uint32_t kBias3Plus = 0x40400000u;
// bits of 1.0f; W lane of the unpack (XMM3331, x64_emitter.cc:670).
constexpr uint32_t kBias1Plus = 0x3F800000u;
// XMMUnpackUINT_2101010_Overflow (x64_emitter.cc:719) == the encoding of field
// value -512, so that one lane becomes NaN.
constexpr uint32_t kUnpack2101010Overflow = 0x403FFE00u;
// XMMUnpackSHORT_Overflow (x64_emitter.cc:709) == the encoding of the
// sign-extended 16-bit field -32768.
constexpr uint32_t kUnpackShort4Overflow = 0x403F8000u;
// XMMQNaN (x64_emitter.cc:762).
constexpr uint32_t kQuietNaN = 0x7FC00000u;

inline float BitsToFloat(uint32_t bits) {
    float f;
    std::memcpy(&f, &bits, sizeof(f));
    return f;
}

inline uint32_t FloatToBits(float f) {
    uint32_t bits;
    std::memcpy(&bits, &f, sizeof(bits));
    return bits;
}

// 3.0f + k*2^-22, masked to the 10-bit two's-complement field. Same shape as
// Xenia's `vmaxps`/`vminps` against XMMPackUINT_2101010_MinUnpacked /
// _MaxUnpacked followed by `vpand _MaskUnpacked`
// (x64_seq_vector.cc:2242-2245, x64_emitter.cc:711-715).
inline uint32_t Extract10(float f) {
    float clamped = f;
    if (!(clamped >= BitsToFloat(kXyzMinBits)))
        clamped = BitsToFloat(kXyzMinBits);
    if (clamped > BitsToFloat(kXyzMaxBits))
        clamped = BitsToFloat(kXyzMaxBits);
    return FloatToBits(clamped) & 0x3FFu;
}

// 1.0f + n*2^-23, masked to the 2-bit W field. The bias is 1.0f, NOT 3.0f:
// that is what the unpack side of this same file (and Xenia, x64_emitter.cc:670)
// decodes, and these two functions are the two halves of one round trip. Xenia's
// *pack* reuses the 3.0f bounds in lane 3 (x64_emitter.cc:711 and :713 put
// 0x40400000 / 0x40400003 in the fourth lane), which is why Xenia's pack and its
// own unpack are not inverses of each other; the corpus agrees with the unpack,
// not with the pack -- see the testable statement below.
inline uint32_t Extract2(float f) {
    float clamped = f;
    if (!(clamped >= BitsToFloat(kWMinBits)))
        clamped = BitsToFloat(kWMinBits);
    if (clamped > BitsToFloat(kWMaxBits))
        clamped = BitsToFloat(kWMaxBits);
    return FloatToBits(clamped) & 0x3u;
}

// WHY kXyzMinBits IS 0x403FFE01 AND NOT 0x403FFE00. The 10-bit two's-complement
// field spans [-512, +511], and 0x403FFE00 is the encoding of -512 -- but -512 is
// a RESERVED value on the unpack side: Xenia's XMMUnpackUINT_2101010_Overflow
// (x64_emitter.cc:719) is exactly 0x403FFE00, and EmitUINT_2101010 replaces every
// lane that lands on it with XMMQNaN (x64_seq_vector.cc:2724-2726). Xenia's own
// architectural corpus pins the same split, from the two fields that bracket it:
//   instr_vupkd3d128.s:69-74  src u32[3]=0x40000201 (field -511) -> 0x403FFE01,
//                            a normal float
//   instr_vupkd3d128.s:75-80  src u32[3]=0x40000200 (field -512) -> 0x7FC00000,
//                            a quiet NaN
// So a clamp at 0x403FFE00 would let the pack emit a dword that this file's own
// mcla_Vupkd3d128_type5 turns into a NaN: a legitimate -512.0 input would come
// back NaN. Clamping at 0x403FFE01 keeps the two halves exactly inverse over the
// whole packed domain (every dword the unpack can produce, 0x403FFE01..0x404001FF
// and 0x3F800000..0x3F800003, re-packs to itself) at the cost of saturating the
// single input -512 to -511. Xenia's _MinUnpacked is the cited authority for the
// clamp; nothing in this tree supports 0x403FFE00 as the *pack* bound, and the
// corpus supports 0x403FFE00 only as the *unpack* sentinel. Consequence stated as
// a testable claim: pack then unpack of a float4 whose fields are all -512 yields
// 0x403FFE01 lanes, never a NaN; a NaN lane is unreachable through the pack path.

// ---- Unpack side (vupkd3d128) -----------------------------------------------
// Xenia's UINT_2101010 unpack does, per lane:
//   vpslld 22 ; vpsrad 22 ; vpaddd XMM3331 ; vcmpeqps <Overflow> ; vblendvps
//   XMMQNaN
// (x64_seq_vector.cc:2717-2726) -- i.e. the sign-extended integer field is added
// straight into the float's bit pattern, then one exact value is replaced by a
// quiet NaN. That is the same encoding the PACK above encodes, so the two
// directions share kBias3Plus.

// vpslld 16 / vpsrad 16 / vpaddd XMM3333 -- see EmitSHORT_4, x64_seq_vector.cc:2658-2686.
inline uint32_t UnpackShort4Lane(int32_t field) {
    const uint32_t bits = kBias3Plus + static_cast<uint32_t>(field);
    return bits == kUnpackShort4Overflow ? kQuietNaN : bits;
}

// vpslld 22 / vpsrad 22 / vpaddd XMM3331 -- see EmitUINT_2101010,
// x64_seq_vector.cc:2687-2729. `bias` is 3.0f's bits for the signed 10-bit lanes
// and 1.0f's bits for the unsigned 2-bit W lane.
inline uint32_t Unpack2101010Lane(int32_t field, uint32_t bias) {
    const uint32_t bits = bias + static_cast<uint32_t>(field);
    return bits == kUnpack2101010Overflow ? kQuietNaN : bits;
}

// Xenia has constant-source early-outs (x64_seq_vector.cc:2690 loads XMM3331,
// :2666 loads XMM3333 when src is constant zero). The general path already
// produces those for a zero source, since sext(0) == 0 adds no bits, so no
// special case is needed here and none is emulated.

// PACKED FIELD -> HOST LANE, and its inverse. Measured two independent ways and
// they agree, so this is the settled direction (see the HOST LANE ORDER header):
//   Xenia, x64_emitter.cc:716-718  MaskPacked = (0x3FF, 0x3FF<<10, 0x3FF<<20,
//                                    0x3<<30) and Shift = (0, 10, 20, 30) feed
//                                    vpsllvd in PACK (x64_seq_vector.cc:2248)
//                                    and vpsrlvd in UNPACK (:2706), so in both
//                                    directions host u32[k] owns bits 10k..
//   Xenia's corpus, instr_vupkd3d128.s:63-68: src u32[3] = 0x400001FF has
//                                    bits 0-9 = 0x1FF and the expected u32[0] is
//                                    0x404001FF = 3.0f + 511*2^-22; bits 30-31
//                                    = 1 and the expected u32[3] is 0x3F800001 =
//                                    1.0f + 2^-23.
// Therefore the inverse, i.e. what Pack2101010 must do: host f32[k] (VR word k)
// owns bits 10k..10k+9 for k in 0..2 and bits 30-31 for k = 3.
inline uint32_t Pack2101010(const PPCVRegister& src) {
    const uint32_t b = Extract10(src.f32[0]);
    const uint32_t g = Extract10(src.f32[1]);
    const uint32_t r = Extract10(src.f32[2]);
    const uint32_t a = Extract2(src.f32[3]);
    return (a << 30) | (r << 20) | (g << 10) | b;
}

std::atomic<uint32_t> g_vpkd3d128_type2_hits{0};
std::atomic<uint32_t> g_vupkd3d128_type5_hits{0};
std::atomic<uint32_t> g_vupkd3d128_type2_hits{0};
std::atomic<uint32_t> g_vupkd3d128_type1_hits{0};

}  // namespace

// vpkd3d128 VD,VB,TYPE=2,VPD=1,VSHIFT=0 -- the only pack type with live hooks:
// 4 sites, all `,2,1,0`, and all four are hooked
// (config/mcla_xenonrecomp.toml:42-67 -> 0x821B3814, 0x821B3C2C, 0x821B3E90,
// 0x821B4788; measured call sites ppc_recomp.13.cpp:23364, :23992, :24382 and
// ppc_recomp.13.cpp:25871). Census: `vpkd3d128` in generated/ppc_xenon/ breaks
// down as 62x D3DCOLOR (type 0), 4x type 2, 1x type 3, 67x float16_4 (type 5),
// 0x research/XenonRecomp type 2 elsewhere -- so these 4 are the whole type-2
// population.
//
// DESTINATION WORD = 3 - VSHIFT, so VSHIFT=0 writes u32[3] and NOT u32[0].
// The ISA rule is pinned by four independent corpus cases that differ only in
// VSHIFT, with VPD=1 so exactly one dword is written:
//   instr_vpkd3d128.s:55  shift 0 -> u32[3] = 0x04010203
//   instr_vpkd3d128.s:63  shift 1 -> u32[2]
//   instr_vpkd3d128.s:71  shift 2 -> u32[1]
//   instr_vpkd3d128.s:79  shift 3 -> u32[0]
// (corpus lists are [u32[0], u32[1], u32[2], u32[3]]; see the header.) Xenia's
// PACK ignores VSHIFT in its HIR and still lands the dword in u32[3]
// (x64_seq_vector.cc:2120, `XMMPackD3DCOLOR` puts the ARGB dword in dword 3),
// which agrees with the shift-0 case and is the only choice it has.
// XenonRecomp's inline translator writes `v(operands[0]).u32[operands[4]]`, i.e.
// u32[VSHIFT] (recompiler.cpp:2167) -- the VPD=1 cases only "pass" under the
// mirrored loader in tools/difftest, which is exactly why that bug is invisible
// there. VPD>=2 additionally zeroes word 2-VSHIFT (instr_vpkd3d128.s:88, :96,
// :104, :121, :129, :137); no live site has VPD>=2 for this type, and the three
// live D3DCOLOR sites that do (ppc_recomp.119.cpp:31241 `0,2,2`,
// ppc_recomp.119.cpp:53580 and ppc_recomp.7.cpp:7314 `0,3,0`) are XenonRecomp's
// inline path, not this file's -- reported, not fixed here.
//
// ONE D-WORD WRITE IS CORRECT AND LOAD-BEARING, proven at all 4 sites rather
// than assumed. Each is the same three-instruction shape; the first,
// generated/ppc_xenon/ppc_recomp.13.cpp:23359-23369:
//     // vor128 v63,v0,v0                            <- full 16-byte copy, :23359
//     simde_mm_store_si128((simde__m128i*)v63.u8, load(ctx.v0.u8));
//     // stvx128 v0,r0,r11      (r11 == r1+144)      <- float4 -> r1+144, :23362
//     // vpkd3d128 v63,v0,2,1,0
//     mcla_Vpkd3d128_type2(v63, ctx.v0);
//     // stvx128 v63,r0,r10      (r10 == r1+144)      <- same slot again, :23369
// VPD=1 defines one written dword, and on real silicon the other three are
// untouched; here they already hold the float4 the guest copied one instruction
// earlier, which the same slot is about to re-store. Writing them from stale
// register contents would destroy that float4.
//
// The written dword is the one the consumer reads. The paired consumer is a
// type-5 unpack of the same stack slot: 94 `vupkd3d128 v?,v?,20` sites
// (census over generated/ppc_xenon), all hooked to mcla_Vupkd3d128_type5, and
// that function reads vA.u32[3] per instr_vupkd3d128.s:63-68. With the
// destination at u32[0] the pack and the unpack never meet, and the guest reads a
// float bit pattern as a packed colour. u32[3] is the only index under which this
// function and mcla_Vupkd3d128_type5 compose.
void mcla_Vpkd3d128_type2(PPCVRegister& vD, PPCVRegister& vA) {
    const uint32_t packed = Pack2101010(vA);
    vD.u32[3] = packed;

    const uint32_t n = g_vpkd3d128_type2_hits.fetch_add(1, std::memory_order_relaxed);
    if (n < 8) {
        MCLA_LOG_INFO(
            "VMX128-PACK type2 #{} packed={:08X} dstWord=3 srcF32=[{:.6g},{:.6g},{:.6g},{:.6g}] "
            "srcBits=[{:08X},{:08X},{:08X},{:08X}]",
            n + 1, packed,
            vA.f32[0], vA.f32[1], vA.f32[2], vA.f32[3],
            FloatToBits(vA.f32[0]), FloatToBits(vA.f32[1]),
            FloatToBits(vA.f32[2]), FloatToBits(vA.f32[3]));
    } else if (n == 8) {
        MCLA_LOG_INFO("VMX128-PACK type2 further hits suppressed (count={})", n + 1);
    }
}

// vupkd3d128 VD,VB,20 -- type 5 = UINT_2101010. 94 of the 101
// __builtin_debugtrap() sites in the live tree (census: 94 `,20`, 1 `,8`;
// the rest are the inline-translated `,0` and `,4`).
//
// Reference: .research/xenia/src/xenia/cpu/backend/x64/x64_seq_vector.cc:2687
//   struct UNPACK::EmitUINT_2101010
// with the lane order fixed by the constants it uses:
//   x64_emitter.cc:718  XMMPackUINT_2101010_Shift = vec128i(0, 10, 20, 30)
//   x64_emitter.cc:717  XMMPackUINT_2101010_MaskPacked = vec128i(0x3FF, 0x3FF<<10,
//                                  0x3FF<<20, 0x3<<30)
//   x64_emitter.cc:670  XMM3331 = vec128f(3.0f, 3.0f, 3.0f, 1.0f)
// i.e. the three signed 10-bit fields are read from bits 0-9/10-19/20-29 of the
// packed dword and land in vD.u32[0..2], biased by 3.0f, and the unsigned 2-bit
// field from bits 30-31 lands in vD.u32[3], biased by 1.0f. The source dword is
// vA.u32[3]: the unpack splats it first (x64_seq_vector.cc:2700,
// `vshufps(dest, src, src, _MM_SHUFFLE(3,3,3,3))`). All four destination dwords
// are written, so there is no stale-lane hazard -- every mode-5 site then feeds
// stvx128 (ppc_recomp.48.cpp:22496, :22508) or stvewx128 (ppc_recomp.79.cpp:1547),
// both of which read the lanes this writes.
//
// This lane order is corroborated independently by the architectural corpus
// (instr_vupkd3d128.s:63-80), which pins bits 0-9 -> u32[0], 30-31 -> u32[3],
// the -512 sentinel -> QNaN, and the -511 encoding. It is the exact inverse of
// Pack2101010 above; the earlier note in this file claiming the two contradicted
// each other was wrong -- the mismatch it saw was Pack2101010 reading the source
// in reverse (f32[3] into bits 0-9), which is now corrected.
void mcla_Vupkd3d128_type5(PPCVRegister& vD, PPCVRegister& vA) {
    const uint32_t packed = vA.u32[3];

    vD.u32[0] = Unpack2101010Lane(static_cast<int32_t>(packed << 22) >> 22, kBias3Plus);
    vD.u32[1] = Unpack2101010Lane(static_cast<int32_t>(packed << 12) >> 22, kBias3Plus);
    vD.u32[2] = Unpack2101010Lane(static_cast<int32_t>(packed << 2) >> 22, kBias3Plus);
    vD.u32[3] = Unpack2101010Lane(static_cast<int32_t>((packed >> 30) & 0x3u), kBias1Plus);

    const uint32_t n = g_vupkd3d128_type5_hits.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 200) == 0) {
        MCLA_LOG_WARN(
            "VMX128-UNPACK type5 #{} src={:08X} f32=[{:.6g},{:.6g},{:.6g},{:.6g}] "
            "bits=[{:08X},{:08X},{:08X},{:08X}]",
            n, packed,
            vD.f32[0], vD.f32[1], vD.f32[2], vD.f32[3],
            vD.u32[0], vD.u32[1], vD.u32[2], vD.u32[3]);
    }
}

// vupkd3d128 VD,VB,8 -- type 2 = SHORT_4. The 1 remaining vupkd3d128 trap,
// generated/ppc_xenon/ppc_recomp.13.cpp:25272 (`vupkd3d128 v0,v62,8`). It is
// live (no hook, no `goto` above it) and its result v0 is read in full as four
// floats by the very next vector op, `vnmsubfp v11,v0,v12,v13` at
// ppc_recomp.13.cpp:25279 (`simde_mm_load_ps(ctx.v0.f32)`), so a partial write
// here would be a real data bug.
//
// Reference: x64_seq_vector.cc:2658 struct UNPACK::EmitSHORT_4, lane order
// taken from the shuffle mask it applies (x64_emitter.cc:708)
//   XMMUnpackSHORT_4 = vec128i(0xFFFF0B0A, 0xFFFF0908, 0xFFFF0F0E, 0xFFFF0D0C)
// pshufb copies src bytes {10,11} into vD.u32[0], {8,9} into vD.u32[1],
// {14,15} into vD.u32[2], {12,13} into vD.u32[3] -- that is, in the VR-word
// order the header establishes, vD.u32[0..3] <- sext16(vA.u32[2] high),
// vA.u32[2] low, vA.u32[3] high, vA.u32[3] low. (Xenia's own "src is
// (xx,xx,VALUE,VALUE)" comment at :2663 uses Xenia-internal element names, so
// the mask above, not the comment, is the authority for lane order here.) Then
// vpslld/vpsrad 16 and vpaddd XMM3333 (x64_emitter.cc:671) add 3.0f to every
// lane, and vcmpeqps/vblendvps turn -32768 into a quiet NaN
// (x64_seq_vector.cc:2684-2685). Corpus: instr_vupkd3d128.s:42-47.
void mcla_Vupkd3d128_type2(PPCVRegister& vD, PPCVRegister& vA) {
    vD.u32[0] = UnpackShort4Lane(static_cast<int32_t>(static_cast<int16_t>(vA.u16[5])));
    vD.u32[1] = UnpackShort4Lane(static_cast<int32_t>(static_cast<int16_t>(vA.u16[4])));
    vD.u32[2] = UnpackShort4Lane(static_cast<int32_t>(static_cast<int16_t>(vA.u16[7])));
    vD.u32[3] = UnpackShort4Lane(static_cast<int32_t>(static_cast<int16_t>(vA.u16[6])));

    const uint32_t n = g_vupkd3d128_type2_hits.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 200) == 0) {
        MCLA_LOG_WARN(
            "VMX128-UNPACK type2 #{} f32=[{:.6g},{:.6g},{:.6g},{:.6g}] "
            "bits=[{:08X},{:08X},{:08X},{:08X}]",
            n, vD.f32[0], vD.f32[1], vD.f32[2], vD.f32[3],
            vD.u32[0], vD.u32[1], vD.u32[2], vD.u32[3]);
    }
}

// vupkd3d128 VD,VB,4 -- type 1 = SHORT_2.  **NOT WIRED -- DO NOT CALL YET.**
//
// The single largest vupkd3d128 population in the guest: 443 `vupkd3d128 v?,v?,4`
// sites in generated/ppc_xenon (measured census), against 94 for `,20` and 1 for
// `,8`. Every one of them is translated INLINE by recompiler.cpp:2356-2365,
// which adds the two 16-bit fields to 3.0f and stores them but has NO overflow
// rule, so a source dword of 0x00008000 (or a high half of 0x8000) yields
// 0x403F8000 where the hardware yields a quiet NaN. That is the mistranslation
// tools/difftest reports as test_vupkd3d128_short2_3
// (instr_vupkd3d128.s:35-40: expected 0x7FC00000, got 0x403F8000).
//
// The function is here so the fix is a wiring change and not a rewrite, but
// adding the ~443 midasm_hook entries is a config/mcla_xenonrecomp.toml edit,
// which this file's owner must not make unilaterally: `python
// tools/addr_owners.py --check` per address first, then one hook per site, then
// a regen and a soak. Until that lands, recompiler.cpp:2368's debugtrap branch
// is unreachable for `,4` and this symbol has no callers.
// Lane order from x64_seq_vector.cc:2648-2653: XMMUnpackSHORT_2
// (x64_emitter.cc:706) is vec128i(0xFFFF0F0E, 0xFFFF0D0C, 0xFFFFFFFF, 0xFFFFFFFF),
// so pshufb leaves vD.u32[0] = sext16(vA.u32[3] high), vD.u32[1] = sext16(vA.u32[3]
// low), vD.u32[2] = 0, vD.u32[3] = 0, and the vpaddd of XMM3301 (x64_emitter.cc:669,
// vec128f(3.0, 3.0, 0.0, 1.0)) then gives 3.0, 3.0, 0.0, 1.0f. Corpus:
// instr_vupkd3d128.s:17-40.
void mcla_Vupkd3d128_type1(PPCVRegister& vD, PPCVRegister& vA) {
    vD.u32[0] = UnpackShort4Lane(static_cast<int32_t>(static_cast<int16_t>(vA.u16[3])));
    vD.u32[1] = UnpackShort4Lane(static_cast<int32_t>(static_cast<int16_t>(vA.u16[2])));
    vD.u32[2] = 0x00000000u;
    vD.u32[3] = kBias1Plus;

    const uint32_t n = g_vupkd3d128_type1_hits.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 200) == 0) {
        MCLA_LOG_WARN(
            "VMX128-UNPACK type1 #{} f32=[{:.6g},{:.6g},{:.6g},{:.6g}] "
            "bits=[{:08X},{:08X},{:08X},{:08X}]",
            n, vD.f32[0], vD.f32[1], vD.f32[2], vD.f32[3],
            vD.u32[0], vD.u32[1], vD.u32[2], vD.u32[3]);
    }
}
