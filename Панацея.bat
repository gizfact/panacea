@echo off

if exist \\fbserv\update\panacea.exe (
ren c:\panacea\panacea.exe 0panacea.exe
copy \\fbserv\update\panacea.exe C:\panacea\
)

start "" "c:\panacea\panacea.exe"
