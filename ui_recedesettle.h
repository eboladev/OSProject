/********************************************************************************
** Form generated from reading UI file 'recedesettle.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEDESETTLE_H
#define UI_RECEDESETTLE_H

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
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecedeSettle
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_settle;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *RecedeSettle)
    {
        if (RecedeSettle->objectName().isEmpty())
            RecedeSettle->setObjectName(QString::fromUtf8("RecedeSettle"));
        RecedeSettle->resize(755, 418);
        gridLayout = new QGridLayout(RecedeSettle);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(RecedeSettle);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_cardNo = new QLineEdit(RecedeSettle);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_cardNo->sizePolicy().hasHeightForWidth());
        lineEdit_cardNo->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_cardNo);

        toolButton = new QToolButton(RecedeSettle);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);

        label_2 = new QLabel(RecedeSettle);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_name = new QLineEdit(RecedeSettle);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_name);

        label_3 = new QLabel(RecedeSettle);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        comboBox = new QComboBox(RecedeSettle);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        btn_clear = new QPushButton(RecedeSettle);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout_2->addWidget(btn_clear);

        btn_search = new QPushButton(RecedeSettle);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout_2->addWidget(btn_search);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(RecedeSettle);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_settle = new QPushButton(RecedeSettle);
        btn_settle->setObjectName(QString::fromUtf8("btn_settle"));

        horizontalLayout->addWidget(btn_settle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_close = new QPushButton(RecedeSettle);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout->addWidget(btn_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(RecedeSettle);

        QMetaObject::connectSlotsByName(RecedeSettle);
    } // setupUi

    void retranslateUi(QWidget *RecedeSettle)
    {
        RecedeSettle->setWindowTitle(QApplication::translate("RecedeSettle", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RecedeSettle", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("RecedeSettle", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RecedeSettle", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RecedeSettle", "\347\273\223\347\256\227\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("RecedeSettle", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RecedeSettle", "\345\267\262\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RecedeSettle", "\346\234\252\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
        );
        btn_clear->setText(QApplication::translate("RecedeSettle", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("RecedeSettle", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_settle->setText(QApplication::translate("RecedeSettle", "\351\200\200\344\275\217\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("RecedeSettle", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecedeSettle: public Ui_RecedeSettle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEDESETTLE_H
