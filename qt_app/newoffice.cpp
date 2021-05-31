#include "newoffice.h"
#include "ui_newoffice.h"

NewOffice::NewOffice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOffice)
{
    ui->setupUi(this);
}

NewOffice::~NewOffice()
{
    delete ui;
}
