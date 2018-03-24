#include <stdio.h>
#include <stdlib.h>

#include "heaps.h"

int main(int argc, char* argv[]){
    int length = argc - 1;

    int* array = malloc(sizeof(int)*length);    // pedimos memoria para el array que le pasaremos al heap
    for (int i = 1; i <= length; ++i) {         // lo poblamos
        array[i-1] = atoi(argv[i]);
    }

    show_array(array, length);

    printf("\nInserción elemento a elemento\n");
    Heap* heap = build_heap_by_insertion(array, length);    // armamos el heap con la primera estrategia

    valid_heap(heap);                           // verificamos que es un heap

    printf("\nOrdenamos los elementos con heapsort\n");
    heap_sort(heap);                            // llamamos a heapsort... "||" marca la división
                                                // entre el heap y la parte ya ordenada
    destroy_heap(heap);

    return 0;
}


int main1(int argc, char* argv[]){
    int length = argc - 1;

    printf("%s\n", argv[0]);
    int* array = malloc(sizeof(int)*length);
    for (int i = 1; i <= length; ++i) {
        array[i-1] = atoi(argv[i]);
    }

    show_array(array, length);

    printf("\nSift down de los elementos de la primera mitad\n");
    Heap* heap = build_heap_by_heapify(array, length);      // armamos el heap con la segunda estrategia

    valid_heap(heap);

    printf("\nOrdenamos los elementos con heapsort\n");
    heap_sort(heap);

    destroy_heap(heap);

    return 0;
}