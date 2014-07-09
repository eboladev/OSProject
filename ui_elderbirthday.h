/********************************************************************************
** Form generated from reading UI file 'elderbirthday.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELDERBIRTHDAY_H
#define UI_ELDERBIRTHDAY_H

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

class Ui_ElderBirthday
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QDateEdit *dateEdit_solarStart;
    QDateEdit *dateEdit_lunarStart;
    QVBoxLayout *verticalLayout_3;
    QDateEdit *dateEdit_solarEnd;
    QDateEdit *dateEdit_lunarEnd;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ElderBirthday)
    {
        if (ElderBirthday->objectName().isEmpty())
            ElderBirthday->setObjectName(QString::fromUtf8("ElderBirthday"));
        ElderBirthday->resize(685, 450);
        gridLayout = new QGridLayout(ElderBirthday);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(ElderBirthday);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(ElderBirthday);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dateEdit_solarStart = new QDateEdit(ElderBirthday);
        dateEdit_solarStart->setObjectName(QString::fromUtf8("dateEdit_solarStart"));
        dateEdit_solarStart->setEnabled(false);
        dateEdit_solarStart->setCalendarPopup(true);

        verticalLayout_2->addWidget(dateEdit_solarStart);

        dateEdit_lunarStart = new QDateEdit(ElderBirthday);
        dateEdit_lunarStart->setObjectName(QString::fromUtf8("dateEdit_lunarStart"));
        dateEdit_lunarStart->setEnabled(false);
        dateEdit_lunarStart->setCalendarPopup(true);

        verticalLayout_2->addWidget(dateEdit_lunarStart);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        dateEdit_solarEnd = new QDateEdit(ElderBirthday);
        dateEdit_solarEnd->setObjectName(QString::fromUtf8("dateEdit_solarEnd"));
        dateEdit_solarEnd->setEnabled(false);
        dateEdit_solarEnd->setCalendarPopup(true);

        verticalLayout_3->addWidget(dateEdit_solarEnd);

        dateEdit_lunarEnd = new QDateEdit(ElderBirthday);
        dateEdit_lunarEnd->setObjectName(QString::fromUtf8("dateEdit_lunarEnd"));
        dateEdit_lunarEnd->setEnabled(false);
        dateEdit_lunarEnd->setCalendarPopup(true);

        verticalLayout_3->addWidget(dateEdit_lunarEnd);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(ElderBirthday);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        label = new QLabel(ElderBirthday);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dateEdit_start = new QDateEdit(ElderBirthday);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(ElderBirthday);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit = new QLineEdit(ElderBirthday);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        btn_clear = new QPushButton(ElderBirthday);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        verticalLayout_6->addWidget(btn_clear);

        btn_search = new QPushButton(ElderBirthday);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        verticalLayout_6->addWidget(btn_search);


        horizontalLayout_4->addLayout(verticalLayout_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_7->addLayout(horizontalLayout_4);

        tableView = new QTableView(ElderBirthday);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_7->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_close = new QPushButton(ElderBirthday);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_7->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(ElderBirthday);

        QMetaObject::connectSlotsByName(ElderBirthday);
    } // setupUi

    void retranslateUi(QWidget *ElderBirthday)
    {
        ElderBirthday->setWindowTitle(QApplication::translate("ElderBirthday", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ElderBirthday", "\351\230\263\345\216\206:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ElderBirthday", "\351\230\264\345\216\206:", 0, QApplication::UnicodeUTF8));
        dateEdit_solarStart->setDisplayFormat(QApplication::translate("ElderBirthday", "MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_lunarStart->setDisplayFormat(QApplication::translate("ElderBirthday", "MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_solarEnd->setDisplayFormat(QApplication::translate("ElderBirthday", "MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_lunarEnd->setDisplayFormat(QApplication::translate("ElderBirthday", "MM-dd", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ElderBirthday", "\346\227\245\346\234\237\350\214\203\345\233\264:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ElderBirthday", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("ElderBirthday", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("ElderBirthday", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("ElderBirthday", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("ElderBirthday", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("ElderBirthday", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElderBirthday: public Ui_ElderBirthday {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELDERBIRTHDAY_H
