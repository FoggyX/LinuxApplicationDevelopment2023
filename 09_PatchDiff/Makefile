BIN=maze maze-1 maze-2 maze-3 
CC=gcc
FLAGS=-O0 -Wall

all: maze maze-1 maze-2 maze-3

%: %.c
	$(CC) $(FLAGS) $< -o $@

maze-%.c: %.patch maze.c
	patch -o $@ < $<

.PHONY: run
run: maze maze-1 maze-2 maze-3
	./maze
	./maze-1 8
	./maze-2 ' @' 5
	./maze-3 11 '`<' 4

.PHONY: clean
clean:
	rm $(BIN)
