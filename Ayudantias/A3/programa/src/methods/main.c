#include <stdio.h>
#include <stdlib.h>

#include "heaps.h"

void valid_heap(Heap* heap){
    printf("\n");
    if (verify_max_heap(heap)){
        printf("It's a heap!\n");
    } else {
        printf("It's not a heap\n");
    }
}

int main1(int argc, char* argv[]){
    int length = argc - 1;

    printf("%s\n", argv[0]);
    int* array = malloc(sizeof(int)*length);
    for (int i = 1; i <= length; ++i) {
        array[i-1] = atoi(argv[i]);
    }

    show_array(array, length);

    // armamos el heap con el array, insertando de a uno los elementos
    Heap* heap = build_heap_by_insertion(array, length);

    show_heap(heap);
    valid_heap(heap);

    heap_sort(heap);
    valid_heap(heap);

    //free(array);
    destroy_heap(heap);

    return 0;
}


int main(int argc, char* argv[]){
    int length = argc - 1;

    printf("%s\n", argv[0]);
    int* array = malloc(sizeof(int)*length);
    for (int i = 1; i <= length; ++i) {
        array[i-1] = atoi(argv[i]);
    }

    show_array(array, length);

    // armamos el heap con el array, insertando de a uno los elementos
    Heap* heap = build_heap_by_heapify(array, length);

    show_heap(heap);
    valid_heap(heap);

    heap_sort(heap);
    valid_heap(heap);

    //free(array);
    destroy_heap(heap);

    return 0;
}