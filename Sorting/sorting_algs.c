#include "sorting_algs.h"

void bubble_sort(int *array, unsigned int size){

    for(int i = size - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++)
            if(array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
    }
}

void selection_sort(int *array, unsigned int size) {
    int min;

    for(int i = 0; i < size; i++) {
        min = i;       
        for(int j = i + 1; j < size; j++)
            if(array[j] < array[min])
                min = j;
        swap(&array[i], &array[min]);
    }
}

void insertion_sort(int *array, unsigned int size) {
    int aux;
    
    for(int i = 1; i < size; i++) {
        aux = array[i];
        for(int j = i - 1; j >= 0; j--) {
            if(array[j] > aux)
                array[j + 1] = array[j];
            else {
                array[j + 1] = aux;
                break;
            }
        }
    }
}

void merge_sort(int *array, int start, int end) {

    int middle = start + (end - start) / 2;

    if(start < end) {
        merge_sort(array, start, middle);
        merge_sort(array, middle + 1, end);

        merge(array, start, middle, end);
    }
}

void quick_sort(int *array, int start, int end) {
    if(start < end) {
        int pivot = partition(array, start, end);

        quick_sort(array, start, pivot - 1);
        quick_sort(array, pivot + 1, end);
    }
}

void heap_sort(int *array, int size) {

    for(int i = size / 2 - 1; i >= 0; i--)
        max_heapify(array, size, i);

    for(int i = size - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        max_heapify(array, i, 0);
    }
}

// Internal Functions

void populate_array(int *array, int size) {
    srand(time(0));

    for(int i = 0; i < size; i++)
        array[i] = rand() % 100;
}

void show_array(int *array, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);

    putchar('\n');
}

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void merge(int *array, int start, int middle, int end) {

    int first = middle - start + 1,
        second = end - middle;
    
    // Create and populate 2 temporary arrays
    int temp_1[first], temp_2[second];
    for(int i = 0; i < first; i++)
        temp_1[i] = array[start + i];
    for(int i = 0; i < second; i++)
        temp_2[i] = array[middle + i + 1];

    // Merge the 2 temp arrays
    int i = 0, j = 0, k = start;
    while(i < first && j < second) {
        if(temp_1[i] < temp_2[j]) {
            array[k] = temp_1[i];
            i++;
        } else {
            array[k] = temp_2[j];
            j++;
        }
        k++;
    }

    while(i < first) {
        array[k] = temp_1[i];
        i++; k++;
    }
    while(j < second) {
        array[k] = temp_2[j];
        j++; k++;
    }
}

int partition(int *array, int start, int end) {
    int pivo = array[end]; // Last position is the pivot
    
    int i = start - 1;

    for(int j = start; j <= end; j++) {
        if(array[j] < pivo) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[end]);
    return i + 1;
}


void max_heapify(int* array, int size, int i) {
    int left = 2 * i + 1,
        right = 2 * i + 2,
        greater = i;

    if(left < size && array[left] > array[greater])
        greater = left;

    if(right < size && array[right] > array[greater])
        greater = right;

    if(greater != i) {
        swap(&array[i], &array[greater]);
        max_heapify(array, size, greater);
    }
}

void min_heapify(int *array, int size, int i) {
    int lowest = i,
        left = 2 * i + 1,
        right = 2 * i + 2;

    if(left < size && array[left] < array[lowest])
        lowest = left;

    if(right < size && array[right] < array[lowest])
        lowest = right;

    if(lowest != i) {
        swap(&array[lowest], &array[i]);
        min_heapify(array, size, lowest);
    }
}
