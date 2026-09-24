# MCLA PC — agent rules (auto-loaded; keep this file short — it costs tokens every session)

Xbox 360 (Xenon) → PC emulator: XenonRecomp static PPC→C++ recompiler + D3D12 backend, guest
`default.xex` (Midnight Club LA prototype). Goal: boot → menu → playable. Not a general game project:
**the guest binary is data, and the docs are the source of truth about it.**

## Read in this order (never skip step 1)

1. `docs/LONG_TODO_MASTER.md` — §0 dated state, §1 rules, §2 task queue, §4 do-not list.
2. `docs/HANDOFF_NEXT_AGENT.md` — live block + session ledger (what the last session actually saw).
3. `docs/PROGRAM_GUIDE.md` on demand — §3 build/run gotchas, §4 guest image, §5 recompiler pipeline,
   §7 host short-circuit table, §9 log-marker inventory, §11 forbidden paths.
4. `docs/ROOT_CAUSE_VALIDATION.md` Part 3 — append-only evidence ledger `F-001…F-117` (whole again on
   E: since the 09-23 merge; `C:\mcla-pc\docs` is archive only — see rule 6).

Older status text anywhere else = trail, not truth. Pre-compression doc text: `git show 8f07a39:docs/<file>`.

**Before asserting anything about the tree, re-census it** (`grep`, `ls -l`, `git log`). Three claims
in one handoff were false purely because they were remembered from a compaction summary, not
re-measured. That is rule 13 in practice: *no claim without a log line, raw word or `file:line`.*

## The 5 rules that keep costing sessions

1. **Census before fix.** No short-circuit without a root cause; never stack short-circuits (do-not
   #1/#9). A mitigation must be labelled and cited at its `file:line`.
2. **Never edit `generated/**` or `.research/**` or `config/mcla_xenonrecomp.toml` or
   `src/ppc_context.h`/`ppc_config.h`/`src/dispatch_guard.cpp`** — full list: PROGRAM_GUIDE §11.
   Tool changes go through `.qoder/skills/mcla-recompiler-regen`.
3. **Raw-byte rule (F-023).** `build/cache/mcla_pe.bin`, offset = VA − 0x82000000, words
   big-endian; the PE section table lies; IDA is a hypothesis until the bytes agree.
4. **One owner per guest address.** `python tools/addr_owners.py --check <addr>` before adding any
   hook (it reads `PPC_FUNC`/`GUEST_FUNCTION_HOOK`/`SetFunction`/`GetFunction` and exits 1 on a
   duplicate); grep is the fallback, not the check.
5. **Concurrent sessions are normal.** Before building/booting: `tasklist | grep -iE "mcla|ninja"`
   and check the newest `build/*.log` is >2 min old (rule 11). Before writing a doc: check its
   mtime and add a dated superseding block rather than editing someone else's.
6. **E: is primary again (merged 2026-09-23, was rule-6's split-tree warning).** The C:\mcla-pc merge
   landed: `src/`+`tools/` ported (gpu_cp register file, patches F-092 cleanup, RPF3 model, fixed
   `ppc_disasm.py`+`addr_owners.py`), `gpu_device.cpp` 3-way-merged, ledger whole on E: (F-001…F-092),
   §2 queue unioned, skills synced. Verified: merged tree **built clean on E: (`build_on_e.bat`, 11/11,
   0 errors) and `w46.log` reproduces `w45b`** (C0000005 0, Fatal 2, GFx 3). `C:\mcla-pc` is retired
   read-only archive; provenance snapshot `E:\mcla-c-snapshot-20260923`. Pre-merge state = commit
   `35912f0`. Do not start building on C: again; if a file still differs from the snapshot, `diff -q`
   before trusting either side.

## Project skills (`.qoder/skills/`) — use them, don't rediscover the gotchas

| Skill | When |
|---|---|
| `mcla-boot-cycle` | any src change to compile+boot (MSYS guards, kill-before-build, stale-exe trap, new log per run) |
| `mcla-guest-raw-decode` | attributing a fault `lr`, naming a vtable slot, checking an IDA address (`lis` sign-extension trap) |
| `mcla-log-census` | reading/comparing soaks or claiming a gate (case-insensitive counts vs named baseline) |
| `mcla-finding-ledger` | writing any conclusion down |
| `mcla-recompiler-regen` | VMX128 ops, stubs, jump tables, `midasm_hook` work |

## Project tools (`tools/*.py`) — the executable form of those skills, run them instead of re-deriving

| Tool | When | Exit code |
|---|---|---|
| `tools/soak_census.py <new.log> <baseline.log>` | reading or comparing any soak. 115 markers counted as matching **lines**, case-insensitive (identical to `grep -ic`), plus a fault-line vs all-line `lr=` split, a **CP truth** line (`drains`/`last_rptr`/`pub` vs `put` — the only honest pipeline signal; a waiter's `rptrWB=` field is not, F-057(1)/F-058) and a **LOG QUALITY** line that flags a soak dominated by one repeating mitigation message as POISONED (F-054: 616,824 laundered firings = 66% of `w38e.log`). It also prints **MARKER NOT IN SRC** for any tracked marker whose literal exists in neither `src/` nor `generated/` — such a marker's zero means nothing (F-057(6): 8 of the old 9 VEH markers were dead text). Reconcile a hand count with it before claiming it. | 0 (informational) |
| `tools/addr_owners.py` | rule 4, before adding **any** hook — guest address → `file:line` → hook name, and which sites actually *claim* it. `--check <addr\|symbol>` for one site; `--gates <addr>` prints each claim's enclosing-function conditions **verbatim, uninterpreted** so a possible conflict is resolved by reading the soak for the installer's own log line, never by guessing which registration wins (F-053). | **1 = duplicate owners** |
| `tools/mitigation_audit.py` | do-not #9 — diffs the `PROGRAM_GUIDE` §7 registry against the mitigation-shaped labels really in `src/` (F-047: §7 lists 13, `src/` has 81). `--tiers`, `--label X`. | **1 = unregistered/stale** |
| `tools/ppc_xrefs.py` | static xrefs without IDA: `find-str <text>`, `xref <hexVA>` (`lis`=`addis rT,0,imm`! sliding per-register state), `calls <hexVA>`, `fn <hexVA>`. One-site messages are load-bearing attributions (F-102 named the whole preload chain this way). | 0 (informational) |
| `tools/rpf_offline.py` | archive forensics without a soak: `header` (RPF3 TOC length/endianness), `names <toc_dump>` (GtaO-joins an **in-guest** TOC dump to real path names), `find <path> [archive\|dump]`, `member <off> <len>`, `islands <lo> <hi>`. Raw-archive `find` returns 0 by design — the on-disk TOC is AES, the in-guest copy is a hash-sorted cleartext table (F-099). | 0 (informational) |

## Project MCP servers (`.qoder/settings.json`, committed — first load shows a trust prompt; run `/mcp reload`)

| Server | What it is | Constraint |
|---|---|---|
| `ida-pro` | `python ~/.local/share/mcp/ida-bridge.py` → idalib on `build/game_data/default.xex`, RPC :8745 | it `taskkill`s `idalib-mcp.exe` on start — **never** launch it while another session's IDA session is open. If `tasklist` shows `idalib-mcp.exe`, **attach to `http://127.0.0.1:8745/mcp` instead** (POST, `Accept: application/json, text/event-stream`, keep `Mcp-Session-Id`) — verified working 09-20 22:2x: 47 tools, `get_metadata`, `decompile_function`, `get_xrefs_to` (PROGRAM_GUIDE §10) |
| `renderdoc` | `python -m renderdoc_mcp` + `C:\Program Files\RenderDoc` | for capture analysis only (W34/W35 GPU work); hooks must stay log-only, no RenderDoc in the boot path |

Already-connected built-ins worth using: `node-repl` (the manifest TOMLs must be edited via node
tooling, never by hand — `PROGRAM_GUIDE` §11), `browser-use`/`WebSearch` (Xenia/XenonRecomp upstream
semantics — cite the file:line into `.research/xenia/` too, it is a local checkout).
`qoder-qmind`/`sites`/`canvas` are irrelevant here; don't spend turns on them.

## Known conflicts / hazards in this directory (audit 2026-09-20 17:35)

- **Two agent configs.** `opencode.json` (+`.opencode/`, both gitignored) declares the *same* IDA and
  RenderDoc servers with a different schema. `.qoder/settings.json` is now the Qoder-side copy;
  keep them semantically identical and note which one you changed. `.gitignore` also ignores
  `.mcp.json` — that filename is **not** read by Qoder, don't create it.
- **`.qoder/` is NOT gitignored**, so `settings.json` and the skills are committed. They contain
  absolute machine paths (`C:\Users\abdul\...`) — fine for this single-user repo, never add a
  secret/token here; use `.qoder/settings.local.json` for per-machine overrides.
- **Duplicate plan file.** `CODE_OPTIMIZATION_PLAN.md` (repo root) and `docs/CODE_OPTIMIZATION_PLAN.md`
  both exist; the **docs/ one is authoritative**, and the root one's Phase 0 is VOID (it edits
  `generated/`, do-not #11). Delete the root duplicate as part of T37.1 — do not follow it.
- **Two task queues.** `LONG_TODO_MASTER.md` §2 is the durable queue; the agent `TaskCreate` list is
  per-session scratch only. Never let a queue item live in only one of them.
- **Root junk (untracked, not ignored):** `11`, `err.txt`, `NUL.obj`, `crash_dump.txt`,
  `crash_log_early.txt`, `fix_stubs_iter.py`, `fix_stubs_self.py`, `mcla_jts_regen.toml`,
  `write_opt_plan.bat`. Docs cite `tools/fix_stubs_*.py` — the scripts are at the repo root. Move
  or delete via T37.1; do not `git add -A` (it would commit them).
- **`git add -A` is unsafe here** — stage named paths only, and `git add -f docs/...` when a doc is
  newly tracked.

## Non-negotiable project constraints

Retail content only (`xarchive_cache.rpf` + audio/music; never `mc4/art`). Guest pointers are
32-bit guest VAs read through the checked helper with explicit endianness
(`ReadU16BE`/`ReadU32BE`/`ReadF32BE`) — no `reinterpret_cast` on guest data. Census hooks capture
state only: no D3D12 calls, no `RegisterFile` dependencies, no invented draw data. No ReXGlue SDK
dependency — from LARecomp/BadassBaboon take guest *facts* only (addresses, timings, quirks), never
their architecture or `rex::` runtime. Do not pop stash
`session33-audlo-forensics-gpu-device-capture-hardening` (it regresses boot). Commit only when
asked.
