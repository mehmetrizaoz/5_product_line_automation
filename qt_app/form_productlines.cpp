#include "form_productlines.h"
#include "ui_form_productlines.h"
#include <QGridLayout>

Form_ProductLines::Form_ProductLines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_ProductLines)
{
    ui->setupUi(this);
    this->setWindowTitle("Product Line");
    this->setStyleSheet("background-color: rgb(123, 204, 181)");
    ui->lineEdit->setStyleSheet("background-color: white;");
    ui->lineEdit_2->setStyleSheet("background-color: white;");
    ui->lineEdit_3->setStyleSheet("background-color: white;");
    ui->lineEdit_4->setStyleSheet("background-color: white;");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->label,0,0);
    layout->addWidget(ui->lineEdit,0,1);
    layout->addWidget(ui->label_2,1,0);
    layout->addWidget(ui->lineEdit_2,1,1);
    layout->addWidget(ui->label_3,2,0);
    layout->addWidget(ui->lineEdit_3,2,1);
    layout->addWidget(ui->label_4,3,0);
    layout->addWidget(ui->lineEdit_4,3,1);

    layout->addWidget(ui->pushButton_1,9,0,1,0);
    this->setLayout(layout);
}

Form_ProductLines::~Form_ProductLines()
{
    delete ui;
}

void Form_ProductLines::on_pushButton_1_clicked()
{

}
