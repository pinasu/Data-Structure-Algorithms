#define EDG

#ifndef STD_H
#include "std.h"
#endif

#include "graph.h"

/* Edge pointer definion */
typedef struct _edge* Edge;

/* Struct Edge definition */
struct _edge{
  Vertex v1;
  Vertex v2;
  double weight;
};

#ifndef ARR_CMP
#include "../../utils/Headers/arraylist_compare.h"
#endif

/* Function prototype to create edge list from given Djset */
ArraylistCompare to_edge_list(Djset djset);

/* Function prototype to create new Edge */
Edge new_edge(Vertex v1, Vertex v2, double weight);

/* Function prototype to create edge list from given Djset */
int equals_vertex(void* a, void* b);
