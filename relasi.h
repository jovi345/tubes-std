#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "parent.h"
#include "child.h"

#define first(L) L.first
#define parent(r) r->parent
#define child(r) r->child

using namespace std;

typedef struct elm_r *adr_r;

struct elm_r
{
    adr_p parent;
    adr_c child;
    adr_r next;
};

struct listRelasi
{
    adr_r first;
};

void createList_r(listRelasi &LR);
adr_r createElm_r(adr_p P, adr_c C);
void insertLast_r(listRelasi &LR, adr_r R);
void deleteFirst_r(listRelasi &LR, adr_r R);
void deleteLast_r(listRelasi &LR, adr_r R);
void deleteAfter_r(listRelasi &LR, adr_r R);
void deleteElm_r(listRelasi &LR, adr_r R);
adr_r findElm_r(listRelasi &LR, string email, string ID);
void connect(listRelasi &LR, adr_p P, adr_c C);
void disconnectThroughParent(listRelasi &LR, adr_p P);
void disconnectThroughChild(listRelasi &LR, adr_c C);
void showDataChildBasedOnParent(listRelasi LR, listParent LP, string email);
void showDataParentBasedOnChild(listRelasi LR, listChild LC, string ID);
void showDataParentRelasiChild(listRelasi LR, listParent LP);
void showDataChildRelasiParent(listRelasi LR, listChild LC);
void countDataSosmedFromAkun(listRelasi LR, listParent LP, string usernameAkun);
void countDataAkunFromSosmed(listRelasi LR, listChild LC, string nameSosmed);

#endif // RELASI_H_INCLUDED
