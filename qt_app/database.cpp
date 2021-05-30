/**
 * @file   color.cpp
 * @author Mehmet Rıza Öz - mehmetrizaoz@gmail.com
 * @brief  color class implementation
 * @date   13.05.2021
*/

#include "QMessageBox"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include "QDebug"
#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QTextStream>
#include "dialog.h"
#include "database.h"

QSqlDatabase db;

bool database::connect(QString hostName, QString database, QString user, QString psw ){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("classicmodels");
    db.setUserName("root");
    db.setPassword("Asd.1234");
    return db.open();
}

QString database::readQuery(QString filename){
    QFile file(filename);
    if(!file.open(QFile::ReadOnly |
                  QFile::Text)){
        qDebug() << " Could not open the file for reading";
        return "";
    }
    QTextStream in(&file);
    QString myText = in.readAll();
    file.close();
    return myText;
}

void database::execQuery(QString queryString, QTableWidget *tableWidget){
    QSqlQuery query(db);
    query.prepare(readQuery(queryString));
    query.exec();

    if(tableWidget != nullptr){
        int columnCount = query.record().count();
        int rowCount = query.size();

        tableWidget->setRowCount(rowCount);
        tableWidget->setColumnCount(columnCount);

        for(int row=0; row<rowCount; row++){
           query.next();
           for(int col=0; col<columnCount; col++){
              QTableWidgetItem *pCell = tableWidget->item(row, col);
              pCell = new QTableWidgetItem;
              tableWidget->setItem(row, col, pCell);
              pCell->setText(query.value(col).toString());
           }
        }
    }

}

database::database(){}

