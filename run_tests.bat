@echo off
REM Script de lancement rapide des tests
REM ChainMaster Pro - INF 231

echo ========================================
echo   ChainMaster Pro - Suite de Tests
echo ========================================
echo.

REM Vérifier si le build existe
if not exist build\test_runner.exe (
    echo Les tests ne sont pas encore compiles.
    echo Lancement de la compilation...
    echo.
    call build.bat
    if %ERRORLEVEL% NEQ 0 (
        echo Erreur lors de la compilation.
        pause
        exit /b 1
    )
)

echo Lancement de la suite de tests...
echo.

build\test_runner.exe

echo.
pause
