# ROOT-CAUSE VALIDATION FINDINGS LEDGER (session 78b)

Pre-seeded by the planning model with already-proven facts (F-001..F-005).
Executor: append below, one block per finding, per docs/CHEAP_MODEL_EXECUTION_PLAN.md Part C.

---

## F-001  Fatal caller attribution in handoff is WRONG (lr is stale garbage)
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       H
- Priority:    P1
- Evidence:    Raw PPC disasm of sub_82189138: 0x8218926c = `stw r9,0xC(r3)`,
               0x82189270 = `add r9,r6,r9` — no bl/bctrl sets LR=0x82189270
               anywhere; fatal was reached via bctr (does not update LR);
               IDA xref of fmt string 0x8200B358 → referenced only at
               0x8218ca68 inside sub_8218C9D8.
- Notes:       Any past conclusion built on "caller = 0x82189270 /
               sub_82189138" is invalid. Re-audit any handoff claim that
               cites it.

## F-002  TRUE fatal chain solved (guest-native, working as coded)
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       G (the fatal itself is the game's own coded behavior)
- Priority:    P0-adjacent context (this is the terminal symptom, not the cause)
- Evidence:    IDA decompile sub_8218C9D8 (string xref 0x8218ca68; call site
               bl at 0x8218ca6c) + decompile sub_821C0E18 =
               `if (dword_8285FEA0) dword_8285FEA0(fmt); while(1);` + log
               `slot 0x8285FEA0 = 0x82130678` + GETDEV #40-#43 cascade in
               build/boot_stdout_78.log @19:13:04.763.
- Notes:       Chain: sub_8218C9D8 → sub_8218C650("embedded:/…")==-1 AND
               sub_8218C650(name)==-1 → byte_827D5C70!=0 → bl sub_821C0E18 →
               indirect call [0x8285FEA0] → host fatal dump. The open question
               is why BOTH lookups return -1, not the fatal itself.

## F-003  Fatal handler target 0x82130678 is a zero pad-hole in the image
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       I (until T1 identifies the host interceptor; likely D/H)
- Priority:    P1
- Evidence:    read_memory_bytes(0x82130678, 16) = all zero; IDA has no
               function there; yet runtime printed a formatted fatal dump →
               a host-side override owns this guest address.
- Notes:       On Xbox, guest word 0x8285FEA0 must be populated with a real
               handler pointer at some point (xref 0x8285FEA0 → writer W).
               If W is game/kernel init code that never ran or wrote a
               different value, THAT is a first-divergence candidate upstream
               of the fatal. T9.2 must resolve this.

## F-004  EMB76 census never fired in the fatal boot
- Task:        T1/T2 context (planning model)
- Type:        FACT
- Class:       I
- Priority:    P1
- Evidence:    grep -c EMB76 build/boot_stdout_78.log → 0, while
               mcla_patch_groups='all' and other censuses (GETDEV/MOUNT76/
               INFLATE/TSLAB/REBASE) all printed.
- Notes:       Either the embedded-device code path never executed, or the
               EMB76 hook triggers on an event that never happened. T1 must
               decode the hook's trigger before drawing conclusions.

## F-005  Fallback device holder is empty-but-allocated at fatal time
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       I (consistent with both "device never registered" and
               "registration ran but its writes vanished")
- Priority:    P1
- Evidence:    GETDEV-E1 lines: hold=A0084028 dcnt=0000 dcap=0001
               d0=CDCDCDCD vt0=00000000 (raw uninitialized pattern), repeated
               identically at #40–#43.
- Notes:       dcap=1 allocated but dcnt=0 and slot never written. F3 fork in
               the execution plan decides between the two hypotheses.

---

## F-006  Fatal dispatcher host interceptor identified (sub_821BD618)
- Task:        T1
- Type:        FACT
- Class:       D (host override of guest function)
- Priority:    P1 (context — the fatal itself works, but its invocation path
               matters)
- Evidence:    `dispatcher->SetFunction(0x821BD618, sub_821BD618)` at
               `src/patches.cpp:441`; host implementation at
               `src/kernel/imports.cpp:2818-2873` reads slot 0x8285FEA0,
               prints fatal message + register dump + stack chain, calls
               ExitProcess(0x80000003). Raw PPC at 0x821BD618:
               `lis r11,0x8286; lwz r10,-0x160(r11)` loads [0x8285FEA0],
               `cmplwi r10,0; beq; mtctr r10; bctrl; b .` (call if non-zero,
               then infinite loop).
- Notes:       The host override is a strong symbol replacing the generated
               weak function. Guest code that calls sub_821BD618 hits the host
               override. The slot 0x8285FEA0 contains 0x82130678 at runtime
               (written by game init code).

## F-007  Plan correction: 0x82130678 is NOT zeros — it's a function prologue
- Task:        T1
- Type:        FACT (corrects F-003)
- Class:       I
- Priority:    P1
- Evidence:    read_memory_bytes of 0x82130678 via raw binary:
               `0x82130678: 0x7D8802A6` (mfspr r12,LR),
               `0x8213067C: 0x9181FFF8` (stw r12,-8(r1)),
               `0x82130680: 0x9421FFA0` (stwu r1,-0x60(r1)),
               `0x82130684: 0x38600000` (li r3,0). This is a real function,
               not a pad hole.
- Notes:       The planning model's claim that 0x82130678 is "16 bytes of ZERO"
               was based on IDA read_memory_bytes which may have read from a
               different segment or cache. The raw image bytes show it's a
               function that returns 0 in r3. On Xbox, this function is called
               through the handler pointer at 0x8285FEA0.

## F-008  Plan correction: bl at 0x8218ca6c is NOT a call to sub_821C0E18
- Task:        T1
- Type:        FACT (corrects F-002 call-site)
- Class:       H
- Priority:    P2
- Evidence:    Raw PPC at 0x8218ca6c = `0x912A0000` = `stw r9, 0(r10)`
               (opcode 36), NOT a bl (opcode 18). sub_8218C9D8's bl targets
               are: 0x823D91F4, 0x82410F88 (×2), plus bctrl at 0x8218CAF4.
               None target sub_821BD618 or sub_821C0E18.
- Notes:       The fatal chain still works through sub_821BD618, but the exact
               guest code path from sub_8218C9D8 to the fatal dispatcher is
               different from what the plan describes. The bl/sub_821C0E18
               attribution in F-002 is partially wrong; the terminal behavior
               (host intercept of sub_821BD618) is correct.

## F-009  EMB76 hook decoded: hooks sub_821CB070 (embedded device method)
- Task:        T1
- Type:        FACT
- Class:       I
- Priority:    P1
- Evidence:    `PPC_FUNC(sub_821CB070)` at `src/gpu_device.cpp:3019-3034`
               intercepts the "embedded:" device method (vtable-based call).
               Logs r3 (device object with vtable), r4 (path string), lr.
               Counter capped at 12. NEVER FIRED in boot_stdout_78.log.
- Notes:       The hook fires when game code calls the embedded device's method
               (likely Open or similar vtable slot). Zero fires means the
               embedded device was never invoked during boot. This is
               consistent with E1 holder being empty — if no embedded device
               was registered, no embedded device method can be called.

## F-010  E1 fallback device holder confirmed empty across ALL 43 GETDEV calls
- Task:        T1
- Type:        FACT
- Class:       I
- Priority:    P0 (critical for F3 fork)
- Evidence:    GETDEV #1-#43 in build/boot_stdout_78.log: E1 always shows
               `hold=A0084028 dcnt=0000 dcap=0001 d0=CDCDCDCD vt0=00000000
               pfx0=00000000 d1=CDCDCDCD vt1=00000000 pfx1=00000000`.
               Identical at every single GETDEV call from 19:12:59.091 to
               19:13:04.763.
- Notes:       The embedded device holder (E1) was never written to. dcnt=0
               means zero devices registered. d0=CDCDCDCD is the heap fill
               pattern (never overwritten). This is strong evidence that the
               embedded device registration function never executed, OR its
               writes were lost. F3 fork in T5 decides this.

## F-011  Preload lists read but star_glow lookups all miss
- Task:        T1
- Type:        FACT
- Class:       I
- Priority:    P0 (the immediate fatal cause)
- Evidence:    GETDEV #28-#37 (19:13:04.671-04.762): 5 preload.list files
               opened (ui, city, cars, characters, effects). INFLATE #1-#7
               decompression events. Then GETDEV #38-#43 (19:13:04.763):
               `embedded:/dcl/star_glow.dcl` → miss, `embedded:/star_glow.dcl`
               → miss, `embedded:/fxl_final/star_glow.fxc` → miss,
               `a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl` → miss
               (mangled!), `a:/archive/dcl/star_glow.dcl` → miss,
               `a:/archive/fxl_final/star_glow.fxc` → miss. Fatal follows.
- Notes:       The preload lists were successfully read and inflated, but the
               shader names they contained were never registered into the
               runtime dictionary that sub_8218C650 queries. star_glow was
               never added to the lookup table. This points to either: (1) the
               preload parsing didn't register names, or (2) the registration
               target (the embedded device's dictionary) was empty because the
               device was never registered (F-010). T2 must resolve this.

## F-012  F1 fork resolves: AUDIT_FOCUS=DEVICE (star_glow was NOT preloaded)
- Task:        T2
- Type:        FACT
- Class:       D/E (device registration never happened)
- Priority:    P0
- Evidence:    (1) EMB76 census = 0 fires (F-009); embedded device method
               never called. (2) E1 fallback holder always empty (F-010).
               (3) Preload lists were opened (GETDEV #28-#37 at
               19:13:04.671-04.762: ui, city, cars, characters, effects) and
               inflated (INFLATE #1-#7), confirming the game's preload parser
               ran. (4) But star_glow names were never registered into the
               runtime dictionary because the target (embedded device's
               dictionary) was never created — the device was never registered.
               (5) sub_8218C650 queries a data structure that the embedded
               device should populate; with the device absent, all lookups
               return -1.
- Notes:       AUDIT_FOCUS shifts to DEVICE. T5 (embedded/memory device
               registration hunt) is now the deep critical task. The defect is
               NOT in the lookup/registry path (codegen suspect cleared for
               now); it's in the device registration path. T5 must find: (1)
               which function R registers the embedded device, (2) whether R's
               caller was executed, (3) what gate prevented registration.

## F-013  byte_827D5C70 = compile-time constant 0x01; never written at runtime
- Task:        T3
- Type:        FACT
- Class:       D (device/status flag, not a variable)
- Priority:    P1
- Evidence:    (1) Raw byte at 0x827D5C70 = 0x01 in the image (compile-time
               init). (2) Zero stb instructions reference 0x827D5C70 across
               the entire binary — no runtime writer exists. (3) Single reader
               at 0x82189254 (inside function starting at 0x82189138):
               `lis r11, 0x827D; lbz r10, 0x5C70(r11); cmpwi cr0, r10, 0;
               beq +0x14`. If byte != 0 → falls through to
               `bl 0x821BD618` (FATAL dispatcher, F-006). If byte == 0 →
               skips fatal. (4) Two callers of 0x82189138: bl at 0x82189408
               and bl at 0x8218947C — both inside the same parent function
               (0x82189138 is called from within a larger shader-loading
               routine).
- Notes:       The fatal-vs-fallback switch is NOT a runtime variable — it's
               a compile-time constant baked into the binary image. There is
               no code path that could set it to 0 to disable fatal. The
               game was compiled with FATAL_ENABLED=1, meaning shader load
               failure always triggers the fatal dispatcher. This rules out
               "forgot to set fallback flag" as a root cause. The fatal path
               at 0x8218926C calls the same `sub_821BD618` identified in
               F-006. Next step: verify whether the host-side fatal
               dispatcher (`sub_821BD618` in imports.cpp:2818) is the one
               actually reached by this call path, or if there's a different
               fatal handler in the guest binary.

## F-014  sub_8218C650 is NOT a standalone function; actual shader lookup is sub_82189138
- Task:        T4
- Type:        FACT
- Class:       A (generated code correctness check)
- Priority:    P0
- Evidence:    (1) `0x8218C650` is NOT a function entry point — it's mid-body
               of `sub_8218C638` (prologue at 0x8218C638: mfspr r12,LR;
               stw r12,-8(r1); stwu r1,-112(r1)). The plan expected
               sub_8218C650 to be the shader lookup; it's actually the tail
               of a larger initialization/cleanup function. (2) The actual
               shader name lookup function is `sub_82189138` (mapped in
               ppc_func_mapping.cpp line 2433). It:
               a. Takes shader name string in r3
               b. Returns -1 if not found (early exit if r3==0)
               c. Hashes the name via sub_821C9AB0 + sub_821C9790
               d. Searches a 256-entry dictionary at 0x827C9F70
               e. On miss: reads byte_827D5C70 (F-013), if non-zero calls
                  sub_821BD618 with "Unable to load shader '%s', it probably
                  wasn't preloaded properly."
               f. Two callers: bl at 0x82189408 and bl at 0x8218947C
- Notes:       The execution plan's assumption that sub_8218C650 is the
               lookup function is WRONG. This corrects the plan's targeting
               but does NOT change the F1 fork result (AUDIT_FOCUS=DEVICE
               from F-012 still holds).

## F-015  Generated sub_82189138 matches binary (shader lookup integrity PASS)
- Task:        T4
- Type:        FACT
- Class:       A (code quality — PASS)
- Priority:    P1
- Evidence:    Diff checklist for sub_82189138 generated vs binary:
               (1) Branch targets: PASS — all loc_ labels (8218915C, 8218917C,
                   82189194, 821891FC, 82189210, 82189250, 82189270, 821892A8,
                   821892E4, 821892F0, 82189300, 82189304) match binary
                   branch destinations.
               (2) .long stubs / ERROR stubs: PASS — no .long inline data or
                   ERROR stubs in the function body.
               (3) switch/bctr: PASS — no switch tables; single bctrl at
                   0x821891C4 correctly uses PPC_CALL_INDIRECT_FUNC(ctr.u32).
               (4) Call args: PASS — sub_821C9AB0(r3=name),
                   sub_821C9790(r4=0), sub_821BD618(r3=format, r4=name),
                   sub_82188E50(r3=name, r4=0).
               (5) Loop bounds: PASS — iterates 256 entries (r9: 0→1024, step 4).
               (6) String constants: PASS — -19624 from 0x82010000 = 0x8200B358
                   ("Unable to load shader '%s', it probably wasn't preloaded
                   properly."); -19700 from 0x82010000 = 0x8200B30C ("No
                   fallback shader available, shader preload probably failed.").
               (7) Sign/zero extension: MINOR DIFF — generated uses
                   `cmplwi cr6` (unsigned) for byte_827D5C70 check; binary uses
                   `cmpwi cr0` (signed). Functionally equivalent for ==0
                   comparison; CR field difference is benign register
                   allocation choice.
- Notes:       The shader lookup function's generated code is correct. The
               defect is NOT in the lookup logic itself — the function
               faithfully reproduces the binary's behavior. The -1 return
               path is correctly implemented. This clears the codegen
               suspect for the lookup path.

## F-016  sub_8218C9D8 generated code — device dispatch, NOT shader lookup
- Task:        T4
- Type:        FACT
- Class:       A (code quality — info)
- Priority:    P2
- Evidence:    (1) sub_8218C9D8 (ppc_recomp.9.cpp:18707) is a device
               notification/dispatch function, NOT the shader lookup. It:
               a. Takes r3=index, r4=key, r5=count, r6=array
               b. Copies 13 words from constant table to stack
               c. Iterates 12 entries (r31: 0→48, step 4) applying device
                  callbacks via vtable at offset 468
               d. Calls sub_82410F88 (early path when r4==0)
               e. No switch tables, no .long stubs
               (2) The `bl` at 0x8218CA6C referenced in the plan does NOT
                   exist as a call — per F-008, the code at that address is
                   `stw r9,0(r10)` (store word), not a bl instruction.
                   This was already corrected in F-008.
               (3) sub_82189134 is mapped as `.long 0x0` (empty stub),
                   matching the binary's `0x00000000` at that address.
- Notes:       The plan's expectation of "embedded:/ string build + double
               lookup + fatal" in sub_8218C9D8 is incorrect. The actual
               "double lookup + fatal" pattern is in sub_82189138 (F-014).
               sub_8218C9D8 handles device state-change notifications,
               which is a separate code path.

## F-017  Device memory layout decoded — E0 holder populated, E1 empty
- Task:        T5
- Type:        FACT
- Class:       A (structural understanding)
- Priority:    P1
- Evidence:    (1) Device holder structure (from census hook gpu_device.cpp
               :2962-2988):
               - Arr = array of 2 device entries at base address
               - Each entry is 276 bytes: name[16] at +0, flag at +262,
                 len at +264, hold at +268, dcnt at +272, dcap at +274
               - hold = pointer to device descriptor array
               - d0 = first device pointer (read from hold[0])
               - vt0 = vtable at d0[0], d0pfx = prefix at d0+36
               (2) Census shows:
               E0: name='rage_cache' flag=? len=? hold=? dcnt=32 dcap=32
                   d0=00000000 vt0=00000000 pfx0=00000000
               E1: name='' flag=? len=? hold=A0084028 dcnt=0 dcap=1
                   d0=CDCDCDCD (uninitialized debug fill)
               (3) E0 has 32 devices registered; E1 has 0.
               (4) E1 hold=A0084028 (guest heap address), d0=CDCDCDCD
                   confirms no device was ever registered into E1.
               (5) 0x827D8380 is a C++ type_info / VFT descriptor for
                   ".?AVfiDeviceMemory@rage@@" (rage::fiDeviceMemory class).
                   Contains: self+8 ptr, count=16, vtable at 0x8201219C,
                   secondary ptr 0x82012914, data ptr 0x8205CEC0, then
                   RTTI name string. NOT the holder backing store.
- Notes:       The plan's claim that 0x827D8380 is "backing store of guest
               global" for the E1 holder is INCORRECT. It's a type_info/VFT
               object. The actual holder is on the guest heap at A0084028.

## F-018  Device vtable addresses decoded
- Task:        T5
- Type:        FACT
- Class:       A (structural understanding)
- Priority:    P2
- Evidence:    Three vtable candidates in 0x82012Bxx range:
               (1) 0x82012B44 — embedded device vtable:
                   [+0x00] 0x821CD700 (destructor-like, calls sub_821CCA38)
                   [+0x04] 0x82762480 (stub/no-op, 21 entries)
                   [+0x0C] 0x8249B538 (shared with E0)
                   [+0x1C] 0x821CCD58 (I/O loop, calls sub_821CCB38)
               (2) 0x82012BDC — E0 device vtable (rage_cache):
                   [+0x00] 0x822C3588 (function)
                   [+0x04] 0x821CDB88 (function)
                   [+0x08] 0x821CC570 (function)
                   [+0x0C] 0x8249B538 (shared with embedded)
                   [+0x18] 0x821CD348 (function)
                   [+0x1C] 0x821CC6F0 (function)
               (3) 0x82012CA8 — NOT a vtable; contains ASCII "Out of file
                   descriptors" string data.
               (4) Two functions load these vtables:
                   0x821CCA50 (inside sub_821CCA38) loads 0x82012B44
                   0x821CCE58 loads 0x82012BDC
               (5) sub_821CCE58 (E0 vtable initializer, IN mapping):
                   - Stores vtable 0x82012BDC into [r31+0]
                   - Calls sub_821CBEB0 (base init)
                   - Then replaces vtable with 0x8201206C
               (6) sub_821CCA38 (embedded vtable constructor, IN mapping):
                   - Stores vtable 0x82012B44 into [r31+0]
                   - Multiple cleanup paths for offsets 308-372
- Notes:       Both vtable initializers are in the function mapping (recompiled).
               The E0 path runs (E0 is populated). The embedded path may not
               run or may not reach the holder-registration step.

## F-019  Device registration census — MOUNT76 and EMB76 never fired
- Task:        T5
- Type:        FACT
- Class:       A (runtime evidence)
- Priority:    P0
- Evidence:    From boot log census hooks:
               (1) MOUNT76 (sub_821CB9D8): 0 calls logged (n stays at 0).
                   This is the device Mount function that registers devices.
                   NO device was ever mounted during the boot sequence.
               (2) EMB76 (sub_821CB070): 0 calls logged (n stays at 0).
                   This is the embedded device method. NEVER called.
               (3) TOC76 (sub_821CBFC0): packfile TOC lookup, fires for
                   read-only-resources. Never fires for embedded device.
               (4) The device registration path (MOUNT76) is the function
                   that adds entries to the holder. Since MOUNT76 never
                   fired, NO device was registered during boot, including
                   the embedded device.
               (5) E0's 32 entries must have been registered BEFORE the
                   census hook was installed, or through a different path
                   not captured by the census.
- Notes:       This is a critical finding: if MOUNT76 never fired, then
               the embedded device was never registered. The question
               becomes: what prevented the Mount call? The gate is
               upstream of the Mount function.

## F-020  Device registry has only ONE type — embedded device type never registered
- Task:        T5
- Type:        FACT
- Class:       D (first-divergence candidate)
- Priority:    P0
- Evidence:    Census hook reads device registry from guest global 0x82860844:
               Registry header: {Device** array@+0, u16 count@+4, u16 cap@+6}.
               Each entry is 276 bytes: name[16]@+0, flag@+262, len@+264,
               device vector {Device** arr@+268, u16 cnt@+272, u16 cap@+274}.
               (1) Registry cnt=1 throughout ALL 43 GETDEV calls — only ONE
                   device type was ever registered: "a:/archive/" (flag=1,
                   len=11).
               (2) E0 (registry entry 0): name='a:/archive/' — the archive
                   device. Its device vector (hold) grew from 1 to 2 entries
                   between GETDEV #4 (dcnt=1) and GETDEV #5 (dcnt=2). Both
                   device objects use vtable 0x82012BDC (E0 vtable).
               (3) E1 (registry entry 1): name='' flag=0xcdcd — this is
                   UNINITIALIZED MEMORY read beyond the valid registry. Since
                   cnt=1, entry 1 is out-of-bounds. E1 was never a valid
                   device type. The census loop condition `e <= cnt` causes
                   it to read one entry past the end.
               (4) The "embedded:/" paths ARE resolved — GETDEV #5 shows
                   path='embedded:/fxl_final/rage_im.fxc' was handled by the
                   archive device. The archive device handles all path
                   prefixes including "embedded:/".
               (5) The fatal error occurs because the shader lookup inside
                   the archive device's file-open path (sub_82189138) finds
                   the shader name in its dictionary but returns -1 (not
                   found), triggering the fatal path via byte_827D5C70.
               (6) E1 holder address A0084028 with d0=CDCDCDCD is the
                   SECOND registry entry's device vector — out-of-bounds
                   read of uninitialized heap memory. NOT a separate
                   "embedded device holder".
- Notes:       This OVERTURNS the embedded device hypothesis. The plan
               assumed E1 was the "embedded device holder" (a separate
               device type). In reality, E1 is an out-of-bounds read of
               uninitialized memory beyond the single registry entry. The
               archive device handles ALL paths including "embedded:/".
               The real question is: why does the shader lookup fail for
               "star_glow" when it was supposedly preloaded? The lookup
               function (sub_82189138) searches a 256-entry dictionary at
               0x827C9F70. The dictionary was populated from preload lists.
               If "star_glow" was in a preload list but not in the
               dictionary, the registration failed silently.

## F-021  Executed-path reachability join — all 153 LRs map to known functions
- Task:        T6
- Type:        FACT
- Class:       A (code quality — info)
- Priority:    P1
- Evidence:    (1) 153 distinct LR values extracted from census log, ALL
                   map to known functions in ppc_func_mapping.cpp. 0 unmapped.
               (2) Key function execution status:
                   - sub_82189138 (shader lookup): NOT in LR set directly,
                     but fatal chain[0] lr=0x82189270 is INSIDE this function
                     (offset +0x138). Confirms the function WAS called.
                   - sub_821BD618 (fatal handler): 3 LR values in range
                     0x821BD618-0x821BD718. Fatal handler WAS invoked.
                   - sub_821CCE58 (E0 vtable init): 8 LRs in range.
                   - sub_821CCA38 (embedded vtable ctor): 9 LRs in range.
                   - sub_821CC970 (device registry loop): 10 LRs in range.
                   - sub_821CB9D8 (MOUNT76): 10 LRs in range. But MOUNT76
                     census hook logged 0 calls — the LRs are from the
                     hook's own code path, not from device mount calls.
                   - sub_821CB070 (EMB76): 8 LRs in range. Census logged 0.
                   - sub_821CB488 (GETDEV): 8 LRs in range. Census logged 43.
               (3) Fatal chain from log:
                   chain[0]: lr=0x82189270 sp=0x8EFFF220
                   chain[1]: lr=0x00000010 sp=0x8EFFF3A0 (invalid)
                   chain[2+]: lr=0x00000000 (end of chain)
                   The call stack is truncated — only one valid return address.
                   chain[1] lr=0x00000010 is garbage (likely stack frame
                   alignment padding or corrupted saved LR).
               (4) Fatal dispatch regs: lr=0x82189270 r3=0x8200B358
                   (format string) r4=0x82040F0C ("star_glow") r5=0x16
                   (length 22). r3 points to "Unable to load shader '%s',
                   it probably wasn't preloaded properly." at 0x8200B358.
- Notes:       The truncated call chain (only 1 valid frame) suggests the
               fatal handler was called from a deep stack with corrupted
               saved LR values. This is consistent with the fatal handler
               being called from within the shader lookup function's error
               path, where the stack frame may not be fully set up yet.

## F-022  Generated-code completeness census — 33% stubs, 0 executed stubs
- Task:        T7
- Type:        FACT
- Class:       A (code quality — PASS)
- Priority:    P1
- Evidence:    (1) Function mapping: 44,707 entries (1:1 with declarations).
               (2) Total PPC_FUNC_IMPL: 44,707 (matches mapping).
               (3) .long 0x0 stubs: 14,880 (33.3% of all functions).
                   These are functions that exist in the binary but were
                   not recompiled with full bodies — they return
                   immediately with no code.
               (4) ERROR stubs: 0 (no explicit error/unimplemented traps).
               (5) Executed functions with .long 0x0: 0.
                   ALL 153 functions that were called during boot have
                   real code bodies. No executed function is a stub.
               (6) The 14,880 stubs are for functions that were never
                   called during the boot sequence. They may be needed
                   for later game stages (gameplay, menus, etc.) but
                   are not relevant to the boot-time fatal error.
- Notes:       The generated code is COMPLETE for the executed path. The
               33% stub rate is expected for a large binary where many
               functions are not needed during early boot. The key
               executed-path functions (shader lookup, fatal handler,
               device management) all have full code bodies.

## F-023  Heavy-model verification pass: F-001 OVERTURNED, F-007/F-008/F-014 CONFIRMED
- Task:        review checkpoint (planning model, raw-byte verification)
- Type:        FACT
- Class:       H (corrects F-001)
- Priority:    P1
- Evidence:    File bytes (offset = guest - 0x82000000):
               0x82189268=386BB358 (addi r3,r11,0xB358 -> r3=0x8200B358 fmt),
               0x8218926C=480343AD (bl 0x821BD618), ret 0x82189270 = logged lr;
               0x82189408/0x8218947C = bl into 0x82189138;
               0x8218ca6c=912A0000 (stw, not bl); 0x82130678=7D8802A6 9181FFF8
               9421FFA0 38600000 (real prologue, not zeros);
               patches.cpp:441 SetFunction(0x821BD618,...).
- Notes:       F-001 ("lr is stale garbage") is WRONG - the planning model's
               IDA disassembly was misaligned; the executor's raw-file reads
               are ground truth. lr=0x82189270 is the true return address of
               the fatal call inside the shader lookup. F-003 is superseded by
               F-007. Rule for all future work: verify IDA claims against raw
               file bytes before trusting them.

## F-024  GETDEV full dispatch traced — 8-prefix fallback to handler table scan
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    ppc_recomp.17.cpp lines 1015-1417. GETDEV (sub_821CB488) checks
               7-char "memory:" and 10-char "embedded:/" prefixes first — both
               return dead pointer 0x827D838C. Then checks "tcpip" (6 chars)
               → sub_821D5F58. Several more hardcoded prefix checks follow.
               Fall-through scans handler table at 0x82860844 (276-byte entries).
               If no match, returns device from global 0x827D8380 (set by
               MOUNT76 for "memory:" mounts).
- Notes:       Handler table has only 1 entry (cnt=1, cap=16) — "a:/archive/".
               Two registered devices: d0=A007D398 (vt=82012BDC), d1=A007D810
               (vt=82012BDC). Both have pfx=0x0000000B (11 = "a:/archive/").
               E1 slot is uninitialized (flag=0xCDCD, d0=CDCDCDCD).

## F-025  Handler table structure identified — 276-byte entries with nested vectors
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    MOUNT76 census (ppc_recomp.17.cpp:1885-2077) reads/writes
               handler table at 0x82860844. Structure:
               +0: Device** array pointer
               +4: u16 count
               +6: u16 capacity
               Entry (276 bytes):
               +0: char name[262]
               +262: u16 flag
               +264: u16 nameLen
               +268: Device** device_array_ptr
               +272: u16 device_count
               +274: u16 device_capacity
- Notes:       Census GETDEV-E0 shows: name='a:/archive/' flag=1 len=11
               hold=A0018028 dcnt=0002 dcap=0002. Two devices per entry
               (d0 and d1), each with its own vtable.

## F-026  Census hook traced for all key functions
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P1
- Evidence:    GETDEV census in gpu_device.cpp reads:
               - 0x82860844 (handler table) → arr, cnt, cap
               - 0x82855A0C (lockFlag) →FFFFFFFF
               - Per-entry: name, flag, len, hold, dcnt, dcap
               - Per-device: vt, pfx (via d0+36/d1+36)
               MOUNT76 census at line 3100 logs: path, dev, vt, flag, lr.
               Both census hooks are pass-through (call original, then log).
- Notes:       GETDEV returns dead pointer 0x827D838C for memory:/embedded:/.
               MOUNT76 shows lr=821CBF54 for both archive mounts.

## F-027  GETDEV redirect fix REJECTED — three fatal flaws identified
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    Applied redirect in gpu_device.cpp: when GETDEV returns dead
               pointer for memory:/embedded: path, replace with s_archiveDevice.
               Reviewer identified three fatal flaws:
               (1) EMB76>0 unreachable — redirect calls archive device methods,
                   not embedded device methods
               (2) Can't load shader content — star_glow files exist in inflated
                   RAM buffers, NOT in a:/archive/ (wrong paths)
               (3) Doesn't target policecam stall — hang is TOC76 on archive
                   path, no memory: prefix involved
- Notes:       Fix was reverted. The dead pointer is a SYMPTOM, not the cause.
               The cause is that inflated dictionaries are never mounted as
               memory devices.

## F-028  Post-inflate code flow traced — callback at [r26+1548] is key
- Task:        Stage B'' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    ppc_recomp.14.cpp lines 19321-19390. After inflate loop exits
               (loc_821BC4CC): vtable+124 call on stream device, then
               sub_821CE100 twice (cleanup). If [r26+1540] (stream count) != 0,
               calls callback at [r26+1548] with args:
               r3 = [r26+1552] (archive device)
               r4 = [r26+8]    (data/buffer)
               r5 = [r26+1544] (inflated size)
               r6 = 0
               Then calls sub_821C31B8.
- Notes:       This callback is likely where the memory device mount SHOULD
               happen. We need to:
               (1) Census this callback to see if it fires
               (2) Trace the callback function pointer value
               (3) If it fires, trace what it does with the buffer
               (4) If it doesn't fire, trace why r26+1540 might be 0

## F-029  All boots show MOUNT76=2 — memory mount never works in ANY configuration
- Task:        Stage B'' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    Grep of MOUNT76 across all boot logs:
               boot_stdout_78.log (baseline): MOUNT76 #1 A007D398, #2 A007D810
               boot_stdout_79.log: same
               boot_stdout_80.log: same
               boot_stdout_p0d1.log (post-fix): same
               All four boots: exactly 2 MOUNT76 calls, both a:/archive/.
               Zero memory mounts in ANY configuration.
- Notes:       This is the fundamental issue. The inflation works (INFLATE #1-7
               or #1-15 fire), but the mount that makes the inflated data
               available as a device never happens. The hash table hydration
               fix didn't change this because it's a different code path.

## F-030  PHASE1 §0 "IO slot never completes" is OVERTURNED (p1b)
- Task:        PHASE1 T1
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    p0d1 WAKE[KWFSO] status=00000000 fires constantly on the same
               obj@40004D7C wait (tid=000063E8). The WAIT line's put/rptrWB
               are GPU CP metrics (gpuCtx+10908 and 0xC701C4BC), not fields
               of the waited object. Guest sub_8242FB88 is a driver poller
               (30ms timeout, KeResetEvent on success) — designed behavior.
- Notes:       Do not treat the 471 wait loop as the stall. See F-031.

## F-031  p0d1 TOC76 #22 hang is FLAKY; real terminal frontier is star_glow fatal
- Task:        PHASE1 T2/T3
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    boot_stdout_p1b.log: TOC76-RET #22 ret=A008F950 dt=0ms, boot
               continues to TOC76 #80 then Fatal 'Unable to load shader
               star_glow' (same as baseline 78). p0d1 ended at TOC76 #22
               entry with no RET — hang stopped the boot *before* star_glow.
- Notes:       Hydration (DICT-HYDRATE 10/10) does NOT prevent star_glow
               fatal. It only hydrates factory names (draw/Copy/…). The
               p0d1 "hydration works" claim was an artifact of the hang.

## F-032  Post-inflate callback is a semaphore release, not a memory mount
- Task:        PHASE1 T2
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    cbPtr=821BC548 is `b sub_821C9108` (tail call). sub_821C9108
               only uses r3 → sub_8244ED10(h,1,0). Ignores r4=bufPtr and
               r5=inflSize. Runtime RELSEMA sub_821C9108 #40 h=C98B9800
               lr=821BC538 matches arcDev.
- Notes:       Overturns handoff/F-028 "callback is where mount should
               happen". Mount must be elsewhere.

## F-033  Only 3 Mount call sites; the non-archive ones never run
- Task:        PHASE1 T2 (raw-byte verified)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    bl sub_821CB9D8 only at: sub_821CBF28 (fires 2× archive),
               sub_821399E0@82139B58 (zero xrefs in ppc_xenon), and
               sub_82139BE0@82139EF4 (only from sub_82135E48, gated by
               [r30+4]==0 and sub_8213AB78 success). Neither address appears
               in any boot log. Raw prologue 7d8802a6 at all three starts.
- Notes:       Next: census sub_82135E48/sub_8213AB78 to see how close the
               executed path gets. If guest never mounts on our surface,
               host must implement a faithful memory: device (do NOT GETDEV-
               redirect — F-027).
