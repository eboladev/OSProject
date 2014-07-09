/********************************************************************************
** Form generated from reading UI file 'basecostdialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASECOSTDIALOG_H
#define UI_BASECOSTDIALOG_H

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
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseCostDialog
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QListView *listView_attribute;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_add;
    QPushButton *btn_delete;

    void setupUi(QDialog *BaseCostDialog)
    {
        if (BaseCostDialog->objectName().isEmpty())
            BaseCostDialog->setObjectName(QString::fromUtf8("BaseCostDialog"));
        BaseCostDialog->resize(570, 382);
        widget = new QWidget(BaseCostDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(190, 310, 158, 25));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btn_ok = new QPushButton(widget);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        horizontalLayout_5->addWidget(btn_ok);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_5->addWidget(btn_cancel);

        widget1 = new QWidget(BaseCostDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(21, 31, 524, 255));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listView_attribute = new QListView(widget1);
        listView_attribute->setObjectName(QString::fromUtf8("listView_attribute"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView_attribute->sizePolicy().hasHeightForWidth());
        listView_attribute->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(listView_attribute);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tableView = new QTableView(widget1);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_add = new QPushButton(widget1);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_3->addWidget(btn_add);

        btn_delete = new QPushButton(widget1);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_3->addWidget(btn_delete);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(BaseCostDialog);

        QMetaObject::connectSlotsByName(BaseCostDialog);
    } // setupUi

    void retranslateUi(QDialog *BaseCostDialog)
    {
        BaseCostDialog->setWindowTitle(QApplication::translate("BaseCostDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BaseCostDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("BaseCostDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BaseCostDialog", " \350\264\271\347\224\250\347\261\273\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BaseCostDialog", "\351\241\271\347\233\256:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BaseCostDialog", "\350\264\271\347\224\250:", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("BaseCostDialog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("BaseCostDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BaseCostDialog: public Ui_BaseCostDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASECOSTDIALOG_H
