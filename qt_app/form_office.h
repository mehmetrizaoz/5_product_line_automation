#ifndef FORM_OFFICE_H
#define FORM_OFFICE_H

#include <QDialog>
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
public slots:
    void on_show();
private slots:
    void on_add_office_clicked();

private:
    Ui::Form_Office *ui;
};

#endif // FORM_OFFICE_H
