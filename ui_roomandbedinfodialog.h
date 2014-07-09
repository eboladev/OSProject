/********************************************************************************
** Form generated from reading UI file 'roomandbedinfodialog.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMANDBEDINFODIALOG_H
#define UI_ROOMANDBEDINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RoomAndBedInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treewidget;

    void setupUi(QDialog *RoomAndBedInfoDialog)
    {
        if (RoomAndBedInfoDialog->objectName().isEmpty())
            RoomAndBedInfoDialog->setObjectName(QString::fromUtf8("RoomAndBedInfoDialog"));
        RoomAndBedInfoDialog->resize(725, 453);
        verticalLayout = new QVBoxLayout(RoomAndBedInfoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treewidget = new QTreeWidget(RoomAndBedInfoDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(6, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(5, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(4, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(3, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(2, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        treewidget->setHeaderItem(__qtreewidgetitem);
        treewidget->setObjectName(QString::fromUtf8("treewidget"));
        treewidget->setTextElideMode(Qt::ElideRight);
        treewidget->header()->setDefaultSectionSize(100);
        treewidget->header()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout->addWidget(treewidget);


        retranslateUi(RoomAndBedInfoDialog);

        QMetaObject::connectSlotsByName(RoomAndBedInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomAndBedInfoDialog)
    {
        RoomAndBedInfoDialog->setWindowTitle(QApplication::translate("RoomAndBedInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treewidget->headerItem();
        ___qtreewidgetitem->setText(6, QApplication::translate("RoomAndBedInfoDialog", "\345\272\212\345\236\253\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(5, QApplication::translate("RoomAndBedInfoDialog", "\346\234\211\347\251\272\345\272\212\345\245\263\346\210\277\351\227\264\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("RoomAndBedInfoDialog", "\346\234\211\347\251\272\345\272\212\347\224\267\346\210\277\351\227\264\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("RoomAndBedInfoDialog", "\345\205\250\347\251\272\345\272\212\346\210\277\351\227\264\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("RoomAndBedInfoDialog", "\347\251\272\345\272\212\344\275\215\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("RoomAndBedInfoDialog", "\345\205\250\351\203\250\345\272\212\344\275\215\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("RoomAndBedInfoDialog", "\346\245\274\345\261\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RoomAndBedInfoDialog: public Ui_RoomAndBedInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMANDBEDINFODIALOG_H
