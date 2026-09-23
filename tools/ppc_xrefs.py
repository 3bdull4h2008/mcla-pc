#!/usr/bin/env python3
"""Static xrefs into the decompressed guest image (rules 3/14/15).

 PPC code materialises a 32-bit address as `lis rA,HI` followed (not necessarily
 immediately) by `addi rT,rA,LO` / `addis rT,rA,LO`, and the second `lis` in a
 pair is a real hazard (do-not #16), so register state is tracked per-register
 across a window instead of pairwise. This tool keeps that state and answers
 "which code points at this address", which is the only xref available here:
 there is no IDA session, and `config`/`generated` give functions, not callers.

  python tools/ppc_xrefs.py find-str <text>            # literal's VA (+ context)
  python tools/ppc_xrefs.py xref <hexVA>               # code that materialises it
  python tools/ppc_xrefs.py fn <hexVA> [<hexVA> ...]   # enclosing sub_XXXXXXXX
  python tools/ppc_xrefs.py calls <hexVA>              # `bl` edges that target it
"""
import array
import bisect
import re
import sys

IMAGE = "build/cache/mcla_pe.bin"
BASE = 0x82000000
FUNC_RE = re.compile(rb"sub_([0-9A-Fa-f]{8})")


def load():
    try:
        img = open(IMAGE, "rb").read()
    except OSError:
        sys.exit(f"missing {IMAGE}: decompress the guest image first (PROGRAM_GUIDE s4)")
    words = array.array("I")
    words.frombytes(img[: len(img) // 4 * 4])
    if sys.byteorder == "little":
        words.byteswap()
    return img, words


def func_starts(words):
    """Guest function addresses named anywhere in generated/ (the call graph's nodes)."""
    import glob
    names = set()
    for path in glob.glob("generated/ppc_xenon/*.cpp"):
        with open(path, "rb") as f:
            buf = f.read()
        for m in FUNC_RE.finditer(buf):
            try:
                names.add(int(m.group(1), 16))
            except ValueError:
                pass
    return sorted(n for n in names if BASE <= n < BASE + len(words) * 4)


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def enclosing(starts, va):
    if not starts:
        return None
    i = bisect.bisect_right(starts, va) - 1
    if i < 0:
        return None
    return starts[i], va - starts[i]


def cmd_find_str(img):
    if len(sys.argv) < 3:
        sys.exit("find-str <text>")
    needle = sys.argv[2].encode()
    hits = 0
    for m in re.finditer(re.escape(needle), img):
        i = m.start()
        while i > 0 and 32 <= img[i - 1] < 127:
            i -= 1
        run = img[i:]
        end = run.find(b"\x00")
        print(f"  {BASE + i:#010x}  {run[:end if end > 0 else 64].decode(errors='replace')!r}")
        hits += 1
        if hits >= 20:
            break
    if not hits:
        print("  no hit (this string is not stored in the clear in the image)")


def cmd_fn(starts):
    if len(sys.argv) < 3:
        sys.exit("fn <hexVA> [...]")
    for a in sys.argv[2:]:
        va = int(a, 16) if not a.lower().startswith("0x") else int(a, 16)
        e = enclosing(starts, va)
        print(f"  {va:#010x} -> " + (f"sub_{e[0]:08X} +{e[1]:#x}" if e else "outside any known function"))


def _hi(w):
    return (w >> 26) & 0x3F


def cmd_xref(img, words, starts):
    if len(sys.argv) < 3:
        sys.exit("xref <hexVA>")
    target = int(sys.argv[2], 16)
    limit = int(sys.argv[4], 10) if len(sys.argv) > 4 and sys.argv[3] == "-n" else 40
    hi = [None] * 32
    found = 0
    for i, w in enumerate(words):
        pc = BASE + i * 4
        op = _hi(w)
        rt = (w >> 21) & 31
        ra = (w >> 16) & 31
        imm = w & 0xFFFF
        if op == 15:                     # addis rT,rA,IMM<<16;  rA==0 is `lis`
            if ra == 0:
                hi[rt] = (imm << 16) & 0xFFFFFFFF
                continue
            if hi[ra] is not None:
                hi[rt] = (hi[ra] + (imm << 16)) & 0xFFFFFFFF
                if hi[rt] == (target & 0xFFFF0000) and (imm << 16) & 0xFFFFFFFF:
                    print(f"  {pc:#010x} addis r{rt},r{ra} -> high half {hi[rt]:#x} of {target:#x}")
                    found += 1
            else:
                hi[rt] = None
            continue
        if op == 14:                     # addi rT,rA,IMM (sign-extended); rA==0 is `li`
            if hi[ra] is not None or ra == 0:
                basev = 0 if ra == 0 else hi[ra]
                val = (basev + sext16(imm)) & 0xFFFFFFFF
                if val == target:
                    e = enclosing(starts, pc)
                    print(f"  {pc:#010x} addi r{rt},r{ra}  in " +
                          (f"sub_{e[0]:08X} +{e[1]:#x}" if e and e[1] < 0x4000 else "non-code/data"))
                    found += 1
                    if found >= limit:
                        break
            hi[rt] = None
            continue
        if op in (32, 33, 34, 35, 36, 37, 40, 41, 42, 43, 44, 45, 46, 47):
            # loads into GPR/FPR: destination is no longer a known immediate
            hi[rt] = None
            if op in (32, 36) and hi[ra] is not None:
                if (hi[ra] + sext16(imm)) & 0xFFFFFFFF == target:
                    print(f"  {pc:#010x} lwz r{rt},{sext16(imm)}(r{ra}) reads target directly")
                    found += 1
            continue
        if op == 31 or op in (8, 9, 10, 48, 49, 50, 51, 52, 53, 54, 55):
            # Fixed-point arithmetic/logic and CR ops: rT is computed, so any
            # tracked immediate in that GPR is dead from here on.
            hi[rt] = None
    print(f"  {found} site(s) materialising {target:#x}")


def cmd_calls(words, starts):
    if len(sys.argv) < 3:
        sys.exit("calls <hexVA>")
    target = int(sys.argv[2], 16)
    n = 0
    for i, w in enumerate(words):
        if _hi(w) in (18, 16) and (w & 0x03FFFFFC):     # bl / bla family
            off = w & 0x03FFFFFC
            if off & 0x02000000:
                off -= 0x04000000
            if (BASE + i * 4 + off) & 0xFFFFFFFF == target:
                pc = BASE + i * 4
                e = enclosing(starts, pc)
                print(f"  {pc:#010x} bl -> " + (f"sub_{e[0]:08X} +{e[1]:#x}" if e else "?"))
                n += 1
                if n > 60:
                    break
    print(f"  {n} call site(s)")


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    img, words = load()
    starts = func_starts(words)
    cmd = sys.argv[1]
    if cmd == "find-str":
        cmd_find_str(img)
    elif cmd == "fn":
        cmd_fn(starts)
    elif cmd == "xref":
        cmd_xref(img, words, starts)
    elif cmd == "calls":
        cmd_calls(words, starts)
    else:
        print(__doc__)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
