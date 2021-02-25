@echo off
SET program="%~1"
if %program% == "" goto err

@rem указаны не все входные параметры
%PROGRAM% test-data\search-string-empty.txt "%TEMP%\out.txt" > "%TEMP%\not-all-options-output.txt"
fc.exe "%TEMP%\not-all-options-output.txt" test-data\not-all-options-output.txt > nul || goto testFailed
echo Test 1 OK

@rem входной файл не существует
%PROGRAM% test-data\not-exists-file.txt "%TEMP%\out.txt" Ivan Vasia > "%TEMP%\not-exists-output.txt"
fc.exe "%TEMP%\not-exists-output.txt" test-data\not-exists-output.txt > nul || goto testFailed
echo Test 2 OK

@rem пустая строка поиска
%PROGRAM% test-data\search-string-empty.txt "%TEMP%\out.txt" "" empty
fc.exe "%TEMP%\out.txt" test-data\search-string-empty.txt > nul || goto testFailed
echo Test 3 OK

@rem замена в нескольких местах
%PROGRAM% test-data\replace-name.txt "%TEMP%\out.txt" Bond Smith
fc.exe "%TEMP%\out.txt" test-data\replace-name-output.txt > nul || goto testFailed
echo Test 4 OK

@rem многократное вхождение искомой строки в строку-заменитель
%PROGRAM% test-data\multiple-occurrence.txt "%TEMP%\out.txt" pa papa
fc.exe "%TEMP%\out.txt" test-data\multiple-occurrence-output.txt > nul || goto testFailed
echo Test 5 OK

@rem числа
%PROGRAM% test-data\numbers.txt "%TEMP%\out.txt" 1231234 0102030
fc.exe "%TEMP%\out.txt" test-data\numbers-output.txt > nul || goto testFailed
echo Test 6 OK

echo OK
exit /B

:testFailed
echo Testing failed
exit /B 1

:err
echo Usage: test.bat [Path to program]

