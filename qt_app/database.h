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

using namespace std;

class database{
public:
   database();
   void execQuery(QString queryString, QTableWidget *tableWidget);
   bool connect(QString hostName, QString database, QString user, QString psw );
   QString readQuery(QString filename);

   void disconnect();
private:
   QString _hostName;
   QString _userName;
   QString _database;
   QString _password;

};
