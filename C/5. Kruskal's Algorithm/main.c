#include "Headers/kruskal.h"

/* Application main */
int main(){
  Graph g = read_file(equals_string);

  ArraylistCompare mst = kruskal(g);

  return 0;
}
