#include "header.h"

double frobenius_norm(double **A, int size)
{
    double temp = 0;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            temp+= sqrt(A[i][j] * A[i][j]);
    return temp;
}
