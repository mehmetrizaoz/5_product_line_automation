#include "form_office.h"
#include "ui_form_office.h"
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
#include "database.h"

Form_Office::Form_Office(QWidget *parent) : QDialog(parent), ui(new Ui::Form_Office){
    ui->setupUi(this);
    this->setWindowTitle("Office");
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
    layout->addWidget(ui->lineEdit_7,6,1);
    layout->addWidget(ui->label_8,7,0);
    layout->addWidget(ui->lineEdit_8,7,1);
    layout->addWidget(ui->label_9,8,0);
    layout->addWidget(ui->lineEdit_9,8,1);
    layout->addWidget(ui->process_office_record,9,0,1,0);
    this->setLayout(layout);
}

void Form_Office::keyPressEvent(QKeyEvent *event) {
   if(mode == DELETE || mode == UPDATE) {
       if (event->key() == Qt::Key_N) {
           if(qr.next() != NULL) //todo: ring behaviour will be implemented
              this->fill_form_with_query_result();
       }
       if (event->key() == Qt::Key_P) {
           if(qr.previous() != NULL)
              this->fill_form_with_query_result();
       }
   }
}

Form_Office::~Form_Office(){
    delete ui;
}

QString Form_Office::getMode(int m){
    if(m == ADD)
        return "Add";
    else if(m == UPDATE)
        return "Update";
    else if(m == DELETE)
        return "Delete";
    return "";
}

void Form_Office::on_show(){
    QString fileName = myDB.readFile("://queries/list_offices");
    ui->process_office_record->setText(getMode(mode));
    if(mode == ADD){
        clear_form();        
        qr = myDB.executeQuery("SELECT MAX(CONVERT(officeCode,UNSIGNED INTEGER)) FROM offices");
        vector<int> cols{0};
        int row = 1;
        int n = myDB.getCells(qr, row, cols).toInt() + 1;
        ui->lineEdit->setText(QString::number(n));
    }
    else if(mode == UPDATE || mode == DELETE){
        qr = myDB.executeQuery(fileName);
        qr.next();
        this->fill_form_with_query_result();
    }
}

void Form_Office::clear_form(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
}

void Form_Office::fill_form_with_query_result(){
    ui->lineEdit->setText(qr.value(0).toString());
    ui->lineEdit_2->setText(qr.value(1).toString());
    ui->lineEdit_3->setText(qr.value(2).toString());
    ui->lineEdit_4->setText(qr.value(3).toString());
    ui->lineEdit_5->setText(qr.value(4).toString());
    ui->lineEdit_6->setText(qr.value(5).toString());
    ui->lineEdit_7->setText(qr.value(6).toString());
    ui->lineEdit_8->setText(qr.value(7).toString());
    ui->lineEdit_9->setText(qr.value(8).toString());
}

void Form_Office::on_process_office_record_clicked(){
    if( mode == ADD ){
        QString queryString = "insert into `offices`(`officeCode`,`city`,`phone`,`addressLine1`,`addressLine2`,`state`,`country`,`postalCode`,`territory`) values (";
        queryString.append("'" + ui->lineEdit->text()   + "',");
        queryString.append("'" + ui->lineEdit_2->text() + "',");
        queryString.append("'" + ui->lineEdit_3->text() + "',");
        queryString.append("'" + ui->lineEdit_4->text() + "',");
        queryString.append("'" + ui->lineEdit_5->text() + "',");
        queryString.append("'" + ui->lineEdit_6->text() + "',");
        queryString.append("'" + ui->lineEdit_7->text() + "',");
        queryString.append("'" + ui->lineEdit_8->text() + "',");
        queryString.append("'" + ui->lineEdit_9->text() + "')");
        myDB.executeQuery(queryString);

        QString next = QString::number(ui->lineEdit->text().toInt() + 1);
        this->clear_form();
        ui->lineEdit->setText(next);
    }
    else if( mode == UPDATE ){
        qDebug() << "update";
    }
    else if( mode == DELETE ){
        QString queryString = "DELETE FROM offices WHERE officeCode = ";
        queryString.append(ui->lineEdit->text());
        myDB.executeQuery(queryString);

        QString fileName = myDB.readFile("://queries/list_offices");
        QThread::msleep(100);
        qr = myDB.executeQuery(fileName);
        qr.next();
        this->fill_form_with_query_result();
    }
}
