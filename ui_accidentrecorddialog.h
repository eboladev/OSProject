/********************************************************************************
** Form generated from reading UI file 'accidentrecorddialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCIDENTRECORDDIALOG_H
#define UI_ACCIDENTRECORDDIALOG_H

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
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccidentRecordDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton_cardNo;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_personInCharge;
    QToolButton *toolButton_personInCharge;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_operator;
    QLabel *label_8;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *AccidentRecordDialog)
    {
        if (AccidentRecordDialog->objectName().isEmpty())
            AccidentRecordDialog->setObjectName(QString::fromUtf8("AccidentRecordDialog"));
        AccidentRecordDialog->resize(424, 419);
        layoutWidget = new QWidget(AccidentRecordDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 370, 158, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_6->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_6->addWidget(btn_cancel);

        layoutWidget1 = new QWidget(AccidentRecordDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 11, 379, 338));
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

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        lineEdit_cardNo->setEnabled(false);

        horizontalLayout->addWidget(lineEdit_cardNo);

        toolButton_cardNo = new QToolButton(layoutWidget1);
        toolButton_cardNo->setObjectName(QString::fromUtf8("toolButton_cardNo"));

        horizontalLayout->addWidget(toolButton_cardNo);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_personInCharge = new QLineEdit(layoutWidget1);
        lineEdit_personInCharge->setObjectName(QString::fromUtf8("lineEdit_personInCharge"));

        horizontalLayout_2->addWidget(lineEdit_personInCharge);

        toolButton_personInCharge = new QToolButton(layoutWidget1);
        toolButton_personInCharge->setObjectName(QString::fromUtf8("toolButton_personInCharge"));

        horizontalLayout_2->addWidget(toolButton_personInCharge);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);

        verticalLayout_3->addWidget(lineEdit_name);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_3->addWidget(comboBox);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        dateEdit = new QDateEdit(layoutWidget1);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout_4->addWidget(dateEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_5);

        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_7->addWidget(lineEdit_operator);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        dateTimeEdit = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_7->addWidget(dateTimeEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);


        retranslateUi(AccidentRecordDialog);

        QMetaObject::connectSlotsByName(AccidentRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *AccidentRecordDialog)
    {
        AccidentRecordDialog->setWindowTitle(QApplication::translate("AccidentRecordDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("AccidentRecordDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("AccidentRecordDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AccidentRecordDialog", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AccidentRecordDialog", "\350\264\243\344\273\273\344\272\272:", 0, QApplication::UnicodeUTF8));
        toolButton_cardNo->setText(QApplication::translate("AccidentRecordDialog", "...", 0, QApplication::UnicodeUTF8));
        toolButton_personInCharge->setText(QApplication::translate("AccidentRecordDialog", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AccidentRecordDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AccidentRecordDialog", "\344\272\213\346\225\205\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
        );
        label_5->setText(QApplication::translate("AccidentRecordDialog", "\344\272\213\345\217\221\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("AccidentRecordDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AccidentRecordDialog", "\344\272\213\346\225\205\345\216\237\345\233\240\345\217\212\345\244\204\347\220\206\346\226\271\346\241\210:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AccidentRecordDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AccidentRecordDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("AccidentRecordDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccidentRecordDialog: public Ui_AccidentRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCIDENTRECORDDIALOG_H
