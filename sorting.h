#include <stdio.h>
#include <stdlib.h>
#ifndef SORTING_H
#define SORTING_H

void swap(void **a, void **b);
void *increment(void *ptr, size_t nbytes);
void bubble_sort(void *array, size_t nitems, size_t size, int (*cmp)(const void*, const void*));

#endif