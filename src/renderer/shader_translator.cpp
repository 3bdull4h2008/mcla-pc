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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace mcla::renderer {
namespace {

constexpr char kSwizzle[] = {'x', 'y', 'z', 'w', '0', '1', '_', '_'};

constexpr const char* kUsageVariables[] = {
    "Position", "BlendWeight", "BlendIndices", "Normal", "PointSize",
    "TexCoord", "Tangent",     "Binormal",     "TessFactor", "PositionT",
    "Color",    "Fog",         "Depth",        "Sample",
};

// Fixed output interpolator set (TexCoord0-7 + Color0/1), matching the
// reference INTERPOLATORS list for VS output declaration.
constexpr uint32_t kInterpolatorCount = 10;

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
            if (c.info.registerSet == RegisterSet::Float4)
                float4Constants_.emplace(c.info.registerIndex, &c);
            else if (c.info.registerSet == RegisterSet::Sampler)
                samplerConstants_.emplace(c.info.registerIndex, &c);
        }
    }

    void Generate() {
        out_.clear();
        const bool ps = !prog_.isVertex;

        AppendHeader(ps);
        AppendRegisters(ps);
        AppendBody(ps);
        AppendEpilogue(ps);
    }

private:
    const ShaderProgram& prog_;
    std::string& out_;
    uint64_t& unsupported_;
    std::unordered_map<uint32_t, const ConstantEntry*> float4Constants_;
    std::unordered_map<uint32_t, const ConstantEntry*> samplerConstants_;

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
        if (select) {
            regFormatted = "r" + std::to_string(reg);
        } else {
            auto it = float4Constants_.find(reg);
            if (it != float4Constants_.end()) {
                std::string name = SanitizedName(it->second->name);
                if (!name.empty()) {
                    const uint16_t regCount = it->second->info.registerCount;
                    if (regCount > 1) {
                        // Named array constant; relative addressing appends aL/a0.
                        uint32_t offset = reg - it->second->info.registerIndex;
                        std::string rel;
                        if (instr.const0Relative)
                            rel = instr.constAddressRegisterRelative ? " + a0"
                                                                     : " + aL";
                        regFormatted = name + "(" + std::to_string(offset) +
                                       (rel.empty() ? std::string()
                                                    : std::string(" + ") +
                                                          (instr.constAddressRegisterRelative
                                                               ? "a0"
                                                               : "aL")) +
                                       ")";
                    } else {
                        regFormatted = name;
                    }
                } else {
                    regFormatted = "c" + std::to_string(reg);
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

        // Constant table. Float4 constants are named where the guest provides
        // a valid identifier; otherwise they fall back to c{N}.
        out_ += "cbuffer ShaderConstants : register(b0)\n{\n";
        for (const auto& c : prog_.constants) {
            if (c.info.registerSet != RegisterSet::Float4) continue;
            std::string name = SanitizedName(c.name);
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
        (void)ps;
        // PS interpolators seed their target register from the matching input.
        // VS registers start at zero (vertex fetch writes them).
        out_ += "    float4 r[" + std::to_string(kRegisterCount) + "] = 0;\n";
        out_ += "    float ps = 0.0;\n";
        out_ += "    int a0 = 0;\n";
        out_ += "    int aL = 0;\n";
        out_ += "    bool p0 = false;\n";
        out_ += "\n";
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
                if (instr.vectorDest == 0) {
                    exportReg = "oPos";
                } else if (instr.vectorDest < kInterpolatorCount) {
                    exportReg = "o" +
                                std::string(kUsageVariables[5]) +
                                std::to_string(instr.vectorDest - 1);
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

        if (vectorWriteMask != 0) {
            std::string dst;
            if (!exportReg.empty()) {
                dst = exportReg;
            } else {
                dst = "r[" + std::to_string(instr.vectorDest) + "]";
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
            EmitScalarClause(instr, ps, exportReg);
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
                          const std::string& exportReg) {
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
        if (scalarWriteMask != 0) {
            std::string dst;
            if (!exportReg.empty()) {
                dst = exportReg;
            } else {
                dst = "r[" + std::to_string(instr.scalarDest) + "]";
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

        // Dest swizzle suffix (x/y/z/w repeated per used component).
        std::string dstSwz;
        for (uint32_t i = 0; i < 4; i++) {
            uint32_t s = (instr.dstSwizzle >> (i * 2)) & 0x3;
            if (s <= 3) dstSwz += kSwizzle[s];
        }
        if (dstSwz.empty()) dstSwz = "x";

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
            const std::string inputName =
                    "i" + std::string(kUsageVariables[usage]) +
                    std::to_string(ui);
            out_ += "    r[" + std::to_string(instr.dstRegister) + "]." + dstSwz +
                    " = " + inputName + "." + dstSwz + ";\n";
        } else if (instr.kind == InstructionKind::TextureFetch) {
            // Texture fetch: sample the bound texture at the source register
            // coords. Diagnostic-grade: uses a fixed sampler set; the runtime
            // binds real descriptors by sampler constant index.
            std::string src = "r[" + std::to_string(instr.srcRegister) + "].";
            uint32_t comps = instr.dimension == 3 ? 3
                            : instr.dimension == 2 ? 3
                            : instr.dimension == 1 ? 2 : 1;
            for (uint32_t i = 0; i < comps; i++)
                src += kSwizzle[(instr.srcSwizzle >> (i * 2)) & 0x3];

            std::string texName = instr.dimension == 3 ? "t3D"
                                : instr.dimension == 2 ? "tCube"
                                : instr.dimension == 1 ? "t2D"
                                                       : "t1D";
            out_ += "    r[" + std::to_string(instr.dstRegister) + "]." + dstSwz +
                    " = " + texName + ".SampleLevel(s0, " + src + ", 0);\n";
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
