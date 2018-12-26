#include "../Headers/arraylist.h"

/*
 * Function: new_arraylist
 * -------------------------
 * new_arraylist implementation.
 * Allocates a new _arraylist struct and the array inside it which is as big as
 * specified size.
 *
 */
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

/*
 * Function: resize
 * -------------------------
 * Function that doubles the size of the array inside _arraylist struct.
 * Copies everything that is inside the array of the _arraylist pointer
 * to a new array with doubled size. The array pointer in the new_arraylist
 * structure becomes a pointer to the newly created array.
 *
 * arraylist: The _arraylist pointer which array size needs to be doubled.
 *
 * returns: 0 if everything went as expected, -1 otherwise.
 */
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

/*
 * Function: insert_arraylist
 * -------------------------
 * Inserts a generic type element into a given _arraylist.
 * If the array pointed by _arraylist is full, it is resized. Adds the given
 * element in the first free position of the array inside the _arraylist.
 *
 * elem: the element tobe added in the _arraylist,
 * a: the _arraylist pointer to which the new element will be added.
 *
 * returns: 0 if everything went as expected, -1 otherwise.
 */
int insert_arraylist(void* elem, Arraylist a){
	if(a->ff == a->size){
	  if(resize(a) == -1)
		return -1;
	}

	a->array[a->ff] = elem;
	a->ff++;

	return 0;
}
