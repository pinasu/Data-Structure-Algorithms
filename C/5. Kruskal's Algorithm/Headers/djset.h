#ifndef STD_H
#include "std.h"
#endif

#include "arraylist_equals.h"

/* Djset definition as ArraylistEquals */
typedef ArraylistEquals Djset;

/* Djset constructor prototype for generic types */
Djset new_djset(int size, equals e);

/* Free Djset prototype for generic types */
void free_djset(Djset a);

/* List pointer definition */
typedef struct _list* List;

/* List definition */
struct _list{
  void* value;
  int rank;
  List next;
};

/* List constructor */
List new_list(void* value);

/* Function prototype to insert element into Djset */
int insert_djset(void* elem, Djset a);

/* Function prototype to create Djset from given generic array */
Djset create_set(void** v, int size, equals e);

/* MakeSet prototype definition */
int make_set(void* elem, Djset a);

/* LinkSet prototype definition */
List link_set(List l1, List l2);

/* FindSet prototype definition */
List find_set(Djset a, void* elem);

/* UnionSet prototype definition */
void union_set(Djset a, void* elem1, void* elem2);
