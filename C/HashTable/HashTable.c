#include <stdio.h>
#include <stdlib.h>

typedef struct Entry{
    int value;
    char* key;
    struct Entry* next;
} Entry;

typedef struct HashTable{
    Entry** arr;
    size_t length;
} HashTable;

HashTable* initialize_hashtable(size_t len){
    HashTable* res = (HashTable*)malloc(sizeof(*res));
    if(res == NULL){
        fprintf(stderr, "Memory allocation for hash table failed\n");
        exit(EXIT_FAILURE);
    }
    res->arr = (Entry**)malloc(sizeof(*res->arr) * len);
    if(res->arr == NULL){
        fprintf(stderr, "Memory allocation for array failed\n");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < len; ++i){
        res->arr[i] = NULL;
    }
    res->length = len;
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
        ++i;
    }
    return (key_value % len);
}

char* duplicate_key(char* key){
    size_t len = 0;
    size_t i = 0;
    while(key[i] != '\0'){
        ++len;
        ++i;
    }
    i = 0;
    char* duped_key = (char*)malloc(sizeof(*duped_key) * (len+1));
    if(duped_key == NULL){
        fprintf(stderr, "Failed to initialize key in memory\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < len + 1; ++i){
        duped_key[i] = key[i];
    }
    return duped_key;
}

int is_same_string(char* str1, char* str2){
    size_t i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return 0;
        }
        ++i;
    }
    return (str1[i] == str2[i]);
}

void hashtable_insert(HashTable* hash, char* key, int value){
    size_t index = hash_division(key, hash->length);
    if(hash->arr[index] == NULL){
        Entry* res = (Entry*)malloc(sizeof(*res));
        if(res == NULL){
            fprintf(stderr, "Failed to initialize Entry in memory\n");
            exit(EXIT_FAILURE);
        }
        res->value = value;
        res->key = duplicate_key(key);
        res->next = NULL;
        hash->arr[index] = res;
    }else{
        Entry* curr = hash->arr[index];
        if(is_same_string(curr->key, key)){
                curr->value = value;
                return;
            }
        while(curr->next != NULL || is_same_string(curr->key, key)){
            curr = curr->next;
            if(is_same_string(curr->key, key)){
                curr->value = value;
                return;
            }
        }
        Entry* res = (Entry*)malloc(sizeof(*res));
        if(res == NULL){
            fprintf(stderr, "Failed to initialize Entry in memory\n");
            exit(EXIT_FAILURE);
        }
        res->value = value;
        res->key = duplicate_key(key);
        res->next = NULL;
        curr->next = res;
    }
}

int hashtable_get(HashTable* hash, char* key){
    size_t index = hash_division(key, hash->length);
    Entry* curr = hash->arr[index];
    while(curr != NULL){
        if(is_same_string(curr->key, key)){
            return curr->value;
        }
        curr = curr->next;
    }
    printf("Error : key has no initialized value\n");
    exit(EXIT_FAILURE);
}

void display_string(char* str){
    size_t i = 0;
    while(str[i] != '\0'){
        printf("%c", str[i]);
        ++i;
    }
}

void display_linked_list(Entry* first){
    Entry* curr = first;
    while(curr != NULL){
        display_string(curr->key);
        printf(" : %d; ",curr->value);
        curr = curr->next;
    }
}

void hashtable_display(HashTable* hash){
    printf("{");
    for(size_t i = 0; i < hash->length; ++i){
        display_linked_list(hash->arr[i]);
    }
    printf("}\n");
}

void free_entry(Entry* first){
    Entry* curr = first;
    Entry* prev = NULL;
    while(curr != NULL){
        prev = curr;
        curr = curr->next;
        free(prev);
    }
}

void hashtable_free(HashTable* hash){
    for(size_t i = 0; i < hash->length; ++i){
        free_entry(hash->arr[i]);
    }
    free(hash->arr);
    free(hash);
}




int main(void){
    HashTable* htbl = initialize_hashtable(307);
    hashtable_insert(htbl, "insert", 2);
    hashtable_insert(htbl, "get", 5);
    hashtable_insert(htbl, "delete", 125);
    hashtable_insert(htbl, "star", 21);
    hashtable_insert(htbl, "moon", 12);
    hashtable_insert(htbl, "moon", 65);
    hashtable_display(htbl);
    hashtable_free(htbl);
    return 0;
}