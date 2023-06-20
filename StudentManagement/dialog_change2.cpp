#include "dialog_change2.h"
#include "ui_dialog_change2.h"
#include"management.h"

QString s2q_(const string &s)
 {
  return QString::fromLocal8Bit(s.data());
 }
string q2s_(const QString qstr)
{
   QByteArray cdata=qstr.toLocal8Bit();
   return string(cdata);
}




Dialog_Change2::Dialog_Change2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Change2)
{
    ui->setupUi(this);


}

Dialog_Change2::~Dialog_Change2()
{
    delete ui;
}


void Dialog_Change2::receiveData(int id)
{
    m_id=id;
    //qDebug()<<id;
}



void Dialog_Change2::on_pushButton_clicked()
{
    management me;
    vector<student>v=me.itxt();
    //qDebug()<<m_id;
    ui->textEdit->clear();
    ui->textEdit->insertPlainText("修改成功！！！");
    student temp(ui->ID->text().toStdString(),q2s_(ui->Name->text()),ui->Math->text().toInt(),ui->Eng->text().toInt(),ui->Phy->text().toInt());
    v[m_id]=temp;
    me.stu=v;
    me.otxt();


}

void Dialog_Change2::updateText()
{
    ui->textEdit->clear();
    management me2;
    vector<student>v1=me2.itxt();
    QString a,b,c,d,e,o;
    a=s2q_(v1[m_id].getId());
    b=s2q_(v1[m_id].getName());
    c=QString::number(v1[m_id].getMath(),10);
    d=QString::number(v1[m_id].getEng(),10);
    e=QString::number(v1[m_id].getPhy(),10);
    o=a+"      "+b+"      "+c+"      "+d+"       "+e+'\n';
    ui->textEdit->insertPlainText(o);

    ui->ID->setText(a);
    ui->Name->setText(b);
    ui->Math->setText(c);
    ui->Eng->setText(d);
    ui->Phy->setText(e);

}

