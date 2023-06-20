#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class student
{
public:
    student();
    student(string,string,int,int,int);
    student(const student&);
    ~student();
    string getId();
    string getName();
    int getMath();
    int getEng();
    int getPhy();
    int total();
    student operator=(const  student &);
    string m_name;
private:
    string m_id;
    int m_math, m_eng, m_phy;



};

#endif // STUDENT_H
