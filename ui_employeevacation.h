/********************************************************************************
** Form generated from reading UI file 'employeevacation.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEVACATION_H
#define UI_EMPLOYEEVACATION_H

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

class Ui_EmployeeVacation
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_auditor;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDateEdit *dateEdit_leaveStart;
    QDateEdit *dateEdit_leaveEnd;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDateEdit *dateEdit_backStart;
    QDateEdit *dateEdit_backEnd;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QComboBox *comboBox_status;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *EmployeeVacation)
    {
        if (EmployeeVacation->objectName().isEmpty())
            EmployeeVacation->setObjectName(QString::fromUtf8("EmployeeVacation"));
        EmployeeVacation->resize(949, 444);
        gridLayout = new QGridLayout(EmployeeVacation);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(EmployeeVacation);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_name = new QLineEdit(EmployeeVacation);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_name);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(EmployeeVacation);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        lineEdit_auditor = new QLineEdit(EmployeeVacation);
        lineEdit_auditor->setObjectName(QString::fromUtf8("lineEdit_auditor"));
        sizePolicy.setHeightForWidth(lineEdit_auditor->sizePolicy().hasHeightForWidth());
        lineEdit_auditor->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(lineEdit_auditor);


        verticalLayout_3->addLayout(horizontalLayout_8);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(EmployeeVacation);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        dateEdit_leaveStart = new QDateEdit(EmployeeVacation);
        dateEdit_leaveStart->setObjectName(QString::fromUtf8("dateEdit_leaveStart"));
        dateEdit_leaveStart->setDate(QDate(2014, 3, 1));
        dateEdit_leaveStart->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_leaveStart->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_leaveStart->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit_leaveStart);

        dateEdit_leaveEnd = new QDateEdit(EmployeeVacation);
        dateEdit_leaveEnd->setObjectName(QString::fromUtf8("dateEdit_leaveEnd"));
        dateEdit_leaveEnd->setDateTime(QDateTime(QDate(2050, 12, 31), QTime(0, 0, 0)));
        dateEdit_leaveEnd->setDate(QDate(2050, 12, 31));
        dateEdit_leaveEnd->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_leaveEnd->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_leaveEnd->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit_leaveEnd);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(EmployeeVacation);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        dateEdit_backStart = new QDateEdit(EmployeeVacation);
        dateEdit_backStart->setObjectName(QString::fromUtf8("dateEdit_backStart"));
        dateEdit_backStart->setDate(QDate(2014, 3, 1));
        dateEdit_backStart->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_backStart->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_backStart->setCalendarPopup(true);

        horizontalLayout_4->addWidget(dateEdit_backStart);

        dateEdit_backEnd = new QDateEdit(EmployeeVacation);
        dateEdit_backEnd->setObjectName(QString::fromUtf8("dateEdit_backEnd"));
        dateEdit_backEnd->setDate(QDate(2050, 12, 31));
        dateEdit_backEnd->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_backEnd->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_backEnd->setCalendarPopup(true);

        horizontalLayout_4->addWidget(dateEdit_backEnd);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(EmployeeVacation);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        dateEdit_start = new QDateEdit(EmployeeVacation);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDate(QDate(2014, 3, 1));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout_5->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(EmployeeVacation);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout_5->addWidget(dateEdit_end);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(EmployeeVacation);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        comboBox_status = new QComboBox(EmployeeVacation);
        comboBox_status->setObjectName(QString::fromUtf8("comboBox_status"));

        horizontalLayout_7->addWidget(comboBox_status);


        horizontalLayout->addLayout(horizontalLayout_7);

        btn_clear = new QPushButton(EmployeeVacation);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(EmployeeVacation);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        tableView = new QTableView(EmployeeVacation);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_4->addWidget(tableView);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        btn_add = new QPushButton(EmployeeVacation);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_9->addWidget(btn_add);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        btn_change = new QPushButton(EmployeeVacation);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_9->addWidget(btn_change);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        btn_delete = new QPushButton(EmployeeVacation);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_9->addWidget(btn_delete);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        btn_close = new QPushButton(EmployeeVacation);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_9->addWidget(btn_close);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_9);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(EmployeeVacation);

        QMetaObject::connectSlotsByName(EmployeeVacation);
    } // setupUi

    void retranslateUi(QWidget *EmployeeVacation)
    {
        EmployeeVacation->setWindowTitle(QApplication::translate("EmployeeVacation", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EmployeeVacation", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("EmployeeVacation", "\346\211\271\345\207\206\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EmployeeVacation", "\350\257\267\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_leaveStart->setDisplayFormat(QApplication::translate("EmployeeVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_leaveEnd->setDisplayFormat(QApplication::translate("EmployeeVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EmployeeVacation", "\351\224\200\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_backStart->setDisplayFormat(QApplication::translate("EmployeeVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_backEnd->setDisplayFormat(QApplication::translate("EmployeeVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EmployeeVacation", "\346\223\215\344\275\234\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("EmployeeVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("EmployeeVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("EmployeeVacation", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        comboBox_status->clear();
        comboBox_status->insertItems(0, QStringList()
         << QApplication::translate("EmployeeVacation", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeVacation", "\345\267\262\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeVacation", "\345\267\262\351\224\200\345\201\207", 0, QApplication::UnicodeUTF8)
        );
        btn_clear->setText(QApplication::translate("EmployeeVacation", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("EmployeeVacation", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("EmployeeVacation", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("EmployeeVacation", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("EmployeeVacation", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("EmployeeVacation", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeVacation: public Ui_EmployeeVacation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEVACATION_H
