@echo off
setlocal EnableDelayedExpansion

:: setup-git-hooks.bat
:: Register git hooks by pointing core.hooksPath to the git-hooks/ directory.
:: This avoids copying files and keeps hooks version-controlled.

:: Get repository root
for /f "delims=" %%i in ('git rev-parse --show-toplevel') do set "REPO_ROOT=%%i"
if errorlevel 1 (
    echo [ERROR] Not a git repository or git is not installed.
    exit /b 1
)

set "HOOKS_DIR=%REPO_ROOT%\git-hooks"

:: Verify that the hooks directory exists
if not exist "%HOOKS_DIR%" (
    echo [ERROR] Hooks directory not found at %HOOKS_DIR%
    exit /b 1
)

:: Point git to use git-hooks/ as the hooks directory
git config --local core.hooksPath "%HOOKS_DIR%"
if errorlevel 1 (
    echo [ERROR] Failed to set core.hooksPath.
    exit /b 1
)

echo [OK] Git hooks registered successfully.
echo      core.hooksPath = %HOOKS_DIR%
echo.
echo Active hooks:

:: List hook files (exclude .sh and .bat extensions)
set "FOUND=0"
for %%f in ("%HOOKS_DIR%\*") do (
    set "NAME=%%~nxf"
    echo !NAME! | findstr /i "\.sh$ \.bat$" >nul 2>&1
    if errorlevel 1 (
        echo      !NAME!
        set "FOUND=1"
    )
)
if "!FOUND!"=="0" (
    echo      (none found - make sure hook files have no .sh/.bat extension)
)

endlocal
exit /b 0