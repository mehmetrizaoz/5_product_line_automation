//sudo apt-get install libqt5sql5-mysql

#include "ui_mainwindow.h"
#include "database.h"
#include "mainwindow.h"
#include <QDesktopWidget>
#include <QStyle>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    login  = new Form_Login();
    office = new Form_Office();
    emp    = new Form_Employee();
    cus    = new Form_Customer();
    pro    = new Form_Product();
    lin    = new Form_ProductLines();

    myDB = database();

    //make window open in screen center
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    setStyleSheet("background-color: rgb(224,243,176)");

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
    ui->comboBox_02->addItem("number of customers per employee");
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
    ui->comboBox_07->addItem("number of products per line");

    //used to get connection status from login window
    connect(login, SIGNAL(loginClicked()), this, SLOT(getLoginStatus()));

    //used to set office windows officeCode column with next p.k.
    connect(ui->comboBox_01, SIGNAL(activated(int)), office, SLOT(on_show()));

    //used to set employee windows employeeNumber column with next p.k.
    connect(ui->comboBox_02, SIGNAL(activated(int)), emp, SLOT(on_show()));
}

MainWindow::~MainWindow(){
    myDB.disconnect();
    delete ui;
    delete login;
    delete office;
    delete emp;
    delete cus;
    delete pro;
    delete lin;
}

void MainWindow::getLoginStatus(){
    if(login->isConnected == true)
        ui->statusbar->showMessage("Connected");    
    else
        ui->statusbar->showMessage("Disconnected");    
}

void MainWindow::on_comboBox_01_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_01->currentIndex()==0){
            office->show();
        }
        else if(ui->comboBox_01->currentIndex()==1){
            qDebug()<<"2";
        }
        else if(ui->comboBox_01->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_01->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_offices");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_01->currentIndex()==4){
            fileName = myDB.readFile("://queries/number_of_employees_for_each_office");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_02_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_02->currentIndex()==0){
            emp->show();
        }
        else if(ui->comboBox_02->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_02->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_02->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_employees");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_02->currentIndex()==4){
            qDebug()<<"4";
        }
        else if(ui->comboBox_02->currentIndex()==5){
            fileName = myDB.readFile("://queries/number_of_customers_for_each_employee");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_02->currentIndex()==6){
            qDebug()<<"6";
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_03_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_03->currentIndex()==0){
            cus->show();
        }
        else if(ui->comboBox_03->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_03->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_03->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_customers");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_03->currentIndex()==4){
            qDebug()<<"4";
        }
        else if(ui->comboBox_03->currentIndex()==5){
            qDebug()<<"5";
        }
        else if(ui->comboBox_03->currentIndex()==6){
            qDebug()<<"6";
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_04_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_04->currentIndex()==0){
            qDebug()<<"0";
        }
        else if(ui->comboBox_04->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_04->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_04->currentIndex()==3){
            qDebug()<<"3";
        }
        else if(ui->comboBox_04->currentIndex()==4){
            qDebug()<<"4";
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_05_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_05->currentIndex()==0){
            qDebug()<<"0";
        }
        else if(ui->comboBox_05->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_05->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_05->currentIndex()==3){
            qDebug()<<"3";
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_06_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_06->currentIndex()==0){
            pro->show();
        }
        else if(ui->comboBox_06->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_06->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_06->currentIndex()==3){
            qDebug()<<"3";
        }
        else if(ui->comboBox_06->currentIndex()==4){
            qDebug()<<"4";
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_07_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_07->currentIndex()==0){            
            lin->show();
        }
        else if(ui->comboBox_07->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_07->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_07->currentIndex()==3){
            qDebug()<<"3";
        }
        else if(ui->comboBox_07->currentIndex()==4){
            fileName = myDB.readFile("://queries/list_products_by_productline");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_07->currentIndex()==5){
            fileName = myDB.readFile("://queries/number_of_products_per_line");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }

    }
    else{ login->show(); }
}
