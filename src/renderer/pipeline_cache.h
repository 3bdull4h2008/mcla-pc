#pragma once

// Phase 5 pipeline-state key + in-memory pipeline cache with async compilation.
//
// A PipelineKey uniquely identifies a pipeline for native execution: the
// translated VS/PS program hashes, the vertex declaration, the color/depth
// target formats, the blend/raster/depth-stencil state, the topology and the
// sample count. Keys are POD and hashable so they can be used in an
// unordered_map. The cache stores ID3D12PipelineState objects directly and
// provides an async compilation queue for on-demand PSO creation.

#include <cstddef>
#include <cstring>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <future>
#include <memory>
#include <wrl/client.h>

#include <d3d12.h>

#include "renderer/shader_translator.h"
#include "renderer/dxc_runtime.h"

namespace mcla::renderer {

constexpr uint32_t kMaxRenderTargets = 8;
constexpr uint32_t kMaxVertexStreams = 16;

// Render-state inputs to a pipeline key (subset relevant to PSO creation).
struct PipelineState {
    uint32_t targetFormats[kMaxRenderTargets] = {};
    uint32_t depthStencilFormat = 0;
    uint32_t blendState = 0;      // opaque hash of blend equations/factors/masks
    uint32_t rasterState = 0;     // cull, fill, depth bias
    uint32_t depthStencilState = 0; // compare funcs, write masks, stencil ops
    uint8_t topology = 0;         // primitive topology
    uint8_t sampleCount = 1;      // MSAA sample count
};

struct PipelineKey {
    uint64_t vsHash = 0;          // translated vertex shader program hash
    uint64_t psHash = 0;          // translated pixel shader program hash
    uint64_t vertexDeclHash = 0;  // hash of vertex stream layout
    PipelineState state;
};

inline bool operator==(const PipelineState& a, const PipelineState& b) {
    return std::memcmp(&a, &b, sizeof(PipelineState)) == 0;
}
inline bool operator==(const PipelineKey& a, const PipelineKey& b) {
    return a.vsHash == b.vsHash && a.psHash == b.psHash &&
           a.vertexDeclHash == b.vertexDeclHash && a.state == b.state;
}

struct PipelineKeyHash {
    std::size_t operator()(const PipelineKey& k) const noexcept;
};

// Build a pipeline key from its inputs. `vertexDecl` is a caller-computed hash
// of the vertex stream layout (see vertex_decode in Phase 3); `state` carries
// the render state.
PipelineKey ComputePipelineKey(uint64_t vsHash, uint64_t psHash,
                               uint64_t vertexDeclHash, const PipelineState& state);

// Deterministic 64-bit hash of a PipelineKey (for debug/trace reporting).
uint64_t HashPipelineKey(const PipelineKey& key);

// Compute a stable 64-bit hash from shader bytecode (HLSL source or DXIL blob).
uint64_t HashShaderBytecode(const std::vector<uint8_t>& bytecode);
uint64_t HashShaderBytecode(const std::string& hlsl);

// Async compilation task for background PSO creation. The worker thread owns
// the DXC runtime, compiles the HLSL source to DXIL, and creates the PSO; the
// calling thread only queues the task and returns the fallback PSO.
struct CompileTask {
    PipelineKey key;
    std::string vsHlsl;
    std::string psHlsl;
    std::vector<D3D12_INPUT_ELEMENT_DESC> inputLayout;
    std::promise<Microsoft::WRL::ComPtr<ID3D12PipelineState>> promise;
};

// Bounded in-memory pipeline cache: key -> ID3D12PipelineState, with async
// compilation queue and fallback PSO for cache misses.
class PipelineCache {
public:
    explicit PipelineCache(std::size_t maxEntries = 4096);
    ~PipelineCache();

    // Start the background compilation worker thread. The worker lazily loads
    // its own DXC runtime on the first task. Must be called exactly once; a
    // second call after StopWorker is a no-op (the joined thread is not reset).
    void StartWorker(Microsoft::WRL::ComPtr<ID3D12Device> device,
                     Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature);

    // Stop the worker thread.
    void StopWorker();

    // Get or create a pipeline for the given key. If the pipeline exists in
    // the cache, returns it immediately. Otherwise queues an async task that
    // compiles the HLSL to DXIL and creates the PSO on the worker thread, and
    // returns the fallback PSO (or nullptr if no fallback). Keys already in
    // flight are not re-queued; the worker populates the cache on completion.
    Microsoft::WRL::ComPtr<ID3D12PipelineState> GetOrCompile(
        const PipelineKey& key,
        const std::string& vsHlsl,
        const std::string& psHlsl,
        const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout);

    // Set the fallback PSO used for cache misses while async compilation runs.
    void SetFallbackPipeline(Microsoft::WRL::ComPtr<ID3D12PipelineState> fallback);

    // Returns true + fills `pso` if the key is present in the cache.
    bool Find(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState>& pso) const;

    // Insert a compiled PSO into the cache (called by the worker thread).
    void Insert(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState> pso);

    std::size_t Size() const {
        std::lock_guard<std::mutex> lock(mapMutex_);
        return map_.size();
    }
    void Clear();

private:
    // Worker thread function.
    void WorkerLoop(Microsoft::WRL::ComPtr<ID3D12Device> device,
                    Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature);

    std::size_t maxEntries_;
    // Hard cap on compile tasks queued/in flight. Under render-state key churn
    // (per-draw raster state) unique keys could exceed maxEntries_, so this
    // bounds pendingKeys_/taskQueue_ memory; overflow returns the fallback.
    static constexpr std::size_t kMaxInflight = 256;
    std::vector<PipelineKey> order_;
    std::unordered_map<PipelineKey, Microsoft::WRL::ComPtr<ID3D12PipelineState>, PipelineKeyHash> map_;
    mutable std::mutex mapMutex_;

    std::mutex queueMutex_;
    std::condition_variable queueCv_;
    std::queue<CompileTask> taskQueue_;
    bool stopWorker_ = false;
    std::thread workerThread_;

    Microsoft::WRL::ComPtr<ID3D12Device> device_;
    Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature_;

    Microsoft::WRL::ComPtr<ID3D12PipelineState> fallbackPso_;
    std::mutex fallbackMutex_;

    // PipelineKeys with a compile task queued or in flight. Prevents duplicate
    // background compiles for the same key (bounded by the unique shader-pair
    // count). Guarded by queueMutex_.
    std::unordered_set<PipelineKey, PipelineKeyHash> pendingKeys_;
};

} // namespace mcla::renderer

