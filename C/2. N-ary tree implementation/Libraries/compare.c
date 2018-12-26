#include "../Headers/compare.h"

/*
 * Function: compare_int
 * -------------------------
 * Compares two _record based on the int field.
 *
 */
int compare_int(void* a, void* b){
  Record tmp_a = (Record)a;
  Record tmp_b = (Record)b;

  if(tmp_a->field3 < tmp_b->field3)
	  return -1;
  else if(tmp_a->field3 == tmp_b->field3)
	  return 0;
  return 1;
}

/*
 * Function: compare_string
 * -------------------------
 * Compares two _record based on the string field.
 *
 */
int compare_string(void* a, void* b){
  Record tmp_a = (Record)a;
  Record tmp_b = (Record)b;

  return strcmp(tmp_a->field1, tmp_b->field1);
}

/*
 * Function: compare_float
 * -------------------------
 * Compares two _record based on the float field.
 *
 */
 int compare_float(void* a, void* b){
  Record tmp_a = (Record)a;
  Record tmp_b = (Record)b;

  if(tmp_a->field2 < tmp_b->field2)
	  return -1;
  else if(tmp_a->field2 == tmp_b->field2)
	  return 0;
  return 1;
}
