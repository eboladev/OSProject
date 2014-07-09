/********************************************************************************
** Form generated from reading UI file 'recedesettledialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEDESETTLEDIALOG_H
#define UI_RECEDESETTLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecedeSettleDialog
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QTabWidget *tabWidget;
    QWidget *tab_bed;
    QGridLayout *gridLayout_4;
    QTableView *tableView_bed;
    QWidget *tab_nurse;
    QHBoxLayout *horizontalLayout_4;
    QTableView *tableView_nurse;
    QWidget *tab_special;
    QGridLayout *gridLayout_6;
    QTableView *tableView_special;
    QWidget *tab_stage;
    QGridLayout *gridLayout_7;
    QTableView *tableView_stage;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_name;
    QDateEdit *dateEdit;
    QComboBox *comboBox;
    QLineEdit *lineEdit_bed;
    QLineEdit *lineEdit_nurse;
    QLineEdit *lineEdit_special;
    QLineEdit *lineEdit_stage;
    QLineEdit *lineEdit_total;
    QLineEdit *lineEdit_account;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_pay;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *radioButton_cash;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_card;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton_bank;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radioButton_check;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_pay;
    QLabel *label_bank;
    QLineEdit *lineEdit_bank;
    QLabel *label_check;
    QLineEdit *lineEdit_check;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_back;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_back;
    QLineEdit *lineEdit_back;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_6;
    QLineEdit *lineEdit_operator;
    QLabel *label_7;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_11;

    void setupUi(QDialog *RecedeSettleDialog)
    {
        if (RecedeSettleDialog->objectName().isEmpty())
            RecedeSettleDialog->setObjectName(QString::fromUtf8("RecedeSettleDialog"));
        RecedeSettleDialog->resize(599, 484);
        gridLayout_5 = new QGridLayout(RecedeSettleDialog);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        tabWidget = new QTabWidget(RecedeSettleDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_bed = new QWidget();
        tab_bed->setObjectName(QString::fromUtf8("tab_bed"));
        gridLayout_4 = new QGridLayout(tab_bed);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableView_bed = new QTableView(tab_bed);
        tableView_bed->setObjectName(QString::fromUtf8("tableView_bed"));

        gridLayout_4->addWidget(tableView_bed, 0, 0, 1, 1);

        tabWidget->addTab(tab_bed, QString());
        tab_nurse = new QWidget();
        tab_nurse->setObjectName(QString::fromUtf8("tab_nurse"));
        horizontalLayout_4 = new QHBoxLayout(tab_nurse);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tableView_nurse = new QTableView(tab_nurse);
        tableView_nurse->setObjectName(QString::fromUtf8("tableView_nurse"));

        horizontalLayout_4->addWidget(tableView_nurse);

        tabWidget->addTab(tab_nurse, QString());
        tab_special = new QWidget();
        tab_special->setObjectName(QString::fromUtf8("tab_special"));
        gridLayout_6 = new QGridLayout(tab_special);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableView_special = new QTableView(tab_special);
        tableView_special->setObjectName(QString::fromUtf8("tableView_special"));

        gridLayout_6->addWidget(tableView_special, 0, 0, 1, 1);

        tabWidget->addTab(tab_special, QString());
        tab_stage = new QWidget();
        tab_stage->setObjectName(QString::fromUtf8("tab_stage"));
        gridLayout_7 = new QGridLayout(tab_stage);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tableView_stage = new QTableView(tab_stage);
        tableView_stage->setObjectName(QString::fromUtf8("tableView_stage"));

        gridLayout_7->addWidget(tableView_stage, 0, 0, 1, 1);

        tabWidget->addTab(tab_stage, QString());

        horizontalLayout_8->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(RecedeSettleDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(RecedeSettleDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_12 = new QLabel(RecedeSettleDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_4 = new QLabel(RecedeSettleDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(RecedeSettleDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_10 = new QLabel(RecedeSettleDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(RecedeSettleDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_9 = new QLabel(RecedeSettleDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_8 = new QLabel(RecedeSettleDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_name = new QLineEdit(RecedeSettleDialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_name);

        dateEdit = new QDateEdit(RecedeSettleDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setEnabled(false);
        dateEdit->setCalendarPopup(true);

        verticalLayout_2->addWidget(dateEdit);

        comboBox = new QComboBox(RecedeSettleDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);

        verticalLayout_2->addWidget(comboBox);

        lineEdit_bed = new QLineEdit(RecedeSettleDialog);
        lineEdit_bed->setObjectName(QString::fromUtf8("lineEdit_bed"));
        lineEdit_bed->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_bed->sizePolicy().hasHeightForWidth());
        lineEdit_bed->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_bed);

        lineEdit_nurse = new QLineEdit(RecedeSettleDialog);
        lineEdit_nurse->setObjectName(QString::fromUtf8("lineEdit_nurse"));
        lineEdit_nurse->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_nurse->sizePolicy().hasHeightForWidth());
        lineEdit_nurse->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_nurse);

        lineEdit_special = new QLineEdit(RecedeSettleDialog);
        lineEdit_special->setObjectName(QString::fromUtf8("lineEdit_special"));
        lineEdit_special->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_special->sizePolicy().hasHeightForWidth());
        lineEdit_special->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_special);

        lineEdit_stage = new QLineEdit(RecedeSettleDialog);
        lineEdit_stage->setObjectName(QString::fromUtf8("lineEdit_stage"));
        lineEdit_stage->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_stage->sizePolicy().hasHeightForWidth());
        lineEdit_stage->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_stage);

        lineEdit_total = new QLineEdit(RecedeSettleDialog);
        lineEdit_total->setObjectName(QString::fromUtf8("lineEdit_total"));
        lineEdit_total->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_total->sizePolicy().hasHeightForWidth());
        lineEdit_total->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_total);

        lineEdit_account = new QLineEdit(RecedeSettleDialog);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_account->sizePolicy().hasHeightForWidth());
        lineEdit_account->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit_account);


        horizontalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_8->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox_pay = new QGroupBox(RecedeSettleDialog);
        groupBox_pay->setObjectName(QString::fromUtf8("groupBox_pay"));
        gridLayout_2 = new QGridLayout(groupBox_pay);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        radioButton_cash = new QRadioButton(groupBox_pay);
        radioButton_cash->setObjectName(QString::fromUtf8("radioButton_cash"));

        horizontalLayout_5->addWidget(radioButton_cash);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        radioButton_card = new QRadioButton(groupBox_pay);
        radioButton_card->setObjectName(QString::fromUtf8("radioButton_card"));

        horizontalLayout_5->addWidget(radioButton_card);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        radioButton_bank = new QRadioButton(groupBox_pay);
        radioButton_bank->setObjectName(QString::fromUtf8("radioButton_bank"));

        horizontalLayout_5->addWidget(radioButton_bank);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        radioButton_check = new QRadioButton(groupBox_pay);
        radioButton_check->setObjectName(QString::fromUtf8("radioButton_check"));

        horizontalLayout_5->addWidget(radioButton_check);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_pay);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_pay = new QLineEdit(groupBox_pay);
        lineEdit_pay->setObjectName(QString::fromUtf8("lineEdit_pay"));
        lineEdit_pay->setEnabled(false);

        horizontalLayout->addWidget(lineEdit_pay);

        label_bank = new QLabel(groupBox_pay);
        label_bank->setObjectName(QString::fromUtf8("label_bank"));

        horizontalLayout->addWidget(label_bank);

        lineEdit_bank = new QLineEdit(groupBox_pay);
        lineEdit_bank->setObjectName(QString::fromUtf8("lineEdit_bank"));

        horizontalLayout->addWidget(lineEdit_bank);

        label_check = new QLabel(groupBox_pay);
        label_check->setObjectName(QString::fromUtf8("label_check"));

        horizontalLayout->addWidget(label_check);

        lineEdit_check = new QLineEdit(groupBox_pay);
        lineEdit_check->setObjectName(QString::fromUtf8("lineEdit_check"));

        horizontalLayout->addWidget(lineEdit_check);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_8->addWidget(groupBox_pay);

        groupBox_back = new QGroupBox(RecedeSettleDialog);
        groupBox_back->setObjectName(QString::fromUtf8("groupBox_back"));
        gridLayout = new QGridLayout(groupBox_back);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_back = new QLabel(groupBox_back);
        label_back->setObjectName(QString::fromUtf8("label_back"));

        horizontalLayout_2->addWidget(label_back);

        lineEdit_back = new QLineEdit(groupBox_back);
        lineEdit_back->setObjectName(QString::fromUtf8("lineEdit_back"));
        lineEdit_back->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_back->sizePolicy().hasHeightForWidth());
        lineEdit_back->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_back);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_8->addWidget(groupBox_back);


        gridLayout_3->addLayout(verticalLayout_8, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        label_6 = new QLabel(RecedeSettleDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_operator = new QLineEdit(RecedeSettleDialog);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_6->addWidget(lineEdit_operator);

        label_7 = new QLabel(RecedeSettleDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        dateTimeEdit = new QDateTimeEdit(RecedeSettleDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_6->addWidget(dateTimeEdit);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        gridLayout_3->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        btn_save = new QPushButton(RecedeSettleDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_7->addWidget(btn_save);

        btn_cancel = new QPushButton(RecedeSettleDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_7->addWidget(btn_cancel);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        gridLayout_3->addLayout(horizontalLayout_7, 3, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(RecedeSettleDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RecedeSettleDialog);
    } // setupUi

    void retranslateUi(QDialog *RecedeSettleDialog)
    {
        RecedeSettleDialog->setWindowTitle(QApplication::translate("RecedeSettleDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_bed), QApplication::translate("RecedeSettleDialog", "\345\272\212\344\275\215\350\264\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_nurse), QApplication::translate("RecedeSettleDialog", "\346\212\244\347\220\206\350\264\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_special), QApplication::translate("RecedeSettleDialog", "\347\211\271\346\256\212\346\234\215\345\212\241\350\264\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_stage), QApplication::translate("RecedeSettleDialog", "\351\230\266\346\256\265\346\200\247\350\264\271\347\224\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RecedeSettleDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RecedeSettleDialog", "\351\200\200\344\275\217\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("RecedeSettleDialog", "\347\273\223\347\256\227\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RecedeSettleDialog", "\345\272\212\344\275\215\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RecedeSettleDialog", "\346\212\244\347\220\206\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("RecedeSettleDialog", "\347\211\271\346\256\212\346\234\215\345\212\241\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("RecedeSettleDialog", "\351\230\266\346\256\265\346\200\247\350\264\271\347\224\250:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("RecedeSettleDialog", "\346\200\273\350\264\271\347\224\250:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("RecedeSettleDialog", "\350\264\246\346\210\267\344\275\231\351\242\235:", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("RecedeSettleDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("RecedeSettleDialog", "\345\267\262\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RecedeSettleDialog", "\346\234\252\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8)
        );
        groupBox_pay->setTitle(QApplication::translate("RecedeSettleDialog", "\344\273\230\346\254\276", 0, QApplication::UnicodeUTF8));
        radioButton_cash->setText(QApplication::translate("RecedeSettleDialog", "\347\216\260\351\207\221\344\273\230\346\254\276", 0, QApplication::UnicodeUTF8));
        radioButton_card->setText(QApplication::translate("RecedeSettleDialog", "\345\210\267\345\215\241\344\273\230\346\254\276", 0, QApplication::UnicodeUTF8));
        radioButton_bank->setText(QApplication::translate("RecedeSettleDialog", "\351\223\266\350\241\214\350\275\254\350\264\246", 0, QApplication::UnicodeUTF8));
        radioButton_check->setText(QApplication::translate("RecedeSettleDialog", "\346\224\257\347\245\250\344\273\230\346\254\276", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RecedeSettleDialog", "\344\273\230\346\254\276\351\207\221\351\242\235:", 0, QApplication::UnicodeUTF8));
        label_bank->setText(QApplication::translate("RecedeSettleDialog", "\351\223\266\350\241\214:", 0, QApplication::UnicodeUTF8));
        label_check->setText(QApplication::translate("RecedeSettleDialog", "\346\224\257\347\245\250\345\217\267:", 0, QApplication::UnicodeUTF8));
        groupBox_back->setTitle(QApplication::translate("RecedeSettleDialog", "\351\200\200\346\254\276", 0, QApplication::UnicodeUTF8));
        label_back->setText(QApplication::translate("RecedeSettleDialog", "\351\200\200\346\254\276\351\207\221\351\242\235:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RecedeSettleDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RecedeSettleDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("RecedeSettleDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("RecedeSettleDialog", "\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("RecedeSettleDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecedeSettleDialog: public Ui_RecedeSettleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEDESETTLEDIALOG_H
