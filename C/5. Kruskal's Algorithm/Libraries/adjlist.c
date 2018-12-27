#include "../Headers/adjlist.h"

/* Vertex constructor */
AdjList new_adjlist(Vertex v, double weight){
  AdjList adj;
  adj = (AdjList)malloc(sizeof(struct _adjlist));
  adj-> v = v;
  adj-> weight = weight;
  adj-> next = NULL;

  return adj;
}

/* Function to add Vertex to AdjList */
void add_head(AdjList* head, Vertex v, double weight){
  AdjList n = new_adjlist(v, weight);
  n-> next = *head;
  *head = n;
}
