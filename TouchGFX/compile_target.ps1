$ErrorActionPreference = "Stop"

$projectRoot = Resolve-Path (Join-Path $PSScriptRoot "..")
$projectName = "stm32f429i-lcd-template"
$debugDir = Join-Path $projectRoot "Debug"
$workspaceDir = Join-Path $env:TEMP "$projectName-cubeide-workspace"

function Find-CubeIdeC {
    $command = Get-Command stm32cubeidec.exe -ErrorAction SilentlyContinue
    if ($command) {
        return $command.Source
    }

    $roots = Get-ChildItem "C:\ST" -Directory -Filter "STM32CubeIDE_*" -ErrorAction SilentlyContinue |
        Sort-Object Name -Descending

    foreach ($root in $roots) {
        $candidate = Join-Path $root.FullName "STM32CubeIDE\stm32cubeidec.exe"
        if (Test-Path $candidate) {
            return $candidate
        }
    }

    return $null
}

function Find-MakeExe {
    $command = Get-Command make.exe -ErrorAction SilentlyContinue
    if ($command) {
        return $command.Source
    }

    $roots = Get-ChildItem "C:\ST" -Directory -Filter "STM32CubeIDE_*" -ErrorAction SilentlyContinue |
        Sort-Object Name -Descending

    foreach ($root in $roots) {
        $pluginRoot = Join-Path $root.FullName "STM32CubeIDE\plugins"
        if (-not (Test-Path $pluginRoot)) {
            continue
        }

        $candidate = Get-ChildItem $pluginRoot -Recurse -Filter "make.exe" -ErrorAction SilentlyContinue |
            Select-Object -First 1 -ExpandProperty FullName

        if ($candidate) {
            return $candidate
        }
    }

    return $null
}

$cubeIdeC = Find-CubeIdeC
$makeExe = Find-MakeExe

if ($cubeIdeC) {
    & $cubeIdeC --launcher.suppressErrors -nosplash `
        -application org.eclipse.cdt.managedbuilder.core.headlessbuild `
        -data $workspaceDir `
        -importAll $projectRoot `
        -build "$projectName/Debug"
    exit $LASTEXITCODE
}

if (-not $makeExe) {
    throw "Neither stm32cubeidec.exe nor make.exe could be found."
}

if (-not (Test-Path (Join-Path $debugDir "makefile"))) {
    throw "Debug/makefile not found. Install STM32CubeIDE for headless build support or generate the Makefiles first."
}

Get-ChildItem $debugDir -Recurse -Filter *.mk | ForEach-Object {
    (Get-Content $_.FullName) -replace ' -fcyclomatic-complexity', '' | Set-Content $_.FullName
}

& $makeExe -C $debugDir -j8 all
exit $LASTEXITCODE
