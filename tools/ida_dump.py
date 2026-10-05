"""Decompile guest functions from the running IDA MCP bridge.

RULE 0 (AGENTS.md, 2026-09-30): a guest fact must come from a tool, never from inference.
This is the tool. Agents read the FILES it writes -- they do not hammer one IDA database.

    python tools/ida_dump.py <out_dir> 0x821378B8 0x821CCEA0 ...

Requires the bridge:
    idalib-mcp.exe --verbose 'E:\\mcla pc\\build\\game_data\\default.xex'
and it listening on http://127.0.0.1:8745/mcp

Base address is 0x82000000 (matches the raw-byte rule: offset = VA - 0x82000000).

KNOWN TRAPS -- this tool emits them so a reader cannot miss them:

  * Decompiler output is a MODEL. All three decompilers available here render PPC
    rotate-immediate masks BACKWARDS (keep the low bits where the ISA keeps the high
    ones). Raw word 55 6A 00 42 is MB=1, ME=1, i.e. bit 1; IDA and ppc_recomp.17.cpp
    both print 0x40000000. Every dump therefore carries RAW BYTES beside the
    pseudocode. Any mask claim is invalid until you read the raw word.

  * CALLERS/CALLEES come back "(none)" for most functions. That is an IDA carving
    artifact -- only a fraction of guest functions are carved. "(none)" is NOT
    evidence of absence. For real xrefs use tools/ppc_xrefs.py calls <hex>, or
    get_xrefs_to on a code address.

  * If decompile_function returns "local variable allocation has failed", the output
    may be wrong. Fall back to disassemble_function / the raw bytes.
"""
import json
import os
import re
import sys

import requests

ENDPOINT = "http://127.0.0.1:8745/mcp"
BASE_HEADERS = {"Content-Type": "application/json",
                "Accept": "application/json, text/event-stream"}
PROTOCOL = "2024-11-05"


def parse_envelope(raw):
    """The server answers as SSE even for plain JSON-RPC."""
    if not isinstance(raw, str):
        return None
    for line in raw.split("\n"):
        if line.startswith("data: "):
            try:
                return json.loads(line[6:])
            except Exception:
                return None
    try:
        return json.loads(raw)
    except Exception:
        return None


def handshake(timeout=30):
    """The session id comes back in the HTTP RESPONSE HEADER, not the JSON-RPC body.

    That is the single most common way this tool fails ("Missing session ID").
    """
    r = requests.post(ENDPOINT, headers=BASE_HEADERS, timeout=timeout, json={
        "jsonrpc": "2.0", "id": 1, "method": "initialize",
        "params": {"protocolVersion": PROTOCOL, "capabilities": {},
                   "clientInfo": {"name": "ida_dump", "version": "1"}}})
    sid = r.headers.get("mcp-session-id") or r.headers.get("Mcp-Session-Id")
    if not sid:
        raise SystemExit(
            "no mcp-session-id in the response header.\n"
            "  Is idalib-mcp.exe listening on 127.0.0.1:8745?\n"
            "  NOTE: do NOT also run the ida-bridge.py stdio script -- it taskkills\n"
            "  idalib-mcp.exe on start and will destroy a running analysis.")
    h = dict(BASE_HEADERS)
    h["mcp-session-id"] = sid
    requests.post(ENDPOINT, headers=h, timeout=timeout,
                  json={"jsonrpc": "2.0", "method": "notifications/initialized"})
    return h


def rpc(h, ident, tool, args, timeout=180):
    r = requests.post(ENDPOINT, headers=h, timeout=timeout, json={
        "jsonrpc": "2.0", "id": ident, "method": "tools/call",
        "params": {"name": tool, "arguments": args}})
    env = parse_envelope(r.text)
    if not env:
        return "<<no envelope: %s>>" % r.text[:300]
    content = env.get("result", {}).get("content")
    if isinstance(content, list):
        return "\n".join(x.get("text", "") for x in content)
    return json.dumps(env)[:2000]


def normalise(addr):
    return addr if addr.lower().startswith("0x") else "0x" + addr


def check_raw(raw, addr):
    """Refuse to file a raw-byte block that is actually a tool error.

    The old `regions` argument shape made read_memory_bytes fail on every call,
    and the failure text was written into the file as if it were the authoritative
    bytes -- 20,530 dumps ended up carrying `Error executing tool ...` under a
    header that says "authoritative". A raw block that is not bytes is worse than
    a missing one, so surface it loudly instead of silently persisting it.
    """
    if not raw:
        return "(not read)"
    if raw.lstrip().startswith("Error executing tool") or raw.lstrip().startswith("Error:"):
        return ("!! RAW BYTES FAILED AT %s -- this file has NO authoritative bytes.\n"
                "!! %s" % (addr, raw.strip()[:500]))
    return raw


def dump_one(h, ident, addr, out_dir, with_raw=True):
    """Write one function. Returns (path, n_lines, ok)."""
    body = rpc(h, ident, "decompile_function", {"address": addr})
    callers = rpc(h, ident + 1, "get_callers", {"function_address": addr})
    callees = rpc(h, ident + 2, "get_callees", {"function_address": addr})

    raw = ""
    if with_raw:
        # 512 bytes is plenty to check any instruction field by hand.
        #
        # ARG NAMES MEASURED 09-30 from the tool's own pydantic error, not guessed.
        # The schema is FLAT -- memory_address + size. The array form below is what
        # this call used to send and it failed on every single dump:
        #   Error executing tool read_memory_bytes: 2 validation errors for
        #   read_memory_bytesArguments / memory_address Field required /
        #   size Field required [type=missing, input_value={'regions': ...}]
        raw = rpc(h, ident + 3, "read_memory_bytes",
                  {"memory_address": addr, "size": 512})
        raw = check_raw(raw, addr)

    sig = (body.split("(")[0] or "fn").strip()[-40:]
    sig = re.sub(r"[^A-Za-z0-9_]", "_", sig) or "fn"
    path = os.path.join(out_dir, "%s_%s.txt" % (addr[2:].upper(), sig))
    with open(path, "w", encoding="utf-8", errors="replace") as fh:
        fh.write("/* guest address %s   base 0x82000000   raw offset VA-0x82000000 */\n\n" % addr)
        fh.write("=== RAW BYTES (authoritative; decompilers misrender rotate-immediate\n"
                 "=== masks, so verify any mask against these) ===\n%s\n\n" % (raw or "(not read)"))
        fh.write("=== CALLERS ===\n%s\n\n" % (callers or "(none) -- CARVING ARTIFACT, not evidence"))
        fh.write("=== CALLEES ===\n%s\n\n" % (callees or "(none) -- CARVING ARTIFACT, not evidence"))
        fh.write("=== PSEUDOCODE (a model, not a proof) ===\n%s\n" % body)

    n = body.count("\n") + 1
    ok = n > 3 and not body.lstrip().startswith("Error")
    return path, n, ok


def main():
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    out_dir = sys.argv[1]
    addrs = [normalise(a) for a in sys.argv[2:]]
    no_raw = "--no-raw" in addrs
    addrs = [a for a in addrs if not a.startswith("--")]
    if not addrs:
        raise SystemExit(__doc__)

    os.makedirs(out_dir, exist_ok=True)
    h = handshake()
    print("handshake ok; dumping %d function(s) -> %s" % (len(addrs), out_dir))

    good = 0
    for i, addr in enumerate(addrs):
        path, n, ok = dump_one(h, 10 + i * 4, addr, out_dir, with_raw=not no_raw)
        good += 1 if ok else 0
        print("  %-12s %5d lines  %s  %s"
              % (addr, n, "ok" if ok else "EMPTY/ERR", os.path.basename(path)))

    print("\n%d/%d decompiled -> %s" % (good, len(addrs), out_dir))
    if good < len(addrs):
        print("EMPTY usually means the address is not a function head, or the "
              "decompiler failed. Check the raw bytes in the file before concluding.")


if __name__ == "__main__":
    main()
