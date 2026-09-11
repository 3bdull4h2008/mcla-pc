# Ghidra MCP Integration — MCLA Native PC GPU

## Purpose
Provides programmatic access to Ghidra for reverse-engineering Xbox 360 (PPC) binaries, Xenos microcode, and ReXGlue recompilation output.

## Architecture (verified 2026-09-10)
- **Ghidra install:** `E:\ghidra_12.1.2_PUBLIC` (not `C:\Program Files\Ghidra`, which is empty).
- **Extension:** GhidraMCP 6.0.0 + XEXLoaderWV installed under
  `%APPDATA%\ghidra\ghidra_12.1.2_PUBLIC\Extensions\` and
  `E:\ghidra_12.1.2_PUBLIC\Extensions\`.
- **Headless HTTP server:** `com.xebyte.headless.GhidraMCPHeadlessServer`
  launched via Ghidra's `support\launch.bat` (needs Ghidra classloader —
  raw `java -cp GhidraMCP.jar` fails with `ClassNotFoundException: ghidra.GhidraLaunchable`).
- **Launcher:** `C:\Users\abdul\.config\opencode\ghidra-mcp\run-ghidra-mcp-headless.bat`
  → HTTP `127.0.0.1:8089`. Keep this process running for RE work.
- **MCP client:** `bridge-mcp-ghidra.exe` (stdio) registered in
  `~/.config/mimocode/mimocode.jsonc` as `mcp.ghidra`. Talks to :8089.

## MCP Server
- **Command**: `C:\Users\abdul\.local\bin\bridge-mcp-ghidra.exe --lazy --default-groups listing,function,program,xref,analysis,documentation`
- **Timeout**: 30s
- **Enabled**: true (engine config; requires new conversation after edit)

## Start the headless backend
```bat
C:\Users\abdul\.config\opencode\ghidra-mcp\run-ghidra-mcp-headless.bat
```
Expect: `HTTP server started on 127.0.0.1:8089` / `Registered 245 REST API endpoints`.
Load `E:\mcla pc\game_data\default.xex` via tools if not preloaded.

## Available Tools (ghidra_*)
| Tool | Description |
|------|-------------|
| `ghidra_analyze` | Run analysis on current program |
| `ghidra_list_functions` | List all functions in program |
| `ghidra_get_function` | Get function details by address/name |
| `ghidra_get_instructions` | Get instructions for address range |
| `ghidra_get_references` | Get cross-references to/from address |
| `ghidra_get_data` | Get defined data at address |
| `ghidra_create_label` | Create label at address |
| `ghidra_set_comment` | Set comment at address |
| `ghidra_get_program_info` | Get program metadata (arch, endian, etc.) |

## Usage Patterns
1. **PPC Function Discovery**: Load recompiled `.elf`/`.exe`, find `xe_*` entry points
2. **Xenos Microcode Analysis**: Disassemble shader microcode blobs from guest memory
3. **Struct Recovery**: Use `ghidra_get_data` + `ghidra_get_references` to reconstruct guest structs
4. **Hook Target Identification**: Trace from known draw calls to find hook insertion points

## Best Practices
- Always use `--lazy` flag for faster startup on large programs
- Filter by address range when possible (guest RAM: `0x00000000`–`0x1FFFFFFF`)
- Combine with `reverser` agent for PPC-specific analysis
- Export findings to `.research/` for persistence across sessions

## Distilled-output discipline (S-B "writing tools for agents", 2026-09-03)
- Ask for **addresses + types + pseudocode**, never raw dumps — the bridge
  response goes straight into agent context; a full listing wastes the window
  (auto-compaction is OFF in this project).
- **Decompile first**: prefer the decompiler output over instruction listings;
  drop to raw disasm only for PPC idioms the decompiler mangles.
- Parameter vocabulary: pass `guest_address` style names and expect
  file:line-citable answers; every claim gets a TU citation or it is folklore.
- Two-source law: an address claim that drives host code needs generated-TU
  text AND (Ghidra or IDA) agreement before being trusted.
- If tool answers degrade, review the tool's own description/prompt first —
  tool text is code (see playbook Part E).

## Troubleshooting
- **Connection refused**: Ensure Ghidra headless is installed and `bridge-mcp-ghidra.exe` is in PATH
- **Analysis incomplete**: Run `ghidra_analyze` before querying functions/data
- **Wrong architecture**: Verify program is loaded as `PowerPC:BE:64:default`