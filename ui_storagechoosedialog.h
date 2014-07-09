/********************************************************************************
** Form generated from reading UI file 'storagechoosedialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORAGECHOOSEDIALOG_H
#define UI_STORAGECHOOSEDIALOG_H

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

class Ui_StorageChooseDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_type;
    QLabel *label_3;
    QComboBox *comboBox_standard;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QDialog *StorageChooseDialog)
    {
        if (StorageChooseDialog->objectName().isEmpty())
            StorageChooseDialog->setObjectName(QString::fromUtf8("StorageChooseDialog"));
        StorageChooseDialog->resize(601, 346);
        gridLayout = new QGridLayout(StorageChooseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(StorageChooseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox_type = new QComboBox(StorageChooseDialog);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        horizontalLayout->addWidget(comboBox_type);

        label_3 = new QLabel(StorageChooseDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox_standard = new QComboBox(StorageChooseDialog);
        comboBox_standard->setObjectName(QString::fromUtf8("comboBox_standard"));

        horizontalLayout->addWidget(comboBox_standard);

        label_2 = new QLabel(StorageChooseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(StorageChooseDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        btn_clear = new QPushButton(StorageChooseDialog);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(StorageChooseDialog);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(StorageChooseDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(StorageChooseDialog);

        QMetaObject::connectSlotsByName(StorageChooseDialog);
    } // setupUi

    void retranslateUi(QDialog *StorageChooseDialog)
    {
        StorageChooseDialog->setWindowTitle(QApplication::translate("StorageChooseDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StorageChooseDialog", "\347\211\251\350\265\204\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("StorageChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("StorageChooseDialog", "\350\247\204\346\240\274:", 0, QApplication::UnicodeUTF8));
        comboBox_standard->clear();
        comboBox_standard->insertItems(0, QStringList()
         << QApplication::translate("StorageChooseDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("StorageChooseDialog", "\347\211\251\350\265\204\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("StorageChooseDialog", "\346\270\205\351\231\244\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("StorageChooseDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StorageChooseDialog: public Ui_StorageChooseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORAGECHOOSEDIALOG_H
