#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* arr;
    size_t length;
} HashTable;

HashTable* initialize_hashtable(size_t len){
    HashTable* res = (HashTable*)malloc(sizeof(HashTable));
    if(res == NULL){
        fprintf(stderr, "Memory allocation for hash table failed\n");
        exit(EXIT_FAILURE);
    }
    res->arr = (int*)malloc(sizeof(int) * len);
    if(res->arr == NULL){
        fprintf(stderr, "Memory allocation for array failed\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < len; ++i){
        res->arr[i] = -1;
    }
    return res;
}


int main(void){
    printf("Hello world!\n");
    return 0;
}