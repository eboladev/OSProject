#include "resideregisterstatusdelegate.h"
#include<QApplication>
#include<QPainter>
ResideRegisterStatusDelegate::ResideRegisterStatusDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void ResideRegisterStatusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    int content = index.model()->data(index,Qt::DisplayRole).toInt();
    QString value;
    if(content == 1)
        value = tr("已登记");
    else if(content == 0)
        value = tr("未登记");
    else
        value = tr("无");
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    drawDisplay(painter, myOption, myOption.rect, value);
    drawFocus(painter, myOption, myOption.rect);
}
