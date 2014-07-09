#include <QtGui>
#include <QTimer>
#include <QDebug>
#include <qmath.h>
#include "instrumentpanel.h"
#include "vernierwidget.h"
#include "receiver.h"
#define PI 3.1425926





InstrumentPanel::InstrumentPanel(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{
   // this->setAttribute(Qt::WA_TranslucentBackground);
    QAction * del_action = new QAction("删除",this);
    connect(del_action,SIGNAL(triggered()),this,SLOT(closeMySelf()));
    addAction(del_action);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("仪表盘");
    this->resize(300,300);

    argname_label = new QLabel("",this);
    argname_label->setAlignment(Qt::AlignCenter);
    argname_label->setFrameShape(QFrame::Box);
    argname_label->setFrameShadow(QFrame::Raised);
    argname_label->setLineWidth(2);
    valuedisplay = new QLineEdit(this);
    valuedisplay->setAlignment(Qt::AlignCenter);
    valuedisplay->setReadOnly(true);
    valuedisplay->setContextMenuPolicy(Qt::NoContextMenu);
    valuedisplay->setStyleSheet("QLineEdit{background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
    valuedisplay->setText("");
    argname_label->setGeometry(10,height()/2+18,210,25);
    valuedisplay->setGeometry(225,height()/2+18,65,25);

}


void InstrumentPanel::loadArgs(QString filename)
{
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

    int count = 0 ;
     count = in.readLine().toInt();
    if(count > 1 )
    {
        QMessageBox::warning(0,tr("警告"),tr("参数个数超过1，参数读取错误！"),tr("确定"));
        file.close();
        return;
    }
    if(count > 0)
    {

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
           file.close();
           argname_label->setText(roomname+":"+argname);
           return;
       }*/

       argname = controlinfo.at(controlinfo.size() - 1);
       argname.remove(" ");
       argname.remove(";");

       if(!roomIsCompleteConfigure(roomid))
       {
           file.close();
           argname_label->setText(roomname+":"+argname);
           return;
       }

       //温度报警
       if(argname == "温度")
       {
           saaar.range_down = analogsrange[roomid].temprature_down;
           saaar.range_up = analogsrange[roomid].temprature_up;
           saaar.alarm_down = analogsrange[roomid].temprature_alarmdown;
           saaar.alarm_up = analogsrange[roomid].temprature_alarmup;
           argunit = analogsrange[roomid].temprature_unit;

       }
       else if(argname == "湿度")
       {
           saaar.range_down = analogsrange[roomid].moisture_down;
           saaar.range_up = analogsrange[roomid].moisture_up;
           saaar.alarm_down = analogsrange[roomid].moisture_alarmdown;
           saaar.alarm_up = analogsrange[roomid].moisture_alarmup;
           argunit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           saaar.range_down = analogsrange[roomid].O2_down;
           saaar.range_up = analogsrange[roomid].O2_up;
           saaar.alarm_down = analogsrange[roomid].O2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].O2_alarmup;
           argunit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           saaar.range_down = analogsrange[roomid].CO2_down;
           saaar.range_up = analogsrange[roomid].CO2_up;
           saaar.alarm_down = analogsrange[roomid].CO2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].CO2_alarmup;
           argunit = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "空气品质")
       {
           saaar.range_down = analogsrange[roomid].index_down;
           saaar.range_up = analogsrange[roomid].index_up;
           saaar.alarm_down = analogsrange[roomid].index_alarmdown;
           saaar.alarm_up = analogsrange[roomid].index_alarmup;
           //argunit = alarmrange.temprature_unit;是否添加这一句
       }
       else if(argname == "市电电压")
       {
           saaar.range_down = analogsrange[roomid].voltage1_down;
           saaar.range_up = analogsrange[roomid].voltage1_up;
           saaar.alarm_down = analogsrange[roomid].voltage1_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage1_alarmup;
           argunit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           saaar.range_down = analogsrange[roomid].voltage2_down;
           saaar.range_up = analogsrange[roomid].voltage2_up;
           saaar.alarm_down = analogsrange[roomid].voltage2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage2_alarmup;
           argunit = analogsrange[roomid].voltage2_unit;
       }
    }
    file.close();
    qDebug()<<roomname;
    qDebug()<<saaar.range_up;
    qDebug()<<saaar.range_down;
    qDebug()<<saaar.alarm_up;
    qDebug()<<saaar.alarm_down;
    argname_label->setText(roomname+":"+argname);
}

void InstrumentPanel::reloadArgs()
{
    roomname = "";
    argname = "";
    argunit ="";
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

    int count = 0 ;
     count = in.readLine().toInt();
    if(count > 1 )
    {
        QMessageBox::warning(0,tr("警告"),tr("参数个数超过1，参数读取错误！"),tr("确定"));
        file.close();
        return;
    }
    if(count > 0)
    {

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
            file.close();
            argname_label->setText(roomname+":"+argname);
            return;
        }*/

        argname = controlinfo.at(controlinfo.size() - 1);
        argname.remove(" ");
        argname.remove(";");

        if(!roomIsCompleteConfigure(roomid))
        {
            file.close();
            argname_label->setText(roomname+":"+argname);
            return;
        }

       //温度报警
       if(argname == "温度")
       {
           saaar.range_down = analogsrange[roomid].temprature_down;
           saaar.range_up = analogsrange[roomid].temprature_up;
           saaar.alarm_down = analogsrange[roomid].temprature_alarmdown;
           saaar.alarm_up = analogsrange[roomid].temprature_alarmup;
           argunit = analogsrange[roomid].temprature_unit;

       }
       else if(argname == "湿度")
       {
           saaar.range_down = analogsrange[roomid].moisture_down;
           saaar.range_up = analogsrange[roomid].moisture_up;
           saaar.alarm_down = analogsrange[roomid].moisture_alarmdown;
           saaar.alarm_up = analogsrange[roomid].moisture_alarmup;
           argunit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           saaar.range_down = analogsrange[roomid].O2_down;
           saaar.range_up = analogsrange[roomid].O2_up;
           saaar.alarm_down = analogsrange[roomid].O2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].O2_alarmup;
           argunit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           saaar.range_down = analogsrange[roomid].CO2_down;
           saaar.range_up = analogsrange[roomid].CO2_up;
           saaar.alarm_down = analogsrange[roomid].CO2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].CO2_alarmup;
           argunit = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "空气品质")
       {
           saaar.range_down = analogsrange[roomid].index_down;
           saaar.range_up = analogsrange[roomid].index_up;
           saaar.alarm_down = analogsrange[roomid].index_alarmdown;
           saaar.alarm_up = analogsrange[roomid].index_alarmup;
           //argunit = alarmrange.temprature_unit;是否添加这一句
       }
       else if(argname == "市电电压")
       {
           saaar.range_down = analogsrange[roomid].voltage1_down;
           saaar.range_up = analogsrange[roomid].voltage1_up;
           saaar.alarm_down = analogsrange[roomid].voltage1_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage1_alarmup;
           argunit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           saaar.range_down = analogsrange[roomid].voltage2_down;
           saaar.range_up = analogsrange[roomid].voltage2_up;
           saaar.alarm_down = analogsrange[roomid].voltage2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage2_alarmup;
           argunit = analogsrange[roomid].voltage2_unit;
       }
    }
    file.close();
    qDebug()<<roomname;
    qDebug()<<saaar.range_up;
    qDebug()<<saaar.range_down;
    qDebug()<<saaar.alarm_up;
    qDebug()<<saaar.alarm_down;
    argname_label->setText(roomname+":"+argname);
    update();
}

void InstrumentPanel::launch()
{
   /* updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(drawInstrumentpanel()));
    updateTimer->start(2000);*/
    connect(rec,SIGNAL(switchRefresh()),this,SLOT(drawInstrumentpanel()));
    drawInstrumentpanel();
}

void InstrumentPanel::mousePressEvent(QMouseEvent *event)
{
    this->raise();
    if (event->button() == Qt::LeftButton) {
        dragposition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    emit raiseAllButton();
}

void InstrumentPanel::mouseMoveEvent(QMouseEvent *event)
{
    if(!(centralGem).contains(event->globalPos())) return;
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragposition);
        event->accept();
    }
}

void InstrumentPanel::paintEvent(QPaintEvent *)
{

    //valuedisplay->setText(QString::number(analog[roomnameToIds[roomname]],'g',1));
    QRegion region(0,0,300,197);
    this->setMask(region);

    static const QPoint needle[3] = {
        QPoint(2, -3),
        QPoint(-2, -3),
        QPoint(0, -75)
    };

    QColor tenscalecolor(127, 0, 127);
    QColor onescalecolor(0, 127, 127, 191);
    QColor needlecolor(Qt::red);
    QColor fivescalecolor(127,127,0);

    int side = qMin(width(), height());
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);
    //绘制背景

    painter.setBrush(Qt::lightGray);
    painter.setPen(Qt::NoPen);
    painter.drawPie(0,0,width(),height(),0,16*180);
    painter.drawRect(5,height()/2,width()-10,50);
    QPen framepen;
    framepen.setStyle(Qt::SolidLine);
    framepen.setWidth(2);
    framepen.setColor(Qt::darkGray);
    painter.setPen(framepen);
    painter.drawLine(6,height()/2 + 16,6,height()/2 +50);
    painter.drawLine(6,height()/2 +46,width()-8,height()/2 +46);
    painter.drawLine(width()-6,height()/2 + 16,width()-6,height()/2 +50);
    QLinearGradient linegradbrush(0,height()/2+6,0,height()/2+16);
    painter.setPen(Qt::NoPen);
    //QLinearGradient linegradbrush(0,0,0,10);
    linegradbrush.setColorAt(0.0,Qt::darkGray);
    linegradbrush.setColorAt(0.4,Qt::gray);
    linegradbrush.setColorAt(0.5,Qt::white);
    linegradbrush.setColorAt(0.6,Qt::gray);
    linegradbrush.setColorAt(1.0,Qt::darkGray);
    painter.setBrush(linegradbrush);
    //painter.setPen(Qt::SolidLine);
    painter.drawRect(5,height()/2+6,width()-10,10);

    QPen backgdpen;
    backgdpen.setWidth(5);
    painter.setPen(backgdpen);
    painter.setBrush(Qt::SolidPattern);

    //绘制边环
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(6);
    pen.setColor(Qt::blue);

    painter.setPen(pen);

    painter.drawArc(3,3,width()-6,height()-6,16,178*16);
    painter.translate(width() / 2, height() / 2);
    float tenscale = (saaar.range_up-saaar.range_down)/10.0;
    float scalewidth = 40;
    //绘制刻度值
    for(int i = 0; i < 11; i++)
        {
            qreal h = 110*qSin(PI*i*18/180.0);
            qreal w = 110*qCos(PI*i*18/180.0);
            QString str = QString::number(i*tenscale+saaar.range_down,'f',1);
             switch(i)
             {
             case 0:painter.drawText(-w-8.0,-h-5.0,scalewidth,10.0,Qt::AlignLeft|Qt::AlignVCenter,str);break;
             case 1:painter.drawText(-w-7.0,-h-7.0,scalewidth,10.0,Qt::AlignLeft|Qt::AlignVCenter,str);break;
             case 2:painter.drawText(-w-8.0,-h-2.0,scalewidth,10.0,Qt::AlignLeft|Qt::AlignVCenter,str);break;

             case 3:painter.drawText(-w-10.0,-h,scalewidth,10.0,Qt::AlignLeft|Qt::AlignVCenter,str);break;

             case 4:painter.drawText(-w-15.0,-h-1.0,scalewidth,10.0,Qt::AlignLeft|Qt::AlignVCenter,str);break;
             case 5:painter.drawText(-w-18.0,-h-7.0,scalewidth,10.0,Qt::AlignCenter,str);break;
             case 6:painter.drawText(-w-22.0,-h-1.0,scalewidth,10.0,Qt::AlignRight|Qt::AlignVCenter,str);break;

             case 7:painter.drawText(-w-24.0,-h,scalewidth,10.0,Qt::AlignRight|Qt::AlignVCenter,str);break;

             case 8:painter.drawText(-w-32.0,-h-2.0,scalewidth,10.0,Qt::AlignRight|Qt::AlignVCenter,str);break;
             case 9:painter.drawText(-w-31.0,-h-7.0,scalewidth,10.0,Qt::AlignRight|Qt::AlignVCenter,str);break;
             case 10:painter.drawText(-w-30.0,-h-6.0,scalewidth,10.0,Qt::AlignRight|Qt::AlignVCenter,str);break;
             }
        }
    painter.scale(side / 210.0, side / 210.0);

    painter.setBrush(tenscalecolor);
    painter.setPen(tenscalecolor);
    painter.save();
    painter.rotate(-180.0);
    //绘制10刻度
    for (int i = 0; i < 11; ++i)
    {
        painter.drawLine(85, 0, 96, 0);
        painter.rotate(18.0);

    }
    painter.restore();
    //绘制5刻度
    painter.setPen(fivescalecolor);
    painter.save();
    for(int i = 0; i < 21; i++)
    {
        if ((i % 2) != 0)
          painter.drawLine(89, 0, 96, 0);
        painter.rotate(-9.0);
    }

    painter.restore();

    painter.setPen(Qt::NoPen);
    painter.setBrush(needlecolor);

    painter.save();
    painter.setPen(Qt::SolidLine);
    qDebug()<<"instrumentpanel currentvalue"<<currentvalue;
    if(!isOffline(roomnameToIds[roomname]) && roomIsCompleteConfigure(roomnameToIds[roomname]))
    {
        if(currentvalue >= saaar.range_down - abnormaldatashift && currentvalue <= saaar.range_up + abnormaldatashift)
            painter.rotate(180.0*(currentvalue - saaar.range_down)/(saaar.range_up - saaar.range_down)-90.0);
        else
            painter.rotate(-90.0);
    }
    else
    {
         painter.rotate(-90.0);
    }
    painter.drawConvexPolygon(needle, 3);
    painter.restore();

        painter.save();
        painter.setBrush(Qt::black);
        painter.drawPie(-10,-10,20,20,0,180*16);
        painter.restore();


    //绘制1刻度
    painter.save();
    painter.setPen(onescalecolor);

    for (int j = 0; j < 100; ++j)
    {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(-1.8);
    }
    painter.restore();
}


QSize InstrumentPanel::sizeHint() const
{
    return QSize(100, 100);
}
void InstrumentPanel::drawInstrumentpanel()
{
    currentvalue = OFFLINEDATA;
    if(argname == "温度")
    {
        currentvalue = analog[roomnameToIds[roomname]].temprature;
    }
    else if(argname == "湿度")
    {
        currentvalue = analog[roomnameToIds[roomname]].moisture;
    }
    else if(argname == "氧气")
    {
        currentvalue = analog[roomnameToIds[roomname]].O2;
    }
    else if(argname == "二氧化碳")
    {
        currentvalue = analog[roomnameToIds[roomname]].CO2;
    }
    else if(argname == "空气品质")
    {
        currentvalue = analog[roomnameToIds[roomname]].index;
    }
    else if(argname == "市电电压")
    {
        currentvalue = analog[roomnameToIds[roomname]].voltage1;
    }
    else if(argname == "零电压差")
    {
        currentvalue = analog[roomnameToIds[roomname]].voltage2;
    }
    qDebug()<<"currentvalue"<<currentvalue;

    if(currentvalue > saaar.range_up)
    {
          currentvalue = saaar.range_up + abnormaldatashift;
    }
    else if(currentvalue < saaar.range_down)
    {
          currentvalue = saaar.range_down - abnormaldatashift;
    }

    if(!isOffline(roomnameToIds[roomname]) && roomIsCompleteConfigure(roomnameToIds[roomname]))
    {
        if( currentvalue > saaar.alarm_up)
        {
            valuedisplay->setStyleSheet("QLineEdit{color:red;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
        }
        else if(currentvalue < saaar.alarm_down)
        {
            valuedisplay->setStyleSheet("QLineEdit{color:magenta;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
        }
        else if(currentvalue >= saaar.range_down && currentvalue <= saaar.range_up)
        {
            valuedisplay->setStyleSheet("QLineEdit{color:lightgreen;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
        }
        if(currentvalue >= saaar.range_down && currentvalue <= saaar.range_up)
            valuedisplay->setText(QString::number(currentvalue,'f',1)+ " " + argunit);
        else
            valuedisplay->setText("error");
    }
    else
    {
        valuedisplay->setStyleSheet("QLineEdit{background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
        valuedisplay->setText("");
    }
    if(isVisible())
        update();
    else
    {
        qDebug()<<"InstrumentPanel invisible";
    }
}

void InstrumentPanel::closeMySelf()
{
    qDebug()<<"关闭我自己";
    emit delMySelf(this->windowTitle());
    this->close();
}

void InstrumentPanel::setControlState(int type)
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
