#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("Usage:\n");
		printf("%s infile outfile\n", argv[0]);
		return 1;
	}
	FILE *source, *target;

	source = fopen(argv[1], "r");
	if (source == NULL) {
		printf("Cannot open file: %s\n", argv[1]);
		return 2;
	}

	target = fopen(argv[2], "w");
	if (target == NULL) {
		printf("Cannot open file: %s\n", argv[2]);
		return 3;
	}
	setvbuf(target, NULL, _IONBF, 0);

	char ch;
	while ((ch = fgetc(source)) != EOF) {
		if (fputc(ch, target) == EOF) {
			printf("Failed to write to file: %s\n", argv[2]);
			fclose(source);
			fclose(target);
			remove(argv[2]);
			return 4;
		}
	}

	if (ferror(source)) {
		printf("Something went wrong\n");
		fclose(source);
		fclose(target);
		remove(argv[2]);
		return 5;
	}
	if (fclose(source) == EOF) {
		printf("Cannot close file: %s\n", argv[1]);
		fclose(target);
		remove(argv[2]);
		return 6;
	}
	if (fclose(target) == EOF) {
		printf("Cannot close file: %s\n", argv[2]);
		remove(argv[2]);
		return 7;
	}

	if (remove(argv[1]) == EOF) {
		printf("Cannot remove file: %s\n", argv[1]);
		return 8;
	}

	return 0;
}