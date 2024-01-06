#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

int main()
{
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
    adr_r R;
    int total;
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
            cout << "Masukkan data yang ingin direlasikan [Email(Akun), Password(Akun), Name(Sosmed)]" << endl;
            cout << "Email       : "; cin >> emailAkun;
            cout << "Password    : "; cin >> passwordAkun;
            cout << "Name Sosmed : "; cin >> nameSosmed;
            P = findElm_p(LP, emailAkun, passwordAkun);
            C = findElm_c(LC, nameSosmed);
            connect(LR, P, C);
            option = menu();
            break;
        case 4:
            cout << "Email yang ingin dihapus    : "; cin >> emailAkun;
            cout << "Password yang ingin dihapus : "; cin >> passwordAkun;
            P = findElm_p(LP, emailAkun, passwordAkun);
            if (P != NULL)
            {
                adr_r R = first(LR);
                while(R != NULL)
                {
                    disconnectThroughParent(LR, P);
                    R = next(R);
                }
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
            cout << "Nama Sosmed yang ingin dihapus : "; cin >> nameSosmed;
            C = findElm_c(LC, nameSosmed);
            if (C != NULL)
            {
                adr_r R = first(LR);
                while (R != NULL)
                {
                    disconnectThroughChild(LR, C);
                    R = next(R);
                }
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
            cout << "==== DATA RELASI ====" << endl;
            cout << "Email Akun : "; cin >> emailAkun;
            cout << "Nama Sosmed : "; cin >> nameSosmed;
            R = findElm_r(LR, emailAkun, nameSosmed);
            if (R != NULL)
            {
                deleteElm_r(LR, R);
                cout << "[System][200] Success\n" << endl;
            }
            else
            {
                cout << "[System][404] Error Request\n" << endl;
            }
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
            cout << "Nama Sosmed yang ingin dicari : "; cin >> nameSosmed;
            C = findElm_c(LC, nameSosmed);
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
            cout << "==== DATA RELASI ====" << endl;
            cout << "Email Akun : "; cin >> emailAkun;
            cout << "Nama Sosmed : "; cin >> nameSosmed;
            R = findElm_r(LR, emailAkun, nameSosmed);
            if (R != NULL)
            {
                cout << "\n" << emailAkun << " dan ID " << nameSosmed << " memiliki relasi\n" << endl;
            }
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
            cout << "Email: "; cin >> emailAkun;
            cout << "Password: "; cin >> passwordAkun;
            P = findElm_p(LP, emailAkun, passwordAkun);
            showDataChildBasedOnParent(LR, P);
            option = menu();
            break;
        case 13:
            cout << "Nama Sosmed : "; cin >> nameSosmed;
            C = findElm_c(LC, nameSosmed);
            showDataParentBasedOnChild(LR, C);
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
            cout << "Email: "; cin >> emailAkun;
            cout << "Password : "; cin >> passwordAkun;
            P = findElm_p(LP, emailAkun, passwordAkun);
            total = countDataSosmedFromAkun(LR, P);
            cout << info(P).username << " terhubung ke " << total << " sosmed\n";
            option = menu();
            break;
        case 17:
            cout << "Masukkan Nama Sosmed : "; cin >> nameSosmed;
            C = findElm_c(LC, nameSosmed);
            total = countDataAkunFromSosmed(LR, C);
            cout << info(C).name << " memiliki " << total << " pengguna\n";
            option = menu();
            break;
        case 18:
            countDataSosmedNoAkun(LR, LC);
            option = menu();
            break;
        case 19:
            countDataAkunNoSosmed(LR, LP);
            option = menu();
            break;
        case 20:
            editRelasi(LR, LP, LC);
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

    return 0;
}
