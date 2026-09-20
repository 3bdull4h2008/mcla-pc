# LONG TODO MASTER — MCLA PC → Playable Game

> **Authoritative ordered backlog. Rewritten+compressed 2026-09-20 (post-W36h).**
> Token-saving reading order: **this file** → `HANDOFF_NEXT_AGENT.md` live block →
> `PROGRAM_GUIDE.md` on demand. All long-form trail was compressed on 2026-09-20:
> `HANDOFF_NEXT_AGENT.md` now carries a session ledger, `EXECUTION_PHASES.md` phase
> ledgers, `ROOT_CAUSE_VALIDATION.md` the F-001…F-054 ledger (append-only — grep it, the range drifts
> every session). Anything
> deeper lives in git (`git show 8f07a39:docs/<file>`) — grep there, never full-load.
> Every claim below cites a commit or log; commit-only claims are marked UNVERIFIED.
> Older status blocks elsewhere = trail, not truth.

## 0a. Newest facts (2026-09-20 20:20, tooling session) — read before §0; it adds three facts and changes none of §0's state

- **`build/w38e.log` (20:02, 175 MB / 1,860,449 lines) is poisoned as a baseline — F-054.** The
  crash-path recovery that was still in the binary at that build fired **616,824 times in 31.7 s**
  (`VEH: permanently disabled sub_822FA958` + `patch applied, continuing`, exactly 1:1), so 2 of every
  3 lines in that log are one host loop and its `C0000005` = 616,825 against **1** in `w38c.log`. Its
  guest markers are unchanged from `w38c` (`GFx` 9, `VdSwap[` 2), i.e. it records no guest advance and
  no guest regression. **Compare against `w38c.log`, never `w38e.log`.** `tools/soak_census.py` now
  prints this itself — a `LOG QUALITY` line naming the dominant repeated shape, and a
  **POISONED** verdict when one mitigation/VEH shape accounts for ≥2% of the log (a benign poller
  dominating is listed but not flagged). Verified: `w38e` → 33% + 33% both POISONED; `w38c`/`w38b` →
  the `WAKE[KWFSO]`/`WAIT[KWFSO]` pollers listed, no verdict. 51 s on a 175 MB log.
- `tools/addr_owners.py` gained `--gates <addr>` (F-053): each claim site's enclosing-function
  branch/return lines, printed verbatim and uninterpreted, with the tie broken by grepping the soak
  for the installer's own message. Its two unverified causal sentences are deleted. Guest VdSwap
  `0x827BD6E4` is **resolved, not fixed** — one owner body (`Hooked_VdSwap`) in all three
  `renderer_mode`/`mcla_patch_groups` configurations; T39.7(1) is closed and only T39.7(2) survives.
- Two CVar facts that are easy to get wrong and are cited nowhere else: `build/cache/mcla.toml` does
  **not** exist, so `renderer_mode` runs at its compiled default `"native"`
  (`src/renderer_mode.cpp:8`, not `"legacy"` as `src/app.cpp:85-87` says) and `mcla_patch_groups` at
  `"all"`; and `config/mcla_manifest.toml:16`'s `renderer_mode = "legacy"` is read by **nothing** in
  `src/` (zero grep hits), so that manifest key is inert.

## 0. State (verified 2026-09-20 20:40 — supersedes the 19:55, 19:20, 17:57, 17:45, 17:05 and 16:23 blocks below)

- **T38.3(a)(b)(c) + the three self-contradictory gate stages ARE DELETED → F-055. The boot worker now
  reaches UILOAD for the first time in the project's history, and new #1 is the atArray allocator
  chain behind the one surviving fault.** Soak `build/w38f.log` (10,001 lines, `BOOT_RC=124`) against
  baseline `build/w38c.log`: `C0000005` **1 → 1**, every recovery marker **→ 0** (the `0xC3` host-entry
  patches, the `Rip += 256MB` advance and the float-div-0 park are gone from `src/boot_host.cpp`; the
  handler now declines → generic park), and `w38f.log:3885-3890` carries
  `event1-ret r3=00000000` → `event2-ret r3=00000000` → `UILOAD-enter r3=[82830998]` →
  `UILOAD-param r3=C9A24500` with **no** `UILOAD-ret`. The deleted stages were `sub_823043F8`,
  `sub_82304348` and `sub_821FC008` — the driver seeded `[0x8288E6F0]=1` / `[0x82830B14]=0` and then
  called exactly the functions those flags tell the guest to skip (`0x82131020 lwz r11,4(r29)` +
  `beq -> 0x8213103C`, and `0x821310C0`; F-055 §1). **The surviving fault** (`w38f.log:4416-4421`) is a
  **write to guest `0xE0`** (`Param[1]=0x1000000E0`, `tag=forced-boot-gate`,
  `r1=8EFFF510 lr=822F44E0 r7=000000E0 r9=827E0000 r10=00000010`), and `lr-4 = 0x822F44DC` is
  `bl 0x822FA958` — the same leaf the deleted `0xC3` mitigation used to patch out ("broken atArray
  allocator chain", `src/gpu_device.cpp:8381`). `sub_822FA958` is a 22-instruction leaf that reads
  `[0x8288E334]` (image bss = 0, and **no `stw` with immediate `0xE334` exists anywhere in
  `0x82130000`–`0x82800000`**, two negative scans) and stores floats relative to it. ⇒ Do **not** arm
  `[0x8288E334]` (do-not #9): the next step is to stop seeding the gate's flags and let
  `sub_82131008` run its own init. `DRAW_INDEXED`/`DRAWDISP` still **0**, CP ring still
  `put=11 rptrWB=0000`. Tree green (exe 20:10), `mcla.exe` killed, nothing committed.

- **T38.2b WAS DONE (19:55) → F-050 + F-052.** The published-context dump works
  (`w38c.log:4089` `ppc ctx=0x8a7b2fefc0 tag=forced-boot-gate`), the register set moved, and the one
  surviving `C0000005` is **our own gate calling guest `sub_82304348` with `this = 0`**
  (`src/gpu_device.cpp:1203-1206`; `freshVolatiles()` clears only `r5`-`r10`) — a host-fabricated call
  frame, not lost guest progress. Nothing is armable to hide it (do-not #9). F-050 adds two facts
  F-052 lacks: the dump's `+0x144` is a **host** code offset (see new do-not #18), and the block that
  offset falsely points at, guest `0x8230448C`, reads a **fourth** bss singleton
  `0x82839D70` (rage static-instance pattern; 4 writers `0x82180390`/`0x821809FC` clear it,
  `0x82186150`/`0x82186240` publish it; vtables `0x82009D34`/`0x8200AAF4`; **0 owners** in `src/`).
  Built green after the fix (`build/w38d_build.log`, `BUILD_RC=0`, exe 19:52) — **not soaked**.

- **T38.2 IS DONE → F-046 + F-049 (soak `build/w38b.log`, 120 s, 11138 lines, `BOOT_RC=124`).** The
  residual AV is **root-caused**: `Param[1]=0x7E780000` is uniquely `PPC_LOOKUP_FUNC`'s slot for guest
  target **0** (the new `probe` lines — `w38b.log:4022-4027` — identity-test it and rule out every
  dumped register as the index), a null target becomes a *call* rather than an earlier fault because
  `ReadGuestU32` swallows the validity bool and returns 0 (`src/guest_memory.h:82-86`, and
  `PPC_LOAD_U32` *is* that helper at `src/ppc_context.h:57`), and — decisively — **the crash dump's
  `lr` and GPRs belong to the boot worker's root `PPCContext`, while the fault happened inside the
  host-forced BOOT-GATE, which runs every stage on an unpublished local `PPCContext g{}`**
  (`src/gpu_device.cpp:1121-1127`, `:1187-1236` vs `g_faultCtx = &ctx` at `src/boot_host.cpp:706`;
  proof: `w38b.log:3864` and `:4021` carry the *same* `lr`/`r3`/`r8`/`r9` 1.044 s and one GFX-BLOCK
  apart). So the AV is a **mitigation artifact of our own gate driver, not lost guest progress**, and
  the register-based readings in F-044(c)/F-045 are void as attributions. **New #1 = T38.2b**
  (publish the faulting context, one soak, then name the site). Census of the named frame is in
  F-049: `0x82839F68` = the shader/preload-list manager singleton (vtable `0x8200AE8C`, whose slot +4
  is the host-overridden `sub_821873E8`), dumped `r4` = the string `"star_glow"`, and
  `sub_822FBAF8` has **five** indirect-call sites — so the old "one `ctr`-inclusive dump away" framing
  is unreachable anyway: `src/ppc_config.h:5,9,10` make `ctr`/`xer`/`r11`/`r14`-`r31` host locals
  that no VEH handler can read (14 build errors proved it).
- *Uncommitted now (19:20):* `src/boot_host.cpp` (the probe block, builds green),
  `docs/ROOT_CAUSE_VALIDATION.md` (F-044…F-049), `docs/LONG_TODO_MASTER.md`, `.gitignore`,
  `AGENTS.md`, `.qoder/`. New logs: `w38b.log`, `w38b_build.log`, `w38b_build2.log`, `w38b_err.log`.

- **COMMITTED.** `5eb9932` = module reorg + the `.gitignore` data-loss hole closed + the VEH
  RIP-advance runaway removed; `8953cea` = stray root `gpu_device.cpp` dropped. **T37.0 and T37.1
  are DONE** — the 17:05 sequencing note below ("do T37.1 BEFORE T38.0") is satisfied, not open.
  Uncommitted now: `docs/ROOT_CAUSE_VALIDATION.md` (F-040…F-043) + new `AGENTS.md`/`.qoder/` (§7).
- **#1 BLOCKER = the guest never reaches its own GFx loader construction** — the 17:45 bullet below
  ("#1 BLOCKER = GFx loader vtable mismatch") is **VOID, see F-044**. T38.1's raw-image census
  (17:57, no rebuild) shows: `0x8206DFAC` is produced by exactly ONE guest site
  (`sub_82482008+0x18` @ `0x82482020`, `stw r9,0(r3)`), the loader ctor `sub_824C6F08` installs
  `0x820736DC`/`0x820736B0` correctly at `0x824C6F28-38` and then **calls `sub_82482008` twice**
  (`0x824C6F48`, `0x824C6F50`), so `vt0=8206DFAC` **is** the post-construction state ⇒
  `GFX-CTOR-VT-MISMATCH` (`src/gpu_device.cpp:1156`) compares a mid-construction expectation against
  post-construction memory and proves nothing. And in `w37a.log` the guest's real movie-ctor wrapper
  `sub_82482F78` appears **0 times** while `824C6F08` appears once (our forced host call) — the guest
  builds no loader, so the `0x82073xxx` scan at `:5251-5254` finding nothing is honest. The whole
  `GFX-BLOCK` (`src/gpu_device.cpp:1131-1165`) is a fabricated stand-in → catalogue at T38.3.
  Frontier therefore = **why the boot-gate thread dies after 2 `GATE-STAGE` lines**
  (`w37a.log:3797-3798` → AV `:3969`) → **T38.2**. *(19:20: that death is now explained — F-046.)*
- *Superseded 17:45 bullet, kept for trail:* "#1 BLOCKER = GFx loader vtable mismatch
  (`GFX-CTOR-VT-MISMATCH … want 820736DC/820736B0`)". The counts were real (`w37a.log`: `GFx` 9,
  `UILOAD` 1, `C0000005` 1, `GFX-CTOR-VT-MISMATCH` 1, `W34-NOGFX` 1; `DRAW_INDEXED` 0; CP
  `put=11 rptrWB=0000`) — the causal reading of them was not.
- **The VEH runaway is closed and measured** (F-040): `C0000005` **703 → 1**, recovery lines → 0,
  T38.0 acceptance (`≤ 3`) **met**. The one residual AV (`w37a.log:3969-3988`,
  `read of 0x7E780000`, `lr=822FBC28`) is **not** root-caused and kills the boot worker thread —
  F-043 supersedes both earlier attributions of it and shows the crash dump is missing `ctr`, which
  is the only register that can settle it → **T38.2** (logging-only change, one soak).
- **`build/cache/mcla_pe.bin` is back** (10,354,688 B @ 17:14) → rule 3 is operable again. The
  17:05 note below saying it is MISSING is void.
- **Route B / VMX128 still off the critical path** (17:05 note below holds: `sub_822FBAF8` has zero
  `__builtin_debugtrap`, soak has zero `0x80000003`). Do not install LLVM.
- **Agent tooling landed but not yet in force:** `AGENTS.md` + `.qoder/settings.json`
  (`ida-pro`, `renderdoc`) + 5 project skills (`mcla-boot-cycle`, `mcla-guest-raw-decode`,
  `mcla-log-census`, `mcla-finding-ledger`, `mcla-recompiler-regen`). Needs `/mcp reload` + the
  first-use trust prompt → **T39.1**. Conflict register: §8.

## 0x. State (verified 2026-09-20 17:05 — trail, superseded by §0)

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

**T38.0 — kill the VEH RIP-advance runaway, then root-cause the one genuine AV.**
**STATUS 17:45: step 1-2 + acceptance DONE** (removed in `5eb9932`; `w37a.log` `C0000005` = 1 vs
baseline 703, recovery lines 0 — F-040). **Steps 3-4 are still open** and are now T38.2/T38.3; the
step-3 address and callee claims below were **wrong** — see F-043 (the global is `0x82839F68`, the
`0x82859F68` here is a `lis` sign-extension slip, and "vtable+4 = `rage::fiDevice::open`" is not
supported by the raw words).

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
   **(19:25 correction, F-046/F-049 — do not act on the last clause.)** Global is
   `0x82839F68` (shader/preload-list manager singleton, *not* `rage::fiDevice` — its vtable
   `0x8200AE8C` is followed by `"preload.list file missing in '%s'"`/`".shader"`/`".fx"`), the name
   decodes to **`"star_glow"`**, and the "genuine `lr`" claim is **false**: the dumped `lr`/GPRs come
   from the boot worker's root `PPCContext` while the fault is in the gate's unpublished `g`, which is
   precisely why T38.2b exists. Step 2 also under-delivered: `Rip += 256MB` and the `0xC3` patches are
   still live (`src/boot_host.cpp:1003`, `:1040`, `:982`, `:1027`) → they belong to T38.3.
4. Audit the **two other stacked mitigations in this same module** before adding anything (rule 4,
   one owner per address): `boot_host.cpp:971-994` permanently disables `sub_822FA958` and
   runtime-patches its host entry to `0xC3` (RET) when `glr == 0x822F44E0`; and `src/gpu_cp.cpp`
   `:903/:917/:962` re-publishes the CP watermark to unpark the `rptrWB` poll. If step 3's real fix
   makes any of these unnecessary, delete it in the same commit.
5. Acceptance: `grep -c C0000005` on the new soak is **≤ 3** (was 703); no `addr` sequence walking in
   +0x1000 steps; and at least one of `GFx|FACTORY|DRAW_INDEXED|DRAWDISP` becomes non-zero **or**
   `rptrWB` moves off `0000`. If instead a *new* terminal fault appears, that is the real frontier —
   write it up as an F-### entry, do not paper over it.

**T38.1 — GFx loader vtable mismatch. DONE 17:57 — the premise was FALSE; see F-044.**
*What the census found (all raw-image, `mcla-guest-raw-decode` arithmetic, no rebuild):* steps 1-2 ran
and (i) `0x8206DFAC` has one producer in the image (`sub_82482008`, stored at `[arg+0]` by
`stw r9,0(r3)` @ `0x82482020`), (ii) the loader ctor `sub_824C6F08` writes the expected
`0x820736DC`/`0x820736B0` correctly with `this` in **r3** (`mr r31,r3` @ `0x824C6F1C`) and then calls
`sub_82482008` twice, which legitimately re-types the slots — so the host's `GFX-CTOR-VT-MISMATCH`
gate (`src/gpu_device.cpp:1156`) is a mid-vs-post construction comparison and is **worthless as a
defect signal**, (iii) step 3's question ("is `CA71D480` guest-allocated?") answers itself the other
way: it is `mem.Alloc(1024)` from the host, and the guest's own ctor wrapper `sub_82482F78` never
runs (`w37a.log` count **0**), so no guest loader exists to find.
*Deferred, deliberately not done:* the gate's wording and the `GFX-BLOCK` fabrication are handled at
**T38.3** (catalogue or delete), and the `W34` scan predicate must NOT be widened to accept
`0x8206Dxxx` — that would invent loaders out of sub-object memory (do-not #15).
**Follow-on work this spawned → T38.2b (#1) and T38.3.**

**T38.2 — DONE 19:20 → F-046 + F-049, and its own premise was wrong twice over.** (i) `ctr`, `xer`,
`r11` and `r14`-`r31` are **not members of `PPCContext`** — `src/ppc_config.h:5,9,10` make them C++
locals inside each generated function, so no VEH handler can ever print them (14 build errors, not an
opinion). The substitute that worked was identity-testing `Param[1]` against
`PPC_LOOKUP_FUNC(base, y)` for the candidate `y`s already in the struct — three added lines at
`src/boot_host.cpp:736-760` + `:861-890`, and `w38b.log:4023` answered it: the index was **0**.
(ii) The "32-bit truncation" framing above is **void**: with `g_base=0x100000000` the sum is correct
64-bit arithmetic that wraps *below* the window because `(uint32)(0 − 0x82130000) * 2` sign-extends
(host `rcx=0xFFFFFFFEFBDA0000`), and `0x7E780000 + 2y` equals `Param[1]` only at `y = 0`.
(iii) The dump's `lr`/GPRs are the **root** boot context (`g_faultCtx = &ctx`,
`src/boot_host.cpp:706`), not the faulting one — see §0 and F-046(3).

**T38.2b — *was* #1, now CLOSED (see the 19:50 block below). Make the crash dump name the faulting
*context*, then attribute the null call.**
Logging/publishing only, no behaviour change, one soak (`w38c.log`). The gate driver calls every guest
stage on a stack-local `PPCContext g{}` (`src/gpu_device.cpp:1121-1127`, stages `:1187-1236`) that is
never published, so `g_faultCtx` and `SetPPCContext`/`g_ppcContext` (`src/boot_host.cpp:701-706`) both
point at the wrong object whenever the fault is gate-driven — which F-046 says it is. Do the cheapest
of these: set `g_faultCtx = &g` (and the TLS `g_ppcContext`) around the forced stage calls and restore
on exit, or stop using a synthetic context and run the stages on the caller's `ctx`. Print one more
line naming which context the dump came from, so a future reader cannot confuse them.
**Gate:** the AV line's GPR set must *move* (different `r1`) and the `probe` block must then match one
of the dumped candidates; only after that, name the site — candidates are the **five**
`PPC_CALL_INDIRECT_FUNC(ctr.u32)` returns in `sub_822FBAF8` (`0x822FBB20/BC28/BC60/BD78/BDA4`,
`generated/ppc_xenon/ppc_recomp.49.cpp:20945-21334`) plus every other unguarded indirect site
(`dispatch_guard.cpp:36-37` covers exactly **one** guest address, `0x8218CC94`). Write the answer as
**F-050**. **Do not** arm `0x82839F68`, a vtable slot or a call target to make the AV disappear —
F-046(c): the AV is inside our own mitigation, and T38.3 may delete the whole gate driver, in which
case this fault is expected to go away with it (rule 1, do-not #9).

**T38.2b — CLOSED 19:50 → F-052** (census of the live session's `build/w38c.log`, 19:39, 9,726 lines, vs
`w38b.log`). **The gate above is met**: `r1` moved `8EFFF920`→`8EFFF7C0`, the fault `lr` moved
`822FBC28`→**`8230436C`**, `C0000005` stayed **1**, `VEH` 2→**1** (only the honest
`VEH-NEUTRAL … declining`), and the probe still names guest target **0**
(`w38c.log:4090`, `:4092-4096`, `:4113`). The frame names itself:
`generated/ppc_xenon/ppc_recomp.50.cpp:5642` sets `ctx.lr = 0x8230436C` immediately before
`PPC_CALL_INDIRECT_FUNC(ctr.u32)` in `__imp__sub_82304348` (`:5615`), and `sub_82304348` has **0 owners**
in `src/`+`config/`. **Causal answer: `src/gpu_device.cpp:1203-1206` calls that guest function from the
host-forced gate on the value-initialised `PPCContext g{}` (`:1123`) and `freshVolatiles()`
(`:1193-1196`) clears only `r5`-`r10`, never `r3`/`r4` — so `this` is 0, three pointer-chasing loads get
laundered to 0 by `ReadGuestU32` (`src/guest_memory.h:82-86`), `ctr` becomes 0 and the AV is the call
through it.** `:1236-1239` already skips `sub_82304398` for exactly this reason, so the rule was known
and this is the site where it was missed; `sub_823043F8` (`:1198-1201`) has the same shape. ⇒ **The
last residual crash is a host-fabricated call, not lost guest progress.** Do NOT arm
`0x82839F68`/`0x82830ACC`/a vtable slot (do-not #9). Next action = **T38.3(e)**: delete the gate driver
and the `GFX-BLOCK`, which F-051 shows is provably safe for the (a)(b)(c) paths (0 fires in both honest
soaks). → **F-050 written 19:55** (the reserved causal summary): gate verdict met, and it adds the
host-offset trap below plus the `0x82839D70` singleton census of the block that trap points at.

**T38.3 — audit the remaining stacked mitigations in the crash/TLS path (rule 4, do-not #9).**
> **STATUS 2026-09-20 20:40 — (a)(b)(c) DONE (deleted, not documented; F-055), (e) PARTIAL.** The three
> crash-path recoveries are gone from `src/boot_host.cpp` (verified by census: all their markers 0 in
> `w38f.log` while `C0000005` stays 1), and the forced driver's stages 1/2/6 (`sub_823043F8`,
> `sub_82304348`, `sub_821FC008`) are deleted because the driver's own flag-seed tells the guest to
> skip them. **Still open: (d) the `sub_821873E8` TLS-dead branch, (e) the `GFX-BLOCK` (left in place
> this soak deliberately, so the UILOAD delta stays attributable to the stage deletions), and the
> `[0x8288E6F0]=1` / `[0x82830B14]=0` / `[0x82830ACC]=0` seeds themselves** — see new **#1 = T38.3f**
> below. Do not add new mitigations meanwhile.

**T38.3f — NEW #1: stop seeding the gate's flags and let `sub_82131008` run its own init (the
remainder of T38.3(e): the whole forced driver is a stand-in).** The residual AV is now one specific
host-visible fact: a **write to guest `0xE0`** at `lr=822F44E0`, i.e. inside
`0x822F44DC bl 0x822FA958` — the 22-instruction `sub_822FA958` leaf that chases
`[0x8288E334]` (image bss 0; no producer `stw …,0xE334(…)`, negative-scanned across
`0x82130000`–`0x82800000`). F-055 §1-§2. Acceptance: delete the three flag-seeds plus the remaining
forced stages, so `sub_82131008` is entered once with a real `r1`/`r13` and its own branches decide
what runs; then census `UILOAD-enter`/`-ret`, `C0000005` and the CP ring against `w38f.log`. Do **not**
hand-write `[0x8288E334]`, `[0x8288B9AC]` or any vtable to make the store land (do-not #9/#18/#19) —
if the guest cannot build the allocator table itself, the finding is *that*, and it is worth more than
a passing store.

**Old T38.3 text (the original enumeration, kept for the (d)/(e) items still open):**
Three are live and none is in `PROGRAM_GUIDE.md` §7's table: (a) `boot_host.cpp` ~`:932-951`
float-div-0 at `lr=0x82133440` → writes `0xC3` (RET) over the **host entry of `sub_823D91F8`** and
parks the thread forever; (b) `~:971-994` `isKnownCrashSite` → sets `s_skipSub822FA958` and writes
`0xC3` over `sub_822FA958`'s host entry; (c) `~:960-1003` illegal-instruction / `s_inUILoad`
`Rip += 256MB` "nuclear advance". Plus two **fabrications** to catalogue (F-044/F-045 corrected both
against the earlier "shape bug" theory): (d) the `sub_821873E8` TLS-dead branch
(`gpu_device.cpp:1035-1101`) builds a 16-byte allocator object + vtable and stores
`__xtl_alloc` at `vtable+8` — the **shape is right** (guest reads `[obj+0]` then `[vt+8]`, F-045),
so this one is a *substitution*, not a defect; keep or delete on evidence, not on suspicion.
(e) the `GFX-BLOCK` at `gpu_device.cpp:1131-1165` — host `Alloc(1024)` + zero-fill + forced
`sub_824C6F08` + a vtable expectation that the ctor itself overwrites (F-044): it produces no guest
loader and no UI, and its `GFX-CTOR-VT-MISMATCH` line should be deleted or downgraded so it stops
being read as a blocker. Gate: each one either deleted (because T38.2 removed the need) or
documented in §7 as a named mitigation with its evidence line. Do not add new ones meanwhile.

**T38.4 — `swfCMD::Fixup - unknown type 0xB7`.** Pre-existing (F-042: identical in
`smoke_blue2.log:11129,11143`), fires at `lr=0x8260A8CC` with `r4=0xB7 r5=B7B6D9B4` and is absorbed
by the host `FATAL-SOFT-RESOURCE-PARK` (another §7-uncatalogued mitigation). `0x8260A830` is the
"Invalid fixup" walker (F-036) and the preceding census line is
`P9-B588 #00003 node=B7B6D9B4 type=B7`. Steps: enumerate which SWF tag types the walker handles vs
the `type=` values the place-walk actually feeds it, from the raw image — this is a **C/E-class data
question** (wrong container bytes) before it is a code question. Gate: a table of observed `type=`
values with counts, then a decision. Only after T38.1 (same thread, different symptom).

**T38.5 — CP consumer `rptrWB=0000` / `put=11`.** **DEFER — do not tune the CP, GPU or GFx against
a soak whose boot-worker thread died at the AV** (F-040 says everything past the fault is the GPU
poller tick, F-030). Re-read only after T38.1 and T38.2 land; if `rptrWB` is still `0000` with the
boot worker alive, `src/gpu_cp.cpp:903/:917/:962` (re-publish watermark to unpark the poll) is the
next thing to audit — that is mitigation (d) of the §7 table and it must be proven unnecessary.

**T39.1 — land the agent tooling and put it in force.** `AGENTS.md`, `.qoder/settings.json`
(project MCP: `ida-pro` via `~/.local/share/mcp/ida-bridge.py`, `renderdoc` via
`python -m renderdoc_mcp`) and `.qoder/skills/{mcla-boot-cycle,mcla-guest-raw-decode,mcla-log-census,
mcla-finding-ledger,mcla-recompiler-regen}/SKILL.md` exist on disk; skills are already auto-discovered.
Steps: run `/mcp reload` and accept the project-MCP trust prompt, then `qodercli mcp list` to
confirm both servers, then **verify `ida-pro` end to end** (it `taskkill`s `idalib-mcp.exe` and
re-opens `build/game_data/default.xex` — coordinate with any session already inside IDA, rule 11).
Gate: one real IDA query answered, one RenderDoc capture listed. Commit with
`git add AGENTS.md .qoder .gitignore docs/` (no `-A`).

**T39.2 — one source of truth for MCP config.** `opencode.json` (+ `.opencode/`, both gitignored)
declares the same two servers in a different schema; `.gitignore` also ignores `.mcp.json`, a file
Qoder does not read (don't create it). Decide the canonical one (suggested: `.qoder/settings.json`
for Qoder, `opencode.json` left for the other tool but cross-referenced from `AGENTS.md`) and add a
header comment to each pointing at the other so they cannot drift silently.

**T39.3 — root junk + citation fix.** Untracked and NOT ignored: `11` (0 B), `err.txt` (0 B),
`NUL.obj`, `crash_dump.txt`, `crash_log_early.txt`, `write_opt_plan.bat`,
`GITHUB_APPEAL_REPLY.txt`/`GITHUB_APPEAL_TEMPLATE.txt`, `fix_stubs_iter.py`, `fix_stubs_self.py`,
`mcla_jts_regen.toml` (obsolete span experiments — the stub work landed in `75ed486`, census is 0),
and the duplicate root `CODE_OPTIMIZATION_PLAN.md` (its Phase 0 is VOID, do-not #11). Also
`build/xr_spans|xr_iter|xr_self|xr_self2` scratch trees. `PROGRAM_GUIDE.md` §5 cites
`tools/fix_stubs_*.py` but the scripts sit at the repo root. Gate: `git status --porcelain` shows
only real work, and every doc path citation resolves (`mcla-guest-raw-decode`-style `ls` check).
**Ask before deleting** — these are user files, and `*.log`/`crash_dump.txt` are evidence-adjacent.

**T39.4 — docs consistency pass.** `docs/HANDOFF_NEXT_AGENT.md` LIVE block still says
"BUILD BROKEN; work T37.0 first" (17:12) — false since `5eb9932`; rewrite it to the §0 state and add
the W37a rows (reorg + VEH removal + this tooling pass). Also: the GFx vtable blocker existed only
in agent memory until 17:45 — memory is not the trail, so any frontier that matters must be in
`docs/` the same session it is learned (rule 10). Gate: a fresh session reading only `docs/` reaches
the same #1 blocker as this file.

**T39.5 — knowledge/wiki pre-flight config (optional, low priority).** `.qoder/repowiki/wiki_plan.yaml`
does not exist; the `qoder-context:qoder-context-knowledge-plan` skill can create it so generated
knowledge cards pin the canonical facts (image mapping, dict table `0x82839F70`, forbidden paths,
marker inventory) instead of re-deriving them from 11.5k-line files. Only worth doing once the tree
is stable — it re-generates on demand and stale cards are worse than none.

**T39.6 — register the three audit scripts, and make two of them commit gates.** *(added 2026-09-20
19:30, this session; `tools/` is tracked again since `5eb9932` closed the ignore hole.)* Built and
validated 18:53–19:01; **uncommitted**:
- `tools/soak_census.py` (9,488 B) — the executable form of the `mcla-log-census` skill. Counts
  matching LINES case-insensitively per marker, i.e. exactly `grep -ic`, over a 115-marker battery
  (`FRONTIER` + `VEH_PATHS` + the §7 short-circuit set + everything §9 names). Also splits guest `lr=`
  census into all-lines vs fault-lines-only, the CP-ring first/last `put=`/`rptrWB=`,
  `[error]`/`[warning]` levels, and prints a delta against a **named** baseline. Usage
  `python tools/soak_census.py build/w38c.log build/w38b.log`. Exit 0 always (informational).
  **Validated against hand-measured ground truth:** reproduces `C0000005` 703 → 1,
  `boot-worker AV` 703 → 0, `GFx` 7 → 9, `DRAW_INDEXED` 0 → 0, `put=11 rptrWB=0000`, short-circuit
  lines 784 → 166, and baseline **703 fault events / 1 distinct fault `lr`** (`822FBC28`).
  `VEH_PATHS` (added 19:40, F-051) gives each named crash-path mitigation its own row so a soak's VEH
  output can be classified honest-vs-laundering without reading `boot_host.cpp`.
- `tools/addr_owners.py` (22,630 B) — rule-4 machine: guest address → `file:line` → hook name, and
  flags multiple *claiming* owners. 678 sites / 409 claiming / 251 hex addresses + 207 named imports
  + 15 unaddressed bodies. `--check <addr|symbol>` for one site's owners (reverse cross-references
  the symbol too), `--gates <addr>` (added 20:10, F-053) dumps each claiming site's enclosing-function
  branch/return lines **verbatim and uninterpreted** — the tie is then broken by grepping the soak for
  the installer's own log line, never by guessing. `--all`, `--notes`, `--tsv`.
  **Exit 1 = violations**, so it can gate a commit. It prints no causal claim about *which* owner
  wins (the two it used to print were unverified and are gone), so every violation it reports still
  needs a human pass — currently 1 (`0x827BD6E4`), and F-053 is that pass for it.
- `tools/mitigation_audit.py` (10,422 B) — diffs §7 against `src/` (F-047's source). `--tiers`,
  `--label X`, `--comments`, `--limit`. **Exit 1 = findings.** Currently: STALE none, 69
  mitigation-shaped labels unregistered.
Work left: (1) `git add tools/soak_census.py tools/addr_owners.py tools/mitigation_audit.py` — named
paths only, never `-A`; (2) add them to `AGENTS.md`'s skills table (a "Project tools" row) and to
`PROGRAM_GUIDE` §3 so a fresh session finds them instead of re-writing a fourth census loop;
(3) decide whether `addr_owners.py --check` runs before any hook-adding commit — if yes it belongs in
§1's rule 4 text, if no do not pretend it is enforced.

**T39.7 — F-048 follow-ups (rule-4 real findings).** See `ROOT_CAUSE_VALIDATION.md` F-048.
(1) **Three owners of guest VdSwap** (`0x827BD6E4`) — **CLOSED 2026-09-20 20:10, and the premise was
FALSE: see F-053.** There is one owner *body* (`Hooked_VdSwap`, `native_renderer.cpp:162-182`) under
all three `renderer_mode`/`mcla_patch_groups` configurations; `native_renderer.cpp:254` is gated by
the early returns at `:191`/`:197`, which are complementary to `patches.cpp:676`, so the two runtime
installers cannot co-fire, and `imports.cpp:3469` forwards to the same body. Nothing to fix; the
queue item is deleted, not deferred. (2) below is the only surviving half of this task.
(2) **Live dead hook**: `patches.cpp:827-853` `hk_XamInputGetState` (installed by `SetFunction` at
`:516`) *replaces* the import, so the compile-time `GUEST_FUNCTION_HOOK` at `imports.cpp:3537` never
runs; it synthesizes `ctx.r3 = 0` + the StartPulse store and never chains — the same class the tree
already fixed once at `imports.cpp:3464-3467`. Remove the compile-time hook or chain it; 6 of the 8
import overlaps already chain correctly (`imports.cpp:899/:855/:867/:884/:321`, KDELAY-SC `:794-825`).
Only fires with the `in` bisect group on — verify group state in a soak before changing behaviour, and
add no new short-circuit while fixing it.
**Method note from (1), applies to every future overlap in the 8:** read the *enclosing function* of
each claim (`--gates`), then confirm against the soak which installer logged. `addr_owners.py`
deliberately does not decide reachability — see F-053's tooling bullet for why an under-reporting
analyzer was rejected.

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

1. Edit `generated/`. 2. Regen without the reproducibility gate (`PLAN_VMX128.md` §4 Route B step 3; TU count must stay 176). 3. Poke shader dict / patch `byte_827D5C70` / stub fatals. 4. GETDEV-redirect (F-027). 5. Write `0xA00xxxxx` scratch from SeedPreBootSlots. 6. Treat `525DE064` as magic (stack residue). 7. Depend on `mc4/art`. 8. Remove hash-table hydration until INSERT proven clean. 9. Stack short-circuits without root cause. 10. Leave mcla.exe running. 11. Follow root `CODE_OPTIMIZATION_PLAN.md` Phase 0 (edits generated/) — VOID by rule 2. 12. "Fix" VMX traps by skipping instructions (R5 — stale vectors). 13. Treat PresentKick r4 as framebuffer (F-B: swap-table timestamp slot). 14. Build caller chains from census `lr` after memset/leaf calls (sticky-LR; use xrefs + arg regs). 15. Widen the `W34` loader scan (`src/gpu_device.cpp:5251-5254`) to accept `0x8206Dxxx` vtables, or write `0x820736DC`/`0x820736B0` into the fabricated loader after `sub_824C6F08` returns — both manufacture loaders out of sub-object memory (F-044). 16. Trust a `lis`/`addi` decode produced by hand or by a scanner that breaks on the *second* of two consecutive `lis`s — the first version of the vtable-producer scan under-reported (`0x824C6F28` missed); re-run with a sliding register state (F-044 §2). 17. Read a VEH crash dump's `lr` **or any GPR** as the faulting frame's until the dump's context is known to be the one that faulted — `g_faultCtx` is the boot worker's *root* `PPCContext`, while the forced gate runs stages on an unpublished local `g` (F-046: identical `lr`/`r3`/`r8`/`r9` 1.044 s apart). Also never try to add `ctr`/`xer`/`r11`/`r14`-`r31` to a dump: `ppc_config.h:5,9,10` make them host locals, so it cannot compile. 18. Read the `+0x…` in a `rip owner=guest 0xAAAAAAAA +0xBBBB` crash-dump line as a guest PC offset — it is `RtlLookupFunctionEntry`-relative **host code** bytes, so adding it to the guest address lands on a block that never executed (F-050: it pointed this session at `0x8230448C`, a second unrelated null-`bctrl`, while the real fault was the `bctrl` at `0x82304368`). Only the function half of that line is evidence. Fixed in text at `src/boot_host.cpp:547` (now `(host+0x…)`), unbuilt-in-soak. 19. Treat a crash-dump `rip owner=…` line as a *guest*-PC bound at all — `GuestFnAtHostAddr` answers from `RtlLookupFunctionEntry`, which returns the enclosing **unwind** entry, and the XenonRecomp output has one entry per recompiled function with no size bound that tracks the guest basic block. F-055 proved it: the printed owner named neither `sub_822F44DC` (the caller at the fault `lr`) nor `sub_822FA958` (the callee). Attribute a fault with `lr` + rule-3 raw words at `lr - 4`; use `rip owner` only as a weak hint about which host region the RIP sits in.

## 5. Done = playable loop

Legal/menu on screen → navigable → race/free-roam starts → controllable car, camera follows → audio present → 60 s soak no fatal.

## 6. W36 commit map (seeds T37.2)

`e46c386` queue trace 19 files +8.9k (task_dispatch_trace +913) · `f3bb765` gpu_device +52 census sub_8218A008 · `b6528ad` TLS allocator + VEH, dropped 461 MB generated/default blob · `e1a2435` boot gate (boot_host, gpu_device +100, imports) · `cc3a433` GFx vtable (gpu_device +41, CMake +1) · `8f07a39` game data + GFx factory; validators re-added (now moving to tools/validators).

## 7. Agent tooling map (added 2026-09-20 17:45; `AGENTS.md` is the auto-loaded summary)

| Layer | Where | Use for |
|---|---|---|
| Auto-loaded rules | `AGENTS.md` (repo root, tracked) | reading order, the 5 expensive rules, forbidden paths, conflict pointer |
| Workflow skills | `.qoder/skills/mcla-boot-cycle/` | build + kill + stale-exe check + soak into a new log |
| | `.qoder/skills/mcla-guest-raw-decode/` | raw word dumps, `lis` sign-extension trap, call-shape/`lr` attribution |
| | `.qoder/skills/mcla-log-census/` | case-insensitive marker counts vs a named baseline log |
| | `.qoder/skills/mcla-finding-ledger/` | writing F-### entries, doc-sync duties, mitigation labelling |
| | `.qoder/skills/mcla-recompiler-regen/` | Route A/B/C, reproducibility gate, TU-count/`ppc_recomp.10.cpp` invariants |
| Project MCP | `.qoder/settings.json` (tracked) | `ida-pro` (idalib on `build/game_data/default.xex`, RPC :8745 — it kills other idalib sessions), `renderdoc` (`python -m renderdoc_mcp` + `C:\Program Files\RenderDoc`) |
| Built-in MCP | connected already | `node-repl` (manifest TOML edits — never by hand), `browser-use`/`WebSearch` (Xenia/XenonRecomp semantics) |
| Not useful here | `sites`, `qmind`, `canvas`, `petdex`, `find-extensions` | skip; they cost turns and touch nothing in this project |

Skills are auto-discovered from `.qoder/skills/` (verified live 17:36). MCP needs one `/mcp reload`
plus the project-server trust prompt (T39.1).

## 8. Conflict register (audit 2026-09-20 17:45 — resolve via T39.x)

1. **Two MCP config dialects.** `opencode.json` (gitignored) vs `.qoder/settings.json` (tracked)
   declare the same `ida-pro` + `renderdoc` servers → drift risk. T39.2.
2. **`.mcp.json` is ignored by `.gitignore` and unread by Qoder** — a plausible-looking file that
   does nothing. Don't create it. Documented in `AGENTS.md`.
3. **Duplicate plan file**: root `CODE_OPTIMIZATION_PLAN.md` vs `docs/CODE_OPTIMIZATION_PLAN.md`;
   docs/ wins, root's Phase 0 is VOID (do-not #11). T39.3.
4. **Doc-vs-doc contradiction still live**: `HANDOFF_NEXT_AGENT.md` LIVE block says "BUILD BROKEN,
   work T37.0"; `LONG_TODO_MASTER.md` §0 says T37.0/T37.1 done and committed. T39.4 fixes the
   former. Until then trust §0 of this file (reading order puts it first for that reason).
5. **Memory held the #1 blocker, docs did not** — `GFX-CTOR-VT-MISMATCH` existed only in agent
   memory until this pass. Memory is not the trail; rule 10. T39.4.
6. **Two task queues**: `TaskCreate` (per-session scratch) vs this §2 (durable). Nothing may live
   only in the session list; the session list must not resurrect closed §2 items.
7. **Root junk, untracked and unignored** (§T39.3 list) → `git add -A` would commit 0-byte files, a
   3 MB `NUL.obj` and stale experiments. Always stage named paths.
8. **Shared build/boot resource across concurrent sessions** — `taskkill /F /IM mcla.exe` and the
   IDA bridge both kill another session's process. Rule 11's 2-minute log check is the guard; the
   IDA bridge needs the same courtesy (check for `idalib-mcp.exe` first).
9. **Address-transcription conflict** — three different globals were cited for the same fault site
   inside one hour (`0x82859F68` here, `0x82839F68` per F-043, `0x827C9F70` historically). The skill
   encodes the arithmetic check; any address quoted in a claim must come from generated-code text or
   a computed dump, never from a hand decode.

## 9. Deferred / parked (do not start without a state change)

- VMX128 Route B (94 type-5 `vupkd3d128` unpack sites, `0x822Fxxxx`) + the Clang-20 toolchain fix —
  parked per §0; the cluster is not reached and `0x80000003` count is 0. Re-open only if a soak logs
  a type-5 site or a `0x80000003`.
- `vupkd3d128` type-2 unpack (`0x821B43D8`), `vcmpbfp128` (`0x825CEA2C`) — `PLAN_VMX128.md` §2.3/§2.4.
- All of `docs/CODE_OPTIMIZATION_PLAN.md` (rule 9): gpu_device split into `src/hooks/` is in flight,
  PCH, log-flood throttling, unity build — re-measure the 19 s/1.6 GB/200 s/23.6 s baseline first.
- Waves D–G (input, audio, world, polish) = T37.7–T37.10; they are gated on T37.4/T37.5 pixels.

*2026-09-20 19:25. T38.1 CLOSED (F-044/F-045: the GFx vtable "mismatch" was a false gate) and
**T38.2 CLOSED** (F-046/F-049: the residual `0x7E780000` AV is a null indirect-call target inside the
host-forced BOOT-GATE, reached because `ReadGuestU32` returns 0 on invalid reads, and the crash dump
prints the *wrong* `PPCContext` — so no register in it is attributable). Next action: **T38.2b** —
publish the faulting context in the dump, one soak (`w38c.log`), then name the site → **F-050**.
Then **T38.3** (catalogue/delete the gate driver + the `GFX-BLOCK`; F-047 says 69 mitigations are
unregistered vs §7's 13) and **T39.4** (HANDOFF still says BUILD BROKEN). Rule-11 check before any
build; an `idalib-mcp.exe` was live at 19:08 — do not start the IDA bridge over it.*

*2026-09-20 19:32 (tooling session; adds to the 19:25 block, does not amend it). The three audit
scripts behind F-047 are built, validated against hand counts and **uncommitted** — see the new
**T39.6**. F-048 landed two real rule-4 findings (3 owners of VdSwap; 1 live dead hook) → new
**T39.7**; `0x822FBAF8` and `0x82839F68` are otherwise unclaimed in `src/`+`config/`, so T38.2b has
no owner collision to resolve. Note for whoever takes T38.2b: `mcla_pe.bin` is back
(`10,354,688 B`, 17:14) so rule-3 raw decode works, and the ledger footer is at **F-050+**.*
