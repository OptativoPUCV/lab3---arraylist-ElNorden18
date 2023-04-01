#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *lista = (ArrayList *) malloc(sizeof(void *));
  if(lista == NULL) return NULL;
  lista->capacity = 2;
  lista->size = 0;
  lista->data = (void **) malloc(sizeof(void *));
  return lista;
}

void append(ArrayList * l, void * data){
  if(l->size == l->capacity)
  {
    l->capacity *= 2;
    l->data = realloc(l->data, l->capacity);
  }
  l->data[l->size] = data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(i > l->size) return;

  if(l->size == l->capacity)
  {
    l->capacity *= 2;
    l->data = realloc(l->data, sizeof(void *) * l->capacity);
  }
  for(int k = l->size; k > i; k--)
    {
      l->data[k] = l->data[k-1];
    }
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList * l, int i){
  if(l == NULL) return NULL;
  if(i < 0)
    i = l->size+i;
  void * aux = l->data[i];
  for(int k = i; k < l->size; k++)
    l->data[k] = l->data[k+1];
  l->size--;
  return aux;
}

void* get(ArrayList * l, int i){
  if(i >= l->size)
    return NULL;
  if(i < 0)
    return l->data[l->size+i];
  return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  free(l->data);
  l->capacity = 0;
  l->size = 0;
  l->data = NULL;
}
