#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc < 2) {
        printf("Usage:\n");
        printf("%s N to generate [0, 1, ... N-1]\n", argv[0]);
        printf("%s M N to generate [M, M+1, ... N-1]\n", argv[0]);
        printf("%s M N S to generate [M, M+S, M+2S, ... N-1]\n", argv[0]);
        return -1;
    }
    
    int S = 1, M = 0, N = 0;

    if (argc == 2) {
    	N = atoi(argv[1]);
    } else if (argc == 3) {
    	M = atoi(argv[1]);
    	N = atoi(argv[2]);
    } else {
    	M = atoi(argv[1]);
    	N = atoi(argv[2]);
    	S = atoi(argv[3]);
    }

    for (int i = M; i < N; i += S) {
    	printf("%i\n", i);
    }

    return 0; 
}
