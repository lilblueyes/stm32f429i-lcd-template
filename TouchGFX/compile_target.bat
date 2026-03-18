@echo off
setlocal

powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0compile_target.ps1"
exit /b %errorlevel%
