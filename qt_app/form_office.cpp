#include "form_office.h"
#include "ui_form_office.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QString>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>
#include "database.h"

Form_Office::Form_Office(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Office)
{
    ui->setupUi(this);
    this->setWindowTitle("Office");

    myDB = database();

    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));

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
    layout->addWidget(ui->pushButton_1,9,0,1,0);
    this->setLayout(layout);
}

Form_Office::~Form_Office()
{
    delete ui;
}

void Form_Office::onShow()
{
    QSqlQuery qr = myDB.executeQuery("SELECT MAX(CONVERT(officeCode,UNSIGNED INTEGER)) FROM offices");
    int n = myDB.getCell(qr, 1, 0).toInt() + 1;
    ui->lineEdit->setText(QString::number(n));
}

void Form_Office::on_pushButton_1_clicked()
{//insert new record

}



