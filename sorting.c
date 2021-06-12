#include "sorting.h"


void swap(void **a, void **b){
     void *temp = a;
     a = b;
     b = temp;
}

void *increment(void *ptr, size_t nbytes){
    char *cptr = (char*)ptr;
    cptr += nbytes;
    return (void*)cptr;
}


void bubble_sort(void *array, size_t nitems, size_t size, int (*cmp)(const void*, const void*)){
    for(size_t i = 1; i <= nitems; i++){
        for(size_t j = 0; i < nitems - i; i++){
            if(cmp(increment(array, j*size), increment(array, (j+1)*size)) > 0) swap(increment(array, j*size), increment(array, (j+1)*size));
        }
    }
}