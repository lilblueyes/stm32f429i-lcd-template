@echo off
setlocal

for /r ..\Debug %%F in (*.mk) do (
  powershell -NoProfile -ExecutionPolicy Bypass -Command "(Get-Content '%%F') -replace ' -fcyclomatic-complexity','' | Set-Content '%%F'"
)

make -C ../Debug -j8 all
exit /b %errorlevel%

