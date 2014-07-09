/********************************************************************************
** Form generated from reading UI file 'prametertablewidget.ui'
**
** Created: Fri Feb 28 20:02:46 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRAMETERTABLEWIDGET_H
#define UI_PRAMETERTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrameterTableWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *edit_pushbutton;
    QPushButton *add_pushbutton;
    QPushButton *save_pushbutton;
    QPushButton *del_pushutton;

    void setupUi(QWidget *PrameterTableWidget)
    {
        if (PrameterTableWidget->objectName().isEmpty())
            PrameterTableWidget->setObjectName(QString::fromUtf8("PrameterTableWidget"));
        PrameterTableWidget->setEnabled(true);
        PrameterTableWidget->resize(352, 640);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrameterTableWidget->sizePolicy().hasHeightForWidth());
        PrameterTableWidget->setSizePolicy(sizePolicy);
        PrameterTableWidget->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(PrameterTableWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(PrameterTableWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        font.setKerning(true);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setLineWidth(4);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);

        widget = new QWidget(PrameterTableWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(widget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(0);
        edit_pushbutton = new QPushButton(PrameterTableWidget);
        edit_pushbutton->setObjectName(QString::fromUtf8("edit_pushbutton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(edit_pushbutton->sizePolicy().hasHeightForWidth());
        edit_pushbutton->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(14);
        edit_pushbutton->setFont(font1);

        gridLayout->addWidget(edit_pushbutton, 0, 0, 1, 1);

        add_pushbutton = new QPushButton(PrameterTableWidget);
        add_pushbutton->setObjectName(QString::fromUtf8("add_pushbutton"));
        sizePolicy2.setHeightForWidth(add_pushbutton->sizePolicy().hasHeightForWidth());
        add_pushbutton->setSizePolicy(sizePolicy2);
        add_pushbutton->setFont(font1);

        gridLayout->addWidget(add_pushbutton, 0, 1, 1, 1);

        save_pushbutton = new QPushButton(PrameterTableWidget);
        save_pushbutton->setObjectName(QString::fromUtf8("save_pushbutton"));
        sizePolicy2.setHeightForWidth(save_pushbutton->sizePolicy().hasHeightForWidth());
        save_pushbutton->setSizePolicy(sizePolicy2);
        save_pushbutton->setFont(font1);

        gridLayout->addWidget(save_pushbutton, 0, 3, 1, 1);

        del_pushutton = new QPushButton(PrameterTableWidget);
        del_pushutton->setObjectName(QString::fromUtf8("del_pushutton"));
        sizePolicy2.setHeightForWidth(del_pushutton->sizePolicy().hasHeightForWidth());
        del_pushutton->setSizePolicy(sizePolicy2);
        del_pushutton->setFont(font1);

        gridLayout->addWidget(del_pushutton, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PrameterTableWidget);

        QMetaObject::connectSlotsByName(PrameterTableWidget);
    } // setupUi

    void retranslateUi(QWidget *PrameterTableWidget)
    {
        PrameterTableWidget->setWindowTitle(QApplication::translate("PrameterTableWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PrameterTableWidget", " \345\217\202\346\225\260\350\241\250 ", 0, QApplication::UnicodeUTF8));
        edit_pushbutton->setText(QApplication::translate("PrameterTableWidget", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        add_pushbutton->setText(QApplication::translate("PrameterTableWidget", "\345\242\236\345\212\240", 0, QApplication::UnicodeUTF8));
        save_pushbutton->setText(QApplication::translate("PrameterTableWidget", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        del_pushutton->setText(QApplication::translate("PrameterTableWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrameterTableWidget: public Ui_PrameterTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRAMETERTABLEWIDGET_H
