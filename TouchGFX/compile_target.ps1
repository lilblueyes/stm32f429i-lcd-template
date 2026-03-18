$ErrorActionPreference = "Stop"

Get-ChildItem ..\Debug -Recurse -Filter *.mk | ForEach-Object {
    (Get-Content $_.FullName) -replace ' -fcyclomatic-complexity', '' | Set-Content $_.FullName
}

& make -C ../Debug -j8 all
exit $LASTEXITCODE

