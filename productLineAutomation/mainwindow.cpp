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
    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";

    QSqlQuery query;
    query.prepare("SELECT * FROM customers");
    query.exec();
    int columnCount = query.record().count();
    int rowCount = query.size();
    qDebug() << "col:" << columnCount << "row:" << rowCount;

    /*QString qs = "";
    while (query.next()) {
       for(int i=0; i<columnCount; i++){
          qs += query.value(i).toString() + " ";
       }
       qDebug() << qs;
       qs = "";
    }*/

    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(columnCount);


    for(int row=0; row<rowCount; row++){
       query.next();
       for(int col=0; col<columnCount; col++){
          QTableWidgetItem *pCell = ui->tableWidget->item(row, col);
          pCell = new QTableWidgetItem;
          ui->tableWidget->setItem(row, col, pCell);
          pCell->setText(query.value(col).toString());
       }
    }
};

