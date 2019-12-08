#include "header.h"

void mx_creatematrix(double **matrix, char *s, int size)
{
    for (int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = mx_atof(&s);
}
