/********************************************************************************
** Form generated from reading UI file 'checkindialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKINDIALOG_H
#define UI_CHECKINDIALOG_H

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

class Ui_CheckInDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton;
    QComboBox *comboBox_gender;
    QComboBox *comboBox_post;
    QComboBox *comboBox_type;
    QComboBox *comboBox_standard;
    QLineEdit *lineEdit_rate;
    QLineEdit *lineEdit_provider;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_buyer;
    QComboBox *comboBox_department;
    QLineEdit *lineEdit_auditor;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_unit;
    QLineEdit *lineEdit_amount;
    QComboBox *comboBox_warehouse;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QDateEdit *dateEdit_inDate;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *lineEdit_operator;
    QLabel *label_17;
    QDateTimeEdit *dateTimeEdit_operationTime;

    void setupUi(QDialog *CheckInDialog)
    {
        if (CheckInDialog->objectName().isEmpty())
            CheckInDialog->setObjectName(QString::fromUtf8("CheckInDialog"));
        CheckInDialog->resize(446, 337);
        layoutWidget = new QWidget(CheckInDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 290, 158, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout_4->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_4->addWidget(pushButton_cancel);

        layoutWidget1 = new QWidget(CheckInDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 19, 393, 266));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout->addWidget(label_13);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_cardNo);

        toolButton = new QToolButton(layoutWidget1);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout);

        comboBox_gender = new QComboBox(layoutWidget1);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        verticalLayout_2->addWidget(comboBox_gender);

        comboBox_post = new QComboBox(layoutWidget1);
        comboBox_post->setObjectName(QString::fromUtf8("comboBox_post"));

        verticalLayout_2->addWidget(comboBox_post);

        comboBox_type = new QComboBox(layoutWidget1);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        verticalLayout_2->addWidget(comboBox_type);

        comboBox_standard = new QComboBox(layoutWidget1);
        comboBox_standard->setObjectName(QString::fromUtf8("comboBox_standard"));

        verticalLayout_2->addWidget(comboBox_standard);

        lineEdit_rate = new QLineEdit(layoutWidget1);
        lineEdit_rate->setObjectName(QString::fromUtf8("lineEdit_rate"));
        sizePolicy.setHeightForWidth(lineEdit_rate->sizePolicy().hasHeightForWidth());
        lineEdit_rate->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_rate);

        lineEdit_provider = new QLineEdit(layoutWidget1);
        lineEdit_provider->setObjectName(QString::fromUtf8("lineEdit_provider"));

        verticalLayout_2->addWidget(lineEdit_provider);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_3->addWidget(label_11);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_3->addWidget(label_14);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_buyer = new QLineEdit(layoutWidget1);
        lineEdit_buyer->setObjectName(QString::fromUtf8("lineEdit_buyer"));
        sizePolicy.setHeightForWidth(lineEdit_buyer->sizePolicy().hasHeightForWidth());
        lineEdit_buyer->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_buyer);

        comboBox_department = new QComboBox(layoutWidget1);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));

        verticalLayout_4->addWidget(comboBox_department);

        lineEdit_auditor = new QLineEdit(layoutWidget1);
        lineEdit_auditor->setObjectName(QString::fromUtf8("lineEdit_auditor"));
        sizePolicy.setHeightForWidth(lineEdit_auditor->sizePolicy().hasHeightForWidth());
        lineEdit_auditor->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_auditor);

        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout_4->addWidget(lineEdit_name);

        comboBox_unit = new QComboBox(layoutWidget1);
        comboBox_unit->setObjectName(QString::fromUtf8("comboBox_unit"));

        verticalLayout_4->addWidget(comboBox_unit);

        lineEdit_amount = new QLineEdit(layoutWidget1);
        lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));
        sizePolicy.setHeightForWidth(lineEdit_amount->sizePolicy().hasHeightForWidth());
        lineEdit_amount->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_amount);

        comboBox_warehouse = new QComboBox(layoutWidget1);
        comboBox_warehouse->setObjectName(QString::fromUtf8("comboBox_warehouse"));

        verticalLayout_4->addWidget(comboBox_warehouse);


        horizontalLayout_2->addLayout(verticalLayout_4);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_6->addWidget(label_15);

        dateEdit_inDate = new QDateEdit(layoutWidget1);
        dateEdit_inDate->setObjectName(QString::fromUtf8("dateEdit_inDate"));
        dateEdit_inDate->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_inDate->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_inDate->setCalendarPopup(true);

        horizontalLayout_6->addWidget(dateEdit_inDate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_5->addWidget(label_16);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_5->addWidget(lineEdit_operator);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_5->addWidget(label_17);

        dateTimeEdit_operationTime = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit_operationTime->setObjectName(QString::fromUtf8("dateTimeEdit_operationTime"));
        dateTimeEdit_operationTime->setEnabled(false);
        dateTimeEdit_operationTime->setMaximumDate(QDate(2050, 12, 31));
        dateTimeEdit_operationTime->setMinimumDate(QDate(2014, 3, 1));
        dateTimeEdit_operationTime->setCalendarPopup(true);

        horizontalLayout_5->addWidget(dateTimeEdit_operationTime);


        verticalLayout_5->addLayout(horizontalLayout_5);


        retranslateUi(CheckInDialog);

        QMetaObject::connectSlotsByName(CheckInDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckInDialog)
    {
        CheckInDialog->setWindowTitle(QApplication::translate("CheckInDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("CheckInDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("CheckInDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CheckInDialog", "\345\267\245\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CheckInDialog", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CheckInDialog", "\350\201\214\345\212\241:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CheckInDialog", "\347\211\251\350\265\204\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CheckInDialog", "\350\247\204\346\240\274:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CheckInDialog", "\345\215\225\344\273\267(\345\205\203):", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("CheckInDialog", "\344\276\233\345\272\224\345\225\206:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("CheckInDialog", "...", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("CheckInDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CheckInDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        comboBox_post->clear();
        comboBox_post->insertItems(0, QStringList()
         << QString()
        );
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QString()
        );
        comboBox_standard->clear();
        comboBox_standard->insertItems(0, QStringList()
         << QString()
        );
        label_2->setText(QApplication::translate("CheckInDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CheckInDialog", "\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CheckInDialog", "\346\211\271\345\207\206\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CheckInDialog", "\347\211\251\350\265\204\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("CheckInDialog", "\345\215\225\344\275\215:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("CheckInDialog", "\346\225\260\351\207\217:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("CheckInDialog", "\344\273\223\345\272\223\345\220\215:", 0, QApplication::UnicodeUTF8));
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
        label_15->setText(QApplication::translate("CheckInDialog", "\345\205\245\345\272\223\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateEdit_inDate->setDisplayFormat(QApplication::translate("CheckInDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("CheckInDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("CheckInDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_operationTime->setDisplayFormat(QApplication::translate("CheckInDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckInDialog: public Ui_CheckInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKINDIALOG_H
