#ifndef FORM_CUSTOMER_H
#define FORM_CUSTOMER_H

#define ADD    0
#define DELETE 1
#define UPDATE 2

#include <QKeyEvent>
#include <QDialog>
#include "database.h"

namespace Ui {
class Form_Customer;
}

class Form_Customer : public QDialog{
    Q_OBJECT
public:
    explicit Form_Customer(QWidget *parent = nullptr);
    ~Form_Customer();
    database myDB;
    int mode = 0;
public slots:
    void on_show();
private slots:
    void on_process_customer_record_clicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Form_Customer *ui;
    QSqlQuery qr;
    QString employeeNo;
    int recordOnScreen = 1;
    QString get_mode(int m);
    void populate_window();
    void clear_form();
    void refresh_query();
    void fill_employees();
    void keyPressEvent(QKeyEvent * e);
};

#endif // FORM_CUSTOMER_H
