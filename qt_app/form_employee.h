#ifndef FORM_EMPLOYEE_H
#define FORM_EMPLOYEE_H

#include <QDialog>
#include "database.h"

namespace Ui {
class Form_Employee;
}

class Form_Employee : public QDialog
{
    Q_OBJECT
public:
    explicit Form_Employee(QWidget *parent = nullptr);
    database myDB;
    ~Form_Employee();
public slots:
    void on_show();
private slots:
    void on_add_employee_clicked();

private:
    Ui::Form_Employee *ui;
};

#endif // FORM_EMPLOYEE_H
