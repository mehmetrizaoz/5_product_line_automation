#include "form_office.h"
#include "ui_form_office.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QString>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>
#include "database.h"

Form_Office::Form_Office(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Office)
{
    ui->setupUi(this);
    this->setWindowTitle("Office");
    myDB = database();
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
    layout->addWidget(ui->lineEdit_6,5,1);
    layout->addWidget(ui->label_7,6,0);
    layout->addWidget(ui->lineEdit_7,6,1);
    layout->addWidget(ui->label_8,7,0);
    layout->addWidget(ui->lineEdit_8,7,1);
    layout->addWidget(ui->label_9,8,0);
    layout->addWidget(ui->lineEdit_9,8,1);
    layout->addWidget(ui->add_office,9,0,1,0);
    this->setLayout(layout);
}

Form_Office::~Form_Office()
{
    delete ui;
}

void Form_Office::on_show()
{
    QSqlQuery qr = myDB.executeQuery("SELECT MAX(CONVERT(officeCode,UNSIGNED INTEGER)) FROM offices");
    int n = myDB.getCell(qr, 1, 0).toInt() + 1;
    ui->lineEdit->setText(QString::number(n));
}

void Form_Office::on_add_office_clicked()
{
    QString queryString = "insert into `offices`(`officeCode`,`city`,`phone`,`addressLine1`,`addressLine2`,`state`,`country`,`postalCode`,`territory`) values (";
    queryString.append("'" + ui->lineEdit->text()   + "',");
    queryString.append("'" + ui->lineEdit_2->text() + "',");
    queryString.append("'" + ui->lineEdit_3->text() + "',");
    queryString.append("'" + ui->lineEdit_4->text() + "',");
    queryString.append("'" + ui->lineEdit_5->text() + "',");
    queryString.append("'" + ui->lineEdit_6->text() + "',");
    queryString.append("'" + ui->lineEdit_7->text() + "',");
    queryString.append("'" + ui->lineEdit_8->text() + "',");
    queryString.append("'" + ui->lineEdit_9->text() + "')");
    myDB.executeQuery(queryString);

    qDebug() << queryString;

    ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt() + 1));
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
}
