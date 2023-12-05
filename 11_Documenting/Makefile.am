SUBDIRS = src po

@DX_RULES@

all-local:  doxygen-doc

pkgdata_DATA=guesser.1

%.1:  ./src/guesser
	help2man -o $@ $<

http:	doxygen-doc
	python3 -m http.server --directory $</html
