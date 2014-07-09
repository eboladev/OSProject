/********************************************************************************
** Form generated from reading UI file 'viewsavedialog.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWSAVEDIALOG_H
#define UI_VIEWSAVEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewSaveDialog
{
public:
    QGroupBox *exsitname_groupbox;
    QVBoxLayout *verticalLayout;
    QListWidget *filename_listwidget;
    QGroupBox *filename_groupbox;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *filename_lineedit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *confirm_pushbutton;
    QPushButton *cancel_pushbutton;

    void setupUi(QDialog *ViewSaveDialog)
    {
        if (ViewSaveDialog->objectName().isEmpty())
            ViewSaveDialog->setObjectName(QString::fromUtf8("ViewSaveDialog"));
        ViewSaveDialog->resize(280, 270);
        exsitname_groupbox = new QGroupBox(ViewSaveDialog);
        exsitname_groupbox->setObjectName(QString::fromUtf8("exsitname_groupbox"));
        exsitname_groupbox->setGeometry(QRect(10, 10, 191, 181));
        verticalLayout = new QVBoxLayout(exsitname_groupbox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        filename_listwidget = new QListWidget(exsitname_groupbox);
        filename_listwidget->setObjectName(QString::fromUtf8("filename_listwidget"));

        verticalLayout->addWidget(filename_listwidget);

        filename_groupbox = new QGroupBox(ViewSaveDialog);
        filename_groupbox->setObjectName(QString::fromUtf8("filename_groupbox"));
        filename_groupbox->setGeometry(QRect(10, 200, 191, 51));
        verticalLayout_2 = new QVBoxLayout(filename_groupbox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        filename_lineedit = new QLineEdit(filename_groupbox);
        filename_lineedit->setObjectName(QString::fromUtf8("filename_lineedit"));

        verticalLayout_2->addWidget(filename_lineedit);

        layoutWidget = new QWidget(ViewSaveDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 200, 51, 54));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        confirm_pushbutton = new QPushButton(layoutWidget);
        confirm_pushbutton->setObjectName(QString::fromUtf8("confirm_pushbutton"));
        confirm_pushbutton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(confirm_pushbutton);

        cancel_pushbutton = new QPushButton(layoutWidget);
        cancel_pushbutton->setObjectName(QString::fromUtf8("cancel_pushbutton"));
        cancel_pushbutton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(cancel_pushbutton);


        retranslateUi(ViewSaveDialog);

        QMetaObject::connectSlotsByName(ViewSaveDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewSaveDialog)
    {
        ViewSaveDialog->setWindowTitle(QApplication::translate("ViewSaveDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        exsitname_groupbox->setTitle(QApplication::translate("ViewSaveDialog", "\345\267\262\345\255\230\345\234\250\347\232\204\345\217\257\350\203\275\351\207\215\345\220\215\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        filename_groupbox->setTitle(QApplication::translate("ViewSaveDialog", "\344\277\235\345\255\230\344\270\272(.view)", 0, QApplication::UnicodeUTF8));
        confirm_pushbutton->setText(QApplication::translate("ViewSaveDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancel_pushbutton->setText(QApplication::translate("ViewSaveDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewSaveDialog: public Ui_ViewSaveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWSAVEDIALOG_H
