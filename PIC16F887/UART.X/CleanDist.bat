@echo off

echo Delete all files in "\dist"
del /f /s /q ".\dist"
echo.

echo Delete all files in "\build"
del /f /s /q ".\build"
echo.

echo Delete all files in "\debug"
del /f /s /q ".\debug"
echo.

echo Done.