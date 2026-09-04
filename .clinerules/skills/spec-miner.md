---
name: spec-miner
description: Reverse-engineering legacy/undocumented Xbox 360 Xenos GPU code
---

# Spec Miner — MCLA Native PC GPU

## Purpose
Extract authoritative specifications from undocumented Xenos GPU microcode, ReXGlue recompilation output, and guest memory structures.

## Workflow
1. **Identify target**: Hook address, microcode blob, guest struct offset
2. **Load in Ghidra**: PPC ELF for code, raw microcode for shaders
3. **Trace data flow**: From game logic → Xenos registers → command processor
4. **Document findings**: Struct layouts, register maps, command formats
5. **Cross-reference**: Xenia, XenosRecomp, UnleashedRecomp in `.research/`

## Key Techniques
- **PPC function discovery**: `xe_*` entry points, draw call thunks
- **Microcode disassembly**: Xenos ALU/TEX/VF fetch/export instructions
- **Struct recovery**: `ghidra_get_data` + `ghidra_get_references` on guest RAM
- **Command processor RE**: PM4 packet formats, register state
- **Two-phase decode** (from SK²Decompile, adopted 2026-09-03): skeleton
  pseudo-C with UNNAMED fields first, then a second pass assigning
  provenance-backed names. Never name a field in the same pass that first
  reads it.
- **Silent-failure law** (BadassBaboon retraction): "grep displacements to
  prove a field unused" is WRONG — by-address args are invisible to grep;
  wrong offsets fail SILENTLY. Assert every offset against a runtime census
  before trusting it.

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
- All offsets/endianness verified via `security-auditor`
- Unknown fields marked `TODO(research)` — never defaulted
- Findings committed to `.research/` for persistence
- Use playbook template T1 (`docs/AI_PROMPT_PLAYBOOK.md`) for decode requests;
  two-source rule per address claim (generated TU + Ghidra/IDA)