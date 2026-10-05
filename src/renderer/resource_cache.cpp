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

// FNV-1a 64-bit over sizeof(ResourceKey) raw bytes: all fields + 3 padding bytes.
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

// ---------------------------------------------------------------------------
// Content hash + LRU texture cache
// ---------------------------------------------------------------------------

uint64_t HashTextureContent(const uint8_t* data, size_t size) {
    uint64_t h = 14695981039346656037ull;
    const uint64_t prime = 1099511628211ull;
    if (!data) return h;  // a null payload hashes to the FNV offset basis
    for (size_t i = 0; i < size; ++i) {
        h ^= uint64_t(data[i]);
        h *= prime;
    }
    // Fold the length in so a payload and its own prefix cannot collide.
    h ^= uint64_t(size);
    h *= prime;
    return h;
}

uint64_t HashTextureCacheKey(const TextureCacheKey& key) {
    uint64_t h = 14695981039346656037ull;
    const uint64_t prime = 1099511628211ull;
    // Explicit field list, NOT a raw-byte hash: TextureCacheKey has padding and
    // the padding would be uninitialised-by-accident. ResourceCache's
    // HashResourceKey does hash raw bytes (resource_cache.cpp:18-27) which is
    // only safe there because that struct's initialisers zero the padding.
    auto mix = [&h](uint64_t v) {
        for (int i = 0; i < 8; ++i) {
            h ^= (v >> (i * 8)) & 0xFFull;
            h *= prime;
        }
    };
    mix(key.contentHash);
    mix(key.guestAddress);
    mix(key.payloadBytes);
    mix(key.xenosFormat);
    mix(key.importDxgiFormat);
    mix(key.width);
    mix(key.height);
    mix(key.depthOrArraySize);
    mix(key.mipCount);
    mix(key.hostFlags);
    mix(key.dataVersion);
    return h;
}

std::size_t TextureCacheKeyHash::operator()(const TextureCacheKey& k) const noexcept {
    return static_cast<std::size_t>(HashTextureCacheKey(k));
}

TextureCache::TextureCache(std::size_t maxEntries, uint64_t softBytes, uint64_t hardBytes)
    : maxEntries_(maxEntries ? maxEntries : 1),
      softBytes_(softBytes),
      hardBytes_(hardBytes < softBytes ? softBytes : hardBytes) {
    map_.reserve(maxEntries_);
    stats_.entries = 0;
    stats_.residentBytes = 0;
}

// Move `it` to the most-recently-used end. O(1): lru_.splice keeps the node.
void TextureCache::Touch(typename TextureCache::List::iterator it) {
    it->entry.lastUseSerial = ++useSerial_;
    lru_.splice(lru_.begin(), lru_, it);
}

bool TextureCache::Find(const TextureCacheKey& key, TextureCacheEntry& out,
                        std::vector<TextureCacheKey>* evict) {
    stats_.lookups++;
    auto it = map_.find(key);
    if (it != map_.end()) {
        stats_.hits++;
        out = it->second->entry;
        Touch(it->second);
        return true;
    }
    stats_.misses++;
    out = TextureCacheEntry{};
    if (evict) evict->clear();
    // Would this key alone bust the hard budget? Then refuse the upload rather
    // than flush the whole cache for something that still will not fit. The
    // caller sees residency == Absent and gives up; nothing is evicted.
    const uint64_t incoming = key.payloadBytes ? key.payloadBytes : 1ull;
    if (residentBytes_ + incoming > hardBytes_) {
        stats_.budgetRejects++;
    }
    return false;
}

std::vector<TextureCacheKey> TextureCache::Insert(const TextureCacheKey& key,
                                                  const TextureCacheEntry& entry) {
    std::vector<TextureCacheKey> stillToRelease;
    auto it = map_.find(key);
    if (it != map_.end()) {
        residentBytes_ -= it->second->entry.residentBytes;
        it->second->entry = entry;
        residentBytes_ += entry.residentBytes;
        Touch(it->second);
    } else {
        lru_.push_front(Node{key, entry});
        auto ins = lru_.begin();
        ins->entry.lastUseSerial = ++useSerial_;
        map_.emplace(key, ins);
        residentBytes_ += entry.residentBytes;
    }
    stats_.uploads++;
    // Evict from the back until both caps hold. Pinned and in-flight entries
    // are counted as skips and left alone: releasing one would pull a live
    // resource out from under a recorded command list.
    // Evict from the tail until both caps hold. Pinned and in-flight entries are
    // SKIPPED, not a stopping condition: the entry cap is a hard count, and
    // stopping at the first live tail would let the cache grow past its own
    // bound every time a live entry happened to be the oldest. The walk is
    // bounded by the number of live entries (a victim is always erased, so the
    // loop makes progress), which is why this cannot spin.
    const auto evictOldest = [&]() -> bool {
        for (auto it = std::prev(lru_.end()); it != lru_.begin();) {
            if (it->entry.residency == TextureResidency::Pinned || it->entry.inFlight) {
                stats_.pinnedSkips++;
                if (it == lru_.begin()) return false;  // everything left is live
                --it;
                continue;
            }
            stats_.evictions++;
            residentBytes_ -= it->entry.residentBytes;
            stillToRelease.push_back(it->key);
            map_.erase(it->key);
            it = lru_.erase(it);
            return true;
        }
        return false;  // a single entry: never empty the cache to satisfy a cap
    };
    while (lru_.size() > maxEntries_ && lru_.size() > 1) {
        if (!evictOldest()) break;
    }
    while (residentBytes_ > softBytes_ && lru_.size() > 1) {
        if (!evictOldest()) break;
    }
    stats_.entries = map_.size();
    stats_.residentBytes = residentBytes_;
    return stillToRelease;
}

bool TextureCache::Erase(const TextureCacheKey& key) {
    auto it = map_.find(key);
    if (it == map_.end()) return false;
    residentBytes_ -= it->second->entry.residentBytes;
    lru_.erase(it->second);
    map_.erase(it);
    stats_.entries = map_.size();
    stats_.residentBytes = residentBytes_;
    return true;
}

void TextureCache::SetInFlight(const TextureCacheKey& key, bool inFlight) {
    auto it = map_.find(key);
    if (it == map_.end()) return;
    it->second->entry.inFlight = inFlight;
}

void TextureCache::SetResidency(const TextureCacheKey& key, TextureResidency residency) {
    auto it = map_.find(key);
    if (it == map_.end()) return;
    it->second->entry.residency = residency;
}

std::size_t TextureCache::InvalidateAddress(uint32_t guestAddress) {
    std::size_t dropped = 0;
    for (auto it = lru_.begin(); it != lru_.end();) {
        if (it->key.guestAddress == guestAddress) {
            residentBytes_ -= it->entry.residentBytes;
            map_.erase(it->key);
            it = lru_.erase(it);
            ++dropped;
        } else {
            ++it;
        }
    }
    stats_.invalidations += dropped;
    stats_.entries = map_.size();
    stats_.residentBytes = residentBytes_;
    return dropped;
}

std::size_t TextureCache::InvalidateStale(uint32_t guestAddress, uint64_t currentVersion) {
    std::size_t dropped = 0;
    for (auto it = lru_.begin(); it != lru_.end();) {
        if (it->key.guestAddress == guestAddress && it->key.dataVersion != currentVersion) {
            residentBytes_ -= it->entry.residentBytes;
            map_.erase(it->key);
            it = lru_.erase(it);
            ++dropped;
        } else {
            ++it;
        }
    }
    stats_.invalidations += dropped;
    stats_.entries = map_.size();
    stats_.residentBytes = residentBytes_;
    return dropped;
}

void TextureCache::Clear() {
    lru_.clear();
    map_.clear();
    residentBytes_ = 0;
    stats_.entries = 0;
    stats_.residentBytes = 0;
}

void TextureCache::NotifySubmitted(uint64_t serial) {
    submittedSerial_ = serial;
    // Anything older than the last submitted serial can no longer be
    // referenced by a pending command list, so it stops being eviction-exempt.
    for (auto& kv : map_) {
        if (kv.second->entry.inFlight && kv.second->entry.lastUseSerial <= submittedSerial_) {
            kv.second->entry.inFlight = false;
        }
    }
}

} // namespace mcla::native
