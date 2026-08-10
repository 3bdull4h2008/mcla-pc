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

static uint16_t ReadU16LE(const uint8_t* data) {
    return static_cast<uint16_t>(data[0]) |
           (static_cast<uint16_t>(data[1]) << 8);
}

static float ReadF32LE(const uint8_t* data) {
    uint32_t bits = ReadU32LE(data);
    float f;
    std::memcpy(&f, &bits, sizeof(f));
    return f;
}

// Reads a 12-byte RW chunk header (LE), masking off library/flags bits.
// Advances ptr past the header on success.
static bool ReadRwChunk(const uint8_t*& ptr, const uint8_t* end, RwChunkHeader& out) {
    if (end - ptr < 12) return false;
    out.type = ReadU32LE(ptr) & 0xFFFFu;
    out.size = ReadU32LE(ptr + 4) & 0x00FFFFFFu;
    out.version = ReadU32LE(ptr + 8);
    ptr += 12;
    return true;
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
    
    // Convert hash to path
    char path[16];
    sprintf_s(path, sizeof(path), "0x%08x", hash);
    
    // Try to find in VFS
    if (!m_vfs->Exists(path)) {
        // Try uppercase
        char buf[16];
        sprintf_s(buf, sizeof(buf), "0x%08X", hash);
        if (m_vfs->Exists(buf)) {
            // Use uppercase path
            sprintf_s(path, sizeof(path), "0x%08X", hash);
        } else {
            return false;
        }
    }
    
    uint64_t file_size = m_vfs->GetFileSize(path);
    if (file_size == 0) return false;
    
    mcla::vfs::RpfVirtualFileSystem::OpenFileHandle handle;
    if (!m_vfs->OpenFile(path, handle)) {
        return false;
    }
    
    std::vector<uint8_t> file_data;
    file_data.resize(static_cast<size_t>(file_size));
    
    uint64_t bytes_read = 0;
    if (!m_vfs->ReadFile(handle, file_data.data(), file_size, bytes_read)) {
        m_vfs->CloseFile(handle);
        return false;
    }
    
    if (!m_vfs->CloseFile(handle)) {
        REXLOG_WARN("Failed to close file handle");
    }
    
    // Parse the container
    if (!out_container.Parse(file_data.data(), file_data.size())) {
        return false;
    }
    
    return true;
}

bool RageAssetManager::ParseCsrEntry(const CsrEntry& entry) {
    // TODO: Parse based on entry.type
    // For now, just log
    REXLOG_INFO("RAGE: Parsing entry hash=0x%08X type=%u size=%u", entry.hash, entry.type, entry.size);
    return true;
}

// Parses a single RW geometry into a DffMesh (positions/normals/uvs/indices).
// Uses standard RW3 flags; exact RAGE layout needs capture validation.
static bool ParseGeometry(const uint8_t* ptr, const uint8_t* end, DffMesh& out_mesh) {
    RwChunkHeader struct_hdr;
    if (!ReadRwChunk(ptr, end, struct_hdr) || struct_hdr.type != RW_STRUCT) return false;
    const uint8_t* struct_end = ptr + struct_hdr.size;
    if (struct_end > end) struct_end = end;
    if (struct_end - ptr < 16) return false;

    const uint32_t flags = ReadU32LE(ptr);
    const uint32_t num_triangles = ReadU32LE(ptr + 4);
    const uint32_t num_vertices = ReadU32LE(ptr + 8);
    const uint32_t num_frames = ReadU32LE(ptr + 12);
    ptr += 16;

    const bool has_positions = (flags & 0x02u) != 0;
    const bool has_normals = (flags & 0x10u) != 0;
    const bool has_colors = (flags & 0x08u) != 0;
    const uint32_t num_uv_sets = (flags & 0x80u) ? 2u : ((flags & 0x04u) ? 1u : 0u);

    out_mesh.hash = 0;
    out_mesh.material_hash = 0;

    // Triangles: 3 x u16 index per triangle.
    if (struct_end - ptr < num_triangles * 6) return false;
    out_mesh.indices.reserve(num_triangles * 3);
    for (uint32_t t = 0; t < num_triangles; ++t) {
        out_mesh.indices.push_back(ReadU16LE(ptr));
        out_mesh.indices.push_back(ReadU16LE(ptr + 2));
        out_mesh.indices.push_back(ReadU16LE(ptr + 4));
        ptr += 6;
    }

    // Per-frame vertex groups.
    if (struct_end - ptr < num_frames * 8) return false;
    ptr += num_frames * 8;

    // Vertices.
    if (has_positions) {
        if (struct_end - ptr < num_vertices * 12) return false;
        out_mesh.positions.reserve(num_vertices * 3);
        for (uint32_t v = 0; v < num_vertices; ++v) {
            out_mesh.positions.push_back(ReadF32LE(ptr));
            out_mesh.positions.push_back(ReadF32LE(ptr + 4));
            out_mesh.positions.push_back(ReadF32LE(ptr + 8));
            ptr += 12;
        }
    }
    if (has_normals) {
        if (struct_end - ptr < num_vertices * 12) return false;
        out_mesh.normals.reserve(num_vertices * 3);
        for (uint32_t v = 0; v < num_vertices; ++v) {
            out_mesh.normals.push_back(ReadF32LE(ptr));
            out_mesh.normals.push_back(ReadF32LE(ptr + 4));
            out_mesh.normals.push_back(ReadF32LE(ptr + 8));
            ptr += 12;
        }
    }
    if (num_uv_sets > 0) {
        if (struct_end - ptr < num_uv_sets * num_vertices * 8) return false;
        out_mesh.texcoords.reserve(num_uv_sets * num_vertices * 2);
        for (uint32_t s = 0; s < num_uv_sets; ++s) {
            for (uint32_t v = 0; v < num_vertices; ++v) {
                out_mesh.texcoords.push_back(ReadF32LE(ptr));
                out_mesh.texcoords.push_back(ReadF32LE(ptr + 4));
                ptr += 8;
            }
        }
    }
    if (has_colors) {
        if (struct_end - ptr < num_vertices * 4) return false;
        ptr += num_vertices * 4;
    }

    REXLOG_INFO("DFF: geometry flags=0x%X vtx=%u tri=%u uv_sets=%u",
                flags, num_vertices, num_triangles, num_uv_sets);
    return true;
}

// Walks the GEOMETRY_LIST chunk body.
static bool ParseGeometryList(const uint8_t* ptr, const uint8_t* end, DffModel& out_model) {
    RwChunkHeader struct_hdr;
    if (!ReadRwChunk(ptr, end, struct_hdr) || struct_hdr.type != RW_STRUCT) return false;
    if (end - ptr < 4) return false;
    const uint32_t num_geoms = ReadU32LE(ptr);
    ptr += 4;

    for (uint32_t g = 0; g < num_geoms && ptr < end; ++g) {
        RwChunkHeader geom_hdr;
        if (!ReadRwChunk(ptr, end, geom_hdr) || geom_hdr.type != RW_GEOMETRY) {
            REXLOG_WARN("DFF: Expected geometry chunk %u", g);
            return false;
        }
        const uint8_t* geom_end = ptr + geom_hdr.size;
        if (geom_end > end) geom_end = end;

        DffMesh mesh = {};
        if (!ParseGeometry(ptr, geom_end, mesh)) {
            REXLOG_ERROR("DFF: Geometry %u parse failed", g);
            return false;
        }
        out_model.meshes.push_back(std::move(mesh));
        ptr = geom_end;
    }
    return true;
}

// TxdParser implementation
bool TxdParser::Parse(const uint8_t* data, size_t size, TxdDictionary& out_dict) {
    const uint8_t* ptr = data;
    const uint8_t* end = data + size;

    RwChunkHeader txd_hdr;
    if (!ReadRwChunk(ptr, end, txd_hdr)) {
        REXLOG_ERROR("TXD: Failed to read dictionary chunk header");
        return false;
    }
    if (txd_hdr.type != RW_TEXTURE_DICTIONARY) {
        REXLOG_ERROR("TXD: Not a texture dictionary (type=0x%X)", txd_hdr.type);
        return false;
    }
    const uint8_t* txd_end = ptr + txd_hdr.size;
    if (txd_end > end) txd_end = end;

    RwChunkHeader struct_hdr;
    if (!ReadRwChunk(ptr, txd_end, struct_hdr) || struct_hdr.type != RW_STRUCT) {
        REXLOG_ERROR("TXD: Expected struct chunk");
        return false;
    }
    const uint8_t* struct_end = ptr + struct_hdr.size;
    if (struct_end > txd_end) struct_end = txd_end;
    if (struct_end - ptr < 4) return false;

    const uint32_t tex_count = ReadU16LE(ptr);
    ptr += 4; // u16 count + u16 padding

    REXLOG_INFO("TXD: %u textures", tex_count);
    out_dict.textures.clear();
    out_dict.textures.reserve(tex_count);

    for (uint32_t i = 0; i < tex_count && ptr < txd_end; ++i) {
        RwChunkHeader tex_hdr;
        if (!ReadRwChunk(ptr, txd_end, tex_hdr) || tex_hdr.type != RW_TEXTURE) {
            REXLOG_ERROR("TXD: Expected texture chunk %u", i);
            return false;
        }
        const uint8_t* tex_end = ptr + tex_hdr.size;
        if (tex_end > txd_end) tex_end = txd_end;

        TxdTexture texture = {};
        texture.hash = 0;
        texture.width = 0;
        texture.height = 0;
        texture.format = 0;
        texture.mip_levels = 1;

        // Texture struct (assumed layout; validate against capture).
        RwChunkHeader ts_hdr;
        if (ReadRwChunk(ptr, tex_end, ts_hdr) && ts_hdr.type == RW_STRUCT) {
            const size_t ts_len = std::min<uint32_t>(ts_hdr.size, static_cast<uint32_t>(tex_end - ptr));
            if (ts_len >= 8) {
                TxdTextureStruct s = {};
                s.name_hash = ReadU32LE(ptr);
                s.width = ReadU16LE(ptr + 4);
                s.height = ReadU16LE(ptr + 6);
                s.mipmaps = (ts_len >= 10) ? ptr[8] : 0;
                s.format = (ts_len >= 11) ? ptr[9] : 0;
                texture.hash = s.name_hash;
                texture.width = s.width;
                texture.height = s.height;
                texture.format = s.format;
                if (s.mipmaps) texture.mip_levels = s.mipmaps;
            }
            ptr += ts_len;
        }

        // Walk sub-chunks: name string, then native texture payload.
        while (ptr < tex_end) {
            RwChunkHeader sub;
            const uint8_t* sub_start = ptr;
            if (!ReadRwChunk(ptr, tex_end, sub)) break;
            if (sub.type == RW_TEXTURE_NATIVE) {
                const size_t avail = static_cast<size_t>(tex_end - ptr);
                const size_t nlen = std::min<uint32_t>(sub.size, static_cast<uint32_t>(avail));
                if (nlen > 0) {
                    texture.data.assign(ptr, ptr + nlen);
                    REXLOG_WARN("TXD[%u]: native payload %zu bytes; header layout unvalidated",
                                i, nlen);
                }
                ptr += nlen;
                break;
            }
            ptr = sub_start + 12;
            ptr += std::min<uint32_t>(sub.size, static_cast<uint32_t>(tex_end - ptr));
        }

        out_dict.textures.push_back(std::move(texture));
        REXLOG_INFO("TXD[%u]: %ux%u fmt=%u mips=%u bytes=%zu", i,
                    texture.width, texture.height, texture.format,
                    texture.mip_levels, texture.data.size());
    }
    return true;
}

// DffParser implementation
bool DffParser::Parse(const uint8_t* data, size_t size, DffModel& out_model) {
    const uint8_t* ptr = data;
    const uint8_t* end = data + size;

    RwChunkHeader root;
    if (!ReadRwChunk(ptr, end, root)) {
        REXLOG_ERROR("DFF: Failed to read root chunk");
        return false;
    }
    if (root.type != RW_CLUMP && root.type != RW_ATOMIC) {
        REXLOG_ERROR("DFF: Not a clump/atomic (type=0x%X)", root.type);
        return false;
    }

    out_model.meshes.clear();

    // Walk top-level children looking for GEOMETRY_LIST.
    const uint8_t* cur = data + 12;
    while (cur + 12 <= end) {
        RwChunkHeader hdr;
        const uint8_t* chunk_start = cur;
        if (!ReadRwChunk(cur, end, hdr)) break;
        const uint8_t* chunk_end = cur + hdr.size;
        if (chunk_end > end) chunk_end = end;

        if (hdr.type == RW_GEOMETRY_LIST) {
            if (!ParseGeometryList(cur, chunk_end, out_model)) {
                REXLOG_ERROR("DFF: Geometry list parse failed");
                return false;
            }
        }
        cur = chunk_start + 12 + hdr.size;
    }

    if (out_model.meshes.empty()) {
        REXLOG_WARN("DFF: No geometry found (chunk layout may differ)");
        return false;
    }
    return true;
}
// RageAssetManager implementation

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
                if (DffParser::Parse(data, entry.size, model) && !model.meshes.empty()) {
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