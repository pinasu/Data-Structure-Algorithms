#include "Headers/std.h"
#include "Headers/djset.h"

/* Application main */
int main(){
  Arraylist a = new_arraylist(5);

  insert_arraylist("A", a);
  insert_arraylist("B", a);
  insert_arraylist("C", a);
  insert_arraylist("G", a);
  insert_arraylist("E", a);
  insert_arraylist("D", a);
  insert_arraylist("F", a);

  Djset d = create_set(a-> array, a->ff, equals_string);

  print_djset(d);

  union_set(d, "A", "C");
  union_set(d, "G", "F");

  print_djset(d);

  return 0;
}
