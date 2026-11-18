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
}



int main(void){
    test_similar();
    return 0;
}