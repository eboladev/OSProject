#include <QMouseEvent>
#include <QTextEdit>
#include <QDebug>
#include <QToolButton>
#include <QMessageBox>
#include <QPainter>
#include "tabwidget.h"
#include "tabinnerwidget.h"
#include "controllistwidget.h"
#include "controltablelistwidget.h"
#include "viewsavedialog.h"
#include "tabinnerwidget.h"

TabInnerWidget::TabInnerWidget(int pagetype, QWidget *parent) :
    QWidget(parent)
{

  //  ((TabWidget *)parent)->installEventFilter(this);
    //  this->setStyleSheet("background-image:url(images/yanglaoyuan.jpg)");
    //this->setAcceptDrops(true);
    objectid = -1;
    isnew = true;
    issave = true;
    this->pagetype = pagetype;
    save_pushbutton = new QToolButton(this);
    save_pushbutton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    save_pushbutton->setIcon(QIcon("images/viewfilesave.png"));
    save_pushbutton->setText("��  ��");
    save_pushbutton->setAutoRaise(true);
    save_pushbutton->setObjectName("save");
    saveas_pushbutton = new QToolButton(this);
    saveas_pushbutton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    saveas_pushbutton->setIcon(QIcon("images/viewfilesaveas.png"));
    saveas_pushbutton->setText("���Ϊ");
    saveas_pushbutton->setAutoRaise(true);
    saveas_pushbutton->setObjectName("saveas");
    exit_pushbutton = new QToolButton(this);
    exit_pushbutton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    exit_pushbutton->setText("��  ��");
    exit_pushbutton->setIcon(QIcon("images/viewfileclose.png"));
    exit_pushbutton->setAutoRaise(true);
    exit_pushbutton->setObjectName("exit");
    savedialog = new ViewSaveDialog(isnew,this);
    connect(save_pushbutton,SIGNAL(clicked()),this,SLOT(saveViewFile()));
    connect(saveas_pushbutton,SIGNAL(clicked()),this,SLOT(saveViewFile()));
    connect(exit_pushbutton,SIGNAL(clicked()),this,SLOT(exitView()));
    connect(savedialog,SIGNAL(saveview(QString)),this,SIGNAL(saveview(QString)));
    connect(savedialog,SIGNAL(tabName(QString)),this,SLOT(addOldFileNameToTabName(QString)));
    //raisAllButton();
   // this->setAttribute(Qt::WA_DeleteOnClose,true);
    tabwid = qobject_cast<TabWidget *>(parent);
    this->setObjectName("tabinnerwidget");
   // this->setStyleSheet("QWidget{background:#EEEEFF;}");

}
void TabInnerWidget::saveViewFile()
{
    QToolButton * pushbtn = qobject_cast<QToolButton *>(sender());
    if(pushbtn == save_pushbutton)
    {
        issave = true;

    }
    else if(pushbtn == saveas_pushbutton)
    {
        issave = false;
    }
    savedialog->setFileSaveAction(issave);
    QString title = windowTitle();
    if(title.left(3) == "δ����")
    {
        savedialog->setSaveName("");
    }
    else
    {
        savedialog->setSaveName(title.split(".").first());
    }

    savedialog->getViewsName();
    savedialog->setVisible(true);
    savedialog->exec();
    savedialog->setVisible(false);
}

void TabInnerWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(0xE0,0xFF,0xFF));
    painter.drawRect(0,0,this->width(),this->height());
    //QWidget::paintEvent(event);
}

void  TabInnerWidget::resizeEvent(QResizeEvent * event)
{
    emit sizeChanged();
    save_pushbutton->setGeometry(width()-150,height()-50,50,50);
    saveas_pushbutton->setGeometry(width()-100,height()-50,50,50);
    exit_pushbutton->setGeometry(width()-50,height()-50,50,50);
    if(pagetype == 0)
    {
        save_pushbutton->hide();
        saveas_pushbutton->hide();
    }
    else
    {
        save_pushbutton->show();
        saveas_pushbutton->show();
    }
}

uint TabInnerWidget::getId()
{
    objectid++;
    return objectid;
}

void TabInnerWidget::setId(uint id)
{
    objectid = id;
}

void TabInnerWidget::setPageType(int pagetype)
{
    this->pagetype = pagetype;
    if(pagetype == 1)
    {
        savedialog->setFileViewState(true);
    }
    else if(pagetype == 2)
    {
        savedialog->setFileViewState(false);
    }
}

void TabInnerWidget::raiseAllButton()
{
    saveas_pushbutton->raise();
    save_pushbutton->raise();
    exit_pushbutton->raise();
}
void TabInnerWidget::saveControlGem()
{
    qDebug()<<"saveControlGem";
    QObjectList  childrenlist = children();
    QObjectList  controllist;
    QObjectList::iterator iter = childrenlist.begin();
    while(iter != childrenlist.end())
    {
        qDebug()<<"new children:"<<((*iter)->objectName());
        QString objectname = (*iter)->objectName();

        if(objectname.left(1) == "v")
        {
            controllist<<(*iter);
        }
        ++iter;
    }
    QString filename = windowTitle();
    QFile file("view/" + filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�ļ�д��ʱ�ļ���ʧ�ܣ�"),tr("ȷ��"));
        return;
    }
    QTextStream out(&file);
    file.resize(0);
    out.seek(0);
    QObjectList::iterator controliter = controllist.begin();
    out<<controllist.size()<<"\n";
    while(controliter != controllist.end())
    {
        QWidget * widget = ((QWidget *)(*controliter));//�˴����ö�ÿ����ͼ�������Ŀؼ����ݽ��ж�д
        out<<widget->windowTitle()<<"*"<<widget->objectName()<<"*"<<widget->x()<<"*"<<widget->y()<<"*"<<widget->width()<<"*"<<widget->height()<<";"<<"\n";
        qDebug()<<widget->windowTitle()<<"*"<<widget->objectName()<<"*"<<widget->x()<<"*"<<widget->y()<<"*"<<widget->width()<<"*"<<widget->height()<<";"<<"\n";
        ++controliter;
    }
    file.close();
}

void TabInnerWidget::exitView()
{
    qDebug()<<"pagetype"<<pagetype;
    int result =  QMessageBox::warning(0,"����","ȷ���˳���","��","��");
    if(result == 1)
    {
        return;
    }
    if(pagetype == 0 && windowTitle().right(2) != "����")
    {
        saveControlGem();
    }
    else if(pagetype == 1 || pagetype == 2)
    {
        qDebug()<<"windowTitle()"<<windowTitle();
        if(windowTitle().right(1) == "*")
        {
            int choice = QMessageBox::warning(0,"����","��ͼ�ѱ��޸�,�Ƿ񱣴�","��","��");
            qDebug()<<"choice"<<choice;
            if(choice == 0)
            {
                return;
            }
            else if(choice == 1)
            {
                QString str = windowTitle();
                if(str.left(str.size() - 1) != "δ����")
                {
                    qDebug()<<"str1";

                  qDebug()<<"str2";
                  qDebug()<<tabwid->usedviews;
                  tabwid->usedviews.removeAt(tabwid->usedviews.indexOf(str.left(str.size() - 1)));
                  qDebug()<<"str3";
                }
            }
        }
        else if(windowTitle() != "δ����")
        {
            saveControlGem();
        }
    }
    emit closeMySelf();
}

void TabInnerWidget::delControl(QString controlname)
{
    qDebug()<<"delControl"<<controlname;
    qDebug()<<usedcontrols.size();
    usedcontrols.removeAt(usedcontrols.indexOf(controlname));
    qDebug()<<usedcontrols.size();
    qDebug()<<windowTitle();
    if(windowTitle().left(3) != "δ����")
    {
        unlinkControlToview(controlname);
        if(windowTitle().right(1) != "*")
        {
            emit tabName(windowTitle()+"*",windowTitle());
        }
    }
}

void TabInnerWidget::unlinkControlToview(QString controlname)
{
    bool finded = false;
    QString path = "controls/";
    QFile file(path+controlname);
    if(!file.exists())
    {
        QMessageBox::critical(0,tr("����"),tr("�����ؼ��ļ������ڣ��������"),tr("ȷ��"));
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�����ؼ���ʧ�ܴ�ʧ�ܣ�"),tr("ȷ��"));
        return;
    }

    QTextStream in(&file);
    QStringList filecontents;
    int count = in.readLine().toInt();
    filecontents<<QString::number(count);
    while(count > 0)
    {
        filecontents<<in.readLine();
        --count;
    }
    QString viewsname = in.readLine();
    file.close();
    QString newviewsnamestr;
    QString windowtitle = windowTitle();
    windowtitle.remove("*");
    if(!viewsname.isNull())
    {
        QStringList viewnamelist = viewsname.split("*");
        QStringList::iterator i = viewnamelist.begin();
        while(i != viewnamelist.end())
        {
            qDebug()<<(*i);
            if(!finded && (*i) ==  windowtitle)
            {
                finded = true;
                i++;
                continue;
            }
            else
            {
                newviewsnamestr += (*i);
                newviewsnamestr += "*";
                ++i;
            }

        }
    }
    if(!newviewsnamestr.isEmpty())
    {

        newviewsnamestr = newviewsnamestr.left(newviewsnamestr.size()-1);
        filecontents<<newviewsnamestr;
    }
    //inout.seek(0);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QStringList::iterator i = filecontents.begin();
    while(i != filecontents.end())
    {
        out<<(*i)<<"\n";
        ++i;
    }
    file.close();
}

void TabInnerWidget::addOldFileNameToTabName(QString newfilename)
{
    emit tabName(newfilename,windowTitle());
}
