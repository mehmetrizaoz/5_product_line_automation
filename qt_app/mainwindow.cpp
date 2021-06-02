//sudo apt-get install libqt5sql5-mysql

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QStatusBar>
#include "database.h"
#include "form_productlines.h"
#include "form_queryresult.h"
#include "form_office.h"
#include "form_employee.h"
#include "form_product.h"
#include "form_customer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   

    //setCentralWidget(ui->frame);

    ui->statusbar->showMessage("Connected");
    this->setStyleSheet("background-color: rgb(123, 204, 181)");

    //ui->comboBox->addItem("abc");
    //ui->comboBox->addItem("def");

    qDebug() << "connecting to database ...";
    myDB = new database();
    myDB->connect("127.0.0.1", "classicmodels", "root", "Asd.1234");

}

MainWindow::~MainWindow()
{
    qDebug() << "disconnecting from database ...";
    myDB->disconnect();
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    Form_QueryResult qry;
    qry.setModal(true);
    qry.exec();
}

void MainWindow::on_pushButton_clicked()
{
    Form_Office ofc;
    ofc.setModal(true);
    ofc.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Form_Employee emp;
    emp.setModal(true);
    emp.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    Form_ProductLines pl;
    pl.setModal(true);
    pl.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    Form_Product prd;
    prd.setModal(true);
    prd.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    Form_Customer cus;
    cus.setModal(true);
    cus.exec();
}


