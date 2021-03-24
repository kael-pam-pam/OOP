@echo off

set PROGRAM="%~1"
:: ���� � ����� � ��������� ������� ���������
set OUT="%TEMP%\out.txt"

:: ��������� ��� �� ������ �����
%PROGRAM% < "%~dp0Boris.txt" > %OUT% || goto err
:: ��������� ����������� ����� � ������� ��������� � ������
:: ���� ��� �� �����, ��������� �� ������ err
fc %OUT% "%~dp0Boris-out.txt" > nil || goto err
echo Test 1 OK

:: ��������� ��� �� ���������� ����
%PROGRAM% < "%~dp0HarryPotter.txt" > %OUT% || goto err
fc %OUT% "%~dp0HarryPotter-out.txt" > nil || goto err
echo Test 2 OK

:: ��������� ������ ���
%PROGRAM% < "%~dp0Empty.txt" > %OUT% || goto err
fc %OUT% "%~dp0Empty-out.txt" > nil || goto err
echo Test 3 OK

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1