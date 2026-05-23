@echo off
REM make_vc.bat - Generate Visual Studio project files from Qt .pro files
REM Recommended for Qt6 migration: consider using CMake in the future.

setlocal enabledelayedexpansion

REM Generate VS projects for each submodule.
REM Use explicit paths and avoid trailing spaces.
qmake -tp vc -o .\src\Application\ .\src\Application\
if errorlevel 1 exit /b 1
qmake -tp vc -o .\src\Chart\ .\src\Chart\
if errorlevel 1 exit /b 1
qmake -tp vc -o .\src\ElectronicComponent\ .\src\ElectronicComponent\
if errorlevel 1 exit /b 1
qmake -tp vc -o .\src\GeneralAPI\ .\src\GeneralAPI\
if errorlevel 1 exit /b 1
qmake -tp vc -o .\src\Dev\ .\src\Dev\
if errorlevel 1 exit /b 1
qmake -tp vc -o .\src\MainWindow\ .\src\MainWindow\
if errorlevel 1 exit /b 1

REM Generate VS project for the main application.
qmake -tp vc -o .\ElectricalCircuitBuildingSystem\ .\ElectricalCircuitBuildingSystem\
if errorlevel 1 exit /b 1

REM Generate VS project from the root .pro file explicitly.
qmake -tp vc .\GraduationWork.pro
if errorlevel 1 exit /b 1

endlocal
