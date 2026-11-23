#ifndef HASHTABLE_C
#define HASHTABLE_C

#include <stdlib.h>
#include <stdio.h>

typedef struct Entry{
    int value;
    char* key;
    struct Entry* next;
} Entry;

typedef struct HashTable{
    Entry** arr;
    size_t length;
} HashTable;

HashTable* initialize_hashtable(size_t len);
size_t pow_rec(size_t x, size_t n);
size_t hash_division(char* key, size_t len);
int power_of_2_of_uint(size_t x);
size_t hash_multiplication(char* key, size_t len);
char* duplicate_key(char* key);
int is_same_string(char* str1, char* str2);
void hashtable_insert(HashTable* hash, char* key, int value);
int hashtable_get(HashTable* hash, char* key);
void display_string(char* str);
void display_linked_list(Entry* first);
void hashtable_display(HashTable* hash);
void free_entry(Entry* first);
void hashtable_free(HashTable* hash);
int hashtable_is_empty(HashTable* hash);
int hashtable_get_size(HashTable* hash);
int hashtable_contains(HashTable* hash, char* key);
void hashtable_remove(HashTable* hash, char* key);
void count_linked_list_length(Entry* head, size_t* acc);
float hashtable_get_load_factor(HashTable* hash);

#endif