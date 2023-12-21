#include "child.h"

void createList_c(listChild &LC)
{
    first(LC) = NULL;
}

adr_c createElm_c(infotype_c data)
{
    adr_c C;
    C = new elm_c;
    info(C) = data;
    next(C) = NULL;
    return C;
}

void insertLast_c(listChild &LC, adr_c C)
{
    if (first(LC) == NULL)
    {
        first(LC) = C;
    }
    else
    {
        adr_c curr = first(LC);
        while (next(curr) != NULL)
        {
            curr = next(curr);
        }
        next(curr) = C;
    }
}

void deleteFirst_c(listChild &LC, adr_c C)
{
    C = first(LC);
    if (next(first(LC)) == NULL)
    {
        first(LC) = NULL;
    }
    else
    {
        first(LC) = next(C);
    }
}

void deleteLast_c(listChild &LC, adr_c C)
{
    C = first(LC);
    while (next(next(C))!= NULL)
    {
        C = next(C);
    }
    next(C) = NULL;
}

void deleteAfter(listChild &LC, adr_c C)
{
    adr_c Prec = first(LC);
    while (next(Prec) != NULL)
    {
        if (next(Prec) == C)
        {
            break;
        }
        Prec = next(Prec);
    }
    adr_c Q = next(C);
    next(Prec) = Q;
    next(C) = NULL;
}

void deleteElm_c(listChild &LC, adr_c C)
{
    if (C != first(LC) && next(C) == NULL)
    {
        deleteLast_c(LC, C);
    }
    else if (C == first(LC))
    {
        deleteFirst_c(LC, C);
    }
    else if (next(C) != NULL && C != first(LC))
    {
        deleteAfter(LC, C);
    }
    delete C;
}

adr_c findElm_c(listChild LC, string ID, string name)
{
    if (first(LC) == NULL)
    {
        cout << "LIST SOSMED KOSONG" << endl;
    }
    else
    {
        adr_c curr = first(LC);
        while (curr != NULL)
        {
            if (info(curr).ID == ID && info(curr).name == name)
            {
                return curr;
            }
            curr = next(curr);
        }


        if (curr == NULL)
        {
            cout << name << " tidak ditemukan\n" << endl;
        }
    }

    return NULL;
}

void showData_c(listChild LC)
{
    if (first(LC) == NULL)
    {
        cout << "LIST SOSMED KOSONG" << endl;
    }
    else
    {
        adr_c curr = first(LC);
        int i = 0;
        cout << "\n======== DATA SOSMED =========";
        while (curr != NULL)
        {
            i++;
            cout << "\nData ke-" << i << endl;
            cout << "ID              : " << info(curr).ID << endl;
            cout << "Name            : "<< info(curr).name << endl;
            cout << "Ratings         : "<< info(curr).ratings << endl;
            cout << "Age Restriction : " << info(curr).age_restriction << endl;
            curr = next(curr);
        }
        cout << "==============================\n" << endl;
    }
}

int menu() {
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "|                           MENU                            |" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "| 1.Tambah Data Akun                                        |" << endl;
    cout << "| 2.Tambah Data Sosmed                                      |" << endl;
    cout << "| 3.Tambah Relasi                                           |" << endl;
    cout << "| 4.Hapus Data Akun                                         |" << endl;
    cout << "| 5.Hapus Data Sosmed                                       |" << endl;
    cout << "| 6.Hapus Relasi                                            |" << endl;
    cout << "| 7.Mencari Data Akun                                       |" << endl;
    cout << "| 8.Mencari Data Sosmed                                     |" << endl;
    cout << "| 9.Mencari Relasi antara Akun dan Sosmed                   |" << endl;
    cout << "| 10.Show Data Akun                                         |" << endl;
    cout << "| 11.Show Data Sosmed                                       |" << endl;
    cout << "| 12.Show Data Sosmed berdasarkan Akun                      |" << endl;
    cout << "| 13.Show Data Akun berdasarkan Sosmed                      |" << endl;
    cout << "| 14.Show Data Akun dan Sosmed yang berelasi                |" << endl;
    cout << "| 15.Show Data Sosmed dan Akun yang berelasi                |" << endl;
    cout << "| 16.Menghitung Jumlah Data Sosmed dari suatu Akun          |" << endl;
    cout << "| 17.Menghitung Jumlah Data Akun dari suatu Sosmed          |" << endl;
    cout << "| 18.Menghitung Jumlah Data Sosmed yang tidak memiliki Akun |" << endl;
    cout << "| 19.Menghitung Jumlah Data Akun yang tidak memiliki Sosmed |" << endl;
    cout << "| 20.Mengubah Data Relasi antara Akun dan Sosmed            |" << endl;
    cout << "| 0.Exit                                                    |" << endl;
    cout << "+-----------------------------------------------------------+" << endl;

    int input = 0;
    cout << "Masukkan menu: "; cin >> input;
    return input;
};
