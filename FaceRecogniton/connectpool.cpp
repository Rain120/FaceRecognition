#include "connectpool.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

ConnectPool::ConnectPool()
{}

bool ConnectPool::connet(const char *dbName)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (!db.open()) {
        qDebug() << "Database Error!";
        return false;
    }
    return true;
}

void ConnectPool::open()
{
    if(connet("fr.db")){
        qDebug() << "Database Create Sucessfully!";
    }
    else{
        qDebug() << "Database Create Failed!";

    }
}

void ConnectPool::createTable(QString tableCreateSQL)
{
    QSqlQuery sql_query;
    QString create_sql = "create table if not exists  " +  tableCreateSQL;
    qDebug() << "create_sql:" << create_sql;
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "createTable sql_query.lastError()";
    }
    else
    {
        qDebug() << "table created!";
    }
}

void ConnectPool::insertData(QString insertSQL, int id, QString name)
{
    QSqlQuery sql_query;
    QString insert_sql = "insert into " + insertSQL;
    qDebug() << "insert_sql:" << insert_sql;
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(id + 1);
    sql_query.addBindValue(name);
    if(!sql_query.exec())
    {
        qDebug() << "insertData sql_query.lastError()";
    }
    else
    {
        qDebug() << "inserted";
    }
}

void ConnectPool::insertPath(QString insertSQL, int id, int userid, QString name)
{
    QSqlQuery sql_query;
    QString insert_sql = "insert into " + insertSQL;
    qDebug() << "insert_sql:" << insert_sql;
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(id + 1);
    sql_query.addBindValue(userid);
    sql_query.addBindValue(name);
    if(!sql_query.exec())
    {
        qDebug() << "insertData sql_query.lastError()";
    }
    else
    {
        qDebug() << "inserted";
    }
}

void ConnectPool::closeSQL()
{
    db.close();
}

