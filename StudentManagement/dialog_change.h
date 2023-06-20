#ifndef DIALOG_CHANGE_H
#define DIALOG_CHANGE_H

#include <QDialog>

namespace Ui {
class Dialog_change;
}

class Dialog_change : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_change(QWidget *parent = nullptr);
    ~Dialog_change();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_change *ui;
};

#endif // DIALOG_CHANGE_H
