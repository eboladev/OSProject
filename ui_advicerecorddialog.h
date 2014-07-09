/********************************************************************************
** Form generated from reading UI file 'advicerecorddialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVICERECORDDIALOG_H
#define UI_ADVICERECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdviceRecordDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_cardNo;
    QLineEdit *lineEdit_doctor;
    QVBoxLayout *verticalLayout_3;
    QToolButton *toolButton_cardNo;
    QToolButton *toolButton_doctor;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_name;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_healthStatus;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_operator;
    QLabel *label_8;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *AdviceRecordDialog)
    {
        if (AdviceRecordDialog->objectName().isEmpty())
            AdviceRecordDialog->setObjectName(QString::fromUtf8("AdviceRecordDialog"));
        AdviceRecordDialog->resize(395, 401);
        layoutWidget = new QWidget(AdviceRecordDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 360, 158, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_4->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_4->addWidget(btn_cancel);

        layoutWidget1 = new QWidget(AdviceRecordDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 367, 334));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        lineEdit_cardNo->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_cardNo);

        lineEdit_doctor = new QLineEdit(layoutWidget1);
        lineEdit_doctor->setObjectName(QString::fromUtf8("lineEdit_doctor"));

        verticalLayout_2->addWidget(lineEdit_doctor);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toolButton_cardNo = new QToolButton(layoutWidget1);
        toolButton_cardNo->setObjectName(QString::fromUtf8("toolButton_cardNo"));

        verticalLayout_3->addWidget(toolButton_cardNo);

        toolButton_doctor = new QToolButton(layoutWidget1);
        toolButton_doctor->setObjectName(QString::fromUtf8("toolButton_doctor"));

        verticalLayout_3->addWidget(toolButton_doctor);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);

        verticalLayout_5->addWidget(lineEdit_name);

        dateEdit = new QDateEdit(layoutWidget1);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        verticalLayout_5->addWidget(dateEdit);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_healthStatus = new QLineEdit(layoutWidget1);
        lineEdit_healthStatus->setObjectName(QString::fromUtf8("lineEdit_healthStatus"));

        horizontalLayout_2->addWidget(lineEdit_healthStatus);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_3);

        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_6->addWidget(textEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_5->addWidget(lineEdit_operator);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        dateTimeEdit = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_5->addWidget(dateTimeEdit);


        verticalLayout_6->addLayout(horizontalLayout_5);


        retranslateUi(AdviceRecordDialog);

        QMetaObject::connectSlotsByName(AdviceRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *AdviceRecordDialog)
    {
        AdviceRecordDialog->setWindowTitle(QApplication::translate("AdviceRecordDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("AdviceRecordDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("AdviceRecordDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdviceRecordDialog", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AdviceRecordDialog", "\345\214\273\345\270\210:", 0, QApplication::UnicodeUTF8));
        toolButton_cardNo->setText(QApplication::translate("AdviceRecordDialog", "...", 0, QApplication::UnicodeUTF8));
        toolButton_doctor->setText(QApplication::translate("AdviceRecordDialog", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdviceRecordDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AdviceRecordDialog", "\345\214\273\345\230\261\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("AdviceRecordDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AdviceRecordDialog", "\345\201\245\345\272\267\347\212\266\345\206\265:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AdviceRecordDialog", "\345\214\273\345\230\261:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AdviceRecordDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AdviceRecordDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("AdviceRecordDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdviceRecordDialog: public Ui_AdviceRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVICERECORDDIALOG_H
