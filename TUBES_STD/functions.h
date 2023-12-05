#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "list_parent_SLL.h"
#include "list_relation_CDLL.h"
#include "list_child_CSLL.h"

#include <iostream>

using namespace std;

void addEducationData(List_parent &L);
void addEmployeeData(List_child &L);
void searchEmployeeData(List_child L, string id);
void addRelationData(List_relation &L, address_p Prt, address_c Cld);
void searchEmployeesOfEducation(List_relation &LR, address_p P);
void deleteEducationWithRelations(List_parent &LP, List_relation &LR);
void deleteEmployeesOfEducation(List_relation &LR, List_parent &LP, List_child &LC);
void showAllEmployeesWithEducation(List_relation LR);
void showEmployeesWithMostEducations(List_relation LR);
void showEducationsWithMostEmployees(List_relation LR);

int inputMenu();
void menuHandler(int x);

#endif // FUNCTIONS_H_INCLUDED
