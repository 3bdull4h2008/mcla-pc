# HANDOFF — next agent, read this first

## READ ME FIRST — CURRENT STATE (2026-09-12, end of session 78; newer than everything below)

**BROKEN-STUB CENSUS IS NOW ZERO (91 → 0).** The last 30 distinct stub targets /
91 sites from session 77 are gone. They were one defect repeated: the
recompiler under-measured 19 functions, orphaning their exit blocks, plus a
tool limitation — the `bctr` switch-case emitter could only `goto` in-span
labels or print `// ERROR`, never call an out-of-span declared function.

What landed (all three pieces were required):
1. **20 parent-extension spans + 28 self-spans** appended to the canonical
   config `config/mcla_xenonrecomp.toml` (with explanatory comments in place).
   Parent spans widen under-measured functions to "next mapping entry - start";
   self-spans declare 2-instruction shared thunks as their own functions.
2. **Tool patch `JTS-TAILCALL`** in `.research/XenonRecomp` `recompiler.cpp`
   (~line 770): an out-of-span switch-case label now emits a tail call
   (`sub_XXXX(ctx, base); return;`) when the target has a function symbol,
   else `// ERROR`. The source edit was found uncompiled on disk (18:31) —
   the binary was rebuilt (verify: the exe contains the string `JTS-TAILCALL`).
   Build via `.research/XenonRecomp/rebuild_clang.bat`.
3. **Dispatch guard as a config hook.** The regen exposed that an earlier
   session had hand-edited the *committed generated output* — a SAFETY guard in
   `sub_8218CC70` (dispatcher trampoline that ends in `bctr` through the
   function-pointer table; a NULL/unmapped slot = hard crash). Any regen
   silently dropped it. It now lives in `src/dispatch_guard.cpp` +
   `[[midasm_hook]]` at `0x8218CC94` (after `lwz r8,64(r9)`,
   `return_on_true`) in the canonical config, so regens keep it. The
   hand-written `sub_8226B450` stub in `src/patches.cpp` was removed — the
   tool now emits it correctly (`li r3,1; blr`).

**Regen mechanics (learned the hard way):** run the tool with the config as a
**bare filename in repo root** (`cp config/mcla_xenonrecomp.toml .` first if
needed) — a path like `config/...` or `build/...` fails silently (exit 127,
empty log). `mcla_jts_regen.toml` (root) is now historical; the canonical
config regenerates straight into `generated/ppc_xenon`.

**Verification done before landing (don't redo):**
- Per-function body diff vs the committed tree: 27 new bodies (the self-spans),
  27 changed bodies (every one a former stub site → real call/label), plus the
  guard hook. 0 removed. File *names* unchanged (176 TUs; CMakeLists unchanged
  for TUs — only `src/dispatch_guard.cpp` added).
- 44,707 mapping entries, 0 without bodies (link-safe by construction).
- 219 "Unrecognized instruction" tool warnings — identical count to session 77.
- Boot soak PASS: same `star_glow` fatal, fatal message/aux/chain byte-identical
  to `boot_stdout_76y.log`, identical steady-state counts (TSLAB-ALLOC 2125,
  PARAM-STORE 401, EVENT-CREATE 256), and *more* forward progress
  (VSYNC-ISR ×120 vs 0, PRESENT #2). One new log line class:
  `Vectored exception code=0x406D1388` — that is the benign Windows
  SetThreadName exception from host code, not guest. Evidence:
  `build/boot_stdout_78.log`.

**Method scripts kept for reference:** `fix_stubs_iter.py` (parent-span
fixed-point loop) and `fix_stubs_self.py` (self-span fixed-point loop). The
intermediate scratch TOMLs they generated were deleted; their final state is in
the canonical config. Scratch regens remain under `build/xr_*` for diffing.

VMX128 note: no doc correction was needed — Route A (4 `vpkd3d128` type-2
hook sites) was already correctly recorded as landed in the session-75 block
below. Zero `debugtrap` in the soak is because those sites are hooked, not
because the path is unreached.

---

## READ ME FIRST — SUPERSEDED session-77 block (kept for context, 2026-09-12)

**THE SYSTEMIC JUMP-TABLE DEFECT IS FIXED AND LANDED (commit `b3d7dab`).** The
session-76y block below still describes it as open — that text is now stale.
The patched-XenonRecomp regeneration was found sitting uncommitted in the
working tree with three TUs deleted, so CMake could not configure and **the
tree did not build**. It has been landed properly rather than discarded.

Broken-stub census, both emitted forms counted (`ERROR: 0x...` and `ERROR ...`):

| | before | after | fixed |
|---|---|---|---|
| `ERROR: 0x…` (jump-table/branch) | 1557 | 29 | 98.1% |
| `ERROR …` (bare form) | 162 | 62 | 61.7% |
| **total** | **1719** | **91** | **94.7%** |
| distinct broken targets | 873 | **30** | — |

Re-grep recipe (both forms — the old recipe missed 162 of them):
`grep -hoE 'ERROR:? *0?x?[0-9A-Fa-f]{8}' generated/ppc_xenon/ppc_recomp.*.cpp`

**What changed mechanically:**
- The patched tool emits **176 TUs, not 179** (`ppc_recomp.0..175`), because
  folding jump-table targets back into their parent functions changes how output
  is split across files. `CMakeLists.txt` was updated to match — **if you
  regenerate again, re-check the TU count against CMakeLists or the build
  breaks.**
- One tool defect needed a host-side fix: the regen registers
  `{ 0x8226B450, sub_8226B450 }` in `ppc_func_mapping.cpp` but emits no body, so
  the link fails on an undefined symbol while 29 guest sites branch to it.
  Defined in `src/patches.cpp` transcribed 1:1 from the raw image
  (`38600001 4E800020` = `li r3,1; blr`). Its sibling `sub_8226B46C`
  (`li r3,-1; blr`) was emitted normally by the tool.
- Regen config tracked at `mcla_jts_regen.toml` (repo root — it must be a **bare
  filename**, see PLAN_VMX128.md §7b item 3). Its `out_directory_path` is
  `build/xr_jts`, and that scratch copy is still on disk as a reference.

**Safety verification done BEFORE landing (don't redo it):**
- The regen run *completed* — last TU closes cleanly, `ppc_func_mapping.cpp`
  (1.4 MB) terminates on its `{ 0, nullptr }` sentinel.
- 863 mapping entries were dropped (the old table-target pseudo-functions).
  **None** of the 177 guest addresses referenced anywhere in `src/` are in that
  set, so every host hook still resolves.
- All three session-28 explicit dispatcher spans survived: `0x825FDA90`,
  `0x8260B588`, `0x821DEE40`.
- `ppc_context.h` came back content-identical (line endings only), which
  independently confirms `src/ppc_context.h` is the correct header input.

**Boot soak result: behavior-neutral at the current frontier.** Identical to the
session-76y baseline on every metric — same `star_glow` fatal, `NATIVE-PRESENT`=4,
`FRAME-END`=2, `REBASE-POISON`=22, `TOC76`=120, `MOUNT76`=2, zero `PHYS-OVERRUN`,
zero AV, zero debugtrap, same fatal chain and same stack pointers. Evidence:
`boot_stdout_jts_regen.log` vs `boot_stdout_76y.log`.
**So the boot still stops at the same place — the `memory:` embedded
shader-device mount (next task unchanged, see below).** The gain from this
landing is *latent*: 1628 silently-broken code paths now exist, but the boot
does not yet reach the loaders that depend on them. Expect the payoff to appear
as newly-reachable code once the shader/archive path advances — re-run the
stub-vs-symptom grep before assuming a "field never written" bug is poison.

**Residual backlog: 30 distinct targets still stubbed.** Highest-count first:
`0x8226B450` (29 sites, now host-defined), then the bare-form set
(`0x8255FD48` ×9, `0x8264B38C` ×6, `0x82135C28` ×6, `0x82397FF4` ×5,
`0x82388030`/`0x8238802C` ×4 each). These are a *different* defect class from
jump tables — unresolved branch targets — and are the next infrastructure
tranche if a boot path lands on one.

**Also note:** `/docs/` is gitignored (`.gitignore:9`) so this handoff is
disk-only and has already lost one file to it (`PLAN_VMX128.md` was deleted and
had to be recovered from commit `09fd9f8`). Force-add docs if you want them to
survive a `git clean -xdf`.

---

## READ ME FIRST — CURRENT STATE (2026-09-12, end of session 76y; newer than everything below)

**Where the boot stops NOW:** clean guest fatal (exit code 3) —
`'Unable to load shader 'star_glow', it probably wasn't preloaded properly.'`
The weeks-long `0x7E780000` GetDevice crash is FIXED. The boot now: mounts both
RPF archives, processes resource packages ui/city/cars/characters/effects,
resolves all four `a:/archive/shaders/*/preload.list`, inflates 512KB shader
dict bodies, and dies when the shader system can't find star_glow because the
**embedded shader-library device ("memory:" mount) never happens** — no
`memory:` device is registered into the fallback slot 0x827D8380, so the
cascade `embedded:/dcl/star_glow.dcl` -> `embedded:/star_glow.dcl` ->
`embedded:/fxl_final/star_glow.fxc` -> mangled archive path all fail.
**Next task: find what should create+mount the embedded shader device and why
it doesn't run.** (MOUNT76 census in tree logs every Mount — only the two
`a:/archive/` packfile mounts appear.)

**The crash fix (committed f523e1a):** the crash was a heap OVERFLOW, not
poison: `sub_8218DCE8` (texture pitch) is a jump-table switch that XenonRecomp
emitted as `// ERROR: 0x...` stubs (return immediately) — pitch never written
-> checkerboard fallback sized its buffer 32 bytes and filled 4096 bytes over
the device-registry holder. Fixed with a faithful host override in
patches.cpp (semantics decoded from the raw image; fmt1 -> w*4 is the case
that mattered). **SYSTEMIC: the image contains 1557 ERROR-stub sites / 873
unique targets — every jump-table switch failed to recompile.** Route B
(fix XenonRecomp jump-table emission, regenerate, byte-diff validate) is the
highest-value infrastructure task; until then, ANY "field never written /
value garbage" bug: `grep -n "ERROR: 0x" generated/ppc_xenon/ppc_recomp.N.cpp`
on the involved functions FIRST.

**Key gotchas learned (don't re-derive):**
- `0xFF00FF00` = checkerboard "missing texture" texel, NOT poison.
- Guest-LR attribution lies after memset/slab-wrapper calls (sticky lr;
  0x8244D158 / 0x821C2AAC are artifacts) — use the FFBT host-backtrace probe.
- Allocator: default allocs route to the BUDDY allocator
  (`sub_821C08F8` -> `m_Allocators[(r6+1)*4]`, arenas at B7xxxxxx); the simple
  allocator (pool A0001010..A2E81000) serves direct callers only.
- Allocator CS 0x82855A0C: guest guard skips locking when `[cs+0]==0`; our
  RtlInitializeCriticalSection now writes Header.Lock=0xFFFFFFFF (verified).
- Census hooks in tree: MOUNT76 / TOC76 / EMB76 / TEXCTOR / GEN76-* / BUDDY76 /
  HEAP76 / GETDEV / FFBT / BOOTPATH — in gpu_device.cpp + patches.cpp.
- docs/ is gitignored: this handoff file exists ONLY on disk at
  docs/HANDOFF_NEXT_AGENT.md — do not lose it; the boot logs
  boot_stdout_76*.log in the repo root carry the evidence.

**Tooling:** IDA idalib server may still be running (port 8745, mcla_pe.bin).
Restart: run the venv python on
`C:/Users/abdul/.local/share/mcp/idamcp-venv/Scripts/idalib_jsonrpc_server.py`
with arg `-v "E:/mcla pc/build/cache/mcla_pe.bin"`.
Build/run (Git Bash): taskkill mcla.exe first, then
`MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat`
then `timeout 120 ./build/mcla.exe > boot_stdout_76z.log 2> boot_stderr_76z.log`.
Everything below this block is the historical session trail.

---


**Date:** 2026-09-11 (session 75j — continuous RE)  
**Goal:** Midnight Club LA native D3D12 renderer — working game with visible frames.  
**Repo:** `E:\mcla pc` (do not delete; overlay notes in `audit-clean/`).

---

## PLAIN STATUS (vibe-coder summary)

**Where we are:** Game boots, loading screens present on GPU. **No 3D world.**

**Fixed this week:** VMX128 int3 crash · blit heap storm (prior).

**Still broken:**
1. Texture packs register **empty**; named INSERT never runs → `CDCDCDCD`
2. Stay on loading screens → no vertex bind → `DRAW_INDEXED=0`
3. Real draw dispatcher `82227428` never sees type `0x20000000`

**Pipeline map (session 75h–j):**
```text
Empty factory 8218BF20     RUNS  → empty dicts
Real loaders 82216B98      DEAD  (streamables/globaltex; unmapped)
Mapped UI parents          DEAD  (STREAMTEX/UILOAD x0)
XMem LZX 8244FF20          WORKS (14x ret=0; not texture dicts)
Named INSERT 82185468      DEAD  (TEXINSERT x0)
```

**Next:** census factory requesters `8218D120` / `8218CB10`; find gate that
should trigger streamables load.

**Tools:** IDA `:8745` · Ghidra `:8089` · `docs/MCLA_RPF3_Technical_Reference.txt`

### RSC5 / XCompress layout (session 75g addendum)

Sample `vnyl_tears_05.xtd` (1227 bytes):
```
0000: 05 43 53 52          version 5 + "CSR"  (= RSC5)
0004: 00 00 00 09 c8 08 00 10
000c: 0f f5 12 ef          XCompress magic 0x0FF512EF
```
XCompress payload starts at **+0xC**. The inflate caller already does
`inLeft = bytesRead - 12` (header skip). INFLATE #1 sees real magic and
passes through. After a small file is consumed, the next refill returns 0
→ `inLeft = -12` → we INFLATE-SKIP (that part is EOF, not a format bug).

`.xtd` files are **never opened by path** in soak — only RPF packfiles
(`xarchive_audlo.rpf`, `xarchive_cache.rpf`). Texture data comes from
inside those archives. Empty dicts are whatever `8218B000` registers,
not necessarily a finished `.xtd` load.

**How to run / check:**
```bat
ninja_build.bat
build\mcla.exe
:: logs in boot_stdout_*.log — look for TEXINSERT, TEXDICT, REBASE-POISON, DRAW_INDEXED
```
**RE tools:** IDA MCP on `127.0.0.1:8745` (preferred) · Ghidra on `:8089` ·
generated TUs are the decompiled game code (never edit `generated/`).

**AUTHORITATIVE ARCHIVE DOC:** `docs/MCLA_RPF3_Technical_Reference.txt`
- MCLA uses **RPF3** exclusively (same struct as RPFv0)
- Header at `0x800`, TOC at `0x1000`, 16-byte entries, BE integers
- File entries: `name_off|flags, data_offset, compressed_size, uncompressed_size`
- **Compression = XMem LZX** (XDK `XMemDecompress`), NOT zlib. Optional
  raw-zlib fallback. Decision: `file_size == uncompressed` → stored.
- VFS extracted cache serves files as **stored** (no LZX on our side).
  Real `.rpf` opens serve the packfile bytes; **guest** XMem-decodes entries.
- Our `zlibInflater` (`sub_821D5E10`) hook is a **different** path from
  RPF XMem — do not conflate them.

### XMem census (session 75h, `boot_stdout_xmem2.log`)

| Marker | Hits | Meaning |
|---|---|---|
| `XMEM #` `sub_8244FF20` | **14**, all `ret=0` | LZX decompress **succeeds** |
| Caller | `lr=821D5EBC` (inside `InflateBegin`) | same path we already pass through when magic is XCompress |
| `XMEM-OUT` heads | `44365500`, `00019249`, … | **not** RSC5 (`05435352`) — these blobs are not texture dicts |
| `TEXINSERT` | 0 | named registry still never filled |

**Unsquish works.** The successful XMem calls are not the texture-dictionary
loads. Next: find which RPF entries / which caller should produce
`pgDictionary<grcTexture>` with a name table.

### Empty-dict factory vs real loader (session 75i)

| Addr | Role | Mapped? | Soak |
|---|---|---|---|
| `sub_8218BF20` | **zeros** dict fields then `8218B000` register | yes | runs (via 8218B000) |
| `sub_82216B98` | refs `$/resources/ui/textures/streamables` + `$/textures/blank` | **no** | — |
| `sub_821FD6B0` | mapped caller of 82216B98 | yes | **STREAMTEX ×0** |
| `sub_8233DE48` | refs `textures/global/cars/globaltex` | **no** | — |
| `sub_82185468` | named INSERT → `0x82839E2C` | no | TEXINSERT ×0 |

So what registers is an **empty-shell factory**, not an RSC load. The
streamables/globaltex loaders never run (or are only reached via unmapped
code). INSERT still dead.

Callers of the factory (`8218BEB0` → `8218BF20`): mapped
`8218C3F8` (unmapped), `8218CB10` (task ENQ family), `8218D120`.
Census `8218D120` / `8218CB10` next — those are the request side.
UI streamables parents `821FD640` / `822012E8` also **STREAMTEX/UILOAD ×0**.

### Session 75j soak (`boot_stdout_ins2.log`)

| Marker | Hits | Notes |
|---|---|---|
| `DICTFACT` `8218BF20` | 18 | factory via `lr=8218C614` in `sub_8218C1C0` / `sub_8218C760` |
| `DICTREQ` `8218D120`/`8218CB10` | **0** | those mapped requesters never run |
| `TEXINSERT2` `821854C8` | **5** | insert **works** when ctor `82185648` runs |
| Names inserted | `"Not Implemented"`, `"uiOverlay"`, `"uiOverlayDepth"` + 2 GPU-ptr "names" | only 3 real names |
| `STREAMTEX`/`UILOAD` | 0 | bulk loaders still dead |
| `REBASE-POISON` | 32 | everything else still misses |

**Insert is not broken.** Only three named textures are ever constructed.
`82185648` ctor → `821854C8` insert is the working path. Need the bulk
streamables/globaltex loaders (or more `82185648` calls) to fire.

Factory parent: `sub_8218C760` (mapped) → `sub_8218C1C0` → `8218BF20`.

### Session 75k — GLOBTEX-BOOT (real insert via guest API)

After TEXINIT, host reads `globaltex.list` (cars+city) and calls the guest
insert linker `821854C8(noneObj, name)` for each first token.
Soak `boot_stdout_gtex.log`: **`GLOBTEX-BOOT inserted=20 noneObj=A010B7E0`**.
Texture-finder poison (`prodLr=821853AC`) still fires for names outside
those lists (UI/world). 112-byte resource poison (`prod=N`) unchanged.

Uses the game's own insert on the game's own `none` object. Real loaders
can overwrite later.

**Note:** user cleanup commit `5fbc08e` deleted `docs/` — this file was
restored from `2742dad`. Keep it (or move status elsewhere) before the
next public push if docs should stay out of the repo.

Remaining: streamables/world texture dicts still never load
(`STREAMTEX`/`UILOAD` ×0). Then `82227428` / `DRAW_INDEXED`.

---

## SESSION 75E — IDA MCP UP; DICTIONARY REGISTER RUNS BUT LOOKUPS STILL MISS

### IDA setup (now live)
```powershell
# already listening on 127.0.0.1:8745, proxy connected
ida-pro_check_connection  # OK, mcla_pe.bin base 0x82000000
```
Start script: `tools/start_idalib_mcp.ps1` (or `idalib_jsonrpc_server.py`).
Use IDA for xrefs/Hex-Rays; generated TUs remain ground truth when bounds are wrong.

### Texture dictionary path (IDA Hex-Rays)

| Addr | Role |
|---|---|
| `sub_821849C0` | named lookup: `"none"` → `0x82839CF0`; else hash `sub_82183E80(&0x82839E2C)`; else walk dict list `0x82839ED0`; miss → fatal `"Unable to find texture '%s' in any active texture dictionary!"` @ `0x82009E20` |
| `sub_82197598` | **pgDictionary register** — `*(entry+8)=oldHead; head=entry` into `0x82839ED0` |
| `sub_8218B000` | mapped caller of 82197598 (census hook) |
| RTTI | `rage::pgDictionary<rage::grcTexture>` @ `0x827DC77C` |

`sub_82197598` is **not** in `ppc_func_mapping.cpp` (no `__imp__`) — cannot `PPC_FUNC` it.
Census lives on `sub_8218B000`.

### Soak `boot_stdout_c75f.log` (70s)

| Marker | Hits |
|---|---|
| `TEXDICT-CALLER` `8218B000` | **10** (r4 always `82860C18`, r3 = pool16 A0110xxx) |
| `TEXINIT` / `GFXINIT` | 2 / 1 (none/nonresident specials still OK) |
| `REBASE-POISON` | 12 (named textures still miss) |
| `DRAWDISP` / `DRAW_INDEXED` | 0 / 0 |

**Dictionaries register.** Named lookups still miss → dictionary *contents*
are empty (inflate never filled the pgDictionary body), not a register bug.

### Next (ranked)
1. Who should populate a loaded `pgDictionary<grcTexture>` (name table +
   texture objects) after inflate — likely another `8218Bxxx` / `8219xxxx`
   sibling once the RSC body is valid.
2. Confirm inflate of the **texture** archive (not audlo) actually produces
   non-empty output.
3. Still no world draws (`82227428` dispatch `0x20000000`).

---

## SESSION 75D — TEXINIT RUNS; NAMED REGISTRY FILL STILL MISSING

### Ghidra MCP (live on :8089, program `mcla_pe.bin` base `0x82000000`)

Workflow that works on this raw image:
1. `ghidra_load_program` with `PowerPC:BE:64:default`
2. `ghidra_set_image_base 0x82000000`
3. **Clear `no-return` on ABI thunks** `0x823D91E4/EC/F0/F4/F8/FC` (savegprlr family) — without this the decompiler truncates every function at the prologue
4. `ghidra_clear_flow_and_repair` on the range, then `decompile_function`

### Texture registry (decoded)

| Addr | Role |
|---|---|
| `sub_821811C0` | name lookup: special-string compare vs `"none"` @ `0x82009E18`, else hash `sub_82180680(table=0x82839E2C)` + linked list walk |
| `sub_82180680` | hash find (`FUN_821C95A0` / `FUN_823DB730`) |
| `sub_82180A30` | **init**: memset `0x82839D08`, creates `"none"`/`"nonresident"` objects into `0x82839CF0/CF4` |
| `sub_82177248` | sole caller of `82180A30` |
| `sub_82177948` | graphics-init bundle (`82177248` + more) |

Strings at `0x82009DFC`: `"Not Implemented"` / `"nonresident"` / `"none"` / `"Unable to find texture '%s'"`.

### Soak `boot_stdout_c75e.log` (80s)

| Marker | Hits |
|---|---|
| `GFXINIT-census` `82177948` | **1** |
| `TEXINIT-CALLER` `82177248` | **1** |
| `TEXINIT-census` `82180A30` | **1** |
| `REBASE-POISON` | 32 (named textures still miss) |
| `DRAWDISP` `82227428` | **0** |
| `DRAW_INDEXED` | 0 |

**Special-name init DOES run.** Fallbacks for `none`/`nonresident` exist. Named
textures still miss the hash table → 64-byte CDCDCDCD objects → REBASE-POISON.

### Still open
1. **Who inserts into hash table `0x82839E2C`?** (named .xtd load → register)
2. Why `82227428` never sees dispatch `0x20000000` (world draws).
3. Do not add more short-circuits.

### Census in tree
SETSTREAMS / DRAWWRAP / DRAWDISP / LOADGATE / TEXINIT / GFXINIT +
SUBMIT lr/streams/vb0 + INFLATE-SKIP head dump.

---

## SESSION 75C — LOADING GATE MAPPED (still no world draws)

### New census (log-only, soak `boot_stdout_c75d.log`)

| Marker | Hits | Meaning |
|---|---|---|
| `DRAWDISP-census` `sub_82227428` | **0** | real-draw dispatcher **never entered** |
| `LOADGATE-census` `sub_82178F38` | **0** | first gate inside SetStreams path **never entered** |
| `SETSTREAMS` / `DRAWWRAP` | 0 | bind + draw wrap dead (as 75b) |
| `sub_82420BA8` | 2 | dummy only (`lr=8217BB10`, streams=0) |
| `FRAME-END` / `NATIVE-PRESENT` | 3 / 4 | loading-screen HUD path healthy |

**Conclusion:** the process never leaves the loading-screen render path.
World-geometry submission (`82227428` → `0x20000000` branch → `8217A470`) is
unreached. Presents work because loading HUD uses the dummy submit.

### Inflate `-12` / magic `525DE064` (NOT the geometry gate)

Explore + soak (`INFLATE-SKIP` with `inPtr`/`head=` dump):
- Caller `sub_821BC140` sets `inLeft = bytesRead - 12` (header skip).
- Short/zero async read on `xarchive_audlo.rpf` (LO-res **audio**, 1.3GB)
  → `inLeft = -12` → we peek OOB and see random bytes (`525DE064…`).
- `525DE064` is **not** a format magic (0 hits in src/ + generated/).
- Do **not** treat INFLATE-SKIP as the root gate. The 8242FC1C wait is
  the healthy GPU-worker tick (`40004D7C`), not a load stall.

### What still blocks a working game

1. **Complete resource registration** so lookups stop creating CDCDCDCD
   64-byte texture objects (`prodLr=821853AC` / `8218542C`). That is the
   session-73 root: loaders never run, not a corruptor.
2. Only after that will `82227428` see the `0x20000000` dispatch type and
   stream bind can run → `DRAW_INDEXED` can go >0.
3. Optional later: short-read on audio archive (`821BC334`) if audlo load
   actually matters for boot completion.

### Ranked next probes

1. Texture registry fill: who should write obj+4 after `sub_82184F58`
   fallback create — find the loader that never runs (inflate/XCompress
   resource body → register).
2. Census `sub_825F48E8` (other SetStreams site) + `sub_82312FEC` mode/`0x1000` bit.
3. Do not add more short-circuits.

### Census left in tree
`SETSTREAMS`/`DRAWWRAP`/`SETSTREAMS-CALLER`/`DRAWDISP`/`LOADGATE` +
`SUBMIT` lr/streams/vb0 + richer `INFLATE-SKIP` head dump.
Ghidra/IDA MCP still optional; TUs + explore are enough for this path.

---

## SESSION 75B — DRAW_INDEXED MAPPED (still 0, but now we know why)

### Real vs dummy draw paths (TU-mapped + soak-proven)

| Path | Chain | Status |
|---|---|---|
| **Real geometry** | `sub_8217A470` → `sub_8241BE78` SetStreams (writes `dev+12748` count + VB descs at `dev+12756`) → `sub_8241C308` (needs r6=IB) → `sub_82420BA8` | **NEVER RUNS** (0 hits on all three) |
| **Dummy/HUD** | `sub_8217B7B0` (lr=`8217BB10`) → `sub_82420BA8` with **r5=0, streams=0** | the only 20BA8 hits in soak |

Evidence: `boot_stdout_c75.log` — `SETSTREAMS-census`=0, `DRAWWRAP-census`=0,
`SETSTREAMS-CALLER`=0, `SUBMIT-census #1/#2 lr=8217BB10 streams=0 vb0=[0,0,0]`.
Presents still land (FRAME-END=3, NATIVE-PRESENT=4). Still in loading.

**Conclusion:** `DRAW_INDEXED=0` is a **symptom of never leaving loading /
 never binding streams**, not a draw-builder bug. Next work is the loader
 path (inflate / resource init / CDCDCDCD initializers), not more GPU hooks.

### Census left in tree (log-only)
- `SUBMIT-census` now logs `lr=` + `streams=` + `vb0=[base,stride,size]` (`dev+12748/12756`)
- `SETSTREAMS-census` `sub_8241BE78`
- `DRAWWRAP-census` `sub_8241C308`
- `SETSTREAMS-CALLER` `sub_8217A470`

### Workflow notes (token-efficient RE)
- Generated TUs are ground truth; Ghidra/IDA MCP are optional xref tools.
- Ghidra headless launcher: `C:\Users\abdul\.config\opencode\ghidra-mcp\run-ghidra-mcp-headless.bat`
  (not running this session). IDA needs Edit→Plugins→MCP.
- Explore subagent for caller mapping; keep main window for decisions + edits.

---

## SESSION 75 — VMX128 TYPE-2 PACK LANDED (trap no longer kills boot)

### What was implemented (Route A, plan `docs/PLAN_VMX128.md`)

`vpkd3d128` SH=2 MB=1 ME=0 (PACK_TYPE_UINT_2101010) is now handled by
midasm hooks + a host function, not by XenonRecomp's `__builtin_debugtrap()`.

| Piece | Where |
|---|---|
| TOML hooks (4 sites) | `config/mcla_xenonrecomp.toml` `[[midasm_hook]]` @ `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` |
| Host impl | `src/vmx128_pack.cpp` `mcla_Vpkd3d128_type2` |
| CMake | `CMakeLists.txt` adds `src/vmx128_pack.cpp` |
| Reconstructed header | `src/ppc_context.h` (`tail -n +4` recipe, roundtrip `cmp`-clean) |

**Semantics (corrected from plan §2.1).** Type 2 does **not** take raw
[-1,1] floats. The guest pre-biases into the IEEE bits of a value near 3.0
(constant vectors at `0x820100F0` = `{3,3,3,3}` and `0x82010100` =
`{-2^-13,-2^-13,-2^-13,-3*2^-22}`; `vnmsubfp v0,v12,v13,v0`). Xenia's
`EmitUINT_2101010` clamps those bits to
`[0x403FFE01, 0x404001FF]` (XYZ) / `[0x40400000, 0x40400003]` (W) and ANDs
with `0x3FF` / `0x3`. Host lane order is reversed (D3DCOLOR convention):
`host.f32[0]=W, [1]=Z, [2]=Y, [3]=X`. Consumer after the trap
(`stvx128` + `lwz 156(r1)` through `VectorMaskL`) reads **`vD.u32[0]`** —
ME=0 write is sufficient.

**Emitted shape** (verified in `build/xr_hooks/ppc_recomp.14.cpp`):
```
mcla_Vpkd3d128_type2(v63, ctx.v0);
goto loc_821B3818;          // skips the dead __builtin_debugtrap()
```

### Regen reproducibility (plan §4 Route B step 3 — DONE)

Unmodified tool `.research/XenonRecomp/build-clang/XenonRecomp/XenonRecomp.exe`,
bare config filename from repo root, header `src/ppc_context.h`:
- **181/183** files byte-identical to `generated/ppc_xenon/`.
- `ppc_context.h`: trailing newline only.
- `ppc_recomp.10.cpp`: **hand safety patch inside `sub_8218CC70`**
  (indirect-branch targetFn/basePtr validation) that the recompiler does
  not emit. **Do not full-replace that file** or the session-38 null-dispatch
  AV returns.

Surgical install used: regen with hooks into `build/xr_hooks`, copy **only**
`ppc_recomp.14.cpp` over `generated/ppc_xenon/`. Everything else untouched.

### Soak evidence (session 75)

| Run | Result |
|---|---|
| `boot_stdout_vmx1.log` | exit ~35s on **new** early fatal `Resource '%s': %s` `legals/legals` (poison family B, lr=`825EF1DC`). **Not deterministic.** |
| `boot_stdout_vmx2.log` | 90s soak, still running when killed. FRAME-END=3 NATIVE-PRESENT=4 SWAP-COMP=9. **No `0x80000003`.** |
| `boot_stdout_vmx3.log` | 180s soak, still running. Same present counts. DRAW_INDEXED=0. No VMX128 trap. |

**Gate: no `0x80000003` in any session-75 soak.** The session-74 terminal
event is gone.

**NOT yet proven executed:** `VMX128-PACK` counter stayed 0 — the
vertex-fetch format-10 path was never reached. Hypothesis: in the session-74
guard run that trap was reached *because* of the fmtEnum=0 blit overrun
chain; with `BLIT-OOB-GUARD`=0 this run never enters that path. The hooks
are in the binary and will fire when it does. Do not claim the pack is
runtime-validated until a soak contains a `VMX128-PACK` line.

### Still open after this session

1. **`DRAW_INDEXED`=0** — still the real frontier. SUBMIT r5 empty; likely
   gated on loaders actually initializing surfaces (CDCDCDCD → use-sites).
2. **Poison family B** — `legals/legals` fatal at `825EF1DC` (soak1). Same
   class as meshtextures; `P5-MISSFIX` logs but does not skip this site.
3. **Type-2 unpack / type-5 unpack / vcmpbfp128** — still unimplemented;
   only needed if those paths are reached.
4. Continuous present soak past 4 — SWAP-COMP=9 matches the s74 baseline;
   not independently re-verified for more presents.

---

## SESSION 74 — HEAP AV STORM CLOSED (handoff item 1 CLOSED). NEW BLOCKER: UNIMPLEMENTED VMX128 OPS

### The corruptor was a blit overrun, not a poison pointer

Full chain, every step backed by a soak-log line (`boot_stdout_blit3.log` →
`boot_stdout_guard.log`):

1. `sub_82182FA0` (surface copy/update) calls the copy-rect wrapper
   `sub_824321E0` with **`dstW=512 dstH=640 fmtEnum=0x0 flag=1`**. Compare the
   7 legitimate mip-chain blits in the same run: `256×256 fmtEnum=0x30 flag=0
   tileShift=0..6`. `fmtEnum=0` is the invalid/uninitialized D3DFORMAT (falls
   through `sub_8240F2A8` to a 1×1-block default); `flag=1` selects the
   direct-copy path that skips `sub_82432D30`, leaving `origin=0`.
2. That reaches the tiled 2D blit `sub_82431A40` as `dst=CAEBB000
   rect=[0,0,512,640] fmt=0`. **The copy extent is purely RECT-driven**
   (`rows=y1-y0`, `per-row=x1-x0`) — it writes `need=0x50000` BYTES. The
   format/bpp in `r10` only sizes an internal staging alloc and is *never*
   multiplied into the copy size. (I got this wrong first and computed
   `w*h*4`; the observed gaps proved bytes, not dwords.)
3. The destination's tracked allocation is only **`size=0xA000`** → overrun of
   **`0x46000` (286 KB)**, landing exactly on the arena allocation frontier
   (`0xCAEC5000 − 0xA0000000 ≈ allocated=720,152,320`), i.e. on o1heap's
   **free** fragments. First probe hit: `PHYS-OVERRUN @ CAEC5004 gap=0x4`
   (dst end = `0xCAEBB000+0xA000`).
4. The bytes copied are `0xCDCDCDCD` — every `BLIT-SRC` descriptor dump is
   pure poison (one leaks ASCII `73746172 5F676C6F 7700` = **"star_glow"**),
   i.e. the source surface was never initialized. Fragment headers then read
   back as poison: `rax=0x337373737373737` = `0xCDCDCDCDCDCDCDCD >> 6`
   (`log2Floor(header.size/64)` in `unbin()`), `rcx=r11=0xCDCDCDCDCDCDCDCD`
   (`next_free`).
5. `unbin()` derefs poison → AV → `SehO1Allocate` swallows it, returns null →
   `MmAllocatePhysicalMemoryEx: FAILED ... allocated=720152320 cap=1610612160
   oomCount=0` (**not** a genuine OOM) → guest gets `E_OUTOFMEMORY` →
   `TEXCREATE-SC` converts it to success → guest derefs a null texture →
   fatal read of guest `0x00000000` → exit 139.
   Timing: overruns `21.933–21.943` → first o1heap AV `21.953` → first alloc
   FAILED `21.960`.
6. `o1heapDoInvariantsHold` never fired (0 hits) — it only validates
   bin/mask/diagnostics consistency and never walks fragment headers. That is
   why the poison went undetected until allocation time.
7. `HEAPHDR-STORE = 0`: no guest store touches `A0000000..A0000800`, so the
   `O1HeapInstance` (bins/mask) is never directly scribbled. Corruption is
   exclusively in fragment headers deeper in the arena.

**Correction to the session-73 handoff:** `0x82431D18` was recorded as "inside
`sub_82431A40` (kernel/XAM territory, filling big 0xCA-0xAF buffers — XAM debug
fill, harmless noise)". Wrong. Both `0x82431D18` and `0x82431A40` are
**memcpy** (`bl 0x823DA950`) inside a tiled 2D surface blit, and that blit *is*
the corruptor.

### Mitigation landed: `BLIT-OOB-GUARD`

`src/gpu_device.cpp` now owns `PPC_FUNC(sub_82431A40)` and
`PPC_FUNC(sub_824321E0)`. The former skips the guest blit body **only** when
the overrun is provable — i.e. the destination matches a tracked allocation
*exactly* and `rectW*rectH > allocSize`. Every legitimate blit (#1–#7) fits
its allocation and is untouched.

Measured, guard run vs the immediately preceding run:

| Marker | before | after guard |
|---|---|---|
| exit code | 139 (segfault) | **3** |
| `PHYS-OVERRUN` | 64 | **0** |
| o1heap AV | 34 genuine (+68 cascading) | **0** |
| `MmAllocatePhysicalMemoryEx: FAILED` | 34 | **0** |
| `TEXCREATE-SC` | 1 | **0** |
| `REBASE-POISON` | 61 | **229** (boot ran far past the old ceiling) |

Two blits were guarded, both `fmt=00000000`:
`dst=CAEBB000 size=0xa000 need=0x50000 overrunBy=0x46000 rect=[0,0,512,640] src=A02B6570`,
and `dst=CAEDD000 size=0x1000 need=0x8000 overrunBy=0x7000 rect=[0,0,256,128] src=A02B6790`.

**This is a labelled mitigation, not a fix.** The guard is only sound because
the allocation match is exact. The faithful fix is upstream: make the source
surface initialize (consistent with the session-73 rule — *killing CDCDCDCD =
making the loaders run, NOT more zeroing at use-sites*), so that `fmtEnum`,
`dstW`/`dstH` and the destination size agree. Still open: why does
`sub_82182FA0` pass `fmtEnum=0x0` with `512×640` against a `0xA000`
destination? `fmtEnum` is genuinely zero, not `0xCD` (`clrlwi r6,r3,26` of
`0xCDCDCDCD` would yield `0x0D`), so the field was zeroed or never set —
possibly a side effect of the `REBASE-POISON` short-circuit, whose count rose
61→229.

### Also fixed this session: `SehO1Filter` cascading AVs (real bugfix)

`src/kernel/heap.cpp`. The old guard
`if (gbase && fault >= lo && fault + 64 < lo + 0x100000000ull)` **wraps** for
wild pointers, so it passed for `0xFFFFFFFFFFFFFFF8` and the diagnostic dump
then dereferenced `p[-4]` *inside the filter* — 2 cascading AVs per real one.
Replaced with an unsigned offset test (`off = fault - lo; off < 0x100000000ull`)
plus an `off >= 32 && off + 40 <= 4GB` bound on the dump. Result: 102 AV log
lines → 34 genuine, 0 secondary; log shrank 22887 → 18492 lines.

### NEW #1 BLOCKER: unimplemented VMX128 instructions (host `int3`)

The guarded run ends 10 ms later on `code=0x80000003` — **EXCEPTION_BREAKPOINT,
not corruption**. XenonRecomp emits `__builtin_debugtrap()` for VMX128 modes it
does not implement, so the guest hits a host `int3`.

```
lr=821B37F4 r3=0000000C r4=00000003 r5=00000004 r6=00000001
r7=8200C0A0 r8=A02B6DB0 r9=00000003
 [ 4] __imp__sub_821B3548 +0x172B      [10] __imp__sub_826137A0 +0x638
 [ 5] __imp__sub_821A0800 +0x164C      [11] __imp__sub_82613970 +0x75
 [ 6] __imp__sub_821917A8 +0x3B80      [12] __imp__sub_82611738 +0xFD
 [ 7] __imp__sub_82192150 +0x2B5       [13] __imp__sub_8249CC00 +0x6A
 [ 8] __imp__sub_82192448 +0x29D
 [ 9] __imp__sub_82612B00 +0x1C5
```

Decoded (all verified against raw bytes + generated TUs):

- **The trap is `vpkd3d128 v63,v0,2,1,0` at guest `0x821B3814`**
  (`ppc_recomp.14.cpp:23432`). `lr=0x821B37F4` is **stale** — it is the return
  address of the last guest `bl 0x8218FEB8` at `0x821B37F0`. There is no failed
  comparison: the *successful* format-10 path runs into the unimplemented pack.
- **`r7=0x8200C0A0` is NOT a string.** It is a component-size-per-format dword
  table in `.rdata` (`2,4,6,8 | 4,8,12,16 | 4,4,4,0…`), loaded via
  `addi r24,r9,-16224`. A second table sits at `0x8200C0E0`. No ASCII within
  ±256 bytes.
- **`sub_821B3548` is not an assert printer.** It is a **VMX128 vertex-fetch
  instruction emulator** (guest `0x821B3548`–`0x821B3CB8`,
  `ppc_recomp.14.cpp:22989–24138`). Args: `r3`=fetch-descriptor struct
  (`+4`→sub-desc, `+16`→64-bit VMX128 instr held in `r31`), `r4`=vertex index,
  `r5`=const floats, `r6`=byte index. `r3=0xC` at the trap is the **return
  value of `sub_8218FEB8`** (a bitfield extractor, `ppc_recomp.11.cpp:7603`),
  not an error code.
- Caller `sub_821A0800` (`ppc_recomp.12.cpp:27277`) loops over fetch
  instructions. `sub_821917A8` (`ppc_recomp.11.cpp:11652`) reaches it only via
  `mtctr/bctrl`. `sub_82192448` allocates a 1184-byte object. Subsystem =
  **CPU-side software fetch-shader / vertex-format unpack** — which is very
  likely upstream of priority #2 (`DRAW_INDEXED`=0).
- **Zero existing host hooks** on `821B3548` / `821A0800` / `821917A8` /
  `82192150` / `82192448` / `821B37F4`. All are free to own.

**Census of the gap** (`grep -B1 __builtin_debugtrap()` over `generated/`, and
independently by scanning `build/cache/mcla_pe.bin` `.text` for the VMX128
opcodes — the two agree):

| Instruction | Trap sites | Guest sites | Status |
|---|---|---|---|
| `vupkd3d128` UIMM=4 (SH=1, 2 shorts) | — | 443 | implemented |
| `vupkd3d128` UIMM=20 (SH=5) | **94** | 94 | MISSING — first at `0x822F1B80`, all in `0x822Fxxxx` |
| `vupkd3d128` UIMM=0 (SH=0, D3D color) | — | 1 | implemented |
| `vupkd3d128` UIMM=8 (SH=2) | **1** | 1 | MISSING — `0x821B43D8` |
| `vpkd3d128` SH=0 MB=1 (D3D color) | — | 58 | implemented |
| `vpkd3d128` SH=5 MB=2 ME=2 (float16_4) | — | 47 | implemented |
| `vpkd3d128` SH=5 MB=3 ME=0 | — | 20 | emits float16 path (warns, no trap) |
| `vpkd3d128` SH=2 MB=1 ME=0 | **4** | 4 | MISSING — `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` |
| `vcmpbfp128` | **1** | 1 | MISSING — `0x825CEA2C` |

Note the two `vpkd3d128 SH=3 MB=1 ME=3` / `SH=0 MB=3` variants appear in the
raw scan but produce **no** debugtrap in `generated/` — they are either outside
a recompiled function or misdecoded data. Don't chase them.

**Field layout (derived from `thirdparty/disasm/ppc-dis.c:2517-2536`):**
`vupkd3d128` operands are `{VD128, VB128, UIMM}` where UIMM = bits 16-20.
XenonRecomp switches on `UIMM >> 2`, i.e. **bits 18-20 = the same `SH` field
`vpkd3d128` uses** (`VD3D0`), and bits 16-17 = `MB` (`VD3D1`). So
`UIMM=0/4/8/20` ⇔ `SH=0/1/2/5`. **`SH=5` is already the float16_4 *pack* mode,
so `SH=5` unpack is almost certainly float16_4 unpack** — that is the natural
counterpart for the 94 missing sites and the single highest-value thing to
implement. `SH=2` remains unidentified for both directions; all 5 `SH=2` sites
live in the vertex-fetch emulator, so read that module's branches (it
dispatches on a 4-bit format field, `(instr>>52)&0xF`, with `cmpwi cr6,r9,10`
guarding the trapping path) rather than guessing.

**Where to implement.** `.research/XenonRecomp/XenonRecomp/recompiler.cpp`:
`case PPC_INST_VPKD3D128` at :2011, `case PPC_INST_VUPKD3D128` at :2203,
`case PPC_INST_VCMPBFP128` at :1847 — each has a `default:` that emits the
debugtrap. Config: `config/mcla_xenonrecomp.toml` (full recompile, 179 TUs).
Entry point: `XenonRecomp [input TOML] [PPC context header]`.

**BLOCKERS on that route, verified this session:**
- `.research/` is **gitignored** (`.gitignore:22`) — any XenonRecomp edit is
  local-only and will NOT survive a clone. If you patch the recompiler, copy the
  patch into `docs/` or `tools/` as a `.patch` file and commit *that*.
- **No XenonRecomp binary exists.** `build/` and `build-msvc/` have CMake caches
  and `build.ninja` but no `.exe`. You must build the tool first
  (`rebuild_clang.bat` exists at `.research/XenonRecomp/`).
- **Before regenerating, prove reproducibility:** run the unmodified tool into a
  temp `out_directory_path` and diff against `generated/ppc_xenon`. If it does
  not reproduce byte-for-byte, do NOT regenerate — the diff would swamp your
  change and could regress boot. Fall back to per-function `PPC_FUNC` overrides
  of the affected guest functions instead.

Cheaper alternative if regen is not reproducible: the 5 `SH=2` traps and the
1 `SH=5` unpack trap in `0x821Bxxxx` are all in the vertex-fetch emulator's few
functions — those specific functions can be overridden host-side. The 94
`SH=5` sites in `0x822Fxxxx` cannot reasonably be hand-rewritten.

### Unchanged after the guard
`DRAW_INDEXED`=0, `SUBMIT`=14, `FRAME-END`=2, `NATIVE-PRESENT`=4,
`SWAP-COMP`=9, `INFLATE-EMPTY`=8.

---

## SESSION 73 — ROOT CAUSE OF `0xCDCDCDCD` FOUND (handoff item 1 CLOSED)

The "corruptor" does not exist. The 0xCD is **guest-native fill-on-alloc**,
compiled into the shipped image:

1. **Fill mechanism (static + runtime proven).** The tiny-slab allocator
   `sub_821DE9D8` memsets every returned element before handing it out:
   common tail at `loc_821DEAFC` (ppc_recomp.20.cpp): `li r4,205; lhz
   r5,4(classHead)  # elemsize; mr r3,node; bl memset(0x823D9890)` — on the
   freelist-pop path AND the fresh-slab refill path. Runtime watch
   (`CDCD-FILL ... lr=821DEB0C`) confirms it live. Two startup fills of the
   1352-byte global at `0x8283C5E0` exist too (`sub_8218C9A8` body, memset
   returns `0x8218C9D4`/`0x8218CCCC`; re-armed at runtime by `sub_8217A068`).
   The heap also free-fills with `0xDD` (seen in POISON-DUMP).
2. **Same fill runs on retail HW** (it is in the shipped XEX). So a
   `CDCDCDCD` field read at a use-site = **a field its owner never
   initialized** — i.e. an initializer/loader that runs on HW but not in our
   emu. Stop hunting a writer; hunt the skipped init step.
3. **Poisoned object family A — texture objects (meshtextures fatal).**
   `sub_82185368`/`sub_82185410` are find-or-create-by-name: on lookup miss
   they `sub_82130528(64)` (RAGE small-alloc → 64-byte element, 0xCD-filled)
   and init via `sub_82184F58` (compares name to "none"/"nonresident",
   builds a 32×32 fallback texture, stores handle at obj+32) — **never
   writes obj+4**, the resource-id field later rebased by
   `sub_821B5A60` (consumer `sub_821D2970`, lr `821D29A0`). Producer LRs
   captured in soak: `821853AC`/`8218542C`.
4. **Poisoned object family B — 112-byte resource objects (A0106xxx
   params).** POISON-DUMP shows records `vtable=0x820131A4 @+0, body +4..+5F
   all CDCD, trailing 0xDD free fill`. The vtable sits next to the string
   `Resource '%s': %s (ptr=%p)` (0x82013167). Ctor writes only the vtable;
   the loader that fills the body never runs in our emu.
5. **Conclusion:** killing CDCDCDCD = making the **loaders run** (real
   XCompress inflate, real texture creation/registration) — NOT more
   zeroing at use-sites. The existing REBASE-POISON / P10-PRE zeroing stays
   as boot life-support until then.

### New instrumentation left in tree (all census-only, no behavior change)
- `TSLAB-ALLOC` / `TSLAB-OWNER` (patches.cpp, `sub_821DE9D8` +
  `sub_821C29A0` wrappers): element → (caller LR, elemsize) rings;
  `mcla_SlimTslabFind` (patches.h) resolves producer at use-sites.
- `CDCD-FILL` value watch (`RegisterGuestWatchValue(0xCDCDCDCD)` in
  boot_host.cpp; census in gpu_cp.cpp `PageWatchOnWrite`). `WriteU8`/`WriteU16BE`
  now route byte/halfword 0xCD stores into the watch for registered ranges.
- `PARAM-STORE` probe ranges (A0106000-A0107000, A0197E00-A0197F00) +
  `POISON-DUMP` record dump on first 3 REBASE-POISON hits.

---

## What worked before (session 72 baseline, unchanged this session)

| Milestone | Evidence |
|-----------|----------|
| Boot past KDELAY stall | `SLEEP60270` count 0 |
| Past meshtextures fatal | `REBASE-POISON` + D890 skip |
| Ring-B consumers drain | `PUSH pIdx` 0→1 |
| D3D12 backend up | RTX 3070, 1280×720, test pipeline |
| **Native present** | `FRAME-END` ×9+, `NATIVE-PRESENT` ×6 |
| Depth backup fatal gone | `TEXCREATE-SC` ×1, fatal count 0 |

**Not working (as of session 74):** the AV storm is gone but the process now
dies in ~1s on an unimplemented VMX128 instruction (see SESSION 74, priority
1); `DRAW_INDEXED` = 0 (empty VB/IB); `CDCDCDCD` still poisons object fields.

---

## Architecture (read before changing hooks)

- Guest PPC runs from `generated/ppc_xenon/` (never edit). Image loaded
  from `build/cache/mcla_pe.bin`.
- Host hooks: one owner per guest address (Golden Rule 1). Check
  `PPC_FUNC` / `GUEST_FUNCTION_HOOK` / `SetFunction` before adding another.
- Guest memory: `mcla::kernel::GuestMemoryHeap` (checked BE accessors).
  `WriteGuestU32` → `GuestMemoryView` (page-watch).
- Physical o1heap arena: guest VA **`0xA0000000`**–`0xFFFFFFFF` (1.6GB).
  Pool16 slabs live inside it (`A0014xxx`).
- Task-join table: count @ `0x8283D1A8`, entries @ `0x8283D1C4`, stride 28,
  idx = `(count-1) & tag`. Wait word = `entry+12`.
- XCompress magic: `0x0FF512EF`. Unknown magic → skip-fatal, emit 0.

---

## Short-circuits in tree (do not stack more without root cause)

| Hook | File | What it does |
|------|------|----------------|
| KDELAY-SC | `gpu_device.cpp` E98 | force `pub0` when wait would spin |
| FENCE-SC + ClearTaskJoinBusy | `gpu_device.cpp` | pre-release ev + clear `entry+12` |
| TASKJOIN-SC | `gpu_device.cpp` `sub_821BD220` | main-thread force busy=0 |
| REBASE-POISON | `task_dispatch_trace.cpp` `sub_821B5A60` | zero `*param` if `0xCD` byte |
| P10-PRE | `task_dispatch_trace.cpp` D890 | skip fatal on poison id, return 0 |
| INFLATE-SKIP / EMPTY | `gpu_device.cpp` `sub_821D5E10` | no XCompress → emit 0 / bail |
| TEXCREATE-SC | `patches.cpp` `sub_82177EB0` | r3<0 → 0 (legacy RT unused) |
| SEH o1heap | `heap.cpp` `SehO1Allocate/Free` | AV → null / no-op |
| pow2 align | `heap.cpp` AllocPhysical | round alignment up |
| NtReleaseSemaphore | `imports.cpp` | `GetKernelObject` like Wait |
| **BLIT-OOB-GUARD** (s74) | `gpu_device.cpp` `sub_82431A40` | skip blit when `rectW*rectH` provably exceeds the exact tracked alloc — this is what closed the AV storm |

**Wake-loss fix is a real bugfix** (create/wait/release wrapper mismatch).
The rest are boot-life support until `CDCDCDCD` is killed.

---

## Next steps (priority order — updated session 74)

### 1. Unimplemented VMX128 ops (THE remaining blocker)
> **A full execution plan is written and ready: [`docs/PLAN_VMX128.md`](PLAN_VMX128.md).**
> It resolves the instruction semantics (against Xenia), censuses every trap
> site, ranks three implementation routes and lays out staged soak gates.
> Start there — do not re-derive the semantics.

The guest dies on a host `int3` from `__builtin_debugtrap()`. Full census,
field layout, trap address and the three route options (patch-and-regen vs
midasm-hook vs host override) are in **SESSION 74** above and in the plan. Semantics are now **confirmed**, not conjectural: the mode selector is
`type = IMM >> 2`, so `vpkd3d128 SH=2` is a **2_10_10_10 pack** and
`vupkd3d128 UIMM=20` is a **FLOAT16_4 unpack**. Fix order is
`vpkd3d128 SH=2` first (4 sites — this is what actually kills the boot, at
`0x821B3814`), then re-triage; only reach for the 94 FLOAT16_4 sites if the
boot gets as far as `0x822Fxxxx`.
**Prove regen reproducibility before regenerating** (plan §4 Route B step 3).
That gate is **unblocked as of session 74c** — plan §7b items 4 and 5 give a
byte-exact `src/ppc_context.h` reconstruction recipe (`tail -n +4
generated/ppc_xenon/ppc_context.h`, round-trip `cmp`-clean) and note that
`config/mcla_xenonrecomp_baseline.toml` already exists and is correct (one line
differs from the authoritative config). `build/xr_baseline/` is **empty** — a
prior run failed to produce output; fix the invocation (bare config filename from
the repo root), do not re-derive the config or hunt for the header again.

### 2. Real draws (P5')
- `SUBMIT-census sub_82420BA8` has `r5=0` (VB/IB empty). Find who fills
  `r5`/`r6` in the device-boundary path. `DRAW_INDEXED` must go >0.
- Likely gated by (1): the trapping module *is* the CPU-side vertex
  fetch/format unpack (`sub_821A0800` loops fetch instructions). Expect
  vertex data to start flowing once those instructions run.
- Then pixel-hash validator (`phase3_validator`).

### 3. Upstream root cause of the blit size mismatch (retire `BLIT-OOB-GUARD`)
Why does `sub_82182FA0` pass `fmtEnum=0x0` with `dstW=512 dstH=640` against a
destination allocated as only `0xA000`? The good blits allocate exactly
`w×h×bpp` (256×256×4 = `0x40000`); `0xA000` cannot be expressed as
`512×640×bpp` for any bpp, so the *destination* was sized for something else —
either the dims/format are stale or the buffer was under-allocated. Trace the
allocator of `dst` via `MclaPhysAllocInfo`'s `allocLr` field (now logged as
`allocLr=` on every `BLIT-CAP` line).

### 4. Continuous presents — mechanically closed (commit `079f94a`), unverified
- Root cause was the swap-table handshake: dev+21624/21628 counters, 2 slots
  reserved per kick (guest writes ZERO, HW fills timestamps LE), completion
  processor `sub_824286A0` advances only when slot `(completed+1&7)+16` is
  non-zero, gated by rlwinm-bit26 of `sub_82458030` (kernel-populated status
  chain our emu never wrote). Both emulation points live in gpu_device.cpp
  (`SWAP-STATUS` / `SWAP-FILL` / `SWAP-COMP` log lines).
- The guard run only reached `NATIVE-PRESENT`=4 before the VMX128 trap, so a
  long present soak is still outstanding. Re-verify after (1).

### 5. Poison family B (lower priority, now understood)
- The 112-byte vtable objects (`vtable 0x820131A4`) get their body from a
  loader that never runs. Use `TSLAB-OWNER`/`PARAM-STORE` in a soak to find
  who allocates them (owner LR) once the inflate path is fixed; the
  initializer is probably upstream of the same data dependency.

---

## How to run

```bat
cd /d "E:\mcla pc"
ninja_build.bat
build\mcla.exe
```

Logs: `boot_stdout_*.log` in repo root. Kill leftover `mcla.exe` before
relink (handoff rule).

**Git Bash on Windows — gotchas that cost real time this session:**
- `cmd.exe /c ninja_build.bat` **silently does nothing** (exit 0, only the cmd
  banner) because Git Bash path-converts `/c`. Always use:
  `MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat`
- The tool rejects any command containing `//F`, `//` or `"// ..."` as a UNC
  path. So `taskkill //F //IM mcla.exe` fails — use
  `cmd.exe /c "taskkill /F /IM mcla.exe"`. Likewise a `grep -o "// pattern"`
  trips it; match without the leading `//`.

**Decoding guest addresses in the image.** `build/cache/mcla_pe.bin` is an
**identity-mapped memory image**: `file offset = VA − 0x82000000`. The PE
*section table* disagrees (it claims `.text` PRD `0x12C800` for VA
`0x82130000`) and following it lands you in zeros — file `0x12C800` is all
zero, while file `0x1B3548` holds `sub_821B3548`'s real first instructions.
Instruction words are **big-endian**.

**IDA MCP:** `powershell -File tools\start_idalib_mcp.ps1` then
`check_connection`. Do not use SSE `idalib_server.py` with the proxy.

**Ghidra:** already connected (`mcla_pe.bin`). Prefer generated TUs as
ground truth; IDA function starts on this raw bin are unreliable.

---

## Do not

- Do not pop stash `session33-audlo-forensics-...` (regresses boot).
- Do not edit `generated/`.
- Do not add a second hook on an address that already has `PPC_FUNC`.
- Do not copy raw non-XCompress bytes into inflate output (causes
  `0x7E780000` AV).
- Do not claim a gate without a soak log line.

---

## Evidence files

| File | What it shows |
|------|----------------|
| `boot_stdout_blit3.log` | pre-guard run: `BLIT-CAP`/`BLIT-SRC`/`BLITWRAP` census, the `nearestAlloc=CAEBB000 size=0xa000 gap=0x4` smoking gun, 64 `PHYS-OVERRUN`, 34 genuine o1heap AVs, exit 139 |
| `boot_stdout_guard.log` | **post-guard run: exit 3, zero PHYS-OVERRUN, zero o1heap AV, zero alloc FAILED**, 2 `BLIT-OOB-GUARD` hits, `REBASE-POISON` ×229, terminal `0x80000003` VMX128 trap |
| `boot_stdout_cdcd74.log` | REBASE-POISON prod=Y prodLr=821853AC/8218542C; CDCD-FILL LR census |
| `boot_stdout_cdcd75.log` | PARAM-STORE probe: A0106xxx written with real param data (lr=821CB1C8) |
| `boot_stdout_cdcd76.log` | POISON-DUMP records (vtable 0x820131A4, body CDCD, 0xDD free fill); INFLATE-EMPTY ×1663; AV rva 0xF3868 |
| `boot_stdout_texsc2.log` | depth fatal 0; AV storm (session 72) |
| `boot_stdout_rootcd.log` | watch armed; INFLATE-EMPTY; no A000 write (session 72) |
| `docs/BOOT_HANDOFF.md` | full session trail |
| `audit-clean/HONEST_ASSESSMENT.md` | why the tree looks messy |

**Session-74 instrumentation left in tree** (all census-only except the guard):
- `BLIT-CAP` / `BLIT-SRC` / `BLIT-OOB-GUARD` — `gpu_device.cpp`,
  `PPC_FUNC(sub_82431A40)`: dst/src/pitch/fmt/rect/wh/srcOrigin/lr plus
  `alloc`/`size`/`allocLr`/`exact`/`need`/`overrunBy`, and an 8-dword dump of
  the source descriptor.
- `BLITWRAP` — `gpu_device.cpp`, `PPC_FUNC(sub_824321E0)`: the copy-rect
  wrapper's dstW/dstH/tileShift/fmtEnum/flag/dstBase/origin/src/lr + alloc.
- `PHYS-OVERRUN` enrichment — `gpu_cp.cpp` `PageWatchOnWrite`: now also
  reports the nearest allocation below the faulting address and the gap.
- `mcla::kernel::MclaPhysAllocInfo(addr,&base,&size,&lr,&exact)` and
  `MclaPhysNearestAllocBelow` — `imports.cpp`, declared in `kernel/memory.h`.
  `MmTrackAllocationSize` now also records the requesting guest LR in
  `s_allocLrMap`. This is what makes an overrun attributable to the site that
  under-allocated the buffer.
- `SehO1Filter` — `heap.cpp`: wrap-safe guest-address test + bounded fragment
  header dump (`[fa-32] … [fa+24]`).

## Task board
Check `task` list: ~~T39 (CDCDCDCD root)~~ root-caused s73; ~~T40 (heap watch
→ AV storm)~~ **CLOSED s74** (blit overrun found, `BLIT-OOB-GUARD` landed);
**NEW: implement `vupkd3d128`/`vpkd3d128` VMX128 modes (s74 #1 blocker)**;
T36 (long soak DRAW_INDEXED), T28 (pool16/UAF — superseded by the
fill-on-alloc finding), T9/T18 (optional IDA dual-source).

---

## SESSION 75l — DICTS ARE NOT EMPTY SHELLS; RECOMPILER GAP FOUND + FIXED

### Environment gotcha that cost an hour
`build/game_data/mcla extracted cache/` **vanished** (junction target or manual
delete) → `app.cpp:90` skipped `vfs.Initialize` → every `game:\*.rpf` open
returned NAME_NOT_FOUND → guest fatal `Cannot load archive
'game:/xarchive_audlo.rpf'` (lr=822C4A44) at boot. Recreate the dir (empty is
enough to boot; boot only opens the 2 real RPFs + raw device) and VFS returns.

### Recompiler gap: `sub_8221D9D0` had no body (build was broken)
- Committed `generated/` tree: `ppc_recomp.26.cpp` ends with a bogus 4-byte
  "function" at `0x8221D9CC` (`.long 0x0`) — the tool's function discovery
  broke there and swallowed the real function at `0x8221D9D0`.
- Mapping table referenced `sub_8221D9D0` (vtable data xrefs at
  `0x820249d0`, `0x820249f0`, `0x821085e0`) but no TU defined it → link
  error. Also `ppc_recomp_shared.h` was missing
  `PPC_EXTERN_FUNC(sub_82216B98);` (its neighbors have it).
- Fixes: added the extern (one line, `ppc_recomp_shared.h:6728`) + a
  log-once census body `PPC_FUNC(sub_8221D9D0)` in `src/patches.cpp`
  (MISSING-BODY). **MISSING-BODY = 0 in the 75l soak** — never dispatched.
  Partial decode if it ever fires: it stores `0x82023AC8` at obj+0, calls
  `0x821D2018` (mid-function entry inside IDA-merged sub_821D1FA0), then
  `0x8212FE88` when (r4&1)==0. Destructor/ctor-flavored; full reconstruction
  only if it ever hits.

### The big finding (enriched DICTFACT census, soak `boot_stdout_dfact.log`)
`sub_8218BF20`'s r4 is a **live deserialization stream slot** (fixed 40-byte
slot array at `0x82860C18`, allocator `sub_821BDDE8`, per-slot 4KB buffer at
`0x82860DF8 + i*0x1000`, free-slot count at `0x827C8874`). Slot state at
dict-build time:
```
#1  buf=82860DF8 pos=0322 end=048A left=360 head='05 '   ← length-prefixed NAMES
#2  pos=032C head='0C '  #3 pos=033D head='0B '  #4 pos=034D head='12 ' ...
```
The factory **consumes real name data** (head bytes are string lengths:
5,12,11,18,9,10,5,16,24,24) and creates **named entries with NULL values**
(`stw r30,4(r3)` … with r30=0 in the TU). So dicts are not empty shells —
they are named registries whose **texture-value fill step never runs**.

**75l soak (3 min, empty cache):** DICTFACT/TEXDICT-CALLER ×**1550** (more
than gtex's 100/90s — the full cache was feeding something), GLOBTEX-BOOT ×1,
MISSING-BODY ×0, STREAMTEX/UILOAD/DICTREQ still ×0, heartbeat healthy.

### Next (ranked)
1. Find who should write entry+4..+30 (texture value) after the factory —
   a second deserialization pass over the SAME slot (pos keeps advancing:
   69 bytes still left after #10) or a lazy fill at first lookup.
2. Dump the actual NAME strings (extend census to read `len` bytes at buf+pos).
3. Investigate what the full extracted cache used to feed (1550 vs 100
   DICTFACT) — consider re-extracting the cache.

---

## SESSION 75m — THE "DEAD LOADERS" ARE DEAD ON HARDWARE TOO; NEW MODEL

### Instrumentation added (all log-only)
- `DICTFACT-census` now dumps the pending **name string** at the stream cursor
  (format proven: u8 len + name + u32 hash). DICTSLOT-ALLOC on the slot
  allocator 821BDDE8. GATE-PROBE (gpu_cp.cpp VDRAIN census) logs
  `[0x828309A0]` every 100 polls: **value = A005D340, a live object, from
  early boot** — the "DLC gate" flag is NOT the blocker.
- Soak: `boot_stdout_names.log`, `boot_stdout_gate.log`.

### Finding 1: the dict factory is the SHADER pipeline
The 1550 "empty" dicts deserialize names like `draw`, `zprepass_draw`,
`shadowBlend_draw`, `multilight_drawskinned`, `CopyDepth` — **shader
technique names**. 8218BF20/8218B000 = pgDictionary name-table pass
(likely COMDAT-folded across T). Shader dicts WORK. The texture-dict
question is a separate path.

### Finding 2: file I/O dies after one 4MB burst
NFS-CENSUS[Read]: sequential 32KB reads from xarchive_cache.rpf
(0x800 → ~0x3D8000) then **zero reads for the rest of a 90s soak**. Frame
loop stays healthy. The game never queues another request.

### Finding 3: the message tables are ORPHANED IN THE RETAIL IMAGE
The streaming/UI "loaders" (8218C1C0 dict-list, 8218CD10/8218D120
requesters, 821FD6B0 STREAMTEX, 822012E8 UILOAD) are registered in
(handler, msgid) tables in .rdata (e.g. streaming table at 0x82104B10,
305-entry UI table at 0x82107628). Proof of orphaning:
- **Zero** data pointers into these tables anywhere in the image.
- **Zero** `addis rX, rX, 0x8210` in the entire .text — no code ever
  computes any address in the 0x82103-0x8212A table region.
- Zero direct `bl`s to 821FD6B0/82216B98/8218D120 etc. (they were only ever
  reached via these tables through the dispatcher).
- Zero CONFIG-DISPATCH rejections in soak: emitted code never dispatches to
  the unmapped functions either.
**Conclusion: on real hardware this message path is dead too.** Session
75i's "real loaders never run" is hardware-accurate, not an emu bug. The
GLOBTEX-BOOT workaround is legitimate, not a crutch.

### New model of the texture pipeline
grcTexture objects are created and name-inserted (ctor 82185648 → insert
821854C8) by the **RAGE resource load path**: pgRscBuilder-style load →
XMem/XCompress inflate (our hook sub_821D5E10) → resource body deserialize →
per-resource grcTexture ctor. The 5 natural TEXINSERT2 hits (uiOverlay etc.)
came through it. The pipeline is not dead — it is barely exercised because
almost nothing requests resources yet.

### Next (ranked)
1. **Trace the resource-load path**: census callers of the inflate hook
   (`sub_821D5E10`, lr=821D5EBC inside InflateBegin), what resource bodies
   it produces, and why only ~3 grcTexture ctors ever run.
2. Why do reads stop at ~4MB? What should issue the next batch of reads
   (the city/vehicle resource loads)? Check the task/streamer request queue
   state in a soak.
3. The 0x821D9D0 recompiler gap (MISSING-BODY stub) — still never hit.

---

## SESSION 75n — BOOT LOAD MACHINERY VERIFIED WORKING; STALL IS UPSTREAM

### Instrumentation changes
- `INLINE-EXEC sub_821BC140` node dump replaced with REQDUMP (16 dwords of
  the request slot + ASCII-name scan). Old NODE walk was for a different
  descriptor layout (garbage @50000000).
- XamContentGetDeviceData / XamContentCreateEnumerator / XamEnumerate now
  log. **Result: the guest NEVER calls them** — save-device enumeration is
  not part of the stall.
- INFLATE hook logs a guest stack walk. Frame convention for the recompiled
  code: saved LR of the function owning frame sp is at `[back_chain - 8]`
  (mflr r12; stw r12,-8(r1); stwu r1,-X(r1)).

### Runtime call chain of the boot loads (proven)
```
producer sub_821BC868 (lr=821BC8F0)  → pushes request slot, releases q+0x616C
worker  sub_821BC910(devIdx)         → single-entered INFINITE loop (RINGB-
                                       CONSUMER ENTER ×1, never returns)
  └─ exec  sub_821BC140(reqSlot)     → 3 executions, lr=821BC998
       └─ inflate steps (15×, lr=821BC380, shared state st=006D8F20)
```
- Queue base is **0x82849518** (+ idx*0x6174) — my first decode said
  0x82749518 (lis sign error); session-16/20 hooks had it right.
- Producer pushed **exactly 3 requests** (slots @+0x614/+0xC28/+0x123C),
  all at boot, then silence for the rest of the soak.
- REQDUMP: slots are **scatter-gather transfer descriptors** —
  `[flags, 0x50000000, dst, size, ...]` triples (dst 0x5/0x6xxxxxxx,
  src 0xB7xxxxxx, sizes 0x80000/0x20000/0x8000 matching the inflate
  outputs). No resource names in the slot.

### Conclusions
1. Boot load machinery (queue, worker, executor, inflate, ~4MB reads, 15
   resource bodies, 1550 shader dicts) is fully functional.
2. The stall is UPSTREAM: the game-logic init sequence never issues the
   next request batch (UI textures, world data). Find the init-stage
   completion callback that should run after the 3 boot transfers and why
   it doesn't advance (callback fnptr is in the slot/executor tail —
   census next).
3. 0x821BC140's dual identity (task executor vs DMA scatter-gather) needs
   one clean decode; session 19's node layout applies to another op class.

### Next (ranked)
1. Decode the completion path of the 3 boot transfers (executor tail after
   the last inflate step — what callback/state advances?).
2. Census the producer's caller (lr=821BC8F0 → wrapper inside 0x821BC868's
   span) — walk one more frame to name the subsystem that requested boot
   data, then find what ITS next stage is.
3. Old queue item: who should enqueue UI/world texture work — note the
   75m finding that message tables are orphaned; requests must come from
   direct calls (like the boot batch did).

---

## SESSION 75o — BOOT REQUESTS NAMED; TASK CHAIN CAPTURED; IDA-XREF WARNING

### Corrections to 75m
- The message system WORKS: boot loads arrive as message 0x40003803 →
  handler sub_821E5FD0 (table entry @0x821071B0). The "orphaned tables"
  conclusion was wrong — the dispatcher reaches them via a runtime-registered
  manager (wiring still unmapped, but not needed).
- IDA xrefs on this raw bin are largely FICTION. Example: IDA claimed 30 code
  callers of sub_821E5F48 incl. 8× sub_823772F8; ground-truth bl-scan of the
  image shows only 4 real call sites, all inside emitted functions. Always
  verify IDA xrefs with a raw bl-scan before acting on them.

### The 3 boot requests (REQ census, named!)
| # | name (a0) | type tag (a1) | requester lr | chain |
|---|---|---|---|---|
| 1 | `meshtextures` | `#td` (texture dict!) | 821E6054 | 821FE4FC → …task… |
| 2 | (stack) | `#sf` | 827201B8 (kernel-side 0x82720140) | |
| 3 | `trash` | `#rn` | 8224C2F4 | 82304B3C → 822F0CB8 → … |

`meshtextures#td` = the texture dictionary behind the old "meshtextures"
fatal. All 3 COMPLETE (COMPLETE sub_821C31B8 ×3, lr=821BC53C = executor tail
→ slot+1540 gate → vtable+88 virtual). Joins exit cleanly (TASKJOIN-SC +
FENCE-SC active as designed).

### Runtime task chain (all EMITTED, read TUs directly)
```
sub_821BD7C0 (task submit)  [TU15]
sub_82131790 / sub_82131508 (task core, module start)  [TU0]
sub_822C2EA8 (task glue)  [TU45]
sub_822F0C18 (boot init step)  [TU50]
sub_823047D8 (boot init step)  [TU51]
sub_821FDED8 (UI/streaming module requester)  [TU23]
```

### Next (ranked) — everything is emitted now, plain TU reading
1. Read `sub_823047D8` (TU51) + `sub_822F0C18` (TU50): the boot init tasks.
   Find what they do after the 3 loads complete and what gates the NEXT
   task batch (state var, tick, callback table).
2. Census sub_821FDED8: it loaded meshtextures#td; does it have a follow-up
   stage that never fires?
3. Keep in mind: only 3 REQ ever fire; STRMWORK worker idles; reads stop at
   ~4MB. The init sequence simply never enqueues its next batch.

---

## SESSION 75p — ROOT CAUSE OF THE BOOT STALL: THE SECOND LOAD BATCH NEVER RECEIVES INPUT

### The chain, fully traced this session
1. Boot batch 1 loads fine (meshtextures#td / #sf / trash#rn → inflate →
   scatter-gather copy → COMPLETE ×3).
2. The dict-body deserialization then enqueues a **batch of ~15 sub-streams**
   (sequential outPtrs 0xB7981000/0xB79A1000/…, outLeft=0x20000 each — the
   content INSIDE meshtextures#td).
3. Each stream's input refill is a **virtual read (vtable+28) on the source
   stream object** [r28+8] inside the executor (sub_821BC140, refill loop
   loc_821BC2D4). That read **returns 0 bytes instantly, forever**. No new
   NFS-CENSUS reads appear for this batch — the source is NOT the packfile.
4. IO-credit gate: refill waits `while [0x827D74E0] <= 0` (Sleep 100 via
   sub_821C91B8) — but credits=1 (>0), so the sleep is SKIPPED and the loop
   spins HOT on the zero-returning read. Retry counters 1→200 in one
   millisecond.
5. Session-73's INFLATE-EMPTY bail then marked every stream complete-empty
   (produced=0) — **the emu was aborting the boot's own next load batch.**
   On hardware the read returns data; here it returns 0 → stall.

### Fixes/corrections landed
- INFLATE-EMPTY no longer kills fresh streams (consumed==0/produced==0 →
  INFLATE-PENDING, state untouched, up to 200 retries ≈ 20s) before bailing.
  Correct but not sufficient: the read itself returns 0.
- NtReadFile now signals the async completion event (was `(void)event`) —
  correct per X360 semantics; this path doesn't use it (RD-EVT=0) but other
  async readers may.
- Counter address corrected twice (sign/arith): credits live at
  **0x827D74E0**, value 1 at stall time. GATE-PROBE logs it.
- NOTE: "meshtextures#td" — the #td texture dictionary whose textures never
  deserialized is the direct ancestor of this stall.

### Next (ranked) — the read returning 0 is THE thread
1. Identify the source stream object ([r28+8], set up per-slot by the worker
   sub_821BC910): its vtable and the read method at vtable+28. Candidates:
   an uninitialized memory-stream (source buffer empty), or a bogus
   recompiler stub (.long 0x0 body) as the read method.
2. r28 is callee-saved (not in PPCContext) — get the object either from the
   worker's slot setup code (sub_821BC910 writes the per-slot context before
   bl 821BC140) or from the executor's saved-register area on the guest stack.
3. If the read method is a recompiler-gap stub: this is the second confirmed
   gap (after sub_8221D9D0) — consider the regen route (tool + configs exist;
   session 75 proved 181/183 byte-identical regen).

---

## SESSION 75q — STREAM OBJECT IDENTIFIED: THE RPF STREAM WRAPPER; STATE LOOKS STALE AT REUSE

### Join-table runtime dump (JOIN[] in INFLATE-PENDING retries==1)
Join table @0x8283D1C4 confirmed live. Layout: +0 key, +8 stream obj,
+12 busy/free-next. All three batch-1 requests hash to entry idx 4
(keys 0x4/0x8004/0x10004 & 0x7FFF = 4 — collisions are by design).
Entries 5-7 are FREE-LIST (busy field = next index, obj = CDCDCDCD).

### The stream object (stable across soaks)
```
JOIN[4] obj=A007D810 vt=82012BDC rd=821CC6F0
objf=[82012BDC(vt) A00E57B0 A0088000(buffer) C6009680(RPF handle!) 0 0 0 0]
inner=A0083660 ivt=82012B44 ird=821CCD58
```
- obj = RPF stream wrapper: holds the cache-RPF file handle C6009680 and an
  internal buffer A0088000.
- rd=821CC6F0 is a WRAPPER: loads [obj+32] (inner=A0083660) and bctrls
  ivt+28 → 821CCD58 (the real read).
- **obj fields +16..+28 are ALL ZERO at stall time.**

### Working hypothesis (strong)
The same stream wrapper is reused for batch 1 AND batch 2. Batch 1 drove it
to EOF (reads 0x800→0x3C8000, then NFS reads stop). Batch 2's sub-transfers
need it re-initialized (seek to a new offset / reset remaining count) — that
re-init never happens (or fails), so every read returns 0 instantly, the
refill hot-spins (credits=1 skips the Sleep), and the boot stalls.
The executor head calls vtable+124 FIRST (returns -1 → error path) — that
is likely the seek/tell that fails or is misused.

### Also
- Fixed a stale-exe trap: two soaks ran an old binary after a failed link
  (exe locked by a running instance). ALWAYS verify build/mcla.exe
  timestamp after building; taskkill before linking (twice).

### Next (ranked)
1. Dump inner stream A0083660 fields (position/size) + the wrapper's
   remaining-count field (extend JOIN dump to [obj+32]+0..40 and
   [inner+0..40]). Confirm EOF-by-state vs EOF-by-size.
2. Read vtable+124 (the first executor call) and vtable+8 semantics from
   82012BDC/82012B44 static vtables in the image (dump the .rdata vtables,
   resolve each slot to a named/emitted function).
3. Find the per-request stream re-init (worker 821BC910 slot setup before
   bl 821BC140) and why it doesn't reset the wrapper for batch 2.

---

## SESSION 75r — BATCH-2 STREAMS RUN WITH A CORRUPTED GUEST CONTEXT (the stall mechanism)

### New runtime proof (INFLATE-PENDING stack/state dump)
Batch-2's InflateStep calls enter with:
```
lr=00000001  r1=821BC380 (a CODE address — the batch-1 inflate return site!)
inPtr=006D8F40 (stack-adjacent)  inLeft=0  produced=0
back-chain walk from r1 reads the instruction word 0x006D8F20 (data)
```
These are NOT normal recompiled calls: r1 points into code, lr=1.
0x821BC380 is exactly the batch-1 inflate caller's saved LR — stale state
from the previous execution resurfacing as a "stack pointer".

###prime suspect: `GuestToHostFunction` (src/kernel/function.h:311)
Host→guest calls build `newCtx` with ONLY r1/r13/fpscr copied
("NOTE: No need for zero initialization") — lr and r14–r31 are whatever the
host thread last had. Any guest callback invoked this way (APCs, task
resumes, kernel completions) starts with garbage lr/callee-saved registers.
If the batch-2 sub-stream inflate is driven through such a call (a resumed
task or an IO completion callback), it inherits r1/lr from whatever guest
code last ran on that host thread — matching the observed 0x821BC380/1.

Also verified: module-base `sub_82130000` is a real `blr` in the shipped
image (not a recompiler gap); the inner stream's page-cache miss path
(821CCB38) contains NO file-read call — it only serves cached 32KB pages
(slots at inner+296/336/356, ops via 821CBE18/821CC8D0) and returns 0 on a
miss. The FETCH for a missing page must be issued by the caller side
(vtable+8 sub_821CC570 — PGLOOKUP ×0: never runs for batch 2).

### Next (ranked)
1. Find the caller that drives batch-2 InflateStep with the bogus ctx:
   log r1+lr in PENDING (done) → set a breakpoint-style census on
   GuestToHostFunction when func==0x821D5E10 or when newCtx.r1 is a code
   address (r1 >= 0x82130000 && < 0x82AD3000 ⇒ garbage) — log the HOST
   callstack (CaptureStackTrace) to name the entry point.
2. Fix candidates: initialize newCtx (lr=0, r14-r31=0) in GuestToHostFunction
   and/or carry the REAL saved context for resumed tasks. Whatever the
   correct semantics, garbage lr/r1 in guest callbacks is wrong.
3. After the fix: verify batch-2 streams get input (PENDING disappears,
   EMPTY only for genuine EOF), REQ count grows past 3, reads resume past
   4MB, and the boot advances (new census markers appear).

---

## SESSION 75s — CORRUPTION LOCALIZED: r1 GOES BAD INSIDE THE WORKER'S LOOP

### Host backtrace of the bogus-context inflate calls (BT[] census)
```
frame 00  sub_821D5E10+0x429      (InflateStep hook — PENDING path)
frame 02  sub_821BC140+0x49d      (executor, refill loop)
frame 03  __imp__sub_821BC910+0x215 (streamer worker)
frame 04  sub_821BC910+0xd5
frame 05  __imp__sub_821C91C8+0x26f (guest thread proc)
frame 06  GuestThread::Start+0x82
frame 07  GuestThreadFunc+0x38
```
The guest call chain is COMPLETELY NORMAL (thread → worker → executor →
inflate). No host-side synthetic call. The corruption is in GUEST STATE:
by the time the executor runs its refill loop, its saved r1 (or the value
it pops) is 0x821BC380 — a stale ctx.lr value from batch-1's inflate loop
written into a back-chain slot.

### Eliminated this session
- sub_82656BF8 (vtable+124) = trivial getter `return [obj+12]` (the file
  handle) — not the problem.
- sub_821CC570 (vtable+8, PGLOOKUP) — never runs for batch 2 at all.
- sub_82130000 (module base, `blr`) — genuinely a no-op in the shipped
  image; not a recompiler gap.
- The inner stream (A0083660) is a 3-slot 32KB page cache (slots at
  +296/+336/+356, ops 821CBE18/821CC8D0); its read returns 0 on a miss and
  contains NO file-read call. Wrapper vtable+8's vtable+144 = 821CBFC0 is
  path/parse-shaped code (with '/' '\' constants).
- No `mr r1, rX` stack-switch exists in TU0/TU15; the only r1 writers are
  stwu-style pushes, epilogue pops (`lwz r1,0(r1)` — all normal returns),
  and the stwux prologue.

### The corruption site
r1 must be corrupted between the worker's frame setup and the executor's
inflate-loop — i.e., inside the worker's per-iteration sync calls
(821C90C0/821C8F08/821C8F70 park/wake family) or during the executor's
early path. A back-chain slot containing a stale ctx.lr means a store
went to the wrong stack offset (frame-size/red-zone collision) or a popped
back-chain was never written (fresh stack region reused).

### Next (ranked)
1. Extend the existing RINGB-CONSUMER hook (sub_821BC910) to log ctx.r1 +
   sanity (r1 should be a low stack address, not >= 0x82130000) EVERY loop
   pass — find the exact pass where r1 flips bad, then bisect the calls
   inside that pass (WAITSYNC/lock ops).
2. Instrument the executor entry (sub_821BC140) with r1 sanity — if already
   bad at entry, the corruption is in the worker; if good, it is inside the
   executor before the inflate loop (narrow between 0x821BC154..0x821BC2D4).
3. Check whether the guest stack region got REUSED: the corrupted slot may
   be below the worker's stack allocation (a stack overflow into another
   thread's stack, or a stale from a previous thread on the same stack).
   THREAD-CREATE logs the stack layout — compare stack addresses of the
   involved threads.

---

## SESSION 75t — TWO THREADS, ONE STACK: THE WORKER'S r1 IS CORRUPTED

### Decisive interleaving evidence (READWRAP + INFLATE-PENDING, same second)
- READWRAP (vtable+28 read wrapper, called from the executor refill loop):
  2000+ calls, ALL with r1in=r1out=**006D8EC0** (VALID stack, the batch-1
  executor frame). r1 never flips across reads.
- INFLATE-PENDING: InflateStep with r1=**821BC380** (code!), lr=1 —
  INTERLEAVED with the reads at the same timestamps.
- Conclusion: the reads and the pending inflates run on **DIFFERENT
  THREADS**. The worker guest thread (THREAD-CREATE #9, start=821C91C8) has
  a corrupted r1 (pointing at code), yet keeps executing the executor loop
  using stale registers (r24 = the batch-1 inflate state 006D8F20 — passed
  as an ARGUMENT, still valid in the register file!).
- The executor refill loop sets ctx.lr=0x821BC380 before each InflateStep
  call — that is where the magic value originates. The worker's r1 holds a
  COPY of it — i.e. the worker resumed with a context whose r1 slot holds
  the saved lr of the batch-1 frame.

### What this means
The worker guest thread resumed from a park/wake with a context whose r1
was never restored (or restored from the wrong slot): r1 = stale code
pointer, lr = 1. The executor loop then "works" using its callee-saved
registers (r24/r26/r28 still hold batch-1 values) but writes locals to
[r1+96..128] — i.e., INTO THE CODE REGION of the identity-mapped image
(0x821BC380+96 = 0x821BC3E0 — guest code bytes being overwritten by loop
state!). The whole inflate state it re-processes is batch-1's stale frame.

### Next (ranked)
1. Add thread-id to READWRAP and INFLATE-PENDING logs (GetCurrentThreadId)
   — confirm the two-thread split explicitly.
2. Find the worker's park/wake: sub_821C90C0/sub_821C91B8 (WAITSYNC family)
   → our host NtWaitForSingleObjectEx park path. Check whether the guest
   thread's PPCContext is preserved across park/wake when the host thread
   blocks INSIDE the recompiled call (it should be — the ctx lives on the
   host thread's stack in GuestThread::Start). Look for ANY host path that
   SWAPS PPCContext on the same host thread (SetPPCContext callers:
   function.h GuestToHostFunction, boot_host.cpp:510).
3. Check the thread STACK allocation: THREAD-CREATE #9 start=821C91C8
   ctx=8285FEA8 — verify the worker's stack range and whether 0x821BC380
   could be a stale value INSIDE that stack from a previous thread
   (stack reuse!) — a fresh thread's stack would then contain old frame
   data including saved lrs.
4. The fix: whatever restores the worker's context after park must restore
   r1. Suspect: the thread was CREATED (not parked) with a bad initial r1 —
   check GuestThread::Start's r1 init vs the guest's own stack-init
   expectations (PCR/TLS/TEB/STACK layout), and whether 0x821C91C8's
   prologue expects an ARGUMENT in r3 (params.value?) that we pass as
   params.value but a corrupted r1 confuses.

---

## SESSION 75u — CORRECTION: THE "CORRUPTED CONTEXT" WAS MY OWN LOGGING BUG

### Retraction of 75r/75s/75t
The "lr=1, r1=821BC380 garbage context" readings were an **arg/format
mismatch in the INFLATE-PENDING log line** (introduced across the 75n/75p
edits). With a clean format (75u) the PENDING calls show:
```
lr=821BC380  r1=006D8EC0  hostTid=0x5748 (the worker)  chain f0=821BC940
```
— a completely VALID context: same worker thread as batch-1, executor's
refill loop, stack descended exactly one 32KB executor frame.
There is NO context corruption, NO two-thread split, NO stack smash.

### The REAL state of the stall (unchanged facts, now clean)
One worker thread, valid frames, hot loop:
```
refill loop: wait-credits(=1, no sleep) → vtable+28 read → returns 0
             → InflateStep (inLeft=0, PENDING) → loop
```
The inner stream is a 3-slot 32KB page cache (slots inner+296/336/356);
on a miss it serves 0 bytes and contains NO fetch call. The wrapper's
first inner call (inner_vt+132) targets 0x82130000 = `blr` (module base) —
a no-op in the shipped image. **Nothing fetches the missing pages.**
Batch-1's pages WERE fetched (NFS reads lr=8244F548 → sub_8244F4C0 TU82,
kernel region) — that fetch path is what batch 2 never triggers.

### Lessons (process)
- The BT[] symbolization + clean arg format caught it. When a value looks
  impossible (TID == a guest stack address), suspect your own log first.
- Verify every format string has exactly matching args after edits.

### Next (ranked)
1. **Find the page-fetch trigger.** Identify sub_8244F4C0's callers
   (kernel read submit path) and what calls it for batch-1 but not
   batch-2. Candidates: the refill loop's read is SUPPOSED to block until
   the page arrives via a kernel-side prefetch thread we don't run; or a
   vtable slot (inner_vt+132?) that should be a "fetch/wait" but points at
   the module-base `blr` — check whether 0x82012BC8's slot value is a
   RELOCATION artifact (pre-reloc value left by our image loader!).
2. **Check the image loader's relocation pass** for the .rdata vtables —
   a missed reloc would leave stale pointers in exactly these slots.
3. If the fetch is kernel-thread-driven: our emu may need to run the
   kernel's IO worker (or service the read synchronously in the wrapper).

---

## SESSION 75v — THE PAGE CACHE IS ALIVE; OUR NtReadFile VIOLATES THE ASYNC CONTRACT

### Also fixed this session
- My PAGESLOT dump dereferenced the inner object's vtable as a base
  ("slots" were .rdata strings — "fiPackfile::Open(%s)"). Fixed: inner =
  [join_entry4+8]+32 = A0083660.

### Runtime page-cache state at stall (PAGESLOT, real values)
```
slot @A0083788: base=0x13 size=0x8000 buf=A00E5880 state=2 event=C6009900
                base=0x14 size=0x8000 buf=A00ED900 state=1
slot @A00837B0: base=0x35 ... state=2 ... base=0x36 ... state=1
```
The cache HOLDS pages (0x13/0x14/0x35/0x36 = offsets 0x98000..0x6C000)
with kernel events per page. Entries with state=1 = PENDING loads that
never finalize.

### The reads DO happen
RD-SUBMIT (kernel read sub_8244F4C0) fired 24+: 32KB reads into the page
buffers, lr=821C50A4 (kernel read wrapper sub_821C4F98 — a VIRTUAL method,
reached via vtable slots 0x820121B4/0x821062C8). NFS-CENSUS: ~100 32KB
reads served by our VFS. Data lands in the page buffers.

### THE CONTRACT MISMATCH (the fix target)
Kernel wrapper sub_8244F4C0: presets ioStatus=259 (STATUS_PENDING), calls
NtReadFile, then:
- r3 == 259 → async path (page stays pending; event/APC finalizes later)
- r3 == 0 (SUCCESS — what our NtReadFile returns!) → returns 1 "done now"
- r3 < 0 → 0xC0000011 error path
The page-cache submitter expects the 259 contract: submit → PENDING →
completion finalizes the slot (state 1→2). With our synchronous SUCCESS,
that finalization never runs as designed — slots stay state=1, the
buffered reader misses, the refill spins.

### Fix to try (next session, small diff in src/kernel/imports.cpp)
NtReadFile: when the caller supplies an event OR apcRoutine (async
semantics), perform the read inline but return **259 (STATUS_PENDING)**
with ioStatus.Information = bytes read, and signal the event (already
implemented in 75p). The guest's own completion machinery then finalizes
the pages. Watch: PAGESLOT states flip to 2, PENDING stops, REQ grows
past 3, reads resume past 4MB.

---

## SESSION 75w — THE BOOT STALL IS DEAD. NEW FRONTIER: 'Fatal disc error'

### THE FIX (small, surgical)
`sub_821CBE18(slot)` = "wait for slot": waits on the slot's event while
[slot+12]==1 (read in flight). Our NtReadFile completes every read
synchronously with evt=0/apc=0 (verified via census) and signals nothing,
so pending slots would block forever on data ALREADY in their buffers.
Hook added (gpu_device.cpp SLOT-READY): if [slot+12]==1 → write 2 before
the wait. Honest: the IO has in fact completed.
Also: NtReadFile now returns 259 (STATUS_PENDING) when an event was
signaled (async contract) — note evt=0 in practice, so this path is
currently dormant.

### Result (soak boot_stdout_sr.log)
- **INFLATE-PENDING ×0** (was 18+spin) — the refill loop consumes data.
- SLOT-READY ×3 (slots A0083788/A00837C4/A0083788 flipped 1→2).
- The boot ADVANCED past the weeks-long loading-screen stall into the disc
  streaming phase — and hit a NEW fatal:
  **'Fatal disc error'** (the game's disc-read error handler) at ~20s.
  A DRAW-SEAM census marker appeared right before it (the game is
  attempting draws!). GLOBTEX-BOOT did not run this time (different path).
- Process exits after the fatal.

### Next (ranked)
1. Trace 'Fatal disc error': log NtReadFile failure returns (ok=false →
   status) with offsets/lengths, and find the guest site that raises the
   fatal (string at 0x820131xx region — locate the check). Candidates:
   a short read (VFS returned < requested), a read at an unmapped offset,
   or the 0xC000000D path.
2. The fatal came right after RELSEMA lr=821CC9E4 (inside the buffered
   read region) — likely the page-fill for a specific page failed.
3. Then re-run the full census battery: REQ count, DRAW_INDEXED, frames.

---

## SESSION 75z — 'FATAL DISC ERROR' FIXED (bit31 ack); NEW FRONTIER: REPRODUCIBLE HOST SEGFAULT

### The disc-error fix (gpu_device.cpp DISCCHK hook)
sub_821CC1E0 fatals when [dev+12] bit30 set && bit31 clear (decoded
polarity: bit30="error/media flag", bit31="handled"). Our devices carry
flags 0x400000EC / 0x4001258B (bit30 set at creation, bit31 never set —
the emu misses the game's acknowledge step). Fix: in the hook, BEFORE the
original runs, set bit31 when bit30 is set. **Critical: the ack must be
BEFORE __imp__ — the fatal fires inside the original** (first attempt
acked after the call and never got a chance to run).

### Result
- 'Fatal disc error' GONE (0 fatals across two runs).
- Boot advances: REQ #2 processes, NFS reads continue (13+), FRAME-END
  fired once in one run.
- NEW, REPRODUCIBLE **host segfault** during batch-2 processing (no guest
  fatal report — our host code or an unhandled guest AV outside the SEH
  filter). Happens around the 2nd request / after reads to ~0xd8000.

### Next (ranked)
1. Catch the segfault: run under cdb/windbg or add a crash handler dump
   (the emu's UnhandledExceptionFilter didn't report — host-side crash or
   the filter itself died). Capture EIP + the host callstack.
2. Prime suspect: the SLOT-READY flip (75w) serves readahead pages whose
   buffers may not hold what the guest expects (state flipped 1→2 but the
   readahead read may target a DIFFERENT page than the slot's base) — a
   serve of stale/foreign data → guest AV. Re-check the flip against the
   slot's base vs the requested offset.
3. The nondeterminism seen earlier (ack run dying at 16ms vs 20s) — likely
   thread-timing; the segfault is the stable failure to chase.

---

## SESSION 76a — THE SEGFAULT DECODED: GUEST AV AT 0x7E780000 IN THE BOOT-INIT CHAIN

### The crash (crash_dump.txt — the emu's filter DID work)
```
code=C0000005  faulting guest addr = 0x7E780000
ppc lr=821782AC r3=C98C4000 r5=2000 r6=C98C5E00 r8=0x1000
host chain: sub_821FA438 ← sub_821FC008 ← sub_821C3048 ← sub_82305E38
            ← thread proc 821C91C8 ← GuestThread::Start
```
**0x7E780000 = the session-72 signature** ("raw non-XCompress bytes
interpreted as pointers → 0x7E780000 AV"). The boot-init task
(82305E38 → 821C3048 → 821FC008 → 821FA438) derefs a resource field
containing 0x7E780000 — a resource body that contains raw/unparsed data
where a pointer should be.

### Also done
- SLOT-READY now requires the slot's buffer to be in a completed-read set
  (tracked in the RD-SUBMIT hook) — correctness gate. In the crashing runs
  it never fires (the crash precedes any slot wait) — the flip is NOT the
  crasher.
- No INFLATE-SKIP in the crashing runs (all streams carried XCompress
  magic) — the garbage isn't from the skip path.

### Next (ranked)
1. **Guest-memory scan for 0x7E780000 in the crash handler** (bounded scan
   of the inflate output regions 0x5/0x6xxxxxxx + the heap) — find WHERE
   the value lives and which resource wrote it. Dump neighbors to identify
   the structure.
2. Identify sub_821FA438/821FC008/821C3048/82305E38 semantics (all
   emitted — read the TUs): which resource field is dereferenced at
   lr=821782AC (the faulting function = the one containing that return
   address).
3. Re-check the batch-1 inflate outputs: are the 15 bodies COMPLETE
   (produced == expected)? An under-produced body would leave poison/raw
   tails that parse as garbage pointers.

---

## SESSION 76b — THE 0x7E780000 POINTER IS COMPUTED, NOT COPIED

### The needle scan (boot_host crash filter, session 76b)
The crash handler now scans guest memory (stacks, inflate-out, phys-heap)
for the faulting value. Result: **"needle 7E780000: no occurrences in
scanned regions"** — the value exists NOWHERE in guest memory.

### Implication
The wild pointer is COMPUTED by the recompiled code, not loaded from a
resource body. Host regs at fault: r8 = 0xFFFFFFFF7E780000 — a 64-bit
value whose low half is 0x7E780000 and high half all-ones = a NEGATIVE
offset (base + offset wrapped). This is pointer arithmetic gone negative:
base(0x100000000) + sign-extended(-0x81880000) style — i.e., a guest
address computation underflowed (a base pointer + a huge unsigned offset,
or a subtraction in the wrong order).

Note: 0x7E780000 is the SAME value as the session-72 AV — a recurring
computed artifact, not data. (r3=C98C4000/r6=C98C5E00 are kernel handles
in the faulting context; 0x7E780000 = 0xC98C4000 - 0x4B14000 — possibly
handle-derived arithmetic.)

### Next (ranked)
1. Decode sub_821FA438's TU (the faulting frame; the AV is inside its
   recompiled body — find the instruction using r8) and its caller chain
   821FC008 ← 821C3048 ← 82305E38 (the boot-init task). Identify the
   guest computation producing the negative offset (a Translate-style
   base+offset with offset = 0x7E780000 from a bad base or length).
2. Check r3=C98C4000: which kernel object is that (the crash context)?
   The computation may be a handle-to-pointer translation with an
   unregistered handle (0x7E780000 could be a handle table slot number
   scaled!).
3. Repro note: crash follows REQ #2 (the '#sf' kernel-side request)
   consistently.

---

## SESSION 76c — THE BAD r8 IS BUILT IN REGISTERS (host-hook leak or inlined callee)

### Faulting site pinned (llvm-symbolizer + PDB)
```
RIP rva 0x62D8D7 → __imp__sub_821FA438 → ppc_recomp.23.cpp:5274
= the call site of sub_8218F308(r3=frame+80, r4=3)  (compiler inlined it)
```
sub_8218F308 (TU11) = tiny: sth to [r3+208]/[r3+210], call 8218F210, ret.
The parent function (sub_821FA438, TU23:5204-5453) only ever assigns
r8=1 — so the crashing r8 = 0xFFFFFFFF7E780000 (= -(0x81880000), a 64-bit
NEGATIVE) comes from either:
  (a) an INLINED callee's computation, or
  (b) a HOST HOOK leaking a negative/host-pointer value into ctx.r8,
after which the guest adds an offset and derefs (base + r8 = 0x7E780000).

### Eliminated
- Needle scan (incl. image+BSS now): the 64-bit value is stored NOWHERE —
  computed in registers.
- INFLATE-SKIP: 0 in crashing runs (all streams XCompress).
- The guest lr (821782AC) is stale — do not chase it.

### Next (ranked)
1. Instrument ctx.r8 at sub_821FA438 entry and after each call site
   (82178370/8218F308/821800A0/8217C088/8217FED0/8217F768/8217C658) — find
   where r8 flips to the 64-bit negative.
2. Grep the hooks that run in this chain (REBASE-POISON sub_821B5A60, the
   821C3048/821FC008 path) for ctx.r8/ctx.rX writes that could leave a
   negative or host pointer in a guest register.
3. r3=C98C4000/r6=C98C5E00 (kernel handles) in the crash regs — check the
   handle-to-object translation for a negative-arith path.

---

## SESSION 76d — POSITIONAL-READ RACE FIXED; CRASH = UNINITIALIZED TASK HANDLE (poison family)

### Fixes landed
1. **ReadFileAt** (vfs_rpf.cpp): positional OVERLAPPED read for real RPF
   handles — NtReadFile no longer does seek+read on the shared position
   (two threads reading one handle raced and served wrong bytes).
   CAREFUL: the fallback re-enters ReadFile → use unique_lock + unlock
   (std::mutex is non-recursive; the first version threw
   resource_deadlock_would_occur — crash_dump 0xE06D7363).
2. NtReadFile now calls ReadFileAt for byteOffset reads.

### The remaining crash (consistent across runs now)
```
r3=FF00FF00 (a DATA value used as a task handle!)  r10=0xCD (poison byte)
chain: 823047D8 (boot init) → 82187820 → 821CA6A8 → 821BDF20
       → 821CB488(task-ctx lookup) → AV deref 0x7E780000
```
The boot init reads a task/handle field from a structure that was never
initialized — session-73's poison family at a new site (0xFF00FF00 =
stale/garbage data where a kernel handle should be; r10=0xCD confirms
poison-filled memory nearby).

### Next (ranked)
1. Trace r3's source: sub_821BDF20's caller chain (821CA6A8/82187820/
   823047D8 TUs) — find the struct field that supplies the handle and
   WHICH initializer should have written it (session-73 rule: make the
   loader run, don't zero the use-site).
2. The TSLAB-OWNER/PARAM-STORE instrumentation (session 73, still in
   tree) can name the object's allocator/owner — arm it for this address
   family.
3. Re-check: does 82187820 correspond to a resource whose dict entry was
   filled by the batch-1 loads? Cross-ref the name (meshtextures#td vs
   the object being initialized).

---

## SESSION 76e — THE CRASH IS IN "ui" RESOURCE PACKAGE PROCESSING

### BOOTPATH census (sub_82187820 entry)
```
#1 r3=A0084110 r4=8201F30C — r4 points at STATIC .rdata strings:
   bytes = "ui\0\0" "$\0\0\0" ... (the descriptor IS a string table)
```
The boot task processes the **"ui" resource package** — the same
`$/resources/ui/...` streamables family from sessions 75i-m. The crash
(fiDevice::GetDevice with a garbage path pointer 0xFF00FF00 → name-lookup
AV at 0x7E780000) happens while building/resolving the ui package's mount
path.

### The full decoded chain (all confirmed this session)
```
823047D8 (boot init task) → 82187820("ui" package desc)
  → 821CA6A8 → 821CA2F8 (PATH PARSER: checks '/' '\' ':')
  → 821BDF20 → 821CB488 (fiDevice::GetDevice — string-compares the path
    against registered device prefixes, 5/6/7/10-char names)
  → AV: the path pointer = 0xFF00FF00 (garbage), name read hits 0x7E780000
```
Also decoded: sub_821CBE18 = "wait for slot" (page-cache fill wait);
sub_821CA2F8 = path parser. 821CB488 = GetDevice.

### Next (ranked)
1. Read 82187820's TU (TU10:3649) around the 821CA6A8 call: which STRING
   does it pass as the path? The "ui" package's mount path comes from the
   package descriptor — find the field and why it's garbage (uninit or
   missing construction step).
2. The "ui" package = the UILOAD/streamables family. Cross-check what the
   guest EXPECTS to be mounted for "ui" (a t:\ device? a packfile?) — our
   VFS serves t:\ already; the guest's own fiDevice for "ui" may need a
   mount that never ran.
3. The 0xFF00FF00 pointer: read 821CA6A8's r30-source (the field holding
   the path ptr) in TU17:14452 — the descriptor field offset → then find
   who should write it.

---

## SESSION 76f — THE "ui" PRELOAD-LIST GLOBAL IS NEVER POPULATED (watch-proven)

### Watch result
RegisterGuestWatchRange(0x827D7770, +0x20) armed at boot — **zero writes
before the crash**. The boot init (sub_823047D8) reads the "ui" preload
list from a global that nothing ever filled. 13 functions touch the
global (sub_82300928 = same-TU sibling = likely the filler; list in 76e
notes).

### Also established
- The 821CA6A8 call = ("ui" manager global, "preload", "list", 0, 1) —
  a RESOURCE-SYSTEM query for the ui package's preload list.
- xarchive_cache.rpf: RPF3 magic at file offset 0 (NOT 0x800); the value
  0xB116A6AB at 0x800 = the TOC-ENCRYPTED marker (retail AES TOC — the
  guest decrypts it with its embedded key; batch-1's by-name reads prove
  decryption works in our emu).
- NFS reads confirm: 18KB TOC read + 374KB TOC/names read at boot.

### Next (ranked)
1. Census the 13 functions touching 0x827D7770 (log-only, first call) —
   find the POPULATOR and whether it ever runs. Prime suspect:
   sub_82300928 (same TU as the boot init).
2. If the populate runs but AFTER the boot init's read: a boot-order bug
   (the task that fills the list must precede the task that reads it —
   check the submit order at 821BD7C0).
3. If the populate NEVER runs: find what should trigger it (a package
   mount/index-load for "ui" that didn't happen — cross-check the batch-1
   package indexes read at boot: 374KB TOC + which packages).

---

## SESSION 76g — THE CRASH IS fiDevice::GetDevice WALKING A BAD DEVICE ENTRY

### Device-list dump at crash (crash_dump.txt "device dump")
```
r6=A0082510 → ASCII "a:/archive/" (a mounted-ARCHIVE path!)
A0082500: [A0082500 00001140 A007DCF0 00000050]  ← device/entry header
A00824D0-F0: repeating 16-byte blocks 25C6BDA2 DAA2379A ... (encrypted-
             TOC-looking data, 3 identical rows)
then: pure CDCDCDCD poison
```
The chain: 823047D8 → 82187820("ui","preload","list") → 821CA6A8 →
821CA2F8 (path parser) → 821BDF20 → 821CB488 = fiDevice::GetDevice —
matching "a:/archive/..." against registered device prefixes. ONE device
entry's name/offset computation yields 0x7E780000 → AV.

### Interpretation
The device registry contains an entry (or the walk overshoots into a
slot) whose name/offset data is garbage. The neighborhood shows an
"a:/archive/" path + encrypted-TOC-style blocks — the "a:" archive
device (the RPF mount) is involved. Likely a registry walk
count/terminator mismatch, or a device registered with an uninitialized
name field (poison family).

### Next (ranked)
1. Read 821CB488's device-loop tail (TU18, after the string compares,
   ~line 1370+): how does the walk TERMINATE (count field? null
   sentinel?) and what global holds the registry head?
2. Dump the WHOLE registry (head → all entries) at crash time via the
   crash handler (extend the device dump to follow the walk), and find
   the entry computing 0x7E780000.
3. Check whether the "a:" archive device's registration (fiPackfile
   mount for the RPFs) writes its name field — the name may live at
   [device+X] where our emu's mount path differs.

---

## SESSION 76h — DEVICE REGISTRY DECODED: head 0x82860844, stride 264, match 821CAA28

### The loop (sub_821CB488 tail, TU18:1419+)
```
r27 = 0x82860844            ← registry header
r29 = [r27+4]               ← device COUNT (u16!)
r6  = [r27+0]               ← device ARRAY base (crash: A0082510)
r7  = r6 + 264              ← first entry scan cursor (stride 264!)
loop: r9 = [r7] (name len u16)
      821CAA28(r3=entry(r7-264), r4=path, r5=len)   ← the prefix match
```
The crash's r6 = the ARRAY BASE. Entry 0's region contains the
"a:/archive/" path + encrypted-TOC-style 16-byte blocks + poison.

### Interpretation candidates
(a) The registry array was allocated in a heap block later reused by the
    TOC-decrypt buffer (stale data where devices should be), or
(b) Entry 0 IS the "a:" archive device (path "a:/archive/" + TOC cache)
    and the AV comes from a LATER entry or a field inside entry 0
    (name ptr at some offset = 0x7E780000).
Note: the needle scan finds no 7E780000 anywhere — the bad address is
computed from an entry field, not stored.

### Next (ranked)
1. Census hook on sub_821CB488 ENTRY: log [0x82860844] (array), [+4]
   (count), and the first 4 entries' first 8 dwords each. This shows the
   registry state BEFORE the walk and exactly which entry is bad.
2. Read sub_821CAA28 (the entry matcher) — which entry field is the name
   ptr / how the prefix match computes addresses (find the field whose
   garbage yields 0x7E780000).
3. Check the registry population: who writes [0x82860844]/[+4] and the
   entries (the fiPackfile mount path) — verify the count matches the
   entries actually registered.

---

## SESSION 76i — THE REGISTRAR IS CAUGHT: lr=821C2AAC writes the array; count never written

### PAGEWATCH on the registry header (0x82860844, 12 bytes)
```
W #01 @ 8286084C = 00000004   lr=822C4700
W #02 @ 82860844 = A0082510   lr=821C2AAC   ← array pointer set
R #01 @ 82860844              lr=821CBB1C   ← GetDevice reads
```
- The COUNT field (+4) is NEVER written (yet GetDevice sees 16 — the
  value lives elsewhere or my offset decode is off by a field).
- Entry 0's name ("a:/archive/", 11 chars) got written; the device-object
  pointer slot (probably entry+256, after the inline name buffer) is
  still CDCDCDCD.
- Layout hypothesis: entry = {char name[256]; Device* dev; ...} — the
  name copy ran, the device-ptr store did not.

### Next (ranked)
1. Read sub_821C2AAC's TU (the array allocator/registrar) and find its
   CALLERS = the Mount path. Then read the Mount function: the name copy
   AND the device-ptr store — why one lands and the other doesn't.
2. Check what the count field offset really is (dump the registry header
   +0..+16 raw at GetDevice time; my +4-u16 read gave 16 — verify).
3. The device OBJECT construction: fiPackfile ctor for the "a:/archive/"
   mount — did it run? Its vtable/fields vs the poison in the entry.

---

## SESSION 76j–76s — THE CRASH IS THE "MISSING TEXTURE" CHECKERBOARD OVERWRITING THE DEVICE REGISTRY HOLDER (3 RE subagents deployed; allocator fully mapped)

### Breakthrough chain (every step evidence-backed)

1. **Registry + Mount + GetDevice fully decoded** (TU ground truth):
   - Registry header `0x82860844` = `{Device** array@+0, u16 count@+4, u16 capacity@+6}` (capacity=16 from global `0x827D8384`, set by array alloc `sub_821CB8B8` ← `ppc_recomp.18.cpp:1908-1961`).
   - Entry = **276 bytes** (NOT 264): `name[262], flag u16@262, nameLen u16@264, device vector {Device** arr@+268, u16 cnt@+272, u16 cap@+274}`. Array allocator `sub_821CB848` (TU18:1825) constructs EVERY slot: `+268=alloc(4), +272=0, +274=1`.
   - `sub_821CB488` = GetDevice (TU18:1238): prefix checks (7/10/6/6/7/5/4/3-char), walk `count` entries stride 276, best-prefix match via `sub_821CAA28`; post-loop: if `[best+272]==1` → single dev `=[[best+268]]`; else iterate `[[best+268]+i*4]` BACKWARD calling `vtable+4` (match) then `vtable+48` on hit. Crash bctrl = `ctx.lr=0x821CB670` (TU18:1522).
   - Mount = `sub_821CB9D8` (TU18:2108): special path "memory:"→fallback global `0x827D8380`; else ctor stack entry `sub_821CB760`, array alloc when cap==0, dup-scan, `count++` ONLY for new entries (TU18:2390), name copy, then push_back `sub_8262E420(&vec,1)` (TU128:27657 = vector grow: `count==cap → cap+=1, realloc(count*4), copy, free old`) + dev stored.
   - Mount call sites (3): `0x82139B58`/`0x82139EF4` (RPF auto-mount `sub_821399E0`/`sub_82139BE0`, TU1) and `0x821CBF54` (thin swap-args wrapper `sub_821CBF28`).
   - fiPackfile vtable `0x82012BDC`: +4=Open `sub_821CDB88` (`r4=[dev+36]+path` → tail `sub_821CCEA0` = open impl; calls `vtable+144` TOC lookup = `sub_821CBFC0` which returns 0 immediately if `[obj+8]==0`).

2. **Runtime census (boot_stdout_76k..76s.log)**: BOTH RPFs mount cleanly at `a:/archive/` (`MOUNT76 #1 dev=A007D398`, `#2 dev=A007D810`, both vt=82012BDC, lr=821CBF54) → entry0 vector ends `cnt=2 dcap=2 d0/d1 valid`. Boot resolves real UI package files (raceeditor/garage/policecam/credits.xsf, meshtextures.xtd, legals.xsf, globaltex.list). Crash = GetDevice call **#28: `a:/archive/shaders/ui/preload.list`** — deterministic, ~60s in.

3. **PAGEWATCH caught the corruption** (watches: `A008261C..24` entry0 vector, `A0018028..30` holder): holder written valid at 35.733 (`W A0018028=A007D398`, `W A001802C=A007D810`), then **0.3s later `W A0018028/2C = FF00FF00`** (lr attribution useless — see memset sticky-LR note below).

4. **FFBT host callstack at the FF00FF00 store**: `sub_8218ECF8 ← sub_8218EDA8 ← sub_82184F58 ← sub_82185368 ← sub_82182240 ← sub_823047D8(boot init)`.

5. **SUBAGENT DECODE (the big reveal)**:
   - **`0xFF00FF00` is NOT poison** — it is **opaque green texel data**: the first dwords of the 4096-byte pixel buffer of the 32×32 magenta/green **"missing texture" checkerboard** (`sub_8218ECF8(32, 0xFF00FF00, 0xFFFF00FF)`, ppc_recomp.11.cpp:4576-4681). The boot loads `globaltex.list` (`$/textures/global/cars`), each line → find-or-create texture `sub_82185368` → DDS load `sub_8218EDA8` → on failure the checkerboard fill runs (conditional failure path!). The buffer = `sub_82130528(128*32*1)` allocated in `sub_8218DE38` (texobj ctor, ppc_recomp.11.cpp:2567-2577) — a **4096-byte general-allocator block**. Its first two texels landed at `A0018028/2C` = **on top of the live device-holder**.
   - **Allocator fully mapped** (sysMemSimpleAllocator): `sub_82130528/550/588` = real guest virtual dispatch `[[[r13]+28]]->vtbl[+8/+0xC]` → registry `0x82830B18` → main heap `0x82830CD8` (`sub_821C29A0` alloc / `sub_821C2AB8` free). ≤64B+align≤16 fast path → 5 size classes @heap+208/216/224/232/240 (elems 4/8/16/32/64, 4072/2036/1018/509/254 per slab) → `sub_821DE9D8` pop (freelist next @elem+0, 0xCD fill) / refill `sub_821C1BB0(heap,16320,16384)` + bitmap bit @heap+252. Free `sub_821C2AB8`: `(p&0x3FFF)<16320 && bitmap bit` → `sub_821DE908` (0xDD fill, push @elem+0; empty slab → unlink + `sub_821C22D0` back to general). General alloc `sub_821C1BB0`: best-fit 16 buckets @heap+12..75, 16B headers (+0 self,+4 size,+8 phys-prev,+12 flags{low4=heap-id from [[r13]+0x30],0x10=in-use}), 0xCD debug fill. Pool = ONE `MmAllocatePhysicalMemoryEx` of 47616KB at boot (`sub_82131228`, 0.cpp:3024-3456). Our synthetic r13 table redirects [[r13]+28] to `__xtl_alloc` ONLY until guest boot installs the real registry (0.cpp:3438-3451) — both are true, in sequence.
   - **lr=8244D158 (W#01) = the Xenon CRT `memset` (`sub_8244D150`, TU82:13453)** — METHODOLOGY: the recomp special-cases memset's `bl __savegprlr_29` (assigns `ctx.lr=0x8244D158`, emits NO call) and nothing restores the caller's lr → **every store after any memset return reports lr=0x8244D158 until the caller's next bl**. All `lr=821C2AAC` stores = same artifact via the slab wrapper's unlock (`sub_821C9030` called at 0x821C2AA8). **Guest-LR attribution after memset/leaf-calls is void — use host backtraces (FFBT) instead.**
   - **lr=821C0A78 = `sysMemMultiAllocator::Free` dispatch** (`sub_821C09C8`, TU16:5837): owns-probe each child, claim at index i → free via `m_Allocators[i+1]` (i→i+1 pairing!), **i==1/3 silently DROPPED** (entries 1/3 = sysMemDualBuddyAllocator registered 3×). Registry alloc dispatch: `sub_821C08F8` forwards r6=0 → entries[0]=sysMemSimpleAllocator.

6. **Allocator lock FIXED but not the root cause**: guest guard `sub_821C8FE0` (TU17:10661) reads `[cs+0]` and **skips RtlEnterCriticalSection when zero**. CS `0x82855A0C` IS initialized by the guest (init #25, guest=82855A0C) but our `RtlInitializeCriticalSection` left `[cs+0]=0` (16-byte XDISPATCHER_HEADER at +0) → **the game's allocator ran completely unlocked across threads**. Fixed: `cs->Header.Lock = 0xFFFFFFFF` in `RtlInitializeCriticalSection`/`...AndSpinCount` (imports.cpp). Runtime-verified `lockFlag=FFFFFFFF`. **Crash unchanged** → the overlap is NOT (only) a lock race.

### Current model of the overlap (to verify, not yet proven)
The holder (8B, guest slab class 1 element) lives at A0018028. The 4096B checkerboard buffer (general allocator) later got A0018028 as its base. With the lock active, the remaining candidates: (a) a **general-allocator free of a bogus/interior pointer** poisoned the free buckets (`sub_821C22D0` trusts [p-16..p] as a header); (b) the **slab-element free path's loose check** (`(p&0x3FFF)<16320 && bitmap bit` → treated ANY pointer in a slab region as an element, 0xDD-fills ownerClass->elemsize bytes!); (c) a fully-freed slab returned to the general pool while entry0+268 still dangles at A0018028.

### Changes landed this session (all committed)
- `src/gpu_device.cpp`: GETDEV census rewritten (true 276-stride layout, path strings, entry dumps, dcnt/dcap, dev+36 prefix lens, lockFlag probe), new censuses MOUNT76 / EMB76 / TOC76 (+RET).
- `src/boot_host.cpp`: watches `A008261C..24`, `A0018028..30` (+ the 76i registry watch).
- `src/gpu_cp.cpp`: FFBT — one-shot host callstack on FF00FF00 stores into watched ranges.
- `src/kernel/heap.cpp`: **exact-allocation contract** — `LivePhysAllocs()` set; `Heap::Free` physical path rejects non-exact frees (BOGUSFREE + one-shot host backtrace; 0 rejections observed so far); WIN76-ALLOC/FREE ownership log for the A0017FE0..A0018060 window (0 hits through AllocPhysical → the pool is one big o1heap block, guest-internal allocs are invisible host-side).
- `src/kernel/imports.cpp`: CS init lock-word fix (above) + init logging with guest addresses.

### NEXT (ranked, concrete)
1. **Reconstruct the general-allocator history of the window**: extend the existing `PPC_FUNC(sub_821C1BB0)` hook (patches.cpp:1454, non-census path) to log every alloc `size>=4096` (ret, lr, capped ~150) and hook `sub_821C22D0(heap=r3, ptr=r4)` (general free, TU16:9909) logging ptr + claimed header words [p-16..p-4] + lr (c
3. If a bogus general free shows up: identify its caller via FFBT-style backtrace and root-cause THAT (do not paper over).
4. Whatever the mechanism, the checkerboard fallback firing at boot means `sub_8218E090` (DDS load via `a:/archive/...` open) FAILED for a globaltex.list entry - after the heap fix, verify whether the DDS opens succeed (the files ARE in the archive per GETDEV #5-27 successes).

### Session evidence files
- `boot_stdout_76k..76s.log` - census progression (76k: first true-layout GETDEV; 76n: PAGEWATCH catches FF00FF00 writer; 76o: FFBT callstack; 76s: lockFlag=FFFFFFFF, crash unchanged)
- `crash_dump.txt` - deterministic signature: ppc r3=FF00FF00 r4=8EFFF540 r6=A0082510 r7=A008272C lr=821CB670, AV read at 0x7E780000 (first uncommitted page below the scan)

---

## SESSION 76t–76y — THE BOOT CRASH IS FIXED (jump-table recompiler gap); NEW STATE: clean guest fatal on shader preload

### THE FIX (root cause, committed)
The week-long `0x7E780000` crash chain (GetDevice reading FF00FF00 Device*) resolved to a **buffer overflow**: the "missing texture" checkerboard fill wrote 4096 bytes into a 32-byte buffer. The buffer was tiny because **`sub_8218DCE8` (texture pitch) is a jump-table switch that the recompiler emitted as ERROR stubs** — every case just `return`s, so `[obj+12]` (pitch) was never written and the ctor sized the buffer from garbage.
- **Fix**: faithful host override `PPC_FUNC(sub_8218DCE8)` in patches.cpp, reconstructed from the raw image (jump table @0x8218DD14, case bodies @0x8218DD6C-30): fmt 1/14-17/19 → w*4; 11/18/22 → w*8; 12/13 → w*16; 20 → w*2; 9/10/21 → no store; 2 → 2; 3-8 → (w>=4 ? fmt : 4). All stored u16 at [obj+12].
- **Result**: pitch=128 for the checkerboard (fmt=1), proper 4096-byte buffer, boot passes the preload.list crash that blocked sessions 76a-76s.

### SYSTEMIC RECOMPILER GAP (the big discovery)
`grep -h "ERROR: 0x" generated/ppc_xenon/*.cpp | wc -l` = **1557 stub sites, 873 unique targets** — every jump-table switch in the game failed to recompile. ppc_recomp.2.cpp alone has 225. These are silent: the switch takes a branch that returns immediately. Any future "field never written / value garbage / behavior differs" bug should check for ERROR stubs in the involved functions FIRST (`grep -n "ERROR: 0x" generated/ppc_xenon/ppc_recomp.N.cpp`). Route B (fix XenonRecomp jump-table emission + regenerate; regen proven byte-identical in session 75) is the proper systemic fix and is now the highest-value infrastructure task.

### Also fixed this session
- Our own BOOTPATH census hook (gpu_device.cpp sub_82187820) AV'd on garbage descriptor fields — rewritten with checked `ReadBytes` (the crash had host rva 0x9C360 = our code, not guest).
- Allocator instrumentation now in tree: GEN76-ALLOC (>=4096B), GEN76-FREE (general free w/ header words), BUDDY76-ALLOC/FREE (buddy allocator), TEXCTOR (texobj ctor dump), HEAP76 (arena layout dump). MOUNT76/TOC76/EMB76/FFBT/GETDEV from earlier in 76j-s.

### Key structural facts learned (subagent-verified, TU-cited)
- Allocator: `sub_82130528/550/588` = virtual dispatch to registry `0x82830B18`; **alloc dispatch `sub_821C08F8` routes to `m_Allocators[(r6+1)*4]` — i.e. the sysMemDualBuddyAllocator (B7xxxxxx arenas), NOT the simple allocator** (earlier agent report had this wrong; TU16:5695-5715). Simple allocator (46.5MB pool A0001010..A2E81000) serves direct callers (TSLAB pops lr=821D4588). Free dispatch `sub_821C09C8` ownership-scans, claims index i → frees via [i+1], silently DROPS i==1/3.
- **Guest-LR attribution is unreliable**: the CRT memset (sub_8244D150) special-cases its savegprlr stub so `ctx.lr=0x8244D158` sticks through the caller until its next bl (same for 821C2AAC via the slab wrapper's unlock). Use host backtraces (FFBT) for attribution.
- The checkerboard `0xFF00FF00/0xFFFF00FF` = "missing texture" placeholder texels, NOT poison.
- Allocator CS `0x82855A0C` is initialized by the guest (init #25); our `RtlInitializeCriticalSection` now sets `Header.Lock=0xFFFFFFFF` so the guest guard (sub_821C8FE0: skip lock when `[cs+0]==0`) actually locks. Verified lockFlag=FFFFFFFF at runtime.

### NEW FRONTIER (where boot now stops)
Exit code 3 (clean guest fatal, ~0.3s after the last fix point):
```
'Unable to load shader 'star_glow', it probably wasn't preloaded properly.'
```
Trace: REQ #1 issues a 9-char-name request ("star_glow"), INFLATE runs (shader dict bodies, 512KB outputs), the boot opens `a:/archive/shaders/{ui,city,cars,characters}/preload.list` (all resolve!), then shader lookups cascade:
`embedded:/dcl/star_glow.dcl` → `embedded:/star_glow.dcl` → `embedded:/fxl_final/star_glow.fxc` → fallback `a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl` (mangled double-path) → fatal.
**MOUNT76 shows NO `memory:` device mount ever happens** — Mount's special "memory:" path (registers the fallback device into 0x827D8380) never runs. The embedded shader library (fxl_final fxc blobs) has no backing device.

### NEXT (ranked)
1. Find what should create+mount the embedded shader-library memory device ("memory:" mount → 0x827D8380) and why it doesn't run. Check the boot init order around sub_82131228 (allocator/heap boot) and the shader-system init; watch for a failed load that silently skipped the mount.
2. GLOBTEX-BOOT inserted=0 this run (was 20) — the texture-insert workaround state changed; re-check after the shader fix.
3. Route B: fix XenonRecomp jump-table emission, regenerate, byte-diff validate, swap in — retires the pitch override and un-blocks 1557 other sites.
