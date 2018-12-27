#ifndef STD_H
#include "std.h"
#endif

/* Equals definition */
typedef int (*equals)(void* a, void* b);

/* Equals prototype for integers */
int equals_int(void* a, void* b);

/* Equals prototype for strings */
int equals_string(void* a, void* b);

/* Equals prototype for floating points */
int equals_float(void* a, void* b);
