#ifndef FORM_ORDER_DETAIL_H
#define FORM_ORDER_DETAIL_H

#include <QDialog>

namespace Ui {
class Form_Order_Detail;
}

class Form_Order_Detail : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Order_Detail(QWidget *parent = nullptr);
    ~Form_Order_Detail();

private slots:
    void on_add_order_detail_clicked();

private:
    Ui::Form_Order_Detail *ui;
};

#endif // FORM_ORDER_DETAIL_H
