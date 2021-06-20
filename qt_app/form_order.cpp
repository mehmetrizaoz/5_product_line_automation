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

void Form_Order::on_show(){   
    ui->process_order_record->setText(get_mode(mode));
    if(mode == ADD){
        QSqlQuery qr = myDB.executeQuery("SELECT * FROM customers");
        vector<int> cols{1};
        int row = 1;
        ui->comboBox->clear();
        for(int i=1; i<=qr.size(); i++){
            QString cust = myDB.getCells(qr, row, cols);
            ui->comboBox->addItem(cust);
        }

        qr = myDB.executeQuery("SELECT MAX(CONVERT(orderNumber,UNSIGNED INTEGER)) FROM orders");
        cols.clear();
        cols.push_back(0);
        row = 1;
        int n = myDB.getCells(qr, row, cols).toInt() + 1;
        ui->lineEdit->setText(QString::number(n));
    }
    else if(mode == UPDATE || mode == DELETE){
        /*
        QString fileName = myDB.readFile("://queries/list_offices");
        qr = myDB.executeQuery(fileName);
        qr.next();
        fill_form_with_query_result();*/
    }
}

void Form_Order::keyPressEvent(QKeyEvent *event){

}

QString Form_Order::get_mode(int m){
    if(m == ADD)
        return "Add";
    else if(m == UPDATE)
        return "Update";
    else if(m == DELETE)
        return "Delete";
    return "";
}

int Form_Order::get_next_order_code(){
    qr = myDB.executeQuery("SELECT MAX(CONVERT(orderNumber,UNSIGNED INTEGER)) FROM orders");
    vector<int> cols{0};
    int row = 1;
    return myDB.getCells(qr, row, cols).toInt() + 1;
}

void Form_Order::clear_form(){

}

void Form_Order::fill_form_with_query_result(){

}

void Form_Order::refresh_query(){

}

Form_Order::~Form_Order(){
    delete ui;
}

void Form_Order::on_process_order_record_clicked(){
    if( mode == ADD ){

    }
    else if( mode == UPDATE ){

    }
    else if( mode == DELETE ){

    }
}
