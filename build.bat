@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
set PATH=C:\Qt\6.10.2\msvc2022_64\bin;C:\Qt\Tools\QtCreator\bin\jom;%PATH%

cd /d "%~dp0"

:: Clean old build
if exist build\Makefile.Release (
    cd build
    jom clean 2>nul
    cd ..
)
if exist build rmdir /s /q build 2>nul
mkdir build
cd build

echo.
echo === qmake ===
:: CONFIG+=no_batch forces explicit compile rules per file (avoids inference rule
:: issues with spaces in paths on Windows)
qmake ../SFDLSaugerPro.pro CONFIG+=release CONFIG+=no_batch
if %ERRORLEVEL% NEQ 0 (
    echo qmake FEHLGESCHLAGEN
    exit /b 1
)

echo.
echo === jom (parallel build) ===
jom -j%NUMBER_OF_PROCESSORS%
if %ERRORLEVEL% NEQ 0 (
    echo jom FEHLGESCHLAGEN
    exit /b 1
)

echo.
echo === windeployqt (Qt-DLLs bereitstellen) ===
windeployqt --release --no-translations release\SFDLSaugerPro.exe
if %ERRORLEVEL% NEQ 0 (
    echo windeployqt FEHLGESCHLAGEN
    exit /b 1
)

echo.
echo === BUILD ERFOLGREICH ===
echo Deployable EXE: %~dp0build\release\SFDLSaugerPro.exe
echo Alle Qt-DLLs sind im Ordner: %~dp0build\release\
