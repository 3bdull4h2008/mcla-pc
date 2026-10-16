## 2026-10-06 18:2x — POINTER BLOCK. The live handoff is BELOW this, not here.

**Go to the heading `# 2026-10-06 — HANDOFF: the boot blocker is SOLVED. Read this first.`** (search the
text, not a line number — it was at line 431 before this pointer existed). **Then go to `## 8. 2026-10-06
20:5x — SUPERSEDING §2` at the END of that block: it answers §2's wall with a 20-frame host backtrace and
names what destroys BOTH o1heap instances (F-778). §2 is trail now, not the frontier.** The two
`SUPERSEDING BLOCK`
headings below are **trail, not truth**, and the 2026-10-02 block's live assertions are now false:

- "**THE COMMIT IS STILL UNMADE**" / "HEAD = `83859255…`" — HEAD is `32127c2` (2026-10-06 18:03). Nine
  commits landed 2026-10-05 19:02 → 2026-10-06 18:03 (`git log -9 --format="%h %ad"`).
- Its blocker (`CP: RING A PARKED … unsatisfied PM4_WAIT_REG_MEM`) is superseded by the 10-06 block.
- "Next free ledger ID: `F-746`" is stale, and so is this pointer block's own earlier replacement of it
  (`F-766`). **Measured 2026-10-06 20:5x: highest heading is `### F-778`, 630 headings total ⇒ next free
  ID is `F-779`.** F-766..F-778 were all written this session.

⚠️ **`docs/ROOT_CAUSE_VALIDATION.md` greps as BINARY.** One deliberate NUL at byte **1,789,044**
(line 12648, inside a quoted guest ASCII tail `…opGamerTask\x00`) — position re-measured 2026-10-06 20:5x
and unchanged by the appends after it. Plain `grep` truncates there, so a valid citation looks absent
(agents.md rule 0's "a grep that finds nothing does not prove a citation was fabricated", now with a
mechanism). **Re-measured with GNU grep 3.0:** `grep -oE "^### F-[0-9]+"` (no `-a`) prints **432 heading
lines / 430 distinct**, last one `### F-543`, plus a trailing `Binary file … matches`; the same pattern
with `-a` prints **630**. ⚠️ This block previously said "**74** of 617 headings" for that exact command —
**74 does not reproduce** under any reading tried (432 lines, 430 distinct, 41 in the F-5xx range). The
*mechanism* is right and the `-a` rule stands; the number was wrong. Always pass `-a` on this file.

⚠️ **None of those nine commits touched the ledger.** `git diff --name-only aadf1ce..HEAD` =
`AGENTS.md`, `MEMORY.md`, `docs/HANDOFF_NEXT_AGENT.md`, `docs/LONG_TODO_MASTER.md`,
`src/apu/audio.cpp`, `src/gpu_device.cpp` — no `ROOT_CAUSE_VALIDATION.md`. So the solved-blocker claim,
the `headIs=1` zlib-oracle proof, the `ctx.r3`-unreadable-at-`sub_8218B0C8` wall, the F-647→F-765
correction and the opcode-18 LI finding are **handoff prose with no F-### record**: UNLEDGERED, and per
agents.md rule 13 a commit hash alone does not make them verified.

---

## 2026-10-02 — SUPERSEDING BLOCK. Ledger through **F-745**. Read this, then the 2026-10-01 block below, which is now trail.

**Nothing below this line is deleted.** This block is the state as of 2026-10-02 06:16 local. The full
evidence — every citation, every falsifier, and three corrections to the brief that produced this block —
is in `docs/ROOT_CAUSE_VALIDATION.md` § **F-729…F-745**. This block is a pointer, not a substitute.
**Next free ledger ID: `F-746`. Do not take `F-695`.**

### One-word state: **FIRST PIXEL, THEN FROZEN.**

Two facts, in this order, and the order matters:

1. **The project reached its first confirmed rendered pixel today.** `build/w700.log` (8,487,020 B,
   sha256 `AA6DBADF20DB29D66E190331DC53B22C9EA893E08A682582CFF1791833BE8B0A`, 55,946 lines) contains the
   first pixel values this backend has ever reported:
   `DRAW-CP-PIXEL #2 draw=2 rgba=(5,8,13,255) at (640,360) rowPitch=5120` and
   `D3D12-DRAW-PIXEL #1 create hr=0x00000000 heap=READBACK bytes=3686400 rowPitch=5120 rows=720
   backBuffer=1280x720 flags=0x1`. The enabling fix is `D3D12_HEAP_TYPE_READBACK` — a heap type that is
   mappable by definition, which four prior paths had declined to use. **Ledger `### F-729`.**
2. **The boot then freezes, correctly, on an unsatisfied memory wait.** `CP: RING A PARKED at
   rptr=0016 header=C0013F00 on an unsatisfied PM4_WAIT_REG_MEM (op=0x3C)`. `rptr` stuck at `0016` for
   **156.349 s** across 20 of 36 `CP: VDRAIN-CENSUS` rows. The wait wants `ref=00000001` at
   `pollByte=1840B284`; the log's own `CP-SCRATCH-WB #2 … dest=1840B284 val=00000001` matches both fields
   exactly but **writes the flat view while the poll reads the pool view, and never calls
   `CpNoteMemWriteDest`.** **OPEN — that is the blocker. Ledger `### F-735`.**

**THE FREEZE IS THE BLOCKER. THE CENSUS IS OPEN. THE COMMIT IS STILL UNMADE.**

### Three things the next session must not get wrong

**1. The pixel census is arithmetically impossible and is OPEN — do not cite those fields.**
`meanChannel=26.0000` **exceeds** `maxChannel=13`, which cannot happen for one region.
`nonBlack=921600/921600` = 100 % on a probe of `rgba=(0,0,0,0)`. And **both `DRAW-CP-PIXEL` rows carry
byte-identical census fields despite different probe values** (row #1 `rgba=(0,0,0,0)`, row #2
`rgba=(5,8,13,255)`, identical `nonBlack`/`maxChannel`/`meanChannel`; row #2's probe sums to exactly 26).
**The probe is real evidence and the summary is not.** An agent is on it. Ledger `### F-732`.

**2. The work is NOT committed, and no single-variable attribution exists.**
HEAD = `83859255b0b7bdff740aeaf8d7195beccfe6e96c`. **`git diff --name-only HEAD -- src/` = 45 files**, so
rule 1a's single-variable check **cannot** be satisfied by anything in today's block: every claim in
`F-729`…`F-745` is **N-way**. Do not let any of it harden into "the fix was X" without a bisect.

**3. Two marker families born today are NOT in `PROGRAM_GUIDE.md` §9, so `tools/soak_census.py` does not
track them** — `DRAW-CP-PIXEL`, `D3D12-DRAW-PIXEL`, `CP-SCRATCH-WB`, `CP-EVENTWRITE`,
`CP-WAITREG-WRITER-MISMATCH`, `D3D12-BEGINFRAME-REFUSE`, `D3D12-FRAME-ABANDONED`, `CP-COLORFMT-VSRTV`.
Their `w700` counts are `DRAW-CP-PIXEL` 2, `D3D12-DRAW-PIXEL` 5, `CP-SCRATCH-WB` 2, `CP-COLORFMT-VSRTV`
2, and **0** for the other four. **A zero for a marker §9 does not list is not evidence of anything.**
Adding them to §9 is the cheapest outstanding task in the project and this session did not have time.

### Kills recorded today — read these before re-asserting anything

- **`CP-WAITREG-NEVERWRITTEN` made a false statement for days.** It queried a **pool VA**
  (`0xB840B284`) against a set keyed on **guest-physical** addresses (`0x1840B284`) — **0xA0000000
  apart, a guaranteed false negative.** Refuted by the log's own earlier line: `CP-EVENTSHD #1
  … dst=1840B284 … written=1`, **2.785 s** before the wait. **`### F-733`.**
- **`PM4_EVENT_WRITE` is not a memory writer.** The reference's `count == 1` form has **no address
  operand and no value operand** (`command_processor.cc:1181-1189`, whose own comment reads *"Just an
  event flag? Where does this write?"*). **The packet that motivated implementing it ran 2.001 s
  BEFORE the park, not behind it.** **`### F-737`.**
- **The standing "PS register N ≡ interpolant N" is dead.** The derivation used a **read** rule and
  invented a `TEXCOORD0` for a shader that writes colour 0 and reads r0 — a register nothing writes.
  That assumption rested on `n = 1`, and that one instance was wrong. The *register-space* reading
  (0–15 are interpolants) survives; only the inference dies. **`### F-739`.**
- **`snapCover` vs `rsPresent` is NOT a contradiction** — same field, same mask, 786 ms apart in
  emission time. **Pair those rows by TIME, never by draw number.** **`### F-743`.**
- **`PM4_WAIT_REG_MEM`'s `budget=2000ms` is host policy, not from the packet.** The reference's writers
  are CPU-side stores and its wait has **no timeout**, so the reference **would hang** where this host
  parks. The host is strictly more conservative — the correct posture. Don't "fix" it toward the packet.
  **`### F-738`.**
- **`DRAW-CP-DRAWN` was counting a refused path**; now gated on `m_stats.drawsIssued`. **`### F-730`.**
- **`layoutRefusal` was set unconditionally and never reset — the layout-completeness proof was DEAD
  CODE**, and a PSO could have been built from an unproven layout. **`### F-740(f)`.**
- **`sizeof(kPrefix)` on a `const char*` = 8, not `strlen` = 20** — off by 13, landing the digit scan
  inside `"float4"` so it read `'a'`, and **every VS emitting an interpolant was refused.**
  **`### F-740(g)`.**
- **`CreateReflection` asked for `IID_IDxcContainerReflection`**; measured matrix says the **IID was
  the whole fault** — the container works under `IID_ID3D12ShaderReflection`, `S_OK`. **`### F-740(i)`.**

### Also worth knowing

- **Log volume reclaimed: 111,153,290 (`w693.log`) → 8,487,020 B; tail 95.59 % → 51.72 %.** The old tail
  was 95.59 % of the file repeating the head's constants verbatim. All four offenders already had a
  cadence gate — the problem was the **population**: a modulus linear in an unbounded serial cannot
  bound volume. Now stride 2^18 with power-of-two summaries, so a truncated soak's last `total=N`
  **bounds the truth to `[N, 2N)`**. Ranks 5–25 got **no edit** — they are the poller-rate and
  drain-truth measurements the freeze diagnosis reads. **`### F-742`.**
- **The abandon loop is closed.** `beganFrame` and abandons each moved **+4800**; 30.0561/s vs 30.0543/s
  = the 33 ms heartbeat, i.e. one completing iteration per tick, **not a spin and not a livelock**. Root
  cause: `ClearAndPresent`'s first act was `MayWriteBackBuffer`, whose own `BeginFrame` ran *after* the
  refusal. **`w700` has 0 `D3D12-FRAME-ABANDONED`** (literal present in the binary) and `FRAME-OWNER`'s
  refusal text is byte-identical. **`### F-741`.**
- **The frame latch had SIX `BeginFrame` failure paths, not three**, and **clearing the latch alone is a
  trap**: `ID3D12CommandAllocator::Reset` then fails `0x80070057`, converting a truthful `already-in-frame`
  into a misleading `allocator-reset`. **The `Close()` is load-bearing.** **`### F-731`.**
- **OPEN: a real off-by-one in the TYPE-0 walker.** `CP: IB-OPC-CENSUS #7 … dwords=1038134
  walked=1038135`. The TYPE-0 arm advances `count + 1` (`gpu_cp.cpp:4307-4315`) so the overshoot is
  bounded by **`count`, not 1**, and `CpType0Apply` feeds out-of-bounds guest memory into `CpRegPoke` —
  a real register write from a foreign buffer. **Clamping `p` is unsafe and incomplete** (the read
  already happened inside `CpType0Write`; `p` also feeds `AccumProgress(p)` at `:4714`). Fix belongs at
  the read boundary, with its own measurement. **`### F-744`.**
- **`chevy` REFUSED again, harder.** Replaying all 108 `MEMBER-SPAN-OWNER` windows byte-for-byte against
  the real `xarchive_cache.rpf`: **`HOLE == bytesChanged` at 100 % for every candidate rule**, including
  F-693's own reverted cap. The range `[004709B3,00490000)` is claimed by **two real byte streams** and a
  flat window can hold only one — a representational impossibility, not a rule-selection problem. The
  `MEMBER-SPAN-ALIAS` premise is also falsified (90 of 92 rows carry `ownerImageIsArchive=0`; bootscripts
  and cameratune contribute **zero** rows), and so is the nested-RPF premise (`handle_nested=0` on all 8
  carconfigs windows; `NESTED-RPF-MOUNT`/`-REGISTER` = 0). **Victim table is 178 spans, not 177.**
  **The file is byte-identical; nothing shipped.** **Narrowest live lead:** `vehicle.lst` **is** decoded
  (`MEMBER-EXPAND off=00471000 … expanded=22391`) and **then never served** — zero `XSF-HOSTSERVE` /
  `SERVE-PROOF` / `LIST-SERVE-VERIFY` rows for it, while those markers fire for other paths in the same
  log. **`### F-745`.**

**NOT DONE BY THIS SESSION, deliberately:** `AGENTS.md`, `LONG_TODO_MASTER.md` and `PROGRAM_GUIDE.md`
were **left alone**. Not enough time to do them properly, and a bad edit to those is worse than none.
`PROGRAM_GUIDE.md` §3/§4/§5/§7 and `LONG_TODO_MASTER.md` §0/§2 are now **behind** this block — §9 needs
the eight markers above, §7's short-circuit registry needs the killed fixes in `F-740`, and
`LONG_TODO_MASTER.md` §2's queue needs "freeze" as the top item.

---

**End of the 2026-10-02 block. Written by a subagent under a 30-minute budget; no build, no soak, no
game run, no git operation. Files written: `docs/ROOT_CAUSE_VALIDATION.md` (append-only, plus the one
`### F-726`-authorised footer amendment) and this file.**
## 2026-10-01 — SUPERSEDING BLOCK. Ledger through **F-692**. Read this, then the 2026-09-30 11:5x block below, which is now trail.

**Nothing below this line is deleted.** This block is the state. Every number below was produced by a
byte-exact count (`bytes.count()` over the whole decoded log, never `findstr`) in the session that wrote
this block; every guest/host address is cited to the log line or the `file:line` that printed it. Where I
could not measure something it says **UNVERIFIED** and says why. **The 09-30 block's "Next free ID: F-654"
is dead — see §5. The 09-28 block's "The tree is RED. It does not boot." is RETIRED — see §7.**

**One-word state: DEGRADED.** `build/w685.log` (12,433,581 B, sha256
`ebe396d085a9b997291df5933f6adaab36758b418860163cf4a9c010d2f65252`, first line `[2026-10-01 08:45:03.260]`,
last `[08:48:03.108]`) builds, reaches the render thread, submits **8** draws, and ends in a **truthful
guest assert** at **+15.847 s** (`Fatal error dispatcher invoked - terminating game`, **line 25092**. Corrected in place 2026-10-01: the block said "line 25,091", and 25091 is an `F442-SECTION #10` row, not the fatal. `build/w685.log` is **raw** — 12,433,581 B, not `.gz` — because the 2026-10-01 de-bloat (`build/LOGS-ARCHIVED-2026-10-01.txt`) compressed only logs older than 2026-09-29, so a plain line number is correct here and no `zgrep` is needed,
`fatal message: 'Unknown manufacturer %s in vehicle list file'`). Zero host AVs (`C0000005` 0,
`Access violation` 0). Not GREEN — 0 pixels and an open regression (§3). Not RED — see §7.

---

### 1. Boot state, `build/w685.log` vs `build/w684.log`

Both logs censused the same way in one pass. `w684.log` = 11,860,787 B, sha256
`2f85adb65b7f498594f3683ca572c0f77bb40b471b50dbbbee0868df95ff644b2`, 71,798 non-empty lines,
`06:58:17.192`→`07:01:16.883`. `w685.log` = 75,874 non-empty lines. Counts are case-insensitive whole-file
substring counts; **the one `%`-note matters, see row 2.**

| marker | w684 | w685 | note |
|---|---|---|---|
| `Fatal error dispatcher invoked - terminating game` | 1 | 1 | boot still ends in a **truthful guest assert at +15.847 s** |
| `fatal %%s arg:` | 1 | 1 | `'chevy'`; `fatal-dispatch regs: lr=0x823966E8`. **Note the two percent signs.** The single-`%` form `fatal %s arg:` is **0 occurrences in `src/`**; `fatal %%s arg:` is 3 (`src/fs/vfs_rpf.cpp`, `src/gpu_device.cpp`, `src/kernel/imports.cpp`) and 1 in `build/mcla.exe` |
| `C0000005` / `Access violation` | 0 / 0 | 0 / 0 | no host AV in either log |
| `OPEN-REFUSED-STATUS` | 74 (36 paths, all `reason=UNPROVED-BODY`) | **0** | the widened proof gate landed |
| — its bytes | `sum(served)`=`sum(logical)`=**3,941,814 B**, `sum(stored)`=9,075,788 B | — | no field on the row sums to 1,234,796 B; if you have a "1.23 MB" figure, name its field before reusing it |
| `SERVE-PROOF-SCOPE` | 0 | **24**, `ran=1` on 24/24 and `ok=1` on 24/24, 12 distinct paths | first firings of this marker in project history |
| `XSF-HOSTSERVE` (`pass=0` subset) | 94 rows, `pass=0` on **6** | 24 rows, `pass=0` on **0** | needle is `pass=0` after `pkgSubst=`, not right after the marker |
| `XSF-INFLATE-SIZE` | 8 | **0** | |
| `LIST-CONTENT-MISMATCH` | 0 | **0** | held — no wrong-bytes regression; literal present in `build/mcla.exe` |
| `GUESTVIEW-U32-FABZERO` | 16 rows / **7 distinct `caller_rva`** | **3** rows / 3 distinct (`0x213dbc`, `0x213ddb`, `0x213e00`) | host→guest context fix landed: 4 of the 7 call sites are gone. Whether the 3 survivors are a self-test is **UNVERIFIED** — no row and no comment in either log or in `src/` contains "self-test" |
| `SYNCTX-STACK` | 0 | 1 — `base=BA2A5280 top=BA2B5280 bytes=00010000 r13=8F200000` | new marker |
| `OPEN-ACCEPTED` | 20 rows / 10 paths | 24 rows / 12 paths | **but 4 paths LEFT** — see §3 |
| `DRAW-CP-REFUSE` | 8 | 8 | all 8 carry `what=no-translated-pso` |
| `DRAW-GATE` plausible / dummy | 0 / 8 | 0 / 8 | 8 draws attempted, **0 pixels** |
| `CP-SHADER-BODY` | 9, `printOmitted=0` on 9/9 | 9, `printOmitted=0` on 9/9 | full bodies in both |
| `CP-WAITREG-ISSUED` / `-SATISFIED` / `-TIMEOUT` | 8 / 8 / 87 | 8 / 8 / **88** | issued=satisfied=8/8; the +1 timeout tracks the extra wait, not a fault |
| `PHYS-POOL-FULL` / `o1heapAllocate returned null` / `MEMBER-EXPAND-SIZE` / `BE710-SLOT-MISS` | 0 / 0 / 0 / 0 | 0 / 0 / 0 / 0 | four wins hold. **All four literals verified present in `build/mcla.exe`** (61,617,664 B, mtime 2026-10-01 08:44:08) — counts 1 / 2 / 2 / 1 — so these are real zeros, not F-057(6) dead text |
| last `XTL-FREE-SUM` | `attempted=8064 honoured=2479 refused=5585 honoured_pct=30.7416 unaccounted=0` | **identical** | |
| last `PHYS-FREE-SUM` | `attempted=2512 honoured=2511 refused=0 honoured_pct=100.0000 unaccounted=1 phys_freed_bytes=25538560 glr=821E0640` | **identical** on every named field | the identity fields (`o1_allocated` `0x1bf0d000`→`0x1b642000`, `caller_rva` `0x2abf7f`→`0x2acfbf`) differ because the two runs are different builds; the counts do not |

**Poison check — and a correction to the claim that was handed to me.** `w685.log`: 75,874 non-empty lines,
600 distinct marker tokens (token 3 after `[ts] [level]`). Top shares: `READWRAP` 13,182 = **17.37 %**,
`CAS-SITE` 10,088 = 13.30 %, `WAIT[KWFSO]` 10,088 = 13.30 %, `WAKE[KWFSO]` 10,086 = 13.29 %,
`INFLATE-ENTER` 6,605 = 8.71 %, `CP-REG-T0` 2,136 = 2.82 %, **`TOCWALK-SLICE` 1,863 = 2.46 %**,
`TOCWALK-DIR` 1,862 = 2.45 %. **`TOCWALK-SLICE` at 1,863/75,874 = 2.46 % is confirmed — and it is the
7th-ranked shape, not the top.** **"No 3-token shape exceeds 10 %" is FALSE as stated.** By marker token the
top is 17.37 %; by `tools/soak_census.py`'s own shape collapse its `LOG QUALITY` lines report **13 %** as the
max (`#CAS-SITE ## lr=#FC#C …`, 10,087 rows; same for `WAKE[KWFSO]` 10,086 and `WAIT[KWFSO]` 10,048).
The honest reading: **`w685` is not newly poisoned** — `w684` was 14.47 % / 14.02 % on the same three
markers, and the tool emitted no `POISONED` verdict — but write **17.4 % by marker token / 13 % by the
tool's collapse, essentially flat vs w684**, never "under 10 %".

**Also from `tools/soak_census.py build/w685.log build/w684.log`, the one honest pipeline signal:**
`CP truth drains=16 last_rptr=0016 pub=49 put=49 (caught up)` — the command processor is **caught up**, not
frozen (this is the `put` column, not a waiter's `rptrWB=` field, which F-057(1)/F-058 retired as evidence).

### 2. Proven this session (nothing here is inherited)

- **`OPEN-REFUSED-STATUS` 74 → 0** while `SERVE-PROOF-SCOPE` 0 → 24/24 `ran=1 ok=1`: the proof gate is
  widened and 24 bodies are now actually proved and served. First data of this kind. §1 table.
- **The `chevy` token really is in the file, and it is capital-C.** Offline, reproducible in one line:
  `zlib.decompressobj(-15).decompress(rpf[0x00471000 : 0x00471000+0x933])` = **22,391 bytes**, matching the
  TOC `w1` logical exactly, and **`Chevy` occurs 8 times** at inflated offsets `[206, 3584, 4862, 7456,
  9154, 9587, 17960, 21899]`. **Re-measured 2026-10-01 from that same one-liner: case-SENSITIVE `Chevy` = 8, case-INSENSITIVE `chevy` = 8, lowercase `chevy` = 0** — so §4's `'Chevvy' x8` is the same 8 and the two spellings in this block never disagreed. (An audit pass reported them as an internal contradiction; it did not reproduce. The guest's own lowercaser `sub_82183870` is why the LOG prints `'chevy'` — `w685.log:25096` — while the member holds capital-C.) Context at 206:
  `…\tName\t\tChevy\r\n\tCanBeOnFire\t1\r\n…`. TOC from the log: `toc=[E94BDE63 00005777 00471000 40000933]`
  (`stored = 0x933 = 2355`, `logical = 0x5777 = 22391`, `off = 0x00471000`).
- **A raw stored-byte scan of the whole 2,130,739,200-byte archive finds exactly 1 case-insensitive
  `chevy` hit.** So all 8 real occurrences in this member are structurally invisible to a raw scan — that is
  the whole reason the earlier "not in the file" reading was wrong. (I did **not** locate the offending
  comment or confirm it has been corrected: **UNVERIFIED**.)
- **`XSF-OPEN` ret flipped 0 → 1 on the four `tune/*` paths that left `OPEN-ACCEPTED`**, with the same TOC
  words: `XSF-OPEN #595 … path='tune/vehicle/vehicle.lst' len=24 ret=0` (w684) → `ret=1` (w685), and
  `XSF-OPEN #537 … path='tune/rmptfx/tireptx.lst' len=23 ret=0` → `ret=1`. (`len=` is the path-string length,
  not the member length.) §3.
- **`GUESTVIEW-U32-FABZERO` 16 → 3 rows and 7 → 3 distinct `caller_rva`.** §1 table.

### 3. OPEN — the KNOWN REGRESSION, stated plainly and **not** softened

**Two first-seen markers in w685, 0 rows in w684, verbatim:**

```
UIXSF-REC pkg=64980000 shot=100 dest=B6282280 goldoff=00040000 len=262144 good=22145 firstbad=+5 probe=03657000 found_at=FFFFFFFF FOREIGN-CONTAINER foreign_pkg=64CB0000@5     (6 of 30 rows)
UIXSF-DIVERGE pkg=64980000 at=00040005 slot=B6282280+00000005 guest=[03657000 70616450 04B2B400 01CDCD00] golden=[04E23000 70616450 0B1B1400 01CDCD00] NOT-IN-GOLDEN-NEIGHBOURHOOD                                  (6 rows)
```

**A container belonging to package `64CB0000` has landed at offset +5 of a 262,144-byte guest-visible UI
region.** Stated as fact: that is what the two rows say. Stated as *open*: **what put it there is not
known, and I am not claiming a mechanism.** Across the 30 `UIXSF-REC` rows: `firstbad=+5` +
`FOREIGN-CONTAINER` + `foreign_pkg=64CB0000@5` on **6**, `firstbad=+0` + `UNKNOWN` +
`foreign_pkg=00000000@FFFFFFFF` on **24**; `len` ∈ {115785, 131072, 262144, 32768}.

**The size of the regression has a measured baseline in this ledger.** `docs/ROOT_CAUSE_VALIDATION.md:11073`
(F-515/F-516, soaks `w520`/`w521`) records the *same shot and the same `goldoff`/`len`*:
`UIXSF-REC pkg=64980000 shot=100 dest=B7C01000 goldoff=00040000 len=262144 good=144864 firstbad=+0 …
UNKNOWN foreign_pkg=00000000@FFFFFFFF`. **`good` 144,864 → 22,145 at identical `goldoff=00040000` and
`len=262144`.** That is the number to argue with, not the marker count.

**Falsifier for the whole item.** A w686/w687 soak that reprints `UIXSF-REC` at `shot=100` with
`good` back near 144,864 and `firstbad=+0` **kills the regression** and it was a one-boot artefact. A soak
that holds `good≈22k firstbad=+5 FOREIGN-CONTAINER` **confirms** it and makes the cause load-bearing. Until
one of those two lands, treat it as open in both directions.

**Second half of the same window — 4 paths LEFT `OPEN-ACCEPTED`:**
`tune/vehicle/vehicle.lst`, `tune/vehicle/vehicle0001.lst`, `tune/vehicle/vehicle0002.lst`,
`tune/rmptfx/tireptx.lst`. 6 paths NEW:
`textures/Random3D.dds`, `textures/effects/fog.dds`, `textures/effects/star_glow.dds`,
`textures/lightglow.dds`, `textures/random3d.dds`, `tune/lighting/SC.ppp`.

- `XSF-OPEN-GATE-SKIPPED path='tune/vehicle/vehicle.lst' entry=B737DE30 +8 00471000 -> host cache not
  poisoned, bit30 withheld from w2, would-be 40471000 (guest memory untouched)` — **fires in BOTH logs**,
  so the gate-skip is *not* new; only the `ret` flip is. `vehicle0002.lst` has **0** gate-skipped rows in
  either log, so "all four went through the gate-skip" is **false as written**.
- **`BDF20 ret` gained a third value in w685 that w684 never printed.**
  w684 = `{−2105144296: 1, −2105144256: 64, −2105144216: 139, 0: 70}`;
  w685 = `{−2105144296: 1, −2105144256: 12, −2105144216: 189, 0: 70, −2105144176: 2}` (274 rows each).
  Writing only "`-2105144256` → `-2105144216`" hides the new `−2105144176`.
- **`MEMBER-SPAN-OWNER refused=1` windows: 52 such rows in w684, 47 in w685.**
  `off=00448000 stored=166323 logical=294912 window=[00470000,00478000) bytes=1 refused=1
  firstRefused=00471000 tail=00490000` — present in **both**, so it **still refuses**. A **second**
  window `window=[00478000,00480000) refused=1 firstRefused=00479000` is **w685-only**.
  These are the *same* offsets as the two gate-skips above (`vehicle.lst +8 00471000`,
  `vehicle0001.lst +8 00479000`). **That is a coincidence of numbers I have measured, not a mechanism I am
  asserting.** Falsifier: show the two window owners are unrelated, or show they are the same span walked
  twice.
- **A regression hunt is in flight.** Do not re-derive any of the above; do not "fix" `UIXSF-DIVERGE` or
  `MEMBER-SPAN-OWNER` by suppressing them (do-not #1/#9).

### 4. The `chevy` fatal — the current chain, and the claims that were KILLED

**Chain, as measured in `build/w685.log` (10 `F442-SECTION` rows in the whole run):**

```
F442-SECTION #2 / #4 / #6  name='Manufacturer' r5=00000000 ret=00000000 hits=0 lr=82397290    (w685)
  -> 10 F442-SECTION rows total; ret distribution {00000000: 9, 00000001: 1}
  -> lr set {821874E8, 82397290 x3, 823972FC x3, 82397350, 823964E8, 82396510}
  -> Fatal error dispatcher invoked - terminating game
     fatal-dispatch regs: lr=0x823966E8 r1=0x8EFFF3A0 r3=0x82051DE8 r4=0x8EFFF4F0 r5=0x00000080
     fatal message: 'Unknown manufacturer %s in vehicle list file'
     FATAL-SOFT: 'Unknown manufacturer %s in vehicle list file' lr=823966E8 - guest paused
  -> 'Chevvy' x8 in the INFLATED tune/vehicle/vehicle.lst at [206,3584,4862,7456,9154,9587,17960,21899]
```

Carried from the ledger and **not re-decompiled this session** (no IDA run): the parser is `sub_821CFF40`
(`docs/ROOT_CAUSE_VALIDATION.md:13856`: "`sub_821CFF40(&it,"Vehicle",0)` found nothing, so `[0x828CD0AC]`
stayed 0"; `:9357` names the same call site `loc_82397328`), the walker is `sub_823971D0`
(`:8552`, `:8918`, `:8983`), the u16 count at `0x828CD07C` and its static registration at `0x828CD0A8`
(`:8946` = `### F-398`, `:9065`), and the reporter is `sub_821BD618` (`:12808`, `:13629`).
**UNVERIFIED this session — but the "0 hits each" here is WRONG, corrected in place 2026-10-01.** The brief handed to this session also names `0x828CD078` as the 8-byte-stride entry
array and `sub_823964C0` as `AllocateCarData`. Measured now over the whole file: `docs/ROOT_CAUSE_VALIDATION.md` holds **`sub_823964C0` ×3** (`:9568` in `### F-443`, `:15119` in `### F-700`, `:15669` in `### F-719`) and **`0x828CD078` ×2** (`:15119`, `:15823`); `### F-700`
states the brief's own chain verbatim ("`0x828CD078` is the 8-byte-stride entry array -> `sub_823964C0` finds `idx == count`"). **`AllocateCarData` itself is still 0 hits anywhere in the tree.** The epistemic status is unchanged — this session decompiled neither function — but
they are no longer *absent from the ledger*, so cite `### F-700` instead of re-grepping. Treat the two links as unproven until `tools/ida_dump.py` or `tools/ppc_disasm.py` prints them.

**Four claims that were killed, so nobody re-derives them:**

1. **"we serve only 10.5 % of vehicle.lst" is FALSE.** `stored`/`logical` is the **DEFLATE compression
   ratio**, not a served fraction: `2355 / 22391 = 10.52 %` — that is where the number came from. I inflated
   the member and got **exactly** the TOC `w1` logical length (§2). **The generalised form "41/41 members
   serve at full logical length" is UNVERIFIED by me**: neither `41/41` nor `10.5` occurs anywhere in
   `docs/ROOT_CAUSE_VALIDATION.md` (grep, 0 hits each), so I cannot cite its entry. Re-derive it or drop it.
2. **"XSF-BIND fired only twice so two files never bound" — the *gate* is confirmed, the *corroboration* is
   not available in w685.** The print is gated `if (n <= 16 || (n % 8) == 0)` at **`src/gpu_device.cpp:20420`**
   (the `MCLA_LOG_WARN("XSF-BIND …")` is `:20421`), and `n` is the **global open ordinal** — the rows beside
   it read `XSF-OPEN #595`. So 2 rows in w684 and 3 in w685 are a **filtered print, not a census**.
   The row that would corroborate it: **`NULL-HANDLE-CHECK` has 24 rows naming vehicle/tireptx in w684** (24
   of 129; sample `path='tune/rmptfx/tireptx.lst' ret=0 … proved=1 bound=1 slotHeldNoBody=0`) and **0 such
   rows in w685** (59 rows total, 24 with `proved=1 bound=1`, none on a `vehicle`/`tireptx` path).
   **So "proved=1 bound=1 for all three vehicle paths" is a w684 fact that w685 does not reprint.** Re-establish
   it before relying on it.
3. **The `walked == 2*t0` framing I was handed is WRONG, and the correction matters.** Both fields **are**
   printed — `CP: IB-OPC-CENSUS #1 ibTotal=1 win=B7C8A2C0 dwords=11 depth=0 trace=1 walked=11 t0=2 t1=0 t2=0
   t3=1 nonzeroT3=1 firstT3Off=5 firstT3Hdr=C0043C00 || op=0x3C count=1` — 32 rows in **each** log, so the
   identity **is** measurable. `### F-685` (`docs/ROOT_CAUSE_VALIDATION.md:14707-14718`) holds **8/8 in
   `w680`** and attributes it to a **TYPE degeneracy** (a zero dword scores TYPE-0 because `hdr>>30 == 0`),
   explicitly *not* to an empty buffer — and says the load-bearing evidence is the raw `CP: INDIRECT_BUFFER`
   dump showing 16 zero dwords where `PKT-CAP` read real bytes `0x20000000` lower, a *pointer-base*
   disagreement, which is what F-680's `CpPhysToPoolVa` addresses.
   **My byte-exact recount of the two current logs: `walked == 2*t0` holds 0 of 32 in w684 and 0 of 32 in
   w685.** So it is not a standing 8/8 invariant any more. **What is genuinely unsupported is the
   `holds=` metric: there is no `holds=` field on any row of either log (0 of 32 in both),** so any
   "real register writes" number keyed on `holds` is a F-057(6) tautology. Write it that way, not as
   "`walked`/`t0` are unmeasurable".
4. **Two dead instruments, both confirmed dead.** **`MEMBER-SPAN-TAIL-VETO`**: the string occurs on
   **194 rows in w684 and 196 in w685** and **every single one is a `MEMBER-EXPAND-OVERRUN` row** (it is
   prose inside that marker's message); 4 src occurrences, all in `src/fs/vfs_rpf.cpp`; 2 in
   `build/mcla.exe`. It has never once printed its own row. **`GUESTVIEW-U32-SUMMARY`**: 1 src occurrence
   (`src/guest_memory.cpp`), 1 in `build/mcla.exe`, **0 rows in both logs.** Per `AGENTS.md`/`F-057(6)` a
   marker's zero means nothing until you have proved the literal exists and can fire — here both fail.

### 5. Next free ID — measured, and the dead pointer retired

**Do NOT follow the 09-30 block's "Next free ID: F-654".** `### F-681` adjudicated it unsafe
(`docs/ROOT_CAUSE_VALIDATION.md`, `### F-681`: *"The instruction to begin at `F-654` is falsified by the
tree"*; the ledger carries the sentence *"NEXT FREE ID: F-654" IS UNSAFE. This is the reason this block
starts at F-681 and not F-654."*).

**CENSUS RE-MEASURED 2026-10-01, IN PLACE. This supersedes every number in the table below and the §5 prose under it; the reasoning is unchanged.** `docs/ROOT_CAUSE_VALIDATION.md` is **2,218,346 B** with **584** `### F-(\d+)` heading lines, **min F-77, max F-728**. Count only `^### F-\d+` headings — a naive `F-(\d+)` token scan of the file returns 5,684 and over-reports. **NEXT FREE ID IS `F-729`, NOT `F-697`.**
Seven ids repeat on a `^### F-\d+` scan (`F-111, F-200, F-204, F-595, F-612, F-617, F-681`), but only **four** are real duplicated headings (`F-111`, `F-595`, `F-612`, `F-617`); `F-200`/`F-204`/`F-681` repeat only via the lettered `### F-200b`/`### F-204b`/`### F-681b` and the compound `### F-612/F-613` / `### F-617/F-618` headings, exactly as `### F-681b` adjudicated — **left untouched, not renumbered.**
`### F-726` in the ledger records the same max and count and prints its own falsifier: a max other than `F-728` or a count other than **584** means another session appended mid-block and every next-free-id statement here is stale — re-run the census. It also records that `F-697`…`F-728` are all written, that **`F-693`/`F-694`/`F-696` are retroactively written as `### F-724`/`### F-722`/`### F-723`** (so their rows below are retired), and that **`F-695` is declared PERMANENTLY UNUSABLE** — 0 `src/` citations, 0 headings, genuinely free, but sitting *below* the consumed `F-696`, so do not back-fill it and do not "tidy" the sequence. The ledger's own footer reads *"NEXT FREE ID: `F-729`. Do not take `F-695`."*

| what | measured | verdict |
|---|---|---|
| max `### F-NNN` heading | **F-728** (was **F-692** when this block was written) | naive "next" = **F-729** |
| **safe next free ID** | **`F-729`** (was **F-697**) | `F-697`…`F-728` are all written; `F-693`, `F-694`, `F-696` are now **entries**, not orphan citations |
| `### F-681` … `### F-728` | **48** headings present (was 12 through `F-692`) | the real sequence starts at F-681 |
| **`F-693`** | **4 citations, 0 entries** — 3 in `src/fs/vfs_rpf.cpp`, 1 in ledger prose at `docs/ROOT_CAUSE_VALIDATION.md:14992` | **CITED, NOT AN ENTRY.** Allocating F-693 collides **[SUPERSEDED 2026-10-01: retroactively written as `### F-724`; no longer an orphan.]** |
| **`F-694`** | **7 citations, 0 entries** — **all 7 in `src/`** (`src/gpu_cp.cpp`, `src/render_queue.h`), **0 in any doc** | **CITED, NOT AN ENTRY.** Note: it appears in *no* ledger prose, so nothing warns you **[SUPERSEDED 2026-10-01: retroactively written as `### F-722`; no longer an orphan.]** |
| **`F-696`** | **3 citations, 0 entries** — all 3 in `src/fs/vfs_rpf.cpp`, 0 in any doc | **CITED, NOT AN ENTRY.** This id was **not** in the brief that produced this block; I found it by census **[SUPERSEDED 2026-10-01: retroactively written as `### F-723`; no longer an orphan.]** |
| `F-629` | 18 citations (2 in `src/gpu_device.cpp`, 16 in docs), 0 entries | **documented VOID SLOT** — ledger: *"VOID SLOT F-629 - F-629 EXISTS ONLY IN CODE"*; `AGENTS.md` forbids reuse. Do not renumber; reconstruct as a new F-6xx/7xx citing 629 |
| `F-654`…`F-659`, `F-680` | 0 entries; my counts 25 / 18 / 6 / 40 / 9 / 5 / 37 = **140 citations** | cited with no entry, adjudicated by `### F-681`. My 140 ≠ F-681's 91 because my scan counts `docs/ROOT_CAUSE_VALIDATION.md`'s own prose too; **do not present either number as the other's** |

**Full orphan-citation list (cited somewhere, no `###` heading). 114 ids, in two classes:**

- **Class A — below the ledger's first heading (76 ids): `F-001`…`F-076`.** The ledger's minimum heading is
  F-77, so nothing below it can have a heading; each is cited **once** in ledger prose and **zero** times in
  `src/`. This is the pre-compaction range (`AGENTS.md` describes the ledger as compacted to
  "claim + evidence"), not a new loss.
- **Class B — inside the range, no heading (38 ids), with my citation counts:**
  `F-150`×6, `F-153`×8, `F-162`×5, `F-258`×5, `F-266`×1, `F-329`×29, `F-364`×5, `F-388`×6, `F-389`×4,
  `F-390`×6, `F-409`×3, `F-412`×64, `F-427`×7, `F-429`×5, `F-460`×1, `F-466`×1, `F-483`×5, `F-494`×3,
  `F-511`×27, `F-516`×10, `F-524`×11, `F-528`×3, `F-610`×79, `F-615`×6, `F-618`×17, `F-625`×20,
  `F-628`×50, `F-629`×18, `F-654`×25, `F-655`×18, `F-656`×6, `F-657`×40, `F-658`×9, `F-659`×5,
  `F-680`×37, `F-693`×4, `F-694`×7, `F-696`×3.
  Of these, **`src/` alone** carries: `F-412`×55, `F-610`×52, `F-680`×25, `F-654`×12, `F-657`×34,
  `F-655`×16, `F-694`×7, `F-696`×3, `F-658`×6, `F-656`×4. **`F-694` and `F-696` are the only two with
  zero doc citations at all** — a `src/` comment can be the sole record of a finding, and both are invisible
  to anyone who reads only the docs.

**Rule to carry forward: allocate the next id above `max(heading)` **and** above every orphan citation.
Today that is **F-729** — `F-697` when this block was written, which is now itself an entry (`### F-697`, ledger `:15001`). F-681 is the precedent for refusing a lower allocation.**

**The two-queue rule, and where the queue actually lives.** `docs/LONG_TODO_MASTER.md` §2 is
`## 2. Tasks (in order; stop-ship gate each)` at **line 992**, running to before `## 3. File map` at
**line 1606**. **Measured drift:** `T41.59` and `T41.60` appear only at LTM lines **315 / 331 / 344** —
all inside a `§0` state block, **not** in §2. `T42.20` → **0** hits anywhere in LTM. `task #87` → **0**
hits in LTM. `F-692` → **0** hits in LTM. Real sequencing migrated to ids invented **inside the ledger**
(`T41.59`→`T42.20`, "task #87") that §2 does not contain. **Both places are named here so neither is
silently the truth: the durable queue is §2, the live sequencing is the ledger, and they have diverged.**
Per `AGENTS.md` a queue item may not live in only one of them.

### 6. Durability — read this before you trust a number that is not in a log

- **HEAD is `83859255b0b7bdff740aeaf8d7195beccfe6e96c`, dated `2026-09-27 23:23:27 +0300`**
  (`rpf_offline.py: stop names/find crashing on a truncated tail record`). **The 09-30 block's "last commit
  `d7125d1`" was the last commit that *touches the ledger* — `git log -1 -- docs/ROOT_CAUSE_VALIDATION.md`
  = `d7125d1e48a9088871cf2aebfd1294a93600b65d` — not HEAD.** Both facts are recorded because only one of
  them was true and the block stated the other.
- **F-572…F-692 plus ~42 modified / 13 untracked `src/` files exist ONLY in the working tree**, on the E:
  drive that zeroed this ledger once on 09-20. Measured today: `git status --porcelain` = **99 lines**
  (56 ` M`, 2 ` D`, 41 `??`); under `src/` **55** = **42 ` M` + 13 `??`**. `git diff --shortstat HEAD` =
  **58 files changed, 53,764 insertions(+), 16,220 deletions(-)**; `src/` alone = **42 files,
  +34,453 / −2,916**.
- **The ledger's uncommitted delta — corrected in place 2026-10-01. The 09-30 block's "~194 KB of uncommitted
  ledger work" is stale, and so was the version of this line written with the block.** Measured now: working copy
  **2,218,346 B** vs HEAD blob **1,846,156 B** = **Δ +372,190 B**; `git diff --numstat HEAD -- docs/ROOT_CAUSE_VALIDATION.md` = **+16,078 / −12,965 lines**; `git diff --shortstat` on that path = **1 file changed, 16,078 insertions(+), 12,965 deletions(-)**; counted off the diff text itself, **+2,202,187 / −1,832,776 B**.
  **Name the field you mean** (file size vs size delta vs lines vs diff bytes). Those are four different figures, not variants of one, and the audit brief's "~2.0 MB added / 1.4 MB deleted" matches none of them exactly.
- **A verified off-volume backup now exists at `C:\mcla-pc-uncommitted-20261001\`** (C:, off the E: volume
  that lost the ledger). Re-measured this session: `tracked.patch` **6,729,792 B**, sha256
  **`466ed6a739cd50712c0a80cb61c1a1915f58cf5c2a1e08229dd4b36d6a14f6e1`** — matches `MANIFEST.txt:29`;
  **`untracked\` holds 46 files**, re-counted this session; `staged.patch` is **0 B**. `MANIFEST.txt:12-13`
  records `git diff --stat HEAD : 58 files changed, 53633 insertions(+), 16216 deletions(-)` and
  `of which under src/ : 42 files, +34322 / -2912`; `MANIFEST.txt:97` records
  `46 of 46 files re-hashed source-vs-copy, 0 mismatches (sha256 AND byte length)`; `MANIFEST.txt:3` says
  *"Purpose: PROTECT uncommitted work. NOT a commit. Repo untouched."* and `MANIFEST.txt:7` pins the same
  HEAD sha.
  **Honest caveat: the tree has drifted since the manifest was written** — my recount is +53,764/−16,220
  overall and +34,453/−2,916 under `src/`, i.e. **+131 and +131 lines** past the manifest. The backup is a
  verified snapshot of an earlier moment, not of right now. Re-run it before relying on it.
- **Project rule: commit only when asked. NO COMMIT HAS BEEN MADE.** This block is a working-tree edit to
  one doc. Nothing was staged, nothing was stashed, no code was edited, no build was run, no game was run.
- **Do not `git add -A` here.** `docs/HANDOFF_NEXT_AGENT.md` was **already ` M`** before this block (pre-edit
  sha256 `8134f2cc32e1778cb809a9b624bcca2b81b2e3e536ab5d0b649effa1263b174a`, 495,673 B, mtime 2026-09-30 12:10:47). **The line count is corrected in place 2026-10-01: the block said "2,545 lines", which is impossible — the true pre-edit count is 3,014 lines.** HEAD's blob is **2,601 lines / 447,107 B, 2,601 LF and 0 CRLF** (`git cat-file -s HEAD:docs/HANDOFF_NEXT_AGENT.md`) and `git diff --numstat HEAD` = `718  0`, so the file is now **3,319 = 2,601 + 715 + 3**; this block is lines 1-301 and the pre-edit file was lines 303-3316 = **3,014 lines**. Reconstructing those bytes gives **495,667 B**, Δ6 B from the 495,673 quoted above — the ±1 separator blank at the block boundary is unresolvable — so **the quoted byte figure and sha256 stand as the author's own measurement, UNVERIFIED by me.**
  Stage named paths only; `git add -f docs/…` for a newly tracked doc.

### 7. RETIRED: the 09-28 "The tree is RED. It does not boot."

The 2026-09-28 19:5x block's line 1 sentence — **`**The tree is RED. It does not boot.**` (this file, line
116 of the pre-edit text, quoting `build/w657.log` at 1,173 lines)** — is **RETIRED as of this block.**
`build/w685.log` builds, boots 180 s, reaches the render thread, submits **8** real draw submissions
(`DRAW-CP-REFUSE` 8, `DRAW-GATE dummy` 8, `DRAW-GATE plausible` 0), has **0** host AVs, and terminates in a
**truthful guest assert** — the guest correctly refusing a manufacturer it cannot find. That is a
**different failure class** from "does not boot": the pipeline runs, the guest is talking, and the guest is
telling us the data is missing. **Do not delete the 09-28 block — it is superseded here and kept as trail.**

### 8. Bookkeeping for the session that wrote this block

- **One file touched: `docs/HANDOFF_NEXT_AGENT.md`. This block is PREPENDED at lines 1-301 and no pre-existing line was
  edited, reordered or deleted by it (per `AGENTS.md` rule 5). **"Prepended only" was FALSE as written — corrected in place 2026-10-01, not by deleting the evidence:** `git diff -U0 HEAD` on this file is exactly two hunks, `@@ -0,0 +1,715 @@` and `@@ -2601,0 +3317,3 @@`, i.e. **718 insertions / 0 deletions**, so 3 lines were also **appended at EOF** by another session. They are lines **3317-3319**, they are **all blank**, they carry **no date header and no content**, they are not attributable to this block, and they were deliberately **left in place**. (The 715-line top hunk is this block's 301 lines, plus the blank separator at :302, plus the whole uncommitted 2026-09-30 block; HEAD's newest `##` block is the 2026-09-27 20:2x one.) **`AGENTS.md`, `docs/PROGRAM_GUIDE.md` and
  `docs/ROOT_CAUSE_VALIDATION.md` are untouched by me** — and note this means **the ledger has still gained
  no row for this session's work**; whoever owns `### F-693`+ should record it there.
- **Every marker literal quoted in §1–§3 was verified present in `src/` or in `build/mcla.exe` before its
  zero was interpreted** (the F-057(6) rule). The three exceptions are named as exceptions in §4.4.
- **Pre-edit sha256 of this file: `8134f2cc32e1778cb809a9b624bcca2b81b2e3e536ab5d0b649effa1263b174a`**
  (495,673 B). Post-edit sha256 is recorded in the session report, not here.

---


---
**[2026-10-01] Session trail relocated to [docs/archive/trail-handoff-2026-10.md](docs/archive/trail-handoff-2026-10.md)** (blocks 2026-09-30 backward; nothing deleted).

---

# 2026-10-06 — HANDOFF: the boot blocker is SOLVED. Read this first.

`HEAD = 3606e30`. Working tree clean under `src/`, 0 staged. **Do not redo anything below.**
> ⚠️ **Stale as of the commit that carried it** (2026-10-06, later that evening): this block was written
> when HEAD was `3606e30` and was then *committed as* `32127c2` ("docs: handoff - boot blocker solved at
> a9bd027…"), so the line above is self-invalidating. **Current HEAD is `32127c2`** — re-run `git log
> --oneline -3`; do not trust either sha as live. The top-of-file block at `:7` carries the corrected
> reading. Nothing else in this block is affected.

---

## 1. THE BLOCKER IS FIXED. THE EVIDENCE, AND THE MEASURES THAT PROVE IT

`a9bd027` — **`gpu_device`: snapshot the reader cursor before the device read.**

**Cause, in one sentence.** `pos` is dword 1 of the reader object the caller passes as `r4` — the
guest's own byte cursor into the member's logical bytes. The file already snapshotted `r4`/`r5`/`r6`
around `__imp__sub_821CC1E0` but **never extended the snapshot to the two dwords it then read out of
guest memory**, so every read observed the *previous* read's end position. The callee's tail advances
it: raw `0x821CC3CC stw r11,4(r31)`.

**The falsifier that killed the alternative reading** — do not re-derive it:
> 18 rows, 18 different members, six different archive offsets, `pos=4096` on every one and
> **never 8192**. An accumulating cursor cannot read 4096 on eighteen independent first pages.

**Measured, `build/w734.log` and `build/w736.log`:**
```
                             w733 (had a fatal)   w734/w736 (no fatal)
Fatal error dispatcher / FATAL-SOFT     1                 0
dstAfter=507B5CED   (DEFLATE head)     1                 0
dstAfter=61786772   (shader magic)     0                 1
ARC-WINDOW headIs=1 (byte-exact)       0                 1
WINWR-CMP beqTaken                     0                 1    r7 = r8 = 0x61786772
boot duration              ~14 s to a fatal    149.8 s, no fatal
DRAW-CP-DRAWN                            -                 4    (was 2)
golden pct=100                          25                30
```
**The plateau is over.** 27 soaks died at 14.494–16.184 s. These do not die.

**The window is NOT a ring** — settled, do not re-open: the fill is clamped by
`uncompressedSize - cursor` (raw `0x821CC260`–`0x821CC27C`), `cur`/`end` are monotone, and two
windows exist one page apart (`0x82861DF8`, `0x82862DF8`). Double-buffering, not a ring.

---

## 2. THE CURRENT WALL — narrow, measured, and NOT a fix you can guess

```
VEH[3] code=0xC0000005  lr=8218B458  read of host addr 0x7e780000
     slot_guest_va=0xFFFFFFFF7E780000
preceded by: BE710-DEAD … outcome=REFUSE-NO-BODY
             XTL-ALLOC-REFUSED size=413 -> returned 0
             o1heap invariants FAIL
```

**The arithmetic is solved.** `slot_guest_va = 0xFFFFFFFF7E780000` becomes host `0x7E780000` via
the **same expression `src/ppc_context.h:127` evaluates.** An agent predicted `would_read_host =
0x7E780000` analytically, before running anything, and a soak reproduced it to the digit.

**The gate is not solved.** A guard on `sub_8218B0C8` was written, soaked, **and reverted** because:

```
AVGUARD-CTR-OOR #8  vt_read_ok=0  vt=00000000  slot_read_ok=0  passthru=0
```
**`passthru=0`** — the host could not read `ctx.r3` at all, so the guard refused **every** call,
including legitimate ones. `FATAL-SOFT` went 0 → 1, `dstAfter=61786772` 1 → 0, `DRAW-CP-PIXEL`
2 → 0. Reverted with `git checkout 3606e30 -- src/gpu_device.cpp`; the good state is restored and
re-verified in `w736.log`.

**THE QUESTION TO ANSWER: why is `ctx.r3` unreadable at `sub_8218B0C8`?** That is a guest-object
resolution problem, not a fault to guard against. `IsKernelObject(handle)` is only
`Translate(handle) != nullptr` (`src/kernel/xdm.cpp:32-39`) and `Translate` returns `m_base +
guestAddr` for **every** `guestAddr < kSize` (`src/kernel/memory.cpp:476-481`, `kSize = 0x100000000`).
**Establish whether that predicate should admit `0xFFFFFFFF7E780000`, and what the real object is.**

⚠️ **A guard that removes the crash while destroying the boot is a net loss.** The crash is a
symptom; reaching the shader check is progress.

---

## 3. A REGRESSION THAT IS NOT ONE — and why it matters more than it looks

```
TOCWALK-SLICE   w685..w722 = 1863 (34 logs, perfectly constant)
                w723..w736 = 0     (14 logs)
AFB8-IN         35 -> 1     BE710-MAGIC 114 -> 0
```
**The TOC walk never ran legitimately.** It ran 1863 times *only because the `kBe710MagicWrite`
fabrication kept the guest limping past 57 dead bodies* long enough to miss `EmbeddedListLookup`
35 times. Remove the lie → 1 open → 0 walks. **This was attributed by content plus a measured
single-variable revert**, because a commit-date bisect is structurally impossible: **all 13
commits have committer-date ≥ 10-05 16:28, i.e. 14 h after w723. The good state was uncommitted.**

**The serve gate is NOT the cause.** Reverting `ret >= 0` at `gpu_device.cpp:22297`:
```
AUtoc_head_control   TOCWALK-SLICE=0  fatal=False
AUtoc_revert_gate    TOCWALK-SLICE=0  fatal=True    <- the fatal RETURNS
```
**So the gate widening is load-bearing for the no-fatal property. Do not revert it.**

**`REFUSE-NO-VERDICT` = 0 in ALL 45 real soaks including healthy ones — it carries ZERO
information.** Its only literal (`gpu_device.cpp:21738`) is inside `if (verdict == nullptr)`, which
is unreachable once `TOCWALK-SUMMARY` has stored a verdict. **Do not use it as evidence.**

---

## 4. CORRECTIONS TO THE RECORD — do not re-import these

| the record said | the truth |
|---|---|
| `F-647`: all three decompilers render rotate-masks backwards | **INVERTED.** MB=1,ME=1 ⇒ bit 30 ⇒ `0x40000000`, which is what the ISA, `ComputeMask`, IDA and `ppc_recomp.17.cpp` all print. Corrected in `AGENTS.md`. |
| `ori`'s destination is `b20:16` | **`b25:21`.** Correct for `ori`/`addi`/`addis`/`lwz`/`stw`; `b20:16` is correct for `or`/`and`/`xor`/`mr`/`cmp`. **Both right, different opcodes.** |
| `rec[8]` is zero | **wrong address** — `[rec+8]` is the caller's state object; the archive offset is `[[rec+0]+8]`, and it is **non-zero**, 4 KiB-aligned. |
| `o8` is page-quantised | **exact archive offsets** (`0xE4000/0x10000 = 14.25`). |
| `o8=0x000F5000` is "one hex digit" from `0x001F5000` | **1 MiB apart, different member** (`cf_bump2.dds`). Coincidence. |
| `TOCWALK-SUMMARY` at `vfs_rpf.cpp:21174` | **`gpu_device.cpp:21665`**. `REFUSE-NO-VERDICT` is `:21738`, not `:21247`. |
| "24 soaks, median 14.903 s" | **45 real soaks exist, not 43 or 123** — 42 are 0-byte sidecars. The literal `'Unexpected EOF…'` is in **2 of 45**. |
| `AUDIO-FRAME`'s zero is prose | **the marker is compiled and leads its own row.** The zero is real. |
| `M6_PAGE_SPLICED_AT_+0x5000` / `M6_PAGE_RAW_AT_+0x5000` | **do not exist anywhere in `src/`.** Phantom. |
| `TIMEOUT_SURVIVED` = a pass | **= 0 across 232 logs.** Not one log ever ended because the guest was running; every soak dies of a fatal then thrashes to the cap. **`process survived` is NOT a pass condition.** |

---

## 5. ~~A NEW ENCODING FINDING THAT MAKES 123,273 TARGETS RESOLVABLE~~ — **REFUTED 2026-10-06, DO NOT USE (F-771)**

🔴 **STOP. Everything in this section below this banner is WRONG and was withdrawn the same night it was
written. It is kept verbatim because this file is append-only, not because it is live.** The claim
"opcode-18 branches use a 26-bit LI at word bits 2..27, AA at bit 1, LK at bit 0" is **inverted**.
Measured directly off `build/cache/mcla_pe.bin` (147,363 opcode-18 words): word bit 0 (MSB) is set in
**0** of them and bit 1 (MSB) in **147,363** — so "AA at bit 1, LK at bit 0" is structurally impossible,
since LK=1 must appear on every `bl`. A bits-2..27 reading puts **0** targets inside the image; the
**textbook** I-form (LI = `word & 0x03FFFFFC`, sign-extended, ×4) puts **144,453** inside. Positive
control: **13,548 of 13,548** recompiler-resolved `bl` sites match the textbook reading. `123,273` was
never reproduced by anyone. **`AGENTS.md`'s opposite error ("unresolvable both ways") was also corrected
that session** — see `AGENTS.md` RULE 0 and ledger **F-771**. If you need op-18 targets, use
`tools/ppc_xrefs.py` (which already encodes `0x03FFFFFC` and carries `--selftest --image`, checking all
293,540 branch words against `tools/ppc_disasm.py`).

**opcode-18 branches use a 26-bit LI at word bits 2..27, AA at bit 1, LK at bit 0.**
The textbook 32-bit I-form (bits 6..31) puts **0 of 147,363** opcode-18 words inside the image;
this reading puts **144,170** inside and lands **123,273** on functions that exist in
`ppc_func_mapping.cpp`.

**`AGENTS.md` currently says op18 targets are "unresolvable both ways". That is now wrong, and it
was propagated into briefs that told three agents to give up.** ⚠️ **Verify on a second sample before
correcting `AGENTS.md` — I have already put one wrong rule in that file tonight.**

---

## 6. THE STANDING RULES THAT COST THE NIGHT — read these before touching anything

- **Extract instruction fields nibble by nibble.** Shift-and-mask produced **four** wrong answers.
- **`ppc_disasm.py` is a PowerPC disassembler and CANNOT decode Xenos GPU microcode.** It also inverts `mr` (F-112) and cannot decode `rldicl`. Use `generated/ppc_xenon/*.cpp` as the tiebreaker.
- **`ppc_xrefs.py calls` invents callers on vtable dispatch** — it reported 20 "callers" of `0x821BE250` where a raw scan finds **0**. Its `->` column names the *enclosing* function.
- **`CALLERS (none)` is an IDA carving artefact, not evidence.**
- **Never put a constant in a census field.** `WINWR-CMP` printed `kAoCmpR8`, a hardcoded literal, and that "measurement" was believed for an hour. Deleted.
- **Establish the discriminating power of any control.** One believed *powerless* discriminates five wrong-models; one believed *sufficient* was symmetric and could never have found its bug.
- **A marker's prose can contain other markers' literals.** `READAT-BRANCH`'s prose contains `raw_positional=1`. **25 of 39 miscounts were this.**
- **A marker absent from `src/` has a zero that means nothing.** `AUDIO-FRAME` is live; `MEMBER-SPAN-ALIAS` is not tracked; `MEMBER-SPAN-TAIL-VETO` has 0 real rows and 33 prose mentions.
- **Never accept a fix on a marker count.** Nine fixes moved markers and not the boot. The measures that count: `headIs=1` byte-for-byte against a python-`zlib` oracle, `dstAfter=61786772`, `FATAL-SOFT=0`.
- **`git checkout <commit> -- <file>` does NOT restore a byte-exact pin** — `core.autocrlf=true`, files are bare-LF, checkout converts. **Verify reverts by content.**
- **Six+ harnesses passed while blind.** One served a body out of a **zero page** and reported fabricated bytes while passing. One reported **90.5%** because it harvested English prose as data. One reported a confident **0** because `re.match` anchored at line start and every line begins with a tab.
- **E: FAILED MID-SESSION.** 158 `.obj` files and `mcla.exe` became unreadable *and undeletable*; `src/gpu_device.cpp` lost its content. A reboot cleared it. **Verify `build/mcla.exe` begins `4D 5A` before every build** — a corrupt exe reports `BUILD_RC=0 error=0`.

---

## 7. THE QUEUE

`docs/LONG_TODO_MASTER.md`, dated block "2026-10-06 — QUEUE AFTER THE BOOT BLOCKER WAS SOLVED",
39 items in three tiers. **Tier 1 is everything behind the blocker that has never once been
exercised:** audio (the guest never constructs the XAudio object — `sub_823F3640` has no caller
and is not in `.CRT$XCU`), input (implemented, hooked, polled every frame, **0 non-NULL polls
ever**), and **the menu, which has 0 evidence in 261 logs.**

⚠️ **71 `LOG_UTILITY` sites in `src/kernel/imports.cpp` compile to nothing under `NDEBUG`, with no
log line at all.** Parts of this project are invisible to every log we have; their zeros are
tautologies.

**The charter win stands and must not be undone:** `kBe710MagicWrite` wrote the exact value the
guest was about to check for, suppressing **57** fatals. Deleted. Verify absent at all times:
`kBe710MagicWrite` = 0, `WriteU32BE(ctx.r4` = 0 across `src/`.

## 8. 2026-10-06 20:5x — SUPERSEDING §2 AND §1's "narrow wall". The wall now has a 20-frame host backtrace, and the thing destroying BOTH allocators is named. Ledger **F-776 / F-777 / F-778** (top is now F-778, 630 headings).

**Read this before §2.** §2 asked "why is `ctx.r3` unreadable at `sub_8218B0C8`?" and called it the
remaining wall. `w740` answers a different and more useful question: **what is `sub_8218B0C8` doing?**
It is the link that destroys the physical allocator.

### 8.1 The chain, proven by host backtrace, not by a guest `lr`

`F379-HEAPSTORE-BT` fired exactly once in `w740` (20 frames, every frame `inmod=1`), and all 20 resolve
with `tools/host_rva_resolve.py build/mcla.map` against the **20:28:33** map — the same build as the log:

```
sub_82131508 -> sub_822C2EA8 -> sub_823047D8 -> sub_82187820 -> sub_82188E50 -> sub_8218C760
             -> sub_8218C1C0 -> sub_8218B0C8 -> sub_821BE250 -> sub_823DA950 (guest memcpy)
             -> WriteU64BE(GuestMemoryView) -> [our watch probe]
```

So `sub_8218B0C8` calls `sub_821BE250`, which calls the guest memcpy `sub_823DA950`, whose **generated
body** runs one 128-byte unrolled block — fifteen non-updating `std rN,8..120(r3)` closed by a single
`stdu r6,128(r3)` (`823DAAF8..823DAB68`) — i.e. **exactly 16 stores of 8 bytes of `0x0`, covering
0x80**, and those 16 land on `0xA0400000 .. 0xA0400078`, the **first 128 bytes of the physical o1heap
instance**. The printed 16 rows are therefore not an arbitrary cap-truncation: they are one complete
loop iteration, and row #16 (`guest=A0400078`, `caller_rva=0x17008c9` = `+0x699`) is the closing
`stdu`. Frames 5/6 also independently corroborate `lr=821BE3BC`, so that `GetPPCContext()` read was
live, not sticky.

### 8.2 The `dst` argument is EXACTLY `0xA0400000`

`F375-HEAPSTORE #1` prints `r3=A03FFFF8` against `guest=A0400000`. **Do not read `r3` as the
destination argument.** The path taken is *not* the `ldu`/`stdu` doubleword loop at `823DA9F4`, and
inside the `>= 0x80` target the alignment loop at `823DAA90` is skipped too because
`0xA0400000 & 0x7F == 0` (`beq -> 823DAA9C`). What actually runs (`tools/ppc_disasm.py 823DAA6C 44`) is
`addi r3,r3,-8` once at `823DAA70`, then a 128-byte unrolled block whose stores are **non-updating**
`std r6,8(r3)` / `std r7,16(r3)` / `std r8,24(r3)` … `std r7,120(r3)`, closed by the single updating
`stdu r6,128(r3)` at `823DAB68`. So `r3` is a **fixed base** = `dst_arg - 8` for the whole block.
**`dst_arg = 0xA0400000` exactly — the guest was handed our instance's own first byte as a copy
destination.**

⚠️ **Which loop ran is proved host-side, NOT by `ctx.r5`.** The earlier text of this section said
"`r5=FFFFFFAF >= 0x80` makes `bge cr7` taken". **`ctx.r5` is a stale translator-local writeback and
`0xFFFFFFAF` is not the length** — see F-778 §4d(ii): `sub_821BE250` is a buffered `read(dst,len)` whose
two exits are exhaustive (path A ⇒ `len = arg3`; path B is entered only when `arg3 > W−R` so the residual
is strictly positive), and all four call sites in `sub_8218B0C8` get the length from `sub_821BE4F0` =
**readByte**, which returns only `0..255` or `0xFFFFFFFF`. `−81` is in neither set. The sound discriminator
is **`caller_rva` distinctness**: phys and user each show **16 rows / 16 distinct `caller_rva`s**, and the
two ordered rva lists are **identical** (`+0x2df … +0x699` from body base `0x1700230`). A `ldu/stdu` loop
has ONE store instruction and would give ONE rva for all 16 rows; 16 distinct return addresses can only be
the unrolled block's fifteen separate `std` sites plus its closing `stdu`. **`live r5 >= 0x80` therefore
follows from the path, not from the register dump** — and the ~4 GiB `ctr = len >> 7 = 0x1FFFFFF` reading
in F-778 §4 loses its only numeric support. The live length is either `[128,255]` (one block, copy ends)
or `0xFFFFFFFF` (runaway); **both print exactly 16 rows, so `w740` cannot separate them.**

**The log corroborates the addressing mode arithmetically as well:** all 8 `F375` rows carry
`r3=A03FFFF8` *unchanged* while `guest` advances `A0400000 -> A0400038` by 8, so `guest - r3` = `0x8,
0x10, 0x18, 0x20, 0x28, 0x30, 0x38, 0x40` — exactly the displacement fields of those eight `std`
instructions in order. An updating `stdu` loop would have moved `r3` too. The same rows print `r6=0 r7=0`,
the loop's own load registers holding zero source data, and host code inside `WriteU64BE` does not touch
the guest context.

**Who returned `0xA0400000` is STILL UNNAMED (F-778 §4d(iii)).** It arrives at site `8218B300` as the
return of the allocator thunk `sub_82130528` (called at `8218B2EC`), but the title's XTL bank is
`0xA0401000..0xA042FFC0` (F-395/F-631, 0x1000 *above* the arena base) and our o1heap's minimum return is
`base+0x240 = 0xA0400240`. `boot_host.cpp:4175-4219` only *logs* the pool base. **Do not cite
`LOWPOOL` = 0**: it is a suffix tag on `BUDDY76-FREE` (`src/hooks/alloc_census.cpp:3524`) whose gate is
the disjunction `n <= 60 || ptr >= kPhysArenaBeginVa` (`:3499`), and `BUDDY76-ALLOC` = `BUDDY76-FREE` =
**0** in `w740.log` — the hook on `sub_82130010` never fires, so it is an **unreachable instrument, not a
bounded one**. Naming the provider needs a new probe on the `sub_82130528` return at `8218B2EC`.
**None of this blocks the fix**: whatever returned it, `0xA0400000` must stop being a returnable address.

I wrote this section wrong **twice** and corrected it in place both times before commit: first reading
`r3` as the argument (§4b of F-778), then citing the right conclusion from the *unexecuted* `ldu/stdu`
loop (§4c). Both wrong versions are kept in F-778 so nobody re-derives them. **General rules: a register
dumped mid-library-function is a running pointer, not a parameter; decode the branch predicates and
follow the one actually taken before quoting any instruction as "the store that fired"; and when a
`ctx.rN` read is load-bearing, look for a host-side discriminator that does not need it.**

### 8.3 The root cause is an address collision WE created, not guest corruption

`src/boot_host.cpp:196` sets `F640PoolPhysBase() = kPhysArenaBeginVa - 0xA0000000 = 0x400000`, and `:226`
maps `poolVa(pa) = kPhysArenaBeginVa + (pa - 0x400000)`. `src/boot_host.h:188` states the same boundary
from the other side: `kNoPoolByte` = "physical **< 4 MiB**". Therefore **`pa = 0x400000` maps to
`poolVa = 0xA0400000 = kPhysArenaBeginVa`** — our o1heap instance header sits at the **first byte of the
guest's own usable physical pool**, inside the `static_assert`-pinned guest extent
`[0xA0400000, 0xC0400000)` (`src/kernel/heap_arena.h:130-137`).

**`heap_arena.h:52-55` says "The instance here is still safe (0xA0400000 is 0x1000 below the first block
o1heap returns)". That is REFUTED.** Its safety argument only considered the title's XTL slab region
*above* the base (`0xA0401000..0xA042FFC0`, F-631) and the first block *our* o1heap returns (`+0x240`).
Neither bounds what the guest hands to a `memcpy`. **F-391 already moved this base once — `0xA0000000 ->
0xA0400000`, for exactly this reason — and it moved the collision instead of removing it. Two
relocations have now failed the same way, so a third small move is not a fix.**

### 8.4 The same 16 store sites zero the USER instance too

16 `F374-HEAPSTORE inst=user` rows at 20:30:59.126, guest `00020000 .. 00020078`, and the
`caller_rva` set is **byte-for-byte identical** to the phys set — all 16 values, same order. One code path
in the generated memcpy body destroys *both* allocator instances. **Gap:** the user event has no
backtrace (`F379` = exactly one event, and it is the phys one) and no register dump (`F375` capped at 8
rows, all phys), so its entry path is inferred from the identical store sites, not proven.

### 8.5 Three instrument results that are CAPS, not measurements — do not quote them as totals

| instrument | value | what it actually bounds |
|---|---|---|
| `F374-HEAPSTORE` / `F631-HEAPWIN` | 16 per instance (32 rows each, strict-anchored) | cap `n <= 16 \|\| (n % 4096) == 0` (`src/guest_memory.cpp:134`, both printers sit inside it); no `%4096` row, so the cap-agnostic bound is **[16, 4095]**. **Tightened 20:5x from the two windows that actually bind:** the printer reports its own `window=[A0400000,A0400240)` / `window_bytes=0x240` (the o1heap instance extent), while the armed watch is `[0xA0400000, 0xA0400800)` for phys (`src/boot_host.cpp:3207-3208`) and only `[0x00020000, 0x00020100)` for user (`:3216-3217`). A store must be inside **both**, so at the observed stride of 8: **phys ∈ [16, 72]** (0x240/8) and **user ∈ [16, 32]** (0x100/8). *Conditional on every in-window store being 8-byte* — the 32 rows show `op=U64` and stride 8, but no counter proves nothing else wrote there. Still a cap, still not a measurement |
| `F774-PHYS-MEMCPY` | 40 rows | cap `k <= 40`; all 40 are `len=2`, `dst=A043Cxxx`, inside **4 ms at 20:30:02.749-.753** — the budget burned out **9 s before** the phys event and **57 s before** the user event. **It excluded nothing and proved nothing about `0xA0400000`.** This is F-774's cap defect reproduced verbatim in the instrument built to replace it |
| `F382-MEMCPY` | **0** | **an open contradiction, not a clean negative.** Its positive control `F382-MEMCPY-LIVE` = 1, so the hook is live; yet the user instance *was* written by the same 16 sites and the phys backtrace has frame 4 = `sub_823DA950 +0x337` (the override). An override on the stack should have matched its own user-window span test. Unresolved — **never report this zero as "the guest never copies low"** |

Also: `F631-HEAPEXT` = **0** anchored rows (the bulk writer never saw a range overlapping either window,
because the copies arrive as individual `WriteU64BE` stores) — but `grep -c F631-HEAPEXT` returns **32**,
because every `F374-HEAPSTORE` row *ends with the literal text* "the whole event is `F631-HEAPEXT` or
`F631-HEAPWIN`". **The same text also inflates the sibling: `grep -c F631-HEAPWIN` = 64 while the true
count is 32** (16 phys + 16 user) — measured 20:5x.

**And the token-boundary half of the anchor rule is not sufficient on its own — the line prefix is the
load-bearing half.** F-777 §4(b) states the rule correctly as *both* halves ("anchor on `] [level] `
**and** match the token exactly"), but a census that only does the second half — "match the token
followed by a space or `#`" — scores `F631-HEAPEXT` as **32**, because in the F374 message text the
token *is* followed by a space ("…`F631-HEAPEXT` or…"). The only anchor that works is the
**line-prefix** one: `^\[\d\d:\d\d:\d\d\.\d\d\d\] \[\w+\] (MARKER)`. Strict-anchored counts for the
whole family in `w740.log`: `F374-HEAPSTORE` 32, `F375-HEAPSTORE` 8, `F631-HEAPWIN` 32,
`F631-HEAPEXT` **0**, `F379-HEAPSTORE-BT` 20, `F774-PHYS-MEMCPY` 40, `F382-MEMCPY` **0**,
`F382-MEMCPY-LIVE` 1. Raw `grep -ic` differs from those on exactly three markers (`F631-HEAPWIN` 64,
`F631-HEAPEXT` 32, `F382-MEMCPY` 1) and every difference is a marker name appearing inside another
marker's prose or as another marker's prefix. **Fold the prefix regex into `tools/soak_census.py`
rather than re-deriving it per session.**

### 8.6 Frontier: unchanged, every gate condition held

`w740` (300 s, `TIMEOUT 300s` = process survived) vs `w739`: `draw_indexed` **0 = 0**,
`o1heap invariants fail` **4 = 4**, `xtl-alloc-refused` **4 = 4**, `headis=1` **1 = 1**,
`dstAfter=61786772` **1 = 1**, `veh-neutral` **1 = 1**, `f370-heap-hdr` **1 = 1**, `HEAPHDR-STORE`
**202 = 202**, `PARAM-STORE` **400 = 400**, `watch: range armed` **32 = 32**, `code=0x80000003` **0 = 0**.
The only intended movement is `F374-HEAPSTORE`/`F631-HEAPWIN` **16 -> 32** = exactly one head cap for the
new phys window (F-777).

Moved, and **NOT attributed** to a log-only change: `code=0xC0000005` 3->5, `fatal-soft` 1->0,
`fatal error` 1->0, `F388-PHYSGUARD-BT` 32->16, `xsf-lastserve-mismatch` 225->226. Across
`w738->w739->w740` the first three read 5->3->5, 0->1->0, 0->1->0 — the bimodal pattern already in project
memory, so a single-variable claim would be unsupported (rule 1a).

### 8.7 LANDED AND VERIFIED (2026-10-06 22:05, F-779): the fix works. What is still NOT landed.

**This section previously read "No fix for §8.3 is landed." That is now superseded — the fix is landed,
built, soaked for the full 300 s and controlled on the same guest caller.**

- **The fix (F-779).** Two new additive functions in `src/kernel/o1heap.c` — `o1heapInstanceSize()`
  (`:363`) and `o1heapInitSeparate(instanceMem, base, size)` (`:368`) — plus `VirtualAlloc`-backed
  instance memory in `Heap::Init` (`src/kernel/heap.cpp:2400-2407`, `:2419-2421` user, `:2446-2448`
  physical). Both o1heap instances now live in host memory **outside** their arenas. No statement of
  `o1heapInit`/`o1heapAllocate`/`o1heapFree`/`o1heapDoInvariantsHold`/`o1heapAllocateGranular` was
  modified, so the "NOTHING ELSE HERE CHANGES" notes at `o1heap.c:569` and `:605` still hold and
  `INSTANCE_SIZE_PADDED` is still `0x240` (`:181`), i.e. every hardcoded instance offset in the
  instrumentation still means what it says.
- **The result, `w741b` (300 s) vs `w740` (300 s).** `XTL-ALLOC-REFUSED` **4 → 0**,
  `o1heap invariants FAIL` **4 → 0** (case-insensitive; a case-sensitive grep scores 0 in the baseline
  too — the census skill's `-i` rule, re-broken and re-caught), `PHYS-STATE` **0 → 1**. Both soaks'
  decisive rows carry the **same `glr=82137904`**, so it is the same guest allocation site with opposite
  outcomes: `cap=0` + `invariants FAIL` + `returned 0 (console value)` becomes `capacity=0x20000000` +
  `verdict=healthy why=suitable_class_present split=exact`. `PHYS-STATE` is a second independent proof:
  it is emitted at `heap.cpp:3252`, *after* the invariant gate's early `return nullptr` at `:3121`
  (gate at `:3096`, FAIL row at `:3103`), so under the old layout it was structurally unreachable.
  Everything else flat: `DRAW_INDEXED` 0, `PRESENT` 49, `C0000005` 5, `Fatal error` 0, `FATAL-SOFT` 0,
  `headIs=1` 1, `dstAfter=61786772` 1, `PHYS-OVERRUN` 7, `F379-HEAPSTORE-BT` 20, `F631-HEAPWIN` 32,
  `skip fatal` **1 → 2 matching lines** ⚠️ **CORRECTED — this bullet originally read "`skip fatal` 0 vs 2
  (fewer short-circuits firing)", which is wrong in both its numbers and its direction; see §8.10 and
  ledger `F-780`.** Mitigation lines are **2,043 → 2,047 (+4)** and the three new rows are a `P5-PHYS`
  short-circuit that had been silent for 18 consecutive soaks. `soak_census.py` reports
  `DEPTH 32,157 vs 31,381 = 1.02x -> COMPARABLE`.
- ⚠️ **THE SHORT `w741` SOAK IS VOID *FOR THE REFUSAL CLAIM ONLY* — read this before re-using it.**
  `build/w741.log` was killed externally (exit `0x40010004`) after **99.0 s** — span
  `21:36:30.494→21:38:09.487` by its own first and last timestamps; *(this bullet said "85 s", and printed
  the correct span beside the wrong number — re-measured for F-780 §6)* and it *also* read
  `XTL-ALLOC-REFUSED 4 → 0`. But `w740`'s four refusals all fired at **+139.9 s**, which `w741` never
  reached. **The zero was a duration artifact indistinguishable from a fix.** Rule: a zero is a result
  only if the new run's timestamps **span the moment the baseline event occurred**; longer-or-equal
  duration is necessary, event-time coverage is what is sufficient. `w741b` (22:00:14→22:05:13) covers it.
  **The rule cuts both ways (F-780 §6): `w741` DOES cover +14.9 s, so it is valid evidence for the
  `P5-PHYS` return in §8.10 and supplies the second independent post-fix observation. Voidness is
  per-event-time, not per-file.**
- **NOT eliminated — the conflict is narrowed.** `F374-HEAPSTORE` is still **32**, at the same relative
  times (+25 s / +75 s), with the same 16 distinct `caller_rva`s: **the guest still zeroes 128 bytes at
  `0xA0400000` and `0x20000`.** Only *what is there* changed. The title's XTL bank
  `0xA0401000..0xA042FFC0` is still **inside** the 512 MiB our o1heap allocates from, so two allocators
  still believe they own the same bytes. The fatal consequence is gone; guest-visible double-ownership
  ~~is unmeasured either way~~ **IS NOW MEASURED — see §8.10 / `F-780` §7: the `P5-PHYS` row fires on
  `old=B6FB2F29`, inside this same arena, i.e. the guest asked its own rebase table about one of our
  physical addresses, missed, and was about to fatal.**
- **Exhaustion is a separate, still-live problem.** `PHYS-STATE #1` at +146 s: `allocated=0x1dd0d000`
  (477 MiB) of `capacity=0x20000000` (512 MiB), `free=0x22f3000` (36 MiB), `peak_req=0x12b84020`
  (**314 MiB in one request**), `oom=1`. Both soaks already show `allocated=0x17465000` (390 MiB) at
  **+1.4 s**. **Do not read `XTL-ALLOC-REFUSED = 0` as "the physical pool is sufficient"** — the refusal
  that was removed was a destroyed-header refusal (`cap=0`), not an exhaustion one.
- **Five log-only instruments are now STALE and will mislead.** They read the instance through a *guest*
  address (or through `g_hdrArena`) and now read arena/fragment data. Full citations, re-verified line by
  line, are in **F-779 §9**; in short: `F373-HEAP-RAW` (printer `heap.cpp:1824-1826`, reads `:1810-1815`,
  and its `moved=` field is now unconditionally 1 because it compares a guest-arena translation against a
  host `VirtualAlloc`); **`F373-HEAP-GOLDEN`** (printer `:2809-2810`, read `:2805` — *its `cap=` stays
  correct while its `hex=` changes subject, so the F-100 golden reference now diffs against the wrong
  thing, which is worse than no reference*); `F370-HEAP-HDR`'s `hdr_off=` field (`:1791`, computed
  `:1794-1795` against `g_hdrArena = heapArenaBase` at `:2422`); the `boot_host.cpp:468` needle comment
  ("fragments start +0x240" — no longer true, and the bucket logic at `:465-468` classifies a trip by
  offset into an instance that is no longer there); and the watch windows at `guest_memory.cpp:60-61` and
  `:77-78` (`kHeapWindows[]` `:79-82`). **`F374-HEAPSTORE` rows after this fix are NOT a failure** — that
  is the guest writing to what is now ordinary arena memory. Retire or re-aim them in a separate, log-only
  build (**T43.5**). *(This bullet originally said "four" and cited `heap.cpp:1810-1815, :2755`: `:2755`
  is an unrelated comment about the HeapGuardWindow ordering rule, and the field at `:1794-1795` is
  `hdr_off=`, not `moved=`. Both re-measured for F-780.)*
- **`AttachPhysicalArena` (`heap.cpp:2485-2490`) still rebinds to an ATTACHED instance.** Dead code in
  this tree; wiring it up without detaching it reintroduces the collision. Noted at `:2442-2444`.
- **The `PHYS-VERDICT-CHANGE` instrumentation-order defect is still NOT landed.** The gate at
  `src/kernel/heap.cpp:3096` logs and does `return nullptr` at `:3121`, i.e. *before* the `:3252`
  `EmitPhysState` and `:3255` `NotePhysVerdict`, so the verdict row keeps its last healthy value exactly
  while the allocator is refusing everything. F-779 made it moot *for this failure* (the gate no longer
  trips), but it would hide the next one the same way. `docs/PROGRAM_GUIDE.md` records it as not landed.
- **The provenance probe for §8.2's unnamed provider is NOT landed either.** It is a separate, additive,
  log-only instrument on the `sub_82130528` return value at guest `8218B2EC`. Per rule 1a it must be its
  **own** build+soak.
- **Revert test not run.** F-779's claim rests on the forward control (same-`glr` pair + timestamp
  coverage), not on a revert-and-see-it-return.
- **Nothing is committed.** Working tree carries `AGENTS.md`, `docs/HANDOFF_NEXT_AGENT.md`,
  `docs/PROGRAM_GUIDE.md`, `docs/ROOT_CAUSE_VALIDATION.md`, `src/guest_memory.cpp`, `src/gpu_cp.cpp`,
  `src/gpu_device.cpp`, `src/kernel/heap.cpp`, `src/kernel/o1heap.c`, `src/kernel/o1heap.h`,
  `tools/ppc_disasm.py`, `tools/ppc_xrefs.py` and two `.qoder/skills/` files. Commit only when asked.

### 8.8 Two `AGENTS.md` rules were wrong tonight and are corrected — do not re-import them

1. **"F-112: `tools/ppc_disasm.py` prints `mr` with RA/RT inverted" is FALSE** (F-776 §3). Re-measured on
   three words, all correct: `7C9D2378` -> `mr r29,r4`, `7FC8F378` -> `mr r8,r30`, `7C8B5214` ->
   `add r4,r11,r10`. The old entry even contradicted itself — its own control `or r8,r30,r30` **is**
   `mr r8,r30` in long form. Acting on it would have broken a correct decoder. The real rule: **b11:15 is
   the destination for the logical family (`or`/`and`/`xor`, hence `mr`); b6:10 is the destination for the
   arithmetic family (`add`/`subf`)**. Both are right for their own family; neither generalises.
2. **The `host_rva_resolve.py` worked example gave the wrong symbol base.** `__imp__sub_823DA950` is
   sec:off **`0001:016ff230`** = `Rva+Base` **`0x141700230`** => RVA **`0x1700230`**, extent **`0xF30`**.
   An earlier revision said `016ff170` / `0x1700170`, produced by hand-computing `0x170050f - 0x2df`;
   **`sec:off 0001:016ff170` does not exist in the map at all**, and RVA `0x1700170` is inside
   `__imp__sub_823DA748` at `+0x5b0`. Read the map's **third** column and subtract with a computer.

Also new in F-776: `tools/ppc_disasm.py` now prints `NOT-DECODED(use generated/ppc_xenon/*.cpp)` on every
opcode it cannot interpret, so a family name can no longer be mistaken for a decode; `--selftest` is still
**25/25 PASS**. The real remaining gap is op-30 only: **5,884 words of 2,588,672 (0.23%)**.

### 8.9 Session bookkeeping

Two soaks, both new log names, both `TIMEOUT 300s`, `mcla.exe` killed (verified `tasklist` clean at
20:37 and again at 20:50): **`build/w739.log`** (20:14:45->20:19:44, 5,109,385 B) and
**`build/w740.log`** (20:29:30->20:34:47, 5,170,727 B). Build 20:28:33, `BUILD_RC=0`; the exe was
verified to have moved and to contain the new format-string literals with the old ones at count 0, because
`BUILD_RC=0` came back twice with a 0-byte build log. Next free ledger ID: **F-779**.

### 8.10 2026-10-06 22:3x — the fix landed, then its own census was re-audited and one claim fell over. Ledger **F-779** (the fix) + **F-780** (the correction). Supersedes §8.9's "Next free ledger ID: F-779" — it is now **F-781**.

**T43.9 IS DONE AND VERIFIED.** `o1heapInstanceSize()` + `o1heapInitSeparate()` in `src/kernel/o1heap.c`
(`:363`, `:368`), declared at `src/kernel/o1heap.h:99`/`:122`, wired in `Heap::Init` at
`src/kernel/heap.cpp:2400-2407`, `:2419-2421` (user) and `:2446-2448` (physical). Both instances now live
in `VirtualAlloc`'d host memory outside their arenas. `build/w741b.log` (300 s) vs `build/w740.log`
(300 s), same guest caller `glr=82137904` on both sides: `XTL-ALLOC-REFUSED` **4 → 0**,
`o1heap invariants FAIL` **4 → 0**, `PHYS-STATE` **0 → 1**. Details and the honest limits are §8.7 and
F-779; **read F-780 before quoting §8.7's neutrality sentence, which was wrong.**

**WHAT THE RE-AUDIT FOUND (this is the part worth the reader's time).** Three errors, all in text written
*this* session, all caught by re-running the citation rather than remembering it:

1. **`skip fatal` "0 vs 2 (fewer short-circuits firing)" was inverted.** The tool run that produced the
   number printed `host short-circuit lines … 2,047 (baseline 2,043)` **in the same sentence** — i.e.
   **+4, more**. And `skip fatal` is graded `field`, **0 own rows in both logs**; its two matching lines
   are owned by `inflate-skip:1` and `p5-phys:1`. The census skill has warned about this exact phrase
   since 2026-09-20. **New failure mode to remember: a `field`-graded label's own-row count is
   legitimately 0, so it reads as "nothing fired" and can hide a mitigation in *both* directions.**
2. **The three new rows are a real short-circuit, and a P1 signal.** `P5-LOOKUP` → `P5-MISSFIX` →
   `P5-PHYS`, all at `22:00:29.492` = **+14.9 s**, all from `PPC_FUNC(sub_821D2378)`
   (`src/task_dispatch_trace.cpp:579`, arm `:604-611`, printer `:607`, registered in §7 at `:226`), called
   from `sub_8260A830 +0x80` via `bl 0x821D2378` at raw `0x8260A8AC` = `4BBC7ACD`. It sets `ctx.r3=0` and
   returns **instead of invoking the guest's resource-group-miss fatal** (`b 821BD618`). The value it
   absorbed, `old=B6FB2F29`, is **inside `[A0400000, C0400000)`** — our physical arena.
3. **The dormancy curve makes it P1, not noise.** `P5-PHYS` = **14** in `w720`, **14** in `w722`, **0 in
   all 18 of `w723`…`w740`**, then **1** in `w741` *and* **1** in `w741b`. That is the same
   `w722 → w723` boundary as the TOC-walk regression (`LONG_TODO_MASTER` §2 item 2.1) — **but they
   diverge**: `TOCWALK` 3,987 → 0 at `w723` and is **still 0** in `w741b`, as are `DIRS=` (2 → 0) and
   `SLICE` (3,727 → 1). So the `w723` regression is **at least two independent mechanisms**, and the one
   feeding `sub_821D2378` is downstream of the physical allocator, not of the TOC walk. Item 2.1's
   "attribution is N-way and unresolved" is now too coarse.

**Rule 1a is satisfied**, so F-779 may be named as the cause: `find src tools -newermt "2026-10-06
20:28:33" ! -newermt "2026-10-06 21:35:49"` returns only `src/kernel/heap.cpp`, `src/kernel/o1heap.h` and
`tools/ppc_disasm.py` (not compiled). `src/kernel/o1heap.c`'s later mtime `22:10:56` is **comment-only**
(verified by reading `:334-337` and `:355-360`), so the `21:35:49` exe still matches the tree. **No revert
run**, so direction stays provisional in the strict sense.

**Two census defects found by this — the first is now FIXED *AND VERIFIED BY THE TOOL*, the second is a
citation correction, also landed.** `P5-PHYS` / `P5-MISSFIX` / `P5-LOOKUP` were registered in §7 but
**absent from §9**, and `markers_from_guide()` (`tools/soak_census.py:813-848`) reads only §9 first cells —
so the tracked battery carried only `P5-GATE` (0 in both) and the marker table had **no row at all** for
the three (an untracked literal prints nothing; it does *not* print `+0` — this block said "`+0` for
everything" before it was corrected, and the table did print deltas elsewhere, e.g. `CAS-SITE` +248).
**A mitigation in §7 and not in §9 is invisible to the tool whose job is to catch mitigations firing.**
Measured scope: **8** literals in the heap/P5 family had 0 §9 first-cell rows — `PHYS-POOL`,
`PHYS-POOL-FULL`, `P5-LOOKUP`, `P5-MISSFIX`, `P5-PHYS`, `F373-HEAP-RAW`, `F373-HEAP-GOLDEN`,
`F374-HEAPSTORE` — while `PHYS-STATE`, `HEAPHDR-STORE`, `F631-HEAPWIN`, `XTL-ALLOC-REFUSED` were already
tracked. **Three §9 rows added 2026-10-06 22:4x; verification is the tool re-run on the SAME two logs:**
`257 tracked` (was 249, +8 exactly) and rows `P5-LOOKUP 1 0 +1 <<` / `P5-MISSFIX 1 0 +1 <<` /
`P5-PHYS 1 0 +1 <<` / `PHYS-POOL 1 1 +0` / `PHYS-POOL-FULL 0 0 +0` / `F373-HEAP-GOLDEN 1 1 +0` /
`F374-HEAPSTORE 32 32 +0`, plus **one delta that was structurally invisible before:
`F373-HEAP-RAW 0 1 -1 >>`** — that stale instrument went silent post-F-779 because its reader changed
subject; **it is NOT a regression and NOT a fact about the heap.** Also landed: §7's `P5-PHYS` citation
`:606` is the cadence gate, the printer is `:607` (arm `:604-612`, mitigation body `:610-611`); and a
supersede note on the §9 `PHYS-STATE` row, whose eight `heap.cpp` citations all drifted under F-779
(gate `:3006`→`:3096`, FAIL `:3013`→`:3103`, `return nullptr` `:3031`→`:3121`, `EmitPhysState`
`:3162`→`:3252`, `NotePhysVerdict` `:3165`→`:3255`, `NotePhysAttempt` `:3046`→`:3136`,
`NotePhysPoolFull` `:3172`→`:3262`, free-path `:3516`→`:3606`) **while the ordering defect itself is
unchanged — T43.1 is still open.** Standing rule left behind: *a new `src/` marker goes into a §9 first
cell in the same change.*

**Full non-zero delta set, `w741b` vs `w740`, so nothing is cherry-picked:** `CAS-SITE`/`WAKE[KWFSO]`/
`WAIT`/`WAKE` **+248 each** (KWFSO poller — FOOD-NOT-PROGRESS class, a timing artifact, never evidence),
`NFS-CENSUS` +4, `F441-QUEUE-STORE` +1, **`PHYS-STATE` +1**, **`F635-CTR-OOR` −1**,
**`XTL-ALLOC-REFUSED` −4**. `DEPTH 1.02x -> COMPARABLE`, **no `POISONED` verdict**. `DRAW_INDEXED` 0 = 0,
`PRESENT` own-rows 49 = 49, `C0000005` 5 = 5, `NATIVE-PRESENT` 2 = 2. **Own-rows ≠ matching lines and
both are right for their own question:** `PRESENT` 49 vs 254/255, `C0000005` 5 vs 7, `F631-HEAPWIN` 32 vs
64 (the tool names the owner of the difference as `f374-heapstore:32` — the `F631-HEAPWIN` literal also
appears inside `F374-HEAPSTORE` rows).

**Still not committed; still no menu; `DRAW_INDEXED` still 0.** Next free ledger ID **F-781**. `mcla.exe`
killed and `tasklist` verified clean; newest `build/*.log` is `w741b.log` at 22:05.

---

## 9. 2026-10-07 00:1x — SUPERSEDING §8.10's "Next free ledger ID: F-781" and §8.7's "what is still NOT landed". Three findings landed tonight: **F-781** (T43.1 done + proven), **F-782** (the reason T43.1 was not enough), **F-783** (F-782's fix, verified). Ledger top is now **F-783**, 635 headings ⇒ **next free ID is F-784**.

**The one-sentence state: the boot is unchanged — still no menu, `DRAW_INDEXED` still 0, two presents ever — but the instrument that was supposed to explain the allocator's refusals has been blind since it was written, and it now sees. What it sees is a contradiction, not an exhaustion.**

### 9.1 T43.1 is DONE and PROVEN, but the proof is a forced gate, not a soak (F-781)

`EmitPhysState` / `NotePhysVerdict` / `NotePhysPoolFull` now run **inside** the o1heap invariant-gate arm,
ahead of its `return nullptr`, with `o1Amount` and `NotePhysAttempt()` hoisted above the gate. **Post-F-779
the gate is dormant** (`invariants FAIL` = 0 rows in `w741`, `w741b`, `w742`, `w743`), so a normal run of the
fixed tree **cannot reach the path at all** — a soak would have proven nothing. `MCLA_T43_FORCE_INV_GATE=1`
(env, default off, `kT43ForceInvGate` in `Heap::AllocPhysical`) forces it. **Control: `build/w742ctl.log:210-215`
and `:298-300`** — `invariants FAIL #1 … cap=536870912` → `PHYS-STATE #1` → `PHYS-VERDICT-CHANGE none ->
healthy … refusals=1 req_amt=0x2e84020` → `PHYS-POOL-FULL #1 … attempts=1 served=0 refused=1 …
class_present=1`. **Nonzero `req_amt` is what proves it is the alloc path** (the free path prints `0x0`).

🔴 **READ `cap=` BEFORE CITATING `w742ctl`.** The control's `invariants FAIL` row says `cap=536870912`
(= `0x20000000`, a *healthy* capacity); a real failure says `cap=0`. **The control proves reachability and
emission only** — it says nothing about `ClassifyPhysPool`'s `capacity_zero` arm, and citing it for that is a
category error. **The injector stays in the tree on purpose** (F-781 §7): deleting it would make this path
unfalsifiable again for exactly as long as F-779's fix holds. It is registered in `PROGRAM_GUIDE` §7 as
**NOT A SHORT-CIRCUIT — AN INVERTED-DIRECTION FAULT INJECTOR**; `tools/mitigation_audit.py` cannot see it
(its `LABEL` regex wants all-caps or hyphenated all-caps; `kT43ForceInvGate` is neither), so that paragraph
is its only registration.

### 9.2 T43.1 was NOT ENOUGH, and the reason was ours, not the guest's (F-782 → fixed → F-783)

`EmitPhysState` calls `NotePhysLive` **unconditionally**, and that sweep did
`std::memcpy(chunk, base + pos, n)` from `pos = 0`. **`base` is `0x100000000` and guest VA 0 is the
deliberate `PAGE_NOACCESS` null guard** — so it faulted on its **first 1 MiB chunk, every boot,
deterministically**, *between* `PHYS-STATE` and the verdict/pool-full rows. **One of the five `C0000005`s in
every boot was ours, and every census ever taken charged it to the guest.** It also meant **`PHYS-LIVE`
printed 0 rows in 0 of 313 logs** and `PHYS-POOL-FULL` 0 rows in 312 of 313.

**Fixed:** `kNullGuardBytes` (`src/kernel/memory.h`, replacing **eight** bare `4096` literals across
`memory.cpp` so "who must respect the guard" is greppable — the structural reason F-122 *and* F-782 both
happened) and `kPhysLiveStart` at all three cursor-zeroing sites in `heap.cpp`.

**Verified in `build/w743.log`** (31,280 lines / 5,159,095 B, 300 s, `23:39:15`→`23:44:15`, **TIMEOUT =
survived**; `DEPTH 1.01x COMPARABLE` vs `w742.log`, **no POISONED**):

| | w742 | w743 | |
|---|---|---|---|
| `PHYS-LIVE` | **0** | **4** | ✅ first rows in the instrument's life (`:30956/30962/30968/30974`) |
| `PHYS-POOL-FULL` | **0** | **4** | ✅ first on a *natural* exhaustion (`cap_o1=0x20000000`, not the injector's `536870912`) |
| `PHYS-STATE` | 1 | **4** | ✅ one per refusal instead of one-then-fault |
| **`host addr 0x100000000`** | **1** | **0** | ✅ **THE discriminator. Our fault is gone.** |
| `code=0xC0000005` | **5** | **5** | ⚠️ **conserved — see 9.3** |
| `XTL-ALLOC-REFUSED` | 0 | **4** | ✅ **unmasked, not new — see 9.3** |
| `invariants FAIL` / `PHYS-LARGE` | 0 / 63 | 0 / 63 | ✅ no regression; `PHYS-LARGE` held ⇒ the sweep ran in both |
| `headIs=1` / `dstAfter=61786772` / `o1_cap_delta=0x240` | 1 / 1 / 1 | 1 / 1 / 1 | ✅ F-766 + F-779 gates held |
| `DRAW_INDEXED` / `FATAL-SOFT` / `Fatal error` / `80000003` | 0 / 0 / 0 / 0 | 0 / 0 / 0 / 0 | ✅ **no menu, no draw, as before** |

Rule 1a: three files, and the `memory.cpp` change is a **provably value-identical literal→constant
substitution**, so the only behavioural variable is `kPhysLiveStart`. Rule 1b: the two new symbols are named
above. `w743_err.log` is byte-identical to `w742_err.log` (101 B).

### 9.3 THREE WAYS THIS SESSION ALMOST WROTE A FALSE CLAIM — read these before you read a delta

**(a) F-782 §9's own acceptance gate was the wrong metric, and it is withdrawn.** It predicted
`C0000005` **5 → 4** and said a count that did not drop refuted the entry. **Measured 5 = 5.** The count is
conserved by **SUBSTITUTION**: `VEH[3] (capped)` caps at three rows, our fault stopped, and the guest's own
fault arrives **1 ms later** and takes the freed slot. **A total that counts events from two producers cannot
be the acceptance test for removing one of them — and a capped printer makes the substitution invisible in
the total.** Gate on the field that identifies the producer.

**(b) `XTL-ALLOC-REFUSED` 0 → 4 is unmasking, not a regression.** Proved two ways. *The row the fault cut
short:* `w742.log:30798` and `w743.log:30954` are the **same row field for field** (`size=0x19d align=0x4000
o1_amount=0x41bd live=0x1dd08000 cap=0x20000000 peak=0x1dd08000 oom=1 caller_rva=0x2b5b5a glr=82137904`),
differing only in timestamp — in `w742` the thread faulted two lines later, before `__xtl_alloc`'s own
`if (ctx.r3.u32 == 0)` could run. *The success path as an independent control:* `XTL-ALLOC` has **14 rows in
both logs**, and its last row is `#3072 size=996 align=16 glr=8218A1D4 seen=3072 refused=0` in **both**,
only the returned pointer differing (`BDF8C000` vs `BDF90000`). **The guest's allocation behaviour did not
change; only our reporting of it did.** ⚠️ An earlier draft claimed "the same 3,195 requests in both runs" —
**unsupported and withdrawn**: the two runs are not at the same total (`seen=3195..3198` on the refusal rows
is a later instant than `#3072`). The identity that carries the argument is the `#3072` row and the 14-row
count, not a total.

**(c) `max_refused=0x0` and `buckets=[le64K=0 … gt32M=0]` on the new rows are CORRECT, not dead fields.**
`NotePhysPoolFull`'s switch puts the histogram and `PhysPoolBumpMax` **only in the `Exhausted` arm**; these
refusals classify `Healthy`, whose own comment says *"deliberately NOT bucketed"*. **That is F-643's arm
working exactly as written — do not "fix" it.** `over_cap=0` and `granfit_missed=0` are likewise correct by
arithmetic (`req.frag 0x8000 > capacity 0x20000000` is false; `free 0x22f8000 < req.frag 0x8000` is false).
**Rule 19's corollary cuts both ways: before calling a zero an artifact, read the gate that produces it.**

### 9.4 THE FRONTIER MOVED — the freed fault slot belongs to the handoff's own named wall

The exception our sweep had been masking is **not** anonymous. `build/w743.log:30978-30984`, four rows, all
`[23:41:35.946]`, all `tid=8284`:

```
GUESTVIEW-U32-FABZERO  #6 va=00000000 size=4 why=range … caller_rva=0x64feaf
GUESTVIEW-U32-REFUSED  #6 va=00000000 … lo_va=00000000 hi_va=00000100 by_why=[range=6 nullout=0 av=0]
GUESTVIEW-U32-FABZERO  #7 va=00000008 size=4 why=range … caller_rva=0x64fed2
GUESTVIEW-U32-REFUSED  #7 va=00000008 … lo_va=00000000 hi_va=00000100 by_why=[range=7 nullout=0 av=0]
F635-CTR-OOR           #3 ctr=00000000 slot_off=0xFFFFFFFEFBDA0000 slot_guest_va=0xFFFFFFFF7E780000
                          load_addr=0x7E780000 base=0x100000000 lr=8218B458 caller_rva=0x64ff06
VEH[3] (capped) code=0xC0000005 → VEH-NEUTRAL … lr=8218B458 read of host addr 0x7e780000
```

Resolved against `build/mcla.map` from the **same** build (`.exe` and `.map` both `23:38:52`; base
`7ff67c9d0000` from `w743.log:186`'s own printed field): `0x64feaf` → **`__imp__sub_8218B0C8 +0xcef`**,
`0x64fed2` → **`+0xd12`**, `0x64ff06` → **`+0xd46`**, faulting `hostRip` `0x7ff67d01ff1f` → **`+0xd5f`**.
**All four host addresses are inside the ONE recompiled body of `sub_8218B0C8`, within 0x70 bytes of each
other**, and guest `lr=8218B458` = `sub_8218B0C8 + 0x390`. **§2's wall — "why is `ctx.r3` unreadable at
`sub_8218B0C8`?" — is now visible with its own instrumentation attached.** The mechanism the rows spell out:
the body reads guest VA `0` and `8` through the *checked* helper (which fabricates zero and logs
`why=range`, `va is BELOW the 0x1000 guard-page floor`); `ctr` is `00000000`; `slot_off` is a sign-extended
garbage value; the resulting `load_addr=0x7E780000` (= guest VA 0 per `mcla-guest-raw-decode`'s
`Param[1]==0x7E780000` gloss) is then read **unchecked** and faults. **Two reads of the same null, one
guarded and one not, 0x19 bytes apart in the host body.** That asymmetry — not the null itself — is what
makes it an access violation rather than a `FABZERO`. **`F635-CTR-OOR` 4 → 5 is this event, and it is the
guest's, not ours.**

### 9.5 T43.2 IS UNBLOCKED, AND IT IS A CONTRADICTION, NOT AN EXHAUSTION

F-782 §11 called this "two named arms, not a finding" because discriminating it needed the refusal path to
survive past `EmitPhysState`. **It survives now, and all four rows say the same thing.** From
`w743.log:30955`, computed rather than eyeballed:

- `free = 0x22f8000` = 36,667,392 B = **34.97 MiB** = **1,119× the 32 KiB (`o1_frag=0x8000`) the request needs**.
- `bin_mask = 0x801c0` = bits **{6, 7, 8, 19}**; `opt_bin = 9` is **NOT** in it; `suitable = 0x80000 = 2^19`,
  so the classifier's plan is *take a bin-19 (512 KiB) fragment and split it down four halvings to bin 9*.
- **Every one of the model's own tests passes** — `class_ok=1`, `page_fits=1`, `pow2_fits=1`, `split=exact`,
  `full=0`, `over_cap=0`, `over_frag=0`, `destroyed=0` — **and `o1heapAllocate` returned null.**

So either `O1BinMask` misreads o1heap's internal bin state (bin 19 reported non-empty but not usable), or
o1heap's split path has a guard the classifier does not model. **Entry point, named from the row:**
`caller_rva=0x2eb768` → **`MmAllocatePhysicalMemoryEx +0x38`**, guest `glr=821325D4` inside `sub_82132578`.
**The third physical allocation of the boot** (`alloc_seq=3`) asked for `size=0x12b80000` = **314 MiB**, got
`block_guest=0xA3A8C000`, and per the row **was never freed** (`freed=0`, `big_freed=0`) — while the host's
own live-pointer registry holds **`reg_hit=0` of `reg_total=3236`** entries inside it. **`freed=0` and
`reg_hit=0` are in direct tension**, and unlike `guest_refs` the registry count is host-side and not subject
to 9.6's aim defect. **First question: who still holds `0xA3A8C000`?**

**Third arm, and it is a modelling defect, not an ordering one:** `PHYS-VERDICT-CHANGE` stayed at **1 row**
across all four refusals (`w743.log:802`, `[23:39:18.072]`, `none -> healthy … refusals=0 req_amt=0x0`,
`caller_rva=0x2d1793` = **`DestroyKernelObject +0x133`**, i.e. the *free* path, 2 m 17 s earlier). **The
classifier does not consider four consecutive refusals a state change.** So T43.1's reordering, though proven
on the gate path, still does not make the verdict row *informative* here — read `PHYS-STATE` /
`PHYS-POOL-FULL` themselves, not the verdict edge.

Also noted, **not interpreted**: `BE710-DEAD #138…#141` fires once per refusal with
`outcome=REFUSE-NO-BODY` and `r4` = `A042C600`, `3CDB24AF`, `3CDB24BB`, `3CDB24C7` — the first inside the
physical arena, the latter three advancing by exactly **+12**, i.e. a caller walking 12-byte records and
getting a null body for each.

### 9.6 NEW TASK T43.1c — the instrument now perturbs what it measures. Do not skip this before T43.2.

**(a) COST.** Each `PHYS-LIVE` emission `std::memcpy`s `kPhysLiveBudget` = **256 MiB** while
`Heap::AllocPhysical` holds `std::lock_guard lock(physicalMutex)` — **the source already says so** in the
comment above `sweep_ppm`'s own definition. Measured in `w743.log:30954-30976`: refusals at
`.779 → .821 → .861 → .903 → .945`, and **the guest's next call lands in the SAME millisecond as the
preceding refusal's last row**, so the 40-42 ms gap is entirely our sweep (≈6.2 GB/s) — **~166 ms of
injected latency across four refusals, with the guest blocked on the mutex.** My own T43.1 comment predicted
this cost and **was unverified when written, because the sweep had never actually run.**

**(b) AIM.** The sweep walks linearly from `kPhysLiveStart`, so its first 1 GiB covers guest VA
`[0x1000, 0x40001000)` — **neither the guest image (`0x82000000+`) nor the physical arena** — while the
block under test (`block_guest=A3A8C000`) is at **2.557 GiB = 63.9% = emission #11 of 16**. `sweep_ppm`
reached only **250000 = 25%** with `complete=0 pass=0`. **So `guest_refs=0` is a statement about the sweep's
aim, not about the block's liveness** — rule 19: an instrument whose positive result is unreachable in the
run being read has not reported a negative.

**Both were deliberately left unfixed in the F-782 pass**: changing either would have made `w743` differ
from `w742` by **two** variables and destroyed the rule-1a attribution that makes 9.2 mean anything. F-783
§7-§8 are the recorded refutation that authorises T43.1c. **Do both in ONE log-only change and re-time the
refusal window — a `PHYS-LIVE` row count is also a latency count.**

### 9.7 Doc state after this session (so the next agent does not re-derive it)

- `PROGRAM_GUIDE` **§9 has a `PHYS-LIVE` row** (it had **0 mentions in any doc** before — the F-780 §9
  defect class recurring within one day). **Verification is the tool re-run on the SAME two logs:
  `257 tracked` → `258 tracked` (+1 exactly) and a new `PHYS-LIVE 4 0 +4 <<` row** — that is the positive
  control proving the registration works, per rule 19. The §9 `PHYS-STATE` row also carries a dated
  **SUPERSEDED 2026-10-07 by F-783** block closing its exhaustion-path blindness and withdrawing the
  `C0000005` 5→4 gate.
- `LONG_TODO_MASTER` §6: **T43.1 ✅ DONE AND PROVEN (F-781)**, **T43.1b ✅ DONE AND VERIFIED (F-783)** with
  its wrong gate marked withdrawn in the cell, **T43.1c** inserted (11 rows now, T43.1…T43.9), **T43.2
  unblocked** and rewritten around the measured contradiction and the `MmAllocatePhysicalMemoryEx +0x38`
  entry point.
- 🔴 **`src/kernel/heap.cpp` line numbers have rotated a FOURTH time** (F-782's fix added `kPhysLiveStart`
  and its comment). **Cite symbols, not line numbers.** The current true set, re-measured after the fix:
  `NotePhysLive` decl `:934` / def `:1644`, `EmitPhysState` `:936` with the unconditional call at `:941`,
  the lock-hold comment `:994-995`, `PHYS-VERDICT-CHANGE` printer `:1046`, `NotePhysPoolFull` `:1427` with
  its switch `:1465-1504` (bucket + `PhysPoolBumpMax` **only** in the `Exhausted` arm `:1467-1481`;
  `Healthy` arm `:1495-1497`, "deliberately NOT bucketed" `:1493-1494`), `PHYS-POOL-FULL` printer `:1525`,
  `kPhysLiveStart` `:1637`, the sweep's `std::memcpy` `:1700`, `PHYS-LIVE` printer `:1757`,
  `std::lock_guard lock(physicalMutex)` `:2979`, `kT43ForceInvGate` `:3139` + gate `:3143` + FAIL printer
  `:3150`, gate-path `EmitPhysState` `:3193` / `NotePhysPoolFull` `:3195`, `returned null` printer `:3317`,
  exhaustion-path `EmitPhysState` `:3330` / `NotePhysPoolFull` `:3340`.
- `.qoder/skills/mcla-boot-cycle/SKILL.md` step 2 corrected: **`build_on_e.bat` redirects ninja itself**
  (`:11` → `build_ninja.log`, `:8` → `build_cfg.log`), so the outer `> build/<wave>_build.log` writes
  **0 bytes** — measured twice (`build/w742_build.log`, `build/w743_build.log`, both 0 B, while
  `build_ninja.log` at the **repo root** held 37,566 B). **Read `build_ninja.log`, and note that 137
  warnings are normal/pre-existing.**

### 9.8 Session bookkeeping

**Nothing is committed.** Working tree carries `AGENTS.md`, four `docs/*.md`,
`.qoder/skills/mcla-boot-cycle/SKILL.md`, `src/gpu_cp.cpp`, `src/gpu_device.cpp`, `src/guest_memory.cpp`,
`src/kernel/heap.cpp`, `src/kernel/memory.cpp`, `src/kernel/memory.h`, `src/kernel/o1heap.c`,
`src/kernel/o1heap.h`, `tools/ppc_disasm.py`, `tools/ppc_xrefs.py`. **`git add -A` is unsafe here — stage
named paths only.** `mcla.exe` killed after the soak and `tasklist` verified clean. Newest `build/*.log` is
`w743.log` at 23:44. **Two 0-byte `build/w74*_build.log` files are the `build_on_e.bat` defect in 9.7, not
failed builds** — do not read them as evidence of anything. Root junk still awaiting a decision:
`reverted.cpp` (50,802 B), `902125b9…harness_body.bin`, 12 `A_gs_bound.*`/`B_no_gs.*` artifacts,
`docs/archive/trail-handoff-2026-10.md.tmp` (492,785 B), `build/xr_821BE250.txt`.

**Next free ledger ID: F-784.** Queue order for the next session: **T43.1c → T43.2** (both now have named
entry points and recorded refutations), then T43.3 (needs more than one log — the `B6FB2F29` / `P5-*` event
is run-nondeterministic: 1 row in `w741b`, **0 in both `w742` and `w743`**), T43.8 (`lr=821BE3BC`, 1,164
lines, the hottest unexamined path), T43.4–T43.6.


## 10. 2026-10-07 07:5x — SUPERSEDING §9.8's "Next free ledger ID: F-784". **F-784 LANDED.** Ledger top = `### F-784`, 636 headings ⇒ **next free ID is F-785**. It names the writer, and the writer is guest code.

**One-sentence state: boot is still unchanged (no menu, `DRAW_INDEXED` = 0, w748 == w747 on every gate marker), but the T44 frontier question — *who zeroes the two o1heap free-fragment cards that cause every physical-alloc refusal* — is ANSWERED on rows: the guest's own memcpy (`sub_823DA950`, store PCs inside `__imp__sub_823DA950 +0x2df..+0x3f3`, extent-checked against this build's map) called from `sub_821BE250+0x16c` (`lr=821BE3BC`), with `pre`-snapshots at the store instant that decode — under `FragmentHeader`'s own layout (`o1heap.c:138-153`) — to `next/prev/size/next_free` values whose sizes are exactly `0x4000` and `0x22D6000`, i.e. exactly bins 8 and 19 by the allocator's own formula (`o1heap.c:236`, divisor 64), which is exactly where `PHYS-BINPROBE` (`w748.log:32075`) says those cards live. The cards were live linked free fragments when destroyed.**

### 10.1 What F-784 establishes (all citations re-read from `build/w748.log` this session)

- **Writer:** six `T44-WIPE-STORE kind=prio` wipe rows (`:19013-:19017` = `BDA1F000` 07:20:38.837, `:19359-:19360` = `BE12A000` 07:20:39.062), all `op=U64 val=0 lr=821BE3BC sp=8EFFECD0`, host PCs `0x7ff79667533f/5384/53c9/540e/5453` → rvas `0x170533f..0x5453` = `__imp__sub_823DA950 +0x2df..+0x3f3` (symbol RVA `0x1705060`, extent `0xF30`, all five inside). Guest: `bl 823DA950` at `0x821BE3B8` (`tools/ppc_disasm.py`), so `lr=821BE3BC` = `sub_821BE250+0x16c`. Full 20-frame `F379-HEAPSTORE-BT` resolved in F-784 §6.
- **Linked-before-wipe, budget-immune:** selftest `:64` (`hits=12 expect_hits=12`, cards `hdr=0` at boot = positive control), probe#0 `:225` (`wipes=0`), four refusal-time `T44-TOTALS` (`:32058/:32082/:32106/:32130`) **byte-identical** at `prio_hits=[515,515,515,515] prio_wipes=8 ring_next=2060` ⇒ no card-page store between 07:20:39.067 and the refusal, regardless of the row budget (`gpu_cp.cpp:7580-7581`).
- **Proximate cause:** `BE12A000` (bin 19, size `0x22D6000` ~34.8 MiB) was the only fragment ≥ `o1_amount=0x41bd`; wiped 101 s before refusal #1 (`:32057`, `caller_rva=0x2b958a` = `GuestMemoryHeap::kernel::Alloc+0x1a`). `BDA1F000` (bin 8, 16 KB) could never have served it. Chain: wipe (07:20:38/39) → refusals ×4 (07:22:20.926-.086) → `VEH-NEUTRAL` `lr=8218B458` read `0x7e780000` (`:32159`, F-783/§9.4) → `PARK-MIRROR-STACK STALE` to log end.
- **This RESOLVES the §9.4/§9.5 + LONG_TODO T43.2 contradiction:** `PHYS-STATE suitable=0x80000` reads bin mask/class; the allocator reads fragment sizes; the sizes were destroyed while the bin lists still named the cards (`len=1` but `n_ge=0`, `found_bin=-1`).

### 10.2 w748 is the new phase-3 baseline

Build 10-07 07:17:50 (`build_ninja.log` ends `[2/2] Linking CXX executable mcla.exe`, 12 warnings, 0 errors); soak 300 s, `build/w748.log` 32,455 lines, 07:20:00.852–07:25:00.360. Rule-1a delta vs w745c (00:55:56): **5 files, +990/−80** — `guest_memory.cpp +227` (06:25), `boot_host.cpp +15` (06:26), `gpu_device.cpp +65` (06:43), `kernel/heap.cpp +363` (07:15), `gpu_cp.cpp +400` (07:17). Two stages: w745c→w747 (first three) moved `code=0xC0000005` 3→5 and `Fatal error` 1→0 — **N-way, not attributed**; w747→w748 (last two, instrument-only) changed **no gate marker at all** (full census in F-784 §9). T44 markers new in w748: `T44-TOTALS` ×5 (probes at boot + each refusal); `T44-WIPE-SELFTEST` ×1.

### 10.3 THE NEXT BLOCKER: why is `sub_821BE250`'s dst/len destructive? (two labeled hypotheses, both falsifiable in one run)

- **(a) ONE huge copy.** `F375-HEAPSTORE` `:15767` (07:20:24.138) reads `r3=A03FFFF8 r4=93C63E40 r5=FFFFFFAF` (= 2^32−81, an underflow shape) at the A0400000 instance burst; if that single call kept running, dst covers instance (07:20:24) → bands → cards (07:20:38/39) at ~29 MB/s, which the timestamps fit. **Tension (measured):** it would cross `0xFFFFFFFF` ~07:20:27.6 and write low guest VAs incl. the null guard, yet no VEH/write-trip exists in 07:20:24–07:20:38 (whole-run VEH = 1). Falsifier: a card-time entry row with fresh params.
- **(b) Per-call corrupt len**, `r22` from the stream via `sub_8218B0C8+0x238` (the one call site whose dst is an alloc result — `tools/ppc_xrefs.py calls 0x821BE250`). Falsifier: exactly ONE huge/card-spanning entry in the whole run, at 07:20:24, none at card time.
- **Instrument spec (w749)**, in `src/gpu_device.cpp`'s `PPC_FUNC(sub_823DA950)` hook — log-only, own counters, positive control per rule 19: (1) entry `len >= 0x100000` → print (k≤64, then %4096); (2) card-spanning `dst <= 0xBDA1F000 && (uint64_t)dst+len >= 0xBDA1F008` (and `BE12A000` page) → print (k≤32). Entry regs only — **do not build on store-time `r3/r4/r5`**: F-784 §8 flags an anomaly (F375's 8 rows read byte-identical `r3/r4/r5` while store addresses advance +8, despite the synchronous `WriteU64BE → report` chain).
- **Why existing entry rows can't answer this:** `T44-WIPE-MEMCPY` (75 rows) and `F774-PHYS-MEMCPY` (40 rows) both exhausted their budgets by 07:20:15.34/15.54 with tiny texture copies (`len=0x10`/`len=2`) — both critical entries (07:20:24, any 07:20:38 copy) were counted but not printed. Silence there = budget, not absence. `F382-MEMCPY-LIVE calls=1` (`:203`) bounds total memcpy calls to **< 200,000** for the run.

### 10.4 Still open (carried forward, unattributed)

1. **Instance restoration:** `A0400000` zeroed 07:20:24 (202 stores over instance + ~0x410), yet at 07:22:20 `bins[8]→BDA1F000`, capacity/`suitable` valid (`:32075`). Who restored the metadata, or which copy of it the probe reads?
2. The (a)/(b) length-provenance question above.
3. `PARK-MIRROR-STACK STALE` persists to log end (`:32169`–`:32455`, `sp=8EFFED60 lr=8218B458`) — post-F-783 parking behaviour unchanged.

### 10.5 Tooling (state as of this block)

- **IDA is DEAD on this machine**: `idalib-mcp` fails to start; direct launch `FATAL ERROR: Cannot continue without a valid license`. Do not retry. Use `tools/ppc_disasm.py`, `tools/ppc_xrefs.py`, `tools/addr_owners.py`, `generated/ppc_xenon/*.cpp` (read-only), `build/mcla.map` + `tools/host_rva_resolve.py`.
- Ledger: **next free ID F-785** (636 headings; compute, don't trust — `grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1`, **always `-a`**, the file has a NUL byte).
- Docs changed this block: `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-784` (:18898), this §10 appended; `docs/LONG_TODO_MASTER.md` §6 T43.8 row marked partial-done (writer named; upstream len open).

## 11. 2026-10-08 00:06 — SUPERSEDING §10.3 ("THE NEXT BLOCKER (a)/(b)") and §10's "next free ledger ID F-785". **F-785 LANDED.** Ledger top = `### F-785`, 637 headings ⇒ **next free ID is F-786** (measured, don't trust — `grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1`, always `-a`).

**One-sentence state: boot is still unchanged (no menu), but the T43.10 question — *why is `sub_821BE250`'s dst/len destructive* — is ANSWERED on rows: (a) ONE huge copy CONFIRMED, (b) refuted, and the guest-side mechanism is decoded to the instruction: `sub_8218B0C8` passes `ReadByte`'s −1 (EOF) sentinel UNCHECKED as the length, and `sub_821BE250`'s SIGNED guards read −1 as "fits in buffer" and never clamp → `memcpy(dst, src, 0xFFFFFFFF)` — a 4 GiB−1 walk from a stack buffer through all of guest memory, twice-ish (wrap measured).**

### 11.1 What F-785 establishes (all citations re-read from `build/w749.log` this session)

- **Decision:** exactly ONE `T4310-HUGE-MEMCPY` + ONE `T4310-CARD-MEMCPY`, both `#001` at `23:33:50.480` (`:14978-14979`): `dst=8EFFEFB0 src=82862DF8 len=FFFFFFFF end=8EFFEFAF lr=821BE3BC sp=8EFFECD0 tid=23144`. k=1 on both arms with budgets wide open ⇒ a second destructive entry would print at k=2 — there is none. All card-crossing stores carry that same `lr/sp` (`:21080-21085` BDA1F000 @23:34:17.038, `:21432-21435` BE12A000 @23:34:17.297). (b)'s predicted fresh entry at card time and its `+0x238`/alloc dst both fail.
- **Positive control (rule 19):** `:204` `T4310-ARM-SELFTEST prio=[0,0,-1,1] (expect [>=0,>=0,-1,>=0]) huge=[1,0]` — all six answers correct ⇒ the arms discriminate; silence would have been interpretable, and it wasn't silence anyway.
- **Root cause (raw-word disasm, `tools/ppc_disasm.py`):** `sub_821BE250` = buffered read(ctx,dst,len) with SIGNED guards (`cmpw;ble` at `0x821BE2B0-B4`, clamp at `0x821BE39C-A4`) before `bl 823DA950` at `0x821BE3B8` — **−1 passes both "≤ available" tests, never clamps**. `sub_821BE4F0` = ReadByte: returns the byte or **`li r3,-1`** (`0x821BE514`) when the 1-byte read ≠ 1 (EOF). `sub_8218B0C8` has FOUR sites using that result as the length with no check: `+0x64/+0x98/+0x1f4/+0x238` — the huge call is **`+0x1f4` (`0x8218B2BC`)**: dst `r1+592`, `8EFFED60+0x250=8EFFEFB0` exactly (`sp_memcpy 8EFFECD0 + 144`), corroborated by the final park row `:36173` `sp=8EFFED60 lr=8218B458`. Healthy-ctx control: benign same-site copy 0.7 s earlier `:12337` `dst=BD890000 src=82862DF8 len=800` — same src, only the requested length differed.
- **Wrap / F-784 §10's tension RESOLVED:** `:28872` `F374-HEAPGUARD trip=3 off=0X0 want=W guestLR=821BE3BC` at `23:34:54.423` = 63.94 s × 28.3 MiB/s = `0x71001050` = exactly `0x100000000−0x8EFFEFB0`. The wrap does NOT fault: `WriteU64BE+0xdd` declines the `<4KiB` window (trip, no VEH) and the walk continues — second pass covers `0x0 → 0x8EFFEFAF` (everything except one byte).
- **Cascade (measured):** instance crossed 23:34:00.288 (`:17385+` F375×8, `:17388+` F379×20, HEAPHDR×202) → cards' 6 header-field wipes (raw bytes = w748's F-784 §5 decode: size `0x4000`/`0x22D6000` = bins 8/19) → wrap 23:34:54 → refusals ×4 23:36:12.931-.054 (`:35816+`, `caller_rva=0x2ba57a` = `GuestMemoryHeap::kernel::Alloc+0x1a` — same fn+off as w748's `0x2b958a`, RVA shifted by build) with binprobe `prev=0 next=0 head=0 n_ge=0` at the same `gva=BDA1F000/BE12A000` (`:35834+`) → `VEH-NEUTRAL` 23:36:13.093 (`:35918`, F-783's) → park to log end. Guest-code crossing (~23:36:09) and copy end (~23:36:15) are DERIVED from the measured pace, labelled as such in F-785 §6.
- **Rule-1a census (raw bytes, w749 vs w748):** 15/16 cited markers **+0** (`C0000005 7`, `Fatal error 0`, `VEH-NEUTRAL 1`, `VEH W0 2`, `XTL-ALLOC-REFUSED 4`, `PHYS-POOL-FULL 4`, `HEAPHDR-STORE 202`, `F374-HEAPSTORE 32`, `F774 40`, `F379 20`, `o1heapAllocate null 4`, `T44-TOTALS 5`, `PHYS-BINPROBE 5`, `PHYS-STATE 4`, `PHYS-LIVE 4`). The one delta `F374-HEAPGUARD 4→3` is characterized: w748 had an extra PRE-copy trip (`:707` `off=0X20 guestLR=00000000 tid=11224`, another thread, 70 s before its wrap) that w749 never had; both runs' wrap trips are the same shape. Build delta = `src/gpu_device.cpp` only (ninja rebuilt exactly that TU + linked).

### 11.2 w749 = the answer run

Build 10-07 23:28:46 (`[1/2] gpu_device.cpp.obj [2/2] Linking`, `BUILD_RC=0`); soak 300 s, `build/w749.log` 36,173 lines, `23:33:33.519–23:38:30.858`, killed by harness (normal). The two entry arms + fwd decls live in `src/gpu_device.cpp`'s `PPC_FUNC(sub_823DA950)` hook (selftest at `ka==1`); predicate definitions in `gpu_cp.cpp:7462-7472`.

### 11.3 Still open (supersedes §10.4)

1. **WHY the stream hit EOF at that iteration** — the loop bound (`lwz r11,3(r31)` vs bytes available) is unmeasured; decode the record table or probe at `+0x1f4`. Falsifier: the −1 fires exactly at `count−records`. → **T43.11(1)**.
2. **Instance restoration** (zeroed 23:34:00, yet `bins[8/19]` readable at 23:36:12) — second run's evidence now; mechanism still unknown.
3. **F375's frozen regs — 2-run byte-identical** (`r3=A03FFFF8 r4=93C63E40 r5=FFFFFFAF` in w748 AND w749, ≠ entry `8EFFEFB0/82862DF8/FFFFFFFF`): neither entry nor live. **Recorded, not interpreted — do not build on store-time r3/r4/r5.**
4. Wild AVs (2/run; w749 +1.27 s after entry, +1.17 s after wrap; none before copy start) — suggestive of copy-clobbered threads, NOT proven.
5. `PARK-MIRROR-STACK STALE` to log end (F-783's shape) — unchanged.

### 11.4 Next tasks (queue of record: LONG_TODO §6)

- **T43.11 (new):** (1) EOF provenance probe (§11.3 #1); (2) design + register a log-only host-side guard rejecting an impossible `len` at the `sub_8218B0C8`/`sub_821BE250` boundary — `tools/addr_owners.py --check` before any hook, PROGRAM_GUIDE §7 registry, no stacked short-circuits (do-not #1/#9). The guest binary stays untouched (data).
- Boot work continues unchanged; the refusal chain now has a fully measured end-to-end mechanism (EOF → 4 GiB copy → header destruction → refusal) but no mitigation yet.

### 11.5 Record notes

- **IDA is still DEAD** (§10.5 unchanged) — `ppc_disasm.py`, `ppc_xrefs.py`, `addr_owners.py`, `host_rva_resolve.py` + fresh `build/mcla.map` (control passed: `WriteU64BE+0xdd`, `HeapInstanceStoreReport+0x628` reproduce w748's exact offsets).
- **F-785 §8 — two instrument bugs, do not re-import:** a filter matching `addr=` against rows printed as `@ ADDR` reported **0 nonzero-pre wipes in w749 — false** (an instrument that never fires looks like a result); a first-8 display cap hid the prio rows. Corrected: prio nonzero = 6, zero = 514 (= w748's structure).
- Docs changed this block: `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-785`; this §11 appended; `docs/LONG_TODO_MASTER.md` T43.10 → ✅ ANSWERED, **T43.11** added.

## 12. 2026-10-08 08:12 — SUPERSEDING §11.3 #1 ("WHY the stream hit EOF at that iteration") and §11.4's T43.11 line. **F-786 LANDED.** Ledger top = `### F-786`, 638 headings ⇒ **next free ID is F-787** (measured, don't trust — `grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1`, always `grep -a`: the file holds 1 NUL byte).

**One-sentence state: boot is still unchanged (no menu), but T43.11 is ANSWERED end-to-end: (1) `ReadByte` −1 = the `CityDefault.fxc` invocation header at member coord 0x5000 was parsed from RAW archive bytes (the tail beyond pos 20480 is never overwritten with the proved body — 5 delivered windows, none at 20480), so a garbage `count=170` ran the record walk out of bytes at iteration 24, never at 170; (2) the registered LOG-ONLY guard `T4311-LEN-GUARD` is landed, built, and verified in `build/w750.log` — it fired 4× on `count=FFFFFFFF` with `lr=8218B2C0` (the return address of `bl 821BE250` @8218B2BC, pinning the record-loop caller directly), its selftest printed `fire=[1,1,0,0] (expect [1,1,0,0])`, and the census gate is **16/16 cited markers +0** with the function's normal-path printers byte-identical. Nothing committed.**

### 12.1 What F-786 establishes (all citations from `build/w750.log` + raw files this session)

- **Provenance chain (RULE 0: measured, not reasoned):** `inflate(rpf[0x1F5000:0x1F6D9A], 7578 B) == ap_oracle_body.bin` byte-identical (23,807 B); correct header at apo[0x5014] = `05 00 08 "ambYPos " … count=0`. `STREAM-WINDOW` w750:13564 `winAbs=0x2000 winHex=0000000001080000` == apo[0x2000] (mid-file body served correctly), but w750:13609 `winAbs=0x5000 winHex=C2342C2A95ABAA0A` == `rpf[0x1FA000]` = member base + 0x5000 = **12,902 B past the member's stored end (0x1F6D9A)** — unrelated archive content. `ARC-WINDOW` (unconditional printer, gpu_device.cpp:20176-20191): exactly 5 CityDefault rows in both runs (#58-62, pos 0..16384), **no pos=20480 row** → tail never overwritten (zero valid: 5-row positive control).
- **The walk:** raw header `b0=0xC2 b1=0x34 l1=44 l2=74 count@0x507A=0xAA=170`; 23 records reach value stage, **22/22 value dwords == BESWAP `dstAfter` rows** (vpos 0x508F..0x5C79); rec23 `P=0x5C7D nl=254 nameAvail=129` → EOF → rec24 `nameLen ReadByte` → −1. **Falsifier satisfied: crash at record 24, never at 170 — bytes, not the count field, ended the loop.**
- **Boundary at 20480 exact:** bytes ≤0x4FFF all apo-served (siColor2 `count@0x4FDA`+trailing@0x4FDB; tireMotionBlur `l1=l2=15`, `count@0x4FFE`+trailing@0x4FFF; `sub_8218B0C8` reads one unconditional trailing byte `8218B328-8218B33C stb r31+2`) → our b0 @0x5000 = winHex. Alternative "count@0x4FFF" parse **REFUTED** (its trailing byte would put b0 at 0x5001 ≠ winHex).
- **Crash chain, field-identical across runs:** w750:13625 `BESWAP-RET #88` → :13626 `WINWR-REC #50` → :13627 **guard #1** → :13628 `T4310-HUGE #001 dst=8EFFEFB0 src=82862DF8 len=FFFFFFFF end=8EFFEFAF lr=821BE3BC sp=8EFFECD0 tid=22064` = w749:14978 byte-for-byte; PARK-MIRROR `f1=8218B2B0 lr=821BE3BC` w750:13707.
- **Guard (log-only):** `src/gpu_device.cpp:25930-25938`, top of `PPC_FUNC(sub_821BE250)` after `count = ctx.r5.u32`; fires iff `count >= 0x10000000u`, budget `k<=16 || k%4096==0`; threshold >400× the largest observed legit count (262,144). `addr_owners --check 0x821BE250` = 2 sites, exit 0. Selftest w750:1898 passes `[1,1,0,0]`. Guards: :13627/:31131/:31156/:31181, all `count=FFFFFFFF lr=8218B2C0`. Event #1 → T4310-HUGE (copy still ran — log-only by design); events #2-#4 → `AllocPhysical: o1heapAllocate returned null #N` (:31132/:31157/:31182), no second huge copy (T4310 k=1 = w749).
- **Registration/audits:** §9 row + §7 paragraph landed in the same change; `markers_from_guide` both tokens tracked=True (234 total); `mitigation_audit` registered 106→118, UNDOCUMENTED 88 (was 89 — `BESWAP-RET` documented as side effect), STALE 6 unchanged (pre-existing exit 1).

### 12.2 w750 = the guard run

Build 10-08 07:46:46 (`gpu_device.obj 07:46:45`, `[2/2] Linking`, `BUILD_RC=0`); soak 300 s via `soak_t44.py w750.log 300` (rc=TIMEOUT/harness-killed, normal), `build/w750.log` 31,523 lines / 5,227,688 B (w749: 36,173 — depth 1.15×, census verdict COMPARABLE). Census `tools/soak_census.py build/w750.log build/w749.log` exit 0: **16/16 cited F-785 §7 markers +0** (12 from the table incl. `C0000005 5/5`, `XTL-ALLOC-REFUSED 4/4`, `HEAPHDR-STORE 202/202`, `F374-HEAPSTORE 32/32`; 4 by direct count incl. `F374-HEAPGUARD 3/3`, `o1heapAllocate returned null 4/4`); function-path printers identical `BE250-GUEST 5, BE250-OBJ 5, BESWAP-RET 88, BE710-DEAD 4, F396-ALLOC-EXIT 65, WINWR-REC 7, BE250-SLOT 25`; new markers `T4311-LEN-GUARD +4`, `T4311-LEN-SELFTEST +1`; the other 21 non-zero deltas are throughput/cadence only, none cited. Rule 1a: build delta vs the w749 build = `src/gpu_device.cpp` + `docs/PROGRAM_GUIDE.md` only; rule 1b new static: `s_4311g`.

### 12.3 Still open (supersedes §11.3; item 1 is now ANSWERED)

1. ~~WHY the stream hit EOF~~ → **F-786, answered** (raw-served tail window; bytes ran out at record 24).
2. **NEW, named by F-786 §7: WHY the tail fill bypassed span/ARC-WINDOW delivery** — `kListMemberSpans` registers [0x1F5000, 0x1F6D9A) yet the window at 0x1FA000 was raw-filled and no `ARC-WINDOW` pos=20480 row exists; no `READAT-BRANCH` row with off=001FA000 appears. The fill path is UNNAMED — this is the fix work; **now registered as `T43.12`** (LONG_TODO §6 queue row, added this block).
3. **Instance restoration** (§11.3 #2) — unchanged.
4. **F375's frozen regs — 2-run byte-identical** (§11.3 #3, now 3 runs incl. w750) — recorded, not interpreted.
5. Wild AVs (§11.3 #4) and `PARK-MIRROR-STACK STALE` (§11.3 #5) — unchanged.
6. The guard **rejects nothing** (log-only by task §1629); rejection is a separate task needing guest-observed semantics. `T4310-*` markers still absent from §9 (`tracked=False`, pre-existing).

### 12.4 Next tasks (queue of record: LONG_TODO §2)

- **T43.11 — ✓ ANSWERED both parts** (this block; LONG_TODO row updated).
- **T43.12** (F-786 §7 #1): name the tail-fill branch that wrote raw bytes at pos≥20480 (log-only probe first; do-not #1 — no fix without the named branch), or resume the boot path (menu is still absent).

### 12.5 Record notes

- **IDA is still DEAD** (§10.5 unchanged) — `ppc_disasm.py`, `ppc_xrefs.py`, `addr_owners.py`, `host_rva_resolve.py` + `build/mcla.map` were the working set.
- **PowerShell `>` writes UTF-16** — bit a census redirect this session (`census750.txt` parsed as UTF-8 = garbage); use `encoding='utf-16'` or python-redirected stdout.
- Docs changed this block: `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-786`; this §12 appended; `docs/PROGRAM_GUIDE.md` §7 paragraph + §9 row (landed pre-soak); `docs/LONG_TODO_MASTER.md` T43.11 → ✓ ANSWERED. Nothing committed.

## 13. 2026-10-08 11:1x — SUPERSEDING §12.3 item 2 ("the fill path is UNNAMED — now registered as T43.12"). **T43.12 ANSWERED (F-787).** Ledger top = `### F-787`, **639** headings ⇒ next free ID **F-788** (measured, don't trust: `grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1`, always `-a` — the file's 1 NUL byte makes plain grep report 74 of 639 headings).

### 13.1 What T43.12 establishes (all citations re-read from the logs this session)

1. **There is NO bypass — the working hypothesis is REFUTED.** The tail read enters `sub_821CC1E0` like every granule: `T4312-UNDELIVERED #24 gate=0 ret=3327 req=4096 retEq=0 rec=B79150A0 win=82862DF8 pos=20480 w1=00005CFF bodySize=23807 posIn=1 want=0 done=0` at `build/w751.log:13748` = `build/w752.log:13764`, identical modulo tid/time.
2. **The named branch = the deliver gate's `origRet == amIn6` clause (`src/gpu_device.cpp:20174`).** The original body returned **3327 = 23807 − 20480** (the member's logical-size clamp) for `req=4096`, and that is the only clause that fails — `rec` valid, `req≠0`, `win` a window base, and the deliver would have computed `posIn=1 want=3327`. The five earlier granules delivered **only** because each returned exactly 4096 (`w752:13670/:13695/:13721/:13732/:13735`, `req=want=done=4096`). The clause is by design (banner `:20144-20145`: a short read is "left exactly as the guest's own code produced it") — the seam is where that design meets a raw-past-stored-end original.
3. **Filler = the original body of that same call.** Full-row elimination in w750: between `ARC-WINDOW #62` (`:13573`, last corrected granule) and `STREAM-WINDOW #1000` (`:13609`, `end=3327`, window already raw) only guest-stack (`8EFFED00/8EFFED50`) and phys-arena (`A0438xxx/A042Cxxx`) writes exist — **nothing touches `82862DF8`**; w751/w752 put the probe row exactly in that gap (`w752:13758` → `:13764` → `:13772`). Source = raw `rpf[member_base+stream_pos]`, byte-identical at two positions: `WINWR-WATCH #42` (`w750:13568`, `src8=8588FC19B565A9BC == rpf[0x1F8000:8]` = stream 0x3000, granule-relative `off=0`, then overwritten by `ARC-WINDOW #61 :13570` `pos=12288`) and the tail (`STREAM-WINDOW w750:13609 winHex=C2342C2A95ABAA0A == rpf[0x1FA000:8]`, re-verified byte-for-byte this session). Guest addressing `abs = archive_offset + pos` is its own (`recomp.17.cpp:3220/3238/3239`, raw words at `gpu_device.cpp:19956-19971`).
4. **Census closure:** 28 probe rows + 22 window-base `ARC-WINDOW` rows = **50 = `WINWR-REC`'s printed `tot=50`**; probe budget not reached (28 ≤ 96), so the census is complete; both runs reproduce it.
5. **Premise corrected (F-786 §7 item 1 / this file's §12.3 item 2 / LONG_TODO `:1630` all said it):** `kListMemberSpans` (`src/gpu_device.cpp:2635-2642`) holds exactly six `.list` entries — **no `CityDefault.fxc`** — and `0x1F6D9A` is the member's *stored* end, not a registered span. CityDefault's span is dynamic (`g_expSpans` via `MarkMemberExpandedIn`, `vfs_rpf.cpp:2204-2235`) with the **logical** length 23807 ⇒ `[0x1F5000, 0x1FACCF)`, which **does** cover `0x1FA000`. "Outside the registered range" was a mis-framing; what let the raw bytes stand is the deliver's refusal (item 2), not a bypass of registration.

### 13.2 Residual → T43.13 (new queue row, LONG_TODO §6)

- **UNNAMED: the host function that physically read `rpf[0x1FA000]`.** w752's complete `READAT-BRANCH` histogram has **0 rows** at `off=001F8000/001F9000/001FA000`, and the zero is legitimate (rule 19 — positive control *at this member*): the 6 `off=001F5000` rows print at #957+/`call≥961` (`w752:13606+`), far past `kReadAtFirstN=16`/`kReadAtEveryN=4096` (`vfs_rpf.cpp:2561-2562`, drop condition `:2716`), which can only be the in-span exemption firing; the span covering the tail is `[0x1F5000,0x1FACCF)` (`MarkMemberExpandedIn :2204-2235` + `WindowInsideRegisteredSpan :2615-2624`, entry `resolved`/`!failed` per the `MEMBER-EXPAND-OVERRUN` success path `:1175-1195`, row `w752:13603`).
- ⇒ the granule fill never reached `RpfVirtualFileSystem::ReadFileAt`. Registered as **T43.13**: log-only probe at that layer, required before any fix of the tail fill (do-not #1).

### 13.3 Gates / state (this block)

- **Build:** `[2/2]` = `gpu_device.cpp.obj` + link only vs the w750 build (rule 1a); `s_4312` is the change's only new static (rule 1b, checked); `mcla.exe` killed after every run; guest binary untouched.
- **Soaks:** `w751` 120 s (28 rows), `w752` 300 s = w750's own length (28 rows, tail row identical) — new log per experiment (rule 5). `soak_census w752 vs w750` exit 0: **12** nonzero deltas, all ≤ +213 on flood counters; control `w750 vs w749` (no source change) = **29** deltas, ±1,107; `T4311-LEN-GUARD` 4=4 (w751's 4→1 was run-length); all function-path printers byte-equal. `addr_owners --check 0x821CC1E0` = 2 sites exit 0. `mitigation_audit` exit 1 pre-existing (unchanged; this change's tokens in neither list).
- **Registration:** `PROGRAM_GUIDE` §7 paragraphs (`:455` probe, `:457` answer) + §9 first-cell row (`:758`); `markers_from_guide` re-run after the edit: `T4312-UNDELIVERED` tracked=True, total 234→235 (T4311 still tracked).
- **Record notes:** `PROGRAM_GUIDE.md` is **CRLF** and holds 1 lone `` — python text-mode line numbers run +1 somewhere after line 459, so cite grep/read-tool numbers (its own §9 row is `:757`/`:758`); `ROOT_CAUSE_VALIDATION.md` stays **LF** with its 1 known NUL; PowerShell `>` still writes UTF-16 (`w752_census.txt` parsed with `encoding='utf-16'`).
- **Docs changed this block:** `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-787`; `docs/PROGRAM_GUIDE.md` §7 + §9; this §13; `docs/LONG_TODO_MASTER.md` T43.12 → ✅ ANSWERED + new T43.13 row. Uncommitted — commit only when asked; stage named paths only.

## 14. 2026-10-08 14:0x — SUPERSEDING §13.2 (the residual). **T43.13 ANSWERED (F-788).** Ledger top = `### F-788`, **640** headings ⇒ next free ID **F-789** (measured, don't trust: `grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1`, always `-a` — the file's 1 NUL byte makes plain grep under-report).

### 14.1 What T43.13 establishes (all citations reread this session; w753/w754 are the probe runs)

1. **The producer is named: `::ReadFile` + OVERLAPPED on the pack handle inside `RpfVirtualFileSystem::ReadFileAt`'s handle branch** (`src/fs/vfs_rpf.cpp:2835-2860`, call `:2842-2843`, span splice `:2852-2855`). Full chain: guest `sub_8244F4C0` body → `NtReadFile` positional arm (`src/kernel/imports.cpp:3460`, NFS-ARM `lr=8244F548` rows all `pos=1`) → `ReadFileAt` → `::ReadFile` → 32K page buffer (`RD-BUF` `src/gpu_device.cpp:19279`, heads byte-exact vs `rpf[0x1F0000]`/`rpf[0x1F8000]`) → guest `sub_821CC1E0` body → `sub_821CBE18` window write (`WINWR-WATCH` `:19593`, `#42 w754:14250 srcBase=B795C000 src8=rpf[0x1F8000]`). Nesting closed by line order: the ReadFileAt row prints before the enclosing RD-BUF (`:14010 → :14012`, adjacent) ⇒ call 949's ReadFileAt completed inside that `sub_8244F4C0` invocation.
2. **The zero was the limiter, and the row now prints itself.** New log-only probe `READAT-DROP` (`vfs_rpf.cpp:2733-2759`, counter `g_readAtDropped` `:2614`, budget `first 1024 + every 4096th` `:2748`): `w754:14010 call=949 off=001F0000 req=32768 got=32768` + `w754:14016 call=950 off=001F8000 ...` — the exact two calls missing between printed `READAT-BRANCH #944/call=948` (`:13980`) and `#947/call=951` (`:14056`). `001F9000/001FA000` stay structural zeros (no read issued there; 0 drop rows either). F-787 §13.2's "⇒ never reached ReadFileAt" is true only for granule fills (they issue no reads) and false for the page reads — both readings are now on separate, named rows.
3. **w753 = the blind-budget warning.** First probe shape (`first-64-then-every-256th`) printed 66 drops but spent them on the preamble (64 by `call=84`, 512 by `call=575`, total <768 — no `#768` row) and missed the target pair (dropN 513-767). Budget fixed to `first-1024-then-every-4096th`; w754 printed all 685 (calls 21..967, every row `got==req`). Recorded in the counter comment `vfs_rpf.cpp:2606-2613` — do not shrink the budget back.
4. **Correction:** the inherited buffer-map note "pair = `001F8000`→B795C000 + `00200000`→B794C000 (`B794C000` = page `rpf[0x200000]`)" is REFUTED by direct rows: pair = `001F0000`→B794C000 + `001F8000`→B795C000 (the two pages covering the whole member `[0x1F5000,0x1FACCF)`); `0x200000` arrives later (`:14254/:14255`, after the fill `:14250`) into a recycled B794C000.

### 14.2 Gates / state (this block)

- **Build:** two builds this block (probe, then budget fix), each `[1/2] vfs_rpf.cpp.obj + [2/2] link` = exactly one TU (rule 1a); `g_readAtDropped` is the only new file-scope symbol (rule 1b); `mcla.exe` killed before/after every run; guest binary untouched; nothing committed.
- **Soaks:** w753 120 s (5,202,487 B, 66 drop rows — blind budget), w754 120 s (5,403,408 B, 685 drop rows incl. both targets) — new log per experiment. `soak_census w754 vs w750` exit 0: DEPTH 1.03x COMPARABLE, LOG QUALITY top 16% (no withholding; drop rows 2.1% of lines), `readat-branch` **282 = 282** (leading-literal rows — the probe observes, not perturbs; naive substring of `READAT-BRANCH` over w754 = 967 = 282 + 685 prose mentions), `rd-buf` 113 (114), `nfs-arm` 21=21, `winwr-watch` 141=141, `arc-window` 62=62. w753 gate also exit 0.
- **Registration:** `PROGRAM_GUIDE` §7 paragraph inserted before `## 8. ` + §9 first-cell row after the `T4312-UNDELIVERED` row (`:758`, now followed by the new row); `markers_from_guide` 235 → 236 (READAT-DROP tracked=True); `soak_census` tracks it from the frontier as well (w753 already reported `readat-drop:66` in COUNT SEMANTICS before any §9 row existed).
- **Record notes:** `PROGRAM_GUIDE.md` is **CRLF** (python byte-insert used; cite grep/read numbers, not python text-line numbers); `ROOT_CAUSE_VALIDATION.md` stays **LF** + 1 NUL (binary append, always `grep -a`); `HANDOFF_NEXT_AGENT.md` is LF. ⚠️ The shell in this harness is **PowerShell**: it eats backticks inside `python -c "..."` double-quoted strings (bit a row-locator this session — pattern silently lost its backtick and matched nothing) and `>` writes UTF-16; use write-tool scripts for anything with backticks. The `READAT-BRANCH` banner prose printed in every row still cites the stale gpu_device sites `:2946`/`:22763` (live = `:3217`/`:23849`, measured this session) — do not chase it; fixing that string would change log text and desync w754.
- **Docs changed this block:** `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-788`; `docs/PROGRAM_GUIDE.md` §7 + §9; `docs/LONG_TODO_MASTER.md` T43.13 → ✅ ANSWERED; this §14. Uncommitted — commit only when asked; stage named paths only.
- **Post-landing gates:** `addr_owners --check sub_8244F4C0` exit 0 (2 sites = orig `:19211` / override `:19225`, one owner each; this task added no hook); `mitigation_audit` exit 1 = pre-existing baseline with **zero T43.13 attribution** — the stale six are all pre-existing and `READAT-DROP` is in neither failure list (registered §7 + literal in `src/`). Count drift vs the 2026-10-01 measurement (registered 92→132, undocumented 86→88, stale 4→6) is N-way across the tree's uncommitted work — not attributed here.

## 15. 2026-10-08 15:2x — SUPERSEDING §14's "Next tasks" framing. **T43.14 LANDED (F-789).** Ledger top = `### F-789`, **641** headings ⇒ next free ID **F-790** (measured this session; always `grep -a` — the file's 1 NUL byte makes plain grep blind to most headings).

### 15.1 What T43.14 establishes (all citations re-read from `build/w755.log` + raw files this session)

1. **The deliver gate now opens on the logical-clamped EOF granule, and the fill is byte-exact.** Fix = `src/gpu_device.cpp` only: served-body lookup moved before the gate (`:20196-20202`, comment `:20191-20195`), gate `arFull || arClamp` (`:20225-20230`, deliver call `:20234`, `arClamp` predicate `:20226-20229`), banner amendment `:20146-20161`. `MclaArcWindowDeliver` untouched (`:19755`, clamp `:19770-19773`, `ret=0` refusal `:19774`), `ctx.r3 = ar.want` (`:20250`) ⇒ guest-visible return identical on every row; only window bytes change. **Proof:** `ARC-WINDOW #153 rec=B79150A0 CityDefault.fxc pos=20480 want=3327 done=3327 head=05000861` (`w755:17422`) == fresh `zlib.decompress(rpf[0x1F5000:0x1F6D9A],-15)[0x5000:0x5004]` byte-exact (**True**); second clamp row `#160 CityDefaultGrime want=2647 = 23127-20480` (`w755:17665`) also exact.
2. **The refusal class is gone — classified, not counted.** `T4312-UNDELIVERED` 28 → 3; tool classifier: **w754 = 22 clamp-refused + 6 zero-eof + 0 other → w755 = 0 clamp + 3 zero-eof** (the 3 are `gate=0 ret=0 pos==bodySize posIn=0`, `w755:13552/:17072/:21347`). Probe retained as complete census + regression alarm.
3. **The F-785→F-786 park chain is dead, every link:** direct `T4310-HUGE-MEMCPY 1→0`, `T4311-LEN-GUARD 1→0`, `count=FFFFFFFF 1→0`, `len=FFFFFFFF 2→0`; census `HEAPHDR-STORE 202→0`, `F374-HEAPSTORE 32→0`, `F631-HEAPWIN 32→0`, `F379-HEAPSTORE-BT 20→0`; `T4311-LEN-SELFTEST fire=[1,1,0,0]` still passes (rule 19).
4. **The ceiling was the refusal — single-variable against w754.** w743/748/750/754 all stall at the identical `ARC-WINDOW#=62, GETDEV=268, LISTLINE=1, star_glow=0`; w755 exe differs in `gpu_device.cpp` only (`[1/2] gpu_device.cpp.obj`), ceiling breaks: `ARC-WINDOW # 62→176`, `STREAM-WINDOW 58→99`, `XSF-HOSTSERVE 51→141`, `LISTLINE 1→81`, `GETDEV 268→620`, census `SERVE-PROOF 102→282`, `TOC76 462→768`, `PARK-SAMPLE 208→84`. **A wall, not THE wall:** no presentation progress (`NATIVE-PRESENT 2=2`, `HB-FLICKER 39=39`, `DRAW_INDEXED 0`) — the boot now dies at the next wall (§15.2).
5. **Regression check on the new fatal — it is NOT the delivered bytes:** `star_glow` = 0 rows in all four baselines (the boot never reached it), 27 in w755; the fatal's member content is served correctly on its other path (`TOCSERVE-DEFLATE leaf='star_glow.dcl' stored=83 tocW1=89 inflated=89 served=89`, `w755:25734`); `Unable to load shader` appears in **no other log of build/w685..w754**, and the older `FATAL-SOFT` rows there are different messages (`'Unknown manufacturer %s…'` w685/w700, `'Old version of rage effect…'` w733, 0 rows w734–w754).

### 15.2 The new head of the queue (measured; cause UNATTRIBUTED — write the next task from here)

- **The fatal:** `FATAL-SOFT 'Unable to load shader '%s'…' lr=82189270` (`w755:25836` @14:48:14.569; dispatcher `:25821`, message `:25824`, **aux `:25825 = 'star_glow'`**). Immediately preceded by the embedded-entry gate, both forms: `AFB76-REFUSE #74 'embedded:/dcl/star_glow.dcl' reason=NO-EMBEDDED-ENTRY content=NOT-CORROBORATED blocked=STEP6-ALLOC` (`:25744`) + `#75 'embedded:/star_glow.dcl'` (`:25763`), each with `AFB76-MISS-HONEST (T41.3d/F-066)` (`:25745/:25764`); then the mangled hop of §8's documented cascade — `TOC76/TOC76-SG path='star_glow/dcl/star_glow/dcl/star_glow.dcl' ret=0 [all zero]` (`:25792-25805`) and `path='dcl/star_glow.dcl'` (`:25807-25812`) — then the fatal 9 ms later. **This is the ancient F-011 cascade, reached for the first time since the early logs; do NOT call it a regression (§15.1 #5 is the check).**
- **Two labeled hypotheses, both falsifiable, neither measured:** (a) the host embedded-entry gate lacks a table this boot needs (T41.3d/F-066 territory) — falsified if supplying the embedded entry kills the fatal without touching the pool; (b) `blocked=STEP6-ALLOC` = content corroboration denied by the refusal burst starting 14:48:03.635 (`PHYS-POOL-FULL #1 … refused=1 over_frag=1`, `:18151`; `XTL-ALLOC-REFUSED #1`, `:18152`) — falsified if a boot with headroom passes STEP6 with no embedded table present.
- **T43.2's phase is now reachable (first full-boot log ever to reach it):** `PHYS-POOL-FULL 0→9`, `XTL-ALLOC-REFUSED 0→8`, `PHYS-LIVE 0→256` (0 in all four baselines). This is exactly the terrain `LONG_TODO §6` **T43.1c** ("the instrument now perturbs what it measures") and **T43.2** ("a contradiction, not an exhaustion") were written for — next session can start there without re-deriving why.
- **The wild AV is host-named:** `Vectored exception code=0xC0000005 rva=0x2980BA7 thread=7200` (`w755:18729` @14:48:04.910) → `host_rva_resolve.py build/mcla.map 0x2980BA7` = **`__imp__sub_825FA460 +0x2a7`** exit 0 (same-build map). Pre-existing class (census `C0000005 4→2`), parks a thread, process survives.

### 15.3 Gates / state (this block)

- **Build:** `[1/2] gpu_device.cpp.obj + [2/2] link`, 0 errors — exactly one TU (rule 1a); only new symbols are locals `arFull`/`arClamp` `:20225/:20226` (rule 1b); `mcla.exe`+`mcla.map` mtime 14:47:14, w755 started 14:47:49.432 (rule 12); `mcla.exe` killed after the run; guest binary untouched; **nothing committed** (stage named paths only if asked: `docs/{ROOT_CAUSE_VALIDATION,PROGRAM_GUIDE,HANDOFF_NEXT_AGENT,LONG_TODO_MASTER}.md`, `src/gpu_device.cpp` + prior sessions' modified `src/*.cpp`).
- **Soak:** w755 = new log per experiment, 120 s survived (TIMEOUT_KILLED), 43,932 lines / 7,853,784 B, span 14:47:49.432 → 14:49:48.845, post-killed.
- **Gates:** `soak_census w755 vs w754` **exit 0** — `DEPTH 1.35x (bar 2.00x) → COMPARABLE`, 262 tracked, no WITHHOLD verdict (LOG QUALITY top = idle CAS-SITE/WAIT/WAKE 15% each). `addr_owners --check 0x821CC1E0` exit 0 (orig `:19798` / override `:19800`, no new hook). `mitigation_audit` exit 1 = **pre-existing baseline, zero T43.14 attribution** (STALE 6 = F432-SC/F434-SC/GATE-STACK/GFX-BLOCK/INVERTED-DIRECTION(+1), UNDOCUMENTED 88; output keyword counts `T43.14=0 arClamp=0 arFull=0 AMENDED=0`). `host_rva_resolve` exit 0 (above).
- **Two instrument notes (rule 19), do not re-import:** `count=170` is **0 in both** logs — never a log literal (F-786's manual hex parse); and `F631-HEAPWIN` census lead-count = 32 while direct literal = 64 — quote census semantics when quoting the census.
- **Docs changed this block:** `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-789` (LF + 1 NUL, binary append); `docs/PROGRAM_GUIDE.md` §7 new clamp-arm paragraph + AMENDED note on the T43.12 paragraph + §9 row amendment (CRLF byte-edits, 0 bare LF introduced); `docs/LONG_TODO_MASTER.md` T43.14 → ✅ (the file has 1 pre-existing bare LF, untouched by this edit); this §15. **Prediction for the next census:** `markers_from_guide` should not change (no new marker added — F-789 added no printer).

## 16. 2026-10-08 16:1x — **T43.15 ANSWERED (F-790): the `star_glow` fatal is pool exhaustion seen through a shader load.** Ledger top = `### F-790`, **642** headings ⇒ next free ID **F-791** (measured after the append: `grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1` = `### F-790`). **No build, no boot** — diagnosis from `build/w755.log` + host code only; the working tree is §15.3's uncommitted set plus this block's doc edits.

### 16.1 What F-790 establishes (every row re-read this session)

1. **The full fatal chain, measured row by row.** `AFB8-IN #74` (`w755:25731`) → seed list intact and missing `star_glow` *by design* (`listCount=15`, `:25385`; comment `gpu_device.cpp:24118-24124`) → F-655 fallback resolves it in the guest TOC (`candidates=1 tocVerdict='OK'`, `:25744`) → inflate + magic pass (`tocW1=89` = `inflated=89`, `:25734`) → **STEP6 `mem.Alloc(89,16)` = 0** (`gpu_device.cpp:24077-24080`) → `AFB76-REFUSE blocked=STEP6-ALLOC` for both forms (`:25744`, `:25763`) → the guest's own fallbacks `TOC76 #502-505` / `BDF20 #268/#269` all zero-return (`:25792-25813`) → fatal (`:25821-25836`).
2. **The null is the pool, continuous since 11 s earlier.** `AllocPhysical: o1heapAllocate returned null #1..#8/#100/#200`, @14:48:03.578→14:48:12.120 (`w755:18124-21088`), every row `live=0x1ffa8000 cap=0x20000000 peak=0x1ffa8000` (511.7/512 MiB), `caller_rva=0x2bc7aa` → `?Alloc@GuestMemoryHeap@kernel@mcla@@QEAAI_K0@Z +0x1a` (`host_rva_resolve.py build/mcla.map`); `PHYS-STATE #1` (`:18139`) = `free=0x58000 free_ppm=671 verdict=over-fragmented why=free_but_no_suitable_class` (`suitable=0x0`, `bin_mask=0x1c0`); `XTL-ALLOC-REFUSED #1..#8` sizes 14..9520 in the same window. Only three return-0 arms exist in `GuestMemoryHeap::Alloc` (`memory.cpp:529-539`) and the null is the only live one (proof in F-790).
3. **F-789's two hypotheses are settled:** (a) table-missing **REFUTED** (list printed, 15/15); (b) pool **CONFIRMED** — but the denied step is the body's *allocation*, not the corroboration, which **passed**. And **`content=NOT-CORROBORATED` is a vestigial constant**: init `gpu_device.cpp:24239`, printed `:24328/:24334`, **no assignment**, 14/14 rows identical — its comment `:24187` overpromises; never read a corroboration verdict off it.
4. **Rule-19 budget note:** the sampler prints only `n <= 8 || (n % 100) == 0` (`heap.cpp:3455`), so the fatal window's empty `oom` set is a budget, not a pass — `blocked=STEP6-ALLOC` is this event's evidence; ≥200 refusals by 14:48:12, unknown after. The 12 `rage_im` refusals are a *different* class (`blocked=NO-GUEST-TOC-RECORD`, `candidates=0` — no such leaf in the guest TOC) and did not fatal; the run's single `AFB76-HIT #1` (`:1866`) is `fxl_final/rage_im.fxc`, the form that does exist.

### 16.2 Next head of queue (registered order unchanged)

- **T43.1c → T43.2 remain the cure** — the fatal has no fix of its own: with the pool refusing everything, the next guest allocation dies the same way. F-790 adds T43.2 three measured inputs: the in-tree mechanism (`heap.cpp:1976-1982`: `__xtl_free` "is a deliberate no-op that returns 1, so EVERY guest XTL allocation is un-reclaimable and the physical arena can only grow"); w755's classifier now says `over-fragmented` where the T43.2 row's w743 premise said `healthy` (`free` 34.97 MiB → 352 KiB, `bin_mask` `0x801c0` → `0x1c0`); the 314 MiB `alloc_seq=3` block is still at `block_guest=A3A8C000`, `freed=0` (`PHYS-LIVE` rows, `:25743`).
- Seeded in §15.2-15.3 and still open: T43.3 (1 row unattributed), T43.4 (provenance probe), the wild AV `__imp__sub_825FA460 +0x2a7`.

### 16.3 Gates / state (this block)

- **No build, no boot;** `mcla.exe` not running; newest `build/*.log` = w755 (§15.3, still the named baseline). Working tree: §15.3's uncommitted set (4 docs + 8 `src/*.cpp`) + this block's 3 doc edits; the `docs/archive/trail-handoff-2026-10.md.tmp` stays untracked/excluded from any commit.
- **Prediction (same check F-789 §15.3 recorded):** next `markers_from_guide` = **262** — F-790 added no printer.
- **Docs changed this block:** `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-790` (LF + 1 NUL preserved, binary append); `docs/LONG_TODO_MASTER.md` §6 gains the T43.15 row (CRLF byte-insert after the T43.14 row; pre-existing bare-LF still exactly 1); this §16.


## 17. 2026-10-08 16:5x — **T43.1c DONE (F-791): `NotePhysLive` is off the allocation path — same storm, 6.9× less injected latency, first positive `guest_refs` ever, `ctl=` fires from row #1.** Ledger top = `### F-791`, **643** headings ⇒ next free **F-792**.

### 17.1 What F-791 establishes (every row re-measured this session)

1. **Cost, re-timed exactly as the row demanded.** `PHYS-LIVE` 256 → 254 rows (= the refusal count both boots; `oom n∈{1..8,100,200}` printed exactly 10 rows of 254), era **10.934 s @42.9 ms mean → 1.596 s @6.3 ms mean**, `scanned=256.0MB → 16.0-16.9MB` per row, same `star_glow` fatal (+25.14 s → +15.94 s boot-relative). Census shows the freed wall-clock went to the guest: `CAS-SITE/WAKE +10,896` each in the same 300 s.
2. **Byte order was the instrument's last structural zero** — 276 rows / 10 prior logs dead (F-783 §8). After the `be()` swap (`heap.cpp:1903`), `PHYS-LIVE #1` (`w756:18167`) already reads **`guest_refs=1 hit0=82830B54`**, stable across all 254 rows: a runtime-written image .bss global (file-at-rest `00 00 00 00`, past code end `0x827CD054`) holds a value in the block's span `[0xA3A8C000, 0xB6611000)` — **the first guest word ever to name the block.** Region 0 (image) found it in emission #1 (`sweep_ppm=4119`); the old linear cursor would have met it 2.04 GiB in.
3. **Rule 19 discharged:** `ctl=2` on row #1 and all 254 rows — both control dwords (`4D 5A 90 00` at image base, `61 28 67 72` at `0x8218C848`) raw-counted in `mcla_pe.bin` this session, **1 occurrence each**. Zeros (`pool_refs=0`, `freed=0`) are data now.
4. **Registry arm type error fixed:** `reg_hit 0 → 2` of `reg_total=4951` (host `aligned` vs guest VA; now `MapVirtual`, `heap.cpp:1862`). The 2nd entry's identity is open — candidates in F-791(e).
5. **One gap, recorded not hidden:** the wrap `complete=1` arm never fired — the fatal ended the era at `sweep_ppm=992674`, **2 emissions short of pass end** (needs ≥257 refusals per block era to close).

### 17.2 Next head of queue

- **T43.2 (name the exhaustion) — now carrying F-791's inputs:** start with **`0x82830B54`** (decode what the runtime word is and who writes it — the first lead that names the span), then `guest_refs=1 / pool_refs=0`, `reg_hit=2/4951`, `ctl=2`. F-790's three inputs (`STEP6-ALLOC` chain, refusal-era continuity, `content=NOT-CORROBORATED` vestige) remain in its row.
- Still open behind it: T43.3 (1 row unattributed), T43.4 (provenance probe), wild AV `__imp__sub_825FA460 +0x2a7` (§15.2).

### 17.3 Gates / state (this block)

- **Build:** one TU — `[1/2] heap.cpp.obj` → `[2/2] link`, 0 errors (`build_ninja.log` 145 B); `mcla.exe` 14:47:14 → 16:40:18 (rule 12 discharged). Rule 1b new symbols of this change only: `PhysLiveRegion`, `kPhysLiveRegions`, `kPhysLiveCtlMz/Ori`, `g_physLiveCtl` (file-scope, `heap.cpp` only), locals `cursorRgn`/`passScanned`; new include `ppc_config.h` (read-only).
- **Soak:** w756 = new log per experiment, 300 s bound, RC=124 survived (as w755), 78,367 lines / 12,667,325 B, span 16:41:21.193 → 16:46:20.304, `mcla.exe` killed after; err log = 1 benign DXC line.
- **Gates:** `soak_census w756 vs w755` **exit 0** — **262 tracked (F-790's prediction held)**, `DEPTH 1.78x (bar 2.00x) → COMPARABLE`, no poisoned verdict (top shapes 22.2%), `PHYS-LIVE 254/256 −2`, `[error] 521/522`, refusal structure `PHYS-STATE 8/8`, `XTL-ALLOC-REFUSED 8/8`, `PHYS-POOL 10/10`, `PHYS-POOL-FULL 9/9`; `mitigation_audit` **exit 1** = baseline; rule 4 — no hook added.
- **Docs changed this block:** `docs/ROOT_CAUSE_VALIDATION.md` appended `### F-791` (binary append, LF + the 1 NUL preserved: 1 → 1); `docs/LONG_TODO_MASTER.md` §6 T43.1c → DONE (measurements inline); this §17. Baseline for the next census: **w756**.

## 18. 2026-10-08 17:3x — **T43.2 DONE (F-792): the 314 MB asker is `sub_82131228`'s video-mode size helper; the 512 MiB pool is the fixed `kConsolePhysicalBytes`; the fill is boot 354.0 MiB + XTL micro-allocs each carrying the 16 KiB slab floor — the pool dies over-fragmented at `free=0x4e000`, then the boot fatals on `star_glow`.**

Ledger top = `### F-792`, **644** headings → next free **F-793**. Baseline census unchanged: **w756** (next markers prediction still **262** — F-792 adds no printer). No build, no boot, no `src/` change this session (docs only).

### 18.1 What the three T43.2 questions resolved to (all tool-measured; full chains + falsifiers in F-792)

1. **Q A — who asks `0x12B80000`:** `sub_827A7688` → `sub_82131228` (one-shot boot init, flag dword `0x828315DC`) → bit4 step → helper `sub_82130EC0` (`r8=min(w,1280)`, `r9=min(h,768)`, `mullw`, `(r7−pixels)×16 & 0xFFFF8000`; `VdQueryVideoMode` hardcodes 1280×720 = `imports.cpp:4589-4590` → pixels=921,600) → `rlwinm sh=10` @`0x82131408` → `bl 821BC0F0` @`0x8213140C` → `sub_82132578` (glr=821325D4) → import `0x827BCF14` → `imports.cpp:4938`. Observed size pins **r7 ∈ `[0x1399000,0x1399800)`**; r7's last def = `mr r7,r29` @`0x82131370` ← `*(0x82830CD4)` — **writer of that dword NOT found; r7 unaudited across `sub_821C0F80`'s four internal calls** (falsifier: one runtime read @`0x821313E8`). Naming word: node `0x82830B54` (r4 = the returned pointer) = **F-791's hit0**.
2. **Q B — what fills it:** boot #1–#3 = 46.5+8.0+**299.5** MiB = **354.0 MiB in 8 ms** (`w756:224/252/260`, over-console +0.017%); tail #2000→#8000: live 402.5→**507.8**, free 109.5→**4.2**, **every row `caller_rva=0x2bc7aa` = `GuestMemoryHeap::Alloc+0x1a`**, host charge 581.3 vs console 455.8 = **+125.5 MiB**. Mechanism: `__xtl_alloc` (`imports.cpp:158`) → `GuestMemoryHeap::Alloc` (`memory.cpp:529-539`) → `AllocPhysical` floors alignment to **`kPhysSlabGranule=0x4000`** (`heap.cpp:3237-3238`) before `o1Amount=size+alignment+96` (`heap.cpp:3387`) — measured: a 14-byte ask charges `0x402e` (≥16.5 KiB each); `align_bytes=131,072,000=8000×16384` at #8000. Counts: 7,447 XTL successes + 954 non-XTL = 8,401 served exactly; refusal era 35.527→37.128 s = **254 refusals in 1.601 s**; death `free=0x4e000` (312 KiB) `verdict=over-fragmented why=free_but_no_suitable_class`; **`PHYS-VERDICT-CHANGE` gains its second row ever (healthy→over-fragmented)**. **`MmAllocatePhysicalMemoryEx: FAILED` = 0 is routing, not blindness** (refusals print `returned null` via `memory.cpp:534`; PHYS-LIVE's `caller_rva=0x2f36a8` is bigRva = block provenance, not the refusing caller; rule 19 satisfied — the same macro printed 22 XTL-ALLOC rows in-log).
3. **Q C — is 512 MiB right:** the pool is the fixed **`kConsolePhysicalBytes=0x20000000u`** (`heap_arena.h:97`), told to the guest by five structural sites (`:176-181`, live = `gpu_cp.cpp:2572-2573`); `MmAllocatePhysicalMemoryEx` receives and *drops* min/maxAddress (`imports.cpp:4938-4943`). **Bounded prediction: console-fair headroom at #8000 ∈ [56.2,129.7] MiB** — under the console's own page model the pool would NOT have died here; **the 16 KiB floor is the candidate root cause, and it is NOT a queue row yet — register it in `LONG_TODO §2` before working it** (two-queue rule; F-792 proposes no fix).
4. **Terminus:** identical `star_glow` shader fatal at +37.128 s in w755 and w756 (w754=0) — pool→fatal is a *hypothesis* with falsifiers (F-792 §2/§4.4).
5. **Regime difference recorded, not explained:** w743's four `verdict=healthy` refusals at free=34.97 MiB did NOT reproduce in w756 — the bin-19/split-at-healthy question is unexercised in this baseline (falsifier: a w756-era refusal row with `verdict=healthy`).
6. **Arithmetic owed by the row's INPUTS, paid:** `0x12B80000` = 314,048,512 B = 314.05 MB = **299.50 MiB** (the old `313.75 MB`/`299.2 MiB` was hand arithmetic, withdrawn in the row); `peak_req=0x12b84020` = 314.06 MB = 299.52 MiB = `size+0x4000+0x20` = the `o1Amount` formula exactly.

### 18.2 Next head

- **Queue:** T43.3 (1 row unattributed) → T43.4 (provenance probe); the wild AV at `__imp__sub_825FA460 +0x2a7` is still out there.
- **Unregistered lead (F-792 §3):** the `kPhysSlabGranule=0x4000` floor as the pool-exhaustion root cause — **needs a new `LONG_TODO §2` row before anyone works it.**
- F-792's seven residuals (§4) each carry a falsifier; cheapest next probe = the runtime read of `0x82830CD4` at `0x821313E8`.

### 18.3 Gates

No build, no boot; `src/` untouched (rule 1b: no new symbols). Docs changed: ledger F-792 (binary append, LF, NUL 1→1 asserted), `LONG_TODO_MASTER.md` T43.2 → DONE + INPUTS arithmetic corrected, this §18. Census baseline: **w756**; next markers prediction: **262**.

## 19. 2026-10-08 20:2x — **T43.3 ANSWERED (F-793): the `P5-LOOKUP → FFFFFFFF` row is our mitigation stack talking to itself — the table is ours, the arena never handed the address out, 5.2's "double-ownership … is measured" is REFUTED.**

Ledger top = `### F-793`, **645** headings → next free **F-794**. Baseline census unchanged: **w756** (next markers prediction still **262** — F-793 adds no printer). No build, no boot, no `src/` change this session (docs only).

### 19.1 What T43.3 asked and what F-793 measured

The question: *is the guest's rebase table legitimately empty for `0xB6FB2F29`, or should our arena never have handed that address out?* Answer — **both arms dissolve the question, and both point at us:**

1. **The table is ours, not the guest's.** `MclaPublishGuestRebaseTable` allocates `s_gRebaseTable` (`gpu_device.cpp:7400-7404`), fills it from `g_mclaRebaseMap` (`:7410-7417`), prints `REBASE-TABLE @BD40C000 n=7 (D828-form vbase/pbase/size)` (`:7418-7419`, `w741b:11364`); `MclaArmRebaseCtx` installs it as `[group+0]` (`:7429-7430`, called at `:16833`, rebuild group `pctx.r4 = s_rbCtx` `:16839`). `P5-LOOKUP r3=BD40C000` (`w741b:11381`) = that same address ⇒ the guest queried **our** table. All 7 records are 0x50/0x60 vbases (`REQDUMP #6 w741b:11389`; `w756 PSTREAM :3612-3620`); membership `vbase<=addr<vbase+size` (`:7381-7386`) ⇒ a `0xB6……` key **structurally cannot hit** — `FFFFFFFF` was guaranteed.
2. **The arena never handed `B6FB2F29` out.** Nibble 9 ⇒ not 16-byte-aligned, not `kPhysSlabGranule=0x4000` (`heap.cpp:3237`). Provenance = **payload word[1]** of buffer `B7981000` (`RSC-CHILD-DUMP w741b:11366`; words [4][5][6] gate-bad `:11367-11369`, incl. ASCII `kdp+`). Span membership in `[A0400000, C0400000)` ≠ a hand-out.
3. **How it got walked (root = ours):** `FDBF8-ARR-RESTORE` (`gpu_device.cpp:16783-16822`) — poison gate `:16783-16784`, `kArrCand` 6 hardcoded buffers `:16786-16789` (`B7981000` is 6th, `break` `:16822`), `looksPtr` `:16800-16801` accepts word[0]=`B813FA0A` ∈ `[B0000000,C0000000)` — promoted the payload buffer to entry array (`w741b:11362`); the rebuild ran the place-pass on a **fresh `pctx`** (`:16834-16843`, lr not copied); fixwalk took `head=[bucket+4]=B6FB2F29` (`:11377-11378`), armed the watch (`:11379`), looked up, missed (`:11381`), and `P5-PHYS` (`task_dispatch_trace.cpp:600-611`, `a5>=0x80000000` ⇒ delta-0) suppressed `sub_821D2378`'s **unconditional** fatal tail (`b 821BD618`; strings `0x82013168` / `0x82009840` read from raw bytes) — so guest ctor `sub_8260B310+0x24` (`stw r10,0(r31)`, r10=`0x82088784`) wrote a real vtable into the payload address (`PAGEWATCH W #064`, `:11385`).
4. **Writer census + the `lr` residue closed:** exhaustive raw scan of `mcla_pe.bin` = exactly **3** `addi …,-30844` sites (`sub_8260A8F8+0x20`, `sub_8260B310+0x20`, `sub_8260B420+0x78`), no host writer (`task_dispatch_trace.cpp:92` only registers the value for watching). The row's `lr=821BC53C` is the **parked original context** (last guest-body bl of `sub_821BC140+0x3f8` → `bl 821C31B8`; proven by `COMPLETE sub_821C31B8 #5 lr=821BC53C` `:11322`, chain sandwiched before `POST-EXEC #5` `:11386`), read via `GetPPCContext()` (`gpu_cp.cpp:7887-7889`) — **not** the storing frame; the hooks print the re-dispatch `pctx` instead. Falsifier in F-793 §5.
5. **Dormant:** `B6FB2F29` in **2 of 192** logs (`w741` + `w741b`, 11 rows each), **0 in `w756`**. `LONG_TODO §5.2` now carries a dated supersession note; the T43.3 row is flipped to ANSWERED.

### 19.2 Next head

- **Queue:** T43.4 (provenance probe on `sub_82130528`'s return at `8218B2EC`, `LONG_TODO:1622`); wild AV `__imp__sub_825FA460 +0x2a7` still open.
- **Two fix candidates, NOT queued (two-queue rule — `§2` rows first):** root `FDBF8-ARR-RESTORE` (`gpu_device.cpp:16783-16822`), silencer `P5-PHYS` (`task_dispatch_trace.cpp:600-611`). **Order matters:** ARR-RESTORE first — removing P5-PHYS alone converts silent corruption into a fatal.
- **REGISTERED 2026-10-08 as `T43.16`:** the `kPhysSlabGranule=0x4000` floor question (F-792 §3's unregistered lead) — operative row in `LONG_TODO` §6's T43 queue table + index bullet in §2; no work before the row's gate.
- F-793 §9's five residuals each carry a falsifier (payload writer of `B7981000[1]`, rest of `sub_8260B310`, the other 5 `kArrCand` candidates, PAGEWATCH lr provenance, T43.4).

### 19.3 Gates

No build, no boot; `src/` untouched (rule 1b: no new symbols; rule 4: nothing new claims a guest address). Docs changed: ledger F-793 (binary append, LF, NUL 1→1 asserted), `LONG_TODO` T43.3 → ANSWERED + §5.2 supersession note, this §19. Census baseline: **w756**; next markers prediction: **262**.
