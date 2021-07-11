#ifndef __main
#define __main

#include<bits/stdc++.h>
using namespace std;

struct date{
    int day,month,year;
    date(int _day, int _month, int _year){
        day = _day;
        month = _month;
        year = _year;
    }
    date(){
    }
    void operator=(date d){
        day = d.day;
        month = d.month;
        year = d.year;
    }
};

bool operator<(date a, date b);
bool operator<=(date a, date b);

struct stud_details{
    long long phone_number;
    string blood_group;
    string address;
    stud_details(){
        phone_number = 0;
        blood_group = "NA";
        address = "NA";
    }
    stud_details(long long ph, string bg, string add){
        phone_number = ph;
        blood_group = bg;
        address = add;
    }
};

class student{
    protected:
        string fname, lname, enrollment, grade;
        date date_of_birth, date_of_joining;
        int year_of_study;
        stud_details optional_details;
        void give_grade(string _grade);
        void add_phone(long long _phone_number);
        void add_bloodg(string _bg);
        void add_address(string _address);
        friend class admin;
    public:
        string get_name();
        string get_enrollment();
        date getDOB();
        date getDOJ();
        stud_details get_opt();
        string get_grade();
        int get_year();
        student(string _fname, string _lname, string _enrollment, string _grade, int _year, date dob, date doj, stud_details opt);
};

class data{
    friend class admin;
    vector<student> student_list;
    vector<student>::iterator get_student(string s);
    public:
    data();
    vector<student> get_student_list();
};
extern data d;

class admin{
    bool active;
    friend class student;
    friend class data;
    public:
        admin(){
            active = false;
        }
        void activate();
        bool status();
        void giveGrade(vector<student>::iterator itr, string curr);
        void add_details(vector<student>::iterator itr, string curr);
        void disp_stud(vector<student>::iterator itr, string curr);
        vector<student>::iterator get_student(string s);
        void add_student(student _st);
        void remove_student(string _name);
        ~admin();
};

void admin_portal();

bool alpha_cmp(student a, student b);
bool DOB_cmp(student a, student b);
bool DOJ_cmp(student a, student b);
bool enrollment_cmp(student a, student b);
bool alpha_cmp_rev(student a, student b);
bool DOB_cmp_rev(student a, student b);
bool DOJ_cmp_rev(student a, student b);
bool enrollment_cmp_rev(student a, student b);
bool year_cm(student a, student b);
void alpha_sort(vector<student>& v);
void DOB_sort(vector<student>& v);
void DOJ_sort(vector<student>& v);
void enroll_sort(vector<student>& v);
void alpharev_sort(vector<student>& v);
void DOBrev_sort(vector<student>& v);
void DOJrev_sort(vector<student>& v);
void enrollrev_sort(vector<student>& v);
void yearsort(vector<student>& v);


void displayAll(vector<student> &v, string mode);
void showBy(vector<student> &v, string type, date a, date b);
void showBy(vector<student> &v, int year);
void interface();

#endif