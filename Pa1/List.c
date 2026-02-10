#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "List.h"

typedef struct NodeObj {
    ListElement data; 
    struct NodeObj* next;
    struct NodeObj* prev;
};

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





