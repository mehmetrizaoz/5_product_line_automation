//sudo apt-get install libqt5sql5-mysql

#include "ui_mainwindow.h"
#include "database.h"
#include "mainwindow.h"
#include "form_productlines.h"
#include "form_office.h"
#include "form_employee.h"
#include "form_product.h"
#include "form_customer.h"
#include "form_login.h"
#include <QDesktopWidget>
#include <QStyle>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);       
    login = new Form_Login();

    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));

    ui->statusbar->showMessage("Disconnected");

    ui->comboBox_01->addItem("add office");
    ui->comboBox_01->addItem("delete office");
    ui->comboBox_01->addItem("update office");
    ui->comboBox_01->addItem("list offices");
    ui->comboBox_01->addItem("group employees by office");

    ui->comboBox_02->addItem("add employee");
    ui->comboBox_02->addItem("delete employee");
    ui->comboBox_02->addItem("update employee");
    ui->comboBox_02->addItem("list employees");
    ui->comboBox_02->addItem("group reporters by employees");
    ui->comboBox_02->addItem("group customers by employees");
    ui->comboBox_02->addItem("group sales by employees");

    ui->comboBox_03->addItem("add customer");
    ui->comboBox_03->addItem("delete customer");
    ui->comboBox_03->addItem("update customer");
    ui->comboBox_03->addItem("list customers");
    ui->comboBox_03->addItem("group orders by customer");
    ui->comboBox_03->addItem("group products by customer");
    ui->comboBox_03->addItem("group payments by customer");

    ui->comboBox_04->addItem("add order");
    ui->comboBox_04->addItem("delete order");
    ui->comboBox_04->addItem("update order");
    ui->comboBox_04->addItem("list orders");
    ui->comboBox_04->addItem("group orders by customer");

    ui->comboBox_05->addItem("add payment");
    ui->comboBox_05->addItem("delete payment");
    ui->comboBox_05->addItem("update payment");
    ui->comboBox_05->addItem("list payments");

    ui->comboBox_06->addItem("add product");
    ui->comboBox_06->addItem("delete product");
    ui->comboBox_06->addItem("update product");
    ui->comboBox_06->addItem("list products");
    ui->comboBox_06->addItem("group sales by product");
    ui->comboBox_06->addItem("group orders by product");

    ui->comboBox_07->addItem("add product line");
    ui->comboBox_07->addItem("delete product line");
    ui->comboBox_07->addItem("update product line");
    ui->comboBox_07->addItem("list product lines");
    ui->comboBox_07->addItem("group products by line");

    connect(login, SIGNAL(loginClicked()), this, SLOT(getLoginStatus()));
}

MainWindow::~MainWindow()
{
    database *myDB = new database();
    myDB->disconnect();
    delete ui;
}

void MainWindow::getLoginStatus(){
    if(login->isConnected == true){
        ui->statusbar->showMessage("Connected");
    }
    else{
        ui->statusbar->showMessage("Disconnected");
    }
}

void MainWindow::on_comboBox_01_activated(int index)
{
    if(ui->comboBox_01->currentIndex()==0){
        Form_Office ofc;
        ofc.setModal(true);
        ofc.exec();
    }
    else if(ui->comboBox_01->currentIndex()==1){
        qDebug()<<"1";
    }
    else if(ui->comboBox_01->currentIndex()==2){
        qDebug()<<"2";
    }
    else if(ui->comboBox_01->currentIndex()==3){
        database myDB = database();
        myDB.execQuery("://queries/list_offices", ui->tableWidget_01);
    }
    else if(ui->comboBox_01->currentIndex()==4){
        database myDB = database();
        myDB.execQuery("://queries/number_of_employees_for_each_office", ui->tableWidget_01);
    }
}

void MainWindow::on_pushButton_01_clicked()
{
    login->show();
}

void MainWindow::on_comboBox_02_activated(int index)
{
    if(ui->comboBox_02->currentIndex()==3){
            database myDB = database();
            myDB.execQuery("://queries/list_employees", ui->tableWidget_01);
        }
}
