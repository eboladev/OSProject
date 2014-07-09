/********************************************************************************
** Form generated from reading UI file 'alarmdealwithconfirmdialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMDEALWITHCONFIRMDIALOG_H
#define UI_ALARMDEALWITHCONFIRMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmDealWithConfirmDialog
{
public:
    QWidget *widget;
    QPushButton *confirm_pushbutton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *identifier_label;
    QLineEdit *identifier_lineedit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwd_label;
    QLineEdit *passwd_lineedit;

    void setupUi(QDialog *AlarmDealWithConfirmDialog)
    {
        if (AlarmDealWithConfirmDialog->objectName().isEmpty())
            AlarmDealWithConfirmDialog->setObjectName(QString::fromUtf8("AlarmDealWithConfirmDialog"));
        AlarmDealWithConfirmDialog->resize(416, 296);
        widget = new QWidget(AlarmDealWithConfirmDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 60, 230, 110));
        confirm_pushbutton = new QPushButton(widget);
        confirm_pushbutton->setObjectName(QString::fromUtf8("confirm_pushbutton"));
        confirm_pushbutton->setGeometry(QRect(124, 80, 75, 23));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(31, 20, 179, 52));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        identifier_label = new QLabel(widget1);
        identifier_label->setObjectName(QString::fromUtf8("identifier_label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(identifier_label->sizePolicy().hasHeightForWidth());
        identifier_label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(identifier_label);

        identifier_lineedit = new QLineEdit(widget1);
        identifier_lineedit->setObjectName(QString::fromUtf8("identifier_lineedit"));

        horizontalLayout->addWidget(identifier_lineedit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passwd_label = new QLabel(widget1);
        passwd_label->setObjectName(QString::fromUtf8("passwd_label"));
        sizePolicy.setHeightForWidth(passwd_label->sizePolicy().hasHeightForWidth());
        passwd_label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(passwd_label);

        passwd_lineedit = new QLineEdit(widget1);
        passwd_lineedit->setObjectName(QString::fromUtf8("passwd_lineedit"));

        horizontalLayout_2->addWidget(passwd_lineedit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AlarmDealWithConfirmDialog);

        QMetaObject::connectSlotsByName(AlarmDealWithConfirmDialog);
    } // setupUi

    void retranslateUi(QDialog *AlarmDealWithConfirmDialog)
    {
        AlarmDealWithConfirmDialog->setWindowTitle(QApplication::translate("AlarmDealWithConfirmDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        confirm_pushbutton->setText(QApplication::translate("AlarmDealWithConfirmDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        identifier_label->setText(QApplication::translate("AlarmDealWithConfirmDialog", "\347\224\250\346\210\267\357\274\232", 0, QApplication::UnicodeUTF8));
        passwd_label->setText(QApplication::translate("AlarmDealWithConfirmDialog", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AlarmDealWithConfirmDialog: public Ui_AlarmDealWithConfirmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMDEALWITHCONFIRMDIALOG_H
