//类似于首页的多文本框
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QTimer>
#include <typeinfo>
#include <QMessageBox>
#include <QPushButton>
#include <QToolButton>
#include <QLayout>
#include "tabwidget.h"
#include "roomtreewidget.h"
#include "homepage.h"
#include "roomstatesearchdialog.h"
#include "struct.h"

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    tabheight = tabBar()->height();
    this->setStyleSheet("QTabBar::tab {"
                        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                    "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,"
                                                    "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
                        "border: 2px solid #C4C4C3;"
                        "border-bottom-color: #C2C7CB;"
                        "border-top-left-radius: 4px;"
                        "border-top-right-radius: 4px;"
                        "min-width: 8ex;"
                        "padding: 2px;"
                        "}"
                         "QTabBar::tab:selected, QTabBar::tab:hover {\
                             background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                                                         stop: 0 #fafafa, stop: 0.4 #f4f4f4,\
                                                         stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\
                         }\
                         QTabBar::tab:selected {\
                             border-color: #9B9B9B;\
                             border-bottom-color: #C2C7CB; \
                         }\
                         QTabBar::tab:!selected {\
                             margin-top: 2px; \
                         }\
                     //    QTabWidget::pane{border-top: 20px solid green;}\
                         "
                          );

}

void TabWidget::resizeEvent(QResizeEvent *event)
{
    QTabWidget::resizeEvent(event);
}

void TabWidget::showHomePage()
{
    this->setCurrentIndex(0);
}

void TabWidget::closeCurrentPage(){
    QWidget *w = qobject_cast<QWidget *>(sender());
    qDebug()<< w->objectName();
    this->removeTab(this->currentIndex());
    delete w;
}

