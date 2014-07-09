/********************************************************************************
** Form generated from reading UI file 'elderbaseinfodialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELDERBASEINFODIALOG_H
#define UI_ELDERBASEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElderBaseInfoDialog
{
public:
    QLabel *label_12;
    QTextEdit *textEdit_remark;
    QLabel *label_image;
    QPushButton *btn_open;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QLineEdit *lineEdit_operator;
    QLabel *label_14;
    QDateTimeEdit *dateTimeEdit_operation;
    QLabel *label_11;
    QLineEdit *lineEdit_hobby;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_nation;
    QComboBox *comboBox_cardType;
    QDateEdit *dateEdit_birthday;
    QLineEdit *lineEdit_residence;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox_gender;
    QComboBox *comboBox_belief;
    QLineEdit *lineEdit_cardNo;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit_lunarBirthday;
    QCheckBox *checkBox_isLunar;
    QComboBox *comboBox_education;

    void setupUi(QDialog *ElderBaseInfoDialog)
    {
        if (ElderBaseInfoDialog->objectName().isEmpty())
            ElderBaseInfoDialog->setObjectName(QString::fromUtf8("ElderBaseInfoDialog"));
        ElderBaseInfoDialog->resize(610, 455);
        label_12 = new QLabel(ElderBaseInfoDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(17, 193, 36, 16));
        textEdit_remark = new QTextEdit(ElderBaseInfoDialog);
        textEdit_remark->setObjectName(QString::fromUtf8("textEdit_remark"));
        textEdit_remark->setGeometry(QRect(80, 190, 311, 100));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_remark->sizePolicy().hasHeightForWidth());
        textEdit_remark->setSizePolicy(sizePolicy);
        textEdit_remark->setMaximumSize(QSize(16777215, 100));
        label_image = new QLabel(ElderBaseInfoDialog);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(460, 40, 121, 151));
        btn_open = new QPushButton(ElderBaseInfoDialog);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));
        btn_open->setGeometry(QRect(470, 210, 75, 23));
        layoutWidget2 = new QWidget(ElderBaseInfoDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(170, 360, 158, 25));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget2);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_13->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget2);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_13->addWidget(btn_cancel);

        layoutWidget3 = new QWidget(ElderBaseInfoDialog);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 310, 374, 22));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_14->addWidget(label_13);

        lineEdit_operator = new QLineEdit(layoutWidget3);
        lineEdit_operator->setObjectName(QString::fromUtf8("lineEdit_operator"));
        lineEdit_operator->setEnabled(false);

        horizontalLayout_14->addWidget(lineEdit_operator);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_14->addWidget(label_14);

        dateTimeEdit_operation = new QDateTimeEdit(layoutWidget3);
        dateTimeEdit_operation->setObjectName(QString::fromUtf8("dateTimeEdit_operation"));
        dateTimeEdit_operation->setEnabled(false);
        dateTimeEdit_operation->setCalendarPopup(true);

        horizontalLayout_14->addWidget(dateTimeEdit_operation);

        label_11 = new QLabel(ElderBaseInfoDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(17, 165, 36, 16));
        lineEdit_hobby = new QLineEdit(ElderBaseInfoDialog);
        lineEdit_hobby->setObjectName(QString::fromUtf8("lineEdit_hobby"));
        lineEdit_hobby->setGeometry(QRect(80, 160, 311, 20));
        widget = new QWidget(ElderBaseInfoDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(2, 2, 380, 130));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout_2->addWidget(lineEdit_name);

        comboBox_nation = new QComboBox(widget);
        comboBox_nation->setObjectName(QString::fromUtf8("comboBox_nation"));

        verticalLayout_2->addWidget(comboBox_nation);

        comboBox_cardType = new QComboBox(widget);
        comboBox_cardType->setObjectName(QString::fromUtf8("comboBox_cardType"));

        verticalLayout_2->addWidget(comboBox_cardType);

        dateEdit_birthday = new QDateEdit(widget);
        dateEdit_birthday->setObjectName(QString::fromUtf8("dateEdit_birthday"));
        dateEdit_birthday->setEnabled(true);
        dateEdit_birthday->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_birthday->setMinimumDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));
        dateEdit_birthday->setCalendarPopup(true);

        verticalLayout_2->addWidget(dateEdit_birthday);

        lineEdit_residence = new QLineEdit(widget);
        lineEdit_residence->setObjectName(QString::fromUtf8("lineEdit_residence"));

        verticalLayout_2->addWidget(lineEdit_residence);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        comboBox_gender = new QComboBox(widget);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        verticalLayout_4->addWidget(comboBox_gender);

        comboBox_belief = new QComboBox(widget);
        comboBox_belief->setObjectName(QString::fromUtf8("comboBox_belief"));

        verticalLayout_4->addWidget(comboBox_belief);

        lineEdit_cardNo = new QLineEdit(widget);
        lineEdit_cardNo->setObjectName(QString::fromUtf8("lineEdit_cardNo"));

        verticalLayout_4->addWidget(lineEdit_cardNo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dateEdit_lunarBirthday = new QDateEdit(widget);
        dateEdit_lunarBirthday->setObjectName(QString::fromUtf8("dateEdit_lunarBirthday"));
        dateEdit_lunarBirthday->setEnabled(true);
        dateEdit_lunarBirthday->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_lunarBirthday);

        checkBox_isLunar = new QCheckBox(widget);
        checkBox_isLunar->setObjectName(QString::fromUtf8("checkBox_isLunar"));

        horizontalLayout->addWidget(checkBox_isLunar);


        verticalLayout_4->addLayout(horizontalLayout);

        comboBox_education = new QComboBox(widget);
        comboBox_education->setObjectName(QString::fromUtf8("comboBox_education"));

        verticalLayout_4->addWidget(comboBox_education);


        horizontalLayout_2->addLayout(verticalLayout_4);


        retranslateUi(ElderBaseInfoDialog);

        QMetaObject::connectSlotsByName(ElderBaseInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *ElderBaseInfoDialog)
    {
        ElderBaseInfoDialog->setWindowTitle(QApplication::translate("ElderBaseInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ElderBaseInfoDialog", "\345\244\207\346\263\250\357\274\232", 0, QApplication::UnicodeUTF8));
        label_image->setText(QString());
        btn_open->setText(QApplication::translate("ElderBaseInfoDialog", "\344\270\212\344\274\240\347\205\247\347\211\207", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("ElderBaseInfoDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("ElderBaseInfoDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ElderBaseInfoDialog", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ElderBaseInfoDialog", "\346\223\215\344\275\234\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_operation->setDisplayFormat(QApplication::translate("ElderBaseInfoDialog", "yyyy-MM-dd H:mm:ss", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ElderBaseInfoDialog", "\347\210\261\345\245\275\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ElderBaseInfoDialog", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ElderBaseInfoDialog", "\346\260\221\346\227\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ElderBaseInfoDialog", "\350\257\201\344\273\266\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ElderBaseInfoDialog", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ElderBaseInfoDialog", "\346\210\267\347\261\215\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_nation->clear();
        comboBox_nation->insertItems(0, QStringList()
         << QString()
        );
        comboBox_cardType->clear();
        comboBox_cardType->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("ElderBaseInfoDialog", "\350\272\253\344\273\275\350\257\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoDialog", "\345\206\233\345\256\230\350\257\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoDialog", "\346\212\244\347\205\247", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoDialog", "\351\251\276\351\251\266\350\257\201", 0, QApplication::UnicodeUTF8)
        );
        dateEdit_birthday->setDisplayFormat(QApplication::translate("ElderBaseInfoDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ElderBaseInfoDialog", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ElderBaseInfoDialog", "\345\256\227\346\225\231\344\277\241\344\273\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ElderBaseInfoDialog", "\350\257\201\344\273\266\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ElderBaseInfoDialog", "\347\224\237\346\227\245\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ElderBaseInfoDialog", "\346\226\207\345\214\226\347\250\213\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("ElderBaseInfoDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ElderBaseInfoDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        comboBox_belief->clear();
        comboBox_belief->insertItems(0, QStringList()
         << QString()
        );
        dateEdit_lunarBirthday->setDisplayFormat(QApplication::translate("ElderBaseInfoDialog", "MM-dd", 0, QApplication::UnicodeUTF8));
        checkBox_isLunar->setText(QApplication::translate("ElderBaseInfoDialog", "\351\230\264\345\216\206", 0, QApplication::UnicodeUTF8));
        comboBox_education->clear();
        comboBox_education->insertItems(0, QStringList()
         << QString()
        );
    } // retranslateUi

};

namespace Ui {
    class ElderBaseInfoDialog: public Ui_ElderBaseInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELDERBASEINFODIALOG_H
