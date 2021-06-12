#include <stdio.h>
#include <stdlib.h>
#ifndef LIST_H
#define LIST_H

typedef struct tnode{
    size_t size;
    enum type{Float, Char, Int};
    struct tnode *next;
    void *value;
}node;
typedef unsigned char byte;


// Useful functions
int compare(void *a, void *b, size_t size);



// Adding elements
node *insert_begin(node *head, void *val, size_t size);
node *int_insert(node *head, int val);



// Deleting elements
node *delete_element(node *head, void *val, size_t size);
node *delete_all(node *head);



#endif