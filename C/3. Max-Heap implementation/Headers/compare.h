#ifndef STD_H
#include "std.h"
#endif

/* Compare definition */
typedef int (*compare)(void* a, void* b);

/* Compare prototype for integers */
int compare_int(void* a, void* b);

/* Compare prototype for strings */
int compare_string(void* a, void* b);

/* Compare prototype for floating points */
int compare_float(void* a, void* b);
