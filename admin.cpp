#include "main.hpp"

void admin::activate()
{
    string login, pass;
    cout << "Enter admin login: ";
    cin >> login;
    cout << "Enter admin password: ";
    cin >> pass;
    if (login == "admin" and pass == "Admin$123")
        active = true;
    else
    {
        cout << "Invalid login or Password";
    }
}
bool admin::status()
{
    return active;
}
void admin::giveGrade(vector<student>::iterator itr, string curr)
{
    if (itr->get_name() != curr)
    {
        cout << "No student selected!\n";
        return;
    }
    string grade;
    cout << "Enter grade to give: ";
    cin >> grade;
    itr->give_grade(grade);
}
void admin::add_details(vector<student>::iterator itr, string curr)
{
    if (itr->get_name() != curr)
    {
        cout << "No student selected!\n";
        return;
    }
    cout << "Enter detials (phone, blood group, address)\n";
    cout<<"(Enter unchanged to keep it unchanged/0)" ;
    string addr, bgp;
    long long phn;
    cin >> phn >> bgp;
    getline(cin, addr);
    if (addr != "unchanged")
        itr->add_address(addr);
    if (bgp != "unchanged")
        itr->add_bloodg(bgp);
    if (phn != 0)
        itr->add_phone(phn);
}
void admin::disp_stud(vector<student>::iterator itr, string curr)
{
    if (itr->get_name() != curr)
    {
        cout << "No student selected!\n";
        return;
    }
    auto s = *itr;
    cout << "Name: " << s.get_name() << endl;
    date a = s.getDOB(), b = s.getDOJ();
    cout << "Year of study: " << s.get_year() << endl;
    cout << "DOB: " << a.day << "/" << a.month << "/" << a.year << endl;
    cout << "Date of joining: " << b.day << "/" << b.month << "/" << b.year << endl;
    cout << "Enrollment: " << s.get_enrollment() << endl;
    cout << "Grade: " << s.get_grade() << endl;
    auto opt = s.get_opt();
    cout << "Phone NUmber: " << opt.phone_number << endl;
    cout << "Blood Group: " << opt.blood_group << endl;
    cout << "Address: " << opt.address << endl
         << endl
         << endl;
}
vector<student>::iterator admin::get_student(string s)
{
    return d.get_student(s);
}

void admin::add_student(student _st)
{
    d.student_list.push_back(_st);
    alpha_sort(d.student_list);
}

admin::~admin()
{
    ofstream out;
    out.open("database.txt");
    alpha_sort(d.student_list);
    for (int i = 0; i < d.student_list.size(); i++)
    {
        student s = d.student_list[i];
        out << s.fname << " " << s.lname << " " << s.enrollment << " " << s.grade << " " << s.year_of_study << endl;
        out << s.date_of_birth.day << " " << s.date_of_birth.month << " " << s.date_of_birth.year << " " << s.date_of_joining.day << " " << s.date_of_joining.month << " " << s.date_of_joining.year << endl;
        out << s.optional_details.phone_number << endl;
        out << s.optional_details.blood_group << endl;
        out << s.optional_details.address;
        if (i < d.student_list.size() - 1)
            out << endl;
    }
}

void admin::remove_student(string _name)
{
    auto it = get_student(_name);
    if (it->get_name() != _name)
        return;
    d.student_list.erase(it);
}

void admin_portal()
{

    system("clear");
    cout << "############################################" << endl
         << "Welcome to admin portal" << endl
         << "Please login to continue" << endl
         << "############################################" << endl;
    admin adm;
    string current_student = "DNE";
    vector<student>::iterator itr = adm.get_student("DNE");
    adm.activate();
    int ch = 1;
    while (!adm.status() and ch)
    {
        cout << "\nRetry (1) / Exit(0) : ";
        cin >> ch;
        if (ch)
            adm.activate();
        else
            return void(system("clear"));
    }
    cout << "############################################" << endl;
    cout << "0. Logout and return to home menu." << endl;
    cout << "1. Add grade to current student." << endl;
    cout << "2. Change details of current student." << endl;
    cout << "3. Display information of current student." << endl;
    cout << "4. Select another student." << endl;
    cout << "5. Add new student." << endl;
    cout << "6. Remove a student." << endl;
    cout << "############################################" << endl;
    if (itr == adm.get_student("DNE"))
        cout << "No student selected\n";
    else
        cout << "Current student: " << current_student << endl;
    cout << "############################################" << endl;
    cin >> ch;
    while (ch)
    {
        if (ch == 1)
        {
            adm.giveGrade(itr, current_student);
        }
        if (ch == 2)
        {
            adm.add_details(itr, current_student);
        }
        if (ch == 3)
        {
            adm.disp_stud(itr, current_student);
        }
        if (ch == 4)
        {
            string s, a, b;
            cout << "Enter first name: ";
            cin >> a;
            cout << "Enter last name: ";
            cin >> b;
            s = a + " " + b;
            itr = adm.get_student(s);
            current_student = s;
            system("clear");
            cout << "############################################" << endl;
            cout << "0. Logout and exit" << endl;
            cout << "1. Give grade to current student" << endl;
            cout << "2. Change details of current student" << endl;
            cout << "3. Display information of current student" << endl;
            cout << "4. Select another student" << endl;
            cout << "5. Add new student" << endl;
            cout << "6. Remove a student." << endl;
            cout << "############################################" << endl;
            if (itr == adm.get_student("DNE"))
                cout << "No student selected\n";
            else
                cout << "Current student: " << current_student << endl;
            cout << "############################################" << endl;
        }
        if (ch == 5)
        {
            // cout << "Enter student details in order: " << endl;
            // cout << "fname lname enrollment grade" << endl;
            // cout << "date of birth date of joining" << endl;
            // cout << "phone number" << endl;
            // cout << "blood group" << endl;
            // cout << "address" <<endl;
            string fname, lname, enroll, grade, bg, address;
            int year;
            long long phone;
            date a, b;
            // cin >> fname >> lname >> enroll >> grade >> year;
            // cin >> a.day >> a.month >> a.year >> b.day >> b.month >> b.year;
            // cin >> phone;
            // cin >> bg;
            // cin >> address;

            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";
            cin >> lname;
            cout << "Enrollment Number: ";
            cin >> enroll;
            cout << "Grade: ";
            cin >> grade;
            cout << "Year of Study: ";
            cin >> year;
            cout << "DOB (dd mm yy): ";
            cin >> a.day >> a.month >> a.year;
            cout << "DOJ (dd mm yy): ";
            cin >> b.day >> b.month >> b.year;
            cout << "Contact Number: ";
            cin >> phone;
            cout << "Blood Group: ";
            cin >> bg;
            cout << "Address (seperate words with underscore '_'): ";
            cin >> address;

            student _st(fname, lname, enroll, grade, year, a, b, stud_details(phone, bg, address));
            adm.add_student(_st);

            cout << "\nNew student successfully added to the databse.\n";
             cout << "\nEnter your other choice.\n";
        }
        if (ch == 6)
        {
            string dummy1, dummy2;

            cout << "Enter the name of student you wish to remove.\n";
            cout << "Press 0 to abort.\n";
            cout<<"Enter first name : ";
            cin >> dummy1 ;
            cout<<"Enter second name : ";
            cin>>dummy2;
            string removedFinal = dummy1 + " " + dummy2;

            if (dummy1 != "0")
            {
                adm.remove_student(removedFinal);
                cout<<"Student removed successfully.\n";
            }

            else
            {
                cout << "Process Aborted.\n";
            }
        }
        cin >> ch;
    }
    system("clear");
}
