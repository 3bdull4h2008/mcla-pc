#pragma once

#include "native_types.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace mcla::native {

class FrameTraceWriter {
public:
    FrameTraceWriter();
    ~FrameTraceWriter();

    bool Open(const std::filesystem::path& tracePath, uint64_t buildHash = 0);
    void Close();
    bool IsOpen() const { return m_file.is_open(); }

    bool WritePacket(const DrawPacket& packet);

    uint32_t GetPacketCount() const { return m_header.packetCount; }
    const std::filesystem::path& GetPath() const { return m_tracePath; }

private:
    std::filesystem::path m_tracePath;
    std::ofstream m_file;
    TraceHeader m_header{};
};

class FrameTraceReader {
public:
    FrameTraceReader();
    ~FrameTraceReader();

    bool Open(const std::filesystem::path& tracePath);
    void Close();
    bool IsOpen() const { return m_isOpen; }

    const TraceHeader& GetHeader() const { return m_header; }
    const std::vector<DrawPacket>& GetPackets() const { return m_packets; }

private:
    bool m_isOpen = false;
    TraceHeader m_header{};
    std::vector<DrawPacket> m_packets;
};

// Unit test / self-test for trace serialization and validation.
bool VerifyTraceFileForTests();

} // namespace mcla::native
