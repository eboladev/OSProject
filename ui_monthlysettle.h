/********************************************************************************
** Form generated from reading UI file 'monthlysettle.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHLYSETTLE_H
#define UI_MONTHLYSETTLE_H

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
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonthlySettle
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_auto;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_print;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *MonthlySettle)
    {
        if (MonthlySettle->objectName().isEmpty())
            MonthlySettle->setObjectName(QString::fromUtf8("MonthlySettle"));
        MonthlySettle->resize(771, 418);
        gridLayout = new QGridLayout(MonthlySettle);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(MonthlySettle);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_cardNo = new QLineEdit(MonthlySettle);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_cardNo);

        toolButton = new QToolButton(MonthlySettle);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);

        label = new QLabel(MonthlySettle);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_name = new QLineEdit(MonthlySettle);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_name);

        label_2 = new QLabel(MonthlySettle);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(MonthlySettle);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_3 = new QLabel(MonthlySettle);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        dateEdit = new QDateEdit(MonthlySettle);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit);

        btn_clear = new QPushButton(MonthlySettle);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout_2->addWidget(btn_clear);

        btn_search = new QPushButton(MonthlySettle);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout_2->addWidget(btn_search);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(MonthlySettle);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btn_auto = new QPushButton(MonthlySettle);
        btn_auto->setObjectName(QString::fromUtf8("btn_auto"));

        horizontalLayout->addWidget(btn_auto);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_print = new QPushButton(MonthlySettle);
        btn_print->setObjectName(QString::fromUtf8("btn_print"));

        horizontalLayout->addWidget(btn_print);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_close = new QPushButton(MonthlySettle);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout->addWidget(btn_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MonthlySettle);

        QMetaObject::connectSlotsByName(MonthlySettle);
    } // setupUi

    void retranslateUi(QWidget *MonthlySettle)
    {
        MonthlySettle->setWindowTitle(QApplication::translate("MonthlySettle", "Form", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MonthlySettle", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MonthlySettle", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MonthlySettle", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MonthlySettle", "\347\273\223\347\256\227\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MonthlySettle", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonthlySettle", "\345\267\262\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonthlySettle", "\346\234\252\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MonthlySettle", "\345\271\264\346\234\210:", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("MonthlySettle", "yyyy-MM", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("MonthlySettle", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("MonthlySettle", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_auto->setText(QApplication::translate("MonthlySettle", "\350\207\252\345\212\250\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8));
        btn_print->setText(QApplication::translate("MonthlySettle", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("MonthlySettle", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MonthlySettle: public Ui_MonthlySettle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHLYSETTLE_H
