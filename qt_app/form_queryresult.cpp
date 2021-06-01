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
    this->setLayout(layout);
    setWindowTitle(tr("List of all Customers"));

    this->setStyleSheet("background-color: rgb(123, 204, 181)");
    ui->tableWidget->setStyleSheet("background-color: white;");
}

Form_QueryResult::~Form_QueryResult()
{
    delete ui;
}

void Form_QueryResult::on_pushButton_clicked()
{
    database myDB = database();
    myDB.execQuery("://queries/number_of_employees_for_each_office", ui->tableWidget);
}
