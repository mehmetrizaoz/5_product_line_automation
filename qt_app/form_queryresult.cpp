#include "form_queryresult.h"
#include <QVBoxLayout>
#include "ui_form_queryresult.h"
#include "database.h"

Form_QueryResult::Form_QueryResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_QueryResult)
{
    ui->setupUi(this);
    this->setWindowTitle("Query Result");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->tableWidget,0,0,1,0);
    layout->addWidget(ui->pushButton,1,0);
    layout->addWidget(ui->lineEdit,1,1);
    this->setLayout(layout);
    setWindowTitle(tr("List of all Customers"));

    this->setStyleSheet("background-color: rgb(123, 204, 181)");
    ui->tableWidget->setStyleSheet("background-color: white;");
    ui->lineEdit->setStyleSheet("background-color: white;");
}

Form_QueryResult::~Form_QueryResult()
{
    delete ui;
}

void Form_QueryResult::on_pushButton_clicked()
{
    password = ui->lineEdit->text();

    database myDB = database();
    if(myDB.connect("127.0.0.1", "classicmodels", "root", password) != false){
       myDB.execQuery("://queries/listCustomers", ui->tableWidget);
    }
    else{
       qDebug() << "cant connect to database";
    }
}
