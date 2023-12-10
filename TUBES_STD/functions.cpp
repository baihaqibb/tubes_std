#include "functions.h"

void addEducationData(List_parent &L_Edu){
    string id, name;

    char ans;
    address_p existingID;

    cout << "INPUT ID: ";
    cin >> id;
    cout << "INPUT NAMA: ";
    cin >> name;
    existingID = findElmParent(L_Edu, id);
    if (existingID == NULL) {
        insertLastParent(L_Edu, createElmParent(id, name));
        cout << "Data berhasil dimasukkan." << endl;
    } else {
        cout << "WARNING: ID yang diinput sudah ada di list" << endl;
        cout << "Apakah anda ingin mengubah data yang telah ada? (Y/N): ";
        cin >> ans;
        if (ans == 'Y' || ans == 'y') {
            existingID->info.name = name;
            cout << "Data berhasil diubah." << endl;
        } else {
            cout << "Data gagal dimasukkan." << endl;
        }
    }
}
void addEmployeeData(List_child &L_Emp){
    string id;
    string name;
    char gender;
    int age;

    char ans;
    address_c existingID;

    cout << "INPUT ID: ";
    cin >> id;
    cout << "INPUT NAMA: ";
    cin >> name;
    cout << "INPUT JENIS KELAMIN: ";
    cin >> gender;
    cout << "INPUT USIA: ";
    cin >> age;
    existingID = findElmChild(L_Emp, id);
    if (existingID == NULL) {
        insertLastChild(L_Emp, createElmChild(id, name, gender, age));
        cout << "Data berhasil dimasukkan." << endl;
    } else {
        cout << "WARNING: ID yang diinput sudah ada di list" << endl;
        cout << "Apakah anda ingin mengubah data yang telah ada? (Y/N): ";
        cin >> ans;
        if (ans == 'Y' || ans == 'y') {
            existingID->info.name = name;
            existingID->info.gender = gender;
            existingID->info.age = age;
            cout << "Data berhasil diubah." << endl;
        } else {
            cout << "Data gagal dimasukkan." << endl;
        }
    }
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

    if (Edu != NULL && Emp != NULL) {
        insertFirstRel(L_Rel, createElmRel(Edu, Emp));
        Edu->info.hiddenCountOfEmp++;
        Emp->info.hiddenCountOfEdu++;
        cout << "Data berhasil dimasukkan." << endl;
    } else {
        if (Edu == NULL) {
            cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!";
        }
        if (Emp == NULL) {
            cout << "ERROR: Pegawai dengan ID " << idEdu << " tidak ditemukan!";
        }
        cout << "Data gagal dimasukkan." << endl;
    }
}
void searchEmployeesOfEducation(List_relation &L_Rel){
    string idEdu;
    address_r Rel = L_Rel.first;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    cout << "====================" << endl;
    if (!isEmptyRel(L_Rel)) {
        do {
            if (Rel->parent->info.id == idEdu) {
                cout << "--------------------" << endl;
                cout << "ID           : " << Rel->child->info.id << endl;
                cout << "Nama         : " << Rel->child->info.name << endl;
                cout << "Jenis Kelamin: " << Rel->child->info.gender << endl;
                cout << "Umur         : " << Rel->child->info.age << endl;
                cout << "--------------------" << endl;
            }
            Rel = Rel->next;
        } while (Rel != L_Rel.first);
    }
    cout << "====================" << endl;
}
void deleteEducationWithRelations(List_parent &L_Edu, List_relation &L_Rel){
    string idEdu;
    address_p Edu;
    address_r Rel = L_Rel.first;
    address_r tempRel;
    address_p beforeEdu, tempEdu;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu);

    if (Edu != NULL) {
        do {
            if (Rel->parent == Edu) {
                Rel = Rel->next;
                deleteAfterRel(L_Rel, Rel->prev->prev, tempRel);
            } else {
                Rel = Rel->next;
            }
        } while (Rel != L_Rel.first && Rel->next != NULL);

        if (Edu == L_Edu.first) {
            deleteFirstParent(L_Edu, tempEdu);
        } else {
            beforeEdu = L_Edu.first;
            while (beforeEdu->next != Edu) {
                beforeEdu = beforeEdu->next;
            }
            deleteAfterParent(L_Edu, beforeEdu, tempEdu);
        }

        delete tempRel;
        delete tempEdu;
    } else {
        cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!";
        cout << "Data gagal dihapus." << endl;
    }
}
void deleteEmployeesOfEducation(List_relation &L_Rel, List_parent L_Edu, List_child &L_Emp){
    string idEdu;
    address_p Edu;
    address_c Emp;
    address_r Rel = L_Rel.first;
    address_r tempRel;
    address_c beforeEmp, tempEmp;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu);

    if (Edu != NULL) {
        do {
            if (Rel->parent == Edu && Rel->child != NULL) {
                beforeEmp = L_Emp.first;
                while (beforeEmp->next != L_Emp.first) {
                    beforeEmp = beforeEmp->next;
                }
                deleteAfterChild(L_Emp, beforeEmp, tempEmp);
                Rel->child = NULL;
            }
            Rel = Rel->next;
        } while (Rel != L_Rel.first);

        do {
            if (Rel->child == NULL) {
                Rel = Rel->next;
                deleteAfterRel(L_Rel, Rel->prev->prev, tempRel);
            } else {
                Rel = Rel->next;
            }
            Edu->info.hiddenCountOfEmp = 0;
        } while (Rel != L_Rel.first && Rel->next != NULL);

        delete tempEmp;
        delete tempRel;
    } else {
        cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!";
        cout << "Data gagal dihapus." << endl;
    }
}
void showAllEmployeesWithEducation(List_relation L_Rel){
    address_r Rel = L_Rel.first;
    address_r tempRel, deletedRel;

    if (!isEmptyRel(L_Rel)) {
        do {
            cout << "--------------------" << endl;
            cout << "ID                : " << Rel->child->info.id << endl;
            cout << "Nama              : " << Rel->child->info.name << endl;
            cout << "Jenis Kelamin     : " << Rel->child->info.gender << endl;
            cout << "Umur              : " << Rel->child->info.age << endl;
            cout << "Riwayat Pendidikan: " << Rel->parent->info.name;
            tempRel = Rel->next;
            while (tempRel != Rel && tempRel->next != NULL) {
                if (tempRel->child->info.id == Rel->child->info.id) {
                    cout << ", " << tempRel->parent->info.name;
                    tempRel = tempRel->next;
                    deleteAfterRel(L_Rel, tempRel->prev->prev, deletedRel);
                } else {
                    tempRel = tempRel->next;
                }
            }
            cout << endl << "--------------------" << endl;
            Rel = Rel->next;
        } while (Rel != L_Rel.first);
    }
}
void showEmployeesWithMostEducations(List_child L_Emp, List_relation L_Rel){
    address_c Emp = L_Emp.first;
    address_r Rel = L_Rel.first;
    int most = 0;
    if (!isEmptyChild(L_Emp) && !isEmptyRel(L_Rel)){
        do {
            if (most < Emp->info.hiddenCountOfEdu) {
                most = Emp->info.hiddenCountOfEdu;
            }
            Emp = Emp->next;
        } while (Emp != L_Emp.first);
        cout << "====================" << endl;
        do {
            if (Rel->child->info.hiddenCountOfEdu == most) {
                cout << "--------------------" << endl;
                cout << "ID           : " << Rel->child->info.id << endl;
                cout << "Nama         : " << Rel->child->info.name << endl;
                cout << "Jenis Kelamin: " << Rel->child->info.gender << endl;
                cout << "Umur         : " << Rel->child->info.age << endl;
                cout << "--------------------" << endl;
            }
        } while (Rel != L_Rel.first);
        cout << "====================" << endl;
    }
}
void showEducationsWithMostEmployees(List_parent L_Edu, List_relation L_Rel){
    address_p Edu = L_Edu.first;
    address_r Rel = L_Rel.first;
    int most = 0;
    if (!isEmptyParent(L_Edu) && !isEmptyRel(L_Rel)){
        while (Edu != NULL) {
            if (most < Edu->info.hiddenCountOfEmp) {
                most = Edu->info.hiddenCountOfEmp;
            }
            Edu = Edu->next;
        };
        cout << "====================" << endl;
        do {
            if (Rel->parent->info.hiddenCountOfEmp == most) {
                cout << "--------------------" << endl;
                cout << "ID           : " << Rel->parent->info.id << endl;
                cout << "Nama         : " << Rel->parent->info.name << endl;
                cout << "--------------------" << endl;
            }
        } while (Rel != L_Rel.first);
        cout << "====================" << endl;
    }
}

int inputMenu();
void menuHandler(int x);
