# PS5/STATIC-RECOMP NOTES (2026-10-13, subagent research, mechanisms only)

> Question: how do static-recompilation projects convert system libraries,
> and what transfers to MCLA (XenonRecomp PPC->C++ + hand-HLE imports)?
> No code copied. License boundaries at the bottom.

## How others replace library calls

- **UnleashedRecomp (same toolchain, direct precedent):** linker weak-override,
  not import-table rewrite. Recompiler aliases each guest fn to `__imp__`;
  host defines `PPC_FUNC(__imp__X)` and wins at link. Typed shims via
  `GUEST_FUNCTION_HOOK` (ints r3-r10, floats f1-f13, pointers base+u32,
  returns r3/f1). Registry = ~80 `GUEST_FUNCTION_HOOK` lines; unknowns =
  empty `GUEST_FUNCTION_STUB` bodies. Mid-function patches via
  `[[midasm_hook]]` in the TOML. Runtime (window, stacks, r13, XEX load)
  is ours, not the recompiler's. We already mirror all of this
  (`src/kernel/function.h`, `ppc_func_mapping.cpp`, `config/mcla_xenonrecomp.toml`).
- **shadPS4 (PS4, dynamic — no static equivalent exists):** 3-tier resolve
  (HLE symbols -> loaded SPRX exports -> counted generic stub that logs
  NID+caller and returns zero). Symbols qualified by
  name+library+version+module. GPU libs are host packet-builders with arg
  validation, not recompiled code; shaders go GCN->IR->SPIR-V (parallels
  our Xenos->HLSL path).
- **PS5 scene (NID patching, bbport):** offline import-slot redirect +
  SDK-version downgrade for drifted builds; per-game native loaders for
  same-ISA ports (bbport runs x86-64 natively, only GPU via renderer).
  True PS4/PS5 static ISA translation does not publicly exist; closest
  true-static models are PSP (`pspreco`: offline MIPS->C + runtime/hle).

## Honesty discipline worth stealing

- UnleashedRecomp: hash-gated inputs (installer rejects mismatched
  disc/update regions) + per-build TOML pins (file/patch/switch-table/
  function boundaries). Drift dies at the door.
- shadPS4: version-qualified symbols, SDK-gated preload, every stub logs;
  unresolvable -> address 0, never a fake pointer. Only deliberate,
  counted stub-success exists (fake handles from a counter).
- MCLA already refuses loudly in the same spirit (INVALID_INFO_CLASS,
  XTL-FREE probe buckets, SYNTH-PROFILE census) — keep extending it.

## 5 transferable techniques (mechanisms, clean-room)

1. **Version-qualified hook registry:** (library, version, module) per
   `GUEST_FUNCTION_HOOK` + listing; kills silent cross-build aliasing.
2. **Tiered resolve with counted-stub fallback:** classify every `__imp__`
   as HLE-real / counted-stub at boot; stubs log + return failure
   NTSTATUS, never success.
3. **Hash-gated input + TOML pin:** hash default.xex before recompile;
   refuse mixed/patched inputs in config.
4. **Validating shims:** check buffer/size/flags, write only well-formed
   output, error code on violation (already our NtQueryInfo shape).
5. **Split CPU/GPU libraries:** static game code, host packet/renderer
   translators for GPU syslibs, pipeline pre-warm at load.

## License boundaries (checked this pass)

XenonRecomp MIT (notice retention). UnleashedRecomp GPLv3 — do NOT lift
shim bodies; re-derive from guest bytes. PS5SDK GPLv2 — same rule.
shadPS4/Xenia/ps5rs/backports: check each LICENSE before reuse; treat
as inspiration-only regardless.
