#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QToolBox>
#include <QVariantList>
#include <QSqlDatabase>
#include <QBitArray>

enum {all,reside,order,holiday,available,none,rssdstate = 15};
enum {simple_or,simple_and,advanced};//查询等级标志
enum {adv_normal,adv_upalarm,adv_downalarm};


class QAbstractButton;
class RoomStateSearchDialog;
class QListWidgetItem;
class RoomWidget;
class HomePage : public QToolBox//多栋楼
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = 0);

    ~HomePage();
    QSqlDatabase * db;

    void createBuildingState(QAbstractButton * btn,QString buildingname);


    QList<QAbstractButton *> btnlist;
protected:
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void resizeEvent(QResizeEvent * event);
    virtual bool eventFilter(QObject* object, QEvent* event);
    
signals:
    void openViewSignal(int);
    void alarmLightSignal();
public slots:
     //parentindex 与信号中的 buildingindex相同
     void highlightFloor(int index);
     void scrollToFloor(int parentindex,int curindex);
     void expandingBuilding(int index);
     void addBuilding(QString buildingname);
     void delBuilding(int index);
     void addFloor(int parentindex,int floornum,int index);
     void delFloor(int parentindex,int index);
     void addRoom(int parentindex,int index,QString roomname);
     void delRoom(int parentindex,int index,QString roomname);
     void onCurrentChanged(int index);


//     void allRadioButton();
//     void normalRadioButton();
//     void offlineRadioButton();
//     void firstalarmRadioButton();
//     void secondalarmRadioButton();
//     void alarmconditionRadioButton();
//     void changeSearchConditon();
//     void onRefreshTimer();

     QObject * mySender()
     {
         return sender();
     }

private:
    int buildingnum;

    //QList<RoomStateSearchDialog * > rssds;
    void connectToDatabase();
    void  loadBuildingInfo(QStringList & buildingmaptofloor);
    QTimer * refreshtimer;
//    void setAlarmRadioButtonChecked(QString objname);
//    void setOtherRadioButtonChecked(bool flag);
    void refreshBuildingStateStatistics(QAbstractButton * btn);
    int oldparentindex;
    int oldcurindex;
};

#endif // HOMEPAGE_H

#ifndef BUILDINGTOOLBOX_H
#define BUILDINGTOOLBOX_H
#include <QToolBox>
class FloorFrameWidget;
class RoomStateWidget;
class BuildingToolBox:public QToolBox{
    Q_OBJECT
public:
    explicit BuildingToolBox(QWidget *parent = 0);
    QList<FloorFrameWidget *> floors;
    void constructBuilding(QString buildingToFloor);
    void createFloorState(QAbstractButton * btn,int floorNum);
    QList<QAbstractButton *> btnlist;
    void floorNumIncrease();
    void floorNumDecrease();
    int getFloorNum();

signals:
public slots:
private:
    //各种房间状态的颜色
    RoomStateWidget * bedReside;
    RoomStateWidget * bedHoliday;
    RoomStateWidget * bedAvailable;
    RoomStateWidget * bedOrder;
    RoomStateWidget * bedNone;
    int floornum;
};
#endif


#ifndef BUILDINGSPLITER_H
#define BUILDINGSPLITER_H

#include <QSplitter>
#include <QScrollArea>
#include <QList>
class FloorFrameWidget;
class BuildingSpliter : public QSplitter//一栋楼
{
    Q_OBJECT
public:

    QList<FloorFrameWidget *> floors;
    explicit BuildingSpliter(QWidget *parent);
    void constructBuilding(QString buildingtofloor);
    void floorNumIncrease();
    void floorNumDecrease();

    QObject * mySender()
    {
        return sender();
    }



signals:
    void openViewSignal(int);
public slots:
private:

    int floornum;
};

#endif // BUILDINGSPLITER_H

#ifndef FLOORFRAMEWIDGET_H
#define FLOORFRAMEWIDGET_H

#include <QWidget>
#include <QModelIndex>
class QLabel;
class QCheckBox;
class QTreeWidget;
class QToolButton;
class QTreeWidget;
class QListWidget;
class RoomStateWidget;
class QTableWidget;
class FloorFrameWidget : public QFrame//楼层
{
    Q_OBJECT
public:
    QLabel * floorname_label;
    QListWidget * rooms;
//    QTableWidget *rooms;

//    int state;
    explicit FloorFrameWidget(int floornum , QWidget *parent = 0);
    void  createRooms(QString buildingname,int floornum);
//    void roomWidgetStateFilter(int filterstate);

//    void refreshRoomStateStatistics();
    void setDataBase(HomePage * ptr);
//    QString advanceCondition;
//    QList<int> args;


signals:


public slots:


private :
    //enum {all,normal,offline,firstalarm,secondalarm};

    RoomStateSearchDialog * rssd;
    QSqlDatabase * homedb;
};

#endif // FLOORFRAMEWIDGET_H


#ifndef ROOMSTATEWIDGET_H
#define ROOMSTATEWIDGET_H

#include <QWidget>
#include <QColor>
class RoomStateWidget : public QWidget//绘制状态
{
    Q_OBJECT
public:
    explicit RoomStateWidget(int state = 0,QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int state;
signals:


};

#endif // ROOMSTATEWIDGET_H

#ifndef BEDWIDGET_H
#define BEDWIDGET_H
#include<QWidget>
class BedWidget:public QWidget{
    Q_OBJECT
    public:
    explicit BedWidget(QString roomName,QString bedNo,QString elderName,QString gender, QWidget *parent = 0);
        QString roomName;
        QString bedNo;
        QString elderName;
        QString gender;

    protected:
        void paintEvent(QPaintEvent *);

    signals:

    public slots:
    private:
        enum {margin = 5,space = 5,roundwidth = 20,textlenth = 35, height = 100};
};

#endif

//#ifndef ROOMWIDGET_H
//#define ROOMWIDGET_H

//#include <QWidget>
//#include <QBitArray>

//class RoomWidget : public QWidget//房间
//{
//    Q_OBJECT
//public:
//    explicit RoomWidget(QString roomname,int state = 0, QWidget *parent = 0);
//    QString roomname;
//    QBitArray statebits;
//    int state;
//    //int abnormalsensorcount;
//    void setRoomState(int newstate);

//protected:
//    void paintEvent(QPaintEvent *);

//signals:

//public slots:
//private:
//    enum {margin = 5,space = 5,roundwidth = 20,textlenth = 35, height = 30};

//    enum {all,normal,offline,firstalarm,secondalarm};

//    /*enum {temperatureup,temperaturedown,humidityup,humiditydown,oxygenup,oxygendown,carbodioxideup, carbodioxidedown,
//          comindexup,comindexdown,mainvoltageup,mainvoltagedown,zerovoltageup,zerovoltagedown,waterlevel,smoke};*/

//};
//#endif // ROOMFRAME_H

#ifndef GENERALVIEWWIDGET_H
#define GENERALVIEWWIDGET_H

#include <QWidget>
//class PieWidget;
class GeneralViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GeneralViewWidget(HomePage * homepage,QWidget *parent = 0);
    void refreshBuildingStructrue();
    void refreshGeneralViewStatistics();
protected:
   // virtual void paintEvent(QPaintEvent * event);
   // virtual void resizeEvent(QResizeEvent * event);
signals:

public slots:
private:
    HomePage * homepageptr;

    //PieWidget * rootpiewidget;
    //QList<PieWidget *> piewidchilds;
    QWidget * procedurewid;
    int mywidth;
    int myheight;
   // float rootdiameter;
   //float childheight ;
   // enum {TOPMARGIN = 30,ROOTCHILDSPACE = 50,CHILDHINTHEIGHT = 130};
};

#endif // GENERALVIEWWIDGET_H

