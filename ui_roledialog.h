/********************************************************************************
** Form generated from reading UI file 'roledialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLEDIALOG_H
#define UI_ROLEDIALOG_H

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

class Ui_RoleDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_add;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_delete;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RoleDialog)
    {
        if (RoleDialog->objectName().isEmpty())
            RoleDialog->setObjectName(QString::fromUtf8("RoleDialog"));
        RoleDialog->resize(371, 282);
        gridLayout = new QGridLayout(RoleDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(RoleDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_add = new QPushButton(RoleDialog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        verticalLayout->addWidget(btn_add);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btn_delete = new QPushButton(RoleDialog);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        verticalLayout->addWidget(btn_delete);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_save = new QPushButton(RoleDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_2->addWidget(btn_save);

        btn_cancel = new QPushButton(RoleDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_2->addWidget(btn_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(RoleDialog);

        QMetaObject::connectSlotsByName(RoleDialog);
    } // setupUi

    void retranslateUi(QDialog *RoleDialog)
    {
        RoleDialog->setWindowTitle(QApplication::translate("RoleDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("RoleDialog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("RoleDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("RoleDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("RoleDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RoleDialog: public Ui_RoleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEDIALOG_H
