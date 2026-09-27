"""Client for the local IDA idalib server (headless decompiler / xrefs).

Three things about this endpoint cost real time repeatedly. All three are encoded
here, which is why this file exists in two revisions (F-350 audit):

1. Start it against the RAW GUEST IMAGE, not the .xex.
   `idalib-mcp.exe "build\\game_data\\default.xex"` dies with
   `RuntimeError: failed to analyze input file`. The working database is
   `build/cache/mcla_pe.bin` (per `get_metadata`: base 0x82000000, size 0xad3000):

     "C:/Users/abdul/.local/share/mcp/idamcp-venv/Scripts/idalib-mcp.exe" \
         -v "E:/mcla pc/build/cache/mcla_pe.bin"

   Check first: `tasklist | grep -i idalib`. If a server is already listening,
   ATTACH — never run ida-bridge.py in that case; its `taskkill /F /IM
   idalib-mcp.exe` destroys another session's database (rule 11).

2. The request must advertise BOTH media types. Without
   `Accept: application/json, text/event-stream` the server answers
   `406 Not Acceptable`, including for `tools/call` routed through the stdio
   proxy — `ida-pro-mcp.exe --transport stdio` forwards without that header (its
   `tools/list` succeeds, so it looks alive); NOT a workaround — use this module.

3. The JSON-RPC result does not arrive in the HTTP body's first bytes; it is
   streamed as server-sent events on the same response. A client that calls
   `read()` gets an empty string and concludes IDA is broken. Read lines until a
   `data:` payload appears (implemented below).

Usage:
  python tools/ida_rpc.py list
  python tools/ida_rpc.py call get_metadata
  python tools/ida_rpc.py call decompile_function '{"address":"0x821BC140"}'
  python tools/ida_rpc.py call get_xrefs_to      '{"address":"0x82461378"}'

Remember docs/PROGRAM_GUIDE.md §4/§10: an IDA xref list is a hypothesis until the
raw words at build/cache/mcla_pe.bin (offset = VA - 0x82000000, big-endian) agree,
and generated/ppc_xenon/*.cpp is ground truth for function bodies.
"""
import json
import sys
import urllib.error
import urllib.request

URL = "http://127.0.0.1:8745/mcp"
PROTOCOL = "2024-11-05"
# Accept must carry both media types; see point 2 in the module docstring.
BASE_HEADERS = {"Content-Type": "application/json",
                "Accept": "application/json, text/event-stream"}


def _rpc(method, params, session=None, rpc_id=None, timeout=180):
    payload = {"jsonrpc": "2.0", "method": method, "params": params}
    if rpc_id is not None:
        payload["id"] = rpc_id
    headers = dict(BASE_HEADERS)
    if session:
        headers["Mcp-Session-Id"] = session
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(),
                                 headers=headers)
    try:
        resp = urllib.request.urlopen(req, timeout=timeout)
    except urllib.error.HTTPError as exc:
        raise SystemExit("HTTP %s: %s" % (exc.code, exc.read()[:300]))
    except OSError as exc:
        raise SystemExit(
            "cannot reach %s (%s)\nStart the server (see this file's docstring),"
            " then check `tasklist | grep -i idalib`." % (URL, exc))
    sid = resp.headers.get("Mcp-Session-Id") or session
    if rpc_id is None:          # notification: no body to wait for
        resp.read()
        return sid, None
    data = None
    while True:                 # the answer arrives on the SSE stream
        line = resp.readline()
        if not line:
            break
        text = line.decode("utf-8", "replace").strip()
        if text.startswith("data:"):
            chunk = text[len("data:"):].strip()
            if chunk:
                data = chunk
                break
    resp.close()
    if data is None:
        raise SystemExit(
            "no SSE payload from the IDA server. Is analysis finished? Retry in "
            "a moment; a 10 MB PPC image takes a few minutes to open.")
    msg = json.loads(data)
    if "error" in msg:
        raise SystemExit("%s failed: %s" % (method, msg["error"]))
    return sid, msg.get("result")


class Client:
    def __init__(self):
        self.sid, _ = _rpc("initialize", {
            "protocolVersion": PROTOCOL, "capabilities": {},
            "clientInfo": {"name": "ida_rpc.py", "version": "3"}}, rpc_id=1)
        _rpc("notifications/initialized", {}, self.sid)

    def tools(self):
        return _rpc("tools/list", {}, self.sid, rpc_id=2)[1].get("tools", [])

    def call(self, name, arguments):
        res = _rpc("tools/call", {"name": name, "arguments": arguments},
                   self.sid, rpc_id=3)[1]
        if res.get("isError"):
            raise SystemExit("tool error: %s" % res.get("content"))
        texts = [c.get("text", "") for c in res.get("content", [])
                 if c.get("type") == "text"]
        out = res.get("structuredContent")
        if out is not None:
            return out
        if len(texts) == 1:
            try:
                return json.loads(texts[0])
            except json.JSONDecodeError:
                return texts[0]
        return texts


def main(argv):
    if len(argv) < 2 or argv[1] in ("-h", "--help"):
        print(__doc__)
        return 1
    client = Client()
    if argv[1] == "list":
        tools = client.tools()
        print("%d tools" % len(tools))
        for t in tools:
            print("  %s" % t["name"])
        return 0
    if argv[1] == "call":
        if len(argv) < 3:
            print("call needs a tool name", file=sys.stderr)
            return 1
        args = {}
        if len(argv) > 3:
            try:
                args = json.loads(argv[3])
            except json.JSONDecodeError:
                print("arguments must be a JSON object", file=sys.stderr)
                return 1
        out = client.call(argv[2], args)
        print(json.dumps(out, indent=1) if isinstance(out, (dict, list))
              else out)
        return 0
    print("unknown command %r (use list|call)" % argv[1], file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
