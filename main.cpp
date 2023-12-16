#include <iostream>
#include "parent.h"
#include "child.h"

using namespace std;

int main()
{
    // DATA PARENT START
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

    adr_p account;
    account = findElm_p(LP, "jane@gmail.com", "123Jane321");
    deleteElm_p(LP, account);

    // Menampilkan isi List Parent setelah penghapusan data Jane
    showData_p(LP);

    // Mencari akun yang tidak ditemukan (Password salah)
    account = findElm_p(LP, "jane@gmail.com", "123456");

    account = findElm_p(LP, "john@gmail.com", "123456");
    deleteElm_p(LP, account);
    showData_p(LP);

    account = findElm_p(LP, "budi@gmail.com", "123Budi321");
    deleteElm_p(LP, account);
    showData_p(LP);
    // DATA PARENT END

    cout << "\n------------------------------------------------------------------\n" << endl;

    // DATA CHILD START
    listChild LC;
    infotype_c dataChild;
    adr_c C;
    createList_c(LC);

    showData_c(LC);

    string dataID[] = {"C01", "C02", "C03"};
    string dataSosmed[] = {"Instagram", "X", "Facebook"};
    float dataRatings[] = {4.7, 4.8, 4.1};
    int dataAgeRestriction[] = {12, 12, 12};
    int n = sizeof(dataID) / sizeof(dataID[0]);

    for (int i = 0; i < n; i++) {
        dataChild.ID = dataID[i];
        dataChild.name = dataSosmed[i];
        dataChild.ratings = dataRatings[i];
        dataChild.age_restriction = dataAgeRestriction[i];
        C = createElm_c(dataChild);
        insertLast_c(LC, C);
    }

    showData_c(LC);
    // DATA CHILD END

    return 0;
}
