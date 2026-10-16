#pragma once

// RAGE ideal dataflow vs MCLA current state -- Rockstar systems view.
// Senior designer read: what the engine WANTS, what this tree HAS, what to do.
//
// IDEAL (360-era RAGE, still true on PS5 RAGE9, only faster media):
//   Disc/HDD -> RPF packfile (TOC + compressed members) -> streaming engine
//     (preload + world cells by velocity, HLOD on PS5) -> resource loader
//     (TXD textures, DFF models, .fxc shaders, XMA audio) -> scene graph +
//     culling -> draw buckets (vertex fetch + constants + textures + samplers)
//     -> GPU ring (PM4 / CP) -> EDRAM resolve -> present.
//   Parallel, never blocking the frame: XMA -> XAudio, input, physics/AI tasks,
//   network. Visual streaming and physics streaming are DECOUPLED (PS5 makes
//   this explicit: discard/rebuild distant clutter procedurally, keep physics
//   cells longer). A placeholder pixel or a fake success anywhere in this chain
//   ships a plausible frame that is not the game's frame -- forbidden.
//
// CURRENT (measured from src/, not from docs/logs):
//   CPU: static recompiler, 176 TUs + func mapping + dispatcher. MOST
//     IMPORTANT, DO NOT TOUCH. Analogous to a PS5 PSSL transpile: if the CPU
//     lies, every system above lies. Protect with the TU-count gate.
//   Kernel: memory/heap/o1heap + XTL alloc/free real, thread blocks real.
//     Correct -- RAGE streams through these allocators constantly.
//   FS: vfs_rpf + rpf3_nested serves outer + nested RPF, expanded spans,
//     raw-deflate lists. On the boot path. XCompress/LZX UI containers decode
//     via xmem_lzx host-side. Keep.
//   GPU: gpu_cp drain + MMIO routing + render_thread queue + capture_hooks +
//     gpu_device census exist. Draw chain is vertex_decode + grc_fvf_decode +
//     TranslateShaderPinned + pipeline_cache + BindGuestTextures/Sampler +
//     DrawDynamicMeshWithPipeline + ResolveGuestSurface + PresentOwnedFrame.
//     Thin but correctly split: guest owns bytes, backend owns pixels.
//   Audio: framing complete (xma_decoder.h), bitstream seam EMPTY by design.
//     Guest never constructs its XAudio object (audio.cpp:40-51: one bl site,
//     zero callers, vtables unreferenced) so nothing is reachable. Policy:
//     true silence + census, never a tone, never fake PCM.
//   Native RAGE parsers (CSR/TXD/DFF in rage_asset_pipeline.cpp): parse for
//     forensics, NEVER feed D3D12 on the boot path. GetTextureData /
//     GetOrCreate* now refuse loudly (RAGE-ASSET-REFUSE) instead of white
//     texture + return true. Growing host upload here duplicates the guest
//     path and masks its failures -- park until menu is reached via guest.
//   Stale comments, not missing files: ppc_context.h TODOs (MMIO/eieio) are
//     already covered by CpInstallMmioRouting; patches.cpp TODO sits in a
//     dead hook (hk_sub_82411840, registered nowhere). Leave both.
//
// PS5 / STATIC-RECOMPILER / EMULATOR note:
//   PS5 RAGE9: SSD streaming cells + procedural rebuild + raytraced audio,
//     same decoupled pipeline, 100x the budget. Lesson for here: stream by
//     velocity, refuse loudly on missing cells, never synthesise.
//   Static recompiler (XenonRecomp): PPC->C++ ahead of time, 1:1 with the
//     guest bytes. Vs Xenia's JIT + HLE kernel: we keep the guest's own code
//     and reimplement only the OS/GPU edges. That is why generated/** is
//     read-only and why a "fix" there is really a hook here.
//   Emulator rule: HLE the OS, never the game. Fake input, fake profile,
//     fake pixels all render something the game never drew.
//
// POLICY for the next agent: if it is on the frame path (alloc, FS read,
//   draw, resolve, present, shader key) -- implement honestly or refuse with
//   a counted marker. If it is parallel (XMA bitstream, native RAGE upload,
//   exotic prims, depth resolve variants) -- census + silence/refusal, no
//   synthesis. Removal trigger for every refusal: a soak reaching menu with
//   that refusal at zero.

#include <cstdint>

namespace mcla::rage {

// Frame-path ownership, one line each so a reader cannot reassign them.
inline constexpr const char* kTextureOwner = "guest DrawPacket -> texture_decode -> D3D12Backend::BindGuestTextures";
inline constexpr const char* kGeometryOwner = "guest DrawPacket -> vertex_decode/grc_fvf_decode -> DrawDynamicMeshWithPipeline";
inline constexpr const char* kShaderOwner = "guest .fxc -> TranslateShaderPinned -> pipeline_cache -> PSO";
inline constexpr const char* kAudioOwner = "guest XMA -> xma framing -> (no bitstream backend) -> true silence";
inline constexpr const char* kNativeRageRole = "offline forensics only: parse + census, never resident on boot path";

} // namespace mcla::rage
