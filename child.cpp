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
            if (info(curr).ID == ID && info(curr).name  == name)
            {
                return curr;
            }
            curr = next(curr);
        }


        if (curr == NULL)
        {
            cout << "Sosmed tidak ditemukan" << endl;
        }
    }

    return NULL;
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
        cout << "======== DATA_SOSMED =========" << endl;
        while (curr != NULL)
        {
            i++;
            cout << "\nData ke-" << i << endl;
            cout << "ID              : " << info(curr).ID << endl;
            cout << "name            : "<< info(curr).name << endl;
            cout << "ratings         : "<< info(curr).ratings << endl;
            cout << "age restriction : " << info(curr).age_restriction << endl;
            curr = next(curr);
        }
        cout << "==============================" << endl;
    }
}
