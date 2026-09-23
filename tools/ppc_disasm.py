"""Tiny PPC32 big-endian disassembler for hand-picked windows from
mcla_pe.bin. Usage: python tools/ppc_disasm.py <hexVA> <nInstructions>
File offset = VA - 0x82000000.
"""
import struct
import sys

PE = "build/cache/mcla_pe.bin"
BASE = 0x82000000


def r(n):
    return f"r{n}"


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


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
    if op == 16:  # bc
        aa = i & 2
        bd = s16(i & 0xFFFC)
        tgt = bd if aa else pc + bd
        return f"bc bo={bo} bi={bi} -> {tgt & 0xFFFFFFFF:08X}" + (" aa" if aa else "") + (" l" if i & 1 else "")
    if op == 18:  # b
        aa = i & 2
        tgt = li if aa else pc + li
        return f"b{'l' if i & 1 else ''} {tgt & 0xFFFFFFFF:08X}" + (" aa" if aa else "")
    if op == 19:
        # 10-bit xo: 528 & 0x1FF == 16, so a 9-bit mask printed bctr/bctrl (a
        # computed CALL) with the same string as blr (a RETURN).
        if xo == 16 or xo == 528:
            _bn = "blr" if xo == 16 else "bctr"
            if i & 1:
                _bn += "l"
            return _bn if bo == 20 else f"{_bn} bo={bo} bi={bi}"
        if xo == 18 or xo == 530:
            return f"bc{'ctr' if xo == 530 else 'lr'} bo={bo} bi={bi}"
        if xo == 17 or xo == 529:
            return f"b{'ctr' if xo == 529 else 'lr'}l bo={bo} bi={bi} aa"
        if xo == 19 or xo == 531:
            return f"b{'ctr' if xo == 531 else 'lr'}la bo={bo} bi={bi} aa"
        if xo9 == 20:
            return "rfi"
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
        if xo == 824:
            return f"sraw {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 792:
            return f"srawi {r(d)},{r(a)},{b}{rc}"
        if xo == 24:
            return f"slw {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 536:
            return f"srw {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 28:
            return f"and {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 444:
            # mr is or with RB == RT; printing a 3-operand or as mr drops RB.
            return f"mr {r(d)},{r(a)}" if d == b else f"or {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 478:
            return f"nand {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 124:
            return f"nor {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 56:
            return f"eqv {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 284:
            return f"orc {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 60:
            return f"andc {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 412:
            return f"orc {r(d)},{r(a)},{r(b)}{rc}"
        if xo == 316:
            return f"xor {r(d)},{r(a)},{r(b)}{rc}"
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
        return f"rlwinm {r(a)},{r(d)},sh={b},mb={mb},me={me}{rc}"
    if op == 23:
        return f"rlwnm {r(a)},{r(d)},{r(b)},mb={mb},me={me}{rc}"
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


def main():
    va = int(sys.argv[1], 16)
    n = int(sys.argv[2])
    with open(PE, "rb") as f:
        f.seek(va - BASE)
        data = f.read(4 * n)
    for k in range(n):
        i = struct.unpack(">I", data[4 * k:4 * k + 4])[0]
        pc = va + 4 * k
        print(f"{pc:08X}  {i:08X}  {decode(i, pc)}")


if __name__ == "__main__":
    main()
