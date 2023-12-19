#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "list_parent_SLL.h"
#include "list_relation_CDLL.h"
#include "list_child_CSLL.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

/** FUNCTIONS/PROCEDURES FOR EACH OPTIONS */
void addEducationData(List_parent &L_Edu); // Spec a.
void addEmployeeData(List_child &L_Emp); // Spec b.
void searchEmployeeData(List_child L_Emp); // Spec c.
void addRelationData(List_relation &L_Rel, List_parent L_Edu, List_child L_Emp); // Spec d.
void searchEmployeesOfEducation(List_relation &L_Rel); // Spec e.
void deleteEducationDataWithRelations(List_parent &L_Edu, List_relation &L_Rel); // Spec f.
void deleteAllEmployeesOfEducation(List_relation &L_Rel, List_parent L_Edu, List_child &L_Emp); // Spec g.
void showAllEmployeesWithEducation(List_relation L_Rel); // Spec h.
void showEmployeesWithMostEducations(List_child L_Emp, List_relation L_Rel); // Spec i.
void showEducationsWithMostEmployees(List_parent L_Edu, List_relation L_Rel); // Spec j.

/** ADDITIONAL FUNCTIONS/PROCEDURES */
// SUBPROGRAM DILUAR SPESIFIKASI SOAL
void searchEducationData(List_parent L_Edu);
void showAllEducationsData(List_parent L_Edu);
void showAllEmployeesData(List_child L_Emp);
void deleteEmployeeDataWithRelations(List_child &L_Emp, List_relation &L_Rel);

/** MENU ELEMENTS */
int menuElm_main();
int menuElm_add();
int menuElm_search();
int menuElm_delete();
int menuElm_show();
void menuHandler();

#endif // FUNCTIONS_H_INCLUDED
