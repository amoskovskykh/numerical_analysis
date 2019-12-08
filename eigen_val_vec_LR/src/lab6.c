#include "header.h"

int main(int argc, char *argv[])
{
    FILE * fd;
    fd = fopen("result.txt", "w+");
    if (argc != 3 || mx_strcmp("LR", argv[2]) != 0) {

        mx_printerr("usage: ./lab6 [file_name] [method \"LR\" or \"QR\" (now only LR method available)]\n");
        exit(0);
    } 

    char *str = mx_strnew(mx_fsize(argv[1])); 
    mx_readfile(argv[1], str);
    int m_size = mx_count_num(str);

    double **A = strnew_matr(m_size);
    double **R = strnew_matr(m_size);
    double **L = strnew_matr(m_size);
    double **L_inv = strnew_matr(m_size);
    double **m_vect = strnew_matr(m_size);
    double *eigval = strnew_vect(m_size);
    double *residal_v = strnew_vect(m_size);
    double e = 0.0000001;

    mx_creatematrix(A, str, m_size);
    for (int i = 0; i < m_size; i++)
        L[i][i] = 1;
    for (int i = 0; i < m_size; i++)
        L_inv[i][i] = 1;
    for (int i = 0; i < m_size; i++)
        residal_v[i] = 0;
    
    _Bool m = true;
    
    for (int i = 0; m; i++)
    {
        fprintf(fd, "Iteration number: %d\n", i + 1);
        gauss(A, L, R, m_size);
        fprintf(fd, "R matrix: \n");
        mx_printm(fd, R, m_size);
        fprintf(fd, "L matrix: \n");
        mx_printm(fd, L, m_size);
        m = mx_check(L, e, m_size);
        low_inverse(L_inv, L, m_size);

        matrix_mult(R, A, L, m_size);
        matrix_mult(A, L_inv, R, m_size);

        fprintf(fd, "Frobenius norm: %lf\n\n", frobenius_norm(A, m_size));
    }

    fprintf(fd, "Eigenvalues and eigenvectors:\n");
    for (int i = 0; i < m_size; i++)
        eigval[i] = A[i][i];
    for (int i = 0; i < m_size; i++)
    {
        mx_creatematrix(A, str, m_size);
        find_eigenvector(fd, A, L, R, m_vect, i, eigval[i], m_size);
    }

    fprintf(fd, "\nResidual vectors:\n");
    mx_creatematrix(A, str, m_size);
    for (int i = 0; i < m_size; i++)
    {
        fprintf(fd, "\neval == %lf\nresidal vector:\n", eigval[i]);        
        mult_m_v(A, residal_v, m_vect[i], m_size);
        for (int j = 0; j < m_size; j++)
            fprintf(fd, "%.5f\n", residal_v[j] - eigval[i] * m_vect[i][j]);
    }

    fclose(fd);
    free(str);
    free(eigval);
    free(residal_v);
    free(m_vect);
    free(A);
    free(L);
    free(R);
    free(L_inv);
    return 0;
}

