SCRIPT_DIR=$(cd $(dirname $0); pwd)
SHA1=$(cat $1 | sha1sum | sed -r "s/ .+//")
test -f $SCRIPT_DIR/tmp/$SHA1.out || /usr/local/lib/zapcc/bin/zapcc++ -std=c++14 -O2 -o $SCRIPT_DIR/tmp/$SHA1.out $1
echo $SCRIPT_DIR/tmp/$SHA1.out
