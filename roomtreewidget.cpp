//房间树
#include <QtCore/QDebug>
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTreeWidgetItemIterator>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>
#include <QHeaderView>
#include <QtCore/QList>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QTabWidget>
#include <QHash>
#include <QMap>
#include <QBitArray>
#include <QSqlRecord>
#include <QListWidget>
#include <qmath.h>
#include <QCheckBox>
#include <QProgressBar>
#include "struct.h"
#include "roomtreewidget.h"
#include "ui_olderinfowidget.h"
#include "management/elderinfo.h"

RoomTreeWidget::RoomTreeWidget(QWidget *parent) :
    QTreeWidget(parent),floorsize(6),roomsize(30)
{
    this->header()->hide();
    //connectToDatabase();
    createRightMenuActions();
    createFloorRoom();
    this->setContextMenuPolicy(Qt::CustomContextMenu);//设置上下文菜单策略
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showRightMenu(QPoint)));
    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(defaultDoubleClicked(QModelIndex)));
    connect(this,SIGNAL(itemActivated(QTreeWidgetItem*,int)),this,SLOT(onItemActivated(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(onCurrentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(this,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(onItemChanged(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(onItemClicked(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemCollapsed(QTreeWidgetItem*)),this,SLOT(onItemCollapsed(QTreeWidgetItem*)));
    connect(this,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(onItemDoubleClicked(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemEntered(QTreeWidgetItem*,int)),this,SLOT(onItemEntered(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemExpanded(QTreeWidgetItem*)),this,SLOT(onItemExpanded(QTreeWidgetItem*)));
    connect(this,SIGNAL(itemPressed(QTreeWidgetItem*,int)),this,SLOT(onItemPressed(QTreeWidgetItem*,int)));
    this->setStyleSheet("QTreeWidget{background-color:#FFFFE0;}");
    this->setCurrentItem(this->topLevelItem(0));
}


void RoomTreeWidget::showRightMenu(const QPoint & pos)
{
    QTreeWidgetItem * curItem = this->itemAt(pos);
    //qDebug()<<curItem<<": "<<curItem->data(0,Qt::UserRole);
    if(curItem == NULL)
    {
       QMenu * roomright_menu = new QMenu;
        roomright_menu->addAction(addbuilding_action);
        roomright_menu->exec(QCursor::pos());
        delete roomright_menu;
    }
    else if(1 == curItem->data(0,Qt::UserRole))
    {
        QMenu * roomright_menu = new QMenu;
         roomright_menu->addAction(addbuilding_action);
         roomright_menu->addAction(delbuilding_action);
         roomright_menu->addAction(addfloor_action);
         roomright_menu->exec(QCursor::pos());
         delete roomright_menu;
    }
    else if(2==curItem->data(0,Qt::UserRole))//楼层
    {
        QMenu * roomright_menu = new QMenu;
        roomright_menu->addAction(delfloor_action);
        roomright_menu->addAction(addroom_action);
        //roomright_menu->addAction(lookupfloorolderinfo_action);
        roomright_menu->exec(QCursor::pos());
        delete roomright_menu;
    }
    else if(3==curItem->data(0,Qt::UserRole))//房间
    {
        QMenu * roomright_menu = new QMenu;
        roomright_menu->addAction(delroom_action);
        //roomright_menu->addAction(lookuproomolderinfo_action);
        if(hassursys)
        {
            if(globaldb.open())
            {
                if(!dbisconnected)
                {
                    dbisconnected = true;
                    raao->setAppEnable(true);
                }
                int roomid = roomnameToIds[curItem->parent()->parent()->text(0)+":"+curItem->parent()->text(0)+":"+curItem->text(0)];
                QSqlQuery query(globaldb);
                query.prepare("SELECT bin(running_state) FROM device_info WHERE device_id = ?");
                query.addBindValue(roomid);
                query.exec();
                if(query.next())
                {
                    bool flag = query.value(0).toBool();
                    if(flag)
                        setroommonitored_action->setChecked(true);
                    else
                        setroommonitored_action->setChecked(false);
                }
                 roomright_menu->addAction(setroommonitored_action);


            }
            else
            {
                if(dbisconnected)
                {
                    dbisconnected = false;
                    raao->setAppEnable(false);
                    QMessageBox::warning(0,tr("警告"),tr("数据库删除床位信息失败！"),tr("确定"));//注意数据库与界面操作是否表现一致，如果不一致该如何处理
                }
            }
        }
        roomright_menu->exec(QCursor::pos());
         delete roomright_menu;
    }
    else if(4==curItem->data(0,Qt::UserRole))//视图
    {
        /* QMenu * viewright_menu = new QMenu;
         viewright_menu->addAction(addview_action);
         viewright_menu->exec(QCursor::pos());
         delete viewright_menu;*/
    }
    else if(5==curItem->data(0,Qt::UserRole))//床位
    {
        QMenu * olderright_menu = new QMenu;
        olderright_menu->addAction(addbed_action);
        olderright_menu->exec(QCursor::pos());
        delete olderright_menu;
    }
    else if(6==curItem->data(0,Qt::UserRole))//默认视图
    {
        QMenu * viewright_menu = new QMenu;
        viewright_menu->addAction(lookupview_action);
        viewright_menu->exec(QCursor::pos());
        delete viewright_menu;
    }
    else if(7 == curItem->data(0,Qt::UserRole))
    {
        QMenu * viewright_menu = new QMenu;
        viewright_menu->addAction(lookupview_action);
        viewright_menu->addAction(delview_action);
        viewright_menu->exec(QCursor::pos());
        delete viewright_menu;
    }
    else if(8==curItem->data(0,Qt::UserRole))//老人1
    {
        QMenu * olderinforight_menu = new QMenu;
        /*olderinforight_menu->addAction(lookupolderinfo_action);
        olderinforight_menu->addAction(addolder_action);
        olderinforight_menu->addAction(editolderinfo_action);
        olderinforight_menu->addAction(delolder_action);*/
        olderinforight_menu->addAction(delbed_action);
        olderinforight_menu->exec(QCursor::pos());
        delete olderinforight_menu;
    }
}

void RoomTreeWidget::createRightMenuActions()
{
  //  roomright_menu = new QMenu(this);
    addbuilding_action = new QAction(tr("添加楼"),this);
    delbuilding_action = new QAction(tr("删除楼"),this);

    addfloor_action = new QAction(tr("添加楼层"),this);
    delfloor_action = new QAction(tr("删除楼层"),this);
    lookupfloorolderinfo_action = new QAction(tr("查看楼层入住人员"),this);

    addroom_action = new QAction(tr("添加房间"),this);
    lookuproomolderinfo_action = new QAction(tr("查看房间入住人员"),this);

    editroom_action = new QAction(tr("编辑房间"),this);
    delroom_action = new QAction(tr("删除房间"),this);
    setroommonitored_action = new QAction("监测房间",this);
    setroommonitored_action->setCheckable(true);
    addview_action = new QAction(tr("添加视图"),this);
    delview_action = new QAction(tr("删除视图"),this);
    editview_action =new QAction(tr("编辑视图"),this);

    lookupview_action = new QAction(tr("查看视图"),this);
    lookupolderinfo_action = new QAction(tr("查看入住人员"),this);
    addbed_action = new QAction(tr("添加床位"),this);
    addolder_action = new QAction(tr("添加入住人员"),this);
    editolderinfo_action = new QAction(tr("编辑入住人员"),this);
    delolder_action = new QAction(tr("删除入住人员"),this);
    delbed_action = new QAction(tr("删除床位"),this);

    connect(addbuilding_action,SIGNAL(triggered()),this,SLOT(addBuilding()));
    connect(delbuilding_action,SIGNAL(triggered()),this,SLOT(delBuilding()));

    connect(addfloor_action,SIGNAL(triggered()),this,SLOT(addFloor()));
    connect(delfloor_action,SIGNAL(triggered()),this,SLOT(deleteFloor()));
    connect(lookupfloorolderinfo_action,SIGNAL(triggered()),this,SLOT(lookupFloorOlderInfo()));

    connect(addroom_action,SIGNAL(triggered()),this,SLOT(addRoom()));
    //connect(editroom_action,SIGNAL(triggered()),this,SLOT(editRoom()));
    connect(lookuproomolderinfo_action,SIGNAL(triggered()),this,SLOT(lookupRoomOlderInfo()));
    connect(delroom_action,SIGNAL(triggered()),this,SLOT(deleteRoomRequest()));
    connect(setroommonitored_action,SIGNAL(triggered(bool)),this,SLOT(setRoomMonitor(bool)));
    connect(addview_action,SIGNAL(triggered()),this,SLOT(addView()));
    connect(delview_action,SIGNAL(triggered()),this,SLOT(delViewRequest()));
    connect(editview_action,SIGNAL(triggered()),this,SLOT(editView()));
    connect(lookupview_action,SIGNAL(triggered()),this,SLOT(lookupView()));
    connect(lookupolderinfo_action,SIGNAL(triggered()),this,SLOT(lookupOlderInfo()));
    connect(addbed_action,SIGNAL(triggered()),this,SLOT(addBed()));
    connect(addolder_action,SIGNAL(triggered()),this,SLOT(addOlder()));
    connect(editolderinfo_action,SIGNAL(triggered()),this,SLOT(editOlderInfo()));
    connect(delolder_action,SIGNAL(triggered()),this,SLOT(delOlder()));
    connect(delbed_action,SIGNAL(triggered()),this,SLOT(delBed()));
}

void RoomTreeWidget::addBuilding()
{
    //响应添加楼
    qDebug()<<tr("添加楼");
    //QString newbuildingname;
    AddBuildingDialog abd(this);
    connect(&abd,SIGNAL(addBuilding(QString)),this,SIGNAL(addBuilding(QString)));
    abd.exec();
    //insertLog("添加楼");
}
void RoomTreeWidget::delBuilding()
{
    //响应删除楼
    qDebug()<<tr("删除楼");
    QTreeWidgetItem * buildingitem = currentItem();
    int result = QMessageBox::warning(0,tr("警告"),tr("确定删除")+buildingitem->text(0)+tr("信息")+"？",tr("确定"),tr("取消"));
    if(result == 1)
    {
        qDebug()<<"haha";
        return;
    }
   /* int floornum = buildingitem->childCount();
    QTreeWidgetItem * floorviewitem = buildingitem->child(0);
    int floorviewcount = floorviewitem->childCount();
    if(floorviewcount > 0)
    {
        QMessageBox::warning(0,tr("警告"),tr("已存在楼层视图，不可删除！"),tr("确定"));
        return;
    }
    for(int i = 1; i < floornum; ++i)
    {
        QTreeWidgetItem * flooritem = buildingitem->child(i);
        qDebug()<<flooritem->text(0);
        int roomnum = flooritem->childCount();

        for(int j = 1; j < roomnum; j++)
        {
            QTreeWidgetItem * roomitem = flooritem->child(j);
            QTreeWidgetItem * viewitem = roomitem->child(0);
            QTreeWidgetItem * beditem = roomitem->child(1);
            if((viewitem->childCount() > 1) || (beditem->childCount() > 0))
            {
                QMessageBox::warning(0,tr("警告"),tr("已存在部分房间信息，不可删除！"),tr("确定"));
                return;
            }
        }
    }*/

    if(buildingitem->childCount() >= 1)
    {
        QMessageBox::warning(0,tr("警告"),tr("已存在楼层信息，不可删除！"),tr("确定"));
        return;
    }

    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        /*QFile file("buildingmaptofloor.dat");
        QStringList list;
        if(file.open(QIODevice::ReadWrite| QIODevice::Text))
        {
            QTextStream ts(&file);
            while(!ts.atEnd())
            {
                QString str = ts.readLine();
              //  qDebug()<<buildingitem->text(0);
                if(str.split(":").first() != buildingitem->text(0))
                {
                    list<<str;
                }
            }
           // qDebug()<<list;
            file.resize(0);
            ts.seek(0);
            for(int j = 0; j < list.size(); j++)
            {
                ts<<list.at(j)<<'\n';
            }
        }
        else
        {
            QMessageBox::warning(0,tr("警告"),tr("文件打开失败，删除失败！"),tr("确定"));
            file.close();
            return;
        }
        file.close();*/
        QSqlQuery query(globaldb);
        query.prepare("DELETE FROM buildingmaptofloor WHERE building_no = ?");
        query.addBindValue(buildingitem->text(0));
        query.exec();

        query.prepare("DELETE FROM device_info WHERE building_no = ?");
        query.addBindValue(buildingitem->text(0));
        qDebug()<< query.exec()<<"************************************************************************************"<<query.lastError();
        query.clear();
        query.finish();
        //globaldb.close();
        insertLog("删除楼："+buildingitem->text(0));
        if(hassursys)
        {
            smt->sendDelBuilding(buildingitem->text(0));
        }
       emit delBuilding(indexOfTopLevelItem(buildingitem));

        this->takeTopLevelItem(indexOfTopLevelItem(buildingitem));

    }
    else
    {
        qDebug()<<"打开失败";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,tr("警告"),tr("数据库删除床位信息失败！"),tr("确定"));//注意数据库与界面操作是否表现一致，如果不一致该如何处理
        }
        return;
    }
}

void RoomTreeWidget::addFloor()
{
    //响应添加楼层
    qDebug()<<tr("增加楼层");
    AddFloorDialog afd(currentItem(),this);
    connect(&afd,SIGNAL(addFloor(int,int,int)),this,SIGNAL(addFloor(int,int,int)));
    afd.exec();
}
void RoomTreeWidget::deleteFloor()
{
    //响应删除楼层
    qDebug()<<tr("删除楼层");
    QTreeWidgetItem * flooritem = currentItem();
    int result = QMessageBox::warning(0,tr("警告"),tr("确定删除")+flooritem->text(0)+tr("信息")+"？",tr("确定"),tr("取消"));
    if(result == 1)
    {
        qDebug()<<"haha";
        return;
    }
    /*int roomnum = flooritem->childCount();
    QTreeWidgetItem * floorviewitem = flooritem->child(0);
    int floorviewcount = floorviewitem->childCount();
    if(floorviewcount > 0)
    {
        QMessageBox::warning(0,tr("警告"),tr("已存在楼层视图，不可删除！"),tr("确定"));
        return;
    }
    for(int j = 1; j < roomnum; j++)
    {
        QTreeWidgetItem * roomitem = flooritem->child(j);
        QTreeWidgetItem * viewitem = roomitem->child(0);
        QTreeWidgetItem * beditem = roomitem->child(1);
        if((viewitem->childCount() > 1) || (beditem->childCount() > 0))
        {
            QMessageBox::warning(0,tr("警告"),tr("已存在部分房间信息，不可删除！"),tr("确定"));
            return;
        }
    }*/

    if(flooritem->childCount() >=2)
    {
        QMessageBox::warning(0,tr("警告"),tr("已存在部分房间信息，不可删除！"),tr("确定"));
        return;
    }
    qDebug()<<"可以删除";

    //记得删除所有关联的房间号,这些房间是还没有视图或者人员信息的
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        /*QFile file("buildingmaptofloor.dat");
        QStringList list;
        if(file.open(QIODevice::ReadWrite| QIODevice::Text))
        {
            QTextStream ts(&file);
            while(!ts.atEnd())
            {
                QString str = ts.readLine();
                QString temp = str;
                QStringList buildingandfloors = temp.split(":");
                if(buildingandfloors.first() == flooritem->parent()->text(0))
                {
                    qDebug()<<str;
                    QStringList floors = buildingandfloors.last().split("*");
                    QString id =  QString::number(floornames.indexOf(flooritem->text(0)) + 1);
                    qDebug()<<"id"<<id;
                    floors.removeAt(floors.indexOf(id));

                    str.clear();
                    str.append(buildingandfloors.first());
                    str.append(":");
                    for(int i = 0 ; i < floors.size(); i++)
                    {
                        str.append(floors.at(i));
                        str.append("*");
                    }
                    if(floors.size() > 0)
                    {
                        str.remove(str.size()-1,1);
                    }
                    qDebug()<<"delfloor";
                    qDebug()<<str;
                }
                list<<str;

            }
            qDebug()<<list;
            file.resize(0);
            ts.seek(0);
            for(int j = 0; j < list.size(); j++)
            {
                ts<<list.at(j)<<'\n';
            }
            qDebug()<<"soga";
        }
        else
        {
            QMessageBox::warning(0,tr("警告"),tr("文件打开失败，删除失败！"),tr("确定"));
            file.close();
            return;
        }
        file.close();*/
        QSqlQuery query(globaldb);
        query.prepare("SELECT floorlist FROM buildingmaptofloor WHERE building_no = ?");
        query.addBindValue(flooritem->parent()->text(0));
        query.exec();
        query.next();
        QString floorliststr = query.value(0).toString();
        QString newfloorliststr = "";
        QString floorstr = QString::number(floornames.indexOf(flooritem->text(0)) + 1);
        if(!floorliststr.isEmpty())
        {
            QStringList floorlists = floorliststr.split("*");
            for(int i = 0; i < floorlists.count(); i++)
            {
                if(floorlists.at(i) != floorstr)
                {
                    newfloorliststr.append(floorlists.at(i)).append("*");
                }
            }
            newfloorliststr.remove(newfloorliststr.count()-1,1);
            query.prepare("UPDATE buildingmaptofloor SET floorlist = ? WHERE building_no = ?");
            query.addBindValue(newfloorliststr);
            query.addBindValue(flooritem->parent()->text(0));
            query.exec();
        }

        qDebug()<<"soga2";
        qDebug()<<flooritem->parent()->text(0)<<floornames.indexOf(flooritem->text(0)) + 1;
        query.prepare("DELETE FROM device_info WHERE building_no = ? AND floor_no = ?");
        qDebug()<<flooritem->parent()->text(0)<<floornames.indexOf(flooritem->text(0)) + 1;
        query.addBindValue(flooritem->parent()->text(0));
        query.addBindValue(floornames.indexOf(flooritem->text(0)) + 1);
        query.exec();
        query.clear();
        query.finish();
        //globaldb.close();
        insertLog("删除楼层："+flooritem->parent()->text(0)+flooritem->text(0));
        if(hassursys)
        {
            smt->sendDelFloor(flooritem->parent()->text(0),flooritem->text(0));
        }
        emit delFloor(this->indexOfTopLevelItem(flooritem->parent()),this->indexFromItem(flooritem).row());

        flooritem->parent()->removeChild(flooritem);

    }
    else
    {
        qDebug()<<"打开失败";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,tr("警告"),tr("数据库删除床位信息失败！"),tr("确定"));//注意数据库与界面操作是否表现一致，如果不一致该如何处理
        }
        return;
    }

}

void RoomTreeWidget::lookupFloorOlderInfo()
{
    //查看楼层入住人员
    qDebug()<<tr("查看楼层入住人员");
    NameSelectDialog dlg;
    connect(&dlg,SIGNAL(locateAndOpenRoom(QString,QString,QString)),this,SLOT(locateAndOpenRoom(QString,QString,QString)));
    QString floorname = currentItem()->text(0);
    QString buildingname = currentItem()->parent()->text(0);
    bool hasolder = dlg.loadFloorOlderBriefInfo(buildingname,floorname);
    if(!hasolder)
    {
        dlg.accept();
        return;
    }
   // dlg.setFixedWidth(600);

    dlg.setWindowTitle(floorname+"入住人员");
    dlg.exec();
}

void RoomTreeWidget::addRoom()
{
    //响应添加房间
    qDebug()<<tr("添加房间");
    if(totalroomcount == MAXROOMNUM)
    {
        QMessageBox::warning(0,"警告","最大房间数为"+ QString::number(MAXROOMNUM)+"不可以继续添加房间！","确定");
        return;
    }
    AddRoomDialog ard(currentItem(),this);
    connect(&ard,SIGNAL(addRoom(int,int,QString)),this,SIGNAL(addRoom(int,int,QString)));
    ard.exec();
}
void RoomTreeWidget::lookupRoomOlderInfo()
{
    //查看房间入住人员
    qDebug()<<tr("查看房间入住人员");
    QTreeWidgetItem * roomitem = currentItem();
    QTreeWidgetItem * bedinfoitem = roomitem->child(1);
    QList<QTreeWidgetItem *> usedbeds;
    for(int i = 0; i < bedinfoitem->childCount(); i++)
    {
        QTreeWidgetItem * item = bedinfoitem->child(i);
        QString bedinfo = item->text(0);
        if(bedinfo.size() > 7)//"X号床 -- "长度
        {
            usedbeds.append(item);
        }
    }



   if(usedbeds.count() == 1)
    {
       QStringList args;
       QTreeWidgetItem * item = usedbeds.first();
       args<<item->parent()->parent()->parent()->parent()->text(0);
       args<<QString::number(floornames.indexOf(item->parent()->parent()->parent()->text(0)) + 1);
       args<<item->parent()->parent()->text(0);
       args<<item->text(0).split("号").first();
       qDebug()<<args;
       ElderInfo eiadd(VIEWELDER,args);
       connect(&eiadd,SIGNAL(locateAndOpenRoom(QString,QString,QString)),this,SLOT(locateAndOpenRoom(QString,QString,QString)));
       eiadd.exec();
    }
    else if(usedbeds.count() > 1)
    {
        QDialog d;
        d.setWindowTitle(tr("入住人员信息"));
        QVBoxLayout *vbl = new QVBoxLayout(&d);
        QTabWidget *tabwidget = new QTabWidget(&d);
        ElderInfo *  eiadd = 0;
        for(int i  = 0;i < usedbeds.count(); i++)
        {
           /* QStringList strlist;
            strlist<<query.value(nameid).toString()<<query.value(sexid).toString()<<query.value(birthid).toString()<<query.value(bodystateid).toString()
                   <<query.value(servicetypeid).toString()<<query.value(mattressid).toString();
            strlist<<query.value(buildingid).toString()<<floornames.at(query.value(floorid).toInt());
            strlist<<query.value(roomnoid).toString()<<query.value(bednoid).toString()<<query.value(icid).toString()
                   <<query.value(telid).toString()<<query.value(contactorid).toString()<<query.value(contactortelid).toString();
            QByteArray data = query.value(photoid).toByteArray();
            OlderInfoWidget * olderinfo = new OlderInfoWidget(&d);
            olderinfo->showOlderInfo(strlist,data);*/
            QStringList args;
            QTreeWidgetItem * item = usedbeds.at(i);
            args<<item->parent()->parent()->parent()->parent()->text(0);
            args<<QString::number(floornames.indexOf(item->parent()->parent()->parent()->text(0)) + 1);
            args<<item->parent()->parent()->text(0);
            args<<item->text(0).split("号").first();
            qDebug()<<args;
            eiadd = new ElderInfo(VIEWELDER,args,&d);
            connect(eiadd,SIGNAL(locateAndOpenRoom(QString,QString,QString)),this,SLOT(locateAndOpenRoom(QString,QString,QString)));
            tabwidget->addTab(eiadd,item->text(0).right(item->text(0).size() - 7));
        }
        vbl->addWidget(tabwidget);
        d.setLayout(vbl);
       // d.setFixedSize(540,380);
        d.setFixedSize(eiadd->width()+20,eiadd->height()+50);
        d.exec();
    }

}

void RoomTreeWidget::editRoom()
{
    //响应编辑房间
    qDebug()<<tr("编辑房间");
}



void RoomTreeWidget::deleteRoomRequest()
{
    qDebug()<<"deleteroom";
    int result = QMessageBox::warning(0,tr("警告"),tr("确定删除该房间？"),tr("确定"),tr("取消"));
    if(result == 1)
        return;
    QTreeWidgetItem * roomitem = currentItem();
    if(roomitem->child(0)->childCount() > 0)
    {
        QMessageBox::warning(0,"警告","该房间已存在床位，无法删除！","确定");
        return;
    }
    if(hassursys)
    {

        drpd = new DelRoomProcessDialog(this);
        drpd->startCount();
        smt->sendDelRoomRequest(roomitem->parent()->parent()->text(0),roomitem->parent()->text(0),roomitem->text(0));
        int result  = drpd->exec();
        qDebug()<<"drpd->getCount()"<<drpd->getCount();
        if(result == drpd->Accepted ||drpd->getCount() == 5)
        {
            //QMessageBox::warning(0,"警告","由于网络问题,房间删除失败!","确定");
            smt->sendDelRoom(roomitem->parent()->parent()->text(0),roomitem->parent()->text(0),roomitem->text(0));
            deleteRoom(true);
            delete drpd;
            return;
        }
        else if(result == drpd->Rejected)
        {
            QMessageBox::warning(0,tr("警告"),tr("其他系统正在使用该房间，无法删除"),tr("确定"));
            delete drpd;
            return;
        }
        delete drpd;
    }
    else
    {
        deleteRoom(true);
    }


    //emit deleteRoomRequestSignal(roomitem->parent()->parent()->text(0) + roomitem->parent()->text(0)+roomitem->text(0) +"房间");

}
void RoomTreeWidget:: deleteRoomCanbe(bool flag)
{
    if(!flag &&hassursys)
    {
        //QMessageBox::warning(0,tr("警告"),tr("其他系统正在使用该房间，无法删除"),tr("确定"));
        drpd->reject();
        drpd->close();
        return;
    }
    else if(flag && hassursys)
    {
        drpd->accept();
        drpd->close();
        return;
    }

}

void RoomTreeWidget::deleteRoom(bool flag)
{
    //响应删除房间
    qDebug()<<tr("删除房间");
  /*  if(!flag)
    {
        //QMessageBox::warning(0,tr("警告"),tr("其他系统正在使用该房间，无法删除"),tr("确定"));
        drpd->reject();
        return;
    }*/
    QTreeWidgetItem * curitem = currentItem();
    {
        if(dbisconnected && globaldb.open())
        {
            QString buildingname = curitem->parent()->parent()->text(0);
            int floorno = floornames.indexOf(curitem->parent()->text(0)) + 1;
            QString roomname = curitem->text(0);
            int roomid = roomnameToIds[buildingname + ":"+floornames.at(floorno - 1)+":" + roomname];
            QSqlQuery query(globaldb);
            query.prepare("DELETE FROM device_info WHERE building_no = ? AND floor_no = ? AND room_name = ?");
            query.addBindValue(buildingname);
            query.addBindValue(floorno);
            query.addBindValue(roomname);
            query.exec();
            query.clear();
            query.finish();
            roomnameToIds.remove(buildingname+":"+floornames.at(floorno - 1)+":" + roomname);
            totalroomcount--;
            insertLog("删除房间：" +buildingname+curitem->parent()->text(0)+roomname);
            emit delRoom(this->indexOfTopLevelItem(curitem->parent()->parent()),curitem->parent()->parent()->indexOfChild(curitem->parent()) - 1,curitem->text(0));
            curitem->parent()->removeChild(curitem);

            //更新p_device表，是否要更新elder_info表?

            query.prepare("SELECT * FROM p_device WHERE room1 = ?");
            query.addBindValue(roomid);
            query.exec();
            if(query.next())
            {
                qDebug()<<"updateroom1";
                query.prepare("UPDATE p_device SET room1 = ?,room1_state = ? WHERE room1 = ?");
                query.addBindValue(-1);
                query.addBindValue(0);
                query.addBindValue(roomid);
                query.exec();
            }
            else
            {
                query.prepare("SELECT * FROM p_device WHERE room2 = ?");
                query.addBindValue(roomid);
                query.exec();
                if(query.next())
                {
                    qDebug()<<"updateroom2";
                    query.prepare("UPDATE p_device SET room2 = ?,room2_state = ? WHERE room2 = ?");
                    query.addBindValue(-1);
                    query.addBindValue(0);
                    query.addBindValue(roomid);
                    query.exec();
                }
                else
                {

                }
            }

            query.clear();
            query.finish();
        /*    if(hassursys)
            {
                drpd->accept();
            }*/

        }
        else
        {
            qDebug()<<"打开失败";
            if(dbisconnected)
            {
                dbisconnected = false;
                raao->setAppEnable(false);
                QMessageBox::warning(0,"警告","数据库连接失败！","确定");
            }
            return;
        }
    }

}
void RoomTreeWidget::setRoomMonitor(bool flag)
{
    qDebug()<<"是否监测房间"<<flag;
    QTreeWidgetItem * curitem = currentItem();//监测该房间
    int roomid = roomnameToIds[curitem->parent()->parent()->text(0)+":"+curitem->parent()->text(0)+":"+curitem->text(0)];

    if(flag)
    {
       int reslut = QMessageBox::warning(0,"警告","将房间"+currentItem()->text(0)+"加入到环境监测系统的监测范围内？","确定");
       if(reslut == 1)
       {
           return;
       }

       if(globaldb.open())
       {
           if(!dbisconnected)
           {
               dbisconnected = true;
               raao->setAppEnable(true);
           }

           QSqlQuery query(globaldb);
           query.prepare("UPDATE device_info SET running_state = ? WHERE device_id = ?");
           query.addBindValue(1);
           query.addBindValue(roomid);
           query.exec();
           query.clear();
           query.finish();

           /*analog[roomid].roomstate = 1;
           curitem->setBackgroundColor(0,Qt::white);
           if(!roomIsCompleteConfigure(roomid))
           {
               QMessageBox::information(0,"警告","对房间"+currentItem()->text(0)+"进行配置以后可以进行监测","确定");
           }*/

           //通知环境系统对房间进行监测
           smt->sendMonitorRoom(curitem->parent()->parent()->text(0),curitem->parent()->text(0),curitem->text(0),true);
       }
       else
       {
           QMessageBox::warning(0,tr("警告"),tr("数据库连接失败！"),tr("确定"));//注意数据库与界面操作是否表现一致，如果不一致该如何处理
           return;
       }


    }
    else//取消该房间的监测
    {
        int reslut = QMessageBox::warning(0,"警告","取消房间"+curitem->text(0)+"在环境监测系统中的监测？","确定");
        if(reslut == 1)
        {
            return;
        }
        if(globaldb.open())
        {
            if(!dbisconnected)
            {
                dbisconnected = true;
                raao->setAppEnable(true);
            }

            QSqlQuery query(globaldb);
            query.prepare("UPDATE device_info SET running_state = ? WHERE device_id = ?");
            query.addBindValue(0);
            query.addBindValue(roomid);
            query.exec();
            query.clear();
            query.finish();

            /*analog[roomid].roomstate = 0;
            curitem->setExpanded(false);
            curitem->setBackgroundColor(0,Qt::lightGray);*/
            //通知环境系统取消对房间的监测
            smt->sendMonitorRoom(curitem->parent()->parent()->text(0),curitem->parent()->text(0),curitem->text(0),false);

        }
        else
        {
            QMessageBox::warning(0,tr("警告"),tr("数据库数据库连接失败！"),tr("确定"));//注意数据库与界面操作是否表现一致，如果不一致该如何处理
            return;
        }

    }

}


void RoomTreeWidget::addView()
{
    //响应增加视图
    qDebug()<<tr("增加视图");
}

void RoomTreeWidget::delViewRequest()
{
    //响应删除视图
    qDebug()<<tr("删除视图");
    emit delRequestSignal(-1);

}

void RoomTreeWidget::delView(bool flag)
{
    int result = QMessageBox::warning(0,tr("警告"),tr("是否删除视图？"),tr("确定"),tr("取消"));
    qDebug()<<"result"<<result;
    if(result == 1)
    {
        return;
    }
    if(!flag)
    {
        QMessageBox::warning(0,tr("警告"),tr("视图使用中，无法删除！"),tr("确定"));
        return;
    }

    QTreeWidgetItem * curitem = currentItem();
    int level = curitem->parent()->parent()->data(0,Qt::UserRole).toInt();
    QString delstr = "";
    switch(level)
    {
    case 1:
    {
        QString curbuildingname = curitem->parent()->parent()->text(0);
        delstr.append(curbuildingname+"*"+curitem->text(0)+";");
    }
        break;
    case 2:
    {
        QString curbuildingname = curitem->parent()->parent()->parent()->text(0);
        QString curfloorname = curitem->parent()->parent()->text(0);
        delstr.append(curbuildingname+curfloorname+"*"+curitem->text(0)+";");
    }
        break;
    case 3:
    {
        QString curbuildingname = curitem->parent()->parent()->parent()->parent()->text(0);
        QString curfloorname = curitem->parent()->parent()->parent()->text(0);
        QString roomname = curitem->parent()->parent()->text(0);
        delstr.append(curbuildingname+curfloorname+roomname+"*"+curitem->text(0)+";");
    }
        break;
    }
    qDebug()<<"delstr"<<delstr;
    QFile file("viewaddtotree.dat");
    QString views = "";
    if(file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QTextStream ts(&file);
        views = ts.readLine();
        qDebug()<<views;
        views.remove(delstr);
        qDebug()<<"views"<<views;
        file.resize(0);
        ts.seek(0);
        ts<<views;
        curitem->parent()->removeChild(curitem);
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("视图删除失败！"),tr("确定"));
        return;
    }
    file.close();
}

void RoomTreeWidget::editView()
{
    //响应编辑视图
    qDebug()<<tr("编辑视图");
}

void RoomTreeWidget::lookupView()
{
    //响应查看视图
    qDebug()<<tr("查看视图");
  //  QString str= this->currentItem()->text(0);
    int index = this->currentIndex().row();
    emit lookuoViewSignal(index);
}

void RoomTreeWidget::lookupOlderInfo()
{
    qDebug()<<tr("查看老人信息");
    QTreeWidgetItem * item = currentItem();
    QString bedinfo = item->text(0);
    if(bedinfo.size() <= 7)//"X号床 -- "长度
    {
        QMessageBox::warning(0,tr("警告"),tr("该床位无入住人员！"),tr("确定"));
        return;
    }
    QStringList args;
    args<<item->parent()->parent()->parent()->parent()->text(0);
    args<<QString::number(floornames.indexOf(item->parent()->parent()->parent()->text(0)) + 1);
    args<<item->parent()->parent()->text(0);
    args<<item->text(0).split("号").first();
    qDebug()<<args;
    ElderInfo eiadd(VIEWELDER,args);
    connect(&eiadd,SIGNAL(locateAndOpenRoom(QString,QString,QString)),this,SLOT(locateAndOpenRoom(QString,QString,QString)));
    eiadd.exec();
}

void RoomTreeWidget::addBed()
{
    qDebug()<<tr("添加床位");
     QTreeWidgetItem * curitem = currentItem();
    AddBedDialog abd(curitem);
    int result =  abd.exec();
    //先判断有没有添加成功，如果添加成功，即treewidget和数据库里面的内容都保持一致即可，再进行消息发送
    /*if(result == abd.Accepted)
    {
       int id = roomnameToIds[curitem->parent()->parent()->parent()->text(0)+":"+curitem->parent()->parent()->text(0)+":"+curitem->parent()->text(0)];
       //emit refreshVernierTableWidget(id);
       if(hassursys)
       {
           smt->sendAddBed(curitem->parent()->parent()->parent()->text(0),curitem->parent()->parent()->text(0),curitem->parent()->text(0),);
       }
    }*/
}
void RoomTreeWidget::addOlder()
{
    qDebug()<<tr("添加老人");
    /*QDialog d;
    d.setWindowTitle(tr("添加入住人员"));
    d.setFixedWidth(220);
    QHBoxLayout * addolder_hbl = new QHBoxLayout;
    QLabel * addolder_label = new QLabel(tr("入住人员姓名："),&d);
    QLineEdit * addolder_lineedit = new QLineEdit(&d);
    addolder_hbl->addWidget(addolder_label);
    addolder_hbl->addWidget(addolder_lineedit);
    QHBoxLayout * btn_hbl = new QHBoxLayout;
    QPushButton * configure_pushbutton = new QPushButton(tr("确定"),&d);
   // configure_pushbutton->setSizePolicy(QSizePolicy.setHorizontalPolicy(1));
    QPushButton * cancel_pushbutton = new QPushButton(tr("取消"),&d);
    btn_hbl->addSpacing(120);
    btn_hbl->setSizeConstraint(QLayout::SetMinimumSize);
    btn_hbl->addWidget(configure_pushbutton);
    btn_hbl->addWidget(cancel_pushbutton);
    QVBoxLayout * vbl = new QVBoxLayout;
    vbl->addLayout(addolder_hbl);
    vbl->addLayout(btn_hbl);
    d.setLayout(vbl);
    d.exec();*/
    QTreeWidgetItem * item = currentItem();//这里应该注意老人被删除后，再次添加入住，和第一次在床位添加入住人员的差别
    QString bedname = item->text(0);
    if(bedname.size()>3)
    {
        QMessageBox::warning(0,tr("警告"),tr("该床位已有入住人员！"),tr("确定"));
        return;
    }

    QStringList args;
    args<<item->parent()->parent()->parent()->parent()->text(0);
    args<<QString::number(floornames.indexOf(item->parent()->parent()->parent()->text(0)) + 1);
    args<<item->parent()->parent()->text(0);
    args<<item->text(0).split("号").first();
    qDebug()<<args;

    QString * strptr = new QString;
    ElderInfo eiadd(NEWELDER,args);
    eiadd.setOlder(strptr);
   int result =  eiadd.exec();//如何判断有没有成功的
   if(result == eiadd.Rejected)
   {
       delete strptr;
       return;
   }
    item->setText(0,item->text(0).append(" -- "+ *strptr));
    delete strptr;
    //刷新vernier
    int id = roomnameToIds[item->parent()->parent()->parent()->parent()->text(0)+":"+item->parent()->parent()->parent()->text(0)+":"+item->parent()->parent()->text(0)];
    emit refreshVernierTableWidget(id);
}
void RoomTreeWidget::editOlderInfo()
{
    qDebug()<<tr("编辑老人信息");
    QTreeWidgetItem * item = currentItem();//这里应该注意老人被删除后，再次添加入住，和第一次在床位添加入住人员的差别
    QString bedname = item->text(0);
    if(bedname.size() <= 3)
    {
        QMessageBox::warning(0,tr("警告"),tr("该床位没有入住人员！"),tr("确定"));
        return;
    }

    QStringList args;
    args<<item->parent()->parent()->parent()->parent()->text(0);
    args<<QString::number(floornames.indexOf(item->parent()->parent()->parent()->text(0)) + 1);
    args<<item->parent()->parent()->text(0);
    args<<item->text(0).split("号").first();
    qDebug()<<args;

    ElderInfo eiadd(EDITELDER,args);
    eiadd.exec();
    /*QString * strptr = new QString;
    ElderInfo eiadd(EDITELDER,args);
    eiadd.setOlder(strptr);
    int result =  eiadd.exec();//如何判断有没有成功的
    if(result == eiadd.Rejected)
    {
        delete strptr;
        return;
    }
    item->setText(0,item->text(0).split(" -- ").first().append(" -- "+ *strptr));
    delete strptr;*/


    //刷新vernier
    int id = roomnameToIds[item->parent()->parent()->parent()->parent()->text(0)+":"+item->parent()->parent()->parent()->text(0)+":"+item->parent()->parent()->text(0)];
    emit refreshVernierTableWidget(id);

}

void RoomTreeWidget::delOlder()
{
    qDebug()<<tr("删除老人");
    QTreeWidgetItem * item = currentItem();
    QString bedname = item->text(0);
    if(bedname.size() <= 7)
    {
        QMessageBox::warning(0,tr("警告"),tr("该床位无入住人员！"),tr("确定"));
        return;
    }
    DelOlderDialog dod(item);
    dod.exec();
    //刷新vernier
    int id = roomnameToIds[item->parent()->parent()->parent()->parent()->text(0)+":"+item->parent()->parent()->parent()->text(0)+":"+item->parent()->parent()->text(0)];
    /*if(id >= 0 && bedno >= 1)
    {
        if(ui->mat_comboBox_11->currentText() == "有")
        {
            mat[roomid].bitmap = mat[roomid].bitmap | (quint8)(pow(2,bedno - 1));
        }
        else if(ui->mat_comboBox_11->currentText() == "无")
        {
            mat[roomid].bitmap = mat[roomid].bitmap & (~(quint8)(pow(2,bedno - 1)));
        }
    }*/
    emit refreshVernierTableWidget(id);
}

void RoomTreeWidget::delBed()
{
    qDebug()<<tr("删除床位");
    QTreeWidgetItem * item = currentItem();
    //判断床位是否有人，然后确定是否可以删除
    int result =  QMessageBox::warning(0,tr("警告"),tr("确定删除该床位？"),tr("确定"),tr("取消"));
    if(result == 1)
    {
        return;
    }
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QString buildingname = item->parent()->parent()->parent()->parent()->text(0);
        int floorno = floornames.indexOf(item->parent()->parent()->parent()->text(0)) + 1;
        QString roomname = item->parent()->parent()->text(0);
        qDebug()<<buildingname<<floorno<<roomname;
        QSqlQuery query(globaldb);
        query.prepare("SELECT device_id,bitmap,bed_no FROM device_info WHERE building_no = ? AND floor_no = ? AND room_name = ?");
        query.addBindValue(buildingname);
        query.addBindValue(floorno);
        query.addBindValue(roomname);
        query.exec();
        if(query.next())
        {
            int bedbits0 = query.value(1).toInt();
            int curbednum = currentItem()->text(0).left(1).toInt();
            bedbits0 = (bedbits0 >> (2*(curbednum - 1)));
            if(!((bedbits0 & 0x03) == 0 || (bedbits0 & 0x03) == 1))//有床无人
            {
                qDebug()<<"bedbits0 & 0x03"<<(bedbits0 & 0x03);
                QMessageBox::warning(0,tr("警告"),tr("该床位已被使用"),tr("确定"));
                return;
            }

            int bedbits = query.value(1).toInt();
            int bedno = item->text(0).left(1).toInt();
            int x = 1;
            for(int i = 0; i < bedno -1; i++)
            {
                x =x<<2;
            }
            bedbits ^= x;
            qDebug()<<bedbits;
            int devicenum = query.value(0).toInt();
            int bednum = query.value(2).toInt();
            qDebug()<<devicenum<<bednum;
            query.prepare("UPDATE device_info SET bitmap = ?,bed_no = ? WHERE device_id = ?");
            query.addBindValue(bedbits);
            query.addBindValue(bednum - 1);
            query.addBindValue(devicenum);
            query.exec();
            insertLog("删除床位：" + buildingname + item->parent()->parent()->parent()->text(0) + roomname + item->text(0));
            if(hassursys)
            {
                smt->sendDelBed(buildingname,item->parent()->parent()->parent()->text(0),roomname,item->text(0));
            }
            QTreeWidgetItem * parentitem = item->parent();
            parentitem->removeChild(item);
            //刷新vernier
            //int id = roomnameToIds[parentitem->parent()->parent()->parent()->text(0)+":"+parentitem->parent()->parent()->text(0)+":"+parentitem->parent()->text(0)];
            //emit refreshVernierTableWidget(id);
        }
        else
        {
            query.clear();
            query.finish();
            if(dbisconnected)
            {
                dbisconnected = false;
                raao->setAppEnable(false);
                QMessageBox::warning(0,"警告","数据库连接失败！","确定");
            }
            return;
        }
        query.clear();
        query.finish();
        //globaldb.close();

    }
    else
    {
        qDebug()<<"打开失败";
        QMessageBox::warning(0,tr("警告"),tr("数据库删除床位信息失败！"),tr("确定"));//注意数据库与界面操作是否表现一致，如果不一致该如何处理
        return;
    }
}

void RoomTreeWidget::defaultDoubleClicked(QModelIndex modelindex)
{
    int id = modelindex.data(Qt::UserRole).toInt();
    switch(id)
    {
    case 0:
    case 1:
    {
        QTreeWidgetItem * item = currentItem();
        //if(!item->isExpanded())
        qDebug()<<"this->indexFromItem(item).row()"<<this->indexFromItem(item).row();
          emit expandbuilding(this->indexFromItem(item).row());
    }
        break;
    case 2:
    {
        QTreeWidgetItem * item = currentItem();

        if(!item->isExpanded())
       // qDebug()<<this->indexFromItem(item).row();
        //  emit expandbuilding(this->indexFromItem(item).row());
            emit scrolltofloor(this->indexFromItem(item->parent()).row(),this->indexFromItem(item).row());
    }
        break;
    case 6:lookupView();
        break;
    case 7:lookupView();
        break;
    case 8:lookupOlderInfo();
        break;
    }

}

//和homepage联动
void RoomTreeWidget::onItemActivated(QTreeWidgetItem * item,int column)
{
    qDebug()<<"onItemActivated!";

}

void RoomTreeWidget::onCurrentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous)
{
   qDebug()<<"onCurrentItemChanged!";
   int id = current->data(0,Qt::UserRole).toInt();
   switch(id)
   {
   case 0:
   case 1:
   {
       emit expandbuilding(this->indexFromItem(current).row());
       emit showHomepage();
   }
       break;
   case 2:
   {
       emit scrolltofloor(this->indexFromItem(current->parent()).row(),this->indexFromItem(current).row());
       emit showHomepage();
   }
       break;
   case 3:
   {
       emit scrolltofloor(this->indexFromItem(current->parent()->parent()).row(),this->indexFromItem(current->parent()).row());
       emit showHomepage();
   }
       break;
   }
}

void RoomTreeWidget::onItemChanged(QTreeWidgetItem * item, int column)
{
qDebug()<<"onItemActivated!";
}

void RoomTreeWidget::onItemClicked(QTreeWidgetItem * item, int column)
{
qDebug()<<"onItemClicked!";
}

void RoomTreeWidget::onItemCollapsed(QTreeWidgetItem * item)
{
qDebug()<<"onItemCollapsed!";
}

void RoomTreeWidget::onItemDoubleClicked(QTreeWidgetItem * item, int column)
{
qDebug()<<"onItemDoubleClicked!";
}

void RoomTreeWidget::onItemEntered(QTreeWidgetItem * item, int column)
{
qDebug()<<"onItemEntered!";
}

void RoomTreeWidget::onItemExpanded(QTreeWidgetItem * item)
{
qDebug()<<"onItemExpanded!";
}

void RoomTreeWidget::onItemPressed(QTreeWidgetItem * item, int column)
{
qDebug()<<"onItemPressed!";
}

void RoomTreeWidget::addViewTo(QString tarbuildingname,QString tarfloorname,QString tarroomname,QString viewname)
{
    qDebug()<<"addViewToSlot";
    qDebug()<<tarbuildingname<<tarfloorname<<tarroomname<<viewname;
    for(int i = 0; i < this->topLevelItemCount(); i++)
    {
        QTreeWidgetItem * buildingitem = topLevelItem(i);
        if(buildingitem->text(0) == tarbuildingname)
        {
            if(tarfloorname.isEmpty())
            {
                //插入楼视图
                QTreeWidgetItem * builidngdefaultview = buildingitem->child(0);
                QTreeWidgetItem * newitem = new QTreeWidgetItem(builidngdefaultview);
                newitem->setText(0,viewname);
                newitem->setData(0,Qt::UserRole,7);
                newitem->setToolTip(0,newitem->text(0));
                builidngdefaultview->addChild(newitem);
            }
            else
            {
                for(int j = 1; j < buildingitem->childCount(); j++)
                {
                    QTreeWidgetItem * flooritem = buildingitem->child(j);
                    if(flooritem->text(0) == tarfloorname)
                    {
                        if(tarroomname.isEmpty())
                        {
                            //插入楼层视图
                            QTreeWidgetItem * floordefaultview = flooritem->child(0);
                            QTreeWidgetItem * newitem = new QTreeWidgetItem(floordefaultview);
                            newitem->setText(0,viewname);
                            newitem->setData(0,Qt::UserRole,7);
                            newitem->setToolTip(0,newitem->text(0));
                            floordefaultview->addChild(newitem);

                        }
                        else
                        {
                            for(int k = 1; k < flooritem->childCount(); k++)
                            {
                                QTreeWidgetItem * roomitem = flooritem->child(k);
                                if(roomitem->text(0) == tarroomname)
                                {
                                    //插入房间视图
                                    QTreeWidgetItem * roomefaultview = roomitem->child(0);
                                    QTreeWidgetItem * newitem = new QTreeWidgetItem(roomefaultview);
                                    newitem->setText(0,viewname);
                                    newitem->setData(0,Qt::UserRole,7);
                                    newitem->setToolTip(0,newitem->text(0));
                                    roomefaultview->addChild(newitem);
                                    break;
                                }
                            }
                        }
                        break;
                    }

                }
            }

            break;
        }
    }
    //将此条记录写入到文件中

    QFile file("viewaddtotree.dat");
    QString views = "";
    if(file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QTextStream ts(&file);
        views = ts.readLine();
        views.append(tarbuildingname+tarfloorname+tarroomname+"*"+viewname+";");
        qDebug()<<"views"<<views;
        file.resize(0);
        ts.seek(0);
        ts<<views;
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("视图添加失败！"),tr("确定"));//这里要与界面上保持一致
        return;
    }
    file.close();
}

void RoomTreeWidget::locateAndOpenRoom(QString buildingname,QString floorname,QString roomname)
{
   qDebug()<<buildingname<<floorname<<roomname;

   QTreeWidgetItem * buidingitem = 0;
   for(int i = 1; i < topLevelItemCount(); i++)
   {
       if(topLevelItem(i)->text(0)==buildingname)
       {
           buidingitem = topLevelItem(i);
           break;
       }
   }
   if(buidingitem)
   {
       buidingitem->setExpanded(true);
       QTreeWidgetItem * flooritem = 0;
       for(int  i = 1; i < buidingitem->childCount(); i++)
       {
           if(buidingitem->child(i)->text(0) == floorname)
           {
               flooritem = buidingitem->child(i);
               break;
           }
       }
       if(flooritem)
       {
           flooritem->setExpanded(true);
           QTreeWidgetItem * roomitem = 0;

           for(int  i = 1; i < flooritem->childCount(); i++)
           {
               if(flooritem->child(i)->text(0)==roomname)
               {
                   roomitem = flooritem->child(i);
                   break;
               }
           }
           if(roomitem)
           {
               roomitem->setExpanded(true);
               emit lookuoViewSignal(buildingname,floorname,roomname);
           }
       }
   }

}


void RoomTreeWidget::createFloorRoom()
{
    //创建各个楼层和各个房间项目
    QTreeWidgetItem * systemviewitem = new QTreeWidgetItem(this);
    systemviewitem->setText(0,"系统概览");
    //systemviewitem->setTextAlignment(0,Qt::AlignCenter);
    systemviewitem->setTextColor(0,Qt::blue);
    QFont font;
    font.setPointSize(10);
    font.setBold(true);
    systemviewitem->setFont(0,font);
    systemviewitem->setData(0,Qt::UserRole,0);
    systemviewitem->setIcon(0,QIcon("images/systemview.jpg"));
    this->addTopLevelItem(systemviewitem);
    QFile viewfile("viewaddtotree.dat");
    QMultiMap<QString,QString> maptoview;
    if(viewfile.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QTextStream ts(&viewfile);
        QString viewsstr = ts.readLine();
        QStringList views = viewsstr.split(";");
        qDebug()<<"views"<<views.size()<<views;
        views.removeAt(views.size() - 1);
        qDebug()<<"views"<<views.size()<<views;
        for(int t = 0; t < views.size(); t++)
        {
            QString temp = views.at(t);
            QStringList bfrandviews = temp.split("*");
            maptoview.insert(bfrandviews.first(),bfrandviews.last());
        }
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("视图添加失败！"),tr("确定"));
    }
    viewfile.close();
    /*QFile file("buildingmaptofloor.dat");
    QStringList buildingmaptofloor;
    QMap<QString, QTreeWidgetItem*> buildings;
    if(file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        qDebug()<<"wenjiandakaichenggong";
        QTextStream ts(&file);
        QString str;
        while(!ts.atEnd())
        {
            str = "";
            str = ts.readLine();
            buildingmaptofloor<<str;
            QStringList list = str.split(":");
            QTreeWidgetItem * item = new QTreeWidgetItem(this);
            item->setIcon(0,QIcon("images/buildingitem.png"));
            item->setText(0,list.first());
            item->setData(0,Qt::UserRole,1);
            buildings[list.first()] = item;
            this->addTopLevelItem(item);
        }
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        return;
    }
    file.close();*/
    QStringList buildingmaptofloor;
    QMap<QString, QTreeWidgetItem*> buildings;
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery roomquery(globaldb);
        //构建楼宇
        roomquery.prepare("SELECT building_no,floorlist FROM buildingmaptofloor");
        roomquery.exec();
        while(roomquery.next())
        {
            buildingmaptofloor<<(roomquery.value(0).toString()+":"+roomquery.value(1).toString());
            QString tempbuildingname = roomquery.value(0).toString();
            tempbuildingname.remove(":");
            QTreeWidgetItem * item = new QTreeWidgetItem(this);
            item->setIcon(0,QIcon("images/buildingitem.png"));
            item->setText(0,tempbuildingname);
            item->setData(0,Qt::UserRole,1);
            buildings[tempbuildingname] = item;
            this->addTopLevelItem(item);
        }


        for(int i = 0; i < buildingmaptofloor.size(); i++)
        {
            QString str = buildingmaptofloor.at(i);

            QStringList list = str.split(":");
            QString buildingname = list.first();
            QTreeWidgetItem * buildingparent = buildings[buildingname];
            QTreeWidgetItem * flooritem = 0;
            QList<int> floornums;
            if(list.last().size() > 0)
            {
                QStringList floorslist;
                floorslist = list.last().split("*");

                for(int j = 0; j < floorslist.size(); j++)
                {
                    floornums.append(floorslist.at(j).toInt());
                }
                qSort(floornums.begin(),floornums.end());

            }

            qDebug()<<"floornums"<<floornums.size();
            for(int k = 0;k < floornums.size() ;k++)
            {
                int floornum = floornums.at(k);
                // qDebug()<<"floornum"<<floornum;

                if(floornum > floornames.size())
                {
                    QMessageBox::warning(0,tr("警告"),"第"+buildingname+floornum+"号房间创建失败！",tr("确定"));
                    return;
                }
                flooritem = new QTreeWidgetItem(buildingparent);
                flooritem->setIcon(0,QIcon("images/flooritem.png"));
                // qDebug()<<"floornum-1"<<floornum-1<<floornames.at(floornum-1);
                flooritem->setText(0,floornames.at(floornum-1));

                flooritem->setData(0,Qt::UserRole,2);





              //  floorviewitem->addChild(floorviewitem);

                /*QString roomquerystr = QString("SELECT room_name FROM device_info WHERE building_no = \"%1\" AND floor_no = %2 ORDER BY room_name ASC").arg(buildingname).arg(floornum);
               roomquery.exec(roomquerystr);*/
                roomquery.prepare("SELECT room_name FROM device_info WHERE building_no = ? AND floor_no = ? ORDER BY room_name ASC");
                roomquery.addBindValue(buildingname);
                roomquery.addBindValue(floornum);
                roomquery.exec();
                while(roomquery.next())
                {
                    //  QString roomname = roomquery.value(0).toString();
                    QString roomname = roomquery.value(0).toString();
                    qDebug()<<roomname;
                    qDebug()<<roomname.size();
                    // qDebug()<<roomname;
                    QTreeWidgetItem * roomitem = new QTreeWidgetItem(flooritem);
                    roomitem->setIcon(0,QIcon("images/roomitem.png"));
                    roomitem->setText(0,roomname);
                    roomitem->setData(0,Qt::UserRole,3);

                    QTreeWidgetItem * olderitem = new QTreeWidgetItem(roomitem);
                    olderitem->setIcon(0,QIcon("images/bedsitem.png"));
                    olderitem->setText(0,tr("床位信息"));
                    olderitem->setData(0,Qt::UserRole,5);
                    //读取数据库添加老人信息
                    QSqlQuery bedinfoquery(globaldb);
                    bedinfoquery.prepare("SELECT bitmap,bed_no FROM device_info WHERE building_no = ? AND floor_no = ? AND room_name = ? ORDER BY room_name ASC");
                    bedinfoquery.addBindValue(buildingname);
                    bedinfoquery.addBindValue(floornum);
                    bedinfoquery.addBindValue(roomname);
                    bedinfoquery.exec();

                    while(bedinfoquery.next())
                    {
                        int bedbits = bedinfoquery.value(0).toInt();
                        int bednum = bedinfoquery.value(1).toInt();
                        if(bednum >= 0 && bednum<=6)
                        {
                            int i = 0;
                            while(i < 6)
                            {
                                //bedbits
                                QTreeWidgetItem * beditem =0;
                                if(bedbits&0x002)
                                {
                                    beditem = new QTreeWidgetItem(olderitem);
                                    beditem->setIcon(0,QIcon("images/.jpg"));
                                    QSqlQuery olderquery(globaldb);
                                    olderquery.prepare("SELECT name,mat,device_id FROM elder_info WHERE building_no = ? AND floor_no = ? AND room_no = ? AND bed_no = ? AND valid = ?");
                                    olderquery.addBindValue(buildingname);
                                    olderquery.addBindValue(floornum);
                                    olderquery.addBindValue(roomname);
                                    olderquery.addBindValue(i+1);
                                    olderquery.addBindValue("1");
                                    olderquery.exec();
                                    QString olderstr = "有人";
                                    int hasmat = 0;
                                    int deviceid = -1;
                                    if(olderquery.next())
                                    {
                                        olderstr = olderquery.value(0).toString();
                                        hasmat = olderquery.value(1).toInt();
                                        deviceid = olderquery.value(2).toInt();

                                    }
                                   // beditem->setText(0,QString::number(i+1)+QString("号床 -- ")+olderstr);
                                   beditem->setText(0,QString::number(i+1)+QString("号床"));
                                    if(hasmat)
                                    {
                                        qDebug()<<"有床垫";
                                        quint8 bedbitset = (quint8)(pow(2,i));
                                        qDebug()<<"mat[deviceid].bitmap"<<deviceid<< mat[deviceid].bitmap;
                                        mat[deviceid].bitmap = mat[deviceid].bitmap|bedbitset;
                                        qDebug()<<"mat[deviceid].bitmap"<< mat[deviceid].bitmap;
                                    }
                                    else
                                    {
                                        qDebug()<<"无床垫";
                                    }
                                    olderquery.clear();
                                    olderquery.finish();
                                }
                                else if(bedbits&0x001)
                                {
                                    beditem = new QTreeWidgetItem(olderitem);
                                    beditem->setIcon(0,QIcon("images/.jpg"));;
                                    beditem->setText(0,QString::number(i+1)+QString("号床"));
                                }
                                if(beditem != 0)
                                {
                                    beditem->setData(0,Qt::UserRole,8);
                                    olderitem->addChild(beditem);
                                }
                                bedbits = bedbits>>2;
                                i++;
                            }
                        }
                    }
                    roomitem->addChild(olderitem);


                    flooritem->addChild(roomitem);
                }
            }
            buildingparent->addChild(flooritem);
        }
        roomquery.clear();
        roomquery.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"db is not open";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
}
void NameSelectDialog::showRightMenu(QPoint pos)
{
    QTableWidgetItem *curItem = tablewidget->itemAt(pos);
    if(curItem != NULL)
    {
        QMenu * detailright_menu = new QMenu;

        detailright_menu->addAction(detailinfo_action);
        detailright_menu->exec(QCursor::pos());
        delete detailright_menu;
    }
}
/*void NameSelectDialog::connectToDatabase()
{
    mysqldb = QSqlDatabase::addDatabase("QMYSQL","name_selectdialog");
    mysqldb.setHostName(serverIP);
    mysqldb.setPort(3306);
    mysqldb.setUserName(globalUserName);
    mysqldb.setPassword(globalUserName);
    mysqldb.setDatabaseName(globalDBName);
    if(!globaldb.open())
        qDebug()<<"fail to open";
    else
        qDebug()<<"succeed";
}*/
NameSelectDialog::NameSelectDialog(QWidget *parent) :
    QDialog(parent)
{
    tablewidget = new QTableWidget(this);
    tablewidget->setColumnCount(7);
    QStringList headnames;
    headnames<<tr("姓名")<<tr("性别")<<tr("楼名")<<tr("层号")<<tr("房间名")<<tr("床号")<<tr("身份证");
    tablewidget->setHorizontalHeaderLabels(headnames);
    //tablewidget->horizontalHeader()->setDefaultSectionSize(80);
    for(int i = 0; i < 6; i++)
    {
         tablewidget->setColumnWidth(i,80);
    }

    tablewidget->horizontalHeader()->setStretchLastSection(true);//设置满表宽度
    tablewidget->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    tablewidget->horizontalHeader()->setHighlightSections(false);
    tablewidget->verticalHeader()->setVisible(false);
    tablewidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tablewidget->setSelectionMode(QAbstractItemView::SingleSelection);
   // tablewidget->setShowGrid(false);
    tablewidget->setFocusPolicy(Qt::NoFocus);
    tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablewidget->setStyleSheet("selection-background-color:lightblue;");
    connect(tablewidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(onShowOlderInfo(int,int)));
    QVBoxLayout * vbl = new QVBoxLayout(this);
    vbl->addWidget(tablewidget);
    this->setLayout(vbl);
   // this->setWindowTitle(tr("重名选择"));
    detailinfo_action = new QAction(tr("详细信息"),this);
    connect(detailinfo_action,SIGNAL(triggered()),this,SLOT(onShowOlderInfo()));
    tablewidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tablewidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showRightMenu(QPoint)));
    //connectToDatabase();
    this->setFixedWidth(630);
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
}

void NameSelectDialog::loadNameBriefInfo(QString oldername)
{

    if( globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        query.prepare("SELECT name,gender,building_no,floor_no,room_no,bed_no,ic FROM elder_info WHERE  name = ? AND valid = ?");
        query.addBindValue(oldername);
        query.addBindValue("1");
        query.exec();

        int row = 0;
        tablewidget->setRowCount(query.size());
        while(query.next())
        {
            QString name = query.value(0).toString();
            QString gender = query.value(1).toString();
            QString buildingname = query.value(2).toString();
            QString floorname = floornames.at(query.value(3).toInt() - 1);
            QString roomname = query.value(4).toString();
            QString bed_no = query.value(5).toString() + "号床";
            QString ic = query.value(6).toString();

            QTableWidgetItem * item = new QTableWidgetItem(name);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            tablewidget->setItem(row,0,item);

            item = new QTableWidgetItem(gender);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            tablewidget->setItem(row,1,item);

            item = new QTableWidgetItem(buildingname);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            tablewidget->setItem(row,2,item);

            item = new QTableWidgetItem(floorname);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            tablewidget->setItem(row,3,item);

            item = new QTableWidgetItem(roomname);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            tablewidget->setItem(row,4,item);

            item = new QTableWidgetItem(bed_no);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            tablewidget->setItem(row,5,item);

            item = new QTableWidgetItem(ic);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            tablewidget->setItem(row,6,item);
            row++;
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
}
bool NameSelectDialog::loadFloorOlderBriefInfo(QString buildingname,QString floorname)
{
    int floornum = floornames.indexOf(floorname)+1;

    qDebug()<<"buildingname"<<buildingname<<"floornum"<<floornum;
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
    QSqlQuery query(globaldb);
    query.prepare("SELECT name,gender,building_no,floor_no,room_no,bed_no,ic FROM elder_info WHERE building_no = ? AND floor_no = ? AND valid = ?");
    query.addBindValue(buildingname);
    query.addBindValue(floornum);
    query.addBindValue("1");
    query.exec();
    int row = 0;
    if(query.size() <= 0)
    {
        QMessageBox::information(0,tr("提示"),buildingname+floorname+tr("无入住人员！"),tr("确定"));
        return false;
    }
    tablewidget->setRowCount(query.size());
    while(query.next())
    {
       // qDebug()<<"haha";
        QString name = query.value(0).toString();
        QString gender = query.value(1).toString();
        QString buildingname = query.value(2).toString();
        QString floorname = floornames.at(query.value(3).toInt() - 1);
        QString roomname = query.value(4).toString();
        QString bed_no = query.value(5).toString()+"号床";
        QString ic = query.value(6).toString();

        QTableWidgetItem * item = new QTableWidgetItem(name);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(row,0,item);

        item = new QTableWidgetItem(gender);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(row,1,item);

        item = new QTableWidgetItem(buildingname);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(row,2,item);

        item = new QTableWidgetItem(floorname);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(row,3,item);

        item = new QTableWidgetItem(roomname);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(row,4,item);

        item = new QTableWidgetItem(bed_no);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(row,5,item);

        item = new QTableWidgetItem(ic);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(row,6,item);


        row++;
    }
    query.clear();
    query.finish();
    //globaldb.close();
    return true;
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
        return false;
    }
}

void NameSelectDialog::onShowOlderInfo()
{
     int row = tablewidget->currentRow();
     int col = tablewidget->currentColumn();
     onShowOlderInfo(row,col);
}

void NameSelectDialog::onShowOlderInfo(int row,int col)
{
    QStringList args;
    args<<tablewidget->item(row,2)->text();
    args<<QString::number(floornames.indexOf(tablewidget->item(row,3)->text()) + 1);
    args<<tablewidget->item(row,4)->text();
    args<<tablewidget->item(row,5)->text().split("号").first();
    qDebug()<<args;
    ElderInfo eiadd(VIEWELDER,args);
    connect(&eiadd,SIGNAL(locateAndOpenRoom(QString,QString,QString)),this,SIGNAL(locateAndOpenRoom(QString,QString,QString)));
    eiadd.exec();
}

/*void NameSelectDialog::connectToDataBase()
{
    qDebug()<<"haha";
    db1 = QSqlDatabase::addDatabase("QMYSQL");
    db1.setHostName(serverIP);
    db1.setPort(3306);
    db1.setDatabaseName(globalDBName);
    db1.setUserName(globalUserName);
    db1.setPassword(globalUserName);
    QSqlError err;
    if(!db1.open())
    {
        err = db1.lastError();
        qDebug()<<err;
        qDebug()<<"databaseerror";
        QMessageBox::warning(0,tr("警告"),tr("数据库连接失败！"),tr("确定"));
    }
    else
    {
        qDebug()<<"connect succeed!";
    }
    db1.close();
}*/


OlderInfoWidget::OlderInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OlderInfoWidget)
{
    ui->setupUi(this);
    this->setFixedSize(538,347);
}

OlderInfoWidget::~OlderInfoWidget()
{
    delete ui;
}
void OlderInfoWidget::showOlderInfo(QStringList strlist,QByteArray data)
{
    ui->name_lineedit->setText(strlist.takeFirst());
    ui->sex_lineedit->setText(strlist.takeFirst());
    ui->birth_lineedit->setText(strlist.takeFirst());
    ui->bodystate_lineedit->setText(strlist.takeFirst());
    ui->servicetype_lineedit->setText(strlist.takeFirst());
    ui->mattress_lineedit->setText(strlist.takeFirst());
    ui->buildingno_lineedit->setText(strlist.takeFirst());
    ui->floorno_lineedit->setText(strlist.takeFirst());
    ui->roomno_lineedit->setText(strlist.takeFirst());
    ui->bedno_lineEdit->setText(strlist.takeFirst());
    ui->ic_lineedit->setText(strlist.takeFirst());
    ui->tel_lineedit->setText(strlist.takeFirst());
    ui->contactor_lineedit->setText(strlist.takeFirst());
    ui->contactortellineedit->setText(strlist.takeFirst());
    QImage photo;
    photo.loadFromData(data);
    ui->photo_label->setPixmap(QPixmap::fromImage(photo).scaled(90,120));
}
//添加楼
AddBuildingDialog::AddBuildingDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("添加楼名"));
    QHBoxLayout * addolder_hbl = new QHBoxLayout;
    addolder_label = new QLabel(tr("输入楼名："),this);
    addolder_lineedit = new QLineEdit(this);
    connect(addolder_lineedit,SIGNAL(textChanged(QString)),this,SLOT(onBuildingNameChanged(QString)));
    addolder_hbl->addWidget(addolder_label);
    addolder_hbl->addWidget(addolder_lineedit);
    QHBoxLayout * btn_hbl = new QHBoxLayout;
    confirm_pushbutton = new QPushButton(tr("确定"),this);
    connect(confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    cancel_pushbutton = new QPushButton(tr("取消"),this);
    connect(cancel_pushbutton,SIGNAL(clicked()),this,SLOT(onCancelPushButton()));
    btn_hbl->addSpacing(120);
    btn_hbl->setSizeConstraint(QLayout::SetMinimumSize);
    btn_hbl->addWidget(confirm_pushbutton);
    btn_hbl->addWidget(cancel_pushbutton);
    QVBoxLayout * vbl = new QVBoxLayout;
    vbl->addLayout(addolder_hbl);
    vbl->addLayout(btn_hbl);
    setLayout(vbl);
    setFixedWidth(220);
    setFixedHeight(80);
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);

}
void AddBuildingDialog::onBuildingNameChanged(QString tempbuildingname)
{
    qDebug()<<tempbuildingname;
    bool flag = false;
    for(int i = 0; i < tempbuildingname.count(); i++)
    {
        QChar ch = tempbuildingname.at(i);
        ushort  dig= ch.unicode();
        qDebug()<<ch<<"unicodeshort"<<hex<<dig;
        if(!((dig >= 0x4E00 && dig <= 0x9FBF) ||ch.isDigit()))
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        addolder_lineedit->setText(oldbuildingname);
        QMessageBox::warning(0,"警告","请输入中文作为楼名！","确定");
    }
    else
    {
        if(tempbuildingname.count() > 7)
        {
            addolder_lineedit->setText(oldbuildingname);
            QMessageBox::warning(0,"警告","楼名最大长度为7！","确定");
        }
        else
            oldbuildingname = addolder_lineedit->text();
    }

}

void AddBuildingDialog::onConfirmPushButton()
{
    QString buildingname = addolder_lineedit->text();
    if(buildingname.isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("楼名为空，请重新输入！"),tr("确定"));
        return;
    }
    /*if(buildingname.right(1) != "楼")
        buildingname.append("楼");*/
    QTreeWidget * treewidget = qobject_cast<QTreeWidget *>(this->parent());
    int topitemcount =  treewidget->topLevelItemCount();
    for(int i = 0; i < topitemcount; i++)
    {
        if(!QString::compare(treewidget->topLevelItem(i)->text(0),buildingname,Qt::CaseInsensitive))
        {
           QMessageBox::warning(0,tr("警告"),tr("该楼已存在，请重新输入！"),tr("确定"));
           return;
        }
    }
    QTreeWidgetItem * item = new QTreeWidgetItem(treewidget);
    item->setText(0,buildingname);
    item->setIcon(0,QIcon("images/buildingitem.png"));
    item->setData(0,Qt::UserRole,1);
    treewidget->addTopLevelItem(item);
    /*QTreeWidgetItem * buildingviewitem = new QTreeWidgetItem(item);
    buildingviewitem->setText(0,tr("楼层视图"));
    buildingviewitem->setIcon(0,QIcon("images/viewsitem.jpg"));
    buildingviewitem->setData(0,Qt::UserRole,4);
    item->addChild(buildingviewitem);*/
    insertLog("添加楼："+buildingname);
    if(hassursys)
    {
        smt->sendAddBuilding(buildingname);
    }
    emit addBuilding(buildingname);

    saveBuildingMapToFloor(buildingname);

    this->accept();
}
void AddBuildingDialog::onCancelPushButton()
{
    this->reject();
}

void AddBuildingDialog::saveBuildingMapToFloor(QString buildingname)
{
        /*QFile file("buildingmaptofloor.dat");
        if(file.open(QIODevice::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"wenjiandakaichenggong";
            QTextStream ts(&file);

            while(!ts.atEnd())
            {
                ts.readLine();
            }
            ts<<buildingname<<":"<<'\n';
        }
        else
        {
            QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
            return;
        }*/
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        //构建楼宇
        query.prepare("INSERT INTO  buildingmaptofloor(building_no,floorlist) VALUES(?,?)");
        query.addBindValue(buildingname);
        query.addBindValue("");
        query.exec();

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


//添加楼层
AddFloorDialog::AddFloorDialog(QTreeWidgetItem * item,QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle(tr("添加楼层"));
    parentitem = item;
    floorlistwidget = new QListWidget(this);
    floorlistwidget->setFocusPolicy(Qt::NoFocus);
    //floornames<<"一楼"<<"二楼"<<"三楼"<<"四楼"<<"五楼"<<"六楼"<<"七楼"<<"八楼"<<"九楼"<<"十楼";
    floorlistwidget->addItems(floornames);
    confirm_pushbutton = new QPushButton(tr("确定"),this);
    connect(confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    cancel_pushbutton = new QPushButton(tr("取消"),this);
    connect(cancel_pushbutton,SIGNAL(clicked()),this,SLOT(onCancelPushButton()));

    QHBoxLayout * hbl = new QHBoxLayout;
    hbl->addWidget(confirm_pushbutton);
    hbl->addWidget(cancel_pushbutton);
    QVBoxLayout * vbl = new QVBoxLayout;
    vbl->addWidget(floorlistwidget);
    vbl->addLayout(hbl);
    this->setLayout(vbl);
    this->setFixedSize(QSize(150,200));
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);

}


void AddFloorDialog::onConfirmPushButton()
{
    int floornum = floornames.indexOf(floorlistwidget->currentItem()->text());
    int childcount = parentitem->childCount();
    int i=0;
    for(i = 0; i < childcount; i++)
    {
        int temp = floornames.indexOf(parentitem->child(i)->text(0));
        if(floornum < temp)
        {
            break;
        }
        else if(floornum == temp)
        {
            QMessageBox::warning(0,tr("警告"),tr("该楼层已存在！"),tr("确定"));
            return;
        }
    }
    /*QFile file("buildingmaptofloor.dat");
    QStringList list;
    if(file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QTextStream ts(&file);
        while(!ts.atEnd())
        {
            QString str = ts.readLine();
            list<<str;
            if(str.split(":").first() == parentitem->text(0))
            {
                if(list.last().size() ==  parentitem->text(0).size() + 1)
                    list.last().append(QString("%1").arg(floornum + 1));
                else
                    list.last().append(QString("*%1").arg(floornum + 1));
            }
        }

        file.resize(0);
        ts.seek(0);
        for(int j = 0; j < list.size(); j++)
        {
            ts<<list.at(j)<<'\n';
        }


    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        this->reject();
        return;
    }
    file.close();*/

    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        query.prepare("SELECT floorlist FROM buildingmaptofloor WHERE building_no = ?");
        query.addBindValue(parentitem->text(0));
        query.exec();
        query.next();
        QString floorliststr = query.value(0).toString();
        if(floorliststr.isEmpty())
        {
            floorliststr.append(QString::number(floornum+1));
        }
        else
        {
            floorliststr.append("*").append(QString::number(floornum+1));
        }
        query.prepare("UPDATE buildingmaptofloor SET floorlist = ? WHERE building_no = ?");
        query.addBindValue(floorliststr);
        query.addBindValue(parentitem->text(0));
        query.exec();
        QTreeWidgetItem * item = new QTreeWidgetItem;
        item->setText(0,floorlistwidget->currentItem()->text());
        item->setIcon(0,QIcon("images/flooritem.png"));
        item->setData(0,Qt::UserRole,2);
        qDebug()<<"i"<<i<<"floornum"<<floornum;
        parentitem->insertChild(i,item);
        /*QTreeWidgetItem * floorviewitem = new QTreeWidgetItem(item);
    floorviewitem->setText(0,tr("楼层视图"));
    floorviewitem->setIcon(0,QIcon("images/viewsitem.jpg"));
    floorviewitem->setData(0,Qt::UserRole,4);
    item->addChild(floorviewitem);*/
        QTreeWidget * treewidget = qobject_cast<QTreeWidget *>(parentWidget());
        insertLog("增加楼层：" + parentitem->text(0) + floorlistwidget->currentItem()->text());
        if(hassursys)
        {
            smt->sendAddFloor(parentitem->text(0),floorlistwidget->currentItem()->text());
        }
        qDebug()<<"界面增加楼层成功";
        emit addFloor(treewidget->indexOfTopLevelItem(parentitem),floornum + 1,i);

        this->accept();
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }

}

void AddFloorDialog::onCancelPushButton()
{

    this->reject();
}
//添加房间
AddRoomDialog::AddRoomDialog(QTreeWidgetItem * item,QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("添加房间"));
    curitem = item;
    QHBoxLayout * addroom_hbl = new QHBoxLayout;
    addroom_label = new QLabel(tr("房间名："),this);
    addroom_lineedit = new QLineEdit(this);
    connect(addroom_lineedit,SIGNAL(textChanged(QString)),this,SLOT(onRoomNameChanged(QString)));
    addroom_hbl->addWidget(addroom_label);
    addroom_hbl->addWidget(addroom_lineedit);

    QHBoxLayout * setmonitor_hbl = 0;
    if(hassursys)
    {
        setmonitor_hbl = new QHBoxLayout;
        setmonitor_checkbox = new QCheckBox("将房间加入监测范围",this);
        setmonitor_hbl->addStretch(60);
        setmonitor_hbl->addWidget(setmonitor_checkbox);
        setmonitor_hbl->addStretch(40);
    }


    QHBoxLayout *direction_hbl = new QHBoxLayout;
    label_direction = new QLabel(tr("房间朝向："),this);
    combox_direction = new QComboBox(this);
    combox_direction->addItem(tr(" "));
    combox_direction->addItem(tr("朝南"));
    combox_direction->addItem(tr("朝北"));
    combox_direction->addItem(tr("朝西"));
    combox_direction->addItem(tr("朝东"));
    direction_hbl->addWidget(label_direction);
    direction_hbl->addWidget(combox_direction);
    QHBoxLayout * btn_hbl = new QHBoxLayout;
    confirm_pushbutton = new QPushButton(tr("确定"),this);
    connect(confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    cancel_pushbutton = new QPushButton(tr("取消"),this);
    connect(cancel_pushbutton,SIGNAL(clicked()),this,SLOT(onCancelPushButton()));
//    btn_hbl->addSpacing(80);
    btn_hbl->setSizeConstraint(QLayout::SetMinimumSize);
    btn_hbl->addWidget(confirm_pushbutton);
    btn_hbl->addWidget(cancel_pushbutton);
    QVBoxLayout * vbl = new QVBoxLayout;
    vbl->addLayout(addroom_hbl);
    if(hassursys)
        vbl->addLayout(setmonitor_hbl);
    vbl->addLayout(direction_hbl);
    vbl->addLayout(btn_hbl);
    setLayout(vbl);
    setFixedWidth(180);
    if(hassursys)
        setFixedHeight(160);
    else
        setFixedHeight(130);
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
}

void AddRoomDialog::onRoomNameChanged(QString temproomname)
{
    qDebug()<<temproomname;
    bool flag = false;
    for(int i = 0; i < temproomname.count(); i++)
    {
        QChar ch = temproomname.at(i);
        if(!ch.isDigit()&&!ch.isUpper())
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        addroom_lineedit->setText(oldroomname);
        QMessageBox::warning(0,"警告","请输入大写字母或数字作为房间名！","确定");
    }
    else
    {
        if(temproomname.count() > 5)
        {
            addroom_lineedit->setText(oldroomname);
            QMessageBox::warning(0,"警告","房间名最大长度为5！","确定");
        }
        else
            oldroomname = addroom_lineedit->text();
    }

}

void AddRoomDialog::onConfirmPushButton()
{
    QString roomname = addroom_lineedit->text();
    QString direction = combox_direction->currentText();
    if(roomname.isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("房间名为空，请重新输入！"),tr("确定"));
        return;
    }
    QTreeWidgetItem * buildingitem = curitem->parent();
   for(int j = 0; j < buildingitem->childCount();j++)
    {
        QTreeWidgetItem * flooritem = buildingitem->child(j);
        int childcount = flooritem->childCount();
        /*if(!QString::compare(flooritem->child(0)->text(0),roomname,Qt::CaseInsensitive))
        {
            QMessageBox::warning(0,tr("警告"),tr("该名称已用作楼层视图！"),tr("确定"));
            return;
        }*/

        for(int i = 0; i < childcount; i++)
        {
            if(!QString::compare(flooritem->child(i)->text(0),roomname,Qt::CaseInsensitive))
            {
                QMessageBox::warning(0,tr("警告"),tr("该房间已存在，请重新输入！"),tr("确定"));
                return;
            }
        }
    }
   qDebug()<<"查重已过";

    //连接数据库进行处理
   if(globaldb.open())
   {
       if(!dbisconnected)
       {
           dbisconnected = true;
           raao->setAppEnable(true);
       }
       // QStringList floornames;
       // floornames<<"一楼"<<"二楼"<<"三楼"<<"四楼"<<"五楼"<<"六楼"<<"七楼"<<"八楼"<<"九楼"<<"十楼";
       QString buildingno = curitem->parent()->text(0);
       int floorno = floornames.indexOf(curitem->text(0))+1;
       qDebug()<<buildingno<<floorno<<roomname;
       QSqlQuery query(globaldb);
       query.exec("SELECT device_id FROM device_info");
       QList<int> deviceids;
       while(query.next())
       {
           deviceids.append(query.value(0).toInt());
       }
       qSort(deviceids.begin(),deviceids.end());
       int i = 0;
       for(i = 0;i < deviceids.size() ; i++)
       {
           if(i < deviceids.at(i)) break;
       }
       int newdeviceid = 0;
       if( i == deviceids.size()) newdeviceid = i;
       else newdeviceid = i;

       qDebug()<<"addroom"<<newdeviceid<<buildingno<<floorno<<roomname;
       // query.prepare("INSERT INTO device_info (building_no,floor_no,room_name,bitmap,bed_no) VALUES (?,?,?,?,?)");
       if(hassursys)
       {
           query.prepare("INSERT INTO device_info (device_id,building_no, floor_no, room_name, room_direction,bitmap, bed_no,temperature_id,moisture_id,O2_id,CO2_id,index_id,voltage1_id,voltage2_id,running_state) VALUES (?, ?, ?, ?, ?, ?,?,?,?,?,?,?,?,?,?)");

       }
       else
       {
           query.prepare("INSERT INTO device_info (device_id,building_no, floor_no, room_name, room_direction,bitmap, bed_no,temperature_id,moisture_id,O2_id,CO2_id,index_id,voltage1_id,voltage2_id) VALUES (?, ?, ?, ?, ?, ?,?,?,?,?,?,?,?,?)");
       }
       query.addBindValue(newdeviceid);
       query.addBindValue(buildingno);
       query.addBindValue(floorno);
       query.addBindValue(roomname);
       query.addBindValue(direction);
       query.addBindValue(0);
       query.addBindValue(0);
       query.addBindValue(0);
       query.addBindValue(0);
       query.addBindValue(0);
       query.addBindValue(0);
       query.addBindValue(0);
       query.addBindValue(0);
       query.addBindValue(0);
       if(hassursys)
           query.addBindValue(setmonitor_checkbox->isChecked());
       query.exec();


       roomnameToIds[curitem->parent()->text(0)+":"+curitem->text(0)+":"+roomname] = newdeviceid;
       totalroomcount++;
       if(totalroomcount - 1 == curmaxroomid)
       {
           curmaxroomid = totalroomcount;
       }
       insertLog("添加房间："+curitem->parent()->text(0)+curitem->text(0) + roomname);
       QTreeWidget * treewidget = qobject_cast<QTreeWidget *>(parentWidget());
       //向环境监测系统发送添加房间信息
       if(hassursys)
       {
           smt->sendAddRoom(curitem->parent()->text(0),curitem->text(0),roomname,setmonitor_checkbox->isChecked());
       }
       //emit addRoom(treewidget->indexOfTopLevelItem(curitem->parent()),curitem->parent()->indexOfChild(curitem),roomname);此处参数需要进一步考虑

       qDebug()<<"roomtreewidgetaddroom";
       QTreeWidgetItem * roomitem = new QTreeWidgetItem;
       roomitem->setText(0,roomname);
       roomitem->setIcon(0,QIcon("images/roomitem.png"));
       roomitem->setData(0,Qt::UserRole,3);
       for( i = 0;i < curitem->childCount(); i++)
       {
           if(QString::compare(curitem->child(i)->text(0),roomname,Qt::CaseInsensitive) >= 0)
           {
               break;
           }
       }

       qDebug()<<"roomtreewidgetaddroom"<<i<<roomitem->text(0)<<curitem->childCount();
       curitem->insertChild(i,roomitem);

       qDebug()<<"roomtreewidgetaddroom"<<i<<roomitem->text(0);
       /*QTreeWidgetItem * viewitem = new QTreeWidgetItem(roomitem);
       viewitem->setText(0,tr("房间视图"));
       viewitem->setIcon(0,QIcon("images/viewsitem.jpg"));
       viewitem->setData(0,Qt::UserRole,4);
       roomitem->addChild(viewitem);
       qDebug()<<"roomtreewidgetaddroom"<<i<<roomitem->text(0);

       QTreeWidgetItem * defaultviewitem = new QTreeWidgetItem(viewitem);
       defaultviewitem->setText(0,tr("默认视图"));
       defaultviewitem->setData(0,Qt::UserRole,6);
       viewitem->addChild(defaultviewitem);*/

       QTreeWidgetItem * beditem = new QTreeWidgetItem(roomitem);
       beditem->setText(0,tr("床位"));
       beditem->setIcon(0,QIcon("images/bedsitem.png"));
       beditem->setData(0,Qt::UserRole,5);
       roomitem->addChild(beditem);

       query.clear();
       query.finish();
       //globaldb.close();
       this->accept();

       //return;
   }
   else
   {
       qDebug()<<"打开失败";
       if(dbisconnected)
       {
           dbisconnected = false;
           raao->setAppEnable(false);
           QMessageBox::warning(0,"警告","数据库连接失败！","确定");
       }
       accept();
   }
}
void AddRoomDialog::onCancelPushButton()
{
    this->reject();
}

DelRoomProcessDialog::DelRoomProcessDialog(QWidget *parent):
    QDialog(parent)
{
    timer = new QTimer(this);
    count = 1;
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
    probar = new QProgressBar(this);
    probar->setTextVisible(false);
    probar->setRange(0,5);
    QHBoxLayout * hbl = new QHBoxLayout;
    hbl->addWidget(probar);
    this->setLayout(hbl);
    this->setFixedWidth(150);
    setWindowFlags(this->windowFlags()&~Qt::WindowCloseButtonHint);

}
void DelRoomProcessDialog::startCount()
{
    timer->start(1000);
}

void DelRoomProcessDialog::onTimer()
{
   probar->setValue(count);
   if(count ==5)
   {
       timer->stop();
       this->reject();
       return;
   }
   count++;
}
int DelRoomProcessDialog::getCount()
{
    return count;
}

//添加床位
AddBedDialog::AddBedDialog(QTreeWidgetItem * item,QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle(tr("添加床位"));
    parentitem = item;
    bedlistwidget = new QListWidget(this);
    bedlistwidget->setFocusPolicy(Qt::NoFocus);
    bednames<<"1号床"<<"2号床"<<"3号床"<<"4号床"<<"5号床"<<"6号床";
    bedlistwidget->addItems(bednames);
    confirm_pushbutton = new QPushButton(tr("确定"),this);
    connect(confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    cancel_pushbutton = new QPushButton(tr("取消"),this);
    connect(cancel_pushbutton,SIGNAL(clicked()),this,SLOT(onCancelPushButton()));

    QHBoxLayout * hbl = new QHBoxLayout;
    hbl->addWidget(confirm_pushbutton);
    hbl->addWidget(cancel_pushbutton);
    QVBoxLayout * vbl = new QVBoxLayout;
    vbl->addWidget(bedlistwidget);
    vbl->addLayout(hbl);
    this->setLayout(vbl);
    this->setFixedSize(QSize(150,150));
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);

}


void AddBedDialog::onConfirmPushButton()
{
    int bednum = bednames.indexOf(bedlistwidget->currentItem()->text());
    int childcount = parentitem->childCount();
    int i=0;
    for(i = 0; i < childcount; i++)
    {
        int temp = bednames.indexOf(parentitem->child(i)->text(0).left(3));
        if(bednum < temp)
        {
            break;
        }
        else if(bednum == temp)
        {
            QMessageBox::warning(0,tr("警告"),tr("该床位已存在！"),tr("确定"));
            return;
        }
    }
        if( globaldb.open())
        {
            if(!dbisconnected)
            {
                dbisconnected = true;
                raao->setAppEnable(true);
            }
            QString buildingname = parentitem->parent()->parent()->parent()->text(0);
            int floorno = floornames.indexOf(parentitem->parent()->parent()->text(0))+1;
            QString roomname = parentitem->parent()->text(0);
            qDebug()<<buildingname<<floorno<<roomname;
            QSqlQuery query(globaldb);
            //QString querystr = QString("SELECT device_id,bitmap,bed_no FROM device_info WHERE building_no = \"%1\" AND floor_no = %2 AND room_name = %3").arg(buildingname).arg(floorno).arg(roomname);
            query.prepare("SELECT device_id,bitmap,bed_no FROM device_info WHERE building_no = ? AND floor_no = ? AND room_name = ?");
            query.addBindValue(buildingname);
            query.addBindValue(floorno);
            query.addBindValue(roomname);
            query.exec();
            if(query.next())
            {
                int bedbits = query.value(1).toInt();
                int x = 1;
                for(int m = 0 ; m < bednum; m++)
                    x = x<<2;
                bedbits ^= x;
                qDebug()<<bedbits;
                int devicenum = query.value(0).toInt();
                int temp = query.value(2).toInt()+1;
                // qDebug()<<query.value(0).toInt()<<bedbits<<query.value(2).toInt();
                //QString updatedevicestr = QString("UPDATE device_info SET bitmap = %1,bed_no = %2 WHERE device_id = %3").arg(bedbits).arg(query.value(2).toInt()+1).arg(devicenum);
                //query.exec(updatedevicestr);
                query.prepare("UPDATE device_info SET bitmap = ?,bed_no = ? WHERE device_id = ?");
                query.addBindValue(bedbits);
                query.addBindValue(temp);
                query.addBindValue(devicenum);
                query.exec();
                query.clear();
                query.finish();
                insertLog("添加床位：" + parentitem->parent()->parent()->parent()->text(0) + parentitem->parent()->parent()->text(0)+parentitem->parent()->text(0)+bedlistwidget->currentItem()->text());
                if(hassursys)
                {
                    smt->sendAddBed(parentitem->parent()->parent()->parent()->text(0),parentitem->parent()->parent()->text(0),parentitem->parent()->text(0),bedlistwidget->currentItem()->text());
                }
                QTreeWidgetItem * item = new QTreeWidgetItem;
                item->setText(0,bedlistwidget->currentItem()->text());
                item->setData(0,Qt::UserRole,8);
                qDebug()<<"i"<<i<<"bednum"<<bednum;
                parentitem->insertChild(i,item);
                query.clear();
                query.finish();
                //globaldb.close();
                this->accept();
            }
            else
            {
                query.clear();
                query.finish();
                if(dbisconnected)
                {
                    dbisconnected = false;
                    raao->setAppEnable(false);
                    QMessageBox::warning(0,"警告","数据库连接失败！","确定");
                }
                //globaldb.close();
                reject();
            }

            //return;
        }
        else
        {
            if(dbisconnected)
            {
                dbisconnected = false;
                raao->setAppEnable(false);
                QMessageBox::warning(0,"警告","数据库连接失败！","确定");
            }
            accept();
        }



}

void AddBedDialog::onCancelPushButton()
{

    this->reject();
}



//添加老人
AddOlderDialog::AddOlderDialog(QTreeWidgetItem *curitem,QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("添加入住人员"));
    this->curitem = curitem;
    QString bedname = curitem->text(0);
    QString floorname = curitem->parent()->parent()->parent()->text(0);
    int floorno =  floornames.indexOf(floorname)+1;
    this->buildingname = curitem->parent()->parent()->parent()->parent()->text(0);
    this->floorno = floorno;
    this->roomname = curitem->parent()->parent()->text(0);
    this->bedno = bedname.left(1).toInt();
    QHBoxLayout * addolder_hbl = new QHBoxLayout;
    addolder_label = new QLabel(tr("入住人员姓名："),this);
    addolder_lineedit = new QLineEdit(this);
    addolder_hbl->addWidget(addolder_label);
    addolder_hbl->addWidget(addolder_lineedit);
    QHBoxLayout * btn_hbl = new QHBoxLayout;
    confirm_pushbutton = new QPushButton(tr("确定"),this);
    connect(confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    cancel_pushbutton = new QPushButton(tr("取消"),this);
    connect(cancel_pushbutton,SIGNAL(clicked()),this,SLOT(onCancelPushButton()));
    btn_hbl->addSpacing(120);
    btn_hbl->setSizeConstraint(QLayout::SetMinimumSize);
    btn_hbl->addWidget(confirm_pushbutton);
    btn_hbl->addWidget(cancel_pushbutton);
    QVBoxLayout * vbl = new QVBoxLayout;
    vbl->addLayout(addolder_hbl);
    vbl->addLayout(btn_hbl);
    setLayout(vbl);
   // d.exec();
    setFixedWidth(220);
    setFixedHeight(80);
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
}

void AddOlderDialog::onConfirmPushButton()
{

    QString oldername = addolder_lineedit->text();
    if(oldername.isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("人名为空,请重新输入！"),tr("确定"));
        return;
    }
    else
    {
        if(globaldb.open())
        {
            if(!dbisconnected)
            {
                dbisconnected = true;
                raao->setAppEnable(true);
            }
            //这里是否每一条query语句都要执行判断语句？
            qDebug()<<"succeed";
            QSqlQuery query(globaldb);
            query.prepare("INSERT INTO elder_info (name,building_no,floor_no,room_no,bed_no) VALUES(?,?,?,?,?)");
            query.addBindValue(oldername);
            query.addBindValue(buildingname);
            query.addBindValue(floorno);
            query.addBindValue(roomname);
            query.addBindValue(bedno);
            qDebug()<<oldername;
            qDebug()<<buildingname;
            qDebug()<<floorno;
            qDebug()<<roomname;
            qDebug()<<bedno;
            query.exec();
            if(query.isActive())
            {
                QString textstr =QString("%1号床 -- %2").arg(bedno).arg(addolder_lineedit->text());
                curitem->setText(0,textstr);
                accept();
               // query.clear();
               // query.finish();
            }
            else
            {
                QMessageBox::warning(0,tr("警告"),tr("数据库写入失败！"),tr("确定"));
                reject();
            }
            //QSqlQuery query2(db);
            query.prepare("SELECT device_id,bitmap,bed_no FROM device_info WHERE building_no = ? AND floor_no = ? AND room_name = ?");
            query.addBindValue(buildingname);
            query.addBindValue(floorno);
            query.addBindValue(roomname);
            query.exec();
            if(query.next())
            {
                int bedbits = query.value(1).toInt();
                int x = 3;
                for(int i = 0 ; i < bedno - 1; i++)
                    x = x<<2;

                bedbits ^= x;
                qDebug()<<bedbits;
                int devicenum = query.value(0).toInt();
                query.prepare("UPDATE elder_info SET device_id = ? WHERE building_no = ? AND floor_no = ? AND room_no = ? AND bed_no = ?");
                query.addBindValue(devicenum);
                query.addBindValue(buildingname);
                query.addBindValue(floorno);
                query.addBindValue(roomname);
                query.addBindValue(bedno);
                query.exec();
                query.exec("UPDATE device_info SET bitmap = ? WHERE device_id = ?");
                query.addBindValue(bedbits);
                query.addBindValue(devicenum);
                query.exec();
                query.clear();
                query.finish();
            }
            else
            {
                QMessageBox::warning(0,tr("警告"),tr("数据库读取失败！"),tr("确定"));
                reject();
            }
            //globaldb.close();

            //return;
        }
        else
        {
            qDebug()<<"打开失败";
            if(dbisconnected)
            {
                dbisconnected = false;
                raao->setAppEnable(false);
                QMessageBox::warning(0,"警告","数据库连接失败！","确定");
            }
            accept();
        }
    }

}

void AddOlderDialog::onCancelPushButton()
{
    this->accept();
}



DelOlderDialog::DelOlderDialog(QTreeWidgetItem *curitem,QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("删除入住人员"));
    this->curitem = curitem;
    QString bedname = curitem->text(0);
    QString floorname = curitem->parent()->parent()->parent()->text(0);
    int floorno =  floornames.indexOf(floorname)+1;
    this->buildingname = curitem->parent()->parent()->parent()->parent()->text(0);
    this->floorno = floorno;
    this->roomname = curitem->parent()->parent()->text(0);
    this->bedno = bedname.left(1).toInt();
    warning_lable =  new QLabel(tr("删除该床位入住人员"),this);
    //warning_lable->setAlignment(Qt::AlignCenter);
    delabs_checkbox = new QCheckBox(tr("彻底删除该入住人员所有信息"),this);

    confirm_pushbutton = new QPushButton(tr("确定"),this);
    connect(confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    cancel_pushbutton = new QPushButton(tr("取消"),this);
    connect(cancel_pushbutton,SIGNAL(clicked()),this,SLOT(onCancelPushButton()));

    QHBoxLayout * hbl = new QHBoxLayout;
    hbl->addSpacing(120);
    hbl->addWidget(confirm_pushbutton);
    hbl->addWidget(cancel_pushbutton);
    hbl->setMargin(0);
    QVBoxLayout * vbl = new QVBoxLayout;
    vbl->addWidget(warning_lable);
    vbl->addSpacing(15);
    vbl->addWidget(delabs_checkbox);
    vbl->addLayout(hbl);
    this->setLayout(vbl);
    setFixedWidth(200);
    setFixedHeight(100);
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);

}

void DelOlderDialog::onConfirmPushButton()
{


    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        if(!delabs_checkbox->isChecked())
        {
            qDebug()<<"QString(mn).toInt()"<<QString("mn").toInt();
            /*QString delrelstr = QString("UPDATE elder_info SET device_id = %1"\
                                        "WHERE building_no = \"%2\" AND floor_no = %3 AND room_no = %4 AND bed_no = %5").arg(NULL).arg(buildingname).arg(floorno).arg(roomname).arg(bedno);*/
            /*query.prepare("UPDATE elder_info SET device_id = ?,building_no = ?,floor_no = ?,room_no = ?,bed_no = ? WHERE building_no = ? AND floor_no = ? AND room_no = ? AND bed_no = ?");
            query.addBindValue(QVariant(QVariant::Int));
            query.addBindValue(QVariant(QVariant::String));
            query.addBindValue(QVariant(QVariant::Int));
            query.addBindValue(QVariant(QVariant::String));
            query.addBindValue(QVariant(QVariant::Int));*/

            query.prepare("UPDATE elder_info SET valid = ? WHERE building_no = ? AND floor_no = ? AND room_no = ? AND bed_no = ?");
            query.addBindValue("0");
            query.addBindValue(buildingname);
            query.addBindValue(floorno);
            query.addBindValue(roomname);
            query.addBindValue(bedno);
            query.exec();
            qDebug()<<"haha";
            if(query.isActive())
            {
                qDebug()<<"chenggong";
                curitem->setText(0,curitem->text(0).left(3));
            }

        }
        else
        {
            //QString delabsstr = QString("DELETE FROM elder_info WHERE building_no = \"%1\" AND floor_no = %2 AND room_name = %3").arg(buildingname).arg(floorno).arg(roomname) ;
            //query.exec(delabsstr);
            qDebug()<<"chedishanchu";
            query.prepare("DELETE FROM elder_info WHERE building_no = ? AND floor_no = ? AND room_no = ? AND bed_no = ? AND valid = ?");
            query.addBindValue(buildingname);
            query.addBindValue(floorno);
            query.addBindValue(roomname);
            query.addBindValue(bedno);
            query.addBindValue("1");
            query.exec();
            if(query.isActive())
            {
                qDebug()<<"chenggong";
                curitem->setText(0,curitem->text(0).left(3));
            }
        }
        QString querystr = QString("SELECT device_id,bitmap,bed_no FROM device_info WHERE building_no = \"%1\" AND floor_no = %2 AND room_name = %3").arg(buildingname).arg(floorno).arg(roomname);


        query.prepare("SELECT device_id,bitmap,bed_no FROM device_info WHERE building_no = ? AND floor_no = ? AND room_name = ?");
        query.addBindValue(buildingname);
        query.addBindValue(floorno);
        query.addBindValue(roomname);
       // query.exec(querystr);
        query.exec();
        if(query.next())
        {
            int bedbits = query.value(1).toInt();
            int x = 3;
            for(int i = 0; i < bedno -1; i++)
                x = x<<2;
            bedbits ^= x;
            qDebug()<<bedbits;
            int devicenum = query.value(0).toInt();
           // QString updatedevicestr = QString("UPDATE device_info SET bitmap = %1 WHERE device_id = %2").arg(bedbits).arg(devicenum);
           // query.exec(updatedevicestr);
            query.prepare("UPDATE device_info SET bitmap = ? WHERE device_id = ?");
            query.addBindValue(bedbits);
            query.addBindValue(devicenum);
            query.exec();
            query.clear();
            query.finish();
            mat[devicenum].bitmap = mat[devicenum].bitmap&(~(1<<(bedno - 1)));
        }
        else
        {
            QMessageBox::warning(0,tr("警告"),tr("数据库连接失败！"),tr("确定"));
            reject();
        }
        query.clear();
        query.finish();
        //globaldb.close();
        this->accept();
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }

}

void DelOlderDialog::onCancelPushButton()
{
    this->reject();
}



