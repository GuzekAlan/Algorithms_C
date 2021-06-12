#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int compare(void *a, void *b, size_t size){
    byte *x = (byte*)a;
    byte *y = (byte*)b;
    for(int i = 0; i < size; i++){
        if(*(x+i) != *(y+i)) return 0;
    }
    return 1;
}


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


node *delete_element(node *head, void *val, size_t size){
    if(!head) return NULL;
    if(compare(head->value, val, size)) return head;
    return delete_element(head->next, val, size);
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