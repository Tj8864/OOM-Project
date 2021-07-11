#include"main.hpp"
//using namespace comp;

void display(student s){
    cout << "Name: " << s.get_name() << endl;
    date a = s.getDOB(), b=s.getDOJ();
    cout << "Year of study: " << s.get_year() << endl;
    cout << "DOB: "<<a.day<<"/"<<a.month<<"/"<<a.year<<endl;
    cout << "DOJ: "<<b.day<<"/"<<b.month<<"/"<<b.year<<endl;
    cout << "Enrollment: " << s.get_enrollment() << endl;
    cout << "Grade: " << s.get_grade() << endl;
    auto opt = s.get_opt();
    cout << "Phone Number: " << opt.phone_number << endl;
    cout << "Blood Group: " << opt.blood_group << endl;
    cout << "Address: "<<opt.address << endl << endl << endl;
}

void displayAll(vector<student>& v, string mode = ""){
    if(mode == "DOB_ASC") DOB_sort(v);
    else if(mode == "DOB_DSC") DOBrev_sort(v);
    else if(mode == "NAME_ASC") alpha_sort(v);
    else if(mode == "NAME_DSC") alpharev_sort(v);
    else if(mode == "DOJ_ASC") DOJ_sort(v);
    else if(mode == "DOJ_DSC") DOJrev_sort(v);
    else if(mode == "ENROLL_ASC") enroll_sort(v);
    else if(mode == "ENROLL_DSC") enrollrev_sort(v);
    else return void(cout << "Invalid Input.\n");
    for(student s:v){
        display(s);
    }
}

void interface(){
    string mode;
    auto s_list = d.get_student_list();
    cout << "How would you like to arrange the student list?\n";
    cout << "Kindly give input in the format A_B, where: \n";
    cout <<"A can be : DOB, NAME, DOJ, ENROLL. \n";
    cout <<"B can be : ASC (Ascending Order) or DSC (Descending Order).\n\n";
    cout << "Your Input: ";
    cin >> mode;
    cout << endl;
    if(mode == "YEAR"){
        int year;
        cout << "Enter year: ";
        cin >> year;
        showBy(s_list,year);
    }
    else if(mode == "RANGE_DOB"){
        date from, to;
        cout << "Enter dates from and to: ";
        cin >> from.day >> from.month >> from.year;
        cin >> to.day >> to.month >> to.year;
        showBy(s_list, "DOB", from, to);
    }
    else if(mode == "RANGE_DOJ"){
        date from, to;
        cout << "Enter dates from and to: ";
        cin >> from.day >> from.month >> from.year;
        cin >> to.day >> to.month >> to.year;
        showBy(s_list, "DOJ", from, to);
    }
    else displayAll(s_list, mode);
}

void showBy(vector<student>& v, string type, date a, date b){
    if(type == "DOB") {
        DOB_sort(v);
        for(auto st:v){
            if(a <= st.getDOB()  and st.getDOB() <= b) display(st);
        }
    }

    else if(type == "DOJ"){
        DOJ_sort(v);
        for(auto st:v){
            if(a <= st.getDOJ() and st.getDOJ() <= b) display(st);
        }
    }
}

void showBy(vector<student> &v, int year){
    alpha_sort(v);
    for(auto st:v){
        if(st.get_year() == year) display(st);
    }
}