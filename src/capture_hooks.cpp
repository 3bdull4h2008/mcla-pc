#include "capture_hooks.h"
#include "renderer_mode.h"

#include <chrono>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <rex/logging.h>
#include <rex/ppc/context.h>

namespace mcla::native {

namespace {
static DrawPacketAccumulator g_accumulator;

// FNV-1a 64-bit hash helper
uint64_t Fnv1a64(const void* data, size_t size, uint64_t hash = 14695981039346656037ULL) {
    const uint8_t* bytes = static_cast<const uint8_t*>(data);
    for (size_t i = 0; i < size; ++i) {
        hash ^= bytes[i];
        hash *= 1099511628211ULL;
    }
    return hash;
}
} // namespace

DrawPacketAccumulator* GetDrawAccumulator() {
    return &g_accumulator;
}

DrawPacketAccumulator::DrawPacketAccumulator() = default;
DrawPacketAccumulator::~DrawPacketAccumulator() = default;

void DrawPacketAccumulator::Initialize(rex::memory::Memory* memory) {
    m_memoryView.SetMemory(memory);
}

void DrawPacketAccumulator::SetCaptureEnabled(bool enabled, const std::filesystem::path& tracePath) {
    m_captureEnabled = enabled;
    if (m_captureEnabled && !tracePath.empty()) {
        m_writer.Open(tracePath);
        m_shaderDumpDir = tracePath.parent_path() / "shaders";
        m_memDumpDir = tracePath.parent_path() / "guestmem";
        m_dumpedRanges.clear();
    } else {
        m_writer.Close();
        m_shaderDumpDir.clear();
        m_memDumpDir.clear();
    }
}

void DrawPacketAccumulator::OnStateSetup(::MclaGpuContext* gpuCtx, uint32_t srcStateAddr) {
    if (!gpuCtx) return;

    if (!srcStateAddr || !m_memoryView.IsValidRange(srcStateAddr, 128)) {
        m_lastCaptureFailed = true;
        return;
    }

    // Capture the 5 surface info source descriptors from the setup struct.
    bool ok = true;
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 108, &m_currentPacket.colorTargets[0]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 112, &m_currentPacket.colorTargets[1]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 116, &m_currentPacket.colorTargets[2]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 120, &m_currentPacket.colorTargets[3]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 124, &m_currentPacket.depthTarget);
    if (!ok) m_lastCaptureFailed = true;
}

void DrawPacketAccumulator::OnDrawBuild(::MclaGpuContext* gpuCtx, ::PPCContext& ctx) {
    if (!gpuCtx) return;

    uint32_t drawFlags = ctx.r4.u32;
    uint32_t primType = drawFlags & 7;

    m_currentPacket.primType = primType;
    m_currentPacket.drawFlags = drawFlags;
    m_currentPacket.startIndex = 0;
    m_currentPacket.indexCount = gpuCtx->drawVertexCount;
    m_currentPacket.baseVertex = 0;

    // Index type is encoded in drawFlags bits 4-6. sub_82420BA8
    // (generated/default/mcla_recomp.26.cpp:20301-20345) sets these from a
    // struct u16&3 indexed by primitive type: 0 -> flags|0x10, 1 -> flags|0x50,
    // else -> flags|0x70. Map to the DrawPacket contract (0=16-bit, 1=32-bit,
    // 2=non-indexed). Unknown encodings are NOT defaulted: the packet is
    // marked invalid so nothing is consumed from unproven index semantics.
    const uint32_t indexField = (drawFlags >> 4) & 0x7;
    switch (indexField) {
        case 0x1: m_currentPacket.indexType = 0; break;  // 16-bit indexed
        case 0x5: m_currentPacket.indexType = 1; break;  // 32-bit indexed
        case 0x7: m_currentPacket.indexType = 2; break;  // non-indexed
        default:
            m_currentPacket.indexType = 0;
            m_lastCaptureFailed = true;
            break;
    }

    // Rasterizer state
    m_currentPacket.paClipCntl = gpuCtx->paClipCntl;
    m_currentPacket.paSuScModeCntl = gpuCtx->paSuScModeCntl;
    m_currentPacket.paClVteCntl = gpuCtx->paClVteCntl;

    // Shader program guest addresses
    m_currentPacket.sqVsProgram = gpuCtx->sqVsProgram;
    m_currentPacket.sqVsConst = gpuCtx->sqVsConst;
    m_currentPacket.sqPsProgram = gpuCtx->sqPsProgram;
    m_currentPacket.sqPsConst = gpuCtx->sqPsConst;

    // Viewport / Scissor mirrors
    m_currentPacket.viewportTL = gpuCtx->rbSurfaceInfoP2;
    m_currentPacket.viewportBR = gpuCtx->rbSurfaceInfoP3;
    m_currentPacket.scissorTL = gpuCtx->rbSurfaceInfoP4;
    m_currentPacket.scissorBR = gpuCtx->rbSurfaceInfoP4;

    // Capture vertex buffer descriptor from r7 parameter if available.
    // Never invent a stream when the descriptor is absent or unreadable.
    uint32_t vbPtr = ctx.r7.u32;
    m_currentPacket.vertexStreamCount = 0;
    if (vbPtr) {
        if (m_memoryView.IsValidRange(vbPtr, 16)) {
            uint32_t streamAddr = 0;
            uint32_t stride = 0;
            if (m_memoryView.ReadU32BE(vbPtr, &streamAddr) &&
                m_memoryView.ReadU32BE(vbPtr + 4, &stride)) {
                m_currentPacket.vertexStreams[0].guestAddress = streamAddr;
                m_currentPacket.vertexStreams[0].stride = stride;
                m_currentPacket.vertexStreams[0].offset = 0;
                m_currentPacket.vertexStreams[0].format = 0;
                m_currentPacket.vertexStreamCount = 1;
            } else {
                m_lastCaptureFailed = true;
            }
        } else {
            m_lastCaptureFailed = true;
        }
    }
}

void DrawPacketAccumulator::OnSubmit(::MclaGpuContext* gpuCtx, uint32_t) {
    if (!gpuCtx) return;

    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    uint64_t timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now).count();

    DrawPacket packet = m_currentPacket;
    packet.frameIndex = m_frameIndex;
    packet.sequenceNum = m_sequenceNum++;
    packet.drawInFrame = m_drawInFrame++;
    packet.cpuTimestamp = timestamp;

    packet.stateHash = ComputeStateHash(packet);
    packet.isValid = ValidatePacket(packet) ? 1 : 0;

    // A failed guest read during capture invalidates the packet and its data
    // must not be trusted by a replay tool.
    if (m_lastCaptureFailed) {
        packet.isValid = 0;
        packet.validationFlags |= (1u << 18);
    }
    m_lastCaptureFailed = false;

    m_totalCapturedDraws++;
    if (packet.isValid) {
        m_validPackets++;
        // Keep the most recent valid packet for the native-renderer
        // consumption path. It is cleared at OnFrameEnd so it never carries
        // into the next frame.
        m_lastPacket = packet;
        m_lastPacketValid = true;
    } else {
        m_invalidPackets++;
        m_lastPacketValid = false;
    }

    if (m_captureEnabled) {
        if (!m_shaderDumpDir.empty()) {
            std::error_code ec;
            std::filesystem::create_directories(m_shaderDumpDir, ec);
            if (packet.sqVsProgram) DumpShaderIfNew(packet.sqVsProgram, true, m_shaderDumpDir);
            if (packet.sqPsProgram) DumpShaderIfNew(packet.sqPsProgram, false, m_shaderDumpDir);
        }
        if (!m_memDumpDir.empty()) {
            std::error_code ec;
            std::filesystem::create_directories(m_memDumpDir, ec);
            DumpPacketGuestMemory(packet, m_memDumpDir);
        }
        if (m_writer.IsOpen()) {
            m_writer.WritePacket(packet);
        } else {
            m_droppedPackets++;
        }
    }
}

void DrawPacketAccumulator::OnFrameEnd() {
    m_frameIndex++;
    m_drawInFrame = 0;
    m_lastPacketValid = false;
    m_lastPacket = {};
}

void DrawPacketAccumulator::DumpShaderIfNew(uint32_t guestAddr, bool isVertex,
                                            const std::filesystem::path& dir) {
    auto& seen = isVertex ? m_dumpedVs : m_dumpedPs;
    if (guestAddr == 0 || seen.count(guestAddr) != 0) return;
    seen.insert(guestAddr);

    // Dump a bounded, page-aligned prefix of the program microcode. Xenos
    // shaders are typically a few KB; 32KB covers all observed sizes.
    constexpr uint32_t kMaxBytes = 0x8000;
    constexpr uint32_t kChunk = 0x1000;

    char name[64];
    std::snprintf(name, sizeof(name), "%s_%08X.bin", isVertex ? "vs" : "ps", guestAddr);
    std::filesystem::path outPath = dir / name;

    std::ofstream out(outPath, std::ios::binary);
    if (!out.is_open()) return;

    std::vector<uint8_t> chunk(kChunk);
    uint32_t written = 0;
    while (written < kMaxBytes) {
        const uint32_t want = std::min(kChunk, kMaxBytes - written);
        if (!m_memoryView.IsValidRange(guestAddr + written, want)) break;
        if (!m_memoryView.ReadBytes(guestAddr + written, chunk.data(), want)) break;
        out.write(reinterpret_cast<const char*>(chunk.data()), want);
        written += want;
    }
    out.close();

    REXLOG_INFO("ShaderDump: {} ({}) -> {} ({} bytes)", name,
                isVertex ? "VS" : "PS", outPath.string(), written);
}

void DrawPacketAccumulator::DumpPacketGuestMemory(const DrawPacket& packet,
                                                  const std::filesystem::path& dir) {
    // Phase 3 evidence capture: write raw guest bytes referenced by the draw
    // so the vertex/index layout can be proven from live data instead of
    // guessed offsets. Each unique (address, size) range is written once.
    auto dumpRange = [&](uint32_t guestAddr, uint32_t size, const char* tag) {
        if (!guestAddr || size == 0) return;
        GuestDumpKey key{ guestAddr, size };
        if (!m_dumpedRanges.insert(key).second) return;

        if (!m_memoryView.IsValidRange(guestAddr, size)) {
            REXLOG_WARN("GuestMemDump: range invalid addr=0x{:08X} size={}", guestAddr, size);
            return;
        }

        char name[96];
        std::snprintf(name, sizeof(name), "%s_%08X_%06X.bin", tag, guestAddr, size);
        std::ofstream out(dir / name, std::ios::binary);
        if (!out.is_open()) return;

        std::vector<uint8_t> chunk(0x1000);
        uint32_t written = 0;
        while (written < size) {
            const uint32_t want = std::min<uint32_t>(0x1000, size - written);
            if (!m_memoryView.ReadBytes(guestAddr + written, chunk.data(), want)) break;
            out.write(reinterpret_cast<const char*>(chunk.data()), want);
            written += want;
        }
        out.close();
        REXLOG_INFO("GuestMemDump: {} addr=0x{:08X} size={} -> {} ({} bytes)",
                    tag, guestAddr, size, (dir / name).string(), written);
    };

    for (uint32_t i = 0; i < packet.vertexStreamCount; ++i) {
        const auto& s = packet.vertexStreams[i];
        // Capture a bounded prefix; a full indexCount*stride range could be
        // huge for instanced/streamed geometry, but a few pages is enough to
        // identify the real vertex layout offline.
        const uint32_t stride = s.stride ? s.stride : 32;
        const uint32_t maxBytes = stride * (packet.indexCount > 0 ? packet.indexCount : 1);
        const uint32_t dumpBytes = std::min(maxBytes, 0x10000u);
        dumpRange(s.guestAddress, dumpBytes, "vb");
    }
    if (packet.indexBufferAddress && packet.indexBufferSize) {
        dumpRange(packet.indexBufferAddress, packet.indexBufferSize, "ib");
    }
}

uint64_t DrawPacketAccumulator::ComputeStateHash(const DrawPacket& packet) const {
    uint64_t hash = 14695981039346656037ULL;
    hash = Fnv1a64(&packet.primType, sizeof(packet.primType), hash);
    hash = Fnv1a64(&packet.indexCount, sizeof(packet.indexCount), hash);
    hash = Fnv1a64(packet.colorTargets, sizeof(packet.colorTargets), hash);
    hash = Fnv1a64(&packet.depthTarget, sizeof(packet.depthTarget), hash);
    hash = Fnv1a64(&packet.sqVsProgram, sizeof(packet.sqVsProgram), hash);
    hash = Fnv1a64(&packet.sqPsProgram, sizeof(packet.sqPsProgram), hash);
    return hash;
}

bool DrawPacketAccumulator::ValidatePacket(DrawPacket& packet) const {
    uint32_t flags = 0;
    bool valid = true;

    // Validate shader program addresses if non-zero
    if (packet.sqVsProgram && !m_memoryView.IsValidRange(packet.sqVsProgram, 4)) {
        flags |= (1 << 0);
        valid = false;
    }
    if (packet.sqPsProgram && !m_memoryView.IsValidRange(packet.sqPsProgram, 4)) {
        flags |= (1 << 1);
        valid = false;
    }

    // Validate vertex stream pointers
    for (uint32_t i = 0; i < packet.vertexStreamCount; ++i) {
        if (packet.vertexStreams[i].guestAddress &&
            !m_memoryView.IsValidRange(packet.vertexStreams[i].guestAddress, 4)) {
            flags |= (1 << (2 + i));
            valid = false;
        }
    }

    packet.validationFlags = flags;
    return valid;
}

} // namespace mcla::native
