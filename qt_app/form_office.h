#ifndef FORM_OFFICE_H
#define FORM_OFFICE_H

#define INSERT 0
#define UPDATE 2
#define DELETE 1

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
    database myDB;
    int mode = 0;
    QSqlQuery qr;
    void fill_form_with_query_result();
    void clear_form();
public slots:
    void on_show();
private slots:
    void on_process_office_record_clicked();
private:
    Ui::Form_Office *ui;
protected:
    void keyPressEvent(QKeyEvent * e);
};

#endif // FORM_OFFICE_H
