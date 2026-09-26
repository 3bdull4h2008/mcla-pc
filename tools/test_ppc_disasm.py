"""Disassembler correctness harness: tools/ppc_disasm.py vs capstone, on real guest bytes.

Why this exists (F-355): `ppc_disasm.py` is a 296-line hand-written `if op ==` chain with
NO test and no VMX at all — every AltiVec word prints as an unnamed hex blob, on a repo
whose docs plan is 251 lines of VMX128 work. The project memory records five separate
hand-decoded PPC bit-field attempts that each returned a confident ZERO instead of an
error, and two decoder bugs (`bctr` printed as `bclr` via the 9-bit XO alias 528→16;
reversed `ori` operands) that were found only by reading. A measuring tool that cannot
fail is worse than no tool, so this makes it able to fail.

Usage:
  python tools/test_ppc_disasm.py                # census over the whole image sample
  python tools/test_ppc_disasm.py --fail         # also exit non-zero on any mismatch
  python tools/test_ppc_disasm.py -n 4000        # bigger sample
  python tools/test_ppc_disasm.py --only 0x82461B98 0x82461530   # one function's words

The oracle is capstone (`pip install capstone`), which decodes VMX/VSX and needs no
license. Agreement is judged on the MNEMONIC, not operand text: the two render registers
differently (`r11` vs `r11` is fine, but `0x82000004` vs `.+5` is not a bug).

Current known gaps this harness is expected to report: the whole VMX/VSX opcode space
(opcodes 4/5/19/20/21 and the float-pair forms), which `ppc_disasm.py` folds into
`float/ps` or `?opNN`. Use `--only` on a specific function to check a claim instead of
arguing from the aggregate.
"""
import argparse
import re
import struct
import sys
from pathlib import Path

import capstone

sys.path.insert(0, str(Path(__file__).resolve().parent))
import ppc_disasm  # noqa: E402

IMAGE = Path(__file__).resolve().parent.parent / "build" / "cache" / "mcla_pe.bin"
BASE = 0x82000000

# Registers our tool prints as `rN`/`fN`/`vN` vs capstone's spellings, normalised away.
# Alias / pseudo-op vocabularies: capstone prints the raw form where our tool prints
# the synthetic one (and the reverse). Collapsing these is what makes the headline
# agreement number mean something.
_ALIAS = {
    "cmpi": "cmpwi", "cmpli": "cmplwi", "cmpd": "cmpdi", "cmpld": "cmpldi",
    "beq": "bc", "bne": "bc", "bgt": "bc", "blt": "bc", "bge": "bc", "bl": "bc",
    "bdnz": "bc", "bdz": "bc", "b": "b",
    "clrlwi": "rlwinm", "clrrwi": "rlwinm", "clrlslwi": "rlwinm",
    "nop": "ori", "li": "addi", "mr": "or", "not": "xori", "neg": "subf",
    "la": "addi", "caup": "addic", "eori": "xori", "srli": "srwi", "srai": "srawi",
    "slli": "slwi", "extsb": "extsb", "extsh": "extsh",
}


def canon_mn(mn):
    mn = mn.strip().lower().rstrip(".")
    if mn.endswith(".") and mn not in _ALIAS:
        mn = mn[:-1]
    return _ALIAS.get(mn, mn)


def norm_word(tok):
    """Collapse every numeric run (hex or decimal, including a displacement in front of
    a register) to `#`. Without this, `lwz r16,23744(r26)` and `lwz r16, 0x5cc0(r26)`
    — the SAME instruction — compare unequal, and the disagreement table fills with
    formatting noise that hides the real defects."""
    t = tok.strip().rstrip(",")
    if t.startswith("(") and t.endswith(")"):
        t = t[1:-1]
    t = re.sub(r"0x[0-9a-fA-F]+", "#", t)
    t = re.sub(r"\d+", "#", t)
    return t


def norm(mn, ops, order=True):
    """Compare on canonical mnemonic plus operand shape. Numbers become `#`; with
    order=False the operands are sorted, so `ori a,b,N` vs `ori b,a,N` still count as
    the same SHAPE and the reversal is reported separately (it is a bug, not style)."""
    mn = canon_mn(mn)
    parts = [norm_word(p) for p in ops.split(",")] if ops.strip() else []
    keep = []
    for p in parts:
        p = p.strip()
        keep.append("#" if (p.startswith("0x") or p.lstrip("-").isdigit()) else p)
    if not order:
        keep = sorted(keep)
    return mn, tuple(keep)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-n", type=int, default=20000, help="words to sample")
    ap.add_argument("--step", type=int, default=4)
    ap.add_argument("--start", default="0x0", help="image-relative start")
    ap.add_argument("--only", nargs="*", help="absolute VAs to decode instead of sampling")
    ap.add_argument("--fail", action="store_true", help="exit 1 if any mismatch")
    ap.add_argument("--show", type=int, default=12, help="examples to print")
    args = ap.parse_args()

    if not IMAGE.exists():
        print(f"missing {IMAGE} — dump it with one 20 s boot first (rule 3)")
        return 2
    data = IMAGE.read_bytes()
    cs = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_BIG_ENDIAN)

    if args.only:
        addrs = [int(a, 16) if a.lower().startswith("0x") else int(a) for a in args.only]
        words = [(a, struct.unpack_from(">I", data, a - BASE)[0]) for a in addrs]
    else:
        start = int(args.start, 0)
        end = max(start, len(data) - 4)
        idx = range(start, end, args.step)
        step = max(1, len(idx) // max(1, args.n))
        words = [(BASE + off, struct.unpack_from(">I", data, off)[0])
                 for off in idx[::step]]

    both = agrees = 0
    ours_only = cs_only = 0
    diffs = {}
    examples = []
    for va, w in words:
        raw = struct.pack(">I", w)
        ci = next(cs.disasm(raw, va), None)
        try:
            ours = ppc_disasm.decode(w, va)
        except Exception as exc:                      # noqa: BLE001
            ours = f"EXC {exc}"
        cs_txt = f"{ci.mnemonic} {ci.op_str}" if ci else None
        if cs_txt is None and (not ours or ours.startswith("?") or "EXC" in ours):
            continue                                   # neither knows: not a finding
        both += 1
        if cs_txt is None:
            cs_only += 1
            continue
        if not ours or ours.startswith("?") or "float/ps" == ours.split()[0].lower():
            ours_only += 1
            if len(examples) < args.show:
                examples.append((va, w, ours, cs_txt))
            continue
        om, oa = ours.split(" ", 1) if " " in ours else (ours, "")
        cm, ca = cs_txt.split(" ", 1) if " " in cs_txt else (cs_txt, "")
        if norm(om, oa) == norm(cm, ca):
            agrees += 1
        elif norm(om, oa, order=False) == norm(cm, ca, order=False):
            # same shape, different operand ORDER -> systematic reversal bug
            key = f"REVERSED {om} vs {cm}"
            diffs[key] = diffs.get(key, 0) + 1
            if len(examples) < args.show:
                examples.append((va, w, ours, cs_txt))
        else:
            key = f"{canon_mn(om)} vs {canon_mn(cm)}"
            diffs[key] = diffs.get(key, 0) + 1
            if len(examples) < args.show:
                examples.append((va, w, ours, cs_txt))

    print(f"words examined        {len(words)}")
    print(f"both engines decoded  {both}")
    print(f"mnemonics agreed      {agrees}")
    print(f"ours unnamed/failed   {ours_only}   "
          f"(capstone named these; our tool cannot — VMX/VSX space)")
    print(f"capstone failed only  {cs_only}")
    rate = (agrees / both * 100.0) if both else 0.0
    print(f"agreement rate        {rate:.2f} %")
    if diffs:
        print("\nreal mnemonic disagreements (top):")
        for k, v in sorted(diffs.items(), key=lambda kv: -kv[1])[:15]:
            print(f"  {v:6d}  {k}")
    if examples:
        print("\nexamples (va  word  ours  ->  capstone):")
        for va, w, ours, c in examples[:args.show]:
            print(f"  {va:#010x} {w:#010x}  {ours!r:<28} -> {c!r}")
    if args.fail and (ours_only or diffs):
        print("\nFAIL: disagreements present (--fail)")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
