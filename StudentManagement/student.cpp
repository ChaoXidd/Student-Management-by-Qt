#include<student.h>
#include<string>
using namespace std;
#pragma execution_character_set("utf-8")
student::student()
{
    m_id="0";
    m_name="0";
    m_math=0;
    m_eng=0;
    m_phy=0;
}
student::student(string id,string name="0", int math=0, int eng=0,int phy=0)
{
    m_id=id;
    m_name=name;
    m_math=math;
    m_eng=eng;
    m_phy=phy;
}
student::student(const student & s){
    m_id=s.m_id;
    m_name=s.m_name;
    m_math=s.m_math;
    m_eng=s.m_eng;
    m_phy=s.m_phy;
}
string student::getId(){
    return m_id;
}
string student::getName(){
    return m_name;
}
int student::getMath(){
    return m_math;
}
int  student::getEng(){
    return m_eng;
}
int  student::getPhy(){
    return m_phy;
}
int student::total(){
    return (getMath()+getEng()+getPhy());
}
student student::operator =(const student & s){
    m_id=s.m_id;
    m_name=s.m_name;
    m_math=s.m_math;
    m_eng=s.m_eng;
    m_phy=s.m_phy;
    return *this;
}

student::~student()
{

}







