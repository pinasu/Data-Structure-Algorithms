#define ADJLIST_H

#ifndef STD_H
#include "std.h"
#endif

/* AdjList pointer definition */
typedef struct _adjlist* AdjList;

#ifndef VERTEX_H
#include "vertex.h"
#endif

/* AdjList struct definition */
struct _adjlist{
	Vertex v;
	double weight;
	AdjList next;
};

/* Function prototype to create AdjList */
AdjList new_adjlist(Vertex v, double weight);

/* Function prototype to add element to AdjList as head */
void add_head(AdjList* head, Vertex v, double weight);
