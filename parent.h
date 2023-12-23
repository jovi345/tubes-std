#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info

using namespace std;

typedef struct elm_p *adr_p;
typedef struct akun infotype_p;

struct akun
{
    string username, email, password;
    int age;
};

struct elm_p
{
    infotype_p info;
    adr_p next;
};

struct listParent
{
    adr_p first;
};

void createList_p(listParent &LP);
adr_p createElm_p(infotype_p data);
void insertLast_p(listParent &LP, adr_p P);
void deleteFirst_p(listParent &LP, adr_p P);
void deleteLast_p(listParent &LP, adr_p P);
void deleteAfter_p(listParent &LP, adr_p Prec, adr_p P);
void deleteElm_p(listParent &LP, adr_p P);
adr_p findElm_p(listParent LP, string username, string email);
void showData_p(listParent LP);

#endif // PARENT_H_INCLUDED
