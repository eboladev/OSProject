/********************************************************************************
** Form generated from reading UI file 'historydataform.ui'
**
** Created: Fri Feb 28 20:02:46 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYDATAFORM_H
#define UI_HISTORYDATAFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryDataForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *left_horizontalspacer;
    QLabel *start_label;
    QDateEdit *start_dateedit;
    QTimeEdit *start_timeedit;
    QLabel *seprator_label;
    QDateEdit *end_dateedit;
    QTimeEdit *end_timeedit;
    QPushButton *search_pushbutton;
    QSpacerItem *right_horizontalspacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *arghint_label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addcol_pushbutton;
    QPushButton *delcol_pushbutton;

    void setupUi(QWidget *HistoryDataForm)
    {
        if (HistoryDataForm->objectName().isEmpty())
            HistoryDataForm->setObjectName(QString::fromUtf8("HistoryDataForm"));
        HistoryDataForm->resize(617, 471);
        verticalLayout = new QVBoxLayout(HistoryDataForm);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(HistoryDataForm);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setLineWidth(4);
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        widget_2 = new QWidget(HistoryDataForm);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, -1, -1, -1);
        left_horizontalspacer = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(left_horizontalspacer);

        start_label = new QLabel(widget_2);
        start_label->setObjectName(QString::fromUtf8("start_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(start_label->sizePolicy().hasHeightForWidth());
        start_label->setSizePolicy(sizePolicy2);
        start_label->setFrameShape(QFrame::StyledPanel);
        start_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(start_label);

        start_dateedit = new QDateEdit(widget_2);
        start_dateedit->setObjectName(QString::fromUtf8("start_dateedit"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(3);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(start_dateedit->sizePolicy().hasHeightForWidth());
        start_dateedit->setSizePolicy(sizePolicy3);
        start_dateedit->setDateTime(QDateTime(QDate(2013, 9, 14), QTime(0, 0, 0)));
        start_dateedit->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        start_dateedit->setMinimumDateTime(QDateTime(QDate(2013, 9, 1), QTime(0, 0, 0)));
        start_dateedit->setCurrentSection(QDateTimeEdit::YearSection);
        start_dateedit->setCalendarPopup(true);
        start_dateedit->setTimeSpec(Qt::LocalTime);

        horizontalLayout_2->addWidget(start_dateedit);

        start_timeedit = new QTimeEdit(widget_2);
        start_timeedit->setObjectName(QString::fromUtf8("start_timeedit"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(start_timeedit->sizePolicy().hasHeightForWidth());
        start_timeedit->setSizePolicy(sizePolicy4);
        start_timeedit->setDateTime(QDateTime(QDate(2013, 9, 14), QTime(0, 0, 0)));
        start_timeedit->setMaximumDateTime(QDateTime(QDate(2013, 9, 14), QTime(23, 59, 59)));
        start_timeedit->setMinimumDateTime(QDateTime(QDate(2013, 9, 14), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(start_timeedit);

        seprator_label = new QLabel(widget_2);
        seprator_label->setObjectName(QString::fromUtf8("seprator_label"));

        horizontalLayout_2->addWidget(seprator_label);

        end_dateedit = new QDateEdit(widget_2);
        end_dateedit->setObjectName(QString::fromUtf8("end_dateedit"));
        sizePolicy3.setHeightForWidth(end_dateedit->sizePolicy().hasHeightForWidth());
        end_dateedit->setSizePolicy(sizePolicy3);
        end_dateedit->setDateTime(QDateTime(QDate(2013, 9, 15), QTime(0, 0, 0)));
        end_dateedit->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        end_dateedit->setMinimumDateTime(QDateTime(QDate(2013, 9, 1), QTime(0, 0, 0)));
        end_dateedit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(end_dateedit);

        end_timeedit = new QTimeEdit(widget_2);
        end_timeedit->setObjectName(QString::fromUtf8("end_timeedit"));
        sizePolicy3.setHeightForWidth(end_timeedit->sizePolicy().hasHeightForWidth());
        end_timeedit->setSizePolicy(sizePolicy3);
        end_timeedit->setDateTime(QDateTime(QDate(2013, 9, 15), QTime(0, 0, 0)));
        end_timeedit->setMaximumDateTime(QDateTime(QDate(2013, 9, 15), QTime(23, 59, 59)));
        end_timeedit->setMinimumDateTime(QDateTime(QDate(2013, 9, 15), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(end_timeedit);

        search_pushbutton = new QPushButton(widget_2);
        search_pushbutton->setObjectName(QString::fromUtf8("search_pushbutton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(search_pushbutton->sizePolicy().hasHeightForWidth());
        search_pushbutton->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(search_pushbutton);

        right_horizontalspacer = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(right_horizontalspacer);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(HistoryDataForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(5);
        sizePolicy6.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy6);

        verticalLayout->addWidget(widget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 9, -1);
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        arghint_label = new QLabel(HistoryDataForm);
        arghint_label->setObjectName(QString::fromUtf8("arghint_label"));

        horizontalLayout_3->addWidget(arghint_label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        addcol_pushbutton = new QPushButton(HistoryDataForm);
        addcol_pushbutton->setObjectName(QString::fromUtf8("addcol_pushbutton"));
        sizePolicy5.setHeightForWidth(addcol_pushbutton->sizePolicy().hasHeightForWidth());
        addcol_pushbutton->setSizePolicy(sizePolicy5);

        horizontalLayout_3->addWidget(addcol_pushbutton);

        delcol_pushbutton = new QPushButton(HistoryDataForm);
        delcol_pushbutton->setObjectName(QString::fromUtf8("delcol_pushbutton"));

        horizontalLayout_3->addWidget(delcol_pushbutton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(HistoryDataForm);

        QMetaObject::connectSlotsByName(HistoryDataForm);
    } // setupUi

    void retranslateUi(QWidget *HistoryDataForm)
    {
        HistoryDataForm->setWindowTitle(QApplication::translate("HistoryDataForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HistoryDataForm", "\345\216\206\345\217\262\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        start_label->setText(QApplication::translate("HistoryDataForm", " \350\265\267\346\255\242\346\227\266\351\227\264 ", 0, QApplication::UnicodeUTF8));
        start_dateedit->setDisplayFormat(QApplication::translate("HistoryDataForm", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        start_timeedit->setDisplayFormat(QApplication::translate("HistoryDataForm", "HH:mm", 0, QApplication::UnicodeUTF8));
        seprator_label->setText(QApplication::translate("HistoryDataForm", "\342\200\224", 0, QApplication::UnicodeUTF8));
        end_dateedit->setDisplayFormat(QApplication::translate("HistoryDataForm", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        end_timeedit->setDisplayFormat(QApplication::translate("HistoryDataForm", "HH:mm", 0, QApplication::UnicodeUTF8));
        search_pushbutton->setText(QApplication::translate("HistoryDataForm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        arghint_label->setText(QString());
        addcol_pushbutton->setText(QApplication::translate("HistoryDataForm", "\345\242\236\345\212\240\345\210\227", 0, QApplication::UnicodeUTF8));
        delcol_pushbutton->setText(QApplication::translate("HistoryDataForm", "\345\210\240\351\231\244\345\210\227", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HistoryDataForm: public Ui_HistoryDataForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYDATAFORM_H
