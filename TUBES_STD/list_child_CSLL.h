#ifndef LIST_CHILD_CSLL_H_INCLUDED
#define LIST_CHILD_CSLL_H_INCLUDED

#include <iostream>

using namespace std;

struct employee {
    string id;
    string name;
    string gender;
    string age;
};
typedef struct employee infotype_c;
typedef elm_child *address_c;
struct elm_child {
    infotype_c info;
    address_c next;
};
struct list_child {
    address_c first;
};

#endif // LIST_CHILD_CSLL_H_INCLUDED
