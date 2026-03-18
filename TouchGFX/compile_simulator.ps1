$ErrorActionPreference = "Stop"

$touchgfxRoot = $PSScriptRoot
$solutionPath = Join-Path $touchgfxRoot "simulator\msvs\Application.sln"

function Find-MSBuild {
    $command = Get-Command MSBuild.exe -ErrorAction SilentlyContinue
    if ($command) {
        return $command.Source
    }

    $candidates = @(
        "C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe",
        "C:\Program Files\Microsoft Visual Studio\2022\Professional\MSBuild\Current\Bin\MSBuild.exe",
        "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\MSBuild\Current\Bin\MSBuild.exe",
        "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe",
        "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\MSBuild\Current\Bin\MSBuild.exe",
        "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\MSBuild\Current\Bin\MSBuild.exe"
    )

    foreach ($candidate in $candidates) {
        if (Test-Path $candidate) {
            return $candidate
        }
    }

    throw "MSBuild.exe not found. Install Visual Studio Build Tools or Visual Studio with C++ support."
}

function Find-TouchGfxPaths {
    $roots = @(
        "C:\TouchGFX\4.24.2\touchgfx",
        "C:\Programmes Files\STM32 TOUCHGFX\en.x-cube-touchgfx-4.24.2\Projects\STM32F746G-DISCO\Applications\DynamicGraph\Middlewares\ST\touchgfx",
        "C:\Programmes Files\STM32 TOUCHGFX\en.x-cube-touchgfx.4.24.1\Projects\STM32F746G-DISCO\Applications\DynamicGraph\Middlewares\ST\touchgfx"
    )

    foreach ($root in $roots) {
        $imageConvert = Join-Path $root "framework\tools\imageconvert\build\msvs\ImageConvert.exe"
        if (Test-Path $imageConvert) {
            return @{
                ReleasePath = $root
                EnvPath = Join-Path (Split-Path $root -Parent) "env"
            }
        }
    }

    throw "TouchGFX simulator tools not found. Install TouchGFX 4.24.x locally."
}

if (-not (Test-Path $solutionPath)) {
    throw "Simulator solution not found at $solutionPath."
}

$msbuild = Find-MSBuild
$touchgfxPaths = Find-TouchGfxPaths

& $msbuild $solutionPath /m /t:Build /p:Configuration=Debug /p:Platform=Win32 /p:PlatformToolset=v143 /p:WindowsTargetPlatformVersion=10.0.22621.0 /p:TouchGFXReleasePath=$($touchgfxPaths.ReleasePath) /p:TouchGFXEnvPath=$($touchgfxPaths.EnvPath)
exit $LASTEXITCODE
