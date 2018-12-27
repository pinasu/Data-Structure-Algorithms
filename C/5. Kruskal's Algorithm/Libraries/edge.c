#include "../Headers/edge.h"
#include "../../utils/Headers/equals.h"

/* Ege constructor */
Edge new_edge(Vertex v1, Vertex v2, double weight){
  Edge e;
  e = (Edge)malloc(sizeof(struct _edge));
  e-> v1 = v1;
  e-> v2 = v2;
  e-> weight = weight;

  return e;
}

/* Function to get edge list from Djset */
ArraylistCompare to_edge_list(Djset djset){
  int i = 0;
  ArraylistCompare edge_list = new_arraylist_compare(djset->arraylist->ff, compare_edge);

  AdjList adj;
  Edge ins;
  Vertex v1 = NULL;
  Vertex v2 = NULL;
  double weight = 0;

  for(i=0; i < djset-> arraylist-> ff; i++){
    List iter = djset-> arraylist-> array[i];

    v1 = iter-> value;
    adj = v1-> adj;

    while(adj != NULL){
      v2 = adj-> v;
      weight = adj-> weight;
      ins = new_edge(v1, v2, weight);

      insert_arraylist_compare(ins, edge_list);

      adj = adj-> next;
    }
  }

  return edge_list;
}

/* Function to check if two Verteces are equals */
int equals_vertex(void* a, void* b){
  Vertex v1 = (Vertex)a;
  Vertex v2 = (Vertex)b;

  return strcmp(v1-> value, v2-> value);
}
