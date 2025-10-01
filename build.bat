@echo off
REM Script de compilation rapide pour Windows
REM ChainMaster Pro - INF 231

echo ========================================
echo   ChainMaster Pro - Build Script
echo ========================================
echo.

REM Créer le dossier build s'il n'existe pas
if not exist build mkdir build

REM Vérifier si GCC est installé
where gcc >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo ERREUR: GCC n'est pas installe ou n'est pas dans le PATH
    echo.
    echo Installez MinGW ou TDM-GCC pour compiler le projet.
    pause
    exit /b 1
)

echo [1/4] Compilation du demo interface...
gcc -Iinclude -Wall -Wextra -O2 src/core/list_simple.c src/core/list_double.c src/core/list_circulaire_simple.c src/core/list_circulaire_double.c src/core/common.c src/core/interface/main.c -o build/demo.exe
if %ERRORLEVEL% NEQ 0 (
    echo ERREUR lors de la compilation du demo interface
    pause
    exit /b 1
)
echo    OK - build/demo.exe

echo [2/4] Compilation du demo complet...
gcc -Iinclude -Wall -Wextra -O2 src/core/list_simple.c src/core/list_double.c src/core/list_circulaire_simple.c src/core/list_circulaire_double.c src/core/common.c examples/demo_complete.c -o build/demo_all.exe
if %ERRORLEVEL% NEQ 0 (
    echo ERREUR lors de la compilation du demo complet
    pause
    exit /b 1
)
echo    OK - build/demo_all.exe

echo [3/4] Compilation du tutorial...
gcc -Iinclude -Wall -Wextra -O2 src/core/list_simple.c src/core/list_double.c src/core/list_circulaire_simple.c src/core/list_circulaire_double.c src/core/common.c examples/tutorial.c -o build/tutorial.exe
if %ERRORLEVEL% NEQ 0 (
    echo ERREUR lors de la compilation du tutorial
    pause
    exit /b 1
)
echo    OK - build/tutorial.exe

echo [4/4] Compilation des tests...
gcc -Iinclude -Wall -Wextra -O2 src/core/list_simple.c src/core/list_double.c src/core/list_circulaire_simple.c src/core/list_circulaire_double.c src/core/common.c src/tests/test_runner.c -o build/test_runner.exe
if %ERRORLEVEL% NEQ 0 (
    echo ERREUR lors de la compilation des tests
    pause
    exit /b 1
)
echo    OK - build/test_runner.exe

echo.
echo ========================================
echo   Compilation reussie! 
echo ========================================
echo.
echo Executables disponibles dans build/:
echo   - demo.exe         (interface interactive)
echo   - demo_all.exe     (demo complet 5 exercices)
echo   - tutorial.exe     (tutorial guide)
echo   - test_runner.exe  (suite de tests)
echo.
echo Pour executer le demo: build\demo_all.exe
echo Pour lancer les tests: build\test_runner.exe
echo.
pause
