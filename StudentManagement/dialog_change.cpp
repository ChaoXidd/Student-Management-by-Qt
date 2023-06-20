#include "dialog_change.h"
#include "ui_dialog_change.h"
#include"management.h"

Dialog_change::Dialog_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_change)
{
    ui->setupUi(this);
}

Dialog_change::~Dialog_change()
{
    delete ui;
}

void Dialog_change::on_pushButton_clicked()
{
   management me;
   vector<student>v=me.itxt();
   string str;
   student stu;
   QString Q=ui->lineEdit->text();
   str=Q.toStdString();
   //cout<<str<<endl;
   bool flag=0;
   for(int i=0;i<v.size();i++)
   {
       stu=v[i];
       if(str==stu.getId())
       {
           student temp(stu.getId(),stu.getName(),ui->lineEdit_2->text().toInt(),ui->lineEdit_3->text().toInt(),ui->lineEdit_4->text().toInt());
           v[i]=temp;
           flag=1;
           ui->textEdit->insertPlainText("修改成功");
           break;
       }
   }
   if(flag==0)
   {

           ui->textEdit->insertPlainText("修改失败");

   }
     me.stu=v;
     me.otxt();
}

