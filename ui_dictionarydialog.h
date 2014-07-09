/********************************************************************************
** Form generated from reading UI file 'dictionarydialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONARYDIALOG_H
#define UI_DICTIONARYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DictionaryDialog
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QListView *listView_attribute;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QListView *listView_value;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_add;
    QPushButton *btn_delete;

    void setupUi(QDialog *DictionaryDialog)
    {
        if (DictionaryDialog->objectName().isEmpty())
            DictionaryDialog->setObjectName(QString::fromUtf8("DictionaryDialog"));
        DictionaryDialog->resize(573, 392);
        widget = new QWidget(DictionaryDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 320, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_ok = new QPushButton(widget);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        horizontalLayout_2->addWidget(btn_ok);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_2->addWidget(btn_cancel);

        widget1 = new QWidget(DictionaryDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 30, 524, 255));
        horizontalLayout_5 = new QHBoxLayout(widget1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        listView_attribute = new QListView(widget1);
        listView_attribute->setObjectName(QString::fromUtf8("listView_attribute"));

        verticalLayout->addWidget(listView_attribute);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        listView_value = new QListView(widget1);
        listView_value->setObjectName(QString::fromUtf8("listView_value"));

        verticalLayout_2->addWidget(listView_value);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_add = new QPushButton(widget1);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout->addWidget(btn_add);

        btn_delete = new QPushButton(widget1);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout->addWidget(btn_delete);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_2);

        btn_add->raise();
        btn_delete->raise();
        label->raise();
        label_2->raise();
        listView_attribute->raise();
        listView_value->raise();
        btn_ok->raise();
        btn_cancel->raise();
        btn_ok->raise();

        retranslateUi(DictionaryDialog);

        QMetaObject::connectSlotsByName(DictionaryDialog);
    } // setupUi

    void retranslateUi(QDialog *DictionaryDialog)
    {
        DictionaryDialog->setWindowTitle(QApplication::translate("DictionaryDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("DictionaryDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("DictionaryDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DictionaryDialog", "\345\261\236\346\200\247\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DictionaryDialog", "\345\261\236\346\200\247\345\200\274:", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("DictionaryDialog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("DictionaryDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DictionaryDialog: public Ui_DictionaryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARYDIALOG_H
