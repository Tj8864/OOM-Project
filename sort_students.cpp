#include "main.hpp"

bool alpha_cmp(student a, student b)
{
    return a.get_name() < b.get_name();
}
bool DOB_cmp(student a, student b)
{
    return a.getDOB() < b.getDOB();
}
bool DOJ_cmp(student a, student b)
{
    return a.getDOJ() < b.getDOJ();
}
bool enrollment_cmp(student a, student b)
{
    if(a.get_year() == b.get_year())return a.get_enrollment() < b.get_enrollment();
    else return a.get_year() < b.get_year();
}
bool alpha_cmp_rev(student a, student b)
{
    return b.get_name() < a.get_name();
}
bool DOB_cmp_rev(student a, student b)
{
    return b.getDOB() < a.getDOB();
}
bool DOJ_cmp_rev(student a, student b)
{
    return b.getDOJ() < a.getDOJ();
}
bool enrollment_cmp_rev(student a, student b)
{
    return !enrollment_cmp(a,b);
}
bool year_cmp(student a, student b)
{
    if (a.get_year() == b.get_year())
        return a.get_name() < b.get_name();
    else
        return a.get_year() < b.get_year();
}
void alpha_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), alpha_cmp);
}
void DOB_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), DOB_cmp);
}
void DOJ_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), DOJ_cmp);
}
void enroll_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), enrollment_cmp);
}
void alpharev_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), alpha_cmp_rev);
}
void DOBrev_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), DOB_cmp_rev);
}
void DOJrev_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), DOJ_cmp_rev);
}
void enrollrev_sort(vector<student> &v)
{
    sort(v.begin(), v.end(), enrollment_cmp_rev);
}
void yearsort(vector<student> &v)
{
    sort(v.begin(), v.end(), year_cmp);
}
