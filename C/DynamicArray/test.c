#include <stdio.h>
#include <assert.h>
#include "DynamicArray.h"

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

int main(void){
    test_addlast();
    return 0;
}