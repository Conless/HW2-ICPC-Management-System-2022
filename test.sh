rm -rf build
test -e build/ || mkdir build
echo "mkdir build/"
cd build
cmake ..
make
cd ..
echo
echo "Start running the program..."
time ./bin/ICPC < ./data/bigger.in > test.out
DIFF=$(diff ./data/bigger.out test.out) 
if [ "$DIFF" == "" ]
then
    echo "The output is correct."
fi
rm -f test.out