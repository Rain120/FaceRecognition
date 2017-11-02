#ifndef CONNECTPOOL_H
#define CONNECTPOOL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

class ConnectPool
{
public:
    ConnectPool();
    bool connet(const char* dbName);
    void createTable();
    void insertData(int id, QString name, int age);
    void selectData();
    void deleteData();
    void closeSQL();
private:
    QSqlDatabase db;
};

#endif // CONNECTPOOL_H
