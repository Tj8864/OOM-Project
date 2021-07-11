#include"main.hpp"
vector<student>::iterator data::get_student(string s){
    int high = student_list.size()-1;
    int low = 0;
    int mid;
    while(high >= low){
        mid = (high+low)/2;
        string name = student_list[mid].get_name();
        if(name == s) return student_list.begin()+mid;
        else if(name > s) high = mid-1;
        else low = mid+1;
    }
    return student_list.end();
}
data::data(){
    ifstream in;
    in.open("database.txt", ios::app);
    in.seekg(0);
    string fname,lname,enroll,grade;
    int yos;
    date a(0,0,0), b(0,0,0);
    long long phone;
    string address;
    string bg;
    while(!in.eof()){
        in >> fname >> lname >> enroll >> grade >> yos;
        in >> a.day >> a.month >> a.year >> b.day >> b.month >> b.year;
        in >> phone;
        in >> bg;
        in >> address;//getline(in, address);
        student_list.push_back(student(fname,lname,enroll, grade, yos, a, b, stud_details(phone, bg, address)));
    }
}
vector<student> data::get_student_list(){
    auto x = student_list;
    return x;
}