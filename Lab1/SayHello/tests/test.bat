@echo off

set PROGRAM="%~1"
:: Путь к файлу с выходными данными программы
set OUT="%TEMP%\out.txt"

:: Тестируем имя из одного слова
%PROGRAM% < "%~dp0Boris.txt" > %OUT% || goto err
:: Сравнение содержимого файла с выводом программы и эталон
:: если они не равны, переходим на строку err
fc %OUT% "%~dp0Boris-out.txt" > nil || goto err
echo Test 1 OK

:: Тестируем имя из нескольких слов
%PROGRAM% < "%~dp0HarryPotter.txt" > %OUT% || goto err
fc %OUT% "%~dp0HarryPotter-out.txt" > nil || goto err
echo Test 2 OK

:: Тестируем пустое имя
%PROGRAM% < "%~dp0Empty.txt" > %OUT% || goto err
fc %OUT% "%~dp0Empty-out.txt" > nil || goto err
echo Test 3 OK

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1