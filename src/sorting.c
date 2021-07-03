#include "sorting.h"
#include <stdlib.h>
// Functions for universl sorting

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

void copy(void *src, void *dest, size_t size){
    byte *s = (byte*)src;
    byte *d = (byte*)dest;
    for(int i = 0; i < size; i++)
        *(d+i) = *(s+i);
}

void *increment(void *ptr, size_t nbytes){
    byte *bptr = (byte*)ptr;
    bptr += nbytes;
    return (void*)bptr;
}

// Bubble sort


void bubble_sort(void *array, size_t nitems, size_t size, int (*cmp)(const void*, const void*)){
    for(size_t i = 0; i < nitems; i++){
        for(size_t j = 0; j < nitems - i -1; j++){
            if(cmp(increment(array, j*size), increment(array, (j+1)*size)) > 0) swap(increment(array, j*size), increment(array, (j+1)*size), size);
        }
    }
}

// Insertion sort
// Not working (didn't go into while even once)
void insertion_sort(void *array, size_t ntimes, size_t size, int (*cmp)(const void*, const void*)){
    int i, j;
    void *key = malloc(size);
    for(j = 1; j < ntimes; j++){
        copy(array+j, key, size);
        i = j-1;
        while(i > 0 && cmp(array+j, key)){
            copy(array+i, array+i+1, size);
            i--;
        }
        copy(array+i+1, key, size);
    }
    free(key);
}

// Heap sort