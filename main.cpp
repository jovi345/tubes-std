#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

int main()
{
    /* DATA PARENT START
    listParent LP;
    infotype_p dataParent;
    adr_p P;
    createList_p(LP);

    showData_p(LP);

    dataParent.email = "john@gmail.com";
    dataParent.username= "John";
    dataParent.password= "123456";
    dataParent.age= 20;
    P = createElm_p(dataParent);
    insertLast_p(LP, P);

    dataParent.email = "jane@gmail.com";
    dataParent.username= "Jane";
    dataParent.password= "123Jane321";
    dataParent.age= 15;
    P = createElm_p(dataParent);
    insertLast_p(LP, P);

    dataParent.email = "budi@gmail.com";
    dataParent.username= "Budi";
    dataParent.password= "123Budi321";
    dataParent.age= 32;
    P = createElm_p(dataParent);
    insertLast_p(LP, P);

    showData_p(LP);
    DATA PARENT END */



    // function menu ada di child.cpp

    /** PARENT START **/
    listParent LP;
    infotype_p dataParent;
    adr_p P;
    string emailAkun, usernameAkun, passwordAkun;
    int ageAkun;
    createList_p(LP);
        /*
            --- DATA INPUT PARENT ---
            Email    : "john@gmail.com", "jane@gmail.com", "budi@gmail.com"
            Username : "John", "Jane", "Budi"
            Password : "123456", "123Jane321", "123Budi321"
            Age      : 20, 15, 32
        */
    /** PARENT END **/

    /** RELATION START **/
    listRelasi LR;
    createList_r(LR);
        /*
            --- DATA INPUT RELATION ---
            Email       : "john@gmail.com", "jane@gmail.com", "budi@gmail.com"
            Password    : "123456", "123Jane321", "123Budi321"
            ID Sosmed   : "C01", "C02", "C03"
            Nama Sosmed : "Instagram", "Telegram", "Facebook"
        */
    /** RELATION END **/

    /** CHILD START **/
    listChild LC;
    infotype_c dataChild;
    adr_c C;
    string idSosmed, nameSosmed;
    float ratingsSosmed;
    int ageRestriction, option;
    createList_c(LC);
        /*
            --- DATA INPUT CHILD ---
            Id              : "C01", "C02", "C03"
            name            : "Instagram", "Telegram", "Facebook"
            ratings         : 4.7, 4.8, 4.1
            Age Restriction : 12, 12, 12
        */
    /** CHILD END **/

    // Nomor yg sudah selesai: 1, 2, 3, 4, 5, 7, 8, 10, 11, 14, 15

    option = menu();
    while (option != 0)
    {
        switch (option)
        {
        case 1:
            cout << "Email    : "; cin >> emailAkun;
            cout << "Username : "; cin >> usernameAkun;
            cout << "Password : "; cin >> passwordAkun;
            cout << "Age      : "; cin >> ageAkun;
            dataParent.email = emailAkun;
            dataParent.username = usernameAkun;
            dataParent.password = passwordAkun;
            dataParent.age = ageAkun;
            P = createElm_p(dataParent);
            insertLast_p(LP, P);
            cout << "[System][200] Success\n" << endl;
            option = menu();
            break;
        case 2:
            cout << "ID Sosmed       : "; cin >> idSosmed;
            cout << "Name Sosmed     : "; cin >> nameSosmed;
            cout << "Rating          : "; cin >> ratingsSosmed;
            cout << "Age Restriction : "; cin >> ageRestriction;
            dataChild.ID = idSosmed;
            dataChild.name = nameSosmed;
            dataChild.ratings = ratingsSosmed;
            dataChild.age_restriction = ageRestriction;
            C = createElm_c(dataChild);
            insertLast_c(LC, C);
            cout << "[System][200] Success\n" << endl;
            option = menu();
            break;
        case 3:
            cout << "Masukkan data yang ingin direlasikan [Email(Akun), Password(Akun), ID(Sosmed), Name(Sosmed)]" << endl;
            cout << "Email       : "; cin >> emailAkun;
            cout << "Password    : "; cin >> passwordAkun;
            cout << "ID Sosmed   : "; cin >> idSosmed;
            cout << "Name Sosmed : "; cin >> nameSosmed;
            connect(LR, LP, LC, emailAkun, passwordAkun, idSosmed, nameSosmed);
            option = menu();
            break;
        case 4:
            cout << "Email yang ingin dihapus    : "; cin >> emailAkun;
            cout << "Password yang ingin dihapus : "; cin >> passwordAkun;
            P = findElm_p(LP, emailAkun, passwordAkun);
            if (P != NULL)
            {
                deleteElm_p(LP, P);
                cout << "[System][200] Success\n" << endl;
            }
            else
            {
                cout << "[System][404] Error Request\n" << endl;
            }
            option = menu();
            break;
        case 5:
            cout << "ID Sosmed yang ingin dihapus   : "; cin >> idSosmed;
            cout << "Nama Sosmed yang ingin dihapus : "; cin >> nameSosmed;
            C = findElm_c(LC, idSosmed, nameSosmed);
            if (C != NULL)
            {
                deleteElm_c(LC, C);
                cout << "[System][200] Success\n" << endl;
            }
            else
            {
                cout << "[System][404] Error Request\n" << endl;
            }
            option = menu();
            break;
        case 6:
            // NOT YET
            cout << "Case 6" << endl;
            option = menu();
            break;
        case 7:
            cout << "==== DATA AKUN ====" << endl;
            cout << "Email yang ingin dicari    : "; cin >> emailAkun;
            cout << "Password yang ingin dicari : "; cin >> passwordAkun;
            P = findElm_p(LP, emailAkun, passwordAkun);
            if (P != NULL)
            {
                cout << "==== Data Detail ====" << endl;
                cout << "Username  : " << info(P).username << endl;
                cout << "Email     : " << info(P).email << endl;
                cout << "Password  : " << info(P).password << endl;
                cout << "Age       : " << info(P).age << "\n\n";
            }
            else
            {
                cout << "[System][404] Error Request\n" << endl;
            }
            option = menu();
            break;
        case 8:
            cout << "==== DATA SOSMED ====" << endl;
            cout << "ID Sosmed yang ingin dicari   : "; cin >> idSosmed;
            cout << "Nama Sosmed yang ingin dicari : "; cin >> nameSosmed;
            C = findElm_c(LC, idSosmed, nameSosmed);
            if (C != NULL)
            {
                cout << "==== Data Detail ====" << endl;
                cout << "ID              : " << info(C).ID << endl;
                cout << "Name            : " << info(C).name << endl;
                cout << "Rating          : " << info(C).ratings << endl;
                cout << "Age Restriction : " << info(C).age_restriction << "\n\n";
            }
            else
            {
                cout << "[System][404] Error Request\n" << endl;
            }
            option = menu();
            break;
        case 9:
            // NOT YET
            cout << "Case 9" << endl;
            option = menu();
            break;
        case 10:
            showData_p(LP);
            option = menu();
            break;
        case 11:
            showData_c(LC);
            option = menu();
            break;
        case 12:
            // NOT YET
            cout << "Case 12" << endl;
            option = menu();
            break;
        case 13:
            // NOT YET
            cout << "Case 13" << endl;
            option = menu();
            break;
        case 14:
            showDataParentRelasiChild(LR, LP);
            option = menu();
            break;
        case 15:
            showDataChildRelasiParent(LR, LC);
            option = menu();
            break;
        case 16:
            // NOT YET
            cout << "Case 16" << endl;
            option = menu();
            break;
        case 17:
            // NOT YET
            cout << "Case 17" << endl;
            option = menu();
            break;
        case 18:
            // NOT YET
            cout << "Case 18" << endl;
            option = menu();
            break;
        case 19:
            // NOT YET
            cout << "Case 19" << endl;
            option = menu();
            break;
        case 20:
            // NOT YET
            cout << "Case 20" << endl;
            option = menu();
            break;
        case 0:
            break;
        default:
            cout << "Invalid option, Please try again.\n" << endl;
            option = menu();
            break;
        }
    }




    // DATA RELASI START
    /** listRelasi LR;
    createList_r(LR);

    connect(LR, LP, LC, "john@gmail.com", "123456", "C01", "Instagram");
    connect(LR, LP, LC, "john@gmail.com", "123456", "C02", "X");
    connect(LR, LP, LC, "john@gmail.com", "123456", "C03", "Facebook");

    connect(LR, LP, LC, "jane@gmail.com", "123Jane321", "C02", "X");
    connect(LR, LP, LC, "jane@gmail.com", "123Jane321", "C03", "Facebook");

    connect(LR, LP, LC, "budi@gmail.com", "123Budi321", "C01", "Instagram");

    // Data parent beserta data child yang berelasi dengannya
    showDataParentRelasiChild(LR, LP); **/

    // DATA RELASI END

    return 0;
}
