# System design scorecard — MCLA PC vs ideal (native charter)

> Compiled 2026-09-28 from 20 read-only auditor missions (F-594..F-626 session
> series). Each row: subsystem, verdict vs ideal, sharpest gap, gate to close.
> Ideal = Xenia architecture where applicable, native-correctness everywhere.
> Rule: no emulation (F-609) — fakes are debt with removal gates, not features.
>
> **§Execution order was rewritten 2026-09-28 19:4x** (its priority 1 routed work into the descent
> that F-627/F-628 refuted). The 20 rows below are unchanged; the order and the gates are not.

## How to read this

- NATIVE-CLEAN: genuinely executes; keep.
- SCAFFOLD: temporary + labeled + removal trigger written. Tolerated.
- FAKE: lies to the guest; removal queued with gate. Not tolerated long-term.
- MISSING: never built; construction job.
- MINED: live crash fault line; do not step past without handling.

## Scorecard

| # | Subsystem | Verdict | Sharpest gap / gate |
|---|---|---|---|
| 1 | Recompiler pipeline | NATIVE-CLEAN with MINED edges | Unbuildable tool + binary-only JTS patch = unreproducible regen; hand patch in generated file; absolute-address fragility. Gate: reproduce regen from tracked inputs. |
| 2 | Guest memory model | NATIVE-CLEAN core, 11 raw patterns | Unguarded raw accesses (boot_host, function.h, guest_thread, heap probes) bypass IsValid/watch/VEH; aliasing defeats watch. Gate: audit each site, guard or justify. |
| 3 | CPU semantics | MINED (~100 int3 traps) + stale stubs | vupkd3d128-mode-5 (+1 mode-2) crash-on-touch on geometry paths; stale-r3 stub returns (fake handles). Gate: implement mode-5 or prove unreachable; fix stub returns to explicit values. |
| 4 | CP depth vs Xenia | NATIVE-CLEAN core, named gaps | MEM_WRITE self-read bug (payload never stored); missing T0 bit15, side-effect writes, predication; fence publication is host-synthesized (no Xenia equivalent). Gate: fix MEM_WRITE dest read first. |
| 5 | Draw bridge (new) | SCAFFOLD (honest) | Marker pipe proven on glass; producer push-blocking risk (add drop-guard); dead paths still broken (null-VB, clear-after-draw) - fix on revive. |
| 6 | Shader pipeline | MISSING (path exists, data absent) | Empty-HLSL lookups, zeroed constants, unbound textures, divergent grcFvf builder, deploy-dependency on DXC. Gate: first real shader through guest data. |
| 7 | Texture pipeline | MISSING past detile | 2-format import, single slot, ignored samplers, unwired mips/RTV, t0/t1 drift. Gate: first textured draw. |
| 8 | Present/pacing | SCAFFOLD + defects | Double-present dead path, heartbeat contention, triple throttle, CPU scale per frame, gradient masking real output. Gate: one pacer, fallback behind cvar. |
| 9 | Audio | MISSING (backend ready) | No XMA decoder, no audlo linkage, worker unreachable, stubs all-zero, slow worker timing. Gate: first decoded frame. |
| 10 | Input | NATIVE-CLEAN (keyboard) + gaps | No physical gamepad, multi-controller faked, rumble no-op, stale-keyboard risk, dead-hook corpses. Gate: open real gamepad. |
| 11 | Kernel HLE | FAKE-heavy (205 hooks, ~100 fake-success) | Scatter-read lies, empty dirs, fake handles, dead TLS split-brain, 5s lock steal, no APC/DPC delivery. Gate: per-stub replacement, steal first. |
| 12 | Threading | NATIVE-CLEAN 1:1 + shared-r13 alias | Boot/vsync/audio share one TLS block; sampler covers 1 handle; no terminate/alertable. Gate: per-thread TLS everywhere. |
| 13 | Heaps | NATIVE-CLEAN + 1 live bug + SEH net | XAllocMem null-memset bug (guard it); SEH absorbs hide corruption (keep, but fix producers); monotonic phys leak (no-op free). |
| 14 | Streamer/inflate | FAKE-carried (3 keepers) | kF406/kF432/kF434 each mask a named native defect (filler-plant, zero-count storm, undecodable spin). Gate: fix the three native defects, then remove. |
| 15 | VFS/archives | NATIVE-CLEAN core + missing mounts | No host TOC decrypt (guest-oracle by design, OK); nested mounts unserved; straddling members; dead index; disc-completion unfixed. |
| 16 | Logging | SCAFFOLD (floods) + registry gaps | Hot bypass flood, uncapped INFLATE-ENTER, missing UILOAD/MOVIE-CTOR in battery, PRESENT collision, addr_owners blind spot, §9 drift. Fix list filed. |
| 17 | Mitigation debt | FAKE inventory (100 shaped, 86 undocumented) | Ordered removal queue exists (dead branch first - DONE F-626). Rule: replace-then-remove, never stacked. |
| 18 | Build system | NATIVE-CLEAN + manual gates | TU-count + regen gates live in skill text only; bare-ninja trap; hardcoded toolset paths; validator rebuild waste. Gate: encode gates in CMake. |
| 19 | GFx integration | MISSING (hooks cold) | Loader/wrapper/lifecycle hooks built, 0 hits; UILOAD middle missing; Fixup stubbed; movie-to-geometry bridge absent. Gate: MOVIE-CTOR > 0. |
| 20 | Boot flow | IN PROGRESS (descent at depth 13) | Installer chain walked function-by-function (F-595..F-626); theft-dependence unmet; tune starvation; record lifetime. Gate: menu LOAD. |

## Execution order — REWRITTEN 2026-09-28 19:4x (supersedes the 18:13 version it replaced)

The 20 rows and their verdicts are **unchanged** — those are real work and they stand. What changed is
the **ordering** and the **gates**. Three edits, each with its evidence.

### Edit 1 — priority 1 is VOID, not "in flight"

The old item 1 was *"Finish the descent (name the stuck function) — in flight."* It is removed.

The 8-round descent (F-611..F-627) was reasoned from the `lr` field of the park sampler. The ledger's
own F-627/F-628 proves that field is a **stale mirror of the last registered guest context, never
cleared**:

- `F598-C6658` — the realloc the `0x821C6DC4` site calls — fired **16 times, last at 18:13:19.977**,
  i.e. zero reallocs in the final ~98 s, while PARK-SAMPLE reported `lr=821C6DC8` for **132 of 203
  samples (65%)**. "A live sample cannot report a return address for a call that stopped happening 98 s
  earlier."
- `rawrip` is worse: resolved with `tools/host_rva_resolve.py build/mcla.map` it is
  `ReadU32BE@GuestMemoryView+0xe1` / `WriteU32BE+0xe1` — the **sampler's own** guest-memory calls, i.e.
  the sampler's `rip`, not the worker's.
- The binding replacement rule is already written down: **"Never compute a percentage of wall time
  from them. Only per-hook atomic counters are live evidence"** (F-627/F-628 method rules 1-2, and
  again in F-631).

So the descent's *individual hook rows* remain valid measurements of what fired; its **synthesis did
not** ("t2 never fires, therefore the stall is inside t1's subtree"). Row 20's "descent at depth 13" is
a trail entry, not a state. **No item below is routed into the descent.** The instrument itself has
since been fixed and now says so out loud — `build/w657.log` prints
`PARK-SAMPLE mirror=STALE(age_ms=104641) … live:{… srva=339d3e3(sampler)} | mirror:STALE/LAST-REGISTERED lr=82131E78`
and `PARK-MIRROR-STACK mirror=STALE(age_ms=…)` — so the F-627 instrument-fix item is **done**, and
the sample fields are now per-field labelled with a `blind=` self-test and a `rows-moved=` count.

### Edit 2 — the two menu-gating MISSING rows are now first among feature work

Rows **#6 Shader** and **#7 Texture** are the only `MISSING` verdicts that stand between the current
state and a visible menu. The 18:13 order did not mention them at all. The citable reason nothing has
reached them is that **no soak has ever produced data for them**: in the last green soak,
`build/w653.log`, `SET_CONSTANT` = 0, `GRCFVF` = 0, `TEX-IMPORT` = 0, and all **15** `DRAW-MARKER`
rows are `prim=1 numIdx=1` — the first is `DRAW-MARKER #1 seq=1 prim=1 numIdx=1` (`build/w653.log:1085`),
one auto-indexed triangle's worth of geometry (`F-604` measured this shape across ~22k observed draws
on `w632`; on the 120 s `w653` the real count is 15). Its 603 `TEXTURE` lines are host blit-framebuffer
setup and `MEMBER-EXPAND-MARK-EARLY`, not guest texture decode. A marker pipe with no data in it
(F-605 proved the pipe, F-606 proved the data is absent) is not a gate to a menu.

### Edit 3 — every gate is a command + an exit code or a log row

No date, no "next session", no vibe. `EXIT=0` below means
`python build/verify_gate.py <new.log> <baseline.log>` returned 0 (exit codes at
`build/verify_gate.py:80-85`: 0 = all gates pass, 1 = a gate failed, 3 = `--strict` and a gate was
UNVERIFIED). Every item keeps the standing per-move gate from the old footer: build green + exe mtime
moved + a **new** log name + marker table + faults zero. No stacking, no bypasses, no borrowed runtime.

### The order

| # | Item | Wake condition (machine-checkable) |
|---|---|---|
| 1 | **Boot-green. Blocks everything below.** The tree is **RED** today. | `verify_gate.py` `EXIT=0` **and** `GETDEV` rows with `arr=` non-zero + `cnt>0` **and** `BOOTPATH` > 0 **and** `C0000005` = 0. Measured today: `build/w657.log` = 1,173 lines vs `build/w653.log` = 166,544; `GETDEV #1 … arr=00000000 cnt=0` (`w657.log:722`); `BOOTPATH`/`DISCCHK`/`F556-C54D8`/`CP-DRAW` all 0 where `w653` had 10/675/1/4,272; `C0000005` 0 → 1. |
| 2 | **F-632 archive offset — the `gpu_device.cpp` half.** A *size* field was used as a *file offset* (`XsfOffsetCandidates`, `src/gpu_device.cpp:1651`). The VFS half already landed (`src/fs/rpf3_nested.{h,cpp}`, `CMakeLists.txt:281-282`). | `F442-SECTION hits > 0` **and** `BDF20 … vehicle0008.lst ret=0` **and** `[0x828CD0AC]` non-zero. In one pass, not split: F-632 lists 8 ordered edits. Its step 8 (`imports.cpp` double-`position`-advance) is **already done** — the F-628 note at `src/kernel/imports.cpp:1781-1787` — so **7 remain**. **Do not touch `kF432SkipZeroCountGrow` (`src/gpu_device.cpp:19964,20014`) in this pass** (F-632 step 9). |
| 3 | **#6 Shader + #7 Texture → first textured draw.** Menu-gating. | A soak row carrying a **non-zero guest constant-bank id** in the root CBV (`SET_CONSTANT` > 0) **and** a texture-import counter > 0 (the 32 refusal buckets at `src/d3d12_backend.cpp:204` are the instrumentation; a refusal total of 0 with 0 imports is a vacuous pass). Until then both are `MISSING` and that is honest. |
| 4 | **#5 Draw-bridge data.** The pipe is built and glass-confirmed (F-605); the missing half is real vertex data (F-606). | `CP-DRAW > 0` **and** `BOOTPATH > 0` **in the same log**, and `DRAW-MARKER` rows whose `numIdx` is not 1. A `CP-DRAW` count with zero `DRAW-MARKER` rows is the F-606 stall reproduced. |
| 5 | **#17/#14 Removal queue — one at a time, each on its own gate.** F98-SKIP, F432, F434, TASKJOIN-SC, the heap SEH net. Never two in one pass (do-not #1/#9). | Each item's own gate, taken from `docs/PROGRAM_GUIDE` §7 plus the keeper it masks: F432's gate is `F442-SECTION hits > 0` **first** (item 2), F434's is a decode that succeeds instead of spinning, the SEH net's is `HEAPLEAK-SUM` `live` plateauing instead of climbing. |
| 6 | **#3 Crash-fault lines — the 101 VMX128 traps.** | `python tools/trap_census.py --fail-over N` → exit 0, one batch at a time. **Correct the tree's own note first**: `src/cpu/vmx128_pack.cpp:250-251` claims the 94 type-5 sites are "all hooked to `mcla_Vupkd3d128_type5`" — measured, `grep -c mcla_Vupkd3d128_type5 generated/ppc_xenon/*.cpp` = **0**, and `generated/ppc_xenon/ppc_recomp.48.cpp:22474` is a bare `__builtin_debugtrap();`. The 101 are **not** wired; `trap_census.py`'s "0 of 101 … wiring gap" line is right and the source comment is wrong. This is regenerator work (`.qoder/skills/mcla-recompiler-regen`), never a hand edit of `generated/**`. |
| 7 | **#9 Audio, #10 Input — when menus exist.** #9 has a hard external blocker: XMA frame decode needs FFmpeg's `libavcodec/xma2dec.c`, which is **not in this repo** (`src/apu/xma_decoder.h:22,440`; Xenia does the same). | First decoded frame, i.e. `apu::XmaKickContext` (`src/apu/audio.cpp:571`) ever reached from the guest. It cannot be: the **XMA MMIO aperture is unmapped**, and the only routed MMIO window is the **cached** `0x7FC80000` (`src/guest_memory.cpp:346,431`). Two sub-tasks first: route the **uncached** alias `0xFFC80000` (it appears today only in a diagnostic formatter, `src/gpu_mmio.cpp:85-86`, never in a gate), and map the XMA aperture. |
| 8 | **#16 Logging / #18 Build hygiene — continuously, never as a feature.** | `python tools/soak_census.py <new.log> <baseline.log>` and `python tools/mitigation_audit.py` (exit 1 = unregistered/stale). |

**Cross-cutting rule for every item above:** a real pipeline state object that **refuses** is correct
under the native charter (F-609); an object that **draws a lie** is not. Never convert a refusal to a
fallback to make a counter move.
