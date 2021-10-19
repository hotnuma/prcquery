@echo off

set root=%~dp0

copy /y %root%..\build\prcquery.exe %windir%
copy /y %root%..\build\prcquery.exe D:\Config\bin

