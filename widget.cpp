#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QToolButton>
#include <QStylePainter>
#include <QBitmap>
#include <QCursor>
#include "widget.h"
#include "struct.h"

Widget::Widget(QWidget *parent):
    QWidget(parent),m_curShape(0),m_pressMouse(false),m_changeRect(false) ,m_curChanged(false),
    m_minWidth(300),m_minHeight(200)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setMouseTracking(true);
    minmumandmaxmum_button = new QToolButton(this);
    minmumandmaxmum_button->setFocusPolicy(Qt::NoFocus);
    minmumandmaxmum_button->setIcon(QIcon("images/maxmum.png"));
    minmumandmaxmum_button->adjustSize();
    minmumandmaxmum_button->setAutoRaise(true);
    ismax = false;
    connect(minmumandmaxmum_button,SIGNAL(clicked()),this,SLOT(minimumAndMaxmum()));
    setMinimumSize(0,0);
    //this->setGeometry(0,0,400,300);//是否注释掉，是否要修改
    if(parent->objectName() == "tabinnerwidget")
    {
        connect((TabInnerWidget *)(this->parent()),SIGNAL(sizeChanged()),this,SLOT(resizeWidget()));
        connect(this,SIGNAL(raiseAllButton()),((TabInnerWidget *)parent),SLOT(raiseAllButton()));
        emit raiseAllButton();
    }
    else
    {
         minmumandmaxmum_button->hide();
         ismax = true;
         //this->setFixedSize(400,300);
    }
}
void Widget::mouseMoveEvent( QMouseEvent * event )
{
    if(ismax) return;
    if(!(centralGem).contains(event->globalPos())) return;

    if (m_pressMouse)    //移动窗口
    {
        setCursor(Qt::OpenHandCursor);
        QPoint movePos = event->globalPos();
        this->repaint();
        move(movePos - m_movePoint);
    }
    else    //改变窗口大小
    {
        if (!m_changeRect)    //如果没按下鼠标左键, 判断是否在边框    (主要是为了按下鼠标后不要再验证鼠标形状了)
        {
            m_curShape = getSideType(event->pos());
            m_curChanged = setCursorShape(m_curShape);
        }
        else
        {
            //if(this->size() == this->minimumSize()&&m_curChanged) return;
            changeRectSize(m_curShape,event->pos());
        }
    }


    // geometryandsize = geometry();

}

void Widget::mousePressEvent( QMouseEvent * event )
{
    this->raise();
    if(ismax)
    {
        //emit raiseAllButton();
        return;
    }

    if (event->button() == Qt::LeftButton)    //只能是鼠标左键移动和改变大小
    {
        m_pressMouse = true;
        if (m_curChanged)
        {
            m_changeRect = true;
            m_pressMouse = false; //防止整个窗口移动
        }
    }

    m_movePoint = event->globalPos() - pos();    //窗口移动距离
    emit raiseAllButton();

}

void Widget::mouseReleaseEvent( QMouseEvent * event )
{
    if(ismax) return;
    m_pressMouse = false;
    m_changeRect = false;
   // m_curChanged = false;
    this->setCursor(Qt::ArrowCursor);
    this->repaint();
}
/*void Widget::mouseDoubleClickEvent(QMouseEvent * event)
{

    if(!ismax)
    {
        geometryandsize = geometry();
        qDebug()<<geometryandsize;
        this->setGeometry(0,0,((QWidget *)(this->parent()))->width(),((QWidget *)(this->parent()))->height());
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

void Widget::paintEvent( QPaintEvent * event )
{

    if(parent()->objectName() == "tabinnerwidget"&&!ismax)
    {
        QStylePainter painter(this);
        QPen pen = painter.pen();
        pen.setWidth(3);
        if(m_pressMouse)
        {
            pen.setColor(Qt::darkGray);
            pen.setStyle(Qt::DotLine);
        }
        else
        {
            pen.setColor(Qt::darkBlue);
            pen.setStyle(Qt::SolidLine);
        }
        painter.setPen(pen);
        painter.drawRect(2,2,this->width()-4,this->height()-4);

    }

}

void Widget::resizeEvent(QResizeEvent * event)
{

     minmumandmaxmum_button->move(this->width()-10-minmumandmaxmum_button->width(),10);

}

int Widget::getSideType( QPoint point )
{
    int lenth = 2;    //设置判断指针的距离
    if (point.x()<=this->rect().left()+lenth)
    {
        if (point.y()>=this->rect().bottom()-lenth)
        {
            return LEFTBOTTOM;
        }
        else if (point.y()<=this->rect().top()+lenth)
        {
             return LEFTTOP;
        }
        return LEFT;
    }
    else if (point.x()>=this->rect().right()-lenth)
    {
        if (point.y()>=this->rect().bottom()-lenth)
        {
            return RIGHTBOTTOM;
        }
        else if (point.y()<=this->rect().top()+lenth)
        {
            return RIGHTTOP;
        }
        return RIGHT;
    }
    else if (point.y()<=this->rect().top()+lenth)
    {
        return TOP;
    }
    else if (point.y()>=this->rect().bottom()-lenth)
    {

        return BOTTOM;
    }
    return -1;
}

bool Widget::setCursorShape( int flag )
{
    QCursor curType;
    bool shapeChanged = false;
    switch (flag)
    {
    case LEFT:
    case RIGHT:
        curType = Qt::SizeHorCursor;
        shapeChanged = true;
        break;

    case TOP:
    case BOTTOM:
        curType = Qt::SizeVerCursor;
        shapeChanged = true;
        break;
    case LEFTTOP:
    case RIGHTBOTTOM:
        curType = Qt::SizeFDiagCursor;
        shapeChanged = true;
        break;
    case RIGHTTOP:
    case LEFTBOTTOM:
        curType = Qt::SizeBDiagCursor;
        shapeChanged = true;
        break;
    default:
        curType = Qt::ArrowCursor;
        break;
    }

    this->setCursor(curType);

    return shapeChanged;
}

void Widget::changeRectSize( int flag ,QPoint globalPos)
{
    //QPoint temp = mapToParent(this->pos());
    globalPos = mapToParent(globalPos);
    int globalX = globalPos.x();
    int globalY = globalPos.y();
    int widgetX = this->pos().x();
    int widgetY = this->pos().y();
    int LMLenght = widgetX+this->width() - globalX;    //左移距离
    int RMLenght = globalX - widgetX +1;
    int TMLenght = widgetY + this->height() - globalY;
    int BMLenght = globalY - widgetY +1;

   if (LMLenght<=m_minWidth)    //防止向右最小时窗口移动
    {
        globalX = this->pos().x();
    }
    if (TMLenght<=m_minHeight)    //防止向下最小时窗口时移动
    {
        globalY = this->pos().y();
    }
    switch (flag)
    {
    case LEFT:
        if(LMLenght>this->minimumWidth())
            setGeometry(globalX,widgetY,LMLenght,this->height());
        break;

    case RIGHT:
        setGeometry(widgetX,widgetY,RMLenght,this->height());
        break;

    case TOP:
        if(TMLenght>this->minimumHeight())
            setGeometry(widgetX,globalY,this->width(),TMLenght);
        break;

    case BOTTOM:
        setGeometry(widgetX,widgetY,this->width(),BMLenght);
        break;

    case LEFTTOP:
        if(LMLenght > this->minimumWidth() && TMLenght > this->minimumHeight())
        {
            setGeometry(globalX,globalY,LMLenght,TMLenght);
            return;
        }

        if(LMLenght > this->minimumWidth())
        {
            setGeometry(globalX,widgetY,LMLenght,this->height());
            return ;
        }
        if(TMLenght>this->minimumHeight())
        {
            setGeometry(widgetX,globalY,this->width(),TMLenght);
            return;
        }
        break;
    case LEFTBOTTOM:
        if(LMLenght > this->minimumWidth() && BMLenght > this->minimumHeight())
        {
            setGeometry(globalX,widgetY,LMLenght,BMLenght);
            return ;
        }
        if(LMLenght > this->minimumWidth())
        {
            setGeometry(globalX,widgetY,LMLenght,this->height());
            return;
        }
        if(BMLenght > this->minimumHeight())
        {
            setGeometry(widgetX,widgetY,this->width(),BMLenght);
            return;
        }

        break;

    case RIGHTTOP:
        if(RMLenght > this->minimumWidth() && TMLenght > this->minimumHeight())
        {
            setGeometry(widgetX,globalY,RMLenght,TMLenght);
            return;
        }
        if(TMLenght>this->minimumHeight())
        {
            setGeometry(widgetX,globalY,this->width(),TMLenght);
            return;
        }
        if(RMLenght > this->minimumWidth())
        {
            setGeometry(widgetX,widgetY,RMLenght,this->height());
            return;
        }

        break;

    case RIGHTBOTTOM:
        setGeometry(widgetX,widgetY,RMLenght,BMLenght);
        break;

    default:
        break;
    }

}
void Widget::minimumAndMaxmum()
{
    if(!ismax)
    {
        geometryandsize = geometry();
        qDebug()<<geometryandsize;
        this->setGeometry(0,0,((QWidget *)(this->parent()))->width(),((QWidget *)(this->parent()))->height());
        ismax = true;
        minmumandmaxmum_button->setIcon(QIcon("images/minmum.png"));
        this->raise();
    }
    else
    {
        this->setGeometry(geometryandsize);
        this->move(geometryandsize.x(),geometryandsize.y());
        this->resize(geometryandsize.width(),geometryandsize.height());
        ismax = false;
        minmumandmaxmum_button->setIcon(QIcon("images/maxmum.png"));
        emit raiseAllButton();
    }

}

 void Widget::resizeWidget()
 {
     qDebug()<<"lianjiechengong";
     if(ismax&&parent()->objectName() == "tabinnerwidget") this->resize(static_cast<TabInnerWidget *>(this->sender())->size());//是否会发生内存泄露问题
      //if(ismax) this->resize(father->size());//father是否需要有待检验
    // minmumandmaxmum_button->setIcon(QIcon("images/maxmum.png"));
 }
