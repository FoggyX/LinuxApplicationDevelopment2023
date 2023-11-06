echo -n "hello world" > test.tmp

SHA1=$(echo "SHA1 test.tmp" | ./rhasher)
SHA1SUM=($(sha1sum test.tmp))

if [[ $SHA1 != $SHA1SUM ]]; then
	exit 1;
fi

MD5=$(echo "MD5 test.tmp" | ./rhasher)
MD5SUM=($(md5sum test.tmp))

if [[ $MD5 != $MD5SUM ]]; then
	exit 1;
fi

rm test.tmp
