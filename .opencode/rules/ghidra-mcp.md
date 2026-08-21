# Ghidra MCP Integration — MCLA Native PC GPU

## Purpose
Provides programmatic access to Ghidra for reverse-engineering Xbox 360 (PPC) binaries, Xenos microcode, and ReXGlue recompilation output.

## MCP Server
- **Command**: `bridge-mcp-ghidra.exe --lazy --default-groups listing,function,program,xref,analysis,documentation`
- **Timeout**: 30s
- **Enabled**: true

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

## Troubleshooting
- **Connection refused**: Ensure Ghidra headless is installed and `bridge-mcp-ghidra.exe` is in PATH
- **Analysis incomplete**: Run `ghidra_analyze` before querying functions/data
- **Wrong architecture**: Verify program is loaded as `PowerPC:BE:64:default`