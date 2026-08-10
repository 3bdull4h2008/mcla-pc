#include "rage_asset_pipeline.h"

#include <cstring>
#include <algorithm>
#include <fstream>
#include <sstream>

#include <rex/logging.h>

#include "vfs_rpf.h"

namespace mcla::rage {

// Helper functions
static uint32_t ReadU32BE(const uint8_t* data) {
    return (static_cast<uint32_t>(data[0]) << 24) |
           (static_cast<uint32_t>(data[1]) << 16) |
           (static_cast<uint32_t>(data[2]) << 8) |
           static_cast<uint32_t>(data[3]);
}

static uint16_t ReadU16BE(const uint8_t* data) {
    return (static_cast<uint16_t>(data[0]) << 8) | data[1];
}

static uint32_t ReadU32LE(const uint8_t* data) {
    return static_cast<uint32_t>(data[0]) |
           (static_cast<uint32_t>(data[1]) << 8) |
           (static_cast<uint32_t>(data[2]) << 16) |
           (static_cast<uint32_t>(data[3]) << 24);
}

// CsrContainer implementation
bool CsrContainer::Parse(const uint8_t* data, size_t size) {
    if (size < sizeof(CsrHeader)) {
        REXLOG_ERROR("CSR: Data too small for header");
        return false;
    }
    
    const uint8_t* ptr = data;
    m_header.version = ptr[0];
    m_header.magic[0] = ptr[1];
    m_header.magic[1] = ptr[2];
    m_header.magic[2] = ptr[3];
    m_header.size = ReadU32BE(ptr + 4);
    m_header.flags = ReadU32BE(ptr + 8);
    m_header.unk1 = ReadU32BE(ptr + 12);
    m_header.unk2 = ReadU32BE(ptr + 16);
    m_header.num_entries = ReadU32BE(ptr + 20);
    
    // Verify magic "CSR"
    if (m_header.magic[0] != 'C' || m_header.magic[1] != 'S' || m_header.magic[2] != 'R') {
        REXLOG_ERROR("CSR: Invalid magic: %c%c%c", m_header.magic[0], m_header.magic[1], m_header.magic[2]);
        return false;
    }
    
    if (m_header.version != 5) {
        REXLOG_WARN("CSR: Unexpected version %d", m_header.version);
    }
    
    if (m_header.num_entries == 0) {
        REXLOG_WARN("CSR: No entries in container");
        return true;
    }
    
    // Parse entries
    ptr += sizeof(CsrHeader);
    m_entries.reserve(m_header.num_entries);
    
    for (uint32_t i = 0; i < m_header.num_entries; ++i) {
        if (reinterpret_cast<const uint8_t*>(ptr + sizeof(CsrEntry)) > data + size) {
            REXLOG_ERROR("CSR: Entry %d out of bounds", i);
            return false;
        }
        
        CsrEntry entry;
        entry.hash = ReadU32BE(ptr);
        entry.offset = ReadU32BE(ptr + 4);
        entry.size = ReadU32BE(ptr + 8);
        entry.flags = ReadU32BE(ptr + 12);
        entry.type = ReadU16BE(ptr + 16);
        entry.unk = ReadU16BE(ptr + 18);
        
        m_entries.push_back(entry);
        ptr += sizeof(CsrEntry);
    }
    
    // Verify total size
    if (m_header.size != size) {
        REXLOG_WARN("CSR: Size mismatch: header=%u, actual=%zu", m_header.size, size);
    }
    
    m_data = data;
    m_data_size = size;
    return true;
}

const std::vector<CsrEntry>& CsrContainer::GetEntries() const {
    return m_entries;
}

bool CsrContainer::HasEntry(uint32_t hash) const {
    for (const auto& entry : m_entries) {
        if (entry.hash == hash) return true;
    }
    return false;
}

const CsrEntry* CsrContainer::GetEntry(uint32_t hash) const {
    for (const auto& entry : m_entries) {
        if (entry.hash == hash) return &entry;
    }
    return nullptr;
}

const uint8_t* CsrContainer::GetEntryData(const CsrEntry& entry) const {
    if (!m_data || entry.offset + entry.size > m_data_size) {
        return nullptr;
    }
    return m_data + entry.offset;
}

// CsrContainer methods for loading from VFS
bool RageAssetManager::LoadCsrContainer(uint32_t hash, CsrContainer& out_container) {
    if (!m_vfs) return false;
    
    // Try to find the file in VFS
    std::string hash_str = "0x" + std::to_string(hash);
    // Convert hash to lowercase hex string
    char buf[16];
    snprintf(nullptr, 0, "0x%08x", hash);
    char buf2[16];
    sprintf(buf2, "0x%08x", hash);
    std::string path = buf2;
    
    // Try to find in VFS
    if (!m_vfs->Exists(path)) {
        // Try alternative paths
        char buf3[32];
        sprintf(buf3, "0x%08X", hash);
        if (m_vfs->Exists(buf3)) {
            path = buf3;
        } else {
            return false;
        }
    }
    
    uint64_t size = m_vfs->GetFileSize(path);
    if (size == 0) return false;
    
    std::vector<uint8_t> data(size);
    mcla::vfs::RpfVirtualFileSystem::OpenFileHandle handle;
    if (!m_vfs->OpenFile(path, handle)) {
        return false;
    }
    
    uint64_t bytes_read = 0;
    if (!m_vfs->ReadFile(handle, size, size, bytes_read)) {
        return false;
    }
    
    // Copy data to our buffer
    std::vector<uint8_t> file_data(size);
    m_vfs->ReadFile(handle, file_data.data(), size, bytes_read);
    
    if (!m_vfs->CloseFile(handle)) {
        REXLOG_WARN("Failed to close file handle");
    }
    
    // Parse the container
    if (!out_container.Parse(file_data.data(), file_data.size())) {
        return false;
    }
    
    // Store the data for later access
    // Note: In a real implementation, we'd store the data persistently
    return true;
}

bool RageAssetManager::ParseCsrEntry(const CsrEntry& entry) {
    // TODO: Parse based on entry.type
    // For now, just log
    REXLOG_INFO("RAGE: Parsing entry hash=0x%08X type=%u size=%u", entry.hash, entry.type, entry.size);
    return true;
}

// TxdParser implementation
bool TxdParser::Parse(const uint8_t* data, size_t size, TxdDictionary& out_dict) {
    // TXD format parsing - simplified for now
    // Real implementation would parse TXD chunks
    REXLOG_WARN("TXD parsing not fully implemented");
    return false;
}

// DffParser implementation
bool DffParser::Parse(const uint8_t* data, size_t size, DffModel& out_model) {
    // DFF format parsing - simplified for now
    REXLOG_WARN("DFF parsing not fully implemented");
    return false;
}

// RageAssetManager implementation
RageAssetManager& RageAssetManager::Instance() {
    static RageAssetManager instance;
    return instance;
}

void RageAssetManager::SetVfs(mcla::vfs::RpfVirtualFileSystem* vfs) {
    m_vfs = vfs;
}

bool RageAssetManager::LoadTextureDictionary(uint32_t hash) {
    if (!m_vfs) return false;
    
    CsrContainer container;
    if (!LoadCsrContainer(hash, container)) {
        return false;
    }
    
    // Find texture dictionary entries
    for (const auto& entry : container.GetEntries()) {
        if (entry.type == static_cast<uint16_t>(ResourceType::TextureDictionary)) {
            const uint8_t* data = container.GetEntryData(entry);
            if (data) {
                TxdDictionary dict;
                if (TxdParser::Parse(container.GetEntryData(entry), entry.size, dict)) {
                    // Store parsed textures
                    for (const auto& tex : dict.textures) {
                        // TODO: Create D3D12 texture resource
                    }
                }
            }
        }
    }
    return true;
}

bool RageAssetManager::LoadModel(uint32_t hash) {
    if (!m_vfs) return false;
    
    CsrContainer container;
    if (!LoadCsrContainer(hash, container)) {
        return false;
    }
    
    for (const auto& entry : container.GetEntries()) {
        if (entry.type == static_cast<uint16_t>(ResourceType::Model)) {
            const uint8_t* data = container.GetEntryData(entry);
            if (data) {
                DffModel model;
                if (DffParser::Parse(data, entry.size, model)) {
                    // Store model geometry
                    m_model_positions[hash] = model.meshes[0].positions; // Simplified
                    m_model_normals[hash] = model.meshes[0].normals;
                    m_model_uvs[hash] = model.meshes[0].texcoords;
                    m_model_indices[hash] = model.meshes[0].indices;
                }
            }
        }
    }
    return true;
}

bool RageAssetManager::GetTextureData(uint32_t hash, std::vector<uint8_t>& out_data, 
                                      uint32_t& out_width, uint32_t& out_height, 
                                      uint32_t& out_format) {
    // Placeholder - return dummy data for now
    out_width = 128;
    out_height = 128;
    out_format = 28; // DXGI_FORMAT_R8G8B8A8_UNORM
    out_data.assign(128 * 128 * 4, 0xFF);
    return true;
}

bool RageAssetManager::GetModelGeometry(uint32_t hash, std::vector<float>& out_positions,
                                        std::vector<float>& out_normals, std::vector<float>& out_uvs,
                                        std::vector<uint16_t>& out_indices) {
    auto it_pos = m_model_positions.find(hash);
    if (it_pos == m_model_positions.end()) return false;
    
    out_positions = it_pos->second;
    
    auto it_nrm = m_model_normals.find(hash);
    if (it_nrm != m_model_normals.end()) out_normals = it_nrm->second;
    
    auto it_uv = m_model_uvs.find(hash);
    if (it_uv != m_model_uvs.end()) out_uvs = it_uv->second;
    
    auto it_idx = m_model_indices.find(hash);
    if (it_idx != m_model_indices.end()) out_indices = it_idx->second;
    
    return true;
}

bool RageAssetManager::GetOrCreateTexture(uint32_t hash) {
    // TODO: Create D3D12 texture resource
    return true;
}

bool RageAssetManager::GetOrCreateModel(uint32_t hash) {
    // TODO: Create D3D12 model buffers
    return true;
}

} // namespace mcla::rage