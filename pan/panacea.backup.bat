rem @echo off

for /l %%i in (1,1,%1) do (

timeout /t 10
del c:\pdb\backup\pan%DATE%.log
c:\"Program Files"\Firebird\Firebird_2_5\bin\gbak -b -g -user sysdba -pass masterkey localhost:c:\pdb\panacea.pdb c:\pdb\backup\pan%DATE%.pbk -v -y c:\pdb\backup\pan%DATE%.log

if not errorlevel 1 goto :end

)

:end
