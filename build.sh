#!/bin/bash
rm -rf build/
rm -rf out/bin/
rm -rf out/lib/
rm -rf out/tst/
 
test -e build/ || mkdir build
echo "mkdir build/"
 
test -e out/ || mkdir out
echo "mkdir out/"
 
test -e out/bin/ || mkdir out/bin
echo "mkdir out/bin/"
 
test -e out/lib/ || mkdir out/lib
echo "mkdir out/lib/"
 
test -e out/tst/ || mkdir out/tst
echo "mkdir out/tst/"
 
cd build/
cmake .. -DCMAKE_BUILD_TYPE=Debug
make