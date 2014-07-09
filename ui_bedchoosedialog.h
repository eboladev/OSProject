/********************************************************************************
** Form generated from reading UI file 'bedchoosedialog.ui'
**
** Created: Sun Jun 29 15:25:42 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEDCHOOSEDIALOG_H
#define UI_BEDCHOOSEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_BedChooseDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QTableWidget *tableWidget;

    void setupUi(QDialog *BedChooseDialog)
    {
        if (BedChooseDialog->objectName().isEmpty())
            BedChooseDialog->setObjectName(QString::fromUtf8("BedChooseDialog"));
        BedChooseDialog->resize(692, 463);
        gridLayout = new QGridLayout(BedChooseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeView = new QTreeView(BedChooseDialog);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(treeView);

        tableWidget = new QTableWidget(BedChooseDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(tableWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(BedChooseDialog);

        QMetaObject::connectSlotsByName(BedChooseDialog);
    } // setupUi

    void retranslateUi(QDialog *BedChooseDialog)
    {
        BedChooseDialog->setWindowTitle(QApplication::translate("BedChooseDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BedChooseDialog: public Ui_BedChooseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEDCHOOSEDIALOG_H
