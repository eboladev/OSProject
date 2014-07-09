#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QSqlDatabase>
class RoomTreeWidget;
class ControlListWidget;
class ControlTableListWidget;
class ViewTableListWidget;
class QListWidget;
class QVBoxLayout;
class QHBoxLayout;
class ViewListWidget;
class QPushButton;
class QTabWidget;
class SidePushButton;
class QDockWidget;
class QMenu;
class QAction;
class QWidgetAction;
class TabWidget;
class QTimer;
class ToolButton;
class SubMenu;
class DeviceConfig;
class SensorConfig;
class TerminalConfig;
class ElderManager;
class UserManager;
class AlarmDockWidget;
class QLabel;
class DateWidget;
class TimeWidget;
class HomePage;
class StatusBar;
class SetSystemTimeDialog;
class ElderBaseInfo;
class AccidentRecord;
class VisitRecord;
class ElderBaseInfo;
class HealthAssess;
class EmployeeBaseinfo;
class EmployeeVacation;
class CheckIn;
class Storage;
class CheckOut;
class ResideRegister;
class NurseRecord;
class AdviceRecord;
class SpecialService;
class ElderVacation;
class ElderBirthday;
class NurseChange;
class AccountPay;
class MonthlySettle;
class RecedeSettle;
class AccountDetail;
class Previlege;
class OperationLog;
class MonthlyResideStatistics;
class DragDropWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
     TabWidget * central_tablewidget;
     HomePage * homepage;
     QToolBar * toolbar;
     VisitRecord *visitRecord;
     ElderBaseInfo *elderBaseInfoPage;
     HealthAssess *healthAssessPage;
     EmployeeBaseinfo *employeeBaseInfoPage;
     EmployeeVacation *employeeVacationPage;
     CheckIn *checkInPage;
     Storage *storagePage;
     CheckOut *checkOutPage;
     ResideRegister *resideRegisterPage;
     NurseRecord *nurseRecordPage;
     AdviceRecord *adviceRecordPage;
     SpecialService *specialServicePage;
     AccidentRecord *accidentRecordPage;
     ElderVacation *elderVacationPage;
     ElderBirthday  *elderBirthdayPage;
     NurseChange *nurseChangePage;
     AccountPay *accountPayPage;
     MonthlySettle *monthlySettlePage;
     RecedeSettle *recedeSettlePage;
     AccountDetail *accountDetailPage;
     Previlege *previlegePage;
     OperationLog *operationLogPage;
     MonthlyResideStatistics *monthlyResideStatisticsPage;


signals:
     void closeapp();
     void refreshanalogrange();//采集器刷新
     //void refreshanalogalarmrange();//报警上下限刷新
     void refreshTerminalInfo();//刷新终端机信息
     void lowerApp();
    
public slots:
private slots:
//     void onAccidentRecordPage();
    //visit manage
     void onVisitRecord();
     //reside manage
     void onElderBaseInfoPage();
     void onHealthAssessPage();
     void onResideRegisterPage();
     //elder manage
     void onNurseRecordPage();
     void onAdviceRecordPage();
     void onSpecialServicePage();
     void onAccidentRecordPage();
     void onElderVacationPage();
     void onElderBirthdayPage();
     void onNurseChangePage();
     //cost manage
     void onAccountPayPage();
     void onMonthlySettlePage();
     void onRecedeSettlePage();
     void onAccountDetailPage();
     //report manage
     void onMonthlyResideStatisticsPage();
     //employee manage
     void onEmployeeBaseInfoPage();
     void onEmployeeVacationPage();
     //storage manage
     void onCheckInPage();
     void onStoragePage();
     void onCheckOutPage();
     //resource manage
     void onDictionaryDialog();
     void onBaseCostDialog();
     void onStageCostDialog();
     //system manage
     void onRoleDialog();
     void onOperatorDialog();
     void onPrevilegePage();
     void onOperationLogPage();
     void onPasswordDialog();

    //退出系统
//    void onLockLeaveSystem();
//    void onLogoutLeaveSystem();
//    void onExitLeaveSystem();
//    void onRestartSystem();

    //显示系统设置时钟
    void showSystemClock();
    //隐藏拖拽窗口
    void hideDragDropWidget();
private:
    bool isTabExist(QString);

    //数据库
    // QSqlDatabase db;
    //菜单
    QMenuBar * menubar;    
//    QMenu * visit_menu;
    QMenu *reside_menu;
    QMenu * elder_menu;
    QMenu * employee_menu;
    QMenu * warehouse_menu;
    QMenu * charge_menu;
    QMenu * report_menu;
    QMenu * resource_menu;
    QMenu *system_menu;
    QMenu *help_menu;


    //toolbar
    //QToolBar * toolbar;
    DateWidget * datewidget;
    TimeWidget * tw;
    //action
    //reside manage
    QWidgetAction * elder_info_widgetaction;
    QWidgetAction * health_assess__widgetaction;
    QWidgetAction * reside_widgetaction;
    //elder manage
    QWidgetAction * nurse_change_widgetaction;
    QWidgetAction *elder_vacation_widgetaction;
    QWidgetAction *special_service_widgetaction;
    QWidgetAction *advice_record_widgetaction;
    QWidgetAction *nurse_record_widgetaction;
    QWidgetAction *accident_record_widgetaction;
    QWidgetAction *elder_birthday_widgetaction;
    //employee manage
    QWidgetAction * employee_info_widgetaction;
    QWidgetAction * employee_vacation_widgetaction;
    //warehouse manage
    QWidgetAction *storage_check_widgetaction;
    QWidgetAction * check_in_widgetaction;
    QWidgetAction * check_out_widgetaction;
    //report manage
    QWidgetAction *monthly_reside_widgetaction;
    //cost manage
    QWidgetAction *account_pay_widgetaction;
    QWidgetAction *monthly_settle_widgetaction;
//    QWidgetAction *settle_check_widgetaction;
    QWidgetAction *recede_settle_widgetaction;
    QWidgetAction *account_detail_widgetaction;
    //resource manage
    QWidgetAction *base_cost_widgetaction;
    QWidgetAction *stage_cost_widgetaction;
    QWidgetAction * dictionary_widgetaction;
    //system manage
    QWidgetAction * role_widgetaction;
    QWidgetAction * operator_widgetaction;
    QWidgetAction *previlege_widgetaction;
    QWidgetAction *operation_log_widgetaction;
    QWidgetAction *password_widgetaction;
    //help
    QWidgetAction *instruction_widgetaction;
    QWidgetAction *about_widgetaction;
    //离开系统
//    QWidgetAction * lock_widgetaction;
//    QWidgetAction * logout_widgetaction;
//    QWidgetAction * exit_widgetaction;
//    QWidgetAction * restart_widgetaction;

    QSize buttoniconsize;
    //侧边停靠窗口
    QDockWidget * rvc_dockwidget;
    QDockWidget * message_dockwidget;
    QDockWidget * alarmsearch_dockwidget;
    DragDropWidget* dragdrop_dockwidget;
    QWidget * room_widget;

    //侧边中心布局
    QVBoxLayout * findroom_verticalLayout;
    QVBoxLayout * controler_verticalLayout;
    QVBoxLayout * view_verticalLayout;

   //左侧停靠窗口内部窗口
    QTabWidget * dock_tablewidget;
    RoomTreeWidget * room_treewidget;

    //中心部件部分
    QWidget * central_widget;

    QHBoxLayout *centralwidget_hboxlayout;
    //状态栏
    StatusBar * statusbar;

    //报警记录
    //系统时钟限制
    SetSystemTimeDialog * sstd;
    //bool connectToDatabase();

    void createMainWindow();
    void createDockWidget();
    void createDragDropDockWidget();
    void createRoom();
    void createAlarmWidget();

    void createMessageDock();
    void createAlarmSearchDock();
    void createCentralWidget();
    void createMenu();    
    void createToolBar();
    void createStatusBar();


    //构造房间名到逻辑序号的映射
    void initRoomData();
    void createRoomNameToId();
    void createRefreshAnalogObject();

    //与环境监测系统
    void loadSurSysInfo();

protected:
    void closeEvent(QCloseEvent * event);
};
#endif

#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>

class ToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ToolButton(QWidget *parent = 0);
    //void setChildMenu( SubMenu * childmenu);
protected:
     // virtual void    mouseReleaseEvent( QMouseEvent * event );
    /*
     virtual void mouseMoveEvent(QMouseEvent *event);*/
    virtual void enterEvent(QEvent * event);
    virtual void leaveEvent(QEvent * event);
    virtual void mousePressEvent(QMouseEvent *event);
signals:

public slots:
private :
    SubMenu * tempmenu;

};

#endif // TOOLBUTTON_H


#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QLCDNumber>

class TimeWidget : public QLCDNumber
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = 0);
protected:
    void mouseDoubleClickEvent(QMouseEvent * event);
    void enterEvent(QEvent * event);
signals:
    void showSystemClock();

public slots:
    void showtime();//显示时间

};

#endif // TIMEWIDGET_H

#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    explicit StatusBar(QWidget *parent = 0);

signals:

public slots:

private:

};
#endif // STATUSBAR_H
