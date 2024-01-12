#include <stdio.h>
#include <stdlib.h>

#include "sorting_algs.h"

int main() {

    int* array;
    int size;

    printf("Tamanho do array: "); scanf("%d", &size);

    array = (int*)malloc(size * sizeof(int));

    populate_array(array, size);

    printf("Array antes da ordenacao: ");
    show_array(array, size);
 
    heap_sort(array, size);

    printf("Array depois da ordenacao: ");
    show_array(array, size);

    free(array);

    return EXIT_SUCCESS;
}
