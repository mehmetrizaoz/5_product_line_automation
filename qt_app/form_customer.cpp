#include "form_customer.h"
#include "ui_form_customer.h"
#include "database.h"
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QDebug>

Form_Customer::Form_Customer(QWidget *parent) : QDialog(parent), ui(new Ui::Form_Customer){
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

    layout->addWidget(ui->label_6,4,0);
    layout->addWidget(ui->lineEdit_6,4,1);
    layout->addWidget(ui->label_7,5,0);
    layout->addWidget(ui->lineEdit_7,5,1);
    layout->addWidget(ui->label_8,6,0);
    layout->addWidget(ui->lineEdit_8,6,1);
    layout->addWidget(ui->label_9,7,0);
    layout->addWidget(ui->lineEdit_9,7,1);
    layout->addWidget(ui->label_10,8,0);
    layout->addWidget(ui->lineEdit_10,8,1);
    layout->addWidget(ui->label_11,9,0);
    layout->addWidget(ui->lineEdit_11,9,1);
    layout->addWidget(ui->label_12,10,0);
    layout->addWidget(ui->comboBox,10,1);
    layout->addWidget(ui->label_13,11,0);
    layout->addWidget(ui->lineEdit_12,11,1);

    layout->addWidget(ui->label_5,12,0);
    layout->addWidget(ui->lineEdit_5,12,1);
    layout->addWidget(ui->process_customer_record,13,0,1,0);
    this->setLayout(layout);
}

Form_Customer::~Form_Customer(){
    delete ui;
}

void Form_Customer::fill_employees(){
    QSqlQuery qr2 = myDB.executeQuery("SELECT * FROM employees");
    vector<int> cols{2, 1};
    int row = 1;
    ui->comboBox->clear();
    for(int i=1; i<=qr2.size(); i++){
        QString responsibleEmployee = myDB.getCells(qr2, row, cols);
        ui->comboBox->addItem(responsibleEmployee);
    }
}

void Form_Customer::on_show(){
    ui->process_customer_record->setText(get_mode(mode));
    fill_employees();

    if(mode == ADD){
        qr = myDB.executeQuery("SELECT MAX(CONVERT(customerNumber, UNSIGNED INTEGER)) FROM customers");
        vector<int> cols{0};
        cols.push_back(0);
        int row = 1;
        int n = myDB.getCells(qr, row, cols).toInt() + 1;
        ui->lineEdit->setText(QString::number(n));
    }
    else if(mode == UPDATE || mode == DELETE){
        qr = myDB.executeQuery("select * from customers");
        qr.next();
        populate_window();
    }
}

void Form_Customer::populate_window(){
    ui->lineEdit->setText(qr.value(0).toString());
    ui->lineEdit_2->setText(qr.value(1).toString());
    ui->lineEdit_3->setText(qr.value(2).toString());
    ui->lineEdit_4->setText(qr.value(3).toString());
    ui->lineEdit_6->setText(qr.value(4).toString());
    ui->lineEdit_7->setText(qr.value(5).toString());
    ui->lineEdit_8->setText(qr.value(6).toString());
    ui->lineEdit_9->setText(qr.value(7).toString());
    ui->lineEdit_10->setText(qr.value(8).toString());
    ui->lineEdit_11->setText(qr.value(9).toString());
    ui->lineEdit_12->setText(qr.value(10).toString());
    ui->lineEdit_5->setText(qr.value(12).toString());
    QString qs = "select CONCAT(firstName,' ',lastName) from employees where employeeNumber = " + qr.value(11).toString();
    QSqlQuery qr3 = myDB.executeQuery(qs);
    qr3.next();
    QString cName = qr3.value(0).toString();
    ui->comboBox->setCurrentText(cName);
}

void Form_Customer::keyPressEvent(QKeyEvent *event){
    if(mode == DELETE || mode == UPDATE){
        if (event->key() == Qt::Key_Up){ //next record
            if(qr.next() == NULL){
                qr.first();
                recordOnScreen = 1;
            }
            else
                recordOnScreen++;
            populate_window();
        }
        if (event->key() == Qt::Key_Down){ //previous record
            if(qr.previous() == NULL){
                qr.last();
                recordOnScreen = qr.size();
            }
            else
                recordOnScreen--;
            populate_window();
        }
    }
}

QString Form_Customer::get_mode(int m){
    if(m == ADD) { return "Add"; }
    else if(m == UPDATE) { return "Update"; }
    else if(m == DELETE) { return "Delete"; }
    return "";
}

void Form_Customer::clear_form(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->comboBox->setCurrentIndex(0);
}

void Form_Customer::refresh_query(){
    QThread::msleep(100);
    qr = myDB.executeQuery("select * from customers");
    qr.next();
    for(int i = 0; i<recordOnScreen-1; i++){ qr.next(); }
    populate_window();
}

void Form_Customer::on_process_customer_record_clicked(){
    QString queryString;
    QString employeeNumber;

    if( mode == ADD ){
        //get selected employee number
        QSqlQuery qr2 = myDB.executeQuery("SELECT * FROM employees");
        vector<int> cols{0};
        QString empNum = myDB.getCells(qr2, ui->comboBox->currentIndex()+1, cols);
        queryString ="insert into customers (customerNumber, customerName, contactLastName, \
            contactFirstName, creditLimit, phone, addressLine1, addressLine2, city, state, \
            postalCode, salesRepEmployeeNumber, country) values (";
        queryString.append(ui->lineEdit->text() + ",");
        queryString.append("'" + ui->lineEdit_2->text() + "',");
        queryString.append("'" + ui->lineEdit_3->text() + "',");
        queryString.append("'" + ui->lineEdit_4->text() + "',");
        queryString.append("'" + ui->lineEdit_5->text() + "',");
        queryString.append("'" + ui->lineEdit_6->text() + "',");
        queryString.append("'" + ui->lineEdit_7->text() + "',");
        queryString.append("'" + ui->lineEdit_8->text() + "',");
        queryString.append("'" + ui->lineEdit_9->text() + "',");
        queryString.append("'" + ui->lineEdit_10->text() + "',");
        queryString.append("'" + ui->lineEdit_11->text() + "',");
        queryString.append(empNum);
        queryString.append(",'" + ui->lineEdit_12->text() + "')");
        myDB.executeQuery(queryString);
        clear_form();
        ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt() + 1));
    }
    else if( mode == UPDATE ){
        queryString = "UPDATE customers SET ";
        queryString.append("customerName = '" + ui->lineEdit_2->text() + "', ");
        queryString.append("contactLastName = '" + ui->lineEdit_3->text() + "', ");
        queryString.append("contactFirstName = '" + ui->lineEdit_4->text() + "', ");
        queryString.append("phone = '" + ui->lineEdit_6->text() + "', ");
        queryString.append("addressLine1 = '" + ui->lineEdit_7->text() + "', ");
        queryString.append("addressLine2 = '" + ui->lineEdit_8->text() + "', ");
        queryString.append("city = '" + ui->lineEdit_9->text() + "', ");
        queryString.append("state = '" + ui->lineEdit_10->text() + "', ");
        queryString.append("postalCode = '" + ui->lineEdit_11->text() + "', ");
        queryString.append("country = '" + ui->lineEdit_12->text() + "', ");
        queryString.append("salesRepEmployeeNumber = '" + employeeNo + "', ");
        queryString.append("creditLimit = '" + ui->lineEdit_5->text() + "' ");
        queryString.append("where customerNumber = " + ui->lineEdit->text());
        myDB.executeQuery(queryString);
        refresh_query();
    }
    else if( mode == DELETE ){
        QString orderNumber;
        queryString = "select orderNumber from orders where customerNumber = " + ui->lineEdit->text();
        //qDebug()<<queryString;
        QSqlQuery qr5 = myDB.executeQuery(queryString);
        int rowCount = qr5.size();
        for(int row=1; row<=rowCount; row++){
            qr5.next();
            orderNumber = qr5.value(0).toString();
            queryString = "delete from orderdetails where orderNumber = " + orderNumber;
            myDB.executeQuery(queryString);
            //qDebug() << queryString;
            queryString = "delete from orders where orderNumber = " + orderNumber;
            myDB.executeQuery(queryString);
            //qDebug() << queryString;
        }
        queryString = "DELETE FROM payments WHERE customerNumber = " + ui->lineEdit->text();
        //qDebug()<<queryString;
        myDB.executeQuery(queryString);
        queryString = "DELETE FROM customers WHERE customerNumber = " + ui->lineEdit->text();
        //qDebug()<<queryString;
        myDB.executeQuery(queryString);
        recordOnScreen--;
        refresh_query();
    }
}

void Form_Customer::on_comboBox_currentIndexChanged(int index){
    QString str = ui->comboBox->currentText();
    QStringList list = str.split(" ");
    QString name = list.value(0);
    QString last = list.value(1);
    QString qs = "select employeeNumber from employees where firstName = '" + name + "' and lastName = '" + last + "'";
    QSqlQuery qr5 = myDB.executeQuery(qs);
    qr5.next();
    employeeNo = qr5.value(0).toString();
}
