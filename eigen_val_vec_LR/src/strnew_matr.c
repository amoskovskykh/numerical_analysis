#include "header.h"

double **strnew_matr(int size)
{
    double **A = (double **) malloc(sizeof(double *) * size);
    for (int i = 0; i < size; i++)
        A[i] = (double *) malloc(sizeof(double) * size);
    return A; 
}
