time /t

set CONF=%1
set DEPS_DIR=.\deps\

set CONAN_HOME=C:\c

if not defined CONF (
    goto default_conf
) else (
    echo "You use configuration %CONF%."
    goto configure
)

:default_conf
SET CONF=Debug
echo "You use default configuration %CONF%. You can use argument Debug or Released."

:configure

rem goto end

rem pip install --upgrade pip
python -m venv tmpEnv

CALL ".\tmpEnv\Scripts\activate"

python -m pip install --upgrade pip
rem pip install html5lib

pip install conan

conan install %DEPS_DIR% -s build_type=%CONF% -of=conan/%CONF% --build=missing --profile %DEPS_DIR%%CONF%_prf
call "%~dp0/conan/%CONF%/build/generators/conanrun.bat"

rem //find msbuild path
rem for /f "delims=" %%i in ('where msbuild') do set MSBUILD_PATH=%%i

rem // find msbuild path from vswhere and add to path
for /f "delims=" %%i in ('"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath') do set VS_INSTALL_DIR=%%i
set MSBUILD_PATH=%VS_INSTALL_DIR%\MSBuild\Current\Bin\MSBuild.exe
set PATH=%VS_INSTALL_DIR%\MSBuild\Current\Bin;%PATH%

rem // find cl.exe path from vswhere and add to path
for /f "delims=" %%i in ('"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath') do set VS_INSTALL_DIR=%%i
for /d %%d in ("%VS_INSTALL_DIR%\VC\Tools\MSVC\*") do set CL_PATH=%%d\bin\Hostx64\x64
set PATH=%CL_PATH%;%PATH%
echo "CL_PATH: %CL_PATH%"

call %~dp0/make_vc.bat

REM Add deps.props import to all .vcxproj files
rem powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0\add_deps_props.ps1" -ProjectRoot "%~dp0"

rem CALL ".\tmpEnv\Scripts\deactivate"

:end

time /t

rem time /t > time_done.txt

rem shutdown -s -f -t 0