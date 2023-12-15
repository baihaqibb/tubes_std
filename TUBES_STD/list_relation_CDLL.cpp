#include "list_relation_CDLL.h"

/**PRIMITIVE SUBPROGRAMS*/
void createListRel(List_relation &L){
    L.first = NULL;
    L.last = NULL;
}
address_r createElmRel(address_p prt, address_c cld){
    address_r P = new elm_relation;
    P->parent = prt;
    P->child = cld;
    P->next = NULL;
    P->prev = NULL;
    return P;
}
bool isEmptyRel(List_relation &L){
    return L.first == NULL && L.last == NULL;
}
bool isOnlyOneRel(List_relation &L){
    return L.first == L.last && L.first != NULL && L.last != NULL;
}
void insertFirstRel(List_relation &L, address_r P){
    if (isEmptyRel(L)) {
        P->next = P;
        P->prev = P;
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        P->prev = L.last;
        L.first->prev = P;
        L.last->next = P;
        L.first = P;
    }
}
void insertLastRel(List_relation &L, address_r P){
    if (isEmptyRel(L)) {
        P->next = P;
        P->prev = P;
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        P->prev = L.last;
        L.first->prev = P;
        L.last->next = P;
        L.last = P;
    }
}
void insertAfterRel(List_relation &L, address_r Pre, address_r P){
    if (Pre != NULL) {
        if (Pre == L.last) {
            insertLastRel(L, P);
        } else {
            P->next = Pre->next;
            P->prev = Pre;
            Pre->next->prev = P;
            Pre->next = P;
        }
    }
}
void deleteFirstRel(List_relation &L, address_r &P){
    if (isEmptyRel(L)) {
        cout << "RELATION LIST EMPTY" << endl;
    } else if (isOnlyOneRel(L)) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
        P->next = NULL;
        P->prev = NULL;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.last->next = L.first;
        L.first->prev = L.last;
        P->next = NULL;
        P->prev = NULL;
    }
}
void deleteLastRel(List_relation &L, address_r &P){
    if (isEmptyRel(L)) {
        cout << "RELATION LIST EMPTY" << endl;
    } else if (isOnlyOneRel(L)) {
        P = L.last;
        L.first = NULL;
        L.last = NULL;
        P->next = NULL;
        P->prev = NULL;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = L.first;
        L.first->prev = L.last;
        P->next = NULL;
        P->prev = NULL;
    }
}
void deleteAfterRel(List_relation &L, address_r Pre, address_r &P){
    if (Pre == NULL) {
        P = NULL;
    } else {
        if (Pre->next == L.first) {
            L.first = L.first->next;
        } else if (Pre->next == L.last) {
            L.last = L.last->prev;
        }
        if (L.first->next == L.first) {
            L.first = NULL;
            L.last = NULL;
        }
        P = Pre->next;
        Pre->next = P->next;
        P->next->prev = Pre;
        P->next = NULL;
        P->prev = NULL;
    }
}
address_r findElmRel(List_relation &L, address_p prt, address_c cld){
    address_r P = L.first;
    bool found = false;
    if (!isEmptyRel(L)) {
        do {
            found = (prt == P->parent && cld == P->child);
            if (!found) {
                P = P->next;
            }
        } while (P != L.first && !found);
    }
    if (found) {
        return P;
    } else {
        return NULL;
    }
}
void printListRel(List_relation L){
    address_r P = L.first;
    cout << "====================" << endl;
    if (!isEmptyRel(L)) {
        do {
            cout << "Parent: " << P->parent->info.id << " | Child: " << P->child->info.id << endl;
            P = P->next;
        } while (P != L.first);
    }
    cout << "====================" << endl << endl;
}
