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
}

void test_get_val(){
    DArray* test = initialize_array();
    addlast_arr(test, 4);
    addlast_arr(test, 8);
    addlast_arr(test, 2);
    addlast_arr(test, 5);
    assert((get_arr_val(test, 3) == 5) && (get_arr_val(test, 2) == 2));

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
}


int main(void){
    test_addlast();
    test_reserve();
    test_get_val();
    test_get_first();
    return 0;
}