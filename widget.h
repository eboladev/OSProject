#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMdiSubWindow>
class QToolButton;

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    enum {LEFT, RIGHT, TOP, BOTTOM,LEFTTOP,RIGHTTOP,LEFTBOTTOM,RIGHTBOTTOM};
    virtual QSize sizeHint ()const
    {
        return QSize(600,400);
    }
signals:
    void raiseAllButton();
public slots:
    void minimumAndMaxmum();
    void resizeWidget();
protected:
    virtual void    paintEvent ( QPaintEvent * event );
    virtual void    mouseMoveEvent ( QMouseEvent * event );
    virtual void    mousePressEvent ( QMouseEvent * event );
    virtual void    mouseReleaseEvent( QMouseEvent * event );
    virtual void    resizeEvent(QResizeEvent * event);
    int   m_curShape;
    QPoint  m_movePoint;    //移动的距离
    bool  m_pressMouse;    //按下鼠标左键
    bool  m_changeRect;    //窗口改变大小
    bool  m_curChanged;    //鼠标形状改变
           //鼠标形状
    int   m_minWidth;
    int   m_minHeight;
    bool ismax;
    bool  setCursorShape(int flag);
     int   getSideType(QPoint point);
     void  changeRectSize(int flag,QPoint globalPos);
   // virtual void    mouseDoubleClickEvent(QMouseEvent * event);
private:



    
private:
    QRect geometryandsize;
    QToolButton * minmumandmaxmum_button;

   // QWidget * father;
};

#endif // WIDGET_H
