#include "staff.h"
void login() {
    string tk, mk;
    cout << "ID: ";
    getline(cin, tk);
    bool showPassword = false;
    cout << "PASSWORD: ";
    while (true) {
        char c = _getch();
        if (c == '\r') {
            break;
        }
        else if (c == 'h' || c == 'H') {
            showPassword = !showPassword;
            continue;
        }
        if (showPassword) {
            cout << c;
        }
        else {
            cout << "*";
        }
        mk += c;
    }
    cout << endl;
    ofstream w;
    w.open("C:/Users/Administrator/Documents/Data/tkmk.txt", ios::out);
    w << tk << endl;
    w << mk;
}
void changepasswork() {
    ifstream r;
    string tk, mk;
    r.open("C:/Users/Administrator/Documents/Data/tkmk.txt", ios::in);
    r >> tk;
    r >> mk;
    string mk1;
    bool showPassword = false;
    do {
        system("cls");
        cout << "Cur Password: ";
        while (true) {
            char c = _getch();
            if (c == '\r') {
                break;
            }
            else if (c == 'h' || c == 'H') {
                showPassword = !showPassword;
                continue;
            }
            if (showPassword) {
                cout << c;
            }
            else {
                cout << "*";
            }
            mk1 += c;
        }
        cout << endl;
        if (mk != mk1)
            cout << "Wrong!. Please re-enter !!" << endl;
        this_thread::sleep_for(chrono::seconds(2)); // tam dung chuong trinh 2s
    } while (mk != mk1);
    cout << "Enter new password: ";
    mk = "";
    while (true) {
        char c = _getch();
        if (c == '\r') {
            break;
        }
        else if (c == 'h' || c == 'H') {
            showPassword = !showPassword;
            continue;
        }
        if (showPassword) {
            cout << c;
        }
        else {
            cout << "*";
        }
        mk += c;
    }
    cout << endl;
    this_thread::sleep_for(chrono::seconds(2));
    ofstream w;
    w.open("C:/Users/Administrator/Documents/Data/tkmk.txt", ios::out);
    w << tk << endl;
    w << mk;
    w.close();
    r.close();
    system("cls");
    cout << "Succesfull!" << endl;
}
void chon() {
    int option = 1;
    while (true) {
    first:
        system("cls");
        cout << "Choose types of users: \n";
        if (option == 1) {
            cout << "> STAFF\n";
        }
        else {
            cout << "  STAFF\n";
        }
        if (option == 2) {
            cout << "> STUDENT\n";
        }
        else {
            cout << "  STUDENT\n";
        }
        char c = _getch();
        if (c == 72) { // Nút mui tên lên
            if (option > 1) {
                option--;
            }
            else {
                option = 2;
            }
        }
        else if (c == 80) { // Nút mui tên xu?ng
            if (option < 2) {
                option++;
            }
            else {
                option = 1;
            }
        }
        else if (c == '\r') { // Nút Enter
            system("cls");
            if (option == 1) {// ctt2
                login();
                int option = 1;
            
                while (true) {
                    system("cls");
                    
                    if (option == 1) {
                        cout << "> Log in.\n";
                    }
                    else {
                        cout << "  Log in.\n";
                    }
                    if (option == 2) {
                        cout << "> EXIT !\n";
                    }
                    else {
                        cout << "  EXIT !\n";
                    }
                    char c = _getch();
                    if (c == 72) { // Nút mui tên lên
                        if (option > 1) {
                            option--;
                        }
                        else {
                            option = 2;
                        }
                    }
                    else if (c == 80) { // Nút mui tên xu?ng
                        if (option < 2) {
                            option++;
                        }
                        else {
                            option = 1;
                        }
                    }
                    else if (c == '\r') { // Nút Enter
                        if (option == 1) {
                            option = 1;
                            while (true) {
                            second:
                                system("cls");
                                cout << "Choose function: \n";
                                if (option == 1) {
                                    cout << "> Profile. \n";
                                }
                                else {
                                    cout << "  Profile.\n";
                                }
                                if (option == 2) {
                                    cout << "> Manage student.\n";
                                }
                                else {
                                    cout << "  Manage student.\n";
                                }
                                if (option == 3) {
                                    cout << "> Manage courses. \n";
                                }
                                else {
                                    cout << "  Manage courses. \n";
                                }
                                if (option == 4) {
                                    cout << "> Change password. \n\n";
                                }
                                else {
                                    cout << "  Change password.\n\n";
                                }
                                if (option == 5) {
                                    cout << "> Back! \n";
                                }
                                else {
                                    cout << "  Back! \n";
                                }
                                char c = _getch();
                                if (c == 72) {
                                    if (option > 1) {
                                        option--;
                                    }
                                    else {
                                        option = 5;
                                    }
                                }
                                else if (c == 80) {
                                    if (option < 5) {
                                        option++;
                                    }
                                    else {
                                        option = 1;
                                    }
                                }
                                else if (c == '\r') {
                                    system("cls");
                                    if (option == 1) {
                                        ifstream r;
                                        profilestaff();
                                        char a = _getch();
                                        if (a == ESC)
                                            goto second;
                                    }
                                    else if (option == 2) {
                                        option = 1;
                                        while (true) {
                                        managestudent:
                                            system("cls");
                                            if (option == 1) {
                                                cout << "> School Year Information. \n";
                                            }
                                            else {
                                                cout << "  School Year Information. \n";
                                            }
                                            if (option == 2) {
                                                cout << "> Create Classes. \n";
                                            }
                                            else {
                                                cout << "  Create Classes. \n";
                                            }
                                            if (option == 3) {
                                                cout << "> List Of Classes. \n\n";
                                            }
                                            else {
                                                cout << "  List Of Classes. \n\n";
                                            }
                                            if (option == 4) {
                                                cout << "> Back! \n";
                                            }
                                            else {
                                                cout << "  Back!\n";
                                            }
                                            char c = _getch();
                                            if (c == 72) {
                                                if (option > 1) {
                                                    option--;
                                                }
                                                else {
                                                    option = 4;
                                                }
                                            }
                                            else if (c == 80) {
                                                if (option < 4) {
                                                    option++;
                                                }
                                                else {
                                                    option = 1;
                                                }
                                            }
                                            else if (c == '\r') { // Nút Enter
                                                if (option == 1) {
                                                    system("cls");
                                                    cout << "School Year 2022-2023" << endl;
                                                    cout << "Start date: 02/10/2022" << endl;
                                                    cout << "End date: 9/2023" << endl;
                                                    char a = _getch();
                                                    if (a == ESC)
                                                        goto managestudent;
                                                }
                                                else if (option == 2) {
                                                    option = 1;
                                                createclass:
                                                    while (1) {
                                                        system("cls");

                                                        if (option == 1) {
                                                            cout << "> Input Class Data. \n";
                                                        }
                                                        else {
                                                            cout << "  Input Class Data. \n";
                                                        }
                                                        if (option == 2) {
                                                            cout << "> Import Class Data File. \n\n";
                                                        }
                                                        else {
                                                            cout << "  Import Class Data File. \n\n";
                                                        }

                                                        if (option == 3) {
                                                            cout << "> Back! \n";
                                                        }
                                                        else {
                                                            cout << "  Back!\n";
                                                        }
                                                        char c = _getch();
                                                        if (c == 72) {
                                                            if (option > 1) {
                                                                option--;
                                                            }
                                                            else {
                                                                option = 3;
                                                            }
                                                        }
                                                        else if (c == 80) {
                                                            if (option < 3) {
                                                                option++;
                                                            }
                                                            else {
                                                                option = 1;
                                                            }
                                                        }
                                                        else if (c == '\r') { // Nút Enter
                                                            if (option == 1) {
                                                                system("cls");
                                                                inputClassData();
                                                                char a = _getch();
                                                                if (a == ESC)
                                                                    goto managestudent;
                                                            }
                                                            if (option == 2) {
                                                                system("cls");
                                                                importClassData();
                                                                char a = _getch();
                                                                if (a == ESC)
                                                                    goto managestudent;
                                                            }
                                                            if (option == 3)
                                                                goto managestudent;
                                                        }
                                                    }
                                                }
                                                else if (option == 3) {
                                                    option = 1;
                                                    while (true) {
                                                    listofclass:
                                                        system("cls");
                                                        if (option == 1) {
                                                            cout << "> First - year Classes. \n";
                                                        }
                                                        else {
                                                            cout << "  First - year Classes. \n";
                                                        }
                                                        if (option == 2) {
                                                            cout << "> Second - year Classes. \n";
                                                        }
                                                        else {
                                                            cout << "  Second - year Classes. \n";
                                                        }
                                                        if (option == 3) {
                                                            cout << "> Third - year Classes. \n";
                                                        }
                                                        else {
                                                            cout << "  Third - year Classes. \n";
                                                        }
                                                        if (option == 4) {
                                                            cout << "> Final - year Classes. \n\n";
                                                        }
                                                        else {
                                                            cout << "  Final - year Classes. \n\n";
                                                        }
                                                        if (option == 5) {
                                                            cout << "> Back! \n";
                                                        }
                                                        else {
                                                            cout << "  Back!\n";
                                                        }
                                                        char c = _getch();
                                                        if (c == 72) {
                                                            if (option > 1) {
                                                                option--;
                                                            }
                                                            else {
                                                                option = 5;
                                                            }
                                                        }
                                                        else if (c == 80) {
                                                            if (option < 5) {
                                                                option++;
                                                            }
                                                            else {
                                                                option = 1;
                                                            }
                                                        }
                                                        else if (c == '\r') { // Nút Enter
                                                            if (option == 1) {
                                                                // nam nhat
                                                                option = 1;
                                                                while (true) {
                                                                firstclass:
                                                                    system("cls");
                                                                    if (option == 1) {
                                                                        cout << "> 21CTT1. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT1. \n";
                                                                    }
                                                                    if (option == 2) {
                                                                        cout << "> 21CTT2. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT2. \n";
                                                                    }
                                                                    if (option == 3) {
                                                                        cout << "> 21CTT3. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT3. \n";
                                                                    }
                                                                    if (option == 4) {
                                                                        cout << "> 21CTT4. \n\n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT4. \n\n";
                                                                    }
                                                                    if (option == 5) {
                                                                        cout << "> Back! \n";
                                                                    }
                                                                    else {
                                                                        cout << "  Back!\n";
                                                                    }
                                                                    char c = _getch();
                                                                    if (c == 72) {
                                                                        if (option > 1) {
                                                                            option--;
                                                                        }
                                                                        else {
                                                                            option = 5;
                                                                        }
                                                                    }
                                                                    else if (c == 80) {
                                                                        if (option < 5) {
                                                                            option++;
                                                                        }
                                                                        else {
                                                                            option = 1;
                                                                        }
                                                                    }
                                                                    else if (c == '\r') { // Nút Enter
                                                                        if (option == 1) {
                                                                            system("cls");
                                                                            ifstream r;
                                                                            r.open("C:/Users/Administrator/Documents/Data/2022-2023/22CTT1.csv");
                                                                            if (r.is_open())
                                                                                doc_xuatconsole("C:/Users/Administrator/Documents/Data/2022-2023/22CTT1.csv");
                                                                            else
                                                                                cout << "Empty!" << endl;
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto firstclass;
                                                                            // gắn các hàm đọc xuất danh sách lớp
                                                                        }
                                                                        else if (option == 2) {
                                                                            system("cls");
                                                                            ifstream r;
                                                                            r.open("C:/Users/Administrator/Documents/Data/2022-2023/22CTT2.csv");
                                                                            if (r.is_open())
                                                                                doc_xuatconsole("C:/Users/Administrator/Documents/Data/2022-2023/22CTT2.csv");
                                                                            else
                                                                                cout << "Empty!" << endl;
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto firstclass;
                                                                        }
                                                                        else if (option == 3) {
                                                                            system("cls");
                                                                            ifstream r;
                                                                            r.open("C:/Users/Administrator/Documents/Data/2022-2023/22CTT3.csv");
                                                                            if (r.is_open())
                                                                                doc_xuatconsole("C:/Users/Administrator/Documents/Data/2022-2023/22CTT3.csv");
                                                                            else
                                                                                cout << "Empty!" << endl;
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto firstclass;
                                                                        }
                                                                        else if (option == 4) {
                                                                            system("cls");
                                                                            ifstream r;
                                                                            r.open("C:/Users/Administrator/Documents/Data/2022-2023/22CTT4.csv");
                                                                            if (r.is_open())
                                                                                doc_xuatconsole("C:/Users/Administrator/Documents/Data/2022-2023/22CTT4.csv");
                                                                            else
                                                                                cout << "Empty!" << endl;
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto firstclass;
                                                                        }
                                                                        else if (option == 5) {
                                                                            option = 1;
                                                                            goto listofclass;
                                                                        }
                                                                    }
                                                                }
                                                                // nam nhat
                                                            }
                                                            else if (option == 2) {
                                                                //
                                                                option = 1;
                                                                while (true) {
                                                                secondclass:
                                                                    system("cls");
                                                                    if (option == 1) {
                                                                        cout << "> 21CTT1. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT1. \n";
                                                                    }
                                                                    if (option == 2) {
                                                                        cout << "> 21CTT2. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT2. \n";
                                                                    }
                                                                    if (option == 3) {
                                                                        cout << "> 21CTT3. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT3. \n";
                                                                    }
                                                                    if (option == 4) {
                                                                        cout << "> 21CTT4. \n\n";
                                                                    }
                                                                    else {
                                                                        cout << "  21CTT4. \n\n";
                                                                    }
                                                                    if (option == 5) {
                                                                        cout << "> Back! \n";
                                                                    }
                                                                    else {
                                                                        cout << "  Back!\n";
                                                                    }
                                                                    char c = _getch();
                                                                    if (c == 72) {
                                                                        if (option > 1) {
                                                                            option--;
                                                                        }
                                                                        else {
                                                                            option = 5;
                                                                        }
                                                                    }
                                                                    else if (c == 80) {
                                                                        if (option < 5) {
                                                                            option++;
                                                                        }
                                                                        else {
                                                                            option = 1;
                                                                        }
                                                                    }
                                                                    else if (c == '\r') { // Nút Enter
                                                                        if (option == 1) {
                                                                            system("cls");
                                                                            cout << "21CTT1 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2021-2022/21CTT1.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto secondclass;
                                                                            // gắn các hàm đọc xuất danh sách lớp
                                                                        }
                                                                        else if (option == 2) {
                                                                            system("cls");
                                                                            cout << "21CTT2 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2021-2022/21CTT2.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto secondclass;
                                                                        }
                                                                        else if (option == 3) {
                                                                            system("cls");
                                                                            cout << "21CTT3 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2021-2022/21CTT3.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto secondclass;
                                                                        }
                                                                        else if (option == 4) {
                                                                            system("cls");
                                                                            cout << "21CTT4 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2021-2022/21CTT4.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto secondclass;
                                                                        }
                                                                        else if (option == 5) {
                                                                            option = 1;
                                                                            goto listofclass;
                                                                        }
                                                                    }
                                                                }
                                                                //
                                                            }
                                                            else if (option == 3) {
                                                                //
                                                                option = 1;
                                                                while (true) {
                                                                thirdclass:
                                                                    system("cls");
                                                                    if (option == 1) {
                                                                        cout << "> 20CTT1. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  20CTT1. \n";
                                                                    }
                                                                    if (option == 2) {
                                                                        cout << "> 20CTT2. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  20CTT2. \n";
                                                                    }
                                                                    if (option == 3) {
                                                                        cout << "> 20CTT3. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  20CTT3. \n";
                                                                    }
                                                                    if (option == 4) {
                                                                        cout << "> 20CTT4. \n\n";
                                                                    }
                                                                    else {
                                                                        cout << "  20CTT4. \n\n";
                                                                    }
                                                                    if (option == 5) {
                                                                        cout << "> Back! \n";
                                                                    }
                                                                    else {
                                                                        cout << "  Back!\n";
                                                                    }
                                                                    char c = _getch();
                                                                    if (c == 72) {
                                                                        if (option > 1) {
                                                                            option--;
                                                                        }
                                                                        else {
                                                                            option = 5;
                                                                        }
                                                                    }
                                                                    else if (c == 80) {
                                                                        if (option < 5) {
                                                                            option++;
                                                                        }
                                                                        else {
                                                                            option = 1;
                                                                        }
                                                                    }
                                                                    else if (c == '\r') { // Nút Enter
                                                                        if (option == 1) {
                                                                            system("cls");
                                                                            cout << "20CTT1 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2020-2021/20CTT1.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto thirdclass;
                                                                            // gắn các hàm đọc xuất danh sách lớp
                                                                        }
                                                                        else if (option == 2) {
                                                                            system("cls");
                                                                            cout << "20CTT2 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2020-2021/20CTT2.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto thirdclass;
                                                                        }
                                                                        else if (option == 3) {
                                                                            system("cls");
                                                                            cout << "20CTT3 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2020-2021/20CTT3.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto thirdclass;
                                                                        }
                                                                        else if (option == 4) {
                                                                            system("cls");
                                                                            cout << "20CTT4 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2020-2021/20CTT4.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto thirdclass;
                                                                        }
                                                                        else if (option == 5) {
                                                                            option = 1;
                                                                            goto listofclass;
                                                                        }
                                                                    }
                                                                }
                                                                //
                                                            }
                                                            else if (option == 4) {
                                                                //
                                                                option = 1;
                                                                while (true) {
                                                                finalclass:
                                                                    system("cls");
                                                                    if (option == 1) {
                                                                        cout << "> 19CTT1. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  19CTT1. \n";
                                                                    }
                                                                    if (option == 2) {
                                                                        cout << "> 19CTT2. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  19CTT2. \n";
                                                                    }
                                                                    if (option == 3) {
                                                                        cout << "> 19CTT3. \n";
                                                                    }
                                                                    else {
                                                                        cout << "  19CTT3. \n";
                                                                    }
                                                                    if (option == 4) {
                                                                        cout << "> 19CTT4. \n\n";
                                                                    }
                                                                    else {
                                                                        cout << "  19CTT4. \n\n";
                                                                    }
                                                                    if (option == 5) {
                                                                        cout << "> Back! \n";
                                                                    }
                                                                    else {
                                                                        cout << "  Back!\n";
                                                                    }
                                                                    char c = _getch();
                                                                    if (c == 72) {
                                                                        if (option > 1) {
                                                                            option--;
                                                                        }
                                                                        else {
                                                                            option = 5;
                                                                        }
                                                                    }
                                                                    else if (c == 80) {
                                                                        if (option < 5) {
                                                                            option++;
                                                                        }
                                                                        else {
                                                                            option = 1;
                                                                        }
                                                                    }
                                                                    else if (c == '\r') { // Nút Enter
                                                                        if (option == 1) {
                                                                            system("cls");
                                                                            cout << "19CTT1 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2019-2020/19CTT1.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto finalclass;
                                                                            // gắn các hàm đọc xuất danh sách lớp
                                                                        }
                                                                        else if (option == 2) {
                                                                            system("cls");
                                                                            cout << "19CTT2 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2019-2020/19CTT2.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto finalclass;
                                                                        }
                                                                        else if (option == 3) {
                                                                            system("cls");
                                                                            cout << "19CTT3 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2019-2020/19CTT3.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto finalclass;
                                                                        }
                                                                        else if (option == 4) {
                                                                            system("cls");
                                                                            cout << "19CTT4 !" << endl;
                                                                            doc_xuatconsole("C:/Users/Administrator/Documents/Data/2019-2020/19CTT4.csv");
                                                                            char a = _getch();
                                                                            if (a == ESC)
                                                                                goto finalclass;
                                                                        }
                                                                        else if (option == 5) {
                                                                            option = 1;
                                                                            goto listofclass;
                                                                        }
                                                                    }
                                                                }
                                                                //
                                                            }
                                                            else if (option == 5) {
                                                                goto managestudent;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (option == 4)
                                                    goto second;
                                            }
                                        }
                                    }
                                    else if (option == 3) {
                                        // managecourses
                                        option = 1;
                                        while (true) {
                                        managecourse:
                                            system("cls");
                                            if (option == 1) {
                                                cout << "> Semester Information. \n";
                                            }
                                            else {
                                                cout << "  Semester Information \n";
                                            }
                                            if (option == 2) {
                                                cout << "> Create Semester. \n";
                                            }
                                            else {
                                                cout << "  Create Semester. \n";
                                            }
                                            if (option == 3) {
                                                cout << "> Add Courses. \n";
                                            }
                                            else {
                                                cout << "  Add Courses. \n";
                                            }
                                            if (option == 4) {
                                                cout << "> List Of Courses. \n";
                                            }
                                            else {
                                                cout << "  List Of Courses. \n";
                                            }
                                            if (option == 5) {
                                                cout << "> Semester Summary. \n\n";
                                            }
                                            else {
                                                cout << "  Semester Summary. \n\n";
                                            }
                                            if (option == 6) {
                                                cout << "> Back! \n";
                                            }
                                            else {
                                                cout << "  Back!\n";
                                            }
                                            char c = _getch();
                                            if (c == 72) {
                                                if (option > 1) {
                                                    option--;
                                                }
                                                else {
                                                    option = 6;
                                                }
                                            }
                                            else if (c == 80) {
                                                if (option < 6) {
                                                    option++;
                                                }
                                                else {
                                                    option = 1;
                                                }
                                            }
                                            else if (c == '\r') {
                                                Semester currentSemester;
                                                if (option == 1) {
                                                    system("cls");
                                                    infoSemester(currentSemester);
                                                    char a = _getch();
                                                    if (a == ESC)
                                                        goto managecourse;
                                                }
                                                else if (option == 2) {
                                                    system("cls");
                                                    createSemester(currentSemester);
                                                    char a = _getch();
                                                    if (a == ESC)
                                                        goto managecourse;
                                                }
                                                else if (option == 3) {
                                                    system("cls");
                                                    // add course
                                                    option = 1;
                                                    while (true) {
                                                    addcourse:
                                                        system("cls");
                                                        if (option == 1) {
                                                            cout << "> Input Courses Data. \n";
                                                        }
                                                        else {
                                                            cout << "  Input Courses Data. \n";
                                                        }
                                                        if (option == 2) {
                                                            cout << "> Import Courses Data File. \n\n";
                                                        }
                                                        else {
                                                            cout << "  Import Courses Data File. \n\n";
                                                        }
                                                        if (option == 3) {
                                                            cout << "> Back! \n";
                                                        }
                                                        else {
                                                            cout << "  Back!\n";
                                                        }
                                                        char c = _getch();
                                                        if (c == 72) {
                                                            if (option > 1) {
                                                                option--;
                                                            }
                                                            else {
                                                                option = 3;
                                                            }
                                                        }
                                                        else if (c == 80) {
                                                            if (option < 3) {
                                                                option++;
                                                            }
                                                            else {
                                                                option = 1;
                                                            }
                                                        }
                                                        else if (c == '\r') {
                                                            if (option == 1) {
                                                                system("cls");
                                                                inputCoursesData();
                                                                char a = _getch();
                                                                if (a == ESC)
                                                                    goto addcourse;
                                                            }
                                                            else if (option == 2) {
                                                                system("cls");
                                                                // input data bang file
                                                                importCoursesData();
                                                                char a = _getch();
                                                                if (a == ESC)
                                                                    goto addcourse;
                                                            }
                                                            else if (option == 3) {
                                                                option = 1;
                                                                goto managecourse;
                                                            }
                                                        }
                                                    }
                                                    // add course
                                                }
                                                else if (option == 4) {
                                                    system("cls");
                                                    // list of courses
                                                    ifstream r;
                                                    r.open("C:/Users/Administrator/Documents/Data/Courses/course.csv");
                                                    if (r.is_open()) {
                                                        cout << setfill(' ') << setw(5) << left << "No" << "| "
                                                            << setfill(' ') << setw(10) << left << "Course ID" << "| "
                                                            << setfill(' ') << setw(30) << left << "Course name" << "| "
                                                            << setfill(' ') << setw(20) << left << "Teacher Name" << "| "
                                                            << setfill(' ') << setw(10) << left << "Credits" << "| "
                                                            << setfill(' ') << setw(10) << left << "Academic" << "| "
                                                            << setfill(' ') << setw(20) << left << "Number of students" << "| "
                                                            << setfill(' ') << setw(10) << left << "Weekday" << "| "
                                                            << setfill(' ') << setw(10) << left << "Session" << endl;
                                                        int no = 1;
                                                        while (no <= 14) {
                                                            Course cour;
                                                            cour = doc_1_course(r);
                                                            ouputcourse_console(cour, no);
                                                            no++;
                                                        }
                                                    }
                                                    else
                                                        cout << "Empty!" << endl;
                                                    //
                                                    char a = _getch();
                                                    if (a == ESC)
                                                        goto managecourse;
                                                }
                                                else if (option == 5) {
                                                    system("cls");
                                                    // summary

                                                    char a = _getch();
                                                    if (a == ESC)
                                                        goto managecourse;
                                                }
                                                else if (option == 6) {
                                                    option = 1;
                                                    goto second;
                                                }
                                            }
                                        }
                                        // managecourses
                                        char a = _getch();
                                        if (a == ESC)
                                            goto second;
                                    }
                                    else if (option == 4) {
                                        changepasswork();
                                        char a = _getch();
                                        if (a == ESC)
                                            goto second;
                                    }
                                    else if (option == 5)
                                        goto first;
                                }
                            }
                        }
                        if (option == 2) {
                            goto first;
                        }
                    }
                }
            }
            else if (option == 2) {
                login();
                option = 1;
                while (true) {
                    system("cls");
                    if (option == 1) {
                        cout << "> Log in.\n";
                    }
                    else {
                        cout << "  Log in.\n";
                    }
                    if (option == 2) {
                        cout << "> EXIT !\n";
                    }
                    else {
                        cout << "  EXIT ! \n";
                    }
                    char c = _getch();
                    if (c == 72) { // Nút mui tên lên
                        if (option > 1) {
                            option--;
                        }
                        else {
                            option = 2;
                        }
                    }
                    else if (c == 80) { // Nút mui tên xu?ng
                        if (option < 2) {
                            option++;
                        }
                        else {
                            option = 1;
                        }
                    }
                    else if (c == '\r') { // Nút Enter
                        if (option == 1) {
                            option = 1;
                            while (true) {
                            third:
                                system("cls");
                                cout << "Choose function: \n";
                                if (option == 1) {
                                    cout << "> Profile. \n";
                                }
                                else {
                                    cout << "  Profile.\n";
                                }
                                if (option == 2) {
                                    cout << "> Courses registration.\n";
                                }
                                else {
                                    cout << "  Courses registration.\n";
                                }
                                if (option == 3) {
                                    cout << "> Scoreboard. \n";
                                }
                                else {
                                    cout << "  Scoreboard.\n";
                                }
                                if (option == 4) {
                                    cout << "> List of classes. \n";
                                }
                                else {
                                    cout << "  List of classes.\n";
                                }
                                if (option == 5) {
                                    cout << "> List of courses. \n\n";
                                }
                                else {
                                    cout << "  List of courses. \n\n";
                                }
                                if (option == 6) {
                                    cout << "> Back! \n";
                                }
                                else {
                                    cout << "  Back!\n";
                                }
                                char c = _getch();
                                if (c == 72) {
                                    if (option > 1) {
                                        option--;
                                    }
                                    else {
                                        option = 6;
                                    }
                                }
                                else if (c == 80) {
                                    if (option < 6) {
                                        option++;
                                    }
                                    else {
                                        option = 1;
                                    }
                                }
                                else if (c == '\r') {
                                    system("cls");
                                    if (option == 1) {
                                        ifstream r;
                                        nodeuser dataUser = NULL;
                                        string fileclass = "C:/Users/Administrator/Documents/Data/Datauser.csv";
                                        doc_danhsach_thongtin_sinhvien(r, dataUser, fileclass);
                                        profile(dataUser);
                                        c = _getch();
                                        if (c == ESC)
                                            goto third;
                                    }
                                    else if (option == 2) {
                                        cout << "Dang ki hoc phan" << endl;
                                        c = _getch();
                                        if (c == ESC)
                                            goto third;
                                    }
                                    else if (option == 3) {
                                        cout << "Bang diem" << endl;
                                        c = _getch();
                                        if (c == ESC)
                                            goto third;
                                    }
                                    else if (option == 6) {
                                        goto first;
                                    }
                                }
                            }
                        }
                        else if (option == 2) {
                            goto first;
                        }
                    }
                }
            }
        }
    }
}
int main() {
    chon();
    return 0;
}