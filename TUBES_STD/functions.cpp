#include "functions.h"

void addEducationData(List_parent &L_Edu){
    string id, name;

    cout << "INPUT ID: ";
    cin >> id;
    cout << "INPUT NAMA: ";
    cin >> name;
    insertLastParent(L_Edu, createElmParent(id, name));
    cout << "Data berhasil dimasukkan." << endl;
}
void addEmployeeData(List_child &L_Emp){
    string id;
    string name;
    char gender;
    int age;

    cout << "INPUT ID: ";
    cin >> id;
    cout << "INPUT NAMA: ";
    cin >> name;
    cout << "INPUT JENIS KELAMIN: ";
    cin >> gender;
    cout << "INPUT USIA: ";
    cin >> age;
    insertLastChild(L_Emp, createElmChild(id, name, gender, age));
    cout << "Data berhasil dimasukkan." << endl;
}
void searchEmployeeData(List_child L_Emp){
    string id;
    address_c Emp;

    cout << "ID PEGAWAI YANG INGIN DICARI: ";
    cin >> id;
    Emp = findElmChild(L_Emp, id);
    if (Emp == NULL) {
        cout << "Pegawai dengan ID " << id << " tidak ditemukan." << endl;
    } else {
        cout << "--------------------" << endl;
        cout << "ID           : " << Emp->info.id << endl;
        cout << "Nama         : " << Emp->info.name << endl;
        cout << "Jenis Kelamin: " << Emp->info.gender << endl;
        cout << "Umur         : " << Emp->info.age << endl;
        cout << "--------------------" << endl;
    }
}
void addRelationData(List_relation &L_Rel, List_parent L_Edu, List_child L_Emp){
    string idEdu, idEmp;
    address_p Edu;
    address_c Emp;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu);

    cout << "INPUT ID PEGAWAI: ";
    cin >> idEmp;
    Emp = findElmChild(L_Emp, idEmp);

    insertLastRel(L_Rel, createElmRel(Edu, Emp));
    cout << "Data berhasil dimasukkan." << endl;
}
void searchEmployeesOfEducation(List_relation &L_Rel){
    string idEdu;
    address_r R = L_Rel.first;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    cout << "====================" << endl;
    if (!isEmptyRel(L_Rel)) {
        do {
            if (R->parent->info.id == idEdu) {
                cout << "--------------------" << endl;
                cout << "ID           : " << R->child->info.id << endl;
                cout << "Nama         : " << R->child->info.name << endl;
                cout << "Jenis Kelamin: " << R->child->info.gender << endl;
                cout << "Umur         : " << R->child->info.age << endl;
                cout << "--------------------" << endl;
            }
            R = R->next;
        } while (R != L_Rel.first);
    }
    cout << "====================" << endl;
}
void deleteEducationWithRelations(List_parent &L_Edu, List_relation &L_Rel){

}
void deleteEmployeesOfEducation(List_relation &L_Rel, List_parent &L_Edu, List_child &L_Emp){

}
void showAllEmployeesWithEducation(List_relation L_Rel){
    address_r R = L_Rel.first;
    address_r T;

    if (!isEmptyRel(L_Rel)) {
        do {
            cout << "--------------------" << endl;
            cout << "ID                : " << R->child->info.id << endl;
            cout << "Nama              : " << R->child->info.name << endl;
            cout << "Jenis Kelamin     : " << R->child->info.gender << endl;
            cout << "Umur              : " << R->child->info.age << endl;
            cout << "Riwayat Pendidikan: " << R->parent->info.name;
            T = R->next;
            while (T != NULL) {
                if (T->child->info.id == R->child->info.id) {
                    cout << ", " << T->parent->info.name;
                }
                T = T->next;
            }
            cout << endl << "--------------------" << endl;
            R = R->next;
        } while (R != L_Rel.first);
    }
}
void showEmployeesWithMostEducations(List_relation L_Rel);
void showEducationsWithMostEmployees(List_relation L_Rel);

int inputMenu();
void menuHandler(int x);
