$ErrorActionPreference = "Stop"

$touchgfxRoot = $PSScriptRoot
$envRoot = "C:\TouchGFX\4.24.2\env"
$mingwBin = Join-Path $envRoot "MinGW\bin"
$msysBin = Join-Path $envRoot "MinGW\msys\1.0\bin"
$rubyBin = Join-Path $envRoot "MinGW\msys\1.0\Ruby30-x64\bin"
$makeExe = Join-Path $msysBin "make.exe"

if (-not (Test-Path $makeExe)) {
    throw "TouchGFX MinGW make.exe not found at $makeExe."
}

$env:PATH = "$mingwBin;$msysBin;$rubyBin;$env:PATH"
Set-Location $touchgfxRoot

& $makeExe -f "simulator/gcc/Makefile" -j8
exit $LASTEXITCODE
