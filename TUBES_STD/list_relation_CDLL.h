#ifndef LIST_RELATION_CDLL_H_INCLUDED
#define LIST_RELATION_CDLL_H_INCLUDED

#include <iostream>

#include "list_parent_SLL.h"
#include "list_child_CSLL.h"

using namespace std;

typedef struct elm_relation *address_r;
struct elm_relation {
    address_p parent;
    address_c child;
    address_r next;
    address_r prev;
};
struct list_relation {
    address_r first;
    address_r last;
};

#endif // LIST_RELATION_CDLL_H_INCLUDED
