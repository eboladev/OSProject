/********************************************************************************
** Form generated from reading UI file 'healthassessdialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEALTHASSESSDIALOG_H
#define UI_HEALTHASSESSDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HealthAssessDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btn_save;
    QPushButton *btn_calcel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_26;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_12;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_elderId;
    QToolButton *toolButton;
    QComboBox *comboBox_cardType;
    QLineEdit *lineEdit_weight;
    QLineEdit *lineEdit_bloodPressureLow;
    QLineEdit *lineEdit_leftEyesight;
    QComboBox *comboBox_mind;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_27;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_cardNo;
    QComboBox *comboBox_bloodType;
    QLineEdit *lineEdit_bloodPressureHigh;
    QLineEdit *lineEdit_rightEyesight;
    QComboBox *comboBox_selfNurse;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_25;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox_gender;
    QLineEdit *lineEdit_height;
    QLineEdit *lineEdit_pulse;
    QComboBox *comboBox_hearing;
    QComboBox *comboBox_memory;
    QComboBox *comboBox_excretion;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit_diet;
    QLineEdit *lineEdit_medicine;
    QLineEdit *lineEdit_personalMedical;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *lineEdit_allergy;
    QLineEdit *lineEdit_familyMedical;
    QComboBox *comboBox_nurseSuggestion;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_22;
    QLineEdit *lineEdit_remark;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_23;
    QLineEdit *lineEdit_operator;
    QLabel *label_24;
    QDateTimeEdit *dateTimeEdit_operationTime;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *HealthAssessDialog)
    {
        if (HealthAssessDialog->objectName().isEmpty())
            HealthAssessDialog->setObjectName(QString::fromUtf8("HealthAssessDialog"));
        HealthAssessDialog->resize(589, 422);
        layoutWidget = new QWidget(HealthAssessDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 360, 158, 25));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_8->addWidget(btn_save);

        btn_calcel = new QPushButton(layoutWidget);
        btn_calcel->setObjectName(QString::fromUtf8("btn_calcel"));

        horizontalLayout_8->addWidget(btn_calcel);

        layoutWidget1 = new QWidget(HealthAssessDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 570, 298));
        verticalLayout_11 = new QVBoxLayout(layoutWidget1);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_26 = new QLabel(layoutWidget1);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_2->addWidget(label_26);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_2->addWidget(label_12);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_elderId = new QLineEdit(layoutWidget1);
        lineEdit_elderId->setObjectName(QString::fromUtf8("lineEdit_elderId"));

        horizontalLayout->addWidget(lineEdit_elderId);

        toolButton = new QToolButton(layoutWidget1);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        comboBox_cardType = new QComboBox(layoutWidget1);
        comboBox_cardType->setObjectName(QString::fromUtf8("comboBox_cardType"));

        verticalLayout->addWidget(comboBox_cardType);

        lineEdit_weight = new QLineEdit(layoutWidget1);
        lineEdit_weight->setObjectName(QString::fromUtf8("lineEdit_weight"));

        verticalLayout->addWidget(lineEdit_weight);

        lineEdit_bloodPressureLow = new QLineEdit(layoutWidget1);
        lineEdit_bloodPressureLow->setObjectName(QString::fromUtf8("lineEdit_bloodPressureLow"));

        verticalLayout->addWidget(lineEdit_bloodPressureLow);

        lineEdit_leftEyesight = new QLineEdit(layoutWidget1);
        lineEdit_leftEyesight->setObjectName(QString::fromUtf8("lineEdit_leftEyesight"));

        verticalLayout->addWidget(lineEdit_leftEyesight);

        comboBox_mind = new QComboBox(layoutWidget1);
        comboBox_mind->setObjectName(QString::fromUtf8("comboBox_mind"));

        verticalLayout->addWidget(comboBox_mind);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_27 = new QLabel(layoutWidget1);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_3->addWidget(label_27);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_3->addWidget(label_14);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_name = new QLineEdit(layoutWidget1);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout_4->addWidget(lineEdit_name);

        lineEdit_cardNo = new QLineEdit(layoutWidget1);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));

        verticalLayout_4->addWidget(lineEdit_cardNo);

        comboBox_bloodType = new QComboBox(layoutWidget1);
        comboBox_bloodType->setObjectName(QString::fromUtf8("comboBox_bloodType"));

        verticalLayout_4->addWidget(comboBox_bloodType);

        lineEdit_bloodPressureHigh = new QLineEdit(layoutWidget1);
        lineEdit_bloodPressureHigh->setObjectName(QString::fromUtf8("lineEdit_bloodPressureHigh"));

        verticalLayout_4->addWidget(lineEdit_bloodPressureHigh);

        lineEdit_rightEyesight = new QLineEdit(layoutWidget1);
        lineEdit_rightEyesight->setObjectName(QString::fromUtf8("lineEdit_rightEyesight"));

        verticalLayout_4->addWidget(lineEdit_rightEyesight);

        comboBox_selfNurse = new QComboBox(layoutWidget1);
        comboBox_selfNurse->setObjectName(QString::fromUtf8("comboBox_selfNurse"));

        verticalLayout_4->addWidget(comboBox_selfNurse);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_25 = new QLabel(layoutWidget1);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_5->addWidget(label_25);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_5->addWidget(label_11);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_5->addWidget(label_16);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        comboBox_gender = new QComboBox(layoutWidget1);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        verticalLayout_6->addWidget(comboBox_gender);

        lineEdit_height = new QLineEdit(layoutWidget1);
        lineEdit_height->setObjectName(QString::fromUtf8("lineEdit_height"));

        verticalLayout_6->addWidget(lineEdit_height);

        lineEdit_pulse = new QLineEdit(layoutWidget1);
        lineEdit_pulse->setObjectName(QString::fromUtf8("lineEdit_pulse"));

        verticalLayout_6->addWidget(lineEdit_pulse);

        comboBox_hearing = new QComboBox(layoutWidget1);
        comboBox_hearing->setObjectName(QString::fromUtf8("comboBox_hearing"));

        verticalLayout_6->addWidget(comboBox_hearing);

        comboBox_memory = new QComboBox(layoutWidget1);
        comboBox_memory->setObjectName(QString::fromUtf8("comboBox_memory"));

        verticalLayout_6->addWidget(comboBox_memory);

        comboBox_excretion = new QComboBox(layoutWidget1);
        comboBox_excretion->setObjectName(QString::fromUtf8("comboBox_excretion"));

        verticalLayout_6->addWidget(comboBox_excretion);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout_11->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_7->addWidget(label_15);

        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_7->addWidget(label_18);

        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_7->addWidget(label_20);


        horizontalLayout_5->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lineEdit_diet = new QLineEdit(layoutWidget1);
        lineEdit_diet->setObjectName(QString::fromUtf8("lineEdit_diet"));

        verticalLayout_8->addWidget(lineEdit_diet);

        lineEdit_medicine = new QLineEdit(layoutWidget1);
        lineEdit_medicine->setObjectName(QString::fromUtf8("lineEdit_medicine"));

        verticalLayout_8->addWidget(lineEdit_medicine);

        lineEdit_personalMedical = new QLineEdit(layoutWidget1);
        lineEdit_personalMedical->setObjectName(QString::fromUtf8("lineEdit_personalMedical"));

        verticalLayout_8->addWidget(lineEdit_personalMedical);


        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_9->addWidget(label_17);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_9->addWidget(label_19);

        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_9->addWidget(label_21);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        lineEdit_allergy = new QLineEdit(layoutWidget1);
        lineEdit_allergy->setObjectName(QString::fromUtf8("lineEdit_allergy"));

        verticalLayout_10->addWidget(lineEdit_allergy);

        lineEdit_familyMedical = new QLineEdit(layoutWidget1);
        lineEdit_familyMedical->setObjectName(QString::fromUtf8("lineEdit_familyMedical"));

        verticalLayout_10->addWidget(lineEdit_familyMedical);

        comboBox_nurseSuggestion = new QComboBox(layoutWidget1);
        comboBox_nurseSuggestion->setObjectName(QString::fromUtf8("comboBox_nurseSuggestion"));

        verticalLayout_10->addWidget(comboBox_nurseSuggestion);


        horizontalLayout_5->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_4->addWidget(label_22);

        lineEdit_remark = new QLineEdit(layoutWidget1);
        lineEdit_remark->setObjectName(QString::fromUtf8("lineEdit_remark"));

        horizontalLayout_4->addWidget(lineEdit_remark);


        verticalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_6->addWidget(label_23);

        lineEdit_operator = new QLineEdit(layoutWidget1);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_6->addWidget(lineEdit_operator);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_6->addWidget(label_24);

        dateTimeEdit_operationTime = new QDateTimeEdit(layoutWidget1);
        dateTimeEdit_operationTime->setObjectName(QString::fromUtf8("dateTimeEdit_operationTime"));
        dateTimeEdit_operationTime->setEnabled(false);
        dateTimeEdit_operationTime->setMaximumDate(QDate(2050, 12, 31));
        dateTimeEdit_operationTime->setMinimumDate(QDate(2014, 3, 1));
        dateTimeEdit_operationTime->setCalendarPopup(true);

        horizontalLayout_6->addWidget(dateTimeEdit_operationTime);


        horizontalLayout_2->addLayout(horizontalLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_11->addLayout(horizontalLayout_2);


        retranslateUi(HealthAssessDialog);

        QMetaObject::connectSlotsByName(HealthAssessDialog);
    } // setupUi

    void retranslateUi(QDialog *HealthAssessDialog)
    {
        HealthAssessDialog->setWindowTitle(QApplication::translate("HealthAssessDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("HealthAssessDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_calcel->setText(QApplication::translate("HealthAssessDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HealthAssessDialog", "\350\200\201\344\272\272ID:", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("HealthAssessDialog", "\350\257\201\344\273\266\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HealthAssessDialog", "\344\275\223\351\207\215(kg):", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HealthAssessDialog", "\350\210\222\345\274\240\345\216\213:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("HealthAssessDialog", "\345\267\246\347\234\274\350\247\206\345\212\233:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("HealthAssessDialog", "\347\245\236\346\231\272:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("HealthAssessDialog", "...", 0, QApplication::UnicodeUTF8));
        comboBox_cardType->clear();
        comboBox_cardType->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("HealthAssessDialog", "\350\272\253\344\273\275\350\257\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HealthAssessDialog", "\345\206\233\345\256\230\350\257\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HealthAssessDialog", "\346\212\244\347\205\247", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HealthAssessDialog", "\351\251\276\351\251\266\350\257\201", 0, QApplication::UnicodeUTF8)
        );
        comboBox_mind->clear();
        comboBox_mind->insertItems(0, QStringList()
         << QString()
        );
        label_2->setText(QApplication::translate("HealthAssessDialog", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("HealthAssessDialog", "\350\257\201\344\273\266\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HealthAssessDialog", "\350\241\200\345\236\213:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HealthAssessDialog", "\346\224\266\347\274\251\345\216\213:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("HealthAssessDialog", "\345\217\263\347\234\274\350\247\206\345\212\233:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("HealthAssessDialog", "\350\207\252\347\220\206\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_bloodType->clear();
        comboBox_bloodType->insertItems(0, QStringList()
         << QString()
        );
        comboBox_selfNurse->clear();
        comboBox_selfNurse->insertItems(0, QStringList()
         << QString()
        );
        label_25->setText(QApplication::translate("HealthAssessDialog", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HealthAssessDialog", "\350\272\253\351\253\230(cm):", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HealthAssessDialog", "\350\204\211\346\220\217:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("HealthAssessDialog", "\345\220\254\345\212\233:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HealthAssessDialog", "\350\256\260\345\277\206\345\212\233:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("HealthAssessDialog", "\345\244\247\345\260\217\344\276\277:", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("HealthAssessDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HealthAssessDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        comboBox_hearing->clear();
        comboBox_hearing->insertItems(0, QStringList()
         << QString()
        );
        comboBox_memory->clear();
        comboBox_memory->insertItems(0, QStringList()
         << QString()
        );
        comboBox_excretion->clear();
        comboBox_excretion->insertItems(0, QStringList()
         << QString()
        );
        label_15->setText(QApplication::translate("HealthAssessDialog", "\351\245\256\351\243\237\347\211\271\347\202\271:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("HealthAssessDialog", "\345\270\270\346\234\215\350\215\257\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("HealthAssessDialog", "\344\270\252\344\272\272\347\227\205\345\217\262:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("HealthAssessDialog", "\350\215\257\347\211\251\350\277\207\346\225\217\345\217\262:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("HealthAssessDialog", "\345\256\266\346\227\217\347\227\205\345\217\262:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("HealthAssessDialog", "\345\273\272\350\256\256\346\212\244\347\220\206\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        comboBox_nurseSuggestion->clear();
        comboBox_nurseSuggestion->insertItems(0, QStringList()
         << QString()
        );
        label_22->setText(QApplication::translate("HealthAssessDialog", "\345\205\266\344\273\226\345\201\245\345\272\267\347\212\266\345\206\265:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("HealthAssessDialog", "\346\223\215\344\275\234\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("HealthAssessDialog", "\346\223\215\344\275\234\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_operationTime->setDisplayFormat(QApplication::translate("HealthAssessDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HealthAssessDialog: public Ui_HealthAssessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHASSESSDIALOG_H
