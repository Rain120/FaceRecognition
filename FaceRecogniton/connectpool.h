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
    void open();
    void createTable(QString tableCreateSQL);
    void insertData(QString insertSQL, int id, QString name);
    void insertPath(QString insertSQL, int id, int userid, QString name);
    void selectData();
    void deleteData();
    void closeSQL();

private:
    QSqlDatabase db;
};

#endif // CONNECTPOOL_H
