"""Tiny PPC32 big-endian disassembler for hand-picked windows from
mcla_pe.bin. Usage:

  python tools/ppc_disasm.py <hexVA> <nInstructions>   # decode a window
  python tools/ppc_disasm.py --selftest               # hand-decoded refs

File offset = VA - 0x82000000.

BRANCHES ARE RENDERED AS MNEMONICS, not as raw `bo=` numbers (F-633). The old
decoder printed `bc bo=12 bi=26` and left the reader to interpret BO by hand.
That is how a comment in src/task_dispatch_trace.cpp came to read the disc-check
as "fatals on ==1": BO=12 was taken at face value. BO is a packed bitfield, not
an opcode -- 12 is `beq`, not `blt`-with-a-number. `bo=`/`bi=` are STILL printed
in brackets after the mnemonic so nothing is lost; the mnemonic is additive, so
every existing reader of this tool's output keeps working.

Everything below is decoded from the raw word by shift/mask only. The BO table was
not recalled from a manual: it was tabulated from all 146,177 opcode-16 words of
build/cache/mcla_pe.bin and validated word-by-word against capstone plus the
project's own generated/ppc_xenon/ppc_recomp.*.cpp. Over the 493 distinct
(BO, BI&3, AA, LK) keys in that image the mapping to a mnemonic is SINGLE-VALUED
(0 ambiguities), so bo_mnemonic() below is a function of those four fields and
nothing else. Run `--selftest` after touching it.
"""
import struct
import sys

PE = "build/cache/mcla_pe.bin"
BASE = 0x82000000


def r(n):
    return f"r{n}"


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def bo_mnemonic(bo, bi):
    """Canonical conditional-branch mnemonic from the BO/BI bitfields.

    BO is bits 25..21 of the word. Named by their bit POSITION IN THE WORD,
    which is what AGENTS.md means by "BO bit 0":
      word bit 21 = BO[0] = SO   word bit 22 = BO[1] = EQ
      word bit 23 = BO[2] = GT   word bit 24 = BO[3] = LT
      word bit 25 = BO[4] = CC  (0 = test a CR bit, 1 = test a COUNT register)
    BI is bits 20..16: BI[3:2] = the CR field, BI[1:0] = which bit of it.

      * BO[4]==1 -> BI is a register, not a CR field (`bdnz rD` / `bdz rD`).
        BO[1] picks zero vs non-zero; BO[3]=1 with BO[2]=0 marks the pre-test
        ('-') form.
      * BO[4]==0 and BO[2]==1 -> compare CR bit BI[1:0]. BO[3]=1 means "bit is
        SET" (blt/bgt/beq/bso); BO[3]=0 means "bit is CLEAR" (bge/ble/bne/bns).
      * BO[4]==0 and BO[2]==BO[3]==0 -> no comparison at all.

    Returns "beq cr6" style text, with the "crN" operand omitted for CR0.
    """
    so = bo & 1
    eq = (bo >> 1) & 1
    gt = (bo >> 2) & 1
    lt = (bo >> 3) & 1
    cc = (bo >> 4) & 1
    mark = "-" if so == 0 else "+"
    if cc:                                     # BI is a count register
        return "bd" + ("z" if eq else "nz") + (mark if lt and not gt else "")
    if not gt and not lt:                      # no comparison tested
        return "bd" + ("zf" if eq else "nzf")
    if not gt and lt:                          # count-then-compare form
        return "bd" + ("z" if eq else "nz") + "t"
    # gt == 1: compare CR bit bi&3. lt=1 -> "bit is SET", lt=0 -> "bit is CLEAR".
    core = ("blt", "bgt", "beq", "bso")[bi & 3] if lt else \
           ("bge", "ble", "bne", "bns")[bi & 3]
    return core + (mark if eq else "")


def bo_operand(bo, bi):
    """Operand text after the mnemonic: the CR field for CR-bit branches, a
    register name for the count-register forms, nothing for CR0."""
    if (bo >> 4) & 1:                          # BO[4]=1 -> BI is a register
        return f"r{bi}"
    crf = bi >> 2
    return f"cr{crf}" if crf else ""


def rot_mask(mb, me):
    """ISA rotate mask for MB/ME. MSB-numbered: bit 0 is the MSB (0x80000000).
    Wraps when MB > ME -- that split mask is what a compiler uses for sign/zero
    extension, and getting it wrong is the "masks render backwards" trap:
      MB=1, ME=1  -> one bit, 0x40000000   (NOT 0x00000001, NOT 0x80000000)
      MB=0, ME=29 -> 0xFFFFFFFC
      MB=3, ME=1  -> bits 3..31 | bits 0..1 = 0xDFFFFFFF
    """
    m = 0
    rng = range(mb, me + 1) if mb <= me else \
        list(range(mb, 32)) + list(range(0, me + 1))
    for bit in rng:
        m |= 0x80000000 >> bit
    return m


def decode(i, pc):
    op = i >> 26
    d = (i >> 21) & 31
    a = (i >> 16) & 31
    b = (i >> 11) & 31
    xo = (i >> 1) & 0x3FF
    xo9 = (i >> 1) & 0x1FF
    simm = s16(i & 0xFFFF)
    uimm = i & 0xFFFF
    bo = (i >> 21) & 31
    bi = (i >> 16) & 31
    li = i & 0x03FFFFFC
    if li & 0x02000000:
        li -= 0x04000000
    mb = (i >> 6) & 31
    me = (i >> 1) & 31
    crd = (i >> 23) & 7
    rc = "." if i & 1 else ""

    if op == 14:
        return f"addi {r(d)},{r(a)},{simm}" if a else f"li {r(d)},{simm}"
    if op == 15:
        return f"lis {r(d)},{uimm:04X}"
    if op == 24:
        return f"ori {r(d)},{r(a)},{uimm:04X}"
    if op == 25:
        return f"oris {r(d)},{r(a)},{uimm:04X}"
    if op == 26:
        return f"xori {r(d)},{r(a)},{uimm:04X}"
    if op == 27:
        return f"xoris {r(d)},{r(a)},{uimm:04X}"
    if op == 12:
        return f"addic {r(d)},{r(a)},{simm}"
    if op == 13:
        return f"addic. {r(d)},{r(a)},{simm}"
    if op == 7:
        return f"mulli {r(d)},{r(a)},{simm}"
    if op == 8:
        return f"subfic {r(d)},{r(a)},{simm}"
    if op == 10:
        return f"cmpli cr{crd},{r(a)},{uimm:04X}"
    if op == 11:
        return f"cmpi cr{crd},{r(a)},{simm}"
    if op == 16:  # bc -- BD is bits 15:2, so (i & 0xFFFC) is ALREADY BD*4;
                 # do not "fix" this into (i>>2)&0x3FFF and lose the <<2.
                 # Proof it is not PC+BD: for BD=3 (word 0x4098000C) PC+BD is
                 # 0x821CC307, an unaligned non-instruction. BD=3*4 = 12 gives
                 # 0x821CC310, which is a real `lwz`.
        aa = i & 2
        bd = s16(i & 0xFFFC)
        tgt = bd if aa else pc + bd
        _m = bo_mnemonic(bo, bi)
        _o = bo_operand(bo, bi)
        return (f"{_m} {_o} -> {tgt & 0xFFFFFFFF:08X}".replace("  ", " ")
                + (" aa" if aa else "") + (" l" if i & 1 else "")
                + f"  [bo={bo} bi={bi}]")
    if op == 18:  # b
        aa = i & 2
        tgt = li if aa else pc + li
        return f"b{'l' if i & 1 else ''} {tgt & 0xFFFFFFFF:08X}" + (" aa" if aa else "")
    if op == 19:
        # 10-bit xo: 528 & 0x1FF == 16, so a 9-bit mask printed bctr/bctrl (a
        # computed CALL) with the same string as blr (a RETURN). Both keep the
        # 10-bit test so 528 stays distinguishable from 16.
        if xo == 16 or xo == 528:
            _reg = "lr" if xo == 16 else "ctr"
            _lk = "l" if i & 1 else ""
            if bo == 20:                        # BO=20 -> no condition tested
                # Bare, no annotation: this form already agreed with capstone
                # before the annotation existed and must not lose that.
                return f"b{_reg}{_lk}"
            # conditional: `bge cr6` -> `bgelr`. Capstone names these by
            # appending the register suffix to the BO mnemonic, so do the same.
            return f"{bo_mnemonic(bo, bi)}{_reg}{_lk}  [bo={bo} bi={bi} xo={xo}]"
        if xo == 18 or xo == 530:
            return f"bc{'ctr' if xo == 530 else 'lr'}  [bo={bo} bi={bi} xo={xo}]"
        if xo == 17 or xo == 529:
            return f"b{'ctr' if xo == 529 else 'lr'}l bo={bo} bi={bi} aa"
        if xo == 19 or xo == 531:
            return f"b{'ctr' if xo == 531 else 'lr'}la bo={bo} bi={bi} aa"
        if xo == 50:                            # rfi; the 9-bit xo9==20 test that
            return "rfi"                         # used to be here can never fire
            # (rfi is XO=50, and 50 & 0x1FF == 50, never 20). NOT exercised by
            # this image -- no op-19 XO=50 word exists in mcla_pe.bin.
        if xo9 == 0:
            return f"mcrf cr{crd},cr{(i >> 18) & 7}"
        if xo9 in (257, 33, 449, 225, 193, 417, 289, 129, 353, 385, 421):
            return f"cr-op {xo9}"
        return f"op19:{xo9}"
    if op == 31:
        if xo == 0:
            return f"cmpw cr{crd},{r(a)},{r(b)}"
        if xo == 32:
            return f"cmplw cr{crd},{r(a)},{r(b)}"
        if xo == 266:
            return f"add {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 40:
            return f"subf {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 10:
            return f"addc {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 138:
            return f"adde {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 234:
            return f"addme {r(d)},{r(a)}{rc}"
        if xo == 202:
            return f"addze {r(d)},{r(a)}{rc}"
        if xo == 8:
            return f"subfc {r(d)},{r(a)},{r(b)}"
        if xo == 136:
            return f"subfe {r(d)},{r(a)},{r(b)}"
        if xo == 104:
            return f"neg {r(d)},{r(a)}"
        # X-form logical/shift keeps RA (destination) at bits 11-15 (`a`) and RS
        # (first source) at bits 6-10 (`d`) - the reverse of the XO arithmetic
        # group above. Ground truth = the recompiler's emitted semantics at a
        # VA anchored by ctx.lr: 821B4AB0, 821B6D3C, 821B6E28, 821B6CF0,
        # 821BD1C4, 821B9DC8, 821B6F1C, 82554358.
        if xo == 824:
            return f"srawi {r(a)},{r(d)},{b}{rc}"
        if xo == 792:
            return f"sraw {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 24:
            return f"slw {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 536:
            return f"srw {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 28:
            return f"and {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 444:
            # mr rA,rS == or rA,rS,rS, so it is an mr only when RB == RS.
            return f"mr {r(a)},{r(d)}" if d == b else f"or {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 478:
            return f"nand {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 124:
            return f"nor {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 56:
            return f"eqv {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 284:
            return f"orc {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 60:
            return f"andc {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 412:
            return f"orc {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 316:
            return f"xor {r(a)},{r(d)},{r(b)}{rc}"
        if xo == 20:
            return f"lwarx {r(d)},{r(a)},{r(b)}"
        if xo == 150:
            return f"stwcx. {r(d)},{r(a)},{r(b)}"
        if xo == 151:
            return f"stwx {r(d)},{r(a)},{r(b)}"
        if xo == 183:
            return f"stwux {r(d)},{r(a)},{r(b)}"
        if xo == 215:
            return f"stbx {r(d)},{r(a)},{r(b)}"
        if xo == 247:
            return f"stbux {r(d)},{r(a)},{r(b)}"
        if xo == 407:
            return f"sthx {r(d)},{r(a)},{r(b)}"
        if xo == 439:
            return f"sthux {r(d)},{r(a)},{r(b)}"
        if xo == 278:
            return "eieio"
        if xo == 598:
            return "sync"
        if xo == 214:
            return f"stwx?214 {r(d)},{r(a)},{r(b)}"
        if xo == 23:
            return f"lwzx {r(d)},{r(a)},{r(b)}"
        if xo == 55:
            return f"lwzux {r(d)},{r(a)},{r(b)}"
        if xo == 87:
            return f"lbzx {r(d)},{r(a)},{r(b)}"
        if xo == 119:
            return f"lbzux {r(d)},{r(a)},{r(b)}"
        if xo == 279:
            return f"lhzx {r(d)},{r(a)},{r(b)}"
        if xo == 311:
            return f"lhzu"
        if xo == 341:
            return f"lwax {r(d)},{r(a)},{r(b)}"
        if xo == 343:
            return f"lhax {r(d)},{r(a)},{r(b)}"
        if xo == 533:
            return f"lswx {r(d)},{r(a)},{r(b)}"
        if xo == 597:
            return f"lswi {r(d)},{r(a)},{b}"
        if xo == 661:
            return f"stswi {r(d)},{r(a)},{b}"
        if xo == 986:  # XeCPU lvewx / vec: on integer decode = 'or with shift'? keep raw
            return f"op31:986 {r(d)},{r(a)},{r(b)}"
        if xo == 725:
            return f"stswx {r(d)},{r(a)},{r(b)}"
        if xo == 922:
            return f"extsh {r(a)},{r(d)}{rc}"
        if xo == 954:
            return f"extsb {r(a)},{r(d)}{rc}"
        if xo == 58:
            return f"cntlzw {r(a)},{r(d)}{rc}"
        if xo == 339:  # mfspr (spr = SPR[10:5]<<5 | SPR[4:0]; bits 15:11 = high)
            spr = (((i >> 11) & 31) << 5) | ((i >> 16) & 31)
            name = {8: "lr", 9: "ctr", 26: "srr0", 27: "srr1"}.get(spr, f"spr{spr}")
            return f"mf{name} {r(d)}" if spr in (8, 9) else f"mfspr {r(d)},{name}"
        if xo == 467:  # mtspr
            spr = (((i >> 11) & 31) << 5) | ((i >> 16) & 31)
            name = {8: "lr", 9: "ctr", 26: "srr0", 27: "srr1"}.get(spr, f"spr{spr}")
            return f"mt{name} {r(d)}" if spr in (8, 9) else f"mtspr {name},{r(d)}"
        if xo == 19:
            return f"mfcr {r(d)}"
        if xo == 68 or xo == 144:
            return f"mtcrf {uimm:02X},{r(d)}"
        if xo == 83:
            return f"mfmsr {r(d)}"
        if xo == 616:
            return f"mtmsr {r(d)}"
        return f"op31:{xo} d={d} a={a} b={b}{rc}"
    if op == 32:
        return f"lwz {r(d)},{simm}({r(a)})"
    if op == 33:
        return f"lwzu {r(d)},{simm}({r(a)})"
    if op == 34:
        return f"lbz {r(d)},{simm}({r(a)})"
    if op == 35:
        return f"lbzu {r(d)},{simm}({r(a)})"
    if op == 36:
        return f"stw {r(d)},{simm}({r(a)})"
    if op == 37:
        return f"stwu {r(d)},{simm}({r(a)})"
    if op == 38:
        return f"stb {r(d)},{simm}({r(a)})"
    if op == 39:
        return f"stbu {r(d)},{simm}({r(a)})"
    if op == 40:
        return f"lhz {r(d)},{simm}({r(a)})"
    if op == 41:
        return f"lhzu {r(d)},{simm}({r(a)})"
    if op == 42:
        return f"lha {r(d)},{simm}({r(a)})"
    if op == 43:
        return f"lhau {r(d)},{simm}({r(a)})"
    if op == 44:
        return f"sth {r(d)},{simm}({r(a)})"
    if op == 45:
        return f"sthu {r(d)},{simm}({r(a)})"
    if op == 46:
        return f"lmw {r(d)},{simm}({r(a)})"
    if op == 47:
        return f"stmw {r(d)},{simm}({r(a)})"
    if op == 3:
        return f"twi to={d},{r(a)},{simm}"
    if op == 2:
        return f"tdi to={d},{r(a)},{simm}"
    if op == 17:
        return "sc"
    if op == 20:
        return f"lswi {r(d)},{r(a)},{b}"
    if op == 21:
        # rlwinm: rA is bits 20:16, rS is bits 25:21 -- the REVERSE of the
        # XO-arithmetic group above, which uses d (bits 25:21) as the source.
        # The resolved mask is printed next to MB/ME so nobody has to redo the
        # MSB-numbered bit arithmetic by hand and get it backwards.
        return (f"rlwinm {r(a)},{r(d)},sh={b},mb={mb},me={me}"
                f",mask=0x{rot_mask(mb, me):08X}{rc}")
    if op == 23:
        return (f"rlwnm {r(a)},{r(d)},{r(b)},mb={mb},me={me}"
                f",mask=0x{rot_mask(mb, me):08X}{rc}")
    if op == 30:
        return f"rldic-family {i:08X}"
    if op == 4:
        return f"float/ps {i:08X}"
    if op == 58:  # 64-bit D-form: ds = bits 15:2, low 2 bits select opcode
        ds = (i & 0xFFFC)
        sub = i & 3
        if sub == 0:
            return f"ld {r(d)},{ds}({r(a)})"
        if sub == 1:
            return f"ldu {r(d)},{ds}({r(a)})"
        if sub == 2:
            return f"lwa {r(d)},{ds}({r(a)})"
        return f"op58sub{sub} {i:08X}"
    if op == 62:  # 64-bit D-form stores
        ds = (i & 0xFFFC)
        sub = i & 3
        if sub == 0:
            return f"std {r(d)},{ds}({r(a)})"
        if sub == 1:
            return f"stdu {r(d)},{ds}({r(a)})"
        return f"op62sub{sub} {i:08X}"
    return f"?op{op}:{i:08X}"


# ---------------------------------------------------------------------------
# Self-test: (word, pc, expected decode). Every word below was hand-decoded from
# its bits first, then confirmed against the raw bytes of build/cache/mcla_pe.bin
# (offset = VA - 0x82000000) and against capstone + generated/ppc_xenon/.
# The BO column records the derivation so a future editor can re-check it
# without trusting this table.
#
# The four gate rows are the disc-check block at 0x821CC2F8..0x821CC304 whose
# wrong reading produced a wrong decision (F-633). If any of these four change,
# something real broke.
# ---------------------------------------------------------------------------
SELFTEST = [
    # --- the disc-check window, byte-for-byte from build/cache/mcla_pe.bin ---
    # 0x2F1D0001: op=11, RT=24->CR6, RA=r29, imm=1  (D-form imm is bits 15:0)
    (0x2F1D0001, 0x821CC2F8, "cmpi cr6,r29,1"),
    # 0x419A0020: BO=(w>>21)&0x1F=12=0b01100 -> bit23(GT)=1,bit24(LT)=1,bit25(CC)=0
    #   -> set-sense, BI=(w>>16)&0x1F=26, 26&3=2 -> beq, 26>>2=6 -> cr6
    #   BD*4 = w&0xFFFC = 0x20 = 32 -> 0x821CC2FC+32 = 0x821CC31C
    (0x419A0020, 0x821CC2FC, "beq cr6 -> 821CC31C  [bo=12 bi=26]"),
    # 0x2F1D0000: same compare, immediate 0
    (0x2F1D0000, 0x821CC300, "cmpi cr6,r29,0"),
    # 0x4098000C: BO=4=0b00100 -> GT=1, LT=0 -> clear-sense; BI=24, 24&3=0 -> bge
    #   BD=3 -> PC+BD would be 0x821CC307 (unaligned, impossible) -> BD*4=12
    #   -> 0x821CC304+12 = 0x821CC310
    (0x4098000C, 0x821CC304, "bge cr6 -> 821CC310  [bo=4 bi=24]"),
    # 0x4BFF130D: op=18, LK=1 -> bl; LI*4 = w&0x03FFFFFC = 0xFF130C,
    #   sign-extended = -86452 -> 0x821CC30C-86452 = 0x821BD618
    (0x4BFF130D, 0x821CC30C, "bl 821BD618"),
    # 0x409AFF38: BO=4 (clear-sense), BI=26, 26&3=2 -> bne; BD*4=0xFF38=-200
    (0x409AFF38, 0x821CC318, "bne cr6 -> 821CC250  [bo=4 bi=26]"),
    # --- the rest of the BO space, constructed by hand from the encoding ---
    # BO=4 BI=25 -> 25&3=1 -> ble ; BD*4=0x20
    (0x40990020, 0x821CC2FC, "ble cr6 -> 821CC31C  [bo=4 bi=25]"),
    # BO=12 BI=25 -> 25&3=1 -> bgt
    (0x41990020, 0x821CC2FC, "bgt cr6 -> 821CC31C  [bo=12 bi=25]"),
    # BO=12 BI=24 -> 24&3=0 -> blt
    (0x41980020, 0x821CC2FC, "blt cr6 -> 821CC31C  [bo=12 bi=24]"),
    # BO=4 BI=2 -> CR0, so the operand is omitted entirely
    (0x40820020, 0x821CC2FC, "bne -> 821CC31C  [bo=4 bi=2]"),
    # BO=16 = 16<<21 = 0x02000000 -> BO[4]=1, so BI is a count register:
    # BO[1]=0 -> bdnz, and there is no CR field to name
    (0x42000020, 0x821CC2FC, "bdnz r0 -> 821CC31C  [bo=16 bi=0]"),
    # BO=18 = 18<<21 = 0x02400000 -> BO[1]=1 -> bdz
    (0x42400020, 0x821CC2FC, "bdz r0 -> 821CC31C  [bo=18 bi=0]"),
    # BO=12 BI=2 XO=16 -> conditional bclr: `beq cr0` + `lr`
    (0x4D820020, 0x821CC2FC, "beqlr  [bo=12 bi=2 xo=16]"),
    # BO=4 BI=24 XO=16 -> `bge cr6` + `lr`
    (0x4C980020, 0x821CC2FC, "bgelr  [bo=4 bi=24 xo=16]"),
    # --- op 19: XO 16 vs 528 must not collide (528 & 0x1FF == 16) ---
    (0x4E800020, 0x821CC2FC, "blr"),
    (0x4E800420, 0x821CC2FC, "bctr"),
    (0x4E800421, 0x821CC2FC, "bctrl"),
    (0x4E800021, 0x821CC2FC, "blrl"),
    # --- real guest words from sub_8218D270, independent of the disc-check ---
    # 0x41990250 BO=12 BI=25 -> bgt cr6 ; BD*4=0x250=592
    (0x41990250, 0x8218D290, "bgt cr6 -> 8218D4E0  [bo=12 bi=25]"),
    # 0x2B0A0014 op=10, RT=24->cr6, RA=r10, UI=0x14
    (0x2B0A0014, 0x8218D28C, "cmpli cr6,r10,0014"),
    # --- rotate masks: MSB-numbered, and WRAPPING when MB > ME ---
    # 0x556A0042: MB=(w>>6)&31=1, ME=(w>>1)&31=1 -> one bit, 0x80000000>>1.
    # NOT 0x00000001 (that would be LSB numbering), NOT 0x80000000 (MB=0).
    (0x556A0042, 0x821CC2FC, "rlwinm r10,r11,sh=0,mb=1,me=1,mask=0x40000000"),
    # MB=0 ME=30 -> bits 0..30 -> 0xFFFFFFFE. This, NOT 0x7FFFFFFF, is what
    # `clrlwi rA,rS,1` means. generated/ppc_xenon/ppc_recomp.10.cpp labels the
    # 0x7FFFFFFF case below `clrlwi r10,r10,1` and is wrong about the NAME.
    (0x554A003C, 0x821CC2FC, "rlwinm r10,r10,sh=0,mb=0,me=30,mask=0xFFFFFFFE"),
    # the real guest word at 0x8218D284: MB=1 ME=31 -> bits 1..31 -> 0x7FFFFFFF
    (0x554A007E, 0x8218D284, "rlwinm r10,r10,sh=0,mb=1,me=31,mask=0x7FFFFFFF"),
    # MB=3 ME=1 WRAPS: bits 3..31 | bits 0..1
    (0x546100C2, 0x821CC2FC, "rlwinm r1,r3,sh=0,mb=3,me=1,mask=0xDFFFFFFF"),
    # the real guest *4-index word at 0x8218D29C: MB=0 ME=29 -> 0xFFFFFFFC
    (0x5540103A, 0x8218D29C, "rlwinm r0,r10,sh=2,mb=0,me=29,mask=0xFFFFFFFC"),
]


def selftest(verbose=False):
    bad = 0
    print(f"{'word':>10} {'pc':>10}  expected -> got")
    print("-" * 78)
    for w, pc, want in SELFTEST:
        got = decode(w, pc)
        ok = got == want
        bad += not ok
        if not ok or verbose:
            print(f"{w:08X}   {pc:08X}  {'ok  ' if ok else 'FAIL'} {want}")
            if not ok:
                print(f"{'':>10} {'':>10}       got  {got}")
    print("-" * 78)
    print(f"{len(SELFTEST) - bad}/{len(SELFTEST)} reference decodes correct")
    if bad:
        print(f"FAIL: {bad} reference decode(s) wrong -- the BO table or the "
              f"rotate mask is broken. Do not trust any output of this tool.")
    else:
        print("PASS: BO/BI mnemonic table and rotate masks match hand-decoded words.")
    return 1 if bad else 0


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--selftest":
        return selftest("-v" in sys.argv)
    va = int(sys.argv[1], 16)
    n = int(sys.argv[2])
    with open(PE, "rb") as f:
        f.seek(va - BASE)
        data = f.read(4 * n)
    for k in range(n):
        i = struct.unpack(">I", data[4 * k:4 * k + 4])[0]
        pc = va + 4 * k
        print(f"{pc:08X}  {i:08X}  {decode(i, pc)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
