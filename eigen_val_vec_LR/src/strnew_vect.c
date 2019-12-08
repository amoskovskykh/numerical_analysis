#include "header.h"

double *strnew_vect(int size)
{
    double *b = (double *) malloc(sizeof(double) * size);
    return b; 
}
