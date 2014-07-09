/********************************************************************************
** Form generated from reading UI file 'elderbaseinfochoosedialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELDERBASEINFOCHOOSEDIALOG_H
#define UI_ELDERBASEINFOCHOOSEDIALOG_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ElderBaseInfoChooseDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox_assess;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox_gender;
    QComboBox *comboBox_reside;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ElderBaseInfoChooseDialog)
    {
        if (ElderBaseInfoChooseDialog->objectName().isEmpty())
            ElderBaseInfoChooseDialog->setObjectName(QString::fromUtf8("ElderBaseInfoChooseDialog"));
        ElderBaseInfoChooseDialog->resize(458, 383);
        gridLayout = new QGridLayout(ElderBaseInfoChooseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ElderBaseInfoChooseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(ElderBaseInfoChooseDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(ElderBaseInfoChooseDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        comboBox_assess = new QComboBox(ElderBaseInfoChooseDialog);
        comboBox_assess->setObjectName(QString::fromUtf8("comboBox_assess"));

        verticalLayout_2->addWidget(comboBox_assess);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(ElderBaseInfoChooseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(ElderBaseInfoChooseDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        comboBox_gender = new QComboBox(ElderBaseInfoChooseDialog);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        verticalLayout_4->addWidget(comboBox_gender);

        comboBox_reside = new QComboBox(ElderBaseInfoChooseDialog);
        comboBox_reside->setObjectName(QString::fromUtf8("comboBox_reside"));

        verticalLayout_4->addWidget(comboBox_reside);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        btn_clear = new QPushButton(ElderBaseInfoChooseDialog);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        verticalLayout_5->addWidget(btn_clear);

        btn_search = new QPushButton(ElderBaseInfoChooseDialog);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        verticalLayout_5->addWidget(btn_search);


        horizontalLayout->addLayout(verticalLayout_5);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(ElderBaseInfoChooseDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_6->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(ElderBaseInfoChooseDialog);

        QMetaObject::connectSlotsByName(ElderBaseInfoChooseDialog);
    } // setupUi

    void retranslateUi(QDialog *ElderBaseInfoChooseDialog)
    {
        ElderBaseInfoChooseDialog->setWindowTitle(QApplication::translate("ElderBaseInfoChooseDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ElderBaseInfoChooseDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ElderBaseInfoChooseDialog", "\345\201\245\345\272\267\350\257\204\344\274\260:", 0, QApplication::UnicodeUTF8));
        comboBox_assess->clear();
        comboBox_assess->insertItems(0, QStringList()
         << QApplication::translate("ElderBaseInfoChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoChooseDialog", "\345\267\262\350\257\204\344\274\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoChooseDialog", "\346\234\252\350\257\204\344\274\260", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("ElderBaseInfoChooseDialog", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ElderBaseInfoChooseDialog", "\345\205\245\344\275\217\347\231\273\350\256\260:", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QApplication::translate("ElderBaseInfoChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoChooseDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoChooseDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        comboBox_reside->clear();
        comboBox_reside->insertItems(0, QStringList()
         << QApplication::translate("ElderBaseInfoChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoChooseDialog", "\345\267\262\347\231\273\350\256\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoChooseDialog", "\346\234\252\347\231\273\350\256\260", 0, QApplication::UnicodeUTF8)
        );
        btn_clear->setText(QApplication::translate("ElderBaseInfoChooseDialog", "\346\270\205\351\231\244\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("ElderBaseInfoChooseDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElderBaseInfoChooseDialog: public Ui_ElderBaseInfoChooseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELDERBASEINFOCHOOSEDIALOG_H
