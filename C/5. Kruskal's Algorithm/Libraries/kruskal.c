#include "../Headers/kruskal.h"

/* Function to get Graph weight */
double get_graph_weight(Graph g){
  int i = 0;
  double count = 0;

  while(i < g-> arraylist-> ff){
    Vertex tmp = (Vertex)g-> arraylist-> array[i];

    AdjList iterator = tmp-> adj;
    while(iterator != NULL){
      count += iterator-> weight;
      iterator = iterator-> next;
    }
    i++;
  }
  return count;
}

/* Function to get graph total weight */
double get_mst_weight(ArraylistCompare mst){
  double count = 0;
  int i = 0;

  while(i < mst-> arraylist-> ff){
    Edge tmp = (Edge)mst-> arraylist-> array[i];
    count += tmp-> weight;
    i++;
  }

  printf("MST total weight is %f\n", count);
  return count;
}

/* Kruskal algorithm implementation */
ArraylistCompare kruskal(Graph g){
  Djset djset = create_set(g-> arraylist-> array, g-> arraylist->ff, equals_vertex);

  ArraylistCompare edge_list = to_edge_list(djset);

  ArraylistCompare mst = new_arraylist_compare(edge_list->arraylist->ff, compare_edge);

  int i = 0;
  while(i < edge_list-> arraylist-> ff){
    Edge e = (Edge)edge_list-> arraylist-> array[i];

    if(find_set(djset, e->v1) != find_set(djset, e->v2)){
      union_set(djset, e-> v1, e-> v2);
      insert_arraylist_compare(e, mst);
    }

    i++;
  }

  printf("There are %d edges in MST\n", mst-> arraylist-> ff);

  get_mst_weight(mst);

  return mst;
}
