#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc-1);
        return 0;
    }



    for (int i = 1; i < argc; i++) {
        if (atoi(argv[i]) <= 0) {
            printf("Incorrect usage. The parameters you provided are not positive integers");
            return 0;

        }
    }

    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    int **matrix = (int**)malloc(row*sizeof(int*));

    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(col*sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = minrand + rand() % (maxrand - minrand + 1);
        }
    } 

    FILE *pFile = fopen("matrix.txt","w");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fprintf(pFile, "%d", matrix[i][j]);

            if (j < col -1) {
                fprintf(pFile, " ");
            }
        }

        if (i < row -1) {
            fprintf(pFile, "\n");
        }
        
    }

    fclose(pFile);
    
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;


}
