/********************************************************************************
** Form generated from reading UI file 'accountpaydialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTPAYDIALOG_H
#define UI_ACCOUNTPAYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountPayDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_cardNo;
    QLineEdit *lineEdit_accountRemain;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton_cash;
    QRadioButton *radioButton_card;
    QRadioButton *radioButton_bank;
    QRadioButton *radioButton_check;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_accountPay;
    QLabel *label_check;
    QLineEdit *lineEdit_check;
    QLabel *label_bank;
    QLineEdit *lineEdit_bank;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_operator;
    QLabel *label_7;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *AccountPayDialog)
    {
        if (AccountPayDialog->objectName().isEmpty())
            AccountPayDialog->setObjectName(QString::fromUtf8("AccountPayDialog"));
        AccountPayDialog->resize(417, 228);
        layoutWidget = new QWidget(AccountPayDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 180, 250, 25));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_8->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_8->addWidget(btn_cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        label_2 = new QLabel(AccountPayDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(242, 12, 26, 16));
        lineEdit_name = new QLineEdit(AccountPayDialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(272, 11, 116, 20));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);
        layoutWidget1 = new QWidget(AccountPayDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 178, 50));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_cardNo);

        lineEdit_accountRemain = new QLineEdit(layoutWidget1);
        lineEdit_accountRemain->setObjectName(QString::fromUtf8("lineEdit_accountRemain"));
        sizePolicy.setHeightForWidth(lineEdit_accountRemain->sizePolicy().hasHeightForWidth());
        lineEdit_accountRemain->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_accountRemain);


        horizontalLayout_2->addLayout(verticalLayout_2);

        layoutWidget2 = new QWidget(AccountPayDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(43, 73, 304, 18));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        radioButton_cash = new QRadioButton(layoutWidget2);
        radioButton_cash->setObjectName(QString::fromUtf8("radioButton_cash"));

        horizontalLayout_7->addWidget(radioButton_cash);

        radioButton_card = new QRadioButton(layoutWidget2);
        radioButton_card->setObjectName(QString::fromUtf8("radioButton_card"));

        horizontalLayout_7->addWidget(radioButton_card);

        radioButton_bank = new QRadioButton(layoutWidget2);
        radioButton_bank->setObjectName(QString::fromUtf8("radioButton_bank"));

        horizontalLayout_7->addWidget(radioButton_bank);

        radioButton_check = new QRadioButton(layoutWidget2);
        radioButton_check->setObjectName(QString::fromUtf8("radioButton_check"));

        horizontalLayout_7->addWidget(radioButton_check);

        layoutWidget3 = new QWidget(AccountPayDialog);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(19, 100, 540, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_accountPay = new QLineEdit(layoutWidget3);
        lineEdit_accountPay->setObjectName(QString::fromUtf8("lineEdit_accountPay"));

        horizontalLayout->addWidget(lineEdit_accountPay);

        label_check = new QLabel(layoutWidget3);
        label_check->setObjectName(QString::fromUtf8("label_check"));

        horizontalLayout->addWidget(label_check);

        lineEdit_check = new QLineEdit(layoutWidget3);
        lineEdit_check->setObjectName(QString::fromUtf8("lineEdit_check"));

        horizontalLayout->addWidget(lineEdit_check);

        label_bank = new QLabel(layoutWidget3);
        label_bank->setObjectName(QString::fromUtf8("label_bank"));

        horizontalLayout->addWidget(label_bank);

        lineEdit_bank = new QLineEdit(layoutWidget3);
        lineEdit_bank->setObjectName(QString::fromUtf8("lineEdit_bank"));

        horizontalLayout->addWidget(lineEdit_bank);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        layoutWidget4 = new QWidget(AccountPayDialog);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 130, 354, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lineEdit_operator = new QLineEdit(layoutWidget4);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_3->addWidget(lineEdit_operator);

        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        dateTimeEdit = new QDateTimeEdit(layoutWidget4);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateTimeEdit);


        retranslateUi(AccountPayDialog);

        QMetaObject::connectSlotsByName(AccountPayDialog);
    } // setupUi

    void retranslateUi(QDialog *AccountPayDialog)
    {
        AccountPayDialog->setWindowTitle(QApplication::translate("AccountPayDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("AccountPayDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("AccountPayDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AccountPayDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AccountPayDialog", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AccountPayDialog", "\350\264\246\346\210\267\344\275\231\351\242\235:", 0, QApplication::UnicodeUTF8));
        radioButton_cash->setText(QApplication::translate("AccountPayDialog", "\347\216\260\351\207\221\346\224\266\346\254\276", 0, QApplication::UnicodeUTF8));
        radioButton_card->setText(QApplication::translate("AccountPayDialog", "\345\210\267\345\215\241\346\224\266\346\254\276", 0, QApplication::UnicodeUTF8));
        radioButton_bank->setText(QApplication::translate("AccountPayDialog", "\351\223\266\350\241\214\350\275\254\350\264\246", 0, QApplication::UnicodeUTF8));
        radioButton_check->setText(QApplication::translate("AccountPayDialog", "\346\224\257\347\245\250\346\224\266\346\254\276", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AccountPayDialog", "\347\273\255\350\264\271\351\207\221\351\242\235:", 0, QApplication::UnicodeUTF8));
        label_check->setText(QApplication::translate("AccountPayDialog", "\346\224\257\347\245\250\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_bank->setText(QApplication::translate("AccountPayDialog", "\351\223\266\350\241\214:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AccountPayDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AccountPayDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("AccountPayDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccountPayDialog: public Ui_AccountPayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTPAYDIALOG_H
