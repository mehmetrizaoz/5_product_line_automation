//sudo apt-get install libqt5sql5-mysql

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QString>
#include "QDebug"
#include "dialog.h"
#include "database.h"
#include "newoffice.h"
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("background-color: rgb(0,255,0)");
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
