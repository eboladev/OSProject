/********************************************************************************
** Form generated from reading UI file 'preferencedialog.ui'
**
** Created: Fri Feb 28 20:02:46 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCEDIALOG_H
#define UI_PREFERENCEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PreferenceDialog
{
public:
    QToolButton *upmove_toolbutton;
    QToolButton *downmove_toolbutton;
    QGroupBox *groupBox;
    QGroupBox *selected_groupBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *curveselected_listidget;
    QLabel *label;
    QPushButton *add_pushbutton;
    QPushButton *delete_pushbutton;
    QPushButton *nextstep_pushbutton;
    QPushButton *cancel_pushbutton;

    void setupUi(QDialog *PreferenceDialog)
    {
        if (PreferenceDialog->objectName().isEmpty())
            PreferenceDialog->setObjectName(QString::fromUtf8("PreferenceDialog"));
        PreferenceDialog->resize(540, 280);
        upmove_toolbutton = new QToolButton(PreferenceDialog);
        upmove_toolbutton->setObjectName(QString::fromUtf8("upmove_toolbutton"));
        upmove_toolbutton->setGeometry(QRect(240, 67, 41, 25));
        downmove_toolbutton = new QToolButton(PreferenceDialog);
        downmove_toolbutton->setObjectName(QString::fromUtf8("downmove_toolbutton"));
        downmove_toolbutton->setGeometry(QRect(240, 100, 41, 25));
        groupBox = new QGroupBox(PreferenceDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 35, 221, 200));
        selected_groupBox = new QGroupBox(PreferenceDialog);
        selected_groupBox->setObjectName(QString::fromUtf8("selected_groupBox"));
        selected_groupBox->setGeometry(QRect(290, 35, 241, 200));
        verticalLayout_3 = new QVBoxLayout(selected_groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        curveselected_listidget = new QListWidget(selected_groupBox);
        curveselected_listidget->setObjectName(QString::fromUtf8("curveselected_listidget"));

        verticalLayout_3->addWidget(curveselected_listidget);

        label = new QLabel(PreferenceDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 10, 130, 20));
        add_pushbutton = new QPushButton(PreferenceDialog);
        add_pushbutton->setObjectName(QString::fromUtf8("add_pushbutton"));
        add_pushbutton->setGeometry(QRect(240, 156, 41, 25));
        add_pushbutton->setFocusPolicy(Qt::NoFocus);
        delete_pushbutton = new QPushButton(PreferenceDialog);
        delete_pushbutton->setObjectName(QString::fromUtf8("delete_pushbutton"));
        delete_pushbutton->setGeometry(QRect(240, 190, 41, 25));
        delete_pushbutton->setFocusPolicy(Qt::NoFocus);
        nextstep_pushbutton = new QPushButton(PreferenceDialog);
        nextstep_pushbutton->setObjectName(QString::fromUtf8("nextstep_pushbutton"));
        nextstep_pushbutton->setGeometry(QRect(420, 244, 52, 23));
        nextstep_pushbutton->setFocusPolicy(Qt::NoFocus);
        cancel_pushbutton = new QPushButton(PreferenceDialog);
        cancel_pushbutton->setObjectName(QString::fromUtf8("cancel_pushbutton"));
        cancel_pushbutton->setGeometry(QRect(478, 244, 51, 23));
        cancel_pushbutton->setFocusPolicy(Qt::NoFocus);
        add_pushbutton->raise();
        delete_pushbutton->raise();
        cancel_pushbutton->raise();
        upmove_toolbutton->raise();
        downmove_toolbutton->raise();
        groupBox->raise();
        selected_groupBox->raise();
        nextstep_pushbutton->raise();
        label->raise();
        QWidget::setTabOrder(curveselected_listidget, upmove_toolbutton);
        QWidget::setTabOrder(upmove_toolbutton, downmove_toolbutton);
        QWidget::setTabOrder(downmove_toolbutton, add_pushbutton);
        QWidget::setTabOrder(add_pushbutton, delete_pushbutton);
        QWidget::setTabOrder(delete_pushbutton, nextstep_pushbutton);
        QWidget::setTabOrder(nextstep_pushbutton, cancel_pushbutton);

        retranslateUi(PreferenceDialog);

        QMetaObject::connectSlotsByName(PreferenceDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferenceDialog)
    {
        PreferenceDialog->setWindowTitle(QApplication::translate("PreferenceDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        upmove_toolbutton->setText(QApplication::translate("PreferenceDialog", "\344\270\212\347\247\273", 0, QApplication::UnicodeUTF8));
        downmove_toolbutton->setText(QApplication::translate("PreferenceDialog", "\344\270\213\347\247\273", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PreferenceDialog", "\345\217\257\351\200\211\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        selected_groupBox->setTitle(QApplication::translate("PreferenceDialog", "\345\267\262\351\200\211\345\217\202\346\225\260(\346\234\200\345\244\2325\344\270\252)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PreferenceDialog", "\350\257\267\351\200\211\346\213\251\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        add_pushbutton->setText(QApplication::translate("PreferenceDialog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        delete_pushbutton->setText(QApplication::translate("PreferenceDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        nextstep_pushbutton->setText(QApplication::translate("PreferenceDialog", "\344\270\213\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        cancel_pushbutton->setText(QApplication::translate("PreferenceDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreferenceDialog: public Ui_PreferenceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCEDIALOG_H
