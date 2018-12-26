#include "arraylist.h"
#include "compare.h"

/*
 * Struct: _ordarraylist
 * -------------------------
 * _ordarraylist structure definition: an _arraylist pointer and a compare function
 *
 * arr_list: the pointer to the _arraylist struct,
 * cmp: the compare function,
 *
 */
struct _ordarraylist {
  Arraylist arr_list;
  compare cmp;
};

/*
 * Pointer: Ord_Arraylist
 * -------------------------
 * _ordarraylist structure pointer.
 *
 */
typedef struct _ordarraylist* Ord_Arraylist;

/*
 * Function: new_arraylist
 * -------------------------
 * Prototype of new_ordarraylist to create a _ordarraylist pointer.
 *
 * size: the size of the _arraylist to be created,
 * c: a compare function.
 *
 * returns: a new Arraylist of desired size.
 *
 */
Ord_Arraylist new_ordarraylist(int size, compare c);

/*
 * Function: insert_ordarraylist
 * -------------------------
 * Prototype of insert_ordarraylist to insert an element into an Arraylist.
 *
 * elem: the pointer to the generic type element to be added,
 * a: the Arraylist in which the given element will be added.
 *
 * returns: 0 if the element was added, -1 otherwise.
 */
int insert_ordarraylist(void* elem, Ord_Arraylist a);

/*
 * Function: get_ff
 * -------------------------
 * Prototype of get_ff to get the first free array element index.
 *
 * a: the Ord_Arraylist.
 *
 * returns: the first free index, -1 if fails.
 */
int get_ff(Ord_Arraylist a);

/*
 * Function: get_index
 * -------------------------
 * Prototype of get to get the array element at given index.
 *
 * a: the Ord_Arraylist,
 * i: the index.
 *
 * returns: the element ad specified index, -1 if fails.
 */
void* get_index(Ord_Arraylist a, int index);
