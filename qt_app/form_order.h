#ifndef FORM_ORDER_H
#define FORM_ORDER_H

#include <QDialog>

namespace Ui {
class Form_Order;
}

class Form_Order : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Order(QWidget *parent = nullptr);
    ~Form_Order();

private slots:
    void on_add_office_clicked();

private:
    Ui::Form_Order *ui;
};

#endif // FORM_ORDER_H
