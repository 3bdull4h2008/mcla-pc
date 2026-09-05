# MCLA Native PC — Architecture Brainmap

Updated 2026-09-05 · **Live frontier:** `docs/BOOT_HANDOFF.md` · Plan: `MCLA_REBUILD_PLAN.md` · Handoffs: `docs/handoffs/` · Default renderer mode: `legacy`

## 1. Purpose

Replace the Xenos command-processor (CP) rendering path inside the XenonRecomp-recompiled
Midnight Club LA PPC image with a native Direct3D 12 renderer: recompiled guest code keeps
running untouched; render intent is captured at the high-level draw boundary and replayed as
real D3D12 work (Xenos microcode → IR → HLSL/DXIL). `renderer_mode=legacy` stays the default
until every phase gate in `MCLA_REBUILD_PLAN.md` passes — never claim a path is native while
the Xenos CP runs, PM4 is submitted by us, or draw data is guessed.

## 2. Component Map

| Component | Role |
| --- | --- |
| `src/kernel/` | UnleashedRecomp-canonical kernel: identity handles (`xdm.h`), typed-arg `GUEST_FUNCTION_HOOK` imports (`imports.cpp`), guest heap/o1heap (`memory`,`heap`), XAM (`xam.cpp`), guest threads PCR/TLS/TEB/stack (`guest_thread.cpp`), `kernel_objects.h`, canonical types (`xbox.h`) |
| `src/cpu/` | `ppc_context.h` register file, guest-thread decls |
| `src/apu/` | Audio host side (`audio.cpp`) |
| `src/renderer/` | Xenos microcode decode → IR (`xenos_microcode`, `xenos_shader_ir`), translator + DXC runtime (`shader_translator`, `dxc_runtime`), pipeline/resource caches, vertex/grcFVF + texture decode, RAGE asset pipeline, offline validator mains (`*_validator.cpp`) |
| `src/user/` | `config.h` (user config surface) |
| Root hosts | `boot_host.cpp` (standalone boot host linking full recompiled image), `main.cpp`/`app.cpp`, `early_init.cpp`, `patches.cpp`, `guest_memory.cpp` (checked BE accessors), `guest_thread.cpp`, `gpu_mmio.cpp` (XGPU MMIO window), `vfs_rpf.cpp` (RPF packfile VFS), `native_renderer.cpp` + `renderer_mode.cpp` (legacy/native switch), `renderer_hook_dispatch.cpp` + `capture_hooks.cpp` (capture boundary), `frame_trace.cpp` (`.mclatrace`/`.xtr` dumps), `d3d12_backend.cpp` (device/PSO cache/present), `compat.cpp`, `boot_log.cpp` |
| `generated/ppc_xenon/` | Recompiler output: `ppc_func_mapping.cpp` + `ppc_recomp.0..178.cpp` (~46k function mappings). **Input only — never patch** |
| CMake targets | `mcla` (exe) · validators: `phase0_validator` (kernel units) · `xenos_decode_validator` · `shader_pipeline_validator` · `phase3_validator` (vertex/texture decode) · `texture_decode_test` · `capture_dump_validator` · `xtr_dump_validator` · `backend_validator` (D3D12 smoke) |

## 3. Data Flow (guest entry → present)

```text
[default.xex load]                        LIVE   boot_host: PE extract, func mappings, BootWorker
      v
[guest entry -> recompiled image]         LIVE   PPC_FUNC_MAPPING dispatch over flat 4GB guest heap
      v
[kernel imports]                          LIVE   typed GUEST_FUNCTION_HOOKs; identity handles;
      v                                          events/sems/critsects/threads healthy (13 thr)
[VFS / packfiles]                         LIVE   vfs_rpf serves 4x xarchive_*.rpf as REAL bytes;
      v                                          FileInformationClass 34 EndOfFile=true sizes
[GPU context init]                        LIVE   VdInitializeEngines/RingBuffer/RPtrWriteBack,
      v                                          VdSetGraphicsInterruptCallback -- full init, no seeding
[vsync interrupt thread]                  LIVE   callback @0x82411478 firing 60fps; r3=interrupt
      |                                          type (r3=0 graphics, r3=1 vsync event)
      v
[OOM / heap churn]                        🟡 ACTIVE  OOM front mitigated but not closed; chain-rebuild
      |                                          fired 4x in the 2026-09-05 soak, no OOM fatal, but
      |                                          overflow root cause remains unidentified
      v
[config dispatch null-handler AV]         ❌ ACTIVE  session-38 deterministic AV inside original
      |                                          sub_8218CC70 body; host r8=0xffffffff7e780000 indicates
      |                                          NULL/garbage handler via PPC_LOOKUP_FUNC arithmetic on
      |                                          target=0; config global @0x82839270 is currently ZERO
      v
[device-method capture]                   🟡 P4′   create-hook @sub_82413588 + packet capture v2
      |                                          @sub_82411640 armed (steps 1-2 done); remaining
      |                                          steps: Present/state/draw hooks → enqueue
      |                                          RenderCommands (NEVER PM4 — golden rule 11)
      v
[render thread & queues]                  ⏳ P4.5′  blocking queue + copy queue; render thread owns
      v                                          ALL D3D12 calls (UR gpu/video.cpp blueprint)
[D3D12 present]                           LIVE*   d3d12_backend device+PSO cache+swap (*synthetic/
                                                 validator content only; real-frame native = P5′/P6′)
[CP drain: PM4 ring]                      FROZEN  legacy path ONLY (CP FREEZE LINE 2026-08-24):
                                                 doorbell 0x7FC80000+0x1C5, rptr->0x072344BC,
                                                 XE_SWAP(0x64); retired/deleted at P6′
```

Legacy mode bypasses everything below `[GPU context init]` via the Xenos command processor —
that is the path being retired.

## 4. Phase Gates

Revised ladder (P4′–P9′) per `MCLA_REBUILD_PLAN.md` — the old P4/P5/P6
CP-emulation gates are superseded:

| Phase | Scope | Status |
| --- | --- | --- |
| P1 | ABI migration (ppc_func abi, checked guest memory, full ABI header) | ✅ DONE |
| P2 | Canonical kernel framework (identity handles, typed hooks, lazy wrap) | ✅ DONE (13/13, re-verified 2026-09-03) |
| P3 | Critical boot imports → real present chain | ✅ **PASSED 2026-08-22 (`39ebebf`)** — boots into main loop, world loads from real archives, VSync present chain 60fps, thousands of frames, zero crashes |
| P4′ | Device-boundary takeover (create/Present/state/draw hooks, enqueue only) | 🔄 steps 1-2 done; blocked on boot OOM front |
| P4.5′ | Render thread & queues (render thread owns all D3D12) | ⏳ pending |
| P4.6′ | Resource model (guest textures/buffers, deferred destruction) | ⏳ pending |
| P5′ | Real draws via device boundary (pixel-hash parity) | ⏳ pending |
| P5.5′ | Offline shader cache (embedded XXH3-keyed DXIL) | ⏳ pending |
| P6′ | Native default & legacy retirement (delete gpu_cp.cpp) | ⏳ pending |
| P7′–P9′ | Build env, codegen config, kernel surface | ⏳ pending |

## 5. Current Front Line (session 38 refreshed, 2026-09-05)

**Primary blocker:** deterministic AV in the original `sub_8218CC70` config-dispatch
path. The OOM front is still active as a related allocator problem, but it is now
considered mitigated rather than the single active blocker: the 2026-09-05 soak saw
chain rebuild fire 4x and no fatal OOM, but the write that overflowed the 16-byte
pool remains unidentified.

Active front:
1. **Config-dispatch null-handler AV** — `__imp__sub_8218CC70 +0xC1`, host
   `r8 = 0xffffffff7e780000`, which is the session-25-decoded
   `PPC_LOOKUP_FUNC` arithmetic on target=0. The call chain lands in the config
   dispatch path, and `CONFIG-DISPATCH GLOBAL @0x82839270` is currently ZERO.
2. **Allocator overflow still unresolved** — class allocator `sub_821DE9D8`
   and the 16-byte pool are still under census; the root cause of the actual
   write overflow has not been identified despite chain-rebuild mitigation.
3. **GPU-progress-wait class (secondary, session 34):** ring put advances but the
   GPU progress counter never does → legacy CP publication not reaching the guest;
   fix only under the CP freeze line as kernel/CP-legacy work.

Discriminating probes (session 38 next):
- `CONFIG-DISPATCH` census v2: log every dispatch (idx, offset, base_ptr,
  struct, target_fn, valid-bit) for the first 200 calls, then every 100th call,
  plus the GLOBAL `@82839270` value per call.
- Confirm the initializer for the config global / handler table and the allocator
  registration path; likely the registration never ran or a `0xB5800000`-class
  phys alloc returned wrong memory.
- After the dispatch front closes, run the writer-attribution census on the 16-byte
  pool slab range to close the overflow root cause.
- Then resume P4′ step 3 render-thread work.

History: post-P3 park ([0x7FC86544] bit0) → superseded 2026-08-24 by the bctrl
dispatch crash at `sub_825FDB30` (decoded: node-chain walk reachable only via
data-section vtables; "raw host pointer 0x7E780000" was PPC_LOOKUP_FUNC slot
arithmetic on ctr=0).

## 6. Validation Infrastructure

| Validator | Gate | Status |
| --- | --- | --- |
| `phase0_validator.exe` | kernel framework units (memory/handles/hooks/objects) | ✅ 13/13 PASS (re-verified 2026-09-03) |
| `xenos_decode_validator.exe` | raw microcode decode over corpus | ✅ |
| `shader_pipeline_validator.exe` | every container translates, no unknown opcodes | ✅ |
| `phase3_validator.exe` | vertex fetch + resource/texture decode | ✅ synthetic data only |
| `texture_decode_test.exe` | tiled/Xenos decode vs oracle | ✅ |
| `capture_dump_validator.exe` | `.mclatrace` integrity, dump coverage | ✅ |
| `xtr_dump_validator.exe` | `.xtr` parse, histogram, frame delims | ✅ |
| `backend_validator.exe` | D3D12 device/PSO/root-signature smoke | ✅ synthetic data only |
| `phase1/2_validator.exe` | boot-import behavior; GPU-context chain | ❌ not yet created |

Smoke gate: `build\mcla.exe --validate-shaders --headless`.

## 7. Session Protocol

Loop Discipline lives in `MCLA_REBUILD_PLAN.md` §Loop Discipline: trigger → verifiable goal →
verification (gates need rung ≥2 evidence; maker ≠ checker) → named terminal state → memory.
Append a Run Receipt per boot run. Handoffs: `docs/handoffs/YYYY-MM-DD-*.md` — read the
newest before acting; externalize exact state (addresses, evidence, open questions) before
context pressure. Auto-compaction is off.

## 8. Ship-Blockers Before Phase 4 Tag (from 2026-08-22 handoff)

1. Strip `function.h` import-trace probe (+ includes) — temporary 4000-cap stderr logger.
2. Demote per-frame VSync INFO logs.
3. Consolidate manual `ctx.rN` query wrappers (`NtQueryVolumeInformationFile`,
   `NtQueryDirectoryFile`) onto existing dead typed impls.
4. Class-34 fallback statuses must be `INVALID_INFO_CLASS`/`INFO_LENGTH_MISMATCH` (xenia
   semantics), not SUCCESS+zeros.
5. Security (MED, open): identity-handle ABA/generation counter before Phase 4 adds handle types.

Standing rules: one hook owner per address · hooks capture-only · wire ONE import at a time ·
no invented draw data · legacy stays default until gates pass.
