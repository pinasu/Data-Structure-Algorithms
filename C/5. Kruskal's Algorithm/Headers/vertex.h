#define VERTEX_H

#ifndef STD_H
#include "std.h"
#endif

/* Vertex pointer definition */
typedef struct _vertex* Vertex;

#ifndef ADJLIST_H
#include "adjlist.h"
#endif

/* Struct Vertex definition */
struct _vertex{
  void* value;
  AdjList adj;
};

/* Function prototye to create new Vertex */
Vertex new_vertex(void* value);

/* Function prototye to Vertex b to Vertex a AdjList */
void add_adj(Vertex a, Vertex b, double weight);
