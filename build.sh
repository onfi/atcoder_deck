SCRIPT_DIR=$(cd $(dirname $0); pwd)
SHA1=$(cat $1 | sha1sum | sed -r "s/ .+//")
test -f $SCRIPT_DIR/tmp/$SHA1.out || g++ -std=gnu++1y -O2 -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o $SCRIPT_DIR/tmp/$SHA1.out $1
cat test.txt | $SCRIPT_DIR/tmp/$SHA1.out | tee tmp/result.txt 
