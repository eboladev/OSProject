/********************************************************************************
** Form generated from reading UI file 'checkin.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKIN_H
#define UI_CHECKIN_H

#include <QtCore/QDate>
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

class Ui_CheckIn
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_name;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_buyer;
    QLineEdit *lineEdit_provider;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *CheckIn)
    {
        if (CheckIn->objectName().isEmpty())
            CheckIn->setObjectName(QString::fromUtf8("CheckIn"));
        CheckIn->resize(804, 455);
        gridLayout = new QGridLayout(CheckIn);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CheckIn);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(CheckIn);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBox_type = new QComboBox(CheckIn);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        verticalLayout_2->addWidget(comboBox_type);

        lineEdit_name = new QLineEdit(CheckIn);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_name);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(CheckIn);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(CheckIn);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_buyer = new QLineEdit(CheckIn);
        lineEdit_buyer->setObjectName(QString::fromUtf8("lineEdit_buyer"));
        sizePolicy.setHeightForWidth(lineEdit_buyer->sizePolicy().hasHeightForWidth());
        lineEdit_buyer->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_buyer);

        lineEdit_provider = new QLineEdit(CheckIn);
        lineEdit_provider->setObjectName(QString::fromUtf8("lineEdit_provider"));
        sizePolicy.setHeightForWidth(lineEdit_provider->sizePolicy().hasHeightForWidth());
        lineEdit_provider->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_provider);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(CheckIn);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dateEdit_start = new QDateEdit(CheckIn);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDate(QDate(2014, 3, 1));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(CheckIn);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_clear = new QPushButton(CheckIn);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout_2->addWidget(btn_clear);

        btn_search = new QPushButton(CheckIn);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout_2->addWidget(btn_search);


        verticalLayout_5->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_3);

        tableView = new QTableView(CheckIn);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_6->addWidget(tableView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btn_add = new QPushButton(CheckIn);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_4->addWidget(btn_add);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        btn_close = new QPushButton(CheckIn);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_4->addWidget(btn_close);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_6->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(CheckIn);

        QMetaObject::connectSlotsByName(CheckIn);
    } // setupUi

    void retranslateUi(QWidget *CheckIn)
    {
        CheckIn->setWindowTitle(QApplication::translate("CheckIn", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CheckIn", "\347\211\251\350\265\204\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CheckIn", "\347\211\251\350\265\204\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("CheckIn", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("CheckIn", "\351\207\207\350\264\255\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CheckIn", "\344\276\233\345\272\224\345\225\206:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CheckIn", "\345\205\245\345\272\223\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("CheckIn", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("CheckIn", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("CheckIn", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("CheckIn", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("CheckIn", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("CheckIn", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckIn: public Ui_CheckIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKIN_H
