#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show(const char *maze, int width, int height, char pass, char wall) {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			char s = maze[y * width + x];
			if (s == 1) {
				printf("%c", wall);
			} else {
				printf("%c", pass);
			}
        }
        printf("\n");
    }
}

void visit(char *maze, int x, int y, int width, int height) {
	maze[y * width + x] = 0;

	int dirs[4] = {0, 1, 2, 3};
	for (int i = 0; i < 4; i++) {
		int r = rand() & 3;
		int temp = dirs[r];
		dirs[r] = dirs[i];
		dirs[i] = temp;
	}

	for (int i = 0; i < 4; ++i) {
		int dx = 0, dy = 0;
		if (dirs[i] == 0) {
			dx = 1;
		} else if (dirs[i] == 1) {
			dy = 1;
		} else if (dirs[i] == 2) {
			dx = -1;
		} else {
			dy = -1;
		}

		int x1 = x + (dx << 1);
		int y1 = y + (dy << 1);

		if (x1 > 0 && y1 > 0 && x1 < width && y1 < height) {
			if (maze[y1 * width + x1] == 1) {
				maze[(y1 - dy) * width + (x1 - dx)] = 0;
				visit(maze, x1, y1, width, height);
			}
		}
	}
}

int main(int argc,char *argv[]) {
	int width, height, size = 6;
	char pass = '.', wall = '#';
	char *maze;

	srand(time(0));

	width = size * 2 + 1;
	height = size * 2 + 1;

	maze = (char*)malloc(width * height * sizeof(char));

	for(int i = 0; i < width * height; i++) {
		maze[i] = 1;
	}

	visit(maze, 1, 1, width, height);
	show(maze, width, height, pass, wall);

	free(maze);
	return 0;
}
