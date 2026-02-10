#ifndef _LIST_H_
#define _LIST_H_


List newList();
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
void delete(List L);
void printList(FILE* out, List L);
List copyList(List L);
List join(List A, List B);

List split(List L);















#endif