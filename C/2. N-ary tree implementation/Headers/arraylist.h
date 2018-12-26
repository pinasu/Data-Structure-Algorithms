#ifndef STD_H
#include "std.h"
#endif

/*
 * Struct: _arraylist
 * -------------------------
 * _arraylist structure definition
 *
 * array: the pointer to the generic type array,
 * size: the array size,
 * ff: the first array free cell.
 *
 */
struct _arraylist{
  void** array;
  int size;
  int ff;
};

/*
 * Pointer: Arraylist
 * -------------------------
 * Arraylist structure pointer.
 *
 */
typedef struct _arraylist* Arraylist;

/*
 * Function: new_arraylist
 * -------------------------
 * Prototype of new_arraylist to create an _arraylist pointer.
 *
 * size: the size of the _arraylist to be created.
 *
 * returns: a new Arraylist of desired size.
 *
 */
Arraylist new_arraylist(int size);

/*
 * Function: insert_arraylist
 * -------------------------
 * Prototype of insert_arraylist to insert an element into an Arraylist.
 *
 * elem: the pointer to the generic type element to be added,
 * a: the Arraylist in which the given element will be added.
 *
 */
int insert_arraylist(void* elem, Arraylist a);
