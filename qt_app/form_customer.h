#ifndef FORM_CUSTOMER_H
#define FORM_CUSTOMER_H

#include <QDialog>

namespace Ui {
class Form_Customer;
}

class Form_Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Customer(QWidget *parent = nullptr);
    ~Form_Customer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form_Customer *ui;
};

#endif // FORM_CUSTOMER_H
