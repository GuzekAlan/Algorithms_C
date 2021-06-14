#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"
#include "list.h"
#include "bst.h"
#include "print_tree.h"

// Program for testing library

#define N 4
#define SEPARATOR (printf("--------------------------\n"))

int copmare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int c_comp(const void *a, const void *b){
    return (int)(*(char*)a - *(char*)b);
}

int main(int argc, char **argv){

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
    SEPARATOR;

    // LIST
    node *head = int_insert(NULL, 7);
    head = int_insert(head, 213);
    head = delete_all(head);
    SEPARATOR;

    SEPARATOR;
    // BST
    int vals[] = {10, 3, 5, 4, 20, 25, 15, 12, 16, 23, 30};
    bst *tree = create_bst(vals, sizeof(vals)/sizeof(*vals));
    print_ascii_tree(tree);
    bst *branch = search(tree,20);
    rotate_left(&tree, branch);     // rotation doesn't work
    print_ascii_tree(tree);
    delete_leaf(search(tree, 20));
    print_ascii_tree(tree);
    
    delete_bst(tree);
    
    return 0;
}