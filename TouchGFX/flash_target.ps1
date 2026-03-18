$ErrorActionPreference = "Stop"

$projectRoot = Resolve-Path (Join-Path $PSScriptRoot "..")
$projectName = "stm32f429i-lcd-template"
$elfPath = Join-Path $projectRoot "Debug\$projectName.elf"

function Find-ProgrammerCli {
    $command = Get-Command STM32_Programmer_CLI.exe -ErrorAction SilentlyContinue
    if ($command) {
        return $command.Source
    }

    $roots = Get-ChildItem "C:\ST" -Directory -Filter "STM32CubeCLT_*" -ErrorAction SilentlyContinue |
        Sort-Object Name -Descending

    foreach ($root in $roots) {
        $candidate = Join-Path $root.FullName "STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe"
        if (Test-Path $candidate) {
            return $candidate
        }
    }

    throw "STM32_Programmer_CLI.exe not found. Install STM32CubeProgrammer or add it to PATH."
}

if (-not (Test-Path $elfPath)) {
    throw "ELF not found at $elfPath. Build the project first."
}

$programmerCli = Find-ProgrammerCli

& $programmerCli -c port=SWD mode=UR -hardRst -w $elfPath -v -rst
if ($LASTEXITCODE -ne 0) {
    & $programmerCli -c port=SWD mode=HotPlug freq=4000 -w $elfPath -v -rst
}

exit $LASTEXITCODE
