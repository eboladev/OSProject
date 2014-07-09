/********************************************************************************
** Form generated from reading UI file 'stagecostdialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAGECOSTDIALOG_H
#define UI_STAGECOSTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StageCostDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btn_add;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_delete;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *StageCostDialog)
    {
        if (StageCostDialog->objectName().isEmpty())
            StageCostDialog->setObjectName(QString::fromUtf8("StageCostDialog"));
        StageCostDialog->resize(517, 315);
        gridLayout = new QGridLayout(StageCostDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(StageCostDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        btn_add = new QPushButton(StageCostDialog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        verticalLayout->addWidget(btn_add);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_delete = new QPushButton(StageCostDialog);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        verticalLayout->addWidget(btn_delete);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_ok = new QPushButton(StageCostDialog);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        horizontalLayout_2->addWidget(btn_ok);

        btn_cancel = new QPushButton(StageCostDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_2->addWidget(btn_cancel);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(StageCostDialog);

        QMetaObject::connectSlotsByName(StageCostDialog);
    } // setupUi

    void retranslateUi(QDialog *StageCostDialog)
    {
        StageCostDialog->setWindowTitle(QApplication::translate("StageCostDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("StageCostDialog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("StageCostDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("StageCostDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("StageCostDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StageCostDialog: public Ui_StageCostDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGECOSTDIALOG_H
