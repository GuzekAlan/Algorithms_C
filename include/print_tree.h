#ifndef __PRINT__TREE_H
#define __PRINT__TREE_H
#include "bst.h"

typedef struct asciinode_struct
{
    struct asciinode_struct *left, *right;

    //length of the edge from this node to its children
    int edge_length;

    int height;

    int lablen;

    //-1=I am left, 0=I am root, 1=right
    int parent_dir;

    //max supported unit32 in dec, 10 digits max
    char label[11];
} asciinode;

void print_level(asciinode *node, int x, int level);
void compute_edge_lengths(asciinode *node);
asciinode *build_ascii_tree_recursive(bst *t);
asciinode *build_ascii_tree(bst *t);
void free_ascii_tree(asciinode *node);
void compute_lprofile(asciinode *node, int x, int y);
void compute_rprofile(asciinode *node, int x, int y);
void print_ascii_tree(bst *t);

#endif