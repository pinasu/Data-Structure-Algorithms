#include "Headers/tree.h"

/* Application main */
int main(){
  Node tree = NULL;
  read_file(&tree, compare_string);

  Node tree_bin = get_binary(tree, compare_string);

  return 0;
}
