/********************************************************************************
** Form generated from reading UI file 'monthlyresidestatistics.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHLYRESIDESTATISTICS_H
#define UI_MONTHLYRESIDESTATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonthlyResideStatistics
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QPushButton *btn_search;
    QPushButton *btn_print;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *MonthlyResideStatistics)
    {
        if (MonthlyResideStatistics->objectName().isEmpty())
            MonthlyResideStatistics->setObjectName(QString::fromUtf8("MonthlyResideStatistics"));
        MonthlyResideStatistics->resize(542, 461);
        gridLayout = new QGridLayout(MonthlyResideStatistics);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MonthlyResideStatistics);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateEdit = new QDateEdit(MonthlyResideStatistics);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        btn_search = new QPushButton(MonthlyResideStatistics);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        btn_print = new QPushButton(MonthlyResideStatistics);
        btn_print->setObjectName(QString::fromUtf8("btn_print"));

        horizontalLayout->addWidget(btn_print);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(MonthlyResideStatistics);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_close = new QPushButton(MonthlyResideStatistics);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MonthlyResideStatistics);

        QMetaObject::connectSlotsByName(MonthlyResideStatistics);
    } // setupUi

    void retranslateUi(QWidget *MonthlyResideStatistics)
    {
        MonthlyResideStatistics->setWindowTitle(QApplication::translate("MonthlyResideStatistics", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MonthlyResideStatistics", "\346\234\210\344\273\275:", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("MonthlyResideStatistics", "yyyy-MM", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("MonthlyResideStatistics", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_print->setText(QApplication::translate("MonthlyResideStatistics", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("MonthlyResideStatistics", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MonthlyResideStatistics: public Ui_MonthlyResideStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHLYRESIDESTATISTICS_H
