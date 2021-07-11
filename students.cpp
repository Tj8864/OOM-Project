#include"main.hpp"

bool operator<(date a, date b){
    if(a.year == b.year and a.month == b.month) return a.day < b.day;
    if(a.year == b.year) return a.month < b.month;
    return a.year < b.year;
}

bool operator <=(date a, date b){
    if(a.year == b.year and a.month == b.month) return a.day <= b.day;
    if(a.year == b.year) return a.month < b.month;
    return a.year < b.year;
}

void student::give_grade(string _grade){
    grade = _grade;
}
void student::add_phone(long long _phone_number){
    optional_details.phone_number = _phone_number;
}
void student::add_bloodg(string _bg){
    optional_details.blood_group = _bg;
}
void student::add_address(string _address){
    optional_details.address = _address;
}
string student::get_name(){
    return fname + " " + lname;
}
string student::get_enrollment(){
    return enrollment;
}
date student::getDOB(){
    return date_of_birth;
}
date student::getDOJ(){
    return date_of_joining;
}
stud_details student::get_opt(){
    return optional_details;
}
string student::get_grade(){
    return grade;
}
int student::get_year(){
    return year_of_study;
}
student::student(string _fname, string _lname, string _enrollment, string _grade, int _year, date dob, date doj, stud_details opt){
    fname = _fname;
    lname = _lname;
    enrollment = _enrollment;
    grade = _grade;
    year_of_study = _year;
    date_of_joining = doj;
    date_of_birth = dob;
    optional_details = opt;
}