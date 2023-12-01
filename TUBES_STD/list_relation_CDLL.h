#ifndef LIST_RELATION_CDLL_H_INCLUDED
#define LIST_RELATION_CDLL_H_INCLUDED

#include <iostream>

#include "list_parent_SLL.h"
#include "list_child_CSLL.h"

using namespace std;

typedef struct elm_relation *address_r;
struct elm_relation {
    address_p parent;
    address_c child;
    address_r next;
    address_r prev;
};
struct List_relation {
    address_r first;
    address_r last;
};

//PRIMITIVE SUBPROGRAMS
void createListRel(List_relation &L);
address_r createElmRel(address_p Prt, address_c Cld);
bool isEmptyRel(List_relation &L);
bool isOnlyOneRel(List_relation &L);
void insertFirstRel(List_relation &L, address_r P);
void insertLastRel(List_relation &L, address_r P);
void insertAfterRel(List_relation &L, address_r Pre, address_r P);
void deleteFirstRel(List_relation &L, address_r &P);
void deleteLastRel(List_relation &L, address_r &P);
void deleteAfterRel(List_relation &L, address_r Pre, address_r &P);
address_r findElmRel(List_relation &L, address_p prt, address_c cld);
void printListRel(List_relation L);

#endif // LIST_RELATION_CDLL_H_INCLUDED
