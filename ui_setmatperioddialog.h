/********************************************************************************
** Form generated from reading UI file 'setmatperioddialog.ui'
**
** Created: Fri Feb 28 20:02:48 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMATPERIODDIALOG_H
#define UI_SETMATPERIODDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetMatPeriodDialog
{
public:
    QPushButton *confirm_pushbutton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *maperiod_spinBox;
    QLabel *label_2;

    void setupUi(QDialog *SetMatPeriodDialog)
    {
        if (SetMatPeriodDialog->objectName().isEmpty())
            SetMatPeriodDialog->setObjectName(QString::fromUtf8("SetMatPeriodDialog"));
        SetMatPeriodDialog->resize(200, 40);
        confirm_pushbutton = new QPushButton(SetMatPeriodDialog);
        confirm_pushbutton->setObjectName(QString::fromUtf8("confirm_pushbutton"));
        confirm_pushbutton->setGeometry(QRect(140, 10, 51, 23));
        widget = new QWidget(SetMatPeriodDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 121, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        maperiod_spinBox = new QSpinBox(widget);
        maperiod_spinBox->setObjectName(QString::fromUtf8("maperiod_spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(maperiod_spinBox->sizePolicy().hasHeightForWidth());
        maperiod_spinBox->setSizePolicy(sizePolicy);
        maperiod_spinBox->setMinimum(1);
        maperiod_spinBox->setMaximum(120);

        horizontalLayout->addWidget(maperiod_spinBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        retranslateUi(SetMatPeriodDialog);

        QMetaObject::connectSlotsByName(SetMatPeriodDialog);
    } // setupUi

    void retranslateUi(QDialog *SetMatPeriodDialog)
    {
        SetMatPeriodDialog->setWindowTitle(QApplication::translate("SetMatPeriodDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        confirm_pushbutton->setText(QApplication::translate("SetMatPeriodDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetMatPeriodDialog", "\345\221\250\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SetMatPeriodDialog", "\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetMatPeriodDialog: public Ui_SetMatPeriodDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMATPERIODDIALOG_H
