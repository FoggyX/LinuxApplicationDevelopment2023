GENERATES = range
TEST_FILES = *.tmp

range: range.c
	gcc -g -O0 $< -o $@ 

test: range 1.gdb 2.gdb
	gdb --quiet $< < 1.gdb | awk '/^@@@/{print substr($$0,4)}' > 1.tmp 
	gdb --quiet $< < 2.gdb | awk '/^@@@/{print substr($$0,4)}' > 2.tmp
	cmp 1.res 1.tmp
	cmp 2.res 2.tmp

clean:
	rm -f *~ $(TEST_FILES) $(GENERATES)
