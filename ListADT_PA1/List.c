#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "List.h"

typedef struct NodeObj {
    ListElement data; 
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

typedef NodeObj* Node; 

typedef struct ListObj {
    Node front;
    Node back;
    Node cursor;
    int length; 
    int index; 
} ListObj;

Node newNode(ListElement data) {
    Node N = malloc(sizeof(NodeObj));
    assert(N!=NULL);
    N->data = data; 
    N->next = NULL;
    N->prev = NULL;
    return N; 
}

void freeNode(Node* pN) {
    if (pN != NULL && *pN != NULL) {
        free (*pN);
        *pN = NULL;
    }
}

List newList(void) {
    List L = malloc(sizeof(ListObj));
    assert(L != NULL);
    L->front = NULL;
    L->back = NULL;
    L->cursor = NULL;
    L-> length = 0;
    L ->index = -1;

    return L; 

}

int length (List L) {
    if(L == NULL) {
         fprintf(stderr, "List Error: length(): NULL List reference\n");
         exit(EXIT_FAILURE);
    }

    return L->length;

}

int postion (List L) {
     if(L == NULL) {
        fprintf(stderr, "List Error: position(): NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    return L->index;
    

}


ListElement front(List L ) {
    if (L == NULL) {
        fprintf(stderr, "List Error: front(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }

    if (L->length == 0) {
        fprintf(stderr, "List Error: front(): Empyt List\n");
        exit(EXIT_FAILURE);
    }

    return L->front->data;
}
ListElement back (List L ) {
      if (L == NULL) {
        fprintf(stderr, "List Error: back(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }

    if (L->length == 0) {
        fprintf(stderr, "List Error: back(): Empyt List\n");
        exit(EXIT_FAILURE);
    }

    return L->back->data;
}

ListElement get(List L) {
      if (L == NULL) {
        fprintf(stderr, "List Error: get(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }

    if (L->length == 0) {
        fprintf(stderr, "List Error: get(): Empyt List\n");
        exit(EXIT_FAILURE);
    }

    if (L->index <0) {
        fprintf(stderr, "List Error: get(): No cursor\n");
        exit(EXIT_FAILURE);
    }

    return L->cursor->data;

}

bool equals(List A, List B) {
    if (A == NULL || B == NULL) {
        fprintf(stdout, "List error: equals(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }
    if (A->length != B->length) {
        return false; 
    }
    Node a = A->front;
    Node b = B->front; 
    while (a != NULL && b != NULL) {
        if (a->data != b->data) return false; 
        a = a->next;
        b = b->next; 
    }

    return true; 


    

}




