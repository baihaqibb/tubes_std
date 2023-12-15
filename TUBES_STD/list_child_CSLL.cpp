#include "list_child_CSLL.h"

/**PRIMITIVE SUBPROGRAMS*/
void createListChild(List_child &L){
    L.first = NULL;
}
address_c createElmChild(string id, string name, char gender, int age){
    address_c P = new elm_child;
    P->info.id = id;
    P->info.name = name;
    P->info.gender = gender;
    P->info.age = age;
    P->next = NULL;
    return P;
}
bool isEmptyChild(List_child &L){
    return L.first == NULL;
}
bool isOnlyOneChild(List_child &L){
    return L.first->next == L.first;
}
void insertFirstChild(List_child &L, address_c P){
    address_c last;
    if (isEmptyChild(L)) {
        P->next = P;
        L.first = P;
    } else {
        last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}
void insertLastChild(List_child &L, address_c P){
    address_c last;
    if (isEmptyChild(L)) {
        P->next = P;
        L.first = P;
    } else {
        last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
    }
}
void insertAfterChild(List_child &L, address_c Pre, address_c P){
    if (Pre != NULL) {
        P->next = Pre->next;
        Pre->next = P;
    }
}
void deleteFirstChild(List_child &L, address_c &P){
    address_c last;
    if (isEmptyChild(L)) {
        cout << "CHILD LIST EMPTY" << endl;
    } else if (isOnlyOneChild(L)) {
        P = L.first;
        L.first = NULL;
        P->next = NULL;
    } else {
        last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P = L.first;
        L.first = L.first->next;
        last->next = L.first;
        P->next = NULL;
    }
}
void deleteLastChild(List_child &L, address_c &P){
    address_c last;
    address_c beforeLast;
    if (isEmptyChild(L)) {
        cout << "CHILD LIST EMPTY" << endl;
    } else if (isOnlyOneChild(L)) {
        P = L.first;
        L.first = NULL;
        P->next = NULL;
    } else {
        last = L.first;
        while (last->next != L.first) {
            beforeLast = last;
            last = last->next;
        }
        P = last;
        beforeLast->next = L.first;
        P->next = NULL;
    }
}
void deleteAfterChild(List_child &L, address_c Pre, address_c &P){
    if (Pre == NULL) {
        P = NULL;
    } else {
        if (Pre->next == L.first) {
            L.first = L.first->next;
        }
        P = Pre->next;
        Pre->next = P->next;
        P->next = NULL;
    }
}
address_c findElmChild(List_child &L, string id){
    address_c P = L.first;
    bool found = false;
    if (!isEmptyChild(L)) {
        do {
            found = (id == P->info.id);
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
void printListChild(List_child L){
    address_c P = L.first;
    cout << "====================" << endl;
    if (!isEmptyChild(L)) {
        cout << "--------------------" << endl;
        do {
            cout << "ID    : " << P->info.id << endl;
            cout << "Name  : " << P->info.name << endl;
            cout << "Gender: " << P->info.gender << endl;
            cout << "Age   : " << P->info.age << endl;
            cout << "--------------------" << endl;
            P = P->next;
        } while (P != L.first);
    }
    cout << "====================" << endl << endl;
}
