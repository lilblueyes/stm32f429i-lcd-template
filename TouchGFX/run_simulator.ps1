$ErrorActionPreference = "Stop"

$touchgfxRoot = $PSScriptRoot
$candidates = @(
    (Join-Path $touchgfxRoot "build\Debug\bin\Application.exe"),
    (Join-Path $touchgfxRoot "build\Release\bin\Application.exe")
)

$simulatorExe = $candidates | Where-Object { Test-Path $_ } | Select-Object -First 1

if (-not $simulatorExe) {
    throw "Simulator executable not found. Build the simulator first."
}

Start-Process -FilePath $simulatorExe -WorkingDirectory (Split-Path $simulatorExe -Parent)
