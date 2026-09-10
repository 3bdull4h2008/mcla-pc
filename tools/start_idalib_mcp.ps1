# Start headless IDA JSON-RPC for ida-pro-mcp.exe --ida-rpc http://127.0.0.1:8745
# Usage: powershell -File tools\start_idalib_mcp.ps1
$ErrorActionPreference = "Stop"
$py = "C:\Users\abdul\.local\share\mcp\idamcp-venv\Scripts\python.exe"
$script = "C:\Users\abdul\.local\share\mcp\idamcp-venv\Scripts\idalib_jsonrpc_server.py"
$bin = "E:\mcla pc\build\cache\mcla_pe.bin"
$out = "E:\mcla pc\idalib_mcp_out.log"
$err = "E:\mcla pc\idalib_mcp_err.log"
$port = 8745

# Already listening?
$existing = netstat -ano | Select-String ":$port\s.*LISTENING"
if ($existing) {
    Write-Host "port $port already listening: $existing"
    exit 0
}

$argLine = "`"$script`" --host 127.0.0.1 --port $port `"$bin`""
$p = Start-Process -FilePath $py -ArgumentList $argLine `
    -RedirectStandardOutput $out -RedirectStandardError $err `
    -WindowStyle Hidden -PassThru
Write-Host "started PID $($p.Id); waiting for IDB..."

$deadline = (Get-Date).AddSeconds(120)
while ((Get-Date) -lt $deadline) {
    Start-Sleep -Seconds 3
    if (Test-Path $err) {
        $txt = Get-Content $err -Raw -ErrorAction SilentlyContinue
        if ($txt -match "JSON-RPC ready") {
            Write-Host $txt
            Write-Host "OK: http://127.0.0.1:$port/mcp"
            exit 0
        }
        if ($txt -match "error:|Error|Traceback") {
            Write-Host $txt
            exit 1
        }
    }
    if (-not (Get-Process -Id $p.Id -ErrorAction SilentlyContinue)) {
        Write-Host "process died; log:"
        Get-Content $err -ErrorAction SilentlyContinue
        exit 1
    }
}
Write-Host "timeout waiting for ready; log:"
Get-Content $err -ErrorAction SilentlyContinue
exit 1
