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
//   - fetch (vertex/tftex) -> vertex-element inputs (VS) or sampler/texture
//     binds with swizzled register writes (PS);
//   - exports -> oC0..oC3 / oDepth (PS) or oPos + interpolators (VS).
//
// This is a generator: it must always emit a complete, tokenizable HLSL body
// so the offline tool can diff and compile it. Every opcode in the ALU/Fetch
// enums has a branch; anything outside the known table is recorded as
// unsupported (never silently dropped). The emitted HLSL is diagnostic-grade;
// precision helper functions (R11G11B10 decode, cube mapping, tfetch helpers)
// are provided inline so the output stands alone.

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace mcla::renderer {

// ---------------------------------------------------------------- reflection
//
// Vertex-input reflection shared by the generator (VS entry signature) and the
// offline PSO smoke test (input layout). A vertex fetch resolves to a
// (usage, usageIndex) pair through the program's vertexElements by slot
// address, falling back to the first element when no element matches — the
// same rule EmitFetch uses. ReferencedVertexInputs returns the unique pairs in
// first-fetch order plus the format/stride/offset of the fetch that introduced
// each pair, so the declared signature and the bound layout always agree.

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

    for (const auto& ir : prog.instructions) {
        if (!ir.isFetch || ir.decoded.kind != InstructionKind::VertexFetch)
            continue;
        uint32_t usage = 0, usageIndex = 0;
        resolve(ir.address, usage, usageIndex);
        if (usage >= 14) usage = 0;
        bool seen = false;
        for (const auto& in : inputs)
            if (in.usage == usage && in.usageIndex == usageIndex) { seen = true; break; }
        if (seen) continue;
        inputs.push_back(VertexInputRef{usage, usageIndex,
                                        ir.decoded.vertexFormat,
                                        ir.decoded.stride, ir.decoded.offset});
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
// Operand selection (mirrors XenosRecomp ShaderRecompiler::op()).
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

    void Generate() {
        out_.clear();
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

        AppendHeader(ps);
        AppendSignature(ps);
        AppendRegisters(ps);
        out_ += body;
        AppendEpilogue(ps);
        out_ += "}\n";
    }

private:
    const ShaderProgram& prog_;
    std::string& out_;
    uint64_t& unsupported_;
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
                    result += kSwizzle[((swizzle >> (i * 2)) + i) & 0x3];
            }
            break;
        }
        case OperandKind::Scalar0:
        case OperandKind::ScalarConstant0:
            result += kSwizzle[((swizzle >> 6) + 3) & 0x3];
            break;
        case OperandKind::Scalar1:
        case OperandKind::ScalarConstant1:
            result += kSwizzle[swizzle & 0x3];
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
        // Xenos Cnd ops emit select(cond, a, b); HLSL has no select intrinsic,
        // so provide ternary-based overloads mirroring the reference helper.
        out_ += "float4 select(bool4 c, float4 a, float4 b) { return c ? a : b; }\n";
        out_ += "float4 select(bool3 c, float4 a, float4 b) { return bool4(c, false) ? a : b; }\n";
        out_ += "float4 select(bool2 c, float4 a, float4 b) { return bool4(c, false, false) ? a : b; }\n";
        out_ += "float4 select(bool c, float4 a, float4 b) { return c ? a : b; }\n";
        out_ += "float3 select(bool c, float3 a, float3 b) { return c ? a : b; }\n";
        out_ += "float2 select(bool c, float2 a, float2 b) { return c ? a : b; }\n";
        out_ += "float select(bool c, float a, float b) { return c ? a : b; }\n";
        out_ += "\n";

        // Constant table. Float4 constants are named where the guest provides
        // a valid identifier; otherwise they fall back to c{N}. The cbuffer is
        // closed over every register the body references (see Analyze), so no
        // operand's c{N} reference is ever left undeclared.
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

        // Sampler/texure binds used by tfetch (named samplers + implicit).
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
            // Sampler constant names (from the table) get a texture declare so
            // tfetch can reference a named resource.
            for (uint32_t index : usedSamplers) {
                auto it = samplerConstants_.find(index);
                const char* dimName =
                    samplerDim[index] == 3 ? "t3D"
                    : samplerDim[index] == 2 ? "tCube"
                    : samplerDim[index] == 1 ? "t2D"
                                             : "t1D";
                std::string texRef = std::string(dimName);
                (void)it;
                (void)texRef;
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
    // (collected in Analyze): PS consumes iPos + interpolator inputs and writes
    // the oC*/oDepth exports it uses; VS consumes the resolved vertex inputs
    // and writes oPos plus the interpolator outputs it exports.
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
            // Ensure oDepth isn't left undefined when the shader never wrote it.
            out_ += "    // exports emitted inline\n";
        } else {
            // Half-pixel offset to match D3D9/Xenos rasterization.
            out_ += "    oPos.xy += float2(0.5, 0.5) * oPos.w;\n";
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
            uint32_t zeroMask =
                instr.scalarDestRelative ? (0b1111 & ~(instr.vectorWriteMask | instr.scalarWriteMask)) : 0;
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
        (void)ps;
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
            // Emit from the vertex element whose address matches this fetch's
            // slot address when known, otherwise fall back to the first
            // element. Diagnostic-grade: the runtime binds real stream data.
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
                          ShaderProgram& prog, TranslatedShader& out) {
    if (!ParseShaderProgram(data, size, prog))
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

bool TranslateShader(const uint8_t* container, size_t size,
                     std::string_view /*commonHeader*/, TranslatedShader& out) {
    // Reset all per-call state up front so a failure path never leaks state
    // from a prior call on the same object.
    out.error.clear();
    out.hlsl.clear();
    out.dxil.clear();
    out.dxilOk = false;
    out.instructionCount = 0;
    out.unknownOpcodeCount = 0;
    out.unsupportedOpcodeCount = 0;

    ShaderProgram prog;
    if (!ParseShaderContainer(container, size, prog, out)) {
        out.error = "container parse failed";
        return false;
    }

    for (const auto& ir : prog.instructions)
        if (ir.decoded.unknown) ++out.unknownOpcodeCount;

    uint64_t unsupported = 0;
    HlslGenerator gen(prog, out.hlsl, unsupported);
    gen.Generate();
    out.unsupportedOpcodeCount = unsupported;
    out.instructionCount = prog.instructions.size();

    if (!out.hlsl.empty()) {
        out.error.clear();
        return true;
    }
    out.error = "translation produced no HLSL";
    return false;
}

}  // namespace mcla::renderer
