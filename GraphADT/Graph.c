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

void freeGraph(Graph* pG) {
    if (pG != NULL && pG != NULL)  {
        Graph G = *pG;

        for (int i = 1; i <= (*pG)->order; i++) {
            freeList(&(G->adj[i]));
        }
        free(G->adj);
        free(G->color);
        free(G->dist);
        free(G->parent);

        free(G);
        *pG = NULL;
    }
}

int getOrder(Graph G) {
     if ( G == NULL) {
        fprintf(stderr, "Graph error: getOrder(): NULL Graph refernce");
        exit(EXIT_FAILURE);
    }
    return G -> order;

}

int getNumEdges(Graph G){
    if ( G == NULL) {
        fprintf(stderr, "Graph error: getNumEdges(): NULL Graph refernce");
        exit(EXIT_FAILURE);
    }

    return G-> numEdges;
}

int getNumArcs (Graph G){
     if ( G == NULL) {
        fprintf(stderr, "Graph error: getNumArcs(): NULL Graph refernce");
        exit(EXIT_FAILURE);
    }

    return G-> numArcs;
}

int getSource (Graph G){
     if ( G == NULL) {
        fprintf(stderr, "Graph error: getSource(): NULL Graph refernce");
        exit(EXIT_FAILURE);
    }

    return G-> source;
}

int getParent (Graph G, int u) {
     if ( G == NULL) {
        fprintf(stderr, "Graph error: getParent(): NULL Graph refernce");
        exit(EXIT_FAILURE);
    }
    if (1 > u || u > G->order) {
        fprintf(stderr, "Graph error: getParent(): vertex %d out of range 1.. %d", u, G->order);
        exit(EXIT_FAILURE);
    }

    return G -> parent[u];
}

int getDist(Graph G, int u) {
    if ( G == NULL) {
        fprintf(stderr, "Graph error: getDist(): NULL Graph refernce");
        exit(EXIT_FAILURE);
    }
    if (1 > u || u > G->order) {
        fprintf(stderr, "Graph error: getDist(): vertex %d out of range 1.. %d", u, G->order);
        exit(EXIT_FAILURE);
    }


    return G-> dist[u];
}

void getPath(List L, Graph G, int u) {
        if (L == NULL) {
        fprintf(stderr, "Graph Error: getPath(): NULL List reference\n");
        exit(EXIT_FAILURE);
    }
     if (G == NULL) {
        fprintf(stderr, "Graph Error: getPath(): NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if ( 1 > u || u > G->order) {
        fprintf(stderr, "Graph error: getPath(): vertex %d out of range 1.. %d", u, G->order);
        exit(EXIT_FAILURE);
    }
    if ( G->source == NIL) { 
         fprintf(stderr, "Graph Error: getPath(): BFS not run (source is NIL)\n");
         exit(EXIT_FAILURE);
    }

    if (G-> source == u) {
        append(L, u);
    } else if (G->parent[u] == NIL ) {
        append(L, NIL);
    } else {
        getPath(L, G, G->parent[u]);
        append(L, u);
    }

}
