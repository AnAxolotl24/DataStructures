#ifndef STACK_H
#define STACK_H

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct Stack{
    size_t size;
    Node* head;
    Node* tail;
} Stack;

Stack* initialize_stack();
void stack_empty(Stack* stk);
size_t stack_size(Stack* stk);
int stack_head(Stack* stk);
void stack_push(Stack* stk, int value);
void stack_pop(Stack* stk);
int stack_is_empty(Stack* stk);
void stack_print(Stack* stk);

#endif