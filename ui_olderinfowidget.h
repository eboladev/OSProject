/********************************************************************************
** Form generated from reading UI file 'olderinfowidget.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OLDERINFOWIDGET_H
#define UI_OLDERINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OlderInfoWidget
{
public:
    QGroupBox *custominfo_groupbox;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *custominfo_textedit;
    QGroupBox *basicinfo_groupbox;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *photo_label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *name_label;
    QLineEdit *name_lineedit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *birth_label;
    QLineEdit *birth_lineedit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *servicetype_label;
    QLineEdit *servicetype_lineedit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *buildingno_label;
    QLineEdit *buildingno_lineedit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *roomno_label;
    QLineEdit *roomno_lineedit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ic_label;
    QLineEdit *ic_lineedit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *contactor_label;
    QLineEdit *contactor_lineedit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sex_label;
    QLineEdit *sex_lineedit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *bodystate_label;
    QLineEdit *bodystate_lineedit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *mattressstate_label;
    QLineEdit *mattress_lineedit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *floorno_label;
    QLineEdit *floorno_lineedit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *bedno_label;
    QLineEdit *bedno_lineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *tel_label;
    QLineEdit *tel_lineedit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *contactortel_label;
    QLineEdit *contactortellineedit;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget6;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget7;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget8;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget9;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget10;
    QVBoxLayout *verticalLayout_12;

    void setupUi(QWidget *OlderInfoWidget)
    {
        if (OlderInfoWidget->objectName().isEmpty())
            OlderInfoWidget->setObjectName(QString::fromUtf8("OlderInfoWidget"));
        OlderInfoWidget->resize(538, 347);
        custominfo_groupbox = new QGroupBox(OlderInfoWidget);
        custominfo_groupbox->setObjectName(QString::fromUtf8("custominfo_groupbox"));
        custominfo_groupbox->setGeometry(QRect(10, 210, 515, 121));
        verticalLayout_3 = new QVBoxLayout(custominfo_groupbox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        custominfo_textedit = new QTextEdit(custominfo_groupbox);
        custominfo_textedit->setObjectName(QString::fromUtf8("custominfo_textedit"));
        custominfo_textedit->setEnabled(true);
        custominfo_textedit->setFrameShape(QFrame::StyledPanel);
        custominfo_textedit->setFrameShadow(QFrame::Raised);
        custominfo_textedit->setLineWidth(1);
        custominfo_textedit->setAcceptRichText(false);
        custominfo_textedit->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_3->addWidget(custominfo_textedit);

        basicinfo_groupbox = new QGroupBox(OlderInfoWidget);
        basicinfo_groupbox->setObjectName(QString::fromUtf8("basicinfo_groupbox"));
        basicinfo_groupbox->setGeometry(QRect(10, 0, 515, 201));
        groupBox_3 = new QGroupBox(basicinfo_groupbox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(392, 19, 111, 161));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        photo_label = new QLabel(groupBox_3);
        photo_label->setObjectName(QString::fromUtf8("photo_label"));

        verticalLayout_4->addWidget(photo_label);

        widget = new QWidget(basicinfo_groupbox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(14, 19, 181, 171));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        name_label = new QLabel(widget);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        horizontalLayout->addWidget(name_label);

        name_lineedit = new QLineEdit(widget);
        name_lineedit->setObjectName(QString::fromUtf8("name_lineedit"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(213, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(149, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 127, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(56, 170, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(170, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        name_lineedit->setPalette(palette);
        name_lineedit->setFrame(false);
        name_lineedit->setReadOnly(true);

        horizontalLayout->addWidget(name_lineedit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        birth_label = new QLabel(widget);
        birth_label->setObjectName(QString::fromUtf8("birth_label"));

        horizontalLayout_3->addWidget(birth_label);

        birth_lineedit = new QLineEdit(widget);
        birth_lineedit->setObjectName(QString::fromUtf8("birth_lineedit"));
        birth_lineedit->setFrame(false);
        birth_lineedit->setReadOnly(true);

        horizontalLayout_3->addWidget(birth_lineedit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        servicetype_label = new QLabel(widget);
        servicetype_label->setObjectName(QString::fromUtf8("servicetype_label"));

        horizontalLayout_8->addWidget(servicetype_label);

        servicetype_lineedit = new QLineEdit(widget);
        servicetype_lineedit->setObjectName(QString::fromUtf8("servicetype_lineedit"));
        servicetype_lineedit->setFrame(false);
        servicetype_lineedit->setReadOnly(true);

        horizontalLayout_8->addWidget(servicetype_lineedit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        buildingno_label = new QLabel(widget);
        buildingno_label->setObjectName(QString::fromUtf8("buildingno_label"));

        horizontalLayout_13->addWidget(buildingno_label);

        buildingno_lineedit = new QLineEdit(widget);
        buildingno_lineedit->setObjectName(QString::fromUtf8("buildingno_lineedit"));
        buildingno_lineedit->setFrame(false);

        horizontalLayout_13->addWidget(buildingno_lineedit);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        roomno_label = new QLabel(widget);
        roomno_label->setObjectName(QString::fromUtf8("roomno_label"));

        horizontalLayout_5->addWidget(roomno_label);

        roomno_lineedit = new QLineEdit(widget);
        roomno_lineedit->setObjectName(QString::fromUtf8("roomno_lineedit"));
        roomno_lineedit->setFrame(false);
        roomno_lineedit->setReadOnly(true);

        horizontalLayout_5->addWidget(roomno_lineedit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ic_label = new QLabel(widget);
        ic_label->setObjectName(QString::fromUtf8("ic_label"));

        horizontalLayout_6->addWidget(ic_label);

        ic_lineedit = new QLineEdit(widget);
        ic_lineedit->setObjectName(QString::fromUtf8("ic_lineedit"));
        ic_lineedit->setFrame(false);
        ic_lineedit->setReadOnly(true);

        horizontalLayout_6->addWidget(ic_lineedit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        contactor_label = new QLabel(widget);
        contactor_label->setObjectName(QString::fromUtf8("contactor_label"));

        horizontalLayout_11->addWidget(contactor_label);

        contactor_lineedit = new QLineEdit(widget);
        contactor_lineedit->setObjectName(QString::fromUtf8("contactor_lineedit"));
        contactor_lineedit->setFrame(false);
        contactor_lineedit->setReadOnly(true);

        horizontalLayout_11->addWidget(contactor_lineedit);


        verticalLayout->addLayout(horizontalLayout_11);

        widget1 = new QWidget(basicinfo_groupbox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(209, 18, 171, 171));
        verticalLayout_13 = new QVBoxLayout(widget1);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sex_label = new QLabel(widget1);
        sex_label->setObjectName(QString::fromUtf8("sex_label"));

        horizontalLayout_2->addWidget(sex_label);

        sex_lineedit = new QLineEdit(widget1);
        sex_lineedit->setObjectName(QString::fromUtf8("sex_lineedit"));
        sex_lineedit->setCursor(QCursor(Qt::ArrowCursor));
        sex_lineedit->setFrame(false);
        sex_lineedit->setReadOnly(true);

        horizontalLayout_2->addWidget(sex_lineedit);


        verticalLayout_13->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bodystate_label = new QLabel(widget1);
        bodystate_label->setObjectName(QString::fromUtf8("bodystate_label"));

        horizontalLayout_4->addWidget(bodystate_label);

        bodystate_lineedit = new QLineEdit(widget1);
        bodystate_lineedit->setObjectName(QString::fromUtf8("bodystate_lineedit"));
        bodystate_lineedit->setFrame(false);
        bodystate_lineedit->setReadOnly(true);

        horizontalLayout_4->addWidget(bodystate_lineedit);


        verticalLayout_13->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        mattressstate_label = new QLabel(widget1);
        mattressstate_label->setObjectName(QString::fromUtf8("mattressstate_label"));

        horizontalLayout_9->addWidget(mattressstate_label);

        mattress_lineedit = new QLineEdit(widget1);
        mattress_lineedit->setObjectName(QString::fromUtf8("mattress_lineedit"));
        mattress_lineedit->setFrame(false);
        mattress_lineedit->setReadOnly(true);

        horizontalLayout_9->addWidget(mattress_lineedit);


        verticalLayout_13->addLayout(horizontalLayout_9);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        floorno_label = new QLabel(widget1);
        floorno_label->setObjectName(QString::fromUtf8("floorno_label"));

        horizontalLayout_14->addWidget(floorno_label);

        floorno_lineedit = new QLineEdit(widget1);
        floorno_lineedit->setObjectName(QString::fromUtf8("floorno_lineedit"));
        floorno_lineedit->setFrame(false);
        floorno_lineedit->setReadOnly(true);

        horizontalLayout_14->addWidget(floorno_lineedit);


        verticalLayout_13->addLayout(horizontalLayout_14);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        bedno_label = new QLabel(widget1);
        bedno_label->setObjectName(QString::fromUtf8("bedno_label"));

        horizontalLayout_7->addWidget(bedno_label);

        bedno_lineEdit = new QLineEdit(widget1);
        bedno_lineEdit->setObjectName(QString::fromUtf8("bedno_lineEdit"));
        bedno_lineEdit->setFrame(false);
        bedno_lineEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(bedno_lineEdit);


        verticalLayout_13->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        tel_label = new QLabel(widget1);
        tel_label->setObjectName(QString::fromUtf8("tel_label"));

        horizontalLayout_10->addWidget(tel_label);

        tel_lineedit = new QLineEdit(widget1);
        tel_lineedit->setObjectName(QString::fromUtf8("tel_lineedit"));
        tel_lineedit->setFrame(false);
        tel_lineedit->setReadOnly(true);

        horizontalLayout_10->addWidget(tel_lineedit);


        verticalLayout_13->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        contactortel_label = new QLabel(widget1);
        contactortel_label->setObjectName(QString::fromUtf8("contactortel_label"));

        horizontalLayout_12->addWidget(contactortel_label);

        contactortellineedit = new QLineEdit(widget1);
        contactortellineedit->setObjectName(QString::fromUtf8("contactortellineedit"));
        contactortellineedit->setFrame(false);
        contactortellineedit->setReadOnly(true);

        horizontalLayout_12->addWidget(contactortellineedit);


        verticalLayout_13->addLayout(horizontalLayout_12);

        groupBox_3->raise();
        buildingno_label->raise();
        widget2 = new QWidget(OlderInfoWidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget3 = new QWidget(OlderInfoWidget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_5 = new QVBoxLayout(widget3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget4 = new QWidget(OlderInfoWidget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_6 = new QVBoxLayout(widget4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget5 = new QWidget(OlderInfoWidget);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_7 = new QVBoxLayout(widget5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget6 = new QWidget(OlderInfoWidget);
        widget6->setObjectName(QString::fromUtf8("widget6"));
        widget6->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_8 = new QVBoxLayout(widget6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget7 = new QWidget(OlderInfoWidget);
        widget7->setObjectName(QString::fromUtf8("widget7"));
        widget7->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_9 = new QVBoxLayout(widget7);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget8 = new QWidget(OlderInfoWidget);
        widget8->setObjectName(QString::fromUtf8("widget8"));
        widget8->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_10 = new QVBoxLayout(widget8);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        widget9 = new QWidget(OlderInfoWidget);
        widget9->setObjectName(QString::fromUtf8("widget9"));
        widget9->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_11 = new QVBoxLayout(widget9);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        widget10 = new QWidget(OlderInfoWidget);
        widget10->setObjectName(QString::fromUtf8("widget10"));
        widget10->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_12 = new QVBoxLayout(widget10);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);

        retranslateUi(OlderInfoWidget);

        QMetaObject::connectSlotsByName(OlderInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *OlderInfoWidget)
    {
        OlderInfoWidget->setWindowTitle(QApplication::translate("OlderInfoWidget", "Form", 0, QApplication::UnicodeUTF8));
        custominfo_groupbox->setTitle(QApplication::translate("OlderInfoWidget", "\345\256\232\345\210\266\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        custominfo_textedit->setHtml(QApplication::translate("OlderInfoWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\222\222\346\227\246\345\274\200\344\270\252\344\274\232\346\222\222\345\244\232\346\231\266\347\241\205\346\222\222\346\227\246\351\253\213\345\205\263\350\212\202\345\245\245\346\226\257\345\215\241\350\247\211\345\276\227\350\267\237\346\222\222\346\227\246\346\225\231\345\205\263\350\201\224\346\216\247\344\273\266\346\222\222\345\244\247\345\205\254\345\274\200\346\222\222\346\227\246\344\270\252\344\272\206\345\201\245\350\272\253\345\215\241\351\230\277\350\277\252\345\205\263\350\201\224\346\216\247\344\273\266\346\222\222\346\227\246\344"
                        "\272\206\345\271\262\346\222\222\347\232\204\350\200\203\350\231\221\350\277\207\346\222\222\344\272\206\346\222\222\346\227\246\351\276\231\346\241\202\346\261\237\346\222\222\346\227\246\344\270\252\344\272\206\345\207\257\346\222\222\350\200\275\346\220\201\344\272\206\345\215\241\350\247\206\350\247\222\345\233\272\345\256\232\345\210\227\345\256\275\345\260\261\346\222\222\346\227\246\344\272\206\351\253\213\345\205\263\350\212\202\346\222\222\344\272\206\350\202\257\345\276\267\345\237\272\345\223\245\346\213\211\346\226\257\345\212\240\345\276\227\345\210\251\345\215\241\346\255\273\345\276\227\346\233\264\345\277\253\344\272\206\346\222\222\345\250\207\347\232\204\344\272\206\351\253\213\345\205\263\350\212\202\350\220\250\345\205\213\351\233\267\345\244\247\351\251\276\345\205\211\344\270\264\346\222\222\347\251\272\345\247\220\344\273\243\350\264\255\346\213\211\346\226\257\345\205\213\345\245\226\347\232\204\351\230\277\346\226\257\351\241\277\344\272\206\346\216\247\344\273\266\346\240\274\346\213\211"
                        "\346\226\257\345\260\261\345\244\237\344\272\206\346\222\222</p></body></html>", 0, QApplication::UnicodeUTF8));
        basicinfo_groupbox->setTitle(QApplication::translate("OlderInfoWidget", "\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("OlderInfoWidget", "\344\270\252\344\272\272\347\205\247\347\211\207", 0, QApplication::UnicodeUTF8));
        photo_label->setText(QString());
        name_label->setText(QApplication::translate("OlderInfoWidget", "\345\247\223    \345\220\215 ", 0, QApplication::UnicodeUTF8));
        name_lineedit->setText(QApplication::translate("OlderInfoWidget", "\344\272\216\345\267\235\347\273\277\351\207\216", 0, QApplication::UnicodeUTF8));
        birth_label->setText(QApplication::translate("OlderInfoWidget", "\345\207\272\347\224\237\345\271\264\346\234\210 ", 0, QApplication::UnicodeUTF8));
        birth_lineedit->setText(QApplication::translate("OlderInfoWidget", "1990-06-20", 0, QApplication::UnicodeUTF8));
        servicetype_label->setText(QApplication::translate("OlderInfoWidget", "\347\233\221\346\212\244\347\261\273\345\236\213 ", 0, QApplication::UnicodeUTF8));
        servicetype_lineedit->setText(QApplication::translate("OlderInfoWidget", "\344\270\200\347\272\247\347\233\221\346\212\244", 0, QApplication::UnicodeUTF8));
        buildingno_label->setText(QApplication::translate("OlderInfoWidget", "\346\245\274    \345\220\215 ", 0, QApplication::UnicodeUTF8));
        buildingno_lineedit->setText(QApplication::translate("OlderInfoWidget", "\347\237\245\350\241\214\346\245\274", 0, QApplication::UnicodeUTF8));
        roomno_label->setText(QApplication::translate("OlderInfoWidget", "\346\210\277 \351\227\264 \345\217\267 ", 0, QApplication::UnicodeUTF8));
        roomno_lineedit->setText(QApplication::translate("OlderInfoWidget", "ws4581", 0, QApplication::UnicodeUTF8));
        ic_label->setText(QApplication::translate("OlderInfoWidget", "\350\272\253 \344\273\275 \350\257\201 ", 0, QApplication::UnicodeUTF8));
        ic_lineedit->setText(QApplication::translate("OlderInfoWidget", "32132319990620257X", 0, QApplication::UnicodeUTF8));
        contactor_label->setText(QApplication::translate("OlderInfoWidget", "\350\201\224 \347\263\273 \344\272\272 ", 0, QApplication::UnicodeUTF8));
        contactor_lineedit->setText(QApplication::translate("OlderInfoWidget", "\346\222\222\351\230\277\346\226\257\351\241\277\345\231\266", 0, QApplication::UnicodeUTF8));
        sex_label->setText(QApplication::translate("OlderInfoWidget", "\346\200\247    \345\210\253 ", 0, QApplication::UnicodeUTF8));
        sex_lineedit->setText(QApplication::translate("OlderInfoWidget", "\345\245\263", 0, QApplication::UnicodeUTF8));
        bodystate_label->setText(QApplication::translate("OlderInfoWidget", "\350\272\253\344\275\223\347\212\266\345\206\265 ", 0, QApplication::UnicodeUTF8));
        bodystate_lineedit->setText(QApplication::translate("OlderInfoWidget", "\350\272\253\344\275\223\345\201\245\345\272\267", 0, QApplication::UnicodeUTF8));
        mattressstate_label->setText(QApplication::translate("OlderInfoWidget", "\345\272\212\345\236\253\347\212\266\346\200\201 ", 0, QApplication::UnicodeUTF8));
        mattress_lineedit->setText(QApplication::translate("OlderInfoWidget", "\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        floorno_label->setText(QApplication::translate("OlderInfoWidget", "\346\245\274    \345\261\202 ", 0, QApplication::UnicodeUTF8));
        floorno_lineedit->setText(QApplication::translate("OlderInfoWidget", "\344\270\200\346\245\274", 0, QApplication::UnicodeUTF8));
        bedno_label->setText(QApplication::translate("OlderInfoWidget", "\345\272\212    \345\217\267 ", 0, QApplication::UnicodeUTF8));
        bedno_lineEdit->setText(QApplication::translate("OlderInfoWidget", "08", 0, QApplication::UnicodeUTF8));
        tel_label->setText(QApplication::translate("OlderInfoWidget", "\347\224\265    \350\257\235 ", 0, QApplication::UnicodeUTF8));
        tel_lineedit->setText(QApplication::translate("OlderInfoWidget", "+8602584985671", 0, QApplication::UnicodeUTF8));
        contactortel_label->setText(QApplication::translate("OlderInfoWidget", "\347\224\265    \350\257\235 ", 0, QApplication::UnicodeUTF8));
        contactortellineedit->setText(QApplication::translate("OlderInfoWidget", "+8602584985671", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OlderInfoWidget: public Ui_OlderInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OLDERINFOWIDGET_H
