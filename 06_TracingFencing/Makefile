GENERATES = move lib_remove.so
TEST_FILES = *.tmp

all: move lib_remove.so

move: move.c
	gcc -O0 $< -o $@

lib_remove.so: remove.c
	gcc -shared -fPIC $< -o $@

test: move lib_remove.so
	echo "test test test" > infile_test.tmp
	cp infile_test.tmp infile.tmp
	./$< infile.tmp outfile.tmp
	diff infile_test.tmp outfile.tmp
	rm outfile.tmp

	cp infile_test.tmp infile.tmp
	strace -e openat -P infile.tmp -e fault=openat:error=EACCES ./$< infile.tmp outfile.tmp || test $$? -eq 2
	test -e infile.tmp
	test ! -e outfile.tmp

	strace -e openat -P outfile.tmp -e fault=openat:error=EACCES ./$< infile.tmp outfile.tmp || test $$? -eq 3
	test -e infile.tmp
	test ! -e outfile.tmp

	strace -e write -e fault=write:error=EIO ./$< infile.tmp outfile.tmp || test $$? -eq 4
	test -e infile.tmp
	test ! -e outfile.tmp

	strace -e read -P infile.tmp -e fault=read:error=EIO ./$< infile.tmp outfile.tmp || test $$? -eq 5
	test -e infile.tmp
	test ! -e outfile.tmp

	strace -e close -e fault=close:error=EIO:when=3 ./$< infile.tmp outfile.tmp || test $$? -eq 6
	test -e infile.tmp
	test ! -e outfile.tmp

	strace -e close -e fault=close:error=EIO:when=4 ./$< infile.tmp outfile.tmp || test $$? -eq 7
	test -e infile.tmp
	test ! -e outfile.tmp

	cp infile.tmp PROTECTED_infile.tmp
	LD_PRELOAD=./lib_remove.so ./$< PROTECTED_infile.tmp outfile.tmp
	test -e outfile.tmp
	test -e PROTECTED_infile.tmp

clean:
	rm -f *~ $(TEST_FILES) $(GENERATES)
