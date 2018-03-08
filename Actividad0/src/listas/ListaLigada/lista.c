// importo el archivo lista.h
#include "lista.h"
// Libreria estandar de C
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: debes completar las funciones que estan a continuacion
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Crea una lista inicialmente vacia y retorna el puntero */
List* list_init()
{
}

/** Inserta un elemento al final de la lista */
void list_append(List* list, int element)
{
}

/** Elimina el ultimo elemento de la lista y lo retorna */
int list_pop(List* list)
{
}

/** Inserta el elemento dado en la posicion indicada */
void list_insert(List* list, int element, int position)
{
}

/** Elimina el elemento de la posicion indicada y lo retorna */
int list_delete(List* list, int position)
{
}

/** Retorna el valor del elemento en la posicion dada */
int list_get(List* list, int position)
{
}

/** Concatena a la lista una segunda lista */
void list_concatenate(List* list, List* list2)
{
}

/** Libera la memoria de la lista para no tener leaks */
void list_destroy(List* list)
{
}
