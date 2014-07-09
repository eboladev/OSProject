#ifndef ROOMTREEWIDGET_H
#define ROOMTREEWIDGET_H

#include <QtGui/QTreeWidget>
#include <QSqlDatabase>
#include <QDialog>
class QMenu;
class QAction;
class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QDialog;
class DelRoomProcessDialog;
//class QList;

class RoomTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    //查找功能
    explicit RoomTreeWidget(QWidget *parent = 0);
    
signals:
    void lookuoViewSignal(int index);
    void showHomepage();
    void lookuoViewSignal(QString buildingname,QString floorname,QString roomname);
    void expandbuilding(int index);
    void scrolltofloor(int parentindex,int curindex);
    void addBuilding(QString buildingname);
    void delBuilding(int buildingindex);
    void addFloor(int buildingindex,int floornum,int curindex);
    void delFloor(int buildingindex,int curindex);
    void addRoom(int buildingindex,int curindex,QString rooname);
    void delRoom(int buildingindex,int curindex,QString rooname);
    
    //删除申请
    void delRequestSignal(int index);
    //删除房间申请
    void deleteRoomRequestSignal(QString roomviewname);

    //verierwidget里面床位以及老人信息的修改
    void refreshVernierTableWidget(int id);

public slots:
    void showRightMenu(const QPoint & pos);

    void addBuilding();
    void delBuilding();

    void addFloor();
    void deleteFloor();
    void lookupFloorOlderInfo();
    void addRoom();
     void lookupRoomOlderInfo();
    void editRoom();

    void deleteRoomRequest();
   void  deleteRoomCanbe(bool flag);
    void deleteRoom(bool flag);
    void setRoomMonitor(bool flag);
    void addView();
    void delViewRequest();
    void delView(bool flag);
    void editView();
    void lookupView();
    void lookupOlderInfo();
    void addBed();
    void addOlder();
    void editOlderInfo();
    void delOlder();
    void delBed();
    void defaultDoubleClicked(QModelIndex modelindex);
    void addViewTo(QString tarbuildingname,QString tarfloorname,QString tarroomname,QString viewname);
    void locateAndOpenRoom(QString buildingname,QString floorname,QString roomname);


    //和homepage联动
    void onItemActivated(QTreeWidgetItem * item,int column);
    void onCurrentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous);
    void onItemChanged(QTreeWidgetItem * item, int column);
    void onItemClicked(QTreeWidgetItem * item, int column);
    void onItemCollapsed(QTreeWidgetItem * item);
    void onItemDoubleClicked(QTreeWidgetItem * item, int column);
    void onItemEntered(QTreeWidgetItem * item, int column);
    void onItemExpanded(QTreeWidgetItem * item);
    void onItemPressed(QTreeWidgetItem * item, int column);

    //
    //void delRoom(bool flag);


private:
    //QMenu * roomright_menu;
    //楼菜单
    QAction * addbuilding_action;
    QAction * delbuilding_action;
    //楼层菜单
    QAction * addfloor_action;
    QAction * delfloor_action; 
    QAction * lookupfloorolderinfo_action;

    QAction * addroom_action;
    QAction * editroom_action;

    //房间菜单
    QAction * delroom_action;
    QAction * addview_action;
    QAction * delview_action;
    QAction * editview_action;
    QAction * lookuproomolderinfo_action;
    QAction * setroommonitored_action;

    //视图处理菜单
    QAction * lookupview_action;
    //老人处理菜单
    QAction * lookupolderinfo_action;
    QAction * addolder_action;
    QAction * editolderinfo_action;
    QAction * delolder_action;
    //床位处理菜单
    QAction * addbed_action;
    QAction * delbed_action;


    QList<QTreeWidgetItem *> floorlist;
    QList<QTreeWidgetItem *> findedOlders;
    const int floorsize;
    const int roomsize;

    void createRightMenuActions();
    void createFloorRoom();
   // void resetRoom(int roomid);
    //void showOlderInfo(QString name,QString roomno,QString bedno);
    //void connectToDatabase();
    //QSqlDatabase db;
   // QStringList floornames;

    //构造房间名到逻辑序号的映射
    //void createRoomNameToId();

    //显示删除房间进度
    DelRoomProcessDialog * drpd;


};

#endif // ROOMTREEWIDGET_H


#ifndef NameSelectDialog_H
#define NameSelectDialog_H

#include <QDialog>
class QTableWidget;
class QAction;

class NameSelectDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NameSelectDialog(QWidget *parent = 0);
     void loadNameBriefInfo(QString oldername);
     bool loadFloorOlderBriefInfo(QString buildingname, QString floorname);
     //void connectToDatabase();
signals:
     void locateAndOpenRoom(QString buildname,QString floorname,QString roomname);
public slots:
    void onShowOlderInfo(int row,int col);
    void onShowOlderInfo();
    void showRightMenu(QPoint);
private:

    QTableWidget * tablewidget;
    QAction * detailinfo_action;
    //QSqlDatabase mysqldb;


   // QSqlDatabase  db1;
};

#endif // NameSelectDialog_H

#ifndef OLDERINFOWIDGET_H
#define OLDERINFOWIDGET_H

#include <QWidget>

namespace Ui {
class OlderInfoWidget;
}

class OlderInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OlderInfoWidget(QWidget *parent = 0);
    void showOlderInfo(QStringList strlist, QByteArray data);
    ~OlderInfoWidget();

private:
    Ui::OlderInfoWidget *ui;
};

#endif // OLDERINFOWIDGET_H


#ifndef ADDBUILDINGDIALOG_H
#define ADDBUILDINGDIALOG_H

#include <QDialog>

class AddBuildingDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddBuildingDialog(QWidget *parent = 0);

signals:
     void addBuilding(QString buildingname);

public slots:
    void onConfirmPushButton();
    void onCancelPushButton();
    void onBuildingNameChanged(QString tempbuildingname);
private:
    QLabel * addolder_label;//忘记修改变量名称
    QLineEdit * addolder_lineedit;
    QPushButton * confirm_pushbutton;
    QPushButton * cancel_pushbutton;
    QString oldbuildingname;
    void saveBuildingMapToFloor(QString buildingname);

};

#endif // ADDBUILDINGDIALOG_H


#ifndef ADDFLOORDIALOG_H
#define ADDFLOORDIALOG_H

#include <QDialog>
class  QListWidget;
class AddFloorDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddFloorDialog(QTreeWidgetItem * item,QWidget *parent = 0);

signals:
     void addFloor(int buildingindex,int floornum,int curindex);

public slots:
    void onConfirmPushButton();
    void onCancelPushButton();
private:
    QPushButton * confirm_pushbutton;
    QPushButton * cancel_pushbutton;
    QListWidget * floorlistwidget;
    QTreeWidgetItem * parentitem;
    //QStringList floornames;

};

#endif // ADDFLOORDIALOG_H



#ifndef ADDROOMDIALOG_H
#define ADDROOMDIALOG_H

#include <QDialog>
#include<QComboBox>
class QCheckBox;
class AddRoomDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddRoomDialog(QTreeWidgetItem *item, QWidget *parent = 0);

signals:
    void addRoom(int buildingindex,int curindex,QString rooname);
public slots:
    void onConfirmPushButton();
    void onCancelPushButton();
    void onRoomNameChanged(QString temproomname);
private:
    QLabel * addroom_label;
    QLineEdit * addroom_lineedit;
    QCheckBox * setmonitor_checkbox;
    QLabel *label_direction;
    QComboBox *combox_direction;
    QPushButton * confirm_pushbutton;
    QPushButton * cancel_pushbutton;
    QTreeWidgetItem * curitem;
    QString oldroomname;
};

#endif // ADDROOMDIALOG_H


#ifndef DELROOMPROCESSDIALOG_H
#define DELROOMPROCESSDIALOG_H

#include <QDialog>
class QProgressBar;

class DelRoomProcessDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DelRoomProcessDialog(QWidget *parent = 0);
    void startCount();
    int getCount();
signals:

public slots:
   void onTimer();
private:
    QTimer * timer;
    QProgressBar * probar;
    int count;



};

#endif // DELROOMPROCESSDIALOG_H




#ifndef ADDBEDDIALOG_H
#define ADDBEDDIALOG_H

#include <QDialog>
class  QListWidget;
class AddBedDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddBedDialog(QTreeWidgetItem * item,QWidget *parent = 0);

signals:

public slots:
    void onConfirmPushButton();
    void onCancelPushButton();
private:
    QPushButton * confirm_pushbutton;
    QPushButton * cancel_pushbutton;
    QListWidget * bedlistwidget;
    QTreeWidgetItem * parentitem;
    QStringList bednames;

};

#endif // ADDFLOORDIALOG_H


#ifndef ADDOLDERDIALOG_H
#define ADDOLDERDIALOG_H

#include <QDialog>

class AddOlderDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddOlderDialog(QTreeWidgetItem * curitem,QWidget *parent = 0);

signals:

public slots:
    void onConfirmPushButton();
    void onCancelPushButton();
private:
    QLabel * addolder_label;
    QLineEdit * addolder_lineedit;
    QPushButton * confirm_pushbutton;
    QPushButton * cancel_pushbutton;
    QString buildingname;
    int  floorno;
    QString roomname;
    int bedno;
    QTreeWidgetItem * curitem;

};

#endif // ADDOLDERDIALOG_H





#ifndef DELOLDERDIALOG_H
#define DELOLDERDIALOG_H

#include <QDialog>
class QCheckBox;
class DelOlderDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DelOlderDialog(QTreeWidgetItem * curitem,QWidget *parent = 0);
signals:

public slots:
    void onConfirmPushButton();
    void onCancelPushButton();
private:

    QLabel * warning_lable;
    QPushButton * confirm_pushbutton;
    QPushButton * cancel_pushbutton;
    QCheckBox * delabs_checkbox;
    QString buildingname;
    int  floorno;
    QString roomname;
    int bedno;
    QTreeWidgetItem * curitem;

};

#endif // DELOLDERDIALOG_H
