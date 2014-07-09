#ifndef STRUCT_H
#define STRUCT_H

#include <QDataStream>
#include <QDebug>
#include <QColor>
#include <QSqlDatabase>
#include "refreshanalogattriobject.h"
#include "sendmessagethread.h"
struct Analog       //模拟量的数据结构
{
    float O2;
    float CO2;
    float index;
    float temprature;
    float moisture;
    float voltage1;//市电电压
    float voltage2;//零电压差
    int pm25;
    qint64 stamp;
};



inline QDataStream& operator<<(QDataStream& out, const Analog & ana)
{
    out.setFloatingPointPrecision(QDataStream::SinglePrecision);
    out << ana.O2;
    out << ana.CO2;
    out << ana.index;
    out << ana.temprature;
    out << ana.moisture;
    out << ana.voltage1;
    out << ana.voltage2;
    out << ana.stamp;
    out << ana.pm25;
    return out;
}

//the total bytes num of ana is 36,when received,all analog data is 174*36
inline QDataStream& operator>>(QDataStream& in, Analog & ana)
{
    in.setFloatingPointPrecision(QDataStream::SinglePrecision);
    in >> ana.O2;
    in >> ana.CO2;
    in >> ana.index;
    in >> ana.temprature;
    in >> ana.moisture;
    in >> ana.voltage1;
    in >> ana.voltage2;
    in >> ana.stamp;
    in >> ana.pm25;
    //qDebug()<<ana.temprature<<ana.moisture<<ana.O2<<ana.CO2<<ana.index<<ana.voltage1<<ana.voltage2;
    return in;
}


//开关量的数据结构
struct Switch
{
    bool smokePrevious;     //previous value of smoke
    bool smokeCurrent;
    bool waterPrevious;      //上一次的值，以便与当期值对比
    bool waterCurrent;
    qint64 stamp;

};

inline QDataStream& operator<<(QDataStream& out, const Switch & swi)
{
    out << swi.smokePrevious;
    out << swi.smokeCurrent;
    out << swi.waterPrevious;
    out << swi.waterCurrent;
    out << swi.stamp;
    return out;
}


//the total bytes num of swi is 12,when received,all analog data is 174*12
inline QDataStream& operator>>(QDataStream& in, Switch & swi)
{
    in >> swi.smokePrevious;
    in >> swi.smokeCurrent;
    in >> swi.waterPrevious;
    in >> swi.waterCurrent;
    in >> swi.stamp;
    return in;
}


//床垫的数据结构
struct Mat
{
    quint8 bitmap;
    quint8 previous;
    quint8 current;
    qint64 stamp;
};


inline QDataStream& operator<<(QDataStream& out, const Mat & mat)
{
    out << mat.previous;
    out << mat.current;
    out << mat.stamp;
    return out;
}

//the total bytes num of mat is 11,when received,all analog data is 174*11
inline QDataStream& operator>>(QDataStream& in, Mat & mat)
{
    in >> mat.previous;
    in >> mat.current;
    in >> mat.stamp;
    return in;
}


//PM2.5的结构体
struct PM25
{
    int value;
    int alarmtype;
    qint64 stamp;
};



inline QDataStream& operator<<(QDataStream& out, const PM25 & pm)
{
    out << pm.value;
    out << pm.stamp;
    return out;
}


//the total bytes num of pm is 12,when received,because of the '\n',all analog data is 174*13
inline QDataStream& operator>>(QDataStream& in, PM25 & pm)
{
    in >> pm.value;
    in >> pm.stamp;
    return in;
}

//by nan
struct AnalogSensorRange//模拟量范围
{
    float uprange;
    float downrange;
    float alarmdownrange;
    float alarmuprangge;
    QString arg_unit;
};


struct RoomAnalogSensorRange//各个房间模拟量范围
{
    float O2_up;
    float CO2_up;
    float index_up;
    float temprature_up;
    float moisture_up;
    float voltage1_up;//市电电压
    float voltage2_up;//零电压差

    float O2_down;
    float CO2_down;
    float index_down;
    float temprature_down;
    float moisture_down;
    float voltage1_down;//市电电压
    float voltage2_down;//零电压差

    float O2_alarmup;
    float O2_alarmdown;
    QString O2_unit;

    float CO2_alarmup;
    float CO2_alarmdown;
    QString CO2_unit;

    float index_alarmup;
    float index_alarmdown;
    QString index_unit;

    float temprature_alarmup;
    float temprature_alarmdown;
    QString temprature_unit;

    float moisture_alarmup;
    float moisture_alarmdown;
    QString moisture_unit;

    float voltage1_alarmup;//市电电压
    float voltage1_alarmdown;//市电电压
    QString voltage1_unit;

    float voltage2_alarmup;//零电压差
    float voltage2_alarmdown;//零电压差
    QString voltage2_unit;
};


struct AlarmRange//报警范围
{
    float O2_alarmup;
    float O2_alarmdown;
    QString O2_unit;

    float CO2_alarmup;
    float CO2_alarmdown;
    QString CO2_unit;

    float index_alarmup;
    float index_alarmdown;
    QString index_unit;

    float temprature_alarmup;
    float temprature_alarmdown;
    QString temprature_unit;

    float moisture_alarmup;
    float moisture_alarmdown;
    QString moisture_unit;

    float voltage1_alarmup;//市电电压
    float voltage1_alarmdown;//市电电压
    QString voltage1_unit;

    float voltage2_alarmup;//零电压差
    float voltage2_alarmdown;//零电压差
    QString voltage2_unit;
};

struct SingleArgAlarmAndRange
{
    QString arg_unit;
    float range_up;
    float range_down;
    float alarm_up;
    float alarm_down;
};


/*struct GloabalRoomState
{
    bool iscompleteconfigure;
    bool isoffline;
};*/

const int MAXROOMNUM = 200;
#define OFFLINEDATA -1000.0
const int abnormaldatashift = 1;

extern bool dbisconnected;
extern bool serverisrunning;
extern QString globalUserName;
//报警类型
enum {temperatureup,temperaturedown,humidityup,humiditydown,oxygenup,oxygendown,carbodioxideup, carbodioxidedown,
      comindexup,comindexdown,pm25up,pm25down,mainvoltageup,mainvoltagedown,zerovoltageup,zerovoltagedown,waterlevel,smoke,mattress};

const int analogrefreshtime = 12;
//控件的颜色显示

const QColor datacolor[3]={Qt::magenta,Qt::red,Qt::green};
const QString datastrcolor[3] ={"magenta","red","lightgreen"};
/*const QColor datacolor[3]={Qt::magenta,Qt::red,Qt::darkGreen};
const QString datastrcolor[3] ={"magenta","red","darkgreen"};*/
enum {alarmdowncolor,alarmupcolor,normalcolor};
//控件的颜色显示
extern QString operatorId;
extern void insertLog(QString operation);
enum {MONITORING,LOCKING,LOGOUTING};
enum {LOGGIN,LOCK,LOGOUT};
//enum {room_normal,room_firstalarm,room_secondalarm,room_offline};


//extern int appstate;
extern RefreshAnalogAttriObject * raao;
struct SortItem
{
    int row;
    int frequecy;
};

extern QString serverIP;
extern QString globalDBName;
extern QSqlDatabase globaldb;
extern int curmaxroomid;
enum {ADD,DEL,MODIFY};
extern bool connectToGloabalDatabase();

extern QMap<QString,int> roomnameToIds;



extern QStringList floornames;
extern int totalroomcount;

extern Mat mat[MAXROOMNUM];
//extern GloabalRoomState gloroomstate[MAXROOMNUM];//房间全局状态
//pm2.5等级：优，良，轻度，中度，重度，严重
enum{pm25_excellent,pm25_fine,pm25_light,pm25_moderate,pm25_serious,pm25_grave};
enum{pmgrade_0,pmgrade_1,pmgrade_2,pmgrade_3,pmgrade_4,pmgrade_5};


extern SendMessageThread * smt;
extern bool hassursys;
extern QString sursysip;



#endif // STRUCT_H
