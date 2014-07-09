/********************************************************************************
** Form generated from reading UI file 'operationlogdialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATIONLOGDIALOG_H
#define UI_OPERATIONLOGDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OperationLogDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *startdate_dateedit;
    QLabel *label_2;
    QDateEdit *enddate_dateedit;
    QLabel *label_3;
    QComboBox *staffid_comboBox;
    QPushButton *search_pushbutton;
    QTableView *view;

    void setupUi(QDialog *OperationLogDialog)
    {
        if (OperationLogDialog->objectName().isEmpty())
            OperationLogDialog->setObjectName(QString::fromUtf8("OperationLogDialog"));
        OperationLogDialog->resize(611, 450);
        verticalLayout = new QVBoxLayout(OperationLogDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(OperationLogDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        startdate_dateedit = new QDateEdit(OperationLogDialog);
        startdate_dateedit->setObjectName(QString::fromUtf8("startdate_dateedit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startdate_dateedit->sizePolicy().hasHeightForWidth());
        startdate_dateedit->setSizePolicy(sizePolicy1);
        startdate_dateedit->setLayoutDirection(Qt::LeftToRight);
        startdate_dateedit->setMinimumDate(QDate(2013, 9, 1));
        startdate_dateedit->setCalendarPopup(true);

        horizontalLayout->addWidget(startdate_dateedit);

        label_2 = new QLabel(OperationLogDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        enddate_dateedit = new QDateEdit(OperationLogDialog);
        enddate_dateedit->setObjectName(QString::fromUtf8("enddate_dateedit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(enddate_dateedit->sizePolicy().hasHeightForWidth());
        enddate_dateedit->setSizePolicy(sizePolicy2);
        enddate_dateedit->setMinimumDate(QDate(2013, 9, 1));
        enddate_dateedit->setCalendarPopup(true);

        horizontalLayout->addWidget(enddate_dateedit);

        label_3 = new QLabel(OperationLogDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_3);

        staffid_comboBox = new QComboBox(OperationLogDialog);
        staffid_comboBox->setObjectName(QString::fromUtf8("staffid_comboBox"));
        sizePolicy2.setHeightForWidth(staffid_comboBox->sizePolicy().hasHeightForWidth());
        staffid_comboBox->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(staffid_comboBox);


        horizontalLayout_7->addLayout(horizontalLayout);

        search_pushbutton = new QPushButton(OperationLogDialog);
        search_pushbutton->setObjectName(QString::fromUtf8("search_pushbutton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(search_pushbutton->sizePolicy().hasHeightForWidth());
        search_pushbutton->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(search_pushbutton);


        verticalLayout->addLayout(horizontalLayout_7);

        view = new QTableView(OperationLogDialog);
        view->setObjectName(QString::fromUtf8("view"));

        verticalLayout->addWidget(view);


        retranslateUi(OperationLogDialog);

        QMetaObject::connectSlotsByName(OperationLogDialog);
    } // setupUi

    void retranslateUi(QDialog *OperationLogDialog)
    {
        OperationLogDialog->setWindowTitle(QApplication::translate("OperationLogDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OperationLogDialog", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        startdate_dateedit->setDisplayFormat(QApplication::translate("OperationLogDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OperationLogDialog", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        enddate_dateedit->setDisplayFormat(QApplication::translate("OperationLogDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OperationLogDialog", "\347\256\241\347\220\206\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        search_pushbutton->setText(QApplication::translate("OperationLogDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OperationLogDialog: public Ui_OperationLogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONLOGDIALOG_H
