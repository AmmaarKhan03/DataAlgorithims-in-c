#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_

#include <stdio.h>
#include <stdbool.h>

#define FORMAT "%d"  // format specifier for List 

typedef struct ListObj* List;
typedef int ListElement; 

List newList(void);
void freeList(List* pL);

int length(List L);
int position(List L);
ListElement front(List L);
ListElement back(List L);
ListElement get(List L);
bool equals(List A, List B);

void clear(List L);
void set(List L, ListElement x); 
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);

void moveNext(List L);
void prepend(List L, ListElement data);
void append(List L, ListElement data);
void insertBefore(List L, ListElement data);
void insertAfter(List L, ListElement data);
void deleteFront(List L);
void deleteBack(List L);
void deleteElement(List L);

void printList(FILE* out, List L);
List copyList(List L);
List join(List A, List B);

List split(List L);















#endif
