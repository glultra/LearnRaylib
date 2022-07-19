@echo off

for /F "tokens=*" %%A in  (branches.txt) do  (
   CALL git checkout -f %%A
   CALL git restore --source master ./deps/
   Call git add .
   CALL git commit -m "Release version of raylib has been restored."
   CALL git push origin -f %%A
)

exit