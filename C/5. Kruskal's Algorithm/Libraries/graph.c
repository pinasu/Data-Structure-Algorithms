#include "../Headers/graph.h"

/* Graph constructor */
Graph new_graph(int size, equals e){
	return new_arraylist_equals(size, e);
}

/* Function to add Vertex to Graph */
void add_graph(Graph g, Vertex v){
  insert_arraylist(v, g-> arraylist);
}

/* Function to print Graph */
void print_graph(Graph g){
  int i = 0;
  printf("\n");
  while(i < g-> arraylist-> ff){
    Vertex tmp = (Vertex)g-> arraylist-> array[i];
    printf("%s: [", (char*)tmp-> value);

    AdjList iterator = tmp-> adj;
    while(iterator != NULL){
      printf("%s", (char*)iterator-> v-> value);
      iterator = iterator-> next;

      if(iterator != NULL)
        printf(",");
    }
    printf("]\n");
    i++;
  }
  printf("\n");
}

/* Function to find Vertex in Graph */
Vertex find_vertex(Graph g, Vertex v){
  int i= 0;
  while(i < g-> arraylist-> ff){
    if(g-> eq(((Vertex)(g-> arraylist-> array[i]))->value, v->value) == 1)
      return (Vertex)g-> arraylist-> array[i];

    i++;
  }
  return NULL;
}

/* Function to read Graph from file */
Graph read_file(equals e){
  FILE* fp = fopen("../../../test.csv", "r");
  char ch;
  char tmp[STRING_LENGTH];
  Graph graph = new_graph(5, e);

  int i = 0;
  while(fscanf(fp, "%c", &ch) > 0){
    if(ch == '\n'){
      tmp[i] = '\0';
      create_graph(graph, tmp);
      i = 0;
    }
    else{
      tmp[i] = ch;
      i++;
    }
  }

  fclose(fp);
  printf("Graph created (%d vertices)\n", graph-> arraylist-> ff);

  return graph;
}

/* Function to create Graph from string */
void create_graph(Graph g, char* line){
  char* token;

  token = strtok(line, ",");
  char* v1 = (char*)malloc(sizeof(char)*CHARS_LENGTH);
  strcpy(v1, token);

  token = strtok(NULL, ",");
  char* v2 = (char*)malloc(sizeof(char)*CHARS_LENGTH);
  strcpy(v2, token);

  token = strtok(NULL, "\0");
  double w = atof(token);

  Vertex vertex1 = new_vertex(v1);
  Vertex vertex2 = new_vertex(v2);

  if(find_vertex(g, vertex1) == NULL)
    add_graph(g, vertex1);

  if(find_vertex(g, vertex2) == NULL)
    add_graph(g, vertex2);

  add_adj(find_vertex(g, vertex1), vertex2, w);
  add_adj(find_vertex(g, vertex2), vertex1, w);

}
