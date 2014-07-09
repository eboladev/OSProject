/********************************************************************************
** Form generated from reading UI file 'accountpay.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTPAY_H
#define UI_ACCOUNTPAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_AccountPay
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_cardNo;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLineEdit *lineEdit_accountStart;
    QLineEdit *lineEdit_accountEnd;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_accountPay;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *AccountPay)
    {
        if (AccountPay->objectName().isEmpty())
            AccountPay->setObjectName(QString::fromUtf8("AccountPay"));
        AccountPay->resize(911, 436);
        gridLayout = new QGridLayout(AccountPay);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(AccountPay);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_cardNo = new QLineEdit(AccountPay);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_cardNo);

        label_2 = new QLabel(AccountPay);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_name = new QLineEdit(AccountPay);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_name);

        label_3 = new QLabel(AccountPay);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_accountStart = new QLineEdit(AccountPay);
        lineEdit_accountStart->setObjectName(QString::fromUtf8("lineEdit_accountStart"));
        sizePolicy.setHeightForWidth(lineEdit_accountStart->sizePolicy().hasHeightForWidth());
        lineEdit_accountStart->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_accountStart);

        lineEdit_accountEnd = new QLineEdit(AccountPay);
        lineEdit_accountEnd->setObjectName(QString::fromUtf8("lineEdit_accountEnd"));
        sizePolicy.setHeightForWidth(lineEdit_accountEnd->sizePolicy().hasHeightForWidth());
        lineEdit_accountEnd->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_accountEnd);

        btn_clear = new QPushButton(AccountPay);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout_2->addWidget(btn_clear);

        btn_search = new QPushButton(AccountPay);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout_2->addWidget(btn_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(AccountPay);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_accountPay = new QPushButton(AccountPay);
        btn_accountPay->setObjectName(QString::fromUtf8("btn_accountPay"));

        horizontalLayout->addWidget(btn_accountPay);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn_close = new QPushButton(AccountPay);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout->addWidget(btn_close);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AccountPay);

        QMetaObject::connectSlotsByName(AccountPay);
    } // setupUi

    void retranslateUi(QWidget *AccountPay)
    {
        AccountPay->setWindowTitle(QApplication::translate("AccountPay", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AccountPay", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AccountPay", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AccountPay", "\345\244\207\347\224\250\351\207\221\344\275\231\351\242\235:", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("AccountPay", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("AccountPay", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_accountPay->setText(QApplication::translate("AccountPay", "\347\273\255\350\264\271", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("AccountPay", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccountPay: public Ui_AccountPay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTPAY_H
