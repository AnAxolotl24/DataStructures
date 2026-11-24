#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix{
    int* matrix;
    size_t row;
    size_t column;
} Matrix;

Matrix* matrix_initialization(size_t row, size_t column){
    Matrix* res = (Matrix*)malloc(sizeof(*res));
    if(res == NULL){
        fprintf(stderr, "Memory allocation for matrix failed\n");
        exit(EXIT_FAILURE);
    }
    res->matrix = (int*)malloc(sizeof(*res->matrix) * row * column);
    if(res->matrix == NULL){
        fprintf(stderr, "Memory allocation for matrix failed\n");
        exit(EXIT_FAILURE);
    }
    res->row = row;
    res->column = column;
    return res;
}

void matrix_free(Matrix* mat){
    free(mat->matrix);
    free(mat);
}

int matrix_get(Matrix* mat, size_t x, size_t y){
    if(x >= mat->row){
        fprintf(stderr, "Row index out of range\n");
        exit(EXIT_FAILURE);
    }else if(y >= mat->column){
        fprintf(stderr, "Column index out of range\n");
        exit(EXIT_FAILURE);
    }
    return mat->matrix[y + x * mat->column];
}

void matrix_set(Matrix* mat, size_t x, size_t y, int val){
    if(x >= mat->row){
        fprintf(stderr, "Row index out of range\n");
        exit(EXIT_FAILURE);
    }else if(y >= mat->column){
        fprintf(stderr, "Column index out of range\n");
        exit(EXIT_FAILURE);
    }
    mat->matrix[y + x * mat->column] = val;
}

void matrix_display(Matrix* mat){
    for(size_t i = 0; i < (mat->row * mat->column); ++i){
        if(i%(mat->row) == 0){
            printf("\n");
        }
        printf("%d ", mat->matrix[i]);
    }
}

void matrix_clear(Matrix* mat){
    for(size_t i = 0; i < (mat->row * mat->column); ++i){
        mat->matrix[i] = 0;
    }
}

int main(void){
    Matrix* test = matrix_initialization(3, 3);
    matrix_clear(test);
    matrix_set(test, 0, 0, 1);
    matrix_set(test, 1, 1, 1);
    matrix_set(test, 2, 2, 1);
    matrix_display(test);
    matrix_free(test);
}
