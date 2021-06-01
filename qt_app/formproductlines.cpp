#include "formproductlines.h"
#include "ui_formproductlines.h"

FormProductLines::FormProductLines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormProductLines)
{
    ui->setupUi(this);
}

FormProductLines::~FormProductLines()
{
    delete ui;
}
