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
    for(size_t i = 0; i < row * column; ++i){
        res->matrix[i] = 0;
    }
    return res;
}

void matrix_free(Matrix* mat){ 
    free(mat->matrix);
    free(mat);
}

int matrix_get(Matrix* mat, size_t y, size_t x){
    if(mat == NULL){
        fprintf(stderr, "Error : cannot get value, matrix given is NULL");
        exit(EXIT_FAILURE);
    }
    if(y >= mat->row){
        fprintf(stderr, "Error : cannot get value, row index out of range\n");
        exit(EXIT_FAILURE);
    }else if(x >= mat->column){
        fprintf(stderr, "Error : cannot get value, Column index out of range\n");
        exit(EXIT_FAILURE);
    }
    return mat->matrix[x + y * mat->column];
}

void matrix_set(Matrix* mat, size_t y, size_t x, int val){
    if(mat == NULL){
        fprintf(stderr, "Error : cannot set value, matrix given is NULL");
        exit(EXIT_FAILURE);
    }
    if(y >= mat->row){
        fprintf(stderr, "Error : cannot set value, row index out of range\n");
    }else if(x >= mat->column){
        fprintf(stderr, "Error : cannot set value, column index out of range\n");
    }
    mat->matrix[x + y * mat->column] = val;
}

void matrix_display(Matrix* mat){
    for(size_t i = 0; i < (mat->row * mat->column); ++i){
        if(i%(mat->row) == 0){
            printf("\n");
        }
        printf("%d ", mat->matrix[i]);
    }
    printf("\n");
}

void matrix_clear(Matrix* mat){
    for(size_t i = 0; i < (mat->row * mat->column); ++i){
        mat->matrix[i] = 0;
    }
}

Matrix* matrix_addition(Matrix* mat, Matrix* rix){
    if(mat == NULL || rix == NULL){
        fprintf(stderr, "Error : cannot add, one of the matrix given is NULL");
        exit(EXIT_FAILURE);
    }else if((mat->row != rix->row) || (mat->column != rix->column)){
        fprintf(stderr, "Error : cannot add, matrix are not of the same size\n");
        return NULL;
    }
    Matrix* res = matrix_initialization(mat->row, mat->column);
    for(size_t i = 0; i < (mat->row * mat->column); ++i){
        res->matrix[i] = mat->matrix[i] + rix->matrix[i];
    }
    return res;
}

Matrix* matrix_substraction(Matrix* mat, Matrix* rix){
    if(mat == NULL || rix == NULL){
        fprintf(stderr, "Error : cannot substract, one of the matrix given is NULL");
        exit(EXIT_FAILURE);
    }else if((mat->row != rix->row) || (mat->column != rix->column)){
        fprintf(stderr, "Error : cannot substract, matrix are not of the same size\n");
        return NULL;
    }
    Matrix* res = matrix_initialization(mat->row, mat->column);
    for(size_t i = 0; i < (mat->row * mat->column); ++i){
        res->matrix[i] = mat->matrix[i] - rix->matrix[i];
    }
    return res;
}

Matrix* matrix_cubic_multiplication(Matrix* mat, Matrix* rix){
    if(mat == NULL || rix == NULL){
        fprintf(stderr, "Error : cannot substract, one of the matrix given is NULL");
        exit(EXIT_FAILURE);
    }else if((mat->row != rix->row) || (mat->column != rix->column)){
        fprintf(stderr, "Error : cannot substract, matrix are not of the same size\n");
        return NULL;
    }
    Matrix* res = matrix_initialization(mat->row, mat->column);
    for(size_t i = 0; i < mat->column; ++i){
        for(size_t j = 0 ; j < mat->row; ++j){
            for(size_t k = 0; k < mat->row; ++k){
                res->matrix[j + i * mat->column] += mat->matrix[k + i * mat->column] * rix->matrix[j + k * mat->column];
            }
        }
    }
    return res;
}

void matrix_copy(Matrix* example, Matrix* copier){
    if(example == NULL){
        fprintf(stderr, "Error : cannot copy, matrix to be copied from is NULL\n");
        exit(EXIT_FAILURE);
    }else if(example->row != copier->row || example->column != copier->column){
        fprintf(stderr, "Error : cannot copy, matrix are not of the same size\n");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < example->row * example->column; ++i){
        copier->matrix[i] = example->matrix[i];
    }
}

int main(void){
    Matrix* test = matrix_initialization(3, 3);
    Matrix* A = matrix_initialization(3, 3);
    matrix_set(test, 0, 0, 1);
    matrix_set(test, 1, 1, 1);
    matrix_set(test, 2, 2, 1);
    matrix_set(A, 0, 1, 10);
    matrix_set(A, 1, 0, 10);
    matrix_copy(A, test);
    matrix_display(A);
    matrix_display(test);
    matrix_free(A);
    matrix_free(test);
    return 0;
}
