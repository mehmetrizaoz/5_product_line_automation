#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include <QTextEdit>
#include "form_login.h"
#include "form_office.h"
#include "form_employee.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    database myDB;
private slots:
    void getLoginStatus();
    void on_pushButton_01_clicked();
    void on_comboBox_01_activated(int index);
    void on_comboBox_02_activated(int index);
    void on_comboBox_03_activated(int index);
    void on_comboBox_04_activated(int index);
    void on_comboBox_05_activated(int index);
    void on_comboBox_06_activated(int index);
    void on_comboBox_07_activated(int index);
private:
    Ui::MainWindow *ui;
    Form_Login    *login;
    Form_Office   *office;
    Form_Employee *emp;

    QString fileName;
    QSqlQuery qr;
};

#endif // MAINWINDOW_H
