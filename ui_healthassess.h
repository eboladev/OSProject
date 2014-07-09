/********************************************************************************
** Form generated from reading UI file 'healthassess.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEALTHASSESS_H
#define UI_HEALTHASSESS_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HealthAssess
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QComboBox *comboBox_selfNurse;
    QLabel *label_4;
    QComboBox *comboBox_nurseSuggestion;
    QLabel *label_5;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_7;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *HealthAssess)
    {
        if (HealthAssess->objectName().isEmpty())
            HealthAssess->setObjectName(QString::fromUtf8("HealthAssess"));
        HealthAssess->resize(978, 433);
        gridLayout = new QGridLayout(HealthAssess);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(HealthAssess);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(HealthAssess);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_name);

        label_3 = new QLabel(HealthAssess);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox_selfNurse = new QComboBox(HealthAssess);
        comboBox_selfNurse->setObjectName(QString::fromUtf8("comboBox_selfNurse"));

        horizontalLayout->addWidget(comboBox_selfNurse);

        label_4 = new QLabel(HealthAssess);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBox_nurseSuggestion = new QComboBox(HealthAssess);
        comboBox_nurseSuggestion->setObjectName(QString::fromUtf8("comboBox_nurseSuggestion"));

        horizontalLayout->addWidget(comboBox_nurseSuggestion);

        label_5 = new QLabel(HealthAssess);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_5);

        dateEdit_start = new QDateEdit(HealthAssess);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        sizePolicy.setHeightForWidth(dateEdit_start->sizePolicy().hasHeightForWidth());
        dateEdit_start->setSizePolicy(sizePolicy);
        dateEdit_start->setDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_start->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_start->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(HealthAssess);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        sizePolicy.setHeightForWidth(dateEdit_end->sizePolicy().hasHeightForWidth());
        dateEdit_end->setSizePolicy(sizePolicy);
        dateEdit_end->setDateTime(QDateTime(QDate(2050, 12, 31), QTime(0, 0, 0)));
        dateEdit_end->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_end->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);

        btn_clear = new QPushButton(HealthAssess);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(HealthAssess);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(HealthAssess);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btn_add = new QPushButton(HealthAssess);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_5->addWidget(btn_add);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btn_change = new QPushButton(HealthAssess);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_5->addWidget(btn_change);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        btn_delete = new QPushButton(HealthAssess);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_5->addWidget(btn_delete);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        btn_close = new QPushButton(HealthAssess);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_5->addWidget(btn_close);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(HealthAssess);

        QMetaObject::connectSlotsByName(HealthAssess);
    } // setupUi

    void retranslateUi(QWidget *HealthAssess)
    {
        HealthAssess->setWindowTitle(QApplication::translate("HealthAssess", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HealthAssess", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HealthAssess", "\350\207\252\347\220\206\347\272\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_selfNurse->clear();
        comboBox_selfNurse->insertItems(0, QStringList()
         << QApplication::translate("HealthAssess", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("HealthAssess", "\345\273\272\350\256\256\346\212\244\347\220\206\347\272\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_nurseSuggestion->clear();
        comboBox_nurseSuggestion->insertItems(0, QStringList()
         << QApplication::translate("HealthAssess", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("HealthAssess", "\347\231\273\350\256\260\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("HealthAssess", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("HealthAssess", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("HealthAssess", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("HealthAssess", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("HealthAssess", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("HealthAssess", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("HealthAssess", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("HealthAssess", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HealthAssess: public Ui_HealthAssess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHASSESS_H
