/********************************************************************************
** Form generated from reading UI file 'specialservicedialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECIALSERVICEDIALOG_H
#define UI_SPECIALSERVICEDIALOG_H

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
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpecialServiceDialog
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
    QLabel *label_3;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton_elder;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_personInCharge;
    QToolButton *toolButton_nurser;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_cost;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEdit_remark;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *lineEdit_operator;
    QLabel *label_9;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *SpecialServiceDialog)
    {
        if (SpecialServiceDialog->objectName().isEmpty())
            SpecialServiceDialog->setObjectName(QString::fromUtf8("SpecialServiceDialog"));
        SpecialServiceDialog->resize(430, 226);
        layoutWidget = new QWidget(SpecialServiceDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 180, 158, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout->addWidget(btn_cancel);

        layoutWidget1 = new QWidget(SpecialServiceDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 23, 391, 138));
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

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        lineEdit_cardNo->setEnabled(false);
        lineEdit_cardNo->setAcceptDrops(true);

        horizontalLayout_2->addWidget(lineEdit_cardNo);

        toolButton_elder = new QToolButton(layoutWidget1);
        toolButton_elder->setObjectName(QString::fromUtf8("toolButton_elder"));

        horizontalLayout_2->addWidget(toolButton_elder);


        verticalLayout_2->addLayout(horizontalLayout_2);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_personInCharge = new QLineEdit(layoutWidget1);
        lineEdit_personInCharge->setObjectName(QString::fromUtf8("lineEdit_personInCharge"));

        horizontalLayout_3->addWidget(lineEdit_personInCharge);

        toolButton_nurser = new QToolButton(layoutWidget1);
        toolButton_nurser->setObjectName(QString::fromUtf8("toolButton_nurser"));

        horizontalLayout_3->addWidget(toolButton_nurser);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);
        lineEdit_name->setAcceptDrops(true);

        verticalLayout_4->addWidget(lineEdit_name);

        lineEdit_cost = new QLineEdit(layoutWidget1);
        lineEdit_cost->setObjectName(QString::fromUtf8("lineEdit_cost"));
        lineEdit_cost->setEnabled(false);

        verticalLayout_4->addWidget(lineEdit_cost);

        dateEdit = new QDateEdit(layoutWidget1);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        verticalLayout_4->addWidget(dateEdit);


        horizontalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        lineEdit_remark = new QLineEdit(layoutWidget1);
        lineEdit_remark->setObjectName(QString::fromUtf8("lineEdit_remark"));

        horizontalLayout_4->addWidget(lineEdit_remark);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_5->addWidget(lineEdit_operator);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        dateTimeEdit = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_5->addWidget(dateTimeEdit);


        verticalLayout_5->addLayout(horizontalLayout_5);


        retranslateUi(SpecialServiceDialog);

        QMetaObject::connectSlotsByName(SpecialServiceDialog);
    } // setupUi

    void retranslateUi(QDialog *SpecialServiceDialog)
    {
        SpecialServiceDialog->setWindowTitle(QApplication::translate("SpecialServiceDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("SpecialServiceDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("SpecialServiceDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpecialServiceDialog", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SpecialServiceDialog", "\346\234\215\345\212\241\351\241\271\347\233\256:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SpecialServiceDialog", "\346\212\244\347\220\206\345\221\230:", 0, QApplication::UnicodeUTF8));
        toolButton_elder->setText(QApplication::translate("SpecialServiceDialog", "...", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
        );
        toolButton_nurser->setText(QApplication::translate("SpecialServiceDialog", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SpecialServiceDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SpecialServiceDialog", "\350\264\271\347\224\250:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SpecialServiceDialog", "\346\234\215\345\212\241\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("SpecialServiceDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SpecialServiceDialog", "\350\257\264\346\230\216:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SpecialServiceDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SpecialServiceDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("SpecialServiceDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpecialServiceDialog: public Ui_SpecialServiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECIALSERVICEDIALOG_H
