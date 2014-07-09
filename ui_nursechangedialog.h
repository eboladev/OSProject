/********************************************************************************
** Form generated from reading UI file 'nursechangedialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NURSECHANGEDIALOG_H
#define UI_NURSECHANGEDIALOG_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NurseChangeDialog
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_17;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_cardNo;
    QToolButton *toolButton_cardNo;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLineEdit *lineEdit_additionalClauseNo;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_formerBuildingName;
    QLineEdit *lineEdit_formerBedNo;
    QComboBox *comboBox_formerNurseLevel;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_23;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_formerRegionNo;
    QComboBox *comboBox_formerBedLevel;
    QLineEdit *lineEdit_formerNurseCost;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEdit_formerRoomNo;
    QLineEdit *lineEdit_formerBedCost;
    QLineEdit *lineEdit_formerNurser;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_13;
    QLabel *label_16;
    QLabel *label_24;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_latterBuildingName;
    QToolButton *toolButton_building;
    QLineEdit *lineEdit_latterBedNo;
    QComboBox *comboBox_latterNurseLevel;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_25;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *lineEdit_latterRegionNo;
    QComboBox *comboBox_latterBedLevel;
    QLineEdit *lineEdit_latterNurseCost;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_15;
    QLineEdit *lineEdit_latterRoomNo;
    QLineEdit *lineEdit_latterBedCost;
    QLineEdit *lineEdit_latterNurser;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_20;
    QLineEdit *lineEdit_operator;
    QLabel *label_21;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *NurseChangeDialog)
    {
        if (NurseChangeDialog->objectName().isEmpty())
            NurseChangeDialog->setObjectName(QString::fromUtf8("NurseChangeDialog"));
        NurseChangeDialog->resize(585, 413);
        gridLayout_4 = new QGridLayout(NurseChangeDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        groupBox_3 = new QGroupBox(NurseChangeDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_cardNo = new QLineEdit(groupBox_3);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));

        horizontalLayout->addWidget(lineEdit_cardNo);

        toolButton_cardNo = new QToolButton(groupBox_3);
        toolButton_cardNo->setObjectName(QString::fromUtf8("toolButton_cardNo"));

        horizontalLayout->addWidget(toolButton_cardNo);


        verticalLayout_2->addLayout(horizontalLayout);

        dateEdit = new QDateEdit(groupBox_3);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        verticalLayout_2->addWidget(dateEdit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_name = new QLineEdit(groupBox_3);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout_2->addWidget(lineEdit_name);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_additionalClauseNo = new QLineEdit(groupBox_3);
        lineEdit_additionalClauseNo->setObjectName(QString::fromUtf8("lineEdit_additionalClauseNo"));

        horizontalLayout_2->addWidget(lineEdit_additionalClauseNo);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout_17->addWidget(groupBox_3);

        groupBox = new QGroupBox(NurseChangeDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_4->addWidget(label_22);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lineEdit_formerBuildingName = new QLineEdit(groupBox);
        lineEdit_formerBuildingName->setObjectName(QString::fromUtf8("lineEdit_formerBuildingName"));

        verticalLayout_5->addWidget(lineEdit_formerBuildingName);

        lineEdit_formerBedNo = new QLineEdit(groupBox);
        lineEdit_formerBedNo->setObjectName(QString::fromUtf8("lineEdit_formerBedNo"));

        verticalLayout_5->addWidget(lineEdit_formerBedNo);

        comboBox_formerNurseLevel = new QComboBox(groupBox);
        comboBox_formerNurseLevel->setObjectName(QString::fromUtf8("comboBox_formerNurseLevel"));

        verticalLayout_5->addWidget(comboBox_formerNurseLevel);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_6->addWidget(label_9);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_6->addWidget(label_23);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lineEdit_formerRegionNo = new QLineEdit(groupBox);
        lineEdit_formerRegionNo->setObjectName(QString::fromUtf8("lineEdit_formerRegionNo"));

        verticalLayout_7->addWidget(lineEdit_formerRegionNo);

        comboBox_formerBedLevel = new QComboBox(groupBox);
        comboBox_formerBedLevel->setObjectName(QString::fromUtf8("comboBox_formerBedLevel"));

        verticalLayout_7->addWidget(comboBox_formerBedLevel);

        lineEdit_formerNurseCost = new QLineEdit(groupBox);
        lineEdit_formerNurseCost->setObjectName(QString::fromUtf8("lineEdit_formerNurseCost"));

        verticalLayout_7->addWidget(lineEdit_formerNurseCost);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_8->addWidget(label_7);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_8->addWidget(label_10);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_8->addWidget(label_11);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lineEdit_formerRoomNo = new QLineEdit(groupBox);
        lineEdit_formerRoomNo->setObjectName(QString::fromUtf8("lineEdit_formerRoomNo"));

        verticalLayout_9->addWidget(lineEdit_formerRoomNo);

        lineEdit_formerBedCost = new QLineEdit(groupBox);
        lineEdit_formerBedCost->setObjectName(QString::fromUtf8("lineEdit_formerBedCost"));

        verticalLayout_9->addWidget(lineEdit_formerBedCost);

        lineEdit_formerNurser = new QLineEdit(groupBox);
        lineEdit_formerNurser->setObjectName(QString::fromUtf8("lineEdit_formerNurser"));

        verticalLayout_9->addWidget(lineEdit_formerNurser);


        horizontalLayout_4->addLayout(verticalLayout_9);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        verticalLayout_17->addWidget(groupBox);

        groupBox_2 = new QGroupBox(NurseChangeDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_10->addWidget(label_13);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_10->addWidget(label_16);

        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_10->addWidget(label_24);


        horizontalLayout_10->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_latterBuildingName = new QLineEdit(groupBox_2);
        lineEdit_latterBuildingName->setObjectName(QString::fromUtf8("lineEdit_latterBuildingName"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_latterBuildingName->sizePolicy().hasHeightForWidth());
        lineEdit_latterBuildingName->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_latterBuildingName);

        toolButton_building = new QToolButton(groupBox_2);
        toolButton_building->setObjectName(QString::fromUtf8("toolButton_building"));

        horizontalLayout_5->addWidget(toolButton_building);


        verticalLayout_11->addLayout(horizontalLayout_5);

        lineEdit_latterBedNo = new QLineEdit(groupBox_2);
        lineEdit_latterBedNo->setObjectName(QString::fromUtf8("lineEdit_latterBedNo"));
        sizePolicy.setHeightForWidth(lineEdit_latterBedNo->sizePolicy().hasHeightForWidth());
        lineEdit_latterBedNo->setSizePolicy(sizePolicy);

        verticalLayout_11->addWidget(lineEdit_latterBedNo);

        comboBox_latterNurseLevel = new QComboBox(groupBox_2);
        comboBox_latterNurseLevel->setObjectName(QString::fromUtf8("comboBox_latterNurseLevel"));

        verticalLayout_11->addWidget(comboBox_latterNurseLevel);


        horizontalLayout_10->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_12->addWidget(label_14);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_12->addWidget(label_17);

        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_12->addWidget(label_25);


        horizontalLayout_10->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        lineEdit_latterRegionNo = new QLineEdit(groupBox_2);
        lineEdit_latterRegionNo->setObjectName(QString::fromUtf8("lineEdit_latterRegionNo"));

        verticalLayout_13->addWidget(lineEdit_latterRegionNo);

        comboBox_latterBedLevel = new QComboBox(groupBox_2);
        comboBox_latterBedLevel->setObjectName(QString::fromUtf8("comboBox_latterBedLevel"));

        verticalLayout_13->addWidget(comboBox_latterBedLevel);

        lineEdit_latterNurseCost = new QLineEdit(groupBox_2);
        lineEdit_latterNurseCost->setObjectName(QString::fromUtf8("lineEdit_latterNurseCost"));

        verticalLayout_13->addWidget(lineEdit_latterNurseCost);


        horizontalLayout_10->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_14->addWidget(label_15);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_14->addWidget(label_18);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_14->addWidget(label_19);


        horizontalLayout_10->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        lineEdit_latterRoomNo = new QLineEdit(groupBox_2);
        lineEdit_latterRoomNo->setObjectName(QString::fromUtf8("lineEdit_latterRoomNo"));

        verticalLayout_15->addWidget(lineEdit_latterRoomNo);

        lineEdit_latterBedCost = new QLineEdit(groupBox_2);
        lineEdit_latterBedCost->setObjectName(QString::fromUtf8("lineEdit_latterBedCost"));

        verticalLayout_15->addWidget(lineEdit_latterBedCost);

        lineEdit_latterNurser = new QLineEdit(groupBox_2);
        lineEdit_latterNurser->setObjectName(QString::fromUtf8("lineEdit_latterNurser"));

        verticalLayout_15->addWidget(lineEdit_latterNurser);


        horizontalLayout_10->addLayout(verticalLayout_15);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 1);


        verticalLayout_17->addWidget(groupBox_2);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_20 = new QLabel(NurseChangeDialog);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_6->addWidget(label_20);

        lineEdit_operator = new QLineEdit(NurseChangeDialog);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_6->addWidget(lineEdit_operator);

        label_21 = new QLabel(NurseChangeDialog);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_6->addWidget(label_21);

        dateTimeEdit = new QDateTimeEdit(NurseChangeDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_6->addWidget(dateTimeEdit);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_16->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        btn_save = new QPushButton(NurseChangeDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_7->addWidget(btn_save);

        btn_cancel = new QPushButton(NurseChangeDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_7->addWidget(btn_cancel);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_16->addLayout(horizontalLayout_9);


        verticalLayout_17->addLayout(verticalLayout_16);


        gridLayout_4->addLayout(verticalLayout_17, 0, 0, 1, 1);


        retranslateUi(NurseChangeDialog);

        QMetaObject::connectSlotsByName(NurseChangeDialog);
    } // setupUi

    void retranslateUi(QDialog *NurseChangeDialog)
    {
        NurseChangeDialog->setWindowTitle(QApplication::translate("NurseChangeDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NurseChangeDialog", "\345\217\230\346\233\264\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NurseChangeDialog", "\345\215\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NurseChangeDialog", "\345\217\230\346\233\264\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        toolButton_cardNo->setText(QApplication::translate("NurseChangeDialog", "...", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("NurseChangeDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NurseChangeDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NurseChangeDialog", "\345\220\210\345\220\214\351\231\204\345\212\240\345\217\267:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NurseChangeDialog", "\345\216\237\346\212\244\347\220\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\346\245\274\345\256\207\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\345\272\212\344\275\215:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\346\212\244\347\220\206\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_formerNurseLevel->clear();
        comboBox_formerNurseLevel->insertItems(0, QStringList()
         << QString()
        );
        label_6->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\345\214\272\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\345\272\212\344\275\215\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\346\212\244\347\220\206\350\264\271:", 0, QApplication::UnicodeUTF8));
        comboBox_formerBedLevel->clear();
        comboBox_formerBedLevel->insertItems(0, QStringList()
         << QString()
        );
        label_7->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\346\210\277\351\227\264\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\345\272\212\344\275\215\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NurseChangeDialog", "\345\216\237\346\212\244\347\220\206\345\221\230:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NurseChangeDialog", "\346\226\260\346\212\244\347\220\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\346\245\274\345\256\207\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\345\272\212\344\275\215:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\346\212\244\347\220\206\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        toolButton_building->setText(QApplication::translate("NurseChangeDialog", "...", 0, QApplication::UnicodeUTF8));
        comboBox_latterNurseLevel->clear();
        comboBox_latterNurseLevel->insertItems(0, QStringList()
         << QString()
        );
        label_14->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\345\214\272\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\345\272\212\344\275\215\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\346\212\244\347\220\206\350\264\271:", 0, QApplication::UnicodeUTF8));
        comboBox_latterBedLevel->clear();
        comboBox_latterBedLevel->insertItems(0, QStringList()
         << QString()
        );
        label_15->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\346\210\277\351\227\264\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\345\272\212\344\275\215\350\264\271:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("NurseChangeDialog", "\346\226\260\346\212\244\347\220\206\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("NurseChangeDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("NurseChangeDialog", "\346\223\215\344\275\234\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("NurseChangeDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("NurseChangeDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("NurseChangeDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NurseChangeDialog: public Ui_NurseChangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NURSECHANGEDIALOG_H
