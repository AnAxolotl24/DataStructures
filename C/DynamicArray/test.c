#include <stdio.h>
#include <assert.h>
#include "DynamicArray.h"

void test_reserve(){
    DArray* test = initialize_array();
    reserve(test, 3);
    assert((test->capacity == 3) && (test->size == 0));

    test->arr[0] = 0;
    test->arr[1] = 1;
    test->size = 2;
    reserve(test, 10);
    assert((test->capacity == 10) && (test->size == 2) && (test->arr[0] == 0) && (test->arr[1] == 1));
    free_arr(test);
}

void test_addlast(){
    DArray* test = initialize_array();
    DArray* res = initialize_array();
    reserve(res, 5);
    res->size = 5;
    res->arr[0] = 1;
    res->arr[1] = 2;
    res->arr[2] = 3;
    res->arr[3] = 4;
    res->arr[4] = 5;
    addlast_arr(test, 1);
    addlast_arr(test, 2);
    addlast_arr(test, 3);
    addlast_arr(test, 4);
    addlast_arr(test, 5);
    assert(is_similar(test, res));

    clear(test);
    clear(res);
    assert(is_similar(test, res));

    res->arr[0] = 15;
    res->size = 1;
    addlast_arr(test, 15);
    assert(is_similar(test, res));
    free_arr(test);
    free_arr(res);
}

void test_pop_back(){
    DArray* test = initialize_array();
    DArray* res = initialize_array();
    addlast_arr(test, 10);
    addlast_arr(test, 20);
    addlast_arr(res, 10);
    addlast_arr(test, 30);
    addlast_arr(test, 40);
    addlast_arr(res, 20);
    assert(!is_similar(test, res));
    
    pop_back_arr(test);
    pop_back_arr(test);
    assert(is_similar(test, res));
    free_arr(test);
    free_arr(res);
}

void test_get_val(){
    DArray* test = initialize_array();
    addlast_arr(test, 4);
    addlast_arr(test, 8);
    addlast_arr(test, 2);
    addlast_arr(test, 5);
    assert((get_arr_val(test, 3) == 5) && (get_arr_val(test, 2) == 2));
    free_arr(test);
}

void test_get_first(){
    DArray* test = initialize_array();
    addlast_arr(test, 4);
    assert(get_first_arr(test) == 4);

    addlast_arr(test, 4);
    addlast_arr(test, 7);
    addlast_arr(test, 1);
    addlast_arr(test, 9);
    assert(get_first_arr(test) == 4);
    free_arr(test);
}

void test_get_last(){
    DArray* test = initialize_array();
    addlast_arr(test, 4);
    assert(get_last_arr(test) == 4);

    addlast_arr(test, 4);
    addlast_arr(test, 7);
    addlast_arr(test, 1);
    addlast_arr(test, 9);
    assert(get_last_arr(test) == 9);
    free_arr(test);
}

void test_set_at(){
    DArray* test = initialize_array();
    DArray* res = initialize_array();
    addlast_arr(test, 10);
    addlast_arr(res, 10);
    addlast_arr(test, 20);
    addlast_arr(test, 1000);
    addlast_arr(test, 120);
    addlast_arr(res, 20);
    addlast_arr(res, 30);
    addlast_arr(res, 40);
    addlast_arr(res, 50);
    set_at_arr(test, 2, 30);
    set_at_arr(test, 3, 40);
    assert(!is_similar(res, test));

    set_at_arr(test, 4, 50);
    assert(is_similar(res, test));
    free_arr(test);
    free_arr(res);
}

void test_get_at(){
    DArray* test = initialize_array();
    addlast_arr(test, 2);
    addlast_arr(test, 3);
    addlast_arr(test, 5);
    addlast_arr(test, 7);
    addlast_arr(test, 11);

    assert(!(get_at_arr(test, 3) == 5));
    assert(get_at_arr(test, 4) == 11);
    free_arr(test);
}

void test_insert_at(){
    DArray* test = initialize_array();
    addlast_arr(test, 2);
    addlast_arr(test, 3);
    addlast_arr(test, 5);
    addlast_arr(test, 7);
    addlast_arr(test, 11);

    assert(!(get_at_arr(test, 3) == 25));

    insert_at_arr(test, 3, 25);
    assert(get_at_arr(test, 3) == 25);
    free_arr(test);
}

void test_remove_at(){
    DArray* test = initialize_array();
    addlast_arr(test, 2);
    addlast_arr(test, 3);
    addlast_arr(test, 5);
    addlast_arr(test, 7);
    addlast_arr(test, 11);

    assert(get_at_arr(test, 3) == 7);

    remove_at_arr(test, 3);
    assert(get_at_arr(test, 3) == 11);
    free_arr(test);
}

void test_get_capacity(){
    DArray* test = initialize_array();
    assert(get_arr_capacity(test) == 8);

    addlast_arr(test, 1);
    addlast_arr(test, 2);
    addlast_arr(test, 3);
    addlast_arr(test, 4);
    addlast_arr(test, 5);
    addlast_arr(test, 6);
    addlast_arr(test, 7);
    addlast_arr(test, 8);
    addlast_arr(test, 9);
    assert(get_arr_capacity(test) == 16);

    reserve(test, 20);
    assert(get_arr_capacity(test) == 20);

    clear(test);
    assert(get_arr_capacity(test) == 20);
    free_arr(test);
}

void test_get_size(){
    DArray* test = initialize_array();
    assert(get_arr_capacity(test) == 8);

    addlast_arr(test, 1);
    addlast_arr(test, 2);
    addlast_arr(test, 3);
    addlast_arr(test, 4);
    addlast_arr(test, 5);
    addlast_arr(test, 6);
    addlast_arr(test, 7);
    addlast_arr(test, 8);
    addlast_arr(test, 9);
    assert(get_arr_size(test) == 9);

    reserve(test, 20);
    assert(get_arr_size(test) == 9);

    clear(test);
    assert(get_arr_size(test) == 0);
    free_arr(test);
}

void test_is_empty(){
    DArray* test = initialize_array();
    assert(is_empty_arr(test) == 1);

    addlast_arr(test, 3);
    addlast_arr(test, 9);

    assert((is_empty_arr(test) == 0));

    clear(test);
    assert(is_empty_arr(test) == 1);
    free_arr(test);
}

void test_get_data(){
    DArray* test = initialize_array();
    addlast_arr(test, 4);
    addlast_arr(test, 16);
    addlast_arr(test, 64);
    int* res = get_data_arr(test);
    int acc = 4;
    for(int i = 0; i < 3; ++i){
        assert(res[i] == acc);
        acc = acc << 2;
    }
    free_arr(test);
}

void test_shrink_to_fit(){
    DArray* test = initialize_array();
    assert(get_arr_capacity(test) == 8);

    addlast_arr(test, 2);
    addlast_arr(test, 4);
    shrink_to_fit_arr(test);
    assert(get_arr_capacity(test) == 2);

    addlast_arr(test, 8);
    addlast_arr(test, 16);
    shrink_to_fit_arr(test);
    assert(get_arr_capacity(test) == 4);

    clear(test);
    shrink_to_fit_arr(test);
    assert(get_arr_capacity(test) == 0);
    free_arr(test);
}

int main(void){
    test_addlast();
    test_reserve();
    test_get_val();
    test_get_first();
    test_get_last();
    test_pop_back();
    test_set_at();
    test_get_at();
    test_insert_at();
    test_remove_at();
    test_get_capacity();
    test_get_size();
    test_is_empty();
    test_get_data();
    test_shrink_to_fit();
    printf("All tests passed\n");
    return 0;
}