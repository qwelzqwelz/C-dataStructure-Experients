mkdir cmake-build-debug

cd ./cmake-build-debug

cmake -G "MinGW Makefiles" .. 

mingw32-make 

for /r "." %%n in (Exp*.exe) do (start %%n)