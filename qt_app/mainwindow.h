#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include <QTextEdit>
#include "form_login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:    
    void on_comboBox_01_activated(int index);
    void on_pushButton_01_clicked();
    void getLoginStatus();
    void on_comboBox_02_activated(int index);

    void on_comboBox_03_activated(int index);

private:
    Ui::MainWindow *ui;
    Form_Login *login;    
};

#endif // MAINWINDOW_H
