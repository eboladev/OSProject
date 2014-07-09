/********************************************************************************
** Form generated from reading UI file 'sendviewfiles.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDVIEWFILES_H
#define UI_SENDVIEWFILES_H

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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SendViewFiles
{
public:
    QGroupBox *sentview_groupbox;
    QVBoxLayout *verticalLayout;
    QListWidget *sentview_listwidget;
    QGroupBox *targetmonitor_groupbox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *targetmonitor_combobox;
    QListWidget *selectedmonitor_listwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *addmonitor_toolbutton;
    QToolButton *removemonitor_toolbutton;
    QGroupBox *sendprogress_groupbox;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *sentview_progressbar;
    QPushButton *sent_pushbutton;
    QPushButton *exit_pushbutton;

    void setupUi(QDialog *SendViewFiles)
    {
        if (SendViewFiles->objectName().isEmpty())
            SendViewFiles->setObjectName(QString::fromUtf8("SendViewFiles"));
        SendViewFiles->resize(409, 343);
        sentview_groupbox = new QGroupBox(SendViewFiles);
        sentview_groupbox->setObjectName(QString::fromUtf8("sentview_groupbox"));
        sentview_groupbox->setGeometry(QRect(220, 20, 170, 210));
        verticalLayout = new QVBoxLayout(sentview_groupbox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sentview_listwidget = new QListWidget(sentview_groupbox);
        sentview_listwidget->setObjectName(QString::fromUtf8("sentview_listwidget"));

        verticalLayout->addWidget(sentview_listwidget);

        targetmonitor_groupbox = new QGroupBox(SendViewFiles);
        targetmonitor_groupbox->setObjectName(QString::fromUtf8("targetmonitor_groupbox"));
        targetmonitor_groupbox->setGeometry(QRect(20, 20, 170, 210));
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

        sendprogress_groupbox = new QGroupBox(SendViewFiles);
        sendprogress_groupbox->setObjectName(QString::fromUtf8("sendprogress_groupbox"));
        sendprogress_groupbox->setGeometry(QRect(20, 240, 371, 52));
        verticalLayout_2 = new QVBoxLayout(sendprogress_groupbox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sentview_progressbar = new QProgressBar(sendprogress_groupbox);
        sentview_progressbar->setObjectName(QString::fromUtf8("sentview_progressbar"));
        sentview_progressbar->setValue(0);
        sentview_progressbar->setAlignment(Qt::AlignCenter);
        sentview_progressbar->setTextVisible(true);
        sentview_progressbar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(sentview_progressbar);

        sent_pushbutton = new QPushButton(SendViewFiles);
        sent_pushbutton->setObjectName(QString::fromUtf8("sent_pushbutton"));
        sent_pushbutton->setGeometry(QRect(250, 300, 61, 25));
        exit_pushbutton = new QPushButton(SendViewFiles);
        exit_pushbutton->setObjectName(QString::fromUtf8("exit_pushbutton"));
        exit_pushbutton->setGeometry(QRect(320, 300, 61, 25));

        retranslateUi(SendViewFiles);

        QMetaObject::connectSlotsByName(SendViewFiles);
    } // setupUi

    void retranslateUi(QDialog *SendViewFiles)
    {
        SendViewFiles->setWindowTitle(QApplication::translate("SendViewFiles", "Dialog", 0, QApplication::UnicodeUTF8));
        sentview_groupbox->setTitle(QApplication::translate("SendViewFiles", "\345\217\221\351\200\201\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        targetmonitor_groupbox->setTitle(QApplication::translate("SendViewFiles", "\347\233\256\346\240\207\347\233\221\350\247\206\346\234\272", 0, QApplication::UnicodeUTF8));
        addmonitor_toolbutton->setText(QApplication::translate("SendViewFiles", "+", 0, QApplication::UnicodeUTF8));
        removemonitor_toolbutton->setText(QApplication::translate("SendViewFiles", "-", 0, QApplication::UnicodeUTF8));
        sendprogress_groupbox->setTitle(QApplication::translate("SendViewFiles", "\345\217\221\351\200\201\350\277\233\345\272\246", 0, QApplication::UnicodeUTF8));
        sent_pushbutton->setText(QApplication::translate("SendViewFiles", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        exit_pushbutton->setText(QApplication::translate("SendViewFiles", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SendViewFiles: public Ui_SendViewFiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDVIEWFILES_H
