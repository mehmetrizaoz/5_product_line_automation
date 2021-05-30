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
#include "dialog.h"
#include "database.h"

#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QTableWidget>

QString MainWindow::read(QString filename){
    QFile file(filename);
    if(!file.open(QFile::ReadOnly |
                  QFile::Text)){
        qDebug() << " Could not open the file for reading";
        return "";
    }
    QTextStream in(&file);
    QString myText = in.readAll();
    file.close();
    return myText;
}

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
    database myDB = database();
    if(myDB.connect("127.0.0.1", "classicmodels", "root", "Asd.1234") != false){
       myDB.execQuery("ss", ui->tableWidget);
    }
    else{
       qDebug() << "cant connect to database";
    }
};

void MainWindow::on_pushButton_3_clicked()
{
    Dialog ddd;
    ddd.setModal(true);
    ddd.exec();
}
