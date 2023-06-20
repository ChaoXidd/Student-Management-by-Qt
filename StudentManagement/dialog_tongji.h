#ifndef DIALOG_TONGJI_H
#define DIALOG_TONGJI_H

#include <QDialog>

namespace Ui {
class Dialog_tongji;
}

class Dialog_tongji : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_tongji(QWidget *parent = nullptr);
    ~Dialog_tongji();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_tongji *ui;
};

#endif // DIALOG_TONGJI_H
