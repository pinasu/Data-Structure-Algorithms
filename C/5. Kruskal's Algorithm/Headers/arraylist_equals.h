#ifndef ARR
#include "arraylist.h"
#endif

#include "equals.h"

/* Arraylist definition */
typedef struct _arraylist_equals* ArraylistEquals;

/* Arraylist definition with equals function */
struct _arraylist_equals{
	Arraylist arraylist;
	equals eq;
};

/* Function to allocate Arraylist with equals function */
ArraylistEquals new_arraylist_equals(int size, equals e);

/* Function to insert element into Arraylist */
int insert_arraylist_equals(void* elem, ArraylistEquals a);

/* Function to free Arraylist occupied memory */
void free_arraylist_equals(ArraylistEquals a);