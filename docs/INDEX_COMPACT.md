# INDEX_COMPACT — MCLA PC (2026-10-12, code-read only)

> New file, pointers only. Zero deletions. Anything with a number not cited to
> `src/` below is UNVERIFIED here — this pass read code, not logs or git
> (`git` binary absent on this PC; `.git/` present but unreadable).

## 1. Goal and gate

Boot → menu → playable. Guest `default.xex` (Xenon PPC) via static
recompiler + D3D12 backend. **Menu-gate (LONG_TODO_MASTER §9, 2026-10-12):**
frame path first; XMA bitstream, native RAGE upload, exotic prims/depth
variants stay parked until a soak reaches menu. Promotion trigger: a soak
proves a parked item blocks menu.

## 2. Ideal flow (RAGE systems view)

`RPF packfile → streaming cells → TXD/DFF/.fxc/XMA decode → scene+cull →
draw buckets (fetch+constants+textures+samplers) → PM4/CP ring → EDRAM
resolve → present`. Audio/input/physics parallel, decoupled. Rule: never
fake the frame path — a placeholder pixel that reports success hides the
real producer. Full statement: `src/rage/rage_ideal_flow.h`.

## 3. What exists in `src/` (verified by listing + reading)

- CPU: `generated/ppc_xenon/ppc_recomp.0..175.cpp` + `ppc_func_mapping.cpp`,
  `src/cpu/vmx128_pack.cpp`, `src/kernel/guest_thread.cpp`. MOST IMPORTANT,
  read-only. TU count gated in `CMakeLists.txt:38`.
- Boot/host: `src/boot_host.cpp`, `src/app.cpp`, `src/guest_memory.cpp`,
  `src/early_init.cpp`, `src/compat.cpp`, `src/dispatch_guard.cpp` (do-not).
- Kernel: `src/kernel/memory.cpp`, `heap.cpp`, `o1heap.c`,
  `src/kernel/imports.cpp`, `xam.cpp`, `xdm.cpp`, `port_net.cpp`,
  `port_kobj.cpp`, `port_xam_user.cpp`, `port_voice_input.cpp`.
  `src/ppc_context.h`, `src/ppc_config.h` are do-not (forbidden list).
- GPU: `src/gpu_cp.cpp`, `src/gpu_mmio.cpp`, `src/gpu_device.cpp`,
  `src/render_thread.cpp`, `src/render_queue.h`, `src/frame_trace.cpp`,
  `src/capture_hooks.cpp`, `src/patches.cpp`, `src/native_renderer.cpp`,
  `src/renderer_mode.cpp`, `src/renderer_hook_dispatch.cpp`.
- D3D12: `src/d3d12_backend.cpp` (`DrawDynamicMeshWithPipeline`,
  `BindGuestTextures`, `BindGuestSampler`, `ResolveGuestSurface`,
  `MapXenosPrimType`, `PresentOwnedFrame`).
- Renderer lib: `src/renderer/xenos_microcode.cpp`, `xenos_shader_ir.cpp`,
  `shader_translator.cpp` (pinned entry `TranslateShaderPinned`),
  `dxc_runtime.cpp`, `pipeline_cache.cpp`, `resource_cache.cpp`,
  `vertex_decode.cpp`, `grc_fvf_decode.cpp`, `texture_decode.cpp`.
- FS: `src/fs/vfs_rpf.cpp`, `src/fs/rpf3_nested.cpp`, `src/raw_inflate.h`,
  `src/xmem_lzx.h`.
- Audio: `src/apu/audio.cpp` (true silence, worker on real thread block),
  `src/apu/xma_decoder.h` (framing done, bitstream seam EMPTY by design).
- Assets (forensics only): `src/rage/rage_asset_pipeline.cpp` (CSR/TXD/DFF
  parse), `src/rage/rage_ideal_flow.h` (policy).

## 4. What is parked, and what was fixed 2026-10-12

- FIXED: `src/rage/rage_asset_pipeline.cpp:499-559` — `GetTextureData` /
  `GetOrCreateTexture` / `GetOrCreateModel` were white-texture/`true`
  fake-success; now honest `false` + counted `RAGE-ASSET-REFUSE`. Guest
  `BindGuestTextures` / vertex_decode own the frame path.
- PARKED: XMA bitstream (`xma_decoder.h:16-32`; guest never constructs
  XAudio per `audio.cpp:40-51` — silence is correct); exotic prims + t4+
  descriptors + depth-resolve variants (refuse + count in backend);
  `ppc_context.h:64,101` + `patches.cpp:869` TODOs (stale/dead-hook
  comments, not missing files — leave).

## 5. Where the queue lives (do not duplicate)

- Operative queue: `docs/LONG_TODO_MASTER.md` §6 T43 table + §9
  Deferred/parked + §9 MENU-GATE. §2 is a superseded snapshot (note at
  `:576-614`); ledger `Task:` rows decide live/closed.
- Evidence: `docs/ROOT_CAUSE_VALIDATION.md` append-only (never rewrite).
- Compact rewrites (2026-10-12, new files, originals intact):
  `docs/COMPACT_LONG_TODO.md`, `docs/COMPACT_HANDOFF.md`,
  `docs/COMPACT_PROGRAM_GUIDE.md`, `docs/COMPACT_HISTORY.md`.
- Live block: `docs/HANDOFF_NEXT_AGENT.md`. Build/run: `docs/PROGRAM_GUIDE.md`
  §3 + `.qoder/skills/mcla-boot-cycle`. Forbidden paths: PROGRAM_GUIDE §11 +
  `AGENTS.md` rule 2. Rules collide by number — always name the file.

## 6. History (measured with portable MinGit 2.55.0, no admin install)

- `rev-list --count HEAD` = **435** commits. First = `c8567d8` "Initial
  commit: MCLA native GPU rebuild tree (Phase 0-3)". HEAD = `32127c24`
  "docs: handoff - boot blocker solved at a9bd027". Mid arc: `a9bd027`
  cursor-snapshot (boot no longer fatals) → tiered queue → audio honesty.
- Remote: `https://github.com/3bdull4h2008/mcla-pc.git`, branch `master`.
- Arc matches code read; full per-commit audit is future work, one file
  per commit per the 09-23 merge rule.

## 7. Not audited yet

Runtime numbers (menu, draws, presents) are UNVERIFIED in this file until a
soak reproduces them. Working-tree deltas since `32127c24` (uncommitted):
`src/rage/rage_asset_pipeline.cpp` (honest refusal),
`src/rage/rage_ideal_flow.h` (new), `docs/LONG_TODO_MASTER.md` (§9
MENU-GATE), this file (new).

## 8. Session pointer, 2026-10-13 (trail-writer)

- Ledger: **`docs/ROOT_CAUSE_VALIDATION.md` F-794** — T43.17 honesty
  campaign CLOSED by the w765 stamp (108,275 lines, `Fatal error` 0;
  PHYS/XTL-FREE-SUM pct over attempted verified live; SEMA 78 = 54 wait +
  24 release; KEWAIT-RESOLVE hits=16383/misses=1); T43.16 slab-floor =
  Attempt (`src/kernel/heap.cpp:3253-3270`); w766 frontier
  (mainwait=B73D8040, 286 s, race UNDECIDED); two withdrawals with cause
  (`~99.8% fallback`, `GLOBTEX-SERVE-BODY` phantom). Re-verified lines in
  the entry; brief-supplied items are marked there, not asserted.
- Soaks: `build/w765.log` (stamp), `build/w766.log` (frontier),
  `build/w769.log` (VFS no-folder fix: absent-row + `Fatal error` 0).
- Not touched per brief: LONG_TODO / HANDOFF / PROGRAM_GUIDE.
