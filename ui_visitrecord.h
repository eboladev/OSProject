/********************************************************************************
** Form generated from reading UI file 'visitrecord.ui'
**
** Created: Tue Jun 24 16:25:07 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITRECORD_H
#define UI_VISITRECORD_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
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

class Ui_VisitRecord
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_vistor;
    QLineEdit *lineEdit_elder;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QComboBox *combox_purpose;
    QComboBox *combox_mode;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_6;
    QDateEdit *dateEdit_visitStart;
    QDateEdit *dateEdit_resideStart;
    QVBoxLayout *verticalLayout_7;
    QDateEdit *dateEdit_visitEnd;
    QDateEdit *dateEdit_resideEnd;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btn_clear;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_add_record;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_change_record;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_delete_record;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *VisitRecord)
    {
        if (VisitRecord->objectName().isEmpty())
            VisitRecord->setObjectName(QString::fromUtf8("VisitRecord"));
        VisitRecord->resize(833, 442);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VisitRecord->sizePolicy().hasHeightForWidth());
        VisitRecord->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(VisitRecord);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(VisitRecord);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        label_4 = new QLabel(VisitRecord);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_vistor = new QLineEdit(VisitRecord);
        lineEdit_vistor->setObjectName(QString::fromUtf8("lineEdit_vistor"));
        sizePolicy1.setHeightForWidth(lineEdit_vistor->sizePolicy().hasHeightForWidth());
        lineEdit_vistor->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lineEdit_vistor);

        lineEdit_elder = new QLineEdit(VisitRecord);
        lineEdit_elder->setObjectName(QString::fromUtf8("lineEdit_elder"));
        sizePolicy1.setHeightForWidth(lineEdit_elder->sizePolicy().hasHeightForWidth());
        lineEdit_elder->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lineEdit_elder);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(VisitRecord);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label_2);

        label_5 = new QLabel(VisitRecord);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        combox_purpose = new QComboBox(VisitRecord);
        combox_purpose->setObjectName(QString::fromUtf8("combox_purpose"));
        sizePolicy1.setHeightForWidth(combox_purpose->sizePolicy().hasHeightForWidth());
        combox_purpose->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(combox_purpose);

        combox_mode = new QComboBox(VisitRecord);
        combox_mode->setObjectName(QString::fromUtf8("combox_mode"));
        sizePolicy1.setHeightForWidth(combox_mode->sizePolicy().hasHeightForWidth());
        combox_mode->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(combox_mode);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(VisitRecord);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(label_3);

        label_6 = new QLabel(VisitRecord);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        dateEdit_visitStart = new QDateEdit(VisitRecord);
        dateEdit_visitStart->setObjectName(QString::fromUtf8("dateEdit_visitStart"));
        sizePolicy1.setHeightForWidth(dateEdit_visitStart->sizePolicy().hasHeightForWidth());
        dateEdit_visitStart->setSizePolicy(sizePolicy1);
        dateEdit_visitStart->setContextMenuPolicy(Qt::DefaultContextMenu);
        dateEdit_visitStart->setDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_visitStart->setDate(QDate(2014, 3, 1));
        dateEdit_visitStart->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_visitStart->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_visitStart->setCalendarPopup(true);

        verticalLayout_6->addWidget(dateEdit_visitStart);

        dateEdit_resideStart = new QDateEdit(VisitRecord);
        dateEdit_resideStart->setObjectName(QString::fromUtf8("dateEdit_resideStart"));
        sizePolicy1.setHeightForWidth(dateEdit_resideStart->sizePolicy().hasHeightForWidth());
        dateEdit_resideStart->setSizePolicy(sizePolicy1);
        dateEdit_resideStart->setDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_resideStart->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_resideStart->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_resideStart->setCalendarPopup(true);

        verticalLayout_6->addWidget(dateEdit_resideStart);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        dateEdit_visitEnd = new QDateEdit(VisitRecord);
        dateEdit_visitEnd->setObjectName(QString::fromUtf8("dateEdit_visitEnd"));
        sizePolicy1.setHeightForWidth(dateEdit_visitEnd->sizePolicy().hasHeightForWidth());
        dateEdit_visitEnd->setSizePolicy(sizePolicy1);
        dateEdit_visitEnd->setDateTime(QDateTime(QDate(2050, 12, 31), QTime(0, 0, 0)));
        dateEdit_visitEnd->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_visitEnd->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_visitEnd->setCalendarPopup(true);

        verticalLayout_7->addWidget(dateEdit_visitEnd);

        dateEdit_resideEnd = new QDateEdit(VisitRecord);
        dateEdit_resideEnd->setObjectName(QString::fromUtf8("dateEdit_resideEnd"));
        sizePolicy1.setHeightForWidth(dateEdit_resideEnd->sizePolicy().hasHeightForWidth());
        dateEdit_resideEnd->setSizePolicy(sizePolicy1);
        dateEdit_resideEnd->setDateTime(QDateTime(QDate(2050, 12, 31), QTime(0, 0, 0)));
        dateEdit_resideEnd->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateEdit_resideEnd->setMinimumDateTime(QDateTime(QDate(2014, 3, 1), QTime(0, 0, 0)));
        dateEdit_resideEnd->setCalendarPopup(true);

        verticalLayout_7->addWidget(dateEdit_resideEnd);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        btn_clear = new QPushButton(VisitRecord);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        sizePolicy1.setHeightForWidth(btn_clear->sizePolicy().hasHeightForWidth());
        btn_clear->setSizePolicy(sizePolicy1);

        verticalLayout_8->addWidget(btn_clear);

        btn_search = new QPushButton(VisitRecord);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        sizePolicy1.setHeightForWidth(btn_search->sizePolicy().hasHeightForWidth());
        btn_search->setSizePolicy(sizePolicy1);

        verticalLayout_8->addWidget(btn_search);


        horizontalLayout->addLayout(verticalLayout_8);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tableView = new QTableView(VisitRecord);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->horizontalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btn_add_record = new QPushButton(VisitRecord);
        btn_add_record->setObjectName(QString::fromUtf8("btn_add_record"));
        sizePolicy1.setHeightForWidth(btn_add_record->sizePolicy().hasHeightForWidth());
        btn_add_record->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(btn_add_record);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btn_change_record = new QPushButton(VisitRecord);
        btn_change_record->setObjectName(QString::fromUtf8("btn_change_record"));
        sizePolicy1.setHeightForWidth(btn_change_record->sizePolicy().hasHeightForWidth());
        btn_change_record->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(btn_change_record);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btn_delete_record = new QPushButton(VisitRecord);
        btn_delete_record->setObjectName(QString::fromUtf8("btn_delete_record"));
        sizePolicy1.setHeightForWidth(btn_delete_record->sizePolicy().hasHeightForWidth());
        btn_delete_record->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(btn_delete_record);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btn_close = new QPushButton(VisitRecord);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        sizePolicy1.setHeightForWidth(btn_close->sizePolicy().hasHeightForWidth());
        btn_close->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(btn_close);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        retranslateUi(VisitRecord);

        QMetaObject::connectSlotsByName(VisitRecord);
    } // setupUi

    void retranslateUi(QWidget *VisitRecord)
    {
        VisitRecord->setWindowTitle(QApplication::translate("VisitRecord", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VisitRecord", "\346\235\245\350\256\277\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VisitRecord", "\350\200\201\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VisitRecord", "\346\235\245\350\256\277\347\233\256\347\232\204\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("VisitRecord", "\345\222\250\350\257\242\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VisitRecord", "\346\235\245\350\256\277\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("VisitRecord", "\350\256\241\345\210\222\345\205\245\344\275\217\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        dateEdit_visitStart->setDisplayFormat(QApplication::translate("VisitRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_resideStart->setDisplayFormat(QApplication::translate("VisitRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_visitEnd->setDisplayFormat(QApplication::translate("VisitRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        dateEdit_resideEnd->setDisplayFormat(QApplication::translate("VisitRecord", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("VisitRecord", "\346\270\205\347\255\233\351\200\211\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_search->setText(QApplication::translate("VisitRecord", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_add_record->setText(QApplication::translate("VisitRecord", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btn_change_record->setText(QApplication::translate("VisitRecord", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btn_delete_record->setText(QApplication::translate("VisitRecord", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("VisitRecord", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VisitRecord: public Ui_VisitRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITRECORD_H
