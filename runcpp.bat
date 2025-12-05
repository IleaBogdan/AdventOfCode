@echo off
setlocal enabledelayedexpansion

set "year_dir="
for /f "delims=" %%d in ('dir /b /ad 20* 2^>nul ^| sort /r') do (
    set "year_dir=%%d"
    goto :found_year
)
:found_year
cd "%year_dir%"
set "cpp_file="
for /f "delims=" %%f in ('dir /b *.cpp 2^>nul ^| sort /r') do (
    set "cpp_file=%%f"
    goto :found_cpp
)
:found_cpp
g++ "%cpp_file%"
a.exe
cd ..

endlocal