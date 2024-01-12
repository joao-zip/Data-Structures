#ifndef SORTING_ALGS_H
#define SORTING_ALGS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sorting Methods

void bubble_sort(int*, unsigned int);
void selection_sort(int*, unsigned int);
void insertion_sort(int*, unsigned int);

void merge_sort(int*, int, int);
void quick_sort(int*, int, int);
void heap_sort(int*, int);

// Internal functions

void populate_array(int*, int);
void show_array(int*, int);
void swap(int*, int*);

void merge(int*, int, int, int);
int partition(int*, int, int);
void max_heapify(int*, int, int);
void min_heapify(int*, int, int);

#endif // !SORTING_ALGS_H
