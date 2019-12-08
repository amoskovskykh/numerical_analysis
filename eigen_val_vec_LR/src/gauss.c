#include "header.h"

void gauss(double **A, double **L, double **R, int size)
{
    int i;
    int x;
    int y;
    double temp;

    for (x = 0; x < size; x++)
        for (y = 0; y < size; y++) 
            R[x][y] = A[x][y];

    for (i = 0; i < size - 1; i++)
    {
        x = i;
        y = i;
        while (R[x][y] == 0)
            x++;

        if (i != x)
        {
            for (; y < size; y++)
            {
                temp = R[i][y];
                R[i][y] = R[x][y];
                R[x][y] = temp;
            }
            y = i;
        }

        for (x = i; x < size - 1; x++)
        {
            temp = R[x+1][i] / R[i][i];
            L[x+1][i] = temp;
            for (; y < size; y++)
                R[x+1][y] -= temp * R[i][y];
            y = i;
        }
    }
}
