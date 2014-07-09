/********************************************************************************
** Form generated from reading UI file 'employeebaseinfo.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEBASEINFO_H
#define UI_EMPLOYEEBASEINFO_H

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

class Ui_EmployeeBaseinfo
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_cardNo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox_department;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *comboBox_post;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBox_gender;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *comboBox_status;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_6;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *EmployeeBaseinfo)
    {
        if (EmployeeBaseinfo->objectName().isEmpty())
            EmployeeBaseinfo->setObjectName(QString::fromUtf8("EmployeeBaseinfo"));
        EmployeeBaseinfo->resize(899, 452);
        gridLayout = new QGridLayout(EmployeeBaseinfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(EmployeeBaseinfo);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_cardNo = new QLineEdit(EmployeeBaseinfo);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_cardNo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(EmployeeBaseinfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        comboBox_department = new QComboBox(EmployeeBaseinfo);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));

        horizontalLayout_2->addWidget(comboBox_department);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_9->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(EmployeeBaseinfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_name = new QLineEdit(EmployeeBaseinfo);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit_name);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(EmployeeBaseinfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        comboBox_post = new QComboBox(EmployeeBaseinfo);
        comboBox_post->setObjectName(QString::fromUtf8("comboBox_post"));

        horizontalLayout_4->addWidget(comboBox_post);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(EmployeeBaseinfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        comboBox_gender = new QComboBox(EmployeeBaseinfo);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        horizontalLayout_5->addWidget(comboBox_gender);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(EmployeeBaseinfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        comboBox_status = new QComboBox(EmployeeBaseinfo);
        comboBox_status->setObjectName(QString::fromUtf8("comboBox_status"));

        horizontalLayout_6->addWidget(comboBox_status);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(EmployeeBaseinfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        dateEdit_start = new QDateEdit(EmployeeBaseinfo);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_start->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_start->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout_7->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(EmployeeBaseinfo);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDateTime(QDateTime(QDate(2050, 12, 31), QTime(0, 0, 0)));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout_7->addWidget(dateEdit_end);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_7);


        horizontalLayout_9->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        btn_clear = new QPushButton(EmployeeBaseinfo);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        verticalLayout_5->addWidget(btn_clear);

        btn_search = new QPushButton(EmployeeBaseinfo);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        verticalLayout_5->addWidget(btn_search);


        horizontalLayout_9->addLayout(verticalLayout_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_9);

        tableView = new QTableView(EmployeeBaseinfo);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_6->addWidget(tableView);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        btn_add = new QPushButton(EmployeeBaseinfo);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_8->addWidget(btn_add);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        btn_change = new QPushButton(EmployeeBaseinfo);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_8->addWidget(btn_change);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        btn_delete = new QPushButton(EmployeeBaseinfo);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_8->addWidget(btn_delete);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        btn_close = new QPushButton(EmployeeBaseinfo);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_8->addWidget(btn_close);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(EmployeeBaseinfo);

        QMetaObject::connectSlotsByName(EmployeeBaseinfo);
    } // setupUi

    void retranslateUi(QWidget *EmployeeBaseinfo)
    {
        EmployeeBaseinfo->setWindowTitle(QApplication::translate("EmployeeBaseinfo", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmployeeBaseinfo", "\345\267\245\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EmployeeBaseinfo", "\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        comboBox_department->clear();
        comboBox_department->insertItems(0, QStringList()
         << QApplication::translate("EmployeeBaseinfo", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("EmployeeBaseinfo", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EmployeeBaseinfo", "\350\201\214\345\212\241:", 0, QApplication::UnicodeUTF8));
        comboBox_post->clear();
        comboBox_post->insertItems(0, QStringList()
         << QApplication::translate("EmployeeBaseinfo", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("EmployeeBaseinfo", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QApplication::translate("EmployeeBaseinfo", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseinfo", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseinfo", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("EmployeeBaseinfo", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        comboBox_status->clear();
        comboBox_status->insertItems(0, QStringList()
         << QApplication::translate("EmployeeBaseinfo", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseinfo", "\345\234\250\350\201\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseinfo", "\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("EmployeeBaseinfo", "\346\223\215\344\275\234\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("EmployeeBaseinfo", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("EmployeeBaseinfo", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("EmployeeBaseinfo", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("EmployeeBaseinfo", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("EmployeeBaseinfo", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("EmployeeBaseinfo", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("EmployeeBaseinfo", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("EmployeeBaseinfo", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeBaseinfo: public Ui_EmployeeBaseinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEBASEINFO_H
