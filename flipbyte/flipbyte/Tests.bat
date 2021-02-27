@echo off

REM Путь к тестируемой программе передаётся через 1-й аргумент командной строки
SET PROGRAM="%~1"

REM Защита от запуска без аргумента, задающего пусть к программе
if %PROGRAM%=="" (
	echo Please specify file path to the program
)

REM Блок с тестами
REM The lowest acceptable limit
%PROGRAM% 0 > %TEMP%\test_1.txt
fc test_1.txt %TEMP%\test_1.txt
if ERRORLEVEL 1 goto err

REM The lowest unacceptable limit
%PROGRAM% -1 > %TEMP%\test_2.txt
fc test_2.txt %TEMP%\test_2.txt
if ERRORLEVEL 1 goto err

REM The highest acceptable limit
%PROGRAM% 255 > %TEMP%\test_3.txt
fc test_3.txt %TEMP%\test_3.txt
if ERRORLEVEL 1 goto err

REM The highest unacceptable limit
%PROGRAM% 256 > %TEMP%\test_4.txt
fc test_4.txt %TEMP%\test_4.txt
if ERRORLEVEL 1 goto err

REM Unacceptable amount of arguments
%PROGRAM% 123 with words > %TEMP%\test_5.txt
fc test_5.txt %TEMP%\test_5.txt
if ERRORLEVEL 1 goto err

REM Unacceptable value (string)
%PROGRAM% "" > %TEMP%\test_6.txt
fc test_6.txt %TEMP%\test_6.txt
if ERRORLEVEL 1 goto err\

REM Unacceptable value (float)
%PROGRAM% 3.14 > %TEMP%\test_7.txt
fc test_7.txt %TEMP%\test_7.txt
if ERRORLEVEL 1 goto err

REM Unacceptable value (string)
%PROGRAM% word > %TEMP%\test_8.txt
fc test_8.txt %TEMP%\test_8.txt
if ERRORLEVEL 1 goto err

REM Unacceptable value (int with string)
%PROGRAM% 2withwords > %TEMP%\test_9.txt
fc test_9.txt %TEMP%\test_9.txt
if ERRORLEVEL 1 goto err

REM Unacceptable value (int with string)
%PROGRAM% wordswith2 > %TEMP%\test_10.txt
fc test_10.txt %TEMP%\test_10.txt
if ERRORLEVEL 1 goto err

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1