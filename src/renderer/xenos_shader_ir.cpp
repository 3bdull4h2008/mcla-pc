#include "xenos_shader_ir.h"

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

namespace mcla::renderer {

static uint32_t ReadBE32(const uint8_t* p) {
    return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) |
           (uint32_t(p[2]) << 8) | uint32_t(p[3]);
}
static uint16_t ReadBE16(const uint8_t* p) {
    return uint16_t((uint16_t(p[0]) << 8) | uint16_t(p[1]));
}

const char* RegisterSetName(RegisterSet set) {
    switch (set) {
        case RegisterSet::Bool:    return "Bool";
        case RegisterSet::Int4:    return "Int4";
        case RegisterSet::Float4:  return "Float4";
        case RegisterSet::Sampler: return "Sampler";
    }
    return "Unknown";
}

static constexpr size_t kContainerHeaderSize = 36;
static constexpr size_t kShaderHeaderSize = 24;

// Defined below ParseShaderProgram, after the derivation's measurement notes.
static void DeriveVertexElementsFromInstructionStream(ShaderProgram& out);
static void DerivePixelInterpolatorsFromInstructionStream(ShaderProgram& out);
static void DeriveVertexInterpolatorExports(ShaderProgram& out);

bool ParseShaderProgram(const uint8_t* data, size_t size, ShaderProgram& out,
                        uint32_t psNumReg) {
    if (size < kContainerHeaderSize) return false;

    // Register state, kept OFF the container and OFF the IR stream, because it is
    // neither (see ShaderProgram::psNumReg). Set before any table is read: the
    // pixel interpolant derivation below consumes it.
    out.psNumReg = psNumReg;

    out.flags       = ReadBE32(data + 0);
    out.virtualSize = ReadBE32(data + 4);
    out.physicalSize= ReadBE32(data + 8);

    if ((out.flags & 0xFFFFFF00) != 0x102A1100) return false;
    uint32_t f1C = ReadBE32(data + 28);
    uint32_t f20 = ReadBE32(data + 32);
    if (f1C != 0 || f20 != 0) return false;
    if (size_t(out.virtualSize) + size_t(out.physicalSize) > size) return false;

    uint32_t so = ReadBE32(data + 24);
    out.isVertex  = (out.flags & 0x1) != 0;

    // Shader header
    if (so + kShaderHeaderSize > out.virtualSize) return false;    const uint8_t* sp = data + so;
    out.physicalOffset   = ReadBE32(sp + 0);
    out.shaderSize       = ReadBE32(sp + 4);
    out.fieldC           = ReadBE32(sp + 12);
    out.field10          = ReadBE32(sp + 16);
    out.interpolatorInfo = ReadBE32(sp + 20);

    const size_t codeStart = size_t(out.virtualSize) + out.physicalOffset;
    if (codeStart + out.shaderSize > size) return false;

    // Decode microcode into IR
    const uint8_t* code = data + codeStart;
    const size_t cfBound = ComputeControlFlowByteBound(code, out.shaderSize);
    const size_t nBlocks = cfBound / 12;

    out.instructions.clear();
    for (size_t b = 0; b < nBlocks; ++b) {
        const uint8_t* blk = code + b * 12;
        uint32_t w0 = ReadBE32(blk);
        uint32_t w1 = ReadBE32(blk + 4);
        uint32_t w2 = ReadBE32(blk + 8);
        for (int slot = 0; slot < 2; ++slot) {
            uint32_t cfw0 = slot == 0 ? w0 : ((w1 >> 16) | (w2 << 16));
            uint16_t cfw1 = slot == 0 ? static_cast<uint16_t>(w1 & 0xFFFF)
                                      : static_cast<uint16_t>(w2 >> 16);
            ControlFlowInstruction cf = DecodeControlFlow(cfw0, cfw1);
            if (!cf.IsExec()) continue;

            const size_t instrBase = size_t(cf.address) * 12;
            for (uint32_t i = 0; i < cf.count; ++i) {
                if (instrBase + size_t(i) * 12 + 12 > out.shaderSize) break;
                const uint8_t* ip = code + instrBase + i * 12;
                uint32_t iw0 = ReadBE32(ip);
                uint32_t iw1 = ReadBE32(ip + 4);
                uint32_t iw2 = ReadBE32(ip + 8);
                bool isFetch = ((cf.sequence >> (2 * i)) & 1) != 0;
                IrInstruction ir;
                ir.address  = uint32_t(cf.address + i);
                ir.isFetch  = isFetch;
                // VertexFetch word 1 bits 30/31: is_mini_fetch, is_predicated.
                // VERTEXFETCH WORD 1 ONLY: tfetch word 1 is_predicated is also
                // bit 31 (ucode.h:866) and ALU word 1 is_predicated is bit 28
                // (ucode.h:2076), so the position is a property of the layout,
                // not of "a fetch" and not of DecodedInstruction. DecodeInstruction
                // reads these same two bits (xenos_microcode.cpp:167-168, and
                // src/gpu_cp.cpp:1295-1296 on the CP side), so the shifts below
                // are a redundant second read, kept so the derivation further
                // down cannot be broken by a layout change in one decoder.
                // The 30/31 evidence is on IrInstruction::fetchFlagBits in
                // xenos_shader_ir.h: the live full/mini pair 0x00393A88 /
                // 0x40263688 in which bit 30 separates the two and bit 28 is 0
                // on both, plus reserved2 (bits 22-23) reading 0 on every vfetch
                // word1 reachable from this tree.
                if (isFetch) {
                    ir.fetchFlagBits = uint8_t(((iw1 >> 30) & 0x1) |
                                              (((iw1 >> 31) & 0x1) << 1));
                }
                ir.decoded  = DecodeInstruction(iw0, iw1, iw2, isFetch);
                out.instructions.push_back(ir);
            }
        }
    }

    // Constant table
    out.constants.clear();
    uint32_t cto = ReadBE32(data + 16);
    // Promote to size_t before adding: cto/ctSize are 32-bit guest fields and
    // can wrap past the buffer when summed in uint32_t (a crafted container
    // with cto near 0xFFFFFFFF would pass the guard and read ~4 GB OOB).
    if (cto != 0 && size_t(cto) + 24 <= out.virtualSize) {
        const uint8_t* ctd = data + cto;
        uint32_t ctSize      = ReadBE32(ctd + 0);
        uint32_t ctConstants = ReadBE32(ctd + 12);
        uint32_t ctInfoOff   = ReadBE32(ctd + 16);
        if (size_t(cto) + ctSize <= out.virtualSize) {
            // Cap iterations to the validated table region; ctConstants is
            // unvalidated and could otherwise loop ~4 G times (CPU DoS).
            const uint32_t maxConstants =
                uint32_t(std::min<size_t>(ctSize / 16, uint32_t(-1)));
            uint32_t capped = std::min(ctConstants, maxConstants);
            for (uint32_t ci = 0; ci < capped; ++ci) {
                const size_t off = size_t(ctInfoOff) + size_t(ci) * 16;
                if (off + 16 > ctSize) break;
                const uint8_t* ciPtr = ctd + off;
                ConstantEntry entry;
                entry.info.nameOffset    = ReadBE32(ciPtr + 0);
                entry.info.registerSet   = static_cast<RegisterSet>(ReadBE16(ciPtr + 4));
                entry.info.registerIndex = ReadBE16(ciPtr + 6);
                entry.info.registerCount = ReadBE16(ciPtr + 8);
                entry.info.reserved      = ReadBE16(ciPtr + 10);
                entry.info.typeInfo      = ReadBE32(ciPtr + 12);
                entry.info.defaultValue  = ReadBE32(ciPtr + 16);
                // Bounds-check the constant name before reading it: nameOffset
                // is an unvalidated, table-relative guest field, so it can
                // point at or past the end of the constant table.
                {
                    const size_t nameOff = size_t(entry.info.nameOffset);
                    if (nameOff < ctSize) {
                        const uint8_t* ns = ctd + nameOff;
                        size_t remain = ctSize - nameOff;
                        size_t len = 0;
                        while (len < remain && ns[len] != 0) ++len;
                        entry.name.assign(ns, ns + len);
                    }
                }
                if (entry.info.typeInfo != 0 && entry.info.typeInfo + kTypeInfoSize <= ctSize) {
                    const uint8_t* tp = ctd + entry.info.typeInfo;
                    entry.type.parameterClass = ReadBE16(tp + 0);
                    entry.type.parameterType  = ReadBE16(tp + 2);
                    entry.type.rows           = ReadBE16(tp + 4);
                    entry.type.columns        = ReadBE16(tp + 6);
                    entry.type.elements       = ReadBE16(tp + 8);
                    entry.type.structMembers  = ReadBE16(tp + 10);
                    entry.type.structMemberInfo = ReadBE32(tp + 12);
                }
                out.constants.push_back(entry);
            }
        }
    }

    // Per-stage surfaces: VS decodes vertex elements plus its interpolators,
    // PS decodes pixel outputs plus its interpolators (both stages append to
    // out.interpolators).
    out.vertexElements.clear();
    out.interpolators.clear();
    out.vertexElementsDerived = false;
    out.interpolatorsDerived = false;
    out.pixelOutputs = PixelOutputs{};
    if (out.isVertex) {
        // VS header: sp+24 is a start index into the 4-byte-entry array of
        // vertex elements and interpolators that begins at sp+36; sp+28 is the
        // vertex element count. Vertex element i sits at array index
        // sp+24 + i, interpolator i at sp+24 + count + i. Element entries pack
        // { address:12, usage:4, usageIndex:4 }; interpolator entries are
        // packed differently (see the interpolator block below).
        uint32_t veStart = ReadBE32(sp + 24);
        uint32_t veCount = ReadBE32(sp + 28);
        // Promote to size_t before multiplying: (veStart+veCount+32)*4 can
        // wrap in uint32_t, letting the guard pass while the element read
        // wraps ~4 GB OOB (crafted container with veStart near 0xFFFFFFFF).
        if (veCount <= 32 &&
            size_t(so) + 36 + (size_t(veStart) + veCount + 32) * 4 <= out.virtualSize) {
            for (uint32_t ve = 0; ve < veCount; ++ve) {
                uint32_t val = ReadBE32(sp + 36 + (size_t(veStart) + ve) * 4);
                VertexInput vi;
                vi.address    = val & 0xFFF;
                vi.usage      = (val >> 12) & 0xF;
                vi.usageIndex = (val >> 16) & 0xF;
                out.vertexElements.push_back(vi);
            }
            // VS interpolators: emitted outputs, stored right after the vertex
            // elements in the same array, packed
            // { usageIndex:4, usage:4, reg:4 }.
            const uint32_t interpCount = out.interpolatorCount();
            if (interpCount <= 32 && size_t(so) + 36 +
                                         (size_t(veStart) + veCount + interpCount) * 4 <=
                                     out.virtualSize) {
                for (uint32_t i = 0; i < interpCount; ++i) {
                    uint32_t word = ReadBE32(sp + 36 + (size_t(veStart) + veCount + i) * 4);
                    VertexInput in;
                    in.usageIndex = (word >> 0) & 0xF;
                    in.usage      = (word >> 4) & 0xF;
                    in.reg        = (word >> 8) & 0xF;
                    out.interpolators.push_back(in);
                }
            }
        }
    } else {
        // PS: pixel outputs at sp+28, interpolator table right after at
        // sp+32. (sp+24, the VS element start index, is not read here.)
        uint32_t psOutputs = ReadBE32(sp + 28);
        out.pixelOutputs.color0 = (psOutputs & 0x01) != 0;
        out.pixelOutputs.color1 = (psOutputs & 0x02) != 0;
        out.pixelOutputs.color2 = (psOutputs & 0x04) != 0;
        out.pixelOutputs.color3 = (psOutputs & 0x08) != 0;
        out.pixelOutputs.depth  = (psOutputs & 0x10) != 0;

        // Interpolator table follows the outputs field. Each entry is
        // Interpolator { usageIndex:4, usage:4, reg:4, pad:20 }.
        const uint32_t interpCount = out.interpolatorCount();
        if (interpCount <= 32 && size_t(so) + 32 + size_t(interpCount) * 4 <= out.virtualSize) {
            for (uint32_t i = 0; i < interpCount; ++i) {
                uint32_t word = ReadBE32(sp + 32 + i * 4);
                VertexInput in;
                in.usageIndex = (word >> 0) & 0xF;
                in.usage      = (word >> 4) & 0xF;
                in.reg        = (word >> 8) & 0xF;
                out.interpolators.push_back(in);
            }
        }
    }

    // The container declared no table (or its declared table was empty): fall
    // back to the program's own instruction stream. See the derivation notes
    // above the helper for what is measured and what is conventional.
    if (out.isVertex) {
        if (out.vertexElements.empty())
            DeriveVertexElementsFromInstructionStream(out);
        // The EXPORT set is a separate question from the declaration tables and is
        // answered for every VS whether or not a table was declared: it is the
        // per-draw half of the reference's interpolator intersection
        // (Shader::writes_interpolators), and a VS whose container declares
        // interpolants must still report which registers it actually writes.
        DeriveVertexInterpolatorExports(out);
    } else {
        if (out.interpolators.empty())
            DerivePixelInterpolatorsFromInstructionStream(out);
    }

    return true;
}


// ---------------------------------------------------------------------------
// Instruction-stream derivation of the two declaration tables.
//
// WHY THIS EXISTS, MEASURED. The container a live draw is parsed from is NOT
// guest data: it is a host-synthesized envelope (render_thread.cpp:928-955)
// whose virtualSize is 60 (render_thread.cpp:866) and whose element start /
// element count words are never written, so both read as 0. The .fxc
// declaration tables are therefore absent BY CONSTRUCTION, and
// ReferencedVertexInputs then resolves every fetch through its "first element"
// fallback (shader_translator.cpp:68-78), which with an empty table leaves an
// initialised usage 0 -- POSITION -- standing for every semantic.
//
// The vfetch decode in the captured bodies reproduces the guest's own
// vertex-fetch words exactly (CP-FETCHVB-DESC vs CP-SHADER-BODY #3, w689):
//
//   draw 1  addr=3  word0=30081000  word1=00393A88  word2=00000007
//           dst_reg = word0[17:12] = 1, format = word1[21:16] = 57,
//           stride = word2[7:0] = 7, offset = word2[30:8] = 0
//   draw 1  addr=4  word0=00080000  word1=40263688  word2=00000300
//           dst_reg = 0, format = 38, is_mini_fetch = word1[30] = 1,
//           offset = 3, stride field 0
//   draw 2  addr=2  word0=00080000  word1=00253B48  word2=00000002
//           dst_reg = 0, format = 37, stride = 2, offset = 0
//
// and each of those registers is read back by an ALU instruction that exports
// it (word0 bit 15 = exportData, word0[5:0] = vectorDest; the register a
// source operand names is word2[23:16]/[15:8]/[7:0] when the matching
// srcNSelect bit -- word2[31]/[30]/[29] -- is 1, which is the same
// select-means-register rule NoteOperand already uses at
// shader_translator.cpp:235-241):
//
//   draw 1  addr=5  c80F8000 00000000 E2000000  -> reads r0, export 0
//   draw 1  addr=6  C80F803E 00000000 E2010100  -> reads r1, export 62
//   draw 2  addr=3  C80F803E 00000000 E2000000  -> reads r0, export 62
//
// So the declaration IS in the instruction stream, one register hop away, and
// that hop is guest-measured end to end: which bytes of the vertex stream a
// fetch covers (format/stride/offset), which register receives them
// (dst_reg), which instruction consumes that register, and which export
// register it becomes.
//
// WHAT IS MEASURED vs WHAT IS CONVENTIONAL. Every field above is a guest word.
// Exactly ONE thing is a convention, and it is the NAME of the semantic:
//   * export register 62 -> POSITION, and export registers 0-15 ->
//     interpolants are already this project's stated reading of the export
//     register space (shader_translator.cpp:108-110).
//   * the reference names those interpolants TEXCOORD#
//     (.research/xenia/src/xenia/gpu/dxbc_shader_translator.cc:3098 VS output
//     signature "Interpolators (TEXCOORD#)", and :2825 for the matching PS
//     input signature), numbering them by DENSE RANK in the interpolant mask
//     (:3110 `interpolator.semantic_index = i`, :2843 for the PS side).
//   * THIS project instead numbers by the guest's own export register
//     (shader_translator.cpp:679-680 already emits `TEXCOORD<exportReg>` on
//     the VS output side). Dense-rank numbering cannot be used here because it
//     needs the full interpolant mask, which lives in register state this
//     project does not capture; numbering by the export register needs only the
//     program, and VS-output and PS-input both apply it, so the two signatures
//     still agree -- which is the only property D3D12 requires.
//
// NO FALLBACK. A fetch whose destination register is never consumed by an
// export instruction, or whose export register is not one of the two nameable
// ranges, produces NO element. Nothing is defaulted to POSITION. A program
// that declares nothing this way keeps an empty table and the caller's refusal
// stands.

// Xenos VS export register space (shader_translator.cpp:108-110).
constexpr uint32_t kVsExportPosition = 62;      // oPos
constexpr uint32_t kVsExportInterpolantFirst = 0;
constexpr uint32_t kVsExportInterpolantLast = 15;

// D3DXDECLUSAGE values (the numbering VertexUsageSemanticName and the
// translator's kUsageVariables share; POSITION = 0, TEXCOORD = 5).
constexpr uint32_t kUsagePosition = 0;
constexpr uint32_t kUsageTexCoord = 5;

// Guest register file: 32 addressable vector registers
// (shader_translator.cpp:126, kRegisterCount).
constexpr uint32_t kGuestRegisterCount = 32;

// Cap on a derived table, matching the declared path's own bound.
constexpr size_t kMaxDerivedInputs = 32;

// xenia::kMaxInterpolators (.research/xenia/src/xenia/gpu/xenia.h:802) -- the
// ceiling the reference clamps its interpolator count to
// (shader_translator.cc:340-341), and the width of the masks it builds.
constexpr uint32_t kMaxInterpolators = 16;

// The export register a source register feeds, or false when the instruction
// does not export. `select` is the guest srcNSelect bit: 1 names a register,
// 0 names a constant index, which is NOT a register read and must not be
// treated as one.
static bool FeedsExport(const DecodedInstruction& d, uint32_t srcReg,
                        bool select, uint32_t& exportReg) {
    if (!select) return false;
    if (d.kind != InstructionKind::Alu || !d.exportData) return false;
    exportReg = d.vectorDest;
    return true;
}

// Name the semantic an export register carries. False for every register this
// project cannot name (63 = point size / edge / kill vertex, and anything
// outside the interpolant range), so an unnamed export yields no element.
static bool ExportRegisterToSemantic(uint32_t exportReg, uint32_t& usage,
                                     uint32_t& usageIndex) {
    if (exportReg == kVsExportPosition) {
        usage = kUsagePosition;
        usageIndex = 0;
        return true;
    }
    if (exportReg >= kVsExportInterpolantFirst &&
        exportReg <= kVsExportInterpolantLast) {
        usage = kUsageTexCoord;
        usageIndex = exportReg;
        return true;
    }
    return false;
}

// Instructions in program (address) order. The decode loop emits in control-
// flow block order, which is address order for a well-formed program but is
// not guaranteed to be; deriving from sorted order is the conservative choice
// because the mini-fetch stride inheritance is order-sensitive.
static void SortedInstructionOrder(const ShaderProgram& prog,
                                   std::vector<const IrInstruction*>& out) {
    out.clear();
    out.reserve(prog.instructions.size());
    for (const auto& ir : prog.instructions) out.push_back(&ir);
    std::stable_sort(out.begin(), out.end(),
                     [](const IrInstruction* a, const IrInstruction* b) {
                         return a->address < b->address;
                     });
}

// Effective element stride for a vertex fetch is applied where the element is
// actually consumed, in ReferencedVertexInputs (shader_translator.cpp), which
// is the only reader of a stride. This file only derives WHICH element exists.

// Derive the VS vertex-element table from the program's own instructions.
static void DeriveVertexElementsFromInstructionStream(ShaderProgram& out) {
    std::vector<const IrInstruction*> order;
    SortedInstructionOrder(out, order);

    // Registers a vfetch writes, and the export each one is consumed by. The
    // FIRST consuming export in address order wins; a register consumed by
    // several exports cannot be named by one semantic, so the first is the
    // only non-arbitrary choice and it is deterministic.
    std::unordered_set<uint32_t> fetched;
    for (const IrInstruction* ir : order) {
        if (!ir->isFetch || ir->decoded.kind != InstructionKind::VertexFetch)
            continue;
        if (ir->decoded.dstRegister < kGuestRegisterCount)
            fetched.insert(ir->decoded.dstRegister);
    }
    std::unordered_map<uint32_t, uint32_t> consumedBy;
    for (const IrInstruction* ir : order) {
        if (ir->isFetch) continue;
        const DecodedInstruction& d = ir->decoded;
        uint32_t exportReg = 0;
        const uint32_t srcs[3] = {d.src1Register, d.src2Register, d.src3Register};
        const bool sels[3] = {d.src1Select, d.src2Select, d.src3Select};
        for (int k = 0; k < 3; ++k) {
            if (!FeedsExport(d, srcs[k], sels[k], exportReg)) continue;
            if (fetched.count(srcs[k]) == 0) continue;
            if (consumedBy.count(srcs[k]) != 0) continue;
            consumedBy.emplace(srcs[k], exportReg);
        }
    }

    for (const IrInstruction* ir : order) {
        if (!ir->isFetch || ir->decoded.kind != InstructionKind::VertexFetch)
            continue;
        const uint32_t dstReg = ir->decoded.dstRegister;
        if (out.vertexElements.size() >= kMaxDerivedInputs) break;
        if (dstReg >= kGuestRegisterCount) continue;
        auto it = consumedBy.find(dstReg);
        if (it == consumedBy.end()) continue;  // consumed by no export: no name
        uint32_t usage = 0, usageIndex = 0;
        if (!ExportRegisterToSemantic(it->second, usage, usageIndex)) continue;
        VertexInput vi;
        // `address` is the stream address the resolver matches a fetch against
        // (ReferencedVertexInputs, shader_translator.cpp:68-73). For a derived
        // element the fetch's own instruction address IS that address, which is
        // what makes the resolver bind rather than fall back.
        vi.address    = uint32_t(ir->address);
        vi.usage      = uint16_t(usage);
        vi.usageIndex = uint16_t(usageIndex);
        vi.reg        = uint16_t(dstReg);
        out.vertexElements.push_back(vi);
    }
    out.vertexElementsDerived = !out.vertexElements.empty();
}

// Whether a FETCH actually writes its destination register, i.e. whether at
// least one component of the destination swizzle selects a REGISTER component.
// Swizzle component values 0-3 name a register component and 4/5 are the zero
// and one constants, so an all-4/5 swizzle writes no register at all -- the
// same reading the emitter applies when it decides to emit `.x = 0.0f`
// (shader_translator.cpp:1242-1244 for the classification, :1251-1259 for the
// emission). The reference reaches the same verdict from the instruction's own
// result mask, `if (!result.GetUsedWriteMask()) return;`
// (.research/xenia/src/xenia/gpu/shader_translator.cc:566-567 for a fetch, :583-585
// for an ALU), which is the same test expressed on the write side.
static bool FetchWritesRegister(const DecodedInstruction& d) {
    for (int i = 0; i < 4; ++i)
        if (((d.dstSwizzle >> (i * 3)) & 0x7) <= 3) return true;
    return false;
}

// Derive the PS interpolant table from the program's own instructions.
//
// THE RULE IS A REGISTER PREFIX. The reference computes a pixel shader's
// interpolator mask from a high-water mark, NOT from the set of registers the
// program reads (.research/xenia/src/xenia/gpu/shader_translator.cc:336-354,
// Shader::GetInterpolatorInputMask):
//
//     count = min(kMaxInterpolators,
//                 max(register_static_address_bound(),
//                     GetDynamicAddressableRegisterCount(ps_num_reg)))
//     mask  = (UINT32_C(1) << count) - 1
//
// `register_static_address_bound` is raised by TWO things, and this file
// implemented only one of them for a long time:
//
//   (a) a RESULT targeting a REGISTER, addressed absolutely, with a non-zero
//       write mask -- GatherFetchResultInformation (shader_translator.cc:565-578)
//       and GatherAluResultInformation (:581-596). A zero write mask returns
//       before the switch (:566-567, :583-585), an absolute register target
//       raises the bound to `storage_index + 1`, and a loop-relative target
//       instead sets `uses_register_dynamic_addressing` (:575-577, :593-594);
//   (b) an OPERAND that is a REGISTER, addressed absolutely --
//       GatherOperandInformation (:532-543), reached for every ALU vector and
//       scalar operand by GatherAluInstructionInformation (:502-510) and every
//       fetch operand (:399-405, :452-455). THIS IS A READ. It raises the bound
//       identically, and a loop-relative operand sets
//       `uses_register_dynamic_addressing` the same way (:540-542).
//
// (b) is the half that was missing, and it is not a detail: a program that only
// ever READS a register has bound 0 under (a) alone, which empties the prefix
// and silently turns a live interpolant into a zero seed. Measured inside the
// function. `kMaxInterpolators` is 16 (xenia.h:802).
//
// An operand that is a c-register CONSTANT, or an immediate, is not a register
// operand and raises nothing (shader_translator.cc:1216-1224 builds the operand
// only for `src_is_temp(i)`; bit 7 of the packed index marks an immediate).
//
// AN EXPORT RAISES NOTHING, and that is the entire fix. The result target is
// chosen from the export register (shader_translator.cc:1304-1348): 0-15 are
// kVSInterpolator0..15 for a VERTEX shader, 62 is kVSPosition, and for a PIXEL
// shader 0-3 are kPSColor0..3 and 4 is kPSDepth (ucode.h:1793-1811). None of
// those is kRegister, so an export never contributes to the bound. The command
// processor then ANDs the pixel mask with the vertex shader's own interpolator
// export set -- `vertex_shader->writes_interpolators() &
// pixel_shader->GetInterpolatorInputMask(...)`
// (.research/xenia/src/xenia/gpu/d3d12/d3d12_command_processor.cc:2081-2086,
// and the identical vulkan_command_processor.cc:2206-2211), passing that one mask
// to BOTH stages (:2088-2094), which is what the equality asserted at
// d3d12/pipeline_cache.cc:1703-1704 records. That intersection is applied by
// ApplyInterpolatorIntersection, further down.
//
// WHAT WAS WRONG, MEASURED ON THE RAW WORDS. The live pixel program
// 7B0032AD4C5B576D is nine dwords at guest VA 0x82061C60 and holds ONE
// executable instruction, at address 1:
//
//     C80F8000 00000000 E2000000
//
// word0 bit 15 (exportData) = 1 and word0 bits 5:0 (vectorDest) = 0, so its
// result goes to eM0 = colour 0 and NOT to a register: the bound stays 0, the
// prefix is empty, and the reference declares NO interpolant. The removed loop
// instead walked the SOURCE operands, found src1Select (word2 bit 31) = 1 with
// src1Register (word2 bits 23:16) = 0, found nothing writing r0, and named r0
// an interpolant. r0 IS read and IS unwritten, so both of that loop's own tests
// passed -- the tests were simply not the rule. It also masked the register
// field with `& 0x3F` nowhere: the low six bits are the register and bits 6/7
// are the relative/absolute-value flags (`src_temp_reg`,
// ucode.h:1884-1892), which is the masking NoteOperand already does
// (shader_translator.cpp:281).
//
// THE ASSUMPTION THIS KILLS: "PS register N is interpolant N". Its whole
// measured basis was n=1 -- one instance, and that instance is this program,
// which is the case where it is false. The register-space reading it rested on
// (export registers 0-15 are interpolants) SURVIVES and is still
// kVsExportInterpolantFirst/Last above; what does not survive is the inference
// from "a PS read r0" to "r0 is an interpolant".
//
// A READ IS STILL REQUIRED. The reference's prefix deliberately
// over-approximates -- it seeds every register below the mask and then lets the
// program's own writes overwrite them (dxbc_shader_translator.cc:688-701,
// writing literal 0.0 into everything outside the mask) -- precisely because it
// has no read set either. This derivation keeps the read requirement it always
// had, so a register nobody reads is never named, and adds the bound as the
// gate that was missing. A PS that genuinely reads an interpolant still finds
// it: the register is read, it is below the bound, and nothing wrote it.
//
// NO FALLBACK, restated. A register at or above the bound, or one this program
// writes, produces no entry. A program that declares nothing keeps an empty
// table and the caller's refusal stands.
static void DerivePixelInterpolatorsFromInstructionStream(ShaderProgram& out) {
    std::vector<const IrInstruction*> order;
    SortedInstructionOrder(out, order);

    // Pass 1: the registers this program writes, and the high-water mark the
    // reference calls register_static_address_bound.
    std::unordered_set<uint32_t> written;
    uint32_t bound = 0;
    bool boundUnknown = false;
    for (const IrInstruction* ir : order) {
        const DecodedInstruction& d = ir->decoded;
        if (d.kind == InstructionKind::Alu) {
            // ---- OPERANDS FIRST, AND THIS IS THE HALF THAT WAS MISSING ----
            //
            // register_static_address_bound is raised by GatherOperandInformation
            // (.research/xenia/src/xenia/gpu/shader_translator.cc:532-543), which
            // is reached for EVERY ALU vector and scalar operand by
            // GatherAluInstructionInformation (:502-510). It raises the bound on an
            // ABSOLUTE REGISTER OPERAND -- a READ, not a write. An ALU operand only
            // becomes a register operand when srcNSelect is 1
            // (.research/xenia/src/xenia/gpu/shader_translator.cc:1216-1224), with
            // storage_index = src_temp_reg(reg) = reg & 0x3F, and it is
            // kLoopRelative (which sets uses_register_dynamic_addressing_ instead)
            // exactly when bit 6 of the packed index is set. A fetch's operands go
            // through the same function (:399-405, :452-455).
            //
            // FALSIFIED THE OTHER WAY, MEASURED. This derivation used to raise the
            // bound from WRITE results only, on the strength of the comment above
            // it claiming "register_static_address_bound is raised by exactly one
            // thing: an instruction whose result targets a REGISTER". That claim
            // is false. The live pixel program 7B0032AD4C5B576D is ONE instruction
            // whose three srcNSelect bits are all set and whose three packed source
            // indices are all 0x00 (word2 = 0xE2000000: bits 29/30/31 set, bits
            // 23:16 / 15:8 / 7:0 zero), i.e. it reads r0 and writes no register --
            // its result exports to eM0 (word0 = 0xC80F8000: bit 15 export_data,
            // bits 5:0 vector_dest = 0, bits 19:16 vector_write_mask = 0xF). The
            // write-only bound was therefore 0, the interpolator prefix was empty,
            // this program was given NO interpolant, and the pixel shader's r0
            // seeded from 0.0 -- which is the black draw. The reference gives this
            // same program bound = 1 from the read alone.
            const uint32_t srcReg[3] = {d.src1Register, d.src2Register,
                                        d.src3Register};
            const bool srcSel[3] = {d.src1Select, d.src2Select, d.src3Select};
            for (int i = 0; i < 3; ++i) {
                if (!srcSel[i]) continue;                 // c-register, not a GPR
                if ((srcReg[i] & 0x80) != 0) continue;    // immediate, not a GPR
                if ((srcReg[i] & 0x40) != 0) {            // kLoopRelative
                    boundUnknown = true;
                    continue;
                }
                const uint32_t r = srcReg[i] & 0x3F;
                if (r < kGuestRegisterCount) bound = std::max(bound, r + 1u);
            }
            // ---- RESULTS, the half that was already here ----
            // An ALU instruction with the export bit set writes to the EXPORT
            // target, not to the register file, so it contributes neither a
            // written register nor to the bound. Same rule the emitter applies --
            // "Export register: writes go to the export target when exportData"
            // (shader_translator.cpp:747-751, write-mask swap at :788 and
            // :1148). Before this was made explicit the live PS's oC0 was
            // mistaken for a register write, and separately its eM0 index was
            // allowed to raise the bound.
            if (d.exportData) continue;
            if (d.vectorWriteMask != 0) {
                if (d.vectorDestRelative) boundUnknown = true;
                else if (d.vectorDest < kGuestRegisterCount) {
                    written.insert(d.vectorDest);
                    bound = std::max(bound, d.vectorDest + 1u);
                }
            }
            if (d.scalarWriteMask != 0) {
                if (d.scalarDestRelative) boundUnknown = true;
                else if (d.scalarDest < kGuestRegisterCount) {
                    written.insert(d.scalarDest);
                    bound = std::max(bound, d.scalarDest + 1u);
                }
            }
            continue;
        }
        // A vertex fetch cannot appear in a pixel program; skipping it keeps
        // this pass from reading a field that means nothing for this stage.
        if (d.kind == InstructionKind::VertexFetch) continue;
        if (!FetchWritesRegister(d)) continue;
        if (d.dstRelative) boundUnknown = true;
        else if (d.dstRegister < kGuestRegisterCount) {
            written.insert(d.dstRegister);
            bound = std::max(bound, d.dstRegister + 1u);
        }
    }

    // GetDynamicAddressableRegisterCount (.research/xenia/src/xenia/gpu/shader.h
    // :938-945), verbatim in effect:
    //
    //     if (!uses_register_dynamic_addressing()) return 0;
    //     return std::max(program_cntl_num_reg + 1, register_static_address_bound());
    //
    // The `if` is the load-bearing half, and it is what lets SQ_PROGRAM_CNTL reach
    // only a dynamically-addressed program. A program with no relative register
    // operand and no relative destination gets 0 here whatever ps_num_reg says, so
    // interpolator_count collapses to register_static_address_bound. That is the
    // reference, not a simplification of it: the same helper also feeds
    // ShaderTranslator::register_count_ (shader_translator.cc:643-649), which is
    // the bound of the GPR-seeding loop itself (dxbc_shader_translator.cc:689).
    //
    // ps_num_reg arrives on ShaderProgram rather than out of the container because
    // it is REGISTER STATE and a container declares no such field (see
    // ShaderProgram::psNumReg). The measured value on the live draw is 0 --
    // build/w704.log, `CP-REG-T0 #17 op=IB base=2180 n=2 written=2 val=1000000E`,
    // whose ps_num_reg field (registers.h:136, bits 8:13) reads 0 -- and the live
    // program uses no register dynamic addressing, so this term is 0 either way on
    // this draw. It is plumbed because a program that DOES use relative addressing
    // needs it, and because a wrong value here silently changes the interpolant
    // count and therefore every seed below the prefix.
    const uint32_t dynamicCount =
        boundUnknown ? std::max(out.psNumReg + 1u, bound) : 0u;
    out.usesRegisterDynamicAddressing = boundUnknown;
    out.registerStaticBound = bound;
    out.dynamicAddressableRegCount = dynamicCount;
    const uint32_t interpolatorCount =
        std::min(kMaxInterpolators, std::max(bound, dynamicCount));

    // Registers at or above the prefix cannot be interpolants: the reference's mask
    // is a mask of exactly this many bits, so it stops here. `boundUnknown` is the
    // one case where the prefix is wider than register_static_address_bound alone,
    // and it is now measured from ps_num_reg rather than assumed to be the whole
    // interpolant range. That range remains the standing ceiling because it is this
    // project's own reading of the export register space
    // (shader_translator.cpp:108-110) and it over-approximates, which is the safe
    // direction. FALSIFIER for that ceiling: a live pixel program whose correct
    // interpolant set is a strict subset of registers 0-15. No such program is
    // reachable from build/w704.log -- all four live programs have absolute vector
    // and scalar destinations and absolute source indices (measured:
    // vectorDestRelative, scalarDestRelative and packed-source bit 6 are false on
    // every one of their ALU instructions).
    const uint32_t limit = std::min(interpolatorCount, kVsExportInterpolantLast + 1u);

    for (const IrInstruction* ir : order) {
        if (ir->isFetch) continue;
        const DecodedInstruction& d = ir->decoded;
        if (d.kind != InstructionKind::Alu) continue;
        const uint32_t srcs[3] = {d.src1Register, d.src2Register, d.src3Register};
        const bool sels[3] = {d.src1Select, d.src2Select, d.src3Select};
        for (int k = 0; k < 3; ++k) {
            if (!sels[k]) continue;  // constant index, not a register read
            const uint32_t r = srcs[k] & 0x3F;  // src_temp_reg: low six bits
            if (r >= limit) continue;           // above the write bound: not an interpolant
            if (written.count(r) != 0) continue;
            if (out.interpolators.size() >= kMaxDerivedInputs) break;
            bool dup = false;
            for (const auto& in : out.interpolators)
                if (in.reg == r) { dup = true; break; }
            if (dup) continue;
            VertexInput vi;
            vi.address    = 0;
            vi.usage      = uint16_t(kUsageTexCoord);
            vi.usageIndex = uint16_t(r);
            vi.reg        = uint16_t(r);
            out.interpolators.push_back(vi);
        }
    }
    out.interpolatorsDerived = !out.interpolators.empty();
}

// Derive the VS's INTERPOLATOR EXPORT SET -- Shader::writes_interpolators()
// (.research/xenia/src/xenia/gpu/shader.h:957) -- from the program's own
// instruction stream. This is the per-draw half of the reference's interpolator
// intersection and it had no home in this tree at all; it is the same shape of
// derivation as the two above it, on the same SortedInstructionOrder walk, and it
// deliberately does not touch the declaration tables.
//
// THE RULE, AND IT IS ONE BIT-PLACE. writes_interpolators_ is set in exactly one
// arm of GatherAluResultInformation
// (.research/xenia/src/xenia/gpu/shader_translator.cc:597-599):
//
//     case InstructionStorageTarget::kInterpolator:
//       writes_interpolators_ |= uint32_t(1) << result.storage_index;
//       break;
//
// and the storage target is chosen in ParseAluInstruction (:1304-1348). For a
// VERTEX shader an export register in 0-15 becomes
// InstructionStorageTarget::kInterpolator with storage_index = export - 0 (:1320-1324),
// 62 becomes kPosition (:1325-1326), and 63 becomes
// kPointSizeEdgeFlagKillVertex (:1327-1329) -- a different arm, :600-601. A
// NON-exporting instruction keeps kRegister (:1306), which is neither arm. So:
//
//   export to 0-15  -> sets the bit (this is the ONLY setter)
//   export to 62    -> POSITION, does not
//   export to 63    -> point size / edge flag / kill vertex, does not
//   a vfetch write  -> kRegister, and a fetch cannot export at all
//                      ("Fetch instructions can't export",
//                      shader_translator.cc:565-570)
//   no export       -> kRegister, does not
//
// The two remaining gates are the reference's own: a result with an EMPTY USED
// WRITE MASK returns before the switch (:583-585), and only the VECTOR result
// reaches GatherAluResultInformation through kInterpolator -- the scalar result
// goes to the same function but an export writes the vector destination
// (ucode.h:2041-2042), so the scalar arm contributes nothing extra here.
//
// MEASURED, both live pairings (build/w704.log CP-SHADER-BODY rows, and the
// decoded IR):
//   draw #1 VS D99385F5E67A3EB1, 27 dwords, 5 instructions:
//     [5] ALU export=1 vectorDest=0  vectorWriteMask=0xF -> interpolant 0, bit set
//     [6] ALU export=1 vectorDest=62 vectorWriteMask=0xF -> POSITION, bit NOT set
//     => writes_interpolators() == 0x00000001
//   draw #2 VS AEAF1F096E09B347, 15 dwords, 2 instructions:
//     [3] ALU export=1 vectorDest=62 vectorWriteMask=0xF -> POSITION only
//     => writes_interpolators() == 0x00000000
// Word-level: both are C80F80xx, bit 15 = export_data and bits 5:0 =
// vector_dest, with the vector write mask 0xF in bits 19:16 (ucode.h:2046-2062).
// So the two draws get DIFFERENT masks from the SAME rule, which is what makes
// the pairing a per-draw fact rather than a program fact.
//
// NOT SUMMARISED INTO THE TABLE BELOW, and the reason is worth stating: the
// declaration table this file also derives (DeriveVertexElementsFromInstructionStream,
// which maps a FETCH to a semantic by asking which export consumes it) is about
// naming inputs, while this mask is about which interpolants leave the VS at all.
// They disagree in the live data -- draw #1's VS exports interpolant 0 from a
// register NO fetch writes (r0, read-only), which the declaration derivation
// cannot name, and the mask still counts it. Collapsing one into the other would
// lose exactly the bit the pixel shader needs.
static void DeriveVertexInterpolatorExports(ShaderProgram& out) {
    std::vector<const IrInstruction*> order;
    SortedInstructionOrder(out, order);
    uint32_t mask = 0;
    for (const IrInstruction* ir : order) {
        // A fetch cannot export (shader_translator.cc:565-570); skip it before
        // touching a field that means nothing for this stage.
        if (ir->isFetch) continue;
        const DecodedInstruction& d = ir->decoded;
        if (d.kind != InstructionKind::Alu) continue;
        if (!d.exportData) continue;                 // kRegister, not kInterpolator
        if (d.vectorDest < kVsExportInterpolantFirst ||
            d.vectorDest > kVsExportInterpolantLast)
            continue;                                // 62 POSITION, 63 point/edge/kill
        // BOTH results, because the reference feeds both to the same function.
        //
        // GatherAluInstructionInformation calls GatherAluResultInformation TWICE
        // per ALU instruction -- once for `vector_and_constant_result` and once
        // for `scalar_result` (shader_translator.cc:502-503) -- and BOTH carry
        // the same storage_target (:1358 and :1399), which for a VS export of
        // 0-15 is kInterpolator with the same storage_index. So the bit is set
        // by whichever arm has a non-empty used write mask, and this used to
        // consult only the vector arm.
        //
        // The masks are not the raw fields. ucode.h:2011-2036:
        //   vector: (vwm & ~swm) | c0 | c1        scalar: swm & ~vwm
        //   c0 = (export && scalar_dest_rel) ? 0b1111 & ~(vwm|swm) : 0
        //   c1 = export ? vwm & swm : 0
        // and on an export c0 | c1 == vwm, so the vector arm reduces to
        // (vwm | c0) & 0xF and the scalar arm to (swm & ~vwm) & 0xF. The 0xF
        // is GetInstructionStorageTargetUsedComponentCount's default arm for
        // kInterpolator (shader.h:83-84), applied by GetUsedWriteMask
        // (shader.h:152-156).
        //
        // WHAT THAT COST, MEASURED. Testing only `vectorWriteMask != 0` is
        // exactly the scalar-only export encoding ucode.h:2058 calls legal
        // ("vector_write_mask 0, scalar_write_mask 1 - from scalar operation").
        // Over the 166-file .fxc corpus: 5 vertex containers where the
        // reference sets a bit this dropped -- shaders_ui_fxl_final_Gloss.fxc,
        // reference 0x000003FF against 0x000001FF, lost 0x00000200, from two
        // instructions with vwm=0x0 and swm=0x1 (corpus.exe, 506 containers,
        // 291 vertex, 5 differing before and 0 after). The dropped bit makes
        // ApplyInterpolatorIntersection remove an interpolant the reference
        // keeps, seeding that GPR with 0.0 instead of the VS's own export.
        //
        // IT IS NOT THE BLACK DRAW. Scanned every shader-body row in all 229
        // build/*.log: 334 export-bearing words, and ZERO vertex ones with
        // vwm==0 and swm!=0. The two live VS bodies reach the vector arm for
        // both their interpolant exports (w0 = C80F8000 and C80F803E, vwm 0xF).
        // A latent defect on 5 corpus shaders, not the fault in w720.log.
        const uint32_t vwm = d.vectorWriteMask & 0xFu;
        const uint32_t swm = d.scalarWriteMask & 0xFu;
        const uint32_t c0 = d.scalarDestRelative ? (0xFu & ~(vwm | swm)) : 0u;
        const uint32_t vectorUsed = (vwm | c0) & 0xFu;
        const uint32_t scalarUsed = (swm & ~vwm) & 0xFu;
        if (vectorUsed == 0 && scalarUsed == 0) continue;   // :583-585
        mask |= (1u << d.vectorDest);
    }
    out.writesInterpolators = mask;
}

InterpolatorIntersection ApplyInterpolatorIntersection(ShaderProgram& ps,
                                                      const ShaderProgram* vs) {
    InterpolatorIntersection r;
    r.candidatesBefore = ps.interpolators.size();
    r.psNumReg = ps.psNumReg;
    r.staticBound = ps.registerStaticBound;
    r.dynamicRegCount = ps.dynamicAddressableRegCount;
    // The PS's own input mask, a PREFIX mask, exactly
    // Shader::GetInterpolatorInputMask's shape
    // (.research/xenia/src/xenia/gpu/shader_translator.cc:336-344) using the two
    // terms DerivePixelInterpolatorsFromInstructionStream measured:
    //     count = min(kMaxInterpolators, max(staticBound, dynamicRegCount))
    //     mask  = (1 << count) - 1
    // recomputed here rather than carried, because the derivation's own `limit` is
    // additionally clamped to the export-register range and this value has to be
    // the reference's mask, not the derivation's ceiling.
    r.interpolatorCount = std::min(kMaxInterpolators,
                                   std::max(r.staticBound, r.dynamicRegCount));
    r.psInputMask = (r.interpolatorCount >= kMaxInterpolators)
                        ? 0xFFFFFFFFu
                        : ((1u << r.interpolatorCount) - 1u);
    if (vs != nullptr) {
        r.vsKnown = true;
        r.vsWritesInterpolators = vs->writesInterpolators;
    }
    // vs == nullptr leaves vsWritesInterpolators 0, so the intersection is 0:
    // an unpaired PS claims no interpolant. That is the reference's mask-0 branch
    // (dxbc_shader_translator.cc:689-700), not a fallback of this project's own.
    r.intersected = r.vsWritesInterpolators & r.psInputMask;

    // REMOVE ONLY. An entry survives exactly when the mask names its register, so
    // this cannot introduce an interpolant the PS's own stream did not name.
    if (r.intersected != 0u) {
        std::vector<VertexInput> keep;
        keep.reserve(ps.interpolators.size());
        for (const VertexInput& in : ps.interpolators) {
            if (in.reg < 32u && (r.intersected & (1u << in.reg)) != 0u)
                keep.push_back(in);
        }
        ps.interpolators.swap(keep);
    } else {
        ps.interpolators.clear();
    }
    r.kept = ps.interpolators.size();
    return r;
}


// FNV-1a 64-bit
static constexpr uint64_t kFNV1aOffset = 14695981039346656037ULL;
static constexpr uint64_t kFNV1aPrime  = 1099511628211ULL;
static void Hash(uint64_t& h, const void* data, size_t len) {
    const uint8_t* p = static_cast<const uint8_t*>(data);
    for (size_t i = 0; i < len; ++i) {
        h ^= uint64_t(p[i]);
        h *= kFNV1aPrime;
    }
}
template<typename T> static void HashVal(uint64_t& h, const T& v) {
    Hash(h, &v, sizeof(v));
}
template<typename T> static void HashBE32(uint64_t& h, T v) {
    uint32_t be = uint32_t(v);
    // hash in big-endian to match guest representation
    uint8_t b[4] = {uint8_t(be>>24), uint8_t(be>>16), uint8_t(be>>8), uint8_t(be)};
    Hash(h, b, 4);
}

uint64_t ComputeShaderProgramHash(const ShaderProgram& prog) {
    uint64_t h = kFNV1aOffset;

    HashVal(h, prog.isVertex);
    // SQ_PROGRAM_CNTL.ps_num_reg is REGISTER STATE, not program bytes: two draws
    // can carry byte-identical programs under different SQ_PROGRAM_CNTL values, and
    // ps_num_reg changes the pixel interpolator prefix
    // (DerivePixelInterpolatorsFromInstructionStream) and therefore the emitted
    // seed. Without this term those two draws would share a PSO whose shader was
    // built for the other mask. Every other new field -- writesInterpolators,
    // registerStaticBound, dynamicAddressableRegCount, usesRegisterDynamicAddressing
    // -- is a pure function of the instruction stream that is already hashed below,
    // so hashing them again would be redundant.
    HashVal(h, prog.psNumReg);
    HashBE32(h, prog.flags);
    HashBE32(h, prog.virtualSize);
    HashBE32(h, prog.physicalSize);
    HashBE32(h, prog.physicalOffset);
    HashBE32(h, prog.shaderSize);
    HashBE32(h, prog.fieldC);
    HashBE32(h, prog.field10);
    HashBE32(h, prog.interpolatorInfo);

    // F-609: the program hash is a PSO key component, so it must cover every
    // container surface that changes the generated HLSL. It previously covered
    // only the instruction stream, which meant two guests with different vertex
    // declarations (or a different constant register layout, hence a different
    // cbuffer packoffset) hashed IDENTICALLY and could share a PSO. The
    // vertex-element and interpolator tables decide the VS entry signature; the
    // constant register triples decide the cbuffer declaration.
    const uint32_t veCount = uint32_t(prog.vertexElements.size());
    // Provenance is a key component: a table derived from the instruction
    // stream and a table read from the container header produce different
    // entry signatures, so they must not share a PSO.
    HashVal(h, prog.vertexElementsDerived);
    HashVal(h, prog.interpolatorsDerived);
    HashVal(h, veCount);
    for (const auto& ve : prog.vertexElements) {
        HashVal(h, ve.usage);
        HashVal(h, ve.usageIndex);
        HashVal(h, ve.address);
        HashVal(h, ve.reg);
    }
    const uint32_t interpCount = uint32_t(prog.interpolators.size());
    HashVal(h, interpCount);
    for (const auto& in : prog.interpolators) {
        HashVal(h, in.usage);
        HashVal(h, in.usageIndex);
        HashVal(h, in.address);
        HashVal(h, in.reg);
    }
    HashVal(h, prog.pixelOutputs.color0);
    HashVal(h, prog.pixelOutputs.color1);
    HashVal(h, prog.pixelOutputs.color2);
    HashVal(h, prog.pixelOutputs.color3);
    HashVal(h, prog.pixelOutputs.depth);
    const uint32_t constCount = uint32_t(prog.constants.size());
    HashVal(h, constCount);
    for (const auto& c : prog.constants) {
        HashVal(h, static_cast<uint32_t>(c.info.registerSet));
        HashVal(h, c.info.registerIndex);
        HashVal(h, c.info.registerCount);
    }

    uint32_t icount = uint32_t(prog.instructions.size());
    HashVal(h, icount);
    for (const auto& ir : prog.instructions) {
        HashBE32(h, ir.address);
        HashVal(h, ir.isFetch);
        HashVal(h, ir.decoded.kind);
        // Fingerprint the fetch-side operand fields only. DecodeInstruction
        // fills dstRegister/srcRegister/constIndex/fetchOpcode for fetch
        // instructions and leaves them at their defaults for ALU ones, so an
        // ALU instruction contributes kind/isFetch/address/unknown but not
        // its vector/scalar opcodes, destinations, masks or sources.
        HashBE32(h, ir.decoded.fetchOpcode);
        HashBE32(h, ir.decoded.dstRegister);
        HashBE32(h, ir.decoded.srcRegister);
        HashBE32(h, ir.decoded.constIndex);
        HashVal(h, ir.decoded.unknown);
    }

    return h;
}

}  // namespace mcla::renderer
