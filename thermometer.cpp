#include <QMouseEvent>
#include <QDebug>
#include <QFile>
#include <Qtextcodec>
#include <QMessageBox>
#include <QAction>
#include "thermometer.h"
#include "receiver.h"

Thermometer::Thermometer(QWidget *parent)
    : QWidget(parent)
{
    //n = -1000.0;
    n = OFFLINEDATA;
    roomname = "";
    saaar.alarm_down = 0.0;
    saaar.alarm_up = 0.0;
    saaar.range_down = 0.0;
    saaar.range_up = 0.0;
    //setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);
    //setWindowFlags(Qt::FramelessWindowHint);
    QAction * del_action = new QAction("ɾ��",this);
    connect(del_action,SIGNAL(triggered()),this,SLOT(closeMySelf()));
    addAction(del_action);
    //setContextMenuPolicy(Qt::ActionsContextMenu);
    this->setFixedSize(166,330);
    this->setMouseTracking(true);
}
void Thermometer::loadArgs(QString filename)
{
    if(filename.isEmpty())
    {
        QMessageBox::warning(0,tr("����"),tr("�ؼ�Ϊ�գ�"),tr("ȷ��"));
        return;
    }
    this->filename = filename;
    connect(raao,SIGNAL(refreshArgs()),this,SLOT(reloadArgs()));
    QString path = "controls/";
    QFile file(path+filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�ļ���ʧ�ܣ�"),tr("ȷ��"));
        return;
    }
    QTextStream in(&file);
    QString controlstr;

    int count = 0 ;
     count = in.readLine().toInt();
    if(count > 1 )
    {
        QMessageBox::warning(0,tr("����"),tr("��ֹһ��������������ȡ����"),tr("ȷ��"));
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
           return;
       }*/
       argname = controlinfo.at(controlinfo.size() - 1);
       argname.remove(" ");
       argname.remove(";");
       if(!roomIsCompleteConfigure(roomid))
       {
           file.close();
           return;
       }

       //�¶ȱ���
       if(argname == "�¶�")
       {
           saaar.range_down = analogsrange[roomid].temprature_down;
           saaar.range_up = analogsrange[roomid].temprature_up;
           saaar.alarm_down = analogsrange[roomid].temprature_alarmdown;
           saaar.alarm_up = analogsrange[roomid].temprature_alarmup;
           saaar.arg_unit = analogsrange[roomid].temprature_unit;

       }
       else if(argname == "ʪ��")
       {
           saaar.range_down = analogsrange[roomid].moisture_down;
           saaar.range_up = analogsrange[roomid].moisture_up;
           saaar.alarm_down = analogsrange[roomid].moisture_alarmdown;
           saaar.alarm_up = analogsrange[roomid].moisture_alarmup;
           saaar.arg_unit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "����")
       {
           saaar.range_down = analogsrange[roomid].O2_down;
           saaar.range_up = analogsrange[roomid].O2_up;
           saaar.alarm_down = analogsrange[roomid].O2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].O2_alarmup;
           saaar.arg_unit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "������̼")
       {
           saaar.range_down = analogsrange[roomid].CO2_down;
           saaar.range_up = analogsrange[roomid].CO2_up;
           saaar.alarm_down = analogsrange[roomid].CO2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].CO2_alarmup;
           saaar.arg_unit = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "����Ʒ��")
       {
           saaar.range_down = analogsrange[roomid].index_down;
           saaar.range_up = analogsrange[roomid].index_up;
           saaar.alarm_down = analogsrange[roomid].index_alarmdown;
           saaar.alarm_up = analogsrange[roomid].index_alarmup;
           saaar.arg_unit = analogsrange[roomid].index_unit;
       }
       else if(argname == "�е��ѹ")
       {
           saaar.range_down = analogsrange[roomid].voltage1_down;
           saaar.range_up = analogsrange[roomid].voltage1_up;
           saaar.alarm_down = analogsrange[roomid].voltage1_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage1_alarmup;
           saaar.arg_unit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "���ѹ��")
       {
           saaar.range_down = analogsrange[roomid].voltage2_down;
           saaar.range_up = analogsrange[roomid].voltage2_up;
           saaar.alarm_down = analogsrange[roomid].voltage2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage2_alarmup;
           saaar.arg_unit = analogsrange[roomid].voltage2_unit;
       }
    }
    file.close();
    qDebug()<<roomname;
    qDebug()<<saaar.range_up;
    qDebug()<<saaar.range_down;
    qDebug()<<saaar.alarm_up;
    qDebug()<<saaar.alarm_down;
}

void Thermometer::reloadArgs()
{
    roomname = "";
    argname = "";
    QString path = "controls/";
    QFile file(path+filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //QMessageBox::warning(0,tr("����"),tr("�ļ���ʧ�ܣ�"),tr("ȷ��"));
        file.close();
        return;
    }
    QTextStream in(&file);
    QString controlstr;

    int count = 0 ;
     count = in.readLine().toInt();
    if(count > 1 )
    {
        QMessageBox::warning(0,tr("����"),tr("��ֹһ��������������ȡ����"),tr("ȷ��"));
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
            return;
        }*/
        argname = controlinfo.at(controlinfo.size() - 1);
        argname.remove(" ");
        argname.remove(";");
        if(!roomIsCompleteConfigure(roomid))
        {
            file.close();
            return;
        }


       //�¶ȱ���
       if(argname == "�¶�")
       {
           saaar.range_down = analogsrange[roomid].temprature_down;
           saaar.range_up = analogsrange[roomid].temprature_up;
           saaar.alarm_down = analogsrange[roomid].temprature_alarmdown;
           saaar.alarm_up = analogsrange[roomid].temprature_alarmup;
           saaar.arg_unit = analogsrange[roomid].temprature_unit;

       }
       else if(argname == "ʪ��")
       {
           saaar.range_down = analogsrange[roomid].moisture_down;
           saaar.range_up = analogsrange[roomid].moisture_up;
           saaar.alarm_down = analogsrange[roomid].moisture_alarmdown;
           saaar.alarm_up = analogsrange[roomid].moisture_alarmup;
           saaar.arg_unit = analogsrange[roomid].moisture_unit;
       }
       else if(argname == "����")
       {
           saaar.range_down = analogsrange[roomid].O2_down;
           saaar.range_up = analogsrange[roomid].O2_up;
           saaar.alarm_down = analogsrange[roomid].O2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].O2_alarmup;
           saaar.arg_unit = analogsrange[roomid].O2_unit;
       }
       else if(argname == "������̼")
       {
           saaar.range_down = analogsrange[roomid].CO2_down;
           saaar.range_up = analogsrange[roomid].CO2_up;
           saaar.alarm_down = analogsrange[roomid].CO2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].CO2_alarmup;
           saaar.arg_unit = analogsrange[roomid].CO2_unit;
       }
       else if(argname == "����Ʒ��")
       {
           saaar.range_down = analogsrange[roomid].index_down;
           saaar.range_up = analogsrange[roomid].index_up;
           saaar.alarm_down = analogsrange[roomid].index_alarmdown;
           saaar.alarm_up = analogsrange[roomid].index_alarmup;
           saaar.arg_unit = analogsrange[roomid].index_unit;
       }
       else if(argname == "�е��ѹ")
       {
           saaar.range_down = analogsrange[roomid].voltage1_down;
           saaar.range_up = analogsrange[roomid].voltage1_up;
           saaar.alarm_down = analogsrange[roomid].voltage1_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage1_alarmup;
           saaar.arg_unit = analogsrange[roomid].voltage1_unit;
       }
       else if(argname == "���ѹ��")
       {
           saaar.range_down = analogsrange[roomid].voltage2_down;
           saaar.range_up = analogsrange[roomid].voltage2_up;
           saaar.alarm_down = analogsrange[roomid].voltage2_alarmdown;
           saaar.alarm_up = analogsrange[roomid].voltage2_alarmup;
           saaar.arg_unit = analogsrange[roomid].voltage2_unit;
       }
    }
    file.close();
    qDebug()<<roomname;
    qDebug()<<saaar.range_up;
    qDebug()<<saaar.range_down;
    qDebug()<<saaar.alarm_up;
    qDebug()<<saaar.alarm_down;
    update();
}

void Thermometer::launch()
{
    /*updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(TimeOut()));
    updateTimer->start(2000);*/
    connect(rec,SIGNAL(switchRefresh()),this,SLOT(TimeOut()));
    TimeOut();
}

void Thermometer::mousePressEvent(QMouseEvent *event)
{
    this->raise();
    if (event->button() == Qt::LeftButton) {
        dragposition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    emit raiseAllButton();
}

void Thermometer::mouseMoveEvent(QMouseEvent *event)
{
     if(!(centralGem).contains(event->globalPos())) return;
     if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragposition);
        event->accept();
    }
}

void Thermometer::TimeOut()
{
    float currentvalue = OFFLINEDATA;
    if(argname == "�¶�")
    {
        currentvalue = analog[roomnameToIds[roomname]].temprature;
    }
    else if(argname == "ʪ��")
    {
        currentvalue = analog[roomnameToIds[roomname]].moisture;
    }
    else if(argname == "����")
    {
        currentvalue = analog[roomnameToIds[roomname]].O2;
    }
    else if(argname == "������̼")
    {
        currentvalue = analog[roomnameToIds[roomname]].CO2;
    }
    else if(argname == "����Ʒ��")
    {
        currentvalue = analog[roomnameToIds[roomname]].index;
    }
    else if(argname == "�е��ѹ")
    {
        currentvalue = analog[roomnameToIds[roomname]].voltage1;
    }
    else if(argname == "���ѹ��")
    {
        currentvalue = analog[roomnameToIds[roomname]].voltage2;
    }
    if(currentvalue > saaar.range_up)
    {
          currentvalue = saaar.range_up + abnormaldatashift;
    }
    else if(currentvalue < saaar.range_down)
    {
          currentvalue = saaar.range_down - abnormaldatashift;
    }

    setvalue(currentvalue);
    if(isVisible())
        update();
    else
    {
        qDebug()<<"Thermometer invisible";
    }
}

void Thermometer::paintEvent(QPaintEvent *)
{
    int x0=128 - 56;//���̶����ұߵ������
    int y0=94 - 31;//���̶����ұߵ�������
    int width0=10;//���̶��߿�
    int width1=6;//�п̶��߿�
    int width3=14;//��������
    int width4=8;//ˮ������
    int widHig0=40;//�̶�ֵ���
    //int widHig1=40;//��λ�ֿ��
    //int widHig2=50;//�ұ���ֵ��ʾ���
    int distan0=4;//�̶�����ˮ���������
    int distan1=1;//ˮ����С�̶ȴ���Բ���
    int distan2=20;//�߿����¼��
    int distan3=75;//�߿����Ҽ��
    int distan4=1;//�̶�ֵ��̶ȼ��
    //int distan5=5;//��λ��̶ȼ��
    int distan6=15;//ˮ�����̶����ϼ��
    int r0=14;//����Բ�뾶
    int r1=10;//ˮ��Բ�뾶

    int height = 200;//���̲��
    int topandbuttommargin = 20;//��������Լ���ֵ��λ
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen thickPen(palette().foreground(), 1);
    painter.setPen(Qt::black); //����ͼ
    painter.setBrush(Qt::white);
    painter.drawRoundRect(x0+distan0-distan3,y0-width3/2-distan6-distan2 - topandbuttommargin,2*distan3+width3,y0+height+/*(saaar.range_up+(-saaar.range_down))*4+*/distan1+(r0-r1)+2*r1-(y0-width3/2-distan6)+2*distan2 + 2*topandbuttommargin,25,25);

    //���Ʒ������
    QFont font1("Arial",9,QFont::Normal,false);
    painter.setFont(font1);
    //
    QString roomnameshow = roomname;
    int floorind = roomnameshow.lastIndexOf("¥");
    roomnameshow.insert(floorind + 1,"\n");
    painter.drawText(x0+distan0-distan3, y0+height+distan1+(r0-r1)+2*r1-(y0-width3/2-distan6)+2*distan2+ 0.5*topandbuttommargin - 5, 2*distan3+width3, topandbuttommargin + 10,Qt::AlignHCenter | Qt::AlignCenter,roomnameshow+":"+argname);
    float tenscaleheight = height/10.0;
    float tenscale = (saaar.range_up-saaar.range_down)/10.0;
    for (int i = 0; i <= 10; i++)//��������߿̶Ⱥ���Ӧ��ֵ
    {
        painter.setPen(thickPen);
       // painter.drawLine(x0, y0+saaar.range_up*4-40*i, x0-width0,  y0+saaar.range_up*4-40*i);
        painter.drawLine(x0, y0 + i*tenscaleheight, x0-width0,  y0 + i*tenscaleheight);
        QFont font("Arial",9,QFont::Bold,false);
        painter.setFont(font);
        /*painter.drawText(x0-width0-distan4-widHig0, y0+saaar.range_up*4-40*i-widHig0/2, widHig0, widHig0,
                        Qt::AlignHCenter | Qt::AlignCenter,
                        QString::number(i*10));*/
        painter.drawText(x0-width0-distan4-widHig0, y0+i*tenscaleheight-widHig0/2, widHig0, widHig0,
                                Qt::AlignHCenter | Qt::AlignCenter,
                         QString::number(saaar.range_down+(10-i)*tenscale,'f',1));


    }
    //������������
    //painter.drawLine(x0);

    float fivescaleheight = height/20.0;
    for(int i=0; i<=20 ;i++)//���γ��߿̶�
    {
        painter.setPen(thickPen);
        if(i%2 != 0)
        painter.drawLine(x0, y0 + i*fivescaleheight, x0-width1, y0+i*fivescaleheight);
    }
    painter.setPen(Qt::NoPen);//��Բ��ɫ���򻭣�ˮ��������ɫ����
    painter.setBrush(QColor(0,0,255,100));
    painter.drawEllipse(x0+distan0+width3/2-r0, y0+height+distan1, 2*r0, 2*r0);
    painter.drawRect(x0+distan0,y0-distan6,width3,height+distan1+(r0-r1+2)+distan6);//���������
    painter.drawPie(x0+distan0, y0-width3/2-distan6, width3, width3,0,180*16);//������Բ
    painter.setPen(Qt::NoPen);//��ˮ����.��ʾҺ��
    painter.setBrush(QColor(255,0,0,250));
    painter.drawEllipse(x0+distan0+width3/2-r1, y0+/*(saaar.range_up+(-saaar.range_down))*4+*/height+distan1+(r0-r1), 2*r1, 2*r1);
    painter.setPen(QColor(255,0,0,255));//����ɫ����
    painter.drawLine(x0+distan0+(width3-width4)/2,y0/*+(saaar.range_up+(-saaar.range_down))*4*/+height,x0+distan0+(width3-width4)/2,y0);
   // else//��ʾ��Ӧ�̶�ֵ���ı���ʾ�Ϳ̶�ֵ
    if(!isOffline(roomnameToIds[roomname]) &&roomIsCompleteConfigure(roomnameToIds[roomname]))
    {
        if(n <= saaar.range_up + abnormaldatashift && n >= saaar.range_down - abnormaldatashift )
        {
            QFont font("Arial",12,QFont::Bold,false);
            painter.setFont(font);
            if(n < saaar.alarm_down)
            {
                painter.setPen(datacolor[alarmdowncolor]);
            }
            else if(n > saaar.alarm_up)
            {
                painter.setPen(datacolor[alarmupcolor]);
            }
            else
            {
                painter.setPen(datacolor[normalcolor]);
            }
            if(n <= saaar.range_up && n >= saaar.range_down)
                painter.drawText(x0+distan0-distan3, y0-width3/2-distan6-distan2 - 0.3*topandbuttommargin, 2*distan3+width3, topandbuttommargin,
                             Qt::AlignHCenter | Qt::AlignCenter,QString::number(n,'f',1)+" "+saaar.arg_unit);
            else
            {
                painter.drawText(x0+distan0-distan3, y0-width3/2-distan6-distan2 - 0.3*topandbuttommargin, 2*distan3+width3, topandbuttommargin,
                                 Qt::AlignHCenter | Qt::AlignCenter,"error");
            }
            painter.setPen(Qt::NoPen);//��ˮ����.��ʾҺ��
            painter.setBrush(QColor(255,0,0,250));
            painter.drawRect(x0+distan0+width3/2-width4/2,y0 + (saaar.range_up - n)*height/(saaar.range_up-saaar.range_down),width4,height-(saaar.range_up - n)*height/(saaar.range_up-saaar.range_down) + 10);/*n��Ҫ��ʾ�Ŀ̶�ֵ*/
        }
        else
        {
            /*painter.drawText(x0+distan0-distan3, y0-width3/2-distan6-distan2 - 0.3*topandbuttommargin, 2*distan3+width3, topandbuttommargin,
                                 Qt::AlignHCenter | Qt::AlignCenter,"");
            painter.setPen(Qt::NoPen);//��ˮ����.��ʾҺ��
            painter.setBrush(QColor(255,0,0,250));
            painter.drawRect(x0+distan0+width3/2-width4/2,y0 + (saaar.range_up - n)*height/(saaar.range_up-saaar.range_down),width4,height-(saaar.range_up - n)*height/(saaar.range_up-saaar.range_down) + 10);*/
        }
    }
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(datacolor[alarmupcolor]);
    painter.setPen(pen);
    painter.drawLine(x0+distan0 + width3,y0 + (saaar.range_up - saaar.alarm_up)*height/(saaar.range_up-saaar.range_down),x0+distan0 + width3*2,y0 + (saaar.range_up - saaar.alarm_up)*height/(saaar.range_up-saaar.range_down));//���������
    pen.setColor(datacolor[alarmdowncolor]);
    painter.setPen(pen);
    painter.drawLine(x0+distan0 + width3,y0 + (saaar.range_up - saaar.alarm_down)*height/(saaar.range_up-saaar.range_down),x0+distan0 + width3*2,y0 + (saaar.range_up - saaar.alarm_down)*height/(saaar.range_up-saaar.range_down));//���������


}
void Thermometer::setvalue(float m)//�ⲿ�ӿ�
{
    n=m;
}
Thermometer::~Thermometer()
{

}

void Thermometer::closeMySelf()
{
    qDebug()<<"�ر����Լ�";
    emit delMySelf(this->windowTitle());
    this->close();
}

void Thermometer::setControlState(int type)
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
