#ifndef BST_H
#define BST_H

#define REL(a, b) (a)>(b) // Macro for relations

// INTEGER BINARY SEARCH TREE

typedef struct bst_node{
    struct bst_node *left; 
    struct bst_node *right; 
    struct bst_node *parent;
    int value; 
}bst;

#define L(X) ((X)->left)
#define R(X) ((X)->right)
#define P(X) ((X)->parent)
#define V(X) ((X)->value)

#define IS_R(X) (R(P((X)))==(X))

// Leaf handling
bst *create_leaf(bst *parent, int val);
void add_leaf(bst **root, bst *parent, int val);
bst *delete_leaf(bst *leaf);

// Printing
void print_leaf(bst *leaf);
void print_bst_inorder(bst *root);
void print_bst_preorder(bst *root);
void print_bst_postorder(bst *root);

// Tree handling
bst *create_bst(int *values, size_t size);
bst *search(bst *root, int val);
bst *minimum(bst *root);
bst *maximum(bst *root);
bst *successor(bst *root);
bst *predecessor(bst *root);
void rotate_left(bst **root, bst *x);
void rotate_right(bst **root, bst *x);
bst *delete_bst(bst *root);

/**
 * Pretty printing using ASCII
 * LINK: https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
*/
int _print_bst(bst *tree, int is_left, int offset, int depth, char s[20][255]);
void print_bst(bst *tree);



#endif