#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Hello");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//sudo apt-get install libqt5sql5-mysql

void MainWindow::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("classicmodels");
    db.setUserName("root");
    db.setPassword("Asd.1234");
    if (!db.open()) qDebug() << "Failed to connect to root mysql admin";

    //QSqlQuery query("SELECT customerName FROM classicmodels.customers", db);
    QSqlQuery query;
    query.exec("SELECT * FROM customers");
    const int memCount = query.record().count();
    //qDebug() << memCount;

    QString qs = "";
    while (query.next()) {
      for(int i=0; i<memCount; i++){
         qs += query.value(i).toString() + " ";
      }
      qDebug() << qs;
      qs = "";
    }


};
