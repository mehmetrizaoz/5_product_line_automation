#include "form_product.h"
#include "ui_form_product.h"
#include <QGridLayout>

Form_Product::Form_Product(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Product)
{
    ui->setupUi(this);
    this->setWindowTitle("Product");

    this->setStyleSheet("background-color: rgb(123, 204, 181)");
    ui->lineEdit->setStyleSheet("background-color: white;");
    ui->lineEdit_2->setStyleSheet("background-color: white;");
    ui->lineEdit_3->setStyleSheet("background-color: white;");
    ui->lineEdit_4->setStyleSheet("background-color: white;");
    ui->lineEdit_5->setStyleSheet("background-color: white;");
    ui->lineEdit_6->setStyleSheet("background-color: white;");
    ui->lineEdit_7->setStyleSheet("background-color: white;");
    ui->lineEdit_8->setStyleSheet("background-color: white;");
    ui->lineEdit_9->setStyleSheet("background-color: white;");

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
    layout->addWidget(ui->pushButton,9,0,1,0);
    this->setLayout(layout);

}

Form_Product::~Form_Product()
{
    delete ui;
}
