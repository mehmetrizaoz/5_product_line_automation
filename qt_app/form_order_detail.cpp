#include "form_order_detail.h"
#include "ui_form_order_detail.h"
#include <QVBoxLayout>
#include <QMainWindow>
#include <QDesktopWidget>

Form_Order_Detail::Form_Order_Detail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Order_Detail)
{
    ui->setupUi(this);
    this->setWindowTitle("Order Detail");
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    setStyleSheet("background-color: rgb(224,243,176)");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->label,0,0);
    layout->addWidget(ui->comboBox,0,1);
    layout->addWidget(ui->label_2,1,0);
    layout->addWidget(ui->comboBox_2,1,1);
    layout->addWidget(ui->label_3,2,0);
    layout->addWidget(ui->lineEdit,2,1);
    layout->addWidget(ui->label_4,3,0);
    layout->addWidget(ui->lineEdit_2,3,1);
    layout->addWidget(ui->label_5,4,0);
    layout->addWidget(ui->lineEdit_3,4,1);
    layout->addWidget(ui->add_order_detail,5,0,1,0);
    this->setLayout(layout);
}

Form_Order_Detail::~Form_Order_Detail()
{
    delete ui;
}

void Form_Order_Detail::on_add_order_detail_clicked()
{

}
