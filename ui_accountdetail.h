/********************************************************************************
** Form generated from reading UI file 'accountdetail.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTDETAIL_H
#define UI_ACCOUNTDETAIL_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountDetail
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *AccountDetail)
    {
        if (AccountDetail->objectName().isEmpty())
            AccountDetail->setObjectName(QString::fromUtf8("AccountDetail"));
        AccountDetail->resize(899, 394);
        gridLayout = new QGridLayout(AccountDetail);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AccountDetail);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_cardNo = new QLineEdit(AccountDetail);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_cardNo);

        toolButton = new QToolButton(AccountDetail);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);

        label_2 = new QLabel(AccountDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_name = new QLineEdit(AccountDetail);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_name);

        label_3 = new QLabel(AccountDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dateEdit_start = new QDateEdit(AccountDetail);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDate(QDate(2014, 3, 1));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(AccountDetail);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);

        btn_clear = new QPushButton(AccountDetail);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(AccountDetail);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(AccountDetail);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_close = new QPushButton(AccountDetail);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AccountDetail);

        QMetaObject::connectSlotsByName(AccountDetail);
    } // setupUi

    void retranslateUi(QWidget *AccountDetail)
    {
        AccountDetail->setWindowTitle(QApplication::translate("AccountDetail", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AccountDetail", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("AccountDetail", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AccountDetail", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AccountDetail", "  \346\227\266\351\227\264\346\256\265:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("AccountDetail", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("AccountDetail", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("AccountDetail", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("AccountDetail", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("AccountDetail", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccountDetail: public Ui_AccountDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTDETAIL_H
