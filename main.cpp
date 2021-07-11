#include <bits/stdc++.h>
using namespace std;
#include "main.hpp"

data d;

int main()
{
    // auto s_list = d.get_student_list();
    // displayAll(s_list, "DOB_ASC");
    cout << "Welcome to College Databse Managemet System!\n\n";
    cout << "Input Codes: \n";
    cout << "0. To Exit.\n";
    cout << "1. Sort and Filter the database.\n";
    cout << "2. Enter the ADMIN Portal.\n";
    cout << "3. Clear screen.\n";
    cout << "############################################\n";
    cout << "\nYour input: ";

    int ch = 1;
    string dummy = "";
    while (ch != 0)
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
            interface();
            break;
        case 2:
            admin_portal();
            break;
        case 0:
            break;
        default:
            system("clear");
        }
        // system("clear");
        if(ch == 0) break;
        cout << "############################################\n";
        cout << "Input Codes: \n";
        cout << "0. To Exit.\n";
        cout << "1. Sort and Filter the database.\n";
        cout << "2. Enter the ADMIN Portal.\n";
        cout << "3. Clear screen.\n";
        cout << "\nYour input: ";
    }
    return 0;
}