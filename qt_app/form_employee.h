#ifndef FORM_EMPLOYEE_H
#define FORM_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class Form_Employee;
}

class Form_Employee : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Employee(QWidget *parent = nullptr);
    ~Form_Employee();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form_Employee *ui;
};

#endif // FORM_EMPLOYEE_H
