#include "list_parent_SLL.h"

//PRIMITIVE SUBPROGRAMS
void createListParent(List_parent &L){
    L.first = NULL;
}
address_p createElmParent(infotype_p x){
    address_p P = new elm_parent;
    P->info = x;
    P->next = NULL;
    return P;
}
bool isEmptyParent(List_parent &L){
    return L.first == NULL;
}
bool isOnlyOneParent(List_parent &L){
    return L.first->next == NULL;
}
void insertFirstParent(List_parent &L, address_p P){
    P->next = L.first;
    L.first = P;
}
void insertLastParent(List_parent &L, address_p P){
    address_p last;
    if (isEmptyParent(L)) {
        L.first = P;
    } else {
        last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
    }
}
void insertAfterParent(List_parent &L, address_p Pre, address_p P){
    P->next = Pre->next;
    Pre->next = P;
}
void deleteFirstParent(List_parent &L, address_p &P){
    if (isEmptyParent(L)) {
        cout << "PARENT LIST EMPTY" << endl;
    } else {
        P = L.first;
        L.first = L.first->next;
        P->next = NULL;
    }
}
void deleteLastParent(List_parent &L, address_p &P){
    address_p last;
    address_p beforeLast;
    if (isEmptyParent(L)) {
        cout << "PARENT LIST EMPTY" << endl;
    } else if (isOnlyOneParent(L)) {
        P = L.first;
        L.first = NULL;
    } else {
        last = L.first;
        while (last->next != NULL) {
            beforeLast = last;
            last = last->next;
        }
        P = last;
        beforeLast->next = NULL;
    }
}
void deleteAfterParent(List_parent &L, address_p Pre, address_p &P){
    P = Pre->next;
    Pre->next = P->next;
    P->next = NULL;
}
address_p findElmParent(List_parent &L, infotype_p x){
    address_p P = L.first;
    bool found = false;
    while (P != NULL && !found) {
        found = (x == P->info);
        P = P->next;
    }
    return P;
}
void printListParent(List_parent L){
    address_p P = L.first;
    cout << "====================" << endl;
    while (P != NULL) {
        cout << P->info << endl;
    }
    cout << "====================" << endl << endl;
}