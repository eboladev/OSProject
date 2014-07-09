/********************************************************************************
** Form generated from reading UI file 'checkoutdialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTDIALOG_H
#define UI_CHECKOUTDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckOutDialog
{
public:
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton;
    QComboBox *comboBox_gender;
    QComboBox *comboBox_post;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_type;
    QToolButton *toolButton_storage;
    QComboBox *comboBox_standard;
    QLineEdit *lineEdit_rate;
    QLineEdit *lineEdit_provider;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_claimer;
    QComboBox *comboBox_department;
    QLineEdit *lineEdit_auditor;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_unit;
    QLineEdit *lineEdit_amount;
    QComboBox *comboBox_warehouse;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QDateEdit *dateEdit_outDate;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *lineEdit_operator;
    QLabel *label_17;
    QDateTimeEdit *dateTimeEdit_operationTime;

    void setupUi(QDialog *CheckOutDialog)
    {
        if (CheckOutDialog->objectName().isEmpty())
            CheckOutDialog->setObjectName(QString::fromUtf8("CheckOutDialog"));
        CheckOutDialog->resize(435, 328);
        layoutWidget1 = new QWidget(CheckOutDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 280, 158, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget1);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_6->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget1);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_6->addWidget(btn_cancel);

        widget = new QWidget(CheckOutDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(21, 22, 391, 244));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout->addWidget(label_13);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_cardNo = new QLineEdit(widget);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_cardNo);

        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout);

        comboBox_gender = new QComboBox(widget);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        verticalLayout_2->addWidget(comboBox_gender);

        comboBox_post = new QComboBox(widget);
        comboBox_post->setObjectName(QString::fromUtf8("comboBox_post"));

        verticalLayout_2->addWidget(comboBox_post);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox_type = new QComboBox(widget);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        horizontalLayout_2->addWidget(comboBox_type);

        toolButton_storage = new QToolButton(widget);
        toolButton_storage->setObjectName(QString::fromUtf8("toolButton_storage"));

        horizontalLayout_2->addWidget(toolButton_storage);


        verticalLayout_2->addLayout(horizontalLayout_2);

        comboBox_standard = new QComboBox(widget);
        comboBox_standard->setObjectName(QString::fromUtf8("comboBox_standard"));

        verticalLayout_2->addWidget(comboBox_standard);

        lineEdit_rate = new QLineEdit(widget);
        lineEdit_rate->setObjectName(QString::fromUtf8("lineEdit_rate"));

        verticalLayout_2->addWidget(lineEdit_rate);

        lineEdit_provider = new QLineEdit(widget);
        lineEdit_provider->setObjectName(QString::fromUtf8("lineEdit_provider"));

        verticalLayout_2->addWidget(lineEdit_provider);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_3->addWidget(label_14);


        horizontalLayout_7->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_claimer = new QLineEdit(widget);
        lineEdit_claimer->setObjectName(QString::fromUtf8("lineEdit_claimer"));
        sizePolicy.setHeightForWidth(lineEdit_claimer->sizePolicy().hasHeightForWidth());
        lineEdit_claimer->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_claimer);

        comboBox_department = new QComboBox(widget);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));

        verticalLayout_4->addWidget(comboBox_department);

        lineEdit_auditor = new QLineEdit(widget);
        lineEdit_auditor->setObjectName(QString::fromUtf8("lineEdit_auditor"));
        sizePolicy.setHeightForWidth(lineEdit_auditor->sizePolicy().hasHeightForWidth());
        lineEdit_auditor->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_auditor);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_name);

        comboBox_unit = new QComboBox(widget);
        comboBox_unit->setObjectName(QString::fromUtf8("comboBox_unit"));

        verticalLayout_4->addWidget(comboBox_unit);

        lineEdit_amount = new QLineEdit(widget);
        lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));
        sizePolicy.setHeightForWidth(lineEdit_amount->sizePolicy().hasHeightForWidth());
        lineEdit_amount->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_amount);

        comboBox_warehouse = new QComboBox(widget);
        comboBox_warehouse->setObjectName(QString::fromUtf8("comboBox_warehouse"));

        verticalLayout_4->addWidget(comboBox_warehouse);


        horizontalLayout_7->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_3->addWidget(label_15);

        dateEdit_outDate = new QDateEdit(widget);
        dateEdit_outDate->setObjectName(QString::fromUtf8("dateEdit_outDate"));
        dateEdit_outDate->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_outDate->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_outDate->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit_outDate);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_5->addWidget(label_16);

        lineEdit_operator = new QLineEdit(widget);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_operator->sizePolicy().hasHeightForWidth());
        lineEdit_operator->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_operator);

        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_5->addWidget(label_17);

        dateTimeEdit_operationTime = new QDateTimeEdit(widget);
        dateTimeEdit_operationTime->setObjectName(QString::fromUtf8("dateTimeEdit_operationTime"));
        dateTimeEdit_operationTime->setEnabled(false);
        dateTimeEdit_operationTime->setMaximumDate(QDate(2050, 12, 31));
        dateTimeEdit_operationTime->setMinimumDate(QDate(2014, 3, 1));
        dateTimeEdit_operationTime->setCalendarPopup(true);

        horizontalLayout_5->addWidget(dateTimeEdit_operationTime);


        verticalLayout_5->addLayout(horizontalLayout_5);


        retranslateUi(CheckOutDialog);

        QMetaObject::connectSlotsByName(CheckOutDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckOutDialog)
    {
        CheckOutDialog->setWindowTitle(QApplication::translate("CheckOutDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("CheckOutDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("CheckOutDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CheckOutDialog", "\345\267\245\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CheckOutDialog", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CheckOutDialog", "\350\201\214\345\212\241:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CheckOutDialog", "\347\211\251\350\265\204\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("CheckOutDialog", "\350\247\204\346\240\274:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CheckOutDialog", "\345\215\225\344\273\267(\345\205\203):", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("CheckOutDialog", "\344\276\233\345\272\224\345\225\206:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("CheckOutDialog", "...", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("CheckOutDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CheckOutDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        comboBox_post->clear();
        comboBox_post->insertItems(0, QStringList()
         << QString()
        );
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QString()
        );
        toolButton_storage->setText(QApplication::translate("CheckOutDialog", "...", 0, QApplication::UnicodeUTF8));
        comboBox_standard->clear();
        comboBox_standard->insertItems(0, QStringList()
         << QString()
        );
        label_2->setText(QApplication::translate("CheckOutDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CheckOutDialog", "\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CheckOutDialog", "\346\211\271\345\207\206\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CheckOutDialog", "\347\211\251\350\265\204\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CheckOutDialog", "\345\215\225\344\275\215:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("CheckOutDialog", "\346\225\260\351\207\217:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("CheckOutDialog", "\344\273\223\345\272\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        comboBox_department->clear();
        comboBox_department->insertItems(0, QStringList()
         << QString()
        );
        comboBox_unit->clear();
        comboBox_unit->insertItems(0, QStringList()
         << QString()
        );
        comboBox_warehouse->clear();
        comboBox_warehouse->insertItems(0, QStringList()
         << QString()
        );
        label_15->setText(QApplication::translate("CheckOutDialog", "\345\207\272\345\272\223\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateEdit_outDate->setDisplayFormat(QApplication::translate("CheckOutDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("CheckOutDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("CheckOutDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_operationTime->setDisplayFormat(QApplication::translate("CheckOutDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckOutDialog: public Ui_CheckOutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
