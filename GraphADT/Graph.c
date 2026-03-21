#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "List.h"
#include "Graph.h"


#define WHITE 0
#define GRAY  1
#define BLACK 2


typedef struct GraphObj {
    int order; 
    int numEdges; 
    int numArcs;
    int source; 
    List* adj;
    int* color;
    int* dist; 
    int* parent;
} GraphObj;

Graph newGraph(int n) {
    Graph G = malloc(sizeof(GraphObj));

    G->order = n; 
    G->numEdges = 0;
    G->numArcs = 0;
    G->source = NIL;

    G->adj = calloc(n+1, sizeof(List));
    G->color = calloc(n+1, sizeof(int));
    G->dist = calloc(n+1, sizeof(int));
    G->parent = calloc(n+1, sizeof(int));

    if (G->adj == NULL || G->color == NULL || G->dist == NULL || G->parent == NULL) {
    fprintf(stderr, "Graph Error: newGraph(): calloc failed\n");
    exit(EXIT_FAILURE);
    }


    for (int i = 1; i <= n; i++) {
        G->adj[i] = newList();
        G->color[i] = WHITE;
        G->dist[i] = INF;
        G->parent[i]= NIL;
    }

    return G;

}
