#include "management.h"
#pragma execution_character_set("utf-8")

management::management()
{

}
vector<student> management::itxt(){   //文件写入

    ifstream in("F:\\Qtcode\\StudentManagement\\data.txt");//打开文件
        if (!in) //判断打开文件是否成功
        {

            qDebug() << "文件打开失败";//若打开文件失败直接输出打开文件失败

        }
        else
        {
            qDebug()<<"打开了";
            string id, name;
            int Math, English, Physics;
            while (!in.eof()) //判断文件是否已经读完
            {
                for (int i = 1; i <= 5; i++) //一个完整的数据由5个小数据组成
                {
                    switch (i)
                    {
                    case 1:
                        in >> id;
                        break;
                    case 2:
                        in >> name;
                        break;
                    case 3:
                        in >> Math;
                        break;
                    case 4:
                        in >> English;
                        break;
                    case 5:
                        in >> Physics;
                    default:
                        break;
                    }
                }
                if (!in.eof())
                    stu.push_back(student(id, name, Math, English, Physics));//将读取到的数据存入m_students里面
            }
            in.close();//关闭文件
        }
        return stu;
}

void management::otxt()
{  ofstream fout;
    fout.open("F:\\Qtcode\\StudentManagement\\data.txt", ios::out);//打开文件
    if (!fout) {

       qDebug()<< "文件打开失败";

    }
    else {
        qDebug()<< "文件打开成功";
        int x = stu.size();//读取数据个数
        for (int i = 0; i < x; i++)
        {
            for (int j = 1; j <= 5; j++)//一个数据由五个小数据组成
            {
                switch (j)
                {
                case 1:
                    fout << stu[i].getId();
                    break;
                case 2:
                    fout << stu[i].getName();
                    break;
                case 3:
                    fout <<stu[i].getMath();
                    break;
                case 4:
                    fout <<stu[i].getEng();
                    break;
                case 5:
                    fout <<stu[i].getPhy();
                default:
                    break;
                }
                fout <<"   ";
            }
            fout << endl;
        }
        fout.close();
    }
}


vector<student> management::deletetxt(const string& m)
{    //删除记录
    for(vector<student>::iterator it=stu.begin();it!=stu.end();it++)
    {
        if(it->getId()==m|it->getName()==m)
        {
            stu.erase(it);
        }
    }


    return stu;
}


 student management::findtxt(const string& m)
 {
    student s;
    for(int i=0;i<stu.size();i++)
    {
        if(stu[i].getId()==m)
        {
           s=stu[i];
           break;
        }
    }
    return s;
 }


 vector<double> management::ttxt(vector<double>in)
 {

     itxt();
     in.clear();
     int i,j;
     double sum1(0),sum2(0),sum3(0),p1(0),p2(0),p3(0),v1(0),v2(0),v3(0);
     for(i=0;i<stu.size();i++)
     {
         sum1+=stu[i].getMath();
         sum2+=stu[i].getEng();
         sum3+=stu[i].getPhy();
         if(stu[i].getMath()>=60)  p1++;
         if(stu[i].getEng()>=60)  p2++;
         if(stu[i].getPhy()>=60)  p3++;
     }
     sum1/=i;
     sum2/=i;
     sum3/=i;
     p1/=i;
     p2/=i;
     p3/=i;
     for(j=0;j<stu.size();j++)
     {
         v1+=(stu[i].getMath()-sum1)*(stu[i].getMath()-sum1);
         v2+=(stu[i].getEng()-sum2)*(stu[i].getEng()-sum2);
         v3+=(stu[i].getPhy()-sum3)*(stu[i].getPhy()-sum3);
     }
     v1=sqrt(v1/i);
     v2=sqrt(v2/i);
     v3=sqrt(v3/i);
     in.push_back(sum1);
     in.push_back(sum2);
     in.push_back(sum3);
     in.push_back(p1);
     in.push_back(p2);
     in.push_back(p3);
     in.push_back(v1);
     in.push_back(v2);
     in.push_back(v3);
     qDebug()<<v1;
     return in;
 }
 vector<student> management::ptxt()
 {
     int i,j;
     student t("0","0",0,0,0);
     for(i=1;i<stu.size();i++)
     {
         for(j=i-1;j>=0;j--)
         {
             if(stu[j+1].total()>stu[j].total())
             {
                 t=stu[j];
                 stu[j]=stu[j+1];
                 stu[j+1]=t;
             }
             else if(stu[j+1].total()==stu[j].total())
             {
                 if(stu[j+1].getMath()>stu[j].getMath())
                 {      //比较数学
                     t=stu[j];
                     stu[j]=stu[j+1];
                     stu[j+1]=t;
                 }
                 else if(stu[j+1].getMath()==stu[j].getMath())
                 {    //比较物理
                     if(stu[j+1].getPhy()>stu[j].getPhy())
                     {
                         t=stu[j];
                         stu[j]=stu[j+1];
                         stu[j+1]=t;
                     }
                     else break;
                 }
                 else  break;
             }
             else break;
         }
     }
     return stu;
 }












