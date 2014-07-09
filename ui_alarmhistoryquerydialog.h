/********************************************************************************
** Form generated from reading UI file 'alarmhistoryquerydialog.ui'
**
** Created: Fri Feb 28 20:02:48 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMHISTORYQUERYDIALOG_H
#define UI_ALARMHISTORYQUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AlarmHistoryQueryDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *building_combobox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *floor_combobox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *room_combobox;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *all_checkBox;
    QCheckBox *smoke_checkbox;
    QCheckBox *mattress_checkbox;
    QCheckBox *pm25_checkbox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QCheckBox *tempratrueup_checkbox;
    QCheckBox *moistrueup_checkbox;
    QCheckBox *O2up_checkbox;
    QCheckBox *CO2up_checkbox;
    QCheckBox *indexsup_checkbox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QCheckBox *tempraturedown_checkbox;
    QCheckBox *moisturedown_checkbox;
    QCheckBox *O2down_checkbox;
    QCheckBox *CO2down_checkbox;
    QCheckBox *indexsdown_checkbox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout;
    QLabel *startandend_label;
    QDateEdit *start_dateedit;
    QTimeEdit *start_timeedit;
    QLabel *label;
    QDateEdit *end_dateedit;
    QTimeEdit *end_timeedit;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *search_pushbutton;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_10;
    QLabel *totalcount_label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lastpage_pushbutton;
    QLineEdit *pagenum_lineedit;
    QPushButton *nextpage_pushbutton;

    void setupUi(QDialog *AlarmHistoryQueryDialog)
    {
        if (AlarmHistoryQueryDialog->objectName().isEmpty())
            AlarmHistoryQueryDialog->setObjectName(QString::fromUtf8("AlarmHistoryQueryDialog"));
        AlarmHistoryQueryDialog->resize(843, 634);
        verticalLayout_2 = new QVBoxLayout(AlarmHistoryQueryDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(AlarmHistoryQueryDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        building_combobox = new QComboBox(AlarmHistoryQueryDialog);
        building_combobox->setObjectName(QString::fromUtf8("building_combobox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(building_combobox->sizePolicy().hasHeightForWidth());
        building_combobox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(building_combobox);


        horizontalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(AlarmHistoryQueryDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        floor_combobox = new QComboBox(AlarmHistoryQueryDialog);
        floor_combobox->setObjectName(QString::fromUtf8("floor_combobox"));
        sizePolicy.setHeightForWidth(floor_combobox->sizePolicy().hasHeightForWidth());
        floor_combobox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(floor_combobox);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(AlarmHistoryQueryDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        room_combobox = new QComboBox(AlarmHistoryQueryDialog);
        room_combobox->setObjectName(QString::fromUtf8("room_combobox"));
        sizePolicy.setHeightForWidth(room_combobox->sizePolicy().hasHeightForWidth());
        room_combobox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(room_combobox);


        horizontalLayout_9->addLayout(horizontalLayout_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        all_checkBox = new QCheckBox(AlarmHistoryQueryDialog);
        all_checkBox->setObjectName(QString::fromUtf8("all_checkBox"));

        horizontalLayout_7->addWidget(all_checkBox);

        smoke_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        smoke_checkbox->setObjectName(QString::fromUtf8("smoke_checkbox"));

        horizontalLayout_7->addWidget(smoke_checkbox);

        mattress_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        mattress_checkbox->setObjectName(QString::fromUtf8("mattress_checkbox"));

        horizontalLayout_7->addWidget(mattress_checkbox);

        pm25_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        pm25_checkbox->setObjectName(QString::fromUtf8("pm25_checkbox"));

        horizontalLayout_7->addWidget(pm25_checkbox);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(AlarmHistoryQueryDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        tempratrueup_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        tempratrueup_checkbox->setObjectName(QString::fromUtf8("tempratrueup_checkbox"));

        horizontalLayout_5->addWidget(tempratrueup_checkbox);

        moistrueup_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        moistrueup_checkbox->setObjectName(QString::fromUtf8("moistrueup_checkbox"));

        horizontalLayout_5->addWidget(moistrueup_checkbox);

        O2up_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        O2up_checkbox->setObjectName(QString::fromUtf8("O2up_checkbox"));

        horizontalLayout_5->addWidget(O2up_checkbox);

        CO2up_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        CO2up_checkbox->setObjectName(QString::fromUtf8("CO2up_checkbox"));

        horizontalLayout_5->addWidget(CO2up_checkbox);

        indexsup_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        indexsup_checkbox->setObjectName(QString::fromUtf8("indexsup_checkbox"));

        horizontalLayout_5->addWidget(indexsup_checkbox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(AlarmHistoryQueryDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        tempraturedown_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        tempraturedown_checkbox->setObjectName(QString::fromUtf8("tempraturedown_checkbox"));

        horizontalLayout_6->addWidget(tempraturedown_checkbox);

        moisturedown_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        moisturedown_checkbox->setObjectName(QString::fromUtf8("moisturedown_checkbox"));

        horizontalLayout_6->addWidget(moisturedown_checkbox);

        O2down_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        O2down_checkbox->setObjectName(QString::fromUtf8("O2down_checkbox"));

        horizontalLayout_6->addWidget(O2down_checkbox);

        CO2down_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        CO2down_checkbox->setObjectName(QString::fromUtf8("CO2down_checkbox"));

        horizontalLayout_6->addWidget(CO2down_checkbox);

        indexsdown_checkbox = new QCheckBox(AlarmHistoryQueryDialog);
        indexsdown_checkbox->setObjectName(QString::fromUtf8("indexsdown_checkbox"));

        horizontalLayout_6->addWidget(indexsdown_checkbox);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startandend_label = new QLabel(AlarmHistoryQueryDialog);
        startandend_label->setObjectName(QString::fromUtf8("startandend_label"));

        horizontalLayout->addWidget(startandend_label);

        start_dateedit = new QDateEdit(AlarmHistoryQueryDialog);
        start_dateedit->setObjectName(QString::fromUtf8("start_dateedit"));

        horizontalLayout->addWidget(start_dateedit);

        start_timeedit = new QTimeEdit(AlarmHistoryQueryDialog);
        start_timeedit->setObjectName(QString::fromUtf8("start_timeedit"));

        horizontalLayout->addWidget(start_timeedit);

        label = new QLabel(AlarmHistoryQueryDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        end_dateedit = new QDateEdit(AlarmHistoryQueryDialog);
        end_dateedit->setObjectName(QString::fromUtf8("end_dateedit"));

        horizontalLayout->addWidget(end_dateedit);

        end_timeedit = new QTimeEdit(AlarmHistoryQueryDialog);
        end_timeedit->setObjectName(QString::fromUtf8("end_timeedit"));

        horizontalLayout->addWidget(end_timeedit);


        horizontalLayout_11->addLayout(horizontalLayout);

        horizontalSpacer_5 = new QSpacerItem(105, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        search_pushbutton = new QPushButton(AlarmHistoryQueryDialog);
        search_pushbutton->setObjectName(QString::fromUtf8("search_pushbutton"));

        horizontalLayout_11->addWidget(search_pushbutton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_11);

        tableWidget = new QTableWidget(AlarmHistoryQueryDialog);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setRowCount(15);
        tableWidget->setColumnCount(8);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        totalcount_label = new QLabel(AlarmHistoryQueryDialog);
        totalcount_label->setObjectName(QString::fromUtf8("totalcount_label"));

        horizontalLayout_10->addWidget(totalcount_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        lastpage_pushbutton = new QPushButton(AlarmHistoryQueryDialog);
        lastpage_pushbutton->setObjectName(QString::fromUtf8("lastpage_pushbutton"));

        horizontalLayout_10->addWidget(lastpage_pushbutton);

        pagenum_lineedit = new QLineEdit(AlarmHistoryQueryDialog);
        pagenum_lineedit->setObjectName(QString::fromUtf8("pagenum_lineedit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pagenum_lineedit->sizePolicy().hasHeightForWidth());
        pagenum_lineedit->setSizePolicy(sizePolicy1);
        pagenum_lineedit->setMaximumSize(QSize(50, 16777215));
        pagenum_lineedit->setContextMenuPolicy(Qt::NoContextMenu);
        pagenum_lineedit->setAlignment(Qt::AlignCenter);
        pagenum_lineedit->setReadOnly(true);

        horizontalLayout_10->addWidget(pagenum_lineedit);

        nextpage_pushbutton = new QPushButton(AlarmHistoryQueryDialog);
        nextpage_pushbutton->setObjectName(QString::fromUtf8("nextpage_pushbutton"));

        horizontalLayout_10->addWidget(nextpage_pushbutton);


        verticalLayout_2->addLayout(horizontalLayout_10);


        retranslateUi(AlarmHistoryQueryDialog);

        QMetaObject::connectSlotsByName(AlarmHistoryQueryDialog);
    } // setupUi

    void retranslateUi(QDialog *AlarmHistoryQueryDialog)
    {
        AlarmHistoryQueryDialog->setWindowTitle(QApplication::translate("AlarmHistoryQueryDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\245\274\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\245\274\345\261\202\345\220\215", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\210\277\351\227\264\345\220\215", 0, QApplication::UnicodeUTF8));
        all_checkBox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
        smoke_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\347\203\237\346\204\237", 0, QApplication::UnicodeUTF8));
        mattress_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\345\272\212\345\236\253", 0, QApplication::UnicodeUTF8));
        pm25_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "PM2.5", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AlarmHistoryQueryDialog", "\344\270\212\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        tempratrueup_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        moistrueup_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        O2up_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        CO2up_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        indexsup_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\347\273\274\345\220\210\346\214\207\346\225\260", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AlarmHistoryQueryDialog", "\344\270\213\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        tempraturedown_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        moisturedown_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        O2down_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        CO2down_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        indexsdown_checkbox->setText(QApplication::translate("AlarmHistoryQueryDialog", "\347\273\274\345\220\210\346\214\207\346\225\260", 0, QApplication::UnicodeUTF8));
        startandend_label->setText(QApplication::translate("AlarmHistoryQueryDialog", "\350\265\267\346\255\242\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        start_dateedit->setDisplayFormat(QApplication::translate("AlarmHistoryQueryDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        start_timeedit->setDisplayFormat(QApplication::translate("AlarmHistoryQueryDialog", "HH:mm:ss", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AlarmHistoryQueryDialog", "--", 0, QApplication::UnicodeUTF8));
        end_dateedit->setDisplayFormat(QApplication::translate("AlarmHistoryQueryDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        end_timeedit->setDisplayFormat(QApplication::translate("AlarmHistoryQueryDialog", "HH:mm:ss", 0, QApplication::UnicodeUTF8));
        search_pushbutton->setText(QApplication::translate("AlarmHistoryQueryDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        totalcount_label->setText(QString());
        lastpage_pushbutton->setText(QApplication::translate("AlarmHistoryQueryDialog", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pagenum_lineedit->setText(QString());
        nextpage_pushbutton->setText(QApplication::translate("AlarmHistoryQueryDialog", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AlarmHistoryQueryDialog: public Ui_AlarmHistoryQueryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMHISTORYQUERYDIALOG_H
