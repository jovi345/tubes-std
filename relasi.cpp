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

adr_r findElm_r(listRelasi &LR, string email, string ID)
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
            if (info(parent(curr)).email == email && info(child(curr)).ID == ID)
            {
                return curr;
            }
            curr = next(curr);
        }


        if (curr == NULL)
        {
            cout << "\n" << email << " dan ID " << ID << " tidak memiliki relasi\n" << endl;
        }
    }

    return NULL;
}

void connect(listRelasi &LR, listParent LP, listChild LC, string email, string password, string ID, string name)
{
    adr_p P = findElm_p(LP, email, password);
    adr_c C = findElm_c(LC, ID, name);

    if (P != NULL && C != NULL)
    {
        adr_r R = createElm_r(P, C);
        insertLast_r(LR, R);
        cout << "[System][200] Success\n" << endl;
    }
    else
    {
        cout << "[System][404] error not found\n" << endl;
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

void showDataChildBasedOnParent(listRelasi LR, listParent LP, string email)
{
    adr_p P = first(LP);
    while (P != NULL)
    {
        if (info(P).email == email)
        {
            cout << info(P).username << " => [ ";
            adr_r R = first(LR);
            while (R != NULL)
            {
                if (parent(R) == P)
                {
                    cout << info(child(R)).name << ", ";
                }
                R = next(R);
            }
            cout << "]\n" << endl;
        }
        P = next(P);
    }
}

void showDataParentBasedOnChild(listRelasi LR, listChild LC, string ID)
{
    adr_c C = first(LC);
    while (C != NULL)
    {
        if (info(C).ID == ID)
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
            cout << "]\n" << endl;
        }
        C = next(C);
    }
}

void showDataParentRelasiChild(listRelasi LR, listParent LP)
{
    adr_p P = first(LP);
    cout << "\n============ DATA AKUN & SOSMED ===========\n" << endl;
    while (P != NULL)
    {
        cout << info(P).username << " => [ ";
        adr_r R = first(LR);
        while (R != NULL)
        {
            if (parent(R) == P)
            {
                cout << info(child(R)).name << ", ";
            }
            R = next(R);
        }
        cout << "]\n";
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

void countDataSosmedFromAkun(listRelasi LR, listParent LP, string usernameAkun)
{
    int sum = 0;
    adr_p P = first(LP);
    while (P != NULL)
    {
        if (info(P).username == usernameAkun)
        {
            cout << info(P).username << " => ";
            adr_r R = first(LR);
            while (R != NULL)
            {
                if (parent(R) == P)
                {
                    sum++;
                }
                R = next(R);
            }
            cout << sum << endl; cout << endl;
        }
        P = next(P);
    }
}

void countDataAkunFromSosmed(listRelasi LR, listChild LC, string nameSosmed)
{
    int sum = 0;
    adr_c C = first(LC);
    while (C != NULL)
    {
        if (info(C).name == nameSosmed)
        {
            cout << info(C).name << " => ";
            adr_r R = first(LR);
            while (R != NULL)
            {
                if (child(R) == C)
                {
                    sum++;
                }
                R = next(R);
            }
            cout << sum << endl; cout << endl;
        }
        C = next(C);
    }
}

