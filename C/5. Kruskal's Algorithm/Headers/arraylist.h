#define ARR 

#ifndef STD_H
#include "std.h"
#endif

/* Arraylist struct for generic types */
struct _arraylist{
  void** array;
  int size;
  int ff;
};

/* Arraylist pointer for generic types */
typedef struct _arraylist* Arraylist;

/* Arraylist constructor prototype for generic types */
Arraylist new_arraylist(int size);

/* Insert into Arraylist prototype for generic types */
int insert_arraylist(void* elem, Arraylist a);

/* Function to get element at given index */
void* get_index(Arraylist a, int index);

/* Function to swap two elements in two given indexes */
void swap(void** array, int i, int j);

/* Function to deallocate arraylist */
void free_arraylist(Arraylist a);