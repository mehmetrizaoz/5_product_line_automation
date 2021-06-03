#include "form_login.h"
#include "ui_form_login.h"
#include <QGridLayout>
#include "database.h"

Form_Login::Form_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Login)
{
    ui->setupUi(this);
    this->setFixedSize(278,194);
    this->setWindowTitle("Login");

    connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(loginClicked()));
}

Form_Login::~Form_Login()
{
    delete ui;
}
/*
void Form_Login::aaa(){
    qDebug() << "aaa";
}*/

void Form_Login::on_pushButton_clicked()
{
    database *myDB = new database();
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString hostname = ui->lineEdit_3->text();
    QString database = ui->lineEdit_4->text();

    if(myDB->connect(hostname, database, username, password) == true)
    {
       qDebug() << "connected";
       isConnected = true;
       this->close();
    }
    else
    {
       //todo: use messagebox
       isConnected = false;
       qDebug() << "cant connect to database server";
    }
}

