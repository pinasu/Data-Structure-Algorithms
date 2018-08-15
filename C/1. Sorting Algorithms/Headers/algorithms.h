#include "arraylist.h"
#include "compare.h"
#include "utils.h"

/*
 * Function: selection_sort
 * -------------------------
 * Prototype of Selection Sort algorithm for generic types.
 *
 * array:  the pointer to the generic type array to be sorted,
 * l: the array length,
 * c: the compare function used in the algorithm.
 *
 */
void selection_sort(void** array, int l, compare c);

/*
 * Function: insertion_sort
 * -------------------------
 * Prototype of Insertion Sort algorithm for generic types.
 *
 * array: the pointer to the generic type array to be sorted,
 * l: the array length,
 * c: the compare function used in the algorithm.
 *
 */
void insertion_sort(void** array, int l, compare c);

/*
 * Function: quick_sort
 * -------------------------
 * Prototype of Quick Sort algorithm for generic types.
 *
 * array: the pointer to the generic type array to be sorted,
 * l: the array length,
 * c: the compare function used in the algorithm.
 *
 */
void quick_sort(void** array, int l, compare c);
