/********************************************************************************
** Form generated from reading UI file 'visitrecorddialog.ui'
**
** Created: Tue Jun 24 16:25:07 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITRECORDDIALOG_H
#define UI_VISITRECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
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

class Ui_VisitRecordDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_13;
    QVBoxLayout *verticalLayout;
    QLineEdit *line_visitor_name;
    QComboBox *combox_card_type;
    QLineEdit *line_telephone;
    QComboBox *combox_purpose;
    QHBoxLayout *horizontalLayout;
    QLineEdit *line_elder_name;
    QToolButton *toolButton;
    QLineEdit *line_building_name;
    QLineEdit *line_room_no;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_18;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QComboBox *combox_gender;
    QLineEdit *line_card_no;
    QDateEdit *dateEdit_visit_date;
    QComboBox *combox_mode;
    QLineEdit *line_relationship;
    QLineEdit *line_region_no;
    QLineEdit *line_bed_no;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QDateEdit *date_reside;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *line_operator;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_17;
    QDateTimeEdit *dateTime_operation;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *VisitRecordDialog)
    {
        if (VisitRecordDialog->objectName().isEmpty())
            VisitRecordDialog->setObjectName(QString::fromUtf8("VisitRecordDialog"));
        VisitRecordDialog->resize(460, 386);
        layoutWidget = new QWidget(VisitRecordDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(26, 25, 413, 325));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_2->addWidget(label_13);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line_visitor_name = new QLineEdit(layoutWidget);
        line_visitor_name->setObjectName(QString::fromUtf8("line_visitor_name"));

        verticalLayout->addWidget(line_visitor_name);

        combox_card_type = new QComboBox(layoutWidget);
        combox_card_type->setObjectName(QString::fromUtf8("combox_card_type"));

        verticalLayout->addWidget(combox_card_type);

        line_telephone = new QLineEdit(layoutWidget);
        line_telephone->setObjectName(QString::fromUtf8("line_telephone"));

        verticalLayout->addWidget(line_telephone);

        combox_purpose = new QComboBox(layoutWidget);
        combox_purpose->setObjectName(QString::fromUtf8("combox_purpose"));

        verticalLayout->addWidget(combox_purpose);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        line_elder_name = new QLineEdit(layoutWidget);
        line_elder_name->setObjectName(QString::fromUtf8("line_elder_name"));
        line_elder_name->setEnabled(false);

        horizontalLayout->addWidget(line_elder_name);

        toolButton = new QToolButton(layoutWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setEnabled(false);

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        line_building_name = new QLineEdit(layoutWidget);
        line_building_name->setObjectName(QString::fromUtf8("line_building_name"));
        line_building_name->setEnabled(false);

        verticalLayout->addWidget(line_building_name);

        line_room_no = new QLineEdit(layoutWidget);
        line_room_no->setObjectName(QString::fromUtf8("line_room_no"));
        line_room_no->setEnabled(false);

        verticalLayout->addWidget(line_room_no);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_3->addWidget(label_18);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_3->addWidget(label_14);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        combox_gender = new QComboBox(layoutWidget);
        combox_gender->setObjectName(QString::fromUtf8("combox_gender"));

        verticalLayout_4->addWidget(combox_gender);

        line_card_no = new QLineEdit(layoutWidget);
        line_card_no->setObjectName(QString::fromUtf8("line_card_no"));

        verticalLayout_4->addWidget(line_card_no);

        dateEdit_visit_date = new QDateEdit(layoutWidget);
        dateEdit_visit_date->setObjectName(QString::fromUtf8("dateEdit_visit_date"));
        dateEdit_visit_date->setCalendarPopup(true);

        verticalLayout_4->addWidget(dateEdit_visit_date);

        combox_mode = new QComboBox(layoutWidget);
        combox_mode->setObjectName(QString::fromUtf8("combox_mode"));
        combox_mode->setEnabled(false);

        verticalLayout_4->addWidget(combox_mode);

        line_relationship = new QLineEdit(layoutWidget);
        line_relationship->setObjectName(QString::fromUtf8("line_relationship"));
        line_relationship->setEnabled(false);

        verticalLayout_4->addWidget(line_relationship);

        line_region_no = new QLineEdit(layoutWidget);
        line_region_no->setObjectName(QString::fromUtf8("line_region_no"));
        line_region_no->setEnabled(false);

        verticalLayout_4->addWidget(line_region_no);

        line_bed_no = new QLineEdit(layoutWidget);
        line_bed_no->setObjectName(QString::fromUtf8("line_bed_no"));
        line_bed_no->setEnabled(false);

        verticalLayout_4->addWidget(line_bed_no);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_3->addWidget(label_15);

        date_reside = new QDateEdit(layoutWidget);
        date_reside->setObjectName(QString::fromUtf8("date_reside"));
        date_reside->setEnabled(false);
        date_reside->setCalendarPopup(true);

        horizontalLayout_3->addWidget(date_reside);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_5->addWidget(label_16);

        line_operator = new QLineEdit(layoutWidget);
        line_operator->setObjectName(QString::fromUtf8("line_operator"));
        line_operator->setEnabled(false);

        horizontalLayout_5->addWidget(line_operator);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_4->addWidget(label_17);

        dateTime_operation = new QDateTimeEdit(layoutWidget);
        dateTime_operation->setObjectName(QString::fromUtf8("dateTime_operation"));
        dateTime_operation->setEnabled(false);
        dateTime_operation->setCalendarPopup(true);
        dateTime_operation->setTimeSpec(Qt::LocalTime);

        horizontalLayout_4->addWidget(dateTime_operation);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btn_save = new QPushButton(layoutWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_6->addWidget(btn_save);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout_6->addWidget(btn_cancel);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_7->addLayout(horizontalLayout_7);


        retranslateUi(VisitRecordDialog);

        QMetaObject::connectSlotsByName(VisitRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *VisitRecordDialog)
    {
        VisitRecordDialog->setWindowTitle(QApplication::translate("VisitRecordDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VisitRecordDialog", "\346\235\245\350\256\277\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VisitRecordDialog", "\350\257\201\344\273\266\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("VisitRecordDialog", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("VisitRecordDialog", "\346\235\245\350\256\277\347\233\256\347\232\204\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("VisitRecordDialog", "\350\200\201\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("VisitRecordDialog", "\346\245\274\345\256\207\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("VisitRecordDialog", "\346\210\277\351\227\264\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("VisitRecordDialog", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VisitRecordDialog", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VisitRecordDialog", "\350\257\201\344\273\266\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("VisitRecordDialog", "\346\235\245\350\256\277\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("VisitRecordDialog", "\345\222\250\350\257\242\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("VisitRecordDialog", "\345\205\263\347\263\273\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("VisitRecordDialog", "\345\214\272\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("VisitRecordDialog", "\345\272\212\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("VisitRecordDialog", "\350\256\241\345\210\222\345\205\245\344\275\217\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("VisitRecordDialog", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("VisitRecordDialog", "\346\223\215\344\275\234\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("VisitRecordDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("VisitRecordDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VisitRecordDialog: public Ui_VisitRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITRECORDDIALOG_H
