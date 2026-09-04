#include "capture_hooks.h"
#include "renderer_mode.h"
#include "logging.h"

#include <chrono>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <filesystem>

namespace mcla::native {

namespace {
static DrawPacketAccumulator g_accumulator;

uint64_t Fnv1a64(const void* data, size_t size, uint64_t hash = 14695981039346656037ULL) {
    const uint8_t* bytes = static_cast<const uint8_t*>(data);
    for (size_t i = 0; i < size; ++i) {
        hash ^= bytes[i];
        hash *= 1099511628211ULL;
    }
    return hash;
}

uint32_t AssembleBE32(const uint8_t* bytes) {
    return (static_cast<uint32_t>(bytes[0]) << 24) |
           (static_cast<uint32_t>(bytes[1]) << 16) |
           (static_cast<uint32_t>(bytes[2]) << 8) |
           static_cast<uint32_t>(bytes[3]);
}

} // namespace

DrawPacketAccumulator* GetDrawAccumulator() {
    return &g_accumulator;
}

DrawPacketAccumulator::DrawPacketAccumulator() = default;
DrawPacketAccumulator::~DrawPacketAccumulator() = default;

void DrawPacketAccumulator::Initialize(uint8_t* base, uint32_t size) {
    m_memoryView.SetMemoryBase(base, size);
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

    const uint32_t indexField = (drawFlags >> 4) & 0x7;
    switch (indexField) {
        case 0x1: m_currentPacket.indexType = 0; break;
        case 0x5: m_currentPacket.indexType = 1; break;
        case 0x7: m_currentPacket.indexType = 2; break;
        default:
            m_currentPacket.indexType = 0;
            m_lastCaptureFailed = true;
            break;
    }

    m_currentPacket.paClipCntl = gpuCtx->paClipCntl;
    m_currentPacket.paSuScModeCntl = gpuCtx->paSuScModeCntl;
    m_currentPacket.paClVteCntl = gpuCtx->paClVteCntl;

    m_currentPacket.sqVsProgram = gpuCtx->sqVsProgram;
    m_currentPacket.sqVsConst = gpuCtx->sqVsConst;
    m_currentPacket.sqPsProgram = gpuCtx->sqPsProgram;
    m_currentPacket.sqPsConst = gpuCtx->sqPsConst;

    m_currentPacket.viewportTL = gpuCtx->rbSurfaceInfoP2;
    m_currentPacket.viewportBR = gpuCtx->rbSurfaceInfoP3;
    m_currentPacket.scissorTL = gpuCtx->rbSurfaceInfoP4;
    m_currentPacket.scissorBR = gpuCtx->rbSurfaceInfoP4;

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

    constexpr uint32_t kDrawableOffset = 10896;
    uint32_t drawablePtr = 0;
    if (m_memoryView.IsValidRange(reinterpret_cast<uintptr_t>(gpuCtx) + kDrawableOffset, 4)) {
        m_memoryView.ReadU32BE(reinterpret_cast<uintptr_t>(gpuCtx) + kDrawableOffset, &drawablePtr);
    }

    constexpr uint32_t kDrawableShaderGroupOff[] = { 0x28, 0x30, 0x38, 0x20 };
    constexpr uint32_t kShaderGroupVDeclOff[]  = { 0x10, 0x18, 0x20, 0x08 };
    constexpr uint32_t kVDeclFvfOff[]          = { 0x10, 0x20, 0x30, 0x08, 0x40 };

    uint32_t fvfMask = 0;
    uint8_t fvfSize = 0, flags = 0, dynamicOrder = 0, channelCount = 0;
    uint64_t types = 0;
    bool gotFvf = false;

    for (uint32_t dsg : kDrawableShaderGroupOff) {
        if (!drawablePtr) break;
        uint32_t shaderGroupPtr = 0;
        if (!m_memoryView.IsValidRange(drawablePtr + dsg, 4)) continue;
        if (!m_memoryView.ReadU32BE(drawablePtr + dsg, &shaderGroupPtr) || !shaderGroupPtr) continue;

        for (uint32_t sgv : kShaderGroupVDeclOff) {
            if (!shaderGroupPtr) break;
            uint32_t vdeclPtr = 0;
            if (!m_memoryView.IsValidRange(shaderGroupPtr + sgv, 4)) continue;
            if (!m_memoryView.ReadU32BE(shaderGroupPtr + sgv, &vdeclPtr) || !vdeclPtr) continue;

            for (uint32_t vfo : kVDeclFvfOff) {
                if (!vdeclPtr) break;
                if (!m_memoryView.IsValidRange(vdeclPtr + vfo, 16)) continue;
                uint32_t mask = 0;
                uint8_t size = 0, fl = 0, dyn = 0, chcnt = 0;
                uint64_t ty = 0;
                if (m_memoryView.ReadU32BE(vdeclPtr + vfo + 0, &mask) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 4, &size) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 5, &fl) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 6, &dyn) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 7, &chcnt) &&
                    m_memoryView.ReadU64BE(vdeclPtr + vfo + 8, &ty)) {
                    if (mask != 0 && size != 0 && ty != 0) {
                        fvfMask = mask;
                        fvfSize = size;
                        flags = fl;
                        dynamicOrder = dyn;
                        channelCount = chcnt;
                        types = ty;
                        gotFvf = true;
                        break;
                    }
                }
            }
            if (gotFvf) break;
        }
        if (gotFvf) break;
    }

    if (gotFvf) {
        m_currentPacket.grcFvf.fvfMask = fvfMask;
        m_currentPacket.grcFvf.fvfSize = fvfSize;
        m_currentPacket.grcFvf.flags = flags;
        m_currentPacket.grcFvf.dynamicOrder = dynamicOrder;
        m_currentPacket.grcFvf.channelCount = channelCount;
        m_currentPacket.grcFvf.types = types;
        m_currentPacket.hasGrcFvf = 1;
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

    if (m_lastCaptureFailed) {
        packet.isValid = 0;
        packet.validationFlags |= (1u << 18);
    }
    m_lastCaptureFailed = false;

    m_totalCapturedDraws++;
    if (packet.isValid) {
        m_validPackets++;
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

    MCLA_LOG_INFO("ShaderDump: {} ({}) -> {} ({} bytes)", name,
                isVertex ? "VS" : "PS", outPath.string(), written);
}

void DrawPacketAccumulator::DumpPacketGuestMemory(const DrawPacket& packet,
                                                  const std::filesystem::path& dir) {
    auto dumpRange = [&](uint32_t guestAddr, uint32_t size, const char* tag) {
        if (!guestAddr || size == 0) return;
        GuestDumpKey key{ guestAddr, size };
        if (!m_dumpedRanges.insert(key).second) return;

        if (!m_memoryView.IsValidRange(guestAddr, size)) {
            MCLA_LOG_WARN("GuestMemDump: range invalid addr=0x{:08X} size={}", guestAddr, size);
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
        MCLA_LOG_INFO("GuestMemDump: {} addr=0x{:08X} size={} -> {} ({} bytes)",
                    tag, guestAddr, size, (dir / name).string(), written);
    };

    for (uint32_t i = 0; i < packet.vertexStreamCount; ++i) {
        const auto& s = packet.vertexStreams[i];
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

    if (packet.sqVsProgram && !m_memoryView.IsValidRange(packet.sqVsProgram, 4)) {
        flags |= (1 << 0);
        valid = false;
    }
    if (packet.sqPsProgram && !m_memoryView.IsValidRange(packet.sqPsProgram, 4)) {
        flags |= (1 << 1);
        valid = false;
    }

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

// ---------------------------------------------------------------------------
// P4'/P5' device-method capture hook: intercepts a simple FP-table render-state
// setter (sub_82413950, FP-table slot 14, device+0x78) and enqueues a
// SetRenderState command to the render thread queue (log-only, no D3D12).
// Signature: func(r3=device, r4=renderStateValue)
// ---------------------------------------------------------------------------

#include "render_queue.h"
#include "kernel/memory.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include <cpu/ppc_context.h>

PPC_FUNC_IMPL(__imp__sub_82413950);
static std::atomic<uint32_t> s_hSetRS{0};

PPC_FUNC(sub_82413950)
{
    const uint32_t n = s_hSetRS.fetch_add(1) + 1;
    const uint32_t dev = ctx.r3.u32;
    const uint32_t value = ctx.r4.u32;

    if (n <= 20 || (n % 2000) == 0)
        MCLA_LOG_INFO("CAPTURE-SET_RS sub_82413950 #{} dev={:08X} value={:08X}", n, dev, value);

    mcla::native::RenderCommand cmd;
    cmd.type = mcla::native::RenderCommand::SET_RENDER_STATE;
    cmd.data = mcla::native::SetRenderStateCommand{ dev, value };
    mcla::native::g_commandQueue.push(cmd);

    __imp__sub_82413950(ctx, base);
}
