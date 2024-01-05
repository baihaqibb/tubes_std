#include <iostream>
#include "list_parent_SLL.h"

using namespace std;

/**PRIMITIVE SUBPROGRAMS*/
void createListParent(List_parent &L){
/*I.S. terdefinisi list parent
F.S. list parent kosong*/
    L.first = NULL;
}
address_p createElmParent(string id, string name){
/*mengembalikan alamat elemen baru parent berisi string id dan string name*/
    address_p P = new elm_parent;
    P->info.id = id;
    P->info.name = name;
    P->next = NULL;
    return P;
}
bool isEmptyParent(List_parent &L){
/*mengembalikan true jika list parent kosong dan false jika tidak*/
    return L.first == NULL;
}
bool isOnlyOneParent(List_parent &L){
/*mengembalikan true jika list parent hanya memiliki 1 elemen dan false jika tidak*/
    return L.first->next == NULL;
}
void insertFirstParent(List_parent &L, address_p P){
/*I.S. terdefinisi sebuah list L dan sebuah pointer P yang berisi alamat suatu elemen baru
F.S. elemen dengan alamat P dimasukkan ke dalam list sebagai elemen pertama*/
    P->next = L.first;
    L.first = P;
}
void insertLastParent(List_parent &L, address_p P){
/*I.S. terdefinsi sebuat list L bertipe list parent dan sebuah pointer P yang berisi alamat suatu elemen baru
F.S. elemen dengan alamat P dimasukkan ke dalam list sebagai elemen terakhir*/
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
/*I.S. terdefinsi sebuat list L bertipe list parent, sebuah pointer Pre berisi alamat suatu elemen, dan sebuah pointer P yang berisi alamat suatu elemen baru
F.S. elemen dengan alamat P dimasukkan ke dalam list sebagai elemen dengan posisi tertentu*/
    if (Pre != NULL) {
        P->next = Pre->next;
        Pre->next = P;
    }
}
void deleteFirstParent(List_parent &L, address_p &P){
/*I.S. terdefinsii list L yang mungkin kosong dan pointer P yang akan menunjuk elemen yang dihapus dari list parent
F.S. pointer P berisi alamat elemen yang dihapus dari list L yang merupakan elemen pertama list*/
    if (isEmptyParent(L)) {
        cout << "PARENT LIST EMPTY" << endl;
    } else {
        P = L.first;
        L.first = L.first->next;
        P->next = NULL;
    }
}
void deleteLastParent(List_parent &L, address_p &P){
/*I.S. terdefinsii list L yang mungkin kosong dan pointer P yang akan menunjuk elemen yang dihapus dari list parent
F.S. pointer P berisi alamat elemen yang dihapus dari list L yang merupakan elemen terakhir list*/
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
/*I.S. terdefinsii list L yang mungkin kosong, pointer Pre berisi alamat suatu elemen parent, dan pointer P yang akan menunjuk elemen yang dihapus dari list parent
F.S. pointer P berisi alamat elemen yang dihapus dari list L dengan posisi tertentu dalam list*/
    if (Pre == NULL || Pre->next == NULL) {
        P = NULL;
    } else {
        P = Pre->next;
        Pre->next = P->next;
        P->next = NULL;
    }
}
address_p findElmParent(List_parent &L, string id){
/*mengembalikan alamat elemen parent dalam list L dengan string id*/
    address_p P = L.first;
    bool found = false;
    while (P != NULL && !found) {
        found = (id == P->info.id);
        if (!found) {
            P = P->next;
        }
    }
    return P;
}
void printListParent(List_parent L){
/*I.S. list parent yang mungkin kosong
F.S. elemen dalam list parent ditampilakn ke layar*/
    address_p P = L.first;
    cout << "====================" << endl;
    while (P != NULL) {
        cout << P->info.id << " - " << P->info.name << endl;
        P = P->next;
    }
    cout << "====================" << endl << endl;
}
