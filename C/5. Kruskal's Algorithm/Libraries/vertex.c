#include "../Headers/vertex.h"

/* Vertex constructor */
Vertex new_vertex(void* value){
  Vertex v;
  v = (Vertex)malloc(sizeof(struct _vertex));
  v-> value = value;
  v-> adj = NULL;

  return v;
}

/* Function to add Vertex b to Vertex a Adjlist */
void add_adj(Vertex a, Vertex b, double weight){
  add_head(&(a-> adj), b, weight);
}
