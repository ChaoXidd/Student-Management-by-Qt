#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCharts>
#include"dialog_change2.h"

#include<QString>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onPieSeriesClicked(QPieSlice*);//点击扇形

    Dialog_Change2 *dialog=new Dialog_Change2;




private slots:
    void on_ok_clicked();

    void on_pushButton_clicked();

    void on_ok_2_clicked();

    void on_pushButton_2_clicked();


    void on_ss_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_chartBtn_clicked();

    void on_pieChartBtn_clicked();

signals:
    void sendData(int id);


private:
    Ui::MainWindow *ui;
    void CreateChartFunc();
    QChartView * chartView;
    QChart*chart;
};
#endif // MAINWINDOW_H
