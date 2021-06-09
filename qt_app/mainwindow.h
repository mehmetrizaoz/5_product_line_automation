#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include <QTextEdit>
#include "form_login.h"
#include "form_office.h"
#include "form_employee.h"
#include "form_customer.h"
#include "form_productlines.h"
#include "form_product.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    database myDB;
private slots:
    void get_login_status();
    void on_comboBox_offices_activated(int index);
    void on_comboBox_employees_activated(int index);
    void on_comboBox_customers_activated(int index);
    void on_comboBox_orders_activated(int index);
    void on_comboBox_payments_activated(int index);
    void on_comboBox_products_activated(int index);
    void on_comboBox_productlines_activated(int index);
private:
    Ui::MainWindow    *ui;
    Form_Login        *login;
    Form_Office       *office;
    Form_Employee     *emp;
    Form_Customer     *cus;
    Form_Product      *pro;
    Form_ProductLines *lin;
    QString           fileName;
    QSqlQuery         qr;
};

#endif // MAINWINDOW_H
