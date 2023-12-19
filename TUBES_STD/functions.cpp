#include "functions.h"

/** FUNCTIONS/PROCEDURES FOR EACH OPTIONS */
void addEducationData(List_parent &L_Edu){
    string id, name;

    char ans;
    address_p existingID;

    cout << "INPUT ID: ";
    cin >> id;
    existingID = findElmParent(L_Edu, id);
    if (existingID == NULL) {
        cout << "INPUT NAMA: ";
        cin >> name;
        insertLastParent(L_Edu, createElmParent(id, name));
        cout << "Data berhasil dimasukkan." << endl;
    } else {
        cout << "WARNING: ID yang diinput sudah ada di list" << endl;
        cout << "Apakah anda ingin mengubah data yang telah ada? (Y/N): ";
        cin >> ans;
        if (ans == 'Y' || ans == 'y') {
            cout << "INPUT NAMA: ";
            cin >> name;
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
    existingID = findElmChild(L_Emp, id);
    if (existingID == NULL) {
        cout << "INPUT NAMA: ";
        cin >> name;
        cout << "INPUT JENIS KELAMIN (L/P): ";
        cin >> gender;
        cout << "INPUT USIA: ";
        cin >> age;
        insertLastChild(L_Emp, createElmChild(id, name, gender, age));
        cout << "Data berhasil dimasukkan." << endl;
    } else {
        cout << "WARNING: ID yang diinput sudah ada di list" << endl;
        cout << "Apakah anda ingin mengubah data yang telah ada? (Y/N): ";
        cin >> ans;
        if (ans == 'Y' || ans == 'y') {
            cout << "INPUT NAMA: ";
            cin >> name;
            cout << "INPUT JENIS KELAMIN (L/P): ";
            cin >> gender;
            cout << "INPUT USIA: ";
            cin >> age;
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
    string idEmp;
    address_c Emp;

    cout << "ID PEGAWAI YANG INGIN DICARI: ";
    cin >> idEmp;
    Emp = findElmChild(L_Emp, idEmp);
    if (Emp == NULL) {
        cout << "Pegawai dengan ID " << idEmp << " tidak ditemukan." << endl;
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
            cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!" << endl;
        }
        if (Emp == NULL) {
            cout << "ERROR: Pegawai dengan ID " << idEmp << " tidak ditemukan!" << endl;
        }
        cout << "Data gagal dimasukkan." << endl;
    }
}
void searchEmployeesOfEducation(List_relation &L_Rel){
    string idEdu;
    address_r Rel = L_Rel.first;
    bool isFollowed = false;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    if (!isEmptyRel(L_Rel)) {
        cout << "====================" << endl;
        do {
            if (Rel->parent->info.id == idEdu) {
                cout << "--------------------" << endl;
                cout << "ID           : " << Rel->child->info.id << endl;
                cout << "Nama         : " << Rel->child->info.name << endl;
                cout << "Jenis Kelamin: " << Rel->child->info.gender << endl;
                cout << "Umur         : " << Rel->child->info.age << endl;
                cout << "--------------------" << endl;
                isFollowed = true;
            }
            Rel = Rel->next;
        } while (Rel != L_Rel.first);
        if (!isFollowed) {
            cout << "Riwayat Pendidikan dengan ID " << idEdu << " tidak diikuti oleh siapapun" << endl;
        }
        cout << "====================" << endl;
    }
}
void deleteEducationDataWithRelations(List_parent &L_Edu, List_relation &L_Rel){
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

        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!" << endl;
        cout << "Data gagal dihapus." << endl;
    }
}
void deleteAllEmployeesOfEducation(List_relation &L_Rel, List_parent L_Edu, List_child &L_Emp){
    string idEdu;
    address_p Edu;
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

        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!" << endl;
        cout << "Data gagal dihapus." << endl;
    }
}
void showAllEmployeesWithEducation(List_relation L_Rel){
    address_r Rel = L_Rel.first;
    address_r tempRel, deletedRel;

    if (!isEmptyRel(L_Rel)) {
        cout << "====================" << endl;
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
        cout << "====================" << endl;
    } else {
        cout << "ERROR: List Relasi kosong!" << endl;
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
    } else {
        if (isEmptyChild(L_Emp)) {
            cout << "ERROR: List Pegawai kosong!" << endl;
        }
        if (isEmptyRel(L_Rel)) {
            cout << "ERROR: List Relasi kosong!" << endl;
        }
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
    } else {
        if (isEmptyParent(L_Edu)) {
            cout << "ERROR: List Riwayat Pendidikan kosong!" << endl;
        }
        if (isEmptyRel(L_Rel)) {
            cout << "ERROR: List Relasi kosong!" << endl;
        }
    }
}

/** ADDITIONAL FUNCTIONS/PROCEDURES */
void searchEducationData(List_parent L_Edu){
    string idEdu;
    address_p Edu;

    cout << "ID RIWAYAT PENDIDIKAN YANG INGIN DICARI: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu);
    if (Edu == NULL) {
        cout << "Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan." << endl;
    } else {
        cout << "--------------------" << endl;
        cout << "ID           : " << Edu->info.id << endl;
        cout << "Nama         : " << Edu->info.name << endl;
        cout << "--------------------" << endl;
    }
}
void showAllEducationsData(List_parent L_Edu){
    if (!isEmptyParent(L_Edu)) {
        printListParent(L_Edu);
    } else {
        cout << "ERROR: List Riwayat Pendidikan kosong!" << endl;
    }
}
void showAllEmployeesData(List_child L_Emp){
    if (!isEmptyChild(L_Emp)) {
        printListChild(L_Emp);
    } else {
        cout << "ERROR: List Pegawai kosong!" << endl;
    }
}
void deleteEmployeeDataWithRelations(List_child &L_Emp, List_relation &L_Rel){
    string idEmp;
    address_c Emp;
    address_r Rel = L_Rel.first;
    address_r tempRel;
    address_c beforeEmp, tempEmp;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEmp;
    Emp = findElmChild(L_Emp, idEmp);

    if (Emp != NULL) {
        do {
            if (Rel->child == Emp) {
                Rel = Rel->next;
                deleteAfterRel(L_Rel, Rel->prev->prev, tempRel);
            } else {
                Rel = Rel->next;
            }
        } while (Rel != L_Rel.first && Rel->next != NULL);

        if (Emp == L_Emp.first) {
            deleteFirstChild(L_Emp, tempEmp);
        } else {
            beforeEmp = L_Emp.first;
            while (beforeEmp->next != Emp) {
                beforeEmp = beforeEmp->next;
            }
            deleteAfterChild(L_Emp, beforeEmp, tempEmp);
        }

        delete tempRel;
        delete tempEmp;

        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "ERROR: Pegawai dengan ID " << idEmp << " tidak ditemukan!" << endl;
        cout << "Data gagal dihapus." << endl;
    }
}
/** TODO:
    - DELETE AN EDUCATION DATA (AND RELATION WITH IT) ACCORDING TO ITS ID
    - DELETE AN EMPLOYEE DATA (AND RELATION WITH IT) ACCORDING TO ITS ID
*/

/** MENU ELEMENTS */
int menuElm_main(){
    char input;
    int res;
    do {
        system("cls");
        cout << "[ EDU-EMP DB v0.1a ]" << endl;
        cout << "======[ MENU ]======" << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Cari data" << endl;
        cout << "3. Hapus data" << endl;
        cout << "4. Tampilkan data" << endl;
        cout << "0. EXIT" << endl << endl;
        cout << "INPUT PENGGUNA: ";
        cin >> input;
        cin.sync();
        res = int(input)-48;
        if (res < 0 || res > 4) {
            cout << "ERROR: Input " << input << " tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 4);
    return res;
}
int menuElm_add(){
    char input;
    int res;
    do {
        system("cls");
        cout << "[ EDU-EMP DB v0.1a ]" << endl;
        cout << "==[ TAMBAH  DATA ]==" << endl;
        cout << "1. Tambah data Riwayat Pendidikan" << endl;
        cout << "2. Tambah data Pegawai" << endl;
        cout << "3. Tambah data Relasi (R.P. <-> Pgw.)" << endl;
        cout << "0. Kembali" << endl << endl;
        cout << "INPUT PENGGUNA: ";
        cin >> input;
        cin.sync();
        res = int(input)-48;
        if (res < 0 || res > 3) {
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 3);
    return res;
}
int menuElm_search(){
    char input;
    int res;
    do {
        system("cls");
        cout << "[ EDU-EMP DB v0.1a ]" << endl;
        cout << "===[ CARI  DATA ]===" << endl;
        cout << "1. Cari data Riwayat Pendidikan" << endl;
        cout << "2. Cari data Pegawai" << endl;
        cout << "3. Cari data Pegawai dengan Riwayat Pendidikan tertentu" << endl;
        cout << "0. Kembali" << endl << endl;
        cout << "INPUT PENGGUNA: ";
        cin >> input;
        cin.sync();
        res = int(input)-48;
        if (res < 0 || res > 3) {
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 3);
    return res;
}
int menuElm_delete(){
    char input;
    int res;
    do {
        system("cls");
        cout << "[ EDU-EMP DB v0.1a ]" << endl;
        cout << "===[ HAPUS DATA ]===" << endl;
        cout << "1. Hapus data Riwayat Pendidikan beserta Relasinya" << endl;
        cout << "2. Hapus data Pegawai beserta Relasinya" << endl;
        cout << "3. Hapus semua data Pegawai yang memiliki Riwayat Pendidikan tertentu" << endl;
        cout << "0. Kembali" << endl << endl;
        cout << "INPUT PENGGUNA: ";
        cin >> input;
        cin.sync();
        res = int(input)-48;
        if (res < 0 || res > 2) {
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 2);
    return res;
}
int menuElm_show(){
    char input;
    int res;
    do {
        system("cls");
        cout << "[ EDU-EMP DB v0.1a ]" << endl;
        cout << "==[ TAMPIL  DATA ]==" << endl;
        cout << "1. Tampilkan seluruh data Riwayat Pendidikan" << endl;
        cout << "2. Tampilkan seluruh data Pegawai" << endl;
        cout << "3. Tampilkan seluruh data Pegawai beserta Riwayat Pendidikannya" << endl;
        cout << "4. Tampilkan data Pegawai yang memiliki Riwayat Pendidikan terbanyak" << endl;
        cout << "5. Tampilkan data Riwayat Pendidikan yang paling banyak diikuti oleh Pegawai" << endl;
        cout << "0. Kembali" << endl << endl;
        cout << "INPUT PENGGUNA: ";
        cin >> input;
        cin.sync();
        res = int(input)-48;
        if (res < 0 || res > 5) {
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 5);
    return res;
}
void menuHandler(){
    List_parent L_Edu;
    List_relation L_Rel;
    List_child L_Emp;
    int input = -1;

    createListParent(L_Edu);
    createListRel(L_Rel);
    createListChild(L_Emp);
    do {
        input = menuElm_main();
        switch (input) {
        case 1:
            input = menuElm_add();
            switch (input) {
            case 1:
                addEducationData(L_Edu);
                system("pause");
                break;
            case 2:
                addEmployeeData(L_Emp);
                system("pause");
                break;
            case 3:
                addRelationData(L_Rel, L_Edu, L_Emp);
                system("pause");
                break;
            default:
                input = -1;
                break;
            }
            break;
        case 2:
        input = menuElm_search();
            switch (input) {
            case 1:
                searchEducationData(L_Edu);
                system("pause");
                break;
            case 2:
                searchEmployeeData(L_Emp);
                system("pause");
                break;
            case 3:
                searchEmployeesOfEducation(L_Rel);
                system("pause");
                break;
            default:
                input = -1;
                break;
            }
            break;
        case 3:
        input = menuElm_delete();
            switch (input) {
            case 1:
                deleteEducationDataWithRelations(L_Edu, L_Rel);
                system("pause");
                break;
            case 2:
                deleteEmployeeDataWithRelations(L_Emp, L_Rel);
                system("pause");
                break;
            case 3:
                deleteAllEmployeesOfEducation(L_Rel, L_Edu, L_Emp);
                system("pause");
                break;
            default:
                input = -1;
                break;
            }
            break;
        case 4:
        input = menuElm_show();
            switch (input) {
            case 1:
                showAllEducationsData(L_Edu);
                system("pause");
                break;
            case 2:
                showAllEmployeesData(L_Emp);
                system("pause");
                break;
            case 3:
                showAllEmployeesWithEducation(L_Rel);
                system("pause");
                break;
            case 4:
                showEmployeesWithMostEducations(L_Emp, L_Rel);
                system("pause");
                break;
            case 5:
                showEducationsWithMostEmployees(L_Edu, L_Rel);
                system("pause");
                break;
            default:
                input = -1;
                break;
            }
            break;
        }
    } while (input != 0);
}
