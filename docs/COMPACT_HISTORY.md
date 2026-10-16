# COMPACT_HISTORY (2026-10-12, MinGit 2.55.0 measured)

> Full per-commit audit is future work (one file per commit). This is the
> phase arc + working-tree truth.

## Arc — 435 commits (`rev-list --count HEAD` = 435)

`c8567d8` initial (Phase 0-3 tree) → capture dump + validator → Phase 4
texture decode + untiling (`renderer/texture_decode.cpp`) → Phase 4
backend + Phase 3 gates → Phase 5 shader pipeline + DXC + cache
(`shader_translator.cpp`, `dxc_runtime.cpp`, `pipeline_cache.cpp`) →
Phase 6-8 samplers + render graph + frame loop → Phase 9a VFS/RPF
(`fs/vfs_rpf.cpp`, `rpf3_nested.cpp`) → Phase 9b RAGE parsers
(`rage/rage_asset_pipeline.cpp`) → Phase 9c VFS thunks/PM4 clamp →
tooling (`soak_census.py`, `rpf_offline.py`) + F-453…F-571 → `a9bd027`
cursor snapshot (boot no longer fatals) → audio honesty → HEAD
`32127c24` handoff. Remote `github.com/3bdull4h2008/mcla-pc.git`, `master`.

## Working tree (`status --short`, 21 modified + 17 untracked)

Modified include: 3 skills, `AGENTS.md`, all 4 big docs, `boot_host.cpp`,
`vfs_rpf.cpp`, `gpu_cp.cpp`, `gpu_device.cpp`, `guest_memory.cpp`,
`kernel/heap.cpp`, `memory.cpp/.h`, `o1heap.c/.h`,
`rage_asset_pipeline.cpp`, `ppc_disasm.py`, `ppc_xrefs.py`. Untracked
include shader `.hlsl/.dxil` pairs, `docs/INDEX_COMPACT.md` (+ 4 COMPACT_*
here), `trail-handoff-2026-10.md.tmp`, `reverted.cpp`,
`src/rage/rage_ideal_flow.h`. N-way dirty → attribution provisional
(rule 1a) until single-variable reverts.

## Code reality (existence measured)

GPU CP/device/MMIO, D3D12 backend + native renderer + render thread,
shader pipeline, texture/vertex/resource decode, kernel heap/memory/
threads/XAM/XDM/ports/imports, FS VFS, RAGE parsers, APU audio + XMA
framing, CPU VMX128, boot/host/capture/hooks — all EXIST under `src/`
(see COMPACT_LONG_TODO §3 for paths). Missing = policy-parked (XMA
bitstream, native upload, exotic prims), not absent files.
