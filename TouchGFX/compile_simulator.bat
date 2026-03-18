@echo off
setlocal

powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0compile_simulator.ps1"
exit /b %errorlevel%
