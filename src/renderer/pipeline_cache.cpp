#include "pipeline_cache.h"

#include <cstring>
#include <functional>
#include <d3d12.h>
#include "dxc_runtime.h"

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

// Stable 64-bit hash of shader bytecode (FNV-1a 64-bit).
static uint64_t Fnv1a64(const uint8_t* data, size_t len) {
    uint64_t hash = 0xcbf29ce484222325ULL;
    for (size_t i = 0; i < len; ++i) {
        hash ^= data[i];
        hash *= 0x100000001b3ULL;
    }
    return hash;
}

uint64_t HashShaderBytecode(const std::vector<uint8_t>& bytecode) {
    return Fnv1a64(bytecode.data(), bytecode.size());
}

uint64_t HashShaderBytecode(const std::string& hlsl) {
    return Fnv1a64(reinterpret_cast<const uint8_t*>(hlsl.data()), hlsl.size());
}

// PipelineCache implementation

PipelineCache::PipelineCache(std::size_t maxEntries) : maxEntries_(maxEntries) {
    map_.reserve(maxEntries_);
    order_.reserve(maxEntries_);
}

PipelineCache::~PipelineCache() {
    StopWorker();
}

void PipelineCache::StartWorker(Microsoft::WRL::ComPtr<ID3D12Device> device,
                                Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature) {
    std::lock_guard<std::mutex> lock(queueMutex_);
    if (workerThread_.joinable()) return;

    device_ = device;
    rootSignature_ = rootSignature;
    stopWorker_ = false;
    workerThread_ = std::thread(&PipelineCache::WorkerLoop, this, device_, rootSignature_);
}

void PipelineCache::StopWorker() {
    {
        std::lock_guard<std::mutex> lock(queueMutex_);
        stopWorker_ = true;
        queueCv_.notify_all();
    }
    if (workerThread_.joinable()) {
        workerThread_.join();
    }
}

void PipelineCache::WorkerLoop(Microsoft::WRL::ComPtr<ID3D12Device> device,
                               Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature) {
    // DXC COM compiler objects are not thread-safe; the worker owns one runtime
    // for its lifetime, lazily loaded on the first task.
    DxcRuntime dxc;
    bool dxcLoaded = false;

    while (true) {
        CompileTask task;
        {
            std::unique_lock<std::mutex> lock(queueMutex_);
            queueCv_.wait(lock, [this] { return stopWorker_ || !taskQueue_.empty(); });
            if (stopWorker_ && taskQueue_.empty()) return;
            if (taskQueue_.empty()) continue;
            task = std::move(taskQueue_.front());
            taskQueue_.pop();
        }

        // Compile HLSL -> DXIL and create the PSO on this thread. The key is
        // left in pendingKeys_ on any failure so it is not retried per draw.
        if (!device || !rootSignature || task.vsHlsl.empty() || task.psHlsl.empty()) {
            std::fprintf(stderr,
                         "PipelineCache: dropped task (missing device/root signature "
                         "or empty HLSL)\n");
            task.promise.set_value(nullptr);
            continue;
        }

        if (!dxcLoaded) {
            std::string usedDir, error;
            if (!dxc.Load("", usedDir, error)) {
                std::fprintf(stderr, "PipelineCache: worker failed to load DXC runtime: %s\n",
                             error.c_str());
                task.promise.set_value(nullptr);
                continue;
            }
            dxcLoaded = true;
        }

        std::vector<uint8_t> vsDxil, psDxil;
        std::string error;
        if (!dxc.Compile(task.vsHlsl, "main", "vs_6_0", vsDxil, error)) {
            std::fprintf(stderr, "PipelineCache: VS HLSL compilation failed: %s\n", error.c_str());
            task.promise.set_value(nullptr);
            continue;
        }
        if (!dxc.Compile(task.psHlsl, "main", "ps_6_0", psDxil, error)) {
            std::fprintf(stderr, "PipelineCache: PS HLSL compilation failed: %s\n", error.c_str());
            task.promise.set_value(nullptr);
            continue;
        }

        Microsoft::WRL::ComPtr<ID3D12PipelineState> pso;
        {
            // The key hashes render-state fields (RTV formats, depth-stencil,
            // raster, topology, blend, sample count) but the desc below
            // intentionally fixes them to the capture-instrumentation profile
            // (R8G8B8A8, triangle, no-depth, cull-none, full write mask).
            // Mapping keyed state into the PSO desc is deferred to a later
            // gate; today the real guest VS/PS HLSL and input layout are what
            // vary between entries.
            D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
            psoDesc.pRootSignature = rootSignature.Get();
            psoDesc.VS = { vsDxil.data(), vsDxil.size() };
            psoDesc.PS = { psDxil.data(), psDxil.size() };
            psoDesc.InputLayout = { task.inputLayout.data(), static_cast<UINT>(task.inputLayout.size()) };
            psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
            psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
            psoDesc.NumRenderTargets = 1;
            psoDesc.SampleDesc.Count = 1;
            psoDesc.SampleMask = UINT_MAX;
            psoDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
            psoDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
            psoDesc.RasterizerState.DepthClipEnable = TRUE;
            psoDesc.BlendState.AlphaToCoverageEnable = FALSE;
            psoDesc.BlendState.IndependentBlendEnable = FALSE;
            for (UINT i = 0; i < 8; ++i) {
                psoDesc.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
            }
            psoDesc.DepthStencilState.DepthEnable = FALSE;
            psoDesc.DepthStencilState.StencilEnable = FALSE;

            HRESULT hr = device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&pso));
            if (FAILED(hr)) {
                std::fprintf(stderr, "PipelineCache: CreateGraphicsPipelineState failed "
                                     "(hr=0x%08X)\n", static_cast<unsigned>(hr));
                pso = nullptr;
            }
        }

        // Insert into cache, clear the in-flight marker and fulfill the promise.
        Insert(task.key, pso);
        {
            std::lock_guard<std::mutex> lock(queueMutex_);
            pendingKeys_.erase(task.key);
        }
        task.promise.set_value(pso);
    }
}

Microsoft::WRL::ComPtr<ID3D12PipelineState> PipelineCache::GetOrCompile(
    const PipelineKey& key,
    const std::string& vsHlsl,
    const std::string& psHlsl,
    const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout) {

    // Fast path: check cache first
    Microsoft::WRL::ComPtr<ID3D12PipelineState> pso;
    {
        std::lock_guard<std::mutex> lock(mapMutex_);
        auto it = map_.find(key);
        if (it != map_.end()) {
            pso = it->second;
            return pso;
        }
    }

    // Cache miss: grab the fallback PSO up front (may be null before SetFallback)
    Microsoft::WRL::ComPtr<ID3D12PipelineState> fallback;
    {
        std::lock_guard<std::mutex> lock(fallbackMutex_);
        fallback = fallbackPso_;
    }

    // Queue an async compile task for this key. The worker compiles HLSL ->
    // DXIL and creates the PSO in the background; the fallback PSO is returned
    // so the draw never stalls. A key already queued or in flight is not
    // re-queued; the first task's completion populates the cache.
    CompileTask task;
    task.key = key;
    task.vsHlsl = vsHlsl;
    task.psHlsl = psHlsl;
    task.inputLayout = inputLayout;

    {
        std::lock_guard<std::mutex> lock(queueMutex_);
        if (pendingKeys_.size() >= kMaxInflight) {
            // Queue saturated; skip to bound memory under key churn. The
            // fallback PSO is still returned so the draw proceeds.
            return fallback;
        }
        if (!pendingKeys_.insert(key).second) {
            return fallback;
        }
        taskQueue_.push(std::move(task));
        queueCv_.notify_one();
    }

    return fallback;
}

void PipelineCache::SetFallbackPipeline(Microsoft::WRL::ComPtr<ID3D12PipelineState> fallback) {
    std::lock_guard<std::mutex> lock(fallbackMutex_);
    fallbackPso_ = fallback;
}

bool PipelineCache::Find(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState>& pso) const {
    std::lock_guard<std::mutex> lock(mapMutex_);
    auto it = map_.find(key);
    if (it == map_.end()) return false;
    pso = it->second;
    return true;
}

void PipelineCache::Insert(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState> pso) {
    std::lock_guard<std::mutex> lock(mapMutex_);

    // Evict if at limit (FIFO). Clear the evicted key's in-flight marker so a
    // later request can recompile it; a pending key is never in the map (the
    // worker clears pendingKeys_ right after Insert), so this is normally a
    // no-op and keeps lock order map_ -> queue_ consistent with the worker.
    if (order_.size() >= maxEntries_ && !order_.empty()) {
        const PipelineKey& oldest = order_.front();
        map_.erase(oldest);
        order_.erase(order_.begin());
        {
            std::lock_guard<std::mutex> qlock(queueMutex_);
            pendingKeys_.erase(oldest);
        }
    }

    map_.emplace(key, pso);
    order_.push_back(key);
}

void PipelineCache::Clear() {
    std::lock_guard<std::mutex> lock(mapMutex_);
    map_.clear();
    order_.clear();
}

} // namespace mcla::renderer