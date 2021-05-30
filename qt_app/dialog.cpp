#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    password = ui->lineEdit->text();

    database myDB = database();
    if(myDB.connect("127.0.0.1", "classicmodels", "root", password) != false){
       myDB.execQuery("://queries/listCustomers", ui->tableWidget);
    }
    else{
       qDebug() << "cant connect to database";
    }
}
