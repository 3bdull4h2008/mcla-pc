// Host implementations for missing VMX128 vpkd3d128 modes (plan: docs/PLAN_VMX128.md).
// XenonRecomp midasm hooks call these by C++ reference, then jump over the
// __builtin_debugtrap() the recompiler would have emitted.

#include "ppc_config.h"
// Angle include: self-dir src/cpu/ppc_context.h is the TLS holder, not the
// ABI header (moved to src/cpu/, quote include would shadow src/ppc_context.h).
#include <ppc_context.h>

#include "logging.h"

#include <atomic>
#include <cstdint>
#include <cstring>

namespace {

// Xenia XMMPackUINT_2101010_* (x64_emitter.cc:710-718). Type-2 pack does NOT
// take raw [-1,1] floats — it clamps IEEE bits near 3.0 and ANDs the mantissa.
// XYZ: signed 10-bit in the low 10 bits of the float encoding of 3.0±511 ULP.
// W:   unsigned 2-bit in 3.0+{0..3} ULP.
constexpr uint32_t kXyzMinBits = 0x403FFE01u;
constexpr uint32_t kXyzMaxBits = 0x404001FFu;
constexpr uint32_t kWMinBits   = 0x40400000u;
constexpr uint32_t kWMaxBits   = 0x40400003u;

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

inline uint32_t Extract10(float f) {
    float clamped = f;
    if (!(clamped >= BitsToFloat(kXyzMinBits)))
        clamped = BitsToFloat(kXyzMinBits);
    if (clamped > BitsToFloat(kXyzMaxBits))
        clamped = BitsToFloat(kXyzMaxBits);
    return FloatToBits(clamped) & 0x3FFu;
}

inline uint32_t Extract2(float f) {
    float clamped = f;
    if (!(clamped >= BitsToFloat(kWMinBits)))
        clamped = BitsToFloat(kWMinBits);
    if (clamped > BitsToFloat(kWMaxBits))
        clamped = BitsToFloat(kWMaxBits);
    return FloatToBits(clamped) & 0x3u;
}

// XenonRecomp stores VMX128 lanes reversed vs guest element order
// (same convention its D3DCOLOR pack uses: host.f32[0] == guest W).
// Guest XYZW  ->  host f32[3], f32[2], f32[1], f32[0].
inline uint32_t Pack2101010(const PPCVRegister& src) {
    const uint32_t x = Extract10(src.f32[3]);
    const uint32_t y = Extract10(src.f32[2]);
    const uint32_t z = Extract10(src.f32[1]);
    const uint32_t w = Extract2(src.f32[0]);
    return (w << 30) | (z << 20) | (y << 10) | x;
}

std::atomic<uint32_t> g_vpkd3d128_type2_hits{0};

}  // namespace

// vpkd3d128 VD,VB,SH=2,MB=1,ME=0 — 4 sites, all in the vertex-fetch emulator.
// ME=0 selects dword 0 of VD; the only consumer (stvx128 + lwz 156(r1)) reads
// host.u32[0] via the VectorMaskL reverse, so writing that lane is sufficient.
void mcla_Vpkd3d128_type2(PPCVRegister& vD, PPCVRegister& vA) {
    const uint32_t packed = Pack2101010(vA);
    vD.u32[0] = packed;

    const uint32_t n = g_vpkd3d128_type2_hits.fetch_add(1, std::memory_order_relaxed);
    if (n < 8) {
        MCLA_LOG_INFO(
            "VMX128-PACK type2 #{} packed={:08X} srcF32=[{:.6g},{:.6g},{:.6g},{:.6g}] "
            "srcBits=[{:08X},{:08X},{:08X},{:08X}]",
            n + 1, packed,
            vA.f32[0], vA.f32[1], vA.f32[2], vA.f32[3],
            FloatToBits(vA.f32[0]), FloatToBits(vA.f32[1]),
            FloatToBits(vA.f32[2]), FloatToBits(vA.f32[3]));
    } else if (n == 8) {
        MCLA_LOG_INFO("VMX128-PACK type2 further hits suppressed (count={})", n + 1);
    }
}
