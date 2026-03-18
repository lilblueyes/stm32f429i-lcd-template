# STM32F429I LCD Template

Template STM32CubeIDE + TouchGFX for the `STM32F429I-DISCO` board.

This repository is meant to be a clean starting point for projects targeting:
- the STM32F429ZI MCU
- the onboard 240x320 LCD
- the STMPE811 touch controller
- FreeRTOS
- TouchGFX

The current demo is intentionally simple:
- a single TouchGFX screen
- two buttons to turn the user LEDs on and off
- a background color change to confirm touch input

## What Is Included

- STM32CubeIDE project files
- CubeMX configuration in [`stm32f429i-lcd-template.ioc`](./stm32f429i-lcd-template.ioc)
- TouchGFX project in [`TouchGFX/stm32f429i-lcd-template.touchgfx`](./TouchGFX/stm32f429i-lcd-template.touchgfx)
- HAL, CMSIS, FreeRTOS, BSP, and TouchGFX sources needed to rebuild the project

## What Is Not Versioned

The repository ignores local or generated artifacts such as:
- `.metadata/`
- `.settings/`
- `Debug/` and `Release/`
- TouchGFX build caches
- local backup files

If those folders/files reappear locally, they should stay untracked.

## Requirements

Tested with:
- STM32CubeIDE 1.16.1
- STM32CubeProgrammer 2.18.0
- STM32CubeCLT 1.17.0

On Windows, the provided scripts try to find STM32CubeIDE and STM32CubeProgrammer automatically under `C:\ST`.

## Build

From TouchGFX Designer, use the configured target build command.

From a terminal:

```powershell
PowerShell -NoProfile -ExecutionPolicy Bypass -File .\TouchGFX\compile_target.ps1
```

The script prefers a headless STM32CubeIDE build. If CubeIDE is not found but `make` and a generated `Debug/makefile` are available, it falls back to `make`.

## Flash

From a terminal:

```powershell
PowerShell -NoProfile -ExecutionPolicy Bypass -File .\TouchGFX\flash_target.ps1
```

The flash script programs `Debug\stm32f429i-lcd-template.elf` over ST-LINK/SWD.

## Notes

- The board support in this template is specific to `STM32F429I-DISCO`.
- The project keeps TouchGFX simulator files because they are useful during UI work on Windows.
- If you regenerate code from CubeMX or TouchGFX, ignored local build artifacts may be recreated. That is expected.
