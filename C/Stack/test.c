#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Stack.h"

void test_similar(){
    Stack* test1 = initialize_stack();
    Stack* test2 = initialize_stack();
    Stack* test3 = initialize_stack();
    stack_push(test1, 2);
    stack_push(test2, 2);
    stack_push(test1, 6);
    stack_push(test2, 6);
    stack_push(test1, 9);
    stack_push(test2, 9);
    stack_push(test3, 2);
    stack_push(test3, 6);
    assert(is_same_stack(test1, test1));
    assert(is_same_stack(test1, test2));
    assert(!is_same_stack(test1, test3));
    free_stack(test1);
    free_stack(test2);
    free_stack(test3);
}

void test_empty_stack(){
    Stack* test = initialize_stack();
    stack_push(test, 1);
    stack_push(test, 2);
    stack_push(test, 3);
    assert(!(test->head == NULL && test->tail == NULL && test->size == 0));

    empty_stack(test);
    assert((test->head == NULL && test->tail == NULL && test->size == 0));
    free_stack(test);
}

void test_stack_size(){
    Stack* test = initialize_stack();
    stack_push(test, 5);
    stack_push(test, 4);
    stack_push(test, 3);
    stack_push(test, 2);
    stack_push(test, 1);
    assert(stack_size(test) == 5);

    empty_stack(test);
    assert(test->size == 0);
    free_stack(test);
}

void test_stack_head(){
    Stack* test = initialize_stack();
    stack_push(test, 1);
    assert(stack_head(test) == 1);
    
    stack_push(test, 5);
    assert(stack_head(test) == 5);
    free_stack(test);
}

void test_stack_pop(){
    Stack* test = initialize_stack();
    stack_push(test, 25);
    stack_push(test, 50);
    assert(stack_head(test) == 50 && stack_size(test) == 2);

    stack_pop(test);
    assert(stack_head(test) == 25 && stack_size(test) == 1);
    free_stack(test);
}

void test_stack_is_empty(){
    Stack* test = initialize_stack();
    assert(stack_is_empty(test) == 1);

    stack_push(test, 5);
    stack_push(test, 7);
    assert(stack_is_empty(test) == 0);

    stack_pop(test);
    assert(stack_is_empty(test) == 0);

    empty_stack(test);
    assert(stack_is_empty(test) == 1);
    free_stack(test);
}

int main(void){
    test_similar();
    test_empty_stack();
    test_stack_size();
    test_stack_head();
    test_stack_pop();
    test_stack_is_empty();
    printf("All stack test passed\n");
    return 0;
}