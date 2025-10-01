@echo off
REM Script de lancement rapide du demo complet
REM ChainMaster Pro - INF 231

echo ========================================
echo   ChainMaster Pro - Demo Complet
echo   Exercices INF 231
echo ========================================
echo.

REM Vérifier si le build existe
if not exist build\demo_all.exe (
    echo Le demo n'est pas encore compile.
    echo Lancement de la compilation...
    echo.
    call build.bat
    if %ERRORLEVEL% NEQ 0 (
        echo Erreur lors de la compilation.
        pause
        exit /b 1
    )
)

echo Lancement du demo des 5 exercices...
echo.
echo ========================================
echo.

build\demo_all.exe

echo.
echo ========================================
echo Demo termine!
echo ========================================
pause
