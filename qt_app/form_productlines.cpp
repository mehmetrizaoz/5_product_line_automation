#include "form_productlines.h"
#include "ui_form_productlines.h"
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

Form_ProductLines::Form_ProductLines(QWidget *parent) : QDialog(parent), ui(new Ui::Form_ProductLines){
    ui->setupUi(this);
    this->setWindowTitle("Product Line");
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
    layout->addWidget(ui->process_product_line_record,9,0,1,0);
    this->setLayout(layout);
}

Form_ProductLines::~Form_ProductLines(){
    delete ui;
}

int Form_ProductLines::get_next_product_line_code(){

}

void Form_ProductLines::populate_window(){
    ui->lineEdit->setText(qr.value(0).toString());
    ui->lineEdit_2->setText(qr.value(1).toString());
    ui->lineEdit_3->setText(qr.value(2).toString());
    ui->lineEdit_4->setText(qr.value(3).toString());
}

void Form_ProductLines::on_show(){
    ui->process_product_line_record->setText(get_mode(mode));
    clear_form();

    if(mode == UPDATE || mode == DELETE){
        qr = myDB.executeQuery("select * from productlines");
        qr.next();
        populate_window();
    }

}

void Form_ProductLines::refresh_query(){

}

QString Form_ProductLines::get_mode(int m){
    if(m == ADD) { return "Add"; }
    else if(m == UPDATE) { return "Update"; }
    else if(m == DELETE) { return "Delete"; }
    return "";
}

void Form_ProductLines::clear_form(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}

void Form_ProductLines::keyPressEvent(QKeyEvent *event){

}

void Form_ProductLines::on_process_product_line_record_clicked(){
    if( mode == ADD ){
        QString queryString = "insert into `productlines`(`productLine`,`textDescription`,`htmlDescription`,`image`) values(";
        queryString.append("'" + ui->lineEdit->text()   + "',");
        queryString.append("'" + ui->lineEdit_2->text() + "',");
        queryString.append("'" + ui->lineEdit_3->text() + "',");
        queryString.append("NULL)");
        myDB.executeQuery(queryString);
        clear_form();
    }
    else if( mode == UPDATE ){

    }
    else if( mode == DELETE ){

    }
}
