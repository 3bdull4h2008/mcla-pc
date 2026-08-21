#include "frame_trace.h"
#include "logging.h"

#include <chrono>
#include <cstring>
#include <fmt/format.h>

namespace mcla::native {

FrameTraceWriter::FrameTraceWriter() = default;

FrameTraceWriter::~FrameTraceWriter() {
    Close();
}

bool FrameTraceWriter::Open(const std::filesystem::path& tracePath, uint64_t buildHash) {
    Close();

    m_tracePath = tracePath;
    m_file.open(m_tracePath, std::ios::binary | std::ios::trunc);
    if (!m_file.is_open()) {
        MCLA_LOG_ERROR("FrameTraceWriter: Failed to open output trace file: {}", tracePath.string());
        return false;
    }

    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    uint64_t timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now).count();

    m_header.magic = kTraceMagic;
    m_header.version = kTraceVersion;
    m_header.headerSize = sizeof(TraceHeader);
    m_header.packetSize = sizeof(DrawPacket);
    m_header.packetCount = 0;
    m_header.reserved = 0;
    m_header.buildHash = buildHash;
    m_header.startTimestamp = timestamp;

    m_file.write(reinterpret_cast<const char*>(&m_header), sizeof(m_header));
    m_file.flush();

    MCLA_LOG_INFO("FrameTraceWriter: Created trace file {}", tracePath.string());
    return true;
}

bool FrameTraceWriter::WritePacket(const DrawPacket& packet) {
    if (!m_file.is_open()) return false;

    m_file.write(reinterpret_cast<const char*>(&packet), sizeof(DrawPacket));
    m_header.packetCount++;
    return m_file.good();
}

void FrameTraceWriter::Close() {
    if (!m_file.is_open()) return;

    m_file.seekp(0, std::ios::beg);
    m_file.write(reinterpret_cast<const char*>(&m_header), sizeof(m_header));
    m_file.close();

    std::filesystem::path manifestPath = m_tracePath;
    manifestPath.replace_filename("trace_manifest.json");

    std::ofstream manifest(manifestPath);
    if (manifest.is_open()) {
        manifest << fmt::format(
            "{{\n"
            "  \"magic\": \"0x{:08X}\",\n"
            "  \"version\": {},\n"
            "  \"packet_count\": {},\n"
            "  \"packet_size\": {},\n"
            "  \"build_hash\": \"0x{:016X}\",\n"
            "  \"start_timestamp\": {}\n"
            "}}\n",
            m_header.magic, m_header.version, m_header.packetCount,
            m_header.packetSize, m_header.buildHash, m_header.startTimestamp);
        manifest.close();
    }

    MCLA_LOG_INFO("FrameTraceWriter: Closed trace file {}, wrote {} packets",
                m_tracePath.string(), m_header.packetCount);
}

FrameTraceReader::FrameTraceReader() = default;

FrameTraceReader::~FrameTraceReader() {
    Close();
}

bool FrameTraceReader::Open(const std::filesystem::path& tracePath) {
    Close();

    std::ifstream file(tracePath, std::ios::binary);
    if (!file.is_open()) {
        MCLA_LOG_ERROR("FrameTraceReader: Failed to open trace file: {}", tracePath.string());
        return false;
    }

    file.read(reinterpret_cast<char*>(&m_header), sizeof(TraceHeader));
    if (!file.good()) {
        MCLA_LOG_ERROR("FrameTraceReader: Truncated header in {}", tracePath.string());
        return false;
    }

    if (m_header.magic != kTraceMagic) {
        MCLA_LOG_ERROR("FrameTraceReader: Invalid magic 0x{:08X} (expected 0x{:08X})",
                     m_header.magic, kTraceMagic);
        return false;
    }

    if (m_header.version != kTraceVersion) {
        MCLA_LOG_ERROR("FrameTraceReader: Unsupported version {} (expected {})",
                     m_header.version, kTraceVersion);
        return false;
    }

    if (m_header.packetSize != sizeof(DrawPacket)) {
        MCLA_LOG_ERROR("FrameTraceReader: Packet size mismatch {} (expected {})",
                     m_header.packetSize, sizeof(DrawPacket));
        return false;
    }

    m_packets.resize(m_header.packetCount);
    if (m_header.packetCount > 0) {
        file.read(reinterpret_cast<char*>(m_packets.data()), m_header.packetCount * sizeof(DrawPacket));
        if (!file.good()) {
            MCLA_LOG_ERROR("FrameTraceReader: Truncated packets stream in {}", tracePath.string());
            return false;
        }
    }

    m_isOpen = true;
    MCLA_LOG_INFO("FrameTraceReader: Successfully loaded trace {} ({} packets)",
                tracePath.string(), m_packets.size());
    return true;
}

void FrameTraceReader::Close() {
    m_isOpen = false;
    m_header = {};
    m_packets.clear();
}

bool VerifyTraceFileForTests() {
    std::filesystem::path testPath = std::filesystem::temp_directory_path() / "mcla_phase1_test.mclatrace";

    {
        FrameTraceWriter writer;
        if (!writer.Open(testPath, 0x123456789ABCDEF0ULL)) {
            MCLA_LOG_ERROR("VerifyTraceFileForTests: Writer open failed");
            return false;
        }

        DrawPacket p1{};
        p1.frameIndex = 1;
        p1.drawInFrame = 0;
        p1.primType = 0;
        p1.indexCount = 36;
        p1.stateHash = 0xDEADBEEFCAFEBABEULL;
        p1.isValid = 1;

        DrawPacket p2{};
        p2.frameIndex = 1;
        p2.drawInFrame = 1;
        p2.primType = 1;
        p2.indexCount = 120;
        p2.stateHash = 0x1122334455667788ULL;
        p2.isValid = 1;

        writer.WritePacket(p1);
        writer.WritePacket(p2);
        writer.Close();
    }

    {
        FrameTraceReader reader;
        if (!reader.Open(testPath)) {
            MCLA_LOG_ERROR("VerifyTraceFileForTests: Reader open failed");
            return false;
        }

        if (reader.GetHeader().packetCount != 2) {
            MCLA_LOG_ERROR("VerifyTraceFileForTests: Expected 2 packets, got {}", reader.GetHeader().packetCount);
            return false;
        }

        const auto& packets = reader.GetPackets();
        if (packets[0].indexCount != 36 || packets[1].indexCount != 120) {
            MCLA_LOG_ERROR("VerifyTraceFileForTests: Packet content mismatch");
            return false;
        }
        if (packets[0].stateHash != 0xDEADBEEFCAFEBABEULL) {
            MCLA_LOG_ERROR("VerifyTraceFileForTests: State hash mismatch");
            return false;
        }
    }

    std::error_code ec;
    std::filesystem::remove(testPath, ec);
    std::filesystem::remove(testPath.parent_path() / "trace_manifest.json", ec);

    MCLA_LOG_INFO("VerifyTraceFileForTests: Phase 1 trace validation PASSED");
    return true;
}

} // namespace mcla::native