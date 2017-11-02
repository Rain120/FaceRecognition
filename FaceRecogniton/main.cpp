#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "connectpool.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    ConnectPool cp;

    if(cp.connet("fr.db")){
        qDebug() << "Database Create Sucessfully!";
    }
    else{
        qDebug() << "Database Create Failed!";

    }

    cp.createTable();
    cp.insertData(0, "Jerry", 20);
    cp.closeSQL();

    w.show();

    return a.exec();
}
