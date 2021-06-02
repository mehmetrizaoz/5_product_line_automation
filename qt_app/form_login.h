#ifndef FORM_LOGIN_H
#define FORM_LOGIN_H

#include <QWidget>

namespace Ui {
class Form_Login;
}

class Form_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Login(QWidget *parent = nullptr);
    ~Form_Login();

private:
    Ui::Form_Login *ui;
};

#endif // FORM_LOGIN_H
