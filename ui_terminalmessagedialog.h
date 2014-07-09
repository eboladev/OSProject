/********************************************************************************
** Form generated from reading UI file 'terminalmessagedialog.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINALMESSAGEDIALOG_H
#define UI_TERMINALMESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TerminalMessageDialog
{
public:
    QGroupBox *targetmonitor_groupbox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *targetmonitor_combobox;
    QListWidget *selectedmonitor_listwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *addmonitor_toolbutton;
    QToolButton *removemonitor_toolbutton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *sentmessage_plaintextedit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *editmessage_plaintextedit;
    QPushButton *sent_pushbutton;

    void setupUi(QDialog *TerminalMessageDialog)
    {
        if (TerminalMessageDialog->objectName().isEmpty())
            TerminalMessageDialog->setObjectName(QString::fromUtf8("TerminalMessageDialog"));
        TerminalMessageDialog->resize(475, 312);
        TerminalMessageDialog->setContextMenuPolicy(Qt::NoContextMenu);
        targetmonitor_groupbox = new QGroupBox(TerminalMessageDialog);
        targetmonitor_groupbox->setObjectName(QString::fromUtf8("targetmonitor_groupbox"));
        targetmonitor_groupbox->setGeometry(QRect(10, 10, 170, 251));
        verticalLayout_3 = new QVBoxLayout(targetmonitor_groupbox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        targetmonitor_combobox = new QComboBox(targetmonitor_groupbox);
        targetmonitor_combobox->setObjectName(QString::fromUtf8("targetmonitor_combobox"));

        verticalLayout_3->addWidget(targetmonitor_combobox);

        selectedmonitor_listwidget = new QListWidget(targetmonitor_groupbox);
        selectedmonitor_listwidget->setObjectName(QString::fromUtf8("selectedmonitor_listwidget"));

        verticalLayout_3->addWidget(selectedmonitor_listwidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addmonitor_toolbutton = new QToolButton(targetmonitor_groupbox);
        addmonitor_toolbutton->setObjectName(QString::fromUtf8("addmonitor_toolbutton"));
        addmonitor_toolbutton->setMinimumSize(QSize(25, 25));

        horizontalLayout->addWidget(addmonitor_toolbutton);

        removemonitor_toolbutton = new QToolButton(targetmonitor_groupbox);
        removemonitor_toolbutton->setObjectName(QString::fromUtf8("removemonitor_toolbutton"));
        removemonitor_toolbutton->setMinimumSize(QSize(25, 25));

        horizontalLayout->addWidget(removemonitor_toolbutton);


        verticalLayout_3->addLayout(horizontalLayout);

        groupBox = new QGroupBox(TerminalMessageDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(190, 10, 276, 171));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sentmessage_plaintextedit = new QPlainTextEdit(groupBox);
        sentmessage_plaintextedit->setObjectName(QString::fromUtf8("sentmessage_plaintextedit"));
        sentmessage_plaintextedit->setContextMenuPolicy(Qt::NoContextMenu);
        sentmessage_plaintextedit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sentmessage_plaintextedit->setReadOnly(true);

        verticalLayout->addWidget(sentmessage_plaintextedit);

        groupBox_2 = new QGroupBox(TerminalMessageDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 190, 276, 71));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        editmessage_plaintextedit = new QPlainTextEdit(groupBox_2);
        editmessage_plaintextedit->setObjectName(QString::fromUtf8("editmessage_plaintextedit"));
        editmessage_plaintextedit->setContextMenuPolicy(Qt::NoContextMenu);
        editmessage_plaintextedit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editmessage_plaintextedit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editmessage_plaintextedit->setMaximumBlockCount(40);

        verticalLayout_2->addWidget(editmessage_plaintextedit);

        sent_pushbutton = new QPushButton(TerminalMessageDialog);
        sent_pushbutton->setObjectName(QString::fromUtf8("sent_pushbutton"));
        sent_pushbutton->setGeometry(QRect(413, 270, 51, 25));

        retranslateUi(TerminalMessageDialog);

        QMetaObject::connectSlotsByName(TerminalMessageDialog);
    } // setupUi

    void retranslateUi(QDialog *TerminalMessageDialog)
    {
        TerminalMessageDialog->setWindowTitle(QApplication::translate("TerminalMessageDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        targetmonitor_groupbox->setTitle(QApplication::translate("TerminalMessageDialog", "\347\233\256\346\240\207\347\233\221\350\247\206\346\234\272", 0, QApplication::UnicodeUTF8));
        addmonitor_toolbutton->setText(QApplication::translate("TerminalMessageDialog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        removemonitor_toolbutton->setText(QApplication::translate("TerminalMessageDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TerminalMessageDialog", "\345\267\262\345\217\221\351\200\201\346\266\210\346\201\257", 0, QApplication::UnicodeUTF8));
        sentmessage_plaintextedit->setPlainText(QString());
        groupBox_2->setTitle(QApplication::translate("TerminalMessageDialog", "\346\266\210\346\201\257\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        editmessage_plaintextedit->setPlainText(QString());
        sent_pushbutton->setText(QApplication::translate("TerminalMessageDialog", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TerminalMessageDialog: public Ui_TerminalMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINALMESSAGEDIALOG_H
