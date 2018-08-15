#ifndef STD_H
#include "std.h"
#endif

/*
 * Struct: _record
 * -------------------------
 * _record structure definition
 *
 * id: the record id,
 * field1: the first field pointer, which is a string,
 * field2: the second field pointer, which is a float,
 * field3: the third field pointer, which is a int.
 *
 */
struct _record{
  int id;
  char* field1;
  float field2;
  int field3;
};

/*
 * Pointer: Record
 * -------------------------
 * _record structure pointer.
 *
 */
typedef struct _record* Record;

/*
 * Function: create_record
 * -------------------------
 * Prototype of create_record to create a _record pointer.
 *
 * str: the whole string from file, which contains comma-separated fields.
 *
 * returns: a new Record with desired infos.
 *
 */
Record create_record(char* str);

/*
 * Function: read_file
 * -------------------------
 * Prototype of read_file to create an _arraylist pointer.
 *
 * size: the size of the _arraylist to be created.
 *
 * returns: a new Arraylist of desired size.
 *
 */
void** read_file(int l);
