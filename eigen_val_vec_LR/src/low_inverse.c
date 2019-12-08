#include "header.h"

void low_inverse(double ** Inv, double **A, int size)
{
    double temp = 0;
    for (int x = 1; x < size; x++)
        for (int i = x; i < size; i++) {
            for (int j = i - x + 1; j <= i; j++)
                temp += (Inv[i][j] * A[j][i-x]);
            Inv[i][i - x] = -temp;
            temp = 0;
        }
}
