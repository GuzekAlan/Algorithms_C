#ifndef BST_H
#define BST_H

#define REL(a, b) (a)>(b) // Macro for relations

// INTEGER BINARY SEARCH TREE

/** structure of binary search tree with integer value */
typedef struct bst_node{
    struct bst_node *left; 
    struct bst_node *right; 
    struct bst_node *parent;
    int value; 
}bst;

/** Marcos which are useful when working on BST */
#define L(X) ((X)->left)
#define R(X) ((X)->right)
#define P(X) ((X)->parent)
#define V(X) ((X)->value)

#define IS_R(X) (R(P((X)))==(X))

// LEAF HANDLING
/** Creates elemt of bst sturcture
 * @param parent parent of leaf which you make 
 * @param val value to assign to the leaf
 * @return pointer to created leaf
*/
bst *create_leaf(bst *parent, int val);
/** adds leaf to tree in appropriate place (using recurrency)
 * @param root pointer to root of tree (which is also a pointer)
 * @param parent parent of root
 * @param val value which we want to insert in our tree
*/
void add_leaf(bst **root, bst *parent, int val);
/** deletes chosen node(branch) (using recurrency)
 * @param leaf pointer to node you want to delete
 * @return pointer to dealocated memory
*/
bst *delete_leaf(bst *leaf);

// PRINTING 
/** prints on screen one node (with newline)
 * @param leaf node which we are printing
*/
void print_leaf(bst *leaf);
/** prints tree on screen in specific order
 * @param root root of printinted tree
*/
void print_bst_inorder(bst *root);
void print_bst_preorder(bst *root);
void print_bst_postorder(bst *root);

// Tree handling
/** creates BST from array of int
 * @param values array of values 
 * @param size size of array values
 * @return pointer to root of tree
*/
bst *create_bst(int *values, size_t size);
/** Binary search on tree
 * @param root root of tree we want to search
 * @param val value which we want to search
 * @return pointer to node storing searched value (NULL if there is no such value in tree)
*/
bst *search(bst *root, int val);
/** finding minimum/makximum value of tree
 * @param root pointer to root of tree (can be subtree)
 * @return pointer to node storing minimum/maximum value of tree
*/
bst *minimum(bst *root);
bst *maximum(bst *root);
/** finding predecessor/successor of tree (can be subtree)
 * @param root root of tree which predecessor/successor we want to find
 * @return pointer to predecessor/successor
*/
bst *successor(bst *root);
bst *predecessor(bst *root);
/** rotating tree
 * @param root pointer to root of tree
 * @param x pointer to node on which we want to rotate
*/
void rotate_left(bst **root, bst *x);
void rotate_right(bst **root, bst *x);
/** Freeing allocated by tree memory
 * @param root root of tree we want to deallocate
 * @return NULL
*/
bst *delete_bst(bst *root);

/**
 * Pretty printing using ASCII (max height of tree is 20)
 * LINK: https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
*/
#define COMPACT     // mode of printing Tree
int _print_bst(bst *tree, int is_left, int offset, int depth, char s[20][255]);
void print_bst(bst *tree);



#endif