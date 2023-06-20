#ifndef DIALOG_CHANGE2_H
#define DIALOG_CHANGE2_H

#include <QDialog>
#include<string>
using namespace std;

namespace Ui {
class Dialog_Change2;
}

class Dialog_Change2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Change2(QWidget *parent = nullptr);
    ~Dialog_Change2();

    void receiveData(int id);
    void updateText();
    int m_id;


private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Change2 *ui;
};

#endif // DIALOG_CHANGE2_H
