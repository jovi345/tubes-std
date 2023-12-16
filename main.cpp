#include <iostream>
#include "parent.h"

using namespace std;

int main()
{
    listParent LP;
    infotype_p dataParent;
    adr_p P;
    createList_p(LP);

    showData_p(LP);

    dataParent.email = "john@gmail.com";
    dataParent.username= "john";
    dataParent.password= "123456";
    dataParent.age= 20;
    P = createElm_p(dataParent);
    insertLast_p(LP, P);

    dataParent.email = "jane@gmail.com";
    dataParent.username= "jane";
    dataParent.password= "123Jane321";
    dataParent.age= 15;
    P = createElm_p(dataParent);
    insertLast_p(LP, P);

    dataParent.email = "budi@gmail.com";
    dataParent.username= "budi";
    dataParent.password= "123Budi321";
    dataParent.age= 32;
    P = createElm_p(dataParent);
    insertLast_p(LP, P);

    showData_p(LP);

    adr_p account = findElm_p(LP, "jane@gmail.com", "123Jane321");
    deleteElm_p(LP, account);

    // Menampilkan isi List Parent setelah penghapusan data Jane
    showData_p(LP);

    return 0;
}
