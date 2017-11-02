#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTextCodec>
#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("FaceRecognition--Rainy"));
    this->setMaximumSize(350,300);
    this->setMinimumSize(350,300);

    connect(ui->addPhotos,SIGNAL(clicked()),this,SLOT(onAddTriggered()),Qt::UniqueConnection);
    connect(ui->dispose,SIGNAL(clicked()),this,SLOT(onDisposeTriggered()),Qt::UniqueConnection);
    connect(ui->addCSV,SIGNAL(clicked()),this,SLOT(onAddcsvTriggered()),Qt::UniqueConnection);
    connect(ui->trainingModel,SIGNAL(clicked()),this,SLOT(onTrainnigmodelTriggered()),Qt::UniqueConnection);
    connect(ui->faceRecognition,SIGNAL(clicked()),this,SLOT(onFacerecognitionTriggered()),Qt::UniqueConnection);
}

Widget::~Widget()
{
    delete ui;
}
/****
 *    相机拍照
 ***/
void Widget::onAddTriggered()
{
    addpeople.show();
}
/****
 *    照片处理
 ***/
void Widget::onDisposeTriggered()
{
    addpeople.disposePic();
}
/****
 *    增加CSV
 ***/
void Widget::onAddcsvTriggered()
{
    addpeople.AddCSV();
}
/****
 *    模型训练
 ***/
void Widget::onTrainnigmodelTriggered()
{
    addpeople.TrainingModel();
}
/****
 *    人脸识别
 ***/
void Widget::onFacerecognitionTriggered()
{
    int label = 0;
    addpeople.file.getManLabel();
    double confidence = 0.0;
    cv::VideoCapture cap(0);    //打开默认摄像头
    if (!cap.isOpened())
    {
        QMessageBox::warning(this,tr("错误"),tr("摄像头打开失败"),QMessageBox::Ok);
        return;
    }
    cv::Mat frame;
    cv::Mat gray;

    qDebug() << "Being recognized";

    cv::CascadeClassifier cascade;
    bool stop = false;
    //训练好的文件名称，放置在可执行文件同目录下
    cascade.load("./haarcascades/haarcascade_frontalface_alt.xml");

    cv::Ptr<cv::FaceRecognizer> modelPCA = cv::createEigenFaceRecognizer();
    modelPCA->load("MyFacePCAModel.xml");
    int sl = 0;
    while (!stop)
    {
        cap >> frame;

        //建立用于存放人脸的向量容器
        std::vector<cv::Rect> faces(0);

        cv::cvtColor(frame, gray, CV_BGR2GRAY);
        //改变图像大小，使用双线性差值
//        cv::resize(gray, smallImg, smallImg.size(), 0, 0, cv::INTER_LINEAR);
        //变换后的图像进行直方图均值化处理
        cv::equalizeHist(gray, gray);

        cascade.detectMultiScale(gray, faces,
                                 1.1, 2,cv::CASCADE_FIND_BIGGEST_OBJECT|cv::CASCADE_DO_ROUGH_SEARCH,
                                 cv::Size(30, 30));

        cv::Mat face;
        cv::Point text_lb;

        for (size_t i = 0; i < faces.size(); i++)
        {
            if (faces[i].height > 0 && faces[i].width > 0)
            {
                face = gray(faces[i]);
                text_lb = cv::Point(faces[i].x, faces[i].y);
                cv::rectangle(frame, faces[i], cv::Scalar(255, 0, 0), 1, 8, 0);
            }
        }

        cv::Mat face_test;

        int predictPCA = 0;
        if (face.rows >= 120)
        {
            cv::resize(face, face_test, cv::Size(92, 112));

        }

        if (!face_test.empty())
        {
            //测试图像应该是灰度图
            int predictedLabel = -1;
            predictPCA = modelPCA->predict(face_test);
            modelPCA->predict(face_test,predictedLabel,confidence);
            qDebug() << "predictedLabel:" << predictedLabel;
            qDebug() << "confidence:" << confidence;
            qDebug() << "s1:" << sl;

        }
        if(sl > 20)
        {
            cv::destroyWindow("FaceReconition");
            if(label < 5) {
                QMessageBox::information(this,tr("失败"),tr("人脸库无此人"),QMessageBox::Ok);
            }
            else {
                QMessageBox::information(this,tr("失败"),tr("人脸确认度低"),QMessageBox::Ok);
            }
            cap.release();
            return;
        }
        if(confidence < 2000) {
            label++;
        }
        qDebug()<<"label:" << label;
        cv::waitKey(50);
        if(label > 12)
        {
            cv::destroyWindow("FaceReconition");
            qDebug() << "predictPCA" << predictPCA;
            std::string nameStr = "Being recognized";
            cv::putText(frame, nameStr, text_lb, cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255));
            qDebug() << "姓名:" << addpeople.file.who[predictPCA];
            qDebug() << "学号:" << addpeople.file.whoLable[predictPCA];
            QString recognition = "Hello! ";
//            recognition += addpeople.file.who[predictPCA] + "\n你的学号是:" + addpeople.file.whoLable[predictPCA];
            recognition.append(addpeople.file.who[predictPCA]);

            qDebug() << recognition;
            QMessageBox::information(this, tr("识别成功"), recognition, QMessageBox::Ok);
            cap.release();
            return;
        }
        sl++;

        imshow("FaceReconition", frame);
        if (cv::waitKey(50) >= 0) {
            stop = true;
        }
    }
}


