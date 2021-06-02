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
#include "form_login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    //this->setStyleSheet("background-color: rgb(123, 204, 181)");
    login = new Form_Login();

    //setCentralWidget(ui->frame);
    //ui->statusbar->showMessage("Connected");
    ui->comboBox->addItem("list details of offices");
    ui->comboBox->addItem("add new office");
    ui->comboBox->addItem("update office");
    ui->comboBox->addItem("list number of employees for each office");
}

MainWindow::~MainWindow()
{
    database *myDB = new database();
    myDB->disconnect();
    delete ui;
}

void MainWindow::on_pushButton_6_clicked()
{
    login->show();
}

void MainWindow::on_comboBox_activated(int index)
{
    if(ui->comboBox->currentIndex()==0){
            qDebug()<<"0";
        }
        else if(ui->comboBox->currentIndex()==1){
            Form_Office ofc;
            ofc.setModal(true);
            ofc.exec();
        }
        else if(ui->comboBox->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox->currentIndex()==3){
            database myDB = database();
            myDB.execQuery("://queries/number_of_employees_for_each_office", ui->tableWidget);
        }
}
