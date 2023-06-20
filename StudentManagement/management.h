#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "student.h"
#include"QString"
#include<QFileDialog>
#include<QFile>
#include<qtextstream.h>
class management{
public:
    management();
    vector<student> deletetxt(const string& m);
    student findtxt(const string& m);
    vector<student> itxt();
    vector<student> getstu(){return stu;}
    vector<double> ttxt(vector<double>);
    vector<student> ptxt();
    void otxt();
    //void show();

    vector<student>stu;
};

#endif // MANAGEMENT_H
