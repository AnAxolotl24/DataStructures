#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct DArray{
    int* arr;
    size_t capacity;
    size_t size;
} DArray;

DArray* initialize_array();
void resize_array(DArray* darr);
int get_arr_val(DArray* darr, size_t k);
int get_first_arr(DArray* darr);
int get_last_arr(DArray* darr);
void addlast_arr(DArray* darr, int val);
void pop_back_arr(DArray* darr);
void set_at(DArray* darr, size_t k, int val);
int get_at(DArray* darr, size_t k);
void insert_at(DArray* darr, size_t k, int val);
void remove_at_arr(DArray* darr, size_t k);
size_t get_arr_capacity(DArray* darr);
size_t get_arr_size(DArray* darr);
size_t get_arr_size(DArray* darr);
int is_empty_arr(DArray* darr);
void clear(DArray* darr);
int* get_data_arr(DArray* darr);
void reserve(DArray* darr, size_t n);
void shrink_to_fit_arr(DArray* darr);
void free_arr(DArray* darr);
void print_arr(DArray* darr);
int is_similar(DArray* darr1, DArray* darr2);

#endif