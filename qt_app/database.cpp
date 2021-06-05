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
#include "database.h"

QSqlDatabase db;

bool database::connect(QString hostName, QString database, QString user, QString psw ){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(psw);
    _hostName = hostName;
    _database = database;
    _userName = user;
    _password = psw;
    qDebug()<<"connecting";
    return db.open();
}

void database::disconnect(){
    qDebug()<<"disconnecting";
    db.close();
    qDebug()<<"disconnected";
}

QString database::readQuery(QString filename){
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << " Could not open the file for reading";
        return "";
    }
    QTextStream in(&file);
    QString myText = in.readAll();
    file.close();
    return myText;
}



void database::fillTableWithQueryResult(QString queryString, QTableWidget *tableWidget){
    QSqlQuery query(db);
    query.prepare(readQuery(queryString));
    query.exec();

    int columnCount = query.record().count();
    int rowCount = query.size();
    tableWidget->setRowCount(rowCount+1); //+1 is for column headers
    tableWidget->setColumnCount(columnCount);

    QFont font;
    font.setBold(true);

    //add column names to the table
    QSqlRecord record = query.record();//db.record("table_name");
    for(int i = 0; i < record.count(); i++){
       QTableWidgetItem *pCell = new QTableWidgetItem;
       tableWidget->setItem(0, i, pCell);
       tableWidget->item(0, i)->setFont(font);
       tableWidget->item(0, i)->setForeground(QBrush(QColor(255, 0, 0)));
       pCell->setText(record.fieldName(i));
    }

    //fill table with query result
    for(int row=1; row<=rowCount; row++){
       query.next();
       for(int col=0; col<columnCount; col++){
          QTableWidgetItem *pCell = new QTableWidgetItem;
          tableWidget->setItem(row, col, pCell);
          pCell->setText(query.value(col).toString());
       }
    }
}

database::database(){}

