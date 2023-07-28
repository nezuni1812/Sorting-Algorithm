@echo off
where /q g++
if %errorlevel% neq 0 (
    echo g++ not found
) else (
    g++ main.cpp -o main
    if %errorlevel% equ 0 (
        echo Program compiled successfully!
        echo Use this command to test it out: .\main.exe -a selection-sort 50000 -both
    )
)
pause