# IDA Pro MCP Integration — MCLA Native PC GPU

## Purpose
Second RE workbench alongside Ghidra for the Xbox 360 (PPC) binary: decompiler-
quality pseudocode (Hex-Rays) for hook-target confirmation, struct recovery,
and xref sweeps on hot paths (`sub_82412F98` fence family, `sub_82411E98`,
kick/dispatch chains). Use IDA when Ghidra output is ambiguous; treat both as
evidence sources and cross-check before claiming a decode.

## Architecture
- **Plugin** (`mcp-plugin.py`, stdlib-only): runs INSIDE IDA, serves JSON-RPC
  over HTTP at `127.0.0.1:13337` (scans up to +9 ports if occupied).
- **Proxy** (`ida-pro-mcp.exe`, venv `C:\Users\abdul\.local\share\mcp\idamcp-venv`):
  stdio MCP <-> HTTP bridge; this is what opencode launches. Dependency pin:
  `ida-pro-mcp==1.4.0` with `mcp>=1.9,<2` (SDK 2.x removed
  `mcp.server.fastmcp` - do not blindly upgrade).
- **IDA**: Professional 9.3 at `C:\Program Files\IDA Professional 9.3`;
  IDAPython = Python 3.14.6 via vendor `idapyswitch` default.

## Headless mode (preferred for autonomous work)
No GUI, no manual arming. One-time prerequisites (DONE on this machine):
- `py-activate-idalib.py` ran with the venv python; `idapro-0.0.7` wheel
  installed into the venv.
- Decrypted/decompressed PE image extracted:
  `build\cache\mcla_pe.bin` (from `game_data\default.xex` via
  `.research/360tools/tools/extract_pe.py`; stock IDA cannot parse XEX).
Start the server (long-lived):
  `idamcp-venv\Scripts\idalib-mcp.exe --host 127.0.0.1 --port 8745
   "E:\mcla pc\build\cache\mcla_pe.bin"`
Then point the proxy at it - opencode.json `mcp.ida.command` args must include
  `["...\\ida-pro-mcp.exe", "--ida-rpc", "http://127.0.0.1:8745"]`
(first analysis of the 10 MB PPC image takes minutes; the .i64 lands next to
the .bin and subsequent starts are fast).

LICENSE PREREQUISITE: idalib fails with "Cannot continue without a valid
license" until IDA Pro has been first-run and licensed in the GUI once
(no .hexlic existed as of 2026-08-25). Complete GUI activation, then use
headless mode.

## Arming (GUI alternative, required every IDA session)
1. Open the MCLA XEX/IDB in IDA (a binary must be loaded or the plugin menu is hidden).
2. `Edit -> Plugins -> MCP` (hotkey Ctrl-Alt-M) starts the HTTP server.
3. opencode connects through the proxy automatically; verify with the
   `check_connection` tool.

## Available Tools (ida_*)
Core set exposed by the proxy (names prefixed `ida_` in-session):
`check_connection`, `get_metadata`, `get_function_by_name`,
`get_function_by_address`, `decompile_function`, `disassemble_function`,
`get_xrefs_to`, `get_entry_points`, `set_comment`, `rename_local_variable`,
`declare_c_type`, `get_global_variable`, `list_strings`, `get_imports`,
plus read/write memory/register helpers. Treat writes (renames/types/comments)
as session-local until the IDB is saved deliberately.

## Usage Patterns
1. **Fence-family decode**: `decompile_function` on sub_82412F98 /
   sub_82425C18 / sub_8244FEC8 to confirm poll/snapshot semantics decoded
   from generated TUs; reconcile against ppc_recomp.*.cpp line evidence.
2. **Hook targeting**: `get_xrefs_to` on candidate stores (doorbell,
   writeback, dev[+10896]) before registering hooks in `src/hooks`.
3. **Struct recovery**: `declare_c_type` for guest structs once field offsets
   are measured; keep names aligned with `.research/findings/ghidra` exports.
4. **Cross-tool rule**: any address claim that drives host code must be
   confirmed by TWO sources (generated TU text, Ghidra, or IDA) - never one.

## Best Practices
- Start the plugin BEFORE spawning heavy opencode subagents (reverser/debugger)
  so they don't burn turns on connection errors.
- Prefer `decompile_function` over raw disasm for control-flow questions;
  fall back to `disassemble_function` for PPC idioms Hex-Rays mangles.
- Export durable findings to `.research/findings/ida/` (same discipline as
  the ghidra export) - IDBs are not diffable; markdown/csv dumps are.
- Keep the venv pinned; when upgrading ida-pro-mcp, re-run
  `...ida-pro-mcp.exe --install` and re-test `check_connection`.

## Troubleshooting
- **Connection refused**: plugin not started (step 2 above), wrong IDB focus,
  or IDA was restarted without re-arming. Port scan means an old instance
  still holds 13337 - check `netstat -ano | findstr 13337`.
- **After install/config changes**: fully quit AND restart both IDA and
  opencode; config is load-once.
- **IDAPython broken**: re-run `idapyswitch.exe` in the IDA dir; if 3.14.6
  misbehaves pick installation #2 (3.13.13). Plugin requires >=3.11.
- **PYTHONPATH warning**: machine-global `PYTHONPATH` points at DaVinci
  Resolve scripting modules. Harmless for the stdlib-only plugin; opencode
  clears it for the proxy via `environment.PYTHONPATH=""`. Do not delete the
  user-global variable.
- **Installer side effects**: `--install` also configured Cline, Claude Code,
  and LM Studio on this machine (their standard behavior); remove there if
  unwanted - project config here is authoritative.
