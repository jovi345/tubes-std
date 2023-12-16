#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info

using namespace std;

typedef struct elm_c *adr_c;
typedef struct sosmed infotype_c;

struct sosmed
{
    string name, ID;
    int age_restriction;
    float ratings;
};

struct elm_c
{
    infotype_c info;
    adr_c next;
};

struct listChild
{
    adr_c first;
};

void createList_c(listChild &LC);
adr_c createElm_c(infotype_c data);
void insertLast_c(listChild &LC, adr_c C);
void deleteFirst_c(listChild &LC, adr_c C);
void deleteLast_c(listChild &LC, adr_c C);
void deleteAfter(listChild &LC, adr_c C);
void deleteElm_c(listChild &LC, adr_c C);
adr_c findElm_c(listChild LC, string ID, string name);
void showData_c(listChild LC);

#endif // CHILD_H_INCLUDED
