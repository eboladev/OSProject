/********************************************************************************
** Form generated from reading UI file 'advicerecord.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVICERECORD_H
#define UI_ADVICERECORD_H

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

class Ui_AdviceRecord
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_adviceId;
    QLabel *label_2;
    QLineEdit *lineEdit_elderName;
    QLabel *label_4;
    QLineEdit *lineEdit_doctor;
    QLabel *label_3;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *AdviceRecord)
    {
        if (AdviceRecord->objectName().isEmpty())
            AdviceRecord->setObjectName(QString::fromUtf8("AdviceRecord"));
        AdviceRecord->resize(1075, 406);
        gridLayout = new QGridLayout(AdviceRecord);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AdviceRecord);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_adviceId = new QLineEdit(AdviceRecord);
        lineEdit_adviceId->setObjectName(QString::fromUtf8("lineEdit_adviceId"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_adviceId->sizePolicy().hasHeightForWidth());
        lineEdit_adviceId->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_adviceId);

        label_2 = new QLabel(AdviceRecord);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_elderName = new QLineEdit(AdviceRecord);
        lineEdit_elderName->setObjectName(QString::fromUtf8("lineEdit_elderName"));
        sizePolicy.setHeightForWidth(lineEdit_elderName->sizePolicy().hasHeightForWidth());
        lineEdit_elderName->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_elderName);

        label_4 = new QLabel(AdviceRecord);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_doctor = new QLineEdit(AdviceRecord);
        lineEdit_doctor->setObjectName(QString::fromUtf8("lineEdit_doctor"));
        sizePolicy.setHeightForWidth(lineEdit_doctor->sizePolicy().hasHeightForWidth());
        lineEdit_doctor->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_doctor);

        label_3 = new QLabel(AdviceRecord);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dateEdit_start = new QDateEdit(AdviceRecord);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDate(QDate(2014, 3, 1));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(AdviceRecord);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);

        btn_clear = new QPushButton(AdviceRecord);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(AdviceRecord);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(AdviceRecord);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_add = new QPushButton(AdviceRecord);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_2->addWidget(btn_add);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_change = new QPushButton(AdviceRecord);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_2->addWidget(btn_change);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_delete = new QPushButton(AdviceRecord);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_2->addWidget(btn_delete);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btn_close = new QPushButton(AdviceRecord);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AdviceRecord);

        QMetaObject::connectSlotsByName(AdviceRecord);
    } // setupUi

    void retranslateUi(QWidget *AdviceRecord)
    {
        AdviceRecord->setWindowTitle(QApplication::translate("AdviceRecord", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdviceRecord", "\345\214\273\345\230\261ID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdviceRecord", "\350\200\201\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AdviceRecord", "\345\214\273\345\270\210:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AdviceRecord", "\345\214\273\345\230\261\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("AdviceRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("AdviceRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("AdviceRecord", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("AdviceRecord", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("AdviceRecord", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("AdviceRecord", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("AdviceRecord", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("AdviceRecord", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdviceRecord: public Ui_AdviceRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVICERECORD_H
