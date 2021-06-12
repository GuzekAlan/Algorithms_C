#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"

#define N 6

int copmare(const void *a, const void *b){
    return (int*)a-(int*)b;
}


int main(void){

    int arr[] = {2, 1, 3, 7, 6, 9};

    bubble_sort(arr, N, sizeof(int), copmare);

    for(int i = 0; i < N; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}