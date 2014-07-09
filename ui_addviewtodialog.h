/********************************************************************************
** Form generated from reading UI file 'addviewtodialog.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVIEWTODIALOG_H
#define UI_ADDVIEWTODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddViewToDialog
{
public:
    QPushButton *confirm_pushbutton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *view_label;
    QLineEdit *view_lineedit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *builiding_label;
    QComboBox *building_combobox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *floor_label;
    QComboBox *floor_combobox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *room_label;
    QComboBox *room_combobox;

    void setupUi(QDialog *AddViewToDialog)
    {
        if (AddViewToDialog->objectName().isEmpty())
            AddViewToDialog->setObjectName(QString::fromUtf8("AddViewToDialog"));
        AddViewToDialog->resize(205, 160);
        confirm_pushbutton = new QPushButton(AddViewToDialog);
        confirm_pushbutton->setObjectName(QString::fromUtf8("confirm_pushbutton"));
        confirm_pushbutton->setGeometry(QRect(111, 127, 75, 23));
        widget = new QWidget(AddViewToDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 167, 108));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        view_label = new QLabel(widget);
        view_label->setObjectName(QString::fromUtf8("view_label"));

        horizontalLayout->addWidget(view_label);

        view_lineedit = new QLineEdit(widget);
        view_lineedit->setObjectName(QString::fromUtf8("view_lineedit"));
        view_lineedit->setReadOnly(true);

        horizontalLayout->addWidget(view_lineedit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        builiding_label = new QLabel(widget);
        builiding_label->setObjectName(QString::fromUtf8("builiding_label"));

        horizontalLayout_2->addWidget(builiding_label);

        building_combobox = new QComboBox(widget);
        building_combobox->setObjectName(QString::fromUtf8("building_combobox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(building_combobox->sizePolicy().hasHeightForWidth());
        building_combobox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(building_combobox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        floor_label = new QLabel(widget);
        floor_label->setObjectName(QString::fromUtf8("floor_label"));

        horizontalLayout_3->addWidget(floor_label);

        floor_combobox = new QComboBox(widget);
        floor_combobox->setObjectName(QString::fromUtf8("floor_combobox"));
        sizePolicy.setHeightForWidth(floor_combobox->sizePolicy().hasHeightForWidth());
        floor_combobox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(floor_combobox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        room_label = new QLabel(widget);
        room_label->setObjectName(QString::fromUtf8("room_label"));

        horizontalLayout_4->addWidget(room_label);

        room_combobox = new QComboBox(widget);
        room_combobox->setObjectName(QString::fromUtf8("room_combobox"));
        sizePolicy.setHeightForWidth(room_combobox->sizePolicy().hasHeightForWidth());
        room_combobox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(room_combobox);


        verticalLayout->addLayout(horizontalLayout_4);

#ifndef QT_NO_SHORTCUT
        view_label->setBuddy(view_lineedit);
        builiding_label->setBuddy(building_combobox);
        floor_label->setBuddy(floor_combobox);
        room_label->setBuddy(room_combobox);
#endif // QT_NO_SHORTCUT

        retranslateUi(AddViewToDialog);

        QMetaObject::connectSlotsByName(AddViewToDialog);
    } // setupUi

    void retranslateUi(QDialog *AddViewToDialog)
    {
        AddViewToDialog->setWindowTitle(QApplication::translate("AddViewToDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        confirm_pushbutton->setText(QApplication::translate("AddViewToDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        view_label->setText(QApplication::translate("AddViewToDialog", "\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
        builiding_label->setText(QApplication::translate("AddViewToDialog", "\346\245\274\346\240\213", 0, QApplication::UnicodeUTF8));
        floor_label->setText(QApplication::translate("AddViewToDialog", "\346\245\274\345\261\202", 0, QApplication::UnicodeUTF8));
        room_label->setText(QApplication::translate("AddViewToDialog", "\346\210\277\351\227\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddViewToDialog: public Ui_AddViewToDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVIEWTODIALOG_H
