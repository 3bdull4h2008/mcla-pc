# Spec Miner — MCLA Native PC GPU

(Ported from `.opencode/skills/spec-miner.md`)

## Purpose
Extract authoritative specifications from undocumented Xenos GPU microcode, ReXGlue recompilation output, and guest memory structures.

## Workflow
1. **Identify target**: Hook address, microcode blob, guest struct offset
2. **Load in Ghidra** (`ghidra` MCP): PPC ELF for code, raw microcode for shaders
3. **Trace data flow**: From game logic → Xenos registers → command processor
4. **Document findings**: Struct layouts, register maps, command formats
5. **Cross-reference**: Xenia, XenosRecomp, UnleashedRecomp in `.research/`

## Key Techniques
- **PPC function discovery**: `xe_*` entry points, draw call thunks
- **Microcode disassembly**: Xenos ALU/TEX/VF fetch/export instructions
- **Struct recovery**: ghidra data/read + xref tools on guest RAM
- **Command processor RE**: PM4 packet formats, register state

## Output Format
```markdown
## [Component Name]
**Guest Address**: 0xXXXXXXXX
**Struct Layout**:
  offset 0x00: u32 field_a (BE)
  offset 0x04: f32 field_b (BE)
**Registers**: XREG_XXX = 0xXX
**Commands**: PM4 type 0xXX = [fields]
**References**: Xenia::Xenos::Class::method, XenosRecomp::file.cpp:line
```

## Validation
- All offsets/endianness verified via a security-audit pass
- Unknown fields marked `TODO(research)` — never defaulted
- Findings committed to `.research/` for persistence
