//
// Created by Sebastian Guerra Bugedo on 22/03/2018.
//

#include <stdlib.h>
#include <stdio.h>
#include "heaps.h"



Heap* heap_init(int *array, int length){
    Heap* my_heap = malloc(sizeof(Heap));
    my_heap->size = length;
    my_heap->count = 0; // no tiene elementos heapeados
    my_heap->array = array;
    //printf("Creado heap(size=%d, count=%d, [%d,%d,%d])\n", my_heap->size, my_heap->count,my_heap->array[0],my_heap->array[1],my_heap->array[2]);
    return my_heap;
}

int father_pos(int pos){
    return (pos + 1)/2 - 1;
}

int left_child(int pos){
    return (pos + 1) * 2 - 1;
}

int right_child(int pos){
    return (pos + 1) * 2;
}

/*
 * Sube un elemento hasta ubicarlo correctamente
 */
void sift_up(Heap* heap, int current){
    if (father_pos(current) >= 0){
        int father = father_pos(current);
        int* arr = heap->array;
        if (arr[father] > arr[current]){
            int aux = arr[father];
            arr[father] = arr[current];
            arr[current] = aux;

            sift_up(heap, father);
        };
    }
}

/*
 * Baja un elemento hasta ubicarlo correctamente
 */
void sift_down(Heap *heap, int current){
    int child;
    int *arr = heap->array;
    if (right_child(current) <= heap->count){
        // tiene hijo más prioritario derecho
        if (arr[right_child(current)] < arr[left_child(current)]){
            child = right_child(current);
        } else { // tiene hijo más prioritario izquierdo
            child = left_child(current);
        }
    } else if (left_child(current) <= heap->count){
        // tiene un solo hijo (el izquierdo)
        child = left_child(current);
    } else {
        // no tiene hijos
        child = 0;
    }
    if (child > 0){
        if (arr[child] < arr[current]){
            int aux = arr[child];
            arr[child] = arr[current];
            arr[current] = aux;

            sift_down(heap, child);
        }
    }
}

void insert(Heap* heap, int new_int){
    // si quedan espacios vacíos
    if (heap->size > heap->count){
        int blank = heap->count;
        heap->array[blank] = new_int;
        heap->count++;
        sift_up(heap, blank);
    }
}

// saca la raíz del heap actual y la retorna (obtiene el MIN)
int extract(Heap* heap){
    int last = heap->count-1;
    int* arr = heap->array;
    int root = arr[0];

    heap->count--;
    if (heap->count){

        arr[0] = arr[last];
        sift_down(heap, 0);
    }
    return root;
}

int verify_max_heap(Heap* heap){
    int *arr = heap->array;
    for (int i = 1; i < heap->count / 2; ++i) {
        // printf("Checking position %d and its children\n", i);
        if (right_child(i) < heap->count){
            if (arr[i] > arr[right_child(i)] || arr[i] > arr[left_child(i)]){
                return 0;
            }
        } else if (left_child(i) < heap->count){
            if (arr[i] > arr[left_child(i)]){
                return 0;
            }
        }
    }
    return 1;
}

Heap* build_heap_by_insertion(int* array, int length){
    Heap* heap = heap_init(array, length);
    show_heap(heap);
    for (int i = 0; i < length; ++i) {
        insert(heap, heap->array[i]);
        show_heap(heap);
    }
    return heap;
}

Heap* build_heap_by_heapify(int* array, int length){
    Heap* heap = heap_init(array, length);
    heap->count = heap->size;
    for (int j = length / 2 - 1; j >= 0; --j) {
        sift_down(heap, j);
    }
    return heap;
}

void heap_sort(Heap* heap){
    // JIJIJIJIJ
}

void show_heap(Heap* heap){
    printf("======= Printing Heap =======\n");
    if (!heap->count){
        printf("|");
    }
    for (int i = 0; i < heap->count; ++i) {
        printf("| %d ", heap->array[i]);
    }
    printf("|\n");
}

void show_heap_and_ordered(Heap* heap, int initial){
    printf("======= Printing Heap =======\n");
    for (int i = 1; i <= initial; ++i) {
        printf("| %d ", heap->array[i]);
        if (heap->count == i){
            printf("|");
        }
    }
    printf("|\n");
}

void show_array(int* array, int length){
    printf("======= Printing Array =======\n");
    if (!length){
        printf("|");
        return;
    }
    for (int i = 0; i < length; ++i) {
        printf("| %d ", array[i]);
    }
    printf("|\n");
}

void destroy_heap(Heap* heap){
    free(heap->array);
    free(heap);
}