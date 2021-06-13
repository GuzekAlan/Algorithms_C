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
    printf("%d\n", V(leaf));
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
        print_bst_inorder(L(root));
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
    return root;
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

void rotate_left(bst **root, bst *x){       // Don't know how this work
    bst *y = R(x);
    R(x) = L(y);
    if(L(y)) P(L(y)) = x;
    P(y) = P(x);
    if(!P(x)) *root = y;
    else if(!IS_R(x)) L(P(x)) = y;
    else R(P(x)) = y;
    L(y) = x;
    P(x) = y;

}
