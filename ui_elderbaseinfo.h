/********************************************************************************
** Form generated from reading UI file 'elderbaseinfo.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELDERBASEINFO_H
#define UI_ELDERBASEINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElderBaseInfo
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_elder;
    QLabel *label_2;
    QComboBox *comboBox_gender;
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

    void setupUi(QWidget *ElderBaseInfo)
    {
        if (ElderBaseInfo->objectName().isEmpty())
            ElderBaseInfo->setObjectName(QString::fromUtf8("ElderBaseInfo"));
        ElderBaseInfo->resize(825, 420);
        gridLayout = new QGridLayout(ElderBaseInfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ElderBaseInfo);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_elder = new QLineEdit(ElderBaseInfo);
        lineEdit_elder->setObjectName(QString::fromUtf8("lineEdit_elder"));
        lineEdit_elder->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_elder->sizePolicy().hasHeightForWidth());
        lineEdit_elder->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_elder);

        label_2 = new QLabel(ElderBaseInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox_gender = new QComboBox(ElderBaseInfo);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        horizontalLayout->addWidget(comboBox_gender);

        label_3 = new QLabel(ElderBaseInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dateEdit_start = new QDateEdit(ElderBaseInfo);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_start->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_start->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(ElderBaseInfo);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDateTime(QDateTime(QDate(2050, 12, 31), QTime(0, 0, 0)));
        dateEdit_end->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_end->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);

        btn_clear = new QPushButton(ElderBaseInfo);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(ElderBaseInfo);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(ElderBaseInfo);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_add = new QPushButton(ElderBaseInfo);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_2->addWidget(btn_add);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_change = new QPushButton(ElderBaseInfo);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_2->addWidget(btn_change);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_delete = new QPushButton(ElderBaseInfo);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_2->addWidget(btn_delete);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btn_close = new QPushButton(ElderBaseInfo);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(ElderBaseInfo);

        QMetaObject::connectSlotsByName(ElderBaseInfo);
    } // setupUi

    void retranslateUi(QWidget *ElderBaseInfo)
    {
        ElderBaseInfo->setWindowTitle(QApplication::translate("ElderBaseInfo", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ElderBaseInfo", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ElderBaseInfo", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QApplication::translate("ElderBaseInfo", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfo", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfo", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("ElderBaseInfo", "\347\231\273\350\256\260\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("ElderBaseInfo", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("ElderBaseInfo", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("ElderBaseInfo", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("ElderBaseInfo", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("ElderBaseInfo", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("ElderBaseInfo", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("ElderBaseInfo", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("ElderBaseInfo", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElderBaseInfo: public Ui_ElderBaseInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELDERBASEINFO_H
