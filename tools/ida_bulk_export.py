"""Bulk-export the guest image's MAP from the running IDA MCP bridge.

RULE 0 (AGENTS.md, 2026-09-30): a guest fact must come from a tool, never from inference.
Run this once and you have the whole binary's index on disk, so nobody has to guess
whether a function exists, what an address is, or which host APIs the game imports.

    python tools/ida_bulk_export.py <out_dir>              # the map (fast, do this first)
    python tools/ida_bulk_export.py <out_dir> --decompile  # + every function's pseudocode (slow)

Requires idalib-mcp.exe listening on http://127.0.0.1:8745/mcp. Base 0x82000000.

Why these five and not just "decompile everything":

  functions_index.txt  every function IDA knows, with address/name/size. Answers
                       "does this function exist and where" without guessing an address.
  imports.txt          THE HOST SPEC. Every kernel API the guest imports. This is the
                       contract our import layer must satisfy -- read it, do not infer it.
  strings_index.txt    every string literal with its address. Answers "which function
                       emits this message" and finds the message a marker refers to.
  entry_points.txt     the real entry point, so "does the boot reach it" is measurable.
  xrefs_to_<addr>.txt  for any address you care about. NOTE: "CALLERS (none)" in
                       ida_dump.py output is a CARVING ARTIFACT, not evidence. This uses
                       get_xrefs_to and is the authority for that question.

--decompile walks every function and writes one file each, with RAW BYTES beside the
pseudocode. It is slow and RESUMABLE: it skips files that already exist, so it is safe
to kill and restart. Agents should read these files rather than calling the bridge
per-function -- a hundred agents on one database will just queue behind each other.
"""
import json
import os
import sys
import time

import requests

ENDPOINT = "http://127.0.0.1:8745/mcp"
BASE_HEADERS = {"Content-Type": "application/json",
                "Accept": "application/json, text/event-stream"}
PROTOCOL = "2024-11-05"


def parse_envelope(raw):
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


def handshake(timeout=60):
    r = requests.post(ENDPOINT, headers=BASE_HEADERS, timeout=timeout, json={
        "jsonrpc": "2.0", "id": 1, "method": "initialize",
        "params": {"protocolVersion": PROTOCOL, "capabilities": {},
                   "clientInfo": {"name": "ida_bulk_export", "version": "1"}}})
    sid = r.headers.get("mcp-session-id") or r.headers.get("Mcp-Session-Id")
    if not sid:
        raise SystemExit("no mcp-session-id header -- is idalib-mcp.exe on 127.0.0.1:8745?\n"
                         "Do NOT run ida-bridge.py as well; it taskkills idalib-mcp.exe.")
    h = dict(BASE_HEADERS)
    h["mcp-session-id"] = sid
    requests.post(ENDPOINT, headers=h, timeout=timeout,
                  json={"jsonrpc": "2.0", "method": "notifications/initialized"})
    return h


def rpc(h, ident, tool, args, timeout=300):
    r = requests.post(ENDPOINT, headers=h, timeout=timeout, json={
        "jsonrpc": "2.0", "id": ident, "method": "tools/call",
        "params": {"name": tool, "arguments": args}})
    env = parse_envelope(r.text)
    if not env:
        return ""
    content = env.get("result", {}).get("content")
    if isinstance(content, list):
        return "\n".join(x.get("text", "") for x in content)
    return json.dumps(env)[:4000]


def write(path, text):
    with open(path, "w", encoding="utf-8", errors="replace") as fh:
        fh.write(text)
    n = text.count("\n") + 1
    print("  %-24s %7d lines  %9d bytes" % (os.path.basename(path), n, len(text)))
    return n


def check_raw(raw, addr):
    """Refuse to file a raw-byte block that is actually a tool error.

    The old `regions` argument shape made read_memory_bytes fail on every call,
    and the error text was written into the file under a header that says
    "authoritative" -- all 20,530 of the first run's dumps. A raw block that is
    not bytes is worse than a missing one, so mark it unmistakably.
    """
    if not raw:
        return "(not read)"
    if raw.lstrip().startswith("Error executing tool") or raw.lstrip().startswith("Error:"):
        return ("!! RAW BYTES FAILED AT %s -- this file has NO authoritative bytes.\n"
                "!! %s" % (addr, raw.strip()[:500]))
    return raw


def paged(h, tool, page_size, ident0=100, extra=None):
    """Pull pages until one comes back short, and return the merged `data` array.

    The list_* tools take `offset` and `count` (MEASURED 09-30 from the tool's own
    pydantic validation error -- not guessed). `limit` is rejected outright.

    Each page is pretty-printed JSON `{"data": [...]}`. PARSE IT -- do not split on
    tokens: the fields carry a trailing `",` and a naive tokeniser silently extracts
    zero records while the output file still looks full (measured 09-30).
    """
    records, page, ident = [], 0, ident0
    while True:
        args = {"offset": page * page_size, "count": page_size}
        if extra:
            args.update(extra)
        chunk = rpc(h, ident, tool, args)
        ident += 1
        if not chunk.strip():
            break
        if chunk.lstrip().startswith("Error executing tool"):
            raise SystemExit("%s rejected args %r:\n%s" % (tool, args, chunk[:400]))
        try:
            batch = json.loads(chunk).get("data") or []
        except Exception:
            # Not JSON: keep it rather than losing it silently.
            records.append({"_raw": chunk})
            break
        records.extend(batch)
        if len(batch) < page_size:
            break
        page += 1
        if page > 4000:
            break
    return records


def main():
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    out_dir = sys.argv[1]
    want_decompile = "--decompile" in sys.argv
    os.makedirs(out_dir, exist_ok=True)
    h = handshake()
    print("handshake ok -> %s" % out_dir)

    # ---- the map -----------------------------------------------------------
    write(os.path.join(out_dir, "imports.txt"),
          "=== GUEST IMPORTS = the host contract. Our import layer must satisfy every one.\n"
          "=== This is the spec; do not infer which APIs the game needs.\n"
          "=== (generated by tools/ida_bulk_export.py)\n\n"
          + json.dumps(paged(h, "list_imports", 1000, ident0=10), indent=1))

    write(os.path.join(out_dir, "entry_points.txt"),
          "=== ENTRY POINTS (generated by tools/ida_bulk_export.py) ===\n\n"
          + (rpc(h, 11, "get_entry_points", {}) or "(none)"))

    write(os.path.join(out_dir, "metadata.txt"),
          "=== IMAGE METADATA (generated by tools/ida_bulk_export.py) ===\n"
          "=== Base 0x82000000; raw-byte rule: offset = VA - 0x82000000 in mcla_pe.bin\n\n"
          + (rpc(h, 12, "get_metadata", {}) or "(none)"))

    write(os.path.join(out_dir, "functions_index.txt"),
          "=== FUNCTION INDEX (generated by tools/ida_bulk_export.py) ===\n"
          "=== 'does this function exist, and at what address' is answered here.\n\n"
          + json.dumps(paged(h, "list_functions", 1000, ident0=20), indent=1))

    write(os.path.join(out_dir, "strings_index.txt"),
          "=== STRING INDEX (generated by tools/ida_bulk_export.py) ===\n"
          "=== Use this to find which function emits a log message you are chasing.\n\n"
          + json.dumps(paged(h, "list_strings", 1000, ident0=21), indent=1))

    if not want_decompile:
        print("\nmap written. For pseudocode use tools/ida_dump.py <dir> 0xADDR ...\n"
              "or re-run with --decompile for every function (slow, resumable).")
        return

    # ---- pseudocode, resumable --------------------------------------------
    fn_dir = os.path.join(out_dir, "functions")
    os.makedirs(fn_dir, exist_ok=True)
    idx = paged(h, "list_functions", 100000, ident0=200)
    addrs = []
    for rec in idx:
        a = rec.get("address")
        if not a:
            continue
        try:
            v = int(str(a), 16)
        except ValueError:
            continue
        if 0x82000000 <= v < 0x83000000:
            addrs.append(v)
    addrs = sorted(set(addrs))
    print("\ndecompiling %d functions (resumable)..." % len(addrs))

    ident, done, skipped, t0 = 300, 0, 0, time.time()
    for n, a in enumerate(addrs):
        hexa = "0x%08X" % a
        path = os.path.join(fn_dir, "%08X.txt" % a)
        if os.path.exists(path) and os.path.getsize(path) > 0:
            skipped += 1
            continue
        body = rpc(h, ident, "decompile_function", {"address": hexa})
        # FLAT schema, MEASURED 09-30 from the tool's own validation error: the
        # array form {"regions":[{"addr":..,"size":..}]} this used to send is
        # rejected on every call ("memory_address Field required" / "size Field
        # required"), which is why every dump of the first run has an error string
        # under a header claiming the bytes are authoritative.
        raw = rpc(h, ident + 1, "read_memory_bytes",
                  {"memory_address": hexa, "size": 256})
        raw = check_raw(raw, hexa)
        ident += 2
        with open(path, "w", encoding="utf-8", errors="replace") as fh:
            fh.write("/* %s   raw offset 0x%X in build/cache/mcla_pe.bin */\n\n" % (hexa, a - 0x82000000))
            fh.write("=== RAW BYTES (authoritative for any rotate-immediate mask) ===\n%s\n\n"
                     % (raw or "(not read)"))
            fh.write("=== PSEUDOCODE (a model, not a proof) ===\n%s\n" % body)
        done += 1
        if done % 100 == 0:
            el = time.time() - t0
            rate = done / el if el else 0
            left = (len(addrs) - n - 1) / rate if rate else 0
            print("  %5d/%d  %.1f fn/s  ~%.0f min left" % (n + 1, len(addrs), rate, left / 60.0))
    print("done: %d written, %d already present -> %s" % (done, skipped, fn_dir))


if __name__ == "__main__":
    main()
