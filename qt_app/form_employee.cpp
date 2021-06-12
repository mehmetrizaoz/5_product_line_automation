#include "form_employee.h"
#include "ui_form_employee.h"
#include <vector>
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QDebug>
#include <QSqlQuery>

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
    layout->addWidget(ui->add_employee,8,0,1,0);
    this->setLayout(layout);

}

void Form_Employee::on_show(){
    QSqlQuery qr = myDB.executeQuery("SELECT max(employeeNumber) FROM classicmodels.employees");
    vector<int> cols{0};
    int row = 1;
    int n = myDB.getCells(qr, row, cols).toInt() + 1;
    ui->lineEdit->setText(QString::number(n));

    qr = myDB.executeQuery("SELECT * FROM offices");
    cols.clear();
    cols.push_back(1);
    row = 1;
    ui->comboBox->clear();
    for(int i=1; i<=qr.size(); i++){
        QString offi = myDB.getCells(qr, row, cols);
        ui->comboBox->addItem(offi);
    }

    qr = myDB.executeQuery("SELECT * FROM employees");
    cols.clear();
    cols.push_back(2);
    cols.push_back(1);
    row = 1;
    ui->comboBox_2->clear();
    for(int i=1; i<=qr.size(); i++){
        QString man = myDB.getCells(qr, row, cols);
        ui->comboBox_2->addItem(man);
    }
}

Form_Employee::~Form_Employee()
{
    delete ui;
}

void Form_Employee::on_add_employee_clicked()
{

}
