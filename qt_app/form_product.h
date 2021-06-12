#ifndef FORM_PRODUCT_H
#define FORM_PRODUCT_H

#include <QDialog>
#include "database.h"

namespace Ui {
class Form_Product;
}

class Form_Product : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Product(QWidget *parent = nullptr);
    ~Form_Product();    
    database myDB;
public slots:
    void on_show();
private slots:
    void on_add_product_clicked();

private:
    Ui::Form_Product *ui;
};

#endif // FORM_PRODUCT_H
