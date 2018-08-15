#include "array_unit_test.h"

/*
 * Prints a given int array
 *
 * array: the array pointer,
 * l: the array length.
 */
void print_array_int(void** array, int l){
  int i = 0;
  int** new_arr = (int**)array;

  if(new_arr != NULL && l>0)
	printf("%d ", new_arr[i][0]);
  else
	printf("Array is NULL.\n");

  printf("\n");
}

/*
 * Allocs a given value int pointer and returns the pointer.
 *
 * x: the int value.
 *
 * returns: a new int pointer.
 */
int* malloc_int(int x){
  int* n = malloc(sizeof(int));
  *n = x;
  return n;
}

/*
 * Creates an empty array.
 *
 * returns: the newly created array pointer.
 */
 void** new_empty_array(){
  void* x = NULL;
  void** v = &x;
  return v;
}

/*
 * Allocs a new array of int.
 *
 * returns: the newly created sorted array.
 */
void** new_sorted_array(){
  void** v =(void**)malloc(sizeof(void*)*TEST_LENGTH);
  v[0] = malloc_int(5);
  v[1] = malloc_int(6);
  v[2] = malloc_int(7);
  v[3] = malloc_int(8);
  v[4] = malloc_int(9);
  v[5] = malloc_int(10);
  v[6] = malloc_int(20);
  v[7] = malloc_int(30);
  v[8] = malloc_int(50);
  v[9] = malloc_int(100);

  return v;
}

/*
 * Allocs a new array of int.
 *
 * returns: the newly created sort inverted array.
 */
 void** new_inverted_sorted_array(){
  void** v =(void**)malloc(sizeof(void*)*TEST_LENGTH);
  v[0] = malloc_int(100);
  v[1] = malloc_int(50);
  v[2] = malloc_int(30);
  v[3] = malloc_int(20);
  v[4] = malloc_int(10);
  v[5] = malloc_int(9);
  v[6] = malloc_int(8);
  v[7] = malloc_int(7);
  v[8] = malloc_int(6);
  v[9] = malloc_int(5);

  return v;
}

/*
 * Allocs a new array of int.
 *
 * returns: the newly created unsorted array.
 */
void** new_unsorted_array(){
  void** v =(void**)malloc(sizeof(void*)*TEST_LENGTH);
  v[0] = malloc_int(6);
  v[1] = malloc_int(10);
  v[2] = malloc_int(7);
  v[3] = malloc_int(5);
  v[4] = malloc_int(30);
  v[5] = malloc_int(100);
  v[6] = malloc_int(8);
  v[7] = malloc_int(20);
  v[8] = malloc_int(9);
  v[9] = malloc_int(50);

  return v;
}

/*
 * Checks if given int array is sorted.
 *
 * array: the array pointer,
 * l: the array length.
 *
 */
 void is_sorted(void** array, int l){
  int i = 0;
  int* x;
  int* y;
  int x_val, y_val;

  if(l<=0)
	assert(1);
  else{
	l--;
	while(i<l){
	  x = (int*)(array[i]);
	  y = (int*)(array[i+1]);
	  x_val = *x;
	  y_val = *y;
	  assert(x_val <= y_val);
	  i++;
	}
  }
}

/*
 * Check if new empty, sorted, inverted sort and unsorted array are
 * sorted after selection_sort.
 */
void test_selectionsort_empty_array(){
  void** v = new_empty_array();
  selection_sort(v, 0, compare_int);
  print_array_int(v, 0);
  is_sorted(v,0);
}

void test_selectionsort_sorted_array(){
  void** v = new_sorted_array();
  selection_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

void test_selectionsort_inverted_sorted_array(){
  void** v = new_inverted_sorted_array();
  selection_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

void test_selectionsort_unsorted_array(){
  void** v = new_unsorted_array();
  selection_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

/*
 * Check if new empty, sorted, inverted sort and unsorted array are
 * sorted after insertion_sort.
 */
void test_insertionsort_empty_array(){
  void** v = new_empty_array();
  insertion_sort(v, 0, compare_int);
  print_array_int(v, 0);
  is_sorted(v,0);
}

void test_insertionsort_sorted_array(){
  void** v = new_sorted_array();
  insertion_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

void test_insertionsort_inverted_sorted_array(){
  void** v = new_inverted_sorted_array();
  insertion_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

void test_insertionsort_unsorted_array(){
  void** v = new_unsorted_array();
  insertion_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

/*
 * Check if new empty, sorted, inverted sort and unsorted array are
 * sorted after quicksort.
 */
void test_quicksort_empty_array(){
  void** v = new_empty_array();
  quick_sort(v, 0, compare_int);
  print_array_int(v, 0);
  is_sorted(v,0);
}

void test_quicksort_sorted_array(){
  void** v = new_sorted_array();
  quick_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

void test_quicksort_inverted_sorted_array(){
  void** v = new_inverted_sorted_array();
  quick_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}

void test_quicksort_unsorted_array(){
  void** v = new_unsorted_array();
  quick_sort(v, TEST_LENGTH, compare_int);
  print_array_int(v, TEST_LENGTH);
  is_sorted(v, TEST_LENGTH);
}
