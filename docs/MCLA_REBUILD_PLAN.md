# MCLA Native PC Rebuild Plan (Unified, 2026-08-19; **UR-Succession Revision 2026-08-22**)

> Single authoritative plan. Supersedes `XENONRECOMP_REBUILD_PLAN.md`,
> `BOOT_REBUILD_PLAN.md`, and `NATIVE_GPU_REBUILD_PLAN.md` (deleted 2026-08-19;
> content preserved in this file). Kernel layer **must mirror**
> `.research/UnleashedRecomp/kernel/` structure exactly — the canonical framework
> uses guest-VA identity handles, typed-arg `GUEST_FUNCTION_HOOK` one-liners,
> `QueryKernelObject` lazy-wrap, and single-param `KernelObject::Wait`. Follow
> phases in order. Never claim a path is native while it calls the Xenos command
> processor, submits PM4, or relies on guessed draw data.

---

## Table of Contents

1. [⭐ UR-Succession Revision (golden rules 11–14, CP freeze line)](#-ur-succession-revision-2026-08-22--authoritative-for-all-gpurender-work)
2. [Current Blocker (sessions 33–37)](#current-blocker-2026-09-05-refresh--sessions-3337)
3. [External Recon (web-verified 2026-09-03)](#external-recon-web-verified-2026-09-03--research-round-18-sources)
4. [Revised Phase Ladder (P4′–P9′) + Automated Phase Gates](#revised-phase-ladder)
5. [Source-vs-Plan Audit (documented conflicts, unfixed)](#source-vs-plan-audit-2026-09-03--documented-conflicts-unfixed)
6. [Debug Surface / Decisions Locked](#debug-surface-for-the-human-requested-2026-08-22)
7. [No-ReXGlue Mandate · Purpose · Core Architecture](#norexglue-mandate-2026-08-20)
8. [Canonical Framework Rules + Import Pattern](#core-architectural-decision-2026-08-19-revalidated)
9. [Constraints / Golden Rules](#constraints--golden-rules)
10. [Phase Plan (P1–P3 active; old P4–P6 superseded)](#phase-plan)
11. [Validation Infrastructure](#validation-infrastructure)
12. [Risk Register](#risk-register-2026-09-03)
13. [Loop Discipline (verification ladder, terminal states, run receipts)](#loop-discipline-cycle-engineering-2026-08-21)
14. [Investigation Record (boot-path evidence, 2026-08-13 →)](#investigation-record-boot-path--key-evidence)
15. [Dependency/Vendoring · Build+Run · Handoff Checklist](#dependency--vendoring-notes)
16. [Revision History](#revision-history)

---

## ⭐ UR-SUCCESSION REVISION (2026-08-22) — AUTHORITATIVE FOR ALL GPU/RENDER WORK

**Decision (user-directed): implement UnleashedRecomp's techniques exactly — NO PM4,
ever.** Diff basis: `docs/handoffs/2026-08-22-ur-vs-mcla-full-diff.md`;
device-boundary ground truth: `docs/handoffs/2026-08-22-session3-device-boundary.md`.
Superseded by this revision for frame production: old "Phase 4 — GPU Context & Draw
Capture" (CP-emulation ladder), Xenia Vd semantics as frame-production requirements,
`gpu_cp.cpp` drain/doorbell role (archived infrastructure; Vd* imports become inert
plumbing).

### New Golden Rules (additive to Constraints)

11. **No PM4 in the native path.** Frame production must not read, write, drain, or
    depend on the PM4 ring, doorbell MMIO, or any CP behavior. `VdSwap` and ring
    imports become stubs exactly like UR (`kernel/imports.cpp:794`).
12. **Device-table boundary is THE boundary.** Guest rendering intent is captured by
    overriding the game's own D3D-class device methods (global-scope strong
    `PPC_FUNC(sub_XXXX)` overrides of generated weak aliases + `g_memory.InsertFunction`
    synthetic thunks past the code range), never by parsing packets.
13. **Guest thread → queue → render thread.** Device-method handlers only enqueue
    RenderCommands; a dedicated render thread owns all host GPU API calls
    (UR `UnleashedRecomp/gpu/video.cpp`:1006/315/5249 blueprint).
14. **Offline shader cache first.** Xenos microcode translates at BUILD time into a
    zstd-compressed embedded DXIL cache keyed by microcode hash; runtime DXC is
    fallback-only for cache misses.

### CP FREEZE LINE (2026-08-24, user-approved re-anchor)

Sessions 6–22 drifted into emulating the guest driver's kernel/GPU underside
(doorbell, rptr publish, progress counters, semaphores, task queues, IB
execution). That rebuilds the superseded Phase-4 CP emulator. Effective now:

1. **CP emulation is FROZEN** at current capability: TYPE0/TYPE2 skip,
   XE_SWAP, WAIT_REG_MEM consume, ME_INIT consume, INDIRECT_BUFFER recursion,
   MEM_WRITE honest writes (`gpu_cp.cpp`). It stays as the LEGACY path only,
   retired at P6′.
2. **No further opcode expansion**: no DRAW_INDX*, no SET_CONSTANT/
   LOAD_ALU_CONSTANT, no IM_LOAD* shader upload, no ME micro-engine
   semantics. Those belong to the device-boundary takeover surface, not CP.
3. **Remaining boot blocker re-scoped**: the async-task/fence system is
   kernel infrastructure required under ANY architecture. Fix it (buffer
   populator or honest task-class short-circuit) as KERNEL work, then STOP.
4. **Next active front = P4′ Device-Boundary Takeover as written**: hook the
   GuestDevice D3D-class methods (create/Present/state/draw), enqueue
   RenderCommands, native render thread consumes. Rendering intent never
   reaches the driver's submission path again — the GPU-progress wait bug
   class disappears by construction for frames.
5. Asset access (RPF VFS + 1,264-file ucode corpus) feeds the takeover's
   shader/resource needs per golden rules 12/14 - no from-scratch engine.

### CURRENT BLOCKER (2026-09-05 refresh — sessions 33–37)

Authoritative live trail: `docs/BOOT_HANDOFF.md`; ledger: `.clinerules/memory/`.

1. **Intermittent OOM fatal ~T+15s**, churn heap struct `0x82830CD8`, cap
   `0x02E7FFF0` (46.5 MB fixed, `sub_821C1BB0` has NO grow path). Corrected field
   map: +76=cap, +84=carved, +152=free — heap is ~4% used at fatal (session-35
   "97-100% full" readings were a swapped-label artifact).
2. **Prime suspect:** class allocator `sub_821DE9D8` (ppc_recomp.20.cpp) returns 0
   WITHOUT calling C1BB0 on inconsistent slab header ([slab+8] count>0 but
   [slab+12] freelist empty/garbage) → `sub_821C29A0` fast-path raise.
3. **Hook mechanism truth:** dispatcher-map SetFunction is NEVER consulted for
   guest calls. Working override = global-scope `PPC_FUNC(sub_XXXX)` weak-alias
   strong def. Live censuses: OOM-CENSUS, PHYSALLOC-CENSUS, ARENA-CENSUS.
4. **Secondary (session 34):** GPU-progress-wait class — ring put advances, guest
   progress counter never does; fix only as kernel/CP-legacy work (freeze line).
5. **Session 37 done:** Enhanced `PPC_FUNC(sub_821DE9D8)` census — full slab chain
   dump on every return-0 (up to 32 slabs, per-slab next/prev/count/freelist/owner,
   chainLen, countMatch check). Build clean.
6. **Next (session 38):** Run gate soak → analyze POOL-CENSUS FAIL# output →
   root-cause slab corruption from live data → then P4′ step 3 render thread.

External recon (web-verified 2026-09-03 — research round: ~18 sources):

**LARecomp (`github.com/mzzvxm/larecomp`) — successor of BadassBaboon/midnightclub,
runs THIS game to gameplay via ReXGlue 0.9.0. Proves our blockers are solvable.
Verified transferable intel:**
- **30 Hz fixed-timestep unlock (for later perf work):** game locks simulation to
  30 Hz; the Xenia patch makes it run double-speed. Correct fix = real measured
  frame delta injected via hooks on BOTH fixed-step paths (@0x821BDB58 /
  loc_821BDB90) PLUS the timer reset guard the Xenia patch skips — dropping the
  guard caused an audio blowout upstream.
- **Frame pacing:** frame times collapse onto a 15.625 ms grid = Windows timer
  resolution; fix = `timeBeginPeriod(1)` + vsync off + wall-clock limiter
  (deliberately NOT vblank-based).
- **vblank interrupt storm** diagnosed as the cause of long-session frame-rate
  collapse upstream — direct warning for our vsync ISR / interrupt-callback path
  (guest callback @0x82411478): add a long-session soak + interrupt-rate census
  before P4′ sign-off.
- **Guest data-patch gotcha:** patching a constant that lives in an
  `.rdata`-mapped guest page (e.g. flt_8201E7EC) throws AV once the page is
  actually populated read-only — unprotect the page first. Applies to any future
  constant patch in `patches.cpp`.
- **SDL3 input:** Win32 `PeekMessageW` never drains SDL3's queue — all message
  pumping must go through SDL3 once windowing moves.
- **Hook placement:** tuning hooks must sit on the constructor epilogue
  (0x826F5CA0 for ambient density) — post-parse code paths may never execute.
- Their remaining rendering issue is dithered alpha only (ReXGlue-side fixes
  covered car reflections + HUD glitches) — a known-issues checklist for P5′.

**XenosRecomp (`github.com/hedge-dev/XenosRecomp`) — P5.5′ blueprint, verified:**
- Directory-scan mode converts a whole shader corpus and **exports the cache as
  a `.cpp` file for direct embedding into the executable**; runtime lookup =
  **64-bit XXH3 hash** of the shader binary. DXIL compressed as-is (pair with
  zstd), SPIR-V pre-compressed with smol-v.
- Specialization constants (alpha-test flag, R11G11B10 NORMAL/TANGENT/BINORMAL
  unpack) implemented as declared-but-unimplemented functions resolved by
  compiling a tiny library at runtime and LINKING it with the shader — DXIL has
  no native specialization constants. Relevant if MCLA needs either behavior.
- Unimplemented upstream: memory export (memexport), point size — audit MCLA's
  ucode corpus for these before trusting P5.5′ coverage numbers.
- DXIL signing: the public validator **verifies and signs** DXIL (per
  DirectXShaderCompiler DXIL.rst); offline toolchain must run dxc + dxil.dll at
  build time so embedded blobs stay signed — unsigned DXIL is rejected by the
  D3D12 runtime.

**Upstream layout correction:** UR render-thread references are
`UnleashedRecomp/gpu/video.cpp` (with `gpu/cache/`, `gpu/shader/`); the kernel is
`UnleashedRecomp/kernel/` = `imports.cpp`, `xdm.cpp/h`, `heap.cpp/h`,
`memory.cpp/h`, `xam.cpp/h`, `xdbf.h`, `io/`, `function.h`, `freelist.h`. The
`video.cpp:1006/315/5249` line cites in golden rule 13 stay valid against that
path (re-diff line numbers before quoting them).

**Xenia CP semantics (src/xenia/gpu/command_processor.cc, master) — validation
oracle for the frozen legacy CP:** worker thread model; gamma ramp initialized
from `VdGetCurrentDisplayGamma` sRGB=1 defaults; TYPE-3 draw =
`VGT_DRAW_INITIATOR` with `source_select` kDMA (indexed: `VGT_DMA_BASE`/`SIZE`,
index endianness = `swap_mode`, 16/32-bit via `index_size`), kAutoIndex, and
kImmediate (UPSTREAM-UNSUPPORTED — do not emulate either).

**BadassBaboon/midnightclub** (the predecessor fork): boot-blocker-free on
rexglue; 0x825F0000–0x8260AFFF hole empty there too; ~1.7M-address stub sweep at
startup; guest facts bank (timebase 49,875,000 Hz; `clear_memory_page_state`
load-bearing; resolution_scale corrupts frustum aspects) remains valid.

### NEW TECH SCAN (2026-09-03, round 2) — transferable technology found

**RT64 (github.com/rt64/rt64, MIT) — closest cousin to our P4′/P5′; public
source; renderer of Zelda64Recomp. Transferable techniques, mapped to ladder:**
1. **Ubershaders** → zero pipeline-compile stutters. P5.5′ offline DXIL cache
   stays primary (we HAVE the 1,264-file corpus); an ubershader fallback
   eliminates cold-cache hitches for unexpected shader permutations.
2. **One contiguous VB/IB + RSP-as-compute-shader** → RT64 keeps ALL data
   untransformed in a single buffer and runs console vertex semantics (RSP) in
   a compute shader at render time. Direct P5′ analog: capture raw guest
   VB/IB bytes at the device boundary and implement Xenos vertex-fetch/FVF
   semantics as a COMPUTE SHADER instead of CPU-side translation at capture.
   Cuts CPU capture cost massively; also enables future model replacement.
3. **Bindless texture array + texcoord scaling** → P4.6′ resource model: one
   contiguous texture descriptor array makes HD texture-pack replacement
   near-free (swap slot, scale coords). Evaluate for `resource_cache.cpp`
   instead of per-texture SRVs.
4. **Extended command set encoded in NOOPs** → their enhancement mechanism;
   freeze line bans PM4 tricks, but the device-boundary equivalent is legal:
   extend RenderCommand with host-only enhancement ops when needed.

**Zelda64Recomp:** `moodycamel::ConcurrentQueue` (lock-free MPMC) between
guest threads and render thread — proven dependency candidate for P4.5′'s
`render_command_queue` (evaluate against render_queue.h before hand-rolling).
Their mod/patch mechanism = single-file recomp output linked as a static lib
with linker-priority symbol override — same class as our weak-alias overrides;
confirms our mechanism is the industry-standard one.

**N64Recomp:** LiveRecomp + `[[patches.func]]/[[patches.hook]]` toml sections =
upstream analog of our P8′ midasm question (reference for the config-format
decision). LiveRecomp itself unneeded (MCLA is a static image, no TLB code).

**LLM4Decompile (7k★; SK²Decompile two-phase, 2025-10):** local decomp models
(6.7B, x86/GCC-trained, Ghidra-integrated). PPC not natively supported — our
Ghidra-MCP + LLM workflow stays superior for PPC; adopt the two-phase IDEA in
T1 (skeleton pseudo-C first, field naming second). No local models required.

**LARecomp activity (Aug 2026):** merged BadassBaboon's fork; **ReXGlue now
0.10.0** (update references when quoting); new fixes are runtime/UI-side
(clock scaling, guest AV handler, windowing) — none address our blocker class
(their kernel semantics live inside unpublished ReXGlue).

**Assessment:** nothing here unblocks the churn-heap OOM (that stays census
work), but RT64's patterns materially improve P4.6′/P5′/P5.5′ design choices,
and moodycamel is a proven P4.5′ dependency candidate. Re-scan when RT64's
emulator-plugin or path-tracing code lands.

## SOURCE-vs-PLAN AUDIT (2026-09-03) — documented conflicts, NOT yet fixed

Full grep sweep of `src/**` against the golden rules and gates. Findings are
recorded here with file:line evidence; **none have been fixed** — each needs an
owner and run-receipt discipline when picked up. Re-run this audit after any
hook/guest-memory change.

### S1 · HIGH — Dual capture systems on `sub_82420BA8` (Golden Rule 1)
- Owner A: `gpu_device.cpp:643` — `PPC_FUNC(sub_82420BA8)` weak-alias override,
  P4′-style `CapturedDrawV1` via checked `mem.ReadU32BE`. This one actually fires.
- Owner B: `native_renderer.cpp` — `PPC_FUNC_IMPL(Hooked_Sub82420BA8)` +
  `orig_Sub82420BA8 = dispatcher->GetFunction(0x82420BA8)` (:699) feeding the old
  DrawAccumulator. Per `docs/BOOT_HANDOFF.md` the dispatcher map is NEVER
  consulted for guest calls ⇒ Owner B is **dead code that still claims the seam**.
- Plan conflict: UR-revision P5′ explicitly *replaces* the sub_82420BA8 capture
  plan with the device boundary — yet Owner A still instruments it as a live
  census and Owner B still exists.
- Fix direction (when picked up): delete Owner B's path or fold it into the
  single gpu_device override; decide whether the BA8 census survives into P5′.

### S2 · HIGH — Same dual-owner pattern on `sub_8241BD08` (GfxCmdBufSubmit)
- `gpu_device.cpp:832` weak-alias override vs `native_renderer.cpp:684`
  (`orig_GfxCmdBufSubmit = dispatcher->GetFunction(0x8241BD08)`) + hooked
  `PPC_FUNC_IMPL` wrapper (native_renderer.cpp:~77). Same dead-map issue as S1;
  the wrapper also runs `DispatchBeforeSubmit` observers that can never fire
  through the map.

### S3 · MEDIUM — Dead dispatcher-map hook layer in `native_renderer.cpp`
- `orig_Sub8241ABB8 = dispatcher->GetFunction(0x8241ABB8)` (:707) has **no
  weak-alias override anywhere in src/** ⇒ that hook can never execute.
- The whole `orig_*`/observer plumbing in native_renderer.cpp predates the P4′
  weak-alias approach and contradicts the hook-mechanism truth (CURRENT BLOCKER
  item 3). Candidate for deletion, not repair.

### S4 · HIGH — Raw guest-struct pointer overlays (Golden Rules 3 & 4)
- `native_renderer.cpp:82, 122, 152` and `patches.cpp:1005`:
  `reinterpret_cast<::MclaGpuContext*>(base + ctx_guest)` — host-pointer struct
  overlay over guest memory; fields read directly instead of through the checked
  BE accessors. Violates "reads through checked GuestMemoryView" and "no
  reinterpret_cast on guest data" even if the struct fields are `be<T>`.

### S5 · HIGH (latent) — Guest address passed as HOST pointer in VFS hooks
- `patches.cpp:787` (`hk_NtReadFile`) and `patches.cpp:800`
  (`hk_NtQueryInformationFile`): `void* buffer = reinterpret_cast<void*>(ctx.r4.u32)`
  — a 32-bit **guest** VA reinterpreted as a **host** pointer and handed to
  `mcla::vfs::hooks::*`.
- VERIFIED 2026-09-03 (`vfs_rpf.cpp:672-694`): every vfs hook
  (NtCreateFile/NtReadFile/NtQueryInformationFile/NtQueryDirectoryFile/NtClose)
  is a **no-op stub that `(void)`-discards the buffer and returns false** — the
  wrapper then falls through to the original. So there is NO live misread today;
  boot I/O flows entirely through the typed imports in `imports.cpp`.
- Why it stays HIGH: the moment anyone implements these stubs, the natural
  implementation writes straight through `buffer` as a host pointer → guest
  memory corruption/AV. The signature itself invites the violation
  (`void* buffer` instead of a guest VA + checked write).
  ACTION: audit-with-census before implementing; fix is guest-VA signature +
  Translate-then-checked-write; overlaps 2026-08-22 ship-blocker #3.

### S6 · MEDIUM — Raw typed guest access bypassing checked reads
- `imports.cpp:1969-1974`: template helper does
  `reinterpret_cast<T*>(mem.Translate(guestAddr))` then dereferences — a
  parallel unchecked read path next to the checked one.
- `imports.cpp:1716`: `uint32_t* signalState = reinterpret_cast<uint32_t*>(
  Translate(...) + 0x10)` — raw field write inside an event object.
- `imports.cpp:2156`: same pattern. Exempt: `kernel/memory.cpp` (the checked
  layer itself), `kernel/function.h` (canonical UR framework),
  `guest_thread.cpp:114` (register bit-cast).

### S7 · MEDIUM — Manual `ctx.rN` reads in `imports.cpp` (Gate 2 not fully met)
- ~20 matches: lines 48–56 (alloc import reads r4/r5 manually), **line 144
  `NtQueryInformationFile` manual wrapper — 2026-08-22 ship-blocker #3, STILL
  OPEN**, lines 2694–2727 (diagnostic logging), 1610–1614 (callback PPCContext
  synthesis — mechanism, exempt). Gate 2's "zero manual ctx.rN reads" holds
  only for typed import bodies; the wrapper/diagnostic tail remains.

### S8 · LOW — `src/hooks/registry.cpp` does not exist
- `.clinerules/coding-standards.md`: "Register hook chains in
  `src/hooks/registry.cpp` only." Reality: registrations are spread across
  `patches.cpp` (weak-alias overrides + hotpatch wraps), `gpu_device.cpp`,
  `capture_hooks.cpp`, `task_dispatch_trace.cpp`, and the dead
  `native_renderer.cpp` dispatcher calls. Either build the registry or amend
  the rule to name `patches.cpp` as the registration point; until then the rule
  is unenforceable.

### S9 · INFO — Accepted `reinterpret_cast` exceptions (inventory, no action)
- `kernel/memory.cpp` — the checked accessor layer itself (must touch raw bytes
  once). `kernel/function.h` — canonical UR framework code.
- Host-local BE byte buffers with explicit `__builtin_bswap32`:
  `imports.cpp:435-438` (XAM media info), `imports.cpp:2414-2418` (cert),
  `imports.cpp:3505-3507` (XEX2 header) — host arrays, not guest aliasing.
- `native_renderer.cpp:133` float bit-cast of `ctx.f1` (register, not memory).
- Test/validator files (`phase0_validator.cpp`, capture/xtr dump validators);
  host-side files (`d3d12_backend.*`, `frame_trace.cpp`, `boot_host.cpp`,
  `app.cpp`); `patches.cpp:159-176, 333, 423-630` (HOST-module IAT / hotpatch
  thunk parsing, not guest memory).

### Audit-compliant checks (no action)
- `gpu_cp.cpp`: frozen opcode set only (TYPE0/TYPE2 skip, XE_SWAP, WAIT_REG_MEM,
  ME_INIT, INDIRECT_BUFFER recursion, honest MEM_WRITE) — **no** DRAW_INDX* /
  SET_CONSTANT / LOAD_ALU / IM_LOAD expansion. Freeze line respected.
- `renderer_mode` default = `"legacy"` (`renderer_mode.cpp:8`), fallback Legacy.
- Hook purity: zero D3D12 calls in `capture_hooks.cpp` / `gpu_device.cpp` /
  `renderer_hook_dispatch.cpp` (single mentions are confirming comments:
  capture_hooks.cpp:375, gpu_device.cpp:330).
- `patches.cpp` censuses: one real definition each (sub_821C29A0, sub_821C1BB0,
  sub_821DE9D8, sub_82130B50); apparent grep duplicates are comments. No
  weak-alias address claimed by two translation units.
- `imports.cpp` GUEST_FUNCTION_HOOK address set is disjoint from the PPC_FUNC
  overrides in gpu_device/patches/task_dispatch_trace. Vd* hotpatch **observers**
  in patches.cpp coexist with typed Vd* imports — proven inert for guest calls,
  but same dead-mechanism class as S3.

### Disposition
- S1–S3 → casualty list of the P4′/P5′ transition; sweep when the boot blocker
  closes (dead/duplicated code — cannot regress boot, but do NOT touch
  mid-blocker per freeze-line discipline).
- S4–S6 → `security-auditor` review before any P5′ capture trust.
- S5 → boot-adjacent (NtReadFile path): audit with a census, not a blind rewrite.
- S7 → close together with ship-blocker #3 in one pass.
- S8 → docs-writer decision: amend the rule or file a P7′ work item.

### Revised Phase Ladder

| Phase | Scope | Gate |
|---|---|---|
| **P4′ Device-Boundary Takeover** | Hook create/Present/state/draw device methods; GuestDevice struct header; retire manual seeding | Real geometry+state flows through ≥1 draw + full state set via host impls; zero PM4 emission during frames; **long-session soak (≥10 min) with interrupt-rate census — upstream (LARecomp) hit a vblank interrupt storm that collapsed frame rate over time** |
| **P4.5′ Render Thread & Queues** | Blocking command queue + copy queue + render-thread ownership of all D3D12 calls | Guest threads only enqueue; frame pacing owned by render thread |
| **P4.6′ Resource Model** | Guest{Texture,Buffer,Surface} in guest heap; deferred destruction; lock/unlock; dirty tracking (UR video.cpp:177–328 blueprint) | Create/destroy/lock stress passes with no leaks or stale-resource faults |
| **P5′ Real Draws via Device Boundary** | VB/IB/format/shader capture from redirected device methods (replaces sub_82420BA8 capture plan); pixel-hash parity vs legacy replay | 3–5 representative captures rasterize identically (pixel diff < 1 px) |
| **P5.5′ Offline Shader Cache** | Corpus = the EXISTING `shader_dumps/shaders/*.ucode.*` microcode (1,264+ files, already translated via custom XenosRecomp). Steps: extend validator dir-scan filter to raw ucode; run XenosRecomp dir-scan mode → **embedded `.cpp` cache, 64-bit XXH3 keys** (upstream-verified); sign with dxc+dxil.dll at build time; vendor zstd (+ smol-v if SPIR-V ever needed) | Boot+gameplay with ZERO runtime-DXC compilations on warm cache; G-CORPUS-* gates flipped enforced against ucode corpus; corpus audited for upstream-unimplemented features (memexport, point size) |
| **P6′ Native Default & Legacy Retirement** | `renderer_mode=native` default; Vd*→stubs; DELETE InitGpuBackendManual/GpuContextPoller/manual seeding, legacy CP path, **gpu_cp.cpp (D3)** | Headless regression: boot → start menu reachable, zero crashes, 10-min soak clean, every frame native, zero PM4 — no race required (**D6**) |
| **P7′ Build Env Modernization** | CMakePresets.json pinning clang-cl+lld; de-hardcode VS/SDK paths (CMakeLists.txt:48–56); codegen via add_custom_command from config/mcla_xenonrecomp.toml (kills drift + hand-listed TUs); vcpkg/FetchContent manifest; **if any `.rc` resources are added: do NOT use `enable_language(RC)` with clang-cl — MS rc.exe cannot parse clang line markers (RC2019, upstream LARecomp bug)** | Clean configure+build on a second machine without prose instructions |
| **P8′ Codegen Config Completion** | Survey invalid_instructions candidates (exception-frame-handler ptrs, cf SWA.toml:76–82); DECISION GATE: adopt midasm_hook equivalent (~150 sites in SWA.toml:84–1155) vs per-function-overrides-only — decision shapes P9/state work; SKIP_LR/SKIP_MSR flip ONLY if midasm adopted (**midasm_hook mechanism verified against upstream XenonRecomp README 2026-09-03: name/address/registers/jump_address_on_true/return semantics; hook signature takes only named registers by C++ reference, not extern "C"**) | Documented decision + survey artifacts committed |
| **P9′ Kernel Surface Completion** | Xam content/save/achievement surface as boot demands (UR xdbf/xam.cpp reference) | Whatever boot progression requires, nothing speculative |

**Execution order:** P4′ → P4.5′ may start once ≥1 real draw flows · P4.6′ parallel
with P5′ · P5.5′ anytime after P4′ · P7′/P8′ independent tracks · P6′ last.

**Status within revised ladder:**
- **P4′ step 1 ✅ DONE (2026-08-22):** create-hook live (`src/gpu_device.cpp`,
  global-scope override of `sub_82413588` — r8 read BEFORE original call), layout
  dumped (dirtyFlags[8]@0x00, RS table[0x65]@0x40 with default-stub 0x82130000,
  sampler table@0x1D4, ring ptrs@0x30), publish chain verified
  (`*(0x82000864)=0xBE010100→device`), redirect seam proven
  (`redirected 10/101 -> 0x827CD054, readback=ok, thunkResolved=true`).
  Two binding gotchas documented: override must be GLOBAL scope (namespaced symbol
  never binds); r8 clobbered after passthrough.
- **P4′ step 2 ✅ DONE (2026-08-23):** packet capture v2 at `sub_82411640`.
  Reverser-pinned semantics: 640 = push-buffer SPACE RESERVER (`r5[0]`=requested
  bytes → returns ring-window VA in r3, writes back consumed bytes); RS FP-tables
  confirmed dead; packed stack pairs = stale garbage. Deferred-drain capture
  yields REAL PM4 (type-3 WAIT_REG_MEM `C0043C00`, batch tokens `00000A31`,
  type-0 writes). 640 fires ~4×/boot → init/state seam only; per-frame draw seam
  is OPEN (candidates: Function_8241E498 VSync worker, sub_82429328/9428/96E8,
  sub_82411840 consumer family incl. sub_82420BA8). Handoff:
  `docs/handoffs/2026-08-23-session4-packet-capture.md`.
- **Shader corpus decode CLEAN (2026-08-23):** LE-reversal fix for `.ucode.bin.*`
  (host-endian dumps) + text-companion skip → binary rollup 806/806,
  unknown/oob/returns = 0/0/0. G-XENOS-DECODE-CLEAN + G-CORPUS-* validators now
  ENFORCED and green.
- Everything else ❌ NOT STARTED under the revised ladder.
- Old-ladder statuses below are HISTORICAL (pre-revision).

### Automated Phase Gates (B2S discipline adopted 2026-08-22)

Runner: `tools\run_phase_gates.ps1 -SoakSeconds 60` → build → all validators →
headless boot soak → log assertions → JSON report at `build\gates\<date>-gate-report.json`
(+ `last-run-log-slice.txt`). Exit 0 = all enforced gates pass.

Laws adopted from B2S (`E:\top secret\docs\milestones.md`):
1. **Harness first** — G0 exists and runs green on HEAD; it is the pass/fail safety
   net every later change must keep green.
2. **Numbers, not judgement** — every gate has machine-checked metrics.
3. **Regression blocks features** — an enforced gate that was green and turns red is
   flagged `[REGRESSION]` and fails the run; feature work stops until fixed.
4. **Dated artifacts persist** per run (commit + timestamp embedded).
5. Shader-corpus validators were `tracked` because their dir-scan filter only
   recognized Rockstar `.fxc` containers. **Correction (2026-08-22): translation
   is NOT capture-blocked** — the existing `shader_dumps/shaders/*.ucode.*` corpus
   (raw Xenos microcode) already translates through our custom XenosRecomp
   pipeline. Queued fix: extend the validators' dir-scan filter to accept raw
   ucode, then flip `G-CORPUS-*` from tracked to enforced against the existing
   corpus. Finding real `.fxc` containers inside RPF archives / `.xrsc` resources
   stays an open RECON item, not a gate dependency.

Enforced set today: G-BUILD · G-VALIDATORS · G-PHASE0 (13/13) · G-BOOT-SOAK ·
G-VSYNC-CHAIN · G-P4-CREATE-HOOK. Tracked: G-CORPUS-* (×3) · G-P4-RS-THUNK-HITS ·
G-P6-PM4FREE-FRAMES. New gates join the runner as phases start; perf-style metrics
use baseline-then-delta targets instead of guessed absolutes.

Operational rule: only ONE mcla.exe instance may run during a gate pass — concurrent
instances share `build\cache\mcla.log` and produce false regressions.

### Debug Surface for the Human (requested 2026-08-22)

Not just agent-facing CLI gates — ship a visible debug layer alongside native mode:
- **In-app overlay/panel** (SDL second window or in-game overlay): live VSync frame
  counter, guest thread states, device pointer + GuestDevice slot ownership, ring
  put/rptr positions, queue depths (after P4.5′), latest gate-report summary.
  Toggled via cvar (`debug_overlay=1`).
- **Gate report viewer**: render newest `build\gates\*.json` pass/fail with numbers
  in the same overlay.
- Lands with P4.5′ render-thread work (it owns the data); overlay buildable any time
  after P4′ step 2 proves a runtime hit.

### Decisions Locked (user, 2026-08-22)

| # | Decision | Choice |
|---|---|---|
| D1 | Debug surface | Easiest form that works — in-present overlay first (we own present), upgrade later |
| D2 | Frame pacing | Ship faithful 60fps; **HFR 120+ = explicit FUTURE phase**, not a launch goal |
| D3 | gpu_cp.cpp | **DELETE** at P6′ retirement (git history preserves it) |
| D4 | Render API | **D3D12 only** — no RHI abstraction layer |
| D5 | Asset IO | **Keep host-side RPF parsing** (P3 depends on it) |
| D6 | Input automation | **None.** This is a graphics problem; logic is fine. Gates require boot → start menu reachable headless, nothing more |
| D7 | midasm_hook | **Decide after survey** (P8′ gate stands as written) |
| D8 | SKIP_LR/SKIP_MSR | **Keep current ctx layout** (no 179-TU revalidate for cosmetic parity) |
| D9 | HLE cut line | **Override at device methods now**; full create-time bypass = post-success improvement |
| D10 | Faithfulness | **Preserve original behavior now**; fixes/enhancements = improvement phase after finish |
| D11 | Xam scope | **Boot+play minimal now**; saves/achievements/full-Xam later |

**Post-completion backlog (explicitly deferred):** full CreateDevice bypass ·
bug-fixes & visual enhancements · HFR 120+ support · full Xam (saves, xdbf,
achievements) · Vulkan/RHI consideration.

---

## No-ReXGlue Mandate (2026-08-20)

**The project must not depend on the ReXGlue SDK.** UnleashedRecomp ships no such
SDK; it uses standard third-party packages (SDL3, fmt, spdlog, etc. via vcpkg).
Therefore:

1. **No `rexglue-sdk/` directory.** Delete it. Vendored third-party dependencies
   (SDL3, fmt, spdlog, toml++, xxhash, o1heap, DXC, simde) live in `third_party/`
   or the `.research/*/thirdparty/` trees — never behind a rexglue wrapper.
2. **No `rex::` API surface.** No `rex::cvar`, `rex::graphics::*`,
   `rex::chrono::Clock`, `rex::memory`, or any `rex/` header. Replace with local
   equivalents (`mcla::cvar::CVarSystem` already exists in `src/cvar.h`).
3. **No `rexruntime.lib`.** The SDK's runtime library is never linked.
4. **No Tracy.** The project does not use Tracy (no source references); remove the
   TRACY_* compile definitions and include dirs.
5. **No REXCVAR/REXLOG SDK macros.** The local compat aliases in `src/cvar.h`
   and `src/logging.h` are removed; call sites use `MCLA_CVAR_*` / `MCLA_LOG_*`.
6. Golden Rule: hooks and kernel code must not depend on any rexglue type or
   runtime symbol.

## Purpose

Replace the Xenos-command-processor rendering path in the recompiled Xbox 360
game with a native Direct3D 12 renderer, and prove the recompiled MCLA guest
code boots end-to-end on PC. Three sub-goals, one pipeline:

1. **ABI migration** — move the recompiled PPC runtime from the ReXGlue ABI to
   the XenonRecomp `PPC_FUNC`/`PPC_LOOKUP_FUNC` ABI with checked
   `GuestMemoryView` access.
2. **Boot proof** — guest code boots from XEX entry (`_xstart`, `0x821322B8`)
   through init and import-slot resolution to the game main loop, then reaches
   a real `VdSwap`/present call.
3. **Native GPU** — capture guest rendering intent at the high-level draw
   boundary and execute it as native D3D12 work. The default `renderer_mode`
   stays `legacy` until the phase gates pass.

---

## Core Architectural Decision (2026-08-19, Revalidated)

**Kernel boundary strategy = UnleashedRecomp framework, NO ADAPTATION.**

The kernel/import layer **must exactly mirror** `.research/UnleashedRecomp/kernel/`
(`imports.cpp`, `GuestThread`, `KernelObject` subclasses, `xdm.h` identity
handles, `function.h` typed-arg machinery, `heap.h` guest physical heap). Where
MCLA's semantics differ from UnleashedRecomp, the reference is the documented
Xbox 360 behavior — not the port verbatim. **Do not invent a third model.**

### Canonical Framework Rules (Non-Negotiable)

1. **Identity handles are canonical.** Handle = guest address of the object in
   the guest physical heap. `GetKernelObject(handle) = Translate(handle)`.
   `GUEST_INVALID_HANDLE_VALUE = 0xFFFFFFFF`. Objects allocated via
   `g_userHeap.AllocPhysical<T>()`. The plan's prior "host-heap handle table"
   (`unordered_map` + index) is a **non-framework third model** — eliminate it.

2. **Lazy-wrap via `QueryKernelObject`.** Checks `WaitListHead.Flink != 'XBOX'`
   (OBJECT_SIGNATURE), creates host wrapper, caches wrapper's guest address in
   `.Blink`. Subsequent calls return cached wrapper. This is how the guest
   interops handles as pointers (e.g., `KeSetEvent(device+16)`).

3. **Typed-arg `GUEST_FUNCTION_HOOK` one-liners.** Every import becomes:
   ```cpp
   uint32_t NtCreateEvent(be<uint32_t>* handle, void* objAttr, uint32_t eventType, uint32_t initialState) { ... }
   GUEST_FUNCTION_HOOK(__imp__NtCreateEvent, NtCreateEvent); // ONE LINE
   ```
   The macro expands to `PPC_FUNC(subroutine) { HostToGuestFunction<function>(ctx, base); }`
   which auto-translates r3-r10, f1-f13, stack args (at `r1+0x54+(arg-8)*8`).

4. **`KernelObject::Wait(uint32_t timeout)` — single parameter.** Alertability
   (`STATUS_USER_APC`) is decided in the import wrapper (`KeWaitForSingleObject`,
   `NtWaitForSingleObjectEx`), not in `KernelObject`.

5. **`KeWaitForMultipleObjects` generation counter.** `g_keSetEventGeneration`
   increments on `KeSetEvent`; `WAIT_ANY` uses it to avoid polling all objects.

6. **Critical sections = `std::atomic_ref` on guest memory.** `XRTL_CRITICAL_SECTION`
   is 28 bytes: `XDISPATCHER_HEADER` (16) + `LockCount@0x10` + `RecursionCount@0x14`
   + `OwningThread@0x18`. MCLA's prior `OwningThread@0x10` is Windows-style — wrong.

7. **`ExCreateThread` = `GuestThread::Start` pattern.** Allocates PCR+TLS+TEB+Stack
   per thread in guest heap, sets up `r1`/`r13`. Not 3 hardcoded addresses.

8. **`ObReferenceObjectByHandle` returns handle as pointer.** `*object = handle; return 0;`
   If guest dereferences the returned value, it must be a valid guest address.

9. **First-page NOACCESS trap.** 4 GB `VirtualAlloc` at `0x100000000`, first page
   `PAGE_NOACCESS` to catch null derefs.

10. **Vd imports match Xenia `xboxkrnl_video.cc` semantics** (pinned 2026-08-19):
    - `VdInitializeRingBuffer(ptr, size_log2)`: `r3`=phys addr, `r4`=log2 size, ring size=`1<<(size_log2+3)`, zero ring
    - `VdEnableRingBufferRPtrWriteBack(ptr, block_size_log2)`: sets CP_RB_RPTR_ADDR (0x70C), freq=`1<<block_size_log2>>2`
    - `VdGetSystemCommandBuffer(p0, p1)`: `p0.Zero(0x94)`, write `0xBEEF0000@p0`, `0xBEEF0001@p1`
    - `VdQueryVideoMode(mode)`: 1280×720, non-interlaced, widescreen=1, hi_def=1, 60 Hz, NTSC
    - `VdQueryVideoFlags()`: widescreen?1 | width≥1280?2 | width≥1920?4
    - `VdInitializeEngines(unk, cb, arg, pfp, me)`: `r3=0x4E810000`, returns 2
    - `VdSwap(buf, fetch, unk2, unk3, unk4, fbuf, fmt, cs, w, h)`: writes `PM4_XE_SWAP` into ring
    - `VdSetGraphicsInterruptCallback(cb, user)`: registers GPU interrupt callback

### Import Pattern (Exact Framework)

```cpp
// In imports.cpp — typed host function with native signature
uint32_t NtCreateEvent(be<uint32_t>* handle, void* objAttr, uint32_t eventType, uint32_t initialState)
{
    *handle = GetKernelHandle(CreateKernelObject<Event>(!eventType, !!initialState));
    return STATUS_SUCCESS;
}

// ONE LINE registration at bottom of imports.cpp
GUEST_FUNCTION_HOOK(__imp__NtCreateEvent, NtCreateEvent);
```

**No manual register reads.** `HostToGuestFunction` handles r3-r10, f1-f13,
stack, endianness (`be<T>`), pointer translation (`Translate`/`MapVirtual`).

### Unimplemented Imports

One-line stubs with `LOG_UTILITY("!!! STUB !!!")` — the game tolerates
non-critical paths. Do not implement until boot path demands it.

---

## Current State (2026-08-19, Post-Regression)

- **ABI migration: largely complete.** Host sources compile clean (44/44
  targets). `mcla.exe` links generated PPC TUs, installs 46,041 `PPCFuncMappings`,
  installs kernel import stubs, boots on worker thread under SEH.
- **Phase 0 gate: PASS** — `phase0_validator.exe` 9/9 framework unit tests;
  full build clean (clang-cl 19.1.7 + Ninja, RelWithDebInfo).
- **Boot regression (2026-08-19).** Mass port of ~150 UnleashedRecomp imports
  applied **incorrectly** — used raw `uint32_t Foo(PPCContext&, uint8_t*)`
  signatures, manual register reads, host-heap handle table, two competing
  implementations per import. Crashed at entry: `addr=0x90`, `callerLR=0x90000000`,
  `lock cmpxchg [rsi], ecx` (null + 0x90 deref in recompiled atomic op).
- **Boot regression FIXED (P0, 2026-08-19).** Root cause = two bugs:
  (A) `ctx.gpr[N]` register mis-mapping (index ≠ register under
  `PPC_CONFIG_NON_*_AS_LOCAL` union layout — `gpr[3]` aliased **r5**, `gpr[13]`
  read unaliased padding). Fix: all `ctx.gpr[N]` → named `ctx.rN` (232 sites +
  `static_assert` layout guard in `ppc_context.h`).
  (B) NULL `GuestMemoryHeap` base in main app path (initialized only by
  `phase0_validator`). Fix: `GuestMemoryHeap::Adopt(base, size)` wired from
  `boot::LoadAndPrepare` (adopts boot host's 4 GiB window).
  **Validated:** build clean; `mcla.exe` boots `default.xex`, survives 75 s at
  ~0% CPU (idle in host wait, not spinning, not faulting).
- **Phase 1 (Critical Imports): ACTIVE but WRONG FRAMEWORK.** 18/28 critical
  imports "implemented" but on the wrong framework (host-heap table, manual
  register reads, two competing implementations). Must be **rewritten on the
  canonical framework**.
- **Native renderer (old Phase 3–5): complete for synthetic data.**
  `backend_validator` + `phase3_validator` CLEAR; `renderer_mode=native` draws
  synthetic triangle. Guest VB/IB capture blocked on boot reaching `VdSwap`.
- **Framework recheck vs UnleashedRecomp (2026-08-19):** CONFIRMED — the
  canonical framework uses identity handles, typed-arg hooks, lazy-wrap,
  single-param `Wait`, generation counter. MCLA's current code violates all
  of these. **No adaptive model — full migration required.**

---

## Definition of Done (Boot)

- Guest code reaches a real game function that calls `VdSwap` / presents in
  `mcla.exe`, deterministically.
- No `READ @0x0` at slot-dispatch. `0x8285FEA0` resolves to a validated target
  before `sub_821BD618` dispatches, and every dispatched callee has a non-NULL
  `PPC_LOOKUP_FUNC` table entry.
- Kernel/import stubs return values consistent with documented 360 semantics
  (checked via `.research/` recomp projects + Xenia), so guest branches off bad
  `r3` garbage stop firing the dirty-disc handler.
- **All imports use typed-arg `GUEST_FUNCTION_HOOK` one-liners.** No manual
  `ctx.rN` reads in `imports.cpp`.
- **Single handle space:** identity handles (guest-VA) for kernel objects.
  No host-heap `unordered_map` index handles.
- **`QueryKernelObject` lazy-wrap** operational for Event/Semaphore/Thread.
- Boot remains deterministic; tree builds clean (ninja, clang-cl, RelWithDebInfo,
  zero errors); default `renderer_mode` stays `legacy`.

---

## Constraints / Golden Rules

- `generated/` is input. Never patch recompiled sources. (`mcla_manifest*.toml`
  edited via node tooling only.)
- One hook owner per guest address. Use the composable dispatcher.
- Hooks only capture state; they must not call D3D12 or depend on
  `rex::graphics::RegisterFile`.
- Guest pointers = 32-bit guest addresses + bounds (`GuestAddr`/`GuestPtr<T>`),
  never raw host pointers; reads through checked `GuestMemoryView` with explicit
  endian reads (`ReadU16BE`, `ReadU32BE`, `ReadF32BE`). No `reinterpret_cast`
  on guest data.
- No invented draw/boot data. Every struct field and return value is researched
  before trust.
- Do not introduce a second PPC ABI; do not optimize memory access yet
  (correctness first).
- A frame is native *or* legacy, never mixed — except explicit capture-only mode.
- Build: Ninja + clang-cl for **both** C and CXX, RelWithDebInfo; requires VS
  BuildTools `vcvars64.bat` on PATH (`build/_build_mcla.bat`). Delete `build/`
  when switching compilers. Zero errors expected.

---

## Phase Plan

### Phase 1 — ABI Migration (XenonRecomp)

**Goal:** Move host + generated code onto the `PPC_FUNC` ABI with checked
`GuestMemoryView` memory access.

| Step | Description | Status |
|------|-------------|--------|
| 1.1 | `src/ppc_config.h` mirrors generated geometry | ✅ DONE |
| 1.2 | `src/ppc_context.h` ports XenonRecomp `ppc_context.h` (`<simde/x86/...>`) | ✅ DONE |
| 1.3 | `src/app.h` includes new headers; `mcla::PPCContext`/`mcla::native::PPCContext` alias `::PPCContext` | ✅ DONE |
| 1.4 | Route `PPC_LOAD/STORE/MM` through `GuestMemoryView` (Read/Write Guest `U8/U16/U32/U64BE`); added `WriteU16BE` | ✅ DONE |
| 1.5 | Include swap: `generated/default/mcla_init.h` → `generated/ppc_xenon/ppc_recomp_shared.h`; migrate `REX_FUNC`/`DECLARE_REX_FUNC`/`__imp__` to `PPC_EXTERN_FUNC`/`PPC_FUNC_IMPL` | ✅ DONE |
| 1.6 | CMake: attach `generated/ppc_xenon` to the `mcla` target | ✅ DONE |
| 1.7 | Codegen with real ABI header (recompile so `generated/ppc_xenon/ppc_context.h` is full ABI, not 38-byte stub) | ⚠️ OPEN — XenonRecomp CLI: `XenonRecomp.exe [config.toml] [path/to/ppc_context.h]`. Run with `src/ppc_context.h` and reconcile `mcla_xenonrecomp.toml` (full recompile, 179 TUs) vs temp no-functions config |
| 1.8 | setjmp/longjmp addresses for MCLA still unlocated (commented out in `mcla_xenonrecomp.toml`); resolve before relying on `PPC_LOOKUP_FUNC` dispatch crossing setjmp | ✅ RESOLVED (2026-08-20) — scanned decompressed PE: no `__imp__setjmp`/`__imp__longjmp` imports, no Microsoft-CRT setjmp/longjmp code pattern in `.text`, no `_setjmp`/`_longjmp` symbols. MCLA uses SEH (`__C_specific_handler`). Leaving addresses unset (0) is correct |

**Gate 1:** Host, hooks, generated, and link all build clean (zero errors) under
vcvars64 + Ninja + clang-cl + RelWithDebInfo; `renderer_mode` stays `legacy`.

---

### Phase 2 — Kernel Framework Foundation (CANONICAL FRAMEWORK)

**Goal:** Build the **exact** UnleashedRecomp kernel framework. Replace ALL
hand-written stubs, host-heap handle table, and manual register reads.

| Step | Description | Status | Validation |
|------|-------------|--------|------------|
| 2.1 | Guest physical heap: 4 GB `VirtualAlloc` at `0x100000000`, first page NOACCESS; `MapVirtual`/`Translate` | ⚠️ PARTIAL (has heap, missing NOACCESS) | Unit test: null deref traps; round-trip guest↔host pointers |
| 2.2 | `PPCContext` struct mirroring PPC register file (XenonRecomp layout) | ✅ DONE | Compile check; existing recompiled code uses it |
| 2.3 | `GUEST_FUNCTION_HOOK` macro + `HostToGuestFunction` / `ArgTranslator` machinery (from `function.h`) | ⚠️ PARTIAL (MCLA has own impl, not framework's) | Unit test: hook a simple import, verify typed args received |
| 2.4 | `KernelObject` hierarchy: `Event`, `Semaphore`, `Thread`, `Timer`, `File` derive from `KernelObject` with `virtual uint32_t Wait(uint32_t timeout)` | ⚠️ PARTIAL (MCLA has `Wait(timeoutMs, alertable)` — wrong signature) | Unit test: create event, signal, wait returns success |
| 2.5 | **Identity handles:** `GetKernelObject(handle) = Translate(handle)`; `QueryKernelObject` lazy-wrap with `OBJECT_SIGNATURE 'XBOX'` in `WaitListHead.Flink` + host wrapper cached in `.Blink`; `GUEST_INVALID_HANDLE_VALUE = 0xFFFFFFFF` | ❌ NOT DONE (MCLA uses host-heap index handles) | Unit test: create event → handle is guest VA → `ObReferenceObjectByHandle` returns same VA |
| 2.6 | TLS/PCR emulation: `r13` = PCR/TLS base, `r1` = stack per guest thread; `GuestThread::Start` allocates PCR+TLS+TEB+Stack in guest heap | ⚠️ PARTIAL (MCLA has TLS but not GuestThread pattern) | Verify `r13` points to valid thread block; `ExCreateThread` spawns real guest threads |
| 2.7 | **Delete `kernel_stubs_body.inc` and MCLA's `HandleTable`/`KernelObject`**. Replace ALL imports with typed-arg `GUEST_FUNCTION_HOOK` one-liners ported from UnleashedRecomp `imports.cpp` (audited against 360 semantics). | ❌ NOT DONE (MCLA has 247 imports calling `mcla::kernel::` but with wrong framework + shadowed by inline stubs) | Build clean; zero `reinterpret_cast` on guest data; zero manual `ctx.rN` reads in `imports.cpp` |
| 2.8 | `g_keSetEventGeneration` counter for `KeWaitForMultipleObjects` WAIT_ANY | ❌ NOT DONE | Unit test: multi-handle wait returns correct index |

**Gate 2:** ✅ **MUST PASS** — `mcla.exe` builds with canonical framework;
`phase0_validator.exe` runs 13/13 framework unit tests (updated for identity
handles). Build clean with clang-cl 19.1.7 + Ninja.

---

### Phase 3 — Critical Import Implementations (Boot Path) — ACTIVE

**Goal:** Implement/fix the imports needed for boot to reach `VdSwap` **on the
canonical framework**. Each import = typed host function + one `GUEST_FUNCTION_HOOK`
line, audited against 360 semantics (UnleashedRecomp + Xenia).

| Import | Priority | Status | Notes |
|--------|----------|--------|-------|
| `NtCreateEvent` / `NtWaitForSingleObjectEx` / `KeSetEvent` | Critical | ❌ REWRITE | Async I/O chain core. Identity handles. `manualReset = !eventType`. |
| `ExCreateThread` | Critical | ❌ REWRITE | `GuestThread::Start` pattern: allocate PCR+TLS+TEB+Stack per thread in guest heap. |
| `NtWaitForMultipleObjects` | Critical | ❌ REWRITE | Full multi-handle wait. |
| `XMsgStartIORequest` | Critical | ❌ REWRITE | Overlapped signal + I/O worker queue. |
| `XMsgCancelIORequest` | Critical | ❌ STUB | I/O cancellation path. |
| `KeWaitForSingleObject` | Critical | ❌ REWRITE | Single-handle wait; alertability in wrapper. |
| `KeWaitForMultipleObjects` | Critical | ❌ REWRITE | Generation counter pattern for WAIT_ANY. |
| `KeResetEvent` | Critical | ❌ REWRITE | Real reset via `QueryKernelObject`. |
| `KeInitializeSpinLock` | Critical | ❌ STUB | Spinlock init (guest memory). |
| `KfAcquireSpinLock` / `KfReleaseSpinLock` | Critical | ❌ REWRITE | Interlocked CAS on guest memory (`g_ppcContext->r13.u32` as owner). |
| `NtCreateFile` / `NtReadFile` / `NtClose` | Critical | ❌ REWRITE | Full file I/O with path decode via `file_system.cpp`. |
| `ObReferenceObjectByHandle` | Critical | ❌ REWRITE | **Identity-handle model: `*object = handle; return STATUS_SUCCESS;`** (guest dereferences handle as pointer — proven). |
| `VdInitializeEngines` | Critical | ❌ REWRITE | Xenia: `r3=0x4E810000`, returns 2. Must fully init GPU context (spinlocks at `+0x4148`, `+0x4158`, cmd buffer at `+0x30`/`+0x38`, present callback at `+0x40A0`). **No manual seeding.** |
| `VdSetGraphicsInterruptCallback` | Critical | ❌ REWRITE | Spawns VSync thread, registers callback. **No manual seeding of `0x827BD6E4` etc.** |
| `VdSetSystemCommandBufferGpuIdentifierAddress` | Critical | ❌ STUB | GPU init plumbing. |
| `MmGetPhysicalAddress` | Critical | ❌ STUB | Physical addr translation (identity on flat window OK). |
| `VdInitializeRingBuffer` | Critical | ❌ REWRITE | GPU ring buffer setup; Xenia: `r3`=phys addr, `r4`=log2 size, size=`1<<(log2+3)`, zero ring. |
| `VdEnableRingBufferRPtrWriteBack` | Critical | ❌ REWRITE | GPU ring buffer write-back; Xenia: CP_RB_RPTR_ADDR 0x70C, freq=`1<<blksz>>2`. |
| `VdQueryVideoMode` | Medium | ❌ REWRITE | Xenia: 1280×720, non-interlaced, widescreen, hi_def, 60 Hz. |
| `VdQueryVideoFlags` | Medium | ❌ REWRITE | Xenia: widescreen?1 \| width≥1280?2 \| width≥1920?4. |
| `XamInputGetState` | Medium | ✅ DONE | Returns hardcoded START-pressed state. |
| `NetDll_XNetStartup` | Low | ✅ DONE | Returns 0 (avoids fatal halt). |
| `XamGetSystemVersion` | Low | ❌ STUB | Returns constant. |
| `XamNotifyCreateListener` | Low | ❌ STUB | Notification listener. |
| `XexGetModuleHandle` | Low | ❌ STUB | Module lookup. |

**Immediate Execution Order (2026-08-19, Authorized):**

1. **P0-FixA:** ✅ DONE — `ctx.gpr[N]` → named `ctx.rN` (232 sites) + `static_assert` layout guard in `ppc_context.h`.
2. **P0-FixB:** ✅ DONE — `GuestMemoryHeap::Adopt(base, size)` wired from `boot::LoadAndPrepare`.
3. **P1 (Framework Rewrite):** ⚠️ **START HERE** — Rewrite kernel framework to canonical UnleashedRecomp (Phase 2 steps 2.1–2.8). This replaces the broken host-heap table, manual register reads, and shadowed imports.
4. **P2 (Critical Imports on Canonical Framework):** Port each critical import from UnleashedRecomp `imports.cpp` as typed-arg `GUEST_FUNCTION_HOOK` one-liners, audited against Xenia/360 semantics.
   - Start with: `NtCreateEvent`, `KeSetEvent`, `ObReferenceObjectByHandle`, `Rtl*CriticalSection`, `KeDelayExecutionThread`, `MmAllocatePhysicalMemoryEx`, `VdGetSystemCommandBuffer`, `HalReturnToFirmware`, `MmQueryAllocationSize`.
   - Then: `ExCreateThread` (GuestThread pattern), `KeWaitForMultipleObjects` (generation counter), `VdInitializeRingBuffer`, `VdEnableRingBufferRPtrWriteBack`, `VdInitializeEngines`, `VdSetGraphicsInterruptCallback`, `VdQueryVideoMode`, `VdQueryVideoFlags`.
5. **P3 (Dead Import Resolution):** Remove ~37 dead/shadowed imports — one handle space, no inline stubs in `kernel_stubs_body.inc`. Delete invented GPU-context seeding.

**Gate 3:** ❌ **NOT MET** — Boot does not yet reach `VdSwap` on canonical framework. Crash/gate evidence recorded in Investigation Record.

---

### Phase 4 — GPU Context & Draw Capture Completion

> ⛔ **SUPERSEDED (2026-08-22, UR-Succession Revision — see top of file).**
> This is the retired CP-emulation ladder. Do NOT implement. Frame production
> goes through **P4′ Device-Boundary Takeover** (Revised Phase Ladder above).
> The CP drain machinery stays LEGACY-only under the CP FREEZE LINE and is
> deleted at P6′. Kept below for the Investigation Record's audit trail.

**Goal:** Complete GPU context initialization so `Function_82419718` processes
the command buffer and calls the present callback.

| Step | Description | Status | Validation |
|------|-------------|--------|------------|
| 4.1 | `VdInitializeEngines` detour calls recompiled impl → fully initializes GPU context (spinlocks at `+0x4148`, `+0x4158`, cmd buffer at `+0x30`/`+0x38`, present callback at `+0x40A0`) | ❌ NOT STARTED | GPU context fully populated; no manual seeding |
| 4.2 | VSync callback (`0x82411478`) → second-level callback (`Function_82419718` at `GPU_ctx+0x2A94+0x10`) → present callback (`GPU_ctx+0x40A0`) → `VdSwap` | ❌ NOT STARTED | Chain fires automatically; no manual seeding |
| 4.3 | `Function_82419718` processes command buffer at `GPU_ctx+0x30`, emits PM4 packets, calls present callback | ❌ NOT STARTED | Real PM4 packets in command buffer |
| 4.4 | Present callback (`hk_vdswap_observer`) → `VdSwap` → capture hook at `sub_82420BA8` fires | ❌ NOT STARTED | First real draw capture |

**Gate 4:** ❌ **NOT MET** — blocked on Phase 3. `phase2_validator.exe` — not yet created.

---

### Phase 5 — Guest Vertex/Index Capture & Native Draw

> ⛔ **SUPERSEDED (2026-08-22)** by **P5′ Real Draws via Device Boundary** —
> capture is redirected from the CP seam (`sub_82420BA8`) to the device-method
> boundary. Do NOT implement this ladder.

**Goal:** Replace the synthetic draw with real guest vertex data captured at
`sub_82420BA8`.

| Step | Description | Status | Validation |
|------|-------------|--------|------------|
| 5.1 | Wire `sub_82420BA8` to capture all guest VB/IB pointers, strides, formats, counts, VFETCH descriptors | ❌ NOT STARTED | Replay single captured draw through `phase3_validator.exe` vs legacy path — pixel hash match |
| 5.2 | Extend `ResourceCache` with per-draw key including resolved vertex format (from VFETCH constants) and index format | ❌ NOT STARTED | Cache hit/miss stats; zero re-uploads for repeated draws |
| 5.3 | Implement native `DrawIndexedInstanced` path in `src/d3d12_backend.cpp` using captured descriptors, root signature, PSO per draw | ⚠️ SYNTHETIC ONLY | `backend_validator` + `phase3_validator` CLEAN on real capture data |
| 5.4 | Add `capture` CVar to `renderer_mode` that replays captured draws without presenting | ❌ NOT STARTED | `renderer_mode=capture` runs headless, logs per-draw stats, zero D3D12 debug messages |
| 5.5 | Select 3–5 representative captures; prove they rasterize identically to legacy path (pixel diff < 1 pixel) | ❌ NOT STARTED | Comparison report in `build/phase3_validation/` |

**Note:** Xenos decode, shader pipeline, backend device, and synthetic draw are
complete. This phase extends with real guest data capture.

**Gate 5:** ❌ **NOT MET** — blocked on Phase 4.

---

### Phase 6 — Renderer Mode & Compatibility

> ⛔ **SUPERSEDED (2026-08-22)** by **P6′ Native Default & Legacy Retirement**
> (adds explicit deletion of `gpu_cp.cpp`, `InitGpuBackendManual`,
> `GpuContextPoller`, manual seeding, and the Vd*→stub conversion per UR
> `kernel/imports.cpp:794`).

**Goal:** `renderer_mode=native` becomes default; legacy path retired.

| Step | Description | Status |
|------|-------------|--------|
| 6.1 | `renderer_mode=native` default; `legacy` opt-in | ❌ NOT STARTED |
| 6.2 | Remove compatibility renderer code paths | ❌ NOT STARTED |
| 6.3 | Full regression: boot → title → race → menu — all frames native | ❌ NOT STARTED |

**Gate 6:** ❌ **NOT MET** — blocked on Phase 5.

---

## UnleashedRecomp Framework Recheck (2026-08-19, Authoritative)

Re-audit of the plan against the vendored UnleashedRecomp tree
(`.research/UnleashedRecomp/UnleashedRecomp/{kernel,cpu,gpu}`), the
XenonRecomp README/wiki, and the Xenia reference. Sources: local vendored
source (authoritative), `hedge-dev/UnleashedRecomp`, `hedge-dev/XenonRecomp`,
`xenia-project/xenia` (`xboxkrnl_video.cc`, `command_processor.cc`).

### Confirmed Correct in the Plan

| Plan Claim | Evidence |
|---|---|
| 4 GB `VirtualAlloc` at `0x100000000` + `MapVirtual`/`Translate` | UnleashedRecomp `kernel/memory.h`: `Memory{ uint8_t* base }`, `Translate`/`MapVirtual`, `PPC_MEMORY_SIZE`; `PPC_LOOKUP_FUNC(x, y)` in `Memory::FindFunction` |
| `PPCFuncMappings[]` links guest → host at startup | `ppc_func_mapping.cpp` + `PPC_LOOKUP_FUNC(base, guest)` in `Memory::FindFunction` |
| Kernel imports = one-line `GUEST_FUNCTION_HOOK` | `kernel/function.h:351` `#define GUEST_FUNCTION_HOOK(subroutine, function) PPC_FUNC(subroutine) { HostToGuestFunction<function>(ctx, base); }` |
| Handle = guest-VA identity | `xdm.h`: `GetKernelObject(handle) = Translate(handle)`, objects in guest heap via `g_userHeap.AllocPhysical<T>`, `GUEST_INVALID_HANDLE_VALUE = 0xFFFFFFFF` |
| Lazy-wrap via `QueryKernelObject` | `xdm.h:130-143`: checks `WaitListHead.Flink != 'XBOX'`, creates wrapper, caches in `.Blink` |
| TLS/PCR: `r13` = PCR, `r1` = stack per guest thread | `cpu/guest_thread.cpp` (PCR_SIZE 0xAB0, TLS_SIZE 0x100, TEB_SIZE 0x2E0, STACK_SIZE 0x40000) |
| `PPC_FUNC(x)` = `void x(PPCContext& __restrict ctx, uint8_t* base)` | XenonRecomp `recompiler.cpp` generated `ppc_config.h` + README |
| 4 GB first page = NOACCESS (null-deref trap) | UnleashedRecomp `kernel/memory.cpp`; MCLA must match |
| `ExCreateThread` = `GuestThread::Start` pattern | `cpu/guest_thread.cpp` allocates PCR+TLS+TEB+Stack per thread |
| Critical sections = `std::atomic_ref` on guest memory | `imports.cpp:691-710` `RtlEnterCriticalSection` uses `std::atomic_ref owningThread(cs->OwningThread)` |

### Deltas Requiring Action (MCLA Currently Violates These)

1. **Identity handles are canonical, not optional.** UnleashedRecomp
   `kernel/xdm.h`: `GetKernelObject(handle) = Translate(handle)` (the handle
   IS the guest address of the in-guest `XDISPATCHER_HEADER`), objects are
   allocated in guest physical heap (`g_userHeap.AllocPhysical<T>`),
   `GUEST_INVALID_HANDLE_VALUE = 0xFFFFFFFF`. The lazy-wrap mechanism is
   `QueryKernelObject(header)`: if `WaitListHead.Flink != 'XBOX'`, mark it
   and cache the host wrapper's guest address in `.Blink`; subsequent calls
   return the cached wrapper. **MCLA's host-heap `unordered_map` + `new` is a
   third, non-framework model — ELIMINATE IT.** ReXGlue's `0xF8000000|slot*4`
   table is the Xenia model. MCLA must use identity handles for ALL kernel
   objects (Event, Semaphore, Thread, Timer, File). This matches the plan's
   own "identity encoding" finding (guest passes embedded `XKEVENT` VAs).

2. **Typed-arg migration is unfinished.** `src/kernel/imports.cpp` declares
   raw `uint32_t Foo(PPCContext& ctx, uint8_t* base)` and reads registers by
   hand. The framework pattern is typed host functions
   (`uint32_t NtCreateEvent(be<uint32_t>* handle, XOBJECT_ATTRIBUTES* attrs, ...)`)
   with `HostToGuestFunction` translating `r3-r10`/`f1-f13`/stack args
   automatically, including `be<uint32_t>` stack slots at `r1+0x54+(arg-8)*8`.
   MCLA's `function.h` already implements the typed-arg machinery
   (`ArgTranslator`, `GuestFunctionHookImpl`) — **it is simply not applied to
   the imports**. Converting an import = change its signature to typed args +
   one `GUEST_FUNCTION_HOOK(__imp__X, X)` line.

3. **`KernelObject::Wait` API differs.** Framework: single
   `virtual uint32_t Wait(uint32_t timeout)`; MCLA:
   `virtual uint32_t Wait(uint32_t timeoutMs, bool alertable)`. **Align on the
   framework shape**; route alertability through the import wrapper
   (`KeWaitForSingleObject`/`NtWaitForSingleObjectEx` decide `STATUS_USER_APC`),
   not through `KernelObject`.

4. **`KeWaitForMultipleObjects` generation counter.** Framework uses a
   `g_keSetEventGeneration` counter to make WAIT_ANY return the low
   wait-completed index cheaply; MCLA delegates to `NtWaitForMultipleObjects`.
   **Port the counter pattern** (small) before multi-handle waits show up on
   the boot path.

5. **`ObReferenceObjectByHandle` returns handle as pointer.** Framework:
   `*object = handle; return 0;`. MCLA writes handle to output but via
   host-heap table. On identity handles, this is a one-liner.

6. **Critical section layout is 28 bytes (Xbox 360), not Windows.** `XRTL_CRITICAL_SECTION`
   = `XDISPATCHER_HEADER` (16) + `LockCount@0x10` + `RecursionCount@0x14` +
   `OwningThread@0x18`. MCLA put `OwningThread@0x10` — WRONG. Fix to 0x18.

7. **`MmAllocatePhysicalMemoryEx` convention.** Real: `r3`=flags, `r4`=size,
   `r5`=protect, `r6`=min, `r7`=max, `r8`=alignment; returns raw guest VA
   (never byteswap a register return). MCLA read `r3`=size, `r4`=alignment,
   byteswapped the return, and the `.inc` wrapper **discards** the return →
   game gets 0 → failure path.

8. **`NtCreateEvent` arg order.** `r3`=&handle, `r4`=objAttr, `r5`=eventType,
   `r6`=initialState; `manualReset = !eventType`. MCLA swapped r5/r6 in both impls.

9. **`KeSetEvent` takes `XKEVENT*` (guest VA), not synthetic handle.** 16-byte
   `XDISPATCHER_HEADER`: Type@0, Absolute@1, Size@2, Inserted@3, SignalState@4
   BE, WaitListHead@8/0xC.

10. **`ExAllocatePoolTypeWithTag` returns guest VA, no pool header.** MCLA read
    `r4`=size, ignored tag, byteswapped the return.

11. **`NtAllocateVirtualMemory` signature.** `r3`=&BaseAddress (in/out), `r4`=&RegionSize
    (in/out), `r5`=alloc_type, `r6`=protect_bits. MCLA read `r4`=base, `r6`=size →
    allocates protect_bits as size; never writes RegionSize back.

12. **`VdGetSystemCommandBuffer` writes 0xBEEF markers.** Game **reads p1** →
    MCLA returning 0 yields garbage command-buffer pointer.

13. **`HalReturnToFirmware` terminates, never returns.** MCLA no-op (evidence:
    MCLA calls it mid-boot and continues; `std::exit(0)` killed process).

14. **`MmQueryAllocationSize` returns real size.** MCLA hardcoded 0x1000.

15. **First-page NOACCESS missing.** MCLA's 4 GB heap lacks the guard page.

---

## Risk Register (2026-09-03)

Top risks to the current plan, with mitigations. Review at every phase gate;
retire rows with evidence.

| # | Risk | Impact | Likelihood | Mitigation |
|---|------|--------|-----------|------------|
| R1 | **Slab corruption in class allocator `sub_821DE9D8` is a symptom, not the root** — the real bug (guest-side double-free / heap misuse) lives elsewhere and resurfaces after any allocator-side fix | Boot blocker persists past session 37+ | Medium | Census first (never "fix" blind); if census shows healthy frees, widen to write-barriers on the churn-heap pages (page-watch was already proven zero-traffic on 0x50000000 — re-target at the heap range) |
| R2 | **OOM fatal is intermittent & census-timing-sensitive** (stall-forensics gotcha: instrumentation shifts the burst) | False "fixed" declarations | High | 2–3 soak repetitions before any terminal state; keep OOM/PHYSALLOC/ARENA censuses permanent until P4′ gate |
| R3 | **vblank interrupt storm** (upstream LARecomp: long-session frame-rate collapse) | Frames flow, then degrade over minutes | Medium | P4′ gate now includes ≥10 min soak + interrupt-rate census (guest callback @0x82411478) |
| R4 | **Corpus contains memexport / point-size ucode** that XenosRecomp does not implement upstream | P5.5′ coverage gap → missing pixels at P5′ | Unknown | Audit 1,264-file corpus for memexport/point-size opcodes BEFORE trusting 0-unknown-opcode coverage claims |
| R5 | **Unsigned DXIL in embedded cache** | Cache blobs rejected at PSO creation | Low (if toolchain runs dxil.dll) | Signing is a build-time step in P5.5′; add a validator assert on the signature flag |
| R6 | **Constant patches hit read-only `.rdata`-mapped guest pages** (upstream flt_8201E7EC AV) | Boot AV that looks like a guest bug | Low | Any `patches.cpp` data patch must unprotect the page first; assert writability before write |
| R7 | **Capture hooks fire but the game never reaches them** (current state: armed, zero captures) | Wasted instrumentation cycles | Active | Blocker-first discipline: no P4′ step-3 work until the OOM/slab front closes |

---

## Validation Infrastructure

| Validator | Purpose | Status |
|-----------|---------|--------|
| `phase0_validator.exe` | Framework unit tests (memory, handles, hooks, kernel objects, identity handles, lazy-wrap) | ✅ EXISTS — 13/13 PASS (re-verified 2026-09-03) |
| `phase1_validator.exe` | Boot-to-VdSwap import behavior; kernel object lifecycle | ❌ NOT YET CREATED |
| `phase2_validator.exe` | GPU context initialization; VSync→present chain; first draw capture | ❌ NOT YET CREATED |
| `phase3_validator.exe` | Guest VB/IB capture replay vs legacy pixel hash; format support matrix | ✅ EXISTS — synthetic data only |
| `backend_validator.exe` | D3D12 device/PSO/root-signature creation; draw execution on HW/WARP | ✅ EXISTS — synthetic data only |
| `capture_dump_validator.exe` | `.mclatrace` integrity; guestmem dump coverage vs stride*count | ✅ EXISTS |
| `xtr_dump_validator.exe` | `.xtr` stream parse to EOF; command histogram; frame delimiters | ✅ EXISTS |
| `xenos_decode_validator.exe` | Xenos microcode decode validation | ✅ EXISTS |
| `shader_pipeline_validator.exe` | Shader pipeline validation | ✅ EXISTS |

---

## Loop Discipline (Cycle Engineering, 2026-08-21)

Every work cycle (debug session, import port, validator extension) is a loop
specification: **trigger → verifiable goal → verification → stopping rule →
memory**. This section makes that discipline explicit and checkable. Grounded
in: arXiv 2607.00038 (loop-spec anatomy, five-level verification ladder, named
terminal states), Anthropic evaluator-optimizer pattern + eval guidance
(deterministic graders first; grade output, not path; regression evals), and
the Loop Library corpus (`Forward-Future/loop-library`). Prompt craft still
matters — the loop amplifies it, never replaces it.

### Verification Ladder (evidence quality)

A gate may only be claimed with rung ≥2 evidence. Rung 0–1 claims are
hypotheses, not results.

| Rung | Evidence | Example here |
|------|----------|--------------|
| 0 | Agent asserts | "should boot now" |
| 1 | Build clean | `cmake --build build` exit 0 |
| 2 | Deterministic validator | `phase0_validator.exe` 13/13; pixel-hash replay |
| 3 | Independent checker (separate context from maker) | `code-reviewer` / `security-auditor` pass on the diff |
| 4 | Human gate | user signs off phase advance |

Rules:
- **Generator never grades its own gate.** Maker/checker split is mandatory at
  rung 3: route through `code-reviewer` (+ `security-auditor` for guest-memory
  changes) before claiming done.
- **Grade output, not path:** a fix passing the validator via a different
  mechanism than predicted still counts — record the actual mechanism.
- **Regression eval:** before declaring any boot-progress win, re-run the last
  known-good run's evidence (survive-Ns log signature). A win that breaks the
  previous gate is a step backward (see 2026-08-19 Mm revert).

### Named Terminal States

Every cycle ends in exactly one named state, recorded in its Investigation
Record entry: **SUCCESS** (gate criterion met) · **NO-OP** (nothing worth
changing) · **BLOCKED** (external prerequisite missing — name it) · **STALLED**
(no measurable progress this iteration) · **EXHAUSTED** (cap hit). Never
mistaking an error for success is Golden Rule 6 enforced procedurally.

### Iteration Caps & Stop Rules

- Max **3 failed hypotheses** on one crash theory → mandatory bisection or
  step-back to last known-good run before a new theory.
- Max **2 consecutive regressions** from one approach → revert, record as
  proven-negative in the Investigation Record.
- Context pressure → externalize exact state to a handoff file *before*
  continuing; auto-compaction is disabled, so an unbounded session is a leak,
  not a strategy.

### Run Receipt (append per boot run)

```text
RUN n: trigger=<change under test> | expect=<verifiable prediction>
observed=<log signature / fault addr / regs> | state=<terminal state>
next=<one concrete action>
```

### Anti-Patterns (mapped to golden rules)

| Anti-pattern | Local form | Countermeasure |
|---|---|---|
| Reward hacking | claiming `native` while Xenos CP / PM4 still runs (Rule 6) | gates cite rung ≥2 evidence only |
| Fake done | "validator will pass" instead of having run it | run receipt required per run |
| Cognitive surrender | accepting agent output without reading the diff | review gates stay; comprehension debt grows otherwise |
| Fuzzy memory | relying on session recall instead of files | spine = Investigation Record + handoff files |

---

## Investigation Record (Boot Path) — Key Evidence

### Proven (2026-08-13) — Crash Chain
- Crash chain: `_xstart` `0x821322B8` → `sub_82132740` → `sub_827A7688` →
  `sub_82131228` → `sub_821C2E60` → `sub_821BD618`. `sub_821305B8` NOT in chain.
- `PPC_LOOKUP_FUNC(x,y) = *(PPCFunc**)(x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
  (uint32_t(y)-PPC_CODE_BASE)*2)`. Constants: `IMAGE_BASE 0x82000000`,
  `IMAGE_SIZE 0x9E0000`, `CODE_BASE 0x82130000`.
- Slot at fault: raw LE `0x78061382` = BE guest `0x82130678` (mapping present).
- Error-handler bodies: `sub_82130678` (`li r3,0; bl sub_82388598; bl sub_82131C58`);
  `sub_82131C58` (`bl __imp__XamShowDirtyDiscErrorUI; li r4,0 r3,0; bl sub_821324A0`);
  `sub_821324A0` (r3==0 → beq → `b 0x827bce54` = `__imp__XamLoaderLaunchTitle`).
- Prime suspects for driving boot into dirty-disc handler: stubs returning garbage
  `r3`: `XamShowDirtyDiscErrorUI`, `XamLoaderLaunchTitle`, `XexCheckExecutablePrivilege`,
  `ExGetXConfigSetting`, `XGetAVPack`.

### Proven (2026-08-14) — Heap Crash Root Cause + Fix
- Heap global `0x8294A5A0` was **0** at buffer-pool fault in `sub_82133438`
  (READ AV at guest `0xFFFFFFFF` walking large-bucket free-list head).
- Root cause: `NtAllocateVirtualMemory` / `NtQueryVirtualMemory` /
  `NtFreeVirtualMemory` were no-op log stubs.
- Fix: guest-VA region allocator + real stubs. `[0x8294A5A0]=0x40000000` verified.
- Post-fix boot: advances through `NtCreateFile`, Xam/net init, thread creation,
  `VdInitializeEngines`, `VdSetGraphicsInterruptCallback`, `VdInitializeRingBuffer`,
  `VdEnableRingBufferRPtrWriteBack`, `KiApcNormalRoutineNop`, then spins in GPU
  fence wait `sub_82412F98`.

### Proven (2026-08-14) — GPU Fence Wait Unblocked
- Fence-wait spin (`sub_82412F98`) never times out because zeroed TEB keeps
  timer at 0.
- Fix: strong `PPC_FUNC(sub_82412F98)` override returning `r3=0` (GPU idle).
- Verified: boot passes `sub_82412F98`; reaches dirty-disc error path
  (`sub_821BD618`, slot `0x8285FEA0=0x82130678` installed).

### Proven (2026-08-15) — `MmQueryAllocationSize` Heap-Wipe Root Cause + Fix
- Root cause: `MmQueryAllocationSize` no-op returning queried address as size.
  Destructor does `memset(addr, 0, MmQueryAllocationSize(addr))`; wiped heap
  descriptor at `0x40000000`.
- Fix: `SmokeAllocPhysical` records `(base,size)`; `MmQueryAllocationSize`
  returns physical → VM → `0x1000` fallback. Verified: no fault, survives 60 s.

### Proven (2026-08-15) — `KeDelayExecutionThread` + Main Loop Reached
- `KeDelayExecutionThread` was no-op, so main loop's `Sleep(ms)` hot-spun.
- Fix: alertable → `STATUS_USER_APC` (0xC0); non-alertable → read BE int64 at
  r5, `Sleep(timeout/10000 ms)`, return `STATUS_SUCCESS`.
- Verified (run8): GPU-init chain fully green; no dirty-disc, no `VdShutdownEngines`,
  no `READ @0x0`. Boot reaches game main loop, parks in `Function_824E5350`.

### Proven (2026-08-15) — `NtCreateEvent` Stub + run9 (No Regression)
- `NtCreateEvent` was no-op: never wrote output handle, device-event poll
  `Function_8244EE40` got garbage.
- Fix: writes non-zero kernel handle (BE) via `SmokeEventAdd()` (disjoint
  `0x10000000+` range), returns `STATUS_SUCCESS`. Verified: no fault, 60 s.

### Proven (2026-08-19) — P1 Boot Progression (Empirical Bisection)
Applied P1 semantic fixes one family at a time, mapped boot behavior per run:
- **Rtl*CriticalSection family** (28-byte layout, `OwningThread@0x18`) unblocks
  early park → VFS mount, XGPU/EDRAM init (`sub_821C2E60`).
- **MmAllocatePhysicalMemoryEx** real convention (r3=flags, r4=size) confirmed:
  `sub_82132578` calls with r3=0, r4=size, requires r3!=0 after. With it, game
  advances to HAL init `sub_823D9A98`→`sub_823D9990`→`sub_823E2A08`→`sub_823E28C8`
  and fires **guest-fatal `KeBugCheck(0xC0000144)`** via indirect-called
  `sub_823E2A68`. Reverting Mm to size-from-r3 sent game to dirty-disc fatal —
  step backward, confirming real convention.
- **NtCreateEvent** (r5=eventType, r6=initialState) and **VdGetSystemCommandBuffer**
  (0xBEEF markers) behaviorally neutral at this point.
- **HalReturnToFirmware** must return (MCLA calls it mid-boot); `std::exit(0)`
  killed process.
- **Current deepest state:** all P0 + P1 evidence-correct fixes applied. Boot
  survives, mounts VFS, reaches HAL init, then game self-fatals
  `KeBugCheck(0xC0000144)`. **Next blocker:** isolate HAL init check that fails
  before `sub_823E2A68` — likely GPU/HAL import (`VdInitializeRingBuffer`,
  `VdQueryVideoMemory`, `VdGetSystemCommandBuffer` consumer, or
  `0x827A7688`/`0x82131228` chain) returning value game treats as failure.

### Proven (2026-08-19) — Boot Regression from Mass Import Port
- After porting ~150 UnleashedRecomp imports **incorrectly** (wrong framework),
  boot regressed from "main loop reached" to crash at entry function.
- Fault: `code=0xC0000005 read addr=0x0000000000000090`, `host rva=0x9E52C`,
  `r1=0x8EFFFB10 r3=0x00000000 r13=0x8F200000 lr=0x00FFFFFF callerLR=0x90000000`,
  fault bytes `F0 0F B1 0E` = `lock cmpxchg [rsi], ecx` — null-pointer deref at
  offset 0x90 in recompiled atomic op, no kernel stubs logged before fault.

### Proven (2026-08-19) — Regression Root Cause (Four Subagent Passes)
**BUG A (register mapping — crash trigger).** Under `PPC_CONFIG_NON_ARGUMENT_AS_LOCAL`
+ `PPC_CONFIG_NON_VOLATILE_AS_LOCAL` (`generated/ppc_xenon/ppc_config.h`),
the `PPCContext` union aliases `gpr[]` to WRONG registers:
`gpr[0]=r3, gpr[1]=r1, gpr[2]=r4, gpr[3]=r5, gpr[4]=r6, gpr[5]=r7, gpr[6]=r8,
gpr[7]=r9, gpr[8]=r10, gpr[9]=r13, gpr[10..31]=padding`. Ported code read
`ctx.gpr[3]` intending r3 — it read **r5**; `ctx.gpr[13]` read **unaliased
padding** (garbage).

**BUG B (NULL heap base — crash mechanism).** `GuestMemoryHeap::Initialize()`
called only in `phase0_validator.cpp`, **never in main app path**; `memory.h`
defaults `m_base=nullptr`. Every `imports.cpp` `Base() + addr` computes from
NULL → AV at `addr`.

**Crash mechanism (fully explained):** guest chain `_xstart` (0x821322B8) →
`sub_82132820` → `sub_823D9930` → `sub_823E24C8` → `sub_823E23F0` →
`sub_82134860` (sets guest `r3=0`, calls `RtlEnterCriticalSection`).
`RtlEnterCriticalSection` misread `gpr[3]` = guest **r5** = 0x80 as `csAddr`;
NULL base + 0x80 + 0x10 (`OwningThread`) = **0x90** → `lock cmpxchg` fault.

**Structural defects (all passes agree):**
- **~37 dead ported functions** shadowed by live inline stubs in
  `kernel_stubs_body.inc` (NtCreateEvent, NtWaitForSingleObjectEx, KeSetEvent,
  KeResetEvent, KfAcquireSpinLock, KfReleaseSpinLock, ExCreateThread,
  XMsgStartIORequest, NtCreateFile, NtReadFile, NtClose, VdInitializeEngines,
  VdSetGraphicsInterruptCallback, XamInputGetState, KeWaitForSingleObject,
  NtOpenFile, NtWriteFile, NtQueryInformationFile, NtQueryDirectoryFile,
  NtQueryFullAttributesFile, NetDll_WSAStartup + 15 `s_StubCalled`-only). Two
  competing implementations per import → Golden Rule 1 violation.
- **Two disjoint handle spaces:** inline stubs use `s_eventMap` (0x80000000+
  guest handles) while ported code uses `HandleTable` (`0x80000000|index`).
  `NtCreateEvent`/`KeSetEvent`/`NtWaitForMultipleObjects` disagree on handle
  space. Game relies on **identity encoding** (passes embedded guest XKEVENT
  VAs, e.g. `KeSetEvent(device+16)`).
- **Hard-rule violations in ported code:** `reinterpret_cast` on guest data,
  no explicit endianness (`*reinterpret_cast<const int64_t*>` timeout reads at
  imports.cpp:127,162,533,557; host-endian struct writes at 763-773), no-op
  bounds checks (`addr < 0x100000000` always true for `uint32_t`), NULL-base
  derefs.
- **Phase discipline violated:** mass port exceeded Phase 3's critical list
  (P1-P4 items — Xam*/XAudio*/XeCrypt*/NetDll_*/Stfs*/Fsc* — ported without
  mandatory per-import 360-semantics audit).
- **Invented GPU-context seeding:** `VdSetGraphicsInterruptCallback` +
  `VdInitializeEngines` hardcode `0x82419718`, `0x827BD6E4`, `0x8F20F000`,
  `0x8F207000`, `GPU_ctx+0xD0=1` — violates Golden Rule 5 and Phase 4's
  "no manual seeding" gate.

**Per-import semantic evidence (research-scout, cited to Xenia/UnleashedRecomp):**
(See "Deltas Requiring Action" table above for full list.)

### Proven (2026-08-19) — HAL-init Premise Corrected
The "next blocker = `KeBugCheck(0xC0000144)`" premise is **retired**. New
evidence (Ghidra decompiles + `build/cache/mcla.log` 07:10 run):
- Observed fault was `KeBugCheck(0)` (r3 forced to 0), not 0xC0000144.
  `0xC0000144` appears nowhere in `src/`; constructed only in guest handler
  `sub_823E2A70` at slot `[0x828CD8E0]` — write-only, no reader, unreachable.
- Real gate firing fatal: `sub_82135D28` reads global `[0x8294A5A0]`;
  `Function_823E28C8` (HAL-init) tail-calls `sub_823DAEC8` =
  `li r3,0; b __imp__KeBugCheck` when slot is 0. **Slot now non-zero** (written
  by `Function_82132970` → `Function_821342B8` during boot; always-0
  `RtlImageXexHeaderField` stub forces create path which succeeds). This is why
  07:10 build boots **fully through HAL init**.
- **Current front-line failure (real next blocker):** VSync second-level
  callback `0x82419718` fires each tick and calls present callback at
  `GPU_ctx+0x40A0`. That slot seeded to `0x827BD6E4` = `__imp__VdSwap`
  (kernel_stubs_body.inc:1098, imports.cpp:409). The `bctrl` at
  `sub_82419718+0x2A4` (`PPC_CALL_INDIRECT_FUNC(ctr)` at ppc_recomp.79.cpp:11096,
  lr=0x82419804) faults `0xC0000005` at guest `0x824F704` (`r1=0xFFFFFF80`,
  `r3=0xFFFFFFD0` — garbage stack/arg registers passed into callback).
  **This is Phase 3's Definition-of-Done boundary:** present chain fires but
  callback entry state is wrong.
- **Recommended direction (evidence, not invented):** present-callback
  invocation in `sub_82419718` builds 3 args on stack (`[r1+80..88]` = counters)
  and calls `[r31+16544]` (`GPU_ctx+0x40A0`) — it **expects a real guest
  callback** (Xenia `VdSwap`-shaped: `VdSwap(buf, fetch, unk2, unk3, unk4, fbuf,
  fmt, cs, w, h)`), not a raw host stub. Seeding `VdSwap` there with no
  register/stack state is exactly the Phase 4 "no manual seeding" violation.
  Keep slot seeded only as Phase-3 stopgap; Phase 4 must let
  `Function_82419718`'s own init (`VdInitializeEngines` real path) install the
  real callback.

---

## Immediate Execution Order (Authorized, 2026-08-19)

0. **Framework Rewrite (Phase 2 Steps 2.1–2.8):** Replace MCLA's kernel
   framework with canonical UnleashedRecomp framework:
   - 2.1: Add NOACCESS guard page to 4 GB heap
   - 2.3: Adopt framework's `function.h` (`HostToGuestFunction`, `ArgTranslator`,
     `GUEST_FUNCTION_HOOK` macro) — replace MCLA's `function.h`
   - 2.4: Fix `KernelObject::Wait(uint32_t timeout)` signature (remove alertable)
   - 2.5: Implement identity handles + `QueryKernelObject` lazy-wrap (`xdm.h`)
   - 2.6: Implement `GuestThread::Start` pattern (PCR+TLS+TEB+Stack in guest heap)
   - 2.7: **Delete `kernel_stubs_body.inc` and MCLA's `HandleTable`/`KernelObject`**.
     Port ALL imports from UnleashedRecomp `imports.cpp` as typed-arg
     `GUEST_FUNCTION_HOOK` one-liners, audited against 360 semantics.
   - 2.8: Add `g_keSetEventGeneration` counter for `KeWaitForMultipleObjects`

1. **Critical Imports on Canonical Framework (Phase 3):** Port each critical
   import as typed-arg one-liner, audited against Xenia/360 semantics:
   - `NtCreateEvent`, `KeSetEvent`, `ObReferenceObjectByHandle`, `Rtl*CriticalSection`
     (28-byte, OwningThread@0x18), `KeDelayExecutionThread`, `MmAllocatePhysicalMemoryEx`
     (r3=flags, r4=size, return guest VA no byteswap), `VdGetSystemCommandBuffer`
     (0xBEEF markers), `HalReturnToFirmware` (no-op return), `MmQueryAllocationSize`
     (real size tracking), `ExCreateThread` (GuestThread pattern),
     `KeWaitForMultipleObjects` (generation counter),
     `VdInitializeRingBuffer`, `VdEnableRingBufferRPtrWriteBack`,
     `VdInitializeEngines` (full GPU context init, no manual seeding),
     `VdSetGraphicsInterruptCallback` (VSync thread, no manual seeding),
     `VdQueryVideoMode`, `VdQueryVideoFlags`.

2. **Dead Import Cleanup:** Remove ~37 shadowed imports, delete
   `kernel_stubs_body.inc`, unify handle space to identity handles.

**Validation gate for P0:** ✅ MET — boot gets past `addr=0x90` fault; `mcla.exe`
boots and survives 75 s at ~0% CPU (idle in host wait), build clean.

**Validation gate for P1 (Framework Rewrite):** ❌ NOT MET — must build clean on
canonical framework with zero `reinterpret_cast` on guest data, zero manual
`ctx.rN` reads in `imports.cpp`, identity handles operational.

---

## Dependency / Vendoring Notes

- **DXC** vendored at `third_party/dxc/` (headers `inc/`, binaries);
  `DXC_INCLUDE_DIR` in `CMakeLists.txt`.
- **No ReXGlue SDK** (2026-08-20). `rexglue-sdk/` deleted. SDL3, fmt, spdlog,
  toml++, and o1heap are vendored under `third_party/`; xxhash under
  `.research/XenonRecomp/thirdparty/xxHash/`; simde under
  `.research/XenonRecomp/thirdparty/simde/`. CMake package configs in `cmake/`
  point at those vendored locations. No `rex::` API, no `rexruntime.lib`, no
  Tracy, no REXCVAR/REXLOG macros.
- **Ghidra MCP** (`ghidra_*` tools) for cross-checking guest function intent;
  `default.xex` via XEX2 loader. Server start:
  `start-ghidra-mcp.ps1`; health check `http://127.0.0.1:8089/check_connection`.
  - **Research findings (2026-08-22): `.research/findings/`** — authoritative
    evidence base: Ghidra `mcla_findings:/default.xex` project (XEXLoaderWV,
    19,887 funcs) + decompiled GPU-init chain (`w3_82426558.c`,
    `w2_82426468.c`: VdInitializeEngines(0x1B530000,…),
    VdSetGraphicsInterruptCallback(0x82411478, ctx), spinlock ctx+0x4148,
    PM4 emission at ctx+0x30 via 0xC0022100 packets, critical sections
    +0x3A60/+0x3A7C); Xenia kernel import table (246 thunks incl.
    VdSwap=0x827BD6E4); PIX D3D12 captures; 1,264-file Xenos microcode+DXIL
    shader corpus (`findings/xenia/shader_dumps/`). NOTE: plan addresses
    `sub_82419718`/`sub_8241976C` are internal branch targets, not entries —
    resolve containing functions (raw bytes: `48000054` = `b +0x54`).
- **XenonRecomp** outputs `generated/ppc_xenon/` — **never edit**. Authoritative
  vanilla compiler: `...\Temp\opencode\XenonRecomp-vanilla\build\XenonRecomp\XenonRecomp.exe`.
  Switch tables: `config/mcla_xenonrecomp.toml` →
  `.research/XenonRecomp/XenonAnalyse/jump_tables.toml` (populated, 174403 B).
- **Glossary:** Xenon**R**ecomp = PPC → C++ (CPU codegen). Xeno**S**Recomp =
  fxc/shaders → HLSL (GPU shader translation). Do not swap them.
- **Xenia Canary** `xenia_canary.exe` for A/B renderer comparison; RenderDoc/PIX
  for GPU capture (see `.clinerules/gpu-tooling-mcp.md`).

---

## Build + Run

```text
cmake -S . -B build -G Ninja ^
  -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl ^
  -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build
build\mcla.exe
build\mcla.exe --function=0x82130000   # direct TU call
```

Caveats: BOTH compilers must be clang-cl; delete `build/` when switching
compilers. VS BuildTools `vcvars64.bat` must be on PATH (call it before
building; `build/_build_mcla.bat` does this). `build/mcla.log` is the runtime
log (under `build/cache/mcla.log` for the boot host).

---

## Handoff Checklist (Every Continuation)

- [x] Single hook owner per guest address confirmed
- [x] Generated code untouched
- [x] Default `renderer_mode` still `legacy`; prior mode still functional
- [ ] Built cleanly; build command + result recorded here
- [ ] Fault/evidence (host stack, regs, PPC_LOOKUP_FUNC entry) recorded above
- [ ] Never claimed deeper boot than the gates prove
- [ ] Unresolved guest-structure assumptions recorded explicitly
- [x] **All imports use typed-arg `GUEST_FUNCTION_HOOK` one-liners**
- [x] **Identity handles operational (no host-heap unordered_map)**
- [x] **`QueryKernelObject` lazy-wrap working for Event/Semaphore/Thread**
- [x] **`KernelObject::Wait(uint32_t timeout)` single-param signature**
- [x] **`g_keSetEventGeneration` counter for `KeWaitForMultipleObjects`**
- [x] **Critical section layout 28 bytes (OwningThread@0x18)**

---

## Status Legend

- **Phase 1 (ABI)** — ✅ DONE (steps 1.1–1.8; codegen verified full ABI header; setjmp/longjmp confirmed absent)
- **Phase 2 (Canonical Framework)** — ✅ DONE (kernel core complete, build green; phase0_validator 13/13)
- **Phase 3 (Critical Imports)** — ✅ PASSED 2026-08-22 (`39ebebf`): boot survives main loop, world loads from real archives, VSync present chain 60fps, zero crashes
- **Old Phase 4 (CP emulation)** — ⛔ **SUPERSEDED by UR-Succession Revision (top of file)** — see P4′–P6′
- **P4′ Device-Boundary Takeover** — 🟡 **steps 1-2 done + CP DRAIN CHAIN LIVE (2026-08-23, commits 41a08e9..0784386):** root cause killed (App never created FunctionDispatcher ⇒ mcla_ApplyPatches incl. CpInstallMmioRouting no-op'd every boot); doorbell→DrainRing→rptrWB publish closed-loop with exact consumption math; progress counter (KTHREAD+0x58 = *(r13+256)+88, block 0x8F200080) decoded via gate-cracker agent + synthesized (CpVblankBump(64)/vsync tick — labeled EXPERIMENT; xenia never writes this field and MCLA freezes there too); consumer-chases-put mirrors into subctx[+0]/[+4]; PARK BROKEN — submitter completes multiple reserve/write/doorbell cycles (RW#0006+, drains 4-8). **SESSION 9 (commit `61150c0`):** E94 = EMPTY padding stub, real body sub_82411E98 decoded + passes at init; MMIO interrupt-status fix per xenia (reg 0x1951→1 vblank + register write shadow) OPENS the game's own vsync ISR gate [0x7FC86544]&1 ⇒ sub_82419718 flip processor VERIFIED firing per tick (queue empty — producer unknown); mirrors generalized to multi-device registry (A0009100 covered); ZERO KeSetEvent/KeReleaseSemaphore signals all run ⇒ worker wakeups are kernel-role. **NEW FRONT LINE:** main thread parks in TU83 worker loop sub_82411E98-style wait on event C9ADB800 via helper sub_82135DC0 (block 0x827D3738: deadline@+128/132, flags@+184..212, event@+52) — no guest signaller exists module-wide; next: census sub_824569C8 (worker entry; sibling 824569C4 empty stub), NtCreateEvent census for C9ADB800 creation LR, research HW kernel ISR→driver-event signaling. Full battle state: `docs/handoffs/2026-08-23-session4-packet-capture.md` (SESSION 9 section) — READ BEFORE ACTING. Diagnostics in tree: RW/RW4/DOORBELL/SUBMIT/E98/WAITHELP/FLIP/SIGNAL censuses (gpu_device.cpp, imports.cpp), PDB-named PARK-SAMPLE (boot_host.cpp). New skill: `.clinerules/skills/mcla-stall-forensics/`.
- **P4.5′ / P4.6′ / P5′ / P5.5′ / P7′ / P8′ / P9′** — ❌ NOT STARTED
- **P6′ (native default)** — ❌ blocked on all above

---

## Revision History

- **2026-08-22 (Decisions Locked):** User answered 12 design questions; results
  recorded as binding table "Decisions Locked" in UR-Succession section. Key calls:
  D3D12-only, host-side RPF stays, no input automation (graphics problem — gates =
  boot→start-menu), device-method override now with full bypass deferred, preserve
  original behavior, minimal Xam, gpu_cp.cpp deleted at P6′, HFR/full-Xam/enhancements
  explicitly deferred to post-completion backlog. Plan also corrected: shader corpus
  needs NO captures (raw ucode translates via custom XenosRecomp); G-CORPUS-* flip to
  enforced after validator dir-scan filter fix.
- **2026-08-22 (UR-Succession Revision):** User-directed plan change — implement
  UnleashedRecomp's GPU techniques exactly, NO PM4 ever. New authoritative section
  at top of file: golden rules 11–14 (no-PM4, device-table boundary, guest→queue→
  render-thread, offline shader cache), revised phase ladder P4′–P9′ replacing old
  CP-emulation Phase 4 and reshaping P5/P6. Basis: three subagent comparison reports
  (architecture/build-env/generated-source) persisted in
  `docs/handoffs/2026-08-22-ur-vs-mcla-full-diff.md`; device-boundary ground
  truth in `docs/handoffs/2026-08-22-session3-device-boundary.md`.
  Same-day commits: `270e429` (ship-blockers: probe strip, typed query hooks,
  xenia query statuses, finite-wait infinite-park fix — phase0 now truly 13/13),
  `d4c16bd` (phase-4 groundwork: CP doorbell seam [archived], XGPU device-create
  capture via global-scope `PPC_FUNC(sub_82413588)` override, GuestDevice layout
  dump matching SWA GuestDevice, FP-table redirect seam proven with
  InsertFunction/readback/lookup roundtrip). Also: LSP phantom errors fixed via
  CMAKE_EXPORT_COMPILE_COMMANDS + .clangd; build now zero-warning.
- **2026-08-21 (Loop Discipline):** Added operational cycle-engineering
  protocol: verification ladder (phase gates require rung ≥2 evidence),
  maker/checker split, named terminal states, iteration caps (3-hypothesis,
  2-regression), per-run receipt format. Sources: arXiv 2607.00038, Anthropic
  eval guidance, Loop Library corpus. Phase 2 plan got the matching per-step
  loop protocol.
- **2026-08-20 (Phase 2 Kernel Core Complete):** Kernel framework rebuilt to UnleashedRecomp canonical:
  - `src/kernel/xbox.h` created with canonical types (XKEVENT, XKSEMAPHORE, XDISPATCHER_HEADER, XRTL_CRITICAL_SECTION, be<T>, xpointer<T>)
  - `IsKernelObject` fixed to identity handle model (validate guest VA in heap)
  - All imports in `imports.cpp` use typed-arg `GUEST_FUNCTION_HOOK` one-liners
  - `KeWaitForMultipleObjects` handles Semaphore + `g_keSetEventGeneration` counter
  - `KeReleaseSemaphore` increments generation counter
  - Vd imports implemented with Xenia semantics (no manual seeding)
  - `kernel_stubs.cpp` deleted from build + filesystem
  - **Blocker:** Build fails due to CRT linkage mismatch (MSVC `boot_host_seh.cpp` objects vs clang-cl objects). SEH replaced with `SetUnhandledExceptionFilter` in `boot_host.cpp` to compile entirely with clang-cl.
- **2026-08-20 (Phase 1.8 Resolved):** Extracted and decrypted MCLA's PE from `default.xex` (LZX basic-block decompression), ran `find_abi_addrs.py` (8/8 ABI save/restore addresses confirmed matching the toml) and a manual Microsoft-CRT setjmp/longjmp pattern scan over `.text`. Result: **MCLA does not use setjmp/longjmp** — no imports, no code pattern, no symbols. Exception handling is SEH-based (`__C_specific_handler`). setjmp_address/longjmp_address correctly remain unset. Phase 1 fully closed.
- **2026-08-19 (Canonical Framework Enforcement):** Complete rewrite of plan to
  enforce UnleashedRecomp framework exactly. Eliminated "adaptive object model"
  — identity handles are canonical. Mandated typed-arg `GUEST_FUNCTION_HOOK`
  one-liners for ALL imports. Fixed `KernelObject::Wait` signature. Required
  `QueryKernelObject` lazy-wrap, `GuestThread::Start` pattern, generation
  counter. Deleted host-heap handle table. Phase 2 now a full framework
  rewrite; Phase 3 blocked until canonical framework builds.
- **2026-08-19 (Framework Recheck):** Re-audited plan against vendored
  UnleashedRecomp + XenonRecomp + Xenia. Confirmed canonical framework;
  surfaced 15 deltas MCLA currently violates. Pinned Xenia Vd semantics.
- **2026-08-19 (P1 Executed + Bisected):** Ran authorized Immediate Execution
  Order. P0-FixA/B verified (no more `addr=0x90` crash). P1 semantic fixes
  applied per evidence and empirically mapped: Rtl*CriticalSection unblocks
  early park, MmAllocatePhysicalMemoryEx real-convention confirmed by
  `sub_82132578`, boot reaches HAL init and hits guest-fatal `KeBugCheck(0)`.
  HalReturnToFirmware reverted to no-op (MCLA calls it mid-boot). Dirty-disc
  fallback from Mm revert documented as step backward.
- **2026-08-19 (Unified + Adaptive):** Merged three prior plans; made kernel
  layer flexible with UnleashedRecomp structure; adaptive object model
  (host-heap default, guest-address per-import); port-audit rule added.
  Recorded 2026-08-19 boot regression as Phase 3 first action item.
- **2026-08-18 (Gap Analysis):** Full UnleashedRecomp gap analysis; 27
  prioritized items across P0–P4; ~770 lines. Implementation order Phase A → B → C.
- **2026-08-18 (Updated):** Phase 0 gate PASS (9/9). Phase 1 at 64% (18/28).
  Boot crash `0x823db208` recorded. Validators inventory.
- **2026-08-18:** UnleashedRecomp kernel framework pattern adopted.
- **2026-08-16:** ABI migration phases 1–3 verified (44/44 targets compile;
  link blocked on PPC symbols now provided by generated TUs).
- **2026-08-15:** GPU-init chain green; main loop reached (`Function_824E5350`);
  `KeDelayExecutionThread` + `NtCreateEvent` fixes landed.
- **2026-08-14:** Heap crash fixed (real `NtAllocateVirtualMemory` family);
  GPU fence wait unblocked (`sub_82412F98` override).
- **2026-08-13:** Crash chain + slot semantics proven; `READ @0x0` resolved.