/********************************************************************************
** Form generated from reading UI file 'eldervacation.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELDERVACATION_H
#define UI_ELDERVACATION_H

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

class Ui_ElderVacation
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_auditor;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QDateEdit *dateEdit_leaveStart;
    QDateEdit *dateEdit_backStart;
    QVBoxLayout *verticalLayout_5;
    QDateEdit *dateEdit_leaveEnd;
    QDateEdit *dateEdit_backEnd;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *ElderVacation)
    {
        if (ElderVacation->objectName().isEmpty())
            ElderVacation->setObjectName(QString::fromUtf8("ElderVacation"));
        ElderVacation->resize(784, 481);
        gridLayout = new QGridLayout(ElderVacation);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ElderVacation);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ElderVacation);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_name = new QLineEdit(ElderVacation);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_name);

        lineEdit_auditor = new QLineEdit(ElderVacation);
        lineEdit_auditor->setObjectName(QString::fromUtf8("lineEdit_auditor"));
        sizePolicy.setHeightForWidth(lineEdit_auditor->sizePolicy().hasHeightForWidth());
        lineEdit_auditor->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_auditor);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(ElderVacation);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(ElderVacation);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        dateEdit_leaveStart = new QDateEdit(ElderVacation);
        dateEdit_leaveStart->setObjectName(QString::fromUtf8("dateEdit_leaveStart"));
        dateEdit_leaveStart->setDate(QDate(2014, 3, 1));
        dateEdit_leaveStart->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_leaveStart->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_leaveStart->setCalendarPopup(true);

        verticalLayout_4->addWidget(dateEdit_leaveStart);

        dateEdit_backStart = new QDateEdit(ElderVacation);
        dateEdit_backStart->setObjectName(QString::fromUtf8("dateEdit_backStart"));
        dateEdit_backStart->setDate(QDate(2014, 3, 1));
        dateEdit_backStart->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_backStart->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_backStart->setCalendarPopup(true);

        verticalLayout_4->addWidget(dateEdit_backStart);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        dateEdit_leaveEnd = new QDateEdit(ElderVacation);
        dateEdit_leaveEnd->setObjectName(QString::fromUtf8("dateEdit_leaveEnd"));
        dateEdit_leaveEnd->setDate(QDate(2050, 12, 31));
        dateEdit_leaveEnd->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_leaveEnd->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_leaveEnd->setCalendarPopup(true);

        verticalLayout_5->addWidget(dateEdit_leaveEnd);

        dateEdit_backEnd = new QDateEdit(ElderVacation);
        dateEdit_backEnd->setObjectName(QString::fromUtf8("dateEdit_backEnd"));
        dateEdit_backEnd->setDate(QDate(2050, 12, 31));
        dateEdit_backEnd->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_backEnd->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_backEnd->setCalendarPopup(true);

        verticalLayout_5->addWidget(dateEdit_backEnd);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(ElderVacation);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        comboBox = new QComboBox(ElderVacation);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        btn_clear = new QPushButton(ElderVacation);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        verticalLayout_6->addWidget(btn_clear);

        btn_search = new QPushButton(ElderVacation);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        verticalLayout_6->addWidget(btn_search);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_8->addLayout(horizontalLayout_2);

        tableView = new QTableView(ElderVacation);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_8->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btn_add = new QPushButton(ElderVacation);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_3->addWidget(btn_add);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btn_change = new QPushButton(ElderVacation);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_3->addWidget(btn_change);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btn_delete = new QPushButton(ElderVacation);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_3->addWidget(btn_delete);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        btn_close = new QPushButton(ElderVacation);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_3->addWidget(btn_close);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_8->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_8, 0, 0, 1, 1);


        retranslateUi(ElderVacation);

        QMetaObject::connectSlotsByName(ElderVacation);
    } // setupUi

    void retranslateUi(QWidget *ElderVacation)
    {
        ElderVacation->setWindowTitle(QApplication::translate("ElderVacation", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ElderVacation", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ElderVacation", "\346\211\271\345\207\206\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ElderVacation", "\350\257\267\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ElderVacation", "\351\224\200\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_leaveStart->setDisplayFormat(QApplication::translate("ElderVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_backStart->setDisplayFormat(QApplication::translate("ElderVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_leaveEnd->setDisplayFormat(QApplication::translate("ElderVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_backEnd->setDisplayFormat(QApplication::translate("ElderVacation", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ElderVacation", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ElderVacation", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderVacation", "\345\267\262\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderVacation", "\345\267\262\351\224\200\345\201\207", 0, QApplication::UnicodeUTF8)
        );
        btn_clear->setText(QApplication::translate("ElderVacation", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("ElderVacation", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("ElderVacation", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("ElderVacation", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("ElderVacation", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("ElderVacation", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElderVacation: public Ui_ElderVacation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELDERVACATION_H
