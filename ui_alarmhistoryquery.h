/********************************************************************************
** Form generated from reading UI file 'alarmhistoryquery.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMHISTORYQUERY_H
#define UI_ALARMHISTORYQUERY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmHistoryQuery
{
public:
    QTableView *tableView;
    QComboBox *buildingCB;
    QComboBox *floorCB;
    QComboBox *roomCB;
    QCheckBox *all_checkBox;
    QDateEdit *start_dateEdit;
    QDateEdit *end_dateEdit_2;
    QTimeEdit *start_timeEdit;
    QTimeEdit *end_timeEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QPushButton *reset_pushButton_2;
    QWidget *widget;
    QCheckBox *temp_checkBox_2;
    QCheckBox *co2_checkBox_5;
    QCheckBox *vol1_checkBox_5;
    QCheckBox *moistrue_checkBox_8;
    QCheckBox *vol2_checkBox_7;
    QCheckBox *vol2_checkBox_6;
    QCheckBox *vol1_checkBox_6;
    QCheckBox *temp_checkBox_3;
    QCheckBox *moistrue_checkBox_7;
    QCheckBox *o2_checkBox_3;
    QCheckBox *co2_checkBox_4;
    QCheckBox *o2_checkBox_4;
    QLabel *label_6;
    QCheckBox *water_checkBox_9;
    QCheckBox *smoke_checkBox_8;
    QLabel *label_7;

    void setupUi(QDialog *AlarmHistoryQuery)
    {
        if (AlarmHistoryQuery->objectName().isEmpty())
            AlarmHistoryQuery->setObjectName(QString::fromUtf8("AlarmHistoryQuery"));
        AlarmHistoryQuery->setEnabled(true);
        AlarmHistoryQuery->resize(668, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AlarmHistoryQuery->sizePolicy().hasHeightForWidth());
        AlarmHistoryQuery->setSizePolicy(sizePolicy);
        tableView = new QTableView(AlarmHistoryQuery);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 125, 651, 341));
        buildingCB = new QComboBox(AlarmHistoryQuery);
        buildingCB->setObjectName(QString::fromUtf8("buildingCB"));
        buildingCB->setGeometry(QRect(50, 10, 69, 22));
        floorCB = new QComboBox(AlarmHistoryQuery);
        floorCB->setObjectName(QString::fromUtf8("floorCB"));
        floorCB->setGeometry(QRect(190, 10, 69, 22));
        roomCB = new QComboBox(AlarmHistoryQuery);
        roomCB->setObjectName(QString::fromUtf8("roomCB"));
        roomCB->setGeometry(QRect(350, 10, 69, 22));
        all_checkBox = new QCheckBox(AlarmHistoryQuery);
        all_checkBox->setObjectName(QString::fromUtf8("all_checkBox"));
        all_checkBox->setGeometry(QRect(10, 50, 45, 16));
        start_dateEdit = new QDateEdit(AlarmHistoryQuery);
        start_dateEdit->setObjectName(QString::fromUtf8("start_dateEdit"));
        start_dateEdit->setGeometry(QRect(70, 90, 81, 22));
        start_dateEdit->setCalendarPopup(true);
        end_dateEdit_2 = new QDateEdit(AlarmHistoryQuery);
        end_dateEdit_2->setObjectName(QString::fromUtf8("end_dateEdit_2"));
        end_dateEdit_2->setGeometry(QRect(230, 90, 81, 22));
        end_dateEdit_2->setCalendarPopup(true);
        start_timeEdit = new QTimeEdit(AlarmHistoryQuery);
        start_timeEdit->setObjectName(QString::fromUtf8("start_timeEdit"));
        start_timeEdit->setGeometry(QRect(155, 90, 51, 22));
        start_timeEdit->setCalendarPopup(false);
        end_timeEdit_2 = new QTimeEdit(AlarmHistoryQuery);
        end_timeEdit_2->setObjectName(QString::fromUtf8("end_timeEdit_2"));
        end_timeEdit_2->setGeometry(QRect(315, 90, 51, 22));
        label_2 = new QLabel(AlarmHistoryQuery);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 10, 54, 21));
        label_3 = new QLabel(AlarmHistoryQuery);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 10, 31, 21));
        label_4 = new QLabel(AlarmHistoryQuery);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 10, 41, 21));
        label = new QLabel(AlarmHistoryQuery);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 90, 21, 20));
        label_5 = new QLabel(AlarmHistoryQuery);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 90, 61, 20));
        reset_pushButton_2 = new QPushButton(AlarmHistoryQuery);
        reset_pushButton_2->setObjectName(QString::fromUtf8("reset_pushButton_2"));
        reset_pushButton_2->setGeometry(QRect(580, 90, 61, 23));
        widget = new QWidget(AlarmHistoryQuery);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 40, 601, 41));
        temp_checkBox_2 = new QCheckBox(widget);
        temp_checkBox_2->setObjectName(QString::fromUtf8("temp_checkBox_2"));
        temp_checkBox_2->setGeometry(QRect(170, 0, 45, 16));
        co2_checkBox_5 = new QCheckBox(widget);
        co2_checkBox_5->setObjectName(QString::fromUtf8("co2_checkBox_5"));
        co2_checkBox_5->setGeometry(QRect(350, 20, 71, 16));
        vol1_checkBox_5 = new QCheckBox(widget);
        vol1_checkBox_5->setObjectName(QString::fromUtf8("vol1_checkBox_5"));
        vol1_checkBox_5->setGeometry(QRect(440, 0, 71, 16));
        moistrue_checkBox_8 = new QCheckBox(widget);
        moistrue_checkBox_8->setObjectName(QString::fromUtf8("moistrue_checkBox_8"));
        moistrue_checkBox_8->setGeometry(QRect(230, 20, 45, 16));
        vol2_checkBox_7 = new QCheckBox(widget);
        vol2_checkBox_7->setObjectName(QString::fromUtf8("vol2_checkBox_7"));
        vol2_checkBox_7->setGeometry(QRect(530, 20, 71, 16));
        vol2_checkBox_6 = new QCheckBox(widget);
        vol2_checkBox_6->setObjectName(QString::fromUtf8("vol2_checkBox_6"));
        vol2_checkBox_6->setGeometry(QRect(530, 0, 71, 16));
        vol1_checkBox_6 = new QCheckBox(widget);
        vol1_checkBox_6->setObjectName(QString::fromUtf8("vol1_checkBox_6"));
        vol1_checkBox_6->setGeometry(QRect(440, 20, 71, 16));
        temp_checkBox_3 = new QCheckBox(widget);
        temp_checkBox_3->setObjectName(QString::fromUtf8("temp_checkBox_3"));
        temp_checkBox_3->setGeometry(QRect(170, 20, 45, 16));
        moistrue_checkBox_7 = new QCheckBox(widget);
        moistrue_checkBox_7->setObjectName(QString::fromUtf8("moistrue_checkBox_7"));
        moistrue_checkBox_7->setGeometry(QRect(230, 0, 45, 16));
        o2_checkBox_3 = new QCheckBox(widget);
        o2_checkBox_3->setObjectName(QString::fromUtf8("o2_checkBox_3"));
        o2_checkBox_3->setGeometry(QRect(290, 0, 45, 16));
        co2_checkBox_4 = new QCheckBox(widget);
        co2_checkBox_4->setObjectName(QString::fromUtf8("co2_checkBox_4"));
        co2_checkBox_4->setGeometry(QRect(350, 0, 71, 16));
        o2_checkBox_4 = new QCheckBox(widget);
        o2_checkBox_4->setObjectName(QString::fromUtf8("o2_checkBox_4"));
        o2_checkBox_4->setGeometry(QRect(290, 20, 45, 16));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 0, 31, 20));
        water_checkBox_9 = new QCheckBox(widget);
        water_checkBox_9->setObjectName(QString::fromUtf8("water_checkBox_9"));
        water_checkBox_9->setGeometry(QRect(10, 10, 41, 16));
        smoke_checkBox_8 = new QCheckBox(widget);
        smoke_checkBox_8->setObjectName(QString::fromUtf8("smoke_checkBox_8"));
        smoke_checkBox_8->setGeometry(QRect(70, 10, 41, 16));
        label_7 = new QLabel(AlarmHistoryQuery);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 60, 31, 20));
        QWidget::setTabOrder(buildingCB, floorCB);
        QWidget::setTabOrder(floorCB, roomCB);
        QWidget::setTabOrder(roomCB, all_checkBox);
        QWidget::setTabOrder(all_checkBox, temp_checkBox_2);
        QWidget::setTabOrder(temp_checkBox_2, temp_checkBox_3);
        QWidget::setTabOrder(temp_checkBox_3, moistrue_checkBox_7);
        QWidget::setTabOrder(moistrue_checkBox_7, moistrue_checkBox_8);
        QWidget::setTabOrder(moistrue_checkBox_8, o2_checkBox_3);
        QWidget::setTabOrder(o2_checkBox_3, o2_checkBox_4);
        QWidget::setTabOrder(o2_checkBox_4, co2_checkBox_4);
        QWidget::setTabOrder(co2_checkBox_4, co2_checkBox_5);
        QWidget::setTabOrder(co2_checkBox_5, vol1_checkBox_5);
        QWidget::setTabOrder(vol1_checkBox_5, vol1_checkBox_6);
        QWidget::setTabOrder(vol1_checkBox_6, vol2_checkBox_6);
        QWidget::setTabOrder(vol2_checkBox_6, vol2_checkBox_7);
        QWidget::setTabOrder(vol2_checkBox_7, smoke_checkBox_8);
        QWidget::setTabOrder(smoke_checkBox_8, water_checkBox_9);
        QWidget::setTabOrder(water_checkBox_9, start_dateEdit);
        QWidget::setTabOrder(start_dateEdit, start_timeEdit);
        QWidget::setTabOrder(start_timeEdit, end_dateEdit_2);
        QWidget::setTabOrder(end_dateEdit_2, end_timeEdit_2);
        QWidget::setTabOrder(end_timeEdit_2, reset_pushButton_2);
        QWidget::setTabOrder(reset_pushButton_2, tableView);

        retranslateUi(AlarmHistoryQuery);

        QMetaObject::connectSlotsByName(AlarmHistoryQuery);
    } // setupUi

    void retranslateUi(QDialog *AlarmHistoryQuery)
    {
        AlarmHistoryQuery->setWindowTitle(QApplication::translate("AlarmHistoryQuery", "AlarmHistoryQuery", 0, QApplication::UnicodeUTF8));
        all_checkBox->setText(QApplication::translate("AlarmHistoryQuery", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
        start_timeEdit->setDisplayFormat(QApplication::translate("AlarmHistoryQuery", "H:mm", 0, QApplication::UnicodeUTF8));
        end_timeEdit_2->setDisplayFormat(QApplication::translate("AlarmHistoryQuery", "H:mm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AlarmHistoryQuery", "\346\210\277\351\227\264\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AlarmHistoryQuery", "\345\261\202\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AlarmHistoryQuery", "\346\245\274\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AlarmHistoryQuery", "---", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AlarmHistoryQuery", "\346\237\245\350\257\242\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        reset_pushButton_2->setText(QApplication::translate("AlarmHistoryQuery", "\351\207\215\347\275\256\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        temp_checkBox_2->setText(QApplication::translate("AlarmHistoryQuery", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        co2_checkBox_5->setText(QApplication::translate("AlarmHistoryQuery", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        vol1_checkBox_5->setText(QApplication::translate("AlarmHistoryQuery", "\345\270\202\347\224\265\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        moistrue_checkBox_8->setText(QApplication::translate("AlarmHistoryQuery", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        vol2_checkBox_7->setText(QApplication::translate("AlarmHistoryQuery", "\351\233\266\347\224\265\345\216\213\345\267\256", 0, QApplication::UnicodeUTF8));
        vol2_checkBox_6->setText(QApplication::translate("AlarmHistoryQuery", "\351\233\266\347\224\265\345\216\213\345\267\256", 0, QApplication::UnicodeUTF8));
        vol1_checkBox_6->setText(QApplication::translate("AlarmHistoryQuery", "\345\270\202\347\224\265\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        temp_checkBox_3->setText(QApplication::translate("AlarmHistoryQuery", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        moistrue_checkBox_7->setText(QApplication::translate("AlarmHistoryQuery", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        o2_checkBox_3->setText(QApplication::translate("AlarmHistoryQuery", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        co2_checkBox_4->setText(QApplication::translate("AlarmHistoryQuery", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        o2_checkBox_4->setText(QApplication::translate("AlarmHistoryQuery", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AlarmHistoryQuery", "\344\270\212\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        water_checkBox_9->setText(QApplication::translate("AlarmHistoryQuery", "\346\260\264\344\275\215", 0, QApplication::UnicodeUTF8));
        smoke_checkBox_8->setText(QApplication::translate("AlarmHistoryQuery", "\347\203\237\351\233\276", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AlarmHistoryQuery", "\344\270\213\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AlarmHistoryQuery: public Ui_AlarmHistoryQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMHISTORYQUERY_H
