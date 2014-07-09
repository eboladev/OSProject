/********************************************************************************
** Form generated from reading UI file 'nurserecord.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NURSERECORD_H
#define UI_NURSERECORD_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
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

class Ui_NurseRecord
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_6;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *NurseRecord)
    {
        if (NurseRecord->objectName().isEmpty())
            NurseRecord->setObjectName(QString::fromUtf8("NurseRecord"));
        NurseRecord->resize(705, 464);
        gridLayout = new QGridLayout(NurseRecord);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(NurseRecord);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(NurseRecord);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(NurseRecord);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateEdit_start = new QDateEdit(NurseRecord);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(NurseRecord);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);

        btn_clear = new QPushButton(NurseRecord);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(NurseRecord);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(NurseRecord);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_add = new QPushButton(NurseRecord);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_2->addWidget(btn_add);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_change = new QPushButton(NurseRecord);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_2->addWidget(btn_change);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_delete = new QPushButton(NurseRecord);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_2->addWidget(btn_delete);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_close = new QPushButton(NurseRecord);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(NurseRecord);

        QMetaObject::connectSlotsByName(NurseRecord);
    } // setupUi

    void retranslateUi(QWidget *NurseRecord)
    {
        NurseRecord->setWindowTitle(QApplication::translate("NurseRecord", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NurseRecord", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NurseRecord", "\346\212\244\347\220\206\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("NurseRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("NurseRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("NurseRecord", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("NurseRecord", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("NurseRecord", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("NurseRecord", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("NurseRecord", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("NurseRecord", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NurseRecord: public Ui_NurseRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NURSERECORD_H
