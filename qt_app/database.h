/**
 * @file   color.h
 * @author Mehmet Rıza Öz - mehmetrizaoz@gmail.com
 * @brief  color class used for agent, path, wall etc. color
 * @date   13.05.2021
*/

#pragma once

#include <QString>
#include <QSqlQuery>
#include "QMessageBox"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QString>
#include <QSqlError>
#include "QDebug"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTableWidget>
#include <vector>

using namespace std;

class database{
public:
   database();
   bool connect(QString hostName, QString database, QString user, QString psw );
   void disconnect();
   QSqlQuery executeQuery(QString qr);
   void fillTable(QSqlQuery query, QTableWidget *tableWidget);
   QString readFile(QString filename);
   QString getCells(QSqlQuery query, int nth_record, vector<int> cols);
private:

};
