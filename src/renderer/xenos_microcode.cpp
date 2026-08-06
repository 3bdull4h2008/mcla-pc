#include "xenos_microcode.h"

#include <array>

namespace mcla::renderer {
namespace {

template <typename E, size_t N>
const char* EnumName(const std::array<const char*, N>& names, E value) {
    size_t idx = static_cast<size_t>(value);
    return idx < names.size() ? names[idx] : "?";
}

}  // namespace

bool ControlFlowInstruction::IsExec() const {
    switch (opcode) {
        case ControlFlowOpcode::Exec:
        case ControlFlowOpcode::ExecEnd:
        case ControlFlowOpcode::CondExec:
        case ControlFlowOpcode::CondExecEnd:
        case ControlFlowOpcode::CondExecPred:
        case ControlFlowOpcode::CondExecPredEnd:
        case ControlFlowOpcode::CondExecPredClean:
        case ControlFlowOpcode::CondExecPredCleanEnd:
            return true;
        default:
            return false;
    }
}

const char* ControlFlowOpcodeName(ControlFlowOpcode opcode) {
    static constexpr std::array<const char*, 16> kNames = {
        "Nop", "Exec", "ExecEnd", "CondExec", "CondExecEnd", "CondExecPred",
        "CondExecPredEnd", "LoopStart", "LoopEnd", "CondCall", "Return",
        "CondJmp", "Alloc", "CondExecPredClean", "CondExecPredCleanEnd",
        "MarkVsFetchDone",
    };
    return EnumName(kNames, opcode);
}

ControlFlowInstruction DecodeControlFlow(uint32_t word0, uint16_t word1) {
    ControlFlowInstruction cf;
    cf.address = word0 & 0xFFF;
    cf.count = (word0 >> 12) & 0x7;
    cf.isYield = ((word0 >> 15) & 0x1) != 0;
    cf.sequence = (word0 >> 16) & 0xFFF;
    cf.vertexCacheHigh = (word0 >> 28) & 0xF;
    cf.vertexCacheLow = word1 & 0x3;
    cf.isPredicateClean = ((word1 >> 9) & 0x1) != 0;
    cf.condition = ((word1 >> 10) & 0x1) != 0;
    cf.absoluteAddressing = ((word1 >> 11) & 0x1) != 0;
    cf.opcode = static_cast<ControlFlowOpcode>((word1 >> 12) & 0xF);
    return cf;
}

size_t ComputeControlFlowByteBound(const uint8_t* code, size_t code_size) {
    const size_t n_blocks = code_size / 12;
    size_t bound = code_size;
    for (size_t b = 0; b < n_blocks; ++b) {
        const uint8_t* blk = code + b * 12;
        uint32_t w0 = AssembleBE32(blk);
        uint32_t w1 = AssembleBE32(blk + 4);
        uint32_t w2 = AssembleBE32(blk + 8);
        for (int slot = 0; slot < 2; ++slot) {
            uint32_t cfw0 = slot == 0 ? w0 : ((w1 >> 16) | (w2 << 16));
            uint16_t cfw1 = slot == 0 ? static_cast<uint16_t>(w1 & 0xFFFF)
                                      : static_cast<uint16_t>(w2 >> 16);
            ControlFlowInstruction cf = DecodeControlFlow(cfw0, cfw1);
            if (cf.IsExec() && cf.address != 0) {
                bound = std::min(bound, size_t(cf.address) * 12);
            }
        }
    }
    return bound;
}

const char* FetchOpcodeName(FetchOpcode opcode) {
    static constexpr std::array<const char*, 32> kNames = {
        "VertexFetch", "TextureFetch", "f?2", "f?3", "f?4", "f?5", "f?6",
        "f?7", "f?8", "f?9", "f?10", "f?11", "f?12", "f?13", "f?14", "f?15",
        "GetTextureBorderColorFrac", "GetTextureComputedLod", "GetTextureGradients",
        "GetTextureWeights", "f?20", "f?21", "f?22", "f?23", "SetTextureLod",
        "SetTextureGradientsHorz", "SetTextureGradientsVert", "f?27", "f?28",
        "f?29", "f?30", "f?31",
    };
    return EnumName(kNames, opcode);
}

const char* AluVectorOpcodeName(AluVectorOpcode opcode) {
    static constexpr std::array<const char*, 30> kNames = {
        "Add", "Mul", "Max", "Min", "Seq", "Sgt", "Sge", "Sne", "Frc", "Trunc",
        "Floor", "Mad", "CndEq", "CndGe", "CndGt", "Dp4", "Dp3", "Dp2Add", "Cube",
        "Max4", "SetpEqPush", "SetpNePush", "SetpGtPush", "SetpGePush", "KillEq",
        "KillGt", "KillGe", "KillNe", "Dst", "MaxA",
    };
    return EnumName(kNames, opcode);
}

const char* AluScalarOpcodeName(AluScalarOpcode opcode) {
    static constexpr std::array<const char*, 51> kNames = {
        "Adds", "AddsPrev", "Muls", "MulsPrev", "MulsPrev2", "Maxs", "Mins",
        "Seqs", "Sgts", "Sges", "Snes", "Frcs", "Truncs", "Floors", "Exp",
        "Logc", "Log", "Rcpc", "Rcpf", "Rcp", "Rsqc", "Rsqf", "Rsq", "MaxAs",
        "MaxAsf", "Subs", "SubsPrev", "SetpEq", "SetpNe", "SetpGt", "SetpGe",
        "SetpInv", "SetpPop", "SetpClr", "SetpRstr", "KillsEq", "KillsGt",
        "KillsGe", "KillsNe", "KillsOne", "Sqrt", "s?41", "Mulsc0", "Mulsc1",
        "Addsc0", "Addsc1", "Subsc0", "Subsc1", "Sin", "Cos", "RetainPrev",
    };
    return EnumName(kNames, opcode);
}

DecodedInstruction DecodeInstruction(uint32_t word0, uint32_t word1,
                                     uint32_t word2, bool isFetch) {
    DecodedInstruction instr;

    if (isFetch) {
        // FetchInstruction (XenosRecomp shader_code.h):
        //   word0: opcode:5, srcReg:6, srcRegAm:1, dstReg:6, dstRegAm:1,
        //          (vfetch: mustBeOne:1 / tfetch: fetchValidOnly:1),
        //          constIndex:5, (vfetch: constIndexSelect:2 / tfetch: texCoordDenorm:1),
        //          srcSwizzle:(vfetch 2 / tfetch 6)
        instr.kind = (word0 & 0x1F) == 0 ? InstructionKind::VertexFetch
                                         : InstructionKind::TextureFetch;
        instr.fetchOpcode = static_cast<FetchOpcode>(word0 & 0x1F);
        instr.srcRegister = (word0 >> 5) & 0x3F;
        instr.srcRelative = ((word0 >> 11) & 0x1) != 0;
        instr.dstRegister = (word0 >> 12) & 0x3F;
        instr.dstRelative = ((word0 >> 18) & 0x1) != 0;
        instr.constIndex = (word0 >> 20) & 0x1F;

        if (instr.kind == InstructionKind::VertexFetch) {
            // VertexFetchInstruction:
            //   word0: ... constIndexSelect:2 (bits 25-26), prefetchCount:3 (27-29),
            //          srcSwizzle:2 (30-31)
            //   word1: dstSwizzle:12, formatCompAll:1, numFormatAll:1,
            //          signedRfModeAll:1, isIndexRounded:1, format:6, reserved2:2,
            //          expAdjust:6, isMiniFetch:1, isPredicated:1
            //   word2: stride:8, offset:23, predCondition:1
            instr.constIndexSelect = (word0 >> 25) & 0x3;
            instr.prefetchCount = (word0 >> 27) & 0x7;
            instr.srcSwizzle = (word0 >> 30) & 0x3;

            instr.dstSwizzle = word1 & 0xFFF;
            instr.isSigned = ((word1 >> 12) & 0x1) != 0;
            instr.isNormalized = ((word1 >> 13) & 0x1) == 0;
            instr.isIndexRounded = ((word1 >> 15) & 0x1) != 0;
            instr.vertexFormat = (word1 >> 16) & 0x3F;
            instr.expAdjust = static_cast<int32_t>((word1 >> 22) & 0x3F);
            if (instr.expAdjust >= 32) instr.expAdjust -= 64;
            instr.isMiniFetch = ((word1 >> 28) & 0x1) != 0;
            instr.isPredicated = ((word1 >> 29) & 0x1) != 0;

            instr.stride = word2 & 0xFF;
            instr.offset = static_cast<int32_t>((word2 >> 8) & 0x7FFFFF);
            if (instr.offset >= (1 << 22)) instr.offset -= (1 << 23);
            instr.predicateCondition = ((word2 >> 31) & 0x1) != 0;
        } else {
            // TextureFetchInstruction:
            //   word0: ... fetchValidOnly:1(19), constIndex:5(20-24),
            //          texCoordDenorm:1(25), srcSwizzle:6(26-31)
            //   word1: dstSwizzle:12, mag/min/mip/vol filters, aniso, arbitrary,
            //          useCompLod, useRegLod, unk, isPredicated (bit 31)
            //   word2: useRegGradients:1, sampleLocation:1, lodBias:7, :5,
            //          dimension:2 (bits 13-14), offsetX/Y/Z:5 each, predCondition:1
            instr.srcSwizzle = (word0 >> 26) & 0x3F;
            instr.dstSwizzle = word1 & 0xFFF;
            instr.isPredicated = ((word1 >> 31) & 0x1) != 0;
            instr.dimension = (word2 >> 13) & 0x3;
            instr.predicateCondition = ((word2 >> 31) & 0x1) != 0;
        }
        instr.unknown = static_cast<uint32_t>(instr.fetchOpcode) > 26;
        return instr;
    }

    // ALU (XenosRecomp AluInstruction):
    //   word0: vectorDest:6, vectorDestRelative:1, absConstants:1, scalarDest:6,
    //          scalarDestRelative:1, exportData:1, vectorWriteMask:4,
    //          scalarWriteMask:4, vectorSaturate:1, scalarSaturate:1,
    //          scalarOpcode:6
    //   word1: src3Swizzle:8, src2Swizzle:8, src1Swizzle:8, src3Negate:1,
    //          src2Negate:1, src1Negate:1, predicateCondition:1, isPredicated:1,
    //          constAddressRegisterRelative:1, const1Relative:1, const0Relative:1
    //   word2: src3Register:8, src2Register:8, src1Register:8,
    //          vectorOpcode:5, src3Select:1, src2Select:1, src1Select:1
    instr.kind = InstructionKind::Alu;
    instr.vectorDest = word0 & 0x3F;
    instr.vectorDestRelative = ((word0 >> 6) & 0x1) != 0;
    instr.scalarDest = (word0 >> 8) & 0x3F;
    instr.scalarDestRelative = ((word0 >> 14) & 0x1) != 0;
    instr.exportData = ((word0 >> 15) & 0x1) != 0;
    instr.vectorWriteMask = (word0 >> 16) & 0xF;
    instr.scalarWriteMask = (word0 >> 20) & 0xF;
    instr.vectorSaturate = ((word0 >> 24) & 0x1) != 0;
    instr.scalarSaturate = ((word0 >> 25) & 0x1) != 0;
    instr.scalarOpcode = static_cast<AluScalarOpcode>((word0 >> 26) & 0x3F);

    instr.src3Swizzle = word1 & 0xFF;
    instr.src2Swizzle = (word1 >> 8) & 0xFF;
    instr.src1Swizzle = (word1 >> 16) & 0xFF;
    instr.src3Negate = ((word1 >> 24) & 0x1) != 0;
    instr.src2Negate = ((word1 >> 25) & 0x1) != 0;
    instr.src1Negate = ((word1 >> 26) & 0x1) != 0;
    instr.predicateCondition = ((word1 >> 27) & 0x1) != 0;
    instr.isPredicated = ((word1 >> 28) & 0x1) != 0;

    instr.src3Register = word2 & 0xFF;
    instr.src2Register = (word2 >> 8) & 0xFF;
    instr.src1Register = (word2 >> 16) & 0xFF;
    instr.vectorOpcode = static_cast<AluVectorOpcode>((word2 >> 24) & 0x1F);
    instr.src3Select = ((word2 >> 29) & 0x1) != 0;
    instr.src2Select = ((word2 >> 30) & 0x1) != 0;
    instr.src1Select = ((word2 >> 31) & 0x1) != 0;

    const uint32_t scalarRaw = static_cast<uint32_t>(instr.scalarOpcode);
    const bool scalarKnown =
        scalarRaw <= 40 ||
        (scalarRaw >= 42 && scalarRaw <= 50);
    instr.unknown = static_cast<uint32_t>(instr.vectorOpcode) > 29 || !scalarKnown;
    return instr;
}

}  // namespace mcla::renderer
