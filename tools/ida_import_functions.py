"""Import XenonRecomp's ground-truth function map into the IDA database.

Reads ida_funcs.txt (ADDR NAME per line, from ppc_func_mapping.cpp) and:
  1. creates a function at every exact address (ida_funcs.add)
  2. names it sub_XXXXXXXX (set_name, force)
  3. re-runs auto-analysis, saves the DB (idb stays in build/cache/)

This eliminates F-023 (IDA guessing wrong function starts on the raw bin).

Run INSIDE the idalib venv python (the server process must be STOPPED first
- idalib allows only one database handle):
  idamcp-venv/Scripts/python.exe ida_import_functions.py
"""
import idapro
import ida_auto
import ida_funcs
import ida_name
import ida_kernwin

FUNC_FILE = r"C:\Users\abdul\AppData\Local\Temp\opencode\ida_funcs.txt"
INPUT = r"E:\mcla pc\build\cache\mcla_pe.bin"


def main() -> int:
    if idapro.open_database(INPUT, run_auto_analysis=False):
        print("open failed")
        return 1

    pairs = []
    with open(FUNC_FILE) as f:
        for line in f:
            parts = line.split()
            if len(parts) == 2:
                pairs.append((int(parts[0], 16), parts[1]))
    print(f"loaded {len(pairs)} mappings")

    made = renamed = 0
    for addr, name in pairs:
        if ida_funcs.get_func(addr) is None:
            if ida_funcs.add_func(addr):
                made += 1
        if ida_name.set_name(addr, name, ida_name.SN_FORCE):
            renamed += 1
    print(f"created {made} functions, named {renamed}")

    ida_auto.auto_make_code(0x82130000)  # nudge code analysis at .text base
    ida_auto.auto_wait()
    idapro.close_database()
    print("database saved")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
