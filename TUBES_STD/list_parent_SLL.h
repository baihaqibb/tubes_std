#ifndef LIST_PARENT_SLL_H_INCLUDED
#define LIST_PARENT_SLL_H_INCLUDED

#include <iostream>

using namespace std;

typedef string infotype_p;
typedef elm_parent *address_p;
struct elm_parent {
    infotype info;
    address_p next;
};
struct List_parent {
    address_p first;
};

//PRIMITIVE SUBPROGRAMS
void createListParent(List_parent &L);
address_p createElmParent(infotype_p x);
void insertFirstParent(List_parent &L, address_p P);
void insertLastParent(List_parent &L, address_p P);
void insertAfterParent(List_parent &L, address_p Pre, address_p P);
void deleteFirstParent(List_parent &L, address_p &P);
void deleteLastParent(List_parent &L, address_p &P);
void deleteAfterParent(List_parent &L, address_p Pre, address_p &P);
address_p findElmParent(List_parent &L, infotype_p x);
void printListParent(List_parent L);

#endif // LIST_PARENT_SLL_H_INCLUDED
