#include "sorting.h"


void swap(void *a, void *b, size_t size){        
     byte *x = (byte*)a;
     byte *y = (byte*)b;
     byte temp;
     for(int i = 0; i < size; i++){
        temp = *(x+i);
        *(x+i) = *(y+i);
        *(y+i) = temp;
     }
}

void *increment(void *ptr, size_t nbytes){
    byte *bptr = (byte*)ptr;
    bptr += nbytes;
    return (void*)bptr;
}


void bubble_sort(void *array, size_t nitems, size_t size, int (*cmp)(const void*, const void*)){
    for(size_t i = 0; i < nitems; i++){
        for(size_t j = 0; j < nitems - i -1; j++){
            if(cmp(increment(array, j*size), increment(array, (j+1)*size)) > 0) swap(increment(array, j*size), increment(array, (j+1)*size), size);
        }
    }
}