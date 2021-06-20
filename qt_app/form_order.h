#ifndef FORM_ORDER_H
#define FORM_ORDER_H

#define ADD    0
#define DELETE 1
#define UPDATE 2

#include <QDialog>
#include "database.h"

namespace Ui {
class Form_Order;
}

class Form_Order : public QDialog{
    Q_OBJECT
public:
    explicit Form_Order(QWidget *parent = nullptr);
    ~Form_Order();    
    int mode = 0;
public slots:
    void on_show();
private slots:
    void on_process_order_record_clicked();
private:
    Ui::Form_Order *ui;
    database myDB;
    QSqlQuery qr;
    int recordOnScreen = 1;
    QString get_mode(int m);
    void fill_form_with_query_result();
    void clear_form();
    void refresh_query();
    int  get_next_order_code();
    void keyPressEvent(QKeyEvent * e);
};

#endif // FORM_ORDER_H
