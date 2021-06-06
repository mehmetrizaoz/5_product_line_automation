#include "form_productlines.h"
#include "ui_form_productlines.h"
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>

Form_ProductLines::Form_ProductLines(QWidget *parent) :
    QDialog(parent), ui(new Ui::Form_ProductLines)
{
    ui->setupUi(this);
    this->setWindowTitle("Product Line");
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
    layout->addWidget(ui->pushButton_1,9,0,1,0);
    this->setLayout(layout);
}

Form_ProductLines::~Form_ProductLines()
{
    delete ui;
}

void Form_ProductLines::on_pushButton_1_clicked()
{
    QString queryString = "insert into `productlines`(`productLine`,`textDescription`,`htmlDescription`,`image `)";
    queryString.append("values ('"   + ui->lineEdit->text()   + "','" + ui->lineEdit_2->text());
    queryString.append("','" + ui->lineEdit_3->text() + "', NULL )");
    myDB.executeQuery(queryString);
}



