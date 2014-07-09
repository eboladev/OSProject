#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSqlQuery>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QHeaderView>
#include <qmath.h>
#include <QAction>
#include <QFontDatabase>
#include <QSqlDatabase>
#include "vernierwidget.h"
#include "receiver.h"
#include "struct.h"
#include "management/elderinfo.h"

VernierWidget::VernierWidget(QWidget *parent) :
    QWidget(parent),diswidthratio(0.875), disheightratio(0.875),vernierspaceratio(0.6),
    vernierargatriratio(0.8),argatrisratio(0.6)
{
    //anaargnum = 7;
    anaargnum = 5;
    resize(640,480);
    emit raiseAllButton();
    argnames<<"温度"<<"湿度"<<"氧气"<<"二氧化碳"<<"空气品质"<<"市电电压"<<"零电压差";
    switchnames<<"漏水"<<"烟雾"<<"报警灯";
    //argnames<<"温度"<<"湿度"<<"氧气"<<"二氧化碳"<<"空气品质";
   // switchnames<<"烟雾"<<"报警灯";
    values<<OFFLINEDATA<<OFFLINEDATA<<OFFLINEDATA<<OFFLINEDATA<<OFFLINEDATA;
    pmvalue = OFFLINEDATA;
    roomid = -1;
   connect(rec,SIGNAL(switchRefresh()),this,SLOT(changevalue()));
   // connect(rec,SIGNAL(pmRefresh()),this,SLOT(updatePMValue()));
    this->setObjectName("vernierwidget");
    //this->setStyleSheet("QWidget#vernierwidget{background-color:#F0FFFF;}");
    //changevalue();
}



void VernierWidget::initArg(QString filename)
{ 
    this->filename = filename;
    connect(raao,SIGNAL(refreshArgs()),this,SLOT(reloadArgs()));
    roomid = roomnameToIds[filename.remove("房间")];
    for(int i = 0; i < anaargnum; i++)
    {
        QString argname = argnames.at(i);
        SingleArgAlarmAndRange saaar;
        //温度报警
        if(argname == "温度")
        {
            saaar.range_down = analogsrange[roomid].temprature_down;
            saaar.range_up = analogsrange[roomid].temprature_up;
            saaar.alarm_down = analogsrange[roomid].temprature_alarmdown;
            saaar.alarm_up = analogsrange[roomid].temprature_alarmup;
            saaar.arg_unit = analogsrange[roomid].temprature_unit;
        }
        else if(argname == "湿度")
        {
            saaar.range_down = analogsrange[roomid].moisture_down;
            saaar.range_up = analogsrange[roomid].moisture_up;
            saaar.alarm_down = analogsrange[roomid].moisture_alarmdown;
            saaar.alarm_up = analogsrange[roomid].moisture_alarmup;
            saaar.arg_unit = analogsrange[roomid].moisture_unit;
        }
        else if(argname == "氧气")
        {
            saaar.range_down = analogsrange[roomid].O2_down;
            saaar.range_up = analogsrange[roomid].O2_up;
            saaar.alarm_down = analogsrange[roomid].O2_alarmdown;
            saaar.alarm_up = analogsrange[roomid].O2_alarmup;
            saaar.arg_unit = analogsrange[roomid].O2_unit;
        }
        else if(argname == "二氧化碳")
        {
            saaar.range_down = analogsrange[roomid].CO2_down;
            saaar.range_up = analogsrange[roomid].CO2_up;
            saaar.alarm_down = analogsrange[roomid].CO2_alarmdown;
            saaar.alarm_up = analogsrange[roomid].CO2_alarmup;
            saaar.arg_unit = analogsrange[roomid].CO2_unit;


            qDebug()<<"二氧化碳";
            qDebug()<<saaar.range_down;
            qDebug()<<saaar.range_up;
            qDebug()<<saaar.alarm_down;
            qDebug()<<saaar.alarm_up;
        }
        else if(argname == "空气品质")
        {
            saaar.range_down = analogsrange[roomid].index_down;
            saaar.range_up = analogsrange[roomid].index_up;
            saaar.alarm_down = analogsrange[roomid].index_alarmdown;
            saaar.alarm_up = analogsrange[roomid].index_alarmup;
            saaar.arg_unit = analogsrange[roomid].index_unit;
        }
        else if(argname == "市电电压")
        {
            saaar.range_down = analogsrange[roomid].voltage1_down;
            saaar.range_up = analogsrange[roomid].voltage1_up;
            saaar.alarm_down = analogsrange[roomid].voltage1_alarmdown;
            saaar.alarm_up = analogsrange[roomid].voltage1_alarmup;
            saaar.arg_unit = analogsrange[roomid].voltage2_unit;
        }
        else if(argname == "零电压差")
        {
            saaar.range_down = analogsrange[roomid].voltage2_down;
            saaar.range_up = analogsrange[roomid].voltage2_up;
            saaar.alarm_down = analogsrange[roomid].voltage2_alarmdown;
            saaar.alarm_up = analogsrange[roomid].voltage2_alarmup;
            saaar.arg_unit = analogsrange[roomid].voltage2_unit;
        }
        anargsvect.append(saaar);
        QLabel * label = new QLabel(this);
        label->setStyleSheet("background-image:url(images/analog_"+QString::number(i)+".png);background-repeat:no-repeat;");
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Raised);
        label->setLineWidth(3);
        argname_labels.append(label);
        QLineEdit * lineedit =new QLineEdit(QString::number(values.at(i),'f',1),this);
        lineedit->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        lineedit->setReadOnly(true);
        lineedit->setContextMenuPolicy(Qt::NoContextMenu);
        lineedit->setFrame(true);
        QFont font = lineedit->font();
        font.setBold(true);
        font.setPointSize(font.pointSize() + 1);
        lineedit->setFont(font);
        lineedit->setStyleSheet("QLineEdit{background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
        lineedit->setText("");
        argvalues.append(lineedit);
    }

    for(int i = 0; i < switchnames.size(); i++)
    {
        switchvalues.append(false);
        QLabel * label = new QLabel(this);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Raised);
        label->setLineWidth(3);
        label->setStyleSheet("background-image:url(images/switch_"+QString::number(i)+".png);");
        switchname_labels.append(label);
    }
    switchname_labels.at(0)->hide();
    /*pm_label = new QLabel(QString(" PM2.5(ug/m3) "),this);
    pm_label->setFixedHeight(25);
    pm_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pm_label->setFrameShape(QFrame::Box);
    pm_label->setFrameShadow(QFrame::Raised);
    pm_label->setLineWidth(2);
    pmval_lineedit = new QLineEdit(this);
    pmval_lineedit->setText("  ");
    pmval_lineedit->setAlignment(Qt::AlignCenter);
    pmval_lineedit->setReadOnly(true);
    pmval_lineedit->setMaximumWidth(40);
    pmval_lineedit->setContextMenuPolicy(Qt::NoContextMenu);
    pmval_lineedit->setStyleSheet("QLineEdit{background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");*/
    pmframe = new PM25Frame(this);
    dbftw = new OlderBriefInfoTableWidget(this->filename,this);
    changevalue();
}

void VernierWidget::reloadArgs()
{
    anargsvect.clear();
    for(int i = 0; i < anaargnum; i++)
    {
        QString argname = argnames.at(i);
        SingleArgAlarmAndRange saaar;
        //温度报警
        if(argname == "温度")
        {
            saaar.range_down = analogsrange[roomid].temprature_down;
            saaar.range_up = analogsrange[roomid].temprature_up;
            saaar.alarm_down = analogsrange[roomid].temprature_alarmdown;
            saaar.alarm_up = analogsrange[roomid].temprature_alarmup;
            saaar.arg_unit = analogsrange[roomid].temprature_unit;
        }
        else if(argname == "湿度")
        {
            saaar.range_down = analogsrange[roomid].moisture_down;
            saaar.range_up = analogsrange[roomid].moisture_up;
            saaar.alarm_down = analogsrange[roomid].moisture_alarmdown;
            saaar.alarm_up = analogsrange[roomid].moisture_alarmup;
            saaar.arg_unit = analogsrange[roomid].moisture_unit;
        }
        else if(argname == "氧气")
        {
            saaar.range_down = analogsrange[roomid].O2_down;
            saaar.range_up = analogsrange[roomid].O2_up;
            saaar.alarm_down = analogsrange[roomid].O2_alarmdown;
            saaar.alarm_up = analogsrange[roomid].O2_alarmup;
            saaar.arg_unit = analogsrange[roomid].O2_unit;
        }
        else if(argname == "二氧化碳")
        {
            saaar.range_down = analogsrange[roomid].CO2_down;
            saaar.range_up = analogsrange[roomid].CO2_up;
            saaar.alarm_down = analogsrange[roomid].CO2_alarmdown;
            saaar.alarm_up = analogsrange[roomid].CO2_alarmup;
            saaar.arg_unit = analogsrange[roomid].CO2_unit;


            qDebug()<<"二氧化碳";
            qDebug()<<saaar.range_down;
            qDebug()<<saaar.range_up;
            qDebug()<<saaar.alarm_down;
            qDebug()<<saaar.alarm_up;
        }
        else if(argname == "空气品质")
        {
            saaar.range_down = analogsrange[roomid].index_down;
            saaar.range_up = analogsrange[roomid].index_up;
            saaar.alarm_down = analogsrange[roomid].index_alarmdown;
            saaar.alarm_up = analogsrange[roomid].index_alarmup;
            saaar.arg_unit = analogsrange[roomid].index_unit;
        }
        else if(argname == "市电电压")
        {
            saaar.range_down = analogsrange[roomid].voltage1_down;
            saaar.range_up = analogsrange[roomid].voltage1_up;
            saaar.alarm_down = analogsrange[roomid].voltage1_alarmdown;
            saaar.alarm_up = analogsrange[roomid].voltage1_alarmup;
            saaar.arg_unit = analogsrange[roomid].voltage2_unit;
        }
        else if(argname == "零电压差")
        {
            saaar.range_down = analogsrange[roomid].voltage2_down;
            saaar.range_up = analogsrange[roomid].voltage2_up;
            saaar.alarm_down = analogsrange[roomid].voltage2_alarmdown;
            saaar.alarm_up = analogsrange[roomid].voltage2_alarmup;
            saaar.arg_unit = analogsrange[roomid].voltage2_unit;
        }
        anargsvect.append(saaar);
    }
    changevalue();
    qDebug()<<"vernier reloadargs";
   /* if(isVisible())
        update();*/

}

void VernierWidget::paintEvent(QPaintEvent *event)
{
    qDebug()<<"vernierpaintbefore";
    QPainter painter(this);
    QPen temppen = painter.pen();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(0xE0,0xFF,0xFF));
    painter.drawRect(0,0,width(),height());
    painter.setPen(temppen);
    painter.setRenderHints(QPainter::Antialiasing,true);
    painter.setRenderHints(QPainter::TextAntialiasing,true);
    qreal diswidth = (width()-LEFTMARGIN - RIGHTMARGIN)*diswidthratio;//显示区域长度
    qreal disheight = height()*disheightratio;//显示区域高度
    qreal vernierspace = diswidth/(anaargnum + 3);//游标加空格宽度
    qreal vernierwidth = vernierspace*vernierspaceratio;//游标宽度
    qreal vernierheight = disheight*vernierargatriratio;//游标高度
    qreal valueandnamewidth = vernierspace*argatrisratio;//参数名及值所占宽度
    qreal tenscaleheight = (vernierheight - vernierheight*0.045  - 20)/10.0;
    painter.save();
    QFont font;
    font.setPixelSize(20);
    painter.setFont(font);
    painter.drawText(width()*(1-diswidthratio)*6/2,0,width()*(1-diswidthratio)*2,
                     height()*(1-disheightratio),Qt::AlignHCenter|Qt::AlignVCenter,filename);
    painter.restore();
    painter.setPen(Qt::NoPen);

    for(int i = 0; i < anaargnum; i++)
    {
        //qDebug()<<"anaargnum1"<<anaargnum;
        qreal x = (width()-diswidth)/2.0+i*vernierspace;//上下标杆加游标尺区域左上角x坐标
        qreal y = (height()-disheight)*3/4.0+(disheight-vernierheight)/2;//下标杆加游标区域左上角y坐标
        //设置字体颜色
        /*if(!isOffline(roomid))
            if(values.at(i) >= anargsvect.at(i).range_down - abnormaldatashift &&  values.at(i) <= anargsvect.at(i).range_up + abnormaldatashift)
            {

                if(values.at(i) < anargsvect.at(i).alarm_down)
                {
                   // argvalues.at(i)->setStyleSheet("QLineEdit{color:magenta;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                }
                else if(values.at(i) > anargsvect.at(i).alarm_up)
                {
                    argvalues.at(i)->setStyleSheet("QLineEdit{color:red;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                }
                else
                {
                   // argvalues.at(i)->setStyleSheet("QLineEdit{color:lightgreen;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                }

                if(values.at(i) >= anargsvect.at(i).range_down && values.at(i) <= anargsvect.at(i).range_up)
                    argvalues.at(i)->setText(QString::number(values.at(i),'f',1)+ " "+anargsvect.at(i).arg_unit);
                else
                    argvalues.at(i)->setText("error");
            }
            else
            {
                argvalues.at(i)->setText("");
            }
        else
        {
            argvalues.at(i)->setText("");
        }*/
        argvalues.at(i)->setGeometry(x-0.2*valueandnamewidth,y*2/3.0,valueandnamewidth*1.4,y/4.0);//参数当前值
        QBrush tempbrush = painter.brush();

        QLinearGradient linegradient(x+1.0/3*vernierwidth,y+vernierheight*0.045*0.5,x+1.0/3*vernierwidth+1.0/3*vernierwidth,y+vernierheight*0.045*0.5);
        linegradient.setColorAt(0.0,Qt::darkGray);
        linegradient.setColorAt(0.5,Qt::white);
        linegradient.setColorAt(1.0,Qt::darkGray);
        painter.setBrush(linegradient);
        painter.drawRect(x+1.0/3*vernierwidth,y+vernierheight*0.045*0.5,1.0/3*vernierwidth,vernierheight*(1-0.045));//游标尺
        painter.setBrush(tempbrush);


        painter.setBrush(QBrush(Qt::gray));
        painter.drawRect(x,y,vernierwidth,vernierheight*0.045*0.5);//上标杆
        painter.setPen(Qt::SolidLine);
        painter.setBrush(QBrush(Qt::white));

        painter.setBrush(QBrush(Qt::black));
        painter.drawLine(x+2,y+vernierheight*0.045*0.5,x+vernierwidth,y+vernierheight*0.045*0.5);
        painter.drawLine(x+vernierwidth,y,x+vernierwidth,y+vernierheight*0.045*0.5);

        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::gray));
        painter.drawRect(x,y+vernierheight*(1-0.045*0.5) -1,vernierwidth,vernierheight*0.045*0.5 -1);//下标杆
        painter.setPen(Qt::SolidLine);
        painter.setBrush(QBrush(Qt::black));
        painter.drawLine(x+2,y+vernierheight -1,x+vernierwidth,y+vernierheight -1);
        painter.drawLine(x+vernierwidth,y+vernierheight*(1-0.045*0.5) -1,x+vernierwidth,y+vernierheight -1);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::gray));



        QPen temppen = painter.pen();
        painter.setPen(temppen);
       /* argname_labels.at(i)->setGeometry(x-0.3*valueandnamewidth,(height()-disheight)*3/4.0+(disheight+vernierheight)/2+5,
                                          valueandnamewidth*1.6,y/3);//参数名称*/
        argname_labels.at(i)->setGeometry(x-0.2*valueandnamewidth,(height()-disheight)*3/4.0+(disheight+vernierheight)/2+5,
                                                  valueandnamewidth*1.4,y/3);

        qreal currentheight = 0.0;//当前值得高度y
        currentheight = y+vernierheight*0.045*0.5+vernierheight*(1-0.045) - 10
                -(values.at(i)-anargsvect.at(i).range_down)*(vernierheight - vernierheight*0.045  - 20)
                /(anargsvect.at(i).range_up-anargsvect.at(i).range_down);
        QRectF needlerect(x+1.0/3*vernierwidth,currentheight,1.0/3*vernierwidth - 1,(values.at(i)-anargsvect.at(i).range_down)*(vernierheight - vernierheight*0.045  - 20)/(anargsvect.at(i).range_up-anargsvect.at(i).range_down));


        //房间未配置完成，应该作何处理
        if(roomIsCompleteConfigure(roomid))
        {
            if(values.at(i) >= anargsvect.at(i).range_down &&  values.at(i) <= anargsvect.at(i).range_up)
            {
                painter.save();
                QLinearGradient linegradient(x+1.0/3*vernierwidth,y+vernierheight*0.045*0.5,x+1.0/3*vernierwidth+1.0/3*vernierwidth,y+vernierheight*0.045*0.5);
                if(values.at(i)> anargsvect.at(i).alarm_up)
                {
                    linegradient.setColorAt(0.0,datacolor[alarmupcolor]);
                    linegradient.setColorAt(0.1,datacolor[alarmupcolor]);
                    linegradient.setColorAt(0.5,Qt::white);
                    linegradient.setColorAt(0.9,datacolor[alarmupcolor]);
                    linegradient.setColorAt(1.0,datacolor[alarmupcolor]);
                }
                else if(values.at(i)< anargsvect.at(i).alarm_down)
                {
                    linegradient.setColorAt(0.0,datacolor[alarmdowncolor]);
                    linegradient.setColorAt(0.1,datacolor[alarmdowncolor]);
                    linegradient.setColorAt(0.5,Qt::white);
                    linegradient.setColorAt(0.9,datacolor[alarmdowncolor]);
                    linegradient.setColorAt(1.0,datacolor[alarmdowncolor]);
                }
                else if(values.at(i) >= anargsvect.at(i).alarm_down && values.at(i) <= anargsvect.at(i).alarm_up)
                {
                    linegradient.setColorAt(0.0,datacolor[normalcolor]);
                    linegradient.setColorAt(0.1,datacolor[normalcolor]);
                    linegradient.setColorAt(0.5,Qt::white);
                    linegradient.setColorAt(0.9,datacolor[normalcolor]);
                    linegradient.setColorAt(1.0,datacolor[normalcolor]);
                }

                painter.setBrush(linegradient);
                painter.drawRect(needlerect);
                painter.restore();
            }
        //qDebug()<<"anaargnum2"<<anaargnum;





        for(int j = 0; j <= 100; j++)
        {
            if(j % 10 == 0)
            {
                painter.setPen(QPen(Qt::black));
                painter.drawLine(x+1.0/3*vernierwidth+vernierwidth/12,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-j*tenscaleheight/10,
                                 x+1.0/3*vernierwidth+1.0/3*vernierwidth-vernierwidth/12,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-j*tenscaleheight/10);
                painter.drawText(x+2.0/3*vernierwidth,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-j*tenscaleheight/10-y/8.0+5,valueandnamewidth,y/4.0,
                                 Qt::AlignHCenter,QString::number(((anargsvect.at(i).range_up-anargsvect.at(i).range_down))*j/10.0/10.0+anargsvect.at(i).range_down,'f',1));
            }
            else if(j % 5 == 0)
            {
                painter.setPen(QPen(Qt::black));
                painter.drawLine(x+1.0/3*vernierwidth+vernierwidth/9,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-j*tenscaleheight/10,
                                 x+1.0/3*vernierwidth+1.0/3*vernierwidth-vernierwidth/9,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-j*tenscaleheight/10);
            }
            else
            {

            }
        }
        //绘制报警下限，绘制报警上限
        QPen alarmepen;
        alarmepen.setWidth(2);
        alarmepen.setColor(datacolor[alarmdowncolor]);
        painter.setPen(alarmepen);
        painter.drawLine(x,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-((anargsvect.at(i).alarm_down-anargsvect.at(i).range_down)/(anargsvect.at(i).range_up-anargsvect.at(i).range_down))*tenscaleheight*10,
                         x+1.0/3*vernierwidth,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-((anargsvect.at(i).alarm_down-anargsvect.at(i).range_down)/(anargsvect.at(i).range_up-anargsvect.at(i).range_down))*tenscaleheight*10);
        alarmepen.setColor(datacolor[alarmupcolor]);
        painter.setPen(alarmepen);
        painter.drawLine(x,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-((anargsvect.at(i).alarm_up-anargsvect.at(i).range_down)/(anargsvect.at(i).range_up-anargsvect.at(i).range_down))*tenscaleheight*10,
                         x+1.0/3*vernierwidth,y+vernierheight*0.045*0.5+vernierheight*(1-0.045)-10-((anargsvect.at(i).alarm_up-anargsvect.at(i).range_down)/(anargsvect.at(i).range_up-anargsvect.at(i).range_down))*tenscaleheight*10);

        painter.setPen(Qt::NoPen);
        //qDebug()<<"vernierpainting";
        }
    }

    painter.setPen(Qt::SolidLine);

    if(!isOffline(roomid) &&roomIsCompleteConfigure(roomid))
    {
        if(pmvalue >= pmgrade[pmgrade_0])
        {
            pmframe->pmvalue_label->setText("  值："+QString::number(pmvalue));
            QString gradestr = "等级: ";
            if(pmvalue >= pmgrade[pmgrade_0] && pmvalue <= pmgrade[pmgrade_1])
            {
                pmframe->pmgrade_label->setText(gradestr + pmgrageshow[pm25_excellent]);
            }
            else if(pmvalue > pmgrade[pmgrade_1] && pmvalue <= pmgrade[pmgrade_2])
            {
                pmframe->pmgrade_label->setText(gradestr + pmgrageshow[pm25_fine]);
            }
            else if(pmvalue > pmgrade[pmgrade_2] && pmvalue <= pmgrade[pmgrade_3])
            {
                pmframe->pmgrade_label->setText(gradestr + pmgrageshow[pm25_light]);
            }
            else if(pmvalue > pmgrade[pmgrade_3] && pmvalue <= pmgrade[pmgrade_4])
            {
                pmframe->pmgrade_label->setText(gradestr + pmgrageshow[pm25_moderate]);
            }
            else if(pmvalue > pmgrade[pmgrade_4] && pmvalue <= pmgrade[pmgrade_5])
            {
                pmframe->pmgrade_label->setText(gradestr + pmgrageshow[pm25_serious]);
            }
            else if(pmvalue > pmgrade[pmgrade_5])
            {
                pmframe->pmgrade_label->setText(gradestr + pmgrageshow[pm25_grave]);
            }
        }
        else
        {
            pmframe->pmvalue_label->setText("error");
            pmframe->pmgrade_label->setText("");
        }

    }

    //绘制开关量
    // painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);
    qreal dbftwx = (width()-diswidth)/2.0+anaargnum*vernierspace+0.4*valueandnamewidth;//上下标杆加游标尺区域左上角x坐标
    qreal dbftwy = (height()-disheight)*3/4.0+(disheight-vernierheight)/2;//下标杆加游标区域左上角y坐标
    qreal rightmarginx = width() - RIGHTMARGIN - LEFTMARGIN;
    dbftw->setFixedWidth(rightmarginx - dbftwx);
    dbftw->move(dbftwx,dbftwy + 100);
    pmframe->move((dbftwx +rightmarginx)/2 - pmframe->width()/2 ,80);
    for(int i = anaargnum + 1; i < anaargnum + switchnames.size(); i++)
    {
        //qreal x = (width()-diswidth)/2.0+i*vernierspace;//上下标杆加游标尺区域左上角x坐标
        qreal y = (height()-disheight)*3/4.0+(disheight-vernierheight)/2;//下标杆加游标区域左上角y坐标
        qreal x = (width()-diswidth)/2.0+(i - 1)*(vernierspace + 10) + 15;//上下标杆加游标尺区域左上角x坐标
        int tempx = x+0.4*valueandnamewidth;
        int tempy = (height()-disheight)*3/4.0+(disheight+vernierheight)/2+5;
        //int tempwid = valueandnamewidth*1.6;
        int tempwid = valueandnamewidth*1.4;
        int tempheight = y/3;
        switchname_labels.at(i - anaargnum)->setGeometry(tempx,tempy,tempwid,tempheight);
        QRadialGradient lampbrush(QPointF(tempx+tempwid/2.0,tempy - 1.25*tempheight),0.85*tempheight,QPointF(tempx+tempwid/2.5,tempy - 1.35*tempheight));
        if(isOffline(roomid) || !roomIsCompleteConfigure(roomid))
        {
            lampbrush.setColorAt(0.0,Qt::white);
            lampbrush.setColorAt(0.8,Qt::gray);
            lampbrush.setColorAt(1.0,Qt::gray);
        }
        else if(!switchvalues.at( i - anaargnum ))
        {
            lampbrush.setColorAt(0.0,Qt::white);
            lampbrush.setColorAt(0.8,Qt::green);
            lampbrush.setColorAt(1.0,Qt::green);
        }
        else
        {
            lampbrush.setColorAt(0.0,Qt::white);
            lampbrush.setColorAt(0.7,Qt::red);
            lampbrush.setColorAt(1.0,Qt::red);
        }
        painter.setBrush(QBrush(Qt::darkGray));
        painter.drawEllipse(QPointF(tempx+tempwid/2.0,tempy - 1.25*tempheight),tempheight,tempheight);
        painter.setBrush(lampbrush);
        painter.drawEllipse(QPointF(tempx+tempwid/2.0,tempy - 1.25*tempheight),0.85*tempheight,0.85*tempheight);
    }

    qDebug()<<"vernierpaintafter";
    QWidget::paintEvent(event);
   // event->accept();
}

void VernierWidget::changevalue()
{
    bool flag = false;
    values[0] = analog[roomid].temprature;
    values[1] = analog[roomid].moisture;
    values[2] = analog[roomid].O2;
    values[3] = analog[roomid].CO2;
    values[4] = analog[roomid].index;
   // values[5] = analog[roomid].voltage1;
    //values[6] = analog[roomid].voltage2;

    for(int i = 0; i < anargsvect.count(); i++)
    {
        if(values[i] > anargsvect.at(i).range_up)
        {
            values[i] = anargsvect.at(i).range_up + abnormaldatashift;
        }
        else if(values[i] < anargsvect.at(i).range_down)
        {
            values[i] = anargsvect.at(i).range_down - abnormaldatashift;
        }


        if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            if(values.at(i) >= anargsvect.at(i).range_down - abnormaldatashift &&  values.at(i) <= anargsvect.at(i).range_up + abnormaldatashift)
            {

                if(values.at(i) < anargsvect.at(i).alarm_down)
                {
                    argvalues.at(i)->setStyleSheet("QLineEdit{color:magenta;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                }
                else if(values.at(i) > anargsvect.at(i).alarm_up)
                {
                    argvalues.at(i)->setStyleSheet("QLineEdit{color:red;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                }
                else
                {
                    argvalues.at(i)->setStyleSheet("QLineEdit{color:lightgreen;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
                }

                if(values.at(i) >= anargsvect.at(i).range_down && values.at(i) <= anargsvect.at(i).range_up)
                    argvalues.at(i)->setText(QString::number(values.at(i),'f',1)+ " "+anargsvect.at(i).arg_unit);
                else
                    argvalues.at(i)->setText("error");
            }
            else
            {
                argvalues.at(i)->setText("");
            }
        else
        {
            argvalues.at(i)->setText("");
        }
    }
    qDebug()<<"vernierwidgetchangevaluehahaha";


    pmvalue = analog[roomid].pm25;
    if(pmvalue < pmgrade[pmgrade_0])
    {
        pmvalue = pmgrade[pmgrade_0] - abnormaldatashift;
    }
    switchvalues[0] = swi[roomid].waterCurrent;
    switchvalues[1] = swi[roomid].smokeCurrent;



    int comindex = argnames.indexOf("空气品质");
    if(values.at(comindex) > anargsvect.at(comindex).alarm_up || values.at(comindex) < anargsvect.at(comindex).alarm_down/*是否判断空气品质下限*/ || pmvalue > pmgrade[pmgrade_5]|| switchvalues[0] || switchvalues[1] ||((mat[roomid].current^0x3f)&mat[roomid].bitmap))
    {
        switchvalues[2] = true;
    }
    else
    {
        switchvalues[2] = false;
    }


    if(isVisible())
    {
        update();
        qDebug()<<"changevalue update";
    }
    else
    {
        qDebug()<<"vernierwidgetchangevalue";
    }

}
void VernierWidget::updatePMValue()
{
    //判断有没有离线?属于整个楼层的 还是否要看起来是属于每个房间的


    /* if(!isOffline(roomid) )
    {
        pmval_lineedit->setStyleSheet("QLineEdit{color:lightgreen;background: black;border-left: 3px solid darkgray;border-right: 3px solid white;border-top: 3px solid darkgray;border-bottom: 3px solid white;}");
        pmval_lineedit->setText(QString::number(pm25s.value,'f',1));
    }
    else
    {
       pmval_lineedit->setText("  ");
    }*/
}

void VernierWidget::resizeEvent(QResizeEvent *)
{
    //update();
    qDebug()<<"resize";
}


OlderBriefInfoTableWidget::OlderBriefInfoTableWidget(QString roomname,QWidget *parent) :
    QTableWidget(parent)
{
    this->setRowCount(6);
    this->setColumnCount(4);
    this->roomname = roomname;
    qDebug()<<"roomname"<<roomname;
    roomid =  roomnameToIds[roomname.remove("房间")];
    QStringList headnames;
    headnames<<"床位"<<"姓名"<<"性别"<<"床垫";
    this->verticalHeader()->setVisible(false);
    this->setHorizontalHeaderLabels(headnames);//设置表头标题
    this->horizontalHeader()->setStretchLastSection(true);//设置满表宽度
    this->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    this->horizontalHeader()->setHighlightSections(false);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);//设置按行选择
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    this->setFocusPolicy(Qt::NoFocus);
    this->setFixedHeight(202);

    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction * deitail_action = new QAction("详细信息",this);
    connect(deitail_action,SIGNAL(triggered()),this,SLOT(detailInfo()));
    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(detailInfo()));
    addAction(deitail_action);
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            QTableWidgetItem * item = new QTableWidgetItem;
            item->setText("");
            item->setTextAlignment(Qt::AlignCenter);
            setItem(i,j,item);
        }
    }

    loadBriefInfo();
    connect(rec,SIGNAL(matRefresh()),this,SLOT(changeMatState()));
    changeMatState();
}

void OlderBriefInfoTableWidget::loadBriefInfo()
{
    qDebug()<<"loadbriefInfo";

    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        qDebug()<<"succeed";
        QSqlQuery query(globaldb);
        query.prepare("SELECT bitmap FROM device_info WHERE device_id = ?");
        qDebug()<<roomname;
        //int id = roomnameToIds[roomname.remove("房间")];
        query.addBindValue(roomid);
        qDebug()<<roomname<<roomid<<query.size();
        query.exec();
        if(query.next())
        {
            int bedbits = query.value(0).toInt();
            for(int i = 0; i < 6; i++)
            {
                if(bedbits&0x01 || bedbits&0x02)
                {
                    this->item(i,0)->setText(QString("%1号床").arg(i+1));
                    // this->item(i,0)->setData(Qt::UserRole,true);
                }
                bedbits = bedbits>>2;
            }
        }

        query.prepare("SELECT name,gender,bed_no,mat FROM elder_info WHERE device_id = ? AND valid = ?");
        query.addBindValue(roomid);
        query.addBindValue("1");
        query.exec();
        while(query.next())
        {
            int bedno = query.value(2).toInt();
            if(bedno > 0)
            {
                item(bedno - 1,0)->setData(Qt::UserRole,query.value(3).toBool());
                item(bedno - 1,1)->setText(query.value(0).toString());
                item(bedno - 1,2)->setText(query.value(1).toString());
            }
        }
        qDebug()<<"salghsahs";
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

void OlderBriefInfoTableWidget::detailInfo()
{
    qDebug()<<"详细信息";
    if(item(currentRow(),1)->text().isEmpty())
    {
        QMessageBox::warning(0,"警告","该床位无入住人员！","确定");
        return;
    }
    QString temproomname = roomname;
    temproomname.remove("房间");
    int index = temproomname.lastIndexOf("楼");
    QString buildingname = temproomname.mid(0,index - 1);
    QString floorname = QString::number(floornames.indexOf(temproomname.mid(index - 1,2)) + 1);
    QString roomname = temproomname.mid(index + 1,temproomname.count() - index);
    QStringList args;
    args<<buildingname<<floorname<<roomname;
    args<<item(currentRow(),0)->text().split("号").first();
    qDebug()<<"args"<<args;
    /*QStringList bfrlist = temproomname.split("楼");

    QStringList args;
    args<<bfrlist.first().append("楼");
    QString tempstr = bfrlist.at(1);
    args<<QString::number(floornames.indexOf(tempstr.append("楼")) + 1);
    args<<bfrlist.last();
    args<< this->item(currentRow(),0)->text().split("号").first();
    qDebug()<<"args"<<args;*/


    ElderInfo eiadd(VIEWELDER,args);
    eiadd.setLookupRoomEnable(false);
    eiadd.exec();

}
void OlderBriefInfoTableWidget::changeMatState()
{
    qDebug()<<"changeMatState";
    qDebug()<<"mat[roomid].current"<<mat[roomid].current<<"mat[roomid].bitmap"<<mat[roomid].bitmap;
    int matbits = mat[roomid].current & mat[roomid].bitmap;
    qDebug()<<matbits;
    for(int i = 0; i < 6; i++)
    {
        if(item(i,0)->data(Qt::UserRole).toBool())
        {
            if(matbits & 0x01)
            {
                item(i,3)->setText("正常");
            }
            else
            {
                item(i,3)->setText("异常");
            }

        }
        matbits = matbits>>1;
    }

}

void OlderBriefInfoTableWidget::onRefreshTableWidget(int id)
{

    if(id == roomid)
    {

        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                //是否内存泄露？
                QTableWidgetItem * item = new QTableWidgetItem;
                item->setText("");
                item->setTextAlignment(Qt::AlignCenter);
                setItem(i,j,item);
            }
        }
        loadBriefInfo();
        changeMatState();
    }
}


PM25Frame::PM25Frame(QWidget *parent) :
    QFrame(parent)
{
    this->setObjectName("PM25Frame");
     setStyleSheet("QFrame#PM25Frame{border-image:url(images/pm25.png);}");
     QFont font;
     QFontDatabase qdb;
     qDebug()<<"families"<<qdb.families();
     font.setFamily("楷体_GB2312");
     font.setPointSize(20);
     pmvalue_label = new QLabel(this);
     pmvalue_label->setFixedWidth(190);
     pmgrade_label = new QLabel(this);
     pmgrade_label->setFixedWidth(190);
     pmvalue_label->setFont(font);
     pmgrade_label->setFont(font);
     resize(245,80);
     pmvalue_label->move(60,10);
     pmgrade_label->move(60,40);
}
