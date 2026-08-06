#include "pipeline_cache.h"

#include <cstring>
#include <functional>

namespace mcla::renderer {

// Simple 64-bit hash combiner (splitmix64-inspired).
static uint64_t CombineHash(uint64_t a, uint64_t b) {
    uint64_t h = a ^ (b + 0x9e3779b97f4a7c15ULL + (a << 6) + (a >> 2));
    h ^= h >> 33;
    h *= 0xff51afd7ed558ccdULL;
    h ^= h >> 33;
    h *= 0xc4ceb9fe1a85ec53ULL;
    h ^= h >> 33;
    return h;
}

static uint64_t HashState(const PipelineState& state) {
    uint64_t h = 0;
    for (uint32_t i = 0; i < kMaxRenderTargets; ++i)
        h = CombineHash(h, state.targetFormats[i]);
    h = CombineHash(h, state.depthStencilFormat);
    h = CombineHash(h, state.blendState);
    h = CombineHash(h, state.rasterState);
    h = CombineHash(h, state.depthStencilState);
    h = CombineHash(h, state.topology);
    h = CombineHash(h, state.sampleCount);
    return h;
}

PipelineKey ComputePipelineKey(uint64_t vsHash, uint64_t psHash,
                               uint64_t vertexDeclHash, const PipelineState& state) {
    PipelineKey key;
    key.vsHash = vsHash;
    key.psHash = psHash;
    key.vertexDeclHash = vertexDeclHash;
    key.state = state;
    return key;
}

uint64_t HashPipelineKey(const PipelineKey& key) {
    uint64_t h = CombineHash(key.vsHash, key.psHash);
    h = CombineHash(h, key.vertexDeclHash);
    h = CombineHash(h, HashState(key.state));
    return h;
}

std::size_t PipelineKeyHash::operator()(const PipelineKey& k) const noexcept {
    return static_cast<std::size_t>(HashPipelineKey(k));
}

PipelineCache::PipelineCache(std::size_t maxEntries) : maxEntries_(maxEntries) {
    map_.reserve(maxEntries_);
    order_.reserve(maxEntries_);
}

uint64_t PipelineCache::Insert(const PipelineKey& key, uint64_t handle) {
    auto it = map_.find(key);
    if (it != map_.end()) {
        it->second = handle;
        return handle;
    }

    // Evict if at limit.
    if (order_.size() >= maxEntries_ && !order_.empty()) {
        const PipelineKey& oldest = order_.front();
        map_.erase(oldest);
        order_.erase(order_.begin());
    }

    map_.emplace(key, handle);
    order_.push_back(key);
    return handle;
}

bool PipelineCache::Find(const PipelineKey& key, uint64_t& handle) const {
    auto it = map_.find(key);
    if (it == map_.end())
        return false;
    handle = it->second;
    return true;
}

void PipelineCache::Clear() {
    map_.clear();
    order_.clear();
}

} // namespace mcla::renderer
