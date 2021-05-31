#include "newoffice.h"
#include "ui_newoffice.h"
#include <QMainWindow>
#include <QVBoxLayout>

NewOffice::NewOffice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOffice)
{
    ui->setupUi(this);

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

    this->setStyleSheet("background-color: rgb(123, 204, 181)");
}

NewOffice::~NewOffice()
{
    delete ui;
}
