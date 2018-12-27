#include "../Headers/djset.h"

/* Djset constructor for generic types */
Djset new_djset(int size, equals e){
  return new_arraylist_equals(size, e);
}

/* Function to insert given element to Djset */
int make_set(void* elem, Djset a){
  if(find_set(a, elem) != NULL)
    return -1;

  List node = new_list(elem);
  return insert_arraylist(node, a-> arraylist);
}

/* Function to create Djset */
Djset create_set(void** v, int size, equals e){
  Djset a = new_djset(size, e);

  int i = 0;
  while(i < size){
    make_set(v[i], a);
    i++;
  }
  return a;
}

/* Function to free Djset */
void free_djset(Djset a){
  int i = 0;
  while(i < a-> arraylist-> ff){
    List iterator = a-> arraylist-> array[i];
    while(iterator != NULL){
      List tmp = iterator-> next;
      free(iterator);
      iterator = tmp;
    }
    free(a-> arraylist-> array[i]);
    i++;
  }
  free_arraylist_equals(a);
}

/* List constructor */
List new_list(void* value){
  List list = malloc(sizeof(struct _list));
  list-> value = value;
  list-> rank = 0;
  list-> next = NULL;

  return list;
}

/*Function to find given element in given Djset */
List find_set(Djset a, void* elem){
  int i = 0;
  while(i < a-> arraylist-> ff){
    List iterator = a-> arraylist-> array[i];

    while(iterator != NULL){
      if(a-> eq(elem, iterator-> value) == 0)
        return a-> arraylist-> array[i];

      iterator = iterator-> next;
    }
    i++;
  }
  return NULL;
}

/* Function to link two lists in Djset */
List link_set(List l1, List l2){
  if(l1 == NULL || l2 == NULL)
    return NULL;

  if(l1->rank > l2->rank){
    List iterator = l1;
    while(iterator-> next != NULL)
      iterator = iterator-> next;

    iterator-> next = l2;
    return l2;
  }

  if(l2->rank >= l1->rank){
    if(l2->rank == l1->rank)
      l2->rank = l2->rank+1;

    List iterator = l2;
    while(iterator-> next != NULL)
      iterator = iterator-> next;

    iterator-> next = l1;
    return l1;
  }

  return NULL;
}

/* Function to union two given sets in given Djset */
void union_set(Djset a, void* elem1, void* elem2){
  List first = find_set(a, elem1);
  List second = find_set(a, elem2);

  if(first != NULL && second != NULL){
    if(first != second){
      List tmp = link_set(first, second);
      int i = 0;
      while(a-> arraylist->  array[i] != tmp)
        i++;

      a-> arraylist-> array[i] = a-> arraylist-> array[a-> arraylist->ff-1];
      a-> arraylist->ff--;
    }
  }
}
