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
#include <list>
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

// ---------------------------------------------------------------------------
// Content-addressed texture cache.
//
// Why this exists: ResourceCache (above) keys on address+size+format+version and
// is a plain FIFO over an opaque uint64 handle - correct for the one index
// buffer that uses it, but not a texture cache. Xenia's texture cache is keyed
// on a *descriptor* hash (page, extents, format, pitch, mip count) and evicts
// by total host memory, not entry count
// (.research/xenia/src/xenia/gpu/texture_cache.h:125-193, texture_cache.cc:181-190).
// Without it, a texture bound twice per frame is decoded and uploaded twice.
//
// Design in five sentences:
//   1. KEY: a content hash of the untiled upload payload, plus the geometry
//      that determines the host resource (extents, xenos format, import DXGI
//      format, array size, mip count, flags) and the guest address for
//      diagnosis - never the address alone, because two draw calls may alias
//      one address and the same content may live at two addresses.
//   2. CAPACITY: bounded by BOTH an entry count and a host byte budget, with a
//      soft limit (evict least-recently-used until back under) and a hard limit
//      (refuse new uploads rather than thrash). Defaults are documented at
//      kDefaultTextureCacheSoftBytes / kDefaultTextureCacheHardBytes.
//   3. INVALIDATION: the caller's `dataVersion` is part of the key, so bumping
//      it produces a different key and the old entry becomes an eviction
//      candidate immediately; InvalidateAddress() drops every entry for a guest
//      address when the guest frees/reuses the memory, which a version bump
//      alone cannot express.
//   4. EVICTION: strict LRU (a doubly linked list, O(1) touch and O(1) pop),
//      skipping entries the caller marked in-flight or pinned, so a texture the
//      GPU is still reading is never released underneath it.
//   5. The cache never frees GPU memory itself: eviction returns the keys, and
//      the backend releases the handle, because only the backend knows which
//      descriptor heap slot and staging resource go with it.
// ---------------------------------------------------------------------------

// FNV-1a 64 over the upload payload. Deterministic, and it is only a key
// discriminator - a collision costs one wrong texture, so the key also carries
// the geometry, which makes that require two equal-geometry payloads to also
// hash equal. `size` is the full payload length, not a sample: a partial hash
// would make two textures that differ only in their tail identical.
uint64_t HashTextureContent(const uint8_t* data, size_t size);

struct TextureCacheKey {
    uint64_t contentHash = 0;   // HashTextureContent over the linear payload
    uint32_t guestAddress = 0;  // diagnostic + invalidation handle
    uint32_t payloadBytes = 0;  // bytes hashed (== the linear payload size)
    uint32_t xenosFormat = 0;
    uint32_t importDxgiFormat = 0;  // 0 = plain buffer, not a decoded texture
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t depthOrArraySize = 1;
    uint32_t mipCount = 1;
    uint32_t hostFlags = 0;   // D3D12_RESOURCE_FLAGS, mirrored for the key
    uint64_t dataVersion = 0; // same concept as ResourceKey::dataVersion

    bool operator==(const TextureCacheKey&) const = default;
};

struct TextureCacheKeyHash {
    std::size_t operator()(const TextureCacheKey& k) const noexcept;
};

uint64_t HashTextureCacheKey(const TextureCacheKey& key);

enum class TextureResidency : uint8_t {
    Absent = 0,
    Resident,  // uploaded, may be evicted
    Pinned,    // caller-held: never evicted (render targets in flight)
};

struct TextureCacheEntry {
    uint64_t handle = 0;        // opaque backend handle (ID3D12Resource*)
    uint64_t uploadedVersion = 0;
    uint32_t descriptorIndex = 0;  // backend SRV heap slot
    uint32_t residentBytes = 0;    // host allocation for this entry
    uint32_t payloadBytes = 0;
    TextureResidency residency = TextureResidency::Resident;
    bool inFlight = false;  // referenced by a recorded-but-unsubmitted list
    uint64_t lastUseSerial = 0;
};

struct TextureCacheStats {
    uint64_t lookups = 0;
    uint64_t hits = 0;
    uint64_t misses = 0;
    uint64_t uploads = 0;
    uint64_t evictions = 0;
    uint64_t pinnedSkips = 0;   // eviction candidates skipped as pinned/in-flight
    uint64_t budgetRejects = 0;  // uploads refused over the hard limit
    uint64_t invalidations = 0;
    std::size_t entries = 0;
    uint64_t residentBytes = 0;
};

// Host byte budget. The soft limit is where LRU eviction starts; the hard limit
// is where new uploads are refused outright. 128 MiB / 192 MiB is chosen for
// this project rather than copied from Xenia: the boot-path renderer runs
// alongside the swapchain and the RAGE runtime in one process, and this cache
// is not the only GPU memory consumer. Both are ctor arguments so a soak can
// move them without a rebuild.
constexpr uint64_t kDefaultTextureCacheSoftBytes = 128ull << 20;
constexpr uint64_t kDefaultTextureCacheHardBytes = 192ull << 20;
constexpr std::size_t kDefaultTextureCacheMaxEntries = 4096;

class TextureCache {
public:
    explicit TextureCache(std::size_t maxEntries = kDefaultTextureCacheMaxEntries,
                          uint64_t softBytes = kDefaultTextureCacheSoftBytes,
                          uint64_t hardBytes = kDefaultTextureCacheHardBytes);

    // Look up `key`, touching it for LRU. Returns true on a HIT (with `out`
    // filled). Returns false on a miss, with `out.residency == Absent` and
    // stats().budgetRejects bumped when the key alone would exceed the hard byte
    // budget - in which case the caller must NOT upload (an upload that cannot
    // fit must not cost the whole cache). The `evict` out-param is accepted for
    // call-site compatibility but is always empty: eviction happens in Insert,
    // after the upload, because the incoming texture's resident cost is not
    // known until the backend has created it. Do not read it as a pre-upload
    // eviction list.
    bool Find(const TextureCacheKey& key, TextureCacheEntry& out,
              std::vector<TextureCacheKey>* evict = nullptr);

    // Record a completed upload. `entry.residentBytes` is the host cost.
    // Enforces the entry cap (a hard count) and the soft byte budget (a
    // pressure valve): the returned keys are the entries the caller must now
    // release with the backend (it owns the ID3D12Resource and the descriptor
    // heap slot). They are already out of the map - do not call Erase on them.
    std::vector<TextureCacheKey> Insert(const TextureCacheKey& key,
                                        const TextureCacheEntry& entry);

    // Drop one entry. Returns true if it was present.
    bool Erase(const TextureCacheKey& key);

    // Mark whether an entry is referenced by an in-flight command list. In
    // flight entries are skipped by eviction.
    void SetInFlight(const TextureCacheKey& key, bool inFlight);
    void SetResidency(const TextureCacheKey& key, TextureResidency residency);

    // Drop every entry whose guestAddress matches - the "guest freed or reused
    // this allocation" signal, which a dataVersion bump cannot express because
    // the version lives in the key we were handed. Returns the count dropped.
    std::size_t InvalidateAddress(uint32_t guestAddress);
    // Bump-and-drop: InvalidateAddress for the caller that tracks versions.
    std::size_t InvalidateStale(uint32_t guestAddress, uint64_t currentVersion);

    void Clear();
    TextureCacheStats Stats() const { return stats_; }
    uint64_t ResidentBytes() const { return residentBytes_; }
    std::size_t Size() const { return map_.size(); }

    // Hint that the GPU finished with everything from `serial` onwards.
    void NotifySubmitted(uint64_t serial);

private:
    struct Node {
        TextureCacheKey key;
        TextureCacheEntry entry;
    };
    void Touch(typename std::list<Node>::iterator it);
    // Intrusive LRU: `front_` is the most recently used, `back_` the eviction
    // candidate. std::list keeps node addresses stable, so the map stores
    // iterators and Touch/Erase are O(1) - unlike ResourceCache's
    // order_.erase(order_.begin()), which is O(n) per eviction.
    using List = std::list<Node>;
    List lru_;
    std::unordered_map<TextureCacheKey, List::iterator, TextureCacheKeyHash> map_;

    std::size_t maxEntries_;
    uint64_t softBytes_;
    uint64_t hardBytes_;
    uint64_t residentBytes_ = 0;
    uint64_t useSerial_ = 0;
    uint64_t submittedSerial_ = 0;
    TextureCacheStats stats_{};
};

} // namespace mcla::native
