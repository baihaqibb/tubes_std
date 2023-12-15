#ifndef LIST_CHILD_CSLL_H_INCLUDED
#define LIST_CHILD_CSLL_H_INCLUDED

#include <iostream>

using namespace std;

struct employee {
    string id;
    string name;
    char gender;
    int age;
    int hiddenCountOfEdu = 0;
};
typedef struct employee infotype_c;
typedef struct elm_child *address_c;
struct elm_child {
    infotype_c info;
    address_c next;
};
struct List_child {
    address_c first;
};

/**PRIMITIVE SUBPROGRAMS*/
void createListChild(List_child &L);
address_c createElmChild(string id, string name, char gender, int age);
bool isEmptyChild(List_child &L);
bool isOnlyOneChild(List_child &L);
void insertFirstChild(List_child &L, address_c P);
void insertLastChild(List_child &L, address_c P);
void insertAfterChild(List_child &L, address_c Pre, address_c P);
void deleteFirstChild(List_child &L, address_c &P);
void deleteLastChild(List_child &L, address_c &P);
void deleteAfterChild(List_child &L, address_c Pre, address_c &P);
address_c findElmChild(List_child &L, string id);
void printListChild(List_child L);

#endif // LIST_CHILD_CSLL_H_INCLUDED
