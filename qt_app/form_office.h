#ifndef FORM_OFFICE_H
#define FORM_OFFICE_H

#include <QDialog>

namespace Ui {
class Form_Office;
}

class Form_Office : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Office(QWidget *parent = nullptr);
    ~Form_Office();

private:
    Ui::Form_Office *ui;
};

#endif // FORM_OFFICE_H
