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

void connect(listRelasi &LR, listParent LP, listChild LC, string email, string password, string ID, string name)
{
    adr_p P = findElm_p(LP, email, password);
    adr_c C = findElm_c(LC, ID, name);

    if (P != NULL && C != NULL)
    {
        adr_r R = createElm_r(P, C);
        insertLast_r(LR, R);
    }
}

void showDataParentRelasiChild(listRelasi LR, listParent LP)
{
    adr_p P = first(LP);
    cout << "\n==========DATA PARENT & CHILDNYA==========\n\n";
    while (P != NULL)
    {
        cout << info(P).email << " => [ ";
        adr_r R = first(LR);
        while (R != NULL)
        {
            if (parent(R) == P)
            {
                cout << R->child->info.name << ", ";
            }
            R = next(R);
        }
        cout << "]\n";
        P = next(P);
    }
    cout << "\n===========================================\n";
}
