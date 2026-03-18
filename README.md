# STM32F429I-DISCO + TouchGFX

Base de projet pour `STM32F429I-DISCO` avec :
- `STM32CubeIDE`
- `TouchGFX`
- `FreeRTOS`
- écran LCD 240x320
- tactile `STMPE811`

Le projet démarre sur un splash screen puis ouvre un écran simple avec deux boutons pour piloter les LED utilisateur.

## Contenu

- projet `STM32CubeIDE`
- configuration CubeMX dans [stm32f429i-lcd-template.ioc](/c:/Users/Jocelyn/Documents/GitHub/stm32f429i-lcd-template/stm32f429i-lcd-template.ioc)
- projet TouchGFX dans [stm32f429i-lcd-template.touchgfx](/c:/Users/Jocelyn/Documents/GitHub/stm32f429i-lcd-template/TouchGFX/stm32f429i-lcd-template.touchgfx)
- sources `HAL`, `CMSIS`, `FreeRTOS`, `BSP` et `TouchGFX`

## Environnement utilisé pour les tests

Ce dépôt a été vérifié avec :
- `Windows 10 Home`, build `26200`
- `STM32CubeMX 6.12.0`
- `STM32CubeIDE 1.16.1`
- `STM32CubeProgrammer 2.18.0`
- `STM32CubeCLT 1.17.0`
- `TouchGFX 4.24.2`
- `FreeRTOS 10.3.1`

Version indiquée par le projet TouchGFX :
- projet : `4.24.2`
- création initiale : `4.24.1`

Ce sont les versions avec lesquelles le projet a été testé ici, pas des versions imposées.

## Carte cible

- carte : `STM32F429I-DISCO`
- MCU : `STM32F429ZITx`
- écran : `240x320`
- tactile : `STMPE811`

## Compilation cible

Depuis `TouchGFX Designer`, la commande cible est déjà configurée.

Depuis un terminal :

```powershell
PowerShell -NoProfile -ExecutionPolicy Bypass -File .\TouchGFX\compile_target.ps1
```

Le script essaie d'abord un build headless via `STM32CubeIDE`. Si `CubeIDE` n'est pas trouvé, il utilise `make` si le projet a déjà été généré.

## Flash

```powershell
PowerShell -NoProfile -ExecutionPolicy Bypass -File .\TouchGFX\flash_target.ps1
```

Le flash se fait sur `Debug\stm32f429i-lcd-template.elf` via `ST-LINK/SWD`.

## Simulateur

```powershell
PowerShell -NoProfile -ExecutionPolicy Bypass -File .\TouchGFX\compile_simulator.ps1
```

Les fichiers du simulateur sont conservés dans le dépôt pour travailler l'interface sous Windows.

## Notes

- Le support matériel est spécifique à `STM32F429I-DISCO`.
- Une régénération depuis `CubeMX` ou `TouchGFX Designer` recrée des fichiers générés, ce qui est normal.
- La transition du splash est gérée côté code utilisateur pour ne pas casser après un `Generate` TouchGFX.
