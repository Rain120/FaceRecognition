/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *addPhotos;
    QPushButton *dispose;
    QPushButton *addCSV;
    QPushButton *trainingModel;
    QPushButton *faceRecognition;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        Widget->setStyleSheet(QStringLiteral(""));
        addPhotos = new QPushButton(Widget);
        addPhotos->setObjectName(QStringLiteral("addPhotos"));
        addPhotos->setGeometry(QRect(30, 20, 149, 28));
        addPhotos->setStyleSheet(QLatin1String("    margin-left: 10px;\n"
"    border-image: none;\n"
"    border-radius: 14px;\n"
"    border-style: solid;\n"
"    border-width: 1px;\n"
"    font-size: 14px;\n"
"    line-height: 20px;\n"
"    margin-bottom: 0;\n"
"    padding: 4px 12px;\n"
"    text-align: center;\n"
"    background-color: #006DCC;\n"
"    color: #FFF;"));
        dispose = new QPushButton(Widget);
        dispose->setObjectName(QStringLiteral("dispose"));
        dispose->setGeometry(QRect(180, 70, 149, 28));
        dispose->setStyleSheet(QLatin1String("    margin-left: 10px;\n"
"    border-image: none;\n"
"    border-radius: 14px;\n"
"    border-style: solid;\n"
"    border-width: 1px;\n"
"    font-size: 14px;\n"
"    line-height: 20px;\n"
"    margin-bottom: 0;\n"
"    padding: 4px 12px;\n"
"    text-align: center;\n"
"    background-color: #006DCC;\n"
"    color: #FFF;"));
        addCSV = new QPushButton(Widget);
        addCSV->setObjectName(QStringLiteral("addCSV"));
        addCSV->setGeometry(QRect(40, 130, 149, 28));
        addCSV->setStyleSheet(QLatin1String("    margin-left: 10px;\n"
"    border-image: none;\n"
"    border-radius: 14px;\n"
"    border-style: solid;\n"
"    border-width: 1px;\n"
"    font-size: 14px;\n"
"    line-height: 20px;\n"
"    margin-bottom: 0;\n"
"    padding: 4px 12px;\n"
"    text-align: center;\n"
"    background-color: #006DCC;\n"
"    color: #FFF;"));
        trainingModel = new QPushButton(Widget);
        trainingModel->setObjectName(QStringLiteral("trainingModel"));
        trainingModel->setGeometry(QRect(180, 200, 149, 28));
        trainingModel->setStyleSheet(QLatin1String("    margin-left: 10px;\n"
"    border-image: none;\n"
"    border-radius: 14px;\n"
"    border-style: solid;\n"
"    border-width: 1px;\n"
"    font-size: 14px;\n"
"    line-height: 20px;\n"
"    margin-bottom: 0;\n"
"    padding: 4px 12px;\n"
"    text-align: center;\n"
"    background-color: #006DCC;\n"
"    color: #FFF;"));
        faceRecognition = new QPushButton(Widget);
        faceRecognition->setObjectName(QStringLiteral("faceRecognition"));
        faceRecognition->setGeometry(QRect(20, 250, 149, 28));
        faceRecognition->setStyleSheet(QLatin1String("    margin-left: 10px;\n"
"    border-image: none;\n"
"    border-radius: 14px;\n"
"    border-style: solid;\n"
"    border-width: 1px;\n"
"    font-size: 14px;\n"
"    line-height: 20px;\n"
"    margin-bottom: 0;\n"
"    padding: 4px 12px;\n"
"    text-align: center;\n"
"    background-color: #006DCC;\n"
"    color: #FFF;"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        addPhotos->setText(QApplication::translate("Widget", "1\343\200\201\346\267\273\345\212\240\347\205\247\347\211\207", Q_NULLPTR));
        dispose->setText(QApplication::translate("Widget", "2\343\200\201\347\205\247\347\211\207\345\244\204\347\220\206", Q_NULLPTR));
        addCSV->setText(QApplication::translate("Widget", "3\343\200\201\345\242\236\345\212\240CSV", Q_NULLPTR));
        trainingModel->setText(QApplication::translate("Widget", "4\343\200\201\346\250\241\345\236\213\350\256\255\347\273\203", Q_NULLPTR));
        faceRecognition->setText(QApplication::translate("Widget", "5\343\200\201\344\272\272\350\204\270\350\257\206\345\210\253", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
