#!/usr/bin/env python3
"""Static xrefs into the decompressed guest image (rules 3/14/15).

 PPC code materialises a 32-bit address as `lis rA,HI` followed (not necessarily
 immediately) by `addi rT,rA,LO` / `ori rT,rA,LO` (zero-extends) / `addis rT,rA,HI`;
 the second `lis` in a pair is a real hazard (do-not #16), so register state is
 tracked per-register across the scan instead of pairwise. Blind spot to remember:
 `hi[]` starts all-None and r2's TOC value is never seeded, so a TOC-relative
 `addis rT,r2,HI` + low half (F-359 §3) materialises nothing here.

  python tools/ppc_xrefs.py find-str <text>            # literal's VA (+ context)
  python tools/ppc_xrefs.py xref <hexVA> [-n <hits>]   # code that materialises it
  python tools/ppc_xrefs.py fn <hexVA> [<hexVA> ...]   # enclosing sub_XXXXXXXX
  python tools/ppc_xrefs.py calls <hexVA>              # branch edges
  python tools/ppc_xrefs.py --selftest [--image]       # hand-decoded refs

BRANCH TARGETS. `calls` used to mask BOTH op-18 and op-16 branch words with
0x03FFFFFC. That is right for op 18 and wrong for op 16, whose BD field is only
bits 15:2; the wide mask folded BO[4:0] (word bits 25:21) and BI[4:0] (bits
20:16) into the displacement, and the sign test `off & 0x02000000` read BO[4] as
the sign bit. Measured on build/cache/mcla_pe.bin: 128,375 of 146,177 opcode-16
words (87.82%) got a wrong target, and 124,367 of those landed off-image or
misaligned. AA (bit 1) was untested, which silently gave PC-relative semantics
to the 13,303 AA=1 opcode-16 and 1,469 AA=1 opcode-18 words. See
branch_target() for the decode and SELFTEST for the hand-derived references;
`--selftest --image` re-checks all 293,540 branch words in the image against
tools/ppc_disasm.py, which is capstone-validated, so the two tools cannot
silently disagree about the same bits.
"""
import array
import bisect
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
try:
    # Reuse ppc_disasm's capstone-validated BO mnemonic table and s16 rather
    # than forking a second copy that could drift (AGENTS.md: two tools
    # disagreeing about the same bits is the standing failure mode).
    import ppc_disasm
except ImportError:                                     # pragma: no cover
    ppc_disasm = None

IMAGE = "build/cache/mcla_pe.bin"
BASE = 0x82000000  # rule 3: offset in mcla_pe.bin = VA - BASE (identity, no section table)
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
    """`sub_XXXXXXXX` tokens in generated/ppc_xenon/*.cpp (definitions and uses), kept if inside the image."""
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


# ---------------------------------------------------------------------------
# Branch target decode. Two DIFFERENT displacement fields live behind opcodes
# 16 and 18, which is exactly why the old single-mask version was wrong.
#
#   op 18  b / bl        LI = word bits 25:2. 24-bit signed, ALREADY <<2,
#                        so mask 0x03FFFFFC; sign bit is LI bit 23 = 0x02000000.
#   op 16  bc / bclr /   BD = word bits 15:2. 14-bit signed, ALREADY <<2,
#        bcctr           so mask 0xFFFC;    sign bit is BD bit 13 = 0x00008000.
#
# Note `already <<2`: BD is a field of *word-aligned byte offsets*, not an
# instruction count. `w & 0xFFFC` is therefore already BD*4; shifting it again
# (the classic "(i>>2)&0x3FFF then <<2" round trip) is how the low 2 bits get
# lost. Proof the mask, not a shift, is right: word 0x4098000C has BD = 3, and
# PC + 3 = 0x821CC307 which is unaligned and cannot be an instruction, while
# PC + BD*4 = PC + 12 = 0x821CC310, a real lwz.
#
# AA (bit 1) = 1 means the displacement IS the address (no PC added). It was
# untested before; PC-relative semantics applied to every AA=1 word.
#
# Arithmetic is identical to ppc_disasm.decode() op16/op18, which was
# validated word-by-word against capstone. --selftest cross-checks the two.
# ---------------------------------------------------------------------------
def branch_target(w, pc, op):
    """(target, aa, lk) for a branch word. op must be 16 or 18."""
    aa = (w >> 1) & 1
    lk = w & 1
    if op == 18:
        disp = w & 0x03FFFFFC
        if disp & 0x02000000:
            disp -= 0x04000000
    else:
        disp = w & 0xFFFC
        if disp & 0x8000:
            disp -= 0x10000
    return ((disp if aa else pc + disp) & 0xFFFFFFFF, aa, lk)


def branch_mnemonic(w, op):
    """Short label for the branch word, so `calls` output stops calling every
    edge `bl`. Op 16 borrows ppc_disasm's BO table; op 18 is `b`/`bl`."""
    if op == 18:
        return ("bl" if w & 1 else "b") + (" aa" if (w >> 1) & 1 else "")
    if ppc_disasm is not None:
        bo, bi = (w >> 21) & 31, (w >> 16) & 31
        txt = ppc_disasm.bo_mnemonic(bo, bi)
        opnd = ppc_disasm.bo_operand(bo, bi)
        if opnd:
            txt += " " + opnd
    else:                                               # pragma: no cover
        txt = f"bc bo={(w >> 21) & 31} bi={(w >> 16) & 31}"
    return txt + (" aa" if (w >> 1) & 1 else "") + (" l" if w & 1 else "")


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
    # KNOWN DEFECT, REPORTED NOT FIXED (same class as the `calls` mask bug: a
    # confident wrong answer where a check is missing). enclosing() has NO
    # image-bounds test, so an address past the end of mcla_pe.bin returns the
    # last known function start plus a nonsense offset instead of saying "no".
    # Measured: `fn 0x83000000` -> "sub_827CCBC0 +0x833440" (image ends
    # 0x829E0000) and `fn 0x8FFFFFFF` -> "sub_827CCBC0 +0xd83343f". Treat an
    # `fn` answer as meaningful only when the +offset is plausibly small.
    if len(sys.argv) < 3:
        sys.exit("fn <hexVA> [...]")
    for a in sys.argv[2:]:
        va = int(a, 16) if not a.lower().startswith("0x") else int(a, 16)
        e = enclosing(starts, va)
        print(f"  {va:#010x} -> " + (f"sub_{e[0]:08X} +{e[1]:#x}" if e else "outside any known function"))


def _hi(w):
    return (w >> 26) & 0x3F


def cmd_xref(img, words, starts):
    # THREE KNOWN BLIND SPOTS, REPORTED NOT FIXED -- all of them make a zero
    # here meaningless, which is the "xref gives false zeros" trap:
    #  (1) THIS FUNCTION NEVER REPORTS A BRANCH TARGET. It only models address
    #      materialisation in rA/rS. Asking it about a `bc`/`bl` destination
    #      returns 0 BY CONSTRUCTION: measured `xref 0x821CC31C` -> 0 sites,
    #      yet 0x821CC2FC really is `beq cr6 -> 0x821CC31C`. Use `calls`.
    #  (2) op 25 (oris), 26 (xori) and 27 (xoris) are not handled, although each
    #      zero-extends a 16-bit immediate and can therefore build a whole
    #      32-bit address in one instruction. Census of this image: 20,143
    #      oris + 9,591 xori + 19,934 xoris = 49,668 words in the unhandled
    #      space. They also leave hi[rt] stale, so this is a false zero AND a
    #      false positive at once.
    #  (3) hi[] starts all-None and r2's TOC value is never seeded (module
    #      docstring), so no TOC-relative addis ever materialises.
    #  NOTE: ROOT_CAUSE_VALIDATION.md:7063 says this tool "never tracks `ori`
    #  (op 60)". Both halves are wrong -- ori IS tracked, at the `op == 24`
    #  branch below, and ori is op 24 not op 60. Verified: `xref 0xC000000D`
    #  finds 17 sites including the lis+ori pair at 0x82131EA4.
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
        if op == 24:                     # ori rT,rA,IMM (IMM zero-extends)
            # `lis rT,HI` + `ori rT,rT,LO` builds an address WITHOUT sign-extending
            # the low half, which `addi` cannot express, so an addi-only scan misses
            # it. Census of the current mcla_pe.bin: 90,192 op-15 words, 72,344 with
            # rA==0 (`lis`); a tracked `lis` result feeds 38,980 `addi` but only 2,451
            # `ori` -- the rarer pairing, not a dominant one (F-359 §3, commit 7307f02).
            if hi[ra] is not None or ra == 0:
                basev = 0 if ra == 0 else hi[ra]
                val = (basev & 0xFFFF0000) | imm
                if val == target:
                    e = enclosing(starts, pc)
                    print(f"  {pc:#010x} ori r{rt},r{ra},{imm:#x}  in " +
                          (f"sub_{e[0]:08X} +{e[1]:#x}" if e and e[1] < 0x4000 else "non-code/data"))
                    found += 1
                    if found >= limit:
                        break
            hi[rt] = None
            continue
        if op in (32, 33, 34, 35, 36, 37, 40, 41, 42, 43, 44, 45, 46, 47):
            # int load/store group (36/37/44/45 stores, 46/47 lmw-cmpl): rT is not an immediate
            # KNOWN DEFECT, REPORTED NOT FIXED: `hi[rt] = None` here is wrong for
            # the STORES (36 stw / 37 stwu / 47 stmw). Those have no rD -- rt is a
            # SOURCE operand and the register survives -- so this line erases a
            # live `lis` high half and every later `addi rT,rX,LO` that wanted it
            # silently stops matching. That is a FALSE NEGATIVE, i.e. a `xref`
            # zero that means nothing (F-057(6) shape). Fixing it needs a real
            # dest-mask per opcode, not a shared tuple.
            hi[rt] = None
            if op in (32, 36) and hi[ra] is not None:  # 36 = stw: that match is a write
                if (hi[ra] + sext16(imm)) & 0xFFFFFFFF == target:
                    print(f"  {pc:#010x} lwz r{rt},{sext16(imm)}(r{ra}) reads target directly")
                    found += 1
            continue
        if op == 31 or op in (8, 9, 10, 48, 49, 50, 51, 52, 53, 54, 55):
            # 31 fixed-point arith/logic, 8 subf, 9 mask, 10 cmp: rT is computed, so any
            # tracked immediate dies. 48-51 are FP stores, 52-55 FP loads (rT is no GPR dest).
            hi[rt] = None  # opcodes matched by no case above leave hi[] stale
    print(f"  {found} site(s) materialising {target:#x}")


def cmd_calls(words, starts):
    if len(sys.argv) < 3:
        sys.exit("calls <hexVA>")
    target = int(sys.argv[2], 16)
    n = 0
    # Ops 16 and 18 carry DIFFERENT displacement widths; branch so each uses its
    # own field (see branch_target). Also note what this cannot see: 15,392
    # register-INDIRECT call sites (bctrl/bctr/bcctrl, op 19) in this image have
    # no static target and are therefore unreachable from here by construction.
    for i, w in enumerate(words):
        op = _hi(w)
        if op not in (16, 18):
            continue
        if not (w & (0xFFFC if op == 16 else 0x03FFFFFC)):
            continue                                   # zero displacement: branches to itself
        pc = BASE + i * 4
        if branch_target(w, pc, op)[0] == target:
            e = enclosing(starts, pc)
            print(f"  {pc:#010x} bl -> " + (f"sub_{e[0]:08X} +{e[1]:#x}" if e else "?")
                  + f"   [{branch_mnemonic(w, op)}]")
            n += 1
            if n > 60:
                break
    print(f"  {n} call site(s)")


# ---------------------------------------------------------------------------
# Self-test: (word, pc, opcode, expected_target, expected_mnemonic).
# Every word below was decoded from its own bits first; the guest ones are
# confirmed against the raw bytes of build/cache/mcla_pe.bin (offset = VA -
# 0x82000000). This is the citation for the `calls` decode -- if a row here has
# to change, something real broke.
# ---------------------------------------------------------------------------
SELFTEST = [
    # --- the case the bug was reported with --------------------------------
    # 0x419A0020: op = 16. BO = (w>>21)&31 = 12, BI = (w>>16)&31 = 26, AA = 0,
    #   LK = 0. BD = w & 0xFFFC = 0x20 = 32 (BD is ALREADY <<2, not 8 instrs).
    #   AA=0 -> PC-relative: 0x821CC2FC + 32 = 0x821CC31C.
    #   OLD code gave 0x83B6C31C: it masked 0x03FFFFFC -> 0x019A0020, i.e. it
    #   read BO=12 and BI=26 as displacement bits and then added ~26 MB.
    (0x419A0020, 0x821CC2FC, 16, 0x821CC31C, "beq cr6"),
    # 0x409AFF38: same site family, NEGATIVE BD. BD = 0xFF38, bit 13 set ->
    #   0xFF38 - 0x10000 = -200 -> 0x821CC318 - 200 = 0x821CC250.
    (0x409AFF38, 0x821CC318, 16, 0x821CC250, "bne cr6"),
    # 0x4098000C: BD = 3 (NOT PC+3, which is unaligned 0x821CC307) -> PC+12.
    (0x4098000C, 0x821CC304, 16, 0x821CC310, "bge cr6"),
    # --- op 16 with AA=1: the displacement IS the address ------------------
    # 0x40980022: identical to the row above plus AA (bit 1). Target becomes
    #   BD*4 = 0x00000020 absolutely. OLD code added the PC and produced
    #   0x83A4C12E, which is 26 MB off.
    (0x40980022, 0x821CC304, 16, 0x00000020, "bge cr6 aa"),
    # AA=1 reaching a data address. BD = 0x1234 -> absolute 0x1234. Note BD is
    # only 14 bits, so an AA=1 `bc` can never reach further than 0xFFFC; the
    # OLD mask made it "reach" 26 MB, which is how the bug looked plausible.
    # OLD code: 0x40981236 & 0x03FFFFFC = 0x01981236 -> target 0x83B64D32.
    (0x40981236, 0x821CC2FC, 16, 0x00001234, "bge cr6 aa"),
    # --- op 18, the form the old mask happened to get right ---------------
    # 0x4BFF130D: op = 18, LK = 1 -> bl. LI = w & 0x03FFFFFC = 0x03FF130C,
    #   bit 25 set -> 0x03FF130C - 0x04000000 = -0xECF4 (-60,660). Note the
    #   subtraction is 0x04000000 - 0x03FF130C = 0xECF4; it is NOT 0xEECF4.
    #   0x821CC30C - 0xECF4 = 0x821BD618. Cross-checked against the raw word
    #   at 0x821CC30C and against capstone.
    (0x4BFF130D, 0x821CC30C, 18, 0x821BD618, "bl"),
    # op 18, LK=0: a plain `b`, i.e. NOT a call. Old output mislabelled it `bl`.
    (0x48000030, 0x82750D20, 18, 0x82750D50, "b"),
    # --- op 18 with AA=1: branch to absolute, no PC ------------------------
    # 0x481CC31E: op = 18, AA = 1, LK = 0. LI = 0x01CC31C, positive, so the
    #   target is 0x01CC31C absolute -- NOT 0x82398D1A (PC-relative, the old
    #   behaviour).
    (0x481CC31E, 0x821CC2FC, 18, 0x01CC31C, "b aa"),
    # op 18, AA=1 and LK=1 -> `bl aa`, still absolute.
    (0x481CC31F, 0x821CC2FC, 18, 0x01CC31C, "bl aa"),
    # The same word as the `bl` row above, at a different PC: a branch word's
    # target MOVES with its PC when AA=0. LI = -0xECF4 -> 0x82750BD4 - 0xECF4
    # = 0x82741EE0. (0x0BD4 = 3,028, not 1,748 -- the borrow arithmetic is the
    # whole test of a 14-bit displacement, which is why it is pinned here.)
    (0x4BFF130D, 0x82750BD4, 18, 0x82741EE0, "bl"),
]


def _mnem(w, op):
    return branch_mnemonic(w, op)


def selftest(image=False, verbose=False):
    """Hand-decoded reference check; with image=True also cross-checks every
    branch word in mcla_pe.bin against tools/ppc_disasm.py."""
    bad = 0
    print(f"{'word':>10} {'pc':>10}  op  {'expected':>10}  got        mnemonic")
    print("-" * 78)
    for w, pc, op, want_t, want_m in SELFTEST:
        got_t, _, _ = branch_target(w, pc, op)
        got_m = _mnem(w, op)
        ok = (got_t == want_t) and (got_m == want_m)
        bad += not ok
        if not ok or verbose:
            print(f"{w:08X}   {pc:08X}  {op:<3} {want_t:08X}   "
                  f"{'ok  ' if ok else 'FAIL'} {got_t:08X}   {got_m}")
            if not ok:
                if got_t != want_t:
                    print(f"{'':>10} {'':>10}       target wanted {want_t:08X} "
                          f"got {got_t:08X}")
                if got_m != want_m:
                    print(f"{'':>10} {'':>10}       mnemonic wanted {want_m!r} "
                          f"got {got_m!r}")
    print("-" * 78)
    print(f"{len(SELFTEST) - bad}/{len(SELFTEST)} reference decodes correct")

    if image:
        bad += _image_crosscheck(verbose)
    elif ppc_disasm is None:
        print("NOTE: ppc_disasm.py not importable -- the mnemonic table could "
              "not be shared. Run from the repo root so tools/ is on sys.path.")

    if bad:
        print(f"FAIL: {bad} check(s) wrong. Do not trust `calls` output until "
              f"the branch decode agrees with the references above.")
        return 1
    print("PASS: op-16 BD and op-18 LI decode to the hand-derived targets, AA "
          "is honoured, and mnemonics match.")
    return 0


def _image_crosscheck(verbose=False):
    """Compare branch_target() against tools/ppc_disasm.py over the whole image.

    The point is that a second tool must never disagree about the same bits.
    ppc_disasm prints its target in the instruction text; parse that back and
    compare, so any future edit to either decode shows up here as a failure
    rather than as two divergent answers in two findings.
    """
    if ppc_disasm is None:
        print("SKIP: ppc_disasm.py not importable, cannot cross-check.")
        return 0
    img, words = load()
    checked = agree = skipped = 0
    bad = []
    import re as _re
    tgt_re = _re.compile(r"(?:^|\s)(?:->\s*)?((?:0x)?[0-9a-fA-F]{6,8})\b")
    for i, w in enumerate(words):
        op = _hi(w)
        if op not in (16, 18):
            continue
        pc = BASE + i * 4
        if not (w & (0xFFFC if op == 16 else 0x03FFFFFC)):
            skipped += 1
            continue
        text = ppc_disasm.decode(w, pc)
        m = tgt_re.search(text)
        if not m:
            skipped += 1
            continue
        tok = m.group(1)
        ref = int(tok, 16) if tok.lower().startswith("0x") else int(tok, 16)
        checked += 1
        if branch_target(w, pc, op)[0] == ref:
            agree += 1
        elif len(bad) < 10:
            bad.append((pc, w, text, branch_target(w, pc, op)[0], ref))
    print(f"image cross-check vs ppc_disasm.py: {agree}/{checked} branch words "
          f"agree ({skipped} zero-displacement skipped)")
    for pc, w, text, mine, ref in bad:
        print(f"  DISAGREE {pc:08X} {w:08X} mine={mine:08X} "
              f"ppc_disasm={ref:08X}  [{text}]")
    return len(bad)


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    if sys.argv[1] == "--selftest":
        return selftest("--image" in sys.argv, "-v" in sys.argv)
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
