#include "record.h"

/*
 * Typedef: int (*compare)
 * -------------------------
 * Compare function pointer definition for generic types.
 *
 * a: pointer to the first generic type element,
 * b: pointer to the second generic type element,
 *
 */
typedef int (*compare)(void* a, void* b);

/*
 * Function: compare_int
 * -------------------------
 * Compare function pointer definition for int types.
 *
 * a: pointer to the first int element,
 * b: pointer to the second int element,
 *
 * returns: -1, 0, 1 if the first element is less, equal or greater than
 * the second one
 */
 int compare_int(void* a, void* b);

 /*
  * Function: compare_string
  * -------------------------
  * Compare function pointer definition for string types.
  *
  * a: pointer to the first string element,
  * b: pointer to the second string element,
  *
  * returns: -1, 0, 1 if the first element is less, equal or greater than
  * the second one
  */
int compare_string(void* a, void* b);

/*
 * Function: compare_string
 * -------------------------
 * Compare function pointer definition for float types.
 *
 * a: pointer to the first float element,
 * b: pointer to the second float element,
 *
 * returns: -1, 0, 1 if the first element is less, equal or greater than
 * the second one
 */
int compare_float(void* a, void* b);
