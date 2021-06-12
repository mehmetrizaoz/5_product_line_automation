#include "form_order.h"
#include "ui_form_order.h"
#include <QVBoxLayout>
#include <QMainWindow>
#include <QDebug>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>

Form_Order::Form_Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Order)
{
    ui->setupUi(this);
    this->setWindowTitle("Order");
    myDB = database();
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    setStyleSheet("background-color: rgb(224,243,176)");

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
    layout->addWidget(ui->comboBox,6,1);
    layout->addWidget(ui->add_office,7,0,1,0);
    this->setLayout(layout);
}

void Form_Order::on_show(){
    //fill customers combobox with query result
    QSqlQuery qr = myDB.executeQuery("SELECT * FROM customers");
    vector<int> cols{1};
    int row = 1;
    ui->comboBox->clear();
    for(int i=1; i<=qr.size(); i++){
        QString cust = myDB.getCells(qr, row, cols);
        ui->comboBox->addItem(cust);
    }

    qr = myDB.executeQuery("SELECT MAX(CONVERT(orderNumber,UNSIGNED INTEGER)) FROM orders");
    cols.clear();
    cols.push_back(0);
    row = 1;
    int n = myDB.getCells(qr, row, cols).toInt() + 1;
    ui->lineEdit->setText(QString::number(n));
}

Form_Order::~Form_Order()
{
    delete ui;
}

void Form_Order::on_add_office_clicked()
{

}
