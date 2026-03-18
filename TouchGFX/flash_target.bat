@echo off
setlocal

powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0flash_target.ps1"
exit /b %errorlevel%
