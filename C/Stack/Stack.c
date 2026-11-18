#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

Stack* initialize_stack(){
    Stack* res = (Stack*)malloc(sizeof(Stack));
    res->size = 0;
    res->head = NULL;
    res->tail = NULL;
    return res;
}

void stack_empty(Stack* stk){
    Node* curr = stk->head;
    Node* prec = NULL;
    while(curr != NULL){
        prec = curr;
        curr = curr->next;
        free(prec);
    }
    stk->size = 0;
    stk->head = NULL;
    stk->tail = NULL;
}

size_t stack_size(Stack* stk){
    return stk->size;
}

int stack_head(Stack* stk){
    if(stk->size == 0){
        printf("Error : Stack is empty\n");
    }
    return stk->head->val;
}

void stack_push(Stack* stk, int value){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->val = value;
    tmp->next = stk->head;
    stk->head = tmp;
    stk->size++;
}

void stack_pop(Stack* stk){
    if(stk->size == 0){
        printf("Error : Cannot pop, stack is empty\n");
    }
    Node* tmp = stk->head;
    stk->head = tmp->next;
    free(tmp);
    stk->size--;
}

int stack_is_empty(Stack* stk){
    return stk->size == 0;
}

void stack_print(Stack* stk){
    Node* curr = stk->head;
    if(curr == NULL){
        printf("{}\n");
        return;
    }
    printf("{");
    while(curr->next != NULL){
        printf("%d, ", curr->val);
        curr = curr->next;
    }
    printf("%d}\n", curr->val);
}

int is_same_stack(Stack* stk1, Stack* stk2){
    if(stk1 == stk2){
        return 1;
    }
    if(stk1->size != stk2->size){
        return 0;
    }
    Node* curr1 = stk1->head;
    Node* curr2 = stk2->head;
    while(curr1 != NULL || curr2 != NULL){
        if(curr1->val != curr2->val){
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return 1;
}

