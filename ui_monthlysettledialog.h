/********************************************************************************
** Form generated from reading UI file 'monthlysettledialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHLYSETTLEDIALOG_H
#define UI_MONTHLYSETTLEDIALOG_H

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
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonthlySettleDialog
{
public:
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_bed;
    QGridLayout *gridLayout;
    QTableView *tableView_bed;
    QWidget *tab_nurse;
    QGridLayout *gridLayout_2;
    QTableView *tableView_nurse;
    QWidget *tab_special;
    QGridLayout *gridLayout_3;
    QTableView *tableView_special;
    QWidget *tab_stage;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_stage;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox;
    QLineEdit *lineEdit_bedCost;
    QLineEdit *lineEdit_nurseCost;
    QLineEdit *lineEdit_SpecialCost;
    QLineEdit *lineEdit_stageCost;
    QLineEdit *lineEdit_totalCost;
    QLineEdit *lineEdit_account;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_settle;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *MonthlySettleDialog)
    {
        if (MonthlySettleDialog->objectName().isEmpty())
            MonthlySettleDialog->setObjectName(QString::fromUtf8("MonthlySettleDialog"));
        MonthlySettleDialog->resize(610, 276);
        gridLayout_4 = new QGridLayout(MonthlySettleDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tabWidget = new QTabWidget(MonthlySettleDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_bed = new QWidget();
        tab_bed->setObjectName(QString::fromUtf8("tab_bed"));
        gridLayout = new QGridLayout(tab_bed);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView_bed = new QTableView(tab_bed);
        tableView_bed->setObjectName(QString::fromUtf8("tableView_bed"));

        gridLayout->addWidget(tableView_bed, 0, 0, 1, 1);

        tabWidget->addTab(tab_bed, QString());
        tab_nurse = new QWidget();
        tab_nurse->setObjectName(QString::fromUtf8("tab_nurse"));
        gridLayout_2 = new QGridLayout(tab_nurse);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView_nurse = new QTableView(tab_nurse);
        tableView_nurse->setObjectName(QString::fromUtf8("tableView_nurse"));

        gridLayout_2->addWidget(tableView_nurse, 0, 0, 1, 1);

        tabWidget->addTab(tab_nurse, QString());
        tab_special = new QWidget();
        tab_special->setObjectName(QString::fromUtf8("tab_special"));
        gridLayout_3 = new QGridLayout(tab_special);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableView_special = new QTableView(tab_special);
        tableView_special->setObjectName(QString::fromUtf8("tableView_special"));

        gridLayout_3->addWidget(tableView_special, 0, 0, 1, 1);

        tabWidget->addTab(tab_special, QString());
        tab_stage = new QWidget();
        tab_stage->setObjectName(QString::fromUtf8("tab_stage"));
        verticalLayout_3 = new QVBoxLayout(tab_stage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableView_stage = new QTableView(tab_stage);
        tableView_stage->setObjectName(QString::fromUtf8("tableView_stage"));

        verticalLayout_3->addWidget(tableView_stage);

        tabWidget->addTab(tab_stage, QString());

        horizontalLayout_3->addWidget(tabWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(MonthlySettleDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_7 = new QLabel(MonthlySettleDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_2 = new QLabel(MonthlySettleDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(MonthlySettleDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(MonthlySettleDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(MonthlySettleDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(MonthlySettleDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(MonthlySettleDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_name = new QLineEdit(MonthlySettleDialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_name);

        comboBox = new QComboBox(MonthlySettleDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        lineEdit_bedCost = new QLineEdit(MonthlySettleDialog);
        lineEdit_bedCost->setObjectName(QString::fromUtf8("lineEdit_bedCost"));
        lineEdit_bedCost->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_bedCost->sizePolicy().hasHeightForWidth());
        lineEdit_bedCost->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_bedCost);

        lineEdit_nurseCost = new QLineEdit(MonthlySettleDialog);
        lineEdit_nurseCost->setObjectName(QString::fromUtf8("lineEdit_nurseCost"));
        lineEdit_nurseCost->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_nurseCost->sizePolicy().hasHeightForWidth());
        lineEdit_nurseCost->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_nurseCost);

        lineEdit_SpecialCost = new QLineEdit(MonthlySettleDialog);
        lineEdit_SpecialCost->setObjectName(QString::fromUtf8("lineEdit_SpecialCost"));
        lineEdit_SpecialCost->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_SpecialCost->sizePolicy().hasHeightForWidth());
        lineEdit_SpecialCost->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_SpecialCost);

        lineEdit_stageCost = new QLineEdit(MonthlySettleDialog);
        lineEdit_stageCost->setObjectName(QString::fromUtf8("lineEdit_stageCost"));
        lineEdit_stageCost->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_stageCost->sizePolicy().hasHeightForWidth());
        lineEdit_stageCost->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_stageCost);

        lineEdit_totalCost = new QLineEdit(MonthlySettleDialog);
        lineEdit_totalCost->setObjectName(QString::fromUtf8("lineEdit_totalCost"));
        lineEdit_totalCost->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_totalCost->sizePolicy().hasHeightForWidth());
        lineEdit_totalCost->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_totalCost);

        lineEdit_account = new QLineEdit(MonthlySettleDialog);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_account->sizePolicy().hasHeightForWidth());
        lineEdit_account->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_account);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_settle = new QPushButton(MonthlySettleDialog);
        btn_settle->setObjectName(QString::fromUtf8("btn_settle"));

        horizontalLayout_2->addWidget(btn_settle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(MonthlySettleDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MonthlySettleDialog);
    } // setupUi

    void retranslateUi(QDialog *MonthlySettleDialog)
    {
        MonthlySettleDialog->setWindowTitle(QApplication::translate("MonthlySettleDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_bed), QApplication::translate("MonthlySettleDialog", "\345\272\212\344\275\215\350\264\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_nurse), QApplication::translate("MonthlySettleDialog", "\346\212\244\347\220\206\350\264\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_special), QApplication::translate("MonthlySettleDialog", "\347\211\271\346\256\212\346\234\215\345\212\241\350\264\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_stage), QApplication::translate("MonthlySettleDialog", "\351\230\266\346\256\265\346\200\247\350\264\271\347\224\250", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MonthlySettleDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MonthlySettleDialog", "\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MonthlySettleDialog", "\345\272\212\344\275\215\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MonthlySettleDialog", "\346\212\244\347\220\206\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MonthlySettleDialog", "\347\211\271\346\256\212\346\234\215\345\212\241\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MonthlySettleDialog", "\351\230\266\346\256\265\346\200\247\350\264\271\347\224\250:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MonthlySettleDialog", "\346\234\210\346\200\273\350\264\271\347\224\250:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MonthlySettleDialog", "\345\244\207\347\224\250\351\207\221\344\275\231\351\242\235:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MonthlySettleDialog", "\345\267\262\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonthlySettleDialog", "\346\234\252\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
        );
        btn_settle->setText(QApplication::translate("MonthlySettleDialog", "\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MonthlySettleDialog: public Ui_MonthlySettleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHLYSETTLEDIALOG_H
