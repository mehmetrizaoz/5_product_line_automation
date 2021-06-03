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
    ui->comboBox->addItem("add office");
    ui->comboBox->addItem("delete office");
    ui->comboBox->addItem("update office");
    ui->comboBox->addItem("list offices");
    ui->comboBox->addItem("list number of employees");

    ui->comboBox_2->addItem("add employee");
    ui->comboBox_2->addItem("delete employee");
    ui->comboBox_2->addItem("update employee");
    ui->comboBox_2->addItem("list employees");
    ui->comboBox_2->addItem("list reporters of an employee");
    ui->comboBox_2->addItem("list customers of an employee");
    ui->comboBox_2->addItem("total number of employees per employee");

    ui->comboBox_3->addItem("add customer");
    ui->comboBox_3->addItem("delete customer");
    ui->comboBox_3->addItem("update customer");
    ui->comboBox_3->addItem("list customers");
    ui->comboBox_3->addItem("list orders of a customer");
    ui->comboBox_3->addItem("list products of a customer");
    ui->comboBox_3->addItem("list payments of a customer");

    ui->comboBox_4->addItem("add order");
    ui->comboBox_4->addItem("delete order");
    ui->comboBox_4->addItem("update order");
    ui->comboBox_4->addItem("list orders");
    ui->comboBox_4->addItem("list order for each customes");

    ui->comboBox_5->addItem("add payment");
    ui->comboBox_5->addItem("delete payment");
    ui->comboBox_5->addItem("update payment");
    ui->comboBox_5->addItem("list payments");
    ui->comboBox_5->addItem("list payment for each customes");

    ui->comboBox_6->addItem("add product");
    ui->comboBox_6->addItem("delete product");
    ui->comboBox_6->addItem("update product");
    ui->comboBox_6->addItem("list products");
    ui->comboBox_6->addItem("list numbers sales of all the products");
    ui->comboBox_6->addItem("list products in an order");

    ui->comboBox_7->addItem("add product line");
    ui->comboBox_7->addItem("delete product line");
    ui->comboBox_7->addItem("update product line");
    ui->comboBox_7->addItem("list product lines");
    ui->comboBox_7->addItem("list products manufactered in a line");
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
        Form_Office ofc;
        ofc.setModal(true);
        ofc.exec();
    }
    else if(ui->comboBox->currentIndex()==1){
        qDebug()<<"1";
    }
    else if(ui->comboBox->currentIndex()==2){
        qDebug()<<"2";
    }
    else if(ui->comboBox->currentIndex()==3){
        database myDB = database();
        myDB.execQuery("://queries/list_offices", ui->tableWidget);
    }
    else if(ui->comboBox->currentIndex()==4){
        database myDB = database();
        myDB.execQuery("://queries/number_of_employees_for_each_office", ui->tableWidget);
    }
}

void MainWindow::on_comboBox_2_activated(int index)
{

}

void MainWindow::on_comboBox_3_activated(int index)
{

}
