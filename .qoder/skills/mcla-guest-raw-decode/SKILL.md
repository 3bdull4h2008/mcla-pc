---
name: mcla-guest-raw-decode
description: Decode PowerPC/Xenon instructions straight out of build/cache/mcla_pe.bin with the project's identity-mapping arithmetic, and verify every IDA claim against those raw bytes (rule 3 / finding F-023). Use when attributing a crash lr, naming a vtable slot, or deciding what a guest function does.
---

# Guest raw-byte decode (the rule-3 tool)

IDA function starts and IDA-sourced addresses have been wrong repeatedly in this project
(F-023: raw file bytes are ground truth; F-024: `0x827C9F70` was a decode error for
`0x82839F70`). **Any address you cite must be produced or checked here.**

## The mapping

`build/cache/mcla_pe.bin` is the identity-mapped image:

- **file offset = guest VA − 0x82000000**
- instruction words are **big-endian**
- the PE section table lies — do not use it to compute offsets

## Dump words

```bash
cd "E:/mcla pc" && python - <<'EOF'
import struct
f = open('build/cache/mcla_pe.bin','rb'); BASE = 0x82000000
def w(va):
    f.seek(va-BASE); return struct.unpack('>I', f.read(4))[0]
for va in range(0x822FBC10, 0x822FBC2C, 4):
    print(hex(va), format(w(va), '08X'))
EOF
```

## The `lis` sign-extension trap (this cost a wrong conclusion on 2026-09-20)

`lis rT, imm16` places `imm16 << 16`. A **negative** printed immediate is a signed 16-bit value:

```
lis r11, -32124    ->  imm16 = 0x82A4?  NO:  -32124 & 0xFFFF = 0x82A4  ->  r11 = 0x82A40000
                      the recompiler stores it sign-extended to 64-bit: 0xFFFFFFFF82A40000,
                      and the u32 guest address is 0x82A40000.
lwz r3, -24728(r11) ->  0x82A40000 - 0x6098 = 0x82A39F68
```

Check the arithmetic with the generated TU instead of by hand — XenonRecomp prints the sign-extended
value, e.g. `r11.s64 = -2105278464` → `0xFFFFFFFF82840000` → **u32 0x82840000**, so
`lwz r3,-24728(r11)` = `0x82840000 − 0x6098` = **`0x82839F68`**. A hand decode of this exact site
produced the wrong global (`0x82859F68`) and a wrong callee name. Compute it, don't eyeball it:

```bash
python -c "print(hex(-2105278464 & 0xFFFFFFFF), hex((-2105278464 & 0xFFFFFFFF) - 24728))"
```

**The mirror-image trap (F-055 → F-056, 20:35→21:30 the same day): never read a D-field's raw hex as
part of the address.** `822FA96C 816BE334 lwz r11,-7372(r11)` with `822FA958 3D608288 lis r11,8288` is
`0x82880000 − 0x1CCC` = **`0x8287E334`**, *not* `0x8288E334` — the low two bytes of the word are the
signed displacement, and pasting them onto the `lis` result silently adds instead of subtracting. Same
rule as above: `python -c "print(hex(0x82880000 - 7372))"`, and prefer the generated TU's own comment
(`// lwz r11,-7372(r11)`) over the disassembler's hex.

## The second thing `rip owner=` cannot do (F-056)

A fault whose `lr` points at a `bl` is **not** necessarily inside that callee. If the generated body
holds a raw `simde_mm_store_si128(... base + ((rX.u32 + ctx.rY.u32) & ~0xF) ...)` — an unchecked VMX
store, unlike `PPC_STORE_U32` — the fault can be the *caller's* store, with `lr` left sticky by the
translator at the last `ctx.lr = …` before a call. Prove it from the caller's own locals: find the line
whose computed register matches the dump (F-056 used `// addi r10,r31,16` → dump `r10=00000010` →
translator-local `r31 = 0`), and check which `PPC_FUNC_IMPL` encloses that line number — `awk` over the
file, not the nearest preceding `sub_` mention.

## Cross-check against generated code

`generated/ppc_xenon/*.cpp` is the recompiler's own decode, with the original PPC text as comments:

```bash
cd "E:/mcla pc" && grep -rn "822FBC18\|loc_822FBC28" generated/ppc_xenon/*.cpp | head
```

`generated/**` is **input only** — never edit it (rule 2).

## Call-shape reading (attribution rules)

- `4E800421` = `bclrl`, `4E800420` = `bclr`, `4E800421` after `7D0903A6` (`mtctr r8`) = **a call
  through a function pointer**; the logged `lr` is the *return address*, i.e. the instruction after
  the `bclrl`. The fault is in the callee or in resolving the target — not at `lr`.
- Do not build caller chains from a census `lr` after a `memset`/leaf call — LR is sticky
  (do-not #14). Use xrefs plus argument registers, or the FFBT trace.
- A `0xC0000005` whose `Param[1]` is **`0x7E780000`** = a read of **guest address 0** = a null guest
  pointer dereference (or an unresolved indirect-call target). `Param[0]=0` = read, `1` = write.
- `0xCDCDCDCD` = guest-native fill-on-alloc (never-initialized, **not** corruption).
  `525DE064` = stack residue, not magic (do-not #6). `0xFF00FF00`/`0xFFFF00FF` = missing-texture
  checkerboard.

## Vtable census

To name the slots of a suspected vtable at `V`, dump `V-8 .. V+0x18` and match each value against
`generated/ppc_xenon` symbol names:

```bash
cd "E:/mcla pc" && grep -rn "PPC_FUNC_IMPL(sub_821873E8)\|__imp__sub_821873E8" generated/ppc_xenon/*.cpp src/*.cpp src/*/*.cpp | head
```

Then apply **rule 4 (one owner per guest address)**: if `src/` already has a `PPC_FUNC`,
`GUEST_FUNCTION_HOOK` or `SetFunction` for that address, extend that hook — never add a second.
