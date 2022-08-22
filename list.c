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
  return (list->current->data);
  }

/* * La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.*/
void * nextList(List * list) {
  list->current = list->current->next;
  return list->current->data;
}
/*3. Programe las funciones `void * lastList(List * list)` y `void * prevList(List * list)`.
   * La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. */

void * lastList(List * list) {
  list->current = list->tail; 
    return list->current->data;
}
/* La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.*/
void * prevList(List * list) {
  if(list)
    return NULL;
}

void pushFront(List * list, void * data) {
  if(list == NULL) return NULL;
  Node *newNode = crearNode(data);
  
  if(list->head != NULL){
    newNode -> prev = list -> current;
    list -> current-> next = newNode;
    list -> tail -> newNode;
    r 
    }
    
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *current = list -> current;
  current -> prev -> next = list -> current -> next;
  current -> next -> prev = list -> current -> prev;

  free(current);
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}