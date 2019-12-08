#include "header.h"

void find_eigenvector(FILE * fd, double **A, double **L, double **R, double **m_vect, int x, double ev, int size)
{   
    for(int i = 0; i < size; i++)
        A[i][i] -= ev;
    
    gauss(A, L, R, size);
    double *b = (double *) malloc(sizeof(double) * size);
    for(int i = 0; i < size; i++)
        b[i] = 0;

    double temp = 0;
    
    b[size - 1] = 1;
    m_vect[x][size - 1] = 1;
    for(int i = size-2; i >= 0; i--)
    {
        for(int j = i+1; j < size; j++)
        {
            temp += R[i][j]/R[i][i] * b[j];
            //printf("[%d][%d] == %lf \n", i, j./, temp);
        }
        b[i] = -1 * temp;
        m_vect[x][i] = -1 * temp;;
        temp = 0;
    }

    fprintf(fd, "eval == %lf; \ne_vect\n", ev);
    for(int i = 0; i < size; i++)
        fprintf(fd, "%lf\n", b[i]);
    fprintf(fd, "\n");
    free(b);
}
