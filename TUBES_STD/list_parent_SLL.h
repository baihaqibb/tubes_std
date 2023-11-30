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
struct list_parent {
    address_p first;
};

#endif // LIST_PARENT_SLL_H_INCLUDED
