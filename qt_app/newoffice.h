#ifndef NEWOFFICE_H
#define NEWOFFICE_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class NewOffice;
}

class NewOffice : public QDialog
{
    Q_OBJECT

public:
    explicit NewOffice(QWidget *parent = nullptr);
    ~NewOffice();

private:
    Ui::NewOffice *ui;
};

#endif // NEWOFFICE_H
