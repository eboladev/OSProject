/********************************************************************************
** Form generated from reading UI file 'storage.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORAGE_H
#define UI_STORAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Storage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_type;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QComboBox *comboBox_standard;
    QLabel *label_4;
    QLineEdit *lineEdit_provider;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Storage)
    {
        if (Storage->objectName().isEmpty())
            Storage->setObjectName(QString::fromUtf8("Storage"));
        Storage->resize(814, 420);
        gridLayout = new QGridLayout(Storage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Storage);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox_type = new QComboBox(Storage);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        horizontalLayout->addWidget(comboBox_type);

        label_2 = new QLabel(Storage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_name = new QLineEdit(Storage);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_name);

        label_3 = new QLabel(Storage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox_standard = new QComboBox(Storage);
        comboBox_standard->setObjectName(QString::fromUtf8("comboBox_standard"));

        horizontalLayout->addWidget(comboBox_standard);

        label_4 = new QLabel(Storage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_provider = new QLineEdit(Storage);
        lineEdit_provider->setObjectName(QString::fromUtf8("lineEdit_provider"));
        sizePolicy.setHeightForWidth(lineEdit_provider->sizePolicy().hasHeightForWidth());
        lineEdit_provider->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_provider);

        btn_clear = new QPushButton(Storage);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        btn_search = new QPushButton(Storage);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(Storage);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btn_close = new QPushButton(Storage);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout_4->addWidget(btn_close);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Storage);

        QMetaObject::connectSlotsByName(Storage);
    } // setupUi

    void retranslateUi(QWidget *Storage)
    {
        Storage->setWindowTitle(QApplication::translate("Storage", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Storage", "\347\211\251\350\265\204\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("Storage", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Storage", "\347\211\251\350\265\204\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Storage", "\350\247\204\346\240\274:", 0, QApplication::UnicodeUTF8));
        comboBox_standard->clear();
        comboBox_standard->insertItems(0, QStringList()
         << QApplication::translate("Storage", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("Storage", "\344\276\233\345\272\224\345\225\206:", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("Storage", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("Storage", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("Storage", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Storage: public Ui_Storage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORAGE_H
