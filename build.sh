SCRIPT_DIR=$(cd $(dirname $0); pwd)
g++ -std=gnu++1y -O2 -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o $SCRIPT_DIR/tmp/a.out $1
cat test.txt | $SCRIPT_DIR/tmp/a.out
