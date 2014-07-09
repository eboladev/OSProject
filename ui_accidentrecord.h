/********************************************************************************
** Form generated from reading UI file 'accidentrecord.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCIDENTRECORD_H
#define UI_ACCIDENTRECORD_H

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

class Ui_AccidentRecord
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_4;
    QLineEdit *lineEdit_personInCharge;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label;
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

    void setupUi(QWidget *AccidentRecord)
    {
        if (AccidentRecord->objectName().isEmpty())
            AccidentRecord->setObjectName(QString::fromUtf8("AccidentRecord"));
        AccidentRecord->resize(1023, 404);
        gridLayout = new QGridLayout(AccidentRecord);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(AccidentRecord);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_name = new QLineEdit(AccidentRecord);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_name);

        label_4 = new QLabel(AccidentRecord);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_personInCharge = new QLineEdit(AccidentRecord);
        lineEdit_personInCharge->setObjectName(QString::fromUtf8("lineEdit_personInCharge"));
        sizePolicy.setHeightForWidth(lineEdit_personInCharge->sizePolicy().hasHeightForWidth());
        lineEdit_personInCharge->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_personInCharge);

        label_3 = new QLabel(AccidentRecord);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox = new QComboBox(AccidentRecord);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label = new QLabel(AccidentRecord);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(label);

        dateEdit_start = new QDateEdit(AccidentRecord);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDate(QDate(2014, 3, 1));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(AccidentRecord);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);

        btn_clear = new QPushButton(AccidentRecord);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(AccidentRecord);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(AccidentRecord);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_add = new QPushButton(AccidentRecord);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_2->addWidget(btn_add);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_change = new QPushButton(AccidentRecord);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_2->addWidget(btn_change);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_delete = new QPushButton(AccidentRecord);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_2->addWidget(btn_delete);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btn_close = new QPushButton(AccidentRecord);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_2->addWidget(btn_close);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AccidentRecord);

        QMetaObject::connectSlotsByName(AccidentRecord);
    } // setupUi

    void retranslateUi(QWidget *AccidentRecord)
    {
        AccidentRecord->setWindowTitle(QApplication::translate("AccidentRecord", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AccidentRecord", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AccidentRecord", "\350\264\243\344\273\273\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AccidentRecord", "\344\272\213\346\225\205\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AccidentRecord", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("AccidentRecord", "\346\227\245\346\234\237\350\214\203\345\233\264\357\274\232", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("AccidentRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("AccidentRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("AccidentRecord", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("AccidentRecord", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("AccidentRecord", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("AccidentRecord", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("AccidentRecord", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("AccidentRecord", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccidentRecord: public Ui_AccidentRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCIDENTRECORD_H
