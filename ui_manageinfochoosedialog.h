/********************************************************************************
** Form generated from reading UI file 'manageinfochoosedialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEINFOCHOOSEDIALOG_H
#define UI_MANAGEINFOCHOOSEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ManageInfoChooseDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_cardNo;
    QComboBox *comboBox_selfNurse;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_nurseLevel;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_contractNo;
    QComboBox *comboBox_bedLevel;
    QVBoxLayout *verticalLayout_7;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ManageInfoChooseDialog)
    {
        if (ManageInfoChooseDialog->objectName().isEmpty())
            ManageInfoChooseDialog->setObjectName(QString::fromUtf8("ManageInfoChooseDialog"));
        ManageInfoChooseDialog->resize(650, 392);
        gridLayout = new QGridLayout(ManageInfoChooseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ManageInfoChooseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(ManageInfoChooseDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_cardNo = new QLineEdit(ManageInfoChooseDialog);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_cardNo);

        comboBox_selfNurse = new QComboBox(ManageInfoChooseDialog);
        comboBox_selfNurse->setObjectName(QString::fromUtf8("comboBox_selfNurse"));

        verticalLayout_2->addWidget(comboBox_selfNurse);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(ManageInfoChooseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_5 = new QLabel(ManageInfoChooseDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_name = new QLineEdit(ManageInfoChooseDialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEdit_name);

        comboBox_nurseLevel = new QComboBox(ManageInfoChooseDialog);
        comboBox_nurseLevel->setObjectName(QString::fromUtf8("comboBox_nurseLevel"));

        verticalLayout_4->addWidget(comboBox_nurseLevel);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(ManageInfoChooseDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        label_6 = new QLabel(ManageInfoChooseDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lineEdit_contractNo = new QLineEdit(ManageInfoChooseDialog);
        lineEdit_contractNo->setObjectName(QString::fromUtf8("lineEdit_contractNo"));
        sizePolicy.setHeightForWidth(lineEdit_contractNo->sizePolicy().hasHeightForWidth());
        lineEdit_contractNo->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(lineEdit_contractNo);

        comboBox_bedLevel = new QComboBox(ManageInfoChooseDialog);
        comboBox_bedLevel->setObjectName(QString::fromUtf8("comboBox_bedLevel"));

        verticalLayout_6->addWidget(comboBox_bedLevel);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        btn_clear = new QPushButton(ManageInfoChooseDialog);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        verticalLayout_7->addWidget(btn_clear);

        btn_search = new QPushButton(ManageInfoChooseDialog);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        verticalLayout_7->addWidget(btn_search);


        horizontalLayout->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(ManageInfoChooseDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_8->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout_8, 0, 0, 1, 1);


        retranslateUi(ManageInfoChooseDialog);

        QMetaObject::connectSlotsByName(ManageInfoChooseDialog);
    } // setupUi

    void retranslateUi(QDialog *ManageInfoChooseDialog)
    {
        ManageInfoChooseDialog->setWindowTitle(QApplication::translate("ManageInfoChooseDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManageInfoChooseDialog", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ManageInfoChooseDialog", "\350\207\252\347\220\206\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_selfNurse->clear();
        comboBox_selfNurse->insertItems(0, QStringList()
         << QApplication::translate("ManageInfoChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("ManageInfoChooseDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ManageInfoChooseDialog", "\346\212\244\347\220\206\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_nurseLevel->clear();
        comboBox_nurseLevel->insertItems(0, QStringList()
         << QApplication::translate("ManageInfoChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("ManageInfoChooseDialog", "\345\220\210\345\220\214\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ManageInfoChooseDialog", "\345\272\212\344\275\215\347\272\247\345\210\253", 0, QApplication::UnicodeUTF8));
        comboBox_bedLevel->clear();
        comboBox_bedLevel->insertItems(0, QStringList()
         << QApplication::translate("ManageInfoChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        btn_clear->setText(QApplication::translate("ManageInfoChooseDialog", "\346\270\205\351\231\244\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("ManageInfoChooseDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManageInfoChooseDialog: public Ui_ManageInfoChooseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEINFOCHOOSEDIALOG_H
