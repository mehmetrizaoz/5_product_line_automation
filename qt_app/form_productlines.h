#ifndef FORM_PRODUCTLINES_H
#define FORM_PRODUCTLINES_H

#define ADD    0
#define DELETE 1
#define UPDATE 2

#include <QDialog>
#include <QKeyEvent>
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
    int mode = 0;
public slots:
    void on_show();
private slots:
    void on_process_product_line_record_clicked();
private:
    QSqlQuery qr;
    int recordOnScreen = 1;
    Ui::Form_ProductLines *ui;
    QString get_mode(int m);
    void clear_form();
    void keyPressEvent(QKeyEvent *event);
    void populate_window();
    void refresh_query();
};

#endif // FORM_PRODUCTLINES_H
