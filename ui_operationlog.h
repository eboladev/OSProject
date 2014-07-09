/********************************************************************************
** Form generated from reading UI file 'operationlog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATIONLOG_H
#define UI_OPERATIONLOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperationLog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_start;
    QDateTimeEdit *dateTimeEdit_end;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *OperationLog)
    {
        if (OperationLog->objectName().isEmpty())
            OperationLog->setObjectName(QString::fromUtf8("OperationLog"));
        OperationLog->resize(729, 437);
        gridLayout = new QGridLayout(OperationLog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(OperationLog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(OperationLog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(OperationLog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateTimeEdit_start = new QDateTimeEdit(OperationLog);
        dateTimeEdit_start->setObjectName(QString::fromUtf8("dateTimeEdit_start"));
        dateTimeEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTimeEdit_start);

        dateTimeEdit_end = new QDateTimeEdit(OperationLog);
        dateTimeEdit_end->setObjectName(QString::fromUtf8("dateTimeEdit_end"));
        dateTimeEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTimeEdit_end);

        btn_clear = new QPushButton(OperationLog);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(OperationLog);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(OperationLog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_close = new QPushButton(OperationLog);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(OperationLog);

        QMetaObject::connectSlotsByName(OperationLog);
    } // setupUi

    void retranslateUi(QWidget *OperationLog)
    {
        OperationLog->setWindowTitle(QApplication::translate("OperationLog", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OperationLog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OperationLog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_start->setDisplayFormat(QApplication::translate("OperationLog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_end->setDisplayFormat(QApplication::translate("OperationLog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("OperationLog", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("OperationLog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("OperationLog", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OperationLog: public Ui_OperationLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONLOG_H
