#include "Headers/heap.h"

/* Application main */
int main(){
  void* array[11];
  array[0] = malloc_int(1);
  array[1] = malloc_int(2);
  array[2] = malloc_int(3);
  array[3] = malloc_int(4);
  array[4] = malloc_int(2);
  array[5] = malloc_int(7);
  array[6] = malloc_int(3);
  array[7] = malloc_int(6);
  array[8] = malloc_int(4);
  array[9] = malloc_int(5);
  array[10] = malloc_int(9);

  int len = 11;

  for(int i = 0; i<len; i++)
    printf("%d, ", *(int*)array[i]);
  printf("\n");
  printf("Is max heap? %d\n", is_max_heap_it(array, len, compare_int));

  Heap heap = from_array(array, len, compare_int);
  for(int i = 0; i<heap->ff; i++)
    printf("%d, ", *(int*)heap->array[i]);
  printf("\n");

  printf("Is max heap? %d\n", is_max_heap_it(heap->array, len, compare_int));

  return 1;
}
