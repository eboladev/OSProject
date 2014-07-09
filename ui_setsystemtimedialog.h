/********************************************************************************
** Form generated from reading UI file 'setsystemtimedialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSYSTEMTIMEDIALOG_H
#define UI_SETSYSTEMTIMEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetSystemTimeDialog
{
public:
    QPushButton *confirm_pushbutton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;

    void setupUi(QDialog *SetSystemTimeDialog)
    {
        if (SetSystemTimeDialog->objectName().isEmpty())
            SetSystemTimeDialog->setObjectName(QString::fromUtf8("SetSystemTimeDialog"));
        SetSystemTimeDialog->resize(140, 95);
        confirm_pushbutton = new QPushButton(SetSystemTimeDialog);
        confirm_pushbutton->setObjectName(QString::fromUtf8("confirm_pushbutton"));
        confirm_pushbutton->setGeometry(QRect(80, 65, 50, 23));
        widget = new QWidget(SetSystemTimeDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 121, 48));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        verticalLayout->addWidget(dateEdit);

        timeEdit = new QTimeEdit(widget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        verticalLayout->addWidget(timeEdit);


        retranslateUi(SetSystemTimeDialog);

        QMetaObject::connectSlotsByName(SetSystemTimeDialog);
    } // setupUi

    void retranslateUi(QDialog *SetSystemTimeDialog)
    {
        SetSystemTimeDialog->setWindowTitle(QApplication::translate("SetSystemTimeDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        confirm_pushbutton->setText(QApplication::translate("SetSystemTimeDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("SetSystemTimeDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        timeEdit->setDisplayFormat(QApplication::translate("SetSystemTimeDialog", "HH:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetSystemTimeDialog: public Ui_SetSystemTimeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSYSTEMTIMEDIALOG_H
