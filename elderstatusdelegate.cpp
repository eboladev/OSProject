#include "elderstatusdelegate.h"

ElderStatusDelegate::ElderStatusDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void ElderStatusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    int content = index.model()->data(index,Qt::DisplayRole).toInt();
    QString value;
    if(content == 1)
        value = tr("��ס");
    else if(content == 2)
        value = tr("���");
    else if(content == 3)
        value = tr("��ס");
    else
        value = tr("��");
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    drawDisplay(painter, myOption, myOption.rect, value);
    drawFocus(painter, myOption, myOption.rect);
}
