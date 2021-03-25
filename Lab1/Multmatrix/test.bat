@echo off
set PROGRAM="%~1"
if %PROGRAM% == "" goto err

:: не указаны входные параметры
%PROGRAM% > "%TEMP%\not-option-output.txt"
fc "%TEMP%\not-option-output.txt" test-data\not-option-output.txt > nul || goto testFailed
echo Test 1 OK

:: входной файл не существует
%PROGRAM% test-data\not-exists-file1.txt test-data\not-exists-file2.txt > "%TEMP%\not-exists-output.txt"
fc "%TEMP%\not-exists-output.txt" test-data\not-exists-output.txt > nul || goto testFailed
echo Test 2 OK

:: не квадратичная матрица 3х3
%PROGRAM% test-data\not-matrix3x3.txt test-data\not-matrix3x3.txt > "%TEMP%\not-matrix3x3-output.txt"
fc "%TEMP%\not-matrix3x3-output.txt" test-data\not-matrix3x3-output.txt > nul || goto testFailed
echo Test 3 OK

:: перемножение матриц
%PROGRAM% test-data\test1-matrix1.txt test-data\test1-matrix2.txt > "%TEMP%\test1-multMatrix-output.txt"
fc "%TEMP%\test1-multMatrix-output.txt" test-data\test1-multMatrix-output.txt > nul || goto testFailed
echo Test 4 OK

:: перемножение матриц
%PROGRAM% test-data\test2-matrix1.txt test-data\test2-matrix2.txt > "%TEMP%\test2-multMatrix-output.txt"
fc "%TEMP%\test2-multMatrix-output.txt" test-data\test2-multMatrix-output.txt > nul || goto testFailed
echo Test 5 OK

:: строки в файле
%PROGRAM% test-data\string-in-file.txt test-data\test2-matrix2.txt > "%TEMP%\string-in-file-output.txt"
fc "%TEMP%\string-in-file-output.txt" test-data\string-in-file-output.txt > nul || goto testFailed
echo Test 6 OK


echo Testing complete
exit /B 0

:testFailed
echo Testing failed
exit /B 1

:err
echo Usage: test.bat [Path to program]