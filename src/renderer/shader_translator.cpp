#include "shader_translator.h"

// Phase 5: per-opcode Xenos microcode -> HLSL lowering.
//
// Consumes the normalized IR produced by xenos_shader_ir (DecodedInstruction
// stream in program order) and emits readable HLSL, following the lowering
// semantics of hedge-dev/XenosRecomp (shader_recompiler.cpp):
//
//   - vector ALU ops -> arithmetic/compare/select/dot expressions on float4
//     registers with per-opcode operand masks;
//   - scalar ALU ops -> the float "ps" (previous-scalar) pipeline, with
//     Setp*/predicate stack and Kills -> clip();
//   - fetch (vertex/tfetch) -> vertex-element inputs (VS) or sampler/texture
//     binds with swizzled register writes (PS);
//   - exports -> oC0..oC3 / oDepth (PS) or oPos + interpolators (VS).
//
// This is a generator: it must always emit a complete, tokenizable HLSL body
// so the offline tool can diff and compile it. Every ALU vector/scalar opcode
// has a lowering branch (scalar RetainPrev is deliberately skipped before the
// clause); vertex and texture fetches get the two fetch branches, and the aux
// GET/SETTEXTURE fetch opcodes decode as known and share the texture-fetch
// path. Anything outside the decoder's known table is recorded as unsupported
// (never silently dropped). The emitted HLSL is diagnostic-grade; the helpers
// the body references (select() ternary overloads, FLT_MIN/FLT_MAX macros)
// are emitted inline in AppendHeader so the output stands alone.

// The unwritten-register census (CensusGuestRegisterAccess,
// LogUnwrittenRegisterReads) reports through mcla::log::Warn. That symbol is
// `inline` (src/common/logging.h:76), so including the header adds no link
// dependency for the validator targets that build this file without a logger
// (CMakeLists.txt:605-609 links only d3d12/dxgi/dxguid). Same include spelling
// as dxc_runtime.cpp:16 and pipeline_cache.cpp:12.
#include "common/logging.h"

#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace mcla::renderer {

// ---------------------------------------------------------------- reflection
//
// Vertex-input reflection consumed by the render thread's input-layout
// fallback (src/render_thread.cpp). A vertex fetch resolves to a
// (usage, usageIndex) pair by matching the program's vertexElements (12-bit
// stream address) against the fetch's IR instruction address, falling back to
// the first element when no element matches — the same comparison EmitFetch
// makes. ReferencedVertexInputs returns the unique pairs in first-fetch order
// plus the format/stride/offset of the fetch that introduced each pair, so
// the declared signature and the bound layout always agree.

const char* VertexUsageSemanticName(uint32_t usage) {
    // DeclUsage semantic table (the all-caps counterparts of kUsageVariables).
    static constexpr const char* kSemantics[] = {
        "POSITION", "BLENDWEIGHT", "BLENDINDICES", "NORMAL", "POINTSIZE",
        "TEXCOORD", "TANGENT",     "BINORMAL",     "TESSFACTOR", "POSITIONT",
        "COLOR",    "FOG",         "DEPTH",        "SAMPLE",
    };
    if (usage >= 14) usage = 0;  // clamp, mirroring the translator fallback
    return kSemantics[usage];
}

std::vector<VertexInputRef> ReferencedVertexInputs(const ShaderProgram& prog) {
    std::vector<VertexInputRef> inputs;
    if (!prog.isVertex) return inputs;

    auto resolve = [&prog](uint32_t addr, uint32_t& usage,
                           uint32_t& usageIndex) {
        usage = 0;
        usageIndex = 0;
        for (const auto& ve : prog.vertexElements) {
            if (ve.address == addr) {
                usage = ve.usage;
                usageIndex = ve.usageIndex;
                return;
            }
        }
        if (!prog.vertexElements.empty()) {
            usage = prog.vertexElements[0].usage;
            usageIndex = prog.vertexElements[0].usageIndex;
        }
    };

    // A vfetch_mini stores stride 0 in its own word2 and inherits the previous
    // vfetch_full's stride: "Reuse previous vfetch_full if this is a mini"
    // (.research/xenia/src/xenia/gpu/shader_translator.cc:1022-1023), applied
    // at `:1045` as `instr.attributes.stride = full_op.stride();`. The offset
    // is NOT inherited (`instr.attributes.offset = op.offset();`, `:1044`).
    //
    // Reported as 0, a mini fetch's element contributes no bytes and the
    // draw's byte accounting is short by exactly the mini's payload -- which is
    // the measured 16 unaccounted bytes on draw 1 (fmt 38 = 4x32-bit float at
    // offset 3 dwords of a 7-dword stride, from CP-FETCHVB-DESC #1 in w689).
    // The mini bit is read from VertexFetch WORD 1 bit 30, via
    // IrInstruction::isMiniFetch (fetchFlagBits, packed by the shifts in
    // xenos_shader_ir.cpp's decode loop). VertexFetch word 1 only: tfetch word 1
    // is_predicated is also bit 31 (ucode.h:866) and ALU word 1 is_predicated
    // is bit 28 (ucode.h:2076) -- three layouts, and "bit 28" is a true
    // statement about an ALU instruction and a false one about this fetch.
    //
    // MEASURED on this very fetch, not inferred: its word1 is 0x40263688, whose
    // bit 30 is 1 and whose bit 28 is 0, while the preceding full fetch's word1
    // 0x00393A88 has bit 30 = 0 -- and that mini/full split is exactly what the
    // stride inheritance above keys on (build/w686.log, CP-SHADER-BODY #3
    // against CP-FETCHVB-DESC #1 instr=0/instr=1, strideDwords=7 then 0; the
    // same pair recurs in w685). Bits 22-23, reserved2, are 0 on every vfetch
    // word1 reachable from this tree, which is what forces exp_adjust to start
    // at 24 and the flags to 30/31; the argument is written out on
    // IrInstruction::fetchFlagBits in xenos_shader_ir.h.
    //
    // DecodeInstruction now reads bit 30 too (xenos_microcode.cpp:167), as does
    // the CP-side decoder (src/gpu_cp.cpp:1295). An earlier revision of this
    // comment said "DecodedInstruction::isMiniFetch reads bit 28
    // (xenos_microcode.cpp:168) and therefore reports 0 for this very fetch" --
    // both halves were false (168 is not the isMiniFetch read, and the
    // report-0 consequence it described no longer exists), so the sentence this
    // paragraph replaces was licensing a defect with a mechanism that was not
    // there.
    //
    // prog.instructions is walked in stored (control-flow block) order. The
    // inheritance is order-sensitive, so only a full fetch that has ALREADY
    // been seen in that same order can donate its stride; a mini ahead of its
    // full fetch keeps 0 rather than borrowing a later one.
    uint32_t previousFullStride = 0;
    for (const auto& ir : prog.instructions) {
        if (!ir.isFetch || ir.decoded.kind != InstructionKind::VertexFetch)
            continue;
        uint32_t usage = 0, usageIndex = 0;
        resolve(ir.address, usage, usageIndex);
        if (usage >= 14) usage = 0;
        bool seen = false;
        for (const auto& in : inputs)
            if (in.usage == usage && in.usageIndex == usageIndex) { seen = true; break; }
        const uint32_t stride =
            ir.isMiniFetch() ? previousFullStride : ir.decoded.stride;
        if (!ir.isMiniFetch()) previousFullStride = ir.decoded.stride;
        if (seen) continue;
        inputs.push_back(VertexInputRef{usage, usageIndex,
                                        ir.decoded.vertexFormat,
                                        stride, ir.decoded.offset});
    }
    return inputs;
}

namespace {

constexpr char kSwizzle[] = {'x', 'y', 'z', 'w', '0', '1', '_', '_'};

constexpr const char* kUsageVariables[] = {
    "Position", "BlendWeight", "BlendIndices", "Normal", "PointSize",
    "TexCoord", "Tangent",     "Binormal",     "TessFactor", "PositionT",
    "Color",    "Fog",         "Depth",        "Sample",
};

// Xenos VS exports: 62 = position, 0-15 = VSInterpolator0..15, 63 = point
// size / edge flag / kill vertex (no color output). PS exports are 0-3
// (color) and 61 (depth), see ExportRegisterName.

// ---------------------------------------------------------------------------
// Operand selection (mirrors the `op` operand lambda inside XenosRecomp's
// ShaderRecompiler::recompile(), shader_recompiler.cpp).
// ---------------------------------------------------------------------------
enum class OperandKind : uint8_t {
    Vector0,
    Vector1,
    Vector2,
    Scalar0,
    Scalar1,
    ScalarConstant0,
    ScalarConstant1,
};

constexpr uint32_t kRegisterCount = 32;

// ---------------------------------------------------------------------------
// clip_disable NDC rescale (the guest-pixel -> host-clip-space map).
//
// WHY IT EXISTS. For this title the guest runs with PA_CL_CLIP_CNTL = 0x00010000
// and PA_CL_VTE_CNTL = 0x00000300. Both are MEASURED, in the log this tree
// produced: build/w706.log:1676-1678 prints
//     CP-DRAW-REGS #1 [30/57] r2204=00010000
//     CP-DRAW-REGS #1 [31/57] r2205=00010000
//     CP-DRAW-REGS #1 [32/57] r2206=00000300
// and the same three values repeat for #2 (w706.log:1722-1724) and #3
// (w706.log:1769-1771). Decoded against
// .research/xenia/src/xenia/gpu/registers.h:534-583 (bit +16 clip_disable, bits
// +0..+5 of PA_CL_VTE_CNTL the six vport_*_ena):
//     r2204 bit 16 set  -> clip_disable = 1, and NO user clip plane (ucp_ena 0)
//     r2206 bits 8,9   -> vtx_xy_fmt / vtx_z_fmt, and ALL SIX vport_*_ena CLEAR
// so there is no host-side viewport transform in the VTE and no clip volume: the
// vertex shader's POSITION output is in GUEST PIXELS, pre-divided by W. That is
// the case the reference documents at draw_util.cc:255-298 and implements at
// :362-386, and it is why this tree's viewport-only transform cannot place the
// geometry: a D3D12 viewport maps clip space to pixels, and pixel-valued clip
// space is not clip space.
//
// THE ARITHMETIC, verbatim from the reference (draw_util.cc:362-386, then the
// application at spirv_shader_translator.cc:1612-1624, then the y negation at
// draw_util.cc:549-552):
//     xy_offset[i]      = 0
//     extent[i]         = min(kTexture2DCubeMaxWidthHeight = 8192, RT extent[i])
//     pixels_to_ndc[i]  = 2 / extent[i]
//     ndc_scale[i]      = scale_xy[i] * pixels_to_ndc[i]        <- 1, enables clear
//     ndc_offset[i]     = (offset_base[i] - extent[i]*0.5 + offset_add[i])
//                        * pixels_to_ndc[i]                     <- 0 + half-pixel
//     ndc_scale[2]      = scale_z = 1,  ndc_offset[2] = offset_z = 0,
//     z_min = 0, z_max = 1
// and then, because D3D12's clip space has +Y DOWN (MEASURED on an RTX 3070, not
// assumed -- see the note on kNdcYSign below):
//     ndc_scale[1] = -ndc_scale[1];  ndc_offset[1] = -ndc_offset[1]
// applied to XYZ ONLY, with the offset scaled by W (so it happens in clip space,
// before the divide):
//     oPos.xyz = oPos.xyz * ndc_scale + ndc_offset * oPos.w
//
// extent is min(8192, RT extent), NOT 8192. For a 1280x720 target the min does
// not bite and extent IS (1280, 720). A constant of 8192 here is simply a
// different transform: measured on the same device it lands the geometry in a
// 2,475-pixel corner blob at (16,4)-(171,34) instead of at its guest pixels.
//
// .research/xenia has no .git, is gitignored and has 0 files in HEAD, so those
// file:line citations cannot be tied to an upstream commit; they are cited as
// trail. The guest facts above are cited to w706.log rows, which are this tree's
// own output.
//
// WHAT IS NOT HERE, AND WHY. The GATE (whether a given draw has clip_disable set
// and the vport enables clear) lives in pipeline_cache.cpp, which decodes
// PA_CL_CLIP_CNTL / PA_CL_VTE_CNTL into DecodedXenosRenderState and is not this
// file's to change; per-draw gating therefore needs a cooperation that does not
// exist yet. Until it does, the rescale is applied to every vertex shader and
// the log says so (kClipDisableRescaleAlwaysNote). The EXTENT, by contrast, is
// not guessed: SetClipDisableViewportExtent is called from the backend at the
// point it sets the D3D12 viewport, from the same m_width/m_height the viewport
// uses, so the two cannot disagree.
struct ClipDisableRescale {
    float scaleX = 0.0f, scaleY = 0.0f, scaleZ = 1.0f;
    float offsetX = 0.0f, offsetY = 0.0f, offsetZ = 0.0f;
    bool valid = false;
};

// D3D12's clip space has +Y DOWN, so the reference's origin_bottom_left negation
// (draw_util.cc:549-552) applies. MEASURED, not assumed: an arm whose kS.y/kO.y
// are negated rasterises a guest-pixel rect (100,50)-(1100,400) at measured
// bbox (100,50)-(1099,399), while the same arm without the negation lands at
// measured bbox (103,320)-(1099,668) -- the exact mirror about y=360 -- and an
// arm with x negated lands at (179,50)-(1178,399), the exact mirror about x=640.
// Both un-negated predictions (the OpenGL convention, +Y up) are refuted by those
// two rows. See %TEMP%\opencode\ndcconv\run2.txt.
constexpr float kNdcYSign = -1.0f;

ClipDisableRescale g_clipDisableRescale;

// Shortest decimal form that round-trips the float exactly, so the literal in
// the generated HLSL is the constant that was computed and not a rounded copy of
// it. File scope rather than a member of HlslGenerator because it touches no
// emitter state, which also makes it reachable from a test that includes this
// file (see %TEMP%\opencode\ndcconv\epilogue_check.cpp).
std::string FloatLit(float v) {
    std::string s = fmt::format("{}", v);
    if (std::strtof(s.c_str(), nullptr) == v) return s;
    return fmt::format("{:e}", v);
}

// Reported once per process by the backend, so a reader of a soak knows the gate
// is a measured constant and not a per-draw register read. DEFINED OUTSIDE the
// anonymous namespace below, because the header declares it with external linkage
// (see shader_translator.h); a definition inside `namespace {` would be internal
// and the two would be different objects with the same name.
//
// Deliberately names no other tracked marker: a tracked marker named inside
// another marker's prose becomes uncountable, because tools/soak_census.py counts
// matching LINES.;

// Compute the reference's constants for one axis. `extent` is ALREADY the
// min(8192, RT extent) result, computed by the caller, because that min is what
// makes a 1280x720 target use 1280x720 and not 8192x8192.
ClipDisableRescale MakeClipDisableRescale(uint32_t widthPx, uint32_t heightPx) {
    ClipDisableRescale r;
    if (widthPx == 0 || heightPx == 0) return r;   // no target: leave invalid
    // kTexture2DCubeMaxWidthHeightLog2 == 13 (xenia.h:1139-1141) -> 8192.
    constexpr float kMaxExtent = 8192.0f;
    const float halfPixel = 0.5f;   // draw_util.cc:344-348, the only offset_add term
    struct Axis { float rt; float* s; float* o; };
    const Axis axes[2] = {
        {static_cast<float>(widthPx),  &r.scaleX,  &r.offsetX},
        {static_cast<float>(heightPx), &r.scaleY,  &r.offsetY},
    };
    for (const Axis& a : axes) {
        const float extent = a.rt < kMaxExtent ? a.rt : kMaxExtent;
        const float pixelsToNdc = 2.0f / extent;
        *a.s = 1.0f * pixelsToNdc;                                  // scale_xy == 1
        *a.o = (0.0f - extent * 0.5f + halfPixel) * pixelsToNdc;   // offset_base == 0
    }
    r.scaleY *= kNdcYSign;
    r.offsetY *= kNdcYSign;
    r.scaleZ = 1.0f;
    r.offsetZ = 0.0f;
    r.valid = true;
    return r;
}

// ---------------------------------------------------------------------------
// Unwritten-register census (the SHADER-UNWRITTEN-REG-READ marker).
// ---------------------------------------------------------------------------

// The reference's VECTOR operand count per opcode, i.e.
// GetAluVectorOpcodeInfo(op.vector_opcode()).GetOperandCount() -- the number of
// source operands ParseAluInstruction actually parses and
// GatherAluInstructionInformation actually gathers.
//
// TRANSCRIBED, NOT INFERRED, from
//   .research/xenia/src/xenia/gpu/ucode.cc:83-116  kAluVectorOpcodeInfos[]
//     {"add", {0b1111, 0b1111}, ...}                      -> 2
//     {"frc", {0b1111}, ...}                             -> 1
//     {"mad", {0b1111, 0b1111, 0b1111}, ...}             -> 3
//     {"dst", {0b0110, 0b1010}, ...}                     -> 2
//     {"opcode_30", {}, ...}, {"opcode_31", {}, ...}     -> 0
// with the 0/1/2/3 reduction itself at
//   .research/xenia/src/xenia/gpu/ucode.h:1715-1726  AluVectorOpcodeInfo::GetOperandCount()
// which returns 0 when all three are zero, then 1, then 2, else 3 -- the
// reference's own nesting, quoted rather than paraphrased.
//
// `.research/xenia/` HAS NO .git, IS GITIGNORED, AND HAS 0 FILES IN HEAD: it is
// an untracked snapshot with no recorded provenance. These constants are trail,
// not authority, and the derivation is restated above so a reader can check it
// against the reference if the checkout ever gains a history.
//
// SAFE TO TRUST EVEN IF THE REFERENCE IS WRONG ABOUT ITSELF, which is why the
// bound is this table and not the opcode alone: every entry is <= the 3 sources
// the decoder carries, so the bound can only ever REMOVE reads this module
// previously counted, never add one.
constexpr uint32_t kReferenceVectorOperandCount[32] = {
    /* 0 add          */ 2, /* 1 mul          */ 2, /* 2 max          */ 2,
    /* 3 min          */ 2, /* 4 seq          */ 2, /* 5 sgt          */ 2,
    /* 6 sge          */ 2, /* 7 sne          */ 2, /* 8 frc          */ 1,
    /* 9 trunc        */ 1, /*10 floor        */ 1, /*11 mad          */ 3,
    /*12 cndeq        */ 3, /*13 cndge        */ 3, /*14 cndgt        */ 3,
    /*15 dp4          */ 2, /*16 dp3          */ 2, /*17 dp2add       */ 3,
    /*18 cube         */ 2, /*19 max4         */ 1, /*20 setp_eq_push */ 2,
    /*21 setp_ne_push */ 2, /*22 setp_gt_push */ 2, /*23 setp_ge_push */ 2,
    /*24 kill_eq      */ 2, /*25 kill_gt      */ 2, /*26 kill_ge      */ 2,
    /*27 kill_ne      */ 2, /*28 dst          */ 2, /*29 maxa         */ 2,
    /*30 opcode_30    */ 0, /*31 opcode_31    */ 0,
};
//
// WHAT THIS IS FOR. A pixel shader whose only instruction is
// `oC0 = max(r0, r0)` reads r0 and writes nothing, so its colour is whatever
// the host seeds r0 with. That seed is a HOST CHOICE, and the one thing a
// reader cannot re-derive from the HLSL is whether the guest ever supplied a
// value. This census answers that from the guest's own bytes and says so in
// the log, so the black is attributable instead of looking like a colour bug.
//
// THE SEED IS NOT AN INVENTION. The reference zero-fills every general-purpose
// register at the top of a shader, precisely so that a program which reads a
// register it never wrote has a defined value:
//   .research/xenia/src/xenia/gpu/spirv_shader_translator.cc:2052-2070 (pixel)
//       // Zero general-purpose registers to prevent crashes when the game
//       // references them after only initializing them conditionally, and copy
//       // interpolants to GPRs.
//   .research/xenia/src/xenia/gpu/spirv_shader_translator.cc:1300-1309 (vertex)
// with the value `const_float4_0_`. It seeds from an interpolant ONLY when the
// interpolator mask has that bit, and that mask is an INTERSECTION:
//   .research/xenia/src/xenia/gpu/vulkan/vulkan_command_processor.cc:2206-2211
//       interpolator_mask = vertex_shader->writes_interpolators() &
//                           pixel_shader->GetInterpolatorInputMask(...)
// so a VS that exports no interpolator leaves the mask 0 and the reference
// zeroes r0 too. `writes_interpolators_` is set only by an ALU result whose
// storage target is kInterpolator (shader_translator.cc:597-599); an export to
// vectorDest 62 is POSITION and does not set it.
//
// CENSUSED FROM THE IR, NOT FROM THE OUTPUT. `referencedRegisters_` records what
// the EMITTER touched, and an instruction whose effective write mask is 0
// emits no operand text at all, so its register reads disappear from that set
// while still being reads in the guest's program. Measured: all four ALU
// instructions of CP-SHADER-BODY #1 have vectorWriteMask 0, so its r0/r1 reads
// never reach referencedRegisters_ and would be invisible here. The `emitted`
// list is therefore reported separately from the guest-level list.
void CensusGuestRegisterAccess(const ShaderProgram& prog, std::vector<bool>& read,
                               std::vector<bool>& written) {
    read.assign(kRegisterCount, false);
    written.assign(kRegisterCount, false);
    for (const auto& ir : prog.instructions) {
        if (ir.isFetch) {
            // An unknown FETCH opcode really does contribute nothing, and the
            // reference's reason is a hard RETURN rather than a decode failure:
            // ParseTextureFetchInstruction's `default:` arm is
            // `assert_unhandled_case(fetch_opcode); return;`
            // (.research/xenia/src/xenia/gpu/shader_translator.cc:1102-1104), so
            // `instr.result` keeps its defaults -- storage_target kNone and
            // original_write_mask 0 -- and GatherFetchResultInformation returns on
            // the empty used write mask at :566-568. No source operand is appended
            // either, so the operand loop at :451-453 has nothing to gather.
            // Skipping the whole instruction is therefore correct HERE, and only
            // here. (Measured on the corpus: 0 unknown fetch opcodes in 506
            // containers, so this arm is currently unreachable either way.)
            if (ir.decoded.unknown) continue;
            // A fetch's SOURCE selector addresses the vertex buffer, not the GPR
            // file, so only the destination is a register write. This matches the
            // reference, which gathers fetch results (GatherFetchResultInformation,
            // shader_translator.cc:565-579) and no fetch source register.
            //
            // ... BUT NOT FOR EVERY KNOWN FETCH OPCODE. THREE OF THEM HAVE NO
            // DESTINATION IN THE REFERENCE, and this arm recorded one anyway
            // (2026-10-05). ParseTextureFetchInstruction builds
            //     opcode_info = {"setTexLOD", false, false, false, 1};      // :1093-1095
            //     opcode_info = {"setGradientH", false, false, false, 3};  // :1096-1098
            //     opcode_info = {"setGradientV", false, false, false, 3};  // :1099-1101
            // -- the second field is has_dest, false in all three -- and then
            //     if (opcode_info.has_dest) {
            //       ParseFetchInstructionResult(op.dest(), op.dest_swizzle(),
            //                                           op.is_dest_relative(),
            //                                           instr.result);
            //     } else {
            //       instr.result.storage_target = InstructionStorageTarget::kNone;
            //     }
            // (:1113-1118). With storage_target kNone the result keeps its default
            // original_write_mask 0, so GetUsedWriteMask() is 0 and
            // GatherFetchResultInformation RETURNS at :566-568 having raised
            // nothing: `register_static_address_bound_` is never advanced and
            // `written[dst]` is never claimed.
            //
            // The three opcodes are FetchOpcode::kSetTextureLod = 24,
            // kSetTextureGradientsHorz = 25, kSetTextureGradientsVert = 26
            // (.research/xenia/src/xenia/gpu/ucode.h:670, 672, 674) -- the numeric
            // values are the point, since a name here would be a claim about this
            // tree's enum rather than the reference's.
            //
            // MEASURED over the corpus (215 pixel containers, 734 known fetches):
            // 10 instructions carry opcode 24/25/26. All 10 wrote a register that
            // is ALSO READ somewhere in the same container, so the reference's
            // smaller `written` set turns 10 read-but-never-written reports into
            // 10 reports that are, on the reference's own terms, correct: the
            // destination of a setTexLOD really is a GPR nothing wrote.
            //
            // LOG-ONLY, as with the read bound above: `written` is a local of this
            // function and the emitter never consults it.
            const uint32_t fetchOpcode = static_cast<uint32_t>(ir.decoded.fetchOpcode);
            const bool fetchHasNoDestination =
                fetchOpcode == 24u || fetchOpcode == 25u || fetchOpcode == 26u;
            if (!fetchHasNoDestination) {
                const uint32_t d = ir.decoded.dstRegister & 0x3F;
                if (d < kRegisterCount) written[d] = true;
            }
            continue;
        }
        const DecodedInstruction& in = ir.decoded;
        // Reads, and ONLY when the opcode is known. An unknown opcode reads
        // NOTHING in the reference: kAluVectorOpcodeInfos[30] and [31] carry an
        // empty operand_components_used, so GetOperandCount() is 0
        // (.research/xenia/src/xenia/gpu/ucode.h:1715-1726 over ucode.cc:114-115),
        // and every unknown scalar opcode carries operand_count 0 (ucode.cc:58 for
        // opcode_41, :68-80 for opcode_51..63). ParseAluInstruction then appends no
        // operand for that half (shader_translator.cc:1385-1389 and :1417-1461), so
        // GatherOperandInformation is never reached for it. Dropping the reads of an
        // unknown instruction is CORRECT.
        if (!in.unknown) {
            // sel == 1 is a temp register and sel == 0 is a c-register
            // constant (ucode.h:1909-1921), the same discrimination NoteOperand
            // makes. Bit 7 of the packed index marks an immediate value rather than
            // a register (ucode.h:1890-1892), so that form is not a GPR read either.
            const uint32_t srcReg[3] = {in.src1Register, in.src2Register,
                                        in.src3Register};
            const bool srcSel[3] = {in.src1Select, in.src2Select, in.src3Select};
            // ... BUT ONLY AS MANY AS THE OPCODE ACTUALLY GATHERS.
            //
            // THIS BOUND IS THE FIX (2026-10-05). The loop used to walk all three
            // source slots unconditionally, so it counted a read the reference
            // never makes. The reference gathers src1..src[vector_operand_count]
            // and nothing more --
            //     instr.vector_operand_count = vector_opcode_info.GetOperandCount();
            //     for (uint32_t i = 0; i < instr.vector_operand_count; ++i)
            //       ParseAluInstructionOperand(op, i + 1, 4, instr.vector_operands[i]);
            // (.research/xenia/src/xenia/gpu/shader_translator.cc:1385-1389) and
            // GetOperandCount() returns 0/1/2/3 from the first zero slot in
            // kAluVectorOpcodeInfos[].operand_components_used
            // (ucode.h:1715-1726 over ucode.cc:83-116). So `max` gathers TWO
            // sources and `mad` gathers THREE, while this loop claimed three for
            // both.
            //
            // MEASURED over the corpus (215 pixel containers, 6517 ALU
            // instructions) with the two models compared per (instruction,
            // register): ours records 14894 reads, the reference gathers 11377, and
            // 2410 pairs are OURS ALONE with 0 the other way -- the reference's set
            // is a strict subset of ours, which is what a missing bound predicts.
            // 137 containers are touched. Set-wise, this changes the row set in 38
            // of 215 pixel containers (symmetric difference 56 pairs).
            //
            // LOG-ONLY, and that is the whole of its effect: `read` is a local of
            // LogUnwrittenRegisterReads and is read by nothing else in this
            // translation path. AppendRegisters, AppendSignature and the emitted
            // body never consult it, so no declaration, no input element and no
            // shader value can move.
            //
            // SCALAR OPERANDS ARE STILL NOT GATHERED HERE, and that is a KNOWN
            // GAP, not a claim of completeness: for scalar_operand_count == 1 the
            // reference parses slot 3 (:1420-1422), and for == 2 its register
            // operand is `op.scalar_const_reg_op_src_temp_reg()` (:1455), a
            // DIFFERENT bitfield from src_reg(1). Neither maps onto src1..src3 as
            // this decoder populates them, so counting them would be inventing a
            // field. Counted as 0 here, exactly as before this fix.
            const uint32_t vopIdx = static_cast<uint32_t>(in.vectorOpcode);
            const uint32_t vectorOperandCount =
                kReferenceVectorOperandCount[vopIdx < 32 ? vopIdx : 0u];
            for (uint32_t i = 0; i < vectorOperandCount && i < 3; ++i) {
                if (!srcSel[i]) continue;
                if ((srcReg[i] & 0x80) != 0) continue;  // immediate, not a register
                const uint32_t r = srcReg[i] & 0x3F;
                if (r < kRegisterCount) read[r] = true;
            }
        }
        // Writes, REGARDLESS of `unknown`. This is the whole point of the change,
        // and it is not a judgement call: the reference's write accounting never
        // consults the opcode at all. ParseAluInstruction builds BOTH results from
        // word0 alone --
        //     original_write_mask = op.GetVectorOpResultWriteMask() | c0 | c1
        //     original_write_mask = op.GetScalarOpResultWriteMask()
        // with storage_index = op.vector_dest() / op.scalar_dest()
        // (.research/xenia/src/xenia/gpu/shader_translator.cc:1358-1383 and
        // :1399-1412) -- and those two masks are the word0 write-mask bits and
        // nothing else (ucode.h:2011-2023). GatherAluInstructionInformation then
        // calls GatherAluResultInformation on both results UNCONDITIONALLY (:502-503),
        // which raises register_static_address_bound_ for a kRegister result whose
        // used write mask is non-empty (:588-596). So an unknown vector opcode with
        // vectorWriteMask 0xF and vector_dest 0 is a WRITE of r0 in the reference, and
        // reporting it as unwritten is a wrong answer -- silently, because the
        // detector's own name promises it can tell those apart.
        //
        // The single `if (ir.decoded.unknown) continue;` this replaces conflated the
        // two halves. It was RIGHT about the reads and WRONG about the writes.
        //
        // WHAT `written` DOES NOT SAY. It says the GUEST wrote the register. It does
        // not say the emitted HLSL did: AppendBody comments an unknown instruction
        // out and counts it (shader_translator.cpp:1151-1155), so until the opcode is
        // lowered the host seed still decides that register in the generated shader.
        // That separate gap is already reported on its own field,
        // TranslatedShader::unsupportedOpcodeCount (shader_translator.h:33, assigned
        // at :2141), and this census deliberately does not merge the two facts:
        // "the guest wrote it" and "the host emitted it" are claims about different
        // artifacts, and F-609 forbids inventing one from the other.
        //
        // With exportData the destination is the EXPORT target, not the GPR, so an
        // exporting instruction writes no GPR at all -- the reference resolves
        // storage_target away from kRegister in that case (shader_translator.cc:1304-
        // 1348). This mirrors the emitter, which takes the RegName(vectorDest) branch
        // only when exportReg is empty (EmitAlu, the vector and scalar write arms).
        if (in.exportData) continue;
        if (in.vectorWriteMask != 0) {
            const uint32_t r = in.vectorDest & 0x3F;
            if (r < kRegisterCount) written[r] = true;
        }
        if (in.scalarWriteMask != 0) {
            const uint32_t r = in.scalarDest & 0x3F;
            if (r < kRegisterCount) written[r] = true;
        }
    }
}

// One marker row per translation that has at least one read-never-written
// register. Rate-limited on the project's own established shape (first 8, then
// every 200th) so a long soak cannot hand one mitigation shape the log; see the
// same guard at src/render_thread.cpp:3141.
//
// THE `seed=` FIELD IS NOW COMPUTED, and that is the only change to the row. It
// used to be the literal `0.0`, which was a statement about the reference's
// behaviour rather than about this translation. It is now the seed the emitted HLSL
// actually used, read back out of `prog.interpolators` -- the post-intersection set,
// which is the same set AppendRegisters seeds from -- so the row can no longer
// disagree with the shader it describes. A row whose seeds are all zero still prints
// `seed=0.0`, byte for byte: the field is only widened when at least one register
// does NOT take the literal `0.0` seed, and then it lists one entry per register in
// ascending order, either `interpolant<N>`, `0.0`, or `none` for a register the
// emitter declared not at all.
//
// CORRECTION (2026-10-05). This block used to end "so the row can no longer
// disagree with the shader it describes", and to say the seed gate needed "no
// re-derivation and no chance of the row and the source disagreeing". Both were
// false. Table membership alone is not the gate AppendRegisters uses -- it also
// requires referencedRegisters_[reg] -- so the row DID disagree, for 25 measured
// (container,register) pairs over the corpus. The gate below is now AppendRegisters'
// own condition, and the disagreement is counted rather than denied; see the block
// at the seed computation for the measurement and for the mechanism (:1489).
//
// NOTHING ELSE MOVED. Every pre-existing `{}` placeholder and its argument keeps
// its position and its value; the new evidence is one clause APPENDED AT THE VERY
// END (`seedRule=`). Two sentences inside the row were corrected rather than left
// standing, because they asserted a value that is now sometimes false ("the
// translator supplies 0.0" / "would also pick 0.0 here"); a row that states a
// falsehood is worse than a prose edit, and neither sentence is a field.
void LogUnwrittenRegisterReads(const ShaderProgram& prog, bool ps,
                               const std::vector<bool>& referenced,
                               const InterpolatorIntersection* pairing) {
    std::vector<bool> read, written;
    CensusGuestRegisterAccess(prog, read, written);

    std::string regs;
    std::string emitted;
    size_t readTotal = 0;
    size_t writeTotal = 0;
    // Per-register seed, in the same ascending order as `regs`.
    std::string seeds;
    // True when EVERY entry is the literal `0.0`, which is the shape this row
    // has always printed for a translation with no interpolant seed at all. It
    // is what keeps the common case byte-identical; anything else prints the
    // full per-register list.
    bool seedsUniformZero = true;
    for (uint32_t r = 0; r < kRegisterCount; ++r) {
        if (written[r]) ++writeTotal;
        if (!read[r]) continue;
        ++readTotal;
        // read and never written: this is what gets the host-chosen seed.
        if (written[r]) continue;
        if (!regs.empty()) regs += ",";
        regs += "r" + std::to_string(r);
        if (r < referenced.size() && referenced[r]) {
            if (!emitted.empty()) emitted += ",";
            emitted += "r" + std::to_string(r);
        }
        // The seed this register's declaration carries -- and, when it has NO
        // declaration, the fact that it has none.
        //
        // THIS GATE IS NOW AppendRegisters' OWN CONDITION, and the previous
        // version of it was wrong. It used to test post-intersection table
        // membership ALONE, on the strength of a claim in the comment here that
        // "the presence of an entry with this reg in prog.interpolators IS the
        // distinction". It is not. AppendRegisters seeds an interpolant only
        // when the register is in the table AND in referencedRegisters_
        // (`:1132-1135` builds `seeded[]` from both, `:1142-1144` re-tests both),
        // so a register that is in the table yet unreferenced gets NO
        // DECLARATION AT ALL -- and this row then printed `interpolant<N>` for a
        // variable the emitted HLSL does not contain.
        //
        // MEASURED over the 164-file corpus (215 pixel containers), driving the
        // real HlslGenerator through the public TranslateShader entry point:
        //   ROW registers = 145 (container,register) pairs in 116 containers
        //   of those, with NO `float4 rN = ...` line in the emitted HLSL = 59
        //     pairs in 46 containers
        //   of THOSE 59, in the interpolator table = 25 pairs in 25 containers
        //   -> 25 rows would name an interpolant seed for a register that is
        //      not in the generated shader
        // The other 34 print `0.0`, which is what AppendRegisters would have
        // given had it declared them, so they are not seed-divergent.
        //
        // THE CAUSE, MEASURED AND NOT INFERRED, because it is not the one this
        // comment used to assert. It is not "a read with a zero write mask": the
        // corpus shows 0 pairs of that shape. It is shader_translator.cpp:1489,
        //     if (instr.exportData) vectorWriteMask &= ~instr.scalarWriteMask;
        // With exportData set and scalarWriteMask covering every bit of
        // vectorWriteMask the EFFECTIVE vector write mask is 0, so the vector
        // write arm at :1496 is skipped, EmitOperand is never called, and
        // NoteOperand never fires -- even though both RAW write masks are
        // non-zero. Every one of the 25 prints `vwm=0xE swm=0xF export=1` or
        // `vwm=0x0 swm=0x8 export=1`, i.e. effective 0x0.
        //
        // `none` is the honest entry for such a register: it has no declaration,
        // so it has no seed, and printing `0.0` would be as false as printing
        // `interpolant<N>` was. `none` is already this row's own vocabulary --
        // the `emittedReads` field below prints it for an empty list -- so no new
        // token enters the log and no tracked marker's name appears here.
        //
        // LOG-ONLY. This changes which string a field prints and nothing else.
        // `AppendRegisters`, `AppendSignature` and the emitted body are all
        // untouched, so no declaration, no input element and no shader value
        // can move.
        uint32_t interpReg = 0xFFFFFFFFu;
        const bool declared =
            r < referenced.size() && referenced[r];
        if (declared) {
            for (const auto& in : prog.interpolators)
                if (in.reg == r) { interpReg = in.usageIndex; break; }
        }
        if (!seeds.empty()) seeds += ",";
        if (!declared) {
            seeds += "none";
            seedsUniformZero = false;
        } else if (interpReg != 0xFFFFFFFFu) {
            seeds += "interpolant" + std::to_string(interpReg);
            seedsUniformZero = false;
        } else {
            seeds += "0.0";
        }
    }
    if (regs.empty()) return;  // nothing unwritten is read; no row is owed.

    static std::atomic<uint32_t> seq{0};
    const uint32_t n = seq.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (n > 8u && (n % 200u) != 0u) return;

    // The appended clause. `psNumReg` and the two count terms are already on
    // `prog`; the two masks are only meaningful with a pairing, and a null pairing
    // prints them as the absent state rather than as a zero that looks measured.
    std::string rule = "no-vs-pairing";
    if (pairing != nullptr) {
        rule = std::string(pairing->vsKnown ? "vs-known " : "vs-unknown ") +
               "vsWrites=0x" + [pairing]() {
                   char buf[16];
                   std::snprintf(buf, sizeof(buf), "%08X",
                                 pairing->vsWritesInterpolators);
                   return std::string(buf);
               }() +
               " psInputMask=0x" + [pairing]() {
                   char buf[16];
                   std::snprintf(buf, sizeof(buf), "%08X", pairing->psInputMask);
                   return std::string(buf);
               }() +
               " intersected=0x" + [pairing]() {
                   char buf[16];
                   std::snprintf(buf, sizeof(buf), "%08X", pairing->intersected);
                   return std::string(buf);
               }() +
               " psNumReg=" + std::to_string(pairing->psNumReg) +
               " staticBound=" + std::to_string(pairing->staticBound) +
               " dynRegCount=" + std::to_string(pairing->dynamicRegCount) +
               " interpCount=" + std::to_string(pairing->interpolatorCount) +
               " kept=" + std::to_string(pairing->kept) + "/" +
               std::to_string(pairing->candidatesBefore);
    }

    MCLA_LOG_WARN(
        "SHADER-UNWRITTEN-REG-READ #{} stage={} regs=[{}] emittedReads=[{}] "
        "seed={} readTotal={} writeTotal={} -- every register in regs is READ "
        "by a guest instruction and NO guest instruction writes it, so its value "
        "is not in the binary and the translator supplies the seed listed in the "
        "seed field, per register. That seed is the reference's own: an unwritten "
        "GPR takes interpolant N when bit N is in interpolator_mask and 0.0 "
        "otherwise (spirv_shader_translator.cc:2052-2070, and "
        "dxbc_shader_translator.cc:685-701 on the DXBC path this backend follows), "
        "where interpolator_mask = VS.writes_interpolators() & "
        "PS.GetInterpolatorInputMask(...) (vulkan_command_processor.cc:2206-2211, "
        "d3d12/d3d12_command_processor.cc:2081-2086). emittedReads is the subset "
        "the generated HLSL actually touches; a register in regs but not "
        "emittedReads had its reads dropped because its write mask was 0. NOT a "
        "fabricated colour: a register nobody wrote has no guest value, and an "
        "interpolant seed is a value the paired VS exported. [seedRule={}]",
        n, ps ? "pixel" : "vertex", regs,
        emitted.empty() ? "none" : emitted,
        seedsUniformZero ? std::string("0.0") : seeds,
        readTotal, writeTotal, rule);
}

// HLSL generator for one shader program. Not thread-safe; one instance per
// translation.
class HlslGenerator {
public:
    HlslGenerator(const ShaderProgram& prog, std::string& out,
                  uint64_t& unsupported)
        : prog_(prog), out_(out), unsupported_(unsupported) {
        for (const auto& c : prog_.constants) {
            if (c.info.registerSet == RegisterSet::Sampler)
                samplerConstants_.emplace(c.info.registerIndex, &c);
        }
    }

    // F-609 item 4. Set before Generate(); a null pointer means "no pin", which
    // is the pre-existing behaviour (semantics from fetch resolution only).
    void SetVertexInputLayout(const VertexInputSemantic* layout, size_t count) {
        layout_ = layout;
        layoutCount_ = count;
    }

    // The per-draw interpolator intersection TranslateShaderImpl already applied to
    // `prog_` (ApplyInterpolatorIntersection), handed over so the seed marker can
    // report the arithmetic rather than only its result. A null pointer means "no
    // pairing was attempted", which is what a VERTEX translation is.
    void SetPairingReport(const InterpolatorIntersection* report) {
        pairing_ = report;
    }

    const std::string& error() const { return error_; }

    bool Generate() {
        out_.clear();
        error_.clear();
        const bool ps = !prog_.isVertex;

        // Unique identifiers for named constants, built once so the cbuffer
        // declaration and every operand reference agree. Guest tables can
        // contain duplicate names at different registers (e.g. two "ler");
        // later duplicates get a numeric suffix.
        BuildConstantNames();

        // Pass 1: emit the body into a scratch buffer, recording every
        // register / constant / export / input it references (the real emitter
        // is the source of truth for its own references). Pass 2 then declares
        // exactly that set and pastes the cached body back, so nothing is
        // undeclared and nothing is invented.
        std::string body;
        {
            std::string scratch;
            scratch.swap(out_);      // out_ -> empty; scratch holds caller's old text
            ResetAnalysis();
            AppendBody(ps);          // writes into the caller's (now empty) buffer
            body.swap(out_);         // cache the generated body
            out_.swap(scratch);      // restore caller's buffer to empty
        }

        // Pin the VS entry signature to the authoritative input layout BEFORE
        // AppendSignature emits it (see PinVertexInputSemantics). A pin that
        // cannot bind an input is a refusal: emitting a semantic the layout does
        // not supply produces a PSO-create failure or a garbage vertex, and
        // there is no third honest option.
        if (!ps && layout_ != nullptr) {
            if (!PinVertexInputSemantics(layout_, layoutCount_)) {
                error_ = "TranslateShaderPinned: a vertex fetch resolved to a semantic the "
                         "authoritative input layout does not supply";
                out_.clear();
                return false;
            }
        }

        AppendHeader(ps);
        AppendSignature(ps);
        AppendRegisters(ps);
        // After AppendRegisters, so the 0.0 seed this row reports is already
        // decided, and referencedRegisters_ is final (pass 1 ran above). Placed
        // on the success path only: the pin refusal returns earlier, and this
        // marker is new, so no existing marker's cadence can be shortened by it.
        LogUnwrittenRegisterReads(prog_, ps, referencedRegisters_, pairing_);
        out_ += body;
        AppendEpilogue(ps);
        out_ += "}\n";
        return true;
    }

    // Whether AppendEpilogue emitted the clip_disable rescale (see the
    // TranslatedShader::clipRescaleBaked comment in shader_translator.h). Read
    // after Generate(); it reports what the epilogue DID rather than re-reading
    // the process global, so it cannot drift from the emitted HLSL.
    bool clipRescaleBaked() const { return clipRescaleBaked_; }

    // The TEXTUAL shape of the position output, as a classification decided while
    // emitting (see AppendEpilogue). Empty for a pixel program, which writes no
    // position. This is a NAME for the emitted code, never a value: F-609 forbids
    // reporting a position this file derived rather than one the pipeline produced,
    // and D3D12 offers no shader-output readback that could produce one.
    const std::string& oPosShape() const { return oPosShape_; }
    // The TEXT of the write that produces it, quoted from out_ rather than
    // reconstructed, so the two cannot disagree.
    std::string oPosWriteExpression() const { return oPosWriteExpression_; }

private:
    const ShaderProgram& prog_;
    std::string& out_;
    uint64_t& unsupported_;
    // True until AppendEpilogue withholds the rescale. Initialised TRUE, not
    // false: a pixel program writes no position, so nothing is ever withheld
    // and the flag must not read as "something was missing" for a stage the
    // transform does not apply to.
    bool clipRescaleBaked_ = true;
    // Set by AppendEpilogue. Both are TEXT/classification, never numbers: see the
    // oPosShape() comment above and AppendEpilogue's own block.
    std::string oPosShape_;
    std::string oPosWriteExpression_;
    std::unordered_map<uint32_t, const ConstantEntry*> samplerConstants_;

    // What the body referenced during emission (see Generate pass 1). Used to
    // declare exactly that set: which registers/constants the body reads, which
    // export surfaces it writes (PS color/depth regs, VS interpolator dests),
    // and which VS inputs its fetches resolve to.
    std::vector<bool> referencedRegisters_;      // index -> used
    std::set<uint32_t> referencedConstants_;     // c-registers referenced
    std::set<uint32_t> psExportRegs_;            // 0-3 (oC) or 61 (oDepth)
    std::set<uint32_t> vsExportDests_;           // VS export vectorDest values
    std::vector<VertexInputRef> vsInputs_;       // VS entry inputs (first-fetch order)
    // Authoritative input layout, or null for the unpinned path.
    const VertexInputSemantic* layout_ = nullptr;
    size_t layoutCount_ = 0;
    // Per-draw interpolator intersection report, or null when none was attempted.
    const InterpolatorIntersection* pairing_ = nullptr;
    std::string error_;

    void ResetAnalysis() {
        referencedRegisters_.assign(kRegisterCount, false);
        referencedConstants_.clear();
        psExportRegs_.clear();
        vsExportDests_.clear();
        vsInputs_.clear();
    }

    void NoteRegister(uint32_t r) {
        if (r < kRegisterCount) referencedRegisters_[r] = true;
    }
    void NoteConstant(uint32_t c) {
        referencedConstants_.insert(c);
    }
    // Record an operand exactly as EmitOperand resolves it: a register read
    // (select) with the high mask bits stripped, or a constant c{N} read.
    void NoteOperand(uint32_t reg, bool select) {
        if (select) {
            NoteRegister(reg & 0x3F);
        } else {
            NoteConstant(reg);
        }
    }
    void NoteExport(bool ps, uint32_t vectorDest) {
        if (ps) psExportRegs_.insert(vectorDest);
        else vsExportDests_.insert(vectorDest);
    }
    // Record a VS vertex-fetch input reference, deduped by (usage, usageIndex)
    // so the entry signature lists each resolved input once.
    void NoteVertexInput(uint32_t usage, uint32_t usageIndex) {
        if (usage >= 14) usage = 0;  // clamp, mirroring the operand fallback
        for (const auto& in : vsInputs_) {
            if (in.usage == usage && in.usageIndex == usageIndex) return;
        }
        vsInputs_.push_back(VertexInputRef{usage, usageIndex, 0, 0, 0});
    }

    // F-609 item 4: pin each entry-signature input's SEMANTIC to the
    // authoritative input layout. The parameter name (iPosition0) is already
    // resolved by the fetch; only the `: SEMANTICn` it is bound to can
    // disagree with the layout, and that disagreement is what produced
    // POSITION0-vs-TEXCOORDn PSO failures. Returns false when an input has no
    // counterpart in the layout, which is a refusal, not a guess.
    bool PinVertexInputSemantics(const VertexInputSemantic* layout, size_t count) {
        for (auto& in : vsInputs_) {
            bool bound = false;
            // 1. exact (usage, usageIndex)
            for (size_t i = 0; i < count && !bound; ++i) {
                if (layout[i].usage == in.usage && layout[i].usageIndex == in.usageIndex) {
                    in.usage = layout[i].usage;
                    in.usageIndex = layout[i].usageIndex;
                    bound = true;
                }
            }
            // 2. the layout's ONLY element with this usage. Refused when the
            //    usage appears more than once: picking one would be arbitrary.
            if (!bound) {
                size_t matches = 0;
                size_t matchIndex = 0;
                for (size_t i = 0; i < count; ++i) {
                    if (layout[i].usage != in.usage) continue;
                    ++matches;
                    matchIndex = i;
                    if (matches > 1) break;
                }
                if (matches == 1) {
                    in.usage = layout[matchIndex].usage;
                    in.usageIndex = layout[matchIndex].usageIndex;
                    bound = true;
                }
            }
            if (!bound) return false;
        }
        // Two inputs pinned onto one semantic would emit a signature with a
        // duplicated SEMANTICn. D3D12 rejects that at PSO creation with an opaque
        // "input layout does not match shader" error; refuse here with a reason.
        for (size_t i = 0; i < vsInputs_.size(); ++i) {
            for (size_t j = i + 1; j < vsInputs_.size(); ++j) {
                if (vsInputs_[i].usage == vsInputs_[j].usage &&
                    vsInputs_[i].usageIndex == vsInputs_[j].usageIndex)
                    return false;
            }
        }
        return true;
    }

    // ---- helpers ----------------------------------------------------------

    static bool IsIdentifierStart(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }
    static bool IsIdentifier(char c) {
        return IsIdentifierStart(c) || (c >= '0' && c <= '9');
    }
    // Return a valid HLSL identifier for a constant name, or empty.
    static std::string SanitizedName(const std::string& name) {
        if (name.empty() || !IsIdentifierStart(name[0])) return {};
        for (char c : name)
            if (!IsIdentifier(c)) return {};
        return name;
    }

    // The named float4 constant whose register range contains `reg`, or
    // nullptr when the guest has no nameable constant covering that register
    // (unnamed entry or bogus index). Used by the operand emitter so every
    // c{N} reference stays consistent with the cbuffer declarations.
    const ConstantEntry* FindNamedConstant(uint32_t reg) const {
        for (const auto& c : prog_.constants) {
            if (c.info.registerSet != RegisterSet::Float4) continue;
            if (SanitizedName(c.name).empty()) continue;
            const uint32_t base = c.info.registerIndex;
            const uint32_t count = std::max<uint32_t>(c.info.registerCount, 1);
            if (reg >= base && reg < base + count) return &c;
        }
        return nullptr;
    }
    bool NamedConstantCovers(uint32_t reg) const {
        return FindNamedConstant(reg) != nullptr;
    }

    // Guest constant tables can name multiple float4 entries identically at
    // different registers; a cbuffer cannot redeclare an identifier. Build a
    // per-register unique name once (first use keeps the guest name, later
    // duplicates get "_<reg>") so declarations and operand references agree.
    std::unordered_map<uint32_t, std::string> constantNames_;

    void BuildConstantNames() {
        constantNames_.clear();
        std::set<std::string> used;
        for (const auto& c : prog_.constants) {
            if (c.info.registerSet != RegisterSet::Float4) continue;
            std::string name = SanitizedName(c.name);
            if (name.empty()) continue;
            if (used.count(name))
                name += "_" + std::to_string(c.info.registerIndex);
            used.insert(name);
            constantNames_[c.info.registerIndex] = name;
        }
    }
    std::string ConstantName(uint32_t registerIndex) const {
        auto it = constantNames_.find(registerIndex);
        return it != constantNames_.end() ? it->second : std::string{};
    }
    static std::string RegName(uint32_t reg) {
        return "r" + std::to_string(reg);
    }

    // Build an operand string for `kind`, following the reference op().
    std::string EmitOperand(const DecodedInstruction& instr, OperandKind kind) {
        uint32_t reg = 0;
        uint32_t swizzle = 0;
        bool select = true;
        bool negate = false;
        bool abs = false;

        switch (kind) {
        case OperandKind::ScalarConstant0:
            reg = instr.src3Register;
            swizzle = instr.src3Swizzle;
            select = false;
            negate = instr.src3Negate;
            abs = instr.absConstants;
            break;
        case OperandKind::ScalarConstant1:
            reg = (uint32_t(instr.scalarOpcode) & 1) |
                  (uint32_t(instr.src3Select) << 1) |
                  (instr.src3Swizzle & 0x3C);
            swizzle = instr.src3Swizzle;
            select = true;
            negate = instr.src3Negate;
            abs = instr.absConstants;
            break;
        default:
            switch (kind) {
            case OperandKind::Vector0:
                reg = instr.src1Register;
                swizzle = instr.src1Swizzle;
                select = instr.src1Select;
                negate = instr.src1Negate;
                break;
            case OperandKind::Vector1:
                reg = instr.src2Register;
                swizzle = instr.src2Swizzle;
                select = instr.src2Select;
                negate = instr.src2Negate;
                break;
            default:  // Vector2 / Scalar0 / Scalar1
                reg = instr.src3Register;
                swizzle = instr.src3Swizzle;
                select = instr.src3Select;
                negate = instr.src3Negate;
                break;
            }
            if (select) {
                abs = (reg & 0x80) != 0;
                reg &= 0x3F;
            } else {
                abs = instr.absConstants;
            }
            break;
        }

        std::string regFormatted;
        // Record the reference exactly as resolved (register vs constant) so
        // the declarations in pass 2 cover every operand the body emits.
        NoteOperand(reg, select);
        if (select) {
            regFormatted = "r" + std::to_string(reg);
        } else {
            // Constant operand. Named entries resolve by name (arrays by index);
            // anything else falls back to the declared c{N} registers.
            const ConstantEntry* named = FindNamedConstant(reg);
            if (named) {
                const std::string name =
                        ConstantName(named->info.registerIndex);
                if (name.empty()) {
                    regFormatted = "c" + std::to_string(reg);
                } else if (named->info.registerCount > 1) {
                    // Named array constant; relative addressing appends aL/a0.
                    uint32_t offset = reg - named->info.registerIndex;
                    std::string idx = std::to_string(offset);
                    if (instr.const0Relative)
                        idx += instr.constAddressRegisterRelative ? " + a0" : " + aL";
                    regFormatted = name + "[" + idx + "]";
                } else {
                    regFormatted = name;
                }
            } else {
                regFormatted = "c" + std::to_string(reg);
            }
        }

        std::string result;
        if (negate) result += '-';
        if (abs) result += "abs(";
        result += regFormatted;
        result += '.';

        // The swizzle is COMPONENT-RELATIVE: destination component i takes source
        // component ((swizzle >> (2*i)) + i) & 3, NOT (swizzle >> (2*i)) & 3.
        //
        // MEASURED, not inferred from the field name. The reference chain is
        // shader.h:118-123 (GetSwizzledAluSourceComponent) ->
        // ucode::AluInstruction::GetSwizzledComponentIndex at ucode.h:1999-2003,
        // whose body is `((swizzle >> (2 * component_index)) + component_index) & 3`,
        // with the comment "Swizzles are component-relative" at ucode.h:2068. The
        // `+ component_index` is the whole difference and it is load-bearing: for
        // the identity swizzle 0 the reference returns component_index (xyzw), and
        // the old expression below returned 0 for all four (xxxx).
        //
        // WHAT IT WAS DOING, measured on draw #1's real vertex program
        // (build/w710.log:6599 CP-SHADER-BODY #3, 27 dwords, hash-verified against
        // DRAW-CP-PIPE #1's vsHash=22BB5C3AE64A3D71 at w710.log:6735): the oPos
        // export is instruction [3], src1Swizzle=0x0, vectorWriteMask=15,
        // vectorDest=62. It emitted
        //     oPos.xyzw = max(r1.xxxx, r1.xxxx);
        // so oPos.x, oPos.y and oPos.z ALL received iPosition0.x and the guest's Y
        // and Z never reached the output at all. With the correct component-relative
        // read the same instruction emits
        //     oPos.xyzw = max(r1.xyzw, r1.xyzw);
        // Falsifier for the fix: if the identity swizzle 0x00 did NOT mean `xyzw`,
        // then a real program whose export swizzle is 0 would still be mis-emitted.
        // The check that settles it is %TEMP%\opencode\opos_h\gs2.txt, which prints
        // both spellings side by side for the measured 0x0.
        auto swizzledComponent = [swizzle](uint32_t i) {
            return ((swizzle >> (2u * i)) + i) & 0x3u;
        };

        switch (kind) {
        case OperandKind::Vector0:
        case OperandKind::Vector1:
        case OperandKind::Vector2: {
            uint32_t mask;
            switch (instr.vectorOpcode) {
            case AluVectorOpcode::Dp2Add:
                mask = (kind == OperandKind::Vector2) ? 0b1 : 0b11;
                break;
            case AluVectorOpcode::Dp3:
                mask = 0b111;
                break;
            case AluVectorOpcode::Dp4:
            case AluVectorOpcode::Max4:
                mask = 0b1111;
                break;
            default:
                mask = instr.vectorWriteMask != 0 ? instr.vectorWriteMask : 0b1;
                break;
            }
            for (uint32_t i = 0; i < 4; i++) {
                if ((mask >> i) & 0x1)
                    result += kSwizzle[swizzledComponent(i)];
            }
            break;
        }
        case OperandKind::Scalar0:
        case OperandKind::ScalarConstant0:
            // A scalar operand is the component the reference reads with a FIXED
            // index, not with the destination index: shader_translator.cc:1244 and
            // :1448 pass 3 (the W slot) for Scalar0/ScalarConstant0, and :1248
            // passes 0 (the X slot) for the X half of a 2-component scalar pair.
            result += kSwizzle[swizzledComponent(3)];
            break;
        case OperandKind::Scalar1:
        case OperandKind::ScalarConstant1:
            // shader_translator.cc:1247-1248: components[0] is read at index 3 and
            // components[1] at index 0, so the 2-component case is emitted by this
            // case using its own fixed indices below.
            result += kSwizzle[swizzledComponent(0)];
            break;
        }

        if (abs) result += ')';
        return result;
    }

    static std::string ExportRegisterName(const DecodedInstruction& instr,
                                          uint32_t reg) {
        // Xenos export registers: 0-3 -> color, 61 -> depth.
        if (reg <= 3) return "oC" + std::to_string(reg);
        if (reg == 61) return "oDepth";
        return {};
    }

    // ---- header / setup ---------------------------------------------------

    void AppendHeader(bool ps) {
        out_ += "// Xenos -> HLSL (mcla::renderer Phase 5 translation)\n";
        out_ += "#define FLT_MIN 1.17549435e-38\n";
        out_ += "#define FLT_MAX 3.40282346e+38\n";
        out_ += "\n";
        // Xenos Cnd ops emit select(cond, a, b). The guest instruction is a
        // PER-COMPONENT conditional move -- Xenia's own words, at
        // .research/xenia/src/xenia/gpu/ucode.h:1459-1465:
        //   "Per-Component Floating-Point Conditional Move If Equal /
        //    cndeq dest, src0, src1, src2
        //        dest.x = src0.x == 0.0 ? src1.x : src2.x;  (and .y/.z/.w likewise)"
        // and its interpreter loops i=0..3 over every lane
        // (.research/xenia/src/xenia/gpu/shader_interpreter.cc:415-421), with the
        // SPIR-V path emitting spv::OpSelect per component.
        //
        // So the condition must select lane by lane. `c ? a : b` is a UNIFORM (scalar)
        // select, which is both semantically wrong here and rejected by HLSL outright:
        //   "condition for short-circuiting ternary operator must be scalar, for
        //    non-scalar types use 'select'"
        // That was the whole of the failure: all 517 dumped programs stopped at this
        // prelude. The three vector-condition overloads are now componentwise.
        //
        // Condition arity: EmitOperand builds the predicate from the CND vector write
        // mask, so the condition is 1/2/3/4 lanes wide and each lane is POSITIONAL --
        // condition component j tests data component j. Measured over the 517-program
        // dump set, 1-, 2-, 3- and 4-lane swizzles all occur (e.g. 'z', 'xz', 'yxz',
        // 'xwzz'), so all four widths must be live.
        //
        // DECLARED SIMPLIFICATION: lanes past the condition's width are outside the
        // guest write mask, so the hardware never writes them -- they are don't care.
        // They are filled from `b` here, preserving the previous bool4(c,false,..)
        // padding. Emitting a full-width predicate would be exact rather than
        // don't-care, but it would change the translated BODY, which is out of scope
        // here (the body must stay byte-identical across this fix).
        out_ += "float4 select(bool4 c, float4 a, float4 b) { return float4(c.x ? a.x : b.x, c.y ? a.y : b.y, c.z ? a.z : b.z, c.w ? a.w : b.w); }\n";
        out_ += "float4 select(bool3 c, float4 a, float4 b) { return float4(c.x ? a.x : b.x, c.y ? a.y : b.y, c.z ? a.z : b.z, false ? a.w : b.w); }\n";
        out_ += "float4 select(bool2 c, float4 a, float4 b) { return float4(c.x ? a.x : b.x, c.y ? a.y : b.y, false ? a.z : b.z, false ? a.w : b.w); }\n";
        // A scalar condition broadcast across a vector IS the per-component select
        // HLSL already means, so these three were legal and correct as written.
        out_ += "float4 select(bool c, float4 a, float4 b) { return c ? a : b; }\n";
        out_ += "float3 select(bool c, float3 a, float3 b) { return c ? a : b; }\n";
        out_ += "float2 select(bool c, float2 a, float2 b) { return c ? a : b; }\n";
        out_ += "float select(bool c, float a, float b) { return c ? a : b; }\n";
        out_ += "\n";

        // Constant table. Float4 constants are named where the guest provides
        // a valid identifier; otherwise they fall back to c{N}. The cbuffer is
        // closed over every register the body references (referencedConstants_
        // from Generate pass 1), so no operand's c{N} reference is ever left
        // undeclared.
        out_ += "cbuffer ShaderConstants : register(b0)\n{\n";
        for (const auto& c : prog_.constants) {
            if (c.info.registerSet != RegisterSet::Float4) continue;
            std::string name = ConstantName(c.info.registerIndex);
            if (name.empty()) continue;
            if (c.info.registerCount > 1) {
                out_ += "    float4 " + name + "[" +
                        std::to_string(c.info.registerCount) +
                        "] : packoffset(c" +
                        std::to_string(c.info.registerIndex) + ");\n";
            } else {
                out_ += "    float4 " + name + " : packoffset(c" +
                        std::to_string(c.info.registerIndex) + ");\n";
            }
        }
        for (uint32_t r : referencedConstants_) {
            if (NamedConstantCovers(r)) continue;
            out_ += "    float4 c" + std::to_string(r) + " : packoffset(c" +
                    std::to_string(r) + ");\n";
        }
        out_ += "};\n\n";

        // Texture/sampler binds for tfetch: the generic dimension-based
        // resources (t1D..tCube + s0) that the emitted fetches actually sample.
        std::unordered_set<uint32_t> usedSamplers;
        std::unordered_map<uint32_t, uint32_t> samplerDim;
        for (const auto& ir : prog_.instructions) {
            if (ir.isFetch &&
                ir.decoded.kind == InstructionKind::TextureFetch) {
                usedSamplers.insert(ir.decoded.constIndex);
                samplerDim[ir.decoded.constIndex] = ir.decoded.dimension;
            }
        }
        if (!usedSamplers.empty()) {
            out_ += "Texture1D   t1D  : register(t0);\n";
            out_ += "Texture2D   t2D  : register(t1);\n";
            out_ += "Texture3D   t3D  : register(t2);\n";
            out_ += "TextureCube tCube : register(t3);\n";
            out_ += "SamplerState s0 : register(s0);\n\n";
            // A Texture2D tex_<slot> placeholder is declared per sampler slot
            // tfetch uses, bound at register(t<slot>). The name is derived
            // from the slot index only (the sampler-table lookup does not
            // change it) and the emitted body never references these — the
            // fetches sample the generic resources above.
            for (uint32_t index : usedSamplers) {
                auto it = samplerConstants_.find(index);
                const char* dimName =
                    samplerDim[index] == 3 ? "t3D"
                    : samplerDim[index] == 2 ? "tCube"
                    : samplerDim[index] == 1 ? "t2D"
                                             : "t1D";
                std::string texName = (it != samplerConstants_.end())
                    ? "tex_" + std::to_string(index)
                    : std::string("tex_") + std::to_string(index);
                out_ += "Texture2D " + texName + " : register(t" + std::to_string(index) + ");\n";
            }
        }
    }

    void AppendRegisters(bool ps) {
        // Per-register float4 locals (a Xenos shader register is one float4).
        // Registers PS interpolators seed are declared with the seed value
        // directly; everything else starts at zero (VS fetches overwrite it).
        std::vector<bool> seeded(kRegisterCount, false);
        for (const auto& interp : prog_.interpolators)
            if (interp.reg < kRegisterCount && referencedRegisters_[interp.reg])
                seeded[interp.reg] = true;

        for (uint32_t r = 0; r < kRegisterCount; r++) {
            if (!referencedRegisters_[r] || seeded[r]) continue;
            out_ += "    float4 r" + std::to_string(r) + " = 0.0;\n";
        }
        if (ps) {
            for (const auto& interp : prog_.interpolators) {
                if (interp.reg >= kRegisterCount || !referencedRegisters_[interp.reg])
                    continue;
                const uint32_t usage = interp.usage >= 14 ? 0 : interp.usage;
                out_ += "    float4 r" + std::to_string(interp.reg) + " = i" +
                        std::string(kUsageVariables[usage]) +
                        std::to_string(interp.usageIndex) + ";\n";
            }
        }
        out_ += "    float ps = 0.0;\n";
        out_ += "    int a0 = 0;\n";
        out_ += "    int aL = 0;\n";
        out_ += "    bool p0 = false;\n";
        out_ += "\n";
    }

    // Entry point whose in/out parameter sets match the body's writes exactly
    // (collected in Generate pass 1): PS consumes iPos + interpolator inputs
    // and writes the oC*/oDepth exports it uses; VS consumes the resolved
    // vertex inputs and writes oPos plus the interpolator outputs it exports.
    void AppendSignature(bool ps) {
        out_ += "void main(\n";
        if (ps) {
            out_ += "    in float4 iPos : SV_Position,\n";
            for (const auto& interp : prog_.interpolators) {
                if (interp.reg >= kRegisterCount || !referencedRegisters_[interp.reg])
                    continue;
                const uint32_t usage = interp.usage >= 14 ? 0 : interp.usage;
                out_ += "    in float4 i" + std::string(kUsageVariables[usage]) +
                        std::to_string(interp.usageIndex) + " : " +
                        VertexUsageSemanticName(usage) +
                        std::to_string(interp.usageIndex) + ",\n";
            }
            if (psExportRegs_.count(0)) out_ += "    out float4 oC0 : SV_Target0,\n";
            if (psExportRegs_.count(1)) out_ += "    out float4 oC1 : SV_Target1,\n";
            if (psExportRegs_.count(2)) out_ += "    out float4 oC2 : SV_Target2,\n";
            if (psExportRegs_.count(3)) out_ += "    out float4 oC3 : SV_Target3,\n";
            if (psExportRegs_.count(61)) out_ += "    out float4 oDepth : SV_Depth,\n";
        } else {
            for (const auto& in : vsInputs_) {
                const uint32_t usage = in.usage >= 14 ? 0 : in.usage;
                out_ += "    in float4 i" + std::string(kUsageVariables[usage]) +
                        std::to_string(in.usageIndex) + " : " +
                        VertexUsageSemanticName(usage) +
                        std::to_string(in.usageIndex) + ",\n";
            }
            out_ += "    out float4 oPos : SV_Position,\n";
            for (uint32_t vd : vsExportDests_) {
                if (vd == 62 || vd >= 16) continue;
                out_ += "    out float4 oTexCoord" + std::to_string(vd) +
                        " : TEXCOORD" + std::to_string(vd) + ",\n";
            }
        }
        // Drop the trailing ",\n" so the last parameter has no dangling comma.
        if (out_.size() >= 2 && out_.compare(out_.size() - 2, 2, ",\n") == 0)
            out_.resize(out_.size() - 2);
        out_ += "\n)\n{\n";
    }

    // ---- body -------------------------------------------------------------

    void AppendBody(bool ps) {
        for (const auto& ir : prog_.instructions) {
            if (ir.decoded.unknown) {
                ++unsupported_;
                out_ += "    // unsupported instruction decode\n";
                continue;
            }
            if (ir.isFetch) {
                EmitFetch(ir);
            } else {
                EmitAlu(ir.decoded, ps);
            }
        }
    }

    void AppendEpilogue(bool ps) {
        if (ps) {
            // Nothing to fill: PS exports are written inline and
            // AppendSignature only declares an oC*/oDepth target that the
            // body actually wrote.
            out_ += "    // exports emitted inline\n";
            return;
        }
        // ---- VS: guest-pixel -> host clip space (see ClipDisableRescale) -----
        //
        // This REPLACES the previous `oPos.xy += float2(0.5, 0.5) * oPos.w`. That
        // line was the reference's offset_add term applied to clip space as if
        // clip space were guest pixels: with a viewport of {0,0,W,H,0,1} a clip
        // offset of 0.5 becomes W/2 = 640 pixels of shift, not half a pixel.
        //
        // The transform is applied to XYZ only and the offset is scaled by W, so
        // it happens BEFORE the perspective divide -- the same place the reference
        // puts it (spirv_shader_translator.cc:1612-1624). Nothing here reads,
        // clamps, defaults or sanitises oPos: a NaN or Inf coming out of the guest
        // program stays NaN or Inf on purpose, because hiding it would make the
        // rasterizer's silence look like a colour bug instead of a guest fact.
        if (!g_clipDisableRescale.valid) {
            // No extent has been published yet. Emit the rescale as the IDENTITY
            // rather than as a wrong constant: identity is the only choice that
            // does not assert a number nobody measured.
            //
            // MEASURED 2026-10-04, build/w707.log, and it is NOT the startup-order
            // guard the previous revision of this comment claimed. That comment
            // said the backend calls SetClipDisableViewportExtent "before any
            // real draw"; it does not. The single call site is
            // d3d12_backend.cpp:3157, INSIDE
            // D3D12Backend::DrawDynamicMeshWithPipeline (which starts at :2811),
            // and this file's translation for a draw happens earlier than that,
            // in the render thread at src/render_thread.cpp:3471. So for the
            // FIRST draw of a process the two are ordered the wrong way round:
            //   06:57:37.262  draw #1's programs translated -- w707.log:7505,
            //                  SHADER-UNWRITTEN-REG-READ #1, emitted by
            //                  LogUnwrittenRegisterReads at :586, the line
            //                  immediately above this one, so it timestamps
            //                  this call. valid == false -> IDENTITY, permanently.
            //   06:57:37.295  SetClipDisableViewportExtent(1280,720) publishes
            //                  (w707.log:8031 is the next row after it).
            //   06:57:37.298  draw #2's programs translated (w707.log:8074) --
            //                  valid == true -> the real rescale.
            // Verified offline on both real programs: given the same published
            // extent the two emit BYTE-IDENTICAL epilogues, and given the same
            // unpublished state they emit byte-identical identity epilogues
            // (%TEMP%\opencode\clipgate\run1.txt, cases A and B). The two draws
            // are indistinguishable to this function; only the publication order
            // differs. A corrected ordering therefore belongs to the call site,
            // not here -- see the handover note beside
            // TranslatedShader::clipRescaleBaked.
            //
            // One row per process, not one per translation: the condition is a
            // property of the ORDER, so every row after the first would be the
            // same fact. Names no tracked marker on purpose -- a tracked marker
            // named inside another marker's prose becomes uncountable, because
            // tools/soak_census.py counts matching LINES.
            static std::atomic<bool> s_unbakedLogged{false};
            bool expected = false;
            if (s_unbakedLogged.compare_exchange_strong(expected, true)) {
                MCLA_LOG_WARN(
                    "VS-RESCALE-UNBAKED: this vertex program's clip-space "
                    "rescale was emitted as the IDENTITY because no render-target "
                    "extent had been published when it was translated. The "
                    "program is cached under a key that does not contain the "
                    "extent, so this translation stays geometry-less for the life "
                    "of the process. Not fabricated and not a default: the extent "
                    "is not knowable at this point, and the identity asserts "
                    "nothing. The fix is to publish the extent BEFORE translating "
                    "-- the one call site is inside the first draw, which runs "
                    "after this translation. TranslatedShader::clipRescaleBaked "
                    "is false for this program.");
            }
            clipRescaleBaked_ = false;
            out_ += "    // clip_disable rescale: NO EXTENT PUBLISHED YET -- identity\n";
            out_ += "    // (see SetClipDisableViewportExtent)\n";
            return;
        }
        const ClipDisableRescale& r = g_clipDisableRescale;
        out_ += "    // guest pixels -> host clip space; draw_util.cc:362-386 + :549-552\n";
        out_ += fmt::format(
            "    oPos.xyz = oPos.xyz * float3({}, {}, {})\n", FloatLit(r.scaleX),
            FloatLit(r.scaleY), FloatLit(r.scaleZ));
        out_ += fmt::format(
            "               + float3({}, {}, {}) * oPos.w;\n", FloatLit(r.offsetX),
            FloatLit(r.offsetY), FloatLit(r.offsetZ));

        // What the geometry stage will read out of this program, as TEXT. F-609:
        // the TEXT is reported, never a value derived from it -- D3D12 has no
        // shader-output readback, so anything numeric here would be this file's
        // own arithmetic wearing the pipeline's clothes.
        //
        // WHAT oPos IS, measured from the emitted HLSL of a real program and not
        // from the field name. Draw #1's vertex microcode (build/w710.log:6599,
        // CP-SHADER-BODY #3, 27 dwords; the container this file emits for it
        // reproduces DRAW-CP-PIPE #1's vsHash=22BB5C3AE64A3D71 at w710.log:6735)
        // emits exactly:
        //
        //     r1.xyz = iPosition0.xyz;
        //     r1.w   = 1.0f;
        //     oPos.xyzw = max(r1.xyzw, r1.xyzw);
        //     oPos.xyz = oPos.xyz * float3(0.0015625, -0.0027777778, 1)
        //                + float3(-0.99921876, 0.99861115, 0) * oPos.w;
        //
        // So oPos is a CLIP-SPACE position (host/NDC, post-rescale), XYZ scaled
        // and W-multiplied exactly as the reference's epilogue does
        // (spirv_shader_translator.cc:1612-1624, dxbc_shader_translator.cc:1058-1068),
        // with W left as the guest wrote it. It is NOT a rectangle tuple, NOT a
        // centre+extent, and NOT guest pixels by the time the GS reads it.
        //
        // The geometry stage reads it as THREE CORNERS of a rectangle and mirrors
        // a fourth, not as a rect: pipeline_cache.cc:2550-2694 picks the longest
        // edge, then emits v0,v1,v2 and v3 = -v0+v1+v2 (:2669-2674), passing each
        // input position through unchanged (:2636-2637). W is used by the
        // rectangle case only through that same linear combination; the
        // point-sprite case is the one that scales a radius by W (:2502-2503).
        // That is why the rescale belongs in the VS epilogue rather than at the
        // GS output: an affine map on (x,y) commutes with the mirroring, so a
        // rectangle stays a rectangle either way, and the reference puts it in the
        // epilogue in both of its own backends.
        oPosShape_ = "clipSpacePosition";
        // The TEXT of every emitted line that assigns oPos, quoted out of out_
        // after the fact rather than re-formatted, so this can never claim a
        // different expression from the one the compiler will see. Leading
        // whitespace and the trailing newline are dropped; the text itself is
        // untouched. A pixel program's AppendEpilogue returns before here, so
        // this stays empty for it and no row claims a position it never wrote.
        // Collect the STATEMENTS that assign oPos. Split on `;`, not on newlines: the
        // epilogue emits its rescale as two physical lines, so a per-line scan
        // reported it twice (the harness printed the same line twice before this)
        // and a reader could not tell one write from two.
        //
        // Each piece is a verbatim substring of out_ with only the leading
        // indentation dropped; nothing is re-formatted, renamed or re-derived, so
        // the row cannot claim an expression the compiler will not see. An
        // assignment spanning two lines has its interior newline collapsed to one
        // space, which is whitespace and changes nothing about the code.
        oPosWriteExpression_.clear();
        {
            bool open = false;  // inside an assignment whose `;` has not arrived
            size_t pos = 0;
            bool armed = false;  // seen `oPos` as an assignment TARGET at least once
            while (pos < out_.size()) {
                const size_t eol = out_.find('\n', pos);
                const size_t stop = (eol == std::string::npos ? out_.size() : eol);
                std::string line = out_.substr(pos, stop - pos);
                const bool isDecl =
                        line.find("out float4 oPos : SV_Position") !=
                        std::string::npos;
                size_t b = line.find_first_not_of(" \t");
                if (b == std::string::npos) b = 0;
                line = line.substr(b);
                // The DECLARATION arms the collector: `out float4 oPos : ...` is
                // the only place oPos comes into scope, so until that line is
                // passed nothing else in the body can be a write to it. Without
                // the arm, every earlier line containing an `=` (the register
                // declarations, and the fetches that assign r0/r1) was collected
                // too -- the harness printed 11 statements before this, including
                // `float4 r0 = 0.0;`, which says nothing about the position.
                const bool writesOPos =
                        line.rfind("oPos", 0) == 0 &&   // statement starts with it
                        line.find('=') != std::string::npos;
                if (isDecl) {
                    armed = true;
                    open = false;
                } else if (armed && !line.empty()) {
                    if (open) {
                        oPosWriteExpression_ += " " + line;
                    } else if (writesOPos) {
                        if (!oPosWriteExpression_.empty())
                            oPosWriteExpression_ += " | ";
                        oPosWriteExpression_ += line;
                        open = true;
                    } else {
                        open = false;
                    }
                    if (open && line.find(';') != std::string::npos) open = false;
                }
                pos = stop + 1;
            }
        }
        // Normalise interior whitespace runs so a wrapped statement reads as one
        // line. Whitespace only; no token is touched.
        {
            std::string flat;
            flat.reserve(oPosWriteExpression_.size());
            bool sp = false;
            for (char ch : oPosWriteExpression_) {
                if (ch == ' ' || ch == '\t' || ch == '\r') {
                    sp = true;
                    continue;
                }
                if (sp && !flat.empty()) flat += ' ';
                sp = false;
                flat += ch;
            }
            oPosWriteExpression_ = flat;
        }
    }

    // ---- ALU lowering -----------------------------------------------------

    void EmitAlu(const DecodedInstruction& instr, bool ps) {
        const bool predicated = instr.isPredicated;

        // Kill vector ops -> clip() before any writes.
        if (instr.vectorOpcode >= AluVectorOpcode::KillEq &&
            instr.vectorOpcode <= AluVectorOpcode::KillNe) {
            const char* rel = nullptr;
            switch (instr.vectorOpcode) {
            case AluVectorOpcode::KillEq: rel = "=="; break;
            case AluVectorOpcode::KillGt: rel = ">"; break;
            case AluVectorOpcode::KillGe: rel = ">="; break;
            case AluVectorOpcode::KillNe: rel = "!="; break;
            default: break;
            }
            if (rel) {
                out_ += "    clip(any(" + EmitOperand(instr, OperandKind::Vector0) +
                        " " + rel + " " + EmitOperand(instr, OperandKind::Vector1) +
                        ") ? -1.0 : 1.0);\n";
            }
        }

        const bool openIf = predicated;
        if (openIf) {
            out_ += std::string("    if (") + (instr.predicateCondition ? "" : "!") +
                    "p0)\n    {\n";
        }

        // Export register: writes go to the export target when exportData.
        std::string exportReg;
        if (instr.exportData) {
            if (ps) {
                exportReg = ExportRegisterName(instr, instr.vectorDest);
            } else {
                // Xenos VS export registers: 62 = position, 0-15 =
                // VSInterpolator0..15, 63 = point-size/edge-flag/kill vertex.
                // The 63 write has no color output and is suppressed below.
                if (instr.vectorDest == 62) {
                    exportReg = "oPos";
                } else if (instr.vectorDest < 16) {
                    exportReg = "oTexCoord" + std::to_string(instr.vectorDest);
                }
            }
        }

        // Setp (predicate push).
        if (instr.vectorOpcode >= AluVectorOpcode::SetpEqPush &&
            instr.vectorOpcode <= AluVectorOpcode::SetpGePush) {
            const char* rel = nullptr;
            switch (instr.vectorOpcode) {
            case AluVectorOpcode::SetpEqPush: rel = "=="; break;
            case AluVectorOpcode::SetpNePush: rel = "!="; break;
            case AluVectorOpcode::SetpGtPush: rel = ">"; break;
            case AluVectorOpcode::SetpGePush: rel = ">="; break;
            default: break;
            }
            out_ += "    p0 = " + EmitOperand(instr, OperandKind::Vector0) +
                    " == 0.0 && " + EmitOperand(instr, OperandKind::Vector1) +
                    " " + rel + " 0.0;\n";
        }

        // MaxA -> address register write.
        if (instr.vectorOpcode == AluVectorOpcode::MaxA) {
            out_ += "    a0 = (int)clamp(floor(" +
                    EmitOperand(instr, OperandKind::Vector0) + ".w + 0.5), -256.0, 255.0);\n";
        }

        // Vector write.
        uint32_t vectorWriteMask = instr.vectorWriteMask;
        if (instr.exportData) vectorWriteMask &= ~instr.scalarWriteMask;

        // VS export 63 is point-size/edge-flag/kill-vertex state with no color
        // output; drop the write rather than emitting an undeclared r63.
        const bool suppressVsExport =
                instr.exportData && !ps && instr.vectorDest == 63;

        if (vectorWriteMask != 0 && !suppressVsExport) {
            std::string dst;
            if (!exportReg.empty()) {
                dst = exportReg;
                NoteExport(ps, instr.vectorDest);
            } else {
                dst = RegName(instr.vectorDest);
                NoteRegister(instr.vectorDest);
            }
            dst += '.';
            for (uint32_t i = 0; i < 4; i++) {
                if ((vectorWriteMask >> i) & 0x1) dst += kSwizzle[i];
            }

            out_ += "    " + dst + " = ";
            if (instr.vectorSaturate) out_ += "saturate(";

            switch (instr.vectorOpcode) {
            case AluVectorOpcode::Add:
                out_ += EmitOperand(instr, OperandKind::Vector0) + " + " +
                        EmitOperand(instr, OperandKind::Vector1);
                break;
            case AluVectorOpcode::Mul:
                out_ += EmitOperand(instr, OperandKind::Vector0) + " * " +
                        EmitOperand(instr, OperandKind::Vector1);
                break;
            case AluVectorOpcode::Max:
            case AluVectorOpcode::MaxA:
                out_ += "max(" + EmitOperand(instr, OperandKind::Vector0) + ", " +
                        EmitOperand(instr, OperandKind::Vector1) + ")";
                break;
            case AluVectorOpcode::Min:
                out_ += "min(" + EmitOperand(instr, OperandKind::Vector0) + ", " +
                        EmitOperand(instr, OperandKind::Vector1) + ")";
                break;
            case AluVectorOpcode::Seq:
                out_ += EmitOperand(instr, OperandKind::Vector0) + " == " +
                        EmitOperand(instr, OperandKind::Vector1);
                break;
            case AluVectorOpcode::Sgt:
                out_ += EmitOperand(instr, OperandKind::Vector0) + " > " +
                        EmitOperand(instr, OperandKind::Vector1);
                break;
            case AluVectorOpcode::Sge:
                out_ += EmitOperand(instr, OperandKind::Vector0) + " >= " +
                        EmitOperand(instr, OperandKind::Vector1);
                break;
            case AluVectorOpcode::Sne:
                out_ += EmitOperand(instr, OperandKind::Vector0) + " != " +
                        EmitOperand(instr, OperandKind::Vector1);
                break;
            case AluVectorOpcode::Frc:
                out_ += "frac(" + EmitOperand(instr, OperandKind::Vector0) + ")";
                break;
            case AluVectorOpcode::Trunc:
                out_ += "trunc(" + EmitOperand(instr, OperandKind::Vector0) + ")";
                break;
            case AluVectorOpcode::Floor:
                out_ += "floor(" + EmitOperand(instr, OperandKind::Vector0) + ")";
                break;
            case AluVectorOpcode::Mad:
                out_ += EmitOperand(instr, OperandKind::Vector0) + " * " +
                        EmitOperand(instr, OperandKind::Vector1) + " + " +
                        EmitOperand(instr, OperandKind::Vector2);
                break;
            case AluVectorOpcode::CndEq:
                out_ += "select(" + EmitOperand(instr, OperandKind::Vector0) +
                        " == 0.0, " + EmitOperand(instr, OperandKind::Vector1) + ", " +
                        EmitOperand(instr, OperandKind::Vector2) + ")";
                break;
            case AluVectorOpcode::CndGe:
                out_ += "select(" + EmitOperand(instr, OperandKind::Vector0) +
                        " >= 0.0, " + EmitOperand(instr, OperandKind::Vector1) + ", " +
                        EmitOperand(instr, OperandKind::Vector2) + ")";
                break;
            case AluVectorOpcode::CndGt:
                out_ += "select(" + EmitOperand(instr, OperandKind::Vector0) +
                        " > 0.0, " + EmitOperand(instr, OperandKind::Vector1) + ", " +
                        EmitOperand(instr, OperandKind::Vector2) + ")";
                break;
            case AluVectorOpcode::Dp4:
            case AluVectorOpcode::Dp3:
                out_ += "dot(" + EmitOperand(instr, OperandKind::Vector0) + ", " +
                        EmitOperand(instr, OperandKind::Vector1) + ")";
                break;
            case AluVectorOpcode::Dp2Add:
                out_ += "dot(" + EmitOperand(instr, OperandKind::Vector0) + ", " +
                        EmitOperand(instr, OperandKind::Vector1) + ") + " +
                        EmitOperand(instr, OperandKind::Vector2);
                break;
            case AluVectorOpcode::Cube:
                out_ += EmitOperand(instr, OperandKind::Vector0);
                break;
            case AluVectorOpcode::Max4:
                out_ += "max(max(" + EmitOperand(instr, OperandKind::Vector0) + ".x, " +
                        EmitOperand(instr, OperandKind::Vector0) + ".y), max(" +
                        EmitOperand(instr, OperandKind::Vector0) + ".z, " +
                        EmitOperand(instr, OperandKind::Vector0) + ".w))";
                break;
            case AluVectorOpcode::SetpEqPush:
            case AluVectorOpcode::SetpNePush:
            case AluVectorOpcode::SetpGtPush:
            case AluVectorOpcode::SetpGePush:
                out_ += "p0 ? 0.0 : " + EmitOperand(instr, OperandKind::Vector0) +
                        " + 1.0";
                break;
            case AluVectorOpcode::KillEq:
            case AluVectorOpcode::KillGt:
            case AluVectorOpcode::KillGe:
            case AluVectorOpcode::KillNe:
                out_ += "0.0";
                break;
            case AluVectorOpcode::Dst:
                out_ += "float4(1.0, " + EmitOperand(instr, OperandKind::Vector1) +
                        ".y, " + EmitOperand(instr, OperandKind::Vector0) + ".z, " +
                        EmitOperand(instr, OperandKind::Vector1) + ".w)";
                break;
            default:
                ++unsupported_;
                out_ += "0.0";
                break;
            }

            if (instr.vectorSaturate) out_ += ')';
            out_ += ";\n";
        }

        // Scalar clause (skip RetainPrev: it only keeps ps alive).
        if (instr.scalarOpcode != AluScalarOpcode::RetainPrev) {
            EmitScalarClause(instr, ps, exportReg, suppressVsExport);
        }

        // Export zero/one fill: untouched vector channels get 0, overlapping
        // vector+scalar channels get 1 (reference post-pass).
        if (instr.exportData && !exportReg.empty()) {
            // MEASURED 2026-10-01: NoteExport is ALSO called here, not only in
            // the vectorWriteMask != 0 arm above. Those are different sets. On
            // CP-SHADER-BODY #1 (VA 0x82061B28, 24 dwords) raw word0
            // C800C000 at addr=4 gives vectorWriteMask=0 and scalarWriteMask=0,
            // so the arm above is skipped entirely; raw word0 C888C03E at addr=5
            // gives 8/8, and `vwm &= ~swm` (line above) makes the arm's test 0
            // again. So no export was ever noted, `vsExportDests_` stayed empty,
            // AppendSignature declared no oTexCoord0 -- and the fill below still
            // emitted `oTexCoord0.x = 0.0;`. The generated HLSL referenced an
            // undeclared identifier, i.e. a shader that cannot compile, produced
            // with ret=true and a non-empty hlsl, so every gate that tests
            // "translated && hlsl non-empty" passed it. This block is the only
            // place the body can write an export target the signature did not
            // declare, so it is the only place that must note one.
            NoteExport(ps, instr.vectorDest);
            uint32_t zeroMask =
                instr.exportData ? (0b1111 & ~(instr.vectorWriteMask | instr.scalarWriteMask)) : 0;
            uint32_t oneMask = instr.vectorWriteMask & instr.scalarWriteMask;
            for (uint32_t i = 0; i < 4; i++) {
                uint32_t mask = 1u << i;
                if (zeroMask & mask) {
                    out_ += std::string("    ") + exportReg + "." + kSwizzle[i] + " = 0.0;\n";
                } else if (oneMask & mask) {
                    out_ += std::string("    ") + exportReg + "." + kSwizzle[i] + " = 1.0;\n";
                }
            }
        }

        // Scalar Kills -> clip on ps.
        if (instr.scalarOpcode >= AluScalarOpcode::KillsEq &&
            instr.scalarOpcode <= AluScalarOpcode::KillsOne) {
            out_ += "    clip(ps != 0.0 ? -1.0 : 1.0);\n";
        }

        if (openIf) {
            out_ += "    }\n";
        }
    }

    void EmitScalarClause(const DecodedInstruction& instr, bool ps,
                          const std::string& exportReg,
                          bool suppressVsExport) {
        // Setp scalar -> predicate write.
        if (instr.scalarOpcode >= AluScalarOpcode::SetpEq &&
            instr.scalarOpcode <= AluScalarOpcode::SetpRstr) {
            out_ += "    p0 = ";
            switch (instr.scalarOpcode) {
            case AluScalarOpcode::SetpEq:
                out_ += EmitOperand(instr, OperandKind::Scalar0) + " == 0.0";
                break;
            case AluScalarOpcode::SetpNe:
                out_ += EmitOperand(instr, OperandKind::Scalar0) + " != 0.0";
                break;
            case AluScalarOpcode::SetpGt:
                out_ += EmitOperand(instr, OperandKind::Scalar0) + " > 0.0";
                break;
            case AluScalarOpcode::SetpGe:
                out_ += EmitOperand(instr, OperandKind::Scalar0) + " >= 0.0";
                break;
            case AluScalarOpcode::SetpInv:
                out_ += EmitOperand(instr, OperandKind::Scalar0) + " == 1.0";
                break;
            case AluScalarOpcode::SetpPop:
                out_ += EmitOperand(instr, OperandKind::Scalar0) + " - 1.0 <= 0.0";
                break;
            case AluScalarOpcode::SetpClr:
                out_ += "false";
                break;
            case AluScalarOpcode::SetpRstr:
                out_ += EmitOperand(instr, OperandKind::Scalar0) + " == 0.0";
                break;
            default:
                break;
            }
            out_ += ";\n";
        }

        // ps write.
        out_ += "    ps = ";
        if (instr.scalarSaturate) out_ += "saturate(";

        switch (instr.scalarOpcode) {
        case AluScalarOpcode::Adds:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " + " +
                    EmitOperand(instr, OperandKind::Scalar1);
            break;
        case AluScalarOpcode::AddsPrev:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " + ps";
            break;
        case AluScalarOpcode::Muls:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " * " +
                    EmitOperand(instr, OperandKind::Scalar1);
            break;
        case AluScalarOpcode::MulsPrev:
        case AluScalarOpcode::MulsPrev2:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " * ps";
            break;
        case AluScalarOpcode::Maxs:
        case AluScalarOpcode::MaxAs:
        case AluScalarOpcode::MaxAsf:
            out_ += "max(" + EmitOperand(instr, OperandKind::Scalar0) + ", " +
                    EmitOperand(instr, OperandKind::Scalar1) + ")";
            break;
        case AluScalarOpcode::Mins:
            out_ += "min(" + EmitOperand(instr, OperandKind::Scalar0) + ", " +
                    EmitOperand(instr, OperandKind::Scalar1) + ")";
            break;
        case AluScalarOpcode::Seqs:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " == 0.0";
            break;
        case AluScalarOpcode::Sgts:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " > 0.0";
            break;
        case AluScalarOpcode::Sges:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " >= 0.0";
            break;
        case AluScalarOpcode::Snes:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " != 0.0";
            break;
        case AluScalarOpcode::Frcs:
            out_ += "frac(" + EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        case AluScalarOpcode::Truncs:
            out_ += "trunc(" + EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        case AluScalarOpcode::Floors:
            out_ += "floor(" + EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        case AluScalarOpcode::Exp:
            out_ += "exp2(" + EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        case AluScalarOpcode::Logc:
        case AluScalarOpcode::Log:
            out_ += "clamp(log2(" + EmitOperand(instr, OperandKind::Scalar0) +
                    "), FLT_MIN, FLT_MAX)";
            break;
        case AluScalarOpcode::Rcpc:
        case AluScalarOpcode::Rcpf:
        case AluScalarOpcode::Rcp:
            out_ += "clamp(1.0 / " + EmitOperand(instr, OperandKind::Scalar0) +
                    ", FLT_MIN, FLT_MAX)";
            break;
        case AluScalarOpcode::Rsqc:
        case AluScalarOpcode::Rsqf:
        case AluScalarOpcode::Rsq:
            out_ += "clamp(rsqrt(" + EmitOperand(instr, OperandKind::Scalar0) +
                    "), FLT_MIN, FLT_MAX)";
            break;
        case AluScalarOpcode::Subs:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " - " +
                    EmitOperand(instr, OperandKind::Scalar1);
            break;
        case AluScalarOpcode::SubsPrev:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " - ps";
            break;
        case AluScalarOpcode::SetpEq:
        case AluScalarOpcode::SetpNe:
        case AluScalarOpcode::SetpGt:
        case AluScalarOpcode::SetpGe:
            out_ += "p0 ? 0.0 : 1.0";
            break;
        case AluScalarOpcode::SetpInv:
            out_ += "(" + EmitOperand(instr, OperandKind::Scalar0) + " == 0.0 ? 1.0 : " +
                    EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        case AluScalarOpcode::SetpPop:
            out_ += "p0 ? 0.0 : (" + EmitOperand(instr, OperandKind::Scalar0) + " - 1.0)";
            break;
        case AluScalarOpcode::SetpClr:
            out_ += "FLT_MAX";
            break;
        case AluScalarOpcode::SetpRstr:
            out_ += "p0 ? 0.0 : " + EmitOperand(instr, OperandKind::Scalar0);
            break;
        case AluScalarOpcode::KillsEq:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " == 0.0";
            break;
        case AluScalarOpcode::KillsGt:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " > 0.0";
            break;
        case AluScalarOpcode::KillsGe:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " >= 0.0";
            break;
        case AluScalarOpcode::KillsNe:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " != 0.0";
            break;
        case AluScalarOpcode::KillsOne:
            out_ += EmitOperand(instr, OperandKind::Scalar0) + " == 1.0";
            break;
        case AluScalarOpcode::Sqrt:
            out_ += "sqrt(" + EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        case AluScalarOpcode::Mulsc0:
        case AluScalarOpcode::Mulsc1:
            out_ += EmitOperand(instr, OperandKind::ScalarConstant0) + " * " +
                    EmitOperand(instr, OperandKind::ScalarConstant1);
            break;
        case AluScalarOpcode::Addsc0:
        case AluScalarOpcode::Addsc1:
            out_ += EmitOperand(instr, OperandKind::ScalarConstant0) + " + " +
                    EmitOperand(instr, OperandKind::ScalarConstant1);
            break;
        case AluScalarOpcode::Subsc0:
        case AluScalarOpcode::Subsc1:
            out_ += EmitOperand(instr, OperandKind::ScalarConstant0) + " - " +
                    EmitOperand(instr, OperandKind::ScalarConstant1);
            break;
        case AluScalarOpcode::Sin:
            out_ += "sin(" + EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        case AluScalarOpcode::Cos:
            out_ += "cos(" + EmitOperand(instr, OperandKind::Scalar0) + ")";
            break;
        default:
            ++unsupported_;
            out_ += "0.0";
            break;
        }

        if (instr.scalarSaturate) out_ += ')';
        out_ += ";\n";

        // MaxAs / MaxAsf -> address register.
        if (instr.scalarOpcode == AluScalarOpcode::MaxAs) {
            out_ += "    a0 = (int)clamp(floor(" +
                    EmitOperand(instr, OperandKind::Scalar0) + " + 0.5), -256.0, 255.0);\n";
        } else if (instr.scalarOpcode == AluScalarOpcode::MaxAsf) {
            out_ += "    a0 = (int)clamp(floor(" +
                    EmitOperand(instr, OperandKind::Scalar0) + "), -256.0, 255.0);\n";
        }

        // Scalar write.
        uint32_t scalarWriteMask = instr.scalarWriteMask;
        if (instr.exportData) scalarWriteMask &= ~instr.vectorWriteMask;
        if (scalarWriteMask != 0 && !suppressVsExport) {
            std::string dst;
            if (!exportReg.empty()) {
                dst = exportReg;
                NoteExport(ps, instr.vectorDest);
            } else {
                dst = RegName(instr.scalarDest);
                NoteRegister(instr.scalarDest);
            }
            dst += '.';
            for (uint32_t i = 0; i < 4; i++) {
                if ((scalarWriteMask >> i) & 0x1) dst += kSwizzle[i];
            }
            out_ += "    " + dst + " = ps;\n";
        }
    }

    // ---- fetch lowering ---------------------------------------------------

    void EmitFetch(const IrInstruction& ir) {
        const DecodedInstruction& instr = ir.decoded;
        const bool predicated = instr.isPredicated;
        if (predicated) {
            out_ += std::string("    if (") + (instr.predicateCondition ? "" : "!") +
                    "p0)\n    {\n";
        }

        // Xenos fetch dest swizzle: 12 bits, 3 bits per component
        // (0-3 = x/y/z/w, 4 = zero, 5 = one, 6/7 = keep). The LHS suffix is
        // written in position order with unique components; the RHS maps to
        // the requested source components and may repeat. Zero/One dest slots
        // are filled by separate constant writes.
        std::string lhsSwz, rhsSwz;
        for (uint32_t i = 0; i < 4; i++) {
            uint32_t s = (instr.dstSwizzle >> (i * 3)) & 0x7;
            if (s <= 3) {
                lhsSwz += kSwizzle[i];
                rhsSwz += kSwizzle[s];
            }
        }
        if (lhsSwz.empty()) lhsSwz = "x";
        if (rhsSwz.empty()) rhsSwz = "x";

        // Zero/One dest slots get explicit constant writes after the fetch.
        auto emitZeroOne = [&](const std::string& regName) {
            for (uint32_t i = 0; i < 4; i++) {
                uint32_t s = (instr.dstSwizzle >> (i * 3)) & 0x7;
                if (s == 4) {
                    out_ += "    " + regName + "." + kSwizzle[i] + " = 0.0f;\n";
                } else if (s == 5) {
                    out_ += "    " + regName + "." + kSwizzle[i] + " = 1.0f;\n";
                }
            }
        };

        if (instr.kind == InstructionKind::VertexFetch) {
            // Vertex fetch: read from the matching vertex element input by
            // usage + usageIndex. The input is derived from the guest stream
            // via the program's vertexElements (usage/index packed).
            // Emit from the vertex element whose 12-bit stream address equals
            // this fetch's IR instruction address when known, otherwise fall
            // back to the first element. Diagnostic-grade: the runtime binds
            // real stream data.
            uint32_t usage = 0, ui = 0;
            bool found = false;
            for (const auto& ve : prog_.vertexElements) {
                if (ve.address == ir.address) {
                    usage = ve.usage;
                    ui = ve.usageIndex;
                    found = true;
                    break;
                }
            }
            if (!found && !prog_.vertexElements.empty()) {
                usage = prog_.vertexElements[0].usage;
                ui = prog_.vertexElements[0].usageIndex;
            }
            // usage is a 4-bit guest field (0-15) but the table has 14 entries;
            // clamp so a malformed container cannot index past the array.
            if (usage >= 14) usage = 0;
            NoteRegister(instr.dstRegister);
            NoteVertexInput(usage, ui);
            const std::string inputName =
                    "i" + std::string(kUsageVariables[usage]) +
                    std::to_string(ui);
            out_ += "    " + RegName(instr.dstRegister) + "." + lhsSwz +
                    " = " + inputName + "." + rhsSwz + ";\n";
            emitZeroOne(RegName(instr.dstRegister));
        } else if (instr.kind == InstructionKind::TextureFetch) {
            // Texture fetch: sample the bound texture at the source register
            // coords. Diagnostic-grade: uses a fixed sampler set; the runtime
            // binds real descriptors by sampler constant index.
            NoteRegister(instr.dstRegister);
            NoteRegister(instr.srcRegister);
            std::string src = RegName(instr.srcRegister) + ".";
            uint32_t comps = instr.dimension == 3 ? 3
                            : instr.dimension == 2 ? 3
                            : instr.dimension == 1 ? 2 : 1;
            // ABSOLUTE here, unlike the ALU vector operands above. Measured from the
            // reference's own two accessors, which deliberately differ:
            //   - ALU vector sources are COMPONENT-RELATIVE --
            //     ucode.h:1999-2003 ((swizzle >> 2i) + i) & 3, comment at :2068
            //     "Swizzles are component-relative";
            //   - a texture fetch's SOURCE swizzle is ABSOLUTE --
            //     shader_translator.cc:1132-1135 walks `swizzle >>= 2` and takes
            //     `swizzle & 0x3` with no `+ i`.
            // ucode.h:677-680 says the same in prose for the fetch DESTINATION
            // swizzle ("absolute, not relative to the component itself, unlike in
            // ALU operation sources"). So this expression is left ABSOLUTE: it
            // already matched the reference, and making it relative would have
            // introduced a second bug while fixing the first.
            for (uint32_t i = 0; i < comps; i++)
                src += kSwizzle[(instr.srcSwizzle >> (i * 2)) & 0x3];

            std::string texName = instr.dimension == 3 ? "t3D"
                                : instr.dimension == 2 ? "tCube"
                                : instr.dimension == 1 ? "t2D"
                                                       : "t1D";
            out_ += "    " + RegName(instr.dstRegister) + "." + lhsSwz +
                    " = " + texName + ".SampleLevel(s0, " + src + ", 0);\n";
            emitZeroOne(RegName(instr.dstRegister));
        }

        if (predicated) {
            out_ += "    }\n";
        }
    }
};

}  // namespace

bool ParseShaderContainer(const uint8_t* data, size_t size,
                          ShaderProgram& prog, TranslatedShader& out,
                          uint32_t psNumReg) {
    if (!ParseShaderProgram(data, size, prog, psNumReg))
        return false;
    out.isVertex = prog.isVertex;
    out.programHash = ComputeShaderProgramHash(prog);
    return true;
}

bool HashShaderContainer(const uint8_t* data, size_t size, bool& isVertex, uint64_t& programHash) {
    ShaderProgram prog;
    if (!ParseShaderProgram(data, size, prog))
        return false;
    isVertex = prog.isVertex;
    programHash = ComputeShaderProgramHash(prog);
    return true;
}

// Publishes the render-target extent the clip_disable rescale is built from.
// Called by the backend at the point it sets the D3D12 viewport, from the SAME
// m_width/m_height the viewport uses, so the shader's constants and the host
// viewport cannot disagree.
//
// `extentX`/`extentY` are the RENDER TARGET dimensions in pixels, not the
// viewport rectangle: the reference's `extent_axis_unscaled` is
// min(8192, RT extent), where the RT extent is what bounds the guest pixels, and
// draw_util.cc:350-353 takes it from the target, not from the viewport.
//
// Returns false when either extent is zero, which leaves any previously published
// transform in place rather than installing an unusable one. Returns true when
// the extent was accepted, INCLUDING when it is unchanged from the value already
// published (that is not an error, it is the steady state).
//
// NOT THREAD-SAFE with respect to in-flight translation, and that is called out
// rather than papered over: the constants are baked into generated HLSL, so a
// translation that starts before this call and ends after it can pick up the new
// extent. The backend calls this during setup, before the pipeline worker is
// started, which is the only ordering the current pipeline guarantees.
bool SetClipDisableViewportExtent(uint32_t extentX, uint32_t extentY) {
    if (extentX == 0 || extentY == 0) return false;
    const ClipDisableRescale next = MakeClipDisableRescale(extentX, extentY);
    if (!next.valid) return false;
    g_clipDisableRescale = next;
    return true;
}

// See the note beside the declaration in shader_translator.h for why this is
// defined out here rather than inside the file's anonymous namespace.
const char* const kClipDisableRescaleGateNote =
    "applied to EVERY vertex shader. The gate is a MEASURED constant, not a per-draw "
    "read: r2204 bit 16 (clip_disable) is set and all six r2206 vport_*_ena are clear "
    "in every draw build/w706.log recorded (w706.log:1676-1678, :1722-1724, :1769-1771). "
    "Per-draw gating needs the decode in pipeline_cache.cpp, which is not this file's.";

bool QueryClipDisableRescale(ClipDisableRescaleConstants* out) {
    if (!out) return false;
    *out = ClipDisableRescaleConstants{};
    if (!g_clipDisableRescale.valid) return false;
    out->scaleX = g_clipDisableRescale.scaleX;
    out->scaleY = g_clipDisableRescale.scaleY;
    out->scaleZ = g_clipDisableRescale.scaleZ;
    out->offsetX = g_clipDisableRescale.offsetX;
    out->offsetY = g_clipDisableRescale.offsetY;
    out->offsetZ = g_clipDisableRescale.offsetZ;
    out->valid = true;
    return true;
}

// Shared body of TranslateShader / TranslateShaderPinned. `havePin == false` is
// the unpinned variant. Returns false with `out`/`error` describing the refusal.
static bool TranslateShaderImpl(const uint8_t* container, size_t size,
                                const VertexInputSemantic* pinLayout, size_t pinCount,
                                bool havePin, TranslatedShader& out,
                                std::string& error,
                                const PixelShaderPairing* pairing = nullptr) {
    // Reset all per-call state up front so a failure path never leaks state
    // from a prior call on the same object.
    out.error.clear();
    out.hlsl.clear();
    out.dxil.clear();
    out.dxilOk = false;
    out.instructionCount = 0;
    out.unknownOpcodeCount = 0;
    out.unsupportedOpcodeCount = 0;
    out.clipRescaleBaked = true;   // nothing withheld until an epilogue says so

    ShaderProgram prog;
    // psNumReg is register state and must reach the pixel interpolant derivation,
    // so it goes in at the PARSE rather than being patched onto `prog` afterwards:
    // DerivePixelInterpolatorsFromInstructionStream runs inside ParseShaderProgram
    // and consumes it. 0 (no pairing supplied) is the initialiser, not a guest
    // value -- see ShaderProgram::psNumReg.
    if (!ParseShaderContainer(container, size, prog, out,
                              pairing != nullptr ? pairing->psNumReg : 0u)) {
        error = "container parse failed";
        out.error = error;
        return false;
    }

    // THE PER-DRAW INTERPOLATOR INTERSECTION, applied at the one point where a
    // pixel shader is translated for a known vertex shader. The reference computes
    // exactly this value once per draw and hands the ONE mask to both stages
    // (vulkan_command_processor.cc:2206-2211,
    // d3d12/d3d12_command_processor.cc:2081-2093), then reads it when seeding each
    // GPR (spirv_shader_translator.cc:2052-2070, dxbc_shader_translator.cc:689-700,
    // the DXBC path being the one this project's backend follows).
    //
    // It has to happen HERE and not in the caller, because `prog.interpolators` is
    // what decides both the entry signature's interpolator inputs
    // (AppendSignature) and each GPR's seed (AppendRegisters) -- an entry outside
    // the mask is not declared as an input and its register is seeded with zero,
    // so filtering it anywhere else would leave the two disagreeing.
    //
    // Applied for a PIXEL program only. writes_interpolators() is a vertex-shader
    // property (shader_translator.cc:597-599 is reached only for kInterpolator,
    // which only a vertex result can target, :1319-1330), so a pairing offered for
    // a vertex program is meaningless rather than an error.
    //
    // NOT A REFUSAL PATH. No pairing, or a VS container that will not parse, both
    // fall through to `vsProg == nullptr` and therefore to mask 0, which is the
    // reference's own behaviour -- so this can neither invent an interpolant nor
    // silently delete a tracked marker's row.
    InterpolatorIntersection pairing2;
    const ShaderProgram* vsProg = nullptr;
    ShaderProgram vsLocal;
    if (pairing != nullptr && !prog.isVertex && pairing->vsContainer != nullptr &&
        pairing->vsContainerSize != 0u) {
        // ps_num_reg is pixel state; a VS parse must not inherit it, so 0.
        if (ParseShaderProgram(pairing->vsContainer, pairing->vsContainerSize,
                               vsLocal, 0u)) {
            vsProg = &vsLocal;
        }
    }
    if (!prog.isVertex) {
        pairing2 = ApplyInterpolatorIntersection(prog, vsProg);
        // The hash is taken AFTER the intersection, so a PSO built from this program
        // is keyed on the shader that was actually emitted. Before this the key
        // would have covered the un-intersected table, and two draws pairing one PS
        // with two different VSs would have collided on a key whose HLSL differs.
        out.programHash = ComputeShaderProgramHash(prog);
    }

    // MEASURED 2026-10-01 (build/w690.log, sha256 1d5ac2ab...8641): this gate
    // fired on EVERY pixel shader, and the refusal it produced was a claim
    // about the caller that was false.
    //
    // The one caller, src/render_thread.cpp:2828, is
    //     TranslateShaderPinned(psEnv, psEnv.size(), nullptr, 0, psOut, err)
    // -- a NULL layout and a ZERO count, deliberately, with the comment at
    // :2822-2826 saying exactly that ("A pixel shader is not a vertex shader,
    // so it is handed NO layout"). The test below keyed on `havePin`, which
    // means only "the PINNED ENTRY POINT was chosen", not "a layout was
    // supplied". So it refused that call, and the message asserted an input
    // layout had been supplied when none had been -- a refusal that
    // misdescribes its own cause.
    //
    // The log agrees and shows the refusal is structural, not program-specific:
    // `DRAW-CP-PIPE #2 ... stop=ps-translate-refused ... psTr=0` on the same
    // 36-byte program twice (`CP-SHADER-BODY #2` and `#4` are byte-identical,
    // both found at three addresses in the guest image). Reproduced offline on
    // that exact program: ret=0, hlsl.len=0, error=the string below.
    //
    // THE HONEST TEST IS THE ARGUMENT, not the entry point: a layout is
    // supplied only when the pointer is non-null. Generate() already uses
    // precisely that test for the pin (:225, `layout_ != nullptr`) and a null
    // layout means "no pin" everywhere else (:1368 stores it verbatim). This one
    // gate was the sole dissenter. `havePin` is kept in the condition so the
    // unpinned entry point stays documented as never applying this rule.
    if (havePin && pinLayout != nullptr && !prog.isVertex) {
        // A pixel shader has no vertex inputs; a caller pinning VS semantics
        // onto one has misread its own layout, so say so instead of ignoring it.
        // The count is in the message: "a layout" without its size does not let
        // the caller see its own mistake, and the count is the measured
        // difference between this refusal and the (now legal) nullptr call.
        error = "TranslateShaderPinned: program is a pixel shader "
                "(prog.isVertex=0) but a vertex input layout WAS supplied "
                "(layout != nullptr, count=" + std::to_string(pinCount) +
                "); a pixel shader has no vertex inputs, so the supplied layout "
                "cannot be honoured";
        out.error = error;
        return false;
    }

    for (const auto& ir : prog.instructions)
        if (ir.decoded.unknown) ++out.unknownOpcodeCount;

    uint64_t unsupported = 0;
    HlslGenerator gen(prog, out.hlsl, unsupported);
    // The pin is applied INSIDE the generator, between pass 1 (which records the
    // fetched inputs in vsInputs_) and AppendSignature (which emits their
    // semantics), so the signature and the body always agree.
    if (havePin) gen.SetVertexInputLayout(pinLayout, pinCount);
    // Same hand-off for the intersection report. `pairing2` is a local of this
    // function and outlives Generate(), so the pointer is valid for the whole call;
    // it is null for a VERTEX translation, which is what makes the seed marker print
    // "no-vs-pairing" there instead of a mask that was never computed.
    gen.SetPairingReport(prog.isVertex ? nullptr : &pairing2);
    const bool ok = gen.Generate();
    out.unsupportedOpcodeCount = unsupported;
    out.instructionCount = prog.instructions.size();
    // Read the generator's own record of what its epilogue did, not a re-read of
    // the process global: Generate() has already returned, and the two cannot
    // drift. Reset alongside the other per-call fields at the top of this
    // function, so a failed translation cannot inherit a prior call's value.
    out.clipRescaleBaked = gen.clipRescaleBaked();

    if (!ok) {
        error = gen.error();
        out.hlsl.clear();
        out.error = error;
        return false;
    }
    if (out.hlsl.empty()) {
        error = "translation produced no HLSL";
        out.error = error;
        return false;
    }

    // F-609: report the TEXT of the position output, never a value derived from
    // it. D3D12 offers no shader-output readback, so any number here would be this
    // file's own arithmetic wearing the pipeline's clothes; the shape is a
    // classification and the expression is quoted out of the emitted string.
    //
    // Once per VERTEX program, from the render thread. The cadence matches
    // VS-RESCALE-UNBAKED above (a static one-shot latch, AppendEpilogue :1208-1223)
    // because both answer a once-per-program question about the same epilogue, and
    // neither is a rate: a marker that fires per translation would be a flood
    // row, which is what CP-T3-CENSUS is the in-tree model against.
    //
    // Names no other tracked marker. `oPos` is an HLSL identifier, not a marker
    // token, and soak_census.py counts matching LINES -- a tracked marker named in
    // this row's prose would make that other marker's count uncountable.
    // Measured on build/w710.log's programs, both vertex rows would print the
    // same shape and the same one-line expression shape, so this is 2 rows for the
    // 2 vertex programs in that soak.
    if (prog.isVertex) {
        static std::atomic<bool> s_oPosLogged{false};
        bool expected = false;
        if (s_oPosLogged.compare_exchange_strong(expected, true)) {
            const std::string& shape = gen.oPosShape();
            const std::string writes = gen.oPosWriteExpression();
            MCLA_LOG_WARN(
                "VS-POSITION-SHAPE #1: the emitted vertex program writes the "
                "position system-value as {}; the writes are exactly [{}]. "
                "TEXT ONLY, no value: the host API has no shader-output "
                "readback, so any coordinate printed here would be this "
                "translator's arithmetic rather than the pipeline's output. The "
                "rescale shown in those writes is the reference's affine map "
                "applied to XYZ with the offset scaled by W, in the epilogue, "
                "which is where the reference puts it in both of its backends. "
                "A consumer of this semantic should read three corners and "
                "generate the fourth; it is not a rectangle tuple and not a "
                "centre-plus-extent. decl=out float4 oPos : SV_Position "
                "rescaleBaked={} expr={}",
                shape.empty() ? "<no position written>" : shape,
                writes.empty() ? "<no assignment to the position>" : writes,
                out.clipRescaleBaked ? 1 : 0,
                writes.empty() ? "<none>" : writes);
        }
    }

    out.error.clear();
    return true;
}

bool TranslateShader(const uint8_t* container, size_t size,
                     std::string_view /*commonHeader*/, TranslatedShader& out) {
    std::string error;
    return TranslateShaderImpl(container, size, nullptr, 0, false, out, error);
}

bool TranslateShaderPinned(const uint8_t* container, size_t size,
                           const VertexInputSemantic* layout, size_t layoutCount,
                           TranslatedShader& out, std::string& error,
                           const PixelShaderPairing* pairing) {
    if (!layout && layoutCount != 0) {
        error = "TranslateShaderPinned: null layout with a non-zero count";
        return false;
    }
    return TranslateShaderImpl(container, size, layout, layoutCount, true, out,
                               error, pairing);
}

}  // namespace mcla::renderer
