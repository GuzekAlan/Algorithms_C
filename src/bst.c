#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


bst *create_leaf(bst *parent, int val){
    bst *leaf = malloc(sizeof(bst));
    if(!leaf){
        printf("Cannot allocate memory for the leaf.\n");
        return NULL;
    }
    V(leaf) = val;
    P(leaf) = parent;
    L(leaf) = NULL;
    R(leaf) = NULL;
    return leaf;
}

void add_leaf(bst **root, bst *parent, int val){
    if(*root){
        if(REL(V(*root), val)) add_leaf(&L(*root), *root, val);
        else add_leaf(&R(*root), *root, val);
    }
    else *root = create_leaf(parent, val);
}

void print_leaf(bst *leaf){         // Content of printf can be changed
    printf("%d\t", V(leaf));
}

void print_bst_inorder(bst *root){
    if(root){
        print_bst_inorder(L(root));
        print_leaf(root);
        print_bst_inorder(R(root));
    }
}

void print_bst_preorder(bst *root){
    if(root){
        print_leaf(root);
        print_bst_preorder(L(root));
        print_bst_preorder(R(root));
    }
}

void print_bst_postorder(bst *root){
    if(root){
        print_bst_postorder(L(root));
        print_bst_postorder(R(root));
        print_leaf(root);
    }
}

bst *delete_bst(bst *root){
    if(L(root)) delete_bst(L(root));
    if(R(root)) delete_bst(R(root));
    free(root);
    return NULL;  
}

bst *delete_leaf(bst *leaf){
    if(L(leaf) == NULL && R(leaf) == NULL){ 
        if(IS_R(leaf)) R(P(leaf)) = NULL;
        else L(P(leaf)) = NULL;
        free(leaf);
        return NULL;
    }
    if(L(leaf) == NULL){
        bst *temp = R(leaf);
        P(temp) = P(leaf);
        if(IS_R(leaf)) R(P(leaf)) = temp;
        else L(P(leaf)) = temp;
        free(leaf);
        return temp;
    }
    if(R(leaf) == NULL){
        bst *temp = L(leaf);
        P(temp) = P(leaf);
        if(IS_R(leaf)) R(P(leaf)) = temp;
        else L(P(leaf)) = temp;
        free(leaf);
        return temp;
    }
    bst *temp = minimum(R(leaf));
    V(leaf) = V(temp);          // Change value and delete another node
    return delete_leaf(temp);
}

bst *search(bst *root, int val){
    while(root && V(root) != val){
        if(V(root) > val) root = L(root);
        else root = R(root);
    }
    if(V(root) == val) return root;
    else return NULL;
}

bst *minimum(bst *root){
    while(L(root)) root = L(root);
    return root;
}

bst *maximum(bst *root){
    while(R(root)) root = R(root);
    return root;
}

bst *successor(bst *root){
    if(R(root)) return minimum(R(root));
    bst *temp = P(root);
    while(temp && root == R(temp)){
        root = temp;
        temp = P(temp);
    }
    return temp;
}

bst *predecessor(bst *root){
    if(L(root)) return maximum(R(root));
    bst *temp = P(root);
    while(temp && root == L(temp)){
        root = temp;
        temp = P(temp);
    }
    return temp;
}

bst *create_bst(int *values, size_t size){
    bst *root = NULL;
    for(int i = 0; i < size; i++){
        add_leaf(&root, NULL, values[i]);
    }
    return root;
}

void rotate_left(bst **root, bst *x){
    bst *y = R(x);
    if(y){                  // check if x have right branch
        R(x) = L(y);
        if(L(y))            // check if y have left branch and if have then assaign x as new parent
            P(L(y)) = x;
        P(y) = P(x);
        if(!P(x))           // if x was root then y will be new root
            *root = y;
        else if(!IS_R(x))   // if x was left child then y will be left child
            L(P(x)) = y;
        else 
            R(P(x)) = y;    // if x was right child then y will be right child
        L(y) = x;
        P(x) = y; 
    }
}

void rotate_right(bst **root, bst *x){
    bst *y = L(x);
    if(y){
        L(x) = R(y);
        if(R(y)) 
            P(R(y)) = x;
        P(y) = P(x);
        if(!P(x)) 
            *root = y;
        else if(IS_R(x)) 
            R(P(x)) = y;
        else 
            L(P(x)) = y;
        R(y) = x;
        P(x) = y; 
    }
}

void print_bst(bst *tree){
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_bst(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}


/**
 * Pretty printing using ASCII
 * LINK: https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
*/
int _print_bst(bst *tree, int is_left, int offset, int depth, char s[20][255]){
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->value);

    int left  = _print_bst(tree->left,  1, offset,                depth + 1, s);
    int right = _print_bst(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}
