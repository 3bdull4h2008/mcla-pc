# MEMORY.md — session memory (written 2026-10-05, ~03:40)

## 🔴🔴🔴🔴 F-647 IS INVERTED. THE PROJECT'S MOST-CITED RULE WAS WRONG ALL ALONG.

**F-647 says: "all three decompilers render PPC rotate-immediate masks backwards — raw `55 6A 00 42` is MB=1, ME=1 = bit 1."**
**That is FALSE. MB=1, ME=1 ⇒ bit 30 ⇒ `0x40000000`, which is what the ISA gives, what `ComputeMask` gives, and what IDA and `ppc_recomp.17.cpp` print. THE EMITTERS WERE RIGHT. THE RECORD'S GLOSS "= bit 1" IS THE ERROR.**

Proof by hand-derivation at a second site — raw word at VA `0x8218C7BC`, bytes `54 68 06 3E`:
```
opcode (w>>26)=21 (rlwinm)  RA=8  RS=3  SH=0  MB=(w>>6)&0x1F=24  ME=(w>>1)&0x1F=31
ISA  (retain bit j iff 24 <= 31-j <= 31)   : 0x000000FF
ComputeMask(24+32, 31+32)  rewriter:5-11 @ :1546 : 0x000000FF
emitted  ppc_recomp.9.cpp:18356            : 0x000000FF
ALL THREE AGREE.  clrlwi = CLEAR LEFT -> retains the low 32-n bits; n=24 -> low byte -> 0xFF.
```

**⚠️ IF ANYONE "FIXES" `generated/**` TO `0xFF000000`, 16,709 SITES ACROSS 176 TUs INVERT AND THE BOOT GETS STRICTLY WORSE.** 176 TUs, 130,206,972 B, sha256 `3ac8016d…b5fd5`. **An agent's refusal stands between that and the tree.**

**F-647's own control could never have detected the bug it was cited for:** MB=0 masks are **symmetric under the MB↔ME swap**, so a control like `rlwinm r5,r9,12,0,19` → `0xFFFFF000` is correct *necessarily*. **The real discriminator is `rlwinm r3,r4,0,16,31` → `0x12345678 & 0x0000FFFF`.**
⚠️ **This is the blind-control trap INVERTED: not a control that passed while blind, but one that was correct by construction and therefore could never find the defect no matter how hard it was used.**

**The 16,708 `& 0xFF;` grep count is CONFIRMED as a count and REFUTED as a defect count.** `clrlwi` 16,315 + `clrlwi.` 49 + `rlwinm` 340 + `clrldi` 3 + `rldicl` 1 = 16,708 — **100.0% rotate-family, 0 wrong.** MB=0,ME=19 emits `0xFFFFF000` at 112/112 sites; MB=5,ME=23's 898 raw words all sit in `0x8200xxxx–0x8212xxxx`, **outside the compiled span — data, not code.** No host-side equivalent: `src/` has **no** rotate-imask emitter.

**F-647 has propagated into `AGENTS.md`, into briefs, and into `src/gpu_device.cpp:23495-23508` + `src/kernel/guest_memory.h:298`, where it justifies a root cause that does not exist.**

**Regen is blocked anyway:** `config/mcla_xenonrecomp_baseline.toml` is **32 lines vs the live config's 257**, missing all four `[[midasm_hook]]` blocks. SKILL.md §3 step 3 says STOP.

## 🔴 I CONFLATED TWO ADDRESSES 168 BYTES APART

```
fatal fires at  lr=0x8218C864  -> 210 log lines
the clrlwi I cited at lr=0x8218C7BC -> 0 log lines
```
**I handed an agent a "smoking gun" built from an instruction that never executed.** `R8PROV` — the hook built to settle it — fired twice with **`r8inIsCompareOperand=0` both times. The compare operand is NEVER WRITTEN.**

## Where the boot actually dies, stated honestly

**The data is right.** `XSF-HOSTSERVE … head=72677861`, `HOSTSERVE-WINDOW-READ #23 req=23807 got=23807 head=726778610BFF0711…`, `served=23807 proved=1`. **The fatal is `'%s: Old version of rage effect found.  You need to recompile your shaders!'`, `lr=0x8218C864`, and its cause is NOT YET NAMED.** Strongest remaining lead is host-side: `DISCCHK2 #33 gate=fatal-chunked` with `slot0=slot1=00000000`. Ledger: **F-765** written.

---

## 🔴🔴 28 SOAKS: A FLAT PLATEAU. ZERO FIXES MOVED THE BOOT.

```
[03:05:34.413] XSF-HOSTSERVE path='shaders/city/fxl_final/CityDefault.fxc' off=001F5000
               size=23807 stored=7578 logical=23807 buf=BACA0280 head=72677861 pass=0
[03:05:34.413] BE8D8-PACK #4 obj=82860C68 h=1 tocEntry=B737C320
               sbuf=BACA0280 size=23807 dst=BACA6280
[03:05:34.414] XSF-HOSTSERVE … buf=BACAF280 head=72677861
[03:05:34.415] STREAM-WINDOW #42 inner=82860C68 h=1 slot0=B927F280 slot1=0000148A
[03:05:34.415] FATAL-SOFT  'Old version of rage effect found.  You need to recompile your shaders!'
```
**THREE serves, all with the correct retail head `72677861` ('rgxa'). The fetch path works.** The stream object `82860C68` carries `h=1` and its `slot0=B927F280` holds `0x148A` = **5,258 bytes = `rage_im.fxc`**, not `CityDefault.fxc` (23,807). **The served body is never installed into the slot the stream reads. This is a BINDING defect, not a data defect.**

⚠️ **UNRESOLVED and must be eliminated, not assumed away:** a prior agent measured that `inner + 0x30` is **`base + 0x1000` = ANOTHER wrapper's `{BUF,…,cap=4096}` triple**. **So `slot0`/`slot1` may be the WRONG OBJECT's fields, and the "mismatch" could be a census artefact.**

### ✅ THE FABRICATION IS DELETED AND VERIFIED (w724, build clean)
`BE710-MAGIC #` 0 · `BE710-MAGIC-OFF` 0 · `BE710-DEAD` 0 · `BE8D8-PACK-MISS` 0 · `REFUSE-NO-SRC`/`REFUSE-NO-BODY` 0/0.
Fatal unchanged: 1, same `lr`, same string. `XSF-POSTOPEN-SERVE` **86** ✓ · golden 25 ✓ · `OPEN-REFUSED-STATUS` 0 · `LIST-CONTENT-MISMATCH` 0.
⚠️ **`lr=8218C864` appears in 139 lines** = 68 `PARK-SAMPLE` + 68 `park-mirror-stack` + 1 `FATAL-SOFT`. **Read `FATAL-SOFT`, never the `lr` count.**
⚠️ **A comment quoting deleted code made the audit tool think the write was still there** — that agent reworded its own comment. **Do not quote the deleted `WriteU32BE` call anywhere.**

### ⚠️ THE GUEST'S CHECK — decoded correctly this time (I had it wrong by one register)
```
8218C83C  bl  0x821BE710        ; read ONE word into the guest
8218C844  lwz  r7,80(r1)        ; the word just read
8218C848  ori  r9,r8,0x6772     ; r9 = 0x61786772  -- a DEAD STORE, r9 never read again
8218C84C  7F074000  cmpw cr6,r7,r8    ; compare against R8, NOT R9
8218C850  beq  cr6 -> 0x8218C878      ; equal -> good path
8218C860  bl  0x821BD618              ; LR := 0x8218C864
```
**The comparison is against `r8` — caller-volatile, whatever the `bctrl` at `0x8218C828` (vtable slot +88) left behind.** `src/gpu_device.cpp` never writes `ctx.r8` (every use is a read). **r8 is the guest's. Do not supply it.** (Cross-checked with `tools/ppc_disasm.py 0x8218C7B0 56`.)

---

## 🔴🔴🔴 A HOST WAS FABRICATING THE ANSWER — `kBe710MagicWrite` — masking 57 fatals. DELETED.

```
             BE710-MAGIC  BE710-DEAD  BE8D8-PACK-MISS
w722:              57           57               21
w723:               0            0                0
```

`src/gpu_device.cpp:24971-24974` wrote **`0x61786772` — literally the constant the guest compares against** — into the guest's buffer, unconditionally, whenever the dead-stream arm was taken. Its own comment names the intent: *"make the rage_im stream itself deliver the magic at the read position."*

**w722 reached that guest site with no served body, so the host fabricated the word and the gate compared a host-fabricated word against a host-fabricated constant and passed.** The `ret >= 0` gate fix made the serve succeed ⇒ w723 delivers the **real retail bytes** ⇒ the guest's own reader now produces the wrong word. **"It is a fabrication being removed from under the check."**

**Why no version field needs writing — the comparison is against served bytes, byte-swapped by the guest itself:**
```
retail member head  72 67 78 61  ('rgxa') = 0x72677861
guest sub_821BE710  loops 0x821BE73C-0x821BE768 byte-swapping each word
  -> 0x61786772  == exactly the constant compared against
```
Harness: `[T1] served 0x72677861 -> guest word 0x61786772` · `[C4] served 0x11223344 -> guest word 0x44332211` · `[C5] served 0x61786772 -> guest word 0x72677861` — **the guest swaps; it does not pass through.**

**Guest side, from raw words:** `lr=0x8218C864` is **`sub_821BD618`'s return address**, and `addr_owners --check 0x821BD618` → 1 site, `src/patches.cpp:414` — **whose own comment calls it the error dispatcher.**
```
8218C83C  bl  0x821BE710       ; read ONE word
8218C844  lwz  r7,80(r1)
8218C848  ori  r9,r8,0x6772    ; expected = 0x61786772
8218C84C  cmpw cr6,r7,r9 ; beq 0x8218C878   ; equal -> good path
8218C85C  addi r3,r11,-18584   ; r3 = 0x8200B768 = the fatal string
8218C860  bl  0x821BD618       ; LR := 0x8218C864   <-- the log's lr
```

**THE REGRESSION QUESTION IS MOOT — the guest did the SAME work.** The two `XSF-OPEN` streams are ordinal-aligned: **88 ordinals common, 0 where the path differs.** w723's path set is a strict subset of w722's. **w723 stopped at ordinal 89 — interrupted, not diverted. No diversion, no starvation.**

## ⚠️ THE `ret >= 0` GATE AGENT'S HARNESS WAS VOID — 12/12 measured nothing

> *My first harness linked all 230 objects, ran, and printed confident numbers for every case — while measuring nothing: it never installed the guest view, so every guest read was refused. My C4 perturbation control failed and exposed it. **Note that the T-retgate harness omits the same two calls, so its earlier result was void for the same reason.***

**Two calls install the guest view: `boot_host.cpp:3163` and `app.cpp:53`.** Without them every read is refused `GUESTVIEW-U32-REFUSED … view_base=0x0 view_size=0x0` and the numbers are **confident and false.**

**The soak effect of the gate fix is still real** (`XSF-POSTOPEN-SERVE` 59→86, 45 rows `handle=1`/`handle=2`; `HOSTSERVE-WINDOW-READ` 11→23; `OPEN-NULL-BOUND` 0→24) — **but its harness evidence is not.** **This is the THIRD harness this session that printed confident numbers while measuring nothing.**

## The live suspect: a slot-binding mismatch

```
slot 1 = 0x148A = 5,258 bytes  = the rage_im.fxc body
CityDefault.fxc = 23,807 (0x5CFF) registered to SLOT 4
stream object 0x82860C68 carries h=1
```
**The guest is reading slot 1, but its `.fxc` was served into slot 4.** Prime suspect for the fatal. **Not localised to a line** — lives in the open/bind path (`BE8D8` slot assignment ~`:23602`, `MakeMemoryStream`). **Do not guess it.**

`DISCCHK2 gate=fatal-chunked` is a **population label, not a decision** — `(flags & 3) == 2` for `flags=40001D9A` (`gpu_device.cpp:19247`). **Not the cause.**

⚠️ **`tools/ppc_disasm.py` mis-decodes `op20` A-form as `lswi`; it is `rlwimi`** (opcode 31, XO=26), verified at `0x821BE74C/50`. The working tiebreaker is `generated/ppc_xenon/ppc_recomp.14.cpp`. **Not fixed — tools belong to another agent and `generated/**` is forbidden.**

---

## 🔴 RETRACTED: the D3D12 input-signature "risk" is NOT REACHABLE. Stop calling it one.

I called it "a PSO input-signature mismatch risk." **Measured four independent ways it cannot fire:**
```
A cache-produced PSO WAS created and bound:  PC-PSO-BOUND #1/#2 … psoIsTestPso=0
PC-PSO-CREATE-FAILED = 0   <- this means "creation SUCCEEDED", not "never reached"
psoDesc.InputLayout is the VERTEX-STREAM layout (pipeline_cache.cpp:1910-1911);
  the PS input signature is intrinsic to psoDesc.PS bytecode (:1902)
d3d12_backend.cpp:6517-6623 never converts descriptors into an ID3D12InputLayout
D3D12 requires PS inputs SUBSET OF VS outputs -- a PS declaring FEWER is LEGAL
516 real paired VS/PS: emitted PS inputs 516/516 = SV_Position only, TEXCOORD 0, unmatched 0
```

**THE DECISIVE FACT: GPRs are not input elements at all.** The reference's PS input signature is one `OpDclInputPS` per set bit of `GetModificationInterpolatorMask()`, breaking at the first bit ≥ `register_count()` (`dxbc_shader_translator.cc:3636-3654`). **The GPR seed is an `OpMov` to `Dest::R(i)` — a register** (`:685-701`). **Nothing about `register_count()` reaches the signature.**

**`176/256` was a miscount of what was compared** — 1353 vs 145 sets *declared GPR locals* against *read-never-written registers*. Different things. **The signature was deliberately NOT widened**; widening would only add inputs for registers no body reads.

### The 59-vs-0 contradiction RESOLVED — neither number was wrong
Both reproduced exactly. **They were over different sets; "(b) was never a bound on (a)".** (b) bounds the *subset* whose register is also in the interpolator table.
| of the 59 | seed printed | verdict |
|---|---|---|
| **in the interpolator table: 25** | `interpolant<N>` | **genuinely false** |
| not in the table: 34 | `0.0` | matches what the emitter would give |

**The cause was NEITHER number's guess.** Not a zero write-mask read — that measures 0 pairs, which is *why* (b) was 0. It is:
```cpp
shader_translator.cpp:1489   if (instr.exportData) vectorWriteMask &= ~instr.scalarWriteMask;
```
With `exportData=1` and `scalarWriteMask` covering `vectorWriteMask` the **effective** mask is 0, so the write arm is skipped and `NoteOperand` never fires **even though both RAW masks are non-zero.** All 25 print `vwm=0xE swm=0xF export=1`.

Three fixes landed, one honest deferral: read over-count bounded by `GetOperandCount()` (pin 14,894 ours vs 11,377 reference, **2,410 ours-only, 0 reference-only**); fetch 24/25/26 no longer records a destination (10 instructions, 5 containers); seed gate now matches the emitter's own condition. **Deferred explicitly: scalar operands remain ungathered** — the reference uses `scalar_const_reg_op_src_temp_reg()` for `count==2`, **a bitfield this decoder does not populate. "Counting them would invent a field."**

⚠️ **UNRESOLVED:** 114 interpolant entries have `usage == 10 = POSITIONT`, a semantic the VS never exports. **Unmeasurable offline** because the intersected mask is empty for every corpus PS (`psInputMask=0x00000000`). Whether a *real* guest draw can produce a non-empty intersection with `usage==10` surviving is **unmeasured** — claimed neither way.

---

## 🔴🔴 THE HEADLINE: 27 SOAKS OF A FLAT PLATEAU. ZERO FIXES MOVED THE BOOT.

**Every marker-moving fix in this session is a mitigation. None moved the boot.**

```
boot -> fatal : median 14.903 s  stdev 0.530  range 14.494-16.184  n=22
                3.6% coefficient of variation across 22 soaks
pinned to an integer, UNCHANGED FOR 27 CONSECUTIVE SOAKS:
    2 presents   2 draws   2 pixel readbacks   0 audio frames   1 fatal
pairwise Jaccard of the pre-fatal token SET, last 12 soaks: 0.96 - 1.00
verdict: FLAT - a plateau. Neither monotonic nor oscillating.
```

### `TIMEOUT_SURVIVED = 0` — I misread my own soak results all session

**Not one log in the corpus ended because the guest was still running.** Every soak dies of a fatal at 14.4–16.0 s, then the host thrashes to the harness cap. **The timeout measures ~135 s of post-mortem.** `TIMEOUT 150s (process survived = normal good result)` **measures nothing.** On duration alone the verdict is a tautology.

**The game has NEVER exited cleanly.** The 3 `CLEAN_EXIT` files are the **texture validator**.

### The corpus is 232 logs, only 48 are game runs
| class | n |
|---|---|
| `OTHER_TRUNCATED` (not a game log, or tail is live thrash) | 157 |
| `FATAL_DISPATCH` | 36 |
| `EMPTY` (all `*_build.log`/`*_err.log`, 0 B) | 35 |
| `CLEAN_EXIT` (texture validator, NOT the game) | 3 |
| `CRASH` (smoke_long2, VEH `0xC0000005`) | 1 |

The 48 game runs (contain `Initializing MCLA Native`): 36 `FATAL_DISPATCH`, 11 no-fatal, 1 `CRASH`.
⚠️ **`w721.log` does not exist** (only an empty `_build.log`). `w697` also missing.

### THE REAL FRONTIER — named from the logs

*2 CP draws issued — the second writes an all-black surface — one present with a real swapchain surface, then the guest **returns to XSF TOC walking** and dies in the vehicle-list tokenizer ~2 s later.*

In w722 the 17,761 lines between the last `DRAW-CP-DRAWN` (L8066) and the fatal (L25655) are dominated by `TOCWALK-SLICE` **1863**, `TOCWALK-DIR` **1862**, `READWRAP` **1650**, `BE710-SLOT` **1089**, `XSF-OPEN` **605**.

**So the frontier is not the graphics pipeline and not the VFS. The guest draws two triangles, presents once, then spends the rest of its life walking a table of contents.** Deepest GPU evidence ever: two 3-vertex triangles, the second `rgba=(0,0,0,0) … nonBlack=0/921600 (0.0000%)`.

The **only** genuine step in 33 soaks is **w720**: the fatal `lr` moved `0x823966E8` → `0x821D02D4`. **Both are unhooked guest code** — `addr_owners --check` = 0 sites each. Nothing on the host owns either path.

### Corrections to numbers I had been quoting as baselines

- **`AUDIO-FRAME` has ZERO real rows.** Its single hit is `AUDIO-UNDERRUN`'s prose naming it. **The guest has never submitted one audio frame.**
- **`PRESENT` 30 in w722 is NOT all refusals:** 22 `PRESENT-SURFACE-UNREADABLE`, 2 `PRESENT-KICK-CENSUS`, 2 `PRESENT-SURF-AUDIT`, 2 `W31-PRESENT-CENSUS`, 2 `NATIVE-PRESENT`.
- **`PRESENT-FB` 4→0 and `PRESENT-BLIT` 2→0 at w718 is NOT a regression.** `GUEST-SURFACE-UNCOHERENT-REFUSED` **first fires in that same log**, on `va=B96EF2C0` — the identical surface w717 blitted, reading `rgb=(0.00,0.00,0.00)`. The acceptance criterion got stricter (37.9% scattered debris vs a 5% ceiling); the surface did not get worse. **What "regressed" was blitting an all-black surface.** Gate `src/render_thread.cpp:1687-1729`.
- `MEMBER-SPAN-START-INSIDE` "3, all `windowOwner=00471000`" is true **only of w722**; in w720 the three rows are `00471000`/`00476615`/`0047682B`.

### The highest-value unattributed lead in the corpus

Time-to-fatal fell ~5× at `f298`(82.9 s) → `w685`(15.8 s). **The comparison CANNOT be closed:** the marker families are **disjoint**, so no shared scale orders them. f298-only: `XMEM` 2769, `INFLATE-OUTPTR` 1448, `INFLATE-R3-CENSUS` 1388, `JOB2-PKG-SERVE` 1297. w722-only: `TOCWALK-SLICE` 1863, `TOCWALK-DIR` 1862. The one datum favouring f298 — `fatal chain[1]: lr=0xD1287000` — **is unusable: that address lies outside the guest image (`0x82000000`…`0x829E0000`), so it is a stale stack slot, not a frame.** Rule 1a: N-way, no single-variable revert available.

### Census cross-check found a residual prefix-collision class
`INFLATE-ENTER` — the repaired tool now lead-anchors, but it is a strict **prefix** of `INFLATE-ENTER-SUMMARY`: **624 real rows + 25 SUMMARY rows = 649.** Both correct, different quantities. **The lead-anchor does not catch this class.**

---

⚠️ **This is NOT the project's durable record.** The authoritative store is
`docs/ROOT_CAUSE_VALIDATION.md` Part 3 (append-only evidence ledger, 616 headings, last `F-764`)
and `docs/LONG_TODO_MASTER.md` §0/§2. This file is a **session checkpoint only** — if the two
disagree, the ledger wins and this file is stale trail.

## The boot blocker, end to end (all links measured from raw bytes)

```
guest tokenizer  sub_821CFAA8  cmpw CUR,END ; bge->refill ; lbzx buffer[cur]   reads +28
guest device     sub_821BE360  bctrl dev->Read(dev, slot, buffer)   PASSES NO COUNT
our device       gpu_device.cpp:21300   serve GATED ON ret == 0
                              ret is the guest's SLOT INDEX, not an error -> never runs
result           +28 = 4096 for a 2839-byte body = 1257 bytes of foreign data
                              the tokenizer parses as text
                 = 'Unexpected EOF in fiBaseTokenizer::Pop'
```

- `+28` = **END**, the byte count the guest's own device read **returned** (`821BE374 stw r11,28(r31)`).
- `+0x3C` is **not a field of this object**; the body touches only `{0,4,8,16,24,28,32}`.
  The census's `w[]` window straddles past the contract (`+0x30` = base+0x1000 = a sibling wrapper).
- `pos` on the live stream regressed **3731 → 2876** (w722) — a re-serve of the same stream.
- **Proof the path can return exact lengths:** one row reads `+28 = 480`, which is exactly member
  `0x0035CA43`'s declared logical length. So something over-serves on the vehicle-list path only.

## Landed this session (all verified by soak)

| change | file | proof |
|---|---|---|
| **Window owner flip rule** — among candidates *beginning inside* a window, the **lowest data offset** wins | `src/fs/vfs_rpf.cpp:1611-1629` | w722: owner chain `00448000 → 00471000 ×3` (was 4 owners); all 3 `MEMBER-SPAN-START-INSIDE` rows now `windowOwner=00471000`; **1 of 108 windows** changed, 27,499 B; **107 byte-identical**; 29 boot flips → 27 |
| **`NFS-BADHANDLE` refusal guard** before both transfer arms (`handle < 0x1000 \|\| handle+sizeof(XDISPATCHER_HEADER) >= kSize`) | `src/kernel/imports.cpp:3281-3300` | harness: pre-fix 4/6 faulted + 2 returned `STATUS_SUCCESS` with a destroyed window; all six now refuse |
| **Resolver discrimination by registry membership**, not `o != raw` | `src/kernel/imports.cpp:2228-2231`, `:1540-1563` | 4 builds at `/O2 /Ob1`: pin REFUSED×3 → fix **ACCEPTED×3, 128 B = oracle**; resolver-only build REFUSED×3 (proves part 2 load-bearing); no-proof build **9P/1F** (proves controls fail) |
| **`CensusGuestRegisterAccess` unknown-arm split** — ALU-unknown still records its write, fetch-unknown records nothing | `src/renderer/shader_translator.cpp` | harness 15/15; pre-edit pin build fails 4 (G,I,L,O); blast radius **0** over 506 containers / 12,785 instructions |
| `read_member_off` prose corrected | `src/fs/vfs_rpf.cpp:2604-2612` | measured 292 rows, 54 non-zero, all 54 `raw_positional=1 span_ran=0` |
| `STREAM-WINDOW` census marker (unregistered) | `src/gpu_device.cpp:24828` | samples `+24/+28/+32/+8` either side of `__imp__sub_821BE250` |

## Claims I made that were MEASURED FALSE — do not re-import

| I said | Reality |
|---|---|
| `len=4096` is a bad section length | The **guest's own device read return value**. No count is passed. |
| `+0x3C` holds 2839 | `0x2EBD3` = **191,443** (off by 188,604). `+0x3C` is past the contract. |
| 36 owner flips | **29** boot-wide on 27 of 108 windows. 36 was the *candidate* count. |
| "RPF3 image" rule would fix it | **No-op** — nothing it admits begins RPF3. |
| "covers more of the window" rule | **Backwards** — carconfigs covers 32,768 vs 22,391. |
| The resolver swap was safe | **Destroys the read path.** |
| `imports.cpp` owned the read | **Wrong layer** — `handle=1` AVs before reaching the code. |
| `MEMBER-SPAN-ALIAS` 93→123 = 30 new collisions | **All 32 are counting artefacts. 0 genuinely new.** |
| `read && !written` "happens to select the same set" | **It selects 145 of 1,353** real seeds (10.7%); equal to the declared set in only **34 of 215** containers. |
| `REALIZE-CAST buf=` shows a byte-swap defect | **Reversed by the guest's own code** (`sub_821CF850` copies descending). Never cite it as served content. |
| "arena-range handles" | A misnomer. It is the `Translate∘MapVirtual = id` identity; all 5 real handles satisfy my own `≥0x20000` test. |
| "3 entry points reject good files today" | **Not firing** — those calls are 0 in both logs. |
| `vfs_rpf.cpp` is LF-only | **All-CRLF**, 2,739 LF *and* 2,739 CRLF. |
| `pos=1012` on a 2839-byte body was a miscount | **Correct** — non-decreasing, no window boundary crossed. |

## Open, with owner

| item | file | state |
|---|---|---|
| **the `ret == 0` gate — the live blocker** | `gpu_device.cpp:21300` | agent running |
| **who returns 4096** = XSF device obj `B7321700` vtable slot +24 | `kernel/imports.cpp` / `fs/vfs_rpf.cpp` | to dispatch |
| remaining **27 of 29** window flips — real rule is *"the owner must be the member the caller is reading"* = `readMemberOff`, structurally unreachable from `vfs_rpf.cpp` | needs `gpu_device.cpp` | blocked on T |
| D3D12 **input-signature under-declaration** (176/256) | `d3d12_backend.cpp` + `shader_translator.cpp` | free |
| **`0x54 PM4_INTERRUPT` undecoded on the boot path** (IB #9 dword 401, 2 packets before the park) | `gpu_cp.cpp` | free |
| fetch arm records `written[dst]` for opcodes 24/25/26 where the reference gives `kNone` — 10 instructions in 5 containers | `shader_translator.cpp` | free |
| `59 vs 0` seed-gate divergence (census row names a variable the emitted HLSL lacks) | `shader_translator.cpp` | free |
| **commit — never authorised.** 63 tracked changed, 67,829 ins / 19,334 del, 0 staged, HEAD `8385925` (2026-09-27). Stage by name in 5 groups; `docs/ROOT_CAUSE_VALIDATION.md` **must be its own commit** (`i/-text w/-text`, 17,017/12,819 vs a 10,110-line blob = whole-file rewrite). **Never `git add -A`.** | — | waiting on user |

## Standing facts for any agent

- **`tools/soak_census.py` misreports 39 of 244 markers** (25 prose-contaminated, 6 tautological
  zeros, 4 not-markers — §9's parser pulled `file:line` citations, `marker_tokens()` splits on `/`
  so they grade LIVE forever — 4 line-count≠count). A tracked marker named in another marker's prose
  is uncountable. Agent running on this.
- `PRESENT` is **not** a present count: of 191 raw lines only 30 lead with a present-token and **all
  30 are `PRESENT-SURFACE-UNREADABLE`, a refusal**. Real presents = `HB-FLICKER` + `NATIVE-PRESENT`.
- `MEMBER-SPAN-ALIAS` **not tracked**; `MEMBER-SPAN-TAIL-VETO` **0 real rows**; `DRAW-CP-DRAWN`
  **uncountable**; `STREAM-WINDOW` **unregistered** — §9 needs it.
- ⚠️ **`tools/ppc_disasm.py` is a PowerPC disassembler and CANNOT decode Xenos GPU microcode.**
  AGENTS.md lists it as "raw instruction truth" — **that is wrong for GPU microcode.**
- ⚠️ **F-647**: all three decompilers render PPC rotate-immediate masks backwards. Raw `55 6A 00 42`
  is MB=1 ME=1 = bit 1; IDA and `generated/ppc_xenon/ppc_recomp.17.cpp` both print `0x40000000`.
- ⚠️ **clang-cl 19.1.7 crashes** (`0xC0000005`, `X86 DAG->DAG Instruction Selection`) when a
  `__try/__except` sits in a frame holding destructible locals under `/EHa`. Isolate SEH into one
  `__declspec(noinline)` function.
- ⚠️ `shlex(posix=False)` splits `/I"E:\mcla pc\src"` and invents 35 errors. `-c` is a substring of
  `-clang:-std=c++23`.
- Line endings: `gpu_cp.cpp`/`gpu_device.cpp`/`vfs_rpf.cpp`/`shader_translator.cpp` differ —
  **measure before any multi-line patch.**
- Never write `build/*.log` with PowerShell `>`; use `build/soak_run.py`. Count byte-exact:
  `open(f,'rb').read().lower().count(b'…')`.
- Charter **F-609**: never fabricate a length, a colour, a pixel, or a file-content claim. A short
  read is a short read. An unread buffer is **refused**, never padded.
- **Six+ harnesses passed while blind.** Traps: per-row *width*; shared oracle structure; untouched
  input as a perturbation; a hard-coded line range the harness's own insert moved; `\s*` crossing a
  newline (silently parsed 45 of 47 enum entries); a generator that emitted one dword per
  instruction and mis-decoded every case after the first. **Prove your controls fail.**

## ⚡ `tools/soak_census.py` REPAIRED — 39 misreporting → 0, and it found a bug I missed

**244 → 240 tracked.** `--self-test` **63 checks, 0 fail** (was 30). Cross-check: 197 non-empty logs, 47,280 marker-instances, 0 incoherent, **1,051 instances (2.2%) moved**, 188 never moved.

**A FALSE NEGATIVE my audit missed entirely:**
```
TEXINSERT(2)   before: 0  ->  after: 16
  count_markers grepped the decorated 'texinsert(2)'; marker_tokens strips '(2)'
```
**A marker reading 0 forever reads as "never fires."** I was hunting inflated counts and missed a deflated one.

**Two of my "100% contaminated" claims were WRONG:**
- `DISCCHK` 41→41 **unchanged** — `DISCCHK2` **leads** those rows; it is the **stem class, not prose**.
- `WAKE` 8,495→8,495 **unchanged** — same reason; its ">99% contamination" is merging `WAKE[KWFSO]`+`WAKE[NTWFSO]`.

**The anchor, proved:** 51,078 of 51,079 lines parse a `[time] [tag]` prefix. `message-start + post-subsys token` discriminates all; **first-token** would report 0 despite real rows for **6** markers, **message-start only** for **1** (`HB-FLICKER`, 1.54% carry a `subsystem:` prefix).

**My other candidate repair was also falsified:** a blanket `MARKER_EXCLUDE` drops whole lines, so `DISCCHK` (41 lines, all `DISCCHK2`) **would be excluded by its own child and lose its family census.** Neither candidate alone was correct.

**Refused, correctly:** the **stem class** — 23 tracked names are a strict prefix of another, 3 share every row (`DISCCHK`/`DISCCHK2`, `GFx`/`GFXINIT`, `VEH`/`VEH W0:`). *"Deciding whether the stem row is a family census or should be deleted changes what the marker means, so I did not decide it."* Measured and printed under `STEM OVERLAP`. **Ledger owner's call.**

**Corrections to my own notes:**
- **`PRESENT` is 30, but only 22 are `PRESENT-SURFACE-UNREADABLE`** — plus `PRESENT-SURF` 4, `PRESENT-KICK-CENSUS` 2, `PRESENT-SURF-AUDIT` 2. I had said "all 30."
- **`slotcov=` 64 lines are all `FLUSH sub_821D5510`** — it is a **field**, needing an anchor, not `MARKER_EXCLUDE`.

**Latent landmine found in the tool itself:** `_strip_comments()` does `from addr_owners import …` without adding `tools/` to `sys.path` — imported by path rather than run as a script, **every marker silently grades DEAD.** `--self-test` catches it; **the census path does not.**

Also measured: `build/f299_cen193.log`, `f299_cen271.log`, `f309_cen273.log` are **census reports, not soaks** (186 lines, leading token `#`); the tool censuses its own output correctly but does not distinguish them.

## ⚡ THE PARK: `PM4_WAIT_REG_MEM ref=0` is NOT provably unsatisfiable — my note was wrong

**My standing note "proven unsatisfiable, reference hangs identically, do not attempt" is REFUTED.** The reference registers an interrupt callback (`VdSetGraphicsInterruptCallback: callback=0x82411478 user=0x40002080`, logged 390 ms before the packet), so `graphics_system.cc:242-244` would **not** early-return.

```
CP-WAITREG-TIMEOUT #1  is_memory=1 poll=1840B282 pollVA=B840B280
                       ref=00000000 mask=FFFFFFFF value=00000004 waited=2001ms budget=2000ms
CP-SCRATCH-WB-ADDR #5  val=00000004
CP-WAITREG-WRITER-VALUES #1  distinct=2 refAmong=0 v0=00000004 v1=00000003
```
**The wait polls for `== 4` at `0x1840B280`; the last writer left 3. `refAmong=0`** — the waited value is not among the written ones.

**`PM4_INTERRUPT` (`0x54`) is PRE-park and was MEASURED — my "0 occurrences" was false:**
```
CP-T3-UNHANDLED op=0x54 thisOp=1 allUnhandled=1     <- the ONLY unhandled type-3 packet in the soak
CP-T3-CENSUS  op=0x54 #1 count=1 depth=0 addr=B7C0A8C4 args=00000004 00000000 ...
0xB7C0A8C4 - 0xB7C0A280 = 0x644 = 401*4             <- dwords 401-402
park at dword 405, 2001 ms later, sequential single-threaded walk
operand 0x4 has bit 2 set -> DispatchInterruptCallback(1, 2) is reproduced by the
guest's own dword, NOT asserted
```
Landed `case 0x54` in `gpu_cp.cpp` — **decode only, DISPATCH REFUSED BY NAME.** `outAdvanceDwords = count + 1u`, **the same value `default:` already used** ⇒ zero behavioural effect. Marker `CP-INTERRUPT` (new, unregistered).

**The dispatch is the only candidate satisfier**, and it was refused because the write target is behind `*(u32*)(*(u32*)(0x40002080 + 10900))` (`ppc_recomp.75.cpp:14055-14115`), clearing bit `1 << (r13+268)`. **An agent is establishing that chain statically now.** It would need a host→guest call facility that is `static` in `gpu_device.cpp:7388`.

**The distinction worth keeping:** `0x54` has a `case` because it is **measured**; `0x64` (`PM4_XE_SWAP`) still has none because it is **not** — reachable only via the gate's `opcode != kPm4XeSwap` carve-out.

Also measured: `0x64` has no `case` in `DrainPacketAt`; `CP: RING A PARKED` prints `header=C0013F00` beside a hardcoded string `"(op=0x3C)"` but `C0013F00` decodes to **0x3F** (INDIRECT_BUFFER) — a mislabel, coherent but reads wrong.

## ⚡ w723: the fatal CHANGED, and the boot got LESS far

**The `ret == 0` gate fix is mechanically verified but the boot REGRESSED in depth. Do not claim progress.**

```
gate fix: gpu_device.cpp:21360  ret == 0  ->  ret >= 0
          gpu_device.cpp:21502  wouldBindNull, same bug, also fixed      (2 non-comment lines)
          proven from raw words: ret in {-1} u [0,16); -1 is the ONLY failure value
          (li r3,-1 at 0x821CCF40 / 0x821CCFE0; success = slot ordinal, stride 68 at
           0x821CCF4C, bound cmpi cr6,r30,16 at 0x821CCF2C; witness sub_821CB2A0)
          it had suppressed 499 of 558 successful opens

VERIFIED TRUE                     w722 -> w723
  XSF-POSTOPEN-SERVE              59 -> 86   (45 rows now carry handle=1 or 2)
  HOSTSERVE-WINDOW-READ           11 -> 23
  OPEN-NULL-BOUND                  0 -> 24   (all raceeditor.xsf; could not fire before)

VERIFIED REGRESSION
  fatal            'Unexpected EOF in fiBaseTokenizer::Pop'
                -> '%s: Old version of rage effect found.  You need to recompile your shaders!'
  fatal at         boot+15.2s  ->  boot+14.8s        <- EARLIER
  log size         8,163,069   ->  6,104,315 B       <- -25%
  XSF-OPEN         674         ->  121              <- -82%
  NFS-CENSUS[Read] 228         ->   91
  F456-STREAMID     40         ->    0              <- the tokenizer NEVER RAN
  MEMBER-SPAN-START-INSIDE  3  ->    0
```

**The EOF fatal is gone because the guest took a shorter path — NOT because the EOF was fixed.**

**New fatal context, verbatim:**
```
GETDEV-RET #68 path='a:/archive/shaders/city/fxl_final/CityDefault.fxc' ret=B7321700 vt=82012BDC
DISCCHK2 #33 strm=B732176C fobj=B7321700 len=1000 rec=B737C320 size=5CFF offs=1F5000
          flags=40001D9A route=guest-disc-read gate=fatal-ch...
STREAM-WINDOW #42 inner=82860C68 h=1 cur=4 end=4096 gran=4096 refilled=1
fatal-dispatch regs: lr=0x8218C864 r3=0x8200B768 r4=0xBAC96280 r5=0x507B0000 r6=0x00005CED
```

**`end=4096` is STILL present** — it is a **window-head offset** on `vfs_rpf.cpp`'s side (`:1888` "distance from the window head (4096 for both)"), against guest reads of `req=32768` at 32 KiB stride. `gpu_device.cpp` itself asks for `logicalLen` verbatim at `:2812` and pads nothing — all 11 `HOSTSERVE-WINDOW-READ` rows have `req == logical == got`.

**MEMBER AMBIGUITY SETTLED — I had merged two files:**
| offset | stored | logical | path |
|---|---|---|---|
| `7EF65487` | 494 | **2839** | **`tune/vehicle/vehicle0002.lst`** |
| `00471000` | 2355 | **22391** | `tune/vehicle/vehicle.lst` |

Also falsified this session: `read && !written` selects **145 of 1,353** real seeds (10.7%), equal to the correct set in only **34 of 215** containers — so it is measurably NOT "the same set" as the reference's unconditional seed. And **59 harvested rows name a variable the emitted HLSL lacks while a structural bound says that is impossible (0 pairs)** — the two disagree and one is wrong; unsettled.

## Tool traps earned this session

- An ISA-correct `op18` branch target read as **signed** lands outside the image; `ppc_disasm.py` reads it **unsigned** and also lands outside. **Not resolvable under either convention.** Only `bc` (16-bit BD) targets are self-consistent.
- `tools/ppc_xrefs.py calls` listed 20 "callers" of `0x821BE250`; a raw scan finds **0** direct call sites — it is vtable dispatch, and its `->` column names the *enclosing* function.
- **PPC decoder bugs found in harnesses (8 total):** primary opcode is `w >> 26` not `w & 0x3F`; op31 compare operands are `bits 20..16`/`bits 15..11` while `add`/`subf` use `bits 25..21`; op10 is `cmpli` not `addi` (it destroys the `cr6` the next `beq` consumes); `beq` BO is 26 not 12; `l`/`lmw` slots; and an F-647-class mask-width slip in `bl`'s LI.
- The guest's tokenizer does **not** re-read `buf[pos]` after a refill — it takes the byte the refill function returns.
- An **inert control**: `nopreload.txt` contains the substring `preload`, so it passed the filter and proved nothing.
- `sub_821CF850` copies the section name **descending** (`stb r10,0(r11); addi r11,r11,-1`), so `REALIZE-CAST buf=` prints the token reversed **by the guest's own code**. Never cite it as served content.
- The guest reads a **page-granularity constant** it wrote itself: `0x821BDEE4 li r30,4096` → `0x821BDEF4 stwx r30,r11,r28` stores it at `[stream+32]`. So `gran=4096` is the guest asking, not the host inventing.

## w722.log baselines (the previous full soak, 8,163,069 B)

```
Fatal error dispatcher 1  ('Unexpected EOF in fiBaseTokenizer::Pop')
MEMBER-SPAN-START-INSIDE 3   UIXSF-GOLDEN-REVERIFY 25 (pct=100 first_bad=ffffffff)
OPEN-REFUSED-STATUS 0   LIST-CONTENT-MISMATCH 0   PC-PSO-CREATE-FAILED 0
CONTROL-NOT-REAL-98765 0     NFS-BADHANDLE 0        NFS-ARM 22
DRAW-CP-PIXEL 2   DRAW-CP-REFUSE 0   BEAT-HELD-NO-NEW-CONTENT 28
GUEST-SURFACE-UNCOHERENT-REFUSED 2   changedBox=x0..639   sum=23961600 0
NFS-CENSUS[Read] 228   (rate limit n<=320 -> EXHAUSTIVE this boot)
owner chain [00470000,00478000): 00448000 -> 00471000 x3
```

**Backup:** `C:\mcla-pc-uncommitted-20261005\` — `tracked.patch` 8,221,167 B sha256 `7F9EF4BC…`,
`staged.patch` **0 B**, 61/61 untracked, 0 missing, 0 mismatches, `MANIFEST.txt` written,
git state untouched.