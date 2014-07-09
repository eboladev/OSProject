/********************************************************************************
** Form generated from reading UI file 'employeevacationdialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEVACATIONDIALOG_H
#define UI_EMPLOYEEVACATIONDIALOG_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeVacationDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButton_leave;
    QRadioButton *radioButton_back;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_leave;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton;
    QComboBox *comboBox_gender;
    QComboBox *comboBox_post;
    QDateEdit *dateEdit_leave;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_back;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox_status;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_department;
    QLineEdit *lineEdit_auditor;
    QDateEdit *dateEdit_back;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *lineEdit_remark;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLineEdit *lineEdit_operator;
    QLabel *label_10;
    QDateTimeEdit *dateTimeEdit_operationTime;

    void setupUi(QDialog *EmployeeVacationDialog)
    {
        if (EmployeeVacationDialog->objectName().isEmpty())
            EmployeeVacationDialog->setObjectName(QString::fromUtf8("EmployeeVacationDialog"));
        EmployeeVacationDialog->resize(439, 287);
        layoutWidget = new QWidget(EmployeeVacationDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 230, 158, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_5->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_5->addWidget(btn_cancel);

        layoutWidget1 = new QWidget(EmployeeVacationDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 20, 395, 194));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        radioButton_leave = new QRadioButton(layoutWidget1);
        radioButton_leave->setObjectName(QString::fromUtf8("radioButton_leave"));

        horizontalLayout_6->addWidget(radioButton_leave);

        radioButton_back = new QRadioButton(layoutWidget1);
        radioButton_back->setObjectName(QString::fromUtf8("radioButton_back"));

        horizontalLayout_6->addWidget(radioButton_back);


        horizontalLayout_2->addLayout(horizontalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
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

        label_leave = new QLabel(layoutWidget1);
        label_leave->setObjectName(QString::fromUtf8("label_leave"));

        verticalLayout->addWidget(label_leave);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));

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

        dateEdit_leave = new QDateEdit(layoutWidget1);
        dateEdit_leave->setObjectName(QString::fromUtf8("dateEdit_leave"));
        dateEdit_leave->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_leave->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_leave->setCalendarPopup(true);

        verticalLayout_2->addWidget(dateEdit_leave);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_back = new QLabel(layoutWidget1);
        label_back->setObjectName(QString::fromUtf8("label_back"));

        verticalLayout_3->addWidget(label_back);


        horizontalLayout_7->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        comboBox_status = new QComboBox(layoutWidget1);
        comboBox_status->setObjectName(QString::fromUtf8("comboBox_status"));

        verticalLayout_4->addWidget(comboBox_status);

        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout_4->addWidget(lineEdit_name);

        comboBox_department = new QComboBox(layoutWidget1);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));

        verticalLayout_4->addWidget(comboBox_department);

        lineEdit_auditor = new QLineEdit(layoutWidget1);
        lineEdit_auditor->setObjectName(QString::fromUtf8("lineEdit_auditor"));

        verticalLayout_4->addWidget(lineEdit_auditor);

        dateEdit_back = new QDateEdit(layoutWidget1);
        dateEdit_back->setObjectName(QString::fromUtf8("dateEdit_back"));
        dateEdit_back->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_back->setMinimumDate(QDate(2014, 3, 1));
        dateEdit_back->setCalendarPopup(true);

        verticalLayout_4->addWidget(dateEdit_back);


        horizontalLayout_7->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        lineEdit_remark = new QLineEdit(layoutWidget1);
        lineEdit_remark->setObjectName(QString::fromUtf8("lineEdit_remark"));

        horizontalLayout_10->addWidget(lineEdit_remark);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_3->addWidget(lineEdit_operator);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        dateTimeEdit_operationTime = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit_operationTime->setObjectName(QString::fromUtf8("dateTimeEdit_operationTime"));
        dateTimeEdit_operationTime->setEnabled(false);
        dateTimeEdit_operationTime->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateTimeEdit_operationTime);


        verticalLayout_6->addLayout(horizontalLayout_3);


        retranslateUi(EmployeeVacationDialog);

        QMetaObject::connectSlotsByName(EmployeeVacationDialog);
    } // setupUi

    void retranslateUi(QDialog *EmployeeVacationDialog)
    {
        EmployeeVacationDialog->setWindowTitle(QApplication::translate("EmployeeVacationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("EmployeeVacationDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("EmployeeVacationDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        radioButton_leave->setText(QApplication::translate("EmployeeVacationDialog", "\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8));
        radioButton_back->setText(QApplication::translate("EmployeeVacationDialog", "\351\224\200\345\201\207", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmployeeVacationDialog", "\345\267\245\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EmployeeVacationDialog", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EmployeeVacationDialog", "\350\201\214\345\212\241:", 0, QApplication::UnicodeUTF8));
        label_leave->setText(QApplication::translate("EmployeeVacationDialog", "\350\257\267\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("EmployeeVacationDialog", "...", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("EmployeeVacationDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeVacationDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        comboBox_post->clear();
        comboBox_post->insertItems(0, QStringList()
         << QString()
        );
        dateEdit_leave->setDisplayFormat(QApplication::translate("EmployeeVacationDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("EmployeeVacationDialog", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EmployeeVacationDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EmployeeVacationDialog", "\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("EmployeeVacationDialog", "\346\211\271\345\207\206\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_back->setText(QApplication::translate("EmployeeVacationDialog", "\351\224\200\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        comboBox_status->clear();
        comboBox_status->insertItems(0, QStringList()
         << QApplication::translate("EmployeeVacationDialog", "\346\227\240", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeVacationDialog", "\345\267\262\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeVacationDialog", "\345\267\262\351\224\200\345\201\207", 0, QApplication::UnicodeUTF8)
        );
        comboBox_department->clear();
        comboBox_department->insertItems(0, QStringList()
         << QString()
        );
        dateEdit_back->setDisplayFormat(QApplication::translate("EmployeeVacationDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("EmployeeVacationDialog", "\350\257\264\346\230\216:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("EmployeeVacationDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("EmployeeVacationDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_operationTime->setDisplayFormat(QApplication::translate("EmployeeVacationDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeVacationDialog: public Ui_EmployeeVacationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEVACATIONDIALOG_H
