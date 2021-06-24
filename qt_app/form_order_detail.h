#ifndef FORM_ORDER_DETAIL_H
#define FORM_ORDER_DETAIL_H

#define ADD    0
#define DELETE 1
#define UPDATE 2

#include <QKeyEvent>
#include <QDialog>
#include "database.h"

namespace Ui {
class Form_Order_Detail;
}

class Form_Order_Detail : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Order_Detail(QWidget *parent = nullptr);
    ~Form_Order_Detail();
    database myDB;
    int mode = 0;
public slots:
    void on_show();
private slots:
    void on_add_order_detail_clicked();
    void on_process_order_detail_record_clicked();

private:
    Ui::Form_Order_Detail *ui;
    QSqlQuery qr;
    int recordOnScreen = 1;
    QString get_mode(int m);
    void populate_window();
    void clear_form();
    void refresh_query();
    void fill_combo_products_combo_box();
    void fill_combo_orders_combo_box();
    void keyPressEvent(QKeyEvent * e);
};

#endif // FORM_ORDER_DETAIL_H
