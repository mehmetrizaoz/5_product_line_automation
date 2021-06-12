#ifndef FORM_PRODUCTLINES_H
#define FORM_PRODUCTLINES_H

#include <QDialog>
#include "database.h"

namespace Ui {
class Form_ProductLines;
}

class Form_ProductLines : public QDialog
{
    Q_OBJECT

public:
    explicit Form_ProductLines(QWidget *parent = nullptr);
    ~Form_ProductLines();
    database myDB;
public slots:
    void on_show();
private slots:
    void on_pushButton_1_clicked();

private:
    Ui::Form_ProductLines *ui;
};

#endif // FORM_PRODUCTLINES_H
