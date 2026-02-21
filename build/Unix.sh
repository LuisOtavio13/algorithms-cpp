#!/bin/bash
set -e  

cd ..

mkdir -p out
cd out

cmake ..

cmake --build . --config Debug
