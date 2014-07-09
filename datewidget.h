// ***************************************************************************
// *	������ο����й��й�ũ��������
// *	��Ȩ���� (C) 2005-2006 �����
// *  Mail:sungaoyong@gmail.com
// ***************************************************************************

//***************************************************************************
// * �й�ũ�������� (Chinese Tradional Calendar Library)
// *
// * ��Ȩ���� (C) 2002-2003 ����
// * ��Ȩ���� (C) 2003      donaldzju@zju.edu.cn
// * ����Դ������������Ӧ˵���Ĵ���ΰ�Ȩ�����������С�
// *
// * ��ϸ��Ȩ������ο�COPYRIGHT��GPL
// ***************************************************************************
#ifndef MyCTCALENDAR_H
#define MyCTCALENDAR_H

#pragma once
#include<math.h>
#include <QByteArray>
#include <QFile>
#include <QString>
#include <QObject>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif

    struct CTCalendar{
    int month;                  /*  ũ���£�������Ϊ0������Ϊ������-3��ʾ������  */
    int day;                    /*  ũ����                                  */
    QString cmonth;             /*  ũ����                                  */
    QString cday;               /*  ũ����                                  */
    QString ganzhi;             /*  ��֧                                    */
    QString sterm;              /*  ����                                    */
    QString caltype;            /*  �������ͣ�-1��ʾ������                    */
    QString holiday;            /*  ��������                                 */
    QString choliday;           /*  ũ������                                 */
    };

class MyCTCalendar: public QObject
{

public:


    MyCTCalendar(void);
    ~MyCTCalendar(void);
    int ctcl_solar_to_lunar(int y,int m,int d,struct CTCalendar* ctc);
        bool InitConnection(QString Path);

private:
    int ctcl_calendar_type(int y, int m, int d, int opt);/*  �ж�Gregorian(����)������Julian(����)��  */
    int ctcl_date_to_days(int y,int m,int d);/*  ����y��m��d����y�������߹�������  */
    int ctcl_days_to_date(int y,int x);/*  ��������y���ղ�����Ϊxʱ����Ӧ��������  */
    int days_from_era(int y);/*  ����y����������  */
    int ctcl_standard_days(int y,int m,int d);/*  ���ص�Ч��׼����  */
    double ctcl_julian_day(int y,int m,int d,int h,int min,int sec,int zone);/*  ����������  */
    int ctcl_day_of_week(int y,int m,int d);/*  ����y��m��d�յ�����ֵ��0Ϊ������  */
    double ctcl_solar_term(int y,int n,int t);/*  ����y���n��������С��Ϊ1�����ղ�����,tȡֵΪ0��1,�ֱ��ʾƽ���Ͷ���  */
    double ctcl_tail(double x);/*  ��x��С������  */
    double ctcl_rem(double x,double w);/*  ��������  */
    double ctcl_round(double x);
    int ctcl_gan(int x);/*  ���ؼ�����x��Ӧ�����������33Ϊ3��  */
    int ctcl_zhi(int x);/*  ���ؼ�����x��Ӧ�ĵ�֧������33Ϊ9��  */
    int ctcl_year_ganzhi(int y,int m,int d,int h);/*  ����y��m��d��hʱ�����֧����1-60��  */
    double ang(double x,double t,double c1,double t0,double t2,double t3);
    int ctcl_lunar_date(int y,int m,int d);
    int ctcl_leap_month(int y);/*  ����y������£����򷵻�0  */
    int ctcl_lunar_month(int y,int m,int d);/*  ����y��m��d�ն�Ӧ��ũ���·ݣ������ø�����ʾ  */
    QByteArray lunarstr;
        int maxyear;
        void logSqlError( const QString& Type, const QString& error);
        QString ctcl_common_query(QString type,QString querystr);
};

#endif
#ifndef DATEWIDGET_H
#define DATEWIDGET_H

#include <QWidget>

class QLabel;
class QProcess;
class DateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DateWidget(QWidget *parent = 0);
protected:
    void enterEvent(QEvent * event);
    
signals:
    void lowerApp();
    void showSystemClock();
public slots:
    void getDate();
protected:
    void mouseDoubleClickEvent(QMouseEvent * event);
private:
    MyCTCalendar calendar;
    CTCalendar cal;

    QLabel * solar_label;
    QLabel * lunar_label;
    //QProcess * dtprocess;


};

#endif // DATEWIDGET_H

