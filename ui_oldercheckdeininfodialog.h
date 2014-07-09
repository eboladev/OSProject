/********************************************************************************
** Form generated from reading UI file 'oldercheckdeininfodialog.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OLDERCHECKDEININFODIALOG_H
#define UI_OLDERCHECKDEININFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_olderCheckdeInInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treewidget;

    void setupUi(QDialog *olderCheckdeInInfoDialog)
    {
        if (olderCheckdeInInfoDialog->objectName().isEmpty())
            olderCheckdeInInfoDialog->setObjectName(QString::fromUtf8("olderCheckdeInInfoDialog"));
        olderCheckdeInInfoDialog->resize(1057, 407);
        verticalLayout = new QVBoxLayout(olderCheckdeInInfoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treewidget = new QTreeWidget(olderCheckdeInInfoDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(10, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(9, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(8, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(7, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(6, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(5, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(4, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(3, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(2, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        treewidget->setHeaderItem(__qtreewidgetitem);
        treewidget->setObjectName(QString::fromUtf8("treewidget"));

        verticalLayout->addWidget(treewidget);


        retranslateUi(olderCheckdeInInfoDialog);

        QMetaObject::connectSlotsByName(olderCheckdeInInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *olderCheckdeInInfoDialog)
    {
        olderCheckdeInInfoDialog->setWindowTitle(QApplication::translate("olderCheckdeInInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treewidget->headerItem();
        ___qtreewidgetitem->setText(10, QApplication::translate("olderCheckdeInInfoDialog", "\344\270\215\347\233\221\346\216\247\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(9, QApplication::translate("olderCheckdeInInfoDialog", "\346\231\256\351\200\232\347\233\221\346\216\247\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(8, QApplication::translate("olderCheckdeInInfoDialog", "\351\207\215\347\202\271\347\233\221\346\216\247\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(7, QApplication::translate("olderCheckdeInInfoDialog", "\345\215\212\345\244\261\350\203\275\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(6, QApplication::translate("olderCheckdeInInfoDialog", "\345\244\261\350\203\275\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(5, QApplication::translate("olderCheckdeInInfoDialog", "\351\225\277\346\234\237\345\215\247\345\272\212\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("olderCheckdeInInfoDialog", "\346\255\243\345\270\270\350\265\267\345\261\205\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("olderCheckdeInInfoDialog", "\345\245\263\345\205\245\344\275\217\344\272\272\345\221\230\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("olderCheckdeInInfoDialog", "\347\224\267\345\205\245\344\275\217\344\272\272\345\221\230\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("olderCheckdeInInfoDialog", "\345\205\245\344\275\217\344\272\272\345\221\230\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("olderCheckdeInInfoDialog", "\346\245\274\345\261\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class olderCheckdeInInfoDialog: public Ui_olderCheckdeInInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OLDERCHECKDEININFODIALOG_H
