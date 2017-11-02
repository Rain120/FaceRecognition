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

void ConnectPool::createTable()
{
    QSqlQuery sql_query;
    QString create_sql = "create table if not exist stu (id int primary key, name varchar(30), age int)";
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

void ConnectPool::insertData(int id, QString name,int age)
{
    QSqlQuery sql_query;
    QString insert_sql = "insert into stu values (?, ?, ?)";
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(id + 1);
    sql_query.addBindValue(name);
    sql_query.addBindValue(age);
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
