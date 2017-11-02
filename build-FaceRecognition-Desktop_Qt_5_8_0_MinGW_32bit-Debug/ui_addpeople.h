/********************************************************************************
** Form generated from reading UI file 'addpeople.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPEOPLE_H
#define UI_ADDPEOPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Addpeople
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *NamelineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *TakeAPotoBtn;

    void setupUi(QDialog *Addpeople)
    {
        if (Addpeople->objectName().isEmpty())
            Addpeople->setObjectName(QStringLiteral("Addpeople"));
        Addpeople->resize(392, 53);
        layoutWidget = new QWidget(Addpeople);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 372, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        NamelineEdit = new QLineEdit(layoutWidget);
        NamelineEdit->setObjectName(QStringLiteral("NamelineEdit"));

        horizontalLayout->addWidget(NamelineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        TakeAPotoBtn = new QPushButton(layoutWidget);
        TakeAPotoBtn->setObjectName(QStringLiteral("TakeAPotoBtn"));
        TakeAPotoBtn->setStyleSheet(QLatin1String("    margin-left: 10px;\n"
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

        horizontalLayout->addWidget(TakeAPotoBtn);


        retranslateUi(Addpeople);

        QMetaObject::connectSlotsByName(Addpeople);
    } // setupUi

    void retranslateUi(QDialog *Addpeople)
    {
        Addpeople->setWindowTitle(QApplication::translate("Addpeople", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Addpeople", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        TakeAPotoBtn->setText(QApplication::translate("Addpeople", "\345\274\200\345\247\213\346\213\215\347\205\247", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Addpeople: public Ui_Addpeople {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPEOPLE_H
