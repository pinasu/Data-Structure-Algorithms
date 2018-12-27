#include "../Headers/arraylist_equals.h"

/* Arraylist constructor for generic types */
ArraylistEquals new_arraylist_equals(int size, equals e){
  ArraylistEquals aEq;
  if(size < 1)
    size = 1;

  aEq = (ArraylistEquals)malloc(sizeof(struct _arraylist_equals));
  aEq-> arraylist = new_arraylist(size);
  aEq-> eq = e;

  return aEq;
}

/* Function to insert given element to Arraylist */
int insert_arraylist_equals(void* elem, ArraylistEquals a){
  int i = 0;

  if(a-> arraylist-> ff == 0)
    insert_arraylist(elem, a-> arraylist);

  while(i < a-> arraylist-> ff){
    if(a-> eq(elem, a-> arraylist-> array[i]) == 1){
      return i;
    }
    else{
      insert_arraylist(elem, a-> arraylist);
    }

    i++;
  }
  
  return a-> arraylist-> ff-1;
}

/* Function to free memory occupied by Arraylist */
void free_arraylist_equals(ArraylistEquals a){
  free_arraylist(a-> arraylist);
  free(a);
}