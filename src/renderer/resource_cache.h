#pragma once

// Phase 3 resource cache for the MCLA native renderer.
//
// Keys are deliberately NOT just the guest address. A resource is uniquely
// identified by kind, guest address, byte size, format/layout, and a data
// version. The cache stores an opaque backend handle (uint64_t) per key,
// plus a small amount of metadata the backend can use to decide whether to
// re-upload. It is a container owned by ResourceCache and filled by the D3D12
// backend; this file is D3D12-free and testable headlessly.

#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace mcla::native {

enum class ResourceKind : uint8_t {
    Unknown = 0,
    Buffer,        // vertex/index/uniform buffer
    Texture,       // sampled texture
    RenderTarget,  // color/depth render target
    Upload,        // staging/upload ring buffer
};

const char* ResourceKindName(ResourceKind kind);

// Everything that can change whether a guest resource maps to the same native
// resource. format/layout is an opaque code (texture format or buffer layout).
struct ResourceKey {
    ResourceKind kind = ResourceKind::Unknown;
    uint32_t guestAddress = 0;
    uint32_t byteSize = 0;
    uint32_t formatLayout = 0;   // e.g. DXGI format code, or 0 for plain buffers
    uint64_t dataVersion = 0;    // bumped when guest contents change

    bool operator==(const ResourceKey&) const = default;
};

struct ResourceKeyHash {
    std::size_t operator()(const ResourceKey& k) const noexcept;
};

// Metadata tracked alongside a cached resource so the backend can decide
// whether an upload is needed.
struct ResourceEntry {
    uint64_t handle = 0;        // opaque backend handle (buffer/texture/target)
    uint64_t uploadedVersion = 0; // dataVersion at last upload
    bool isRenderTarget = false;
};

// Bounded in-memory cache keyed by ResourceKey with FIFO eviction, mirroring
// PipelineCache's policy.
class ResourceCache {
public:
    explicit ResourceCache(std::size_t maxEntries = 8192);

    // Insert or replace the handle/version for `key`. Returns the stored entry.
    ResourceEntry& Insert(const ResourceKey& key, const ResourceEntry& entry);
    // Returns true + fills `entry` if present.
    bool Find(const ResourceKey& key, ResourceEntry& entry) const;
    // Convenience: does a cached entry exist whose uploadedVersion != key.dataVersion?
    bool NeedsUpload(const ResourceKey& key) const;

    std::size_t Size() const { return map_.size(); }
    void Clear();

private:
    std::size_t maxEntries_;
    std::vector<ResourceKey> order_;  // insertion order for FIFO eviction
    std::unordered_map<ResourceKey, ResourceEntry, ResourceKeyHash> map_;
};

// Deterministic 64-bit hash of a ResourceKey (for trace/debug reporting).
uint64_t HashResourceKey(const ResourceKey& key);

// ---------------------------------------------------------------------------
// Texture sizing (Phase 4). Reuses texture_decode's oracle-validated format
// table so the backend and the cache share one code path for turning Xenos
// texture parameters into byte sizes and host format info.
// ---------------------------------------------------------------------------

struct TextureLayout {
    uint32_t dxgiFormat = 0;     // host format code (0 = unsupported)
    uint32_t blocksX = 0;        // width in blocks (pitch units)
    uint32_t blocksY = 0;        // height in blocks
    uint32_t bytesPerBlock = 0;  // per the format table
    uint32_t bpbLog2 = 0;        // log2(bytesPerBlock), 0 when invalid
    uint32_t byteSize = 0;       // blocksX * blocksY * bytesPerBlock (1 layer)
    bool valid = false;
};

// Size a 2D/stacked texture from its Xenos format code and texel extents.
// `width`/`height` are texels; pitch is aligned to the format block size.
// `bpbLog2` is only meaningful when bytesPerBlock is a power of two <= 64
// (the range the tiled-offset math supports).
TextureLayout ComputeTextureLayout(uint32_t xenosFormat, uint32_t width,
                                   uint32_t height);

} // namespace mcla::native
