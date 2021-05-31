//sudo apt-get install libqt5sql5-mysql

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QString>
#include "QDebug"
#include "queryResult.h"
#include "database.h"
#include "office.h"
#include <QTableWidget>
#include "employee.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->frame);

    this->setStyleSheet("background-color: rgb(123, 204, 181)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog ddd;
    ddd.setModal(true);
    ddd.exec();
}

void MainWindow::on_pushButton_clicked()
{
    NewOffice ddd;
    ddd.setModal(true);
    ddd.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    employee ddd;
    ddd.setModal(true);
    ddd.exec();
}
