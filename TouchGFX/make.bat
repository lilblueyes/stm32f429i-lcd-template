@echo off
setlocal

set "MAKE_EXE=C:\TouchGFX\4.24.2\env\MinGW\msys\1.0\bin\make.exe"
set "MINGW_BIN=C:\TouchGFX\4.24.2\env\MinGW\bin"
set "MSYS_BIN=C:\TouchGFX\4.24.2\env\MinGW\msys\1.0\bin"
set "RUBY_BIN=C:\TouchGFX\4.24.2\env\MinGW\msys\1.0\Ruby30-x64\bin"

if not exist "%MAKE_EXE%" (
  echo TouchGFX make.exe not found at "%MAKE_EXE%".
  exit /b 1
)

set "PATH=%MINGW_BIN%;%MSYS_BIN%;%RUBY_BIN%;%PATH%"
"%MAKE_EXE%" %*
exit /b %errorlevel%
