#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>

typedef unsigned char byte;

void swap(void *a, void *b, size_t);
void *increment(void *ptr, size_t nbytes);

void bubble_sort(void *array, size_t nitems, size_t size, int (*cmp)(const void*, const void*));

#endif