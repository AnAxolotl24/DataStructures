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
    for(size_t i = 0; i < len; ++i){
        res->arr[i] = -1;
    }
    return res;
}

size_t pow_rec(size_t x, size_t n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 1){
        size_t a = pow_rec(x, (n-1)/2);
        return a*a*x;
    }else{
        size_t a = pow_rec(x, n/2);
        return a*a;
    }
}

size_t hash_division(char* key, size_t len){
    size_t key_value = 0;
    size_t i = 0;
    while(key[i] != '\0'){
        key_value += key[i] * pow_rec(128, i);
    }
    return key_value % len;
}

void hashtable_insert(HashTable* hash,char* key, int value){
    hash->arr[hash_division(key, hash->length)] = value;
}


int main(void){
    printf("Hello world!\n");
    return 0;
}