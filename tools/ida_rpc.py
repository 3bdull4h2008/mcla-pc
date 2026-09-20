"""Tiny JSON-RPC client for the local IDA idalib server (port 8745).

Usage:
  python ida_rpc.py <method> [json_params]
  python ida_rpc.py decompile_function '"0x8218AF68"'
"""
import json
import sys
import urllib.request

URL = "http://127.0.0.1:8745/mcp"


def call(method, params):
    body = json.dumps({"jsonrpc": "2.0", "id": 1, "method": method,
                       "params": params}).encode()
    req = urllib.request.Request(URL, data=body,
                                 headers={"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=120) as r:
        out = json.loads(r.read().decode())
    if "error" in out:
        print("ERROR:", out["error"], file=sys.stderr)
        return None
    return out.get("result")


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    method = sys.argv[1]
    params = []
    for a in sys.argv[2:]:
        # Accept raw strings as well as JSON (PowerShell mangles quoting).
        try:
            params.append(json.loads(a))
        except json.JSONDecodeError:
            params.append(a)
    res = call(method, params)
    print(json.dumps(res, indent=1))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
