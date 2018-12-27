#include "../Headers/arraylist.h"

/* Arraylist constructor for generic types */
Arraylist new_arraylist(int size){
  Arraylist n;
  if(size < 1)
    size = 1;

  n = (Arraylist)malloc(sizeof(struct _arraylist));
  n->array = (void**)malloc(sizeof(void*)*size);
  n->size = size;
  n->ff = 0;

  return n;
}

/* Arraylist resizer for given Arraylist */
int resize(Arraylist arraylist){
  void** tmp;

  if(arraylist == NULL)
    return -1;

  arraylist->size = (arraylist->size)*2;
  tmp = (void**)malloc(sizeof(void*)*arraylist->size);

  for(int i=0; i < arraylist->ff; i++)
    tmp[i] = arraylist->array[i];
  
  free(arraylist->array);
  arraylist->array = tmp;

  return 0;
}

/* Function to insert given element to Arraylist */
int insert_arraylist(void* elem, Arraylist a){
    if(a->ff == a->size){
      if(resize(a) == -1)
        return -1;
    }

    a->array[a->ff] = elem;
    a->ff++;
  
    return 0;
}

/* Function to get element in given index of Arraylist */
void* get_index(Arraylist a, int index){
  return a->array[index];
}

/* Function to swap given index in given generic array */
void swap(void** array, int i, int j){
    void* tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/* Function to free memory occupied Arraylist */
void free_arraylist(Arraylist a){
  free(a-> array);
  free(a);
}