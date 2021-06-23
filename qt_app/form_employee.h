#ifndef FORM_EMPLOYEE_H
#define FORM_EMPLOYEE_H

#define ADD    0
#define DELETE 1
#define UPDATE 2

#include <QKeyEvent>
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
    int mode = 0;
public slots:
    void on_show();
private slots:
    void on_add_employee_clicked();
    void on_process_employee_record_clicked();

private:
    Ui::Form_Employee *ui;
    QSqlQuery qr;
    int recordOnScreen = 1;
    QString get_mode(int m);
    void populate_window();
    void clear_form();
    void refresh_query();
    void keyPressEvent(QKeyEvent * e);
};

#endif // FORM_EMPLOYEE_H
