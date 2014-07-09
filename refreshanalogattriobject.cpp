//全局调用，不同作用域通信
#include "refreshanalogattriobject.h"
#include "mainwindow.h"

RefreshAnalogAttriObject::RefreshAnalogAttriObject(QWidget *parent) :
    QObject(parent)
{
    parentwid = (qobject_cast<MainWindow *>(parent));
}
void RefreshAnalogAttriObject::setAppEnable(bool flag)
{
    if(parentwid)
        parentwid->setEnabled(flag);
}

