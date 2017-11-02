#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QLabel>
#include <QProcess>
#include <QMessageBox>
#include <math.h>
#include "addpeople.h"
#include "file.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void onAddTriggered();     //添加图库

    void onDisposeTriggered();

    void onAddcsvTriggered();

    void onTrainnigmodelTriggered();

    void onFacerecognitionTriggered();

private:
    Ui::Widget *ui;
    Addpeople addpeople;    //添加图库界面
    MyFILE file;  //文件操作
};

#endif // WIDGET_H
