#include <iostream>
#include "list_child_CSLL.h"

using namespace std;

/**PRIMITIVE SUBPROGRAMS*/
void createListChild(List_child &L){
/*I.S. terdefinsi list child
F.S. list child kosong*/
    L.first = NULL;
}
address_c createElmChild(string id, string name, char gender, int age){
/*mengembalikan alamat elemen baru child berisi string name, character gender, dan integer age*/
    address_c P = new elm_child;
    P->info.id = id;
    P->info.name = name;
    P->info.gender = gender;
    P->info.age = age;
    P->next = NULL;
    return P;
}
bool isEmptyChild(List_child &L){
/*mengembalikan true jika list child kosong dan false jika tidak*/
    return L.first == NULL;
}
bool isOnlyOneChild(List_child &L){
/*mengembalikan true jika list child hanya memiliki 1 elemen dan false jika tidak*/
    return L.first->next == L.first;
}
void insertFirstChild(List_child &L, address_c P){
/*I.S. terdefinisi sebuah list L dan sebuah pointer P yang berisi alamat suatu elemen baru
F.S. elemen dengan alamat P dimasukkan ke dalam list sebagai elemen pertama*/
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
/*I.S. terdefinsi sebuat list L bertipe list child dan sebuah pointer P yang berisi alamat suatu elemen baru
F.S. elemen dengan alamat P dimasukkan ke dalam list sebagai elemen terakhir*/
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
/*I.S. terdefinsi sebuat list L bertipe list child, sebuah pointer Pre berisi alamat suatu elemen, dan sebuah pointer P yang berisi alamat suatu elemen baru
F.S. elemen dengan alamat P dimasukkan ke dalam list sebagai elemen dengan posisi tertentu*/
    if (Pre != NULL) {
        P->next = Pre->next;
        Pre->next = P;
    }
}
void deleteFirstChild(List_child &L, address_c &P){
/*I.S. terdefinsii list L yang mungkin kosong dan pointer P yang akan menunjuk elemen yang dihapus dari list child
F.S. pointer P berisi alamat elemen yang dihapus dari list L yang merupakan elemen pertama list*/
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
/*I.S. terdefinsii list L yang mungkin kosong dan pointer P yang akan menunjuk elemen yang dihapus dari list child
F.S. pointer P berisi alamat elemen yang dihapus dari list L yang merupakan elemen terakhir list*/
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
/*I.S. terdefinsii list L yang mungkin kosong, pointer Pre berisi alamat suatu elemen child, dan pointer P yang akan menunjuk elemen yang dihapus dari list child
F.S. pointer P berisi alamat elemen yang dihapus dari list L dengan posisi tertentu dalam list*/
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
/*mengembalikan alamat elemen child dalam list L dengan string id*/
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
/*I.S. list child yang mungkin kosong
F.S. elemen dalam list child ditampilakn ke layar*/
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
