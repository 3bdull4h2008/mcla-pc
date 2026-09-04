# Handoff — MCLA Native PC (E:\mcla pc) — 2026-08-22 (session 3)

**Base:** `11a8e97` → commits `270e429` (ship-blockers) + `d4c16bd` (phase-4 groundwork). Tree clean.
**Direction locked by user:** NO PM4 emulation. Follow UnleashedRecomp's device-table technique exactly
("we follow the succession"). CP/doorbell code stays as infrastructure but is deprioritized.

## MILESTONE: XGPU device boundary captured + FP-table seam proven

The UnleashedRecomp technique is now live against MCLA:

1. **Device-create hook works.** `src/gpu_device.cpp` overrides guest `sub_82413588`
   (= XGPU/D3D CreateDevice; allocates the 0x5E00 GuestDevice, out-pointer in r8)
   via global-scope `PPC_FUNC(sub_82413588)` strong override of the generated weak
   alias, intercept+passthrough to `__imp__sub_82413588`.
   - **TWO linker gotchas cost hours — do not regress:**
     a) The override MUST be at GLOBAL scope. Inside `namespace mcla::gpu` it
        mangles differently (`?sub_82413588@gpu@mcla@@...`) and silently never binds.
     b) Read `ctx.r8` BEFORE calling the original — recomp ABI clobbers volatile regs.

2. **GuestDevice layout ground truth (dump @ runtime, device #1 = A0003080):**
   - `+0x00 dirtyFlags[8]` (init all-ones)
   - `+0x30` ring/cursor ptrs (C62345BC / C62B4480 / C62B43E0 — matches GPU_ctx+0x30!)
   - `+0x40 setRenderStateFunctions[0x65]` → ends 0x1D4; unused slots default-stub =
     `0x82130000` (= PPC_CODE_BASE); real handlers 0x82413950..0x82415C20 family
   - `+0x1D4 setSamplerStateFunctions` (~0x50 bytes, 824159xx/82415Axx family)
   - `+0x224..`: more stubs (0x821A5CC0) then further tables — layout beyond diverges
     from SWA's GuestDevice; map before touching.
   - Device create is called TWICE (A0003080, A0009100) from sub_8217AC30 (reverser "×2").
   - Publish chain: *(u32*)0x82000864 = 0xBE010100 → device VA (slot holds a pointer to
     a pointer). Poller slot [0x82839254] receives the SAME device pointer via r8.

3. **FP-table redirect seam PROVEN (rung-2):**
   - Synthetic thunk VA = `PPC_CODE_BASE + PPC_CODE_SIZE` = `0x827CD054` (lands just
     past highest real mapping 0x827CCBC0 — no collision).
   - `g_memory.InsertFunction(0x827CD054, thunk)` + BE table writes verified by
     readback; `FindFunction(0x827CD054)` resolves.
   - Log line: `redirected 10/101 default RS slots -> 827CD054 | readback=ok | thunkResolved=true`.
   - Zero runtime hits yet (expected — only *default/unimplemented* states redirected;
     healthy boot doesn't call them). Next proof: passthrough-thunk a REAL handler slot.

## KEY DISCOVERY THIS SESSION

All GPU init seen in logs (VdInitializeEngines/VSync thread/ring buffer) comes from THE
GUEST's own driver chain — NOT from InitGpuBackendManual/GpuContextPoller (those never
fire; poller slot stays 0 because... it IS 0x82839254 which receives the device only at
create — poller races and loses; manual path is dead code now).
Also: `m_dispatcher` is NEVER instantiated (app.cpp:66 `if (m_dispatcher)` always false)
→ ALL dispatcher-based patches in patches.cpp have always been dead. Only static
GUEST_FUNCTION_HOOKs + link-time PPC_FUNC overrides actually run. Decide later whether
to revive or delete that layer.

## NEXT STEPS (in order)

1. Passthrough-redirect ONE real RS handler slot (e.g. +0x68 = 0x82414078), log
   state/value args, confirm runtime hit during boot/gameplay.
2. Implement host SetRenderState semantics per SWA reference (state/4 index into table;
   read/write GuestDevice fields; set dirtyFlags) backed by d3d12_backend.
3. Map sampler table (+0x1D4) same way. Then find draw entry (SWA analog:
   DrawIndexedPrimitive is NOT in the RS table — SWA dispatches draws elsewhere; locate
   MCLA's equivalent via reverser around sub_82411180/sub_82411618 callers).
4. Retire InitGpuBackendManual/GpuContextPoller once real create drives everything
   ("no manual seeding" gate).
5. gpu_cp.cpp doorbell/drain stays available if we ever need PM4 fallback; currently
   unrouted (CpInstallMmioRouting sits in dead patches.cpp section).

## METHOD NOTES

- Weak-override binding requires EXACT mangled-name match at global scope; verify with
  dumpbin /SYMBOLS on both objects when a hook "doesn't fire".
- build\cache\mcla.log appends across runs — slice runs by last "kernel heaps" line.
- LSP phantom errors fixed via .clangd + CMAKE_EXPORT_COMPILE_COMMANDS (commit d4c16bd).

## CORRECTION (same day, later): G-CORPUS gate framing was wrong
User correction accepted: shader translation is NOT blocked on future ".fxc captures".
- Validators scan for Rockstar .fxc CONTAINERS; existing corpus
  (.research/findings/xenia/shader_dumps/shaders/*.ucode.*) is RAW MICROCODE and
  translates fine via our custom XenosRecomp pipeline (xenos_decode_validator reads
  single ucode files successfully - verified).
- Gap = validators' DIR-SCAN filter ignores ucode files. Fix (small): extend filter
  to accept *.ucode.* / raw microcode in shader_pipeline_validator +
  phase3_validator + xenos_decode_validator dir modes -> point args at
  shader_dumps\shaders -> FLIP G-CORPUS-* gates from tracked to ENFORCED.
- Also: extracted cache (game_data/mcla extracted cache, mc4/) holds 2627
  extensionless RAGE resources; shader containers may live inside .xrsc/unextracted
  rpfs - open recon item, NOT a gate dependency.

## SESSION 3 ADDENDUM (final): corpus gates live
- Commit 45290fa: xenos_decode_validator ScanDirectory now accepts *.ucode.* raw
  microcode (dual-path: container-magic -> ParseFxc, else DecodeMicrocode) and
  scanned 1612 shaders from .research/findings/xenia/shader_dumps.
- Gate system: G-CORPUS-XENOS-DECODE ENFORCED (files>=1000). NEW tracked gate
  G-XENOS-DECODE-CLEAN exposes decoder-quality findings: unknown_instrs=3496,
  oob=26650, returns=198 across corpus (~2.2/~16.5/~0.1 per shader) - these are
  DecodeMicrocode gaps to fix, NOT corpus corruption. Fixing flips tracked->pass.
- shader_pipeline + phase3 validators still need Rockstar .fxc container input
  (tracked); extending them for raw ucode = next-session option.
- NEXT SESSION ORDER: (1) P4 step 2 - passthrough-thunk ONE real RS slot
  (+0x68=0x82414078 family), flip G-P4-RS-THUNK-HITS enforced>=1; (2) debug
  overlay for human; (3) extend other two validators for ucode; (4) fix
  DecodeMicrocode unknown/opcode gaps using G-XENOS-DECODE-CLEAN as the bar.
- GOTCHA reminder: single mcla.exe instance during gates; cmd quoting breaks on
  "E:\mcla pc" spaces - use temp .cmd files for long build/run commands.

## PIVOT FINDING (2026-08-23): MCLA does NOT dispatch RS via device FP-tables
Experiment: redirected ALL 91 real setRenderStateFunctions slots (both devices,
selftest ok) to host thunks -> ZERO hits across full boot+menu soak. Plus slot
+0x68 alone: zero hits. Conclusion: like Xenia-model drivers, MCLA's runtime
state/draw path goes DIRECTLY to PM4-emitting helpers (sub_82411180/sub_82411618/
sub_824238E0/sub_82422EF8 - all direct-called, never table-stored).
=> UR's table-redirect technique has NO target here. The MCLA boundary = those
   four helper functions (+ present/VSync workers sub_82429328/9428/96E8).
   They are GLOBAL-SCOPE overridable exactly like sub_82413588 (proven pattern).
G-P4-RS-THUNK-HITS demoted to tracked (premise invalid). NEXT: override
sub_82411180 (draw-shaped) via PPC_FUNC(sub_82411180)+passthrough, log args,
gate on >=1 hit during boot - same discipline, correct seam.
Probe infrastructure kept in gpu_device.cpp (log-only thunks harmless).

## BREAKTHROUGH (2026-08-23): helper-function boundary LIVE
Global-scope PPC_FUNC(sub_82411180)/PPC_FUNC(sub_82411618) overrides intercept
MCLA's real state/draw submissions. Boot evidence: sub_82411180(r3=DEVICE
A0003080, r4=C62B44EC ring-region) + sub_82411618(r3=A0009100). G-P4-RS-THUNK-HITS
PASS. NEXT: decode arg semantics per call site (Ghidra/reverser), then implement
capture -> RenderCommand queue (P4.5'). RS-table thunks stay as dead research.

## CHOKE POINT ARGS CAPTURED (2026-08-23, final)
sub_82411640 override live: hit #1..#N during boot with dev=A0003080,
r4=00000001 (type/tag), r5=<guest STACK ptr 0x8EFFFxxx> (packet descriptor built
by caller), r6=payload dword-count (observed 0x20 and 0x04 - matches Function_
8241E498-style paired PM4 writes). NEXT SESSION: read r6 dwords BE from r5 in
the override BEFORE passthrough -> dump captured packets -> correlate against
Xenos reg map for BEGIN_END/draw classes -> feed RenderCommand queue (P4.5').
Gate note: HELPER-thunk pattern already counted by G-P4-RS-THUNK-HITS metrics.
