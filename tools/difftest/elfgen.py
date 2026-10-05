"""Emit a big-endian ELF32 PowerPC object from raw machine words.

Upstream XenonRecomp ships a differential-test entry point we can use without
building anything: `XenonRecomp.exe <srcDir> <dstDir>` falls into
`TestRecompiler::RecompileTests` (test_recompiler.cpp:35) whenever <srcDir> is
a *directory* rather than a TOML file.  It scans the `.o` files in that
directory with `Image::ParseImage` -> `ElfLoadImage`
(.research/XenonRecomp/XenonUtils/image.cpp:46), finds function starts, runs the
real translator over each, emits `<stem>.cpp` plus a `main.cpp` driver that
reads the `#_ REGISTER_IN` / `#_ REGISTER_OUT` annotations from `../<stem>.s`,
and checks the results.  That is exactly the harness shape we want, and the
binary is already built at
.research/XenonRecomp/build-clang/XenonRecomp/XenonRecomp.exe.

We have to hand it an ELF, because the one upstream uses is produced by a
custom binutils build that is not in this tree (and there is no working web
access to fetch one, and this clang has no PowerPC backend -- verified:
`clang --target=powerpc-unknown-linux-gnu` -> "unknown target triple").

Everything semantic comes from the corpus: this file only lays out a container
format.  The instruction words are lifted verbatim from Xenia's own `.s`
files (see corpus.py -- a word we cannot lift verbatim is a test we skip).
"""

from __future__ import annotations

import struct

# ELF32 constants, from the System V gABI (identical to the structs XenonUtils
# ships in XenonUtils/elf.h).
ET_EXEC = 2
EM_PPC = 20
EV_CURRENT = 1
PT_LOAD = 1
SHT_NULL = 0
SHT_PROGBITS = 1
SHT_STRTAB = 3
SHF_ALLOC = 0x2
SHF_EXECINSTR = 0x4
PF_R = 0x4
PF_X = 0x1
EHDR_SIZE = 52
PHDR_SIZE = 32
SHDR_SIZE = 40

# ElfLoadImage() asserts EI_DATA == 2 (ELFDATA2MSB) and ByteSwap()es every
# multi-byte header field, so the *headers* must be big-endian while the .text
# payload stays raw big-endian PowerPC words.  That is what we emit.
EIDATA_MSB = 2


def build_elf(words, load_vaddr: int = 0) -> bytes:
    """Serialise `words` (a list of 32-bit PPC words) into an ELF32 MSB object.

    Layout: ehdr | 1 phdr (PT_LOAD) | 3 shdr (null, .text, .shstrtab) | .text | .shstrtab
    The section addresses are relative to the first PT_LOAD p_vaddr, so
    load_vaddr=0 makes TestRecompiler's function bases equal their .text offsets
    -- which is what its `address &= 0xFFFFF` disassembly lookup expects.
    """
    text = b"".join(struct.pack(">I", w & 0xFFFFFFFF) for w in words)

    shstrtab = b"\x00.text\x00.shstrtab\x00"
    name_text = shstrtab.index(b".text")
    name_shstrtab = shstrtab.index(b".shstrtab")

    ehdr_size = EHDR_SIZE
    phoff = ehdr_size
    shoff = phoff + PHDR_SIZE
    text_off = shoff + 3 * SHDR_SIZE
    shstrtab_off = text_off + len(text)

    ehdr = struct.pack(
        ">16sHHIIIIIHHHHHH",
        bytes([0x7F]) + b"ELF" + bytes([1, EIDATA_MSB, 1, 0, 0]) + bytes(8),  # e_ident
        ET_EXEC, EM_PPC, EV_CURRENT,
        load_vaddr,          # e_entry
        phoff,               # e_phoff
        shoff,               # e_shoff
        0,                   # e_flags
        ehdr_size, PHDR_SIZE, 1,          # e_ehsize, e_phentsize, e_phnum
        SHDR_SIZE, 3, 2,     # e_shentsize, e_shnum, e_shstrndx
    )
    assert len(ehdr) == EHDR_SIZE, len(ehdr)

    phdr = struct.pack(">IIIIIIII", PT_LOAD, 0, load_vaddr, load_vaddr,
                       len(text), len(text), PF_R | PF_X, 4)

    shdrs = [
        struct.pack(">IIIIIIIIII", 0, SHT_NULL, 0, 0, 0, 0, 0, 0, 0, 0),
        struct.pack(">IIIIIIIIII", name_text, SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR,
                    load_vaddr, text_off, len(text), 0, 0, 4, 0),
        struct.pack(">IIIIIIIIII", name_shstrtab, SHT_STRTAB, 0,
                    0, shstrtab_off, len(shstrtab), 0, 0, 1, 0),
    ]

    return ehdr + phdr + b"".join(shdrs) + text + shstrtab


def build_dis(entries) -> str:
    """Emit the `.dis` sidecar TestRecompiler reads to map labels to symbols.

    test_recompiler.cpp:80-97 parses each line as
        addr = from_chars(line[0 .. first_space], 16) & 0xFFFFF
        name = line.substr(first_space + 2, first_'>' - first_space - 2)
    so the line must be `%08X` + two spaces + <label> immediately followed by
    '<'.  The trailing "<label>" is padding to satisfy the fixed-width substr;
    the tool only reads the width, not the contents.
    """
    out = []
    for addr, label in entries:
        out.append("%08X  %s<%s>" % (addr, label, label))
    return "\n".join(out) + "\n"
