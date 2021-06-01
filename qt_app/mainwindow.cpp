//sudo apt-get install libqt5sql5-mysql

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include "database.h"
#include "form_productlines.h"
#include "form_queryresult.h"
#include "form_office.h"
#include "form_employee.h"
#include "form_product.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->frame);

    this->setStyleSheet("background-color: rgb(123, 204, 181)");
}

MainWindow::~MainWindow()
{
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
