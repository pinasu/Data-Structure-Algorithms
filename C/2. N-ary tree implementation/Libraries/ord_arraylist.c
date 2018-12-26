#include "../Headers/ord_arraylist.h"

/*
 * Function: swap
 * -------------------------
 * Compares two swap given indexes elements in given generic array.
 *
 */
void swap(void** array, int i, int j){
	void* tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/*
 * Function: new_ordarraylist
 * -------------------------
 * Create a new ordered arraylist from a given size and compare function.
 *
 */
Ord_Arraylist new_ordarraylist(int size, compare c){
	Ord_Arraylist n;
	if(size < 1)
		size = 1;

	n = (Ord_Arraylist)malloc(sizeof(struct _ordarraylist));
	n->arr_list = new_arraylist(size);
	n->cmp = c;

	return n;
}

/*
 * Function: insert_ordarraylist
 * -------------------------
 * Inserts a given generic element in the right place in given ordered arraylist.
 *
 */
int insert_ordarraylist(void* elem, Ord_Arraylist a){
	insert_arraylist(elem, a->arr_list);

	int i = a->arr_list->ff-1;

	while(i > 0 && a->cmp(a->arr_list->array[i-1], a->arr_list->array[i]) > 0){
		swap(a->arr_list->array, i-1, i);
		i--;
	}

	return 0;
}

/* Function to get given ordered arraylist first free */
/*
 * Function: get_ff
 * -------------------------
 * Returns the first free index in given arraylist.
 *
 */
int get_ff(Ord_Arraylist a){
	return a->arr_list->ff;
}

/* Function to get given ordered arraylist index pointer */
/*
 * Function: get_ff
 * -------------------------
 * Returns the element of given index in given arraylist.
 *
 */
void* get_index(Ord_Arraylist a, int index){
	return a->arr_list->array[index];
}
