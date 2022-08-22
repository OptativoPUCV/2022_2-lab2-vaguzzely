#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
//1. Programe la función `List* createList()`, la cual retorna el puntero del tipo de dato `List` con sus valores inicializados en NULL.
List * createList() {
  List *list = (List *) malloc (sizeof(List));
	list->head = NULL;
  list->tail = NULL;
	list->current = NULL;
	return list;
  }
/*2. Programe las funciones `void * firstList(List * list)` y `void * nextList(List * list)`. 
   * La primera retorna el dato del primer nodo de la lista (`head`) y actualiza el current para que apunte a ese nodo. 
  */
void * firstList(List * list) {
  list->current = list->head;
  if(list->current != NULL)
    return (list->current->data);
  else
    return NULL;
  }

/* * La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.*/
  
void * nextList(List * list) {
  if(list->current->next != NULL)
    list->current = list->current->next;
  else if(list->current != NULL)
    return (list->current->data);
  else
    return NULL;
  }
/*3. Programe las funciones `void * lastList(List * list)` y `void * prevList(List * list)`.
   * La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. */

void * lastList(List * list) {
  list->current = list->tail; 
  if(list->current != NULL)
    return (list->current->data);
  else
    return NULL;
}
/* La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.*/
void * prevList(List * list) {
  if(list->current->prev != NULL)
    list->current = list->current->prev;
  if(list->current != NULL)
    return (list->current->data);
  else
    return NULL;
}
/*. Programe la función `void pushFront(List * list, void * data)`, la cual agrega un dato al comienzo de la lista. 
> Puede utilizar la función `Node* createNode(void * data)` la cual crea, incializa y retorna un nodo con el dato correspondiente. */
void pushFront(List * list, void * data){
  Node *newNode = createNode(data);
  if(list->head != NULL)
    list->head->prev = newNode ;
  }

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}
/*5. Programe la función `void pushCurrent(List * list, void* data)`, la cual agrega un dato a continuación del nodo apuntado por `list->current`.*/
void pushCurrent(List * list, void * data) {
  Node *newNode = createNode(data);
  newNode->next = list->current->next;
  list->current->next= newNode;
  newNode->prev= list->current;
}


void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

/*Las funciones `pushBack`, `popFront` y `popBack` se pueden implementar usando `popCurrent` y `pushCurrent` (búsquelas en el código).

### Por lo tanto, ya tiene implementado su primer TDA!
*/
void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}
/*6. Programe la función `void* popCurrent(List * list)`, la cual elimina el nodo que está en la posición del current de la lista enlazada, y además retorna el **dato** del nodo eliminado.
> **Nota**: El current debe quedar apuntando al nodo siguiente del eliminado.
*/
void * popCurrent(List * list) {
  void *dato;
  dato = list->current->data;
  list->current->prev->next= list->current->next;
  return dato;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}