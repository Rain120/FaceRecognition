#ifndef ADDPEOPLE_H
#define ADDPEOPLE_H

#include <QDialog>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "file.h"

namespace Ui {
class Addpeople;
}

class Addpeople : public QDialog
{
    Q_OBJECT

public:
    explicit Addpeople(QWidget *parent = 0);
    ~Addpeople();
    void disposePic();  //处理图片 ROI区域
    void AddCSV();      //增添CSV信息
    void TrainingModel();    //训练模型
    MyFILE file;

    void setAddCp(const ConnectPool &value);

private slots:
    void onTakeapotobtnClicked();

private:
    Ui::Addpeople *ui;
    cv::Mat frame;
    cv::VideoCapture *capture;
    int MaxNumAboutPeople;  
    ConnectPool addCp;

    void detectAndDisplay(QString source,QString target);

    static cv::Mat norm_0_255(cv::InputArray _src);

    //使用CSV文件去读图像和标签,主要使用stringstream和getline方法
    static void read_csv(const std::string& filename, std::vector<cv::Mat>& images, std::vector<int>& labels);
};

#endif // ADDPEOPLE_H
