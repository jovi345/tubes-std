#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"

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

    // DATA PARENT END

//-------------------------------------- //

    // PARENT START
        /*
            .....
        */
    // PARENT END

    // RELATION START
        /*
            .....
        */
    // RELATION END

    // CHILD START
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
            name            : "Instagram", "X", "Facebook"
            ratings         : 4.7, 4.8, 4.1
            Age Restriction : 12, 12, 12
        */
    // CHILD END

    // Nomor yg sudah selesai: 2, 5, 8, 11

    option = menu();
    while (option != 0)
    {
        switch (option)
        {
        case 1:
            // NOT YET
            cout << "Case 1" << endl;
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
            // NOT YET
            cout << "Case 3" << endl;
            option = menu();
            break;
        case 4:
            // NOT YET
            cout << "Case 4" << endl;
            break;
        case 5:
            cout << "ID Sosmed yang ingin dihapus   : "; cin >> idSosmed;
            cout << "Name Sosmed yang ingin dihapus : "; cin >> nameSosmed;
            C = findElm_c(LC, idSosmed, nameSosmed);
            if (C != NULL)
            {
                deleteElm_c(LC, C);
                cout << "[System][200] Success\n" << endl;
            }
            option = menu();
            break;
        case 6:
            // NOT YET
            cout << "Case 6" << endl;
            option = menu();
            break;
        case 7:
            // NOT YET
            cout << "Case 7" << endl;
            option = menu();
            break;
        case 8:
            cout << "ID Sosmed yang ingin dicari   : "; cin >> idSosmed;
            cout << "Name Sosmed yang ingin dicari : "; cin >> nameSosmed;
            C = findElm_c(LC, idSosmed, nameSosmed);
            if (C != NULL)
            {
                cout << "==== Data Detail ====" << endl;
                cout << "ID              : " << info(C).ID << endl;
                cout << "Name            : " << info(C).name << endl;
                cout << "Rating          : " << info(C).ratings << endl;
                cout << "Age Restriction : \n" << info(C).age_restriction << endl;
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
            // NOT YET
            cout << "Case 10" << endl;
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
            // NOT YET
            cout << "Case 14" << endl;
            option = menu();
            break;
        case 15:
            // NOT YET
            cout << "Case 15" << endl;
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

    // ------------------------------------------------------------------- //

    // DATA RELASI START
    listRelasi LR;
    createList_r(LR);

    connect(LR, LP, LC, "john@gmail.com", "123456", "C01", "Instagram");
    connect(LR, LP, LC, "john@gmail.com", "123456", "C02", "X");
    connect(LR, LP, LC, "john@gmail.com", "123456", "C03", "Facebook");

    connect(LR, LP, LC, "jane@gmail.com", "123Jane321", "C02", "X");
    connect(LR, LP, LC, "jane@gmail.com", "123Jane321", "C03", "Facebook");

    connect(LR, LP, LC, "budi@gmail.com", "123Budi321", "C01", "Instagram");

    // Data parent beserta data child yang berelasi dengannya
    showDataParentRelasiChild(LR, LP);

    // DATA RELASI END

    return 0;
}
