#include "resource_cache.h"

#include "texture_decode.h"

namespace mcla::native {

const char* ResourceKindName(ResourceKind kind) {
    switch (kind) {
        case ResourceKind::Buffer:       return "buffer";
        case ResourceKind::Texture:      return "texture";
        case ResourceKind::RenderTarget: return "render_target";
        case ResourceKind::Upload:       return "upload";
        default:                         return "unknown";
    }
}

// FNV-1a 64-bit hash combiner over the key fields.
uint64_t HashResourceKey(const ResourceKey& key) {
    uint64_t h = 14695981039346656037ULL;
    const uint64_t prime = 1099511628211ULL;
    const uint8_t* p = reinterpret_cast<const uint8_t*>(&key);
    for (size_t i = 0; i < sizeof(ResourceKey); ++i) {
        h ^= uint64_t(p[i]);
        h *= prime;
    }
    return h;
}

std::size_t ResourceKeyHash::operator()(const ResourceKey& k) const noexcept {
    return static_cast<std::size_t>(HashResourceKey(k));
}

ResourceCache::ResourceCache(std::size_t maxEntries) : maxEntries_(maxEntries) {
    map_.reserve(maxEntries_);
    order_.reserve(maxEntries_);
}

ResourceEntry& ResourceCache::Insert(const ResourceKey& key, const ResourceEntry& entry) {
    auto it = map_.find(key);
    if (it != map_.end()) {
        it->second = entry;
        return it->second;
    }
    // Evict oldest if at capacity.
    if (order_.size() >= maxEntries_ && !order_.empty()) {
        const ResourceKey& oldest = order_.front();
        map_.erase(oldest);
        order_.erase(order_.begin());
    }
    auto [it2, inserted] = map_.emplace(key, entry);
    order_.push_back(key);
    return it2->second;
}

bool ResourceCache::Find(const ResourceKey& key, ResourceEntry& entry) const {
    auto it = map_.find(key);
    if (it == map_.end()) return false;
    entry = it->second;
    return true;
}

bool ResourceCache::NeedsUpload(const ResourceKey& key) const {
    auto it = map_.find(key);
    if (it == map_.end()) return true;
    return it->second.uploadedVersion != key.dataVersion;
}

void ResourceCache::Clear() {
    map_.clear();
    order_.clear();
}

TextureLayout ComputeTextureLayout(uint32_t xenosFormat, uint32_t width,
                                   uint32_t height) {
    TextureLayout layout = {};
    const TextureFormatInfo* info = GetTextureFormatInfo(xenosFormat);
    if (!info || info->dxgiFormat == 0 || width == 0 || height == 0) return layout;
    layout.dxgiFormat = info->dxgiFormat;
    uint32_t blocksX = 0, blocksY = 0;
    const uint32_t blocks = GetTextureBlockSpan(xenosFormat, width, height,
                                                &blocksX, &blocksY);
    if (blocks == 0) return layout;
    layout.blocksX = blocksX;
    layout.blocksY = blocksY;
    layout.bytesPerBlock = GetTextureBytesPerBlock(xenosFormat);
    if (layout.bytesPerBlock == 0 || (layout.bytesPerBlock & (layout.bytesPerBlock - 1)) != 0 ||
        layout.bytesPerBlock > 64) {
        return layout;  // non-power-of-two bpb not addressable by tiled math
    }
    layout.bpbLog2 = 31 - uint32_t(__builtin_clz(layout.bytesPerBlock));
    layout.byteSize = uint32_t(uint64_t(blocksX) * blocksY * layout.bytesPerBlock);
    layout.valid = layout.byteSize != 0;
    return layout;
}

} // namespace mcla::native
