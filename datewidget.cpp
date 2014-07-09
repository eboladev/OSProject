//����
#include "datewidget.h"
#include "setsystemtimedialog.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QProcess>
#include <QDir>
#include <QTimer>

DateWidget::DateWidget(QWidget *parent) :
    QWidget(parent)
{
    QFont font;
    const int width = 150;
    font.setPixelSize(16);
    font.setBold(true);
    solar_label = new QLabel(this);
    solar_label->setFont(font);
    solar_label->setAlignment(Qt::AlignCenter);
    solar_label->setFixedWidth(width);
    //solar_label->setFixedHeight(50);
    lunar_label = new QLabel(this);
    lunar_label->setFont(font);
    lunar_label->setAlignment(Qt::AlignCenter);
    lunar_label->setFixedWidth(width);
    //lunar_label->setFixedHeight(50);
    QVBoxLayout  * vbl= new QVBoxLayout;
    vbl->setSpacing(0);
    vbl->setMargin(0);
    vbl->addWidget(solar_label);
    vbl->addWidget(lunar_label);
    this->setLayout(vbl);
    calendar.InitConnection(QDir::currentPath());
    QTimer *t = new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(getDate()));
    t->start(1000);
    this->setFixedHeight(50);
    this->setFixedWidth(width);
    this->setToolTip("˫������ϵͳʱ��");
}
void DateWidget::enterEvent(QEvent * event)
{
    this->setCursor(Qt::PointingHandCursor);
    QWidget::enterEvent(event);
}

void DateWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
    QWidget::mouseDoubleClickEvent(event);

   /* if(dtprocess->state() == QProcess::NotRunning)
        dtprocess->start("C:\\WINDOWS\\system32\\rundll32.exe",QStringList()<<"C:\\WINDOWS\\system32\\shell32.dll,Control_RunDLL"<<"C:\\WINDOWS\\system32\\timedate.cpl,,6");*/
  //  QProcess::startDetached("C:\\WINDOWS\\system32\\rundll32.exe",QStringList()<<"C:\\WINDOWS\\system32\\shell32.dll,Control_RunDLL"<<"C:\\WINDOWS\\system32\\timedate.cpl,,6");

    //SetSystemTimeDialog sstd(this);
    //sstd.show();
    emit showSystemClock();

}

void DateWidget::getDate()
{
    QDate today = QDate::currentDate();
    int curyear = today.year();
    int curmonth = today.month();
    int curday = today.day();
    QString solarstr = QString::number(curyear)+tr("��")+QString::number(curmonth)+tr("��")+QString::number(curday)+tr("��");
    solar_label->setText(solarstr);
   // calendar.ctcl_solar_to_lunar(2012,6,1,&cal);
    calendar.ctcl_solar_to_lunar(curyear,curmonth,curday,&cal);
    QString holiday;
    if(!cal.choliday.isEmpty())
    {
        holiday = cal.choliday;
    }else if(!cal.sterm.isEmpty())
    {
        holiday = cal.sterm;
    }else
    {
        holiday = cal.holiday;
    }
    //qDebug()<<holiday;
   // qDebug()<<cal.ganzhi<<cal.cmonth<<cal.cday;      //������
    QString lunarstr =cal.ganzhi +tr("��")+cal.cmonth+cal.cday;
    lunar_label->setText(lunarstr);

}





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
#include<string.h>
#include <QDate>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTextStream>
#include <QtDebug>
const int beginning_year=-849;  //��¼�ӹ�Ԫǰ850�꿪ʼ
const int baseIndex = 0;

//
//ũ��������"lunar.db"��sqlite3���ݿ��У������������ֲ��������vc2003�лᱨ�ֶι����Ĵ���
//

MyCTCalendar::MyCTCalendar(void)
{
}

MyCTCalendar::~MyCTCalendar(void)
{

}

// /***************************************************************************
// *������int ctcl_calendar_type(int y,int m,int d,int opt);
// *���ܣ��ж�Gregorian(����)������Julian(����)��
// *����������y��m��(1,2,..,12,��ͬ)d��,opt=1,2,3�ֱ��ʾ��׼����,Gregorge����Julian��
// *����ֵ��1(������)��0(������)��-1(������)
// ***************************************************************************/

int MyCTCalendar::ctcl_calendar_type(int y, int m, int d, int opt)
{
  int days_of_month[13]={0,31,28,31,30,31,30,31,30,30,31,30,31};
  if(opt==1){
    if(y>1582 || (y==1582 && m>10) || (y==1582 && m==10 && d>14) ){
      if( (y%400==0) || (y%4==0 && y%100!=0) )days_of_month[2]++;
      if(m>0 && m<=12 && d>0 && d<=days_of_month[m])
    return(1);  //Gregorian
      else
    return(-1);
    }else if(y==1582 && m==10 && d>=5 && d<=14){
      return(-1);  /*  ��ʮ������ʷ�ϲ�����  */
    }else{
      if(y%4==0)days_of_month[2]++;
      if(m>0 && m<=12 && d>0 && d<=days_of_month[m])
    return(0);  //Julian
      else
    return(-1);
    }
  }

  if(opt==2)
    return(1);  //Gregorian
  return(0);  //Julian
}
// /**************************************************************************
// *������int ctcl_date_to_days(int y,int m,int d);
// *���ܣ�����y��m��d����y�������߹�������
// **************************************************************************/

int MyCTCalendar::ctcl_date_to_days(int y,int m,int d)
{
  int days=0,i;
  int type=ctcl_calendar_type(y,m,d,1);
  int dm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//Days of each month
  if(type!=0){
    if( (y%100!=0 && y%4==0) || (y%400==0) )
      dm[2]+=1;
  }else{
    if(y%4==0)
      dm[2]+=1;
  }
  for(i=0;i<=m-1;i++){
    days+=dm[i];
  }
  days+=d;
  if(y==1582){
    if(type==1)
      days-=10;
    if(type==-1)
      days=-1;  /*  ��Ч  */
  }
  return days;
}

// /***************************************************************************
// *���� int ctcl_days_to_date(int y,int x);
// *���ܣ���������y���ղ�����Ϊxʱ����Ӧ��������
// *     ����y=2000��x=274ʱ������1001(��ʾ10��1�գ�������100*m+d)��
// **************************************************************************/

int MyCTCalendar::ctcl_days_to_date(int y,int x)
{
  int m=1;
  int i;
  for(i=1;i<=12;i++){
    int d=ctcl_date_to_days(y,i+1,1)-ctcl_date_to_days(y,i,1);
    if(x<=d || i==12){
      m=i;
      break;
    }else{
       x-=d;
    }
  }
  return 100*m+x;
}

// /***************************************************************************
// *������int day_from_era(int y);
// *���ܣ�����y������������y��1��1�վ���Ӧ���ֵ�1��1��1�յ�������
// ***************************************************************************/

int MyCTCalendar::days_from_era(int y)
{
  int days=(y-1)*365 + (y-1)/4;  /*  Julian���������  */
  if(y>1582)
    days+= -((y-1)/100) + (y-1)/400;  /*  Gregorian���������  */
  return days;
}

// /***************************************************************************
// *������int ctcl_standard_days(int y,int m,int d);
// *���ܣ����ص�Ч��׼����
// *     ��y��m��d����Ӧ���ֵ�1��1��1�յĵ�Ч(����Gregorian����Julian��
// *       ��ͳһ��)������
// ***************************************************************************/

int MyCTCalendar::ctcl_standard_days(int y,int m,int d)
{
  int days=(y-1)*365 + (y-1)/4 + ctcl_date_to_days(y,m,d) - 2;  /*  Julian�ĵ�Ч��׼����  */
  if(y>1582)
    days+= -((y-1)/100) + ((y-1)/400) + 2;  /*  Gregorian�ĵ�Ч��׼����  */
  return days;
}

// /***************************************************************************
// *������double ctcl_julian_day(int y,int m,int d,int h,int min,int sec,int zone);
// *���ܣ����������գ�zoneʱ��y��m��d��hʱmin��sec�����������Ԫǰ4713��
// *      1��1�ո�������ʱ������12ʱ��������
// ***************************************************************************/

double MyCTCalendar::ctcl_julian_day(int y,int m,int d,int h,int min,int sec,int zone)
{
  int type=ctcl_calendar_type(y,m,d,1);
  double jt=(h+(min+sec/60.0)/60.0)/24.0-0.5-zone/24.0;
  double jd=(type!=0) ? (ctcl_standard_days(y,m,d)+1721425+jt) :
    (ctcl_standard_days(y,m,d)+1721425+jt);/*  ������  */
  return jd;
}

// /***************************************************************************
// *������int ctcl_day_of_week(int y,int m,int d);
// *���ܣ�����y��m��d�յ�����ֵ��0Ϊ������
// ***************************************************************************/
int MyCTCalendar::ctcl_day_of_week(int y,int m,int d)
{
  return ctcl_standard_days(y,m,d)%7;
}



// /***************************************************************************
// *������double ctcl_solar_term(int y,int n,int t);
// *���ܣ�����y���n��������С��Ϊ1�����ղ�����,tȡֵΪ0��1,�ֱ��ʾƽ���Ͷ���
// ***************************************************************************/

double MyCTCalendar::ctcl_solar_term(int y,int n,int t)
{
  double jd = y * (365.2423112 - 6.4e-14*(y-100)*(y-100) - 3.047e-8*(y-100))
    + 15.218427 * n + 1721050.71301;/*  ������  */
  double zeta = 3.0e-4 * y - 0.372781384 - 0.2617913325 * n;/*  �Ƕ�  */
  double yd = ( 1.945 * sin(zeta) - 0.01206 * sin(2*zeta) )
    * ( 1.048994 - 2.583e-5 *y );/*  ���ʵ����  */
  double sd =-18e-4*sin(2.313908653*y-0.439822951-3.0443*n);/*  ˷��ʵ����  */
  return (t==1)?(jd+yd+sd-ctcl_standard_days(y,1,0)-1721425)
    :(jd-ctcl_standard_days(y,1,0)-1721425);
}

// /****************************************************************************
// *������double ctcl_tail(double x);
// *���ܣ���x��С������
// ***************************************************************************/

double MyCTCalendar::ctcl_tail(double x)
{
  return x-floor(x);
}
// /****************************************************************************
// *������double ctcl_rem(double x,double w);
// *���ܣ���������
// ***************************************************************************/

double MyCTCalendar::ctcl_rem(double x,double w)
{
  return ctcl_tail(x/w)*w;
}

// /****************************************************************************
// *������double ctcl_round(double x);
// *���ܣ���������
// ***************************************************************************/

double MyCTCalendar::ctcl_round(double x){
  return floor(x+0.5);
}

// /***************************************************************************
// *������int ctcl_year_ganzhi(int y,int m,int d,int h);
// *���ܣ�����y��m��d��hʱ�����֧����1-60��
// ***************************************************************************/

int MyCTCalendar::ctcl_year_ganzhi(int y,int m,int d,int h)
{
  if ( (ctcl_date_to_days(y,m,d)+h/24.0)
       < ctcl_solar_term(y,3,1)-1.0 )/*  �ж��Ƿ������  */
    y-=1;
  return ctcl_round( ctcl_rem(y-3.0,60.0) );
}
// ***************************************************************************
// **TODO:ctcl_month_ganzhi, ctcl_day_ganzhi, ctcl_hour_ganzhi
// ***************************************************************************

//�ǶȺ���(˽��)
double MyCTCalendar::ang(double x,double t,double c1,double t0,double t2,double t3)
{
  return ctcl_tail(c1*x)*2*M_PI+t0-t2*t*t-t3*t*t*t;
}

// /****************************************************************************
// *������int ctcl_lunar_date(int y,int m,int d);
// *���ܣ�����ũ������
// ***************************************************************************/

int MyCTCalendar::ctcl_lunar_date(int y,int m,int d)
{
  int lunar_date=-1;
  const double rpi=180/M_PI;
  const double zone=8.0;  /*  ʱ��:������  */
  double t=(y-1899.5)/100.0;
  double ms=floor((y-1900)*12.3685);
  double f0=ang(ms,t,0,0.75933,2.172e-4,1.55e-7)
    +0.53058868*ms-8.37e-4*t+zone/24.0+0.5;
  double fc=0.1734-3.93e-4*t;
  double j0=693595+29*ms;
  double aa0=ang(ms,t,0.08084821133,359.2242/rpi,
         0.0000333/rpi,0.00000347/rpi);
  double ab0=ang(ms,t,7.171366127999999e-2,306.0253/rpi,
         -0.0107306/rpi,-0.00001236/rpi);
  double ac0=ang(ms,t,0.08519585128,21.2964/rpi,
         0.0016528/rpi,0.00000239/rpi);
  int i;
  for(i=-1;i<=13;i+=1){  /*  k=����Ϊ˷,k=������Ϊ��  */
    double aa=aa0+0.507984293*i;
    double ab=ab0+6.73377553*i;
    double ac=ac0+6.818486628*i;
    double f1=f0+1.53058868*i+fc*sin(aa)-0.4068*sin(ab)+0.0021*sin(2*aa)
      +0.0161*sin(2*ab)+0.0104*sin(2*ac)-0.0074*sin(aa-ab)-0.0051*sin(aa+ab);
    double j=j0+28*i+f1;  /*  ˷�����ĵ�Ч��׼������ʱ��  */
    int diff=ctcl_standard_days(y,m,d)-floor(j);  /*  ��ǰ�վ�˷�յĲ�ֵ  */
    if( diff>=0 && diff<=29 )
      lunar_date=diff+1;
  }
  return(lunar_date);
}

// /****************************************************************************
// *������int ctcl_leap_month(int y);
// *���ܣ�����y������£����򷵻�0
// ***************************************************************************/

int MyCTCalendar::ctcl_leap_month(int y)
{
    char leap=lunarstr.mid(y-beginning_year,2).at(0);
    //char leap;
    if(leap=='a')
        leap='0'+10;
    if(leap=='b')
        leap='0'+11;
    if(leap=='c')
        leap='0'+12;
    return leap-'0';
}

// /****************************************************************************
// *������int ctcl_lunar_month(int y,int m,int d);
// *���ܣ�����y��m��d�ն�Ӧ��ũ���·ݣ������ø�����ʾ
// ***************************************************************************/

int MyCTCalendar::ctcl_lunar_month(int y,int m,int d)
{
  double lunar_date=ctcl_lunar_date(y,m,d);
  int lunar_days=lunar_date-floor(lunar_date/100)*100;  /*  ũ������  */
  int leap_num=0;  /*  �ӵ��굽-849�����������  */
  int i;
  int non_leap;
  int lunar_month;

  for(i=-849;i<=y;i++){
    if(ctcl_leap_month(i)!=0)
      leap_num++;
  }

  non_leap=ctcl_round((ctcl_standard_days(y,m,d)
          -ctcl_standard_days(-849,1,21)
          -lunar_days)/29.530588)-leap_num;
  /*  �ӵ��굽-849�����Ч������(�۳�����)  */

  if(y<=240) non_leap++;
  if(y<=237) non_leap--;
  if(y<24) non_leap++;
  if(y<9) non_leap--;
  if(y<=-255) non_leap++;
  if(y<=-256) non_leap+=2;
  if(y<=-722) non_leap++;  /*  ��ʷ�ϵ��޸��½�  */

  lunar_month=ctcl_round(ctcl_rem(non_leap-3.0,12.0)+1.0);
  if(lunar_month==ctcl_leap_month(y-1) && m==1 && d<lunar_days)
    lunar_month*=-1;    /*  ���y-1��ĩ�������Ҹ��½ӵ���y��,��y�����Ҳ������  */
  else if(lunar_month==ctcl_leap_month(y))
    lunar_month*=-1;
  else if(lunar_month<ctcl_leap_month(y) || ( m<lunar_month && ctcl_leap_month(y) ) )
    lunar_month++;  /*  ���y�������µ�����δ��������ǰ���۳��˱�������£�����Ӧ������  */
  else lunar_month=ctcl_round(ctcl_rem(lunar_month-1,12)+1);

  return lunar_month;
}

// /***************************************************************************
// *������int ctcl_solar_to_lunar(int y,int m,int d,struct CTCalendar* ctc);
// *���ܣ��ѹ���y��m��d��ת��Ϊũ�������ctc��
// *����ֵ��-1���������ڲ��Ϸ���0��ũ�������ݣ�1��һ������
// ***************************************************************************/

int MyCTCalendar::ctcl_solar_to_lunar(int y,int m,int d,struct CTCalendar* ctc)
{
  int r,i;
  char buf[10];
       ::qsnprintf(buf, 10, "%02d%02d", m,d);
  QString MD = QString::fromAscii(buf);
  QString QueryStr;
  QueryStr=QString("select VALUE from holiday where DATA='"+MD+"'");
  ctc->holiday=ctcl_common_query("holiday",QueryStr);
  //logSqlError("holiday",QueryStr);
  int type=ctcl_calendar_type(y,m,d,1);
  QueryStr=QString("select VALUE from caltype where ID=%1").arg(type);
  ctc->caltype=ctcl_common_query("caltype",QueryStr);

  if(type==-1)return -1;
  QueryStr=QString("select VALUE from tiangan where ID=%1").arg(ctcl_year_ganzhi(y,m,d,12) %10);
  ctc->ganzhi=ctcl_common_query("gan",QueryStr);
  QueryStr=QString("select VALUE from dizhi where ID=%1").arg(ctcl_year_ganzhi(y,m,d,12) %12);
  ctc->ganzhi.append(ctcl_common_query("zhi",QueryStr));


//��ȡ24����
  for(i=0;i<24;i++){
    r=ctcl_days_to_date(y,ctcl_solar_term(y,i+1,1));
    if(r>=m*100+d){
        if(r == m*100+d){
            QueryStr=QString("select VALUE from sterm where ID=%1").arg(i);
            ctc->sterm=ctcl_common_query("sterm",QueryStr);
      }
      break;
    }else if(i==23){
      QueryStr=QString("select VALUE from sterm where ID=0");
      ctc->sterm=ctcl_common_query("sterm",QueryStr);
      r=ctcl_days_to_date(y+1,ctcl_solar_term(y+1,1,1));
    }
  }

  if(y>=maxyear){
    ctc->day=0;
    ctc->month=0;
    ctc->cday=tr("unknown");
    ctc->cmonth=tr("no data");
    return 0;
  }

 ctc->day=ctcl_lunar_date(y,m,d);
  if(ctc->day<=10){
   QueryStr=QString("select VALUE from cnumber where ID=%1").arg(ctc->day);
   ctc->cday=QString::fromUtf8("\345\210\235")+ctcl_common_query("day",QueryStr);/*  ��  */
  }else if(ctc->day<20){
   QueryStr=QString("select VALUE from cnumber where ID=%1").arg(ctc->day%10);
   ctc->cday=QString::fromUtf8("\345\215\201")+ctcl_common_query("day",QueryStr);/*  ʮ  */
  }else if(ctc->day==20){
    ctc->cday=QString::fromUtf8("\344\272\214\345\215\201");/*  ��ʮ  */
  }else if(ctc->day<30){
  QueryStr=QString("select VALUE from cnumber where ID=%1").arg(ctc->day%10);
  ctc->cday=QString::fromUtf8("\345\273\277")+ctcl_common_query("day",QueryStr);/*  إ  */
  }else if(ctc->day==30){
    ctc->cday=QString::fromUtf8("\344\270\211\345\215\201");/*  ��ʮ  */
  }

  ctc->month=ctcl_lunar_month(y,m,d);
  if(ctc->month==-12){
    ctc->cmonth=QString::fromUtf8("\351\227\260\345\215\201\344\272\214\346\234\210");/*  "��ʮ����"  */
  }else if(ctc->month==-11){
    ctc->cmonth=QString::fromUtf8("\351\227\260\345\215\201\344\270\200\346\234\210");       /*  "��ʮһ��"  */
  }else if(ctc->month==-1){
    ctc->cmonth=QString::fromUtf8("\351\227\260\346\255\243\346\234\210");       /*  "������"  */
  }else if(ctc->month<0){
    ctc->cmonth=QString::fromUtf8("\351\227\260");                /*  "��"  */
    QueryStr=QString("select VALUE from cnumber where ID=%1").arg(-ctc->month);
    ctc->cmonth.append(ctcl_common_query("month",QueryStr));
    ctc->cmonth.append(QString::fromUtf8("\346\234\210"));             /*   ��  */
  }else if(ctc->month==13){
    ctc->cmonth=QString::fromUtf8("\346\255\243\346\234\210");              /*  "����"  */
  }else{
    QueryStr=QString("select VALUE from cnumber where ID=%1").arg(ctc->month);
    ctc->cmonth=ctcl_common_query("month",QueryStr);
    ctc->cmonth.append(QString::fromUtf8("\346\234\210"));   /*   ��  */
  }
  memset(buf,sizeof(buf),0x00);
  if(qAbs(ctc->month)<13)
   ::qsnprintf(buf, 10, "%02d%02d", qAbs(ctc->month),ctc->day);
  else if(qAbs(ctc->month)==13)
   ::qsnprintf(buf, 10, "%02d%02d", 1,ctc->day);
   MD = QString::fromAscii(buf);
   if(ctc->month>0){
    QueryStr=QString("select VALUE from choliday where DATA='"+MD+"'");
    ctc->choliday=ctcl_common_query("choliday",QueryStr);
    //logSqlError("choliday",QueryStr);
    }
  return 1;
}



// /***************************************************************************
// *������bool InitConnection(QString Path)
// *���ܣ�connect to sqlite3 database
// *����ֵ��true ok,
// ***************************************************************************/
bool MyCTCalendar::InitConnection(QString Path)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path+"/lunar.db");
    if (!db.open()) {
            return false;
    }

    QSqlQuery query;
    query.exec("select * from lunar where MaxYear=2100");
    query.last();
    maxyear=query.value(0).toInt();
    lunarstr=query.value(1).toByteArray ();

    return true;
}

// /***************************************************************************
// *������void MyCTCalendar::logSqlError(  const QString& Type, const QString& error)
// *���ܣ�log error message to a log file
// *����ֵ��none
// ***************************************************************************/
void MyCTCalendar::logSqlError(const QString& Type, const QString& error)
{
    QFile f("mycalendar.log" );
    if ( !f.open(QIODevice::ReadWrite | QIODevice::Append ) )
        return;
    QTextStream t( &f );
    t << "Error time: " << QDateTime::currentDateTime().toString() << "\n";
    t << Type << "\n";
    t << error << "\n";
    f.close();
}


// /***************************************************************************
// *������MyCTCalendar::ctcl_common_query(QString type,Qstring querystr)
// *���ܣ�common query
// *����ֵ��result
// ***************************************************************************/
QString MyCTCalendar::ctcl_common_query(QString type,QString querystr)
{
    QSqlQuery query;
    query.prepare(querystr);
    if(!query.exec())
      logSqlError(type,query.lastError().text());
//    qDebug()<<query.last();
    if(query.next())
        return query.value(0).toString();
    return "";
}
