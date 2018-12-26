#ifndef STD_H
#include "std.h"
#endif

#include "../Headers/compare.h"

/* Arraylist struct definition for generic types */
struct _heap{
  void** array;
  int size;
  int ff;
  compare cmp;
};

/* Arraylist pointer definition for generic types */
typedef struct _heap* Heap;

/* Function prototype to malloc and return int pointer */
int* malloc_int(int n);

/* Arraylist constructor prototype for generic types */
Heap new_heap(int size, compare c);

/* Insert into Arraylist prototype for generic types */
int insert_heap(void* elem, Heap h);

/* Function prototype to get Heap from given arraylist */
Heap from_array(void** a, int len, compare c);

/* Function prototype to maintain Heap property during insert */
void heapify_insert(Heap h, int i);

/* Function prototype to swap two element in given generic array */
void swap(void** array, int i, int max);

/* Function prototype to get given element index in given Heap */
int get_elem(Heap h, void* elem);

/* Function prototype to extract given elem from Heap */
void extract_heap(Heap h, void* elem);

/* Function prototype to maintain Heap property during removal*/
void heapify_extract(Heap h, int index);

/* Return father index of a given node prototype */
int get_father(int index);

/* Return left child index of a given node prototype */
int get_left(int len, int index);

/* Return right child index of a given node prototype */
int get_right(int len, int index);

int is_max_heap_rec(void** array, int len, compare c);

int is_max_heap_it(void** array, int len, compare c);
