#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

bool mx_isdigit(char c);
int mx_strlen(const char *str);
bool mx_isspace(char c);
void mx_printerr(const char *s); 
double mx_atof(char **str); 
void mx_printm(FILE *fd, double **matrix, int size);
_Bool mx_allowed(char c);
int mx_strcmp(const char *s1, const char *s2);

void mx_readfile(char *f, char *str); 
int mx_fsize(const char *f);
int mx_count_num(const char *str);
void mx_creatematrix(double **matrix, char *s, int size);

void gauss(double **A, double **L, double **R, int size);
void matrix_mult(double **A, double **B, double **C, int size);
void low_inverse(double **Inv, double **A, int size);
double frobenius_norm(double **A, int size);
void find_eigenvector(FILE *fd, double **A, double **L, double **R, double **m_vect, int x, double ev, int size);
void mult_m_v(double **A, double *a, double *c, int size);
double **strnew_matr(int size);
char *mx_strnew(const int size);
double *strnew_vect(int size);
_Bool mx_check(double **L, double e, int size);

#endif
