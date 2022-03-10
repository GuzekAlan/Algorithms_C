#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"
#include "list.h"
#include "bst.h"
#include "print_tree.h"

// Program for testing library

#define SORTING
// #define LIST
// #define BST

#define SEPARATOR printf("--------------------------\n");


#ifdef SORTING
int copmare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int c_comp(const void *a, const void *b){
    return (int)(*(char*)a - *(char*)b);
}
#endif

int main(int argc, char **argv){

    //  SORTING
#ifdef SORTING
    const int N = 4;
    int arr[] = {9, 2, 6, 1};
    char arr2[] = {'j', 'p', '2', 'g'};

    insertion_sort(arr, N, sizeof(int), copmare);
    insertion_sort(arr2, N, sizeof(char), c_comp);

    for(int i = 0; i < N; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++){
        printf("%c\t", arr2[i]);
    }
    printf("\n");
#endif
#ifdef LIST
    // LIST
    node *head = int_insert(NULL, 7);
    head = int_insert(head, 213);
    head = delete_all(head);
#endif
#ifdef BST
    // BST
    int i;
    bst *tree = NULL;
    int option = 1;
    int val;
    bst *temp;

    int *values = malloc(sizeof(int)*(argc-1));
    for(i = 1; i < argc; i++) values[i-1] = atoi(argv[i]);  // creating array from input
    if(!values){
        printf("No values inserted!\n");
        exit(0);
    }
    tree = create_bst(values, argc-1);

    while(option){      // Main loop
        SEPARATOR
        printf(
            "Choose an operation on Binary Search tree:\n"
            "[1]\tAdd element to tree\n"
            "[2]\tDelete element from tree\n"
            "[3]\tPrint graphical\n"
            "[4]\tPrint inorder\n"
            "[5]\tPrint preorder\n"
            "[6]\tPrint postorder\n"
            "[7]\tRotate left\n"
            "[8]\tRotate right\n"
            "[9]\tFind successor\n"
            "[10]\tFind predecessor\n"
            "[0]\tEXIT\n"
        );
        scanf("%d", &option);
        SEPARATOR
        switch (option)
        {
        case 0:
            delete_bst(tree);
            exit(0);
        case 1:
            printf("Enter element value: ");
            scanf("%d", &val);
            add_leaf(&tree, NULL, val);
            break;
        case 2:
            printf("Enter element value: ");
            scanf("%d", &val);
            temp = search(tree, val);
            if(!temp) printf("There is no such value in tree!\n");
            else delete_leaf(search(tree, val));
            break;
        case 3:
            print_ascii_tree(tree);
            break;
        case 4: 
            print_bst_inorder(tree);
            printf("\n");
            break;
        case 5: 
            print_bst_preorder(tree);
            printf("\n");
            break;
        case 6: 
            print_bst_postorder(tree);
            printf("\n");
            break;
        case 7:
            printf("Enter branch value you want to rotate: ");
            scanf("%d", &val);
            rotate_left(&tree, search(tree, val));
            break;
        case 8:
            printf("Enter branch value you want to rotate: ");
            scanf("%d", &val);
            rotate_right(&tree, search(tree, val));
            break;
        case 9:
            printf("Which successor do you want to find: ");
            scanf("%d", &val);
            temp = successor(search(tree, val));
            print_leaf(temp);
            printf("\n");
            break;
        case 10:
            printf("Which predecessor do you want to find: ");
            scanf("%d", &val);
            temp = predecessor(search(tree, val));
            print_leaf(temp);
            printf("\n");
            break;
        default:
            printf("Inserted wrong input. Try again!\n");
            option = 1;
            break;
        }
        getchar();
        getchar();
    }
    
#endif


    return 0;
}