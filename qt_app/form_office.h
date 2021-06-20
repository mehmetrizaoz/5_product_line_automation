#ifndef FORM_OFFICE_H
#define FORM_OFFICE_H

#define ADD    0
#define DELETE 1
#define UPDATE 2

#include <QDialog>
#include <QApplication>
#include <QKeyEvent>
#include "database.h"

namespace Ui {
class Form_Office;
}

class Form_Office : public QDialog
{
    Q_OBJECT
public:
    explicit Form_Office(QWidget *parent = nullptr);
    ~Form_Office();
    int mode = 0;
public slots:
    void on_show();
private slots:
    void on_process_office_record_clicked();
private:
    Ui::Form_Office *ui;
    QString get_mode(int m);
    void fill_form_with_query_result();
    void clear_form();
    void refresh_query();
    int  get_next_office_code();
    void keyPressEvent(QKeyEvent * e);
    database myDB;
    QSqlQuery qr;
    int recordOnScreen = 1;
};

#endif // FORM_OFFICE_H
