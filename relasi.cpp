#include "relasi.h"

void createList_r(listRelasi &LR)
{
    first(LR) = NULL;
}

adr_r createElm_r(adr_p P, adr_c C)
{
    adr_r R = new elm_r;
    parent(R) = P;
    child(R) = C;
    next(R) = NULL;
    return R;
}

void insertLast_r(listRelasi &LR, adr_r R)
{
    if (first(LR) == NULL)
    {
        first(LR) = R;
    }
    else
    {
        adr_r curr = first(LR);
        while (next(curr)!=NULL)
        {
            curr = next(curr);
        }
        next(curr) = R;
    }
}

void deleteFirst_r(listRelasi &LR, adr_r R)
{
    R = first(LR);
    if (next(first(LR)) == NULL)
    {
        first(LR) = NULL;
    }
    else
    {
        parent(R) = NULL;
        child(R) = NULL;
        first(LR) = next(R);
    }
}

void deleteLast_r(listRelasi &LR, adr_r R)
{
    R = first(LR);
    while (next(next(R))!= NULL)
    {
        R = next(R);
    }
    parent(next(R)) = NULL;
    child(next(R)) = NULL;
    next(R) = NULL;
}

void deleteAfter_r(listRelasi &LR, adr_r R)
{
    adr_r Prec = first(LR);
    while (next(Prec) != NULL)
    {
        if (next(Prec) == R)
        {
            break;
        }
        Prec = next(Prec);
    }
    adr_r Q = next(R);
    parent(R) = NULL;
    child(R) = NULL;
    next(Prec) = Q;
    next(R) = NULL;
}

void deleteElm_r(listRelasi &LR, adr_r R)
{
    if (R != first(LR) && next(R) == NULL)
    {
        deleteLast_r(LR, R);
    }
    else if (R == first(LR))
    {
        deleteFirst_r(LR, R);
    }
    else if (next(R) != NULL && R != first(LR))
    {
        deleteAfter_r(LR, R);
    }
    delete R;
}

adr_r findElm_r(listRelasi &LR, string email, string name)
{
    if (first(LR) == NULL)
    {
        cout << "RELASI KOSONG" << endl;
    }
    else
    {
        adr_r curr = first(LR);
        while (curr != NULL)
        {
            if (info(parent(curr)).email == email && info(child(curr)).name == name)
            {
                return curr;
            }
            curr = next(curr);
        }


        if (curr == NULL)
        {
            cout << "\n" << email << " dan " << name << " tidak memiliki relasi\n" << endl;
        }
    }

    return NULL;
}

void connect(listRelasi &LR, adr_p P, adr_c C)
{
    if (P != NULL && C != NULL)
    {
        if (info(P).age >= info(C).age_restriction)
        {
            adr_r R = createElm_r(P, C);
            insertLast_r(LR, R);
            cout << "[System][200] Successfully Connected\n";
        }
        else
        {
            cout << "[System][400] Error: Umur user tidak mencukupi untuk mengakses sosmed ini\n";
        }
    }
    else
    {
        cout << "[System][404] Error: Account Not Found\n" << endl;
    }
}

void disconnectThroughParent(listRelasi &LR, adr_p P)
{
    adr_r R = first(LR);
    while (R != NULL)
    {
        if (parent(R) == P)
        {
            parent(R) = NULL;
            child(R) = NULL;
        }
        R = next(R);
    }
}

void disconnectThroughChild(listRelasi &LR, adr_c C)
{
    adr_r R = first(LR);
    while (R != NULL)
    {
        if (child(R) == C)
        {
            parent(R) = NULL;
            child(R) = NULL;
        }
        R = next(R);
    }
}

void showDataChildBasedOnParent(listRelasi LR, adr_p P)
{
    if (!P) return;

    adr_r R = first(LR);
    cout << info(P).username << " => [ ";
    while (R != NULL)
    {
        if (parent(R) == P)
        {
            cout << info(child(R)).name << ", ";
        }
        R = next(R);
    }
    cout << " ]\n";
}

void showDataParentBasedOnChild(listRelasi LR, adr_c C)
{
    if (!C) return;


    adr_r R = first(LR);
    cout << info(C).name << " => [ ";
    while (R != NULL)
    {
        if (child(R) == C)
        {
            cout << info(parent(R)).username << ", ";
        }
        R = next(R);
    }
    cout << " ]\n";
}

void showDataParentRelasiChild(listRelasi LR, listParent LP)
{
    adr_p P = first(LP);
    cout << "\n============ DATA AKUN & SOSMED ===========\n" << endl;

    cout << "+-------------------------------------------------------+";
    cout << "\n| No.\tEmail\t\tSosmed\t\t\t\t|";
    cout << "\n+-------------------------------------------------------+\n";

    int i = 0;
    while (P != NULL)
    {
        i++;
        cout << "| " << i << ".\t";
        cout << info(P).email << "\t";
        adr_r R = first(LR);

        int t = 0; // Variabel t hanya untuk membantu pembuatan layout table

        while (R != NULL)
        {
            if (parent(R) == P)
            {
                cout << info(child(R)).name << " ";
                t++;
            }
            R = next(R);
        }

        // Loop ini hanya untuk pembuatan layout table
        // Awal
        while (t != 4)
        {
            cout << "\t";
            t++;
        }
        cout << "|";
        cout << "\n+-------------------------------------------------------+\n";
        // Akhir

        P = next(P);
    }
    cout << "\n===========================================\n" << endl;
}

void showDataChildRelasiParent(listRelasi LR, listChild LC)
{
    adr_c C = first(LC);
    cout << "\n============ DATA SOSMED & AKUN ============\n" << endl;
    while (C != NULL)
    {
        cout << info(C).name << " => [ ";
        adr_r R = first(LR);
        while (R != NULL)
        {
            if (child(R) == C)
            {
                cout << info(parent(R)).username << ", ";
            }
            R = next(R);
        }
        cout << "]\n";
        C = next(C);
    }
    cout << "\n===========================================\n" << endl;
}

int countDataSosmedFromAkun(listRelasi LR, adr_p P)
{
    int countSosmed = 0;
    adr_r R = first(LR);
    while (R != NULL)
    {
        if (parent(R) == P)
        {
            countSosmed++;
        }
        R = next(R);
    }

    return countSosmed;
}

int countDataAkunFromSosmed(listRelasi LR, adr_c C)
{
    int countAkun = 0;
    adr_r R = first(LR);
    while (R != NULL)
    {
        if (child(R) == C)
        {
            countAkun++;
        }
        R = next(R);
    }
    return countAkun;
}

void countDataSosmedNoAkun(listRelasi LR, listChild LC)
{
    adr_c C = first(LC);
    bool flag = false;
    int countSosmed = 0;

    cout << "Total => ";
    while (C != NULL)
    {
        adr_r R = first(LR);
        while (R != NULL && !flag)
        {
            if (child(R) == C)
            {
                flag = true;
            }
            R = next(R);
        }

        if (!flag)
        {
            countSosmed++;
        }

        flag = false;
        C = next(C);
    }
    cout << countSosmed << " sosmed tidak memiliki akun.\n" << endl;
}

void countDataAkunNoSosmed(listRelasi LR, listParent LP)
{
    adr_p P = first(LP);
    bool flag = false;
    int countAkun = 0;

    cout << "Total => ";
    while (P != NULL)
    {
        adr_r R = first(LR);
        while (R != NULL && !flag)
        {
            if (parent(R) == P)
            {
                flag = true;
            }
            R = next(R);
        }

        if (!flag)
        {
            countAkun++;
        }

        flag = false;
        P = next(P);
    }
    cout << countAkun << " akun tidak memiliki sosmed.\n" << endl;
}

void editRelasi(listRelasi &LR, listParent LP, listChild LC)
{
    string nameSosmed, emailAkun, passwordAkun;
    cout << "Masukkan info untuk mencari relasi yang ingin Anda ubah\n";
    cout << "Email: "; cin >> emailAkun;
    cout << "Nama Sosmed: "; cin >> nameSosmed;
    adr_r R = findElm_r(LR, emailAkun, nameSosmed);

    if (!R) return;

    int option;
    cout << "Pilih menu berikut\n";
    cout << "1. Ganti Relasi Akun dengan Sosmed tertentu\n";
    cout << "2. Ganti Relasi Sosmed dengan Akun tertentu\n";
    cout << "Pilih menu: "; cin >> option;

    if (option == 1)
    {
        cout << "Nama Sosmed: "; cin >> nameSosmed;
        adr_c C = findElm_c(LC, nameSosmed);
        child(R) = C;
        cout << "\nRelasi berhasil diubah\n";
    }
    else if (option == 2)
    {
        cout << "Masukkan info Akun\n";
        cout << "Email: "; cin >> emailAkun;
        cout << "Password: "; cin >> passwordAkun;
        adr_p P = findElm_p(LP, emailAkun, passwordAkun);
        parent(R) = P;
        cout << "\nRelasi berhasil diubah\n";
    }
    else
    {
        cout << "\nINVALID\n";
    }
}
