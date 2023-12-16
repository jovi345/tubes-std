#include "parent.h"

void createList_p(listParent &LP)
{
    first(LP) = NULL;
}

adr_p createElm_p(infotype_p data)
{
    adr_p P;
    P = new elm_p;
    info(P) = data;
    next(P) = NULL;
    return P;
}

void insertLast_p(listParent &LP, adr_p P)
{
    if (first(LP) == NULL)
    {
        first(LP) = P;
    }
    else
    {
        adr_p curr = first(LP);
        while (next(curr) != NULL)
        {
            curr = next(curr);
        }
        next(curr) = P;
    }
}


adr_p findElm_p(listParent LP, string email, string password)
{
    if (first(LP) == NULL)
    {
        cout << "\nLIST PARENT KOSONG\n";
    }
    else
    {
        adr_p curr = first(LP);
        while (curr != NULL)
        {
            if (info(curr).email == email && info(curr).password  == password)
            {
                return curr;
            }
            curr = next(curr);
        }


        if (curr == NULL)
        {
            cout << "\nAkun tidak ditemukan\n";
        }
    }

    return NULL;
}

void deleteFirst_p(listParent &LP, adr_p P)
{
    P = first(LP);
    if (next(first(LP)) == NULL)
    {
        first(LP) = NULL;
    }
    else
    {
        first(LP) = next(P);
    }
}

void deleteLast_p(listParent &LP, adr_p P)
{
    P = first(LP);
    while (next(next(P))!= NULL)
    {
        P = next(P);
    }
    next(P) = NULL;
}

void deleteAfter(listParent &LP, adr_p P)
{
    adr_p Prec = first(LP);
    while (next(Prec) != NULL)
    {
        if (next(Prec) == P)
        {
            break;
        }
        Prec = next(Prec);
    }
    adr_p Q = next(P);
    next(Prec) = Q;
    next(P) = NULL;
}

void deleteElm_p(listParent &LP, adr_p P)
{
    if (P != first(LP) && next(P) == NULL)
    {
        deleteLast_p(LP, P);
    }
    else if (P == first(LP))
    {
        deleteFirst_p(LP, P);
    }
    else if (next(P) != NULL && P != first(LP))
    {
        deleteAfter(LP, P);
    }
    delete P;
}

void showData_p(listParent LP)
{

    if (first(LP) == NULL)
    {
        cout << "\nLIST PARENT KOSONG\n";
    }
    else
    {
        adr_p curr = first(LP);
        int i = 0;
        cout << "\n========DATA_PARENT==========\n";
        while (curr != NULL)
        {
            i++;
            cout << "\nData ke-" << i << "\n";
            cout << "Username: " << curr->info.username << "\n";
            cout << "Email: "<< curr->info.email << "\n";
            cout << "Password: "<< curr->info.password << "\n";
            cout << "Age (year): " << curr->info.age << "\n";
            curr = next(curr);
        }
        cout << "\n==============================\n";
    }
}

