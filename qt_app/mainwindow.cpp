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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    login  = new Form_Login();
    office = new Form_Office();
    emp    = new Form_Employee();
    cus    = new Form_Customer();
    pro    = new Form_Product();
    lin    = new Form_ProductLines();
    ord    = new Form_Order();
    orddt  = new Form_Order_Detail();
    myDB   = database();

    //make window open in screen center
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    setStyleSheet("background-color: rgb(224,243,176)");

    ui->statusbar->showMessage("Disconnected");

    ui->comboBox_offices->addItem("add office");
    ui->comboBox_offices->addItem("delete office");
    ui->comboBox_offices->addItem("update office");
    ui->comboBox_offices->addItem("list offices");
    ui->comboBox_offices->addItem("group employees by office");

    ui->comboBox_employees->addItem("add employee");
    ui->comboBox_employees->addItem("delete employee");
    ui->comboBox_employees->addItem("update employee");
    ui->comboBox_employees->addItem("list employees");
    ui->comboBox_employees->addItem("group reporters by employees");
    ui->comboBox_employees->addItem("number of customers per employee");
    ui->comboBox_employees->addItem("list sales by representative");

    ui->comboBox_customers->addItem("add customer");
    ui->comboBox_customers->addItem("delete customer");
    ui->comboBox_customers->addItem("update customer");
    ui->comboBox_customers->addItem("list customers");
    ui->comboBox_customers->addItem("number of orders per customer");
    ui->comboBox_customers->addItem("list products sold by customer");
    ui->comboBox_customers->addItem("group payments by customer");

    ui->comboBox_orders->addItem("add order");
    ui->comboBox_orders->addItem("delete order");
    ui->comboBox_orders->addItem("update order");
    ui->comboBox_orders->addItem("list orders");

    ui->comboBox_order_details->addItem("add order detail");
    ui->comboBox_order_details->addItem("delete order detail");
    ui->comboBox_order_details->addItem("update order detail");
    ui->comboBox_order_details->addItem("list order detail");
    ui->comboBox_order_details->addItem("list details of active orders");

    ui->comboBox_products->addItem("add product");
    ui->comboBox_products->addItem("delete product");
    ui->comboBox_products->addItem("update product");
    ui->comboBox_products->addItem("list products");

    ui->comboBox_productlines->addItem("add product line");
    ui->comboBox_productlines->addItem("delete product line");
    ui->comboBox_productlines->addItem("update product line");
    ui->comboBox_productlines->addItem("list product lines");
    ui->comboBox_productlines->addItem("group products by line");
    ui->comboBox_productlines->addItem("number of products per line");

    ui->tableWidget_01->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );

    //used to get connection status from login window
    connect(login, SIGNAL(loginClicked()), this, SLOT(get_login_status()));
    //trigger on show events
    connect(ui->comboBox_offices, SIGNAL(activated(int)), office, SLOT(on_show()));    
    connect(ui->comboBox_employees, SIGNAL(activated(int)), emp, SLOT(on_show()));
    connect(ui->comboBox_customers, SIGNAL(activated(int)), cus, SLOT(on_show()));
    connect(ui->comboBox_orders, SIGNAL(activated(int)), ord, SLOT(on_show()));
    connect(ui->comboBox_productlines, SIGNAL(activated(int)), lin, SLOT(on_show()));
    connect(ui->comboBox_products, SIGNAL(activated(int)), pro, SLOT(on_show()));
    connect(ui->comboBox_order_details, SIGNAL(activated(int)), orddt, SLOT(on_show()));
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
    delete ord;
    delete orddt;
}

void MainWindow::get_login_status(){
    if(login->isConnected == true)
        ui->statusbar->showMessage("Connected");    
    else
        ui->statusbar->showMessage("Disconnected");    
}

void MainWindow::on_comboBox_offices_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_offices->currentIndex()==0){
            office->show();
        }
        else if(ui->comboBox_offices->currentIndex()==1){
            qDebug()<<"2";
        }
        else if(ui->comboBox_offices->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_offices->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_offices");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_offices->currentIndex()==4){
            fileName = myDB.readFile("://queries/number_of_employees_for_each_office");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_employees_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_employees->currentIndex()==0){
            emp->show();
        }
        else if(ui->comboBox_employees->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_employees->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_employees->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_employees");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_employees->currentIndex()==4){
            fileName = myDB.readFile("://queries/list_employee_hierarchy");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_employees->currentIndex()==5){
            fileName = myDB.readFile("://queries/number_of_customers_for_each_employee");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_employees->currentIndex()==6){            
            fileName = myDB.readFile("://queries/list_sales");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_customers_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_customers->currentIndex()==0){
            cus->show();
        }
        else if(ui->comboBox_customers->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_customers->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_customers->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_customers");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_customers->currentIndex()==4){
            fileName = myDB.readFile("://queries/number_of_orders_per_customer");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_customers->currentIndex()==5){
            fileName = myDB.readFile("://queries/list_products_sold_by_customer");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_customers->currentIndex()==6){
            fileName = myDB.readFile("://queries/list_customers_by_payement");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_orders_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_orders->currentIndex()==0){
            ord->show();
        }
        else if(ui->comboBox_orders->currentIndex()==1){
            qDebug()<<"1";                        
        }
        else if(ui->comboBox_orders->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_orders->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_orders");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_order_details_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_order_details->currentIndex()==0){
            orddt->show();
        }
        else if(ui->comboBox_order_details->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_order_details->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_order_details->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_order_details");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_order_details->currentIndex()==4){
            fileName = myDB.readFile("://queries/list_active_order_details");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_products_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_products->currentIndex()==0){
            pro->show();
        }
        else if(ui->comboBox_products->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_products->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_products->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_products");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
    }
    else{ login->show(); }
}

void MainWindow::on_comboBox_productlines_activated(int index){
    if(login->isConnected == true){
        if(ui->comboBox_productlines->currentIndex()==0){
            lin->show();
        }
        else if(ui->comboBox_productlines->currentIndex()==1){
            qDebug()<<"1";
        }
        else if(ui->comboBox_productlines->currentIndex()==2){
            qDebug()<<"2";
        }
        else if(ui->comboBox_productlines->currentIndex()==3){
            fileName = myDB.readFile("://queries/list_product_lines");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_productlines->currentIndex()==4){
            fileName = myDB.readFile("://queries/list_products_by_productline");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
        else if(ui->comboBox_productlines->currentIndex()==5){
            fileName = myDB.readFile("://queries/number_of_products_per_line");
            qr = myDB.executeQuery(fileName);
            myDB.fillTable(qr, ui->tableWidget_01);
        }
    }
    else{ login->show(); }
}
