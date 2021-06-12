#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node *insert_begin(node *head, void *val, size_t size){
    node *temp = malloc(sizeof(node));
    if(!temp){
        printf("Cannot allocate memory\n");
        return head;
    }
    temp->value = val;
    temp->size = size;
    temp->next = head;
    return temp;
}

node *int_insert(node *head, int val){
    int *temp = malloc(sizeof(int));
    *temp = val;
    head = insert_begin(head, temp, sizeof(int));
}




node *delete_all(node *head){
    node *next;
    while(head){
        next = head->next;
        free(head->value);
        free(head);
        head = next;
    }
    return NULL;
}