cd build
cmake ..
make
echo
echo "Start running the program..."
time ./ICPC < ../data/bigger.in > test.out
DIFF=$(diff ../data/bigger.out test.out) 
if [ "$DIFF" == "" ]
then
    echo "The output is correct."
fi