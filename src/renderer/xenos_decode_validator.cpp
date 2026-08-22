// Standalone MCLA Xenos shader-microcode validator.
// Usage: xenos_decode_validator.exe <path-to-fxc-or-microcode>
//  - Parses Rockstar .fxc containers (flags 0x102A1100), decodes every VS/PS
//    microcode blob, and reports unknown instructions / OOB exec targets.
//  - If given a raw microcode file, decodes it directly.
// Exit code 0 = clean, 1 = errors found.

#include "xenos_microcode.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace mcla::renderer;

struct ContainerHeader {
    uint32_t flags, virtualSize, physicalSize, fieldC;
    uint32_t constantTableOffset, definitionTableOffset, shaderOffset;
    uint32_t field1C, field20;
};

struct ShaderHeader {
    uint32_t physicalOffset, size, field8, fieldC, field10, interpolatorInfo;
};

struct Stats {
    uint64_t containers = 0;
    uint64_t shaders = 0;
    uint64_t cleanShaders = 0;
    uint64_t unknownInstructions = 0;
    uint64_t oobExecs = 0;
    uint64_t returns = 0;
};

static uint32_t ReadBE32(const uint8_t* p) {
    return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) |
           (uint32_t(p[2]) << 8) | uint32_t(p[3]);
}

static void PrintMicrocode(const uint8_t* code, size_t size) {
    const size_t cf_bound = ComputeControlFlowByteBound(code, size);
    size_t n = cf_bound / 12;  // CF blocks (3 dwords each = 2 CF instrs)
    for (size_t b = 0; b < n; ++b) {
        const uint8_t* blk = code + b * 12;
        uint32_t w0 = ReadBE32(blk);
        uint32_t w1 = ReadBE32(blk + 4);
        uint32_t w2 = ReadBE32(blk + 8);

        for (int slot = 0; slot < 2; ++slot) {
            uint32_t cfw0 = slot == 0 ? w0 : ((w1 >> 16) | (w2 << 16));
            uint16_t cfw1 = slot == 0 ? static_cast<uint16_t>(w1 & 0xFFFF)
                                      : static_cast<uint16_t>(w2 >> 16);
            ControlFlowInstruction cf = DecodeControlFlow(cfw0, cfw1);
            std::printf("  [%04zu] %-20s addr=%-4u count=%u seq=0x%03X\n",
                        b * 2 + slot, ControlFlowOpcodeName(cf.opcode),
                        cf.address, cf.count, cf.sequence);
            if (cf.IsExec()) {
                size_t base = size_t(cf.address) * 12;
                if (cf.count > 0 && base + size_t(cf.count) * 12 > size) {
                    std::printf("        !! OOB exec target (base=%zu count=%u size=%zu)\n",
                                base, cf.count, size);
                    continue;
                }
                for (uint32_t i = 0; i < cf.count; ++i) {
                    const uint8_t* ip = code + base + i * 12;
                    uint32_t a = ReadBE32(ip);
                    uint32_t b_ = ReadBE32(ip + 4);
                    uint32_t c = ReadBE32(ip + 8);
                    bool isFetch = ((cf.sequence >> (2 * i)) & 1) != 0;
                    DecodedInstruction ins = DecodeInstruction(a, b_, c, isFetch);
                    std::printf("        +%04zu %-14s %s\n", base + i * 12,
                                ins.kind == InstructionKind::Alu ? "ALU"
                                : ins.kind == InstructionKind::VertexFetch ? "VERTEXFETCH"
                                : "TEXFETCH",
                                ins.unknown ? "??" : "ok");
                }
            }
            if (cf.opcode == ControlFlowOpcode::Return) return;
        }
    }
}

static bool DecodeMicrocode(const uint8_t* code, size_t size, Stats& stats,
                            bool print) {
    bool clean = true;
    const size_t cf_bound = ComputeControlFlowByteBound(code, size);
    size_t n = cf_bound / 12;
    for (size_t b = 0; b < n; ++b) {
        const uint8_t* blk = code + b * 12;
        uint32_t w0 = ReadBE32(blk);
        uint32_t w1 = ReadBE32(blk + 4);
        uint32_t w2 = ReadBE32(blk + 8);
        for (int slot = 0; slot < 2; ++slot) {
            uint32_t cfw0 = slot == 0 ? w0 : ((w1 >> 16) | (w2 << 16));
            uint16_t cfw1 = slot == 0 ? static_cast<uint16_t>(w1 & 0xFFFF)
                                      : static_cast<uint16_t>(w2 >> 16);
            ControlFlowInstruction cf = DecodeControlFlow(cfw0, cfw1);
            if (cf.IsExec()) {
                size_t base = size_t(cf.address) * 12;
                if (cf.count > 0 && base + size_t(cf.count) * 12 > size) {
                    ++stats.oobExecs;
                    clean = false;
                    continue;
                }
                for (uint32_t i = 0; i < cf.count; ++i) {
                    const uint8_t* ip = code + base + i * 12;
                    uint32_t a = ReadBE32(ip);
                    uint32_t b_ = ReadBE32(ip + 4);
                    uint32_t c = ReadBE32(ip + 8);
                    bool isFetch = ((cf.sequence >> (2 * i)) & 1) != 0;
                    DecodedInstruction ins = DecodeInstruction(a, b_, c, isFetch);
                    if (ins.unknown) {
                        ++stats.unknownInstructions;
                        clean = false;
                        if (print) {
                            std::printf("  !! unknown instr at +%04zu kind=%d\n",
                                        base + i * 12, int(ins.kind));
                        }
                    }
                }
            }
            if (cf.opcode == ControlFlowOpcode::Return) {
                ++stats.returns;
                return clean;
            }
        }
    }
    return clean;
}

static bool ParseFxc(const uint8_t* data, size_t size, Stats& stats, bool print) {
    size_t i = 0;
    bool allClean = true;
    while (i + sizeof(ContainerHeader) <= size) {
        ContainerHeader h;
        std::memcpy(&h, data + i, sizeof(h));
        // Container is big-endian on disk; assemble fields individually.
        const uint8_t* p = data + i;
        h.flags = ReadBE32(p + 0);
        h.virtualSize = ReadBE32(p + 4);
        h.physicalSize = ReadBE32(p + 8);
        h.fieldC = ReadBE32(p + 12);
        h.constantTableOffset = ReadBE32(p + 16);
        h.definitionTableOffset = ReadBE32(p + 20);
        h.shaderOffset = ReadBE32(p + 24);
        h.field1C = ReadBE32(p + 28);
        h.field20 = ReadBE32(p + 32);

        if ((h.flags & 0xFFFFFF00) == 0x102A1100 &&
            h.field1C == 0 && h.field20 == 0 &&
            size_t(h.virtualSize) + size_t(h.physicalSize) <= size - i) {
            ++stats.containers;
            if (size_t(h.shaderOffset) + sizeof(ShaderHeader) > size_t(h.virtualSize)) {
                ++stats.oobExecs;
                allClean = false;
                continue;
            }
            ShaderHeader sh;
            const uint8_t* sp = data + i + h.shaderOffset;
            sh.physicalOffset = ReadBE32(sp + 0);
            sh.size = ReadBE32(sp + 4);
            sh.fieldC = ReadBE32(sp + 12);

            const size_t codeStart = i + h.virtualSize + sh.physicalOffset;
            if (codeStart + sh.size > size) {
                ++stats.oobExecs;
                allClean = false;
                i += h.virtualSize + h.physicalSize;
                continue;
            }
            ++stats.shaders;
            bool isVs = (h.flags & 0x1) != 0;
            if (print) {
                std::printf("--- container @%zu flags=0x%08X %s vsize=%u psize=%u shader.size=%u ---\n",
                            i, h.flags, isVs ? "VS" : "PS", h.virtualSize,
                            h.physicalSize, sh.size);
            }
            if (DecodeMicrocode(data + codeStart, sh.size, stats, print)) {
                ++stats.cleanShaders;
            } else {
                allClean = false;
            }
            i += h.virtualSize + h.physicalSize;
        } else {
            i += 4;
        }
    }
    return allClean;
}

static std::string FormatInstruction(const DecodedInstruction& ins) {
    std::string out;
    if (ins.kind == InstructionKind::Alu) {
        out += "ALU " + std::string(AluVectorOpcodeName(ins.vectorOpcode));
        out += " / " + std::string(AluScalarOpcodeName(ins.scalarOpcode));
        out += " vdst=r" + std::to_string(ins.vectorDest) + " sdst=r" +
               std::to_string(ins.scalarDest);
        char buf[64];
        std::snprintf(buf, sizeof(buf), " vmask=0x%X smask=0x%X", ins.vectorWriteMask,
                      ins.scalarWriteMask);
        out += buf;
        out += " s1=r" + std::to_string(ins.src1Register) + " s2=r" +
               std::to_string(ins.src2Register) + " s3=r" +
               std::to_string(ins.src3Register);
    } else {
        out += (ins.kind == InstructionKind::VertexFetch ? "VFETCH " : "TFETCH ");
        out += std::string(FetchOpcodeName(ins.fetchOpcode));
        out += " dst=r" + std::to_string(ins.dstRegister) + " src=r" +
               std::to_string(ins.srcRegister) + " const=" +
               std::to_string(ins.constIndex);
        if (ins.kind == InstructionKind::VertexFetch) {
            out += " fmt=" + std::to_string(ins.vertexFormat) + " stride=" +
                   std::to_string(ins.stride) + " off=" + std::to_string(ins.offset);
        } else {
            out += " dim=" + std::to_string(ins.dimension);
        }
    }
    if (ins.isPredicated) out += " pred";
    if (ins.unknown) out += " [UNKNOWN]";
    return out;
}

static void DumpShaderIr(const uint8_t* code, size_t size, FILE* out) {
    const size_t cf_bound = ComputeControlFlowByteBound(code, size);
    size_t n = cf_bound / 12;
    for (size_t b = 0; b < n; ++b) {
        const uint8_t* blk = code + b * 12;
        uint32_t w0 = ReadBE32(blk);
        uint32_t w1 = ReadBE32(blk + 4);
        uint32_t w2 = ReadBE32(blk + 8);
        for (int slot = 0; slot < 2; ++slot) {
            uint32_t cfw0 = slot == 0 ? w0 : ((w1 >> 16) | (w2 << 16));
            uint16_t cfw1 = slot == 0 ? static_cast<uint16_t>(w1 & 0xFFFF)
                                      : static_cast<uint16_t>(w2 >> 16);
            ControlFlowInstruction cf = DecodeControlFlow(cfw0, cfw1);
            std::fprintf(out, "cf[%04zu] %-20s addr=%-4u count=%u seq=0x%03X\n",
                         b * 2 + slot, ControlFlowOpcodeName(cf.opcode),
                         cf.address, cf.count, cf.sequence);
            if (cf.IsExec()) {
                size_t base = size_t(cf.address) * 12;
                if (cf.count > 0 && base + size_t(cf.count) * 12 > size) {
                    std::fprintf(out, "    !! OOB exec target\n");
                    continue;
                }
                for (uint32_t i = 0; i < cf.count; ++i) {
                    const uint8_t* ip = code + base + i * 12;
                    uint32_t a = ReadBE32(ip);
                    uint32_t b_ = ReadBE32(ip + 4);
                    uint32_t c = ReadBE32(ip + 8);
                    bool isFetch = ((cf.sequence >> (2 * i)) & 1) != 0;
                    DecodedInstruction ins = DecodeInstruction(a, b_, c, isFetch);
                    std::fprintf(out, "    +%04zu %s\n", base + i * 12,
                                 FormatInstruction(ins).c_str());
                }
            }
            if (cf.opcode == ControlFlowOpcode::Return) return;
        }
    }
}

static bool ScanDirectory(const fs::path& dir, Stats& total) {
    bool allClean = true;
    size_t count = 0;
    for (const auto& entry : fs::recursive_directory_iterator(dir)) {
        if (!entry.is_regular_file()) continue;
        // Accept .fxc containers AND raw microcode dumps (*.ucode.*) - the
        // Xenia-dump corpus is raw microcode and translates through the same
        // decoder (dual path below mirrors main()'s single-file logic).
        auto ext = entry.path().extension().string();
        const bool isUcode = entry.path().string().find(".ucode.") != std::string::npos;
        if (ext != ".fxc" && !isUcode) continue;
        FILE* f = std::fopen(entry.path().string().c_str(), "rb");
        if (!f) continue;
        std::fseek(f, 0, SEEK_END);
        long sz = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        std::vector<uint8_t> data(sz);
        if (sz > 0 && std::fread(data.data(), 1, sz, f) != size_t(sz)) {
            std::fclose(f);
            continue;
        }
        std::fclose(f);
        Stats stats;
        bool clean;
        bool foundContainer = false;
        for (size_t i = 0; i + sizeof(ContainerHeader) <= data.size(); i += 4) {
            if ((ReadBE32(data.data() + i) & 0xFFFFFF00) == 0x102A1100) { foundContainer = true; break; }
        }
        if (foundContainer) {
            clean = ParseFxc(data.data(), data.size(), stats, false);
        } else {
            clean = DecodeMicrocode(data.data(), data.size(), stats, false);
        }
        total.containers += stats.containers;
        total.shaders += stats.shaders;
        total.cleanShaders += stats.cleanShaders;
        total.unknownInstructions += stats.unknownInstructions;
        total.oobExecs += stats.oobExecs;
        total.returns += stats.returns;
        if (!clean) allClean = false;
        count++;
    }
    std::printf("files=%zu\n", count);
    return allClean;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::printf("Usage: %s <fxc-file-or-microcode-or-dir> [--print]\n", argv[0]);
        return 2;
    }
    const fs::path path = argv[1];
    bool print = argc > 2 && std::strcmp(argv[2], "--print") == 0;
    // --ir <outdir> [path]: dump readable IR for every shader in path into outdir
    bool irMode = false;
    fs::path irOut;
    if (argc >= 4 && std::strcmp(argv[1], "--ir") == 0) {
        irMode = true;
        irOut = argv[2];
        fs::create_directories(irOut);
    }
    if (irMode) {
        const fs::path src = argv[3];
        size_t dumped = 0;
        if (fs::is_directory(src)) {
            for (const auto& entry : fs::recursive_directory_iterator(src)) {
                if (!entry.is_regular_file() || entry.path().extension() != ".fxc") continue;
                FILE* f = std::fopen(entry.path().string().c_str(), "rb");
                if (!f) continue;
                std::fseek(f, 0, SEEK_END);
                long sz = std::ftell(f);
                std::fseek(f, 0, SEEK_SET);
                std::vector<uint8_t> data(sz);
                if (sz > 0 && std::fread(data.data(), 1, sz, f) != size_t(sz)) { std::fclose(f); continue; }
                std::fclose(f);
                size_t i = 0;
                uint32_t shaderIndex = 0;
                while (i + sizeof(ContainerHeader) <= data.size()) {
                    const uint8_t* p = data.data() + i;
                    uint32_t flags = ReadBE32(p + 0), vsize = ReadBE32(p + 4);
                    uint32_t psize = ReadBE32(p + 8), so = ReadBE32(p + 24);
                    if ((flags & 0xFFFFFF00) == 0x102A1100 && vsize + psize <= data.size() - i) {
                        uint32_t po = ReadBE32(p + so + 0);
                        uint32_t shSize = ReadBE32(p + so + 4);
                        size_t cs = i + vsize + po;
                        if (cs + shSize <= data.size()) {
                            char name[512];
                            std::snprintf(name, sizeof(name), "%s__%02u.ir.txt",
                                          entry.path().stem().string().c_str(), shaderIndex);
                            fs::path outp = irOut / name;
                            FILE* o = std::fopen(outp.string().c_str(), "w");
                            if (o) {
                                std::fprintf(o, "# %s %s vsize=%u psize=%u shader.size=%u\n",
                                             entry.path().stem().string().c_str(),
                                             (flags & 0x1) ? "VS" : "PS", vsize, psize, shSize);
                                DumpShaderIr(data.data() + cs, shSize, o);
                                std::fclose(o);
                                dumped++;
                            }
                        }
                        shaderIndex++;
                        i += vsize + psize;
                    } else {
                        i += 4;
                    }
                }
            }
        } else {
            FILE* f = std::fopen(src.string().c_str(), "rb");
            if (f) {
                std::fseek(f, 0, SEEK_END);
                long sz = std::ftell(f);
                std::fseek(f, 0, SEEK_SET);
                std::vector<uint8_t> data(sz);
                if (sz > 0 && std::fread(data.data(), 1, sz, f) == size_t(sz)) {
                    FILE* o = std::fopen((irOut / (src.stem().string() + ".ir.txt")).string().c_str(), "w");
                    if (o) {
                        DumpShaderIr(data.data(), data.size(), o);
                        std::fclose(o);
                        dumped++;
                    }
                }
                std::fclose(f);
            }
        }
        std::printf("IR dumps written: %zu -> %s\n", dumped, irOut.string().c_str());
        return dumped > 0 ? 0 : 2;
    }
    if (fs::is_directory(path)) {
        Stats total;
        bool clean = ScanDirectory(path, total);
        std::printf("dir scan: containers=%llu shaders=%llu clean=%llu unknown_instrs=%llu oob=%llu returns=%llu\n",
                    (unsigned long long)total.containers,
                    (unsigned long long)total.shaders,
                    (unsigned long long)total.cleanShaders,
                    (unsigned long long)total.unknownInstructions,
                    (unsigned long long)total.oobExecs,
                    (unsigned long long)total.returns);
        std::printf(clean ? "RESULT: CLEAN\n" : "RESULT: ISSUES FOUND\n");
        return clean ? 0 : 1;
    }

    std::vector<uint8_t> data;
    {
        FILE* f = std::fopen(path.string().c_str(), "rb");
        if (!f) { std::printf("cannot open %s\n", path.string().c_str()); return 2; }
        std::fseek(f, 0, SEEK_END);
        long sz = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        data.resize(sz);
        if (sz > 0 && std::fread(data.data(), 1, sz, f) != size_t(sz)) {
            std::printf("read error\n");
            std::fclose(f);
            return 2;
        }
        std::fclose(f);
    }

    Stats stats;
    bool clean;
    // .fxc files start with a name string; container headers sit at variable
    // offsets. Scan for the magic like XenosRecomp does; fall back to raw
    // microcode decode only if no container is found.
    bool foundContainer = false;
    for (size_t i = 0; i + sizeof(ContainerHeader) <= data.size(); i += 4) {
        if ((ReadBE32(data.data() + i) & 0xFFFFFF00) == 0x102A1100) {
            foundContainer = true;
            break;
        }
    }
    if (foundContainer) {
        clean = ParseFxc(data.data(), data.size(), stats, print);
        std::printf("containers=%llu shaders=%llu clean=%llu unknown_instrs=%llu oob=%llu returns=%llu\n",
                    (unsigned long long)stats.containers,
                    (unsigned long long)stats.shaders,
                    (unsigned long long)stats.cleanShaders,
                    (unsigned long long)stats.unknownInstructions,
                    (unsigned long long)stats.oobExecs,
                    (unsigned long long)stats.returns);
    } else {
        if (print) PrintMicrocode(data.data(), data.size());
        clean = DecodeMicrocode(data.data(), data.size(), stats, print);
        std::printf("raw microcode: %zu bytes, unknown_instrs=%llu oob=%llu returns=%llu\n",
                    data.size(),
                    (unsigned long long)stats.unknownInstructions,
                    (unsigned long long)stats.oobExecs,
                    (unsigned long long)stats.returns);
    }
    std::printf(clean ? "RESULT: CLEAN\n" : "RESULT: ISSUES FOUND\n");
    return clean ? 0 : 1;
}






