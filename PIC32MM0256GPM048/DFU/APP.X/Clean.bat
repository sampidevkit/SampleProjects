@echo off

copy "dist\default\production\APP.X.production.unified.hex" ".\bld_app.hex"
del /f /s /q ".\dist"
del /f /s /q ".\build"
del /f /s /q ".\debug"

echo Done.