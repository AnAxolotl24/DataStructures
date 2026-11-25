#ifndef MATRIX_C
#define MATRIX_C

#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix{
    int* matrix;
    size_t row;
    size_t column;
} Matrix;

Matrix* matrix_initialization(size_t row, size_t column);
void matrix_free(Matrix* mat);
int matrix_get(Matrix* mat, size_t y, size_t x);
void matrix_set(Matrix* mat, size_t y, size_t x, int val);
void matrix_display(Matrix* mat);
void matrix_clear(Matrix* mat);
Matrix* matrix_addition(Matrix* mat, Matrix* rix);
Matrix* matrix_substraction(Matrix* mat, Matrix* rix);
Matrix* matrix_cubic_multiplication(Matrix* mat, Matrix* rix);
void matrix_copy(Matrix* example, Matrix* copier);

#endif