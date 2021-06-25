#include "form_customer.h"
#include "ui_form_customer.h"
#include "database.h"
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QDebug>

Form_Customer::Form_Customer(QWidget *parent) : QDialog(parent), ui(new Ui::Form_Customer){
    ui->setupUi(this);
    this->setWindowTitle("Customer");
    setStyleSheet("background-color: rgb(224,243,176)");
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    myDB = database();

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
    layout->addWidget(ui->lineEdit_7,6,1);
    layout->addWidget(ui->label_8,7,0);
    layout->addWidget(ui->lineEdit_8,7,1);
    layout->addWidget(ui->label_9,8,0);
    layout->addWidget(ui->lineEdit_9,8,1);
    layout->addWidget(ui->label_10,9,0);
    layout->addWidget(ui->lineEdit_10,9,1);
    layout->addWidget(ui->label_11,10,0);
    layout->addWidget(ui->lineEdit_11,10,1);
    layout->addWidget(ui->label_12,11,0);
    layout->addWidget(ui->comboBox,11,1);
    layout->addWidget(ui->label_13,12,0);
    layout->addWidget(ui->lineEdit_12,12,1);
    layout->addWidget(ui->process_customer_record,13,0,1,0);
    this->setLayout(layout);
}

Form_Customer::~Form_Customer(){
    delete ui;
}

void Form_Customer::on_show(){
    ui->process_customer_record->setText(get_mode(mode));

    if(mode == ADD){
        QSqlQuery qr = myDB.executeQuery("SELECT * FROM employees");
        vector<int> cols{2, 1};
        int row = 1;
        ui->comboBox->clear();
        for(int i=1; i<=qr.size(); i++){
            QString responsibleEmployee = myDB.getCells(qr, row, cols);
            ui->comboBox->addItem(responsibleEmployee);
        }
        qr = myDB.executeQuery("SELECT MAX(CONVERT(customerNumber, UNSIGNED INTEGER)) FROM customers");
        cols.clear();
        cols.push_back(0);
        row = 1;
        int n = myDB.getCells(qr, row, cols).toInt() + 1;
        ui->lineEdit->setText(QString::number(n));
    }
    else if(mode == UPDATE || mode == DELETE){
        qr = myDB.executeQuery("select * from customers");
        qr.next();
        populate_window();
    }
}

void Form_Customer::populate_window(){
    ui->lineEdit->setText(qr.value(0).toString());
    ui->lineEdit_2->setText(qr.value(1).toString());
    ui->lineEdit_3->setText(qr.value(2).toString());
    ui->lineEdit_4->setText(qr.value(3).toString());
    ui->lineEdit_5->setText(qr.value(4).toString());
    ui->lineEdit_6->setText(qr.value(5).toString());
    ui->lineEdit_7->setText(qr.value(6).toString());
    ui->lineEdit_8->setText(qr.value(7).toString());
    ui->lineEdit_9->setText(qr.value(8).toString());
    ui->lineEdit_10->setText(qr.value(9).toString());
    //combobox
    ui->lineEdit_11->setText(qr.value(11).toString());
    ui->lineEdit_12->setText(qr.value(12).toString());
}

void Form_Customer::keyPressEvent(QKeyEvent *event){
    if(mode == DELETE || mode == UPDATE){
        if (event->key() == Qt::Key_Up){ //next record
            if(qr.next() == NULL){
                qr.first();
                recordOnScreen = 1;
            }
            else
                recordOnScreen++;
            populate_window();
        }
        if (event->key() == Qt::Key_Down){ //previous record
            if(qr.previous() == NULL){
                qr.last();
                recordOnScreen = qr.size();
            }
            else
                recordOnScreen--;
            populate_window();
        }
    }
}

QString Form_Customer::get_mode(int m){
    if(m == ADD) { return "Add"; }
    else if(m == UPDATE) { return "Update"; }
    else if(m == DELETE) { return "Delete"; }
    return "";
}

void Form_Customer::clear_form(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
}

void Form_Customer::refresh_query(){

}

void Form_Customer::on_process_customer_record_clicked(){
    QString queryString;
    if( mode == ADD ){
        //get selected employee number
        QSqlQuery qr2 = myDB.executeQuery("SELECT * FROM employees");
        vector<int> cols{0};
        QString empNum = myDB.getCells(qr2, ui->comboBox->currentIndex()+1, cols);

        queryString ="insert into customers (customerNumber, customerName, contactLastName, \
            contactFirstName, creditLimit, phone, addressLine1, addressLine2, city, state, \
            postalCode, salesRepEmployeeNumber, country) values (";
        queryString.append(ui->lineEdit->text() + ",");
        queryString.append("'" + ui->lineEdit_2->text() + "',");
        queryString.append("'" + ui->lineEdit_3->text() + "',");
        queryString.append("'" + ui->lineEdit_4->text() + "',");
        queryString.append("'" + ui->lineEdit_5->text() + "',");
        queryString.append("'" + ui->lineEdit_6->text() + "',");
        queryString.append("'" + ui->lineEdit_7->text() + "',");
        queryString.append("'" + ui->lineEdit_8->text() + "',");
        queryString.append("'" + ui->lineEdit_9->text() + "',");
        queryString.append("'" + ui->lineEdit_10->text() + "',");
        queryString.append("'" + ui->lineEdit_11->text() + "',");
        queryString.append(empNum);
        queryString.append(",'" + ui->lineEdit_12->text() + "')");
        myDB.executeQuery(queryString);

        clear_form();
        ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt() + 1));
    }
    else if( mode == UPDATE ){

    }
    else if( mode == DELETE ){

    }
}

