#include "elderstatusdelegate.h"

ElderStatusDelegate::ElderStatusDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void ElderStatusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    int content = index.model()->data(index,Qt::DisplayRole).toInt();
    QString value;
    if(content == 1)
        value = tr("入住");
    else if(content == 2)
        value = tr("请假");
    else if(content == 3)
        value = tr("退住");
    else
        value = tr("无");
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    drawDisplay(painter, myOption, myOption.rect, value);
    drawFocus(painter, myOption, myOption.rect);
}
