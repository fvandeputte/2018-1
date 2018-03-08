// Esta linea sirve para que el codigo de este archivo solo se importe una vez
#pragma once


/** Estructura de un arreglo dinamico */
struct array_list
{
  // TODO: Completar esto
};

// Aqui le estoy poniendo un nombre mas simple a la lista para no tener que
// referirme a la lista como struct array_list
/** Estructura de un arreglo dinamico */
typedef struct array_list Array;


//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

//OJO: No se debe modificar nada de esto

/** Crea un arreglo dinamico inicialmente vacia y retorna el puntero */
Array* array_init();

/** Inserta un elemento al final del arreglo dinamico */
void array_append(Array* array, int element);

/** Elimina el ultimo elemento del arreglo dinamico y lo retorna */
int array_pop(Array* array);

/** Inserta el elemento dado en la posicion indicada */
void array_insert(Array* array, int element, int position);

/** Elimina el elemento de la posicion indicada y lo retorna */
int array_delete(Array* array, int position);

/** Retorna el valor del elemento en la posicion dada */
int array_get(Array* array, int position);

/** Concatena el arreglo dinamico con otro arreglo dinamico */
void array_concatenate(Array* array, Array* array2);

/** Libera la memoria del arreglo dinamico para no tener leaks */
void array_destroy(Array* array);
