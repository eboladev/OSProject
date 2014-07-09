//首页
#include <QLayout>
#include <QAbstractButton>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QAbstractButton>
#include <QList>
#include <QDebug>
#include <QMap>
#include <QScrollArea>
#include <QToolButton>
#include <QStringList>
#include <QHash>
#include <QAction>
#include <QSplitterHandle>
#include <QSqlQuery>
#include <QLineEdit>
#include <QCheckBox>
#include <QFile>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDateTime>
#include <QScrollBar>
#include <QTimer>
#include <QMouseEvent>
#include <QSqlError>
#include<QTableWidget>
#include<QHeaderView>
#include<QPalette>

#include "struct.h"
#include "homepage.h"
#include "roomstatesearchdialog.h"
#include "piewidget.h"


HomePage::HomePage(QWidget *parent) :
    QToolBox(parent)
{    
    //点亮报警灯信
    QStringList buildingmaptofloor;
    connectToDatabase();
    loadBuildingInfo(buildingmaptofloor);
    buildingnum  = buildingmaptofloor.size();
    QScrollArea * scrollarea = new QScrollArea(this);
    scrollarea->setWidgetResizable(true);
    /*scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);*/
    GeneralViewWidget * gvw = new GeneralViewWidget(this,scrollarea);
    scrollarea->setWidget(gvw);
    this->addItem(scrollarea,"");

    for(int j = 0; j < buildingnum ; j++)
    {
        int floorNum = 0;
        int index = 0;
        QScrollArea * scrollarea = new QScrollArea(this);
        //scrollarea->setObjectName("scro");
        scrollarea->setWidgetResizable(true);
//        BuildingSpliter * spliter = new BuildingSpliter(scrollarea);
//        spliter->constructBuilding(buildingmaptofloor.at(j));
//        scrollarea->setWidget(spliter);

        BuildingToolBox * toolbox = new BuildingToolBox(scrollarea);
        toolbox->constructBuilding(buildingmaptofloor.at(j));
        floorNum = toolbox->getFloorNum();
        scrollarea->setWidget(toolbox);
        this->addItem(scrollarea,"");

//        btnlist = findChildren<QAbstractButton*>(tr("qt_toolbox_toolboxbutton"));
        QList<QAbstractButton *> children = findChildren<QAbstractButton*>(tr("qt_toolbox_toolboxbutton"));
        index = children.size() - floorNum-1;
        if(j == 0){
            btnlist.append(children.first());
        }
        btnlist.append(children.at(index));
        qDebug()<<"btnlist size**********************************"<<btnlist.size();
        QString str = buildingmaptofloor.at(j);
        createBuildingState(btnlist.last(),str.split(":").first());
        qDebug()<<"haha";
        //btnlist.clear();
    }
//     btnlist = findChildren<QAbstractButton*>(tr("qt_toolbox_toolboxbutton"));
     QFont font;
     font.setPointSize(10);
     font.setBold(true);
     btnlist.first()->setFont(font);
     btnlist.first()->setText("系统概览");
    connect(this,SIGNAL(currentChanged(int)),this,SLOT(highlightFloor(int)));
    this->layout()->setSpacing(0);
    this->layout()->setMargin(0);
 //   this->setStyleSheet("QToolBox::tab{selection-color:red; background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #F4A460, stop: 1.0 #F4A460);/*border-radius: 5px;color: darkgray;*/}");
  //  this->setStyleSheet("QToolBox::tab{background-color:lightblue;border:2px groove gray}");
    btnlist.at(0)->setStyleSheet("#qt_toolbox_toolboxbutton{background:lightblue}");
    for(int i = 1;i < buildingnum + 1 ;i++)//初始楼层的高亮显示
    {
       /* if(i == 1)//lightblue
        {
             btnlist.at(i)->setStyleSheet("#qt_toolbox_toolboxbutton{background:#1E90FF}");
             QList<QWidget *>  widlist = btnlist.at(i)->findChildren<QWidget *>();
             QList<QWidget *>::iterator iter = widlist.begin();
             QList<QWidget *>::iterator iterend = widlist.end();
             iterend--;
             while(iter != iterend)
             {
                QWidget * wid  = *iter;
                if(!(wid->objectName() == "alarmcondition_toolbutton"))
                    wid->setEnabled(true);
                wid->setStyleSheet("QWidget{color:white}");
                 ++iter;
             }
             QWidget * btn = btnlist.at(i)->findChild<QWidget *>("alarmcondition_toolbutton");
             btn->setStyleSheet("QWidget{color:black}");
        }
        else
        {*/
             btnlist.at(i)->setStyleSheet("#qt_toolbox_toolboxbutton{background:lightblue}");
             QList<QWidget *>  widlist = btnlist.at(i)->findChildren<QWidget *>();
             QList<QWidget *>::iterator iter = widlist.begin();
             while(iter != widlist.end())
             {
                QWidget * wid  = *iter;
//                if(!(wid->objectName() == "alarmcondition_toolbutton"))
//                    wid->setEnabled(false);
                QString widobjname = wid->objectName();
                if(widobjname != "state_frame" && widobjname != "reside_label" &&widobjname != "holiday_label" &&widobjname != "order_label" &&widobjname != "available_label" )
                    wid->setStyleSheet("QWidget{color:black}");
                 if(widobjname == "state_frame" || widobjname == "reside_label" ||widobjname == "holiday_label" ||widobjname == "order_label" ||widobjname == "available_label" )
                    wid->setEnabled(true);
                 ++iter;
             }
        //}
    }
    gvw->refreshBuildingStructrue();
    //gvw->show();
    /*for(int i = 0; i < btnlist.count(); i++)
    {
        btnlist.at(i)->setEnabled(false);
    }*/

    qDebug()<<"homepagwidthandheightinit"<<this->width()<<this->height();
    refreshtimer = new QTimer(this);
   // connect(refreshtimer,SIGNAL(timeout()),this,SLOT(onRefreshTimer()));
    //refreshtimer->start(5000);
    //onRefreshTimer();
    for(int i = 0; i < btnlist.count(); i++)
    {
        btnlist.at(i)->installEventFilter(this);
       // if(i % 2 == 0)
       btnlist.at(i)->hide();
    }
    oldparentindex = -1;
    oldcurindex = -1;
    btnlist.at(0)->setVisible(false);
    connect(this,SIGNAL(currentChanged(int)),this,SLOT(onCurrentChanged(int)));
}

void HomePage::onCurrentChanged(int index)
{

    btnlist.at(0)->setVisible(false);
    for(int i=1;i<btnlist.count();i++)
    {
        qDebug()<<"oncurrentchanged*******"<<index;
        if(i==index)
            btnlist.at(i)->setVisible(true);
        else
            btnlist.at(i)->setVisible(false);
    }
}
HomePage:: ~HomePage()
{
    QString dbname = db->connectionName();
    db->close();
    delete db;
    db = NULL;
    QSqlDatabase::removeDatabase(dbname);
}

void HomePage::mousePressEvent(QMouseEvent * event)
{
    qDebug()<<"mousepressevent";
    event->accept();
}
void HomePage::resizeEvent(QResizeEvent * event)
{
    QToolBox::resizeEvent(event);
    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(0));
    GeneralViewWidget * gvw = qobject_cast<GeneralViewWidget *>(scrollarea->widget());
    gvw->refreshBuildingStructrue();
    gvw->show();
}

bool HomePage::eventFilter(QObject* object, QEvent* event)
{
    if((event->type() == QEvent::MouseButtonDblClick ||event->type() == QEvent::MouseButtonPress))
    {
         event->accept();
         return true;
    }
    else
    {
        return QToolBox::eventFilter(object,event);
    }
}

void HomePage::connectToDatabase()
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL","homepage"));
    db->setHostName(serverIP);
    db->setPort(3306);
    db->setDatabaseName(globalDBName);
    db->setUserName(globalUserName);
    db->setPassword(globalUserName);
    QSqlError err;
    if(db->open())
    {
        err = db->lastError();
        dbisconnected = true;
        return;
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！homepage1","确定");
        }

    }
}
//void HomePage::onRefreshTimer()
//{

//    QDateTime starttime = QDateTime::currentDateTime();
//    if(db->open())
//    {
//        if(!dbisconnected)
//        {
//            dbisconnected = true;
//            raao->setAppEnable(true);
//        }

//        totalallcount = 0;
//        totalnormalcount = 0;
//        totalofflinecount = 0;
//        totalfirstalarmcount = 0;
//        totalsecondalarmcount = 0;
//        for(int i = 1; i < buildingnum + 1; i++)
//        {
//            allcount = 0;
//            normalcount = 0;
//            offlinecount = 0;
//            firstalarmcount = 0;
//            secondalarmcount = 0;
//            QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(i));
//            BuildingSpliter * bdsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//            int floorsnum = (bdsplitter->floors).size();//注意floors的增加和减少问题
//            for(int j = 0; j < floorsnum; j++)
//            {
//                QListWidget * rooms = (bdsplitter->floors).at(j)->rooms;
//                int roomsnum = rooms->count();
//                bdsplitter->floors.at(j)->normalcount = 0;
//                bdsplitter->floors.at(j)->offlinecount = 0;
//                bdsplitter->floors.at(j)->firstalarmcount = 0;
//                bdsplitter->floors.at(j)->secondalarmcount = 0;
//                for(int k = 0; k < roomsnum; k++)
//                {
//                    int curstate = 0;
//                    switch(curstate)
//                    {
//                    case normal:
//                        (bdsplitter->floors.at(j)->normalcount)++;
//                        break;
//                    case offline:
//                        (bdsplitter->floors.at(j)->offlinecount)++;
//                        break;
//                    case firstalarm:
//                        (bdsplitter->floors.at(j)->firstalarmcount)++;
//                        break;
//                    case secondalarm:
//                        (bdsplitter->floors.at(j)->secondalarmcount)++;
//                        break;
//                    }
//                }
//                normalcount += bdsplitter->floors.at(j)->normalcount;
//                offlinecount += bdsplitter->floors.at(j)->offlinecount;
//                firstalarmcount += bdsplitter->floors.at(j)->firstalarmcount;
//                secondalarmcount += bdsplitter->floors.at(j)->secondalarmcount;
//                //刷新楼层房间状态数统计
//                bdsplitter->floors.at(j)->refreshRoomStateStatistics();
//                //筛选楼层信息
//                bdsplitter->floors.at(j)->roomWidgetStateFilter(bdsplitter->floors.at(j)->state);
//            }
//            allcount =  normalcount + offlinecount + firstalarmcount + secondalarmcount;
//            totalnormalcount += normalcount;
//            totalofflinecount += offlinecount;
//            totalfirstalarmcount += firstalarmcount;
//            totalsecondalarmcount += secondalarmcount;
//            totalallcount += allcount;
//            refreshBuildingStateStatistics(btnlist.at(i));
//        }
//        qDebug()<<"onfreshtimer";
//        //刷新系统概览这一页面
//        qDebug()<<totalnormalcount<<totalofflinecount<<totalfirstalarmcount<<totalsecondalarmcount;
//        QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(0));
////        (qobject_cast<GeneralViewWidget *>(scrollarea->widget()))->refreshGeneralViewStatistics();
//        //发送报警灯信号
//       // emit alarmLightSignal();
//    }
//    else
//    {
//        if(dbisconnected)
//        {
//            dbisconnected = false;
//            raao->setAppEnable(false);
//            QMessageBox::warning(0,"警告","数据库连接失败！homepage2","确定");
//        }
//    }
//   qDebug()<<"homepage fresh"<<starttime.msecsTo(QDateTime::currentDateTime());
//}
void HomePage::refreshBuildingStateStatistics(QAbstractButton * btn)
{
//    QString allstr = (allcount >= 10) ? QString::number(allcount):"0"+ QString::number(allcount);
//    QString normalstr = (normalcount >= 10) ? QString::number(normalcount):"0"+ QString::number(normalcount);
//    QString offlinestr = (offlinecount >= 10) ? QString::number(offlinecount):"0"+ QString::number(offlinecount);
//    QString firstalarmstr = (firstalarmcount >= 10) ? QString::number(firstalarmcount):"0"+ QString::number(firstalarmcount);
//    QString secondalarmallstr = (secondalarmcount >= 10) ? QString::number(secondalarmcount):"0"+ QString::number(secondalarmcount);

//    QCheckBox * all_radiobutton = btn->findChild<QCheckBox *>("all_radiobutton");
//    QCheckBox * normal_radiobutton = btn->findChild<QCheckBox *>("normal_radiobutton");
//    QCheckBox * offline_radiobutton = btn->findChild<QCheckBox *>("offline_radiobutton");
//    QCheckBox * firstalarm_radiobutton = btn->findChild<QCheckBox *>("firstalarm_radiobutton");
//    QCheckBox * secondalarm_radiobutton = btn->findChild<QCheckBox *>("secondalarm_radiobutton");
//    QLabel * reside_label = btn->findChild<QLabel *>("reside_label");
//    QLabel * order_label = btn->findChild<QLabel *>("order_label");
//    QLabel * available_label = btn->findChild<QLabel *>("available_label");

//    all_radiobutton->setText("全部("+allstr+")");
//    normal_radiobutton->setText("正常("+normalstr+")");
//    offline_radiobutton->setText("离线("+offlinestr+")");
//    firstalarm_radiobutton->setText("重要("+firstalarmstr+")");
//    secondalarm_radiobutton->setText("普通("+secondalarmallstr+")");
//    if(allcount != 0)
//    {
//        normalrate_label->setText("正常率=" + QString::number(normalcount*100/float(allcount),'f',1)+"%");
//        order_label->setText("报警率=" +QString::number((firstalarmcount + secondalarmcount)*100/float(allcount),'f',1) +"%");
//        available_label->setText("离线率=" +QString::number(offlinecount*100/float(allcount),'f',1) +"%");
//    }
//    else
//    {
//        normalrate_label->setText("正常率=0.0%");
//        order_label->setText("报警率=0.0%");
//        available_label->setText("离线率=0.0%");
//    }
}

void HomePage::loadBuildingInfo(QStringList & buildingmaptofloor)
{
    /*QFile file("buildingmaptofloor.dat");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"wenjiandakaichenggong";
        QTextStream ts(&file);
        while(!ts.atEnd())
        {
            buildingmaptofloor<<ts.readLine();
        }
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        return;
    }
    file.close();*/

    if(db->open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        //构建楼宇
        query.prepare("SELECT building_no,floorlist FROM buildingmaptofloor");
        query.exec();
        while(query.next())
        {
            buildingmaptofloor<<(query.value(0).toString()+":"+query.value(1).toString());

        }
        query.clear();
        query.finish();
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

void HomePage::createBuildingState(QAbstractButton * btn,QString buildingname)
{
    btn->setFixedHeight(25);
    QHBoxLayout * hbl = new QHBoxLayout(btn);
    hbl->addSpacing(5);
    hbl->setMargin(0);
    hbl->setSpacing(25);
    QLabel * buildingname_label = new QLabel(buildingname,btn);//需要楼名,注意建楼层名与建楼层的顺序是否一致
    buildingname_label->setObjectName("buildingname_label");
    buildingname_label->setAlignment(Qt::AlignCenter);
    buildingname_label->setMinimumWidth(61);

    RoomStateWidget *  reside_roomstatewidget = new RoomStateWidget(reside,btn);
    RoomStateWidget * holiday_roomstatewidget = new RoomStateWidget(holiday,btn);
    RoomStateWidget * available_roomstatewidget = new RoomStateWidget(available,btn);
    RoomStateWidget * order_roomstatewidget = new RoomStateWidget(order,btn);

    QHBoxLayout * frame_hbl = new QHBoxLayout;
    QFrame * state_frame = new QFrame(btn);
    state_frame->setFixedWidth(340);
    state_frame->setObjectName("state_frame");
    state_frame->setStyleSheet("QFrame#state_frame{border-image:url(images/curtime.png);}");
    //state_frame->setFrameShape(QFrame::Box);
   // state_frame->setFrameShadow(QFrame::Raised);
    //state_frame->setLineWidth(2);
    QHBoxLayout * staterate_hbl = new QHBoxLayout;
    QLabel * reside_label = new QLabel(state_frame);
    reside_label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    reside_label->setObjectName("reside_label");
    reside_label->setText("入住(0)");
    QLabel * holiday_label = new QLabel(state_frame);
    holiday_label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    holiday_label->setObjectName("holiday_label");
    holiday_label->setText("请假(0)");
    QLabel * order_label = new QLabel(state_frame);
    order_label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    order_label->setObjectName("order_label");
    order_label->setText("预约(0)");
    QLabel * available_label = new QLabel(state_frame);
    available_label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    available_label->setObjectName("available_label");
    available_label->setText("空闲(0)");
    staterate_hbl->setMargin(0);
    staterate_hbl->setSpacing(4);
    staterate_hbl->addSpacing(35);
    staterate_hbl->addWidget(reside_roomstatewidget);
    staterate_hbl->addWidget(reside_label);
    staterate_hbl->addWidget(holiday_roomstatewidget);
    staterate_hbl->addWidget(holiday_label);
    staterate_hbl->addWidget(order_roomstatewidget);
    staterate_hbl->addWidget(order_label);
    staterate_hbl->addWidget(available_roomstatewidget);
    staterate_hbl->addWidget(available_label);
    staterate_hbl->addSpacing(30);
    state_frame->setLayout(staterate_hbl);
    frame_hbl->addWidget(state_frame);
    frame_hbl->setMargin(1);

    QHBoxLayout *search_hbl = new QHBoxLayout;
    search_hbl->setSpacing(20);
    search_hbl->addSpacing(30);
    QCheckBox *all_check = new QCheckBox(tr("全部"),btn);
    all_check->setChecked(true);
    QCheckBox *one_check = new QCheckBox(tr("单人间"),btn);
    QCheckBox *two_check = new QCheckBox(tr("双人间"),btn);
    QCheckBox *four_check = new QCheckBox(tr("四人间"),btn);
    QCheckBox *six_check = new QCheckBox(tr("六人间"),btn);
    QPushButton *btn_search = new QPushButton(tr("查询"),btn);
    btn_search->setObjectName("btn_search");
    search_hbl->addWidget(all_check);
    search_hbl->addWidget(one_check);
    search_hbl->addWidget(two_check);
    search_hbl->addWidget(four_check);
    search_hbl->addWidget(six_check);
    search_hbl->addWidget(btn_search);
    hbl->addWidget(buildingname_label);
    hbl->addSpacing(4);
    hbl->addLayout(frame_hbl);   
    hbl->addLayout(search_hbl);

   // hbl->addWidget(alarmcondition_toolbutton);
//    hbl->addLayout(alarmcondition_hbl);
    /*hbl->addSpacing(15);
    hbl->addLayout(frame_hbl);*/
    hbl->addStretch();
    /*hbl->addLayout(pm_hbl);*/
}

//void HomePage::changeSearchConditon()
//{
//    qDebug()<<"homepage"<<"changeSearchConditon";
//    QScrollArea * scrollarea = qobject_cast<QScrollArea *>(currentWidget());
//    BuildingSpliter * buildingsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    RoomStateSearchDialog * temprssd = rssds.at(currentIndex() - 1);
//    //int floorscount = rssds.size();
//    qDebug()<<"rssds.size"<<rssds.size();
//    for(int i = 0; i < buildingsplitter->count(); i++)
//    {
//       FloorFrameWidget * ffw = qobject_cast<FloorFrameWidget *>(buildingsplitter->widget(i));
//       ffw->state = rssdstate;
//       ffw->currssdstate = temprssd->rssdstate;
//       ffw->andbits = temprssd->andbits;
//       ffw->orbits = temprssd->orbits;
//       ffw->advanceCondition = temprssd->advancedcondtion;

//       ffw->args = temprssd->args;
////       ffw->roomWidgetStateFilter(rssdstate);
//       qDebug()<<rssdstate<<ffw->advanceCondition;
//    }
//}

void HomePage::highlightFloor(int index)
{
    qDebug()<<index;
//    btnlist = findChildren<QAbstractButton*>(tr("qt_toolbox_toolboxbutton"));
//    QCheckBox * tempchekbox = 0;
    for(int i = 1;i < buildingnum + 1 ;i++)
    {
        if(i == index)//lightblue
        {
            btnlist.at(i)->setStyleSheet("#qt_toolbox_toolboxbutton{background:#1E90FF}");
            QList<QWidget *>  widlist = btnlist.at(i)->findChildren<QWidget *>();
            QList<QWidget *>::iterator iter = widlist.begin();
            QList<QWidget *>::iterator iterend = widlist.end();
            while(iter != iterend)
            {
               QWidget * wid  = *iter;
//               if(!(wid->objectName() == "alarmcondition_toolbutton"))
//               {
//                   wid->setEnabled(true);
//               }
//               if(wid->objectName() == "alarmcondition_radiobutton")
//               {
//                   tempchekbox = qobject_cast<QCheckBox *>(*iter);
//               }
               QString widobjname = wid->objectName();
               if(widobjname != "state_frame" && widobjname != "reside_label" && widobjname != "holiday_label" &&widobjname != "order_label" &&widobjname != "available_label" &&widobjname != "btn_search")
                wid->setStyleSheet("QWidget{color:white}");
               /*if(widobjname == "state_frame" || widobjname == "normalrate_label" ||widobjname == "order_label" ||widobjname == "available_label" )
                  wid->setEnabled(true);*/
                ++iter;
            }
            // btnlist.at(i)->setEnabled(false);
//            QWidget * btn =btnlist.at(i)->findChild<QWidget *>("alarmcondition_toolbutton");
//            btn->setStyleSheet("QWidget{color:black}");
//            if(tempchekbox&&tempchekbox->isChecked())
//            {
//                btn->setEnabled(true);
//            }
        }
        else
        {
            btnlist.at(i)->setStyleSheet("#qt_toolbox_toolboxbutton{background:lightblue}");
            QList<QWidget *>  widlist = btnlist.at(i)->findChildren<QWidget *>();
            QList<QWidget *>::iterator iter = widlist.begin();
            while(iter != widlist.end())
            {
               QWidget * wid  = *iter;
//               if(!(wid->objectName() == "alarmcondition_toolbutton"))
//                   wid->setEnabled(false);
               QString widobjname = wid->objectName();
               if(widobjname != "state_frame" && widobjname != "reside_label" && widobjname != "holiday_label" &&widobjname != "order_label" &&widobjname != "available_label" &&widobjname != "btn_search")
                   wid->setStyleSheet("QWidget{color:black}");
               if(widobjname == "state_frame" || widobjname == "reside_label" || widobjname != "holiday_label" ||widobjname == "order_label" ||widobjname == "available_label" )
                  wid->setEnabled(true);
                  // wid->setEnabled(true);
               ++iter;
            }
           //btnlist.at(i)->setEnabled(false);
//            QWidget * btn =btnlist.at(i)->findChild<QWidget *>("alarmcondition_toolbutton");
//            btn->setEnabled(false);
        }
    }
}
void HomePage::expandingBuilding(int index)
{
    //index++;
    qDebug()<<"expandingbuiding******";
    if(oldparentindex != -1 && oldcurindex != -1)
    {
        QScrollArea *oldscrollarea = qobject_cast<QScrollArea *>(this->widget(oldparentindex));
        BuildingSpliter * oldspliter = qobject_cast< BuildingSpliter *>(oldscrollarea->widget());
        //qDebug()<<scrollarea->objectName();
        qDebug()<<"oldcurindex"<<oldcurindex;
        if(oldscrollarea)
        {
             if(oldcurindex >= 0 && oldcurindex < oldspliter->floors.count())
                 oldspliter->floors.at(oldcurindex)->rooms->setStyleSheet("#rooms{background-color:#FFFFE0}");
        }
    }
    oldparentindex = -1;
    oldcurindex = -1;

    qDebug()<<"setcurrentindexbefore";
    this->setCurrentIndex(index);
    qDebug()<<"setcurrentindexafter";
}

void HomePage::scrollToFloor(int parentindex,int curindex)
{
    //parentindex++;//新添加
//    qDebug()<<"scrolltofloor";
//    if(oldparentindex != -1 && oldcurindex != -1)
//    {
//        QScrollArea *oldscrollarea = qobject_cast<QScrollArea *>(this->widget(oldparentindex));
//        BuildingSpliter * oldspliter = qobject_cast< BuildingSpliter *>(oldscrollarea->widget());
//        qDebug()<<"oldcurindex"<<oldcurindex<<"olderparentindex"<<oldparentindex;
//        if(oldscrollarea)
//        {
//            if(oldcurindex >= 0 && oldcurindex < oldspliter->floors.count())
//            oldspliter->floors.at(oldcurindex)->rooms->setStyleSheet("#rooms{background-color:#FFFFE0}");
//        }
//    }
//    qDebug()<<"scorlltofloor2";
//    this->setCurrentIndex(parentindex);
//    qDebug()<<"parentindex"<<"curindex"<<parentindex<<curindex;
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(parentindex));
//    BuildingSpliter * curspliter = qobject_cast< BuildingSpliter *>(scrollarea->widget());
//    /*int height = scrollarea->widget()->height();
//    int count = static_cast<QSplitter *>(scrollarea->widget())->count();*/
//    int height = curspliter->height();
//    int count = curspliter->count();
//    qDebug()<<scrollarea->objectName();
//    if(scrollarea)
//    {
//        scrollarea->verticalScrollBar()->setSliderPosition(height*curindex/((float)count));
//        if(curindex >= 0 && curindex < curspliter->floors.count())
//            curspliter->floors.at(curindex)->rooms->setStyleSheet("#rooms{background-color:white}");
//    }
//    oldparentindex = parentindex;
//    oldcurindex = curindex;
}

void HomePage::addBuilding(QString buildingname)
{
//    QScrollArea * scrollarea = new QScrollArea(this);
//    scrollarea->setWidgetResizable(true);
//    BuildingSpliter * splitter = new BuildingSpliter(scrollarea);
//    connect(splitter,SIGNAL(openViewSignal(int)),this,SIGNAL(openViewSignal(int)));
//    //splitter->constructBuilding();
//    scrollarea->setWidget(splitter);
//    this->addItem(scrollarea,"");
//    btnlist = findChildren<QAbstractButton*>(tr("qt_toolbox_toolboxbutton"));
//    createBuildingState(btnlist.last(),buildingname);
//    buildingnum++;
//    btnlist.last()->setStyleSheet("#qt_toolbox_toolboxbutton{background:lightblue}");
//    btnlist.last()->hide();
//    for(int i = 0; i < btnlist.count(); i++)
//    {
//        btnlist.at(i)->installEventFilter(this);
//    }
//    highlightFloor(currentIndex());
   // this->setCurrentIndex(this->count() - 1);
    /*QList<QWidget *>  widlist = btnlist.last()->findChildren<QWidget *>();
    QList<QWidget *>::iterator iter = widlist.begin();
    while(iter != widlist.end())
    {
       QWidget * wid  = *iter;
       wid->setStyleSheet("QWidget{color:black}");
        ++iter;
    }*/
    QScrollArea *firstscrollarea = qobject_cast<QScrollArea *>(this->widget(0));
//    (qobject_cast<GeneralViewWidget *>(firstscrollarea->widget()))->refreshBuildingStructrue();
//    onRefreshTimer();
}
void HomePage::delBuilding(int index)
{
    //这里注意在只有一栋楼要如何处理
    //index++;
//    qDebug()<<"homepage"<<index;
//    qDebug()<<"delbuilding"<<index;
//    QScrollArea * scrollarea = qobject_cast<QScrollArea *>(this->widget(index));
//    qDebug()<<"currentindex"<<currentIndex();
//    if(currentIndex() == index)
//    {
//        if(index == 1 && count()>2)
//            this->setCurrentIndex(index + 1);
//        else
//        {
//            this->setCurrentIndex(index - 1);
//        }
//    }
//     qDebug()<<"after delbuilding1";
//    //删除对应的条件查询框，功能是否健全有待完善
//    qDebug()<<"after delbuilding2";
//    //RoomStateSearchDialog * temprssd = rssds.takeAt(index - 1);//最开始是个空的
//    //delete temprssd;

//    qDebug()<<"after delbuilding";
//     qDebug()<<"sadhashashsah";
//    this->removeItem(index);
//     qDebug()<<"builingnum"<<buildingnum;
//    delete scrollarea;
//    buildingnum--;
//    qDebug()<<"builingnum"<<buildingnum;
//    btnlist = findChildren<QAbstractButton*>(tr("qt_toolbox_toolboxbutton"));
//    QScrollArea *firstscrollarea = qobject_cast<QScrollArea *>(this->widget(0));
//    (qobject_cast<GeneralViewWidget *>(firstscrollarea->widget()))->refreshBuildingStructrue();
//    onRefreshTimer();
}

void HomePage::addFloor(int parentindex,int floornum,int index)
{
//    qDebug()<<"addlfloor1";
//    //parentindex++;
//    qDebug()<<parentindex<<floornum<<index;
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(parentindex));
//    scrollarea->hide();
//    BuildingSpliter * buildingsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    qDebug()<<"addlfloor2";
//    FloorFrameWidget * ffw = new FloorFrameWidget(floornum,buildingsplitter);
//    ffw->setDataBase(this);
//    qDebug()<<"addlfloor3";
//    buildingsplitter->floors.append(ffw);

//   // connect(ffw,SIGNAL(openViewSignal(int)),buildingsplitter,SIGNAL(openViewSignal(int)));
//    buildingsplitter->insertWidget(index,ffw);
//    buildingsplitter->handle(index)->setEnabled(false);
//    buildingsplitter->floorNumIncrease();
//    scrollarea->show();
//    QScrollArea *firstscrollarea = qobject_cast<QScrollArea *>(this->widget(0));
//    (qobject_cast<GeneralViewWidget *>(firstscrollarea->widget()))->refreshBuildingStructrue();
//    onRefreshTimer();
}

void HomePage::delFloor(int parentindex,int index)
{
    //parentindex++;
//    qDebug()<<parentindex<<index;
//   // oldcurindex = -1;

//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(parentindex));
//    BuildingSpliter * buildingsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    FloorFrameWidget * ffw = qobject_cast<FloorFrameWidget *>(buildingsplitter->widget(index));
//    buildingsplitter->floors.removeAt(buildingsplitter->floors.indexOf(ffw));
//    delete buildingsplitter->widget(index);
//    buildingsplitter->floorNumDecrease();
//    qDebug()<<"delfloor1";
//    QScrollArea *firstscrollarea = qobject_cast<QScrollArea *>(this->widget(0));
////    (qobject_cast<GeneralViewWidget *>(firstscrollarea->widget()))->refreshBuildingStructrue();
//    qDebug()<<"delfloor2";
//    onRefreshTimer();

}
void HomePage::addRoom(int parentindex,int index,QString roomname)
{
    //parentindex++;
//    qDebug()<<parentindex<<index<<roomname<<"haha";
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(parentindex));
//    BuildingSpliter * buildingsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    QString addbuidingname = (btnlist.at(parentindex)->findChild<QLabel *>("buildingname_label"))->text();
//    FloorFrameWidget * floorframe = qobject_cast<FloorFrameWidget *>(buildingsplitter->widget(index));


//    qDebug()<<addbuidingname+floorframe->floorname_label->text().remove(" ")+roomname;
//    QListWidgetItem * item = new QListWidgetItem;

//    int i = 0;
//    for(i = 0;i < floorframe->rooms->columnCount()-1; i++)
//    {
//        RoomWidget * temrw = qobject_cast<RoomWidget *>(floorframe->rooms->itemWidget(floorframe->rooms->item(i)));
//        qDebug()<<"temrw->roomname"<<temrw->roomname;
//        QString str = temrw->roomname;
//        qDebug();
//        if(QString::compare(str.split("楼").last(),roomname,Qt::CaseInsensitive) >= 0)
//        {
//            break;
//        }
//    }
//    qDebug()<<"homepageaddRoom"<<i<<floorframe->rooms->count();
//    /*if(i != 0 && i == floorframe->rooms->count())
//    {
//        floorframe->rooms->insertItem(i - 1,item);
//    }
//    else
//        floorframe->rooms->insertItem(i,item);*/
//    floorframe->rooms->insertItem(i,item);
//     qDebug()<<"homepageaddRoom";
//    QFont font = item->font();
//    font.setPixelSize(30);
//    item->setFont(font);
//    item->setText("    ");
//    floorframe->rooms->setItemWidget(item,new RoomWidget(addbuidingname+floorframe->floorname_label->text().remove(" ")+roomname,offline,floorframe->rooms));
//    floorframe->offlinecount++;
//    floorframe->allcount++;
//    onRefreshTimer();
}

void HomePage::delRoom(int parentindex,int index,QString roomname)//隐藏一个占用CPU的隐患待查证
{
    //parentindex++;
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(this->widget(parentindex));
//    BuildingSpliter * buildingsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    FloorFrameWidget * floorframe = qobject_cast<FloorFrameWidget *>(buildingsplitter->widget(index));
//    QListWidget * roomlistwidget = floorframe->rooms;
//    int itemcount =  roomlistwidget->count();
//    int i = 0;
//    for( i = 0; i < itemcount ; i++)
//    {
//        if((qobject_cast<RoomWidget *>(roomlistwidget->itemWidget(roomlistwidget->item(i))))->roomname.split("楼").last() == roomname)
//            break;
//    }
//    switch((qobject_cast<RoomWidget *>(roomlistwidget->itemWidget(roomlistwidget->item(i))))->state)
//    {
//    case normal:
//        (floorframe->normalcount)--;
//        break;
//    case offline:
//        (floorframe->offlinecount)--;
//        break;
//    case firstalarm:
//        (floorframe->firstalarmcount)--;
//        break;
//    case secondalarm:
//        (floorframe->secondalarmcount)--;
//        break;
//    }

//    floorframe->allcount--;
//    roomlistwidget->removeItemWidget(roomlistwidget->item(i));//一定会找到匹配项
//    delete roomlistwidget->takeItem(i);
//    onRefreshTimer();
}

//void HomePage::setAlarmRadioButtonChecked(QString objname)
//{
//    qDebug()<<tr("重要普通状态");
//    qDebug()<<"homepage";
//    qDebug()<<"setAlarmRadioButtonChecked";
//    QCheckBox * radiobutton = qobject_cast<QCheckBox *>(sender());
//    QList<QCheckBox *> radiobuttons = radiobutton->parentWidget()->findChildren<QCheckBox *>();
//    for(int i = 0; i < radiobuttons.size(); i++)
//    {
//        radiobuttons.at(i)->setChecked(false);
//    }
//    (radiobutton->parentWidget()->findChild<QToolButton *>("alarmcondition_toolbutton"))->setEnabled(false);
//    QCheckBox * checked_radiobutton = radiobutton->parentWidget()->findChild<QCheckBox *>(objname);
//    checked_radiobutton->setChecked(true);
//    qDebug()<<"setAlarmRadioButtonChecked"<<"homepage";
//}

//void HomePage::setOtherRadioButtonChecked(bool flag)
//{
//    qDebug()<<tr("其他状态");
//    QCheckBox * alarm_radiobutton = qobject_cast<QCheckBox *>(sender());
//    QCheckBox * all_radiobutton = alarm_radiobutton->parentWidget()->findChild<QCheckBox *>("all_radiobutton");
//    QCheckBox * normal_radiobutton = alarm_radiobutton->parentWidget()->findChild<QCheckBox *>("normal_radiobutton");
//    QCheckBox * offline_radiobutton = alarm_radiobutton->parentWidget()->findChild<QCheckBox *>("offline_radiobutton");
//    QCheckBox * alarmcondition_radiobutton = alarm_radiobutton->parentWidget()->findChild<QCheckBox *>("alarmcondition_radiobutton");
//    all_radiobutton->setChecked(flag);
//    normal_radiobutton->setChecked(flag);
//    offline_radiobutton->setChecked(flag);h
//    alarmcondition_radiobutton->setChecked(flag);
//    (alarm_radiobutton->parentWidget()->findChild<QToolButton *>("alarmcondition_toolbutton"))->setEnabled(flag);
//}


//void HomePage::allRadioButton()
//{
//    qDebug()<<tr("全部");
//    setAlarmRadioButtonChecked("all_radiobutton");
//    //注意此处，一定是当前的widget
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(currentWidget());
//    BuildingSpliter * bdsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    int floorsnum = (bdsplitter->floors).size();//注意floors的增加和减少问题
//    qDebug()<<"floorsnum"<<floorsnum;
//    for(int i = 0; i < floorsnum; i++)
//    {
////        (bdsplitter->floors).at(i)->allRadioButton();
//    }
//}

//void HomePage::normalRadioButton()
//{
//    qDebug()<<tr("正常");
//    setAlarmRadioButtonChecked("normal_radiobutton");
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(currentWidget());
//    BuildingSpliter * bdsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    int floorsnum = (bdsplitter->floors).size();//注意floors的增加和减少问题
//    qDebug()<<"floorsnum"<<floorsnum;
//    for(int i = 0; i < floorsnum; i++)
//    {
////        (bdsplitter->floors).at(i)->normalRadioButton();
//    }
//}

//void HomePage::offlineRadioButton()
//{
//    qDebug()<<tr("离线");
//    setAlarmRadioButtonChecked("offline_radiobutton");
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(currentWidget());
//    BuildingSpliter * bdsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    int floorsnum = (bdsplitter->floors).size();//注意floors的增加和减少问题
//    qDebug()<<"floorsnum"<<floorsnum;
//    for(int i = 0; i < floorsnum; i++)
//    {

////        (bdsplitter->floors).at(i)->offlineRadioButton();
//    }
//}

//void HomePage::firstalarmRadioButton()
//{
//    qDebug()<<tr("重要");
//    setOtherRadioButtonChecked(false);
//    QCheckBox * firstalarm_radiobutton = qobject_cast<QCheckBox *>(sender());
//    QCheckBox * secondalarm_radiobutton = firstalarm_radiobutton->parentWidget()->findChild<QCheckBox *>("secondalarm_radiobutton");
//    if(!secondalarm_radiobutton->isChecked())
//    {
//        firstalarm_radiobutton->setChecked(true);
//    }

//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(currentWidget());
//    BuildingSpliter * bdsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    int floorsnum = (bdsplitter->floors).size();//注意floors的增加和减少问题
//    qDebug()<<"floorsnum"<<floorsnum;
//    for(int i = 0; i < floorsnum; i++)
//    {
////        if(firstalarm_radiobutton->isChecked())
////            (bdsplitter->floors).at(i)->firstalarm_radiobutton->setChecked(true);
////        else
////            (bdsplitter->floors).at(i)->firstalarm_radiobutton->setChecked(false);
////        (bdsplitter->floors).at(i)->firstalarmRadioButton();
//    }
//}

//void HomePage::secondalarmRadioButton()
//{
//    qDebug()<<tr("普通");
//    setOtherRadioButtonChecked(false);
//    QCheckBox * secondalarm_radiobutton = qobject_cast<QCheckBox *>(sender());
//    QCheckBox * firstalarm_radiobutton = secondalarm_radiobutton->parentWidget()->findChild<QCheckBox *>("firstalarm_radiobutton");
//    if(!firstalarm_radiobutton->isChecked())
//    {
//        secondalarm_radiobutton->setChecked(true);
//    }
//    QScrollArea *scrollarea = qobject_cast<QScrollArea *>(currentWidget());
//    BuildingSpliter * bdsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    int floorsnum = (bdsplitter->floors).size();//注意floors的增加和减少问题
//    qDebug()<<"floorsnum"<<floorsnum;
//    for(int i = 0; i < floorsnum; i++)
//    {
////        if(secondalarm_radiobutton->isChecked())
////            (bdsplitter->floors).at(i)->secondalarm_radiobutton->setChecked(true);
////        else
////            (bdsplitter->floors).at(i)->secondalarm_radiobutton->setChecked(false);
////        (bdsplitter->floors).at(i)->secondalarmRadioButton();
//    }
//}

//void HomePage::alarmconditionRadioButton()
//{
//    qDebug()<<tr("条件查询");
//    setAlarmRadioButtonChecked("alarmcondition_radiobutton");

//    QCheckBox * alarmcondition_radiobutton = qobject_cast<QCheckBox *>(sender());
//    QToolButton * alarmcondition_toolbutton = alarmcondition_radiobutton->parentWidget()->findChild<QToolButton *>("alarmcondition_toolbutton");
//    if(alarmcondition_radiobutton->isChecked())
//    {
//        alarmcondition_toolbutton->setEnabled(true);
//    }
//    QScrollArea * scrollarea = qobject_cast<QScrollArea *>(currentWidget());
//    BuildingSpliter * buildingsplitter = qobject_cast<BuildingSpliter *>(scrollarea->widget());
//    for(int i = 0; i < buildingsplitter->count(); i++)
//    {
//        FloorFrameWidget * floorframe = qobject_cast<FloorFrameWidget *>(buildingsplitter->widget(i));
//        QCheckBox * all_radiobutton = floorframe->findChild<QCheckBox *>("all_radiobutton");
//        QCheckBox * normal_radiobutton = floorframe->findChild<QCheckBox *>("normal_radiobutton");
//        QCheckBox * firstalarm_radiobutton = floorframe->findChild<QCheckBox *>("firstalarm_radiobutton");
//        QCheckBox * secondalarm_radiobutton = floorframe->findChild<QCheckBox *>("secondalarm_radiobutton");
//        QCheckBox * offline_radiobutton = floorframe->findChild<QCheckBox *>("offline_radiobutton");
//        QCheckBox * alarmcondition_radiobutton = floorframe->findChild<QCheckBox *>("alarmcondition_radiobutton");
//        all_radiobutton->setChecked(false);
//        normal_radiobutton->setChecked(false);
//        offline_radiobutton->setChecked(false);
//        alarmcondition_radiobutton->setChecked(false);
//        firstalarm_radiobutton->setChecked(false);
//        secondalarm_radiobutton->setChecked(false);
//    }
//     qDebug()<<"alarmconditionRadioButton";
////    changeSearchConditon();
//}

/*#include "buildingspliter.h"
#include "floorframewidget.h"*/
BuildingToolBox::BuildingToolBox(QWidget *parent):
    QToolBox(parent){
    floornum = 0;
    this->setObjectName("BuildingToolBox");
//    this->setStyleSheet("#BuildingToolBox{border:4px groove #1E90FF}");
    this->setStyleSheet("#BuildingToolBox{border:4px groove #6E7F8A}");

}

void BuildingToolBox::constructBuilding(QString buildingtofloor){
    QStringList floorlist;
    QStringList builingandfloors;
    builingandfloors = buildingtofloor.split(":");
    QString buildingname = builingandfloors.first();
    QString floorstrnums = builingandfloors.last();
    if(!floorstrnums.isEmpty())//这里判断是否标准
    {
        floorlist = floorstrnums.split("*");//如果没有星号分隔符怎么弄
    }
    floornum = floorlist.size();
    QList<int> floornumlist;
    for(int i = 0; i < floornum; i++)
    {
        floornumlist<<floorlist.at(i).toInt();
    }
    qSort(floornumlist.begin(),floornumlist.end());

    qDebug()<<"floornum"<<floornum;

    for(int i = 0; i < floornum; i++)
    {
        QScrollArea * scrollarea = new QScrollArea(this);
        scrollarea->setWidgetResizable(true);
        FloorFrameWidget * ffw = new FloorFrameWidget(floornumlist.at(i),this);
        ffw->setDataBase((qobject_cast<HomePage *>(parent()->parent())));
        ffw->createRooms(buildingname,floornumlist.at(i));
        scrollarea->setWidget(ffw);
        this->addItem(scrollarea,"");

        btnlist = findChildren<QAbstractButton*>(tr("qt_toolbox_toolboxbutton"));
        createFloorState(btnlist.last(),floornumlist.at(i));
    }
}

void BuildingToolBox::createFloorState(QAbstractButton *btn, int floorNum){
    btn->setFixedHeight(25);
    QHBoxLayout * hbl = new QHBoxLayout(btn);
    hbl->addSpacing(5);
    hbl->setMargin(0);
    hbl->setSpacing(25);
    QLabel * label_floorName = new QLabel(floornames.at(floorNum-1),btn);

    bedReside = new RoomStateWidget(reside,this);
    bedHoliday = new RoomStateWidget(holiday,this);
    bedAvailable = new RoomStateWidget(available,this);
    bedOrder = new RoomStateWidget(order,this);
    bedNone = new RoomStateWidget(none,this);

    QHBoxLayout * frame_hbl = new QHBoxLayout;

    QHBoxLayout *reside_hbl = new QHBoxLayout;
    reside_hbl->setSpacing(4);
    reside_hbl->addSpacing(20);
    QLabel *labelReside = new QLabel(tr("入住"),this);
    reside_hbl->addWidget(bedReside);
    reside_hbl->addWidget(labelReside);

    QHBoxLayout *holiday_hbl =  new QHBoxLayout;
    holiday_hbl->setSpacing(4);
    holiday_hbl->addSpacing(20);
    QLabel *labelHoliday = new QLabel(tr("请假"),this);
    holiday_hbl->addWidget(bedHoliday);
    holiday_hbl->addWidget(labelHoliday);

    QHBoxLayout *order_hbl =  new QHBoxLayout;
    order_hbl->setSpacing(4);
    order_hbl->addSpacing(20);
    QLabel *labelOrder = new QLabel(tr("预约"),this);
    order_hbl->addWidget(bedOrder);
    order_hbl->addWidget(labelOrder);

    QHBoxLayout *available_hbl =  new QHBoxLayout;
    available_hbl->setSpacing(4);
    available_hbl->addSpacing(20);
    QLabel *labelAvailable = new QLabel(tr("空闲"),this);
    available_hbl->addWidget(bedAvailable);
    available_hbl->addWidget(labelAvailable);

    QHBoxLayout *none_hbl =  new QHBoxLayout;
    none_hbl->setSpacing(4);
    none_hbl->addSpacing(20);
    QLabel *labelNone = new QLabel(tr("无床"),this);
    none_hbl->addWidget(bedNone);
    none_hbl->addWidget(labelNone);

    frame_hbl->setSpacing(5);
    frame_hbl->addLayout(reside_hbl);
    frame_hbl->addLayout(holiday_hbl);
    frame_hbl->addLayout(order_hbl);
    frame_hbl->addLayout(available_hbl);
    frame_hbl->addLayout(none_hbl);

    hbl->addWidget(label_floorName);
    hbl->addLayout(frame_hbl);
    hbl->addStretch();
}

void BuildingToolBox::floorNumIncrease(){
    floornum++;
}

void BuildingToolBox::floorNumDecrease(){
    floornum--;
}

int BuildingToolBox::getFloorNum(){
    return floornum;
}

BuildingSpliter::BuildingSpliter(QWidget *parent):
    QSplitter(parent)
{
    floornum = 0;
    this->setOrientation(Qt::Vertical);
    this->setHandleWidth(1);
    this->setOpaqueResize(true);
    this->setChildrenCollapsible(false);
    this->setObjectName("splitter");
    this->setStyleSheet("#splitter{border:4px groove #1E90FF}");
}

void BuildingSpliter::floorNumIncrease()
{
    floornum++;
}

void BuildingSpliter::floorNumDecrease()
{
    floornum--;
}

void BuildingSpliter::constructBuilding(QString buildingtofloor)
{

    QStringList floorlist;
    QStringList builingandfloors;
    builingandfloors = buildingtofloor.split(":");
    QString buildingname = builingandfloors.first();
    QString floorstrnums = builingandfloors.last();
    if(!floorstrnums.isEmpty())//这里判断是否标准
    {
        floorlist = floorstrnums.split("*");//如果没有星号分隔符怎么弄
    }
    floornum = floorlist.size();
    QList<int> floornumlist;
    for(int i = 0; i < floornum; i++)
    {
        floornumlist<<floorlist.at(i).toInt();
    }
    qSort(floornumlist.begin(),floornumlist.end());

    qDebug()<<"floornum"<<floornum;

    for(int i = 0; i < floornum; i++)
    {
        FloorFrameWidget * ffw = new FloorFrameWidget(floornumlist.at(i),this);
        ffw->setDataBase((qobject_cast<HomePage *>(parent()->parent())));
        floors.append(ffw);
//        connect(ffw,SIGNAL(openViewSignal(int)),this,SIGNAL(openViewSignal(int)));
        ffw->createRooms(buildingname,floornumlist.at(i));
        this->addWidget(ffw);
        this->handle(i)->setEnabled(false);
    }

}

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QToolButton>
#include <QListWidget>
#include <QPainter>

#include <QListWidget>
#include <QListWidgetItem>
//#include "floorframewidget.h"
FloorFrameWidget::FloorFrameWidget(int floornum,QWidget *parent) ://楼层//没有问题
    QFrame(parent)
{
//    args.clear();
     rooms = new QListWidget(this);     
     rooms->setViewMode(QListView::IconMode);
//     rooms->setMovement(QListView::Free);
     rooms->setResizeMode(QListView::Adjust);
//     rooms->setWrapping(false);
//     rooms->setFlow(QListView::LeftToRight);
     rooms->setSpacing(1);
     QHBoxLayout * hbl = new QHBoxLayout;
     hbl->addWidget(rooms);
     this->setLayout(hbl);
     this->setObjectName("floorframewidget");
     this->setStyleSheet("#floorframewidget{background:#FDE7C9}");
}

void FloorFrameWidget::setDataBase(HomePage * ptr)
{
     homedb = ptr->db;
}

void FloorFrameWidget::createRooms(QString buildingname,int floornum)
{
    if(homedb->open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery roomquery(*homedb);
        //此处读取数据库会不会出问题？
        roomquery.prepare("SELECT room_name,room_direction,bitmap,bedStatus,bed_no FROM device_info WHERE building_no = ? AND floor_no = ? ORDER BY room_name ASC");
        roomquery.addBindValue(buildingname);
        roomquery.addBindValue(floornum);
        roomquery.exec();
        int roomnum = roomquery.size();
//        rooms->setColumnCount(roomnum);

        unsigned char j = 0;
        int bitMap = 0;
        int bedStatus = 0;
        int bedNo = 0;
        for(int i = 0;i < roomnum;i++)
        {
            roomquery.next();            
            QString roomName = roomquery.value(0).toString();
            QString direction = roomquery.value(1).toString();
            bitMap = roomquery.value(2).toInt();
            bedStatus = roomquery.value(3).toInt();
            bedNo = roomquery.value(4).toInt();                       
            for(j = 0;j<6;++j){
                if((bedStatus & 3) != 0 || (bitMap & 3) != 0){
                    QListWidgetItem *item = new QListWidgetItem("",rooms);
                    item->setSizeHint(QSize(180,220));
                    rooms->setItemWidget(item,new BedWidget(roomName,QString::number(j+1),NULL,NULL,rooms));
                    rooms->addItem(item);
                    qDebug()<<"bedwidget*********************"<<i<<"*"<<j;
//                if((bedStatus & 3) == 2)//请假
//                    item->setBackgroundColor(Qt::cyan);
//                else{
//                    if(j>=bedNo || ((bitMap & 3) == 0))
//                        item->setBackgroundColor(Qt::gray);
//                    else if((bitMap & 3)== 2)//入住
//                        item->setBackgroundColor(QColor(43,213,111));
//                    else if((bitMap & 3) == 1)//空闲
//                        item->setBackgroundColor(QColor(196,60,60));
//                    else //预约
//                        item->setBackgroundColor(QColor(255,165,0));
                }
                bedStatus >>= 2;
                bitMap  >>= 2;
            }
        }
        roomquery.clear();
        roomquery.finish();
        //globaldb.close();
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！homepage3","确定");
        }
    }
}

RoomStateWidget::RoomStateWidget(int state, QWidget *parent) ://房间状态标示
    QWidget(parent),state(state)
{
    this->setFixedSize(15,15);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void RoomStateWidget::paintEvent(QPaintEvent *event)
{
   // if(!isVisible()) return;
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    switch(state)
    {
    case reside:painter.setBrush(QColor(43,213,111));break;//深绿色
    case none:painter.setBrush(Qt::gray);break;
    case available:painter.setBrush(QColor(196,60,60));break;
    case order:painter.setBrush(QColor(255,165,0));break;//橙色
    case holiday:painter.setBrush(Qt::cyan);break;//淡蓝色
    default :painter.setBrush(Qt::green);
    }
    painter.setPen(Qt::NoPen);
    if(state)
    painter.drawRect(1,1,13,13);
    else
    {
        painter.setBrush(Qt::green);
        painter.drawRect(1,1,7,7);
        painter.setBrush(Qt::gray);
        painter.drawRect(8,1,7,7);
        painter.setBrush(Qt::red);
        painter.drawRect(1,8,7,7);
        painter.setBrush(QColor(255,165,0));
        painter.drawRect(8,8,7,7);
    }
}

BedWidget::BedWidget(QString roomName, QString bedNo, QString elderName, QString gender, QWidget *parent):
    QWidget(parent),
    roomName(roomName),
    bedNo(bedNo),
    elderName(elderName),
    gender(gender)
{  
    this->setFixedSize(201,251);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void BedWidget::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPixmap pix;
    pix.load("images/card.png");
    painter.drawPixmap(0,0,180,220,pix);
    QPen penId = painter.pen();
    penId.setWidth(2);
    penId.setColor(Qt::black);
    painter.setPen(penId);
    painter.drawText(80,20,tr("%1-%2").arg(roomName).arg(bedNo));
}

//#include <QPainter>
//#include <QRadialGradient>
//#include <QDebug>

//RoomWidget::RoomWidget(QString roomname,int state,QWidget *parent) ://小房子
//    QWidget(parent)
//{
//    this->roomname = roomname;
//    this->state = state;
//    //this->abnormalsensorcount = 0;

//    statebits.resize(19);
//    statebits.fill(0);

//    this->setFixedSize(textlenth+space+margin*2+roundwidth,height);

//    //this->setFrameShadow(QFrame::Raised);
//   // this->setFrameShape(QFrame::Box);
//   // this->setLineWidth(5);
//   // this->setWindowFlags(Qt::FramelessWindowHint);
//}
//void RoomWidget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing,true);
//  /*  int width = textlenth+space+margin*2+roundwidth;

//     QPen  pen1  = painter.pen();
//     pen1.setWidth(2);
//     pen1.setColor(Qt::white);
//     painter.setPen(pen1);
//    painter.drawRect(1,1,width-2,height-2);
//   // painter.drawRect(2,2,width-4,height-4);
//    QPen pen  = painter.pen();
//    pen.setWidth(1);
//    pen.setColor(Qt::darkGray);
//    painter.setPen(pen);
//    painter.drawRect(3,3,width-6,height-6);*/

//    painter.setPen(Qt::NoPen);
//    painter.setBrush(QBrush(Qt::darkGray));
//    painter.drawEllipse(margin,margin,20,20);
//    QRadialGradient roomstatebrush(15,15,8,13,13);
//    switch(state)
//    {
//    case normal:
//    {
//        roomstatebrush.setColorAt(0.0,Qt::white);
//        roomstatebrush.setColorAt(0.1,Qt::white);
//        roomstatebrush.setColorAt(1.0,Qt::green);
//    }break;
//    case offline:
//    {
//        roomstatebrush.setColorAt(0.0,Qt::white);
//        roomstatebrush.setColorAt(0.1,Qt::white);
//        roomstatebrush.setColorAt(1.0,Qt::gray);

//    }break;
//    case firstalarm:
//    {
//        roomstatebrush.setColorAt(0.0,Qt::white);
//        roomstatebrush.setColorAt(0.1,Qt::white);
//        roomstatebrush.setColorAt(1.0,Qt::red);
//    }break;
//    case secondalarm:
//    {
//        roomstatebrush.setColorAt(0.0,Qt::white);
//        roomstatebrush.setColorAt(0.1,Qt::white);
//        roomstatebrush.setColorAt(1.0,QColor(255,165,0));
//    }break;
//    default:;
//    }
//    painter.setBrush(roomstatebrush);
//    painter.drawEllipse(margin+2,margin+2,16,16);
//    painter.setPen(Qt::SolidLine);
//    painter.drawText(margin+roundwidth,margin,textlenth,roundwidth,Qt::AlignCenter,roomname.split("楼").last());
//}

//void RoomWidget::setRoomState(int newstate)
//{
//    this->state = newstate;
//    if(isVisible())
//        update();
//}

GeneralViewWidget::GeneralViewWidget(HomePage * homepage,QWidget *parent) :
    QWidget(parent)
{
    this->homepageptr = homepage;

    mywidth = parent->width();
    myheight = parent->height();
    procedurewid = new QWidget(this);
    procedurewid->setStyleSheet("QWidget{border-image:url(images/procedure.png);}");
    procedurewid->show();

    qDebug()<<"GeneralViewWidgetparent"<<parent->width()<<parent<<height();
}

void GeneralViewWidget::refreshBuildingStructrue()
{
    mywidth = parentWidget()->width();
    myheight = parentWidget()->height();
   // procedurewid->setGeometry(mywidth/10,myheight/10,mywidth*4/5,myheight*4/5);
     procedurewid->setGeometry(0,0,mywidth,myheight);


}

void GeneralViewWidget::refreshGeneralViewStatistics()
{

}



/*void GeneralViewWidget::resizeEvent(QResizeEvent * event)
{
    QWidget::resizeEvent(event);
}*/
