# LONG TODO MASTER — MCLA PC → Playable Game

> **Authoritative ordered backlog. Rewritten+compressed 2026-09-20 (post-W36h).**
> Token-saving reading order: **this file** → `HANDOFF_NEXT_AGENT.md` live block →
> `PROGRAM_GUIDE.md` on demand. All long-form trail was compressed on 2026-09-20:
> `HANDOFF_NEXT_AGENT.md` now carries a session ledger, `EXECUTION_PHASES.md` phase
> ledgers, `ROOT_CAUSE_VALIDATION.md` the F-001…F-039 ledger (append-only). Anything
> deeper lives in git (`git show 8f07a39:docs/<file>`) — grep there, never full-load.
> Every claim below cites a commit or log; commit-only claims are marked UNVERIFIED.
> Older status blocks elsewhere = trail, not truth.

## 0. State (verified 2026-09-20 17:05 — supersedes the 16:23 block below)

- **TREE BUILDS. T37.0 IS DONE.** `build/mcla.exe` mtime **16:41** (moved — rule 12 satisfied),
  `build/cp_nudge19.log` 16:41 was the green attempt. Verified in source: `CpAdvanceGuestPublication`
  now has ONE definition at `src/gpu_cp.cpp:752` in `mcla::gpu` scope, matching the `src/gpu_cp.h:83`
  decl; the 4 formerly-ambiguous call sites are now `:1046/:1111/:1346/:1453`. No mcla.exe/ninja
  running at 17:05, newest log 16 min old → **rule 11 stand-down is lifted, src work is allowed.**
- **#1 BLOCKER IS OUR OWN VEH MITIGATION, not the guest.** See T38.0 — this is new and re-orders
  the backlog. `build/smoke_long2.log` (16:49, 9560 lines, 120 s) contains **703 `code=0xC0000005`
  lines**, all `lr=822FBC28`. The earlier "0 `c0000005`" claim in `HANDOFF_SESSION78.md` §5 is a
  **case-sensitivity false negative** (`grep -c c0000005` = 0, `grep -c C0000005` = 703). Treat that
  claim as void.
- **`build/cache/mcla_pe.bin` IS MISSING** → rule 3 (raw-byte verification) is currently
  **inoperable**, and so are `tools/ppc_disasm.py` + `tools/ida_import_functions.py`. It is dumped
  at runtime by `src/boot_host.cpp:1233`, so any short boot regenerates it. Do this before any
  IDA/raw-byte claim (T38.0 step 1).
- **The type-5 `vupkd3d128` cluster is NOT on the critical path.** `sub_822FBAF8` (the function
  containing the `0x822FBC28` call site, `generated/ppc_xenon/ppc_recomp.49.cpp:20945`) contains
  **zero** `__builtin_debugtrap`/`vupkd3d128`/`vpkd3d128` lines, and the soak has **0 `0x80000003`**.
  ⇒ `PLAN_VMX128.md` Route B stays parked, and **the Clang-20 toolchain blocker is off the critical
  path — do not spend a session installing LLVM.**

## 0b. Prior state (16:23 — trail only, superseded)

- **Committed frontier: W36h** `8f07a39` (TLS allocator `f3bb765`/`b6528ad`, boot-worker trace `e46c386`, boot gate `e1a2435`, GFx loader `cc3a433`, game data + factory `8f07a39`). W36 is documented nowhere else → T37.2 records it.
- **TREE DOES NOT BUILD — live second session fixing it.** `build/cp_nudge*.log` series (13 attempts by 16:23, newest <2 min old = stand down, rule 11): 4× `CpAdvanceGuestPublication` ambiguous `gpu_cp.cpp:1044/1109/1344/1451` (stable all attempts; diagnosis in T37.0) + `src/hooks/alloc_census.cpp` move-injuries (line numbers drift per attempt — read newest cp_nudge log) from the in-flight gpu_device→hooks relocation. gpu_device.cpp untouched since 07:07.
- **Last good boot:** `build/mcla.exe` 14:48 (mtime never moved since — no green build after it, rule 12) + `build/smoke_long.log` (15:18, 2 min): real packfiles (`xarchive_cache.rpf` 2032 MB), TOC76 #69, SUBMIT ×16, GLOBTEX-SERVE alive, threads park, **no fatal** (only `fatal` text = REBASE-POISON census wording). Present = synthetic: guest present-kick ×2 (`native_renderer.cpp:152` census), both `PRESENT-FB` samples = fallback clear rgb(0.06,0.10,0.22) on swap-table slots — F-B reproduced, no real pixels.
- **UNVERIFIED:** "UILOAD executes" (`e1a2435` message) — **0 UILOAD/GFx markers** in smoke_long. Re-verify at T37.3.

Build/soak (Git Bash; MSYS vars REQUIRED or `cmd.exe /c` silently no-ops; `//F//IM` misreads as UNC — `PROGRAM_GUIDE.md` §3):

```bash
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat
cmd.exe /c "taskkill /F /IM mcla.exe"            # before build AND after soak
timeout 120 ./build/mcla.exe > build/w37a.log 2> build/w37a_err.log   # new name every run
```

## 1. Rules (all in force; each cost a session)

1. **Census before fix** — no short-circuit without root cause.
2. **Never edit `generated/**`** — recompiler output, input only.
3. **Raw-byte rule (F-023)** — verify every IDA claim vs `build/cache/mcla_pe.bin` (offset = VA − 0x82000000) or the generated TUs.
4. **One owner per guest address** — grep `src/` before adding any hook/override.
5. **One new log per experiment** — `w37` series; never overwrite.
6. **`timeout` every boot; kill mcla.exe after every soak and before every build** (`cmd.exe /c "taskkill /F /IM mcla.exe"`).
7. **Tree must always compile** — fix the build before adding anything.
8. **Retail content only** (`xarchive_cache.rpf` + audio/music); never `mc4/art`.
9. **No framework rewrites/optimization while the game isn't booting** — parked in `CODE_OPTIMIZATION_PLAN.md`.
10. **Write the trail as you go** (HANDOFF live block + session ledger; F-### ledger; phase ledger; this file's tables). `docs/` is GITIGNORED — `git add -f` new docs or they die on `git clean -xdf`.
11. **Two-session coordination (LIVE 09-20 16:18).** Before build: no mcla/ninja running AND newest `build/*.log` older than ~2 min — fresher = another session mid-experiment: docs-only work. Keep src edits additive.
12. **Stale-exe trap** — after any link attempt verify `mcla.exe` mtime moved before soaking.
13. **No claim without evidence.** Cite log line or commit hash; commit-only claims marked UNVERIFIED until a soak reproduces them.

## 2. Tasks (in order; stop-ship gate each)

**T38.0 — kill the VEH RIP-advance runaway, then root-cause the one genuine AV. NEW #1.**

*Mechanism (verified from `smoke_long2.log` + `src/boot_host.cpp:1011-1039`, not inferred):*
the handler buckets faults by **guest** `lr` and escalates `Rip += 16` (#1) → `Rip += 64` (#2) →
"clean return via `[rsp]`" (#3+) → **`Rip += 4096`** (when the stack slot reads 0). Because the
guest `lr` is frozen at `822FBC28` while the **host** RIP runs away, all 703 faults attribute to one
site and the logged `addr` is the walking RIP, not a data pointer:
`0x3f83a000 → 0x3f920000 → 0x3fab0000 → 0x3fab3000`, exactly +0x1000 per fault, 16:48:43 → 16:49:37
(**53 s of the 120 s soak spent executing unallocated host memory**). The `s_inUILoad` branch at
`:1000` is worse: `Rip += 256MB`.

*Consequence:* the boot-worker thread never returns to guest code after its first AV. It is dead for
the rest of the soak, which is the simplest sufficient explanation for the whole downstream
starvation in the same log — `GFx` 0, `FACTORY` 0, `DRAW_INDEXED` 0, `DRAWDISP` 0, and the CP ring
frozen at `put=11 rptrWB=0000 wb@C71D81BC=00000000` (guest published work, no consumer left).
**So the soak currently measures nothing past 16:48:43.** Do not tune the CP, the GPU or GFx against
it.

*This violates the project's own rules* — rule 1 (no short-circuit without root cause) and
`PLAN_VMX128.md` R5 (never "fix" a trap by skipping the instruction: it leaves stale state and
*looks like progress*). It is a mitigation that destroyed the signal it was guarding.

Steps, in order:
1. Regenerate `build/cache/mcla_pe.bin` with one `timeout 20` boot (rule 3 is dead without it).
2. Make the handler **diagnostic before it is permissive**: on the first fault at an unroot-caused
   `lr`, log guest PC/lr/r3-r12, host RIP, fault addr, and read-vs-execute (`ExceptionInformation[0]`),
   then **park**. Delete `Rip += 16/64/4096` and `Rip += 256MB`. Parking is honest; advancing RIP
   fabricates execution.
3. New soak `w38a`. Read the *single* genuine first fault. Known shape of the site
   (`ppc_recomp.49.cpp:21103-21125`, inside `__imp__sub_822FBAF8`): `r3 = *(u32*)0x82859F68`
   (global object ptr) → `r9 = *r3` (vtable) → `r8 = vtable[+4]` → `mtctr/bctrl`, with
   `r4 = 0x82040F0C` (a name string) and `r31 = 0x82040F0C`. **vtable+4 is `rage::fiDevice::open`**
   per the durable-facts table ⇒ decode the name at `0x82040F0C` (offset `0x40F0C`) and identify the
   callee; the AV is *inside* that callee, and `lr` here is a genuine return address (not sticky-LR,
   since the fault is in the callee body, not after a memset/leaf).
4. Audit the **two other stacked mitigations in this same module** before adding anything (rule 4,
   one owner per address): `boot_host.cpp:971-994` permanently disables `sub_822FA958` and
   runtime-patches its host entry to `0xC3` (RET) when `glr == 0x822F44E0`; and `src/gpu_cp.cpp`
   `:903/:917/:962` re-publishes the CP watermark to unpark the `rptrWB` poll. If step 3's real fix
   makes any of these unnecessary, delete it in the same commit.
5. Acceptance: `grep -c C0000005` on the new soak is **≤ 3** (was 703); no `addr` sequence walking in
   +0x1000 steps; and at least one of `GFx|FACTORY|DRAW_INDEXED|DRAWDISP` becomes non-zero **or**
   `rptrWB` moves off `0000`. If instead a *new* terminal fault appears, that is the real frontier —
   write it up as an F-### entry, do not paper over it.

**T37.0 — green build.** **DONE 2026-09-20 16:41** (verified §0: single `CpAdvanceGuestPublication`
definition at `gpu_cp.cpp:752`, exe mtime moved, `smoke_long2.log` taken after it). Kept for trail —
the original diagnosis was: TWO functions, `gpu_cp.h:83` (declared in `namespace mcla::gpu`) vs a
definition inside the **anon ns opened `:22`** (closed `:790`; `mcla::gpu` closes `:1728`). Anon-ns
member = separate entity visible throughout `mcla::gpu` → ambiguous at 4 sites outside the anon ns;
the `:576` call was inside it (innermost lookup, no error); `patches.cpp:237` already qualified.
Fix applied: move the definition out of the anon ns to `mcla::gpu` scope (helpers
`GuestPub`/`g_pubMutex`/`g_pubStates` stay anon). Do NOT just qualify call sites — that compiles then
link-errors (header fn left undefined).

**T37.1 — land reorg** as one commit `w37a: module reorg (...)`, no behavior changes mixed in. README/PROGRAM_GUIDE layout already updated 09-20 — verify, don't redo. Acceptance: build green from committed tree; status clean except logs.
> **SEQUENCING DECISION (17:05): do T37.1 BEFORE T38.0.** The dirty tree already mixes the module
> reorg (27 renames into `common/ cpu/ fs/ rage/ renderer/ tools/validators/`) with the T37.0 build
> fix and the doc compression. T38.0 edits `src/boot_host.cpp`, which is already modified — committing
> after that would entangle a behavior change into the reorg and break rule 10's auditability.
> Do **not** try to split the existing mix: the build is green *as it stands*, so land it as one
> commit titled `w37a: module reorg + T37.0 anon-ns build fix + doc compression` and say in the body
> that it is not purely moves. Remember `git add -f docs/` (`.gitignore:9`).
> Also fold in the two loose ends from `HANDOFF_SESSION78.md` §4: move `fix_stubs_iter.py` +
> `fix_stubs_self.py` from the repo root into `tools/` (decision: **move them**, and fix the
> `PROGRAM_GUIDE.md` §5 citation to match), and delete the root `CODE_OPTIMIZATION_PLAN.md` duplicate
> in favour of `docs/CODE_OPTIMIZATION_PLAN.md` (its Phase 0 is VOID per do-not #11). Root junk to
> drop in the same commit: `11` (0 B), `err.txt` (0 B), `NUL.obj` (3 MB build artifact).

**T37.2 — write W36 record** (from the 6 commit diffs + code): per commit list guest addresses owned, host files, new log markers, evidence lines. Output, in the compressed doc set: one row in the HANDOFF session ledger plus the W36 detail it links to, a row in `EXECUTION_PHASES.md`'s phase ledger, and F-040+ entries in `ROOT_CAUSE_VALIDATION.md` Part 3. Acceptance: an agent who never saw W36 can name every new address owner and marker from docs alone.

**T37.3 — re-baseline.** Boot ×2 ×120 s (`w37b`, `w37c`); count markers `UILOAD|GFx*|FACTORY*|NATIVE-PRESENT|FRAME-END|SUBMIT|DRAWDISP|DRAW_INDEXED|TOC76-RET|INFLATE|PKG-SUBST|PRESENT-FB|fatal`. **If UILOAD/GFx still 0: verify W36f claim at code level (marker gating? game-data condition?) before Wave A.** Record fork: (a) UI/GFx progressing → T37.4; (b) GPU/draw-starved → T37.5; (c) new crash family → census per rule 1 first.

**T37.4 — Wave A: UI/GFx → authored pixels.** Re-derive the job#2/swfC delivery state from code (W36 GFx path may have replaced the old PKG-SUBST host-serve — delete stale hooks if so, one owner per address). Acceptance: parse past legals (no font/fixup fatals), 0× CDCD at FDBF8 place-pass.

**T37.5 — Wave B: real framebuffer (M3).** F-B/F-C spec: census `EnqueueNativePresent` — dump `[obj..obj+0x30]` (24 BE words) for obj ∈ {C61D8818, C61D8928, C625894C}; one-hop follow words in 0x40000000–0xE0000000 (first 8 hits); decode `swap_info` 0x004E0D30; correlate TEXCREATE/EDRAM surfaces ≥1280×720 (3.5 MB @32bpp / 1.8 MB @16bpp); detile Xenos `7E`/`8E` → BGRA → `PresentBgra`. Never read EDRAM linear. Acceptance: PRESENT-FB samples vary plausibly; non-flat window 10+ s.

**T37.6 — Wave C: draws.** Verify PKT-CAP still Type-3=0; minimal GPU CP (RT, viewport/scissor, draw indexed); first visible = clear/spinner/legal quads. Acceptance: `DRAW_INDEXED > 0` in 120 s.

**T37.7 — Wave D: input** (`src/kernel/xam.cpp`): `XamInputGetState` (thunk detour failed historically — import-stub or non-hotpatch hook); SDL3→XINPUT map (dpad/stick=nav, A=accept, B=back; later triggers/sticks); `XINPUT-STATE` 1/s overlay. Acceptance: menu cursor moves.

**T37.8 — Wave E: audio** (`src/apu/`): census 0-returning stubs; confirm audlo TOC `.xma`; `XAudio2SubmitRenderDriverFrame` → SDL3 callback (silence-stub first, XMA decode later). Acceptance: any non-zero audio, no crash.

**T37.9 — Wave F: world.** Post-UI streaming census (retail only); INLINE-EXEC payloads (XCompress + raw); vehicle/camera/HUD; free-roam spawn. Acceptance: car spawns, camera follows, 60 s no fatal.

**T37.10 — Wave G: polish.** Dtor poison AVs; log-flood counters (KWFSO/PKT-CAP/PARK-SAMPLE); frame pacing; `.bik` skip flag; save/load.

## 3. File map (post-reorg; re-list before editing — hooks/ is in flight)

`src/` root: boot_host, main, app, patches (registry only), **gpu_device.cpp ~11.5k lines (monolith, being split)**, gpu_cp, gpu_mmio, d3d12_backend, native_renderer, render_thread, renderer_mode, guest_memory, dispatch_guard, early_init, capture_hooks, frame_trace · `src/hooks/`: PPC_FUNC bodies from patches.cpp, now absorbing gpu_device (alloc_census ~94 KB+, LIVE) · `src/common/`: logging.h, cvar.h · `src/cpu/`: vmx128_pack, guest_thread.h, ppc_context.h · `src/fs/`: vfs_rpf · `src/rage/`: rage_asset_pipeline · `src/kernel/`: imports (Nt*/Ke*/Xam*), memory, heap+o1heap, xam (input), xdm, guest_thread · `src/renderer/`: xenos decode, shader IR→DXIL, caches · `src/apu/`, `src/user/` · `tools/validators/`: phase-gate exes · `generated/ppc_xenon/`: 176 TUs, INPUT ONLY · `build/`: mcla.exe, logs, `cache/mcla_pe.bin`.

## 4. Do-not (each cost ≥1 session; carry forward)

1. Edit `generated/`. 2. Regen without the reproducibility gate (`PLAN_VMX128.md` §4 Route B step 3; TU count must stay 176). 3. Poke shader dict / patch `byte_827D5C70` / stub fatals. 4. GETDEV-redirect (F-027). 5. Write `0xA00xxxxx` scratch from SeedPreBootSlots. 6. Treat `525DE064` as magic (stack residue). 7. Depend on `mc4/art`. 8. Remove hash-table hydration until INSERT proven clean. 9. Stack short-circuits without root cause. 10. Leave mcla.exe running. 11. Follow root `CODE_OPTIMIZATION_PLAN.md` Phase 0 (edits generated/) — VOID by rule 2. 12. "Fix" VMX traps by skipping instructions (R5 — stale vectors). 13. Treat PresentKick r4 as framebuffer (F-B: swap-table timestamp slot). 14. Build caller chains from census `lr` after memset/leaf calls (sticky-LR; use xrefs + arg regs).

## 5. Done = playable loop

Legal/menu on screen → navigable → race/free-roam starts → controllable car, camera follows → audio present → 60 s soak no fatal.

## 6. W36 commit map (seeds T37.2)

`e46c386` queue trace 19 files +8.9k (task_dispatch_trace +913) · `f3bb765` gpu_device +52 census sub_8218A008 · `b6528ad` TLS allocator + VEH, dropped 461 MB generated/default blob · `e1a2435` boot gate (boot_host, gpu_device +100, imports) · `cc3a433` GFx vtable (gpu_device +41, CMake +1) · `8f07a39` game data + GFx factory; validators re-added (now moving to tools/validators).

*2026-09-20. Next action: **T37.0** (after rule-11 check).*
