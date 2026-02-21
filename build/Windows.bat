@echo off
cd ..
mkdir out
cd out
cmake ..
cmake --build . --config Debug
