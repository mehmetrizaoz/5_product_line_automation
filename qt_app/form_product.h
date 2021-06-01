#ifndef FORM_PRODUCT_H
#define FORM_PRODUCT_H

#include <QDialog>

namespace Ui {
class Form_Product;
}

class Form_Product : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Product(QWidget *parent = nullptr);
    ~Form_Product();

private:
    Ui::Form_Product *ui;
};

#endif // FORM_PRODUCT_H
