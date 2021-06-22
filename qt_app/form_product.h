#ifndef FORM_PRODUCT_H
#define FORM_PRODUCT_H

#define ADD    0
#define DELETE 1
#define UPDATE 2

#include <QDialog>
#include <QKeyEvent>
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
    int mode = 0;
public slots:
    void on_show();
private slots:
    void on_process_product_recor_clicked();
private:
    QSqlQuery qr;
    Ui::Form_Product *ui;
    int recordOnScreen = 1;
    void fill_product_line_combo_box();
    void clear_form();
    QString get_mode(int m);
    void refresh_query();
    void populate_window();
    void keyPressEvent(QKeyEvent *event);
};

#endif // FORM_PRODUCT_H
