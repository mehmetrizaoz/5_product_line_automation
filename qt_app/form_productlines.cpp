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
    QThread::msleep(100);
    qr = myDB.executeQuery("select * from productlines");
    qr.next();
    for(int i = 0; i<recordOnScreen-1; i++){ qr.next(); }
    populate_window();
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

void Form_ProductLines::on_process_product_line_record_clicked(){
    QString queryString;
    if( mode == ADD ){
        queryString = "insert into `productlines`(`productLine`,`textDescription`,`htmlDescription`,`image`) values(";
        queryString.append("'" + ui->lineEdit->text()   + "',");
        queryString.append("'" + ui->lineEdit_2->text() + "',");
        queryString.append("'" + ui->lineEdit_3->text() + "',");
        queryString.append("NULL)");
        myDB.executeQuery(queryString);
        clear_form();
    }
    else if( mode == UPDATE ){
        queryString = "UPDATE productlines SET ";
        queryString.append("textDescription = '" + ui->lineEdit_2->text() + "', ");
        queryString.append("htmlDescription = '" + ui->lineEdit_3->text() + "' ");
        //queryString.append("image = '" + ui->lineEdit_4->text() + "', ");
        queryString.append("where productLine = '" + ui->lineEdit->text() + "'");
        myDB.executeQuery(queryString);
        refresh_query();
    }
    else if( mode == DELETE ){
        myDB.executeQuery("DELETE FROM productlines WHERE productLine = '" + ui->lineEdit->text() + "'");
        recordOnScreen--;
        refresh_query();
    }
}
