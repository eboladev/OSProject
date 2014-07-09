/********************************************************************************
** Form generated from reading UI file 'employeebaseinfochoosedialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEBASEINFOCHOOSEDIALOG_H
#define UI_EMPLOYEEBASEINFOCHOOSEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EmployeeBaseInfoChooseDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_cardNo;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QTableWidget *tableWidget;

    void setupUi(QDialog *EmployeeBaseInfoChooseDialog)
    {
        if (EmployeeBaseInfoChooseDialog->objectName().isEmpty())
            EmployeeBaseInfoChooseDialog->setObjectName(QString::fromUtf8("EmployeeBaseInfoChooseDialog"));
        EmployeeBaseInfoChooseDialog->resize(474, 381);
        gridLayout = new QGridLayout(EmployeeBaseInfoChooseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(EmployeeBaseInfoChooseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_cardNo = new QLineEdit(EmployeeBaseInfoChooseDialog);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));

        horizontalLayout->addWidget(lineEdit_cardNo);

        label = new QLabel(EmployeeBaseInfoChooseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(EmployeeBaseInfoChooseDialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);

        btn_clear = new QPushButton(EmployeeBaseInfoChooseDialog);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(EmployeeBaseInfoChooseDialog);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(EmployeeBaseInfoChooseDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(EmployeeBaseInfoChooseDialog);

        QMetaObject::connectSlotsByName(EmployeeBaseInfoChooseDialog);
    } // setupUi

    void retranslateUi(QDialog *EmployeeBaseInfoChooseDialog)
    {
        EmployeeBaseInfoChooseDialog->setWindowTitle(QApplication::translate("EmployeeBaseInfoChooseDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EmployeeBaseInfoChooseDialog", "\345\267\245\345\217\267:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmployeeBaseInfoChooseDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("EmployeeBaseInfoChooseDialog", "\346\270\205\351\231\244\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("EmployeeBaseInfoChooseDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeBaseInfoChooseDialog: public Ui_EmployeeBaseInfoChooseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEBASEINFOCHOOSEDIALOG_H
