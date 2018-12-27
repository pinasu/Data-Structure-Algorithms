#include "vertex.h"
#include "djset.h"

/*Constant for max string length*/
#define STRING_LENGTH 500

/*Constant for max read chars length*/
#define CHARS_LENGTH 50

/* Graph definition as ArraylistEquals */
typedef ArraylistEquals Graph;

/* Function prototye to create Graph */
Graph new_graph(int size, equals e);

/* Function prototye to add given Vertex to given Graph */
void add_graph(Graph g, Vertex v);

/* Function prototye to print given Graph */
void print_graph(Graph g);

/* Function prototye to check if given Vertex is in Graph */
Vertex find_vertex(Graph g, Vertex v);

/* Function prototype to read from file record */
Graph read_file(equals e);

/* Function prototye to insert elements into given Graph */
void create_graph(Graph g, char* line);
