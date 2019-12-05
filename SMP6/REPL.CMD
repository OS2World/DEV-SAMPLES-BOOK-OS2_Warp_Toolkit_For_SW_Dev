
echo off
echo Running Sample with input from SMP6.C 
echo.
smp6 smp6.c 
echo.
echo.
echo Running FWDSTAMP to create replacement, MY.DLL
echo.
echo.
fwdstamp -v smp6dll.dll my.def my.dll
echo.
echo.
echo Renaming original SMP6DLL.DLL to SMP6DLL.ORG
echo.
echo.
rename smp6dll.dll smp6dll.org
echo.
echo.
echo Copying replacement, MY.DLL to SMP6DLL.DLL
echo.
echo.
copy my.dll smp6dll.dll
echo.
echo.
echo Now to re-run same program with replaced DLL.
echo.
smp6 smp6.c 
