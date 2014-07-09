//大窗口
#include <QToolBar>
#include <QLayout>
#include <QCloseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QSplashScreen>
#include <QTimer>
#include "hook.h"
#include "tabwidget.h"
#include "fullscreenmainwindow.h"
#include "mainwindow.h"
FullScreenMainWindow::FullScreenMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //setHook();
    QPixmap pixmap("images/start.jpg");
    this->setVisible(false);
    this->resize(10,10);
    splash = new QSplashScreen(pixmap);
    splash->setDisabled(true);
    splash->setGeometry(QApplication::desktop()->width()/4,QApplication::desktop()->height()/4,QApplication::desktop()->width()/2,QApplication::desktop()->height()/2);
    splash->show();
    QFont font = splash->font();
    font.setFamily("华文中宋");
    font.setPointSize(20);
    font.setItalic(true);
    splash->setFont(font);
    splash->showMessage("程序加载中...",Qt::AlignHCenter|Qt::AlignBottom,Qt::blue);
    this->setVisible(false);
    centralmainwindow = new MainWindow;
    connect(centralmainwindow,SIGNAL(closeapp()),this,SLOT(close()));
    this->setContextMenuPolicy(Qt::NoContextMenu);
    toolbar = new QToolBar(this);
    toolbar->setMovable(false);
    toolbar->setFixedHeight(70);
    toolbar->setStyleSheet("QToolBar{border-image:url(images/yanglaoyuan.png);}");
    this->setWindowIcon(QIcon("images/systemicon.png"));
    this->setWindowTitle("养老院运营与服务系统");
    this->addToolBar(toolbar);
    this->setCentralWidget(centralmainwindow);
    timer = new QTimer(this);
    timer->singleShot(2000,this,SLOT(otherOperation()));
}

void FullScreenMainWindow::otherOperation()
{

    this->showMaximized();
    //this->showFullScreen();
    splash->finish(this);
    delete splash;
}



