#include <QtGui>
#include <QTimer>
#include "histoGramWidget.h"
#include "receiver.h"
#include "struct.h"
#include "widget.h"




HistoGramWidget::HistoGramWidget(QWidget *parent): Widget( parent )
{
    setMinimumSize(240,160);
  //  adjustSize();
    initGram();
    QAction * del_action = new QAction("删除",this);
    connect(del_action,SIGNAL(triggered()),this,SLOT(closeMySelf()));
    addAction(del_action);
   // setContextMenuPolicy(Qt::ActionsContextMenu);
    setAttribute(Qt::WA_DeleteOnClose);

}

void HistoGramWidget::loadArgs(QString filename)
{
    int effectargnum = 0;
    if(filename.isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("该控件不存在！"),tr("确定"));
        return;
    }
    this->filename = filename;
    connect(raao,SIGNAL(refreshArgs()),this,SLOT(reloadargs()));
    //histname = filename;
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
    int itemnum = 0;
    QString controlname;
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
           controlname.append(str);
           roomname.append(str);
           //roomname.append("*");
       }
       //roomname.remove(roomname.size() - 1,1);

       int roomid = roomnameToIds[roomname];
      /* if(isOffline(roomid))
       {
           itemnum++;
           continue;
       }*/
       argname = controlinfo.at(controlinfo.size() - 1);
       argname.remove(" ");
       argname.remove(";");
       if(!roomIsCompleteConfigure(roomid))
       {
           itemnum++;
           continue;
       }

       float range_down = 0;
       float range_up  = 0;
       float alarm_down = 0;
       float alarm_up = 0;

       //温度报警
       if(argname == "温度")
       {
           range_down = analogsrange[roomid].temprature_down;
           range_up = analogsrange[roomid].temprature_up;
           alarm_down = analogsrange[roomid].temprature_alarmdown;
           alarm_up = analogsrange[roomid].temprature_alarmup;
           histogram->argunit = analogsrange[roomid].temprature_unit;

       }
       else if(argname == "湿度")
       {
           range_down = analogsrange[roomid].moisture_down;
           range_up = analogsrange[roomid].moisture_up;
           alarm_down = analogsrange[roomid].moisture_alarmdown;
           alarm_up = analogsrange[roomid].moisture_alarmup;
           histogram->argunit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           range_down = analogsrange[roomid].O2_down;
           range_up = analogsrange[roomid].O2_up;
           alarm_down = analogsrange[roomid].O2_alarmdown;
           alarm_up = analogsrange[roomid].O2_alarmup;
           histogram->argunit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           range_down = analogsrange[roomid].CO2_down;
           range_up = analogsrange[roomid].CO2_up;
           alarm_down = analogsrange[roomid].CO2_alarmdown;
           alarm_up = analogsrange[roomid].CO2_alarmup;
           histogram->argunit = analogsrange[roomid].CO2_unit;

       }
       else if(argname == "空气品质")
       {
           range_down = analogsrange[roomid].index_down;
           range_up = analogsrange[roomid].index_up;
           alarm_down = analogsrange[roomid].index_alarmdown;
           alarm_up = analogsrange[roomid].index_alarmup;
           //histogram->argunit;
       }
       else if(argname == "市电电压")
       {
           range_down = analogsrange[roomid].voltage1_down;
           range_up = analogsrange[roomid].voltage1_up;
           alarm_down = analogsrange[roomid].voltage1_alarmdown;
           alarm_up = analogsrange[roomid].voltage1_alarmup;
           histogram->argunit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           range_down = analogsrange[roomid].voltage2_down;
           range_up = analogsrange[roomid].voltage2_up;
           alarm_down = analogsrange[roomid].voltage2_alarmdown;
           alarm_up = analogsrange[roomid].voltage2_alarmup;
            histogram->argunit = analogsrange[roomid].voltage2_unit;
       }
       HistogramItem item;

       item.initHistoGramItem(roomname,range_down,range_up,alarm_down,alarm_up);
       histogram->addItem(item);
      (histogram->argnames).push_back(argname);
       qDebug()<<controlname;
       qDebug()<<range_up;
       qDebug()<<range_down;
       qDebug()<<alarm_up;
       qDebug()<<alarm_down;
       effectargnum++;
       itemnum++;
    }
    histogram->histname = argname;
    file.close();
    histogram->maxRangeUp();
    histogram->minRangeDown();

    this->setMinimumWidth(histogram->YAXISOFFSET+histogram->RIGHTMARGIN+effectargnum*90);//80如何确定下来
    this->setMinimumHeight(300);
    this->resize(this->minimumWidth(),350);
   // onTimeChanged();
}

void HistoGramWidget::reloadargs()
{
    int effectargnum = 0;
    histogram->clearItem();
    histogram->argunit = "";
    histogram->histname = "";
    histogram->argnames.clear();
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
    int itemnum = 0;
    QString controlname;
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
           //controlname.append(str);
           roomname.append(str);
          // roomname.append("*");
       }

      // roomname.remove(roomname.size() - 1,1);
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
           itemnum++;
           continue;
       }

       float range_down = 0;
       float range_up  = 0;
       float alarm_down = 0;
       float alarm_up = 0;

       //温度报警

       if(argname == "温度")
       {
           range_down = analogsrange[roomid].temprature_down;
           range_up = analogsrange[roomid].temprature_up;
           alarm_down = analogsrange[roomid].temprature_alarmdown;
           alarm_up = analogsrange[roomid].temprature_alarmup;
           histogram->argunit = analogsrange[roomid].temprature_unit;

       }
       else if(argname == "湿度")
       {
           range_down = analogsrange[roomid].moisture_down;
           range_up = analogsrange[roomid].moisture_up;
           alarm_down = analogsrange[roomid].moisture_alarmdown;
           alarm_up = analogsrange[roomid].moisture_alarmup;
           histogram->argunit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           range_down = analogsrange[roomid].O2_down;
           range_up = analogsrange[roomid].O2_up;
           alarm_down = analogsrange[roomid].O2_alarmdown;
           alarm_up = analogsrange[roomid].O2_alarmup;
           histogram->argunit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           range_down = analogsrange[roomid].CO2_down;
           range_up = analogsrange[roomid].CO2_up;
           alarm_down = analogsrange[roomid].CO2_alarmdown;
           alarm_up = analogsrange[roomid].CO2_alarmup;
           histogram->argunit = analogsrange[roomid].CO2_unit;
            qDebug()<<"二氧化碳"<<range_down<<range_up<<alarm_down<<alarm_up;
       }
       else if(argname == "空气品质")
       {
           range_down = analogsrange[roomid].index_down;
           range_up = analogsrange[roomid].index_up;
           alarm_down = analogsrange[roomid].index_alarmdown;
           alarm_up = analogsrange[roomid].index_alarmup;
           //histogram->argunit;
       }
       else if(argname == "市电电压")
       {
           range_down = analogsrange[roomid].voltage1_down;
           range_up = analogsrange[roomid].voltage1_up;
           alarm_down = analogsrange[roomid].voltage1_alarmdown;
           alarm_up = analogsrange[roomid].voltage1_alarmup;
           histogram->argunit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           range_down = analogsrange[roomid].voltage2_down;
           range_up = analogsrange[roomid].voltage2_up;
           alarm_down = analogsrange[roomid].voltage2_alarmdown;
           alarm_up = analogsrange[roomid].voltage2_alarmup;
           histogram->argunit = analogsrange[roomid].voltage2_unit;
       }
       HistogramItem item;

       item.initHistoGramItem(roomname,range_down,range_up,alarm_down,alarm_up);
       histogram->addItem(item);
      (histogram->argnames).push_back(argname);
       qDebug()<<controlname;
       qDebug()<<range_up;
       qDebug()<<range_down;
       qDebug()<<alarm_up;
       qDebug()<<alarm_down;
       effectargnum++;
       itemnum++;

    }
    histogram->histname = argname;
    file.close();
    histogram->maxRangeUp();
    histogram->minRangeDown();
    this->setMinimumWidth(histogram->YAXISOFFSET+histogram->RIGHTMARGIN+effectargnum*90);//80如何确定下来
    this->setMinimumHeight(300);
    this->resize(this->minimumWidth(),350);
    qDebug()<<"HistoGramWidget reloadargs";
    update();

}

void HistoGramWidget::launch()
{
    updateTimer = new QTimer(this);
    /*connect(updateTimer, SIGNAL(timeout()), this, SLOT(onTimeChanged()));
    updateTimer->start(2000);*/
    connect(rec,SIGNAL(switchRefresh()),this,SLOT(onTimeChanged()));
    onTimeChanged();
}

void HistoGramWidget::initGram()
{

   // histname = QString(tr("空气品质"));
    histogram = new Histogram(this);
    histogram->setMaxValue( 64 );
    /*HistogramItem item1,item2,item3,item4,item5;
    item1.initHistoGramItem(tr("W303"),0.0,100.0);
    item2.initHistoGramItem(tr("E603"),0.0,100.0);
    item3.initHistoGramItem(tr("S125"),0.0,100.0);
    item4.initHistoGramItem(tr("N208"),0.0,100.0);
    item5.initHistoGramItem(tr("S412"),0.0,100.0);
    histogram->addItem(item1);
    histogram->addItem(item2);
    histogram->addItem(item3);
    histogram->addItem(item4);
    histogram->addItem(item5);*/
}

void HistoGramWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    pixmap = QPixmap(width(),height());
    pixmap.fill(this,0,0);
    histogram->paint(&pixmap);
    painter.drawPixmap(0,0,pixmap);
    Widget::paintEvent(event);
}

void HistoGramWidget::resizeEvent(QResizeEvent *event)
{
    Widget::resizeEvent(event);
}

void HistoGramWidget::onTimeChanged()
{
    for(int i = 0; i < histogram->histogramitems.size(); i++)
    {
        float currentvalue = 0;
        QString roomname = (histogram->roomnames)[i];
        QString argname = (histogram->argnames)[i];
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


        if(currentvalue > histogram->histogramitems.at(i).uplimit)
        {
            currentvalue = histogram->histogramitems.at(i).uplimit + abnormaldatashift;
        }
        else if(currentvalue < histogram->histogramitems.at(i).downlimit)
        {
            currentvalue = histogram->histogramitems.at(i).downlimit - abnormaldatashift;
        }
        (histogram->histogramitems)[i].setValue(currentvalue);
    }
    if(isVisible())
        update();
    else
    {
        qDebug()<<"Histogram invisible";
    }
}

Histogram::Histogram(QWidget *parent)
{
    maxrangeup = OFFLINEDATA;
    minrangedown = OFFLINEDATA;
    histogramitems.clear();
    roomnames.clear();
    argnames.clear();
}

void Histogram::addItem(HistogramItem item)
{
    histogramitems.push_back(item);
    roomnames.push_back(item.name);
}
void Histogram::clearItem()
{
    histogramitems.clear();
    roomnames.clear();
}

void Histogram::setMaxValue( float maxValue )
{
    m_MaxValue = maxValue;
}
void Histogram::maxRangeUp()
{
    if(histogramitems.size() > 0)
    {
        maxrangeup = histogramitems.at(0).uplimit;
        for(int i=1; i< histogramitems.size(); i++)
        {
            if(histogramitems.at(i).uplimit > maxrangeup)
                maxrangeup = histogramitems.at(i).uplimit;
        }
    }
}

void Histogram::minRangeDown()
{
    if(histogramitems.size() > 0)
    {
        minrangedown = histogramitems.at(0).downlimit;
        for(int i=1; i< histogramitems.size(); i++)
        {
            if(histogramitems.at(i).downlimit < minrangedown)
                minrangedown = histogramitems.at(i).downlimit;
        }
    }
}

void Histogram::paint( QPaintDevice* pDevice)
{
    if(histogramitems.size() == 0)
    {
        return;
    }
    QPainter painter(pDevice);
    painter.setBrush(Qt::lightGray);
    QPen temppen = painter.pen();
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,0,pDevice->width(),pDevice->height());
    painter.setPen(temppen);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
    drawAxis( pDevice, &painter );
    drawPillars( pDevice, &painter );
    drawText( &painter );
    drawScale( pDevice, &painter );
}

void Histogram::drawAxis( QPaintDevice* pDevice, QPainter* pPainter)
{
    //绘制条形图单位
    QRectF unitrect(YAXISOFFSET - 12,TOPMARGIN - 20,20,20);
    pPainter->drawText(unitrect,Qt::AlignHCenter|Qt::AlignVCenter,argunit);

    pPainter->drawLine( YAXISOFFSET, TOPMARGIN, YAXISOFFSET, pDevice->height()-XAXISOFFSET);//y轴
    pPainter->drawLine( YAXISOFFSET, pDevice->height() - XAXISOFFSET,//X轴
                        pDevice->width()-RIGHTMARGIN, pDevice->height() - XAXISOFFSET);
    QRectF histnamerect(pDevice->width()/4.0,TOPMARGIN/6.0,pDevice->width()/2.0,TOPMARGIN*2.0/3);


    QFont histnamefont,tempfont;
    tempfont = pPainter->font();
    histnamefont.setPixelSize(27);
    pPainter->setFont(histnamefont);
    pPainter->drawText(histnamerect,Qt::AlignHCenter|Qt::AlignVCenter,histname);
    pPainter->setFont(tempfont);
}

void Histogram::drawPillars( QPaintDevice* pDevice, QPainter* pPainter )
{
   // if ( histogramitems.size() == 0 ) return;


    qreal pillarWidth = ( pDevice->width( ) - YAXISOFFSET - PILLARINDENT-RIGHTMARGIN
                            - quint32( histogramitems.size( ) - 1 ) * BLANKWIDTH )
            / (qreal)histogramitems.size();


    //qreal heightFact = qreal( pDevice->height( ) - XAXISOFFSET - TOPMARGIN ) / (histogramitems[0].uplimit - histogramitems[0].downlimit);
    qreal heightFact = qreal( pDevice->height( ) - XAXISOFFSET - TOPMARGIN ) / (maxrangeup - minrangedown);

    for ( int i = 0; i < histogramitems.size(); ++i )
    {

        //if(histogramitems[i].value == histogramitems[i].downlimit) continue;
        qreal pillarHeight = (histogramitems[i].value -histogramitems[i].downlimit) * heightFact;
        qreal leftUpX = YAXISOFFSET + PILLARINDENT + i * ( pillarWidth + BLANKWIDTH );
        qreal leftUpY = pDevice->height( ) - XAXISOFFSET - pillarHeight;
        QRectF& rect = histogramitems[i].pillarRect;

        rect.setRect(leftUpX,leftUpY,pillarWidth,pillarHeight);

        /*pPainter->setPen( QPen( histogramitems[i].pillarColor) );
        pPainter->setBrush( QBrush( histogramitems[i].pillarColor));*/
        //保证没有离线
        if(!isOffline(roomnameToIds[roomnames.at(i)]) && roomIsCompleteConfigure(roomnameToIds[roomnames.at(i)]))
        {
            if(histogramitems[i].value >= histogramitems[i].downlimit - abnormaldatashift && histogramitems[i].value <= histogramitems[i].uplimit + abnormaldatashift)
            {
                if(histogramitems[i].value > histogramitems[i].alarm_uplimit)
                {
                   /*pPainter->setPen( QPen(datacolor[alarmupcolor]) );
                    pPainter->setBrush( QBrush( datacolor[alarmupcolor]));*/
                    pPainter->setPen( QPen(Qt::darkRed) );
                    pPainter->setBrush( QBrush( Qt::darkRed));

                }
                else if( histogramitems[i].value < histogramitems[i].alarm_downlimit)
                {
                    /*pPainter->setPen( QPen(datacolor[alarmdowncolor]) );
                    pPainter->setBrush( QBrush(datacolor[alarmdowncolor]));*/
                    pPainter->setPen( QPen(Qt::darkMagenta) );
                    pPainter->setBrush( QBrush(Qt::darkMagenta));
                }
                else if(histogramitems[i].value >= histogramitems[i].alarm_downlimit && histogramitems[i].value <= histogramitems[i].alarm_uplimit)
                {
                    /*pPainter->setPen( QPen(datacolor[normalcolor]) );
                    pPainter->setBrush( QBrush(datacolor[normalcolor]));*/
                    pPainter->setPen( QPen(Qt::darkGreen) );
                    pPainter->setBrush( QBrush(Qt::darkGreen));

                }
                pPainter->drawRect(rect);
            }
        }

        if(roomIsCompleteConfigure(roomnameToIds[roomnames.at(i)]))
        {
            pPainter->setPen(QPen(datacolor[alarmdowncolor]));
            pPainter->drawLine(YAXISOFFSET + PILLARINDENT/2 + (pillarWidth+BLANKWIDTH)*i,heightFact*(histogramitems[i].uplimit - histogramitems[i].alarm_downlimit)+TOPMARGIN,YAXISOFFSET + PILLARINDENT/2 + (pillarWidth+BLANKWIDTH)*(i+1),heightFact*(histogramitems[0].uplimit - histogramitems[0].alarm_downlimit)+TOPMARGIN);
            pPainter->setPen(QPen(datacolor[alarmupcolor]));
            pPainter->drawLine(YAXISOFFSET + PILLARINDENT/2 + (pillarWidth+BLANKWIDTH)*i,heightFact*(histogramitems[i].uplimit - histogramitems[i].alarm_uplimit)+TOPMARGIN,YAXISOFFSET + PILLARINDENT/2 + (pillarWidth+BLANKWIDTH)*(i+1),heightFact*(histogramitems[0].uplimit - histogramitems[0].alarm_uplimit)+TOPMARGIN);
        }


    }
    //绘制报警上下限
    /*pPainter->setPen(QPen(datacolor[alarmdowncolor]));
    pPainter->drawLine(YAXISOFFSET,heightFact*(histogramitems[0].uplimit - histogramitems[0].alarm_downlimit)+TOPMARGIN,pDevice->width()-RIGHTMARGIN,heightFact*(histogramitems[0].uplimit - histogramitems[0].alarm_downlimit)+TOPMARGIN);
    pPainter->setPen(QPen(datacolor[alarmupcolor]));
    pPainter->drawLine(YAXISOFFSET,heightFact*(histogramitems[0].uplimit - histogramitems[0].alarm_uplimit)+TOPMARGIN,pDevice->width()-RIGHTMARGIN,heightFact*(histogramitems[0].uplimit - histogramitems[0].alarm_uplimit)+TOPMARGIN);*/
}

void Histogram::drawText( QPainter* pPainter )
{
    for ( int i = 0; i < histogramitems.size(); ++i )
    {
        pPainter->setPen(QPen(Qt::black));
        pPainter->setBrush(QBrush(Qt::black));

        QRectF valuerect( histogramitems[i].pillarRect.left( ),
                    histogramitems[i].pillarRect.top( ) - TEXTRECTHEIGHT,
                    histogramitems[i].pillarRect.width( ),
                    TEXTRECTHEIGHT );
        /*if(i % 2 == 0)
        {
            QRectF namerect(histogramitems[i].pillarRect.left()-histogramitems[i].pillarRect.width()/2.0,histogramitems[i].pillarRect.bottom()+XAXISOFFSET/5.0,
                            histogramitems[i].pillarRect.width()*2,1.0/3*XAXISOFFSET);
            pPainter->drawText(namerect,Qt::AlignHCenter|Qt::AlignVCenter,histogramitems[i].name);
        }
        else
        {
            QRectF namerect(histogramitems[i].pillarRect.left()-histogramitems[i].pillarRect.width()/2.0,histogramitems[i].pillarRect.bottom()+XAXISOFFSET/2.0,
                            histogramitems[i].pillarRect.width()*2,1.0/3*XAXISOFFSET);
            pPainter->drawText(namerect,Qt::AlignHCenter|Qt::AlignVCenter,histogramitems[i].name);
        }*/

        QRectF namerect(histogramitems[i].pillarRect.left()-histogramitems[i].pillarRect.width()/2.0,histogramitems[i].pillarRect.bottom()+XAXISOFFSET/5.0,
                        histogramitems[i].pillarRect.width()*2,2.0/3*XAXISOFFSET);
        QString namestr = histogramitems[i].name;
        namestr.insert(namestr.lastIndexOf("楼") - 1,"\n");
        pPainter->drawText(namerect,Qt::AlignHCenter|Qt::AlignVCenter,namestr);

        const QString& text = QString( "%1" )
                .arg( histogramitems[i].value );
        if(!isOffline(roomnameToIds[roomnames.at(i)]) && roomIsCompleteConfigure(roomnameToIds[roomnames.at(i)]))
        {
            if(histogramitems[i].value >= histogramitems[i].downlimit && histogramitems[i].value <= histogramitems[i].uplimit)
            {
                if(histogramitems[i].value > histogramitems[i].alarm_uplimit)
                {
                    /*pPainter->setPen( QPen(datacolor[alarmupcolor]) );
                    pPainter->setBrush( QBrush( datacolor[alarmupcolor]));*/
                    pPainter->setPen( QPen(Qt::darkRed) );
                    pPainter->setBrush( QBrush( Qt::darkRed));


                }
                else if(histogramitems[i].value < histogramitems[i].alarm_downlimit)
                {
                   /* pPainter->setPen( QPen(datacolor[alarmdowncolor]) );
                    pPainter->setBrush( QBrush(datacolor[alarmdowncolor]));*/
                    pPainter->setPen( QPen(Qt::darkMagenta) );
                    pPainter->setBrush( QBrush(Qt::darkMagenta));
                }
                else if(histogramitems[i].value >= histogramitems[i].alarm_downlimit && histogramitems[i].value <= histogramitems[i].alarm_uplimit)
                {
                    /*pPainter->setPen( QPen(datacolor[normalcolor]) );
                    pPainter->setBrush( QBrush(datacolor[normalcolor]));*/
                    pPainter->setPen( QPen(Qt::darkGreen) );
                    pPainter->setBrush( QBrush(Qt::darkGreen));

                }
                if(histogramitems[i].value >= histogramitems.at(i).downlimit && histogramitems[i].value <= histogramitems.at(i).uplimit)
                    pPainter->drawText(valuerect, Qt::AlignCenter,text);
                else
                    pPainter->drawText(valuerect, Qt::AlignCenter,"error");
            }
            else
            {

            }
        }
    }
}

void Histogram::drawScale( QPaintDevice *pDevice, QPainter *pPainter )
{
    qreal MSHeight = TEXTRECTHEIGHT;
    qreal heightInterval =(pDevice->height()-XAXISOFFSET-TOPMARGIN) / 10.0;

    pPainter->setPen(QPen(Qt::black));
    pPainter->setBrush( QBrush(Qt::black));
    for ( int i = 0; i <= 10; ++i )
    {
        pPainter->drawLine( YAXISOFFSET*9.0/10,
                            i * heightInterval+TOPMARGIN,
                            YAXISOFFSET ,
                            i * heightInterval+TOPMARGIN);
        QRectF scaletextrect(YAXISOFFSET/5.0,i * heightInterval + TOPMARGIN-5,YAXISOFFSET*3/5.0,MSHeight);
        pPainter->drawText(
                    scaletextrect, Qt::AlignRight, QString
                    ::number((double)((maxrangeup -minrangedown) * ( 10 - i ) / 10.0 ) + minrangedown,'f',1 ));
    }
}
void HistogramItem::initHistoGramItem(QString name,float downlimit,float uplimit, float alarm_downlimit_arg, float alarm_uplimit_arg)
{
    this->name = name;
    this->downlimit = downlimit;
    this->uplimit = uplimit;
    this->alarm_downlimit = alarm_downlimit_arg;
    this->alarm_uplimit = alarm_uplimit_arg;
    this->value = OFFLINEDATA;
    this->pillarColor = Qt::black;
    this->pillarRect = QRect();
}

void HistogramItem::setValue(float currentvalue)
{
    this->value = currentvalue;
}
void HistogramItem::setRange(float down,float up)
{
    this->downlimit = down;
    this->uplimit = up;
}

void HistoGramWidget::closeMySelf()
{
    qDebug()<<"关闭我自己";
    emit delMySelf(this->windowTitle());
    this->close();
}

void HistoGramWidget::setControlState(int type)
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
