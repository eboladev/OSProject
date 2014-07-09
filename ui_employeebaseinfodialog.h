/********************************************************************************
** Form generated from reading UI file 'employeebaseinfodialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEBASEINFODIALOG_H
#define UI_EMPLOYEEBASEINFODIALOG_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeBaseInfoDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_cardNo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox_identityType;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QDateEdit *dateEdit_birthday;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QComboBox *comboBox_post;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLineEdit *lineEdit_school;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QComboBox *comboBox_computer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QLineEdit *lineEdit_residence;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_21;
    QLineEdit *lineEdit_operator;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *lineEdit_identityNo;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QComboBox *comboBox_maritalStatus;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_23;
    QDateEdit *dateEdit_entryDate;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QLineEdit *lineEdit_major;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_17;
    QLineEdit *lineEdit_address;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_19;
    QLineEdit *lineEdit_zipCode;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_22;
    QDateTimeEdit *dateTimeEdit_operationTime;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_3;
    QComboBox *comboBox_gender;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_6;
    QComboBox *comboBox_status;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_9;
    QComboBox *comboBox_department;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_11;
    QComboBox *comboBox_degree;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_14;
    QComboBox *comboBox_english;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_18;
    QLineEdit *lineEdit_telephone;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_20;
    QLineEdit *lineEdit_remark;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *EmployeeBaseInfoDialog)
    {
        if (EmployeeBaseInfoDialog->objectName().isEmpty())
            EmployeeBaseInfoDialog->setObjectName(QString::fromUtf8("EmployeeBaseInfoDialog"));
        EmployeeBaseInfoDialog->resize(591, 321);
        layoutWidget = new QWidget(EmployeeBaseInfoDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 270, 158, 25));
        horizontalLayout_25 = new QHBoxLayout(layoutWidget);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_25->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_25->addWidget(btn_cancel);

        layoutWidget1 = new QWidget(EmployeeBaseInfoDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(6, 16, 572, 224));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_cardNo = new QLineEdit(layoutWidget1);
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
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        comboBox_identityType = new QComboBox(layoutWidget1);
        comboBox_identityType->setObjectName(QString::fromUtf8("comboBox_identityType"));

        horizontalLayout_2->addWidget(comboBox_identityType);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        dateEdit_birthday = new QDateEdit(layoutWidget1);
        dateEdit_birthday->setObjectName(QString::fromUtf8("dateEdit_birthday"));
        dateEdit_birthday->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit_birthday);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        comboBox_post = new QComboBox(layoutWidget1);
        comboBox_post->setObjectName(QString::fromUtf8("comboBox_post"));

        horizontalLayout_4->addWidget(comboBox_post);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        lineEdit_school = new QLineEdit(layoutWidget1);
        lineEdit_school->setObjectName(QString::fromUtf8("lineEdit_school"));
        sizePolicy.setHeightForWidth(lineEdit_school->sizePolicy().hasHeightForWidth());
        lineEdit_school->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_school);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_6->addWidget(label_15);

        comboBox_computer = new QComboBox(layoutWidget1);
        comboBox_computer->setObjectName(QString::fromUtf8("comboBox_computer"));

        horizontalLayout_6->addWidget(comboBox_computer);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_7->addWidget(label_16);

        lineEdit_residence = new QLineEdit(layoutWidget1);
        lineEdit_residence->setObjectName(QString::fromUtf8("lineEdit_residence"));

        horizontalLayout_7->addWidget(lineEdit_residence);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_23->addWidget(label_21);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_operator->sizePolicy().hasHeightForWidth());
        lineEdit_operator->setSizePolicy(sizePolicy);

        horizontalLayout_23->addWidget(lineEdit_operator);


        verticalLayout_4->addLayout(horizontalLayout_23);


        horizontalLayout_22->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(lineEdit_name);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        lineEdit_identityNo = new QLineEdit(layoutWidget1);
        lineEdit_identityNo->setObjectName(QString::fromUtf8("lineEdit_identityNo"));
        sizePolicy.setHeightForWidth(lineEdit_identityNo->sizePolicy().hasHeightForWidth());
        lineEdit_identityNo->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(lineEdit_identityNo);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        comboBox_maritalStatus = new QComboBox(layoutWidget1);
        comboBox_maritalStatus->setObjectName(QString::fromUtf8("comboBox_maritalStatus"));

        horizontalLayout_10->addWidget(comboBox_maritalStatus);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_11->addWidget(label_23);

        dateEdit_entryDate = new QDateEdit(layoutWidget1);
        dateEdit_entryDate->setObjectName(QString::fromUtf8("dateEdit_entryDate"));
        dateEdit_entryDate->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_entryDate->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_entryDate->setCalendarPopup(true);

        horizontalLayout_11->addWidget(dateEdit_entryDate);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_12->addWidget(label_13);

        lineEdit_major = new QLineEdit(layoutWidget1);
        lineEdit_major->setObjectName(QString::fromUtf8("lineEdit_major"));
        sizePolicy.setHeightForWidth(lineEdit_major->sizePolicy().hasHeightForWidth());
        lineEdit_major->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(lineEdit_major);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_13->addWidget(label_17);

        lineEdit_address = new QLineEdit(layoutWidget1);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));
        sizePolicy.setHeightForWidth(lineEdit_address->sizePolicy().hasHeightForWidth());
        lineEdit_address->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(lineEdit_address);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_14->addWidget(label_19);

        lineEdit_zipCode = new QLineEdit(layoutWidget1);
        lineEdit_zipCode->setObjectName(QString::fromUtf8("lineEdit_zipCode"));
        sizePolicy.setHeightForWidth(lineEdit_zipCode->sizePolicy().hasHeightForWidth());
        lineEdit_zipCode->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(lineEdit_zipCode);


        verticalLayout_2->addLayout(horizontalLayout_14);


        verticalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_24->addWidget(label_22);

        dateTimeEdit_operationTime = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit_operationTime->setObjectName(QString::fromUtf8("dateTimeEdit_operationTime"));
        dateTimeEdit_operationTime->setEnabled(false);
        dateTimeEdit_operationTime->setMaximumDate(QDate(2050, 12, 31));
        dateTimeEdit_operationTime->setMinimumDate(QDate(2014, 3, 1));
        dateTimeEdit_operationTime->setCalendarPopup(true);

        horizontalLayout_24->addWidget(dateTimeEdit_operationTime);


        verticalLayout_5->addLayout(horizontalLayout_24);


        horizontalLayout_22->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_15->addWidget(label_3);

        comboBox_gender = new QComboBox(layoutWidget1);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        horizontalLayout_15->addWidget(comboBox_gender);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_16->addWidget(label_6);

        comboBox_status = new QComboBox(layoutWidget1);
        comboBox_status->setObjectName(QString::fromUtf8("comboBox_status"));

        horizontalLayout_16->addWidget(comboBox_status);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_17->addWidget(label_9);

        comboBox_department = new QComboBox(layoutWidget1);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));

        horizontalLayout_17->addWidget(comboBox_department);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_18->addWidget(label_11);

        comboBox_degree = new QComboBox(layoutWidget1);
        comboBox_degree->setObjectName(QString::fromUtf8("comboBox_degree"));

        horizontalLayout_18->addWidget(comboBox_degree);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_19->addWidget(label_14);

        comboBox_english = new QComboBox(layoutWidget1);
        comboBox_english->setObjectName(QString::fromUtf8("comboBox_english"));

        horizontalLayout_19->addWidget(comboBox_english);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_20->addWidget(label_18);

        lineEdit_telephone = new QLineEdit(layoutWidget1);
        lineEdit_telephone->setObjectName(QString::fromUtf8("lineEdit_telephone"));
        sizePolicy.setHeightForWidth(lineEdit_telephone->sizePolicy().hasHeightForWidth());
        lineEdit_telephone->setSizePolicy(sizePolicy);

        horizontalLayout_20->addWidget(lineEdit_telephone);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_21->addWidget(label_20);

        lineEdit_remark = new QLineEdit(layoutWidget1);
        lineEdit_remark->setObjectName(QString::fromUtf8("lineEdit_remark"));
        sizePolicy.setHeightForWidth(lineEdit_remark->sizePolicy().hasHeightForWidth());
        lineEdit_remark->setSizePolicy(sizePolicy);

        horizontalLayout_21->addWidget(lineEdit_remark);


        verticalLayout_3->addLayout(horizontalLayout_21);


        verticalLayout_6->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_2);


        horizontalLayout_22->addLayout(verticalLayout_6);


        retranslateUi(EmployeeBaseInfoDialog);

        QMetaObject::connectSlotsByName(EmployeeBaseInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *EmployeeBaseInfoDialog)
    {
        EmployeeBaseInfoDialog->setWindowTitle(QApplication::translate("EmployeeBaseInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("EmployeeBaseInfoDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\267\245\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EmployeeBaseInfoDialog", "\350\257\201\344\273\266\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        comboBox_identityType->clear();
        comboBox_identityType->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("EmployeeBaseInfoDialog", "\350\272\253\344\273\275\350\257\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseInfoDialog", "\345\206\233\345\256\230\350\257\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseInfoDialog", "\346\212\244\347\205\247", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseInfoDialog", "\351\251\276\351\251\266\350\257\201", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\207\272\347\224\237\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_birthday->setDisplayFormat(QApplication::translate("EmployeeBaseInfoDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("EmployeeBaseInfoDialog", "\350\201\214\345\212\241:", 0, QApplication::UnicodeUTF8));
        comboBox_post->clear();
        comboBox_post->insertItems(0, QStringList()
         << QString()
        );
        label_12->setText(QApplication::translate("EmployeeBaseInfoDialog", "\346\257\225\344\270\232\351\231\242\346\240\241:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("EmployeeBaseInfoDialog", "\350\256\241\347\256\227\346\234\272\346\260\264\345\271\263:", 0, QApplication::UnicodeUTF8));
        comboBox_computer->clear();
        comboBox_computer->insertItems(0, QStringList()
         << QString()
        );
        label_16->setText(QApplication::translate("EmployeeBaseInfoDialog", "\346\210\267\347\261\215\346\211\200\345\234\250\345\234\260:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("EmployeeBaseInfoDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EmployeeBaseInfoDialog", "\350\257\201\344\273\266\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\251\232\345\247\273\347\212\266\345\206\265:", 0, QApplication::UnicodeUTF8));
        comboBox_maritalStatus->clear();
        comboBox_maritalStatus->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("EmployeeBaseInfoDialog", "\345\267\262\345\251\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseInfoDialog", "\346\234\252\345\251\232", 0, QApplication::UnicodeUTF8)
        );
        label_23->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\205\245\350\201\214\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_entryDate->setDisplayFormat(QApplication::translate("EmployeeBaseInfoDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("EmployeeBaseInfoDialog", "\344\270\223\344\270\232:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("EmployeeBaseInfoDialog", "\347\216\260\345\261\205\345\234\260:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("EmployeeBaseInfoDialog", "\351\202\256\347\274\226:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("EmployeeBaseInfoDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_operationTime->setDisplayFormat(QApplication::translate("EmployeeBaseInfoDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EmployeeBaseInfoDialog", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("EmployeeBaseInfoDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseInfoDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("EmployeeBaseInfoDialog", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        comboBox_status->clear();
        comboBox_status->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("EmployeeBaseInfoDialog", "\345\234\250\350\201\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeBaseInfoDialog", "\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("EmployeeBaseInfoDialog", "\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        comboBox_department->clear();
        comboBox_department->insertItems(0, QStringList()
         << QString()
        );
        label_11->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\255\246\345\216\206:", 0, QApplication::UnicodeUTF8));
        comboBox_degree->clear();
        comboBox_degree->insertItems(0, QStringList()
         << QString()
        );
        label_14->setText(QApplication::translate("EmployeeBaseInfoDialog", "\350\213\261\350\257\255\346\260\264\345\271\263:", 0, QApplication::UnicodeUTF8));
        comboBox_english->clear();
        comboBox_english->insertItems(0, QStringList()
         << QString()
        );
        label_18->setText(QApplication::translate("EmployeeBaseInfoDialog", "\350\201\224\347\263\273\346\226\271\345\274\217:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("EmployeeBaseInfoDialog", "\345\244\207\346\263\250:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeBaseInfoDialog: public Ui_EmployeeBaseInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEBASEINFODIALOG_H
