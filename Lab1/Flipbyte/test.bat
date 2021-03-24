@echo off
set PROGRAM="%~1"
if %PROGRAM% == "" goto err

:: не указан входной параметр
%PROGRAM% > "%TEMP%\not-option-output.txt"
fc "%TEMP%\not-option-output.txt" test-data\not-option-output.txt > nul || goto testFailed
echo Test 1 OK

:: входной параметр не число
%PROGRAM% Ivan > "%TEMP%\option-not-number-output.txt"
fc "%TEMP%\option-not-number-output.txt" test-data\option-not-number-output.txt > nul || goto testFailed
echo Test 2 OK

:: входной параметр - строка с числом
%PROGRAM% Ivan345 > "%TEMP%\option-not-number-output.txt"
fc "%TEMP%\option-not-number-output.txt" test-data\option-not-number-output.txt > nul || goto testFailed
echo Test 3 OK

:: входной параметр - числом > 255
%PROGRAM% 256 > "%TEMP%\option-number-out-of-range-output.txt"
fc "%TEMP%\option-number-out-of-range-output.txt" test-data\option-number-out-of-range-output.txt > nul || goto testFailed
echo Test 4 OK

:: входной параметр - числом < 0
%PROGRAM% -5 > "%TEMP%\option-number-out-of-range-output.txt"
fc "%TEMP%\option-number-out-of-range-output.txt" test-data\option-number-out-of-range-output.txt > nul || goto testFailed
echo Test 5 OK

:: входной параметр - 0
%PROGRAM% 0 > "%TEMP%\option-0-output.txt"
fc "%TEMP%\option-0-output.txt" test-data\option-0-output.txt > nul || goto testFailed
echo Test 6 OK

:: входной параметр - 6
%PROGRAM% 6 > "%TEMP%\option-6-output.txt"
fc "%TEMP%\option-6-output.txt" test-data\option-6-output.txt > nul || goto testFailed
echo Test 7 OK

:: входной параметр - 255
%PROGRAM% 255 > "%TEMP%\option-255-output.txt"
fc "%TEMP%\option-255-output.txt" test-data\option-255-output.txt > nul || goto testFailed
echo Test 8 OK

echo Testing complete
exit /B 0

:testFailed
echo Testing failed
exit /B 1

:err
echo Usage: test.bat [Path to program]