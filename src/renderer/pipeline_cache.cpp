#include "pipeline_cache.h"

#include <cstring>
#include <functional>
#include <d3d12.h>
#include "dxc_runtime.h"
#include "d3d12_backend.h"

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

    // Cache of root signatures keyed by CBV binding hash
    std::unordered_map<uint64_t, Microsoft::WRL::ComPtr<ID3D12RootSignature>> rootSigCache;

    auto getOrCreateRootSignature = [&](const std::vector<DxcRuntime::CbvBinding>& vsCbvs,
                                         const std::vector<DxcRuntime::CbvBinding>& psCbvs)
        -> Microsoft::WRL::ComPtr<ID3D12RootSignature> {
        // Compute a hash of all CBV bindings
        uint64_t hash = 0;
        for (const auto& cbv : vsCbvs) {
            hash = (hash * 1315423911u) ^ (static_cast<uint64_t>(cbv.register_) << 32 | cbv.space_);
        }
        for (const auto& cbv : psCbvs) {
            hash = (hash * 1315423911u) ^ (static_cast<uint64_t>(cbv.register_) << 32 | cbv.space_ | 0x80000000);
        }

        auto it = rootSigCache.find(hash);
        if (it != rootSigCache.end()) {
            return it->second;
        }

        // Collect all unique CBV (register, space) pairs
        std::vector<std::pair<uint32_t, uint32_t>> allCbvs;
        for (const auto& cbv : vsCbvs) {
            allCbvs.emplace_back(cbv.register_, cbv.space_);
        }
        for (const auto& cbv : psCbvs) {
            allCbvs.emplace_back(cbv.register_, cbv.space_);
        }

        // Sort and deduplicate
        std::sort(allCbvs.begin(), allCbvs.end());
        allCbvs.erase(std::unique(allCbvs.begin(), allCbvs.end()), allCbvs.end());

        // Build root signature with CBV slots for each unique CBV
        // Start with base root params: SRV table (t0..t3), static sampler (s0)
        std::vector<D3D12_ROOT_PARAMETER> rootParams;
        
        // Root param 0: SRV descriptor table (t0..t3)
        D3D12_DESCRIPTOR_RANGE srvRange = {};
        srvRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
        srvRange.NumDescriptors = 4;  // t0..t3
        srvRange.BaseShaderRegister = 0;
        srvRange.RegisterSpace = 0;
        srvRange.OffsetInDescriptorsFromTableStart = 0;

        D3D12_ROOT_PARAMETER srvParam = {};
        srvParam.ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
        srvParam.DescriptorTable.NumDescriptorRanges = 1;
        srvParam.DescriptorTable.pDescriptorRanges = &srvRange;
        srvParam.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
        rootParams.push_back(srvParam);

        // Root params for each CBV
        std::vector<D3D12_ROOT_PARAMETER> cbvParams;
        cbvParams.reserve(allCbvs.size());
        for (const auto& cbv : allCbvs) {
            D3D12_ROOT_PARAMETER cbvParam = {};
            cbvParam.ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
            cbvParam.Descriptor.ShaderRegister = cbv.first;
            cbvParam.Descriptor.RegisterSpace = cbv.second;
            cbvParam.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
            cbvParams.push_back(cbvParam);
        }

        // Static sampler at s0
        D3D12_STATIC_SAMPLER_DESC staticSampler = {};
        staticSampler.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
        staticSampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
        staticSampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
        staticSampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
        staticSampler.MipLODBias = 0.0f;
        staticSampler.MaxAnisotropy = 1;
        staticSampler.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS;
        staticSampler.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK;
        staticSampler.MinLOD = 0.0f;
        staticSampler.MaxLOD = D3D12_FLOAT32_MAX;
        staticSampler.ShaderRegister = 0;  // s0
        staticSampler.RegisterSpace = 0;
        staticSampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

        // Combine all root params: SRV table + CBVs
        std::vector<D3D12_ROOT_PARAMETER> allRootParams;
        allRootParams.reserve(1 + cbvParams.size());
        allRootParams.push_back(srvParam);
        for (auto& p : cbvParams) {
            allRootParams.push_back(p);
        }

        D3D12_ROOT_SIGNATURE_DESC rootDesc = {};
        rootDesc.NumParameters = static_cast<UINT>(allRootParams.size());
        rootDesc.pParameters = allRootParams.data();
        rootDesc.NumStaticSamplers = 1;
        rootDesc.pStaticSamplers = &staticSampler;
        rootDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

        Microsoft::WRL::ComPtr<ID3DBlob> signatureBlob;
        Microsoft::WRL::ComPtr<ID3DBlob> errorBlob;
        HRESULT hr = D3D12SerializeRootSignature(&rootDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
                                                 &signatureBlob, &errorBlob);
        if (FAILED(hr)) {
            std::fprintf(stderr, "PipelineCache: D3D12SerializeRootSignature failed (hr=0x%08X)\n", static_cast<unsigned>(hr));
            return rootSignature;  // Fall back to the default
        }

        Microsoft::WRL::ComPtr<ID3D12RootSignature> newRootSig;
        hr = device->CreateRootSignature(0, signatureBlob->GetBufferPointer(),
                                         signatureBlob->GetBufferSize(),
                                         IID_PPV_ARGS(&newRootSig));
        if (FAILED(hr)) {
            std::fprintf(stderr, "PipelineCache: CreateRootSignature failed (hr=0x%08X)\n", static_cast<unsigned>(hr));
            return rootSignature;  // Fall back to the default
        }

        rootSigCache.emplace(hash, newRootSig);
        return newRootSig;
    };

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
        if (!device || task.vsHlsl.empty() || task.psHlsl.empty()) {
            std::fprintf(stderr,
                         "PipelineCache: dropped task (missing device or empty HLSL)\n");
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
        // Compile WITH reflection data to enable CBV binding detection
        if (!dxc.Compile(task.vsHlsl, "main", "vs_6_0", vsDxil, error, true)) {
            std::fprintf(stderr, "PipelineCache: VS HLSL compilation failed: %s\n", error.c_str());
            task.promise.set_value(nullptr);
            continue;
        }
        if (!dxc.Compile(task.psHlsl, "main", "ps_6_0", psDxil, error, true)) {
            std::fprintf(stderr, "PipelineCache: PS HLSL compilation failed: %s\n", error.c_str());
            task.promise.set_value(nullptr);
            continue;
        }

        // Reflect CBV bindings from both VS and PS
        std::vector<DxcRuntime::CbvBinding> vsCbvs, psCbvs;
        if (!dxc.ReflectCbvBindings(vsDxil, vsCbvs, error)) {
            std::fprintf(stderr, "PipelineCache: VS CBV reflection failed: %s\n", error.c_str());
        }
        if (!dxc.ReflectCbvBindings(psDxil, psCbvs, error)) {
            std::fprintf(stderr, "PipelineCache: PS CBV reflection failed: %s\n", error.c_str());
        }

        // Get or create root signature with appropriate CBV slots
        Microsoft::WRL::ComPtr<ID3D12RootSignature> rs = getOrCreateRootSignature(vsCbvs, psCbvs);

        Microsoft::WRL::ComPtr<ID3D12PipelineState> pso;
        {
            D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
            psoDesc.pRootSignature = rs.Get();
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

    if (map_.count(key)) return;
    map_.emplace(key, pso);
    order_.push_back(key);
}

void PipelineCache::Clear() {
    std::lock_guard<std::mutex> lock(mapMutex_);
    map_.clear();
    order_.clear();
}

} // namespace mcla::renderer