#include <QVBoxLayout>
#include <QDebug>
#include <QTimer>
#include <QToolButton>
#include <QMessageBox>
#include <QFile>
#include <QPainter>
#include "prametertablewidget.h"
#include "ui_prametertablewidget.h"
#include "parametertable.h"
#include "struct.h"
#include "receiver.h"
#include "treecombobox.h"
PrameterTableWidget::PrameterTableWidget(QWidget *parent) :
    Widget(parent),
    ui(new Ui::PrameterTableWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    paratable = new ParameterTable(this);
    tablelayout = new QVBoxLayout;
    tablelayout->addWidget(paratable);
    ui->widget->setLayout(tablelayout);

    QAction * del_action = new QAction("删除",this);
    connect(del_action,SIGNAL(triggered()),this,SLOT(closeMySelf()));
    addAction(del_action);
   // setContextMenuPolicy(Qt::ActionsContextMenu);
   /*connect(ui->del_pushutton,SIGNAL(clicked()),this,SLOT(onDelPushButton()));
    connect(ui->add_pushbutton,SIGNAL(clicked()),this,SLOT(onAddPushButton()));
    connect(ui->edit_pushbutton,SIGNAL(clicked()),this,SLOT(onEditPushButton()));
    connect(ui->save_pushbutton,SIGNAL(clicked()),this,SLOT(onSavePushButton()));*/

    ui->del_pushutton->setHidden(true);
    ui->add_pushbutton->setHidden(true);
    ui->edit_pushbutton->setHidden(true);
    ui->save_pushbutton->setHidden(true);
    this->setAttribute(Qt::WA_TranslucentBackground,false);

}

PrameterTableWidget::~PrameterTableWidget()
{
    delete ui;
}

void PrameterTableWidget::loadArgs(QString filename)
{

    if(filename.isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("该控件不存在！"),tr("确定"));
        return;
    }
    //histname = filename;
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
       QString unitstr = "";
       //温度报警
       if(argname == "温度")
       {
           range_down = analogsrange[roomid].temprature_down;
           range_up = analogsrange[roomid].temprature_up;
           alarm_down = analogsrange[roomid].temprature_alarmdown;
           alarm_up = analogsrange[roomid].temprature_alarmup;
           unitstr = analogsrange[roomid].temprature_unit;
       }
       else if(argname == "湿度")
       {
           range_down = analogsrange[roomid].moisture_down;
           range_up = analogsrange[roomid].moisture_up;
           alarm_down = analogsrange[roomid].moisture_alarmdown;
           alarm_up = analogsrange[roomid].moisture_alarmup;
           unitstr = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           range_down = analogsrange[roomid].O2_down;
           range_up = analogsrange[roomid].O2_up;
           alarm_down = analogsrange[roomid].O2_alarmdown;
           alarm_up = analogsrange[roomid].O2_alarmup;
           unitstr = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           range_down = analogsrange[roomid].CO2_down;
           range_up = analogsrange[roomid].CO2_up;
           alarm_down = analogsrange[roomid].CO2_alarmdown;
           alarm_up = analogsrange[roomid].CO2_alarmup;
           unitstr = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "空气品质")
       {
           range_down = analogsrange[roomid].index_down;
           range_up = analogsrange[roomid].index_up;
           alarm_down = analogsrange[roomid].index_alarmdown;
           alarm_up = analogsrange[roomid].index_alarmup;
           unitstr = analogsrange[roomid].index_unit;

       }
       else if(argname == "市电电压")
       {
           range_down = analogsrange[roomid].voltage1_down;
           range_up = analogsrange[roomid].voltage1_up;
           alarm_down = analogsrange[roomid].voltage1_alarmdown;
           alarm_up = analogsrange[roomid].voltage1_alarmup;
           unitstr = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           range_down = analogsrange[roomid].voltage2_down;
           range_up = analogsrange[roomid].voltage2_up;
           alarm_down = analogsrange[roomid].voltage2_alarmdown;
           alarm_up = analogsrange[roomid].voltage2_alarmup;
           unitstr = analogsrange[roomid].voltage2_unit;
       }
       else if(argname == "漏水")
       {
           range_down = 0.0;
           range_up = 0.0;
           alarm_down = 0.0;
           alarm_up = 0.0;
           unitstr = "";
       }
       else if(argname == "烟雾")
       {
           range_down = 0.0;
           range_up = 0.0;
           alarm_down = 0.0;
           alarm_up = 0.0;
           unitstr = "";
       }
       qDebug()<<"canshubiaojiazaicansh";
       int row = paratable->rowCount();
       paratable->insertRow(row);
       qDebug()<<"canshubiaojiazaicansh";
       QTableWidgetItem * item = new QTableWidgetItem(roomname+"*"+argname);
       paratable->setItem(paratable->rowCount()-1 ,0,item);
       item->setTextAlignment(Qt::AlignCenter);

       item = new QTableWidgetItem("");
       paratable->setItem(paratable->rowCount()-1,1,item);
       item->setTextAlignment(Qt::AlignCenter);

       item = new QTableWidgetItem(unitstr);
       paratable->setItem(paratable->rowCount()-1,2,item);
       item->setTextAlignment(Qt::AlignCenter);
       if(argname!="烟雾" && argname !="漏水")
           item = new QTableWidgetItem(QString::number(range_down,'f',1)+"-"+QString::number(range_up,'f',1));
       else
           item = new QTableWidgetItem("");

       paratable->setItem(paratable->rowCount()-1,3,item);
       item->setTextAlignment(Qt::AlignCenter);
       if(argname!="烟雾" && argname !="漏水")
           item = new QTableWidgetItem(QString::number(alarm_down,'f',1)+"-"+QString::number(alarm_up,'f',1));
       else
           item = new QTableWidgetItem("");
       paratable->setItem(paratable->rowCount()-1,4,item);
       item->setTextAlignment(Qt::AlignCenter);
       qDebug()<<"canshubiaojiazaicansh";
       qDebug()<<roomname;
       qDebug()<<range_up;
       qDebug()<<range_down;
       qDebug()<<alarm_up;
       qDebug()<<alarm_down;
       itemnum++;
    }
    file.close();
    this->setMinimumWidth(650);
    this->setMinimumHeight(paratable->verticalHeader()->defaultSectionSize()*itemnum+92);
    this->resize(this->minimumWidth(),this->minimumHeight());
}
void PrameterTableWidget::reloadArgs()
{
     int effectargnum = 0;
    paratable->clear();
    QStringList horizontitles;
    horizontitles<<"名称"<<"值"<<"单位"<<"量程"<<"报警上下限";//备注中放正常值范围
    paratable->setHorizontalHeaderLabels(horizontitles);
    QString path = "controls/";
    QFile file(path+filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        file.close();
        return;
    }
    QTextStream in(&file);
    QString controlstr;

    int count = 0 ;
        count = in.readLine().toInt();
    int itemnum = 0;
    QString roomname;
    QString argname;
    //int row = 0;
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

       QString unitstr = "";
       //温度报警
       if(argname == "温度")
       {
           range_down = analogsrange[roomid].temprature_down;
           range_up = analogsrange[roomid].temprature_up;
           alarm_down = analogsrange[roomid].temprature_alarmdown;
           alarm_up = analogsrange[roomid].temprature_alarmup;
           unitstr = analogsrange[roomid].temprature_unit;
       }
       else if(argname == "湿度")
       {
           range_down = analogsrange[roomid].moisture_down;
           range_up = analogsrange[roomid].moisture_up;
           alarm_down = analogsrange[roomid].moisture_alarmdown;
           alarm_up = analogsrange[roomid].moisture_alarmup;
           unitstr = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "氧气")
       {
           range_down = analogsrange[roomid].O2_down;
           range_up = analogsrange[roomid].O2_up;
           alarm_down = analogsrange[roomid].O2_alarmdown;
           alarm_up = analogsrange[roomid].O2_alarmup;
           unitstr = analogsrange[roomid].O2_unit;
       }
       else if(argname == "二氧化碳")
       {
           range_down = analogsrange[roomid].CO2_down;
           range_up = analogsrange[roomid].CO2_up;
           alarm_down = analogsrange[roomid].CO2_alarmdown;
           alarm_up = analogsrange[roomid].CO2_alarmup;
           unitstr = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "空气品质")
       {
           range_down = analogsrange[roomid].index_down;
           range_up = analogsrange[roomid].index_up;
           alarm_down = analogsrange[roomid].index_alarmdown;
           alarm_up = analogsrange[roomid].index_alarmup;
           unitstr = analogsrange[roomid].index_unit;
       }
       else if(argname == "市电电压")
       {
           range_down = analogsrange[roomid].voltage1_down;
           range_up = analogsrange[roomid].voltage1_up;
           alarm_down = analogsrange[roomid].voltage1_alarmdown;
           alarm_up = analogsrange[roomid].voltage1_alarmup;
           unitstr = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "零电压差")
       {
           range_down = analogsrange[roomid].voltage2_down;
           range_up = analogsrange[roomid].voltage2_up;
           alarm_down = analogsrange[roomid].voltage2_alarmdown;
           alarm_up = analogsrange[roomid].voltage2_alarmup;
           unitstr = analogsrange[roomid].voltage2_unit;
       }
       else if(argname == "漏水")
       {
           range_down = 0.0;
           range_up = 0.0;
           alarm_down = 0.0;
           alarm_up = 0.0;
           unitstr = "";
       }
       else if(argname == "烟雾")
       {
           range_down = 0.0;
           range_up = 0.0;
           alarm_down = 0.0;
           alarm_up = 0.0;
           unitstr = "";
       }
       qDebug()<<"canshubiaojiazaicansh";
       //int row = paratable->rowCount();
      // paratable->insertRow(row);
       qDebug()<<"canshubiaojiazaicansh";
       QTableWidgetItem * item = new QTableWidgetItem(roomname+"*"+argname);
       paratable->setItem(effectargnum ,0,item);
       item->setTextAlignment(Qt::AlignCenter);

       item = new QTableWidgetItem("");
       paratable->setItem(effectargnum,1,item);
       item->setTextAlignment(Qt::AlignCenter);

       item = new QTableWidgetItem(unitstr);
       paratable->setItem(effectargnum,2,item);
       item->setTextAlignment(Qt::AlignCenter);

       if(argname!="烟雾" && argname !="漏水")
           item = new QTableWidgetItem(QString::number(range_down,'f',1)+"-"+QString::number(range_up,'f',1));
       else
           item = new QTableWidgetItem("");
       paratable->setItem(effectargnum,3,item);
       item->setTextAlignment(Qt::AlignCenter);

       if(argname!="烟雾" && argname !="漏水")
           item = new QTableWidgetItem(QString::number(alarm_down,'f',1)+"-"+QString::number(alarm_up,'f',1));
       else
           item = new QTableWidgetItem("");
       paratable->setItem(effectargnum,4,item);
       item->setTextAlignment(Qt::AlignCenter);
       qDebug()<<"canshubiaojiazaicansh";
       qDebug()<<roomname;
       qDebug()<<range_up;
       qDebug()<<range_down;
       qDebug()<<alarm_up;
       qDebug()<<alarm_down;
       effectargnum++;
       itemnum++;
    }
    file.close();

}

void PrameterTableWidget::launch()
{
    refreshtime = new QTimer(this);
    /*connect(refreshtime,SIGNAL(timeout()),this,SLOT(updateTimeDone()));
    refreshtime->start(2000);*/
    connect(rec,SIGNAL(switchRefresh()),this,SLOT(updateTimeDone()));
    updateTimeDone();
}

void PrameterTableWidget::onDelPushButton()
{
    qDebug()<<"shanchu";
    qDebug()<<"paratable count"<<paratable->rowcount;
    //if(paratable->rowcount > 0)
    if(paratable->currentRow() >= 0)
    {
        qDebug()<<"currentRowbefore"<<paratable->currentRow();
        paratable->removeRow(paratable->currentRow());
        //--(paratable->rowcount);
         qDebug()<<"currentRowafter"<<paratable->currentRow();
    }
}

void PrameterTableWidget::onAddPushButton()
{
    qDebug()<<"beforadd curret row:"<<paratable->currentRow();
    if(paratable->currentRow() >= 0)
    {
        paratable->insertRow(paratable->currentRow()+1);
        QTableWidgetItem * item = new QTableWidgetItem;
        paratable->setItem(paratable->currentRow()+1,0,item);
        item = new QTableWidgetItem(tr(""));
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        paratable->setItem(paratable->currentRow()+1,1,item);
        item = new QTableWidgetItem(tr(""));
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        paratable->setItem(paratable->currentRow()+1,2,item);
        item = new QTableWidgetItem(tr(""));
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        paratable->setItem(paratable->currentRow()+1,3,item);
    }
    else
    {
        paratable->insertRow(paratable->rowCount());
        QTableWidgetItem * item = new QTableWidgetItem;
        paratable->setItem(paratable->rowCount()-1,0,item);
        item = new QTableWidgetItem(tr(""));
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        paratable->setItem(paratable->rowCount()-1,1,item);
        item = new QTableWidgetItem(tr(""));
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        paratable->setItem(paratable->rowCount()-1,2,item);
        item = new QTableWidgetItem(tr(""));
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        paratable->setItem(paratable->rowCount()-1,3,item);
    }
    qDebug()<<"afteradd curret row:"<<paratable->currentRow();
    //++(paratable->rowcount);
     //paratable->setCurrentCell(paratable->rowcount,0);
    paratable->setCurrentCell(paratable->rowCount(),0);
    qDebug()<<"row:"<<paratable->currentRow();

}

void PrameterTableWidget::onEditPushButton()
{
    int row = paratable->currentRow();
    paratable->editItem(paratable->item(row,0));
}

void PrameterTableWidget::onSavePushButton()
{
    qDebug()<<tr("保存");

}

void PrameterTableWidget::updateTimeDone()
{
  //  qDebug()<<tr("参数表定时器");
    QColor color;
    for(int i = 0; i < paratable->rowCount(); i++)
    {
        float curval = 0.0;
        QStringList  roomnameandargname = paratable->item(i,0)->text().split("*");
        int roomid = roomnameToIds[roomnameandargname.first()];
        QString argname = roomnameandargname.last();
        if(argname == "温度")
        {
            curval = analog[roomid].temprature;
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(curval > analogsrange[roomid].temprature_alarmup)
                {
                    //color = datacolor[alarmupcolor];
                    color = Qt::darkRed;
                }
                else if(curval < analogsrange[roomid].temprature_alarmdown)
                {
                   // color = datacolor[alarmdowncolor];
                    color = Qt::darkMagenta;
                }
                else
                {
                    //color = datacolor[normalcolor];
                    color = Qt::darkGreen;
                }
                paratable->item(i,1)->setTextColor(color);
                if(curval >= analogsrange[roomid].temprature_down && curval <= analogsrange[roomid].temprature_up)
                    paratable->item(i,1)->setText(QString::number(curval,'f',1));
                else
                    paratable->item(i,1)->setText("error");
            }
            else
            {
                paratable->item(i,1)->setTextColor(Qt::black);
                paratable->item(i,1)->setText("");
            }
        }
        else if(argname == "湿度")
        {
            curval = analog[roomid].moisture;
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(curval > analogsrange[roomid].moisture_alarmup)
                {
                    //color = datacolor[alarmupcolor];
                    color = Qt::darkRed;
                }
                else if(curval < analogsrange[roomid].moisture_alarmdown)
                {
                    // color = datacolor[alarmdowncolor];
                     color = Qt::darkMagenta;
                }
                else
                {
                    //color = datacolor[normalcolor];
                    color = Qt::darkGreen;
                }
                paratable->item(i,1)->setTextColor(color);
                if(curval >= analogsrange[roomid].moisture_down && curval <= analogsrange[roomid].moisture_up)
                    paratable->item(i,1)->setText(QString::number(curval,'f',1));
                else
                    paratable->item(i,1)->setText("error");
            }
            else
            {
                paratable->item(i,1)->setTextColor(Qt::black);
                paratable->item(i,1)->setText("");
            }
        }
        else if(argname == "氧气")
        {
            curval = analog[roomid].O2;
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(curval > analogsrange[roomid].O2_alarmup)
                {
                    //color = datacolor[alarmupcolor];
                    color = Qt::darkRed;
                }
                else if(curval < analogsrange[roomid].O2_alarmdown)
                {
                    // color = datacolor[alarmdowncolor];
                     color = Qt::darkMagenta;
                }
                else
                {
                    //color = datacolor[normalcolor];
                    color = Qt::darkGreen;
                }
                paratable->item(i,1)->setTextColor(color);
                if(curval >= analogsrange[roomid].O2_down && curval <= analogsrange[roomid].O2_up)
                    paratable->item(i,1)->setText(QString::number(curval,'f',1));
                else
                    paratable->item(i,1)->setText("error");
            }
            else
            {
                paratable->item(i,1)->setTextColor(Qt::black);
                paratable->item(i,1)->setText("");
            }
        }
        else if(argname == "二氧化碳")
        {
             curval = analog[roomid].CO2;
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
             {
                 if(curval > analogsrange[roomid].CO2_alarmup)
                 {
                     //color = datacolor[alarmupcolor];
                     color = Qt::darkRed;
                 }
                 else if(curval < analogsrange[roomid].CO2_alarmdown)
                 {
                     // color = datacolor[alarmdowncolor];
                      color = Qt::darkMagenta;
                 }
                 else
                 {
                     //color = datacolor[normalcolor];
                     color = Qt::darkGreen;
                 }
                 paratable->item(i,1)->setTextColor(color);
                 if(curval >= analogsrange[roomid].CO2_down && curval <= analogsrange[roomid].CO2_up)
                     paratable->item(i,1)->setText(QString::number(curval,'f',1));
                 else
                     paratable->item(i,1)->setText("error");
             }
             else
             {
                 paratable->item(i,1)->setTextColor(Qt::black);
                 paratable->item(i,1)->setText("");
             }
        }
        else if(argname == "空气品质")
        {
             curval = analog[roomid].index;
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
             {
                 if(curval > analogsrange[roomid].index_alarmup)
                 {
                     //color = datacolor[alarmupcolor];
                     color = Qt::darkRed;
                 }
                 else if(curval < analogsrange[roomid].index_alarmdown)
                 {
                     // color = datacolor[alarmdowncolor];
                      color = Qt::darkMagenta;
                 }
                 else
                 {
                     //color = datacolor[normalcolor];
                     color = Qt::darkGreen;
                 }
                 paratable->item(i,1)->setTextColor(color);
                 if(curval >= analogsrange[roomid].index_down && curval <= analogsrange[roomid].index_up)
                     paratable->item(i,1)->setText(QString::number(curval,'f',1));
                 else
                     paratable->item(i,1)->setText("error");
             }
             else
             {
                 paratable->item(i,1)->setTextColor(Qt::black);
                 paratable->item(i,1)->setText("");
             }
        }
        else if(argname == "市电电压")
        {
             curval = analog[roomid].voltage1;
             if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
             {
                 if(curval > analogsrange[roomid].voltage1_alarmup)
                 {
                     //color = datacolor[alarmupcolor];
                     color = Qt::darkRed;
                 }
                 else if(curval < analogsrange[roomid].voltage1_alarmdown)
                 {
                     // color = datacolor[alarmdowncolor];
                      color = Qt::darkMagenta;
                 }
                 else
                 {
                     //color = datacolor[normalcolor];
                     color = Qt::darkGreen;
                 }
                 paratable->item(i,1)->setTextColor(color);
                 if(curval >= analogsrange[roomid].voltage1_down && curval <= analogsrange[roomid].voltage1_up)
                     paratable->item(i,1)->setText(QString::number(curval,'f',1));
                 else
                     paratable->item(i,1)->setText("error");
             }
             else
             {
                 paratable->item(i,1)->setTextColor(Qt::black);
                 paratable->item(i,1)->setText("");
             }
        }
        else if(argname == "零电压差")
        {
            curval = analog[roomid].voltage2;
            if(!isOffline(roomid)&&roomIsCompleteConfigure(roomid))
            {
                if(curval > analogsrange[roomid].voltage2_alarmup)
                {
                    //color = datacolor[alarmupcolor];
                    color = Qt::darkRed;
                }
                else if(curval < analogsrange[roomid].voltage2_alarmdown)
                {
                    // color = datacolor[alarmdowncolor];
                     color = Qt::darkMagenta;
                }
                else
                {
                    //color = datacolor[normalcolor];
                    color = Qt::darkGreen;
                }
                paratable->item(i,1)->setTextColor(color);
                 if(curval >= analogsrange[roomid].voltage2_down && curval <= analogsrange[roomid].voltage2_up)
                     paratable->item(i,1)->setText(QString::number(curval,'f',1));
                 else
                     paratable->item(i,1)->setText("error");
            }
            else
            {
                paratable->item(i,1)->setTextColor(Qt::black);
                paratable->item(i,1)->setText("");
            }
        }
        else if(argname == "漏水" ||argname == "烟雾")
        {
           if(isOffline(roomid) || !roomIsCompleteConfigure(roomid))
           {
                paratable->item(i,1)->setTextColor(Qt::black);
                paratable->item(i,1)->setText("");
           }
           else
           {
               if(argname == "漏水")
               {
                   if(swi[roomid].waterCurrent)//1表示正常还是异常
                   {
                       //paratable->item(i,1)->setTextColor(Qt::red);
                       paratable->item(i,1)->setTextColor(Qt::darkRed);
                       paratable->item(i,1)->setText("异常");
                   }
                   else
                   {
                       //paratable->item(i,1)->setTextColor(Qt::green);
                       paratable->item(i,1)->setTextColor(Qt::darkGreen);
                       paratable->item(i,1)->setText("正常");
                   }
               }
               else if(argname == "烟雾")
               {
                   if(swi[roomid].smokeCurrent)//1表示正常还是异常
                   {
                       //paratable->item(i,1)->setTextColor(Qt::red);
                       paratable->item(i,1)->setTextColor(Qt::darkRed);
                       paratable->item(i,1)->setText("异常");
                   }
                   else
                   {
                       //paratable->item(i,1)->setTextColor(Qt::green);
                       paratable->item(i,1)->setTextColor(Qt::darkGreen);
                       paratable->item(i,1)->setText("正常");
                   }
               }
           }
        }
    }

}

void PrameterTableWidget::resizeEvent (QResizeEvent *  event)
{

    qDebug()<<"resize";
     Widget::resizeEvent(event);

}

void PrameterTableWidget::closeMySelf()
{
    qDebug()<<"关闭我自己";
    emit delMySelf(this->windowTitle());
    this->close();
}

void PrameterTableWidget::setControlState(int type)
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
 void PrameterTableWidget::paintEvent(QPaintEvent *event)
 {
     QPainter painter(this);
     painter.setBrush(Qt::lightGray);
     painter.setPen(Qt::NoPen);
     painter.drawRect(0,0,width(),height());
     Widget::paintEvent(event);
 }
