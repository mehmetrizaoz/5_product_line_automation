#include "form_customer.h"
#include "ui_form_customer.h"
#include "database.h"
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QDebug>

Form_Customer::Form_Customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Customer)
{
    ui->setupUi(this);
    this->setWindowTitle("Customer");
    setStyleSheet("background-color: rgb(224,243,176)");
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    myDB = database();

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
    layout->addWidget(ui->label_10,9,0);
    layout->addWidget(ui->lineEdit_10,9,1);
    layout->addWidget(ui->label_11,10,0);
    layout->addWidget(ui->lineEdit_11,10,1);
    layout->addWidget(ui->label_12,11,0);
    layout->addWidget(ui->comboBox,11,1);
    layout->addWidget(ui->label_13,12,0);
    layout->addWidget(ui->lineEdit_12,12,1);

    layout->addWidget(ui->add_customer,13,0,1,0);

    this->setLayout(layout);
}

Form_Customer::~Form_Customer()
{
    delete ui;
}

void Form_Customer::on_show(){
    database myDB = database();
    QSqlQuery qr = myDB.executeQuery("SELECT contactFirstName, contactLastName FROM classicmodels.customers");

    //fill employee combobox with qery result
    vector<int> cols{0, 1};
    int row = 1;
    for(int i=1; i<=qr.size(); i++){
        QString responsibleEmployee = myDB.getCells(qr, row, cols);
        ui->comboBox->addItem(responsibleEmployee);
    }

    qr = myDB.executeQuery("SELECT MAX(CONVERT(customerNumber, UNSIGNED INTEGER)) FROM customers");
    cols.clear();
    cols.push_back(0);
    row = 1;
    int n = myDB.getCells(qr, row, cols).toInt() + 1;
    ui->lineEdit->setText(QString::number(n));
}

void Form_Customer::on_add_customer_clicked()
{
    QString queryString ="insert into customers (customerNumber, customerName, contactLastName, contactFirstName, \
phone, addressLine1, addressLine2, city, state, postalCode, country, salesRepEmployeeNumber, \
creditLimit) values (";
    queryString.append(ui->lineEdit->text() + ",");
    queryString.append("'" + ui->lineEdit_2->text()   + "',");
    queryString.append("'" + ui->lineEdit_3->text()   + "',");
    queryString.append("'" + ui->lineEdit_4->text()   + "',");
    queryString.append("'" + ui->lineEdit_5->text()   + "',");
    queryString.append("'" + ui->lineEdit_6->text()   + "',");
    queryString.append("'" + ui->lineEdit_7->text()   + "',");
    queryString.append("'" + ui->lineEdit_8->text()   + "',");
    queryString.append("'" + ui->lineEdit_9->text()   + "',");
    queryString.append("'" + ui->lineEdit_10->text()   + "',");
    queryString.append("'" + ui->lineEdit_11->text()   + "',");

    queryString.append("1370, '21000.00')");

    myDB.executeQuery(queryString);
    qDebug()<<queryString;

    /*

    queryString.append("'" + ui->lineEdit_2->text() + "',");
    queryString.append("'" + ui->lineEdit_3->text() + "',");
    queryString.append("'" + ui->lineEdit_4->text() + "',");
    queryString.append("'" + ui->lineEdit_6->text() + "',");
    queryString.append("'" + ui->lineEdit_7->text() + "',");
    queryString.append("'" + ui->lineEdit_8->text() + "',");
    queryString.append("'" + ui->lineEdit_9->text() + "',");
    queryString.append("'" + ui->lineEdit_10->text() + "',");
    queryString.append("'" + ui->lineEdit_11->text() + "',");
    queryString.append("'" + ui->lineEdit_12->text() + "',");
    queryString.append("'" + ui->comboBox->currentText() + "',");
    queryString.append("'" + ui->lineEdit_14->text() + "')");

    myDB.executeQuery(queryString);

    qDebug() << queryString;

    ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt() + 1));
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_14->setText("");*/
}
