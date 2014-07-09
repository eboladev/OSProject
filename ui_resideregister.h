/********************************************************************************
** Form generated from reading UI file 'resideregister.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIDEREGISTER_H
#define UI_RESIDEREGISTER_H

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

class Ui_ResideRegister
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_cardNo;
    QLineEdit *lineEdit_name;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_contractNo;
    QComboBox *comboBox_nurseLevel;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox_bedLevel;
    QComboBox *comboBox_status;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *ResideRegister)
    {
        if (ResideRegister->objectName().isEmpty())
            ResideRegister->setObjectName(QString::fromUtf8("ResideRegister"));
        ResideRegister->resize(850, 448);
        gridLayout = new QGridLayout(ResideRegister);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ResideRegister);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ResideRegister);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_cardNo = new QLineEdit(ResideRegister);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_cardNo);

        lineEdit_name = new QLineEdit(ResideRegister);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_name);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(ResideRegister);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(ResideRegister);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_contractNo = new QLineEdit(ResideRegister);
        lineEdit_contractNo->setObjectName(QString::fromUtf8("lineEdit_contractNo"));
        sizePolicy.setHeightForWidth(lineEdit_contractNo->sizePolicy().hasHeightForWidth());
        lineEdit_contractNo->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_contractNo);

        comboBox_nurseLevel = new QComboBox(ResideRegister);
        comboBox_nurseLevel->setObjectName(QString::fromUtf8("comboBox_nurseLevel"));

        verticalLayout_4->addWidget(comboBox_nurseLevel);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(ResideRegister);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_3 = new QLabel(ResideRegister);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        comboBox_bedLevel = new QComboBox(ResideRegister);
        comboBox_bedLevel->setObjectName(QString::fromUtf8("comboBox_bedLevel"));

        verticalLayout_6->addWidget(comboBox_bedLevel);

        comboBox_status = new QComboBox(ResideRegister);
        comboBox_status->setObjectName(QString::fromUtf8("comboBox_status"));

        verticalLayout_6->addWidget(comboBox_status);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(ResideRegister);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        dateEdit_start = new QDateEdit(ResideRegister);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setDate(QDate(2014, 3, 1));
        dateEdit_start->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_start->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(ResideRegister);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDate(QDate(2050, 12, 31));
        dateEdit_end->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_end->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_end);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_clear = new QPushButton(ResideRegister);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(ResideRegister);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);


        verticalLayout_7->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_3);

        tableView = new QTableView(ResideRegister);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_8->addWidget(tableView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btn_add = new QPushButton(ResideRegister);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_4->addWidget(btn_add);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_change = new QPushButton(ResideRegister);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));

        horizontalLayout_4->addWidget(btn_change);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btn_delete = new QPushButton(ResideRegister);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_4->addWidget(btn_delete);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        btn_close = new QPushButton(ResideRegister);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_4->addWidget(btn_close);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_8->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_8, 0, 0, 1, 1);


        retranslateUi(ResideRegister);

        QMetaObject::connectSlotsByName(ResideRegister);
    } // setupUi

    void retranslateUi(QWidget *ResideRegister)
    {
        ResideRegister->setWindowTitle(QApplication::translate("ResideRegister", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ResideRegister", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ResideRegister", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ResideRegister", "\345\220\210\345\220\214\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ResideRegister", "\346\212\244\347\220\206\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_nurseLevel->clear();
        comboBox_nurseLevel->insertItems(0, QStringList()
         << QApplication::translate("ResideRegister", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("ResideRegister", "\345\272\212\344\275\215\347\272\247\345\210\253", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ResideRegister", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        comboBox_bedLevel->clear();
        comboBox_bedLevel->insertItems(0, QStringList()
         << QApplication::translate("ResideRegister", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        comboBox_status->clear();
        comboBox_status->insertItems(0, QStringList()
         << QApplication::translate("ResideRegister", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ResideRegister", "\345\205\245\344\275\217", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ResideRegister", "\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ResideRegister", "\351\200\200\344\275\217", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("ResideRegister", "\345\205\245\344\275\217\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("ResideRegister", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("ResideRegister", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("ResideRegister", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("ResideRegister", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("ResideRegister", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change->setText(QApplication::translate("ResideRegister", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("ResideRegister", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("ResideRegister", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ResideRegister: public Ui_ResideRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIDEREGISTER_H
