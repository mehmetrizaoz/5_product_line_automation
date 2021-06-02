#include "form_login.h"
#include "ui_form_login.h"
#include <QGridLayout>

Form_Login::Form_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Login)
{
    ui->setupUi(this);
    this->setFixedSize(278,131);
    this->setWindowTitle("Login");
}

Form_Login::~Form_Login()
{
    delete ui;
}
