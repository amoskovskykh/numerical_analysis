#include "header.h"

void mult_m_v(double **A, double *a, double *c, int size)
{
    double temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            temp += A[i][j] * c[j];
        a[i] = temp;
        temp = 0;
    }
}
