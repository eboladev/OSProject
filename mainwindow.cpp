//小窗口
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <QtGui/QStandardItemModel>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QListView>
#include <QtGui/QDockWidget>
#include <QtGui/QMenu>
#include <QtGui/QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QtGui/QAction>
#include <QSettings>
#include <QMdiArea>
#include <QWidgetAction>
#include <QTableWidget>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include <QSqlQuery>

#include "roomtreewidget.h"
#include "mainwindow.h"
#include "plotter.h"
#include "tabwidget.h"
#include "homepage.h"

#include "widget.h"//有待商
#include "struct.h"
#include "datewidget.h"
#include "accidentrecord.h"
#include "visitrecord.h"
#include "elderbaseinfo.h"
#include "healthassess.h"
#include "dictionarydialog.h"
#include "employeebaseinfo.h"
#include "employeevacation.h"
#include "checkin.h"
#include "storage.h"
#include "checkout.h"
#include "basecostdialog.h"
#include "stagecostdialog.h"
#include "resideregister.h"
#include "nurserecord.h"
#include "advicerecord.h"
#include "specialservice.h"
#include "eldervacation.h"
#include "elderbirthday.h"
#include "nursechange.h"
#include "accountpay.h"
#include "monthlysettle.h"
#include "recedesettle.h"
#include "accountdetail.h"
#include "roledialog.h"
#include "operatordialog.h"
#include "previlege.h"
#include "operationlog.h"
#include "passworddialog.h"
#include "monthlyresidestatistics.h"

#include "alarmdealwithconfirmdialog.h"
#include "operationlogdialog.h"
#include "refreshanalogattriobject.h"
#include "setsystemtimedialog.h"
#include "dragdropwidget.h"

Mat mat[MAXROOMNUM];
QMap<QString,int> roomnameToIds;
QStringList floornames;
int totalroomcount;
int curmaxroomid;
RefreshAnalogAttriObject * raao;
extern QList<QString> menuList;
extern QList<QString> barList;
/////
SendMessageThread * smt;
bool hassursys;
QString sursysip;

void insertLog(QString operation)
{
    if(globaldb.open())//是否需要判断
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery loginsertquery(globaldb);
        loginsertquery.prepare("INSERT INTO operation_log  VALUES(NULL,?,?,?)");
        loginsertquery.addBindValue(operation);
        loginsertquery.addBindValue(operatorId);        
        loginsertquery.addBindValue(QDateTime::currentDateTime());
        loginsertquery.exec();
        loginsertquery.clear();
        loginsertquery.finish();
        //globaldb.close();
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！alarmdockdb","确定");
        }
        qDebug()<<"insertLog 数据库连接失败！";
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //登陆  
    floornames<<"一楼"<<"二楼"<<"三楼"<<"四楼"<<"五楼"<<"六楼"<<"七楼"<<"八楼"<<"九楼"<<"十楼";

    createRefreshAnalogObject();
    loadSurSysInfo();
    initRoomData();
    createRoomNameToId();
    smt = new SendMessageThread;
    createMainWindow();
    smt->start();
//    homepage->onRefreshTimer();
    this->setStyleSheet("QMainWindow::separator {background: yellow;width: 0px;height: 0px; }");
}

void MainWindow::loadSurSysInfo()
{
    hassursys = false;
    sursysip = "";
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        query.prepare("SELECT arg_value FROM com_arg WHERE arg_name = ?");
        query.addBindValue("has_sur_sys");
        query.exec();
        query.next();
        hassursys = query.value(0).toInt();

        query.prepare("SELECT arg_value FROM com_arg WHERE arg_name = ?");
        query.addBindValue("sur_sys_ip");
        query.exec();
        query.next();
        sursysip = query.value(0).toString();

        query.clear();
        query.finish();
        qDebug()<<"hassursys"<<hassursys<<"sursysip"<<sursysip;
    }
    else
    {

        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
        }

    }
}
void MainWindow::initRoomData()
{
    for(int i = 0; i < MAXROOMNUM; i++)
    {
        mat[i].bitmap = 0;
    }
}

void MainWindow::createRoomNameToId()
{
    qDebug()<<"createRoomNameToId";
    totalroomcount = 0;
    curmaxroomid = 0;
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        query.prepare("SELECT building_no,floor_no,room_name,device_id FROM device_info");//会不会出现房间名相同？
        query.exec();
        int i = 0;
        qDebug()<<"createRoomNameToId";
        while(query.next())
        {
            roomnameToIds[query.value(0).toString()+":"+floornames.at(query.value(1).toInt() - 1)+":"+query.value(2).toString()] = query.value(3).toInt();
            qDebug()<<query.value(3).toInt()<<query.value(0).toString()+":"+floornames.at(query.value(1).toInt() - 1)+":"+query.value(2).toString();
            i++;
            totalroomcount++;
            curmaxroomid++;
        }
        //globaldb.close();
    }
    else
    {
        qDebug()<<"createRoomNameToId 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！alarmdockdb5","确定");
        }
    }
    for(int t = 0; t < totalroomcount;t++ )
    {
        qDebug()<<roomnameToIds.key(t);
    }
}



void MainWindow::createRefreshAnalogObject()
{
    raao = new RefreshAnalogAttriObject(this);
}

void MainWindow::createMainWindow()
{
    createDockWidget();
    createDragDropDockWidget();
    createCentralWidget();
    createMenu();
    createToolBar();


    /*QLabel * projectname = new QLabel(tr("居养保障"));
    projectname->setAlignment(Qt::AlignHCenter);
    QTime t;
    QLabel * systemtime = new QLabel(tr(t.currentTime().toString().toUtf8()));
    systemtime->setAlignment(Qt::AlignRight);
    this->statusBar()->addWidget(projectname);
    this->statusBar()->addWidget(systemtime);*/
    //this->showMaximized();
    createStatusBar();

//    qDebug()<<"toolbar"<<this->toolbar->height();
//    qDebug()<<central_tablewidget->tabheight;
//    int tempheight = this->toolbar->height() + central_tablewidget->tabheight;
//    QPoint tempoint = central_tablewidget->widget(0)->mapToGlobal(central_tablewidget->widget(0)->pos());
//    centralGem =QRect(tempoint.x(),tempoint.y()+tempheight,central_tablewidget->widget(0)->width(),central_tablewidget->widget(0)->height()-tempheight);


//    qDebug()<<"centralGem"<<centralGem;

    //Qt::FramelessWindowHint

    //central_tablewidget->showFullScreen();//全屏幕
    //setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    //this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);

    // this->showFullScreen();
    //this->setWindowFlags(this->windowFlags()& ~(Qt::WindowMinMaxButtonsHint|Qt::WindowSystemMenuHint|Qt::WindowCloseButtonHint)|Qt::CustomizeWindowHint);//最大无关闭按钮等


    //centralGem =QRect(central_tablewidget->mapToGlobal(central_tablewidget->pos()).x(),central_tablewidget->mapToGlobal(central_tablewidget->pos()).y(),central_tablewidget->width(),central_tablewidget->height());
    // centralGem =QRect(homepage->mapToGlobal(homepage->pos()).x(),homepage->mapToGlobal(homepage->pos()).y(),homepage->width(),homepage->height());

}

void MainWindow::createDockWidget()
{
    this->setCorner(Qt::BottomLeftCorner,Qt::LeftDockWidgetArea);
    rvc_dockwidget = new QDockWidget(tr("管理窗口"),this);
    rvc_dockwidget->setFeatures(QDockWidget::NoDockWidgetFeatures);

    rvc_dockwidget->setStyleSheet("QDockWidget#rvc_dockwidget{border: 0px solid red;}\
                                  QDockWidget::title {text-align: left;background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop: 0 #ffaa55,stop: 0.025 #ffaa55,stop: 1 white);padding-left: 5px;}\
");
rvc_dockwidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

rvc_dockwidget->setFixedWidth(260);
rvc_dockwidget->setMinimumHeight(300);
dock_tablewidget = new QTabWidget(rvc_dockwidget);
dock_tablewidget->setTabPosition(QTabWidget::North);
// dock_tablewidget->setStyleSheet("QTabWidget{border: 10px solid red;} QTabWidget::pane{border-top: 20px solid green;border-right: 20px solid green;}");记得改回来


createRoom();

// createAlarmWidget();//记得改回来
QWidget * wid = new QWidget(rvc_dockwidget);
wid->setObjectName("wid");
// wid->setStyleSheet("#wid{background:#F0FFFF;border: 10px solid red;}");记得改回来
QVBoxLayout * vbl = new QVBoxLayout;
vbl->setMargin(0);
vbl->setSpacing(0);
// dock_tablewidget->setSizePolicy();
vbl->addWidget(dock_tablewidget);
// vbl->addWidget(alarmwidget);
wid->setLayout(vbl);
rvc_dockwidget->setWidget(wid);
//this->addDockWidget(Qt::LeftDockWidgetArea,rvc_dockwidget);
this->addDockWidget(Qt::LeftDockWidgetArea,rvc_dockwidget);
}

void MainWindow::createDragDropDockWidget(){
    dragdrop_dockwidget = new DragDropWidget(tr("拖拽窗口"),this);
    dragdrop_dockwidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dragdrop_dockwidget->setStyleSheet("QDockWidget#dragdrop_dockwidget{border: 0px solid red;}\
                                  QDockWidget::title {text-align: left;background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop: 0 #ffaa55,stop: 0.025 #ffaa55,stop: 1 white);padding-left: 5px;}\
");
    this->addDockWidget(Qt::LeftDockWidgetArea,dragdrop_dockwidget);
}

void MainWindow::createRoom()
{
    room_widget = new QWidget(dock_tablewidget);
    room_widget->setObjectName("room_widget");
    room_widget->setStyleSheet("#room_widget{background:#F0FFFF}");
    dock_tablewidget->addTab(room_widget,tr("房间管理"));
    room_treewidget = new RoomTreeWidget(room_widget);
    findroom_verticalLayout = new QVBoxLayout(room_widget);
    findroom_verticalLayout->setSpacing(2);
    findroom_verticalLayout->setMargin(0);
    findroom_verticalLayout->addWidget(room_treewidget);
    room_widget->setLayout(findroom_verticalLayout);
}
void MainWindow::createAlarmWidget()
{

}

void MainWindow::createMessageDock()
{
    message_dockwidget = new QDockWidget(tr("公共信息"),this);
    message_dockwidget->setFeatures(message_dockwidget->features()&~QDockWidget::DockWidgetClosable);
    QLabel * msg = new QLabel(message_dockwidget);
    msg->setText(tr("Qt 是一个已经形成事实上的标准的C++ 框架，它被用于高性能的跨平台软件开发"));
    message_dockwidget->setWidget(msg);
    this->addDockWidget(Qt::BottomDockWidgetArea,message_dockwidget);

}

void MainWindow::createAlarmSearchDock()
{
    alarmsearch_dockwidget = new QDockWidget(tr("快速查询"),this);
    //   alarmsearch_dockwidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    alarmsearch_dockwidget->setAllowedAreas(Qt::RightDockWidgetArea|Qt::BottomDockWidgetArea);
    //alarmsearch_dockwidget->setFixedWidth(100);
    this->setCorner(Qt::BottomLeftCorner,Qt::BottomDockWidgetArea);
    this->addDockWidget(Qt::BottomDockWidgetArea,alarmsearch_dockwidget);
}

/*void MainWindow::createSidePushButtton()
{
    hidedockwidget_pushbutton = new SidePushButton(this);
    hidedockwidget_pushbutton->setContentsMargins(0,0,0,0);
    //hidedockwidget_pushbutton->setFlat(true);

    QFont font = hidedockwidget_pushbutton->font();
    font.setPointSize(10);
    font.setBold(true);
    hidedockwidget_pushbutton->setFont(font);
    //qDebug()<<"haha"<<mainui.centralwidget->height();
    hidedockwidget_pushbutton->setFixedWidth(5);
   // hidedockwidget_pushbutton->setFixedHeight(mainui.mainwidget->height());
   // hidedockwidget_pushbutton->setFocusPolicy(Qt::NoFocus);
   // hidedockwidget_pushbutton->resize(QSize(10,1000));
    hidedockwidget_pushbutton->setStyleSheet("QPushButton{border:0pxgroovegray;}");//设置透明
    hidedockwidget_pushbutton->setFocusPolicy(Qt::NoFocus);
}*/



void MainWindow::createCentralWidget()
{
    central_widget = new QWidget(this);
    centralwidget_hboxlayout = new QHBoxLayout(central_widget);
    centralwidget_hboxlayout->setMargin(0);
    central_tablewidget = new TabWidget(central_widget);

    homepage = new HomePage(central_tablewidget);     
//     accidentRecordPage = new AccidentRecord(central_tablewidget);
    central_tablewidget->addTab(homepage,tr("首页"));
//    central_tablewidget->setTabsClosable(true);

    //centralwidget_hboxlayout->addWidget(hidedockwidget_pushbutton);
    centralwidget_hboxlayout->addWidget(central_tablewidget);

    //this->setCentralWidget(centralwidget_hboxlayout);
    central_widget->setLayout(centralwidget_hboxlayout);
    this->setCentralWidget(central_widget);
    central_widget->setAutoFillBackground(true);
    central_widget->setObjectName("central_widget");
    central_widget->setStyleSheet("QWidget#central_widget{background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop: 0 #ffaa55,stop: 0.025 white,stop: 1 green);}");


    connect(room_treewidget,SIGNAL(expandbuilding(int)),homepage,SLOT(expandingBuilding(int)));
    connect(room_treewidget,SIGNAL(scrolltofloor(int,int)),homepage,SLOT(scrollToFloor(int,int)));
    connect(room_treewidget,SIGNAL(addBuilding(QString)),homepage,SLOT(addBuilding(QString)));
    connect(room_treewidget,SIGNAL(delBuilding(int)),homepage,SLOT(delBuilding(int)));
    connect(room_treewidget,SIGNAL(addFloor(int,int,int)),homepage,SLOT(addFloor(int,int,int)));
    connect(room_treewidget,SIGNAL(delFloor(int,int)),homepage,SLOT(delFloor(int,int)));
    connect(room_treewidget,SIGNAL(addRoom(int,int,QString)),homepage,SLOT(addRoom(int,int,QString)));
    connect(room_treewidget,SIGNAL(delRoom(int,int,QString)),homepage,SLOT(delRoom(int,int,QString)));

    connect(room_treewidget,SIGNAL(showHomepage()),central_tablewidget,SLOT(showHomePage()));
    connect(central_tablewidget,SIGNAL(currentChanged(int)),this,SLOT(hideDragDropWidget()));

    connect(smt,SIGNAL(delRoom(bool)),room_treewidget,SLOT(deleteRoomCanbe(bool)));
//    connect(visitRecord,SIGNAL(closeVisitRecord()),central_tablewidget,SLOT(closeCurrentPage()));
}


void MainWindow::createMenu()
{
    buttoniconsize = QSize(35,35);
    menubar = this->menuBar();
    //visit
//    visit_menu = new QMenu(tr("来访登记管理"),menubar);
    //reside
    reside_menu = new QMenu(tr("入住管理"),menubar);    
    elder_info_widgetaction = new QWidgetAction(reside_menu);
    ToolButton * elder_toolbutton = new ToolButton(reside_menu);
    elder_toolbutton->setObjectName("elder_info_toolbutton");
    elder_toolbutton->setText(tr(""));
    elder_toolbutton->setStyleSheet("QToolButton#elder_info_toolbutton:hover,QToolButton#elder_info_toolbutton:open{"
                                     "border-image:url(images/elder_info_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#elder_info_toolbutton:!hover:!open{"
                                     "border-image:url(images/elder_info_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    //sensor_toolbutton->setStyleSheet("QToolButton#sensor_toolbutton{background-image:url(images/configure_toolbutton_used.png);}");   
    //sensor_toolbutton->setIcon(QIcon(QPixmap("images/ip_widgetaction.png").scaled(QSize(35,35))));
//    connect(elder_toolbutton,SIGNAL(clicked()),this,SLOT(onElderBaseInfoPage()));
    connect(elder_toolbutton,SIGNAL(clicked()),this,SLOT(onElderBaseInfoPage()));
    elder_info_widgetaction->setDefaultWidget(elder_toolbutton);
    if(!menuList.contains(tr("elder_info_toolbutton")))
        elder_info_widgetaction->setVisible(false);

    health_assess__widgetaction = new QWidgetAction(reside_menu);
    ToolButton *health_assess__toolbutton = new ToolButton(reside_menu);
    health_assess__toolbutton->setObjectName("health_assess__toolbutton");
    health_assess__toolbutton->setText(tr(""));
    health_assess__toolbutton->setStyleSheet("QToolButton#health_assess__toolbutton:hover,QToolButton#health_assess__toolbutton:open{"
                                     "border-image:url(images/health_assess__toolbutton_used.png);"
                                     "}"
                                     "QToolButton#health_assess__toolbutton:!hover:!open{"
                                     "border-image:url(images/health_assess__toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(health_assess__toolbutton,SIGNAL(clicked()),this,SLOT(onHealthAssessPage()));
    health_assess__widgetaction->setDefaultWidget(health_assess__toolbutton);
    if(!menuList.contains(tr("health_assess__toolbutton")))
        health_assess__widgetaction->setVisible(false);

    reside_widgetaction = new QWidgetAction(reside_menu);
    ToolButton * reside_toolbutton = new ToolButton(reside_menu);
    reside_toolbutton->setObjectName("living_toolbutton");
    connect(reside_toolbutton,SIGNAL(clicked()),this,SLOT(onResideRegisterPage()));
    reside_toolbutton->setText(tr(""));
    reside_toolbutton->setStyleSheet("QToolButton#living_toolbutton:hover,QToolButton#living_toolbutton:open{"
                                     "border-image:url(images/living_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#living_toolbutton:!hover:!open{"
                                     "border-image:url(images/living_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    reside_widgetaction->setDefaultWidget(reside_toolbutton);
    if(!menuList.contains(tr("living_toolbutton")))
        reside_widgetaction->setVisible(false);

    reside_menu->addAction(elder_info_widgetaction);
    reside_menu->addAction(health_assess__widgetaction);
    reside_menu->addAction(reside_widgetaction);

    //elder
    elder_menu = new QMenu(tr("老人管理"),menubar);
    nurse_record_widgetaction = new QWidgetAction(elder_menu);
    ToolButton *nurse_record_toolbutton = new ToolButton(elder_menu);
    nurse_record_toolbutton->setObjectName("nurse_record_toolbutton");
    nurse_record_toolbutton->setText(tr(""));
    nurse_record_toolbutton->setStyleSheet("QToolButton#nurse_record_toolbutton:hover,QToolButton#nurse_record_toolbutton:open{"
                                     "border-image:url(images/nurse_record_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#nurse_record_toolbutton:!hover:!open{"
                                     "border-image:url(images/nurse_record_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(nurse_record_toolbutton,SIGNAL(clicked()),this,SLOT(onNurseRecordPage()));
    nurse_record_widgetaction->setDefaultWidget(nurse_record_toolbutton);
    if(!menuList.contains(tr("nurse_record_toolbutton")))
        nurse_record_widgetaction->setVisible(false);

    advice_record_widgetaction = new QWidgetAction(elder_menu);
    ToolButton *advice_record_toolbutton = new ToolButton(elder_menu);
    advice_record_toolbutton->setObjectName("advice_record_toolbutton");
    advice_record_toolbutton->setText(tr(""));
    advice_record_toolbutton->setStyleSheet("QToolButton#advice_record_toolbutton:hover,QToolButton#advice_record_toolbutton:open{"
                                     "border-image:url(images/advice_record_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#advice_record_toolbutton:!hover:!open{"
                                     "border-image:url(images/advice_record_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(advice_record_toolbutton,SIGNAL(clicked()),this,SLOT(onAdviceRecordPage()));
    advice_record_widgetaction->setDefaultWidget(advice_record_toolbutton);
    if(!menuList.contains(tr("advice_record_toolbutton")))
        advice_record_widgetaction->setVisible(false);

    special_service_widgetaction = new QWidgetAction(elder_menu);
    ToolButton *special_service_toolbutton = new ToolButton(elder_menu);
    special_service_toolbutton->setObjectName("special_service_toolbutton");
    special_service_toolbutton->setText(tr(""));
    special_service_toolbutton->setStyleSheet("QToolButton#special_service_toolbutton:hover,QToolButton#special_service_toolbutton:open{"
                                     "border-image:url(images/special_service_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#special_service_toolbutton:!hover:!open{"
                                     "border-image:url(images/special_service_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(special_service_toolbutton,SIGNAL(clicked()),this,SLOT(onSpecialServicePage()));
    special_service_widgetaction->setDefaultWidget(special_service_toolbutton);
    if(!menuList.contains(tr("special_service_toolbutton")))
        special_service_widgetaction->setVisible(false);

    accident_record_widgetaction = new QWidgetAction(elder_menu);
    ToolButton *accident_record_toolbutton = new ToolButton(elder_menu);
    accident_record_toolbutton->setObjectName("accident_record_toolbutton");
    accident_record_toolbutton->setText(tr(""));
    accident_record_toolbutton->setStyleSheet("QToolButton#accident_record_toolbutton:hover,QToolButton#accident_record_toolbutton:open{"
                                     "border-image:url(images/accident_record_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#accident_record_toolbutton:!hover:!open{"
                                     "border-image:url(images/accident_record_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(accident_record_toolbutton,SIGNAL(clicked()),this,SLOT(onAccidentRecordPage()));
    accident_record_widgetaction->setDefaultWidget(accident_record_toolbutton);
    if(!menuList.contains(tr("accident_record_toolbutton")))
        accident_record_widgetaction->setVisible(false);

    elder_vacation_widgetaction = new QWidgetAction(elder_menu);
    ToolButton *elder_vacation_toolbutton = new ToolButton(elder_menu);
    elder_vacation_toolbutton->setObjectName("elder_vacation_toolbutton");
    elder_vacation_toolbutton->setText(tr(""));
    elder_vacation_toolbutton->setStyleSheet("QToolButton#elder_vacation_toolbutton:hover,QToolButton#elder_vacation_toolbutton:open{"
                                     "border-image:url(images/elder_vacation_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#elder_vacation_toolbutton:!hover:!open{"
                                     "border-image:url(images/elder_vacation_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(elder_vacation_toolbutton,SIGNAL(clicked()),this,SLOT(onElderVacationPage()));
    elder_vacation_widgetaction->setDefaultWidget(elder_vacation_toolbutton);
    if(!menuList.contains(tr("elder_vacation_toolbutton")))
        elder_vacation_widgetaction->setVisible(false);

    elder_birthday_widgetaction = new QWidgetAction(elder_menu);
    ToolButton *elder_birthday_toolbutton = new ToolButton(elder_menu);
    elder_birthday_toolbutton->setObjectName("elder_birthday_toolbutton");
    elder_birthday_toolbutton->setText(tr(""));
    elder_birthday_toolbutton->setStyleSheet("QToolButton#elder_birthday_toolbutton:hover,QToolButton#elder_birthday_toolbutton:open{"
                                     "border-image:url(images/elder_birthday_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#elder_birthday_toolbutton:!hover:!open{"
                                     "border-image:url(images/elder_birthday_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(elder_birthday_toolbutton,SIGNAL(clicked()),this,SLOT(onElderBirthdayPage()));
    elder_birthday_widgetaction->setDefaultWidget(elder_birthday_toolbutton);
    if(!menuList.contains(tr("elder_birthday_toolbutton")))
        elder_birthday_widgetaction->setVisible(false);

    nurse_change_widgetaction = new QWidgetAction(elder_menu);
    ToolButton * nurse_change_toolbutton = new ToolButton(elder_menu);
    nurse_change_toolbutton->setObjectName("nurse_change_toolbutton");
    nurse_change_toolbutton->setText(tr(""));
    nurse_change_toolbutton->setStyleSheet("QToolButton#nurse_change_toolbutton:hover,QToolButton#nurse_change_toolbutton:open{"
                                     "border-image:url(images/nurse_change_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#nurse_change_toolbutton:!hover:!open{"
                                     "border-image:url(images/nurse_change_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(nurse_change_toolbutton,SIGNAL(clicked()),this,SLOT(onNurseChangePage()));
    nurse_change_widgetaction->setDefaultWidget(nurse_change_toolbutton);
    if(!menuList.contains(tr("nurse_change_toolbutton")))
        nurse_change_widgetaction->setVisible(false);

    elder_menu->addAction(advice_record_widgetaction);
    elder_menu->addAction(nurse_record_widgetaction);
    elder_menu->addAction(special_service_widgetaction);
    elder_menu->addAction(accident_record_widgetaction);
    elder_menu->addAction(elder_vacation_widgetaction);
    elder_menu->addAction(elder_birthday_widgetaction);
    elder_menu->addAction(nurse_change_widgetaction);

    //employee
    employee_menu = new QMenu(tr("员工管理"),menubar);

    employee_info_widgetaction = new QWidgetAction(employee_menu);
    ToolButton *employee_info_toolbutton = new ToolButton(employee_menu);
    employee_info_toolbutton->setObjectName("employee_info_toolbutton");
    employee_info_toolbutton->setText(tr(""));
    employee_info_toolbutton->setStyleSheet("QToolButton#employee_info_toolbutton:hover,QToolButton#employee_info_toolbutton:open{"
                                     "border-image:url(images/employee_info_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#employee_info_toolbutton:!hover:!open{"
                                     "border-image:url(images/employee_info_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(employee_info_toolbutton,SIGNAL(clicked()),this,SLOT(onEmployeeBaseInfoPage()));
    employee_info_widgetaction->setDefaultWidget(employee_info_toolbutton);
    if(!menuList.contains(tr("employee_info_toolbutton")))
        employee_info_widgetaction->setVisible(false);

    employee_vacation_widgetaction = new QWidgetAction(employee_menu);
    ToolButton *employee_vacation_toolbutton = new ToolButton(employee_menu);
    employee_vacation_toolbutton->setObjectName("employee_vacation_toolbutton");
    employee_vacation_toolbutton->setText(tr(""));
    employee_vacation_toolbutton->setStyleSheet("QToolButton#employee_vacation_toolbutton:hover,QToolButton#employee_vacation_toolbutton:open{"
                                     "border-image:url(images/employee_vacation_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#employee_vacation_toolbutton:!hover:!open{"
                                     "border-image:url(images/employee_vacation_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(employee_vacation_toolbutton,SIGNAL(clicked()),this,SLOT(onEmployeeVacationPage()));
    employee_vacation_widgetaction->setDefaultWidget(employee_vacation_toolbutton);
    if(!menuList.contains(tr("employee_vacation_toolbutton")))
        employee_vacation_widgetaction->setVisible(false);

    employee_menu->addAction(employee_info_widgetaction);
    employee_menu->addAction(employee_vacation_widgetaction);

    //warehouse
    warehouse_menu = new QMenu(tr(""),menubar);

    check_in_widgetaction = new QWidgetAction(warehouse_menu);
    ToolButton *check_in_toolbutton = new ToolButton(warehouse_menu);
    check_in_toolbutton->setObjectName("check_in_toolbutton");
    check_in_toolbutton->setText(tr(""));
    check_in_toolbutton->setStyleSheet("QToolButton#check_in_toolbutton:hover,QToolButton#check_in_toolbutton:open{"
                                     "border-image:url(images/check_in_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#check_in_toolbutton:!hover:!open{"
                                     "border-image:url(images/check_in_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(check_in_toolbutton,SIGNAL(clicked()),this,SLOT(onCheckInPage()));
    check_in_widgetaction->setDefaultWidget(check_in_toolbutton);
    if(!menuList.contains(tr("check_in_toolbutton")))
        check_in_widgetaction->setVisible(false);

    check_out_widgetaction = new QWidgetAction(warehouse_menu);
    ToolButton *check_out_toolbutton = new ToolButton(warehouse_menu);
    check_out_toolbutton->setObjectName("check_out_toolbutton");
    check_out_toolbutton->setText(tr(""));
    check_out_toolbutton->setStyleSheet("QToolButton#check_out_toolbutton:hover,QToolButton#check_out_toolbutton:open{"
                                     "border-image:url(images/check_out_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#check_out_toolbutton:!hover:!open{"
                                     "border-image:url(images/check_out_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(check_out_toolbutton,SIGNAL(clicked()),this,SLOT(onCheckOutPage()));
    check_out_widgetaction->setDefaultWidget(check_out_toolbutton);
    if(!menuList.contains(tr("check_out_toolbutton")))
        check_out_widgetaction->setVisible(false);

    storage_check_widgetaction = new QWidgetAction(warehouse_menu);
    ToolButton *storage_check_toolbutton = new ToolButton(warehouse_menu);
    storage_check_toolbutton->setObjectName("storage_check_toolbutton");
    storage_check_toolbutton->setText(tr(""));
    storage_check_toolbutton->setStyleSheet("QToolButton#storage_check_toolbutton:hover,QToolButton#storage_check_toolbutton:open{"
                                     "border-image:url(images/storage_check_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#storage_check_toolbutton:!hover:!open{"
                                     "border-image:url(images/storage_check_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(storage_check_toolbutton,SIGNAL(clicked()),this,SLOT(onStoragePage()));
    storage_check_widgetaction->setDefaultWidget(storage_check_toolbutton);
    if(!menuList.contains(tr("storage_check_toolbutton")))
        storage_check_widgetaction->setVisible(false);

    warehouse_menu->addAction(check_in_widgetaction);
    warehouse_menu->addAction(check_out_widgetaction);
    warehouse_menu->addAction(storage_check_widgetaction);

    //cost manage
    charge_menu = new QMenu(tr("收费管理"),menubar);

    account_pay_widgetaction = new QWidgetAction(charge_menu);
    ToolButton *account_pay_toolbutton = new ToolButton(charge_menu);
    account_pay_toolbutton->setObjectName("account_pay_toolbutton");
    account_pay_toolbutton->setText(tr(""));
    account_pay_toolbutton->setStyleSheet("QToolButton#account_pay_toolbutton:hover,QToolButton#account_pay_toolbutton:open{"
                                     "border-image:url(images/account_pay_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#account_pay_toolbutton:!hover:!open{"
                                     "border-image:url(images/account_pay_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(account_pay_toolbutton,SIGNAL(clicked()),this,SLOT(onAccountPayPage()));
    account_pay_widgetaction->setDefaultWidget(account_pay_toolbutton);
    if(!menuList.contains(tr("account_pay_toolbutton")))
        account_pay_widgetaction->setVisible(false);

    monthly_settle_widgetaction = new QWidgetAction(charge_menu);
    ToolButton *monthly_settle_toolbutton = new ToolButton(charge_menu);
    monthly_settle_toolbutton->setObjectName("monthly_settle_toolbutton");
    monthly_settle_toolbutton->setText(tr(""));
    monthly_settle_toolbutton->setStyleSheet("QToolButton#monthly_settle_toolbutton:hover,QToolButton#monthly_settle_toolbutton:open{"
                                     "border-image:url(images/monthly_settle_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#monthly_settle_toolbutton:!hover:!open{"
                                     "border-image:url(images/monthly_settle_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(monthly_settle_toolbutton,SIGNAL(clicked()),this,SLOT(onMonthlySettlePage()));
    monthly_settle_widgetaction->setDefaultWidget(monthly_settle_toolbutton);
    if(!menuList.contains(tr("monthly_settle_toolbutton")))
        monthly_settle_widgetaction->setVisible(false);

//    settle_check_widgetaction = new QWidgetAction(charge_menu);
//    ToolButton *settle_check_toolbutton = new ToolButton(charge_menu);
//    settle_check_toolbutton->setObjectName("settle_check_toolbutton");
//    settle_check_toolbutton->setText(tr("结算查询"));
//    settle_check_widgetaction->setDefaultWidget(settle_check_toolbutton);

    recede_settle_widgetaction = new QWidgetAction(charge_menu);
    ToolButton *recede_settle_toolbutton = new ToolButton(charge_menu);
    recede_settle_toolbutton->setObjectName("recede_settle_toolbutton");
    recede_settle_toolbutton->setText(tr(""));
    recede_settle_toolbutton->setStyleSheet("QToolButton#recede_settle_toolbutton:hover,QToolButton#recede_settle_toolbutton:open{"
                                     "border-image:url(images/recede_settle_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#recede_settle_toolbutton:!hover:!open{"
                                     "border-image:url(images/recede_settle_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(recede_settle_toolbutton,SIGNAL(clicked()),this,SLOT(onRecedeSettlePage()));
    recede_settle_widgetaction->setDefaultWidget(recede_settle_toolbutton);
    if(!menuList.contains(tr("recede_settle_toolbutton")))
        monthly_settle_widgetaction->setVisible(false);

    account_detail_widgetaction = new QWidgetAction(charge_menu);
    ToolButton *account_detail_toolbutton = new ToolButton(charge_menu);
    account_detail_toolbutton->setObjectName("account_detail_toolbutton");
    account_detail_toolbutton->setText(tr(""));
    account_detail_toolbutton->setStyleSheet("QToolButton#account_detail_toolbutton:hover,QToolButton#account_detail_toolbutton:open{"
                                     "border-image:url(images/account_detail_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#account_detail_toolbutton:!hover:!open{"
                                     "border-image:url(images/account_detail_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(account_detail_toolbutton,SIGNAL(clicked()),this,SLOT(onAccountDetailPage()));
    account_detail_widgetaction->setDefaultWidget(account_detail_toolbutton);
    if(!menuList.contains(tr("account_detail_toolbutton")))
        account_detail_widgetaction->setVisible(false);

    charge_menu->addAction(account_pay_widgetaction);
    charge_menu->addAction(monthly_settle_widgetaction);
//    charge_menu->addAction(settle_check_widgetaction);
    charge_menu->addAction(recede_settle_widgetaction);
    charge_menu->addAction(account_detail_widgetaction);
    //report manage
    report_menu = new QMenu(tr("报表管理"),menubar);

    monthly_reside_widgetaction = new QWidgetAction(report_menu);
    ToolButton *monthly_reside_toolbutton = new ToolButton(report_menu);
    monthly_reside_toolbutton->setObjectName("monthly_reside_toolbutton");
    monthly_reside_toolbutton->setText(tr("月入住统计"));
//    base_cost_toolbutton->setStyleSheet("QToolButton#base_cost_toolbutton:hover,QToolButton#base_cost_toolbutton:open{"
//                                     "border-image:url(images/base_cost_toolbutton_used.png);"
//                                     "}"
//                                     "QToolButton#base_cost_toolbutton:!hover:!open{"
//                                     "border-image:url(images/base_cost_toolbutton_unused.png);"
//                                     "}"
//                                     "QToolButton:menu-indicator{image:None;}");
    connect(monthly_reside_toolbutton,SIGNAL(clicked()),this,SLOT(onMonthlyResideStatisticsPage()));
    monthly_reside_widgetaction->setDefaultWidget(monthly_reside_toolbutton);
    if(!menuList.contains(tr("monthly_reside_toolbutton")))
        monthly_reside_widgetaction->setVisible(false);

    report_menu->addAction(monthly_reside_widgetaction);
    //resource manage
    resource_menu = new QMenu(tr("资料管理"),menubar);

    base_cost_widgetaction = new QWidgetAction(resource_menu);
    ToolButton *base_cost_toolbutton = new ToolButton(resource_menu);
    base_cost_toolbutton->setObjectName("base_cost_toolbutton");
    base_cost_toolbutton->setText(tr(""));
    base_cost_toolbutton->setStyleSheet("QToolButton#base_cost_toolbutton:hover,QToolButton#base_cost_toolbutton:open{"
                                     "border-image:url(images/base_cost_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#base_cost_toolbutton:!hover:!open{"
                                     "border-image:url(images/base_cost_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(base_cost_toolbutton,SIGNAL(clicked()),this,SLOT(onBaseCostDialog()));
    base_cost_widgetaction->setDefaultWidget(base_cost_toolbutton);
    if(!menuList.contains(tr("base_cost_toolbutton")))
        base_cost_widgetaction->setVisible(false);

    stage_cost_widgetaction = new QWidgetAction(resource_menu);
    ToolButton *stage_cost_toolbutton = new ToolButton(resource_menu);
    stage_cost_toolbutton->setObjectName("stage_cost_toolbutton");
    stage_cost_toolbutton->setText(tr(""));
    stage_cost_toolbutton->setStyleSheet("QToolButton#stage_cost_toolbutton:hover,QToolButton#stage_cost_toolbutton:open{"
                                     "border-image:url(images/stage_cost_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#stage_cost_toolbutton:!hover:!open{"
                                     "border-image:url(images/stage_cost_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(stage_cost_toolbutton,SIGNAL(clicked()),this,SLOT(onStageCostDialog()));
    stage_cost_widgetaction->setDefaultWidget(stage_cost_toolbutton);
    if(!menuList.contains(tr("stage_cost_toolbutton")))
        stage_cost_widgetaction->setVisible(false);

    dictionary_widgetaction = new QWidgetAction(resource_menu);
    ToolButton *dictionary_toolbutton = new ToolButton(resource_menu);
    dictionary_toolbutton->setObjectName("dictionary_toolbutton");
    dictionary_toolbutton->setText(tr(""));
    dictionary_toolbutton->setStyleSheet("QToolButton#dictionary_toolbutton:hover,QToolButton#dictionary_toolbutton:open{"
                                     "border-image:url(images/dictionary_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#dictionary_toolbutton:!hover:!open{"
                                     "border-image:url(images/dictionary_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(dictionary_toolbutton,SIGNAL(clicked()),this,SLOT(onDictionaryDialog()));
    dictionary_widgetaction->setDefaultWidget(dictionary_toolbutton);
    if(!menuList.contains(tr("dictionary_toolbutton")))
        dictionary_widgetaction->setVisible(false);

    resource_menu->addAction(base_cost_widgetaction);
    resource_menu->addAction(stage_cost_widgetaction);
    resource_menu->addAction(dictionary_widgetaction);

    //system manage
    system_menu = new QMenu(tr("系统管理"),menubar);

    role_widgetaction = new QWidgetAction(system_menu);
    ToolButton *role_toolbutton = new ToolButton(system_menu);
    role_toolbutton->setObjectName("role_toolbutton");
    role_toolbutton->setText(tr(""));
    role_toolbutton->setStyleSheet("QToolButton#role_toolbutton:hover,QToolButton#role_toolbutton:open{"
                                     "border-image:url(images/role_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#role_toolbutton:!hover:!open{"
                                     "border-image:url(images/role_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(role_toolbutton,SIGNAL(clicked()),this,SLOT(onRoleDialog()));
    role_widgetaction->setDefaultWidget(role_toolbutton);
    if(!menuList.contains(tr("role_toolbutton")))
        role_widgetaction->setVisible(false);

    operator_widgetaction = new QWidgetAction(system_menu);
    ToolButton *operator_toolbutton = new ToolButton(system_menu);
    operator_toolbutton->setObjectName("operator_toolbutton");
    operator_toolbutton->setText(tr(""));
    operator_toolbutton->setStyleSheet("QToolButton#operator_toolbutton:hover,QToolButton#operator_toolbutton:open{"
                                     "border-image:url(images/operator_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#operator_toolbutton:!hover:!open{"
                                     "border-image:url(images/operator_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(operator_toolbutton,SIGNAL(clicked()),this,SLOT(onOperatorDialog()));
    operator_widgetaction->setDefaultWidget(operator_toolbutton);
    if(!menuList.contains(tr("operator_toolbutton")))
        operator_widgetaction->setVisible(false);

    previlege_widgetaction = new QWidgetAction(system_menu);
    ToolButton *previlege_toolbutton = new ToolButton(system_menu);
    previlege_toolbutton->setObjectName("previlege_toolbutton");
    previlege_toolbutton->setText(tr(""));
    previlege_toolbutton->setStyleSheet("QToolButton#previlege_toolbutton:hover,QToolButton#previlege_toolbutton:open{"
                                     "border-image:url(images/previlege_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#previlege_toolbutton:!hover:!open{"
                                     "border-image:url(images/previlege_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(previlege_toolbutton,SIGNAL(clicked()),this,SLOT(onPrevilegePage()));
    previlege_widgetaction->setDefaultWidget(previlege_toolbutton);
    if(!menuList.contains(tr("previlege_toolbutton")))
        previlege_widgetaction->setVisible(false);

    operation_log_widgetaction = new QWidgetAction(system_menu);
    ToolButton *operation_log_toolbutton = new ToolButton(system_menu);
    operation_log_toolbutton->setObjectName("operation_log_toolbutton");
    operation_log_toolbutton->setText(tr(""));
    operation_log_toolbutton->setStyleSheet("QToolButton#operation_log_toolbutton:hover,QToolButton#operation_log_toolbutton:open{"
                                     "border-image:url(images/operation_log_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#operation_log_toolbutton:!hover:!open{"
                                     "border-image:url(images/operation_log_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(operation_log_toolbutton,SIGNAL(clicked()),this,SLOT(onOperationLogPage()));
    operation_log_widgetaction->setDefaultWidget(operation_log_toolbutton);
    if(!menuList.contains(tr("operation_log_toolbutton")))
        operation_log_widgetaction->setVisible(false);

    password_widgetaction = new QWidgetAction(system_menu);
    ToolButton *password_toolbutton = new ToolButton(system_menu);
    password_toolbutton->setObjectName("password_toolbutton");
    password_toolbutton->setText(tr("密码修改"));
    password_toolbutton->setStyleSheet("QToolButton#password_toolbutton:hover,QToolButton#password_toolbutton:open{"
                                     "border-image:url(images/password_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#password_toolbutton:!hover:!open{"
                                     "border-image:url(images/password_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    connect(password_toolbutton,SIGNAL(clicked()),this,SLOT(onPasswordDialog()));
    password_widgetaction->setDefaultWidget(password_toolbutton);
    if(!menuList.contains(tr("password_toolbutton")))
        password_widgetaction->setVisible(false);

    system_menu->addAction(role_widgetaction);
    system_menu->addAction(operator_widgetaction);
    system_menu->addAction(previlege_widgetaction);
    system_menu->addAction(operation_log_widgetaction);
    system_menu->addAction(password_widgetaction);

    help_menu = new QMenu(tr("帮助"),menubar);

    instruction_widgetaction = new QWidgetAction(help_menu);
    ToolButton *instruction_toolbutton = new ToolButton(help_menu);
    instruction_toolbutton->setObjectName("instruction_toolbutton");
    instruction_toolbutton->setText(tr(""));
    instruction_toolbutton->setStyleSheet("QToolButton#instruction_toolbutton:hover,QToolButton#instruction_toolbutton:open{"
                                     "border-image:url(images/instruction_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#instruction_toolbutton:!hover:!open{"
                                     "border-image:url(images/instruction_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    instruction_widgetaction->setDefaultWidget(instruction_toolbutton);
    if(!menuList.contains(tr("instruction_toolbutton")))
        instruction_widgetaction->setVisible(false);

    about_widgetaction = new QWidgetAction(help_menu);
    ToolButton *about_toolbutton = new ToolButton(help_menu);
    about_toolbutton->setObjectName("about_toolbutton");
    about_toolbutton->setText(tr(""));
    about_toolbutton->setStyleSheet("QToolButton#about_toolbutton:hover,QToolButton#about_toolbutton:open{"
                                     "border-image:url(images/about_toolbutton_used.png);"
                                     "}"
                                     "QToolButton#about_toolbutton:!hover:!open{"
                                     "border-image:url(images/about_toolbutton_unused.png);"
                                     "}"
                                     "QToolButton:menu-indicator{image:None;}");
    about_widgetaction->setDefaultWidget(about_toolbutton);
    if(!menuList.contains(tr("about_toolbutton")))
        about_widgetaction->setVisible(false);

    help_menu->addAction(instruction_widgetaction);
    help_menu->addAction(about_widgetaction);
}

void MainWindow::createToolBar()
{
    toolbar = new QToolBar(this);
    toolbar->setMovable(false);
    //toolbar->setFixedWidth(QApplication::desktop()->width()-290);
    toolbar->setFixedWidth(QApplication::desktop()->width());
    toolbar->setFixedHeight(55);
    this->setContextMenuPolicy(Qt::NoContextMenu);
    toolbar->setObjectName("toolbar");
    toolbar->setStyleSheet("QToolBar#toolbar{background: red;spacing: 3px;background-image:url(images/toolbar.png);}");
    toolbar->setWindowTitle(tr("工具栏"));

    QSize iconsize(60,50);

    if(menuList.contains(tr("visit_toolbutton"))){
        ToolButton * visit_toolbutton = new ToolButton(this);
         visit_toolbutton->setText(tr(""));
        //configure_toolbutton->setIcon(QIcon(QPixmap("images/configure_menu.png").scaled(iconsize)));
        visit_toolbutton->setObjectName("visit_toolbutton");
        visit_toolbutton->setStyleSheet("QToolButton#visit_toolbutton:hover,QToolButton#visit_toolbutton:open{"
                                            "background-image:url(images/visit_toolbutton_used.png);"
                                            "background-repeat:no-repeat;"
                                            "}"
                                            "QToolButton#visit_toolbutton:!hover:!open{"
                                            "background-image:url(images/visit_toolbutton_unused.png);"
                                            "background-repeat:no-repeat;"
                                            "}"
                                            "QToolButton:menu-indicator{image:None;}");
        connect(visit_toolbutton,SIGNAL(clicked()),this,SLOT(onVisitRecord()));
        toolbar->addWidget(visit_toolbutton);
    }

    if(barList.contains(tr("reside_toolbutton"))){
        ToolButton * reside_toolbutton = new ToolButton(this);
        reside_toolbutton->setText(tr(""));
        //configure_toolbutton->setIcon(QIcon(QPixmap("images/configure_menu.png").scaled(iconsize)));
        reside_toolbutton->setObjectName("reside_toolbutton");
        reside_toolbutton->setStyleSheet("QToolButton#reside_toolbutton:hover,QToolButton#reside_toolbutton:open{"
                                         "background-image:url(images/reside_toolbutton_used.png);"
                                         "background-repeat:no-repeat;"
                                         "}"
                                         "QToolButton#reside_toolbutton:!hover:!open{"
                                         "background-image:url(images/reside_toolbutton_unused.png);"
                                         "background-repeat:no-repeat;"
                                         "}"
                                         "QToolButton:menu-indicator{image:None;}");
        reside_toolbutton->setMenu(reside_menu);
        toolbar->addWidget(reside_toolbutton);
    }

    if(barList.contains(tr("elder_toolbutton"))){
        ToolButton * elder_toolbutton = new ToolButton(this);
        //personel_toolbutton->setIcon(QIcon(QPixmap("images/older_menu.png").scaled(iconsize)));
        elder_toolbutton->setObjectName("elder_toolbutton");
        elder_toolbutton->setStyleSheet("QToolButton#elder_toolbutton:hover,QToolButton#elder_toolbutton:open{"
                                           "background-image:url(images/elder_toolbutton_used.png);"
                                           "background-repeat:no-repeat;"
                                           "}"
                                           "QToolButton#elder_toolbutton:!hover:!open{"
                                           "background-image:url(images/elder_toolbutton_unused.png);"
                                           "background-repeat:no-repeat;"
                                           "}"
                                           "QToolButton:menu-indicator{image:None;}");
        elder_toolbutton->setText(tr(""));
        elder_toolbutton->setMenu(elder_menu);
        toolbar->addWidget(elder_toolbutton);
    }

    if(barList.contains(tr("charge_toolbutton"))){
        ToolButton * charge_toolbutton = new ToolButton(this);
        charge_toolbutton->setObjectName("charge_toolbutton");
        charge_toolbutton->setText(tr(""));
        charge_toolbutton->setMenu(charge_menu);
        charge_toolbutton->setStyleSheet("QToolButton#charge_toolbutton:hover,QToolButton#charge_toolbutton:open{"
                                               "background-image:url(images/charge_toolbutton_used.png);"
                                               "background-repeat:no-repeat;"
                                               "}"
                                               "QToolButton#charge_toolbutton:!hover:!open{"
                                               "background-image:url(images/charge_toolbutton_unused.png);"
                                               "background-repeat:no-repeat;"
                                               "}"
                                               "QToolButton:menu-indicator{image:None;}");
    //    connect(monitorstate_toolbutton,SIGNAL(clicked()),this,SLOT(onShowMonitorState()));
        toolbar->addWidget(charge_toolbutton);
    }

    if(barList.contains(tr("report_toolbutton"))){
        ToolButton *report_toolbutton = new ToolButton(this);
        //levavesystem_toolbutton->hide();
        report_toolbutton->setObjectName("report_toolbutton");
        report_toolbutton->setText(tr(""));
        report_toolbutton->setStyleSheet("QToolButton#report_toolbutton:hover,QToolButton#report_toolbutton:open{"
                                               "background-image:url(images/report_toolbutton_used.png);"
                                               "background-repeat:no-repeat;"
                                               "}"
                                               "QToolButton#report_toolbutton:!hover:!open{"
                                               "background-image:url(images/report_toolbutton_unused.png);"
                                               "background-repeat:no-repeat;"
                                               "}"
                                               "QToolButton:menu-indicator{image:None;}");
        report_toolbutton->setMenu(report_menu);
        toolbar->addWidget(report_toolbutton);
    }

    if(barList.contains(tr("employee_toolbutton"))){
        ToolButton * employee_toolbutton = new ToolButton(this);
        //query_toolbutton->setIcon(QIcon(QPixmap("images/query_menu.png").scaled(iconsize)));
        employee_toolbutton->setObjectName("employee_toolbutton");
        employee_toolbutton->setStyleSheet("QToolButton#employee_toolbutton:hover,QToolButton#employee_toolbutton:open{"
                                        "background-image:url(images/employee_toolbutton_used.png);"
                                        "background-repeat:no-repeat;"
                                        "}"
                                        "QToolButton#employee_toolbutton:!hover:!open{"
                                        "background-image:url(images/employee_toolbutton_unused.png);"
                                        "background-repeat:no-repeat;"
                                        "}"
                                        "QToolButton:menu-indicator{image:None;}");
         employee_toolbutton->setText(tr(""));
        employee_toolbutton->setMenu(employee_menu);
        toolbar->addWidget(employee_toolbutton);
    }

    if(barList.contains(tr("warehouse_toolbutton"))){
        ToolButton * warehouse_toolbutton = new ToolButton(this);
        //message_toolbutton->setIcon(QIcon(QPixmap("images/message_menu.png").scaled(iconsize)));
        warehouse_toolbutton->setObjectName("warehouse_toolbutton");
        warehouse_toolbutton->setText(tr(""));
        warehouse_toolbutton->setMenu(warehouse_menu);
        warehouse_toolbutton->setStyleSheet("QToolButton#warehouse_toolbutton:hover,QToolButton#warehouse_toolbutton:open{"
                                          "background-image:url(images/warehouse_toolbutton_used.png);"
                                          "background-repeat:no-repeat;"
                                          "}"
                                          "QToolButton#warehouse_toolbutton:!hover:!open{"
                                          "background-image:url(images/warehouse_toolbutton_unused.png);"
                                          "background-repeat:no-repeat;"
                                          "}"
                                          "QToolButton:menu-indicator{image:None;}");
        toolbar->addWidget(warehouse_toolbutton);
    }

    if(barList.contains(tr("resource_toolbutton"))){
        ToolButton *resource_toolbutton = new ToolButton(this);
        resource_toolbutton->setObjectName("resource_toolbutton");
        resource_toolbutton->setText(tr(""));
        resource_toolbutton->setStyleSheet("QToolButton#resource_toolbutton:hover,QToolButton#resource_toolbutton:open{"
                                       "background-image:url(images/resource_toolbutton_used.png);"
                                       "background-repeat:no-repeat;"
                                       "}"
                                       "QToolButton#resource_toolbutton:!hover:!open{"
                                       "background-image:url(images/resource_toolbutton_unused.png);"
                                       "background-repeat:no-repeat;"
                                       "}"
                                       "QToolButton:menu-indicator{image:None;}");
        resource_toolbutton->setMenu(resource_menu);
        toolbar->addWidget(resource_toolbutton);
    }

    if(barList.contains(tr("system_toolbutton"))){
        ToolButton *system_toolbutton = new ToolButton(this);
        system_toolbutton->setObjectName("system_toolbutton");
        system_toolbutton->setText(tr(""));
        system_toolbutton->setStyleSheet("QToolButton#system_toolbutton:hover,QToolButton#system_toolbutton:open{"
                                       "background-image:url(images/system_toolbutton_used.png);"
                                       "background-repeat:no-repeat;"
                                       "}"
                                       "QToolButton#system_toolbutton:!hover:!open{"
                                       "background-image:url(images/system_toolbutton_unused.png);"
                                       "background-repeat:no-repeat;"
                                       "}"
                                       "QToolButton:menu-indicator{image:None;}");
        system_toolbutton->setMenu(system_menu);
        toolbar->addWidget(system_toolbutton);
    }

    if(barList.contains(tr("help_toolbutton"))){
        ToolButton *help_toolbutton = new ToolButton(this);
        help_toolbutton->setObjectName("help_toolbutton");
        help_toolbutton->setText(tr(""));
        help_toolbutton->setStyleSheet("QToolButton#help_toolbutton:hover,QToolButton#help_toolbutton:open{"
                                       "background-image:url(images/help_toolbutton_used.png);"
                                       "background-repeat:no-repeat;"
                                       "}"
                                       "QToolButton#help_toolbutton:!hover:!open{"
                                       "background-image:url(images/help_toolbutton_unused.png);"
                                       "background-repeat:no-repeat;"
                                       "}"
                                       "QToolButton:menu-indicator{image:None;}");
        help_toolbutton->setMenu(help_menu);
        toolbar->addWidget(help_toolbutton);
    }

    this->addToolBar(Qt::TopToolBarArea,toolbar);

    qDebug()<<"time_toolbar";
    QToolBar * time_toolbar = new QToolBar(this);
    time_toolbar->setToolTip("双击此处设置系统时间");
    time_toolbar->setMovable(false);
    sstd = new SetSystemTimeDialog(this);
    sstd->move(QApplication::desktop()->width()/2,20);
    sstd->hide();
    datewidget = new DateWidget(time_toolbar);
    connect(datewidget,SIGNAL(showSystemClock()),this,SLOT(showSystemClock()));
    tw = new TimeWidget(time_toolbar);
    connect(tw,SIGNAL(showSystemClock()),this,SLOT(showSystemClock()));
    datewidget->move(20,2);
    tw->move(160,2);
    time_toolbar->setFixedWidth(290);
    time_toolbar->setFixedHeight(55);
    time_toolbar->setStyleSheet("QToolBar{margin-left:0px;margin-top:0px;margin-bottom:0px;margin-right:0px;border-image:url(images/curtime.png);}");
    qDebug()<<"time_toolbar";
    //this->addToolBar(Qt::TopToolBarArea,time_toolbar);
    time_toolbar->hide();
}

bool MainWindow::isTabExist(QString param){
    for(int i = 0;i<central_tablewidget->count();++i){
        if(central_tablewidget->tabText(i).compare(param) == 0){
             return true;
        }
    }
    return false;
}

void MainWindow::onVisitRecord(){
    if(!this->isTabExist(tr("来访登记管理"))){
        visitRecord = new VisitRecord(central_tablewidget);
        connect(visitRecord,SIGNAL(closeVisitRecord()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(visitRecord,tr("来访登记管理"));
    }
    central_tablewidget->setCurrentWidget(visitRecord);    
}

void MainWindow::onElderBaseInfoPage(){
    if(!this->isTabExist(tr("基本信息录入"))){
        elderBaseInfoPage = new ElderBaseInfo(central_tablewidget);
        connect(elderBaseInfoPage,SIGNAL(closeElderBaseInfoPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(elderBaseInfoPage,tr("基本信息录入"));
    }
    central_tablewidget->setCurrentWidget(elderBaseInfoPage);
    reside_menu->hide();//内存只读错误
}

void MainWindow::onHealthAssessPage(){
    if(!this->isTabExist(tr("健康评估"))){
        healthAssessPage = new HealthAssess(central_tablewidget);
        connect(healthAssessPage,SIGNAL(closeHealthAssessPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(healthAssessPage,tr("健康评估"));
    }
    central_tablewidget->setCurrentWidget(healthAssessPage);
    reside_menu->hide();
}

void MainWindow::onResideRegisterPage(){
    if(!this->isTabExist(tr("居住管理"))){
        resideRegisterPage = new ResideRegister(central_tablewidget);
        connect(resideRegisterPage,SIGNAL(closeResideRegisterPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(resideRegisterPage,tr("居住管理"));
    }
    central_tablewidget->setCurrentWidget(resideRegisterPage);
    reside_menu->hide();
}

void MainWindow::onNurseRecordPage(){
    if(!this->isTabExist(tr("护理记录"))){
        nurseRecordPage = new NurseRecord(central_tablewidget);
        connect(nurseRecordPage,SIGNAL(closeNurseRecordPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(nurseRecordPage,tr("护理记录"));
    }
    central_tablewidget->setCurrentWidget(nurseRecordPage);
    elder_menu->hide();
}

void MainWindow::onAdviceRecordPage(){
    if(!this->isTabExist(tr("医嘱记录"))){
        adviceRecordPage = new AdviceRecord(central_tablewidget);
        connect(adviceRecordPage,SIGNAL(closeAdviceRecordPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(adviceRecordPage,tr("医嘱记录"));
    }
    central_tablewidget->setCurrentWidget(adviceRecordPage);
    elder_menu->hide();
}

void MainWindow::onSpecialServicePage(){
    if(!this->isTabExist(tr("特殊服务"))){
        specialServicePage = new SpecialService(central_tablewidget);
        connect(specialServicePage,SIGNAL(closeSpecialServicePage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(specialServicePage,tr("特殊服务"));
    }
    central_tablewidget->setCurrentWidget(specialServicePage);
    elder_menu->hide();
}

void MainWindow::onAccidentRecordPage(){
    if(!this->isTabExist(tr("事故记录"))){
        accidentRecordPage = new AccidentRecord(central_tablewidget);
        connect(accidentRecordPage,SIGNAL(closeAccidentRecordPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(accidentRecordPage,tr("事故记录"));
    }
    central_tablewidget->setCurrentWidget(accidentRecordPage);
    elder_menu->hide();
}

void MainWindow::onElderVacationPage(){
    if(!this->isTabExist(tr("老人请假管理"))){
        elderVacationPage = new ElderVacation(central_tablewidget);
        connect(elderVacationPage,SIGNAL(closeElderVacationPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(elderVacationPage,tr("老人请假管理"));
    }
    central_tablewidget->setCurrentWidget(elderVacationPage);
    elder_menu->hide();
}

void MainWindow::onElderBirthdayPage(){
    if(!this->isTabExist(tr("生日提醒"))){
        elderBirthdayPage = new ElderBirthday(central_tablewidget);
        connect(elderBirthdayPage,SIGNAL(closeElderBirthdayPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(elderBirthdayPage,tr("生日提醒"));
    }
    central_tablewidget->setCurrentWidget(elderBirthdayPage);
    elder_menu->hide();
}

void MainWindow::onNurseChangePage(){
    if(!this->isTabExist(tr("护理变更"))){
        nurseChangePage = new NurseChange(central_tablewidget);
        connect(nurseChangePage,SIGNAL(closeNurseChangePage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(nurseChangePage,tr("护理变更"));
    }
    central_tablewidget->setCurrentWidget(nurseChangePage);
    elder_menu->hide();
}

void MainWindow::onAccountPayPage(){
    if(!this->isTabExist(tr("备用金续费"))){
        accountPayPage = new AccountPay(central_tablewidget);
        connect(accountPayPage,SIGNAL(closeAccountPayPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(accountPayPage,tr("备用金续费"));
    }
    central_tablewidget->setCurrentWidget(accountPayPage);
    charge_menu->hide();
}

void MainWindow::onMonthlySettlePage(){
    if(!this->isTabExist(tr("月费用结算"))){
        monthlySettlePage = new MonthlySettle(central_tablewidget);
        connect(monthlySettlePage,SIGNAL(closeMonthlySettlePage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(monthlySettlePage,tr("月费用结算"));
    }
    central_tablewidget->setCurrentWidget(monthlySettlePage);
    charge_menu->hide();
}

void MainWindow::onRecedeSettlePage(){
    if(!this->isTabExist(tr("退住结款"))){
        recedeSettlePage = new RecedeSettle(central_tablewidget);
        connect(recedeSettlePage,SIGNAL(closeRecedeSettlePage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(recedeSettlePage,tr("退住结款"));
    }
    central_tablewidget->setCurrentWidget(recedeSettlePage);
    charge_menu->hide();
}

void MainWindow::onAccountDetailPage(){
    if(!this->isTabExist(tr("备用金流水"))){
        accountDetailPage = new AccountDetail(central_tablewidget);
        connect(accountDetailPage,SIGNAL(closeAccountDetailPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(accountDetailPage,tr("备用金流水"));
    }
    central_tablewidget->setCurrentWidget(accountDetailPage);
    charge_menu->hide();
}

void MainWindow::onMonthlyResideStatisticsPage(){
    if(!this->isTabExist(tr("月入住统计"))){
        monthlyResideStatisticsPage = new MonthlyResideStatistics(central_tablewidget);
        connect(monthlyResideStatisticsPage,SIGNAL(closeMonthlyAResideStatisticsPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(monthlyResideStatisticsPage,tr("月入住统计"));
    }
    central_tablewidget->setCurrentWidget(monthlyResideStatisticsPage);
    report_menu->hide();
}

void MainWindow::onEmployeeBaseInfoPage(){
    if(!this->isTabExist(tr("员工基本信息"))){
        employeeBaseInfoPage = new EmployeeBaseinfo(central_tablewidget);
        connect(employeeBaseInfoPage,SIGNAL(closeEmployeeBaseInfoPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(employeeBaseInfoPage,tr("员工基本信息"));
    }
    central_tablewidget->setCurrentWidget(employeeBaseInfoPage);
    employee_menu->hide();
}

void MainWindow::onEmployeeVacationPage(){
    if(!this->isTabExist(tr("员工请假管理"))){
        employeeVacationPage = new EmployeeVacation(central_tablewidget);
        connect(employeeVacationPage,SIGNAL(closeEmployeeVacationPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(employeeVacationPage,tr("员工请假管理"));
    }
    central_tablewidget->setCurrentWidget(employeeVacationPage);
    employee_menu->hide();
}

void MainWindow::onCheckInPage(){
    if(!this->isTabExist(tr("入库管理"))){
        checkInPage = new CheckIn(central_tablewidget);
        connect(checkInPage,SIGNAL(closeCheckInPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(checkInPage,tr("入库管理"));
    }
    central_tablewidget->setCurrentWidget(checkInPage);
    warehouse_menu->hide();
}

void MainWindow::onStoragePage(){
    if(!this->isTabExist(tr("库存查询"))){
        storagePage = new Storage(central_tablewidget);
        connect(storagePage,SIGNAL(closeStoragePage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(storagePage,tr("库存查询"));
    }
    central_tablewidget->setCurrentWidget(storagePage);
    warehouse_menu->hide();
}

void MainWindow::onCheckOutPage(){
    if(!this->isTabExist(tr("出库管理"))){
        checkOutPage = new CheckOut(central_tablewidget);
        connect(checkOutPage,SIGNAL(closeCheckOutPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(checkOutPage,tr("出库管理"));
    }
    central_tablewidget->setCurrentWidget(checkOutPage);
    warehouse_menu->hide();
}

void MainWindow::onDictionaryDialog(){
    resource_menu->hide();
    DictionaryDialog *dialog = new DictionaryDialog(this);
    dialog->exec();
}

void MainWindow::onBaseCostDialog(){
    resource_menu->hide();
    BaseCostDialog *dialog = new BaseCostDialog(this);
    dialog->exec();
}

void MainWindow::onStageCostDialog(){
    resource_menu->hide();
    StageCostDialog *dialog = new StageCostDialog(this);
    dialog->exec();
}

void MainWindow::onRoleDialog(){
    system_menu->hide();
    RoleDialog *dialog = new RoleDialog(this);
    dialog->exec();
}

void MainWindow::onOperatorDialog(){
    system_menu->hide();
    OperatorDialog *dialog = new OperatorDialog(this);
    dialog->exec();
}

void MainWindow::onPrevilegePage(){
    if(!this->isTabExist(tr("角色权限管理"))){
        previlegePage = new Previlege(central_tablewidget);
        connect(previlegePage,SIGNAL(closePrevilegePage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(previlegePage,tr("角色权限管理"));
    }
    central_tablewidget->setCurrentWidget(previlegePage);
    system_menu->hide();
}

void MainWindow::onOperationLogPage(){
    if(!this->isTabExist(tr("操作日志查询"))){
        operationLogPage = new OperationLog(central_tablewidget);
        connect(operationLogPage,SIGNAL(closeOperationLogPage()),central_tablewidget,SLOT(closeCurrentPage()));
        central_tablewidget->addTab(operationLogPage,tr("操作日志查询"));
    }
    central_tablewidget->setCurrentWidget(operationLogPage);
    system_menu->hide();
}

void MainWindow::onPasswordDialog(){
    system_menu->hide();
    PasswordDialog *dialog = new PasswordDialog(this);
    dialog->exec();
}

void MainWindow::showSystemClock()
{
    qDebug()<<"showSystemClock";
    sstd->setCurrentTime();
    sstd->show();
}

void MainWindow::hideDragDropWidget(){
    if(central_tablewidget->currentIndex()==0)
        dragdrop_dockwidget->setVisible(true);
    else
        dragdrop_dockwidget->setVisible(false);
}

void MainWindow::createStatusBar()
{
    qDebug()<<"创建工具栏";
    statusbar = new StatusBar(this);
    this->setStatusBar(statusbar);
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    qDebug()<<"mainwindowcloseevent";
    QMainWindow::closeEvent(event);
}


// void MainWindow::onElderBaseInfoPage(){
//     elderBaseInfoPage = new ElderBaseInfo(central_tablewidget);
//     central_tablewidget->addTab(elderBaseInfoPage,tr("老人信息"));
//     central_tablewidget->setCurrentWidget(elderBaseInfoPage);
// }

// void MainWindow::onAccidentRecordPage(){
//     if(central_tablewidget)
//     accidentRecordPage = new AccidentRecord(central_tablewidget);
//     central_tablewidget->addTab(accidentRecordPage,tr("事故记录"));
//     central_tablewidget->setCurrentWidget(accidentRecordPage);
// }

//void MainWindow::onAboutHelp()
//{
//    //关于软件

//    qDebug()<<tr("关于软件");
//    QDialog d(this);
//    d.setWindowTitle("关于软件");
//    d.resize(200,100);
//    QVBoxLayout * vbl = new QVBoxLayout;
//    QLabel * softwarename = new QLabel("养老院环境监测与辅助护理智能系统 v1.0",&d);
//    QLabel * companyname = new QLabel("版权 2014-2015 中国南京.华根电子 保留所有权利",&d);
//    vbl->addWidget(softwarename);
//    vbl->addWidget(companyname);
//    d.setLayout(vbl);
//    d.exec();
//}

//void MainWindow::onLockLeaveSystem()
//{
//    qDebug()<<"锁定";

//    if(globaldb.open())
//    {
//        if(!dbisconnected)
//        {
//            dbisconnected = true;
//            raao->setAppEnable(true);
//        }
//        insertLog("锁定系统");
//        AlarmDealWithConfirmDialog awcd;
//        awcd.setState(LOCK);
//        if(awcd.exec()==awcd.Accepted)
//            insertLog("系统解锁");
//        //globaldb.close();
//    }
//    else
//    {
//        if(dbisconnected)
//        {
//            dbisconnected = false;
//            raao->setAppEnable(false);
//            QMessageBox::warning(0,"警告","数据库连接失败，暂时无法锁定系统！","确定");
//        }
//    }
//}

//void MainWindow::onLogoutLeaveSystem()
//{
//    qDebug()<<"注销";

//    if(globaldb.open())
//    {
//        if(!dbisconnected)
//        {
//            dbisconnected = true;
//            raao->setAppEnable(true);
//        }
//        int result = QMessageBox::warning(0,"警告","即将注销系统","确定","取消");
//        if(result == 0)
//        {
//            if(central_tablewidget->count() >= 2 )
//            {
//                QMessageBox::warning(0,"警告","请关闭实时监控区域打开的页面！","确定");
//                return;
//            }
//            else
//            {
//                insertLog("系统注销");
//            }
//        }
//        else
//        {
//            return;
//        }

//        AlarmDealWithConfirmDialog awcd;
//        awcd.setState(LOGOUT);
//        if(awcd.exec() == awcd.Accepted)
//        {
//            insertLog("登陆系统");
//        }
//        //globaldb.close();
//    }
//    else
//    {
//        if(dbisconnected)
//        {
//            dbisconnected = false;
//            raao->setAppEnable(false);
//            QMessageBox::warning(0,"警告","数据库连接失败，暂时无法注销系统！","确定");
//        }
//    }
//}

//void MainWindow::onExitLeaveSystem()
//{
//    qDebug()<<"关闭";

//    int result  = QMessageBox::warning(0,"警告","是否关闭系统？","确定","取消");
//    if(result == 0)
//    {
//        if(central_tablewidget->count() >= 2 )
//        {
//            QMessageBox::warning(0,"警告","请关闭实时监控区域打开的页面！","确定");
//            return;
//        }
//        else
//        {
//            insertLog("关闭系统");
//            emit closeapp();
//        }
//    }
//    else
//    {
//        return;
//    }
//}

//void MainWindow::onRestartSystem()
//{

//    int result  = QMessageBox::warning(0,"警告","是否重新启动系统","确定","取消");

//    if(result == 0)
//    {
//        if(central_tablewidget->count() >= 2 )
//        {
//            QMessageBox::warning(0,"警告","请关闭实时监控区域打开的页面！","确定");
//            return;
//        }
//        else
//        {
//            insertLog("重新启动系统");
//            qApp->exit(773);//773 = 'r'+'e'+'s'+'t'+'a'+'r'+'t'
//        }
//    }
//    else
//    {
//        return;
//    }
//}

ToolButton::ToolButton(QWidget *parent) :
    QToolButton(parent)
{
    this->setFixedSize(110,55);
    //this->setIconSize(QSize(25,25));
    this->setPopupMode(QToolButton::InstantPopup);
    //this->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QFont font = this->font();
    font.setPixelSize(12);
    this->setFont(font);
    //  this->setStyleSheet("QToolButton:menu-indicator{image:None;}");
    this->setAutoRaise(true);
    this->setAutoFillBackground(true);
}

void ToolButton::enterEvent(QEvent * event)
{
    /*if(this->objectName() == "help_toolbutton")
        setStyleSheet("QToolButton#help_toolbutton:hover,QToolButton#help_toolbutton:pressed{"
                      "background-image:url(images/help_toolbutton_used.png);"
                      "background-repeat:no-repeat;"
                      "}"
                      "QToolButton:menu-indicator{image:None;}");*/

    QToolButton::enterEvent(event);
}

void ToolButton::leaveEvent(QEvent * event)
{
    /*if(this->objectName() == "help_toolbutton")
        setStyleSheet("QToolButton#help_toolbutton{"
                      "background-image:url(images/help_toolbutton_unused.png);"
                      "background-repeat:no-repeat;"
                      "}"
                      "QToolButton:menu-indicator{image:None;}");*/
    QToolButton::leaveEvent(event);
}

void ToolButton::mousePressEvent(QMouseEvent *event)
{
    /* if(this->objectName() == "help_toolbutton")
        setStyleSheet("QToolButton#help_toolbutton{"
                      "background-image:url(images/help_toolbutton_used.png);"
                      "background-repeat:no-repeat;"
                      "}"
                      "QToolButton:menu-indicator{image:None;}");*/
    QToolButton::mousePressEvent(event);
}

#include<QtGui>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

void loadStyleSheet(QString qssName)//加载qss文件
{
    QFile data(qssName);
    QString qssFile;
    if(data.open(QFile::ReadOnly))
    {
        QTextStream styleIn(&data);
        qssFile = styleIn.readAll();
        data.close();
        qApp->setStyleSheet(qssFile);

    }else{
        qDebug()<<"failed!!!/n";
        //qDebug()<<QDir::currentPath().toStdString().c_str();
    }
}
TimeWidget::TimeWidget(QWidget *parent) :
    QLCDNumber(parent)
{
    this->setObjectName("timewidget");
    // loadStyleSheet(QString("application.qss"));
    //setNumDigits(19);
    setNumDigits(5);
    setSegmentStyle(QLCDNumber::Flat);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));//一秒钟显示一次
    timer->start(1000);
    showtime();
    // setWindowTitle(tr("Digital Clock"));
    this->setFixedHeight(50);
    this->setFixedWidth(100);
    this->setFrameShape(QFrame::NoFrame);
    this->setToolTip("双击设置系统时间");
    //this->setFixedSize(255,45);
    //resize(300,60);

}

void TimeWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
    QLCDNumber::mouseDoubleClickEvent(event);
    emit showSystemClock();
}
void TimeWidget::enterEvent(QEvent * event)
{
    this->setCursor(Qt::PointingHandCursor);
    QLCDNumber::enterEvent(event);
}

void TimeWidget::showtime()
{
    QDateTime time=QDateTime::currentDateTime();
    //QString text=time.toString("yyyy-MM-dd hh:mm:ss");
    QString text=time.toString("hh:mm");
    display(text);
}

StatusBar::StatusBar(QWidget *parent) :
    QStatusBar(parent)
{
}






