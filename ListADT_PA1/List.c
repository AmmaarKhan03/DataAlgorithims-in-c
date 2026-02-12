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


void clear (List L ) {

    if (L == NULL) {
        fprintf(stdout, "List error: clear(): NULL list refreence\n");
        exit(EXIT_FAILURE);
    }

    Node n = L->front;
    while (n != NULL) {
        Node temp = n; 
        n = n->next; 
        freeNode(&temp);
    }
    L->front = L->back = L->cursor = NULL; 
    L->length = 0; 
    L->index = -1;

}

void set (List L, ListElement x) {
    if (L == NULL ) {
        fprintf(stdout, "List error: set(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }

    if (length(L) == 0) {
        fprintf(stdout, "List error: set(): empty List\n");
        exit(EXIT_FAILURE);
    }
    if (length(L) < 0) {
        fprintf(stdout, "List error: set(): no cursor\n");
        exit(EXIT_FAILURE);
    }

    L ->cursor -> data = x;
}

void moveFront(List L) {
    if (L == NULL ) {
        fprintf(stdout, "List error: movefront(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }
    if (L->length > 0) {
        L->cursor = L->front;
        L->index = 0;
    }
}

void moveBack(List L) {
    if (L == NULL ) {
        fprintf(stdout, "List error: movefront(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }
    if (L->length > 0) {
        L->cursor = L->back;
        L->index = L->length - 1;
    }
}


void movePrev(List L) {
    if (L == NULL ) {
        fprintf(stdout, "List error: movePrev(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor != NULL) {
        if (L->cursor == L->front) {
            L->cursor = NULL;
            L->index = -1;
        } else {
            L-> cursor = L->cursor ->prev;
            L->index--;
        }
    }
}

void moveNext(List L) {
    if (L == NULL ) {
        fprintf(stdout, "List error: moveNext(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }

    if (L->cursor != NULL) {
        if (L-> cursor == L->back) {
            L-> cursor = NULL; 
            L->index = -1; 
        } else {
            L->cursor = L->cursor ->next; 
            L->index++;
        }
    }
}


void preprend (List L, ListElement data) {
    if (L == NULL ) {
        fprintf(stdout, "List error: prepend(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }
    Node n = newNode(data); 
    if (L ->length == 0) {
        L->front = L->back = n;  
        L ->length++;
    } else {
        n ->next = L->front; 
        L->front->prev = n; 
        L->front = n; 
        
        if(L->index >= 0) L->index ++;
    }
    L->length++;
}

void append(List L, ListElement data) {
    if (L == NULL ) {
        fprintf(stdout, "List error: append(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }

    Node n = newNode(data);
    if (length(L) == 0) {
        L->back = L->front = n;
        L->length++; 
    } else  {
        n -> prev = L ->back;
        L->back ->next= n; 
        L->back = n; 
        
        if (L->index >= 0) L->index++;
    }
    L -> length++;
}

void insertBefore(List L, ListElement data) {
     if (L == NULL ) {
        fprintf(stdout, "List error: insertbefore(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }
     if (L->length == 0) {
       fprintf(stderr, "List Error: insertBefore(): Empyt List\n");
        exit(EXIT_FAILURE);
    }
    if (L->index < 0) {
        fprintf(stderr, "List Error: insertBefore(): No cursor\n");
        exit(EXIT_FAILURE);
    }

    if (L->cursor == L->front) {
        prepend(L, data);
        return;
    }

    Node n = newNode(data); 
    Node c = L->cursor; 
    n ->prev = c->prev; 
    c->prev ->next = n;
    c ->prev = n; 

    L ->length++;
    L ->index++;
}

void insertAfter(List L, ListElement data) {
    if (L == NULL ) {
        fprintf(stdout, "List error: insertAfter(): NULL list reference\n");
        exit(EXIT_FAILURE);
    }

    if (L->length == 0) {
       fprintf(stderr, "List Error: insertAfter(): Empyt List\n");
        exit(EXIT_FAILURE);
    }
    if (L->index < 0) {
        fprintf(stderr, "List Error: insertfAter(): No cursor\n");
        exit(EXIT_FAILURE);
    }

    if (L->cursor == L->back) {
        append(L, data);
        return;
    }

    Node n = newNode(data);
    Node c = L->cursor; 

    n->next = c->next;
    n->prev = c;
    c->next->prev = n;
    c->next = n;
}

