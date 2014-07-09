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
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    this->setWindowTitle("��ʷ����");
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
        item = new QTableWidgetItem(tr("˫���˴�ѡ�����"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        tablewidget->setItem(0,i*2,item);

        tablewidget->setSpan(1,i*2,1,2);
        item = new QTableWidgetItem(tr("��������"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(1,i*2,item);

        item = new QTableWidgetItem(tr("ʱ��"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(2,i*2,item);
        item = new QTableWidgetItem(tr("ֵ"));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFlags(item->flags()&~Qt::ItemIsEditable);
        tablewidget->setItem(2,i*2+1,item);
    }

    vboxlayout = new QVBoxLayout();//�����ظ���Ӳ���
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
           QMessageBox::warning(0,tr("����"),tr("��ʼ���ڴ�����ֹ���ڣ�"),tr("ȷ��"));
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
        QMessageBox::warning(0,tr("����"),tr("��ʼ���ڴ�����ֹ���ڣ�"),tr("ȷ��"));
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
        QMessageBox::warning(0,tr("����"),tr("��ʼʱ�������ֹʱ�䣡"),tr("ȷ��"));
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
        QMessageBox::warning(0,tr("����"),tr("��ʼʱ�������ֹʱ�䣡"),tr("ȷ��"));
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

       if(str =="˫���˴�ѡ�����") return;
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
           QMessageBox::warning(0,"����","�����ظ���","ȷ��");
           tablewidget->item(datachangedrow,datachangedcolnum)->setText("˫���˴�ѡ�����");
           return;
       }

       qDebug()<<"datachangedrow"<<datachangedrow<<"datachangedcolnum"<<datachangedcolnum<<str;



       QStringList roomandarg = str.split("�� ");
       int roomid = roomnameToIds[roomandarg.first()];

       QString normalrange = "";
       QString alarmlimit = "";
       QStringList argandunit = roomandarg.last().split("(");
       QString argname = argandunit.first();
       QString arguint = "";

       if(argname == "�¶�")
       {
           arguint = "��";

           normalrange.append(QString::number(analogsrange[roomid].temprature_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].temprature_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmup,'f',1));

       }
       else if(argname == "ʪ��")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].moisture_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].moisture_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmup,'f',1));
       }
       else if(argname == "����")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].O2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].O2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmup,'f',1));
       }
       else if(argname == "������̼")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].CO2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].CO2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmup,'f',1));
       }
       else if(argname == "����Ʒ��")
       {
           // arguint = "��";�޵�λ
           normalrange.append(QString::number(analogsrange[roomid].index_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].index_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmup,'f',1));
       }
       else if(argname == "�е��ѹ")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage1_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage1_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmup,'f',1));
       }
       else if(argname == "���ѹ��")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmup,'f',1));
       }
       else if(argname == "©ˮ")
       {
           // arguint = "��";�޵�λ
       }
       else if(argname == "����")
       {
           // arguint = "��";�޵�λ
       }
       if(tablewidget->item(0,datachangedcolnum)->text() != "˫���˴�ѡ�����")
       {
           if(argname != "©ˮ" && argname != "����")
           {
               tablewidget->item(1,datachangedcolnum)->setText( "��    ��: " + normalrange + "\n"+"������Χ: " + alarmlimit);
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

    ui->arghint_label->setText("��" + QString::number(col/2 + 1)+"�в���");
    currentcol = col/2;
    /*if(row == 0)
    {

        if(tablewidget->item(row,col)->text() != tr("˫���˴�ѡ�����"))
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
    ui->arghint_label->setText("��" + QString::number(item->column()/2 + 1)+"�в���");
    currentcol = item->column()/2;
    if(item->row() == 0)
    {
       qDebug()<<item->text();
       QString str = item->text();
       QStringList roomandarg = str.split("�� ");
       int roomid = roomnameToIds[roomandarg.first()];

       QString normalrange = "";
       QString alarmlimit = "";
       QString argname = roomandarg.last();
       QString arguint = "";

       if(argname == "�¶�")
       {
           arguint = "��";

           normalrange.append(QString::number(analogsrange[roomid].temprature_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].temprature_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].temprature_alarmup,'f',1));

       }
       else if(argname == "ʪ��")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].moisture_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].moisture_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].moisture_alarmup,'f',1));
       }
       else if(argname == "����")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].O2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].O2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].O2_alarmup,'f',1));
       }
       else if(argname == "������̼")
       {
           arguint = "%";

           normalrange.append(QString::number(analogsrange[roomid].CO2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].CO2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].CO2_alarmup,'f',1));
       }
       else if(argname == "����Ʒ��")
       {
           // arguint = "��";�޵�λ
           normalrange.append(QString::number(analogsrange[roomid].index_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].index_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].index_alarmup,'f',1));
       }
       else if(argname == "�е��ѹ")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage1_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage1_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage1_alarmup,'f',1));
       }
       else if(argname == "���ѹ��")
       {
           arguint = "V";

           normalrange.append(QString::number(analogsrange[roomid].voltage2_down,'f',1));
           normalrange.append("-");
           normalrange.append(QString::number(analogsrange[roomid].voltage2_up,'f',1));

           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmdown,'f',1));
           alarmlimit.append("-");
           alarmlimit.append(QString::number(analogsrange[roomid].voltage2_alarmup,'f',1));
       }
       else if(argname == "©ˮ")
       {
           // arguint = "��";�޵�λ
       }
       else if(argname == "����")
       {
           // arguint = "��";�޵�λ
       }
       if(argname != "©ˮ" || argname != "����")
       {
           tablewidget->item(1,item->column())->setText( "����:" + normalrange +"\n������Χ:" + alarmlimit);
       }

    }
}


void HistoryDataForm::onAddColumnPushButton()
{
    qDebug()<<"������";
    if(paranum == 9)
    {
        QMessageBox::warning(0,"����","����ѡ��9������","ȷ��");
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
    item = new QTableWidgetItem(tr("˫���˴�ѡ�����"));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    tablewidget->setItem(0,paranum*2,item);

    tablewidget->setSpan(1,paranum*2,1,2);
    item = new QTableWidgetItem(tr("��������"));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item->setFlags(item->flags()&~Qt::ItemIsEditable);
    tablewidget->setItem(1,paranum*2,item);

    item = new QTableWidgetItem(tr("ʱ��"));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item->setFlags(item->flags()&~Qt::ItemIsEditable);
    tablewidget->setItem(2,paranum*2,item);
    item = new QTableWidgetItem(tr("ֵ"));
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
    qDebug()<<"ɾ����";


    if(paranum == 1)
    {
        QMessageBox::warning(0,"����","������һ������","ȷ��");
        ui->delcol_pushbutton->setEnabled(false);
        return;
    }


    int result  = QMessageBox::warning(0,"����","������һ������","ȷ��","ȡ��");
    if(result == 1)
    {
        return;
    }

    ui->addcol_pushbutton->setEnabled(true);
    if(currentcol < 0)
    {
        QMessageBox::warning(0,"����","��δѡ��Ҫɾ���Ĳ���","ȷ��");
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
    qDebug()<<"��ѯ";
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
            QMessageBox::warning(0,tr("����"),tr("��ʼʱ����ڽ���ʱ�䣡"),tr("ȷ��"));
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
            if(str != "˫���˴�ѡ�����")
            {
                QString  arg = str.split("�� ").last().split("(").first();
                qDebug()<<"arg"<<arg;
                if(arg != "©ˮ" && arg != "����")
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
            QMessageBox::warning(0,tr("����"),tr("��δѡ�������"),tr("ȷ��"));
            return ;
        }
        if(oldstartdatetime.date() == ui->start_dateedit->date() && oldstartdatetime.time() == ui->start_timeedit->time()
                && oldenddatetime.date() == ui->end_dateedit->date() && oldenddatetime.time() == ui->end_timeedit->time() && curargs == oldargs)//ʱ���û�иı����û�иı�
        {
        }
        else //ʱ��θı�
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
                if(mininterval > 3)//90��
                {
                    QMessageBox::warning(0,tr("����"),tr("�����к��п����������ʱ����Ϊ3����"),tr("ȷ��"));
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
                    //�����µ�����
                    rownum = mininterval*60/2 + 1;
                }
            }
            else if(ananum)
            {
                if(mininterval > 45)//90��
                {
                    QMessageBox::warning(0,tr("����"),tr("���в���Ϊģ����,���ʱ����Ϊ45����"),tr("ȷ��"));
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
                    //�����µ�����
                    rownum = mininterval*60/30 + 1;
                }
            }
            if(ananum || swinum)
            {
                for(int i = titlerow; i < titlerow + rownum; i++)
                {
                    tablewidget->insertRow(i);
                }
                //��ȡ�����е�����
                for(int i = 0; i < curargs.size();i++)
                {
                    QString str = curargs.at(i);
                    if(str != "˫���˴�ѡ�����")
                    {
                        QStringList roomandargs = str.split("�� ");
                        QString roomname = roomandargs.first();
                        int roomid = roomnameToIds[roomname];
                        QString  argname = roomandargs.last().split("(").first();
                        QString  queryarg = "";
                        if(argname == "�¶�")
                        {
                            queryarg = "temperature";
                        }
                        else if(argname == "ʪ��")
                        {
                            queryarg = "moisture";
                        }
                        else if(argname == "����")
                        {
                            queryarg = "O2";
                        }
                        else if(argname == "������̼")
                        {
                            queryarg = "CO2";
                        }
                        else if(argname == "����Ʒ��")
                        {
                            queryarg = "indexs";
                        }
                        else if(argname == "�е��ѹ")
                        {
                            queryarg = "voltage1";
                        }
                        else if(argname == "���ѹ��")
                        {
                            queryarg = "voltage2";
                        }
                        else if(argname == "©ˮ")
                        {
                            queryarg = "water";
                        }
                        else if(argname == "����")
                        {
                            queryarg = "smoke";
                        }
                        QSqlQuery query(globaldb);
                        if(argname != "����" && argname != "©ˮ")
                        {
                            //��ȡ����������
                            QString arglimitstr = tablewidget->item(1,2*i)->text().split("������Χ:").last();
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
                                    QMessageBox::information(0,tr("��ʾ"),str + tr("��ʱ���������ʷ���ݣ�"),tr("ȷ��"));
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
                                QMessageBox::information(0,tr("��ʾ"),str + tr("��ʱ���������ʷ���ݣ�"),tr("ȷ��"));
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
                                    item->setText("�쳣");
                                }
                                else
                                {
                                    //item->setTextColor(datacolor[normalcolor]);
                                    item->setTextColor(Qt::darkGreen);
                                    item->setText("����");
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
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
        }
    }
}

