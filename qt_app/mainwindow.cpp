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
#include "color.h"

#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QTextStream>


QString MainWindow::read(QString filename){
    QFile file(filename);
    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return "";
    }

    QTextStream in(&file);
    QString myText = in.readAll();

    // put QString into qDebug stream
    //qDebug() << myText;

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
    color myColor = color(10, 20, 30);
    qDebug() << myColor.R;
    qDebug() << myColor.G;
    qDebug() << myColor.B;


    //read("://queries/listEmployees");
    //qDebug() << read("://queries/listCustomers");


    //connect to classicmodels database
    //todo: if no connection check
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("classicmodels");
    db.setUserName("root");
    db.setPassword("Asd.1234");
    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";

    //create and execute query
    //todo: make code below a generic class
    QSqlQuery query;
    query.prepare(read("://queries/listCustomers"));
    query.exec();
    int columnCount = query.record().count();
    int rowCount = query.size();

    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(columnCount);

    //populate the table widget with the query result
    for(int row=0; row<rowCount; row++){
       query.next();
       for(int col=0; col<columnCount; col++){
          QTableWidgetItem *pCell = ui->tableWidget->item(row, col);
          pCell = new QTableWidgetItem;
          ui->tableWidget->setItem(row, col, pCell);
          pCell->setText(query.value(col).toString());
       }
    }

    //fit cell width according to its content
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

};

void MainWindow::on_pushButton_3_clicked()
{
    //this->hide();
    Dialog ddd;
    ddd.setModal(true);
    ddd.exec();
}
