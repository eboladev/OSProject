#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QButtonGroup>
#include <QDebug>
#include <QMessageBox>

#include "historydataform.h"
#include "ui_historydataform.h"
#include "treecombobox.h"
#include "struct.h"

HistoryDataForm::HistoryDataForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryDataForm)
{

    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    this->setWindowTitle("历史数据");
     this->setWindowIcon(QIcon("images/historydataform_icon.png"));
    paranum = 3;
    titlerow = 3;
    rownum = 0;
    currentcol = -1;
    colnum = 2*paranum;

    oldstartdatetime = QDateTime::fromString("2013-8-30 00:00","yyyy-MM-dd hh:mm");
    oldenddatetime = QDateTime::fromString("2013-8-30 00:00","yyyy-MM-dd hh:mm");
    oldargs.clear();

    tablewidget = new QTableWidget(titlerow,colnum,this);
    tablewidget->setRowHeight(1,40);
    for(int i = 0; i < colnum; i++)
    {
        if(i%2 == 0)
            tablewidget->setColumnWidth(i,130);
        else
            tablewidget->setColumnWidth(i,60);
    }
    tablewidget->horizontalHeader()->hide();
    tablewidget->verticalHeader()->hide();


    for(int i = 0; i < paranum; i++)
    {
        QTableWidgetItem * item;

        tablewidget->setSpan(0,i*2,1,2);
        item = new QTableWidgetItem(tr("双击此处选择参数"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(0,i*2,item);

        tablewidget->setSpan(1,i*2,1,2);
        item = new QTableWidgetItem(tr("参数属性"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(1,i*2,item);

        item = new QTableWidgetItem(tr("时间"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(2,i*2,item);
        item = new QTableWidgetItem(tr("值"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(2,i*2+1,item);
    }

    vboxlayout = new QVBoxLayout();//可能重复添加布局
    vboxlayout->addWidget(tablewidget);
    ui->widget->setLayout(vboxlayout);

   // this->setMinimumSize(600,400);
   // connect(ui->start_dateedit,SIGNAL(dateChanged(QDate)),this,SLOT(onStartDateEditChanged(QDate)));
    //connect(ui->end_dateedit,SIGNAL(dateChanged(QDate)),this,SLOT(onEndDateEditChanged(QDate)));
    //connect(ui->start_timeedit,SIGNAL(timeChanged(QTime)),this,SLOT(onStartTimeEditChanged(QTime)));
    //connect(ui->end_timeedit,SIGNAL(timeChanged(QTime)),this,SLOT(onEndTimeEditChanged(QTime)));
    //connect(ui->end_timeedit,SIGNAL(timeChanged(QTime)),this,SLOT(onEndTimeEditChanged(QTime)));


    connect(tablewidget,SIGNAL(cellClicked(int,int)),SLOT(onTableWidgetCellChanged(int,int)));
    //connect(tablewidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(onTableWidgetItemChanged(QTableWidgetItem*)));
    //connect(tablewidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(onTableWidgetItemChanged(QTableWidgetItem*)));
    connect(tablewidget->model(),SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(onDataChanged(QModelIndex,QModelIndex)));

    connect(ui->addcol_pushbutton,SIGNAL(clicked()),this,SLOT(onAddColumnPushButton()));
    connect(ui->delcol_pushbutton,SIGNAL(clicked()),this,SLOT(onDelColumnPushButton()));
    connect(ui->search_pushbutton,SIGNAL(clicked()),this,SLOT(onSearchPushButton()));
    this->resize(590,600);
    //globaldb.open();
    QDateTime curdatetime = QDateTime::currentDateTime();
    ui->start_dateedit->setMinimumDate(curdatetime.date().addYears(-2).addDays(1));
    ui->end_dateedit->setMinimumDate(curdatetime.date().addYears(-2).addDays(1));

    tablewidget->setAlternatingRowColors(true);
    tablewidget->setStyleSheet("QTableWidget{alternate-background-color: lightgray;background:white;selection-background-color: gray;}");
}

HistoryDataForm::~HistoryDataForm()
{
    delete ui;
}



/*void HistoryDataForm::onStartDateEditChanged(const QDate & date)
{
    qDebug()<<"startdatechange";
    int day = ui->start_dateedit->date().daysTo(ui->end_dateedit->date());
    qDebug()<<"daydistance"<<day;
    if(day < 0)
    {
        if(firstshowmessge)
        {
           QMessageBox::warning(0,tr("警告"),tr("起始日期大于终止日期！"),tr("确定"));
           firstshowmessge = false;
        }
        ui->start_dateedit->setDate(oldstartdate);
        if(!firstshowmessge)
            firstshowmessge = true;


        return ;
    }
    else
    {
        oldstartdate = ui->start_dateedit->date();
    }
}

void HistoryDataForm::onEndDateEditChanged(const QDate & date)
{
    qDebug()<<"enddatechange";
    int day = ui->start_dateedit->date().daysTo(ui->end_dateedit->date());
    if(day < 0)
    {
        QMessageBox::warning(0,tr("警告"),tr("起始日期大于终止日期！"),tr("确定"));
        ui->end_dateedit->setDate(oldenddate);
        return ;
    }
    else
    {
        oldenddate = ui->end_dateedit->date();
    }
}

void HistoryDataForm::onStartTimeEditChanged (const QTime & time)
{
    qDebug()<<"starttimechange";
    int day = ui->start_dateedit->date().daysTo(ui->end_dateedit->date());
    int premins = QTime(0,0,0).secsTo(ui->start_timeedit->time())/60;
    int aftmins = QTime(0,0,0).secsTo(ui->end_timeedit->time())/60;
    int mininterval = day*24*60 - premins + aftmins;
    if(mininterval < 0)
    {
        QMessageBox::warning(0,tr("警告"),tr("起始时间大于终止时间！"),tr("确定"));
        ui->start_timeedit->setTime(oldstarttime);
        return ;
    }
    else
    {
        oldstarttime = ui->start_timeedit->time();
    }
}

void HistoryDataForm::onEndTimeEditChanged (const QTime & time)
{
    int day = ui->start_dateedit->date().daysTo(ui->end_dateedit->date());
    int premins = QTime(0,0,0).secsTo(ui->start_timeedit->time())/60;
    int aftmins = QTime(0,0,0).secsTo(ui->end_timeedit->time())/60;
    int mininterval = day*24*60 - premins + aftmins;
    if(mininterval < 0)
    {
        QMessageBox::warning(0,tr("警告"),tr("起始时间大于终止时间！"),tr("确定"));
        ui->end_timeedit->setTime(oldendtime);
        return ;
    }
    else
    {
        oldendtime = ui->end_timeedit->time();
    }
}*/

void HistoryDataForm::onDataChanged(QModelIndex lefttop,QModelIndex rightbuttom)
{
    int datachangedrow = lefttop.row();
    int datachangedcolnum = lefttop.column();

    if(datachangedrow == 0)
    {
       //qDebug()<<item->text();
       QString str = tablewidget->item(datachangedrow,datachangedcolnum)->text();

       if(str =="双击此处选择参数") return;
       bool flag = false;
       for(int i = 0; i < colnum/2; i ++)
       {
           if(i*2 != datachangedcolnum)
           {
               if(tablewidget->item(datachangedrow,2*i)->text() == str)
               {
                   flag = true;
                   break;
               }
           }
       }
       if(flag)
       {
           QMessageBox::warning(0,"警告","参数重复！","确定");
           tablewidget->item(datachangedrow,datachangedcolnum)->setText("双击此处选择参数");
           return;
       }

       qDebug()<<"datachangedrow"<<datachangedrow<<"datachangedcolnum"<<datachangedcolnum<<str;



       QStringList roomandarg = str.split("： ");
       int roomid = roomnameToIds[roomandarg.first()];

       QString normalrange = "";
       QString alarmlimit = "";
       QStringList argandunit = roomandarg.last().split("(");
       QString argname = argandunit.first();
       QString arguint = "";

       if(argname == "温度")
       {
           arguint = "℃";

           normalrange.append(QString::number(analogsrange[roomid].temprature_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].temprature_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmup,'f',1));

       }
       else if(argname == "湿度")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].moisture_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].moisture_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmup,'f',1));
       }
       else if(argname == "氧气")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].O2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].O2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmup,'f',1));
       }
       else if(argname == "二氧化碳")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].CO2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].CO2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmup,'f',1));
       }
       else if(argname == "空气品质")
       {
           // arguint = "℃";无单位
           normalrange.append(QString::number(analogsrange[roomid].index_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].index_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmup,'f',1));
       }
       else if(argname == "市电电压")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage1_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage1_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmup,'f',1));
       }
       else if(argname == "零电压差")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmup,'f',1));
       }
       else if(argname == "漏水")
       {
           // arguint = "℃";无单位
       }
       else if(argname == "烟雾")
       {
           // arguint = "℃";无单位
       }
       if(tablewidget->item(0,datachangedcolnum)->text() != "双击此处选择参数")
       {
           if(argname != "漏水" && argname != "烟雾")
           {
               tablewidget->item(1,datachangedcolnum)->setText( "量    程: " + normalrange + "\n"+"报警范围: " + alarmlimit);
           }
           else if(!argname.isEmpty())
           {
               tablewidget->item(1,datachangedcolnum)->setText("--");
           }
       }

    }
}


void HistoryDataForm::onTableWidgetCellChanged(int row, int col)
{

    ui->arghint_label->setText("第" + QString::number(col/2 + 1)+"列参数");
    currentcol = col/2;
    /*if(row == 0)
    {

        if(tablewidget->item(row,col)->text() != tr("双击此处选择参数"))
        {
            qDebug()<<col;
            if(currentcol != col/2)
            {
                currentcol = col/2;
                qDebug()<<"currentcol"<<currentcol;
                iscellchanged = true;


               //iscellchanged = false;
            }
        }
    }*/
}
void HistoryDataForm::onTableWidgetItemChanged(QTableWidgetItem * item)
{

    //if(item->column()/2 == )
    ui->arghint_label->setText("第" + QString::number(item->column()/2 + 1)+"列参数");
    currentcol = item->column()/2;
    if(item->row() == 0)
    {
       qDebug()<<item->text();
       QString str = item->text();
       QStringList roomandarg = str.split("： ");
       int roomid = roomnameToIds[roomandarg.first()];

       QString normalrange = "";
       QString alarmlimit = "";
       QString argname = roomandarg.last();
       QString arguint = "";

       if(argname == "温度")
       {
           arguint = "℃";

           normalrange.append(QString::number(analogsrange[roomid].temprature_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].temprature_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmup,'f',1));

       }
       else if(argname == "湿度")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].moisture_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].moisture_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmup,'f',1));
       }
       else if(argname == "氧气")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].O2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].O2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmup,'f',1));
       }
       else if(argname == "二氧化碳")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].CO2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].CO2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmup,'f',1));
       }
       else if(argname == "空气品质")
       {
           // arguint = "℃";无单位
           normalrange.append(QString::number(analogsrange[roomid].index_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].index_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmup,'f',1));
       }
       else if(argname == "市电电压")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage1_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage1_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmup,'f',1));
       }
       else if(argname == "零电压差")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmup,'f',1));
       }
       else if(argname == "漏水")
       {
           // arguint = "℃";无单位
       }
       else if(argname == "烟雾")
       {
           // arguint = "℃";无单位
       }
       if(argname != "漏水" || argname != "烟雾")
       {
           tablewidget->item(1,item->column())->setText( "量程:" + normalrange +"\n报警范围:" + alarmlimit);
       }

    }
}


void HistoryDataForm::onAddColumnPushButton()
{
    qDebug()<<"增加列";
    if(paranum == 9)
    {
        QMessageBox::warning(0,"警告","最多可选择9个参数","确定");
        ui->addcol_pushbutton->setEnabled(false);
        return;
    }
    ui->delcol_pushbutton->setEnabled(true);

    tablewidget->insertColumn(colnum);
    tablewidget->insertColumn(colnum+1);
    tablewidget->setColumnWidth(colnum,130);
    tablewidget->setColumnWidth(colnum + 1,60);



    QTableWidgetItem * item;
    tablewidget->setSpan(0,paranum*2,1,2);
    item = new QTableWidgetItem(tr("双击此处选择参数"));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    tablewidget->setItem(0,paranum*2,item);

    tablewidget->setSpan(1,paranum*2,1,2);
    item = new QTableWidgetItem(tr("参数属性"));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item->setFlags(item->flags()&~Qt::ItemIsEditable);
    tablewidget->setItem(1,paranum*2,item);

    item = new QTableWidgetItem(tr("时间"));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item->setFlags(item->flags()&~Qt::ItemIsEditable);
    tablewidget->setItem(2,paranum*2,item);
    item = new QTableWidgetItem(tr("值"));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item->setFlags(item->flags()&~Qt::ItemIsEditable);
    tablewidget->setItem(2,paranum*2+1,item);

    for(int i = titlerow; i < titlerow + rownum; i++)
    {
        item = new QTableWidgetItem;
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(i,paranum*2,item);
        item = new QTableWidgetItem;
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(i,paranum*2 + 1,item);
    }
    paranum++;
    colnum += 2;

}

void HistoryDataForm::onDelColumnPushButton()
{
    qDebug()<<"删除列";


    if(paranum == 1)
    {
        QMessageBox::warning(0,"警告","至少有一个参数","确定");
        ui->delcol_pushbutton->setEnabled(false);
        return;
    }


    int result  = QMessageBox::warning(0,"警告","至少有一个参数","确定","取消");
    if(result == 1)
    {
        return;
    }

    ui->addcol_pushbutton->setEnabled(true);
    if(currentcol < 0)
    {
        QMessageBox::warning(0,"警告","尚未选择要删除的参数","确定");
        return;
    }

    tablewidget->removeColumn(currentcol*2 + 1);
    tablewidget->removeColumn(currentcol*2);
    currentcol = -1;
    ui->arghint_label->setText("");
    paranum--;
    colnum -= 2;
}
void HistoryDataForm::onSearchPushButton()
{
    qDebug()<<"查询";
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        int day = ui->start_dateedit->date().daysTo(ui->end_dateedit->date());
        int premins = QTime(0,0,0).secsTo(ui->start_timeedit->time())/60;
        int aftmins = QTime(0,0,0).secsTo(ui->end_timeedit->time())/60;
        int mininterval = day*24*60 - premins + aftmins;
        if(mininterval < 0)
        {
            QMessageBox::warning(0,tr("警告"),tr("起始时间大于结束时间！"),tr("确定"));
            return ;
        }
        int ananum = 0;
        int swinum = 0;
        QStringList curargs;
        for(int i = 0; i < paranum ; i++)
        {
            QString str = tablewidget->item(0,2*i)->text();
            curargs<<str;
            qDebug()<<str;
            if(str != "双击此处选择参数")
            {
                QString  arg = str.split("： ").last().split("(").first();
                qDebug()<<"arg"<<arg;
                if(arg != "漏水" && arg != "烟雾")
                {
                    ananum++;
                }
                else if(!arg.isEmpty())
                {
                    swinum++;
                }
            }
        }
        qDebug()<<ananum<<swinum;
        if(ananum == 0 && swinum == 0)
        {
            QMessageBox::warning(0,tr("警告"),tr("尚未选择参数！"),tr("确定"));
            return ;
        }
        if(oldstartdatetime.date() == ui->start_dateedit->date() && oldstartdatetime.time() == ui->start_timeedit->time()
                && oldenddatetime.date() == ui->end_dateedit->date() && oldenddatetime.time() == ui->end_timeedit->time() && curargs == oldargs)//时间段没有改变参数没有改变
        {
        }
        else //时间段改变
        {

            QList<QDateTime> startdatetimes;
            QList<QDateTime> enddatetimes;
            QStringList tablenames;
            QString startmonth;
            startmonth.append(QString::number(ui->start_dateedit->date().year()));
            startmonth.append(QString::number(ui->start_dateedit->date().month()));
            QString endmonth;
            endmonth.append(QString::number(ui->end_dateedit->date().year()));
            endmonth.append(QString::number(ui->end_dateedit->date().month()));
            if(startmonth == endmonth)
            {
                QDateTime tempstartdatetime;
                QDateTime tempenddatetime;
                tempstartdatetime.setDate(ui->start_dateedit->date());
                tempstartdatetime.setTime(ui->start_timeedit->time());
                startdatetimes.append(tempstartdatetime);

                tempenddatetime.setDate(ui->end_dateedit->date());
                tempenddatetime.setTime(ui->end_timeedit->time());
                enddatetimes.append(tempenddatetime);

                QString temptablename = "analog";
                /*temptablename.append(QString::number(ui->start_dateedit->date().year()));
                temptablename.append(QString::number(ui->start_dateedit->date().month()));*/
                temptablename.append(ui->start_dateedit->date().toString("yyyyMM"));
                tablenames.append(temptablename);
            }
            else
            {
                QDateTime tempstartdatetime;
                QDateTime tempenddatetime;
                tempstartdatetime.setDate(ui->start_dateedit->date());
                tempstartdatetime.setTime(ui->start_timeedit->time());
                startdatetimes.append(tempstartdatetime);

                tempenddatetime.setDate(ui->start_dateedit->date());
                tempenddatetime.setTime(QTime::fromString("23:59:59"));
                enddatetimes.append(tempenddatetime);

                QString temptablename = "analog";
                /*temptablename.append(QString::number(ui->start_dateedit->date().year()));
                temptablename.append(QString::number(ui->start_dateedit->date().month()));*/
                temptablename.append(ui->start_dateedit->date().toString("yyyyMM"));
                tablenames.append(temptablename);


                tempstartdatetime.setDate(ui->end_dateedit->date());
                tempstartdatetime.setTime(QTime::fromString("00:00:00"));
                startdatetimes.append(tempstartdatetime);

                tempenddatetime.setDate(ui->end_dateedit->date());
                tempenddatetime.setTime(ui->end_timeedit->time());
                enddatetimes.append(tempenddatetime);

                temptablename = "analog";
                /*temptablename.append(QString::number(ui->end_dateedit->date().year()));
                temptablename.append(QString::number(ui->end_dateedit->date().month()));*/
                temptablename.append(ui->end_dateedit->date().toString("yyyyMM"));
                tablenames.append(temptablename);
            }
            if(swinum)
            {
                if(mininterval > 3)//90条
                {
                    QMessageBox::warning(0,tr("警告"),tr("参数中含有开关量，最大时间间隔为3分钟"),tr("确定"));
                    return;
                }
                else
                {
                    while(rownum > 0)
                    {
                        tablewidget->removeRow(tablewidget->rowCount() - 1);
                        rownum--;
                        qDebug()<<"shanchuhang";
                    }
                    //产生新的行数
                    rownum = mininterval*60/2 + 1;
                }
            }
            else if(ananum)
            {
                if(mininterval > 45)//90条
                {
                    QMessageBox::warning(0,tr("警告"),tr("所有参数为模拟量,最大时间间隔为45分钟"),tr("确定"));
                    return;
                }
                else
                {
                    while(rownum > 0)
                    {
                        tablewidget->removeRow(tablewidget->rowCount() - 1);
                        rownum--;
                        qDebug()<<"shanchuhang";
                    }
                    //产生新的行数
                    rownum = mininterval*60/30 + 1;
                }
            }
            if(ananum || swinum)
            {
                for(int i = titlerow; i < titlerow + rownum; i++)
                {
                    tablewidget->insertRow(i);
                }
                //读取数据中的数据
                for(int i = 0; i < curargs.size();i++)
                {
                    QString str = curargs.at(i);
                    if(str != "双击此处选择参数")
                    {
                        QStringList roomandargs = str.split("： ");
                        QString roomname = roomandargs.first();
                        int roomid = roomnameToIds[roomname];
                        QString  argname = roomandargs.last().split("(").first();
                        QString  queryarg = "";
                        if(argname == "温度")
                        {
                            queryarg = "temperature";
                        }
                        else if(argname == "湿度")
                        {
                            queryarg = "moisture";
                        }
                        else if(argname == "氧气")
                        {
                            queryarg = "O2";
                        }
                        else if(argname == "二氧化碳")
                        {
                            queryarg = "CO2";
                        }
                        else if(argname == "空气品质")
                        {
                            queryarg = "indexs";
                        }
                        else if(argname == "市电电压")
                        {
                            queryarg = "voltage1";
                        }
                        else if(argname == "零电压差")
                        {
                            queryarg = "voltage2";
                        }
                        else if(argname == "漏水")
                        {
                            queryarg = "water";
                        }
                        else if(argname == "烟雾")
                        {
                            queryarg = "smoke";
                        }
                        QSqlQuery query(globaldb);
                        if(argname != "烟雾" && argname != "漏水")
                        {
                            //获取报警上下限
                            QString arglimitstr = tablewidget->item(1,2*i)->text().split("报警范围:").last();
                            QStringList downanduplimit = arglimitstr.split("-");
                            float argdownlimit = downanduplimit.first().toFloat();
                            float arguplimit = downanduplimit.last().toFloat();

                            qDebug()<<startdatetimes;
                            qDebug()<<enddatetimes;
                            qDebug()<<tablenames;
                            for(int k = 0; k < tablenames.count(); k++)
                            {

                                QString querystr = "SELECT ";
                                querystr.append("time,");
                                querystr.append(queryarg+ " ");
                                querystr.append(" FROM ");
                                querystr.append(tablenames.at(k));
                                querystr.append(" WHERE device_id = ? AND time >= ? AND time <= ?");
                                qDebug()<<"querystr"<<querystr;
                                query.prepare(querystr);
                                query.addBindValue(roomid);
                                query.addBindValue(startdatetimes.at(k).toString("yyyy-MM-dd hh:mm:ss"));
                                query.addBindValue(enddatetimes.at(k).toString("yyyy-MM-dd hh:mm:ss"));
                                query.exec();
                                qDebug()<<"roomid"<<roomid;
                                qDebug()<<"starttime"<<startdatetimes.at(k).toString("yyyy-MM-dd hh:mm:ss");
                                qDebug()<<"starttime"<<enddatetimes.at(k).toString("yyyy-MM-dd hh:mm:ss");
                                qDebug()<<"querysize"<<query.size();
                                int startrow = 3;
                                QTableWidgetItem * item = 0;
                                if(query.size() <= 0)
                                {
                                    QMessageBox::information(0,tr("提示"),str + tr("此时间段内无历史数据！"),tr("确定"));
                                }
                                while(query.next())
                                {
                                    item = new QTableWidgetItem;
                                    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                    item->setFlags(item->flags()&~Qt::ItemIsEditable);
                                    item->setText(query.value(0).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                                    tablewidget->setItem(startrow,i*2,item);
                                    item = new QTableWidgetItem;
                                    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                    item->setFlags(item->flags()&~Qt::ItemIsEditable);
                                    float curvalue = query.value(1).toFloat();
                                    if(curvalue > arguplimit)
                                    {
                                        //item->setTextColor(datacolor[alarmupcolor]);
                                        item->setTextColor(Qt::darkRed);
                                    }
                                    else if(curvalue < argdownlimit)
                                    {
                                        //item->setTextColor(datacolor[alarmdowncolor]);
                                        item->setTextColor(Qt::darkMagenta);
                                    }
                                    else
                                    {
                                        //item->setTextColor(datacolor[normalcolor]);
                                        item->setTextColor(Qt::darkGreen);
                                    }
                                    item->setText(QString::number(curvalue,'f',1));
                                    tablewidget->setItem(startrow,i*2+1,item);
                                    startrow++;
                                }
                                // query.clear();
                                // query.finish();
                            }
                        }
                        else
                        {
                            QString querystr = "SELECT ";
                            querystr.append("time,");
                            querystr.append(queryarg+ " ");
                            QString tablename="";
                            QSqlQuery query(globaldb);
                            tablename = "switch";
                            querystr.append(" FROM ");
                            querystr.append(tablename);
                            querystr.append(" WHERE device_id = ? AND time >= ? AND time <= ?");
                            qDebug()<<"querystr"<<querystr;
                            query.prepare(querystr);
                            query.addBindValue(roomid);
                            QDateTime curstartdatetime;
                            curstartdatetime.setDate(ui->start_dateedit->date());
                            curstartdatetime.setTime(ui->start_timeedit->time());
                            query.addBindValue(curstartdatetime);
                            qDebug()<<curstartdatetime;
                            QDateTime curenddatetime;
                            curenddatetime.setDate(ui->end_dateedit->date());
                            curenddatetime.setTime(ui->end_timeedit->time());
                            qDebug()<<curenddatetime;
                            query.addBindValue(curenddatetime);
                            query.exec();
                            qDebug()<<"querysize"<<query.size();
                            int startrow = 3;
                            QTableWidgetItem * item = 0;
                            if(query.size() <= 0)
                            {
                                QMessageBox::information(0,tr("提示"),str + tr("此时间段内无历史数据！"),tr("确定"));
                            }
                            while(query.next())
                            {
                                item = new QTableWidgetItem;
                                item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                item->setFlags(item->flags()&~Qt::ItemIsEditable);
                                item->setText(query.value(0).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                                tablewidget->setItem(startrow,i*2,item);
                                item = new QTableWidgetItem;
                                item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                item->setFlags(item->flags()&~Qt::ItemIsEditable);
                                bool swicthvalue = query.value(1).toBool();
                                if(swicthvalue)
                                {
                                    //item->setTextColor(datacolor[alarmupcolor]);
                                    item->setTextColor(Qt::darkRed);
                                    item->setText("异常");
                                }
                                else
                                {
                                    //item->setTextColor(datacolor[normalcolor]);
                                    item->setTextColor(Qt::darkGreen);
                                    item->setText("正常");
                                }
                                tablewidget->setItem(startrow,i*2+1,item);
                                startrow++;
                            }
                        }
                        query.clear();
                        query.finish();
                    }
                }
            }
            oldstartdatetime.setDate(ui->start_dateedit->date());
            oldstartdatetime.setTime(ui->start_timeedit->time());
            oldenddatetime.setDate(ui->end_dateedit->date());
            oldenddatetime.setTime(ui->end_timeedit->time());
            oldargs = curargs;
            //globaldb.close();
        }

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

