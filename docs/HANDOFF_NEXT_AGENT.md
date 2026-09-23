# HANDOFF — next agent, read this first

> Compressed 2026-09-20. Queue: `LONG_TODO_MASTER.md` (T37.0 first). This =
> frontier + ledger + durable facts. Also: `PROGRAM_GUIDE.md`,
> `ROOT_CAUSE_VALIDATION.md`, `EXECUTION_PHASES.md`, `PLAN_VMX128.md`,
> `CODE_OPTIMIZATION_PLAN.md`. Full text in git
> (`git show 8f07a39:docs/HANDOFF_NEXT_AGENT.md`). Old paths = trail, re-grep.
> `docs/` is **tracked** since `5eb9932` (verified 19:25: `git check-ignore -v docs/*.md` → rc=1) —
> plain `git add docs/…` is correct now; only a *newly created* doc needs `git add -f`.

## LIVE — 2026-09-20 23:32: IDA attached, three fixes shipped (F-063 is the good one), and the frontier is now **one guest instruction deep inside the `star_glow` shader init** — T41.3b. Newest soak baseline: `build/w38s.log`. Read the 23:32 addendum first; it supersedes the 22:12/21:55 headings for anything about the last `C0000005`.

### Addendum — 23:32: the last AV was a downstream symptom. The blocker is `sub_822FBAF8`, and one over-broad guard was starving it

Session start: the user asked to connect IDA via `opencode.json`, follow `docs/`, produce a long
backlog, and keep going to playable. IDA came up by **attaching to the already-live
`idalib-mcp.exe` RPC on `127.0.0.1:8745`** (47 tools, `get_metadata` = `default.xex` @ `0x82000000`);
`ida-bridge.py` was deliberately NOT run, because its line 25 `taskkill`s that process and another
session owned it. The backlog is `LONG_TODO_MASTER.md` §2 **T41.1–T41.15** (four stages, every item
with a named baseline soak as its gate).

- **The chain, end to end (F-060 → F-061 → F-063).** The last `C0000005` writes to guest `0xE0`
  because `sub_822F3BD8`'s only caller, `sub_823045E0`, passes `this = [0x8287E26C]` = 0
  (`ppc_recomp.50.cpp:6059-6063`), and that word's **only writer in the image** is the factory
  `sub_822F38C0` (`ppc_recomp.48.cpp:27313`) — which is never reached, because the statement before it
  in `sub_823047D8` is a call to **`sub_822FBAF8`, the `star_glow` effect init, which never returns**.
  Both ends turn out to be `(handler, msgid)` table entries (`0x8210DA98` = msg `0x40001503`,
  `0x8210DED8` = `0x40000B03`, `0x82102AC0` = the boot gate's own msg `0x40003B03`) and `src/` has no
  walker for that table — F-060(4).
- **F-063 is the shipped fix and it works.** `PPC_FUNC(sub_821D3070)` skipped any request whose `r4`
  had bit 15 set — a bit its *caller* `8C760` sets as a flag — so the shader's own 32 KB buffer was
  silently dropped. Removing that one clause from the skip condition gives: `D3070-SKIP` 2 → **0**,
  `TSLAB-OWNER size=32768` for the shader buffer, `sub_822F9FA8` (`[0x8287E334]`'s producer — the
  global F-055 said had none) running **for the first time in the project's history**, the guest's own
  `sub_82188CF8` ctor on a simple-pool object (so the `FIX-821873E8` fabrication is no longer reached
  on this path), **host short-circuit lines 177 → 96**, `[error]` 61 → 51, bogus `AllocPhysical` nulls
  3 → 0.
- **Where it stops now, and why (F-064 — read this before T41.3b).** One statement later, the guest
  raises a **fatal**: `'drawblit technique is old and busted, rename to blit_draw.'`
  (`w38s.log:3981`, `lr=0x82188770 r3=0x8200B15C`), right after
  `MSGBISECT 14-8218B688 technique-lookup #6 r3=CA71D388 r4=8200934C` (`:3980`). Cause: the bytes it is
  parsing are fabricated — `AFB76-FALLBACK #4 … serve rage_im buf=827D2DD0 size=5258` (`:3860`) hands
  the guest the **embedded name-list buffer** as `star_glow.fxc`. So the next task is a *data* question,
  read-only: what does the guest's own `TOC76` lookup for `fxl_final/star_glow.fxc` return, and is the
  archive path reachable (F-034)? Never grep the archive to answer it — its TOC is encrypted.
  `DICT-HYDRATE` and do-not #3/#8 both still apply.
- **Two marker drops that are NOT regressions, said plainly.** `UILOAD 1 → 0` and `GFx 9 → 1`:
  the forced gate's only trigger was the `FIX-821873E8` TLSDEAD branch, which the fix made
  unreachable, so `sub_82131008` is now dispatched by nobody — and the 8 lost `GFx` lines are the
  host's own `GFX-*`/`W34-*` stand-in prints, not guest output (F-051's test; **T41.3c** owns the
  choice between dispatching the gate on its real message and deleting the stand-in). The gate also
  no longer runs re-entrantly inside the guest's allocator hook on that thread's stack — it has its own
  host thread + its own `g_userHeap` guest stack (`GATE-STACK`; from the phys o1heap it caused 3 bogus
  `AllocPhysical` nulls).
- **New parked fault, unattributed:** `code=0xC0000005 Param[1]=0x100000040` (guest EA `0x40`),
  `ppc ctx=nil tag=none`, `rip owner=host … not a mapped guest fn`, parked
  (`w38s.log:5804`/`:5825`) ⇒ **T40.5** (symbolise the host fault address) is now on the critical path.
- **Concurrent session, live:** another session wrote **F-062** + **T42.1/T42.2** (the fabricated
  shared TLS block at `0x8F200000`, `r13` hard-set at 25 sites, two refuted causes of `slot12=0`) at
  23:23-23:25 while this one was soaking. F-063's last bullet is the measurement T42.1 §7 asked for,
  for this path. Check mtimes and `tasklist` before building.
- **State on disk:** tree green (`build/w38s_build`… exe 23:17 → w38s), `mcla.exe` killed, IDA left
  running for the other session. **Nothing committed.** Dirty now: the previous session's 14 files,
  plus this session's `src/gpu_device.cpp`, `tools/soak_census.py`, 4 `docs/*.md`, `AGENTS.md`, and
  new logs `w38n`…`w38s`. Never `git add -A` here.


### Addendum — 22:12: T40.6 steps 1-2 shipped; **the guest really does submit draws** (F-059)

Soak `build/w38m.log` (exe 22:05, `BOOT_RC=124`) vs baseline `build/w38j.log` (and `build/w38k.log` for
the census-only step):

- **The CP's own logger was hiding the draws.** `LogUnknownOpcode` reported each opcode `< 0x20` once
  and collapsed **every** opcode `>= 0x20` into a single line — precisely the draw range
  (`PM4_DRAW_INDX = 0x22`, `PM4_DRAW_INDX_2 = 0x36`). Replaced by `LogType3Unhandled`
  (`src/gpu_cp.cpp:351-367`): first 3 hits per opcode with argument dwords. It named 13 previously
  invisible opcodes in `w38k.log` (`0x21 REG_RMW`, `0x2B IM_LOAD_IMMEDIATE`, `0x3B INVALIDATE_STATE`,
  `0x3C WAIT_REG_MEM`, `0x45 COND_WRITE`, `0x46 EVENT_WRITE`, `0x54 INTERRUPT`, `0x58 EVENT_WRITE_SHD`,
  `0x60-0x63 SET_BIN_MASK/SELECT` — names from `xenos.h`).
- **`DRAW_INDX`/`DRAW_INDX_2` now decode** (`src/gpu_cp.cpp:496-531`, `VGT_DRAW_INITIATOR` fields per
  `.research/xenia/src/xenia/gpu/registers.h:311-326`), and the result is concrete: **24 real
  `PM4_DRAW_INDX_2` submissions** — `CP-DRAW #1…#24`, every one `op=0x36 src=2 (kAutoIndex)
  prim=1 (kPointList) numIdx=1 initiator=00010081 hdr=C0003600`, `C71DC180→C71DC238` at an 8-byte
  stride, which is 24 packets × 2 dwords = the nested IB's entire declared 48 dwords. The "misaligned
  walk over data" alternative was tested, not waved away: every header is a well-formed Type-3 header,
  and the absence of a `#64` line bounds the total to `[24, 63]`.
- **`DRAW_INDEXED` is still 0 — decode is not render.** The CP models no Xenos register file, so there
  is no VB/IB/shader state behind a submission. The host-side path that *does* enqueue `DRAW_INDEXED`
  (`src/gpu_device.cpp:1793-1803`) is starved separately and for a documented reason: the
  `sub_82420BA8` hook only sees dummy `li r5=0` submits because the guest's D3D9 chain
  (`sub_8217A470 → sub_8241BE78 → sub_8241C308 → sub_82420BA8`) never runs (`:1829-1835`).
- **No regression:** `C0000005` 1→1, `GFx` 9→9, `UILOAD` 1→1, `PRESENT` 68→68, `Fatal error` 1→1,
  `VEH W0: parking thread` 0→0, short-circuits 178→177. **Next soak's baseline is `build/w38m.log`.**
- **Next:** T40.6 step 3 = register state (`0x21 REG_RMW`, `0x2B IM_LOAD_IMMEDIATE`, the Type-0 writes)
  into VB/IB/shader, and answer what those 24 point draws are — from the register writes, not from more
  draw logging.

### Addendum — 21:55: two of the three fixes are in and soaked; the third task was a false premise (F-058)

Soak `build/w38j.log` (11,120 lines, `BOOT_RC=124`, exe 21:45, `w38i_build2.log` `BUILD_RC=0`) vs
baseline `build/w38g.log`:

- **T40.3 SHIPPED.** `PhysToKernelVA` on the PM4 `INDIRECT_BUFFER` list pointer at both sites
  (`src/gpu_cp.cpp:454`, `:666`). The eight IB packets went from `CP[IB]: TYPE0 base=000` (walking
  zeros) to real Xenos register offsets `A31/A2F/D02/A02/1DD/1DC/5C8/D04` (`w38j.log:858-872`), and
  **three nested IBs are now reached** where `w38g` had none (`:873-875`).
- **T40.4 SHIPPED.** New `CpPrimaryWritebackVA()` (`src/gpu_cp.cpp:986`) replaces the two hard-coded
  addresses in the waiter census (`src/kernel/imports.cpp:2112`+), and `tools/soak_census.py` now prints
  `CP truth drains=8 last_rptr=001F pub=11 put=11 (caught up)` and flags any tracked marker whose
  literal is in neither `src/` nor `generated/` (4 today). Its `rptrWB → "no CP consumer"` verdict is
  deleted, and the `mcla-log-census` skill carries the same correction.
- **`DRAW_INDEXED` is still 0 — the diagnosis was one layer short.** Addressing was wrong, but the
  missing capability is packet *handlers*: this CP implements only Type-3 `0x3F/0x3D/0x48/0x64`, while
  the draws are `0x22 PM4_DRAW_INDX` / `0x36 PM4_DRAW_INDX_2` (`xenos.h:1600-1601`). New #1 is
  **T40.6**, which is T37.6 Wave C — census the real Type-3 stream first, then state, then the handler.
  Do not invent draw data.
- **T40.1 is VOID and must not be implemented.** The "wrong package window" blocker was a sweep artifact:
  the path hard-code and the TOC decode give the *same* offset for the one file where the log exposes
  both (`meshtextures.xtd`, `r5=40060000` → `0x60000`), both call sites already fall back to the TOC, and
  the hard-code is documented as deliberate because TOC-derived `.xsf`/`.xtd` bodies are AES ciphertext
  (`src/gpu_device.cpp:521-523`). F-057(5)'s last sentence is retracted. Lesson for the next session:
  a fleet finding is a hypothesis — check it against the log before queueing work from it.
- Unchanged, as expected: `C0000005` 1 → 1 (same instruction), `GFx` 9 → 9, `PRESENT` 68 → 68,
  `PRESENT-FB` 4 → 4, `Fatal error` 1 → 1, short-circuits 185 → 178. The census's `VEH` 1 → 2 is the
  substring in `ser**ve H**ead` on one new `READWRAP-SERVE` line, not a second AV.

> This block supersedes the 20:40 block (now "Trail"). That block's `[0x8288E334]`, its leaf
> attribution, and its `DRAW_INDEXED 0, CP put=11 rptrWB=0000` line are all **void** — F-056 corrects
> the first two, F-057 the third. Its deletion list, UILOAD-first-time claim and do-not #19 note stand.

**Take `docs/LONG_TODO_MASTER.md` §2 T40.6** (was T40.1 — void, see the addendum). What `build/w38g.log` (exe 20:39, 11,298 lines,
`BOOT_RC=124`, baseline `build/w38f.log`) plus a 22-agent read-only sweep of every `src/`, `docs/` and
`tools/` file established:

- **T38.3f ran and settled the question.** The six seed writes are deleted (`src/gpu_device.cpp:1101+`
  is now a read-only `GATE-FLAG-READ` census) and `sub_82131008` is entered once, unseeded, on a 4 KB
  reserve with `g.lr = ctx.lr` (`w38g.log:3810-3823`). `C0000005` stayed **1** at the *same*
  instruction → the flags were never the cause, and F-055's "the seed lies, so the allocator table is
  never built" hypothesis is not what the surviving fault tests. The forced gate driver is still a
  stand-in; T38.3(d)/(e) remain open.
- **The fault is now named to a generated-code line** (F-056):
  `generated/ppc_xenon/ppc_recomp.49.cpp:2660-2661` `// stvx128 v33,r31,r7` →
  `simde_mm_store_si128((__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), …)` — a **raw, unchecked**
  store (no `IsValidRange`, unlike `PPC_STORE_U32`), with translator-local `r31 = 0` (proved by
  `:2614-2615 addi r10,r31,16` against the dump's `r10=00000010`) and `ctx.r7 = 224` (`:2583-2585`).
  It is inside `__imp__sub_822F3BD8` (opens at `:500`), **not** the leaf `sub_822FA958`; `lr=822F44E0`
  is sticky from `:1965-1966`. And the address F-055 chased is `0x8287E334`, not `0x8288E334` —
  raw `822FA96C 816BE334 lwz r11,-7372(r11)` with `822FA958 3D608288 lis r11,8288`: the D-field
  sign-extends. Do-not #19 now carries a dated correction: `rip owner=` was *right* at function level
  here; it is the PC bound that it cannot give.
- **The pipeline is not starved — we were misreading our own census** (F-057). `WAIT[KWFSO] …
  rptrWB=0000` polls hard-coded `0xC71D81BC` (`src/kernel/imports.cpp:2117`) while the CP publishes to
  `C71D82BC` (`src/gpu_cp.cpp:951`, `w38g.log:794-795`) — 4 bytes to the left, so it can only print 0.
  The ring **drained 8×** to `rptr=001F` with `pub==put==11` (`w38g.log:865`-`:3186`, `GUEST-PUB #5`),
  so "no consumer" is dead. The real `DRAW_INDEXED=0` cause is one line away: `src/gpu_cp.cpp:664-666`
  hands `DrainIndirectBuffer` a raw phys `listPtr` (`0x06258300`) instead of `PhysToKernelVA(...)`
  (`0xC6258300`) → zero packets. That is **T40.3**.
- **Nobody is parked.** `parking thread` = **0** in `w38g.log`; the 2,852 `obj@40004D7C` waits are
  `tid=00000C90 lr=8242FC1C`'s satisfied 16 ms heartbeat (2,851 × `WAKE status=00000000`). The boot
  worker (`tid=19552`, `tag=forced-boot-gate`) stops at `w38g.log:4335`/`:4359` because the handler
  **declined** and the thread was abandoned mid-gate — which is honest, and is why the gate never
  returns.
- **The dark blue is real on screen and 100 % host.** Pixel capture of the live window
  (`build/screen_shot.png`, 33 s into `w38h_screen2.log`): `AVG_RGB=16,26,56`, 79/81 samples `0F1938`,
  title `MCLA Native`, empty client area. That is `0.06,0.10,0.22` — `src/render_thread.cpp:85`,
  `:444`, `:505-507` — presented every ~33 ms because each heartbeat `PRESENT #n … fb=00000000`
  short-circuits the blit (`:535-539`). The four guest `PRESENT-FB sample rgb=(0.06,0.10,0.22)` lines
  in `w38g.log` are *not* guest pixels: `:503-507` substitutes that triple for any framebuffer whose
  sample sums below 0.02, i.e. they report **black** guest frames. Two live defects: Present's HRESULT
  is never checked, and `:572-574` clears *after* `DrawDynamicMesh` inside the same `BeginFrame`.
- **Assets are being read from the wrong window** (F-057(5) → **T40.1**): 6 named UI packages (`resources/ui/`: 5 × `.xsf` + `meshtextures.xtd`, 57 `XSF-OPEN ret=0`) open and
  are served, `xarchive_cache.rpf` is intact, and the real-archive reader already exists
  (`src/fs/vfs_rpf.cpp:443-459`) — but `MclaPreferredPkgOffForPath` (`src/gpu_device.cpp:285-296`)
  picks the offset by path string (`0xA0000` for `.xsf`/`.xtd`/`resources/ui`) instead of using the
  TOC word that `MclaPkgOffFromTocW2` (`:272-282`) already decodes.
- **Tool rot to fix before the next soak** (T40.4): `tools/soak_census.py`'s `VEH_PATHS` has 9 markers,
  **8 of which exist nowhere in `src/`** (verified literal-by-literal), while the one that does fire —
  `VEH W0: parking thread`, `src/boot_host.cpp:1064` — is missing from the list;
  `tools/mitigation_audit.py` self-reports 626 label-shaped tokens → 81 mitigation / 64 census /
  **481 unclassified**; `tools/ppc_disasm.py` decodes no FP/VMX (`?op48:`, `float/ps`) — its claimed
  `ori`/`rlwinm` operand swap is **UNVERIFIED and unsupported** (F-057(6)); the `mcla-log-census` skill
  still teaches `rptrWB=0000` = "no consumer", which F-057(1) forbids (corrected in place at 21:30).
- Verified state at 21:30: tree green (`build/w38g_build.log` `BUILD_RC=0`, exe 20:39), `mcla.exe`
  killed after both the soak and the capture run, `idalib-mcp.exe` live (do **not** start the IDA
  bridge). Uncommitted: `src/boot_host.{h,cpp}`, `src/gpu_device.cpp`,
  `docs/{ROOT_CAUSE_VALIDATION,LONG_TODO_MASTER,HANDOFF_NEXT_AGENT,PROGRAM_GUIDE}.md`. New evidence:
  `build/w38g.log`, `build/w38h_screen2.log`, `build/screen_shot.png`, `build/cap.ps1` (the capture
  script — reusable, takes the HWND from `Get-Process mcla`).

## Trail — 2026-09-20 20:40: T38.3(a)(b)(c)+stages DONE (F-055) — UILOAD reached for the first time; frontier was **T38.3f** stop seeding the gate's flags

> This block supersedes the 19:55 heading below. That block's "delete the gate driver and this AV
> disappears" prediction is **half right**: the crash-path mitigations and the three self-contradictory
> stages are gone, `C0000005` stayed **1**, and the UI layer was entered anyway — so the AV was never
> the gate's own blocker. Its do-not #18 bullet and the `0x82839D70` census are still valid.

**Take `docs/LONG_TODO_MASTER.md` §2 T38.3f** (new #1). What `build/w38f.log` (20:10 build, 10,001
lines, `BOOT_RC=124`, baseline `build/w38c.log`) established:

- **Deleted, with guest justification (F-055 §1):** forced driver stages 1/2/6 — `sub_823043F8`,
  `sub_82304348`, `sub_821FC008` — because the driver *itself* seeds `[0x8288E6F0]=1` and
  `[0x82830B14]=0`, and raw `0x82131020 lwz r11,4(r29)` + `beq → 0x8213103C` / `0x821310C0` show those
  flags make the guest branch over exactly those calls. Also deleted from `src/boot_host.cpp`: the
  `0xC000008E` float-div-0 park + `0xC3` host-entry patch over `sub_823D91F8`, the `0xC000001D` UI-load
  `Rip += 256MB`, and the `isKnownCrashSite` (`0x822F44E0`/`0x82133440`) `s_skipSub822FA958` + `0xC3` +
  `Rip += 256MB` + park chain (`src/boot_host.cpp:1021` has the dated comment). The handler now
  **declines** (`EXCEPTION_CONTINUE_SEARCH`) → generic park.
- **First-ever UILOAD entry, deterministic across two builds** (`w38f.log:3885-3890`; same four lines
  at `w38e.log:3876-3881`): `event1-ret r3=00000000` → `event2-ret r3=00000000` →
  `UILOAD-enter r3=[82830998]` → `UILOAD-param r3=C9A24500`, and **no `UILOAD-ret`**. The event-out
  slots `[r1+80]`/`[r1+84]` are seeded to −1 because guest `0x8213103C li r11,-1` +
  `stw r11,80(r1)`/`84(r1)` do exactly that before the two `bl 0x821C0750`.
- **The one surviving fault is now precise** (`w38f.log:4416-4421`): a **write to guest `0xE0`**
  (`Param[1]=0x1000000E0`, `tag=forced-boot-gate`, `r1=8EFFF510 lr=822F44E0 r7=000000E0 r9=827E0000
  r10=00000010`). `lr-4 = 0x822F44DC` is `bl 0x822FA958` — the 22-instruction leaf the deleted `0xC3`
  mitigation used to patch out. It chases `[0x8288E334]`, which is image bss (0), and **two negative
  scans found no `stw` with immediate `0xE334` anywhere in `0x82130000`–`0x82800000`** — no host-side
  producer exists to copy. ⇒ The next move is to delete the remaining seeds (`[0x8288E6F0]=1`,
  `[0x82830B14]=0`, `[0x82830ACC]=0`) and let `sub_82131008` build its own state, **not** to write
  `[0x8288E334]` by hand (do-not #9).
- **Two new limits on our instrumentation** (do-not #19): `rip owner=…` is a `RtlLookupFunctionEntry`
  *unwind* bound — in `w38f` it named neither `sub_822F44DC` nor `sub_822FA958`, so it cannot bound a
  guest PC at all (F-050's #18 is now generalised). And `build/w38e.log` (1.86 M lines) is **poisoned
  as a baseline** — F-054: one recovery loop = 616,824 of its lines; compare against `w38c`/`w38f`.
- **Still present deliberately:** `GFX-BLOCK` (`src/gpu_device.cpp:1137-1171`, incl. the
  `GFX-FACTORY-SKIP` line) and the `sub_821873E8` TLS-dead branch — left in so this soak's UILOAD delta
  stays attributable to the stage deletions. `DRAW_INDEXED`/`DRAWDISP` **0**, CP `put=11 rptrWB=0000`.
- Verified state: tree green (`build/w38f_build.log` `BUILD_RC=0`, exe 20:10), `mcla.exe` killed,
  `idalib-mcp.exe` live (do **not** start the IDA bridge). Uncommitted: `src/boot_host.{h,cpp}`,
  `src/gpu_device.cpp`, `docs/{ROOT_CAUSE_VALIDATION,LONG_TODO_MASTER,HANDOFF_NEXT_AGENT,PROGRAM_GUIDE}.md`.

## Trail — 2026-09-20 19:55: T38.2b CLOSED (F-050 + F-052); frontier was **T38.3(e)** delete the forced gate

> This block supersedes the 19:25 heading below ("frontier = T38.2b") — items 1-2 of that block are
> still correct as *history*; item 1's "→ T38.2b" is now done.

**Take `docs/LONG_TODO_MASTER.md` §2 T38.3(e).** What `w38c.log` (19:39, 9,726 lines, exe mtime 19:37)
plus this session's raw decode established:

- The instrument works: `w38c.log:4089` prints `ppc ctx=0x8a7b2fefc0 tag=forced-boot-gate`, `r1` moved
  vs `w38b`, `C0000005` stayed **1**, and nothing advanced (expected — T38.2b was diagnostic only).
- **The last residual crash is a call the *host* invented**: `src/gpu_device.cpp:1203-1206` enters
  guest `sub_82304348` with `r3 = 0` on a value-initialised `PPCContext` (`freshVolatiles()` at
  `:1193-1196` clears only `r5`-`r10`). Three pointer-chasing loads (`lwz r3,4(r3)` → `lwz r11,0(r3)`
  → `lwz r10,16(r11)`) are each silently answered with 0 by `ReadGuestU32`, `ctr` becomes 0 and the AV
  is the `bctrl` at guest `0x82304368` — `lr=8230436C` is that call's *own* return address
  (`ppc_recomp.50.cpp:5642`), so for once `lr` is honest. `:1236-1239` already skips `sub_82304398`
  for exactly this reason; `sub_823043F8` (`:1198-1201`) has the same null-`this` shape.
- ⇒ Deleting the gate driver + `GFX-BLOCK` (T38.3(e), and F-051 shows the crash-path mitigations fire
  **0** times in both honest soaks) is expected to make this AV disappear. Prove it with a full marker
  census vs `w38c.log`, not by the absence of the AV alone — and if `GFx`/`UILOAD` counts *drop*, that
  tells you the gate was carrying them, which is its own finding.
- **New do-not #18:** in `rip owner=guest 0xAAAAAAAA +0xBBBB`, the offset is **host** code bytes
  (`RtlLookupFunctionEntry`-relative), not a guest PC. Adding it lands on a block that never ran; that
  false reading is what briefly sent this session hunting a non-existent `0x82839D70` null. Message now
  says `(host+0x…)` at `src/boot_host.cpp:547` (built green `build/w38d_build.log`, `BUILD_RC=0`, exe
  19:52, **not soaked**). Bonus fact worth keeping: `0x82839D70` *is* a real rage static-instance
  singleton (4 writers: `0x82180390`/`0x821809FC` dtor-clear, `0x82186150`/`0x82186240` publish;
  vtables `0x82009D34`/`0x8200AAF4`; 0 owners in `src/`) — unrelated to the AV, don't arm it.
- Uncommitted here: `src/boot_host.{h,cpp}`, `src/gpu_device.cpp` (the `FaultContextScope` publishes),
  `docs/{ROOT_CAUSE_VALIDATION,LONG_TODO_MASTER,HANDOFF_NEXT_AGENT,PROGRAM_GUIDE}.md`.

## Trail — 2026-09-20 19:25: TREE BUILDS GREEN; frontier was T38.2b (dump the *faulting* context)

**Work `docs/LONG_TODO_MASTER.md` §2 T38.2b next** — all rules, verified state and the full trail
live there. This block supersedes items 1-3 of the 17:12 mirror below, which said "tree does not
compile": that was fixed by T37.0 in `5eb9932`, and this session built clean twice
(`build/w38b_build.log` 18:21, `build/w38b_build2.log` 18:39).

1. **The one residual `C0000005` is root-caused and is OUR artifact (F-046).** `Param[1]=0x7E780000`
   is `PPC_LOOKUP_FUNC`'s slot for guest target **0** (identity-probe matched it uniquely,
   `w38b.log:4023`); nulls reach a call because `ReadGuestU32` returns 0 on invalid reads instead of
   faulting (`src/guest_memory.h:82-86`, and `PPC_LOAD_U32` *is* that helper); and the fault is inside
   the **host-forced BOOT-GATE**, which runs guest stages on an unpublished local `PPCContext g{}`
   (`src/gpu_device.cpp:1121-1127`) while `g_faultCtx = &ctx` points at the boot worker's **root**
   context (`src/boot_host.cpp:706`) — so the dump's `lr` **and every GPR** describe a different frame
   (`w38b.log:3864` vs `:4021`: identical `lr`/`r3`/`r8`/`r9`, 1.044 s apart). → **T38.2b**. Loop worth
   noting: the p3b session's "TLS slot-12 host-complete (kills 0x7E780000)" mitigation *is* the path
   that now produces the surviving AV.
2. **Frontier after that = the guest never builds its own GFx loader** (F-044: the guest movie-ctor
   wrapper `sub_82482F78` appears **0** times in any soak, and `GFX-CTOR-VT-MISMATCH` is a false gate —
   do-not #15). Downstream stays starved: `DRAW_INDEXED` 0, `DRAWDISP` 0, CP `put=11 rptrWB=0000`.
3. **`ctr`/`xer`/`r11`/`r14`-`r31` can never appear in a dump** — `src/ppc_config.h:5,9,10` make them
   host locals (proved by 14 build errors this session). Use the lookup-address probe instead.

*Trail (17:12 block, superseded by the three items above — kept so the diagnosis is not re-derived):*

1. **Tree does not compile; another session is LIVE on it** — `build/cp_nudge*.log` series (13
   attempts by 16:23, ~2 min cadence): 4× `CpAdvanceGuestPublication` ambiguous
   `src/gpu_cp.cpp:1044/1109/1344/1451` (T37.0 has the verified diagnosis + the ONE correct
   fix: move the `:328` definition out of the anon ns opened `:22` — do NOT just qualify call
   sites, that link-errors) plus drifting move-injuries in `src/hooks/alloc_census.cpp`
   (gpu_device→hooks relocation in flight). Newest `build/*.log` < 2 min old = stand down
   (LONG_TODO rule 11; docs-only work is safe).
2. **Frontier = W36h** (`8f07a39`): TLS allocator, VEH recovery, boot gate, GFx loader vtable
   + factory call, game data. "UILOAD executes" is commit-claimed only (0 markers in the last
   soak) — UNVERIFIED. W36 is documented nowhere else → T37.2 must record it.
3. **Last good boot** = `build/mcla.exe` @ 14:48 (mtime never moved — no green build since) +
   `build/smoke_long.log` (15:18, 2 min): real packfiles (`xarchive_cache.rpf` 2032 MB),
   TOC76 #69, SUBMIT ×16, GLOBTEX-SERVE alive, threads park, no fatal (only "fatal" text =
   REBASE-POISON census wording). Present is synthetic: guest present-kick ×2
   (`native_renderer.cpp:152` census), both `PRESENT-FB` samples = fallback clear
   rgb(0.06,0.10,0.22) on swap-table slots — F-B reproduced, no real pixels.
4. Everything below = **trail** (pre-W36 paths/line numbers — re-grep before trusting).

## Session ledger — 2026-09-11 → 2026-09-20 (newest first; full text in git)

| Session | Date | What it established / landed | Commit(s) · evidence |
|---|---|---|---|
| **w38a→w38m** | 09-20 | **Eight blockers voided, four code fixes shipped, and the first real draw submissions ever decoded.** Shipped: T38.3(a)(b)(c) deleted the three crash-path recoveries so the handler declines honestly; T38.3f deleted the six forced-gate flag seeds and let guest `sub_82131008` run its own init; **T40.3** `PhysToKernelVA` on the PM4 `INDIRECT_BUFFER` pointer (IB packets went from `TYPE0 base=000` zeros to real register offsets + 3 nested IBs); **T40.4** `CpPrimaryWritebackVA()` + `tools/soak_census.py` `dead_tracked()` and a `CP truth` line (its false `rptrWB → no consumer` verdict deleted); **T40.6 steps 1-2** per-opcode Type-3 census + `DRAW_INDX`/`DRAW_INDX_2` decode → **24 real `PM4_DRAW_INDX_2` packets** (`CP-DRAW #1…#24`, kAutoIndex/kPointList, filling a 48-dword nested IB exactly). VOIDED the same day: the VEH RIP-advance runaway (F-040), the GFx vtable mismatch (F-044), the guest-frame dump reading (F-046), three-owners-of-VdSwap (F-053), `w38e` as a baseline (F-054), F-055's `[0x8288E334]` + leaf attribution (F-056 — the fault is `stvx128 v33,r31,r7` with a null translator-local at `ppc_recomp.49.cpp:2660`, and the real address is `0x8287E334`), five pipeline readings incl. the dark blue being guest pixels (F-057), the “wrong package window” blocker (F-058 — **T40.1 voided, never implement it**), and the logger that hid the draws (F-059). Also proven: the boot worker declines and goes silent rather than parking, and the on-screen dark blue is `src/render_thread.cpp:85,444,505-507` (`build/screen_shot.png`, `AVG_RGB=16,26,56`). **Nothing committed** — 14 modified files in the working tree (`src/gpu_cp.{cpp,h}`, `src/kernel/imports.cpp`, `src/boot_host.{h,cpp}`, `src/gpu_device.cpp`, 4 `docs/*.md`, `AGENTS.md`, `tools/soak_census.py`, 2 `.qoder/skills/*/SKILL.md`). Separately, `GITHUB_APPEAL_REPLY.txt` + `GITHUB_APPEAL_TEMPLATE.txt` show as **deleted** in the working tree (tracked since `e1a2435`, 1156/1093 B) — **not this session's doing**; re-census before any `git add`, and never `git add -A` here. Next: T40.6 step 3 (Xenos register file so the 24 decoded submissions can render); baseline `build/w38m.log`. |
| **W36a–h** | 09-20 | TLS allocator + VEH boot-worker recovery + boot gate + GFx loader vtable + factory call + game data; validators re-added (now moving to `tools/validators/`). Commit map in `LONG_TODO_MASTER.md` §6; no other doc records it (T37.2). | `e46c386` queue trace (19 files, `task_dispatch_trace` +913) · `f3bb765` gpu_device +52, census `sub_8218A008` · `b6528ad` TLS allocator + VEH, dropped the 461 MB `generated/default` blob · `e1a2435` boot gate · `cc3a433` GFx vtable (gpu_device +41) · `8f07a39` game data + GFx factory |
| **p3b** | 09-17 | star_glow fatal GONE: preload inflate host-serve + RSC5 header skip (guest refill Read returns 0 → host-serve 32 KB from `xarchive_cache.rpf` @ 0x60000; head is RSC5 `05435352`, XCompress at +12, `INFLATE-RSC5` strips 12 B); `sub_821873E8` TLS slot-12 host-complete (kills 0x7E780000); guest-memory view self-test PASSED (guard-page addrs ≥ 0x1000). Frontier: job #2 (swfC, tag 0x8004, dest B7B41000) — blind RPF host-serve serves wrong bytes (`INFLATE-SKIP` magic 6655A8B1); present still INERT (draw_indx=0, picker=0); residual AVs on the swfC dtor path. | soaks `build/boot_stdout_p3*.log` |
| **p2t** | 09-17 | `821873E8` fixed + self-test PASS; star_glow frontier reached. | `EXECUTION_PHASES.md` → PHASE 2 log |
| **p2p** | 09-15 11:20 | **F-039** identity-semaphore fix (`NtCreateSemaphore` handle was never registered → Release woke a phantom wrapper = T5 root cause). Preload RUNS; GPU frames start. | ledger F-039 |
| **p2f–p2o** | 09-15 | Preload crash chain FIXED (three-guard neutralization of poison container walks, **F-038**; `GetKernelObject` raw-cast AV, **F-037**), boot stable 240 s+. | F-036/F-037/F-038 |
| **p2f** | 09-15 07:00 | rgxa magic check decoded (**F-036**: preload `.xsf`/`.xtd` stream containers never filled — CDCD); rgxa FIXED → new frontier 825FDC64. | `EXECUTION_PHASES.md` p2d/p2f |
| **p2c** | 09-15 | Second fix: BE8D8-HOST path + slot-0 guard. | p2c log |
| **p2b** | 09-15 | First Phase-2 fix: `MakeMemoryStream` inserts into the guest slot table. | p2b log |
| **p2a** | 09-15 | Static-analysis pass: T2/T3/T5 decoded **before** any boot (no code change). | p2a log |
| **t24d analysis** | 09-14 | No code changed, three corrections: (1) boot is not parked, it is a **0xCDCDCDCD fill marathon** (`CDCD-FILL #135,640,000 @ AC8EE8C4`, lr `821BE3BC` inside `sub_821BE250`, frontier walked A0024020→AC8Exxxx ~210 MB at ~1.5 MB/s); our own CDCD watcher may dominate cost. (2) TLS is **not proven wiped** — `tls0`=8F201000 (armed) in every park sample of t23b…t24c, `ATARRAY-TLSDEAD` fired 0×; real disease = new threads get a zeroed TLS table by design (`src/kernel/guest_thread.cpp:20-35`) and only the slot-28 alloc chain is ever armed — **TLS slot +12** (atArray 16 B family) and **FuncBlock+16** (realloc) are armed by nobody. (3) Streaming is half-alive: NFS reads happen at thread-spawn (`evt=0/apc=0` = the 75w dormant-pending-slot issue) but INFLATE/READWRAP/XMEM = 0; the executor's 3-slot 32 KB page cache serves 0 on a miss and contains no fetch call (batch-1 fetches went through `sub_8244F4C0`, later batches never arm it). | handoff "ANALYSIS PASS" + `build/*t24*` logs |
| **t23a→t24c** | 09-14 | Boot PARKED, 13 guest threads, 0 AVs. `0x7E780000` decoded = `PPC_LOOKUP_FUNC(guest 0)`, i.e. `bctrl` through a NULL guest fn ptr — the whole "AV storm" family was null-indirect calls. atArray ctor guards `sub_8218AF68` (16 B), `sub_82189F00` (32 B, tails 0xFFFF), `sub_8218BFF0` (16 B #2) → poisoned count/cap becomes an empty array. XTL import strong overrides `sub_82130528` (alloc) / `550` (alloc-max) / `588` (free) call `__xtl_alloc/free` directly — **ABI: set r4=size, r5=16, r6=0 before `__xtl_alloc`** (leaking stale r4 produced a host-pointer/nul AllocPhysical storm in t24a). `sub_821D30E8` (buffer Grow via TLS FuncBlock+16 realloc) hooked host-side, realloc semantics kept. BE250 dead-stream reads host-served (`MemoryStreamServeRead`) instead of −1 (the −1 poisoned count/cap). | commit `f9278c5` |
| **t4–t15 rounds** | 09-13/14 | Successive boot-init fix rounds (seed/rebase, TLS slot arming, host-complete of guest stubs — e.g. BE0C8, T8b AV chase, t11b→t15b soaks): every round = boot ×2 into a new log, then a new documented frontier. Jump targets/host-completed addresses live in the pre-compression text (git) and in the cheat sheets below. | `build/boot_stdout_t*.log` |
| **T4-final** | 09-13 | star_glow fatal gone; memory-device vtable **0x82012918** installed on the static device; PE section table parsed (`mcla_pe.bin` = decompressed linear image, identity `file_off = VA − 0x82000000`; PE raw pointers are NOT offsets into it). GETDEV prefix returns static Device* `0x827D838C`; fallback slot `0x827D8380` (later identified as the `fiDeviceMemory` type_info/VFT object, **not** a holder — `PROGRAM_GUIDE.md` §8); host dead-ctor replay `ReplayDeadMemoryDeviceCtor()` + strong overrides of CRT `sub_827B8B38`/`sub_827B8B20` (CRT was clobbering the vtable with base `0x8201206C`). Never write guest-heap scratch (`0xA00xxxxx`) from these hooks. Boots: `t4final2`/`t4final4` = GETDEV 24/5, star_glow 0, fatal 0, VSYNC 120. | soaks `boot_stdout_t4final*.log` |
| **weaker-model plan** | 09-13 | AFB8 hook landed: `sub_821CAFB8` resolves `embedded:/` via the D22E8/D2308 name list (head `0x82860AF8`) using CRT embed-seed (`SeedEmbeddedNameList`: `node 0x828495B8, name 0x820093D4, buf 0x827D2DD0, size 0x148A`); new signal `AFB76-HIT` (2 boots). **EMB76 stays 0 forever** — INSERT uses vtable+4 (AFB8), not +16 (CB070). Post-inflate D2308-INS wired but skipped (`inflSize=12` sentinel). | `boot_stdout_t5c.log`, `t5d.log` |
| **session 78** | 09-12 | **Broken-stub census 91 → 0.** Last 30 distinct stub targets were one defect repeated: the recompiler under-measured 19 functions, orphaning their exit blocks; fixed by a JTS-TAILCALL tool patch + a dispatch-guard hook. | commit `75ed486` |
| **session 77** | 09-12 | **Systemic jump-table defect FIXED and landed** (patched XenonRecomp regen): each jump-table switch had recompiled to a `// ERROR: 0x…` stub (1557 sites / 873 targets). 863 mapping entries dropped (none referenced from `src/`), dispatcher spans `0x825FDA90`/`0x8260B588`/`0x821DEE40` survived, `ppc_context.h` came back content-identical; output is **176 TUs, not 179** (CMakeLists updated — re-check on any future regen). `sub_8226B450` (29 sites) had to be host-defined in `patches.cpp` (`38600001 4E800020` = `li r3,1; blr`) because the tool registered it without a body. Boot behavior-neutral vs 76y. Residual backlog: 30 distinct targets still stubbed — `0x8255FD48` ×9, `0x8264B38C` ×6, `0x82135C28` ×6, `0x82397FF4` ×5, `0x82388030`/`0x8238802C` ×4 each. Regen config `mcla_jts_regen.toml` (bare filename; scratch copy in `build/xr_jts`). | commit `b3d7dab`; soak `boot_stdout_jts_regen.log` |
| **76t–76y** | 09-12 | **The 0x7E780000 GetDevice crash FIXED.** Root cause = buffer OVERFLOW, not poison: `sub_8218DCE8` (texture pitch) is a jump-table switch emitted as `ERROR: 0x…` stubs → pitch never written → the "missing texture" checkerboard path sized its buffer 32 B but filled 4096 B, over the device-registry holder. Fix = faithful host override `PPC_FUNC(sub_8218DCE8)` in `patches.cpp` reconstructed from the raw image (jump table @0x8218DD14, bodies @0x8218DD6C-30; fmt 1 → `w*4`). New frontier: clean guest fatal (exit 3) `'Unable to load shader 'star_glow', it probably wasn't preloaded properly.'` — the `memory:` mount never happens. Also: BOOTPATH census hook AV'd on garbage descriptor fields → rewritten with checked `ReadBytes`; allocator instrumentation (GEN76-ALLOC ≥4096 B, GEN76-FREE, BUDDY76-*, TEXCTOR) added. | soak `boot_stdout_76y.log` |
| **76j–76s** | 09-12 | Crash decoded: the "missing texture" checkerboard **overwrites the device-registry holder**; allocator fully mapped (3 RE subagents); PAGEWATCH caught the `FF00FF00` writer, FFBT gave the host callstack; lockFlag=FFFFFFFF verified. Evidence: `boot_stdout_76k…76s.log`, `crash_dump.txt` (deterministic signature r3=FF00FF00 r4=8EFFF540 r6=A0082510 r7=A008272C lr=821CB670, AV read at 0x7E780000 = first uncommitted page below the scan). | 76k–76s logs |
| **76i** | 09-12 | Registrar caught: `lr=821C2AAC` writes the registry array; the **count is never written**. PAGEWATCH on registry header `0x82860844` (12 bytes). | `boot_stdout_76i.log` |
| **76h** | 09-12 | Device registry decoded: head `0x82860844`, **stride 264**, entry match fn `821CAA28` (loop in `sub_821CB488` tail, TU18:1419+). | `boot_stdout_76h.log` |
| **76g** | 09-12 | Crash = `fiDevice::GetDevice` walking a BAD device entry (device-list dump in `crash_dump.txt`). | 76g log |
| **76f** | 09-12 | The "ui" preload-list global is **never populated** (watch-proven). | 76f log |
| **76e** | 09-12 | Crash is in **"ui" resource-package processing** (`BOOTPATH` census `sub_82187820`; full decoded chain). | 76e log |
| **76d** | 09-12 | **Positional-read race FIXED** (`ReadFileAt` in `src/fs/vfs_rpf.cpp`: positional OVERLAPPED for real RPF handles; two threads had shared one position). Remaining crash = uninitialized task handle (poison family). | 76d log |
| **76c** | 09-12 | Bad `r8` (0xFFFFFFFF7E780000) is **built in registers** — pinned via llvm-symbolizer + PDB to the inlined call site of `sub_8218F308` inside `__imp__sub_821FA438` (`ppc_recomp.23.cpp:5274`). | 76c log |
| **76b** | 09-12 | The 0x7E780000 pointer is **computed, not copied**: a needle scan of stacks/inflate-out/phys-heap found 0 occurrences. | 76b log |
| **76a** | 09-12 | Host segfault decoded — the crash filter DID work (`crash_dump.txt`): guest AV at 0x7E780000 in the boot-init chain, `ppc lr=821782AC r3=C98C4000 r5=2000 r8=0x1000`. SLOT-READY hardened to require a completed-read set (correctness gate). | 76a log |
| **75z** | 09-11 | 'Fatal disc error' FIXED — `sub_821CC1E0` fatals when `[dev+12]` bit30 set && bit31 clear; our devices had bit30 set and bit31 never set. `DISCCHK` hook sets the ack **before** the original runs. New frontier: reproducible host segfault. | gpu_device.cpp DISCCHK hook |
| **75w** | 09-11 | **Boot stall DEAD.** `sub_821CBE18(slot)` = "wait for slot": waits on the slot's event while `[slot+12]==1`. Our `NtReadFile` completed every read synchronously with evt=0/apc=0 and signalled nothing → the refill loop spun forever. Fix = `SLOT-READY` marks the slot done when the read already completed. Result: `INFLATE-PENDING` 18+spin → 0, SLOT-READY ×3, boot advances past the weeks-long loading-screen stall into 'Fatal disc error'. | soak `boot_stdout_sr.log` |
| **75v** | 09-11 | Page cache is alive; **our NtReadFile violates the Xbox async contract**. Kernel wrapper `sub_8244F4C0` presets `ioStatus=259` (STATUS_PENDING), calls `NtReadFile`, then takes the async path only if r3==259. `RD-SUBMIT` fired 24+ (32 KB reads into page buffers, lr 821C50A4 via vtable slots `0x820121B4`/`0x821062C8`); PAGESLOT real state: `slot @A0083788 base=0x13 size=0x8000 buf=A00E5880 state=2 event=C6009900`, `base=0x14 size=0x8000 buf=A00ED900 state=1`. Fix target: return 259 + `Information`=bytes + signal the event. Also fixed a PAGESLOT dump bug (inner object = `[join_entry4+8]+32` = A0083660, not the vtable). | soak `boot_stdout_75v*` |
| **75u** | 09-11 | Executor decode: 3-slot 32 KB page cache serves 0 bytes on a miss and contains **no fetch call**; batch-1's fetches went through `sub_8244F4C0`, later batches never arm it. This retracts the 75r/75s/75t readings. | 75u log |
| **75o** | 09-11 | Boot requests NAMED: message `0x40003803` → handler `sub_821E5FD0`; task chain captured. Warning recorded: IDA xref lists on this raw bin must be bl-scan-verified. | 75o log |
| **75n** | 09-11 | Boot load machinery verified WORKING (queue, worker `sub_821BC910`, executor, inflate, ~4 MB reads, 15 resource bodies, 1550 shader dicts) — the stall is UPSTREAM in the game-logic init sequence. `INLINE-EXEC` node dump replaced by REQDUMP (16 dwords + ASCII name scan). | 75n log |
| **75m** | 09-11 | The "dead loaders" are dead on hardware too; the dict factory is the **SHADER pipeline** (names are technique names: `draw`, `zprepass_draw`, `multilight_drawskinned`, `CopyDepth`…). File I/O dies after one 4 MB burst (sequential 32 KB reads 0x800→0x3D8000 then zero reads for the rest of a 90 s soak). The streaming/UI loaders are registered in (handler,msgid) tables in `.rdata` (streaming table `0x82104B10`) — reachable only by messages. | 75m log |
| **75l** | 09-11 | Recompiler gap found + fixed: `sub_8221D9D0` had no body (a bogus 4-byte "function" at `0x8221D9CC` swallowed it → the build was broken). DICTFACT decode: `sub_8218BF20`'s r4 is a live deserialization stream slot — 40-byte slot array `0x82860C18`, slot allocator `sub_821BDDE8`, per-slot 4 KB buffer `0x82860DF8 + i*0x1000`, free-slot count `0x827C8874`. Env gotcha: `build/game_data/mcla extracted cache/` must exist or `app.cpp:90` skips `vfs.Initialize` and every `game:/*.rpf` open fails. | soak `boot_stdout_dfact.log` |
| **75k** | 09-11 | GLOBTEX-BOOT: host reads `globaltex.list` (cars+city) and calls the guest insert linker `821854C8(noneObj, name)` per first token → `GLOBTEX-BOOT inserted=20 noneObj=A010B7E0` (the game's own insert on the game's own `none` object). | soak `boot_stdout_gtex.log` |
| **75j** | 09-11 | Insert path works (5×) — ctor `82185648` → insert `821854C8`; but only 3 real names are ever constructed (`"Not Implemented"`, `"uiOverlay"`, `"uiOverlayDepth"`); `STREAMTEX`/`UILOAD` = 0; `REBASE-POISON` 32. Factory parent `sub_8218C760` → `sub_8218C1C0` → `8218BF20`. | soak `boot_stdout_ins2.log` |
| **75i** | 09-11 | Empty-dict factory vs real loader mapped: `sub_8218BF20` zeros dict fields then `8218B000` registers; bulk loaders still dead. | 75i log |
| **75h** | 09-11 | XMemDecompress works — `XMEM` hook `sub_8244FF20` fired 14×, **all `ret=0`** (LZX decompress succeeds); outputs are not texture dicts. | soak `boot_stdout_xmem2.log` |
| **75g** | 09-11 | RSC5/.xtd layout: sample `vnyl_tears_05.xtd` (1227 B) starts `05 43 53 52` = version 5 + "CSR" (RSC5) with XCompress at +12 — matches the inflate 12-byte header skip. | soak + `docs/MCLA_RPF3_Technical_Reference.txt` (lost to the gitignore; folded into `PROGRAM_GUIDE.md` §4/§6) |
| **75e** | 09-11 | IDA MCP live (`:8745`, `mcla_pe.bin`, base 0x82000000). Texture-dict path decoded: named lookup `sub_821849C0` (`"none"`→`0x82839CF0`, else hash `sub_82183E80(&0x82839E2C)`, else list `0x82839ED0`; miss → fatal `"Unable to find texture '%s' in any active texture dictionary!"` @ `0x82009E20`); register `sub_82197598` (not in `ppc_func_mapping.cpp` → no `PPC_FUNC`; census on caller `sub_8218B000`). Dictionaries DO register (10×) but named lookups miss → dict *contents* empty. | soak `boot_stdout_c75f.log` |
| **75d** | 09-11 | TEXINIT runs; named registry fill still missing. Texture registry decoded (`sub_821811C0` lookup, hash table `0x82839E2C`). **Ghidra MCP retired** — IDA Pro idalib is the only RE backend. | soak `boot_stdout_c75e.log` |
| **75c** | 09-11 | Loading gate mapped: `DRAWDISP` (`sub_82227428`) never entered; inflate `-12` / magic `525DE064` is **not** the geometry gate (**stack residue**, not a format magic — 0 hits in src/ + generated/); the `8242FC1C` wait is the healthy GPU-worker tick (`40004D7C`). | soak `boot_stdout_c75d.log` |
| **75b** | 09-11 | `DRAW_INDEXED` mapped: real geometry path `sub_8217A470` → `sub_8241BE78` (SetStreams) → `sub_8241C308` (needs r6=IB) → `sub_82420BA8` **NEVER RUNS**; only the dummy/HUD submit `sub_8217B7B0` (r5=0, streams=0). `DRAW_INDEXED=0` is a symptom of never leaving loading, not a draw-builder bug. | soak `boot_stdout_c75.log` |
| **75** | 09-11 | VMX128 type-2 pack LANDED (Route A): 4 `[[midasm_hook]]` entries in `config/mcla_xenonrecomp.toml` @ `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` + host impl `mcla_Vpkd3d128_type2`; no `0x80000003` in any soak. Regen reproducibility proven: 181/183 files byte-identical (only `ppc_context.h` trailing newline and `ppc_recomp.10.cpp`, which carries a hand safety patch inside `sub_8218CC70` — **never full-replace that file**). Caveat: `VMX128-PACK` counter never fired → not runtime-validated. | `boot_stdout_vmx2/3.log` |
| **74** | 09-11 | Heap AV storm CLOSED — `BLIT-OOB-GUARD` (`gpu_device.cpp` `sub_82431A40`: skip blit when `rectW*rectH` provably exceeds the exact tracked alloc; smoking gun `nearestAlloc=CAEBB000 size=0xa000 gap=0x4`). D3D12 backend up (RTX 3070, 1280×720). New blocker = unimplemented VMX128 ops (host `int3`). | `boot_stdout_blit3.log` |
| **72–73 baseline** | 09-10 | KDELAY stall passed (`SLEEP60270`=0); meshtextures fatal passed via `REBASE-POISON` + D890 skip; ring-B consumers drain; **native present works** (`FRAME-END` ×9+, `NATIVE-PRESENT` ×6, `SWAP-COMP`=9); `DRAW_INDEXED`=0 (empty VB/IB); CDCDCDCD still poisons object fields. | `PROGRAM_GUIDE.md` §7 table |
| **≤ s64** | ≤ 09-09 | Guest park blocker closed: spinlock seed 1→0 in `VdInitializeEngines` + host-side kernel-wrapper identity map; game ran 10+ min in loading screens, 0 crashes. | `docs/BOOT_HANDOFF.md` (lost to the gitignore) |

## Durable facts (still cited; carried forward from the compressed blocks)

**Boot-stack layer map** (layer → status as of the last good soak; use it to place any new
frontier):

| # | Layer | Status |
|---|---|---|
| 1 | CRT init / module load | DONE |
| 2 | Kernel imports (xam/xboxkrnl, 46k stubs, 0 broken) | DONE |
| 3 | Memory device / VFS (`memory:`, `embedded:`, RPF packs — rgxa accepted at BE710, memory-stream reads host-served at BE250) | DONE |
| 4 | Title subsystem ctors (atArray factory family, XTL allocator imports) | DONE (t23a→t24c guards/overrides) |
| 5 | Worker-thread spawn + streaming loads (13 guest threads, entries `821C91C8` + `8242FB88`, semaphores, NTWFSO waits, CP doorbell drain `gpuCtx=40002080`) | REACHED — threads wait on work/streams; W36 moved this further |
| 6 | GPU submit / draw calls / presentation | NOT reached cleanly (`DRAW_INDEXED`=0; present is synthetic) |

**TLS / allocator** (the t24d correction is the current truth):

- New guest threads get a **zeroed TLS table by design** (`src/kernel/guest_thread.cpp` zeroes the
  whole PCR+TLS+TEB+STACK block — was lines 20-35 in the pre-reorg tree). `boot_host` arms ONLY the
  slot-28 alloc chain: **TLS slot +12** (atArray 16 B family) and **FuncBlock+16** (realloc) are
  armed by nobody → first-use AV through a never-armed slot looks exactly like a wipe. `tls0`/[r13]
  is intact (`8F201000`), `ATARRAY-TLSDEAD` never fired.
- Physical pool: one `MmAllocatePhysicalMemoryEx` → o1heap arena at guest VA
  **`0xA0000000`–`0xFFFFFFFF`**; pool16 slabs inside it (`A0014xxx`). Never write `0xA00xxxxx`
  scratch from `SeedPreBootSlots` (o1heap corruption) or from the dead-ctor replay.
- Guest allocator: registry `0x82830B18`; dispatch `sub_821C08F8` →
  `m_Allocators[(r6+1)*4]` = **sysMemDualBuddyAllocator** (arenas `B7xxxxxx`) for default
  allocs; the simple allocator (pool `A0001010..A2E81000`) serves direct callers only. Tiny-slab
  `sub_821DE9D8` memsets every returned element with `0xCD` (so `0xCDCDCDCD` =
  never-initialized field, *not* corruption).

**Executor / streaming** (t24d + 75l–75w):

- The executor's 3-slot 32 KB page cache serves 0 bytes on a miss and contains no fetch call;
  batch-1 fetches go through `sub_8244F4C0`, later batches never arm it → the executor fetch
  gate is the starvation, not the loader.
- File I/O dies after one 4 MB burst (sequential 32 KB reads then 0 reads for the rest of a
  soak) — the game itself never queues another request.
- Host `NtReadFile` completes synchronously; the Xbox contract expects
  submit → STATUS_PENDING (259) → completion finalizes the slot. `SLOT-READY` (`sub_821CBE18`)
  is the honest equivalent while the IO really did complete; `RD-SUBMIT`, `PAGESLOT`,
  `READWRAP` censuses exist for this path.
- Streaming/UI loaders are reachable only by messages ((handler,msgid) tables in `.rdata`;
  streaming table `0x82104B10`); boot loads arrive as msg `0x40003803` → `sub_821E5FD0`.
- Dict-factory stream slots: 40-byte slot array `0x82860C18`, allocator `sub_821BDDE8`,
  per-slot 4 KB buffer `0x82860DF8 + i*0x1000`, free-slot count `0x827C8874`.

**Device / filesystem (`rage::fiDevice`)** — locked facts:

| Fact | Value |
|---|---|
| Guest image | `build/cache/mcla_pe.bin`, identity `off = VA − 0x82000000`, instruction words big-endian |
| Memory-device vtable | `0x82012918` (`+0` `sub_821CAE50` exists/size, accepts `embedded:/` via list; `+4` `sub_821CAFB8` open, **only `memory:`**; `+16` `sub_821CB070` table insert = `EMB76` census; `+80` `sub_821CB400`) |
| Static Device* / dead pointer | `0x827D838C` — returned by the GETDEV prefix checks *and* the dead pointer for `memory:`/`embedded:`. `0x827D8380` is the `fiDeviceMemory` type_info/VFT object, **not** a holder (`PROGRAM_GUIDE.md` §8); base fiDevice vtable (open = stub) `0x8201206C` |
| Name-buffer list | head `0x82860AF8`, node `{+0 name, +4 buf, +8 size, +12 next}`; insert `sub_821D22E8(node,name*,buf,size)`, lookup `sub_821D2308(name,&buf,&size)` |
| Device registry | header `0x82860844` = `{Device** @+0, u16 count @+4, u16 cap @+6}` (cap 16 from `0x827D8384`), entry stride **264**, best-prefix match `sub_821CAA28`; the registrar writes the array but never the count |
| Mount | `sub_821CB9D8`, only 3 call sites; the non-archive chain never executes (F-034) — `MOUNT76`=2 in every boot |
| INSERT resolution | `sub_821BDF20` → GETDEV → **vtable+4** (AFB8), so `EMB76`(+16) is never the acceptance signal |
| Packfile vtable / TOC | `0x82012BDC` / embedded `0x82012B44`; TOC lookup = vtable+144 `sub_821CBFC0` (0 if `[obj+8]==0`); Open `sub_821CDB88` |
| `memory:` strings | `"memory:$%p,%d,%d:%s"` @ `0x82012A28`, `"memory:"` @ `0x820127D8` |
| RPF3 | header `0x800`, TOC `0x1000`, 16-byte BE entries; `xarchive_cache.rpf` has the `0xB116A6AB` TOC-encrypt marker at 0x800 (guest decrypts with the embedded key — works). Compression is XMem LZX, not zlib. |

**Shader / texture dictionary** (used by the T37.4/T37.5 waves):

- Lookup `sub_82189138` (r3=name, −1 on miss, `ppc_recomp.9.cpp`); INSERT `sub_82188E50`
  fails because the resource handler `sub_821CB488` returns NULL; dict hash table
  **`0x82839F70`** (256×4 B; the early `0x827C9F70` was a decode error), active list
  `0x82839ED0`; factory `sub_8218BF20` via `sub_8218B000` (10 entries); ctor `82185648` →
  insert `821854C8` is the working named-texture path.
- Fatal switch `byte_827D5C70` = compile-time 0x01 with zero runtime writers — never patch it.
  Fatal raiser `sub_821BD618` → slot `0x8285FEA0` = `0x82130678` (a real function), host
  override `patches.cpp:441`; `DICT-HYDRATE` (commit `3c8744e`) stays until INSERT proves clean
  without it. Preload lists: `a:/archive/shaders/{ui,city,cars,characters,effects}/preload.list`.
- RSC5 `.xtd`: `05 43 53 52` (version 5 + "CSR"), XCompress at +12 → the inflate hook
  (`sub_821D5E10`, magic `0x0FF512EF`, unknown magic → skip-fatal) strips 12 bytes;
  `XMemDecompress` (`sub_8244FF20`) works (14× ret=0).

**Draw/present path**: real geometry `sub_8217A470` → `sub_8241BE78` (SetStreams, writes
`dev+12748` count + VB descs at `dev+12756`) → `sub_8241C308` (needs r6=IB) → `sub_82420BA8`;
the only live submit is the dummy/HUD one (`sub_8217B7B0`, r5=0). Present swap-table handshake
at `dev+21624/21628` (2 slots per kick, guest writes ZERO, HW fills timestamps LE; completion
processor `sub_824286A0` advances only when slot `(completed+1 & 7)+16` is ready). Task-join
table: count `0x8283D1A8`, entries `0x8283D1C4`, stride 28, wait word `entry+12`.

**Lessons that cost sessions (process):**

- Guest-LR attribution lies after memset/slab-wrapper calls (sticky LR; `0x8244D158`,
  `0x821C2AAC` are artifacts) — use xrefs + arg regs, or the `FFBT` host-backtrace probe.
- `0xFF00FF00`/`0xFFFF00FF` = checkerboard "missing texture" texels, NOT poison.
  `0x7E780000` = `PPC_LOOKUP_FUNC(guest 0)` (null indirect call). `525DE064` = stack residue.
  `0x80000003` = XenonRecomp `__builtin_debugtrap()` for an unimplemented VMX128 mode.
- Before calling a "field never written / garbage value" bug a poison bug: grep the ERROR stubs
  on the involved functions (`grep -hn "ERROR: 0x" generated/ppc_xenon/ppc_recomp.N.cpp`) —
  silent stub returns caused weeks of misdiagnosis (texture pitch → heap overwrite).
- One new log name per experiment; `timeout` every boot; kill `mcla.exe` before linking and
  after every soak; verify `mcla.exe` mtime moved after a link (stale-exe trap). Never build
  while an old `mcla.exe` is running.
- When two statements conflict, the higher/newer one wins — later blocks overturn earlier ones.
