#include <stdio.h>
#include <stdlib.h>


typedef struct String{
    char* string;
    size_t length;
} String;

String* string_initialization(char* str){
    if(str == NULL){
        fprintf(stderr, "Error : cannot initialize string, passed argument is NULL\n");
        exit(EXIT_FAILURE);
    }
    size_t n = 0;
    while(str[n] != '\0'){
        ++n;
    }
    if(n == 0){
        fprintf(stderr, "Error : cannot initialise empty string\n");
        exit(EXIT_FAILURE);
    }
    String* res = (String*)malloc(sizeof(*res));
    if(res == NULL){
        fprintf(stderr, "Error : string structure allocation failed due to memory alloction failing");
        exit(EXIT_FAILURE);
    }
    res->string = (char*)malloc(sizeof(*res->string) *(n+1));
    res->length = n;
    if(res->string == NULL){
        fprintf(stderr, "Error : string allocation failed due to memory alloction failing");
        exit(EXIT_FAILURE);
    }
    for(size_t k = 0; k < n; ++k){
        res->string[k] = str[k];
    }
    res->string[n] = '\0';
    return res;
}

void string_free(String* str){
    free(str->string);
    free(str);
}

void string_copy(String* str1, String* str2){
    if(str1 == NULL ||str2 == NULL){
        fprintf(stderr, "Error : couldn't copy string, one of the argument is NULL\n");
        exit(EXIT_FAILURE);
    }
    char* tmp = (char*)malloc(sizeof(*tmp) * (str2->length + 1));
    if(tmp == NULL){
        fprintf(stderr, "Error : couldn't copy string, the memory allocation of new string failed\n");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < str2->length; ++i){
        tmp[i] = str2->string[i] + 1;
    }
    tmp[str2->length] = '\0';
    free(str1->string);
    str1->string = tmp;
    str1->length = str2->length;
}

void string_replace(String* str, char* rep){
    if(str == NULL || rep == NULL){
        fprintf(stderr, "Error : can't replace string, one of the argument is NULL\n");
        exit(EXIT_FAILURE);
    }
    size_t n = 0;
    while(rep[n] != '\0'){
        ++n;
    }
    if(n == 0){
        fprintf(stderr, "Error : can't replace string, copied string is empty\n");
        exit(EXIT_FAILURE);
    }
    char* tmp = (char*)malloc(sizeof(*tmp) * (n+1));
    if(tmp == NULL){
        fprintf(stderr, "Error : cannot replace string, memory allocation for new string failed\n");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < n; ++i){
        tmp[i] = rep[i];
    }
    tmp[n] = '\0';
    str->length = n;
    str->string = tmp;
}

int string_is_similar(String* str1, String* str2){
    if(str1 == NULL ||str2 == NULL){
        fprintf(stderr, "Error : cannot compare strings, one of the argument is NULL\n");
        exit(EXIT_FAILURE);
    }
    if(str1->length != str2->length){
        return 0;
    }
    if(str1 == str2){
        return 1;
    }
    for(size_t i = 0; i < str1->length; ++i){
        if(str1->string[i] != str2->string[i]){
            return 0;
        }
    }
    return 1;
}

size_t string_get_length(String* str){
    if(str == NULL){
        fprintf(stderr, "Error : can't get string length, argument is NULL\n");
        exit(EXIT_FAILURE);
    }
    return str->length;
}

char* string_get_str(String* str){
    if(str == NULL){
        fprintf(stderr, "Error : can't get string, argument is NULL\n");
        exit(EXIT_FAILURE);
    }
    return str->string;
}

int string_is_empty(String* str){
    if(str == NULL){
        fprintf(stderr, "Error : cannot check if string is empty, argument given is NULL\n");
        exit(EXIT_FAILURE);
    }
    return str->length == 0;
}

char string_get_at(String* str, size_t k){
    if(str == NULL){
        fprintf(stderr, "Error : cannot get character at position k=%lld, argument given is NULL\n", k);
        exit(EXIT_FAILURE);
    }
    if(k >= str->length){
        fprintf(stderr, "Error : cannot get character at position k=%lld, index out of range\n", k);
        exit(EXIT_FAILURE);
    }
    return str->string[k];
}

void string_caesar(String* str, int n){
    if(str == NULL){
        fprintf(stderr,"Error : cannot apply caesar, string given is NULL\n");
        exit(EXIT_FAILURE);
    }
    if(n < 0){
        int r = (-n)%26;
        n = 26 - r;
    }else{
        n = n%26;
    }
    if(n == 0){
        return;
    }
    unsigned int tmp = 0;
    for(size_t i = 0; i < str->length; ++i){
        tmp = str->string[i];
        if(tmp >= 65 && tmp <= 90){
            tmp += n;
            if(tmp > 90){
                tmp = tmp - 26;
            }
            str->string[i] = tmp;
        }else if(tmp >= 97 && tmp <= 122){
            tmp += n;
            if(tmp > 122){
                tmp = tmp - 26;
            }
            str->string[i] = tmp;
        }
    }
}

int string_is_palindrom(String* str){
    if(str == NULL){
        fprintf(stderr,"Error : cannot check if it is palindrome, string given is NULL\n");
        exit(EXIT_FAILURE);
    }
    size_t n = str->length;
    for(size_t i = 0; i < (n/2 - 1); ++i){
        if(str->string[i] != str->string[n - i - 1]){
            return 0;
        }
    }
    return 1;
}

int main(void){
    String* test = string_initialization("Hello world!");
    string_free(test);
    return 0;
}