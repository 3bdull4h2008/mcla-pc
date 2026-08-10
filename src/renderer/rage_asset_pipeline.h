#pragma once

// Phase 9: RAGE Art Asset Pipeline
// Parses RAGE format files (.dff model, .txd texture dictionary, .stream)
// Files in extracted cache have "CSR" (0x525343) container header

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "vfs_rpf.h"

namespace mcla::rage {

// RW (RenderWare) chunk ids used by .dff/.txd assets.
// Stored little-endian in file; type/size carry optional library/flags bits
// that ReadRwChunk masks off.
enum RwChunkType : uint32_t {
    RW_STRUCT = 0x0001,
    RW_STRING = 0x0002,
    RW_EXTENSION = 0x0003,
    RW_CAMERA = 0x0004,
    RW_TEXTURE = 0x0005,
    RW_MATERIAL = 0x0006,
    RW_MATERIAL_LIST = 0x0007,
    RW_FRAME_LIST = 0x0008,
    RW_GEOMETRY = 0x0009,
    RW_GEOMETRY_LIST = 0x000A,
    RW_ATOMIC = 0x000B,
    RW_TEXTURE_NATIVE = 0x000C,
    RW_TEXTURE_DICTIONARY = 0x000D,
    RW_CLUMP = 0x0010,
};

// 12-byte chunk header: type, payload size, version (all LE on disk).
struct RwChunkHeader {
    uint32_t type;
    uint32_t size;
    uint32_t version;
};

// Assumed RAGE texture pixel formats (needs capture validation).
enum TxFormat : uint32_t {
    TEX_FMT_DXT1 = 0,
    TEX_FMT_DXT3 = 1,
    TEX_FMT_DXT5 = 2,
    TEX_FMT_RGBA8888 = 4,
    TEX_FMT_RGB888 = 5,
    TEX_FMT_RGB565 = 6,
    TEX_FMT_ARGB8888 = 7,
};

// Assumed texture struct layout inside a TXD (needs capture validation).
struct TxdTextureStruct {
    uint32_t name_hash;
    uint16_t width;
    uint16_t height;
    uint8_t mipmaps;
    uint8_t format;
    uint16_t flags;
    uint32_t data_size;
};

// RAGE CSR Container Header
struct CsrHeader {
    uint8_t version;          // 0x05
    char magic[3];            // "CSR" = 0x52 0x53 0x43
    uint32_t size;            // Container size (big-endian)
    uint32_t flags;           // Flags
    uint32_t unk1;            // Unknown
    uint32_t unk2;            // Unknown
    uint32_t num_entries;     // Number of entries
};

// CSR Entry
struct CsrEntry {
    uint32_t hash;            // Resource hash
    uint32_t offset;          // Offset in container
    uint32_t size;            // Entry size
    uint32_t flags;           // Flags
    uint16_t type;            // Resource type
    uint16_t unk;             // Unknown
};

// RAGE Resource Types
enum class ResourceType : uint16_t {
    Unknown = 0,
    TextureDictionary = 1,    // .txd
    Model = 2,                // .dff
    Stream = 3,               // .stream
    Texture = 4,              // Texture
    Geometry = 5,             // Geometry
    Animation = 6,            // Animation
    Collision = 7,            // Collision
    Audio = 8,                // Audio
};

// CSR Container Parser
class CsrContainer {
public:
    bool Parse(const uint8_t* data, size_t size);
    const std::vector<CsrEntry>& GetEntries() const { return m_entries; }
    bool HasEntry(uint32_t hash) const;
    const CsrEntry* GetEntry(uint32_t hash) const;
    const uint8_t* GetEntryData(const CsrEntry& entry) const;
    
private:
    CsrHeader m_header;
    std::vector<CsrEntry> m_entries;
    const uint8_t* m_data = nullptr;
    size_t m_data_size = 0;
};

// Texture Dictionary (.txd) Parser
struct TxdTexture {
    uint32_t hash;
    uint32_t width;
    uint32_t height;
    uint32_t format;
    uint32_t mip_levels;
    std::vector<uint8_t> data;
};

struct TxdDictionary {
    uint32_t hash;
    std::vector<TxdTexture> textures;
};

class TxdParser {
public:
    static bool Parse(const uint8_t* data, size_t size, TxdDictionary& out_dict);
};

// Model (.dff) Parser
struct DffMesh {
    uint32_t hash;
    std::vector<float> positions;
    std::vector<float> normals;
    std::vector<float> texcoords;
    std::vector<uint16_t> indices;
    uint32_t material_hash;
};

struct DffModel {
    uint32_t hash;
    std::vector<DffMesh> meshes;
};

class DffParser {
public:
    static bool Parse(const uint8_t* data, size_t size, DffModel& out_model);
};

// RAGE Asset Manager
class RageAssetManager {
public:
    static RageAssetManager& Instance() {
        static RageAssetManager instance;
        return instance;
    }
    
    // Initialize with VFS
    void SetVfs(mcla::vfs::RpfVirtualFileSystem* vfs) { m_vfs = vfs; }
    
    // Load texture dictionary by hash
    bool LoadTextureDictionary(uint32_t hash);
    
    // Load model by hash
    bool LoadModel(uint32_t hash);
    
    // Get texture data for native renderer
    bool GetTextureData(uint32_t hash, std::vector<uint8_t>& out_data, 
                        uint32_t& out_width, uint32_t& out_height, 
                        uint32_t& out_format);
    
    // Get model geometry for native renderer
    bool GetModelGeometry(uint32_t hash, std::vector<float>& out_positions,
                          std::vector<float>& out_normals, std::vector<float>& out_uvs,
                          std::vector<uint16_t>& out_indices);
    
    // Get or create D3D12 texture resource
    bool GetOrCreateTexture(uint32_t hash);
    
    // Get or create D3D12 model buffer
    bool GetOrCreateModel(uint32_t hash);

private:
    RageAssetManager() = default;
    mcla::vfs::RpfVirtualFileSystem* m_vfs = nullptr;
    
    std::unordered_map<uint32_t, std::vector<uint8_t>> m_parsed_textures;
    std::unordered_map<uint32_t, std::vector<float>> m_model_positions;
    std::unordered_map<uint32_t, std::vector<float>> m_model_normals;
    std::unordered_map<uint32_t, std::vector<float>> m_model_uvs;
    std::unordered_map<uint32_t, std::vector<uint16_t>> m_model_indices;
    
    // Helper to load CSR container from VFS
    bool LoadCsrContainer(uint32_t hash, CsrContainer& out_container);
    
    // Parse CSR entry based on type
    bool ParseCsrEntry(const CsrEntry& entry);
    
    // D3D12 resource creation
    bool CreateTextureResource(uint32_t hash, uint32_t width, uint32_t height, 
                               uint32_t format, const void* data, size_t size);
    bool CreateModelBuffers(uint32_t hash, const std::vector<float>& positions,
                            const std::vector<float>& normals, const std::vector<float>& uvs,
                            const std::vector<uint16_t>& indices);
};

} // namespace mcla::rage