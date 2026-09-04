# Blocker Trace Investigation — 2026-08-24

Session: tooling inventory + precise static trace (gate-cracker) + cross-field
research sweep (research-scout ×2) + RAGE-community recon. Read-only; no code
changed. Base commit 96ddd54.

---

## A. Tooling inventory (verified live)

| Asset | Status | Note |
|---|---|---|
| Ghidra MCP (`bridge-mcp-ghidra.exe`) | ✅ present+configured | globally disabled in opencode.json; enabled per-agent (reverser/debugger/architect). Route via subagents |
| RenderDoc MCP | ✅ binary present | not applicable to boot crash |
| PIX MCP | ✅ binary present | not applicable to boot crash |
| LLVM binutils | ✅ llvm-objdump/symbolizer/pdbutil | PPC-capable disasm available CLI-side |
| Skills | ✅ mcla-stall-forensics · debugging-wizard · mcla-phase-gate · second-brain · spec-miner · the-fool | stall-forensics loop is the canonical method |
| Agents | ✅ gate-cracker (+13 catalog agents) | gate-cracker delivered this session's decode |
| second-brain MCP server | ❌ never attached | file ledger `.opencode/memory/` remains the store (schema per skill) |

Nothing needed downloading beyond verification; arsenal was already complete.

---

## B. Gate-cracker static decode (all claims cited to generated TUs)

### B1. Dispatch site fully resolved

Chain: `sub_825FC5E0` (task submit, 224-byte task, ctor `sub_825FA2E8`,
vtbl `0x82086E0C`, writes `[task+4]=arg5` unconditionally —
ppc_recomp.124.cpp:7863–7977) → `sub_825FDB30(r30=container, r31=task)`
(ppc_recomp.124.cpp:11147–11240) → path A `sub_8260A710(listPtr, task)` /
path B `sub_8260A7D0` / sibling tail `sub_8260A770` → walk node chain:

```
entry = [container+12] + rotl16(u16[task+164],3)      ; 124.cpp:11170–11195
head  = [entry+4]                                      ; 125.cpp:7792–7799
loop: obj = [node+0]                                   ; 125.cpp:7801–7802
      fn  = [obj+4]   -> mtctr -> bctrl                ; 125.cpp:7807–7813  ← CRASH
      next = [node+12]                                 ; 125.cpp:7814–7819
```

- A770 reads `[obj+8]`, A7D0 reads `[obj+12]` — three handler slots/vtable.
- The two historical crash reports are ONE fault: FDB30+0x158 (caller frame)
  over A710+0x116 (callee frame); host rva drift per build explains the rest.
- ALL family entry points (FDB30/FC5E0/A710/A770/A7D0): **zero direct
  callers, zero immediate materializations** in all 179 TUs → reached only
  via data-section vtables. Static registrar identification requires scanning
  the DECOMPRESSED XEX for vtable words holding these addresses (or runtime
  lr capture, probe P1).
- E58F0 producer hypothesis ELIMINATED: Function_821E58F0 writes only
  `record[+0]` (allocation staging, pass-1 array A tag 1 / pass-2 array B
  tag 3, TLS allocator vtbl+8, mode byte @abs 0x827BCE81;
  ppc_recomp.21.cpp:4529–5006). E58 tail's `[op+4]` store is BCB10's slot
  token return, NOT a fnptr (21.cpp:5393–5417).

### B2. "Raw host pointer 0x7E780000" MYTH BUSTED — it is arithmetic on ctr=0

`PPC_LOOKUP_FUNC(x,y) = *(PPCFunc**)(x + 0x829E0000 + (u32)(y−0x82130000)*2)`
(ppc_context.h:118–122). With y=ctr=0:
slot = base + 0x829E0000 + 0xFBDA0000 = base + 0x17E780000 = **0x27E780000**
→ outside 4 GiB window [0x100000000,0x20000000) → guaranteed READ AV whose
low 32 bits print as …7E780000 (VEH prints %016zX; earlier transcriptions
dropped the leading `2`). No raw-host-pointer-in-guest-struct bug class here;
no non-macro loads exist near the dispatch (125.cpp:7770–7833,
124.cpp:11126–11217).

Contributing hazard: failed checked reads return **0 silently**, not a
sentinel (src/guest_memory.h:75–79 + guest_memory.cpp:31–34 reject <0x1000),
so obj=0 → fn=`PPC_LOAD_U32(4)`=0 → ctr=0 with no diagnostic.

### B3. Family split (corrects sessions 19–22 framing)

- **Family 1 — async-op ring** (E58/E58F0/BCB10/BC140, op[+4]=slot token):
  what sessions 19–22 decoded; NOT the crasher. Session-20 NODE dump
  (slot[+4]=0x50000000) instrumented THIS family.
- **Family 2 — task runner** (FC5E0/FA2E8/FDB30/A710/A770/A7D0 +
  getters ED470/ED480: container at `[owner+28]`, idx at `[owner+32]`,
  alt path via `[obj+128]`; ppc_recomp.122.cpp:42550–42587): the crasher.
  Same defect CLASS (unfilled structure consumed as pointer), different site.

Two readings remain, discriminated only by probe P1:
- **Reading A (instance split):** registration ran against a different
  container instance than dispatched (precedent: ring-A/B semaphore twins).
- **Reading B (never ran):** registering init diverged earlier; our RAM is
  zero-filled where HW may leave garbage → unfilled node reads {0,0,0} →
  obj=0 → fn=0 → ctr=0.

### B4. 0x50000000 identity + REAL BUG FOUND in NtAllocateVirtualMemory

- NO TU computes any 0x5000xxxx value (zero lis/ori forms; rg sweep).
- OUR allocators can NEVER return it: both NtAllocateVirtualMemory and
  MmAllocatePhysicalMemoryEx allocate from o1heap arena **[0xA0000000,
  0x100000000)** (imports.cpp:976–999,1590–1613; heap.cpp:7–8,131–155).
- 0x40000000–0x7FFFFFFF = guest VIRTUAL 64 KB-page region (Xenia cpu.md);
  game's own vmem manager carves it (its base global [0x8294A5A0]=0x40000000
  is guest state).
- **BUG:** `NtAllocateVirtualMemory` rubber-stamps explicit-base requests:
  `if (base!=0 && Translate(base)) { *regionSize=size; return 0; }` — and
  Translate succeeds for ANY addr <4 GiB with no allocation check
  (imports.cpp:981–989). We ACK reservations we never made. HW would fail/
  commit differently; game then derives structures from a region nobody
  populated. Fix direction: honor MEM_COMMIT/reserve state, fail loud on
  unbacked bases (per xenia contrast: xenia silently masks phys &0x1FFFFFFF;
  we should FAULT loudly instead).
- Buffer populator candidates (post-ME_INIT deprioritization): CPU DMA
  ordered after task dispatch, or init code that never ran due to earlier
  divergence. Xenia negative evidence: ME_INIT just drains words into
  `me_bin_`, never executes microcode; no known title depends on ME side
  effects (command_processor.cc).

### B5. Ranked probes (log-only, MCLA_LOG_*, throttled n<=16||n%500==0)

| # | Probe | Discriminates |
|---|---|---|
| P1 | Global-scope `PPC_FUNC(sub_825FDB30)` census: log r3/r4, u16[task+164], byte[task+172], entry, head, obj, fn, caller lr — checked reads BEFORE passthrough | which cold level (head? obj? fn? container?) + lr names the vtable dispatch site → next static target |
| P2 | Allocator return census (every VA in [0x40000000,0x80000000)) | kills/confirms "legit reservation" reading permanently |
| P3 | Value-watch: log checked stores whose VALUE==0x50000000 | exact planting instruction (stale-stack vs computed pointer) |
| P4 | One-shot debug scan of decompressed XEX for BE dword 0x825FDB30 (InsertFunction walk precedent, boot_host.cpp:67–70) | finds every referencing vtable statically-at-runtime |
| P5 | After P1 names cold level: fix the KERNEL-ROLE input gating the registrar (Reading B) or scoped single-instance convergence (Reading A) | honest fix; never seed fnptrs (rejected: bounds-guarding PPC_LOOKUP_FUNC alone would convert AV into silent wrong behavior) |

---

## C. Cross-field precedents (research-scout, primary sources)

Top transfers:
1. **UR #522/#1734** — recomp codegen flags (non_volatile_as_local) silently
   change which paths run; fix = per-function faithful semantics; bisect the
   function space. github.com/hedge-dev/UnleashedRecomp/issues/522,1734
2. **Dolphin #10732/#10761** — HLE answered an init poll too early → game's
   own fill loop starved forever. Audit what the guest polled right before
   the skipped branch. dolphin-emu/dolphin PR 10732
3. **RPCS3 #16907 (#6514)** — SPURS urgent-command FIFO ordering/reservation
   mismatch froze MGS4; consumer assumed order producer didn't guarantee.
   Wake/descriptor visibility ORDERING audit applies to our task ring.
4. **Xenia #1677→#1992** — shared-condition phantom wakes swallow real ones;
   per-object wait lists fixed it (validates our identity-resolution fix;
   residual risk: any remaining shared-cond wait can still eat wakes).
   UnleashedRecomp generation-counter = same class.
5. **Zelda64Recomp** — shipped escape hatch: replace guest scheduling boundary
   with host-side synchronous completion (Graph_TaskSet00); mesg queue
   rewrite w/ priority wakes; "only game threads block". Legitimately
   sanctioned last resort if prep pass proves unfixable.

Also: xenia#2056 (single unimplemented PM4 opcode wedges title),
xenia#1296 (sync-completed XOVERLAPPED breaks games → defer completion),
PCSX2 IPU/VIF ordering fixes (consumer must not outrun producer DMA),
xemu#34/#326 (OOB ranges silently wrap on HW — decide wrap-vs-fault
explicitly), Dolphin #5440 (interrupt too fast → delay completion),
morsisko/xFindOut + tokmakov.me hw-breakpoint producer-tracing methodology,
XenonRecomp #6 jump-table discovery workflow (indirect-dispatch auditing).

Documented-nowhere gaps (our niche): ME_INIT microcode effects; static-recomp
in-engine worker-pool fill-branch divergence; guest-VA-vs-phys misclassif-
ication producing false "zeroed buffer"; guest-address-aware watchpoints for
recomp hosts.

---

## D. RAGE/MCLA community recon (new strategic intel)

- **BadassBaboon/midnightclub** (github.com/BadassBaboon/midnightclub):
  ANOTHER team's completed static recomp of THIS EXACT GAME (Windows x64,
  ReXGlue 0.9.0 + prebuilt xenos plugin DLL). Game runs to gameplay (~50 fps,
  races, streaming) ⇒ our blockers are provably solvable.
  - TECHNICAL_NOTES.md + MCLA_workplan.md digested (commit 4dfb5c9):
    - Boot blockers: NONE documented (booted day-one on rexglue) — their
      runtime's kernel layer handled sync/tasks implicitly.
    - 0x825F0000–0x8260AFFF hole EMPTY on their side too: no labels for our
      dispatcher family anywhere.
    - Stub sweep: ~1.7M addresses stubbed at startup (0x82130000–0x827CD054,
      stride 4, ~450 ms); converts unmapped indirect call into logged no-op.
    - Functions reached ONLY indirectly must be marked is_function_start
      (their Phase 12: 25 registration fns → 513 script natives).
    - Guest facts bank: timebase 49,875,000 Hz (flt_82011110=2.00504e-8);
      frame timer sub_821BDA90 (fields 0x827D7500–7558); two fixed-step
      paths @0x821BDB58/loc_821BDB90; PM4 present-interval field @0x82419AA0
      built by sub_824199B0; mc_FlushDataCache @0x821D5510 = dcbf loop →
      identity+fence (largest single CPU saving, ~66 MB/s flush volume);
      clear_memory_page_state=false breaks minimap coherency (page-state
      init IS load-bearing); resolution_scale corrupts frustum aspects.
    - Tools: idaxex fork github.com/SaveEditors/idaxex; IDA↔recomp function-
      boundary sync script pattern (apply_rexglue_functions.py, 30,029
      entries); xenia-edge (github.com/has207/xenia-edge) carries MCLA-class
      rendering fixes; CodeX.Games.MCLA = RSC5 specs + 146k Jenkins-hash
      symbol table (no LICENSE — don't vendor).
    - Retraction list (don't repeat): 13 items incl. "grep displacements to
      prove field unused" is WRONG (by-address args invisible); wrong guest
      offsets fail SILENTLY — assert every offset.
- GTA-Network/IV-Network docs: RAGE class taxonomy (rage::rlTaskBase/rlTask,
  rlWorker pool, ThreadPool global, CRageDirect3D9Device hook-interface
  pattern, RenderVM hSemaphore/hRenderThread) — naming vocabulary for our
  family-2 container/listener system (RAGE-style observer dispatch).
- xenia-canary game-patches #14: MCLA grcore shader command names
  (AmbientOcclusion_draw, zprepass_*, generate_shadow_impostor*) — future
  renderer-phase corpus.

---

## E. Next actions (ordered)

1. P1 census override on sub_825FDB30 (global scope, register-only snapshot
   pre-passthrough) + P4 vtable-word scan in same run.
2. P2 allocator census alongside (cheap, permanent kill of one reading).
3. Fix NtAllocateVirtualMemory rubber-stamp (honest reserve/commit state,
   loud failure) — independent of P1 outcome, likely prerequisite anyway.
4. On P1's lr: identify registrar (decompressed-XEX scan or idaxex DB),
   then Reading-A/B-specific minimal kernel-role fix.
5. Keep freeze-line discipline: this stays KERNEL work; stop when frames
   flow through P4′ hooks.

RUN receipt template: append per-run lines to plan Investigation Record.
