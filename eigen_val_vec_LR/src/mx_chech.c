#include "header.h"

_Bool mx_check(double **L, double e, int size) {
    for (int i = 1; i < size; i++)
        for (int j = 0; j < i; j++)
            if (L[i][j] > e)
                return true;
    return false;
}
