#ifndef FORM_QUERYRESULT_H
#define FORM_QUERYRESULT_H

#include <QDialog>

namespace Ui {
class Form_QueryResult;
}

class Form_QueryResult : public QDialog
{
    Q_OBJECT

public:
    explicit Form_QueryResult(QWidget *parent = nullptr);
    ~Form_QueryResult();
    QString password;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form_QueryResult *ui;
};

#endif // FORM_QUERYRESULT_H
