#include "header.h"

void matrix_mult(double **A, double **B, double **C, int size)
{
    int i;
    int x;
    int y;
    double sum = 0;
    for (i = 0; i < size; i++)
        for (x = 0; x < size; x++) {
            for (y = 0; y < size; y++)
                sum += B[i][y] * C[y][x];
            A[i][x] = sum;
            sum = 0;
        }
}

