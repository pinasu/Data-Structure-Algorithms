#include "assert.h"

/*
 * Constant for the array initial length
 */
#define TEST_LENGTH 10

/*
 * Function prototype to print generic array
 */
void print_array_int(void** array, int l);

/*
 * Function prototype to alloc int pointer
 */
int* malloc_int(int x);

/*
 * Function prototype to alloc generic empty array
 */
void** new_empty_array();

/*
 * Function prototype to alloc generic sorted array
 */
void** new_sorted_array();

/*
 * Function prototype to alloc generic inverted sorted array
 */
void** new_inverted_sorted_array();

/*
 * Function prototype to alloc generic unsorted array
 */
void** new_unsorted_array();

/*
 * Function prototype to check if generic array is sorted
 */
void is_sorted(void** array, int l);

/*
 * Selectionsort protptype tests
 */
void test_selectionsort_empty_array();

void test_selectionsort_sorted_array();

void test_selectionsort_inverted_sorted_array();

void test_selectionsort_unsorted_array();

/*
 * Insertionsort prototype tests
 */
void test_insertionsort_empty_array();

void test_insertionsort_sorted_array();

void test_insertionsort_inverted_sorted_array();

void test_insertionsort_unsorted_array();

/*
 * Quicksort prototype tests
 */
void test_quicksort_empty_array();

void test_quicksort_sorted_array();

void test_quicksort_inverted_sorted_array();

void test_quicksort_unsorted_array();
