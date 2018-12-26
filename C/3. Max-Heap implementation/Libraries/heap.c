#include "../Headers/heap.h"

/* Function to malloc and return int pointer */
int* malloc_int(int n){
  int* x = (int*)malloc(sizeof(int));
  *x = n;
  return x;
}

/* Heap constructor for generic types */
Heap new_heap(int size, compare c){
  Heap n;
  if(size < 1)
    size = 1;

  n = (Heap)malloc(sizeof(struct _heap));
  n->array = (void**)malloc(sizeof(void*)*size);
  n->size = size;
  n->ff = 0;
  n->cmp = c;

  return n;
}

/* Heap resizer for given Heap */
int resize(Heap h){
  void** tmp;

  if(h == NULL)
    return -1;

  h->size = (h->size)*2;
  tmp = (void**)malloc(sizeof(void*)*h->size);

  for(int i=0; i < h->ff; i++)
    tmp[i] = h->array[i];

  free(h->array);
  h->array = tmp;

  return 0;
}

/* Function to get heap from given arraylist */
Heap from_array(void** a, int len, compare c){
  if(a == NULL || len < 0) return NULL;

  Heap heap = new_heap(len, c);

  for(int i=0; i<len; i++)
    insert_heap(a[i], heap);

  return heap;
}

/* Function to insert given element to Heap */
int insert_heap(void* elem, Heap h){
  if(h->ff == h->size){
    if(resize(h) == -1)
      return -1;
  }

  h->array[h->ff] = elem;
  h->ff++;
  heapify_insert(h, h->ff-1);

  return 0;
}

/* Function to maintain Heap property when inserting element */
void heapify_insert(Heap h, int i){
    int f;
    if(i > 0){
      f = get_father(i);
      if(h->cmp(h->array[i], h->array[f]) == 1){
        swap(h->array, f, i);
          heapify_insert(h, f);
      }
  }

  return;
}

/* Function to get given element index in given Heap */
int get_elem(Heap h, void* elem){
  for(int i=0; i<h->ff; i++){
    if(h->cmp(h->array[i], elem) == 0)
      return i;
  }
  return -1;
}

/* Function to maintain Heap property when removing element */
void heapify_extract(Heap h, int index){
  int l = get_left(h->ff, index);
  int r = get_right(h->ff, index);
  int max = 0;

  if(l == -1 || r == -1)
    return;

  if(h->cmp(h->array[l], h->array[r]) == 1)
    max = l;
  else
    max = r;

  if(h->cmp(h->array[max], h->array[index]) == 1){
    swap(h->array, index, max);
    heapify_extract(h, max);
}

  return;
}

/* Function to extracr element from Heap */
void extract_heap(Heap h, void* elem){
  int index = get_elem(h, elem);
  if(index == -1)
    return;

  swap(h->array, index, h->ff-1);

  free(h->array[h->ff-1]);
  h->ff = h->ff-1;

  heapify_extract(h, index);
}

/* Function for swapping given index in given generic array */
void swap(void** array, int i, int j){
    void* tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/* Recursive function to determine if given generic array is max Heap */
int is_max_heap_rec(void** array, int len, compare c){
  return is_max_heap_rec_help(array, len, c, 0);
}

/* Recursive function helper to determine if given generic array is max Heap */
int is_max_heap_rec_help(void** array, int len, compare c, int index){
  int l = (index*2) + 1;
  int r = (index*2) + 2;

  if(l >= len)
    return 0;

  else if(r >= len)
    is_max_heap_rec_help(array, len, c, l);

  else{
    if(c(array[index], array[l]) == 1)
      is_max_heap_rec_help(array, len, c, l);
    else
      return -1;

    if(c(array[index], array[r]) == 1)
      is_max_heap_rec_help(array, len, c, r);
    else
      return -1;
  }

  return 0;
}

/* Iterative function to determine if given generic array is a max heap */
int is_max_heap_it(void** array, int len, compare c){
  int index, l, r;
  index = 0;

  if(len == 0 || len == 1)
    return 0;

  while(index < len/2){
    l = (index*2) + 1;
    r = (index*2) + 2;

    if(c(array[index], array[l]) == -1)
      return -1;

    if(r >= len)
      return 0;

    if(c(array[index], array[r]) == -1)
      return -1;

    index++;
  }
  return 0;
}

/* Function to return father index of a given node */
int get_father(int index){
  int father = index/2;

  if(index%2 == 0)
    father--;

  return father;
}

/* Function to return left child index of a given node */
int get_left(int len, int index){
  int left =  (index*2) + 1;
  if(left >= len)
    return -1;

  return left;
}

/* Function to return right child index of a given node */
int get_right(int len, int index){
  int right = (index*2) + 2;
  if(right >= len)
    return -1;

  return right;
}
