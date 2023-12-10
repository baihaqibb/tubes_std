#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "list_parent_SLL.h"
#include "list_relation_CDLL.h"
#include "list_child_CSLL.h"

#include <iostream>

using namespace std;

void addEducationData(List_parent &L_Edu);
void addEmployeeData(List_child &L_Emp);
void searchEmployeeData(List_child L_Emp);
void addRelationData(List_relation &L_Rel, List_parent L_Edu, List_child L_Emp);
void searchEmployeesOfEducation(List_relation &L_Rel);
void deleteEducationWithRelations(List_parent &L_Edu, List_relation &L_Rel);
void deleteEmployeesOfEducation(List_relation &L_Rel, List_parent L_Edu, List_child &L_Emp);
void showAllEmployeesWithEducation(List_relation L_Rel);
void showEmployeesWithMostEducations(List_child L_Emp, List_relation L_Rel);
void showEducationsWithMostEmployees(List_parent L_Edu, List_relation L_Rel);

int inputMenu();
void menuHandler(int x);

#endif // FUNCTIONS_H_INCLUDED
