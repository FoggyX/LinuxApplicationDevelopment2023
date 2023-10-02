GENERATES = prog prog-a prog-so
TRASH = *.o *~ o.* *.a *.so
TEST_FILES = *.tmp

%.o: %.c
	cc -fPIC $< -c -o $@

all: prog prog-a prog-so

liboutput_static.a: fun.o const.o
	ar -rcs $@ $^

liboutput.so: fun.o const.o
	cc -shared $^ -o $@

prog: const.o fun.o prog.o
	cc $^ -o $@

prog-a: prog.o liboutput_static.a
	cc -L. $< -loutput_static -o $@ 

prog-so: prog.o liboutput.so
	cc -L. $< -loutput -o $@ 

test: test-zero-arg test-one-arg test-three-args
	cmp prog-zero.tmp prog-a-zero.tmp
	cmp prog-zero.tmp prog-so-zero.tmp
	cmp prog-one.tmp prog-a-one.tmp
	cmp prog-one.tmp prog-so-one.tmp
	cmp prog-three.tmp prog-a-three.tmp
	cmp prog-three.tmp prog-so-three.tmp
	
test-zero-arg: prog prog-a prog-so
	./prog 1> "prog-zero.tmp"
	./prog-a 1> "prog-a-zero.tmp"
	LD_LIBRARY_PATH=`pwd` ./prog-so 1> "prog-so-zero.tmp"

test-one-arg: prog prog-a prog-so
	./prog 1 1> "prog-one.tmp"
	./prog-a 1 1> "prog-a-one.tmp"
	LD_LIBRARY_PATH=`pwd` ./prog-so 1 1> "prog-so-one.tmp"

test-three-args: prog prog-a prog-so
	./prog 1 2 3 1> "prog-three.tmp"
	./prog-a 1 2 3 1> "prog-a-three.tmp"
	LD_LIBRARY_PATH=`pwd` ./prog-so 1 2 3 1> "prog-so-three.tmp"

clean:
	rm -f $(TRASH) $(TEST_FILES) $(GENERATES)
