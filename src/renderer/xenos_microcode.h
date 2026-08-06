#pragma once

// Xenos (Xbox 360) shader microcode decoder.
//
// Bit layouts faithfully follow XenosRecomp (hedge-dev/XenosRecomp,
// shader_code.h) and Xenia (xenia-project/xenia, src/xenia/gpu/ucode.h).
// Guest microcode is big-endian; words are assembled explicitly, never via
// bitfields.
//
// Layout summary:
//   - Control flow: 2 instructions per 12-byte block. Each CF instruction is
//     6 bytes = 32-bit word0 + 16-bit word1. Opcode is word1 bits 12-15.
//   - Exec targets: address is in *instruction units* (3 dwords = 12 bytes)
//     relative to microcode start.
//   - Instruction: 12 bytes = 3 dwords. Fetch vs ALU is chosen by the exec
//     sequence bit (2 bits per slot; bit0 = ALU(0)/fetch(1)).

#include <cstdint>

namespace mcla::renderer {

// --- Control flow ---

enum class ControlFlowOpcode : uint8_t {
    Nop = 0,
    Exec = 1,
    ExecEnd = 2,
    CondExec = 3,
    CondExecEnd = 4,
    CondExecPred = 5,
    CondExecPredEnd = 6,
    LoopStart = 7,
    LoopEnd = 8,
    CondCall = 9,
    Return = 10,
    CondJmp = 11,
    Alloc = 12,
    CondExecPredClean = 13,
    CondExecPredCleanEnd = 14,
    MarkVsFetchDone = 15,
};

const char* ControlFlowOpcodeName(ControlFlowOpcode opcode);

struct ControlFlowInstruction {
    uint32_t address = 0;            // word0 bits 0-11  (exec target, 12-byte units)
    uint32_t count = 0;              // word0 bits 12-14 (instruction count)
    bool isYield = false;            // word0 bit 15
    uint32_t sequence = 0;           // word0 bits 16-27 (2 bits per slot)
    uint32_t vertexCacheHigh = 0;    // word0 bits 28-31
    uint32_t vertexCacheLow = 0;     // word1 bits 0-1
    bool isPredicateClean = false;   // word1 bit 9
    bool condition = false;          // word1 bit 10
    bool absoluteAddressing = false; // word1 bit 11
    ControlFlowOpcode opcode = ControlFlowOpcode::Nop; // word1 bits 12-15

    bool IsExec() const;
};

ControlFlowInstruction DecodeControlFlow(uint32_t word0, uint16_t word1);

// Xenos microcode layout: all control-flow pairs are listed at the top of the
// program; the executable instruction area follows immediately after the last
// control-flow pair. Exec addresses are in 12-byte instruction units relative
// to the start of the program (not relative to the control-flow region).
//
// ComputeControlFlowByteBound returns the size of the control-flow region in
// bytes by scanning for the first exec instruction whose target address is
// nonzero and using that address as the upper bound (the freedreno/Xenia/
// XenosRecomp approach). If no nonzero exec target is found, the whole buffer
// is treated as control flow.
size_t ComputeControlFlowByteBound(const uint8_t* code, size_t code_size);

// --- Instructions ---

enum class FetchOpcode : uint8_t {
    VertexFetch = 0,
    TextureFetch = 1,
    GetTextureBorderColorFrac = 16,
    GetTextureComputedLod = 17,
    GetTextureGradients = 18,
    GetTextureWeights = 19,
    SetTextureLod = 24,
    SetTextureGradientsHorz = 25,
    SetTextureGradientsVert = 26,
};

enum class AluVectorOpcode : uint8_t {
    Add = 0, Mul = 1, Max = 2, Min = 3, Seq = 4, Sgt = 5, Sge = 6, Sne = 7,
    Frc = 8, Trunc = 9, Floor = 10, Mad = 11, CndEq = 12, CndGe = 13,
    CndGt = 14, Dp4 = 15, Dp3 = 16, Dp2Add = 17, Cube = 18, Max4 = 19,
    SetpEqPush = 20, SetpNePush = 21, SetpGtPush = 22, SetpGePush = 23,
    KillEq = 24, KillGt = 25, KillGe = 26, KillNe = 27, Dst = 28, MaxA = 29,
};

enum class AluScalarOpcode : uint8_t {
    Adds = 0, AddsPrev = 1, Muls = 2, MulsPrev = 3, MulsPrev2 = 4,
    Maxs = 5, Mins = 6, Seqs = 7, Sgts = 8, Sges = 9, Snes = 10, Frcs = 11,
    Truncs = 12, Floors = 13, Exp = 14, Logc = 15, Log = 16, Rcpc = 17,
    Rcpf = 18, Rcp = 19, Rsqc = 20, Rsqf = 21, Rsq = 22, MaxAs = 23,
    MaxAsf = 24, Subs = 25, SubsPrev = 26, SetpEq = 27, SetpNe = 28,
    SetpGt = 29, SetpGe = 30, SetpInv = 31, SetpPop = 32, SetpClr = 33,
    SetpRstr = 34, KillsEq = 35, KillsGt = 36, KillsGe = 37, KillsNe = 38,
    KillsOne = 39, Sqrt = 40, Mulsc0 = 42, Mulsc1 = 43, Addsc0 = 44,
    Addsc1 = 45, Subsc0 = 46, Subsc1 = 47, Sin = 48, Cos = 49, RetainPrev = 50,
};

enum class InstructionKind : uint8_t {
    Alu = 0,
    VertexFetch = 1,
    TextureFetch = 2,
};

const char* FetchOpcodeName(FetchOpcode opcode);
const char* AluVectorOpcodeName(AluVectorOpcode opcode);
const char* AluScalarOpcodeName(AluScalarOpcode opcode);

struct DecodedInstruction {
    InstructionKind kind = InstructionKind::Alu;
    uint32_t slotAddress = 0;  // byte offset within microcode (filled by walker)

    // Fetch operands
    FetchOpcode fetchOpcode = FetchOpcode::VertexFetch;
    uint32_t dstRegister = 0;
    uint32_t dstSwizzle = 0;
    uint32_t srcRegister = 0;
    uint32_t srcSwizzle = 0;
    bool dstRelative = false;
    bool srcRelative = false;
    uint32_t constIndex = 0;
    uint32_t constIndexSelect = 0;
    uint32_t prefetchCount = 0;
    bool isPredicated = false;
    bool predicateCondition = false;
    // VertexFetch-specific
    uint32_t vertexFormat = 0;
    uint32_t stride = 0;
    int32_t offset = 0;
    bool isMiniFetch = false;
    bool isSigned = false;
    bool isNormalized = false;
    int32_t expAdjust = 0;
    bool isIndexRounded = false;
    // TextureFetch-specific
    uint32_t dimension = 0;

    // ALU operands
    AluVectorOpcode vectorOpcode = AluVectorOpcode::Add;
    AluScalarOpcode scalarOpcode = AluScalarOpcode::Adds;
    uint32_t vectorDest = 0;
    uint32_t scalarDest = 0;
    bool vectorDestRelative = false;
    bool scalarDestRelative = false;
    uint32_t vectorWriteMask = 0;
    uint32_t scalarWriteMask = 0;
    bool vectorSaturate = false;
    bool scalarSaturate = false;
    bool exportData = false;
    uint32_t src1Register = 0, src2Register = 0, src3Register = 0;
    uint32_t src1Swizzle = 0, src2Swizzle = 0, src3Swizzle = 0;
    bool src1Select = false, src2Select = false, src3Select = false;
    bool src1Negate = false, src2Negate = false, src3Negate = false;

    bool unknown = false;
};

// Decode one 12-byte instruction from three assembled guest dwords.
// isFetch selects fetch vs ALU layout (comes from the exec sequence bit).
DecodedInstruction DecodeInstruction(uint32_t word0, uint32_t word1,
                                     uint32_t word2, bool isFetch);

// Assemble a big-endian 32-bit guest word from 4 bytes.
inline uint32_t AssembleBE32(const uint8_t* p) {
    return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) |
           (uint32_t(p[2]) << 8) | uint32_t(p[3]);
}

}  // namespace mcla::renderer
