#include "header.h"

void mx_printm(FILE *fd, double **matrix, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            fprintf(fd, "%.6f\t", matrix[i][j]);
        fprintf(fd, "\n");
    }
}
