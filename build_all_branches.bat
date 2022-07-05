@echo off

if not exist "examples\res" (
    mkdir "examples\res"
    xcopy .\res\ .\examples\res /E
)
for /F "tokens=*" %%A in  (branches.txt) do  (
   CALL git checkout %%A
   CALL make compile
   Call move main.exe .\examples\%%A.exe
)

exit