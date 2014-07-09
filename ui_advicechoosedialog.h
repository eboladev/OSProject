/********************************************************************************
** Form generated from reading UI file 'advicechoosedialog.ui'
**
** Created: Sat May 17 16:16:40 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVICECHOOSEDIALOG_H
#define UI_ADVICECHOOSEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
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

class Ui_AdviceChooseDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_elder;
    QLabel *label_2;
    QLineEdit *lineEdit_doctor;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QTableWidget *tableWidget;

    void setupUi(QDialog *AdviceChooseDialog)
    {
        if (AdviceChooseDialog->objectName().isEmpty())
            AdviceChooseDialog->setObjectName(QString::fromUtf8("AdviceChooseDialog"));
        AdviceChooseDialog->resize(511, 363);
        gridLayout = new QGridLayout(AdviceChooseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(AdviceChooseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_elder = new QLineEdit(AdviceChooseDialog);
        lineEdit_elder->setObjectName(QString::fromUtf8("lineEdit_elder"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_elder->sizePolicy().hasHeightForWidth());
        lineEdit_elder->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_elder);

        label_2 = new QLabel(AdviceChooseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_doctor = new QLineEdit(AdviceChooseDialog);
        lineEdit_doctor->setObjectName(QString::fromUtf8("lineEdit_doctor"));
        sizePolicy.setHeightForWidth(lineEdit_doctor->sizePolicy().hasHeightForWidth());
        lineEdit_doctor->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_doctor);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(AdviceChooseDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dateEdit_start = new QDateEdit(AdviceChooseDialog);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start);

        dateEdit_end = new QDateEdit(AdviceChooseDialog);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_end);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_clear = new QPushButton(AdviceChooseDialog);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        verticalLayout_2->addWidget(btn_clear);

        btn_search = new QPushButton(AdviceChooseDialog);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        verticalLayout_2->addWidget(btn_search);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(AdviceChooseDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(AdviceChooseDialog);

        QMetaObject::connectSlotsByName(AdviceChooseDialog);
    } // setupUi

    void retranslateUi(QDialog *AdviceChooseDialog)
    {
        AdviceChooseDialog->setWindowTitle(QApplication::translate("AdviceChooseDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdviceChooseDialog", "\350\200\201\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdviceChooseDialog", "\345\214\273\345\270\210:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AdviceChooseDialog", "\345\214\273\345\230\261\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dateEdit_start->setDisplayFormat(QApplication::translate("AdviceChooseDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_end->setDisplayFormat(QApplication::translate("AdviceChooseDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("AdviceChooseDialog", "\346\270\205\351\231\244\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("AdviceChooseDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdviceChooseDialog: public Ui_AdviceChooseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVICECHOOSEDIALOG_H
