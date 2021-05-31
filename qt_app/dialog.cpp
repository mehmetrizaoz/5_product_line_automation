#include "dialog.h"
#include "ui_dialog.h"
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->tableWidget,0,0,1,0);
    layout->addWidget(ui->pushButton,1,0);
    layout->addWidget(ui->lineEdit,1,1);
    this->setLayout(layout);
    setWindowTitle(tr("List of all Customers"));

    this->setStyleSheet("background-color: rgb(123, 204, 181)");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
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
