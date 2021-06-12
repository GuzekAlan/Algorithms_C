#include <stdio.h>
#include <stdlib.h>
#ifndef LIST_H
#define LIST_H

typedef struct tnode{
    size_t size;
    struct tnode *next;
    void *value;
}node;

// Adding elements
node *insert_begin(node*, void*, size_t size);
node *int_insert(node*, int);



// Deleting elements
node *delete_all(node*);



#endif