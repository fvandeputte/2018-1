// Importo el archivo arraylist.h
#include "arraylist.h"
// Libreria estandar de C
#include <stdlib.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: Debes completar las siguientes funciones
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Duplica el tanio del arreglo */
void duplicate(ArrayList* list)
{
  // Creo un arreglo del doble de tamanio
  int* new_array = malloc(sizeof(int) * 2 * list -> size);

  // Itero sobre el arreglo viejo traspasando los datos
  for (int i = 0; i < list -> count; i++)
  {
    new_array[i] = list -> array[i];
  }

  // Libero la memoria vieja
  free(list -> array);

  // Cambio el puntero al nuevo arreglo
  list -> array = new_array;

  // Agrando el tamanio
  list -> size *= 2;
}

/** Crea una arraylist inicialmente vacia y retorna su puntero */
ArrayList* arraylist_init()
{
  // Creo el arraylist en memoria
  ArrayList* arrlist = malloc(sizeof(ArrayList));

  // Inicializo sus atributos
  arrlist -> size = 8;
  arrlist -> count = 0;
  arrlist -> array = malloc(sizeof(int) * arrlist -> size);

  // Retorno
  return arrlist;
}

/** Inserta un elemento al final de la arraylist */
void arraylist_append(ArrayList* list, int element)
{
  if (list -> count == list -> size)
  // Duplico la memoria si estoy lleno
  {
    duplicate(list);
  }
  // Guardo el elemento
  list -> array[list -> count] = element;
  // Agrego 1 al contador
  list -> count++;
}

/** Inserta el elemento dado en la posicion indicada */
void arraylist_insert(ArrayList* list, int element, int position)
{
  // S estoy lleno, duplico el arreglo
  if (list -> size == list -> count)
  {
    duplicate(list);
  }

  // Itero sobre los elementos posteriores a la posicion de insercion y los muevo
  for (int i = list -> count - 1; i >= position; i--)
  {
    list -> array[i + 1] = list -> array[i];
  }

  // Inserto el elemento
  list -> array[position] = element;

  // Sumo 1 al count
  list -> count++;
}

/** Elimina el elemento de la posicion indicada y lo retorna */
int arraylist_delete(ArrayList* list, int position)
{
  // Obtengo el valor de la posicion
  int value = list -> array[position];

  // Itero sobre los elmentos posteriores moviendo los datos
  for (int i = position; i < list -> count - 1; i++)
  {
    list -> array[i] = list -> array[i + 1];
  }

  // Saco 1 de la cuenta total
  list -> count--;

  // Retorno el valor eliminado
  return value;
}

/** Retorna el valor del elemento en la posicion dada */
int arraylist_get(ArrayList* list, int position)
{
  // Simplemente retorno el valor
  return list -> array[position];
}

/** Concatena la segunda arraylist a la primera arraylist */
void arraylist_concatenate(ArrayList* list1, ArrayList* list2)
{
  // Calculo el espacio total que voy a necesitar
  int total = list1 -> count + list2 -> count;

  // Calculo la potencia de 2 mas chica donde caben los datos
  int size = 8;
  while (size < total)
  {
    size *= 2;
  }

  // Si no tengo suficiente espacio en la lista1, la agrando
  if (size >= list1 -> size)
  {
    // Creo un arreglo nuevo de tamanio size
    int* new_array = malloc(sizeof(int) * size);

    // Traspaso todos los datos del arrelgo viejo al nuevo
    for (int i = 0; i < list1 -> count; i++)
    {
      new_array[i] = list1 -> array[i];
    }

    // Libero el arreglo antiguo
    free(list1 -> array);

    // Asigno el arreglo nuevo y su tamanio a la lista
    list1 -> array = new_array;
    list1 -> size = size;
  }

  // Traspaso los datos de la lista 2 a la lista 1
  for (int i = 0; i < list2 -> count; i++)
  {
    list1 -> array[i + list1 -> count] = list2 -> array[i];
  }

  // Actualizo la cantidad de datos de la lista 1
  list1 -> count += list2 -> count;

  // Libero la lista 2
  arraylist_destroy(list2);
}

/** Libera todos los recursos asociados a la lista */
void arraylist_destroy(ArrayList* list)
{
  // Libero el arreglo de enteros
  free(list -> array);

  // Libero la estructura
  free(list);
}
