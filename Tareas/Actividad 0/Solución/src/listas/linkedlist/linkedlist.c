// importo el archivo linkedlist.h
#include "linkedlist.h"
// Libreria estandar de C
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: debes completar las funciones que estan a continuacion
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Crea un nodo */
Node* node_init(int value)
{
  // Creo el nodo
  Node* node = malloc(sizeof(Node));

  // Le agrego el valor y le pongo next = NULL
  node -> value = value;
  node -> next = NULL;

  // Retorno el nodo
  return node;
}

/** Libera los nodos recursivamente */
void recursive_destroy(Node* node)
{
  // Si tiene sucesor, llama recursivamente
  if (node -> next)
  {
    recursive_destroy(node -> next);
  }

  // Libero al nodo
  free(node);
}

/** Crea una lista inicialmente vacia y retorna el puntero */
LinkedList* linkedlist_init()
{
  // Creo la linked list
  LinkedList* list = malloc(sizeof(LinkedList));

  // Relleno sus atributos
  list -> count = 0;
  list -> first = NULL;
  list -> last = NULL;

  // Retorno la lista
  return list;
}

/** Inserta un elemento al final de la lista */
void linkedlist_append(LinkedList* list, int element)
{
  // Creo el nodo a agregar
  Node* node = node_init(element);

  // Si la lista esta vacia
  if (list -> count == 0)
  {
    // Hago que sea el primer nodo
    list -> first = node;
  }
  // Sino,
  else
  {
    // Hago que sea el siguiente del ultimo
    list -> last -> next = node;
  }

  // Ahora este nodo es el ultimo
  list -> last = node;

  // Agrego 1 a la cuenta
  list -> count++;
}

/** Inserta el elemento dado en la posicion indicada */
void linkedlist_insert(LinkedList* list, int element, int position)
{
  // Creo el nodo a insertar
  Node* node = node_init(element);

  // Si me piden insertar en la posicion 0:
  if (position == 0)
  {
    // Hago que referencie al primero
    node -> next = list -> first;
    // Hago el nodo nuevo como el primero
    list -> first = node;
  }
  // Si insertan en la ultima posicion
  else if (position == list -> count)
  {
    // Hago que sea el siguiente del ultimo
    list -> last -> next = node;

    // Ahora este nodo es el ultimo
    list -> last = node;
  }
  // Si inserto entremedio
  else
  {
    // Itero sobre la lista hasta encontrar la posicion
    Node* actual = list -> first;
    for (int i = 1; i < position; i++)
    {
      actual = actual -> next;
    }
    // Hago que el nodo apunte al siguiente
    node -> next = actual -> next;
    // Hago que el anterior apunte al nodo
    actual -> next = node;
  }

  // Actualizo la cantidad
  list -> count++;
}

/** Elimina el elemento de la posicion indicada y lo retorna */
int linkedlist_delete(LinkedList* list, int position)
{
  // Variable a retornar
  int value;

  // Si me piden eliminar el primero
  if (position == 0)
  {
    // Obtengo el valor a retornar
    value = list -> first -> value;

    // Guardo el primero
    Node* first = list -> first;

    // Hago que el primero sea ahora el siguiente
    list -> first = first -> next;

    // Elimino el anterior
    free(first);
  }
  // En cuelquier otro caso
  else
  {
    // Busco el nodo anterior al que voy a eliminar
    Node* last = list -> first;
    for (int i = 1; i < position; i++)
    {
      last = last -> next;
    }

    // Obtengo el nodo a eliminar
    Node* actual = last -> next;

    // Obtengo el valor a retornar
    value = actual -> value;

    // Cambio el link del anterior al siguiente
    last -> next = actual -> next;

    // Libero la memoria del nodo eliminado
    free(actual);

    // Si elimine el ultimo, actualizo cual es la posicion final de la lista
    if (position == list -> count - 1)
    {
      list -> last = last;
    }
  }

  // Disminullo en 1 el count
  list -> count--;

  // retorno el valor eliminado
  return value;
}

/** Retorna el valor del elemento en la posicion dada */
int linkedlist_get(LinkedList* list, int position)
{
  // Itero sobre la lista buscando el valor a retornar
  Node* actual = list -> first;
  for (int i = 0; i < position; i++)
  {
    actual = actual -> next;
  }

  // Retorno el valor que hay en el nodo
  return actual -> value;
}

/** Concatena a la lista una segunda lista */
void linkedlist_concatenate(LinkedList* list1, LinkedList* list2)
{
  // Si la primera lista esta vacia
  if (list1 -> count == 0)
  {
    // Hago que tome el first y el last de la segunda lista
    list1 -> first = list2 -> first;
    list1 -> last = list2 -> last;
  }
  // Si la segunda lista esta vacia
  else if (list2 -> count == 0)
  {
    // No hago nada
  }
  // En cualquier otro caso
  else
  {
    // Hago que el ultimo nodo de la lista 1 apuente al primero de la siguiente
    list1 -> last -> next = list2 -> first;

    // Actualizo el last de la primera lista
    list1 -> last = list2 -> last;
  }

  // Actualizo el count de la primera lista
  list1 -> count += list2 -> count;

  // Libero la segunda lista
  free(list2);
}

/** Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list)
{
  // Libero todos los nodos
  recursive_destroy(list -> first);

  // Libero la lista
  free(list);
}
