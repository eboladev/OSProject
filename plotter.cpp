#include <cmath>
#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QtGui/QToolButton>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>
#include <QFile>
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QtGui/QStylePainter>
#include <QtGui/QStyleOptionFocusRect>
#include <QtGui/QMouseEvent>
#include <QtGui/QScrollBar>
#include <QtGui/QPushButton>

#include "plotter.h"
#include "plotsettings.h"
#include "struct.h"
#include "receiver.h"


Plotter::Plotter(QWidget *parent)
    : Widget(parent)
{
    this->numcurve = 0;
   // if(numcurve < 1) return;
    isstop = true;
    timescalecount = 0;
    hisx = -1;
    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);
    rubberbandisshown = false;

    /*zoomin_button = new QToolButton(this);
    zoomin_button ->setFocusPolicy(Qt::NoFocus);
    zoomin_button->setIcon(QIcon("images/zoomin.png"));
    zoomin_button->adjustSize();
    zoomin_button->setEnabled(false);
    connect(zoomin_button, SIGNAL(clicked()), this, SLOT(zoomIn()));

    zoomout_button = new QToolButton(this);
    zoomout_button->setFocusPolicy(Qt::NoFocus);
    zoomout_button->setIcon(QIcon("images/zoomout.png"));
    zoomout_button->adjustSize();
    zoomout_button->setEnabled(false);
    connect(zoomout_button, SIGNAL(clicked()), this, SLOT(zoomOut()));*/

    leftpage_button = new QToolButton(this);
    leftpage_button->setFocusPolicy(Qt::NoFocus);
    leftpage_button->setIcon(QIcon("images/leftpage.png"));
    leftpage_button->adjustSize();
    leftpage_button->hide();
    connect(leftpage_button,SIGNAL(clicked()),this,SLOT(leftPage()));

    rightpage_button = new QToolButton(this);
    rightpage_button->setFocusPolicy(Qt::NoFocus);
    rightpage_button->setIcon(QIcon("images/rightpage.png"));
    rightpage_button->adjustSize();
    rightpage_button->hide();
    connect(rightpage_button,SIGNAL(clicked()),this,SLOT(rightPage()));



    /*startandstop_button = new QPushButton(tr("开始"),this);
    startandstop_button->setFocusPolicy(Qt::NoFocus);
    startandstop_button->resize(40,22);
    connect(startandstop_button,SIGNAL(clicked()),this,SLOT(startAndStopTimer()));*/

    /*minmumandmaxmum_button = new QToolButton(this);
    minmumandmaxmum_button->setFocusPolicy(Qt::NoFocus);
    minmumandmaxmum_button->setIcon(QIcon("images/maxmum.png"));
    minmumandmaxmum_button->setAutoRaise(true);
    ismax = false;
    minmumandmaxmum_button->move(width()-minmumandmaxmum_button->width()-10,10);
    connect(minmumandmaxmum_button,SIGNAL(clicked()),this,SLOT(minimumAndMaxmum()));*/



    scrollbar = new QScrollBar(Qt::Horizontal,this);
    scrollbar->setRange(0,40);
    scrollbar->setSingleStep(1);
    scrollbar->setSliderPosition(40);
    scrollbar->setSliderDown(false);
    scrollbar->setTracking(true);
    olderscrollvalue = scrollbar->value();
    connect(scrollbar,SIGNAL(valueChanged(int)),this,SLOT(onValueChanged(int)));

    createUpAnddown_buttons();
    creatPlotSettings();
    curzoom = 0;

    realtimevaluehint = new QLabel("00:00:00 ",this);
    realtimevaluehint->setFixedHeight(20);
    realtimevaluehint->setAlignment(Qt::AlignCenter);
    /*realtimevaluehint->setFrameShape(QFrame::Box);
    realtimevaluehint->setFrameShadow(QFrame::Raised);
    realtimevaluehint->setLineWidth(2);*/
    realtimevaluehint->setStyleSheet("QLabel{color:black;border-left: 3px solid lightgreen;border-right: 3px solid lightgreen;border-top: 3px solid lightgreen;border-bottom: 3px solid lightgreen;}");
    //realtimevaluehint->setStyleSheet("QLabel{color:black;border-left: 3px solid lightgreen;border-right: 3px solid white;border-top: 3px solid white;border-bottom: 3px solid white;}");
    historyvaluehint = new QLabel("00:00:00 ",this);
    historyvaluehint->setFixedHeight(20);
    historyvaluehint->setAlignment(Qt::AlignCenter);
    /*historyvaluehint->setFrameShape(QFrame::Box);
    historyvaluehint->setFrameShadow(QFrame::Raised);
    historyvaluehint->setLineWidth(2);*/
    historyvaluehint->setStyleSheet("QLabel{color:black;border-left: 3px solid lightgreen;border-right: 3px solid lightgreen;border-top: 3px solid lightgreen;border-bottom: 3px solid lightgreen;}");
    realtimevaluehint->hide();
    historyvaluehint->hide();
    this->setMinimumSize(600,400);
    //qDebug()<<this->maximumSize();

    //refreshtime->start(150);
   //setMinimumSize(0,0);
    //geometryandsize = this->geometry();
    //connect(this,SIGNAL(raiseAllButton()),((TabInnerWidget *)parent),SLOT(raiseAllButton()));
    QAction * del_action = new QAction("删除",this);
    connect(del_action,SIGNAL(triggered()),this,SLOT(closeMySelf()));
    addAction(del_action);
    //setContextMenuPolicy(Qt::ActionsContextMenu);
    setAttribute(Qt::WA_DeleteOnClose);
}

void Plotter::loadArgs(QString filename)
{
    qDebug()<<"loadargsbegin";
    if(filename.isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("该控件不存在！"),tr("确定"));
        return;
    }
    this->filename = filename;
    connect(raao,SIGNAL(refreshArgs()),this,SLOT(reloadArgs()));
    QString path = "controls/";
    QFile file(path+filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        return;
    }
    QTextStream in(&file);
    QString controlstr;

    int count  = 0;
    count = in.readLine().toInt();
    qDebug()<<"numcurve"<<count;
    int itemnum = 0;
    QString roomname;
    QString argname;
    while(itemnum < count)
    {
       roomname.clear();
       argname.clear();
       controlstr = in.readLine();
       QStringList controlinfo = controlstr.split(":");
       for(int i = 0; i < controlinfo.size() - 1; i++)
       {
           QString str = controlinfo.at(i);
           str.remove(" ");
           roomname.append(str);
       }

       int roomid = roomnameToIds[roomname];
       /*if(isOffline(roomid))
       {
           itemnum++;
           continue;
       }*/
       argname = controlinfo.at(controlinfo.size() - 1);
       argname.remove(" ");
       argname.remove(";");
       if(!roomIsCompleteConfigure(roomid))
       {
           {
               itemnum++;
               continue;
           }
       }

       float range_down = 0;
       float range_up  = 0;
       float alarm_down = 0;
       float alarm_up = 0;
       QString argunit;
       roomnames.append(roomname);
       argnames.append(argname);

       //温度报警
       if(argname == "温度")
       {
           range_down = analogsrange[roomid].temprature_down;
           range_up = analogsrange[roomid].temprature_up;
           alarm_down = analogsrange[roomid].temprature_alarmdown;
           alarm_up = analogsrange[roomid].temprature_alarmup;
           argunit = analogsrange[roomid].temprature_unit;
       }
       else if(argname == "湿度")
       {
           range_down = analogsrange[roomid].moisture_down;
           range_up = analogsrange[roomid].moisture_up;
           alarm_down = analogsrange[roomid].moisture_alarmdown;
           alarm_up = analogsrange[roomid].moisture_alarmup;
           argunit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           range_down = analogsrange[roomid].O2_down;
           range_up = analogsrange[roomid].O2_up;
           alarm_down = analogsrange[roomid].O2_alarmdown;
           alarm_up = analogsrange[roomid].O2_alarmup;
           argunit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           range_down = analogsrange[roomid].CO2_down;
           range_up = analogsrange[roomid].CO2_up;
           alarm_down = analogsrange[roomid].CO2_alarmdown;
           alarm_up = analogsrange[roomid].CO2_alarmup;
           argunit = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "空气品质")
       {
           range_down = analogsrange[roomid].index_down;
           range_up = analogsrange[roomid].index_up;
           alarm_down = analogsrange[roomid].index_alarmdown;
           alarm_up = analogsrange[roomid].index_alarmup;
           //argunit = alarmrange.temprature_unit;
       }
       else if(argname == "市电电压")
       {
           range_down = analogsrange[roomid].voltage1_down;
           range_up = analogsrange[roomid].voltage1_up;
           alarm_down = analogsrange[roomid].voltage1_alarmdown;
           alarm_up = analogsrange[roomid].voltage1_alarmup;
           argunit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           range_down = analogsrange[roomid].voltage2_down;
           range_up = analogsrange[roomid].voltage2_up;
           alarm_down = analogsrange[roomid].voltage2_alarmdown;
           alarm_up = analogsrange[roomid].voltage2_alarmup;
           argunit = analogsrange[roomid].voltage2_unit;
       }

       PlotSettings settings(0,600.0,20,range_down,range_up,20);
       this->setPlotSettings(itemnum + 1,settings);
       qDebug()<<"loadargs0";
       QList<QPointF> points;
       for(int x = -40; x <= 21; ++x)
       {
           points.append(QPointF(x*30, -1000.0));
           datatimevec.append("00:00:00");
       }
       qDebug()<<"loadargs1";
       this->setCurveData(itemnum,points);
       qDebug()<<"loadargs2";
       qDebug()<<roomname;
       qDebug()<<range_up;
       qDebug()<<range_down;
       qDebug()<<alarm_up;
       qDebug()<<alarm_down;
       SingleArgAlarmAndRange saaar;
       saaar.range_down = range_down;
       saaar.range_up = range_up;
       saaar.alarm_down = alarm_down;
       saaar.alarm_up = alarm_up;
       saaar.arg_unit = argunit;
       argattris.insert(itemnum,saaar);
       numcurve++;
       itemnum++;
       QLineEdit * lineedit = new QLineEdit("",this);
       lineedit->setFixedHeight(20);
       lineedit->setReadOnly(true);
       lineedit->setAlignment(Qt::AlignCenter);
       lineedit->setFixedWidth(SCALESPACE);
       lineedit->setStyleSheet("QLineEdit{background: black;border-left: 2px solid gray;border-right: 2px solid white;border-top: 2px solid gray;border-bottom: 2px solid white;}");
       lineedit->hide();
       realtimevalues.append(lineedit);
       lineedit = new QLineEdit("",this);
       lineedit->setStyleSheet("QLineEdit{background: black;border-left: 2px solid gray;border-right: 2px solid white;border-top: 2px solid gray;border-bottom: 2px solid white;}");
       lineedit->setFixedHeight(20);
       lineedit->setReadOnly(true);
       lineedit->setAlignment(Qt::AlignCenter);
       lineedit->setFixedWidth(SCALESPACE);
       lineedit->hide();
       historyvalues.append(lineedit);
    }
    file.close();
    qDebug()<<"loadargsend";
    this->setMinimumWidth(LEFTMARGIN+RIGHTMARGIN+numcurve*SCALESPACE+30*20);
}

void Plotter::reloadArgs()
{
    roomnames.clear();
    argnames.clear();
    argattris.clear();
    numcurve = 0;
    QString path = "controls/";
    QFile file(path+filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       // QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        file.close();
        return;
    }
    QTextStream in(&file);
    QString controlstr;
    int count = 0;
    count = in.readLine().toInt();
    qDebug()<<"numcurve"<<count;
    int itemnum = 0;
    QString roomname;
    QString argname;
    while(itemnum < count)
    {
       roomname.clear();
       argname.clear();
       controlstr = in.readLine();
       QStringList controlinfo = controlstr.split(":");
       for(int i = 0; i < controlinfo.size() - 1; i++)
       {
           QString str = controlinfo.at(i);
           str.remove(" ");
           roomname.append(str);
       }

       int roomid = roomnameToIds[roomname];
       /*if(isOffline(roomid))
       {
           itemnum++;
           continue;
       }*/
       argname = controlinfo.at(controlinfo.size() - 1);
       argname.remove(" ");
       argname.remove(";");
       if(!roomIsCompleteConfigure(roomid))
       {
           {
               itemnum++;
               continue;
           }
       }

       float range_down = 0;
       float range_up  = 0;
       float alarm_down = 0;
       float alarm_up = 0;
       QString argunit;
       roomnames.append(roomname);
       argnames.append(argname);

       //温度报警
       if(argname == "温度")
       {
           range_down = analogsrange[roomid].temprature_down;
           range_up = analogsrange[roomid].temprature_up;
           alarm_down = analogsrange[roomid].temprature_alarmdown;
           alarm_up = analogsrange[roomid].temprature_alarmup;
           argunit = analogsrange[roomid].temprature_unit;
       }
       else if(argname == "湿度")
       {
           range_down = analogsrange[roomid].moisture_down;
           range_up = analogsrange[roomid].moisture_up;
           alarm_down = analogsrange[roomid].moisture_alarmdown;
           alarm_up = analogsrange[roomid].moisture_alarmup;
           argunit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           range_down = analogsrange[roomid].O2_down;
           range_up = analogsrange[roomid].O2_up;
           alarm_down = analogsrange[roomid].O2_alarmdown;
           alarm_up = analogsrange[roomid].O2_alarmup;
           argunit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           range_down = analogsrange[roomid].CO2_down;
           range_up = analogsrange[roomid].CO2_up;
           alarm_down = analogsrange[roomid].CO2_alarmdown;
           alarm_up = analogsrange[roomid].CO2_alarmup;
           argunit = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "空气品质")
       {
           range_down = analogsrange[roomid].index_down;
           range_up = analogsrange[roomid].index_up;
           alarm_down = analogsrange[roomid].index_alarmdown;
           alarm_up = analogsrange[roomid].index_alarmup;
           //argunit = alarmrange.temprature_unit;
       }
       else if(argname == "市电电压")
       {
           range_down = analogsrange[roomid].voltage1_down;
           range_up = analogsrange[roomid].voltage1_up;
           alarm_down = analogsrange[roomid].voltage1_alarmdown;
           alarm_up = analogsrange[roomid].voltage1_alarmup;
           argunit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           range_down = analogsrange[roomid].voltage2_down;
           range_up = analogsrange[roomid].voltage2_up;
           alarm_down = analogsrange[roomid].voltage2_alarmdown;
           alarm_up = analogsrange[roomid].voltage2_alarmup;
           argunit = analogsrange[roomid].voltage2_unit;
       }

       qDebug()<<roomname;
       qDebug()<<range_up;
       qDebug()<<range_down;
       qDebug()<<alarm_up;
       qDebug()<<alarm_down;
       SingleArgAlarmAndRange saaar;
       saaar.range_down = range_down;
       saaar.range_up = range_up;
       saaar.alarm_down = alarm_down;
       saaar.alarm_up = alarm_up;
       saaar.arg_unit = argunit;
       argattris.insert(itemnum,saaar);
       numcurve++;
       itemnum++;
    }
    file.close();
    this->setMinimumWidth(LEFTMARGIN+RIGHTMARGIN+numcurve*SCALESPACE+30*20);
    refreshPixmap();
}


void Plotter::launch()
{
    //第一次跟新数据，是否从数据库里面取部分历史数据

    realtimevaluehint->show();
    historyvaluehint->show();
    for(int i = 0; i < numcurve; i++)
    {
        realtimevalues.at(i)->show();
        historyvalues.at(i)->show();
    }
    updatedatatimer = new QTimer(this);
    /*connect(updatedatatimer, SIGNAL(timeout()), this, SLOT(updateData()));
    updatedatatimer->start(5000);*/
    connect(rec,SIGNAL(analogRefresh()),this,SLOT(updateData()));
    connect(rec,SIGNAL(switchRefresh()),this,SLOT(refreshPlotter()));
    updateData();
}
void Plotter::refreshPlotter()
{
    if(isVisible())
        refreshPixmap();
    else
    {
        qDebug()<<"Plotter invisible";
    }
}

void Plotter::updateData()
{
    int roomid = -1;
    QString color;
    for(int i = 0; i < numcurve; i++)
    {
        for(int j = 1; j <= 61;j++)
        {
            (curvemap[i])[j - 1].setY((curvemap[i])[j].y());
        }
        QString argname = argnames.at(i);
        roomid  = roomnameToIds[roomnames.at(i)];
        float value = OFFLINEDATA;//记得用常量替换回来
        realtimevaluehint->setText(datatimevec[60]);
        if(argname == "温度")
        {
            value = analog[roomid].temprature;
           // value = qrand()%(int(analogsrange[roomid].temprature_up - analogsrange[roomid].temprature_down ));
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(value > analogsrange[roomid].temprature_alarmup)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < analogsrange[roomid].temprature_alarmdown)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                realtimevalues.at(numcurve - i -1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >=analogsrange[roomid].temprature_down && value <=analogsrange[roomid].temprature_up)
                    realtimevalues.at(numcurve - i -1)->setText(QString::number(value,'f',1));//是否顺序倒过来
                else
                {
                    if(value > analogsrange[roomid].temprature_up)
                    {
                        value  = analogsrange[roomid].temprature_up + abnormaldatashift;
                    }
                    else if(value < analogsrange[roomid].temprature_down)
                    {
                        value  = analogsrange[roomid].temprature_down - abnormaldatashift;
                    }
                    realtimevalues.at(numcurve - i -1)->setText("error");
                }
            }
            else
            {
                realtimevalues.at(numcurve - i -1)->setText("");
            }

        }
        else if(argname == "湿度")
        {
            value = analog[roomid].moisture;
            //value = qrand()%(int(analogsrange[roomid].moisture_up - analogsrange[roomid].moisture_down ));
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(value > analogsrange[roomid].moisture_alarmup)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < analogsrange[roomid].moisture_alarmdown)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                realtimevalues.at(numcurve - i -1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >=analogsrange[roomid].moisture_down && value <=analogsrange[roomid].moisture_up)
                    realtimevalues.at(numcurve - i -1)->setText(QString::number(value,'f',1));//是否顺序倒过来
                else
                {
                    if(value > analogsrange[roomid].moisture_up)
                    {
                        value  = analogsrange[roomid].moisture_up + abnormaldatashift;
                    }
                    else if(value < analogsrange[roomid].moisture_down)
                    {
                        value  = analogsrange[roomid].moisture_down - abnormaldatashift;
                    }
                    realtimevalues.at(numcurve - i -1)->setText("error");
                }
            }
            else
            {
                 realtimevalues.at(numcurve - i -1)->setText("");
            }
        }
        else if(argname == "氧气")
        {
            value = analog[roomid].O2;
            //value = qrand()%(int(analogsrange[roomid].O2_up - analogsrange[roomid].O2_down ));
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(value > analogsrange[roomid].O2_alarmup)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < analogsrange[roomid].O2_alarmdown)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                realtimevalues.at(numcurve - i -1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >=analogsrange[roomid].O2_down && value <=analogsrange[roomid].O2_up)
                    realtimevalues.at(numcurve - i -1)->setText(QString::number(value,'f',1));//是否顺序倒过来
                else
                {
                    if(value > analogsrange[roomid].O2_up)
                    {
                        value  = analogsrange[roomid].O2_up + abnormaldatashift;
                    }
                    else if(value < analogsrange[roomid].O2_down)
                    {
                        value  = analogsrange[roomid].O2_down - abnormaldatashift;
                    }
                    realtimevalues.at(numcurve - i -1)->setText("error");
                }
            }
            else
            {
                 realtimevalues.at(numcurve - i -1)->setText("");
            }
        }
        else if(argname == "二氧化碳")
        {
            value = analog[roomid].CO2;
            //value = qrand()%(int(analogsrange[roomid].CO2_up - analogsrange[roomid].CO2_down ));
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(value > analogsrange[roomid].CO2_alarmup)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < analogsrange[roomid].CO2_alarmdown)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                realtimevalues.at(numcurve - i -1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >=analogsrange[roomid].CO2_down && value <=analogsrange[roomid].CO2_up)
                    realtimevalues.at(numcurve - i -1)->setText(QString::number(value,'f',1));//是否顺序倒过来
                else
                {
                    if(value > analogsrange[roomid].CO2_up)
                    {
                        value  = analogsrange[roomid].CO2_up + abnormaldatashift;
                    }
                    else if(value < analogsrange[roomid].CO2_down)
                    {
                        value  = analogsrange[roomid].CO2_down - abnormaldatashift;
                    }
                    realtimevalues.at(numcurve - i -1)->setText("error");
                }
            }
            else
            {
                realtimevalues.at(numcurve - i -1)->setText("");
            }
        }
        else if(argname == "空气品质")
        {
            value = analog[roomid].index;
            //value = qrand()%(int(analogsrange[roomid].index_up - analogsrange[roomid].index_down ));
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(value > analogsrange[roomid].index_alarmup)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < analogsrange[roomid].index_alarmdown)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                realtimevalues.at(numcurve - i -1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >=analogsrange[roomid].index_down && value <=analogsrange[roomid].index_up)
                    realtimevalues.at(numcurve - i -1)->setText(QString::number(value,'f',1));//是否顺序倒过来
                else
                {
                    if(value > analogsrange[roomid].index_up)
                    {
                        value  = analogsrange[roomid].index_up + abnormaldatashift;
                    }
                    else if(value < analogsrange[roomid].index_down)
                    {
                        value  = analogsrange[roomid].index_down - abnormaldatashift;
                    }
                    realtimevalues.at(numcurve - i -1)->setText("error");
                }
            }
            else
            {
                 realtimevalues.at(numcurve - i -1)->setText("");
            }
        }
        else if(argname == "市电电压")
        {
            value = analog[roomid].voltage1;
            //value = qrand()%(int(analogsrange[roomid].voltage1_up - analogsrange[roomid].voltage1_down ));
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(value > analogsrange[roomid].voltage1_alarmup)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < analogsrange[roomid].voltage1_alarmdown)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                realtimevalues.at(numcurve - i -1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >=analogsrange[roomid].voltage1_down && value <=analogsrange[roomid].voltage1_up)
                    realtimevalues.at(numcurve - i -1)->setText(QString::number(value,'f',1));//是否顺序倒过来
                else
                {
                    if(value > analogsrange[roomid].voltage1_up)
                    {
                        value  = analogsrange[roomid].voltage1_up + abnormaldatashift;
                    }
                    else if(value < analogsrange[roomid].voltage1_down)
                    {
                        value  = analogsrange[roomid].voltage1_down - abnormaldatashift;
                    }
                    realtimevalues.at(numcurve - i -1)->setText("error");
                }

            }
            else
            {
                  realtimevalues.at(numcurve - i -1)->setText("");
            }
        }
        else if(argname == "零电压差")
        {
            value = analog[roomid].voltage2;
            //value = qrand()%(int(analogsrange[roomid].voltage2_up - analogsrange[roomid].voltage2_down ));
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(value > analogsrange[roomid].voltage2_alarmup)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < analogsrange[roomid].voltage2_alarmdown)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                realtimevalues.at(numcurve - i -1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >=analogsrange[roomid].voltage2_down && value <=analogsrange[roomid].voltage2_up)
                    realtimevalues.at(numcurve - i -1)->setText(QString::number(value,'f',1));//是否顺序倒过来
                else
                {
                    if(value > analogsrange[roomid].voltage2_up)
                    {
                        value  = analogsrange[roomid].voltage2_up + abnormaldatashift;
                    }
                    else if(value < analogsrange[roomid].voltage2_down)
                    {
                        value  = analogsrange[roomid].voltage2_down - abnormaldatashift;
                    }
                    realtimevalues.at(numcurve - i -1)->setText("error");
                }

            }
            else
            {
                   realtimevalues.at(numcurve - i -1)->setText("");
            }
        }
        (curvemap[i])[60].setY(value);
        (curvemap[i])[61].setY(value);
    }
    if(roomid >= 0)
    for(int j = 1; j <= 60;j++)
    {
         datatimevec[j - 1] = datatimevec[j];
    }
    QString time = "00:00:00";

    time = QDateTime::fromMSecsSinceEpoch(analog[roomid].stamp).toString("hh:mm:ss");
    datatimevec[60] = time;
    datatimevec[61] = time;

    for(int i = 0; i < numcurve; i++)
        (*settingsstack[i])[curzoom].scroll(-300, 0);
    for(int i = 0; i < numcurve; i++)
        (*settingsstack[i])[curzoom].scroll(300, 0);
    if(isVisible())
        refreshPixmap();
    else
    {
        qDebug()<<"Plotter invisible";
    }
    timescalecount++;
    if(timescalecount == 4)
        timescalecount = 0;

}

void Plotter::setPlotSettings(int i,const PlotSettings &settings)
{
    if(i >= 1 )
    {
        settingsstack[i - 1];
        settingsstack[i - 1]->clear();
        settingsstack[i - 1]->append(settings);
    }
   // refreshPixmap();
}
void Plotter::creatPlotSettings()
{
    QVector<PlotSettings> * zoomStack;
    for(int i = 0; i < MAXCURVENUM; i++)
    {
        zoomStack = new  QVector<PlotSettings>;
        zoomStack->clear();
        zoomStack->append(PlotSettings());//注意plotsettings是否能够长期存在，是否会发生内存泄露，回头验证！
        settingsstack.append(zoomStack);
    }

   // refreshPixmap();

}
void Plotter::createUpAnddown_buttons()
{
       QToolButton * up;
       QToolButton * down;
       //第一条曲线按钮
       up = new QToolButton(this);
       up->setFocusPolicy(Qt::NoFocus);
       up->setIcon(QIcon("images/up.png"));
       up->setIconSize(QSize(10,10));
       up->hide();
       up_buttons.append(up);
       connect(up,SIGNAL(pressed()),this,SLOT(upCurve0()));
       down = new QToolButton(this);
       down->setFocusPolicy(Qt::NoFocus);
       down->setIcon(QIcon("images/down.png"));
       down->setIconSize(QSize(10,10));
       down->hide();
       down_buttons.append(down);
       connect(down,SIGNAL(clicked()),this,SLOT(downCurve0()));
       //第二条曲线按钮
       up = new QToolButton(this);
       up->setFocusPolicy(Qt::NoFocus);
       up->setIcon(QIcon("images/up.png"));
       up->setIconSize(QSize(10,10));
       up->hide();
       up_buttons.append(up);
       connect(up,SIGNAL(clicked()),this,SLOT(upCurve1()));
       down = new QToolButton(this);
       down->setFocusPolicy(Qt::NoFocus);
       down->setIcon(QIcon("images/down.png"));
       down->setIconSize(QSize(10,10));
       down->hide();
       down_buttons.append(down);
       connect(down,SIGNAL(clicked()),this,SLOT(downCurve1()));
       //第三条曲线按钮
       up = new QToolButton(this);
       up->setFocusPolicy(Qt::NoFocus);
       up->setIcon(QIcon("images/up.png"));
       up->setIconSize(QSize(10,10));
       up->hide();
       up_buttons.append(up);
       connect(up,SIGNAL(clicked()),this,SLOT(upCurve2()));
       down = new QToolButton(this);
       down->setFocusPolicy(Qt::NoFocus);
       down->setIcon(QIcon("images/down.png"));
       down->setIconSize(QSize(10,10));
       down->hide();
       down_buttons.append(down);
       connect(down,SIGNAL(clicked()),this,SLOT(downCurve2()));
       //第四条曲线按钮
       up = new QToolButton(this);
       up->setFocusPolicy(Qt::NoFocus);
       up->setIcon(QIcon("images/up.png"));
       up->setIconSize(QSize(10,10));
       up->hide();
       up_buttons.append(up);
       connect(up,SIGNAL(clicked()),this,SLOT(upCurve3()));
       down = new QToolButton(this);
       down->setFocusPolicy(Qt::NoFocus);
       down->setIcon(QIcon("images/down.png"));
       down->setIconSize(QSize(10,10));
       down->hide();
       down_buttons.append(down);
       connect(down,SIGNAL(clicked()),this,SLOT(downCurve3()));
       //第五条曲线按钮
       up = new QToolButton(this);
       up->setFocusPolicy(Qt::NoFocus);
       up->setIcon(QIcon("images/up.png"));
       up->setIconSize(QSize(10,10));
       up->hide();
       up_buttons.append(up);
       connect(up,SIGNAL(clicked()),this,SLOT(upCurve4()));
       down = new QToolButton(this);
       down->setFocusPolicy(Qt::NoFocus);
       down->setIcon(QIcon("images/down.png"));
       down->setIconSize(QSize(10,10));
       down->hide();
       down_buttons.append(down);
       connect(down,SIGNAL(clicked()),this,SLOT(downCurve4()));

}
void Plotter::upCurve0()
{
    qDebug()<<"upCurve0";
    (*settingsstack[0])[curzoom].scroll(0, -2);
    if(isstop) refreshPixmap();
}

void Plotter::downCurve0()
{
   qDebug()<<"downCurve0";
   (*settingsstack[0])[curzoom].scroll(0, +2);
   if(isstop) refreshPixmap();
}
void Plotter::upCurve1()
{
    qDebug()<<"upCurve1";
    (*settingsstack[1])[curzoom].scroll(0, -2);
   if(isstop) refreshPixmap();
}
void Plotter::downCurve1()
{
   qDebug()<<"downCurve1";
   (*settingsstack[1])[curzoom].scroll(0, +2);
    if(isstop) refreshPixmap();
}

void Plotter::upCurve2()
{
    qDebug()<<"upCurve2";
    (*settingsstack[2])[curzoom].scroll(0, -2);
    if(isstop) refreshPixmap();
}
void Plotter::downCurve2()
{
   qDebug()<<"downCurve2";
   (*settingsstack[2])[curzoom].scroll(0, +2);
   if(isstop) refreshPixmap();
}
void Plotter::upCurve3()
{
    qDebug()<<"upCurve3";
    (*settingsstack[3])[curzoom].scroll(0, -2);
   if(isstop) refreshPixmap();
}
void Plotter::downCurve3()
{
   qDebug()<<"downCurve3";
   (*settingsstack[3])[curzoom].scroll(0, +2);
   if(isstop) refreshPixmap();
}
void Plotter::upCurve4()
{
    qDebug()<<"upCurve4";
    (*settingsstack[4])[curzoom].scroll(0, -2);
    if(isstop) refreshPixmap();
}
void Plotter::downCurve4()
{
   qDebug()<<"downCurve4";
   (*settingsstack[4])[curzoom].scroll(0, +2);
   if(isstop) refreshPixmap();
}
/*void Plotter::startAndStopTimer()
{
    //开始停止按钮响应
    if(isstop)
    {
        isstop = false;
       // updateData();
        //updatedatatimer->start(30000);
       // refreshtime->start(30000);
        startandstop_button->setText(tr("暂停"));
    }
    else
    {
        isstop = true;
        refreshtime->stop();
        startandstop_button->setText(tr("开始"));
    }
}*/

void Plotter::leftPage()
{
    for(int i = 0; i < numcurve; i++)
        (*settingsstack[i])[curzoom].scroll((*settingsstack[i])[curzoom].numxticks*200, 0);
    if(isstop) refreshPixmap();
}

void Plotter::rightPage()
{

    for(int i = 0; i < numcurve; i++)
        (*settingsstack[i])[curzoom].scroll(-(*settingsstack[i])[curzoom].numxticks*200, 0);
     if(isstop) refreshPixmap();
}

void Plotter::onValueChanged(int value)
{
    qDebug()<<"value"<<value;
    for(int i = 0; i < numcurve; i++)
        (*settingsstack[i])[curzoom].scroll(300*(value - olderscrollvalue), 0);
    olderscrollvalue = value;
      refreshPixmap();
}

/*void Plotter::updateTimeDone()
{

    updateData();
}
*/
/*void Plotter::zoomOut()
{
    if (curzoom > 0) {
        --curzoom;
        zoomout_button->setEnabled(curzoom > 0);
        zoomin_button->setEnabled(true);
        zoomin_button->show();
        if(isstop) refreshPixmap();
    }
}

void Plotter::zoomIn()
{
    if (curzoom < settingsstack[0]->count() - 1) {
        ++curzoom;
        zoomin_button->setEnabled(curzoom < settingsstack[0]->count() - 1);
        zoomout_button->setEnabled(true);
        zoomout_button->show();
       if(isstop)  refreshPixmap();
    }
}*/

void Plotter::setCurveData(int id, const QList<QPointF> &data)
{
    curvemap.insert(id,data);
    qDebug()<<"setCurveData";
   // refreshPixmap();

}

void Plotter::clearCurve(int id)
{
    curvemap.remove(id);
    refreshPixmap();
}

/*QSize Plotter::minimumSizeHint() const
{
    return QSize(6 * Margin, 4 * Margin);
}*/

/*QSize Plotter::sizeHint() const
{
    return QSize(12 * Margin, 8 * Margin);
}*/

void Plotter::paintEvent(QPaintEvent *  event )
{
    QStylePainter painter(this);
    painter.drawPixmap(0, 0, pixmap);


    if (rubberbandisshown) {
        painter.setPen(palette().light().color());
        painter.drawRect(rubberbandrect.normalized()
                                       .adjusted(0, 0, -1, -1));
    }

   /* if (hasFocus()) {
        QStyleOptionFocusRect option;
        option.initFrom(this);
        option.backgroundColor = palette().dark().color();
        painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);
    }*/
    Widget::paintEvent(event);
   // refreshPixmap();
}

void Plotter::resizeEvent(QResizeEvent * event)
{
    qDebug()<<"resizeEvent1";
    //startandstop_button->move(LEFTMARGIN+SCALESPACE+15,height()-BOTTUMMARGIN+29);
    //zoomout_button->move(LEFTMARGIN+SCALESPACE+startandstop_button->width()+20,height()-BOTTUMMARGIN+29);
    qDebug()<<"resizeEvent();";
    //zoomin_button->move(LEFTMARGIN+SCALESPACE+startandstop_button->width()+zoomout_button->width()+25,height()-BOTTUMMARGIN+29);
    rightpage_button->move(LEFTMARGIN+numcurve*SCALESPACE,height()-BOTTUMMARGIN+29);
    leftpage_button->move(width()-RIGHTMARGIN-22,height()-BOTTUMMARGIN+29);

    for(int i = 0; i < numcurve; i++)
    {
        up_buttons[i]->move(LEFTMARGIN+(numcurve-i-1)*SCALESPACE-8,TOPMARGIN-20);
        up_buttons[i]->show();
        down_buttons[i]->move(LEFTMARGIN+(numcurve-i-1)*SCALESPACE-8,height()-BOTTUMMARGIN+5);
        down_buttons[i]->show();
    }
    scrollbar->move(LEFTMARGIN+numcurve*SCALESPACE+30,height()-BOTTUMMARGIN+30);
    scrollbar->resize(width()-LEFTMARGIN-RIGHTMARGIN-numcurve*SCALESPACE-60,20);

    realtimevaluehint->move(7,height()-BOTTUMMARGIN + 45);
    historyvaluehint->move(7,height()-BOTTUMMARGIN + 70);
    for(int i = 0 ; i < numcurve; i++)
    {
        realtimevalues.at(i)->move(LEFTMARGIN+i*SCALESPACE,height()-BOTTUMMARGIN + 43);
        historyvalues.at(i)->move(LEFTMARGIN+i*SCALESPACE,height()-BOTTUMMARGIN + 67);
    }

    Widget::resizeEvent(event);

    refreshPixmap();
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    QRect rect(LEFTMARGIN+numcurve*SCALESPACE, TOPMARGIN,
               width() - (LEFTMARGIN+RIGHTMARGIN+numcurve*SCALESPACE), height() -  (TOPMARGIN+BOTTUMMARGIN));
    if(!rect.contains(event->pos()))
          Widget::mousePressEvent(event);
    else
    {
       /* if (event->button() == Qt::LeftButton) {
            if (rect.contains(event->pos())) {
                rubberbandisshown = true;
                rubberbandrect.setTopLeft(event->pos());
                rubberbandrect.setBottomRight(event->pos());
                updateRubberBandRegion();
                setCursor(Qt::CrossCursor);
            }
        }*/
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    QRect rect(LEFTMARGIN+numcurve*SCALESPACE, TOPMARGIN,
               width() - (LEFTMARGIN+RIGHTMARGIN+numcurve*SCALESPACE), height() - (TOPMARGIN+BOTTUMMARGIN));
    if(!rect.contains(event->pos()))
    {
        //setCursorShape( getSideType(event->pos()));
        /*if (!m_changeRect)    //如果没按下鼠标左键, 判断是否在边框    (主要是为了按下鼠标后不要再验证鼠标形状了)
        {
            m_curShape = getSideType(event->pos());
            m_curChanged = setCursorShape(m_curShape);
        }
        else
        {
            //if(this->size() == this->minimumSize()&&m_curChanged) return;
            changeRectSize(m_curShape,event->pos());
        }*/
         setCursor(Qt::ArrowCursor);
         //设置当前值
         hisx = -1;
         historyvaluehint->setText("00:00:00");
         for(int k = 0; k < numcurve; k++)
         {
             historyvalues.at(k)->setText("");
         }
         Widget::mouseMoveEvent(event);
    }
    else
    {
       /* if (rubberbandisshown) {
            this->setCursor(Qt::CrossCursor);
            updateRubberBandRegion();
            rubberbandrect.setBottomRight(event->pos());
            updateRubberBandRegion();
        }*/
        if(numcurve > 0)
        {
            int curx =  event->pos().x();
            QVector<PlotSettings> * zoomStack = settingsstack[0];
            PlotSettings settings = (*zoomStack)[curzoom];
            for (int i = 0; i <= settings.numxticks; ++i) {//水平方向由上向下画网格
                int x = rect.left() + (i * (rect.width() - 1) / settings.numxticks);
                if((curx >= x - 2) && (curx <= x + 2))
                {
                    setCursor(Qt::CrossCursor);
                    qDebug()<<QDateTime::currentDateTime().time()<<i;
                    hisx = i;
                    qDebug()<<"i"<<i;
                    QString color;
                    for(int k = 0; k < numcurve; k++)
                    {
                        if(datatimevec.at(scrollbar->value()+ hisx).isEmpty())
                            historyvaluehint->setText("00:00:00");
                        else
                            historyvaluehint->setText(datatimevec.at(scrollbar->value()+ hisx));

                        float value = curvemap[k].at(scrollbar->value()+ hisx).y() ;//记得用常量替换回来
                        SingleArgAlarmAndRange tempsaar = argattris[k];
                        if(value >= tempsaar.range_down  - abnormaldatashift && value <= tempsaar.range_up + abnormaldatashift)
                        {
                            if(value > tempsaar.alarm_up)
                            {
                                color = datastrcolor[alarmupcolor];
                            }
                            else if(value < tempsaar.alarm_down)
                            {
                                color = datastrcolor[alarmdowncolor];
                            }
                            else
                            {
                                color = datastrcolor[normalcolor];
                            }
                            historyvalues.at(numcurve -k - 1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                            if(value >= tempsaar.range_down && value <= tempsaar.range_up)
                                historyvalues.at(numcurve -k - 1)->setText(QString::number(value,'f',1));
                            else
                                historyvalues.at(numcurve -k - 1)->setText("error");
                        }
                        else
                        {
                            historyvalues.at(numcurve -k - 1)->setText("");
                        }

                        //qDebug()<<curvemap[k].at(scrollbar->value() + hisx).x()<<curvemap[k].at(scrollbar->value() + hisx + 1).y();
                    }
                    //设置当前值
                    break;
                }
                else
                {
                    setCursor(Qt::ArrowCursor);
                    hisx = -1;
                    for(int k = 0; k < numcurve; k++)
                    {
                        historyvaluehint->setText("00:00:00");
                        historyvalues.at(k)->setText("");
                    }
                    //设置当前值
                }

            }
        }
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event)
{
    QRect rect(LEFTMARGIN+numcurve*SCALESPACE, TOPMARGIN,
               width() - (LEFTMARGIN+RIGHTMARGIN+numcurve*SCALESPACE), height() - (TOPMARGIN+BOTTUMMARGIN));
    if(!rect.contains(event->pos()))
    {
        /*if(rubberbandisshown == true)
        {
            rubberbandisshown = false;
            refreshPixmap();
            return;
        }*/
        Widget::mouseReleaseEvent(event);
    }
    else
    {
        /*if ((event->button() == Qt::LeftButton) && rubberbandisshown) {
            rubberbandisshown = false;
            updateRubberBandRegion();
            unsetCursor();

            QRect rect = rubberbandrect.normalized();
            if (rect.width() < 4 || rect.height() < 4)
                return;
            rect.translate(-(LEFTMARGIN+SCALESPACE*numcurve), -TOPMARGIN);

            for(int i = 0; i < numcurve; i++)
            {
                QVector<PlotSettings> * zoomStack = settingsstack[i];
                PlotSettings prevSettings = (*zoomStack)[curzoom];
                PlotSettings settings;
                double dx = prevSettings.spanX() / (width() - (LEFTMARGIN+RIGHTMARGIN+SCALESPACE*numcurve));
                double dy = prevSettings.spanY() / (height() - (TOPMARGIN+BOTTUMMARGIN));
                settings.minx = prevSettings.minx + dx * rect.left();
                settings.maxx = prevSettings.minx + dx * rect.right();
                settings.miny = prevSettings.maxy - dy * rect.bottom();
                settings.maxy = prevSettings.maxy - dy * rect.top();
                settings.adjust();//需要验证
                zoomStack->resize(curzoom + 1);
                zoomStack->append(settings);

            }
            zoomIn();
        }*/
        m_pressMouse = false;
        m_changeRect = false;
       this->setCursor(Qt::ArrowCursor);
    }
}

void Plotter::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Plus:
            //zoomIn();
            break;
        case Qt::Key_Minus:
            //zoomOut();
            break;
        case Qt::Key_Left:
            for(int i = 0; i < numcurve; i++) (*settingsstack[i])[curzoom].scroll(+1, 0);
            break;
        case Qt::Key_Right:
             for(int i = 0; i < numcurve; i++) (*settingsstack[i])[curzoom].scroll(-1, 0);
            break;
        case Qt::Key_Down:
             for(int i = 0; i < numcurve; i++) (*settingsstack[i])[curzoom].scroll(0, +1);
            break;
        case Qt::Key_Up:
             for(int i = 0; i < numcurve; i++) (*settingsstack[i])[curzoom].scroll(0, -1);
            break;
        default:
            QWidget::keyPressEvent(event);
        }
    if(isstop) refreshPixmap();
}

void Plotter::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;
    int numTicks = numDegrees / 15;
    if (event->orientation() == Qt::Horizontal) {
        for(int i = 0; i < numcurve; i++) (*settingsstack[i])[curzoom].scroll(numTicks, 0);
    } else {
        for(int i = 0; i < numcurve; i++) (*settingsstack[i])[curzoom].scroll(0, numTicks);
    }
   if(isstop) refreshPixmap();
}

void Plotter::updateRubberBandRegion()
{
    QRect rect = rubberbandrect.normalized();
    update(rect.left(), rect.top(), rect.width(), 1);
    update(rect.left(), rect.top(), 1, rect.height());
    update(rect.left(), rect.bottom(), rect.width(), 1);
    update(rect.right(), rect.top(), 1, rect.height());
}

void Plotter::refreshPixmap()
{
    pixmap = QPixmap(size());
   // qDebug()<<"pixmap size:"<<sizeof(pixmap);
    pixmap.fill(this, 0, 0);

    QPainter painter(&pixmap);
    painter.setBrush(Qt::gray);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,0,pixmap.width(),pixmap.height());
    painter.setBrush(Qt::NoBrush);
    painter.initFrom(this);
    drawGrid(&painter);
    drawCurves(&painter);  
    update();
}

void Plotter::drawGrid(QPainter *painter)
{
    //if(numcurve < 1) return;
    QRectF rect(LEFTMARGIN+numcurve*SCALESPACE, TOPMARGIN,
               width() - (LEFTMARGIN+RIGHTMARGIN+numcurve*SCALESPACE), height() - (TOPMARGIN+BOTTUMMARGIN));
    if (!rect.isValid())
        return;
    QRectF timerect(width()/2-80,30,160,40);
    QPen realtimepen;
    realtimepen.setWidth(5);
    //realtimepen.setColor(Qt::red);
    painter->setPen(realtimepen);
    //painter->drawRect(timerect);
    QFont realtimefont,tempFont;
    tempFont = painter->font();
    realtimefont.setPixelSize(27);
    painter->setFont(realtimefont);
    painter->drawText(timerect,Qt::AlignHCenter|Qt::AlignVCenter,QString(tr("实时曲线")));
    painter->setFont(tempFont);
    QVector<PlotSettings> * zoomStack = settingsstack[0];
    PlotSettings settings = (*zoomStack)[curzoom];
    QPen quiteDark = palette().dark().color().light();
    for (int i = 0; i <= settings.numxticks; ++i) {//水平方向由上向下画网格
        int x = rect.left() + (i * (rect.width() - 1) / settings.numxticks);
        //double label = settings.minx + (i * settings.spanX() / settings.numxticks);
        painter->setPen(quiteDark);
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }

    //绘制时间




    //QVector<PlotSettings> * zoomStack = settingsstack[0];
    //PlotSettings settings = (*zoomStack)[curzoom];
    QList<QPointF> data = curvemap[0];
    //int drawtimecount = 0;
    for (int j = 0; j <= 60; j++) {
        double dx = data[j].x() - settings.minx;
        //double dy = data[j].y() - settings.miny;
        double x = rect.left() + (dx * (rect.width() - 1)
                                  / settings.spanX());
        /*double y = rect.bottom() - (dy * (rect.height() - 1)
                                    / settings.spanY());*/
        painter->setPen(Qt::blue);
       /* if((j+timescalecount)%4 == 0 && data[j].y() != OFFLINEDATA && (x >= rect.left() && x <= rect.right()))
          painter->drawText(x - 50,rect.bottom() + 5, 100, 20,Qt::AlignHCenter | Qt::AlignTop,datatimevec[j]);*/
        if((j+timescalecount)%4 == 0 && (x >= rect.left() && x <= rect.right()))
          painter->drawText(x - 50,rect.bottom() + 5, 100, 20,Qt::AlignHCenter | Qt::AlignTop,datatimevec[j]);
        // j += 4;
    }




    for (int j = 0; j <= settings.numyticks; ++j) {//垂直方向由左向右画网格
        int y = rect.bottom() - (j * (rect.height() - 1)
                                   / settings.numyticks);
       /* double label = settings.minY + (j * settings.spanY()
                                          / settings.numYTicks);*/
        painter->setPen(quiteDark);
        painter->drawLine(rect.left(), y, rect.right(), y);
       // painter->setPen(light);
     //   painter->drawLine(rect.left() - 5, y, rect.left(), y);
       /* painter->drawText(rect.left() - Margin, y - 10, Margin - 5, 20,
                          Qt::AlignRight | Qt::AlignVCenter,
                          QString::number(label));*/
    }
    painter->drawRect(rect.adjusted(0, 0, -1, -1));
    int xAxis  = rect.left();
    for(int k = 1; k <= numcurve; k++)
    {
        painter->setPen(colorforids[uint(k-1) % 5]);
        settings = (*settingsstack[k-1])[curzoom];
        xAxis = rect.left()-k*SCALESPACE;
        painter->drawLine(xAxis,TOPMARGIN,xAxis,TOPMARGIN+rect.height());
        for(int l = 0; l <= settings.numyticks; l++)
        {
            int y = rect.bottom() - (l * (rect.height() - 1)
                                     / settings.numyticks);
           // painter->setPen(light);
            painter->drawLine(xAxis,y,xAxis+5,y);
            double label = settings.miny + (l * settings.spanY()
                                                      / settings.numyticks);
            painter->drawText(xAxis + SCALESPACE/6.0 , y - 10, 55, 20,
                                      Qt::AlignLeft | Qt::AlignVCenter,
                              QString::number(label,'f',1));
        }
    }
    for(int k = 0; k < numcurve; k++)
    {
        painter->setPen(colorforids[uint(k) % 5]);
        painter->drawLine(this->width()-ILLSTRATEWIDTH-RIGHTMARGIN,20+k*ILLSTRATEHEIGHT,
                          this->width()-RIGHTMARGIN-ILLSTRATEWIDTH+LINELEN - 10,20+k*ILLSTRATEHEIGHT);
        painter->drawText(this->width()-RIGHTMARGIN-ILLSTRATEWIDTH+LINELEN,20+k*ILLSTRATEHEIGHT-7.5,
                          ILLSTRATEWIDTH-LINELEN, 20, Qt::AlignLeft | Qt::AlignVCenter,roomnames.at(k)+":"+argnames.at(k)+" ("+argattris[k].arg_unit+")");
        painter->drawText(LEFTMARGIN+(numcurve-k-1)*SCALESPACE-8,TOPMARGIN-37,55,20,Qt::AlignLeft | Qt::AlignVCenter,QString::number(argattris[k].range_up,'f',1));
        painter->drawText(LEFTMARGIN+(numcurve-k-1)*SCALESPACE-8,height()-BOTTUMMARGIN+20,55,20,Qt::AlignLeft | Qt::AlignVCenter,QString::number(argattris[k].range_down,'f',1));
    }


    for(int k = 0; k < numcurve; k++)
    {


       // down_buttons[k]->move(LEFTMARGIN+(numcurve-i-1)*SCALESPACE-8,height()-BOTTUMMARGIN+5);
    }


    //refreshPixmap();
}

void Plotter::drawCurves(QPainter *painter)
{
    QRect rect(LEFTMARGIN+numcurve*SCALESPACE, TOPMARGIN,
               width() - (LEFTMARGIN+RIGHTMARGIN+numcurve*SCALESPACE), height() -  (TOPMARGIN+BOTTUMMARGIN));
    if (!rect.isValid())
        return;
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setClipRect(rect.adjusted(+1, +1, -1, -1));

    bool drawtimefirst = true;
    QMapIterator<int, QList<QPointF> > i(curvemap);
    int curid = 0;
    while (i.hasNext())
    {
        i.next();
        int id = i.key();
        QVector<PlotSettings> * zoomStack = settingsstack[id];
        PlotSettings settings = (*zoomStack)[curzoom];
        QList<QPointF> data = i.value();
        QPolygonF polyline(data.count());

        for (int j = 0; j < data.count(); ++j) {
            double dx = data[j].x() - settings.minx;
            double dy = data[j].y() - settings.miny;
            double x = rect.left() + (dx * (rect.width() - 1)
                                         / settings.spanX());
            double y = rect.bottom() - (dy * (rect.height() - 1)
                                           / settings.spanY());
            polyline[j] = QPointF(x, y);
            //绘制每一个时间点
            painter->setPen(Qt::blue);
           /* if(drawtimefirst)
            {
                painter->drawText(x,rect.bottom() + 5, 100, 20,
                                  Qt::AlignHCenter | Qt::AlignTop,
                                  datatimevec[j]);
                qDebug()<<"datatimevec"<<datatimevec[j];
            }*/
        }
        drawtimefirst = false;
        painter->setPen(colorforids[uint(id) % 5]);
        //painter->drawPolyline(polyline);
        for(int j = 0; j < data.count() - 1; ++j)
        {
            //if(data[j].y() != OFFLINEDATA && data[j+1].y() != OFFLINEDATA)//这里的curid是否跟实际值相对应
            if((data[j].y() != OFFLINEDATA && data[j+1].y() != OFFLINEDATA)&&(data[j].y() >= argattris[curid].range_down - abnormaldatashift && data[j].y() <= argattris[curid].range_up + abnormaldatashift) && (data[j+1].y()  >= argattris[curid].range_down - abnormaldatashift && data[j+1].y() <= argattris[curid].range_up + abnormaldatashift))
                painter->drawLine(polyline[j],polyline[j + 1]);
        }
        curid++;
    }
    if(hisx >= 0)
        for(int k = 0; k < numcurve; k++)
        {
            QString color;
            if(datatimevec.at(scrollbar->value()+ hisx).isEmpty())
                historyvaluehint->setText("00:00:00");
            else
                historyvaluehint->setText(datatimevec.at(scrollbar->value()+ hisx));
            float value = curvemap[k].at(scrollbar->value()+ hisx).y() ;//记得用常量替换回来
            SingleArgAlarmAndRange tempsaar = argattris[k];
            if(value >= tempsaar.range_down  - abnormaldatashift && value <= tempsaar.range_up + abnormaldatashift)
            {
                if(value > tempsaar.alarm_up)
                {
                    color = datastrcolor[alarmupcolor];
                }
                else if(value < tempsaar.alarm_down)
                {
                    color = datastrcolor[alarmdowncolor];
                }
                else
                {
                    color = datastrcolor[normalcolor];
                }
                historyvalues.at(numcurve -k - 1)->setStyleSheet("QLineEdit{color:" +color+";background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                if(value >= tempsaar.range_down  && value <= tempsaar.range_up )
                    historyvalues.at(numcurve -k - 1)->setText(QString::number(value,'f',1));
                else
                    historyvalues.at(numcurve -k - 1)->setText("error");
            }
            else
            {
                historyvalues.at(numcurve -k - 1)->setText("");
            }




            /*if(curvemap[k].at(scrollbar->value()+ hisx).y() != OFFLINEDATA)
                historyvalues.at(numcurve -k - 1)->setText(QString::number(curvemap[k].at(scrollbar->value() + hisx).y(),'f',1));
            else
                historyvalues.at(numcurve -k - 1)->setText("");*/
        }
   // refreshPixmap();
}

const QColor Plotter::colorforids[5]= {
       Qt::red, Qt::green, Qt::blue, Qt::cyan, Qt::magenta //Qt::yellow
   };


/*void Plotter::minimumAndMaxmum()
{
    qDebug()<<geometryandsize;
    if(!ismax)
    {
        geometryandsize = geometry();
        this->showMinimized();
      //  this->showMaximized();
        ismax = true;
        minmumandmaxmum_button->setIcon(QIcon("images/minmum.png"));
    }
    else
    {
        this->setGeometry(geometryandsize);
        this->move(geometryandsize.x(),geometryandsize.y());
        this->resize(geometryandsize.width(),geometryandsize.height());
        ismax = false;
        minmumandmaxmum_button->setIcon(QIcon("images/maxmum.png"));
    }
}*/

void Plotter::closeMySelf()
{
    qDebug()<<"关闭我自己";
    emit delMySelf(this->windowTitle());
    this->close();
}

void Plotter::setControlState(int type)
{
    opentype = type;
    if(opentype == NEW)
    {
        setContextMenuPolicy(Qt::ActionsContextMenu);
    }
    else if(opentype == OPEN)
    {

    }
    else if(opentype == EDIT)
    {
        setContextMenuPolicy(Qt::ActionsContextMenu);
    }
}
