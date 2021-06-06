#include "form_employee.h"
#include "ui_form_employee.h"
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>

Form_Employee::Form_Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Employee)
{
    ui->setupUi(this);
    this->setWindowTitle("Employee");
    setStyleSheet("background-color: rgb(224,243,176)");
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
    layout->addWidget(ui->comboBox,5,1);
    layout->addWidget(ui->label_7,6,0);
    layout->addWidget(ui->comboBox_2,6,1);
    layout->addWidget(ui->label_8,7,0);
    layout->addWidget(ui->lineEdit_8,7,1);
    layout->addWidget(ui->pushButton,8,0,1,0);
    this->setLayout(layout);

}

Form_Employee::~Form_Employee()
{
    delete ui;
}

void Form_Employee::on_pushButton_clicked()
{

}
