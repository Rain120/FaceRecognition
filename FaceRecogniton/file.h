#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QByteArray>
#include <QDebug>
#include <QTextStream>
#include <QDir>
#include <connectpool.h>

class MyFILE: public QObject
{
    Q_OBJECT
public:
    MyFILE(QObject *parent = 0);
    QString who[10];  //姓名
    int whoLable[10];   //标号
    void CreateFile(QString fileName);
    int GetMaxNum(QString path);
    void AddPeople(QString path, QString text);   //添加用户到data文件里的people.txt
    void MakecsvFile(); //生成csv.txt文件
    void getManLabel();

    void setMainCP(const ConnectPool &value);


private:
    int MaxNumAboutPeople;
    ConnectPool mainCP;
    QDir *PicFile;    //创建文件夹
};

#endif // FILE_H
