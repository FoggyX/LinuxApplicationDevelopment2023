CFLAGS = -ansi -pedantic -Wall -Wextra
if COND_GCOV
CFLAGS += -O0 -g -fprofile-arcs -ftest-coverage
else
CFLAGS += -O3 -g3
endif


lib_LTLIBRARIES = libbuf.la

buf_LDADD = libbuf.la

gcov:
	gcov -o .libs libbuf -b
