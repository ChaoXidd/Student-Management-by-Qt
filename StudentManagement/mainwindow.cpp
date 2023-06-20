#pragma execution_character_set("utf-8")

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<student.h>
#include<QDebug>
#include"management.h"
#include"dialog_change.h"
#include"dialog_tongji.h"
#include<QBarSet>
#include<QBarSeries>
#include<QBarCategoryAxis>
#include<QTableWidget>
using namespace std;


management me;
vector<student>v=me.itxt();
QString s2q(const string &s)
 {
  return QString::fromLocal8Bit(s.data());
 }
string q2s(const QString qstr)
{
   QByteArray cdata=qstr.toLocal8Bit();
   return string(cdata);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->textEdit->setText("                    欢迎进入学生成绩管理系统！");



    //双击表格修改学生成绩

    //信号和槽mainwindow传出学生id



    void(Dialog_Change2::*a)(int)=&Dialog_Change2::receiveData;
    void(MainWindow::*b)(int)=&MainWindow::sendData;
    connect(this,b,dialog,a);



    connect(ui->textEdit,&QTableWidget::cellDoubleClicked,[=](){
        //1.创建新dialog类
        //2.自定义信号和槽传递数据
        //3.在新dialog中实现修改学生成绩
        //qDebug()<<ui->textEdit->currentColumn()<<ui->textEdit->currentRow();
        emit sendData(ui->textEdit->currentRow());

        dialog->updateText();
        dialog->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ok_clicked()
{
    ui->textEdit->clear();
    student temp(ui->ID->text().toStdString(),q2s(ui->xingming->text()),ui->shuxue->text().toInt(),ui->yingyu->text().toInt(),ui->wuli->text().toInt());
    v.push_back(temp);
    QString a,b,c,d,e,o;
    a=s2q(temp.getId());
    b=ui->xingming->text();
    //cout<<q2s(ui->xingming->text())<<endl;未乱码      toStdString为乱码原因
    //qDebug()<<b;  //未乱码
    //cout<<ui->xingming->text().toStdString()<<endl;   //乱码，原因大概为toStdString()

//    c=QString::number(temp.getMath(),10);
//    d=QString::number(temp.getEng(),10);
//    e=QString::number(temp.getPhy(),10);
//    o=a+"      "+b+"      "+c+"      "+d+"       "+e+'\n';
//    ui->textEdit->insertPlainText(o);
//    ui->textEdit->insertPlainText("添加成功！");
    me.stu=v;
    me.otxt();
    on_pushButton_clicked();

}


void MainWindow::on_pushButton_clicked()
{
    //ui->textEdit->insertPlainText("ID:                     姓名：    数学：   英语：    物理：");
    QString a,b,c,d,e,o;
    student s;
//    for(int i=0;i<v.size();i++)
//    {
//        s=v[i];
//        a=s2q(s.getId());
//        b=s2q(s.getName());
//        //cout<<s.getName()<<endl;            //乱码
//        //cout<<s.m_name<<endl;           //乱码，student成员内已乱码
//        c=QString::number(s.getMath(),10);
//        d=QString::number(s.getEng(),10);
//        e=QString::number(s.getPhy(),10);
//        o=a+"      "+b+"      "+c+"      "+d+"      "+e+'\n';
//        //ui->textEdit->insertPlainText(o);
//    ui->textEdit->clear();





    //设置不可编辑
    ui->textEdit->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->textEdit->clear();
    ui->textEdit->setColumnCount(5);
    ui->textEdit->setHorizontalHeaderLabels(QStringList()<<"ID:                     "<<"姓名：    "<<"数学：   "<<"英语：    "<<"物理：");
    ui->textEdit->setRowCount(v.size());
    for(int i=0;i<v.size();i++)
    {
        s=v[i];
        a=s2q(s.getId());
        b=s2q(s.getName());
        c=QString::number(s.getMath(),10);
        d=QString::number(s.getEng(),10);
        e=QString::number(s.getPhy(),10);
        int col=0;
        ui->textEdit->setItem(i,col++,new QTableWidgetItem(a));
        ui->textEdit->setItem(i,col++,new QTableWidgetItem(b));
        ui->textEdit->setItem(i,col++,new QTableWidgetItem(c));
        ui->textEdit->setItem(i,col++,new QTableWidgetItem(d));
        ui->textEdit->setItem(i,col++,new QTableWidgetItem(e));
    }







}


void MainWindow::on_ok_2_clicked()
{
   QString qst=ui->delete_2->text();
   string st=qst.toStdString();
    v=me.deletetxt(st);
    me.stu=v;
    me.otxt();
   ui->delete_2->clear();

}


void MainWindow::on_pushButton_2_clicked()
{
   Dialog_change * dialog1=new Dialog_change(this);
   dialog1->setWindowTitle(tr("修改学生数据"));
   if(dialog1->exec()==QDialog::Rejected) return;
}

void MainWindow::on_ss_clicked()
{
    student s;
    s=me.findtxt(ui->sousuo->text().toStdString());
    cout<<ui->sousuo->text().toStdString()<<endl;
    //ui->textEdit->clear();
    //ui->textEdit->insertPlainText("ID:                     姓名：    数学：   英语：    物理：");
    QString a,b,c,d,e,o;
    a=s2q(s.getId());
    b=s2q(s.getName());
    c=QString::number(s.getMath(),10);
    d=QString::number(s.getEng(),10);
    e=QString::number(s.getPhy(),10);
    o=a+"      "+b+"      "+c+"      "+d+"      "+e+'\n';
    //ui->textEdit->insertPlainText(o);
    QWidget *widget=new QWidget;
    widget->resize(331,461);
    QTextEdit *text=new QTextEdit(widget);
    text->resize(331,461);
    text->insertPlainText("ID:                     姓名：    数学：   英语：    物理：");
    text->insertPlainText(o);
    widget->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    Dialog_tongji * dialog3 = new Dialog_tongji(this);
     dialog3->setWindowTitle(tr("统计信息"));
     if(dialog3->exec()==QDialog::Rejected) return;
}


void MainWindow::on_pushButton_4_clicked()
{
    vector<student>v1=me.ptxt();

    //on_pushButton_clicked();
    //QDialog *dialog1=new QDialog;
    QTableWidget  * text=new QTableWidget;
    QString a,b,c,d,e,o;
    student s;




    //设置不可编辑
    text->setEditTriggers(QAbstractItemView::NoEditTriggers);
    text->clear();
    text->setColumnCount(5);
    text->setHorizontalHeaderLabels(QStringList()<<"ID:                     "<<"姓名：    "<<"数学：   "<<"英语：    "<<"物理：");
    text->setRowCount(v1.size());
    for(int i=0;i<v1.size();i++)
    {
        s=v1[i];
        a=s2q(s.getId());
        b=s2q(s.getName());
        c=QString::number(s.getMath(),10);
        d=QString::number(s.getEng(),10);
        e=QString::number(s.getPhy(),10);
        int col=0;
        text->setItem(i,col++,new QTableWidgetItem(a));
        text->setItem(i,col++,new QTableWidgetItem(b));
        text->setItem(i,col++,new QTableWidgetItem(c));
        text->setItem(i,col++,new QTableWidgetItem(d));
        text->setItem(i,col++,new QTableWidgetItem(e));
    }
    text->resize(700,700);
    text->show();

}


void MainWindow::on_chartBtn_clicked()
{
    CreateChartFunc();
    chartView->show();
}

void MainWindow::CreateChartFunc()
{
//    //创建图表
//    chartView=new QChartView;
//    chart=new QChart();
//    chart->setTitle("sin/cos图表");
//    chartView->setChart(chart);//chart添加到chartView


//    //创建曲线序列
//    QLineSeries *series1=new QLineSeries();
//    QLineSeries *series2=new QLineSeries();
//    series1->setName("sin");
//    series2->setName("cos");
//    chart->addSeries(series1);
//    chart->addSeries(series2);

//    //通过序列添加数据
//    qreal t=0,y1,y2=0.1;
//    qreal intv=0.1;
//    int icount=100;
//    for(int i=0;i<icount;i++)
//    {
//        y1=qSin(t);
//        series1->append(t,y1);

//        y2=qSin(t+20);
//        series2->append(t,y2);

//        t=t+intv;
//    }
//    //创建坐标轴
//    QValueAxis *axisX=new QValueAxis;
//    axisX->setRange(0,10);//设置范围
//    axisX->setTitleText("X");//标题

//    QValueAxis *axisY=new QValueAxis;
//    axisY->setRange(-2,2);//设置范围
//    axisY->setTitleText("Y");//标题

//    chart->setAxisX(axisX,series1);
//    chart->setAxisY(axisY,series1);

//    chart->setAxisX(axisX,series2);
//    chart->setAxisY(axisY,series2);

    //统计数学分数0-80,80-90,90-100人数
    int p1 = 0,p2=0,p3=0;
    int m1=0,m2=0,m3=0;
    int k1=0,k2=0,k3=0;
    for(int i=0;i<v.size();i++)
    {

        if(v[i].getMath()<80)
        {
            p1++;
        }
        else if(v[i].getMath()>=80&&v[i].getMath()<90)
        {
            p2++;
        }
        else
        {
            p3++;
        }

    }
    for(int j=0;j<v.size();j++)
    {

        if(v[j].getEng()<80)
        {
            m1++;
        }
        else if(v[j].getEng()>=80&&v[j].getEng()<90)
        {
            m2++;
        }
        else
        {
            m3++;
        }
    }
    for(int k=0;k<v.size();k++)
    {

        if(v[k].getPhy()<80)
        {
            k1++;
        }
        else if(v[k].getPhy()>=80&&v[k].getPhy()<90)
        {
            k2++;
        }
        else
        {
            k3++;
        }
    }
     qDebug()<<p1<<" "<<p2<<" "<<p3;
     qDebug()<<m1<<" "<<m2<<" "<<m3;
     qDebug()<<k1<<" "<<k2<<" "<<k3;


     QBarSet *set0=new QBarSet("数学");
     QBarSet *set1=new QBarSet("英语");
     QBarSet *set2=new QBarSet("物理");

     *set0<<p1<<p2<<p3;
     *set1<<m1<<m2<<m3;
     *set2<<k1<<k2<<k3;

     QBarSeries *series=new QBarSeries();
     series->append(set0);
     series->append(set1);
     series->append(set2);

     //设置标签显示位置
     series->setLabelsPosition(QAbstractBarSeries::LabelsPosition::LabelsCenter);
     // 显示标签
     series->setLabelsVisible(true);

     chartView=new QChartView;
     chart=new QChart();
     chart->addSeries(series);
     chart->setTitle("条形统计图");
     chartView->setChart(chart);


     QStringList categories;
     categories<< "0~80" <<" 80~90" << "90~100" ;
     QBarCategoryAxis *axis=new QBarCategoryAxis();
     axis->append(categories);
     axis->setTitleText("分数段");

     chart->setAxisX(axis,series);
     //chart->createDefaultAxes();
     QValueAxis *axisY=new QValueAxis;
     axisY->setRange(0,20);//设置范围
     axisY->setTitleText("人数");//标题
     chart->setAxisY(axisY,series);

     chartView->resize(500,500);
     chartView->show();
}








void MainWindow::on_pieChartBtn_clicked()
{
    //饼状图
    //数学中各个分数段人数占比
    int i=0;
    double a0_60=0,a60_70=0,a70_80=0,a80_90=0,a90_100=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i].getMath()<60)
        {
            a0_60++;
        }
        else if(v[i].getMath()>=60&&v[i].getMath()<70)
        {
            a60_70++;
        }
        else if(v[i].getMath()>=60&&v[i].getMath()<70)
        {
            a60_70++;
        }
        else if(v[i].getMath()>=70&&v[i].getMath()<80)
        {
            a70_80++;
        }
        else if(v[i].getMath()>=80&&v[i].getMath()<90)
        {
            a80_90++;
        }
        else
        {
            a90_100++;
        }
    }

    //qDebug()<<a0_60<<a60_70<<a70_80<< a80_90<<a90_100;

    QPieSeries *pie_series=new QPieSeries();
    pie_series->append("0~60: "+QString::number(a0_60), a0_60)->setColor(QColor(0, 200, 200));	    // 构造饼状分区
    pie_series->append("60~70: "+QString::number(a60_70), a60_70)->setColor(QColor(0, 0, 255));     //设置每个分区的占比与颜色
    pie_series->append("70~80: "+QString::number(a70_80),a70_80)->setColor(QColor(0,150,0));
    pie_series->append("80~90: "+QString::number(a80_90),a80_90)->setColor(QColor(0,255,0));
    pie_series->append("90~100: "+QString::number(a90_100),a90_100)->setColor(QColor(255,0,0));
    pie_series->setLabelsVisible();

    QChart* chart = new QChart;
    chart->setTitle("数学成绩分布饼状图");
    chart->setTheme(QChart::ChartThemeDark);
    //加入扇形
    chart->addSeries(pie_series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setBackgroundVisible(false);

    QChartView* chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setChart(chart);
    chartView->resize(500,500);
    chartView->show();


}

void MainWindow::onPieSeriesClicked(QPieSlice* slice)
{
    slice->setExploded(!slice->isExploded());
}
