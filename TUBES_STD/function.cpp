#include <iostream>
#include "function.h"

using namespace std;

/** FUNCTIONS/PROCEDURES FOR EACH OPTIONS */
void addEducationData(List_parent &L_Edu){
/*I.S. list parent berisi data riwayat pendidikan yang mungkin kosong
F.S. sebuah elemen mungkin dimasukkan ke dalam list parent dan mungkin tidak*/
    string id, name;

    char ans;
    address_p existingID;

    cout << "INPUT ID: ";
    cin >> id;
    existingID = findElmParent(L_Edu, id); /*mencari elemen parent berdasarkan ID yang dimasukkan user*/
    if (existingID == NULL) { /*jika elemen parent dengan ID tersebut tidak ditemukan dalam list parent*/
        cout << "INPUT NAMA: ";
        cin >> name;
        insertLastParent(L_Edu, createElmParent(id, name));
        cout << "Data berhasil dimasukkan." << endl;
    } else { /*jika elemen parent dengan ID tersebut sudah ada dalam list parent*/
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
/*I.S. list child berisi data pekerja yang mungkin kosong
F.S. sebuah elemen mungkin dimasukkan ke dalam list parent dan mungkin tidak*/
    string id;
    string name;
    char gender;
    int age;

    char ans;
    address_c existingID;

    cout << "INPUT ID: ";
    cin >> id;
    existingID = findElmChild(L_Emp, id); /*mencari elemen child berdasarkan ID yang dimasukkan user*/
    if (existingID == NULL) { /*jika elemen child dengan ID tersebut tidak ditemukan dalam list child*/
        cout << "INPUT NAMA: ";
        cin >> name;
        cout << "INPUT JENIS KELAMIN (L/P): ";
        cin >> gender;
        cout << "INPUT USIA: ";
        cin >> age;
        insertLastChild(L_Emp, createElmChild(id, name, gender, age));
        cout << "Data berhasil dimasukkan." << endl;
    } else {  /*jika elemen child dengan ID tersebut sudah ada dalam list child*/
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
/*I.S. list child berisi data pekerja yang mungkin kosong
F.S. data pekerja yang dicari ditampilkan ke layar*/
    string idEmp;
    address_c Emp;

    cout << "ID PEGAWAI YANG INGIN DICARI: ";
    cin >> idEmp;
    Emp = findElmChild(L_Emp, idEmp); /*mencari elemen child berdasarkan ID yang dimasukkan user*/
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
/*I.S. list relation, list parent, dan list child
F.S. elemen baru mungkin ditambahkan ke dalma list relation*/
    string idEdu, idEmp;
    address_p Edu;
    address_c Emp;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu); /*mencari elemen parent berdasarkan ID yang dimasukkan user*/

    cout << "INPUT ID PEGAWAI: ";
    cin >> idEmp;
    Emp = findElmChild(L_Emp, idEmp); /*mencari elemen child berdasarkan ID yang dimasukkan user*/

    if (Edu != NULL && Emp != NULL) { /*jika elemen child dengan ID idEmp dan elemen parent dengan ID idEdu tidak ditemukan*/
        insertFirstRel(L_Rel, createElmRel(Edu, Emp)); /*menambahkan data ke dalam list relation sebagai elemen relation baru*/
        Edu->info.hiddenCountOfEmp++; /*menambah perhitungan jumlah pekerja*/
        Emp->info.hiddenCountOfEdu++; /*menambah perhitungan jumlah riwayat pendidikan*/
        cout << "Data berhasil dimasukkan." << endl;
    } else { /*jika elemen child dengan ID idEmp dan elemen parent dengan ID idEdu sudah ada*/
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
/*I.S. list relation yang mungkin kosong
F.S. data pekerja dengan ID riwayat pendidikan yang dimasukkan user ditampilkan ke layar*/
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
/*I.S. list parent dan list relation yang mungkin kosong
F.S. elemen parent dengan ID yang diamsukkan user dan relation dalam list relation yang menunjuknya dihapus dari list*/
    string idEdu;
    address_p Edu;
    address_r Rel = L_Rel.first;
    address_r tempRel;
    address_p beforeEdu, tempEdu;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu); /*Edu berisi alamat elemen parent yang memiliki ID idEdu yang mungkin tidak ditemukan dalam list parent*/

    if (Edu != NULL) { /*jika alamat Edu tidak NULL atau data riwayat pendidikan dengan idEdu ditemukan dalam list parent*/
        do {
            if (Rel->parent == Edu) {  /*jika elemen parent yang akan dihapus merupakan elemen pertama yang ditunjuk dalam list relation*/
                Rel = Rel->next;
                deleteAfterRel(L_Rel, Rel->prev->prev, tempRel); /*menghapus elemen relation dengan ID idEdu*/
            } else {
                Rel = Rel->next; /*memindahkan pointer Rel sampai elemen yang ditunjuk oleh Rel memiliki alamat parent yang sama dengan alamat Edu*/
            }
        } while (Rel != L_Rel.first && Rel->next != NULL);

        if (Edu == L_Edu.first) { /*jika elemen parent yang akan dihapus merupakan elemen pertama dalam list parent*/
            deleteFirstParent(L_Edu, tempEdu);
        } else { /*jika elemen parent yang akan dihapus bukan merupakan elemen pertama dalma list parent*/
            beforeEdu = L_Edu.first; /*pointer untuk menunjuk elemen sebelum elemen dengan alamat Edu karena data dihapus menggunakan metode delete after*/
            while (beforeEdu->next != Edu) {
                beforeEdu = beforeEdu->next;
            }
            deleteAfterParent(L_Edu, beforeEdu, tempEdu);
        }

        delete tempRel;
        delete tempEdu;

        cout << "Data berhasil dihapus" << endl;
    } else { /*jika alamat Edu NULL atau data riwayat pendidikan elemen dengan idEdu tidak ditemukan dalam list parent*/
        cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!" << endl;
        cout << "Data gagal dihapus." << endl;
    }
}
void deleteAllEmployeesOfEducation(List_relation &L_Rel, List_parent L_Edu, List_child &L_Emp){
/*I.S. list relation, list parent, dan list child yang mungkin kosong
F.S. elemen child dengan ID yang diamsukkan user dan relation dalam list relation yang menunjuknya dihapus dari list*/
    string idEdu;
    address_p Edu;
    address_r Rel = L_Rel.first;
    address_r tempRel;
    address_c beforeEmp, tempEmp;

    cout << "INPUT ID RIWAYAT PENDIDIKAN: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu); /*Edu berisi alamat elemen parent yang memiliki ID idEdu yang mungkin tidak ditemukan dalam list parent*/

    if (Edu != NULL) { /*jika alamat Edu tidak NULL atau data riwayat pendidikan dengan idEdu ditemukan dalam list parent*/
        do {
            if (Rel->parent == Edu && Rel->child != NULL) { /*jika elemen parent yang akan dihapus merupakan elemen pertama yang ditunjuk dalam list relation dan pointer child dalam elemen Rel tidak NULL*/
                beforeEmp = L_Emp.first;
                while (beforeEmp->next != L_Emp.first) {
                    beforeEmp = beforeEmp->next;
                }
                deleteAfterChild(L_Emp, beforeEmp, tempEmp); /*menghapus elemen child dengan ID idEdu*/
                Rel->child = NULL;
            }
            Rel = Rel->next;
        } while (Rel != L_Rel.first);

        do {
            if (Rel->child == NULL) { /*jika pointer child dalam elemen relation NULL atau tidak menunjuk elemen child mana pun*/
                Rel = Rel->next;
                deleteAfterRel(L_Rel, Rel->prev->prev, tempRel);
            } else {
                Rel = Rel->next; /*memindahkan pointer Rel sampai elemen yang ditunjuk oleh Rel memiliki alamat parent yang sama dengan alamat Edu*/
            }
            Edu->info.hiddenCountOfEmp = 0;
        } while (Rel != L_Rel.first && Rel->next != NULL);

        delete tempEmp;
        delete tempRel;

        cout << "Data berhasil dihapus" << endl;
    } else { /*jika alamat Edu NULL atau data riwayat pendidikan elemen dengan idEdu tidak ditemukan dalam list parent*/
        cout << "ERROR: Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan!" << endl;
        cout << "Data gagal dihapus." << endl;
    }
}
void showAllEmployeesWithEducation(List_relation L_Rel){
/*I.S. list relation yang mungkin kosong
F.S. menampilkan data pekerja dalam list child beserta riwayat pendidikannya ke layar*/
    address_r Rel = L_Rel.first;
    address_r tempRel, deletedRel;

    if (!isEmptyRel(L_Rel)) { /*jika list relation tidak kosong*/
        cout << "====================" << endl;
        do {
            cout << "--------------------" << endl;
            cout << "ID                : " << Rel->child->info.id << endl;
            cout << "Nama              : " << Rel->child->info.name << endl;
            cout << "Jenis Kelamin     : " << Rel->child->info.gender << endl;
            cout << "Umur              : " << Rel->child->info.age << endl;
            cout << "Riwayat Pendidikan: " << Rel->parent->info.name; /*menampilkan riwayat pendidikan pekerja*/
            tempRel = Rel->next;
            while (tempRel != Rel && tempRel->next != NULL) { /*menampilkan riwayat pendidikan lain pekerja jika ada*/
                if (tempRel->child->info.id == Rel->child->info.id) {
                    cout << ", " << tempRel->parent->info.name;
                    tempRel = tempRel->next;
                    deleteAfterRel(L_Rel, tempRel->prev->prev, deletedRel);
                } else {
                    tempRel = tempRel->next;
                }
            }
            cout << endl << "--------------------" << endl;
            Rel = Rel->next; /*memindahkan pointer rel ke elemen relation berikutnya*/
        } while (Rel != L_Rel.first); /*pinter Rel dipindahkan ke elemen berikutnya selama Rel tidak menunjuk elemen pertama dalam list relation*/
        cout << "====================" << endl;
    } else { /*jika list relation kosong*/
        cout << "ERROR: List Relasi kosong!" << endl;
    }
}
void showEmployeesWithMostEducations(List_child L_Emp, List_relation L_Rel){
/*I.S. list child dan list relation yang mungkin kosong
F.S. menampilkan data pekerja dengan riwayat pendidikan terbanyak*/
    address_c Emp = L_Emp.first;
    address_r Rel = L_Rel.first;
    int most = 0;
    if (!isEmptyChild(L_Emp) && !isEmptyRel(L_Rel)){ /*jika list child dan list relation tidak kosong*/
        do {
            if (most < Emp->info.hiddenCountOfEdu) { /*mencari pekerja dengan riwayat pendidikan terbanyak*/
                most = Emp->info.hiddenCountOfEdu;
            }
            Emp = Emp->next;
        } while (Emp != L_Emp.first);
        cout << "====================" << endl;
        do { /*menampilkan seluruh pekerja dengan jumlah riwayat pendidikan sebanyak most*/
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
    } else { /*jika list child dan/atau list relation kosong*/
        if (isEmptyChild(L_Emp)) {
            cout << "ERROR: List Pegawai kosong!" << endl;
        }
        if (isEmptyRel(L_Rel)) {
            cout << "ERROR: List Relasi kosong!" << endl;
        }
    }
}
void showEducationsWithMostEmployees(List_parent L_Edu, List_relation L_Rel){
/*I.S. list parent dan list relation yang mungkin kosong
F.S. menampilkan data riwayat pendidikan dengan pekerja terbanyak*/
    address_p Edu = L_Edu.first;
    address_r Rel = L_Rel.first;
    int most = 0;
    if (!isEmptyParent(L_Edu) && !isEmptyRel(L_Rel)){ /*jika list parent dan list relation tidak kosong*/
        while (Edu != NULL) {
            if (most < Edu->info.hiddenCountOfEmp) { /*mencari riwayat pendidikan dengan jumlah pekerja terbanyak*/
                most = Edu->info.hiddenCountOfEmp;
            }
            Edu = Edu->next;
        };
        cout << "====================" << endl;
        do { /*menampilkan seluruh riwayat pendidikan dengan jumlah pekerja sebanyak most*/
            if (Rel->parent->info.hiddenCountOfEmp == most) {
                cout << "--------------------" << endl;
                cout << "ID           : " << Rel->parent->info.id << endl;
                cout << "Nama         : " << Rel->parent->info.name << endl;
                cout << "--------------------" << endl;
            }
        } while (Rel != L_Rel.first);
        cout << "====================" << endl;
    } else { /*jika list parent dan/atau list relation kosong*/
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
/*I.S. list parent yang mungkin kosong
F.S. mencari data riwayat pendidikan dalam list berdasarkan ID yang dimasukkan user*/
    string idEdu;
    address_p Edu;

    cout << "ID RIWAYAT PENDIDIKAN YANG INGIN DICARI: ";
    cin >> idEdu;
    Edu = findElmParent(L_Edu, idEdu); /*Edu berisi alamat elemen parent yang memiliki ID idEdu yang mungkin tidak ditemukan dalam list parent*/
    if (Edu == NULL) { /*jika Edu tidak NULL atau elemen parent dengan ID idEdu ditemukan dalam list*/
        cout << "Riwayat Pendidikan dengan ID " << idEdu << " tidak ditemukan." << endl;
    } else { /*jika Edu NULL atau elemen dengan ID idEdu tidak ditemukan dalam list*/
        cout << "--------------------" << endl;
        cout << "ID           : " << Edu->info.id << endl;
        cout << "Nama         : " << Edu->info.name << endl;
        cout << "--------------------" << endl;
    }
}
void showAllEducationsData(List_parent L_Edu){
/*I.S. list parent yang mungkin kosong
F.S. menampilkan seluruh data riwayat pendidikan dalam list parent ke layar*/
    if (!isEmptyParent(L_Edu)) {
        printListParent(L_Edu);
    } else {
        cout << "ERROR: List Riwayat Pendidikan kosong!" << endl;
    }
}
void showAllEmployeesData(List_child L_Emp){
/*I.S. list child yang mungkin kosong
F.S. menampilkan seluruh data pekerja dalam list child ke layar*/
    if (!isEmptyChild(L_Emp)) {
        printListChild(L_Emp);
    } else {
        cout << "ERROR: List Pegawai kosong!" << endl;
    }
}
void deleteEmployeeDataWithRelations(List_child &L_Emp, List_relation &L_Rel){
/*I.S. list child dan list relation yang mungkin kosong
F.S. elemen child dengan id idEmp dan elemen relation yang menunjuknya dihapus dari list*/
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



/** MENU ELEMENTS */
int menuElm_main(){
/*mengembalikan pilihan menu ke layar*/
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
        if (res < 0 || res > 4) { /*jika user memasukkan angka selain pilihan di layar*/
            cout << "ERROR: Input " << input << " tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 4);
    return res;
}
int menuElm_add(){ /*jika function menuElm_main mengembalikan angka 1*/
/*mengembalikan pilihan menu tambah data ke layar*/
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
        if (res < 0 || res > 3) { /*jika user memasukkan angka selain pilihan di layar*/
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 3);
    return res;
}
int menuElm_search(){ /*jika function menuElm_main mengembalikan angka 2*/
/*mengembalikan pilihan menu cari data ke layar*/
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
        if (res < 0 || res > 3) { /*jika user memasukkan angka selain pilihan di layar*/
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 3);
    return res;
}
int menuElm_delete(){ /*jika function menuElm_main mengembalikan angka 3*/
/*mengembalikan pilihan menu hapus data ke layar*/
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
        if (res < 0 || res > 3) {
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 3); /*jika user memasukkan angka selain pilihan di layar*/
    return res;
}
int menuElm_show(){ /*jika function menuElm_main mengembalikan angka 4*/
/*mengembalikan pilihan menu tampilkan data ke layar*/
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
        if (res < 0 || res > 5) { /*jika user memasukkan angka selain pilihan di layar*/
            cout << "ERROR: Input tidak valid!" << endl;
            system("pause");
        }
    } while (res < 0 || res > 5);
    return res;
}
void menuHandler(){
/*I.S. -
F.S. menampilkan menuElm_main beserta menu lain yang dimasukkan oleh user*/
    List_parent L_Edu;
    List_relation L_Rel;
    List_child L_Emp;
    int input = -1;

    createListParent(L_Edu); /*membuat list parent*/
    createListRel(L_Rel); /*membuat list relation*/
    createListChild(L_Emp); /*membuat list child*/
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
