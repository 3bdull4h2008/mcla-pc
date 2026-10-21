#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <wrl/client.h>

#include <cstdint>
#include <filesystem>
#include <memory>
#include <mutex>
#include <optional>
#include <unordered_map>
#include <vector>

#include "renderer/resource_cache.h"
#include "renderer/pipeline_cache.h"
#include "renderer/texture_decode.h"
#include "renderer/trace_types.h"

namespace mcla::native {

class D3D12Backend {
public:
    static constexpr uint32_t kBufferCount = 3;

    D3D12Backend();
    ~D3D12Backend();

    // Initialize D3D12 device, command queue, swap chain, descriptor heaps
    bool Initialize(HWND hwnd, uint32_t width, uint32_t height);
    void Shutdown();

    bool IsInitialized() const { return m_initialized; }

    // Resize swap chain buffers
    bool Resize(uint32_t width, uint32_t height);

    // Frame lifecycle
    bool BeginFrame();
    bool ClearAndPresent(float r, float g, float b, float a);

    // F-610: PresentDirect() was removed. It had zero callers and advanced
    // m_frameIndex / signalled a fence with no command list executed. The
    // present paths that do exist (DrawDynamicMesh*, ClearAndPresent,
    // PresentBgra) close+execute+present atomically.

    // W6: full-viewport blit of linear 32bpp host pixels onto the backbuffer.
    // Uploads through a persistent DEFAULT texture + staging, CopyResource to
    // the swapchain image, then Present. Nearest-neighbor scales if (w,h) does
    // not match the current backbuffer. Caller should fall back to
    // ClearAndPresent when this returns false.
    bool PresentBgra(uint32_t width, uint32_t height, const uint8_t* pixels);

    // Host-side geometry for DrawDynamicMesh. Data is already validated by the
    // caller; the backend never interprets guest layouts — it only uploads and
    // draws with the input layout the PSO declares. `cachedIndexGpu` is set by
    // the caller to reuse a previously cached static index buffer (0 = none).
    struct DynamicMeshDesc {
        const void* vertexBytes = nullptr;  // host vertex data
        uint32_t vertexBytesSize = 0;
        uint32_t vertexStride = 0;          // must match the test input layout (28)
        uint32_t vertexCount = 0;           // non-indexed draw count

        bool indexed = false;
        const void* indexBytes = nullptr;   // uploaded this frame (indexed case)
        uint32_t indexBytesSize = 0;
        DXGI_FORMAT indexFormat = DXGI_FORMAT_R16_UINT;
        D3D12_GPU_VIRTUAL_ADDRESS cachedIndexGpu = 0;  // cached static IB, or 0
        uint32_t cachedIndexBytesSize = 0;  // byte size of cachedIndexGpu (required when set)
        // F-633: the Xenos constant bank for this draw, already read out of guest
        // memory by the producer and byte-copied to the host. The backend must not
        // read guest memory itself (it has no endianness discipline and no validity
        // check at this layer), so the read happens upstream and arrives here as
        // plain bytes. Null means "the producer had no constant bank", which the
        // backend reports rather than silently substituting zeros -- a shader that
        // reads a zero constant and a shader that reads the right one are not the
        // same result, and the difference has to be countable.
        const void* guestConstBytes = nullptr;
        uint32_t guestConstBytesSize = 0;
        uint32_t indexCount = 0;            // indexed draw count

        // F-637: topology and index/vertex offsets. Before this the draw path
        // hardcoded IASetPrimitiveTopology(TRIANGLELIST) and
        // DrawIndexedInstanced(count, 1, 0, 0, 0), so every captured draw was
        // silently re-interpreted as a non-indexed-from-zero triangle list: a
        // LINE_STRIP draw drew garbage, and a draw with a non-zero start index
        // or base vertex drew the wrong vertices with no log line anywhere.
        // `topology` is the D3D12 topology, NOT the Xenos prim_type: the caller
        // maps it through MapXenosPrimType, which refuses the prim_types that
        // have no D3D12 equivalent instead of substituting a triangle list.
        D3D_PRIMITIVE_TOPOLOGY topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        uint32_t startIndexLocation = 0;    // DrawIndexedInstanced StartIndexLocation
        int32_t baseVertexLocation = 0;     // DrawIndexedInstanced BaseVertexLocation
    };

    // F-637: Xenos VGT_DRAW_INITIATOR.prim_type (xenos.h:44-59, enum
    // xenos::PrimitiveType) -> D3D_PRIMITIVE_TOPOLOGY. The value space is the
    // architected one, NOT DrawPacket::primType's own stale comment ("0=TriList,
    // 1=TriStrip"): 0x00 kNone, 0x01 kPointList, 0x02 kLineList, 0x03 kLineStrip,
    // 0x04 kTriangleList, 0x05 kTriangleFan, 0x06 kTriangleStrip, 0x07
    // kTriangleWithWFlags, 0x08 kRectangleList, 0x0C kLineLoop, 0x0D kQuadList,
    // 0x0E kQuadStrip, 0x0F kPolygon.
    //
    // Returns false for every prim_type with no exact D3D12 topology and leaves
    // `out` untouched: kNone, kTriangleWithWFlags (0x07, a per-triangle W-flag
    // that D3D12 cannot carry in a topology), kLineLoop (0x0C — D3D12 has no loop
    // topology), kQuadList/kQuadStrip (0x0D/0x0E), kPolygon (0x0F) and
    // everything >= 0x10. Those are refused, counted and logged by the caller,
    // because a TRIANGLELIST substitution renders a plausible frame that is not
    // the guest's frame.
    //
    // kRectangleList (0x08) is the one case whose answer DEPENDS ON A FACT the
    // caller holds and D3D12 cannot be asked for, so it takes a third argument:
    //
    //   hasGeometryStage == false (the default, and what every pre-existing call
    //   site passes) -> 0x08 is REFUSED, exactly as before. The default is the
    //   safe answer on purpose: a rectangle list is three guest vertices and a
    //   TRIANGLELIST without the expansion stage draws one of its two triangles.
    //
    //   hasGeometryStage == true -> 0x08 maps to D3D_PRIMITIVE_TOPOLOGY_TRIANGLE-
    //   LIST, which is what the PSO in hand will actually accept, because that
    //   PSO has the geometry stage that turns the triangle into a quad. The
    //   mapping is the reference's, measured, not chosen: the reference sets
    //   D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST at d3d12_command_processor.cc
    //   :2308-2310 and calls D3DDrawInstanced(count, 1, 0, 0) with NO index
    //   buffer at :2330-2339, and keys the pipeline with
    //   geometry_shader = kRectangleList at d3d12/pipeline_cache.cc:1402-1405.
    //
    // WHY THIS IS A CARRIED FACT AND NOT A DEVICE QUERY. Two reasons, both
    // load-bearing. (1) D3D12 cannot report a PSO's geometry shader:
    // ID3D12PipelineState has one pipeline method, GetCachedBlob, and
    // GetGeometryShader is D3D10-only. (2) The DEVICE is not the question. The
    // feature level is already measured (the backend logs "geometry-stage
    // capable = yes -- F-653" at 0xB000/11.0), so gating on it would map 0x08 on
    // EVERY captured rectangle draw -- including the ones where the pipeline in
    // hand is the GS-LESS fallback handed back on a cache miss -- and produce
    // half-quads with nothing in the log saying anything was dropped. The flag
    // therefore means "the PSO I am about to draw with HAS the stage", and it is
    // supplied by PipelineCache::GetOrCompile's out-parameter, which can only
    // say yes on a cache hit whose key named the stage.
    //
    // The refusal counter for 0x08 below still fires on the false arm, so the
    // gate stays countable: a soak reads PrimTypeRefusalCount(0x08) as "rectangle
    // draws refused because the PSO in hand had no expansion stage".
    static bool MapXenosPrimType(uint32_t primType, D3D_PRIMITIVE_TOPOLOGY& out,
                                 bool hasGeometryStage = false);

    // F-637: refusals from MapXenosPrimType, by prim_type, so a soak can prove
    // the gate fired (0 until it does; the counter is the evidence).
    static uint64_t PrimTypeRefusalCount(uint32_t primType);
    static uint64_t PrimTypeRefusalTotal();

    // Phase 3 native draw slice: submit a test indexed triangle through the
    // upload arena + test PSO. Proves buffer, index, viewport, topology, and
    // RTV handling end-to-end on the native (non-Xenos) path.
    bool DrawTestMeshedTriangle(uint32_t frame);

    // Generic dynamic-geometry draw: uploads the caller's vertex/index bytes
    // through the per-frame upload arena and issues one draw (indexed or not).
    // This is the consumption target for a captured DrawPacket whose layout
    // provably matches the test PSO input layout.
    bool DrawDynamicMesh(const DynamicMeshDesc& desc);

    // Overload that accepts a specific PSO to use instead of the default test pipeline.
    bool DrawDynamicMeshWithPipeline(const DynamicMeshDesc& desc,
                                     ID3D12PipelineState* pipeline);

    // Every `return false` in DrawDynamicMeshWithPipeline that used to be
    // SILENT now names itself through this. `gate` is a stable token, a/b/c
    // are whatever numbers that gate refused on (0 where meaningless) -- the
    // point is that "the draw produced nothing" and "the draw was never
    // attempted" stop being the same log. Emits the NEW marker
    // `D3D12-DRAW-RETURN`; appends to nothing existing.
    void RecordSilentDrawReturn(const char* gate, uint32_t a = 0, uint32_t b = 0,
                                uint32_t c = 0);

    // 2026-10-02: EVERY `return false` in BeginFrame() names itself through
    // this. BeginFrame() is the single boolean that gates the entire draw path
    // (render_thread.cpp:3598 takes its result as `beganFrame`, and
    // DRAW-CP-ISSUED reports beginFrame=0 when it is false) and until this edit
    // it wrote NO log line on any of its exits -- so `beginFrame=0` in a soak
    // named the OUTCOME and not the CAUSE. Five exits exist (d3d12_backend.cpp
    // :3360 twice, :3362, :3365, :3368); `kFenceGate` is the WaitForCurrentFrameGpu
    // one, which cannot fire from BeginFrame's own :3360 check (same recursive
    // mutex, and m_initialized is written only under it) but is named anyway so
    // the enumeration is complete rather than curated.
    //
    // The enum is the per-gate COUNTER key, so a soak can count "the in-frame
    // latch refused 14,000 times" separately from "the allocator Reset failed
    // twice". A single shared counter would answer only "BeginFrame refused N
    // times" and leave the one question this row exists for unanswered.
    enum class BeginFrameGate : uint32_t {
        kNotInitialized = 0,   // !m_initialized            (device down / post-Shutdown)
        kAlreadyInFrame = 1,   // m_inFrame                 (a begun frame was never released)
        kFenceGate = 2,        // !WaitForCurrentFrameGpu() (unreachable from BeginFrame; see above)
        kAllocatorReset = 3,   // ID3D12CommandAllocator::Reset failed
        kCommandListReset = 4, // ID3D12GraphicsCommandList::Reset failed
        kCount
    };
    void RecordBeginFrameRefusal(BeginFrameGate gate, uint32_t a = 0, uint32_t b = 0);

    // 2026-10-02: the OTHER half of the BeginFrame fix. `m_inFrame` was a latch
    // with no release-on-abandon: BeginFrame() sets it (:3370) and only
    // PresentOwnedFrame (:3552) or EndFrame (:3782) clear it, so any caller that
    // began a frame and then returned WITHOUT presenting left the whole backend
    // permanently unable to open another -- and the symptom is exactly the
    // measured one, `beginFrame=0` on every subsequent draw with no other marker
    // moving. Three such sites are live in the tree and all are in files this
    // stream owns; see the call sites in render_thread.cpp and
    // d3d12_backend.cpp:3109. AbandonFrame is the D3D12-sanctioned release: the
    // next BeginFrame Resets the allocator and the command list, which discards
    // whatever was recorded but never executed. It does NOT make a draw happen
    // and it does NOT bypass any gate -- it stops one abandoned frame from
    // poisoning every later one, so the refusal becomes per-frame and the new
    // D3D12-BEGINFRAME-REFUSE row can name it.
    //
    // Internally guarded on `m_inFrame`, so calling it after a call that already
    // presented is a no-op and cannot double-release.
    void AbandonFrame(const char* owner);


    // Pipeline cache access for Phase 5 shader integration.
    renderer::PipelineCache& GetPipelineCache() { return m_pipelineCache; }

    // Counters for the Phase 3 debug overlay / structured log.
    struct DrawStats {
        uint64_t drawsIssued = 0;
        uint64_t uploadsBytes = 0;
        uint64_t bytesThisFrame = 0;
        uint64_t cacheHits = 0;
        uint64_t cacheMisses = 0;
    };
    const DrawStats& Stats() const { return m_stats; }

    // 2026-10-02: the DXGI format of the render target the draw path actually
    // bound, as a raw DXGI_FORMAT value (28 = R8G8B8A8_UNORM), or 0 if no render
    // target has been bound yet. Read-only and side-effect free.
    //
    // It exists because the OTHER half of the only comparison that matters for
    // a silent draw is not reachable from this class: D3D12 exposes no
    // reflection getter for a pipeline state's RTVFormats[], so the PSO side
    // lives in the render thread (which maps the guest's RB_COLOR_INFO) and the
    // bound side lives here. Until there was an accessor the two numbers were
    // only ever printed in two different translation units and never in the
    // same row.
    uint32_t BoundRtvFormat() const { return m_boundRtvFormat; }

    // ---------------------------------------------------------------------
    // F-725: the POST-DRAW PIXEL SAMPLE.
    //
    // Until now no row in this tree carried a pixel value, because every
    // framebuffer sample in the log (PRESENT-FB and its NEAR-BLAME sibling) is
    // taken inside RenderCommand::PRESENT and only when blitVA != 0, i.e. from
    // the GUEST's linear surface, and every one of them is timestamped BEFORE
    // the draws in build/w699.log. This is the reading of the surface the draw
    // actually wrote, taken after the draw.
    //
    // Valid() is the gate. It is false until a readback has completed, so a
    // caller that reads these before the first draw gets false and must say
    // nothing, rather than reporting a default-initialised zero as a
    // measurement. ChainedValuesAreConsistent() exists so that the gate cannot
    // be passed by a partially-updated set: RenderThreadPixelsValid() is only
    // true when both the flag and the dimensions agree.
    // ---------------------------------------------------------------------
    bool RenderThreadPixelsValid() const {
        return m_lastPixelValid && m_lastPixelTotal > 0 &&
               m_lastPixelTotal == static_cast<uint64_t>(m_width) * m_height;
    }
    uint32_t RenderThreadPixelX() const { return m_lastPixelX; }
    uint32_t RenderThreadPixelY() const { return m_lastPixelY; }
    uint8_t RenderThreadPixelR() const { return m_lastPixelR; }
    uint8_t RenderThreadPixelG() const { return m_lastPixelG; }
    uint8_t RenderThreadPixelB() const { return m_lastPixelB; }
    uint8_t RenderThreadPixelA() const { return m_lastPixelA; }
    uint64_t RenderThreadNonBlackPixels() const { return m_lastPixelNonBlack; }
    uint64_t RenderPixelCensusTotal() const { return m_lastPixelTotal; }
    uint32_t RenderThreadPixelRowPitch() const { return m_lastPixelRowPitch; }
    uint64_t RenderThreadMaxChannel() const { return m_lastPixelMaxChannel; }
    double RenderThreadMeanChannel() const { return m_lastPixelMeanChannel; }
    uint64_t DrawReadbackCompletions() const { return m_drawReadbackCompletions; }

    // ---------------------------------------------------------------------
    // F-650: back-buffer frame ownership.
    // The back buffer had THREE writers and no arbiter: the draw path
    // (DrawDynamicMeshWithPipeline), the guest-framebuffer blit (PresentBgra,
    // which ends in CopyResource over the whole back buffer) and the clear
    // (ClearAndPresent, whose first act is ClearRenderTargetView). Each closed
    // its own command list and called m_swapChain->Present itself, so the frame
    // on screen was whichever of the three ran last. build/w662.log measured the
    // two heavy ones running 15,660 and 197,580 times in one 180 s soak.
    //
    // The arrangement is now settled and singular: the DRAW path owns the back
    // buffer, and the other two refuse to write it once a draw has presented.
    // See PresentOwnedFrame in the .cpp for which surface that is and why.
    // ---------------------------------------------------------------------
    enum class FrameOwner : uint8_t { None = 0, Draw = 1, Blit = 2, Clear = 3 };
    static const char* FrameOwnerName(FrameOwner owner);

    // Census. `presented` counts every Present() this backend issued.
    // Once DrawPathOwnsBackBuffer() is true, `drawOwned` must equal `presented`
    // and blitRefused + clearRefused must account for every refused write --
    // i.e. the final content of every presented frame is decided by exactly one
    // writer, and it is the same writer every time. `conflicts` counts frames in
    // which two writers touched the back buffer between two presents; it is
    // structurally impossible under the current policy, so a non-zero value
    // means a fourth writer was added without going through the arbiter.
    uint64_t PresentedFrames() const { return m_presentedFrames; }
    uint64_t DrawOwnedFrames() const { return m_drawOwnedFrames; }
    uint64_t BlitRefusedFrames() const { return m_blitRefused; }
    uint64_t ClearRefusedFrames() const { return m_clearRefused; }
    uint64_t FrameOwnerConflicts() const { return m_ownerConflicts; }
    bool DrawPathOwnsBackBuffer() const { return m_drawPathTookBackBuffer; }

    // Phase 4 texture path (data-independent slice). Uploads host-linear
    // decoded pixel bytes (already untiled by texture_decode) into a
    // DEFAULT-heap texture and creates a shader-visible SRV at t0. Returns
    // false on any D3D12 failure; a failed create leaves the previous texture
    // untouched.
    bool CreateDecodedTexture(const uint8_t* linearPixels, uint32_t width,
                              uint32_t height, uint32_t dxgiFormat);

    // F-638: the plan-driven import. `CreateDecodedTexture`'s 4-argument form is
    // a thin forwarder to this one with a scalar plan, kept because
    // tools/validators/texture_import_validator.cpp:379 calls it directly.
    //
    // `plan` is the authoritative decision from native::PlanTextureImport and is
    // never second-guessed here: the host format is plan->nativeDxgiFormat, so
    // the zero-copy BC1/BC2/BC3/BC4/BC5 path becomes importable without this
    // file re-implementing the Xenos->DXGI table (which is what made the old
    // two-case switch at d3d12_backend.cpp:703-709 wrong the moment the table
    // grew a row). A plan whose format this backend cannot import is refused
    // with MCLA_LOG_ERROR + native::TextureRefusalName(plan->refusal) and
    // returns false -- never a substituted format, because sampling a
    // re-interpreted payload is not "close enough", it is a different image.
    //
    // Mips: `mipCount` == 1 creates MipLevels = 1 with NO UAV flag and must not
    // be followed by GenerateMipmaps (which requires
    // ALLOW_UNORDERED_ACCESS). `mipCount` > 1 uploads every level from
    // `mipPayloads[i]` with per-subresource transitions, OR, when
    // `generateMipChain` is set, allocates the UAV flag and lets the mipgen PSO
    // derive the chain. The two are mutually exclusive and the caller must say
    // which: a chain the guest supplied is uploaded, a chain the guest did not
    // supply is generated.
    struct TextureImportDesc {
        const native::TextureImportPlan* plan = nullptr;
        const uint8_t* mipPayloads[native::kTextureMaxMips] = {};
        uint32_t mipBytes[native::kTextureMaxMips] = {};
        uint32_t mipCount = 1;              // 0 => refused (an unknown chain)
        bool generateMipChain = false;      // UAV + mipgen instead of upload
        uint32_t width = 0;                 // mip 0, texels
        uint32_t height = 0;
        uint32_t srvSlot = kTexture2DSlot;  // heap slot to publish the SRV into
        // Resident handle out-param. Committed only on success, so a refused
        // import leaves the previous resident in place.
        Microsoft::WRL::ComPtr<ID3D12Resource>* outTexture = nullptr;
        // SRV published into `srvSlot` only after the copy is enqueued.
        D3D12_GPU_DESCRIPTOR_HANDLE* outSrvGpu = nullptr;
    };
    bool CreateDecodedTexture(const TextureImportDesc& desc);

    // F-638: named import refusals. `CreateDecodedTexture(TextureImportDesc)`
    // increments the bucket matching plan->refusal; a plan that is refused for a
    // backend-side reason (unsupported DXGI form, short payload, mip count
    // beyond the chain) increments `other`.
    static uint64_t TextureImportRefusals(uint32_t reason);
    static uint64_t TextureImportRefusalTotal();

    // F-649: THE IMPORT CENSUS. The `TEX-IMPORT` literal did not exist as a
    // source marker anywhere under src/ or generated/ before this block, so every
    // historical "the game issued zero texture imports" reading was a vacuous
    // zero of the F-057(6) kind -- a count of a log call, not of guest traffic.
    //
    // F-648 already made PlanTextureImport bump the per-format census
    // (renderer/texture_decode.h:513-532) from its single success exit and from
    // NoteTextureRefusal, so TextureImportCountTotal /
    // TextureImportAcceptedTotal already answer "did the title reach the import
    // path at all" and "was every plan it reached refused". What was missing was
    // the marker itself and the BACKEND-SIDE half of the accounting, which is
    // what these rows add:
    //
    //   TextureImportPlanCount()  - every plan that reached
    //     CreateDecodedTexture, accepted or refused, accepted or not. This is
    //     the row the `TEX-IMPORT` marker's own throttle rides on.
    //   TextureImportSuccessCount() - plans that produced a resident texture.
    //
    // Every backend-side refusal ALSO still increments g_textureImportRefusalOther
    // (unchanged), so TextureImportRefusals(32)/TextureImportRefusalTotal() keep
    // their F-638 values exactly; the enum below is an ADDITIONAL by-reason view
    // of that same total, not a replacement bucket.
    static uint64_t TextureImportPlanCount();
    static uint64_t TextureImportSuccessCount();

    // Why the BACKEND refused a plan the renderer accepted. These are the cases
    // F-638 deliberately filed under `other` because they are not
    // native::TextureRefusal values -- "plan was fine but THIS backend could not
    // carry it" (d3d12_backend.cpp:263-268). They are the ones a soak cannot
    // otherwise attribute: one `other` bucket covering ten distinct causes is a
    // count, not a diagnosis.
    enum class TextureBackendRefusal : uint32_t {
        Unlisted = 0,              // a new site has not been classified yet
        LegacyUnsupportedDxgi,     // the 4-arg forwarder, dxgi outside {R8G8B8A8,R8}
        LegacyBadArgs,             // the 4-arg forwarder, null pixels or zero extent
        NoHostFormat,              // plan wants a DXGI form absent from the table
        ZeroExtent,
        MipCountOutOfRange,        // mipCount 0 or > kTextureMaxMips
        MipChainAndGenerate,       // mipCount > 1 AND generateMipChain
        MipLevelHasNoPayload,      // a declared level of the chain was not supplied
        MipZeroHasNoPayload,
        SrvSlotOutOfRange,         // srvSlot outside the heap
        ShortPayload,              // mip bytes < pitch * block rows
        MipgenFailed,              // GenerateMipmaps refused; mip 0 is resident
        kCount,
    };
    static const char* TextureBackendRefusalName(TextureBackendRefusal reason);
    static uint64_t TextureBackendRefusals(TextureBackendRefusal reason);
    static uint64_t TextureBackendRefusalTotal();

    // F-639: one captured texture descriptor index, ready to bind.
    //
    // The backend does NOT walk guest memory for textures, for the same reason
    // it does not for the constant bank (see the guestConstBytes note above):
    // DecodeGuestTextureDescriptor/UntileTexture2D need explicit-endianness
    // guest reads and a validity check that live one layer up. The producer
    // therefore hands over a 24-BYTE SNAPSHOT of the fetch constant plus the
    // host-untiled payload per level. DecodeGuestTextureDescriptor is a pure
    // function of those 24 bytes, so the backend running it is not a guest read.
    struct GuestTextureEntry {
        uint32_t descriptorIndex = 0;    // t-register index from DrawPacket
        uint8_t descriptorBytes[24] = {};  // big-endian xe_gpu_texture_fetch_t
        const uint8_t* mipPayloads[native::kTextureMaxMips] = {};
        uint32_t mipBytes[native::kTextureMaxMips] = {};
        uint32_t mipCount = 0;           // 0 => plan.mipCount is used
    };

    // F-639: bind up to 16 captured texture descriptors for one pass. Per
    // index: decode -> PlanTextureImport -> on refusal log
    // TextureRefusalName(plan.refusal) once, count it, and write a NULL SRV at
    // kTexture2DSlot + i (a null SRV is a defined sample of a defined colour, so
    // an unbound slot is safe, whereas leaving a stale SRV from a previous pass
    // is not). On success the linear payload is content-hashed
    // (HashTextureContent) and looked up in the TextureCache: a hit costs no
    // upload, a miss uploads once and releases whatever keys Insert returns for
    // eviction. The SRV is then created into kTexture2DSlot + descriptorIndex.
    //
    // ONE MIP PER DESCRIPTOR INDEX PER PASS. A draw that needs a mip range other
    // than level 0 is refused (counted, logged) rather than bound to level 0,
    // because "the shader asked for mip 3 and got mip 0" renders a sharp image
    // and hides the bug.
    //
    // Returns the number of descriptor indices that ended up bound to a real
    // resident texture; refusals still leave a valid null SRV behind, so a
    // partial result is a usable draw.
    uint32_t BindGuestTextures(const GuestTextureEntry* entries, uint32_t count);

    // F-639: sampler table for the current draw. `hostSampler` is
    // native::DecodeGuestSamplerState's output; the descriptor is interned in
    // the sampler heap and root parameter 1 (the SAMPLER descriptor table) is
    // set. This replaces the single hardcoded D3D12_STATIC_SAMPLER_DESC, which
    // meant every guest fetch constant's clamp mode, filter, aniso and LOD bias
    // were discarded and the frame was sampled with clamp+linear+aniso1.
    //
    // `hostSampler.hash` is the cache key (HostSamplerDesc.hash). Returns false
    // when the sampler heap is exhausted: the caller then leaves the previous
    // table bound and the draw is counted, because binding a stale sampler is
    // worse than a reported one.
    bool BindGuestSampler(const native::HostSamplerDesc& hostSampler);

    // Bind the SRV descriptor table (+ the sampler table at root param 1) for
    // the current draw. No-op when no decoded texture has been created.
    void BindDecodedTexture();

    // Phase 5 live DXIL PSO creation: build a graphics pipeline state from
    // runtime-compiled VS/PS DXIL blobs and the provided render state.
    // Returns false on any D3D12 failure.
    bool CreatePipelineFromDxil(const std::vector<uint8_t>& vsDxil,
                                const std::vector<uint8_t>& psDxil,
                                const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout,
                                const renderer::PipelineState& state,
                                Microsoft::WRL::ComPtr<ID3D12PipelineState>& outPso);

    // F-610: DrawCapturedPacket() was removed — zero callers, and it self-failed
    // (null vertexBytes tripped the DrawDynamicMesh guard while the PSO lookup
    // passed empty HLSL the pipeline cache drops). The live capture path is the
    // DRAW_CAPTURED RenderCommand handled in src/render_thread.cpp.
    // BuildPipelineStateFromPacket / UploadPacketGeometry are retained as
    // helpers for that path; see the F-610 note at their definitions.

    // Helper: Build D3D12 input layout from captured grcFvf vertex declaration.
    // Returns empty vector on failure (unsupported format).
    std::vector<D3D12_INPUT_ELEMENT_DESC>
    BuildInputLayoutFromGrcFvf(const native::GrcFvfDesc& grcFvf);

    // Helper: Build render state from captured DrawPacket state.
    renderer::PipelineState BuildPipelineStateFromPacket(const native::DrawPacket& packet);

    // Helper: Upload guest vertex/index data from captured packet to upload arena.
    // Returns false if upload fails or data is invalid.
    bool UploadPacketGeometry(const native::DrawPacket& packet,
                              D3D12_GPU_VIRTUAL_ADDRESS& vbGpu,
                              D3D12_GPU_VIRTUAL_ADDRESS& ibGpu,
                              uint32_t& vertexStride,
                              uint32_t& vertexCount,
                              uint32_t& indexCount,
                              DXGI_FORMAT& indexFormat);

    // Phase 4: Sampler state management
    // Creates or retrieves a cached sampler state from the provided descriptor.
    // Returns the D3D12_STATIC_SAMPLER_DESC index for root signature binding,
    // or UINT32_MAX on failure.
    uint32_t GetOrCreateStaticSampler(const D3D12_SAMPLER_DESC& desc);

    // Phase 4: Render target view for a texture (allows texture to be used as RT)
    // Creates an RTV for the given texture resource with the specified format.
    // Returns false on failure.
    bool CreateRenderTargetView(ID3D12Resource* texture, DXGI_FORMAT format,
                                D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle);

    // Phase 4: Depth-stencil view for a texture
    bool CreateDepthStencilView(ID3D12Resource* texture, DXGI_FORMAT format,
                                D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle);

    // Phase 4: Generate mipmaps for a texture (requires SRV + UAV)
    // Source texture must have D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS.
    bool GenerateMipmaps(ID3D12Resource* texture, uint32_t mipLevels);

    // Phase 5: Create mipmap generation compute pipeline (root signature + PSO)
    bool CreateMipGenPipeline();

    // F-641: the DXC compile of the mipgen CS used to sit inline in
    // GenerateMipmaps, i.e. on whichever draw happened to be the first one to
    // need a mip chain -- a multi-hundred-millisecond LoadLibrary + fxc compile
    // between MapUpload and DrawIndexedInstanced, stalling the render thread
    // mid-frame. It is now a one-shot warm-up kicked off at the end of
    // Initialize; GenerateMipmaps only ever uses an already-built PSO and
    // refuses loudly when the warm-up failed.
    bool EnsureMipGenPipeline();

    // Phase 6: Create shader-visible sampler descriptor heap
    bool CreateSamplerHeap();

    // Phase 6: Dynamic sampler descriptor heap management
    // Returns CPU/GPU descriptor handles for a sampler state; creates and caches if new.
    // The GPU handle is valid for binding to a root signature descriptor table slot.
    struct SamplerDescriptor {
        D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle;
        D3D12_GPU_DESCRIPTOR_HANDLE gpuHandle;
    };
    SamplerDescriptor GetOrCreateSamplerDescriptor(const D3D12_SAMPLER_DESC& desc);

    // Binds the shader-visible sampler descriptor heap to the command list.
    // Call after BeginRenderPass or before drawing when sampler tables are needed.
    void BindSamplerHeap();

    // Phase 4: Resolve a render target to a texture (for MSAA or format conversion)
    // F-640: now transitions from the TRACKED state of each resource instead of
    // asserting RENDER_TARGET and COMMON (:2106/:2111 before), which was only
    // ever true on the first call for a given resource.
    bool ResolveRenderTarget(ID3D12Resource* srcRt, ID3D12Resource* dstTexture,
                             DXGI_FORMAT format);

    // F-640: the EDRAM-resolve entry point. `srcRt` is the MSAA colour surface
    // and `dstTexture` the single-sample destination; a null destination is a
    // named refusal (counted + logged), not a skipped call, because a guest
    // resolve whose copy-dest was never bound means the colour ended up
    // nowhere and the next pass samples garbage.
    //
    // Everything BuildResolveDesc decides is honoured or refused:
    //   * !desc.valid                       -> refusal, desc.refusal logged
    //   * desc.isDepthResolve               -> refusal (needs its own path)
    //   * desc.hostDxgiFormat == 0          -> refusal, no host resolve form
    //   * desc.endianSwap || desc.swapRedBlue -> refusal; ResolveSubresource
    //     performs no swizzle or byte swap, so this would be a silently
    //     un-swizzled image
    //   * desc.clearSource                  -> refusal; D3D12 has no
    //     copy-and-clear on a colour target that is also a resolve source
    //   * desc.hostDxgiFormat != desc's actual destination format -> refusal
    bool ResolveGuestSurface(uint32_t xenosFormat, uint32_t width, uint32_t height,
                             uint32_t sampleSelect, bool endianSwap, bool swapRedBlue,
                             bool clearSource, uint32_t extentX, uint32_t extentY,
                             uint32_t copyDestPitch, uint32_t copyDestHeight,
                             uint32_t guestBaseAddress, ID3D12Resource* srcRt,
                             ID3D12Resource* dstTexture);
    static uint64_t ResolveRefusalCount();

    // Phase 4: Full render state objects (cached by descriptor)
    // Blend state
    const D3D12_BLEND_DESC* GetOrCreateBlendState(const D3D12_BLEND_DESC& desc);
    // Depth-stencil state
    const D3D12_DEPTH_STENCIL_DESC* GetOrCreateDepthStencilState(const D3D12_DEPTH_STENCIL_DESC& desc);
    // Rasterizer state
    const D3D12_RASTERIZER_DESC* GetOrCreateRasterizerState(const D3D12_RASTERIZER_DESC& desc);

    // Phase 4: Resource state tracking and automatic barrier insertion
    // Call before accessing a resource to ensure correct state transition.
    // Returns true if a barrier was emitted.
    bool TransitionResource(ID3D12Resource* resource,
                            D3D12_RESOURCE_STATES stateBefore,
                            D3D12_RESOURCE_STATES stateAfter,
                            UINT subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES);

    // Phase 4: Frame graph / render pass support
    // Begin a render pass: sets RTs/DSV, emits necessary barriers, clears if requested.
    // Passes an array of render target descriptors (format, clear color, load/store ops).
    struct RenderPassDesc {
        struct RTV {
            D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle;
            DXGI_FORMAT format;
            float clearColor[4] = {0, 0, 0, 0};
            bool clear = false;
            D3D12_RESOURCE_STATES initialState = D3D12_RESOURCE_STATE_RENDER_TARGET;
            D3D12_RESOURCE_STATES finalState = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
        };
        struct DSV {
            D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle;
            DXGI_FORMAT format;
            float depthClear = 1.0f;
            UINT8 stencilClear = 0;
            bool clearDepth = false;
            bool clearStencil = false;
            D3D12_RESOURCE_STATES initialState = D3D12_RESOURCE_STATE_DEPTH_WRITE;
            D3D12_RESOURCE_STATES finalState = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
        };
        std::vector<RTV> rtvs;
        std::optional<DSV> dsv;
        D3D12_VIEWPORT viewport = {};
        D3D12_RECT scissor = {};
    };
    bool BeginRenderPass(const RenderPassDesc& desc);
    void EndRenderPass();

    // Phase 7: Render Graph / Frame Graph Architecture
    // Declarative render graph builder for automatic barrier management and transient resource allocation.
    struct RenderGraphPass;
    class RenderGraphBuilder {
    public:
        // Opaque handle to a pass in the graph
        struct PassHandle { uint32_t index; };
        // Resource usage in a pass
        enum class ResourceUsage {
            Read,       // SRV
            Write,      // RTV/DSV/UAV
            ReadWrite   // UAV read+write
        };
        // Resource access info for a pass
        struct ResourceAccess {
            ID3D12Resource* resource = nullptr;
            ResourceUsage usage = ResourceUsage::Read;
            D3D12_RESOURCE_STATES beforeState = D3D12_RESOURCE_STATE_COMMON;
            D3D12_RESOURCE_STATES afterState = D3D12_RESOURCE_STATE_COMMON;
            UINT subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        };
        // Transient resource description for allocation
        struct TransientResourceDesc {
            std::wstring name;
            D3D12_RESOURCE_DESC desc;
            D3D12_CLEAR_VALUE clearValue = {};
        };

        RenderGraphBuilder() = default;
        explicit RenderGraphBuilder(D3D12Backend* backend) : m_backend(backend) {}

        // Add a pass to the graph. `execute` is called during graph execution.
        // `resources` lists all resources accessed by this pass with their usage and state transitions.
        // Returns a handle to the pass for later reference.
        PassHandle AddPass(std::wstring name,
                           std::vector<ResourceAccess> resources,
                           std::function<void(ID3D12GraphicsCommandList*)> execute);

        // Request a transient resource. The graph will allocate/recycle based on lifetime.
        ID3D12Resource* GetTransientResource(const TransientResourceDesc& desc);

        // Build the graph: validates dependencies, performs topological sort, allocates transients.
        bool Build();

        // Execute the built graph on the current command list.
        void Execute();

        // Clear the graph for the next frame.
        void Reset();

    private:
        D3D12Backend* m_backend = nullptr;
        friend class D3D12Backend;
    };

    // Create a RenderGraphBuilder for the current frame.
    RenderGraphBuilder CreateRenderGraph();

    void EndFrame();

    // Accessors
    ID3D12Device* GetDevice() const { return m_device.Get(); }
    ID3D12GraphicsCommandList* GetCommandList() const { return m_commandList.Get(); }
    ID3D12CommandQueue* GetCommandQueue() const { return m_commandQueue.Get(); }
    ID3D12CommandQueue* GetCopyQueue() const { return m_copyQueue.Get(); }
    ID3D12RootSignature* GetRootSignature() const { return m_rootSignature.Get(); }
    uint32_t GetCurrentFrameIndex() const { return m_frameIndex; }
    uint32_t GetWidth() const { return m_width; }
    uint32_t GetHeight() const { return m_height; }

    // Streaming upload via copy queue (P4.5′)
    // Uploads host data to a DEFAULT-heap resource using the copy queue.
    // The caller must ensure the resource is in COPY_DEST state before calling.
    bool StreamingUpload(ID3D12Resource* dest, const void* data, uint32_t size);
    // Signal a fence on the copy queue; returns the fence value.
    uint64_t SignalCopyFence();
    // Wait for the copy queue to reach a given fence value.
    void WaitForCopyFence(uint64_t fenceValue);

    // Wait for all GPU work to complete
    void WaitForGpu();

    // Wait until the GPU is done with the current back buffer's prior frame.
    // Must precede writes into this frame's upload arena region.
    bool WaitForCurrentFrameGpu();

    // F-650: the back-buffer arbiter. MayWriteBackBuffer is the ONLY sanctioned
    // way to decide that a writer may touch m_renderTargets[m_frameIndex], and
    // PresentOwnedFrame is the ONLY sanctioned way to call m_swapChain->Present.
    // Both take the writer's identity so a refusal can name the writer that lost
    // the frame instead of leaving the log to infer it.
    //
    // MayWriteBackBuffer returns false for a non-owner. A false return MUST mean
    // "write nothing": the callers below are arranged to bail before their first
    // byte reaches the back buffer, because a writer that clears, copies over
    // and then refuses has already destroyed the frame it was going to decline.
    bool MayWriteBackBuffer(FrameOwner owner);
    bool PresentOwnedFrame(FrameOwner owner);

// Phase 3 draw-path resources
    bool CreateUploadHeap();
    bool CreateTestRootSignature();
    bool CreateTestPipeline();
    uint8_t* MapUpload(size_t size, size_t alignment, D3D12_GPU_VIRTUAL_ADDRESS& gpu);

    // Per-frame upload arena lives in an upload heap and records into
    // vertex/index buffers. Grows once on Initialize. The arena is split into
    // kBufferCount regions, one per back buffer, so a frame only writes the
    // region whose completion is guaranteed by BeginFrame's fence wait.
    Microsoft::WRL::ComPtr<ID3D12Resource> m_uploadHeap;
    size_t m_uploadCapacity = 0;
    size_t m_uploadRegionSize = 0;
    size_t m_uploadOffset = 0;
    uint8_t* m_uploadMap = nullptr;

    Microsoft::WRL::ComPtr<ID3D12RootSignature> m_rootSignature;
    Microsoft::WRL::ComPtr<ID3D12PipelineState> m_testPipeline;

    // Phase 5: Mipmap generation compute pipeline
    Microsoft::WRL::ComPtr<ID3D12RootSignature> m_mipGenRootSignature;
    Microsoft::WRL::ComPtr<ID3D12PipelineState> m_mipGenPipeline;

    // Static index buffer for the deterministic triangle, uploaded once and
    // cached by ResourceCache so later frames do not re-upload it.
    bool CreateStaticIndexBuffer();
    Microsoft::WRL::ComPtr<ID3D12Resource> m_staticIndexBuffer;
    ResourceCache m_resourceCache;

    // Phase 4 texture resources (decoded host-linear pixels -> texture + SRV).
    // Shader-visible SRV heap layout matches the translator's HLSL contract:
    // slot 0 -> t0 (t1D), 1 -> t1 (t2D), 2 -> t2 (t3D), 3 -> t3 (tCube).
    static constexpr uint32_t kShaderTextureSlotCount = 4;
    static constexpr uint32_t kTexture2DSlot = 1;
    // F-639: DrawPacket carries textureDescriptors[16] and the heap must have a
    // slot for each of them at kTexture2DSlot + i, so the heap is 17 deep. The
    // ROOT SIGNATURE still binds only the first kShaderTextureSlotCount
    // descriptors (t0..t3): the translator's HLSL cannot sample t4, and the
    // pipeline worker refuses (kRefuseOverTextureSlots) any reflected register
    // outside that table, so a descriptor at index >= 4 is uploaded and counted
    // but cannot be sampled until the table grows. Growing the heap alone would
    // NOT make t4 reachable, and pretending otherwise is the substitution this
    // charter forbids.
    static constexpr uint32_t kMaxGuestTextureDescriptors = 16;
    static constexpr uint32_t kSrvHeapDescriptorCount =
        kTexture2DSlot + kMaxGuestTextureDescriptors;
    // Xenos float-constant bank size bound at root CBV b0.
    static constexpr uint32_t kShaderConstantBytes = 256 * 16;
    bool CreateSrvHeap();
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_srvHeap;
    uint32_t m_srvDescriptorSize = 0;
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_samplerHeap;
    uint32_t m_samplerDescriptorSize = 0;
    uint32_t m_samplerHeapOffset = 0;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_decodedTexture;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_decodedTextureUpload;
    D3D12_GPU_DESCRIPTOR_HANDLE m_decodedTextureSrvGpu = {};
    HRESULT m_lastPresentHr = S_OK;

    // F-639: content-addressed texture residency. handle in TextureCacheEntry
    // is (pool index + 1) so 0 can mean "no resource"; m_texturePoolSlots keeps
    // stable ComPtrs alive and the by-handle vector makes the draw-path
    // handle -> ID3D12Resource lookup a plain index, not a hash. A slot is only
    // released when the TextureCache evicts the entry, so a texture the GPU may
    // still be reading outlives the frame it was bound in.
    struct ResidentTexture {
        Microsoft::WRL::ComPtr<ID3D12Resource> texture;
        Microsoft::WRL::ComPtr<ID3D12Resource> upload;  // outlives the copy
        uint32_t width = 0, height = 0, mipLevels = 1;
        uint32_t xenosFormat = 0, importDxgiFormat = 0;
    };
    std::vector<ResidentTexture> m_texturePoolSlots;
    std::vector<ResidentTexture*> m_texturePoolByHandle;  // [handle-1]
    std::vector<uint32_t> m_texturePoolFree;
    TextureCache m_textureCache;
    // F-639: scratch for ExpandTextureToImportBytes, kept across calls so the
    // draw path does not allocate per texture. Reserved once at first use.
    std::vector<uint8_t> m_importScratch;
    // F-639: guest samplers interned by HostSamplerDesc::hash -> heap index,
    // so DecodeGuestSamplerState's result is a hash lookup and not a
    // D3D12_SAMPLER_DESC construction plus a linear scan.
    std::unordered_map<uint64_t, uint32_t> m_guestSamplerIndex;
    D3D12_GPU_DESCRIPTOR_HANDLE m_samplerTableGpu = {};
    // F-637: draws whose index/vertex offsets were non-zero. Bounded log: this
    // used to be hardcoded 0,0 with no counter at all, so "the capture's base
    // vertex is never non-zero" was an assumption, not a measurement.
    uint32_t m_offsetDraws = 0;
    uint32_t m_primTypeRefusals = 0;
    // F-650: draws refused because desc.topology was still D3D12_PRIMITIVE_
    // TOPOLOGY_UNDEFINED, i.e. the PRODUCER never set a topology at all. It was
    // sharing the patchlist bucket, which reports a different fault in a
    // different file (a real patchlist draw against a PSO with no tessellation
    // domain) and so read as a tessellation problem when the measured reality is
    // that nothing assigns the field. Its own row is the only way a soak can
    // tell those two apart.
    uint32_t m_topologyUnsetRefusals = 0;
    // F-650: draws refused because the vertex stride did not match the TEST
    // PSO's hardcoded POSITION float3 + COLOR float4 = 28-byte layout. It was
    // logging UNBOUNDED and uncounted (build/w662.log: 4,940 lines, which is
    // the only reason the number is known at all), so this counter plus the
    // house-pattern bound is the fix; the stride MISMATCH itself is not fixed
    // here and cannot be -- see the note at the refusal site.
    uint32_t m_testLayoutStrideRefusals = 0;
    // ---- F-653: the two bypasses, counted --------------------------------
    // m_noPipelineBypassRefusals: draws that reached DrawDynamicMesh with no
    //   pipeline of their own. That entry no longer resolves to the test PSO, so
    //   every one of these is a refusal. The counter is the measure of the
    //   bypass's removal AND of the follow-up still owed by render_thread.cpp
    //   (:937, :2042, :2099) -- it should trend to zero once those sites pass a
    //   real PSO, and while it is non-zero those draws are NOT being drawn.
    // m_nullPipelineRefusals: the same condition reaching
    //   DrawDynamicMeshWithPipeline directly. Kept as a separate counter, not
    //   folded into the one above, because the two entry points have different
    //   callers and a soak needs to tell which door is still being used.
    // m_cachePipelineDraws: draws actually issued through a cache-produced PSO.
    uint64_t m_noPipelineBypassRefusals = 0;
    uint64_t m_nullPipelineRefusals = 0;
    uint64_t m_cachePipelineDraws = 0;
    // ---- the SILENT draw returns, named (2026-10-02) --------------------
    // m_silentDrawReturns: DrawDynamicMeshWithPipeline had three `return
    // false` paths that wrote NO log line at all -- not the device, not the
    // vertex-data gate at d3d12_backend.cpp:2705, not the index gate at
    // :2760. A draw dropped by any of them is therefore indistinguishable
    // from a draw that was never attempted. MEASURED on build/w696.log
    // (sha256 3D21DE0E..7F1893, 55,669 lines), which is the whole reason
    // this counter exists: that log carries `DRAW-CP-DRAWN #1` and `#2` and
    // `FRAME-OWNER owner=draw` ZERO times, and `D3D12Backend: draw #N
    // issued through a cache-produced PSO` zero times, so the two rows that
    // LOOK like a closed draw chain are not evidence that anything was
    // issued. Every one of these three gates now reports.
    uint64_t m_silentDrawReturns = 0;
    // 2026-10-02: the BeginFrame gate census. `m_beginFrameBegins` counts the
    // SUCCESSES on purpose: a refusal row that prints "refused 3" without
    // printing "began 0" cannot distinguish "one frame in three was refused"
    // from "the frame context never opened at all", and those are opposite
    // faults with opposite fixes. `m_beginFrameRefusalByGate` is indexed by
    // BeginFrameGate so each of the five exits is countable on its own; a
    // kFenceGate entry that is non-zero would mean m_initialized went false
    // between :3360 and :3349, which the recursive mutex currently forbids.
    uint64_t m_beginFrameBegins = 0;
    uint64_t m_beginFrameRefusals = 0;
    uint64_t m_beginFrameRefusalByGate[static_cast<uint32_t>(BeginFrameGate::kCount)] = {};
    // m_framesAbandoned: frames released by AbandonFrame instead of by a
    // present. Non-zero is not a fault by itself -- it is the count of frames
    // that were BEGUN AND THEN DROPPED, which is a fault, and this is the
    // number that says how many.
    uint64_t m_framesAbandoned = 0;
    // m_frameAbandonCloseFailures: abandonments whose ID3D12GraphicsCommandList::
    // Close() failed. Zero in every healthy run -- the latch is still released
    // when this is non-zero, so a non-zero value predicts a subsequent
    // BeginFrame refusal on a DIFFERENT gate, and this counter is what says the
    // refusal was caused here rather than by the GPU.
    uint64_t m_frameAbandonCloseFailures = 0;
    // m_psoBoundDraws: draws that reached SetPipelineState with a non-null
    // cache-produced PSO. Backs the `PC-PSO-BOUND` row, which exists because
    // the PSO's real creation is on renderer/pipeline_cache.cpp:1972 (not this
    // stream's file) and that site has no success row -- so on build/w696.log
    // every "CreateGraphicsPipelineState" hit is DXC-OUTPUTS prose and no line
    // anywhere states that a PSO exists.
    uint64_t m_psoBoundDraws = 0;
    // 2026-10-04: the two new draw-path observation rows' row counters.
    // Both increment UNCONDITIONALLY on every pass through their block and gate
    // only the TEXT through ShouldLogRefusal, per the F-649 rule quoted at
    // d3d12_backend.cpp:2853-2858 -- a suppressed row that is not counted is how
    // a soak reads "nothing happened" out of something that happened many times.
    //
    // m_vsInputStreamRows backs VS-INPUT-STREAM: the complete byte image of the
    // vertex stream the draw binds, EVERY vertex and EVERY dword. It exists
    // because the row above it reports four lanes of vertex 0 and calls itself
    // clip space, and a 3-vertex rectangle is not determined by vertex 0.
    uint64_t m_vsInputStreamRows = 0;
    // m_commandListBoundRows backs DRAW-COMMANDLIST-BOUND: the post-DrawInstanced
    // command-list state this file itself sets (viewport, scissor, topology,
    // vertex/index buffer views, bound render-target format) plus the pipeline
    // cache's own geometry-stage totals, read from m_pipelineCache -- the SAME
    // member render_thread.cpp:3742 calls GetOrCompile on, so the counters are
    // about the PSO actually bound here.
    uint64_t m_commandListBoundRows = 0;
    // m_boundRtvFormat: the DXGI format of the render target actually bound
    // by the draw path, read back from the bound resource's own D3D12
    //_RESOURCE_DESC (never assumed from the swapchain description). It is
    // half of the one comparison nobody could make before: the PSO declares
    // RTVFormats[] from the GUEST's RB_COLOR_INFO (render_thread.cpp:3031
    // -> renderer/pipeline_cache.cpp:1921-1945) while the bound RTV is the
    // swapchain back buffer created with pDesc = nullptr
    // (d3d12_backend.cpp:763), i.e. DXGI_FORMAT_R8G8B8A8_UNORM
    // (:711). A guest colour_format of 2..15 maps to a DIFFERENT DXGI
    // format (render_thread.cpp:456-501), and a PSO whose RTVFormats[0]
    // disagrees with the bound RTV rasterizes nothing without an error.
    // 0 = not yet bound.
    uint32_t m_boundRtvFormat = 0;
    // m_rtvFormatRows: how many times D3D12-RTV-FORMAT has been CONSIDERED.
    // The row used to be latched on `m_boundRtvFormat == 0` and so printed at
    // most once per process -- which is unreachable in practice, because the
    // site is downstream of BeginFrame() and a closed gate never reaches it.
    uint32_t m_rtvFormatRows = 0;
    // F-653: the feature level the device REPORTS, measured once at device
    // creation with ID3D12Device::GetFeatureLevel(). The 11_0 that
    // CreateDevice is asked for is a request; this is the answer, and the
    // difference is what a rectangle draw depends on. A geometry stage requires
    // 11_0, so m_geometryStageSupported false means every rectangle draw refuses
    // with `geom-stage-unsupported-at-this-feature-level` rather than rendering
    // black.
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_10_0;
    bool m_geometryStageSupported = false;
    uint32_t m_textureBindPasses = 0;
    // F-641: times a caller passed a `stateBefore` to TransitionResource that
    // disagreed with the tracked state of that subresource. Non-zero means some
    // call site is asserting a prior state it has not measured -- the exact bug
    // the mipgen loop had.
    uint32_t m_trackedStateDisagreements = 0;
    // F-639: frame serial handed to TextureCache::NotifySubmitted at EndFrame.
    uint64_t m_frameSerial = 0;

    // W6 PresentBgra path: persistent blit texture + upload staging.
    // Texture state after a successful blit is COPY_SOURCE; next blit
    // transitions it back to COPY_DEST before CopyTextureRegion.
    bool EnsureFbTexture(uint32_t width, uint32_t height);
    Microsoft::WRL::ComPtr<ID3D12Resource> m_fbTexture;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_fbUpload;
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT m_fbFootprint = {};
    uint32_t m_fbTexW = 0;
    uint32_t m_fbTexH = 0;
    D3D12_RESOURCE_STATES m_fbTexState = D3D12_RESOURCE_STATE_COPY_DEST;
    std::vector<uint8_t> m_fbHost;

    // ---------------------------------------------------------------------
    // F-XXX: THE GUEST'S RENDER TARGET ("EDRAM") AND THE RESOLVE INTO THE
    // SCANOUT SURFACE.
    //
    // WHAT THE CONSOLE DOES, IN THE GUEST'S OWN WORDS (citations in
    // src/gpu_cp.h, which carries the PE-image bytes):
    //   * the guest renders into EDRAM, whose geometry the guest states in
    //     RB_SURFACE_INFO (surface_pitch in pixels) and whose mode it states
    //     in RB_MODECONTROL (xenos::EdramMode);
    //   * the guest then copies EDRAM out with the RB copy unit:
    //     RB_COPY_CONTROL / RB_COPY_DEST_BASE / RB_COPY_DEST_PITCH /
    //     RB_COPY_DEST_INFO, and the copy itself is a DRAW with
    //     RB_MODECONTROL.edram_mode = kCopy (xenos.h:911-915 states the rule
    //     in words: "Xenos copies EDRAM contents to a tiled 2D or 3D texture
    //     (resolves) by drawing primitives with the EDRAM mode
    //     EdramMode::kCopy");
    //   * the display then scans that surface out.
    //
    // WHAT THIS HOST HAD: NO EDRAM target and NO RB_COPY consumer
    // (build/agents/audit_gpu.md row 1), and ResolveGuestSurface
    // (src/d3d12_backend.cpp:6295) with no call site at all. The guest's
    // draws went straight into the swap-chain back buffer, so the guest's
    // render target and the scan-out surface were the SAME object and the
    // console's copy step did not exist.
    //
    // WHAT THIS IS: the missing object and the missing step, in the smallest
    // form that can be built and falsified.
    //   * m_guestRt is the guest's render target, sized and formatted from the
    //     guest's OWN registers (RB_SURFACE_INFO's pitch, the screen scissor's
    //     height, the colour format the guest's RB_COLOR_INFO mapped to).
    //   * the guest's draws go into m_guestRt.
    //   * ResolveGuestRenderTarget copies m_guestRt into the scan-out surface
    //     (the swap-chain back buffer) -- the console's EDRAM -> scanout
    //     resolve, in the host's terms.
    //
    // THE FALLBACK IS NOT OPTIONAL. If the guest's render target does not
    // match the scan-out surface 1:1, the resolve cannot be a copy, so the
    // guest's draws go into the back buffer exactly as they did before this
    // existed and the refusal is counted and named.
    // ---------------------------------------------------------------------
    bool EnsureGuestRenderTarget(uint32_t width, uint32_t height,
                                 DXGI_FORMAT format);
    // The console's EDRAM -> scanout resolve. Returns false when there is
    // nothing to resolve (no guest render target, or nothing drawn into it
    // since the last resolve).
    bool ResolveGuestRenderTarget();
    // Named, counted refusal of the guest render target, so "the guest's
    // render target was not used" is a number and not an absence.
    //
    // `hr` is the D3D12 HRESULT when the refusal came from a D3D12 call, and
    // 0xFFFFFFFF when it did not (no call was made). F-XXX: the row used to
    // print the reason alone, so "create-failed" named the outcome and not
    // the cause -- the same silence the row exists to end.
    void GuestRenderTargetRefused(const char* why, uint32_t hr = 0xFFFFFFFFu);
    Microsoft::WRL::ComPtr<ID3D12Resource> m_guestRt;
    // A replaced guest render target is kept here until the GPU has caught up
    // with the fence, because a texture the GPU may still be reading must not
    // be released under it. The size can only change on a window resize (the
    // resolve requires the guest's render target to be 1:1 with the scan-out
    // surface), so this list stays empty in practice.
    std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> m_guestRtRetired;
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_guestRtvHeap;
    D3D12_CPU_DESCRIPTOR_HANDLE m_guestRtv = {};
    uint32_t m_guestRtW = 0;
    uint32_t m_guestRtH = 0;
    DXGI_FORMAT m_guestRtFormat = DXGI_FORMAT_UNKNOWN;
    bool m_guestRtValid = false;
    // The guest render target's tracked D3D12 state. It starts COMMON and is
    // RENDER_TARGET between draws; the readback and the resolve each take it
    // to COPY_SOURCE and back. Asserting a state the resource is not in is
    // the F-725 hazard this file already documents at :4130-4142, so the
    // state is TRACKED here rather than assumed.
    D3D12_RESOURCE_STATES m_guestRtState = D3D12_RESOURCE_STATE_COMMON;
    // True once the guest has drawn into m_guestRt since the last resolve.
    bool m_guestRtDrawn = false;
    // True while the draw path is rendering into m_guestRt rather than into
    // the back buffer. The back buffer's ledger (NoteBufferWrite) describes
    // the BACK BUFFER, so while the draws land in the guest render target
    // they must not be counted as writes to it; the resolve is the write.
    bool m_drawsIntoGuestRt = false;
    // F-XXX: the number of NON-MODAL pixels the last post-draw readback
    // measured in the GUEST RENDER TARGET (the same count the D3D12-DRAW-PIXEL
    // row prints as changedPx). The resolve's row carries it, because "the
    // copy ran" and "the thing that was copied was not blank" are two
    // different facts and only this one is the second.
    //
    // IT LAGS THE RESOLVE BY ONE FRAME on purpose, not by accident: the
    // readback's copy is executed by the present, and the buffer can only be
    // mapped after that present returns (F-725's fence arithmetic, .cpp
    // :4529 and the wait below it), so the measurement of frame N is available
    // after the resolve of frame N. The value is a MEMBER and is not cleared,
    // so once the guest has drawn something the number stays.
    uint64_t m_guestRtChangedPx = 0;
    uint64_t m_guestRtResolves = 0;
    uint64_t m_guestRtRefusals = 0;
    uint64_t m_guestRtCreated = 0;

    // ---------------------------------------------------------------------
    // F-725: the post-draw readback (see ReportDrawReadback in the .cpp for the
    // measurement and for the four dead ends it supersedes).
    //
    // m_readbackDisabled is a ONE-WAY latch: once the READBACK heap buffer has
    // failed to be created the path never retries, because a retry per draw is
    // exactly the per-frame cost this feature was created to remove. It is
    // separate from the attempt bound below, which is about doing the readback
    // too OFTEN rather than failing.
    // ---------------------------------------------------------------------
    static constexpr uint64_t kDrawReadbackMaxReadbacks = 4;
    bool EnsureDrawReadback();
    bool RecordDrawReadback();
    void ReportDrawReadback();
    Microsoft::WRL::ComPtr<ID3D12Resource> m_readbackBuffer;
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT m_readbackFootprint = {};
    UINT64 m_readbackRowPitch = 0;
    uint32_t m_readbackW = 0;
    uint32_t m_readbackH = 0;
    bool m_readbackDisabled = false;
    bool m_readbackExhaustedLogged = false;
    uint64_t m_drawReadbackAttempts = 0;
    uint64_t m_drawReadbackCreates = 0;
    uint64_t m_drawReadbackCompletions = 0;
    uint64_t m_drawReadbackCreateFailures = 0;
    uint64_t m_drawReadbackMapFailures = 0;

    // ---------------------------------------------------------------------
    // F-761: THE LATE-FRAME READBACK -- a sample of a frame that carries NO
    // draw, which is the frame the window is actually showing.
    //
    // WHY IT EXISTS. The readback above is reachable only from the draw path, so
    // a run in which the guest issues two draws in 150 seconds produces two
    // pixel samples and both of them describe t = the second draw. MEASURED in
    // build/w716.log (7,738,233 B): the draw-path sample rows are at
    // 17:08:05.582 and 17:08:05.604, and the last present of the run is at
    // 17:10:20.932 -- 135.3 s later, presented=4400. Every pixel fact anyone
    // read out of that run therefore describes a frame that had been off the
    // screen for more than two minutes, and the bound on the sample count
    // (kDrawReadbackMaxReadbacks) was never the reason: with only two draws in
    // the whole run the draw-path bound of 4 was never reached.
    //
    // It shares the readback heap buffer and the fence discipline above, and it
    // is bounded by its own compile-time constant for the same reason: a runtime
    // knob is one more thing that can differ between two logs being compared.
    // A present is EITHER a draw present OR a late present, never both, so the
    // two paths cannot both hold the shared buffer at once.
    // ---------------------------------------------------------------------
    static constexpr uint64_t kLateFrameReadbackMaxReadbacks = 4;
    bool RecordLateFrameReadback();
    void ReportLateFrameReadback();
    uint64_t m_lateFrameReadbackAttempts = 0;
    uint64_t m_lateFrameReadbackCompletions = 0;
    uint64_t m_lateFrameReadbackMapFailures = 0;
    bool m_lateFrameExhaustedLogged = false;
    // Presents refused because the buffer the swap chain had rotated onto had
    // never been written by anything. See RefuseUnwrittenPresent in the .cpp.
    uint64_t m_unwrittenPresentRefused = 0;
    // Beats that showed nothing new and were therefore NOT shown. See
    // RefuseUnchangedPresent in the .cpp. This is deliberately NOT folded into
    // m_presentedFrames: presented= is the count of flips issued, and a
    // suppressed beat issues none, so the two counters have to stay separate for
    // "the guest stopped drawing" to be readable as a difference.
    uint64_t m_heldBeatsNotShown = 0;

    // The last completed sample. Written only by ReportDrawReadback, under
    // m_mutex, and read only through the accessors above.
    bool m_lastPixelValid = false;
    uint32_t m_lastPixelX = 0;
    uint32_t m_lastPixelY = 0;
    uint8_t m_lastPixelR = 0;
    uint8_t m_lastPixelG = 0;
    uint8_t m_lastPixelB = 0;
    uint8_t m_lastPixelA = 0;
    uint64_t m_lastPixelNonBlack = 0;
    uint64_t m_lastPixelTotal = 0;
    uint64_t m_lastPixelMaxChannel = 0;
    double m_lastPixelMeanChannel = 0.0;
    uint32_t m_lastPixelRowPitch = 0;

DrawStats m_stats;

    // Phase 6: Dynamic sampler descriptor heap
    static constexpr uint32_t kSamplerHeapSize = 2048;
    // SamplerCacheKey and hash must be defined before the map that uses them
    struct SamplerCacheKey {
        D3D12_SAMPLER_DESC desc;
        bool operator==(const SamplerCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_SAMPLER_DESC)) == 0;
        }
    };
    struct SamplerCacheKeyHash {
        size_t operator()(const SamplerCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_SAMPLER_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
std::unordered_map<SamplerCacheKey, D3D12_SAMPLER_DESC, SamplerCacheKeyHash> m_samplerCache;
    std::vector<D3D12_STATIC_SAMPLER_DESC> m_staticSamplerArray;  // for root signature
    std::unordered_map<SamplerCacheKey, uint32_t, SamplerCacheKeyHash> m_samplerDescriptorIndex;  // desc -> heap index

    // Phase 4: Cached state objects
    // Samplers in D3D12 are either static (root signature) or descriptor heap entries.
    // We cache the descriptor descriptors for reuse.

    // For Blend/DepthStencil/Rasterizer states, D3D12 bakes them into PSOs.
    // We cache the descriptors for reuse when creating PSOs.
    struct BlendStateCacheKey {
        D3D12_BLEND_DESC desc;
        bool operator==(const BlendStateCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_BLEND_DESC)) == 0;
        }
    };
    struct BlendStateCacheKeyHash {
        size_t operator()(const BlendStateCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_BLEND_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
    std::unordered_map<BlendStateCacheKey, D3D12_BLEND_DESC, BlendStateCacheKeyHash> m_blendStateCache;

    struct DepthStencilStateCacheKey {
        D3D12_DEPTH_STENCIL_DESC desc;
        bool operator==(const DepthStencilStateCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_DEPTH_STENCIL_DESC)) == 0;
        }
    };
    struct DepthStencilStateCacheKeyHash {
        size_t operator()(const DepthStencilStateCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_DEPTH_STENCIL_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
    std::unordered_map<DepthStencilStateCacheKey, D3D12_DEPTH_STENCIL_DESC, DepthStencilStateCacheKeyHash> m_depthStencilStateCache;

    struct RasterizerStateCacheKey {
        D3D12_RASTERIZER_DESC desc;
        bool operator==(const RasterizerStateCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_RASTERIZER_DESC)) == 0;
        }
    };
    struct RasterizerStateCacheKeyHash {
        size_t operator()(const RasterizerStateCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_RASTERIZER_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
    std::unordered_map<RasterizerStateCacheKey, D3D12_RASTERIZER_DESC, RasterizerStateCacheKeyHash> m_rasterizerStateCache;

    // Resource state tracking for automatic barrier insertion.
    //
    // F-641: this used to be ONE state per resource plus ONE subresource index,
    // which cannot describe a mip chain: after uploading mip 0 and transitioning
    // it to PIXEL_SHADER_RESOURCE, the tracker had no way to say mip 1 was
    // still COPY_DEST, so the mipgen loop emitted COMMON->UNORDERED_ACCESS for
    // mip 1 and COMMON->NON_PIXEL_SHADER_RESOURCE for mip 0 with a barrier on
    // the wrong subresource -- the exact class of bug D3D12's debug layer
    // exists to catch. `perMip` now holds one state per mip/slice; index 0 is
    // the whole-resource state and is what a caller that transitions
    // D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES writes.
    struct ResourceStateEntry {
        D3D12_RESOURCE_STATES whole = D3D12_RESOURCE_STATE_COMMON;
        std::vector<D3D12_RESOURCE_STATES> perMip;  // index == mip/slice
        bool hasWhole = false;
    };
    std::unordered_map<ID3D12Resource*, ResourceStateEntry> m_resourceStates;

    // F-641: the tracked state of one subresource, or COMMON when the resource
    // has never been transitioned. Used by the resolve path so the barrier it
    // emits states the resource's REAL prior state instead of asserting
    // RENDER_TARGET/COMMON.
    D3D12_RESOURCE_STATES TrackedState(ID3D12Resource* resource, UINT subresource) const;
    // F-641: record a state WITHOUT emitting a barrier. For the resolve path,
    // which builds its own barrier batch and so must tell the tracker what it
    // actually did.
    void SetTrackedState(ID3D12Resource* resource, UINT subresource,
                         D3D12_RESOURCE_STATES state);

    // F-639: resident-texture pool. Acquire returns (index + 1), 0 on failure;
    // Release(0) and an out-of-range handle are no-ops. A slot's ComPtrs are
    // dropped only by Release, i.e. only when the TextureCache evicts the entry
    // -- so a texture the GPU may still be reading outlives the frame it was
    // bound in. This is the only place that frees a resident texture.
    uint32_t AcquireTexturePoolSlot();
    void ReleaseTexturePoolSlot(uint64_t handle);

    // Current render pass state
    std::optional<RenderPassDesc> m_activeRenderPass;

    // Phase 7: Render Graph state
    struct RenderGraphPass {
        std::wstring name;
        std::vector<RenderGraphBuilder::ResourceAccess> resources;
        std::function<void(ID3D12GraphicsCommandList*)> execute;
        std::vector<uint32_t> dependencies;  // indices of passes this depends on
        std::vector<uint32_t> dependents;    // indices of passes that depend on this
    };
    struct TransientResourceEntry {
        std::wstring name;
        D3D12_RESOURCE_DESC desc;
        D3D12_CLEAR_VALUE clearValue;
        Microsoft::WRL::ComPtr<ID3D12Resource> resource;
        uint64_t lastUsedFrame = 0;
        bool inUse = false;
    };
    std::vector<RenderGraphPass> m_renderGraphPasses;
    std::vector<TransientResourceEntry> m_transientResources;
    std::vector<uint32_t> m_renderGraphExecutionOrder;
    bool m_renderGraphBuilt = false;

private:
    bool CreateDevice();
    bool CreateSwapChain(HWND hwnd, uint32_t width, uint32_t height);
    bool CreateRenderTargets();
    bool CreateCommandObjects();
    bool CreateCopyQueue();
    bool CreateSyncObjects();

    bool m_initialized = false;
    HWND m_hwnd = nullptr;
    uint32_t m_width = 1280;
    uint32_t m_height = 720;

    Microsoft::WRL::ComPtr<IDXGIFactory4> m_factory;
    Microsoft::WRL::ComPtr<ID3D12Device> m_device;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_commandQueue;
    Microsoft::WRL::ComPtr<IDXGISwapChain3> m_swapChain;

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    uint32_t m_rtvDescriptorSize = 0;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_renderTargets[kBufferCount];

    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_commandAllocators[kBufferCount];
    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_commandList;

    // Copy queue for streaming uploads (P4.5′)
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_copyQueue;
    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_copyAllocator;
    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_copyCommandList;
    Microsoft::WRL::ComPtr<ID3D12Fence> m_copyFence;
    HANDLE m_copyFenceEvent = nullptr;
    uint64_t m_copyFenceValue = 0;

    // CPU-GPU sync
    Microsoft::WRL::ComPtr<ID3D12Fence> m_fence;
    HANDLE m_fenceEvent = nullptr;
    uint64_t m_fenceValues[kBufferCount] = {};
    uint64_t m_currentFenceValue = 0;
    uint32_t m_frameIndex = 0;
    // F-633: draws whose root constant bank carried the game's real constants vs a
    // zero fill. Kept as a plain counter (draw submission is already serialised on
    // the render thread) purely to bound the CONST-BANK log.
    uint32_t m_constBankDraws = 0;

    // ---------------------------------------------------------------------
    // F-650: back-buffer frame ownership state. All of it is written only from
    // inside MayWriteBackBuffer / PresentOwnedFrame, which run under m_mutex, so
    // plain members are correct here and cost nothing on the present path (no
    // allocation, no atomics beyond the one relaxed read DrawPathOwnsBackBuffer
    // exposes to the render thread's diagnostics).
    // ---------------------------------------------------------------------
    // True once the draw path has presented a frame. From that point the blit
    // and the clear are refused for the rest of the session. One-way by
    // design, exactly like render_thread.cpp's s_guestContentSeen (F-610): a
    // back buffer that alternates owners is a flickering frame, and "the draw
    // path stopped" is not a reason to start overwriting real draws.
    bool m_drawPathTookBackBuffer = false;
    // Who wrote the back buffer since the last present. Reset by
    // PresentOwnedFrame. A second, different writer in the same window is the
    // last-writer-wins defect the arbiter exists to make impossible; the counter
    // proves it stayed impossible.
    FrameOwner m_frameWriter = FrameOwner::None;
    uint64_t m_presentedFrames = 0;
    uint64_t m_drawOwnedFrames = 0;
    uint64_t m_blitRefused = 0;
    uint64_t m_clearRefused = 0;
    uint64_t m_ownerConflicts = 0;

    // ---------------------------------------------------------------------
    // F-761: THE PER-BUFFER WRITE LEDGER. "Which writer owned the back buffer"
    // above is a per-PRESENT question and m_frameWriter answers it for the one
    // buffer that was current. It cannot answer "has buffer 2 EVER been written",
    // because PresentOwnedFrame advances m_frameIndex to
    // m_swapChain->GetCurrentBackBufferIndex() on every present and the previous
    // frame's ownership is gone by the time anyone asks. With kBufferCount = 3
    // (:34) and a flip-model chain that rotates, that is the difference between
    // "the window shows garbage" and "the window shows a buffer nothing ever
    // wrote to", and only one of those is a defect in this file.
    //
    // everWritten is a uint64_t rather than a bool so that one printf serves it
    // and so that a struct reset cannot leave a stale bit pattern behind.
    // ---------------------------------------------------------------------
    struct BufferLedger {
        uint64_t everWritten = 0;  // 1 once anything has written this resource
        uint64_t presents = 0;     // times this index was the presented buffer
        uint64_t clears = 0;       // ClearRenderTargetView recorded against it
        uint64_t draws = 0;        // draw calls recorded against it
        uint64_t blits = 0;        // CopyResource recorded into it
        // ------------------------------------------------------------------
        // F-763: THE CONTENT VERSION, WHICH IS WHAT "NEW CONTENT" MEANS.
        //
        // WHY THE FIVE COUNTS ABOVE CANNOT ANSWER IT. They are all cumulative
        // and none of them is paired with WHICH state of the resource a given
        // flip showed. So "this buffer holds the guest's draw" and "this buffer
        // holds the guest's draw that the window is already showing" are the
        // same answer to every one of them, and a present cannot tell them
        // apart. MEASURED in build/w718.log, 150 s soak, 4,400 flips:
        //   LATE-FRAME-PIXEL #1 buffer=1 writes=119 clears=119 draws=0
        //   LATE-FRAME-PIXEL #2 buffer=2 writes=120 clears=119 draws=1
        //   LATE-FRAME-PIXEL #3 buffer=0 writes=121 clears=120 draws=1
        // and the four rows' PIXELS disagree with those counts: #1 is a uniform
        // (15,25,56) navy, #2 carries the guest's 640x360 rectangle, #3 is a
        // uniform (0,0,0) with alpha 0. Three surfaces, alternating, on a window
        // whose guest has issued two draws. The alternation is the flash.
        //
        // WHAT IS ADDED, AND IT IS TWO COUNTERS, NOT A FLAG. contentSeq is a
        // monotonic version of this resource's CONTENTS: NoteBufferWrite bumps
        // it once per write, and those are the only four write sites
        // ("draw-path-clear", "draw", "blit", "clear" -- measured by grep, and
        // every other m_renderTargets[m_frameIndex] use in the file is a copy
        // OUT for a readback, a GetDesc, a barrier or a Reset). contentShown is
        // the value contentSeq held when this index was last flipped. Equal
        // values therefore mean one thing and one thing only: the bytes now in
        // this resource are the bytes this index last handed the compositor.
        //
        // WHY IT IS NOT A BOOL. A bool cannot be cleared at the right moment.
        // The moment is "this exact resource, at this exact write", and a
        // per-index counter is the smallest structure that survives a
        // ResetBufferLedger with nothing left over -- the reset zeroes both
        // halves, so a new resource starts at 0 == 0 and its FIRST write moves
        // it to 1 != 0 without any special case.
        // ------------------------------------------------------------------
        uint64_t contentSeq = 0;    // bumped once per write to this resource
        uint64_t contentShown = 0;  // contentSeq at this index's last flip
        // True when this resource has been written since this index last showed
        // it, i.e. when flipping it would change what the window displays.
        bool contentIsNew() const { return contentSeq != contentShown; }
        uint64_t writes() const { return clears + draws + blits; }
    };
    BufferLedger m_ledger[kBufferCount];
    // Called from CreateSwapChain and from Resize after ResizeBuffers, because
    // both hand back NEW resources whose contents are not the old contents.
    void ResetBufferLedger(const char* why);
    // Records one write against m_frameIndex. `how` is the site label that goes
    // in the log when this is the reason a buffer is still unwritten.
    void NoteBufferWrite(const char* how);
    // Refuses, by name, a present of a buffer nothing has written.
    bool RefuseUnwrittenPresent(const char* ownerName);
    // F-763: refuses, by name, a present of a buffer whose content version is
    // exactly the one that buffer last showed -- the empty-beat flip. Returns
    // true when the frame must be HELD (caller abandons it), false when the
    // buffer holds something the window has not seen and the flip goes ahead.
    bool RefuseUnchangedPresent(const char* ownerName);

    bool m_inFrame = false;
    std::recursive_mutex m_mutex;

    // Phase 5 pipeline cache for live shader compilation
    renderer::PipelineCache m_pipelineCache;
};

// ===========================================================================
// F-762: THE WHOLE-SURFACE COHERENCE GATE ON THE GUEST-MEMORY BLIT.
//
// THE MEASUREMENT THAT CREATED IT. build/w717.log, 150 s soak, 4400 steps
// through the chain, two of which carried a guest surface VA. At 18:23:55.785
// and 18:23:55.788 the guest offered va=B96EF2C0 and then va=B96EF2C4; both
// were read as 1280x720 (3,686,400 bytes) and both were uploaded, and the
// near-black flag printed rgb=(0.000,0.000,0.000) for each. (The marker names
// are deliberately NOT written here: they are tracked tokens, quoting them
// would put a tracked name into new text, and the numbers plus the timestamps
// above are what the argument rests on.)
//
// And, for the buffer the window was actually showing, same log, at
// 18:23:56.319:
//   buffer=2 draws=0 blits=1 nonBlack=1087/921600 maxChannel=255 sum=464299
//   distinctRgba=260 topRgba=(0,0,0,0)x920510 (0,0,255,255)x508
//   (255,255,255,255)x71 (1,0,0,0)x24 (245,245,245,245)x21 (95,95,95,95)x17
//   (85,85,85,85)x16 (215,215,255,245)x10 modalCount=920510 changedPx=1090
//   changedBox=x0..1279 y0..7
//
// So the sampler said "near black" and the pixel census of the very bytes the
// sampler read says 260 different colours with a maximum channel of 255. The
// two describe the same 3,686,400 bytes and disagree, so the sampler is the
// defect. WHY IT CANNOT AGREE, ARITHMETICALLY. The sampler is a 16x16 grid
// (render_thread.cpp:1588, sampleCount = 16*16 = 256), so its points sit at
// x = x*(1280/16) and y = y*(720/16), i.e. rows 0, 45, 90 ... 675. The noise
// band measured above is rows 0..7, so exactly ONE sampled row (y=0) touches it,
// carrying 16 of the 256 points. The band holds 1090 non-modal pixels out of
// 8*1280 = 10240, a density of 0.1064, so the expected number of contaminated
// sampled points is 16 * 0.1064 = 1.70. A 256-point MEAN therefore returns
// essentially the surface's MODAL value, and the modal value of uninitialised
// memory is zero -- which is also the modal value of a legitimately black
// frame. The sampler is a modal estimator and no threshold on its output can
// separate the two cases. 256 of 921600 pixels is 0.0278% of the surface.
//
// WHY THE CENSUS NUMBERS ARE THE RIGHT THING TO GATE ON. The signal has to be
// PLACEMENT-INVARIANT, because the log records which colours a surface holds
// and how many of each, but not which pixel holds which colour. Anything
// geometric (a bounding box, a fill ratio, an isolation count) would be
// answering a question the measurement cannot answer. A value HISTOGRAM is
// fully determined by the logged numbers, so the statistic below is computed
// from measured quantities only.
//
// THE STATISTIC. rareFraction = (contaminated pixels whose own colour occurs at
// most kGuestCensusRareCount times in the whole surface) / (contaminated
// pixels), where contaminated = total - modalCount. It answers one question:
// of the pixels that are NOT the surface's background, how much mass sits in
// colours that are individually almost absent?
//
//   A surface the guest drew   -> its content is REGIONS. A region is one
//     colour repeated thousands of times, so its mass is not in rare colours
//     and rareFraction is 0.
//   A VA the guest never wrote -> its content is whatever the allocator left.
//     That is bright fragments, each appearing a handful of times, so its mass
//     IS in rare colours and rareFraction is near 1.
//
// MEASURED on the three surfaces build/w717.log describes. All three numbers
// are read off LATE-FRAME-PIXEL rows, none is inferred:
//
//   buffer 0  total=921600 modalCount=691200 contaminated=230400
//             distinct=2  -> every one of those 230400 px is the same colour
//             (topRgba gives (0,0,0,255)x230400) -> rareCount=0
//             rareFraction = 0/230400 = 0.000000            COHERENT
//   buffer 1  total=921600 modalCount=921600 contaminated=0
//             distinct=1  -> uniform, the vacuous branch   COHERENT
//   buffer 2  total=921600 modalCount=920510 contaminated=1090
//             distinct=260 -> of the 1090, the eight largest non-modal counts
//             are 508, 71, 24, 21, 17, 16, 10, so 1090-667 = 423 px sit in
//             colours occurring at most 8 times
//             rareFraction = 423/1090 = 0.388073          NOT COHERENT
//
// THE THRESHOLD, AND ITS MEASURED ERROR RATE. kGuestCensusRareFractionMax is
// 0.05. On the good side the measured value is EXACTLY 0.0, so the margin is
// the threshold itself: any threshold above zero accepts both drawn surfaces.
// On the refused side the measured value is 0.388073, which is 7.76x over the
// threshold. False-refusal rate on the two drawn surfaces measured in this log:
// 0 of 2. False-acceptance rate on the two never-written VA families named
// above: 0 of 2, once this gate exists -- and 2 of 2 without it, because the
// old sampler gated NOTHING (see the .cpp comment at the call site).
//
// THE LIMIT OF THIS GATE, STATED BECAUSE IT IS REAL AND NOT HIDDEN. The log
// contains exactly TWO legitimate surfaces and both are flat, so 0.05 is
// calibrated against n=2. A legitimate frame whose non-modal pixels are mostly
// in colours occurring at most 8 times -- heavy anti-aliasing, a gradient, fine
// particle detail -- would be refused, and nothing in build/w717.log measures
// how often that is. That false-refusal rate on rich content is UNRESOLVED and
// needs an owner; the remedy is a threshold moved on a real frame's census, not
// a guess. What this gate does establish is the direction that cannot be
// wrong: it refuses a surface it cannot vouch for and never paints over one.
//
// THE TWO REFUSAL DIRECTIONS ARE DELIBERATE AND ASYMMETRIC. A histogram that
// overflowed its cap cannot prove uniformity, so an overflow REFUSES. A
// zero-pixel surface has measured nothing, so it REFUSES. Neither substitutes
// anything: charter F-609 forbids inventing a pixel, and the only honest
// answers to "this surface is not coherent" are to leave the back buffer
// exactly as it stands and to say so by name.
// ===========================================================================

struct GuestSurfaceCensus {
    uint64_t total = 0;             // pixels examined, stride 1, no sampling
    uint64_t distinct = 0;          // different rgba values seen
    uint64_t distinctOverflow = 0;  // values that did not fit the cap
    uint64_t modalCount = 0;        // pixels holding the most common rgba
    uint64_t contaminated = 0;      // total - modalCount
    uint64_t rareCount = 0;         // contaminated px in colours seen <= 8 times
    uint64_t distinctNonModal = 0;  // distinct values other than the modal one
    uint64_t largestNonModal = 0;   // biggest count among those
    double rareFraction = 0.0;      // rareCount / contaminated
};

// Open-addressed histogram capacity. 4096 values in 16384 slots is a load
// factor of 0.25, so the probe loop cannot exhaust; the same numbers the
// existing pixel census in the .cpp uses, so one surface cannot measure two
// different distinctRgba depending on which path asked.
inline constexpr uint32_t kGuestCensusDistinctCap = 4096u;
inline constexpr uint32_t kGuestCensusSlots = kGuestCensusDistinctCap * 4u;
// "Individually almost absent." 8 is one byte: a colour held by fewer than a
// byte's worth of a 32-bit pixel cannot be a region.
inline constexpr uint32_t kGuestCensusRareCount = 8u;
// Geometric reasoning is not available here because the good side measures
// exactly 0, so this is chosen from the refused side alone: 0.05 sits 7.76x
// under the measured 0.388073 of the never-written surface and above the 0.0
// of both drawn surfaces.
inline constexpr double kGuestCensusRareFractionMax = 0.05;

// Walks EVERY pixel of the surface. There is no stride and no sampling here
// on purpose: a subsample is the defect being removed, so a subsample cannot
// be reintroduced as an optimisation. `pixels` is the host copy the caller
// already holds, so this adds no guest read and no page-in.
//
// RUN-LENGTH ENCODING, AND WHY IT IS EXACT RATHER THAN A SAMPLE. A flat run of
// N pixels holding one colour contributes exactly N to that colour's count, so
// a run is folded into the histogram as a single addition of its length. Every
// pixel is still read and every pixel is still counted; nothing is skipped and
// nothing is estimated. It matters because the per-pixel cost is a pair of
// dependent loads (probe the slot, then load the key it names) and because a
// surface the guest drew is overwhelmingly flat, so the number of runs is
// orders of magnitude below the number of pixels. MEASURED on this machine,
// 1280x720: 2896 us per walk over the drawn surface without it, and the figure
// with it is printed by the F-762 harness in %TEMP%\opencode. The worst case
// is unchanged -- scattered debris has one run per pixel -- and the worst case
// is the case being refused, which is rare.
//
// thread_local scratch rather than a fresh allocation per call, because the
// call site runs on the frame path. A surface is uploaded or refused on the
// same bytes every time, so the walk is repeated by design and only its
// allocation is amortised.
inline void CensusGuestSurface(const uint8_t* pixels, uint32_t width,
                               uint32_t height, GuestSurfaceCensus* out) {
    if (!out) return;
    *out = GuestSurfaceCensus{};
    if (!pixels || width == 0 || height == 0) return;

    static thread_local std::vector<uint32_t> slots;
    static thread_local std::vector<uint32_t> keys;
    static thread_local std::vector<uint64_t> counts;
    slots.assign(kGuestCensusSlots, 0u);
    keys.clear();
    counts.clear();
    keys.reserve(kGuestCensusDistinctCap);
    counts.reserve(kGuestCensusDistinctCap);

    // Adds `run` to `key`'s count, creating the entry if this is its first
    // appearance. Returns false only when the histogram could not take the
    // key, which the caller counts as an overflow.
    auto add = [&](uint32_t key, uint64_t run) -> bool {
        uint32_t slot = ((key * 2654435761u) >> 12) & (kGuestCensusSlots - 1u);
        uint32_t probes = 0;
        while (probes < kGuestCensusSlots) {
            const uint32_t occupant = slots[slot];
            if (occupant == 0u) {
                if (keys.size() >= kGuestCensusDistinctCap) return false;
                keys.push_back(key);
                counts.push_back(run);
                slots[slot] = static_cast<uint32_t>(keys.size());
                return true;
            }
            if (keys[occupant - 1u] == key) {
                counts[occupant - 1u] += run;
                return true;
            }
            slot = (slot + 1u) & (kGuestCensusSlots - 1u);
            ++probes;
        }
        return false;
    };

    uint64_t total = 0;
    uint64_t distinctOverflow = 0;
    uint32_t runKey = 0;
    uint64_t runLen = 0;
    for (uint32_t y = 0; y < height; ++y) {
        const uint8_t* row = pixels + static_cast<size_t>(y) * width * 4u;
        for (uint32_t x = 0; x < width; ++x) {
            const uint8_t* q = row + static_cast<size_t>(x) * 4u;
            const uint32_t key = static_cast<uint32_t>(q[0]) |
                                 (static_cast<uint32_t>(q[1]) << 8) |
                                 (static_cast<uint32_t>(q[2]) << 16) |
                                 (static_cast<uint32_t>(q[3]) << 24);
            if (runLen != 0 && key == runKey) {
                ++runLen;
            } else {
                if (runLen != 0 && !add(runKey, runLen)) ++distinctOverflow;
                runKey = key;
                runLen = 1;
            }
            ++total;
        }
    }
    if (runLen != 0 && !add(runKey, runLen)) ++distinctOverflow;

    uint32_t modalKey = 0;
    uint64_t modalCount = 0;
    for (size_t i = 0; i < keys.size(); ++i) {
        if (counts[i] > modalCount) { modalCount = counts[i]; modalKey = keys[i]; }
    }

    uint64_t rareCount = 0;
    uint64_t distinctNonModal = 0;
    uint64_t largestNonModal = 0;
    for (size_t i = 0; i < keys.size(); ++i) {
        if (modalCount != 0 && keys[i] == modalKey) continue;
        ++distinctNonModal;
        if (counts[i] > largestNonModal) largestNonModal = counts[i];
        if (counts[i] <= kGuestCensusRareCount) rareCount += counts[i];
    }

    out->total = total;
    out->distinct = static_cast<uint64_t>(keys.size());
    out->distinctOverflow = distinctOverflow;
    out->modalCount = modalCount;
    out->contaminated = total - modalCount;
    out->rareCount = rareCount;
    out->distinctNonModal = distinctNonModal;
    out->largestNonModal = largestNonModal;
    out->rareFraction = (out->contaminated != 0)
                            ? static_cast<double>(rareCount) /
                                  static_cast<double>(out->contaminated)
                            : 0.0;
}

// The gate itself. Four outcomes, and only one of them is "go":
//   no pixels measured      -> refuse (nothing was examined)
//   histogram overflowed    -> refuse (cannot prove uniformity from a full table)
//   one single value        -> ACCEPT: a uniform surface. Black is a
//                              measurement, and there is no scattered content
//                              in it to be wrong about.
//   otherwise               -> ACCEPT iff rareFraction is within the ceiling.
inline bool GuestSurfaceIsCoherent(const GuestSurfaceCensus& c) {
    if (c.total == 0) return false;
    if (c.distinctOverflow != 0) return false;
    if (c.contaminated == 0) return true;
    return c.rareFraction <= kGuestCensusRareFractionMax;
}

D3D12Backend* GetD3D12Backend();

} // namespace mcla::native
