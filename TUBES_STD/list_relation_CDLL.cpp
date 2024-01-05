#include <iostream>
#include "list_relation_CDLL.h"

using namespace std;

/**PRIMITIVE SUBPROGRAMS*/
void createListRel(List_relation &L){
/*I.S. terdefinsi list relation
F.S. list relation kosong*/
    L.first = NULL;
    L.last = NULL;
}
address_r createElmRel(address_p prt, address_c cld){
/*mengembalikan alamat elemen baru relation berisi alamat parent prt dan alamat child cld*/
    address_r P = new elm_relation;
    P->parent = prt;
    P->child = cld;
    P->next = NULL;
    P->prev = NULL;
    return P;
}
bool isEmptyRel(List_relation &L){
/*mengembalikan true jika list relation kosong dan false jika tidak*/
    return L.first == NULL && L.last == NULL;
}
bool isOnlyOneRel(List_relation &L){
/*mengembalikan true jika list relation hanya memiliki datu elemen dan false jika tidak*/
    return L.first == L.last && L.first != NULL && L.last != NULL;
}
void insertFirstRel(List_relation &L, address_r P){
/*I.S. list relation yang mungkin kosong dan suatu alamat relation yang menunjuk suatu elemen relation yang akan dimasukkan ke dalam list
F.S. elemen baru ditambahkan sebagai elemen pertama ke dalam list relation*/
    if (isEmptyRel(L)) { /*jika list relation kosong*/
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
/*I.S. list relation yang mungkin kosong dan suatu alamat relation yang menunjuk suatu elemen relation yang akan dimasukkan ke dalam list
F.S. elemen baru ditambahkan sebagai elemen terakhir ke dalam list relation*/
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
/*I.S. list relation yang mungkin kosong dan suatu alamat relation yang menunjuk suatu elemen relation yang akan dimasukkan ke dalam list
F.S. elemen baru ditambahkan dengan posisi tertentu ke dalam list relation*/
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
/*I.S. list relation yang mungkin kosong dan suatu alamat relation yang akan menunjuk suatu elemen yang akan dihapus dari list
F.S. alamat P berisi elemen pertama relation yang dihapus*/
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
/*I.S. list relation yang mungkin kosong dan suatu alamat relation yang akan menunjuk suatu elemen yang akan dihapus dari list
F.S. alamat P berisi elemen terakhir relation yang dihapus*/
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
/*I.S. list relation yang mungkin kosong dan suatu alamat relation yang akan menunjuk suatu elemen yang akan dihapus dari list
F.S. alamat P berisi elemen relation dengan posisi tertentu yang dihapus*/
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
/*mengembalikan alamat relatiion yang menunjuk elemen relation dengan alamat parent prt dan alamat child cld*/
    address_r P = L.first;
    bool found = false;
    if (!isEmptyRel(L)) { /*jika list relation tidak kosong*/
        do {
            found = (prt == P->parent && cld == P->child); /*found bernilai true jika alamat P yang menunjuk suatu elemen relation memiliki alamat parent yang sama dengan prt dan alamat child yang sama dengan cld*/
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
/*I.S. list relation yang mungkin kosong
F.S. elemen dalam list relation ditampilakn ke layar*/
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
