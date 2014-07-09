/********************************************************************************
** Form generated from reading UI file 'sensordistribution.ui'
**
** Created: Fri Feb 28 20:02:47 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORDISTRIBUTION_H
#define UI_SENSORDISTRIBUTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_SensorDistribution
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *SensorDistribution)
    {
        if (SensorDistribution->objectName().isEmpty())
            SensorDistribution->setObjectName(QString::fromUtf8("SensorDistribution"));
        SensorDistribution->resize(390, 264);
        horizontalLayout = new QHBoxLayout(SensorDistribution);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(SensorDistribution);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);


        retranslateUi(SensorDistribution);

        QMetaObject::connectSlotsByName(SensorDistribution);
    } // setupUi

    void retranslateUi(QDialog *SensorDistribution)
    {
        SensorDistribution->setWindowTitle(QApplication::translate("SensorDistribution", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SensorDistribution: public Ui_SensorDistribution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORDISTRIBUTION_H
