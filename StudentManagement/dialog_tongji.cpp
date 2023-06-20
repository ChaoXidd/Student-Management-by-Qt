#include "dialog_tongji.h"
#include "ui_dialog_tongji.h"
#include"management.h"
#include"student.h"
#include<vector>


Dialog_tongji::Dialog_tongji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_tongji)
{
    ui->setupUi(this);
}

Dialog_tongji::~Dialog_tongji()
{
    delete ui;
}

void Dialog_tongji::on_pushButton_clicked()
{
    QString qst;
    ui->textEdit->clear();
    management me;     ui->textEdit->insertPlainText("科目依次为数学、英语、物理。");
    ui->textEdit->insertPlainText("    前三个为平均分，中间为及格率，后三个为标准差      ");
    vector<double>in;
    in=me.ttxt(in);
    for(int i=0;i<in.size();i++)
    {
        qst=QString::number(in[i]);
        ui->textEdit->insertPlainText(qst+'\n');
    }

















}

