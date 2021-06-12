#include <stdlib.h>
#include <stdio.h>
#include "src/sorting.h"
#include "src/list.h"

#define N 4

int copmare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int c_comp(const void *a, const void *b){
    return (int)(*(char*)a - *(char*)b);
}

int main(void){

    //  SORTING
    int arr[] = {9, 6, 2, 1};
    char arr2[] = {'j', 'p', '2', 'g'};

    bubble_sort(arr, N, sizeof(int), copmare);
    bubble_sort(arr2, N, sizeof(char), c_comp);

    for(int i = 0; i < N; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++){
        printf("%c\t", arr2[i]);
    }
    printf("\n");

    // LIST
    node *head = int_insert(NULL, 7);
    head = int_insert(head, 213);
    head = delete_all(head);

    
    return 0;
}