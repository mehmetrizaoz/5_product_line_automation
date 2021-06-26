#include "form_order.h"
#include "ui_form_order.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QString>
#include <vector>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlError>
#include <QThread>
#include <QSqlQuery>

Form_Order::Form_Order(QWidget *parent) : QDialog(parent), ui(new Ui::Form_Order){
    ui->setupUi(this);
    this->setWindowTitle("Order");
    myDB = database();
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    setStyleSheet("background-color: rgb(224,243,176)");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->label,0,0);
    layout->addWidget(ui->lineEdit,0,1);
    layout->addWidget(ui->label_2,1,0);
    layout->addWidget(ui->lineEdit_2,1,1);
    layout->addWidget(ui->label_3,2,0);
    layout->addWidget(ui->lineEdit_3,2,1);
    layout->addWidget(ui->label_4,3,0);
    layout->addWidget(ui->lineEdit_4,3,1);
    layout->addWidget(ui->label_5,4,0);
    layout->addWidget(ui->lineEdit_5,4,1);
    layout->addWidget(ui->label_6,5,0);
    layout->addWidget(ui->lineEdit_6,5,1);
    layout->addWidget(ui->label_7,6,0);
    layout->addWidget(ui->comboBox,6,1);
    layout->addWidget(ui->process_order_record,7,0,1,0);
    this->setLayout(layout);
}

void Form_Order::populate_window(){
    ui->lineEdit->setText(qr.value(0).toString());
    ui->lineEdit_2->setText(qr.value(1).toString());
    ui->lineEdit_3->setText(qr.value(2).toString());
    ui->lineEdit_4->setText(qr.value(3).toString());
    ui->lineEdit_5->setText(qr.value(4).toString());
    ui->lineEdit_6->setText(qr.value(5).toString());

    QString qs = "select customerName from customers where customerNumber = " + qr.value(6).toString();
    QSqlQuery qr3 = myDB.executeQuery(qs);
    qr3.next();
    QString cName = qr3.value(0).toString();
    ui->comboBox->setCurrentText(cName);
}

void Form_Order::fill_costumers(){
    QSqlQuery qr1 = myDB.executeQuery("SELECT * FROM customers");
    vector<int> cols{1};
    int row = 1;
    ui->comboBox->clear();
    for(int i=1; i<=qr1.size(); i++){
        QString cust = myDB.getCells(qr1, row, cols);
        ui->comboBox->addItem(cust);
    }
}

void Form_Order::on_show(){   
    ui->process_order_record->setText(get_mode(mode));
    clear_form();
    fill_costumers();
    if(mode == ADD){
        get_next_order_code();
    }
    else if(mode == UPDATE || mode == DELETE){
        qr = myDB.executeQuery("select * from orders");
        qr.next();
        populate_window();
    }
}

void Form_Order::keyPressEvent(QKeyEvent *event){
    if(mode == DELETE || mode == UPDATE){
        if (event->key() == Qt::Key_Up){ //next record
            if(qr.next() == NULL){
                qr.first();
                recordOnScreen = 1;
            }
            else { recordOnScreen++; }
            populate_window();
        }
        if (event->key() == Qt::Key_Down){ //previous record
            if(qr.previous() == NULL){
                qr.last();
                recordOnScreen = qr.size();
            }
            else { recordOnScreen--; }
            populate_window();
        }
    }
}

QString Form_Order::get_mode(int m){
    if(m == ADD) { return "Add"; }
    else if(m == UPDATE) { return "Update"; }
    else if(m == DELETE) { return "Delete"; }
    return "";
}

void Form_Order::get_next_order_code(){
    vector<int> cols{1};
    int row = 1;
    QSqlQuery qr2 = myDB.executeQuery("SELECT MAX(CONVERT(orderNumber,UNSIGNED INTEGER)) FROM orders");
    cols.clear();
    cols.push_back(0);
    int n = myDB.getCells(qr2, row, cols).toInt() + 1;
    ui->lineEdit->setText(QString::number(n));
}

void Form_Order::clear_form(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->comboBox->setCurrentIndex(0);
}

void Form_Order::refresh_query(){
    QThread::msleep(100);
    qr = myDB.executeQuery("select * from orders");
    qr.next();
    for(int i = 0; i<recordOnScreen-1; i++){ qr.next(); }
    populate_window();
}

Form_Order::~Form_Order(){
    delete ui;
}

QString Form_Order::get_customer_number_from_customer_name(){
    QString queryString = "select customerNumber from customers where customerName = '" + ui->comboBox->currentText() + "'";
    vector<int> cols{0};
    int row = 1;
    return myDB.getCells(myDB.executeQuery(queryString), row, cols);
}

void Form_Order::on_process_order_record_clicked(){
    QString queryString;
    QString customerNumber;

    if( mode == ADD ){
        customerNumber = get_customer_number_from_customer_name();
        queryString = "insert into `orders`(`orderNumber`,`orderDate`,`requiredDate`,`shippedDate`,`status`,`comments`,`customerNumber`) values (";
        queryString.append("'" + ui->lineEdit->text()   + "',");
        queryString.append("'" + ui->lineEdit_2->text() + "',");
        queryString.append("'" + ui->lineEdit_3->text() + "',");
        queryString.append("'" + ui->lineEdit_4->text() + "',");
        queryString.append("'" + ui->lineEdit_5->text() + "',");
        queryString.append("'" + ui->lineEdit_6->text() + "',");
        queryString.append(customerNumber + ")");
        myDB.executeQuery(queryString);

        QString nextOrderNumber = QString::number(ui->lineEdit->text().toInt() + 1);
        clear_form();
        ui->lineEdit->setText(nextOrderNumber);
    }
    else if( mode == UPDATE ){
        customerNumber = get_customer_number_from_customer_name();
        queryString = "UPDATE orders SET ";
        queryString.append("orderDate = '" + ui->lineEdit_2->text() + "', ");
        queryString.append("requiredDate = '" + ui->lineEdit_3->text() + "', ");
        queryString.append("shippedDate = '" + ui->lineEdit_4->text() + "', ");
        queryString.append("status = '" + ui->lineEdit_5->text() + "', ");
        queryString.append("comments = '" + ui->lineEdit_6->text() + "', ");
        queryString.append("customerNumber = '" + customerNumber + "' ");
        queryString.append("where orderNumber = " + ui->lineEdit->text());
        myDB.executeQuery(queryString);
        refresh_query();
    }
    else if( mode == DELETE ){
        queryString = "DELETE FROM orderdetails WHERE orderNumber = " + ui->lineEdit->text();
        myDB.executeQuery(queryString);
        queryString = "DELETE FROM orders WHERE orderNumber = " + ui->lineEdit->text();
        myDB.executeQuery(queryString);
        recordOnScreen--;
        refresh_query();
    }
}
