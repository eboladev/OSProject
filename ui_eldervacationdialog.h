/********************************************************************************
** Form generated from reading UI file 'eldervacationdialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELDERVACATIONDIALOG_H
#define UI_ELDERVACATIONDIALOG_H

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

class Ui_ElderVacationDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton_cardNo;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_auditor;
    QToolButton *toolButton_auditor;
    QDateEdit *dateEdit_leave;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox;
    QDateEdit *dateEdit_back;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *lineEdit_operator;
    QLabel *label_9;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *ElderVacationDialog)
    {
        if (ElderVacationDialog->objectName().isEmpty())
            ElderVacationDialog->setObjectName(QString::fromUtf8("ElderVacationDialog"));
        ElderVacationDialog->resize(435, 402);
        layoutWidget = new QWidget(ElderVacationDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 360, 158, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout->addWidget(btn_cancel);

        layoutWidget1 = new QWidget(ElderVacationDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 391, 336));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));

        horizontalLayout_4->addWidget(lineEdit_cardNo);

        toolButton_cardNo = new QToolButton(layoutWidget1);
        toolButton_cardNo->setObjectName(QString::fromUtf8("toolButton_cardNo"));

        horizontalLayout_4->addWidget(toolButton_cardNo);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_auditor = new QLineEdit(layoutWidget1);
        lineEdit_auditor->setObjectName(QString::fromUtf8("lineEdit_auditor"));

        horizontalLayout_5->addWidget(lineEdit_auditor);

        toolButton_auditor = new QToolButton(layoutWidget1);
        toolButton_auditor->setObjectName(QString::fromUtf8("toolButton_auditor"));

        horizontalLayout_5->addWidget(toolButton_auditor);


        verticalLayout_3->addLayout(horizontalLayout_5);

        dateEdit_leave = new QDateEdit(layoutWidget1);
        dateEdit_leave->setObjectName(QString::fromUtf8("dateEdit_leave"));
        dateEdit_leave->setCalendarPopup(true);

        verticalLayout_3->addWidget(dateEdit_leave);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout_4->addWidget(lineEdit_name);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_4->addWidget(comboBox);

        dateEdit_back = new QDateEdit(layoutWidget1);
        dateEdit_back->setObjectName(QString::fromUtf8("dateEdit_back"));
        dateEdit_back->setCalendarPopup(true);

        verticalLayout_4->addWidget(dateEdit_back);


        horizontalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_3);

        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_2->addWidget(lineEdit_operator);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);

        dateTimeEdit = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);

        horizontalLayout_2->addWidget(dateTimeEdit);


        verticalLayout_5->addLayout(horizontalLayout_2);


        retranslateUi(ElderVacationDialog);

        QMetaObject::connectSlotsByName(ElderVacationDialog);
    } // setupUi

    void retranslateUi(QDialog *ElderVacationDialog)
    {
        ElderVacationDialog->setWindowTitle(QApplication::translate("ElderVacationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("ElderVacationDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("ElderVacationDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ElderVacationDialog", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ElderVacationDialog", "\346\211\271\345\207\206\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ElderVacationDialog", "\350\257\267\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        toolButton_cardNo->setText(QApplication::translate("ElderVacationDialog", "...", 0, QApplication::UnicodeUTF8));
        toolButton_auditor->setText(QApplication::translate("ElderVacationDialog", "...", 0, QApplication::UnicodeUTF8));
        dateEdit_leave->setDisplayFormat(QApplication::translate("ElderVacationDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ElderVacationDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ElderVacationDialog", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ElderVacationDialog", "\351\224\200\345\201\207\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ElderVacationDialog", "\345\267\262\350\257\267\345\201\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderVacationDialog", "\345\267\262\351\224\200\345\201\207", 0, QApplication::UnicodeUTF8)
        );
        dateEdit_back->setDisplayFormat(QApplication::translate("ElderVacationDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ElderVacationDialog", "\350\257\264\346\230\216:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ElderVacationDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ElderVacationDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElderVacationDialog: public Ui_ElderVacationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELDERVACATIONDIALOG_H
